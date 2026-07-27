#include "recomp.h"
#include "funcs.h"

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
RECOMP_FUNC void MtxUtil_CopyOrientation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2C84: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C2C88: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800C2C8C: nop

    // 0x800C2C90: bne         $t6, $zero, L_800C2CA8
    if (ctx->r14 != 0) {
        // 0x800C2C94: nop
    
            goto L_800C2CA8;
    }
    // 0x800C2C94: nop

    // 0x800C2C98: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C2C9C: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C2CA0: b           L_800C2CAC
    // 0x800C2CA4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
        goto L_800C2CAC;
    // 0x800C2CA4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
L_800C2CA8:
    // 0x800C2CA8: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
L_800C2CAC:
    // 0x800C2CAC: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800C2CB0: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800C2CB4:
    // 0x800C2CB4: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C2CB8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C2CBC: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C2CC0: nop

    // 0x800C2CC4: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C2CC8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C2CCC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C2CD0: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C2CD4: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C2CD8: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C2CDC: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C2CE0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C2CE4: nop

    // 0x800C2CE8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C2CEC: slti        $at, $t5, 0xC
    ctx->r1 = SIGNED(ctx->r13) < 0XC ? 1 : 0;
    // 0x800C2CF0: bne         $at, $zero, L_800C2CB4
    if (ctx->r1 != 0) {
        // 0x800C2CF4: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C2CB4;
    }
    // 0x800C2CF4: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C2CF8: b           L_800C2D00
    // 0x800C2CFC: nop

        goto L_800C2D00;
    // 0x800C2CFC: nop

L_800C2D00:
    // 0x800C2D00: jr          $ra
    // 0x800C2D04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C2D04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80068B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B08: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068B0C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068B10: nop

    // 0x80068B14: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068B18: nop

    // 0x80068B1C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068B20: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068B24: jr          $ra
    // 0x80068B28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068B28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068B2C: jr          $ra
    // 0x80068B30: nop

    return;
    // 0x80068B30: nop

    // 0x80068B34: jr          $ra
    // 0x80068B38: nop

    return;
    // 0x80068B38: nop

;}
RECOMP_FUNC void func_8006C2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C2A8: jal         0x8005F064
    // 0x8006C2AC: addiu       $a0, $zero, 0xB7
    ctx->r4 = ADD32(0, 0XB7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C2AC: addiu       $a0, $zero, 0xB7
    ctx->r4 = ADD32(0, 0XB7);
    after_0:
    // 0x8006C2B0: b           L_8006C2C0
    // 0x8006C2B4: nop

        goto L_8006C2C0;
    // 0x8006C2B4: nop

    // 0x8006C2B8: b           L_8006C2C0
    // 0x8006C2BC: nop

        goto L_8006C2C0;
    // 0x8006C2BC: nop

L_8006C2C0:
    // 0x8006C2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C2C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C2C8: jr          $ra
    // 0x8006C2CC: nop

    return;
    // 0x8006C2CC: nop

;}
RECOMP_FUNC void func_800639F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800639F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800639F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800639F8: nop

    // 0x800639FC: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x80063A00: nop

    // 0x80063A04: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80063A08: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063A0C: jr          $ra
    // 0x80063A10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063A10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063A14: jr          $ra
    // 0x80063A18: nop

    return;
    // 0x80063A18: nop

    // 0x80063A1C: jr          $ra
    // 0x80063A20: nop

    return;
    // 0x80063A20: nop

;}
RECOMP_FUNC void func_800660D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800660DC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800660E0: nop

    // 0x800660E4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800660E8: nop

    // 0x800660EC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800660F0: jr          $ra
    // 0x800660F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800660F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800660F8: jr          $ra
    // 0x800660FC: nop

    return;
    // 0x800660FC: nop

    // 0x80066100: jr          $ra
    // 0x80066104: nop

    return;
    // 0x80066104: nop

;}
RECOMP_FUNC void func_80072F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072F50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072F54: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072F58: nop

    // 0x80072F5C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072F60: nop

    // 0x80072F64: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072F68: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072F6C: jr          $ra
    // 0x80072F70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072F70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072F74: jr          $ra
    // 0x80072F78: nop

    return;
    // 0x80072F78: nop

    // 0x80072F7C: jr          $ra
    // 0x80072F80: nop

    return;
    // 0x80072F80: nop

;}
RECOMP_FUNC void func_80085CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085CC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80085CCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CD0: jal         0x8008A46C
    // 0x80085CD4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80085CD4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80085CD8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80085CDC: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80085CE0: jal         0x8008BFF4
    // 0x80085CE4: nop

    func_8008BFF4(rdram, ctx);
        goto after_1;
    // 0x80085CE4: nop

    after_1:
    // 0x80085CE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CEC: jal         0x80089170
    // 0x80085CF0: nop

    func_80089170(rdram, ctx);
        goto after_2;
    // 0x80085CF0: nop

    after_2:
    // 0x80085CF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CF8: jal         0x80089418
    // 0x80085CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80089418(rdram, ctx);
        goto after_3;
    // 0x80085CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80085D00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80085D04: nop

    // 0x80085D08: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80085D0C: b           L_80085D1C
    // 0x80085D10: nop

        goto L_80085D1C;
    // 0x80085D10: nop

    // 0x80085D14: b           L_80085D1C
    // 0x80085D18: nop

        goto L_80085D1C;
    // 0x80085D18: nop

L_80085D1C:
    // 0x80085D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085D24: jr          $ra
    // 0x80085D28: nop

    return;
    // 0x80085D28: nop

;}
RECOMP_FUNC void func_800851C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800851C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800851CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800851D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800851D4: jal         0x8008A46C
    // 0x800851D8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x800851D8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x800851DC: jal         0x8008C160
    // 0x800851E0: nop

    func_8008C160(rdram, ctx);
        goto after_1;
    // 0x800851E0: nop

    after_1:
    // 0x800851E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800851E8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800851EC: addiu       $t6, $t6, 0x4720
    ctx->r14 = ADD32(ctx->r14, 0X4720);
    // 0x800851F0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800851F4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800851F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800851FC: beq         $t7, $at, L_800852F4
    if (ctx->r15 == ctx->r1) {
        // 0x80085200: nop
    
            goto L_800852F4;
    }
    // 0x80085200: nop

L_80085204:
    // 0x80085204: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80085208: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008520C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80085210: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80085214: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80085218: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8008521C: lh          $t0, 0x4726($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X4726);
    // 0x80085220: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80085224: bne         $t0, $at, L_800852C8
    if (ctx->r8 != ctx->r1) {
        // 0x80085228: nop
    
            goto L_800852C8;
    }
    // 0x80085228: nop

    // 0x8008522C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80085230: nop

    // 0x80085234: bne         $t1, $zero, L_80085280
    if (ctx->r9 != 0) {
        // 0x80085238: nop
    
            goto L_80085280;
    }
    // 0x80085238: nop

    // 0x8008523C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80085240: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085244: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80085248: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008524C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80085250: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80085254: addiu       $t2, $zero, 0x81
    ctx->r10 = ADD32(0, 0X81);
    // 0x80085258: sh          $t2, 0x4728($at)
    MEM_H(0X4728, ctx->r1) = ctx->r10;
    // 0x8008525C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80085260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085264: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80085268: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008526C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80085270: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80085274: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80085278: b           L_800852C0
    // 0x8008527C: sh          $t5, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r13;
        goto L_800852C0;
    // 0x8008527C: sh          $t5, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r13;
L_80085280:
    // 0x80085280: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80085284: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085288: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008528C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80085290: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80085294: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80085298: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8008529C: sh          $t8, 0x4728($at)
    MEM_H(0X4728, ctx->r1) = ctx->r24;
    // 0x800852A0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800852A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800852A8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x800852AC: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x800852B0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800852B4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800852B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800852BC: sh          $t1, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r9;
L_800852C0:
    // 0x800852C0: b           L_800852F4
    // 0x800852C4: nop

        goto L_800852F4;
    // 0x800852C4: nop

L_800852C8:
    // 0x800852C8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800852CC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800852D0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800852D4: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x800852D8: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x800852DC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800852E0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800852E4: lh          $t7, 0x4720($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X4720);
    // 0x800852E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800852EC: bne         $t7, $at, L_80085204
    if (ctx->r15 != ctx->r1) {
        // 0x800852F0: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_80085204;
    }
    // 0x800852F0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800852F4:
    // 0x800852F4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800852F8: addiu       $t9, $t9, 0x4720
    ctx->r25 = ADD32(ctx->r25, 0X4720);
    // 0x800852FC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80085300: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x80085304: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085308: beq         $t8, $at, L_8008541C
    if (ctx->r24 == ctx->r1) {
        // 0x8008530C: nop
    
            goto L_8008541C;
    }
    // 0x8008530C: nop

L_80085310:
    // 0x80085310: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80085314: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085318: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8008531C: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x80085320: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80085324: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80085328: lh          $t1, 0x4726($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4726);
    // 0x8008532C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085330: bne         $t1, $at, L_800853F0
    if (ctx->r9 != ctx->r1) {
        // 0x80085334: nop
    
            goto L_800853F0;
    }
    // 0x80085334: nop

    // 0x80085338: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008533C: nop

    // 0x80085340: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80085344: beq         $at, $zero, L_800853A8
    if (ctx->r1 == 0) {
        // 0x80085348: nop
    
            goto L_800853A8;
    }
    // 0x80085348: nop

    // 0x8008534C: beq         $t2, $zero, L_80085364
    if (ctx->r10 == 0) {
        // 0x80085350: nop
    
            goto L_80085364;
    }
    // 0x80085350: nop

    // 0x80085354: jal         0x8008C1F0
    // 0x80085358: nop

    func_8008C1F0(rdram, ctx);
        goto after_2;
    // 0x80085358: nop

    after_2:
    // 0x8008535C: bne         $v0, $zero, L_800853A8
    if (ctx->r2 != 0) {
        // 0x80085360: nop
    
            goto L_800853A8;
    }
    // 0x80085360: nop

L_80085364:
    // 0x80085364: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80085368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008536C: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80085370: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x80085374: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80085378: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8008537C: addiu       $t4, $zero, 0x81
    ctx->r12 = ADD32(0, 0X81);
    // 0x80085380: sh          $t4, 0x4728($at)
    MEM_H(0X4728, ctx->r1) = ctx->r12;
    // 0x80085384: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80085388: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008538C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80085390: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80085394: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085398: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008539C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800853A0: b           L_800853E8
    // 0x800853A4: sh          $t7, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r15;
        goto L_800853E8;
    // 0x800853A4: sh          $t7, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r15;
L_800853A8:
    // 0x800853A8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800853AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800853B0: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x800853B4: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x800853B8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800853BC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800853C0: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800853C4: sh          $t0, 0x4728($at)
    MEM_H(0X4728, ctx->r1) = ctx->r8;
    // 0x800853C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800853CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800853D0: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800853D4: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x800853D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800853DC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800853E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800853E4: sh          $t2, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r10;
L_800853E8:
    // 0x800853E8: b           L_8008541C
    // 0x800853EC: nop

        goto L_8008541C;
    // 0x800853EC: nop

L_800853F0:
    // 0x800853F0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800853F4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800853F8: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x800853FC: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80085400: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x80085404: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80085408: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008540C: lh          $t8, 0x4720($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X4720);
    // 0x80085410: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085414: bne         $t8, $at, L_80085310
    if (ctx->r24 != ctx->r1) {
        // 0x80085418: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_80085310;
    }
    // 0x80085418: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008541C:
    // 0x8008541C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80085420: jal         0x80089170
    // 0x80085424: nop

    func_80089170(rdram, ctx);
        goto after_3;
    // 0x80085424: nop

    after_3:
    // 0x80085428: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8008542C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80085430: jal         0x800898D8
    // 0x80085434: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800898D8(rdram, ctx);
        goto after_4;
    // 0x80085434: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80085438: beq         $v0, $zero, L_80085488
    if (ctx->r2 == 0) {
        // 0x8008543C: nop
    
            goto L_80085488;
    }
    // 0x8008543C: nop

    // 0x80085440: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80085444: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x80085448: lh          $t6, 0x28($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X28);
    // 0x8008544C: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x80085450: addu        $a1, $t3, $t0
    ctx->r5 = ADD32(ctx->r11, ctx->r8);
    // 0x80085454: addu        $a2, $t6, $t2
    ctx->r6 = ADD32(ctx->r14, ctx->r10);
    // 0x80085458: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008545C: bgez        $a1, L_8008546C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80085460: sra         $t1, $a1, 1
        ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8008546C;
    }
    // 0x80085460: sra         $t1, $a1, 1
    ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80085464: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80085468: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8008546C:
    // 0x8008546C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80085470: bgez        $a2, L_80085480
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80085474: sra         $t4, $a2, 1
        ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80085480;
    }
    // 0x80085474: sra         $t4, $a2, 1
    ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80085478: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x8008547C: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80085480:
    // 0x80085480: jal         0x80089B04
    // 0x80085484: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    func_80089B04(rdram, ctx);
        goto after_5;
    // 0x80085484: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_5:
L_80085488:
    // 0x80085488: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8008548C: nop

    // 0x80085490: lh          $v0, 0x4($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X4);
    // 0x80085494: b           L_800854A4
    // 0x80085498: nop

        goto L_800854A4;
    // 0x80085498: nop

    // 0x8008549C: b           L_800854A4
    // 0x800854A0: nop

        goto L_800854A4;
    // 0x800854A0: nop

L_800854A4:
    // 0x800854A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800854A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800854AC: jr          $ra
    // 0x800854B0: nop

    return;
    // 0x800854B0: nop

;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5C74: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C5C78: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x800C5C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5C80: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C5C84: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800C5C88: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800C5C8C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800C5C90: blez        $t6, L_800C5CA4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C5C94: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_800C5CA4;
    }
    // 0x800C5C94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C5C98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C5C9C: b           L_800C5CB0
    // 0x800C5CA0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_800C5CB0;
    // 0x800C5CA0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_800C5CA4:
    // 0x800C5CA4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800C5CA8: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x800C5CAC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800C5CB0:
    // 0x800C5CB0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C5CB4: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800C5CB8: beq         $at, $zero, L_800C5CF4
    if (ctx->r1 == 0) {
        // 0x800C5CBC: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800C5CF4;
    }
    // 0x800C5CBC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_800C5CC0:
    // 0x800C5CC0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5CC4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800C5CC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C5CCC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800C5CD0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C5CD4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800C5CD8: beq         $t5, $at, L_800C5CF4
    if (ctx->r13 == ctx->r1) {
        // 0x800C5CDC: nop
    
            goto L_800C5CF4;
    }
    // 0x800C5CDC: nop

    // 0x800C5CE0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5CE4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C5CE8: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800C5CEC: bne         $at, $zero, L_800C5CC0
    if (ctx->r1 != 0) {
        // 0x800C5CF0: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_800C5CC0;
    }
    // 0x800C5CF0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_800C5CF4:
    // 0x800C5CF4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5CF8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800C5CFC: bne         $t8, $at, L_800C5D18
    if (ctx->r24 != ctx->r1) {
        // 0x800C5D00: nop
    
            goto L_800C5D18;
    }
    // 0x800C5D00: nop

    // 0x800C5D04: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800C5D08: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800C5D0C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C5D10: b           L_800C5EC8
    // 0x800C5D14: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800C5EC8;
    // 0x800C5D14: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800C5D18:
    // 0x800C5D18: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800C5D1C:
    // 0x800C5D1C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800C5D20: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x800C5D24: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x800C5D28: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C5D2C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C5D30: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x800C5D34: bne         $at, $zero, L_800C5D1C
    if (ctx->r1 != 0) {
        // 0x800C5D38: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800C5D1C;
    }
    // 0x800C5D38: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800C5D3C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5D40: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800C5D44: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C5D48: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800C5D4C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800C5D50: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5D54: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800C5D58: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800C5D5C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C5D60: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800C5D64: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800C5D68: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x800C5D6C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C5D70: beq         $at, $zero, L_800C5E44
    if (ctx->r1 == 0) {
        // 0x800C5D74: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_800C5E44;
    }
    // 0x800C5D74: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800C5D78: beq         $at, $zero, L_800C5E44
    if (ctx->r1 == 0) {
        // 0x800C5D7C: nop
    
            goto L_800C5E44;
    }
    // 0x800C5D7C: nop

L_800C5D80:
    // 0x800C5D80: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5D84: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800C5D88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C5D8C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800C5D90: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800C5D94: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800C5D98: bne         $t7, $at, L_800C5E10
    if (ctx->r15 != ctx->r1) {
        // 0x800C5D9C: nop
    
            goto L_800C5E10;
    }
    // 0x800C5D9C: nop

    // 0x800C5DA0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800C5DA4: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x800C5DA8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800C5DAC: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x800C5DB0: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800C5DB4: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x800C5DB8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800C5DBC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800C5DC0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5DC4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800C5DC8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800C5DCC: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x800C5DD0: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800C5DD4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800C5DD8: jal         0x800C5ED8
    // 0x800C5DDC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    __osClearPage(rdram, ctx);
        goto after_0;
    // 0x800C5DDC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800C5DE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C5DE4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5DE8: beq         $t2, $zero, L_800C5DF8
    if (ctx->r10 == 0) {
        // 0x800C5DEC: nop
    
            goto L_800C5DF8;
    }
    // 0x800C5DEC: nop

    // 0x800C5DF0: b           L_800C5EC8
    // 0x800C5DF4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800C5EC8;
    // 0x800C5DF4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800C5DF8:
    // 0x800C5DF8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5DFC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800C5E00: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800C5E04: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800C5E08: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800C5E0C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_800C5E10:
    // 0x800C5E10: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5E14: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800C5E18: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800C5E1C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800C5E20: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800C5E24: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800C5E28: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C5E2C: beq         $at, $zero, L_800C5E44
    if (ctx->r1 == 0) {
        // 0x800C5E30: nop
    
            goto L_800C5E44;
    }
    // 0x800C5E30: nop

    // 0x800C5E34: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5E38: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800C5E3C: bne         $at, $zero, L_800C5D80
    if (ctx->r1 != 0) {
        // 0x800C5E40: nop
    
            goto L_800C5D80;
    }
    // 0x800C5E40: nop

L_800C5E44:
    // 0x800C5E44: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800C5E48: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800C5E4C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800C5E50: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800C5E54: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5E58: bne         $t1, $at, L_800C5E8C
    if (ctx->r9 != ctx->r1) {
        // 0x800C5E5C: nop
    
            goto L_800C5E8C;
    }
    // 0x800C5E5C: nop

    // 0x800C5E60: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800C5E64: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800C5E68: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x800C5E6C: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C5E70: beq         $at, $zero, L_800C5E8C
    if (ctx->r1 == 0) {
        // 0x800C5E74: nop
    
            goto L_800C5E8C;
    }
    // 0x800C5E74: nop

    // 0x800C5E78: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800C5E7C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800C5E80: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800C5E84: b           L_800C5EC8
    // 0x800C5E88: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800C5EC8;
    // 0x800C5E88: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800C5E8C:
    // 0x800C5E8C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800C5E90: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800C5E94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C5E98: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800C5E9C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800C5EA0: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x800C5EA4: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800C5EA8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800C5EAC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800C5EB0: jal         0x800C5ED8
    // 0x800C5EB4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    __osClearPage(rdram, ctx);
        goto after_1;
    // 0x800C5EB4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800C5EB8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800C5EBC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C5EC0: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800C5EC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800C5EC8:
    // 0x800C5EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5ECC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800C5ED0: jr          $ra
    // 0x800C5ED4: nop

    return;
    // 0x800C5ED4: nop

;}
RECOMP_FUNC void func_80065C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065C60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065C64: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065C68: nop

    // 0x80065C6C: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80065C70: nop

    // 0x80065C74: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065C78: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065C7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065C80: beq         $v0, $zero, L_80065C98
    if (ctx->r2 == 0) {
        // 0x80065C84: nop
    
            goto L_80065C98;
    }
    // 0x80065C84: nop

    // 0x80065C88: jal         0x8005F064
    // 0x80065C8C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065C8C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_0:
    // 0x80065C90: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80065C94: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065C98:
    // 0x80065C98: b           L_80065CA8
    // 0x80065C9C: nop

        goto L_80065CA8;
    // 0x80065C9C: nop

    // 0x80065CA0: b           L_80065CA8
    // 0x80065CA4: nop

        goto L_80065CA8;
    // 0x80065CA4: nop

L_80065CA8:
    // 0x80065CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065CB0: jr          $ra
    // 0x80065CB4: nop

    return;
    // 0x80065CB4: nop

;}
RECOMP_FUNC void func_80063D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D40: jal         0x80061488
    // 0x80063D44: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063D44: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    after_0:
    // 0x80063D48: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063D4C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063D50: b           L_80063D60
    // 0x80063D54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063D60;
    // 0x80063D54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063D58: b           L_80063D60
    // 0x80063D5C: nop

        goto L_80063D60;
    // 0x80063D5C: nop

L_80063D60:
    // 0x80063D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063D68: jr          $ra
    // 0x80063D6C: nop

    return;
    // 0x80063D6C: nop

;}
RECOMP_FUNC void ContPak_GetOpenFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEA10: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEA14: nop

    // 0x800AEA18: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x800AEA1C: beq         $t7, $zero, L_800AEA2C
    if (ctx->r15 == 0) {
        // 0x800AEA20: nop
    
            goto L_800AEA2C;
    }
    // 0x800AEA20: nop

    // 0x800AEA24: jr          $ra
    // 0x800AEA28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEA28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEA2C:
    // 0x800AEA2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEA30: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEA34: nop

    // 0x800AEA38: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x800AEA3C: beq         $t9, $zero, L_800AEA4C
    if (ctx->r25 == 0) {
        // 0x800AEA40: nop
    
            goto L_800AEA4C;
    }
    // 0x800AEA40: nop

    // 0x800AEA44: jr          $ra
    // 0x800AEA48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEA48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEA4C:
    // 0x800AEA4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEA50: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AEA54: nop

    // 0x800AEA58: beq         $t0, $zero, L_800AEA78
    if (ctx->r8 == 0) {
        // 0x800AEA5C: nop
    
            goto L_800AEA78;
    }
    // 0x800AEA5C: nop

    // 0x800AEA60: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEA64: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AEA68: nop

    // 0x800AEA6C: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AEA70: jr          $ra
    // 0x800AEA74: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AEA74: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AEA78:
    // 0x800AEA78: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEA7C: lw          $v0, 0x167C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X167C);
    // 0x800AEA80: jr          $ra
    // 0x800AEA84: nop

    return;
    // 0x800AEA84: nop

    // 0x800AEA88: jr          $ra
    // 0x800AEA8C: nop

    return;
    // 0x800AEA8C: nop

    // 0x800AEA90: jr          $ra
    // 0x800AEA94: nop

    return;
    // 0x800AEA94: nop

;}
RECOMP_FUNC void func_8006C000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C008: jal         0x8005F064
    // 0x8006C00C: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C00C: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_0:
    // 0x8006C010: b           L_8006C020
    // 0x8006C014: nop

        goto L_8006C020;
    // 0x8006C014: nop

    // 0x8006C018: b           L_8006C020
    // 0x8006C01C: nop

        goto L_8006C020;
    // 0x8006C01C: nop

L_8006C020:
    // 0x8006C020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C028: jr          $ra
    // 0x8006C02C: nop

    return;
    // 0x8006C02C: nop

;}
RECOMP_FUNC void func_80069908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006990C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069910: jal         0x80061348
    // 0x80069914: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069914: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x80069918: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006991C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069920: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069924: beq         $v0, $zero, L_80069964
    if (ctx->r2 == 0) {
        // 0x80069928: nop
    
            goto L_80069964;
    }
    // 0x80069928: nop

    // 0x8006992C: jal         0x80061348
    // 0x80069930: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069930: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x80069934: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069938: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006993C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069940: beq         $v0, $zero, L_80069964
    if (ctx->r2 == 0) {
        // 0x80069944: nop
    
            goto L_80069964;
    }
    // 0x80069944: nop

    // 0x80069948: jal         0x80061348
    // 0x8006994C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006994C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x80069950: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069954: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069958: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006995C: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069960: nop
    
            goto L_80069BA8;
    }
    // 0x80069960: nop

L_80069964:
    // 0x80069964: jal         0x80061348
    // 0x80069968: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80069968: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006996C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069970: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069974: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069978: beq         $v0, $zero, L_800699B8
    if (ctx->r2 == 0) {
        // 0x8006997C: nop
    
            goto L_800699B8;
    }
    // 0x8006997C: nop

    // 0x80069980: jal         0x80061348
    // 0x80069984: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x80069984: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x80069988: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006998C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069990: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069994: beq         $v0, $zero, L_800699B8
    if (ctx->r2 == 0) {
        // 0x80069998: nop
    
            goto L_800699B8;
    }
    // 0x80069998: nop

    // 0x8006999C: jal         0x80061348
    // 0x800699A0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x800699A0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x800699A4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x800699A8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x800699AC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800699B0: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x800699B4: nop
    
            goto L_80069BA8;
    }
    // 0x800699B4: nop

L_800699B8:
    // 0x800699B8: jal         0x80061348
    // 0x800699BC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800699BC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x800699C0: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x800699C4: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x800699C8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800699CC: beq         $v0, $zero, L_80069A0C
    if (ctx->r2 == 0) {
        // 0x800699D0: nop
    
            goto L_80069A0C;
    }
    // 0x800699D0: nop

    // 0x800699D4: jal         0x80061348
    // 0x800699D8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x800699D8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x800699DC: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x800699E0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800699E4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800699E8: beq         $v0, $zero, L_80069A0C
    if (ctx->r2 == 0) {
        // 0x800699EC: nop
    
            goto L_80069A0C;
    }
    // 0x800699EC: nop

    // 0x800699F0: jal         0x80061348
    // 0x800699F4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x800699F4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x800699F8: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x800699FC: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069A00: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069A04: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069A08: nop
    
            goto L_80069BA8;
    }
    // 0x80069A08: nop

L_80069A0C:
    // 0x80069A0C: jal         0x80061348
    // 0x80069A10: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x80069A10: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x80069A14: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069A18: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80069A1C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069A20: beq         $v0, $zero, L_80069A60
    if (ctx->r2 == 0) {
        // 0x80069A24: nop
    
            goto L_80069A60;
    }
    // 0x80069A24: nop

    // 0x80069A28: jal         0x80061348
    // 0x80069A2C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x80069A2C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x80069A30: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80069A34: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069A38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069A3C: beq         $v0, $zero, L_80069A60
    if (ctx->r2 == 0) {
        // 0x80069A40: nop
    
            goto L_80069A60;
    }
    // 0x80069A40: nop

    // 0x80069A44: jal         0x80061348
    // 0x80069A48: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x80069A48: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x80069A4C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069A50: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069A54: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069A58: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069A5C: nop
    
            goto L_80069BA8;
    }
    // 0x80069A5C: nop

L_80069A60:
    // 0x80069A60: jal         0x80061348
    // 0x80069A64: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x80069A64: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x80069A68: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069A6C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069A70: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069A74: beq         $v0, $zero, L_80069AB4
    if (ctx->r2 == 0) {
        // 0x80069A78: nop
    
            goto L_80069AB4;
    }
    // 0x80069A78: nop

    // 0x80069A7C: jal         0x80061348
    // 0x80069A80: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x80069A80: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x80069A84: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069A88: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069A8C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80069A90: beq         $v0, $zero, L_80069AB4
    if (ctx->r2 == 0) {
        // 0x80069A94: nop
    
            goto L_80069AB4;
    }
    // 0x80069A94: nop

    // 0x80069A98: jal         0x80061348
    // 0x80069A9C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x80069A9C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x80069AA0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80069AA4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80069AA8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80069AAC: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069AB0: nop
    
            goto L_80069BA8;
    }
    // 0x80069AB0: nop

L_80069AB4:
    // 0x80069AB4: jal         0x80061348
    // 0x80069AB8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x80069AB8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x80069ABC: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x80069AC0: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80069AC4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80069AC8: beq         $v0, $zero, L_80069B08
    if (ctx->r2 == 0) {
        // 0x80069ACC: nop
    
            goto L_80069B08;
    }
    // 0x80069ACC: nop

    // 0x80069AD0: jal         0x80061348
    // 0x80069AD4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x80069AD4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x80069AD8: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80069ADC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80069AE0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80069AE4: beq         $v0, $zero, L_80069B08
    if (ctx->r2 == 0) {
        // 0x80069AE8: nop
    
            goto L_80069B08;
    }
    // 0x80069AE8: nop

    // 0x80069AEC: jal         0x80061348
    // 0x80069AF0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x80069AF0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x80069AF4: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x80069AF8: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80069AFC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80069B00: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069B04: nop
    
            goto L_80069BA8;
    }
    // 0x80069B04: nop

L_80069B08:
    // 0x80069B08: jal         0x80061348
    // 0x80069B0C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x80069B0C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x80069B10: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x80069B14: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80069B18: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80069B1C: beq         $v0, $zero, L_80069B5C
    if (ctx->r2 == 0) {
        // 0x80069B20: nop
    
            goto L_80069B5C;
    }
    // 0x80069B20: nop

    // 0x80069B24: jal         0x80061348
    // 0x80069B28: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x80069B28: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x80069B2C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x80069B30: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80069B34: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80069B38: beq         $v0, $zero, L_80069B5C
    if (ctx->r2 == 0) {
        // 0x80069B3C: nop
    
            goto L_80069B5C;
    }
    // 0x80069B3C: nop

    // 0x80069B40: jal         0x80061348
    // 0x80069B44: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x80069B44: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x80069B48: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80069B4C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80069B50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069B54: bne         $v0, $zero, L_80069BA8
    if (ctx->r2 != 0) {
        // 0x80069B58: nop
    
            goto L_80069BA8;
    }
    // 0x80069B58: nop

L_80069B5C:
    // 0x80069B5C: jal         0x80061348
    // 0x80069B60: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x80069B60: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x80069B64: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80069B68: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069B6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069B70: beq         $v0, $zero, L_80069BA8
    if (ctx->r2 == 0) {
        // 0x80069B74: nop
    
            goto L_80069BA8;
    }
    // 0x80069B74: nop

    // 0x80069B78: jal         0x80061348
    // 0x80069B7C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x80069B7C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x80069B80: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80069B84: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069B88: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069B8C: beq         $v0, $zero, L_80069BA8
    if (ctx->r2 == 0) {
        // 0x80069B90: nop
    
            goto L_80069BA8;
    }
    // 0x80069B90: nop

    // 0x80069B94: jal         0x80061348
    // 0x80069B98: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x80069B98: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x80069B9C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80069BA0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80069BA4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80069BA8:
    // 0x80069BA8: b           L_80069BB8
    // 0x80069BAC: nop

        goto L_80069BB8;
    // 0x80069BAC: nop

    // 0x80069BB0: b           L_80069BB8
    // 0x80069BB4: nop

        goto L_80069BB8;
    // 0x80069BB4: nop

L_80069BB8:
    // 0x80069BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069BC0: jr          $ra
    // 0x80069BC4: nop

    return;
    // 0x80069BC4: nop

;}
RECOMP_FUNC void alEvtqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3B50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D3B54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3B58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D3B5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3B60: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D3B64: jal         0x800C41A0
    // 0x800D3B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D3B6C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800D3B70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800D3B74: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800D3B78: lw          $s0, 0x8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8);
    // 0x800D3B7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D3B80: beql        $s0, $zero, L_800D3BB8
    if (ctx->r16 == 0) {
        // 0x800D3B84: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_800D3BB8;
    }
    goto skip_0;
    // 0x800D3B84: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x800D3B88: jal         0x800C7890
    // 0x800D3B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800D3B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D3B90: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x800D3B94: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800D3B98: jal         0x800D6320
    // 0x800D3B9C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    alCopy(rdram, ctx);
        goto after_2;
    // 0x800D3B9C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x800D3BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3BA4: jal         0x800C78C0
    // 0x800D3BA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800D3BA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800D3BAC: b           L_800D3BBC
    // 0x800D3BB0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
        goto L_800D3BBC;
    // 0x800D3BB0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800D3BB4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_800D3BB8:
    // 0x800D3BB8: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_800D3BBC:
    // 0x800D3BBC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D3BC0: jal         0x800C41A0
    // 0x800D3BC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x800D3BC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800D3BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3BCC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800D3BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3BD4: jr          $ra
    // 0x800D3BD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D3BD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80063DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063DA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063DB0: jal         0x80061488
    // 0x80063DB4: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063DB4: addiu       $a0, $zero, 0x5D8
    ctx->r4 = ADD32(0, 0X5D8);
    after_0:
    // 0x80063DB8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063DBC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063DC0: b           L_80063DD0
    // 0x80063DC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063DD0;
    // 0x80063DC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063DC8: b           L_80063DD0
    // 0x80063DCC: nop

        goto L_80063DD0;
    // 0x80063DCC: nop

L_80063DD0:
    // 0x80063DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063DD8: jr          $ra
    // 0x80063DDC: nop

    return;
    // 0x80063DDC: nop

;}
RECOMP_FUNC void func_80073ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073AD4: jal         0x80061488
    // 0x80073AD8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073AD8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073ADC: slti        $t6, $v0, 0x6
    ctx->r14 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80073AE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80073AE4: b           L_80073AF4
    // 0x80073AE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073AF4;
    // 0x80073AE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073AEC: b           L_80073AF4
    // 0x80073AF0: nop

        goto L_80073AF4;
    // 0x80073AF0: nop

L_80073AF4:
    // 0x80073AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073AFC: jr          $ra
    // 0x80073B00: nop

    return;
    // 0x80073B00: nop

;}
RECOMP_FUNC void func_80032604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032604: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80032608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003260C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032610: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80032614:
    // 0x80032614: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80032618: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003261C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80032620: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80032624: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80032628: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003262C: lw          $t8, 0xDA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XDA8);
    // 0x80032630: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80032634: beq         $t8, $at, L_80032674
    if (ctx->r24 == ctx->r1) {
        // 0x80032638: nop
    
            goto L_80032674;
    }
    // 0x80032638: nop

    // 0x8003263C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80032640: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80032644: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80032648: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8003264C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80032650: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80032654: addiu       $t2, $t2, 0xDA8
    ctx->r10 = ADD32(ctx->r10, 0XDA8);
    // 0x80032658: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8003265C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x80032660: addu        $a1, $t0, $t2
    ctx->r5 = ADD32(ctx->r8, ctx->r10);
    // 0x80032664: jal         0x800BCFCC
    // 0x80032668: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x80032668: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x8003266C: b           L_8003273C
    // 0x80032670: nop

        goto L_8003273C;
    // 0x80032670: nop

L_80032674:
    // 0x80032674: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80032678: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003267C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80032680: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80032684: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80032688: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8003268C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80032690: sw          $t3, 0x60F0($at)
    MEM_W(0X60F0, ctx->r1) = ctx->r11;
    // 0x80032694: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80032698: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8003269C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800326A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800326A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800326A8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800326AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800326B0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800326B4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800326B8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800326BC: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x800326C0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800326C4: sh          $zero, 0x60F8($at)
    MEM_H(0X60F8, ctx->r1) = 0;
    // 0x800326C8: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x800326CC: lhu         $s0, 0x8($t0)
    ctx->r16 = MEM_HU(ctx->r8, 0X8);
    // 0x800326D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800326D4: sh          $s0, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r16;
    // 0x800326D8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800326DC: nop

    // 0x800326E0: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800326E4: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800326E8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800326EC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800326F0: sh          $s0, 0x60F6($at)
    MEM_H(0X60F6, ctx->r1) = ctx->r16;
    // 0x800326F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800326F8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800326FC: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80032700: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80032704: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80032708: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003270C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80032710: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80032714: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80032718: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8003271C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80032720: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80032724: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80032728: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003272C: swc1        $f4, 0x6104($at)
    MEM_W(0X6104, ctx->r1) = ctx->f4.u32l;
    // 0x80032730: lwc1        $f6, 0x14($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80032734: nop

    // 0x80032738: swc1        $f6, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f6.u32l;
L_8003273C:
    // 0x8003273C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80032740: nop

    // 0x80032744: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80032748: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8003274C: bne         $at, $zero, L_80032614
    if (ctx->r1 != 0) {
        // 0x80032750: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_80032614;
    }
    // 0x80032750: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80032754: b           L_8003275C
    // 0x80032758: nop

        goto L_8003275C;
    // 0x80032758: nop

L_8003275C:
    // 0x8003275C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032764: jr          $ra
    // 0x80032768: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80032768: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800AC920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC920: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800AC924: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800AC928: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800AC92C: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800AC930: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800AC934: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC938: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AC93C: swc1        $f4, -0x7390($at)
    MEM_W(-0X7390, ctx->r1) = ctx->f4.u32l;
    // 0x800AC940: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800AC944: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800AC948: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC94C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AC950: swc1        $f6, -0x738C($at)
    MEM_W(-0X738C, ctx->r1) = ctx->f6.u32l;
    // 0x800AC954: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800AC958: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800AC95C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC960: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800AC964: swc1        $f8, -0x7388($at)
    MEM_W(-0X7388, ctx->r1) = ctx->f8.u32l;
    // 0x800AC968: b           L_800AC970
    // 0x800AC96C: nop

        goto L_800AC970;
    // 0x800AC96C: nop

L_800AC970:
    // 0x800AC970: jr          $ra
    // 0x800AC974: nop

    return;
    // 0x800AC974: nop

;}
RECOMP_FUNC void func_80071080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071088: jal         0x80061348
    // 0x8007108C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007108C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_0:
    // 0x80071090: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071094: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071098: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007109C: beq         $v0, $zero, L_800710F0
    if (ctx->r2 == 0) {
        // 0x800710A0: nop
    
            goto L_800710F0;
    }
    // 0x800710A0: nop

    // 0x800710A4: jal         0x80061348
    // 0x800710A8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800710A8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x800710AC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800710B0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800710B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800710B8: beq         $v0, $zero, L_800710F0
    if (ctx->r2 == 0) {
        // 0x800710BC: nop
    
            goto L_800710F0;
    }
    // 0x800710BC: nop

    // 0x800710C0: jal         0x80061348
    // 0x800710C4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800710C4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_2:
    // 0x800710C8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800710CC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800710D0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800710D4: beq         $v0, $zero, L_800710F0
    if (ctx->r2 == 0) {
        // 0x800710D8: nop
    
            goto L_800710F0;
    }
    // 0x800710D8: nop

    // 0x800710DC: jal         0x80061348
    // 0x800710E0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800710E0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x800710E4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800710E8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800710EC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800710F0:
    // 0x800710F0: b           L_80071100
    // 0x800710F4: nop

        goto L_80071100;
    // 0x800710F4: nop

    // 0x800710F8: b           L_80071100
    // 0x800710FC: nop

        goto L_80071100;
    // 0x800710FC: nop

L_80071100:
    // 0x80071100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071108: jr          $ra
    // 0x8007110C: nop

    return;
    // 0x8007110C: nop

;}
RECOMP_FUNC void alEvtqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3BDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D3BE0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D3BE4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D3BE8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D3BEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D3BF0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D3BF4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D3BF8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800D3BFC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800D3C00: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800D3C04: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800D3C08: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800D3C0C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D3C10: blez        $a2, L_800D3C34
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800D3C14: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800D3C34;
    }
    // 0x800D3C14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D3C18: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_800D3C1C:
    // 0x800D3C1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D3C20: jal         0x800C78C0
    // 0x800D3C24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_0;
    // 0x800D3C24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800D3C28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D3C2C: bne         $s0, $s3, L_800D3C1C
    if (ctx->r16 != ctx->r19) {
        // 0x800D3C30: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_800D3C1C;
    }
    // 0x800D3C30: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_800D3C34:
    // 0x800D3C34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D3C38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D3C3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D3C40: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3C44: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D3C48: jr          $ra
    // 0x800D3C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D3C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006E71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E71C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E724: jal         0x80061348
    // 0x8006E728: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E728: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E72C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E730: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E734: beq         $v0, $zero, L_8006E74C
    if (ctx->r2 == 0) {
        // 0x8006E738: nop
    
            goto L_8006E74C;
    }
    // 0x8006E738: nop

    // 0x8006E73C: jal         0x80061348
    // 0x8006E740: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E740: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    after_1:
    // 0x8006E744: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E748: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E74C:
    // 0x8006E74C: b           L_8006E75C
    // 0x8006E750: nop

        goto L_8006E75C;
    // 0x8006E750: nop

    // 0x8006E754: b           L_8006E75C
    // 0x8006E758: nop

        goto L_8006E75C;
    // 0x8006E758: nop

L_8006E75C:
    // 0x8006E75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E764: jr          $ra
    // 0x8006E768: nop

    return;
    // 0x8006E768: nop

;}
RECOMP_FUNC void func_8001ECDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ECDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ECE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ECE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001ECE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001ECEC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ECF0: nop

    // 0x8001ECF4: bltz        $t6, L_8001ED68
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001ECF8: nop
    
            goto L_8001ED68;
    }
    // 0x8001ECF8: nop

    // 0x8001ECFC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001ED00: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001ED04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001ED08: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001ED0C: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001ED10: nop

    // 0x8001ED14: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001ED18: bne         $t0, $zero, L_8001ED38
    if (ctx->r8 != 0) {
        // 0x8001ED1C: nop
    
            goto L_8001ED38;
    }
    // 0x8001ED1C: nop

    // 0x8001ED20: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001ED24: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001ED28: nop

    // 0x8001ED2C: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001ED30: beq         $t2, $zero, L_8001ED68
    if (ctx->r10 == 0) {
        // 0x8001ED34: nop
    
            goto L_8001ED68;
    }
    // 0x8001ED34: nop

L_8001ED38:
    // 0x8001ED38: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001ED3C: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x8001ED40: nop

    // 0x8001ED44: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8001ED48: beq         $t4, $zero, L_8001ED60
    if (ctx->r12 == 0) {
        // 0x8001ED4C: nop
    
            goto L_8001ED60;
    }
    // 0x8001ED4C: nop

    // 0x8001ED50: jal         0x800BDA58
    // 0x8001ED54: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800BDA58(rdram, ctx);
        goto after_0;
    // 0x8001ED54: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x8001ED58: b           L_8001ED68
    // 0x8001ED5C: nop

        goto L_8001ED68;
    // 0x8001ED5C: nop

L_8001ED60:
    // 0x8001ED60: jal         0x800BDA58
    // 0x8001ED64: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800BDA58(rdram, ctx);
        goto after_1;
    // 0x8001ED64: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
L_8001ED68:
    // 0x8001ED68: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001ED6C: lw          $t5, 0x168C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X168C);
    // 0x8001ED70: nop

    // 0x8001ED74: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x8001ED78: beq         $t6, $zero, L_8001ED94
    if (ctx->r14 == 0) {
        // 0x8001ED7C: nop
    
            goto L_8001ED94;
    }
    // 0x8001ED7C: nop

    // 0x8001ED80: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ED84: jal         0x8008ECE4
    // 0x8001ED88: addiu       $a0, $a0, -0x24DC
    ctx->r4 = ADD32(ctx->r4, -0X24DC);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001ED88: addiu       $a0, $a0, -0x24DC
    ctx->r4 = ADD32(ctx->r4, -0X24DC);
    after_2:
    // 0x8001ED8C: b           L_8001EDA0
    // 0x8001ED90: nop

        goto L_8001EDA0;
    // 0x8001ED90: nop

L_8001ED94:
    // 0x8001ED94: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ED98: jal         0x8008ECE4
    // 0x8001ED9C: addiu       $a0, $a0, -0x24D4
    ctx->r4 = ADD32(ctx->r4, -0X24D4);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001ED9C: addiu       $a0, $a0, -0x24D4
    ctx->r4 = ADD32(ctx->r4, -0X24D4);
    after_3:
L_8001EDA0:
    // 0x8001EDA0: b           L_8001EDB0
    // 0x8001EDA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EDB0;
    // 0x8001EDA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EDA8: b           L_8001EDB0
    // 0x8001EDAC: nop

        goto L_8001EDB0;
    // 0x8001EDAC: nop

L_8001EDB0:
    // 0x8001EDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EDB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EDB8: jr          $ra
    // 0x8001EDBC: nop

    return;
    // 0x8001EDBC: nop

;}
RECOMP_FUNC void func_8006C660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C668: jal         0x8005F064
    // 0x8006C66C: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C66C: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_0:
    // 0x8006C670: b           L_8006C680
    // 0x8006C674: nop

        goto L_8006C680;
    // 0x8006C674: nop

    // 0x8006C678: b           L_8006C680
    // 0x8006C67C: nop

        goto L_8006C680;
    // 0x8006C67C: nop

L_8006C680:
    // 0x8006C680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C688: jr          $ra
    // 0x8006C68C: nop

    return;
    // 0x8006C68C: nop

;}
RECOMP_FUNC void func_80066CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066CF4: jal         0x80061348
    // 0x80066CF8: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066CF8: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    after_0:
    // 0x80066CFC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066D00: b           L_80066D10
    // 0x80066D04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066D10;
    // 0x80066D04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066D08: b           L_80066D10
    // 0x80066D0C: nop

        goto L_80066D10;
    // 0x80066D0C: nop

L_80066D10:
    // 0x80066D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066D14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066D18: jr          $ra
    // 0x80066D1C: nop

    return;
    // 0x80066D1C: nop

;}
RECOMP_FUNC void func_8006F760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F768: jal         0x80061488
    // 0x8006F76C: addiu       $a0, $zero, 0x3C8
    ctx->r4 = ADD32(0, 0X3C8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006F76C: addiu       $a0, $zero, 0x3C8
    ctx->r4 = ADD32(0, 0X3C8);
    after_0:
    // 0x8006F770: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006F774: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006F778: b           L_8006F788
    // 0x8006F77C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F788;
    // 0x8006F77C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F780: b           L_8006F788
    // 0x8006F784: nop

        goto L_8006F788;
    // 0x8006F784: nop

L_8006F788:
    // 0x8006F788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F78C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F790: jr          $ra
    // 0x8006F794: nop

    return;
    // 0x8006F794: nop

;}
RECOMP_FUNC void func_800B6A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6A00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B6A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B6A08: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B6A0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B6A10:
    // 0x800B6A10: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B6A14: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B6A18: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B6A1C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B6A20: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B6A24: sh          $t7, 0x24($t0)
    MEM_H(0X24, ctx->r8) = ctx->r15;
    // 0x800B6A28: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B6A2C: nop

    // 0x800B6A30: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B6A34: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B6A38: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B6A3C: nop

    // 0x800B6A40: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B6A44: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x800B6A48: bne         $at, $zero, L_800B6A10
    if (ctx->r1 != 0) {
        // 0x800B6A4C: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B6A10;
    }
    // 0x800B6A4C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B6A50: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x800B6A54: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x800B6A58: jal         0x8000D688
    // 0x800B6A5C: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B6A5C: nop

    after_0:
    // 0x800B6A60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B6A64: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800B6A68: nop

    // 0x800B6A6C: beq         $t6, $zero, L_800B6AB4
    if (ctx->r14 == 0) {
        // 0x800B6A70: nop
    
            goto L_800B6AB4;
    }
    // 0x800B6A70: nop

    // 0x800B6A74: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B6A78: nop

    // 0x800B6A7C: lw          $t7, 0x1AC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X1AC);
    // 0x800B6A80: nop

    // 0x800B6A84: slti        $at, $t7, 0x4000
    ctx->r1 = SIGNED(ctx->r15) < 0X4000 ? 1 : 0;
    // 0x800B6A88: bne         $at, $zero, L_800B6AAC
    if (ctx->r1 != 0) {
        // 0x800B6A8C: nop
    
            goto L_800B6AAC;
    }
    // 0x800B6A8C: nop

    // 0x800B6A90: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800B6A94: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B6A98: beq         $at, $zero, L_800B6AAC
    if (ctx->r1 == 0) {
        // 0x800B6A9C: nop
    
            goto L_800B6AAC;
    }
    // 0x800B6A9C: nop

    // 0x800B6AA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B6AA4: jal         0x80015B6C
    // 0x800B6AA8: nop

    func_80015B6C(rdram, ctx);
        goto after_1;
    // 0x800B6AA8: nop

    after_1:
L_800B6AAC:
    // 0x800B6AAC: b           L_800B6B08
    // 0x800B6AB0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800B6B08;
    // 0x800B6AB0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800B6AB4:
    // 0x800B6AB4: addiu       $t9, $sp, 0x24
    ctx->r25 = ADD32(ctx->r29, 0X24);
    // 0x800B6AB8: lhu         $a0, 0x2($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X2);
    // 0x800B6ABC: jal         0x8000D5A8
    // 0x800B6AC0: nop

    func_8000D5A8(rdram, ctx);
        goto after_2;
    // 0x800B6AC0: nop

    after_2:
    // 0x800B6AC4: beq         $v0, $zero, L_800B6AD4
    if (ctx->r2 == 0) {
        // 0x800B6AC8: nop
    
            goto L_800B6AD4;
    }
    // 0x800B6AC8: nop

    // 0x800B6ACC: b           L_800B6B08
    // 0x800B6AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B6B08;
    // 0x800B6AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B6AD4:
    // 0x800B6AD4: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800B6AD8: lhu         $a0, 0x2($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X2);
    // 0x800B6ADC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800B6AE0: jal         0x8000D934
    // 0x800B6AE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8000D934(rdram, ctx);
        goto after_3;
    // 0x800B6AE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x800B6AE8: bgez        $v0, L_800B6AF8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B6AEC: nop
    
            goto L_800B6AF8;
    }
    // 0x800B6AEC: nop

    // 0x800B6AF0: b           L_800B6B08
    // 0x800B6AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B6B08;
    // 0x800B6AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B6AF8:
    // 0x800B6AF8: b           L_800B6B08
    // 0x800B6AFC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800B6B08;
    // 0x800B6AFC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800B6B00: b           L_800B6B08
    // 0x800B6B04: nop

        goto L_800B6B08;
    // 0x800B6B04: nop

L_800B6B08:
    // 0x800B6B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6B0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B6B10: jr          $ra
    // 0x800B6B14: nop

    return;
    // 0x800B6B14: nop

;}
RECOMP_FUNC void func_80071DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071DAC: jal         0x80061348
    // 0x80071DB0: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071DB0: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071DB4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071DB8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071DBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071DC0: beq         $v0, $zero, L_80071DF8
    if (ctx->r2 == 0) {
        // 0x80071DC4: nop
    
            goto L_80071DF8;
    }
    // 0x80071DC4: nop

    // 0x80071DC8: jal         0x80061348
    // 0x80071DCC: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071DCC: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071DD0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071DD4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071DD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071DDC: beq         $v0, $zero, L_80071DF8
    if (ctx->r2 == 0) {
        // 0x80071DE0: nop
    
            goto L_80071DF8;
    }
    // 0x80071DE0: nop

    // 0x80071DE4: jal         0x80061348
    // 0x80071DE8: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071DE8: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071DEC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071DF0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071DF4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071DF8:
    // 0x80071DF8: b           L_80071E08
    // 0x80071DFC: nop

        goto L_80071E08;
    // 0x80071DFC: nop

    // 0x80071E00: b           L_80071E08
    // 0x80071E04: nop

        goto L_80071E08;
    // 0x80071E04: nop

L_80071E08:
    // 0x80071E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071E10: jr          $ra
    // 0x80071E14: nop

    return;
    // 0x80071E14: nop

;}
RECOMP_FUNC void func_800B7C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7C4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B7C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7C54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B7C58: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B7C5C:
    // 0x800B7C5C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B7C60: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7C64: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7C68: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7C6C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7C70: sh          $t7, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r15;
    // 0x800B7C74: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B7C78: nop

    // 0x800B7C7C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7C80: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B7C84: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7C88: nop

    // 0x800B7C8C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7C90: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B7C94: bne         $at, $zero, L_800B7C5C
    if (ctx->r1 != 0) {
        // 0x800B7C98: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B7C5C;
    }
    // 0x800B7C98: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B7C9C: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800B7CA0: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7CA4: jal         0x8000D688
    // 0x800B7CA8: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x800B7CA8: nop

    after_0:
    // 0x800B7CAC: beq         $v0, $zero, L_800B7CBC
    if (ctx->r2 == 0) {
        // 0x800B7CB0: nop
    
            goto L_800B7CBC;
    }
    // 0x800B7CB0: nop

    // 0x800B7CB4: b           L_800B7D10
    // 0x800B7CB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7D10;
    // 0x800B7CB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800B7CBC:
    // 0x800B7CBC: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x800B7CC0: lhu         $a0, 0x2($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X2);
    // 0x800B7CC4: jal         0x8000D5A8
    // 0x800B7CC8: nop

    func_8000D5A8(rdram, ctx);
        goto after_1;
    // 0x800B7CC8: nop

    after_1:
    // 0x800B7CCC: beq         $v0, $zero, L_800B7CDC
    if (ctx->r2 == 0) {
        // 0x800B7CD0: nop
    
            goto L_800B7CDC;
    }
    // 0x800B7CD0: nop

    // 0x800B7CD4: b           L_800B7D10
    // 0x800B7CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7D10;
    // 0x800B7CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7CDC:
    // 0x800B7CDC: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x800B7CE0: lhu         $a0, 0x2($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7CE4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B7CE8: jal         0x8000D934
    // 0x800B7CEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8000D934(rdram, ctx);
        goto after_2;
    // 0x800B7CEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x800B7CF0: bgez        $v0, L_800B7D00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B7CF4: nop
    
            goto L_800B7D00;
    }
    // 0x800B7CF4: nop

    // 0x800B7CF8: b           L_800B7D10
    // 0x800B7CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7D10;
    // 0x800B7CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7D00:
    // 0x800B7D00: b           L_800B7D10
    // 0x800B7D04: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7D10;
    // 0x800B7D04: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B7D08: b           L_800B7D10
    // 0x800B7D0C: nop

        goto L_800B7D10;
    // 0x800B7D0C: nop

L_800B7D10:
    // 0x800B7D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7D14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B7D18: jr          $ra
    // 0x800B7D1C: nop

    return;
    // 0x800B7D1C: nop

;}
RECOMP_FUNC void func_80062D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062D54: jal         0x80061488
    // 0x80062D58: addiu       $a0, $zero, 0x697
    ctx->r4 = ADD32(0, 0X697);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062D58: addiu       $a0, $zero, 0x697
    ctx->r4 = ADD32(0, 0X697);
    after_0:
    // 0x80062D5C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062D60: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062D64: b           L_80062D74
    // 0x80062D68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062D74;
    // 0x80062D68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062D6C: b           L_80062D74
    // 0x80062D70: nop

        goto L_80062D74;
    // 0x80062D70: nop

L_80062D74:
    // 0x80062D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062D7C: jr          $ra
    // 0x80062D80: nop

    return;
    // 0x80062D80: nop

;}
RECOMP_FUNC void func_80065C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065C2C: jal         0x80061488
    // 0x80065C30: addiu       $a0, $zero, 0x6CF
    ctx->r4 = ADD32(0, 0X6CF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065C30: addiu       $a0, $zero, 0x6CF
    ctx->r4 = ADD32(0, 0X6CF);
    after_0:
    // 0x80065C34: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065C38: b           L_80065C48
    // 0x80065C3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065C48;
    // 0x80065C3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065C40: b           L_80065C48
    // 0x80065C44: nop

        goto L_80065C48;
    // 0x80065C44: nop

L_80065C48:
    // 0x80065C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065C50: jr          $ra
    // 0x80065C54: nop

    return;
    // 0x80065C54: nop

;}
RECOMP_FUNC void func_800870BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800870C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800870C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800870C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800870CC: jal         0x8008B4EC
    // 0x800870D0: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800870D0: nop

    after_0:
    // 0x800870D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800870D8: jal         0x8008B600
    // 0x800870DC: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x800870DC: nop

    after_1:
    // 0x800870E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800870E4: jal         0x8008BA24
    // 0x800870E8: nop

    func_8008BA24(rdram, ctx);
        goto after_2;
    // 0x800870E8: nop

    after_2:
    // 0x800870EC: b           L_800870F4
    // 0x800870F0: nop

        goto L_800870F4;
    // 0x800870F0: nop

L_800870F4:
    // 0x800870F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800870F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800870FC: jr          $ra
    // 0x80087100: nop

    return;
    // 0x80087100: nop

;}
RECOMP_FUNC void alSeqFileNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C84E8: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800C84EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C84F0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C84F4: blez        $t6, L_800C8520
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C84F8: nop
    
            goto L_800C8520;
    }
    // 0x800C84F8: nop

    // 0x800C84FC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_800C8500:
    // 0x800C8500: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C8504: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C8508: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C850C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800C8510: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800C8514: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C8518: bnel        $at, $zero, L_800C8500
    if (ctx->r1 != 0) {
        // 0x800C851C: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_800C8500;
    }
    goto skip_0;
    // 0x800C851C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_800C8520:
    // 0x800C8520: jr          $ra
    // 0x800C8524: nop

    return;
    // 0x800C8524: nop

;}
RECOMP_FUNC void func_8006AA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AA18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006AA1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006AA20: jal         0x80061348
    // 0x8006AA24: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006AA24: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006AA28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AA2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AA30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AA34: beq         $v0, $zero, L_8006AA74
    if (ctx->r2 == 0) {
        // 0x8006AA38: nop
    
            goto L_8006AA74;
    }
    // 0x8006AA38: nop

    // 0x8006AA3C: jal         0x80061348
    // 0x8006AA40: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006AA40: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006AA44: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AA48: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AA4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AA50: beq         $v0, $zero, L_8006AA74
    if (ctx->r2 == 0) {
        // 0x8006AA54: nop
    
            goto L_8006AA74;
    }
    // 0x8006AA54: nop

    // 0x8006AA58: jal         0x80061348
    // 0x8006AA5C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006AA5C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006AA60: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AA64: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AA68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AA6C: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AA70: nop
    
            goto L_8006ACB8;
    }
    // 0x8006AA70: nop

L_8006AA74:
    // 0x8006AA74: jal         0x80061348
    // 0x8006AA78: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006AA78: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006AA7C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AA80: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AA84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006AA88: beq         $v0, $zero, L_8006AAC8
    if (ctx->r2 == 0) {
        // 0x8006AA8C: nop
    
            goto L_8006AAC8;
    }
    // 0x8006AA8C: nop

    // 0x8006AA90: jal         0x80061348
    // 0x8006AA94: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006AA94: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006AA98: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006AA9C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006AAA0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006AAA4: beq         $v0, $zero, L_8006AAC8
    if (ctx->r2 == 0) {
        // 0x8006AAA8: nop
    
            goto L_8006AAC8;
    }
    // 0x8006AAA8: nop

    // 0x8006AAAC: jal         0x80061348
    // 0x8006AAB0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006AAB0: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006AAB4: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006AAB8: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006AABC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006AAC0: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AAC4: nop
    
            goto L_8006ACB8;
    }
    // 0x8006AAC4: nop

L_8006AAC8:
    // 0x8006AAC8: jal         0x80061348
    // 0x8006AACC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006AACC: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006AAD0: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006AAD4: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006AAD8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006AADC: beq         $v0, $zero, L_8006AB1C
    if (ctx->r2 == 0) {
        // 0x8006AAE0: nop
    
            goto L_8006AB1C;
    }
    // 0x8006AAE0: nop

    // 0x8006AAE4: jal         0x80061348
    // 0x8006AAE8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006AAE8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006AAEC: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006AAF0: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006AAF4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006AAF8: beq         $v0, $zero, L_8006AB1C
    if (ctx->r2 == 0) {
        // 0x8006AAFC: nop
    
            goto L_8006AB1C;
    }
    // 0x8006AAFC: nop

    // 0x8006AB00: jal         0x80061348
    // 0x8006AB04: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006AB04: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006AB08: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006AB0C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006AB10: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006AB14: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AB18: nop
    
            goto L_8006ACB8;
    }
    // 0x8006AB18: nop

L_8006AB1C:
    // 0x8006AB1C: jal         0x80061348
    // 0x8006AB20: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006AB20: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006AB24: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006AB28: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006AB2C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006AB30: beq         $v0, $zero, L_8006AB70
    if (ctx->r2 == 0) {
        // 0x8006AB34: nop
    
            goto L_8006AB70;
    }
    // 0x8006AB34: nop

    // 0x8006AB38: jal         0x80061348
    // 0x8006AB3C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006AB3C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006AB40: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AB44: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AB48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AB4C: beq         $v0, $zero, L_8006AB70
    if (ctx->r2 == 0) {
        // 0x8006AB50: nop
    
            goto L_8006AB70;
    }
    // 0x8006AB50: nop

    // 0x8006AB54: jal         0x80061348
    // 0x8006AB58: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006AB58: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006AB5C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AB60: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AB64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AB68: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AB6C: nop
    
            goto L_8006ACB8;
    }
    // 0x8006AB6C: nop

L_8006AB70:
    // 0x8006AB70: jal         0x80061348
    // 0x8006AB74: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006AB74: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006AB78: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AB7C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AB80: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AB84: beq         $v0, $zero, L_8006ABC4
    if (ctx->r2 == 0) {
        // 0x8006AB88: nop
    
            goto L_8006ABC4;
    }
    // 0x8006AB88: nop

    // 0x8006AB8C: jal         0x80061348
    // 0x8006AB90: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006AB90: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006AB94: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006AB98: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006AB9C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006ABA0: beq         $v0, $zero, L_8006ABC4
    if (ctx->r2 == 0) {
        // 0x8006ABA4: nop
    
            goto L_8006ABC4;
    }
    // 0x8006ABA4: nop

    // 0x8006ABA8: jal         0x80061348
    // 0x8006ABAC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006ABAC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006ABB0: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006ABB4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006ABB8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006ABBC: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006ABC0: nop
    
            goto L_8006ACB8;
    }
    // 0x8006ABC0: nop

L_8006ABC4:
    // 0x8006ABC4: jal         0x80061348
    // 0x8006ABC8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006ABC8: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006ABCC: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006ABD0: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006ABD4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006ABD8: beq         $v0, $zero, L_8006AC18
    if (ctx->r2 == 0) {
        // 0x8006ABDC: nop
    
            goto L_8006AC18;
    }
    // 0x8006ABDC: nop

    // 0x8006ABE0: jal         0x80061348
    // 0x8006ABE4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006ABE4: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006ABE8: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006ABEC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006ABF0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006ABF4: beq         $v0, $zero, L_8006AC18
    if (ctx->r2 == 0) {
        // 0x8006ABF8: nop
    
            goto L_8006AC18;
    }
    // 0x8006ABF8: nop

    // 0x8006ABFC: jal         0x80061348
    // 0x8006AC00: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006AC00: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006AC04: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006AC08: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006AC0C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006AC10: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AC14: nop
    
            goto L_8006ACB8;
    }
    // 0x8006AC14: nop

L_8006AC18:
    // 0x8006AC18: jal         0x80061348
    // 0x8006AC1C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006AC1C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006AC20: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006AC24: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006AC28: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006AC2C: beq         $v0, $zero, L_8006AC6C
    if (ctx->r2 == 0) {
        // 0x8006AC30: nop
    
            goto L_8006AC6C;
    }
    // 0x8006AC30: nop

    // 0x8006AC34: jal         0x80061348
    // 0x8006AC38: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006AC38: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006AC3C: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006AC40: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006AC44: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006AC48: beq         $v0, $zero, L_8006AC6C
    if (ctx->r2 == 0) {
        // 0x8006AC4C: nop
    
            goto L_8006AC6C;
    }
    // 0x8006AC4C: nop

    // 0x8006AC50: jal         0x80061348
    // 0x8006AC54: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006AC54: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006AC58: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AC5C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AC60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AC64: bne         $v0, $zero, L_8006ACB8
    if (ctx->r2 != 0) {
        // 0x8006AC68: nop
    
            goto L_8006ACB8;
    }
    // 0x8006AC68: nop

L_8006AC6C:
    // 0x8006AC6C: jal         0x80061348
    // 0x8006AC70: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006AC70: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006AC74: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AC78: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AC7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AC80: beq         $v0, $zero, L_8006ACB8
    if (ctx->r2 == 0) {
        // 0x8006AC84: nop
    
            goto L_8006ACB8;
    }
    // 0x8006AC84: nop

    // 0x8006AC88: jal         0x80061348
    // 0x8006AC8C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006AC8C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006AC90: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AC94: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AC98: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AC9C: beq         $v0, $zero, L_8006ACB8
    if (ctx->r2 == 0) {
        // 0x8006ACA0: nop
    
            goto L_8006ACB8;
    }
    // 0x8006ACA0: nop

    // 0x8006ACA4: jal         0x80061348
    // 0x8006ACA8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006ACA8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006ACAC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006ACB0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006ACB4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006ACB8:
    // 0x8006ACB8: b           L_8006ACC8
    // 0x8006ACBC: nop

        goto L_8006ACC8;
    // 0x8006ACBC: nop

    // 0x8006ACC0: b           L_8006ACC8
    // 0x8006ACC4: nop

        goto L_8006ACC8;
    // 0x8006ACC4: nop

L_8006ACC8:
    // 0x8006ACC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ACCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ACD0: jr          $ra
    // 0x8006ACD4: nop

    return;
    // 0x8006ACD4: nop

;}
RECOMP_FUNC void Main_GfxClearScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE328: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE32C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BE330: nop

    // 0x800BE334: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800BE338: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BE33C: nop

    // 0x800BE340: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800BE344: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800BE348: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800BE34C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800BE350: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800BE354: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x800BE358: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800BE35C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800BE360: lui         $t1, 0x30
    ctx->r9 = S32(0X30 << 16);
    // 0x800BE364: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800BE368: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800BE36C: nop

    // 0x800BE370: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800BE374: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800BE378: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800BE37C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE380: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x800BE384: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x800BE388: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800BE38C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE390: lui         $t7, 0xF0A
    ctx->r15 = S32(0XF0A << 16);
    // 0x800BE394: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x800BE398: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BE39C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BE3A0: nop

    // 0x800BE3A4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800BE3A8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800BE3AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800BE3B0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800BE3B4: lui         $t1, 0xFF10
    ctx->r9 = S32(0XFF10 << 16);
    // 0x800BE3B8: ori         $t1, $t1, 0x13F
    ctx->r9 = ctx->r9 | 0X13F;
    // 0x800BE3BC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800BE3C0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800BE3C4: lw          $t3, 0x7200($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7200);
    // 0x800BE3C8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800BE3CC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800BE3D0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800BE3D4: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800BE3D8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800BE3DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BE3E0: nop

    // 0x800BE3E4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800BE3E8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800BE3EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800BE3F0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800BE3F4: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x800BE3F8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800BE3FC: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800BE400: lui         $t0, 0xFFFC
    ctx->r8 = S32(0XFFFC << 16);
    // 0x800BE404: ori         $t0, $t0, 0xFFFC
    ctx->r8 = ctx->r8 | 0XFFFC;
    // 0x800BE408: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800BE40C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BE410: nop

    // 0x800BE414: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BE418: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BE41C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800BE420: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800BE424: lui         $t4, 0xF64F
    ctx->r12 = S32(0XF64F << 16);
    // 0x800BE428: ori         $t4, $t4, 0xC3BC
    ctx->r12 = ctx->r12 | 0XC3BC;
    // 0x800BE42C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800BE430: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800BE434: nop

    // 0x800BE438: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800BE43C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800BE440: nop

    // 0x800BE444: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800BE448: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800BE44C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800BE450: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800BE454: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800BE458: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800BE45C: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800BE460: nop

    // 0x800BE464: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800BE468: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800BE46C: nop

    // 0x800BE470: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BE474: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BE478: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800BE47C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800BE480: lui         $t4, 0xFE00
    ctx->r12 = S32(0XFE00 << 16);
    // 0x800BE484: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800BE488: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800BE48C: lw          $t6, 0x7200($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7200);
    // 0x800BE490: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800BE494: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800BE498: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800BE49C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800BE4A0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BE4A4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BE4A8: nop

    // 0x800BE4AC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800BE4B0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800BE4B4: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800BE4B8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BE4BC: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x800BE4C0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800BE4C4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800BE4C8: nop

    // 0x800BE4CC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800BE4D0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800BE4D4: nop

    // 0x800BE4D8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800BE4DC: b           L_800BE4E4
    // 0x800BE4E0: nop

        goto L_800BE4E4;
    // 0x800BE4E0: nop

L_800BE4E4:
    // 0x800BE4E4: jr          $ra
    // 0x800BE4E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800BE4E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A7160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A7164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7168: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A716C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A7170: nop

    // 0x800A7174: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800A7178: bne         $at, $zero, L_800A7188
    if (ctx->r1 != 0) {
        // 0x800A717C: nop
    
            goto L_800A7188;
    }
    // 0x800A717C: nop

    // 0x800A7180: b           L_800A7220
    // 0x800A7184: nop

        goto L_800A7220;
    // 0x800A7184: nop

L_800A7188:
    // 0x800A7188: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800A718C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A7190: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A7194: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A7198: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A719C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A71A0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800A71A4: addiu       $t9, $t9, 0x7340
    ctx->r25 = ADD32(ctx->r25, 0X7340);
    // 0x800A71A8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A71AC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A71B0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A71B4: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A71B8: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x800A71BC: nop

    // 0x800A71C0: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A71C4: bne         $t3, $zero, L_800A71D4
    if (ctx->r11 != 0) {
        // 0x800A71C8: nop
    
            goto L_800A71D4;
    }
    // 0x800A71C8: nop

    // 0x800A71CC: b           L_800A7220
    // 0x800A71D0: nop

        goto L_800A7220;
    // 0x800A71D0: nop

L_800A71D4:
    // 0x800A71D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800A71D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A71DC: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800A71E0: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800A71E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A71E8: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800A71EC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A71F0: lwc1        $f8, 0xD0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x800A71F4: lwc1        $f10, 0xE4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XE4);
    // 0x800A71F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A71FC: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A7200: lwc1        $f4, 0xD4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XD4);
    // 0x800A7204: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A7208: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A720C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800A7210: jal         0x800C2304
    // 0x800A7214: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_0;
    // 0x800A7214: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x800A7218: b           L_800A7220
    // 0x800A721C: nop

        goto L_800A7220;
    // 0x800A721C: nop

L_800A7220:
    // 0x800A7220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7224: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7228: jr          $ra
    // 0x800A722C: nop

    return;
    // 0x800A722C: nop

;}
RECOMP_FUNC void func_800A39C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A39C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A39C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A39CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A39D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A39D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800A39D8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800A39DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A39E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800A39E4: lhu         $t7, 0x24FC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X24FC);
    // 0x800A39E8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800A39EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A39F0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800A39F4: lw          $t0, 0x12C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X12C);
    // 0x800A39F8: nop

    // 0x800A39FC: bne         $t0, $zero, L_800A3A34
    if (ctx->r8 != 0) {
        // 0x800A3A00: nop
    
            goto L_800A3A34;
    }
    // 0x800A3A00: nop

    // 0x800A3A04: jal         0x800BC6EC
    // 0x800A3A08: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800A3A08: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    after_0:
    // 0x800A3A0C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800A3A10: lhu         $t2, 0x24FC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X24FC);
    // 0x800A3A14: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A3A18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A3A1C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A3A20: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800A3A24: bne         $s0, $zero, L_800A3A34
    if (ctx->r16 != 0) {
        // 0x800A3A28: sw          $s0, 0x12C($t4)
        MEM_W(0X12C, ctx->r12) = ctx->r16;
            goto L_800A3A34;
    }
    // 0x800A3A28: sw          $s0, 0x12C($t4)
    MEM_W(0X12C, ctx->r12) = ctx->r16;
    // 0x800A3A2C: b           L_800A3FB0
    // 0x800A3A30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A3FB0;
    // 0x800A3A30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A3A34:
    // 0x800A3A34: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800A3A38: lhu         $t7, 0x24FC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X24FC);
    // 0x800A3A3C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800A3A40: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800A3A44: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800A3A48: lw          $t9, 0x12C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X12C);
    // 0x800A3A4C: nop

    // 0x800A3A50: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800A3A54: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800A3A58: lhu         $t2, 0x24FC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X24FC);
    // 0x800A3A5C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A3A60: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x800A3A64: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800A3A68: lw          $t4, 0x12C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X12C);
    // 0x800A3A6C: nop

    // 0x800A3A70: sw          $t4, 0x128($t0)
    MEM_W(0X128, ctx->r8) = ctx->r12;
    // 0x800A3A74: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A3A78: nop

    // 0x800A3A7C: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800A3A80: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800A3A84: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A3A88: nop

    // 0x800A3A8C: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800A3A90: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800A3A94: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800A3A98: nop

    // 0x800A3A9C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800A3AA0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800A3AA4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A3AA8: nop

    // 0x800A3AAC: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x800A3AB0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A3AB4: nop

    // 0x800A3AB8: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800A3ABC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800A3AC0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A3AC4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A3AC8: nop

    // 0x800A3ACC: sh          $t0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r8;
    // 0x800A3AD0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800A3AD4: nop

    // 0x800A3AD8: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x800A3ADC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800A3AE0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A3AE4: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800A3AE8: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x800A3AEC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800A3AF0: nop

    // 0x800A3AF4: addiu       $t1, $t2, 0x2
    ctx->r9 = ADD32(ctx->r10, 0X2);
    // 0x800A3AF8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800A3AFC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800A3B00: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800A3B04: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x800A3B08: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A3B0C: nop

    // 0x800A3B10: addiu       $t7, $t0, 0x2
    ctx->r15 = ADD32(ctx->r8, 0X2);
    // 0x800A3B14: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800A3B18: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800A3B1C: nop

    // 0x800A3B20: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800A3B24: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A3B28: nop

    // 0x800A3B2C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x800A3B30: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A3B34: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x800A3B38: addiu       $a0, $t8, 0x1
    ctx->r4 = ADD32(ctx->r24, 0X1);
    // 0x800A3B3C: jal         0x800BCFCC
    // 0x800A3B40: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x800A3B40: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x800A3B44: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A3B48:
    // 0x800A3B48: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800A3B4C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3B50: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A3B54: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x800A3B58: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
    // 0x800A3B5C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3B60: nop

    // 0x800A3B64: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x800A3B68: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800A3B6C: bne         $at, $zero, L_800A3B48
    if (ctx->r1 != 0) {
        // 0x800A3B70: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_800A3B48;
    }
    // 0x800A3B70: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800A3B74: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A3B78:
    // 0x800A3B78: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3B7C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800A3B80: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800A3B84: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A3B88: addu        $t2, $t5, $t8
    ctx->r10 = ADD32(ctx->r13, ctx->r24);
    // 0x800A3B8C: sb          $t7, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r15;
    // 0x800A3B90: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3B94: nop

    // 0x800A3B98: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x800A3B9C: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800A3BA0: bne         $at, $zero, L_800A3B78
    if (ctx->r1 != 0) {
        // 0x800A3BA4: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_800A3B78;
    }
    // 0x800A3BA4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800A3BA8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800A3BAC: nop

    // 0x800A3BB0: addiu       $t4, $t3, 0x40
    ctx->r12 = ADD32(ctx->r11, 0X40);
    // 0x800A3BB4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800A3BB8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800A3BBC: nop

    // 0x800A3BC0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A3BC4: lh          $t6, 0x3E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3E);
    // 0x800A3BC8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800A3BCC: addiu       $t5, $t6, -0x8
    ctx->r13 = ADD32(ctx->r14, -0X8);
    // 0x800A3BD0: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x800A3BD4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A3BD8: nop

    // 0x800A3BDC: addiu       $t2, $t7, 0x2
    ctx->r10 = ADD32(ctx->r15, 0X2);
    // 0x800A3BE0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800A3BE4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800A3BE8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A3BEC: nop

    // 0x800A3BF0: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x800A3BF4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A3BF8: nop

    // 0x800A3BFC: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800A3C00: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800A3C04: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A3C08: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x800A3C0C: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
    // 0x800A3C10: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800A3C14: nop

    // 0x800A3C18: addiu       $t8, $t5, 0x2
    ctx->r24 = ADD32(ctx->r13, 0X2);
    // 0x800A3C1C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800A3C20: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800A3C24: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800A3C28: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
    // 0x800A3C2C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A3C30: nop

    // 0x800A3C34: addiu       $t9, $t1, 0x2
    ctx->r25 = ADD32(ctx->r9, 0X2);
    // 0x800A3C38: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800A3C3C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A3C40: nop

    // 0x800A3C44: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800A3C48: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800A3C4C: nop

    // 0x800A3C50: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x800A3C54: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800A3C58: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x800A3C5C: addiu       $a0, $t0, 0x1
    ctx->r4 = ADD32(ctx->r8, 0X1);
    // 0x800A3C60: jal         0x800BCFCC
    // 0x800A3C64: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x800A3C64: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_2:
    // 0x800A3C68: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A3C6C:
    // 0x800A3C6C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800A3C70: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3C74: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A3C78: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800A3C7C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800A3C80: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3C84: nop

    // 0x800A3C88: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800A3C8C: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x800A3C90: bne         $at, $zero, L_800A3C6C
    if (ctx->r1 != 0) {
        // 0x800A3C94: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_800A3C6C;
    }
    // 0x800A3C94: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800A3C98: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A3C9C:
    // 0x800A3C9C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3CA0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800A3CA4: sll         $t0, $t4, 3
    ctx->r8 = S32(ctx->r12 << 3);
    // 0x800A3CA8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A3CAC: addu        $t5, $t3, $t0
    ctx->r13 = ADD32(ctx->r11, ctx->r8);
    // 0x800A3CB0: sb          $t9, 0x7($t5)
    MEM_B(0X7, ctx->r13) = ctx->r25;
    // 0x800A3CB4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3CB8: nop

    // 0x800A3CBC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800A3CC0: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800A3CC4: bne         $at, $zero, L_800A3C9C
    if (ctx->r1 != 0) {
        // 0x800A3CC8: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_800A3C9C;
    }
    // 0x800A3CC8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800A3CCC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800A3CD0: nop

    // 0x800A3CD4: addiu       $t2, $t7, 0x40
    ctx->r10 = ADD32(ctx->r15, 0X40);
    // 0x800A3CD8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800A3CDC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800A3CE0: nop

    // 0x800A3CE4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800A3CE8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800A3CEC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A3CF0: nop

    // 0x800A3CF4: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
    // 0x800A3CF8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A3CFC: nop

    // 0x800A3D00: addiu       $t9, $t0, 0x2
    ctx->r25 = ADD32(ctx->r8, 0X2);
    // 0x800A3D04: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800A3D08: lh          $t5, 0x3A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3A);
    // 0x800A3D0C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A3D10: addiu       $t8, $t5, -0x8
    ctx->r24 = ADD32(ctx->r13, -0X8);
    // 0x800A3D14: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x800A3D18: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A3D1C: nop

    // 0x800A3D20: addiu       $t2, $t7, 0x2
    ctx->r10 = ADD32(ctx->r15, 0X2);
    // 0x800A3D24: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800A3D28: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800A3D2C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800A3D30: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
    // 0x800A3D34: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A3D38: nop

    // 0x800A3D3C: addiu       $t0, $t3, 0x2
    ctx->r8 = ADD32(ctx->r11, 0X2);
    // 0x800A3D40: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A3D44: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800A3D48: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x800A3D4C: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
    // 0x800A3D50: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800A3D54: nop

    // 0x800A3D58: addiu       $t6, $t8, 0x2
    ctx->r14 = ADD32(ctx->r24, 0X2);
    // 0x800A3D5C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800A3D60: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A3D64: nop

    // 0x800A3D68: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800A3D6C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800A3D70: nop

    // 0x800A3D74: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x800A3D78: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800A3D7C: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x800A3D80: addiu       $a0, $t1, 0x1
    ctx->r4 = ADD32(ctx->r9, 0X1);
    // 0x800A3D84: jal         0x800BCFCC
    // 0x800A3D88: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x800A3D88: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_3:
    // 0x800A3D8C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A3D90:
    // 0x800A3D90: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800A3D94: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3D98: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A3D9C: addu        $t9, $t3, $t0
    ctx->r25 = ADD32(ctx->r11, ctx->r8);
    // 0x800A3DA0: sb          $t4, 0x38($t9)
    MEM_B(0X38, ctx->r25) = ctx->r12;
    // 0x800A3DA4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3DA8: nop

    // 0x800A3DAC: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800A3DB0: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x800A3DB4: bne         $at, $zero, L_800A3D90
    if (ctx->r1 != 0) {
        // 0x800A3DB8: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_800A3D90;
    }
    // 0x800A3DB8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800A3DBC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A3DC0:
    // 0x800A3DC0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3DC4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800A3DC8: sll         $t1, $t2, 3
    ctx->r9 = S32(ctx->r10 << 3);
    // 0x800A3DCC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A3DD0: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800A3DD4: sb          $t6, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r14;
    // 0x800A3DD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3DDC: nop

    // 0x800A3DE0: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x800A3DE4: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800A3DE8: bne         $at, $zero, L_800A3DC0
    if (ctx->r1 != 0) {
        // 0x800A3DEC: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_800A3DC0;
    }
    // 0x800A3DEC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800A3DF0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800A3DF4: nop

    // 0x800A3DF8: addiu       $t5, $t9, 0x40
    ctx->r13 = ADD32(ctx->r25, 0X40);
    // 0x800A3DFC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800A3E00: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A3E04: nop

    // 0x800A3E08: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800A3E0C: lh          $t2, 0x3E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3E);
    // 0x800A3E10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E14: addiu       $t7, $t2, -0x8
    ctx->r15 = ADD32(ctx->r10, -0X8);
    // 0x800A3E18: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x800A3E1C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E20: nop

    // 0x800A3E24: addiu       $t3, $t6, 0x2
    ctx->r11 = ADD32(ctx->r14, 0X2);
    // 0x800A3E28: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800A3E2C: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x800A3E30: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E34: addiu       $t4, $t0, -0x8
    ctx->r12 = ADD32(ctx->r8, -0X8);
    // 0x800A3E38: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // 0x800A3E3C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E40: nop

    // 0x800A3E44: addiu       $t8, $t5, 0x2
    ctx->r24 = ADD32(ctx->r13, 0X2);
    // 0x800A3E48: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800A3E4C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E50: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x800A3E54: sh          $t2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r10;
    // 0x800A3E58: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E5C: nop

    // 0x800A3E60: addiu       $t6, $t1, 0x2
    ctx->r14 = ADD32(ctx->r9, 0X2);
    // 0x800A3E64: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800A3E68: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E6C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800A3E70: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x800A3E74: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E78: nop

    // 0x800A3E7C: addiu       $t9, $t4, 0x2
    ctx->r25 = ADD32(ctx->r12, 0X2);
    // 0x800A3E80: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800A3E84: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800A3E88: nop

    // 0x800A3E8C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800A3E90: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A3E94: nop

    // 0x800A3E98: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800A3E9C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800A3EA0: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x800A3EA4: addiu       $a0, $t2, 0x1
    ctx->r4 = ADD32(ctx->r10, 0X1);
    // 0x800A3EA8: jal         0x800BCFCC
    // 0x800A3EAC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x800A3EAC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_4:
    // 0x800A3EB0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A3EB4:
    // 0x800A3EB4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800A3EB8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3EBC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A3EC0: addu        $t3, $t1, $t6
    ctx->r11 = ADD32(ctx->r9, ctx->r14);
    // 0x800A3EC4: sb          $t7, 0x38($t3)
    MEM_B(0X38, ctx->r11) = ctx->r15;
    // 0x800A3EC8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3ECC: nop

    // 0x800A3ED0: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x800A3ED4: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800A3ED8: bne         $at, $zero, L_800A3EB4
    if (ctx->r1 != 0) {
        // 0x800A3EDC: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_800A3EB4;
    }
    // 0x800A3EDC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800A3EE0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A3EE4:
    // 0x800A3EE4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3EE8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800A3EEC: sll         $t2, $t8, 3
    ctx->r10 = S32(ctx->r24 << 3);
    // 0x800A3EF0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A3EF4: addu        $t1, $t5, $t2
    ctx->r9 = ADD32(ctx->r13, ctx->r10);
    // 0x800A3EF8: sb          $t9, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r25;
    // 0x800A3EFC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3F00: nop

    // 0x800A3F04: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A3F08: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x800A3F0C: bne         $at, $zero, L_800A3EE4
    if (ctx->r1 != 0) {
        // 0x800A3F10: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_800A3EE4;
    }
    // 0x800A3F10: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800A3F14: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800A3F18: nop

    // 0x800A3F1C: addiu       $t0, $t3, 0x40
    ctx->r8 = ADD32(ctx->r11, 0X40);
    // 0x800A3F20: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800A3F24: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800A3F28: nop

    // 0x800A3F2C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800A3F30: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800A3F34: addiu       $t8, $zero, -0x8000
    ctx->r24 = ADD32(0, -0X8000);
    // 0x800A3F38: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
    // 0x800A3F3C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800A3F40: nop

    // 0x800A3F44: addiu       $t9, $t2, 0x2
    ctx->r25 = ADD32(ctx->r10, 0X2);
    // 0x800A3F48: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800A3F4C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A3F50: addiu       $t1, $zero, -0x8000
    ctx->r9 = ADD32(0, -0X8000);
    // 0x800A3F54: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x800A3F58: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A3F5C: nop

    // 0x800A3F60: addiu       $t3, $t7, 0x2
    ctx->r11 = ADD32(ctx->r15, 0X2);
    // 0x800A3F64: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800A3F68: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800A3F6C: addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // 0x800A3F70: sh          $t0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r8;
    // 0x800A3F74: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800A3F78: nop

    // 0x800A3F7C: addiu       $t5, $t8, 0x2
    ctx->r13 = ADD32(ctx->r24, 0X2);
    // 0x800A3F80: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800A3F84: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A3F88: addiu       $t2, $zero, -0x8000
    ctx->r10 = ADD32(0, -0X8000);
    // 0x800A3F8C: sh          $t2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r10;
    // 0x800A3F90: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A3F94: nop

    // 0x800A3F98: addiu       $t6, $t1, 0x2
    ctx->r14 = ADD32(ctx->r9, 0X2);
    // 0x800A3F9C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800A3FA0: b           L_800A3FB0
    // 0x800A3FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A3FB0;
    // 0x800A3FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A3FA8: b           L_800A3FB0
    // 0x800A3FAC: nop

        goto L_800A3FB0;
    // 0x800A3FAC: nop

L_800A3FB0:
    // 0x800A3FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3FB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A3FB8: jr          $ra
    // 0x800A3FBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A3FBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80086010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008601C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086020: jal         0x8008A46C
    // 0x80086024: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80086024: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80086028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008602C: jal         0x8008BFF4
    // 0x80086030: nop

    func_8008BFF4(rdram, ctx);
        goto after_1;
    // 0x80086030: nop

    after_1:
    // 0x80086034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086038: jal         0x80089170
    // 0x8008603C: nop

    func_80089170(rdram, ctx);
        goto after_2;
    // 0x8008603C: nop

    after_2:
    // 0x80086040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086044: jal         0x80089418
    // 0x80086048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80089418(rdram, ctx);
        goto after_3;
    // 0x80086048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8008604C: b           L_8008605C
    // 0x80086050: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8008605C;
    // 0x80086050: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80086054: b           L_8008605C
    // 0x80086058: nop

        goto L_8008605C;
    // 0x80086058: nop

L_8008605C:
    // 0x8008605C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086064: jr          $ra
    // 0x80086068: nop

    return;
    // 0x80086068: nop

;}
RECOMP_FUNC void func_8007C54C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C54C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C550: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C554: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007C558: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007C55C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C560: nop

    // 0x8007C564: beq         $t6, $zero, L_8007C914
    if (ctx->r14 == 0) {
        // 0x8007C568: nop
    
            goto L_8007C914;
    }
    // 0x8007C568: nop

    // 0x8007C56C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C570: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007C574: addiu       $a0, $a0, 0x7190
    ctx->r4 = ADD32(ctx->r4, 0X7190);
    // 0x8007C578: jal         0x800BCFCC
    // 0x8007C57C: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x8007C57C: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_0:
    // 0x8007C580: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C584: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C588: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x8007C58C: nop

    // 0x8007C590: beq         $s0, $at, L_8007C5B8
    if (ctx->r16 == ctx->r1) {
        // 0x8007C594: nop
    
            goto L_8007C5B8;
    }
    // 0x8007C594: nop

    // 0x8007C598: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007C59C: beq         $s0, $at, L_8007C874
    if (ctx->r16 == ctx->r1) {
        // 0x8007C5A0: nop
    
            goto L_8007C874;
    }
    // 0x8007C5A0: nop

    // 0x8007C5A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007C5A8: beq         $s0, $at, L_8007C874
    if (ctx->r16 == ctx->r1) {
        // 0x8007C5AC: nop
    
            goto L_8007C874;
    }
    // 0x8007C5AC: nop

    // 0x8007C5B0: b           L_8007C90C
    // 0x8007C5B4: nop

        goto L_8007C90C;
    // 0x8007C5B4: nop

L_8007C5B8:
    // 0x8007C5B8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007C5BC: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007C5C0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007C5C4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8007C5C8:
    // 0x8007C5C8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007C5CC: nop

    // 0x8007C5D0: bne         $t9, $zero, L_8007C5E0
    if (ctx->r25 != 0) {
        // 0x8007C5D4: nop
    
            goto L_8007C5E0;
    }
    // 0x8007C5D4: nop

    // 0x8007C5D8: b           L_8007C6D0
    // 0x8007C5DC: nop

        goto L_8007C6D0;
    // 0x8007C5DC: nop

L_8007C5E0:
    // 0x8007C5E0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007C5E4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007C5E8: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x8007C5EC: nop

    // 0x8007C5F0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8007C5F4: sw          $t2, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r10;
    // 0x8007C5F8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007C5FC: nop

    // 0x8007C600: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x8007C604: nop

    // 0x8007C608: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8007C60C: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x8007C610: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C614: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007C618: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8007C61C: nop

    // 0x8007C620: swc1        $f4, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f4.u32l;
    // 0x8007C624: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007C628: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007C62C: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8007C630: nop

    // 0x8007C634: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8007C638: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007C63C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007C640: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8007C644: nop

    // 0x8007C648: swc1        $f8, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f8.u32l;
    // 0x8007C64C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007C650: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007C654: lwc1        $f10, 0x10($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8007C658: nop

    // 0x8007C65C: swc1        $f10, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f10.u32l;
    // 0x8007C660: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007C664: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007C668: lwc1        $f16, 0x14($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8007C66C: nop

    // 0x8007C670: swc1        $f16, 0xE8($t3)
    MEM_W(0XE8, ctx->r11) = ctx->f16.u32l;
    // 0x8007C674: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C678: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8007C67C: lwc1        $f18, 0x18($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X18);
    // 0x8007C680: nop

    // 0x8007C684: swc1        $f18, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f18.u32l;
    // 0x8007C688: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007C68C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007C690: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8007C694: nop

    // 0x8007C698: swc1        $f4, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f4.u32l;
    // 0x8007C69C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8007C6A0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007C6A4: lhu         $t2, 0x20($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X20);
    // 0x8007C6A8: nop

    // 0x8007C6AC: sh          $t2, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r10;
    // 0x8007C6B0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007C6B4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007C6B8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007C6BC: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8007C6C0: addiu       $t6, $t3, 0x160
    ctx->r14 = ADD32(ctx->r11, 0X160);
    // 0x8007C6C4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8007C6C8: bne         $at, $zero, L_8007C5C8
    if (ctx->r1 != 0) {
        // 0x8007C6CC: sw          $t5, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r13;
            goto L_8007C5C8;
    }
    // 0x8007C6CC: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8007C6D0:
    // 0x8007C6D0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C6D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C6D8: lwc1        $f6, 0x24($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X24);
    // 0x8007C6DC: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8007C6E0: lwc1        $f16, 0x44($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8007C6E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007C6E8: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007C6EC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007C6F0: swc1        $f18, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f18.u32l;
    // 0x8007C6F4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007C6F8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C6FC: lwc1        $f4, 0x28($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X28);
    // 0x8007C700: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8007C704: lwc1        $f10, 0x44($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8007C708: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007C70C: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007C710: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007C714: swc1        $f16, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = ctx->f16.u32l;
    // 0x8007C718: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007C71C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C720: lwc1        $f18, 0x2C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X2C);
    // 0x8007C724: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8007C728: lwc1        $f8, 0x44($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X44);
    // 0x8007C72C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007C730: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007C734: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007C738: swc1        $f10, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f10.u32l;
    // 0x8007C73C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007C740: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C744: lwc1        $f16, 0x30($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X30);
    // 0x8007C748: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8007C74C: lwc1        $f6, 0x44($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8007C750: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007C754: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007C758: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007C75C: swc1        $f8, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->f8.u32l;
    // 0x8007C760: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C764: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007C768: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x8007C76C: lwc1        $f16, 0x14($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8007C770: lwc1        $f4, 0x44($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X44);
    // 0x8007C774: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8007C778: addiu       $t5, $t5, 0x7190
    ctx->r13 = ADD32(ctx->r13, 0X7190);
    // 0x8007C77C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007C780: swc1        $f6, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f6.u32l;
    // 0x8007C784: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C788: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C78C: lwc1        $f8, 0x38($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X38);
    // 0x8007C790: lwc1        $f10, 0x18($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X18);
    // 0x8007C794: lwc1        $f18, 0x44($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8007C798: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8007C79C: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007C7A0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007C7A4: swc1        $f4, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f4.u32l;
    // 0x8007C7A8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007C7AC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C7B0: lwc1        $f6, 0x3C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x8007C7B4: lwc1        $f8, 0x1C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8007C7B8: lwc1        $f16, 0x44($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8007C7BC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007C7C0: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007C7C4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007C7C8: swc1        $f18, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->f18.u32l;
    // 0x8007C7CC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007C7D0: nop

    // 0x8007C7D4: lhu         $t0, 0x40($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0X40);
    // 0x8007C7D8: nop

    // 0x8007C7DC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8007C7E0: bgez        $t0, L_8007C7F8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007C7E4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8007C7F8;
    }
    // 0x8007C7E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007C7E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007C7EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C7F0: nop

    // 0x8007C7F4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8007C7F8:
    // 0x8007C7F8: lhu         $t4, 0x20($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X20);
    // 0x8007C7FC: nop

    // 0x8007C800: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8007C804: bgez        $t4, L_8007C81C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007C808: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8007C81C;
    }
    // 0x8007C808: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007C80C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007C810: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007C814: nop

    // 0x8007C818: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8007C81C:
    // 0x8007C81C: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8007C820: lwc1        $f8, 0x44($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X44);
    // 0x8007C824: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C828: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8007C82C: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007C830: swc1        $f10, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->f10.u32l;
    // 0x8007C834: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007C838: nop

    // 0x8007C83C: lhu         $t5, 0x20($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X20);
    // 0x8007C840: nop

    // 0x8007C844: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8007C848: bgez        $t5, L_8007C860
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007C84C: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8007C860;
    }
    // 0x8007C84C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007C850: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007C854: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007C858: nop

    // 0x8007C85C: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_8007C860:
    // 0x8007C860: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007C864: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007C868: swc1        $f6, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->f6.u32l;
    // 0x8007C86C: b           L_8007C90C
    // 0x8007C870: nop

        goto L_8007C90C;
    // 0x8007C870: nop

L_8007C874:
    // 0x8007C874: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007C878: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007C87C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007C880: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C884: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C888: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8007C88C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007C890: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007C894: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8007C898: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8007C89C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007C8A0: sh          $t1, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r9;
    // 0x8007C8A4: nop

    // 0x8007C8A8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007C8AC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C8B0: lwc1        $f10, 0x44($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8007C8B4: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007C8B8: swc1        $f10, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f10.u32l;
    // 0x8007C8BC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8007C8C0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C8C4: lwc1        $f18, 0x24($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X24);
    // 0x8007C8C8: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007C8CC: swc1        $f18, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f18.u32l;
    // 0x8007C8D0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007C8D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007C8D8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8007C8DC: nop

    // 0x8007C8E0: bne         $t7, $at, L_8007C904
    if (ctx->r15 != ctx->r1) {
        // 0x8007C8E4: nop
    
            goto L_8007C904;
    }
    // 0x8007C8E4: nop

    // 0x8007C8E8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007C8EC: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007C8F0: nop

    // 0x8007C8F4: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x8007C8F8: nop

    // 0x8007C8FC: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x8007C900: sw          $t1, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r9;
L_8007C904:
    // 0x8007C904: b           L_8007C90C
    // 0x8007C908: nop

        goto L_8007C90C;
    // 0x8007C908: nop

L_8007C90C:
    // 0x8007C90C: b           L_8007D528
    // 0x8007C910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007D528;
    // 0x8007C910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C914:
    // 0x8007C914: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007C918: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8007C91C: lw          $s0, 0x7190($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7190);
    // 0x8007C920: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C924: beq         $s0, $at, L_8007C94C
    if (ctx->r16 == ctx->r1) {
        // 0x8007C928: nop
    
            goto L_8007C94C;
    }
    // 0x8007C928: nop

    // 0x8007C92C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007C930: beq         $s0, $at, L_8007D344
    if (ctx->r16 == ctx->r1) {
        // 0x8007C934: nop
    
            goto L_8007D344;
    }
    // 0x8007C934: nop

    // 0x8007C938: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007C93C: beq         $s0, $at, L_8007D344
    if (ctx->r16 == ctx->r1) {
        // 0x8007C940: nop
    
            goto L_8007D344;
    }
    // 0x8007C940: nop

    // 0x8007C944: b           L_8007D500
    // 0x8007C948: nop

        goto L_8007D500;
    // 0x8007C948: nop

L_8007C94C:
    // 0x8007C94C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C950: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007C954: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007C958: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007C95C: lwc1        $f16, 0x48($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8007C960: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007C964: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8007C968: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007C96C: nop

    // 0x8007C970: lwc1        $f8, 0xCC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8007C974: nop

    // 0x8007C978: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8007C97C: swc1        $f10, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f10.u32l;
    // 0x8007C980: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C984: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007C988: lwc1        $f18, 0x48($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X48);
    // 0x8007C98C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007C990: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007C994: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007C998: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x8007C99C: nop

    // 0x8007C9A0: bc1t        L_8007CA3C
    if (c1cs) {
        // 0x8007C9A4: nop
    
            goto L_8007CA3C;
    }
    // 0x8007C9A4: nop

    // 0x8007C9A8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007C9AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007C9B0: nop

    // 0x8007C9B4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x8007C9B8: nop

    // 0x8007C9BC: bc1f        L_8007C9EC
    if (!c1cs) {
        // 0x8007C9C0: nop
    
            goto L_8007C9EC;
    }
    // 0x8007C9C0: nop

    // 0x8007C9C4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007C9C8: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007C9CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C9D0: lwc1        $f10, 0x71B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71B4);
    // 0x8007C9D4: lwc1        $f4, 0xCC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x8007C9D8: nop

    // 0x8007C9DC: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8007C9E0: nop

    // 0x8007C9E4: bc1t        L_8007CA3C
    if (c1cs) {
        // 0x8007C9E8: nop
    
            goto L_8007CA3C;
    }
    // 0x8007C9E8: nop

L_8007C9EC:
    // 0x8007C9EC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C9F0: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007C9F4: lwc1        $f18, 0x48($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8007C9F8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8007C9FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007CA00: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CA04: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8007CA08: nop

    // 0x8007CA0C: bc1f        L_8007CA54
    if (!c1cs) {
        // 0x8007CA10: nop
    
            goto L_8007CA54;
    }
    // 0x8007CA10: nop

    // 0x8007CA14: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007CA18: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007CA1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CA20: lwc1        $f4, 0x71B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71B4);
    // 0x8007CA24: lwc1        $f8, 0xCC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8007CA28: nop

    // 0x8007CA2C: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8007CA30: nop

    // 0x8007CA34: bc1f        L_8007CA54
    if (!c1cs) {
        // 0x8007CA38: nop
    
            goto L_8007CA54;
    }
    // 0x8007CA38: nop

L_8007CA3C:
    // 0x8007CA3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CA40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007CA44: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007CA48: lwc1        $f10, 0x71B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71B4);
    // 0x8007CA4C: b           L_8007CA5C
    // 0x8007CA50: swc1        $f10, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f10.u32l;
        goto L_8007CA5C;
    // 0x8007CA50: swc1        $f10, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f10.u32l;
L_8007CA54:
    // 0x8007CA54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007CA58: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8007CA5C:
    // 0x8007CA5C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007CA60: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007CA64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CA68: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CA6C: lwc1        $f18, 0x4C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4C);
    // 0x8007CA70: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007CA74: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8007CA78: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007CA7C: nop

    // 0x8007CA80: lwc1        $f8, 0xD0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8007CA84: nop

    // 0x8007CA88: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007CA8C: swc1        $f4, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f4.u32l;
    // 0x8007CA90: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007CA94: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007CA98: lwc1        $f10, 0x4C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x8007CA9C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CAA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CAA4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CAA8: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x8007CAAC: nop

    // 0x8007CAB0: bc1t        L_8007CB4C
    if (c1cs) {
        // 0x8007CAB4: nop
    
            goto L_8007CB4C;
    }
    // 0x8007CAB4: nop

    // 0x8007CAB8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CABC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CAC0: nop

    // 0x8007CAC4: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x8007CAC8: nop

    // 0x8007CACC: bc1f        L_8007CAFC
    if (!c1cs) {
        // 0x8007CAD0: nop
    
            goto L_8007CAFC;
    }
    // 0x8007CAD0: nop

    // 0x8007CAD4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007CAD8: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007CADC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CAE0: lwc1        $f4, 0x71B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71B8);
    // 0x8007CAE4: lwc1        $f16, 0xD0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8007CAE8: nop

    // 0x8007CAEC: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x8007CAF0: nop

    // 0x8007CAF4: bc1t        L_8007CB4C
    if (c1cs) {
        // 0x8007CAF8: nop
    
            goto L_8007CB4C;
    }
    // 0x8007CAF8: nop

L_8007CAFC:
    // 0x8007CAFC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007CB00: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007CB04: lwc1        $f10, 0x4C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4C);
    // 0x8007CB08: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007CB0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007CB10: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CB14: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8007CB18: nop

    // 0x8007CB1C: bc1f        L_8007CB64
    if (!c1cs) {
        // 0x8007CB20: nop
    
            goto L_8007CB64;
    }
    // 0x8007CB20: nop

    // 0x8007CB24: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007CB28: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007CB2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CB30: lwc1        $f16, 0x71B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71B8);
    // 0x8007CB34: lwc1        $f8, 0xD0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8007CB38: nop

    // 0x8007CB3C: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x8007CB40: nop

    // 0x8007CB44: bc1f        L_8007CB64
    if (!c1cs) {
        // 0x8007CB48: nop
    
            goto L_8007CB64;
    }
    // 0x8007CB48: nop

L_8007CB4C:
    // 0x8007CB4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CB50: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007CB54: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007CB58: lwc1        $f4, 0x71B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71B8);
    // 0x8007CB5C: b           L_8007CB6C
    // 0x8007CB60: swc1        $f4, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f4.u32l;
        goto L_8007CB6C;
    // 0x8007CB60: swc1        $f4, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f4.u32l;
L_8007CB64:
    // 0x8007CB64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007CB68: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_8007CB6C:
    // 0x8007CB6C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007CB70: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007CB74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CB78: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CB7C: lwc1        $f10, 0x50($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X50);
    // 0x8007CB80: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007CB84: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8007CB88: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007CB8C: nop

    // 0x8007CB90: lwc1        $f8, 0xF4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF4);
    // 0x8007CB94: nop

    // 0x8007CB98: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8007CB9C: swc1        $f16, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f16.u32l;
    // 0x8007CBA0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007CBA4: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007CBA8: lwc1        $f4, 0x50($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X50);
    // 0x8007CBAC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CBB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CBB4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CBB8: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x8007CBBC: nop

    // 0x8007CBC0: bc1t        L_8007CC5C
    if (c1cs) {
        // 0x8007CBC4: nop
    
            goto L_8007CC5C;
    }
    // 0x8007CBC4: nop

    // 0x8007CBC8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CBCC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CBD0: nop

    // 0x8007CBD4: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8007CBD8: nop

    // 0x8007CBDC: bc1f        L_8007CC0C
    if (!c1cs) {
        // 0x8007CBE0: nop
    
            goto L_8007CC0C;
    }
    // 0x8007CBE0: nop

    // 0x8007CBE4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007CBE8: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007CBEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CBF0: lwc1        $f16, 0x71BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71BC);
    // 0x8007CBF4: lwc1        $f18, 0xF4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x8007CBF8: nop

    // 0x8007CBFC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x8007CC00: nop

    // 0x8007CC04: bc1t        L_8007CC5C
    if (c1cs) {
        // 0x8007CC08: nop
    
            goto L_8007CC5C;
    }
    // 0x8007CC08: nop

L_8007CC0C:
    // 0x8007CC0C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007CC10: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007CC14: lwc1        $f4, 0x50($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X50);
    // 0x8007CC18: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007CC1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007CC20: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CC24: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8007CC28: nop

    // 0x8007CC2C: bc1f        L_8007CC74
    if (!c1cs) {
        // 0x8007CC30: nop
    
            goto L_8007CC74;
    }
    // 0x8007CC30: nop

    // 0x8007CC34: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007CC38: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007CC3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CC40: lwc1        $f18, 0x71BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71BC);
    // 0x8007CC44: lwc1        $f8, 0xF4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x8007CC48: nop

    // 0x8007CC4C: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8007CC50: nop

    // 0x8007CC54: bc1f        L_8007CC74
    if (!c1cs) {
        // 0x8007CC58: nop
    
            goto L_8007CC74;
    }
    // 0x8007CC58: nop

L_8007CC5C:
    // 0x8007CC5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CC60: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007CC64: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8007CC68: lwc1        $f16, 0x71BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71BC);
    // 0x8007CC6C: b           L_8007CC7C
    // 0x8007CC70: swc1        $f16, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f16.u32l;
        goto L_8007CC7C;
    // 0x8007CC70: swc1        $f16, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f16.u32l;
L_8007CC74:
    // 0x8007CC74: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007CC78: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_8007CC7C:
    // 0x8007CC7C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007CC80: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007CC84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CC88: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CC8C: lwc1        $f4, 0x54($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X54);
    // 0x8007CC90: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007CC94: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007CC98: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007CC9C: nop

    // 0x8007CCA0: lwc1        $f8, 0xF8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x8007CCA4: nop

    // 0x8007CCA8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007CCAC: swc1        $f18, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f18.u32l;
    // 0x8007CCB0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007CCB4: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007CCB8: lwc1        $f16, 0x54($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X54);
    // 0x8007CCBC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CCC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CCC4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8007CCC8: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8007CCCC: nop

    // 0x8007CCD0: bc1t        L_8007CD6C
    if (c1cs) {
        // 0x8007CCD4: nop
    
            goto L_8007CD6C;
    }
    // 0x8007CCD4: nop

    // 0x8007CCD8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CCDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CCE0: nop

    // 0x8007CCE4: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x8007CCE8: nop

    // 0x8007CCEC: bc1f        L_8007CD1C
    if (!c1cs) {
        // 0x8007CCF0: nop
    
            goto L_8007CD1C;
    }
    // 0x8007CCF0: nop

    // 0x8007CCF4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007CCF8: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007CCFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CD00: lwc1        $f18, 0x71C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71C0);
    // 0x8007CD04: lwc1        $f10, 0xF8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x8007CD08: nop

    // 0x8007CD0C: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x8007CD10: nop

    // 0x8007CD14: bc1t        L_8007CD6C
    if (c1cs) {
        // 0x8007CD18: nop
    
            goto L_8007CD6C;
    }
    // 0x8007CD18: nop

L_8007CD1C:
    // 0x8007CD1C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007CD20: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007CD24: lwc1        $f16, 0x54($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X54);
    // 0x8007CD28: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8007CD2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007CD30: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8007CD34: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8007CD38: nop

    // 0x8007CD3C: bc1f        L_8007CD84
    if (!c1cs) {
        // 0x8007CD40: nop
    
            goto L_8007CD84;
    }
    // 0x8007CD40: nop

    // 0x8007CD44: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007CD48: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007CD4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CD50: lwc1        $f10, 0x71C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71C0);
    // 0x8007CD54: lwc1        $f8, 0xF8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x8007CD58: nop

    // 0x8007CD5C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x8007CD60: nop

    // 0x8007CD64: bc1f        L_8007CD84
    if (!c1cs) {
        // 0x8007CD68: nop
    
            goto L_8007CD84;
    }
    // 0x8007CD68: nop

L_8007CD6C:
    // 0x8007CD6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CD70: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007CD74: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8007CD78: lwc1        $f18, 0x71C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71C0);
    // 0x8007CD7C: b           L_8007CD8C
    // 0x8007CD80: swc1        $f18, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f18.u32l;
        goto L_8007CD8C;
    // 0x8007CD80: swc1        $f18, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f18.u32l;
L_8007CD84:
    // 0x8007CD84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007CD88: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8007CD8C:
    // 0x8007CD8C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007CD90: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007CD94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CD98: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CD9C: lwc1        $f16, 0x58($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X58);
    // 0x8007CDA0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007CDA4: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8007CDA8: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007CDAC: nop

    // 0x8007CDB0: lwc1        $f8, 0xE8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XE8);
    // 0x8007CDB4: nop

    // 0x8007CDB8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8007CDBC: swc1        $f10, 0xE8($t3)
    MEM_W(0XE8, ctx->r11) = ctx->f10.u32l;
    // 0x8007CDC0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007CDC4: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007CDC8: lwc1        $f18, 0x58($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8007CDCC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CDD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CDD4: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CDD8: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x8007CDDC: nop

    // 0x8007CDE0: bc1t        L_8007CE7C
    if (c1cs) {
        // 0x8007CDE4: nop
    
            goto L_8007CE7C;
    }
    // 0x8007CDE4: nop

    // 0x8007CDE8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CDEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CDF0: nop

    // 0x8007CDF4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x8007CDF8: nop

    // 0x8007CDFC: bc1f        L_8007CE2C
    if (!c1cs) {
        // 0x8007CE00: nop
    
            goto L_8007CE2C;
    }
    // 0x8007CE00: nop

    // 0x8007CE04: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007CE08: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007CE0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CE10: lwc1        $f10, 0x71C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71C4);
    // 0x8007CE14: lwc1        $f4, 0xE8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x8007CE18: nop

    // 0x8007CE1C: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8007CE20: nop

    // 0x8007CE24: bc1t        L_8007CE7C
    if (c1cs) {
        // 0x8007CE28: nop
    
            goto L_8007CE7C;
    }
    // 0x8007CE28: nop

L_8007CE2C:
    // 0x8007CE2C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007CE30: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007CE34: lwc1        $f18, 0x58($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X58);
    // 0x8007CE38: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8007CE3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007CE40: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8007CE44: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8007CE48: nop

    // 0x8007CE4C: bc1f        L_8007CE94
    if (!c1cs) {
        // 0x8007CE50: nop
    
            goto L_8007CE94;
    }
    // 0x8007CE50: nop

    // 0x8007CE54: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007CE58: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007CE5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CE60: lwc1        $f4, 0x71C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71C4);
    // 0x8007CE64: lwc1        $f8, 0xE8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XE8);
    // 0x8007CE68: nop

    // 0x8007CE6C: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8007CE70: nop

    // 0x8007CE74: bc1f        L_8007CE94
    if (!c1cs) {
        // 0x8007CE78: nop
    
            goto L_8007CE94;
    }
    // 0x8007CE78: nop

L_8007CE7C:
    // 0x8007CE7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CE80: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007CE84: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8007CE88: lwc1        $f10, 0x71C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71C4);
    // 0x8007CE8C: b           L_8007CE9C
    // 0x8007CE90: swc1        $f10, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f10.u32l;
        goto L_8007CE9C;
    // 0x8007CE90: swc1        $f10, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f10.u32l;
L_8007CE94:
    // 0x8007CE94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007CE98: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8007CE9C:
    // 0x8007CE9C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007CEA0: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007CEA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CEA8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CEAC: lwc1        $f18, 0x5C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x8007CEB0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007CEB4: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8007CEB8: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007CEBC: nop

    // 0x8007CEC0: lwc1        $f8, 0xEC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XEC);
    // 0x8007CEC4: nop

    // 0x8007CEC8: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007CECC: swc1        $f4, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f4.u32l;
    // 0x8007CED0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007CED4: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007CED8: lwc1        $f10, 0x5C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X5C);
    // 0x8007CEDC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CEE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CEE4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CEE8: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x8007CEEC: nop

    // 0x8007CEF0: bc1t        L_8007CF8C
    if (c1cs) {
        // 0x8007CEF4: nop
    
            goto L_8007CF8C;
    }
    // 0x8007CEF4: nop

    // 0x8007CEF8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007CEFC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007CF00: nop

    // 0x8007CF04: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x8007CF08: nop

    // 0x8007CF0C: bc1f        L_8007CF3C
    if (!c1cs) {
        // 0x8007CF10: nop
    
            goto L_8007CF3C;
    }
    // 0x8007CF10: nop

    // 0x8007CF14: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007CF18: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007CF1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CF20: lwc1        $f4, 0x71C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71C8);
    // 0x8007CF24: lwc1        $f16, 0xEC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XEC);
    // 0x8007CF28: nop

    // 0x8007CF2C: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x8007CF30: nop

    // 0x8007CF34: bc1t        L_8007CF8C
    if (c1cs) {
        // 0x8007CF38: nop
    
            goto L_8007CF8C;
    }
    // 0x8007CF38: nop

L_8007CF3C:
    // 0x8007CF3C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007CF40: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007CF44: lwc1        $f10, 0x5C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x8007CF48: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007CF4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007CF50: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8007CF54: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8007CF58: nop

    // 0x8007CF5C: bc1f        L_8007CFA4
    if (!c1cs) {
        // 0x8007CF60: nop
    
            goto L_8007CFA4;
    }
    // 0x8007CF60: nop

    // 0x8007CF64: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007CF68: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007CF6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CF70: lwc1        $f16, 0x71C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71C8);
    // 0x8007CF74: lwc1        $f8, 0xEC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XEC);
    // 0x8007CF78: nop

    // 0x8007CF7C: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x8007CF80: nop

    // 0x8007CF84: bc1f        L_8007CFA4
    if (!c1cs) {
        // 0x8007CF88: nop
    
            goto L_8007CFA4;
    }
    // 0x8007CF88: nop

L_8007CF8C:
    // 0x8007CF8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007CF90: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007CF94: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007CF98: lwc1        $f4, 0x71C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X71C8);
    // 0x8007CF9C: b           L_8007CFAC
    // 0x8007CFA0: swc1        $f4, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f4.u32l;
        goto L_8007CFAC;
    // 0x8007CFA0: swc1        $f4, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f4.u32l;
L_8007CFA4:
    // 0x8007CFA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007CFA8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8007CFAC:
    // 0x8007CFAC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007CFB0: addiu       $t1, $t1, 0x7190
    ctx->r9 = ADD32(ctx->r9, 0X7190);
    // 0x8007CFB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007CFB8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007CFBC: lwc1        $f10, 0x60($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X60);
    // 0x8007CFC0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007CFC4: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8007CFC8: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007CFCC: nop

    // 0x8007CFD0: lwc1        $f8, 0xF0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8007CFD4: nop

    // 0x8007CFD8: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8007CFDC: swc1        $f16, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f16.u32l;
    // 0x8007CFE0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007CFE4: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007CFE8: lwc1        $f4, 0x60($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X60);
    // 0x8007CFEC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007CFF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007CFF4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8007CFF8: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x8007CFFC: nop

    // 0x8007D000: bc1t        L_8007D09C
    if (c1cs) {
        // 0x8007D004: nop
    
            goto L_8007D09C;
    }
    // 0x8007D004: nop

    // 0x8007D008: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007D00C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007D010: nop

    // 0x8007D014: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8007D018: nop

    // 0x8007D01C: bc1f        L_8007D04C
    if (!c1cs) {
        // 0x8007D020: nop
    
            goto L_8007D04C;
    }
    // 0x8007D020: nop

    // 0x8007D024: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007D028: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x8007D02C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D030: lwc1        $f16, 0x71CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71CC);
    // 0x8007D034: lwc1        $f18, 0xF0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x8007D038: nop

    // 0x8007D03C: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x8007D040: nop

    // 0x8007D044: bc1t        L_8007D09C
    if (c1cs) {
        // 0x8007D048: nop
    
            goto L_8007D09C;
    }
    // 0x8007D048: nop

L_8007D04C:
    // 0x8007D04C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007D050: addiu       $t2, $t2, 0x7190
    ctx->r10 = ADD32(ctx->r10, 0X7190);
    // 0x8007D054: lwc1        $f4, 0x60($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X60);
    // 0x8007D058: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007D05C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007D060: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8007D064: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8007D068: nop

    // 0x8007D06C: bc1f        L_8007D0B4
    if (!c1cs) {
        // 0x8007D070: nop
    
            goto L_8007D0B4;
    }
    // 0x8007D070: nop

    // 0x8007D074: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007D078: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007D07C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D080: lwc1        $f18, 0x71CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71CC);
    // 0x8007D084: lwc1        $f8, 0xF0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XF0);
    // 0x8007D088: nop

    // 0x8007D08C: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8007D090: nop

    // 0x8007D094: bc1f        L_8007D0B4
    if (!c1cs) {
        // 0x8007D098: nop
    
            goto L_8007D0B4;
    }
    // 0x8007D098: nop

L_8007D09C:
    // 0x8007D09C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D0A0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007D0A4: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007D0A8: lwc1        $f16, 0x71CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71CC);
    // 0x8007D0AC: b           L_8007D0BC
    // 0x8007D0B0: swc1        $f16, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f16.u32l;
        goto L_8007D0BC;
    // 0x8007D0B0: swc1        $f16, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f16.u32l;
L_8007D0B4:
    // 0x8007D0B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007D0B8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_8007D0BC:
    // 0x8007D0BC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007D0C0: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007D0C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D0C8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007D0CC: lwc1        $f4, 0x64($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X64);
    // 0x8007D0D0: lwc1        $f8, 0x68($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X68);
    // 0x8007D0D4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007D0D8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007D0DC: swc1        $f18, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->f18.u32l;
    // 0x8007D0E0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007D0E4: addiu       $t9, $t9, 0x7190
    ctx->r25 = ADD32(ctx->r25, 0X7190);
    // 0x8007D0E8: lwc1        $f16, 0x64($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X64);
    // 0x8007D0EC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007D0F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007D0F4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8007D0F8: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8007D0FC: nop

    // 0x8007D100: bc1t        L_8007D1BC
    if (c1cs) {
        // 0x8007D104: nop
    
            goto L_8007D1BC;
    }
    // 0x8007D104: nop

    // 0x8007D108: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8007D10C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007D110: nop

    // 0x8007D114: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x8007D118: nop

    // 0x8007D11C: bc1f        L_8007D15C
    if (!c1cs) {
        // 0x8007D120: nop
    
            goto L_8007D15C;
    }
    // 0x8007D120: nop

    // 0x8007D124: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007D128: lhu         $t1, 0x71D0($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X71D0);
    // 0x8007D12C: lwc1        $f10, 0x68($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X68);
    // 0x8007D130: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8007D134: bgez        $t1, L_8007D14C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8007D138: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8007D14C;
    }
    // 0x8007D138: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007D13C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007D140: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007D144: nop

    // 0x8007D148: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_8007D14C:
    // 0x8007D14C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8007D150: nop

    // 0x8007D154: bc1t        L_8007D1BC
    if (c1cs) {
        // 0x8007D158: nop
    
            goto L_8007D1BC;
    }
    // 0x8007D158: nop

L_8007D15C:
    // 0x8007D15C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007D160: addiu       $t8, $t8, 0x7190
    ctx->r24 = ADD32(ctx->r24, 0X7190);
    // 0x8007D164: lwc1        $f4, 0x64($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X64);
    // 0x8007D168: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007D16C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007D170: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8007D174: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x8007D178: nop

    // 0x8007D17C: bc1f        L_8007D1D4
    if (!c1cs) {
        // 0x8007D180: nop
    
            goto L_8007D1D4;
    }
    // 0x8007D180: nop

    // 0x8007D184: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007D188: lhu         $t0, 0x71D0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X71D0);
    // 0x8007D18C: lwc1        $f6, 0x68($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X68);
    // 0x8007D190: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8007D194: bgez        $t0, L_8007D1AC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007D198: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8007D1AC;
    }
    // 0x8007D198: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007D19C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007D1A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007D1A4: nop

    // 0x8007D1A8: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8007D1AC:
    // 0x8007D1AC: c.le.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl <= ctx->f16.fl;
    // 0x8007D1B0: nop

    // 0x8007D1B4: bc1f        L_8007D1D4
    if (!c1cs) {
        // 0x8007D1B8: nop
    
            goto L_8007D1D4;
    }
    // 0x8007D1B8: nop

L_8007D1BC:
    // 0x8007D1BC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007D1C0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007D1C4: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8007D1C8: lhu         $t4, 0x71D0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X71D0);
    // 0x8007D1CC: b           L_8007D214
    // 0x8007D1D0: sh          $t4, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r12;
        goto L_8007D214;
    // 0x8007D1D0: sh          $t4, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r12;
L_8007D1D4:
    // 0x8007D1D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007D1D8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D1DC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8007D1E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007D1E4: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007D1E8: lwc1        $f8, 0x68($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X68);
    // 0x8007D1EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007D1F0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007D1F4: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007D1F8: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007D1FC: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8007D200: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007D204: sh          $t5, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r13;
    // 0x8007D208: nop

    // 0x8007D20C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007D210: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8007D214:
    // 0x8007D214: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007D218: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007D21C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007D220: addiu       $t0, $t8, 0x160
    ctx->r8 = ADD32(ctx->r24, 0X160);
    // 0x8007D224: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8007D228: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_8007D22C:
    // 0x8007D22C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007D230: nop

    // 0x8007D234: bne         $t4, $zero, L_8007D244
    if (ctx->r12 != 0) {
        // 0x8007D238: nop
    
            goto L_8007D244;
    }
    // 0x8007D238: nop

    // 0x8007D23C: b           L_8007D324
    // 0x8007D240: nop

        goto L_8007D324;
    // 0x8007D240: nop

L_8007D244:
    // 0x8007D244: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007D248: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8007D24C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007D250: lwc1        $f10, 0xCC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8007D254: nop

    // 0x8007D258: swc1        $f10, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f10.u32l;
    // 0x8007D25C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007D260: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007D264: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007D268: lwc1        $f4, 0xD0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8007D26C: nop

    // 0x8007D270: swc1        $f4, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f4.u32l;
    // 0x8007D274: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007D278: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007D27C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007D280: lwc1        $f6, 0xF4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x8007D284: nop

    // 0x8007D288: swc1        $f6, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f6.u32l;
    // 0x8007D28C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007D290: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8007D294: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8007D298: lwc1        $f16, 0xF8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x8007D29C: nop

    // 0x8007D2A0: swc1        $f16, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f16.u32l;
    // 0x8007D2A4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007D2A8: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8007D2AC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2B0: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8007D2B4: nop

    // 0x8007D2B8: swc1        $f8, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f8.u32l;
    // 0x8007D2BC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8007D2C0: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x8007D2C4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2C8: lwc1        $f18, 0xEC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XEC);
    // 0x8007D2CC: nop

    // 0x8007D2D0: swc1        $f18, 0xEC($t3)
    MEM_W(0XEC, ctx->r11) = ctx->f18.u32l;
    // 0x8007D2D4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007D2D8: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007D2DC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2E0: lwc1        $f10, 0xF0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XF0);
    // 0x8007D2E4: nop

    // 0x8007D2E8: swc1        $f10, 0xF0($t5)
    MEM_W(0XF0, ctx->r13) = ctx->f10.u32l;
    // 0x8007D2EC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8007D2F0: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8007D2F4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2F8: lh          $t9, 0x11E($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X11E);
    // 0x8007D2FC: nop

    // 0x8007D300: sh          $t9, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r25;
    // 0x8007D304: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007D308: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007D30C: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8007D310: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8007D314: addiu       $t2, $t4, 0x160
    ctx->r10 = ADD32(ctx->r12, 0X160);
    // 0x8007D318: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8007D31C: bne         $at, $zero, L_8007D22C
    if (ctx->r1 != 0) {
        // 0x8007D320: sw          $t0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r8;
            goto L_8007D22C;
    }
    // 0x8007D320: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_8007D324:
    // 0x8007D324: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D328: nop

    // 0x8007D32C: bne         $t3, $zero, L_8007D33C
    if (ctx->r11 != 0) {
        // 0x8007D330: nop
    
            goto L_8007D33C;
    }
    // 0x8007D330: nop

    // 0x8007D334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D338: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
L_8007D33C:
    // 0x8007D33C: b           L_8007D500
    // 0x8007D340: nop

        goto L_8007D500;
    // 0x8007D340: nop

L_8007D344:
    // 0x8007D344: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007D348: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007D34C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D350: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007D354: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8007D358: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007D35C: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007D360: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007D364: nop

    // 0x8007D368: lh          $t4, 0x11E($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X11E);
    // 0x8007D36C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8007D370: nop

    // 0x8007D374: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8007D378: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007D37C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007D380: nop

    // 0x8007D384: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007D388: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8007D38C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8007D390: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8007D394: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8007D398: addu        $t2, $t4, $t1
    ctx->r10 = ADD32(ctx->r12, ctx->r9);
    // 0x8007D39C: sh          $t2, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = ctx->r10;
    // 0x8007D3A0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007D3A4: addiu       $t0, $t0, 0x7190
    ctx->r8 = ADD32(ctx->r8, 0X7190);
    // 0x8007D3A8: lwc1        $f18, 0x48($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8007D3AC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8007D3B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007D3B4: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8007D3B8: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x8007D3BC: nop

    // 0x8007D3C0: bc1f        L_8007D440
    if (!c1cs) {
        // 0x8007D3C4: nop
    
            goto L_8007D440;
    }
    // 0x8007D3C4: nop

    // 0x8007D3C8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8007D3CC: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8007D3D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007D3D4: lh          $t6, 0x11E($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X11E);
    // 0x8007D3D8: addiu       $t5, $t5, 0x7190
    ctx->r13 = ADD32(ctx->r13, 0X7190);
    // 0x8007D3DC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8007D3E0: lwc1        $f8, 0x4C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4C);
    // 0x8007D3E4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007D3E8: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x8007D3EC: nop

    // 0x8007D3F0: bc1f        L_8007D430
    if (!c1cs) {
        // 0x8007D3F4: nop
    
            goto L_8007D430;
    }
    // 0x8007D3F4: nop

    // 0x8007D3F8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007D3FC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007D400: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007D404: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007D408: addiu       $t7, $t7, 0x7190
    ctx->r15 = ADD32(ctx->r15, 0X7190);
    // 0x8007D40C: lwc1        $f18, 0x4C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8007D410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007D414: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007D418: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007D41C: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8007D420: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8007D424: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007D428: b           L_8007D438
    // 0x8007D42C: sh          $t4, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r12;
        goto L_8007D438;
    // 0x8007D42C: sh          $t4, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r12;
L_8007D430:
    // 0x8007D430: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007D434: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8007D438:
    // 0x8007D438: b           L_8007D4B0
    // 0x8007D43C: nop

        goto L_8007D4B0;
    // 0x8007D43C: nop

L_8007D440:
    // 0x8007D440: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007D444: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007D448: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007D44C: lh          $t0, 0x11E($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X11E);
    // 0x8007D450: addiu       $t3, $t3, 0x7190
    ctx->r11 = ADD32(ctx->r11, 0X7190);
    // 0x8007D454: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8007D458: lwc1        $f16, 0x4C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X4C);
    // 0x8007D45C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007D460: c.le.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl <= ctx->f16.fl;
    // 0x8007D464: nop

    // 0x8007D468: bc1f        L_8007D4A8
    if (!c1cs) {
        // 0x8007D46C: nop
    
            goto L_8007D4A8;
    }
    // 0x8007D46C: nop

    // 0x8007D470: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8007D474: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007D478: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8007D47C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007D480: addiu       $t6, $t6, 0x7190
    ctx->r14 = ADD32(ctx->r14, 0X7190);
    // 0x8007D484: lwc1        $f8, 0x4C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4C);
    // 0x8007D488: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007D48C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007D490: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007D494: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007D498: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8007D49C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8007D4A0: b           L_8007D4B0
    // 0x8007D4A4: sh          $t7, 0x11E($t9)
    MEM_H(0X11E, ctx->r25) = ctx->r15;
        goto L_8007D4B0;
    // 0x8007D4A4: sh          $t7, 0x11E($t9)
    MEM_H(0X11E, ctx->r25) = ctx->r15;
L_8007D4A8:
    // 0x8007D4A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007D4AC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8007D4B0:
    // 0x8007D4B0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D4B4: nop

    // 0x8007D4B8: bne         $t1, $zero, L_8007D4F8
    if (ctx->r9 != 0) {
        // 0x8007D4BC: nop
    
            goto L_8007D4F8;
    }
    // 0x8007D4BC: nop

    // 0x8007D4C0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007D4C4: lw          $t2, 0x7190($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7190);
    // 0x8007D4C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007D4CC: bne         $t2, $at, L_8007D4F0
    if (ctx->r10 != ctx->r1) {
        // 0x8007D4D0: nop
    
            goto L_8007D4F0;
    }
    // 0x8007D4D0: nop

    // 0x8007D4D4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8007D4D8: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8007D4DC: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8007D4E0: lw          $t0, 0xC0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC0);
    // 0x8007D4E4: nop

    // 0x8007D4E8: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8007D4EC: sw          $t3, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r11;
L_8007D4F0:
    // 0x8007D4F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007D4F4: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
L_8007D4F8:
    // 0x8007D4F8: b           L_8007D500
    // 0x8007D4FC: nop

        goto L_8007D500;
    // 0x8007D4FC: nop

L_8007D500:
    // 0x8007D500: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D504: nop

    // 0x8007D508: beq         $t6, $zero, L_8007D518
    if (ctx->r14 == 0) {
        // 0x8007D50C: nop
    
            goto L_8007D518;
    }
    // 0x8007D50C: nop

    // 0x8007D510: b           L_8007D528
    // 0x8007D514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007D528;
    // 0x8007D514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007D518:
    // 0x8007D518: b           L_8007D528
    // 0x8007D51C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007D528;
    // 0x8007D51C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007D520: b           L_8007D528
    // 0x8007D524: nop

        goto L_8007D528;
    // 0x8007D524: nop

L_8007D528:
    // 0x8007D528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D52C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007D530: jr          $ra
    // 0x8007D534: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007D534: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
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
RECOMP_FUNC void func_80085F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80085F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085F28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80085F2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085F30: jal         0x8008B4EC
    // 0x80085F34: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80085F34: nop

    after_0:
    // 0x80085F38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085F3C: jal         0x8008B600
    // 0x80085F40: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80085F40: nop

    after_1:
    // 0x80085F44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085F4C: jal         0x8008B738
    // 0x80085F50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80085F50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80085F54: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80085F58: jal         0x8008A518
    // 0x80085F5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x80085F5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80085F60: beq         $v0, $zero, L_80085FF8
    if (ctx->r2 == 0) {
        // 0x80085F64: nop
    
            goto L_80085FF8;
    }
    // 0x80085F64: nop

    // 0x80085F68: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80085F6C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80085F70: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085F74: bne         $at, $zero, L_80085FF8
    if (ctx->r1 != 0) {
        // 0x80085F78: nop
    
            goto L_80085FF8;
    }
    // 0x80085F78: nop

    // 0x80085F7C: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80085F80: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085F84: beq         $at, $zero, L_80085FF8
    if (ctx->r1 == 0) {
        // 0x80085F88: nop
    
            goto L_80085FF8;
    }
    // 0x80085F88: nop

    // 0x80085F8C: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80085F90: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80085F94: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80085F98: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80085F9C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085FA0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80085FA4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80085FA8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80085FAC: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80085FB0: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80085FB4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80085FB8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80085FBC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80085FC0: nop

    // 0x80085FC4: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80085FC8: nop

    // 0x80085FCC: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80085FD0: beq         $t4, $zero, L_80085FF8
    if (ctx->r12 == 0) {
        // 0x80085FD4: nop
    
            goto L_80085FF8;
    }
    // 0x80085FD4: nop

    // 0x80085FD8: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x80085FDC: beq         $t5, $zero, L_80085FF8
    if (ctx->r13 == 0) {
        // 0x80085FE0: nop
    
            goto L_80085FF8;
    }
    // 0x80085FE0: nop

    // 0x80085FE4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80085FE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085FEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085FF0: jal         0x8008B738
    // 0x80085FF4: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80085FF4: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    after_4:
L_80085FF8:
    // 0x80085FF8: b           L_80086000
    // 0x80085FFC: nop

        goto L_80086000;
    // 0x80085FFC: nop

L_80086000:
    // 0x80086000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086008: jr          $ra
    // 0x8008600C: nop

    return;
    // 0x8008600C: nop

;}
RECOMP_FUNC void func_80098820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098820: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098824: sw          $zero, 0x72CC($at)
    MEM_W(0X72CC, ctx->r1) = 0;
    // 0x80098828: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009882C: sw          $zero, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = 0;
    // 0x80098830: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80098834: sw          $zero, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = 0;
    // 0x80098838: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009883C: sw          $zero, 0x40D0($at)
    MEM_W(0X40D0, ctx->r1) = 0;
    // 0x80098840: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098844: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098848: addiu       $at, $zero, -0x19
    ctx->r1 = ADD32(0, -0X19);
    // 0x8009884C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80098850: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098854: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098858: jr          $ra
    // 0x8009885C: nop

    return;
    // 0x8009885C: nop

    // 0x80098860: jr          $ra
    // 0x80098864: nop

    return;
    // 0x80098864: nop

;}
RECOMP_FUNC void func_80077C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077C78: jal         0x80061348
    // 0x80077C7C: addiu       $a0, $zero, 0x558
    ctx->r4 = ADD32(0, 0X558);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80077C7C: addiu       $a0, $zero, 0x558
    ctx->r4 = ADD32(0, 0X558);
    after_0:
    // 0x80077C80: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077C84: b           L_80077C94
    // 0x80077C88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077C94;
    // 0x80077C88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077C8C: b           L_80077C94
    // 0x80077C90: nop

        goto L_80077C94;
    // 0x80077C90: nop

L_80077C94:
    // 0x80077C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077C9C: jr          $ra
    // 0x80077CA0: nop

    return;
    // 0x80077CA0: nop

;}
RECOMP_FUNC void func_80073158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073158: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007315C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073160: nop

    // 0x80073164: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073168: nop

    // 0x8007316C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073170: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073174: jr          $ra
    // 0x80073178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007317C: jr          $ra
    // 0x80073180: nop

    return;
    // 0x80073180: nop

    // 0x80073184: jr          $ra
    // 0x80073188: nop

    return;
    // 0x80073188: nop

;}
RECOMP_FUNC void func_800B80A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B80A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B80A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B80AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B80B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B80B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B80B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B80BC: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    // 0x800B80C0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800B80C4: jal         0x8000D934
    // 0x800B80C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_8000D934(rdram, ctx);
        goto after_0;
    // 0x800B80C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_0:
    // 0x800B80CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B80D0: bne         $v0, $at, L_800B80E0
    if (ctx->r2 != ctx->r1) {
        // 0x800B80D4: nop
    
            goto L_800B80E0;
    }
    // 0x800B80D4: nop

    // 0x800B80D8: b           L_800B80F4
    // 0x800B80DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B80F4;
    // 0x800B80DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B80E0:
    // 0x800B80E0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B80E4: b           L_800B80F4
    // 0x800B80E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800B80F4;
    // 0x800B80E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B80EC: b           L_800B80F4
    // 0x800B80F0: nop

        goto L_800B80F4;
    // 0x800B80F0: nop

L_800B80F4:
    // 0x800B80F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B80F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B80FC: jr          $ra
    // 0x800B8100: nop

    return;
    // 0x800B8100: nop

;}
RECOMP_FUNC void func_800663FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066404: jal         0x80061348
    // 0x80066408: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066408: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x8006640C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066410: b           L_80066420
    // 0x80066414: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066420;
    // 0x80066414: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066418: b           L_80066420
    // 0x8006641C: nop

        goto L_80066420;
    // 0x8006641C: nop

L_80066420:
    // 0x80066420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066428: jr          $ra
    // 0x8006642C: nop

    return;
    // 0x8006642C: nop

;}
RECOMP_FUNC void alSavePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1DC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D1DC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D1DCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D1DD0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800D1DD4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800D1DD8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D1DDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800D1DE0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800D1DE4: jalr        $t9
    // 0x800D1DE8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D1DE8: nop

    after_0:
    // 0x800D1DEC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800D1DF0: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800D1DF4: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x800D1DF8: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800D1DFC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800D1E00: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800D1E04: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x800D1E08: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x800D1E0C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800D1E10: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800D1E14: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800D1E18: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800D1E1C: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800D1E20: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800D1E24: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800D1E28: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800D1E2C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800D1E30: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D1E34: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800D1E38: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800D1E3C: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800D1E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1E44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D1E48: jr          $ra
    // 0x800D1E4C: nop

    return;
    // 0x800D1E4C: nop

;}
RECOMP_FUNC void func_80047808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047808: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8004780C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80047810: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80047814: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80047818: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004781C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80047820: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80047824: jal         0x800AF060
    // 0x80047828: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x80047828: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x8004782C: jal         0x800A41B4
    // 0x80047830: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    func_800A41B4(rdram, ctx);
        goto after_1;
    // 0x80047830: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x80047834: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80047838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004783C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80047840: swc1        $f4, 0x450($at)
    MEM_W(0X450, ctx->r1) = ctx->f4.u32l;
    // 0x80047844: jal         0x800BC6EC
    // 0x80047848: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80047848: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_2:
    // 0x8004784C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80047850: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80047854: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047858: sw          $t6, 0x7214($at)
    MEM_W(0X7214, ctx->r1) = ctx->r14;
    // 0x8004785C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80047860: nop

    // 0x80047864: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80047868: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8004786C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80047870: sb          $t8, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r24;
    // 0x80047874: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80047878: nop

    // 0x8004787C: lbu         $t1, 0x4($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4);
    // 0x80047880: nop

    // 0x80047884: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x80047888: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8004788C: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80047890: sb          $t2, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r10;
    // 0x80047894: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80047898: nop

    // 0x8004789C: lbu         $t5, 0x5($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X5);
    // 0x800478A0: nop

    // 0x800478A4: sb          $t5, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r13;
    // 0x800478A8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800478AC: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x800478B0: sb          $t6, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r14;
    // 0x800478B4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800478B8: nop

    // 0x800478BC: lbu         $t9, 0x6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X6);
    // 0x800478C0: nop

    // 0x800478C4: sb          $t9, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r25;
    // 0x800478C8: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800478CC: nop

    // 0x800478D0: sb          $zero, 0x7($t1)
    MEM_B(0X7, ctx->r9) = 0;
    // 0x800478D4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800478D8: nop

    // 0x800478DC: lbu         $t2, 0x7($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X7);
    // 0x800478E0: nop

    // 0x800478E4: sb          $t2, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r10;
    // 0x800478E8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800478EC: nop

    // 0x800478F0: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800478F4: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x800478F8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800478FC: nop

    // 0x80047900: sb          $zero, 0x4($t4)
    MEM_B(0X4, ctx->r12) = 0;
    // 0x80047904: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80047908: nop

    // 0x8004790C: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x80047910: nop

    // 0x80047914: sb          $t7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r15;
    // 0x80047918: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8004791C: nop

    // 0x80047920: sb          $zero, 0x5($t9)
    MEM_B(0X5, ctx->r25) = 0;
    // 0x80047924: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80047928: nop

    // 0x8004792C: lbu         $t1, 0x5($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X5);
    // 0x80047930: nop

    // 0x80047934: sb          $t1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r9;
    // 0x80047938: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8004793C: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x80047940: sb          $t2, 0x6($t0)
    MEM_B(0X6, ctx->r8) = ctx->r10;
    // 0x80047944: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80047948: nop

    // 0x8004794C: lbu         $t5, 0x6($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X6);
    // 0x80047950: nop

    // 0x80047954: sb          $t5, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r13;
    // 0x80047958: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8004795C: addiu       $t4, $zero, 0x59
    ctx->r12 = ADD32(0, 0X59);
    // 0x80047960: sb          $t4, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r12;
    // 0x80047964: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80047968: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8004796C: sb          $t6, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r14;
    // 0x80047970: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80047974: nop

    // 0x80047978: sb          $zero, 0xA($t1)
    MEM_B(0XA, ctx->r9) = 0;
    // 0x8004797C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80047980: nop

    // 0x80047984: sb          $zero, 0xB($t8)
    MEM_B(0XB, ctx->r24) = 0;
    // 0x80047988: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8004798C: nop

    // 0x80047990: lbu         $s0, 0xB($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0XB);
    // 0x80047994: nop

    // 0x80047998: sb          $s0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r16;
    // 0x8004799C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800479A0: nop

    // 0x800479A4: sb          $s0, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r16;
    // 0x800479A8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800479AC: nop

    // 0x800479B0: addiu       $t3, $t5, 0x18
    ctx->r11 = ADD32(ctx->r13, 0X18);
    // 0x800479B4: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x800479B8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800479BC: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800479C0: sb          $t4, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r12;
    // 0x800479C4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800479C8: nop

    // 0x800479CC: lbu         $t9, 0x4($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X4);
    // 0x800479D0: nop

    // 0x800479D4: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800479D8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800479DC: nop

    // 0x800479E0: sb          $zero, 0x5($t1)
    MEM_B(0X5, ctx->r9) = 0;
    // 0x800479E4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800479E8: nop

    // 0x800479EC: lbu         $t2, 0x5($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X5);
    // 0x800479F0: nop

    // 0x800479F4: sb          $t2, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r10;
    // 0x800479F8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800479FC: nop

    // 0x80047A00: sb          $zero, 0x6($t0)
    MEM_B(0X6, ctx->r8) = 0;
    // 0x80047A04: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80047A08: nop

    // 0x80047A0C: lbu         $t3, 0x6($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X6);
    // 0x80047A10: nop

    // 0x80047A14: sb          $t3, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r11;
    // 0x80047A18: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80047A1C: nop

    // 0x80047A20: sb          $zero, 0x8($t4)
    MEM_B(0X8, ctx->r12) = 0;
    // 0x80047A24: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80047A28: nop

    // 0x80047A2C: sb          $zero, 0x9($t7)
    MEM_B(0X9, ctx->r15) = 0;
    // 0x80047A30: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80047A34: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80047A38: sb          $t9, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r25;
    // 0x80047A3C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80047A40: nop

    // 0x80047A44: sb          $zero, 0xB($t1)
    MEM_B(0XB, ctx->r9) = 0;
    // 0x80047A48: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80047A4C: nop

    // 0x80047A50: lbu         $s0, 0xB($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0XB);
    // 0x80047A54: nop

    // 0x80047A58: sb          $s0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r16;
    // 0x80047A5C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80047A60: nop

    // 0x80047A64: sb          $s0, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r16;
    // 0x80047A68: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80047A6C: jal         0x800A5624
    // 0x80047A70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_3;
    // 0x80047A70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80047A74: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    // 0x80047A78: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x80047A7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80047A80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80047A84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80047A88: jal         0x800A57C4
    // 0x80047A8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800A57C4(rdram, ctx);
        goto after_4;
    // 0x80047A8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x80047A90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80047A94: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80047A98: sw          $t0, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r8;
    // 0x80047A9C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80047AA0: sh          $t3, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r11;
    // 0x80047AA4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80047AA8: lh          $t5, 0x7268($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7268);
    // 0x80047AAC: nop

    // 0x80047AB0: andi        $t4, $t5, 0x7FFF
    ctx->r12 = ctx->r13 & 0X7FFF;
    // 0x80047AB4: bne         $t4, $zero, L_80047AD0
    if (ctx->r12 != 0) {
        // 0x80047AB8: nop
    
            goto L_80047AD0;
    }
    // 0x80047AB8: nop

    // 0x80047ABC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80047AC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047AC4: sh          $t7, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r15;
    // 0x80047AC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047ACC: sb          $zero, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = 0;
L_80047AD0:
    // 0x80047AD0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80047AD4: lh          $t9, 0x7268($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7268);
    // 0x80047AD8: nop

    // 0x80047ADC: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80047AE0: andi        $t1, $t6, 0x7FFF
    ctx->r9 = ctx->r14 & 0X7FFF;
    // 0x80047AE4: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x80047AE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047AEC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80047AF0: addiu       $t2, $t2, 0x7158
    ctx->r10 = ADD32(ctx->r10, 0X7158);
    // 0x80047AF4: swc1        $f6, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f6.u32l;
    // 0x80047AF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047AFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80047B00: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80047B04: addiu       $t8, $t8, 0x7158
    ctx->r24 = ADD32(ctx->r24, 0X7158);
    // 0x80047B08: swc1        $f8, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f8.u32l;
    // 0x80047B0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047B10: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80047B14: addiu       $t0, $t0, 0x7158
    ctx->r8 = ADD32(ctx->r8, 0X7158);
    // 0x80047B18: swc1        $f10, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f10.u32l;
    // 0x80047B1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047B20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80047B24: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80047B28: addiu       $t3, $t3, 0x7158
    ctx->r11 = ADD32(ctx->r11, 0X7158);
    // 0x80047B2C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80047B30: addiu       $t5, $t5, 0x7158
    ctx->r13 = ADD32(ctx->r13, 0X7158);
    // 0x80047B34: swc1        $f16, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f16.u32l;
    // 0x80047B38: lwc1        $f20, 0x20($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0X20);
    // 0x80047B3C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80047B40: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x80047B44: swc1        $f20, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f20.u32l;
    // 0x80047B48: swc1        $f20, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f20.u32l;
    // 0x80047B4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80047B50: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80047B54: jal         0x800C4240
    // 0x80047B58: nop

    guRandom(rdram, ctx);
        goto after_5;
    // 0x80047B58: nop

    after_5:
    // 0x80047B5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80047B60: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80047B64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80047B68: mfhi        $t7
    ctx->r15 = hi;
    // 0x80047B6C: addiu       $t9, $t7, 0x5
    ctx->r25 = ADD32(ctx->r15, 0X5);
    // 0x80047B70: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80047B74: nop

    // 0x80047B78: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80047B7C: swc1        $f4, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f4.u32l;
    // 0x80047B80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047B84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80047B88: swc1        $f6, 0xE6C($at)
    MEM_W(0XE6C, ctx->r1) = ctx->f6.u32l;
    // 0x80047B8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047B90: sh          $zero, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = 0;
    // 0x80047B94: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80047B98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80047B9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BA0: swc1        $f8, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f8.u32l;
    // 0x80047BA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047BA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BAC: swc1        $f10, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f10.u32l;
    // 0x80047BB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BB4: swc1        $f10, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f10.u32l;
    // 0x80047BB8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80047BBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BC0: swc1        $f16, 0x733C($at)
    MEM_W(0X733C, ctx->r1) = ctx->f16.u32l;
    // 0x80047BC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BC8: swc1        $f16, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = ctx->f16.u32l;
    // 0x80047BCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047BD0: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
    // 0x80047BD4: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80047BD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80047BDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047BE0: swc1        $f18, -0x73E0($at)
    MEM_W(-0X73E0, ctx->r1) = ctx->f18.u32l;
    // 0x80047BE4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80047BE8: lbu         $t6, 0x7256($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7256);
    // 0x80047BEC: nop

    // 0x80047BF0: bne         $t6, $zero, L_80047DBC
    if (ctx->r14 != 0) {
        // 0x80047BF4: nop
    
            goto L_80047DBC;
    }
    // 0x80047BF4: nop

    // 0x80047BF8: lhu         $t1, 0x72($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X72);
    // 0x80047BFC: nop

    // 0x80047C00: bne         $t1, $zero, L_80047C48
    if (ctx->r9 != 0) {
        // 0x80047C04: nop
    
            goto L_80047C48;
    }
    // 0x80047C04: nop

    // 0x80047C08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047C0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047C10: swc1        $f4, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f4.u32l;
    // 0x80047C14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80047C18: lwc1        $f6, -0x1130($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1130);
    // 0x80047C1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047C20: swc1        $f6, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f6.u32l;
    // 0x80047C24: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80047C28: lwc1        $f8, -0x112C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X112C);
    // 0x80047C2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047C30: swc1        $f8, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f8.u32l;
    // 0x80047C34: jal         0x800BC918
    // 0x80047C38: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_6;
    // 0x80047C38: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_6:
    // 0x80047C3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047C40: b           L_80047DB4
    // 0x80047C44: sw          $v0, 0x7260($at)
    MEM_W(0X7260, ctx->r1) = ctx->r2;
        goto L_80047DB4;
    // 0x80047C44: sw          $v0, 0x7260($at)
    MEM_W(0X7260, ctx->r1) = ctx->r2;
L_80047C48:
    // 0x80047C48: jal         0x800C4240
    // 0x80047C4C: nop

    guRandom(rdram, ctx);
        goto after_7;
    // 0x80047C4C: nop

    after_7:
    // 0x80047C50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80047C54: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80047C58: mfhi        $t2
    ctx->r10 = hi;
    // 0x80047C5C: andi        $t8, $t2, 0xFFFF
    ctx->r24 = ctx->r10 & 0XFFFF;
    // 0x80047C60: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
    // 0x80047C64: jal         0x800C4240
    // 0x80047C68: nop

    guRandom(rdram, ctx);
        goto after_8;
    // 0x80047C68: nop

    after_8:
    // 0x80047C6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80047C70: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80047C74: mfhi        $t0
    ctx->r8 = hi;
    // 0x80047C78: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x80047C7C: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x80047C80: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
    // 0x80047C84: lhu         $t4, 0x6E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6E);
    // 0x80047C88: nop

    // 0x80047C8C: bne         $t5, $t4, L_80047CEC
    if (ctx->r13 != ctx->r12) {
        // 0x80047C90: nop
    
            goto L_80047CEC;
    }
    // 0x80047C90: nop

    // 0x80047C94: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80047C98: nop

    // 0x80047C9C: bne         $t7, $zero, L_80047CEC
    if (ctx->r15 != 0) {
        // 0x80047CA0: nop
    
            goto L_80047CEC;
    }
    // 0x80047CA0: nop

    // 0x80047CA4: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80047CA8: nop

    // 0x80047CAC: bne         $t9, $zero, L_80047CEC
    if (ctx->r25 != 0) {
        // 0x80047CB0: nop
    
            goto L_80047CEC;
    }
    // 0x80047CB0: nop

    // 0x80047CB4: jal         0x800C4240
    // 0x80047CB8: nop

    guRandom(rdram, ctx);
        goto after_9;
    // 0x80047CB8: nop

    after_9:
    // 0x80047CBC: bgez        $v0, L_80047CD0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80047CC0: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80047CD0;
    }
    // 0x80047CC0: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80047CC4: beq         $t6, $zero, L_80047CD0
    if (ctx->r14 == 0) {
        // 0x80047CC8: nop
    
            goto L_80047CD0;
    }
    // 0x80047CC8: nop

    // 0x80047CCC: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_80047CD0:
    // 0x80047CD0: beq         $t6, $zero, L_80047CE4
    if (ctx->r14 == 0) {
        // 0x80047CD4: nop
    
            goto L_80047CE4;
    }
    // 0x80047CD4: nop

    // 0x80047CD8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80047CDC: b           L_80047CEC
    // 0x80047CE0: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
        goto L_80047CEC;
    // 0x80047CE0: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
L_80047CE4:
    // 0x80047CE4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80047CE8: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
L_80047CEC:
    // 0x80047CEC: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x80047CF0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047CF4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80047CF8: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80047CFC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80047D00: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80047D04: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80047D08: addiu       $t3, $t0, 0x46
    ctx->r11 = ADD32(ctx->r8, 0X46);
    // 0x80047D0C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80047D10: nop

    // 0x80047D14: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047D18: swc1        $f16, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f16.u32l;
    // 0x80047D1C: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80047D20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047D24: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80047D28: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x80047D2C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80047D30: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80047D34: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80047D38: addiu       $t7, $t4, 0x46
    ctx->r15 = ADD32(ctx->r12, 0X46);
    // 0x80047D3C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80047D40: nop

    // 0x80047D44: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80047D48: swc1        $f4, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f4.u32l;
    // 0x80047D4C: jal         0x800C4240
    // 0x80047D50: nop

    guRandom(rdram, ctx);
        goto after_10;
    // 0x80047D50: nop

    after_10:
    // 0x80047D54: bgez        $v0, L_80047D68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80047D58: andi        $t9, $v0, 0x3
        ctx->r25 = ctx->r2 & 0X3;
            goto L_80047D68;
    }
    // 0x80047D58: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x80047D5C: beq         $t9, $zero, L_80047D68
    if (ctx->r25 == 0) {
        // 0x80047D60: nop
    
            goto L_80047D68;
    }
    // 0x80047D60: nop

    // 0x80047D64: addiu       $t9, $t9, -0x4
    ctx->r25 = ADD32(ctx->r25, -0X4);
L_80047D68:
    // 0x80047D68: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80047D6C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80047D70: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x80047D74: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80047D78: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x80047D7C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80047D80: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x80047D84: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80047D88: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80047D8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047D90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80047D94: swc1        $f8, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f8.u32l;
    // 0x80047D98: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80047D9C: lw          $t8, 0x7260($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7260);
    // 0x80047DA0: addiu       $t2, $zero, 0x168
    ctx->r10 = ADD32(0, 0X168);
    // 0x80047DA4: sh          $t2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r10;
    // 0x80047DA8: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x80047DAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80047DB0: sh          $t0, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r8;
L_80047DB4:
    // 0x80047DB4: b           L_80047E84
    // 0x80047DB8: nop

        goto L_80047E84;
    // 0x80047DB8: nop

L_80047DBC:
    // 0x80047DBC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80047DC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047DC4: lwc1        $f10, -0x73EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80047DC8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80047DCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80047DD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047DD4: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80047DD8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80047DDC: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80047DE0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80047DE4: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80047DE8: sra         $t7, $t4, 16
    ctx->r15 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80047DEC: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80047DF0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047DF4: mflo        $t9
    ctx->r25 = lo;
    // 0x80047DF8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80047DFC: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80047E00: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80047E04: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80047E08: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80047E0C: addiu       $t1, $t6, 0x46
    ctx->r9 = ADD32(ctx->r14, 0X46);
    // 0x80047E10: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80047E14: nop

    // 0x80047E18: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80047E1C: swc1        $f4, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f4.u32l;
    // 0x80047E20: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80047E24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047E28: lwc1        $f6, -0x73D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80047E2C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80047E30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80047E34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047E38: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80047E3C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80047E40: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80047E44: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80047E48: sll         $t0, $t8, 16
    ctx->r8 = S32(ctx->r24 << 16);
    // 0x80047E4C: sra         $t3, $t0, 16
    ctx->r11 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80047E50: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80047E54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80047E58: mflo        $t5
    ctx->r13 = lo;
    // 0x80047E5C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80047E60: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x80047E64: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80047E68: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80047E6C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80047E70: addiu       $t7, $t4, 0x46
    ctx->r15 = ADD32(ctx->r12, 0X46);
    // 0x80047E74: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80047E78: nop

    // 0x80047E7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047E80: swc1        $f16, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f16.u32l;
L_80047E84:
    // 0x80047E84: jal         0x800BC6EC
    // 0x80047E88: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x80047E88: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_11:
    // 0x80047E8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047E90: sw          $v0, 0x71FC($at)
    MEM_W(0X71FC, ctx->r1) = ctx->r2;
    // 0x80047E94: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80047E98: lw          $t9, 0x7260($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7260);
    // 0x80047E9C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80047EA0: lw          $t1, 0x71FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X71FC);
    // 0x80047EA4: addiu       $t6, $t9, 0x2
    ctx->r14 = ADD32(ctx->r25, 0X2);
    // 0x80047EA8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80047EAC: jal         0x800BC6EC
    // 0x80047EB0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_12;
    // 0x80047EB0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_12:
    // 0x80047EB4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80047EB8: lhu         $t2, 0x72($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X72);
    // 0x80047EBC: nop

    // 0x80047EC0: bne         $t2, $zero, L_80047EE4
    if (ctx->r10 != 0) {
        // 0x80047EC4: nop
    
            goto L_80047EE4;
    }
    // 0x80047EC4: nop

    // 0x80047EC8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047ECC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80047ED0: addiu       $a0, $a0, -0x2C10
    ctx->r4 = ADD32(ctx->r4, -0X2C10);
    // 0x80047ED4: jal         0x800BD218
    // 0x80047ED8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_13;
    // 0x80047ED8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_13:
    // 0x80047EDC: b           L_80047EF8
    // 0x80047EE0: nop

        goto L_80047EF8;
    // 0x80047EE0: nop

L_80047EE4:
    // 0x80047EE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80047EE8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80047EEC: addiu       $a0, $a0, -0x2C00
    ctx->r4 = ADD32(ctx->r4, -0X2C00);
    // 0x80047EF0: jal         0x800BD218
    // 0x80047EF4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_14;
    // 0x80047EF4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_14:
L_80047EF8:
    // 0x80047EF8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80047EFC: lw          $t8, 0x71FC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X71FC);
    // 0x80047F00: nop

    // 0x80047F04: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80047F08: nop

    // 0x80047F0C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x80047F10: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_80047F14:
    // 0x80047F14: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
L_80047F18:
    // 0x80047F18: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80047F1C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80047F20: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80047F24: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80047F28: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80047F2C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80047F30: lbu         $t1, 0x0($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X0);
    // 0x80047F34: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80047F38: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80047F3C: lbu         $t2, -0x2C20($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2C20);
    // 0x80047F40: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80047F44: nop

    // 0x80047F48: sb          $t2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r10;
    // 0x80047F4C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80047F50: nop

    // 0x80047F54: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80047F58: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x80047F5C: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80047F60: nop

    // 0x80047F64: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80047F68: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80047F6C: bne         $at, $zero, L_80047F18
    if (ctx->r1 != 0) {
        // 0x80047F70: sw          $t4, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r12;
            goto L_80047F18;
    }
    // 0x80047F70: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x80047F74: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80047F78: nop

    // 0x80047F7C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80047F80: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80047F84: bne         $at, $zero, L_80047F14
    if (ctx->r1 != 0) {
        // 0x80047F88: sw          $t9, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r25;
            goto L_80047F14;
    }
    // 0x80047F88: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x80047F8C: lhu         $t6, 0x72($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X72);
    // 0x80047F90: nop

    // 0x80047F94: bne         $t6, $zero, L_80047FB4
    if (ctx->r14 != 0) {
        // 0x80047F98: nop
    
            goto L_80047FB4;
    }
    // 0x80047F98: nop

    // 0x80047F9C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80047FA0: lw          $t2, 0x71FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71FC);
    // 0x80047FA4: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
    // 0x80047FA8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80047FAC: b           L_80047FCC
    // 0x80047FB0: sb          $t1, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r9;
        goto L_80047FCC;
    // 0x80047FB0: sb          $t1, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r9;
L_80047FB4:
    // 0x80047FB4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80047FB8: lw          $t3, 0x71FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X71FC);
    // 0x80047FBC: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x80047FC0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80047FC4: nop

    // 0x80047FC8: sb          $t0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r8;
L_80047FCC:
    // 0x80047FCC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80047FD0: jal         0x800BC980
    // 0x80047FD4: nop

    SysMem_Free(rdram, ctx);
        goto after_15;
    // 0x80047FD4: nop

    after_15:
    // 0x80047FD8: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x80047FDC: lw          $a3, 0x71FC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X71FC);
    // 0x80047FE0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80047FE4: addiu       $a2, $a2, -0x3BE0
    ctx->r6 = ADD32(ctx->r6, -0X3BE0);
    // 0x80047FE8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80047FEC: jal         0x80043F14
    // 0x80047FF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80043F14(rdram, ctx);
        goto after_16;
    // 0x80047FF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80047FF4: lhu         $t4, 0x72($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X72);
    // 0x80047FF8: lhu         $t7, 0x6E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X6E);
    // 0x80047FFC: nop

    // 0x80048000: bne         $t4, $t7, L_8004806C
    if (ctx->r12 != ctx->r15) {
        // 0x80048004: nop
    
            goto L_8004806C;
    }
    // 0x80048004: nop

    // 0x80048008: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004800C: lbu         $t9, 0x7256($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7256);
    // 0x80048010: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80048014: bne         $t9, $at, L_80048048
    if (ctx->r25 != ctx->r1) {
        // 0x80048018: nop
    
            goto L_80048048;
    }
    // 0x80048018: nop

    // 0x8004801C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80048020: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80048024: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80048028: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004802C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80048030: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80048034: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80048038: jal         0x80044248
    // 0x8004803C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_80044248(rdram, ctx);
        goto after_17;
    // 0x8004803C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_17:
    // 0x80048040: b           L_8004806C
    // 0x80048044: nop

        goto L_8004806C;
    // 0x80048044: nop

L_80048048:
    // 0x80048048: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8004804C: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80048050: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80048054: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80048058: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8004805C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80048060: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80048064: jal         0x80044248
    // 0x80048068: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_80044248(rdram, ctx);
        goto after_18;
    // 0x80048068: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_18:
L_8004806C:
    // 0x8004806C: lui         $a0, 0x80A4
    ctx->r4 = S32(0X80A4 << 16);
    // 0x80048070: jal         0x800AF92C
    // 0x80048074: addiu       $a0, $a0, -0x40D0
    ctx->r4 = ADD32(ctx->r4, -0X40D0);
    func_800AF92C(rdram, ctx);
        goto after_19;
    // 0x80048074: addiu       $a0, $a0, -0x40D0
    ctx->r4 = ADD32(ctx->r4, -0X40D0);
    after_19:
    // 0x80048078: lui         $a0, 0x80A3
    ctx->r4 = S32(0X80A3 << 16);
    // 0x8004807C: jal         0x800AF72C
    // 0x80048080: addiu       $a0, $a0, 0x7648
    ctx->r4 = ADD32(ctx->r4, 0X7648);
    func_800AF72C(rdram, ctx);
        goto after_20;
    // 0x80048080: addiu       $a0, $a0, 0x7648
    ctx->r4 = ADD32(ctx->r4, 0X7648);
    after_20:
    // 0x80048084: jal         0x800BC6EC
    // 0x80048088: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_21;
    // 0x80048088: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_21:
    // 0x8004808C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80048090: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80048094: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80048098: sw          $t3, -0x73B8($at)
    MEM_W(-0X73B8, ctx->r1) = ctx->r11;
    // 0x8004809C: jal         0x800BC6EC
    // 0x800480A0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_22;
    // 0x800480A0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_22:
    // 0x800480A4: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x800480A8: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800480AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800480B0: sw          $t0, -0x73B4($at)
    MEM_W(-0X73B4, ctx->r1) = ctx->r8;
    // 0x800480B4: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x800480B8: jal         0x80099E2C
    // 0x800480BC: nop

    func_80099E2C(rdram, ctx);
        goto after_23;
    // 0x800480BC: nop

    after_23:
    // 0x800480C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800480C4: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x800480C8: nop

    // 0x800480CC: swc1        $f18, 0xD4($t5)
    MEM_W(0XD4, ctx->r13) = ctx->f18.u32l;
    // 0x800480D0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800480D4: lui         $t4, 0x4
    ctx->r12 = S32(0X4 << 16);
    // 0x800480D8: ori         $t4, $t4, 0x8004
    ctx->r12 = ctx->r12 | 0X8004;
    // 0x800480DC: sw          $t4, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r12;
    // 0x800480E0: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x800480E4: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x800480E8: sh          $t9, 0x11E($t6)
    MEM_H(0X11E, ctx->r14) = ctx->r25;
    // 0x800480EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800480F0: lwc1        $f4, -0x1128($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1128);
    // 0x800480F4: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x800480F8: nop

    // 0x800480FC: swc1        $f4, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->f4.u32l;
    // 0x80048100: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80048104: nop

    // 0x80048108: sw          $zero, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = 0;
    // 0x8004810C: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80048110: nop

    // 0x80048114: sw          $zero, 0x140($t8)
    MEM_W(0X140, ctx->r24) = 0;
    // 0x80048118: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8004811C: nop

    // 0x80048120: lw          $t0, 0x140($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X140);
    // 0x80048124: nop

    // 0x80048128: sw          $t0, 0x13C($t3)
    MEM_W(0X13C, ctx->r11) = ctx->r8;
    // 0x8004812C: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80048130: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80048134: sh          $t5, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r13;
    // 0x80048138: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x8004813C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80048140: jal         0x800B1B04
    // 0x80048144: nop

    func_800B1B04(rdram, ctx);
        goto after_24;
    // 0x80048144: nop

    after_24:
    // 0x80048148: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004814C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048150: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80048154: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80048158: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8004815C: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x80048160: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80048164: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80048168: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004816C: jal         0x800B1F0C
    // 0x80048170: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_25;
    // 0x80048170: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_25:
    // 0x80048174: addiu       $t7, $zero, 0x27
    ctx->r15 = ADD32(0, 0X27);
    // 0x80048178: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004817C: sh          $t7, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r15;
    // 0x80048180: jal         0x800BC6EC
    // 0x80048184: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_26;
    // 0x80048184: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_26:
    // 0x80048188: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004818C: sw          $v0, 0x722C($at)
    MEM_W(0X722C, ctx->r1) = ctx->r2;
    // 0x80048190: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80048194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80048198: jal         0x800AFB70
    // 0x8004819C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_27;
    // 0x8004819C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x800481A0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800481A4: lw          $t9, 0x722C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X722C);
    // 0x800481A8: nop

    // 0x800481AC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x800481B0: jal         0x800BC6EC
    // 0x800481B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_28;
    // 0x800481B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_28:
    // 0x800481B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800481BC: sw          $v0, 0x7220($at)
    MEM_W(0X7220, ctx->r1) = ctx->r2;
    // 0x800481C0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800481C4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800481C8: lw          $t6, 0x7220($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7220);
    // 0x800481CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800481D0: nop

    // 0x800481D4: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x800481D8: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x800481DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800481E0: lw          $t2, 0x7220($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7220);
    // 0x800481E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800481E8: nop

    // 0x800481EC: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
    // 0x800481F0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800481F4: lw          $t1, 0x7220($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7220);
    // 0x800481F8: nop

    // 0x800481FC: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x80048200: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80048204: lw          $t8, 0x7220($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7220);
    // 0x80048208: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004820C: nop

    // 0x80048210: swc1        $f18, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f18.u32l;
    // 0x80048214: lhu         $t0, 0x72($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X72);
    // 0x80048218: lhu         $t3, 0x6E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6E);
    // 0x8004821C: nop

    // 0x80048220: bne         $t0, $t3, L_80048250
    if (ctx->r8 != ctx->r11) {
        // 0x80048224: nop
    
            goto L_80048250;
    }
    // 0x80048224: nop

    // 0x80048228: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004822C: lw          $t5, 0x7260($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7260);
    // 0x80048230: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048234: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80048238: swc1        $f4, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f4.u32l;
    // 0x8004823C: lw          $t4, 0x7260($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7260);
    // 0x80048240: nop

    // 0x80048244: lwc1        $f6, 0x18($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X18);
    // 0x80048248: b           L_80048440
    // 0x8004824C: swc1        $f6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f6.u32l;
        goto L_80048440;
    // 0x8004824C: swc1        $f6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f6.u32l;
L_80048250:
    // 0x80048250: jal         0x800BC6EC
    // 0x80048254: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_29;
    // 0x80048254: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_29:
    // 0x80048258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004825C: sw          $v0, 0x726C($at)
    MEM_W(0X726C, ctx->r1) = ctx->r2;
    // 0x80048260: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80048264: lbu         $t7, 0x7256($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7256);
    // 0x80048268: nop

    // 0x8004826C: bne         $t7, $zero, L_8004834C
    if (ctx->r15 != 0) {
        // 0x80048270: nop
    
            goto L_8004834C;
    }
    // 0x80048270: nop

    // 0x80048274: jal         0x800C4240
    // 0x80048278: nop

    guRandom(rdram, ctx);
        goto after_30;
    // 0x80048278: nop

    after_30:
    // 0x8004827C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048280: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80048284: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80048288: lw          $t8, 0x726C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X726C);
    // 0x8004828C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80048290: mfhi        $s1
    ctx->r17 = hi;
    // 0x80048294: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x80048298: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8004829C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800482A0: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800482A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800482A8: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x800482AC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800482B0: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800482B4: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x800482B8: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x800482BC: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800482C0: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800482C4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800482C8: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800482CC: sh          $s1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r17;
    // 0x800482D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800482D4: lw          $t0, 0x7260($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7260);
    // 0x800482D8: nop

    // 0x800482DC: swc1        $f10, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f10.u32l;
    // 0x800482E0: jal         0x800C4240
    // 0x800482E4: nop

    guRandom(rdram, ctx);
        goto after_31;
    // 0x800482E4: nop

    after_31:
    // 0x800482E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800482EC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800482F0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800482F4: lw          $t9, 0x726C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X726C);
    // 0x800482F8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800482FC: mfhi        $s1
    ctx->r17 = hi;
    // 0x80048300: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80048304: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80048308: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8004830C: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80048310: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80048314: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x80048318: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8004831C: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80048320: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x80048324: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x80048328: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x8004832C: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80048330: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80048334: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x80048338: sh          $s1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r17;
    // 0x8004833C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80048340: lw          $t6, 0x7260($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7260);
    // 0x80048344: b           L_800483BC
    // 0x80048348: swc1        $f18, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f18.u32l;
        goto L_800483BC;
    // 0x80048348: swc1        $f18, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f18.u32l;
L_8004834C:
    // 0x8004834C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80048350: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80048354: lw          $t2, 0x7260($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7260);
    // 0x80048358: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8004835C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048360: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048364: lwc1        $f4, 0x14($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80048368: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004836C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80048370: lw          $t0, 0x726C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X726C);
    // 0x80048374: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80048378: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8004837C: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80048380: nop

    // 0x80048384: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80048388: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004838C: lw          $t3, 0x7260($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7260);
    // 0x80048390: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80048394: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048398: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004839C: lwc1        $f8, 0x18($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X18);
    // 0x800483A0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800483A4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800483A8: lw          $t7, 0x726C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X726C);
    // 0x800483AC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800483B0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800483B4: sh          $t4, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r12;
    // 0x800483B8: nop

L_800483BC:
    // 0x800483BC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800483C0: lw          $t9, 0x726C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X726C);
    // 0x800483C4: nop

    // 0x800483C8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800483CC: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x800483D0: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x800483D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800483D8: jal         0x800AFB70
    // 0x800483DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_32;
    // 0x800483DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x800483E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800483E4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800483E8: jal         0x800A424C
    // 0x800483EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800A424C(rdram, ctx);
        goto after_33;
    // 0x800483EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_33:
    // 0x800483F0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800483F4: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800483F8: sh          $t2, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r10;
    // 0x800483FC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80048400: nop

    // 0x80048404: lw          $t0, 0xC0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC0);
    // 0x80048408: nop

    // 0x8004840C: ori         $t3, $t0, 0xA000
    ctx->r11 = ctx->r8 | 0XA000;
    // 0x80048410: sw          $t3, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r11;
    // 0x80048414: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80048418: nop

    // 0x8004841C: sh          $zero, 0xD0($t5)
    MEM_H(0XD0, ctx->r13) = 0;
    // 0x80048420: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80048424: nop

    // 0x80048428: lh          $s1, 0xD0($t4)
    ctx->r17 = MEM_H(ctx->r12, 0XD0);
    // 0x8004842C: nop

    // 0x80048430: sh          $s1, 0xCE($t4)
    MEM_H(0XCE, ctx->r12) = ctx->r17;
    // 0x80048434: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80048438: nop

    // 0x8004843C: sh          $s1, 0xCC($t7)
    MEM_H(0XCC, ctx->r15) = ctx->r17;
L_80048440:
    // 0x80048440: jal         0x800BC6EC
    // 0x80048444: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_34;
    // 0x80048444: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    after_34:
    // 0x80048448: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004844C: sw          $v0, 0x724C($at)
    MEM_W(0X724C, ctx->r1) = ctx->r2;
    // 0x80048450: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80048454: lw          $t9, 0x7260($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7260);
    // 0x80048458: nop

    // 0x8004845C: lwc1        $f16, 0x14($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80048460: nop

    // 0x80048464: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x80048468: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004846C: lw          $t6, 0x7260($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7260);
    // 0x80048470: nop

    // 0x80048474: lwc1        $f18, 0x18($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80048478: nop

    // 0x8004847C: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
L_80048480:
    // 0x80048480: jal         0x800C4240
    // 0x80048484: nop

    guRandom(rdram, ctx);
        goto after_35;
    // 0x80048484: nop

    after_35:
    // 0x80048488: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004848C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80048490: mfhi        $t2
    ctx->r10 = hi;
    // 0x80048494: andi        $t1, $t2, 0xFFFF
    ctx->r9 = ctx->r10 & 0XFFFF;
    // 0x80048498: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x8004849C: jal         0x800C4240
    // 0x800484A0: nop

    guRandom(rdram, ctx);
        goto after_36;
    // 0x800484A0: nop

    after_36:
    // 0x800484A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800484A8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800484AC: mfhi        $t0
    ctx->r8 = hi;
    // 0x800484B0: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800484B4: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x800484B8: lhu         $t8, 0x72($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X72);
    // 0x800484BC: lhu         $t5, 0x6E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6E);
    // 0x800484C0: nop

    // 0x800484C4: bne         $t8, $t5, L_80048524
    if (ctx->r24 != ctx->r13) {
        // 0x800484C8: nop
    
            goto L_80048524;
    }
    // 0x800484C8: nop

    // 0x800484CC: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x800484D0: nop

    // 0x800484D4: bne         $t4, $zero, L_80048524
    if (ctx->r12 != 0) {
        // 0x800484D8: nop
    
            goto L_80048524;
    }
    // 0x800484D8: nop

    // 0x800484DC: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800484E0: nop

    // 0x800484E4: bne         $t7, $zero, L_80048524
    if (ctx->r15 != 0) {
        // 0x800484E8: nop
    
            goto L_80048524;
    }
    // 0x800484E8: nop

    // 0x800484EC: jal         0x800C4240
    // 0x800484F0: nop

    guRandom(rdram, ctx);
        goto after_37;
    // 0x800484F0: nop

    after_37:
    // 0x800484F4: bgez        $v0, L_80048508
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800484F8: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_80048508;
    }
    // 0x800484F8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800484FC: beq         $t9, $zero, L_80048508
    if (ctx->r25 == 0) {
        // 0x80048500: nop
    
            goto L_80048508;
    }
    // 0x80048500: nop

    // 0x80048504: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_80048508:
    // 0x80048508: beq         $t9, $zero, L_8004851C
    if (ctx->r25 == 0) {
        // 0x8004850C: nop
    
            goto L_8004851C;
    }
    // 0x8004850C: nop

    // 0x80048510: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80048514: b           L_80048524
    // 0x80048518: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
        goto L_80048524;
    // 0x80048518: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
L_8004851C:
    // 0x8004851C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80048520: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
L_80048524:
    // 0x80048524: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x80048528: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8004852C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80048530: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x80048534: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80048538: addu        $t1, $t1, $s1
    ctx->r9 = ADD32(ctx->r9, ctx->r17);
    // 0x8004853C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80048540: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80048544: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x80048548: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x8004854C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80048550: sra         $t3, $s1, 16
    ctx->r11 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80048554: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80048558: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8004855C: lw          $t8, 0x724C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X724C);
    // 0x80048560: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80048564: sh          $s1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r17;
    // 0x80048568: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x8004856C: lw          $s1, 0x80($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X80);
    // 0x80048570: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80048574: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80048578: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x8004857C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80048580: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x80048584: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80048588: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8004858C: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x80048590: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x80048594: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x80048598: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004859C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800485A0: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800485A4: lw          $t9, 0x724C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X724C);
    // 0x800485A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800485AC: sh          $s1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r17;
    // 0x800485B0: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x800485B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800485B8: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x800485BC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800485C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800485C4: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800485C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800485CC: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800485D0: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800485D4: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x800485D8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800485DC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800485E0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800485E4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800485E8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800485EC: jal         0x800C3C80
    // 0x800485F0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_38;
    // 0x800485F0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_38:
    // 0x800485F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800485F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800485FC: nop

    // 0x80048600: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80048604: nop

    // 0x80048608: bc1f        L_80048480
    if (!c1cs) {
        // 0x8004860C: nop
    
            goto L_80048480;
    }
    // 0x8004860C: nop

    // 0x80048610: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80048614: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048618: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8004861C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80048620: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80048624: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80048628: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004862C: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80048630: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80048634: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80048638: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8004863C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80048640: jal         0x800C3C80
    // 0x80048644: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_39;
    // 0x80048644: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_39:
    // 0x80048648: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004864C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048650: nop

    // 0x80048654: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80048658: nop

    // 0x8004865C: bc1f        L_80048480
    if (!c1cs) {
        // 0x80048660: nop
    
            goto L_80048480;
    }
    // 0x80048660: nop

    // 0x80048664: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80048668: lbu         $t6, 0x7256($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7256);
    // 0x8004866C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80048670: bne         $t6, $at, L_8004868C
    if (ctx->r14 != ctx->r1) {
        // 0x80048674: nop
    
            goto L_8004868C;
    }
    // 0x80048674: nop

    // 0x80048678: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004867C: lw          $t1, 0x724C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X724C);
    // 0x80048680: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80048684: b           L_8004869C
    // 0x80048688: sb          $t2, 0x1A8($t1)
    MEM_B(0X1A8, ctx->r9) = ctx->r10;
        goto L_8004869C;
    // 0x80048688: sb          $t2, 0x1A8($t1)
    MEM_B(0X1A8, ctx->r9) = ctx->r10;
L_8004868C:
    // 0x8004868C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80048690: lw          $t0, 0x724C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X724C);
    // 0x80048694: nop

    // 0x80048698: sb          $zero, 0x1A8($t0)
    MEM_B(0X1A8, ctx->r8) = 0;
L_8004869C:
    // 0x8004869C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800486A0: lw          $t3, 0x724C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X724C);
    // 0x800486A4: nop

    // 0x800486A8: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x800486AC: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x800486B0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800486B4: lw          $t5, 0x724C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X724C);
    // 0x800486B8: nop

    // 0x800486BC: addiu       $t4, $t5, 0x168
    ctx->r12 = ADD32(ctx->r13, 0X168);
    // 0x800486C0: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x800486C4: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x800486C8: jal         0x80099E2C
    // 0x800486CC: nop

    func_80099E2C(rdram, ctx);
        goto after_40;
    // 0x800486CC: nop

    after_40:
    // 0x800486D0: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x800486D4: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x800486D8: jal         0x800B1B04
    // 0x800486DC: nop

    func_800B1B04(rdram, ctx);
        goto after_41;
    // 0x800486DC: nop

    after_41:
    // 0x800486E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800486E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800486E8: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x800486EC: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x800486F0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800486F4: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x800486F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800486FC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80048700: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80048704: jal         0x800B1F0C
    // 0x80048708: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_42;
    // 0x80048708: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_42:
    // 0x8004870C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80048710: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x80048714: ori         $t7, $t7, 0x2004
    ctx->r15 = ctx->r15 | 0X2004;
    // 0x80048718: sw          $t7, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r15;
    // 0x8004871C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80048720: lwc1        $f16, -0x1124($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1124);
    // 0x80048724: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80048728: nop

    // 0x8004872C: swc1        $f16, 0xFC($t6)
    MEM_W(0XFC, ctx->r14) = ctx->f16.u32l;
    // 0x80048730: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80048734: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80048738: sh          $t2, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r10;
    // 0x8004873C: b           L_80048744
    // 0x80048740: nop

        goto L_80048744;
    // 0x80048740: nop

L_80048744:
    // 0x80048744: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80048748: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8004874C: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80048750: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80048754: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80048758: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8004875C: jr          $ra
    // 0x80048760: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80048760: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80072420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072420: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072424: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072428: nop

    // 0x8007242C: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072430: nop

    // 0x80072434: slti        $t7, $v0, 0xE6
    ctx->r15 = SIGNED(ctx->r2) < 0XE6 ? 1 : 0;
    // 0x80072438: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007243C: jr          $ra
    // 0x80072440: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072440: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072444: jr          $ra
    // 0x80072448: nop

    return;
    // 0x80072448: nop

    // 0x8007244C: jr          $ra
    // 0x80072450: nop

    return;
    // 0x80072450: nop

;}
