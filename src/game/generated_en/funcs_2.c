#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800124B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800124B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800124BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800124C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800124C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800124C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800124CC: jal         0x8000DA44
    // 0x800124D0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800124D0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800124D4: bgez        $v0, L_800124E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800124D8: nop

            goto L_800124E4;
    }
    // 0x800124D8: nop

    // 0x800124DC: b           L_80012624
    // 0x800124E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012624;
    // 0x800124E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800124E4:
    // 0x800124E4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800124E8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800124EC: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800124F0: nop

    // 0x800124F4: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800124F8: bne         $at, $zero, L_80012518
    if (ctx->r1 != 0) {
        // 0x800124FC: nop

            goto L_80012518;
    }
    // 0x800124FC: nop

    // 0x80012500: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80012504: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80012508: beq         $at, $zero, L_80012518
    if (ctx->r1 == 0) {
        // 0x8001250C: nop

            goto L_80012518;
    }
    // 0x8001250C: nop

    // 0x80012510: b           L_80012624
    // 0x80012514: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012624;
    // 0x80012514: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012518:
    // 0x80012518: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8001251C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80012520: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80012524: nop

    // 0x80012528: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x8001252C: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x80012530: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80012534: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80012538: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8001253C: nop

    // 0x80012540: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012544: swc1        $f6, 0x1B0($t3)
    MEM_W(0X1B0, ctx->r11) = ctx->f6.u32l;
    // 0x80012548: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x8001254C: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x80012550: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80012554: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80012558: lwc1        $f16, -0x71C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8001255C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80012560: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80012564: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80012568: swc1        $f18, 0x1B4($t6)
    MEM_W(0X1B4, ctx->r14) = ctx->f18.u32l;
    // 0x8001256C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80012570: nop

    // 0x80012574: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x80012578: nop

    // 0x8001257C: bne         $t8, $zero, L_80012598
    if (ctx->r24 != 0) {
        // 0x80012580: nop

            goto L_80012598;
    }
    // 0x80012580: nop

    // 0x80012584: jal         0x8000D164
    // 0x80012588: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    TempHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x80012588: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x8001258C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80012590: nop

    // 0x80012594: sw          $v0, 0x20C($t9)
    MEM_W(0X20C, ctx->r25) = ctx->r2;
L_80012598:
    // 0x80012598: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001259C: nop

    // 0x800125A0: lw          $t1, 0x20C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20C);
    // 0x800125A4: nop

    // 0x800125A8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800125AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800125B0: jal         0x8000E3D4
    // 0x800125B4: nop

    func_8000E3D4(rdram, ctx);
        goto after_2;
    // 0x800125B4: nop

    after_2:
    // 0x800125B8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800125BC: nop

    // 0x800125C0: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x800125C4: addiu       $t3, $sp, 0x2C
    ctx->r11 = ADD32(ctx->r29, 0X2C);
    // 0x800125C8: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x800125CC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800125D0: nop

    // 0x800125D4: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x800125D8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800125DC: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x800125E0: lhu         $a2, 0x2($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X2);
    // 0x800125E4: lwc1        $f4, 0x1B4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B4);
    // 0x800125E8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800125EC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800125F0: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x800125F4: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x800125F8: lw          $a3, 0x1B0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1B0);
    // 0x800125FC: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80012600: jal         0x800298A4
    // 0x80012604: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800298A4(rdram, ctx);
        goto after_3;
    // 0x80012604: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80012608: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001260C: nop

    // 0x80012610: sw          $v0, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->r2;
    // 0x80012614: b           L_80012624
    // 0x80012618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012624;
    // 0x80012618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001261C: b           L_80012624
    // 0x80012620: nop

        goto L_80012624;
    // 0x80012620: nop

L_80012624:
    // 0x80012624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012628: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001262C: jr          $ra
    // 0x80012630: nop

    return;
    // 0x80012630: nop

;}
RECOMP_FUNC void func_80012634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012634: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80012638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001263C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80012640: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80012644: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80012648: jal         0x8000DA44
    // 0x8001264C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x8001264C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80012650: bgez        $v0, L_80012660
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012654: nop

            goto L_80012660;
    }
    // 0x80012654: nop

    // 0x80012658: b           L_80012788
    // 0x8001265C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012788;
    // 0x8001265C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012660:
    // 0x80012660: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80012664: nop

    // 0x80012668: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001266C: nop

    // 0x80012670: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80012674: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80012678: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8001267C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80012680: nop

    // 0x80012684: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x80012688: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x8001268C: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    // 0x80012690: jal         0x80014BD4
    // 0x80012694: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80012694: nop

    after_1:
    // 0x80012698: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8001269C: nop

    // 0x800126A0: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x800126A4: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800126A8: lhu         $a0, 0x6($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X6);
    // 0x800126AC: jal         0x80014BD4
    // 0x800126B0: nop

    func_80014BD4(rdram, ctx);
        goto after_2;
    // 0x800126B0: nop

    after_2:
    // 0x800126B4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800126B8: nop

    // 0x800126BC: swc1        $f0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f0.u32l;
    // 0x800126C0: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800126C4: lhu         $a0, 0x8($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X8);
    // 0x800126C8: jal         0x80014BD4
    // 0x800126CC: nop

    func_80014BD4(rdram, ctx);
        goto after_3;
    // 0x800126CC: nop

    after_3:
    // 0x800126D0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800126D4: nop

    // 0x800126D8: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x800126DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800126E0: nop

    // 0x800126E4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800126E8: nop

    // 0x800126EC: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x800126F0: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x800126F4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800126F8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800126FC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80012700: nop

    // 0x80012704: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80012708: lhu         $t2, 0x6($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X6);
    // 0x8001270C: nop

    // 0x80012710: blez        $t2, L_80012778
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80012714: nop

            goto L_80012778;
    }
    // 0x80012714: nop

L_80012718:
    // 0x80012718: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001271C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80012720: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80012724: nop

    // 0x80012728: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8001272C: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x80012730: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80012734: nop

    // 0x80012738: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x8001273C: nop

    // 0x80012740: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80012744: sw          $t9, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r25;
    // 0x80012748: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001274C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80012750: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80012754: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80012758: addiu       $t2, $t0, 0x160
    ctx->r10 = ADD32(ctx->r8, 0X160);
    // 0x8001275C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80012760: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80012764: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80012768: nop

    // 0x8001276C: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80012770: bne         $at, $zero, L_80012718
    if (ctx->r1 != 0) {
        // 0x80012774: nop

            goto L_80012718;
    }
    // 0x80012774: nop

L_80012778:
    // 0x80012778: b           L_80012788
    // 0x8001277C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012788;
    // 0x8001277C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012780: b           L_80012788
    // 0x80012784: nop

        goto L_80012788;
    // 0x80012784: nop

L_80012788:
    // 0x80012788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001278C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80012790: jr          $ra
    // 0x80012794: nop

    return;
    // 0x80012794: nop

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
RECOMP_FUNC void func_8001292C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001292C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80012930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012934: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80012938: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001293C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80012940: jal         0x8000DA44
    // 0x80012944: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012944: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80012948: bgez        $v0, L_80012958
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001294C: nop

            goto L_80012958;
    }
    // 0x8001294C: nop

    // 0x80012950: b           L_800129EC
    // 0x80012954: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800129EC;
    // 0x80012954: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012958:
    // 0x80012958: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001295C: nop

    // 0x80012960: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80012964: nop

    // 0x80012968: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001296C: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x80012970: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80012974: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80012978: nop

    // 0x8001297C: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x80012980: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80012984: nop

    // 0x80012988: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8001298C: nop

    // 0x80012990: lh          $t3, 0x11E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X11E);
    // 0x80012994: nop

    // 0x80012998: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8001299C: nop

    // 0x800129A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800129A4: swc1        $f6, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f6.u32l;
    // 0x800129A8: addiu       $t4, $sp, 0x1C
    ctx->r12 = ADD32(ctx->r29, 0X1C);
    // 0x800129AC: lhu         $a0, 0x4($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X4);
    // 0x800129B0: jal         0x80014BD4
    // 0x800129B4: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x800129B4: nop

    after_1:
    // 0x800129B8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800129BC: nop

    // 0x800129C0: swc1        $f0, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f0.u32l;
    // 0x800129C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800129C8: nop

    // 0x800129CC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800129D0: nop

    // 0x800129D4: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x800129D8: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x800129DC: b           L_800129EC
    // 0x800129E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800129EC;
    // 0x800129E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800129E4: b           L_800129EC
    // 0x800129E8: nop

        goto L_800129EC;
    // 0x800129E8: nop

L_800129EC:
    // 0x800129EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800129F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800129F4: jr          $ra
    // 0x800129F8: nop

    return;
    // 0x800129F8: nop

;}
RECOMP_FUNC void func_800129FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800129FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80012A00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012A04: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80012A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012A0C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80012A10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80012A14: jal         0x8000DA44
    // 0x80012A18: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012A18: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80012A1C: bgez        $v0, L_80012A2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012A20: nop

            goto L_80012A2C;
    }
    // 0x80012A20: nop

    // 0x80012A24: b           L_80012E6C
    // 0x80012A28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012E6C;
    // 0x80012A28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012A2C:
    // 0x80012A2C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80012A30: nop

    // 0x80012A34: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80012A38: nop

    // 0x80012A3C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80012A40: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x80012A44: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80012A48: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80012A4C: nop

    // 0x80012A50: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x80012A54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80012A58: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80012A5C: nop

    // 0x80012A60: swc1        $f4, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f4.u32l;
    // 0x80012A64: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012A68: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80012A6C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80012A70: nop

    // 0x80012A74: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80012A78: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80012A7C: addiu       $t5, $sp, 0x2C
    ctx->r13 = ADD32(ctx->r29, 0X2C);
    // 0x80012A80: lh          $s0, 0x4($t5)
    ctx->r16 = MEM_H(ctx->r13, 0X4);
    // 0x80012A84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012A88: beq         $s0, $at, L_80012AB0
    if (ctx->r16 == ctx->r1) {
        // 0x80012A8C: nop

            goto L_80012AB0;
    }
    // 0x80012A8C: nop

    // 0x80012A90: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80012A94: beq         $s0, $at, L_80012B3C
    if (ctx->r16 == ctx->r1) {
        // 0x80012A98: nop

            goto L_80012B3C;
    }
    // 0x80012A98: nop

    // 0x80012A9C: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80012AA0: beq         $s0, $at, L_80012BB0
    if (ctx->r16 == ctx->r1) {
        // 0x80012AA4: nop

            goto L_80012BB0;
    }
    // 0x80012AA4: nop

    // 0x80012AA8: b           L_80012C3C
    // 0x80012AAC: nop

        goto L_80012C3C;
    // 0x80012AAC: nop

L_80012AB0:
    // 0x80012AB0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80012AB4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012AB8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80012ABC: nop

    // 0x80012AC0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80012AC4: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80012AC8: nop

    // 0x80012ACC: blez        $t8, L_80012B34
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80012AD0: nop

            goto L_80012B34;
    }
    // 0x80012AD0: nop

L_80012AD4:
    // 0x80012AD4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80012AD8: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80012ADC: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x80012AE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80012AE4: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80012AE8: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
    // 0x80012AEC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80012AF0: nop

    // 0x80012AF4: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80012AF8: nop

    // 0x80012AFC: ori         $t2, $t4, 0x200
    ctx->r10 = ctx->r12 | 0X200;
    // 0x80012B00: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
    // 0x80012B04: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80012B08: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80012B0C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80012B10: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80012B14: addiu       $t8, $t6, 0x160
    ctx->r24 = ADD32(ctx->r14, 0X160);
    // 0x80012B18: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80012B1C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80012B20: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x80012B24: nop

    // 0x80012B28: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80012B2C: bne         $at, $zero, L_80012AD4
    if (ctx->r1 != 0) {
        // 0x80012B30: nop

            goto L_80012AD4;
    }
    // 0x80012B30: nop

L_80012B34:
    // 0x80012B34: b           L_80012E5C
    // 0x80012B38: nop

        goto L_80012E5C;
    // 0x80012B38: nop

L_80012B3C:
    // 0x80012B3C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80012B40: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012B44: lw          $t4, 0xC($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XC);
    // 0x80012B48: nop

    // 0x80012B4C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80012B50: lhu         $t2, 0x6($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X6);
    // 0x80012B54: nop

    // 0x80012B58: blez        $t2, L_80012BA8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80012B5C: nop

            goto L_80012BA8;
    }
    // 0x80012B5C: nop

L_80012B60:
    // 0x80012B60: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80012B64: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80012B68: lw          $t5, 0xC0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC0);
    // 0x80012B6C: ori         $at, $at, 0xFDFF
    ctx->r1 = ctx->r1 | 0XFDFF;
    // 0x80012B70: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80012B74: sw          $t6, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r14;
    // 0x80012B78: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80012B7C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80012B80: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80012B84: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80012B88: addiu       $t1, $t7, 0x160
    ctx->r9 = ADD32(ctx->r15, 0X160);
    // 0x80012B8C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80012B90: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80012B94: lhu         $t9, 0x6($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X6);
    // 0x80012B98: nop

    // 0x80012B9C: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80012BA0: bne         $at, $zero, L_80012B60
    if (ctx->r1 != 0) {
        // 0x80012BA4: nop

            goto L_80012B60;
    }
    // 0x80012BA4: nop

L_80012BA8:
    // 0x80012BA8: b           L_80012E5C
    // 0x80012BAC: nop

        goto L_80012E5C;
    // 0x80012BAC: nop

L_80012BB0:
    // 0x80012BB0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012BB4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012BB8: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x80012BBC: nop

    // 0x80012BC0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80012BC4: lhu         $t6, 0x6($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X6);
    // 0x80012BC8: nop

    // 0x80012BCC: blez        $t6, L_80012C34
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80012BD0: nop

            goto L_80012C34;
    }
    // 0x80012BD0: nop

L_80012BD4:
    // 0x80012BD4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80012BD8: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80012BDC: lw          $t8, 0xC0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0XC0);
    // 0x80012BE0: nop

    // 0x80012BE4: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x80012BE8: sw          $t7, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r15;
    // 0x80012BEC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80012BF0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80012BF4: lw          $t4, 0xC0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC0);
    // 0x80012BF8: nop

    // 0x80012BFC: or          $t0, $t4, $at
    ctx->r8 = ctx->r12 | ctx->r1;
    // 0x80012C00: sw          $t0, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r8;
    // 0x80012C04: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80012C08: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80012C0C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80012C10: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x80012C14: addiu       $t6, $t2, 0x160
    ctx->r14 = ADD32(ctx->r10, 0X160);
    // 0x80012C18: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80012C1C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80012C20: lhu         $t7, 0x6($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X6);
    // 0x80012C24: nop

    // 0x80012C28: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80012C2C: bne         $at, $zero, L_80012BD4
    if (ctx->r1 != 0) {
        // 0x80012C30: nop

            goto L_80012BD4;
    }
    // 0x80012C30: nop

L_80012C34:
    // 0x80012C34: b           L_80012E5C
    // 0x80012C38: nop

        goto L_80012E5C;
    // 0x80012C38: nop

L_80012C3C:
    // 0x80012C3C: addiu       $t3, $sp, 0x2C
    ctx->r11 = ADD32(ctx->r29, 0X2C);
    // 0x80012C40: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80012C44: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80012C48: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80012C4C: nop

    // 0x80012C50: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80012C54: swc1        $f8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f8.u32l;
    // 0x80012C58: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80012C5C: lh          $t1, 0x721C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X721C);
    // 0x80012C60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80012C64: bne         $t1, $at, L_80012DD8
    if (ctx->r9 != ctx->r1) {
        // 0x80012C68: nop

            goto L_80012DD8;
    }
    // 0x80012C68: nop

    // 0x80012C6C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80012C70: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80012C74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80012C78: lwc1        $f10, 0x24($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X24);
    // 0x80012C7C: nop

    // 0x80012C80: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80012C84: nop

    // 0x80012C88: bc1f        L_80012D34
    if (!c1cs) {
        // 0x80012C8C: nop

            goto L_80012D34;
    }
    // 0x80012C8C: nop

    // 0x80012C90: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012C94: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012C98: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x80012C9C: nop

    // 0x80012CA0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80012CA4: lhu         $t8, 0x6($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X6);
    // 0x80012CA8: nop

    // 0x80012CAC: blez        $t8, L_80012D2C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80012CB0: nop

            goto L_80012D2C;
    }
    // 0x80012CB0: nop

L_80012CB4:
    // 0x80012CB4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80012CB8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80012CBC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80012CC0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012CC4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012CC8: lwc1        $f18, 0x24($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X24);
    // 0x80012CCC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80012CD0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80012CD4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80012CD8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80012CDC: sh          $t3, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r11;
    // 0x80012CE0: nop

    // 0x80012CE4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80012CE8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80012CEC: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x80012CF0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80012CF4: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x80012CF8: sw          $t9, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r25;
    // 0x80012CFC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80012D00: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80012D04: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80012D08: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x80012D0C: addiu       $t5, $t8, 0x160
    ctx->r13 = ADD32(ctx->r24, 0X160);
    // 0x80012D10: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80012D14: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80012D18: lhu         $t3, 0x6($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X6);
    // 0x80012D1C: nop

    // 0x80012D20: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80012D24: bne         $at, $zero, L_80012CB4
    if (ctx->r1 != 0) {
        // 0x80012D28: nop

            goto L_80012CB4;
    }
    // 0x80012D28: nop

L_80012D2C:
    // 0x80012D2C: b           L_80012DD0
    // 0x80012D30: nop

        goto L_80012DD0;
    // 0x80012D30: nop

L_80012D34:
    // 0x80012D34: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80012D38: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012D3C: lw          $t1, 0xC($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC);
    // 0x80012D40: nop

    // 0x80012D44: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80012D48: lhu         $t9, 0x6($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X6);
    // 0x80012D4C: nop

    // 0x80012D50: blez        $t9, L_80012DD0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80012D54: nop

            goto L_80012DD0;
    }
    // 0x80012D54: nop

L_80012D58:
    // 0x80012D58: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80012D5C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80012D60: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80012D64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012D68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012D6C: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80012D70: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80012D74: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80012D78: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80012D7C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80012D80: sh          $t8, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r24;
    // 0x80012D84: nop

    // 0x80012D88: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80012D8C: nop

    // 0x80012D90: lw          $t2, 0xC0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0XC0);
    // 0x80012D94: nop

    // 0x80012D98: ori         $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 | 0X8000;
    // 0x80012D9C: sw          $t3, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r11;
    // 0x80012DA0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80012DA4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80012DA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80012DAC: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x80012DB0: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80012DB4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80012DB8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80012DBC: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80012DC0: nop

    // 0x80012DC4: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80012DC8: bne         $at, $zero, L_80012D58
    if (ctx->r1 != 0) {
        // 0x80012DCC: nop

            goto L_80012D58;
    }
    // 0x80012DCC: nop

L_80012DD0:
    // 0x80012DD0: b           L_80012E5C
    // 0x80012DD4: nop

        goto L_80012E5C;
    // 0x80012DD4: nop

L_80012DD8:
    // 0x80012DD8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80012DDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80012DE0: lw          $t2, 0xC($t5)
    ctx->r10 = MEM_W(ctx->r13, 0XC);
    // 0x80012DE4: nop

    // 0x80012DE8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80012DEC: lhu         $t3, 0x6($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X6);
    // 0x80012DF0: nop

    // 0x80012DF4: blez        $t3, L_80012E5C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80012DF8: nop

            goto L_80012E5C;
    }
    // 0x80012DF8: nop

L_80012DFC:
    // 0x80012DFC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80012E00: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80012E04: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80012E08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012E0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012E10: lwc1        $f10, 0x24($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X24);
    // 0x80012E14: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80012E18: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80012E1C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80012E20: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80012E24: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
    // 0x80012E28: nop

    // 0x80012E2C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80012E30: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80012E34: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80012E38: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x80012E3C: addiu       $t2, $t8, 0x160
    ctx->r10 = ADD32(ctx->r24, 0X160);
    // 0x80012E40: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80012E44: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80012E48: lhu         $t3, 0x6($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X6);
    // 0x80012E4C: nop

    // 0x80012E50: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80012E54: bne         $at, $zero, L_80012DFC
    if (ctx->r1 != 0) {
        // 0x80012E58: nop

            goto L_80012DFC;
    }
    // 0x80012E58: nop

L_80012E5C:
    // 0x80012E5C: b           L_80012E6C
    // 0x80012E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012E6C;
    // 0x80012E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012E64: b           L_80012E6C
    // 0x80012E68: nop

        goto L_80012E6C;
    // 0x80012E68: nop

L_80012E6C:
    // 0x80012E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80012E70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012E74: jr          $ra
    // 0x80012E78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80012E78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80012E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012E7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80012E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012E84: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80012E88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80012E8C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80012E90: jal         0x8000DA44
    // 0x80012E94: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012E94: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80012E98: bgez        $v0, L_80012EA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012E9C: nop

            goto L_80012EA8;
    }
    // 0x80012E9C: nop

    // 0x80012EA0: b           L_800131E4
    // 0x80012EA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800131E4;
    // 0x80012EA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012EA8:
    // 0x80012EA8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80012EAC: nop

    // 0x80012EB0: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80012EB4: nop

    // 0x80012EB8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80012EBC: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80012EC0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80012EC4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80012EC8: nop

    // 0x80012ECC: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x80012ED0: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80012ED4: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x80012ED8: nop

    // 0x80012EDC: beq         $t2, $zero, L_80012EF4
    if (ctx->r10 == 0) {
        // 0x80012EE0: nop

            goto L_80012EF4;
    }
    // 0x80012EE0: nop

    // 0x80012EE4: lhu         $t3, 0x8($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X8);
    // 0x80012EE8: nop

    // 0x80012EEC: bne         $t3, $zero, L_80012F64
    if (ctx->r11 != 0) {
        // 0x80012EF0: nop

            goto L_80012F64;
    }
    // 0x80012EF0: nop

L_80012EF4:
    // 0x80012EF4: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x80012EF8: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80012EFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012F00: beq         $t5, $at, L_80012F10
    if (ctx->r13 == ctx->r1) {
        // 0x80012F04: nop

            goto L_80012F10;
    }
    // 0x80012F04: nop

    // 0x80012F08: bne         $t5, $zero, L_80012F28
    if (ctx->r13 != 0) {
        // 0x80012F0C: nop

            goto L_80012F28;
    }
    // 0x80012F0C: nop

L_80012F10:
    // 0x80012F10: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80012F14: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80012F18: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80012F1C: nop

    // 0x80012F20: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80012F24: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
L_80012F28:
    // 0x80012F28: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x80012F2C: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x80012F30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80012F34: beq         $t0, $at, L_80012F44
    if (ctx->r8 == ctx->r1) {
        // 0x80012F38: nop

            goto L_80012F44;
    }
    // 0x80012F38: nop

    // 0x80012F3C: bne         $t0, $zero, L_80012F5C
    if (ctx->r8 != 0) {
        // 0x80012F40: nop

            goto L_80012F5C;
    }
    // 0x80012F40: nop

L_80012F44:
    // 0x80012F44: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80012F48: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x80012F4C: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x80012F50: nop

    // 0x80012F54: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80012F58: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
L_80012F5C:
    // 0x80012F5C: b           L_800131E4
    // 0x80012F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800131E4;
    // 0x80012F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012F64:
    // 0x80012F64: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x80012F68: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80012F6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012F70: beq         $t5, $at, L_80012F80
    if (ctx->r13 == ctx->r1) {
        // 0x80012F74: nop

            goto L_80012F80;
    }
    // 0x80012F74: nop

    // 0x80012F78: bne         $t5, $zero, L_8001309C
    if (ctx->r13 != 0) {
        // 0x80012F7C: nop

            goto L_8001309C;
    }
    // 0x80012F7C: nop

L_80012F80:
    // 0x80012F80: addiu       $t7, $sp, 0x20
    ctx->r15 = ADD32(ctx->r29, 0X20);
    // 0x80012F84: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x80012F88: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x80012F8C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80012F90: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80012F94: mfhi        $t6
    ctx->r14 = hi;
    // 0x80012F98: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80012F9C: nop

    // 0x80012FA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012FA4: swc1        $f6, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f6.u32l;
    // 0x80012FA8: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x80012FAC: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x80012FB0: nop

    // 0x80012FB4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80012FB8: bgez        $t1, L_80012FD0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80012FBC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80012FD0;
    }
    // 0x80012FBC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80012FC0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80012FC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80012FC8: nop

    // 0x80012FCC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80012FD0:
    // 0x80012FD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80012FD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012FD8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80012FDC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80012FE0: lwc1        $f9, -0x2AF8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2AF8);
    // 0x80012FE4: lwc1        $f8, -0x2AF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2AF4);
    // 0x80012FE8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80012FEC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80012FF0: nop

    // 0x80012FF4: div.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d);
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x80012FF8: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80012FFC: swc1        $f10, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f10.u32l;
    // 0x80013000: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x80013004: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x80013008: nop

    // 0x8001300C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80013010: bgez        $t4, L_8001302C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80013014: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_8001302C;
    }
    // 0x80013014: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80013018: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8001301C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80013020: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80013024: nop

    // 0x80013028: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_8001302C:
    // 0x8001302C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80013030: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80013034: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80013038: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001303C: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80013040: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80013044: swc1        $f10, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f10.u32l;
    // 0x80013048: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8001304C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80013050: lwc1        $f18, 0x2C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x80013054: lwc1        $f5, -0x2AF0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2AF0);
    // 0x80013058: lwc1        $f4, -0x2AEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AEC);
    // 0x8001305C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80013060: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80013064: jal         0x800C3070
    // 0x80013068: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x80013068: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_1:
    // 0x8001306C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80013070: nop

    // 0x80013074: lwc1        $f16, 0x34($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X34);
    // 0x80013078: nop

    // 0x8001307C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80013080: swc1        $f10, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f10.u32l;
    // 0x80013084: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80013088: nop

    // 0x8001308C: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x80013090: nop

    // 0x80013094: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80013098: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
L_8001309C:
    // 0x8001309C: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x800130A0: lhu         $t3, 0x4($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X4);
    // 0x800130A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800130A8: beq         $t3, $at, L_800130B8
    if (ctx->r11 == ctx->r1) {
        // 0x800130AC: nop

            goto L_800130B8;
    }
    // 0x800130AC: nop

    // 0x800130B0: bne         $t3, $zero, L_800131D4
    if (ctx->r11 != 0) {
        // 0x800130B4: nop

            goto L_800131D4;
    }
    // 0x800130B4: nop

L_800130B8:
    // 0x800130B8: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x800130BC: lh          $t4, 0xA($t2)
    ctx->r12 = MEM_H(ctx->r10, 0XA);
    // 0x800130C0: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800130C4: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800130C8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800130CC: mfhi        $t5
    ctx->r13 = hi;
    // 0x800130D0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800130D4: nop

    // 0x800130D8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800130DC: swc1        $f8, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f8.u32l;
    // 0x800130E0: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x800130E4: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800130E8: nop

    // 0x800130EC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800130F0: bgez        $t9, L_80013108
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800130F4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80013108;
    }
    // 0x800130F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800130F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800130FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013100: nop

    // 0x80013104: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80013108:
    // 0x80013108: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001310C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80013110: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80013114: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80013118: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8001311C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80013120: lwc1        $f5, -0x2AE8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2AE8);
    // 0x80013124: lwc1        $f4, -0x2AE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AE4);
    // 0x80013128: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8001312C: div.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80013130: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x80013134: swc1        $f6, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f6.u32l;
    // 0x80013138: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x8001313C: lhu         $t1, 0x6($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X6);
    // 0x80013140: nop

    // 0x80013144: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80013148: bgez        $t1, L_80013164
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001314C: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_80013164;
    }
    // 0x8001314C: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x80013150: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80013154: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80013158: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001315C: nop

    // 0x80013160: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_80013164:
    // 0x80013164: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80013168: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001316C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80013170: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80013174: mul.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80013178: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8001317C: swc1        $f6, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f6.u32l;
    // 0x80013180: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80013184: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80013188: lwc1        $f10, 0x3C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X3C);
    // 0x8001318C: lwc1        $f19, -0x2AE0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2AE0);
    // 0x80013190: lwc1        $f18, -0x2ADC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2ADC);
    // 0x80013194: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80013198: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8001319C: jal         0x800C3070
    // 0x800131A0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_2;
    // 0x800131A0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_2:
    // 0x800131A4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800131A8: nop

    // 0x800131AC: lwc1        $f16, 0x44($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X44);
    // 0x800131B0: nop

    // 0x800131B4: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800131B8: swc1        $f6, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f6.u32l;
    // 0x800131BC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800131C0: nop

    // 0x800131C4: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x800131C8: nop

    // 0x800131CC: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x800131D0: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
L_800131D4:
    // 0x800131D4: b           L_800131E4
    // 0x800131D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800131E4;
    // 0x800131D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800131DC: b           L_800131E4
    // 0x800131E0: nop

        goto L_800131E4;
    // 0x800131E0: nop

L_800131E4:
    // 0x800131E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800131E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800131EC: jr          $ra
    // 0x800131F0: nop

    return;
    // 0x800131F0: nop

;}
RECOMP_FUNC void func_800131F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800131F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800131F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800131FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80013200: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80013204: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80013208: jal         0x8000DA44
    // 0x8001320C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x8001320C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80013210: bgez        $v0, L_80013220
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013214: nop

            goto L_80013220;
    }
    // 0x80013214: nop

    // 0x80013218: b           L_80013388
    // 0x8001321C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013388;
    // 0x8001321C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013220:
    // 0x80013220: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80013224: nop

    // 0x80013228: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001322C: nop

    // 0x80013230: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80013234: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x80013238: lhu         $a0, 0x4($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X4);
    // 0x8001323C: jal         0x8000D688
    // 0x80013240: nop

    func_8000D688(rdram, ctx);
        goto after_1;
    // 0x80013240: nop

    after_1:
    // 0x80013244: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80013248: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8001324C: nop

    // 0x80013250: bne         $t9, $zero, L_80013260
    if (ctx->r25 != 0) {
        // 0x80013254: nop

            goto L_80013260;
    }
    // 0x80013254: nop

    // 0x80013258: b           L_80013388
    // 0x8001325C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013388;
    // 0x8001325C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013260:
    // 0x80013260: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80013264: nop

    // 0x80013268: lw          $t1, 0x20C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20C);
    // 0x8001326C: nop

    // 0x80013270: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80013274: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80013278: nop

    // 0x8001327C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80013280: nop

    // 0x80013284: lw          $t4, 0xC8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC8);
    // 0x80013288: nop

    // 0x8001328C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80013290: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80013294: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80013298: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8001329C: nop

    // 0x800132A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800132A4: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x800132A8: nop

    // 0x800132AC: blez        $t7, L_80013300
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800132B0: nop

            goto L_80013300;
    }
    // 0x800132B0: nop

L_800132B4:
    // 0x800132B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800132B8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800132BC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800132C0: nop

    // 0x800132C4: lw          $t0, 0xC8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC8);
    // 0x800132C8: nop

    // 0x800132CC: sw          $t0, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r8;
    // 0x800132D0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800132D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800132D8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800132DC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800132E0: addiu       $t6, $t4, 0x160
    ctx->r14 = ADD32(ctx->r12, 0X160);
    // 0x800132E4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800132E8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800132EC: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x800132F0: nop

    // 0x800132F4: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800132F8: bne         $at, $zero, L_800132B4
    if (ctx->r1 != 0) {
        // 0x800132FC: nop

            goto L_800132B4;
    }
    // 0x800132FC: nop

L_80013300:
    // 0x80013300: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80013304: nop

    // 0x80013308: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8001330C: nop

    // 0x80013310: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80013314: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80013318: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8001331C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80013320: nop

    // 0x80013324: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80013328: lhu         $t2, 0x6($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X6);
    // 0x8001332C: nop

    // 0x80013330: blez        $t2, L_80013378
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80013334: nop

            goto L_80013378;
    }
    // 0x80013334: nop

L_80013338:
    // 0x80013338: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8001333C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80013340: nop

    // 0x80013344: sw          $t4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r12;
    // 0x80013348: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8001334C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80013350: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80013354: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x80013358: addiu       $t8, $t7, 0x160
    ctx->r24 = ADD32(ctx->r15, 0X160);
    // 0x8001335C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80013360: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80013364: lhu         $t1, 0x6($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X6);
    // 0x80013368: nop

    // 0x8001336C: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80013370: bne         $at, $zero, L_80013338
    if (ctx->r1 != 0) {
        // 0x80013374: nop

            goto L_80013338;
    }
    // 0x80013374: nop

L_80013378:
    // 0x80013378: b           L_80013388
    // 0x8001337C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013388;
    // 0x8001337C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013380: b           L_80013388
    // 0x80013384: nop

        goto L_80013388;
    // 0x80013384: nop

L_80013388:
    // 0x80013388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001338C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80013390: jr          $ra
    // 0x80013394: nop

    return;
    // 0x80013394: nop

;}
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
RECOMP_FUNC void func_800139B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800139B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800139BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800139C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800139C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800139C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800139CC: jal         0x8000DA44
    // 0x800139D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800139D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800139D4: bgez        $v0, L_800139E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800139D8: nop

            goto L_800139E4;
    }
    // 0x800139D8: nop

    // 0x800139DC: b           L_80013AEC
    // 0x800139E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013AEC;
    // 0x800139E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800139E4:
    // 0x800139E4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800139E8: nop

    // 0x800139EC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800139F0: nop

    // 0x800139F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800139F8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800139FC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80013A00: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x80013A04: nop

    // 0x80013A08: beq         $t9, $at, L_80013A18
    if (ctx->r25 == ctx->r1) {
        // 0x80013A0C: nop

            goto L_80013A18;
    }
    // 0x80013A0C: nop

    // 0x80013A10: b           L_80013AEC
    // 0x80013A14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013AEC;
    // 0x80013A14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013A18:
    // 0x80013A18: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80013A1C: nop

    // 0x80013A20: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80013A24: nop

    // 0x80013A28: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x80013A2C: bne         $t2, $zero, L_80013A3C
    if (ctx->r10 != 0) {
        // 0x80013A30: nop

            goto L_80013A3C;
    }
    // 0x80013A30: nop

    // 0x80013A34: b           L_80013AEC
    // 0x80013A38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013AEC;
    // 0x80013A38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013A3C:
    // 0x80013A3C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80013A40: nop

    // 0x80013A44: lw          $t4, 0x5C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X5C);
    // 0x80013A48: nop

    // 0x80013A4C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80013A50: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80013A54: nop

    // 0x80013A58: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80013A5C: jal         0x8001AE90
    // 0x80013A60: nop

    func_8001AE90(rdram, ctx);
        goto after_1;
    // 0x80013A60: nop

    after_1:
    // 0x80013A64: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80013A68: nop

    // 0x80013A6C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80013A70: jal         0x8000D390
    // 0x80013A74: nop

    TempHeap_Free(rdram, ctx);
        goto after_2;
    // 0x80013A74: nop

    after_2:
    // 0x80013A78: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80013A7C: nop

    // 0x80013A80: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x80013A84: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80013A88: nop

    // 0x80013A8C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x80013A90: jal         0x8000D390
    // 0x80013A94: nop

    TempHeap_Free(rdram, ctx);
        goto after_3;
    // 0x80013A94: nop

    after_3:
    // 0x80013A98: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80013A9C: nop

    // 0x80013AA0: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80013AA4: jal         0x8000D390
    // 0x80013AA8: nop

    TempHeap_Free(rdram, ctx);
        goto after_4;
    // 0x80013AA8: nop

    after_4:
    // 0x80013AAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80013AB0: jal         0x8000D390
    // 0x80013AB4: nop

    TempHeap_Free(rdram, ctx);
        goto after_5;
    // 0x80013AB4: nop

    after_5:
    // 0x80013AB8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80013ABC: nop

    // 0x80013AC0: sw          $zero, 0x5C($t0)
    MEM_W(0X5C, ctx->r8) = 0;
    // 0x80013AC4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80013AC8: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80013ACC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80013AD0: nop

    // 0x80013AD4: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80013AD8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80013ADC: b           L_80013AEC
    // 0x80013AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013AEC;
    // 0x80013AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013AE4: b           L_80013AEC
    // 0x80013AE8: nop

        goto L_80013AEC;
    // 0x80013AE8: nop

L_80013AEC:
    // 0x80013AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013AF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80013AF4: jr          $ra
    // 0x80013AF8: nop

    return;
    // 0x80013AF8: nop

;}
RECOMP_FUNC void func_80013AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013AFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80013B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013B04: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80013B08: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80013B0C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80013B10: jal         0x8000DA44
    // 0x80013B14: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80013B14: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80013B18: bgez        $v0, L_80013B28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013B1C: nop

            goto L_80013B28;
    }
    // 0x80013B1C: nop

    // 0x80013B20: b           L_80013C80
    // 0x80013B24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013C80;
    // 0x80013B24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013B28:
    // 0x80013B28: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80013B2C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80013B30: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x80013B34: nop

    // 0x80013B38: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80013B3C: bne         $at, $zero, L_80013B5C
    if (ctx->r1 != 0) {
        // 0x80013B40: nop

            goto L_80013B5C;
    }
    // 0x80013B40: nop

    // 0x80013B44: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80013B48: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80013B4C: beq         $at, $zero, L_80013B5C
    if (ctx->r1 == 0) {
        // 0x80013B50: nop

            goto L_80013B5C;
    }
    // 0x80013B50: nop

    // 0x80013B54: b           L_80013C80
    // 0x80013B58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013C80;
    // 0x80013B58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013B5C:
    // 0x80013B5C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80013B60: nop

    // 0x80013B64: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80013B68: nop

    // 0x80013B6C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80013B70: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80013B74: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x80013B78: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80013B7C: bne         $t1, $at, L_80013BD0
    if (ctx->r9 != ctx->r1) {
        // 0x80013B80: nop

            goto L_80013BD0;
    }
    // 0x80013B80: nop

    // 0x80013B84: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80013B88: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x80013B8C: lhu         $a2, 0x6($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X6);
    // 0x80013B90: addiu       $a0, $t2, 0xC
    ctx->r4 = ADD32(ctx->r10, 0XC);
    // 0x80013B94: jal         0x800B3DBC
    // 0x80013B98: addiu       $a1, $t2, 0x10
    ctx->r5 = ADD32(ctx->r10, 0X10);
    func_800B3DBC(rdram, ctx);
        goto after_1;
    // 0x80013B98: addiu       $a1, $t2, 0x10
    ctx->r5 = ADD32(ctx->r10, 0X10);
    after_1:
    // 0x80013B9C: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80013BA0: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80013BA4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80013BA8: nop

    // 0x80013BAC: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x80013BB0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80013BB4: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x80013BB8: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80013BBC: nop

    // 0x80013BC0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80013BC4: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x80013BC8: b           L_80013C80
    // 0x80013BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013C80;
    // 0x80013BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80013BD0:
    // 0x80013BD0: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80013BD4: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x80013BD8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80013BDC: nop

    // 0x80013BE0: sh          $t1, 0x50($t2)
    MEM_H(0X50, ctx->r10) = ctx->r9;
    // 0x80013BE4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80013BE8: nop

    // 0x80013BEC: lhu         $t4, 0x50($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X50);
    // 0x80013BF0: nop

    // 0x80013BF4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80013BF8: bgez        $t4, L_80013C10
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80013BFC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80013C10;
    }
    // 0x80013BFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013C00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013C04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80013C08: nop

    // 0x80013C0C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80013C10:
    // 0x80013C10: swc1        $f6, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->f6.u32l;
    // 0x80013C14: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80013C18: nop

    // 0x80013C1C: sh          $zero, 0x52($t5)
    MEM_H(0X52, ctx->r13) = 0;
    // 0x80013C20: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80013C24:
    // 0x80013C24: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80013C28: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80013C2C: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80013C30: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80013C34: lhu         $t9, 0x2A($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X2A);
    // 0x80013C38: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80013C3C: sh          $t9, 0x54($t0)
    MEM_H(0X54, ctx->r8) = ctx->r25;
    // 0x80013C40: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80013C44: nop

    // 0x80013C48: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80013C4C: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80013C50: bne         $at, $zero, L_80013C24
    if (ctx->r1 != 0) {
        // 0x80013C54: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_80013C24;
    }
    // 0x80013C54: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80013C58: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80013C5C: nop

    // 0x80013C60: lhu         $t3, 0x0($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X0);
    // 0x80013C64: nop

    // 0x80013C68: ori         $t5, $t3, 0x400
    ctx->r13 = ctx->r11 | 0X400;
    // 0x80013C6C: sh          $t5, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r13;
    // 0x80013C70: b           L_80013C80
    // 0x80013C74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013C80;
    // 0x80013C74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013C78: b           L_80013C80
    // 0x80013C7C: nop

        goto L_80013C80;
    // 0x80013C7C: nop

L_80013C80:
    // 0x80013C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013C84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80013C88: jr          $ra
    // 0x80013C8C: nop

    return;
    // 0x80013C8C: nop

;}
RECOMP_FUNC void func_80013C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013C90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80013C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013C98: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80013C9C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80013CA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80013CA4: jal         0x8000DA44
    // 0x80013CA8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80013CA8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80013CAC: bgez        $v0, L_80013CBC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013CB0: nop

            goto L_80013CBC;
    }
    // 0x80013CB0: nop

    // 0x80013CB4: b           L_80013EF4
    // 0x80013CB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013EF4;
    // 0x80013CB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013CBC:
    // 0x80013CBC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80013CC0: nop

    // 0x80013CC4: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80013CC8: nop

    // 0x80013CCC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80013CD0: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x80013CD4: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x80013CD8: nop

    // 0x80013CDC: beq         $t9, $zero, L_80013ECC
    if (ctx->r25 == 0) {
        // 0x80013CE0: nop

            goto L_80013ECC;
    }
    // 0x80013CE0: nop

    // 0x80013CE4: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x80013CE8: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x80013CEC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80013CF0: nop

    // 0x80013CF4: sh          $t1, 0x84($t2)
    MEM_H(0X84, ctx->r10) = ctx->r9;
    // 0x80013CF8: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x80013CFC: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x80013D00: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80013D04: nop

    // 0x80013D08: sh          $t4, 0x86($t5)
    MEM_H(0X86, ctx->r13) = ctx->r12;
    // 0x80013D0C: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80013D10: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x80013D14: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80013D18: nop

    // 0x80013D1C: sh          $t7, 0x88($t8)
    MEM_H(0X88, ctx->r24) = ctx->r15;
    // 0x80013D20: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x80013D24: lhu         $t0, 0xA($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XA);
    // 0x80013D28: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80013D2C: nop

    // 0x80013D30: sh          $t0, 0x8A($t1)
    MEM_H(0X8A, ctx->r9) = ctx->r8;
    // 0x80013D34: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x80013D38: lhu         $t3, 0xC($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XC);
    // 0x80013D3C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80013D40: nop

    // 0x80013D44: sh          $t3, 0x90($t4)
    MEM_H(0X90, ctx->r12) = ctx->r11;
    // 0x80013D48: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x80013D4C: lhu         $t6, 0xE($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0XE);
    // 0x80013D50: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80013D54: nop

    // 0x80013D58: sh          $t6, 0x8C($t7)
    MEM_H(0X8C, ctx->r15) = ctx->r14;
    // 0x80013D5C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80013D60: nop

    // 0x80013D64: lhu         $t9, 0x84($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X84);
    // 0x80013D68: nop

    // 0x80013D6C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80013D70: bgez        $t9, L_80013D88
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80013D74: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80013D88;
    }
    // 0x80013D74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013D78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013D7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80013D80: nop

    // 0x80013D84: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80013D88:
    // 0x80013D88: swc1        $f6, 0x80($t8)
    MEM_W(0X80, ctx->r24) = ctx->f6.u32l;
    // 0x80013D8C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80013D90: nop

    // 0x80013D94: sh          $zero, 0x8E($t0)
    MEM_H(0X8E, ctx->r8) = 0;
    // 0x80013D98: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80013D9C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80013DA0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80013DA4: nop

    // 0x80013DA8: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80013DAC: lhu         $t3, 0x6($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X6);
    // 0x80013DB0: nop

    // 0x80013DB4: blez        $t3, L_80013EB0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80013DB8: nop

            goto L_80013EB0;
    }
    // 0x80013DB8: nop

L_80013DBC:
    // 0x80013DBC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80013DC0: nop

    // 0x80013DC4: lw          $t5, 0x138($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X138);
    // 0x80013DC8: nop

    // 0x80013DCC: bne         $t5, $zero, L_80013DDC
    if (ctx->r13 != 0) {
        // 0x80013DD0: sw          $t5, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r13;
            goto L_80013DDC;
    }
    // 0x80013DD0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80013DD4: b           L_80013E80
    // 0x80013DD8: nop

        goto L_80013E80;
    // 0x80013DD8: nop

L_80013DDC:
    // 0x80013DDC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80013DE0:
    // 0x80013DE0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80013DE4: nop

    // 0x80013DE8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80013DEC: nop

    // 0x80013DF0: andi        $t9, $t7, 0xFFFE
    ctx->r25 = ctx->r15 & 0XFFFE;
    // 0x80013DF4: bne         $t9, $zero, L_80013E14
    if (ctx->r25 != 0) {
        // 0x80013DF8: nop

            goto L_80013E14;
    }
    // 0x80013DF8: nop

    // 0x80013DFC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80013E00: nop

    // 0x80013E04: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x80013E08: nop

    // 0x80013E0C: andi        $t2, $t0, 0xFFFE
    ctx->r10 = ctx->r8 & 0XFFFE;
    // 0x80013E10: sh          $t2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r10;
L_80013E14:
    // 0x80013E14: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80013E18: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80013E1C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80013E20: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    // 0x80013E24: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80013E28: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80013E2C: bne         $at, $zero, L_80013DE0
    if (ctx->r1 != 0) {
        // 0x80013E30: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_80013DE0;
    }
    // 0x80013E30: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80013E34: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80013E38: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80013E3C: lh          $t5, 0x90($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X90);
    // 0x80013E40: lhu         $t3, 0x8E($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X8E);
    // 0x80013E44: lhu         $t0, 0x86($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X86);
    // 0x80013E48: multu       $t5, $t3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013E4C: lw          $t7, 0x138($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X138);
    // 0x80013E50: lhu         $t8, 0x88($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X88);
    // 0x80013E54: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80013E58: lhu         $a2, 0x8A($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X8A);
    // 0x80013E5C: addu        $a0, $t7, $t2
    ctx->r4 = ADD32(ctx->r15, ctx->r10);
    // 0x80013E60: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x80013E64: addu        $t4, $t7, $t1
    ctx->r12 = ADD32(ctx->r15, ctx->r9);
    // 0x80013E68: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x80013E6C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80013E70: mflo        $t6
    ctx->r14 = lo;
    // 0x80013E74: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x80013E78: jal         0x800BCFCC
    // 0x80013E7C: addu        $a1, $t4, $t0
    ctx->r5 = ADD32(ctx->r12, ctx->r8);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x80013E7C: addu        $a1, $t4, $t0
    ctx->r5 = ADD32(ctx->r12, ctx->r8);
    after_1:
L_80013E80:
    // 0x80013E80: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80013E84: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80013E88: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80013E8C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80013E90: addiu       $t5, $t1, 0x160
    ctx->r13 = ADD32(ctx->r9, 0X160);
    // 0x80013E94: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80013E98: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80013E9C: lhu         $t6, 0x6($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X6);
    // 0x80013EA0: nop

    // 0x80013EA4: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80013EA8: bne         $at, $zero, L_80013DBC
    if (ctx->r1 != 0) {
        // 0x80013EAC: nop

            goto L_80013DBC;
    }
    // 0x80013EAC: nop

L_80013EB0:
    // 0x80013EB0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80013EB4: nop

    // 0x80013EB8: lhu         $t0, 0x0($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0X0);
    // 0x80013EBC: nop

    // 0x80013EC0: ori         $t9, $t0, 0x1000
    ctx->r25 = ctx->r8 | 0X1000;
    // 0x80013EC4: b           L_80013EE4
    // 0x80013EC8: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
        goto L_80013EE4;
    // 0x80013EC8: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
L_80013ECC:
    // 0x80013ECC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80013ED0: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80013ED4: lhu         $t8, 0x0($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X0);
    // 0x80013ED8: nop

    // 0x80013EDC: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x80013EE0: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
L_80013EE4:
    // 0x80013EE4: b           L_80013EF4
    // 0x80013EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013EF4;
    // 0x80013EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013EEC: b           L_80013EF4
    // 0x80013EF0: nop

        goto L_80013EF4;
    // 0x80013EF0: nop

L_80013EF4:
    // 0x80013EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013EF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80013EFC: jr          $ra
    // 0x80013F00: nop

    return;
    // 0x80013F00: nop

;}
RECOMP_FUNC void func_80013F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013F04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80013F08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013F0C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80013F10: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80013F14: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80013F18: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80013F1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80013F20: jal         0x8000DA44
    // 0x80013F24: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80013F24: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80013F28: bgez        $v0, L_80013F38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013F2C: nop

            goto L_80013F38;
    }
    // 0x80013F2C: nop

    // 0x80013F30: b           L_80013FD8
    // 0x80013F34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013FD8;
    // 0x80013F34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80013F38:
    // 0x80013F38: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80013F3C: nop

    // 0x80013F40: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80013F44: nop

    // 0x80013F48: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80013F4C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80013F50: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80013F54: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80013F58: nop

    // 0x80013F5C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80013F60: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x80013F64: nop

    // 0x80013F68: blez        $t0, L_80013FC8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80013F6C: nop

            goto L_80013FC8;
    }
    // 0x80013F6C: nop

L_80013F70:
    // 0x80013F70: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x80013F74: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    // 0x80013F78: jal         0x80014BD4
    // 0x80013F7C: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80013F7C: nop

    after_1:
    // 0x80013F80: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80013F84: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80013F88: swc1        $f20, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f20.u32l;
    // 0x80013F8C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80013F90: nop

    // 0x80013F94: swc1        $f20, 0xF4($t3)
    MEM_W(0XF4, ctx->r11) = ctx->f20.u32l;
    // 0x80013F98: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80013F9C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80013FA0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80013FA4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80013FA8: addiu       $t7, $t6, 0x160
    ctx->r15 = ADD32(ctx->r14, 0X160);
    // 0x80013FAC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80013FB0: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80013FB4: lhu         $t8, 0x6($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X6);
    // 0x80013FB8: nop

    // 0x80013FBC: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80013FC0: bne         $at, $zero, L_80013F70
    if (ctx->r1 != 0) {
        // 0x80013FC4: nop

            goto L_80013F70;
    }
    // 0x80013FC4: nop

L_80013FC8:
    // 0x80013FC8: b           L_80013FD8
    // 0x80013FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013FD8;
    // 0x80013FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80013FD0: b           L_80013FD8
    // 0x80013FD4: nop

        goto L_80013FD8;
    // 0x80013FD4: nop

L_80013FD8:
    // 0x80013FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013FDC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80013FE0: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80013FE4: jr          $ra
    // 0x80013FE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80013FE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80013FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013FEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80013FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013FF4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80013FF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80013FFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80014000: jal         0x8000DA44
    // 0x80014004: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80014004: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80014008: bgez        $v0, L_80014018
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001400C: nop

            goto L_80014018;
    }
    // 0x8001400C: nop

    // 0x80014010: b           L_800140C8
    // 0x80014014: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800140C8;
    // 0x80014014: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014018:
    // 0x80014018: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001401C: nop

    // 0x80014020: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80014024: nop

    // 0x80014028: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8001402C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80014030: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80014034: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80014038: nop

    // 0x8001403C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80014040: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x80014044: nop

    // 0x80014048: blez        $t0, L_800140B8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001404C: nop

            goto L_800140B8;
    }
    // 0x8001404C: nop

L_80014050:
    // 0x80014050: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x80014054: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    // 0x80014058: jal         0x80014BD4
    // 0x8001405C: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x8001405C: nop

    after_1:
    // 0x80014060: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80014064: nop

    // 0x80014068: swc1        $f0, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f0.u32l;
    // 0x8001406C: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x80014070: lhu         $a0, 0x6($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X6);
    // 0x80014074: jal         0x80014BD4
    // 0x80014078: nop

    func_80014BD4(rdram, ctx);
        goto after_2;
    // 0x80014078: nop

    after_2:
    // 0x8001407C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80014080: nop

    // 0x80014084: swc1        $f0, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f0.u32l;
    // 0x80014088: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001408C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80014090: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80014094: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80014098: addiu       $t9, $t7, 0x160
    ctx->r25 = ADD32(ctx->r15, 0X160);
    // 0x8001409C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800140A0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800140A4: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x800140A8: nop

    // 0x800140AC: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800140B0: bne         $at, $zero, L_80014050
    if (ctx->r1 != 0) {
        // 0x800140B4: nop

            goto L_80014050;
    }
    // 0x800140B4: nop

L_800140B8:
    // 0x800140B8: b           L_800140C8
    // 0x800140BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800140C8;
    // 0x800140BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800140C0: b           L_800140C8
    // 0x800140C4: nop

        goto L_800140C8;
    // 0x800140C4: nop

L_800140C8:
    // 0x800140C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800140CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800140D0: jr          $ra
    // 0x800140D4: nop

    return;
    // 0x800140D4: nop

;}
RECOMP_FUNC void func_800140D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800140D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800140DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800140E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800140E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800140E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800140EC: jal         0x8000DA44
    // 0x800140F0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800140F0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800140F4: bgez        $v0, L_80014104
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800140F8: nop

            goto L_80014104;
    }
    // 0x800140F8: nop

    // 0x800140FC: b           L_80014218
    // 0x80014100: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80014218;
    // 0x80014100: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014104:
    // 0x80014104: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014108: nop

    // 0x8001410C: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80014110: nop

    // 0x80014114: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80014118: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8001411C:
    // 0x8001411C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80014120: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80014124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80014128: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001412C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80014130: swc1        $f4, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f4.u32l;
    // 0x80014134: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80014138: nop

    // 0x8001413C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80014140: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x80014144: bne         $at, $zero, L_8001411C
    if (ctx->r1 != 0) {
        // 0x80014148: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8001411C;
    }
    // 0x80014148: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8001414C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80014150: nop

    // 0x80014154: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80014158: nop

    // 0x8001415C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80014160: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80014164: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80014168: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8001416C: nop

    // 0x80014170: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80014174: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x80014178: nop

    // 0x8001417C: blez        $t9, L_80014208
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80014180: nop

            goto L_80014208;
    }
    // 0x80014180: nop

L_80014184:
    // 0x80014184: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80014188: lhu         $a0, 0x4($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X4);
    // 0x8001418C: jal         0x80014BD4
    // 0x80014190: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80014190: nop

    after_1:
    // 0x80014194: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80014198: nop

    // 0x8001419C: swc1        $f0, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f0.u32l;
    // 0x800141A0: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x800141A4: lhu         $a0, 0x6($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X6);
    // 0x800141A8: jal         0x80014BD4
    // 0x800141AC: nop

    func_80014BD4(rdram, ctx);
        goto after_2;
    // 0x800141AC: nop

    after_2:
    // 0x800141B0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800141B4: nop

    // 0x800141B8: swc1        $f0, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f0.u32l;
    // 0x800141BC: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800141C0: lhu         $a0, 0x8($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X8);
    // 0x800141C4: jal         0x80014BD4
    // 0x800141C8: nop

    func_80014BD4(rdram, ctx);
        goto after_3;
    // 0x800141C8: nop

    after_3:
    // 0x800141CC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800141D0: nop

    // 0x800141D4: swc1        $f0, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f0.u32l;
    // 0x800141D8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800141DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800141E0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800141E4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x800141E8: addiu       $t9, $t6, 0x160
    ctx->r25 = ADD32(ctx->r14, 0X160);
    // 0x800141EC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800141F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800141F4: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x800141F8: nop

    // 0x800141FC: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80014200: bne         $at, $zero, L_80014184
    if (ctx->r1 != 0) {
        // 0x80014204: nop

            goto L_80014184;
    }
    // 0x80014204: nop

L_80014208:
    // 0x80014208: b           L_80014218
    // 0x8001420C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80014218;
    // 0x8001420C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014210: b           L_80014218
    // 0x80014214: nop

        goto L_80014218;
    // 0x80014214: nop

L_80014218:
    // 0x80014218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001421C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014220: jr          $ra
    // 0x80014224: nop

    return;
    // 0x80014224: nop

;}
RECOMP_FUNC void func_80014228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014228: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001422C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014230: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80014234: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80014238: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001423C: jal         0x8000DA44
    // 0x80014240: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80014240: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80014244: bgez        $v0, L_80014254
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80014248: nop

            goto L_80014254;
    }
    // 0x80014248: nop

    // 0x8001424C: b           L_800145C4
    // 0x80014250: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800145C4;
    // 0x80014250: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014254:
    // 0x80014254: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014258: nop

    // 0x8001425C: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80014260: nop

    // 0x80014264: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80014268: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x8001426C: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x80014270: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80014274: nop

    // 0x80014278: sh          $t9, 0x62($t0)
    MEM_H(0X62, ctx->r8) = ctx->r25;
    // 0x8001427C: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x80014280: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x80014284: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80014288: nop

    // 0x8001428C: sh          $t2, 0x64($t3)
    MEM_H(0X64, ctx->r11) = ctx->r10;
    // 0x80014290: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80014294: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80014298: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001429C: nop

    // 0x800142A0: sh          $t5, 0x66($t6)
    MEM_H(0X66, ctx->r14) = ctx->r13;
    // 0x800142A4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800142A8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800142AC: lhu         $t8, 0x62($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X62);
    // 0x800142B0: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x800142B4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800142B8: sltiu       $at, $t9, 0xD
    ctx->r1 = ctx->r25 < 0XD ? 1 : 0;
    // 0x800142BC: beq         $at, $zero, L_8001459C
    if (ctx->r1 == 0) {
        // 0x800142C0: nop

            goto L_8001459C;
    }
    // 0x800142C0: nop

    // 0x800142C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800142C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800142CC: addu        $at, $at, $t9
    gpr jr_addend_800142D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800142D0: lw          $t9, -0x2AD8($at)
    ctx->r25 = ADD32(ctx->r1, -0X2AD8);
    // 0x800142D4: nop

    // 0x800142D8: jr          $t9
    // 0x800142DC: nop

    switch (jr_addend_800142D8 >> 2) {
        case 0: goto L_800142E0; break;
        case 1: goto L_8001459C; break;
        case 2: goto L_800142F8; break;
        case 3: goto L_80014348; break;
        case 4: goto L_8001459C; break;
        case 5: goto L_8001459C; break;
        case 6: goto L_8001459C; break;
        case 7: goto L_8001459C; break;
        case 8: goto L_80014398; break;
        case 9: goto L_80014464; break;
        case 10: goto L_800144AC; break;
        case 11: goto L_800144FC; break;
        case 12: goto L_8001454C; break;
        default: switch_error(__func__, 0x800142D8, 0x800ED528);
    }
    // 0x800142DC: nop

L_800142E0:
    // 0x800142E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800142E4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800142E8: nop

    // 0x800142EC: swc1        $f4, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->f4.u32l;
    // 0x800142F0: b           L_8001459C
    // 0x800142F4: nop

        goto L_8001459C;
    // 0x800142F4: nop

L_800142F8:
    // 0x800142F8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800142FC: nop

    // 0x80014300: lh          $t3, 0x66($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X66);
    // 0x80014304: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80014308: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8001430C: lwc1        $f6, 0xCC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x80014310: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80014314: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80014318: nop

    // 0x8001431C: bc1f        L_80014334
    if (!c1cs) {
        // 0x80014320: nop

            goto L_80014334;
    }
    // 0x80014320: nop

    // 0x80014324: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80014328: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001432C: b           L_80014340
    // 0x80014330: sh          $t4, 0x68($t5)
    MEM_H(0X68, ctx->r13) = ctx->r12;
        goto L_80014340;
    // 0x80014330: sh          $t4, 0x68($t5)
    MEM_H(0X68, ctx->r13) = ctx->r12;
L_80014334:
    // 0x80014334: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80014338: nop

    // 0x8001433C: sh          $zero, 0x68($t6)
    MEM_H(0X68, ctx->r14) = 0;
L_80014340:
    // 0x80014340: b           L_8001459C
    // 0x80014344: nop

        goto L_8001459C;
    // 0x80014344: nop

L_80014348:
    // 0x80014348: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8001434C: nop

    // 0x80014350: lh          $t9, 0x66($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X66);
    // 0x80014354: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80014358: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8001435C: lwc1        $f16, 0xD0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x80014360: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80014364: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80014368: nop

    // 0x8001436C: bc1f        L_80014384
    if (!c1cs) {
        // 0x80014370: nop

            goto L_80014384;
    }
    // 0x80014370: nop

    // 0x80014374: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80014378: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001437C: b           L_80014390
    // 0x80014380: sh          $t0, 0x68($t2)
    MEM_H(0X68, ctx->r10) = ctx->r8;
        goto L_80014390;
    // 0x80014380: sh          $t0, 0x68($t2)
    MEM_H(0X68, ctx->r10) = ctx->r8;
L_80014384:
    // 0x80014384: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80014388: nop

    // 0x8001438C: sh          $zero, 0x68($t1)
    MEM_H(0X68, ctx->r9) = 0;
L_80014390:
    // 0x80014390: b           L_8001459C
    // 0x80014394: nop

        goto L_8001459C;
    // 0x80014394: nop

L_80014398:
    // 0x80014398: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8001439C: nop

    // 0x800143A0: lw          $t4, 0x1AC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1AC);
    // 0x800143A4: nop

    // 0x800143A8: slti        $at, $t4, 0x4000
    ctx->r1 = SIGNED(ctx->r12) < 0X4000 ? 1 : 0;
    // 0x800143AC: bne         $at, $zero, L_800143C4
    if (ctx->r1 != 0) {
        // 0x800143B0: nop

            goto L_800143C4;
    }
    // 0x800143B0: nop

    // 0x800143B4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800143B8: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800143BC: bne         $at, $zero, L_80014414
    if (ctx->r1 != 0) {
        // 0x800143C0: nop

            goto L_80014414;
    }
    // 0x800143C0: nop

L_800143C4:
    // 0x800143C4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800143C8: nop

    // 0x800143CC: lh          $t6, 0x66($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X66);
    // 0x800143D0: lwc1        $f8, 0x14($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800143D4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800143D8: nop

    // 0x800143DC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800143E0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800143E4: nop

    // 0x800143E8: bc1f        L_80014400
    if (!c1cs) {
        // 0x800143EC: nop

            goto L_80014400;
    }
    // 0x800143EC: nop

    // 0x800143F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800143F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800143F8: b           L_8001440C
    // 0x800143FC: sh          $t8, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r24;
        goto L_8001440C;
    // 0x800143FC: sh          $t8, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r24;
L_80014400:
    // 0x80014400: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80014404: nop

    // 0x80014408: sh          $zero, 0x68($t9)
    MEM_H(0X68, ctx->r25) = 0;
L_8001440C:
    // 0x8001440C: b           L_8001445C
    // 0x80014410: nop

        goto L_8001445C;
    // 0x80014410: nop

L_80014414:
    // 0x80014414: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80014418: nop

    // 0x8001441C: lh          $t1, 0x66($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X66);
    // 0x80014420: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x80014424: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80014428: lwc1        $f18, 0xD4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XD4);
    // 0x8001442C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80014430: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80014434: nop

    // 0x80014438: bc1f        L_80014450
    if (!c1cs) {
        // 0x8001443C: nop

            goto L_80014450;
    }
    // 0x8001443C: nop

    // 0x80014440: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80014444: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80014448: b           L_8001445C
    // 0x8001444C: sh          $t3, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r11;
        goto L_8001445C;
    // 0x8001444C: sh          $t3, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r11;
L_80014450:
    // 0x80014450: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80014454: nop

    // 0x80014458: sh          $zero, 0x68($t5)
    MEM_H(0X68, ctx->r13) = 0;
L_8001445C:
    // 0x8001445C: b           L_8001459C
    // 0x80014460: nop

        goto L_8001459C;
    // 0x80014460: nop

L_80014464:
    // 0x80014464: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80014468: nop

    // 0x8001446C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80014470: lhu         $t9, 0x66($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X66);
    // 0x80014474: lhu         $t7, 0x11E($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X11E);
    // 0x80014478: nop

    // 0x8001447C: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80014480: beq         $at, $zero, L_80014498
    if (ctx->r1 == 0) {
        // 0x80014484: nop

            goto L_80014498;
    }
    // 0x80014484: nop

    // 0x80014488: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001448C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80014490: b           L_800144A4
    // 0x80014494: sh          $t2, 0x68($t0)
    MEM_H(0X68, ctx->r8) = ctx->r10;
        goto L_800144A4;
    // 0x80014494: sh          $t2, 0x68($t0)
    MEM_H(0X68, ctx->r8) = ctx->r10;
L_80014498:
    // 0x80014498: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8001449C: nop

    // 0x800144A0: sh          $zero, 0x68($t1)
    MEM_H(0X68, ctx->r9) = 0;
L_800144A4:
    // 0x800144A4: b           L_8001459C
    // 0x800144A8: nop

        goto L_8001459C;
    // 0x800144A8: nop

L_800144AC:
    // 0x800144AC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800144B0: nop

    // 0x800144B4: lh          $t5, 0x66($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X66);
    // 0x800144B8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x800144BC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800144C0: lwc1        $f6, 0xE8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XE8);
    // 0x800144C4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800144C8: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800144CC: nop

    // 0x800144D0: bc1f        L_800144E8
    if (!c1cs) {
        // 0x800144D4: nop

            goto L_800144E8;
    }
    // 0x800144D4: nop

    // 0x800144D8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800144DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800144E0: b           L_800144F4
    // 0x800144E4: sh          $t8, 0x68($t6)
    MEM_H(0X68, ctx->r14) = ctx->r24;
        goto L_800144F4;
    // 0x800144E4: sh          $t8, 0x68($t6)
    MEM_H(0X68, ctx->r14) = ctx->r24;
L_800144E8:
    // 0x800144E8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800144EC: nop

    // 0x800144F0: sh          $zero, 0x68($t7)
    MEM_H(0X68, ctx->r15) = 0;
L_800144F4:
    // 0x800144F4: b           L_8001459C
    // 0x800144F8: nop

        goto L_8001459C;
    // 0x800144F8: nop

L_800144FC:
    // 0x800144FC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80014500: nop

    // 0x80014504: lh          $t0, 0x66($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X66);
    // 0x80014508: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8001450C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80014510: lwc1        $f16, 0xEC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XEC);
    // 0x80014514: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80014518: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8001451C: nop

    // 0x80014520: bc1f        L_80014538
    if (!c1cs) {
        // 0x80014524: nop

            goto L_80014538;
    }
    // 0x80014524: nop

    // 0x80014528: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8001452C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80014530: b           L_80014544
    // 0x80014534: sh          $t1, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r9;
        goto L_80014544;
    // 0x80014534: sh          $t1, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r9;
L_80014538:
    // 0x80014538: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8001453C: nop

    // 0x80014540: sh          $zero, 0x68($t3)
    MEM_H(0X68, ctx->r11) = 0;
L_80014544:
    // 0x80014544: b           L_8001459C
    // 0x80014548: nop

        goto L_8001459C;
    // 0x80014548: nop

L_8001454C:
    // 0x8001454C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80014550: nop

    // 0x80014554: lh          $t6, 0x66($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X66);
    // 0x80014558: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x8001455C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80014560: lwc1        $f8, 0xF0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x80014564: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80014568: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8001456C: nop

    // 0x80014570: bc1f        L_80014588
    if (!c1cs) {
        // 0x80014574: nop

            goto L_80014588;
    }
    // 0x80014574: nop

    // 0x80014578: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8001457C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80014580: b           L_80014594
    // 0x80014584: sh          $t7, 0x68($t2)
    MEM_H(0X68, ctx->r10) = ctx->r15;
        goto L_80014594;
    // 0x80014584: sh          $t7, 0x68($t2)
    MEM_H(0X68, ctx->r10) = ctx->r15;
L_80014588:
    // 0x80014588: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8001458C: nop

    // 0x80014590: sh          $zero, 0x68($t9)
    MEM_H(0X68, ctx->r25) = 0;
L_80014594:
    // 0x80014594: b           L_8001459C
    // 0x80014598: nop

        goto L_8001459C;
    // 0x80014598: nop

L_8001459C:
    // 0x8001459C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800145A0: nop

    // 0x800145A4: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x800145A8: nop

    // 0x800145AC: ori         $t4, $t1, 0x80
    ctx->r12 = ctx->r9 | 0X80;
    // 0x800145B0: sw          $t4, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r12;
    // 0x800145B4: b           L_800145C4
    // 0x800145B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800145C4;
    // 0x800145B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800145BC: b           L_800145C4
    // 0x800145C0: nop

        goto L_800145C4;
    // 0x800145C0: nop

L_800145C4:
    // 0x800145C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800145C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800145CC: jr          $ra
    // 0x800145D0: nop

    return;
    // 0x800145D0: nop

;}
RECOMP_FUNC void func_800145D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800145D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800145D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800145DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800145E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800145E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800145E8: jal         0x8000DA44
    // 0x800145EC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800145EC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800145F0: bgez        $v0, L_80014600
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800145F4: nop

            goto L_80014600;
    }
    // 0x800145F4: nop

    // 0x800145F8: b           L_80014A70
    // 0x800145FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80014A70;
    // 0x800145FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80014600:
    // 0x80014600: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014604: nop

    // 0x80014608: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001460C: nop

    // 0x80014610: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80014614: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80014618: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x8001461C: nop

    // 0x80014620: bne         $t9, $zero, L_80014634
    if (ctx->r25 != 0) {
        // 0x80014624: nop

            goto L_80014634;
    }
    // 0x80014624: nop

    // 0x80014628: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001462C: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80014630: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
L_80014634:
    // 0x80014634: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x80014638: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x8001463C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80014640: ori         $at, $at, 0x1FFE
    ctx->r1 = ctx->r1 | 0X1FFE;
    // 0x80014644: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80014648: sltiu       $at, $t4, 0xB
    ctx->r1 = ctx->r12 < 0XB ? 1 : 0;
    // 0x8001464C: beq         $at, $zero, L_80014A60
    if (ctx->r1 == 0) {
        // 0x80014650: nop

            goto L_80014A60;
    }
    // 0x80014650: nop

    // 0x80014654: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80014658: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001465C: addu        $at, $at, $t4
    gpr jr_addend_80014668 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80014660: lw          $t4, -0x2AA4($at)
    ctx->r12 = ADD32(ctx->r1, -0X2AA4);
    // 0x80014664: nop

    // 0x80014668: jr          $t4
    // 0x8001466C: nop

    switch (jr_addend_80014668 >> 2) {
        case 0: goto L_80014670; break;
        case 1: goto L_800146D4; break;
        case 2: goto L_80014A60; break;
        case 3: goto L_80014A60; break;
        case 4: goto L_80014A60; break;
        case 5: goto L_80014A60; break;
        case 6: goto L_80014738; break;
        case 7: goto L_80014A60; break;
        case 8: goto L_8001479C; break;
        case 9: goto L_80014888; break;
        case 10: goto L_80014974; break;
        default: switch_error(__func__, 0x80014668, 0x800ED55C);
    }
    // 0x8001466C: nop

L_80014670:
    // 0x80014670: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x80014674: lhu         $a0, 0x6($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X6);
    // 0x80014678: jal         0x80014BD4
    // 0x8001467C: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x8001467C: nop

    after_1:
    // 0x80014680: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80014684: nop

    // 0x80014688: swc1        $f0, 0x98($t6)
    MEM_W(0X98, ctx->r14) = ctx->f0.u32l;
    // 0x8001468C: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80014690: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x80014694: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80014698: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8001469C: lwc1        $f4, 0x98($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X98);
    // 0x800146A0: lwc1        $f6, 0x6C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x800146A4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800146A8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800146AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800146B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800146B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800146B8: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800146BC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800146C0: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800146C4: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800146C8: swc1        $f8, 0xA4($t7)
    MEM_W(0XA4, ctx->r15) = ctx->f8.u32l;
    // 0x800146CC: b           L_80014A60
    // 0x800146D0: nop

        goto L_80014A60;
    // 0x800146D0: nop

L_800146D4:
    // 0x800146D4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x800146D8: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    // 0x800146DC: jal         0x80014BD4
    // 0x800146E0: nop

    func_80014BD4(rdram, ctx);
        goto after_2;
    // 0x800146E0: nop

    after_2:
    // 0x800146E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800146E8: nop

    // 0x800146EC: swc1        $f0, 0x9C($t1)
    MEM_W(0X9C, ctx->r9) = ctx->f0.u32l;
    // 0x800146F0: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800146F4: lh          $t4, 0x8($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X8);
    // 0x800146F8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800146FC: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80014700: lwc1        $f16, 0x9C($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X9C);
    // 0x80014704: lwc1        $f18, 0x70($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X70);
    // 0x80014708: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001470C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80014710: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80014714: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80014718: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001471C: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80014720: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80014724: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80014728: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8001472C: swc1        $f4, 0xA8($t2)
    MEM_W(0XA8, ctx->r10) = ctx->f4.u32l;
    // 0x80014730: b           L_80014A60
    // 0x80014734: nop

        goto L_80014A60;
    // 0x80014734: nop

L_80014738:
    // 0x80014738: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x8001473C: lhu         $a0, 0x6($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X6);
    // 0x80014740: jal         0x80014BD4
    // 0x80014744: nop

    func_80014BD4(rdram, ctx);
        goto after_3;
    // 0x80014744: nop

    after_3:
    // 0x80014748: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001474C: nop

    // 0x80014750: swc1        $f0, 0xA0($t6)
    MEM_W(0XA0, ctx->r14) = ctx->f0.u32l;
    // 0x80014754: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x80014758: lh          $t7, 0x8($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X8);
    // 0x8001475C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80014760: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80014764: lwc1        $f10, 0xA0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XA0);
    // 0x80014768: lwc1        $f8, 0x74($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X74);
    // 0x8001476C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80014770: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80014774: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80014778: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8001477C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80014780: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80014784: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80014788: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8001478C: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80014790: swc1        $f16, 0xAC($t8)
    MEM_W(0XAC, ctx->r24) = ctx->f16.u32l;
    // 0x80014794: b           L_80014A60
    // 0x80014798: nop

        goto L_80014A60;
    // 0x80014798: nop

L_8001479C:
    // 0x8001479C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x800147A0: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    // 0x800147A4: jal         0x80014BD4
    // 0x800147A8: nop

    func_80014BD4(rdram, ctx);
        goto after_4;
    // 0x800147A8: nop

    after_4:
    // 0x800147AC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800147B0: nop

    // 0x800147B4: swc1        $f0, 0xB0($t1)
    MEM_W(0XB0, ctx->r9) = ctx->f0.u32l;
    // 0x800147B8: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x800147BC: lh          $t2, 0x8($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X8);
    // 0x800147C0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800147C4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800147C8: lwc1        $f6, 0xB0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XB0);
    // 0x800147CC: lwc1        $f4, 0x18($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X18);
    // 0x800147D0: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800147D4: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800147D8: nop

    // 0x800147DC: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800147E0: swc1        $f16, 0xBC($t3)
    MEM_W(0XBC, ctx->r11) = ctx->f16.u32l;
    // 0x800147E4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800147E8: nop

    // 0x800147EC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800147F0: nop

    // 0x800147F4: ori         $t9, $t6, 0x20
    ctx->r25 = ctx->r14 | 0X20;
    // 0x800147F8: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
    // 0x800147FC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80014800: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80014804: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80014808: nop

    // 0x8001480C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80014810: lhu         $t0, 0x6($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X6);
    // 0x80014814: nop

    // 0x80014818: blez        $t0, L_80014880
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001481C: nop

            goto L_80014880;
    }
    // 0x8001481C: nop

L_80014820:
    // 0x80014820: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80014824: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80014828: lw          $t4, 0xC0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC0);
    // 0x8001482C: nop

    // 0x80014830: and         $t2, $t4, $at
    ctx->r10 = ctx->r12 & ctx->r1;
    // 0x80014834: sw          $t2, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r10;
    // 0x80014838: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001483C: nop

    // 0x80014840: lw          $t6, 0xC0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC0);
    // 0x80014844: nop

    // 0x80014848: ori         $t9, $t6, 0x10
    ctx->r25 = ctx->r14 | 0X10;
    // 0x8001484C: sw          $t9, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r25;
    // 0x80014850: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80014854: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80014858: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001485C: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80014860: addiu       $t0, $t7, 0x160
    ctx->r8 = ADD32(ctx->r15, 0X160);
    // 0x80014864: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80014868: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8001486C: lhu         $t2, 0x6($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X6);
    // 0x80014870: nop

    // 0x80014874: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80014878: bne         $at, $zero, L_80014820
    if (ctx->r1 != 0) {
        // 0x8001487C: nop

            goto L_80014820;
    }
    // 0x8001487C: nop

L_80014880:
    // 0x80014880: b           L_80014A60
    // 0x80014884: nop

        goto L_80014A60;
    // 0x80014884: nop

L_80014888:
    // 0x80014888: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x8001488C: lhu         $a0, 0x6($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X6);
    // 0x80014890: jal         0x80014BD4
    // 0x80014894: nop

    func_80014BD4(rdram, ctx);
        goto after_5;
    // 0x80014894: nop

    after_5:
    // 0x80014898: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001489C: nop

    // 0x800148A0: swc1        $f0, 0xB4($t6)
    MEM_W(0XB4, ctx->r14) = ctx->f0.u32l;
    // 0x800148A4: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x800148A8: lh          $t5, 0x8($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X8);
    // 0x800148AC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800148B0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800148B4: lwc1        $f6, 0xB4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XB4);
    // 0x800148B8: lwc1        $f4, 0x1C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x800148BC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800148C0: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800148C4: nop

    // 0x800148C8: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800148CC: swc1        $f16, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->f16.u32l;
    // 0x800148D0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800148D4: nop

    // 0x800148D8: lhu         $t0, 0x0($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X0);
    // 0x800148DC: nop

    // 0x800148E0: ori         $t4, $t0, 0x20
    ctx->r12 = ctx->r8 | 0X20;
    // 0x800148E4: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
    // 0x800148E8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800148EC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800148F0: lw          $t2, 0xC($t8)
    ctx->r10 = MEM_W(ctx->r24, 0XC);
    // 0x800148F4: nop

    // 0x800148F8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800148FC: lhu         $t1, 0x6($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X6);
    // 0x80014900: nop

    // 0x80014904: blez        $t1, L_8001496C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80014908: nop

            goto L_8001496C;
    }
    // 0x80014908: nop

L_8001490C:
    // 0x8001490C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80014910: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80014914: lw          $t3, 0xC0($t6)
    ctx->r11 = MEM_W(ctx->r14, 0XC0);
    // 0x80014918: nop

    // 0x8001491C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80014920: sw          $t5, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r13;
    // 0x80014924: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80014928: nop

    // 0x8001492C: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x80014930: nop

    // 0x80014934: ori         $t4, $t0, 0x10
    ctx->r12 = ctx->r8 | 0X10;
    // 0x80014938: sw          $t4, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r12;
    // 0x8001493C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80014940: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80014944: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80014948: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8001494C: addiu       $t1, $t8, 0x160
    ctx->r9 = ADD32(ctx->r24, 0X160);
    // 0x80014950: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80014954: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80014958: lhu         $t5, 0x6($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X6);
    // 0x8001495C: nop

    // 0x80014960: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80014964: bne         $at, $zero, L_8001490C
    if (ctx->r1 != 0) {
        // 0x80014968: nop

            goto L_8001490C;
    }
    // 0x80014968: nop

L_8001496C:
    // 0x8001496C: b           L_80014A60
    // 0x80014970: nop

        goto L_80014A60;
    // 0x80014970: nop

L_80014974:
    // 0x80014974: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80014978: lhu         $a0, 0x6($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X6);
    // 0x8001497C: jal         0x80014BD4
    // 0x80014980: nop

    func_80014BD4(rdram, ctx);
        goto after_6;
    // 0x80014980: nop

    after_6:
    // 0x80014984: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80014988: nop

    // 0x8001498C: swc1        $f0, 0xB8($t0)
    MEM_W(0XB8, ctx->r8) = ctx->f0.u32l;
    // 0x80014990: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x80014994: lh          $t7, 0x8($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X8);
    // 0x80014998: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001499C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800149A0: lwc1        $f6, 0xB8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XB8);
    // 0x800149A4: lwc1        $f4, 0x20($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X20);
    // 0x800149A8: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800149AC: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800149B0: nop

    // 0x800149B4: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800149B8: swc1        $f16, 0xC4($t4)
    MEM_W(0XC4, ctx->r12) = ctx->f16.u32l;
    // 0x800149BC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800149C0: nop

    // 0x800149C4: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x800149C8: nop

    // 0x800149CC: ori         $t3, $t1, 0x20
    ctx->r11 = ctx->r9 | 0X20;
    // 0x800149D0: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x800149D4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800149D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800149DC: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800149E0: nop

    // 0x800149E4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800149E8: lhu         $t6, 0x6($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X6);
    // 0x800149EC: nop

    // 0x800149F0: blez        $t6, L_80014A58
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800149F4: nop

            goto L_80014A58;
    }
    // 0x800149F4: nop

L_800149F8:
    // 0x800149F8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800149FC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80014A00: lw          $t9, 0xC0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC0);
    // 0x80014A04: nop

    // 0x80014A08: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80014A0C: sw          $t7, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r15;
    // 0x80014A10: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80014A14: nop

    // 0x80014A18: lw          $t1, 0xC0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC0);
    // 0x80014A1C: nop

    // 0x80014A20: ori         $t3, $t1, 0x10
    ctx->r11 = ctx->r9 | 0X10;
    // 0x80014A24: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
    // 0x80014A28: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80014A2C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80014A30: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80014A34: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x80014A38: addiu       $t6, $t2, 0x160
    ctx->r14 = ADD32(ctx->r10, 0X160);
    // 0x80014A3C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80014A40: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80014A44: lhu         $t7, 0x6($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X6);
    // 0x80014A48: nop

    // 0x80014A4C: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80014A50: bne         $at, $zero, L_800149F8
    if (ctx->r1 != 0) {
        // 0x80014A54: nop

            goto L_800149F8;
    }
    // 0x80014A54: nop

L_80014A58:
    // 0x80014A58: b           L_80014A60
    // 0x80014A5C: nop

        goto L_80014A60;
    // 0x80014A5C: nop

L_80014A60:
    // 0x80014A60: b           L_80014A70
    // 0x80014A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80014A70;
    // 0x80014A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014A68: b           L_80014A70
    // 0x80014A6C: nop

        goto L_80014A70;
    // 0x80014A6C: nop

L_80014A70:
    // 0x80014A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014A74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014A78: jr          $ra
    // 0x80014A7C: nop

    return;
    // 0x80014A7C: nop

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
RECOMP_FUNC void func_80014B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014B5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80014B60: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80014B64: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80014B68: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x80014B6C: lw          $t6, 0x306C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X306C);
    // 0x80014B70: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80014B74: blez        $t7, L_80014BBC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80014B78: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_80014BBC;
    }
    // 0x80014B78: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_80014B7C:
    // 0x80014B7C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80014B80: nop

    // 0x80014B84: bne         $t8, $a0, L_80014B94
    if (ctx->r24 != ctx->r4) {
        // 0x80014B88: nop

            goto L_80014B94;
    }
    // 0x80014B88: nop

    // 0x80014B8C: b           L_80014BCC
    // 0x80014B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80014BCC;
    // 0x80014B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80014B94:
    // 0x80014B94: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80014B98: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80014B9C: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80014BA0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80014BA4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80014BA8: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80014BAC: addiu       $t2, $t1, 0x28
    ctx->r10 = ADD32(ctx->r9, 0X28);
    // 0x80014BB0: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80014BB4: bne         $at, $zero, L_80014B7C
    if (ctx->r1 != 0) {
        // 0x80014BB8: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_80014B7C;
    }
    // 0x80014BB8: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_80014BBC:
    // 0x80014BBC: b           L_80014BCC
    // 0x80014BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80014BCC;
    // 0x80014BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014BC4: b           L_80014BCC
    // 0x80014BC8: nop

        goto L_80014BCC;
    // 0x80014BC8: nop

L_80014BCC:
    // 0x80014BCC: jr          $ra
    // 0x80014BD0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80014BD0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80014BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014BD4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80014BD8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80014BDC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80014BE0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014BE4: bgez        $t7, L_80014BF4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80014BE8: sra         $t8, $t7, 8
        ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
            goto L_80014BF4;
    }
    // 0x80014BE8: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80014BEC: addiu       $at, $t7, 0xFF
    ctx->r1 = ADD32(ctx->r15, 0XFF);
    // 0x80014BF0: sra         $t8, $at, 8
    ctx->r24 = S32(SIGNED(ctx->r1) >> 8);
L_80014BF4:
    // 0x80014BF4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80014BF8: andi        $t9, $a0, 0x8000
    ctx->r25 = ctx->r4 & 0X8000;
    // 0x80014BFC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80014C00: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80014C04: bne         $at, $zero, L_80014C20
    if (ctx->r1 != 0) {
        // 0x80014C08: nop

            goto L_80014C20;
    }
    // 0x80014C08: nop

    // 0x80014C0C: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x80014C10: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80014C14: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80014C18: b           L_80014C28
    // 0x80014C1C: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
        goto L_80014C28;
    // 0x80014C1C: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_80014C20:
    // 0x80014C20: andi        $t2, $a0, 0xFF
    ctx->r10 = ctx->r4 & 0XFF;
    // 0x80014C24: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_80014C28:
    // 0x80014C28: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x80014C2C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80014C30: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80014C34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80014C38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80014C3C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80014C40: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80014C44: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80014C48: nop

    // 0x80014C4C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80014C50: b           L_80014C60
    // 0x80014C54: add.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f0.fl = ctx->f18.fl + ctx->f10.fl;
        goto L_80014C60;
    // 0x80014C54: add.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f0.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80014C58: b           L_80014C60
    // 0x80014C5C: nop

        goto L_80014C60;
    // 0x80014C5C: nop

L_80014C60:
    // 0x80014C60: jr          $ra
    // 0x80014C64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80014C64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80014C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014C68: nop

    // 0x80014C6C: nop

;}
RECOMP_FUNC void func_80014C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014C70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014C78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80014C7C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014C80: nop

    // 0x80014C84: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80014C88: nop

    // 0x80014C8C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80014C90: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014C94: nop

    // 0x80014C98: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x80014C9C: nop

    // 0x80014CA0: addiu       $t0, $t9, -0x4000
    ctx->r8 = ADD32(ctx->r25, -0X4000);
    // 0x80014CA4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80014CA8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80014CAC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80014CB0: nop

    // 0x80014CB4: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
    // 0x80014CB8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80014CBC: nop

    // 0x80014CC0: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80014CC4: nop

    // 0x80014CC8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80014CCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80014CD0: jal         0x80099E2C
    // 0x80014CD4: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x80014CD4: nop

    after_0:
    // 0x80014CD8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80014CDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80014CE0: lwc1        $f4, 0x1B0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X1B0);
    // 0x80014CE4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80014CE8: nop

    // 0x80014CEC: swc1        $f4, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f4.u32l;
    // 0x80014CF0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014CF4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80014CF8: lwc1        $f6, 0x1B4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1B4);
    // 0x80014CFC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80014D00: nop

    // 0x80014D04: swc1        $f6, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f6.u32l;
    // 0x80014D08: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80014D0C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80014D10: lwc1        $f8, 0x1B8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B8);
    // 0x80014D14: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80014D18: nop

    // 0x80014D1C: swc1        $f8, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f8.u32l;
    // 0x80014D20: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80014D24: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80014D28: lw          $t5, 0x1AC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1AC);
    // 0x80014D2C: nop

    // 0x80014D30: beq         $t5, $at, L_80014D44
    if (ctx->r13 == ctx->r1) {
        // 0x80014D34: nop

            goto L_80014D44;
    }
    // 0x80014D34: nop

    // 0x80014D38: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80014D3C: bne         $t5, $at, L_80014DA0
    if (ctx->r13 != ctx->r1) {
        // 0x80014D40: nop

            goto L_80014DA0;
    }
    // 0x80014D40: nop

L_80014D44:
    // 0x80014D44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80014D48: lwc1        $f10, -0x2A70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A70);
    // 0x80014D4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014D50: nop

    // 0x80014D54: swc1        $f10, 0x1B0($t6)
    MEM_W(0X1B0, ctx->r14) = ctx->f10.u32l;
    // 0x80014D58: lui         $at, 0x4479
    ctx->r1 = S32(0X4479 << 16);
    // 0x80014D5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80014D60: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80014D64: nop

    // 0x80014D68: swc1        $f16, 0x1B4($t7)
    MEM_W(0X1B4, ctx->r15) = ctx->f16.u32l;
    // 0x80014D6C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014D70: nop

    // 0x80014D74: sh          $zero, 0x118($t8)
    MEM_H(0X118, ctx->r24) = 0;
    // 0x80014D78: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80014D7C: nop

    // 0x80014D80: sh          $zero, 0x11A($t9)
    MEM_H(0X11A, ctx->r25) = 0;
    // 0x80014D84: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80014D88: nop

    // 0x80014D8C: sh          $zero, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = 0;
    // 0x80014D90: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80014D94: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80014D98: b           L_80014F20
    // 0x80014D9C: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
        goto L_80014F20;
    // 0x80014D9C: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
L_80014DA0:
    // 0x80014DA0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80014DA4: nop

    // 0x80014DA8: lw          $t4, 0x1AC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1AC);
    // 0x80014DAC: nop

    // 0x80014DB0: slti        $at, $t4, 0x6000
    ctx->r1 = SIGNED(ctx->r12) < 0X6000 ? 1 : 0;
    // 0x80014DB4: beq         $at, $zero, L_80014F20
    if (ctx->r1 == 0) {
        // 0x80014DB8: nop

            goto L_80014F20;
    }
    // 0x80014DB8: nop

    // 0x80014DBC: jal         0x8000D164
    // 0x80014DC0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    TempHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x80014DC0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x80014DC4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80014DC8: nop

    // 0x80014DCC: sw          $v0, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r2;
    // 0x80014DD0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80014DD4: nop

    // 0x80014DD8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80014DDC: nop

    // 0x80014DE0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80014DE4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014DE8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80014DEC: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x80014DF0: nop

    // 0x80014DF4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80014DF8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80014DFC: lw          $t1, -0x4EC4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4EC4);
    // 0x80014E00: nop

    // 0x80014E04: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80014E08: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80014E0C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80014E10: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80014E14: nop

    // 0x80014E18: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80014E1C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80014E20: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80014E24: nop

    // 0x80014E28: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80014E2C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80014E30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80014E34: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80014E38: jal         0x800AFB70
    // 0x80014E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x80014E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80014E40: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80014E44: nop

    // 0x80014E48: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // 0x80014E4C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80014E50: nop

    // 0x80014E54: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x80014E58: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80014E5C: nop

    // 0x80014E60: addiu       $t1, $t0, 0x24
    ctx->r9 = ADD32(ctx->r8, 0X24);
    // 0x80014E64: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80014E68: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80014E6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80014E70: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80014E74: nop

    // 0x80014E78: beq         $t3, $at, L_80014F20
    if (ctx->r11 == ctx->r1) {
        // 0x80014E7C: nop

            goto L_80014F20;
    }
    // 0x80014E7C: nop

L_80014E80:
    // 0x80014E80: jal         0x800BC6EC
    // 0x80014E84: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80014E84: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x80014E88: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80014E8C: nop

    // 0x80014E90: sw          $v0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r2;
    // 0x80014E94: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80014E98: nop

    // 0x80014E9C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80014EA0: nop

    // 0x80014EA4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80014EA8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80014EAC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80014EB0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014EB4: nop

    // 0x80014EB8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80014EBC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80014EC0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80014EC4: nop

    // 0x80014EC8: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80014ECC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80014ED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80014ED4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80014ED8: jal         0x800AFB70
    // 0x80014EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_4;
    // 0x80014EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80014EE0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80014EE4: nop

    // 0x80014EE8: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x80014EEC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80014EF0: nop

    // 0x80014EF4: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x80014EF8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80014EFC: nop

    // 0x80014F00: addiu       $t6, $t5, 0x24
    ctx->r14 = ADD32(ctx->r13, 0X24);
    // 0x80014F04: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80014F08: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80014F0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80014F10: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014F14: nop

    // 0x80014F18: bne         $t8, $at, L_80014E80
    if (ctx->r24 != ctx->r1) {
        // 0x80014F1C: nop

            goto L_80014E80;
    }
    // 0x80014F1C: nop

L_80014F20:
    // 0x80014F20: b           L_80014F28
    // 0x80014F24: nop

        goto L_80014F28;
    // 0x80014F24: nop

L_80014F28:
    // 0x80014F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014F2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014F30: jr          $ra
    // 0x80014F34: nop

    return;
    // 0x80014F34: nop

;}
RECOMP_FUNC void func_80014F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014F38: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80014F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014F40: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80014F44: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80014F48: nop

    // 0x80014F4C: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80014F50: nop

    // 0x80014F54: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x80014F58: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80014F5C: nop

    // 0x80014F60: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80014F64: nop

    // 0x80014F68: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x80014F6C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80014F70: nop

    // 0x80014F74: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80014F78: nop

    // 0x80014F7C: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80014F80: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80014F84: nop

    // 0x80014F88: lw          $t3, 0x1AC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1AC);
    // 0x80014F8C: nop

    // 0x80014F90: addiu       $t4, $t3, -0x4000
    ctx->r12 = ADD32(ctx->r11, -0X4000);
    // 0x80014F94: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
    // 0x80014F98: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80014F9C: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80014FA0: lw          $t6, 0x1AC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1AC);
    // 0x80014FA4: nop

    // 0x80014FA8: bne         $t6, $at, L_80014FB8
    if (ctx->r14 != ctx->r1) {
        // 0x80014FAC: nop

            goto L_80014FB8;
    }
    // 0x80014FAC: nop

    // 0x80014FB0: b           L_80015B54
    // 0x80014FB4: nop

        goto L_80015B54;
    // 0x80014FB4: nop

L_80014FB8:
    // 0x80014FB8: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80014FBC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80014FC0: lw          $t8, 0x1AC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1AC);
    // 0x80014FC4: nop

    // 0x80014FC8: bne         $t8, $at, L_800158E8
    if (ctx->r24 != ctx->r1) {
        // 0x80014FCC: nop

            goto L_800158E8;
    }
    // 0x80014FCC: nop

    // 0x80014FD0: jal         0x8000D688
    // 0x80014FD4: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x80014FD4: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_0:
    // 0x80014FD8: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80014FDC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80014FE0: nop

    // 0x80014FE4: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80014FE8: jal         0x800C1754
    // 0x80014FEC: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_1;
    // 0x80014FEC: nop

    after_1:
    // 0x80014FF0: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80014FF4: nop

    // 0x80014FF8: lwc1        $f12, 0xCC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x80014FFC: lwc1        $f14, 0xD0($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80015000: lw          $a2, 0xD4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XD4);
    // 0x80015004: jal         0x800C2304
    // 0x80015008: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_2;
    // 0x80015008: nop

    after_2:
    // 0x8001500C: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x80015010: nop

    // 0x80015014: lwc1        $f12, 0xF0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XF0);
    // 0x80015018: jal         0x800C2780
    // 0x8001501C: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_3;
    // 0x8001501C: nop

    after_3:
    // 0x80015020: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80015024: nop

    // 0x80015028: lwc1        $f12, 0xEC($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XEC);
    // 0x8001502C: jal         0x800C25B8
    // 0x80015030: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_4;
    // 0x80015030: nop

    after_4:
    // 0x80015034: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80015038: nop

    // 0x8001503C: lwc1        $f12, 0xE8($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XE8);
    // 0x80015040: jal         0x800C23E8
    // 0x80015044: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_5;
    // 0x80015044: nop

    after_5:
    // 0x80015048: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8001504C: nop

    // 0x80015050: lwc1        $f12, 0xCC($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x80015054: lwc1        $f14, 0xD0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x80015058: lw          $a2, 0xD4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XD4);
    // 0x8001505C: jal         0x800C2304
    // 0x80015060: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_6;
    // 0x80015060: nop

    after_6:
    // 0x80015064: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80015068: nop

    // 0x8001506C: lwc1        $f12, 0xF0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XF0);
    // 0x80015070: jal         0x800C2780
    // 0x80015074: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_7;
    // 0x80015074: nop

    after_7:
    // 0x80015078: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8001507C: nop

    // 0x80015080: lwc1        $f12, 0xEC($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XEC);
    // 0x80015084: jal         0x800C25B8
    // 0x80015088: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_8;
    // 0x80015088: nop

    after_8:
    // 0x8001508C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80015090: nop

    // 0x80015094: lwc1        $f12, 0xE8($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x80015098: jal         0x800C23E8
    // 0x8001509C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_9;
    // 0x8001509C: nop

    after_9:
    // 0x800150A0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800150A4: jal         0x800C1A84
    // 0x800150A8: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_10;
    // 0x800150A8: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    after_10:
    // 0x800150AC: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800150B0: nop

    // 0x800150B4: lwc1        $f4, 0xD4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XD4);
    // 0x800150B8: lwc1        $f12, 0xCC($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x800150BC: lwc1        $f14, 0xD0($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x800150C0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800150C4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800150C8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800150CC: jal         0x800C2304
    // 0x800150D0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_11;
    // 0x800150D0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
    after_11:
    // 0x800150D4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800150D8: jal         0x800C1A84
    // 0x800150DC: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_12;
    // 0x800150DC: addiu       $a0, $a0, -0x5A90
    ctx->r4 = ADD32(ctx->r4, -0X5A90);
    after_12:
    // 0x800150E0: jal         0x800C1A28
    // 0x800150E4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_13;
    // 0x800150E4: nop

    after_13:
    // 0x800150E8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800150EC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800150F0: addiu       $t0, $t0, -0x5AD0
    ctx->r8 = ADD32(ctx->r8, -0X5AD0);
    // 0x800150F4: addiu       $t9, $t9, -0x5A90
    ctx->r25 = ADD32(ctx->r25, -0X5A90);
    // 0x800150F8: lwc1        $f8, 0x30($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X30);
    // 0x800150FC: lwc1        $f10, 0x30($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80015100: nop

    // 0x80015104: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80015108: nop

    // 0x8001510C: bc1f        L_80015138
    if (!c1cs) {
        // 0x80015110: nop

            goto L_80015138;
    }
    // 0x80015110: nop

    // 0x80015114: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80015118: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001511C: lwc1        $f16, 0xB0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XB0);
    // 0x80015120: lwc1        $f5, -0x2A68($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2A68);
    // 0x80015124: lwc1        $f4, -0x2A64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A64);
    // 0x80015128: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001512C: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80015130: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80015134: swc1        $f8, 0xB0($t1)
    MEM_W(0XB0, ctx->r9) = ctx->f8.u32l;
L_80015138:
    // 0x80015138: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001513C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80015140: addiu       $t3, $t3, -0x5AD0
    ctx->r11 = ADD32(ctx->r11, -0X5AD0);
    // 0x80015144: addiu       $t2, $t2, -0x5A90
    ctx->r10 = ADD32(ctx->r10, -0X5A90);
    // 0x80015148: lwc1        $f10, 0x34($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8001514C: lwc1        $f16, 0x34($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X34);
    // 0x80015150: nop

    // 0x80015154: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80015158: nop

    // 0x8001515C: bc1f        L_80015188
    if (!c1cs) {
        // 0x80015160: nop

            goto L_80015188;
    }
    // 0x80015160: nop

    // 0x80015164: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80015168: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001516C: lwc1        $f18, 0xB4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XB4);
    // 0x80015170: lwc1        $f7, -0x2A60($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2A60);
    // 0x80015174: lwc1        $f6, -0x2A5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A5C);
    // 0x80015178: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8001517C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80015180: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80015184: swc1        $f10, 0xB4($t4)
    MEM_W(0XB4, ctx->r12) = ctx->f10.u32l;
L_80015188:
    // 0x80015188: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001518C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80015190: addiu       $t6, $t6, -0x5AD0
    ctx->r14 = ADD32(ctx->r14, -0X5AD0);
    // 0x80015194: addiu       $t5, $t5, -0x5A90
    ctx->r13 = ADD32(ctx->r13, -0X5A90);
    // 0x80015198: lwc1        $f16, 0x38($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X38);
    // 0x8001519C: lwc1        $f18, 0x38($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X38);
    // 0x800151A0: nop

    // 0x800151A4: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800151A8: nop

    // 0x800151AC: bc1f        L_800151D8
    if (!c1cs) {
        // 0x800151B0: nop

            goto L_800151D8;
    }
    // 0x800151B0: nop

    // 0x800151B4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800151B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800151BC: lwc1        $f4, 0xB8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XB8);
    // 0x800151C0: lwc1        $f9, -0x2A58($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2A58);
    // 0x800151C4: lwc1        $f8, -0x2A54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A54);
    // 0x800151C8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800151CC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x800151D0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800151D4: swc1        $f16, 0xB8($t7)
    MEM_W(0XB8, ctx->r15) = ctx->f16.u32l;
L_800151D8:
    // 0x800151D8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800151DC: addiu       $t8, $t8, -0x5AD0
    ctx->r24 = ADD32(ctx->r24, -0X5AD0);
    // 0x800151E0: lwc1        $f18, 0x30($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X30);
    // 0x800151E4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800151E8: addiu       $t9, $t9, -0x5B00
    ctx->r25 = ADD32(ctx->r25, -0X5B00);
    // 0x800151EC: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
    // 0x800151F0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800151F4: addiu       $t0, $t0, -0x5AD0
    ctx->r8 = ADD32(ctx->r8, -0X5AD0);
    // 0x800151F8: lwc1        $f4, 0x34($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X34);
    // 0x800151FC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80015200: addiu       $t1, $t1, -0x5B00
    ctx->r9 = ADD32(ctx->r9, -0X5B00);
    // 0x80015204: swc1        $f4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f4.u32l;
    // 0x80015208: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001520C: addiu       $t2, $t2, -0x5AD0
    ctx->r10 = ADD32(ctx->r10, -0X5AD0);
    // 0x80015210: lwc1        $f6, 0x38($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X38);
    // 0x80015214: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80015218: addiu       $t3, $t3, -0x5B00
    ctx->r11 = ADD32(ctx->r11, -0X5B00);
    // 0x8001521C: swc1        $f6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f6.u32l;
    // 0x80015220: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80015224: addiu       $t4, $t4, -0x5A90
    ctx->r12 = ADD32(ctx->r12, -0X5A90);
    // 0x80015228: lwc1        $f8, 0x30($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X30);
    // 0x8001522C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80015230: addiu       $t5, $t5, -0x5B00
    ctx->r13 = ADD32(ctx->r13, -0X5B00);
    // 0x80015234: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x80015238: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8001523C: addiu       $t6, $t6, -0x5A90
    ctx->r14 = ADD32(ctx->r14, -0X5A90);
    // 0x80015240: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x80015244: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80015248: addiu       $t7, $t7, -0x5B00
    ctx->r15 = ADD32(ctx->r15, -0X5B00);
    // 0x8001524C: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x80015250: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80015254: addiu       $t8, $t8, -0x5A90
    ctx->r24 = ADD32(ctx->r24, -0X5A90);
    // 0x80015258: lwc1        $f16, 0x38($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X38);
    // 0x8001525C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80015260: addiu       $t9, $t9, -0x5B00
    ctx->r25 = ADD32(ctx->r25, -0X5B00);
    // 0x80015264: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    // 0x80015268: jal         0x800C1754
    // 0x8001526C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_14;
    // 0x8001526C: nop

    after_14:
    // 0x80015270: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80015274: jal         0x800C1AF4
    // 0x80015278: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_15;
    // 0x80015278: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    after_15:
    // 0x8001527C: jal         0x800C1908
    // 0x80015280: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_ClearTranslation(rdram, ctx);
        goto after_16;
    // 0x80015280: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80015284: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015288: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001528C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80015290: jal         0x800C2304
    // 0x80015294: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_17;
    // 0x80015294: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_17:
    // 0x80015298: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001529C: jal         0x800C1A84
    // 0x800152A0: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_18;
    // 0x800152A0: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    after_18:
    // 0x800152A4: jal         0x800C1A28
    // 0x800152A8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_19;
    // 0x800152A8: nop

    after_19:
    // 0x800152AC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800152B0: addiu       $t0, $t0, -0x5AD0
    ctx->r8 = ADD32(ctx->r8, -0X5AD0);
    // 0x800152B4: lwc1        $f18, 0x30($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X30);
    // 0x800152B8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800152BC: addiu       $t1, $t1, -0x5B00
    ctx->r9 = ADD32(ctx->r9, -0X5B00);
    // 0x800152C0: swc1        $f18, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f18.u32l;
    // 0x800152C4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800152C8: addiu       $t2, $t2, -0x5AD0
    ctx->r10 = ADD32(ctx->r10, -0X5AD0);
    // 0x800152CC: lwc1        $f4, 0x34($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800152D0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800152D4: addiu       $t3, $t3, -0x5B00
    ctx->r11 = ADD32(ctx->r11, -0X5B00);
    // 0x800152D8: swc1        $f4, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f4.u32l;
    // 0x800152DC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800152E0: addiu       $t4, $t4, -0x5AD0
    ctx->r12 = ADD32(ctx->r12, -0X5AD0);
    // 0x800152E4: lwc1        $f6, 0x38($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X38);
    // 0x800152E8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800152EC: addiu       $t5, $t5, -0x5B00
    ctx->r13 = ADD32(ctx->r13, -0X5B00);
    // 0x800152F0: swc1        $f6, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->f6.u32l;
    // 0x800152F4: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800152F8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800152FC: lwc1        $f8, 0xF4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XF4);
    // 0x80015300: addiu       $t7, $t7, -0x5B00
    ctx->r15 = ADD32(ctx->r15, -0X5B00);
    // 0x80015304: swc1        $f8, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f8.u32l;
    // 0x80015308: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8001530C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80015310: lwc1        $f10, 0xF4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x80015314: addiu       $t9, $t9, -0x5B00
    ctx->r25 = ADD32(ctx->r25, -0X5B00);
    // 0x80015318: swc1        $f10, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f10.u32l;
    // 0x8001531C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80015320: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80015324: lwc1        $f16, 0xF4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XF4);
    // 0x80015328: addiu       $t1, $t1, -0x5B00
    ctx->r9 = ADD32(ctx->r9, -0X5B00);
    // 0x8001532C: swc1        $f16, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f16.u32l;
    // 0x80015330: jal         0x800C1680
    // 0x80015334: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_20;
    // 0x80015334: nop

    after_20:
    // 0x80015338: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8001533C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80015340: addiu       $a1, $a1, -0x5B00
    ctx->r5 = ADD32(ctx->r5, -0X5B00);
    // 0x80015344: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80015348: jal         0x800B1250
    // 0x8001534C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_21;
    // 0x8001534C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x80015350: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80015354: jal         0x800C1A84
    // 0x80015358: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_22;
    // 0x80015358: addiu       $a0, $a0, -0x5AD0
    ctx->r4 = ADD32(ctx->r4, -0X5AD0);
    after_22:
    // 0x8001535C: jal         0x800C1A28
    // 0x80015360: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_23;
    // 0x80015360: nop

    after_23:
    // 0x80015364: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80015368: lw          $t2, 0x1B44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1B44);
    // 0x8001536C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80015370: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80015374: sw          $t3, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r11;
    // 0x80015378: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x8001537C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80015380: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80015384: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80015388: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001538C: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x80015390: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80015394: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80015398: addiu       $t6, $t6, -0x47F8
    ctx->r14 = ADD32(ctx->r14, -0X47F8);
    // 0x8001539C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800153A0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800153A4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800153A8: lw          $t9, 0x1B44($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1B44);
    // 0x800153AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800153B0: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800153B4: sw          $t0, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r8;
    // 0x800153B8: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x800153BC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800153C0: lui         $t1, 0xBC00
    ctx->r9 = S32(0XBC00 << 16);
    // 0x800153C4: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x800153C8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800153CC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800153D0: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800153D4: ori         $t3, $t3, 0x60
    ctx->r11 = ctx->r11 | 0X60;
    // 0x800153D8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800153DC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800153E0: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x800153E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800153E8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800153EC: sw          $t6, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r14;
    // 0x800153F0: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x800153F4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800153F8: lui         $t7, 0x386
    ctx->r15 = S32(0X386 << 16);
    // 0x800153FC: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x80015400: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80015404: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80015408: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8001540C: addiu       $t9, $t9, -0x5730
    ctx->r25 = ADD32(ctx->r25, -0X5730);
    // 0x80015410: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80015414: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80015418: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8001541C: lw          $t2, 0x1B44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1B44);
    // 0x80015420: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80015424: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80015428: sw          $t3, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r11;
    // 0x8001542C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x80015430: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80015434: lui         $t4, 0x388
    ctx->r12 = S32(0X388 << 16);
    // 0x80015438: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x8001543C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80015440: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80015444: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80015448: addiu       $t6, $t6, -0x5730
    ctx->r14 = ADD32(ctx->r14, -0X5730);
    // 0x8001544C: addiu       $t7, $t6, 0x18
    ctx->r15 = ADD32(ctx->r14, 0X18);
    // 0x80015450: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80015454: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80015458: lw          $t9, 0x1B44($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1B44);
    // 0x8001545C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80015460: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80015464: sw          $t0, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r8;
    // 0x80015468: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8001546C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80015470: lui         $t1, 0x38A
    ctx->r9 = S32(0X38A << 16);
    // 0x80015474: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x80015478: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8001547C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80015480: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80015484: addiu       $t3, $t3, -0x5730
    ctx->r11 = ADD32(ctx->r11, -0X5730);
    // 0x80015488: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8001548C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80015490: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x80015494: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80015498: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8001549C: sw          $t6, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r14;
    // 0x800154A0: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x800154A4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800154A8: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x800154AC: ori         $t7, $t7, 0x404
    ctx->r15 = ctx->r15 | 0X404;
    // 0x800154B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800154B4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800154B8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800154BC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800154C0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800154C4: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x800154C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800154CC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800154D0: sw          $t2, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r10;
    // 0x800154D4: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800154D8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800154DC: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x800154E0: ori         $t3, $t3, 0xC04
    ctx->r11 = ctx->r11 | 0XC04;
    // 0x800154E4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800154E8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800154EC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800154F0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800154F4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800154F8: lw          $t7, 0x1B44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B44);
    // 0x800154FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80015500: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80015504: sw          $t8, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r24;
    // 0x80015508: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8001550C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80015510: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x80015514: ori         $t9, $t9, 0x1404
    ctx->r25 = ctx->r25 | 0X1404;
    // 0x80015518: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8001551C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80015520: ori         $t1, $zero, 0xFFFE
    ctx->r9 = 0 | 0XFFFE;
    // 0x80015524: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80015528: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001552C: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x80015530: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80015534: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80015538: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x8001553C: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80015540: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80015544: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x80015548: ori         $t5, $t5, 0x1C04
    ctx->r13 = ctx->r13 | 0X1C04;
    // 0x8001554C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80015550: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80015554: ori         $t7, $zero, 0xFFFE
    ctx->r15 = 0 | 0XFFFE;
    // 0x80015558: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8001555C: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80015560: nop

    // 0x80015564: lwc1        $f18, 0x1B0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X1B0);
    // 0x80015568: lwc1        $f4, 0x1B4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1B4);
    // 0x8001556C: nop

    // 0x80015570: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80015574: nop

    // 0x80015578: bc1f        L_80015690
    if (!c1cs) {
        // 0x8001557C: nop

            goto L_80015690;
    }
    // 0x8001557C: nop

    // 0x80015580: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80015584: lw          $t0, 0x1B44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B44);
    // 0x80015588: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001558C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80015590: sw          $t1, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r9;
    // 0x80015594: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80015598: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8001559C: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x800155A0: ori         $t2, $t2, 0x1402
    ctx->r10 = ctx->r10 | 0X1402;
    // 0x800155A4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800155A8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800155AC: nop

    // 0x800155B0: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800155B4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800155B8: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x800155BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800155C0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800155C4: sw          $t6, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r14;
    // 0x800155C8: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800155CC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800155D0: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x800155D4: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x800155D8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800155DC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800155E0: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x800155E4: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x800155E8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800155EC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800155F0: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x800155F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800155F8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800155FC: sw          $t2, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r10;
    // 0x80015600: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80015604: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80015608: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x8001560C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80015610: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80015614: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80015618: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8001561C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80015620: lw          $t7, 0x1B44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B44);
    // 0x80015624: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80015628: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8001562C: sw          $t8, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r24;
    // 0x80015630: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80015634: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80015638: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x8001563C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80015640: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80015644: lui         $t1, 0x2
    ctx->r9 = S32(0X2 << 16);
    // 0x80015648: ori         $t1, $t1, 0x2205
    ctx->r9 = ctx->r9 | 0X2205;
    // 0x8001564C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80015650: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80015654: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x80015658: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001565C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80015660: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x80015664: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80015668: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001566C: lui         $t5, 0xFC12
    ctx->r13 = S32(0XFC12 << 16);
    // 0x80015670: ori         $t5, $t5, 0x1824
    ctx->r13 = ctx->r13 | 0X1824;
    // 0x80015674: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80015678: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8001567C: lui         $t7, 0xFF33
    ctx->r15 = S32(0XFF33 << 16);
    // 0x80015680: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80015684: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80015688: b           L_800158D0
    // 0x8001568C: nop

        goto L_800158D0;
    // 0x8001568C: nop

L_80015690:
    // 0x80015690: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80015694: lw          $t9, 0x1B44($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1B44);
    // 0x80015698: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001569C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800156A0: sw          $t0, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r8;
    // 0x800156A4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800156A8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800156AC: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x800156B0: ori         $t1, $t1, 0x1402
    ctx->r9 = ctx->r9 | 0X1402;
    // 0x800156B4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800156B8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800156BC: lui         $t3, 0x10
    ctx->r11 = S32(0X10 << 16);
    // 0x800156C0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800156C4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800156C8: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x800156CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800156D0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800156D4: sw          $t6, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r14;
    // 0x800156D8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800156DC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800156E0: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x800156E4: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x800156E8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800156EC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800156F0: lui         $t9, 0xC811
    ctx->r25 = S32(0XC811 << 16);
    // 0x800156F4: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x800156F8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800156FC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80015700: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x80015704: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80015708: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8001570C: sw          $t2, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r10;
    // 0x80015710: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80015714: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80015718: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8001571C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80015720: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80015724: lui         $t5, 0x3
    ctx->r13 = S32(0X3 << 16);
    // 0x80015728: ori         $t5, $t5, 0x2205
    ctx->r13 = ctx->r13 | 0X2205;
    // 0x8001572C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80015730: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80015734: lw          $t7, 0x1B44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B44);
    // 0x80015738: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001573C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80015740: sw          $t8, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r24;
    // 0x80015744: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80015748: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001574C: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x80015750: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x80015754: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80015758: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001575C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80015760: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80015764: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015768: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001576C: lwc1        $f6, 0x1B4($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x80015770: lwc1        $f10, 0x1B0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1B0);
    // 0x80015774: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80015778: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8001577C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80015780: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80015784: ori         $t7, $t7, 0xF400
    ctx->r15 = ctx->r15 | 0XF400;
    // 0x80015788: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8001578C: nop

    // 0x80015790: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80015794: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015798: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001579C: nop

    // 0x800157A0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800157A4: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800157A8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800157AC: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x800157B0: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x800157B4: bne         $t6, $zero, L_800157C0
    if (ctx->r14 != 0) {
        // 0x800157B8: nop

            goto L_800157C0;
    }
    // 0x800157B8: nop

    // 0x800157BC: break       7
    do_break(2147571644);
L_800157C0:
    // 0x800157C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800157C4: bne         $t6, $at, L_800157D8
    if (ctx->r14 != ctx->r1) {
        // 0x800157C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800157D8;
    }
    // 0x800157C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800157CC: bne         $t7, $at, L_800157D8
    if (ctx->r15 != ctx->r1) {
        // 0x800157D0: nop

            goto L_800157D8;
    }
    // 0x800157D0: nop

    // 0x800157D4: break       6
    do_break(2147571668);
L_800157D8:
    // 0x800157D8: negu        $t2, $t5
    ctx->r10 = SUB32(0, ctx->r13);
    // 0x800157DC: sll         $t1, $t2, 8
    ctx->r9 = S32(ctx->r10 << 8);
    // 0x800157E0: addu        $at, $t7, $zero
    ctx->r1 = ADD32(ctx->r15, 0);
    // 0x800157E4: addu        $t4, $t1, $at
    ctx->r12 = ADD32(ctx->r9, ctx->r1);
    // 0x800157E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800157EC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800157F0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x800157F4: div         $zero, $t4, $t6
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r14)));
    // 0x800157F8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800157FC: bne         $t6, $zero, L_80015808
    if (ctx->r14 != 0) {
        // 0x80015800: nop

            goto L_80015808;
    }
    // 0x80015800: nop

    // 0x80015804: break       7
    do_break(2147571716);
L_80015808:
    // 0x80015808: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001580C: bne         $t6, $at, L_80015820
    if (ctx->r14 != ctx->r1) {
        // 0x80015810: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80015820;
    }
    // 0x80015810: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80015814: bne         $t4, $at, L_80015820
    if (ctx->r12 != ctx->r1) {
        // 0x80015818: nop

            goto L_80015820;
    }
    // 0x80015818: nop

    // 0x8001581C: break       6
    do_break(2147571740);
L_80015820:
    // 0x80015820: mflo        $t3
    ctx->r11 = lo;
    // 0x80015824: andi        $t7, $t3, 0xFFFF
    ctx->r15 = ctx->r11 & 0XFFFF;
    // 0x80015828: or          $t8, $t0, $t7
    ctx->r24 = ctx->r8 | ctx->r15;
    // 0x8001582C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80015830: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80015834: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x80015838: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001583C: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x80015840: sw          $t2, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r10;
    // 0x80015844: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80015848: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001584C: lui         $t1, 0xF800
    ctx->r9 = S32(0XF800 << 16);
    // 0x80015850: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x80015854: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80015858: nop

    // 0x8001585C: lh          $t3, 0x118($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X118);
    // 0x80015860: lh          $t8, 0x11A($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X11A);
    // 0x80015864: lh          $t1, 0x11C($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X11C);
    // 0x80015868: andi        $t0, $t3, 0xFF
    ctx->r8 = ctx->r11 & 0XFF;
    // 0x8001586C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80015870: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x80015874: sll         $t7, $t0, 24
    ctx->r15 = S32(ctx->r8 << 24);
    // 0x80015878: lh          $t8, 0x11E($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X11E);
    // 0x8001587C: or          $t2, $t7, $t5
    ctx->r10 = ctx->r15 | ctx->r13;
    // 0x80015880: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x80015884: sll         $t3, $t4, 8
    ctx->r11 = S32(ctx->r12 << 8);
    // 0x80015888: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001588C: or          $t0, $t2, $t3
    ctx->r8 = ctx->r10 | ctx->r11;
    // 0x80015890: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80015894: or          $t7, $t0, $t9
    ctx->r15 = ctx->r8 | ctx->r25;
    // 0x80015898: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8001589C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800158A0: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x800158A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800158A8: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x800158AC: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x800158B0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800158B4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800158B8: lui         $t2, 0xFC12
    ctx->r10 = S32(0XFC12 << 16);
    // 0x800158BC: ori         $t2, $t2, 0x19FF
    ctx->r10 = ctx->r10 | 0X19FF;
    // 0x800158C0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800158C4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800158C8: addiu       $t6, $zero, -0x1C8
    ctx->r14 = ADD32(0, -0X1C8);
    // 0x800158CC: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
L_800158D0:
    // 0x800158D0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800158D4: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800158D8: jal         0x800AD1E4
    // 0x800158DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_24;
    // 0x800158DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_24:
    // 0x800158E0: b           L_80015B54
    // 0x800158E4: nop

        goto L_80015B54;
    // 0x800158E4: nop

L_800158E8:
    // 0x800158E8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800158EC: nop

    // 0x800158F0: lw          $t9, 0x1AC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X1AC);
    // 0x800158F4: nop

    // 0x800158F8: slti        $at, $t9, 0x6000
    ctx->r1 = SIGNED(ctx->r25) < 0X6000 ? 1 : 0;
    // 0x800158FC: beq         $at, $zero, L_80015B54
    if (ctx->r1 == 0) {
        // 0x80015900: nop

            goto L_80015B54;
    }
    // 0x80015900: nop

    // 0x80015904: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80015908: nop

    // 0x8001590C: lh          $t5, 0x11E($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X11E);
    // 0x80015910: nop

    // 0x80015914: beq         $t5, $zero, L_80015B54
    if (ctx->r13 == 0) {
        // 0x80015918: nop

            goto L_80015B54;
    }
    // 0x80015918: nop

    // 0x8001591C: jal         0x800C1754
    // 0x80015920: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_25;
    // 0x80015920: nop

    after_25:
    // 0x80015924: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80015928: addiu       $t1, $t1, -0x5B00
    ctx->r9 = ADD32(ctx->r9, -0X5B00);
    // 0x8001592C: lwc1        $f12, 0x18($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80015930: lwc1        $f14, 0x1C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80015934: lw          $a2, 0x20($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X20);
    // 0x80015938: jal         0x800C2948
    // 0x8001593C: nop

    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_26;
    // 0x8001593C: nop

    after_26:
    // 0x80015940: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80015944: nop

    // 0x80015948: lwc1        $f12, 0xCC($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8001594C: lwc1        $f14, 0xD0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x80015950: lw          $a2, 0xD4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XD4);
    // 0x80015954: jal         0x800C2304
    // 0x80015958: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_27;
    // 0x80015958: nop

    after_27:
    // 0x8001595C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80015960: nop

    // 0x80015964: lwc1        $f12, 0xF0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XF0);
    // 0x80015968: jal         0x800C2780
    // 0x8001596C: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_28;
    // 0x8001596C: nop

    after_28:
    // 0x80015970: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80015974: nop

    // 0x80015978: lwc1        $f12, 0xEC($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XEC);
    // 0x8001597C: jal         0x800C25B8
    // 0x80015980: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_29;
    // 0x80015980: nop

    after_29:
    // 0x80015984: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80015988: nop

    // 0x8001598C: lwc1        $f12, 0xE8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x80015990: jal         0x800C23E8
    // 0x80015994: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_30;
    // 0x80015994: nop

    after_30:
L_80015998:
    // 0x80015998: jal         0x800C1680
    // 0x8001599C: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_31;
    // 0x8001599C: nop

    after_31:
    // 0x800159A0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800159A4: nop

    // 0x800159A8: lwc1        $f18, 0xF4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x800159AC: nop

    // 0x800159B0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800159B4: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    // 0x800159B8: jal         0x800C2948
    // 0x800159BC: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_32;
    // 0x800159BC: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    after_32:
    // 0x800159C0: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800159C4: nop

    // 0x800159C8: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x800159CC: nop

    // 0x800159D0: lwc1        $f12, 0x8($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800159D4: lwc1        $f14, 0xC($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800159D8: lw          $a2, 0x10($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X10);
    // 0x800159DC: jal         0x800C2304
    // 0x800159E0: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_33;
    // 0x800159E0: nop

    after_33:
    // 0x800159E4: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800159E8: nop

    // 0x800159EC: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x800159F0: nop

    // 0x800159F4: lwc1        $f12, 0x1C($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x800159F8: jal         0x800C2780
    // 0x800159FC: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_34;
    // 0x800159FC: nop

    after_34:
    // 0x80015A00: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80015A04: nop

    // 0x80015A08: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80015A0C: nop

    // 0x80015A10: lwc1        $f12, 0x18($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X18);
    // 0x80015A14: jal         0x800C25B8
    // 0x80015A18: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_35;
    // 0x80015A18: nop

    after_35:
    // 0x80015A1C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80015A20: nop

    // 0x80015A24: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80015A28: nop

    // 0x80015A2C: lwc1        $f12, 0x14($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80015A30: jal         0x800C23E8
    // 0x80015A34: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_36;
    // 0x80015A34: nop

    after_36:
    // 0x80015A38: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80015A3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80015A40: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80015A44: nop

    // 0x80015A48: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80015A4C: nop

    // 0x80015A50: beq         $t0, $at, L_80015AE0
    if (ctx->r8 == ctx->r1) {
        // 0x80015A54: nop

            goto L_80015AE0;
    }
    // 0x80015A54: nop

    // 0x80015A58: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80015A5C: nop

    // 0x80015A60: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80015A64: nop

    // 0x80015A68: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80015A6C: jal         0x8000D688
    // 0x80015A70: nop

    func_8000D688(rdram, ctx);
        goto after_37;
    // 0x80015A70: nop

    after_37:
    // 0x80015A74: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80015A78: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80015A7C: nop

    // 0x80015A80: beq         $t5, $zero, L_80015AE0
    if (ctx->r13 == 0) {
        // 0x80015A84: nop

            goto L_80015AE0;
    }
    // 0x80015A84: nop

    // 0x80015A88: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80015A8C: nop

    // 0x80015A90: lwc1        $f12, 0xCC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x80015A94: lwc1        $f14, 0xD0($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80015A98: lw          $a2, 0xD4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XD4);
    // 0x80015A9C: jal         0x800C2304
    // 0x80015AA0: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_38;
    // 0x80015AA0: nop

    after_38:
    // 0x80015AA4: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80015AA8: nop

    // 0x80015AAC: lwc1        $f12, 0xF0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x80015AB0: jal         0x800C2780
    // 0x80015AB4: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_39;
    // 0x80015AB4: nop

    after_39:
    // 0x80015AB8: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80015ABC: nop

    // 0x80015AC0: lwc1        $f12, 0xEC($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XEC);
    // 0x80015AC4: jal         0x800C25B8
    // 0x80015AC8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_40;
    // 0x80015AC8: nop

    after_40:
    // 0x80015ACC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80015AD0: nop

    // 0x80015AD4: lwc1        $f12, 0xE8($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XE8);
    // 0x80015AD8: jal         0x800C23E8
    // 0x80015ADC: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_41;
    // 0x80015ADC: nop

    after_41:
L_80015AE0:
    // 0x80015AE0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80015AE4: nop

    // 0x80015AE8: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80015AEC: nop

    // 0x80015AF0: lwc1        $f4, 0x20($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80015AF4: nop

    // 0x80015AF8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80015AFC: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x80015B00: jal         0x800C2948
    // 0x80015B04: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_42;
    // 0x80015B04: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_42:
    // 0x80015B08: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80015B0C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80015B10: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x80015B14: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80015B18: jal         0x800B18C4
    // 0x80015B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_43;
    // 0x80015B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_43:
    // 0x80015B20: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80015B24: nop

    // 0x80015B28: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80015B2C: nop

    // 0x80015B30: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x80015B34: jal         0x800C1A28
    // 0x80015B38: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_44;
    // 0x80015B38: nop

    after_44:
    // 0x80015B3C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80015B40: nop

    // 0x80015B44: bne         $t5, $zero, L_80015998
    if (ctx->r13 != 0) {
        // 0x80015B48: nop

            goto L_80015998;
    }
    // 0x80015B48: nop

    // 0x80015B4C: jal         0x800C1A28
    // 0x80015B50: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_45;
    // 0x80015B50: nop

    after_45:
L_80015B54:
    // 0x80015B54: b           L_80015B5C
    // 0x80015B58: nop

        goto L_80015B5C;
    // 0x80015B58: nop

L_80015B5C:
    // 0x80015B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015B60: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80015B64: jr          $ra
    // 0x80015B68: nop

    return;
    // 0x80015B68: nop

;}
RECOMP_FUNC void func_80015B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015B6C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80015B70: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x80015B74: nop

    // 0x80015B78: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80015B7C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80015B80: nop

    // 0x80015B84: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80015B88: nop

    // 0x80015B8C: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80015B90: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80015B94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015B98: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80015B9C: nop

    // 0x80015BA0: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x80015BA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015BA8: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x80015BAC: nop

    // 0x80015BB0: swc1        $f6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f6.u32l;
    // 0x80015BB4: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80015BB8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80015BBC: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x80015BC0: b           L_80015BC8
    // 0x80015BC4: nop

        goto L_80015BC8;
    // 0x80015BC4: nop

L_80015BC8:
    // 0x80015BC8: jr          $ra
    // 0x80015BCC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80015BCC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80015BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015BD0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80015BD4: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x80015BD8: nop

    // 0x80015BDC: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x80015BE0: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80015BE4: nop

    // 0x80015BE8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80015BEC: nop

    // 0x80015BF0: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80015BF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015BF8: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80015BFC: nop

    // 0x80015C00: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x80015C04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015C08: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x80015C0C: nop

    // 0x80015C10: swc1        $f6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f6.u32l;
    // 0x80015C14: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x80015C18: nop

    // 0x80015C1C: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x80015C20: b           L_80015C28
    // 0x80015C24: nop

        goto L_80015C28;
    // 0x80015C24: nop

L_80015C28:
    // 0x80015C28: jr          $ra
    // 0x80015C2C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80015C2C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80015C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015C30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80015C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015C38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80015C3C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80015C40: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80015C44: jal         0x8000DA44
    // 0x80015C48: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80015C48: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80015C4C: bgez        $v0, L_80015C5C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80015C50: nop

            goto L_80015C5C;
    }
    // 0x80015C50: nop

    // 0x80015C54: b           L_80015D64
    // 0x80015C58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80015D64;
    // 0x80015C58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015C5C:
    // 0x80015C5C: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80015C60: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80015C64: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80015C68: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80015C6C: nop

    // 0x80015C70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015C74: swc1        $f6, 0x1B0($t8)
    MEM_W(0X1B0, ctx->r24) = ctx->f6.u32l;
    // 0x80015C78: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x80015C7C: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80015C80: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80015C84: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80015C88: nop

    // 0x80015C8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80015C90: swc1        $f10, 0x1B4($t1)
    MEM_W(0X1B4, ctx->r9) = ctx->f10.u32l;
    // 0x80015C94: addiu       $t2, $sp, 0x1C
    ctx->r10 = ADD32(ctx->r29, 0X1C);
    // 0x80015C98: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x80015C9C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80015CA0: nop

    // 0x80015CA4: sh          $t3, 0x118($t4)
    MEM_H(0X118, ctx->r12) = ctx->r11;
    // 0x80015CA8: addiu       $t5, $sp, 0x1C
    ctx->r13 = ADD32(ctx->r29, 0X1C);
    // 0x80015CAC: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x80015CB0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80015CB4: nop

    // 0x80015CB8: sh          $t6, 0x11A($t7)
    MEM_H(0X11A, ctx->r15) = ctx->r14;
    // 0x80015CBC: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x80015CC0: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x80015CC4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80015CC8: nop

    // 0x80015CCC: sh          $t9, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r25;
    // 0x80015CD0: addiu       $t1, $sp, 0x1C
    ctx->r9 = ADD32(ctx->r29, 0X1C);
    // 0x80015CD4: lhu         $t2, 0xC($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XC);
    // 0x80015CD8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80015CDC: nop

    // 0x80015CE0: sh          $t2, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r10;
    // 0x80015CE4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80015CE8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80015CEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80015CF0: lwc1        $f16, 0x1B0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X1B0);
    // 0x80015CF4: nop

    // 0x80015CF8: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80015CFC: nop

    // 0x80015D00: bc1f        L_80015D1C
    if (!c1cs) {
        // 0x80015D04: nop

            goto L_80015D1C;
    }
    // 0x80015D04: nop

    // 0x80015D08: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80015D0C: lwc1        $f4, -0x2A50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A50);
    // 0x80015D10: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80015D14: nop

    // 0x80015D18: swc1        $f4, 0x1B0($t5)
    MEM_W(0X1B0, ctx->r13) = ctx->f4.u32l;
L_80015D1C:
    // 0x80015D1C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80015D20: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80015D24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80015D28: lwc1        $f6, 0x1B4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1B4);
    // 0x80015D2C: nop

    // 0x80015D30: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80015D34: nop

    // 0x80015D38: bc1f        L_80015D54
    if (!c1cs) {
        // 0x80015D3C: nop

            goto L_80015D54;
    }
    // 0x80015D3C: nop

    // 0x80015D40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80015D44: lwc1        $f10, -0x2A4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A4C);
    // 0x80015D48: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80015D4C: nop

    // 0x80015D50: swc1        $f10, 0x1B4($t7)
    MEM_W(0X1B4, ctx->r15) = ctx->f10.u32l;
L_80015D54:
    // 0x80015D54: b           L_80015D64
    // 0x80015D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80015D64;
    // 0x80015D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015D5C: b           L_80015D64
    // 0x80015D60: nop

        goto L_80015D64;
    // 0x80015D60: nop

L_80015D64:
    // 0x80015D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015D68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80015D6C: jr          $ra
    // 0x80015D70: nop

    return;
    // 0x80015D70: nop

;}
RECOMP_FUNC void func_80015D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015D74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80015D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015D7C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80015D80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80015D84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80015D88: jal         0x8000DA44
    // 0x80015D8C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80015D8C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80015D90: bgez        $v0, L_80015DA0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80015D94: nop

            goto L_80015DA0;
    }
    // 0x80015D94: nop

    // 0x80015D98: b           L_80015E38
    // 0x80015D9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80015E38;
    // 0x80015D9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015DA0:
    // 0x80015DA0: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80015DA4: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80015DA8: nop

    // 0x80015DAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80015DB0: nop

    // 0x80015DB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015DB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80015DBC: nop

    // 0x80015DC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80015DC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015DC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015DCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80015DD0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80015DD4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80015DD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80015DDC: sw          $t9, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r25;
    // 0x80015DE0: nop

    // 0x80015DE4: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x80015DE8: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80015DEC: nop

    // 0x80015DF0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80015DF4: nop

    // 0x80015DF8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80015DFC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80015E00: nop

    // 0x80015E04: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80015E08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015E0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015E10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80015E14: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80015E18: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80015E1C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80015E20: sw          $t3, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r11;
    // 0x80015E24: nop

    // 0x80015E28: b           L_80015E38
    // 0x80015E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80015E38;
    // 0x80015E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015E30: b           L_80015E38
    // 0x80015E34: nop

        goto L_80015E38;
    // 0x80015E34: nop

L_80015E38:
    // 0x80015E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015E3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80015E40: jr          $ra
    // 0x80015E44: nop

    return;
    // 0x80015E44: nop

;}
RECOMP_FUNC void func_80015E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015E48: nop

    // 0x80015E4C: nop

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
RECOMP_FUNC void func_80015E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015E94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80015E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015E9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80015EA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80015EA4:
    // 0x80015EA4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80015EA8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80015EAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80015EB0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80015EB4: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x80015EB8: nop

    // 0x80015EBC: bne         $t8, $zero, L_80015ECC
    if (ctx->r24 != 0) {
        // 0x80015EC0: nop

            goto L_80015ECC;
    }
    // 0x80015EC0: nop

    // 0x80015EC4: b           L_80015EE4
    // 0x80015EC8: nop

        goto L_80015EE4;
    // 0x80015EC8: nop

L_80015ECC:
    // 0x80015ECC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80015ED0: nop

    // 0x80015ED4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80015ED8: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80015EDC: bne         $at, $zero, L_80015EA4
    if (ctx->r1 != 0) {
        // 0x80015EE0: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_80015EA4;
    }
    // 0x80015EE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_80015EE4:
    // 0x80015EE4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80015EE8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80015EEC: bne         $t1, $at, L_80015EFC
    if (ctx->r9 != ctx->r1) {
        // 0x80015EF0: nop

            goto L_80015EFC;
    }
    // 0x80015EF0: nop

    // 0x80015EF4: b           L_80015FA4
    // 0x80015EF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80015FA4;
    // 0x80015EF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015EFC:
    // 0x80015EFC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80015F00: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80015F04: addiu       $t4, $t4, -0x4530
    ctx->r12 = ADD32(ctx->r12, -0X4530);
    // 0x80015F08: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80015F0C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80015F10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80015F14: sw          $t5, -0x4538($at)
    MEM_W(-0X4538, ctx->r1) = ctx->r13;
    // 0x80015F18: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80015F1C: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80015F20: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80015F24: nop

    // 0x80015F28: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x80015F2C: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80015F30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80015F34: jal         0x80004654
    // 0x80015F38: nop

    func_80004654(rdram, ctx);
        goto after_0;
    // 0x80015F38: nop

    after_0:
    // 0x80015F3C: bgez        $v0, L_80015F64
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80015F40: nop

            goto L_80015F64;
    }
    // 0x80015F40: nop

    // 0x80015F44: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80015F48: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80015F4C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80015F50: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80015F54: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80015F58: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x80015F5C: b           L_80015FA4
    // 0x80015F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80015FA4;
    // 0x80015F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015F64:
    // 0x80015F64: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80015F68: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80015F6C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80015F70: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80015F74: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80015F78: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80015F7C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80015F80: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80015F84: lw          $t7, -0x4538($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4538);
    // 0x80015F88: lw          $t5, 0x6C10($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6C10);
    // 0x80015F8C: nop

    // 0x80015F90: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80015F94: b           L_80015FA4
    // 0x80015F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80015FA4;
    // 0x80015F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015F9C: b           L_80015FA4
    // 0x80015FA0: nop

        goto L_80015FA4;
    // 0x80015FA0: nop

L_80015FA4:
    // 0x80015FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015FA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80015FAC: jr          $ra
    // 0x80015FB0: nop

    return;
    // 0x80015FB0: nop

;}
RECOMP_FUNC void func_80015FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015FB4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80015FB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80015FBC: bne         $a0, $at, L_80015FCC
    if (ctx->r4 != ctx->r1) {
        // 0x80015FC0: nop

            goto L_80015FCC;
    }
    // 0x80015FC0: nop

    // 0x80015FC4: b           L_8001606C
    // 0x80015FC8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001606C;
    // 0x80015FC8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015FCC:
    // 0x80015FCC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80015FD0:
    // 0x80015FD0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80015FD4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80015FD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80015FDC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80015FE0: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x80015FE4: nop

    // 0x80015FE8: beq         $t8, $zero, L_80016044
    if (ctx->r24 == 0) {
        // 0x80015FEC: nop

            goto L_80016044;
    }
    // 0x80015FEC: nop

    // 0x80015FF0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80015FF4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80015FF8: addiu       $t1, $t1, -0x4530
    ctx->r9 = ADD32(ctx->r9, -0X4530);
    // 0x80015FFC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80016000: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80016004: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80016008: sw          $t2, -0x4538($at)
    MEM_W(-0X4538, ctx->r1) = ctx->r10;
    // 0x8001600C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80016010: lw          $t3, -0x4538($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4538);
    // 0x80016014: nop

    // 0x80016018: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8001601C: nop

    // 0x80016020: lw          $t5, 0x1A4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A4);
    // 0x80016024: nop

    // 0x80016028: bne         $t5, $a0, L_80016044
    if (ctx->r13 != ctx->r4) {
        // 0x8001602C: nop

            goto L_80016044;
    }
    // 0x8001602C: nop

    // 0x80016030: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80016034: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80016038: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001603C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80016040: sw          $zero, -0x4530($at)
    MEM_W(-0X4530, ctx->r1) = 0;
L_80016044:
    // 0x80016044: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80016048: nop

    // 0x8001604C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80016050: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80016054: bne         $at, $zero, L_80015FD0
    if (ctx->r1 != 0) {
        // 0x80016058: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_80015FD0;
    }
    // 0x80016058: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8001605C: b           L_8001606C
    // 0x80016060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001606C;
    // 0x80016060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016064: b           L_8001606C
    // 0x80016068: nop

        goto L_8001606C;
    // 0x80016068: nop

L_8001606C:
    // 0x8001606C: jr          $ra
    // 0x80016070: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80016070: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80016074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016074: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80016078: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001607C: bne         $a0, $at, L_8001608C
    if (ctx->r4 != ctx->r1) {
        // 0x80016080: nop

            goto L_8001608C;
    }
    // 0x80016080: nop

    // 0x80016084: b           L_80016130
    // 0x80016088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016130;
    // 0x80016088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001608C:
    // 0x8001608C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80016090:
    // 0x80016090: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80016094: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80016098: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001609C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800160A0: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x800160A4: nop

    // 0x800160A8: beq         $t8, $zero, L_80016108
    if (ctx->r24 == 0) {
        // 0x800160AC: nop

            goto L_80016108;
    }
    // 0x800160AC: nop

    // 0x800160B0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800160B4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800160B8: addiu       $t1, $t1, -0x4530
    ctx->r9 = ADD32(ctx->r9, -0X4530);
    // 0x800160BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800160C0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800160C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800160C8: sw          $t2, -0x4538($at)
    MEM_W(-0X4538, ctx->r1) = ctx->r10;
    // 0x800160CC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800160D0: lw          $t3, -0x4538($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4538);
    // 0x800160D4: nop

    // 0x800160D8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800160DC: nop

    // 0x800160E0: lw          $t5, 0x1A4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A4);
    // 0x800160E4: nop

    // 0x800160E8: bne         $t5, $a0, L_80016108
    if (ctx->r13 != ctx->r4) {
        // 0x800160EC: nop

            goto L_80016108;
    }
    // 0x800160EC: nop

    // 0x800160F0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800160F4: lw          $t6, -0x4538($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4538);
    // 0x800160F8: nop

    // 0x800160FC: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80016100: b           L_80016130
    // 0x80016104: nop

        goto L_80016130;
    // 0x80016104: nop

L_80016108:
    // 0x80016108: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8001610C: nop

    // 0x80016110: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80016114: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x80016118: bne         $at, $zero, L_80016090
    if (ctx->r1 != 0) {
        // 0x8001611C: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_80016090;
    }
    // 0x8001611C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80016120: b           L_80016130
    // 0x80016124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016130;
    // 0x80016124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016128: b           L_80016130
    // 0x8001612C: nop

        goto L_80016130;
    // 0x8001612C: nop

L_80016130:
    // 0x80016130: jr          $ra
    // 0x80016134: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80016134: addiu       $sp, $sp, 0x8
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
RECOMP_FUNC void func_800161E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800161E0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800161E4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800161E8:
    // 0x800161E8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800161EC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800161F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800161F4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800161F8: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x800161FC: nop

    // 0x80016200: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80016204: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80016208: nop

    // 0x8001620C: beq         $t9, $zero, L_8001623C
    if (ctx->r25 == 0) {
        // 0x80016210: nop

            goto L_8001623C;
    }
    // 0x80016210: nop

    // 0x80016214: lw          $t0, 0x1A4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A4);
    // 0x80016218: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001621C: beq         $t0, $at, L_8001623C
    if (ctx->r8 == ctx->r1) {
        // 0x80016220: nop

            goto L_8001623C;
    }
    // 0x80016220: nop

    // 0x80016224: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x80016228: nop

    // 0x8001622C: lw          $t2, 0x1A0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A0);
    // 0x80016230: nop

    // 0x80016234: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80016238: sw          $t3, 0x1A0($t1)
    MEM_W(0X1A0, ctx->r9) = ctx->r11;
L_8001623C:
    // 0x8001623C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80016240: nop

    // 0x80016244: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80016248: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8001624C: bne         $at, $zero, L_800161E8
    if (ctx->r1 != 0) {
        // 0x80016250: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_800161E8;
    }
    // 0x80016250: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80016254: b           L_8001625C
    // 0x80016258: nop

        goto L_8001625C;
    // 0x80016258: nop

L_8001625C:
    // 0x8001625C: jr          $ra
    // 0x80016260: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80016260: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80016264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016264: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001626C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80016270:
    // 0x80016270: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016274: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80016278: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001627C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80016280: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x80016284: nop

    // 0x80016288: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8001628C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80016290: nop

    // 0x80016294: beq         $t9, $zero, L_8001632C
    if (ctx->r25 == 0) {
        // 0x80016298: nop

            goto L_8001632C;
    }
    // 0x80016298: nop

    // 0x8001629C: lw          $t0, 0x1A4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A4);
    // 0x800162A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800162A4: beq         $t0, $at, L_8001632C
    if (ctx->r8 == ctx->r1) {
        // 0x800162A8: nop

            goto L_8001632C;
    }
    // 0x800162A8: nop

    // 0x800162AC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800162B0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800162B4: lw          $t2, 0x1A0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A0);
    // 0x800162B8: nop

    // 0x800162BC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800162C0: sw          $t3, 0x1A0($t1)
    MEM_W(0X1A0, ctx->r9) = ctx->r11;
    // 0x800162C4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800162C8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800162CC: lw          $t5, 0x1A4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A4);
    // 0x800162D0: nop

    // 0x800162D4: beq         $t5, $at, L_800162E8
    if (ctx->r13 == ctx->r1) {
        // 0x800162D8: nop

            goto L_800162E8;
    }
    // 0x800162D8: nop

    // 0x800162DC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800162E0: bne         $t5, $at, L_8001632C
    if (ctx->r13 != ctx->r1) {
        // 0x800162E4: nop

            goto L_8001632C;
    }
    // 0x800162E4: nop

L_800162E8:
    // 0x800162E8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800162EC: nop

    // 0x800162F0: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x800162F4: nop

    // 0x800162F8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800162FC: beq         $t8, $zero, L_8001632C
    if (ctx->r24 == 0) {
        // 0x80016300: nop

            goto L_8001632C;
    }
    // 0x80016300: nop

    // 0x80016304: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80016308: nop

    // 0x8001630C: lw          $a0, 0x12C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X12C);
    // 0x80016310: jal         0x800BCCE4
    // 0x80016314: nop

    func_800BCCE4(rdram, ctx);
        goto after_0;
    // 0x80016314: nop

    after_0:
    // 0x80016318: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8001631C: nop

    // 0x80016320: lw          $a0, 0x128($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X128);
    // 0x80016324: jal         0x800BCCE4
    // 0x80016328: nop

    func_800BCCE4(rdram, ctx);
        goto after_1;
    // 0x80016328: nop

    after_1:
L_8001632C:
    // 0x8001632C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80016330: nop

    // 0x80016334: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80016338: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8001633C: bne         $at, $zero, L_80016270
    if (ctx->r1 != 0) {
        // 0x80016340: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_80016270;
    }
    // 0x80016340: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80016344: b           L_8001634C
    // 0x80016348: nop

        goto L_8001634C;
    // 0x80016348: nop

L_8001634C:
    // 0x8001634C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016354: jr          $ra
    // 0x80016358: nop

    return;
    // 0x80016358: nop

;}
RECOMP_FUNC void func_8001635C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001635C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016364: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80016368:
    // 0x80016368: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001636C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80016370: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80016374: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80016378: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x8001637C: nop

    // 0x80016380: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80016384: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80016388: nop

    // 0x8001638C: beq         $t9, $zero, L_80016400
    if (ctx->r25 == 0) {
        // 0x80016390: nop

            goto L_80016400;
    }
    // 0x80016390: nop

    // 0x80016394: lw          $t0, 0x1A0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A0);
    // 0x80016398: nop

    // 0x8001639C: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x800163A0: beq         $t1, $zero, L_80016400
    if (ctx->r9 == 0) {
        // 0x800163A4: nop

            goto L_80016400;
    }
    // 0x800163A4: nop

    // 0x800163A8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800163AC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800163B0: lw          $t3, 0x1A4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A4);
    // 0x800163B4: nop

    // 0x800163B8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800163BC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800163C0: lw          $t5, -0x248C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X248C);
    // 0x800163C4: nop

    // 0x800163C8: bne         $t5, $zero, L_800163D8
    if (ctx->r13 != 0) {
        // 0x800163CC: nop

            goto L_800163D8;
    }
    // 0x800163CC: nop

    // 0x800163D0: b           L_80016400
    // 0x800163D4: nop

        goto L_80016400;
    // 0x800163D4: nop

L_800163D8:
    // 0x800163D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800163DC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800163E0: lw          $t7, 0x1A4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A4);
    // 0x800163E4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800163E8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800163EC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800163F0: lw          $t9, -0x248C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X248C);
    // 0x800163F4: nop

    // 0x800163F8: jalr        $t9
    // 0x800163FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800163FC: nop

    after_0:
L_80016400:
    // 0x80016400: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016404: nop

    // 0x80016408: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001640C: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x80016410: bne         $at, $zero, L_80016368
    if (ctx->r1 != 0) {
        // 0x80016414: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_80016368;
    }
    // 0x80016414: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80016418: b           L_80016420
    // 0x8001641C: nop

        goto L_80016420;
    // 0x8001641C: nop

L_80016420:
    // 0x80016420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016428: jr          $ra
    // 0x8001642C: nop

    return;
    // 0x8001642C: nop

;}
RECOMP_FUNC void func_80016430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016430: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80016434: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016438: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001643C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80016440: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016444: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80016448: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001644C: nop

    // 0x80016450: lw          $t7, 0x1A0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A0);
    // 0x80016454: nop

    // 0x80016458: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x8001645C: sw          $t8, 0x1A0($t6)
    MEM_W(0X1A0, ctx->r14) = ctx->r24;
    // 0x80016460: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80016464: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80016468: sw          $t9, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r25;
    // 0x8001646C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80016470: nop

    // 0x80016474: sw          $zero, 0x1AC($t1)
    MEM_W(0X1AC, ctx->r9) = 0;
    // 0x80016478: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001647C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80016480: nop

    // 0x80016484: swc1        $f4, 0x1EC($t2)
    MEM_W(0X1EC, ctx->r10) = ctx->f4.u32l;
    // 0x80016488: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001648C: nop

    // 0x80016490: lwc1        $f6, 0x1EC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1EC);
    // 0x80016494: nop

    // 0x80016498: swc1        $f6, 0x1E8($t3)
    MEM_W(0X1E8, ctx->r11) = ctx->f6.u32l;
    // 0x8001649C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800164A0: nop

    // 0x800164A4: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x800164A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800164AC: jal         0x80099E2C
    // 0x800164B0: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x800164B0: nop

    after_0:
    // 0x800164B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800164B8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800164BC: nop

    // 0x800164C0: swc1        $f8, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f8.u32l;
    // 0x800164C4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800164C8: nop

    // 0x800164CC: lwc1        $f10, 0xD0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x800164D0: nop

    // 0x800164D4: swc1        $f10, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f10.u32l;
    // 0x800164D8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800164DC: lw          $t8, -0x4CCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CCC);
    // 0x800164E0: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x800164E4: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x800164E8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800164EC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800164F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800164F4: swc1        $f18, 0xD4($t0)
    MEM_W(0XD4, ctx->r8) = ctx->f18.u32l;
    // 0x800164F8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800164FC: nop

    // 0x80016500: sw          $zero, 0x108($t1)
    MEM_W(0X108, ctx->r9) = 0;
    // 0x80016504: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80016508: nop

    // 0x8001650C: lw          $t3, 0x108($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X108);
    // 0x80016510: nop

    // 0x80016514: sw          $t3, 0x104($t2)
    MEM_W(0X104, ctx->r10) = ctx->r11;
    // 0x80016518: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001651C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80016520: nop

    // 0x80016524: swc1        $f4, 0xF0($t4)
    MEM_W(0XF0, ctx->r12) = ctx->f4.u32l;
    // 0x80016528: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8001652C: nop

    // 0x80016530: lwc1        $f20, 0xF0($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0XF0);
    // 0x80016534: nop

    // 0x80016538: swc1        $f20, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f20.u32l;
    // 0x8001653C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80016540: nop

    // 0x80016544: swc1        $f20, 0xE8($t7)
    MEM_W(0XE8, ctx->r15) = ctx->f20.u32l;
    // 0x80016548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001654C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016550: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80016554: nop

    // 0x80016558: swc1        $f6, 0xF8($t6)
    MEM_W(0XF8, ctx->r14) = ctx->f6.u32l;
    // 0x8001655C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80016560: nop

    // 0x80016564: lwc1        $f8, 0xF8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x80016568: nop

    // 0x8001656C: swc1        $f8, 0xF4($t8)
    MEM_W(0XF4, ctx->r24) = ctx->f8.u32l;
    // 0x80016570: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80016574: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80016578: sw          $t9, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r25;
    // 0x8001657C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80016580: nop

    // 0x80016584: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x80016588: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8001658C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80016590: sh          $t3, 0x116($t2)
    MEM_H(0X116, ctx->r10) = ctx->r11;
    // 0x80016594: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80016598: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001659C: sh          $t4, 0x114($t5)
    MEM_H(0X114, ctx->r13) = ctx->r12;
    // 0x800165A0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800165A4: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x800165A8: sh          $t7, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r15;
    // 0x800165AC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800165B0: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x800165B4: sh          $t8, 0x102($t9)
    MEM_H(0X102, ctx->r25) = ctx->r24;
    // 0x800165B8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800165BC: nop

    // 0x800165C0: sh          $zero, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = 0;
    // 0x800165C4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800165C8: nop

    // 0x800165CC: lh          $s0, 0x11C($t1)
    ctx->r16 = MEM_H(ctx->r9, 0X11C);
    // 0x800165D0: nop

    // 0x800165D4: sh          $s0, 0x11A($t1)
    MEM_H(0X11A, ctx->r9) = ctx->r16;
    // 0x800165D8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800165DC: nop

    // 0x800165E0: sh          $s0, 0x118($t3)
    MEM_H(0X118, ctx->r11) = ctx->r16;
    // 0x800165E4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800165E8: lw          $t4, -0x4538($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4538);
    // 0x800165EC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800165F0: nop

    // 0x800165F4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800165F8: b           L_80016608
    // 0x800165FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016608;
    // 0x800165FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016600: b           L_80016608
    // 0x80016604: nop

        goto L_80016608;
    // 0x80016604: nop

L_80016608:
    // 0x80016608: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001660C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80016610: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80016614: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80016618: jr          $ra
    // 0x8001661C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001661C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80016620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016620: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80016624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016628: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001662C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016630: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80016634: jal         0x80016074
    // 0x80016638: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80016638: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x8001663C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80016640: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80016644: nop

    // 0x80016648: bne         $t6, $zero, L_80016658
    if (ctx->r14 != 0) {
        // 0x8001664C: nop

            goto L_80016658;
    }
    // 0x8001664C: nop

    // 0x80016650: b           L_800168A0
    // 0x80016654: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800168A0;
    // 0x80016654: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80016658:
    // 0x80016658: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001665C: nop

    // 0x80016660: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x80016664: nop

    // 0x80016668: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8001666C: sw          $t9, 0x1A8($t7)
    MEM_W(0X1A8, ctx->r15) = ctx->r25;
    // 0x80016670: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80016674: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x80016678: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8001667C: nop

    // 0x80016680: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80016684: sw          $t2, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r10;
    // 0x80016688: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8001668C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80016690: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80016694: nop

    // 0x80016698: swc1        $f4, 0x1EC($t4)
    MEM_W(0X1EC, ctx->r12) = ctx->f4.u32l;
    // 0x8001669C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800166A0: nop

    // 0x800166A4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800166A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800166AC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800166B0: nop

    // 0x800166B4: swc1        $f6, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f6.u32l;
    // 0x800166B8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800166BC: nop

    // 0x800166C0: lwc1        $f8, 0xD0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x800166C4: nop

    // 0x800166C8: swc1        $f8, 0xCC($t8)
    MEM_W(0XCC, ctx->r24) = ctx->f8.u32l;
    // 0x800166CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800166D0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800166D4: nop

    // 0x800166D8: swc1        $f10, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f10.u32l;
    // 0x800166DC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800166E0: nop

    // 0x800166E4: lwc1        $f20, 0xF0($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0XF0);
    // 0x800166E8: nop

    // 0x800166EC: swc1        $f20, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f20.u32l;
    // 0x800166F0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800166F4: nop

    // 0x800166F8: swc1        $f20, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f20.u32l;
    // 0x800166FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016700: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80016704: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80016708: nop

    // 0x8001670C: swc1        $f16, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f16.u32l;
    // 0x80016710: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80016714: nop

    // 0x80016718: lwc1        $f18, 0xF8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x8001671C: nop

    // 0x80016720: swc1        $f18, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->f18.u32l;
    // 0x80016724: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80016728: ori         $t3, $zero, 0x8044
    ctx->r11 = 0 | 0X8044;
    // 0x8001672C: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
    // 0x80016730: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80016734: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80016738: sh          $t5, 0x116($t6)
    MEM_H(0X116, ctx->r14) = ctx->r13;
    // 0x8001673C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80016740: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80016744: sh          $t8, 0x114($t9)
    MEM_H(0X114, ctx->r25) = ctx->r24;
    // 0x80016748: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8001674C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80016750: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80016754: nop

    // 0x80016758: sh          $t1, 0x118($t2)
    MEM_H(0X118, ctx->r10) = ctx->r9;
    // 0x8001675C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80016760: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80016764: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x80016768: nop

    // 0x8001676C: sh          $t3, 0x11A($t4)
    MEM_H(0X11A, ctx->r12) = ctx->r11;
    // 0x80016770: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80016774: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80016778: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8001677C: nop

    // 0x80016780: sh          $t6, 0x11C($t8)
    MEM_H(0X11C, ctx->r24) = ctx->r14;
    // 0x80016784: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80016788: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001678C: lw          $t7, 0x10($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X10);
    // 0x80016790: nop

    // 0x80016794: sh          $t7, 0x100($t1)
    MEM_H(0X100, ctx->r9) = ctx->r15;
    // 0x80016798: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8001679C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800167A0: lw          $t0, 0x14($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X14);
    // 0x800167A4: nop

    // 0x800167A8: sh          $t0, 0x102($t3)
    MEM_H(0X102, ctx->r11) = ctx->r8;
    // 0x800167AC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800167B0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800167B4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800167B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800167BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800167C0: lwc1        $f4, 0x18($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X18);
    // 0x800167C4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800167C8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800167CC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800167D0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800167D4: sw          $t6, 0x104($t8)
    MEM_W(0X104, ctx->r24) = ctx->r14;
    // 0x800167D8: nop

    // 0x800167DC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800167E0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800167E4: lwc1        $f8, 0x1C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x800167E8: nop

    // 0x800167EC: swc1        $f8, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f8.u32l;
    // 0x800167F0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800167F4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800167F8: lwc1        $f10, 0x20($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800167FC: nop

    // 0x80016800: swc1        $f10, 0xD4($t2)
    MEM_W(0XD4, ctx->r10) = ctx->f10.u32l;
    // 0x80016804: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80016808: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001680C: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x80016810: nop

    // 0x80016814: sw          $t3, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r11;
    // 0x80016818: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001681C: nop

    // 0x80016820: lw          $t6, 0x1A8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1A8);
    // 0x80016824: nop

    // 0x80016828: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x8001682C: beq         $t8, $zero, L_80016890
    if (ctx->r24 == 0) {
        // 0x80016830: nop

            goto L_80016890;
    }
    // 0x80016830: nop

    // 0x80016834: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80016838: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001683C: lw          $t7, 0x1A8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X1A8);
    // 0x80016840: nop

    // 0x80016844: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x80016848: sw          $t1, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->r9;
    // 0x8001684C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80016850: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80016854: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80016858: nop

    // 0x8001685C: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80016860: nop

    // 0x80016864: bc1f        L_8001687C
    if (!c1cs) {
        // 0x80016868: nop

            goto L_8001687C;
    }
    // 0x80016868: nop

    // 0x8001686C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016870: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80016874: b           L_80016890
    // 0x80016878: swc1        $f4, 0x1E8($t0)
    MEM_W(0X1E8, ctx->r8) = ctx->f4.u32l;
        goto L_80016890;
    // 0x80016878: swc1        $f4, 0x1E8($t0)
    MEM_W(0X1E8, ctx->r8) = ctx->f4.u32l;
L_8001687C:
    // 0x8001687C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80016880: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016884: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80016888: nop

    // 0x8001688C: swc1        $f6, 0x1E8($t3)
    MEM_W(0X1E8, ctx->r11) = ctx->f6.u32l;
L_80016890:
    // 0x80016890: b           L_800168A0
    // 0x80016894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800168A0;
    // 0x80016894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016898: b           L_800168A0
    // 0x8001689C: nop

        goto L_800168A0;
    // 0x8001689C: nop

L_800168A0:
    // 0x800168A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800168A4: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800168A8: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800168AC: jr          $ra
    // 0x800168B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800168B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800168B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800168B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800168B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800168BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800168C0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800168C4: nop

    // 0x800168C8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800168CC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800168D0: nop

    // 0x800168D4: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x800168D8: nop

    // 0x800168DC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800168E0: beq         $t9, $zero, L_80016A38
    if (ctx->r25 == 0) {
        // 0x800168E4: nop

            goto L_80016A38;
    }
    // 0x800168E4: nop

    // 0x800168E8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800168EC: nop

    // 0x800168F0: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x800168F4: nop

    // 0x800168F8: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800168FC: beq         $t2, $zero, L_8001690C
    if (ctx->r10 == 0) {
        // 0x80016900: nop

            goto L_8001690C;
    }
    // 0x80016900: nop

    // 0x80016904: b           L_80016A30
    // 0x80016908: nop

        goto L_80016A30;
    // 0x80016908: nop

L_8001690C:
    // 0x8001690C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80016910: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80016914: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80016918: lwc1        $f4, 0x1EC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X1EC);
    // 0x8001691C: lwc1        $f10, 0x1E8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X1E8);
    // 0x80016920: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80016924: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80016928: swc1        $f16, 0x1E8($t3)
    MEM_W(0X1E8, ctx->r11) = ctx->f16.u32l;
    // 0x8001692C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80016930: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016934: lwc1        $f18, 0x1E8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X1E8);
    // 0x80016938: nop

    // 0x8001693C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80016940: nop

    // 0x80016944: bc1f        L_800169A0
    if (!c1cs) {
        // 0x80016948: nop

            goto L_800169A0;
    }
    // 0x80016948: nop

    // 0x8001694C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80016950: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016954: nop

    // 0x80016958: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8001695C: nop

    // 0x80016960: bc1f        L_800169A0
    if (!c1cs) {
        // 0x80016964: nop

            goto L_800169A0;
    }
    // 0x80016964: nop

    // 0x80016968: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001696C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80016970: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80016974: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80016978: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001697C: lwc1        $f10, 0x1E8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X1E8);
    // 0x80016980: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016984: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80016988: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001698C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80016990: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80016994: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x80016998: b           L_80016A30
    // 0x8001699C: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
        goto L_80016A30;
    // 0x8001699C: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
L_800169A0:
    // 0x800169A0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800169A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800169A8: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x800169AC: nop

    // 0x800169B0: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800169B4: sw          $t3, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r11;
    // 0x800169B8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800169BC: nop

    // 0x800169C0: lw          $t5, 0x1A8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A8);
    // 0x800169C4: nop

    // 0x800169C8: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x800169CC: sw          $t6, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r14;
    // 0x800169D0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800169D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800169D8: lwc1        $f16, 0x1EC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1EC);
    // 0x800169DC: nop

    // 0x800169E0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800169E4: nop

    // 0x800169E8: bc1f        L_80016A10
    if (!c1cs) {
        // 0x800169EC: nop

            goto L_80016A10;
    }
    // 0x800169EC: nop

    // 0x800169F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800169F4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800169F8: nop

    // 0x800169FC: swc1        $f18, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f18.u32l;
    // 0x80016A00: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016A04: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80016A08: b           L_80016A30
    // 0x80016A0C: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
        goto L_80016A30;
    // 0x80016A0C: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
L_80016A10:
    // 0x80016A10: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80016A14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016A18: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80016A1C: nop

    // 0x80016A20: swc1        $f6, 0x1E8($t2)
    MEM_W(0X1E8, ctx->r10) = ctx->f6.u32l;
    // 0x80016A24: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80016A28: nop

    // 0x80016A2C: sh          $zero, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = 0;
L_80016A30:
    // 0x80016A30: b           L_80016A6C
    // 0x80016A34: nop

        goto L_80016A6C;
    // 0x80016A34: nop

L_80016A38:
    // 0x80016A38: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80016A3C: nop

    // 0x80016A40: lw          $t5, 0x1A8($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X1A8);
    // 0x80016A44: nop

    // 0x80016A48: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80016A4C: beq         $t6, $zero, L_80016A6C
    if (ctx->r14 == 0) {
        // 0x80016A50: nop

            goto L_80016A6C;
    }
    // 0x80016A50: nop

    // 0x80016A54: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80016A58: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80016A5C: lw          $t8, 0x1A8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1A8);
    // 0x80016A60: nop

    // 0x80016A64: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x80016A68: sw          $t7, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r15;
L_80016A6C:
    // 0x80016A6C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80016A70: nop

    // 0x80016A74: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x80016A78: nop

    // 0x80016A7C: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x80016A80: bne         $t2, $zero, L_80016AB8
    if (ctx->r10 != 0) {
        // 0x80016A84: nop

            goto L_80016AB8;
    }
    // 0x80016A84: nop

    // 0x80016A88: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x80016A8C: bne         $t3, $zero, L_80016AB8
    if (ctx->r11 != 0) {
        // 0x80016A90: nop

            goto L_80016AB8;
    }
    // 0x80016A90: nop

    // 0x80016A94: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80016A98: bne         $t1, $zero, L_80016AB8
    if (ctx->r9 != 0) {
        // 0x80016A9C: nop

            goto L_80016AB8;
    }
    // 0x80016A9C: nop

    // 0x80016AA0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80016AA4: nop

    // 0x80016AA8: lh          $t6, 0x11E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X11E);
    // 0x80016AAC: nop

    // 0x80016AB0: beq         $t6, $zero, L_80016AE8
    if (ctx->r14 == 0) {
        // 0x80016AB4: nop

            goto L_80016AE8;
    }
    // 0x80016AB4: nop

L_80016AB8:
    // 0x80016AB8: jal         0x800C1754
    // 0x80016ABC: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x80016ABC: nop

    after_0:
    // 0x80016AC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80016AC4: jal         0x8009A14C
    // 0x80016AC8: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x80016AC8: nop

    after_1:
    // 0x80016ACC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80016AD0: jal         0x800997D8
    // 0x80016AD4: nop

    func_800997D8(rdram, ctx);
        goto after_2;
    // 0x80016AD4: nop

    after_2:
    // 0x80016AD8: jal         0x800C1A28
    // 0x80016ADC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x80016ADC: nop

    after_3:
    // 0x80016AE0: b           L_80016AE8
    // 0x80016AE4: nop

        goto L_80016AE8;
    // 0x80016AE4: nop

L_80016AE8:
    // 0x80016AE8: b           L_80016AF8
    // 0x80016AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016AF8;
    // 0x80016AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016AF0: b           L_80016AF8
    // 0x80016AF4: nop

        goto L_80016AF8;
    // 0x80016AF4: nop

L_80016AF8:
    // 0x80016AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016AFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016B00: jr          $ra
    // 0x80016B04: nop

    return;
    // 0x80016B04: nop

    // 0x80016B08: nop

    // 0x80016B0C: nop

;}
RECOMP_FUNC void func_80016B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016B10: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80016B14: lw          $t6, 0x1A0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A0);
    // 0x80016B18: nop

    // 0x80016B1C: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80016B20: sw          $t7, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->r15;
    // 0x80016B24: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80016B28: sw          $zero, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = 0;
    // 0x80016B2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016B30: nop

    // 0x80016B34: swc1        $f4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f4.u32l;
    // 0x80016B38: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80016B3C: nop

    // 0x80016B40: swc1        $f6, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f6.u32l;
    // 0x80016B44: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016B48: nop

    // 0x80016B4C: swc1        $f8, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->f8.u32l;
    // 0x80016B50: lwc1        $f10, 0x1F4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x80016B54: nop

    // 0x80016B58: swc1        $f10, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f10.u32l;
    // 0x80016B5C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80016B60: lw          $t8, -0x4538($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4538);
    // 0x80016B64: nop

    // 0x80016B68: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x80016B6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016B70: lwc1        $f16, 0x61C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x80016B74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016B78: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80016B7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016B80: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80016B84: swc1        $f4, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f4.u32l;
    // 0x80016B88: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016B8C: lwc1        $f6, 0x61C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80016B90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016B94: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80016B98: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016B9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80016BA0: swc1        $f10, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f10.u32l;
    // 0x80016BA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016BA8: lwc1        $f16, 0x61C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80016BAC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016BB0: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80016BB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016BB8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80016BBC: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
    // 0x80016BC0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016BC4: lwc1        $f6, 0x61D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x80016BC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016BCC: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80016BD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016BD4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80016BD8: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
    // 0x80016BDC: b           L_80016BEC
    // 0x80016BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016BEC;
    // 0x80016BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016BE4: b           L_80016BEC
    // 0x80016BE8: nop

        goto L_80016BEC;
    // 0x80016BE8: nop

L_80016BEC:
    // 0x80016BEC: jr          $ra
    // 0x80016BF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80016BF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80016BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016BFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80016C00: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80016C04: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80016C08: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80016C0C: jal         0x80016074
    // 0x80016C10: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80016C10: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_0:
    // 0x80016C14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80016C18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C1C: nop

    // 0x80016C20: bne         $t6, $zero, L_80016C30
    if (ctx->r14 != 0) {
        // 0x80016C24: nop

            goto L_80016C30;
    }
    // 0x80016C24: nop

    // 0x80016C28: b           L_80016F70
    // 0x80016C2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80016F70;
    // 0x80016C2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80016C30:
    // 0x80016C30: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C34: nop

    // 0x80016C38: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80016C3C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C40: nop

    // 0x80016C44: lw          $t9, 0x1A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A8);
    // 0x80016C48: nop

    // 0x80016C4C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80016C50: sw          $t0, 0x1A8($t8)
    MEM_W(0X1A8, ctx->r24) = ctx->r8;
    // 0x80016C54: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C58: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x80016C5C: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x80016C60: nop

    // 0x80016C64: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80016C68: sw          $t3, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r11;
    // 0x80016C6C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016C70: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C74: nop

    // 0x80016C78: swc1        $f4, 0x1EC($t4)
    MEM_W(0X1EC, ctx->r12) = ctx->f4.u32l;
    // 0x80016C7C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C80: nop

    // 0x80016C84: lwc1        $f6, 0x1EC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X1EC);
    // 0x80016C88: nop

    // 0x80016C8C: swc1        $f6, 0x1E8($t5)
    MEM_W(0X1E8, ctx->r13) = ctx->f6.u32l;
    // 0x80016C90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016C94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C98: nop

    // 0x80016C9C: swc1        $f8, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->f8.u32l;
    // 0x80016CA0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80016CA4: nop

    // 0x80016CA8: lwc1        $f10, 0x1F4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X1F4);
    // 0x80016CAC: nop

    // 0x80016CB0: swc1        $f10, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f10.u32l;
    // 0x80016CB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016CB8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80016CBC: nop

    // 0x80016CC0: swc1        $f16, 0x1FC($t9)
    MEM_W(0X1FC, ctx->r25) = ctx->f16.u32l;
    // 0x80016CC4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016CC8: nop

    // 0x80016CCC: lwc1        $f18, 0x1FC($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X1FC);
    // 0x80016CD0: nop

    // 0x80016CD4: swc1        $f18, 0x1F8($t0)
    MEM_W(0X1F8, ctx->r8) = ctx->f18.u32l;
    // 0x80016CD8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80016CDC: nop

    // 0x80016CE0: andi        $t2, $t8, 0x4
    ctx->r10 = ctx->r24 & 0X4;
    // 0x80016CE4: beq         $t2, $zero, L_80016E64
    if (ctx->r10 == 0) {
        // 0x80016CE8: nop

            goto L_80016E64;
    }
    // 0x80016CE8: nop

    // 0x80016CEC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80016CF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016CF4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80016CF8: nop

    // 0x80016CFC: swc1        $f4, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f4.u32l;
    // 0x80016D00: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80016D04: nop

    // 0x80016D08: lwc1        $f6, 0xD0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80016D0C: nop

    // 0x80016D10: swc1        $f6, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f6.u32l;
    // 0x80016D14: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80016D18: nop

    // 0x80016D1C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80016D20: beq         $t5, $zero, L_80016D80
    if (ctx->r13 == 0) {
        // 0x80016D24: nop

            goto L_80016D80;
    }
    // 0x80016D24: nop

    // 0x80016D28: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016D2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016D30: swc1        $f8, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f8.u32l;
    // 0x80016D34: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016D38: swc1        $f8, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f8.u32l;
    // 0x80016D3C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016D40: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016D44: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80016D48: nop

    // 0x80016D4C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80016D50: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80016D54: nop

    // 0x80016D58: swc1        $f4, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = ctx->f4.u32l;
    // 0x80016D5C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80016D60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016D64: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016D68: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016D6C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80016D70: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80016D74: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80016D78: b           L_80016DB8
    // 0x80016D7C: swc1        $f18, 0x1F4($t7)
    MEM_W(0X1F4, ctx->r15) = ctx->f18.u32l;
        goto L_80016DB8;
    // 0x80016D7C: swc1        $f18, 0x1F4($t7)
    MEM_W(0X1F4, ctx->r15) = ctx->f18.u32l;
L_80016D80:
    // 0x80016D80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016D84: lwc1        $f4, 0x61C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x80016D88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016D8C: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80016D90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016D94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80016D98: swc1        $f8, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f8.u32l;
    // 0x80016D9C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016DA0: lwc1        $f10, 0x61C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80016DA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016DA8: lwc1        $f16, 0x7224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80016DAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016DB0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80016DB4: swc1        $f18, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f18.u32l;
L_80016DB8:
    // 0x80016DB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80016DBC: nop

    // 0x80016DC0: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x80016DC4: beq         $t0, $zero, L_80016E24
    if (ctx->r8 == 0) {
        // 0x80016DC8: nop

            goto L_80016E24;
    }
    // 0x80016DC8: nop

    // 0x80016DCC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016DD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016DD4: swc1        $f4, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f4.u32l;
    // 0x80016DD8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016DDC: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
    // 0x80016DE0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016DE4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016DE8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80016DEC: nop

    // 0x80016DF0: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016DF4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80016DF8: nop

    // 0x80016DFC: swc1        $f16, 0x1F8($t8)
    MEM_W(0X1F8, ctx->r24) = ctx->f16.u32l;
    // 0x80016E00: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80016E04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80016E08: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016E0C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016E10: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80016E14: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80016E18: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80016E1C: b           L_80016E5C
    // 0x80016E20: swc1        $f10, 0x1FC($t2)
    MEM_W(0X1FC, ctx->r10) = ctx->f10.u32l;
        goto L_80016E5C;
    // 0x80016E20: swc1        $f10, 0x1FC($t2)
    MEM_W(0X1FC, ctx->r10) = ctx->f10.u32l;
L_80016E24:
    // 0x80016E24: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016E28: lwc1        $f16, 0x61C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80016E2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016E30: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80016E34: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016E38: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80016E3C: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
    // 0x80016E40: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016E44: lwc1        $f6, 0x61D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x80016E48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80016E4C: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80016E50: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016E54: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80016E58: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
L_80016E5C:
    // 0x80016E5C: b           L_80016F60
    // 0x80016E60: nop

        goto L_80016F60;
    // 0x80016E60: nop

L_80016E64:
    // 0x80016E64: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80016E68: nop

    // 0x80016E6C: andi        $t1, $t3, 0x8
    ctx->r9 = ctx->r11 & 0X8;
    // 0x80016E70: beq         $t1, $zero, L_80016F58
    if (ctx->r9 == 0) {
        // 0x80016E74: nop

            goto L_80016F58;
    }
    // 0x80016E74: nop

    // 0x80016E78: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016E7C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80016E80: nop

    // 0x80016E84: swc1        $f16, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f16.u32l;
    // 0x80016E88: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016E8C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80016E90: nop

    // 0x80016E94: swc1        $f18, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f18.u32l;
    // 0x80016E98: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80016E9C: nop

    // 0x80016EA0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016EA4: beq         $t7, $zero, L_80016EF4
    if (ctx->r15 == 0) {
        // 0x80016EA8: nop

            goto L_80016EF4;
    }
    // 0x80016EA8: nop

    // 0x80016EAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016EB0: lwc1        $f6, 0x6190($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x80016EB4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016EB8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016EBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80016EC0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80016EC4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016EC8: swc1        $f16, 0x1F0($t9)
    MEM_W(0X1F0, ctx->r25) = ctx->f16.u32l;
    // 0x80016ECC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016ED0: lwc1        $f18, 0x6198($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x80016ED4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80016ED8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016EDC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80016EE0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016EE4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80016EE8: nop

    // 0x80016EEC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016EF0: swc1        $f16, 0x1F4($t0)
    MEM_W(0X1F4, ctx->r8) = ctx->f16.u32l;
L_80016EF4:
    // 0x80016EF4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80016EF8: nop

    // 0x80016EFC: andi        $t2, $t8, 0x2
    ctx->r10 = ctx->r24 & 0X2;
    // 0x80016F00: beq         $t2, $zero, L_80016F50
    if (ctx->r10 == 0) {
        // 0x80016F04: nop

            goto L_80016F50;
    }
    // 0x80016F04: nop

    // 0x80016F08: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016F0C: lwc1        $f4, 0x6194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x80016F10: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016F14: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016F18: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80016F1C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80016F20: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80016F24: swc1        $f10, 0x1F8($t3)
    MEM_W(0X1F8, ctx->r11) = ctx->f10.u32l;
    // 0x80016F28: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80016F2C: lwc1        $f16, 0x619C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x80016F30: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016F34: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016F38: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80016F3C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80016F40: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80016F44: nop

    // 0x80016F48: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80016F4C: swc1        $f10, 0x1FC($t1)
    MEM_W(0X1FC, ctx->r9) = ctx->f10.u32l;
L_80016F50:
    // 0x80016F50: b           L_80016F60
    // 0x80016F54: nop

        goto L_80016F60;
    // 0x80016F54: nop

L_80016F58:
    // 0x80016F58: b           L_80016F70
    // 0x80016F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80016F70;
    // 0x80016F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016F60:
    // 0x80016F60: b           L_80016F70
    // 0x80016F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016F70;
    // 0x80016F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016F68: b           L_80016F70
    // 0x80016F6C: nop

        goto L_80016F70;
    // 0x80016F6C: nop

L_80016F70:
    // 0x80016F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016F74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016F78: jr          $ra
    // 0x80016F7C: nop

    return;
    // 0x80016F7C: nop

;}
RECOMP_FUNC void func_80016F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016F80: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80016F84: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80016F88: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80016F8C: lw          $t6, 0x1A8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A8);
    // 0x80016F90: nop

    // 0x80016F94: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016F98: beq         $t7, $zero, L_80017198
    if (ctx->r15 == 0) {
        // 0x80016F9C: nop

            goto L_80017198;
    }
    // 0x80016F9C: nop

    // 0x80016FA0: lw          $t8, 0x1A8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1A8);
    // 0x80016FA4: nop

    // 0x80016FA8: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80016FAC: beq         $t9, $zero, L_80016FBC
    if (ctx->r25 == 0) {
        // 0x80016FB0: nop

            goto L_80016FBC;
    }
    // 0x80016FB0: nop

    // 0x80016FB4: b           L_80017190
    // 0x80016FB8: nop

        goto L_80017190;
    // 0x80016FB8: nop

L_80016FBC:
    // 0x80016FBC: lwc1        $f4, 0x1E8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x80016FC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80016FC4: nop

    // 0x80016FC8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80016FCC: nop

    // 0x80016FD0: bc1f        L_800170A0
    if (!c1cs) {
        // 0x80016FD4: nop

            goto L_800170A0;
    }
    // 0x80016FD4: nop

    // 0x80016FD8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80016FDC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80016FE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80016FE4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80016FE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016FEC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80016FF0: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80016FF4: lwc1        $f4, 0x1E8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x80016FF8: nop

    // 0x80016FFC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80017000: sub.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = ctx->f6.d - ctx->f18.d;
    // 0x80017004: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80017008: swc1        $f8, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f8.u32l;
    // 0x8001700C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80017010: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80017014: lwc1        $f16, 0x1F0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1F0);
    // 0x80017018: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001701C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80017020: lwc1        $f18, 0x6190($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x80017024: nop

    // 0x80017028: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8001702C: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x80017030: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80017034: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80017038: lwc1        $f8, 0x1F4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x8001703C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017040: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80017044: lwc1        $f18, 0x6198($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x80017048: nop

    // 0x8001704C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80017050: swc1        $f6, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f6.u32l;
    // 0x80017054: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80017058: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001705C: lwc1        $f10, 0x1F8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F8);
    // 0x80017060: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017064: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80017068: lwc1        $f18, 0x6194($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x8001706C: nop

    // 0x80017070: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80017074: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
    // 0x80017078: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001707C: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80017080: lwc1        $f6, 0x1FC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1FC);
    // 0x80017084: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017088: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001708C: lwc1        $f18, 0x619C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x80017090: nop

    // 0x80017094: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80017098: b           L_80017190
    // 0x8001709C: swc1        $f16, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f16.u32l;
        goto L_80017190;
    // 0x8001709C: swc1        $f16, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f16.u32l;
L_800170A0:
    // 0x800170A0: lw          $t0, 0x1A8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1A8);
    // 0x800170A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800170A8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800170AC: sw          $t1, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r9;
    // 0x800170B0: lw          $t2, 0x1A8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1A8);
    // 0x800170B4: nop

    // 0x800170B8: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x800170BC: sw          $t3, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r11;
    // 0x800170C0: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800170C4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800170C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800170CC: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800170D0: nop

    // 0x800170D4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800170D8: nop

    // 0x800170DC: bc1f        L_80017158
    if (!c1cs) {
        // 0x800170E0: nop

            goto L_80017158;
    }
    // 0x800170E0: nop

    // 0x800170E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800170E8: lwc1        $f10, 0x61C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800170EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800170F0: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800170F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800170F8: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800170FC: swc1        $f8, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f8.u32l;
    // 0x80017100: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017104: lwc1        $f16, 0x61C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80017108: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001710C: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80017110: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017114: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80017118: swc1        $f6, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f6.u32l;
    // 0x8001711C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017120: lwc1        $f10, 0x61C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80017124: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017128: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8001712C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017130: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80017134: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
    // 0x80017138: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001713C: lwc1        $f16, 0x61D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x80017140: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017144: lwc1        $f4, 0x7230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80017148: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001714C: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80017150: b           L_80017190
    // 0x80017154: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
        goto L_80017190;
    // 0x80017154: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
L_80017158:
    // 0x80017158: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8001715C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017160: lwc1        $f10, 0xCC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x80017164: nop

    // 0x80017168: swc1        $f10, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f10.u32l;
    // 0x8001716C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017170: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x80017174: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80017178: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001717C: lwc1        $f18, 0xD0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x80017180: nop

    // 0x80017184: swc1        $f18, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f18.u32l;
    // 0x80017188: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001718C: swc1        $f18, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f18.u32l;
L_80017190:
    // 0x80017190: b           L_800171BC
    // 0x80017194: nop

        goto L_800171BC;
    // 0x80017194: nop

L_80017198:
    // 0x80017198: lw          $t7, 0x1A8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1A8);
    // 0x8001719C: nop

    // 0x800171A0: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800171A4: beq         $t8, $zero, L_800171BC
    if (ctx->r24 == 0) {
        // 0x800171A8: nop

            goto L_800171BC;
    }
    // 0x800171A8: nop

    // 0x800171AC: lw          $t9, 0x1A8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1A8);
    // 0x800171B0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800171B4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800171B8: sw          $t0, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r8;
L_800171BC:
    // 0x800171BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800171C0: lwc1        $f8, 0x6190($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800171C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800171C8: lwc1        $f16, 0x61C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800171CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800171D0: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800171D4: nop

    // 0x800171D8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800171DC: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800171E0: nop

    // 0x800171E4: bc1f        L_80017208
    if (!c1cs) {
        // 0x800171E8: nop

            goto L_80017208;
    }
    // 0x800171E8: nop

    // 0x800171EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800171F0: lwc1        $f10, 0x61C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800171F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800171F8: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800171FC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017200: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80017204: swc1        $f16, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f16.u32l;
L_80017208:
    // 0x80017208: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001720C: lwc1        $f4, 0x6194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x80017210: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017214: lwc1        $f8, 0x61C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80017218: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001721C: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80017220: nop

    // 0x80017224: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80017228: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8001722C: nop

    // 0x80017230: bc1f        L_80017254
    if (!c1cs) {
        // 0x80017234: nop

            goto L_80017254;
    }
    // 0x80017234: nop

    // 0x80017238: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001723C: lwc1        $f18, 0x61C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80017240: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017244: lwc1        $f16, 0x7230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80017248: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001724C: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80017250: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
L_80017254:
    // 0x80017254: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017258: lwc1        $f6, 0x6198($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x8001725C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017260: lwc1        $f4, 0x61C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80017264: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017268: lwc1        $f10, 0x7224($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x8001726C: nop

    // 0x80017270: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017274: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80017278: nop

    // 0x8001727C: bc1f        L_800172A0
    if (!c1cs) {
        // 0x80017280: nop

            goto L_800172A0;
    }
    // 0x80017280: nop

    // 0x80017284: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017288: lwc1        $f16, 0x61C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8001728C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80017290: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80017294: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017298: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8001729C: swc1        $f4, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f4.u32l;
L_800172A0:
    // 0x800172A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172A4: lwc1        $f10, 0x619C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800172A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172AC: lwc1        $f6, 0x61D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800172B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800172B4: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800172B8: nop

    // 0x800172BC: sub.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800172C0: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800172C4: nop

    // 0x800172C8: bc1f        L_800172EC
    if (!c1cs) {
        // 0x800172CC: nop

            goto L_800172EC;
    }
    // 0x800172CC: nop

    // 0x800172D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172D4: lwc1        $f8, 0x61D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800172D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800172DC: lwc1        $f4, 0x7230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800172E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172E4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800172E8: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
L_800172EC:
    // 0x800172EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800172F0: lwc1        $f18, 0x6190($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800172F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800172F8: nop

    // 0x800172FC: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80017300: nop

    // 0x80017304: bc1f        L_80017318
    if (!c1cs) {
        // 0x80017308: nop

            goto L_80017318;
    }
    // 0x80017308: nop

    // 0x8001730C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80017310: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017314: swc1        $f16, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f16.u32l;
L_80017318:
    // 0x80017318: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001731C: lwc1        $f8, 0x6198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x80017320: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017324: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017328: nop

    // 0x8001732C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80017330: nop

    // 0x80017334: bc1f        L_8001734C
    if (!c1cs) {
        // 0x80017338: nop

            goto L_8001734C;
    }
    // 0x80017338: nop

    // 0x8001733C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017344: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017348: swc1        $f6, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f6.u32l;
L_8001734C:
    // 0x8001734C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017350: lwc1        $f18, 0x6194($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x80017354: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80017358: nop

    // 0x8001735C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80017360: nop

    // 0x80017364: bc1f        L_80017378
    if (!c1cs) {
        // 0x80017368: nop

            goto L_80017378;
    }
    // 0x80017368: nop

    // 0x8001736C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80017370: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017374: swc1        $f16, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f16.u32l;
L_80017378:
    // 0x80017378: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001737C: lwc1        $f8, 0x619C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x80017380: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017388: nop

    // 0x8001738C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80017390: nop

    // 0x80017394: bc1f        L_800173AC
    if (!c1cs) {
        // 0x80017398: nop

            goto L_800173AC;
    }
    // 0x80017398: nop

    // 0x8001739C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800173A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800173A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800173A8: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
L_800173AC:
    // 0x800173AC: b           L_800173BC
    // 0x800173B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800173BC;
    // 0x800173B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800173B4: b           L_800173BC
    // 0x800173B8: nop

        goto L_800173BC;
    // 0x800173B8: nop

L_800173BC:
    // 0x800173BC: jr          $ra
    // 0x800173C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800173C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800173C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800173C4: nop

    // 0x800173C8: nop

    // 0x800173CC: nop

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
RECOMP_FUNC void func_80017438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017438: jr          $ra
    // 0x8001743C: nop

    return;
    // 0x8001743C: nop

    // 0x80017440: jr          $ra
    // 0x80017444: nop

    return;
    // 0x80017444: nop

;}
RECOMP_FUNC void func_80017448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017448: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001744C: lw          $t6, 0x1A8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A8);
    // 0x80017450: nop

    // 0x80017454: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80017458: beq         $t7, $zero, L_8001778C
    if (ctx->r15 == 0) {
        // 0x8001745C: nop

            goto L_8001778C;
    }
    // 0x8001745C: nop

    // 0x80017460: lw          $t8, 0x1A8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1A8);
    // 0x80017464: nop

    // 0x80017468: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8001746C: beq         $t9, $zero, L_8001747C
    if (ctx->r25 == 0) {
        // 0x80017470: nop

            goto L_8001747C;
    }
    // 0x80017470: nop

    // 0x80017474: b           L_80017784
    // 0x80017478: nop

        goto L_80017784;
    // 0x80017478: nop

L_8001747C:
    // 0x8001747C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80017480: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80017484: lwc1        $f4, 0x1EC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80017488: lwc1        $f10, 0x1E8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x8001748C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80017490: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80017494: swc1        $f16, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f16.u32l;
    // 0x80017498: lwc1        $f18, 0x1EC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x8001749C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800174A0: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800174A4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800174A8: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800174AC: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800174B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800174B4: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800174B8: lwc1        $f8, 0x1EC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x800174BC: nop

    // 0x800174C0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800174C4: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x800174C8: lwc1        $f4, 0x1E8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x800174CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800174D0: nop

    // 0x800174D4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800174D8: nop

    // 0x800174DC: bc1f        L_8001769C
    if (!c1cs) {
        // 0x800174E0: nop

            goto L_8001769C;
    }
    // 0x800174E0: nop

    // 0x800174E4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800174E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800174EC: lwc1        $f10, 0x1E8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x800174F0: nop

    // 0x800174F4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800174F8: nop

    // 0x800174FC: bc1f        L_8001769C
    if (!c1cs) {
        // 0x80017500: nop

            goto L_8001769C;
    }
    // 0x80017500: nop

    // 0x80017504: lw          $t0, 0x20C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X20C);
    // 0x80017508: nop

    // 0x8001750C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x80017510: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80017514: nop

    // 0x80017518: beq         $t1, $zero, L_800175C4
    if (ctx->r9 == 0) {
        // 0x8001751C: nop

            goto L_800175C4;
    }
    // 0x8001751C: nop

L_80017520:
    // 0x80017520: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80017524: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80017528: lh          $t3, 0x11E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X11E);
    // 0x8001752C: nop

    // 0x80017530: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80017534: nop

    // 0x80017538: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001753C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80017540: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80017544: nop

    // 0x80017548: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8001754C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80017550: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80017554: nop

    // 0x80017558: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001755C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80017560: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80017564: sh          $t5, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r13;
    // 0x80017568: nop

    // 0x8001756C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80017570: nop

    // 0x80017574: lh          $t7, 0x11E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X11E);
    // 0x80017578: nop

    // 0x8001757C: bgez        $t7, L_80017590
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80017580: nop

            goto L_80017590;
    }
    // 0x80017580: nop

    // 0x80017584: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80017588: nop

    // 0x8001758C: sh          $zero, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = 0;
L_80017590:
    // 0x80017590: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x80017594: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80017598: lw          $t1, -0x5A50($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5A50);
    // 0x8001759C: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800175A0: nop

    // 0x800175A4: or          $t3, $t0, $t1
    ctx->r11 = ctx->r8 | ctx->r9;
    // 0x800175A8: sw          $t3, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r11;
    // 0x800175AC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800175B0: nop

    // 0x800175B4: lw          $t5, 0x150($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X150);
    // 0x800175B8: nop

    // 0x800175BC: bne         $t5, $zero, L_80017520
    if (ctx->r13 != 0) {
        // 0x800175C0: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_80017520;
    }
    // 0x800175C0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_800175C4:
    // 0x800175C4: lw          $t2, 0x210($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X210);
    // 0x800175C8: nop

    // 0x800175CC: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x800175D0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800175D4: nop

    // 0x800175D8: beq         $t6, $zero, L_80017694
    if (ctx->r14 == 0) {
        // 0x800175DC: nop

            goto L_80017694;
    }
    // 0x800175DC: nop

L_800175E0:
    // 0x800175E0: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800175E4: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800175E8: lh          $t8, 0x11E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X11E);
    // 0x800175EC: nop

    // 0x800175F0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800175F4: nop

    // 0x800175F8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800175FC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80017600: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80017604: nop

    // 0x80017608: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8001760C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80017610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80017614: nop

    // 0x80017618: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001761C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80017620: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80017624: sh          $t1, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r9;
    // 0x80017628: nop

    // 0x8001762C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x80017630: nop

    // 0x80017634: lh          $t9, 0x11E($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X11E);
    // 0x80017638: lh          $t4, 0x120($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X120);
    // 0x8001763C: nop

    // 0x80017640: slt         $at, $t4, $t9
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80017644: beq         $at, $zero, L_80017660
    if (ctx->r1 == 0) {
        // 0x80017648: nop

            goto L_80017660;
    }
    // 0x80017648: nop

    // 0x8001764C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80017650: nop

    // 0x80017654: lh          $t2, 0x120($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X120);
    // 0x80017658: nop

    // 0x8001765C: sh          $t2, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r10;
L_80017660:
    // 0x80017660: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80017664: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80017668: lw          $t0, -0x5A50($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5A50);
    // 0x8001766C: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x80017670: nop

    // 0x80017674: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80017678: sw          $t1, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r9;
    // 0x8001767C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80017680: nop

    // 0x80017684: lw          $t3, 0x150($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X150);
    // 0x80017688: nop

    // 0x8001768C: bne         $t3, $zero, L_800175E0
    if (ctx->r11 != 0) {
        // 0x80017690: sw          $t3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r11;
            goto L_800175E0;
    }
    // 0x80017690: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
L_80017694:
    // 0x80017694: b           L_80017784
    // 0x80017698: nop

        goto L_80017784;
    // 0x80017698: nop

L_8001769C:
    // 0x8001769C: lw          $t9, 0x1A8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1A8);
    // 0x800176A0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800176A4: and         $t4, $t9, $at
    ctx->r12 = ctx->r25 & ctx->r1;
    // 0x800176A8: sw          $t4, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r12;
    // 0x800176AC: lw          $t2, 0x1A8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1A8);
    // 0x800176B0: nop

    // 0x800176B4: ori         $t5, $t2, 0x2
    ctx->r13 = ctx->r10 | 0X2;
    // 0x800176B8: sw          $t5, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r13;
    // 0x800176BC: lw          $t8, 0x20C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20C);
    // 0x800176C0: nop

    // 0x800176C4: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800176C8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800176CC: nop

    // 0x800176D0: beq         $t0, $zero, L_8001771C
    if (ctx->r8 == 0) {
        // 0x800176D4: nop

            goto L_8001771C;
    }
    // 0x800176D4: nop

L_800176D8:
    // 0x800176D8: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800176DC: nop

    // 0x800176E0: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x800176E4: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800176E8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800176EC: lw          $t3, -0x5A50($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5A50);
    // 0x800176F0: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800176F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800176F8: xor         $t9, $t3, $at
    ctx->r25 = ctx->r11 ^ ctx->r1;
    // 0x800176FC: and         $t4, $t7, $t9
    ctx->r12 = ctx->r15 & ctx->r25;
    // 0x80017700: sw          $t4, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r12;
    // 0x80017704: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80017708: nop

    // 0x8001770C: lw          $t5, 0x150($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X150);
    // 0x80017710: nop

    // 0x80017714: bne         $t5, $zero, L_800176D8
    if (ctx->r13 != 0) {
        // 0x80017718: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800176D8;
    }
    // 0x80017718: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_8001771C:
    // 0x8001771C: lw          $t8, 0x210($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X210);
    // 0x80017720: nop

    // 0x80017724: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x80017728: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8001772C: nop

    // 0x80017730: beq         $t0, $zero, L_80017784
    if (ctx->r8 == 0) {
        // 0x80017734: nop

            goto L_80017784;
    }
    // 0x80017734: nop

L_80017738:
    // 0x80017738: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8001773C: nop

    // 0x80017740: lh          $t3, 0x120($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X120);
    // 0x80017744: nop

    // 0x80017748: sh          $t3, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r11;
    // 0x8001774C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80017750: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80017754: lw          $t4, -0x5A50($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5A50);
    // 0x80017758: lw          $t9, 0xC0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC0);
    // 0x8001775C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80017760: xor         $t6, $t4, $at
    ctx->r14 = ctx->r12 ^ ctx->r1;
    // 0x80017764: and         $t2, $t9, $t6
    ctx->r10 = ctx->r25 & ctx->r14;
    // 0x80017768: sw          $t2, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r10;
    // 0x8001776C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80017770: nop

    // 0x80017774: lw          $t8, 0x150($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X150);
    // 0x80017778: nop

    // 0x8001777C: bne         $t8, $zero, L_80017738
    if (ctx->r24 != 0) {
        // 0x80017780: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_80017738;
    }
    // 0x80017780: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_80017784:
    // 0x80017784: b           L_800177C0
    // 0x80017788: nop

        goto L_800177C0;
    // 0x80017788: nop

L_8001778C:
    // 0x8001778C: lw          $t0, 0x1A8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1A8);
    // 0x80017790: nop

    // 0x80017794: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x80017798: beq         $t3, $zero, L_800177C0
    if (ctx->r11 == 0) {
        // 0x8001779C: nop

            goto L_800177C0;
    }
    // 0x8001779C: nop

    // 0x800177A0: lw          $t1, 0x1A8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1A8);
    // 0x800177A4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800177A8: and         $t4, $t1, $at
    ctx->r12 = ctx->r9 & ctx->r1;
    // 0x800177AC: sw          $t4, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r12;
    // 0x800177B0: sw          $zero, 0x210($a0)
    MEM_W(0X210, ctx->r4) = 0;
    // 0x800177B4: lw          $t9, 0x210($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X210);
    // 0x800177B8: nop

    // 0x800177BC: sw          $t9, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->r25;
L_800177C0:
    // 0x800177C0: b           L_800177D0
    // 0x800177C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800177D0;
    // 0x800177C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800177C8: b           L_800177D0
    // 0x800177CC: nop

        goto L_800177D0;
    // 0x800177CC: nop

L_800177D0:
    // 0x800177D0: jr          $ra
    // 0x800177D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800177D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800177D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800177D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800177DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800177E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800177E4: jal         0x80016074
    // 0x800177E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800177E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800177EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800177F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800177F4: nop

    // 0x800177F8: bne         $t6, $zero, L_80017808
    if (ctx->r14 != 0) {
        // 0x800177FC: nop

            goto L_80017808;
    }
    // 0x800177FC: nop

    // 0x80017800: b           L_800178C4
    // 0x80017804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800178C4;
    // 0x80017804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017808:
    // 0x80017808: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8001780C: nop

    // 0x80017810: sw          $zero, 0x150($t7)
    MEM_W(0X150, ctx->r15) = 0;
    // 0x80017814: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80017818: nop

    // 0x8001781C: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80017820: nop

    // 0x80017824: bne         $t9, $zero, L_8001783C
    if (ctx->r25 != 0) {
        // 0x80017828: nop

            goto L_8001783C;
    }
    // 0x80017828: nop

    // 0x8001782C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80017830: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80017834: b           L_800178B4
    // 0x80017838: sw          $t0, 0x20C($t1)
    MEM_W(0X20C, ctx->r9) = ctx->r8;
        goto L_800178B4;
    // 0x80017838: sw          $t0, 0x20C($t1)
    MEM_W(0X20C, ctx->r9) = ctx->r8;
L_8001783C:
    // 0x8001783C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80017840: nop

    // 0x80017844: lw          $t3, 0x20C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20C);
    // 0x80017848: nop

    // 0x8001784C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80017850: lw          $t4, 0x150($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X150);
    // 0x80017854: nop

    // 0x80017858: beq         $t4, $zero, L_800178A4
    if (ctx->r12 == 0) {
        // 0x8001785C: nop

            goto L_800178A4;
    }
    // 0x8001785C: nop

L_80017860:
    // 0x80017860: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80017864: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80017868: lw          $t6, 0x150($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X150);
    // 0x8001786C: nop

    // 0x80017870: bne         $t6, $t7, L_80017880
    if (ctx->r14 != ctx->r15) {
        // 0x80017874: nop

            goto L_80017880;
    }
    // 0x80017874: nop

    // 0x80017878: b           L_800178C4
    // 0x8001787C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800178C4;
    // 0x8001787C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80017880:
    // 0x80017880: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80017884: nop

    // 0x80017888: lw          $t9, 0x150($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X150);
    // 0x8001788C: nop

    // 0x80017890: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80017894: lw          $t0, 0x150($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X150);
    // 0x80017898: nop

    // 0x8001789C: bne         $t0, $zero, L_80017860
    if (ctx->r8 != 0) {
        // 0x800178A0: nop

            goto L_80017860;
    }
    // 0x800178A0: nop

L_800178A4:
    // 0x800178A4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800178A8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800178AC: nop

    // 0x800178B0: sw          $t1, 0x150($t2)
    MEM_W(0X150, ctx->r10) = ctx->r9;
L_800178B4:
    // 0x800178B4: b           L_800178C4
    // 0x800178B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800178C4;
    // 0x800178B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800178BC: b           L_800178C4
    // 0x800178C0: nop

        goto L_800178C4;
    // 0x800178C0: nop

L_800178C4:
    // 0x800178C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800178C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800178CC: jr          $ra
    // 0x800178D0: nop

    return;
    // 0x800178D0: nop

;}
RECOMP_FUNC void func_800178D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800178D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800178D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800178DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800178E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800178E4: jal         0x80016074
    // 0x800178E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800178E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800178EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800178F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800178F4: nop

    // 0x800178F8: bne         $t6, $zero, L_80017908
    if (ctx->r14 != 0) {
        // 0x800178FC: nop

            goto L_80017908;
    }
    // 0x800178FC: nop

    // 0x80017900: b           L_80017A10
    // 0x80017904: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80017A10;
    // 0x80017904: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017908:
    // 0x80017908: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8001790C: nop

    // 0x80017910: sw          $zero, 0x150($t7)
    MEM_W(0X150, ctx->r15) = 0;
    // 0x80017914: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80017918: nop

    // 0x8001791C: bgez        $t8, L_80017928
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80017920: nop

            goto L_80017928;
    }
    // 0x80017920: nop

    // 0x80017924: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
L_80017928:
    // 0x80017928: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8001792C: nop

    // 0x80017930: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80017934: bne         $at, $zero, L_80017944
    if (ctx->r1 != 0) {
        // 0x80017938: nop

            goto L_80017944;
    }
    // 0x80017938: nop

    // 0x8001793C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80017940: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
L_80017944:
    // 0x80017944: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80017948: nop

    // 0x8001794C: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x80017950: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x80017954: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80017958: nop

    // 0x8001795C: sh          $t2, 0x120($t3)
    MEM_H(0X120, ctx->r11) = ctx->r10;
    // 0x80017960: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80017964: nop

    // 0x80017968: lw          $t5, 0x210($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X210);
    // 0x8001796C: nop

    // 0x80017970: bne         $t5, $zero, L_80017988
    if (ctx->r13 != 0) {
        // 0x80017974: nop

            goto L_80017988;
    }
    // 0x80017974: nop

    // 0x80017978: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001797C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80017980: b           L_80017A00
    // 0x80017984: sw          $t6, 0x210($t7)
    MEM_W(0X210, ctx->r15) = ctx->r14;
        goto L_80017A00;
    // 0x80017984: sw          $t6, 0x210($t7)
    MEM_W(0X210, ctx->r15) = ctx->r14;
L_80017988:
    // 0x80017988: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001798C: nop

    // 0x80017990: lw          $t9, 0x210($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X210);
    // 0x80017994: nop

    // 0x80017998: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8001799C: lw          $t0, 0x150($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X150);
    // 0x800179A0: nop

    // 0x800179A4: beq         $t0, $zero, L_800179F0
    if (ctx->r8 == 0) {
        // 0x800179A8: nop

            goto L_800179F0;
    }
    // 0x800179A8: nop

L_800179AC:
    // 0x800179AC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800179B0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800179B4: lw          $t2, 0x150($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X150);
    // 0x800179B8: nop

    // 0x800179BC: bne         $t2, $t3, L_800179CC
    if (ctx->r10 != ctx->r11) {
        // 0x800179C0: nop

            goto L_800179CC;
    }
    // 0x800179C0: nop

    // 0x800179C4: b           L_80017A10
    // 0x800179C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80017A10;
    // 0x800179C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800179CC:
    // 0x800179CC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800179D0: nop

    // 0x800179D4: lw          $t5, 0x150($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X150);
    // 0x800179D8: nop

    // 0x800179DC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800179E0: lw          $t6, 0x150($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X150);
    // 0x800179E4: nop

    // 0x800179E8: bne         $t6, $zero, L_800179AC
    if (ctx->r14 != 0) {
        // 0x800179EC: nop

            goto L_800179AC;
    }
    // 0x800179EC: nop

L_800179F0:
    // 0x800179F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800179F4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800179F8: nop

    // 0x800179FC: sw          $t7, 0x150($t8)
    MEM_W(0X150, ctx->r24) = ctx->r15;
L_80017A00:
    // 0x80017A00: b           L_80017A10
    // 0x80017A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017A10;
    // 0x80017A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017A08: b           L_80017A10
    // 0x80017A0C: nop

        goto L_80017A10;
    // 0x80017A0C: nop

L_80017A10:
    // 0x80017A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017A14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017A18: jr          $ra
    // 0x80017A1C: nop

    return;
    // 0x80017A1C: nop

;}
RECOMP_FUNC void func_80017A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80017A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017A28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80017A2C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80017A30: jal         0x80016074
    // 0x80017A34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80017A34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x80017A38: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80017A3C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A40: nop

    // 0x80017A44: bne         $t6, $zero, L_80017A54
    if (ctx->r14 != 0) {
        // 0x80017A48: nop

            goto L_80017A54;
    }
    // 0x80017A48: nop

    // 0x80017A4C: b           L_80017AEC
    // 0x80017A50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80017AEC;
    // 0x80017A50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017A54:
    // 0x80017A54: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A58: nop

    // 0x80017A5C: lw          $t8, 0x210($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X210);
    // 0x80017A60: lw          $t9, 0x20C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X20C);
    // 0x80017A64: nop

    // 0x80017A68: bne         $t8, $t9, L_80017A80
    if (ctx->r24 != ctx->r25) {
        // 0x80017A6C: nop

            goto L_80017A80;
    }
    // 0x80017A6C: nop

    // 0x80017A70: bne         $t9, $zero, L_80017A80
    if (ctx->r25 != 0) {
        // 0x80017A74: nop

            goto L_80017A80;
    }
    // 0x80017A74: nop

    // 0x80017A78: b           L_80017AEC
    // 0x80017A7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80017AEC;
    // 0x80017A7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017A80:
    // 0x80017A80: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A84: nop

    // 0x80017A88: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x80017A8C: nop

    // 0x80017A90: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80017A94: sw          $t2, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r10;
    // 0x80017A98: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80017A9C: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x80017AA0: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x80017AA4: nop

    // 0x80017AA8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80017AAC: sw          $t5, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = ctx->r13;
    // 0x80017AB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017AB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80017AB8: nop

    // 0x80017ABC: swc1        $f4, 0x1E8($t6)
    MEM_W(0X1E8, ctx->r14) = ctx->f4.u32l;
    // 0x80017AC0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80017AC4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80017AC8: nop

    // 0x80017ACC: swc1        $f6, 0x1EC($t7)
    MEM_W(0X1EC, ctx->r15) = ctx->f6.u32l;
    // 0x80017AD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80017AD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017AD8: sw          $t8, -0x5A50($at)
    MEM_W(-0X5A50, ctx->r1) = ctx->r24;
    // 0x80017ADC: b           L_80017AEC
    // 0x80017AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017AEC;
    // 0x80017AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017AE4: b           L_80017AEC
    // 0x80017AE8: nop

        goto L_80017AEC;
    // 0x80017AE8: nop

L_80017AEC:
    // 0x80017AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017AF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017AF4: jr          $ra
    // 0x80017AF8: nop

    return;
    // 0x80017AF8: nop

    // 0x80017AFC: nop

;}
