#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80057538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057538: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005753C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80057540: lh          $t6, 0x1B48($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1B48);
    // 0x80057544: nop

    // 0x80057548: bne         $t6, $zero, L_80057558
    if (ctx->r14 != 0) {
        // 0x8005754C: nop
    
            goto L_80057558;
    }
    // 0x8005754C: nop

    // 0x80057550: b           L_8005770C
    // 0x80057554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005770C;
    // 0x80057554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057558:
    // 0x80057558: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005755C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80057560: lw          $t8, 0x306C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X306C);
    // 0x80057564: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x80057568: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8005756C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80057570: blez        $t7, L_80057644
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80057574: sw          $t7, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r15;
            goto L_80057644;
    }
    // 0x80057574: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80057578:
    // 0x80057578: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005757C: nop

    // 0x80057580: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x80057584: nop

    // 0x80057588: bne         $t0, $zero, L_8005761C
    if (ctx->r8 != 0) {
        // 0x8005758C: nop
    
            goto L_8005761C;
    }
    // 0x8005758C: nop

    // 0x80057590: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x80057594: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80057598: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x8005759C: nop
    
            goto L_8005761C;
    }
    // 0x8005759C: nop

    // 0x800575A0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800575A4: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575A8: nop
    
            goto L_8005761C;
    }
    // 0x800575A8: nop

    // 0x800575AC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800575B0: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575B4: nop
    
            goto L_8005761C;
    }
    // 0x800575B4: nop

    // 0x800575B8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800575BC: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575C0: nop
    
            goto L_8005761C;
    }
    // 0x800575C0: nop

    // 0x800575C4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800575C8: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575CC: nop
    
            goto L_8005761C;
    }
    // 0x800575CC: nop

    // 0x800575D0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800575D4: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575D8: nop
    
            goto L_8005761C;
    }
    // 0x800575D8: nop

    // 0x800575DC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800575E0: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575E4: nop
    
            goto L_8005761C;
    }
    // 0x800575E4: nop

    // 0x800575E8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x800575EC: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575F0: nop
    
            goto L_8005761C;
    }
    // 0x800575F0: nop

    // 0x800575F4: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800575F8: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x800575FC: nop
    
            goto L_8005761C;
    }
    // 0x800575FC: nop

    // 0x80057600: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80057604: beq         $t1, $at, L_8005761C
    if (ctx->r9 == ctx->r1) {
        // 0x80057608: nop
    
            goto L_8005761C;
    }
    // 0x80057608: nop

    // 0x8005760C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80057610: nop

    // 0x80057614: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80057618: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
L_8005761C:
    // 0x8005761C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80057620: nop

    // 0x80057624: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x80057628: nop

    // 0x8005762C: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80057630: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80057634: nop

    // 0x80057638: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8005763C: bgtz        $t8, L_80057578
    if (SIGNED(ctx->r24) > 0) {
        // 0x80057640: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_80057578;
    }
    // 0x80057640: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_80057644:
    // 0x80057644: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80057648: nop

    // 0x8005764C: bne         $t7, $zero, L_8005765C
    if (ctx->r15 != 0) {
        // 0x80057650: nop
    
            goto L_8005765C;
    }
    // 0x80057650: nop

    // 0x80057654: b           L_8005770C
    // 0x80057658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005770C;
    // 0x80057658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005765C:
    // 0x8005765C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80057660: lw          $t0, 0x670($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X670);
    // 0x80057664: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80057668: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005766C: div         $zero, $t0, $t9
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r25)));
    // 0x80057670: lw          $t2, 0x306C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X306C);
    // 0x80057674: bne         $t9, $zero, L_80057680
    if (ctx->r25 != 0) {
        // 0x80057678: nop
    
            goto L_80057680;
    }
    // 0x80057678: nop

    // 0x8005767C: break       7
    do_break(2147841660);
L_80057680:
    // 0x80057680: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057684: bne         $t9, $at, L_80057698
    if (ctx->r25 != ctx->r1) {
        // 0x80057688: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80057698;
    }
    // 0x80057688: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005768C: bne         $t0, $at, L_80057698
    if (ctx->r8 != ctx->r1) {
        // 0x80057690: nop
    
            goto L_80057698;
    }
    // 0x80057690: nop

    // 0x80057694: break       6
    do_break(2147841684);
L_80057698:
    // 0x80057698: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8005769C: mfhi        $t1
    ctx->r9 = hi;
    // 0x800576A0: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800576A4: blez        $t1, L_800576F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800576A8: nop
    
            goto L_800576F8;
    }
    // 0x800576A8: nop

L_800576AC:
    // 0x800576AC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800576B0: nop

    // 0x800576B4: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x800576B8: nop

    // 0x800576BC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800576C0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800576C4: nop

    // 0x800576C8: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x800576CC: nop

    // 0x800576D0: bne         $t6, $zero, L_800576E8
    if (ctx->r14 != 0) {
        // 0x800576D4: nop
    
            goto L_800576E8;
    }
    // 0x800576D4: nop

    // 0x800576D8: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800576DC: nop

    // 0x800576E0: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800576E4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800576E8:
    // 0x800576E8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800576EC: nop

    // 0x800576F0: bgtz        $t0, L_800576AC
    if (SIGNED(ctx->r8) > 0) {
        // 0x800576F4: nop
    
            goto L_800576AC;
    }
    // 0x800576F4: nop

L_800576F8:
    // 0x800576F8: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800576FC: b           L_8005770C
    // 0x80057700: nop

        goto L_8005770C;
    // 0x80057700: nop

    // 0x80057704: b           L_8005770C
    // 0x80057708: nop

        goto L_8005770C;
    // 0x80057708: nop

L_8005770C:
    // 0x8005770C: jr          $ra
    // 0x80057710: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80057710: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80013474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013474: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80013478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001347C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80013480: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80013484: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80013488: jal         0x8000DA44
    // 0x8001348C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x8001348C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80013490: bgez        $v0, L_800134A0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013494: nop
    
            goto L_800134A0;
    }
    // 0x80013494: nop

    // 0x80013498: b           L_80013614
    // 0x8001349C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013614;
    // 0x8001349C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800134A0:
    // 0x800134A0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800134A4: nop

    // 0x800134A8: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800134AC: nop

    // 0x800134B0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800134B4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800134B8:
    // 0x800134B8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800134BC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800134C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800134C4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800134C8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800134CC: swc1        $f4, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f4.u32l;
    // 0x800134D0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800134D4: nop

    // 0x800134D8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800134DC: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x800134E0: bne         $at, $zero, L_800134B8
    if (ctx->r1 != 0) {
        // 0x800134E4: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_800134B8;
    }
    // 0x800134E4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800134E8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800134EC: nop

    // 0x800134F0: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800134F4: nop

    // 0x800134F8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800134FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80013500: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80013504: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80013508: nop

    // 0x8001350C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80013510: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x80013514: nop

    // 0x80013518: blez        $t9, L_80013604
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001351C: nop
    
            goto L_80013604;
    }
    // 0x8001351C: nop

L_80013520:
    // 0x80013520: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x80013524: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x80013528: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001352C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80013530: nop

    // 0x80013534: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80013538: swc1        $f8, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f8.u32l;
    // 0x8001353C: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x80013540: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x80013544: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80013548: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8001354C: nop

    // 0x80013550: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80013554: swc1        $f16, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f16.u32l;
    // 0x80013558: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8001355C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80013560: lw          $t7, 0x1AC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1AC);
    // 0x80013564: nop

    // 0x80013568: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001356C: bne         $at, $zero, L_8001358C
    if (ctx->r1 != 0) {
        // 0x80013570: nop
    
            goto L_8001358C;
    }
    // 0x80013570: nop

    // 0x80013574: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80013578: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001357C: beq         $at, $zero, L_8001358C
    if (ctx->r1 == 0) {
        // 0x80013580: nop
    
            goto L_8001358C;
    }
    // 0x80013580: nop

    // 0x80013584: b           L_800135D4
    // 0x80013588: nop

        goto L_800135D4;
    // 0x80013588: nop

L_8001358C:
    // 0x8001358C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80013590: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80013594: lwc1        $f18, 0x1B8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X1B8);
    // 0x80013598: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8001359C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800135A0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800135A4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800135A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800135AC: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x800135B0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800135B4: nop

    // 0x800135B8: lwc1        $f4, 0xD0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x800135BC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800135C0: add.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d + ctx->f8.d;
    // 0x800135C4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800135C8: add.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f6.d + ctx->f18.d;
    // 0x800135CC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800135D0: swc1        $f16, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f16.u32l;
L_800135D4:
    // 0x800135D4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800135D8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800135DC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800135E0: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800135E4: addiu       $t2, $t1, 0x160
    ctx->r10 = ADD32(ctx->r9, 0X160);
    // 0x800135E8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800135EC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800135F0: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x800135F4: nop

    // 0x800135F8: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800135FC: bne         $at, $zero, L_80013520
    if (ctx->r1 != 0) {
        // 0x80013600: nop
    
            goto L_80013520;
    }
    // 0x80013600: nop

L_80013604:
    // 0x80013604: b           L_80013614
    // 0x80013608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013614;
    // 0x80013608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001360C: b           L_80013614
    // 0x80013610: nop

        goto L_80013614;
    // 0x80013610: nop

L_80013614:
    // 0x80013614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001361C: jr          $ra
    // 0x80013620: nop

    return;
    // 0x80013620: nop

;}
RECOMP_FUNC void func_8007483C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007483C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074844: jal         0x80061348
    // 0x80074848: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074848: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x8007484C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074850: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074854: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074858: beq         $v0, $zero, L_800748AC
    if (ctx->r2 == 0) {
        // 0x8007485C: nop
    
            goto L_800748AC;
    }
    // 0x8007485C: nop

    // 0x80074860: jal         0x80061348
    // 0x80074864: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074864: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074868: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007486C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074870: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074874: beq         $v0, $zero, L_800748AC
    if (ctx->r2 == 0) {
        // 0x80074878: nop
    
            goto L_800748AC;
    }
    // 0x80074878: nop

    // 0x8007487C: jal         0x80061348
    // 0x80074880: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074880: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074884: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074888: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007488C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074890: beq         $v0, $zero, L_800748AC
    if (ctx->r2 == 0) {
        // 0x80074894: nop
    
            goto L_800748AC;
    }
    // 0x80074894: nop

    // 0x80074898: jal         0x80061348
    // 0x8007489C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007489C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x800748A0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800748A4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800748A8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800748AC:
    // 0x800748AC: b           L_800748BC
    // 0x800748B0: nop

        goto L_800748BC;
    // 0x800748B0: nop

    // 0x800748B4: b           L_800748BC
    // 0x800748B8: nop

        goto L_800748BC;
    // 0x800748B8: nop

L_800748BC:
    // 0x800748BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800748C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800748C4: jr          $ra
    // 0x800748C8: nop

    return;
    // 0x800748C8: nop

;}
RECOMP_FUNC void func_80088568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088568: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008856C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088570: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80088574: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80088578: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008857C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80088580: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80088584: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80088588: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8008858C: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80088590: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80088594: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80088598: beq         $t0, $zero, L_80088610
    if (ctx->r8 == 0) {
        // 0x8008859C: nop
    
            goto L_80088610;
    }
    // 0x8008859C: nop

    // 0x800885A0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800885A4: jal         0x8008A518
    // 0x800885A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800885A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800885AC: beq         $v0, $zero, L_80088610
    if (ctx->r2 == 0) {
        // 0x800885B0: nop
    
            goto L_80088610;
    }
    // 0x800885B0: nop

    // 0x800885B4: lhu         $s0, 0x24($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X24);
    // 0x800885B8: addiu       $at, $zero, 0x4007
    ctx->r1 = ADD32(0, 0X4007);
    // 0x800885BC: beq         $s0, $at, L_80088600
    if (ctx->r16 == ctx->r1) {
        // 0x800885C0: nop
    
            goto L_80088600;
    }
    // 0x800885C0: nop

    // 0x800885C4: addiu       $at, $zero, 0x4008
    ctx->r1 = ADD32(0, 0X4008);
    // 0x800885C8: beq         $s0, $at, L_800885D8
    if (ctx->r16 == ctx->r1) {
        // 0x800885CC: nop
    
            goto L_800885D8;
    }
    // 0x800885CC: nop

    // 0x800885D0: b           L_80088610
    // 0x800885D4: nop

        goto L_80088610;
    // 0x800885D4: nop

L_800885D8:
    // 0x800885D8: jal         0x8008CE48
    // 0x800885DC: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x800885DC: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x800885E0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800885E4: nop

    // 0x800885E8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800885EC: nop

    // 0x800885F0: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x800885F4: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x800885F8: b           L_80088664
    // 0x800885FC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80088664;
    // 0x800885FC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80088600:
    // 0x80088600: jal         0x8008CE48
    // 0x80088604: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80088604: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80088608: b           L_80088664
    // 0x8008860C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_80088664;
    // 0x8008860C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_80088610:
    // 0x80088610: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80088614: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x80088618: lhu         $t4, 0x36($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X36);
    // 0x8008861C: nop

    // 0x80088620: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80088624: beq         $t6, $zero, L_80088654
    if (ctx->r14 == 0) {
        // 0x80088628: nop
    
            goto L_80088654;
    }
    // 0x80088628: nop

    // 0x8008862C: jal         0x8008CE48
    // 0x80088630: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80088630: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x80088634: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80088638: nop

    // 0x8008863C: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x80088640: nop

    // 0x80088644: ori         $t8, $t9, 0x200
    ctx->r24 = ctx->r25 | 0X200;
    // 0x80088648: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x8008864C: b           L_80088664
    // 0x80088650: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80088664;
    // 0x80088650: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80088654:
    // 0x80088654: b           L_80088664
    // 0x80088658: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_80088664;
    // 0x80088658: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x8008865C: b           L_80088664
    // 0x80088660: nop

        goto L_80088664;
    // 0x80088660: nop

L_80088664:
    // 0x80088664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80088668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008866C: jr          $ra
    // 0x80088670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80088670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _freePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7B58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C7B5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C7B60: jal         0x800C7890
    // 0x800C7B64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C7B64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800C7B68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C7B6C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7B70: jal         0x800C78C0
    // 0x800C7B74: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C7B74: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x800C7B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7B80: jr          $ra
    // 0x800C7B84: nop

    return;
    // 0x800C7B84: nop

;}
RECOMP_FUNC void func_80072794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007279C: jal         0x80061488
    // 0x800727A0: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800727A0: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    after_0:
    // 0x800727A4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800727A8: b           L_800727B8
    // 0x800727AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800727B8;
    // 0x800727AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800727B0: b           L_800727B8
    // 0x800727B4: nop

        goto L_800727B8;
    // 0x800727B4: nop

L_800727B8:
    // 0x800727B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800727BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800727C0: jr          $ra
    // 0x800727C4: nop

    return;
    // 0x800727C4: nop

;}
RECOMP_FUNC void func_800777CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800777CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800777D0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800777D4: nop

    // 0x800777D8: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x800777DC: nop

    // 0x800777E0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800777E4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800777E8: jr          $ra
    // 0x800777EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800777EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800777F0: jr          $ra
    // 0x800777F4: nop

    return;
    // 0x800777F4: nop

    // 0x800777F8: jr          $ra
    // 0x800777FC: nop

    return;
    // 0x800777FC: nop

;}
RECOMP_FUNC void Thread_SetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0FFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C1008: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C100C: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C1010: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C1014: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C1018: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C101C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C1020: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C1024: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C1028: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C102C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C1030: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C1034: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C1038: nop

    // 0x800C103C: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C1040: bne         $t9, $zero, L_800C1050
    if (ctx->r25 != 0) {
        // 0x800C1044: nop
    
            goto L_800C1050;
    }
    // 0x800C1044: nop

    // 0x800C1048: b           L_800C109C
    // 0x800C104C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C109C;
    // 0x800C104C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C1050:
    // 0x800C1050: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C1054: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C1058: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C105C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C1060: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C1064: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C1068: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C106C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C1070: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C1074: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C1078: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C107C: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C1080: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1084: jal         0x800CB5A0
    // 0x800C1088: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1088: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x800C108C: b           L_800C109C
    // 0x800C1090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C109C;
    // 0x800C1090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1094: b           L_800C109C
    // 0x800C1098: nop

        goto L_800C109C;
    // 0x800C1098: nop

L_800C109C:
    // 0x800C109C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C10A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C10A4: jr          $ra
    // 0x800C10A8: nop

    return;
    // 0x800C10A8: nop

;}
RECOMP_FUNC void func_8008B738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B738: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008B73C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B740: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8008B744: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8008B748: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8008B74C: jal         0x80090754
    // 0x8008B750: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090754(rdram, ctx);
        goto after_0;
    // 0x8008B750: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8008B754: jal         0x80090728
    // 0x8008B758: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090728(rdram, ctx);
        goto after_1;
    // 0x8008B758: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x8008B75C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B760: nop

    // 0x8008B764: beq         $t6, $zero, L_8008B794
    if (ctx->r14 == 0) {
        // 0x8008B768: nop
    
            goto L_8008B794;
    }
    // 0x8008B768: nop

    // 0x8008B76C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B770: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8008B774: jal         0x8008BE0C
    // 0x8008B778: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8008BE0C(rdram, ctx);
        goto after_2;
    // 0x8008B778: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_2:
    // 0x8008B77C: bgez        $v0, L_8008B78C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008B780: sra         $t7, $v0, 1
        ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8008B78C;
    }
    // 0x8008B780: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008B784: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8008B788: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8008B78C:
    // 0x8008B78C: b           L_8008B798
    // 0x8008B790: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_8008B798;
    // 0x8008B790: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8008B794:
    // 0x8008B794: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008B798:
    // 0x8008B798: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B79C: nop

    // 0x8008B7A0: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x8008B7A4: beq         $at, $zero, L_8008B7E4
    if (ctx->r1 == 0) {
        // 0x8008B7A8: sw          $t8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r24;
            goto L_8008B7E4;
    }
    // 0x8008B7A8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_8008B7AC:
    // 0x8008B7AC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008B7B0: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x8008B7B4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008B7B8: sll         $t0, $t9, 0
    ctx->r8 = S32(ctx->r25 << 0);
    // 0x8008B7BC: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x8008B7C0: addiu       $a1, $a1, -0xAA4
    ctx->r5 = ADD32(ctx->r5, -0XAA4);
    // 0x8008B7C4: jal         0x800BCFCC
    // 0x8008B7C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x8008B7C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8008B7CC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008B7D0: nop

    // 0x8008B7D4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008B7D8: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x8008B7DC: bne         $at, $zero, L_8008B7AC
    if (ctx->r1 != 0) {
        // 0x8008B7E0: sw          $t3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r11;
            goto L_8008B7AC;
    }
    // 0x8008B7E0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
L_8008B7E4:
    // 0x8008B7E4: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x8008B7E8: sb          $zero, 0x7($t4)
    MEM_B(0X7, ctx->r12) = 0;
    // 0x8008B7EC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B7F0: addiu       $a0, $a0, -0xAA0
    ctx->r4 = ADD32(ctx->r4, -0XAA0);
    // 0x8008B7F4: jal         0x8008ECE4
    // 0x8008B7F8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8008B7F8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_4:
    // 0x8008B7FC: addiu       $t5, $zero, 0xBB
    ctx->r13 = ADD32(0, 0XBB);
    // 0x8008B800: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B804: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x8008B808: addiu       $t6, $zero, 0x82
    ctx->r14 = ADD32(0, 0X82);
    // 0x8008B80C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B810: sw          $t6, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r14;
    // 0x8008B814: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x8008B818: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8008B81C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8008B820: nop

    // 0x8008B824: beq         $t8, $zero, L_8008B880
    if (ctx->r24 == 0) {
        // 0x8008B828: nop
    
            goto L_8008B880;
    }
    // 0x8008B828: nop

L_8008B82C:
    // 0x8008B82C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008B830: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8008B834: jal         0x800BCFCC
    // 0x8008B838: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x8008B838: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8008B83C: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x8008B840: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
    // 0x8008B844: jal         0x8008ECE4
    // 0x8008B848: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8008B848: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x8008B84C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008B850: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x8008B854: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B858: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008B85C: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8008B860: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008B864: nop

    // 0x8008B868: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008B86C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8008B870: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8008B874: nop

    // 0x8008B878: bne         $t4, $zero, L_8008B82C
    if (ctx->r12 != 0) {
        // 0x8008B87C: nop
    
            goto L_8008B82C;
    }
    // 0x8008B87C: nop

L_8008B880:
    // 0x8008B880: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008B884: nop

    // 0x8008B888: bne         $t5, $zero, L_8008B8C0
    if (ctx->r13 != 0) {
        // 0x8008B88C: nop
    
            goto L_8008B8C0;
    }
    // 0x8008B88C: nop

    // 0x8008B890: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008B894: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008B898: nop

    // 0x8008B89C: swc1        $f4, 0xBD4($t6)
    MEM_W(0XBD4, ctx->r14) = ctx->f4.u32l;
    // 0x8008B8A0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008B8A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008B8A8: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x8008B8AC: nop

    // 0x8008B8B0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8008B8B4: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x8008B8B8: b           L_8008BA14
    // 0x8008B8BC: nop

        goto L_8008BA14;
    // 0x8008B8BC: nop

L_8008B8C0:
    // 0x8008B8C0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8008B8C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008B8C8: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008B8CC: lwc1        $f6, 0xBD4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XBD4);
    // 0x8008B8D0: nop

    // 0x8008B8D4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008B8D8: swc1        $f10, 0xBD4($t0)
    MEM_W(0XBD4, ctx->r8) = ctx->f10.u32l;
    // 0x8008B8DC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008B8E0: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8008B8E4: lwc1        $f16, 0xBD4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XBD4);
    // 0x8008B8E8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8008B8EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008B8F0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8008B8F4: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8008B8F8: nop

    // 0x8008B8FC: bc1f        L_8008B968
    if (!c1cs) {
        // 0x8008B900: nop
    
            goto L_8008B968;
    }
    // 0x8008B900: nop

L_8008B904:
    // 0x8008B904: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008B908: nop

    // 0x8008B90C: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x8008B910: nop

    // 0x8008B914: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x8008B918: sh          $t4, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r12;
    // 0x8008B91C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008B920: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8008B924: lwc1        $f6, 0xBD4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XBD4);
    // 0x8008B928: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8008B92C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008B930: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008B934: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8008B938: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8008B93C: swc1        $f18, 0xBD4($t5)
    MEM_W(0XBD4, ctx->r13) = ctx->f18.u32l;
    // 0x8008B940: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008B944: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8008B948: lwc1        $f4, 0xBD4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XBD4);
    // 0x8008B94C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008B950: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008B954: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008B958: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8008B95C: nop

    // 0x8008B960: bc1t        L_8008B904
    if (c1cs) {
        // 0x8008B964: nop
    
            goto L_8008B904;
    }
    // 0x8008B964: nop

L_8008B968:
    // 0x8008B968: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B96C: nop

    // 0x8008B970: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x8008B974: bne         $at, $zero, L_8008B984
    if (ctx->r1 != 0) {
        // 0x8008B978: nop
    
            goto L_8008B984;
    }
    // 0x8008B978: nop

    // 0x8008B97C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8008B980: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008B984:
    // 0x8008B984: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B988: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B98C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8008B990: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B994: mflo        $t0
    ctx->r8 = lo;
    // 0x8008B998: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8008B99C: addiu       $t1, $t0, 0xBB
    ctx->r9 = ADD32(ctx->r8, 0XBB);
    // 0x8008B9A0: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8008B9A4: addiu       $t3, $zero, 0x82
    ctx->r11 = ADD32(0, 0X82);
    // 0x8008B9A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B9AC: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8008B9B0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008B9B4: nop

    // 0x8008B9B8: lhu         $t2, 0x2($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X2);
    // 0x8008B9BC: nop

    // 0x8008B9C0: andi        $t5, $t2, 0x1
    ctx->r13 = ctx->r10 & 0X1;
    // 0x8008B9C4: beq         $t5, $zero, L_8008B9E0
    if (ctx->r13 == 0) {
        // 0x8008B9C8: nop
    
            goto L_8008B9E0;
    }
    // 0x8008B9C8: nop

    // 0x8008B9CC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B9D0: jal         0x8008ECE4
    // 0x8008B9D4: addiu       $a0, $a0, -0xA9C
    ctx->r4 = ADD32(ctx->r4, -0XA9C);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8008B9D4: addiu       $a0, $a0, -0xA9C
    ctx->r4 = ADD32(ctx->r4, -0XA9C);
    after_7:
    // 0x8008B9D8: b           L_8008BA0C
    // 0x8008B9DC: nop

        goto L_8008BA0C;
    // 0x8008B9DC: nop

L_8008B9E0:
    // 0x8008B9E0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B9E4: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x8008B9E8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8008B9EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8008B9F0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8008B9F4: jal         0x800BCFCC
    // 0x8008B9F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_8;
    // 0x8008B9F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x8008B9FC: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x8008BA00: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
    // 0x8008BA04: jal         0x8008ECE4
    // 0x8008BA08: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8008BA08: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_9:
L_8008BA0C:
    // 0x8008BA0C: b           L_8008BA14
    // 0x8008BA10: nop

        goto L_8008BA14;
    // 0x8008BA10: nop

L_8008BA14:
    // 0x8008BA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BA18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008BA1C: jr          $ra
    // 0x8008BA20: nop

    return;
    // 0x8008BA20: nop

;}
RECOMP_FUNC void func_800972FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800972FC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80097300: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80097304: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80097308: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8009730C: jr          $ra
    // 0x80097310: nop

    return;
    // 0x80097310: nop

    // 0x80097314: jr          $ra
    // 0x80097318: nop

    return;
    // 0x80097318: nop

;}
RECOMP_FUNC void func_8008A788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A78C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008A794: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008A798: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008A79C: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x8008A7A0: lh          $t0, 0x73C($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X73C);
    // 0x8008A7A4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008A7A8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008A7AC: lh          $t9, 0x4664($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4664);
    // 0x8008A7B0: nop

    // 0x8008A7B4: bne         $t9, $t0, L_8008A7C4
    if (ctx->r25 != ctx->r8) {
        // 0x8008A7B8: nop
    
            goto L_8008A7C4;
    }
    // 0x8008A7B8: nop

    // 0x8008A7BC: b           L_8008A7F8
    // 0x8008A7C0: nop

        goto L_8008A7F8;
    // 0x8008A7C0: nop

L_8008A7C4:
    // 0x8008A7C4: jal         0x80031AC8
    // 0x8008A7C8: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x8008A7C8: nop

    after_0:
    // 0x8008A7CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008A7D0: bne         $v0, $at, L_8008A7E8
    if (ctx->r2 != ctx->r1) {
        // 0x8008A7D4: nop
    
            goto L_8008A7E8;
    }
    // 0x8008A7D4: nop

    // 0x8008A7D8: jal         0x800317E4
    // 0x8008A7DC: nop

    func_800317E4(rdram, ctx);
        goto after_1;
    // 0x8008A7DC: nop

    after_1:
    // 0x8008A7E0: b           L_8008A7F0
    // 0x8008A7E4: nop

        goto L_8008A7F0;
    // 0x8008A7E4: nop

L_8008A7E8:
    // 0x8008A7E8: jal         0x80031BB0
    // 0x8008A7EC: nop

    func_80031BB0(rdram, ctx);
        goto after_2;
    // 0x8008A7EC: nop

    after_2:
L_8008A7F0:
    // 0x8008A7F0: b           L_8008A7F8
    // 0x8008A7F4: nop

        goto L_8008A7F8;
    // 0x8008A7F4: nop

L_8008A7F8:
    // 0x8008A7F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A7FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A800: jr          $ra
    // 0x8008A804: nop

    return;
    // 0x8008A804: nop

;}
RECOMP_FUNC void func_80077834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077834: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077838: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007783C: nop

    // 0x80077840: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80077844: nop

    // 0x80077848: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007784C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077850: jr          $ra
    // 0x80077854: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077854: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077858: jr          $ra
    // 0x8007785C: nop

    return;
    // 0x8007785C: nop

    // 0x80077860: jr          $ra
    // 0x80077864: nop

    return;
    // 0x80077864: nop

;}
RECOMP_FUNC void func_8007268C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007268C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072694: jal         0x80061488
    // 0x80072698: addiu       $a0, $zero, 0x519
    ctx->r4 = ADD32(0, 0X519);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072698: addiu       $a0, $zero, 0x519
    ctx->r4 = ADD32(0, 0X519);
    after_0:
    // 0x8007269C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800726A0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800726A4: b           L_800726B4
    // 0x800726A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800726B4;
    // 0x800726A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800726AC: b           L_800726B4
    // 0x800726B0: nop

        goto L_800726B4;
    // 0x800726B0: nop

L_800726B4:
    // 0x800726B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800726B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800726BC: jr          $ra
    // 0x800726C0: nop

    return;
    // 0x800726C0: nop

;}
RECOMP_FUNC void func_80063BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063BE8: jal         0x8005F064
    // 0x80063BEC: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063BEC: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063BF0: b           L_80063C00
    // 0x80063BF4: nop

        goto L_80063C00;
    // 0x80063BF4: nop

    // 0x80063BF8: b           L_80063C00
    // 0x80063BFC: nop

        goto L_80063C00;
    // 0x80063BFC: nop

L_80063C00:
    // 0x80063C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063C08: jr          $ra
    // 0x80063C0C: nop

    return;
    // 0x80063C0C: nop

;}
RECOMP_FUNC void func_8006BFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BFA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BFA8: jal         0x8005F064
    // 0x8006BFAC: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BFAC: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x8006BFB0: b           L_8006BFC0
    // 0x8006BFB4: nop

        goto L_8006BFC0;
    // 0x8006BFB4: nop

    // 0x8006BFB8: b           L_8006BFC0
    // 0x8006BFBC: nop

        goto L_8006BFC0;
    // 0x8006BFBC: nop

L_8006BFC0:
    // 0x8006BFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BFC8: jr          $ra
    // 0x8006BFCC: nop

    return;
    // 0x8006BFCC: nop

;}
RECOMP_FUNC void func_80059BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BA0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80059BA4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80059BA8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80059BAC: lw          $t7, 0x306C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X306C);
    // 0x80059BB0: lh          $t6, 0x1B48($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1B48);
    // 0x80059BB4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80059BB8: bne         $t7, $zero, L_80059BC8
    if (ctx->r15 != 0) {
        // 0x80059BBC: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_80059BC8;
    }
    // 0x80059BBC: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80059BC0: blez        $t6, L_80059C2C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80059BC4: nop
    
            goto L_80059C2C;
    }
    // 0x80059BC4: nop

L_80059BC8:
    // 0x80059BC8: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80059BCC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80059BD0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80059BD4: nop

    // 0x80059BD8: bne         $t9, $at, L_80059C08
    if (ctx->r25 != ctx->r1) {
        // 0x80059BDC: nop
    
            goto L_80059C08;
    }
    // 0x80059BDC: nop

    // 0x80059BE0: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80059BE4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80059BE8: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80059BEC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80059BF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80059BF4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80059BF8: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80059BFC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80059C00: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80059C04: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_80059C08:
    // 0x80059C08: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x80059C0C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80059C10: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80059C14: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80059C18: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80059C1C: bne         $t2, $zero, L_80059BC8
    if (ctx->r10 != 0) {
        // 0x80059C20: sw          $t2, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r10;
            goto L_80059BC8;
    }
    // 0x80059C20: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80059C24: bgtz        $t4, L_80059BC8
    if (SIGNED(ctx->r12) > 0) {
        // 0x80059C28: nop
    
            goto L_80059BC8;
    }
    // 0x80059C28: nop

L_80059C2C:
    // 0x80059C2C: b           L_80059C34
    // 0x80059C30: nop

        goto L_80059C34;
    // 0x80059C30: nop

L_80059C34:
    // 0x80059C34: jr          $ra
    // 0x80059C38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80059C38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800BDE6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDE6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BDE70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDE74: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BDE78: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800BDE7C: jal         0x800C4270
    // 0x800BDE80: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800BDE80: nop

    after_0:
    // 0x800BDE84: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BDE88: nop

    // 0x800BDE8C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800BDE90: beq         $t7, $zero, L_800BDEA0
    if (ctx->r15 == 0) {
        // 0x800BDE94: nop
    
            goto L_800BDEA0;
    }
    // 0x800BDE94: nop

    // 0x800BDE98: jal         0x800BE068
    // 0x800BDE9C: nop

    func_800BE068(rdram, ctx);
        goto after_1;
    // 0x800BDE9C: nop

    after_1:
L_800BDEA0:
    // 0x800BDEA0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800BDEA4: nop

    // 0x800BDEA8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800BDEAC: beq         $t9, $zero, L_800BDEBC
    if (ctx->r25 == 0) {
        // 0x800BDEB0: nop
    
            goto L_800BDEBC;
    }
    // 0x800BDEB0: nop

    // 0x800BDEB4: jal         0x800BE08C
    // 0x800BDEB8: nop

    func_800BE08C(rdram, ctx);
        goto after_2;
    // 0x800BDEB8: nop

    after_2:
L_800BDEBC:
    // 0x800BDEBC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800BDEC0: nop

    // 0x800BDEC4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BDEC8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800BDECC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDED0: sw          $zero, 0x2528($at)
    MEM_W(0X2528, ctx->r1) = 0;
    // 0x800BDED4: jal         0x800C40D0
    // 0x800BDED8: nop

    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x800BDED8: nop

    after_3:
    // 0x800BDEDC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BDEE0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BDEE4: lw          $t3, 0x19AC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X19AC);
    // 0x800BDEE8: lw          $t2, 0x19A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X19A8);
    // 0x800BDEEC: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800BDEF0: subu        $t4, $v0, $t2
    ctx->r12 = SUB32(ctx->r2, ctx->r10);
    // 0x800BDEF4: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x800BDEF8: subu        $t5, $v1, $t3
    ctx->r13 = SUB32(ctx->r3, ctx->r11);
    // 0x800BDEFC: or          $t6, $t5, $zero
    ctx->r14 = ctx->r13 | 0;
    // 0x800BDF00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF04: sw          $t6, 0x251C($at)
    MEM_W(0X251C, ctx->r1) = ctx->r14;
    // 0x800BDF08: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BDF0C: lhu         $t7, 0x24FC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X24FC);
    // 0x800BDF10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF14: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x800BDF18: sh          $t8, 0x24FC($at)
    MEM_H(0X24FC, ctx->r1) = ctx->r24;
    // 0x800BDF1C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BDF20: lhu         $t9, 0x24FC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X24FC);
    // 0x800BDF24: nop

    // 0x800BDF28: beq         $t9, $zero, L_800BDF44
    if (ctx->r25 == 0) {
        // 0x800BDF2C: nop
    
            goto L_800BDF44;
    }
    // 0x800BDF2C: nop

    // 0x800BDF30: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x800BDF34: addiu       $t0, $t0, -0x5800
    ctx->r8 = ADD32(ctx->r8, -0X5800);
    // 0x800BDF38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF3C: b           L_800BDF54
    // 0x800BDF40: sw          $t0, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r8;
        goto L_800BDF54;
    // 0x800BDF40: sw          $t0, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r8;
L_800BDF44:
    // 0x800BDF44: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x800BDF48: addiu       $t1, $t1, 0x0
    ctx->r9 = ADD32(ctx->r9, 0X0);
    // 0x800BDF4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF50: sw          $t1, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r9;
L_800BDF54:
    // 0x800BDF54: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BDF58: lhu         $t2, 0x24FC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X24FC);
    // 0x800BDF5C: nop

    // 0x800BDF60: beq         $t2, $zero, L_800BDF7C
    if (ctx->r10 == 0) {
        // 0x800BDF64: nop
    
            goto L_800BDF7C;
    }
    // 0x800BDF64: nop

    // 0x800BDF68: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x800BDF6C: addiu       $t3, $t3, 0x0
    ctx->r11 = ADD32(ctx->r11, 0X0);
    // 0x800BDF70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF74: b           L_800BDF8C
    // 0x800BDF78: sw          $t3, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r11;
        goto L_800BDF8C;
    // 0x800BDF78: sw          $t3, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r11;
L_800BDF7C:
    // 0x800BDF7C: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x800BDF80: addiu       $t4, $t4, -0x5800
    ctx->r12 = ADD32(ctx->r12, -0X5800);
    // 0x800BDF84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDF88: sw          $t4, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r12;
L_800BDF8C:
    // 0x800BDF8C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BDF90: lw          $a0, 0x24D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D0);
    // 0x800BDF94: jal         0x8008ECCC
    // 0x800BDF98: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_4;
    // 0x800BDF98: nop

    after_4:
    // 0x800BDF9C: jal         0x800C40D0
    // 0x800BDFA0: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x800BDFA0: nop

    after_5:
    // 0x800BDFA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDFA8: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x800BDFAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDFB0: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
    // 0x800BDFB4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BDFB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BDFBC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800BDFC0: lw          $t6, 0x2554($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2554);
    // 0x800BDFC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BDFC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDFCC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDFD0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BDFD4: swc1        $f6, 0x2538($at)
    MEM_W(0X2538, ctx->r1) = ctx->f6.u32l;
    // 0x800BDFD8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BDFDC: lw          $t8, 0x2554($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2554);
    // 0x800BDFE0: nop

    // 0x800BDFE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BDFE8: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x800BDFEC: beq         $at, $zero, L_800BE000
    if (ctx->r1 == 0) {
        // 0x800BDFF0: nop
    
            goto L_800BE000;
    }
    // 0x800BDFF0: nop

    // 0x800BDFF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDFF8: b           L_800BE008
    // 0x800BDFFC: sw          $t9, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = ctx->r25;
        goto L_800BE008;
    // 0x800BDFFC: sw          $t9, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = ctx->r25;
L_800BE000:
    // 0x800BE000: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE004: sw          $zero, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = 0;
L_800BE008:
    // 0x800BE008: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BE00C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800BE010: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_800BE014:
    // 0x800BE014: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BE018: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE01C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BE020: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800BE024: lwc1        $f16, 0x2538($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2538);
    // 0x800BE028: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BE02C: nop

    // 0x800BE030: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800BE034: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800BE038: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BE03C: nop

    // 0x800BE040: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BE044: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800BE048: bne         $at, $zero, L_800BE014
    if (ctx->r1 != 0) {
        // 0x800BE04C: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_800BE014;
    }
    // 0x800BE04C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BE050: b           L_800BE058
    // 0x800BE054: nop

        goto L_800BE058;
    // 0x800BE054: nop

L_800BE058:
    // 0x800BE058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE05C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE060: jr          $ra
    // 0x800BE064: nop

    return;
    // 0x800BE064: nop

;}
RECOMP_FUNC void func_80065B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065B8C: jal         0x80061488
    // 0x80065B90: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065B90: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065B94: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065B98: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065B9C: b           L_80065BAC
    // 0x80065BA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065BAC;
    // 0x80065BA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065BA4: b           L_80065BAC
    // 0x80065BA8: nop

        goto L_80065BAC;
    // 0x80065BA8: nop

L_80065BAC:
    // 0x80065BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065BB4: jr          $ra
    // 0x80065BB8: nop

    return;
    // 0x80065BB8: nop

;}
RECOMP_FUNC void func_8006F40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F40C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F410: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F414: nop

    // 0x8006F418: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F41C: nop

    // 0x8006F420: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F424: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F428: jr          $ra
    // 0x8006F42C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F42C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F430: jr          $ra
    // 0x8006F434: nop

    return;
    // 0x8006F434: nop

    // 0x8006F438: jr          $ra
    // 0x8006F43C: nop

    return;
    // 0x8006F43C: nop

;}
RECOMP_FUNC void __unmapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D23E0: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800D23E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D23E8: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
    // 0x800D23EC: beq         $v1, $zero, L_800D2448
    if (ctx->r3 == 0) {
        // 0x800D23F0: nop
    
            goto L_800D2448;
    }
    // 0x800D23F0: nop

L_800D23F4:
    // 0x800D23F4: bnel        $v1, $a2, L_800D243C
    if (ctx->r3 != ctx->r6) {
        // 0x800D23F8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800D243C;
    }
    goto skip_0;
    // 0x800D23F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x800D23FC: beql        $v0, $zero, L_800D2414
    if (ctx->r2 == 0) {
        // 0x800D2400: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_800D2414;
    }
    goto skip_1;
    // 0x800D2400: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800D2404: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D2408: b           L_800D2418
    // 0x800D240C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_800D2418;
    // 0x800D240C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D2410: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_800D2414:
    // 0x800D2414: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
L_800D2418:
    // 0x800D2418: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x800D241C: bnel        $v1, $t8, L_800D242C
    if (ctx->r3 != ctx->r24) {
        // 0x800D2420: lw          $t9, 0x6C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X6C);
            goto L_800D242C;
    }
    goto skip_2;
    // 0x800D2420: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    skip_2:
    // 0x800D2424: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
    // 0x800D2428: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
L_800D242C:
    // 0x800D242C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D2430: jr          $ra
    // 0x800D2434: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    return;
    // 0x800D2434: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x800D2438: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D243C:
    // 0x800D243C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800D2440: bne         $v1, $zero, L_800D23F4
    if (ctx->r3 != 0) {
        // 0x800D2444: nop
    
            goto L_800D23F4;
    }
    // 0x800D2444: nop

L_800D2448:
    // 0x800D2448: jr          $ra
    // 0x800D244C: nop

    return;
    // 0x800D244C: nop

;}
RECOMP_FUNC void func_8001AE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001AE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AE98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001AE9C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001AEA0: nop

    // 0x8001AEA4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8001AEA8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8001AEAC: nop

    // 0x8001AEB0: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x8001AEB4: nop

    // 0x8001AEB8: beq         $t8, $zero, L_8001AEE0
    if (ctx->r24 == 0) {
        // 0x8001AEBC: nop
    
            goto L_8001AEE0;
    }
    // 0x8001AEBC: nop

    // 0x8001AEC0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8001AEC4: nop

    // 0x8001AEC8: lw          $a0, 0x20C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20C);
    // 0x8001AECC: jal         0x800BC980
    // 0x8001AED0: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x8001AED0: nop

    after_0:
    // 0x8001AED4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001AED8: nop

    // 0x8001AEDC: sw          $zero, 0x20C($t0)
    MEM_W(0X20C, ctx->r8) = 0;
L_8001AEE0:
    // 0x8001AEE0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AEE4: nop

    // 0x8001AEE8: lw          $t2, 0x12C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12C);
    // 0x8001AEEC: nop

    // 0x8001AEF0: beq         $t2, $zero, L_8001AF18
    if (ctx->r10 == 0) {
        // 0x8001AEF4: nop
    
            goto L_8001AF18;
    }
    // 0x8001AEF4: nop

    // 0x8001AEF8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AEFC: nop

    // 0x8001AF00: lw          $a0, 0x12C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X12C);
    // 0x8001AF04: jal         0x800BC980
    // 0x8001AF08: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x8001AF08: nop

    after_1:
    // 0x8001AF0C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF10: nop

    // 0x8001AF14: sw          $zero, 0x12C($t4)
    MEM_W(0X12C, ctx->r12) = 0;
L_8001AF18:
    // 0x8001AF18: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF1C: nop

    // 0x8001AF20: lw          $t6, 0x130($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X130);
    // 0x8001AF24: nop

    // 0x8001AF28: beq         $t6, $zero, L_8001AF50
    if (ctx->r14 == 0) {
        // 0x8001AF2C: nop
    
            goto L_8001AF50;
    }
    // 0x8001AF2C: nop

    // 0x8001AF30: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF34: nop

    // 0x8001AF38: lw          $a0, 0x130($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X130);
    // 0x8001AF3C: jal         0x800BC980
    // 0x8001AF40: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8001AF40: nop

    after_2:
    // 0x8001AF44: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF48: nop

    // 0x8001AF4C: sw          $zero, 0x130($t8)
    MEM_W(0X130, ctx->r24) = 0;
L_8001AF50:
    // 0x8001AF50: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF54: nop

    // 0x8001AF58: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x8001AF5C: nop

    // 0x8001AF60: beq         $t0, $zero, L_8001AF88
    if (ctx->r8 == 0) {
        // 0x8001AF64: nop
    
            goto L_8001AF88;
    }
    // 0x8001AF64: nop

    // 0x8001AF68: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF6C: nop

    // 0x8001AF70: lw          $a0, 0x138($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X138);
    // 0x8001AF74: jal         0x800BC980
    // 0x8001AF78: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x8001AF78: nop

    after_3:
    // 0x8001AF7C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF80: nop

    // 0x8001AF84: sw          $zero, 0x138($t2)
    MEM_W(0X138, ctx->r10) = 0;
L_8001AF88:
    // 0x8001AF88: b           L_8001AF90
    // 0x8001AF8C: nop

        goto L_8001AF90;
    // 0x8001AF8C: nop

L_8001AF90:
    // 0x8001AF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001AF98: jr          $ra
    // 0x8001AF9C: nop

    return;
    // 0x8001AF9C: nop

;}
RECOMP_FUNC void func_80072760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072760: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072764: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072768: nop

    // 0x8007276C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80072770: nop

    // 0x80072774: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072778: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007277C: jr          $ra
    // 0x80072780: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072780: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072784: jr          $ra
    // 0x80072788: nop

    return;
    // 0x80072788: nop

    // 0x8007278C: jr          $ra
    // 0x80072790: nop

    return;
    // 0x80072790: nop

;}
RECOMP_FUNC void func_80015E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015E50: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80015E54: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80015E58:
    // 0x80015E58: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80015E5C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80015E60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80015E64: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80015E68: sw          $zero, -0x4530($at)
    MEM_W(-0X4530, ctx->r1) = 0;
    // 0x80015E6C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80015E70: nop

    // 0x80015E74: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80015E78: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80015E7C: bne         $at, $zero, L_80015E58
    if (ctx->r1 != 0) {
        // 0x80015E80: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_80015E58;
    }
    // 0x80015E80: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80015E84: b           L_80015E8C
    // 0x80015E88: nop

        goto L_80015E8C;
    // 0x80015E88: nop

L_80015E8C:
    // 0x80015E8C: jr          $ra
    // 0x80015E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80015E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800686AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800686AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800686B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800686B4: jal         0x80061488
    // 0x800686B8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800686B8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_0:
    // 0x800686BC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800686C0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800686C4: b           L_800686D4
    // 0x800686C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800686D4;
    // 0x800686C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800686CC: b           L_800686D4
    // 0x800686D0: nop

        goto L_800686D4;
    // 0x800686D0: nop

L_800686D4:
    // 0x800686D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800686D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800686DC: jr          $ra
    // 0x800686E0: nop

    return;
    // 0x800686E0: nop

;}
RECOMP_FUNC void func_80067890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067898: jal         0x80061488
    // 0x8006789C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006789C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x800678A0: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x800678A4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800678A8: b           L_800678B8
    // 0x800678AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800678B8;
    // 0x800678AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800678B0: b           L_800678B8
    // 0x800678B4: nop

        goto L_800678B8;
    // 0x800678B4: nop

L_800678B8:
    // 0x800678B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800678BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800678C0: jr          $ra
    // 0x800678C4: nop

    return;
    // 0x800678C4: nop

;}
RECOMP_FUNC void func_80079910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079918: jal         0x80080738
    // 0x8007991C: nop

    func_80080738(rdram, ctx);
        goto after_0;
    // 0x8007991C: nop

    after_0:
    // 0x80079920: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079924: sw          $zero, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = 0;
    // 0x80079928: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007992C: sw          $zero, 0x70F0($at)
    MEM_W(0X70F0, ctx->r1) = 0;
    // 0x80079930: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079934: sw          $zero, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = 0;
    // 0x80079938: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007993C: sw          $zero, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = 0;
    // 0x80079940: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079944: lh          $t6, 0x72AC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72AC);
    // 0x80079948: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007994C: sw          $t6, 0x7100($at)
    MEM_W(0X7100, ctx->r1) = ctx->r14;
    // 0x80079950: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079954: lh          $t7, 0x72B4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X72B4);
    // 0x80079958: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007995C: sw          $t7, 0x7104($at)
    MEM_W(0X7104, ctx->r1) = ctx->r15;
    // 0x80079960: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079964: sh          $zero, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = 0;
    // 0x80079968: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007996C: sh          $zero, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = 0;
    // 0x80079970: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079974: sb          $zero, 0x7108($at)
    MEM_B(0X7108, ctx->r1) = 0;
    // 0x80079978: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007997C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079980: swc1        $f4, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f4.u32l;
    // 0x80079984: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80079988: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007998C: swc1        $f6, 0x711C($at)
    MEM_W(0X711C, ctx->r1) = ctx->f6.u32l;
    // 0x80079990: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079994: swc1        $f6, 0x7118($at)
    MEM_W(0X7118, ctx->r1) = ctx->f6.u32l;
    // 0x80079998: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007999C: swc1        $f6, 0x7114($at)
    MEM_W(0X7114, ctx->r1) = ctx->f6.u32l;
    // 0x800799A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799A4: swc1        $f6, 0x7110($at)
    MEM_W(0X7110, ctx->r1) = ctx->f6.u32l;
    // 0x800799A8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800799AC: addiu       $t8, $t8, 0x70F0
    ctx->r24 = ADD32(ctx->r24, 0X70F0);
    // 0x800799B0: sh          $zero, 0x3C($t8)
    MEM_H(0X3C, ctx->r24) = 0;
    // 0x800799B4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800799B8: addiu       $t9, $t9, 0x70F0
    ctx->r25 = ADD32(ctx->r25, 0X70F0);
    // 0x800799BC: sh          $zero, 0x3E($t9)
    MEM_H(0X3E, ctx->r25) = 0;
    // 0x800799C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799C4: sh          $zero, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = 0;
    // 0x800799C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799CC: sh          $zero, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = 0;
    // 0x800799D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800799D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799D8: swc1        $f8, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f8.u32l;
    // 0x800799DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799E0: sb          $zero, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = 0;
    // 0x800799E4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800799E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799EC: sb          $t0, 0x7143($at)
    MEM_B(0X7143, ctx->r1) = ctx->r8;
    // 0x800799F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800799F4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800799F8: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
    // 0x800799FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80079A00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079A04: swc1        $f10, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f10.u32l;
    // 0x80079A08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079A0C: lh          $t2, 0x72AC($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X72AC);
    // 0x80079A10: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80079A14: bne         $t2, $at, L_80079A30
    if (ctx->r10 != ctx->r1) {
        // 0x80079A18: nop
    
            goto L_80079A30;
    }
    // 0x80079A18: nop

    // 0x80079A1C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80079A20: lh          $t3, 0x72B4($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X72B4);
    // 0x80079A24: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80079A28: beq         $t3, $at, L_80079A58
    if (ctx->r11 == ctx->r1) {
        // 0x80079A2C: nop
    
            goto L_80079A58;
    }
    // 0x80079A2C: nop

L_80079A30:
    // 0x80079A30: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80079A34: lh          $t4, 0x72AC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X72AC);
    // 0x80079A38: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80079A3C: bne         $t4, $at, L_80079B68
    if (ctx->r12 != ctx->r1) {
        // 0x80079A40: nop
    
            goto L_80079B68;
    }
    // 0x80079A40: nop

    // 0x80079A44: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079A48: lh          $t5, 0x72B4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X72B4);
    // 0x80079A4C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80079A50: bne         $t5, $at, L_80079B68
    if (ctx->r13 != ctx->r1) {
        // 0x80079A54: nop
    
            goto L_80079B68;
    }
    // 0x80079A54: nop

L_80079A58:
    // 0x80079A58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079A5C: sb          $zero, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = 0;
    // 0x80079A60: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079A64: lh          $t6, 0x72AC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72AC);
    // 0x80079A68: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80079A6C: bne         $t6, $at, L_80079AA0
    if (ctx->r14 != ctx->r1) {
        // 0x80079A70: nop
    
            goto L_80079AA0;
    }
    // 0x80079A70: nop

    // 0x80079A74: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079A78: lh          $t7, 0x72B4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X72B4);
    // 0x80079A7C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80079A80: bne         $t7, $at, L_80079AA0
    if (ctx->r15 != ctx->r1) {
        // 0x80079A84: nop
    
            goto L_80079AA0;
    }
    // 0x80079A84: nop

    // 0x80079A88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079A8C: sw          $zero, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = 0;
    // 0x80079A90: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80079A94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079A98: b           L_80079AB8
    // 0x80079A9C: sh          $t8, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r24;
        goto L_80079AB8;
    // 0x80079A9C: sh          $t8, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r24;
L_80079AA0:
    // 0x80079AA0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80079AA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079AA8: sw          $t9, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = ctx->r25;
    // 0x80079AAC: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x80079AB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079AB4: sh          $t0, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r8;
L_80079AB8:
    // 0x80079AB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079ABC: sh          $zero, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = 0;
    // 0x80079AC0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80079AC4: lw          $t1, 0x70F8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F8);
    // 0x80079AC8: nop

    // 0x80079ACC: bne         $t1, $zero, L_80079B10
    if (ctx->r9 != 0) {
        // 0x80079AD0: nop
    
            goto L_80079B10;
    }
    // 0x80079AD0: nop

    // 0x80079AD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80079AD8: jal         0x8007A514
    // 0x80079ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8007A514(rdram, ctx);
        goto after_1;
    // 0x80079ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80079AE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079AE4: sw          $v0, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r2;
    // 0x80079AE8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079AEC: lw          $t2, 0x70FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70FC);
    // 0x80079AF0: nop

    // 0x80079AF4: bne         $t2, $zero, L_80079B10
    if (ctx->r10 != 0) {
        // 0x80079AF8: nop
    
            goto L_80079B10;
    }
    // 0x80079AF8: nop

    // 0x80079AFC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80079B00: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x80079B04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079B08: ori         $t4, $t3, 0x100
    ctx->r12 = ctx->r11 | 0X100;
    // 0x80079B0C: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
L_80079B10:
    // 0x80079B10: jal         0x800BC6EC
    // 0x80079B14: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80079B14: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_2:
    // 0x80079B18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079B1C: sw          $v0, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = ctx->r2;
    // 0x80079B20: jal         0x800BC6EC
    // 0x80079B24: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80079B24: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_3:
    // 0x80079B28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079B2C: sw          $v0, 0x70F0($at)
    MEM_W(0X70F0, ctx->r1) = ctx->r2;
    // 0x80079B30: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079B34: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x80079B38: jal         0x80099E2C
    // 0x80079B3C: nop

    func_80099E2C(rdram, ctx);
        goto after_4;
    // 0x80079B3C: nop

    after_4:
    // 0x80079B40: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079B44: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80079B48: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x80079B4C: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x80079B50: jal         0x800B1B04
    // 0x80079B54: nop

    func_800B1B04(rdram, ctx);
        goto after_5;
    // 0x80079B54: nop

    after_5:
    // 0x80079B58: jal         0x8007B710
    // 0x80079B5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007B710(rdram, ctx);
        goto after_6;
    // 0x80079B5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80079B60: jal         0x8003168C
    // 0x80079B64: nop

    func_8003168C(rdram, ctx);
        goto after_7;
    // 0x80079B64: nop

    after_7:
L_80079B68:
    // 0x80079B68: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079B6C: lh          $t5, 0x72AC($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X72AC);
    // 0x80079B70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80079B74: bne         $t5, $at, L_80079C64
    if (ctx->r13 != ctx->r1) {
        // 0x80079B78: nop
    
            goto L_80079C64;
    }
    // 0x80079B78: nop

    // 0x80079B7C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079B80: lh          $t6, 0x72B4($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72B4);
    // 0x80079B84: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80079B88: beq         $t6, $at, L_80079B9C
    if (ctx->r14 == ctx->r1) {
        // 0x80079B8C: nop
    
            goto L_80079B9C;
    }
    // 0x80079B8C: nop

    // 0x80079B90: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x80079B94: bne         $t6, $at, L_80079C64
    if (ctx->r14 != ctx->r1) {
        // 0x80079B98: nop
    
            goto L_80079C64;
    }
    // 0x80079B98: nop

L_80079B9C:
    // 0x80079B9C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80079BA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079BA4: sh          $t7, 0x7144($at)
    MEM_H(0X7144, ctx->r1) = ctx->r15;
    // 0x80079BA8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80079BAC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079BB0: sb          $t8, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = ctx->r24;
    // 0x80079BB4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80079BB8: lh          $t9, 0x72B4($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X72B4);
    // 0x80079BBC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80079BC0: bne         $t9, $at, L_80079BD8
    if (ctx->r25 != ctx->r1) {
        // 0x80079BC4: nop
    
            goto L_80079BD8;
    }
    // 0x80079BC4: nop

    // 0x80079BC8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80079BCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079BD0: b           L_80079C08
    // 0x80079BD4: sw          $t0, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = ctx->r8;
        goto L_80079C08;
    // 0x80079BD4: sw          $t0, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = ctx->r8;
L_80079BD8:
    // 0x80079BD8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80079BDC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079BE0: sw          $t1, 0x70F8($at)
    MEM_W(0X70F8, ctx->r1) = ctx->r9;
    // 0x80079BE4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079BE8: lh          $t2, 0x7132($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7132);
    // 0x80079BEC: nop

    // 0x80079BF0: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80079BF4: beq         $at, $zero, L_80079C08
    if (ctx->r1 == 0) {
        // 0x80079BF8: nop
    
            goto L_80079C08;
    }
    // 0x80079BF8: nop

    // 0x80079BFC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80079C00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079C04: sh          $t3, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r11;
L_80079C08:
    // 0x80079C08: jal         0x800A3918
    // 0x80079C0C: nop

    func_800A3918(rdram, ctx);
        goto after_8;
    // 0x80079C0C: nop

    after_8:
    // 0x80079C10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079C14: sw          $v0, 0x70F4($at)
    MEM_W(0X70F4, ctx->r1) = ctx->r2;
    // 0x80079C18: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079C1C: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x80079C20: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80079C24: sh          $t4, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r12;
    // 0x80079C28: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079C2C: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x80079C30: addiu       $t6, $zero, 0x7D0
    ctx->r14 = ADD32(0, 0X7D0);
    // 0x80079C34: sw          $t6, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r14;
    // 0x80079C38: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80079C3C: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x80079C40: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x80079C44: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x80079C48: nop

    // 0x80079C4C: sh          $t8, 0x1FE($t0)
    MEM_H(0X1FE, ctx->r8) = ctx->r24;
    // 0x80079C50: addiu       $t1, $zero, 0x29
    ctx->r9 = ADD32(0, 0X29);
    // 0x80079C54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079C58: sh          $t1, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r9;
    // 0x80079C5C: jal         0x8007B710
    // 0x80079C60: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_8007B710(rdram, ctx);
        goto after_9;
    // 0x80079C60: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_9:
L_80079C64:
    // 0x80079C64: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80079C68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80079C6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80079C70: swc1        $f16, -0x3890($at)
    MEM_W(-0X3890, ctx->r1) = ctx->f16.u32l;
    // 0x80079C74: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x80079C78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80079C7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80079C80: swc1        $f18, -0x388C($at)
    MEM_W(-0X388C, ctx->r1) = ctx->f18.u32l;
    // 0x80079C84: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80079C88: jal         0x8001A690
    // 0x80079C8C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    func_8001A690(rdram, ctx);
        goto after_10;
    // 0x80079C8C: addiu       $a0, $a0, -0x3A40
    ctx->r4 = ADD32(ctx->r4, -0X3A40);
    after_10:
    // 0x80079C90: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80079C94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80079C98: sh          $t2, -0x397C($at)
    MEM_H(-0X397C, ctx->r1) = ctx->r10;
    // 0x80079C9C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80079CA0: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80079CA4: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x80079CA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80079CAC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80079CB0: sh          $t5, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r13;
    // 0x80079CB4: b           L_80079CBC
    // 0x80079CB8: nop

        goto L_80079CBC;
    // 0x80079CB8: nop

L_80079CBC:
    // 0x80079CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80079CC4: jr          $ra
    // 0x80079CC8: nop

    return;
    // 0x80079CC8: nop

;}
RECOMP_FUNC void func_800AF184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AF188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AF18C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800AF190: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800AF194: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800AF198: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AF19C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF1A0: swc1        $f4, 0x430($at)
    MEM_W(0X430, ctx->r1) = ctx->f4.u32l;
    // 0x800AF1A4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AF1A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF1AC: swc1        $f6, 0x438($at)
    MEM_W(0X438, ctx->r1) = ctx->f6.u32l;
    // 0x800AF1B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AF1B4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF1B8: lwc1        $f17, -0x6E0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X6E0);
    // 0x800AF1BC: lwc1        $f16, -0x6DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6DC);
    // 0x800AF1C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AF1C4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800AF1C8: jal         0x800C3650
    // 0x800AF1CC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    func_800C3650(rdram, ctx);
        goto after_0;
    // 0x800AF1CC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x800AF1D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF1D4: swc1        $f0, 0x440($at)
    MEM_W(0X440, ctx->r1) = ctx->f0.u32l;
    // 0x800AF1D8: b           L_800AF1E0
    // 0x800AF1DC: nop

        goto L_800AF1E0;
    // 0x800AF1DC: nop

L_800AF1E0:
    // 0x800AF1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AF1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AF1E8: jr          $ra
    // 0x800AF1EC: nop

    return;
    // 0x800AF1EC: nop

;}
RECOMP_FUNC void func_800B5730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5738: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B573C: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B5740: nop

    // 0x800B5744: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800B5748: nop

    // 0x800B574C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800B5750: beq         $t8, $zero, L_800B5768
    if (ctx->r24 == 0) {
        // 0x800B5754: nop
    
            goto L_800B5768;
    }
    // 0x800B5754: nop

    // 0x800B5758: jal         0x80031728
    // 0x800B575C: nop

    func_80031728(rdram, ctx);
        goto after_0;
    // 0x800B575C: nop

    after_0:
    // 0x800B5760: b           L_800B57A0
    // 0x800B5764: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B57A0;
    // 0x800B5764: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B5768:
    // 0x800B5768: jal         0x800B57B0
    // 0x800B576C: nop

    func_800B57B0(rdram, ctx);
        goto after_1;
    // 0x800B576C: nop

    after_1:
    // 0x800B5770: jal         0x800B5AA0
    // 0x800B5774: nop

    func_800B5AA0(rdram, ctx);
        goto after_2;
    // 0x800B5774: nop

    after_2:
    // 0x800B5778: jal         0x800B5AF0
    // 0x800B577C: nop

    func_800B5AF0(rdram, ctx);
        goto after_3;
    // 0x800B577C: nop

    after_3:
    // 0x800B5780: beq         $v0, $zero, L_800B5790
    if (ctx->r2 == 0) {
        // 0x800B5784: nop
    
            goto L_800B5790;
    }
    // 0x800B5784: nop

    // 0x800B5788: jal         0x800B5FB4
    // 0x800B578C: nop

    func_800B5FB4(rdram, ctx);
        goto after_4;
    // 0x800B578C: nop

    after_4:
L_800B5790:
    // 0x800B5790: b           L_800B57A0
    // 0x800B5794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B57A0;
    // 0x800B5794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B5798: b           L_800B57A0
    // 0x800B579C: nop

        goto L_800B57A0;
    // 0x800B579C: nop

L_800B57A0:
    // 0x800B57A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B57A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B57A8: jr          $ra
    // 0x800B57AC: nop

    return;
    // 0x800B57AC: nop

;}
RECOMP_FUNC void func_80068C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068C40: jal         0x80061488
    // 0x80068C44: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068C44: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    after_0:
    // 0x80068C48: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068C4C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068C50: b           L_80068C60
    // 0x80068C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068C60;
    // 0x80068C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068C58: b           L_80068C60
    // 0x80068C5C: nop

        goto L_80068C60;
    // 0x80068C5C: nop

L_80068C60:
    // 0x80068C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068C68: jr          $ra
    // 0x80068C6C: nop

    return;
    // 0x80068C6C: nop

;}
RECOMP_FUNC void func_8006D9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D9DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D9E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D9E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D9E8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D9EC: nop

    // 0x8006D9F0: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006D9F4: nop

    // 0x8006D9F8: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D9FC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006DA00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DA04: beq         $v0, $zero, L_8006DA38
    if (ctx->r2 == 0) {
        // 0x8006DA08: nop
    
            goto L_8006DA38;
    }
    // 0x8006DA08: nop

    // 0x8006DA0C: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x8006DA10: nop

    // 0x8006DA14: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006DA18: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006DA1C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006DA20: beq         $v0, $zero, L_8006DA38
    if (ctx->r2 == 0) {
        // 0x8006DA24: nop
    
            goto L_8006DA38;
    }
    // 0x8006DA24: nop

    // 0x8006DA28: jal         0x8005F064
    // 0x8006DA2C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006DA2C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    after_0:
    // 0x8006DA30: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006DA34: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006DA38:
    // 0x8006DA38: b           L_8006DA48
    // 0x8006DA3C: nop

        goto L_8006DA48;
    // 0x8006DA3C: nop

    // 0x8006DA40: b           L_8006DA48
    // 0x8006DA44: nop

        goto L_8006DA48;
    // 0x8006DA44: nop

L_8006DA48:
    // 0x8006DA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DA50: jr          $ra
    // 0x8006DA54: nop

    return;
    // 0x8006DA54: nop

;}
RECOMP_FUNC void func_8006DD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DD1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DD20: jal         0x80061348
    // 0x8006DD24: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DD24: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_0:
    // 0x8006DD28: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DD2C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DD30: beq         $v0, $zero, L_8006DD48
    if (ctx->r2 == 0) {
        // 0x8006DD34: nop
    
            goto L_8006DD48;
    }
    // 0x8006DD34: nop

    // 0x8006DD38: jal         0x80061348
    // 0x8006DD3C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DD3C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_1:
    // 0x8006DD40: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DD44: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DD48:
    // 0x8006DD48: b           L_8006DD58
    // 0x8006DD4C: nop

        goto L_8006DD58;
    // 0x8006DD4C: nop

    // 0x8006DD50: b           L_8006DD58
    // 0x8006DD54: nop

        goto L_8006DD58;
    // 0x8006DD54: nop

L_8006DD58:
    // 0x8006DD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DD60: jr          $ra
    // 0x8006DD64: nop

    return;
    // 0x8006DD64: nop

;}
RECOMP_FUNC void func_80098AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098AD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098AE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80098AE4: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80098AE8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80098AEC: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80098AF0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098AF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80098AF8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80098AFC: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80098B00: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098B04: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80098B08: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x80098B0C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80098B10: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80098B14: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80098B18: nop

    // 0x80098B1C: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80098B20: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x80098B24: nop

    // 0x80098B28: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80098B2C: bne         $t2, $zero, L_80098B3C
    if (ctx->r10 != 0) {
        // 0x80098B30: nop
    
            goto L_80098B3C;
    }
    // 0x80098B30: nop

    // 0x80098B34: b           L_80098BA8
    // 0x80098B38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098BA8;
    // 0x80098B38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098B3C:
    // 0x80098B3C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80098B40: nop

    // 0x80098B44: addiu       $t4, $t3, 0x7FFF
    ctx->r12 = ADD32(ctx->r11, 0X7FFF);
    // 0x80098B48: lbu         $t4, 0x2E9($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X2E9);
    // 0x80098B4C: nop

    // 0x80098B50: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x80098B54: bne         $t5, $zero, L_80098B64
    if (ctx->r13 != 0) {
        // 0x80098B58: nop
    
            goto L_80098B64;
    }
    // 0x80098B58: nop

    // 0x80098B5C: b           L_80098BA8
    // 0x80098B60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098BA8;
    // 0x80098B60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098B64:
    // 0x80098B64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80098B68: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80098B6C: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x80098B70: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x80098B74: jal         0x8009731C
    // 0x80098B78: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    Scheduler_RemoveClient(rdram, ctx);
        goto after_0;
    // 0x80098B78: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    after_0:
    // 0x80098B7C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80098B80: nop

    // 0x80098B84: addiu       $t7, $t6, 0x7FFF
    ctx->r15 = ADD32(ctx->r14, 0X7FFF);
    // 0x80098B88: lbu         $t7, 0x2E9($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2E9);
    // 0x80098B8C: addiu       $at, $t6, 0x7FFF
    ctx->r1 = ADD32(ctx->r14, 0X7FFF);
    // 0x80098B90: andi        $t8, $t7, 0xFD
    ctx->r24 = ctx->r15 & 0XFD;
    // 0x80098B94: sb          $t8, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r24;
    // 0x80098B98: b           L_80098BA8
    // 0x80098B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098BA8;
    // 0x80098B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098BA0: b           L_80098BA8
    // 0x80098BA4: nop

        goto L_80098BA8;
    // 0x80098BA4: nop

L_80098BA8:
    // 0x80098BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098BAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098BB0: jr          $ra
    // 0x80098BB4: nop

    return;
    // 0x80098BB4: nop

;}
RECOMP_FUNC void func_80076CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076CE4: jal         0x80061488
    // 0x80076CE8: addiu       $a0, $zero, 0x551
    ctx->r4 = ADD32(0, 0X551);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076CE8: addiu       $a0, $zero, 0x551
    ctx->r4 = ADD32(0, 0X551);
    after_0:
    // 0x80076CEC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076CF0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076CF4: b           L_80076D04
    // 0x80076CF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076D04;
    // 0x80076CF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076CFC: b           L_80076D04
    // 0x80076D00: nop

        goto L_80076D04;
    // 0x80076D00: nop

L_80076D04:
    // 0x80076D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076D0C: jr          $ra
    // 0x80076D10: nop

    return;
    // 0x80076D10: nop

;}
RECOMP_FUNC void func_8007DF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DF3C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8007DF40: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8007DF44: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8007DF48: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8007DF4C: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8007DF50: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8007DF54: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8007DF58: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8007DF5C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8007DF60: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8007DF64: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8007DF68: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8007DF6C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007DF70: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8007DF74: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007DF78: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007DF7C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007DF80: bne         $t6, $at, L_8007DFA8
    if (ctx->r14 != ctx->r1) {
        // 0x8007DF84: nop
    
            goto L_8007DFA8;
    }
    // 0x8007DF84: nop

    // 0x8007DF88: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007DF8C: lw          $t7, 0x7104($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7104);
    // 0x8007DF90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007DF94: beq         $t7, $at, L_8007DFB0
    if (ctx->r15 == ctx->r1) {
        // 0x8007DF98: nop
    
            goto L_8007DFB0;
    }
    // 0x8007DF98: nop

    // 0x8007DF9C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007DFA0: beq         $t7, $at, L_8007DFB0
    if (ctx->r15 == ctx->r1) {
        // 0x8007DFA4: nop
    
            goto L_8007DFB0;
    }
    // 0x8007DFA4: nop

L_8007DFA8:
    // 0x8007DFA8: b           L_8007E914
    // 0x8007DFAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E914;
    // 0x8007DFAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007DFB0:
    // 0x8007DFB0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007DFB4: lb          $t8, 0x7142($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X7142);
    // 0x8007DFB8: nop

    // 0x8007DFBC: bgez        $t8, L_8007DFCC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007DFC0: nop
    
            goto L_8007DFCC;
    }
    // 0x8007DFC0: nop

    // 0x8007DFC4: b           L_8007E914
    // 0x8007DFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E914;
    // 0x8007DFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007DFCC:
    // 0x8007DFCC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007DFD0: lb          $t9, 0x7142($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7142);
    // 0x8007DFD4: nop

    // 0x8007DFD8: sb          $t9, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r25;
    // 0x8007DFDC: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x8007DFE0: nop

    // 0x8007DFE4: beq         $t0, $zero, L_8007E158
    if (ctx->r8 == 0) {
        // 0x8007DFE8: nop
    
            goto L_8007E158;
    }
    // 0x8007DFE8: nop

    // 0x8007DFEC: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x8007DFF0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8007DFF4: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8007DFF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007DFFC: sw          $t2, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = ctx->r10;
    // 0x8007E000: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x8007E004: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E008: beq         $s0, $at, L_8007E024
    if (ctx->r16 == ctx->r1) {
        // 0x8007E00C: nop
    
            goto L_8007E024;
    }
    // 0x8007E00C: nop

    // 0x8007E010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E014: beq         $s0, $at, L_8007E0A0
    if (ctx->r16 == ctx->r1) {
        // 0x8007E018: nop
    
            goto L_8007E0A0;
    }
    // 0x8007E018: nop

    // 0x8007E01C: b           L_8007E150
    // 0x8007E020: nop

        goto L_8007E150;
    // 0x8007E020: nop

L_8007E024:
    // 0x8007E024: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E028: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E02C: swc1        $f4, 0x7120($at)
    MEM_W(0X7120, ctx->r1) = ctx->f4.u32l;
    // 0x8007E030: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007E034: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007E038: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E03C: swc1        $f6, 0x7124($at)
    MEM_W(0X7124, ctx->r1) = ctx->f6.u32l;
    // 0x8007E040: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007E044: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E048: swc1        $f8, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f8.u32l;
    // 0x8007E04C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007E050: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007E054: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007E058: swc1        $f10, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f10.u32l;
    // 0x8007E05C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007E060: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007E064: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007E068: addiu       $t4, $t4, 0x7190
    ctx->r12 = ADD32(ctx->r12, 0X7190);
    // 0x8007E06C: swc1        $f16, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f16.u32l;
    // 0x8007E070: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E074: lwc1        $f18, -0xCE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XCE8);
    // 0x8007E078: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007E07C: addiu       $t5, $t5, 0x7190
    ctx->r13 = ADD32(ctx->r13, 0X7190);
    // 0x8007E080: swc1        $f18, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f18.u32l;
    // 0x8007E084: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E088: lwc1        $f4, -0xCE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XCE4);
    // 0x8007E08C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007E090: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007E094: swc1        $f4, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f4.u32l;
    // 0x8007E098: b           L_8007E150
    // 0x8007E09C: nop

        goto L_8007E150;
    // 0x8007E09C: nop

L_8007E0A0:
    // 0x8007E0A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007E0A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E0A8: swc1        $f6, 0x7120($at)
    MEM_W(0X7120, ctx->r1) = ctx->f6.u32l;
    // 0x8007E0AC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007E0B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007E0B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E0B8: swc1        $f8, 0x7124($at)
    MEM_W(0X7124, ctx->r1) = ctx->f8.u32l;
    // 0x8007E0BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007E0C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E0C4: swc1        $f10, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f10.u32l;
    // 0x8007E0C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007E0CC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007E0D0: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007E0D4: swc1        $f16, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f16.u32l;
    // 0x8007E0D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007E0DC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007E0E0: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007E0E4: swc1        $f18, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->f18.u32l;
    // 0x8007E0E8: lb          $t9, 0x6B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E0EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E0F0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007E0F4: lwc1        $f5, -0xCE0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XCE0);
    // 0x8007E0F8: lwc1        $f4, -0xCDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XCDC);
    // 0x8007E0FC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8007E100: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8007E104: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E108: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8007E10C: lwc1        $f6, 0x2468($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x8007E110: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x8007E114: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007E118: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007E11C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007E120: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x8007E124: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007E128: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8007E12C: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007E130: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8007E134: swc1        $f6, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f6.u32l;
    // 0x8007E138: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E13C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007E140: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007E144: swc1        $f4, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->f4.u32l;
    // 0x8007E148: b           L_8007E150
    // 0x8007E14C: nop

        goto L_8007E150;
    // 0x8007E14C: nop

L_8007E150:
    // 0x8007E150: b           L_8007E914
    // 0x8007E154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007E914;
    // 0x8007E154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007E158:
    // 0x8007E158: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007E15C: lw          $t3, 0x7190($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7190);
    // 0x8007E160: nop

    // 0x8007E164: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x8007E168: beq         $t4, $zero, L_8007E1F0
    if (ctx->r12 == 0) {
        // 0x8007E16C: nop
    
            goto L_8007E1F0;
    }
    // 0x8007E16C: nop

    // 0x8007E170: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E174: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E178: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007E17C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007E180: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E184: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007E188: lwc1        $f18, 0x714C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E18C: nop

    // 0x8007E190: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8007E194: swc1        $f6, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f6.u32l;
    // 0x8007E198: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E19C: lwc1        $f4, 0x714C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E1A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E1A4: lwc1        $f11, -0xCD8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XCD8);
    // 0x8007E1A8: lwc1        $f10, -0xCD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XCD4);
    // 0x8007E1AC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007E1B0: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x8007E1B4: nop

    // 0x8007E1B8: bc1f        L_8007E1E8
    if (!c1cs) {
        // 0x8007E1BC: nop
    
            goto L_8007E1E8;
    }
    // 0x8007E1BC: nop

    // 0x8007E1C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E1C4: lwc1        $f18, 0x714C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E1C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E1CC: lwc1        $f7, -0xCD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XCD0);
    // 0x8007E1D0: lwc1        $f6, -0xCCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XCCC);
    // 0x8007E1D4: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007E1D8: sub.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d - ctx->f6.d;
    // 0x8007E1DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E1E0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8007E1E4: swc1        $f8, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f8.u32l;
L_8007E1E8:
    // 0x8007E1E8: b           L_8007E3EC
    // 0x8007E1EC: nop

        goto L_8007E3EC;
    // 0x8007E1EC: nop

L_8007E1F0:
    // 0x8007E1F0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8007E1F4: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8007E1F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007E1FC: lhu         $t7, 0x1042($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1042);
    // 0x8007E200: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x8007E204: nop

    // 0x8007E208: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8007E20C: beq         $t8, $zero, L_8007E290
    if (ctx->r24 == 0) {
        // 0x8007E210: nop
    
            goto L_8007E290;
    }
    // 0x8007E210: nop

    // 0x8007E214: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007E218: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007E21C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E220: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x8007E224: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007E228: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8007E22C: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8007E230: lwc1        $f10, 0x14($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8007E234: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8007E238: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8007E23C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007E240: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007E244: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x8007E248: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E24C: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8007E250: swc1        $f4, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f4.u32l;
    // 0x8007E254: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8007E258: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8007E25C: lwc1        $f8, 0x10($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8007E260: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007E264: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007E268: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007E26C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007E270: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8007E274: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E278: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8007E27C: swc1        $f6, 0x7150($at)
    MEM_W(0X7150, ctx->r1) = ctx->f6.u32l;
    // 0x8007E280: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E284: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E288: b           L_8007E3EC
    // 0x8007E28C: swc1        $f4, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f4.u32l;
        goto L_8007E3EC;
    // 0x8007E28C: swc1        $f4, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f4.u32l;
L_8007E290:
    // 0x8007E290: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007E294: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007E298: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8007E29C: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8007E2A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2A4: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007E2A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2AC: lwc1        $f8, 0x714C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E2B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E2B4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E2B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2BC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007E2C0: swc1        $f18, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f18.u32l;
    // 0x8007E2C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2C8: lwc1        $f16, 0x714C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E2CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E2D0: lwc1        $f5, -0xCC8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XCC8);
    // 0x8007E2D4: lwc1        $f4, -0xCC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XCC4);
    // 0x8007E2D8: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8007E2DC: c.le.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d <= ctx->f6.d;
    // 0x8007E2E0: nop

    // 0x8007E2E4: bc1f        L_8007E314
    if (!c1cs) {
        // 0x8007E2E8: nop
    
            goto L_8007E314;
    }
    // 0x8007E2E8: nop

    // 0x8007E2EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E2F0: lwc1        $f8, 0x714C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E2F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E2F8: lwc1        $f19, -0xCC0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XCC0);
    // 0x8007E2FC: lwc1        $f18, -0xCBC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XCBC);
    // 0x8007E300: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8007E304: sub.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d - ctx->f18.d;
    // 0x8007E308: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E30C: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8007E310: swc1        $f6, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f6.u32l;
L_8007E314:
    // 0x8007E314: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E318: lwc1        $f4, 0x7150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7150);
    // 0x8007E31C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E320: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E324: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E328: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8007E32C: swc1        $f10, 0x7150($at)
    MEM_W(0X7150, ctx->r1) = ctx->f10.u32l;
    // 0x8007E330: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E334: lwc1        $f18, 0x7150($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7150);
    // 0x8007E338: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E33C: lwc1        $f7, -0xCB8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XCB8);
    // 0x8007E340: lwc1        $f6, -0xCB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XCB4);
    // 0x8007E344: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007E348: c.le.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d <= ctx->f16.d;
    // 0x8007E34C: nop

    // 0x8007E350: bc1f        L_8007E380
    if (!c1cs) {
        // 0x8007E354: nop
    
            goto L_8007E380;
    }
    // 0x8007E354: nop

    // 0x8007E358: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E35C: lwc1        $f4, 0x7150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7150);
    // 0x8007E360: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E364: lwc1        $f11, -0xCB0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XCB0);
    // 0x8007E368: lwc1        $f10, -0xCAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XCAC);
    // 0x8007E36C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007E370: sub.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d - ctx->f10.d;
    // 0x8007E374: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E378: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8007E37C: swc1        $f16, 0x7150($at)
    MEM_W(0X7150, ctx->r1) = ctx->f16.u32l;
L_8007E380:
    // 0x8007E380: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E384: lwc1        $f6, 0x7154($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7154);
    // 0x8007E388: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E38C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E390: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E394: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8007E398: swc1        $f8, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f8.u32l;
    // 0x8007E39C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E3A0: lwc1        $f10, 0x7154($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7154);
    // 0x8007E3A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E3A8: lwc1        $f17, -0xCA8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XCA8);
    // 0x8007E3AC: lwc1        $f16, -0xCA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XCA4);
    // 0x8007E3B0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007E3B4: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x8007E3B8: nop

    // 0x8007E3BC: bc1f        L_8007E3EC
    if (!c1cs) {
        // 0x8007E3C0: nop
    
            goto L_8007E3EC;
    }
    // 0x8007E3C0: nop

    // 0x8007E3C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E3C8: lwc1        $f6, 0x7154($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7154);
    // 0x8007E3CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E3D0: lwc1        $f9, -0xCA0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XCA0);
    // 0x8007E3D4: lwc1        $f8, -0xC9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XC9C);
    // 0x8007E3D8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8007E3DC: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x8007E3E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E3E4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8007E3E8: swc1        $f18, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f18.u32l;
L_8007E3EC:
    // 0x8007E3EC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007E3F0: lb          $t6, 0x7143($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7143);
    // 0x8007E3F4: lb          $t5, 0x6B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E3F8: nop

    // 0x8007E3FC: beq         $t5, $t6, L_8007E534
    if (ctx->r13 == ctx->r14) {
        // 0x8007E400: nop
    
            goto L_8007E534;
    }
    // 0x8007E400: nop

    // 0x8007E404: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007E408: lw          $t7, 0x307C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X307C);
    // 0x8007E40C: nop

    // 0x8007E410: beq         $t7, $zero, L_8007E438
    if (ctx->r15 == 0) {
        // 0x8007E414: nop
    
            goto L_8007E438;
    }
    // 0x8007E414: nop

    // 0x8007E418: jal         0x800B0E08
    // 0x8007E41C: nop

    func_800B0E08(rdram, ctx);
        goto after_0;
    // 0x8007E41C: nop

    after_0:
    // 0x8007E420: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007E424: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8007E428: jal         0x800BC980
    // 0x8007E42C: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x8007E42C: nop

    after_1:
    // 0x8007E430: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E434: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_8007E438:
    // 0x8007E438: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007E43C: lb          $t8, 0x7142($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X7142);
    // 0x8007E440: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007E444: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8007E448: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8007E44C: lhu         $a0, -0x4770($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4770);
    // 0x8007E450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8007E454: jal         0x800AFB70
    // 0x8007E458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x8007E458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8007E45C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E460: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x8007E464: lb          $t0, 0x6B($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E468: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E46C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007E470: sh          $t1, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r9;
    // 0x8007E474: lb          $t2, 0x6B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E478: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E47C: sb          $t2, 0x7143($at)
    MEM_B(0X7143, ctx->r1) = ctx->r10;
    // 0x8007E480: lb          $t3, 0x6B($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E484: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007E488: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007E48C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8007E490: lh          $t5, -0x4574($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4574);
    // 0x8007E494: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E498: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8007E49C: nop

    // 0x8007E4A0: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007E4A4: swc1        $f6, 0x714C($at)
    MEM_W(0X714C, ctx->r1) = ctx->f6.u32l;
    // 0x8007E4A8: lb          $t6, 0x6B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E4AC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007E4B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007E4B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007E4B8: lh          $t8, -0x4572($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4572);
    // 0x8007E4BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E4C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8007E4C4: nop

    // 0x8007E4C8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007E4CC: swc1        $f8, 0x7150($at)
    MEM_W(0X7150, ctx->r1) = ctx->f8.u32l;
    // 0x8007E4D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007E4D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E4D8: swc1        $f10, 0x7154($at)
    MEM_W(0X7154, ctx->r1) = ctx->f10.u32l;
    // 0x8007E4DC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007E4E0: lb          $t9, 0x7142($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7142);
    // 0x8007E4E4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007E4E8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007E4EC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8007E4F0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8007E4F4: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8007E4F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007E4FC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007E500: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007E504: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007E508: lw          $a2, 0x245C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X245C);
    // 0x8007E50C: jal         0x800BD1FC
    // 0x8007E510: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8007E510: nop

    after_3:
    // 0x8007E514: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007E518: jal         0x80080910
    // 0x8007E51C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_4;
    // 0x8007E51C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8007E520: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007E524: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007E528: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E52C: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8007E530: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
L_8007E534:
    // 0x8007E534: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007E538: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x8007E53C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007E540: lw          $t4, 0x7190($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7190);
    // 0x8007E544: nop

    // 0x8007E548: beq         $t4, $zero, L_8007E78C
    if (ctx->r12 == 0) {
        // 0x8007E54C: nop
    
            goto L_8007E78C;
    }
    // 0x8007E54C: nop

    // 0x8007E550: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007E554: addiu       $t5, $t5, 0x7190
    ctx->r13 = ADD32(ctx->r13, 0X7190);
    // 0x8007E558: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E55C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E560: lwc1        $f18, 0x54($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X54);
    // 0x8007E564: lwc1        $f4, 0x4C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4C);
    // 0x8007E568: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8007E56C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007E570: swc1        $f8, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = ctx->f8.u32l;
    // 0x8007E574: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007E578: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007E57C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E580: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E584: lwc1        $f10, 0x48($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8007E588: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E58C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007E590: lwc1        $f4, 0x7120($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7120);
    // 0x8007E594: nop

    // 0x8007E598: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8007E59C: swc1        $f6, 0x7120($at)
    MEM_W(0X7120, ctx->r1) = ctx->f6.u32l;
    // 0x8007E5A0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007E5A4: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007E5A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E5AC: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E5B0: lwc1        $f8, 0x4C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8007E5B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E5B8: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007E5BC: lwc1        $f4, 0x7124($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7124);
    // 0x8007E5C0: nop

    // 0x8007E5C4: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8007E5C8: swc1        $f16, 0x7124($at)
    MEM_W(0X7124, ctx->r1) = ctx->f16.u32l;
    // 0x8007E5CC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007E5D0: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007E5D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007E5D8: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007E5DC: lwc1        $f6, 0x50($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X50);
    // 0x8007E5E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E5E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007E5E8: lwc1        $f4, 0x7128($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7128);
    // 0x8007E5EC: nop

    // 0x8007E5F0: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8007E5F4: swc1        $f18, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f18.u32l;
    // 0x8007E5F8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007E5FC: lw          $t9, 0x7190($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7190);
    // 0x8007E600: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8007E604: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8007E608: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8007E60C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E610: bne         $t0, $at, L_8007E66C
    if (ctx->r8 != ctx->r1) {
        // 0x8007E614: nop
    
            goto L_8007E66C;
    }
    // 0x8007E614: nop

    // 0x8007E618: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E61C: lwc1        $f16, 0x7124($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7124);
    // 0x8007E620: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E624: lwc1        $f9, -0xC98($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XC98);
    // 0x8007E628: lwc1        $f8, -0xC94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XC94);
    // 0x8007E62C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8007E630: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8007E634: nop

    // 0x8007E638: bc1f        L_8007E664
    if (!c1cs) {
        // 0x8007E63C: nop
    
            goto L_8007E664;
    }
    // 0x8007E63C: nop

    // 0x8007E640: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8007E644: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007E648: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007E64C: nop

    // 0x8007E650: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8007E654: bne         $t2, $zero, L_8007E664
    if (ctx->r10 != 0) {
        // 0x8007E658: nop
    
            goto L_8007E664;
    }
    // 0x8007E658: nop

    // 0x8007E65C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E660: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
L_8007E664:
    // 0x8007E664: b           L_8007E784
    // 0x8007E668: nop

        goto L_8007E784;
    // 0x8007E668: nop

L_8007E66C:
    // 0x8007E66C: lb          $t3, 0x6B($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E670: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E674: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007E678: lwc1        $f4, 0x7128($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7128);
    // 0x8007E67C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007E680: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007E684: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E688: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8007E68C: lwc1        $f10, 0x2468($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x8007E690: nop

    // 0x8007E694: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8007E698: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x8007E69C: nop

    // 0x8007E6A0: bc1f        L_8007E784
    if (!c1cs) {
        // 0x8007E6A4: nop
    
            goto L_8007E784;
    }
    // 0x8007E6A4: nop

    // 0x8007E6A8: lb          $t5, 0x6B($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E6AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E6B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8007E6B4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8007E6B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8007E6BC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8007E6C0: lwc1        $f16, 0x2468($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x8007E6C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007E6C8: lwc1        $f11, -0xC90($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XC90);
    // 0x8007E6CC: lwc1        $f10, -0xC8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XC8C);
    // 0x8007E6D0: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x8007E6D4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007E6D8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8007E6DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E6E0: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8007E6E4: swc1        $f18, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f18.u32l;
    // 0x8007E6E8: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8007E6EC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007E6F0: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007E6F4: nop

    // 0x8007E6F8: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8007E6FC: bne         $t8, $zero, L_8007E784
    if (ctx->r24 != 0) {
        // 0x8007E700: nop
    
            goto L_8007E784;
    }
    // 0x8007E700: nop

    // 0x8007E704: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E708: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
    // 0x8007E70C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007E710: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007E714: nop

    // 0x8007E718: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x8007E71C: beq         $t0, $zero, L_8007E768
    if (ctx->r8 == 0) {
        // 0x8007E720: nop
    
            goto L_8007E768;
    }
    // 0x8007E720: nop

    // 0x8007E724: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007E728: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007E72C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E730: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8007E734: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
    // 0x8007E738: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8007E73C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E740: sh          $t3, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r11;
    // 0x8007E744: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8007E748: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E74C: sh          $t4, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r12;
    // 0x8007E750: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E754: sw          $zero, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = 0;
    // 0x8007E758: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8007E75C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E760: b           L_8007E784
    // 0x8007E764: sb          $t5, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r13;
        goto L_8007E784;
    // 0x8007E764: sb          $t5, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r13;
L_8007E768:
    // 0x8007E768: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007E76C: lw          $t6, 0x70FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70FC);
    // 0x8007E770: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E774: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8007E778: nop

    // 0x8007E77C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007E780: sb          $t8, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r24;
L_8007E784:
    // 0x8007E784: b           L_8007E7B8
    // 0x8007E788: nop

        goto L_8007E7B8;
    // 0x8007E788: nop

L_8007E78C:
    // 0x8007E78C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8007E790: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007E794: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E798: swc1        $f16, 0x7120($at)
    MEM_W(0X7120, ctx->r1) = ctx->f16.u32l;
    // 0x8007E79C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007E7A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007E7A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E7A8: swc1        $f6, 0x7124($at)
    MEM_W(0X7124, ctx->r1) = ctx->f6.u32l;
    // 0x8007E7AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007E7B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E7B4: swc1        $f8, 0x7128($at)
    MEM_W(0X7128, ctx->r1) = ctx->f8.u32l;
L_8007E7B8:
    // 0x8007E7B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007E7BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007E7C0: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x8007E7C4: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x8007E7C8: swc1        $f10, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f10.u32l;
    // 0x8007E7CC: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8007E7D0: nop

    // 0x8007E7D4: swc1        $f4, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f4.u32l;
    // 0x8007E7D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007E7DC: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x8007E7E0: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x8007E7E4: swc1        $f18, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f18.u32l;
    // 0x8007E7E8: lwc1        $f28, 0x8($t2)
    ctx->f28.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8007E7EC: addiu       $t3, $sp, 0x70
    ctx->r11 = ADD32(ctx->r29, 0X70);
    // 0x8007E7F0: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x8007E7F4: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x8007E7F8: swc1        $f28, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f28.u32l;
    // 0x8007E7FC: swc1        $f26, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f26.u32l;
    // 0x8007E800: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x8007E804: addiu       $t4, $sp, 0x70
    ctx->r12 = ADD32(ctx->r29, 0X70);
    // 0x8007E808: swc1        $f24, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f24.u32l;
    // 0x8007E80C: addiu       $t5, $sp, 0x70
    ctx->r13 = ADD32(ctx->r29, 0X70);
    // 0x8007E810: swc1        $f22, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f22.u32l;
    // 0x8007E814: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8007E818: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8007E81C: swc1        $f20, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f20.u32l;
    // 0x8007E820: addiu       $t7, $sp, 0x70
    ctx->r15 = ADD32(ctx->r29, 0X70);
    // 0x8007E824: swc1        $f20, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f20.u32l;
    // 0x8007E828: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007E82C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007E830: addiu       $t8, $sp, 0x70
    ctx->r24 = ADD32(ctx->r29, 0X70);
    // 0x8007E834: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x8007E838: swc1        $f16, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f16.u32l;
    // 0x8007E83C: lwc1        $f20, 0x20($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8007E840: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x8007E844: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x8007E848: swc1        $f20, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f20.u32l;
    // 0x8007E84C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007E850: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8007E854: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8007E858: jal         0x800B1250
    // 0x8007E85C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_5;
    // 0x8007E85C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8007E860: jal         0x800C1850
    // 0x8007E864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_6;
    // 0x8007E864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8007E868: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E86C: lwc1        $f12, 0x7120($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7120);
    // 0x8007E870: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E874: lwc1        $f14, 0x7124($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7124);
    // 0x8007E878: jal         0x800C2304
    // 0x8007E87C: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_7;
    // 0x8007E87C: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    after_7:
    // 0x8007E880: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E884: lwc1        $f12, 0x714C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X714C);
    // 0x8007E888: jal         0x800C23E8
    // 0x8007E88C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_8;
    // 0x8007E88C: nop

    after_8:
    // 0x8007E890: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E894: lwc1        $f12, 0x7150($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7150);
    // 0x8007E898: jal         0x800C25B8
    // 0x8007E89C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_9;
    // 0x8007E89C: nop

    after_9:
    // 0x8007E8A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E8A4: lwc1        $f12, 0x7154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7154);
    // 0x8007E8A8: jal         0x800C2780
    // 0x8007E8AC: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_10;
    // 0x8007E8AC: nop

    after_10:
    // 0x8007E8B0: lb          $t1, 0x6B($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X6B);
    // 0x8007E8B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007E8B8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007E8BC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8007E8C0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007E8C4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8007E8C8: lwc1        $f6, 0x2468($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x8007E8CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007E8D0: lwc1        $f8, 0x7128($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7128);
    // 0x8007E8D4: nop

    // 0x8007E8D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E8DC: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x8007E8E0: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007E8E4: nop

    // 0x8007E8E8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8007E8EC: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x8007E8F0: jal         0x800C2948
    // 0x8007E8F4: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_11;
    // 0x8007E8F4: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_11:
    // 0x8007E8F8: jal         0x8002D200
    // 0x8007E8FC: nop

    func_8002D200(rdram, ctx);
        goto after_12;
    // 0x8007E8FC: nop

    after_12:
    // 0x8007E900: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x8007E904: b           L_8007E914
    // 0x8007E908: nop

        goto L_8007E914;
    // 0x8007E908: nop

    // 0x8007E90C: b           L_8007E914
    // 0x8007E910: nop

        goto L_8007E914;
    // 0x8007E910: nop

L_8007E914:
    // 0x8007E914: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007E918: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8007E91C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007E920: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8007E924: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007E928: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8007E92C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007E930: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8007E934: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007E938: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8007E93C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007E940: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8007E944: jr          $ra
    // 0x8007E948: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8007E948: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void alSndpSetFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA050: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA058: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CA05C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800CA060: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800CA064: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800CA068: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA06C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800CA070: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x800CA074: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CA078: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CA07C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800CA080: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CA084: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800CA088: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA08C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA090: jal         0x800D3A2C
    // 0x800CA094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CA098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA09C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA0A0: jr          $ra
    // 0x800CA0A4: nop

    return;
    // 0x800CA0A4: nop

;}
RECOMP_FUNC void func_8006F440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F440: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F444: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F448: nop

    // 0x8006F44C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F450: nop

    // 0x8006F454: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006F458: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F45C: jr          $ra
    // 0x8006F460: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F460: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F464: jr          $ra
    // 0x8006F468: nop

    return;
    // 0x8006F468: nop

    // 0x8006F46C: jr          $ra
    // 0x8006F470: nop

    return;
    // 0x8006F470: nop

;}
RECOMP_FUNC void func_80074DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074DB8: jal         0x80061488
    // 0x80074DBC: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80074DBC: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80074DC0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80074DC4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80074DC8: b           L_80074DD8
    // 0x80074DCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80074DD8;
    // 0x80074DCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074DD0: b           L_80074DD8
    // 0x80074DD4: nop

        goto L_80074DD8;
    // 0x80074DD4: nop

L_80074DD8:
    // 0x80074DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074DDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074DE0: jr          $ra
    // 0x80074DE4: nop

    return;
    // 0x80074DE4: nop

;}
RECOMP_FUNC void func_80074C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074C30: jal         0x80061348
    // 0x80074C34: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074C34: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x80074C38: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074C3C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074C40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074C44: beq         $v0, $zero, L_80074C98
    if (ctx->r2 == 0) {
        // 0x80074C48: nop
    
            goto L_80074C98;
    }
    // 0x80074C48: nop

    // 0x80074C4C: jal         0x80061348
    // 0x80074C50: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074C50: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074C54: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074C58: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074C5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074C60: beq         $v0, $zero, L_80074C98
    if (ctx->r2 == 0) {
        // 0x80074C64: nop
    
            goto L_80074C98;
    }
    // 0x80074C64: nop

    // 0x80074C68: jal         0x80061348
    // 0x80074C6C: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074C6C: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074C70: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074C74: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074C78: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074C7C: beq         $v0, $zero, L_80074C98
    if (ctx->r2 == 0) {
        // 0x80074C80: nop
    
            goto L_80074C98;
    }
    // 0x80074C80: nop

    // 0x80074C84: jal         0x80061348
    // 0x80074C88: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074C88: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074C8C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074C90: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074C94: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074C98:
    // 0x80074C98: b           L_80074CA8
    // 0x80074C9C: nop

        goto L_80074CA8;
    // 0x80074C9C: nop

    // 0x80074CA0: b           L_80074CA8
    // 0x80074CA4: nop

        goto L_80074CA8;
    // 0x80074CA4: nop

L_80074CA8:
    // 0x80074CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074CB0: jr          $ra
    // 0x80074CB4: nop

    return;
    // 0x80074CB4: nop

;}
RECOMP_FUNC void func_8006BCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BCD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BCD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BCD8: jal         0x8005F064
    // 0x8006BCDC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BCDC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_0:
    // 0x8006BCE0: b           L_8006BCF0
    // 0x8006BCE4: nop

        goto L_8006BCF0;
    // 0x8006BCE4: nop

    // 0x8006BCE8: b           L_8006BCF0
    // 0x8006BCEC: nop

        goto L_8006BCF0;
    // 0x8006BCEC: nop

L_8006BCF0:
    // 0x8006BCF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BCF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BCF8: jr          $ra
    // 0x8006BCFC: nop

    return;
    // 0x8006BCFC: nop

;}
RECOMP_FUNC void func_8008ED4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ED4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008ED50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008ED54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008ED58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008ED5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008ED60: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008ED64: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8008ED68: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8008ED6C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8008ED70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008ED74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008ED78: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008ED7C: jal         0x8008EDA4
    // 0x8008ED80: nop

    vsprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008ED80: nop

    after_0:
    // 0x8008ED84: b           L_8008ED94
    // 0x8008ED88: nop

        goto L_8008ED94;
    // 0x8008ED88: nop

    // 0x8008ED8C: b           L_8008ED94
    // 0x8008ED90: nop

        goto L_8008ED94;
    // 0x8008ED90: nop

L_8008ED94:
    // 0x8008ED94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008ED98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008ED9C: jr          $ra
    // 0x8008EDA0: nop

    return;
    // 0x8008EDA0: nop

;}
RECOMP_FUNC void func_80064F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064F88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064F8C: nop

    // 0x80064F90: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80064F94: nop

    // 0x80064F98: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064F9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064FA0: jr          $ra
    // 0x80064FA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064FA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064FA8: jr          $ra
    // 0x80064FAC: nop

    return;
    // 0x80064FAC: nop

    // 0x80064FB0: jr          $ra
    // 0x80064FB4: nop

    return;
    // 0x80064FB4: nop

;}
RECOMP_FUNC void func_800B77D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B77D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B77DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B77E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B77E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B77E8:
    // 0x800B77E8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B77EC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B77F0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B77F4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B77F8: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B77FC: sh          $t7, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r15;
    // 0x800B7800: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B7804: nop

    // 0x800B7808: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B780C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B7810: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B7814: nop

    // 0x800B7818: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B781C: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B7820: bne         $at, $zero, L_800B77E8
    if (ctx->r1 != 0) {
        // 0x800B7824: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_800B77E8;
    }
    // 0x800B7824: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B7828: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B782C: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7830: ori         $at, $zero, 0xE000
    ctx->r1 = 0 | 0XE000;
    // 0x800B7834: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B7838: bne         $at, $zero, L_800B7850
    if (ctx->r1 != 0) {
        // 0x800B783C: nop
    
            goto L_800B7850;
    }
    // 0x800B783C: nop

    // 0x800B7840: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B7844: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B7848: bne         $at, $zero, L_800B7858
    if (ctx->r1 != 0) {
        // 0x800B784C: nop
    
            goto L_800B7858;
    }
    // 0x800B784C: nop

L_800B7850:
    // 0x800B7850: b           L_800B79EC
    // 0x800B7854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B79EC;
    // 0x800B7854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7858:
    // 0x800B7858: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B785C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B7860: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B7864: lhu         $t7, 0x2($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7868: nop

    // 0x800B786C: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x800B7870: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B7874: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B7878: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B787C: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800B7880: nop

    // 0x800B7884: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x800B7888: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x800B788C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B7890: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B7894: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x800B7898: nop

    // 0x800B789C: sh          $t4, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r12;
    // 0x800B78A0: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B78A4: lhu         $t8, 0x2($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X2);
    // 0x800B78A8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800B78AC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x800B78B0: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x800B78B4: sltiu       $at, $t7, 0x12
    ctx->r1 = ctx->r15 < 0X12 ? 1 : 0;
    // 0x800B78B8: beq         $at, $zero, L_800B79C0
    if (ctx->r1 == 0) {
        // 0x800B78BC: nop
    
            goto L_800B79C0;
    }
    // 0x800B78BC: nop

    // 0x800B78C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B78C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B78C8: addu        $at, $at, $t7
    gpr jr_addend_800B78D4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B78CC: lw          $t7, -0x5A0($at)
    ctx->r15 = ADD32(ctx->r1, -0X5A0);
    // 0x800B78D0: nop

    // 0x800B78D4: jr          $t7
    // 0x800B78D8: nop

    switch (jr_addend_800B78D4 >> 2) {
        case 0: goto L_800B78DC; break;
        case 1: goto L_800B7928; break;
        case 2: goto L_800B7928; break;
        case 3: goto L_800B7928; break;
        case 4: goto L_800B79C0; break;
        case 5: goto L_800B79C0; break;
        case 6: goto L_800B79C0; break;
        case 7: goto L_800B7928; break;
        case 8: goto L_800B7928; break;
        case 9: goto L_800B7928; break;
        case 10: goto L_800B7928; break;
        case 11: goto L_800B7928; break;
        case 12: goto L_800B7928; break;
        case 13: goto L_800B7928; break;
        case 14: goto L_800B7928; break;
        case 15: goto L_800B7928; break;
        case 16: goto L_800B7928; break;
        case 17: goto L_800B78DC; break;
        default: switch_error(__func__, 0x800B78D4, 0x800EFA60);
    }
    // 0x800B78D8: nop

L_800B78DC:
    // 0x800B78DC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B78E0: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B78E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B78E8: nop

    // 0x800B78EC: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x800B78F0: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B78F4: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800B78F8: nop

    // 0x800B78FC: bne         $t1, $zero, L_800B7920
    if (ctx->r9 != 0) {
        // 0x800B7900: nop
    
            goto L_800B7920;
    }
    // 0x800B7900: nop

    // 0x800B7904: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B7908: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B790C: nop

    // 0x800B7910: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x800B7914: nop

    // 0x800B7918: ori         $t4, $t3, 0x400
    ctx->r12 = ctx->r11 | 0X400;
    // 0x800B791C: sh          $t4, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r12;
L_800B7920:
    // 0x800B7920: b           L_800B79C0
    // 0x800B7924: nop

        goto L_800B79C0;
    // 0x800B7924: nop

L_800B7928:
    // 0x800B7928: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800B792C: lw          $t5, 0x3068($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3068);
    // 0x800B7930: nop

    // 0x800B7934: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800B7938: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B793C: lhu         $a0, 0x4($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X4);
    // 0x800B7940: jal         0x8000D688
    // 0x800B7944: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B7944: nop

    after_0:
    // 0x800B7948: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B794C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7950: nop

    // 0x800B7954: bne         $t8, $zero, L_800B7964
    if (ctx->r24 != 0) {
        // 0x800B7958: nop
    
            goto L_800B7964;
    }
    // 0x800B7958: nop

    // 0x800B795C: b           L_800B79EC
    // 0x800B7960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B79EC;
    // 0x800B7960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7964:
    // 0x800B7964: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7968: nop

    // 0x800B796C: lw          $t9, 0x20C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X20C);
    // 0x800B7970: nop

    // 0x800B7974: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800B7978: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B797C: nop

    // 0x800B7980: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x800B7984: nop

    // 0x800B7988: andi        $t3, $t1, 0x100
    ctx->r11 = ctx->r9 & 0X100;
    // 0x800B798C: beq         $t3, $zero, L_800B799C
    if (ctx->r11 == 0) {
        // 0x800B7990: nop
    
            goto L_800B799C;
    }
    // 0x800B7990: nop

    // 0x800B7994: b           L_800B79EC
    // 0x800B7998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B79EC;
    // 0x800B7998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B799C:
    // 0x800B799C: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x800B79A0: lhu         $a0, 0x4($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X4);
    // 0x800B79A4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800B79A8: jal         0x8000D934
    // 0x800B79AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8000D934(rdram, ctx);
        goto after_1;
    // 0x800B79AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800B79B0: bgez        $v0, L_800B79C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B79B4: nop
    
            goto L_800B79C0;
    }
    // 0x800B79B4: nop

    // 0x800B79B8: b           L_800B79EC
    // 0x800B79BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B79EC;
    // 0x800B79BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B79C0:
    // 0x800B79C0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800B79C4: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x800B79C8: nop

    // 0x800B79CC: lhu         $t5, 0x4($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X4);
    // 0x800B79D0: nop

    // 0x800B79D4: ori         $t6, $t5, 0x100
    ctx->r14 = ctx->r13 | 0X100;
    // 0x800B79D8: sh          $t6, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r14;
    // 0x800B79DC: b           L_800B79EC
    // 0x800B79E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B79EC;
    // 0x800B79E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B79E4: b           L_800B79EC
    // 0x800B79E8: nop

        goto L_800B79EC;
    // 0x800B79E8: nop

L_800B79EC:
    // 0x800B79EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B79F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B79F4: jr          $ra
    // 0x800B79F8: nop

    return;
    // 0x800B79F8: nop

;}
RECOMP_FUNC void func_80066AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066AEC: jal         0x80061348
    // 0x80066AF0: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066AF0: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x80066AF4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066AF8: b           L_80066B08
    // 0x80066AFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066B08;
    // 0x80066AFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066B00: b           L_80066B08
    // 0x80066B04: nop

        goto L_80066B08;
    // 0x80066B04: nop

L_80066B08:
    // 0x80066B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066B10: jr          $ra
    // 0x80066B14: nop

    return;
    // 0x80066B14: nop

;}
RECOMP_FUNC void func_800821A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800821A0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800821A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800821A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800821AC: sw          $zero, 0x165C($at)
    MEM_W(0X165C, ctx->r1) = 0;
    // 0x800821B0: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800821B4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800821B8: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x800821BC: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x800821C0: nop

    // 0x800821C4: bne         $t7, $zero, L_800821D4
    if (ctx->r15 != 0) {
        // 0x800821C8: nop
    
            goto L_800821D4;
    }
    // 0x800821C8: nop

    // 0x800821CC: b           L_800824FC
    // 0x800821D0: nop

        goto L_800824FC;
    // 0x800821D0: nop

L_800821D4:
    // 0x800821D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800821D8: addiu       $t8, $t8, 0x7340
    ctx->r24 = ADD32(ctx->r24, 0X7340);
    // 0x800821DC: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x800821E0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800821E4: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x800821E8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800821EC: nop

    // 0x800821F0: bne         $t0, $at, L_80082208
    if (ctx->r8 != ctx->r1) {
        // 0x800821F4: nop
    
            goto L_80082208;
    }
    // 0x800821F4: nop

    // 0x800821F8: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x800821FC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80082200: beq         $t1, $at, L_800824F4
    if (ctx->r9 == ctx->r1) {
        // 0x80082204: nop
    
            goto L_800824F4;
    }
    // 0x80082204: nop

L_80082208:
    // 0x80082208: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8008220C: jal         0x8008250C
    // 0x80082210: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008250C(rdram, ctx);
        goto after_0;
    // 0x80082210: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80082214: beq         $v0, $zero, L_800824C4
    if (ctx->r2 == 0) {
        // 0x80082218: nop
    
            goto L_800824C4;
    }
    // 0x80082218: nop

    // 0x8008221C: jal         0x800BC6EC
    // 0x80082220: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80082220: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_1:
    // 0x80082224: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80082228: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8008222C: lw          $t2, 0x165C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X165C);
    // 0x80082230: nop

    // 0x80082234: bne         $t2, $zero, L_8008224C
    if (ctx->r10 != 0) {
        // 0x80082238: nop
    
            goto L_8008224C;
    }
    // 0x80082238: nop

    // 0x8008223C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80082240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082244: b           L_8008226C
    // 0x80082248: sw          $t3, 0x165C($at)
    MEM_W(0X165C, ctx->r1) = ctx->r11;
        goto L_8008226C;
    // 0x80082248: sw          $t3, 0x165C($at)
    MEM_W(0X165C, ctx->r1) = ctx->r11;
L_8008224C:
    // 0x8008224C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80082250: nop

    // 0x80082254: beq         $t4, $zero, L_8008226C
    if (ctx->r12 == 0) {
        // 0x80082258: nop
    
            goto L_8008226C;
    }
    // 0x80082258: nop

    // 0x8008225C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80082260: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80082264: nop

    // 0x80082268: sw          $t5, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r13;
L_8008226C:
    // 0x8008226C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80082270: nop

    // 0x80082274: sw          $zero, 0x44($t7)
    MEM_W(0X44, ctx->r15) = 0;
    // 0x80082278: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8008227C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80082280: nop

    // 0x80082284: sw          $t8, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r24;
    // 0x80082288: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8008228C: nop

    // 0x80082290: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x80082294: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80082298: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8008229C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800822A0: nop

    // 0x800822A4: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x800822A8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800822AC: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x800822B0: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800822B4: nop

    // 0x800822B8: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x800822BC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800822C0: nop

    // 0x800822C4: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800822C8: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800822CC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800822D0: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x800822D4: nop

    // 0x800822D8: andi        $t8, $t7, 0x3C
    ctx->r24 = ctx->r15 & 0X3C;
    // 0x800822DC: sra         $t0, $t8, 2
    ctx->r8 = S32(SIGNED(ctx->r24) >> 2);
    // 0x800822E0: sh          $t0, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r8;
    // 0x800822E4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800822E8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800822EC: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x800822F0: nop

    // 0x800822F4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800822F8: nop

    // 0x800822FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082300: swc1        $f6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f6.u32l;
    // 0x80082304: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80082308: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8008230C: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x80082310: nop

    // 0x80082314: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80082318: nop

    // 0x8008231C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80082320: swc1        $f10, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f10.u32l;
    // 0x80082324: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80082328: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8008232C: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x80082330: nop

    // 0x80082334: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80082338: nop

    // 0x8008233C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80082340: swc1        $f18, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f18.u32l;
    // 0x80082344: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80082348: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8008234C: lh          $t1, 0xE($t9)
    ctx->r9 = MEM_H(ctx->r25, 0XE);
    // 0x80082350: nop

    // 0x80082354: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80082358: nop

    // 0x8008235C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082360: swc1        $f6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f6.u32l;
    // 0x80082364: lh          $t3, 0x2C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2C);
    // 0x80082368: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8008236C: nop

    // 0x80082370: sh          $t3, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r11;
    // 0x80082374: lh          $t5, 0x2E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2E);
    // 0x80082378: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8008237C: nop

    // 0x80082380: sh          $t5, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r13;
    // 0x80082384: lh          $t7, 0x30($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X30);
    // 0x80082388: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8008238C: nop

    // 0x80082390: sh          $t7, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r15;
    // 0x80082394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082398: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8008239C: nop

    // 0x800823A0: swc1        $f8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f8.u32l;
    // 0x800823A4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800823A8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800823AC: nop

    // 0x800823B0: sw          $t9, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r25;
    // 0x800823B4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800823B8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800823BC: nop

    // 0x800823C0: sw          $t2, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r10;
    // 0x800823C4: lhu         $t4, 0x3C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3C);
    // 0x800823C8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800823CC: nop

    // 0x800823D0: sh          $t4, 0x2C($t5)
    MEM_H(0X2C, ctx->r13) = ctx->r12;
    // 0x800823D4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800823D8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800823DC: nop

    // 0x800823E0: sw          $t6, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r14;
    // 0x800823E4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800823E8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800823EC: nop

    // 0x800823F0: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x800823F4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800823F8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800823FC: nop

    // 0x80082400: sw          $t9, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r25;
    // 0x80082404: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80082408: nop

    // 0x8008240C: lh          $t3, 0xC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XC);
    // 0x80082410: nop

    // 0x80082414: beq         $t3, $zero, L_800824B8
    if (ctx->r11 == 0) {
        // 0x80082418: nop
    
            goto L_800824B8;
    }
    // 0x80082418: nop

    // 0x8008241C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80082420: nop

    // 0x80082424: lwc1        $f10, 0x14($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X14);
    // 0x80082428: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x8008242C: lh          $t7, 0xA($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XA);
    // 0x80082430: lhu         $a3, 0x2C($t4)
    ctx->r7 = MEM_HU(ctx->r12, 0X2C);
    // 0x80082434: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80082438: lwc1        $f16, 0x18($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8008243C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80082440: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80082444: addiu       $a0, $t4, 0x24
    ctx->r4 = ADD32(ctx->r12, 0X24);
    // 0x80082448: addiu       $a1, $t4, 0x28
    ctx->r5 = ADD32(ctx->r12, 0X28);
    // 0x8008244C: or          $a2, $t6, $t7
    ctx->r6 = ctx->r14 | ctx->r15;
    // 0x80082450: jal         0x800B202C
    // 0x80082454: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_2;
    // 0x80082454: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80082458: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8008245C: nop

    // 0x80082460: sw          $v0, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r2;
    // 0x80082464: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80082468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008246C: jal         0x8005A5F4
    // 0x80082470: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8005A5F4(rdram, ctx);
        goto after_3;
    // 0x80082470: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x80082474: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80082478: nop

    // 0x8008247C: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x80082480: nop

    // 0x80082484: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80082488: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x8008248C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80082490: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082494: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80082498: nop

    // 0x8008249C: bne         $t3, $at, L_800824B0
    if (ctx->r11 != ctx->r1) {
        // 0x800824A0: nop
    
            goto L_800824B0;
    }
    // 0x800824A0: nop

    // 0x800824A4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800824A8: nop

    // 0x800824AC: sh          $zero, 0xC($t5)
    MEM_H(0XC, ctx->r13) = 0;
L_800824B0:
    // 0x800824B0: b           L_800824C4
    // 0x800824B4: nop

        goto L_800824C4;
    // 0x800824B4: nop

L_800824B8:
    // 0x800824B8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800824BC: nop

    // 0x800824C0: sw          $zero, 0x30($t6)
    MEM_W(0X30, ctx->r14) = 0;
L_800824C4:
    // 0x800824C4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800824C8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800824CC: addiu       $t4, $t7, 0x10
    ctx->r12 = ADD32(ctx->r15, 0X10);
    // 0x800824D0: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x800824D4: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x800824D8: nop

    // 0x800824DC: bne         $t8, $at, L_80082208
    if (ctx->r24 != ctx->r1) {
        // 0x800824E0: nop
    
            goto L_80082208;
    }
    // 0x800824E0: nop

    // 0x800824E4: lhu         $t9, 0x2($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X2);
    // 0x800824E8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800824EC: bne         $t9, $at, L_80082208
    if (ctx->r25 != ctx->r1) {
        // 0x800824F0: nop
    
            goto L_80082208;
    }
    // 0x800824F0: nop

L_800824F4:
    // 0x800824F4: b           L_800824FC
    // 0x800824F8: nop

        goto L_800824FC;
    // 0x800824F8: nop

L_800824FC:
    // 0x800824FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80082500: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80082504: jr          $ra
    // 0x80082508: nop

    return;
    // 0x80082508: nop

;}
RECOMP_FUNC void func_8008C634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C63C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C640: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008C644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008C648: jal         0x8005FC18
    // 0x8008C64C: nop

    func_8005FC18(rdram, ctx);
        goto after_0;
    // 0x8008C64C: nop

    after_0:
    // 0x8008C650: bne         $v0, $zero, L_8008C678
    if (ctx->r2 != 0) {
        // 0x8008C654: nop
    
            goto L_8008C678;
    }
    // 0x8008C654: nop

    // 0x8008C658: jal         0x8005D150
    // 0x8008C65C: nop

    func_8005D150(rdram, ctx);
        goto after_1;
    // 0x8008C65C: nop

    after_1:
    // 0x8008C660: jal         0x8005F01C
    // 0x8008C664: nop

    func_8005F01C(rdram, ctx);
        goto after_2;
    // 0x8008C664: nop

    after_2:
    // 0x8008C668: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008C66C: sb          $zero, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = 0;
    // 0x8008C670: b           L_8008C6D0
    // 0x8008C674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008C6D0;
    // 0x8008C674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008C678:
    // 0x8008C678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008C67C: jal         0x80028B94
    // 0x8008C680: nop

    func_80028B94(rdram, ctx);
        goto after_3;
    // 0x8008C680: nop

    after_3:
    // 0x8008C684: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008C688: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008C68C: lw          $t7, 0x68($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X68);
    // 0x8008C690: nop

    // 0x8008C694: sw          $t7, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r15;
    // 0x8008C698: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008C69C: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x8008C6A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008C6A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008C6A8: lhu         $t9, 0x6C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6C);
    // 0x8008C6AC: nop

    // 0x8008C6B0: sb          $t9, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = ctx->r25;
    // 0x8008C6B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C6B8: jal         0x8008C6E0
    // 0x8008C6BC: nop

    func_8008C6E0(rdram, ctx);
        goto after_4;
    // 0x8008C6BC: nop

    after_4:
    // 0x8008C6C0: b           L_8008C6D0
    // 0x8008C6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C6D0;
    // 0x8008C6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008C6C8: b           L_8008C6D0
    // 0x8008C6CC: nop

        goto L_8008C6D0;
    // 0x8008C6CC: nop

L_8008C6D0:
    // 0x8008C6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C6D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C6D8: jr          $ra
    // 0x8008C6DC: nop

    return;
    // 0x8008C6DC: nop

;}
RECOMP_FUNC void func_8002BB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BB50: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BB54: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BB58: slti        $at, $a0, 0x2A
    ctx->r1 = SIGNED(ctx->r4) < 0X2A ? 1 : 0;
    // 0x8002BB5C: bne         $at, $zero, L_8002BB74
    if (ctx->r1 != 0) {
        // 0x8002BB60: nop
    
            goto L_8002BB74;
    }
    // 0x8002BB60: nop

    // 0x8002BB64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BB68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002BB6C: jr          $ra
    // 0x8002BB70: nop

    return;
    // 0x8002BB70: nop

L_8002BB74:
    // 0x8002BB74: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BB78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002BB7C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002BB80: lwc1        $f0, -0x4620($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4620);
    // 0x8002BB84: jr          $ra
    // 0x8002BB88: nop

    return;
    // 0x8002BB88: nop

    // 0x8002BB8C: jr          $ra
    // 0x8002BB90: nop

    return;
    // 0x8002BB90: nop

    // 0x8002BB94: jr          $ra
    // 0x8002BB98: nop

    return;
    // 0x8002BB98: nop

;}
RECOMP_FUNC void func_80098688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098688: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009868C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098690: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80098694: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80098698: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8009869C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800986A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800986A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800986A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800986AC: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800986B0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800986B4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800986B8: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800986BC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800986C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800986C4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800986C8: nop

    // 0x800986CC: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800986D0: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800986D4: nop

    // 0x800986D8: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800986DC: bne         $t2, $zero, L_800986EC
    if (ctx->r10 != 0) {
        // 0x800986E0: nop
    
            goto L_800986EC;
    }
    // 0x800986E0: nop

    // 0x800986E4: b           L_80098744
    // 0x800986E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098744;
    // 0x800986E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800986EC:
    // 0x800986EC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800986F0: jal         0x800C1154
    // 0x800986F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C1154(rdram, ctx);
        goto after_0;
    // 0x800986F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x800986F8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800986FC: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x80098700: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    // 0x80098704: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x80098708: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009870C: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x80098710: jal         0x800971D4
    // 0x80098714: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    func_800971D4(rdram, ctx);
        goto after_1;
    // 0x80098714: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    after_1:
    // 0x80098718: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8009871C: nop

    // 0x80098720: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x80098724: lbu         $t5, 0x2E9($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2E9);
    // 0x80098728: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x8009872C: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80098730: sb          $t6, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r14;
    // 0x80098734: b           L_80098744
    // 0x80098738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098744;
    // 0x80098738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009873C: b           L_80098744
    // 0x80098740: nop

        goto L_80098744;
    // 0x80098740: nop

L_80098744:
    // 0x80098744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098748: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009874C: jr          $ra
    // 0x80098750: nop

    return;
    // 0x80098750: nop

;}
RECOMP_FUNC void func_8007959C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007959C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800795A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800795A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800795A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800795AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800795B0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800795B4: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x800795B8: nop

    // 0x800795BC: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x800795C0: nop

    // 0x800795C4: bne         $t7, $zero, L_800795D4
    if (ctx->r15 != 0) {
        // 0x800795C8: nop
    
            goto L_800795D4;
    }
    // 0x800795C8: nop

    // 0x800795CC: b           L_800797E4
    // 0x800795D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800797E4;
    // 0x800795D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800795D4:
    // 0x800795D4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800795D8: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x800795DC: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
    // 0x800795E0: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x800795E4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800795E8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800795EC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800795F0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800795F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800795F8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800795FC: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80079600: nop

    // 0x80079604: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80079608: nop

    // 0x8007960C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079610: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80079614: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80079618: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007961C: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80079620: nop

    // 0x80079624: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80079628: nop

    // 0x8007962C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80079630: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x80079634: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80079638: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007963C: lh          $t9, 0x4($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X4);
    // 0x80079640: nop

    // 0x80079644: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80079648: nop

    // 0x8007964C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80079650: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x80079654: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80079658: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007965C: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x80079660: nop

    // 0x80079664: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80079668: nop

    // 0x8007966C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079670: swc1        $f6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f6.u32l;
    // 0x80079674: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x80079678: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007967C: nop

    // 0x80079680: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80079684: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80079688: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007968C: lhu         $t0, 0x8($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X8);
    // 0x80079690: nop

    // 0x80079694: andi        $t1, $t0, 0xFF00
    ctx->r9 = ctx->r8 & 0XFF00;
    // 0x80079698: sh          $t1, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r9;
    // 0x8007969C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800796A0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800796A4: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800796A8: nop

    // 0x800796AC: sh          $t3, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r11;
    // 0x800796B0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800796B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800796B8: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x800796BC: nop

    // 0x800796C0: andi        $t7, $t6, 0x3C
    ctx->r15 = ctx->r14 & 0X3C;
    // 0x800796C4: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800796C8: sb          $t8, 0x16($t0)
    MEM_B(0X16, ctx->r8) = ctx->r24;
    // 0x800796CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800796D0: nop

    // 0x800796D4: lh          $s0, 0x10($t1)
    ctx->r16 = MEM_H(ctx->r9, 0X10);
    // 0x800796D8: nop

    // 0x800796DC: beq         $s0, $zero, L_800796F8
    if (ctx->r16 == 0) {
        // 0x800796E0: nop
    
            goto L_800796F8;
    }
    // 0x800796E0: nop

    // 0x800796E4: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800796E8: beq         $s0, $at, L_80079774
    if (ctx->r16 == ctx->r1) {
        // 0x800796EC: nop
    
            goto L_80079774;
    }
    // 0x800796EC: nop

    // 0x800796F0: b           L_800797D4
    // 0x800796F4: nop

        goto L_800797D4;
    // 0x800796F4: nop

L_800796F8:
    // 0x800796F8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800796FC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80079700: lhu         $t2, 0xC($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0XC);
    // 0x80079704: nop

    // 0x80079708: sh          $t2, 0x1C($t3)
    MEM_H(0X1C, ctx->r11) = ctx->r10;
    // 0x8007970C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80079710: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80079714: lhu         $t5, 0xE($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XE);
    // 0x80079718: nop

    // 0x8007971C: sh          $t5, 0x1E($t6)
    MEM_H(0X1E, ctx->r14) = ctx->r13;
    // 0x80079720: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80079724: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80079728: lhu         $t8, 0xA($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XA);
    // 0x8007972C: nop

    // 0x80079730: bne         $t8, $at, L_8007974C
    if (ctx->r24 != ctx->r1) {
        // 0x80079734: nop
    
            goto L_8007974C;
    }
    // 0x80079734: nop

    // 0x80079738: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007973C: nop

    // 0x80079740: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
    // 0x80079744: b           L_800797D4
    // 0x80079748: nop

        goto L_800797D4;
    // 0x80079748: nop

L_8007974C:
    // 0x8007974C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80079750: nop

    // 0x80079754: lhu         $a0, 0xA($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XA);
    // 0x80079758: jal         0x800797F4
    // 0x8007975C: nop

    func_800797F4(rdram, ctx);
        goto after_0;
    // 0x8007975C: nop

    after_0:
    // 0x80079760: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80079764: nop

    // 0x80079768: sw          $v0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r2;
    // 0x8007976C: b           L_800797D4
    // 0x80079770: nop

        goto L_800797D4;
    // 0x80079770: nop

L_80079774:
    // 0x80079774: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80079778: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007977C: lhu         $t3, 0xA($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XA);
    // 0x80079780: nop

    // 0x80079784: sh          $t3, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r11;
    // 0x80079788: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007978C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80079790: lhu         $t6, 0xC($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0XC);
    // 0x80079794: nop

    // 0x80079798: sh          $t6, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r14;
    // 0x8007979C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800797A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800797A4: lhu         $t0, 0xE($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0XE);
    // 0x800797A8: nop

    // 0x800797AC: sh          $t0, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r8;
    // 0x800797B0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800797B4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800797B8: lhu         $t2, 0x8($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X8);
    // 0x800797BC: nop

    // 0x800797C0: andi        $t3, $t2, 0xC0
    ctx->r11 = ctx->r10 & 0XC0;
    // 0x800797C4: sra         $t4, $t3, 6
    ctx->r12 = S32(SIGNED(ctx->r11) >> 6);
    // 0x800797C8: sb          $t4, 0x1E($t5)
    MEM_B(0X1E, ctx->r13) = ctx->r12;
    // 0x800797CC: b           L_800797D4
    // 0x800797D0: nop

        goto L_800797D4;
    // 0x800797D0: nop

L_800797D4:
    // 0x800797D4: b           L_800797E4
    // 0x800797D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800797E4;
    // 0x800797D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800797DC: b           L_800797E4
    // 0x800797E0: nop

        goto L_800797E4;
    // 0x800797E0: nop

L_800797E4:
    // 0x800797E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800797E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800797EC: jr          $ra
    // 0x800797F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800797F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800B55B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B55B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B55B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B55B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B55BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B55C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B55C4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B55C8: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B55CC: nop

    // 0x800B55D0: bne         $t6, $zero, L_800B55E8
    if (ctx->r14 != 0) {
        // 0x800B55D4: nop
    
            goto L_800B55E8;
    }
    // 0x800B55D4: nop

    // 0x800B55D8: jal         0x8000D164
    // 0x800B55DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    TempHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x800B55DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800B55E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B55E4: sw          $v0, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = ctx->r2;
L_800B55E8:
    // 0x800B55E8: ori         $t7, $zero, 0xC002
    ctx->r15 = 0 | 0XC002;
    // 0x800B55EC: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B55F0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800B55F4: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x800B55F8: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B55FC: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x800B5600: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x800B5604: sh          $zero, 0xA($t1)
    MEM_H(0XA, ctx->r9) = 0;
    // 0x800B5608: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x800B560C: lhu         $s1, 0xA($t2)
    ctx->r17 = MEM_HU(ctx->r10, 0XA);
    // 0x800B5610: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x800B5614: sh          $s1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r17;
    // 0x800B5618: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800B561C: sh          $s0, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r16;
    // 0x800B5620: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x800B5624: sh          $s0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r16;
    // 0x800B5628: jal         0x800B6A00
    // 0x800B562C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800B6A00(rdram, ctx);
        goto after_1;
    // 0x800B562C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x800B5630: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800B5634: beq         $at, $zero, L_800B5644
    if (ctx->r1 == 0) {
        // 0x800B5638: nop
    
            goto L_800B5644;
    }
    // 0x800B5638: nop

    // 0x800B563C: b           L_800B56DC
    // 0x800B5640: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B56DC;
    // 0x800B5640: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B5644:
    // 0x800B5644: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B5648: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B564C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B5650: nop

    // 0x800B5654: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800B5658: jal         0x800B8398
    // 0x800B565C: nop

    func_800B8398(rdram, ctx);
        goto after_2;
    // 0x800B565C: nop

    after_2:
    // 0x800B5660: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800B5664: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x800B5668: nop

    // 0x800B566C: sh          $v0, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r2;
    // 0x800B5670: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B5674: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B5678: nop

    // 0x800B567C: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x800B5680: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B5684: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x800B5688: nop

    // 0x800B568C: sh          $zero, 0x8($t9)
    MEM_H(0X8, ctx->r25) = 0;
    // 0x800B5690: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B5694: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B5698: nop

    // 0x800B569C: sh          $zero, 0xA($t0)
    MEM_H(0XA, ctx->r8) = 0;
    // 0x800B56A0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800B56A4: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x800B56A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B56AC: nop

    // 0x800B56B0: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x800B56B4: jal         0x800B5730
    // 0x800B56B8: nop

    func_800B5730(rdram, ctx);
        goto after_3;
    // 0x800B56B8: nop

    after_3:
    // 0x800B56BC: beq         $v0, $zero, L_800B56CC
    if (ctx->r2 == 0) {
        // 0x800B56C0: nop
    
            goto L_800B56CC;
    }
    // 0x800B56C0: nop

    // 0x800B56C4: b           L_800B56DC
    // 0x800B56C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B56DC;
    // 0x800B56C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B56CC:
    // 0x800B56CC: b           L_800B56DC
    // 0x800B56D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B56DC;
    // 0x800B56D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B56D4: b           L_800B56DC
    // 0x800B56D8: nop

        goto L_800B56DC;
    // 0x800B56D8: nop

L_800B56DC:
    // 0x800B56DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B56E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B56E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B56E8: jr          $ra
    // 0x800B56EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B56EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80067624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006762C: jal         0x80061488
    // 0x80067630: addiu       $a0, $zero, 0x2F4
    ctx->r4 = ADD32(0, 0X2F4);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067630: addiu       $a0, $zero, 0x2F4
    ctx->r4 = ADD32(0, 0X2F4);
    after_0:
    // 0x80067634: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067638: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006763C: b           L_8006764C
    // 0x80067640: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006764C;
    // 0x80067640: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067644: b           L_8006764C
    // 0x80067648: nop

        goto L_8006764C;
    // 0x80067648: nop

L_8006764C:
    // 0x8006764C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067654: jr          $ra
    // 0x80067658: nop

    return;
    // 0x80067658: nop

;}
