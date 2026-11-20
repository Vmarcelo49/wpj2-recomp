#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8009230C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009230C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80092310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092314: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80092318: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8009231C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80092320: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80092324: nop

    // 0x80092328: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x8009232C: bne         $t7, $zero, L_8009288C
    if (ctx->r15 != 0) {
        // 0x80092330: nop

            goto L_8009288C;
    }
    // 0x80092330: nop

    // 0x80092334: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80092338:
    // 0x80092338: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8009233C: lw          $t8, 0x6BA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6BA0);
    // 0x80092340: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80092344: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80092348: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009234C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80092350: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092354: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80092358: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009235C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092360: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80092364: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80092368: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009236C: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x80092370: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80092374: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80092378: lw          $t1, 0x6C14($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6C14);
    // 0x8009237C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80092380: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80092384: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80092388: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009238C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80092390: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80092394: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80092398: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8009239C: nop

    // 0x800923A0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800923A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800923A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800923AC: nop

    // 0x800923B0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800923B4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800923B8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800923BC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800923C0: nop

    // 0x800923C4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800923C8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800923CC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800923D0: lw          $t9, -0x78C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X78C);
    // 0x800923D4: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x800923D8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800923DC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800923E0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800923E4: lbu         $t1, -0x400($t0)
    ctx->r9 = MEM_BU(ctx->r8, -0X400);
    // 0x800923E8: nop

    // 0x800923EC: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x800923F0: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x800923F4: nop

    // 0x800923F8: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x800923FC: beq         $t3, $zero, L_8009242C
    if (ctx->r11 == 0) {
        // 0x80092400: nop

            goto L_8009242C;
    }
    // 0x80092400: nop

    // 0x80092404: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092408: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009240C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092410: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092414: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092418: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009241C: jal         0x80090784
    // 0x80092420: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x80092420: nop

    after_0:
    // 0x80092424: b           L_8009244C
    // 0x80092428: nop

        goto L_8009244C;
    // 0x80092428: nop

L_8009242C:
    // 0x8009242C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092430: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092434: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092438: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009243C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092440: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092444: jal         0x80090784
    // 0x80092448: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80092448: nop

    after_1:
L_8009244C:
    // 0x8009244C: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x80092450: nop

    // 0x80092454: andi        $t6, $t4, 0x40
    ctx->r14 = ctx->r12 & 0X40;
    // 0x80092458: beq         $t6, $zero, L_80092488
    if (ctx->r14 == 0) {
        // 0x8009245C: nop

            goto L_80092488;
    }
    // 0x8009245C: nop

    // 0x80092460: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092464: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092468: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009246C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092470: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092474: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092478: jal         0x80090784
    // 0x8009247C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x8009247C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x80092480: b           L_800924A8
    // 0x80092484: nop

        goto L_800924A8;
    // 0x80092484: nop

L_80092488:
    // 0x80092488: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009248C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092490: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092494: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092498: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009249C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800924A0: jal         0x80090784
    // 0x800924A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x800924A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_800924A8:
    // 0x800924A8: lbu         $t5, 0x27($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X27);
    // 0x800924AC: nop

    // 0x800924B0: andi        $t7, $t5, 0x20
    ctx->r15 = ctx->r13 & 0X20;
    // 0x800924B4: beq         $t7, $zero, L_800924E4
    if (ctx->r15 == 0) {
        // 0x800924B8: nop

            goto L_800924E4;
    }
    // 0x800924B8: nop

    // 0x800924BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800924C0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800924C4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800924C8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800924CC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800924D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800924D4: jal         0x80090784
    // 0x800924D8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x800924D8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x800924DC: b           L_80092504
    // 0x800924E0: nop

        goto L_80092504;
    // 0x800924E0: nop

L_800924E4:
    // 0x800924E4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800924E8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800924EC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800924F0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800924F4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800924F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800924FC: jal         0x80090784
    // 0x80092500: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x80092500: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80092504:
    // 0x80092504: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x80092508: nop

    // 0x8009250C: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x80092510: beq         $t9, $zero, L_80092540
    if (ctx->r25 == 0) {
        // 0x80092514: nop

            goto L_80092540;
    }
    // 0x80092514: nop

    // 0x80092518: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009251C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092520: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092524: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092528: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009252C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092530: jal         0x80090784
    // 0x80092534: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80092534: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80092538: b           L_80092560
    // 0x8009253C: nop

        goto L_80092560;
    // 0x8009253C: nop

L_80092540:
    // 0x80092540: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092544: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092548: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009254C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092550: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092554: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092558: jal         0x80090784
    // 0x8009255C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x8009255C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_80092560:
    // 0x80092560: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80092564: nop

    // 0x80092568: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x8009256C: beq         $t1, $zero, L_8009259C
    if (ctx->r9 == 0) {
        // 0x80092570: nop

            goto L_8009259C;
    }
    // 0x80092570: nop

    // 0x80092574: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092578: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009257C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092580: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092584: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092588: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009258C: jal         0x80090784
    // 0x80092590: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x80092590: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x80092594: b           L_800925BC
    // 0x80092598: nop

        goto L_800925BC;
    // 0x80092598: nop

L_8009259C:
    // 0x8009259C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800925A0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800925A4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800925A8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800925AC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800925B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800925B4: jal         0x80090784
    // 0x800925B8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x800925B8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_800925BC:
    // 0x800925BC: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x800925C0: nop

    // 0x800925C4: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800925C8: beq         $t3, $zero, L_800925F8
    if (ctx->r11 == 0) {
        // 0x800925CC: nop

            goto L_800925F8;
    }
    // 0x800925CC: nop

    // 0x800925D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800925D4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800925D8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800925DC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800925E0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800925E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800925E8: jal         0x80090784
    // 0x800925EC: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x800925EC: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x800925F0: b           L_80092618
    // 0x800925F4: nop

        goto L_80092618;
    // 0x800925F4: nop

L_800925F8:
    // 0x800925F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800925FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092600: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092604: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092608: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009260C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092610: jal         0x80090784
    // 0x80092614: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80092614: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80092618:
    // 0x80092618: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x8009261C: nop

    // 0x80092620: andi        $t6, $t4, 0x2
    ctx->r14 = ctx->r12 & 0X2;
    // 0x80092624: beq         $t6, $zero, L_80092654
    if (ctx->r14 == 0) {
        // 0x80092628: nop

            goto L_80092654;
    }
    // 0x80092628: nop

    // 0x8009262C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092630: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092634: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092638: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009263C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092640: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092644: jal         0x80090784
    // 0x80092648: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80092648: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x8009264C: b           L_80092674
    // 0x80092650: nop

        goto L_80092674;
    // 0x80092650: nop

L_80092654:
    // 0x80092654: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092658: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009265C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092660: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092664: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092668: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009266C: jal         0x80090784
    // 0x80092670: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x80092670: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_80092674:
    // 0x80092674: lbu         $t5, 0x27($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X27);
    // 0x80092678: nop

    // 0x8009267C: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80092680: beq         $t7, $zero, L_800926B0
    if (ctx->r15 == 0) {
        // 0x80092684: nop

            goto L_800926B0;
    }
    // 0x80092684: nop

    // 0x80092688: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009268C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092690: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092694: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092698: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009269C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800926A0: jal         0x80090784
    // 0x800926A4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x800926A4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x800926A8: b           L_800926D0
    // 0x800926AC: nop

        goto L_800926D0;
    // 0x800926AC: nop

L_800926B0:
    // 0x800926B0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800926B4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800926B8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800926BC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800926C0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800926C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800926C8: jal         0x80090784
    // 0x800926CC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x800926CC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_800926D0:
    // 0x800926D0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800926D4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800926D8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800926DC: lw          $t3, -0x78C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X78C);
    // 0x800926E0: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800926E4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800926E8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800926EC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800926F0: lbu         $t6, -0x3FF($t4)
    ctx->r14 = MEM_BU(ctx->r12, -0X3FF);
    // 0x800926F4: nop

    // 0x800926F8: sb          $t6, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r14;
    // 0x800926FC: lbu         $t5, 0x27($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X27);
    // 0x80092700: nop

    // 0x80092704: andi        $t7, $t5, 0x80
    ctx->r15 = ctx->r13 & 0X80;
    // 0x80092708: beq         $t7, $zero, L_80092738
    if (ctx->r15 == 0) {
        // 0x8009270C: nop

            goto L_80092738;
    }
    // 0x8009270C: nop

    // 0x80092710: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092714: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092718: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009271C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092720: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092724: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092728: jal         0x80090784
    // 0x8009272C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_16;
    // 0x8009272C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_16:
    // 0x80092730: b           L_80092758
    // 0x80092734: nop

        goto L_80092758;
    // 0x80092734: nop

L_80092738:
    // 0x80092738: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009273C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092740: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092744: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092748: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009274C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092750: jal         0x80090784
    // 0x80092754: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_17;
    // 0x80092754: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_17:
L_80092758:
    // 0x80092758: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x8009275C: nop

    // 0x80092760: andi        $t0, $t8, 0x40
    ctx->r8 = ctx->r24 & 0X40;
    // 0x80092764: beq         $t0, $zero, L_80092794
    if (ctx->r8 == 0) {
        // 0x80092768: nop

            goto L_80092794;
    }
    // 0x80092768: nop

    // 0x8009276C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092770: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092774: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092778: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009277C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092780: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092784: jal         0x80090784
    // 0x80092788: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_18;
    // 0x80092788: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_18:
    // 0x8009278C: b           L_800927B4
    // 0x80092790: nop

        goto L_800927B4;
    // 0x80092790: nop

L_80092794:
    // 0x80092794: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092798: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009279C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800927A0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800927A4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800927A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800927AC: jal         0x80090784
    // 0x800927B0: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_19;
    // 0x800927B0: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_19:
L_800927B4:
    // 0x800927B4: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x800927B8: nop

    // 0x800927BC: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x800927C0: beq         $t1, $zero, L_800927F0
    if (ctx->r9 == 0) {
        // 0x800927C4: nop

            goto L_800927F0;
    }
    // 0x800927C4: nop

    // 0x800927C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800927CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800927D0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800927D4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800927D8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800927DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800927E0: jal         0x80090784
    // 0x800927E4: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_20;
    // 0x800927E4: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_20:
    // 0x800927E8: b           L_80092810
    // 0x800927EC: nop

        goto L_80092810;
    // 0x800927EC: nop

L_800927F0:
    // 0x800927F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800927F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800927F8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800927FC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092800: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092804: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092808: jal         0x80090784
    // 0x8009280C: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_21;
    // 0x8009280C: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_21:
L_80092810:
    // 0x80092810: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x80092814: nop

    // 0x80092818: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x8009281C: beq         $t3, $zero, L_8009284C
    if (ctx->r11 == 0) {
        // 0x80092820: nop

            goto L_8009284C;
    }
    // 0x80092820: nop

    // 0x80092824: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092828: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009282C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092830: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092834: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092838: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009283C: jal         0x80090784
    // 0x80092840: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_22;
    // 0x80092840: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_22:
    // 0x80092844: b           L_8009286C
    // 0x80092848: nop

        goto L_8009286C;
    // 0x80092848: nop

L_8009284C:
    // 0x8009284C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092850: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092854: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092858: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009285C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092860: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092864: jal         0x80090784
    // 0x80092868: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_23;
    // 0x80092868: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_23:
L_8009286C:
    // 0x8009286C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80092870: nop

    // 0x80092874: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80092878: slti        $at, $t6, 0xC
    ctx->r1 = SIGNED(ctx->r14) < 0XC ? 1 : 0;
    // 0x8009287C: bne         $at, $zero, L_80092338
    if (ctx->r1 != 0) {
        // 0x80092880: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_80092338;
    }
    // 0x80092880: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80092884: b           L_80093B00
    // 0x80092888: nop

        goto L_80093B00;
    // 0x80092888: nop

L_8009288C:
    // 0x8009288C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80092890:
    // 0x80092890: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80092894: lw          $t5, 0x6BA0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6BA0);
    // 0x80092898: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8009289C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800928A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800928A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800928A8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800928AC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800928B0: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800928B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800928B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800928BC: lwc1        $f8, -0x4510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x800928C0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800928C4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800928C8: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x800928CC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800928D0: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800928D4: lw          $t9, 0x6C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C14);
    // 0x800928D8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800928DC: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800928E0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800928E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800928E8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800928EC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800928F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800928F4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800928F8: nop

    // 0x800928FC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80092900: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80092904: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80092908: nop

    // 0x8009290C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80092910: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80092914: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80092918: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8009291C: nop

    // 0x80092920: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80092924: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80092928: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8009292C: lw          $t8, -0x78C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X78C);
    // 0x80092930: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80092934: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x80092938: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8009293C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80092940: lbu         $t9, -0x400($t0)
    ctx->r25 = MEM_BU(ctx->r8, -0X400);
    // 0x80092944: nop

    // 0x80092948: sb          $t9, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r25;
    // 0x8009294C: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x80092950: nop

    // 0x80092954: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80092958: beq         $t2, $zero, L_80092A14
    if (ctx->r10 == 0) {
        // 0x8009295C: nop

            goto L_80092A14;
    }
    // 0x8009295C: nop

    // 0x80092960: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092964: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80092968: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009296C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80092970: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092974: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092978: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009297C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092980: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80092984: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092988: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x8009298C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092990: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092994: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092998: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8009299C: beq         $t6, $zero, L_800929F0
    if (ctx->r14 == 0) {
        // 0x800929A0: nop

            goto L_800929F0;
    }
    // 0x800929A0: nop

    // 0x800929A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800929A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800929AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800929B0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800929B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800929B8: nop

    // 0x800929BC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800929C0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800929C4: nop

    // 0x800929C8: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x800929CC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800929D0: bne         $t6, $zero, L_800929E8
    if (ctx->r14 != 0) {
        // 0x800929D4: nop

            goto L_800929E8;
    }
    // 0x800929D4: nop

    // 0x800929D8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800929DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800929E0: b           L_80092A00
    // 0x800929E4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80092A00;
    // 0x800929E4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800929E8:
    // 0x800929E8: b           L_80092A00
    // 0x800929EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80092A00;
    // 0x800929EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800929F0:
    // 0x800929F0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800929F4: nop

    // 0x800929F8: bltz        $t6, L_800929E8
    if (SIGNED(ctx->r14) < 0) {
        // 0x800929FC: nop

            goto L_800929E8;
    }
    // 0x800929FC: nop

L_80092A00:
    // 0x80092A00: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80092A04: jal         0x800908A0
    // 0x80092A08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_24;
    // 0x80092A08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_24:
    // 0x80092A0C: b           L_80092AC0
    // 0x80092A10: nop

        goto L_80092AC0;
    // 0x80092A10: nop

L_80092A14:
    // 0x80092A14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092A18: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80092A1C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092A20: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80092A24: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092A28: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092A2C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80092A30: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092A34: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80092A38: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092A3C: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80092A40: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092A44: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092A48: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092A4C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80092A50: beq         $t5, $zero, L_80092AA4
    if (ctx->r13 == 0) {
        // 0x80092A54: nop

            goto L_80092AA4;
    }
    // 0x80092A54: nop

    // 0x80092A58: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092A5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092A60: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092A64: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80092A68: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80092A6C: nop

    // 0x80092A70: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80092A74: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80092A78: nop

    // 0x80092A7C: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80092A80: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80092A84: bne         $t5, $zero, L_80092A9C
    if (ctx->r13 != 0) {
        // 0x80092A88: nop

            goto L_80092A9C;
    }
    // 0x80092A88: nop

    // 0x80092A8C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80092A90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092A94: b           L_80092AB4
    // 0x80092A98: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80092AB4;
    // 0x80092A98: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80092A9C:
    // 0x80092A9C: b           L_80092AB4
    // 0x80092AA0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80092AB4;
    // 0x80092AA0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80092AA4:
    // 0x80092AA4: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80092AA8: nop

    // 0x80092AAC: bltz        $t5, L_80092A9C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80092AB0: nop

            goto L_80092A9C;
    }
    // 0x80092AB0: nop

L_80092AB4:
    // 0x80092AB4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80092AB8: jal         0x800908A0
    // 0x80092ABC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_25;
    // 0x80092ABC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_25:
L_80092AC0:
    // 0x80092AC0: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x80092AC4: nop

    // 0x80092AC8: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80092ACC: beq         $t8, $zero, L_80092B88
    if (ctx->r24 == 0) {
        // 0x80092AD0: nop

            goto L_80092B88;
    }
    // 0x80092AD0: nop

    // 0x80092AD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092AD8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80092ADC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092AE0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80092AE4: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092AE8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092AEC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80092AF0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092AF4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80092AF8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092AFC: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80092B00: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092B04: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092B0C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80092B10: beq         $t9, $zero, L_80092B64
    if (ctx->r25 == 0) {
        // 0x80092B14: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80092B64;
    }
    // 0x80092B14: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80092B18: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092B1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80092B20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092B24: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80092B28: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80092B2C: nop

    // 0x80092B30: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80092B34: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80092B38: nop

    // 0x80092B3C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80092B40: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80092B44: bne         $t9, $zero, L_80092B5C
    if (ctx->r25 != 0) {
        // 0x80092B48: nop

            goto L_80092B5C;
    }
    // 0x80092B48: nop

    // 0x80092B4C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80092B50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092B54: b           L_80092B74
    // 0x80092B58: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80092B74;
    // 0x80092B58: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80092B5C:
    // 0x80092B5C: b           L_80092B74
    // 0x80092B60: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80092B74;
    // 0x80092B60: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80092B64:
    // 0x80092B64: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80092B68: nop

    // 0x80092B6C: bltz        $t9, L_80092B5C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80092B70: nop

            goto L_80092B5C;
    }
    // 0x80092B70: nop

L_80092B74:
    // 0x80092B74: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80092B78: jal         0x800908A0
    // 0x80092B7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_26;
    // 0x80092B7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_26:
    // 0x80092B80: b           L_80092C34
    // 0x80092B84: nop

        goto L_80092C34;
    // 0x80092B84: nop

L_80092B88:
    // 0x80092B88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092B8C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80092B90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80092B94: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80092B98: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092B9C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092BA0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80092BA4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092BA8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80092BAC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092BB0: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80092BB4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092BB8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092BBC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092BC0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80092BC4: beq         $t2, $zero, L_80092C18
    if (ctx->r10 == 0) {
        // 0x80092BC8: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80092C18;
    }
    // 0x80092BC8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80092BCC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092BD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80092BD4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80092BD8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80092BDC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80092BE0: nop

    // 0x80092BE4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80092BE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80092BEC: nop

    // 0x80092BF0: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80092BF4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80092BF8: bne         $t2, $zero, L_80092C10
    if (ctx->r10 != 0) {
        // 0x80092BFC: nop

            goto L_80092C10;
    }
    // 0x80092BFC: nop

    // 0x80092C00: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80092C04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092C08: b           L_80092C28
    // 0x80092C0C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80092C28;
    // 0x80092C0C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80092C10:
    // 0x80092C10: b           L_80092C28
    // 0x80092C14: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80092C28;
    // 0x80092C14: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80092C18:
    // 0x80092C18: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80092C1C: nop

    // 0x80092C20: bltz        $t2, L_80092C10
    if (SIGNED(ctx->r10) < 0) {
        // 0x80092C24: nop

            goto L_80092C10;
    }
    // 0x80092C24: nop

L_80092C28:
    // 0x80092C28: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80092C2C: jal         0x800908A0
    // 0x80092C30: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_27;
    // 0x80092C30: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_27:
L_80092C34:
    // 0x80092C34: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x80092C38: nop

    // 0x80092C3C: andi        $t6, $t3, 0x20
    ctx->r14 = ctx->r11 & 0X20;
    // 0x80092C40: beq         $t6, $zero, L_80092CFC
    if (ctx->r14 == 0) {
        // 0x80092C44: nop

            goto L_80092CFC;
    }
    // 0x80092C44: nop

    // 0x80092C48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092C4C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80092C50: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092C54: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80092C58: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092C5C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092C60: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80092C64: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092C68: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80092C6C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092C70: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80092C74: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092C78: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092C7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092C80: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80092C84: beq         $t5, $zero, L_80092CD8
    if (ctx->r13 == 0) {
        // 0x80092C88: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80092CD8;
    }
    // 0x80092C88: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80092C8C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092C90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092C94: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092C98: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80092C9C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80092CA0: nop

    // 0x80092CA4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80092CA8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80092CAC: nop

    // 0x80092CB0: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80092CB4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80092CB8: bne         $t5, $zero, L_80092CD0
    if (ctx->r13 != 0) {
        // 0x80092CBC: nop

            goto L_80092CD0;
    }
    // 0x80092CBC: nop

    // 0x80092CC0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80092CC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092CC8: b           L_80092CE8
    // 0x80092CCC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80092CE8;
    // 0x80092CCC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80092CD0:
    // 0x80092CD0: b           L_80092CE8
    // 0x80092CD4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80092CE8;
    // 0x80092CD4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80092CD8:
    // 0x80092CD8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80092CDC: nop

    // 0x80092CE0: bltz        $t5, L_80092CD0
    if (SIGNED(ctx->r13) < 0) {
        // 0x80092CE4: nop

            goto L_80092CD0;
    }
    // 0x80092CE4: nop

L_80092CE8:
    // 0x80092CE8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80092CEC: jal         0x800908A0
    // 0x80092CF0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_28;
    // 0x80092CF0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_28:
    // 0x80092CF4: b           L_80092DA8
    // 0x80092CF8: nop

        goto L_80092DA8;
    // 0x80092CF8: nop

L_80092CFC:
    // 0x80092CFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092D00: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80092D04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092D08: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80092D0C: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092D10: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092D14: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80092D18: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092D1C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80092D20: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092D24: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80092D28: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092D2C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092D30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092D34: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80092D38: beq         $t8, $zero, L_80092D8C
    if (ctx->r24 == 0) {
        // 0x80092D3C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80092D8C;
    }
    // 0x80092D3C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80092D40: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092D44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80092D48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092D4C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80092D50: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80092D54: nop

    // 0x80092D58: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80092D5C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80092D60: nop

    // 0x80092D64: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80092D68: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80092D6C: bne         $t8, $zero, L_80092D84
    if (ctx->r24 != 0) {
        // 0x80092D70: nop

            goto L_80092D84;
    }
    // 0x80092D70: nop

    // 0x80092D74: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80092D78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092D7C: b           L_80092D9C
    // 0x80092D80: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80092D9C;
    // 0x80092D80: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80092D84:
    // 0x80092D84: b           L_80092D9C
    // 0x80092D88: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80092D9C;
    // 0x80092D88: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80092D8C:
    // 0x80092D8C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80092D90: nop

    // 0x80092D94: bltz        $t8, L_80092D84
    if (SIGNED(ctx->r24) < 0) {
        // 0x80092D98: nop

            goto L_80092D84;
    }
    // 0x80092D98: nop

L_80092D9C:
    // 0x80092D9C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80092DA0: jal         0x800908A0
    // 0x80092DA4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_29;
    // 0x80092DA4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_29:
L_80092DA8:
    // 0x80092DA8: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80092DAC: nop

    // 0x80092DB0: andi        $t9, $t0, 0x10
    ctx->r25 = ctx->r8 & 0X10;
    // 0x80092DB4: beq         $t9, $zero, L_80092E70
    if (ctx->r25 == 0) {
        // 0x80092DB8: nop

            goto L_80092E70;
    }
    // 0x80092DB8: nop

    // 0x80092DBC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092DC0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80092DC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80092DC8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80092DCC: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092DD0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092DD4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80092DD8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092DDC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80092DE0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092DE4: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80092DE8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092DEC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092DF0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092DF4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80092DF8: beq         $t2, $zero, L_80092E4C
    if (ctx->r10 == 0) {
        // 0x80092DFC: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_80092E4C;
    }
    // 0x80092DFC: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80092E00: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092E04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80092E08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80092E0C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80092E10: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80092E14: nop

    // 0x80092E18: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80092E1C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80092E20: nop

    // 0x80092E24: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80092E28: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80092E2C: bne         $t2, $zero, L_80092E44
    if (ctx->r10 != 0) {
        // 0x80092E30: nop

            goto L_80092E44;
    }
    // 0x80092E30: nop

    // 0x80092E34: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80092E38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092E3C: b           L_80092E5C
    // 0x80092E40: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80092E5C;
    // 0x80092E40: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80092E44:
    // 0x80092E44: b           L_80092E5C
    // 0x80092E48: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80092E5C;
    // 0x80092E48: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80092E4C:
    // 0x80092E4C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80092E50: nop

    // 0x80092E54: bltz        $t2, L_80092E44
    if (SIGNED(ctx->r10) < 0) {
        // 0x80092E58: nop

            goto L_80092E44;
    }
    // 0x80092E58: nop

L_80092E5C:
    // 0x80092E5C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80092E60: jal         0x800908A0
    // 0x80092E64: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_30;
    // 0x80092E64: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_30:
    // 0x80092E68: b           L_80092F1C
    // 0x80092E6C: nop

        goto L_80092F1C;
    // 0x80092E6C: nop

L_80092E70:
    // 0x80092E70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092E74: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80092E78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092E7C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80092E80: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092E84: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092E88: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80092E8C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092E90: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80092E94: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092E98: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80092E9C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092EA0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092EA4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092EA8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80092EAC: beq         $t6, $zero, L_80092F00
    if (ctx->r14 == 0) {
        // 0x80092EB0: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_80092F00;
    }
    // 0x80092EB0: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80092EB4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092EB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092EBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092EC0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80092EC4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80092EC8: nop

    // 0x80092ECC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80092ED0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80092ED4: nop

    // 0x80092ED8: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80092EDC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80092EE0: bne         $t6, $zero, L_80092EF8
    if (ctx->r14 != 0) {
        // 0x80092EE4: nop

            goto L_80092EF8;
    }
    // 0x80092EE4: nop

    // 0x80092EE8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80092EEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092EF0: b           L_80092F10
    // 0x80092EF4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80092F10;
    // 0x80092EF4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80092EF8:
    // 0x80092EF8: b           L_80092F10
    // 0x80092EFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80092F10;
    // 0x80092EFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80092F00:
    // 0x80092F00: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80092F04: nop

    // 0x80092F08: bltz        $t6, L_80092EF8
    if (SIGNED(ctx->r14) < 0) {
        // 0x80092F0C: nop

            goto L_80092EF8;
    }
    // 0x80092F0C: nop

L_80092F10:
    // 0x80092F10: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80092F14: jal         0x800908A0
    // 0x80092F18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_31;
    // 0x80092F18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_31:
L_80092F1C:
    // 0x80092F1C: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x80092F20: nop

    // 0x80092F24: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x80092F28: beq         $t5, $zero, L_80092FE4
    if (ctx->r13 == 0) {
        // 0x80092F2C: nop

            goto L_80092FE4;
    }
    // 0x80092F2C: nop

    // 0x80092F30: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092F34: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80092F38: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092F3C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80092F40: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092F44: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092F48: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80092F4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092F50: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80092F54: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092F58: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80092F5C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092F60: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092F64: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092F68: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80092F6C: beq         $t8, $zero, L_80092FC0
    if (ctx->r24 == 0) {
        // 0x80092F70: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80092FC0;
    }
    // 0x80092F70: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80092F74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092F78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80092F7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092F80: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80092F84: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80092F88: nop

    // 0x80092F8C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80092F90: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80092F94: nop

    // 0x80092F98: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80092F9C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80092FA0: bne         $t8, $zero, L_80092FB8
    if (ctx->r24 != 0) {
        // 0x80092FA4: nop

            goto L_80092FB8;
    }
    // 0x80092FA4: nop

    // 0x80092FA8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80092FAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092FB0: b           L_80092FD0
    // 0x80092FB4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80092FD0;
    // 0x80092FB4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80092FB8:
    // 0x80092FB8: b           L_80092FD0
    // 0x80092FBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80092FD0;
    // 0x80092FBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80092FC0:
    // 0x80092FC0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80092FC4: nop

    // 0x80092FC8: bltz        $t8, L_80092FB8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80092FCC: nop

            goto L_80092FB8;
    }
    // 0x80092FCC: nop

L_80092FD0:
    // 0x80092FD0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80092FD4: jal         0x800908A0
    // 0x80092FD8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_32;
    // 0x80092FD8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_32:
    // 0x80092FDC: b           L_80093090
    // 0x80092FE0: nop

        goto L_80093090;
    // 0x80092FE0: nop

L_80092FE4:
    // 0x80092FE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092FE8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80092FEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092FF0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80092FF4: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092FF8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092FFC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80093000: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093004: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80093008: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009300C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80093010: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093014: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093018: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009301C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80093020: beq         $t9, $zero, L_80093074
    if (ctx->r25 == 0) {
        // 0x80093024: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80093074;
    }
    // 0x80093024: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80093028: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009302C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093030: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80093034: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80093038: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8009303C: nop

    // 0x80093040: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80093044: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80093048: nop

    // 0x8009304C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80093050: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80093054: bne         $t9, $zero, L_8009306C
    if (ctx->r25 != 0) {
        // 0x80093058: nop

            goto L_8009306C;
    }
    // 0x80093058: nop

    // 0x8009305C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80093060: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093064: b           L_80093084
    // 0x80093068: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80093084;
    // 0x80093068: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8009306C:
    // 0x8009306C: b           L_80093084
    // 0x80093070: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80093084;
    // 0x80093070: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80093074:
    // 0x80093074: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80093078: nop

    // 0x8009307C: bltz        $t9, L_8009306C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80093080: nop

            goto L_8009306C;
    }
    // 0x80093080: nop

L_80093084:
    // 0x80093084: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80093088: jal         0x800908A0
    // 0x8009308C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_33;
    // 0x8009308C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_33:
L_80093090:
    // 0x80093090: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x80093094: nop

    // 0x80093098: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x8009309C: beq         $t2, $zero, L_80093158
    if (ctx->r10 == 0) {
        // 0x800930A0: nop

            goto L_80093158;
    }
    // 0x800930A0: nop

    // 0x800930A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800930A8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800930AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800930B0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800930B4: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800930B8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800930BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800930C0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800930C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800930C8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800930CC: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x800930D0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800930D4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800930D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800930DC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800930E0: beq         $t6, $zero, L_80093134
    if (ctx->r14 == 0) {
        // 0x800930E4: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_80093134;
    }
    // 0x800930E4: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x800930E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800930EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800930F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800930F4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800930F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800930FC: nop

    // 0x80093100: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80093104: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80093108: nop

    // 0x8009310C: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80093110: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80093114: bne         $t6, $zero, L_8009312C
    if (ctx->r14 != 0) {
        // 0x80093118: nop

            goto L_8009312C;
    }
    // 0x80093118: nop

    // 0x8009311C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80093120: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093124: b           L_80093144
    // 0x80093128: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80093144;
    // 0x80093128: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8009312C:
    // 0x8009312C: b           L_80093144
    // 0x80093130: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80093144;
    // 0x80093130: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80093134:
    // 0x80093134: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80093138: nop

    // 0x8009313C: bltz        $t6, L_8009312C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80093140: nop

            goto L_8009312C;
    }
    // 0x80093140: nop

L_80093144:
    // 0x80093144: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80093148: jal         0x800908A0
    // 0x8009314C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_34;
    // 0x8009314C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_34:
    // 0x80093150: b           L_80093204
    // 0x80093154: nop

        goto L_80093204;
    // 0x80093154: nop

L_80093158:
    // 0x80093158: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009315C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80093160: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80093164: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80093168: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009316C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093170: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80093174: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093178: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8009317C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093180: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80093184: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093188: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009318C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093190: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80093194: beq         $t5, $zero, L_800931E8
    if (ctx->r13 == 0) {
        // 0x80093198: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_800931E8;
    }
    // 0x80093198: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x8009319C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800931A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800931A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800931A8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800931AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800931B0: nop

    // 0x800931B4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800931B8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800931BC: nop

    // 0x800931C0: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800931C4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800931C8: bne         $t5, $zero, L_800931E0
    if (ctx->r13 != 0) {
        // 0x800931CC: nop

            goto L_800931E0;
    }
    // 0x800931CC: nop

    // 0x800931D0: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800931D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800931D8: b           L_800931F8
    // 0x800931DC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800931F8;
    // 0x800931DC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800931E0:
    // 0x800931E0: b           L_800931F8
    // 0x800931E4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800931F8;
    // 0x800931E4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_800931E8:
    // 0x800931E8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800931EC: nop

    // 0x800931F0: bltz        $t5, L_800931E0
    if (SIGNED(ctx->r13) < 0) {
        // 0x800931F4: nop

            goto L_800931E0;
    }
    // 0x800931F4: nop

L_800931F8:
    // 0x800931F8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800931FC: jal         0x800908A0
    // 0x80093200: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_35;
    // 0x80093200: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_35:
L_80093204:
    // 0x80093204: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x80093208: nop

    // 0x8009320C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80093210: beq         $t8, $zero, L_800932CC
    if (ctx->r24 == 0) {
        // 0x80093214: nop

            goto L_800932CC;
    }
    // 0x80093214: nop

    // 0x80093218: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009321C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80093220: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80093224: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80093228: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009322C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093230: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80093234: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093238: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009323C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093240: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80093244: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093248: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009324C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093250: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80093254: beq         $t9, $zero, L_800932A8
    if (ctx->r25 == 0) {
        // 0x80093258: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_800932A8;
    }
    // 0x80093258: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x8009325C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093264: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80093268: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009326C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80093270: nop

    // 0x80093274: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80093278: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009327C: nop

    // 0x80093280: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80093284: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80093288: bne         $t9, $zero, L_800932A0
    if (ctx->r25 != 0) {
        // 0x8009328C: nop

            goto L_800932A0;
    }
    // 0x8009328C: nop

    // 0x80093290: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80093294: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093298: b           L_800932B8
    // 0x8009329C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800932B8;
    // 0x8009329C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800932A0:
    // 0x800932A0: b           L_800932B8
    // 0x800932A4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800932B8;
    // 0x800932A4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800932A8:
    // 0x800932A8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800932AC: nop

    // 0x800932B0: bltz        $t9, L_800932A0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800932B4: nop

            goto L_800932A0;
    }
    // 0x800932B4: nop

L_800932B8:
    // 0x800932B8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800932BC: jal         0x800908A0
    // 0x800932C0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_36;
    // 0x800932C0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_36:
    // 0x800932C4: b           L_80093378
    // 0x800932C8: nop

        goto L_80093378;
    // 0x800932C8: nop

L_800932CC:
    // 0x800932CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800932D0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800932D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800932D8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800932DC: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800932E0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800932E4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800932E8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800932EC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800932F0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800932F4: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x800932F8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800932FC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093300: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093304: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80093308: beq         $t2, $zero, L_8009335C
    if (ctx->r10 == 0) {
        // 0x8009330C: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_8009335C;
    }
    // 0x8009330C: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80093310: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093314: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80093318: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8009331C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80093320: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80093324: nop

    // 0x80093328: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009332C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093330: nop

    // 0x80093334: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80093338: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8009333C: bne         $t2, $zero, L_80093354
    if (ctx->r10 != 0) {
        // 0x80093340: nop

            goto L_80093354;
    }
    // 0x80093340: nop

    // 0x80093344: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80093348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009334C: b           L_8009336C
    // 0x80093350: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8009336C;
    // 0x80093350: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80093354:
    // 0x80093354: b           L_8009336C
    // 0x80093358: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8009336C;
    // 0x80093358: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8009335C:
    // 0x8009335C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80093360: nop

    // 0x80093364: bltz        $t2, L_80093354
    if (SIGNED(ctx->r10) < 0) {
        // 0x80093368: nop

            goto L_80093354;
    }
    // 0x80093368: nop

L_8009336C:
    // 0x8009336C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80093370: jal         0x800908A0
    // 0x80093374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_37;
    // 0x80093374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_37:
L_80093378:
    // 0x80093378: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x8009337C: nop

    // 0x80093380: andi        $t6, $t3, 0x1
    ctx->r14 = ctx->r11 & 0X1;
    // 0x80093384: beq         $t6, $zero, L_80093440
    if (ctx->r14 == 0) {
        // 0x80093388: nop

            goto L_80093440;
    }
    // 0x80093388: nop

    // 0x8009338C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093390: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80093394: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80093398: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8009339C: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800933A0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800933A4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800933A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800933AC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800933B0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800933B4: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800933B8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800933BC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800933C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800933C4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800933C8: beq         $t5, $zero, L_8009341C
    if (ctx->r13 == 0) {
        // 0x800933CC: addiu       $a3, $a3, 0xE
        ctx->r7 = ADD32(ctx->r7, 0XE);
            goto L_8009341C;
    }
    // 0x800933CC: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x800933D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800933D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800933D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800933DC: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800933E0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800933E4: nop

    // 0x800933E8: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800933EC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800933F0: nop

    // 0x800933F4: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800933F8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800933FC: bne         $t5, $zero, L_80093414
    if (ctx->r13 != 0) {
        // 0x80093400: nop

            goto L_80093414;
    }
    // 0x80093400: nop

    // 0x80093404: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80093408: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009340C: b           L_8009342C
    // 0x80093410: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8009342C;
    // 0x80093410: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80093414:
    // 0x80093414: b           L_8009342C
    // 0x80093418: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8009342C;
    // 0x80093418: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_8009341C:
    // 0x8009341C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80093420: nop

    // 0x80093424: bltz        $t5, L_80093414
    if (SIGNED(ctx->r13) < 0) {
        // 0x80093428: nop

            goto L_80093414;
    }
    // 0x80093428: nop

L_8009342C:
    // 0x8009342C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80093430: jal         0x800908A0
    // 0x80093434: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_38;
    // 0x80093434: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_38:
    // 0x80093438: b           L_800934EC
    // 0x8009343C: nop

        goto L_800934EC;
    // 0x8009343C: nop

L_80093440:
    // 0x80093440: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093444: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80093448: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009344C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80093450: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093454: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093458: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009345C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093460: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80093464: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093468: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8009346C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093470: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093474: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093478: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8009347C: beq         $t8, $zero, L_800934D0
    if (ctx->r24 == 0) {
        // 0x80093480: addiu       $a3, $a3, 0xE
        ctx->r7 = ADD32(ctx->r7, 0XE);
            goto L_800934D0;
    }
    // 0x80093480: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x80093484: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093488: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009348C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80093490: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80093494: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80093498: nop

    // 0x8009349C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800934A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800934A4: nop

    // 0x800934A8: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800934AC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800934B0: bne         $t8, $zero, L_800934C8
    if (ctx->r24 != 0) {
        // 0x800934B4: nop

            goto L_800934C8;
    }
    // 0x800934B4: nop

    // 0x800934B8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800934BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800934C0: b           L_800934E0
    // 0x800934C4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800934E0;
    // 0x800934C4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800934C8:
    // 0x800934C8: b           L_800934E0
    // 0x800934CC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800934E0;
    // 0x800934CC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800934D0:
    // 0x800934D0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800934D4: nop

    // 0x800934D8: bltz        $t8, L_800934C8
    if (SIGNED(ctx->r24) < 0) {
        // 0x800934DC: nop

            goto L_800934C8;
    }
    // 0x800934DC: nop

L_800934E0:
    // 0x800934E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800934E4: jal         0x800908A0
    // 0x800934E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_39;
    // 0x800934E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_39:
L_800934EC:
    // 0x800934EC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800934F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800934F4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800934F8: lw          $t6, -0x78C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78C);
    // 0x800934FC: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x80093500: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80093504: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80093508: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x8009350C: lbu         $t5, -0x3FF($t4)
    ctx->r13 = MEM_BU(ctx->r12, -0X3FF);
    // 0x80093510: nop

    // 0x80093514: sb          $t5, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r13;
    // 0x80093518: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x8009351C: nop

    // 0x80093520: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80093524: beq         $t8, $zero, L_800935E0
    if (ctx->r24 == 0) {
        // 0x80093528: nop

            goto L_800935E0;
    }
    // 0x80093528: nop

    // 0x8009352C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093530: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80093534: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80093538: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009353C: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093540: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093544: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80093548: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009354C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80093550: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093554: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80093558: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009355C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093560: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093564: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80093568: beq         $t1, $zero, L_800935BC
    if (ctx->r9 == 0) {
        // 0x8009356C: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800935BC;
    }
    // 0x8009356C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80093570: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80093578: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009357C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80093580: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80093584: nop

    // 0x80093588: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009358C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80093590: nop

    // 0x80093594: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80093598: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8009359C: bne         $t1, $zero, L_800935B4
    if (ctx->r9 != 0) {
        // 0x800935A0: nop

            goto L_800935B4;
    }
    // 0x800935A0: nop

    // 0x800935A4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800935A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800935AC: b           L_800935CC
    // 0x800935B0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800935CC;
    // 0x800935B0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800935B4:
    // 0x800935B4: b           L_800935CC
    // 0x800935B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800935CC;
    // 0x800935B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800935BC:
    // 0x800935BC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800935C0: nop

    // 0x800935C4: bltz        $t1, L_800935B4
    if (SIGNED(ctx->r9) < 0) {
        // 0x800935C8: nop

            goto L_800935B4;
    }
    // 0x800935C8: nop

L_800935CC:
    // 0x800935CC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800935D0: jal         0x800908A0
    // 0x800935D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_40;
    // 0x800935D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_40:
    // 0x800935D8: b           L_8009368C
    // 0x800935DC: nop

        goto L_8009368C;
    // 0x800935DC: nop

L_800935E0:
    // 0x800935E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800935E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800935E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800935EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800935F0: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800935F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800935F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800935FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093600: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093604: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093608: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8009360C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093610: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093614: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093618: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8009361C: beq         $t2, $zero, L_80093670
    if (ctx->r10 == 0) {
        // 0x80093620: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80093670;
    }
    // 0x80093620: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80093624: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093628: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009362C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80093630: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80093634: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80093638: nop

    // 0x8009363C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80093640: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093644: nop

    // 0x80093648: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8009364C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80093650: bne         $t2, $zero, L_80093668
    if (ctx->r10 != 0) {
        // 0x80093654: nop

            goto L_80093668;
    }
    // 0x80093654: nop

    // 0x80093658: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8009365C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093660: b           L_80093680
    // 0x80093664: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80093680;
    // 0x80093664: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80093668:
    // 0x80093668: b           L_80093680
    // 0x8009366C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80093680;
    // 0x8009366C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80093670:
    // 0x80093670: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80093674: nop

    // 0x80093678: bltz        $t2, L_80093668
    if (SIGNED(ctx->r10) < 0) {
        // 0x8009367C: nop

            goto L_80093668;
    }
    // 0x8009367C: nop

L_80093680:
    // 0x80093680: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80093684: jal         0x800908A0
    // 0x80093688: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_41;
    // 0x80093688: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_41:
L_8009368C:
    // 0x8009368C: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x80093690: nop

    // 0x80093694: andi        $t6, $t3, 0x40
    ctx->r14 = ctx->r11 & 0X40;
    // 0x80093698: beq         $t6, $zero, L_80093754
    if (ctx->r14 == 0) {
        // 0x8009369C: nop

            goto L_80093754;
    }
    // 0x8009369C: nop

    // 0x800936A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800936A4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800936A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800936AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800936B0: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800936B4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800936B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800936BC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800936C0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800936C4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800936C8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800936CC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800936D0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800936D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800936D8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800936DC: beq         $t5, $zero, L_80093730
    if (ctx->r13 == 0) {
        // 0x800936E0: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80093730;
    }
    // 0x800936E0: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x800936E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800936E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800936EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800936F0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800936F4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800936F8: nop

    // 0x800936FC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80093700: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80093704: nop

    // 0x80093708: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x8009370C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80093710: bne         $t5, $zero, L_80093728
    if (ctx->r13 != 0) {
        // 0x80093714: nop

            goto L_80093728;
    }
    // 0x80093714: nop

    // 0x80093718: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8009371C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093720: b           L_80093740
    // 0x80093724: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80093740;
    // 0x80093724: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80093728:
    // 0x80093728: b           L_80093740
    // 0x8009372C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80093740;
    // 0x8009372C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80093730:
    // 0x80093730: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80093734: nop

    // 0x80093738: bltz        $t5, L_80093728
    if (SIGNED(ctx->r13) < 0) {
        // 0x8009373C: nop

            goto L_80093728;
    }
    // 0x8009373C: nop

L_80093740:
    // 0x80093740: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80093744: jal         0x800908A0
    // 0x80093748: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_42;
    // 0x80093748: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_42:
    // 0x8009374C: b           L_80093800
    // 0x80093750: nop

        goto L_80093800;
    // 0x80093750: nop

L_80093754:
    // 0x80093754: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093758: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8009375C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80093760: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80093764: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093768: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009376C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80093770: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093774: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80093778: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009377C: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80093780: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093784: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093788: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009378C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80093790: beq         $t8, $zero, L_800937E4
    if (ctx->r24 == 0) {
        // 0x80093794: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_800937E4;
    }
    // 0x80093794: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80093798: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009379C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800937A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800937A4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800937A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800937AC: nop

    // 0x800937B0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800937B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800937B8: nop

    // 0x800937BC: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800937C0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800937C4: bne         $t8, $zero, L_800937DC
    if (ctx->r24 != 0) {
        // 0x800937C8: nop

            goto L_800937DC;
    }
    // 0x800937C8: nop

    // 0x800937CC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800937D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800937D4: b           L_800937F4
    // 0x800937D8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800937F4;
    // 0x800937D8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800937DC:
    // 0x800937DC: b           L_800937F4
    // 0x800937E0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800937F4;
    // 0x800937E0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800937E4:
    // 0x800937E4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800937E8: nop

    // 0x800937EC: bltz        $t8, L_800937DC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800937F0: nop

            goto L_800937DC;
    }
    // 0x800937F0: nop

L_800937F4:
    // 0x800937F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800937F8: jal         0x800908A0
    // 0x800937FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_43;
    // 0x800937FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_43:
L_80093800:
    // 0x80093800: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80093804: nop

    // 0x80093808: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x8009380C: beq         $t1, $zero, L_800938C8
    if (ctx->r9 == 0) {
        // 0x80093810: nop

            goto L_800938C8;
    }
    // 0x80093810: nop

    // 0x80093814: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093818: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009381C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80093820: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80093824: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093828: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009382C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80093830: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093834: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093838: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009383C: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80093840: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093844: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093848: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009384C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80093850: beq         $t2, $zero, L_800938A4
    if (ctx->r10 == 0) {
        // 0x80093854: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_800938A4;
    }
    // 0x80093854: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x80093858: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009385C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80093860: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80093864: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80093868: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8009386C: nop

    // 0x80093870: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80093874: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093878: nop

    // 0x8009387C: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80093880: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80093884: bne         $t2, $zero, L_8009389C
    if (ctx->r10 != 0) {
        // 0x80093888: nop

            goto L_8009389C;
    }
    // 0x80093888: nop

    // 0x8009388C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80093890: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093894: b           L_800938B4
    // 0x80093898: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800938B4;
    // 0x80093898: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8009389C:
    // 0x8009389C: b           L_800938B4
    // 0x800938A0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800938B4;
    // 0x800938A0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_800938A4:
    // 0x800938A4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800938A8: nop

    // 0x800938AC: bltz        $t2, L_8009389C
    if (SIGNED(ctx->r10) < 0) {
        // 0x800938B0: nop

            goto L_8009389C;
    }
    // 0x800938B0: nop

L_800938B4:
    // 0x800938B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800938B8: jal         0x800908A0
    // 0x800938BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_44;
    // 0x800938BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_44:
    // 0x800938C0: b           L_80093974
    // 0x800938C4: nop

        goto L_80093974;
    // 0x800938C4: nop

L_800938C8:
    // 0x800938C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800938CC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800938D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800938D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800938D8: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800938DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800938E0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800938E4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800938E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800938EC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800938F0: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x800938F4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800938F8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800938FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093900: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80093904: beq         $t6, $zero, L_80093958
    if (ctx->r14 == 0) {
        // 0x80093908: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_80093958;
    }
    // 0x80093908: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x8009390C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093914: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80093918: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009391C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80093920: nop

    // 0x80093924: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80093928: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009392C: nop

    // 0x80093930: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80093934: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80093938: bne         $t6, $zero, L_80093950
    if (ctx->r14 != 0) {
        // 0x8009393C: nop

            goto L_80093950;
    }
    // 0x8009393C: nop

    // 0x80093940: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80093944: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093948: b           L_80093968
    // 0x8009394C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80093968;
    // 0x8009394C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80093950:
    // 0x80093950: b           L_80093968
    // 0x80093954: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80093968;
    // 0x80093954: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80093958:
    // 0x80093958: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009395C: nop

    // 0x80093960: bltz        $t6, L_80093950
    if (SIGNED(ctx->r14) < 0) {
        // 0x80093964: nop

            goto L_80093950;
    }
    // 0x80093964: nop

L_80093968:
    // 0x80093968: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009396C: jal         0x800908A0
    // 0x80093970: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_45;
    // 0x80093970: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_45:
L_80093974:
    // 0x80093974: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x80093978: nop

    // 0x8009397C: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80093980: beq         $t5, $zero, L_80093A3C
    if (ctx->r13 == 0) {
        // 0x80093984: nop

            goto L_80093A3C;
    }
    // 0x80093984: nop

    // 0x80093988: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009398C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80093990: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80093994: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80093998: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009399C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800939A0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800939A4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800939A8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800939AC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800939B0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800939B4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800939B8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800939BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800939C0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800939C4: beq         $t8, $zero, L_80093A18
    if (ctx->r24 == 0) {
        // 0x800939C8: addiu       $a3, $a3, 0x16
        ctx->r7 = ADD32(ctx->r7, 0X16);
            goto L_80093A18;
    }
    // 0x800939C8: addiu       $a3, $a3, 0x16
    ctx->r7 = ADD32(ctx->r7, 0X16);
    // 0x800939CC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800939D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800939D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800939D8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800939DC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800939E0: nop

    // 0x800939E4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800939E8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800939EC: nop

    // 0x800939F0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800939F4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800939F8: bne         $t8, $zero, L_80093A10
    if (ctx->r24 != 0) {
        // 0x800939FC: nop

            goto L_80093A10;
    }
    // 0x800939FC: nop

    // 0x80093A00: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80093A04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093A08: b           L_80093A28
    // 0x80093A0C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80093A28;
    // 0x80093A0C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80093A10:
    // 0x80093A10: b           L_80093A28
    // 0x80093A14: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80093A28;
    // 0x80093A14: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80093A18:
    // 0x80093A18: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80093A1C: nop

    // 0x80093A20: bltz        $t8, L_80093A10
    if (SIGNED(ctx->r24) < 0) {
        // 0x80093A24: nop

            goto L_80093A10;
    }
    // 0x80093A24: nop

L_80093A28:
    // 0x80093A28: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80093A2C: jal         0x800908A0
    // 0x80093A30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_46;
    // 0x80093A30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_46:
    // 0x80093A34: b           L_80093AE8
    // 0x80093A38: nop

        goto L_80093AE8;
    // 0x80093A38: nop

L_80093A3C:
    // 0x80093A3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093A40: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80093A44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80093A48: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80093A4C: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093A50: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093A54: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80093A58: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093A5C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80093A60: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093A64: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80093A68: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093A6C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093A70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093A74: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80093A78: beq         $t1, $zero, L_80093ACC
    if (ctx->r9 == 0) {
        // 0x80093A7C: addiu       $a3, $a3, 0x16
        ctx->r7 = ADD32(ctx->r7, 0X16);
            goto L_80093ACC;
    }
    // 0x80093A7C: addiu       $a3, $a3, 0x16
    ctx->r7 = ADD32(ctx->r7, 0X16);
    // 0x80093A80: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093A84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80093A88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80093A8C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80093A90: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80093A94: nop

    // 0x80093A98: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80093A9C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80093AA0: nop

    // 0x80093AA4: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80093AA8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80093AAC: bne         $t1, $zero, L_80093AC4
    if (ctx->r9 != 0) {
        // 0x80093AB0: nop

            goto L_80093AC4;
    }
    // 0x80093AB0: nop

    // 0x80093AB4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80093AB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093ABC: b           L_80093ADC
    // 0x80093AC0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80093ADC;
    // 0x80093AC0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80093AC4:
    // 0x80093AC4: b           L_80093ADC
    // 0x80093AC8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80093ADC;
    // 0x80093AC8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80093ACC:
    // 0x80093ACC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80093AD0: nop

    // 0x80093AD4: bltz        $t1, L_80093AC4
    if (SIGNED(ctx->r9) < 0) {
        // 0x80093AD8: nop

            goto L_80093AC4;
    }
    // 0x80093AD8: nop

L_80093ADC:
    // 0x80093ADC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80093AE0: jal         0x800908A0
    // 0x80093AE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_47;
    // 0x80093AE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_47:
L_80093AE8:
    // 0x80093AE8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80093AEC: nop

    // 0x80093AF0: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80093AF4: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x80093AF8: bne         $at, $zero, L_80092890
    if (ctx->r1 != 0) {
        // 0x80093AFC: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_80092890;
    }
    // 0x80093AFC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80093B00:
    // 0x80093B00: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80093B04: lw          $t3, 0x6B98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6B98);
    // 0x80093B08: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80093B0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80093B10: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x80093B14: sw          $t4, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r12;
    // 0x80093B18: b           L_80093B20
    // 0x80093B1C: nop

        goto L_80093B20;
    // 0x80093B1C: nop

L_80093B20:
    // 0x80093B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093B24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80093B28: jr          $ra
    // 0x80093B2C: nop

    return;
    // 0x80093B2C: nop

;}
RECOMP_FUNC void func_80093B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093B30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80093B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093B38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80093B3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80093B40: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80093B44:
    // 0x80093B44: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80093B48: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x80093B4C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80093B50: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80093B54: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093B58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80093B5C: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093B60: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80093B64: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80093B68: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093B6C: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80093B70: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80093B74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80093B78: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x80093B7C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80093B80: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80093B84: lw          $t9, 0x6C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C14);
    // 0x80093B88: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80093B8C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80093B90: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80093B94: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80093B98: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80093B9C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80093BA0: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80093BA4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80093BA8: nop

    // 0x80093BAC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80093BB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80093BB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80093BB8: nop

    // 0x80093BBC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80093BC0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80093BC4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80093BC8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80093BCC: nop

    // 0x80093BD0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80093BD4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80093BD8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80093BDC: lw          $t7, -0x788($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X788);
    // 0x80093BE0: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80093BE4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80093BE8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80093BEC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80093BF0: lbu         $t9, -0x400($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X400);
    // 0x80093BF4: nop

    // 0x80093BF8: sb          $t9, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r25;
    // 0x80093BFC: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093C00: nop

    // 0x80093C04: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80093C08: beq         $t1, $zero, L_80093C38
    if (ctx->r9 == 0) {
        // 0x80093C0C: nop

            goto L_80093C38;
    }
    // 0x80093C0C: nop

    // 0x80093C10: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093C14: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093C18: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093C1C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093C20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093C24: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093C28: jal         0x80090784
    // 0x80093C2C: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x80093C2C: nop

    after_0:
    // 0x80093C30: b           L_80093C58
    // 0x80093C34: nop

        goto L_80093C58;
    // 0x80093C34: nop

L_80093C38:
    // 0x80093C38: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093C3C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093C40: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093C44: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093C48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093C4C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093C50: jal         0x80090784
    // 0x80093C54: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80093C54: nop

    after_1:
L_80093C58:
    // 0x80093C58: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093C5C: nop

    // 0x80093C60: andi        $t4, $t2, 0x40
    ctx->r12 = ctx->r10 & 0X40;
    // 0x80093C64: beq         $t4, $zero, L_80093C94
    if (ctx->r12 == 0) {
        // 0x80093C68: nop

            goto L_80093C94;
    }
    // 0x80093C68: nop

    // 0x80093C6C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093C70: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093C74: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093C78: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093C7C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093C80: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093C84: jal         0x80090784
    // 0x80093C88: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x80093C88: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x80093C8C: b           L_80093CB4
    // 0x80093C90: nop

        goto L_80093CB4;
    // 0x80093C90: nop

L_80093C94:
    // 0x80093C94: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093C98: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093C9C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093CA0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093CA4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093CA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093CAC: jal         0x80090784
    // 0x80093CB0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x80093CB0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_80093CB4:
    // 0x80093CB4: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093CB8: nop

    // 0x80093CBC: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x80093CC0: beq         $t5, $zero, L_80093CF0
    if (ctx->r13 == 0) {
        // 0x80093CC4: nop

            goto L_80093CF0;
    }
    // 0x80093CC4: nop

    // 0x80093CC8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093CCC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093CD0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093CD4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093CD8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093CDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093CE0: jal         0x80090784
    // 0x80093CE4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x80093CE4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x80093CE8: b           L_80093D10
    // 0x80093CEC: nop

        goto L_80093D10;
    // 0x80093CEC: nop

L_80093CF0:
    // 0x80093CF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093CF4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093CF8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093CFC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093D00: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093D04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093D08: jal         0x80090784
    // 0x80093D0C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x80093D0C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80093D10:
    // 0x80093D10: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093D14: nop

    // 0x80093D18: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80093D1C: beq         $t7, $zero, L_80093D4C
    if (ctx->r15 == 0) {
        // 0x80093D20: nop

            goto L_80093D4C;
    }
    // 0x80093D20: nop

    // 0x80093D24: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093D28: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093D2C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093D30: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093D34: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093D38: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093D3C: jal         0x80090784
    // 0x80093D40: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80093D40: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80093D44: b           L_80093D6C
    // 0x80093D48: nop

        goto L_80093D6C;
    // 0x80093D48: nop

L_80093D4C:
    // 0x80093D4C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093D50: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093D54: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093D58: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093D5C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093D60: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093D64: jal         0x80090784
    // 0x80093D68: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x80093D68: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_80093D6C:
    // 0x80093D6C: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093D70: nop

    // 0x80093D74: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80093D78: beq         $t9, $zero, L_80093DA8
    if (ctx->r25 == 0) {
        // 0x80093D7C: nop

            goto L_80093DA8;
    }
    // 0x80093D7C: nop

    // 0x80093D80: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093D84: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093D88: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093D8C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093D90: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093D94: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093D98: jal         0x80090784
    // 0x80093D9C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x80093D9C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x80093DA0: b           L_80093DC8
    // 0x80093DA4: nop

        goto L_80093DC8;
    // 0x80093DA4: nop

L_80093DA8:
    // 0x80093DA8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093DAC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093DB0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093DB4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093DB8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093DBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093DC0: jal         0x80090784
    // 0x80093DC4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x80093DC4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_80093DC8:
    // 0x80093DC8: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093DCC: nop

    // 0x80093DD0: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80093DD4: beq         $t1, $zero, L_80093E04
    if (ctx->r9 == 0) {
        // 0x80093DD8: nop

            goto L_80093E04;
    }
    // 0x80093DD8: nop

    // 0x80093DDC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093DE0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093DE4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093DE8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093DEC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093DF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093DF4: jal         0x80090784
    // 0x80093DF8: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x80093DF8: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x80093DFC: b           L_80093E24
    // 0x80093E00: nop

        goto L_80093E24;
    // 0x80093E00: nop

L_80093E04:
    // 0x80093E04: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093E08: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093E0C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093E10: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093E14: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093E18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093E1C: jal         0x80090784
    // 0x80093E20: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80093E20: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80093E24:
    // 0x80093E24: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093E28: nop

    // 0x80093E2C: andi        $t4, $t2, 0x2
    ctx->r12 = ctx->r10 & 0X2;
    // 0x80093E30: beq         $t4, $zero, L_80093E60
    if (ctx->r12 == 0) {
        // 0x80093E34: nop

            goto L_80093E60;
    }
    // 0x80093E34: nop

    // 0x80093E38: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093E3C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093E40: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093E44: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093E48: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093E4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093E50: jal         0x80090784
    // 0x80093E54: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80093E54: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x80093E58: b           L_80093E80
    // 0x80093E5C: nop

        goto L_80093E80;
    // 0x80093E5C: nop

L_80093E60:
    // 0x80093E60: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093E64: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093E68: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093E6C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093E70: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093E74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093E78: jal         0x80090784
    // 0x80093E7C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x80093E7C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_80093E80:
    // 0x80093E80: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093E84: nop

    // 0x80093E88: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x80093E8C: beq         $t5, $zero, L_80093EBC
    if (ctx->r13 == 0) {
        // 0x80093E90: nop

            goto L_80093EBC;
    }
    // 0x80093E90: nop

    // 0x80093E94: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093E98: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093E9C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093EA0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093EA4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093EA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093EAC: jal         0x80090784
    // 0x80093EB0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x80093EB0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x80093EB4: b           L_80093EDC
    // 0x80093EB8: nop

        goto L_80093EDC;
    // 0x80093EB8: nop

L_80093EBC:
    // 0x80093EBC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093EC0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093EC4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093EC8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093ECC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093ED0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093ED4: jal         0x80090784
    // 0x80093ED8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x80093ED8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_80093EDC:
    // 0x80093EDC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80093EE0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80093EE4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80093EE8: lw          $t1, -0x788($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X788);
    // 0x80093EEC: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80093EF0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80093EF4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80093EF8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80093EFC: lbu         $t4, -0x3FF($t2)
    ctx->r12 = MEM_BU(ctx->r10, -0X3FF);
    // 0x80093F00: nop

    // 0x80093F04: sb          $t4, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r12;
    // 0x80093F08: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093F0C: nop

    // 0x80093F10: andi        $t5, $t3, 0x80
    ctx->r13 = ctx->r11 & 0X80;
    // 0x80093F14: beq         $t5, $zero, L_80093F44
    if (ctx->r13 == 0) {
        // 0x80093F18: nop

            goto L_80093F44;
    }
    // 0x80093F18: nop

    // 0x80093F1C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093F20: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093F24: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093F28: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093F2C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093F30: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093F34: jal         0x80090784
    // 0x80093F38: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_16;
    // 0x80093F38: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_16:
    // 0x80093F3C: b           L_80093F64
    // 0x80093F40: nop

        goto L_80093F64;
    // 0x80093F40: nop

L_80093F44:
    // 0x80093F44: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093F48: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093F4C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093F50: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093F54: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093F58: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093F5C: jal         0x80090784
    // 0x80093F60: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_17;
    // 0x80093F60: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_17:
L_80093F64:
    // 0x80093F64: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093F68: nop

    // 0x80093F6C: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80093F70: beq         $t8, $zero, L_80093FA0
    if (ctx->r24 == 0) {
        // 0x80093F74: nop

            goto L_80093FA0;
    }
    // 0x80093F74: nop

    // 0x80093F78: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093F7C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093F80: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093F84: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093F88: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093F8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093F90: jal         0x80090784
    // 0x80093F94: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_18;
    // 0x80093F94: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_18:
    // 0x80093F98: b           L_80093FC0
    // 0x80093F9C: nop

        goto L_80093FC0;
    // 0x80093F9C: nop

L_80093FA0:
    // 0x80093FA0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093FA4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093FA8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093FAC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093FB0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093FB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093FB8: jal         0x80090784
    // 0x80093FBC: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_19;
    // 0x80093FBC: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_19:
L_80093FC0:
    // 0x80093FC0: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093FC4: nop

    // 0x80093FC8: andi        $t9, $t7, 0x20
    ctx->r25 = ctx->r15 & 0X20;
    // 0x80093FCC: beq         $t9, $zero, L_80093FFC
    if (ctx->r25 == 0) {
        // 0x80093FD0: nop

            goto L_80093FFC;
    }
    // 0x80093FD0: nop

    // 0x80093FD4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093FD8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093FDC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093FE0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093FE4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093FE8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093FEC: jal         0x80090784
    // 0x80093FF0: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_20;
    // 0x80093FF0: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_20:
    // 0x80093FF4: b           L_8009401C
    // 0x80093FF8: nop

        goto L_8009401C;
    // 0x80093FF8: nop

L_80093FFC:
    // 0x80093FFC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094000: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094004: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094008: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009400C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094010: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094014: jal         0x80090784
    // 0x80094018: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_21;
    // 0x80094018: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_21:
L_8009401C:
    // 0x8009401C: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80094020: nop

    // 0x80094024: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80094028: beq         $t1, $zero, L_80094058
    if (ctx->r9 == 0) {
        // 0x8009402C: nop

            goto L_80094058;
    }
    // 0x8009402C: nop

    // 0x80094030: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094034: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094038: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009403C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094040: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094044: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094048: jal         0x80090784
    // 0x8009404C: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_22;
    // 0x8009404C: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_22:
    // 0x80094050: b           L_80094078
    // 0x80094054: nop

        goto L_80094078;
    // 0x80094054: nop

L_80094058:
    // 0x80094058: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009405C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094060: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094064: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094068: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009406C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094070: jal         0x80090784
    // 0x80094074: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_23;
    // 0x80094074: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_23:
L_80094078:
    // 0x80094078: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8009407C: nop

    // 0x80094080: andi        $t4, $t2, 0x8
    ctx->r12 = ctx->r10 & 0X8;
    // 0x80094084: beq         $t4, $zero, L_800940B4
    if (ctx->r12 == 0) {
        // 0x80094088: nop

            goto L_800940B4;
    }
    // 0x80094088: nop

    // 0x8009408C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094090: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094094: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094098: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009409C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800940A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800940A4: jal         0x80090784
    // 0x800940A8: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    func_80090784(rdram, ctx);
        goto after_24;
    // 0x800940A8: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    after_24:
    // 0x800940AC: b           L_800940D4
    // 0x800940B0: nop

        goto L_800940D4;
    // 0x800940B0: nop

L_800940B4:
    // 0x800940B4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800940B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800940BC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800940C0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800940C4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800940C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800940CC: jal         0x80090784
    // 0x800940D0: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    func_80090784(rdram, ctx);
        goto after_25;
    // 0x800940D0: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    after_25:
L_800940D4:
    // 0x800940D4: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x800940D8: nop

    // 0x800940DC: andi        $t5, $t3, 0x4
    ctx->r13 = ctx->r11 & 0X4;
    // 0x800940E0: beq         $t5, $zero, L_80094110
    if (ctx->r13 == 0) {
        // 0x800940E4: nop

            goto L_80094110;
    }
    // 0x800940E4: nop

    // 0x800940E8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800940EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800940F0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800940F4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800940F8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800940FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094100: jal         0x80090784
    // 0x80094104: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    func_80090784(rdram, ctx);
        goto after_26;
    // 0x80094104: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    after_26:
    // 0x80094108: b           L_80094130
    // 0x8009410C: nop

        goto L_80094130;
    // 0x8009410C: nop

L_80094110:
    // 0x80094110: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094114: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094118: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009411C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094120: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094124: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094128: jal         0x80090784
    // 0x8009412C: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    func_80090784(rdram, ctx);
        goto after_27;
    // 0x8009412C: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    after_27:
L_80094130:
    // 0x80094130: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80094134: nop

    // 0x80094138: andi        $t8, $t6, 0x2
    ctx->r24 = ctx->r14 & 0X2;
    // 0x8009413C: beq         $t8, $zero, L_8009416C
    if (ctx->r24 == 0) {
        // 0x80094140: nop

            goto L_8009416C;
    }
    // 0x80094140: nop

    // 0x80094144: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094148: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009414C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094150: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094154: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094158: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009415C: jal         0x80090784
    // 0x80094160: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    func_80090784(rdram, ctx);
        goto after_28;
    // 0x80094160: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    after_28:
    // 0x80094164: b           L_8009418C
    // 0x80094168: nop

        goto L_8009418C;
    // 0x80094168: nop

L_8009416C:
    // 0x8009416C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094170: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094174: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094178: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009417C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094180: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094184: jal         0x80090784
    // 0x80094188: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    func_80090784(rdram, ctx);
        goto after_29;
    // 0x80094188: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    after_29:
L_8009418C:
    // 0x8009418C: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x80094190: nop

    // 0x80094194: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80094198: beq         $t9, $zero, L_800941C8
    if (ctx->r25 == 0) {
        // 0x8009419C: nop

            goto L_800941C8;
    }
    // 0x8009419C: nop

    // 0x800941A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800941A4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800941A8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800941AC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800941B0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800941B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800941B8: jal         0x80090784
    // 0x800941BC: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    func_80090784(rdram, ctx);
        goto after_30;
    // 0x800941BC: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    after_30:
    // 0x800941C0: b           L_800941E8
    // 0x800941C4: nop

        goto L_800941E8;
    // 0x800941C4: nop

L_800941C8:
    // 0x800941C8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800941CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800941D0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800941D4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800941D8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800941DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800941E0: jal         0x80090784
    // 0x800941E4: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    func_80090784(rdram, ctx);
        goto after_31;
    // 0x800941E4: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    after_31:
L_800941E8:
    // 0x800941E8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800941EC: nop

    // 0x800941F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800941F4: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x800941F8: bne         $at, $zero, L_80093B44
    if (ctx->r1 != 0) {
        // 0x800941FC: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_80093B44;
    }
    // 0x800941FC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80094200: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80094204: lw          $t2, 0x6B98($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6B98);
    // 0x80094208: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8009420C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094210: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80094214: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x80094218: b           L_80094220
    // 0x8009421C: nop

        goto L_80094220;
    // 0x8009421C: nop

L_80094220:
    // 0x80094220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094224: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80094228: jr          $ra
    // 0x8009422C: nop

    return;
    // 0x8009422C: nop

;}
RECOMP_FUNC void func_80094230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094230: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80094234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094238: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009423C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80094240: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80094244: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80094248: nop

    // 0x8009424C: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x80094250: beq         $at, $zero, L_80094630
    if (ctx->r1 == 0) {
        // 0x80094254: nop

            goto L_80094630;
    }
    // 0x80094254: nop

    // 0x80094258: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8009425C:
    // 0x8009425C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80094260: lw          $t7, 0x6BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA0);
    // 0x80094264: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80094268: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009426C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094270: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80094274: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094278: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8009427C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80094280: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094284: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80094288: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8009428C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80094290: lw          $t9, 0x6B98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6B98);
    // 0x80094294: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80094298: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009429C: lw          $t0, 0x6C14($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C14);
    // 0x800942A0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800942A4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800942A8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800942AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800942B0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800942B4: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800942B8: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800942BC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800942C0: nop

    // 0x800942C4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800942C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800942CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800942D0: nop

    // 0x800942D4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800942D8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800942DC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800942E0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800942E4: nop

    // 0x800942E8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800942EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800942F0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800942F4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800942F8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800942FC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80094300: lw          $t8, -0x780($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X780);
    // 0x80094304: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80094308: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8009430C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80094310: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80094314: nop

    // 0x80094318: sb          $t0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r8;
    // 0x8009431C: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x80094320: nop

    // 0x80094324: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80094328: beq         $t2, $zero, L_80094358
    if (ctx->r10 == 0) {
        // 0x8009432C: nop

            goto L_80094358;
    }
    // 0x8009432C: nop

    // 0x80094330: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094334: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094338: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009433C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094340: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094344: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094348: jal         0x80090784
    // 0x8009434C: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x8009434C: nop

    after_0:
    // 0x80094350: b           L_80094378
    // 0x80094354: nop

        goto L_80094378;
    // 0x80094354: nop

L_80094358:
    // 0x80094358: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009435C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094360: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094364: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094368: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009436C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094370: jal         0x80090784
    // 0x80094374: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80094374: nop

    after_1:
L_80094378:
    // 0x80094378: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x8009437C: nop

    // 0x80094380: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x80094384: beq         $t4, $zero, L_800943B4
    if (ctx->r12 == 0) {
        // 0x80094388: nop

            goto L_800943B4;
    }
    // 0x80094388: nop

    // 0x8009438C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094390: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094394: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094398: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009439C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800943A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800943A4: jal         0x80090784
    // 0x800943A8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x800943A8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x800943AC: b           L_800943D4
    // 0x800943B0: nop

        goto L_800943D4;
    // 0x800943B0: nop

L_800943B4:
    // 0x800943B4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800943B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800943BC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800943C0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800943C4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800943C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800943CC: jal         0x80090784
    // 0x800943D0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x800943D0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_800943D4:
    // 0x800943D4: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x800943D8: nop

    // 0x800943DC: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x800943E0: beq         $t6, $zero, L_80094410
    if (ctx->r14 == 0) {
        // 0x800943E4: nop

            goto L_80094410;
    }
    // 0x800943E4: nop

    // 0x800943E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800943EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800943F0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800943F4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800943F8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800943FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094400: jal         0x80090784
    // 0x80094404: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x80094404: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x80094408: b           L_80094430
    // 0x8009440C: nop

        goto L_80094430;
    // 0x8009440C: nop

L_80094410:
    // 0x80094410: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094414: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094418: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009441C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094420: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094424: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094428: jal         0x80090784
    // 0x8009442C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x8009442C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80094430:
    // 0x80094430: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x80094434: nop

    // 0x80094438: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8009443C: beq         $t8, $zero, L_8009446C
    if (ctx->r24 == 0) {
        // 0x80094440: nop

            goto L_8009446C;
    }
    // 0x80094440: nop

    // 0x80094444: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094448: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009444C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094450: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094454: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094458: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009445C: jal         0x80090784
    // 0x80094460: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80094460: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80094464: b           L_8009448C
    // 0x80094468: nop

        goto L_8009448C;
    // 0x80094468: nop

L_8009446C:
    // 0x8009446C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094470: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094474: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094478: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009447C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094480: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094484: jal         0x80090784
    // 0x80094488: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x80094488: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_8009448C:
    // 0x8009448C: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x80094490: nop

    // 0x80094494: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80094498: beq         $t0, $zero, L_800944C8
    if (ctx->r8 == 0) {
        // 0x8009449C: nop

            goto L_800944C8;
    }
    // 0x8009449C: nop

    // 0x800944A0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800944A4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800944A8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800944AC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800944B0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800944B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800944B8: jal         0x80090784
    // 0x800944BC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x800944BC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x800944C0: b           L_800944E8
    // 0x800944C4: nop

        goto L_800944E8;
    // 0x800944C4: nop

L_800944C8:
    // 0x800944C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800944CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800944D0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800944D4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800944D8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800944DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800944E0: jal         0x80090784
    // 0x800944E4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x800944E4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_800944E8:
    // 0x800944E8: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x800944EC: nop

    // 0x800944F0: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800944F4: beq         $t2, $zero, L_80094524
    if (ctx->r10 == 0) {
        // 0x800944F8: nop

            goto L_80094524;
    }
    // 0x800944F8: nop

    // 0x800944FC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094500: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094504: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094508: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009450C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094510: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094514: jal         0x80090784
    // 0x80094518: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x80094518: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x8009451C: b           L_80094544
    // 0x80094520: nop

        goto L_80094544;
    // 0x80094520: nop

L_80094524:
    // 0x80094524: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094528: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009452C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094530: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094534: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094538: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009453C: jal         0x80090784
    // 0x80094540: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80094540: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80094544:
    // 0x80094544: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x80094548: nop

    // 0x8009454C: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80094550: beq         $t4, $zero, L_80094580
    if (ctx->r12 == 0) {
        // 0x80094554: nop

            goto L_80094580;
    }
    // 0x80094554: nop

    // 0x80094558: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009455C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094560: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094564: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094568: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009456C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094570: jal         0x80090784
    // 0x80094574: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80094574: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x80094578: b           L_800945A0
    // 0x8009457C: nop

        goto L_800945A0;
    // 0x8009457C: nop

L_80094580:
    // 0x80094580: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094584: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094588: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009458C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094590: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094594: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094598: jal         0x80090784
    // 0x8009459C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x8009459C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_800945A0:
    // 0x800945A0: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x800945A4: nop

    // 0x800945A8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800945AC: beq         $t6, $zero, L_800945DC
    if (ctx->r14 == 0) {
        // 0x800945B0: nop

            goto L_800945DC;
    }
    // 0x800945B0: nop

    // 0x800945B4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800945B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800945BC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800945C0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800945C4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800945C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800945CC: jal         0x80090784
    // 0x800945D0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x800945D0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x800945D4: b           L_800945FC
    // 0x800945D8: nop

        goto L_800945FC;
    // 0x800945D8: nop

L_800945DC:
    // 0x800945DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800945E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800945E4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800945E8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800945EC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800945F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800945F4: jal         0x80090784
    // 0x800945F8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x800945F8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_800945FC:
    // 0x800945FC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80094600: nop

    // 0x80094604: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80094608: slti        $at, $t8, 0xC
    ctx->r1 = SIGNED(ctx->r24) < 0XC ? 1 : 0;
    // 0x8009460C: bne         $at, $zero, L_8009425C
    if (ctx->r1 != 0) {
        // 0x80094610: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_8009425C;
    }
    // 0x80094610: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80094614: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80094618: lw          $t9, 0x6B98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6B98);
    // 0x8009461C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80094620: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094624: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80094628: b           L_80095E60
    // 0x8009462C: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
        goto L_80095E60;
    // 0x8009462C: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
L_80094630:
    // 0x80094630: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80094634: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x80094638: nop

    // 0x8009463C: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x80094640: bne         $t3, $zero, L_80094BB8
    if (ctx->r11 != 0) {
        // 0x80094644: nop

            goto L_80094BB8;
    }
    // 0x80094644: nop

    // 0x80094648: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8009464C:
    // 0x8009464C: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80094650: lw          $t4, 0x6BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA0);
    // 0x80094654: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80094658: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8009465C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094660: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80094664: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094668: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8009466C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80094670: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094674: lwc1        $f8, -0x4510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80094678: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8009467C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80094680: lw          $t6, 0x6B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B98);
    // 0x80094684: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80094688: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8009468C: lw          $t7, 0x6C14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C14);
    // 0x80094690: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80094694: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80094698: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8009469C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800946A0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800946A4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800946A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800946AC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800946B0: nop

    // 0x800946B4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800946B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800946BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800946C0: nop

    // 0x800946C4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800946C8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800946CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800946D0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800946D4: nop

    // 0x800946D8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800946DC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800946E0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800946E4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800946E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800946EC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800946F0: lw          $t6, -0x780($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X780);
    // 0x800946F4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800946F8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800946FC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80094700: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80094704: lbu         $t8, -0x1200($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1200);
    // 0x80094708: nop

    // 0x8009470C: sb          $t8, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r24;
    // 0x80094710: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x80094714: nop

    // 0x80094718: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x8009471C: beq         $t0, $zero, L_8009474C
    if (ctx->r8 == 0) {
        // 0x80094720: nop

            goto L_8009474C;
    }
    // 0x80094720: nop

    // 0x80094724: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094728: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009472C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094730: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094734: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094738: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009473C: jal         0x80090784
    // 0x80094740: nop

    func_80090784(rdram, ctx);
        goto after_16;
    // 0x80094740: nop

    after_16:
    // 0x80094744: b           L_8009476C
    // 0x80094748: nop

        goto L_8009476C;
    // 0x80094748: nop

L_8009474C:
    // 0x8009474C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094750: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094754: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094758: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009475C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094760: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094764: jal         0x80090784
    // 0x80094768: nop

    func_80090784(rdram, ctx);
        goto after_17;
    // 0x80094768: nop

    after_17:
L_8009476C:
    // 0x8009476C: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x80094770: nop

    // 0x80094774: andi        $t3, $t1, 0x40
    ctx->r11 = ctx->r9 & 0X40;
    // 0x80094778: beq         $t3, $zero, L_800947A8
    if (ctx->r11 == 0) {
        // 0x8009477C: nop

            goto L_800947A8;
    }
    // 0x8009477C: nop

    // 0x80094780: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094784: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094788: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009478C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094790: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094794: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094798: jal         0x80090784
    // 0x8009479C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_18;
    // 0x8009479C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_18:
    // 0x800947A0: b           L_800947C8
    // 0x800947A4: nop

        goto L_800947C8;
    // 0x800947A4: nop

L_800947A8:
    // 0x800947A8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800947AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800947B0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800947B4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800947B8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800947BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800947C0: jal         0x80090784
    // 0x800947C4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_19;
    // 0x800947C4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_19:
L_800947C8:
    // 0x800947C8: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x800947CC: nop

    // 0x800947D0: andi        $t4, $t2, 0x20
    ctx->r12 = ctx->r10 & 0X20;
    // 0x800947D4: beq         $t4, $zero, L_80094804
    if (ctx->r12 == 0) {
        // 0x800947D8: nop

            goto L_80094804;
    }
    // 0x800947D8: nop

    // 0x800947DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800947E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800947E4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800947E8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800947EC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800947F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800947F4: jal         0x80090784
    // 0x800947F8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_20;
    // 0x800947F8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_20:
    // 0x800947FC: b           L_80094824
    // 0x80094800: nop

        goto L_80094824;
    // 0x80094800: nop

L_80094804:
    // 0x80094804: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094808: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009480C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094810: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094814: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094818: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009481C: jal         0x80090784
    // 0x80094820: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_21;
    // 0x80094820: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_21:
L_80094824:
    // 0x80094824: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x80094828: nop

    // 0x8009482C: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80094830: beq         $t6, $zero, L_80094860
    if (ctx->r14 == 0) {
        // 0x80094834: nop

            goto L_80094860;
    }
    // 0x80094834: nop

    // 0x80094838: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009483C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094840: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094844: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094848: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009484C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094850: jal         0x80090784
    // 0x80094854: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_22;
    // 0x80094854: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_22:
    // 0x80094858: b           L_80094880
    // 0x8009485C: nop

        goto L_80094880;
    // 0x8009485C: nop

L_80094860:
    // 0x80094860: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094864: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094868: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009486C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094870: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094874: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094878: jal         0x80090784
    // 0x8009487C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_23;
    // 0x8009487C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_23:
L_80094880:
    // 0x80094880: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x80094884: nop

    // 0x80094888: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8009488C: beq         $t8, $zero, L_800948BC
    if (ctx->r24 == 0) {
        // 0x80094890: nop

            goto L_800948BC;
    }
    // 0x80094890: nop

    // 0x80094894: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094898: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009489C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800948A0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800948A4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800948A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800948AC: jal         0x80090784
    // 0x800948B0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_24;
    // 0x800948B0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_24:
    // 0x800948B4: b           L_800948DC
    // 0x800948B8: nop

        goto L_800948DC;
    // 0x800948B8: nop

L_800948BC:
    // 0x800948BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800948C0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800948C4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800948C8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800948CC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800948D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800948D4: jal         0x80090784
    // 0x800948D8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_25;
    // 0x800948D8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_25:
L_800948DC:
    // 0x800948DC: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x800948E0: nop

    // 0x800948E4: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x800948E8: beq         $t0, $zero, L_80094918
    if (ctx->r8 == 0) {
        // 0x800948EC: nop

            goto L_80094918;
    }
    // 0x800948EC: nop

    // 0x800948F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800948F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800948F8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800948FC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094900: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094904: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094908: jal         0x80090784
    // 0x8009490C: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_26;
    // 0x8009490C: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_26:
    // 0x80094910: b           L_80094938
    // 0x80094914: nop

        goto L_80094938;
    // 0x80094914: nop

L_80094918:
    // 0x80094918: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009491C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094920: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094924: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094928: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009492C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094930: jal         0x80090784
    // 0x80094934: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_27;
    // 0x80094934: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_27:
L_80094938:
    // 0x80094938: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x8009493C: nop

    // 0x80094940: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x80094944: beq         $t3, $zero, L_80094974
    if (ctx->r11 == 0) {
        // 0x80094948: nop

            goto L_80094974;
    }
    // 0x80094948: nop

    // 0x8009494C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094950: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094954: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094958: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009495C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094960: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094964: jal         0x80090784
    // 0x80094968: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_28;
    // 0x80094968: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_28:
    // 0x8009496C: b           L_80094994
    // 0x80094970: nop

        goto L_80094994;
    // 0x80094970: nop

L_80094974:
    // 0x80094974: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094978: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009497C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094980: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094984: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094988: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009498C: jal         0x80090784
    // 0x80094990: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_29;
    // 0x80094990: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_29:
L_80094994:
    // 0x80094994: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80094998: beq         $t2, $zero, L_800949F0
    if (ctx->r10 == 0) {
        // 0x8009499C: nop

            goto L_800949F0;
    }
    // 0x8009499C: nop

    // 0x800949A0: b           L_80094B3C
    // 0x800949A4: nop

        goto L_80094B3C;
    // 0x800949A4: nop

    // 0x800949A8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800949AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800949B0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800949B4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800949B8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800949BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800949C0: jal         0x80090784
    // 0x800949C4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_30;
    // 0x800949C4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_30:
    // 0x800949C8: b           L_800949F0
    // 0x800949CC: nop

        goto L_800949F0;
    // 0x800949CC: nop

    // 0x800949D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800949D4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800949D8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800949DC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800949E0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800949E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800949E8: jal         0x80090784
    // 0x800949EC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_31;
    // 0x800949EC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_31:
L_800949F0:
    // 0x800949F0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800949F4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800949F8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800949FC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80094A00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80094A04: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80094A08: lw          $t1, -0x780($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X780);
    // 0x80094A0C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80094A10: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80094A14: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80094A18: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80094A1C: lbu         $t2, -0x11FF($t3)
    ctx->r10 = MEM_BU(ctx->r11, -0X11FF);
    // 0x80094A20: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80094A24: beq         $zero, $t2, L_80094B3C
    if (0 == ctx->r10) {
        // 0x80094A28: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_80094B3C;
    }
    // 0x80094A28: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80094A2C: sltiu       $t0, $t2, 0x9
    ctx->r8 = ctx->r10 < 0X9 ? 1 : 0;
    // 0x80094A30: beq         $zero, $t0, L_80094B3C
    if (0 == ctx->r8) {
        // 0x80094A34: nop

            goto L_80094B3C;
    }
    // 0x80094A34: nop

    // 0x80094A38: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x80094A3C: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80094A40: addiu       $t4, $t4, -0x47B4
    ctx->r12 = ADD32(ctx->r12, -0X47B4);
    // 0x80094A44: beq         $t4, $t0, L_80094B3C
    if (ctx->r12 == ctx->r8) {
        // 0x80094A48: nop

            goto L_80094B3C;
    }
    // 0x80094A48: nop

    // 0x80094A4C: srl         $t4, $t2, 1
    ctx->r12 = S32(U32(ctx->r10) >> 1);
    // 0x80094A50: b           L_80094B3C
    // 0x80094A54: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
        goto L_80094B3C;
    // 0x80094A54: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80094A58: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80094A5C: b           L_80094A84
    // 0x80094A60: nop

        goto L_80094A84;
    // 0x80094A60: nop

    // 0x80094A64: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094A68: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094A6C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094A70: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094A74: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094A78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094A7C: jal         0x80090784
    // 0x80094A80: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_32;
    // 0x80094A80: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_32:
L_80094A84:
    // 0x80094A84: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80094A88: nop

    // 0x80094A8C: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80094A90: beq         $t8, $zero, L_80094AC0
    if (ctx->r24 == 0) {
        // 0x80094A94: nop

            goto L_80094AC0;
    }
    // 0x80094A94: nop

    // 0x80094A98: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094A9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094AA0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094AA4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094AA8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094AAC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094AB0: jal         0x80090784
    // 0x80094AB4: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_33;
    // 0x80094AB4: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_33:
    // 0x80094AB8: b           L_80094AE0
    // 0x80094ABC: nop

        goto L_80094AE0;
    // 0x80094ABC: nop

L_80094AC0:
    // 0x80094AC0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094AC4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094AC8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094ACC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094AD0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094AD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094AD8: jal         0x80090784
    // 0x80094ADC: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_34;
    // 0x80094ADC: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_34:
L_80094AE0:
    // 0x80094AE0: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x80094AE4: nop

    // 0x80094AE8: andi        $t9, $t7, 0x20
    ctx->r25 = ctx->r15 & 0X20;
    // 0x80094AEC: beq         $t9, $zero, L_80094B1C
    if (ctx->r25 == 0) {
        // 0x80094AF0: nop

            goto L_80094B1C;
    }
    // 0x80094AF0: nop

    // 0x80094AF4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094AF8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094AFC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094B00: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094B04: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B0C: jal         0x80090784
    // 0x80094B10: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_35;
    // 0x80094B10: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_35:
    // 0x80094B14: b           L_80094B3C
    // 0x80094B18: nop

        goto L_80094B3C;
    // 0x80094B18: nop

L_80094B1C:
    // 0x80094B1C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094B20: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094B24: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094B28: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094B2C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094B30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B34: jal         0x80090784
    // 0x80094B38: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_36;
    // 0x80094B38: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_36:
L_80094B3C:
    // 0x80094B3C: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x80094B40: nop

    // 0x80094B44: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80094B48: beq         $t1, $zero, L_80094B78
    if (ctx->r9 == 0) {
        // 0x80094B4C: nop

            goto L_80094B78;
    }
    // 0x80094B4C: nop

    // 0x80094B50: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094B54: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094B58: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094B5C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094B60: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094B64: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B68: jal         0x80090784
    // 0x80094B6C: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_37;
    // 0x80094B6C: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_37:
    // 0x80094B70: b           L_80094B98
    // 0x80094B74: nop

        goto L_80094B98;
    // 0x80094B74: nop

L_80094B78:
    // 0x80094B78: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094B7C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094B80: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094B84: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094B88: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094B8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B90: jal         0x80090784
    // 0x80094B94: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_38;
    // 0x80094B94: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_38:
L_80094B98:
    // 0x80094B98: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B9C: nop

    // 0x80094BA0: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80094BA4: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x80094BA8: bne         $at, $zero, L_8009464C
    if (ctx->r1 != 0) {
        // 0x80094BAC: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_8009464C;
    }
    // 0x80094BAC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80094BB0: b           L_80095E44
    // 0x80094BB4: nop

        goto L_80095E44;
    // 0x80094BB4: nop

L_80094BB8:
    // 0x80094BB8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80094BBC:
    // 0x80094BBC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80094BC0: lw          $t4, 0x6BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA0);
    // 0x80094BC4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80094BC8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80094BCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094BD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80094BD4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80094BD8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80094BDC: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094BE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80094BE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094BE8: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80094BEC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80094BF0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80094BF4: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x80094BF8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80094BFC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80094C00: lw          $t7, 0x6C14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C14);
    // 0x80094C04: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80094C08: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80094C0C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80094C10: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80094C14: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80094C18: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80094C1C: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80094C20: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80094C24: nop

    // 0x80094C28: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80094C2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80094C30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80094C34: nop

    // 0x80094C38: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80094C3C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80094C40: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80094C44: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80094C48: nop

    // 0x80094C4C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80094C50: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80094C54: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80094C58: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80094C5C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80094C60: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80094C64: lw          $t8, -0x780($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X780);
    // 0x80094C68: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x80094C6C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80094C70: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80094C74: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80094C78: lbu         $t9, -0x1200($t7)
    ctx->r25 = MEM_BU(ctx->r15, -0X1200);
    // 0x80094C7C: nop

    // 0x80094C80: sb          $t9, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r25;
    // 0x80094C84: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x80094C88: nop

    // 0x80094C8C: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80094C90: beq         $t1, $zero, L_80094D4C
    if (ctx->r9 == 0) {
        // 0x80094C94: nop

            goto L_80094D4C;
    }
    // 0x80094C94: nop

    // 0x80094C98: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094C9C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80094CA0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80094CA4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80094CA8: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094CAC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094CB0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80094CB4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094CB8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80094CBC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094CC0: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80094CC4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094CC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094CCC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094CD0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80094CD4: beq         $t4, $zero, L_80094D28
    if (ctx->r12 == 0) {
        // 0x80094CD8: nop

            goto L_80094D28;
    }
    // 0x80094CD8: nop

    // 0x80094CDC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094CE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80094CE4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80094CE8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80094CEC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80094CF0: nop

    // 0x80094CF4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80094CF8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80094CFC: nop

    // 0x80094D00: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80094D04: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80094D08: bne         $t4, $zero, L_80094D20
    if (ctx->r12 != 0) {
        // 0x80094D0C: nop

            goto L_80094D20;
    }
    // 0x80094D0C: nop

    // 0x80094D10: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80094D14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094D18: b           L_80094D38
    // 0x80094D1C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80094D38;
    // 0x80094D1C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80094D20:
    // 0x80094D20: b           L_80094D38
    // 0x80094D24: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80094D38;
    // 0x80094D24: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80094D28:
    // 0x80094D28: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80094D2C: nop

    // 0x80094D30: bltz        $t4, L_80094D20
    if (SIGNED(ctx->r12) < 0) {
        // 0x80094D34: nop

            goto L_80094D20;
    }
    // 0x80094D34: nop

L_80094D38:
    // 0x80094D38: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80094D3C: jal         0x800908A0
    // 0x80094D40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800908A0(rdram, ctx);
        goto after_39;
    // 0x80094D40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_39:
    // 0x80094D44: b           L_80094DF8
    // 0x80094D48: nop

        goto L_80094DF8;
    // 0x80094D48: nop

L_80094D4C:
    // 0x80094D4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094D50: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80094D54: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094D58: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80094D5C: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094D60: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094D64: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80094D68: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094D6C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80094D70: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094D74: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80094D78: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094D7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094D80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094D84: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80094D88: beq         $t5, $zero, L_80094DDC
    if (ctx->r13 == 0) {
        // 0x80094D8C: nop

            goto L_80094DDC;
    }
    // 0x80094D8C: nop

    // 0x80094D90: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094D94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80094D98: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094D9C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80094DA0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80094DA4: nop

    // 0x80094DA8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80094DAC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80094DB0: nop

    // 0x80094DB4: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80094DB8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80094DBC: bne         $t5, $zero, L_80094DD4
    if (ctx->r13 != 0) {
        // 0x80094DC0: nop

            goto L_80094DD4;
    }
    // 0x80094DC0: nop

    // 0x80094DC4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80094DC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094DCC: b           L_80094DEC
    // 0x80094DD0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80094DEC;
    // 0x80094DD0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80094DD4:
    // 0x80094DD4: b           L_80094DEC
    // 0x80094DD8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80094DEC;
    // 0x80094DD8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80094DDC:
    // 0x80094DDC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80094DE0: nop

    // 0x80094DE4: bltz        $t5, L_80094DD4
    if (SIGNED(ctx->r13) < 0) {
        // 0x80094DE8: nop

            goto L_80094DD4;
    }
    // 0x80094DE8: nop

L_80094DEC:
    // 0x80094DEC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80094DF0: jal         0x800908A0
    // 0x80094DF4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_40;
    // 0x80094DF4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_40:
L_80094DF8:
    // 0x80094DF8: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80094DFC: nop

    // 0x80094E00: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80094E04: beq         $t8, $zero, L_80094EC0
    if (ctx->r24 == 0) {
        // 0x80094E08: nop

            goto L_80094EC0;
    }
    // 0x80094E08: nop

    // 0x80094E0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094E10: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80094E14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80094E18: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80094E1C: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094E20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094E24: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80094E28: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094E2C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80094E30: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094E34: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80094E38: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094E3C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094E40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094E44: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80094E48: beq         $t9, $zero, L_80094E9C
    if (ctx->r25 == 0) {
        // 0x80094E4C: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80094E9C;
    }
    // 0x80094E4C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80094E50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094E54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80094E58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80094E5C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80094E60: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80094E64: nop

    // 0x80094E68: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80094E6C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80094E70: nop

    // 0x80094E74: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80094E78: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80094E7C: bne         $t9, $zero, L_80094E94
    if (ctx->r25 != 0) {
        // 0x80094E80: nop

            goto L_80094E94;
    }
    // 0x80094E80: nop

    // 0x80094E84: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80094E88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094E8C: b           L_80094EAC
    // 0x80094E90: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80094EAC;
    // 0x80094E90: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80094E94:
    // 0x80094E94: b           L_80094EAC
    // 0x80094E98: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80094EAC;
    // 0x80094E98: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80094E9C:
    // 0x80094E9C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80094EA0: nop

    // 0x80094EA4: bltz        $t9, L_80094E94
    if (SIGNED(ctx->r25) < 0) {
        // 0x80094EA8: nop

            goto L_80094E94;
    }
    // 0x80094EA8: nop

L_80094EAC:
    // 0x80094EAC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80094EB0: jal         0x800908A0
    // 0x80094EB4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_41;
    // 0x80094EB4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_41:
    // 0x80094EB8: b           L_80094F6C
    // 0x80094EBC: nop

        goto L_80094F6C;
    // 0x80094EBC: nop

L_80094EC0:
    // 0x80094EC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094EC4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80094EC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80094ECC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80094ED0: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094ED4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094ED8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80094EDC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094EE0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80094EE4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094EE8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80094EEC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094EF0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094EF4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094EF8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80094EFC: beq         $t1, $zero, L_80094F50
    if (ctx->r9 == 0) {
        // 0x80094F00: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80094F50;
    }
    // 0x80094F00: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80094F04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094F08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80094F0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80094F10: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80094F14: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80094F18: nop

    // 0x80094F1C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80094F20: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80094F24: nop

    // 0x80094F28: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80094F2C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80094F30: bne         $t1, $zero, L_80094F48
    if (ctx->r9 != 0) {
        // 0x80094F34: nop

            goto L_80094F48;
    }
    // 0x80094F34: nop

    // 0x80094F38: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80094F3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094F40: b           L_80094F60
    // 0x80094F44: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80094F60;
    // 0x80094F44: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80094F48:
    // 0x80094F48: b           L_80094F60
    // 0x80094F4C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80094F60;
    // 0x80094F4C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80094F50:
    // 0x80094F50: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80094F54: nop

    // 0x80094F58: bltz        $t1, L_80094F48
    if (SIGNED(ctx->r9) < 0) {
        // 0x80094F5C: nop

            goto L_80094F48;
    }
    // 0x80094F5C: nop

L_80094F60:
    // 0x80094F60: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80094F64: jal         0x800908A0
    // 0x80094F68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_42;
    // 0x80094F68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_42:
L_80094F6C:
    // 0x80094F6C: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x80094F70: nop

    // 0x80094F74: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80094F78: beq         $t4, $zero, L_80095034
    if (ctx->r12 == 0) {
        // 0x80094F7C: nop

            goto L_80095034;
    }
    // 0x80094F7C: nop

    // 0x80094F80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094F84: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80094F88: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094F8C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80094F90: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094F94: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094F98: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80094F9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094FA0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80094FA4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094FA8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80094FAC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094FB0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094FB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094FB8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80094FBC: beq         $t5, $zero, L_80095010
    if (ctx->r13 == 0) {
        // 0x80094FC0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80095010;
    }
    // 0x80094FC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80094FC4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094FC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80094FCC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094FD0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80094FD4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80094FD8: nop

    // 0x80094FDC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80094FE0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80094FE4: nop

    // 0x80094FE8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80094FEC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80094FF0: bne         $t5, $zero, L_80095008
    if (ctx->r13 != 0) {
        // 0x80094FF4: nop

            goto L_80095008;
    }
    // 0x80094FF4: nop

    // 0x80094FF8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80094FFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095000: b           L_80095020
    // 0x80095004: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80095020;
    // 0x80095004: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80095008:
    // 0x80095008: b           L_80095020
    // 0x8009500C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80095020;
    // 0x8009500C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80095010:
    // 0x80095010: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80095014: nop

    // 0x80095018: bltz        $t5, L_80095008
    if (SIGNED(ctx->r13) < 0) {
        // 0x8009501C: nop

            goto L_80095008;
    }
    // 0x8009501C: nop

L_80095020:
    // 0x80095020: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095024: jal         0x800908A0
    // 0x80095028: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_43;
    // 0x80095028: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_43:
    // 0x8009502C: b           L_800950E0
    // 0x80095030: nop

        goto L_800950E0;
    // 0x80095030: nop

L_80095034:
    // 0x80095034: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095038: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009503C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095040: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095044: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095048: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009504C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095050: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095054: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80095058: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009505C: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80095060: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095064: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095068: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009506C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80095070: beq         $t8, $zero, L_800950C4
    if (ctx->r24 == 0) {
        // 0x80095074: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800950C4;
    }
    // 0x80095074: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80095078: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009507C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095080: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095084: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095088: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8009508C: nop

    // 0x80095090: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095094: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80095098: nop

    // 0x8009509C: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800950A0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800950A4: bne         $t8, $zero, L_800950BC
    if (ctx->r24 != 0) {
        // 0x800950A8: nop

            goto L_800950BC;
    }
    // 0x800950A8: nop

    // 0x800950AC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800950B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800950B4: b           L_800950D4
    // 0x800950B8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800950D4;
    // 0x800950B8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800950BC:
    // 0x800950BC: b           L_800950D4
    // 0x800950C0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800950D4;
    // 0x800950C0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800950C4:
    // 0x800950C4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800950C8: nop

    // 0x800950CC: bltz        $t8, L_800950BC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800950D0: nop

            goto L_800950BC;
    }
    // 0x800950D0: nop

L_800950D4:
    // 0x800950D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800950D8: jal         0x800908A0
    // 0x800950DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_44;
    // 0x800950DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_44:
L_800950E0:
    // 0x800950E0: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x800950E4: nop

    // 0x800950E8: andi        $t9, $t7, 0x10
    ctx->r25 = ctx->r15 & 0X10;
    // 0x800950EC: beq         $t9, $zero, L_800951A8
    if (ctx->r25 == 0) {
        // 0x800950F0: nop

            goto L_800951A8;
    }
    // 0x800950F0: nop

    // 0x800950F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800950F8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800950FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095100: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095104: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095108: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009510C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095110: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095114: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095118: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009511C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095120: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095124: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095128: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009512C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095130: beq         $t1, $zero, L_80095184
    if (ctx->r9 == 0) {
        // 0x80095134: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_80095184;
    }
    // 0x80095134: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80095138: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009513C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095140: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095144: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80095148: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009514C: nop

    // 0x80095150: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80095154: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095158: nop

    // 0x8009515C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095160: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095164: bne         $t1, $zero, L_8009517C
    if (ctx->r9 != 0) {
        // 0x80095168: nop

            goto L_8009517C;
    }
    // 0x80095168: nop

    // 0x8009516C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80095170: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095174: b           L_80095194
    // 0x80095178: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80095194;
    // 0x80095178: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8009517C:
    // 0x8009517C: b           L_80095194
    // 0x80095180: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80095194;
    // 0x80095180: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80095184:
    // 0x80095184: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80095188: nop

    // 0x8009518C: bltz        $t1, L_8009517C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80095190: nop

            goto L_8009517C;
    }
    // 0x80095190: nop

L_80095194:
    // 0x80095194: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80095198: jal         0x800908A0
    // 0x8009519C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_45;
    // 0x8009519C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_45:
    // 0x800951A0: b           L_80095254
    // 0x800951A4: nop

        goto L_80095254;
    // 0x800951A4: nop

L_800951A8:
    // 0x800951A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800951AC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800951B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800951B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800951B8: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800951BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800951C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800951C4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800951C8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800951CC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800951D0: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800951D4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800951D8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800951DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800951E0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800951E4: beq         $t4, $zero, L_80095238
    if (ctx->r12 == 0) {
        // 0x800951E8: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_80095238;
    }
    // 0x800951E8: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x800951EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800951F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800951F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800951F8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800951FC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80095200: nop

    // 0x80095204: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80095208: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8009520C: nop

    // 0x80095210: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80095214: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80095218: bne         $t4, $zero, L_80095230
    if (ctx->r12 != 0) {
        // 0x8009521C: nop

            goto L_80095230;
    }
    // 0x8009521C: nop

    // 0x80095220: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80095224: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095228: b           L_80095248
    // 0x8009522C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80095248;
    // 0x8009522C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80095230:
    // 0x80095230: b           L_80095248
    // 0x80095234: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80095248;
    // 0x80095234: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80095238:
    // 0x80095238: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8009523C: nop

    // 0x80095240: bltz        $t4, L_80095230
    if (SIGNED(ctx->r12) < 0) {
        // 0x80095244: nop

            goto L_80095230;
    }
    // 0x80095244: nop

L_80095248:
    // 0x80095248: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009524C: jal         0x800908A0
    // 0x80095250: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800908A0(rdram, ctx);
        goto after_46;
    // 0x80095250: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_46:
L_80095254:
    // 0x80095254: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x80095258: nop

    // 0x8009525C: andi        $t5, $t2, 0x8
    ctx->r13 = ctx->r10 & 0X8;
    // 0x80095260: beq         $t5, $zero, L_8009531C
    if (ctx->r13 == 0) {
        // 0x80095264: nop

            goto L_8009531C;
    }
    // 0x80095264: nop

    // 0x80095268: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009526C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80095270: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095274: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095278: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009527C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095280: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095284: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095288: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009528C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095290: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80095294: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095298: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009529C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800952A0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800952A4: beq         $t8, $zero, L_800952F8
    if (ctx->r24 == 0) {
        // 0x800952A8: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800952F8;
    }
    // 0x800952A8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800952AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800952B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800952B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800952B8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800952BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800952C0: nop

    // 0x800952C4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800952C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800952CC: nop

    // 0x800952D0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800952D4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800952D8: bne         $t8, $zero, L_800952F0
    if (ctx->r24 != 0) {
        // 0x800952DC: nop

            goto L_800952F0;
    }
    // 0x800952DC: nop

    // 0x800952E0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800952E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800952E8: b           L_80095308
    // 0x800952EC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80095308;
    // 0x800952EC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800952F0:
    // 0x800952F0: b           L_80095308
    // 0x800952F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80095308;
    // 0x800952F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800952F8:
    // 0x800952F8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800952FC: nop

    // 0x80095300: bltz        $t8, L_800952F0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80095304: nop

            goto L_800952F0;
    }
    // 0x80095304: nop

L_80095308:
    // 0x80095308: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009530C: jal         0x800908A0
    // 0x80095310: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_47;
    // 0x80095310: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_47:
    // 0x80095314: b           L_800953C8
    // 0x80095318: nop

        goto L_800953C8;
    // 0x80095318: nop

L_8009531C:
    // 0x8009531C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095320: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095324: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80095328: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8009532C: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095330: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095334: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095338: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009533C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095340: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095344: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80095348: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009534C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095350: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095354: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80095358: beq         $t9, $zero, L_800953AC
    if (ctx->r25 == 0) {
        // 0x8009535C: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800953AC;
    }
    // 0x8009535C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80095360: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095364: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095368: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009536C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80095370: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80095374: nop

    // 0x80095378: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009537C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095380: nop

    // 0x80095384: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80095388: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8009538C: bne         $t9, $zero, L_800953A4
    if (ctx->r25 != 0) {
        // 0x80095390: nop

            goto L_800953A4;
    }
    // 0x80095390: nop

    // 0x80095394: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80095398: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009539C: b           L_800953BC
    // 0x800953A0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800953BC;
    // 0x800953A0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800953A4:
    // 0x800953A4: b           L_800953BC
    // 0x800953A8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800953BC;
    // 0x800953A8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800953AC:
    // 0x800953AC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800953B0: nop

    // 0x800953B4: bltz        $t9, L_800953A4
    if (SIGNED(ctx->r25) < 0) {
        // 0x800953B8: nop

            goto L_800953A4;
    }
    // 0x800953B8: nop

L_800953BC:
    // 0x800953BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800953C0: jal         0x800908A0
    // 0x800953C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_48;
    // 0x800953C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_48:
L_800953C8:
    // 0x800953C8: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x800953CC: nop

    // 0x800953D0: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x800953D4: beq         $t1, $zero, L_80095490
    if (ctx->r9 == 0) {
        // 0x800953D8: nop

            goto L_80095490;
    }
    // 0x800953D8: nop

    // 0x800953DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800953E0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800953E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800953E8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800953EC: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800953F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800953F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800953F8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800953FC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80095400: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095404: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80095408: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009540C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095410: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095414: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80095418: beq         $t4, $zero, L_8009546C
    if (ctx->r12 == 0) {
        // 0x8009541C: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_8009546C;
    }
    // 0x8009541C: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x80095420: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095424: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095428: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009542C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095430: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80095434: nop

    // 0x80095438: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8009543C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80095440: nop

    // 0x80095444: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80095448: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8009544C: bne         $t4, $zero, L_80095464
    if (ctx->r12 != 0) {
        // 0x80095450: nop

            goto L_80095464;
    }
    // 0x80095450: nop

    // 0x80095454: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80095458: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009545C: b           L_8009547C
    // 0x80095460: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8009547C;
    // 0x80095460: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80095464:
    // 0x80095464: b           L_8009547C
    // 0x80095468: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8009547C;
    // 0x80095468: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_8009546C:
    // 0x8009546C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80095470: nop

    // 0x80095474: bltz        $t4, L_80095464
    if (SIGNED(ctx->r12) < 0) {
        // 0x80095478: nop

            goto L_80095464;
    }
    // 0x80095478: nop

L_8009547C:
    // 0x8009547C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80095480: jal         0x800908A0
    // 0x80095484: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800908A0(rdram, ctx);
        goto after_49;
    // 0x80095484: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_49:
    // 0x80095488: b           L_8009553C
    // 0x8009548C: nop

        goto L_8009553C;
    // 0x8009548C: nop

L_80095490:
    // 0x80095490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095494: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80095498: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009549C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800954A0: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800954A4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800954A8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800954AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800954B0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800954B4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800954B8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800954BC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800954C0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800954C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800954C8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800954CC: beq         $t5, $zero, L_80095520
    if (ctx->r13 == 0) {
        // 0x800954D0: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_80095520;
    }
    // 0x800954D0: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x800954D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800954D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800954DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800954E0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800954E4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800954E8: nop

    // 0x800954EC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800954F0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800954F4: nop

    // 0x800954F8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800954FC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80095500: bne         $t5, $zero, L_80095518
    if (ctx->r13 != 0) {
        // 0x80095504: nop

            goto L_80095518;
    }
    // 0x80095504: nop

    // 0x80095508: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8009550C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095510: b           L_80095530
    // 0x80095514: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80095530;
    // 0x80095514: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80095518:
    // 0x80095518: b           L_80095530
    // 0x8009551C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80095530;
    // 0x8009551C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80095520:
    // 0x80095520: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80095524: nop

    // 0x80095528: bltz        $t5, L_80095518
    if (SIGNED(ctx->r13) < 0) {
        // 0x8009552C: nop

            goto L_80095518;
    }
    // 0x8009552C: nop

L_80095530:
    // 0x80095530: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095534: jal         0x800908A0
    // 0x80095538: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_50;
    // 0x80095538: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_50:
L_8009553C:
    // 0x8009553C: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80095540: nop

    // 0x80095544: andi        $t8, $t6, 0x2
    ctx->r24 = ctx->r14 & 0X2;
    // 0x80095548: beq         $t8, $zero, L_80095604
    if (ctx->r24 == 0) {
        // 0x8009554C: nop

            goto L_80095604;
    }
    // 0x8009554C: nop

    // 0x80095550: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095554: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095558: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009555C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80095560: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095564: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095568: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009556C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095570: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095574: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095578: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8009557C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095580: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095584: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095588: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8009558C: beq         $t9, $zero, L_800955E0
    if (ctx->r25 == 0) {
        // 0x80095590: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_800955E0;
    }
    // 0x80095590: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80095594: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095598: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009559C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800955A0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800955A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800955A8: nop

    // 0x800955AC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800955B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800955B4: nop

    // 0x800955B8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800955BC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800955C0: bne         $t9, $zero, L_800955D8
    if (ctx->r25 != 0) {
        // 0x800955C4: nop

            goto L_800955D8;
    }
    // 0x800955C4: nop

    // 0x800955C8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800955CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800955D0: b           L_800955F0
    // 0x800955D4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800955F0;
    // 0x800955D4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800955D8:
    // 0x800955D8: b           L_800955F0
    // 0x800955DC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800955F0;
    // 0x800955DC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800955E0:
    // 0x800955E0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800955E4: nop

    // 0x800955E8: bltz        $t9, L_800955D8
    if (SIGNED(ctx->r25) < 0) {
        // 0x800955EC: nop

            goto L_800955D8;
    }
    // 0x800955EC: nop

L_800955F0:
    // 0x800955F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800955F4: jal         0x800908A0
    // 0x800955F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_51;
    // 0x800955F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_51:
    // 0x800955FC: b           L_800956B0
    // 0x80095600: nop

        goto L_800956B0;
    // 0x80095600: nop

L_80095604:
    // 0x80095604: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095608: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8009560C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095610: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095614: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095618: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009561C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80095620: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095624: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095628: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009562C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095630: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095634: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095638: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009563C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095640: beq         $t1, $zero, L_80095694
    if (ctx->r9 == 0) {
        // 0x80095644: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_80095694;
    }
    // 0x80095644: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80095648: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009564C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095650: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095654: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095658: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009565C: nop

    // 0x80095660: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80095664: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095668: nop

    // 0x8009566C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095670: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095674: bne         $t1, $zero, L_8009568C
    if (ctx->r9 != 0) {
        // 0x80095678: nop

            goto L_8009568C;
    }
    // 0x80095678: nop

    // 0x8009567C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80095680: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095684: b           L_800956A4
    // 0x80095688: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800956A4;
    // 0x80095688: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8009568C:
    // 0x8009568C: b           L_800956A4
    // 0x80095690: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800956A4;
    // 0x80095690: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80095694:
    // 0x80095694: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80095698: nop

    // 0x8009569C: bltz        $t1, L_8009568C
    if (SIGNED(ctx->r9) < 0) {
        // 0x800956A0: nop

            goto L_8009568C;
    }
    // 0x800956A0: nop

L_800956A4:
    // 0x800956A4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800956A8: jal         0x800908A0
    // 0x800956AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_52;
    // 0x800956AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_52:
L_800956B0:
    // 0x800956B0: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x800956B4: nop

    // 0x800956B8: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800956BC: beq         $t4, $zero, L_80095778
    if (ctx->r12 == 0) {
        // 0x800956C0: nop

            goto L_80095778;
    }
    // 0x800956C0: nop

    // 0x800956C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800956C8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800956CC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800956D0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800956D4: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800956D8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800956DC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800956E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800956E4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800956E8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800956EC: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800956F0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800956F4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800956F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800956FC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80095700: beq         $t5, $zero, L_80095754
    if (ctx->r13 == 0) {
        // 0x80095704: addiu       $a3, $a3, 0xE
        ctx->r7 = ADD32(ctx->r7, 0XE);
            goto L_80095754;
    }
    // 0x80095704: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x80095708: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009570C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095710: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80095714: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095718: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8009571C: nop

    // 0x80095720: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095724: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80095728: nop

    // 0x8009572C: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80095730: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80095734: bne         $t5, $zero, L_8009574C
    if (ctx->r13 != 0) {
        // 0x80095738: nop

            goto L_8009574C;
    }
    // 0x80095738: nop

    // 0x8009573C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80095740: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095744: b           L_80095764
    // 0x80095748: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80095764;
    // 0x80095748: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8009574C:
    // 0x8009574C: b           L_80095764
    // 0x80095750: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80095764;
    // 0x80095750: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80095754:
    // 0x80095754: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80095758: nop

    // 0x8009575C: bltz        $t5, L_8009574C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80095760: nop

            goto L_8009574C;
    }
    // 0x80095760: nop

L_80095764:
    // 0x80095764: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095768: jal         0x800908A0
    // 0x8009576C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_53;
    // 0x8009576C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_53:
    // 0x80095770: b           L_80095824
    // 0x80095774: nop

        goto L_80095824;
    // 0x80095774: nop

L_80095778:
    // 0x80095778: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009577C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80095780: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095784: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095788: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009578C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095790: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095794: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095798: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009579C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800957A0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800957A4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800957A8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800957AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800957B0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800957B4: beq         $t8, $zero, L_80095808
    if (ctx->r24 == 0) {
        // 0x800957B8: addiu       $a3, $a3, 0xE
        ctx->r7 = ADD32(ctx->r7, 0XE);
            goto L_80095808;
    }
    // 0x800957B8: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x800957BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800957C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800957C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800957C8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800957CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800957D0: nop

    // 0x800957D4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800957D8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800957DC: nop

    // 0x800957E0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800957E4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800957E8: bne         $t8, $zero, L_80095800
    if (ctx->r24 != 0) {
        // 0x800957EC: nop

            goto L_80095800;
    }
    // 0x800957EC: nop

    // 0x800957F0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800957F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800957F8: b           L_80095818
    // 0x800957FC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80095818;
    // 0x800957FC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80095800:
    // 0x80095800: b           L_80095818
    // 0x80095804: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80095818;
    // 0x80095804: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80095808:
    // 0x80095808: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8009580C: nop

    // 0x80095810: bltz        $t8, L_80095800
    if (SIGNED(ctx->r24) < 0) {
        // 0x80095814: nop

            goto L_80095800;
    }
    // 0x80095814: nop

L_80095818:
    // 0x80095818: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009581C: jal         0x800908A0
    // 0x80095820: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_54;
    // 0x80095820: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_54:
L_80095824:
    // 0x80095824: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80095828: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8009582C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80095830: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80095834: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80095838: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8009583C: lw          $t2, -0x780($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X780);
    // 0x80095840: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80095844: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80095848: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8009584C: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x80095850: lbu         $t6, -0x11FF($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X11FF);
    // 0x80095854: nop

    // 0x80095858: sb          $t6, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r14;
    // 0x8009585C: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x80095860: nop

    // 0x80095864: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80095868: bne         $zero, $t6, L_80095E2C
    if (0 != ctx->r14) {
        // 0x8009586C: nop

            goto L_80095E2C;
    }
    // 0x8009586C: nop

    // 0x80095870: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80095874: beq         $zero, $t8, L_80095E2C
    if (0 == ctx->r24) {
        // 0x80095878: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80095E2C;
    }
    // 0x80095878: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8009587C: sltiu       $t1, $t8, 0x9
    ctx->r9 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80095880: beq         $zero, $t1, L_80095E2C
    if (0 == ctx->r9) {
        // 0x80095884: nop

            goto L_80095E2C;
    }
    // 0x80095884: nop

    // 0x80095888: b           L_80095E2C
    // 0x8009588C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_80095E2C;
    // 0x8009588C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80095890: nop

    // 0x80095894: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095898: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x8009589C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800958A0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800958A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800958A8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800958AC: beq         $t1, $zero, L_80095900
    if (ctx->r9 == 0) {
        // 0x800958B0: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80095900;
    }
    // 0x800958B0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800958B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800958B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800958BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800958C0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800958C4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800958C8: nop

    // 0x800958CC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800958D0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800958D4: nop

    // 0x800958D8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800958DC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800958E0: bne         $t1, $zero, L_800958F8
    if (ctx->r9 != 0) {
        // 0x800958E4: nop

            goto L_800958F8;
    }
    // 0x800958E4: nop

    // 0x800958E8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800958EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800958F0: b           L_80095910
    // 0x800958F4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80095910;
    // 0x800958F4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800958F8:
    // 0x800958F8: b           L_80095910
    // 0x800958FC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80095910;
    // 0x800958FC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80095900:
    // 0x80095900: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80095904: nop

    // 0x80095908: bltz        $t1, L_800958F8
    if (SIGNED(ctx->r9) < 0) {
        // 0x8009590C: nop

            goto L_800958F8;
    }
    // 0x8009590C: nop

L_80095910:
    // 0x80095910: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80095914: jal         0x800908A0
    // 0x80095918: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_55;
    // 0x80095918: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_55:
    // 0x8009591C: b           L_800959D0
    // 0x80095920: nop

        goto L_800959D0;
    // 0x80095920: nop

    // 0x80095924: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095928: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8009592C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095930: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80095934: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095938: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009593C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095940: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095944: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80095948: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009594C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80095950: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095954: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095958: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009595C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80095960: beq         $t3, $zero, L_800959B4
    if (ctx->r11 == 0) {
        // 0x80095964: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800959B4;
    }
    // 0x80095964: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80095968: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009596C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095970: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095974: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095978: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009597C: nop

    // 0x80095980: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095984: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80095988: nop

    // 0x8009598C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80095990: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80095994: bne         $t3, $zero, L_800959AC
    if (ctx->r11 != 0) {
        // 0x80095998: nop

            goto L_800959AC;
    }
    // 0x80095998: nop

    // 0x8009599C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800959A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800959A4: b           L_800959C4
    // 0x800959A8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800959C4;
    // 0x800959A8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800959AC:
    // 0x800959AC: b           L_800959C4
    // 0x800959B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800959C4;
    // 0x800959B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800959B4:
    // 0x800959B4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800959B8: nop

    // 0x800959BC: bltz        $t3, L_800959AC
    if (SIGNED(ctx->r11) < 0) {
        // 0x800959C0: nop

            goto L_800959AC;
    }
    // 0x800959C0: nop

L_800959C4:
    // 0x800959C4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800959C8: jal         0x800908A0
    // 0x800959CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800908A0(rdram, ctx);
        goto after_56;
    // 0x800959CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_56:
L_800959D0:
    // 0x800959D0: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x800959D4: nop

    // 0x800959D8: andi        $t2, $t4, 0x40
    ctx->r10 = ctx->r12 & 0X40;
    // 0x800959DC: beq         $t2, $zero, L_80095A98
    if (ctx->r10 == 0) {
        // 0x800959E0: nop

            goto L_80095A98;
    }
    // 0x800959E0: nop

    // 0x800959E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800959E8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800959EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800959F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800959F4: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800959F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800959FC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095A00: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095A04: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80095A08: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095A0C: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80095A10: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095A14: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095A18: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095A1C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80095A20: beq         $t6, $zero, L_80095A74
    if (ctx->r14 == 0) {
        // 0x80095A24: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80095A74;
    }
    // 0x80095A24: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80095A28: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095A2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095A30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095A34: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80095A38: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80095A3C: nop

    // 0x80095A40: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80095A44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80095A48: nop

    // 0x80095A4C: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80095A50: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80095A54: bne         $t6, $zero, L_80095A6C
    if (ctx->r14 != 0) {
        // 0x80095A58: nop

            goto L_80095A6C;
    }
    // 0x80095A58: nop

    // 0x80095A5C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80095A60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095A64: b           L_80095A84
    // 0x80095A68: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80095A84;
    // 0x80095A68: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80095A6C:
    // 0x80095A6C: b           L_80095A84
    // 0x80095A70: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80095A84;
    // 0x80095A70: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80095A74:
    // 0x80095A74: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80095A78: nop

    // 0x80095A7C: bltz        $t6, L_80095A6C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80095A80: nop

            goto L_80095A6C;
    }
    // 0x80095A80: nop

L_80095A84:
    // 0x80095A84: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80095A88: jal         0x800908A0
    // 0x80095A8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_57;
    // 0x80095A8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_57:
    // 0x80095A90: b           L_80095B44
    // 0x80095A94: nop

        goto L_80095B44;
    // 0x80095A94: nop

L_80095A98:
    // 0x80095A98: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095A9C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80095AA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095AA4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80095AA8: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095AAC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095AB0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80095AB4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095AB8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095ABC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095AC0: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80095AC4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095AC8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095ACC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095AD0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80095AD4: beq         $t7, $zero, L_80095B28
    if (ctx->r15 == 0) {
        // 0x80095AD8: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80095B28;
    }
    // 0x80095AD8: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80095ADC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095AE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095AE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095AE8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095AEC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80095AF0: nop

    // 0x80095AF4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80095AF8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095AFC: nop

    // 0x80095B00: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80095B04: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80095B08: bne         $t7, $zero, L_80095B20
    if (ctx->r15 != 0) {
        // 0x80095B0C: nop

            goto L_80095B20;
    }
    // 0x80095B0C: nop

    // 0x80095B10: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80095B14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095B18: b           L_80095B38
    // 0x80095B1C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80095B38;
    // 0x80095B1C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80095B20:
    // 0x80095B20: b           L_80095B38
    // 0x80095B24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80095B38;
    // 0x80095B24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80095B28:
    // 0x80095B28: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80095B2C: nop

    // 0x80095B30: bltz        $t7, L_80095B20
    if (SIGNED(ctx->r15) < 0) {
        // 0x80095B34: nop

            goto L_80095B20;
    }
    // 0x80095B34: nop

L_80095B38:
    // 0x80095B38: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095B3C: jal         0x800908A0
    // 0x80095B40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800908A0(rdram, ctx);
        goto after_58;
    // 0x80095B40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_58:
L_80095B44:
    // 0x80095B44: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x80095B48: nop

    // 0x80095B4C: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x80095B50: beq         $t1, $zero, L_80095C0C
    if (ctx->r9 == 0) {
        // 0x80095B54: nop

            goto L_80095C0C;
    }
    // 0x80095B54: nop

    // 0x80095B58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095B5C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80095B60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095B64: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80095B68: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095B6C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095B70: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095B74: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095B78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80095B7C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095B80: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80095B84: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095B88: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095B8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095B90: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80095B94: beq         $t3, $zero, L_80095BE8
    if (ctx->r11 == 0) {
        // 0x80095B98: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_80095BE8;
    }
    // 0x80095B98: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x80095B9C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095BA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095BA4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095BA8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095BAC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80095BB0: nop

    // 0x80095BB4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095BB8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80095BBC: nop

    // 0x80095BC0: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80095BC4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80095BC8: bne         $t3, $zero, L_80095BE0
    if (ctx->r11 != 0) {
        // 0x80095BCC: nop

            goto L_80095BE0;
    }
    // 0x80095BCC: nop

    // 0x80095BD0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80095BD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095BD8: b           L_80095BF8
    // 0x80095BDC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80095BF8;
    // 0x80095BDC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80095BE0:
    // 0x80095BE0: b           L_80095BF8
    // 0x80095BE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80095BF8;
    // 0x80095BE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80095BE8:
    // 0x80095BE8: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80095BEC: nop

    // 0x80095BF0: bltz        $t3, L_80095BE0
    if (SIGNED(ctx->r11) < 0) {
        // 0x80095BF4: nop

            goto L_80095BE0;
    }
    // 0x80095BF4: nop

L_80095BF8:
    // 0x80095BF8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80095BFC: jal         0x800908A0
    // 0x80095C00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800908A0(rdram, ctx);
        goto after_59;
    // 0x80095C00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_59:
    // 0x80095C04: b           L_80095CB8
    // 0x80095C08: nop

        goto L_80095CB8;
    // 0x80095C08: nop

L_80095C0C:
    // 0x80095C0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095C10: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80095C14: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80095C18: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095C1C: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095C20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095C24: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095C28: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095C2C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80095C30: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095C34: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80095C38: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095C3C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095C40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095C44: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80095C48: beq         $t2, $zero, L_80095C9C
    if (ctx->r10 == 0) {
        // 0x80095C4C: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_80095C9C;
    }
    // 0x80095C4C: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x80095C50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095C54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095C58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80095C5C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80095C60: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095C64: nop

    // 0x80095C68: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80095C6C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80095C70: nop

    // 0x80095C74: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80095C78: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80095C7C: bne         $t2, $zero, L_80095C94
    if (ctx->r10 != 0) {
        // 0x80095C80: nop

            goto L_80095C94;
    }
    // 0x80095C80: nop

    // 0x80095C84: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80095C88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095C8C: b           L_80095CAC
    // 0x80095C90: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80095CAC;
    // 0x80095C90: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80095C94:
    // 0x80095C94: b           L_80095CAC
    // 0x80095C98: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80095CAC;
    // 0x80095C98: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80095C9C:
    // 0x80095C9C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80095CA0: nop

    // 0x80095CA4: bltz        $t2, L_80095C94
    if (SIGNED(ctx->r10) < 0) {
        // 0x80095CA8: nop

            goto L_80095C94;
    }
    // 0x80095CA8: nop

L_80095CAC:
    // 0x80095CAC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80095CB0: jal         0x800908A0
    // 0x80095CB4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_60;
    // 0x80095CB4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_60:
L_80095CB8:
    // 0x80095CB8: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x80095CBC: nop

    // 0x80095CC0: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80095CC4: beq         $t6, $zero, L_80095D80
    if (ctx->r14 == 0) {
        // 0x80095CC8: nop

            goto L_80095D80;
    }
    // 0x80095CC8: nop

    // 0x80095CCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095CD0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80095CD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095CD8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80095CDC: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095CE0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095CE4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80095CE8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095CEC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095CF0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095CF4: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80095CF8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095CFC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095D00: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095D04: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80095D08: beq         $t7, $zero, L_80095D5C
    if (ctx->r15 == 0) {
        // 0x80095D0C: addiu       $a3, $a3, 0x16
        ctx->r7 = ADD32(ctx->r7, 0X16);
            goto L_80095D5C;
    }
    // 0x80095D0C: addiu       $a3, $a3, 0x16
    ctx->r7 = ADD32(ctx->r7, 0X16);
    // 0x80095D10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095D14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095D18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095D1C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095D20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80095D24: nop

    // 0x80095D28: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80095D2C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095D30: nop

    // 0x80095D34: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80095D38: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80095D3C: bne         $t7, $zero, L_80095D54
    if (ctx->r15 != 0) {
        // 0x80095D40: nop

            goto L_80095D54;
    }
    // 0x80095D40: nop

    // 0x80095D44: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80095D48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095D4C: b           L_80095D6C
    // 0x80095D50: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80095D6C;
    // 0x80095D50: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80095D54:
    // 0x80095D54: b           L_80095D6C
    // 0x80095D58: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80095D6C;
    // 0x80095D58: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80095D5C:
    // 0x80095D5C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80095D60: nop

    // 0x80095D64: bltz        $t7, L_80095D54
    if (SIGNED(ctx->r15) < 0) {
        // 0x80095D68: nop

            goto L_80095D54;
    }
    // 0x80095D68: nop

L_80095D6C:
    // 0x80095D6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095D70: jal         0x800908A0
    // 0x80095D74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800908A0(rdram, ctx);
        goto after_61;
    // 0x80095D74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_61:
    // 0x80095D78: b           L_80095E2C
    // 0x80095D7C: nop

        goto L_80095E2C;
    // 0x80095D7C: nop

L_80095D80:
    // 0x80095D80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095D84: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095D88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095D8C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095D90: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095D94: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095D98: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095D9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095DA0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095DA4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095DA8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095DAC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095DB0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095DB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095DB8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095DBC: beq         $t1, $zero, L_80095E10
    if (ctx->r9 == 0) {
        // 0x80095DC0: addiu       $a3, $a3, 0x16
        ctx->r7 = ADD32(ctx->r7, 0X16);
            goto L_80095E10;
    }
    // 0x80095DC0: addiu       $a3, $a3, 0x16
    ctx->r7 = ADD32(ctx->r7, 0X16);
    // 0x80095DC4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095DC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095DCC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095DD0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095DD4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095DD8: nop

    // 0x80095DDC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095DE0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095DE4: nop

    // 0x80095DE8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095DEC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095DF0: bne         $t1, $zero, L_80095E08
    if (ctx->r9 != 0) {
        // 0x80095DF4: nop

            goto L_80095E08;
    }
    // 0x80095DF4: nop

    // 0x80095DF8: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80095DFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095E00: b           L_80095E20
    // 0x80095E04: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80095E20;
    // 0x80095E04: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80095E08:
    // 0x80095E08: b           L_80095E20
    // 0x80095E0C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80095E20;
    // 0x80095E0C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80095E10:
    // 0x80095E10: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80095E14: nop

    // 0x80095E18: bltz        $t1, L_80095E08
    if (SIGNED(ctx->r9) < 0) {
        // 0x80095E1C: nop

            goto L_80095E08;
    }
    // 0x80095E1C: nop

L_80095E20:
    // 0x80095E20: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80095E24: jal         0x800908A0
    // 0x80095E28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_62;
    // 0x80095E28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_62:
L_80095E2C:
    // 0x80095E2C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80095E30: nop

    // 0x80095E34: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80095E38: slti        $at, $t3, 0xC
    ctx->r1 = SIGNED(ctx->r11) < 0XC ? 1 : 0;
    // 0x80095E3C: bne         $at, $zero, L_80094BBC
    if (ctx->r1 != 0) {
        // 0x80095E40: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_80094BBC;
    }
    // 0x80095E40: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80095E44:
    // 0x80095E44: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80095E48: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80095E4C: lw          $t4, 0x6B98($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6B98);
    // 0x80095E50: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80095E54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095E58: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80095E5C: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
L_80095E60:
    // 0x80095E60: b           L_80095E68
    // 0x80095E64: nop

        goto L_80095E68;
    // 0x80095E64: nop

L_80095E68:
    // 0x80095E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80095E6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80095E70: jr          $ra
    // 0x80095E74: nop

    return;
    // 0x80095E74: nop

;}
RECOMP_FUNC void func_80095E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095E78: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80095E7C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80095E80: nop

    // 0x80095E84: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80095E88: sb          $t7, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r15;
    // 0x80095E8C: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x80095E90: nop

    // 0x80095E94: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80095E98: sb          $t9, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r25;
    // 0x80095E9C: lbu         $t0, 0x7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7);
    // 0x80095EA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80095EA4: bgez        $t0, L_80095EB8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80095EA8: andi        $t1, $t0, 0x1
        ctx->r9 = ctx->r8 & 0X1;
            goto L_80095EB8;
    }
    // 0x80095EA8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80095EAC: beq         $t1, $zero, L_80095EB8
    if (ctx->r9 == 0) {
        // 0x80095EB0: nop

            goto L_80095EB8;
    }
    // 0x80095EB0: nop

    // 0x80095EB4: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
L_80095EB8:
    // 0x80095EB8: bne         $t1, $at, L_80095EFC
    if (ctx->r9 != ctx->r1) {
        // 0x80095EBC: nop

            goto L_80095EFC;
    }
    // 0x80095EBC: nop

    // 0x80095EC0: lbu         $t2, 0x6($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6);
    // 0x80095EC4: nop

    // 0x80095EC8: addiu       $t3, $t2, 0x1F
    ctx->r11 = ADD32(ctx->r10, 0X1F);
    // 0x80095ECC: sb          $t3, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r11;
    // 0x80095ED0: lbu         $t4, 0x6($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X6);
    // 0x80095ED4: nop

    // 0x80095ED8: slti        $at, $t4, 0x7F
    ctx->r1 = SIGNED(ctx->r12) < 0X7F ? 1 : 0;
    // 0x80095EDC: bne         $at, $zero, L_80095EF4
    if (ctx->r1 != 0) {
        // 0x80095EE0: nop

            goto L_80095EF4;
    }
    // 0x80095EE0: nop

    // 0x80095EE4: lbu         $t5, 0x6($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X6);
    // 0x80095EE8: nop

    // 0x80095EEC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80095EF0: sb          $t6, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r14;
L_80095EF4:
    // 0x80095EF4: b           L_80095F0C
    // 0x80095EF8: nop

        goto L_80095F0C;
    // 0x80095EF8: nop

L_80095EFC:
    // 0x80095EFC: lbu         $t7, 0x6($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X6);
    // 0x80095F00: nop

    // 0x80095F04: addiu       $t8, $t7, 0x7E
    ctx->r24 = ADD32(ctx->r15, 0X7E);
    // 0x80095F08: sb          $t8, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r24;
L_80095F0C:
    // 0x80095F0C: lbu         $t9, 0x7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F10: nop

    // 0x80095F14: addiu       $t0, $t9, -0x21
    ctx->r8 = ADD32(ctx->r25, -0X21);
    // 0x80095F18: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80095F1C: addiu       $t2, $t1, 0x81
    ctx->r10 = ADD32(ctx->r9, 0X81);
    // 0x80095F20: sb          $t2, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r10;
    // 0x80095F24: lbu         $t3, 0x7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F28: nop

    // 0x80095F2C: slti        $at, $t3, 0xA0
    ctx->r1 = SIGNED(ctx->r11) < 0XA0 ? 1 : 0;
    // 0x80095F30: bne         $at, $zero, L_80095F48
    if (ctx->r1 != 0) {
        // 0x80095F34: nop

            goto L_80095F48;
    }
    // 0x80095F34: nop

    // 0x80095F38: lbu         $t4, 0x7($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F3C: nop

    // 0x80095F40: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x80095F44: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
L_80095F48:
    // 0x80095F48: beq         $a0, $zero, L_80095F78
    if (ctx->r4 == 0) {
        // 0x80095F4C: nop

            goto L_80095F78;
    }
    // 0x80095F4C: nop

    // 0x80095F50: lbu         $t6, 0x7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F54: nop

    // 0x80095F58: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80095F5C: lbu         $t7, 0x6($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X6);
    // 0x80095F60: nop

    // 0x80095F64: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x80095F68: b           L_80095F94
    // 0x80095F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80095F94;
    // 0x80095F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80095F70: b           L_80095F8C
    // 0x80095F74: nop

        goto L_80095F8C;
    // 0x80095F74: nop

L_80095F78:
    // 0x80095F78: lbu         $t8, 0x7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X7);
    // 0x80095F7C: lbu         $t0, 0x6($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6);
    // 0x80095F80: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80095F84: b           L_80095F94
    // 0x80095F88: or          $v0, $t9, $t0
    ctx->r2 = ctx->r25 | ctx->r8;
        goto L_80095F94;
    // 0x80095F88: or          $v0, $t9, $t0
    ctx->r2 = ctx->r25 | ctx->r8;
L_80095F8C:
    // 0x80095F8C: b           L_80095F94
    // 0x80095F90: nop

        goto L_80095F94;
    // 0x80095F90: nop

L_80095F94:
    // 0x80095F94: jr          $ra
    // 0x80095F98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80095F98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_80096250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096250: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80096254: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80096258:
    // 0x80096258: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8009625C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096260: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80096264: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80096268: sw          $zero, -0x3EB8($at)
    MEM_W(-0X3EB8, ctx->r1) = 0;
    // 0x8009626C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80096270: nop

    // 0x80096274: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80096278: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8009627C: bne         $at, $zero, L_80096258
    if (ctx->r1 != 0) {
        // 0x80096280: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_80096258;
    }
    // 0x80096280: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80096284: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80096288: addiu       $t0, $t0, -0x28B8
    ctx->r8 = ADD32(ctx->r8, -0X28B8);
    // 0x8009628C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096290: sw          $t0, -0x2878($at)
    MEM_W(-0X2878, ctx->r1) = ctx->r8;
    // 0x80096294: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80096298: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009629C: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
    // 0x800962A0: b           L_800962A8
    // 0x800962A4: nop

        goto L_800962A8;
    // 0x800962A4: nop

L_800962A8:
    // 0x800962A8: jr          $ra
    // 0x800962AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800962AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800962B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800962B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800962B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962B8: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x800962BC: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800962C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962C4: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x800962C8: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800962CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962D0: sw          $t8, 0x6BA8($at)
    MEM_W(0X6BA8, ctx->r1) = ctx->r24;
    // 0x800962D4: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x800962D8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962DC: sw          $t9, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r25;
    // 0x800962E0: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x800962E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962E8: sw          $t0, 0x6C08($at)
    MEM_W(0X6C08, ctx->r1) = ctx->r8;
    // 0x800962EC: lw          $t1, 0x14($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14);
    // 0x800962F0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962F4: sw          $t1, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = ctx->r9;
    // 0x800962F8: lw          $t2, 0x18($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X18);
    // 0x800962FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096300: sw          $t2, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r10;
    // 0x80096304: lw          $t3, 0x1C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1C);
    // 0x80096308: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009630C: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
    // 0x80096310: lw          $t4, 0x20($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X20);
    // 0x80096314: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096318: sw          $t4, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r12;
    // 0x8009631C: lh          $t5, 0x24($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X24);
    // 0x80096320: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096324: sh          $t5, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = ctx->r13;
    // 0x80096328: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8009632C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096330: swc1        $f4, -0x4CBC($at)
    MEM_W(-0X4CBC, ctx->r1) = ctx->f4.u32l;
    // 0x80096334: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80096338: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009633C: swc1        $f6, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f6.u32l;
    // 0x80096340: lwc1        $f8, 0x30($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80096344: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096348: swc1        $f8, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f8.u32l;
    // 0x8009634C: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80096350: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096354: swc1        $f10, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f10.u32l;
    // 0x80096358: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x8009635C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096360: sw          $t6, -0x44BC($at)
    MEM_W(-0X44BC, ctx->r1) = ctx->r14;
    // 0x80096364: jr          $ra
    // 0x80096368: nop

    return;
    // 0x80096368: nop

    // 0x8009636C: jr          $ra
    // 0x80096370: nop

    return;
    // 0x80096370: nop

;}
RECOMP_FUNC void func_80096374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096374: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80096378: lw          $t6, 0x6B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B98);
    // 0x8009637C: nop

    // 0x80096380: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80096384: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80096388: lw          $t7, 0x6BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA0);
    // 0x8009638C: nop

    // 0x80096390: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80096394: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80096398: lw          $t8, 0x6BA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6BA8);
    // 0x8009639C: nop

    // 0x800963A0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800963A4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800963A8: lw          $t9, 0x6BC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6BC0);
    // 0x800963AC: nop

    // 0x800963B0: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x800963B4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800963B8: lw          $t0, 0x6C08($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C08);
    // 0x800963BC: nop

    // 0x800963C0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x800963C4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800963C8: lw          $t1, 0x6C14($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6C14);
    // 0x800963CC: nop

    // 0x800963D0: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x800963D4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800963D8: lw          $t2, -0x4CE0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CE0);
    // 0x800963DC: nop

    // 0x800963E0: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x800963E4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800963E8: lw          $t3, -0x4CD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CD8);
    // 0x800963EC: nop

    // 0x800963F0: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
    // 0x800963F4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800963F8: lw          $t4, -0x4CD0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CD0);
    // 0x800963FC: nop

    // 0x80096400: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x80096404: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096408: lh          $t5, -0x4CC8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4CC8);
    // 0x8009640C: nop

    // 0x80096410: sh          $t5, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r13;
    // 0x80096414: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096418: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009641C: nop

    // 0x80096420: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x80096424: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096428: lwc1        $f6, -0x4534($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x8009642C: nop

    // 0x80096430: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    // 0x80096434: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096438: lwc1        $f8, -0x4510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x8009643C: nop

    // 0x80096440: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80096444: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096448: lwc1        $f10, -0x44D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X44D8);
    // 0x8009644C: nop

    // 0x80096450: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    // 0x80096454: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80096458: lw          $t6, -0x44BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44BC);
    // 0x8009645C: nop

    // 0x80096460: sw          $t6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r14;
    // 0x80096464: jr          $ra
    // 0x80096468: nop

    return;
    // 0x80096468: nop

    // 0x8009646C: jr          $ra
    // 0x80096470: nop

    return;
    // 0x80096470: nop

;}
RECOMP_FUNC void func_80096474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009647C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80096480: lw          $t6, -0x800($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X800);
    // 0x80096484: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80096488: addiu       $t7, $t7, -0x2820
    ctx->r15 = ADD32(ctx->r15, -0X2820);
    // 0x8009648C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80096490: slti        $at, $t8, 0x1F01
    ctx->r1 = SIGNED(ctx->r24) < 0X1F01 ? 1 : 0;
    // 0x80096494: bne         $at, $zero, L_800964A4
    if (ctx->r1 != 0) {
        // 0x80096498: nop

            goto L_800964A4;
    }
    // 0x80096498: nop

    // 0x8009649C: b           L_800967C8
    // 0x800964A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800967C8;
    // 0x800964A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800964A4:
    // 0x800964A4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800964A8: lw          $t9, -0x4CD8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CD8);
    // 0x800964AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800964B0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800964B4: addiu       $t1, $t1, -0x44B8
    ctx->r9 = ADD32(ctx->r9, -0X44B8);
    // 0x800964B8: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800964BC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800964C0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x800964C4: jal         0x800BCFCC
    // 0x800964C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x800964C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800964CC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800964D0: lw          $t2, -0x800($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X800);
    // 0x800964D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800964D8: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x800964DC: sw          $t3, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r11;
    // 0x800964E0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800964E4: lw          $t4, -0x4CE0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CE0);
    // 0x800964E8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800964EC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800964F0: addiu       $t6, $t6, -0x44B8
    ctx->r14 = ADD32(ctx->r14, -0X44B8);
    // 0x800964F4: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800964F8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800964FC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x80096500: jal         0x800BCFCC
    // 0x80096504: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x80096504: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80096508: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8009650C: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x80096510: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096514: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x80096518: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x8009651C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096520: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096524: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096528: addiu       $a1, $a1, 0x6B98
    ctx->r5 = ADD32(ctx->r5, 0X6B98);
    // 0x8009652C: jal         0x800BCFCC
    // 0x80096530: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x80096530: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80096534: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80096538: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x8009653C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096540: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80096544: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x80096548: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009654C: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096550: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096554: addiu       $a1, $a1, 0x6BA0
    ctx->r5 = ADD32(ctx->r5, 0X6BA0);
    // 0x80096558: jal         0x800BCFCC
    // 0x8009655C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x8009655C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80096560: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096564: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x80096568: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009656C: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80096570: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x80096574: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096578: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x8009657C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096580: addiu       $a1, $a1, 0x6BA8
    ctx->r5 = ADD32(ctx->r5, 0X6BA8);
    // 0x80096584: jal         0x800BCFCC
    // 0x80096588: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x80096588: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x8009658C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096590: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x80096594: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096598: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x8009659C: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x800965A0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800965A4: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800965A8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800965AC: addiu       $a1, $a1, 0x6BC0
    ctx->r5 = ADD32(ctx->r5, 0X6BC0);
    // 0x800965B0: jal         0x800BCFCC
    // 0x800965B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x800965B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x800965B8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800965BC: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x800965C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800965C4: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800965C8: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x800965CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800965D0: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800965D4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800965D8: addiu       $a1, $a1, 0x6C08
    ctx->r5 = ADD32(ctx->r5, 0X6C08);
    // 0x800965DC: jal         0x800BCFCC
    // 0x800965E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_6;
    // 0x800965E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x800965E4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800965E8: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x800965EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800965F0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800965F4: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x800965F8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800965FC: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096600: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80096604: addiu       $a1, $a1, 0x6C14
    ctx->r5 = ADD32(ctx->r5, 0X6C14);
    // 0x80096608: jal         0x800BCFCC
    // 0x8009660C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_7;
    // 0x8009660C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80096610: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80096614: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x80096618: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009661C: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80096620: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x80096624: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096628: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x8009662C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096630: addiu       $a1, $a1, -0x4CE0
    ctx->r5 = ADD32(ctx->r5, -0X4CE0);
    // 0x80096634: jal         0x800BCFCC
    // 0x80096638: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_8;
    // 0x80096638: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x8009663C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096640: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x80096644: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096648: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x8009664C: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x80096650: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096654: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096658: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8009665C: addiu       $a1, $a1, -0x4CD8
    ctx->r5 = ADD32(ctx->r5, -0X4CD8);
    // 0x80096660: jal         0x800BCFCC
    // 0x80096664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_9;
    // 0x80096664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x80096668: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8009666C: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x80096670: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096674: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80096678: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x8009667C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096680: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096684: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096688: addiu       $a1, $a1, -0x4CD0
    ctx->r5 = ADD32(ctx->r5, -0X4CD0);
    // 0x8009668C: jal         0x800BCFCC
    // 0x80096690: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_10;
    // 0x80096690: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x80096694: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096698: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x8009669C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800966A0: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800966A4: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x800966A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800966AC: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800966B0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800966B4: addiu       $a1, $a1, -0x4CC8
    ctx->r5 = ADD32(ctx->r5, -0X4CC8);
    // 0x800966B8: jal         0x800BCFCC
    // 0x800966BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_11;
    // 0x800966BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x800966C0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800966C4: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x800966C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800966CC: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800966D0: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x800966D4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800966D8: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x800966DC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800966E0: addiu       $a1, $a1, -0x4CBC
    ctx->r5 = ADD32(ctx->r5, -0X4CBC);
    // 0x800966E4: jal         0x800BCFCC
    // 0x800966E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_12;
    // 0x800966E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x800966EC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800966F0: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x800966F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800966F8: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800966FC: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x80096700: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096704: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096708: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8009670C: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x80096710: jal         0x800BCFCC
    // 0x80096714: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_13;
    // 0x80096714: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_13:
    // 0x80096718: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8009671C: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x80096720: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096724: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80096728: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x8009672C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096730: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096734: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096738: addiu       $a1, $a1, -0x4510
    ctx->r5 = ADD32(ctx->r5, -0X4510);
    // 0x8009673C: jal         0x800BCFCC
    // 0x80096740: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_14;
    // 0x80096740: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_14:
    // 0x80096744: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096748: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x8009674C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096750: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80096754: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x80096758: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009675C: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x80096760: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096764: addiu       $a1, $a1, -0x44D8
    ctx->r5 = ADD32(ctx->r5, -0X44D8);
    // 0x80096768: jal         0x800BCFCC
    // 0x8009676C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_15;
    // 0x8009676C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_15:
    // 0x80096770: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096774: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x80096778: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009677C: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x80096780: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x80096784: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096788: lw          $a0, -0x800($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X800);
    // 0x8009678C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096790: addiu       $a1, $a1, -0x44BC
    ctx->r5 = ADD32(ctx->r5, -0X44BC);
    // 0x80096794: jal         0x800BCFCC
    // 0x80096798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_16;
    // 0x80096798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_16:
    // 0x8009679C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800967A0: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x800967A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800967A8: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800967AC: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x800967B0: jal         0x800C4270
    // 0x800967B4: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_17;
    // 0x800967B4: nop

    after_17:
    // 0x800967B8: b           L_800967C8
    // 0x800967BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800967C8;
    // 0x800967BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800967C0: b           L_800967C8
    // 0x800967C4: nop

        goto L_800967C8;
    // 0x800967C4: nop

L_800967C8:
    // 0x800967C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800967CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800967D0: jr          $ra
    // 0x800967D4: nop

    return;
    // 0x800967D4: nop

;}
RECOMP_FUNC void func_800967D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800967D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800967DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800967E0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800967E4: lw          $t6, -0x800($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X800);
    // 0x800967E8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800967EC: addiu       $t7, $t7, -0x2820
    ctx->r15 = ADD32(ctx->r15, -0X2820);
    // 0x800967F0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800967F4: bgtz        $t8, L_80096804
    if (SIGNED(ctx->r24) > 0) {
        // 0x800967F8: nop

            goto L_80096804;
    }
    // 0x800967F8: nop

    // 0x800967FC: b           L_80096B28
    // 0x80096800: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80096B28;
    // 0x80096800: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80096804:
    // 0x80096804: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80096808: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x8009680C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096810: addiu       $t0, $t9, -0x4
    ctx->r8 = ADD32(ctx->r25, -0X4);
    // 0x80096814: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x80096818: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8009681C: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096820: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096824: addiu       $a0, $a0, -0x44BC
    ctx->r4 = ADD32(ctx->r4, -0X44BC);
    // 0x80096828: jal         0x800BCFCC
    // 0x8009682C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x8009682C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80096830: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096834: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x80096838: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009683C: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x80096840: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x80096844: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096848: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x8009684C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096850: addiu       $a0, $a0, -0x44D8
    ctx->r4 = ADD32(ctx->r4, -0X44D8);
    // 0x80096854: jal         0x800BCFCC
    // 0x80096858: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x80096858: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8009685C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096860: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x80096864: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096868: addiu       $t4, $t3, -0x4
    ctx->r12 = ADD32(ctx->r11, -0X4);
    // 0x8009686C: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x80096870: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096874: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096878: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009687C: addiu       $a0, $a0, -0x4510
    ctx->r4 = ADD32(ctx->r4, -0X4510);
    // 0x80096880: jal         0x800BCFCC
    // 0x80096884: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x80096884: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80096888: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8009688C: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x80096890: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096894: addiu       $t6, $t5, -0x4
    ctx->r14 = ADD32(ctx->r13, -0X4);
    // 0x80096898: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x8009689C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800968A0: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x800968A4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800968A8: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x800968AC: jal         0x800BCFCC
    // 0x800968B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x800968B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x800968B4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800968B8: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x800968BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800968C0: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x800968C4: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x800968C8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800968CC: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x800968D0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800968D4: addiu       $a0, $a0, -0x4CBC
    ctx->r4 = ADD32(ctx->r4, -0X4CBC);
    // 0x800968D8: jal         0x800BCFCC
    // 0x800968DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x800968DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x800968E0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800968E4: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x800968E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800968EC: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x800968F0: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x800968F4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800968F8: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x800968FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096900: addiu       $a0, $a0, -0x4CC8
    ctx->r4 = ADD32(ctx->r4, -0X4CC8);
    // 0x80096904: jal         0x800BCFCC
    // 0x80096908: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x80096908: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x8009690C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096910: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x80096914: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096918: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x8009691C: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x80096920: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096924: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096928: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009692C: addiu       $a0, $a0, -0x4CD0
    ctx->r4 = ADD32(ctx->r4, -0X4CD0);
    // 0x80096930: jal         0x800BCFCC
    // 0x80096934: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_6;
    // 0x80096934: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80096938: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8009693C: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x80096940: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096944: addiu       $t4, $t3, -0x4
    ctx->r12 = ADD32(ctx->r11, -0X4);
    // 0x80096948: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x8009694C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096950: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096954: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096958: addiu       $a0, $a0, -0x4CD8
    ctx->r4 = ADD32(ctx->r4, -0X4CD8);
    // 0x8009695C: jal         0x800BCFCC
    // 0x80096960: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_7;
    // 0x80096960: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80096964: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096968: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x8009696C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096970: addiu       $t6, $t5, -0x4
    ctx->r14 = ADD32(ctx->r13, -0X4);
    // 0x80096974: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x80096978: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8009697C: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096980: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096984: addiu       $a0, $a0, -0x4CE0
    ctx->r4 = ADD32(ctx->r4, -0X4CE0);
    // 0x80096988: jal         0x800BCFCC
    // 0x8009698C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_8;
    // 0x8009698C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x80096990: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80096994: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x80096998: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009699C: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x800969A0: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x800969A4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800969A8: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x800969AC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800969B0: addiu       $a0, $a0, 0x6C14
    ctx->r4 = ADD32(ctx->r4, 0X6C14);
    // 0x800969B4: jal         0x800BCFCC
    // 0x800969B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_9;
    // 0x800969B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x800969BC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800969C0: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x800969C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800969C8: addiu       $t0, $t9, -0x4
    ctx->r8 = ADD32(ctx->r25, -0X4);
    // 0x800969CC: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x800969D0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800969D4: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x800969D8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800969DC: addiu       $a0, $a0, 0x6C08
    ctx->r4 = ADD32(ctx->r4, 0X6C08);
    // 0x800969E0: jal         0x800BCFCC
    // 0x800969E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_10;
    // 0x800969E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x800969E8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800969EC: lw          $t1, -0x800($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X800);
    // 0x800969F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800969F4: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x800969F8: sw          $t2, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r10;
    // 0x800969FC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096A00: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096A04: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80096A08: addiu       $a0, $a0, 0x6BC0
    ctx->r4 = ADD32(ctx->r4, 0X6BC0);
    // 0x80096A0C: jal         0x800BCFCC
    // 0x80096A10: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_11;
    // 0x80096A10: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x80096A14: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096A18: lw          $t3, -0x800($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X800);
    // 0x80096A1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096A20: addiu       $t4, $t3, -0x4
    ctx->r12 = ADD32(ctx->r11, -0X4);
    // 0x80096A24: sw          $t4, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r12;
    // 0x80096A28: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096A2C: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096A30: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80096A34: addiu       $a0, $a0, 0x6BA8
    ctx->r4 = ADD32(ctx->r4, 0X6BA8);
    // 0x80096A38: jal         0x800BCFCC
    // 0x80096A3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_12;
    // 0x80096A3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x80096A40: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80096A44: lw          $t5, -0x800($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X800);
    // 0x80096A48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096A4C: addiu       $t6, $t5, -0x4
    ctx->r14 = ADD32(ctx->r13, -0X4);
    // 0x80096A50: sw          $t6, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r14;
    // 0x80096A54: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096A58: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096A5C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80096A60: addiu       $a0, $a0, 0x6BA0
    ctx->r4 = ADD32(ctx->r4, 0X6BA0);
    // 0x80096A64: jal         0x800BCFCC
    // 0x80096A68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_13;
    // 0x80096A68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_13:
    // 0x80096A6C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80096A70: lw          $t7, -0x800($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X800);
    // 0x80096A74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096A78: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x80096A7C: sw          $t8, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r24;
    // 0x80096A80: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096A84: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096A88: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80096A8C: addiu       $a0, $a0, 0x6B98
    ctx->r4 = ADD32(ctx->r4, 0X6B98);
    // 0x80096A90: jal         0x800BCFCC
    // 0x80096A94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_14;
    // 0x80096A94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_14:
    // 0x80096A98: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80096A9C: lw          $t9, -0x800($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X800);
    // 0x80096AA0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096AA4: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x80096AA8: sw          $t0, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r8;
    // 0x80096AAC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80096AB0: lw          $t1, -0x4CE0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4CE0);
    // 0x80096AB4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80096AB8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096ABC: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096AC0: addiu       $t3, $t3, -0x44B8
    ctx->r11 = ADD32(ctx->r11, -0X44B8);
    // 0x80096AC4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80096AC8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80096ACC: jal         0x800BCFCC
    // 0x80096AD0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_15;
    // 0x80096AD0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_15:
    // 0x80096AD4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80096AD8: lw          $t4, -0x800($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X800);
    // 0x80096ADC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096AE0: addiu       $t5, $t4, -0x2
    ctx->r13 = ADD32(ctx->r12, -0X2);
    // 0x80096AE4: sw          $t5, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r13;
    // 0x80096AE8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80096AEC: lw          $t6, -0x4CD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CD8);
    // 0x80096AF0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80096AF4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80096AF8: lw          $a1, -0x800($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X800);
    // 0x80096AFC: addiu       $t8, $t8, -0x44B8
    ctx->r24 = ADD32(ctx->r24, -0X44B8);
    // 0x80096B00: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80096B04: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80096B08: jal         0x800BCFCC
    // 0x80096B0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_16;
    // 0x80096B0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_16:
    // 0x80096B10: jal         0x800C4270
    // 0x80096B14: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_17;
    // 0x80096B14: nop

    after_17:
    // 0x80096B18: b           L_80096B28
    // 0x80096B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80096B28;
    // 0x80096B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80096B20: b           L_80096B28
    // 0x80096B24: nop

        goto L_80096B28;
    // 0x80096B24: nop

L_80096B28:
    // 0x80096B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096B30: jr          $ra
    // 0x80096B34: nop

    return;
    // 0x80096B34: nop

;}
RECOMP_FUNC void func_80096B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096B38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80096B3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80096B40: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80096B44: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80096B48: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80096B4C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80096B50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80096B54: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80096B58: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80096B5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80096B60: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80096B64: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80096B68: jal         0x800BD1FC
    // 0x80096B6C: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80096B6C: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80096B70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80096B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80096B78: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80096B7C: jal         0x800BD218
    // 0x80096B80: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80096B80: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80096B84: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80096B88: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80096B8C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80096B90: jal         0x800BC6EC
    // 0x80096B94: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80096B94: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    after_2:
    // 0x80096B98: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80096B9C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80096BA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80096BA4: sltu        $at, $t2, $at
    ctx->r1 = ctx->r10 < ctx->r1 ? 1 : 0;
    // 0x80096BA8: bne         $at, $zero, L_80096BFC
    if (ctx->r1 != 0) {
        // 0x80096BAC: nop

            goto L_80096BFC;
    }
    // 0x80096BAC: nop

    // 0x80096BB0: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x80096BB4: sltu        $at, $t2, $at
    ctx->r1 = ctx->r10 < ctx->r1 ? 1 : 0;
    // 0x80096BB8: beq         $at, $zero, L_80096BFC
    if (ctx->r1 == 0) {
        // 0x80096BBC: nop

            goto L_80096BFC;
    }
    // 0x80096BBC: nop

    // 0x80096BC0: addiu       $t3, $sp, 0x30
    ctx->r11 = ADD32(ctx->r29, 0X30);
    // 0x80096BC4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80096BC8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80096BCC: nop

    // 0x80096BD0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80096BD4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80096BD8: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x80096BDC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80096BE0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80096BE4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80096BE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80096BEC: jal         0x800BCFCC
    // 0x80096BF0: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x80096BF0: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
    after_3:
    // 0x80096BF4: b           L_80096C38
    // 0x80096BF8: nop

        goto L_80096C38;
    // 0x80096BF8: nop

L_80096BFC:
    // 0x80096BFC: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x80096C00: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80096C04: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80096C08: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80096C0C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80096C10: jal         0x800BD1FC
    // 0x80096C14: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x80096C14: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x80096C18: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80096C1C: addiu       $t3, $sp, 0x30
    ctx->r11 = ADD32(ctx->r29, 0X30);
    // 0x80096C20: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80096C24: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80096C28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80096C2C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80096C30: jal         0x800BD218
    // 0x80096C34: subu        $a2, $t4, $t5
    ctx->r6 = SUB32(ctx->r12, ctx->r13);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x80096C34: subu        $a2, $t4, $t5
    ctx->r6 = SUB32(ctx->r12, ctx->r13);
    after_5:
L_80096C38:
    // 0x80096C38: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80096C3C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80096C40: nop

    // 0x80096C44: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80096C48: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80096C4C: b           L_80096C5C
    // 0x80096C50: nop

        goto L_80096C5C;
    // 0x80096C50: nop

    // 0x80096C54: b           L_80096C5C
    // 0x80096C58: nop

        goto L_80096C5C;
    // 0x80096C58: nop

L_80096C5C:
    // 0x80096C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80096C60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80096C64: jr          $ra
    // 0x80096C68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80096C68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80096C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096C6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096C74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80096C78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80096C7C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80096C80: nop

    // 0x80096C84: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80096C88:
    // 0x80096C88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80096C8C: jal         0x800319B0
    // 0x80096C90: nop

    func_800319B0(rdram, ctx);
        goto after_0;
    // 0x80096C90: nop

    after_0:
L_80096C94:
    // 0x80096C94: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80096C98: nop

    // 0x80096C9C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80096CA0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80096CA4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80096CA8: nop

    // 0x80096CAC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80096CB0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80096CB4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80096CB8: nop

    // 0x80096CBC: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80096CC0: nop

    // 0x80096CC4: bne         $t2, $zero, L_80096C94
    if (ctx->r10 != 0) {
        // 0x80096CC8: nop

            goto L_80096C94;
    }
    // 0x80096CC8: nop

L_80096CCC:
    // 0x80096CCC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80096CD0: nop

    // 0x80096CD4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80096CD8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80096CDC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80096CE0: nop

    // 0x80096CE4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80096CE8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80096CEC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80096CF0: nop

    // 0x80096CF4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80096CF8: nop

    // 0x80096CFC: beq         $t8, $zero, L_80096CCC
    if (ctx->r24 == 0) {
        // 0x80096D00: nop

            goto L_80096CCC;
    }
    // 0x80096D00: nop

    // 0x80096D04: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80096D08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80096D0C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80096D10: nop

    // 0x80096D14: bne         $t0, $at, L_80096C88
    if (ctx->r8 != ctx->r1) {
        // 0x80096D18: nop

            goto L_80096C88;
    }
    // 0x80096D18: nop

    // 0x80096D1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80096D20: jal         0x800BC980
    // 0x80096D24: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80096D24: nop

    after_1:
    // 0x80096D28: b           L_80096D30
    // 0x80096D2C: nop

        goto L_80096D30;
    // 0x80096D2C: nop

L_80096D30:
    // 0x80096D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096D34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096D38: jr          $ra
    // 0x80096D3C: nop

    return;
    // 0x80096D3C: nop

;}
RECOMP_FUNC void func_80096D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096D40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096D48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80096D4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80096D50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80096D54: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80096D58: nop

    // 0x80096D5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80096D60: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80096D64:
    // 0x80096D64: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80096D68: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80096D6C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80096D70: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80096D74: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80096D78: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80096D7C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80096D80: nop

    // 0x80096D84: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80096D88: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80096D8C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80096D90: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80096D94: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80096D98: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80096D9C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_80096DA0:
    // 0x80096DA0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80096DA4: nop

    // 0x80096DA8: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80096DAC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80096DB0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80096DB4: nop

    // 0x80096DB8: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80096DBC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80096DC0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80096DC4: nop

    // 0x80096DC8: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80096DCC: nop

    // 0x80096DD0: bne         $t3, $zero, L_80096DA0
    if (ctx->r11 != 0) {
        // 0x80096DD4: nop

            goto L_80096DA0;
    }
    // 0x80096DD4: nop

L_80096DD8:
    // 0x80096DD8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80096DDC: nop

    // 0x80096DE0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80096DE4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80096DE8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80096DEC: nop

    // 0x80096DF0: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80096DF4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80096DF8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80096DFC: nop

    // 0x80096E00: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x80096E04: nop

    // 0x80096E08: beq         $t0, $zero, L_80096DD8
    if (ctx->r8 == 0) {
        // 0x80096E0C: nop

            goto L_80096DD8;
    }
    // 0x80096E0C: nop

    // 0x80096E10: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80096E14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80096E18: lbu         $t1, 0x0($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X0);
    // 0x80096E1C: nop

    // 0x80096E20: bne         $t1, $at, L_80096D64
    if (ctx->r9 != ctx->r1) {
        // 0x80096E24: nop

            goto L_80096D64;
    }
    // 0x80096E24: nop

    // 0x80096E28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80096E2C: jal         0x800BC980
    // 0x80096E30: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x80096E30: nop

    after_0:
    // 0x80096E34: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80096E38: b           L_80096E48
    // 0x80096E3C: nop

        goto L_80096E48;
    // 0x80096E3C: nop

    // 0x80096E40: b           L_80096E48
    // 0x80096E44: nop

        goto L_80096E48;
    // 0x80096E44: nop

L_80096E48:
    // 0x80096E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096E50: jr          $ra
    // 0x80096E54: nop

    return;
    // 0x80096E54: nop

;}
RECOMP_FUNC void func_80096E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096E58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80096E64: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80096E68: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80096E6C: jal         0x800BC6EC
    // 0x80096E70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80096E70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_0:
    // 0x80096E74: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80096E78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80096E7C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80096E80: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80096E84: jal         0x8008ED4C
    // 0x80096E88: addiu       $a1, $a1, -0x9F0
    ctx->r5 = ADD32(ctx->r5, -0X9F0);
    func_8008ED4C(rdram, ctx);
        goto after_1;
    // 0x80096E88: addiu       $a1, $a1, -0x9F0
    ctx->r5 = ADD32(ctx->r5, -0X9F0);
    after_1:
    // 0x80096E8C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80096E90: b           L_80096EA0
    // 0x80096E94: nop

        goto L_80096EA0;
    // 0x80096E94: nop

    // 0x80096E98: b           L_80096EA0
    // 0x80096E9C: nop

        goto L_80096EA0;
    // 0x80096E9C: nop

L_80096EA0:
    // 0x80096EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096EA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096EA8: jr          $ra
    // 0x80096EAC: nop

    return;
    // 0x80096EAC: nop

;}
RECOMP_FUNC void func_80096EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096EB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80096EB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80096EB8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80096EBC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80096EC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80096EC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096EC8: sw          $t6, 0x4CA4($at)
    MEM_W(0X4CA4, ctx->r1) = ctx->r14;
    // 0x80096ECC: b           L_80096ED4
    // 0x80096ED0: nop

        goto L_80096ED4;
    // 0x80096ED0: nop

L_80096ED4:
    // 0x80096ED4: jr          $ra
    // 0x80096ED8: nop

    return;
    // 0x80096ED8: nop

;}
RECOMP_FUNC void func_80096EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096EDC: nop

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
RECOMP_FUNC void Scheduler_CreateSchedulerThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009706C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80097074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097078: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009707C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80097080: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097084: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097088: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8009708C: addiu       $a2, $a2, 0x756C
    ctx->r6 = ADD32(ctx->r6, 0X756C);
    // 0x80097090: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80097094: addiu       $a0, $t6, 0xD0
    ctx->r4 = ADD32(ctx->r14, 0XD0);
    // 0x80097098: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8009709C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800970A0: jal         0x800C4800
    // 0x800970A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800970A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x800970A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800970AC: jal         0x800C4950
    // 0x800970B0: addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800970B0: addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
    after_1:
    // 0x800970B4: b           L_800970BC
    // 0x800970B8: nop

        goto L_800970BC;
    // 0x800970B8: nop

L_800970BC:
    // 0x800970BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800970C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800970C4: jr          $ra
    // 0x800970C8: nop

    return;
    // 0x800970C8: nop

;}
RECOMP_FUNC void func_800970CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800970CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800970D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800970D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800970D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800970DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800970E0: jal         0x800C41A0
    // 0x800970E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800970E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800970E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800970EC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800970F0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800970F4: nop

    // 0x800970F8: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800970FC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80097100: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097104: lw          $t9, 0x280($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X280);
    // 0x80097108: nop

    // 0x8009710C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80097110: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80097114: nop

    // 0x80097118: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
    // 0x8009711C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80097120: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80097124: nop

    // 0x80097128: sw          $t2, 0x280($t3)
    MEM_W(0X280, ctx->r11) = ctx->r10;
    // 0x8009712C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80097130: jal         0x800C41A0
    // 0x80097134: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80097134: nop

    after_1:
    // 0x80097138: b           L_80097140
    // 0x8009713C: nop

        goto L_80097140;
    // 0x8009713C: nop

L_80097140:
    // 0x80097140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097148: jr          $ra
    // 0x8009714C: nop

    return;
    // 0x8009714C: nop

;}
RECOMP_FUNC void func_80097150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80097154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097158: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009715C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097160: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80097164: jal         0x800C41A0
    // 0x80097168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80097168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8009716C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097170: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097174: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097178: nop

    // 0x8009717C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80097180: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80097184: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097188: lw          $t9, 0x280($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X280);
    // 0x8009718C: nop

    // 0x80097190: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80097194: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80097198: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8009719C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x800971A0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800971A4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800971A8: nop

    // 0x800971AC: sw          $t3, 0x280($t4)
    MEM_W(0X280, ctx->r12) = ctx->r11;
    // 0x800971B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800971B4: jal         0x800C41A0
    // 0x800971B8: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800971B8: nop

    after_1:
    // 0x800971BC: b           L_800971C4
    // 0x800971C0: nop

        goto L_800971C4;
    // 0x800971C0: nop

L_800971C4:
    // 0x800971C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800971C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800971CC: jr          $ra
    // 0x800971D0: nop

    return;
    // 0x800971D0: nop

;}
RECOMP_FUNC void func_800971D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800971D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800971D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800971DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800971E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800971E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800971E8: jal         0x800C41A0
    // 0x800971EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800971EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800971F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800971F4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800971F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800971FC: nop

    // 0x80097200: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80097204: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80097208: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8009720C: lw          $t9, 0x280($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X280);
    // 0x80097210: nop

    // 0x80097214: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80097218: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8009721C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80097220: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80097224: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80097228: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8009722C: nop

    // 0x80097230: sw          $t3, 0x280($t4)
    MEM_W(0X280, ctx->r12) = ctx->r11;
    // 0x80097234: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80097238: jal         0x800C41A0
    // 0x8009723C: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8009723C: nop

    after_1:
    // 0x80097240: b           L_80097248
    // 0x80097244: nop

        goto L_80097248;
    // 0x80097244: nop

L_80097248:
    // 0x80097248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009724C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097250: jr          $ra
    // 0x80097254: nop

    return;
    // 0x80097254: nop

;}
RECOMP_FUNC void func_80097258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097258: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009725C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097260: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80097264: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097268: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009726C: jal         0x800C41A0
    // 0x80097270: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80097270: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80097274: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097278: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009727C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097280: nop

    // 0x80097284: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80097288: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8009728C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097290: lw          $t9, 0x280($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X280);
    // 0x80097294: nop

    // 0x80097298: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8009729C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800972A0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800972A4: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x800972A8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800972AC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800972B0: nop

    // 0x800972B4: sw          $t3, 0x280($t4)
    MEM_W(0X280, ctx->r12) = ctx->r11;
    // 0x800972B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800972BC: jal         0x800C41A0
    // 0x800972C0: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800972C0: nop

    after_1:
    // 0x800972C4: b           L_800972CC
    // 0x800972C8: nop

        goto L_800972CC;
    // 0x800972C8: nop

L_800972CC:
    // 0x800972CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800972D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800972D4: jr          $ra
    // 0x800972D8: nop

    return;
    // 0x800972D8: nop

;}
RECOMP_FUNC void func_800972DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800972DC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800972E0: nop

    // 0x800972E4: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x800972E8: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800972EC: jr          $ra
    // 0x800972F0: nop

    return;
    // 0x800972F0: nop

    // 0x800972F4: jr          $ra
    // 0x800972F8: nop

    return;
    // 0x800972F8: nop

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
RECOMP_FUNC void Scheduler_RemoveClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009731C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80097320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097324: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097328: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8009732C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097330: nop

    // 0x80097334: lw          $t7, 0x280($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X280);
    // 0x80097338: nop

    // 0x8009733C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80097340: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80097344: jal         0x800C41A0
    // 0x80097348: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80097348: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8009734C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097350: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80097354: nop

    // 0x80097358: beq         $t8, $zero, L_800973E4
    if (ctx->r24 == 0) {
        // 0x8009735C: nop

            goto L_800973E4;
    }
    // 0x8009735C: nop

L_80097360:
    // 0x80097360: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097364: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80097368: nop

    // 0x8009736C: bne         $t9, $t0, L_800973B4
    if (ctx->r25 != ctx->r8) {
        // 0x80097370: nop

            goto L_800973B4;
    }
    // 0x80097370: nop

    // 0x80097374: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80097378: nop

    // 0x8009737C: beq         $t1, $zero, L_80097398
    if (ctx->r9 == 0) {
        // 0x80097380: nop

            goto L_80097398;
    }
    // 0x80097380: nop

    // 0x80097384: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80097388: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8009738C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80097390: b           L_800973AC
    // 0x80097394: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_800973AC;
    // 0x80097394: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80097398:
    // 0x80097398: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8009739C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800973A0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800973A4: nop

    // 0x800973A8: sw          $t6, 0x280($t7)
    MEM_W(0X280, ctx->r15) = ctx->r14;
L_800973AC:
    // 0x800973AC: b           L_800973E4
    // 0x800973B0: nop

        goto L_800973E4;
    // 0x800973B0: nop

L_800973B4:
    // 0x800973B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800973B8: nop

    // 0x800973BC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800973C0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800973C4: nop

    // 0x800973C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800973CC: nop

    // 0x800973D0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800973D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800973D8: nop

    // 0x800973DC: bne         $t1, $zero, L_80097360
    if (ctx->r9 != 0) {
        // 0x800973E0: nop

            goto L_80097360;
    }
    // 0x800973E0: nop

L_800973E4:
    // 0x800973E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800973E8: jal         0x800C41A0
    // 0x800973EC: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800973EC: nop

    after_1:
    // 0x800973F0: b           L_800973F8
    // 0x800973F4: nop

        goto L_800973F8;
    // 0x800973F4: nop

L_800973F8:
    // 0x800973F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800973FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097400: jr          $ra
    // 0x80097404: nop

    return;
    // 0x80097404: nop

;}
RECOMP_FUNC void func_80097408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097408: jr          $ra
    // 0x8009740C: addiu       $v0, $a0, 0x98
    ctx->r2 = ADD32(ctx->r4, 0X98);
    return;
    // 0x8009740C: addiu       $v0, $a0, 0x98
    ctx->r2 = ADD32(ctx->r4, 0X98);
    // 0x80097410: jr          $ra
    // 0x80097414: nop

    return;
    // 0x80097414: nop

    // 0x80097418: jr          $ra
    // 0x8009741C: nop

    return;
    // 0x8009741C: nop

;}
RECOMP_FUNC void func_80097420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097420: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80097424: lw          $t6, 0x280($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X280);
    // 0x80097428: nop

    // 0x8009742C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80097430: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80097434: nop

    // 0x80097438: beq         $t7, $zero, L_80097488
    if (ctx->r15 == 0) {
        // 0x8009743C: nop

            goto L_80097488;
    }
    // 0x8009743C: nop

L_80097440:
    // 0x80097440: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80097444: nop

    // 0x80097448: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8009744C: nop

    // 0x80097450: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80097454: bne         $t0, $zero, L_80097470
    if (ctx->r8 != 0) {
        // 0x80097458: nop

            goto L_80097470;
    }
    // 0x80097458: nop

    // 0x8009745C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80097460: nop

    // 0x80097464: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80097468: nop

    // 0x8009746C: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
L_80097470:
    // 0x80097470: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80097474: nop

    // 0x80097478: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009747C: nop

    // 0x80097480: bne         $t4, $zero, L_80097440
    if (ctx->r12 != 0) {
        // 0x80097484: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_80097440;
    }
    // 0x80097484: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
L_80097488:
    // 0x80097488: b           L_80097490
    // 0x8009748C: nop

        goto L_80097490;
    // 0x8009748C: nop

L_80097490:
    // 0x80097490: jr          $ra
    // 0x80097494: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80097494: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80097498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097498: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009749C: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x800974A0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800974A4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800974A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800974AC: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x800974B0: jr          $ra
    // 0x800974B4: nop

    return;
    // 0x800974B4: nop

    // 0x800974B8: jr          $ra
    // 0x800974BC: nop

    return;
    // 0x800974BC: nop

;}
RECOMP_FUNC void func_800974C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800974C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800974C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800974C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800974CC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800974D0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800974D4: lw          $t7, 0x280($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X280);
    // 0x800974D8: nop

    // 0x800974DC: beq         $t7, $zero, L_8009753C
    if (ctx->r15 == 0) {
        // 0x800974E0: sw          $t7, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r15;
            goto L_8009753C;
    }
    // 0x800974E0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_800974E4:
    // 0x800974E4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800974E8: nop

    // 0x800974EC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800974F0: nop

    // 0x800974F4: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x800974F8: beq         $t0, $zero, L_80097524
    if (ctx->r8 == 0) {
        // 0x800974FC: nop

            goto L_80097524;
    }
    // 0x800974FC: nop

    // 0x80097500: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80097504: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80097508: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x8009750C: jal         0x800C4AA0
    // 0x80097510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80097510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80097514: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80097518: nop

    // 0x8009751C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80097520: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_80097524:
    // 0x80097524: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80097528: nop

    // 0x8009752C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80097530: nop

    // 0x80097534: bne         $t5, $zero, L_800974E4
    if (ctx->r13 != 0) {
        // 0x80097538: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_800974E4;
    }
    // 0x80097538: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
L_8009753C:
    // 0x8009753C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80097540: nop

    // 0x80097544: beq         $t6, $zero, L_80097554
    if (ctx->r14 == 0) {
        // 0x80097548: nop

            goto L_80097554;
    }
    // 0x80097548: nop

    // 0x8009754C: jal         0x800C4BF0
    // 0x80097550: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80097550: nop

    after_1:
L_80097554:
    // 0x80097554: b           L_8009755C
    // 0x80097558: nop

        goto L_8009755C;
    // 0x80097558: nop

L_8009755C:
    // 0x8009755C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097564: jr          $ra
    // 0x80097568: nop

    return;
    // 0x80097568: nop

;}
RECOMP_FUNC void Scheduler_Thread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009756C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80097570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097574: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80097578: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009757C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80097580: nop

    // 0x80097584: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80097588:
    // 0x80097588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8009758C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80097590: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80097594: jal         0x800C4C40
    // 0x80097598: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80097598: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    after_0:
    // 0x8009759C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800975A0: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x800975A4: beq         $s0, $at, L_800975D8
    if (ctx->r16 == ctx->r1) {
        // 0x800975A8: nop

            goto L_800975D8;
    }
    // 0x800975A8: nop

    // 0x800975AC: addiu       $at, $zero, 0x29B
    ctx->r1 = ADD32(0, 0X29B);
    // 0x800975B0: beq         $s0, $at, L_800975F4
    if (ctx->r16 == ctx->r1) {
        // 0x800975B4: nop

            goto L_800975F4;
    }
    // 0x800975B4: nop

    // 0x800975B8: addiu       $at, $zero, 0x29C
    ctx->r1 = ADD32(0, 0X29C);
    // 0x800975BC: beq         $s0, $at, L_80097610
    if (ctx->r16 == ctx->r1) {
        // 0x800975C0: nop

            goto L_80097610;
    }
    // 0x800975C0: nop

    // 0x800975C4: addiu       $at, $zero, 0x29D
    ctx->r1 = ADD32(0, 0X29D);
    // 0x800975C8: beq         $s0, $at, L_8009762C
    if (ctx->r16 == ctx->r1) {
        // 0x800975CC: nop

            goto L_8009762C;
    }
    // 0x800975CC: nop

    // 0x800975D0: b           L_8009767C
    // 0x800975D4: nop

        goto L_8009767C;
    // 0x800975D4: nop

L_800975D8:
    // 0x800975D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800975DC: jal         0x8009769C
    // 0x800975E0: nop

    Scheduler_HandleVideoMesg(rdram, ctx);
        goto after_1;
    // 0x800975E0: nop

    after_1:
    // 0x800975E4: jal         0x800C4240
    // 0x800975E8: nop

    guRandom(rdram, ctx);
        goto after_2;
    // 0x800975E8: nop

    after_2:
    // 0x800975EC: b           L_8009767C
    // 0x800975F0: nop

        goto L_8009767C;
    // 0x800975F0: nop

L_800975F4:
    // 0x800975F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800975F8: jal         0x80097988
    // 0x800975FC: nop

    Scheduler_HandleRspMesg(rdram, ctx);
        goto after_3;
    // 0x800975FC: nop

    after_3:
    // 0x80097600: jal         0x800C4240
    // 0x80097604: nop

    guRandom(rdram, ctx);
        goto after_4;
    // 0x80097604: nop

    after_4:
    // 0x80097608: b           L_8009767C
    // 0x8009760C: nop

        goto L_8009767C;
    // 0x8009760C: nop

L_80097610:
    // 0x80097610: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097614: jal         0x80097B0C
    // 0x80097618: nop

    Scheduler_HandleRdpMesg(rdram, ctx);
        goto after_5;
    // 0x80097618: nop

    after_5:
    // 0x8009761C: jal         0x800C4240
    // 0x80097620: nop

    guRandom(rdram, ctx);
        goto after_6;
    // 0x80097620: nop

    after_6:
    // 0x80097624: b           L_8009767C
    // 0x80097628: nop

        goto L_8009767C;
    // 0x80097628: nop

L_8009762C:
    // 0x8009762C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80097630: nop

    // 0x80097634: lw          $t8, 0x280($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X280);
    // 0x80097638: nop

    // 0x8009763C: beq         $t8, $zero, L_80097674
    if (ctx->r24 == 0) {
        // 0x80097640: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80097674;
    }
    // 0x80097640: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80097644:
    // 0x80097644: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097648: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8009764C: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80097650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097654: jal         0x800C4AA0
    // 0x80097658: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80097658: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_7:
    // 0x8009765C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097660: nop

    // 0x80097664: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80097668: nop

    // 0x8009766C: bne         $t1, $zero, L_80097644
    if (ctx->r9 != 0) {
        // 0x80097670: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_80097644;
    }
    // 0x80097670: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80097674:
    // 0x80097674: b           L_8009767C
    // 0x80097678: nop

        goto L_8009767C;
    // 0x80097678: nop

L_8009767C:
    // 0x8009767C: b           L_80097588
    // 0x80097680: nop

        goto L_80097588;
    // 0x80097680: nop

    // 0x80097684: b           L_8009768C
    // 0x80097688: nop

        goto L_8009768C;
    // 0x80097688: nop

L_8009768C:
    // 0x8009768C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80097690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097694: jr          $ra
    // 0x80097698: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80097698: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Scheduler_HandleVideoMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009769C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800976A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800976A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800976A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800976AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800976B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800976B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800976B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800976BC: jal         0x800C4C40
    // 0x800976C0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800976C0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_0:
    // 0x800976C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800976C8: beq         $v0, $at, L_80097700
    if (ctx->r2 == ctx->r1) {
        // 0x800976CC: nop

            goto L_80097700;
    }
    // 0x800976CC: nop

L_800976D0:
    // 0x800976D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800976D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800976D8: jal         0x80097D44
    // 0x800976DC: nop

    Scheduler_AppendTask(rdram, ctx);
        goto after_1;
    // 0x800976DC: nop

    after_1:
    // 0x800976E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800976E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800976E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800976EC: jal         0x800C4C40
    // 0x800976F0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800976F0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_2:
    // 0x800976F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800976F8: bne         $v0, $at, L_800976D0
    if (ctx->r2 != ctx->r1) {
        // 0x800976FC: nop

            goto L_800976D0;
    }
    // 0x800976FC: nop

L_80097700:
    // 0x80097700: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80097704: nop

    // 0x80097708: lw          $t7, 0x2A4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2A4);
    // 0x8009770C: nop

    // 0x80097710: beq         $t7, $zero, L_8009773C
    if (ctx->r15 == 0) {
        // 0x80097714: nop

            goto L_8009773C;
    }
    // 0x80097714: nop

    // 0x80097718: lw          $t8, 0x294($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X294);
    // 0x8009771C: nop

    // 0x80097720: beq         $t8, $zero, L_8009773C
    if (ctx->r24 == 0) {
        // 0x80097724: nop

            goto L_8009773C;
    }
    // 0x80097724: nop

    // 0x80097728: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8009772C: jal         0x80097F04
    // 0x80097730: nop

    Scheduler_RspTaskYield(rdram, ctx);
        goto after_3;
    // 0x80097730: nop

    after_3:
    // 0x80097734: b           L_80097798
    // 0x80097738: nop

        goto L_80097798;
    // 0x80097738: nop

L_8009773C:
    // 0x8009773C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80097740: nop

    // 0x80097744: lw          $t0, 0x294($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X294);
    // 0x80097748: lw          $t3, 0x298($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X298);
    // 0x8009774C: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80097750: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80097754: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80097758: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8009775C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80097760: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80097764: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80097768: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8009776C: jal         0x80097F78
    // 0x80097770: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    Scheduler_ScheduleTask(rdram, ctx);
        goto after_4;
    // 0x80097770: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x80097774: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80097778: nop

    // 0x8009777C: beq         $v0, $t7, L_80097798
    if (ctx->r2 == ctx->r15) {
        // 0x80097780: nop

            goto L_80097798;
    }
    // 0x80097780: nop

    // 0x80097784: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80097788: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8009778C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80097790: jal         0x80097DDC
    // 0x80097794: nop

    Scheduler_ExecuteTask(rdram, ctx);
        goto after_5;
    // 0x80097794: nop

    after_5:
L_80097798:
    // 0x80097798: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009779C: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x800977A0: nop

    // 0x800977A4: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800977A8: bne         $t8, $zero, L_80097818
    if (ctx->r24 != 0) {
        // 0x800977AC: nop

            goto L_80097818;
    }
    // 0x800977AC: nop

    // 0x800977B0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800977B4: nop

    // 0x800977B8: lw          $t1, 0x280($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X280);
    // 0x800977BC: nop

    // 0x800977C0: beq         $t1, $zero, L_80097810
    if (ctx->r9 == 0) {
        // 0x800977C4: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80097810;
    }
    // 0x800977C4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_800977C8:
    // 0x800977C8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800977CC: nop

    // 0x800977D0: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x800977D4: nop

    // 0x800977D8: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x800977DC: bne         $t2, $zero, L_800977F8
    if (ctx->r10 != 0) {
        // 0x800977E0: nop

            goto L_800977F8;
    }
    // 0x800977E0: nop

    // 0x800977E4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800977E8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800977EC: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x800977F0: jal         0x800C4AA0
    // 0x800977F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800977F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_800977F8:
    // 0x800977F8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800977FC: nop

    // 0x80097800: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80097804: nop

    // 0x80097808: bne         $t7, $zero, L_800977C8
    if (ctx->r15 != 0) {
        // 0x8009780C: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_800977C8;
    }
    // 0x8009780C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80097810:
    // 0x80097810: b           L_80097914
    // 0x80097814: nop

        goto L_80097914;
    // 0x80097814: nop

L_80097818:
    // 0x80097818: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009781C: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80097820: nop

    // 0x80097824: andi        $t8, $t6, 0x2
    ctx->r24 = ctx->r14 & 0X2;
    // 0x80097828: bne         $t8, $zero, L_8009789C
    if (ctx->r24 != 0) {
        // 0x8009782C: nop

            goto L_8009789C;
    }
    // 0x8009782C: nop

    // 0x80097830: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80097834: nop

    // 0x80097838: lw          $t1, 0x280($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X280);
    // 0x8009783C: nop

    // 0x80097840: beq         $t1, $zero, L_80097894
    if (ctx->r9 == 0) {
        // 0x80097844: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80097894;
    }
    // 0x80097844: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80097848:
    // 0x80097848: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009784C: nop

    // 0x80097850: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x80097854: nop

    // 0x80097858: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x8009785C: bne         $t2, $zero, L_8009787C
    if (ctx->r10 != 0) {
        // 0x80097860: nop

            goto L_8009787C;
    }
    // 0x80097860: nop

    // 0x80097864: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80097868: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8009786C: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x80097870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097874: jal         0x800C4AA0
    // 0x80097878: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80097878: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_7:
L_8009787C:
    // 0x8009787C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80097880: nop

    // 0x80097884: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80097888: nop

    // 0x8009788C: bne         $t7, $zero, L_80097848
    if (ctx->r15 != 0) {
        // 0x80097890: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_80097848;
    }
    // 0x80097890: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80097894:
    // 0x80097894: b           L_80097914
    // 0x80097898: nop

        goto L_80097914;
    // 0x80097898: nop

L_8009789C:
    // 0x8009789C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800978A0: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x800978A4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800978A8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800978AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800978B0: sw          $t8, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r24;
    // 0x800978B4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800978B8: nop

    // 0x800978BC: lw          $t1, 0x280($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X280);
    // 0x800978C0: nop

    // 0x800978C4: beq         $t1, $zero, L_80097914
    if (ctx->r9 == 0) {
        // 0x800978C8: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80097914;
    }
    // 0x800978C8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_800978CC:
    // 0x800978CC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800978D0: nop

    // 0x800978D4: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x800978D8: nop

    // 0x800978DC: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x800978E0: bne         $t2, $zero, L_800978FC
    if (ctx->r10 != 0) {
        // 0x800978E4: nop

            goto L_800978FC;
    }
    // 0x800978E4: nop

    // 0x800978E8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800978EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800978F0: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x800978F4: jal         0x800C4AA0
    // 0x800978F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800978F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
L_800978FC:
    // 0x800978FC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80097900: nop

    // 0x80097904: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80097908: nop

    // 0x8009790C: bne         $t7, $zero, L_800978CC
    if (ctx->r15 != 0) {
        // 0x80097910: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_800978CC;
    }
    // 0x80097910: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80097914:
    // 0x80097914: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80097918: nop

    // 0x8009791C: lw          $t8, 0x29C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X29C);
    // 0x80097920: nop

    // 0x80097924: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80097928: sw          $t0, 0x29C($t6)
    MEM_W(0X29C, ctx->r14) = ctx->r8;
    // 0x8009792C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80097930: nop

    // 0x80097934: lw          $t9, 0x2A0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X2A0);
    // 0x80097938: nop

    // 0x8009793C: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80097940: sw          $t3, 0x2A0($t1)
    MEM_W(0X2A0, ctx->r9) = ctx->r11;
    // 0x80097944: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80097948: lw          $t2, 0x72DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72DC);
    // 0x8009794C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80097950: ori         $t4, $t2, 0x8
    ctx->r12 = ctx->r10 | 0X8;
    // 0x80097954: sw          $t4, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r12;
    // 0x80097958: jal         0x800C40D0
    // 0x8009795C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_9;
    // 0x8009795C: nop

    after_9:
    // 0x80097960: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80097964: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x80097968: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009796C: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
    // 0x80097970: b           L_80097978
    // 0x80097974: nop

        goto L_80097978;
    // 0x80097974: nop

L_80097978:
    // 0x80097978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009797C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80097980: jr          $ra
    // 0x80097984: nop

    return;
    // 0x80097984: nop

;}
RECOMP_FUNC void Scheduler_HandleRspMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097988: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009798C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097990: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097994: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80097998: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8009799C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800979A0: nop

    // 0x800979A4: lw          $t7, 0x294($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X294);
    // 0x800979A8: nop

    // 0x800979AC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800979B0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800979B4: nop

    // 0x800979B8: sw          $zero, 0x294($t8)
    MEM_W(0X294, ctx->r24) = 0;
    // 0x800979BC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800979C0: nop

    // 0x800979C4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800979C8: nop

    // 0x800979CC: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x800979D0: beq         $t1, $zero, L_80097A70
    if (ctx->r9 == 0) {
        // 0x800979D4: nop

            goto L_80097A70;
    }
    // 0x800979D4: nop

    // 0x800979D8: jal         0x800C4D80
    // 0x800979DC: addiu       $a0, $t9, 0x10
    ctx->r4 = ADD32(ctx->r25, 0X10);
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_0;
    // 0x800979DC: addiu       $a0, $t9, 0x10
    ctx->r4 = ADD32(ctx->r25, 0X10);
    after_0:
    // 0x800979E0: beq         $v0, $zero, L_80097A70
    if (ctx->r2 == 0) {
        // 0x800979E4: nop

            goto L_80097A70;
    }
    // 0x800979E4: nop

    // 0x800979E8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800979EC: nop

    // 0x800979F0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800979F4: nop

    // 0x800979F8: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x800979FC: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80097A00: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80097A04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80097A08: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80097A0C: nop

    // 0x80097A10: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80097A14: bne         $t7, $at, L_80097A68
    if (ctx->r15 != ctx->r1) {
        // 0x80097A18: nop

            goto L_80097A68;
    }
    // 0x80097A18: nop

    // 0x80097A1C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097A20: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80097A24: lw          $t0, 0x288($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X288);
    // 0x80097A28: nop

    // 0x80097A2C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80097A30: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097A34: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80097A38: nop

    // 0x80097A3C: sw          $t9, 0x288($t3)
    MEM_W(0X288, ctx->r11) = ctx->r25;
    // 0x80097A40: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80097A44: nop

    // 0x80097A48: lw          $t2, 0x290($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X290);
    // 0x80097A4C: nop

    // 0x80097A50: bne         $t2, $zero, L_80097A68
    if (ctx->r10 != 0) {
        // 0x80097A54: nop

            goto L_80097A68;
    }
    // 0x80097A54: nop

    // 0x80097A58: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80097A5C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097A60: nop

    // 0x80097A64: sw          $t5, 0x290($t6)
    MEM_W(0X290, ctx->r14) = ctx->r13;
L_80097A68:
    // 0x80097A68: b           L_80097A98
    // 0x80097A6C: nop

        goto L_80097A98;
    // 0x80097A6C: nop

L_80097A70:
    // 0x80097A70: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097A74: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80097A78: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80097A7C: nop

    // 0x80097A80: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80097A84: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x80097A88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097A8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80097A90: jal         0x80097C5C
    // 0x80097A94: nop

    Scheduler_IsTaskComplete(rdram, ctx);
        goto after_1;
    // 0x80097A94: nop

    after_1:
L_80097A98:
    // 0x80097A98: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80097A9C: nop

    // 0x80097AA0: lw          $t9, 0x294($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X294);
    // 0x80097AA4: lw          $t2, 0x298($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X298);
    // 0x80097AA8: sltiu       $t3, $t9, 0x1
    ctx->r11 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80097AAC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80097AB0: sltiu       $t5, $t2, 0x1
    ctx->r13 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80097AB4: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80097AB8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80097ABC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097AC0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80097AC4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80097AC8: jal         0x80097F78
    // 0x80097ACC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    Scheduler_ScheduleTask(rdram, ctx);
        goto after_2;
    // 0x80097ACC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80097AD0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80097AD4: nop

    // 0x80097AD8: beq         $v0, $t8, L_80097AF4
    if (ctx->r2 == ctx->r24) {
        // 0x80097ADC: nop

            goto L_80097AF4;
    }
    // 0x80097ADC: nop

    // 0x80097AE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097AE4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80097AE8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80097AEC: jal         0x80097DDC
    // 0x80097AF0: nop

    Scheduler_ExecuteTask(rdram, ctx);
        goto after_3;
    // 0x80097AF0: nop

    after_3:
L_80097AF4:
    // 0x80097AF4: b           L_80097AFC
    // 0x80097AF8: nop

        goto L_80097AFC;
    // 0x80097AF8: nop

L_80097AFC:
    // 0x80097AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097B00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097B04: jr          $ra
    // 0x80097B08: nop

    return;
    // 0x80097B08: nop

;}
RECOMP_FUNC void Scheduler_HandleRdpMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097B0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80097B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097B14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097B18: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80097B1C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80097B20: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097B24: nop

    // 0x80097B28: lw          $t7, 0x298($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X298);
    // 0x80097B2C: nop

    // 0x80097B30: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80097B34: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097B38: nop

    // 0x80097B3C: sw          $zero, 0x298($t8)
    MEM_W(0X298, ctx->r24) = 0;
    // 0x80097B40: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097B44: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80097B48: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80097B4C: nop

    // 0x80097B50: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80097B54: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80097B58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097B5C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80097B60: jal         0x80097C5C
    // 0x80097B64: nop

    Scheduler_IsTaskComplete(rdram, ctx);
        goto after_0;
    // 0x80097B64: nop

    after_0:
    // 0x80097B68: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80097B6C: nop

    // 0x80097B70: lw          $t3, 0x294($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X294);
    // 0x80097B74: lw          $t6, 0x298($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X298);
    // 0x80097B78: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80097B7C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80097B80: sltiu       $t7, $t6, 0x1
    ctx->r15 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80097B84: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80097B88: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80097B8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097B90: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80097B94: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80097B98: jal         0x80097F78
    // 0x80097B9C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    Scheduler_ScheduleTask(rdram, ctx);
        goto after_1;
    // 0x80097B9C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80097BA0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80097BA4: nop

    // 0x80097BA8: beq         $v0, $t0, L_80097BC4
    if (ctx->r2 == ctx->r8) {
        // 0x80097BAC: nop

            goto L_80097BC4;
    }
    // 0x80097BAC: nop

    // 0x80097BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097BB4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80097BB8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80097BBC: jal         0x80097DDC
    // 0x80097BC0: nop

    Scheduler_ExecuteTask(rdram, ctx);
        goto after_2;
    // 0x80097BC0: nop

    after_2:
L_80097BC4:
    // 0x80097BC4: b           L_80097BCC
    // 0x80097BC8: nop

        goto L_80097BCC;
    // 0x80097BC8: nop

L_80097BCC:
    // 0x80097BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097BD4: jr          $ra
    // 0x80097BD8: nop

    return;
    // 0x80097BD8: nop

;}
RECOMP_FUNC void Scheduler_IsTaskReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097BDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80097BE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097BE4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80097BE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80097BEC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80097BF0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80097BF4: nop

    // 0x80097BF8: beq         $t6, $zero, L_80097C3C
    if (ctx->r14 == 0) {
        // 0x80097BFC: nop

            goto L_80097C3C;
    }
    // 0x80097BFC: nop

    // 0x80097C00: jal         0x800C4160
    // 0x80097C04: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80097C04: nop

    after_0:
    // 0x80097C08: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80097C0C: jal         0x800C4E00
    // 0x80097C10: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80097C10: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_1:
    // 0x80097C14: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80097C18: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097C1C: nop

    // 0x80097C20: beq         $t7, $s0, L_80097C30
    if (ctx->r15 == ctx->r16) {
        // 0x80097C24: nop

            goto L_80097C30;
    }
    // 0x80097C24: nop

    // 0x80097C28: b           L_80097C4C
    // 0x80097C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097C4C;
    // 0x80097C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097C30:
    // 0x80097C30: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80097C34: b           L_80097C4C
    // 0x80097C38: nop

        goto L_80097C4C;
    // 0x80097C38: nop

L_80097C3C:
    // 0x80097C3C: b           L_80097C4C
    // 0x80097C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097C4C;
    // 0x80097C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097C44: b           L_80097C4C
    // 0x80097C48: nop

        goto L_80097C4C;
    // 0x80097C48: nop

L_80097C4C:
    // 0x80097C4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80097C50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097C54: jr          $ra
    // 0x80097C58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80097C58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Scheduler_IsTaskComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097C5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80097C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097C64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80097C68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097C6C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80097C70: nop

    // 0x80097C74: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80097C78: nop

    // 0x80097C7C: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x80097C80: bne         $t8, $zero, L_80097D24
    if (ctx->r24 != 0) {
        // 0x80097C84: nop

            goto L_80097D24;
    }
    // 0x80097C84: nop

    // 0x80097C88: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80097C90: lw          $a0, 0x50($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X50);
    // 0x80097C94: lw          $a1, 0x54($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X54);
    // 0x80097C98: jal         0x800C4AA0
    // 0x80097C9C: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80097C9C: nop

    after_0:
    // 0x80097CA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097CA4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097CA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80097CAC: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80097CB0: nop

    // 0x80097CB4: bne         $t1, $at, L_80097D1C
    if (ctx->r9 != ctx->r1) {
        // 0x80097CB8: nop

            goto L_80097D1C;
    }
    // 0x80097CB8: nop

    // 0x80097CBC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80097CC0: nop

    // 0x80097CC4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80097CC8: nop

    // 0x80097CCC: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x80097CD0: beq         $t4, $zero, L_80097D1C
    if (ctx->r12 == 0) {
        // 0x80097CD4: nop

            goto L_80097D1C;
    }
    // 0x80097CD4: nop

    // 0x80097CD8: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x80097CDC: beq         $t5, $zero, L_80097D1C
    if (ctx->r13 == 0) {
        // 0x80097CE0: nop

            goto L_80097D1C;
    }
    // 0x80097CE0: nop

    // 0x80097CE4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80097CE8: lw          $t6, -0x7344($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7344);
    // 0x80097CEC: nop

    // 0x80097CF0: beq         $t6, $zero, L_80097D08
    if (ctx->r14 == 0) {
        // 0x80097CF4: nop

            goto L_80097D08;
    }
    // 0x80097CF4: nop

    // 0x80097CF8: jal         0x800C46B0
    // 0x80097CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x80097CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80097D00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80097D04: sw          $zero, -0x7344($at)
    MEM_W(-0X7344, ctx->r1) = 0;
L_80097D08:
    // 0x80097D08: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097D0C: nop

    // 0x80097D10: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x80097D14: jal         0x800C4080
    // 0x80097D18: nop

    osViSwapBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x80097D18: nop

    after_2:
L_80097D1C:
    // 0x80097D1C: b           L_80097D34
    // 0x80097D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80097D34;
    // 0x80097D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80097D24:
    // 0x80097D24: b           L_80097D34
    // 0x80097D28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097D34;
    // 0x80097D28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097D2C: b           L_80097D34
    // 0x80097D30: nop

        goto L_80097D34;
    // 0x80097D30: nop

L_80097D34:
    // 0x80097D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097D38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097D3C: jr          $ra
    // 0x80097D40: nop

    return;
    // 0x80097D40: nop

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
RECOMP_FUNC void Scheduler_ExecuteTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097DDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80097DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097DE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80097DE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097DEC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80097DF0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80097DF4: nop

    // 0x80097DF8: beq         $t6, $zero, L_80097E84
    if (ctx->r14 == 0) {
        // 0x80097DFC: nop

            goto L_80097E84;
    }
    // 0x80097DFC: nop

    // 0x80097E00: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097E04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80097E08: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80097E0C: nop

    // 0x80097E10: bne         $t8, $at, L_80097E20
    if (ctx->r24 != ctx->r1) {
        // 0x80097E14: nop

            goto L_80097E20;
    }
    // 0x80097E14: nop

    // 0x80097E18: jal         0x800C4270
    // 0x80097E1C: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80097E1C: nop

    after_0:
L_80097E20:
    // 0x80097E20: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097E24: addiu       $at, $zero, -0x31
    ctx->r1 = ADD32(0, -0X31);
    // 0x80097E28: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80097E2C: nop

    // 0x80097E30: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80097E34: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80097E38: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80097E3C: jal         0x800C4F5C
    // 0x80097E40: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_1;
    // 0x80097E40: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x80097E44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80097E48: jal         0x800C50BC
    // 0x80097E4C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_2;
    // 0x80097E4C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_2:
    // 0x80097E50: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80097E54: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80097E58: nop

    // 0x80097E5C: sw          $t2, 0x294($t3)
    MEM_W(0X294, ctx->r11) = ctx->r10;
    // 0x80097E60: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80097E64: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80097E68: nop

    // 0x80097E6C: bne         $t4, $t5, L_80097E84
    if (ctx->r12 != ctx->r13) {
        // 0x80097E70: nop

            goto L_80097E84;
    }
    // 0x80097E70: nop

    // 0x80097E74: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097E78: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80097E7C: nop

    // 0x80097E80: sw          $t6, 0x298($t7)
    MEM_W(0X298, ctx->r15) = ctx->r14;
L_80097E84:
    // 0x80097E84: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097E88: nop

    // 0x80097E8C: beq         $t8, $zero, L_80097EEC
    if (ctx->r24 == 0) {
        // 0x80097E90: nop

            goto L_80097EEC;
    }
    // 0x80097E90: nop

    // 0x80097E94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097E98: nop

    // 0x80097E9C: beq         $t8, $t0, L_80097EEC
    if (ctx->r24 == ctx->r8) {
        // 0x80097EA0: nop

            goto L_80097EEC;
    }
    // 0x80097EA0: nop

    // 0x80097EA4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80097EA8: nop

    // 0x80097EAC: lw          $t9, 0x3C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X3C);
    // 0x80097EB0: lw          $a0, 0x38($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X38);
    // 0x80097EB4: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80097EB8: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x80097EBC: jal         0x800C5100
    // 0x80097EC0: nop

    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80097EC0: nop

    after_3:
    // 0x80097EC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097EC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80097ECC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80097ED0: sw          $t2, -0x734C($at)
    MEM_W(-0X734C, ctx->r1) = ctx->r10;
    // 0x80097ED4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80097ED8: sw          $zero, -0x7348($at)
    MEM_W(-0X7348, ctx->r1) = 0;
    // 0x80097EDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80097EE0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80097EE4: nop

    // 0x80097EE8: sw          $t3, 0x298($t4)
    MEM_W(0X298, ctx->r12) = ctx->r11;
L_80097EEC:
    // 0x80097EEC: b           L_80097EF4
    // 0x80097EF0: nop

        goto L_80097EF4;
    // 0x80097EF0: nop

L_80097EF4:
    // 0x80097EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097EF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097EFC: jr          $ra
    // 0x80097F00: nop

    return;
    // 0x80097F00: nop

;}
RECOMP_FUNC void Scheduler_RspTaskYield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097F0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097F10: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80097F14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80097F18: lw          $t7, 0x294($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X294);
    // 0x80097F1C: nop

    // 0x80097F20: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80097F24: nop

    // 0x80097F28: bne         $t8, $at, L_80097F60
    if (ctx->r24 != ctx->r1) {
        // 0x80097F2C: nop

            goto L_80097F60;
    }
    // 0x80097F2C: nop

    // 0x80097F30: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80097F34: nop

    // 0x80097F38: lw          $t0, 0x294($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X294);
    // 0x80097F3C: nop

    // 0x80097F40: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80097F44: nop

    // 0x80097F48: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80097F4C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80097F50: jal         0x800C51B0
    // 0x80097F54: nop

    osSpTaskYield_recomp(rdram, ctx);
        goto after_0;
    // 0x80097F54: nop

    after_0:
    // 0x80097F58: b           L_80097F60
    // 0x80097F5C: nop

        goto L_80097F60;
    // 0x80097F5C: nop

L_80097F60:
    // 0x80097F60: b           L_80097F68
    // 0x80097F64: nop

        goto L_80097F68;
    // 0x80097F64: nop

L_80097F68:
    // 0x80097F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097F70: jr          $ra
    // 0x80097F74: nop

    return;
    // 0x80097F74: nop

;}
RECOMP_FUNC void Scheduler_ScheduleTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097F78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80097F7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097F80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097F84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80097F88: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80097F8C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80097F90: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80097F94: nop

    // 0x80097F98: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80097F9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80097FA0: nop

    // 0x80097FA4: lw          $t8, 0x288($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X288);
    // 0x80097FA8: nop

    // 0x80097FAC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80097FB0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80097FB4: nop

    // 0x80097FB8: lw          $t0, 0x284($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X284);
    // 0x80097FBC: nop

    // 0x80097FC0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80097FC4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80097FC8: nop

    // 0x80097FCC: lw          $t2, 0x2A4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2A4);
    // 0x80097FD0: nop

    // 0x80097FD4: beq         $t2, $zero, L_800980AC
    if (ctx->r10 == 0) {
        // 0x80097FD8: nop

            goto L_800980AC;
    }
    // 0x80097FD8: nop

    // 0x80097FDC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80097FE0: nop

    // 0x80097FE4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80097FE8: beq         $t4, $zero, L_800980AC
    if (ctx->r12 == 0) {
        // 0x80097FEC: nop

            goto L_800980AC;
    }
    // 0x80097FEC: nop

    // 0x80097FF0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80097FF4: nop

    // 0x80097FF8: beq         $t5, $zero, L_80098038
    if (ctx->r13 == 0) {
        // 0x80097FFC: nop

            goto L_80098038;
    }
    // 0x80097FFC: nop

    // 0x80098000: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80098004: nop

    // 0x80098008: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8009800C: beq         $t7, $zero, L_80098038
    if (ctx->r15 == 0) {
        // 0x80098010: nop

            goto L_80098038;
    }
    // 0x80098010: nop

    // 0x80098014: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80098018: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8009801C: nop

    // 0x80098020: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80098024: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80098028: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8009802C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80098030: b           L_800980A4
    // 0x80098034: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
        goto L_800980A4;
    // 0x80098034: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80098038:
    // 0x80098038: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8009803C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80098040: nop

    // 0x80098044: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80098048: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8009804C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80098050: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80098054: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80098058: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009805C: nop

    // 0x80098060: sw          $zero, 0x2A4($t6)
    MEM_W(0X2A4, ctx->r14) = 0;
    // 0x80098064: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80098068: nop

    // 0x8009806C: lw          $t8, 0x284($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X284);
    // 0x80098070: nop

    // 0x80098074: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80098078: nop

    // 0x8009807C: sw          $t9, 0x284($t7)
    MEM_W(0X284, ctx->r15) = ctx->r25;
    // 0x80098080: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80098084: nop

    // 0x80098088: lw          $t1, 0x284($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X284);
    // 0x8009808C: nop

    // 0x80098090: bne         $t1, $zero, L_800980A4
    if (ctx->r9 != 0) {
        // 0x80098094: nop

            goto L_800980A4;
    }
    // 0x80098094: nop

    // 0x80098098: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8009809C: nop

    // 0x800980A0: sw          $zero, 0x28C($t2)
    MEM_W(0X28C, ctx->r10) = 0;
L_800980A4:
    // 0x800980A4: b           L_80098358
    // 0x800980A8: nop

        goto L_80098358;
    // 0x800980A8: nop

L_800980AC:
    // 0x800980AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800980B0: jal         0x80097BDC
    // 0x800980B4: nop

    Scheduler_IsTaskReady(rdram, ctx);
        goto after_0;
    // 0x800980B4: nop

    after_0:
    // 0x800980B8: beq         $v0, $zero, L_80098358
    if (ctx->r2 == 0) {
        // 0x800980BC: nop

            goto L_80098358;
    }
    // 0x800980BC: nop

    // 0x800980C0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800980C4: nop

    // 0x800980C8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800980CC: nop

    // 0x800980D0: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x800980D4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800980D8: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x800980DC: beq         $at, $zero, L_80098350
    if (ctx->r1 == 0) {
        // 0x800980E0: nop

            goto L_80098350;
    }
    // 0x800980E0: nop

    // 0x800980E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800980E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800980EC: addu        $at, $at, $t6
    gpr jr_addend_800980F8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800980F0: lw          $t6, -0x870($at)
    ctx->r14 = ADD32(ctx->r1, -0X870);
    // 0x800980F4: nop

    // 0x800980F8: jr          $t6
    // 0x800980FC: nop

    switch (jr_addend_800980F8 >> 2) {
        case 0: goto L_80098350; break;
        case 1: goto L_80098260; break;
        case 2: goto L_80098100; break;
        case 3: goto L_80098350; break;
        case 4: goto L_80098350; break;
        case 5: goto L_80098260; break;
        case 6: goto L_80098260; break;
        default: switch_error(__func__, 0x800980F8, 0x800EF790);
    }
    // 0x800980FC: nop

L_80098100:
    // 0x80098100: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80098104: nop

    // 0x80098108: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8009810C: nop

    // 0x80098110: andi        $t7, $t9, 0x20
    ctx->r15 = ctx->r25 & 0X20;
    // 0x80098114: beq         $t7, $zero, L_800981D4
    if (ctx->r15 == 0) {
        // 0x80098118: nop

            goto L_800981D4;
    }
    // 0x80098118: nop

    // 0x8009811C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80098120: nop

    // 0x80098124: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80098128: beq         $t1, $zero, L_800981CC
    if (ctx->r9 == 0) {
        // 0x8009812C: nop

            goto L_800981CC;
    }
    // 0x8009812C: nop

    // 0x80098130: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80098134: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80098138: nop

    // 0x8009813C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80098140: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80098144: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80098148: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8009814C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80098150: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80098154: nop

    // 0x80098158: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8009815C: nop

    // 0x80098160: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80098164: beq         $t9, $zero, L_8009818C
    if (ctx->r25 == 0) {
        // 0x80098168: nop

            goto L_8009818C;
    }
    // 0x80098168: nop

    // 0x8009816C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80098170: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80098174: nop

    // 0x80098178: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8009817C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80098180: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80098184: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80098188: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_8009818C:
    // 0x8009818C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80098190: nop

    // 0x80098194: lw          $t4, 0x288($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X288);
    // 0x80098198: nop

    // 0x8009819C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800981A0: nop

    // 0x800981A4: sw          $t5, 0x288($t3)
    MEM_W(0X288, ctx->r11) = ctx->r13;
    // 0x800981A8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800981AC: nop

    // 0x800981B0: lw          $t8, 0x288($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X288);
    // 0x800981B4: nop

    // 0x800981B8: bne         $t8, $zero, L_800981CC
    if (ctx->r24 != 0) {
        // 0x800981BC: nop

            goto L_800981CC;
    }
    // 0x800981BC: nop

    // 0x800981C0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800981C4: nop

    // 0x800981C8: sw          $zero, 0x290($t9)
    MEM_W(0X290, ctx->r25) = 0;
L_800981CC:
    // 0x800981CC: b           L_80098258
    // 0x800981D0: nop

        goto L_80098258;
    // 0x800981D0: nop

L_800981D4:
    // 0x800981D4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800981D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800981DC: bne         $t7, $at, L_80098258
    if (ctx->r15 != ctx->r1) {
        // 0x800981E0: nop

            goto L_80098258;
    }
    // 0x800981E0: nop

    // 0x800981E4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800981E8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800981EC: nop

    // 0x800981F0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800981F4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800981F8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800981FC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80098200: nop

    // 0x80098204: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80098208: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8009820C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80098210: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x80098214: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80098218: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8009821C: nop

    // 0x80098220: lw          $t9, 0x288($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X288);
    // 0x80098224: nop

    // 0x80098228: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8009822C: nop

    // 0x80098230: sw          $t7, 0x288($t8)
    MEM_W(0X288, ctx->r24) = ctx->r15;
    // 0x80098234: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80098238: nop

    // 0x8009823C: lw          $t1, 0x288($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X288);
    // 0x80098240: nop

    // 0x80098244: bne         $t1, $zero, L_80098258
    if (ctx->r9 != 0) {
        // 0x80098248: nop

            goto L_80098258;
    }
    // 0x80098248: nop

    // 0x8009824C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80098250: nop

    // 0x80098254: sw          $zero, 0x290($t2)
    MEM_W(0X290, ctx->r10) = 0;
L_80098258:
    // 0x80098258: b           L_80098358
    // 0x8009825C: nop

        goto L_80098358;
    // 0x8009825C: nop

L_80098260:
    // 0x80098260: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80098264: nop

    // 0x80098268: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8009826C: nop

    // 0x80098270: andi        $t3, $t5, 0x2
    ctx->r11 = ctx->r13 & 0X2;
    // 0x80098274: beq         $t3, $zero, L_800982B8
    if (ctx->r11 == 0) {
        // 0x80098278: nop

            goto L_800982B8;
    }
    // 0x80098278: nop

    // 0x8009827C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80098280: nop

    // 0x80098284: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x80098288: beq         $t9, $zero, L_800982B0
    if (ctx->r25 == 0) {
        // 0x8009828C: nop

            goto L_800982B0;
    }
    // 0x8009828C: nop

    // 0x80098290: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80098294: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80098298: nop

    // 0x8009829C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800982A0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800982A4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800982A8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800982AC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_800982B0:
    // 0x800982B0: b           L_80098348
    // 0x800982B4: nop

        goto L_80098348;
    // 0x800982B4: nop

L_800982B8:
    // 0x800982B8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800982BC: nop

    // 0x800982C0: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x800982C4: nop

    // 0x800982C8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800982CC: beq         $t5, $zero, L_80098348
    if (ctx->r13 == 0) {
        // 0x800982D0: nop

            goto L_80098348;
    }
    // 0x800982D0: nop

    // 0x800982D4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800982D8: nop

    // 0x800982DC: andi        $t6, $t3, 0x1
    ctx->r14 = ctx->r11 & 0X1;
    // 0x800982E0: beq         $t6, $zero, L_80098348
    if (ctx->r14 == 0) {
        // 0x800982E4: nop

            goto L_80098348;
    }
    // 0x800982E4: nop

    // 0x800982E8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800982EC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800982F0: nop

    // 0x800982F4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800982F8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800982FC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80098300: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80098304: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80098308: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8009830C: nop

    // 0x80098310: lw          $t2, 0x288($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X288);
    // 0x80098314: nop

    // 0x80098318: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8009831C: nop

    // 0x80098320: sw          $t4, 0x288($t1)
    MEM_W(0X288, ctx->r9) = ctx->r12;
    // 0x80098324: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80098328: nop

    // 0x8009832C: lw          $t3, 0x288($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X288);
    // 0x80098330: nop

    // 0x80098334: bne         $t3, $zero, L_80098348
    if (ctx->r11 != 0) {
        // 0x80098338: nop

            goto L_80098348;
    }
    // 0x80098338: nop

    // 0x8009833C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80098340: nop

    // 0x80098344: sw          $zero, 0x290($t6)
    MEM_W(0X290, ctx->r14) = 0;
L_80098348:
    // 0x80098348: b           L_80098358
    // 0x8009834C: nop

        goto L_80098358;
    // 0x8009834C: nop

L_80098350:
    // 0x80098350: b           L_80098358
    // 0x80098354: nop

        goto L_80098358;
    // 0x80098354: nop

L_80098358:
    // 0x80098358: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8009835C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80098360: nop

    // 0x80098364: beq         $t9, $t7, L_80098388
    if (ctx->r25 == ctx->r15) {
        // 0x80098368: nop

            goto L_80098388;
    }
    // 0x80098368: nop

    // 0x8009836C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80098370: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80098374: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80098378: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8009837C: jal         0x80097F78
    // 0x80098380: nop

    Scheduler_ScheduleTask(rdram, ctx);
        goto after_1;
    // 0x80098380: nop

    after_1:
    // 0x80098384: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80098388:
    // 0x80098388: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8009838C: b           L_8009839C
    // 0x80098390: nop

        goto L_8009839C;
    // 0x80098390: nop

    // 0x80098394: b           L_8009839C
    // 0x80098398: nop

        goto L_8009839C;
    // 0x80098398: nop

L_8009839C:
    // 0x8009839C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800983A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800983A4: jr          $ra
    // 0x800983A8: nop

    return;
    // 0x800983A8: nop

;}
RECOMP_FUNC void func_800983AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800983AC: nop

;}
RECOMP_FUNC void InitScheduler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800983B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800983B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800983B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800983BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800983C0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800983C4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800983C8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800983CC: jal         0x80096EE0
    // 0x800983D0: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    Scheduler_CreateScheduler(rdram, ctx);
        goto after_0;
    // 0x800983D0: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_0:
    // 0x800983D4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800983D8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800983DC: addiu       $a1, $a1, -0x37B0
    ctx->r5 = ADD32(ctx->r5, -0X37B0);
    // 0x800983E0: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x800983E4: jal         0x800C14E0
    // 0x800983E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Thread_CreateMesgQueue(rdram, ctx);
        goto after_1;
    // 0x800983E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800983EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800983F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800983F4: sh          $t6, -0x3778($at)
    MEM_H(-0X3778, ctx->r1) = ctx->r14;
    // 0x800983F8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800983FC: addiu       $t7, $t7, -0x3758
    ctx->r15 = ADD32(ctx->r15, -0X3758);
    // 0x80098400: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80098404: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80098408: nop

    // 0x8009840C: sw          $zero, 0x294($t8)
    MEM_W(0X294, ctx->r24) = 0;
    // 0x80098410: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80098414: nop

    // 0x80098418: sw          $zero, 0x298($t9)
    MEM_W(0X298, ctx->r25) = 0;
    // 0x8009841C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80098420: nop

    // 0x80098424: sw          $zero, 0x280($t0)
    MEM_W(0X280, ctx->r8) = 0;
    // 0x80098428: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8009842C: nop

    // 0x80098430: sw          $zero, 0x29C($t1)
    MEM_W(0X29C, ctx->r9) = 0;
    // 0x80098434: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80098438: nop

    // 0x8009843C: sw          $zero, 0x2A0($t2)
    MEM_W(0X2A0, ctx->r10) = 0;
    // 0x80098440: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80098444: nop

    // 0x80098448: sw          $zero, 0x284($t3)
    MEM_W(0X284, ctx->r11) = 0;
    // 0x8009844C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80098450: nop

    // 0x80098454: sw          $zero, 0x288($t4)
    MEM_W(0X288, ctx->r12) = 0;
    // 0x80098458: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8009845C: nop

    // 0x80098460: sw          $zero, 0x28C($t5)
    MEM_W(0X28C, ctx->r13) = 0;
    // 0x80098464: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80098468: nop

    // 0x8009846C: sw          $zero, 0x290($t6)
    MEM_W(0X290, ctx->r14) = 0;
    // 0x80098470: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80098474: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80098478: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8009847C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80098480: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80098484: sh          $t9, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r25;
    // 0x80098488: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8009848C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80098490: sh          $t1, 0x40($t2)
    MEM_H(0X40, ctx->r10) = ctx->r9;
    // 0x80098494: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80098498: sw          $zero, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = 0;
    // 0x8009849C: b           L_800984A4
    // 0x800984A0: nop

        goto L_800984A4;
    // 0x800984A0: nop

L_800984A4:
    // 0x800984A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800984A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800984AC: jr          $ra
    // 0x800984B0: nop

    return;
    // 0x800984B0: nop

;}
RECOMP_FUNC void CreateSchedulerThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800984B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800984B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800984BC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800984C0: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x800984C4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800984C8: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x800984CC: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x800984D0: jal         0x80097068
    // 0x800984D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    Scheduler_CreateSchedulerThread(rdram, ctx);
        goto after_0;
    // 0x800984D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x800984D8: b           L_800984E0
    // 0x800984DC: nop

        goto L_800984E0;
    // 0x800984DC: nop

L_800984E0:
    // 0x800984E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800984E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800984E8: jr          $ra
    // 0x800984EC: nop

    return;
    // 0x800984EC: nop

;}
RECOMP_FUNC void func_800984F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800984F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800984F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800984F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800984FC: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80098500: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80098504: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80098508: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009850C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80098510: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80098514: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80098518: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009851C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80098520: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x80098524: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80098528: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009852C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80098530: nop

    // 0x80098534: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80098538: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x8009853C: nop

    // 0x80098540: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80098544: bne         $t2, $zero, L_80098554
    if (ctx->r10 != 0) {
        // 0x80098548: nop

            goto L_80098554;
    }
    // 0x80098548: nop

    // 0x8009854C: b           L_800985AC
    // 0x80098550: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800985AC;
    // 0x80098550: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098554:
    // 0x80098554: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x80098558: jal         0x800C1154
    // 0x8009855C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C1154(rdram, ctx);
        goto after_0;
    // 0x8009855C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80098560: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80098564: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x80098568: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    // 0x8009856C: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x80098570: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80098574: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x80098578: jal         0x80097258
    // 0x8009857C: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    func_80097258(rdram, ctx);
        goto after_1;
    // 0x8009857C: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    after_1:
    // 0x80098580: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80098584: nop

    // 0x80098588: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x8009858C: lbu         $t5, 0x2E9($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2E9);
    // 0x80098590: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80098594: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80098598: sb          $t6, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r14;
    // 0x8009859C: b           L_800985AC
    // 0x800985A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800985AC;
    // 0x800985A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800985A4: b           L_800985AC
    // 0x800985A8: nop

        goto L_800985AC;
    // 0x800985A8: nop

L_800985AC:
    // 0x800985AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800985B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800985B4: jr          $ra
    // 0x800985B8: nop

    return;
    // 0x800985B8: nop

;}
RECOMP_FUNC void func_800985BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800985BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800985C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800985C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800985C8: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800985CC: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800985D0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800985D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800985D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800985DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800985E0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800985E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800985E8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800985EC: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800985F0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800985F4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800985F8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800985FC: nop

    // 0x80098600: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80098604: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x80098608: nop

    // 0x8009860C: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80098610: bne         $t2, $zero, L_80098620
    if (ctx->r10 != 0) {
        // 0x80098614: nop

            goto L_80098620;
    }
    // 0x80098614: nop

    // 0x80098618: b           L_80098678
    // 0x8009861C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098678;
    // 0x8009861C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098620:
    // 0x80098620: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x80098624: jal         0x800C1154
    // 0x80098628: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C1154(rdram, ctx);
        goto after_0;
    // 0x80098628: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8009862C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80098630: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x80098634: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    // 0x80098638: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x8009863C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80098640: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x80098644: jal         0x80097150
    // 0x80098648: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    func_80097150(rdram, ctx);
        goto after_1;
    // 0x80098648: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    after_1:
    // 0x8009864C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80098650: nop

    // 0x80098654: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x80098658: lbu         $t5, 0x2E9($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2E9);
    // 0x8009865C: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80098660: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80098664: sb          $t6, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r14;
    // 0x80098668: b           L_80098678
    // 0x8009866C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098678;
    // 0x8009866C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098670: b           L_80098678
    // 0x80098674: nop

        goto L_80098678;
    // 0x80098674: nop

L_80098678:
    // 0x80098678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009867C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098680: jr          $ra
    // 0x80098684: nop

    return;
    // 0x80098684: nop

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
RECOMP_FUNC void func_80098754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098754: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009875C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80098760: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80098764: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80098768: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8009876C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098770: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80098774: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80098778: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8009877C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098780: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80098784: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x80098788: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8009878C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80098790: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80098794: nop

    // 0x80098798: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x8009879C: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800987A0: nop

    // 0x800987A4: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800987A8: bne         $t2, $zero, L_800987B8
    if (ctx->r10 != 0) {
        // 0x800987AC: nop

            goto L_800987B8;
    }
    // 0x800987AC: nop

    // 0x800987B0: b           L_80098810
    // 0x800987B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098810;
    // 0x800987B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800987B8:
    // 0x800987B8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800987BC: jal         0x800C1154
    // 0x800987C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C1154(rdram, ctx);
        goto after_0;
    // 0x800987C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x800987C4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800987C8: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x800987CC: addu        $a1, $t3, $at
    ctx->r5 = ADD32(ctx->r11, ctx->r1);
    // 0x800987D0: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800987D4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800987D8: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    // 0x800987DC: jal         0x80097258
    // 0x800987E0: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    func_80097258(rdram, ctx);
        goto after_1;
    // 0x800987E0: addu        $a2, $t3, $at
    ctx->r6 = ADD32(ctx->r11, ctx->r1);
    after_1:
    // 0x800987E4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800987E8: nop

    // 0x800987EC: addiu       $t5, $t4, 0x7FFF
    ctx->r13 = ADD32(ctx->r12, 0X7FFF);
    // 0x800987F0: lbu         $t5, 0x2E9($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2E9);
    // 0x800987F4: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x800987F8: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x800987FC: sb          $t6, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r14;
    // 0x80098800: b           L_80098810
    // 0x80098804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098810;
    // 0x80098804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098808: b           L_80098810
    // 0x8009880C: nop

        goto L_80098810;
    // 0x8009880C: nop

L_80098810:
    // 0x80098810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098818: jr          $ra
    // 0x8009881C: nop

    return;
    // 0x8009881C: nop

;}
