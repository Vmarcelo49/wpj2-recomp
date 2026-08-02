#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8008D23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D23C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D244: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D248: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D24C: jal         0x8001AE90
    // 0x8008D250: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001AE90(rdram, ctx);
        goto after_0;
    // 0x8008D250: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_0:
    // 0x8008D254: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D258: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8008D25C: nop

    // 0x8008D260: lw          $a0, 0x3A8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3A8);
    // 0x8008D264: jal         0x800BC980
    // 0x8008D268: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x8008D268: nop

    after_1:
    // 0x8008D26C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D270: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D274: jal         0x800BC980
    // 0x8008D278: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8008D278: nop

    after_2:
    // 0x8008D27C: b           L_8008D28C
    // 0x8008D280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D28C;
    // 0x8008D280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D284: b           L_8008D28C
    // 0x8008D288: nop

        goto L_8008D28C;
    // 0x8008D288: nop

L_8008D28C:
    // 0x8008D28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D294: jr          $ra
    // 0x8008D298: nop

    return;
    // 0x8008D298: nop

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
RECOMP_FUNC void SysMem_MarkHeap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCC8C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCC90: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x800BCC94: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BCC98: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800BCC9C: nop

    // 0x800BCCA0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800BCCA4: nop

    // 0x800BCCA8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BCCAC: bne         $t9, $zero, L_800BCCBC
    if (ctx->r25 != 0) {
        // 0x800BCCB0: nop
    
            goto L_800BCCBC;
    }
    // 0x800BCCB0: nop

    // 0x800BCCB4: b           L_800BCCDC
    // 0x800BCCB8: nop

        goto L_800BCCDC;
    // 0x800BCCB8: nop

L_800BCCBC:
    // 0x800BCCBC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800BCCC0: nop

    // 0x800BCCC4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800BCCC8: nop

    // 0x800BCCCC: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800BCCD0: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x800BCCD4: b           L_800BCCDC
    // 0x800BCCD8: nop

        goto L_800BCCDC;
    // 0x800BCCD8: nop

L_800BCCDC:
    // 0x800BCCDC: jr          $ra
    // 0x800BCCE0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCCE0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80073290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073290: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073294: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073298: nop

    // 0x8007329C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800732A0: nop

    // 0x800732A4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800732A8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800732AC: jr          $ra
    // 0x800732B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800732B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800732B4: jr          $ra
    // 0x800732B8: nop

    return;
    // 0x800732B8: nop

    // 0x800732BC: jr          $ra
    // 0x800732C0: nop

    return;
    // 0x800732C0: nop

;}
RECOMP_FUNC void func_8003B160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B160: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x8003B164: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003B168: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8003B16C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8003B170: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8003B174: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003B178: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8003B17C: jal         0x800C1754
    // 0x8003B180: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8003B180: nop

    after_0:
    // 0x8003B184: sh          $zero, 0x182($sp)
    MEM_H(0X182, ctx->r29) = 0;
    // 0x8003B188: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003B18C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8003B190: nop

    // 0x8003B194: addiu       $t7, $t6, 0x46
    ctx->r15 = ADD32(ctx->r14, 0X46);
    // 0x8003B198: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x8003B19C: jal         0x80031AC8
    // 0x8003B1A0: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x8003B1A0: nop

    after_1:
    // 0x8003B1A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8003B1A8: bne         $v0, $at, L_8003B374
    if (ctx->r2 != ctx->r1) {
        // 0x8003B1AC: nop
    
            goto L_8003B374;
    }
    // 0x8003B1AC: nop

    // 0x8003B1B0: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8003B1B4: lbu         $t8, -0x69F8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X69F8);
    // 0x8003B1B8: nop

    // 0x8003B1BC: beq         $t8, $zero, L_8003B374
    if (ctx->r24 == 0) {
        // 0x8003B1C0: nop
    
            goto L_8003B374;
    }
    // 0x8003B1C0: nop

    // 0x8003B1C4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003B1C8: lw          $t9, 0x258C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X258C);
    // 0x8003B1CC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8003B1D0: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x8003B1D4: mfhi        $t0
    ctx->r8 = hi;
    // 0x8003B1D8: bne         $t0, $zero, L_8003B220
    if (ctx->r8 != 0) {
        // 0x8003B1DC: nop
    
            goto L_8003B220;
    }
    // 0x8003B1DC: nop

    // 0x8003B1E0: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8003B1E4: nop

    // 0x8003B1E8: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8003B1EC: nop

    // 0x8003B1F0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003B1F4: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x8003B1F8: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x8003B1FC: nop

    // 0x8003B200: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8003B204: nop

    // 0x8003B208: slti        $at, $t5, 0x2711
    ctx->r1 = SIGNED(ctx->r13) < 0X2711 ? 1 : 0;
    // 0x8003B20C: bne         $at, $zero, L_8003B220
    if (ctx->r1 != 0) {
        // 0x8003B210: nop
    
            goto L_8003B220;
    }
    // 0x8003B210: nop

    // 0x8003B214: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8003B218: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x8003B21C: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_8003B220:
    // 0x8003B220: sh          $zero, 0x184($sp)
    MEM_H(0X184, ctx->r29) = 0;
    // 0x8003B224: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8003B228: nop

    // 0x8003B22C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8003B230: nop

    // 0x8003B234: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8003B238: nop

    // 0x8003B23C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B240: swc1        $f6, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f6.u32l;
    // 0x8003B244: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003B248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003B24C: lwc1        $f8, 0x16C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003B250: nop

    // 0x8003B254: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8003B258: nop

    // 0x8003B25C: bc1f        L_8003B298
    if (!c1cs) {
        // 0x8003B260: nop
    
            goto L_8003B298;
    }
    // 0x8003B260: nop

    // 0x8003B264: jal         0x8005F064
    // 0x8003B268: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    func_8005F064(rdram, ctx);
        goto after_2;
    // 0x8003B268: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    after_2:
    // 0x8003B26C: bne         $v0, $zero, L_8003B298
    if (ctx->r2 != 0) {
        // 0x8003B270: nop
    
            goto L_8003B298;
    }
    // 0x8003B270: nop

    // 0x8003B274: jal         0x80031874
    // 0x8003B278: nop

    func_80031874(rdram, ctx);
        goto after_3;
    // 0x8003B278: nop

    after_3:
    // 0x8003B27C: bne         $v0, $zero, L_8003B298
    if (ctx->r2 != 0) {
        // 0x8003B280: nop
    
            goto L_8003B298;
    }
    // 0x8003B280: nop

    // 0x8003B284: jal         0x8005F0DC
    // 0x8003B288: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    func_8005F0DC(rdram, ctx);
        goto after_4;
    // 0x8003B288: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    after_4:
    // 0x8003B28C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003B290: b           L_8003B33C
    // 0x8003B294: sh          $t0, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r8;
        goto L_8003B33C;
    // 0x8003B294: sh          $t0, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r8;
L_8003B298:
    // 0x8003B298: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8003B29C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003B2A0: lwc1        $f16, 0x16C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003B2A4: nop

    // 0x8003B2A8: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8003B2AC: nop

    // 0x8003B2B0: bc1f        L_8003B2EC
    if (!c1cs) {
        // 0x8003B2B4: nop
    
            goto L_8003B2EC;
    }
    // 0x8003B2B4: nop

    // 0x8003B2B8: jal         0x8005F064
    // 0x8003B2BC: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x8003B2BC: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    after_5:
    // 0x8003B2C0: bne         $v0, $zero, L_8003B2EC
    if (ctx->r2 != 0) {
        // 0x8003B2C4: nop
    
            goto L_8003B2EC;
    }
    // 0x8003B2C4: nop

    // 0x8003B2C8: jal         0x80031874
    // 0x8003B2CC: nop

    func_80031874(rdram, ctx);
        goto after_6;
    // 0x8003B2CC: nop

    after_6:
    // 0x8003B2D0: bne         $v0, $zero, L_8003B2EC
    if (ctx->r2 != 0) {
        // 0x8003B2D4: nop
    
            goto L_8003B2EC;
    }
    // 0x8003B2D4: nop

    // 0x8003B2D8: jal         0x8005F0DC
    // 0x8003B2DC: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    func_8005F0DC(rdram, ctx);
        goto after_7;
    // 0x8003B2DC: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    after_7:
    // 0x8003B2E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003B2E4: b           L_8003B33C
    // 0x8003B2E8: sh          $t2, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r10;
        goto L_8003B33C;
    // 0x8003B2E8: sh          $t2, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r10;
L_8003B2EC:
    // 0x8003B2EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B2F0: lwc1        $f6, -0x14E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X14E8);
    // 0x8003B2F4: lwc1        $f4, 0x16C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003B2F8: nop

    // 0x8003B2FC: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8003B300: nop

    // 0x8003B304: bc1f        L_8003B33C
    if (!c1cs) {
        // 0x8003B308: nop
    
            goto L_8003B33C;
    }
    // 0x8003B308: nop

    // 0x8003B30C: jal         0x8005F064
    // 0x8003B310: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    func_8005F064(rdram, ctx);
        goto after_8;
    // 0x8003B310: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    after_8:
    // 0x8003B314: bne         $v0, $zero, L_8003B33C
    if (ctx->r2 != 0) {
        // 0x8003B318: nop
    
            goto L_8003B33C;
    }
    // 0x8003B318: nop

    // 0x8003B31C: jal         0x80031874
    // 0x8003B320: nop

    func_80031874(rdram, ctx);
        goto after_9;
    // 0x8003B320: nop

    after_9:
    // 0x8003B324: bne         $v0, $zero, L_8003B33C
    if (ctx->r2 != 0) {
        // 0x8003B328: nop
    
            goto L_8003B33C;
    }
    // 0x8003B328: nop

    // 0x8003B32C: jal         0x8005F0DC
    // 0x8003B330: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    func_8005F0DC(rdram, ctx);
        goto after_10;
    // 0x8003B330: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    after_10:
    // 0x8003B334: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003B338: sh          $t3, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r11;
L_8003B33C:
    // 0x8003B33C: lhu         $t1, 0x184($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X184);
    // 0x8003B340: nop

    // 0x8003B344: beq         $t1, $zero, L_8003B374
    if (ctx->r9 == 0) {
        // 0x8003B348: nop
    
            goto L_8003B374;
    }
    // 0x8003B348: nop

    // 0x8003B34C: jal         0x800B9000
    // 0x8003B350: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    func_800B9000(rdram, ctx);
        goto after_11;
    // 0x8003B350: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    after_11:
    // 0x8003B354: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003B358: lw          $t4, 0x7284($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7284);
    // 0x8003B35C: nop

    // 0x8003B360: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x8003B364: jal         0x800319B0
    // 0x8003B368: nop

    func_800319B0(rdram, ctx);
        goto after_12;
    // 0x8003B368: nop

    after_12:
    // 0x8003B36C: jal         0x80031B6C
    // 0x8003B370: nop

    func_80031B6C(rdram, ctx);
        goto after_13;
    // 0x8003B370: nop

    after_13:
L_8003B374:
    // 0x8003B374: jal         0x8005F064
    // 0x8003B378: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    func_8005F064(rdram, ctx);
        goto after_14;
    // 0x8003B378: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    after_14:
    // 0x8003B37C: beq         $v0, $zero, L_8003B394
    if (ctx->r2 == 0) {
        // 0x8003B380: nop
    
            goto L_8003B394;
    }
    // 0x8003B380: nop

    // 0x8003B384: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B388: lwc1        $f8, -0x14E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X14E4);
    // 0x8003B38C: b           L_8003B3E0
    // 0x8003B390: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
        goto L_8003B3E0;
    // 0x8003B390: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
L_8003B394:
    // 0x8003B394: jal         0x8005F064
    // 0x8003B398: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    func_8005F064(rdram, ctx);
        goto after_15;
    // 0x8003B398: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    after_15:
    // 0x8003B39C: beq         $v0, $zero, L_8003B3B4
    if (ctx->r2 == 0) {
        // 0x8003B3A0: nop
    
            goto L_8003B3B4;
    }
    // 0x8003B3A0: nop

    // 0x8003B3A4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8003B3A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003B3AC: b           L_8003B3E0
    // 0x8003B3B0: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
        goto L_8003B3E0;
    // 0x8003B3B0: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_8003B3B4:
    // 0x8003B3B4: jal         0x8005F064
    // 0x8003B3B8: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    func_8005F064(rdram, ctx);
        goto after_16;
    // 0x8003B3B8: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    after_16:
    // 0x8003B3BC: beq         $v0, $zero, L_8003B3D4
    if (ctx->r2 == 0) {
        // 0x8003B3C0: nop
    
            goto L_8003B3D4;
    }
    // 0x8003B3C0: nop

    // 0x8003B3C4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003B3C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003B3CC: b           L_8003B3E0
    // 0x8003B3D0: swc1        $f16, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f16.u32l;
        goto L_8003B3E0;
    // 0x8003B3D0: swc1        $f16, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f16.u32l;
L_8003B3D4:
    // 0x8003B3D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003B3D8: nop

    // 0x8003B3DC: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
L_8003B3E0:
    // 0x8003B3E0: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8003B3E4: lhu         $s0, 0x728E($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X728E);
    // 0x8003B3E8: nop

    // 0x8003B3EC: andi        $t5, $s0, 0x1
    ctx->r13 = ctx->r16 & 0X1;
    // 0x8003B3F0: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8003B3F4: sltiu       $t6, $s0, 0x1
    ctx->r14 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x8003B3F8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8003B3FC: sh          $s0, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r16;
    // 0x8003B400: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8003B404: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8003B408: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8003B40C: nop

    // 0x8003B410: swc1        $f4, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f4.u32l;
    // 0x8003B414: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8003B418: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8003B41C: lwc1        $f6, 0x14($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8003B420: nop

    // 0x8003B424: swc1        $f6, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f6.u32l;
    // 0x8003B428: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B42C: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8003B430: lwc1        $f17, -0x14E0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X14E0);
    // 0x8003B434: lwc1        $f16, -0x14DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X14DC);
    // 0x8003B438: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8003B43C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8003B440: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003B444: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003B448: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8003B44C: swc1        $f4, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f4.u32l;
    // 0x8003B450: bc1f        L_8003B47C
    if (!c1cs) {
        // 0x8003B454: nop
    
            goto L_8003B47C;
    }
    // 0x8003B454: nop

    // 0x8003B458: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B45C: lwc1        $f11, -0x14D8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X14D8);
    // 0x8003B460: lwc1        $f10, -0x14D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X14D4);
    // 0x8003B464: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8003B468: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8003B46C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003B470: swc1        $f18, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f18.u32l;
    // 0x8003B474: b           L_8003B4A0
    // 0x8003B478: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
        goto L_8003B4A0;
    // 0x8003B478: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_8003B47C:
    // 0x8003B47C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B480: lwc1        $f6, 0x17C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8003B484: lwc1        $f9, -0x14D0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X14D0);
    // 0x8003B488: lwc1        $f8, -0x14CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X14CC);
    // 0x8003B48C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8003B490: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8003B494: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003B498: swc1        $f16, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f16.u32l;
    // 0x8003B49C: neg.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = -ctx->f16.fl;
L_8003B4A0:
    // 0x8003B4A0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8003B4A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8003B4A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003B4AC: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8003B4B0: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8003B4B4: nop

    // 0x8003B4B8: bc1f        L_8003B4CC
    if (!c1cs) {
        // 0x8003B4BC: nop
    
            goto L_8003B4CC;
    }
    // 0x8003B4BC: nop

    // 0x8003B4C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003B4C4: nop

    // 0x8003B4C8: swc1        $f4, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f4.u32l;
L_8003B4CC:
    // 0x8003B4CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B4D0: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8003B4D4: lwc1        $f17, -0x14C8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X14C8);
    // 0x8003B4D8: lwc1        $f16, -0x14C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X14C4);
    // 0x8003B4DC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8003B4E0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8003B4E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003B4E8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8003B4EC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003B4F0: swc1        $f6, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f6.u32l;
    // 0x8003B4F4: bc1f        L_8003B520
    if (!c1cs) {
        // 0x8003B4F8: nop
    
            goto L_8003B520;
    }
    // 0x8003B4F8: nop

    // 0x8003B4FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B500: lwc1        $f11, -0x14C0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X14C0);
    // 0x8003B504: lwc1        $f10, -0x14BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X14BC);
    // 0x8003B508: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003B50C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8003B510: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003B514: swc1        $f18, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f18.u32l;
    // 0x8003B518: b           L_8003B544
    // 0x8003B51C: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
        goto L_8003B544;
    // 0x8003B51C: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_8003B520:
    // 0x8003B520: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B524: lwc1        $f4, 0x178($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8003B528: lwc1        $f9, -0x14B8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X14B8);
    // 0x8003B52C: lwc1        $f8, -0x14B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X14B4);
    // 0x8003B530: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003B534: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003B538: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003B53C: swc1        $f16, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f16.u32l;
    // 0x8003B540: neg.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = -ctx->f16.fl;
L_8003B544:
    // 0x8003B544: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8003B548: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003B54C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003B550: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8003B554: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8003B558: nop

    // 0x8003B55C: bc1f        L_8003B570
    if (!c1cs) {
        // 0x8003B560: nop
    
            goto L_8003B570;
    }
    // 0x8003B560: nop

    // 0x8003B564: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003B568: nop

    // 0x8003B56C: swc1        $f6, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f6.u32l;
L_8003B570:
    // 0x8003B570: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8003B574: nop

    // 0x8003B578: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003B57C: swc1        $f10, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->f10.u32l;
    // 0x8003B580: lwc1        $f16, 0x178($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8003B584: nop

    // 0x8003B588: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8003B58C: swc1        $f18, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f18.u32l;
    // 0x8003B590: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8003B594: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8003B598: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x8003B59C: nop

    // 0x8003B5A0: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8003B5A4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8003B5A8: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8003B5AC: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x8003B5B0: nop

    // 0x8003B5B4: sw          $t3, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r11;
    // 0x8003B5B8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003B5BC: lw          $t1, 0x7260($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7260);
    // 0x8003B5C0: nop

    // 0x8003B5C4: sw          $t1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r9;
    // 0x8003B5C8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003B5CC: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x8003B5D0: nop

    // 0x8003B5D4: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003B5D8: nop

    // 0x8003B5DC: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    // 0x8003B5E0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003B5E4: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x8003B5E8: nop

    // 0x8003B5EC: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8003B5F0: nop

    // 0x8003B5F4: swc1        $f6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f6.u32l;
    // 0x8003B5F8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003B5FC: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x8003B600: nop

    // 0x8003B604: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8003B608: nop

    // 0x8003B60C: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
    // 0x8003B610: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003B614: lw          $t7, 0x7278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7278);
    // 0x8003B618: nop

    // 0x8003B61C: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8003B620: nop

    // 0x8003B624: swc1        $f10, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f10.u32l;
    // 0x8003B628: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003B62C: lw          $t8, 0x7278($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7278);
    // 0x8003B630: nop

    // 0x8003B634: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8003B638: nop

    // 0x8003B63C: swc1        $f16, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f16.u32l;
    // 0x8003B640: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003B644: lw          $t9, 0x7278($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7278);
    // 0x8003B648: nop

    // 0x8003B64C: lwc1        $f18, 0x14($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8003B650: nop

    // 0x8003B654: swc1        $f18, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f18.u32l;
    // 0x8003B658: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003B65C: lw          $t0, 0x7278($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7278);
    // 0x8003B660: nop

    // 0x8003B664: lwc1        $f4, 0x18($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8003B668: nop

    // 0x8003B66C: swc1        $f4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f4.u32l;
    // 0x8003B670: lwc1        $f12, 0x150($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003B674: jal         0x800C23E8
    // 0x8003B678: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_17;
    // 0x8003B678: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_17:
    // 0x8003B67C: lwc1        $f12, 0x144($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003B680: jal         0x800C2780
    // 0x8003B684: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateZ(rdram, ctx);
        goto after_18;
    // 0x8003B684: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_18:
    // 0x8003B688: lwc1        $f12, 0x14C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003B68C: jal         0x800C25B8
    // 0x8003B690: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_19;
    // 0x8003B690: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_19:
    // 0x8003B694: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003B698: lwc1        $f12, 0x15C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003B69C: lwc1        $f14, 0x158($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003B6A0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003B6A4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8003B6A8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8003B6AC: jal         0x800C2304
    // 0x8003B6B0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_20;
    // 0x8003B6B0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_20:
    // 0x8003B6B4: jal         0x800C1680
    // 0x8003B6B8: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_21;
    // 0x8003B6B8: nop

    after_21:
    // 0x8003B6BC: jal         0x800AD680
    // 0x8003B6C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800AD680(rdram, ctx);
        goto after_22;
    // 0x8003B6C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_22:
    // 0x8003B6C4: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8003B6C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003B6CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003B6D0: lwc1        $f14, -0x14B0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X14B0);
    // 0x8003B6D4: jal         0x800AF184
    // 0x8003B6D8: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    func_800AF184(rdram, ctx);
        goto after_23;
    // 0x8003B6D8: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    after_23:
    // 0x8003B6DC: jal         0x80037344
    // 0x8003B6E0: nop

    func_80037344(rdram, ctx);
        goto after_24;
    // 0x8003B6E0: nop

    after_24:
    // 0x8003B6E4: jal         0x800C1850
    // 0x8003B6E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_25;
    // 0x8003B6E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x8003B6EC: lwc1        $f12, 0x14C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003B6F0: jal         0x800C25B8
    // 0x8003B6F4: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_26;
    // 0x8003B6F4: nop

    after_26:
    // 0x8003B6F8: lwc1        $f12, 0x144($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003B6FC: jal         0x800C2780
    // 0x8003B700: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_27;
    // 0x8003B700: nop

    after_27:
    // 0x8003B704: lwc1        $f12, 0x150($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003B708: jal         0x800C23E8
    // 0x8003B70C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_28;
    // 0x8003B70C: nop

    after_28:
    // 0x8003B710: jal         0x800C1A84
    // 0x8003B714: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_29;
    // 0x8003B714: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    after_29:
    // 0x8003B718: lhu         $t2, 0x186($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X186);
    // 0x8003B71C: nop

    // 0x8003B720: beq         $t2, $zero, L_8003C3C8
    if (ctx->r10 == 0) {
        // 0x8003B724: nop
    
            goto L_8003C3C8;
    }
    // 0x8003B724: nop

    // 0x8003B728: jal         0x800C1850
    // 0x8003B72C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_30;
    // 0x8003B72C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_30:
    // 0x8003B730: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003B734: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8003B738: jal         0x800AD1E4
    // 0x8003B73C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_31;
    // 0x8003B73C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_31:
    // 0x8003B740: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8003B744: lw          $t3, -0x4CCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CCC);
    // 0x8003B748: lwc1        $f10, 0x150($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003B74C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8003B750: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003B754: subu        $t4, $t1, $t3
    ctx->r12 = SUB32(ctx->r9, ctx->r11);
    // 0x8003B758: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8003B75C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003B760: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003B764: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8003B768: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003B76C: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8003B770: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003B774: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003B778: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8003B77C: jal         0x800C2304
    // 0x8003B780: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_32;
    // 0x8003B780: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    after_32:
    // 0x8003B784: lwc1        $f12, 0x144($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003B788: jal         0x800C2780
    // 0x8003B78C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateZ(rdram, ctx);
        goto after_33;
    // 0x8003B78C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_33:
    // 0x8003B790: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003B794: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x8003B798: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003B79C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8003B7A0: sw          $t6, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r14;
    // 0x8003B7A4: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
    // 0x8003B7A8: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8003B7AC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003B7B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8003B7B4: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x8003B7B8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8003B7BC: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x8003B7C0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8003B7C4: addiu       $t9, $t9, 0x158
    ctx->r25 = ADD32(ctx->r25, 0X158);
    // 0x8003B7C8: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8003B7CC: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x8003B7D0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003B7D4: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x8003B7D8: addiu       $a1, $a1, 0x258
    ctx->r5 = ADD32(ctx->r5, 0X258);
    // 0x8003B7DC: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8003B7E0: jal         0x800B18C4
    // 0x8003B7E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800B18C4(rdram, ctx);
        goto after_34;
    // 0x8003B7E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_34:
    // 0x8003B7E8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003B7EC: lw          $t1, 0x72A4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72A4);
    // 0x8003B7F0: nop

    // 0x8003B7F4: lw          $t3, 0x14C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X14C);
    // 0x8003B7F8: nop

    // 0x8003B7FC: sw          $t3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r11;
    // 0x8003B800: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003B804: lw          $t4, 0x258C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X258C);
    // 0x8003B808: nop

    // 0x8003B80C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8003B810: bgez        $t4, L_8003B828
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8003B814: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8003B828;
    }
    // 0x8003B814: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003B818: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8003B81C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003B820: nop

    // 0x8003B824: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8003B828:
    // 0x8003B828: swc1        $f16, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f16.u32l;
    // 0x8003B82C: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x8003B830: nop

    // 0x8003B834: beq         $t5, $zero, L_8003BC4C
    if (ctx->r13 == 0) {
        // 0x8003B838: nop
    
            goto L_8003BC4C;
    }
    // 0x8003B838: nop

L_8003B83C:
    // 0x8003B83C: sh          $zero, 0x188($sp)
    MEM_H(0X188, ctx->r29) = 0;
    // 0x8003B840: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8003B844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003B848: lhu         $s0, 0x0($t6)
    ctx->r16 = MEM_HU(ctx->r14, 0X0);
    // 0x8003B84C: nop

    // 0x8003B850: beq         $s0, $at, L_8003B86C
    if (ctx->r16 == ctx->r1) {
        // 0x8003B854: nop
    
            goto L_8003B86C;
    }
    // 0x8003B854: nop

    // 0x8003B858: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003B85C: beq         $s0, $at, L_8003B9BC
    if (ctx->r16 == ctx->r1) {
        // 0x8003B860: nop
    
            goto L_8003B9BC;
    }
    // 0x8003B860: nop

    // 0x8003B864: b           L_8003BAB4
    // 0x8003B868: nop

        goto L_8003BAB4;
    // 0x8003B868: nop

L_8003B86C:
    // 0x8003B86C: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8003B870: nop

    // 0x8003B874: lw          $t8, 0x148($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X148);
    // 0x8003B878: nop

    // 0x8003B87C: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x8003B880: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8003B884: sh          $t9, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r25;
    // 0x8003B888: jal         0x800C1850
    // 0x8003B88C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_35;
    // 0x8003B88C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_35:
    // 0x8003B890: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x8003B894: nop

    // 0x8003B898: lhu         $t2, 0xC($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0XC);
    // 0x8003B89C: nop

    // 0x8003B8A0: beq         $t2, $zero, L_8003B8FC
    if (ctx->r10 == 0) {
        // 0x8003B8A4: nop
    
            goto L_8003B8FC;
    }
    // 0x8003B8A4: nop

    // 0x8003B8A8: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x8003B8AC: lwc1        $f6, 0x164($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003B8B0: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003B8B4: nop

    // 0x8003B8B8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003B8BC: jal         0x800C25B8
    // 0x8003B8C0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_36;
    // 0x8003B8C0: nop

    after_36:
    // 0x8003B8C4: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x8003B8C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003B8CC: lwc1        $f12, 0x10($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X10);
    // 0x8003B8D0: lwc1        $f14, 0x14($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X14);
    // 0x8003B8D4: jal         0x800C2304
    // 0x8003B8D8: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_37;
    // 0x8003B8D8: nop

    after_37:
    // 0x8003B8DC: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x8003B8E0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003B8E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003B8E8: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8003B8EC: jal         0x800C25B8
    // 0x8003B8F0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_38;
    // 0x8003B8F0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_38:
    // 0x8003B8F4: b           L_8003B944
    // 0x8003B8F8: nop

        goto L_8003B944;
    // 0x8003B8F8: nop

L_8003B8FC:
    // 0x8003B8FC: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x8003B900: lwc1        $f16, 0x164($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003B904: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003B908: nop

    // 0x8003B90C: mul.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8003B910: jal         0x800C25B8
    // 0x8003B914: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_39;
    // 0x8003B914: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_39:
    // 0x8003B918: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8003B91C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003B920: lwc1        $f12, 0x10($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8003B924: lwc1        $f14, 0x14($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8003B928: jal         0x800C2304
    // 0x8003B92C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_40;
    // 0x8003B92C: nop

    after_40:
    // 0x8003B930: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8003B934: nop

    // 0x8003B938: lwc1        $f12, 0x8($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8003B93C: jal         0x800C25B8
    // 0x8003B940: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_41;
    // 0x8003B940: nop

    after_41:
L_8003B944:
    // 0x8003B944: jal         0x800C2070
    // 0x8003B948: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    func_800C2070(rdram, ctx);
        goto after_42;
    // 0x8003B948: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    after_42:
    // 0x8003B94C: jal         0x800B1844
    // 0x8003B950: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    func_800B1844(rdram, ctx);
        goto after_43;
    // 0x8003B950: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_43:
    // 0x8003B954: addiu       $t8, $sp, 0x104
    ctx->r24 = ADD32(ctx->r29, 0X104);
    // 0x8003B958: lwc1        $f4, 0x38($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X38);
    // 0x8003B95C: lwc1        $f12, 0x30($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X30);
    // 0x8003B960: lwc1        $f14, 0x34($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X34);
    // 0x8003B964: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003B968: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x8003B96C: jal         0x800AF1F0
    // 0x8003B970: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
    func_800AF1F0(rdram, ctx);
        goto after_44;
    // 0x8003B970: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
    after_44:
    // 0x8003B974: sh          $v0, 0x188($sp)
    MEM_H(0X188, ctx->r29) = ctx->r2;
    // 0x8003B978: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8003B97C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x8003B980: lhu         $a2, 0x188($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X188);
    // 0x8003B984: jal         0x8003A52C
    // 0x8003B988: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    func_8003A52C(rdram, ctx);
        goto after_45;
    // 0x8003B988: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    after_45:
    // 0x8003B98C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8003B990: lh          $t0, 0x182($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X182);
    // 0x8003B994: sra         $t9, $s1, 16
    ctx->r25 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8003B998: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8003B99C: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x8003B9A0: sh          $t2, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r10;
    // 0x8003B9A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003B9A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B9AC: nop

    // 0x8003B9B0: swc1        $f6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f6.u32l;
    // 0x8003B9B4: b           L_8003BAB4
    // 0x8003B9B8: nop

        goto L_8003BAB4;
    // 0x8003B9B8: nop

L_8003B9BC:
    // 0x8003B9BC: jal         0x800C1850
    // 0x8003B9C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_46;
    // 0x8003B9C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_46:
    // 0x8003B9C4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x8003B9C8: nop

    // 0x8003B9CC: lwc1        $f12, 0x10($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8003B9D0: lwc1        $f14, 0x14($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8003B9D4: lw          $a2, 0x18($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X18);
    // 0x8003B9D8: jal         0x800C2304
    // 0x8003B9DC: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_47;
    // 0x8003B9DC: nop

    after_47:
    // 0x8003B9E0: lwc1        $f12, 0x164($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003B9E4: jal         0x800C25B8
    // 0x8003B9E8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_48;
    // 0x8003B9E8: nop

    after_48:
    // 0x8003B9EC: jal         0x800C2070
    // 0x8003B9F0: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    func_800C2070(rdram, ctx);
        goto after_49;
    // 0x8003B9F0: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    after_49:
    // 0x8003B9F4: jal         0x800B1844
    // 0x8003B9F8: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    func_800B1844(rdram, ctx);
        goto after_50;
    // 0x8003B9F8: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_50:
    // 0x8003B9FC: addiu       $t3, $sp, 0x104
    ctx->r11 = ADD32(ctx->r29, 0X104);
    // 0x8003BA00: lwc1        $f8, 0x38($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X38);
    // 0x8003BA04: lwc1        $f12, 0x30($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X30);
    // 0x8003BA08: lwc1        $f14, 0x34($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X34);
    // 0x8003BA0C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8003BA10: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x8003BA14: jal         0x800AF1F0
    // 0x8003BA18: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
    func_800AF1F0(rdram, ctx);
        goto after_51;
    // 0x8003BA18: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
    after_51:
    // 0x8003BA1C: sh          $v0, 0x188($sp)
    MEM_H(0X188, ctx->r29) = ctx->r2;
    // 0x8003BA20: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BA24: lhu         $a2, 0x188($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X188);
    // 0x8003BA28: lw          $a1, 0x148($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X148);
    // 0x8003BA2C: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    // 0x8003BA30: jal         0x8003A7F0
    // 0x8003BA34: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_8003A7F0(rdram, ctx);
        goto after_52;
    // 0x8003BA34: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_52:
    // 0x8003BA38: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8003BA3C: lh          $t6, 0x182($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X182);
    // 0x8003BA40: sra         $t5, $s1, 16
    ctx->r13 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8003BA44: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8003BA48: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8003BA4C: sh          $t7, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r15;
    // 0x8003BA50: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003BA54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003BA58: nop

    // 0x8003BA5C: swc1        $f10, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f10.u32l;
    // 0x8003BA60: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BA64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003BA68: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x8003BA6C: nop

    // 0x8003BA70: bne         $t9, $at, L_8003BA84
    if (ctx->r25 != ctx->r1) {
        // 0x8003BA74: nop
    
            goto L_8003BA84;
    }
    // 0x8003BA74: nop

    // 0x8003BA78: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x8003BA7C: b           L_8003BAAC
    // 0x8003BA80: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
        goto L_8003BAAC;
    // 0x8003BA80: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
L_8003BA84:
    // 0x8003BA84: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BA88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003BA8C: lhu         $t1, 0x2($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X2);
    // 0x8003BA90: nop

    // 0x8003BA94: bne         $t1, $at, L_8003BAA4
    if (ctx->r9 != ctx->r1) {
        // 0x8003BA98: nop
    
            goto L_8003BAA4;
    }
    // 0x8003BA98: nop

    // 0x8003BA9C: b           L_8003BAAC
    // 0x8003BAA0: sh          $zero, 0x188($sp)
    MEM_H(0X188, ctx->r29) = 0;
        goto L_8003BAAC;
    // 0x8003BAA0: sh          $zero, 0x188($sp)
    MEM_H(0X188, ctx->r29) = 0;
L_8003BAA4:
    // 0x8003BAA4: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8003BAA8: sh          $t3, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r11;
L_8003BAAC:
    // 0x8003BAAC: b           L_8003BAB4
    // 0x8003BAB0: nop

        goto L_8003BAB4;
    // 0x8003BAB0: nop

L_8003BAB4:
    // 0x8003BAB4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003BAB8: lhu         $t4, 0x728E($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X728E);
    // 0x8003BABC: nop

    // 0x8003BAC0: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8003BAC4: bne         $t5, $zero, L_8003BB48
    if (ctx->r13 != 0) {
        // 0x8003BAC8: nop
    
            goto L_8003BB48;
    }
    // 0x8003BAC8: nop

    // 0x8003BACC: lhu         $t6, 0x188($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X188);
    // 0x8003BAD0: nop

    // 0x8003BAD4: beq         $t6, $zero, L_8003BB48
    if (ctx->r14 == 0) {
        // 0x8003BAD8: nop
    
            goto L_8003BB48;
    }
    // 0x8003BAD8: nop

    // 0x8003BADC: addiu       $t7, $sp, 0xB8
    ctx->r15 = ADD32(ctx->r29, 0XB8);
    // 0x8003BAE0: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8003BAE4: lwc1        $f14, 0x4($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8003BAE8: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x8003BAEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003BAF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003BAF4: lwc1        $f18, 0x15C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003BAF8: lwc1        $f16, 0x158($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003BAFC: lwc1        $f4, 0x154($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003BB00: lw          $a3, 0x168($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X168);
    // 0x8003BB04: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8003BB08: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8003BB0C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8003BB10: jal         0x800C3C80
    // 0x8003BB14: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_53;
    // 0x8003BB14: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_53:
    // 0x8003BB18: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8003BB1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003BB20: nop

    // 0x8003BB24: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8003BB28: nop

    // 0x8003BB2C: bc1t        L_8003BB48
    if (c1cs) {
        // 0x8003BB30: nop
    
            goto L_8003BB48;
    }
    // 0x8003BB30: nop

    // 0x8003BB34: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003BB38: lhu         $t8, 0x728E($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X728E);
    // 0x8003BB3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BB40: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8003BB44: sh          $t9, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r25;
L_8003BB48:
    // 0x8003BB48: lhu         $t0, 0x188($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X188);
    // 0x8003BB4C: nop

    // 0x8003BB50: beq         $t0, $zero, L_8003BC28
    if (ctx->r8 == 0) {
        // 0x8003BB54: nop
    
            goto L_8003BC28;
    }
    // 0x8003BB54: nop

    // 0x8003BB58: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BB5C: nop

    // 0x8003BB60: addiu       $t1, $t2, 0x108
    ctx->r9 = ADD32(ctx->r10, 0X108);
    // 0x8003BB64: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x8003BB68: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8003BB6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003BB70: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003BB74: nop

    // 0x8003BB78: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8003BB7C: nop

    // 0x8003BB80: bc1f        L_8003BB9C
    if (!c1cs) {
        // 0x8003BB84: nop
    
            goto L_8003BB9C;
    }
    // 0x8003BB84: nop

    // 0x8003BB88: lhu         $t3, 0x18A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003BB8C: nop

    // 0x8003BB90: addiu       $t4, $t3, -0x2
    ctx->r12 = ADD32(ctx->r11, -0X2);
    // 0x8003BB94: b           L_8003BBCC
    // 0x8003BB98: sh          $t4, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r12;
        goto L_8003BBCC;
    // 0x8003BB98: sh          $t4, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r12;
L_8003BB9C:
    // 0x8003BB9C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8003BBA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003BBA4: lwc1        $f16, 0x16C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003BBA8: nop

    // 0x8003BBAC: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8003BBB0: nop

    // 0x8003BBB4: bc1f        L_8003BBCC
    if (!c1cs) {
        // 0x8003BBB8: nop
    
            goto L_8003BBCC;
    }
    // 0x8003BBB8: nop

    // 0x8003BBBC: lhu         $t5, 0x18A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003BBC0: nop

    // 0x8003BBC4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8003BBC8: sh          $t6, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r14;
L_8003BBCC:
    // 0x8003BBCC: lhu         $t8, 0x18A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X18A);
    // 0x8003BBD0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003BBD4: lw          $t7, 0x722C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X722C);
    // 0x8003BBD8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003BBDC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8003BBE0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8003BBE4: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8003BBE8: nop

    // 0x8003BBEC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x8003BBF0: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BBF4: nop

    // 0x8003BBF8: lwc1        $f6, 0x28($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X28);
    // 0x8003BBFC: nop

    // 0x8003BC00: swc1        $f6, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f6.u32l;
    // 0x8003BC04: lwc1        $f8, 0x16C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003BC08: nop

    // 0x8003BC0C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8003BC10: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    // 0x8003BC14: jal         0x800C2948
    // 0x8003BC18: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_54;
    // 0x8003BC18: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
    after_54:
    // 0x8003BC1C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BC20: jal         0x800A4638
    // 0x8003BC24: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_800A4638(rdram, ctx);
        goto after_55;
    // 0x8003BC24: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_55:
L_8003BC28:
    // 0x8003BC28: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BC2C: nop

    // 0x8003BC30: lw          $t5, 0x14C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14C);
    // 0x8003BC34: nop

    // 0x8003BC38: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    // 0x8003BC3C: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8003BC40: nop

    // 0x8003BC44: bne         $t6, $zero, L_8003B83C
    if (ctx->r14 != 0) {
        // 0x8003BC48: nop
    
            goto L_8003B83C;
    }
    // 0x8003BC48: nop

L_8003BC4C:
    // 0x8003BC4C: jal         0x800C1850
    // 0x8003BC50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_56;
    // 0x8003BC50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_56:
    // 0x8003BC54: jal         0x800C1850
    // 0x8003BC58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_57;
    // 0x8003BC58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_57:
    // 0x8003BC5C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003BC60: lw          $t8, 0x722C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X722C);
    // 0x8003BC64: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8003BC68: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8003BC6C: jal         0x800A42C8
    // 0x8003BC70: nop

    func_800A42C8(rdram, ctx);
        goto after_58;
    // 0x8003BC70: nop

    after_58:
    // 0x8003BC74: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003BC78: jal         0x800A5854
    // 0x8003BC7C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_800A5854(rdram, ctx);
        goto after_59;
    // 0x8003BC7C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_59:
    // 0x8003BC80: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003BC84: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8003BC88: jal         0x800AD1E4
    // 0x8003BC8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_60;
    // 0x8003BC8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_60:
    // 0x8003BC90: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8003BC94: addiu       $t7, $t7, 0x61D8
    ctx->r15 = ADD32(ctx->r15, 0X61D8);
    // 0x8003BC98: addiu       $t9, $t7, 0x618
    ctx->r25 = ADD32(ctx->r15, 0X618);
    // 0x8003BC9C: sw          $t9, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r25;
    // 0x8003BCA0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003BCA4: lw          $t0, 0x1B44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B44);
    // 0x8003BCA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BCAC: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x8003BCB0: sw          $t2, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r10;
    // 0x8003BCB4: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x8003BCB8: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8003BCBC: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8003BCC0: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8003BCC4: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8003BCC8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003BCCC: lw          $t5, 0x70E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E4);
    // 0x8003BCD0: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8003BCD4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8003BCD8: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8003BCDC: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8003BCE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8003BCE4: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x8003BCE8: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x8003BCEC: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8003BCF0: jal         0x800C1754
    // 0x8003BCF4: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_61;
    // 0x8003BCF4: nop

    after_61:
    // 0x8003BCF8: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x8003BCFC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003BD00: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003BD04: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8003BD08: jal         0x800C2304
    // 0x8003BD0C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_62;
    // 0x8003BD0C: nop

    after_62:
    // 0x8003BD10: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003BD14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003BD18: jal         0x800C23E8
    // 0x8003BD1C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_63;
    // 0x8003BD1C: nop

    after_63:
    // 0x8003BD20: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003BD24: lw          $a0, 0x72C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72C8);
    // 0x8003BD28: jal         0x8003288C
    // 0x8003BD2C: nop

    func_8003288C(rdram, ctx);
        goto after_64;
    // 0x8003BD2C: nop

    after_64:
    // 0x8003BD30: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003BD34: lw          $t1, 0x70E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E4);
    // 0x8003BD38: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003BD3C: lw          $t2, 0x72C8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72C8);
    // 0x8003BD40: sll         $t3, $t1, 6
    ctx->r11 = S32(ctx->r9 << 6);
    // 0x8003BD44: jal         0x800C2AE8
    // 0x8003BD48: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_65;
    // 0x8003BD48: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_65:
    // 0x8003BD4C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003BD50: lw          $a0, 0x72C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72C8);
    // 0x8003BD54: jal         0x800C1A84
    // 0x8003BD58: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_66;
    // 0x8003BD58: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_66:
    // 0x8003BD5C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003BD60: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x8003BD64: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BD68: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8003BD6C: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x8003BD70: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    // 0x8003BD74: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8003BD78: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8003BD7C: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x8003BD80: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8003BD84: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003BD88: lw          $t9, 0x70E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70E4);
    // 0x8003BD8C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003BD90: lw          $t7, 0x72C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C8);
    // 0x8003BD94: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8003BD98: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x8003BD9C: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x8003BDA0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8003BDA4: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8003BDA8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8003BDAC: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8003BDB0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003BDB4: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x8003BDB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BDBC: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8003BDC0: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x8003BDC4: sw          $t5, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r13;
    // 0x8003BDC8: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8003BDCC: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8003BDD0: ori         $t6, $t6, 0x201
    ctx->r14 = ctx->r14 | 0X201;
    // 0x8003BDD4: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8003BDD8: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8003BDDC: nop

    // 0x8003BDE0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8003BDE4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003BDE8: lw          $t7, 0x1B44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B44);
    // 0x8003BDEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BDF0: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x8003BDF4: sw          $t0, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r8;
    // 0x8003BDF8: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x8003BDFC: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8003BE00: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x8003BE04: ori         $t1, $t1, 0x1402
    ctx->r9 = ctx->r9 | 0X1402;
    // 0x8003BE08: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8003BE0C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8003BE10: nop

    // 0x8003BE14: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8003BE18: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003BE1C: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x8003BE20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BE24: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8003BE28: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x8003BE2C: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8003BE30: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8003BE34: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x8003BE38: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8003BE3C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8003BE40: addiu       $t9, $zero, 0x2204
    ctx->r25 = ADD32(0, 0X2204);
    // 0x8003BE44: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8003BE48: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003BE4C: lw          $t0, 0x1B44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B44);
    // 0x8003BE50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BE54: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003BE58: sw          $t1, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r9;
    // 0x8003BE5C: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8003BE60: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003BE64: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x8003BE68: ori         $t2, $t2, 0xFE24
    ctx->r10 = ctx->r10 | 0XFE24;
    // 0x8003BE6C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8003BE70: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8003BE74: lui         $t5, 0xFF30
    ctx->r13 = S32(0XFF30 << 16);
    // 0x8003BE78: ori         $t5, $t5, 0xF3FF
    ctx->r13 = ctx->r13 | 0XF3FF;
    // 0x8003BE7C: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x8003BE80: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003BE84: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x8003BE88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BE8C: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8003BE90: sw          $t8, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r24;
    // 0x8003BE94: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x8003BE98: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8003BE9C: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8003BEA0: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8003BEA4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8003BEA8: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8003BEAC: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x8003BEB0: ori         $t0, $t0, 0x2048
    ctx->r8 = ctx->r8 | 0X2048;
    // 0x8003BEB4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8003BEB8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003BEBC: lw          $t2, 0x1B44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1B44);
    // 0x8003BEC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BEC4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8003BEC8: sw          $t3, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r11;
    // 0x8003BECC: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x8003BED0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8003BED4: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x8003BED8: ori         $t5, $t5, 0x1301
    ctx->r13 = ctx->r13 | 0X1301;
    // 0x8003BEDC: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x8003BEE0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8003BEE4: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8003BEE8: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8003BEEC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003BEF0: lw          $t9, 0x1B44($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1B44);
    // 0x8003BEF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BEF8: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8003BEFC: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x8003BF00: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8003BF04: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003BF08: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8003BF0C: ori         $t0, $t0, 0x1102
    ctx->r8 = ctx->r8 | 0X1102;
    // 0x8003BF10: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8003BF14: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8003BF18: lui         $t2, 0x4
    ctx->r10 = S32(0X4 << 16);
    // 0x8003BF1C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8003BF20: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003BF24: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x8003BF28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BF2C: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8003BF30: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x8003BF34: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x8003BF38: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8003BF3C: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8003BF40: ori         $t6, $t6, 0x1001
    ctx->r14 = ctx->r14 | 0X1001;
    // 0x8003BF44: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8003BF48: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8003BF4C: nop

    // 0x8003BF50: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8003BF54: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003BF58: lw          $t7, 0x1B44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B44);
    // 0x8003BF5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BF60: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x8003BF64: sw          $t0, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r8;
    // 0x8003BF68: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x8003BF6C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8003BF70: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x8003BF74: ori         $t1, $t1, 0xE02
    ctx->r9 = ctx->r9 | 0XE02;
    // 0x8003BF78: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8003BF7C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8003BF80: nop

    // 0x8003BF84: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8003BF88: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003BF8C: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x8003BF90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BF94: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x8003BF98: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x8003BF9C: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x8003BFA0: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8003BFA4: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8003BFA8: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x8003BFAC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8003BFB0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8003BFB4: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8003BFB8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8003BFBC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003BFC0: lw          $t0, 0x1B44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B44);
    // 0x8003BFC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003BFC8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003BFCC: sw          $t1, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r9;
    // 0x8003BFD0: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x8003BFD4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8003BFD8: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8003BFDC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8003BFE0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003BFE4: lw          $t5, 0x72C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72C8);
    // 0x8003BFE8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8003BFEC: lw          $t4, 0xD8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XD8);
    // 0x8003BFF0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8003BFF4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8003BFF8: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8003BFFC: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8003C000: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003C004: lw          $t9, 0x1B44($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1B44);
    // 0x8003C008: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C00C: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8003C010: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x8003C014: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8003C018: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8003C01C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8003C020: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8003C024: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8003C028: nop

    // 0x8003C02C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8003C030: jal         0x800C1A28
    // 0x8003C034: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_67;
    // 0x8003C034: nop

    after_67:
    // 0x8003C038: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003C03C: lw          $t3, 0x7240($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7240);
    // 0x8003C040: nop

    // 0x8003C044: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x8003C048: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x8003C04C: nop

    // 0x8003C050: beq         $t5, $zero, L_8003C0E4
    if (ctx->r13 == 0) {
        // 0x8003C054: nop
    
            goto L_8003C0E4;
    }
    // 0x8003C054: nop

L_8003C058:
    // 0x8003C058: jal         0x800C1850
    // 0x8003C05C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_68;
    // 0x8003C05C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_68:
    // 0x8003C060: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x8003C064: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003C068: lwc1        $f12, 0x0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003C06C: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    // 0x8003C070: jal         0x800C2304
    // 0x8003C074: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_69;
    // 0x8003C074: nop

    after_69:
    // 0x8003C078: jal         0x800C2070
    // 0x8003C07C: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    func_800C2070(rdram, ctx);
        goto after_70;
    // 0x8003C07C: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    after_70:
    // 0x8003C080: addiu       $t6, $sp, 0x104
    ctx->r14 = ADD32(ctx->r29, 0X104);
    // 0x8003C084: lwc1        $f12, 0x30($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X30);
    // 0x8003C088: lwc1        $f14, 0x34($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X34);
    // 0x8003C08C: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x8003C090: jal         0x800AF1F0
    // 0x8003C094: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800AF1F0(rdram, ctx);
        goto after_71;
    // 0x8003C094: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_71:
    // 0x8003C098: beq         $v0, $zero, L_8003C0C0
    if (ctx->r2 == 0) {
        // 0x8003C09C: nop
    
            goto L_8003C0C0;
    }
    // 0x8003C09C: nop

    // 0x8003C0A0: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8003C0A4: nop

    // 0x8003C0A8: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8003C0AC: jal         0x800C25B8
    // 0x8003C0B0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_72;
    // 0x8003C0B0: nop

    after_72:
    // 0x8003C0B4: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x8003C0B8: jal         0x800A4638
    // 0x8003C0BC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800A4638(rdram, ctx);
        goto after_73;
    // 0x8003C0BC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_73:
L_8003C0C0:
    // 0x8003C0C0: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8003C0C4: nop

    // 0x8003C0C8: lw          $t7, 0x128($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X128);
    // 0x8003C0CC: nop

    // 0x8003C0D0: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8003C0D4: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x8003C0D8: nop

    // 0x8003C0DC: bne         $t0, $zero, L_8003C058
    if (ctx->r8 != 0) {
        // 0x8003C0E0: nop
    
            goto L_8003C058;
    }
    // 0x8003C0E0: nop

L_8003C0E4:
    // 0x8003C0E4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003C0E8: lw          $t1, 0x7220($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7220);
    // 0x8003C0EC: nop

    // 0x8003C0F0: sw          $t1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r9;
    // 0x8003C0F4: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x8003C0F8: nop

    // 0x8003C0FC: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x8003C100: jal         0x800C1850
    // 0x8003C104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_74;
    // 0x8003C104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_74:
    // 0x8003C108: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x8003C10C: nop

    // 0x8003C110: lwc1        $f12, 0xCC($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x8003C114: lwc1        $f14, 0xD0($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8003C118: lw          $a2, 0xD4($t3)
    ctx->r6 = MEM_W(ctx->r11, 0XD4);
    // 0x8003C11C: jal         0x800C2304
    // 0x8003C120: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_75;
    // 0x8003C120: nop

    after_75:
    // 0x8003C124: jal         0x800C2070
    // 0x8003C128: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    func_800C2070(rdram, ctx);
        goto after_76;
    // 0x8003C128: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    after_76:
    // 0x8003C12C: addiu       $t5, $sp, 0x104
    ctx->r13 = ADD32(ctx->r29, 0X104);
    // 0x8003C130: lwc1        $f10, 0x38($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X38);
    // 0x8003C134: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8003C138: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003C13C: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8003C140: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8003C144: swc1        $f18, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f18.u32l;
    // 0x8003C148: bc1f        L_8003C29C
    if (!c1cs) {
        // 0x8003C14C: nop
    
            goto L_8003C29C;
    }
    // 0x8003C14C: nop

    // 0x8003C150: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003C154: lhu         $t4, 0x728E($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X728E);
    // 0x8003C158: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8003C15C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8003C160: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C164: sh          $t6, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r14;
    // 0x8003C168: jal         0x800C4240
    // 0x8003C16C: nop

    guRandom(rdram, ctx);
        goto after_77;
    // 0x8003C16C: nop

    after_77:
    // 0x8003C170: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8003C174: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8003C178: mfhi        $t8
    ctx->r24 = hi;
    // 0x8003C17C: bne         $t8, $zero, L_8003C294
    if (ctx->r24 != 0) {
        // 0x8003C180: nop
    
            goto L_8003C294;
    }
    // 0x8003C180: nop

    // 0x8003C184: jal         0x800C1850
    // 0x8003C188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_78;
    // 0x8003C188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_78:
    // 0x8003C18C: lwc1        $f12, 0x15C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003C190: lwc1        $f14, 0x158($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003C194: lw          $a2, 0x154($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X154);
    // 0x8003C198: jal         0x800C2304
    // 0x8003C19C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_79;
    // 0x8003C19C: nop

    after_79:
    // 0x8003C1A0: lwc1        $f12, 0x14C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003C1A4: jal         0x800C25B8
    // 0x8003C1A8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_80;
    // 0x8003C1A8: nop

    after_80:
    // 0x8003C1AC: lwc1        $f12, 0x150($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003C1B0: jal         0x800C23E8
    // 0x8003C1B4: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_81;
    // 0x8003C1B4: nop

    after_81:
    // 0x8003C1B8: jal         0x800C4240
    // 0x8003C1BC: nop

    guRandom(rdram, ctx);
        goto after_82;
    // 0x8003C1BC: nop

    after_82:
    // 0x8003C1C0: jal         0x800C4240
    // 0x8003C1C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    guRandom(rdram, ctx);
        goto after_83;
    // 0x8003C1C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_83:
    // 0x8003C1C8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8003C1CC: div         $zero, $s2, $at
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r1)));
    // 0x8003C1D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003C1D4: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8003C1D8: lw          $t0, -0x4CCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4CCC);
    // 0x8003C1DC: addiu       $t1, $zero, -0x64
    ctx->r9 = ADD32(0, -0X64);
    // 0x8003C1E0: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x8003C1E4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8003C1E8: nop

    // 0x8003C1EC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003C1F0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8003C1F4: mfhi        $t9
    ctx->r25 = hi;
    // 0x8003C1F8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8003C1FC: nop

    // 0x8003C200: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x8003C204: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003C208: mfhi        $t7
    ctx->r15 = hi;
    // 0x8003C20C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8003C210: jal         0x800C2304
    // 0x8003C214: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_84;
    // 0x8003C214: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_84:
    // 0x8003C218: jal         0x800B1844
    // 0x8003C21C: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    func_800B1844(rdram, ctx);
        goto after_85;
    // 0x8003C21C: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_85:
    // 0x8003C220: addiu       $t3, $sp, 0xB8
    ctx->r11 = ADD32(ctx->r29, 0XB8);
    // 0x8003C224: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8003C228: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x8003C22C: nop

    // 0x8003C230: swc1        $f10, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f10.u32l;
    // 0x8003C234: addiu       $t4, $sp, 0xB8
    ctx->r12 = ADD32(ctx->r29, 0XB8);
    // 0x8003C238: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8003C23C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8003C240: nop

    // 0x8003C244: swc1        $f18, 0xD4($t6)
    MEM_W(0XD4, ctx->r14) = ctx->f18.u32l;
    // 0x8003C248: addiu       $t8, $sp, 0xB8
    ctx->r24 = ADD32(ctx->r29, 0XB8);
    // 0x8003C24C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003C250: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003C254: lwc1        $f20, 0x4($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8003C258: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8003C25C: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x8003C260: swc1        $f20, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f20.u32l;
    // 0x8003C264: bc1f        L_8003C280
    if (!c1cs) {
        // 0x8003C268: nop
    
            goto L_8003C280;
    }
    // 0x8003C268: nop

    // 0x8003C26C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003C270: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003C274: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8003C278: nop

    // 0x8003C27C: swc1        $f4, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f4.u32l;
L_8003C280:
    // 0x8003C280: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003C284: lhu         $t1, 0x728E($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X728E);
    // 0x8003C288: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C28C: ori         $t0, $t1, 0x4
    ctx->r8 = ctx->r9 | 0X4;
    // 0x8003C290: sh          $t0, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r8;
L_8003C294:
    // 0x8003C294: b           L_8003C3C8
    // 0x8003C298: nop

        goto L_8003C3C8;
    // 0x8003C298: nop

L_8003C29C:
    // 0x8003C29C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003C2A0: lhu         $t2, 0x728E($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X728E);
    // 0x8003C2A4: nop

    // 0x8003C2A8: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8003C2AC: beq         $t3, $zero, L_8003C3C8
    if (ctx->r11 == 0) {
        // 0x8003C2B0: nop
    
            goto L_8003C3C8;
    }
    // 0x8003C2B0: nop

    // 0x8003C2B4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8003C2B8: lw          $t5, -0x4CCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CCC);
    // 0x8003C2BC: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C2C0: addiu       $t4, $t5, 0x64
    ctx->r12 = ADD32(ctx->r13, 0X64);
    // 0x8003C2C4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8003C2C8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003C2CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003C2D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003C2D4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003C2D8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8003C2DC: swc1        $f18, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f18.u32l;
    // 0x8003C2E0: bc1f        L_8003C2F8
    if (!c1cs) {
        // 0x8003C2E4: nop
    
            goto L_8003C2F8;
    }
    // 0x8003C2E4: nop

    // 0x8003C2E8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003C2EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003C2F0: b           L_8003C320
    // 0x8003C2F4: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
        goto L_8003C320;
    // 0x8003C2F4: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
L_8003C2F8:
    // 0x8003C2F8: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C2FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003C300: nop

    // 0x8003C304: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8003C308: nop

    // 0x8003C30C: bc1f        L_8003C320
    if (!c1cs) {
        // 0x8003C310: nop
    
            goto L_8003C320;
    }
    // 0x8003C310: nop

    // 0x8003C314: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003C318: nop

    // 0x8003C31C: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
L_8003C320:
    // 0x8003C320: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003C324: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003C328: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8003C32C: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C330: nop

    // 0x8003C334: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003C338: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8003C33C: nop

    // 0x8003C340: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8003C344: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8003C348: beq         $t8, $zero, L_8003C39C
    if (ctx->r24 == 0) {
        // 0x8003C34C: nop
    
            goto L_8003C39C;
    }
    // 0x8003C34C: nop

    // 0x8003C350: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8003C354: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003C358: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003C35C: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8003C360: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8003C364: nop

    // 0x8003C368: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003C36C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8003C370: nop

    // 0x8003C374: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8003C378: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8003C37C: bne         $t8, $zero, L_8003C394
    if (ctx->r24 != 0) {
        // 0x8003C380: nop
    
            goto L_8003C394;
    }
    // 0x8003C380: nop

    // 0x8003C384: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8003C388: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003C38C: b           L_8003C3AC
    // 0x8003C390: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8003C3AC;
    // 0x8003C390: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8003C394:
    // 0x8003C394: b           L_8003C3AC
    // 0x8003C398: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8003C3AC;
    // 0x8003C398: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8003C39C:
    // 0x8003C39C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8003C3A0: nop

    // 0x8003C3A4: bltz        $t8, L_8003C394
    if (SIGNED(ctx->r24) < 0) {
        // 0x8003C3A8: nop
    
            goto L_8003C394;
    }
    // 0x8003C3A8: nop

L_8003C3AC:
    // 0x8003C3AC: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8003C3B0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003C3B4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8003C3B8: sh          $t9, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r25;
    // 0x8003C3BC: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x8003C3C0: jal         0x800997D8
    // 0x8003C3C4: nop

    func_800997D8(rdram, ctx);
        goto after_86;
    // 0x8003C3C4: nop

    after_86:
L_8003C3C8:
    // 0x8003C3C8: lwc1        $f12, 0x15C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003C3CC: lwc1        $f14, 0x158($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003C3D0: lw          $a2, 0x154($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X154);
    // 0x8003C3D4: jal         0x8003A0A4
    // 0x8003C3D8: addiu       $a3, $sp, 0xC4
    ctx->r7 = ADD32(ctx->r29, 0XC4);
    func_8003A0A4(rdram, ctx);
        goto after_87;
    // 0x8003C3D8: addiu       $a3, $sp, 0xC4
    ctx->r7 = ADD32(ctx->r29, 0XC4);
    after_87:
    // 0x8003C3DC: jal         0x8003AEB0
    // 0x8003C3E0: nop

    func_8003AEB0(rdram, ctx);
        goto after_88;
    // 0x8003C3E0: nop

    after_88:
    // 0x8003C3E4: beq         $v0, $zero, L_8003C474
    if (ctx->r2 == 0) {
        // 0x8003C3E8: nop
    
            goto L_8003C474;
    }
    // 0x8003C3E8: nop

    // 0x8003C3EC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003C3F0: lhu         $t1, 0x728E($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X728E);
    // 0x8003C3F4: nop

    // 0x8003C3F8: andi        $t0, $t1, 0x2
    ctx->r8 = ctx->r9 & 0X2;
    // 0x8003C3FC: bne         $t0, $zero, L_8003C474
    if (ctx->r8 != 0) {
        // 0x8003C400: nop
    
            goto L_8003C474;
    }
    // 0x8003C400: nop

    // 0x8003C404: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003C408: lhu         $t2, 0x728E($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X728E);
    // 0x8003C40C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C410: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8003C414: sh          $t3, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r11;
    // 0x8003C418: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003C41C: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x8003C420: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003C424: lhu         $t4, 0x1C($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X1C);
    // 0x8003C428: nop

    // 0x8003C42C: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8003C430: sh          $t6, 0x1C($t5)
    MEM_H(0X1C, ctx->r13) = ctx->r14;
    // 0x8003C434: lw          $t8, 0x7278($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7278);
    // 0x8003C438: nop

    // 0x8003C43C: lhu         $t9, 0x1C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1C);
    // 0x8003C440: nop

    // 0x8003C444: bne         $t9, $zero, L_8003C464
    if (ctx->r25 != 0) {
        // 0x8003C448: nop
    
            goto L_8003C464;
    }
    // 0x8003C448: nop

    // 0x8003C44C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003C450: lhu         $t7, 0x728E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X728E);
    // 0x8003C454: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C458: ori         $t1, $t7, 0x8
    ctx->r9 = ctx->r15 | 0X8;
    // 0x8003C45C: b           L_8003C46C
    // 0x8003C460: sh          $t1, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r9;
        goto L_8003C46C;
    // 0x8003C460: sh          $t1, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r9;
L_8003C464:
    // 0x8003C464: jal         0x800B9000
    // 0x8003C468: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    func_800B9000(rdram, ctx);
        goto after_89;
    // 0x8003C468: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    after_89:
L_8003C46C:
    // 0x8003C46C: jal         0x80035CF8
    // 0x8003C470: nop

    func_80035CF8(rdram, ctx);
        goto after_90;
    // 0x8003C470: nop

    after_90:
L_8003C474:
    // 0x8003C474: jal         0x80033EFC
    // 0x8003C478: nop

    func_80033EFC(rdram, ctx);
        goto after_91;
    // 0x8003C478: nop

    after_91:
    // 0x8003C47C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003C480: lhu         $t0, 0x728E($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X728E);
    // 0x8003C484: nop

    // 0x8003C488: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8003C48C: bne         $t2, $zero, L_8003C848
    if (ctx->r10 != 0) {
        // 0x8003C490: nop
    
            goto L_8003C848;
    }
    // 0x8003C490: nop

    // 0x8003C494: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003C498: lwc1        $f4, -0x14AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14AC);
    // 0x8003C49C: lwc1        $f6, 0x160($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8003C4A0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003C4A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003C4A8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003C4AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003C4B0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8003C4B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003C4B8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003C4BC: add.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d + ctx->f18.d;
    // 0x8003C4C0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003C4C4: div.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f16.d);
    // 0x8003C4C8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003C4CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003C4D0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8003C4D4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8003C4D8: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8003C4DC: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
    // 0x8003C4E0: bc1f        L_8003C4F8
    if (!c1cs) {
        // 0x8003C4E4: nop
    
            goto L_8003C4F8;
    }
    // 0x8003C4E4: nop

    // 0x8003C4E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003C4EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003C4F0: nop

    // 0x8003C4F4: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
L_8003C4F8:
    // 0x8003C4F8: lwc1        $f16, 0x174($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003C4FC: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C500: nop

    // 0x8003C504: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8003C508: swc1        $f8, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->f8.u32l;
    // 0x8003C50C: lwc1        $f10, 0x170($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003C510: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C514: nop

    // 0x8003C518: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8003C51C: swc1        $f4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f4.u32l;
    // 0x8003C520: lwc1        $f16, 0x17C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8003C524: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003C528: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003C52C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8003C530: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8003C534: nop

    // 0x8003C538: bc1f        L_8003C584
    if (!c1cs) {
        // 0x8003C53C: nop
    
            goto L_8003C584;
    }
    // 0x8003C53C: nop

    // 0x8003C540: lwc1        $f10, 0x144($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003C544: lwc1        $f18, 0x174($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003C548: nop

    // 0x8003C54C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8003C550: nop

    // 0x8003C554: bc1f        L_8003C584
    if (!c1cs) {
        // 0x8003C558: nop
    
            goto L_8003C584;
    }
    // 0x8003C558: nop

    // 0x8003C55C: lwc1        $f4, 0x16C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C560: nop

    // 0x8003C564: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8003C568: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8003C56C: swc1        $f16, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f16.u32l;
    // 0x8003C570: bc1f        L_8003C584
    if (!c1cs) {
        // 0x8003C574: nop
    
            goto L_8003C584;
    }
    // 0x8003C574: nop

    // 0x8003C578: lwc1        $f6, 0x174($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003C57C: b           L_8003C5E8
    // 0x8003C580: swc1        $f6, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f6.u32l;
        goto L_8003C5E8;
    // 0x8003C580: swc1        $f6, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f6.u32l;
L_8003C584:
    // 0x8003C584: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8003C588: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8003C58C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003C590: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8003C594: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8003C598: nop

    // 0x8003C59C: bc1f        L_8003C5E8
    if (!c1cs) {
        // 0x8003C5A0: nop
    
            goto L_8003C5E8;
    }
    // 0x8003C5A0: nop

    // 0x8003C5A4: lwc1        $f16, 0x144($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003C5A8: lwc1        $f18, 0x174($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003C5AC: nop

    // 0x8003C5B0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8003C5B4: nop

    // 0x8003C5B8: bc1f        L_8003C5E8
    if (!c1cs) {
        // 0x8003C5BC: nop
    
            goto L_8003C5E8;
    }
    // 0x8003C5BC: nop

    // 0x8003C5C0: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C5C4: nop

    // 0x8003C5C8: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8003C5CC: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8003C5D0: swc1        $f8, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f8.u32l;
    // 0x8003C5D4: bc1f        L_8003C5E8
    if (!c1cs) {
        // 0x8003C5D8: nop
    
            goto L_8003C5E8;
    }
    // 0x8003C5D8: nop

    // 0x8003C5DC: lwc1        $f10, 0x174($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8003C5E0: nop

    // 0x8003C5E4: swc1        $f10, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f10.u32l;
L_8003C5E8:
    // 0x8003C5E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003C5EC: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003C5F0: lwc1        $f7, -0x14A8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X14A8);
    // 0x8003C5F4: lwc1        $f6, -0x14A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X14A4);
    // 0x8003C5F8: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8003C5FC: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x8003C600: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003C604: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003C608: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8003C60C: lwc1        $f18, -0x149C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X149C);
    // 0x8003C610: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x8003C614: lwc1        $f19, -0x14A0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X14A0);
    // 0x8003C618: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8003C61C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8003C620: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8003C624: swc1        $f16, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f16.u32l;
    // 0x8003C628: bc1f        L_8003C654
    if (!c1cs) {
        // 0x8003C62C: nop
    
            goto L_8003C654;
    }
    // 0x8003C62C: nop

    // 0x8003C630: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003C634: lwc1        $f10, 0x14C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003C638: lwc1        $f5, -0x1498($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1498);
    // 0x8003C63C: lwc1        $f4, -0x1494($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1494);
    // 0x8003C640: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8003C644: sub.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d - ctx->f4.d;
    // 0x8003C648: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8003C64C: b           L_8003C694
    // 0x8003C650: swc1        $f6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f6.u32l;
        goto L_8003C694;
    // 0x8003C650: swc1        $f6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f6.u32l;
L_8003C654:
    // 0x8003C654: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003C658: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8003C65C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003C660: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8003C664: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x8003C668: nop

    // 0x8003C66C: bc1f        L_8003C694
    if (!c1cs) {
        // 0x8003C670: nop
    
            goto L_8003C694;
    }
    // 0x8003C670: nop

    // 0x8003C674: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003C678: lwc1        $f4, 0x14C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003C67C: lwc1        $f7, -0x1490($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1490);
    // 0x8003C680: lwc1        $f6, -0x148C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X148C);
    // 0x8003C684: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8003C688: add.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f16.d + ctx->f6.d;
    // 0x8003C68C: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8003C690: swc1        $f10, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f10.u32l;
L_8003C694:
    // 0x8003C694: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8003C698: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8003C69C: jal         0x80034230
    // 0x8003C6A0: addiu       $a0, $sp, 0x144
    ctx->r4 = ADD32(ctx->r29, 0X144);
    func_80034230(rdram, ctx);
        goto after_92;
    // 0x8003C6A0: addiu       $a0, $sp, 0x144
    ctx->r4 = ADD32(ctx->r29, 0X144);
    after_92:
    // 0x8003C6A4: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8003C6A8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8003C6AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003C6B0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8003C6B4: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x8003C6B8: nop

    // 0x8003C6BC: bc1f        L_8003C728
    if (!c1cs) {
        // 0x8003C6C0: nop
    
            goto L_8003C728;
    }
    // 0x8003C6C0: nop

    // 0x8003C6C4: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8003C6C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003C6CC: lwc1        $f6, 0x158($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003C6D0: nop

    // 0x8003C6D4: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8003C6D8: nop

    // 0x8003C6DC: bc1f        L_8003C728
    if (!c1cs) {
        // 0x8003C6E0: nop
    
            goto L_8003C728;
    }
    // 0x8003C6E0: nop

    // 0x8003C6E4: lwc1        $f10, 0x150($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003C6E8: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003C6EC: nop

    // 0x8003C6F0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8003C6F4: nop

    // 0x8003C6F8: bc1f        L_8003C728
    if (!c1cs) {
        // 0x8003C6FC: nop
    
            goto L_8003C728;
    }
    // 0x8003C6FC: nop

    // 0x8003C700: lwc1        $f4, 0x16C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C704: nop

    // 0x8003C708: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8003C70C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8003C710: swc1        $f16, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f16.u32l;
    // 0x8003C714: bc1f        L_8003C728
    if (!c1cs) {
        // 0x8003C718: nop
    
            goto L_8003C728;
    }
    // 0x8003C718: nop

    // 0x8003C71C: lwc1        $f6, 0x170($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003C720: b           L_8003C7AC
    // 0x8003C724: swc1        $f6, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f6.u32l;
        goto L_8003C7AC;
    // 0x8003C724: swc1        $f6, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f6.u32l;
L_8003C728:
    // 0x8003C728: lwc1        $f18, 0x178($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8003C72C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8003C730: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003C734: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8003C738: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8003C73C: nop

    // 0x8003C740: bc1f        L_8003C7AC
    if (!c1cs) {
        // 0x8003C744: nop
    
            goto L_8003C7AC;
    }
    // 0x8003C744: nop

    // 0x8003C748: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8003C74C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003C750: lwc1        $f16, 0x158($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003C754: nop

    // 0x8003C758: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8003C75C: nop

    // 0x8003C760: bc1f        L_8003C7AC
    if (!c1cs) {
        // 0x8003C764: nop
    
            goto L_8003C7AC;
    }
    // 0x8003C764: nop

    // 0x8003C768: lwc1        $f6, 0x150($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003C76C: lwc1        $f18, 0x170($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003C770: nop

    // 0x8003C774: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8003C778: nop

    // 0x8003C77C: bc1f        L_8003C7AC
    if (!c1cs) {
        // 0x8003C780: nop
    
            goto L_8003C7AC;
    }
    // 0x8003C780: nop

    // 0x8003C784: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003C788: nop

    // 0x8003C78C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003C790: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8003C794: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
    // 0x8003C798: bc1f        L_8003C7AC
    if (!c1cs) {
        // 0x8003C79C: nop
    
            goto L_8003C7AC;
    }
    // 0x8003C79C: nop

    // 0x8003C7A0: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8003C7A4: nop

    // 0x8003C7A8: swc1        $f16, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f16.u32l;
L_8003C7AC:
    // 0x8003C7AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003C7B0: lwc1        $f8, -0x1488($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1488);
    // 0x8003C7B4: nop

    // 0x8003C7B8: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
    // 0x8003C7BC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8003C7C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003C7C4: lwc1        $f6, 0x158($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003C7C8: nop

    // 0x8003C7CC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8003C7D0: nop

    // 0x8003C7D4: bc1f        L_8003C7FC
    if (!c1cs) {
        // 0x8003C7D8: nop
    
            goto L_8003C7FC;
    }
    // 0x8003C7D8: nop

    // 0x8003C7DC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8003C7E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003C7E4: nop

    // 0x8003C7E8: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
    // 0x8003C7EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003C7F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003C7F4: b           L_8003C83C
    // 0x8003C7F8: swc1        $f18, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f18.u32l;
        goto L_8003C83C;
    // 0x8003C7F8: swc1        $f18, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f18.u32l;
L_8003C7FC:
    // 0x8003C7FC: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8003C800: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003C804: lwc1        $f16, 0x158($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003C808: nop

    // 0x8003C80C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8003C810: nop

    // 0x8003C814: bc1f        L_8003C83C
    if (!c1cs) {
        // 0x8003C818: nop
    
            goto L_8003C83C;
    }
    // 0x8003C818: nop

    // 0x8003C81C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8003C820: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003C824: nop

    // 0x8003C828: swc1        $f6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f6.u32l;
    // 0x8003C82C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003C830: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003C834: nop

    // 0x8003C838: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
L_8003C83C:
    // 0x8003C83C: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x8003C840: jal         0x80034230
    // 0x8003C844: addiu       $a0, $sp, 0x150
    ctx->r4 = ADD32(ctx->r29, 0X150);
    func_80034230(rdram, ctx);
        goto after_93;
    // 0x8003C844: addiu       $a0, $sp, 0x150
    ctx->r4 = ADD32(ctx->r29, 0X150);
    after_93:
L_8003C848:
    // 0x8003C848: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003C84C: lwc1        $f4, 0x158($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003C850: lwc1        $f17, -0x1480($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1480);
    // 0x8003C854: lwc1        $f16, -0x147C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X147C);
    // 0x8003C858: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003C85C: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8003C860: nop

    // 0x8003C864: bc1f        L_8003C904
    if (!c1cs) {
        // 0x8003C868: nop
    
            goto L_8003C904;
    }
    // 0x8003C868: nop

    // 0x8003C86C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003C870: lhu         $t3, 0x728E($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X728E);
    // 0x8003C874: nop

    // 0x8003C878: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x8003C87C: bne         $t4, $zero, L_8003C904
    if (ctx->r12 != 0) {
        // 0x8003C880: nop
    
            goto L_8003C904;
    }
    // 0x8003C880: nop

    // 0x8003C884: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8003C888: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003C88C: lui         $at, 0xC29E
    ctx->r1 = S32(0XC29E << 16);
    // 0x8003C890: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003C894: lw          $a2, 0x15C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X15C);
    // 0x8003C898: lw          $a3, 0x154($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X154);
    // 0x8003C89C: jal         0x800C3C08
    // 0x8003C8A0: nop

    MathUtil_GetDistance2D(rdram, ctx);
        goto after_94;
    // 0x8003C8A0: nop

    after_94:
    // 0x8003C8A4: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8003C8A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003C8AC: lwc1        $f6, 0x158($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003C8B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003C8B4: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8003C8B8: lwc1        $f17, -0x1478($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1478);
    // 0x8003C8BC: lwc1        $f16, -0x1474($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1474);
    // 0x8003C8C0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003C8C4: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8003C8C8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8003C8CC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003C8D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003C8D4: nop

    // 0x8003C8D8: sub.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d - ctx->f6.d;
    // 0x8003C8DC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8003C8E0: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x8003C8E4: nop

    // 0x8003C8E8: bc1f        L_8003C904
    if (!c1cs) {
        // 0x8003C8EC: nop
    
            goto L_8003C904;
    }
    // 0x8003C8EC: nop

    // 0x8003C8F0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003C8F4: lhu         $t6, 0x728E($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X728E);
    // 0x8003C8F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C8FC: ori         $t5, $t6, 0x8
    ctx->r13 = ctx->r14 | 0X8;
    // 0x8003C900: sh          $t5, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r13;
L_8003C904:
    // 0x8003C904: jal         0x80034360
    // 0x8003C908: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_80034360(rdram, ctx);
        goto after_95;
    // 0x8003C908: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_95:
    // 0x8003C90C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003C910: lhu         $t8, 0x728E($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X728E);
    // 0x8003C914: nop

    // 0x8003C918: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8003C91C: beq         $t9, $zero, L_8003CAC8
    if (ctx->r25 == 0) {
        // 0x8003C920: nop
    
            goto L_8003CAC8;
    }
    // 0x8003C920: nop

    // 0x8003C924: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C928: lwc1        $f16, 0x720C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x8003C92C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C930: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003C934: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C938: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003C93C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003C940: swc1        $f10, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f10.u32l;
    // 0x8003C944: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8003C948: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003C94C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003C950: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8003C954: nop

    // 0x8003C958: bc1f        L_8003C99C
    if (!c1cs) {
        // 0x8003C95C: nop
    
            goto L_8003C99C;
    }
    // 0x8003C95C: nop

    // 0x8003C960: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8003C964: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003C968: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003C96C: jal         0x80099F90
    // 0x8003C970: nop

    func_80099F90(rdram, ctx);
        goto after_96;
    // 0x8003C970: nop

    after_96:
    // 0x8003C974: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003C978: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C97C: swc1        $f4, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f4.u32l;
    // 0x8003C980: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003C984: lhu         $t7, 0x728E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X728E);
    // 0x8003C988: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8003C98C: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x8003C990: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003C994: b           L_8003CA14
    // 0x8003C998: sh          $t1, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r9;
        goto L_8003CA14;
    // 0x8003C998: sh          $t1, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r9;
L_8003C99C:
    // 0x8003C99C: jal         0x800C4240
    // 0x8003C9A0: nop

    guRandom(rdram, ctx);
        goto after_97;
    // 0x8003C9A0: nop

    after_97:
    // 0x8003C9A4: jal         0x800C4240
    // 0x8003C9A8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    guRandom(rdram, ctx);
        goto after_98;
    // 0x8003C9A8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_98:
    // 0x8003C9AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003C9B0: bgez        $s2, L_8003C9C4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8003C9B4: andi        $t0, $s2, 0xF
        ctx->r8 = ctx->r18 & 0XF;
            goto L_8003C9C4;
    }
    // 0x8003C9B4: andi        $t0, $s2, 0xF
    ctx->r8 = ctx->r18 & 0XF;
    // 0x8003C9B8: beq         $t0, $zero, L_8003C9C4
    if (ctx->r8 == 0) {
        // 0x8003C9BC: nop
    
            goto L_8003C9C4;
    }
    // 0x8003C9BC: nop

    // 0x8003C9C0: addiu       $t0, $t0, -0x10
    ctx->r8 = ADD32(ctx->r8, -0X10);
L_8003C9C4:
    // 0x8003C9C4: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8003C9C8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8003C9CC: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8003C9D0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003C9D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003C9D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003C9DC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003C9E0: sub.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d - ctx->f10.d;
    // 0x8003C9E4: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8003C9E8: bgez        $s0, L_8003C9FC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8003C9EC: andi        $t2, $s0, 0xF
        ctx->r10 = ctx->r16 & 0XF;
            goto L_8003C9FC;
    }
    // 0x8003C9EC: andi        $t2, $s0, 0xF
    ctx->r10 = ctx->r16 & 0XF;
    // 0x8003C9F0: beq         $t2, $zero, L_8003C9FC
    if (ctx->r10 == 0) {
        // 0x8003C9F4: nop
    
            goto L_8003C9FC;
    }
    // 0x8003C9F4: nop

    // 0x8003C9F8: addiu       $t2, $t2, -0x10
    ctx->r10 = ADD32(ctx->r10, -0X10);
L_8003C9FC:
    // 0x8003C9FC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8003CA00: nop

    // 0x8003CA04: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x8003CA08: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x8003CA0C: jal         0x80099F90
    // 0x8003CA10: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    func_80099F90(rdram, ctx);
        goto after_99;
    // 0x8003CA10: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    after_99:
L_8003CA14:
    // 0x8003CA14: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003CA18: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003CA1C: lwc1        $f10, 0x61C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x8003CA20: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8003CA24: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003CA28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003CA2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003CA30: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003CA34: lwc1        $f8, 0x61C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x8003CA38: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003CA3C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8003CA40: nop

    // 0x8003CA44: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8003CA48: nop

    // 0x8003CA4C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8003CA50: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003CA54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003CA58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003CA5C: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8003CA60: lwc1        $f16, 0x61C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8003CA64: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8003CA68: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003CA6C: nop

    // 0x8003CA70: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003CA74: nop

    // 0x8003CA78: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003CA7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003CA80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003CA84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003CA88: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003CA8C: lwc1        $f10, 0x61D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x8003CA90: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003CA94: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8003CA98: nop

    // 0x8003CA9C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8003CAA0: nop

    // 0x8003CAA4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8003CAA8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003CAAC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003CAB0: nop

    // 0x8003CAB4: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003CAB8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8003CABC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003CAC0: jal         0x800AC0A4
    // 0x8003CAC4: nop

    func_800AC0A4(rdram, ctx);
        goto after_100;
    // 0x8003CAC4: nop

    after_100:
L_8003CAC8:
    // 0x8003CAC8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003CACC: lhu         $t8, 0x728E($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X728E);
    // 0x8003CAD0: nop

    // 0x8003CAD4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8003CAD8: beq         $t9, $zero, L_8003CBF0
    if (ctx->r25 == 0) {
        // 0x8003CADC: nop
    
            goto L_8003CBF0;
    }
    // 0x8003CADC: nop

    // 0x8003CAE0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8003CAE4: lhu         $t7, -0x73C8($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X73C8);
    // 0x8003CAE8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003CAEC: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x8003CAF0: sh          $t1, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r9;
    // 0x8003CAF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003CAF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003CAFC: swc1        $f8, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f8.u32l;
    // 0x8003CB00: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003CB04: sw          $zero, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = 0;
    // 0x8003CB08: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003CB0C: sw          $zero, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = 0;
    // 0x8003CB10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003CB14: sw          $zero, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = 0;
    // 0x8003CB18: jal         0x80059D80
    // 0x8003CB1C: nop

    func_80059D80(rdram, ctx);
        goto after_101;
    // 0x8003CB1C: nop

    after_101:
    // 0x8003CB20: jal         0x800B9000
    // 0x8003CB24: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    func_800B9000(rdram, ctx);
        goto after_102;
    // 0x8003CB24: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_102:
    // 0x8003CB28: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003CB2C: sb          $zero, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = 0;
    // 0x8003CB30: jal         0x800C1850
    // 0x8003CB34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_103;
    // 0x8003CB34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_103:
    // 0x8003CB38: lwc1        $f12, 0x15C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003CB3C: lwc1        $f14, 0x158($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003CB40: lw          $a2, 0x154($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X154);
    // 0x8003CB44: jal         0x800C2304
    // 0x8003CB48: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_104;
    // 0x8003CB48: nop

    after_104:
    // 0x8003CB4C: jal         0x800C1D44
    // 0x8003CB50: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    func_800C1D44(rdram, ctx);
        goto after_105;
    // 0x8003CB50: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    after_105:
    // 0x8003CB54: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8003CB58: lw          $t0, -0x4CCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4CCC);
    // 0x8003CB5C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8003CB60: subu        $t3, $t2, $t0
    ctx->r11 = SUB32(ctx->r10, ctx->r8);
    // 0x8003CB64: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8003CB68: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003CB6C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003CB70: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003CB74: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003CB78: jal         0x800C2304
    // 0x8003CB7C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_106;
    // 0x8003CB7C: nop

    after_106:
    // 0x8003CB80: jal         0x800B1844
    // 0x8003CB84: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    func_800B1844(rdram, ctx);
        goto after_107;
    // 0x8003CB84: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_107:
    // 0x8003CB88: addiu       $t4, $sp, 0xB8
    ctx->r12 = ADD32(ctx->r29, 0XB8);
    // 0x8003CB8C: lwc1        $f12, 0x0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003CB90: lwc1        $f14, 0x4($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8003CB94: lw          $a2, 0x8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X8);
    // 0x8003CB98: addiu       $t6, $zero, 0x69
    ctx->r14 = ADD32(0, 0X69);
    // 0x8003CB9C: addiu       $t5, $zero, 0x1E1
    ctx->r13 = ADD32(0, 0X1E1);
    // 0x8003CBA0: addiu       $t8, $zero, 0x36
    ctx->r24 = ADD32(0, 0X36);
    // 0x8003CBA4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8003CBA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8003CBAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003CBB0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8003CBB4: jal         0x80033D78
    // 0x8003CBB8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    func_80033D78(rdram, ctx);
        goto after_108;
    // 0x8003CBB8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_108:
    // 0x8003CBBC: jal         0x80031728
    // 0x8003CBC0: nop

    func_80031728(rdram, ctx);
        goto after_109;
    // 0x8003CBC0: nop

    after_109:
    // 0x8003CBC4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003CBC8: lhu         $t9, 0x728E($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X728E);
    // 0x8003CBCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003CBD0: ori         $t7, $t9, 0x3
    ctx->r15 = ctx->r25 | 0X3;
    // 0x8003CBD4: sh          $t7, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r15;
    // 0x8003CBD8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003CBDC: lhu         $t1, 0x728E($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X728E);
    // 0x8003CBE0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8003CBE4: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8003CBE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003CBEC: sh          $t2, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r10;
L_8003CBF0:
    // 0x8003CBF0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003CBF4: lwc1        $f16, -0x76B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x8003CBF8: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8003CBFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003CC00: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003CC04: c.eq.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d == ctx->f10.d;
    // 0x8003CC08: nop

    // 0x8003CC0C: bc1t        L_8003D054
    if (c1cs) {
        // 0x8003CC10: nop
    
            goto L_8003D054;
    }
    // 0x8003CC10: nop

    // 0x8003CC14: jal         0x800C1850
    // 0x8003CC18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_110;
    // 0x8003CC18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_110:
    // 0x8003CC1C: lwc1        $f12, 0x14C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003CC20: jal         0x800C25B8
    // 0x8003CC24: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_111;
    // 0x8003CC24: nop

    after_111:
    // 0x8003CC28: lwc1        $f12, 0x150($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003CC2C: jal         0x800C23E8
    // 0x8003CC30: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_112;
    // 0x8003CC30: nop

    after_112:
    // 0x8003CC34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003CC38: lwc1        $f6, -0x76B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x8003CC3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003CC40: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003CC44: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003CC48: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003CC4C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003CC50: neg.s       $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = -ctx->f4.fl;
    // 0x8003CC54: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8003CC58: jal         0x800C2304
    // 0x8003CC5C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_113;
    // 0x8003CC5C: nop

    after_113:
    // 0x8003CC60: jal         0x800B1844
    // 0x8003CC64: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    func_800B1844(rdram, ctx);
        goto after_114;
    // 0x8003CC64: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_114:
    // 0x8003CC68: addiu       $t0, $sp, 0xB8
    ctx->r8 = ADD32(ctx->r29, 0XB8);
    // 0x8003CC6C: lwc1        $f20, 0x0($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003CC70: lwc1        $f18, 0x15C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003CC74: swc1        $f20, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f20.u32l;
    // 0x8003CC78: add.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8003CC7C: swc1        $f10, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f10.u32l;
    // 0x8003CC80: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x8003CC84: lwc1        $f8, 0x16C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003CC88: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8003CC8C: nop

    // 0x8003CC90: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003CC94: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8003CC98: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x8003CC9C: nop

    // 0x8003CCA0: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8003CCA4: nop

    // 0x8003CCA8: swc1        $f16, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f16.u32l;
    // 0x8003CCAC: sh          $zero, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = 0;
    // 0x8003CCB0: sh          $zero, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = 0;
    // 0x8003CCB4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003CCB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003CCBC: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x8003CCC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003CCC4: swc1        $f18, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f18.u32l;
    // 0x8003CCC8: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x8003CCCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003CCD0: lwc1        $f10, 0x164($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003CCD4: nop

    // 0x8003CCD8: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8003CCDC: nop

    // 0x8003CCE0: bc1f        L_8003CD2C
    if (!c1cs) {
        // 0x8003CCE4: nop
    
            goto L_8003CD2C;
    }
    // 0x8003CCE4: nop

    // 0x8003CCE8: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8003CCEC: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x8003CCF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003CCF4: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8003CCF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003CCFC: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003CD00: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x8003CD04: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8003CD08: nop

    // 0x8003CD0C: lwc1        $f18, 0x8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8003CD10: nop

    // 0x8003CD14: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x8003CD18: lhu         $t8, 0x18E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X18E);
    // 0x8003CD1C: nop

    // 0x8003CD20: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003CD24: b           L_8003CD8C
    // 0x8003CD28: sh          $t9, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = ctx->r25;
        goto L_8003CD8C;
    // 0x8003CD28: sh          $t9, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = ctx->r25;
L_8003CD2C:
    // 0x8003CD2C: lui         $at, 0xC400
    ctx->r1 = S32(0XC400 << 16);
    // 0x8003CD30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003CD34: lwc1        $f10, 0x164($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003CD38: nop

    // 0x8003CD3C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8003CD40: nop

    // 0x8003CD44: bc1f        L_8003CD8C
    if (!c1cs) {
        // 0x8003CD48: nop
    
            goto L_8003CD8C;
    }
    // 0x8003CD48: nop

    // 0x8003CD4C: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8003CD50: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x8003CD54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003CD58: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8003CD5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003CD60: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8003CD64: swc1        $f16, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f16.u32l;
    // 0x8003CD68: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x8003CD6C: nop

    // 0x8003CD70: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8003CD74: nop

    // 0x8003CD78: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x8003CD7C: lhu         $t2, 0x18E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X18E);
    // 0x8003CD80: nop

    // 0x8003CD84: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8003CD88: sh          $t0, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = ctx->r8;
L_8003CD8C:
    // 0x8003CD8C: addiu       $t3, $sp, 0xB8
    ctx->r11 = ADD32(ctx->r29, 0XB8);
    // 0x8003CD90: lwc1        $f6, 0x4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8003CD94: lwc1        $f10, 0x158($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003CD98: nop

    // 0x8003CD9C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8003CDA0: swc1        $f8, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f8.u32l;
    // 0x8003CDA4: addiu       $t4, $sp, 0xB8
    ctx->r12 = ADD32(ctx->r29, 0XB8);
    // 0x8003CDA8: lwc1        $f20, 0x8($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8003CDAC: lwc1        $f4, 0x154($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003CDB0: swc1        $f20, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f20.u32l;
    // 0x8003CDB4: add.s       $f16, $f4, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8003CDB8: swc1        $f16, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f16.u32l;
    // 0x8003CDBC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8003CDC0: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8003CDC4: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8003CDC8: nop

    // 0x8003CDCC: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8003CDD0: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x8003CDD4: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8003CDD8: nop

    // 0x8003CDDC: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8003CDE0: nop

    // 0x8003CDE4: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
    // 0x8003CDE8: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x8003CDEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003CDF0: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003CDF4: nop

    // 0x8003CDF8: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8003CDFC: nop

    // 0x8003CE00: bc1f        L_8003CE4C
    if (!c1cs) {
        // 0x8003CE04: nop
    
            goto L_8003CE4C;
    }
    // 0x8003CE04: nop

    // 0x8003CE08: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8003CE0C: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x8003CE10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CE14: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8003CE18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003CE1C: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8003CE20: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x8003CE24: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8003CE28: nop

    // 0x8003CE2C: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8003CE30: nop

    // 0x8003CE34: swc1        $f8, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f8.u32l;
    // 0x8003CE38: lhu         $t7, 0x18C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003CE3C: nop

    // 0x8003CE40: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x8003CE44: b           L_8003CEAC
    // 0x8003CE48: sh          $t1, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r9;
        goto L_8003CEAC;
    // 0x8003CE48: sh          $t1, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r9;
L_8003CE4C:
    // 0x8003CE4C: lui         $at, 0xC400
    ctx->r1 = S32(0XC400 << 16);
    // 0x8003CE50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003CE54: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8003CE58: nop

    // 0x8003CE5C: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8003CE60: nop

    // 0x8003CE64: bc1f        L_8003CEAC
    if (!c1cs) {
        // 0x8003CE68: nop
    
            goto L_8003CEAC;
    }
    // 0x8003CE68: nop

    // 0x8003CE6C: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x8003CE70: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x8003CE74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CE78: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8003CE7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003CE80: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8003CE84: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    // 0x8003CE88: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x8003CE8C: nop

    // 0x8003CE90: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8003CE94: nop

    // 0x8003CE98: swc1        $f8, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f8.u32l;
    // 0x8003CE9C: lhu         $t3, 0x18C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003CEA0: nop

    // 0x8003CEA4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8003CEA8: sh          $t4, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r12;
L_8003CEAC:
    // 0x8003CEAC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CEB0: lwc1        $f4, 0x15C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003CEB4: lwc1        $f19, -0x1470($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1470);
    // 0x8003CEB8: lwc1        $f18, -0x146C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X146C);
    // 0x8003CEBC: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8003CEC0: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8003CEC4: nop

    // 0x8003CEC8: bc1f        L_8003CF18
    if (!c1cs) {
        // 0x8003CECC: nop
    
            goto L_8003CF18;
    }
    // 0x8003CECC: nop

    // 0x8003CED0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CED4: lwc1        $f10, 0x15C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003CED8: lwc1        $f9, -0x1468($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1468);
    // 0x8003CEDC: lwc1        $f8, -0x1464($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1464);
    // 0x8003CEE0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003CEE4: sub.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d - ctx->f8.d;
    // 0x8003CEE8: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8003CEEC: swc1        $f16, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f16.u32l;
    // 0x8003CEF0: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8003CEF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CEF8: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8003CEFC: lwc1        $f7, -0x1460($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1460);
    // 0x8003CF00: lwc1        $f6, -0x145C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X145C);
    // 0x8003CF04: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8003CF08: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x8003CF0C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003CF10: b           L_8003CF80
    // 0x8003CF14: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
        goto L_8003CF80;
    // 0x8003CF14: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_8003CF18:
    // 0x8003CF18: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CF1C: lwc1        $f16, 0x15C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003CF20: lwc1        $f11, -0x1458($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1458);
    // 0x8003CF24: lwc1        $f10, -0x1454($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1454);
    // 0x8003CF28: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003CF2C: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8003CF30: nop

    // 0x8003CF34: bc1f        L_8003CF80
    if (!c1cs) {
        // 0x8003CF38: nop
    
            goto L_8003CF80;
    }
    // 0x8003CF38: nop

    // 0x8003CF3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CF40: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003CF44: lwc1        $f5, -0x1450($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1450);
    // 0x8003CF48: lwc1        $f4, -0x144C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X144C);
    // 0x8003CF4C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003CF50: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x8003CF54: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003CF58: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8003CF5C: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8003CF60: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CF64: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003CF68: lwc1        $f9, -0x1448($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1448);
    // 0x8003CF6C: lwc1        $f8, -0x1444($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1444);
    // 0x8003CF70: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003CF74: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x8003CF78: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8003CF7C: swc1        $f16, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f16.u32l;
L_8003CF80:
    // 0x8003CF80: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CF84: lwc1        $f18, 0x154($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003CF88: lwc1        $f7, -0x1440($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1440);
    // 0x8003CF8C: lwc1        $f6, -0x143C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X143C);
    // 0x8003CF90: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8003CF94: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8003CF98: nop

    // 0x8003CF9C: bc1f        L_8003CFEC
    if (!c1cs) {
        // 0x8003CFA0: nop
    
            goto L_8003CFEC;
    }
    // 0x8003CFA0: nop

    // 0x8003CFA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CFA8: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003CFAC: lwc1        $f17, -0x1438($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1438);
    // 0x8003CFB0: lwc1        $f16, -0x1434($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1434);
    // 0x8003CFB4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8003CFB8: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x8003CFBC: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8003CFC0: swc1        $f10, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f10.u32l;
    // 0x8003CFC4: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8003CFC8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CFCC: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8003CFD0: lwc1        $f5, -0x1430($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1430);
    // 0x8003CFD4: lwc1        $f4, -0x142C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X142C);
    // 0x8003CFD8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003CFDC: sub.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d - ctx->f4.d;
    // 0x8003CFE0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003CFE4: b           L_8003D054
    // 0x8003CFE8: swc1        $f18, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f18.u32l;
        goto L_8003D054;
    // 0x8003CFE8: swc1        $f18, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f18.u32l;
L_8003CFEC:
    // 0x8003CFEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003CFF0: lwc1        $f10, 0x154($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003CFF4: lwc1        $f9, -0x1428($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1428);
    // 0x8003CFF8: lwc1        $f8, -0x1424($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1424);
    // 0x8003CFFC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D000: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8003D004: nop

    // 0x8003D008: bc1f        L_8003D054
    if (!c1cs) {
        // 0x8003D00C: nop
    
            goto L_8003D054;
    }
    // 0x8003D00C: nop

    // 0x8003D010: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D014: lwc1        $f4, 0x154($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003D018: lwc1        $f19, -0x1420($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1420);
    // 0x8003D01C: lwc1        $f18, -0x141C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X141C);
    // 0x8003D020: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D024: add.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f16.d + ctx->f18.d;
    // 0x8003D028: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8003D02C: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x8003D030: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8003D034: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003D038: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8003D03C: lwc1        $f17, -0x1418($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1418);
    // 0x8003D040: lwc1        $f16, -0x1414($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1414);
    // 0x8003D044: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8003D048: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x8003D04C: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8003D050: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
L_8003D054:
    // 0x8003D054: lhu         $t7, 0x18E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X18E);
    // 0x8003D058: nop

    // 0x8003D05C: beq         $t7, $zero, L_8003D07C
    if (ctx->r15 == 0) {
        // 0x8003D060: nop
    
            goto L_8003D07C;
    }
    // 0x8003D060: nop

    // 0x8003D064: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D068: lwc1        $f8, 0x50D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003D06C: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003D070: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x8003D074: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003D078: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
L_8003D07C:
    // 0x8003D07C: lhu         $t2, 0x18C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X18C);
    // 0x8003D080: nop

    // 0x8003D084: beq         $t2, $zero, L_8003D0A4
    if (ctx->r10 == 0) {
        // 0x8003D088: nop
    
            goto L_8003D0A4;
    }
    // 0x8003D088: nop

    // 0x8003D08C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003D090: lwc1        $f18, 0x50D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8003D094: lwc1        $f16, 0x154($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003D098: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x8003D09C: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003D0A0: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
L_8003D0A4:
    // 0x8003D0A4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003D0A8: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x8003D0AC: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8003D0B0: nop

    // 0x8003D0B4: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
    // 0x8003D0B8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8003D0BC: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x8003D0C0: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8003D0C4: nop

    // 0x8003D0C8: swc1        $f8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f8.u32l;
    // 0x8003D0CC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003D0D0: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x8003D0D4: lwc1        $f4, 0x154($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8003D0D8: nop

    // 0x8003D0DC: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x8003D0E0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003D0E4: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x8003D0E8: lwc1        $f16, 0x150($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8003D0EC: nop

    // 0x8003D0F0: swc1        $f16, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f16.u32l;
    // 0x8003D0F4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003D0F8: lw          $t8, 0x7278($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7278);
    // 0x8003D0FC: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8003D100: nop

    // 0x8003D104: swc1        $f18, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f18.u32l;
    // 0x8003D108: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003D10C: lw          $t9, 0x7278($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7278);
    // 0x8003D110: lwc1        $f10, 0x148($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X148);
    // 0x8003D114: nop

    // 0x8003D118: swc1        $f10, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f10.u32l;
    // 0x8003D11C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8003D120: lw          $t7, 0x7278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7278);
    // 0x8003D124: lwc1        $f6, 0x144($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X144);
    // 0x8003D128: nop

    // 0x8003D12C: swc1        $f6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f6.u32l;
    // 0x8003D130: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8003D134: lh          $t0, 0x182($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X182);
    // 0x8003D138: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8003D13C: nop

    // 0x8003D140: addu        $t3, $t2, $t0
    ctx->r11 = ADD32(ctx->r10, ctx->r8);
    // 0x8003D144: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x8003D148: jal         0x800C1A28
    // 0x8003D14C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_115;
    // 0x8003D14C: nop

    after_115:
    // 0x8003D150: jal         0x800C1A28
    // 0x8003D154: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_116;
    // 0x8003D154: nop

    after_116:
    // 0x8003D158: b           L_8003D160
    // 0x8003D15C: nop

        goto L_8003D160;
    // 0x8003D15C: nop

L_8003D160:
    // 0x8003D160: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D164: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8003D168: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003D16C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8003D170: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8003D174: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8003D178: jr          $ra
    // 0x8003D17C: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    return;
    // 0x8003D17C: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
;}
RECOMP_FUNC void func_80077D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077D44: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077D48: nop

    // 0x80077D4C: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80077D50: nop

    // 0x80077D54: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80077D58: jr          $ra
    // 0x80077D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077D60: jr          $ra
    // 0x80077D64: nop

    return;
    // 0x80077D64: nop

    // 0x80077D68: jr          $ra
    // 0x80077D6C: nop

    return;
    // 0x80077D6C: nop

;}
RECOMP_FUNC void func_8006B73C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B73C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B744: jal         0x80061488
    // 0x8006B748: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006B748: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    after_0:
    // 0x8006B74C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006B750: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006B754: b           L_8006B764
    // 0x8006B758: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006B764;
    // 0x8006B758: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B75C: b           L_8006B764
    // 0x8006B760: nop

        goto L_8006B764;
    // 0x8006B760: nop

L_8006B764:
    // 0x8006B764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B76C: jr          $ra
    // 0x8006B770: nop

    return;
    // 0x8006B770: nop

;}
RECOMP_FUNC void func_80067CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067CCC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067CD0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067CD4: nop

    // 0x80067CD8: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067CDC: nop

    // 0x80067CE0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067CE4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067CE8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067CEC: beq         $v0, $zero, L_80067D24
    if (ctx->r2 == 0) {
        // 0x80067CF0: nop
    
            goto L_80067D24;
    }
    // 0x80067CF0: nop

    // 0x80067CF4: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067CF8: nop

    // 0x80067CFC: slti        $t8, $v0, 0x96
    ctx->r24 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067D00: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067D04: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80067D08: beq         $v0, $zero, L_80067D24
    if (ctx->r2 == 0) {
        // 0x80067D0C: nop
    
            goto L_80067D24;
    }
    // 0x80067D0C: nop

    // 0x80067D10: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067D14: nop

    // 0x80067D18: slti        $t9, $v0, 0x96
    ctx->r25 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067D1C: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80067D20: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80067D24:
    // 0x80067D24: jr          $ra
    // 0x80067D28: nop

    return;
    // 0x80067D28: nop

    // 0x80067D2C: jr          $ra
    // 0x80067D30: nop

    return;
    // 0x80067D30: nop

    // 0x80067D34: jr          $ra
    // 0x80067D38: nop

    return;
    // 0x80067D38: nop

;}
RECOMP_FUNC void func_800B26E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B26E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B26E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B26E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B26EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B26F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B26F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B26F8: jal         0x800B2A34
    // 0x800B26FC: nop

    func_800B2A34(rdram, ctx);
        goto after_0;
    // 0x800B26FC: nop

    after_0:
    // 0x800B2700: beq         $v0, $zero, L_800B2728
    if (ctx->r2 == 0) {
        // 0x800B2704: nop
    
            goto L_800B2728;
    }
    // 0x800B2704: nop

    // 0x800B2708: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B270C: nop

    // 0x800B2710: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B2714: nop

    // 0x800B2718: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x800B271C: sh          $t8, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r24;
    // 0x800B2720: b           L_800B2738
    // 0x800B2724: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2738;
    // 0x800B2724: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B2728:
    // 0x800B2728: b           L_800B2738
    // 0x800B272C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B2738;
    // 0x800B272C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B2730: b           L_800B2738
    // 0x800B2734: nop

        goto L_800B2738;
    // 0x800B2734: nop

L_800B2738:
    // 0x800B2738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B273C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2740: jr          $ra
    // 0x800B2744: nop

    return;
    // 0x800B2744: nop

;}
RECOMP_FUNC void func_800631C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800631C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800631C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800631C8: jal         0x80061488
    // 0x800631CC: addiu       $a0, $zero, 0x61A
    ctx->r4 = ADD32(0, 0X61A);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800631CC: addiu       $a0, $zero, 0x61A
    ctx->r4 = ADD32(0, 0X61A);
    after_0:
    // 0x800631D0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800631D4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800631D8: b           L_800631E8
    // 0x800631DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800631E8;
    // 0x800631DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800631E0: b           L_800631E8
    // 0x800631E4: nop

        goto L_800631E8;
    // 0x800631E4: nop

L_800631E8:
    // 0x800631E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800631EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800631F0: jr          $ra
    // 0x800631F4: nop

    return;
    // 0x800631F4: nop

;}
RECOMP_FUNC void func_8008ECAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ECAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008ECB0: swc1        $f12, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f12.u32l;
    // 0x8008ECB4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008ECB8: swc1        $f14, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f14.u32l;
    // 0x8008ECBC: jr          $ra
    // 0x8008ECC0: nop

    return;
    // 0x8008ECC0: nop

    // 0x8008ECC4: jr          $ra
    // 0x8008ECC8: nop

    return;
    // 0x8008ECC8: nop

;}
RECOMP_FUNC void func_80073B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073B44: jal         0x80061348
    // 0x80073B48: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073B48: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073B4C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073B50: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073B54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073B58: beq         $v0, $zero, L_80073BAC
    if (ctx->r2 == 0) {
        // 0x80073B5C: nop
    
            goto L_80073BAC;
    }
    // 0x80073B5C: nop

    // 0x80073B60: jal         0x80061348
    // 0x80073B64: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073B64: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073B68: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073B6C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073B70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073B74: beq         $v0, $zero, L_80073BAC
    if (ctx->r2 == 0) {
        // 0x80073B78: nop
    
            goto L_80073BAC;
    }
    // 0x80073B78: nop

    // 0x80073B7C: jal         0x80061348
    // 0x80073B80: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073B80: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073B84: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073B88: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073B8C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073B90: beq         $v0, $zero, L_80073BAC
    if (ctx->r2 == 0) {
        // 0x80073B94: nop
    
            goto L_80073BAC;
    }
    // 0x80073B94: nop

    // 0x80073B98: jal         0x80061348
    // 0x80073B9C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073B9C: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073BA0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073BA4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80073BA8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073BAC:
    // 0x80073BAC: b           L_80073BBC
    // 0x80073BB0: nop

        goto L_80073BBC;
    // 0x80073BB0: nop

    // 0x80073BB4: b           L_80073BBC
    // 0x80073BB8: nop

        goto L_80073BBC;
    // 0x80073BB8: nop

L_80073BBC:
    // 0x80073BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073BC4: jr          $ra
    // 0x80073BC8: nop

    return;
    // 0x80073BC8: nop

;}
RECOMP_FUNC void func_8006FC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FC74: jal         0x80061348
    // 0x8006FC78: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FC78: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FC7C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FC80: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FC84: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FC88: beq         $v0, $zero, L_8006FCDC
    if (ctx->r2 == 0) {
        // 0x8006FC8C: nop
    
            goto L_8006FCDC;
    }
    // 0x8006FC8C: nop

    // 0x8006FC90: jal         0x80061348
    // 0x8006FC94: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FC94: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FC98: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FC9C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FCA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FCA4: beq         $v0, $zero, L_8006FCDC
    if (ctx->r2 == 0) {
        // 0x8006FCA8: nop
    
            goto L_8006FCDC;
    }
    // 0x8006FCA8: nop

    // 0x8006FCAC: jal         0x80061348
    // 0x8006FCB0: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FCB0: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FCB4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FCB8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FCBC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FCC0: beq         $v0, $zero, L_8006FCDC
    if (ctx->r2 == 0) {
        // 0x8006FCC4: nop
    
            goto L_8006FCDC;
    }
    // 0x8006FCC4: nop

    // 0x8006FCC8: jal         0x80061348
    // 0x8006FCCC: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FCCC: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FCD0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FCD4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FCD8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FCDC:
    // 0x8006FCDC: b           L_8006FCEC
    // 0x8006FCE0: nop

        goto L_8006FCEC;
    // 0x8006FCE0: nop

    // 0x8006FCE4: b           L_8006FCEC
    // 0x8006FCE8: nop

        goto L_8006FCEC;
    // 0x8006FCE8: nop

L_8006FCEC:
    // 0x8006FCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FCF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FCF4: jr          $ra
    // 0x8006FCF8: nop

    return;
    // 0x8006FCF8: nop

;}
RECOMP_FUNC void func_8006FCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FCFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FD00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FD04: jal         0x80061488
    // 0x8006FD08: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006FD08: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    after_0:
    // 0x8006FD0C: slti        $t6, $v0, 0xA
    ctx->r14 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8006FD10: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006FD14: b           L_8006FD24
    // 0x8006FD18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006FD24;
    // 0x8006FD18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FD1C: b           L_8006FD24
    // 0x8006FD20: nop

        goto L_8006FD24;
    // 0x8006FD20: nop

L_8006FD24:
    // 0x8006FD24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FD28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FD2C: jr          $ra
    // 0x8006FD30: nop

    return;
    // 0x8006FD30: nop

;}
RECOMP_FUNC void func_80066628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006662C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066630: jal         0x80061348
    // 0x80066634: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066634: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80066638: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006663C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066640: bne         $v0, $zero, L_80066688
    if (ctx->r2 != 0) {
        // 0x80066644: nop
    
            goto L_80066688;
    }
    // 0x80066644: nop

    // 0x80066648: jal         0x80061348
    // 0x8006664C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006664C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x80066650: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066654: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066658: bne         $v0, $zero, L_80066688
    if (ctx->r2 != 0) {
        // 0x8006665C: nop
    
            goto L_80066688;
    }
    // 0x8006665C: nop

    // 0x80066660: jal         0x80061348
    // 0x80066664: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80066664: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_2:
    // 0x80066668: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006666C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80066670: bne         $v0, $zero, L_80066688
    if (ctx->r2 != 0) {
        // 0x80066674: nop
    
            goto L_80066688;
    }
    // 0x80066674: nop

    // 0x80066678: jal         0x80061348
    // 0x8006667C: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006667C: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_3:
    // 0x80066680: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066684: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80066688:
    // 0x80066688: b           L_80066698
    // 0x8006668C: nop

        goto L_80066698;
    // 0x8006668C: nop

    // 0x80066690: b           L_80066698
    // 0x80066694: nop

        goto L_80066698;
    // 0x80066694: nop

L_80066698:
    // 0x80066698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006669C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800666A0: jr          $ra
    // 0x800666A4: nop

    return;
    // 0x800666A4: nop

;}
RECOMP_FUNC void func_800721E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800721E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800721E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800721EC: jal         0x80061348
    // 0x800721F0: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800721F0: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x800721F4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800721F8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800721FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072200: beq         $v0, $zero, L_80072238
    if (ctx->r2 == 0) {
        // 0x80072204: nop
    
            goto L_80072238;
    }
    // 0x80072204: nop

    // 0x80072208: jal         0x80061348
    // 0x8007220C: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007220C: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x80072210: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80072214: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80072218: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007221C: beq         $v0, $zero, L_80072238
    if (ctx->r2 == 0) {
        // 0x80072220: nop
    
            goto L_80072238;
    }
    // 0x80072220: nop

    // 0x80072224: jal         0x80061348
    // 0x80072228: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80072228: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x8007222C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80072230: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80072234: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80072238:
    // 0x80072238: b           L_80072248
    // 0x8007223C: nop

        goto L_80072248;
    // 0x8007223C: nop

    // 0x80072240: b           L_80072248
    // 0x80072244: nop

        goto L_80072248;
    // 0x80072244: nop

L_80072248:
    // 0x80072248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007224C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072250: jr          $ra
    // 0x80072254: nop

    return;
    // 0x80072254: nop

;}
RECOMP_FUNC void func_80064EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064EB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064EBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064EC0: nop

    // 0x80064EC4: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80064EC8: nop

    // 0x80064ECC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80064ED0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064ED4: jr          $ra
    // 0x80064ED8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064ED8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064EDC: jr          $ra
    // 0x80064EE0: nop

    return;
    // 0x80064EE0: nop

    // 0x80064EE4: jr          $ra
    // 0x80064EE8: nop

    return;
    // 0x80064EE8: nop

;}
RECOMP_FUNC void func_80090C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090C94: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80090C98: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090C9C: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, -0X3AB8);
    // 0x80090CA0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80090CA4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80090CA8: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x80090CAC: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80090CB0: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x80090CB4: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x80090CB8: sh          $t0, 0x100($t2)
    MEM_H(0X100, ctx->r10) = ctx->r8;
    // 0x80090CBC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80090CC0: lw          $t3, -0x282C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X282C);
    // 0x80090CC4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80090CC8: addiu       $t4, $t4, -0x2870
    ctx->r12 = ADD32(ctx->r12, -0X2870);
    // 0x80090CCC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80090CD0: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80090CD4: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80090CD8: beq         $at, $zero, L_80090D04
    if (ctx->r1 == 0) {
        // 0x80090CDC: nop
    
            goto L_80090D04;
    }
    // 0x80090CDC: nop

    // 0x80090CE0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090CE4: lw          $t8, -0x282C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X282C);
    // 0x80090CE8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80090CEC: lhu         $t1, -0x44C0($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X44C0);
    // 0x80090CF0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090CF4: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x80090CF8: sw          $t9, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r25;
    // 0x80090CFC: b           L_80090D1C
    // 0x80090D00: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
        goto L_80090D1C;
    // 0x80090D00: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_80090D04:
    // 0x80090D04: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090D08: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090D0C: lw          $t0, -0x282C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X282C);
    // 0x80090D10: lhu         $t7, -0x44C0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X44C0);
    // 0x80090D14: nop

    // 0x80090D18: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
L_80090D1C:
    // 0x80090D1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090D20: sh          $a0, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r4;
    // 0x80090D24: jr          $ra
    // 0x80090D28: nop

    return;
    // 0x80090D28: nop

    // 0x80090D2C: jr          $ra
    // 0x80090D30: nop

    return;
    // 0x80090D30: nop

;}
RECOMP_FUNC void func_800706E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800706E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800706EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800706F0: jal         0x80061348
    // 0x800706F4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800706F4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800706F8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800706FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070700: beq         $v0, $zero, L_80070750
    if (ctx->r2 == 0) {
        // 0x80070704: nop
    
            goto L_80070750;
    }
    // 0x80070704: nop

    // 0x80070708: jal         0x80061348
    // 0x8007070C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007070C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070710: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070714: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070718: beq         $v0, $zero, L_80070750
    if (ctx->r2 == 0) {
        // 0x8007071C: nop
    
            goto L_80070750;
    }
    // 0x8007071C: nop

    // 0x80070720: jal         0x80061348
    // 0x80070724: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070724: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070728: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007072C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070730: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070734: beq         $v0, $zero, L_80070750
    if (ctx->r2 == 0) {
        // 0x80070738: nop
    
            goto L_80070750;
    }
    // 0x80070738: nop

    // 0x8007073C: jal         0x80061348
    // 0x80070740: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070740: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070744: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070748: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007074C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070750:
    // 0x80070750: b           L_80070760
    // 0x80070754: nop

        goto L_80070760;
    // 0x80070754: nop

    // 0x80070758: b           L_80070760
    // 0x8007075C: nop

        goto L_80070760;
    // 0x8007075C: nop

L_80070760:
    // 0x80070760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070768: jr          $ra
    // 0x8007076C: nop

    return;
    // 0x8007076C: nop

;}
RECOMP_FUNC void alLoadParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D01D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D01D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D01D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D01DC: beq         $a1, $at, L_800D0334
    if (ctx->r5 == ctx->r1) {
        // 0x800D01E0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800D0334;
    }
    // 0x800D01E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D01E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800D01E8: bnel        $a1, $at, L_800D0398
    if (ctx->r5 != ctx->r1) {
        // 0x800D01EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0398;
    }
    goto skip_0;
    // 0x800D01EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D01F0: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x800D01F4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D01F8: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800D01FC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800D0200: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800D0204: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x800D0208: beql        $v0, $zero, L_800D0228
    if (ctx->r2 == 0) {
        // 0x800D020C: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_800D0228;
    }
    goto skip_1;
    // 0x800D020C: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x800D0210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D0214: beq         $v0, $a0, L_800D02E8
    if (ctx->r2 == ctx->r4) {
        // 0x800D0218: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_800D02E8;
    }
    // 0x800D0218: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800D021C: b           L_800D0398
    // 0x800D0220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D0398;
    // 0x800D0220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0224: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_800D0228:
    // 0x800D0228: addiu       $t7, $t7, 0x87C
    ctx->r15 = ADD32(ctx->r15, 0X87C);
    // 0x800D022C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800D0230: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800D0234: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800D0238: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x800D023C: mflo        $t9
    ctx->r25 = lo;
    // 0x800D0240: bne         $a1, $zero, L_800D024C
    if (ctx->r5 != 0) {
        // 0x800D0244: nop
    
            goto L_800D024C;
    }
    // 0x800D0244: nop

    // 0x800D0248: break       7
    do_break(2148336200);
L_800D024C:
    // 0x800D024C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0250: bne         $a1, $at, L_800D0264
    if (ctx->r5 != ctx->r1) {
        // 0x800D0254: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D0264;
    }
    // 0x800D0254: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D0258: bne         $t8, $at, L_800D0264
    if (ctx->r24 != ctx->r1) {
        // 0x800D025C: nop
    
            goto L_800D0264;
    }
    // 0x800D025C: nop

    // 0x800D0260: break       6
    do_break(2148336224);
L_800D0264:
    // 0x800D0264: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0268: mflo        $t0
    ctx->r8 = lo;
    // 0x800D026C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800D0270: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800D0274: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800D0278: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800D027C: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x800D0280: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800D0284: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0288: mflo        $t4
    ctx->r12 = lo;
    // 0x800D028C: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x800D0290: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D0294: beql        $v1, $zero, L_800D02DC
    if (ctx->r3 == 0) {
        // 0x800D0298: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800D02DC;
    }
    goto skip_2;
    // 0x800D0298: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x800D029C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800D02A0: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x800D02A4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800D02A8: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x800D02AC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800D02B0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800D02B4: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x800D02B8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800D02BC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800D02C0: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x800D02C4: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800D02C8: jal         0x800D6320
    // 0x800D02CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy(rdram, ctx);
        goto after_0;
    // 0x800D02CC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800D02D0: b           L_800D0398
    // 0x800D02D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D0398;
    // 0x800D02D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D02D8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800D02DC:
    // 0x800D02DC: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800D02E0: b           L_800D0394
    // 0x800D02E4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800D0394;
    // 0x800D02E4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800D02E8:
    // 0x800D02E8: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800D02EC: addiu       $t0, $t0, 0x3A4
    ctx->r8 = ADD32(ctx->r8, 0X3A4);
    // 0x800D02F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x800D02F4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D02F8: beql        $v1, $zero, L_800D0328
    if (ctx->r3 == 0) {
        // 0x800D02FC: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800D0328;
    }
    goto skip_3;
    // 0x800D02FC: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x800D0300: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800D0304: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x800D0308: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800D030C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800D0310: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x800D0314: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800D0318: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800D031C: b           L_800D0394
    // 0x800D0320: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_800D0394;
    // 0x800D0320: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x800D0324: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800D0328:
    // 0x800D0328: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800D032C: b           L_800D0394
    // 0x800D0330: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800D0394;
    // 0x800D0330: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800D0334:
    // 0x800D0334: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800D0338: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D033C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800D0340: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x800D0344: beq         $v0, $zero, L_800D0394
    if (ctx->r2 == 0) {
        // 0x800D0348: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_800D0394;
    }
    // 0x800D0348: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800D034C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D0350: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x800D0354: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x800D0358: bne         $v1, $zero, L_800D0378
    if (ctx->r3 != 0) {
        // 0x800D035C: nop
    
            goto L_800D0378;
    }
    // 0x800D035C: nop

    // 0x800D0360: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D0364: beql        $v1, $zero, L_800D0398
    if (ctx->r3 == 0) {
        // 0x800D0368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0398;
    }
    goto skip_4;
    // 0x800D0368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800D036C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800D0370: b           L_800D0394
    // 0x800D0374: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_800D0394;
    // 0x800D0374: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_800D0378:
    // 0x800D0378: bnel        $a0, $v1, L_800D0398
    if (ctx->r4 != ctx->r3) {
        // 0x800D037C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0398;
    }
    goto skip_5;
    // 0x800D037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800D0380: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D0384: beql        $v1, $zero, L_800D0398
    if (ctx->r3 == 0) {
        // 0x800D0388: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0398;
    }
    goto skip_6;
    // 0x800D0388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800D038C: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800D0390: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_800D0394:
    // 0x800D0394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D0398:
    // 0x800D0398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D039C: jr          $ra
    // 0x800D03A0: nop

    return;
    // 0x800D03A0: nop

;}
RECOMP_FUNC void func_800657E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800657E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800657E4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800657E8: nop

    // 0x800657EC: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x800657F0: nop

    // 0x800657F4: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x800657F8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800657FC: jr          $ra
    // 0x80065800: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065800: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065804: jr          $ra
    // 0x80065808: nop

    return;
    // 0x80065808: nop

    // 0x8006580C: jr          $ra
    // 0x80065810: nop

    return;
    // 0x80065810: nop

;}
RECOMP_FUNC void func_80063A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A5C: jal         0x8005F064
    // 0x80063A60: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063A60: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063A64: b           L_80063A74
    // 0x80063A68: nop

        goto L_80063A74;
    // 0x80063A68: nop

    // 0x80063A6C: b           L_80063A74
    // 0x80063A70: nop

        goto L_80063A74;
    // 0x80063A70: nop

L_80063A74:
    // 0x80063A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063A7C: jr          $ra
    // 0x80063A80: nop

    return;
    // 0x80063A80: nop

;}
RECOMP_FUNC void func_8006A378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A37C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A380: jal         0x80061348
    // 0x8006A384: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006A384: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006A388: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A38C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A390: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A394: beq         $v0, $zero, L_8006A3D4
    if (ctx->r2 == 0) {
        // 0x8006A398: nop
    
            goto L_8006A3D4;
    }
    // 0x8006A398: nop

    // 0x8006A39C: jal         0x80061348
    // 0x8006A3A0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006A3A0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006A3A4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A3A8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A3AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A3B0: beq         $v0, $zero, L_8006A3D4
    if (ctx->r2 == 0) {
        // 0x8006A3B4: nop
    
            goto L_8006A3D4;
    }
    // 0x8006A3B4: nop

    // 0x8006A3B8: jal         0x80061348
    // 0x8006A3BC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006A3BC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006A3C0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A3C4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A3C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A3CC: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A3D0: nop
    
            goto L_8006A618;
    }
    // 0x8006A3D0: nop

L_8006A3D4:
    // 0x8006A3D4: jal         0x80061348
    // 0x8006A3D8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006A3D8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006A3DC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A3E0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A3E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006A3E8: beq         $v0, $zero, L_8006A428
    if (ctx->r2 == 0) {
        // 0x8006A3EC: nop
    
            goto L_8006A428;
    }
    // 0x8006A3EC: nop

    // 0x8006A3F0: jal         0x80061348
    // 0x8006A3F4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006A3F4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006A3F8: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006A3FC: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006A400: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006A404: beq         $v0, $zero, L_8006A428
    if (ctx->r2 == 0) {
        // 0x8006A408: nop
    
            goto L_8006A428;
    }
    // 0x8006A408: nop

    // 0x8006A40C: jal         0x80061348
    // 0x8006A410: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006A410: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006A414: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006A418: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006A41C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006A420: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A424: nop
    
            goto L_8006A618;
    }
    // 0x8006A424: nop

L_8006A428:
    // 0x8006A428: jal         0x80061348
    // 0x8006A42C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006A42C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006A430: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006A434: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006A438: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006A43C: beq         $v0, $zero, L_8006A47C
    if (ctx->r2 == 0) {
        // 0x8006A440: nop
    
            goto L_8006A47C;
    }
    // 0x8006A440: nop

    // 0x8006A444: jal         0x80061348
    // 0x8006A448: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006A448: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006A44C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006A450: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006A454: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006A458: beq         $v0, $zero, L_8006A47C
    if (ctx->r2 == 0) {
        // 0x8006A45C: nop
    
            goto L_8006A47C;
    }
    // 0x8006A45C: nop

    // 0x8006A460: jal         0x80061348
    // 0x8006A464: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006A464: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006A468: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A46C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A470: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A474: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A478: nop
    
            goto L_8006A618;
    }
    // 0x8006A478: nop

L_8006A47C:
    // 0x8006A47C: jal         0x80061348
    // 0x8006A480: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006A480: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006A484: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A488: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A48C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A490: beq         $v0, $zero, L_8006A4D0
    if (ctx->r2 == 0) {
        // 0x8006A494: nop
    
            goto L_8006A4D0;
    }
    // 0x8006A494: nop

    // 0x8006A498: jal         0x80061348
    // 0x8006A49C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006A49C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006A4A0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A4A4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A4A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A4AC: beq         $v0, $zero, L_8006A4D0
    if (ctx->r2 == 0) {
        // 0x8006A4B0: nop
    
            goto L_8006A4D0;
    }
    // 0x8006A4B0: nop

    // 0x8006A4B4: jal         0x80061348
    // 0x8006A4B8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006A4B8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006A4BC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A4C0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A4C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A4C8: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A4CC: nop
    
            goto L_8006A618;
    }
    // 0x8006A4CC: nop

L_8006A4D0:
    // 0x8006A4D0: jal         0x80061348
    // 0x8006A4D4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006A4D4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006A4D8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A4DC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A4E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A4E4: beq         $v0, $zero, L_8006A524
    if (ctx->r2 == 0) {
        // 0x8006A4E8: nop
    
            goto L_8006A524;
    }
    // 0x8006A4E8: nop

    // 0x8006A4EC: jal         0x80061348
    // 0x8006A4F0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006A4F0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006A4F4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A4F8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A4FC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006A500: beq         $v0, $zero, L_8006A524
    if (ctx->r2 == 0) {
        // 0x8006A504: nop
    
            goto L_8006A524;
    }
    // 0x8006A504: nop

    // 0x8006A508: jal         0x80061348
    // 0x8006A50C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006A50C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006A510: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006A514: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006A518: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006A51C: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A520: nop
    
            goto L_8006A618;
    }
    // 0x8006A520: nop

L_8006A524:
    // 0x8006A524: jal         0x80061348
    // 0x8006A528: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006A528: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006A52C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006A530: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006A534: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006A538: beq         $v0, $zero, L_8006A578
    if (ctx->r2 == 0) {
        // 0x8006A53C: nop
    
            goto L_8006A578;
    }
    // 0x8006A53C: nop

    // 0x8006A540: jal         0x80061348
    // 0x8006A544: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006A544: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006A548: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006A54C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006A550: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006A554: beq         $v0, $zero, L_8006A578
    if (ctx->r2 == 0) {
        // 0x8006A558: nop
    
            goto L_8006A578;
    }
    // 0x8006A558: nop

    // 0x8006A55C: jal         0x80061348
    // 0x8006A560: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006A560: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006A564: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006A568: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006A56C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006A570: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A574: nop
    
            goto L_8006A618;
    }
    // 0x8006A574: nop

L_8006A578:
    // 0x8006A578: jal         0x80061348
    // 0x8006A57C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006A57C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006A580: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006A584: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006A588: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006A58C: beq         $v0, $zero, L_8006A5CC
    if (ctx->r2 == 0) {
        // 0x8006A590: nop
    
            goto L_8006A5CC;
    }
    // 0x8006A590: nop

    // 0x8006A594: jal         0x80061348
    // 0x8006A598: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006A598: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006A59C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006A5A0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006A5A4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006A5A8: beq         $v0, $zero, L_8006A5CC
    if (ctx->r2 == 0) {
        // 0x8006A5AC: nop
    
            goto L_8006A5CC;
    }
    // 0x8006A5AC: nop

    // 0x8006A5B0: jal         0x80061348
    // 0x8006A5B4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006A5B4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006A5B8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006A5BC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006A5C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A5C4: bne         $v0, $zero, L_8006A618
    if (ctx->r2 != 0) {
        // 0x8006A5C8: nop
    
            goto L_8006A618;
    }
    // 0x8006A5C8: nop

L_8006A5CC:
    // 0x8006A5CC: jal         0x80061348
    // 0x8006A5D0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006A5D0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006A5D4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006A5D8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006A5DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A5E0: beq         $v0, $zero, L_8006A618
    if (ctx->r2 == 0) {
        // 0x8006A5E4: nop
    
            goto L_8006A618;
    }
    // 0x8006A5E4: nop

    // 0x8006A5E8: jal         0x80061348
    // 0x8006A5EC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006A5EC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006A5F0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006A5F4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006A5F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006A5FC: beq         $v0, $zero, L_8006A618
    if (ctx->r2 == 0) {
        // 0x8006A600: nop
    
            goto L_8006A618;
    }
    // 0x8006A600: nop

    // 0x8006A604: jal         0x80061348
    // 0x8006A608: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006A608: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006A60C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006A610: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006A614: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006A618:
    // 0x8006A618: b           L_8006A628
    // 0x8006A61C: nop

        goto L_8006A628;
    // 0x8006A61C: nop

    // 0x8006A620: b           L_8006A628
    // 0x8006A624: nop

        goto L_8006A628;
    // 0x8006A624: nop

L_8006A628:
    // 0x8006A628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A62C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A630: jr          $ra
    // 0x8006A634: nop

    return;
    // 0x8006A634: nop

;}
RECOMP_FUNC void func_8006B6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B6D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B6DC: nop

    // 0x8006B6E0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B6E4: nop

    // 0x8006B6E8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006B6EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B6F0: jr          $ra
    // 0x8006B6F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B6F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B6F8: jr          $ra
    // 0x8006B6FC: nop

    return;
    // 0x8006B6FC: nop

    // 0x8006B700: jr          $ra
    // 0x8006B704: nop

    return;
    // 0x8006B704: nop

;}
RECOMP_FUNC void func_80098CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098CFC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098D00: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098D04: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80098D08: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80098D0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098D10: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098D14: jr          $ra
    // 0x80098D18: nop

    return;
    // 0x80098D18: nop

    // 0x80098D1C: jr          $ra
    // 0x80098D20: nop

    return;
    // 0x80098D20: nop

;}
RECOMP_FUNC void func_80090784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090784: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80090788: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8009078C: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80090790: nop

    // 0x80090794: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80090798: bne         $t7, $zero, L_800907B0
    if (ctx->r15 != 0) {
        // 0x8009079C: nop
    
            goto L_800907B0;
    }
    // 0x8009079C: nop

    // 0x800907A0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800907A4: lw          $t8, -0x4CD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CD8);
    // 0x800907A8: b           L_800907C0
    // 0x800907AC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
        goto L_800907C0;
    // 0x800907AC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_800907B0:
    // 0x800907B0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800907B4: lw          $t9, -0x4CE0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CE0);
    // 0x800907B8: nop

    // 0x800907BC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_800907C0:
    // 0x800907C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800907C4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800907C8: nop

    // 0x800907CC: bne         $a0, $t0, L_8009082C
    if (ctx->r4 != ctx->r8) {
        // 0x800907D0: nop
    
            goto L_8009082C;
    }
    // 0x800907D0: nop

    // 0x800907D4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800907D8: lh          $t1, -0x4CC8($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CC8);
    // 0x800907DC: nop

    // 0x800907E0: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x800907E4: beq         $t2, $zero, L_8009082C
    if (ctx->r10 == 0) {
        // 0x800907E8: nop
    
            goto L_8009082C;
    }
    // 0x800907E8: nop

    // 0x800907EC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800907F0: lw          $t3, -0x4CD0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CD0);
    // 0x800907F4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800907F8: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800907FC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80090800: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80090804: lhu         $t6, -0x44B8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X44B8);
    // 0x80090808: nop

    // 0x8009080C: sh          $t6, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r14;
    // 0x80090810: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090814: lw          $t7, -0x4CD0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CD0);
    // 0x80090818: nop

    // 0x8009081C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80090820: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80090824: b           L_80090844
    // 0x80090828: nop

        goto L_80090844;
    // 0x80090828: nop

L_8009082C:
    // 0x8009082C: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80090830: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090834: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80090838: lhu         $t0, -0x44B8($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44B8);
    // 0x8009083C: nop

    // 0x80090840: sh          $t0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r8;
L_80090844:
    // 0x80090844: lhu         $t1, 0xE($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XE);
    // 0x80090848: nop

    // 0x8009084C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80090850: beq         $t2, $zero, L_80090890
    if (ctx->r10 == 0) {
        // 0x80090854: nop
    
            goto L_80090890;
    }
    // 0x80090854: nop

    // 0x80090858: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8009085C: lh          $t3, -0x4CC8($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4CC8);
    // 0x80090860: nop

    // 0x80090864: andi        $t4, $t3, 0x400
    ctx->r12 = ctx->r11 & 0X400;
    // 0x80090868: bne         $t4, $zero, L_80090884
    if (ctx->r12 != 0) {
        // 0x8009086C: nop
    
            goto L_80090884;
    }
    // 0x8009086C: nop

    // 0x80090870: lhu         $t5, 0xE($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XE);
    // 0x80090874: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x80090878: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8009087C: b           L_80090890
    // 0x80090880: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
        goto L_80090890;
    // 0x80090880: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
L_80090884:
    // 0x80090884: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80090888: addu        $t9, $a2, $a3
    ctx->r25 = ADD32(ctx->r6, ctx->r7);
    // 0x8009088C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_80090890:
    // 0x80090890: b           L_80090898
    // 0x80090894: nop

        goto L_80090898;
    // 0x80090894: nop

L_80090898:
    // 0x80090898: jr          $ra
    // 0x8009089C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8009089C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800722CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800722CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800722D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800722D4: jal         0x80061348
    // 0x800722D8: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800722D8: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x800722DC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800722E0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800722E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800722E8: beq         $v0, $zero, L_80072320
    if (ctx->r2 == 0) {
        // 0x800722EC: nop
    
            goto L_80072320;
    }
    // 0x800722EC: nop

    // 0x800722F0: jal         0x80061348
    // 0x800722F4: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800722F4: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x800722F8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800722FC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80072300: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072304: beq         $v0, $zero, L_80072320
    if (ctx->r2 == 0) {
        // 0x80072308: nop
    
            goto L_80072320;
    }
    // 0x80072308: nop

    // 0x8007230C: jal         0x80061348
    // 0x80072310: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80072310: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x80072314: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80072318: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007231C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80072320:
    // 0x80072320: b           L_80072330
    // 0x80072324: nop

        goto L_80072330;
    // 0x80072324: nop

    // 0x80072328: b           L_80072330
    // 0x8007232C: nop

        goto L_80072330;
    // 0x8007232C: nop

L_80072330:
    // 0x80072330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072338: jr          $ra
    // 0x8007233C: nop

    return;
    // 0x8007233C: nop

;}
RECOMP_FUNC void func_8008ABB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ABB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008ABB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008ABBC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008ABC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008ABC4: lui         $t6, 0x809A
    ctx->r14 = S32(0X809A << 16);
    // 0x8008ABC8: lui         $t7, 0x809A
    ctx->r15 = S32(0X809A << 16);
    // 0x8008ABCC: addiu       $t7, $t7, -0x6FD8
    ctx->r15 = ADD32(ctx->r15, -0X6FD8);
    // 0x8008ABD0: addiu       $t6, $t6, -0x6F10
    ctx->r14 = ADD32(ctx->r14, -0X6F10);
    // 0x8008ABD4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8008ABD8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008ABDC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008ABE0: jal         0x800BC6EC
    // 0x8008ABE4: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008ABE4: nop

    after_0:
    // 0x8008ABE8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008ABEC: nop

    // 0x8008ABF0: sw          $v0, 0x72C($t9)
    MEM_W(0X72C, ctx->r25) = ctx->r2;
    // 0x8008ABF4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008ABF8: jal         0x800BC6EC
    // 0x8008ABFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8008ABFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8008AC00: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008AC04: nop

    // 0x8008AC08: sw          $v0, 0x734($t0)
    MEM_W(0X734, ctx->r8) = ctx->r2;
    // 0x8008AC0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008AC10: jal         0x800BC6EC
    // 0x8008AC14: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8008AC14: nop

    after_2:
    // 0x8008AC18: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8008AC1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008AC20: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008AC24: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008AC28: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008AC2C: lui         $a2, 0x809A
    ctx->r6 = S32(0X809A << 16);
    // 0x8008AC30: jal         0x800BD1FC
    // 0x8008AC34: addiu       $a2, $a2, -0x6FD8
    ctx->r6 = ADD32(ctx->r6, -0X6FD8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8008AC34: addiu       $a2, $a2, -0x6FD8
    ctx->r6 = ADD32(ctx->r6, -0X6FD8);
    after_3:
    // 0x8008AC38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008AC3C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AC40: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8008AC44: jal         0x800BD218
    // 0x8008AC48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x8008AC48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008AC4C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AC50: nop

    // 0x8008AC54: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8008AC58: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008AC5C: nop

    // 0x8008AC60: lw          $t3, 0x72C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X72C);
    // 0x8008AC64: nop

    // 0x8008AC68: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8008AC6C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008AC70: nop

    // 0x8008AC74: lw          $t5, 0x734($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X734);
    // 0x8008AC78: nop

    // 0x8008AC7C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8008AC80:
    // 0x8008AC80: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008AC84: nop

    // 0x8008AC88: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008AC8C: nop

    // 0x8008AC90: bne         $t7, $zero, L_8008ACA0
    if (ctx->r15 != 0) {
        // 0x8008AC94: nop
    
            goto L_8008ACA0;
    }
    // 0x8008AC94: nop

    // 0x8008AC98: b           L_8008AD58
    // 0x8008AC9C: nop

        goto L_8008AD58;
    // 0x8008AC9C: nop

L_8008ACA0:
    // 0x8008ACA0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008ACA4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008ACA8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008ACAC: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008ACB0: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008ACB4: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x8008ACB8: jal         0x800BD1FC
    // 0x8008ACBC: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8008ACBC: nop

    after_5:
    // 0x8008ACC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008ACC4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008ACC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008ACCC: jal         0x800BD218
    // 0x8008ACD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_6;
    // 0x8008ACD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x8008ACD4: jal         0x800BC6EC
    // 0x8008ACD8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x8008ACD8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_7:
    // 0x8008ACDC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008ACE0: nop

    // 0x8008ACE4: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8008ACE8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008ACEC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008ACF0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008ACF4: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008ACF8: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008ACFC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8008AD00: jal         0x800BD1FC
    // 0x8008AD04: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_8;
    // 0x8008AD04: nop

    after_8:
    // 0x8008AD08: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8008AD0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008AD10: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8008AD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AD18: jal         0x800BD218
    // 0x8008AD1C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    SysMem_DmaCopy(rdram, ctx);
        goto after_9;
    // 0x8008AD1C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_9:
    // 0x8008AD20: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008AD24: nop

    // 0x8008AD28: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8008AD2C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8008AD30: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AD34: nop

    // 0x8008AD38: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x8008AD3C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8008AD40: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008AD44: nop

    // 0x8008AD48: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8008AD4C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008AD50: b           L_8008AC80
    // 0x8008AD54: nop

        goto L_8008AC80;
    // 0x8008AD54: nop

L_8008AD58:
    // 0x8008AD58: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8008AD5C: nop

    // 0x8008AD60: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8008AD64: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AD68: jal         0x800BC980
    // 0x8008AD6C: nop

    SysMem_Free(rdram, ctx);
        goto after_10;
    // 0x8008AD6C: nop

    after_10:
    // 0x8008AD70: b           L_8008AD78
    // 0x8008AD74: nop

        goto L_8008AD78;
    // 0x8008AD74: nop

L_8008AD78:
    // 0x8008AD78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AD7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AD80: jr          $ra
    // 0x8008AD84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008AD84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006C8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C8B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C8BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C8C0: jal         0x8005F064
    // 0x8006C8C4: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C8C4: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_0:
    // 0x8006C8C8: b           L_8006C8D8
    // 0x8006C8CC: nop

        goto L_8006C8D8;
    // 0x8006C8CC: nop

    // 0x8006C8D0: b           L_8006C8D8
    // 0x8006C8D4: nop

        goto L_8006C8D8;
    // 0x8006C8D4: nop

L_8006C8D8:
    // 0x8006C8D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C8DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C8E0: jr          $ra
    // 0x8006C8E4: nop

    return;
    // 0x8006C8E4: nop

;}
RECOMP_FUNC void func_800BE510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE510: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE514: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BE518: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BE51C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800BE520: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800BE524: jal         0x800BE0FC
    // 0x800BE528: nop

    Main_GfxInit(rdram, ctx);
        goto after_0;
    // 0x800BE528: nop

    after_0:
    // 0x800BE52C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE530: jal         0x800BE18C
    // 0x800BE534: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    Main_GfxSetSegments(rdram, ctx);
        goto after_1;
    // 0x800BE534: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_1:
    // 0x800BE538: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE53C: jal         0x800BE328
    // 0x800BE540: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    Main_GfxClearScreen(rdram, ctx);
        goto after_2;
    // 0x800BE540: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_2:
    // 0x800BE544: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE548: jal         0x800ABC30
    // 0x800BE54C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_800ABC30(rdram, ctx);
        goto after_3;
    // 0x800BE54C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_3:
    // 0x800BE550: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE554: jal         0x800AC524
    // 0x800BE558: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_800AC524(rdram, ctx);
        goto after_4;
    // 0x800BE558: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_4:
    // 0x800BE55C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BE564: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800BE568: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE56C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800BE570: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BE574: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800BE578: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800BE57C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE580: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800BE584: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800BE588: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800BE58C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800BE590: jal         0x800B0E88
    // 0x800BE594: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800B0E88(rdram, ctx);
        goto after_5;
    // 0x800BE594: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x800BE598: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800BE59C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5A0: swc1        $f10, 0x25A0($at)
    MEM_W(0X25A0, ctx->r1) = ctx->f10.u32l;
    // 0x800BE5A4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BE5A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5AC: swc1        $f16, 0x25A8($at)
    MEM_W(0X25A8, ctx->r1) = ctx->f16.u32l;
    // 0x800BE5B0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800BE5B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5B8: swc1        $f18, 0x25B0($at)
    MEM_W(0X25B0, ctx->r1) = ctx->f18.u32l;
    // 0x800BE5BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE5C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BE5C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5C8: swc1        $f4, 0x25B8($at)
    MEM_W(0X25B8, ctx->r1) = ctx->f4.u32l;
    // 0x800BE5CC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800BE5D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE5D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5D8: swc1        $f6, 0x25C0($at)
    MEM_W(0X25C0, ctx->r1) = ctx->f6.u32l;
    // 0x800BE5DC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800BE5E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BE5E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5E8: swc1        $f8, 0x25C8($at)
    MEM_W(0X25C8, ctx->r1) = ctx->f8.u32l;
    // 0x800BE5EC: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800BE5F0: jal         0x80099FB0
    // 0x800BE5F4: nop

    func_80099FB0(rdram, ctx);
        goto after_6;
    // 0x800BE5F4: nop

    after_6:
    // 0x800BE5F8: b           L_800BE600
    // 0x800BE5FC: nop

        goto L_800BE600;
    // 0x800BE5FC: nop

L_800BE600:
    // 0x800BE600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BE604: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE608: jr          $ra
    // 0x800BE60C: nop

    return;
    // 0x800BE60C: nop

;}
RECOMP_FUNC void func_8006D224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D22C: jal         0x80061348
    // 0x8006D230: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D230: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006D234: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D238: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D23C: beq         $v0, $zero, L_8006D254
    if (ctx->r2 == 0) {
        // 0x8006D240: nop
    
            goto L_8006D254;
    }
    // 0x8006D240: nop

    // 0x8006D244: jal         0x80061348
    // 0x8006D248: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006D248: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x8006D24C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D250: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006D254:
    // 0x8006D254: b           L_8006D264
    // 0x8006D258: nop

        goto L_8006D264;
    // 0x8006D258: nop

    // 0x8006D25C: b           L_8006D264
    // 0x8006D260: nop

        goto L_8006D264;
    // 0x8006D260: nop

L_8006D264:
    // 0x8006D264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D26C: jr          $ra
    // 0x8006D270: nop

    return;
    // 0x8006D270: nop

;}
RECOMP_FUNC void func_800A72BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A72BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A72C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A72C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A72C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A72CC: nop

    // 0x800A72D0: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800A72D4: bne         $at, $zero, L_800A72E4
    if (ctx->r1 != 0) {
        // 0x800A72D8: nop
    
            goto L_800A72E4;
    }
    // 0x800A72D8: nop

    // 0x800A72DC: b           L_800A734C
    // 0x800A72E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A734C;
    // 0x800A72E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A72E4:
    // 0x800A72E4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800A72E8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A72EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A72F0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A72F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A72F8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A72FC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800A7300: addiu       $t9, $t9, 0x7340
    ctx->r25 = ADD32(ctx->r25, 0X7340);
    // 0x800A7304: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A7308: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A730C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7310: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A7314: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x800A7318: nop

    // 0x800A731C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A7320: bne         $t3, $zero, L_800A7330
    if (ctx->r11 != 0) {
        // 0x800A7324: nop
    
            goto L_800A7330;
    }
    // 0x800A7324: nop

    // 0x800A7328: b           L_800A734C
    // 0x800A732C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A734C;
    // 0x800A732C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A7330:
    // 0x800A7330: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7334: jal         0x800997D8
    // 0x800A7338: nop

    func_800997D8(rdram, ctx);
        goto after_0;
    // 0x800A7338: nop

    after_0:
    // 0x800A733C: b           L_800A734C
    // 0x800A7340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A734C;
    // 0x800A7340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A7344: b           L_800A734C
    // 0x800A7348: nop

        goto L_800A734C;
    // 0x800A7348: nop

L_800A734C:
    // 0x800A734C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7354: jr          $ra
    // 0x800A7358: nop

    return;
    // 0x800A7358: nop

;}
RECOMP_FUNC void func_80080AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080AA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80080AA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80080AA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80080AAC: jal         0x800BC6EC
    // 0x80080AB0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80080AB0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x80080AB4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80080AB8: nop

    // 0x80080ABC: sw          $v0, 0x20C($t6)
    MEM_W(0X20C, ctx->r14) = ctx->r2;
    // 0x80080AC0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80080AC4: nop

    // 0x80080AC8: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x80080ACC: nop

    // 0x80080AD0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80080AD4: jal         0x80081FB8
    // 0x80080AD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80081FB8(rdram, ctx);
        goto after_1;
    // 0x80080AD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80080ADC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80080AE0: nop

    // 0x80080AE4: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80080AE8: jal         0x80081FB8
    // 0x80080AEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80081FB8(rdram, ctx);
        goto after_2;
    // 0x80080AEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80080AF0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80080AF4: nop

    // 0x80080AF8: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80080AFC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80080B04: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80080B08: nop

    // 0x80080B0C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80080B10: nop

    // 0x80080B14: swc1        $f4, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f4.u32l;
    // 0x80080B18: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B1C: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x80080B20: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80080B24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80080B28: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80080B2C: nop

    // 0x80080B30: swc1        $f6, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f6.u32l;
    // 0x80080B34: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B38: nop

    // 0x80080B3C: sh          $zero, 0xE($t7)
    MEM_H(0XE, ctx->r15) = 0;
    // 0x80080B40: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B44: nop

    // 0x80080B48: lhu         $a0, 0xE($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XE);
    // 0x80080B4C: jal         0x80081B00
    // 0x80080B50: nop

    func_80081B00(rdram, ctx);
        goto after_3;
    // 0x80080B50: nop

    after_3:
    // 0x80080B54: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B58: nop

    // 0x80080B5C: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x80080B60: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80080B68: sh          $t0, 0xC($t1)
    MEM_H(0XC, ctx->r9) = ctx->r8;
    // 0x80080B6C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B70: nop

    // 0x80080B74: sh          $zero, 0xA($t2)
    MEM_H(0XA, ctx->r10) = 0;
    // 0x80080B78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80080B7C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B80: nop

    // 0x80080B84: swc1        $f8, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f8.u32l;
    // 0x80080B88: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80080B8C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80080B90: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80080B94: lh          $t6, -0x498($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X498);
    // 0x80080B98: lh          $t5, 0x7280($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7280);
    // 0x80080B9C: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x80080BA0: lh          $a3, 0x7274($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7274);
    // 0x80080BA4: addiu       $a0, $t4, 0x16
    ctx->r4 = ADD32(ctx->r12, 0X16);
    // 0x80080BA8: addiu       $a1, $t4, 0x18
    ctx->r5 = ADD32(ctx->r12, 0X18);
    // 0x80080BAC: addiu       $a2, $t4, 0x1A
    ctx->r6 = ADD32(ctx->r12, 0X1A);
    // 0x80080BB0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80080BB4: jal         0x80081B90
    // 0x80080BB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_80081B90(rdram, ctx);
        goto after_4;
    // 0x80080BB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_4:
    // 0x80080BBC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80080BC0: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80080BC4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80080BC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80080BCC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80080BD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80080BD4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80080BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80080BDC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80080BE0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80080BE4: addiu       $a1, $t8, 0x4
    ctx->r5 = ADD32(ctx->r24, 0X4);
    // 0x80080BE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80080BEC: jal         0x800B202C
    // 0x80080BF0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_5;
    // 0x80080BF0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80080BF4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80080BF8: nop

    // 0x80080BFC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80080C00: nop

    // 0x80080C04: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // 0x80080C08: b           L_80080C18
    // 0x80080C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80080C18;
    // 0x80080C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80080C10: b           L_80080C18
    // 0x80080C14: nop

        goto L_80080C18;
    // 0x80080C14: nop

L_80080C18:
    // 0x80080C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80080C1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80080C20: jr          $ra
    // 0x80080C24: nop

    return;
    // 0x80080C24: nop

;}
RECOMP_FUNC void func_80034360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034360: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80034364: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034368: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003436C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80034370: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80034374: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80034378: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8003437C: nop

    // 0x80034380: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x80034384: beq         $t8, $zero, L_80034394
    if (ctx->r24 == 0) {
        // 0x80034388: nop
    
            goto L_80034394;
    }
    // 0x80034388: nop

    // 0x8003438C: b           L_800343A8
    // 0x80034390: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
        goto L_800343A8;
    // 0x80034390: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
L_80034394:
    // 0x80034394: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80034398: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8003439C: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x800343A0: nop

    // 0x800343A4: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
L_800343A8:
    // 0x800343A8: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x800343AC: lhu         $s0, -0x73C8($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X73C8);
    // 0x800343B0: nop

    // 0x800343B4: beq         $s0, $zero, L_800343E8
    if (ctx->r16 == 0) {
        // 0x800343B8: nop
    
            goto L_800343E8;
    }
    // 0x800343B8: nop

    // 0x800343BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800343C0: beq         $s0, $at, L_80034450
    if (ctx->r16 == ctx->r1) {
        // 0x800343C4: nop
    
            goto L_80034450;
    }
    // 0x800343C4: nop

    // 0x800343C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800343CC: beq         $s0, $at, L_80034458
    if (ctx->r16 == ctx->r1) {
        // 0x800343D0: nop
    
            goto L_80034458;
    }
    // 0x800343D0: nop

    // 0x800343D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800343D8: beq         $s0, $at, L_80034570
    if (ctx->r16 == ctx->r1) {
        // 0x800343DC: nop
    
            goto L_80034570;
    }
    // 0x800343DC: nop

    // 0x800343E0: b           L_800345C8
    // 0x800343E4: nop

        goto L_800345C8;
    // 0x800343E4: nop

L_800343E8:
    // 0x800343E8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800343EC: lhu         $t2, 0x1042($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1042);
    // 0x800343F0: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800343F4: nop

    // 0x800343F8: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x800343FC: beq         $t3, $zero, L_80034448
    if (ctx->r11 == 0) {
        // 0x80034400: nop
    
            goto L_80034448;
    }
    // 0x80034400: nop

    // 0x80034404: jal         0x80031874
    // 0x80034408: nop

    func_80031874(rdram, ctx);
        goto after_0;
    // 0x80034408: nop

    after_0:
    // 0x8003440C: bne         $v0, $zero, L_80034448
    if (ctx->r2 != 0) {
        // 0x80034410: nop
    
            goto L_80034448;
    }
    // 0x80034410: nop

    // 0x80034414: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80034418: sb          $zero, 0x25EC($at)
    MEM_B(0X25EC, ctx->r1) = 0;
    // 0x8003441C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80034420: lw          $t4, 0x7284($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7284);
    // 0x80034424: nop

    // 0x80034428: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8003442C: jal         0x800319B0
    // 0x80034430: nop

    func_800319B0(rdram, ctx);
        goto after_1;
    // 0x80034430: nop

    after_1:
    // 0x80034434: jal         0x800B9000
    // 0x80034438: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    func_800B9000(rdram, ctx);
        goto after_2;
    // 0x80034438: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_2:
    // 0x8003443C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80034440: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80034444: sh          $t5, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r13;
L_80034448:
    // 0x80034448: b           L_800345C8
    // 0x8003444C: nop

        goto L_800345C8;
    // 0x8003444C: nop

L_80034450:
    // 0x80034450: b           L_800345C8
    // 0x80034454: nop

        goto L_800345C8;
    // 0x80034454: nop

L_80034458:
    // 0x80034458: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003445C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80034460: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x80034464: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80034468: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x8003446C: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x80034470: nop

    // 0x80034474: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80034478: beq         $t8, $zero, L_800344A8
    if (ctx->r24 == 0) {
        // 0x8003447C: nop
    
            goto L_800344A8;
    }
    // 0x8003447C: nop

    // 0x80034480: jal         0x800B9000
    // 0x80034484: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x80034484: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x80034488: jal         0x80031728
    // 0x8003448C: nop

    func_80031728(rdram, ctx);
        goto after_4;
    // 0x8003448C: nop

    after_4:
    // 0x80034490: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80034494: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80034498: sb          $t9, 0x25EC($at)
    MEM_B(0X25EC, ctx->r1) = ctx->r25;
    // 0x8003449C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800344A0: b           L_80034568
    // 0x800344A4: sh          $zero, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = 0;
        goto L_80034568;
    // 0x800344A4: sh          $zero, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = 0;
L_800344A8:
    // 0x800344A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800344AC: lhu         $t1, 0xFF4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XFF4);
    // 0x800344B0: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x800344B4: nop

    // 0x800344B8: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x800344BC: beq         $t2, $zero, L_80034568
    if (ctx->r10 == 0) {
        // 0x800344C0: nop
    
            goto L_80034568;
    }
    // 0x800344C0: nop

    // 0x800344C4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800344C8: sb          $zero, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = 0;
    // 0x800344CC: jal         0x800B9000
    // 0x800344D0: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x800344D0: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_5:
    // 0x800344D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800344D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800344DC: sb          $t3, 0x25EC($at)
    MEM_B(0X25EC, ctx->r1) = ctx->r11;
    // 0x800344E0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800344E4: lw          $t4, 0x7284($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7284);
    // 0x800344E8: nop

    // 0x800344EC: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x800344F0: jal         0x800319B0
    // 0x800344F4: nop

    func_800319B0(rdram, ctx);
        goto after_6;
    // 0x800344F4: nop

    after_6:
    // 0x800344F8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800344FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80034504: swc1        $f6, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f6.u32l;
    // 0x80034508: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003450C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80034510: sh          $t5, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r13;
    // 0x80034514: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80034518: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8003451C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80034520: beq         $t6, $at, L_80034568
    if (ctx->r14 == ctx->r1) {
        // 0x80034524: nop
    
            goto L_80034568;
    }
    // 0x80034524: nop

    // 0x80034528: jal         0x8005F064
    // 0x8003452C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_8005F064(rdram, ctx);
        goto after_7;
    // 0x8003452C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_7:
    // 0x80034530: beq         $v0, $zero, L_80034568
    if (ctx->r2 == 0) {
        // 0x80034534: nop
    
            goto L_80034568;
    }
    // 0x80034534: nop

    // 0x80034538: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003453C: lw          $t8, 0x64C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X64C);
    // 0x80034540: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80034544: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80034548: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8003454C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80034550: lw          $t7, 0x718C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X718C);
    // 0x80034554: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80034558: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003455C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80034560: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80034564: sw          $t0, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r8;
L_80034568:
    // 0x80034568: b           L_800345C8
    // 0x8003456C: nop

        goto L_800345C8;
    // 0x8003456C: nop

L_80034570:
    // 0x80034570: jal         0x80031AC8
    // 0x80034574: nop

    func_80031AC8(rdram, ctx);
        goto after_8;
    // 0x80034574: nop

    after_8:
    // 0x80034578: bne         $v0, $zero, L_800345C0
    if (ctx->r2 != 0) {
        // 0x8003457C: nop
    
            goto L_800345C0;
    }
    // 0x8003457C: nop

    // 0x80034580: jal         0x80031728
    // 0x80034584: nop

    func_80031728(rdram, ctx);
        goto after_9;
    // 0x80034584: nop

    after_9:
    // 0x80034588: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8003458C: lh          $t1, 0x7254($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7254);
    // 0x80034590: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80034594: ori         $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 | 0X8000;
    // 0x80034598: sh          $t2, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r10;
    // 0x8003459C: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800345A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800345A4: sw          $t3, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r11;
    // 0x800345A8: lhu         $t4, 0x2A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2A);
    // 0x800345AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800345B0: sh          $t4, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r12;
    // 0x800345B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800345B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800345BC: sh          $t5, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r13;
L_800345C0:
    // 0x800345C0: b           L_800345C8
    // 0x800345C4: nop

        goto L_800345C8;
    // 0x800345C4: nop

L_800345C8:
    // 0x800345C8: b           L_800345D0
    // 0x800345CC: nop

        goto L_800345D0;
    // 0x800345CC: nop

L_800345D0:
    // 0x800345D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800345D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800345D8: jr          $ra
    // 0x800345DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800345DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006E678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E680: jal         0x80061348
    // 0x8006E684: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E684: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E688: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E68C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E690: beq         $v0, $zero, L_8006E6A8
    if (ctx->r2 == 0) {
        // 0x8006E694: nop
    
            goto L_8006E6A8;
    }
    // 0x8006E694: nop

    // 0x8006E698: jal         0x80061348
    // 0x8006E69C: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E69C: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_1:
    // 0x8006E6A0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E6A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E6A8:
    // 0x8006E6A8: b           L_8006E6B8
    // 0x8006E6AC: nop

        goto L_8006E6B8;
    // 0x8006E6AC: nop

    // 0x8006E6B0: b           L_8006E6B8
    // 0x8006E6B4: nop

        goto L_8006E6B8;
    // 0x8006E6B4: nop

L_8006E6B8:
    // 0x8006E6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E6BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E6C0: jr          $ra
    // 0x8006E6C4: nop

    return;
    // 0x8006E6C4: nop

;}
RECOMP_FUNC void func_8008DE78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DE78: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008DE7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DE80: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8008DE84: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8008DE88: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8008DE8C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008DE90: lhu         $a2, 0x4E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X4E);
    // 0x8008DE94: jal         0x8008DEC8
    // 0x8008DE98: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008DEC8(rdram, ctx);
        goto after_0;
    // 0x8008DE98: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8008DE9C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008DEA0: lhu         $a1, 0x52($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X52);
    // 0x8008DEA4: addiu       $a0, $a0, -0xA18
    ctx->r4 = ADD32(ctx->r4, -0XA18);
    // 0x8008DEA8: jal         0x8008ECE4
    // 0x8008DEAC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8008DEAC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8008DEB0: b           L_8008DEB8
    // 0x8008DEB4: nop

        goto L_8008DEB8;
    // 0x8008DEB4: nop

L_8008DEB8:
    // 0x8008DEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DEBC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008DEC0: jr          $ra
    // 0x8008DEC4: nop

    return;
    // 0x8008DEC4: nop

;}
RECOMP_FUNC void func_8008ECE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ECE4: addiu       $sp, $sp, -0x420
    ctx->r29 = ADD32(ctx->r29, -0X420);
    // 0x8008ECE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008ECEC: sw          $a0, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r4;
    // 0x8008ECF0: sw          $a1, 0x424($sp)
    MEM_W(0X424, ctx->r29) = ctx->r5;
    // 0x8008ECF4: sw          $a2, 0x428($sp)
    MEM_W(0X428, ctx->r29) = ctx->r6;
    // 0x8008ECF8: sw          $a3, 0x42C($sp)
    MEM_W(0X42C, ctx->r29) = ctx->r7;
    // 0x8008ECFC: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
    // 0x8008ED00: sw          $t6, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r14;
    // 0x8008ED04: addiu       $t7, $sp, 0x420
    ctx->r15 = ADD32(ctx->r29, 0X420);
    // 0x8008ED08: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8008ED0C: sw          $t8, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r24;
    // 0x8008ED10: lw          $a0, 0x418($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X418);
    // 0x8008ED14: lw          $a1, 0x420($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X420);
    // 0x8008ED18: lw          $a2, 0x41C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X41C);
    // 0x8008ED1C: jal         0x8008EDA4
    // 0x8008ED20: nop

    vsprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008ED20: nop

    after_0:
    // 0x8008ED24: jal         0x80090E58
    // 0x8008ED28: addiu       $a0, $sp, 0x418
    ctx->r4 = ADD32(ctx->r29, 0X418);
    func_80090E58(rdram, ctx);
        goto after_1;
    // 0x8008ED28: addiu       $a0, $sp, 0x418
    ctx->r4 = ADD32(ctx->r29, 0X418);
    after_1:
    // 0x8008ED2C: b           L_8008ED3C
    // 0x8008ED30: nop

        goto L_8008ED3C;
    // 0x8008ED30: nop

    // 0x8008ED34: b           L_8008ED3C
    // 0x8008ED38: nop

        goto L_8008ED3C;
    // 0x8008ED38: nop

L_8008ED3C:
    // 0x8008ED3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008ED40: addiu       $sp, $sp, 0x420
    ctx->r29 = ADD32(ctx->r29, 0X420);
    // 0x8008ED44: jr          $ra
    // 0x8008ED48: nop

    return;
    // 0x8008ED48: nop

;}
RECOMP_FUNC void func_800B9DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9DD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9DDC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800B9DE0: lw          $t6, -0x730C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X730C);
    // 0x800B9DE4: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800B9DE8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800B9DEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9DF0: sw          $t7, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r15;
    // 0x800B9DF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B9DF8:
    // 0x800B9DF8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9DFC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B9E00: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B9E04: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B9E08: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B9E0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B9E10: lw          $t0, -0x1A64($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1A64);
    // 0x800B9E14: nop

    // 0x800B9E18: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800B9E1C: beq         $t1, $zero, L_800B9E58
    if (ctx->r9 == 0) {
        // 0x800B9E20: nop
    
            goto L_800B9E58;
    }
    // 0x800B9E20: nop

    // 0x800B9E24: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800B9E28: lw          $t2, -0x730C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X730C);
    // 0x800B9E2C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9E30: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x800B9E34: sw          $t3, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r11;
    // 0x800B9E38: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9E3C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B9E40: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800B9E44: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B9E48: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B9E4C: addiu       $t6, $t6, -0x1A68
    ctx->r14 = ADD32(ctx->r14, -0X1A68);
    // 0x800B9E50: jal         0x800B9F48
    // 0x800B9E54: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    func_800B9F48(rdram, ctx);
        goto after_0;
    // 0x800B9E54: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_0:
L_800B9E58:
    // 0x800B9E58: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9E5C: nop

    // 0x800B9E60: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B9E64: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x800B9E68: bne         $at, $zero, L_800B9DF8
    if (ctx->r1 != 0) {
        // 0x800B9E6C: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800B9DF8;
    }
    // 0x800B9E6C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800B9E70: b           L_800B9E78
    // 0x800B9E74: nop

        goto L_800B9E78;
    // 0x800B9E74: nop

L_800B9E78:
    // 0x800B9E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9E80: jr          $ra
    // 0x800B9E84: nop

    return;
    // 0x800B9E84: nop

;}
RECOMP_FUNC void func_800A9564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9564: addiu       $sp, $sp, -0x1D8
    ctx->r29 = ADD32(ctx->r29, -0X1D8);
    // 0x800A9568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A956C: sw          $a0, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r4;
    // 0x800A9570: sw          $a1, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r5;
    // 0x800A9574: sw          $a2, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r6;
    // 0x800A9578: sw          $a3, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r7;
    // 0x800A957C: jal         0x800C1680
    // 0x800A9580: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800A9580: nop

    after_0:
    // 0x800A9584: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A9588: jal         0x800C1AF4
    // 0x800A958C: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_1;
    // 0x800A958C: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    after_1:
    // 0x800A9590: jal         0x800C1B64
    // 0x800A9594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C1B64(rdram, ctx);
        goto after_2;
    // 0x800A9594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800A9598: lw          $a0, 0x1F0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1F0);
    // 0x800A959C: jal         0x800C1D44
    // 0x800A95A0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    func_800C1D44(rdram, ctx);
        goto after_3;
    // 0x800A95A0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_3:
    // 0x800A95A4: lw          $a0, 0x1DC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A95A8: jal         0x800C1D44
    // 0x800A95AC: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_4;
    // 0x800A95AC: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_4:
    // 0x800A95B0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A95B4: jal         0x800C1A84
    // 0x800A95B8: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_5;
    // 0x800A95B8: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_5:
    // 0x800A95BC: jal         0x800C1A28
    // 0x800A95C0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x800A95C0: nop

    after_6:
    // 0x800A95C4: lw          $t6, 0x1DC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A95C8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A95CC: lw          $t8, 0x7250($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7250);
    // 0x800A95D0: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800A95D4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A95D8: lw          $t0, 0x7258($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7258);
    // 0x800A95DC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800A95E0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800A95E4: sw          $t1, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r9;
    // 0x800A95E8: lw          $t2, 0x1B4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A95EC: nop

    // 0x800A95F0: andi        $t3, $t2, 0x200
    ctx->r11 = ctx->r10 & 0X200;
    // 0x800A95F4: bne         $t3, $zero, L_800A9634
    if (ctx->r11 != 0) {
        // 0x800A95F8: nop
    
            goto L_800A9634;
    }
    // 0x800A95F8: nop

    // 0x800A95FC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800A9600: addiu       $t4, $t4, 0x6BC8
    ctx->r12 = ADD32(ctx->r12, 0X6BC8);
    // 0x800A9604: lwc1        $f4, 0x38($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X38);
    // 0x800A9608: lw          $a0, 0x1D8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1D8);
    // 0x800A960C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A9610: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A9614: jal         0x8009A084
    // 0x800A9618: nop

    func_8009A084(rdram, ctx);
        goto after_7;
    // 0x800A9618: nop

    after_7:
    // 0x800A961C: bgez        $v0, L_800A962C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A9620: nop
    
            goto L_800A962C;
    }
    // 0x800A9620: nop

    // 0x800A9624: b           L_800ABAB8
    // 0x800A9628: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ABAB8;
    // 0x800A9628: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A962C:
    // 0x800A962C: b           L_800A96D4
    // 0x800A9630: nop

        goto L_800A96D4;
    // 0x800A9630: nop

L_800A9634:
    // 0x800A9634: lw          $t5, 0x1B4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9638: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800A963C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800A9640: beq         $t6, $zero, L_800A9680
    if (ctx->r14 == 0) {
        // 0x800A9644: nop
    
            goto L_800A9680;
    }
    // 0x800A9644: nop

    // 0x800A9648: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800A964C: addiu       $t7, $t7, 0x6BC8
    ctx->r15 = ADD32(ctx->r15, 0X6BC8);
    // 0x800A9650: lwc1        $f8, 0x38($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X38);
    // 0x800A9654: lw          $a0, 0x1D8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1D8);
    // 0x800A9658: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A965C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A9660: jal         0x8009A084
    // 0x800A9664: nop

    func_8009A084(rdram, ctx);
        goto after_8;
    // 0x800A9664: nop

    after_8:
    // 0x800A9668: bgez        $v0, L_800A9678
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A966C: nop
    
            goto L_800A9678;
    }
    // 0x800A966C: nop

    // 0x800A9670: b           L_800ABAB8
    // 0x800A9674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ABAB8;
    // 0x800A9674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A9678:
    // 0x800A9678: b           L_800A96D4
    // 0x800A967C: nop

        goto L_800A96D4;
    // 0x800A967C: nop

L_800A9680:
    // 0x800A9680: lw          $t8, 0x1B4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9684: nop

    // 0x800A9688: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x800A968C: beq         $t9, $zero, L_800A96D4
    if (ctx->r25 == 0) {
        // 0x800A9690: nop
    
            goto L_800A96D4;
    }
    // 0x800A9690: nop

    // 0x800A9694: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A9698: lwc1        $f16, 0x25A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25A8);
    // 0x800A969C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800A96A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A96A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A96A8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A96AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A96B0: lw          $a0, 0x1D8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1D8);
    // 0x800A96B4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A96B8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A96BC: jal         0x8009A084
    // 0x800A96C0: nop

    func_8009A084(rdram, ctx);
        goto after_9;
    // 0x800A96C0: nop

    after_9:
    // 0x800A96C4: bgez        $v0, L_800A96D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A96C8: nop
    
            goto L_800A96D4;
    }
    // 0x800A96C8: nop

    // 0x800A96CC: b           L_800ABAB8
    // 0x800A96D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ABAB8;
    // 0x800A96D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A96D4:
    // 0x800A96D4: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A96D8: lw          $t2, 0x1F0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1F0);
    // 0x800A96DC: lh          $t1, 0x11E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X11E);
    // 0x800A96E0: lwc1        $f18, 0xE8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x800A96E4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A96E8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A96EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A96F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A96F4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A96F8: nop

    // 0x800A96FC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A9700: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A9704: nop

    // 0x800A9708: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A970C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9710: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9714: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A9718: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A971C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A9720: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A9724: sh          $t4, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r12;
    // 0x800A9728: nop

    // 0x800A972C: jal         0x800C1680
    // 0x800A9730: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_10;
    // 0x800A9730: nop

    after_10:
    // 0x800A9734: lw          $a0, 0x1F0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1F0);
    // 0x800A9738: jal         0x800C1AF4
    // 0x800A973C: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_11;
    // 0x800A973C: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_11:
    // 0x800A9740: lw          $a0, 0x1DC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9744: jal         0x800C1D44
    // 0x800A9748: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_12;
    // 0x800A9748: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_12:
    // 0x800A974C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A9750: jal         0x800C1A84
    // 0x800A9754: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_13;
    // 0x800A9754: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_13:
    // 0x800A9758: jal         0x800C1A28
    // 0x800A975C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_14;
    // 0x800A975C: nop

    after_14:
    // 0x800A9760: lw          $t5, 0x1D8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D8);
    // 0x800A9764: nop

    // 0x800A9768: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A976C: nop

    // 0x800A9770: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800A9774: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A9778: sw          $t7, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r15;
    // 0x800A977C: lwc1        $f16, 0x1E8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x800A9780: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A9784: nop

    // 0x800A9788: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A978C: nop

    // 0x800A9790: bc1f        L_800A97A8
    if (!c1cs) {
        // 0x800A9794: nop
    
            goto L_800A97A8;
    }
    // 0x800A9794: nop

    // 0x800A9798: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A979C: lwc1        $f4, -0x750($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X750);
    // 0x800A97A0: nop

    // 0x800A97A4: swc1        $f4, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->f4.u32l;
L_800A97A8:
    // 0x800A97A8: lwc1        $f6, 0x1EC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1EC);
    // 0x800A97AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A97B0: nop

    // 0x800A97B4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800A97B8: nop

    // 0x800A97BC: bc1f        L_800A97D4
    if (!c1cs) {
        // 0x800A97C0: nop
    
            goto L_800A97D4;
    }
    // 0x800A97C0: nop

    // 0x800A97C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A97C8: lwc1        $f10, -0x74C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X74C);
    // 0x800A97CC: nop

    // 0x800A97D0: swc1        $f10, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->f10.u32l;
L_800A97D4:
    // 0x800A97D4: lw          $t8, 0x1DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A97D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A97DC: lwc1        $f16, 0xF4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x800A97E0: lwc1        $f18, 0xFC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x800A97E4: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A97E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A97EC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800A97F0: addiu       $t9, $t9, 0x6BC8
    ctx->r25 = ADD32(ctx->r25, 0X6BC8);
    // 0x800A97F4: lwc1        $f10, 0x38($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X38);
    // 0x800A97F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A97FC: nop

    // 0x800A9800: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A9804: swc1        $f16, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f16.u32l;
    // 0x800A9808: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A980C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A9810: lwc1        $f18, 0xF8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x800A9814: lwc1        $f4, 0xFC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XFC);
    // 0x800A9818: lwc1        $f8, 0x7218($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A981C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A9820: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800A9824: addiu       $t1, $t1, 0x6BC8
    ctx->r9 = ADD32(ctx->r9, 0X6BC8);
    // 0x800A9828: lwc1        $f16, 0x38($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X38);
    // 0x800A982C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A9830: nop

    // 0x800A9834: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A9838: swc1        $f18, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f18.u32l;
    // 0x800A983C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800A9840: addiu       $t2, $t2, 0x6BC8
    ctx->r10 = ADD32(ctx->r10, 0X6BC8);
    // 0x800A9844: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A9848: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A984C: lwc1        $f6, 0x38($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X38);
    // 0x800A9850: nop

    // 0x800A9854: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A9858: swc1        $f8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f8.u32l;
    // 0x800A985C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9860: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A9864: lwc1        $f19, -0x748($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X748);
    // 0x800A9868: lwc1        $f18, -0x744($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X744);
    // 0x800A986C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800A9870: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x800A9874: nop

    // 0x800A9878: bc1f        L_800A98B0
    if (!c1cs) {
        // 0x800A987C: nop
    
            goto L_800A98B0;
    }
    // 0x800A987C: nop

    // 0x800A9880: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9884: lwc1        $f5, -0x740($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X740);
    // 0x800A9888: lwc1        $f4, -0x73C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73C);
    // 0x800A988C: nop

    // 0x800A9890: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x800A9894: nop

    // 0x800A9898: bc1f        L_800A98B0
    if (!c1cs) {
        // 0x800A989C: nop
    
            goto L_800A98B0;
    }
    // 0x800A989C: nop

    // 0x800A98A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A98A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A98A8: nop

    // 0x800A98AC: swc1        $f6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f6.u32l;
L_800A98B0:
    // 0x800A98B0: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800A98B4: addiu       $t3, $t3, 0x6BC8
    ctx->r11 = ADD32(ctx->r11, 0X6BC8);
    // 0x800A98B8: lwc1        $f8, 0x30($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X30);
    // 0x800A98BC: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A98C0: lwc1        $f16, 0x1E8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x800A98C4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A98C8: nop

    // 0x800A98CC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A98D0: swc1        $f4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f4.u32l;
    // 0x800A98D4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800A98D8: addiu       $t4, $t4, 0x6BC8
    ctx->r12 = ADD32(ctx->r12, 0X6BC8);
    // 0x800A98DC: lwc1        $f6, 0x34($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X34);
    // 0x800A98E0: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A98E4: lwc1        $f18, 0x1EC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1EC);
    // 0x800A98E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A98EC: nop

    // 0x800A98F0: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A98F4: swc1        $f16, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f16.u32l;
    // 0x800A98F8: lw          $t5, 0x1B4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A98FC: nop

    // 0x800A9900: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x800A9904: beq         $t6, $zero, L_800A9944
    if (ctx->r14 == 0) {
        // 0x800A9908: nop
    
            goto L_800A9944;
    }
    // 0x800A9908: nop

    // 0x800A990C: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9910: nop

    // 0x800A9914: lwc1        $f4, 0xF4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x800A9918: lwc1        $f6, 0xFC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x800A991C: nop

    // 0x800A9920: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A9924: swc1        $f8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f8.u32l;
    // 0x800A9928: lw          $t8, 0x1DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A992C: nop

    // 0x800A9930: lwc1        $f10, 0xF8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x800A9934: lwc1        $f18, 0xFC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x800A9938: nop

    // 0x800A993C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A9940: swc1        $f16, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f16.u32l;
L_800A9944:
    // 0x800A9944: lwc1        $f4, 0x14C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800A9948: lwc1        $f6, 0x1E8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x800A994C: nop

    // 0x800A9950: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A9954: swc1        $f8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f8.u32l;
    // 0x800A9958: lwc1        $f10, 0x148($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800A995C: lwc1        $f18, 0x1EC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1EC);
    // 0x800A9960: nop

    // 0x800A9964: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A9968: swc1        $f16, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f16.u32l;
    // 0x800A996C: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800A9970: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A9974: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A9978: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A997C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A9980: nop

    // 0x800A9984: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800A9988: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800A998C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800A9990: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A9994: nop

    // 0x800A9998: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800A999C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A99A0: nop

    // 0x800A99A4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A99A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A99AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A99B0: nop

    // 0x800A99B4: cvt.w.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_D(ctx->f16.d);
    // 0x800A99B8: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800A99BC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A99C0: sh          $t0, 0x152($sp)
    MEM_H(0X152, ctx->r29) = ctx->r8;
    // 0x800A99C4: nop

    // 0x800A99C8: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800A99CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A99D0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A99D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A99D8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800A99DC: nop

    // 0x800A99E0: div.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800A99E4: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800A99E8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A99EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A99F0: nop

    // 0x800A99F4: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800A99F8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A99FC: nop

    // 0x800A9A00: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A9A04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9A08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9A0C: nop

    // 0x800A9A10: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800A9A14: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x800A9A18: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A9A1C: sh          $t2, 0x150($sp)
    MEM_H(0X150, ctx->r29) = ctx->r10;
    // 0x800A9A20: nop

    // 0x800A9A24: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9A28: nop

    // 0x800A9A2C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A9A30: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800A9A34: sw          $t3, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r11;
    // 0x800A9A38: lw          $t6, 0x138($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X138);
    // 0x800A9A3C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A9A40: ori         $t5, $t5, 0x1402
    ctx->r13 = ctx->r13 | 0X1402;
    // 0x800A9A44: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A9A48: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x800A9A4C: nop

    // 0x800A9A50: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A9A54: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9A58: nop

    // 0x800A9A5C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A9A60: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800A9A64: sw          $t8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r24;
    // 0x800A9A68: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x800A9A6C: lui         $t0, 0xBB00
    ctx->r8 = S32(0XBB00 << 16);
    // 0x800A9A70: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x800A9A74: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A9A78: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x800A9A7C: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800A9A80: ori         $t2, $t2, 0x8000
    ctx->r10 = ctx->r10 | 0X8000;
    // 0x800A9A84: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A9A88: lw          $t4, 0x1B4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9A8C: nop

    // 0x800A9A90: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x800A9A94: beq         $t5, $zero, L_800A9B78
    if (ctx->r13 == 0) {
        // 0x800A9A98: nop
    
            goto L_800A9B78;
    }
    // 0x800A9A98: nop

    // 0x800A9A9C: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9AA0: nop

    // 0x800A9AA4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A9AA8: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800A9AAC: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
    // 0x800A9AB0: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x800A9AB4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A9AB8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A9ABC: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9AC0: nop

    // 0x800A9AC4: lh          $t4, 0x11A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X11A);
    // 0x800A9AC8: lh          $t1, 0x118($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X118);
    // 0x800A9ACC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A9AD0: lh          $t8, 0x11C($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X11C);
    // 0x800A9AD4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800A9AD8: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x800A9ADC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800A9AE0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800A9AE4: lh          $t4, -0x4CDC($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CDC);
    // 0x800A9AE8: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800A9AEC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800A9AF0: sll         $t1, $t9, 8
    ctx->r9 = S32(ctx->r25 << 8);
    // 0x800A9AF4: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x800A9AF8: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x800A9AFC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A9B00: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x800A9B04: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800A9B08: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9B0C: nop

    // 0x800A9B10: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A9B14: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800A9B18: sw          $t0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r8;
    // 0x800A9B1C: lw          $t7, 0x12C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X12C);
    // 0x800A9B20: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800A9B24: ori         $t9, $t9, 0x97FF
    ctx->r25 = ctx->r25 | 0X97FF;
    // 0x800A9B28: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A9B2C: lw          $t4, 0x12C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X12C);
    // 0x800A9B30: lui         $t1, 0xFF2C
    ctx->r9 = S32(0XFF2C << 16);
    // 0x800A9B34: ori         $t1, $t1, 0xFE7F
    ctx->r9 = ctx->r9 | 0XFE7F;
    // 0x800A9B38: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800A9B3C: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9B40: nop

    // 0x800A9B44: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A9B48: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800A9B4C: sw          $t2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r10;
    // 0x800A9B50: lw          $t6, 0x128($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X128);
    // 0x800A9B54: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A9B58: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x800A9B5C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800A9B60: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    // 0x800A9B64: lui         $t0, 0xF0A
    ctx->r8 = S32(0XF0A << 16);
    // 0x800A9B68: ori         $t0, $t0, 0x233
    ctx->r8 = ctx->r8 | 0X233;
    // 0x800A9B6C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800A9B70: b           L_800A9CD0
    // 0x800A9B74: nop

        goto L_800A9CD0;
    // 0x800A9B74: nop

L_800A9B78:
    // 0x800A9B78: lw          $t9, 0x1B4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9B7C: nop

    // 0x800A9B80: andi        $t7, $t9, 0x8000
    ctx->r15 = ctx->r25 & 0X8000;
    // 0x800A9B84: beq         $t7, $zero, L_800A9C68
    if (ctx->r15 == 0) {
        // 0x800A9B88: nop
    
            goto L_800A9C68;
    }
    // 0x800A9B88: nop

    // 0x800A9B8C: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9B90: nop

    // 0x800A9B94: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x800A9B98: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800A9B9C: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x800A9BA0: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x800A9BA4: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A9BA8: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A9BAC: lw          $t3, 0x1DC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9BB0: nop

    // 0x800A9BB4: lh          $t9, 0x11A($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X11A);
    // 0x800A9BB8: lh          $t6, 0x118($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X118);
    // 0x800A9BBC: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800A9BC0: lh          $t2, 0x11C($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X11C);
    // 0x800A9BC4: andi        $t0, $t6, 0xFF
    ctx->r8 = ctx->r14 & 0XFF;
    // 0x800A9BC8: sll         $t8, $t0, 24
    ctx->r24 = S32(ctx->r8 << 24);
    // 0x800A9BCC: sll         $t1, $t7, 16
    ctx->r9 = S32(ctx->r15 << 16);
    // 0x800A9BD0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800A9BD4: lh          $t9, -0x4CDC($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4CDC);
    // 0x800A9BD8: or          $t4, $t8, $t1
    ctx->r12 = ctx->r24 | ctx->r9;
    // 0x800A9BDC: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x800A9BE0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800A9BE4: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800A9BE8: or          $t0, $t4, $t6
    ctx->r8 = ctx->r12 | ctx->r14;
    // 0x800A9BEC: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800A9BF0: or          $t8, $t0, $t7
    ctx->r24 = ctx->r8 | ctx->r15;
    // 0x800A9BF4: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800A9BF8: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9BFC: nop

    // 0x800A9C00: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A9C04: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800A9C08: sw          $t3, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r11;
    // 0x800A9C0C: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x800A9C10: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x800A9C14: ori         $t5, $t5, 0x97FF
    ctx->r13 = ctx->r13 | 0X97FF;
    // 0x800A9C18: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A9C1C: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x800A9C20: lui         $t6, 0xFF2C
    ctx->r14 = S32(0XFF2C << 16);
    // 0x800A9C24: ori         $t6, $t6, 0xFE7F
    ctx->r14 = ctx->r14 | 0XFE7F;
    // 0x800A9C28: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800A9C2C: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9C30: nop

    // 0x800A9C34: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800A9C38: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800A9C3C: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    // 0x800A9C40: lw          $t1, 0x11C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X11C);
    // 0x800A9C44: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x800A9C48: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x800A9C4C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800A9C50: lw          $t2, 0x11C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X11C);
    // 0x800A9C54: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x800A9C58: ori         $t3, $t3, 0x4A50
    ctx->r11 = ctx->r11 | 0X4A50;
    // 0x800A9C5C: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x800A9C60: b           L_800A9CD0
    // 0x800A9C64: nop

        goto L_800A9CD0;
    // 0x800A9C64: nop

L_800A9C68:
    // 0x800A9C68: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9C6C: nop

    // 0x800A9C70: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x800A9C74: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800A9C78: sw          $t5, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r13;
    // 0x800A9C7C: lw          $t9, 0x118($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X118);
    // 0x800A9C80: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800A9C84: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800A9C88: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800A9C8C: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x800A9C90: lui         $t0, 0xFFFC
    ctx->r8 = S32(0XFFFC << 16);
    // 0x800A9C94: ori         $t0, $t0, 0xF279
    ctx->r8 = ctx->r8 | 0XF279;
    // 0x800A9C98: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x800A9C9C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9CA0: nop

    // 0x800A9CA4: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x800A9CA8: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800A9CAC: sw          $t8, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r24;
    // 0x800A9CB0: lw          $t2, 0x114($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X114);
    // 0x800A9CB4: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A9CB8: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x800A9CBC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A9CC0: lw          $t4, 0x114($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X114);
    // 0x800A9CC4: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x800A9CC8: ori         $t5, $t5, 0x3078
    ctx->r13 = ctx->r13 | 0X3078;
    // 0x800A9CCC: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
L_800A9CD0:
    // 0x800A9CD0: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9CD4: nop

    // 0x800A9CD8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800A9CDC: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800A9CE0: sw          $t6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r14;
    // 0x800A9CE4: lw          $t7, 0x110($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X110);
    // 0x800A9CE8: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x800A9CEC: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x800A9CF0: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
    // 0x800A9CF4: addiu       $t8, $zero, 0x205
    ctx->r24 = ADD32(0, 0X205);
    // 0x800A9CF8: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800A9CFC: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9D00: nop

    // 0x800A9D04: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A9D08: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800A9D0C: sw          $t3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r11;
    // 0x800A9D10: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x800A9D14: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A9D18: ori         $t5, $t5, 0x1301
    ctx->r13 = ctx->r13 | 0X1301;
    // 0x800A9D1C: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A9D20: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x800A9D24: nop

    // 0x800A9D28: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A9D2C: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9D30: nop

    // 0x800A9D34: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A9D38: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800A9D3C: sw          $t9, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r25;
    // 0x800A9D40: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x800A9D44: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A9D48: ori         $t7, $t7, 0x1102
    ctx->r15 = ctx->r15 | 0X1102;
    // 0x800A9D4C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A9D50: lw          $t1, 0x108($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X108);
    // 0x800A9D54: nop

    // 0x800A9D58: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A9D5C: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9D60: nop

    // 0x800A9D64: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A9D68: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800A9D6C: sw          $t3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r11;
    // 0x800A9D70: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x800A9D74: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A9D78: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x800A9D7C: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A9D80: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800A9D84: nop

    // 0x800A9D88: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A9D8C: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9D90: nop

    // 0x800A9D94: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A9D98: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800A9D9C: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x800A9DA0: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x800A9DA4: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A9DA8: ori         $t7, $t7, 0x903
    ctx->r15 = ctx->r15 | 0X903;
    // 0x800A9DAC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A9DB0: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x800A9DB4: addiu       $t1, $zero, 0xC00
    ctx->r9 = ADD32(0, 0XC00);
    // 0x800A9DB8: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800A9DBC: lw          $t2, 0x1B4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9DC0: nop

    // 0x800A9DC4: andi        $t5, $t2, 0x4
    ctx->r13 = ctx->r10 & 0X4;
    // 0x800A9DC8: bne         $t5, $zero, L_800A9E08
    if (ctx->r13 != 0) {
        // 0x800A9DCC: nop
    
            goto L_800A9E08;
    }
    // 0x800A9DCC: nop

    // 0x800A9DD0: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9DD4: nop

    // 0x800A9DD8: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x800A9DDC: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800A9DE0: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
    // 0x800A9DE4: lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XFC);
    // 0x800A9DE8: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A9DEC: ori         $t9, $t9, 0xC02
    ctx->r25 = ctx->r25 | 0XC02;
    // 0x800A9DF0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A9DF4: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x800A9DF8: nop

    // 0x800A9DFC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A9E00: b           L_800A9E38
    // 0x800A9E04: nop

        goto L_800A9E38;
    // 0x800A9E04: nop

L_800A9E08:
    // 0x800A9E08: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9E0C: nop

    // 0x800A9E10: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x800A9E14: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800A9E18: sw          $t8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r24;
    // 0x800A9E1C: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x800A9E20: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A9E24: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x800A9E28: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A9E2C: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x800A9E30: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x800A9E34: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
L_800A9E38:
    // 0x800A9E38: lw          $t6, 0x1DC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9E3C: nop

    // 0x800A9E40: lh          $t9, 0x10C($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X10C);
    // 0x800A9E44: nop

    // 0x800A9E48: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x800A9E4C: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x800A9E50: sw          $t7, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r15;
    // 0x800A9E54: lw          $t8, 0x1DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9E58: nop

    // 0x800A9E5C: lh          $t1, 0x10E($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X10E);
    // 0x800A9E60: nop

    // 0x800A9E64: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x800A9E68: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x800A9E6C: sw          $t2, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r10;
    // 0x800A9E70: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800A9E74: addiu       $t5, $t5, 0x6BC8
    ctx->r13 = ADD32(ctx->r13, 0X6BC8);
    // 0x800A9E78: lwc1        $f4, 0x30($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X30);
    // 0x800A9E7C: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x800A9E80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9E84: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800A9E88: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A9E8C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A9E90: nop

    // 0x800A9E94: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A9E98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9E9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9EA0: nop

    // 0x800A9EA4: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A9EA8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800A9EAC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A9EB0: sw          $t6, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r14;
    // 0x800A9EB4: nop

    // 0x800A9EB8: lw          $t9, 0x1DC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9EBC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800A9EC0: lh          $t0, 0x10C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10C);
    // 0x800A9EC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9EC8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800A9ECC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A9ED0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9ED4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A9ED8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A9EDC: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800A9EE0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800A9EE4: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800A9EE8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9EEC: nop

    // 0x800A9EF0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A9EF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9EF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9EFC: nop

    // 0x800A9F00: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A9F04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9F08: swc1        $f4, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->f4.u32l;
    // 0x800A9F0C: nop

    // 0x800A9F10: lw          $t8, 0x1A0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A0);
    // 0x800A9F14: lw          $t1, 0x1C0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C0);
    // 0x800A9F18: nop

    // 0x800A9F1C: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x800A9F20: addiu       $t2, $t3, -0x3F
    ctx->r10 = ADD32(ctx->r11, -0X3F);
    // 0x800A9F24: bgez        $t2, L_800A9F34
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A9F28: sra         $t5, $t2, 6
        ctx->r13 = S32(SIGNED(ctx->r10) >> 6);
            goto L_800A9F34;
    }
    // 0x800A9F28: sra         $t5, $t2, 6
    ctx->r13 = S32(SIGNED(ctx->r10) >> 6);
    // 0x800A9F2C: addiu       $at, $t2, 0x3F
    ctx->r1 = ADD32(ctx->r10, 0X3F);
    // 0x800A9F30: sra         $t5, $at, 6
    ctx->r13 = S32(SIGNED(ctx->r1) >> 6);
L_800A9F34:
    // 0x800A9F34: sll         $t4, $t5, 6
    ctx->r12 = S32(ctx->r13 << 6);
    // 0x800A9F38: sw          $t4, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r12;
    // 0x800A9F3C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800A9F40: addiu       $t6, $t6, 0x6BC8
    ctx->r14 = ADD32(ctx->r14, 0X6BC8);
    // 0x800A9F44: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800A9F48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9F4C: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x800A9F50: nop

    // 0x800A9F54: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A9F58: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A9F5C: nop

    // 0x800A9F60: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A9F64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9F68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9F6C: nop

    // 0x800A9F70: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A9F74: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800A9F78: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A9F7C: sw          $t0, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->r8;
    // 0x800A9F80: nop

    // 0x800A9F84: lw          $t7, 0x1BC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1BC);
    // 0x800A9F88: nop

    // 0x800A9F8C: bgez        $t7, L_800A9F9C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800A9F90: sra         $t8, $t7, 5
        ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
            goto L_800A9F9C;
    }
    // 0x800A9F90: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x800A9F94: addiu       $at, $t7, 0x1F
    ctx->r1 = ADD32(ctx->r15, 0X1F);
    // 0x800A9F98: sra         $t8, $at, 5
    ctx->r24 = S32(SIGNED(ctx->r1) >> 5);
L_800A9F9C:
    // 0x800A9F9C: sll         $t1, $t8, 5
    ctx->r9 = S32(ctx->r24 << 5);
    // 0x800A9FA0: addiu       $t3, $t1, -0x20
    ctx->r11 = ADD32(ctx->r9, -0X20);
    // 0x800A9FA4: sw          $t3, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->r11;
    // 0x800A9FA8: lw          $t2, 0x1DC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9FAC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800A9FB0: lh          $t5, 0x10E($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X10E);
    // 0x800A9FB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9FB8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800A9FBC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A9FC0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9FC4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A9FC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A9FCC: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800A9FD0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800A9FD4: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800A9FD8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A9FDC: nop

    // 0x800A9FE0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A9FE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9FE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9FEC: nop

    // 0x800A9FF0: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A9FF4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A9FF8: swc1        $f4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->f4.u32l;
    // 0x800A9FFC: nop

    // 0x800AA000: sw          $zero, 0x194($sp)
    MEM_W(0X194, ctx->r29) = 0;
L_800AA004:
    // 0x800AA004: lw          $t6, 0x1C0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AA008: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x800AA00C: nop

    // 0x800AA010: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AA014: beq         $at, $zero, L_800AA024
    if (ctx->r1 == 0) {
        // 0x800AA018: nop
    
            goto L_800AA024;
    }
    // 0x800AA018: nop

    // 0x800AA01C: b           L_800ABA20
    // 0x800AA020: nop

        goto L_800ABA20;
    // 0x800AA020: nop

L_800AA024:
    // 0x800AA024: lw          $t0, 0x1C0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AA028: nop

    // 0x800AA02C: bgez        $t0, L_800AA03C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AA030: nop
    
            goto L_800AA03C;
    }
    // 0x800AA030: nop

    // 0x800AA034: b           L_800ABA20
    // 0x800AA038: nop

        goto L_800ABA20;
    // 0x800AA038: nop

L_800AA03C:
    // 0x800AA03C: sw          $zero, 0x188($sp)
    MEM_W(0X188, ctx->r29) = 0;
    // 0x800AA040: lw          $t7, 0x1BC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1BC);
    // 0x800AA044: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800AA048: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x800AA04C: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x800AA050: sw          $t1, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r9;
L_800AA054:
    // 0x800AA054: lw          $t3, 0x1B8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA058: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x800AA05C: nop

    // 0x800AA060: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AA064: beq         $at, $zero, L_800AA074
    if (ctx->r1 == 0) {
        // 0x800AA068: nop
    
            goto L_800AA074;
    }
    // 0x800AA068: nop

    // 0x800AA06C: b           L_800ABA00
    // 0x800AA070: nop

        goto L_800ABA00;
    // 0x800AA070: nop

L_800AA074:
    // 0x800AA074: lw          $t5, 0x1B8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA078: nop

    // 0x800AA07C: bgez        $t5, L_800AA08C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800AA080: nop
    
            goto L_800AA08C;
    }
    // 0x800AA080: nop

    // 0x800AA084: b           L_800ABA00
    // 0x800AA088: nop

        goto L_800ABA00;
    // 0x800AA088: nop

L_800AA08C:
    // 0x800AA08C: lw          $t9, 0x1DC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA090: lw          $t4, 0x1B8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA094: lh          $t0, 0x10C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10C);
    // 0x800AA098: bgez        $t4, L_800AA0A8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800AA09C: sra         $t6, $t4, 8
        ctx->r14 = S32(SIGNED(ctx->r12) >> 8);
            goto L_800AA0A8;
    }
    // 0x800AA09C: sra         $t6, $t4, 8
    ctx->r14 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800AA0A0: addiu       $at, $t4, 0xFF
    ctx->r1 = ADD32(ctx->r12, 0XFF);
    // 0x800AA0A4: sra         $t6, $at, 8
    ctx->r14 = S32(SIGNED(ctx->r1) >> 8);
L_800AA0A8:
    // 0x800AA0A8: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AA0AC: lw          $t8, 0x1C0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AA0B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800AA0B4: bgez        $t8, L_800AA0C4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800AA0B8: sra         $t1, $t8, 6
        ctx->r9 = S32(SIGNED(ctx->r24) >> 6);
            goto L_800AA0C4;
    }
    // 0x800AA0B8: sra         $t1, $t8, 6
    ctx->r9 = S32(SIGNED(ctx->r24) >> 6);
    // 0x800AA0BC: addiu       $at, $t8, 0x3F
    ctx->r1 = ADD32(ctx->r24, 0X3F);
    // 0x800AA0C0: sra         $t1, $at, 6
    ctx->r9 = S32(SIGNED(ctx->r1) >> 6);
L_800AA0C4:
    // 0x800AA0C4: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800AA0C8: sw          $t3, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r11;
    // 0x800AA0CC: lw          $t2, 0x1DC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA0D0: lw          $t4, 0x198($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X198);
    // 0x800AA0D4: lw          $t5, 0x13C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X13C);
    // 0x800AA0D8: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x800AA0DC: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x800AA0E0: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x800AA0E4: lh          $t1, 0x124($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X124);
    // 0x800AA0E8: bgez        $t0, L_800AA0F8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AA0EC: sra         $t8, $t0, 12
        ctx->r24 = S32(SIGNED(ctx->r8) >> 12);
            goto L_800AA0F8;
    }
    // 0x800AA0EC: sra         $t8, $t0, 12
    ctx->r24 = S32(SIGNED(ctx->r8) >> 12);
    // 0x800AA0F0: addiu       $at, $t0, 0xFFF
    ctx->r1 = ADD32(ctx->r8, 0XFFF);
    // 0x800AA0F4: sra         $t8, $at, 12
    ctx->r24 = S32(SIGNED(ctx->r1) >> 12);
L_800AA0F8:
    // 0x800AA0F8: andi        $t7, $t8, 0x7
    ctx->r15 = ctx->r24 & 0X7;
    // 0x800AA0FC: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800AA100: sw          $t3, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r11;
    // 0x800AA104: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x800AA108: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA10C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800AA110: lw          $t5, 0x13C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X13C);
    // 0x800AA114: lw          $t1, 0x1B8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA118: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x800AA11C: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x800AA120: lw          $t0, 0x140($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X140);
    // 0x800AA124: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x800AA128: sll         $t7, $t2, 3
    ctx->r15 = S32(ctx->r10 << 3);
    // 0x800AA12C: bgez        $t1, L_800AA140
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800AA130: andi        $t3, $t1, 0xFF
        ctx->r11 = ctx->r9 & 0XFF;
            goto L_800AA140;
    }
    // 0x800AA130: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x800AA134: beq         $t3, $zero, L_800AA140
    if (ctx->r11 == 0) {
        // 0x800AA138: nop
    
            goto L_800AA140;
    }
    // 0x800AA138: nop

    // 0x800AA13C: addiu       $t3, $t3, -0x100
    ctx->r11 = ADD32(ctx->r11, -0X100);
L_800AA140:
    // 0x800AA140: bgez        $t3, L_800AA150
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AA144: sra         $t9, $t3, 5
        ctx->r25 = S32(SIGNED(ctx->r11) >> 5);
            goto L_800AA150;
    }
    // 0x800AA144: sra         $t9, $t3, 5
    ctx->r25 = S32(SIGNED(ctx->r11) >> 5);
    // 0x800AA148: addiu       $at, $t3, 0x1F
    ctx->r1 = ADD32(ctx->r11, 0X1F);
    // 0x800AA14C: sra         $t9, $at, 5
    ctx->r25 = S32(SIGNED(ctx->r1) >> 5);
L_800AA150:
    // 0x800AA150: addu        $t5, $t7, $t9
    ctx->r13 = ADD32(ctx->r15, ctx->r25);
    // 0x800AA154: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800AA158: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x800AA15C: lhu         $t2, 0x0($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X0);
    // 0x800AA160: nop

    // 0x800AA164: sh          $t2, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r10;
    // 0x800AA168: lw          $t1, 0x1DC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA16C: lhu         $t7, 0x182($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X182);
    // 0x800AA170: lw          $t3, 0x110($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X110);
    // 0x800AA174: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800AA178: bne         $t3, $t9, L_800AA188
    if (ctx->r11 != ctx->r25) {
        // 0x800AA17C: nop
    
            goto L_800AA188;
    }
    // 0x800AA17C: nop

    // 0x800AA180: b           L_800ABA00
    // 0x800AA184: nop

        goto L_800ABA00;
    // 0x800AA184: nop

L_800AA188:
    // 0x800AA188: lw          $t5, 0x1DC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA18C: lw          $t0, 0x198($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X198);
    // 0x800AA190: lw          $t4, 0x13C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X13C);
    // 0x800AA194: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800AA198: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x800AA19C: lhu         $t2, 0x0($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X0);
    // 0x800AA1A0: nop

    // 0x800AA1A4: andi        $t1, $t2, 0x8000
    ctx->r9 = ctx->r10 & 0X8000;
    // 0x800AA1A8: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800AA1AC: lhu         $t3, 0x182($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X182);
    // 0x800AA1B0: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800AA1B4: andi        $t9, $t3, 0x8000
    ctx->r25 = ctx->r11 & 0X8000;
    // 0x800AA1B8: xor         $t5, $t7, $t9
    ctx->r13 = ctx->r15 ^ ctx->r25;
    // 0x800AA1BC: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800AA1C0: lhu         $t0, 0x182($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X182);
    // 0x800AA1C4: lw          $t6, 0x1AC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1AC);
    // 0x800AA1C8: lw          $t1, 0x1DC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA1CC: bgez        $t0, L_800AA1DC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AA1D0: sra         $t4, $t0, 12
        ctx->r12 = S32(SIGNED(ctx->r8) >> 12);
            goto L_800AA1DC;
    }
    // 0x800AA1D0: sra         $t4, $t0, 12
    ctx->r12 = S32(SIGNED(ctx->r8) >> 12);
    // 0x800AA1D4: addiu       $at, $t0, 0xFFF
    ctx->r1 = ADD32(ctx->r8, 0XFFF);
    // 0x800AA1D8: sra         $t4, $at, 12
    ctx->r12 = S32(SIGNED(ctx->r1) >> 12);
L_800AA1DC:
    // 0x800AA1DC: lh          $t3, 0x122($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X122);
    // 0x800AA1E0: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x800AA1E4: andi        $t2, $t8, 0x7
    ctx->r10 = ctx->r24 & 0X7;
    // 0x800AA1E8: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AA1EC: beq         $at, $zero, L_800AA1FC
    if (ctx->r1 == 0) {
        // 0x800AA1F0: nop
    
            goto L_800AA1FC;
    }
    // 0x800AA1F0: nop

    // 0x800AA1F4: b           L_800AA214
    // 0x800AA1F8: sw          $t2, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r10;
        goto L_800AA214;
    // 0x800AA1F8: sw          $t2, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r10;
L_800AA1FC:
    // 0x800AA1FC: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA200: nop

    // 0x800AA204: lh          $t9, 0x122($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X122);
    // 0x800AA208: nop

    // 0x800AA20C: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800AA210: sw          $t5, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r13;
L_800AA214:
    // 0x800AA214: lhu         $t0, 0x182($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X182);
    // 0x800AA218: nop

    // 0x800AA21C: andi        $t4, $t0, 0xFFF
    ctx->r12 = ctx->r8 & 0XFFF;
    // 0x800AA220: sh          $t4, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r12;
    // 0x800AA224: lw          $t6, 0x1B0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1B0);
    // 0x800AA228: lw          $t8, 0x1AC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1AC);
    // 0x800AA22C: nop

    // 0x800AA230: beq         $t6, $t8, L_800AA558
    if (ctx->r14 == ctx->r24) {
        // 0x800AA234: nop
    
            goto L_800AA558;
    }
    // 0x800AA234: nop

    // 0x800AA238: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x800AA23C: nop

    // 0x800AA240: sw          $t1, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r9;
    // 0x800AA244: lw          $t3, 0x1DC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA248: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AA24C: lh          $t2, 0x116($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X116);
    // 0x800AA250: nop

    // 0x800AA254: beq         $t2, $at, L_800AA4FC
    if (ctx->r10 == ctx->r1) {
        // 0x800AA258: nop
    
            goto L_800AA4FC;
    }
    // 0x800AA258: nop

    // 0x800AA25C: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA260: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AA264: lh          $t9, 0x116($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X116);
    // 0x800AA268: nop

    // 0x800AA26C: bne         $t9, $at, L_800AA3A0
    if (ctx->r25 != ctx->r1) {
        // 0x800AA270: nop
    
            goto L_800AA3A0;
    }
    // 0x800AA270: nop

    // 0x800AA274: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA278: nop

    // 0x800AA27C: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800AA280: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800AA284: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800AA288: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x800AA28C: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x800AA290: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800AA294: lw          $t8, 0x1DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA298: lw          $t3, 0x1B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B0);
    // 0x800AA29C: lw          $t1, 0x138($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X138);
    // 0x800AA2A0: sll         $t2, $t3, 8
    ctx->r10 = S32(ctx->r11 << 8);
    // 0x800AA2A4: lw          $t5, 0xF4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF4);
    // 0x800AA2A8: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x800AA2AC: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x800AA2B0: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x800AA2B4: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA2B8: nop

    // 0x800AA2BC: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800AA2C0: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800AA2C4: sw          $t0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r8;
    // 0x800AA2C8: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x800AA2CC: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x800AA2D0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800AA2D4: lw          $t3, 0xF0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF0);
    // 0x800AA2D8: nop

    // 0x800AA2DC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800AA2E0: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA2E4: nop

    // 0x800AA2E8: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x800AA2EC: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800AA2F0: sw          $t2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r10;
    // 0x800AA2F4: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
    // 0x800AA2F8: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x800AA2FC: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x800AA300: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800AA304: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x800AA308: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x800AA30C: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AA310: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA314: nop

    // 0x800AA318: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x800AA31C: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AA320: sw          $t4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r12;
    // 0x800AA324: lw          $t3, 0xE8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE8);
    // 0x800AA328: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800AA32C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800AA330: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x800AA334: nop

    // 0x800AA338: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800AA33C: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA340: nop

    // 0x800AA344: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800AA348: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AA34C: sw          $t1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r9;
    // 0x800AA350: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x800AA354: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x800AA358: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800AA35C: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x800AA360: lui         $t0, 0x73F
    ctx->r8 = S32(0X73F << 16);
    // 0x800AA364: ori         $t0, $t0, 0xC000
    ctx->r8 = ctx->r8 | 0XC000;
    // 0x800AA368: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x800AA36C: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA370: nop

    // 0x800AA374: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x800AA378: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AA37C: sw          $t6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r14;
    // 0x800AA380: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x800AA384: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800AA388: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800AA38C: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x800AA390: nop

    // 0x800AA394: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AA398: b           L_800AA4C4
    // 0x800AA39C: nop

        goto L_800AA4C4;
    // 0x800AA39C: nop

L_800AA3A0:
    // 0x800AA3A0: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA3A4: nop

    // 0x800AA3A8: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800AA3AC: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800AA3B0: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x800AA3B4: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800AA3B8: lui         $t5, 0xFD10
    ctx->r13 = S32(0XFD10 << 16);
    // 0x800AA3BC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AA3C0: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA3C4: lw          $t8, 0x1B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B0);
    // 0x800AA3C8: lw          $t6, 0x138($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X138);
    // 0x800AA3CC: sll         $t3, $t8, 8
    ctx->r11 = S32(ctx->r24 << 8);
    // 0x800AA3D0: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x800AA3D4: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x800AA3D8: addu        $t1, $t6, $t2
    ctx->r9 = ADD32(ctx->r14, ctx->r10);
    // 0x800AA3DC: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x800AA3E0: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA3E4: nop

    // 0x800AA3E8: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800AA3EC: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AA3F0: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
    // 0x800AA3F4: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x800AA3F8: lui         $t0, 0xE800
    ctx->r8 = S32(0XE800 << 16);
    // 0x800AA3FC: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800AA400: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x800AA404: nop

    // 0x800AA408: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800AA40C: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA410: nop

    // 0x800AA414: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800AA418: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AA41C: sw          $t3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r11;
    // 0x800AA420: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x800AA424: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x800AA428: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x800AA42C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800AA430: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x800AA434: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x800AA438: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800AA43C: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA440: nop

    // 0x800AA444: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800AA448: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800AA44C: sw          $t5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r13;
    // 0x800AA450: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800AA454: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800AA458: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x800AA45C: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x800AA460: nop

    // 0x800AA464: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800AA468: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA46C: nop

    // 0x800AA470: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x800AA474: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800AA478: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800AA47C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800AA480: lui         $t1, 0xF000
    ctx->r9 = S32(0XF000 << 16);
    // 0x800AA484: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x800AA488: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800AA48C: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x800AA490: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x800AA494: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x800AA498: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA49C: nop

    // 0x800AA4A0: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800AA4A4: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800AA4A8: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x800AA4AC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800AA4B0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AA4B4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800AA4B8: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800AA4BC: nop

    // 0x800AA4C0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_800AA4C4:
    // 0x800AA4C4: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA4C8: nop

    // 0x800AA4CC: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x800AA4D0: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800AA4D4: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800AA4D8: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800AA4DC: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800AA4E0: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x800AA4E4: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800AA4E8: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800AA4EC: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x800AA4F0: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AA4F4: b           L_800AA52C
    // 0x800AA4F8: nop

        goto L_800AA52C;
    // 0x800AA4F8: nop

L_800AA4FC:
    // 0x800AA4FC: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA500: nop

    // 0x800AA504: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800AA508: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AA50C: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800AA510: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800AA514: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800AA518: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x800AA51C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AA520: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x800AA524: nop

    // 0x800AA528: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_800AA52C:
    // 0x800AA52C: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA530: nop

    // 0x800AA534: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800AA538: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AA53C: sw          $t1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r9;
    // 0x800AA540: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x800AA544: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800AA548: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800AA54C: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800AA550: nop

    // 0x800AA554: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800AA558:
    // 0x800AA558: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800AA55C: nop

    // 0x800AA560: bne         $t4, $zero, L_800AAFBC
    if (ctx->r12 != 0) {
        // 0x800AA564: nop
    
            goto L_800AAFBC;
    }
    // 0x800AA564: nop

    // 0x800AA568: lw          $t8, 0x1C0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AA56C: lw          $t3, 0x1A0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A0);
    // 0x800AA570: nop

    // 0x800AA574: subu        $t6, $t8, $t3
    ctx->r14 = SUB32(ctx->r24, ctx->r11);
    // 0x800AA578: sw          $t6, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r14;
    // 0x800AA57C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800AA580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA584: nop

    // 0x800AA588: swc1        $f10, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->f10.u32l;
    // 0x800AA58C: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800AA590: lw          $t1, 0x1B8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA594: nop

    // 0x800AA598: subu        $t7, $t2, $t1
    ctx->r15 = SUB32(ctx->r10, ctx->r9);
    // 0x800AA59C: sw          $t7, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r15;
    // 0x800AA5A0: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AA5A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA5A8: nop

    // 0x800AA5AC: swc1        $f18, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->f18.u32l;
    // 0x800AA5B0: lw          $t9, 0x1D0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D0);
    // 0x800AA5B4: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AA5B8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800AA5BC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800AA5C0: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AA5C4: lwc1        $f16, 0x1E0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1E0);
    // 0x800AA5C8: lwc1        $f10, 0x144($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800AA5CC: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AA5D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA5D4: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AA5D8: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AA5DC: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800AA5E0: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
    // 0x800AA5E4: lwc1        $f10, 0x1A8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800AA5E8: lwc1        $f16, 0x14C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AA5EC: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA5F0: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AA5F4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800AA5F8: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
    // 0x800AA5FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AA600: nop

    // 0x800AA604: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
    // 0x800AA608: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA60C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800AA610: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AA614: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800AA618: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x800AA61C: nop

    // 0x800AA620: bc1f        L_800AA64C
    if (!c1cs) {
        // 0x800AA624: nop
    
            goto L_800AA64C;
    }
    // 0x800AA624: nop

    // 0x800AA628: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA62C: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AA630: nop

    // 0x800AA634: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AA638: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800AA63C: swc1        $f10, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f10.u32l;
    // 0x800AA640: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AA644: b           L_800AA6A0
    // 0x800AA648: swc1        $f16, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f16.u32l;
        goto L_800AA6A0;
    // 0x800AA648: swc1        $f16, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f16.u32l;
L_800AA64C:
    // 0x800AA64C: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA650: lui         $at, 0x4074
    ctx->r1 = S32(0X4074 << 16);
    // 0x800AA654: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800AA658: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AA65C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800AA660: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x800AA664: nop

    // 0x800AA668: bc1f        L_800AA6A0
    if (!c1cs) {
        // 0x800AA66C: nop
    
            goto L_800AA6A0;
    }
    // 0x800AA66C: nop

    // 0x800AA670: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AA674: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA678: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA67C: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AA680: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800AA684: nop

    // 0x800AA688: div.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AA68C: swc1        $f18, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f18.u32l;
    // 0x800AA690: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AA694: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA698: nop

    // 0x800AA69C: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
L_800AA6A0:
    // 0x800AA6A0: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AA6A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AA6A8: nop

    // 0x800AA6AC: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800AA6B0: nop

    // 0x800AA6B4: bc1f        L_800AA6C8
    if (!c1cs) {
        // 0x800AA6B8: nop
    
            goto L_800AA6C8;
    }
    // 0x800AA6B8: nop

    // 0x800AA6BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AA6C0: b           L_800AA6F8
    // 0x800AA6C4: swc1        $f16, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f16.u32l;
        goto L_800AA6F8;
    // 0x800AA6C4: swc1        $f16, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f16.u32l;
L_800AA6C8:
    // 0x800AA6C8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AA6CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA6D0: lwc1        $f6, 0x164($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AA6D4: nop

    // 0x800AA6D8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800AA6DC: nop

    // 0x800AA6E0: bc1f        L_800AA6F8
    if (!c1cs) {
        // 0x800AA6E4: nop
    
            goto L_800AA6F8;
    }
    // 0x800AA6E4: nop

    // 0x800AA6E8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AA6EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA6F0: nop

    // 0x800AA6F4: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
L_800AA6F8:
    // 0x800AA6F8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA6FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA700: lwc1        $f4, 0x16C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA704: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800AA708: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AA70C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AA710: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AA714: nop

    // 0x800AA718: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AA71C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AA720: nop

    // 0x800AA724: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x800AA728: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800AA72C: beq         $t0, $zero, L_800AA780
    if (ctx->r8 == 0) {
        // 0x800AA730: nop
    
            goto L_800AA780;
    }
    // 0x800AA730: nop

    // 0x800AA734: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AA738: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA73C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800AA740: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AA744: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AA748: nop

    // 0x800AA74C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AA750: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AA754: nop

    // 0x800AA758: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x800AA75C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800AA760: bne         $t0, $zero, L_800AA778
    if (ctx->r8 != 0) {
        // 0x800AA764: nop
    
            goto L_800AA778;
    }
    // 0x800AA764: nop

    // 0x800AA768: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800AA76C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA770: b           L_800AA790
    // 0x800AA774: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800AA790;
    // 0x800AA774: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800AA778:
    // 0x800AA778: b           L_800AA790
    // 0x800AA77C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800AA790;
    // 0x800AA77C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800AA780:
    // 0x800AA780: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800AA784: nop

    // 0x800AA788: bltz        $t0, L_800AA778
    if (SIGNED(ctx->r8) < 0) {
        // 0x800AA78C: nop
    
            goto L_800AA778;
    }
    // 0x800AA78C: nop

L_800AA790:
    // 0x800AA790: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AA794: sw          $t0, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r8;
    // 0x800AA798: nop

    // 0x800AA79C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA7A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA7A4: lwc1        $f18, 0x164($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AA7A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AA7AC: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AA7B0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AA7B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AA7B8: nop

    // 0x800AA7BC: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AA7C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AA7C4: nop

    // 0x800AA7C8: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800AA7CC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800AA7D0: beq         $t8, $zero, L_800AA824
    if (ctx->r24 == 0) {
        // 0x800AA7D4: nop
    
            goto L_800AA824;
    }
    // 0x800AA7D4: nop

    // 0x800AA7D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AA7DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA7E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AA7E4: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800AA7E8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AA7EC: nop

    // 0x800AA7F0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AA7F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AA7F8: nop

    // 0x800AA7FC: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800AA800: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800AA804: bne         $t8, $zero, L_800AA81C
    if (ctx->r24 != 0) {
        // 0x800AA808: nop
    
            goto L_800AA81C;
    }
    // 0x800AA808: nop

    // 0x800AA80C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800AA810: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA814: b           L_800AA834
    // 0x800AA818: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800AA834;
    // 0x800AA818: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800AA81C:
    // 0x800AA81C: b           L_800AA834
    // 0x800AA820: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800AA834;
    // 0x800AA820: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800AA824:
    // 0x800AA824: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800AA828: nop

    // 0x800AA82C: bltz        $t8, L_800AA81C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800AA830: nop
    
            goto L_800AA81C;
    }
    // 0x800AA830: nop

L_800AA834:
    // 0x800AA834: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AA838: sw          $t8, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r24;
    // 0x800AA83C: nop

    // 0x800AA840: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AA844: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA848: lwc1        $f16, 0x158($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X158);
    // 0x800AA84C: nop

    // 0x800AA850: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AA854: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AA858: nop

    // 0x800AA85C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AA860: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA864: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA868: nop

    // 0x800AA86C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AA870: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AA874: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AA878: sh          $t6, 0x15E($sp)
    MEM_H(0X15E, ctx->r29) = ctx->r14;
    // 0x800AA87C: nop

    // 0x800AA880: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800AA884: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x800AA888: nop

    // 0x800AA88C: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
    // 0x800AA890: beq         $at, $zero, L_800AAFB4
    if (ctx->r1 == 0) {
        // 0x800AA894: nop
    
            goto L_800AAFB4;
    }
    // 0x800AA894: nop

    // 0x800AA898: lw          $t7, 0x1CC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1CC);
    // 0x800AA89C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800AA8A0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800AA8A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA8A8: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AA8AC: lwc1        $f10, 0x1E4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1E4);
    // 0x800AA8B0: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AA8B4: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800AA8B8: lwc1        $f10, 0x140($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800AA8BC: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AA8C0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AA8C4: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AA8C8: swc1        $f18, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f18.u32l;
    // 0x800AA8CC: lwc1        $f8, 0x1A4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x800AA8D0: lwc1        $f4, 0x148($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AA8D4: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA8D8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AA8DC: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AA8E0: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x800AA8E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AA8E8: nop

    // 0x800AA8EC: swc1        $f18, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f18.u32l;
    // 0x800AA8F0: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA8F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AA8F8: nop

    // 0x800AA8FC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800AA900: nop

    // 0x800AA904: bc1f        L_800AA930
    if (!c1cs) {
        // 0x800AA908: nop
    
            goto L_800AA930;
    }
    // 0x800AA908: nop

    // 0x800AA90C: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA910: lwc1        $f6, 0x148($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AA914: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800AA918: nop

    // 0x800AA91C: div.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AA920: swc1        $f18, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f18.u32l;
    // 0x800AA924: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AA928: b           L_800AA980
    // 0x800AA92C: swc1        $f8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f8.u32l;
        goto L_800AA980;
    // 0x800AA92C: swc1        $f8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f8.u32l;
L_800AA930:
    // 0x800AA930: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA934: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA938: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA93C: nop

    // 0x800AA940: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800AA944: nop

    // 0x800AA948: bc1f        L_800AA980
    if (!c1cs) {
        // 0x800AA94C: nop
    
            goto L_800AA980;
    }
    // 0x800AA94C: nop

    // 0x800AA950: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA954: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA958: lwc1        $f6, 0x168($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA95C: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AA960: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AA964: nop

    // 0x800AA968: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AA96C: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
    // 0x800AA970: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA974: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA978: nop

    // 0x800AA97C: swc1        $f10, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f10.u32l;
L_800AA980:
    // 0x800AA980: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AA984: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AA988: nop

    // 0x800AA98C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800AA990: nop

    // 0x800AA994: bc1f        L_800AA9A8
    if (!c1cs) {
        // 0x800AA998: nop
    
            goto L_800AA9A8;
    }
    // 0x800AA998: nop

    // 0x800AA99C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AA9A0: b           L_800AA9D8
    // 0x800AA9A4: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
        goto L_800AA9D8;
    // 0x800AA9A4: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
L_800AA9A8:
    // 0x800AA9A8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA9AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA9B0: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AA9B4: nop

    // 0x800AA9B8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800AA9BC: nop

    // 0x800AA9C0: bc1f        L_800AA9D8
    if (!c1cs) {
        // 0x800AA9C4: nop
    
            goto L_800AA9D8;
    }
    // 0x800AA9C4: nop

    // 0x800AA9C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA9CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA9D0: nop

    // 0x800AA9D4: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_800AA9D8:
    // 0x800AA9D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA9DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA9E0: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA9E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AA9E8: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AA9EC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AA9F0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AA9F4: nop

    // 0x800AA9F8: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AA9FC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AAA00: nop

    // 0x800AAA04: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800AAA08: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800AAA0C: beq         $t5, $zero, L_800AAA60
    if (ctx->r13 == 0) {
        // 0x800AAA10: nop
    
            goto L_800AAA60;
    }
    // 0x800AAA10: nop

    // 0x800AAA14: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AAA18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AAA1C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AAA20: sub.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800AAA24: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AAA28: nop

    // 0x800AAA2C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AAA30: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AAA34: nop

    // 0x800AAA38: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800AAA3C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800AAA40: bne         $t5, $zero, L_800AAA58
    if (ctx->r13 != 0) {
        // 0x800AAA44: nop
    
            goto L_800AAA58;
    }
    // 0x800AAA44: nop

    // 0x800AAA48: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800AAA4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AAA50: b           L_800AAA70
    // 0x800AAA54: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800AAA70;
    // 0x800AAA54: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800AAA58:
    // 0x800AAA58: b           L_800AAA70
    // 0x800AAA5C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800AAA70;
    // 0x800AAA5C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_800AAA60:
    // 0x800AAA60: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800AAA64: nop

    // 0x800AAA68: bltz        $t5, L_800AAA58
    if (SIGNED(ctx->r13) < 0) {
        // 0x800AAA6C: nop
    
            goto L_800AAA58;
    }
    // 0x800AAA6C: nop

L_800AAA70:
    // 0x800AAA70: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AAA74: sw          $t5, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r13;
    // 0x800AAA78: nop

    // 0x800AAA7C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AAA80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AAA84: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AAA88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800AAA8C: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AAA90: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AAA94: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AAA98: nop

    // 0x800AAA9C: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AAAA0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AAAA4: nop

    // 0x800AAAA8: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800AAAAC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800AAAB0: beq         $t4, $zero, L_800AAB04
    if (ctx->r12 == 0) {
        // 0x800AAAB4: nop
    
            goto L_800AAB04;
    }
    // 0x800AAAB4: nop

    // 0x800AAAB8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AAABC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AAAC0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800AAAC4: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AAAC8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AAACC: nop

    // 0x800AAAD0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AAAD4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AAAD8: nop

    // 0x800AAADC: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800AAAE0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800AAAE4: bne         $t4, $zero, L_800AAAFC
    if (ctx->r12 != 0) {
        // 0x800AAAE8: nop
    
            goto L_800AAAFC;
    }
    // 0x800AAAE8: nop

    // 0x800AAAEC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800AAAF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AAAF4: b           L_800AAB14
    // 0x800AAAF8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800AAB14;
    // 0x800AAAF8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800AAAFC:
    // 0x800AAAFC: b           L_800AAB14
    // 0x800AAB00: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800AAB14;
    // 0x800AAB00: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800AAB04:
    // 0x800AAB04: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800AAB08: nop

    // 0x800AAB0C: bltz        $t4, L_800AAAFC
    if (SIGNED(ctx->r12) < 0) {
        // 0x800AAB10: nop
    
            goto L_800AAAFC;
    }
    // 0x800AAB10: nop

L_800AAB14:
    // 0x800AAB14: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AAB18: sw          $t4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r12;
    // 0x800AAB1C: nop

    // 0x800AAB20: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AAB24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AAB28: lwc1        $f18, 0x154($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800AAB2C: nop

    // 0x800AAB30: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AAB34: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AAB38: nop

    // 0x800AAB3C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AAB40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAB44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAB48: nop

    // 0x800AAB4C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AAB50: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800AAB54: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AAB58: sh          $t3, 0x15C($sp)
    MEM_H(0X15C, ctx->r29) = ctx->r11;
    // 0x800AAB5C: nop

    // 0x800AAB60: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x800AAB64: lw          $t2, 0x170($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X170);
    // 0x800AAB68: nop

    // 0x800AAB6C: sltu        $at, $t6, $t2
    ctx->r1 = ctx->r14 < ctx->r10 ? 1 : 0;
    // 0x800AAB70: bne         $at, $zero, L_800AABAC
    if (ctx->r1 != 0) {
        // 0x800AAB74: nop
    
            goto L_800AABAC;
    }
    // 0x800AAB74: nop

    // 0x800AAB78: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAB7C: nop

    // 0x800AAB80: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800AAB84: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AAB88: sw          $t1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r9;
    // 0x800AAB8C: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800AAB90: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800AAB94: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800AAB98: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800AAB9C: nop

    // 0x800AABA0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800AABA4: b           L_800AAFB4
    // 0x800AABA8: nop

        goto L_800AAFB4;
    // 0x800AABA8: nop

L_800AABAC:
    // 0x800AABAC: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AABB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AABB4: lh          $t8, 0x116($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X116);
    // 0x800AABB8: nop

    // 0x800AABBC: bne         $t8, $at, L_800AAD34
    if (ctx->r24 != ctx->r1) {
        // 0x800AABC0: nop
    
            goto L_800AAD34;
    }
    // 0x800AABC0: nop

    // 0x800AABC4: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AABC8: nop

    // 0x800AABCC: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800AABD0: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AABD4: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x800AABD8: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x800AABDC: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x800AABE0: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800AABE4: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AABE8: lhu         $t5, 0x182($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X182);
    // 0x800AABEC: lw          $t9, 0x128($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X128);
    // 0x800AABF0: sll         $t0, $t5, 6
    ctx->r8 = S32(ctx->r13 << 6);
    // 0x800AABF4: sll         $t4, $t0, 5
    ctx->r12 = S32(ctx->r8 << 5);
    // 0x800AABF8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800AABFC: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x800AAC00: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800AAC04: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x800AAC08: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x800AAC0C: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800AAC10: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAC14: nop

    // 0x800AAC18: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x800AAC1C: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800AAC20: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x800AAC24: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x800AAC28: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x800AAC2C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AAC30: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x800AAC34: lui         $t0, 0x709
    ctx->r8 = S32(0X709 << 16);
    // 0x800AAC38: ori         $t0, $t0, 0x4160
    ctx->r8 = ctx->r8 | 0X4160;
    // 0x800AAC3C: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800AAC40: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAC44: nop

    // 0x800AAC48: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800AAC4C: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AAC50: sw          $t4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r12;
    // 0x800AAC54: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800AAC58: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x800AAC5C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AAC60: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800AAC64: nop

    // 0x800AAC68: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800AAC6C: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAC70: nop

    // 0x800AAC74: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800AAC78: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AAC7C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800AAC80: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x800AAC84: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x800AAC88: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AAC8C: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x800AAC90: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x800AAC94: ori         $t9, $t9, 0xF100
    ctx->r25 = ctx->r25 | 0XF100;
    // 0x800AAC98: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x800AAC9C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AACA0: nop

    // 0x800AACA4: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x800AACA8: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800AACAC: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x800AACB0: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x800AACB4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800AACB8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800AACBC: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x800AACC0: nop

    // 0x800AACC4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AACC8: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AACCC: nop

    // 0x800AACD0: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AACD4: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AACD8: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x800AACDC: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800AACE0: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x800AACE4: ori         $t0, $t0, 0x1000
    ctx->r8 = ctx->r8 | 0X1000;
    // 0x800AACE8: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800AACEC: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800AACF0: lui         $t4, 0x9
    ctx->r12 = S32(0X9 << 16);
    // 0x800AACF4: ori         $t4, $t4, 0x4160
    ctx->r12 = ctx->r12 | 0X4160;
    // 0x800AACF8: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x800AACFC: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAD00: nop

    // 0x800AAD04: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800AAD08: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AAD0C: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x800AAD10: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x800AAD14: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x800AAD18: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800AAD1C: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x800AAD20: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x800AAD24: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x800AAD28: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800AAD2C: b           L_800AAEAC
    // 0x800AAD30: nop

        goto L_800AAEAC;
    // 0x800AAD30: nop

L_800AAD34:
    // 0x800AAD34: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AAD38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AAD3C: lh          $t9, 0x116($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X116);
    // 0x800AAD40: nop

    // 0x800AAD44: bne         $t9, $at, L_800AAEAC
    if (ctx->r25 != ctx->r1) {
        // 0x800AAD48: nop
    
            goto L_800AAEAC;
    }
    // 0x800AAD48: nop

    // 0x800AAD4C: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAD50: nop

    // 0x800AAD54: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800AAD58: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AAD5C: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x800AAD60: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800AAD64: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x800AAD68: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AAD6C: lhu         $t7, 0x182($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X182);
    // 0x800AAD70: lw          $t2, 0x1DC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AAD74: sll         $t5, $t7, 6
    ctx->r13 = S32(ctx->r15 << 6);
    // 0x800AAD78: lw          $t1, 0x128($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X128);
    // 0x800AAD7C: sll         $t0, $t5, 5
    ctx->r8 = S32(ctx->r13 << 5);
    // 0x800AAD80: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800AAD84: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x800AAD88: addu        $t4, $t1, $t9
    ctx->r12 = ADD32(ctx->r9, ctx->r25);
    // 0x800AAD8C: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x800AAD90: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAD94: nop

    // 0x800AAD98: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800AAD9C: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AADA0: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x800AADA4: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x800AADA8: lui         $t2, 0xF510
    ctx->r10 = S32(0XF510 << 16);
    // 0x800AADAC: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800AADB0: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800AADB4: lui         $t5, 0x705
    ctx->r13 = S32(0X705 << 16);
    // 0x800AADB8: ori         $t5, $t5, 0x4160
    ctx->r13 = ctx->r13 | 0X4160;
    // 0x800AADBC: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AADC0: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AADC4: nop

    // 0x800AADC8: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x800AADCC: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800AADD0: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800AADD4: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800AADD8: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800AADDC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x800AADE0: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800AADE4: nop

    // 0x800AADE8: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800AADEC: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AADF0: nop

    // 0x800AADF4: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x800AADF8: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800AADFC: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x800AAE00: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x800AAE04: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800AAE08: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AAE0C: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800AAE10: lui         $t0, 0x77F
    ctx->r8 = S32(0X77F << 16);
    // 0x800AAE14: ori         $t0, $t0, 0xF080
    ctx->r8 = ctx->r8 | 0XF080;
    // 0x800AAE18: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800AAE1C: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAE20: nop

    // 0x800AAE24: addiu       $t4, $t9, 0x8
    ctx->r12 = ADD32(ctx->r25, 0X8);
    // 0x800AAE28: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800AAE2C: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x800AAE30: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800AAE34: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AAE38: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800AAE3C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800AAE40: nop

    // 0x800AAE44: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800AAE48: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAE4C: nop

    // 0x800AAE50: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AAE54: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AAE58: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x800AAE5C: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800AAE60: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x800AAE64: ori         $t5, $t5, 0x2000
    ctx->r13 = ctx->r13 | 0X2000;
    // 0x800AAE68: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AAE6C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x800AAE70: lui         $t1, 0x5
    ctx->r9 = S32(0X5 << 16);
    // 0x800AAE74: ori         $t1, $t1, 0x4160
    ctx->r9 = ctx->r9 | 0X4160;
    // 0x800AAE78: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800AAE7C: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAE80: nop

    // 0x800AAE84: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800AAE88: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AAE8C: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x800AAE90: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800AAE94: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x800AAE98: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AAE9C: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800AAEA0: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800AAEA4: ori         $t2, $t2, 0xC07C
    ctx->r10 = ctx->r10 | 0XC07C;
    // 0x800AAEA8: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
L_800AAEAC:
    // 0x800AAEAC: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAEB0: nop

    // 0x800AAEB4: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800AAEB8: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800AAEBC: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800AAEC0: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x800AAEC4: lw          $t3, 0x170($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X170);
    // 0x800AAEC8: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800AAECC: sll         $t4, $t9, 12
    ctx->r12 = S32(ctx->r25 << 12);
    // 0x800AAED0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800AAED4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800AAED8: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x800AAEDC: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x800AAEE0: or          $t2, $t8, $t6
    ctx->r10 = ctx->r24 | ctx->r14;
    // 0x800AAEE4: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800AAEE8: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800AAEEC: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x800AAEF0: andi        $t0, $t5, 0xFFF
    ctx->r8 = ctx->r13 & 0XFFF;
    // 0x800AAEF4: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800AAEF8: sll         $t1, $t0, 12
    ctx->r9 = S32(ctx->r8 << 12);
    // 0x800AAEFC: andi        $t4, $t9, 0xFFF
    ctx->r12 = ctx->r25 & 0XFFF;
    // 0x800AAF00: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x800AAF04: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x800AAF08: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAF0C: nop

    // 0x800AAF10: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x800AAF14: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800AAF18: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x800AAF1C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800AAF20: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x800AAF24: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AAF28: lh          $t0, 0x15E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X15E);
    // 0x800AAF2C: lh          $t4, 0x15C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X15C);
    // 0x800AAF30: andi        $t9, $t0, 0xFFFF
    ctx->r25 = ctx->r8 & 0XFFFF;
    // 0x800AAF34: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800AAF38: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x800AAF3C: andi        $t3, $t4, 0xFFFF
    ctx->r11 = ctx->r12 & 0XFFFF;
    // 0x800AAF40: or          $t8, $t1, $t3
    ctx->r24 = ctx->r9 | ctx->r11;
    // 0x800AAF44: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800AAF48: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAF4C: nop

    // 0x800AAF50: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AAF54: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AAF58: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x800AAF5C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800AAF60: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x800AAF64: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AAF68: lh          $t9, 0x152($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X152);
    // 0x800AAF6C: lh          $t3, 0x150($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X150);
    // 0x800AAF70: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800AAF74: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800AAF78: sll         $t1, $t4, 16
    ctx->r9 = S32(ctx->r12 << 16);
    // 0x800AAF7C: andi        $t8, $t3, 0xFFFF
    ctx->r24 = ctx->r11 & 0XFFFF;
    // 0x800AAF80: or          $t6, $t1, $t8
    ctx->r14 = ctx->r9 | ctx->r24;
    // 0x800AAF84: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x800AAF88: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAF8C: nop

    // 0x800AAF90: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AAF94: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AAF98: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x800AAF9C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800AAFA0: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800AAFA4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800AAFA8: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800AAFAC: nop

    // 0x800AAFB0: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
L_800AAFB4:
    // 0x800AAFB4: b           L_800ABA00
    // 0x800AAFB8: nop

        goto L_800ABA00;
    // 0x800AAFB8: nop

L_800AAFBC:
    // 0x800AAFBC: lw          $t3, 0x1C0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AAFC0: lw          $t1, 0x1A0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A0);
    // 0x800AAFC4: nop

    // 0x800AAFC8: subu        $t8, $t3, $t1
    ctx->r24 = SUB32(ctx->r11, ctx->r9);
    // 0x800AAFCC: sw          $t8, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r24;
    // 0x800AAFD0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800AAFD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AAFD8: nop

    // 0x800AAFDC: swc1        $f16, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->f16.u32l;
    // 0x800AAFE0: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800AAFE4: lw          $t2, 0x1B8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AAFE8: nop

    // 0x800AAFEC: subu        $t7, $t6, $t2
    ctx->r15 = SUB32(ctx->r14, ctx->r10);
    // 0x800AAFF0: sw          $t7, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r15;
    // 0x800AAFF4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AAFF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AAFFC: nop

    // 0x800AB000: swc1        $f6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->f6.u32l;
    // 0x800AB004: lw          $t5, 0x1D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D0);
    // 0x800AB008: lwc1        $f4, 0x14C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AB00C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800AB010: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800AB014: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AB018: lwc1        $f18, 0x1E0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1E0);
    // 0x800AB01C: lwc1        $f16, 0x144($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800AB020: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AB024: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AB028: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AB02C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800AB030: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AB034: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
    // 0x800AB038: lwc1        $f16, 0x1A8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800AB03C: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AB040: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB044: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AB048: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AB04C: swc1        $f4, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f4.u32l;
    // 0x800AB050: lwc1        $f10, 0x1A8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800AB054: nop

    // 0x800AB058: swc1        $f10, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f10.u32l;
    // 0x800AB05C: lwc1        $f16, 0x16C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB060: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800AB064: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AB068: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AB06C: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x800AB070: nop

    // 0x800AB074: bc1f        L_800AB0A0
    if (!c1cs) {
        // 0x800AB078: nop
    
            goto L_800AB0A0;
    }
    // 0x800AB078: nop

    // 0x800AB07C: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB080: lwc1        $f4, 0x14C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AB084: lwc1        $f16, 0x1A8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800AB088: div.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AB08C: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800AB090: swc1        $f18, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f18.u32l;
    // 0x800AB094: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AB098: b           L_800AB0F4
    // 0x800AB09C: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
        goto L_800AB0F4;
    // 0x800AB09C: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
L_800AB0A0:
    // 0x800AB0A0: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB0A4: lui         $at, 0x4074
    ctx->r1 = S32(0X4074 << 16);
    // 0x800AB0A8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800AB0AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AB0B0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800AB0B4: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x800AB0B8: nop

    // 0x800AB0BC: bc1f        L_800AB0F4
    if (!c1cs) {
        // 0x800AB0C0: nop
    
            goto L_800AB0F4;
    }
    // 0x800AB0C0: nop

    // 0x800AB0C4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AB0C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AB0CC: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB0D0: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AB0D4: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AB0D8: nop

    // 0x800AB0DC: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AB0E0: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
    // 0x800AB0E4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AB0E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB0EC: nop

    // 0x800AB0F0: swc1        $f16, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f16.u32l;
L_800AB0F4:
    // 0x800AB0F4: lwc1        $f10, 0x164($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AB0F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AB0FC: nop

    // 0x800AB100: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800AB104: nop

    // 0x800AB108: bc1f        L_800AB11C
    if (!c1cs) {
        // 0x800AB10C: nop
    
            goto L_800AB11C;
    }
    // 0x800AB10C: nop

    // 0x800AB110: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AB114: b           L_800AB14C
    // 0x800AB118: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
        goto L_800AB14C;
    // 0x800AB118: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
L_800AB11C:
    // 0x800AB11C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AB120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB124: lwc1        $f6, 0x164($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AB128: nop

    // 0x800AB12C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800AB130: nop

    // 0x800AB134: bc1f        L_800AB14C
    if (!c1cs) {
        // 0x800AB138: nop
    
            goto L_800AB14C;
    }
    // 0x800AB138: nop

    // 0x800AB13C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AB140: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB144: nop

    // 0x800AB148: swc1        $f16, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f16.u32l;
L_800AB14C:
    // 0x800AB14C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AB150: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB154: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB158: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB15C: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AB160: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AB164: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AB168: nop

    // 0x800AB16C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AB170: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AB174: nop

    // 0x800AB178: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800AB17C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AB180: beq         $t9, $zero, L_800AB1D4
    if (ctx->r25 == 0) {
        // 0x800AB184: nop
    
            goto L_800AB1D4;
    }
    // 0x800AB184: nop

    // 0x800AB188: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AB18C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AB190: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB194: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AB198: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AB19C: nop

    // 0x800AB1A0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AB1A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AB1A8: nop

    // 0x800AB1AC: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800AB1B0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AB1B4: bne         $t9, $zero, L_800AB1CC
    if (ctx->r25 != 0) {
        // 0x800AB1B8: nop
    
            goto L_800AB1CC;
    }
    // 0x800AB1B8: nop

    // 0x800AB1BC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800AB1C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AB1C4: b           L_800AB1E4
    // 0x800AB1C8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800AB1E4;
    // 0x800AB1C8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800AB1CC:
    // 0x800AB1CC: b           L_800AB1E4
    // 0x800AB1D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800AB1E4;
    // 0x800AB1D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800AB1D4:
    // 0x800AB1D4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800AB1D8: nop

    // 0x800AB1DC: bltz        $t9, L_800AB1CC
    if (SIGNED(ctx->r25) < 0) {
        // 0x800AB1E0: nop
    
            goto L_800AB1CC;
    }
    // 0x800AB1E0: nop

L_800AB1E4:
    // 0x800AB1E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AB1E8: sw          $t9, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r25;
    // 0x800AB1EC: nop

    // 0x800AB1F0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AB1F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB1F8: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AB1FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB200: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AB204: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AB208: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB20C: nop

    // 0x800AB210: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AB214: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB218: nop

    // 0x800AB21C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800AB220: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AB224: beq         $t3, $zero, L_800AB278
    if (ctx->r11 == 0) {
        // 0x800AB228: nop
    
            goto L_800AB278;
    }
    // 0x800AB228: nop

    // 0x800AB22C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AB230: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB234: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB238: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AB23C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB240: nop

    // 0x800AB244: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AB248: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB24C: nop

    // 0x800AB250: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800AB254: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AB258: bne         $t3, $zero, L_800AB270
    if (ctx->r11 != 0) {
        // 0x800AB25C: nop
    
            goto L_800AB270;
    }
    // 0x800AB25C: nop

    // 0x800AB260: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800AB264: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AB268: b           L_800AB288
    // 0x800AB26C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800AB288;
    // 0x800AB26C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800AB270:
    // 0x800AB270: b           L_800AB288
    // 0x800AB274: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800AB288;
    // 0x800AB274: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800AB278:
    // 0x800AB278: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800AB27C: nop

    // 0x800AB280: bltz        $t3, L_800AB270
    if (SIGNED(ctx->r11) < 0) {
        // 0x800AB284: nop
    
            goto L_800AB270;
    }
    // 0x800AB284: nop

L_800AB288:
    // 0x800AB288: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AB28C: sw          $t3, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r11;
    // 0x800AB290: nop

    // 0x800AB294: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AB298: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AB29C: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x800AB2A0: nop

    // 0x800AB2A4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AB2A8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AB2AC: nop

    // 0x800AB2B0: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AB2B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB2B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB2BC: nop

    // 0x800AB2C0: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AB2C4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800AB2C8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AB2CC: sh          $t8, 0x15E($sp)
    MEM_H(0X15E, ctx->r29) = ctx->r24;
    // 0x800AB2D0: nop

    // 0x800AB2D4: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x800AB2D8: lw          $t2, 0x174($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X174);
    // 0x800AB2DC: nop

    // 0x800AB2E0: sltu        $at, $t6, $t2
    ctx->r1 = ctx->r14 < ctx->r10 ? 1 : 0;
    // 0x800AB2E4: beq         $at, $zero, L_800ABA00
    if (ctx->r1 == 0) {
        // 0x800AB2E8: nop
    
            goto L_800ABA00;
    }
    // 0x800AB2E8: nop

    // 0x800AB2EC: lw          $t7, 0x1CC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1CC);
    // 0x800AB2F0: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AB2F4: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800AB2F8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AB2FC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800AB300: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AB304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AB308: lwc1        $f4, 0x140($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800AB30C: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AB310: lwc1        $f18, 0x1E4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1E4);
    // 0x800AB314: sub.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AB318: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AB31C: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AB320: swc1        $f6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f6.u32l;
    // 0x800AB324: lwc1        $f4, 0x1A4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x800AB328: lwc1        $f10, 0x148($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AB32C: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB330: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AB334: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AB338: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
    // 0x800AB33C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AB340: nop

    // 0x800AB344: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x800AB348: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB34C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AB350: nop

    // 0x800AB354: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800AB358: nop

    // 0x800AB35C: bc1f        L_800AB388
    if (!c1cs) {
        // 0x800AB360: nop
    
            goto L_800AB388;
    }
    // 0x800AB360: nop

    // 0x800AB364: lwc1        $f18, 0x168($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB368: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AB36C: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
    // 0x800AB370: nop

    // 0x800AB374: div.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AB378: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x800AB37C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AB380: b           L_800AB3D8
    // 0x800AB384: swc1        $f4, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f4.u32l;
        goto L_800AB3D8;
    // 0x800AB384: swc1        $f4, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f4.u32l;
L_800AB388:
    // 0x800AB388: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB38C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB390: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB394: nop

    // 0x800AB398: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800AB39C: nop

    // 0x800AB3A0: bc1f        L_800AB3D8
    if (!c1cs) {
        // 0x800AB3A4: nop
    
            goto L_800AB3D8;
    }
    // 0x800AB3A4: nop

    // 0x800AB3A8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB3AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB3B0: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB3B4: lwc1        $f4, 0x148($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AB3B8: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800AB3BC: nop

    // 0x800AB3C0: div.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AB3C4: swc1        $f10, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f10.u32l;
    // 0x800AB3C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB3CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB3D0: nop

    // 0x800AB3D4: swc1        $f18, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f18.u32l;
L_800AB3D8:
    // 0x800AB3D8: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AB3DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AB3E0: nop

    // 0x800AB3E4: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800AB3E8: nop

    // 0x800AB3EC: bc1f        L_800AB400
    if (!c1cs) {
        // 0x800AB3F0: nop
    
            goto L_800AB400;
    }
    // 0x800AB3F0: nop

    // 0x800AB3F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AB3F8: b           L_800AB430
    // 0x800AB3FC: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
        goto L_800AB430;
    // 0x800AB3FC: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
L_800AB400:
    // 0x800AB400: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB404: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AB408: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AB40C: nop

    // 0x800AB410: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800AB414: nop

    // 0x800AB418: bc1f        L_800AB430
    if (!c1cs) {
        // 0x800AB41C: nop
    
            goto L_800AB430;
    }
    // 0x800AB41C: nop

    // 0x800AB420: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB424: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB428: nop

    // 0x800AB42C: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
L_800AB430:
    // 0x800AB430: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AB434: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AB438: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB43C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB440: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AB444: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AB448: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AB44C: nop

    // 0x800AB450: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AB454: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AB458: nop

    // 0x800AB45C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800AB460: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AB464: beq         $t9, $zero, L_800AB4B8
    if (ctx->r25 == 0) {
        // 0x800AB468: nop
    
            goto L_800AB4B8;
    }
    // 0x800AB468: nop

    // 0x800AB46C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AB470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB474: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB478: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AB47C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AB480: nop

    // 0x800AB484: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AB488: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AB48C: nop

    // 0x800AB490: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800AB494: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AB498: bne         $t9, $zero, L_800AB4B0
    if (ctx->r25 != 0) {
        // 0x800AB49C: nop
    
            goto L_800AB4B0;
    }
    // 0x800AB49C: nop

    // 0x800AB4A0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800AB4A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AB4A8: b           L_800AB4C8
    // 0x800AB4AC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800AB4C8;
    // 0x800AB4AC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800AB4B0:
    // 0x800AB4B0: b           L_800AB4C8
    // 0x800AB4B4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800AB4C8;
    // 0x800AB4B4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800AB4B8:
    // 0x800AB4B8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800AB4BC: nop

    // 0x800AB4C0: bltz        $t9, L_800AB4B0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800AB4C4: nop
    
            goto L_800AB4B0;
    }
    // 0x800AB4C4: nop

L_800AB4C8:
    // 0x800AB4C8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AB4CC: sw          $t9, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r25;
    // 0x800AB4D0: nop

    // 0x800AB4D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AB4D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB4DC: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AB4E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB4E4: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AB4E8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AB4EC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB4F0: nop

    // 0x800AB4F4: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AB4F8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB4FC: nop

    // 0x800AB500: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800AB504: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AB508: beq         $t3, $zero, L_800AB55C
    if (ctx->r11 == 0) {
        // 0x800AB50C: nop
    
            goto L_800AB55C;
    }
    // 0x800AB50C: nop

    // 0x800AB510: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AB514: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AB518: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB51C: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800AB520: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB524: nop

    // 0x800AB528: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AB52C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB530: nop

    // 0x800AB534: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800AB538: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AB53C: bne         $t3, $zero, L_800AB554
    if (ctx->r11 != 0) {
        // 0x800AB540: nop
    
            goto L_800AB554;
    }
    // 0x800AB540: nop

    // 0x800AB544: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800AB548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AB54C: b           L_800AB56C
    // 0x800AB550: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800AB56C;
    // 0x800AB550: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800AB554:
    // 0x800AB554: b           L_800AB56C
    // 0x800AB558: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800AB56C;
    // 0x800AB558: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800AB55C:
    // 0x800AB55C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800AB560: nop

    // 0x800AB564: bltz        $t3, L_800AB554
    if (SIGNED(ctx->r11) < 0) {
        // 0x800AB568: nop
    
            goto L_800AB554;
    }
    // 0x800AB568: nop

L_800AB56C:
    // 0x800AB56C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AB570: sw          $t3, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r11;
    // 0x800AB574: nop

    // 0x800AB578: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AB57C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB580: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800AB584: nop

    // 0x800AB588: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AB58C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AB590: nop

    // 0x800AB594: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AB598: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB59C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB5A0: nop

    // 0x800AB5A4: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AB5A8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800AB5AC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AB5B0: sh          $t8, 0x15C($sp)
    MEM_H(0X15C, ctx->r29) = ctx->r24;
    // 0x800AB5B4: nop

    // 0x800AB5B8: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x800AB5BC: lw          $t2, 0x170($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X170);
    // 0x800AB5C0: nop

    // 0x800AB5C4: sltu        $at, $t6, $t2
    ctx->r1 = ctx->r14 < ctx->r10 ? 1 : 0;
    // 0x800AB5C8: bne         $at, $zero, L_800AB604
    if (ctx->r1 != 0) {
        // 0x800AB5CC: nop
    
            goto L_800AB604;
    }
    // 0x800AB5CC: nop

    // 0x800AB5D0: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB5D4: nop

    // 0x800AB5D8: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AB5DC: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AB5E0: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x800AB5E4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800AB5E8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800AB5EC: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800AB5F0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x800AB5F4: nop

    // 0x800AB5F8: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800AB5FC: b           L_800ABA00
    // 0x800AB600: nop

        goto L_800ABA00;
    // 0x800AB600: nop

L_800AB604:
    // 0x800AB604: lw          $t3, 0x1DC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AB608: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB60C: lh          $t1, 0x116($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X116);
    // 0x800AB610: nop

    // 0x800AB614: bne         $t1, $at, L_800AB780
    if (ctx->r9 != ctx->r1) {
        // 0x800AB618: nop
    
            goto L_800AB780;
    }
    // 0x800AB618: nop

    // 0x800AB61C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB620: nop

    // 0x800AB624: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800AB628: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AB62C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800AB630: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AB634: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x800AB638: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800AB63C: lw          $t5, 0x1DC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AB640: lhu         $t9, 0x182($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X182);
    // 0x800AB644: lw          $t0, 0x128($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X128);
    // 0x800AB648: sll         $t4, $t9, 6
    ctx->r12 = S32(ctx->r25 << 6);
    // 0x800AB64C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800AB650: sll         $t3, $t4, 5
    ctx->r11 = S32(ctx->r12 << 5);
    // 0x800AB654: addu        $t1, $t0, $t3
    ctx->r9 = ADD32(ctx->r8, ctx->r11);
    // 0x800AB658: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x800AB65C: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB660: nop

    // 0x800AB664: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x800AB668: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800AB66C: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x800AB670: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800AB674: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x800AB678: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AB67C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800AB680: lui         $t9, 0x709
    ctx->r25 = S32(0X709 << 16);
    // 0x800AB684: ori         $t9, $t9, 0x4160
    ctx->r25 = ctx->r25 | 0X4160;
    // 0x800AB688: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x800AB68C: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB690: nop

    // 0x800AB694: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AB698: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800AB69C: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x800AB6A0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800AB6A4: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x800AB6A8: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800AB6AC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800AB6B0: nop

    // 0x800AB6B4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800AB6B8: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB6BC: nop

    // 0x800AB6C0: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AB6C4: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AB6C8: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x800AB6CC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB6D0: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x800AB6D4: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800AB6D8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB6DC: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x800AB6E0: ori         $t4, $t4, 0xF100
    ctx->r12 = ctx->r12 | 0XF100;
    // 0x800AB6E4: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x800AB6E8: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB6EC: nop

    // 0x800AB6F0: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x800AB6F4: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800AB6F8: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x800AB6FC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800AB700: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AB704: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800AB708: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800AB70C: nop

    // 0x800AB710: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800AB714: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB718: nop

    // 0x800AB71C: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AB720: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AB724: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800AB728: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800AB72C: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x800AB730: ori         $t9, $t9, 0x1000
    ctx->r25 = ctx->r25 | 0X1000;
    // 0x800AB734: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800AB738: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800AB73C: lui         $t0, 0x9
    ctx->r8 = S32(0X9 << 16);
    // 0x800AB740: ori         $t0, $t0, 0x4160
    ctx->r8 = ctx->r8 | 0X4160;
    // 0x800AB744: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800AB748: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB74C: nop

    // 0x800AB750: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800AB754: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AB758: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800AB75C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800AB760: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800AB764: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800AB768: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800AB76C: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x800AB770: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x800AB774: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800AB778: b           L_800AB8F8
    // 0x800AB77C: nop

        goto L_800AB8F8;
    // 0x800AB77C: nop

L_800AB780:
    // 0x800AB780: lw          $t9, 0x1DC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AB784: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AB788: lh          $t4, 0x116($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X116);
    // 0x800AB78C: nop

    // 0x800AB790: bne         $t4, $at, L_800AB8F8
    if (ctx->r12 != ctx->r1) {
        // 0x800AB794: nop
    
            goto L_800AB8F8;
    }
    // 0x800AB794: nop

    // 0x800AB798: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB79C: nop

    // 0x800AB7A0: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AB7A4: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800AB7A8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800AB7AC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800AB7B0: lui         $t1, 0xFD10
    ctx->r9 = S32(0XFD10 << 16);
    // 0x800AB7B4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800AB7B8: lhu         $t7, 0x182($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X182);
    // 0x800AB7BC: lw          $t6, 0x1DC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AB7C0: sll         $t5, $t7, 6
    ctx->r13 = S32(ctx->r15 << 6);
    // 0x800AB7C4: lw          $t2, 0x128($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X128);
    // 0x800AB7C8: sll         $t9, $t5, 5
    ctx->r25 = S32(ctx->r13 << 5);
    // 0x800AB7CC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800AB7D0: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800AB7D4: addu        $t0, $t2, $t4
    ctx->r8 = ADD32(ctx->r10, ctx->r12);
    // 0x800AB7D8: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800AB7DC: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB7E0: nop

    // 0x800AB7E4: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800AB7E8: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AB7EC: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800AB7F0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800AB7F4: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x800AB7F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AB7FC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800AB800: lui         $t5, 0x705
    ctx->r13 = S32(0X705 << 16);
    // 0x800AB804: ori         $t5, $t5, 0x4160
    ctx->r13 = ctx->r13 | 0X4160;
    // 0x800AB808: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x800AB80C: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB810: nop

    // 0x800AB814: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800AB818: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800AB81C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800AB820: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800AB824: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x800AB828: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800AB82C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800AB830: nop

    // 0x800AB834: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AB838: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB83C: nop

    // 0x800AB840: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800AB844: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AB848: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800AB84C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800AB850: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800AB854: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AB858: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800AB85C: lui         $t9, 0x77F
    ctx->r25 = S32(0X77F << 16);
    // 0x800AB860: ori         $t9, $t9, 0xF080
    ctx->r25 = ctx->r25 | 0XF080;
    // 0x800AB864: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800AB868: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB86C: nop

    // 0x800AB870: addiu       $t0, $t4, 0x8
    ctx->r8 = ADD32(ctx->r12, 0X8);
    // 0x800AB874: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800AB878: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800AB87C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800AB880: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800AB884: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x800AB888: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800AB88C: nop

    // 0x800AB890: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800AB894: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB898: nop

    // 0x800AB89C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800AB8A0: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AB8A4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800AB8A8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800AB8AC: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x800AB8B0: ori         $t5, $t5, 0x2000
    ctx->r13 = ctx->r13 | 0X2000;
    // 0x800AB8B4: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800AB8B8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800AB8BC: lui         $t2, 0x5
    ctx->r10 = S32(0X5 << 16);
    // 0x800AB8C0: ori         $t2, $t2, 0x4160
    ctx->r10 = ctx->r10 | 0X4160;
    // 0x800AB8C4: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800AB8C8: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB8CC: nop

    // 0x800AB8D0: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AB8D4: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800AB8D8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800AB8DC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800AB8E0: lui         $t1, 0xF200
    ctx->r9 = S32(0XF200 << 16);
    // 0x800AB8E4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800AB8E8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800AB8EC: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x800AB8F0: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x800AB8F4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
L_800AB8F8:
    // 0x800AB8F8: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB8FC: nop

    // 0x800AB900: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800AB904: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800AB908: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800AB90C: lw          $t2, 0x174($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X174);
    // 0x800AB910: lw          $t1, 0x170($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X170);
    // 0x800AB914: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x800AB918: sll         $t0, $t4, 12
    ctx->r8 = S32(ctx->r12 << 12);
    // 0x800AB91C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800AB920: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800AB924: or          $t3, $t0, $at
    ctx->r11 = ctx->r8 | ctx->r1;
    // 0x800AB928: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x800AB92C: or          $t6, $t3, $t8
    ctx->r14 = ctx->r11 | ctx->r24;
    // 0x800AB930: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AB934: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800AB938: lw          $t4, 0x178($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X178);
    // 0x800AB93C: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x800AB940: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800AB944: sll         $t2, $t9, 12
    ctx->r10 = S32(ctx->r25 << 12);
    // 0x800AB948: andi        $t0, $t4, 0xFFF
    ctx->r8 = ctx->r12 & 0XFFF;
    // 0x800AB94C: or          $t1, $t2, $t0
    ctx->r9 = ctx->r10 | ctx->r8;
    // 0x800AB950: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800AB954: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB958: nop

    // 0x800AB95C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800AB960: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AB964: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800AB968: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB96C: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x800AB970: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AB974: lh          $t9, 0x15E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X15E);
    // 0x800AB978: lh          $t0, 0x15C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X15C);
    // 0x800AB97C: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800AB980: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB984: sll         $t2, $t4, 16
    ctx->r10 = S32(ctx->r12 << 16);
    // 0x800AB988: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x800AB98C: or          $t3, $t2, $t1
    ctx->r11 = ctx->r10 | ctx->r9;
    // 0x800AB990: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x800AB994: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB998: nop

    // 0x800AB99C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800AB9A0: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AB9A4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800AB9A8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800AB9AC: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x800AB9B0: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800AB9B4: lh          $t4, 0x152($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X152);
    // 0x800AB9B8: lh          $t1, 0x150($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X150);
    // 0x800AB9BC: andi        $t0, $t4, 0xFFFF
    ctx->r8 = ctx->r12 & 0XFFFF;
    // 0x800AB9C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800AB9C4: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x800AB9C8: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
    // 0x800AB9CC: or          $t8, $t2, $t3
    ctx->r24 = ctx->r10 | ctx->r11;
    // 0x800AB9D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800AB9D4: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB9D8: nop

    // 0x800AB9DC: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AB9E0: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AB9E4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800AB9E8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800AB9EC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800AB9F0: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800AB9F4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800AB9F8: nop

    // 0x800AB9FC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800ABA00:
    // 0x800ABA00: lw          $t1, 0x190($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X190);
    // 0x800ABA04: lw          $t3, 0x1B8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B8);
    // 0x800ABA08: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800ABA0C: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x800ABA10: addiu       $t8, $t3, 0x20
    ctx->r24 = ADD32(ctx->r11, 0X20);
    // 0x800ABA14: sw          $t8, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r24;
    // 0x800ABA18: bne         $at, $zero, L_800AA054
    if (ctx->r1 != 0) {
        // 0x800ABA1C: sw          $t2, 0x190($sp)
        MEM_W(0X190, ctx->r29) = ctx->r10;
            goto L_800AA054;
    }
    // 0x800ABA1C: sw          $t2, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r10;
L_800ABA20:
    // 0x800ABA20: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x800ABA24: lw          $t5, 0x1C0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C0);
    // 0x800ABA28: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800ABA2C: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x800ABA30: addiu       $t9, $t5, 0x40
    ctx->r25 = ADD32(ctx->r13, 0X40);
    // 0x800ABA34: sw          $t9, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r25;
    // 0x800ABA38: bne         $at, $zero, L_800AA004
    if (ctx->r1 != 0) {
        // 0x800ABA3C: sw          $t7, 0x194($sp)
        MEM_W(0X194, ctx->r29) = ctx->r15;
            goto L_800AA004;
    }
    // 0x800ABA3C: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x800ABA40: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800ABA44: nop

    // 0x800ABA48: addiu       $t0, $t4, 0x8
    ctx->r8 = ADD32(ctx->r12, 0X8);
    // 0x800ABA4C: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800ABA50: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800ABA54: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800ABA58: lui         $t1, 0xBB00
    ctx->r9 = S32(0XBB00 << 16);
    // 0x800ABA5C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800ABA60: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800ABA64: nop

    // 0x800ABA68: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800ABA6C: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800ABA70: nop

    // 0x800ABA74: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x800ABA78: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800ABA7C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800ABA80: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABA84: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800ABA88: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800ABA8C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABA90: nop

    // 0x800ABA94: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800ABA98: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800ABA9C: lw          $t0, 0x1D8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D8);
    // 0x800ABAA0: nop

    // 0x800ABAA4: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800ABAA8: b           L_800ABAB8
    // 0x800ABAAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ABAB8;
    // 0x800ABAAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ABAB0: b           L_800ABAB8
    // 0x800ABAB4: nop

        goto L_800ABAB8;
    // 0x800ABAB4: nop

L_800ABAB8:
    // 0x800ABAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ABABC: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
    // 0x800ABAC0: jr          $ra
    // 0x800ABAC4: nop

    return;
    // 0x800ABAC4: nop

;}
RECOMP_FUNC void func_80068BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068BD0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068BD4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068BD8: nop

    // 0x80068BDC: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068BE0: nop

    // 0x80068BE4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068BE8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068BEC: jr          $ra
    // 0x80068BF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068BF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068BF4: jr          $ra
    // 0x80068BF8: nop

    return;
    // 0x80068BF8: nop

    // 0x80068BFC: jr          $ra
    // 0x80068C00: nop

    return;
    // 0x80068C00: nop

;}
RECOMP_FUNC void func_80067110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067110: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067114: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067118: nop

    // 0x8006711C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067120: nop

    // 0x80067124: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067128: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006712C: jr          $ra
    // 0x80067130: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067130: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067134: jr          $ra
    // 0x80067138: nop

    return;
    // 0x80067138: nop

    // 0x8006713C: jr          $ra
    // 0x80067140: nop

    return;
    // 0x80067140: nop

;}
RECOMP_FUNC void func_80065FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065FD4: jal         0x80061488
    // 0x80065FD8: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065FD8: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_0:
    // 0x80065FDC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065FE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065FE4: b           L_80065FF4
    // 0x80065FE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065FF4;
    // 0x80065FE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065FEC: b           L_80065FF4
    // 0x80065FF0: nop

        goto L_80065FF4;
    // 0x80065FF0: nop

L_80065FF4:
    // 0x80065FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065FF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065FFC: jr          $ra
    // 0x80066000: nop

    return;
    // 0x80066000: nop

;}
RECOMP_FUNC void func_8006CC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CC2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CC30: jal         0x80061488
    // 0x8006CC34: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006CC34: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    after_0:
    // 0x8006CC38: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006CC3C: b           L_8006CC4C
    // 0x8006CC40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006CC4C;
    // 0x8006CC40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006CC44: b           L_8006CC4C
    // 0x8006CC48: nop

        goto L_8006CC4C;
    // 0x8006CC48: nop

L_8006CC4C:
    // 0x8006CC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CC54: jr          $ra
    // 0x8006CC58: nop

    return;
    // 0x8006CC58: nop

;}
RECOMP_FUNC void alCSPNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C95F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C95F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C95F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C95FC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C9600: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x800C9604: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800C9608: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800C960C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9610: lw          $t6, -0x33E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33E0);
    // 0x800C9614: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C9618: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800C961C: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800C9620: addiu       $t0, $zero, 0x3E80
    ctx->r8 = ADD32(0, 0X3E80);
    // 0x800C9624: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x800C9628: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800C962C: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800C9630: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800C9634: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x800C9638: sw          $t0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r8;
    // 0x800C963C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800C9640: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800C9644: lw          $t1, 0x10($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X10);
    // 0x800C9648: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x800C964C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C9650: sw          $t1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r9;
    // 0x800C9654: lw          $t2, 0x14($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X14);
    // 0x800C9658: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C965C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800C9660: sw          $t2, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r10;
    // 0x800C9664: lw          $t3, 0x18($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X18);
    // 0x800C9668: sh          $t4, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r12;
    // 0x800C966C: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
    // 0x800C9670: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x800C9674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C9678: sb          $t5, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r13;
    // 0x800C967C: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x800C9680: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C9684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9688: jal         0x800C7950
    // 0x800C968C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800C968C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C9690: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x800C9694: jal         0x800D3714
    // 0x800C9698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __initChanState(rdram, ctx);
        goto after_1;
    // 0x800C9698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C969C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C96A0: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x800C96A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C96A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C96AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C96B0: jal         0x800C7950
    // 0x800C96B4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800C96B4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800C96B8: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800C96BC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800C96C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C96C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C96C8: blez        $t8, L_800C96F8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C96CC: addiu       $t1, $zero, 0x1C
        ctx->r9 = ADD32(0, 0X1C);
            goto L_800C96F8;
    }
    // 0x800C96CC: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x800C96D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C96D4: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
L_800C96D8:
    // 0x800C96D8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C96DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C96E0: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x800C96E4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800C96E8: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800C96EC: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C96F0: bnel        $at, $zero, L_800C96D8
    if (ctx->r1 != 0) {
        // 0x800C96F4: lw          $t9, 0x6C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X6C);
            goto L_800C96D8;
    }
    goto skip_0;
    // 0x800C96F4: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    skip_0:
L_800C96F8:
    // 0x800C96F8: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800C96FC: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800C9700: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x800C9704: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C9708: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C970C: jal         0x800C7950
    // 0x800C9710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800C9710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800C9714: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800C9718: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C971C: jal         0x800D3BDC
    // 0x800C9720: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x800C9720: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x800C9724: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800C9728: addiu       $t2, $t2, -0x7024
    ctx->r10 = ADD32(ctx->r10, -0X7024);
    // 0x800C972C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800C9730: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800C9734: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800C9738: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C973C: lw          $a0, -0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33E0);
    // 0x800C9740: jal         0x800D3C50
    // 0x800C9744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x800C9744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800C9748: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C974C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9750: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C9754: jr          $ra
    // 0x800C9758: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C9758: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006F5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F5D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F5D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F5DC: nop

    // 0x8006F5E0: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x8006F5E4: nop

    // 0x8006F5E8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F5EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F5F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F5F4: bne         $v0, $zero, L_8006F648
    if (ctx->r2 != 0) {
        // 0x8006F5F8: nop
    
            goto L_8006F648;
    }
    // 0x8006F5F8: nop

    // 0x8006F5FC: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x8006F600: nop

    // 0x8006F604: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F608: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006F60C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006F610: bne         $v0, $zero, L_8006F648
    if (ctx->r2 != 0) {
        // 0x8006F614: nop
    
            goto L_8006F648;
    }
    // 0x8006F614: nop

    // 0x8006F618: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x8006F61C: nop

    // 0x8006F620: slti        $t9, $v0, 0x1F4
    ctx->r25 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F624: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x8006F628: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006F62C: bne         $v0, $zero, L_8006F648
    if (ctx->r2 != 0) {
        // 0x8006F630: nop
    
            goto L_8006F648;
    }
    // 0x8006F630: nop

    // 0x8006F634: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x8006F638: nop

    // 0x8006F63C: slti        $t0, $v0, 0x1F4
    ctx->r8 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F640: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x8006F644: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006F648:
    // 0x8006F648: jr          $ra
    // 0x8006F64C: nop

    return;
    // 0x8006F64C: nop

    // 0x8006F650: jr          $ra
    // 0x8006F654: nop

    return;
    // 0x8006F654: nop

    // 0x8006F658: jr          $ra
    // 0x8006F65C: nop

    return;
    // 0x8006F65C: nop

;}
RECOMP_FUNC void func_80076C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C44: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076C48: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076C4C: nop

    // 0x80076C50: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076C54: nop

    // 0x80076C58: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80076C5C: jr          $ra
    // 0x80076C60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076C60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076C64: jr          $ra
    // 0x80076C68: nop

    return;
    // 0x80076C68: nop

    // 0x80076C6C: jr          $ra
    // 0x80076C70: nop

    return;
    // 0x80076C70: nop

;}
RECOMP_FUNC void func_80067568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067568: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006756C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067570: nop

    // 0x80067574: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067578: nop

    // 0x8006757C: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x80067580: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067584: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067588: beq         $v0, $zero, L_800675A4
    if (ctx->r2 == 0) {
        // 0x8006758C: nop
    
            goto L_800675A4;
    }
    // 0x8006758C: nop

    // 0x80067590: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067594: nop

    // 0x80067598: slti        $t8, $v0, 0x32
    ctx->r24 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8006759C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800675A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800675A4:
    // 0x800675A4: jr          $ra
    // 0x800675A8: nop

    return;
    // 0x800675A8: nop

    // 0x800675AC: jr          $ra
    // 0x800675B0: nop

    return;
    // 0x800675B0: nop

    // 0x800675B4: jr          $ra
    // 0x800675B8: nop

    return;
    // 0x800675B8: nop

;}
RECOMP_FUNC void func_80090A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A7C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090A80: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80090A84: nop

    // 0x80090A88: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x80090A8C: bne         $t7, $zero, L_80090C84
    if (ctx->r15 != 0) {
        // 0x80090A90: nop
    
            goto L_80090C84;
    }
    // 0x80090A90: nop

    // 0x80090A94: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090A98: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x80090A9C: nop

    // 0x80090AA0: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x80090AA4: bne         $t9, $zero, L_80090B9C
    if (ctx->r25 != 0) {
        // 0x80090AA8: nop
    
            goto L_80090B9C;
    }
    // 0x80090AA8: nop

    // 0x80090AAC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090AB0: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x80090AB4: nop

    // 0x80090AB8: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x80090ABC: beq         $t1, $zero, L_80090AE0
    if (ctx->r9 == 0) {
        // 0x80090AC0: nop
    
            goto L_80090AE0;
    }
    // 0x80090AC0: nop

    // 0x80090AC4: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80090AC8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090ACC: sw          $t2, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r10;
    // 0x80090AD0: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80090AD4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090AD8: b           L_80090B94
    // 0x80090ADC: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
        goto L_80090B94;
    // 0x80090ADC: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
L_80090AE0:
    // 0x80090AE0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80090AE4: lh          $t4, -0x4CC8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CC8);
    // 0x80090AE8: nop

    // 0x80090AEC: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80090AF0: beq         $t5, $zero, L_80090B14
    if (ctx->r13 == 0) {
        // 0x80090AF4: nop
    
            goto L_80090B14;
    }
    // 0x80090AF4: nop

    // 0x80090AF8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80090AFC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B00: sw          $t6, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r14;
    // 0x80090B04: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80090B08: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B0C: b           L_80090B94
    // 0x80090B10: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
        goto L_80090B94;
    // 0x80090B10: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
L_80090B14:
    // 0x80090B14: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090B18: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x80090B1C: nop

    // 0x80090B20: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x80090B24: beq         $t9, $zero, L_80090B48
    if (ctx->r25 == 0) {
        // 0x80090B28: nop
    
            goto L_80090B48;
    }
    // 0x80090B28: nop

    // 0x80090B2C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80090B30: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B34: sw          $t0, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r8;
    // 0x80090B38: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x80090B3C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B40: b           L_80090B94
    // 0x80090B44: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
        goto L_80090B94;
    // 0x80090B44: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
L_80090B48:
    // 0x80090B48: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80090B4C: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x80090B50: nop

    // 0x80090B54: andi        $t3, $t2, 0x200
    ctx->r11 = ctx->r10 & 0X200;
    // 0x80090B58: beq         $t3, $zero, L_80090B7C
    if (ctx->r11 == 0) {
        // 0x80090B5C: nop
    
            goto L_80090B7C;
    }
    // 0x80090B5C: nop

    // 0x80090B60: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80090B64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B68: sw          $t4, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r12;
    // 0x80090B6C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80090B70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B74: b           L_80090B94
    // 0x80090B78: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
        goto L_80090B94;
    // 0x80090B78: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
L_80090B7C:
    // 0x80090B7C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80090B80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B84: sw          $t6, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r14;
    // 0x80090B88: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80090B8C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B90: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
L_80090B94:
    // 0x80090B94: b           L_80090C84
    // 0x80090B98: nop

        goto L_80090C84;
    // 0x80090B98: nop

L_80090B9C:
    // 0x80090B9C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090BA0: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x80090BA4: nop

    // 0x80090BA8: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x80090BAC: beq         $t9, $zero, L_80090BD0
    if (ctx->r25 == 0) {
        // 0x80090BB0: nop
    
            goto L_80090BD0;
    }
    // 0x80090BB0: nop

    // 0x80090BB4: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80090BB8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090BBC: sw          $t0, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r8;
    // 0x80090BC0: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80090BC4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090BC8: b           L_80090C84
    // 0x80090BCC: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
        goto L_80090C84;
    // 0x80090BCC: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
L_80090BD0:
    // 0x80090BD0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80090BD4: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x80090BD8: nop

    // 0x80090BDC: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80090BE0: beq         $t3, $zero, L_80090C04
    if (ctx->r11 == 0) {
        // 0x80090BE4: nop
    
            goto L_80090C04;
    }
    // 0x80090BE4: nop

    // 0x80090BE8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80090BEC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090BF0: sw          $t4, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r12;
    // 0x80090BF4: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80090BF8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090BFC: b           L_80090C84
    // 0x80090C00: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
        goto L_80090C84;
    // 0x80090C00: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
L_80090C04:
    // 0x80090C04: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090C08: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80090C0C: nop

    // 0x80090C10: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80090C14: beq         $t7, $zero, L_80090C38
    if (ctx->r15 == 0) {
        // 0x80090C18: nop
    
            goto L_80090C38;
    }
    // 0x80090C18: nop

    // 0x80090C1C: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80090C20: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C24: sw          $t8, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r24;
    // 0x80090C28: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x80090C2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C30: b           L_80090C84
    // 0x80090C34: sw          $t9, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r25;
        goto L_80090C84;
    // 0x80090C34: sw          $t9, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r25;
L_80090C38:
    // 0x80090C38: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090C3C: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x80090C40: nop

    // 0x80090C44: andi        $t1, $t0, 0x200
    ctx->r9 = ctx->r8 & 0X200;
    // 0x80090C48: beq         $t1, $zero, L_80090C6C
    if (ctx->r9 == 0) {
        // 0x80090C4C: nop
    
            goto L_80090C6C;
    }
    // 0x80090C4C: nop

    // 0x80090C50: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80090C54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C58: sw          $t2, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r10;
    // 0x80090C5C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80090C60: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C64: b           L_80090C84
    // 0x80090C68: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
        goto L_80090C84;
    // 0x80090C68: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
L_80090C6C:
    // 0x80090C6C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80090C70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C74: sw          $t4, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r12;
    // 0x80090C78: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80090C7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C80: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
L_80090C84:
    // 0x80090C84: jr          $ra
    // 0x80090C88: nop

    return;
    // 0x80090C88: nop

    // 0x80090C8C: jr          $ra
    // 0x80090C90: nop

    return;
    // 0x80090C90: nop

;}
RECOMP_FUNC void func_800ACC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACC34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ACC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACC3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800ACC40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800ACC44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800ACC48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800ACC4C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800ACC50: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800ACC54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ACC58: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800ACC5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800ACC60: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x800ACC64: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800ACC68: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800ACC6C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800ACC70: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800ACC74: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800ACC78: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800ACC7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACC80: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800ACC84: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800ACC88: swc1        $f4, -0x7390($at)
    MEM_W(-0X7390, ctx->r1) = ctx->f4.u32l;
    // 0x800ACC8C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800ACC90: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800ACC94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACC98: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800ACC9C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800ACCA0: swc1        $f6, -0x738C($at)
    MEM_W(-0X738C, ctx->r1) = ctx->f6.u32l;
    // 0x800ACCA4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800ACCA8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800ACCAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACCB0: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800ACCB4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800ACCB8: swc1        $f8, -0x7388($at)
    MEM_W(-0X7388, ctx->r1) = ctx->f8.u32l;
    // 0x800ACCBC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACCC0: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800ACCC4: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800ACCC8: nop

    // 0x800ACCCC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800ACCD0: beq         $t8, $zero, L_800ACD64
    if (ctx->r24 == 0) {
        // 0x800ACCD4: nop
    
            goto L_800ACD64;
    }
    // 0x800ACCD4: nop

    // 0x800ACCD8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800ACCDC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACCE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACCE4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800ACCE8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800ACCEC: lwc1        $f16, -0x7390($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7390);
    // 0x800ACCF0: lwc1        $f10, 0xCC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800ACCF4: nop

    // 0x800ACCF8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ACCFC: swc1        $f18, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f18.u32l;
    // 0x800ACD00: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800ACD04: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACD08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACD0C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800ACD10: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800ACD14: lwc1        $f6, -0x738C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X738C);
    // 0x800ACD18: lwc1        $f4, 0xD0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x800ACD1C: nop

    // 0x800ACD20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACD24: swc1        $f8, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f8.u32l;
    // 0x800ACD28: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800ACD2C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACD30: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACD34: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800ACD38: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800ACD3C: lwc1        $f16, -0x7388($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7388);
    // 0x800ACD40: lwc1        $f10, 0xD4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD4);
    // 0x800ACD44: nop

    // 0x800ACD48: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ACD4C: swc1        $f18, 0xD4($t5)
    MEM_W(0XD4, ctx->r13) = ctx->f18.u32l;
    // 0x800ACD50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800ACD54: jal         0x800AC978
    // 0x800ACD58: nop

    func_800AC978(rdram, ctx);
        goto after_0;
    // 0x800ACD58: nop

    after_0:
    // 0x800ACD5C: b           L_800ACD6C
    // 0x800ACD60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_800ACD6C;
    // 0x800ACD60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_800ACD64:
    // 0x800ACD64: b           L_800ACD80
    // 0x800ACD68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ACD80;
    // 0x800ACD68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800ACD6C:
    // 0x800ACD6C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800ACD70: b           L_800ACD80
    // 0x800ACD74: nop

        goto L_800ACD80;
    // 0x800ACD74: nop

    // 0x800ACD78: b           L_800ACD80
    // 0x800ACD7C: nop

        goto L_800ACD80;
    // 0x800ACD7C: nop

L_800ACD80:
    // 0x800ACD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ACD84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800ACD88: jr          $ra
    // 0x800ACD8C: nop

    return;
    // 0x800ACD8C: nop

;}
RECOMP_FUNC void func_8006DA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DA5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DA60: jal         0x8005F064
    // 0x8006DA64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006DA64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8006DA68: b           L_8006DA78
    // 0x8006DA6C: nop

        goto L_8006DA78;
    // 0x8006DA6C: nop

    // 0x8006DA70: b           L_8006DA78
    // 0x8006DA74: nop

        goto L_8006DA78;
    // 0x8006DA74: nop

L_8006DA78:
    // 0x8006DA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DA7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DA80: jr          $ra
    // 0x8006DA84: nop

    return;
    // 0x8006DA84: nop

;}
