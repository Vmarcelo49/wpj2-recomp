#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80077E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077E98: jal         0x8005F064
    // 0x80077E9C: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077E9C: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077EA0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077EA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077EA8: beq         $v0, $zero, L_80077EC0
    if (ctx->r2 == 0) {
        // 0x80077EAC: nop
    
            goto L_80077EC0;
    }
    // 0x80077EAC: nop

    // 0x80077EB0: jal         0x8005F064
    // 0x80077EB4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80077EB4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x80077EB8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077EBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80077EC0:
    // 0x80077EC0: b           L_80077ED0
    // 0x80077EC4: nop

        goto L_80077ED0;
    // 0x80077EC4: nop

    // 0x80077EC8: b           L_80077ED0
    // 0x80077ECC: nop

        goto L_80077ED0;
    // 0x80077ECC: nop

L_80077ED0:
    // 0x80077ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077ED8: jr          $ra
    // 0x80077EDC: nop

    return;
    // 0x80077EDC: nop

;}
RECOMP_FUNC void func_800703B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800703B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800703BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800703C0: jal         0x80061348
    // 0x800703C4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800703C4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800703C8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800703CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800703D0: beq         $v0, $zero, L_80070420
    if (ctx->r2 == 0) {
        // 0x800703D4: nop
    
            goto L_80070420;
    }
    // 0x800703D4: nop

    // 0x800703D8: jal         0x80061348
    // 0x800703DC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800703DC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800703E0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800703E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800703E8: beq         $v0, $zero, L_80070420
    if (ctx->r2 == 0) {
        // 0x800703EC: nop
    
            goto L_80070420;
    }
    // 0x800703EC: nop

    // 0x800703F0: jal         0x80061348
    // 0x800703F4: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800703F4: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800703F8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800703FC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070400: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070404: beq         $v0, $zero, L_80070420
    if (ctx->r2 == 0) {
        // 0x80070408: nop
    
            goto L_80070420;
    }
    // 0x80070408: nop

    // 0x8007040C: jal         0x80061348
    // 0x80070410: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070410: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070414: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070418: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007041C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070420:
    // 0x80070420: b           L_80070430
    // 0x80070424: nop

        goto L_80070430;
    // 0x80070424: nop

    // 0x80070428: b           L_80070430
    // 0x8007042C: nop

        goto L_80070430;
    // 0x8007042C: nop

L_80070430:
    // 0x80070430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070438: jr          $ra
    // 0x8007043C: nop

    return;
    // 0x8007043C: nop

;}
RECOMP_FUNC void func_8002D798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D798: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002D79C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D7A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002D7A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002D7A8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002D7AC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002D7B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D7B4: jal         0x80096474
    // 0x8002D7B8: nop

    func_80096474(rdram, ctx);
        goto after_0;
    // 0x8002D7B8: nop

    after_0:
    // 0x8002D7BC: jal         0x80090754
    // 0x8002D7C0: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    func_80090754(rdram, ctx);
        goto after_1;
    // 0x8002D7C0: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    after_1:
    // 0x8002D7C4: jal         0x80090728
    // 0x8002D7C8: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    func_80090728(rdram, ctx);
        goto after_2;
    // 0x8002D7C8: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    after_2:
    // 0x8002D7CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D7D0: jal         0x8008EAA8
    // 0x8002D7D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x8002D7D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8002D7D8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002D7DC: nop

    // 0x8002D7E0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8002D7E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002D7E8: jal         0x8008ECCC
    // 0x8002D7EC: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_4;
    // 0x8002D7EC: nop

    after_4:
    // 0x8002D7F0: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x8002D7F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8002D7F8: blez        $t7, L_8002D938
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8002D7FC: nop
    
            goto L_8002D938;
    }
    // 0x8002D7FC: nop

L_8002D800:
    // 0x8002D800: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D804: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002D808: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002D80C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002D810: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8002D814: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D818: nop

    // 0x8002D81C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002D820: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8002D824: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D828: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8002D82C: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8002D830: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8002D834: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8002D838: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D83C: nop

    // 0x8002D840: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D844: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002D848: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D84C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002D850: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002D854: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002D858: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8002D85C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D860: nop

    // 0x8002D864: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002D868: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8002D86C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D870: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8002D874: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8002D878: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8002D87C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8002D880: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D884: nop

    // 0x8002D888: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D88C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002D890: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D894: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002D898: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002D89C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002D8A0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8002D8A4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8A8: nop

    // 0x8002D8AC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002D8B0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8002D8B4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8B8: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8002D8BC: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8002D8C0: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8002D8C4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8002D8C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8CC: nop

    // 0x8002D8D0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D8D4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002D8D8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8DC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002D8E0: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8002D8E4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002D8E8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8002D8EC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8F0: nop

    // 0x8002D8F4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002D8F8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8002D8FC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002D900: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8002D904: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8002D908: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8002D90C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8002D910: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D914: nop

    // 0x8002D918: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D91C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002D920: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D924: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x8002D928: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002D92C: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002D930: bne         $at, $zero, L_8002D800
    if (ctx->r1 != 0) {
        // 0x8002D934: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8002D800;
    }
    // 0x8002D934: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8002D938:
    // 0x8002D938: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x8002D93C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002D940: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
    // 0x8002D944: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002D948: sw          $zero, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = 0;
    // 0x8002D94C: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x8002D950: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002D954: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x8002D958: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8002D95C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002D960: jal         0x8008ECAC
    // 0x8002D964: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_8008ECAC(rdram, ctx);
        goto after_5;
    // 0x8002D964: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_5:
    // 0x8002D968: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x8002D96C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002D970: sll         $t3, $t5, 3
    ctx->r11 = S32(ctx->r13 << 3);
    // 0x8002D974: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002D978: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002D97C: jal         0x8008EC8C
    // 0x8002D980: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_8008EC8C(rdram, ctx);
        goto after_6;
    // 0x8002D980: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_6:
    // 0x8002D984: lh          $s0, 0x32($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X32);
    // 0x8002D988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002D98C: beq         $s0, $at, L_8002D9B4
    if (ctx->r16 == ctx->r1) {
        // 0x8002D990: nop
    
            goto L_8002D9B4;
    }
    // 0x8002D990: nop

    // 0x8002D994: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002D998: beq         $s0, $at, L_8002D9CC
    if (ctx->r16 == ctx->r1) {
        // 0x8002D99C: nop
    
            goto L_8002D9CC;
    }
    // 0x8002D99C: nop

    // 0x8002D9A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002D9A4: beq         $s0, $at, L_8002D9E4
    if (ctx->r16 == ctx->r1) {
        // 0x8002D9A8: nop
    
            goto L_8002D9E4;
    }
    // 0x8002D9A8: nop

    // 0x8002D9AC: b           L_8002D9FC
    // 0x8002D9B0: nop

        goto L_8002D9FC;
    // 0x8002D9B0: nop

L_8002D9B4:
    // 0x8002D9B4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002D9B8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002D9BC: jal         0x8008ECE4
    // 0x8002D9C0: addiu       $a0, $a0, -0x1860
    ctx->r4 = ADD32(ctx->r4, -0X1860);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8002D9C0: addiu       $a0, $a0, -0x1860
    ctx->r4 = ADD32(ctx->r4, -0X1860);
    after_7:
    // 0x8002D9C4: b           L_8002D9FC
    // 0x8002D9C8: nop

        goto L_8002D9FC;
    // 0x8002D9C8: nop

L_8002D9CC:
    // 0x8002D9CC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002D9D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002D9D4: jal         0x8008ECE4
    // 0x8002D9D8: addiu       $a0, $a0, -0x185C
    ctx->r4 = ADD32(ctx->r4, -0X185C);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x8002D9D8: addiu       $a0, $a0, -0x185C
    ctx->r4 = ADD32(ctx->r4, -0X185C);
    after_8:
    // 0x8002D9DC: b           L_8002D9FC
    // 0x8002D9E0: nop

        goto L_8002D9FC;
    // 0x8002D9E0: nop

L_8002D9E4:
    // 0x8002D9E4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002D9E8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002D9EC: jal         0x8008ECE4
    // 0x8002D9F0: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8002D9F0: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
    after_9:
    // 0x8002D9F4: b           L_8002D9FC
    // 0x8002D9F8: nop

        goto L_8002D9FC;
    // 0x8002D9F8: nop

L_8002D9FC:
    // 0x8002D9FC: jal         0x800967D8
    // 0x8002DA00: nop

    func_800967D8(rdram, ctx);
        goto after_10;
    // 0x8002DA00: nop

    after_10:
    // 0x8002DA04: b           L_8002DA0C
    // 0x8002DA08: nop

        goto L_8002DA0C;
    // 0x8002DA08: nop

L_8002DA0C:
    // 0x8002DA0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DA10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DA14: jr          $ra
    // 0x8002DA18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002DA18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800856E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800856E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800856EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800856F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800856F4: jal         0x8008A46C
    // 0x800856F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x800856F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x800856FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80085700: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80085704: jal         0x8008BFF4
    // 0x80085708: nop

    func_8008BFF4(rdram, ctx);
        goto after_1;
    // 0x80085708: nop

    after_1:
    // 0x8008570C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085710: jal         0x80089170
    // 0x80085714: nop

    func_80089170(rdram, ctx);
        goto after_2;
    // 0x80085714: nop

    after_2:
    // 0x80085718: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008571C: jal         0x80089418
    // 0x80085720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80089418(rdram, ctx);
        goto after_3;
    // 0x80085720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80085724: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80085728: lh          $a2, 0x7A16($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7A16);
    // 0x8008572C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80085730: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80085734: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80085738: jal         0x800898D8
    // 0x8008573C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    func_800898D8(rdram, ctx);
        goto after_4;
    // 0x8008573C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    after_4:
    // 0x80085740: beq         $v0, $zero, L_80085790
    if (ctx->r2 == 0) {
        // 0x80085744: nop
    
            goto L_80085790;
    }
    // 0x80085744: nop

    // 0x80085748: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8008574C: lh          $t7, 0x22($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X22);
    // 0x80085750: lh          $t9, 0x20($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20);
    // 0x80085754: lh          $t0, 0x24($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X24);
    // 0x80085758: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8008575C: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x80085760: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085764: bgez        $a1, L_80085774
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80085768: sra         $t8, $a1, 1
        ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80085774;
    }
    // 0x80085768: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8008576C: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80085770: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80085774:
    // 0x80085774: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80085778: bgez        $a2, L_80085788
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008577C: sra         $t1, $a2, 1
        ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80085788;
    }
    // 0x8008577C: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80085780: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80085784: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80085788:
    // 0x80085788: jal         0x80089B04
    // 0x8008578C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_80089B04(rdram, ctx);
        goto after_5;
    // 0x8008578C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_5:
L_80085790:
    // 0x80085790: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80085794: nop

    // 0x80085798: lh          $v0, 0x4($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X4);
    // 0x8008579C: b           L_800857AC
    // 0x800857A0: nop

        goto L_800857AC;
    // 0x800857A0: nop

    // 0x800857A4: b           L_800857AC
    // 0x800857A8: nop

        goto L_800857AC;
    // 0x800857A8: nop

L_800857AC:
    // 0x800857AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800857B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800857B4: jr          $ra
    // 0x800857B8: nop

    return;
    // 0x800857B8: nop

;}
RECOMP_FUNC void func_80065DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065DD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065DD8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065DDC: nop

    // 0x80065DE0: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80065DE4: nop

    // 0x80065DE8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065DEC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065DF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065DF4: beq         $v0, $zero, L_80065E0C
    if (ctx->r2 == 0) {
        // 0x80065DF8: nop
    
            goto L_80065E0C;
    }
    // 0x80065DF8: nop

    // 0x80065DFC: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80065E00: nop

    // 0x80065E04: slti        $t8, $v0, 0x321
    ctx->r24 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80065E08: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065E0C:
    // 0x80065E0C: jr          $ra
    // 0x80065E10: nop

    return;
    // 0x80065E10: nop

    // 0x80065E14: jr          $ra
    // 0x80065E18: nop

    return;
    // 0x80065E18: nop

    // 0x80065E1C: jr          $ra
    // 0x80065E20: nop

    return;
    // 0x80065E20: nop

;}
RECOMP_FUNC void AudioDriver_StopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC4A4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BC4A8: lw          $t6, -0x1D90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1D90);
    // 0x800BC4AC: nop

    // 0x800BC4B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BC4B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BC4B8: sw          $a0, -0x1D90($at)
    MEM_W(-0X1D90, ctx->r1) = ctx->r4;
    // 0x800BC4BC: jr          $ra
    // 0x800BC4C0: nop

    return;
    // 0x800BC4C0: nop

    // 0x800BC4C4: jr          $ra
    // 0x800BC4C8: nop

    return;
    // 0x800BC4C8: nop

;}
RECOMP_FUNC void alSaveParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1D90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1D94: beq         $a1, $at, L_800D1DB0
    if (ctx->r5 == ctx->r1) {
        // 0x800D1D98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D1DB0;
    }
    // 0x800D1D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D1D9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800D1DA0: beql        $a1, $at, L_800D1DBC
    if (ctx->r5 == ctx->r1) {
        // 0x800D1DA4: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800D1DBC;
    }
    goto skip_0;
    // 0x800D1DA4: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800D1DA8: jr          $ra
    // 0x800D1DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D1DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D1DB0:
    // 0x800D1DB0: jr          $ra
    // 0x800D1DB4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x800D1DB4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800D1DB8: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800D1DBC:
    // 0x800D1DBC: jr          $ra
    // 0x800D1DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D1DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void MtxUtil_PushIdentity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1754: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1758: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C175C: lw          $t6, 0xCD8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCD8);
    // 0x800C1760: nop

    // 0x800C1764: bgtz        $t6, L_800C1774
    if (SIGNED(ctx->r14) > 0) {
        // 0x800C1768: nop
    
            goto L_800C1774;
    }
    // 0x800C1768: nop

    // 0x800C176C: b           L_800C1848
    // 0x800C1770: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1848;
    // 0x800C1770: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C1774:
    // 0x800C1774: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C1778: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C177C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1780: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x800C1784: sw          $t8, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r24;
    // 0x800C1788: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C178C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C1790: nop

    // 0x800C1794: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C1798: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800C179C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
L_800C17A0:
    // 0x800C17A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C17A4: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C17A8: nop

    // 0x800C17AC: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x800C17B0: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C17B4: nop

    // 0x800C17B8: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C17BC: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C17C0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C17C4: nop

    // 0x800C17C8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800C17CC: bgtz        $t5, L_800C17A0
    if (SIGNED(ctx->r13) > 0) {
        // 0x800C17D0: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C17A0;
    }
    // 0x800C17D0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C17D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C17D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C17DC: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C17E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C17E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C17E8: swc1        $f6, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f6.u32l;
    // 0x800C17EC: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C17F0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C17F4: lwc1        $f14, 0x3C($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x800C17F8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C17FC: swc1        $f14, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f14.u32l;
    // 0x800C1800: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C1804: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C1808: swc1        $f12, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f12.u32l;
    // 0x800C180C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C1810: nop

    // 0x800C1814: swc1        $f12, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f12.u32l;
    // 0x800C1818: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800C181C: lw          $t0, 0xCD8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCD8);
    // 0x800C1820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1824: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800C1828: sw          $t1, 0xCD8($at)
    MEM_W(0XCD8, ctx->r1) = ctx->r9;
    // 0x800C182C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800C1830: lw          $t2, 0xCD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCD8);
    // 0x800C1834: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800C1838: b           L_800C1848
    // 0x800C183C: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
        goto L_800C1848;
    // 0x800C183C: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x800C1840: b           L_800C1848
    // 0x800C1844: nop

        goto L_800C1848;
    // 0x800C1844: nop

L_800C1848:
    // 0x800C1848: jr          $ra
    // 0x800C184C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C184C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006CE18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CE18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CE1C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CE20: nop

    // 0x8006CE24: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x8006CE28: nop

    // 0x8006CE2C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CE30: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CE34: jr          $ra
    // 0x8006CE38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CE38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CE3C: jr          $ra
    // 0x8006CE40: nop

    return;
    // 0x8006CE40: nop

    // 0x8006CE44: jr          $ra
    // 0x8006CE48: nop

    return;
    // 0x8006CE48: nop

;}
RECOMP_FUNC void func_80063A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A2C: jal         0x8005F064
    // 0x80063A30: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063A30: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063A34: b           L_80063A44
    // 0x80063A38: nop

        goto L_80063A44;
    // 0x80063A38: nop

    // 0x80063A3C: b           L_80063A44
    // 0x80063A40: nop

        goto L_80063A44;
    // 0x80063A40: nop

L_80063A44:
    // 0x80063A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063A48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063A4C: jr          $ra
    // 0x80063A50: nop

    return;
    // 0x80063A50: nop

;}
RECOMP_FUNC void func_80056E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056E88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80056E8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80056E90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80056E94: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80056E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80056E9C: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80056EA0: nop

    // 0x80056EA4: andi        $t7, $t6, 0xC000
    ctx->r15 = ctx->r14 & 0XC000;
    // 0x80056EA8: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x80056EAC: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x80056EB0: nop

    // 0x80056EB4: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x80056EB8: sh          $t9, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r25;
    // 0x80056EBC: jal         0x800560A4
    // 0x80056EC0: nop

    func_800560A4(rdram, ctx);
        goto after_0;
    // 0x80056EC0: nop

    after_0:
    // 0x80056EC4: bne         $v0, $zero, L_80056F10
    if (ctx->r2 != 0) {
        // 0x80056EC8: nop
    
            goto L_80056F10;
    }
    // 0x80056EC8: nop

    // 0x80056ECC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80056ED0: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80056ED4: nop

    // 0x80056ED8: lh          $t1, 0x2E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2E);
    // 0x80056EDC: nop

    // 0x80056EE0: slti        $at, $t1, 0x384
    ctx->r1 = SIGNED(ctx->r9) < 0X384 ? 1 : 0;
    // 0x80056EE4: beq         $at, $zero, L_80056F10
    if (ctx->r1 == 0) {
        // 0x80056EE8: nop
    
            goto L_80056F10;
    }
    // 0x80056EE8: nop

    // 0x80056EEC: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x80056EF0: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80056EF4: nop

    // 0x80056EF8: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x80056EFC: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80056F00: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80056F04: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80056F08: b           L_800574BC
    // 0x80056F0C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x80056F0C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80056F10:
    // 0x80056F10: jal         0x800526C0
    // 0x80056F14: nop

    func_800526C0(rdram, ctx);
        goto after_1;
    // 0x80056F14: nop

    after_1:
    // 0x80056F18: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80056F1C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80056F20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056F24: bne         $t6, $at, L_80056F44
    if (ctx->r14 != ctx->r1) {
        // 0x80056F28: nop
    
            goto L_80056F44;
    }
    // 0x80056F28: nop

    // 0x80056F2C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80056F30: nop

    // 0x80056F34: beq         $t7, $zero, L_80056F44
    if (ctx->r15 == 0) {
        // 0x80056F38: nop
    
            goto L_80056F44;
    }
    // 0x80056F38: nop

    // 0x80056F3C: b           L_800574BC
    // 0x80056F40: addiu       $v0, $zero, 0xAF
    ctx->r2 = ADD32(0, 0XAF);
        goto L_800574BC;
    // 0x80056F40: addiu       $v0, $zero, 0xAF
    ctx->r2 = ADD32(0, 0XAF);
L_80056F44:
    // 0x80056F44: jal         0x80061D20
    // 0x80056F48: nop

    func_80061D20(rdram, ctx);
        goto after_2;
    // 0x80056F48: nop

    after_2:
    // 0x80056F4C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80056F50: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80056F54: nop

    // 0x80056F58: beq         $t8, $zero, L_80056F6C
    if (ctx->r24 == 0) {
        // 0x80056F5C: nop
    
            goto L_80056F6C;
    }
    // 0x80056F5C: nop

    // 0x80056F60: addiu       $t9, $t8, -0x17
    ctx->r25 = ADD32(ctx->r24, -0X17);
    // 0x80056F64: b           L_80056F70
    // 0x80056F68: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
        goto L_80056F70;
    // 0x80056F68: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_80056F6C:
    // 0x80056F6C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80056F70:
    // 0x80056F70: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80056F74: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80056F78: nop

    // 0x80056F7C: lh          $t1, 0x2E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2E);
    // 0x80056F80: nop

    // 0x80056F84: slti        $at, $t1, 0x384
    ctx->r1 = SIGNED(ctx->r9) < 0X384 ? 1 : 0;
    // 0x80056F88: bne         $at, $zero, L_80056F98
    if (ctx->r1 != 0) {
        // 0x80056F8C: nop
    
            goto L_80056F98;
    }
    // 0x80056F8C: nop

    // 0x80056F90: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80056F94: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_80056F98:
    // 0x80056F98: lh          $s0, 0x32($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X32);
    // 0x80056F9C: nop

    // 0x80056FA0: slti        $at, $s0, 0xA1
    ctx->r1 = SIGNED(ctx->r16) < 0XA1 ? 1 : 0;
    // 0x80056FA4: bne         $at, $zero, L_80056FCC
    if (ctx->r1 != 0) {
        // 0x80056FA8: nop
    
            goto L_80056FCC;
    }
    // 0x80056FA8: nop

    // 0x80056FAC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80056FB0: beq         $s0, $at, L_80057230
    if (ctx->r16 == ctx->r1) {
        // 0x80056FB4: nop
    
            goto L_80057230;
    }
    // 0x80056FB4: nop

    // 0x80056FB8: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x80056FBC: beq         $s0, $at, L_800573D0
    if (ctx->r16 == ctx->r1) {
        // 0x80056FC0: nop
    
            goto L_800573D0;
    }
    // 0x80056FC0: nop

    // 0x80056FC4: b           L_8005746C
    // 0x80056FC8: nop

        goto L_8005746C;
    // 0x80056FC8: nop

L_80056FCC:
    // 0x80056FCC: slti        $at, $s0, 0x24
    ctx->r1 = SIGNED(ctx->r16) < 0X24 ? 1 : 0;
    // 0x80056FD0: bne         $at, $zero, L_80057004
    if (ctx->r1 != 0) {
        // 0x80056FD4: nop
    
            goto L_80057004;
    }
    // 0x80056FD4: nop

    // 0x80056FD8: addiu       $t3, $s0, -0x45
    ctx->r11 = ADD32(ctx->r16, -0X45);
    // 0x80056FDC: sltiu       $at, $t3, 0x5C
    ctx->r1 = ctx->r11 < 0X5C ? 1 : 0;
    // 0x80056FE0: beq         $at, $zero, L_8005746C
    if (ctx->r1 == 0) {
        // 0x80056FE4: nop
    
            goto L_8005746C;
    }
    // 0x80056FE4: nop

    // 0x80056FE8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80056FEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80056FF0: addu        $at, $at, $t3
    gpr jr_addend_80056FFC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80056FF4: lw          $t3, -0x10A0($at)
    ctx->r11 = ADD32(ctx->r1, -0X10A0);
    // 0x80056FF8: nop

    // 0x80056FFC: jr          $t3
    // 0x80057000: nop

    switch (jr_addend_80056FFC >> 2) {
        case 0: goto L_80057264; break;
        case 1: goto L_8005746C; break;
        case 2: goto L_8005746C; break;
        case 3: goto L_8005746C; break;
        case 4: goto L_80057298; break;
        case 5: goto L_8005746C; break;
        case 6: goto L_8005746C; break;
        case 7: goto L_8005746C; break;
        case 8: goto L_800572CC; break;
        case 9: goto L_8005746C; break;
        case 10: goto L_8005746C; break;
        case 11: goto L_8005746C; break;
        case 12: goto L_80057300; break;
        case 13: goto L_8005746C; break;
        case 14: goto L_8005746C; break;
        case 15: goto L_8005746C; break;
        case 16: goto L_80057334; break;
        case 17: goto L_8005746C; break;
        case 18: goto L_8005746C; break;
        case 19: goto L_8005746C; break;
        case 20: goto L_8005746C; break;
        case 21: goto L_80057368; break;
        case 22: goto L_8005746C; break;
        case 23: goto L_8005746C; break;
        case 24: goto L_8005746C; break;
        case 25: goto L_8005739C; break;
        case 26: goto L_8005746C; break;
        case 27: goto L_8005746C; break;
        case 28: goto L_8005746C; break;
        case 29: goto L_8005746C; break;
        case 30: goto L_8005746C; break;
        case 31: goto L_8005746C; break;
        case 32: goto L_80057194; break;
        case 33: goto L_8005746C; break;
        case 34: goto L_8005746C; break;
        case 35: goto L_8005746C; break;
        case 36: goto L_80057160; break;
        case 37: goto L_8005746C; break;
        case 38: goto L_8005746C; break;
        case 39: goto L_8005746C; break;
        case 40: goto L_8005746C; break;
        case 41: goto L_8005746C; break;
        case 42: goto L_8005746C; break;
        case 43: goto L_8005746C; break;
        case 44: goto L_80057024; break;
        case 45: goto L_8005746C; break;
        case 46: goto L_8005746C; break;
        case 47: goto L_8005746C; break;
        case 48: goto L_8005746C; break;
        case 49: goto L_8005746C; break;
        case 50: goto L_8005746C; break;
        case 51: goto L_8005746C; break;
        case 52: goto L_8005746C; break;
        case 53: goto L_8005746C; break;
        case 54: goto L_8005746C; break;
        case 55: goto L_8005746C; break;
        case 56: goto L_8005746C; break;
        case 57: goto L_8005746C; break;
        case 58: goto L_8005746C; break;
        case 59: goto L_8005746C; break;
        case 60: goto L_80057404; break;
        case 61: goto L_8005746C; break;
        case 62: goto L_8005746C; break;
        case 63: goto L_8005746C; break;
        case 64: goto L_8005746C; break;
        case 65: goto L_8005746C; break;
        case 66: goto L_8005746C; break;
        case 67: goto L_8005746C; break;
        case 68: goto L_8005746C; break;
        case 69: goto L_8005746C; break;
        case 70: goto L_8005746C; break;
        case 71: goto L_8005746C; break;
        case 72: goto L_8005746C; break;
        case 73: goto L_8005746C; break;
        case 74: goto L_80057438; break;
        case 75: goto L_8005746C; break;
        case 76: goto L_8005746C; break;
        case 77: goto L_8005746C; break;
        case 78: goto L_8005746C; break;
        case 79: goto L_8005746C; break;
        case 80: goto L_8005746C; break;
        case 81: goto L_8005746C; break;
        case 82: goto L_8005746C; break;
        case 83: goto L_8005746C; break;
        case 84: goto L_8005746C; break;
        case 85: goto L_8005746C; break;
        case 86: goto L_800571C8; break;
        case 87: goto L_8005746C; break;
        case 88: goto L_8005746C; break;
        case 89: goto L_8005746C; break;
        case 90: goto L_8005746C; break;
        case 91: goto L_800571FC; break;
        default: switch_error(__func__, 0x80056FFC, 0x800EEF60);
    }
    // 0x80057000: nop

L_80057004:
    // 0x80057004: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80057008: beq         $s0, $at, L_800570C4
    if (ctx->r16 == ctx->r1) {
        // 0x8005700C: nop
    
            goto L_800570C4;
    }
    // 0x8005700C: nop

    // 0x80057010: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80057014: beq         $s0, $at, L_80057090
    if (ctx->r16 == ctx->r1) {
        // 0x80057018: nop
    
            goto L_80057090;
    }
    // 0x80057018: nop

    // 0x8005701C: b           L_8005746C
    // 0x80057020: nop

        goto L_8005746C;
    // 0x80057020: nop

L_80057024:
    // 0x80057024: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80057028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005702C: beq         $s0, $at, L_80057048
    if (ctx->r16 == ctx->r1) {
        // 0x80057030: nop
    
            goto L_80057048;
    }
    // 0x80057030: nop

    // 0x80057034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80057038: beq         $s0, $at, L_80057050
    if (ctx->r16 == ctx->r1) {
        // 0x8005703C: nop
    
            goto L_80057050;
    }
    // 0x8005703C: nop

    // 0x80057040: b           L_80057058
    // 0x80057044: nop

        goto L_80057058;
    // 0x80057044: nop

L_80057048:
    // 0x80057048: b           L_800574BC
    // 0x8005704C: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
        goto L_800574BC;
    // 0x8005704C: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
L_80057050:
    // 0x80057050: b           L_800574BC
    // 0x80057054: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
        goto L_800574BC;
    // 0x80057054: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
L_80057058:
    // 0x80057058: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8005705C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80057060: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80057064: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80057068: lh          $v0, -0x2794($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2794);
    // 0x8005706C: b           L_800574BC
    // 0x80057070: nop

        goto L_800574BC;
    // 0x80057070: nop

    // 0x80057074: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80057078: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005707C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80057080: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80057084: lh          $v0, -0x2794($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2794);
    // 0x80057088: b           L_800574BC
    // 0x8005708C: nop

        goto L_800574BC;
    // 0x8005708C: nop

L_80057090:
    // 0x80057090: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80057094: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80057098: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005709C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800570A0: lh          $t0, -0x278A($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X278A);
    // 0x800570A4: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800570A8: nop

    // 0x800570AC: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800570B0: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800570B4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800570B8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800570BC: b           L_800574BC
    // 0x800570C0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x800570C0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800570C4:
    // 0x800570C4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800570C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800570CC: beq         $s0, $at, L_800570E8
    if (ctx->r16 == ctx->r1) {
        // 0x800570D0: nop
    
            goto L_800570E8;
    }
    // 0x800570D0: nop

    // 0x800570D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800570D8: beq         $s0, $at, L_800570F0
    if (ctx->r16 == ctx->r1) {
        // 0x800570DC: nop
    
            goto L_800570F0;
    }
    // 0x800570DC: nop

    // 0x800570E0: b           L_800570F8
    // 0x800570E4: nop

        goto L_800570F8;
    // 0x800570E4: nop

L_800570E8:
    // 0x800570E8: b           L_800574BC
    // 0x800570EC: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
        goto L_800574BC;
    // 0x800570EC: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
L_800570F0:
    // 0x800570F0: b           L_800574BC
    // 0x800570F4: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
        goto L_800574BC;
    // 0x800570F4: addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
L_800570F8:
    // 0x800570F8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800570FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80057100: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80057104: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80057108: lh          $t6, -0x2780($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2780);
    // 0x8005710C: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80057110: nop

    // 0x80057114: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x80057118: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8005711C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80057120: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057124: b           L_800574BC
    // 0x80057128: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x80057128: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8005712C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80057130: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80057134: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80057138: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005713C: lh          $t2, -0x2780($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X2780);
    // 0x80057140: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80057144: nop

    // 0x80057148: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x8005714C: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80057150: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80057154: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057158: b           L_800574BC
    // 0x8005715C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x8005715C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80057160:
    // 0x80057160: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80057164: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80057168: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8005716C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80057170: lh          $t8, -0x2776($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2776);
    // 0x80057174: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80057178: nop

    // 0x8005717C: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    // 0x80057180: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80057184: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80057188: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005718C: b           L_800574BC
    // 0x80057190: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800574BC;
    // 0x80057190: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80057194:
    // 0x80057194: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80057198: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8005719C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800571A0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800571A4: lh          $t4, -0x276C($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X276C);
    // 0x800571A8: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x800571AC: nop

    // 0x800571B0: or          $v0, $t4, $t5
    ctx->r2 = ctx->r12 | ctx->r13;
    // 0x800571B4: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800571B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800571BC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800571C0: b           L_800574BC
    // 0x800571C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800574BC;
    // 0x800571C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800571C8:
    // 0x800571C8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800571CC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800571D0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800571D4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800571D8: lh          $t0, -0x2762($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2762);
    // 0x800571DC: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800571E0: nop

    // 0x800571E4: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800571E8: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800571EC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800571F0: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800571F4: b           L_800574BC
    // 0x800571F8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x800571F8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800571FC:
    // 0x800571FC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80057200: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80057204: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80057208: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005720C: lh          $t6, -0x2758($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2758);
    // 0x80057210: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80057214: nop

    // 0x80057218: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x8005721C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057220: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80057224: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057228: b           L_800574BC
    // 0x8005722C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x8005722C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80057230:
    // 0x80057230: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80057234: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80057238: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8005723C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80057240: lh          $t2, -0x274E($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X274E);
    // 0x80057244: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80057248: nop

    // 0x8005724C: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x80057250: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80057254: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80057258: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005725C: b           L_800574BC
    // 0x80057260: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x80057260: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80057264:
    // 0x80057264: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80057268: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005726C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80057270: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80057274: lh          $t8, -0x2744($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2744);
    // 0x80057278: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8005727C: nop

    // 0x80057280: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    // 0x80057284: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80057288: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8005728C: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057290: b           L_800574BC
    // 0x80057294: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800574BC;
    // 0x80057294: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80057298:
    // 0x80057298: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005729C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800572A0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800572A4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800572A8: lh          $t4, -0x273A($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X273A);
    // 0x800572AC: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x800572B0: nop

    // 0x800572B4: or          $v0, $t4, $t5
    ctx->r2 = ctx->r12 | ctx->r13;
    // 0x800572B8: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800572BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800572C0: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800572C4: b           L_800574BC
    // 0x800572C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800574BC;
    // 0x800572C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800572CC:
    // 0x800572CC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800572D0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800572D4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800572D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800572DC: lh          $t0, -0x2730($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2730);
    // 0x800572E0: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800572E4: nop

    // 0x800572E8: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800572EC: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800572F0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800572F4: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800572F8: b           L_800574BC
    // 0x800572FC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x800572FC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80057300:
    // 0x80057300: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80057304: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80057308: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8005730C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80057310: lh          $t6, -0x2726($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2726);
    // 0x80057314: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80057318: nop

    // 0x8005731C: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x80057320: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057324: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80057328: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005732C: b           L_800574BC
    // 0x80057330: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x80057330: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80057334:
    // 0x80057334: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80057338: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8005733C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80057340: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80057344: lh          $t2, -0x271C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X271C);
    // 0x80057348: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8005734C: nop

    // 0x80057350: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x80057354: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80057358: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8005735C: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057360: b           L_800574BC
    // 0x80057364: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x80057364: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80057368:
    // 0x80057368: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005736C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80057370: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80057374: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80057378: lh          $t8, -0x2712($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2712);
    // 0x8005737C: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80057380: nop

    // 0x80057384: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    // 0x80057388: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8005738C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80057390: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057394: b           L_800574BC
    // 0x80057398: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800574BC;
    // 0x80057398: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8005739C:
    // 0x8005739C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800573A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800573A4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800573A8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800573AC: lh          $t4, -0x2708($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X2708);
    // 0x800573B0: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x800573B4: nop

    // 0x800573B8: or          $v0, $t4, $t5
    ctx->r2 = ctx->r12 | ctx->r13;
    // 0x800573BC: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800573C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800573C4: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800573C8: b           L_800574BC
    // 0x800573CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800574BC;
    // 0x800573CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800573D0:
    // 0x800573D0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800573D4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800573D8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800573DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800573E0: lh          $t0, -0x26FE($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X26FE);
    // 0x800573E4: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x800573E8: nop

    // 0x800573EC: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800573F0: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800573F4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800573F8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800573FC: b           L_800574BC
    // 0x80057400: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x80057400: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80057404:
    // 0x80057404: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80057408: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005740C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80057410: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80057414: lh          $t6, -0x26F4($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26F4);
    // 0x80057418: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x8005741C: nop

    // 0x80057420: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x80057424: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057428: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8005742C: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057430: b           L_800574BC
    // 0x80057434: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x80057434: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80057438:
    // 0x80057438: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005743C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80057440: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80057444: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80057448: lh          $t2, -0x26EA($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X26EA);
    // 0x8005744C: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80057450: nop

    // 0x80057454: or          $v0, $t2, $t3
    ctx->r2 = ctx->r10 | ctx->r11;
    // 0x80057458: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8005745C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80057460: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057464: b           L_800574BC
    // 0x80057468: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800574BC;
    // 0x80057468: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8005746C:
    // 0x8005746C: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x80057470: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x80057474: nop

    // 0x80057478: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x8005747C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057480: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80057484: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80057488: b           L_800574BC
    // 0x8005748C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800574BC;
    // 0x8005748C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80057490: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x80057494: lh          $t1, 0x32($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X32);
    // 0x80057498: nop

    // 0x8005749C: or          $v0, $t0, $t1
    ctx->r2 = ctx->r8 | ctx->r9;
    // 0x800574A0: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x800574A4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800574A8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800574AC: b           L_800574BC
    // 0x800574B0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800574BC;
    // 0x800574B0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800574B4: b           L_800574BC
    // 0x800574B8: nop

        goto L_800574BC;
    // 0x800574B8: nop

L_800574BC:
    // 0x800574BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800574C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800574C4: jr          $ra
    // 0x800574C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800574C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B9F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9F48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9F50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B9F54: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B9F58: nop

    // 0x800B9F5C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800B9F60: nop

    // 0x800B9F64: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B9F68: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x800B9F6C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B9F70: nop

    // 0x800B9F74: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B9F78: nop

    // 0x800B9F7C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800B9F80: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800B9F84: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B9F88: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800B9F8C: lw          $t4, 0x28($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X28);
    // 0x800B9F90: nop

    // 0x800B9F94: beq         $t2, $t4, L_800B9FC8
    if (ctx->r10 == ctx->r12) {
        // 0x800B9F98: nop
    
            goto L_800B9FC8;
    }
    // 0x800B9F98: nop

    // 0x800B9F9C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800B9FA0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B9FA4: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x800B9FA8: nop

    // 0x800B9FAC: sw          $t7, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r15;
    // 0x800B9FB0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800B9FB4: nop

    // 0x800B9FB8: lw          $t9, 0x1C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C);
    // 0x800B9FBC: nop

    // 0x800B9FC0: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800B9FC4: sw          $t0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r8;
L_800B9FC8:
    // 0x800B9FC8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800B9FCC: nop

    // 0x800B9FD0: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x800B9FD4: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x800B9FD8: nop

    // 0x800B9FDC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B9FE0: beq         $at, $zero, L_800BA050
    if (ctx->r1 == 0) {
        // 0x800B9FE4: nop
    
            goto L_800BA050;
    }
    // 0x800B9FE4: nop

    // 0x800B9FE8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B9FEC: nop

    // 0x800B9FF0: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x800B9FF4: nop

    // 0x800B9FF8: ori         $t7, $t5, 0x2
    ctx->r15 = ctx->r13 | 0X2;
    // 0x800B9FFC: sw          $t7, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r15;
    // 0x800BA000: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800BA004: nop

    // 0x800BA008: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x800BA00C: lhu         $t0, 0x18($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X18);
    // 0x800BA010: nop

    // 0x800BA014: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x800BA018: sw          $t6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r14;
    // 0x800BA01C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800BA020: nop

    // 0x800BA024: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x800BA028: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x800BA02C: nop

    // 0x800BA030: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BA034: beq         $at, $zero, L_800BA050
    if (ctx->r1 == 0) {
        // 0x800BA038: nop
    
            goto L_800BA050;
    }
    // 0x800BA038: nop

    // 0x800BA03C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BA040: nop

    // 0x800BA044: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x800BA048: nop

    // 0x800BA04C: sw          $t7, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r15;
L_800BA050:
    // 0x800BA050: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800BA054: nop

    // 0x800BA058: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x800BA05C: lw          $t0, 0x10($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X10);
    // 0x800BA060: nop

    // 0x800BA064: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BA068: beq         $at, $zero, L_800BA0D8
    if (ctx->r1 == 0) {
        // 0x800BA06C: nop
    
            goto L_800BA0D8;
    }
    // 0x800BA06C: nop

    // 0x800BA070: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800BA074: nop

    // 0x800BA078: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x800BA07C: nop

    // 0x800BA080: ori         $t1, $t8, 0x2
    ctx->r9 = ctx->r24 | 0X2;
    // 0x800BA084: sw          $t1, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r9;
    // 0x800BA088: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800BA08C: nop

    // 0x800BA090: lw          $t2, 0x10($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X10);
    // 0x800BA094: lhu         $t7, 0x18($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X18);
    // 0x800BA098: nop

    // 0x800BA09C: subu        $t5, $t2, $t7
    ctx->r13 = SUB32(ctx->r10, ctx->r15);
    // 0x800BA0A0: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    // 0x800BA0A4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800BA0A8: nop

    // 0x800BA0AC: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x800BA0B0: lw          $t0, 0x10($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X10);
    // 0x800BA0B4: nop

    // 0x800BA0B8: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BA0BC: beq         $at, $zero, L_800BA0D8
    if (ctx->r1 == 0) {
        // 0x800BA0C0: nop
    
            goto L_800BA0D8;
    }
    // 0x800BA0C0: nop

    // 0x800BA0C4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800BA0C8: nop

    // 0x800BA0CC: lw          $t1, 0xC($t8)
    ctx->r9 = MEM_W(ctx->r24, 0XC);
    // 0x800BA0D0: nop

    // 0x800BA0D4: sw          $t1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r9;
L_800BA0D8:
    // 0x800BA0D8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BA0DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800BA0E0: lbu         $t2, 0x1A($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X1A);
    // 0x800BA0E4: lbu         $t5, 0x31($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X31);
    // 0x800BA0E8: nop

    // 0x800BA0EC: beq         $t2, $t5, L_800BA120
    if (ctx->r10 == ctx->r13) {
        // 0x800BA0F0: nop
    
            goto L_800BA120;
    }
    // 0x800BA0F0: nop

    // 0x800BA0F4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800BA0F8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800BA0FC: lbu         $t4, 0x1A($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1A);
    // 0x800BA100: nop

    // 0x800BA104: sb          $t4, 0x31($t9)
    MEM_B(0X31, ctx->r25) = ctx->r12;
    // 0x800BA108: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800BA10C: nop

    // 0x800BA110: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800BA114: nop

    // 0x800BA118: ori         $t8, $t1, 0x4
    ctx->r24 = ctx->r9 | 0X4;
    // 0x800BA11C: sw          $t8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r24;
L_800BA120:
    // 0x800BA120: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800BA124: nop

    // 0x800BA128: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800BA12C: nop

    // 0x800BA130: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x800BA134: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x800BA138: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800BA13C: nop

    // 0x800BA140: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x800BA144: nop

    // 0x800BA148: bne         $t3, $zero, L_800BA1D0
    if (ctx->r11 != 0) {
        // 0x800BA14C: nop
    
            goto L_800BA1D0;
    }
    // 0x800BA14C: nop

L_800BA150:
    // 0x800BA150: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800BA154: nop

    // 0x800BA158: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x800BA15C: nop

    // 0x800BA160: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x800BA164: nop

    // 0x800BA168: sh          $t1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r9;
    // 0x800BA16C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800BA170: nop

    // 0x800BA174: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x800BA178: nop

    // 0x800BA17C: addiu       $t7, $t0, 0x2
    ctx->r15 = ADD32(ctx->r8, 0X2);
    // 0x800BA180: sw          $t7, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r15;
    // 0x800BA184: lh          $t2, 0x1E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1E);
    // 0x800BA188: nop

    // 0x800BA18C: slti        $at, $t2, 0x4000
    ctx->r1 = SIGNED(ctx->r10) < 0X4000 ? 1 : 0;
    // 0x800BA190: beq         $at, $zero, L_800BA1A8
    if (ctx->r1 == 0) {
        // 0x800BA194: nop
    
            goto L_800BA1A8;
    }
    // 0x800BA194: nop

    // 0x800BA198: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x800BA19C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800BA1A0: b           L_800BA1B8
    // 0x800BA1A4: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
        goto L_800BA1B8;
    // 0x800BA1A4: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
L_800BA1A8:
    // 0x800BA1A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BA1AC: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x800BA1B0: jal         0x800BA244
    // 0x800BA1B4: nop

    func_800BA244(rdram, ctx);
        goto after_0;
    // 0x800BA1B4: nop

    after_0:
L_800BA1B8:
    // 0x800BA1B8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800BA1BC: nop

    // 0x800BA1C0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800BA1C4: nop

    // 0x800BA1C8: beq         $t4, $zero, L_800BA150
    if (ctx->r12 == 0) {
        // 0x800BA1CC: nop
    
            goto L_800BA150;
    }
    // 0x800BA1CC: nop

L_800BA1D0:
    // 0x800BA1D0: b           L_800BA1D8
    // 0x800BA1D4: nop

        goto L_800BA1D8;
    // 0x800BA1D4: nop

L_800BA1D8:
    // 0x800BA1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA1DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BA1E0: jr          $ra
    // 0x800BA1E4: nop

    return;
    // 0x800BA1E4: nop

;}
RECOMP_FUNC void func_8006F078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F07C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F080: jal         0x80061348
    // 0x8006F084: addiu       $a0, $zero, 0x2B5
    ctx->r4 = ADD32(0, 0X2B5);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F084: addiu       $a0, $zero, 0x2B5
    ctx->r4 = ADD32(0, 0X2B5);
    after_0:
    // 0x8006F088: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F08C: b           L_8006F09C
    // 0x8006F090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F09C;
    // 0x8006F090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F094: b           L_8006F09C
    // 0x8006F098: nop

        goto L_8006F09C;
    // 0x8006F098: nop

L_8006F09C:
    // 0x8006F09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F0A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F0A4: jr          $ra
    // 0x8006F0A8: nop

    return;
    // 0x8006F0A8: nop

;}
RECOMP_FUNC void Thread_ReceiveMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1578: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C157C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1580: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C1584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1588: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C158C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C1590: jal         0x800C4C40
    // 0x800C1594: nop

    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1594: nop

    after_0:
    // 0x800C1598: b           L_800C15A8
    // 0x800C159C: nop

        goto L_800C15A8;
    // 0x800C159C: nop

    // 0x800C15A0: b           L_800C15A8
    // 0x800C15A4: nop

        goto L_800C15A8;
    // 0x800C15A4: nop

L_800C15A8:
    // 0x800C15A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C15AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C15B0: jr          $ra
    // 0x800C15B4: nop

    return;
    // 0x800C15B4: nop

;}
RECOMP_FUNC void func_800740B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800740B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800740B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800740BC: jal         0x80061348
    // 0x800740C0: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800740C0: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x800740C4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800740C8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800740CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800740D0: beq         $v0, $zero, L_800740EC
    if (ctx->r2 == 0) {
        // 0x800740D4: nop
    
            goto L_800740EC;
    }
    // 0x800740D4: nop

    // 0x800740D8: jal         0x80061348
    // 0x800740DC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800740DC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x800740E0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800740E4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800740E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800740EC:
    // 0x800740EC: b           L_800740FC
    // 0x800740F0: nop

        goto L_800740FC;
    // 0x800740F0: nop

    // 0x800740F4: b           L_800740FC
    // 0x800740F8: nop

        goto L_800740FC;
    // 0x800740F8: nop

L_800740FC:
    // 0x800740FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074104: jr          $ra
    // 0x80074108: nop

    return;
    // 0x80074108: nop

;}
RECOMP_FUNC void func_800687B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687B4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800687B8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800687BC: nop

    // 0x800687C0: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x800687C4: nop

    // 0x800687C8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800687CC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800687D0: jr          $ra
    // 0x800687D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800687D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800687D8: jr          $ra
    // 0x800687DC: nop

    return;
    // 0x800687DC: nop

    // 0x800687E0: jr          $ra
    // 0x800687E4: nop

    return;
    // 0x800687E4: nop

;}
RECOMP_FUNC void func_8008DD40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008DD44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008DD48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008DD4C: lui         $t6, 0x809A
    ctx->r14 = S32(0X809A << 16);
    // 0x8008DD50: lui         $t7, 0x809A
    ctx->r15 = S32(0X809A << 16);
    // 0x8008DD54: addiu       $t7, $t7, -0x67E8
    ctx->r15 = ADD32(ctx->r15, -0X67E8);
    // 0x8008DD58: addiu       $t6, $t6, -0x6778
    ctx->r14 = ADD32(ctx->r14, -0X6778);
    // 0x8008DD5C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8008DD60: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008DD64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008DD68: jal         0x800BC6EC
    // 0x8008DD6C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008DD6C: nop

    after_0:
    // 0x8008DD70: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8008DD74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008DD78: jal         0x800BC6EC
    // 0x8008DD7C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8008DD7C: nop

    after_1:
    // 0x8008DD80: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8008DD84: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008DD88: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008DD8C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008DD90: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008DD94: lui         $a2, 0x809A
    ctx->r6 = S32(0X809A << 16);
    // 0x8008DD98: jal         0x800BD1FC
    // 0x8008DD9C: addiu       $a2, $a2, -0x67E8
    ctx->r6 = ADD32(ctx->r6, -0X67E8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8008DD9C: addiu       $a2, $a2, -0x67E8
    ctx->r6 = ADD32(ctx->r6, -0X67E8);
    after_2:
    // 0x8008DDA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008DDA4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DDA8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8008DDAC: jal         0x800BD218
    // 0x8008DDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8008DDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008DDB4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DDB8: nop

    // 0x8008DDBC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8008DDC0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DDC4: nop

    // 0x8008DDC8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_8008DDCC:
    // 0x8008DDCC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008DDD0: nop

    // 0x8008DDD4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8008DDD8: nop

    // 0x8008DDDC: bne         $t2, $zero, L_8008DDEC
    if (ctx->r10 != 0) {
        // 0x8008DDE0: nop
    
            goto L_8008DDEC;
    }
    // 0x8008DDE0: nop

    // 0x8008DDE4: b           L_8008DE48
    // 0x8008DDE8: nop

        goto L_8008DE48;
    // 0x8008DDE8: nop

L_8008DDEC:
    // 0x8008DDEC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008DDF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008DDF4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008DDF8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008DDFC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008DE00: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x8008DE04: jal         0x800BD1FC
    // 0x8008DE08: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x8008DE08: nop

    after_4:
    // 0x8008DE0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008DE10: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008DE14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008DE18: jal         0x800BD218
    // 0x8008DE1C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x8008DE1C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x8008DE20: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008DE24: nop

    // 0x8008DE28: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x8008DE2C: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8008DE30: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008DE34: nop

    // 0x8008DE38: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8008DE3C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008DE40: b           L_8008DDCC
    // 0x8008DE44: nop

        goto L_8008DDCC;
    // 0x8008DE44: nop

L_8008DE48:
    // 0x8008DE48: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DE4C: jal         0x800BC980
    // 0x8008DE50: nop

    SysMem_Free(rdram, ctx);
        goto after_6;
    // 0x8008DE50: nop

    after_6:
    // 0x8008DE54: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DE58: b           L_8008DE68
    // 0x8008DE5C: nop

        goto L_8008DE68;
    // 0x8008DE5C: nop

    // 0x8008DE60: b           L_8008DE68
    // 0x8008DE64: nop

        goto L_8008DE68;
    // 0x8008DE64: nop

L_8008DE68:
    // 0x8008DE68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DE6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008DE70: jr          $ra
    // 0x8008DE74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008DE74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8008DEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DEC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008DECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008DED0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008DED4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8008DED8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8008DEDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008DEE0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8008DEE4: lhu         $t8, 0x3A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3A);
    // 0x8008DEE8: lw          $t7, 0x3A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3A8);
    // 0x8008DEEC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008DEF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008DEF4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008DEF8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8008DEFC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8008DF00: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008DF04: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008DF08: jal         0x800BD1FC
    // 0x8008DF0C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8008DF0C: nop

    after_0:
    // 0x8008DF10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008DF14: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8008DF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008DF1C: jal         0x800BD218
    // 0x8008DF20: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8008DF20: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_1:
    // 0x8008DF24: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8008DF28: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8008DF2C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8008DF30:
    // 0x8008DF30: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DF34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008DF38: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8008DF3C: nop

    // 0x8008DF40: beq         $t3, $at, L_8008DF50
    if (ctx->r11 == ctx->r1) {
        // 0x8008DF44: nop
    
            goto L_8008DF50;
    }
    // 0x8008DF44: nop

    // 0x8008DF48: bne         $t3, $zero, L_8008DF58
    if (ctx->r11 != 0) {
        // 0x8008DF4C: nop
    
            goto L_8008DF58;
    }
    // 0x8008DF4C: nop

L_8008DF50:
    // 0x8008DF50: b           L_8008DF78
    // 0x8008DF54: nop

        goto L_8008DF78;
    // 0x8008DF54: nop

L_8008DF58:
    // 0x8008DF58: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008DF5C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DF60: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8008DF64: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x8008DF68: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8008DF6C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8008DF70: bne         $at, $zero, L_8008DF30
    if (ctx->r1 != 0) {
        // 0x8008DF74: sw          $t5, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r13;
            goto L_8008DF30;
    }
    // 0x8008DF74: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8008DF78:
    // 0x8008DF78: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DF7C: nop

    // 0x8008DF80: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8008DF84: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8008DF88: b           L_8008DF98
    // 0x8008DF8C: nop

        goto L_8008DF98;
    // 0x8008DF8C: nop

    // 0x8008DF90: b           L_8008DF98
    // 0x8008DF94: nop

        goto L_8008DF98;
    // 0x8008DF94: nop

L_8008DF98:
    // 0x8008DF98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DF9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008DFA0: jr          $ra
    // 0x8008DFA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008DFA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80064044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006404C: jal         0x80061488
    // 0x80064050: addiu       $a0, $zero, 0x5BE
    ctx->r4 = ADD32(0, 0X5BE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064050: addiu       $a0, $zero, 0x5BE
    ctx->r4 = ADD32(0, 0X5BE);
    after_0:
    // 0x80064054: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80064058: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006405C: b           L_8006406C
    // 0x80064060: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006406C;
    // 0x80064060: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064064: b           L_8006406C
    // 0x80064068: nop

        goto L_8006406C;
    // 0x80064068: nop

L_8006406C:
    // 0x8006406C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064074: jr          $ra
    // 0x80064078: nop

    return;
    // 0x80064078: nop

;}
RECOMP_FUNC void func_80077938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077938: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007793C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077940: nop

    // 0x80077944: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077948: nop

    // 0x8007794C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077950: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077954: jr          $ra
    // 0x80077958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007795C: jr          $ra
    // 0x80077960: nop

    return;
    // 0x80077960: nop

    // 0x80077964: jr          $ra
    // 0x80077968: nop

    return;
    // 0x80077968: nop

;}
RECOMP_FUNC void func_800652C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800652C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800652C8: jal         0x8005F064
    // 0x800652CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800652CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x800652D0: b           L_800652E0
    // 0x800652D4: nop

        goto L_800652E0;
    // 0x800652D4: nop

    // 0x800652D8: b           L_800652E0
    // 0x800652DC: nop

        goto L_800652E0;
    // 0x800652DC: nop

L_800652E0:
    // 0x800652E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800652E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800652E8: jr          $ra
    // 0x800652EC: nop

    return;
    // 0x800652EC: nop

;}
RECOMP_FUNC void func_80073438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007343C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073440: jal         0x80061488
    // 0x80073444: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073444: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_0:
    // 0x80073448: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8007344C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80073450: b           L_80073460
    // 0x80073454: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073460;
    // 0x80073454: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073458: b           L_80073460
    // 0x8007345C: nop

        goto L_80073460;
    // 0x8007345C: nop

L_80073460:
    // 0x80073460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073468: jr          $ra
    // 0x8007346C: nop

    return;
    // 0x8007346C: nop

;}
RECOMP_FUNC void func_80031FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031FF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80031FF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031FFC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80032000: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80032004: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80032008: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8003200C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80032010:
    // 0x80032010: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80032014: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80032018: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003201C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80032020: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x80032024: nop

    // 0x80032028: beq         $t0, $zero, L_80032070
    if (ctx->r8 == 0) {
        // 0x8003202C: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_80032070;
    }
    // 0x8003202C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80032030: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80032034: nop

    // 0x80032038: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8003203C: nop

    // 0x80032040: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80032044: beq         $t3, $zero, L_80032054
    if (ctx->r11 == 0) {
        // 0x80032048: nop
    
            goto L_80032054;
    }
    // 0x80032048: nop

    // 0x8003204C: b           L_80032068
    // 0x80032050: nop

        goto L_80032068;
    // 0x80032050: nop

L_80032054:
    // 0x80032054: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80032058: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8003205C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80032060: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80032064: sw          $zero, 0x20C($t6)
    MEM_W(0X20C, ctx->r14) = 0;
L_80032068:
    // 0x80032068: b           L_80032080
    // 0x8003206C: nop

        goto L_80032080;
    // 0x8003206C: nop

L_80032070:
    // 0x80032070: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80032074: nop

    // 0x80032078: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003207C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_80032080:
    // 0x80032080: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80032084: nop

    // 0x80032088: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8003208C: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80032090: bne         $at, $zero, L_80032010
    if (ctx->r1 != 0) {
        // 0x80032094: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80032010;
    }
    // 0x80032094: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80032098: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8003209C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800320A0: bne         $t2, $at, L_800320BC
    if (ctx->r10 != ctx->r1) {
        // 0x800320A4: nop
    
            goto L_800320BC;
    }
    // 0x800320A4: nop

    // 0x800320A8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800320AC: nop

    // 0x800320B0: sw          $zero, 0x1A0($t3)
    MEM_W(0X1A0, ctx->r11) = 0;
    // 0x800320B4: b           L_8003236C
    // 0x800320B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8003236C;
    // 0x800320B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800320BC:
    // 0x800320BC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800320C0: nop

    // 0x800320C4: lw          $t4, 0x1A8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X1A8);
    // 0x800320C8: nop

    // 0x800320CC: andi        $t7, $t4, 0x100
    ctx->r15 = ctx->r12 & 0X100;
    // 0x800320D0: bne         $t7, $zero, L_8003235C
    if (ctx->r15 != 0) {
        // 0x800320D4: nop
    
            goto L_8003235C;
    }
    // 0x800320D4: nop

    // 0x800320D8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800320DC: nop

    // 0x800320E0: lhu         $t8, 0x208($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X208);
    // 0x800320E4: nop

    // 0x800320E8: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800320EC: beq         $at, $zero, L_8003235C
    if (ctx->r1 == 0) {
        // 0x800320F0: nop
    
            goto L_8003235C;
    }
    // 0x800320F0: nop

    // 0x800320F4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800320F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800320FC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80032100: lwc1        $f4, 0x1E8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1E8);
    // 0x80032104: nop

    // 0x80032108: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003210C: swc1        $f20, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f20.u32l;
    // 0x80032110: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80032114: nop

    // 0x80032118: lwc1        $f8, 0x1EC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1EC);
    // 0x8003211C: nop

    // 0x80032120: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80032124: nop

    // 0x80032128: bc1f        L_8003235C
    if (!c1cs) {
        // 0x8003212C: nop
    
            goto L_8003235C;
    }
    // 0x8003212C: nop

    // 0x80032130: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80032134: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80032138: nop

    // 0x8003213C: swc1        $f10, 0x1E8($t1)
    MEM_W(0X1E8, ctx->r9) = ctx->f10.u32l;
    // 0x80032140: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80032144: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80032148: lwc1        $f16, 0x1EC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X1EC);
    // 0x8003214C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80032150: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80032154: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80032158: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8003215C: nop

    // 0x80032160: bc1f        L_8003227C
    if (!c1cs) {
        // 0x80032164: nop
    
            goto L_8003227C;
    }
    // 0x80032164: nop

    // 0x80032168: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8003216C: nop

    // 0x80032170: lw          $a0, 0x1AC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X1AC);
    // 0x80032174: jal         0x800BB448
    // 0x80032178: nop

    func_800BB448(rdram, ctx);
        goto after_0;
    // 0x80032178: nop

    after_0:
    // 0x8003217C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80032180: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80032184: nop

    // 0x80032188: beq         $t5, $zero, L_8003227C
    if (ctx->r13 == 0) {
        // 0x8003218C: nop
    
            goto L_8003227C;
    }
    // 0x8003218C: nop

    // 0x80032190: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80032194: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80032198: lhu         $t7, 0x208($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X208);
    // 0x8003219C: lwc1        $f6, 0x1F0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X1F0);
    // 0x800321A0: sll         $t6, $t7, 11
    ctx->r14 = S32(ctx->r15 << 11);
    // 0x800321A4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800321A8: nop

    // 0x800321AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800321B0: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800321B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800321B8: nop

    // 0x800321BC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800321C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800321C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800321C8: nop

    // 0x800321CC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800321D0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800321D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800321D8: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x800321DC: nop

    // 0x800321E0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800321E4: nop

    // 0x800321E8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800321EC: nop

    // 0x800321F0: slti        $at, $t2, 0x1000
    ctx->r1 = SIGNED(ctx->r10) < 0X1000 ? 1 : 0;
    // 0x800321F4: beq         $at, $zero, L_80032208
    if (ctx->r1 == 0) {
        // 0x800321F8: nop
    
            goto L_80032208;
    }
    // 0x800321F8: nop

    // 0x800321FC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80032200: addiu       $t3, $zero, 0x1000
    ctx->r11 = ADD32(0, 0X1000);
    // 0x80032204: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
L_80032208:
    // 0x80032208: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003220C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80032210: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003221C: lwc1        $f4, 0x1F4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1F4);
    // 0x80032220: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80032224: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80032228: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8003222C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032230: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80032234: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80032238: sb          $t9, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = ctx->r25;
    // 0x8003223C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80032240: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80032244: lhu         $t3, 0x208($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X208);
    // 0x80032248: nop

    // 0x8003224C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80032250: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80032254: sw          $t1, 0x20C($t4)
    MEM_W(0X20C, ctx->r12) = ctx->r9;
    // 0x80032258: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8003225C: nop

    // 0x80032260: lhu         $t6, 0x208($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X208);
    // 0x80032264: nop

    // 0x80032268: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8003226C: sh          $t8, 0x208($t7)
    MEM_H(0X208, ctx->r15) = ctx->r24;
    // 0x80032270: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80032274: jal         0x800BB4B4
    // 0x80032278: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BB4B4(rdram, ctx);
        goto after_1;
    // 0x80032278: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
L_8003227C:
    // 0x8003227C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80032280: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80032284: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80032288: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003228C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032290: lwc1        $f6, 0x1F0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1F0);
    // 0x80032294: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80032298: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8003229C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800322A0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800322A4: bgez        $t3, L_800322B4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800322A8: sra         $t2, $t3, 8
        ctx->r10 = S32(SIGNED(ctx->r11) >> 8);
            goto L_800322B4;
    }
    // 0x800322A8: sra         $t2, $t3, 8
    ctx->r10 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800322AC: addiu       $at, $t3, 0xFF
    ctx->r1 = ADD32(ctx->r11, 0XFF);
    // 0x800322B0: sra         $t2, $at, 8
    ctx->r10 = S32(SIGNED(ctx->r1) >> 8);
L_800322B4:
    // 0x800322B4: subu        $t1, $t5, $t2
    ctx->r9 = SUB32(ctx->r13, ctx->r10);
    // 0x800322B8: bgez        $t1, L_800322C8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800322BC: sra         $t4, $t1, 3
        ctx->r12 = S32(SIGNED(ctx->r9) >> 3);
            goto L_800322C8;
    }
    // 0x800322BC: sra         $t4, $t1, 3
    ctx->r12 = S32(SIGNED(ctx->r9) >> 3);
    // 0x800322C0: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x800322C4: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800322C8:
    // 0x800322C8: blez        $t4, L_800322FC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800322CC: nop
    
            goto L_800322FC;
    }
    // 0x800322CC: nop

    // 0x800322D0: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x800322D4: subu        $t8, $t6, $t2
    ctx->r24 = SUB32(ctx->r14, ctx->r10);
    // 0x800322D8: bgez        $t8, L_800322E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800322DC: sra         $t7, $t8, 3
        ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
            goto L_800322E8;
    }
    // 0x800322DC: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800322E0: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x800322E4: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800322E8:
    // 0x800322E8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800322EC: nop

    // 0x800322F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800322F4: b           L_8003235C
    // 0x800322F8: swc1        $f18, 0x1EC($t9)
    MEM_W(0X1EC, ctx->r25) = ctx->f18.u32l;
        goto L_8003235C;
    // 0x800322F8: swc1        $f18, 0x1EC($t9)
    MEM_W(0X1EC, ctx->r25) = ctx->f18.u32l;
L_800322FC:
    // 0x800322FC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80032300: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80032304: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80032308: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003230C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032310: lwc1        $f4, 0x1F0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1F0);
    // 0x80032314: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80032318: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003231C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80032320: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80032324: bgez        $t5, L_80032334
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80032328: sra         $t1, $t5, 8
        ctx->r9 = S32(SIGNED(ctx->r13) >> 8);
            goto L_80032334;
    }
    // 0x80032328: sra         $t1, $t5, 8
    ctx->r9 = S32(SIGNED(ctx->r13) >> 8);
    // 0x8003232C: addiu       $at, $t5, 0xFF
    ctx->r1 = ADD32(ctx->r13, 0XFF);
    // 0x80032330: sra         $t1, $at, 8
    ctx->r9 = S32(SIGNED(ctx->r1) >> 8);
L_80032334:
    // 0x80032334: subu        $t6, $t4, $t1
    ctx->r14 = SUB32(ctx->r12, ctx->r9);
    // 0x80032338: bgez        $t6, L_80032348
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8003233C: sra         $t2, $t6, 3
        ctx->r10 = S32(SIGNED(ctx->r14) >> 3);
            goto L_80032348;
    }
    // 0x8003233C: sra         $t2, $t6, 3
    ctx->r10 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80032340: addiu       $at, $t6, 0x7
    ctx->r1 = ADD32(ctx->r14, 0X7);
    // 0x80032344: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_80032348:
    // 0x80032348: negu        $t8, $t2
    ctx->r24 = SUB32(0, ctx->r10);
    // 0x8003234C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80032350: nop

    // 0x80032354: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80032358: swc1        $f10, 0x1EC($t0)
    MEM_W(0X1EC, ctx->r8) = ctx->f10.u32l;
L_8003235C:
    // 0x8003235C: b           L_8003236C
    // 0x80032360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003236C;
    // 0x80032360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032364: b           L_8003236C
    // 0x80032368: nop

        goto L_8003236C;
    // 0x80032368: nop

L_8003236C:
    // 0x8003236C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032370: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80032374: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80032378: jr          $ra
    // 0x8003237C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003237C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80051380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051384: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80051388: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005138C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80051390: jal         0x80056118
    // 0x80051394: nop

    func_80056118(rdram, ctx);
        goto after_0;
    // 0x80051394: nop

    after_0:
    // 0x80051398: bne         $v0, $zero, L_800513A8
    if (ctx->r2 != 0) {
        // 0x8005139C: nop
    
            goto L_800513A8;
    }
    // 0x8005139C: nop

    // 0x800513A0: b           L_80051508
    // 0x800513A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x800513A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800513A8:
    // 0x800513A8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800513AC: lh          $s0, 0x10F0($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X10F0);
    // 0x800513B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800513B4: beq         $s0, $at, L_800513D0
    if (ctx->r16 == ctx->r1) {
        // 0x800513B8: nop
    
            goto L_800513D0;
    }
    // 0x800513B8: nop

    // 0x800513BC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800513C0: beq         $s0, $at, L_8005148C
    if (ctx->r16 == ctx->r1) {
        // 0x800513C4: nop
    
            goto L_8005148C;
    }
    // 0x800513C4: nop

    // 0x800513C8: b           L_800514EC
    // 0x800513CC: nop

        goto L_800514EC;
    // 0x800513CC: nop

L_800513D0:
    // 0x800513D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800513D4: lw          $t6, 0x11A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11A0);
    // 0x800513D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800513DC: lh          $s0, 0x0($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X0);
    // 0x800513E0: nop

    // 0x800513E4: beq         $s0, $at, L_8005140C
    if (ctx->r16 == ctx->r1) {
        // 0x800513E8: nop
    
            goto L_8005140C;
    }
    // 0x800513E8: nop

    // 0x800513EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800513F0: beq         $s0, $at, L_80051444
    if (ctx->r16 == ctx->r1) {
        // 0x800513F4: nop
    
            goto L_80051444;
    }
    // 0x800513F4: nop

    // 0x800513F8: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800513FC: beq         $s0, $at, L_8005147C
    if (ctx->r16 == ctx->r1) {
        // 0x80051400: nop
    
            goto L_8005147C;
    }
    // 0x80051400: nop

    // 0x80051404: b           L_80051484
    // 0x80051408: nop

        goto L_80051484;
    // 0x80051408: nop

L_8005140C:
    // 0x8005140C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051410: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80051414: nop

    // 0x80051418: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8005141C: nop

    // 0x80051420: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x80051424: beq         $at, $zero, L_8005143C
    if (ctx->r1 == 0) {
        // 0x80051428: nop
    
            goto L_8005143C;
    }
    // 0x80051428: nop

    // 0x8005142C: b           L_80051508
    // 0x80051430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x80051430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80051434: b           L_80051444
    // 0x80051438: nop

        goto L_80051444;
    // 0x80051438: nop

L_8005143C:
    // 0x8005143C: b           L_800514EC
    // 0x80051440: nop

        goto L_800514EC;
    // 0x80051440: nop

L_80051444:
    // 0x80051444: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80051448: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8005144C: nop

    // 0x80051450: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x80051454: nop

    // 0x80051458: slti        $at, $t0, 0x3D
    ctx->r1 = SIGNED(ctx->r8) < 0X3D ? 1 : 0;
    // 0x8005145C: beq         $at, $zero, L_80051474
    if (ctx->r1 == 0) {
        // 0x80051460: nop
    
            goto L_80051474;
    }
    // 0x80051460: nop

    // 0x80051464: b           L_80051508
    // 0x80051468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x80051468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005146C: b           L_8005147C
    // 0x80051470: nop

        goto L_8005147C;
    // 0x80051470: nop

L_80051474:
    // 0x80051474: b           L_800514EC
    // 0x80051478: nop

        goto L_800514EC;
    // 0x80051478: nop

L_8005147C:
    // 0x8005147C: b           L_80051508
    // 0x80051480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x80051480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80051484:
    // 0x80051484: b           L_800514EC
    // 0x80051488: nop

        goto L_800514EC;
    // 0x80051488: nop

L_8005148C:
    // 0x8005148C: jal         0x80061F08
    // 0x80051490: nop

    func_80061F08(rdram, ctx);
        goto after_1;
    // 0x80051490: nop

    after_1:
    // 0x80051494: beq         $v0, $zero, L_800514A4
    if (ctx->r2 == 0) {
        // 0x80051498: nop
    
            goto L_800514A4;
    }
    // 0x80051498: nop

    // 0x8005149C: b           L_800514EC
    // 0x800514A0: nop

        goto L_800514EC;
    // 0x800514A0: nop

L_800514A4:
    // 0x800514A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800514A8: lw          $a0, 0x11A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11A8);
    // 0x800514AC: jal         0x80056C60
    // 0x800514B0: nop

    func_80056C60(rdram, ctx);
        goto after_2;
    // 0x800514B0: nop

    after_2:
    // 0x800514B4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800514B8: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800514BC: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800514C0: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
    // 0x800514C4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800514C8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800514CC: lh          $t3, 0x2C5C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2C5C);
    // 0x800514D0: nop

    // 0x800514D4: beq         $t3, $zero, L_800514E4
    if (ctx->r11 == 0) {
        // 0x800514D8: nop
    
            goto L_800514E4;
    }
    // 0x800514D8: nop

    // 0x800514DC: b           L_80051508
    // 0x800514E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80051508;
    // 0x800514E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800514E4:
    // 0x800514E4: b           L_800514EC
    // 0x800514E8: nop

        goto L_800514EC;
    // 0x800514E8: nop

L_800514EC:
    // 0x800514EC: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800514F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800514F4: sh          $t4, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r12;
    // 0x800514F8: b           L_80051508
    // 0x800514FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051508;
    // 0x800514FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80051500: b           L_80051508
    // 0x80051504: nop

        goto L_80051508;
    // 0x80051504: nop

L_80051508:
    // 0x80051508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005150C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80051510: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80051514: jr          $ra
    // 0x80051518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80051518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800BDC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDC70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BDC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDC78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BDC7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800BDC80: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800BDC84: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800BDC88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BDC8C: lw          $t6, 0x2584($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2584);
    // 0x800BDC90: nop

    // 0x800BDC94: beq         $t6, $zero, L_800BDCAC
    if (ctx->r14 == 0) {
        // 0x800BDC98: nop
    
            goto L_800BDCAC;
    }
    // 0x800BDC98: nop

    // 0x800BDC9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BDCA0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800BDCA4: jal         0x800BD8D4
    // 0x800BDCA8: nop

    func_800BD8D4(rdram, ctx);
        goto after_0;
    // 0x800BDCA8: nop

    after_0:
L_800BDCAC:
    // 0x800BDCAC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BDCB0: lw          $a1, 0x168C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X168C);
    // 0x800BDCB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BDCB8: jal         0x800BD9D0
    // 0x800BDCBC: nop

    func_800BD9D0(rdram, ctx);
        goto after_1;
    // 0x800BDCBC: nop

    after_1:
    // 0x800BDCC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BDCC4: lw          $t7, 0x2584($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2584);
    // 0x800BDCC8: nop

    // 0x800BDCCC: beq         $t7, $zero, L_800BDD80
    if (ctx->r15 == 0) {
        // 0x800BDCD0: nop
    
            goto L_800BDD80;
    }
    // 0x800BDCD0: nop

    // 0x800BDCD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDCD8: sh          $zero, 0x24FC($at)
    MEM_H(0X24FC, ctx->r1) = 0;
    // 0x800BDCDC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800BDCE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDCE4: sw          $t8, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r24;
    // 0x800BDCE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDCEC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x800BDCF0: sw          $t9, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r25;
    // 0x800BDCF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDCF8: sw          $zero, 0x251C($at)
    MEM_W(0X251C, ctx->r1) = 0;
    // 0x800BDCFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BDD00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD04: sw          $t0, 0x2528($at)
    MEM_W(0X2528, ctx->r1) = ctx->r8;
    // 0x800BDD08: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BDD0C: lhu         $t1, 0x24FC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X24FC);
    // 0x800BDD10: nop

    // 0x800BDD14: beq         $t1, $zero, L_800BDD30
    if (ctx->r9 == 0) {
        // 0x800BDD18: nop
    
            goto L_800BDD30;
    }
    // 0x800BDD18: nop

    // 0x800BDD1C: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x800BDD20: addiu       $t2, $t2, -0x5800
    ctx->r10 = ADD32(ctx->r10, -0X5800);
    // 0x800BDD24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD28: b           L_800BDD40
    // 0x800BDD2C: sw          $t2, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r10;
        goto L_800BDD40;
    // 0x800BDD2C: sw          $t2, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r10;
L_800BDD30:
    // 0x800BDD30: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x800BDD34: addiu       $t3, $t3, 0x0
    ctx->r11 = ADD32(ctx->r11, 0X0);
    // 0x800BDD38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD3C: sw          $t3, 0x24D0($at)
    MEM_W(0X24D0, ctx->r1) = ctx->r11;
L_800BDD40:
    // 0x800BDD40: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800BDD44: lhu         $t4, 0x24FC($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X24FC);
    // 0x800BDD48: nop

    // 0x800BDD4C: beq         $t4, $zero, L_800BDD68
    if (ctx->r12 == 0) {
        // 0x800BDD50: nop
    
            goto L_800BDD68;
    }
    // 0x800BDD50: nop

    // 0x800BDD54: lui         $t5, 0x8020
    ctx->r13 = S32(0X8020 << 16);
    // 0x800BDD58: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x800BDD5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD60: b           L_800BDD78
    // 0x800BDD64: sw          $t5, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r13;
        goto L_800BDD78;
    // 0x800BDD64: sw          $t5, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r13;
L_800BDD68:
    // 0x800BDD68: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x800BDD6C: addiu       $t6, $t6, -0x5800
    ctx->r14 = ADD32(ctx->r14, -0X5800);
    // 0x800BDD70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDD74: sw          $t6, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->r14;
L_800BDD78:
    // 0x800BDD78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BDD7C: sw          $zero, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = 0;
L_800BDD80:
    // 0x800BDD80: jal         0x8008E630
    // 0x800BDD84: nop

    func_8008E630(rdram, ctx);
        goto after_2;
    // 0x800BDD84: nop

    after_2:
    // 0x800BDD88: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BDD8C: lw          $a0, 0x24D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D0);
    // 0x800BDD90: jal         0x8008ECCC
    // 0x800BDD94: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_3;
    // 0x800BDD94: nop

    after_3:
    // 0x800BDD98: jal         0x800C15C0
    // 0x800BDD9C: nop

    MtxUtil_InitStack(rdram, ctx);
        goto after_4;
    // 0x800BDD9C: nop

    after_4:
    // 0x800BDDA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BDDA4:
    // 0x800BDDA4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDDA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BDDAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BDDB0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDDB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDDB8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BDDBC: swc1        $f4, 0x2538($at)
    MEM_W(0X2538, ctx->r1) = ctx->f4.u32l;
    // 0x800BDDC0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDDC4: nop

    // 0x800BDDC8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BDDCC: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800BDDD0: bne         $at, $zero, L_800BDDA4
    if (ctx->r1 != 0) {
        // 0x800BDDD4: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800BDDA4;
    }
    // 0x800BDDD4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800BDDD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BDDDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BDDE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDDE4: swc1        $f6, 0x257C($at)
    MEM_W(0X257C, ctx->r1) = ctx->f6.u32l;
    // 0x800BDDE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDDEC: sw          $zero, 0x2554($at)
    MEM_W(0X2554, ctx->r1) = 0;
    // 0x800BDDF0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800BDDF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDDF8: sw          $t1, 0x2574($at)
    MEM_W(0X2574, ctx->r1) = ctx->r9;
    // 0x800BDDFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDE00: sw          $zero, 0x258C($at)
    MEM_W(0X258C, ctx->r1) = 0;
    // 0x800BDE04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800BDE08: jal         0x80099660
    // 0x800BDE0C: addiu       $a0, $a0, 0x5E8
    ctx->r4 = ADD32(ctx->r4, 0X5E8);
    func_80099660(rdram, ctx);
        goto after_5;
    // 0x800BDE0C: addiu       $a0, $a0, 0x5E8
    ctx->r4 = ADD32(ctx->r4, 0X5E8);
    after_5:
    // 0x800BDE10: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800BDE14: nop

    // 0x800BDE18: beq         $t2, $zero, L_800BDE2C
    if (ctx->r10 == 0) {
        // 0x800BDE1C: nop
    
            goto L_800BDE2C;
    }
    // 0x800BDE1C: nop

    // 0x800BDE20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800BDE24: jal         0x800AF060
    // 0x800BDE28: nop

    func_800AF060(rdram, ctx);
        goto after_6;
    // 0x800BDE28: nop

    after_6:
L_800BDE2C:
    // 0x800BDE2C: jal         0x800A6440
    // 0x800BDE30: nop

    func_800A6440(rdram, ctx);
        goto after_7;
    // 0x800BDE30: nop

    after_7:
    // 0x800BDE34: jal         0x800AC890
    // 0x800BDE38: nop

    func_800AC890(rdram, ctx);
        goto after_8;
    // 0x800BDE38: nop

    after_8:
    // 0x800BDE3C: jal         0x800ABAC8
    // 0x800BDE40: nop

    func_800ABAC8(rdram, ctx);
        goto after_9;
    // 0x800BDE40: nop

    after_9:
    // 0x800BDE44: jal         0x800ACE50
    // 0x800BDE48: nop

    func_800ACE50(rdram, ctx);
        goto after_10;
    // 0x800BDE48: nop

    after_10:
    // 0x800BDE4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDE50: sw          $zero, 0x2584($at)
    MEM_W(0X2584, ctx->r1) = 0;
    // 0x800BDE54: b           L_800BDE5C
    // 0x800BDE58: nop

        goto L_800BDE5C;
    // 0x800BDE58: nop

L_800BDE5C:
    // 0x800BDE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDE60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BDE64: jr          $ra
    // 0x800BDE68: nop

    return;
    // 0x800BDE68: nop

;}
RECOMP_FUNC void func_800298A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800298A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800298A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800298AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800298B0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800298B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800298B8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800298BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800298C0: jal         0x80029204
    // 0x800298C4: nop

    func_80029204(rdram, ctx);
        goto after_0;
    // 0x800298C4: nop

    after_0:
    // 0x800298C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800298CC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800298D0: nop

    // 0x800298D4: bne         $t6, $zero, L_800298E4
    if (ctx->r14 != 0) {
        // 0x800298D8: nop
    
            goto L_800298E4;
    }
    // 0x800298D8: nop

    // 0x800298DC: b           L_800299B4
    // 0x800298E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800299B4;
    // 0x800298E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800298E4:
    // 0x800298E4: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x800298E8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800298EC: nop

    // 0x800298F0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800298F4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800298F8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800298FC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80029900: lh          $t1, 0x32($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X32);
    // 0x80029904: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80029908: nop

    // 0x8002990C: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80029910: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x80029914: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80029918: nop

    // 0x8002991C: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80029920: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80029924: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80029928: nop

    // 0x8002992C: swc1        $f4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f4.u32l;
    // 0x80029930: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80029934: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80029938: nop

    // 0x8002993C: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x80029940: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80029944: nop

    // 0x80029948: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x8002994C: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x80029950: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80029954: addiu       $t9, $t9, 0x1B18
    ctx->r25 = ADD32(ctx->r25, 0X1B18);
    // 0x80029958: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002995C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80029960: nop

    // 0x80029964: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80029968: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
    // 0x8002996C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80029970: lh          $a1, 0x32($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X32);
    // 0x80029974: lh          $a2, 0x36($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36);
    // 0x80029978: jal         0x800293EC
    // 0x8002997C: nop

    func_800293EC(rdram, ctx);
        goto after_1;
    // 0x8002997C: nop

    after_1:
    // 0x80029980: lh          $a0, 0x32($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X32);
    // 0x80029984: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x80029988: jal         0x800292B0
    // 0x8002998C: nop

    func_800292B0(rdram, ctx);
        goto after_2;
    // 0x8002998C: nop

    after_2:
    // 0x80029990: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80029994: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80029998: jal         0x800291B4
    // 0x8002999C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800291B4(rdram, ctx);
        goto after_3;
    // 0x8002999C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800299A0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800299A4: b           L_800299B4
    // 0x800299A8: nop

        goto L_800299B4;
    // 0x800299A8: nop

    // 0x800299AC: b           L_800299B4
    // 0x800299B0: nop

        goto L_800299B4;
    // 0x800299B0: nop

L_800299B4:
    // 0x800299B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800299B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800299BC: jr          $ra
    // 0x800299C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800299C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8009B530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B530: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x8009B534: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009B538: sw          $a0, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r4;
    // 0x8009B53C: sw          $a1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r5;
    // 0x8009B540: sw          $a2, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r6;
    // 0x8009B544: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009B548: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009B54C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B550: lw          $t6, 0x198($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X198);
    // 0x8009B554: nop

    // 0x8009B558: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009B55C: nop

    // 0x8009B560: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x8009B564: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B568: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009B56C: lw          $t0, 0x7250($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7250);
    // 0x8009B570: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x8009B574: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009B578: lw          $t2, 0x7258($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7258);
    // 0x8009B57C: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8009B580: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8009B584: sw          $t3, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r11;
    // 0x8009B588: lw          $t4, 0x1A0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A0);
    // 0x8009B58C: nop

    // 0x8009B590: beq         $t4, $zero, L_8009B608
    if (ctx->r12 == 0) {
        // 0x8009B594: nop
    
            goto L_8009B608;
    }
    // 0x8009B594: nop

    // 0x8009B598: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009B59C: lw          $t6, 0x70E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70E4);
    // 0x8009B5A0: lw          $t5, 0x1A0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A0);
    // 0x8009B5A4: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8009B5A8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8009B5AC: sw          $t8, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r24;
    // 0x8009B5B0: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B5B4: lw          $t1, 0x1A0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A0);
    // 0x8009B5B8: lh          $t0, 0x11E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X11E);
    // 0x8009B5BC: lwc1        $f8, 0xE8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x8009B5C0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8009B5C4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8009B5C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009B5CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B5D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009B5D4: nop

    // 0x8009B5D8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009B5DC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8009B5E0: nop

    // 0x8009B5E4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8009B5E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009B5EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009B5F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009B5F4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8009B5F8: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8009B5FC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8009B600: b           L_8009B620
    // 0x8009B604: sh          $t3, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r11;
        goto L_8009B620;
    // 0x8009B604: sh          $t3, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r11;
L_8009B608:
    // 0x8009B608: sw          $zero, 0x148($sp)
    MEM_W(0X148, ctx->r29) = 0;
    // 0x8009B60C: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B610: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009B614: lh          $t6, 0x11E($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X11E);
    // 0x8009B618: nop

    // 0x8009B61C: sh          $t6, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r14;
L_8009B620:
    // 0x8009B620: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x8009B624: nop

    // 0x8009B628: andi        $t7, $t5, 0x40
    ctx->r15 = ctx->r13 & 0X40;
    // 0x8009B62C: bne         $t7, $zero, L_8009B670
    if (ctx->r15 != 0) {
        // 0x8009B630: nop
    
            goto L_8009B670;
    }
    // 0x8009B630: nop

    // 0x8009B634: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B638: nop

    // 0x8009B63C: lwc1        $f6, 0xF4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x8009B640: lwc1        $f8, 0xFC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x8009B644: nop

    // 0x8009B648: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009B64C: swc1        $f10, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f10.u32l;
    // 0x8009B650: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B654: nop

    // 0x8009B658: lwc1        $f16, 0xF8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x8009B65C: lwc1        $f18, 0xFC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XFC);
    // 0x8009B660: nop

    // 0x8009B664: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009B668: b           L_8009B778
    // 0x8009B66C: swc1        $f4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f4.u32l;
        goto L_8009B778;
    // 0x8009B66C: swc1        $f4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f4.u32l;
L_8009B670:
    // 0x8009B670: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x8009B674: nop

    // 0x8009B678: beq         $t0, $zero, L_8009B720
    if (ctx->r8 == 0) {
        // 0x8009B67C: nop
    
            goto L_8009B720;
    }
    // 0x8009B67C: nop

    // 0x8009B680: jal         0x800C1680
    // 0x8009B684: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x8009B684: nop

    after_0:
    // 0x8009B688: lw          $a0, 0x148($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X148);
    // 0x8009B68C: jal         0x800C2B20
    // 0x8009B690: nop

    MtxUtil_SetCurrentFromMtx(rdram, ctx);
        goto after_1;
    // 0x8009B690: nop

    after_1:
    // 0x8009B694: lw          $a0, 0x19C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B698: jal         0x800C1D44
    // 0x8009B69C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_2;
    // 0x8009B69C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_2:
    // 0x8009B6A0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8009B6A4: jal         0x800C1A84
    // 0x8009B6A8: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_3;
    // 0x8009B6A8: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_3:
    // 0x8009B6AC: jal         0x800C1A28
    // 0x8009B6B0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_4;
    // 0x8009B6B0: nop

    after_4:
    // 0x8009B6B4: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B6B8: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8009B6BC: lwc1        $f6, 0xF4($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XF4);
    // 0x8009B6C0: lwc1        $f8, 0xFC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XFC);
    // 0x8009B6C4: addiu       $t2, $t2, 0x6BC8
    ctx->r10 = ADD32(ctx->r10, 0X6BC8);
    // 0x8009B6C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009B6CC: lwc1        $f16, 0x38($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X38);
    // 0x8009B6D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009B6D4: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009B6D8: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8009B6DC: nop

    // 0x8009B6E0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009B6E4: swc1        $f6, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f6.u32l;
    // 0x8009B6E8: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B6EC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8009B6F0: lwc1        $f8, 0xF8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XF8);
    // 0x8009B6F4: lwc1        $f16, 0xFC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XFC);
    // 0x8009B6F8: addiu       $t4, $t4, 0x6BC8
    ctx->r12 = ADD32(ctx->r12, 0X6BC8);
    // 0x8009B6FC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009B700: lwc1        $f18, 0x38($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X38);
    // 0x8009B704: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009B708: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009B70C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8009B710: nop

    // 0x8009B714: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009B718: b           L_8009B778
    // 0x8009B71C: swc1        $f8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f8.u32l;
        goto L_8009B778;
    // 0x8009B71C: swc1        $f8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f8.u32l;
L_8009B720:
    // 0x8009B720: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B724: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009B728: lwc1        $f16, 0xF4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XF4);
    // 0x8009B72C: lwc1        $f18, 0xFC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XFC);
    // 0x8009B730: lwc1        $f4, 0xB8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XB8);
    // 0x8009B734: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009B738: lwc1        $f8, 0x7218($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009B73C: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8009B740: nop

    // 0x8009B744: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009B748: swc1        $f16, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f16.u32l;
    // 0x8009B74C: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B750: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009B754: lwc1        $f18, 0xF8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x8009B758: lwc1        $f4, 0xFC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XFC);
    // 0x8009B75C: lwc1        $f6, 0xB8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XB8);
    // 0x8009B760: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009B764: lwc1        $f16, 0x7218($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009B768: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8009B76C: nop

    // 0x8009B770: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009B774: swc1        $f18, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f18.u32l;
L_8009B778:
    // 0x8009B778: jal         0x800C1754
    // 0x8009B77C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_5;
    // 0x8009B77C: nop

    after_5:
    // 0x8009B780: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x8009B784: nop

    // 0x8009B788: beq         $t7, $zero, L_8009B79C
    if (ctx->r15 == 0) {
        // 0x8009B78C: nop
    
            goto L_8009B79C;
    }
    // 0x8009B78C: nop

    // 0x8009B790: lw          $a0, 0x148($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X148);
    // 0x8009B794: jal         0x800C2B20
    // 0x8009B798: nop

    MtxUtil_SetCurrentFromMtx(rdram, ctx);
        goto after_6;
    // 0x8009B798: nop

    after_6:
L_8009B79C:
    // 0x8009B79C: lw          $a0, 0x19C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B7A0: jal         0x800C1D44
    // 0x8009B7A4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_7;
    // 0x8009B7A4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_7:
    // 0x8009B7A8: lwc1        $f12, 0x150($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009B7AC: lwc1        $f14, 0x14C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009B7B0: jal         0x800C2948
    // 0x8009B7B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_8;
    // 0x8009B7B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_8:
    // 0x8009B7B8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009B7BC: lw          $t9, 0x70E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70E4);
    // 0x8009B7C0: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B7C4: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x8009B7C8: jal         0x800C2AE8
    // 0x8009B7CC: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_9;
    // 0x8009B7CC: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    after_9:
    // 0x8009B7D0: jal         0x800C1A28
    // 0x8009B7D4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_10;
    // 0x8009B7D4: nop

    after_10:
    // 0x8009B7D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009B7DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009B7E0: nop

    // 0x8009B7E4: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
    // 0x8009B7E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009B7EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009B7F0: nop

    // 0x8009B7F4: swc1        $f6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f6.u32l;
    // 0x8009B7F8: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B7FC: nop

    // 0x8009B800: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x8009B804: nop

    // 0x8009B808: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8009B80C: beq         $t3, $zero, L_8009B824
    if (ctx->r11 == 0) {
        // 0x8009B810: nop
    
            goto L_8009B824;
    }
    // 0x8009B810: nop

    // 0x8009B814: lwc1        $f10, 0x150($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009B818: nop

    // 0x8009B81C: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x8009B820: swc1        $f8, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f8.u32l;
L_8009B824:
    // 0x8009B824: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B828: nop

    // 0x8009B82C: lw          $t6, 0xC0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC0);
    // 0x8009B830: nop

    // 0x8009B834: andi        $t5, $t6, 0x2
    ctx->r13 = ctx->r14 & 0X2;
    // 0x8009B838: beq         $t5, $zero, L_8009B850
    if (ctx->r13 == 0) {
        // 0x8009B83C: nop
    
            goto L_8009B850;
    }
    // 0x8009B83C: nop

    // 0x8009B840: lwc1        $f16, 0x14C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009B844: nop

    // 0x8009B848: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8009B84C: swc1        $f18, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f18.u32l;
L_8009B850:
    // 0x8009B850: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B854: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009B858: lw          $t9, 0x128($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X128);
    // 0x8009B85C: nop

    // 0x8009B860: sw          $t9, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r25;
    // 0x8009B864: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009B868: nop

    // 0x8009B86C: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x8009B870: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009B874: sw          $t8, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r24;
    // 0x8009B878: lw          $t2, 0x144($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X144);
    // 0x8009B87C: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x8009B880: ori         $t1, $t1, 0x1402
    ctx->r9 = ctx->r9 | 0X1402;
    // 0x8009B884: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009B888: lw          $t3, 0x144($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X144);
    // 0x8009B88C: nop

    // 0x8009B890: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8009B894: lw          $t4, 0x194($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X194);
    // 0x8009B898: nop

    // 0x8009B89C: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x8009B8A0: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009B8A4: sw          $t4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r12;
    // 0x8009B8A8: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x8009B8AC: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8009B8B0: ori         $t5, $t5, 0x201
    ctx->r13 = ctx->r13 | 0X201;
    // 0x8009B8B4: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8009B8B8: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x8009B8BC: nop

    // 0x8009B8C0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009B8C4: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009B8C8: nop

    // 0x8009B8CC: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x8009B8D0: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009B8D4: sw          $t8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r24;
    // 0x8009B8D8: lw          $t2, 0x13C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X13C);
    // 0x8009B8DC: lui         $t1, 0x106
    ctx->r9 = S32(0X106 << 16);
    // 0x8009B8E0: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8009B8E4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009B8E8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009B8EC: lw          $t4, 0x70E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70E4);
    // 0x8009B8F0: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B8F4: lw          $t7, 0x13C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X13C);
    // 0x8009B8F8: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x8009B8FC: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8009B900: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8009B904: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8009B908: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009B90C: lh          $t8, 0x116($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X116);
    // 0x8009B910: nop

    // 0x8009B914: beq         $t8, $at, L_8009D154
    if (ctx->r24 == ctx->r1) {
        // 0x8009B918: nop
    
            goto L_8009D154;
    }
    // 0x8009B918: nop

    // 0x8009B91C: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009B920: nop

    // 0x8009B924: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8009B928: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x8009B92C: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    // 0x8009B930: lw          $t4, 0x138($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X138);
    // 0x8009B934: lui         $t2, 0xBB00
    ctx->r10 = S32(0XBB00 << 16);
    // 0x8009B938: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x8009B93C: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8009B940: lw          $t6, 0x138($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X138);
    // 0x8009B944: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8009B948: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x8009B94C: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8009B950: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x8009B954: nop

    // 0x8009B958: andi        $t7, $t5, 0x20
    ctx->r15 = ctx->r13 & 0X20;
    // 0x8009B95C: beq         $t7, $zero, L_8009B9D4
    if (ctx->r15 == 0) {
        // 0x8009B960: nop
    
            goto L_8009B9D4;
    }
    // 0x8009B960: nop

    // 0x8009B964: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009B968: nop

    // 0x8009B96C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8009B970: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
    // 0x8009B974: sw          $t9, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r25;
    // 0x8009B978: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x8009B97C: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x8009B980: ori         $t0, $t0, 0xFE24
    ctx->r8 = ctx->r8 | 0XFE24;
    // 0x8009B984: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009B988: lw          $t4, 0x134($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X134);
    // 0x8009B98C: lui         $t2, 0xFF30
    ctx->r10 = S32(0XFF30 << 16);
    // 0x8009B990: ori         $t2, $t2, 0xF3FF
    ctx->r10 = ctx->r10 | 0XF3FF;
    // 0x8009B994: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8009B998: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009B99C: nop

    // 0x8009B9A0: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8009B9A4: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009B9A8: sw          $t3, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r11;
    // 0x8009B9AC: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x8009B9B0: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8009B9B4: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x8009B9B8: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8009B9BC: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x8009B9C0: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x8009B9C4: ori         $t9, $t9, 0x233
    ctx->r25 = ctx->r25 | 0X233;
    // 0x8009B9C8: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8009B9CC: b           L_8009BAC0
    // 0x8009B9D0: nop

        goto L_8009BAC0;
    // 0x8009B9D0: nop

L_8009B9D4:
    // 0x8009B9D4: lw          $t0, 0x168($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X168);
    // 0x8009B9D8: nop

    // 0x8009B9DC: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x8009B9E0: beq         $t1, $zero, L_8009BA58
    if (ctx->r9 == 0) {
        // 0x8009B9E4: nop
    
            goto L_8009BA58;
    }
    // 0x8009B9E4: nop

    // 0x8009B9E8: lw          $t2, 0x194($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X194);
    // 0x8009B9EC: nop

    // 0x8009B9F0: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8009B9F4: sw          $t4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r12;
    // 0x8009B9F8: sw          $t2, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r10;
    // 0x8009B9FC: lw          $t6, 0x12C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X12C);
    // 0x8009BA00: lui         $t3, 0xFCFF
    ctx->r11 = S32(0XFCFF << 16);
    // 0x8009BA04: ori         $t3, $t3, 0xFE24
    ctx->r11 = ctx->r11 | 0XFE24;
    // 0x8009BA08: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8009BA0C: lw          $t7, 0x12C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X12C);
    // 0x8009BA10: lui         $t5, 0xFF30
    ctx->r13 = S32(0XFF30 << 16);
    // 0x8009BA14: ori         $t5, $t5, 0xF3FF
    ctx->r13 = ctx->r13 | 0XF3FF;
    // 0x8009BA18: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8009BA1C: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009BA20: nop

    // 0x8009BA24: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8009BA28: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
    // 0x8009BA2C: sw          $t9, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r25;
    // 0x8009BA30: lw          $t1, 0x128($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X128);
    // 0x8009BA34: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x8009BA38: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x8009BA3C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009BA40: lw          $t4, 0x128($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X128);
    // 0x8009BA44: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x8009BA48: ori         $t2, $t2, 0x4A50
    ctx->r10 = ctx->r10 | 0X4A50;
    // 0x8009BA4C: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8009BA50: b           L_8009BAC0
    // 0x8009BA54: nop

        goto L_8009BAC0;
    // 0x8009BA54: nop

L_8009BA58:
    // 0x8009BA58: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009BA5C: nop

    // 0x8009BA60: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8009BA64: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009BA68: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x8009BA6C: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x8009BA70: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x8009BA74: ori         $t5, $t5, 0xFE24
    ctx->r13 = ctx->r13 | 0XFE24;
    // 0x8009BA78: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8009BA7C: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8009BA80: lui         $t9, 0xFF30
    ctx->r25 = S32(0XFF30 << 16);
    // 0x8009BA84: ori         $t9, $t9, 0xF3FF
    ctx->r25 = ctx->r25 | 0XF3FF;
    // 0x8009BA88: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8009BA8C: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009BA90: nop

    // 0x8009BA94: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8009BA98: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x8009BA9C: sw          $t0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r8;
    // 0x8009BAA0: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x8009BAA4: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8009BAA8: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8009BAAC: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8009BAB0: lw          $t6, 0x120($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X120);
    // 0x8009BAB4: lui         $t3, 0x55
    ctx->r11 = S32(0X55 << 16);
    // 0x8009BAB8: ori         $t3, $t3, 0x3078
    ctx->r11 = ctx->r11 | 0X3078;
    // 0x8009BABC: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
L_8009BAC0:
    // 0x8009BAC0: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x8009BAC4: nop

    // 0x8009BAC8: andi        $t7, $t5, 0x800
    ctx->r15 = ctx->r13 & 0X800;
    // 0x8009BACC: bne         $t7, $zero, L_8009BB34
    if (ctx->r15 != 0) {
        // 0x8009BAD0: nop
    
            goto L_8009BB34;
    }
    // 0x8009BAD0: nop

    // 0x8009BAD4: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009BAD8: nop

    // 0x8009BADC: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8009BAE0: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
    // 0x8009BAE4: sw          $t9, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r25;
    // 0x8009BAE8: lw          $t1, 0x11C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X11C);
    // 0x8009BAEC: lui         $t0, 0xB600
    ctx->r8 = S32(0XB600 << 16);
    // 0x8009BAF0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009BAF4: lw          $t4, 0x11C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X11C);
    // 0x8009BAF8: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x8009BAFC: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8009BB00: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009BB04: nop

    // 0x8009BB08: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8009BB0C: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009BB10: sw          $t3, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r11;
    // 0x8009BB14: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x8009BB18: lui         $t5, 0xB700
    ctx->r13 = S32(0XB700 << 16);
    // 0x8009BB1C: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8009BB20: lw          $t8, 0x118($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X118);
    // 0x8009BB24: addiu       $t9, $zero, 0x205
    ctx->r25 = ADD32(0, 0X205);
    // 0x8009BB28: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8009BB2C: b           L_8009BB60
    // 0x8009BB30: nop

        goto L_8009BB60;
    // 0x8009BB30: nop

L_8009BB34:
    // 0x8009BB34: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009BB38: nop

    // 0x8009BB3C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8009BB40: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x8009BB44: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
    // 0x8009BB48: lw          $t4, 0x114($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X114);
    // 0x8009BB4C: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x8009BB50: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8009BB54: lw          $t6, 0x114($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X114);
    // 0x8009BB58: addiu       $t3, $zero, 0x2205
    ctx->r11 = ADD32(0, 0X2205);
    // 0x8009BB5C: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
L_8009BB60:
    // 0x8009BB60: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009BB64: nop

    // 0x8009BB68: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8009BB6C: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x8009BB70: sw          $t5, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r13;
    // 0x8009BB74: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
    // 0x8009BB78: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8009BB7C: ori         $t9, $t9, 0x1301
    ctx->r25 = ctx->r25 | 0X1301;
    // 0x8009BB80: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8009BB84: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
    // 0x8009BB88: lui         $t0, 0x8
    ctx->r8 = S32(0X8 << 16);
    // 0x8009BB8C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8009BB90: lw          $t2, 0x194($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X194);
    // 0x8009BB94: nop

    // 0x8009BB98: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8009BB9C: sw          $t4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r12;
    // 0x8009BBA0: sw          $t2, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r10;
    // 0x8009BBA4: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x8009BBA8: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8009BBAC: ori         $t3, $t3, 0x1102
    ctx->r11 = ctx->r11 | 0X1102;
    // 0x8009BBB0: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8009BBB4: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x8009BBB8: lui         $t5, 0x4
    ctx->r13 = S32(0X4 << 16);
    // 0x8009BBBC: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8009BBC0: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009BBC4: nop

    // 0x8009BBC8: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8009BBCC: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
    // 0x8009BBD0: sw          $t9, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r25;
    // 0x8009BBD4: lw          $t1, 0x108($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X108);
    // 0x8009BBD8: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8009BBDC: ori         $t0, $t0, 0x1001
    ctx->r8 = ctx->r8 | 0X1001;
    // 0x8009BBE0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009BBE4: lw          $t2, 0x108($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X108);
    // 0x8009BBE8: nop

    // 0x8009BBEC: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8009BBF0: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x8009BBF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009BBF8: lh          $t3, 0x116($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X116);
    // 0x8009BBFC: nop

    // 0x8009BC00: beq         $t3, $at, L_8009BE90
    if (ctx->r11 == ctx->r1) {
        // 0x8009BC04: nop
    
            goto L_8009BE90;
    }
    // 0x8009BC04: nop

    // 0x8009BC08: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8009BC0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009BC10: lh          $t5, 0x116($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X116);
    // 0x8009BC14: nop

    // 0x8009BC18: bne         $t5, $at, L_8009BD40
    if (ctx->r13 != ctx->r1) {
        // 0x8009BC1C: nop
    
            goto L_8009BD40;
    }
    // 0x8009BC1C: nop

    // 0x8009BC20: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x8009BC24: nop

    // 0x8009BC28: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8009BC2C: sw          $t9, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r25;
    // 0x8009BC30: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x8009BC34: lw          $t0, 0x104($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X104);
    // 0x8009BC38: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8009BC3C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8009BC40: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x8009BC44: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x8009BC48: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x8009BC4C: nop

    // 0x8009BC50: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8009BC54: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009BC58: nop

    // 0x8009BC5C: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8009BC60: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009BC64: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x8009BC68: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x8009BC6C: lui         $t5, 0xE800
    ctx->r13 = S32(0XE800 << 16);
    // 0x8009BC70: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8009BC74: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x8009BC78: nop

    // 0x8009BC7C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009BC80: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009BC84: nop

    // 0x8009BC88: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x8009BC8C: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009BC90: sw          $t8, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r24;
    // 0x8009BC94: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8009BC98: lui         $t1, 0xF500
    ctx->r9 = S32(0XF500 << 16);
    // 0x8009BC9C: ori         $t1, $t1, 0x100
    ctx->r9 = ctx->r9 | 0X100;
    // 0x8009BCA0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009BCA4: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x8009BCA8: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x8009BCAC: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x8009BCB0: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x8009BCB4: nop

    // 0x8009BCB8: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x8009BCBC: sw          $t5, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r13;
    // 0x8009BCC0: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
    // 0x8009BCC4: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8009BCC8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009BCCC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8009BCD0: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8009BCD4: nop

    // 0x8009BCD8: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8009BCDC: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009BCE0: nop

    // 0x8009BCE4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8009BCE8: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x8009BCEC: sw          $t0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r8;
    // 0x8009BCF0: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x8009BCF4: lui         $t2, 0xF000
    ctx->r10 = S32(0XF000 << 16);
    // 0x8009BCF8: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8009BCFC: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8009BD00: lui         $t3, 0x73F
    ctx->r11 = S32(0X73F << 16);
    // 0x8009BD04: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x8009BD08: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8009BD0C: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009BD10: nop

    // 0x8009BD14: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8009BD18: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x8009BD1C: sw          $t5, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r13;
    // 0x8009BD20: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x8009BD24: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009BD28: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8009BD2C: lw          $t0, 0xF0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF0);
    // 0x8009BD30: nop

    // 0x8009BD34: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8009BD38: b           L_8009BE58
    // 0x8009BD3C: nop

        goto L_8009BE58;
    // 0x8009BD3C: nop

L_8009BD40:
    // 0x8009BD40: lw          $t1, 0x194($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X194);
    // 0x8009BD44: nop

    // 0x8009BD48: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8009BD4C: sw          $t2, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r10;
    // 0x8009BD50: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
    // 0x8009BD54: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8009BD58: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x8009BD5C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8009BD60: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8009BD64: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8009BD68: lw          $t5, 0x138($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X138);
    // 0x8009BD6C: nop

    // 0x8009BD70: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8009BD74: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009BD78: nop

    // 0x8009BD7C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8009BD80: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
    // 0x8009BD84: sw          $t9, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r25;
    // 0x8009BD88: lw          $t1, 0xE8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE8);
    // 0x8009BD8C: lui         $t0, 0xE800
    ctx->r8 = S32(0XE800 << 16);
    // 0x8009BD90: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8009BD94: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x8009BD98: nop

    // 0x8009BD9C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8009BDA0: lw          $t4, 0x194($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X194);
    // 0x8009BDA4: nop

    // 0x8009BDA8: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x8009BDAC: sw          $t3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r11;
    // 0x8009BDB0: sw          $t4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r12;
    // 0x8009BDB4: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x8009BDB8: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8009BDBC: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8009BDC0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8009BDC4: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8009BDC8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8009BDCC: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8009BDD0: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009BDD4: nop

    // 0x8009BDD8: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x8009BDDC: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009BDE0: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x8009BDE4: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x8009BDE8: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x8009BDEC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009BDF0: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8009BDF4: nop

    // 0x8009BDF8: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8009BDFC: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009BE00: nop

    // 0x8009BE04: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8009BE08: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009BE0C: sw          $t3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r11;
    // 0x8009BE10: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x8009BE14: lui         $t5, 0xF000
    ctx->r13 = S32(0XF000 << 16);
    // 0x8009BE18: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8009BE1C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x8009BE20: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x8009BE24: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8009BE28: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8009BE2C: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009BE30: nop

    // 0x8009BE34: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8009BE38: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x8009BE3C: sw          $t0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r8;
    // 0x8009BE40: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x8009BE44: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8009BE48: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8009BE4C: lw          $t3, 0xD8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD8);
    // 0x8009BE50: nop

    // 0x8009BE54: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
L_8009BE58:
    // 0x8009BE58: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x8009BE5C: nop

    // 0x8009BE60: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x8009BE64: sw          $t5, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r13;
    // 0x8009BE68: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
    // 0x8009BE6C: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8009BE70: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8009BE74: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x8009BE78: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8009BE7C: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8009BE80: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8009BE84: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8009BE88: b           L_8009BEC0
    // 0x8009BE8C: nop

        goto L_8009BEC0;
    // 0x8009BE8C: nop

L_8009BE90:
    // 0x8009BE90: lw          $t1, 0x194($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X194);
    // 0x8009BE94: nop

    // 0x8009BE98: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8009BE9C: sw          $t2, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r10;
    // 0x8009BEA0: sw          $t1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r9;
    // 0x8009BEA4: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x8009BEA8: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x8009BEAC: ori         $t4, $t4, 0xE02
    ctx->r12 = ctx->r12 | 0XE02;
    // 0x8009BEB0: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8009BEB4: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8009BEB8: nop

    // 0x8009BEBC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_8009BEC0:
    // 0x8009BEC0: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009BEC4: nop

    // 0x8009BEC8: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8009BECC: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x8009BED0: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
    // 0x8009BED4: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8009BED8: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8009BEDC: ori         $t9, $t9, 0x903
    ctx->r25 = ctx->r25 | 0X903;
    // 0x8009BEE0: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8009BEE4: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8009BEE8: addiu       $t0, $zero, 0xC00
    ctx->r8 = ADD32(0, 0XC00);
    // 0x8009BEEC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8009BEF0: lw          $t2, 0x168($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X168);
    // 0x8009BEF4: nop

    // 0x8009BEF8: andi        $t4, $t2, 0x4
    ctx->r12 = ctx->r10 & 0X4;
    // 0x8009BEFC: bne         $t4, $zero, L_8009BF3C
    if (ctx->r12 != 0) {
        // 0x8009BF00: nop
    
            goto L_8009BF3C;
    }
    // 0x8009BF00: nop

    // 0x8009BF04: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009BF08: nop

    // 0x8009BF0C: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8009BF10: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009BF14: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8009BF18: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8009BF1C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x8009BF20: ori         $t5, $t5, 0xC02
    ctx->r13 = ctx->r13 | 0XC02;
    // 0x8009BF24: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8009BF28: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8009BF2C: nop

    // 0x8009BF30: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009BF34: b           L_8009BF6C
    // 0x8009BF38: nop

        goto L_8009BF6C;
    // 0x8009BF38: nop

L_8009BF3C:
    // 0x8009BF3C: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009BF40: nop

    // 0x8009BF44: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x8009BF48: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009BF4C: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x8009BF50: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x8009BF54: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x8009BF58: ori         $t1, $t1, 0xC02
    ctx->r9 = ctx->r9 | 0XC02;
    // 0x8009BF5C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009BF60: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x8009BF64: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x8009BF68: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
L_8009BF6C:
    // 0x8009BF6C: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8009BF70: nop

    // 0x8009BF74: lh          $t5, 0x100($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X100);
    // 0x8009BF78: nop

    // 0x8009BF7C: sw          $t5, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r13;
    // 0x8009BF80: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009BF84: nop

    // 0x8009BF88: lh          $t9, 0x102($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X102);
    // 0x8009BF8C: nop

    // 0x8009BF90: sw          $t9, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r25;
    // 0x8009BF94: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009BF98: nop

    // 0x8009BF9C: lh          $t0, 0x100($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X100);
    // 0x8009BFA0: nop

    // 0x8009BFA4: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x8009BFA8: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x8009BFAC: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x8009BFB0: nop

    // 0x8009BFB4: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x8009BFB8: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x8009BFBC: nop

    // 0x8009BFC0: lhu         $t4, 0x114($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X114);
    // 0x8009BFC4: nop

    // 0x8009BFC8: sltiu       $at, $t4, 0x9
    ctx->r1 = ctx->r12 < 0X9 ? 1 : 0;
    // 0x8009BFCC: beq         $at, $zero, L_8009C1B8
    if (ctx->r1 == 0) {
        // 0x8009BFD0: nop
    
            goto L_8009C1B8;
    }
    // 0x8009BFD0: nop

    // 0x8009BFD4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8009BFD8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009BFDC: addu        $at, $at, $t4
    gpr jr_addend_8009BFE8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8009BFE0: lw          $t4, -0x83C($at)
    ctx->r12 = ADD32(ctx->r1, -0X83C);
    // 0x8009BFE4: nop

    // 0x8009BFE8: jr          $t4
    // 0x8009BFEC: nop

    switch (jr_addend_8009BFE8 >> 2) {
        case 0: goto L_8009BFF0; break;
        case 1: goto L_8009C000; break;
        case 2: goto L_8009C034; break;
        case 3: goto L_8009C058; break;
        case 4: goto L_8009C088; break;
        case 5: goto L_8009C0DC; break;
        case 6: goto L_8009C120; break;
        case 7: goto L_8009C140; break;
        case 8: goto L_8009C184; break;
        default: switch_error(__func__, 0x8009BFE8, 0x800EF7C4);
    }
    // 0x8009BFEC: nop

L_8009BFF0:
    // 0x8009BFF0: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    // 0x8009BFF4: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x8009BFF8: b           L_8009C1B8
    // 0x8009BFFC: nop

        goto L_8009C1B8;
    // 0x8009BFFC: nop

L_8009C000:
    // 0x8009C000: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C004: nop

    // 0x8009C008: lh          $t6, 0x100($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X100);
    // 0x8009C00C: nop

    // 0x8009C010: negu        $t5, $t6
    ctx->r13 = SUB32(0, ctx->r14);
    // 0x8009C014: bgez        $t5, L_8009C024
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8009C018: sra         $t7, $t5, 1
        ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8009C024;
    }
    // 0x8009C018: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8009C01C: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8009C020: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8009C024:
    // 0x8009C024: sw          $t7, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r15;
    // 0x8009C028: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x8009C02C: b           L_8009C1B8
    // 0x8009C030: nop

        goto L_8009C1B8;
    // 0x8009C030: nop

L_8009C034:
    // 0x8009C034: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C038: nop

    // 0x8009C03C: lh          $t8, 0x100($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X100);
    // 0x8009C040: nop

    // 0x8009C044: negu        $t0, $t8
    ctx->r8 = SUB32(0, ctx->r24);
    // 0x8009C048: sw          $t0, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r8;
    // 0x8009C04C: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x8009C050: b           L_8009C1B8
    // 0x8009C054: nop

        goto L_8009C1B8;
    // 0x8009C054: nop

L_8009C058:
    // 0x8009C058: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    // 0x8009C05C: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C060: nop

    // 0x8009C064: lh          $t2, 0x102($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X102);
    // 0x8009C068: nop

    // 0x8009C06C: bgez        $t2, L_8009C07C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009C070: sra         $t4, $t2, 1
        ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
            goto L_8009C07C;
    }
    // 0x8009C070: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8009C074: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x8009C078: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8009C07C:
    // 0x8009C07C: sw          $t4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r12;
    // 0x8009C080: b           L_8009C1B8
    // 0x8009C084: nop

        goto L_8009C1B8;
    // 0x8009C084: nop

L_8009C088:
    // 0x8009C088: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C08C: nop

    // 0x8009C090: lh          $t6, 0x100($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X100);
    // 0x8009C094: nop

    // 0x8009C098: negu        $t5, $t6
    ctx->r13 = SUB32(0, ctx->r14);
    // 0x8009C09C: bgez        $t5, L_8009C0AC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8009C0A0: sra         $t7, $t5, 1
        ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8009C0AC;
    }
    // 0x8009C0A0: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8009C0A4: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8009C0A8: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8009C0AC:
    // 0x8009C0AC: sw          $t7, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r15;
    // 0x8009C0B0: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C0B4: nop

    // 0x8009C0B8: lh          $t8, 0x102($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X102);
    // 0x8009C0BC: nop

    // 0x8009C0C0: bgez        $t8, L_8009C0D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8009C0C4: sra         $t0, $t8, 1
        ctx->r8 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8009C0D0;
    }
    // 0x8009C0C4: sra         $t0, $t8, 1
    ctx->r8 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8009C0C8: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8009C0CC: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8009C0D0:
    // 0x8009C0D0: sw          $t0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r8;
    // 0x8009C0D4: b           L_8009C1B8
    // 0x8009C0D8: nop

        goto L_8009C1B8;
    // 0x8009C0D8: nop

L_8009C0DC:
    // 0x8009C0DC: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C0E0: nop

    // 0x8009C0E4: lh          $t2, 0x100($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X100);
    // 0x8009C0E8: nop

    // 0x8009C0EC: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x8009C0F0: sw          $t4, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r12;
    // 0x8009C0F4: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C0F8: nop

    // 0x8009C0FC: lh          $t6, 0x102($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X102);
    // 0x8009C100: nop

    // 0x8009C104: bgez        $t6, L_8009C114
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8009C108: sra         $t5, $t6, 1
        ctx->r13 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8009C114;
    }
    // 0x8009C108: sra         $t5, $t6, 1
    ctx->r13 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8009C10C: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8009C110: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8009C114:
    // 0x8009C114: sw          $t5, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r13;
    // 0x8009C118: b           L_8009C1B8
    // 0x8009C11C: nop

        goto L_8009C1B8;
    // 0x8009C11C: nop

L_8009C120:
    // 0x8009C120: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    // 0x8009C124: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C128: nop

    // 0x8009C12C: lh          $t9, 0x102($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X102);
    // 0x8009C130: nop

    // 0x8009C134: sw          $t9, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r25;
    // 0x8009C138: b           L_8009C1B8
    // 0x8009C13C: nop

        goto L_8009C1B8;
    // 0x8009C13C: nop

L_8009C140:
    // 0x8009C140: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C144: nop

    // 0x8009C148: lh          $t0, 0x100($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X100);
    // 0x8009C14C: nop

    // 0x8009C150: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8009C154: bgez        $t1, L_8009C164
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8009C158: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8009C164;
    }
    // 0x8009C158: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8009C15C: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8009C160: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8009C164:
    // 0x8009C164: sw          $t2, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r10;
    // 0x8009C168: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C16C: nop

    // 0x8009C170: lh          $t3, 0x102($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X102);
    // 0x8009C174: nop

    // 0x8009C178: sw          $t3, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r11;
    // 0x8009C17C: b           L_8009C1B8
    // 0x8009C180: nop

        goto L_8009C1B8;
    // 0x8009C180: nop

L_8009C184:
    // 0x8009C184: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C188: nop

    // 0x8009C18C: lh          $t5, 0x100($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X100);
    // 0x8009C190: nop

    // 0x8009C194: negu        $t7, $t5
    ctx->r15 = SUB32(0, ctx->r13);
    // 0x8009C198: sw          $t7, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r15;
    // 0x8009C19C: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C1A0: nop

    // 0x8009C1A4: lh          $t8, 0x102($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X102);
    // 0x8009C1A8: nop

    // 0x8009C1AC: sw          $t8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r24;
    // 0x8009C1B0: b           L_8009C1B8
    // 0x8009C1B4: nop

        goto L_8009C1B8;
    // 0x8009C1B4: nop

L_8009C1B8:
    // 0x8009C1B8: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
L_8009C1BC:
    // 0x8009C1BC: sw          $zero, 0x174($sp)
    MEM_W(0X174, ctx->r29) = 0;
    // 0x8009C1C0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009C1C4: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009C1C8: nop

    // 0x8009C1CC: sw          $t0, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r8;
    // 0x8009C1D0: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x8009C1D4: nop

    // 0x8009C1D8: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8009C1DC: beq         $at, $zero, L_8009C7D8
    if (ctx->r1 == 0) {
        // 0x8009C1E0: nop
    
            goto L_8009C7D8;
    }
    // 0x8009C1E0: nop

L_8009C1E4:
    // 0x8009C1E4: sw          $zero, 0x180($sp)
    MEM_W(0X180, ctx->r29) = 0;
    // 0x8009C1E8: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
L_8009C1EC:
    // 0x8009C1EC: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x8009C1F0: nop

    // 0x8009C1F4: bne         $t2, $zero, L_8009C204
    if (ctx->r10 != 0) {
        // 0x8009C1F8: nop
    
            goto L_8009C204;
    }
    // 0x8009C1F8: nop

    // 0x8009C1FC: b           L_8009C264
    // 0x8009C200: nop

        goto L_8009C264;
    // 0x8009C200: nop

L_8009C204:
    // 0x8009C204: lw          $t4, 0x180($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X180);
    // 0x8009C208: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8009C20C: nop

    // 0x8009C210: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8009C214: slti        $at, $t6, 0x801
    ctx->r1 = SIGNED(ctx->r14) < 0X801 ? 1 : 0;
    // 0x8009C218: bne         $at, $zero, L_8009C228
    if (ctx->r1 != 0) {
        // 0x8009C21C: nop
    
            goto L_8009C228;
    }
    // 0x8009C21C: nop

    // 0x8009C220: b           L_8009C264
    // 0x8009C224: nop

        goto L_8009C264;
    // 0x8009C224: nop

L_8009C228:
    // 0x8009C228: lw          $t5, 0x180($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X180);
    // 0x8009C22C: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x8009C230: nop

    // 0x8009C234: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8009C238: sw          $t9, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r25;
    // 0x8009C23C: lw          $t8, 0x17C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X17C);
    // 0x8009C240: nop

    // 0x8009C244: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8009C248: sw          $t0, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r8;
    // 0x8009C24C: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x8009C250: nop

    // 0x8009C254: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8009C258: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x8009C25C: b           L_8009C1EC
    // 0x8009C260: nop

        goto L_8009C1EC;
    // 0x8009C260: nop

L_8009C264:
    // 0x8009C264: lw          $t4, 0x17C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X17C);
    // 0x8009C268: nop

    // 0x8009C26C: bne         $t4, $zero, L_8009C27C
    if (ctx->r12 != 0) {
        // 0x8009C270: nop
    
            goto L_8009C27C;
    }
    // 0x8009C270: nop

    // 0x8009C274: b           L_8009C7D8
    // 0x8009C278: nop

        goto L_8009C7D8;
    // 0x8009C278: nop

L_8009C27C:
    // 0x8009C27C: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x8009C280: lwc1        $f10, 0x150($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009C284: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8009C288: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C28C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009C290: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C294: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8009C298: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009C29C: nop

    // 0x8009C2A0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8009C2A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009C2A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009C2AC: nop

    // 0x8009C2B0: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009C2B4: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8009C2B8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009C2BC: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x8009C2C0: nop

    // 0x8009C2C4: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x8009C2C8: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x8009C2CC: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009C2D0: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8009C2D4: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8009C2D8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009C2DC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009C2E0: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009C2E4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009C2E8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8009C2EC: nop

    // 0x8009C2F0: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8009C2F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009C2F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009C2FC: nop

    // 0x8009C300: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009C304: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8009C308: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009C30C: sh          $t2, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r10;
    // 0x8009C310: nop

    // 0x8009C314: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009C318: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009C31C: lw          $t3, 0x178($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X178);
    // 0x8009C320: nop

    // 0x8009C324: sh          $t3, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r11;
    // 0x8009C328: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009C32C: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009C330: nop

    // 0x8009C334: sh          $zero, 0x8($t5)
    MEM_H(0X8, ctx->r13) = 0;
    // 0x8009C338: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C33C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C340: nop

    // 0x8009C344: sh          $zero, 0xA($t7)
    MEM_H(0XA, ctx->r15) = 0;
    // 0x8009C348: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009C34C: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x8009C350: nop

    // 0x8009C354: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x8009C358: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009C35C: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009C360: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009C364: sb          $t8, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r24;
    // 0x8009C368: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009C36C: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x8009C370: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009C374: sb          $t1, 0xD($t2)
    MEM_B(0XD, ctx->r10) = ctx->r9;
    // 0x8009C378: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009C37C: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009C380: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8009C384: sb          $t4, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r12;
    // 0x8009C388: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8009C38C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009C390: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009C394: lh          $t6, -0x4CDC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CDC);
    // 0x8009C398: nop

    // 0x8009C39C: sb          $t6, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r14;
    // 0x8009C3A0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C3A4: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C3A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009C3AC: addiu       $t9, $t7, 0x10
    ctx->r25 = ADD32(ctx->r15, 0X10);
    // 0x8009C3B0: sw          $t9, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r25;
    // 0x8009C3B4: lw          $t8, 0x174($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X174);
    // 0x8009C3B8: nop

    // 0x8009C3BC: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8009C3C0: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    // 0x8009C3C4: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8009C3C8: lw          $t2, 0x188($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X188);
    // 0x8009C3CC: lwc1        $f4, 0x150($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009C3D0: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8009C3D4: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8009C3D8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009C3DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009C3E0: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009C3E4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009C3E8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8009C3EC: nop

    // 0x8009C3F0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8009C3F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009C3F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009C3FC: nop

    // 0x8009C400: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8009C404: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8009C408: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009C40C: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
    // 0x8009C410: nop

    // 0x8009C414: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x8009C418: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x8009C41C: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009C420: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8009C424: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009C428: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009C42C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009C430: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x8009C434: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009C438: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8009C43C: nop

    // 0x8009C440: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8009C444: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009C448: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009C44C: nop

    // 0x8009C450: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009C454: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8009C458: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8009C45C: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x8009C460: nop

    // 0x8009C464: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009C468: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009C46C: nop

    // 0x8009C470: sh          $zero, 0x4($t4)
    MEM_H(0X4, ctx->r12) = 0;
    // 0x8009C474: lw          $t3, 0x188($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X188);
    // 0x8009C478: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009C47C: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009C480: sll         $t6, $t3, 6
    ctx->r14 = S32(ctx->r11 << 6);
    // 0x8009C484: sh          $t6, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r14;
    // 0x8009C488: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C48C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C490: nop

    // 0x8009C494: sh          $zero, 0xA($t7)
    MEM_H(0XA, ctx->r15) = 0;
    // 0x8009C498: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009C49C: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x8009C4A0: nop

    // 0x8009C4A4: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x8009C4A8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009C4AC: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009C4B0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009C4B4: sb          $t8, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r24;
    // 0x8009C4B8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009C4BC: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x8009C4C0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009C4C4: sb          $t1, 0xD($t2)
    MEM_B(0XD, ctx->r10) = ctx->r9;
    // 0x8009C4C8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009C4CC: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009C4D0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8009C4D4: sb          $t4, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r12;
    // 0x8009C4D8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8009C4DC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009C4E0: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009C4E4: lh          $t6, -0x4CDC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CDC);
    // 0x8009C4E8: nop

    // 0x8009C4EC: sb          $t6, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r14;
    // 0x8009C4F0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C4F4: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C4F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009C4FC: addiu       $t9, $t7, 0x10
    ctx->r25 = ADD32(ctx->r15, 0X10);
    // 0x8009C500: sw          $t9, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r25;
    // 0x8009C504: lw          $t8, 0x174($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X174);
    // 0x8009C508: nop

    // 0x8009C50C: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8009C510: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    // 0x8009C514: lw          $t1, 0x178($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X178);
    // 0x8009C518: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x8009C51C: nop

    // 0x8009C520: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8009C524: sw          $t4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r12;
    // 0x8009C528: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x8009C52C: lwc1        $f16, 0x150($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009C530: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8009C534: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C538: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009C53C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C540: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009C544: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009C548: nop

    // 0x8009C54C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8009C550: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009C554: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009C558: nop

    // 0x8009C55C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8009C560: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8009C564: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009C568: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x8009C56C: nop

    // 0x8009C570: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x8009C574: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x8009C578: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009C57C: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8009C580: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009C584: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009C588: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009C58C: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009C590: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8009C594: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8009C598: nop

    // 0x8009C59C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8009C5A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009C5A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009C5A8: nop

    // 0x8009C5AC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8009C5B0: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8009C5B4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009C5B8: sh          $t2, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r10;
    // 0x8009C5BC: nop

    // 0x8009C5C0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009C5C4: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009C5C8: nop

    // 0x8009C5CC: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x8009C5D0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009C5D4: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009C5D8: nop

    // 0x8009C5DC: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x8009C5E0: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x8009C5E4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009C5E8: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x8009C5EC: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x8009C5F0: sh          $t7, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r15;
    // 0x8009C5F4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009C5F8: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x8009C5FC: nop

    // 0x8009C600: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x8009C604: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009C608: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x8009C60C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8009C610: sb          $t0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r8;
    // 0x8009C614: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009C618: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009C61C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009C620: sb          $t2, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r10;
    // 0x8009C624: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009C628: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009C62C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009C630: sb          $t3, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r11;
    // 0x8009C634: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8009C638: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C63C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C640: lh          $t5, -0x4CDC($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4CDC);
    // 0x8009C644: nop

    // 0x8009C648: sb          $t5, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r13;
    // 0x8009C64C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009C650: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x8009C654: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009C658: addiu       $t8, $t9, 0x10
    ctx->r24 = ADD32(ctx->r25, 0X10);
    // 0x8009C65C: sw          $t8, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r24;
    // 0x8009C660: lw          $t0, 0x174($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X174);
    // 0x8009C664: nop

    // 0x8009C668: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8009C66C: sw          $t1, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r9;
    // 0x8009C670: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8009C674: lw          $t4, 0x188($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X188);
    // 0x8009C678: lwc1        $f10, 0x150($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009C67C: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8009C680: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8009C684: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C688: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009C68C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C690: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8009C694: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009C698: nop

    // 0x8009C69C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8009C6A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009C6A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009C6A8: nop

    // 0x8009C6AC: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009C6B0: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8009C6B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009C6B8: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x8009C6BC: nop

    // 0x8009C6C0: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x8009C6C4: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x8009C6C8: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009C6CC: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8009C6D0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8009C6D4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009C6D8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009C6DC: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009C6E0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009C6E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8009C6E8: nop

    // 0x8009C6EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8009C6F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009C6F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009C6F8: nop

    // 0x8009C6FC: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009C700: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8009C704: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009C708: sh          $t2, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r10;
    // 0x8009C70C: nop

    // 0x8009C710: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009C714: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009C718: nop

    // 0x8009C71C: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x8009C720: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x8009C724: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C728: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C72C: sll         $t5, $t6, 6
    ctx->r13 = S32(ctx->r14 << 6);
    // 0x8009C730: sh          $t5, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r13;
    // 0x8009C734: lw          $t9, 0x17C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X17C);
    // 0x8009C738: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009C73C: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009C740: sll         $t8, $t9, 6
    ctx->r24 = S32(ctx->r25 << 6);
    // 0x8009C744: sh          $t8, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r24;
    // 0x8009C748: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009C74C: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x8009C750: nop

    // 0x8009C754: sh          $zero, 0x6($t1)
    MEM_H(0X6, ctx->r9) = 0;
    // 0x8009C758: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009C75C: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009C760: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009C764: sb          $t2, 0xC($t4)
    MEM_B(0XC, ctx->r12) = ctx->r10;
    // 0x8009C768: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009C76C: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009C770: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009C774: sb          $t3, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r11;
    // 0x8009C778: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009C77C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009C780: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009C784: sb          $t5, 0xE($t7)
    MEM_B(0XE, ctx->r15) = ctx->r13;
    // 0x8009C788: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8009C78C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009C790: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x8009C794: lh          $t9, -0x4CDC($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4CDC);
    // 0x8009C798: nop

    // 0x8009C79C: sb          $t9, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r25;
    // 0x8009C7A0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009C7A4: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009C7A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009C7AC: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x8009C7B0: sw          $t1, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r9;
    // 0x8009C7B4: lw          $t2, 0x174($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X174);
    // 0x8009C7B8: nop

    // 0x8009C7BC: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8009C7C0: sw          $t4, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r12;
    // 0x8009C7C4: lw          $t3, 0x174($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X174);
    // 0x8009C7C8: nop

    // 0x8009C7CC: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x8009C7D0: bne         $at, $zero, L_8009C1E4
    if (ctx->r1 != 0) {
        // 0x8009C7D4: nop
    
            goto L_8009C1E4;
    }
    // 0x8009C7D4: nop

L_8009C7D8:
    // 0x8009C7D8: lw          $t6, 0x174($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X174);
    // 0x8009C7DC: nop

    // 0x8009C7E0: bne         $t6, $zero, L_8009C7F0
    if (ctx->r14 != 0) {
        // 0x8009C7E4: nop
    
            goto L_8009C7F0;
    }
    // 0x8009C7E4: nop

    // 0x8009C7E8: b           L_8009D14C
    // 0x8009C7EC: nop

        goto L_8009D14C;
    // 0x8009C7EC: nop

L_8009C7F0:
    // 0x8009C7F0: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009C7F4: nop

    // 0x8009C7F8: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8009C7FC: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x8009C800: sw          $t5, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r13;
    // 0x8009C804: lw          $t9, 0x174($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X174);
    // 0x8009C808: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8009C80C: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8009C810: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x8009C814: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8009C818: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8009C81C: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8009C820: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x8009C824: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x8009C828: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x8009C82C: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x8009C830: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8009C834: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x8009C838: lw          $t0, 0xC0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC0);
    // 0x8009C83C: nop

    // 0x8009C840: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8009C844: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x8009C848: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
    // 0x8009C84C: blez        $t1, L_8009D144
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8009C850: nop
    
            goto L_8009D144;
    }
    // 0x8009C850: nop

L_8009C854:
    // 0x8009C854: lw          $t9, 0x170($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X170);
    // 0x8009C858: lw          $t2, 0x154($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X154);
    // 0x8009C85C: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8009C860: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8009C864: lh          $t6, 0x4($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X4);
    // 0x8009C868: nop

    // 0x8009C86C: sw          $t6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r14;
    // 0x8009C870: lw          $t7, 0x170($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X170);
    // 0x8009C874: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x8009C878: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8009C87C: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x8009C880: sh          $zero, 0x4($t0)
    MEM_H(0X4, ctx->r8) = 0;
    // 0x8009C884: lw          $t9, 0x170($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X170);
    // 0x8009C888: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    // 0x8009C88C: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8009C890: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8009C894: lh          $t4, 0x2A($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2A);
    // 0x8009C898: nop

    // 0x8009C89C: sra         $t6, $t4, 6
    ctx->r14 = S32(SIGNED(ctx->r12) >> 6);
    // 0x8009C8A0: sw          $t6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r14;
    // 0x8009C8A4: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009C8A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009C8AC: lh          $t5, 0x116($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X116);
    // 0x8009C8B0: nop

    // 0x8009C8B4: bne         $t5, $at, L_8009CB58
    if (ctx->r13 != ctx->r1) {
        // 0x8009C8B8: nop
    
            goto L_8009CB58;
    }
    // 0x8009C8B8: nop

    // 0x8009C8BC: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009C8C0: nop

    // 0x8009C8C4: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x8009C8C8: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009C8CC: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x8009C8D0: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x8009C8D4: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8009C8D8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8009C8DC: lw          $t2, 0x15C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X15C);
    // 0x8009C8E0: lw          $t3, 0x188($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X188);
    // 0x8009C8E4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009C8E8: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009C8EC: lw          $t6, 0x72E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72E0);
    // 0x8009C8F0: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x8009C8F4: mflo        $t4
    ctx->r12 = lo;
    // 0x8009C8F8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8009C8FC: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8009C900: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009C904: nop

    // 0x8009C908: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x8009C90C: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009C910: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8009C914: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x8009C918: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8009C91C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8009C920: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x8009C924: lui         $t2, 0x708
    ctx->r10 = S32(0X708 << 16);
    // 0x8009C928: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8009C92C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8009C930: lw          $t4, 0x194($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X194);
    // 0x8009C934: nop

    // 0x8009C938: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x8009C93C: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009C940: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x8009C944: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x8009C948: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009C94C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8009C950: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8009C954: nop

    // 0x8009C958: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8009C95C: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009C960: nop

    // 0x8009C964: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x8009C968: sw          $t9, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r25;
    // 0x8009C96C: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x8009C970: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x8009C974: lui         $t1, 0xF300
    ctx->r9 = S32(0XF300 << 16);
    // 0x8009C978: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009C97C: lw          $t3, 0x188($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X188);
    // 0x8009C980: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x8009C984: nop

    // 0x8009C988: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009C98C: mflo        $t6
    ctx->r14 = lo;
    // 0x8009C990: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009C994: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8009C998: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8009C99C: slti        $at, $t8, 0x7FF
    ctx->r1 = SIGNED(ctx->r24) < 0X7FF ? 1 : 0;
    // 0x8009C9A0: beq         $at, $zero, L_8009C9B0
    if (ctx->r1 == 0) {
        // 0x8009C9A4: nop
    
            goto L_8009C9B0;
    }
    // 0x8009C9A4: nop

    // 0x8009C9A8: b           L_8009C9B4
    // 0x8009C9AC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
        goto L_8009C9B4;
    // 0x8009C9AC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_8009C9B0:
    // 0x8009C9B0: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_8009C9B4:
    // 0x8009C9B4: lw          $t0, 0x188($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X188);
    // 0x8009C9B8: nop

    // 0x8009C9BC: bgez        $t0, L_8009C9CC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009C9C0: sra         $t9, $t0, 3
        ctx->r25 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8009C9CC;
    }
    // 0x8009C9C0: sra         $t9, $t0, 3
    ctx->r25 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8009C9C4: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8009C9C8: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8009C9CC:
    // 0x8009C9CC: bgtz        $t9, L_8009C9DC
    if (SIGNED(ctx->r25) > 0) {
        // 0x8009C9D0: nop
    
            goto L_8009C9DC;
    }
    // 0x8009C9D0: nop

    // 0x8009C9D4: b           L_8009C9F8
    // 0x8009C9D8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8009C9F8;
    // 0x8009C9D8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8009C9DC:
    // 0x8009C9DC: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x8009C9E0: nop

    // 0x8009C9E4: bgez        $s1, L_8009C9F4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8009C9E8: sra         $t1, $s1, 3
        ctx->r9 = S32(SIGNED(ctx->r17) >> 3);
            goto L_8009C9F4;
    }
    // 0x8009C9E8: sra         $t1, $s1, 3
    ctx->r9 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8009C9EC: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x8009C9F0: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8009C9F4:
    // 0x8009C9F4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_8009C9F8:
    // 0x8009C9F8: lw          $t2, 0x188($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X188);
    // 0x8009C9FC: nop

    // 0x8009CA00: bgez        $t2, L_8009CA10
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009CA04: sra         $t3, $t2, 3
        ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
            goto L_8009CA10;
    }
    // 0x8009CA04: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8009CA08: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x8009CA0C: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8009CA10:
    // 0x8009CA10: bgtz        $t3, L_8009CA20
    if (SIGNED(ctx->r11) > 0) {
        // 0x8009CA14: nop
    
            goto L_8009CA20;
    }
    // 0x8009CA14: nop

    // 0x8009CA18: b           L_8009CA3C
    // 0x8009CA1C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8009CA3C;
    // 0x8009CA1C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8009CA20:
    // 0x8009CA20: lw          $s0, 0x188($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X188);
    // 0x8009CA24: nop

    // 0x8009CA28: bgez        $s0, L_8009CA38
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8009CA2C: sra         $t4, $s0, 3
        ctx->r12 = S32(SIGNED(ctx->r16) >> 3);
            goto L_8009CA38;
    }
    // 0x8009CA2C: sra         $t4, $s0, 3
    ctx->r12 = S32(SIGNED(ctx->r16) >> 3);
    // 0x8009CA30: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x8009CA34: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_8009CA38:
    // 0x8009CA38: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_8009CA3C:
    // 0x8009CA3C: addiu       $t6, $s1, 0x7FF
    ctx->r14 = ADD32(ctx->r17, 0X7FF);
    // 0x8009CA40: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x8009CA44: andi        $t8, $s2, 0xFFF
    ctx->r24 = ctx->r18 & 0XFFF;
    // 0x8009CA48: bne         $s0, $zero, L_8009CA54
    if (ctx->r16 != 0) {
        // 0x8009CA4C: nop
    
            goto L_8009CA54;
    }
    // 0x8009CA4C: nop

    // 0x8009CA50: break       7
    do_break(2148125264);
L_8009CA54:
    // 0x8009CA54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009CA58: bne         $s0, $at, L_8009CA6C
    if (ctx->r16 != ctx->r1) {
        // 0x8009CA5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009CA6C;
    }
    // 0x8009CA5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009CA60: bne         $t6, $at, L_8009CA6C
    if (ctx->r14 != ctx->r1) {
        // 0x8009CA64: nop
    
            goto L_8009CA6C;
    }
    // 0x8009CA64: nop

    // 0x8009CA68: break       6
    do_break(2148125288);
L_8009CA6C:
    // 0x8009CA6C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009CA70: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x8009CA74: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x8009CA78: or          $t9, $t0, $at
    ctx->r25 = ctx->r8 | ctx->r1;
    // 0x8009CA7C: mflo        $t7
    ctx->r15 = lo;
    // 0x8009CA80: andi        $t5, $t7, 0xFFF
    ctx->r13 = ctx->r15 & 0XFFF;
    // 0x8009CA84: or          $t1, $t5, $t9
    ctx->r9 = ctx->r13 | ctx->r25;
    // 0x8009CA88: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8009CA8C: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009CA90: nop

    // 0x8009CA94: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8009CA98: sw          $t4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r12;
    // 0x8009CA9C: sw          $t3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r11;
    // 0x8009CAA0: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8009CAA4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8009CAA8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009CAAC: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8009CAB0: nop

    // 0x8009CAB4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8009CAB8: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009CABC: nop

    // 0x8009CAC0: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x8009CAC4: sw          $t5, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r13;
    // 0x8009CAC8: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x8009CACC: lw          $t9, 0x188($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X188);
    // 0x8009CAD0: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8009CAD4: addiu       $t1, $t9, 0x7
    ctx->r9 = ADD32(ctx->r25, 0X7);
    // 0x8009CAD8: sra         $t2, $t1, 3
    ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8009CADC: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x8009CAE0: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x8009CAE4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8009CAE8: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x8009CAEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009CAF0: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x8009CAF4: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8009CAF8: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8009CAFC: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8009CB00: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009CB04: nop

    // 0x8009CB08: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x8009CB0C: sw          $t9, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r25;
    // 0x8009CB10: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x8009CB14: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x8009CB18: lui         $t1, 0xF200
    ctx->r9 = S32(0XF200 << 16);
    // 0x8009CB1C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009CB20: lw          $t3, 0x188($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X188);
    // 0x8009CB24: lw          $t0, 0x158($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X158);
    // 0x8009CB28: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8009CB2C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8009CB30: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x8009CB34: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8009CB38: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009CB3C: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8009CB40: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009CB44: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8009CB48: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8009CB4C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8009CB50: b           L_8009D040
    // 0x8009CB54: nop

        goto L_8009D040;
    // 0x8009CB54: nop

L_8009CB58:
    // 0x8009CB58: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x8009CB5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009CB60: lh          $t6, 0x116($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X116);
    // 0x8009CB64: nop

    // 0x8009CB68: bne         $t6, $at, L_8009CE24
    if (ctx->r14 != ctx->r1) {
        // 0x8009CB6C: nop
    
            goto L_8009CE24;
    }
    // 0x8009CB6C: nop

    // 0x8009CB70: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x8009CB74: nop

    // 0x8009CB78: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x8009CB7C: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009CB80: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x8009CB84: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8009CB88: lui         $t5, 0xFD10
    ctx->r13 = S32(0XFD10 << 16);
    // 0x8009CB8C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8009CB90: lw          $t8, 0x188($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X188);
    // 0x8009CB94: lw          $t2, 0x15C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X15C);
    // 0x8009CB98: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8009CB9C: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009CBA0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009CBA4: lw          $t4, 0x72E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72E0);
    // 0x8009CBA8: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x8009CBAC: mflo        $t3
    ctx->r11 = lo;
    // 0x8009CBB0: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8009CBB4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8009CBB8: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009CBBC: nop

    // 0x8009CBC0: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x8009CBC4: sw          $t5, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r13;
    // 0x8009CBC8: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    // 0x8009CBCC: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8009CBD0: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x8009CBD4: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8009CBD8: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8009CBDC: lui         $t1, 0x708
    ctx->r9 = S32(0X708 << 16);
    // 0x8009CBE0: ori         $t1, $t1, 0x200
    ctx->r9 = ctx->r9 | 0X200;
    // 0x8009CBE4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8009CBE8: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009CBEC: nop

    // 0x8009CBF0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8009CBF4: sw          $t4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r12;
    // 0x8009CBF8: sw          $t3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r11;
    // 0x8009CBFC: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8009CC00: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8009CC04: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009CC08: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x8009CC0C: nop

    // 0x8009CC10: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8009CC14: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009CC18: nop

    // 0x8009CC1C: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x8009CC20: sw          $t9, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r25;
    // 0x8009CC24: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    // 0x8009CC28: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8009CC2C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8009CC30: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8009CC34: lw          $t2, 0x188($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X188);
    // 0x8009CC38: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x8009CC3C: nop

    // 0x8009CC40: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009CC44: mflo        $t4
    ctx->r12 = lo;
    // 0x8009CC48: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8009CC4C: slti        $at, $t6, 0x7FF
    ctx->r1 = SIGNED(ctx->r14) < 0X7FF ? 1 : 0;
    // 0x8009CC50: beq         $at, $zero, L_8009CC60
    if (ctx->r1 == 0) {
        // 0x8009CC54: nop
    
            goto L_8009CC60;
    }
    // 0x8009CC54: nop

    // 0x8009CC58: b           L_8009CC64
    // 0x8009CC5C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
        goto L_8009CC64;
    // 0x8009CC5C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
L_8009CC60:
    // 0x8009CC60: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_8009CC64:
    // 0x8009CC64: lw          $t7, 0x188($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X188);
    // 0x8009CC68: nop

    // 0x8009CC6C: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x8009CC70: bgez        $t0, L_8009CC80
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009CC74: sra         $t5, $t0, 3
        ctx->r13 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8009CC80;
    }
    // 0x8009CC74: sra         $t5, $t0, 3
    ctx->r13 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8009CC78: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8009CC7C: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_8009CC80:
    // 0x8009CC80: bgtz        $t5, L_8009CC90
    if (SIGNED(ctx->r13) > 0) {
        // 0x8009CC84: nop
    
            goto L_8009CC90;
    }
    // 0x8009CC84: nop

    // 0x8009CC88: b           L_8009CCB4
    // 0x8009CC8C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8009CCB4;
    // 0x8009CC8C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8009CC90:
    // 0x8009CC90: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x8009CC94: nop

    // 0x8009CC98: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x8009CC9C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8009CCA0: bgez        $s1, L_8009CCB0
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8009CCA4: sra         $t8, $s1, 3
        ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
            goto L_8009CCB0;
    }
    // 0x8009CCA4: sra         $t8, $s1, 3
    ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8009CCA8: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x8009CCAC: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8009CCB0:
    // 0x8009CCB0: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
L_8009CCB4:
    // 0x8009CCB4: lw          $t1, 0x188($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X188);
    // 0x8009CCB8: nop

    // 0x8009CCBC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8009CCC0: bgez        $t2, L_8009CCD0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009CCC4: sra         $t3, $t2, 3
        ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
            goto L_8009CCD0;
    }
    // 0x8009CCC4: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8009CCC8: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x8009CCCC: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8009CCD0:
    // 0x8009CCD0: bgtz        $t3, L_8009CCE0
    if (SIGNED(ctx->r11) > 0) {
        // 0x8009CCD4: nop
    
            goto L_8009CCE0;
    }
    // 0x8009CCD4: nop

    // 0x8009CCD8: b           L_8009CD04
    // 0x8009CCDC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8009CD04;
    // 0x8009CCDC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8009CCE0:
    // 0x8009CCE0: lw          $s0, 0x188($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X188);
    // 0x8009CCE4: nop

    // 0x8009CCE8: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x8009CCEC: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x8009CCF0: bgez        $s0, L_8009CD00
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8009CCF4: sra         $t6, $s0, 3
        ctx->r14 = S32(SIGNED(ctx->r16) >> 3);
            goto L_8009CD00;
    }
    // 0x8009CCF4: sra         $t6, $s0, 3
    ctx->r14 = S32(SIGNED(ctx->r16) >> 3);
    // 0x8009CCF8: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x8009CCFC: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8009CD00:
    // 0x8009CD00: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8009CD04:
    // 0x8009CD04: addiu       $t7, $s1, 0x7FF
    ctx->r15 = ADD32(ctx->r17, 0X7FF);
    // 0x8009CD08: div         $zero, $t7, $s0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r16)));
    // 0x8009CD0C: andi        $t9, $s2, 0xFFF
    ctx->r25 = ctx->r18 & 0XFFF;
    // 0x8009CD10: bne         $s0, $zero, L_8009CD1C
    if (ctx->r16 != 0) {
        // 0x8009CD14: nop
    
            goto L_8009CD1C;
    }
    // 0x8009CD14: nop

    // 0x8009CD18: break       7
    do_break(2148125976);
L_8009CD1C:
    // 0x8009CD1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009CD20: bne         $s0, $at, L_8009CD34
    if (ctx->r16 != ctx->r1) {
        // 0x8009CD24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009CD34;
    }
    // 0x8009CD24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009CD28: bne         $t7, $at, L_8009CD34
    if (ctx->r15 != ctx->r1) {
        // 0x8009CD2C: nop
    
            goto L_8009CD34;
    }
    // 0x8009CD2C: nop

    // 0x8009CD30: break       6
    do_break(2148126000);
L_8009CD34:
    // 0x8009CD34: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009CD38: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8009CD3C: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8009CD40: or          $t1, $t8, $at
    ctx->r9 = ctx->r24 | ctx->r1;
    // 0x8009CD44: mflo        $t0
    ctx->r8 = lo;
    // 0x8009CD48: andi        $t5, $t0, 0xFFF
    ctx->r13 = ctx->r8 & 0XFFF;
    // 0x8009CD4C: or          $t2, $t5, $t1
    ctx->r10 = ctx->r13 | ctx->r9;
    // 0x8009CD50: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8009CD54: lw          $t4, 0x194($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X194);
    // 0x8009CD58: nop

    // 0x8009CD5C: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x8009CD60: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009CD64: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
    // 0x8009CD68: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8009CD6C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8009CD70: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8009CD74: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8009CD78: nop

    // 0x8009CD7C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009CD80: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009CD84: nop

    // 0x8009CD88: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x8009CD8C: sw          $t5, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r13;
    // 0x8009CD90: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x8009CD94: lw          $t1, 0x188($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X188);
    // 0x8009CD98: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8009CD9C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8009CDA0: addiu       $t3, $t2, 0x7
    ctx->r11 = ADD32(ctx->r10, 0X7);
    // 0x8009CDA4: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8009CDA8: andi        $t6, $t4, 0x1FF
    ctx->r14 = ctx->r12 & 0X1FF;
    // 0x8009CDAC: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8009CDB0: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8009CDB4: or          $t0, $t7, $at
    ctx->r8 = ctx->r15 | ctx->r1;
    // 0x8009CDB8: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8009CDBC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8009CDC0: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8009CDC4: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8009CDC8: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x8009CDCC: lw          $t1, 0x194($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X194);
    // 0x8009CDD0: nop

    // 0x8009CDD4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8009CDD8: sw          $t2, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r10;
    // 0x8009CDDC: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8009CDE0: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8009CDE4: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x8009CDE8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8009CDEC: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x8009CDF0: lw          $t5, 0x158($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X158);
    // 0x8009CDF4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8009CDF8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8009CDFC: addiu       $t1, $t5, -0x1
    ctx->r9 = ADD32(ctx->r13, -0X1);
    // 0x8009CE00: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8009CE04: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x8009CE08: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8009CE0C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8009CE10: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x8009CE14: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x8009CE18: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x8009CE1C: b           L_8009D040
    // 0x8009CE20: nop

        goto L_8009D040;
    // 0x8009CE20: nop

L_8009CE24:
    // 0x8009CE24: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x8009CE28: nop

    // 0x8009CE2C: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x8009CE30: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009CE34: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    // 0x8009CE38: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x8009CE3C: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8009CE40: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8009CE44: lw          $t1, 0x188($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X188);
    // 0x8009CE48: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x8009CE4C: bgez        $t1, L_8009CE5C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8009CE50: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8009CE5C;
    }
    // 0x8009CE50: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8009CE54: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8009CE58: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8009CE5C:
    // 0x8009CE5C: multu       $t2, $t8
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009CE60: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009CE64: lw          $t4, 0x72E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72E0);
    // 0x8009CE68: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8009CE6C: mflo        $t3
    ctx->r11 = lo;
    // 0x8009CE70: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8009CE74: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8009CE78: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009CE7C: nop

    // 0x8009CE80: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x8009CE84: sw          $t9, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r25;
    // 0x8009CE88: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8009CE8C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8009CE90: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x8009CE94: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8009CE98: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8009CE9C: lui         $t2, 0x708
    ctx->r10 = S32(0X708 << 16);
    // 0x8009CEA0: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8009CEA4: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x8009CEA8: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009CEAC: nop

    // 0x8009CEB0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8009CEB4: sw          $t4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r12;
    // 0x8009CEB8: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x8009CEBC: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8009CEC0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8009CEC4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009CEC8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8009CECC: nop

    // 0x8009CED0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8009CED4: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009CED8: nop

    // 0x8009CEDC: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x8009CEE0: sw          $t5, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r13;
    // 0x8009CEE4: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x8009CEE8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x8009CEEC: lui         $t1, 0xF300
    ctx->r9 = S32(0XF300 << 16);
    // 0x8009CEF0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009CEF4: lw          $t8, 0x188($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X188);
    // 0x8009CEF8: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x8009CEFC: nop

    // 0x8009CF00: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009CF04: mflo        $t4
    ctx->r12 = lo;
    // 0x8009CF08: addiu       $t6, $t4, 0x3
    ctx->r14 = ADD32(ctx->r12, 0X3);
    // 0x8009CF0C: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x8009CF10: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8009CF14: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8009CF18: beq         $at, $zero, L_8009CF28
    if (ctx->r1 == 0) {
        // 0x8009CF1C: nop
    
            goto L_8009CF28;
    }
    // 0x8009CF1C: nop

    // 0x8009CF20: b           L_8009CF2C
    // 0x8009CF24: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
        goto L_8009CF2C;
    // 0x8009CF24: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
L_8009CF28:
    // 0x8009CF28: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_8009CF2C:
    // 0x8009CF2C: b           L_8009CF38
    // 0x8009CF30: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8009CF38;
    // 0x8009CF30: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8009CF34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8009CF38:
    // 0x8009CF38: b           L_8009CF44
    // 0x8009CF3C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8009CF44;
    // 0x8009CF3C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8009CF40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009CF44:
    // 0x8009CF44: addiu       $t9, $s1, 0x7FF
    ctx->r25 = ADD32(ctx->r17, 0X7FF);
    // 0x8009CF48: div         $zero, $t9, $s0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r16)));
    // 0x8009CF4C: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
    // 0x8009CF50: bne         $s0, $zero, L_8009CF5C
    if (ctx->r16 != 0) {
        // 0x8009CF54: nop
    
            goto L_8009CF5C;
    }
    // 0x8009CF54: nop

    // 0x8009CF58: break       7
    do_break(2148126552);
L_8009CF5C:
    // 0x8009CF5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009CF60: bne         $s0, $at, L_8009CF74
    if (ctx->r16 != ctx->r1) {
        // 0x8009CF64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009CF74;
    }
    // 0x8009CF64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009CF68: bne         $t9, $at, L_8009CF74
    if (ctx->r25 != ctx->r1) {
        // 0x8009CF6C: nop
    
            goto L_8009CF74;
    }
    // 0x8009CF6C: nop

    // 0x8009CF70: break       6
    do_break(2148126576);
L_8009CF74:
    // 0x8009CF74: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009CF78: sll         $t8, $t2, 12
    ctx->r24 = S32(ctx->r10 << 12);
    // 0x8009CF7C: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8009CF80: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x8009CF84: mflo        $t5
    ctx->r13 = lo;
    // 0x8009CF88: andi        $t1, $t5, 0xFFF
    ctx->r9 = ctx->r13 & 0XFFF;
    // 0x8009CF8C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8009CF90: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x8009CF94: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x8009CF98: nop

    // 0x8009CF9C: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x8009CFA0: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009CFA4: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8009CFA8: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8009CFAC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009CFB0: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8009CFB4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8009CFB8: nop

    // 0x8009CFBC: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8009CFC0: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009CFC4: nop

    // 0x8009CFC8: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x8009CFCC: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x8009CFD0: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x8009CFD4: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8009CFD8: lui         $t3, 0xF540
    ctx->r11 = S32(0XF540 << 16);
    // 0x8009CFDC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8009CFE0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8009CFE4: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8009CFE8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8009CFEC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8009CFF0: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009CFF4: nop

    // 0x8009CFF8: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x8009CFFC: sw          $t9, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r25;
    // 0x8009D000: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x8009D004: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8009D008: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x8009D00C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8009D010: lw          $t8, 0x188($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X188);
    // 0x8009D014: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x8009D018: addiu       $t1, $t8, -0x1
    ctx->r9 = ADD32(ctx->r24, -0X1);
    // 0x8009D01C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8009D020: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8009D024: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8009D028: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x8009D02C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8009D030: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x8009D034: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x8009D038: or          $t2, $t6, $t5
    ctx->r10 = ctx->r14 | ctx->r13;
    // 0x8009D03C: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
L_8009D040:
    // 0x8009D040: lw          $t1, 0x194($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X194);
    // 0x8009D044: nop

    // 0x8009D048: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8009D04C: sw          $t3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r11;
    // 0x8009D050: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8009D054: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8009D058: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x8009D05C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8009D060: lw          $t0, 0x170($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X170);
    // 0x8009D064: nop

    // 0x8009D068: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8009D06C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8009D070: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8009D074: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8009D078: addiu       $t2, $t9, 0x1E
    ctx->r10 = ADD32(ctx->r25, 0X1E);
    // 0x8009D07C: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x8009D080: sll         $t5, $t6, 16
    ctx->r13 = S32(ctx->r14 << 16);
    // 0x8009D084: sll         $t1, $t8, 8
    ctx->r9 = S32(ctx->r24 << 8);
    // 0x8009D088: addiu       $t4, $t9, 0xA
    ctx->r12 = ADD32(ctx->r25, 0XA);
    // 0x8009D08C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8009D090: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x8009D094: or          $t3, $t5, $t1
    ctx->r11 = ctx->r13 | ctx->r9;
    // 0x8009D098: or          $t0, $t3, $t7
    ctx->r8 = ctx->r11 | ctx->r15;
    // 0x8009D09C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8009D0A0: lw          $t2, 0x194($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X194);
    // 0x8009D0A4: nop

    // 0x8009D0A8: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8009D0AC: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
    // 0x8009D0B0: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x8009D0B4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8009D0B8: lui         $t5, 0xBF00
    ctx->r13 = S32(0XBF00 << 16);
    // 0x8009D0BC: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8009D0C0: lw          $t9, 0x170($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X170);
    // 0x8009D0C4: nop

    // 0x8009D0C8: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8009D0CC: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x8009D0D0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8009D0D4: andi        $t3, $t4, 0xFF
    ctx->r11 = ctx->r12 & 0XFF;
    // 0x8009D0D8: addiu       $t0, $t4, 0x14
    ctx->r8 = ADD32(ctx->r12, 0X14);
    // 0x8009D0DC: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x8009D0E0: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x8009D0E4: sll         $t2, $t6, 8
    ctx->r10 = S32(ctx->r14 << 8);
    // 0x8009D0E8: addiu       $t5, $t4, 0x1E
    ctx->r13 = ADD32(ctx->r12, 0X1E);
    // 0x8009D0EC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8009D0F0: andi        $t1, $t5, 0xFF
    ctx->r9 = ctx->r13 & 0XFF;
    // 0x8009D0F4: or          $t8, $t7, $t2
    ctx->r24 = ctx->r15 | ctx->r10;
    // 0x8009D0F8: or          $t9, $t8, $t1
    ctx->r25 = ctx->r24 | ctx->r9;
    // 0x8009D0FC: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8009D100: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x8009D104: nop

    // 0x8009D108: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x8009D10C: sw          $t6, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r14;
    // 0x8009D110: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8009D114: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8009D118: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8009D11C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8009D120: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8009D124: nop

    // 0x8009D128: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8009D12C: lw          $t5, 0x170($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X170);
    // 0x8009D130: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x8009D134: addiu       $t8, $t5, 0x4
    ctx->r24 = ADD32(ctx->r13, 0X4);
    // 0x8009D138: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8009D13C: bne         $at, $zero, L_8009C854
    if (ctx->r1 != 0) {
        // 0x8009D140: sw          $t8, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r24;
            goto L_8009C854;
    }
    // 0x8009D140: sw          $t8, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r24;
L_8009D144:
    // 0x8009D144: b           L_8009C1BC
    // 0x8009D148: nop

        goto L_8009C1BC;
    // 0x8009D148: nop

L_8009D14C:
    // 0x8009D14C: b           L_8009DADC
    // 0x8009D150: nop

        goto L_8009DADC;
    // 0x8009D150: nop

L_8009D154:
    // 0x8009D154: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009D158: nop

    // 0x8009D15C: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x8009D160: sw          $t3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r11;
    // 0x8009D164: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x8009D168: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8009D16C: lui         $t0, 0xBB00
    ctx->r8 = S32(0XBB00 << 16);
    // 0x8009D170: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8009D174: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8009D178: nop

    // 0x8009D17C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8009D180: lw          $t2, 0x168($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X168);
    // 0x8009D184: nop

    // 0x8009D188: andi        $t4, $t2, 0x8000
    ctx->r12 = ctx->r10 & 0X8000;
    // 0x8009D18C: beq         $t4, $zero, L_8009D204
    if (ctx->r12 == 0) {
        // 0x8009D190: nop
    
            goto L_8009D204;
    }
    // 0x8009D190: nop

    // 0x8009D194: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009D198: nop

    // 0x8009D19C: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x8009D1A0: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
    // 0x8009D1A4: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x8009D1A8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8009D1AC: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x8009D1B0: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x8009D1B4: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8009D1B8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8009D1BC: lui         $t3, 0xFFFE
    ctx->r11 = S32(0XFFFE << 16);
    // 0x8009D1C0: ori         $t3, $t3, 0x793C
    ctx->r11 = ctx->r11 | 0X793C;
    // 0x8009D1C4: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x8009D1C8: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x8009D1CC: nop

    // 0x8009D1D0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8009D1D4: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x8009D1D8: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8009D1DC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8009D1E0: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8009D1E4: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8009D1E8: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8009D1EC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8009D1F0: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8009D1F4: ori         $t5, $t5, 0x4A50
    ctx->r13 = ctx->r13 | 0X4A50;
    // 0x8009D1F8: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8009D1FC: b           L_8009D26C
    // 0x8009D200: nop

        goto L_8009D26C;
    // 0x8009D200: nop

L_8009D204:
    // 0x8009D204: lw          $t1, 0x194($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X194);
    // 0x8009D208: nop

    // 0x8009D20C: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x8009D210: sw          $t9, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r25;
    // 0x8009D214: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8009D218: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8009D21C: lui         $t3, 0xFCFF
    ctx->r11 = S32(0XFCFF << 16);
    // 0x8009D220: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x8009D224: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8009D228: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8009D22C: lui         $t6, 0xFFFE
    ctx->r14 = S32(0XFFFE << 16);
    // 0x8009D230: ori         $t6, $t6, 0x793C
    ctx->r14 = ctx->r14 | 0X793C;
    // 0x8009D234: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8009D238: lw          $t2, 0x194($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X194);
    // 0x8009D23C: nop

    // 0x8009D240: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8009D244: sw          $t4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r12;
    // 0x8009D248: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8009D24C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8009D250: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8009D254: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x8009D258: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8009D25C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8009D260: lui         $t1, 0x55
    ctx->r9 = S32(0X55 << 16);
    // 0x8009D264: ori         $t1, $t1, 0x3078
    ctx->r9 = ctx->r9 | 0X3078;
    // 0x8009D268: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
L_8009D26C:
    // 0x8009D26C: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x8009D270: nop

    // 0x8009D274: addiu       $t0, $t3, 0x8
    ctx->r8 = ADD32(ctx->r11, 0X8);
    // 0x8009D278: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009D27C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8009D280: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8009D284: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x8009D288: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009D28C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8009D290: addiu       $t2, $zero, 0x205
    ctx->r10 = ADD32(0, 0X205);
    // 0x8009D294: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8009D298: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D29C: nop

    // 0x8009D2A0: lh          $t8, 0x100($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X100);
    // 0x8009D2A4: nop

    // 0x8009D2A8: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
    // 0x8009D2AC: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D2B0: nop

    // 0x8009D2B4: lh          $t9, 0x102($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X102);
    // 0x8009D2B8: nop

    // 0x8009D2BC: sw          $t9, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r25;
    // 0x8009D2C0: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x8009D2C4: lw          $t3, 0x184($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X184);
    // 0x8009D2C8: nop

    // 0x8009D2CC: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x8009D2D0: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D2D4: nop

    // 0x8009D2D8: lhu         $t6, 0x114($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X114);
    // 0x8009D2DC: nop

    // 0x8009D2E0: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8009D2E4: beq         $at, $zero, L_8009D4D0
    if (ctx->r1 == 0) {
        // 0x8009D2E8: nop
    
            goto L_8009D4D0;
    }
    // 0x8009D2E8: nop

    // 0x8009D2EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009D2F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009D2F4: addu        $at, $at, $t6
    gpr jr_addend_8009D300 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8009D2F8: lw          $t6, -0x818($at)
    ctx->r14 = ADD32(ctx->r1, -0X818);
    // 0x8009D2FC: nop

    // 0x8009D300: jr          $t6
    // 0x8009D304: nop

    switch (jr_addend_8009D300 >> 2) {
        case 0: goto L_8009D308; break;
        case 1: goto L_8009D318; break;
        case 2: goto L_8009D34C; break;
        case 3: goto L_8009D370; break;
        case 4: goto L_8009D3A0; break;
        case 5: goto L_8009D3F4; break;
        case 6: goto L_8009D438; break;
        case 7: goto L_8009D458; break;
        case 8: goto L_8009D49C; break;
        default: switch_error(__func__, 0x8009D300, 0x800EF7E8);
    }
    // 0x8009D304: nop

L_8009D308:
    // 0x8009D308: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    // 0x8009D30C: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x8009D310: b           L_8009D4D0
    // 0x8009D314: nop

        goto L_8009D4D0;
    // 0x8009D314: nop

L_8009D318:
    // 0x8009D318: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D31C: nop

    // 0x8009D320: lh          $t2, 0x100($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X100);
    // 0x8009D324: nop

    // 0x8009D328: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x8009D32C: bgez        $t4, L_8009D33C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8009D330: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8009D33C;
    }
    // 0x8009D330: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8009D334: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8009D338: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8009D33C:
    // 0x8009D33C: sw          $t5, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r13;
    // 0x8009D340: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x8009D344: b           L_8009D4D0
    // 0x8009D348: nop

        goto L_8009D4D0;
    // 0x8009D348: nop

L_8009D34C:
    // 0x8009D34C: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D350: nop

    // 0x8009D354: lh          $t1, 0x100($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X100);
    // 0x8009D358: nop

    // 0x8009D35C: negu        $t9, $t1
    ctx->r25 = SUB32(0, ctx->r9);
    // 0x8009D360: sw          $t9, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r25;
    // 0x8009D364: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x8009D368: b           L_8009D4D0
    // 0x8009D36C: nop

        goto L_8009D4D0;
    // 0x8009D36C: nop

L_8009D370:
    // 0x8009D370: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    // 0x8009D374: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D378: nop

    // 0x8009D37C: lh          $t0, 0x102($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X102);
    // 0x8009D380: nop

    // 0x8009D384: bgez        $t0, L_8009D394
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009D388: sra         $t6, $t0, 1
        ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8009D394;
    }
    // 0x8009D388: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8009D38C: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8009D390: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8009D394:
    // 0x8009D394: sw          $t6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r14;
    // 0x8009D398: b           L_8009D4D0
    // 0x8009D39C: nop

        goto L_8009D4D0;
    // 0x8009D39C: nop

L_8009D3A0:
    // 0x8009D3A0: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D3A4: nop

    // 0x8009D3A8: lh          $t2, 0x100($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X100);
    // 0x8009D3AC: nop

    // 0x8009D3B0: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x8009D3B4: bgez        $t4, L_8009D3C4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8009D3B8: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8009D3C4;
    }
    // 0x8009D3B8: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8009D3BC: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8009D3C0: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8009D3C4:
    // 0x8009D3C4: sw          $t5, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r13;
    // 0x8009D3C8: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D3CC: nop

    // 0x8009D3D0: lh          $t1, 0x102($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X102);
    // 0x8009D3D4: nop

    // 0x8009D3D8: bgez        $t1, L_8009D3E8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8009D3DC: sra         $t9, $t1, 1
        ctx->r25 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8009D3E8;
    }
    // 0x8009D3DC: sra         $t9, $t1, 1
    ctx->r25 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8009D3E0: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8009D3E4: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8009D3E8:
    // 0x8009D3E8: sw          $t9, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r25;
    // 0x8009D3EC: b           L_8009D4D0
    // 0x8009D3F0: nop

        goto L_8009D4D0;
    // 0x8009D3F0: nop

L_8009D3F4:
    // 0x8009D3F4: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D3F8: nop

    // 0x8009D3FC: lh          $t0, 0x100($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X100);
    // 0x8009D400: nop

    // 0x8009D404: negu        $t6, $t0
    ctx->r14 = SUB32(0, ctx->r8);
    // 0x8009D408: sw          $t6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r14;
    // 0x8009D40C: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D410: nop

    // 0x8009D414: lh          $t2, 0x102($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X102);
    // 0x8009D418: nop

    // 0x8009D41C: bgez        $t2, L_8009D42C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009D420: sra         $t4, $t2, 1
        ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
            goto L_8009D42C;
    }
    // 0x8009D420: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8009D424: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x8009D428: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8009D42C:
    // 0x8009D42C: sw          $t4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r12;
    // 0x8009D430: b           L_8009D4D0
    // 0x8009D434: nop

        goto L_8009D4D0;
    // 0x8009D434: nop

L_8009D438:
    // 0x8009D438: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    // 0x8009D43C: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D440: nop

    // 0x8009D444: lh          $t8, 0x102($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X102);
    // 0x8009D448: nop

    // 0x8009D44C: sw          $t8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r24;
    // 0x8009D450: b           L_8009D4D0
    // 0x8009D454: nop

        goto L_8009D4D0;
    // 0x8009D454: nop

L_8009D458:
    // 0x8009D458: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D45C: nop

    // 0x8009D460: lh          $t9, 0x100($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X100);
    // 0x8009D464: nop

    // 0x8009D468: negu        $t3, $t9
    ctx->r11 = SUB32(0, ctx->r25);
    // 0x8009D46C: bgez        $t3, L_8009D47C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8009D470: sra         $t0, $t3, 1
        ctx->r8 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8009D47C;
    }
    // 0x8009D470: sra         $t0, $t3, 1
    ctx->r8 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8009D474: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8009D478: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8009D47C:
    // 0x8009D47C: sw          $t0, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r8;
    // 0x8009D480: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D484: nop

    // 0x8009D488: lh          $t7, 0x102($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X102);
    // 0x8009D48C: nop

    // 0x8009D490: sw          $t7, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r15;
    // 0x8009D494: b           L_8009D4D0
    // 0x8009D498: nop

        goto L_8009D4D0;
    // 0x8009D498: nop

L_8009D49C:
    // 0x8009D49C: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D4A0: nop

    // 0x8009D4A4: lh          $t4, 0x100($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X100);
    // 0x8009D4A8: nop

    // 0x8009D4AC: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8009D4B0: sw          $t5, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r13;
    // 0x8009D4B4: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D4B8: nop

    // 0x8009D4BC: lh          $t1, 0x102($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X102);
    // 0x8009D4C0: nop

    // 0x8009D4C4: sw          $t1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r9;
    // 0x8009D4C8: b           L_8009D4D0
    // 0x8009D4CC: nop

        goto L_8009D4D0;
    // 0x8009D4CC: nop

L_8009D4D0:
    // 0x8009D4D0: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D4D4: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x8009D4D8: lw          $t0, 0x104($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X104);
    // 0x8009D4DC: nop

    // 0x8009D4E0: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8009D4E4: sw          $t6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r14;
    // 0x8009D4E8: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D4EC: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x8009D4F0: lw          $t4, 0x108($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X108);
    // 0x8009D4F4: nop

    // 0x8009D4F8: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x8009D4FC: sw          $t5, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r13;
    // 0x8009D500: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009D504: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x8009D508: nop

    // 0x8009D50C: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
    // 0x8009D510: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8009D514: lwc1        $f4, 0x150($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009D518: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8009D51C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009D520: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009D524: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009D528: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009D52C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8009D530: nop

    // 0x8009D534: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8009D538: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009D53C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009D540: nop

    // 0x8009D544: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8009D548: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8009D54C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009D550: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x8009D554: nop

    // 0x8009D558: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x8009D55C: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009D560: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8009D564: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009D568: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009D56C: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009D570: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009D574: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8009D578: nop

    // 0x8009D57C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8009D580: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009D584: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009D588: nop

    // 0x8009D58C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009D590: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8009D594: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8009D598: sh          $t7, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r15;
    // 0x8009D59C: nop

    // 0x8009D5A0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009D5A4: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009D5A8: nop

    // 0x8009D5AC: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x8009D5B0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009D5B4: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x8009D5B8: nop

    // 0x8009D5BC: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x8009D5C0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009D5C4: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x8009D5C8: nop

    // 0x8009D5CC: sh          $zero, 0xA($t1)
    MEM_H(0XA, ctx->r9) = 0;
    // 0x8009D5D0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009D5D4: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009D5D8: nop

    // 0x8009D5DC: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x8009D5E0: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D5E4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009D5E8: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009D5EC: lh          $t0, 0x118($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X118);
    // 0x8009D5F0: nop

    // 0x8009D5F4: sb          $t0, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r8;
    // 0x8009D5F8: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D5FC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009D600: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009D604: lh          $t7, 0x11A($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X11A);
    // 0x8009D608: nop

    // 0x8009D60C: sb          $t7, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r15;
    // 0x8009D610: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D614: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009D618: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x8009D61C: lh          $t8, 0x11C($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X11C);
    // 0x8009D620: nop

    // 0x8009D624: sb          $t8, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r24;
    // 0x8009D628: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8009D62C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009D630: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x8009D634: lh          $t3, -0x4CDC($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4CDC);
    // 0x8009D638: nop

    // 0x8009D63C: sb          $t3, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r11;
    // 0x8009D640: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009D644: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009D648: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009D64C: addiu       $t6, $t0, 0x10
    ctx->r14 = ADD32(ctx->r8, 0X10);
    // 0x8009D650: sw          $t6, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r14;
    // 0x8009D654: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8009D658: lw          $t7, 0x188($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X188);
    // 0x8009D65C: lwc1        $f16, 0x150($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009D660: addu        $t4, $t2, $t7
    ctx->r12 = ADD32(ctx->r10, ctx->r15);
    // 0x8009D664: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8009D668: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009D66C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009D670: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x8009D674: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009D678: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8009D67C: nop

    // 0x8009D680: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8009D684: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009D688: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009D68C: nop

    // 0x8009D690: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8009D694: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009D698: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8009D69C: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x8009D6A0: nop

    // 0x8009D6A4: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x8009D6A8: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009D6AC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8009D6B0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009D6B4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009D6B8: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009D6BC: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8009D6C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009D6C4: nop

    // 0x8009D6C8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8009D6CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009D6D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009D6D4: nop

    // 0x8009D6D8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8009D6DC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8009D6E0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8009D6E4: sh          $t0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r8;
    // 0x8009D6E8: nop

    // 0x8009D6EC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009D6F0: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x8009D6F4: nop

    // 0x8009D6F8: sh          $zero, 0x4($t2)
    MEM_H(0X4, ctx->r10) = 0;
    // 0x8009D6FC: lw          $t7, 0x188($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X188);
    // 0x8009D700: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009D704: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009D708: sll         $t4, $t7, 6
    ctx->r12 = S32(ctx->r15 << 6);
    // 0x8009D70C: sh          $t4, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r12;
    // 0x8009D710: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009D714: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x8009D718: nop

    // 0x8009D71C: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x8009D720: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009D724: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x8009D728: nop

    // 0x8009D72C: sh          $zero, 0x6($t1)
    MEM_H(0X6, ctx->r9) = 0;
    // 0x8009D730: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D734: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009D738: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009D73C: lh          $t9, 0x118($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X118);
    // 0x8009D740: nop

    // 0x8009D744: sb          $t9, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r25;
    // 0x8009D748: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D74C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8009D750: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x8009D754: lh          $t2, 0x11A($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X11A);
    // 0x8009D758: nop

    // 0x8009D75C: sb          $t2, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r10;
    // 0x8009D760: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D764: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009D768: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x8009D76C: lh          $t5, 0x11C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X11C);
    // 0x8009D770: nop

    // 0x8009D774: sb          $t5, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r13;
    // 0x8009D778: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8009D77C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009D780: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009D784: lh          $t1, -0x4CDC($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CDC);
    // 0x8009D788: nop

    // 0x8009D78C: sb          $t1, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r9;
    // 0x8009D790: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009D794: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x8009D798: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009D79C: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x8009D7A0: sw          $t0, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r8;
    // 0x8009D7A4: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x8009D7A8: lwc1        $f10, 0x150($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009D7AC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8009D7B0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8009D7B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009D7B8: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x8009D7BC: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8009D7C0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8009D7C4: nop

    // 0x8009D7C8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8009D7CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009D7D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009D7D4: nop

    // 0x8009D7D8: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009D7DC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8009D7E0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8009D7E4: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x8009D7E8: nop

    // 0x8009D7EC: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x8009D7F0: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x8009D7F4: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009D7F8: subu        $t1, $t5, $t8
    ctx->r9 = SUB32(ctx->r13, ctx->r24);
    // 0x8009D7FC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8009D800: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009D804: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009D808: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009D80C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009D810: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8009D814: nop

    // 0x8009D818: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8009D81C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009D820: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009D824: nop

    // 0x8009D828: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009D82C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009D830: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009D834: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x8009D838: nop

    // 0x8009D83C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009D840: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009D844: nop

    // 0x8009D848: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x8009D84C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009D850: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x8009D854: nop

    // 0x8009D858: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
    // 0x8009D85C: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x8009D860: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009D864: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009D868: sll         $t4, $t7, 6
    ctx->r12 = S32(ctx->r15 << 6);
    // 0x8009D86C: sh          $t4, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r12;
    // 0x8009D870: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8009D874: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x8009D878: nop

    // 0x8009D87C: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x8009D880: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D884: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009D888: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x8009D88C: lh          $t3, 0x118($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X118);
    // 0x8009D890: nop

    // 0x8009D894: sb          $t3, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r11;
    // 0x8009D898: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D89C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009D8A0: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x8009D8A4: lh          $t6, 0x11A($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X11A);
    // 0x8009D8A8: nop

    // 0x8009D8AC: sb          $t6, 0xD($t2)
    MEM_B(0XD, ctx->r10) = ctx->r14;
    // 0x8009D8B0: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D8B4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009D8B8: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009D8BC: lh          $t4, 0x11C($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X11C);
    // 0x8009D8C0: nop

    // 0x8009D8C4: sb          $t4, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r12;
    // 0x8009D8C8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8009D8CC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8009D8D0: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x8009D8D4: lh          $t8, -0x4CDC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CDC);
    // 0x8009D8D8: nop

    // 0x8009D8DC: sb          $t8, 0xF($t1)
    MEM_B(0XF, ctx->r9) = ctx->r24;
    // 0x8009D8E0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009D8E4: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009D8E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009D8EC: addiu       $t9, $t3, 0x10
    ctx->r25 = ADD32(ctx->r11, 0X10);
    // 0x8009D8F0: sw          $t9, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r25;
    // 0x8009D8F4: lw          $t0, 0x164($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X164);
    // 0x8009D8F8: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x8009D8FC: lwc1        $f4, 0x150($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X150);
    // 0x8009D900: addu        $t2, $t0, $t6
    ctx->r10 = ADD32(ctx->r8, ctx->r14);
    // 0x8009D904: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8009D908: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009D90C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009D910: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009D914: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009D918: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8009D91C: nop

    // 0x8009D920: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8009D924: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009D928: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009D92C: nop

    // 0x8009D930: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8009D934: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8009D938: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8009D93C: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x8009D940: nop

    // 0x8009D944: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x8009D948: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x8009D94C: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x8009D950: subu        $t3, $t8, $t1
    ctx->r11 = SUB32(ctx->r24, ctx->r9);
    // 0x8009D954: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8009D958: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009D95C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009D960: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009D964: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009D968: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009D96C: nop

    // 0x8009D970: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8009D974: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009D978: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009D97C: nop

    // 0x8009D980: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009D984: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8009D988: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8009D98C: sh          $t0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r8;
    // 0x8009D990: nop

    // 0x8009D994: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009D998: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x8009D99C: nop

    // 0x8009D9A0: sh          $zero, 0x4($t2)
    MEM_H(0X4, ctx->r10) = 0;
    // 0x8009D9A4: lw          $t7, 0x188($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X188);
    // 0x8009D9A8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009D9AC: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009D9B0: sll         $t4, $t7, 6
    ctx->r12 = S32(ctx->r15 << 6);
    // 0x8009D9B4: sh          $t4, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r12;
    // 0x8009D9B8: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x8009D9BC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009D9C0: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009D9C4: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x8009D9C8: sh          $t1, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r9;
    // 0x8009D9CC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8009D9D0: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x8009D9D4: nop

    // 0x8009D9D8: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x8009D9DC: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D9E0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8009D9E4: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x8009D9E8: lh          $t6, 0x118($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X118);
    // 0x8009D9EC: nop

    // 0x8009D9F0: sb          $t6, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r14;
    // 0x8009D9F4: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8009D9F8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8009D9FC: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x8009DA00: lh          $t4, 0x11A($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X11A);
    // 0x8009DA04: nop

    // 0x8009DA08: sb          $t4, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r12;
    // 0x8009DA0C: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8009DA10: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8009DA14: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x8009DA18: lh          $t1, 0x11C($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X11C);
    // 0x8009DA1C: nop

    // 0x8009DA20: sb          $t1, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r9;
    // 0x8009DA24: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8009DA28: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8009DA2C: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x8009DA30: lh          $t9, -0x4CDC($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4CDC);
    // 0x8009DA34: nop

    // 0x8009DA38: sb          $t9, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r25;
    // 0x8009DA3C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009DA40: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x8009DA44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009DA48: addiu       $t2, $t6, 0x10
    ctx->r10 = ADD32(ctx->r14, 0X10);
    // 0x8009DA4C: sw          $t2, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r10;
    // 0x8009DA50: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x8009DA54: nop

    // 0x8009DA58: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x8009DA5C: sw          $t4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r12;
    // 0x8009DA60: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8009DA64: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8009DA68: lui         $t5, 0x430
    ctx->r13 = S32(0X430 << 16);
    // 0x8009DA6C: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x8009DA70: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8009DA74: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    // 0x8009DA78: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8009DA7C: nop

    // 0x8009DA80: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x8009DA84: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8009DA88: nop

    // 0x8009DA8C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8009DA90: sw          $t0, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r8;
    // 0x8009DA94: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8009DA98: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8009DA9C: lui         $t6, 0xBF00
    ctx->r14 = S32(0XBF00 << 16);
    // 0x8009DAA0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8009DAA4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8009DAA8: addiu       $t7, $zero, 0x1E0A
    ctx->r15 = ADD32(0, 0X1E0A);
    // 0x8009DAAC: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8009DAB0: lw          $t5, 0x194($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X194);
    // 0x8009DAB4: nop

    // 0x8009DAB8: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x8009DABC: sw          $t8, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r24;
    // 0x8009DAC0: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8009DAC4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8009DAC8: lui         $t1, 0xBF00
    ctx->r9 = S32(0XBF00 << 16);
    // 0x8009DACC: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8009DAD0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8009DAD4: addiu       $t9, $zero, 0x141E
    ctx->r25 = ADD32(0, 0X141E);
    // 0x8009DAD8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_8009DADC:
    // 0x8009DADC: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x8009DAE0: nop

    // 0x8009DAE4: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x8009DAE8: sw          $t2, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r10;
    // 0x8009DAEC: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8009DAF0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8009DAF4: lui         $t7, 0xBD00
    ctx->r15 = S32(0XBD00 << 16);
    // 0x8009DAF8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8009DAFC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8009DB00: nop

    // 0x8009DB04: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8009DB08: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8009DB0C: nop

    // 0x8009DB10: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x8009DB14: sw          $t1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r9;
    // 0x8009DB18: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8009DB1C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8009DB20: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8009DB24: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8009DB28: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8009DB2C: nop

    // 0x8009DB30: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8009DB34: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x8009DB38: lw          $t2, 0x198($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X198);
    // 0x8009DB3C: nop

    // 0x8009DB40: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8009DB44: b           L_8009DB54
    // 0x8009DB48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009DB54;
    // 0x8009DB48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009DB4C: b           L_8009DB54
    // 0x8009DB50: nop

        goto L_8009DB54;
    // 0x8009DB50: nop

L_8009DB54:
    // 0x8009DB54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009DB58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009DB5C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DB60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009DB64: jr          $ra
    // 0x8009DB68: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    return;
    // 0x8009DB68: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
;}
RECOMP_FUNC void func_80068FAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068FB4: jal         0x80061488
    // 0x80068FB8: addiu       $a0, $zero, 0x390
    ctx->r4 = ADD32(0, 0X390);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068FB8: addiu       $a0, $zero, 0x390
    ctx->r4 = ADD32(0, 0X390);
    after_0:
    // 0x80068FBC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068FC0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068FC4: b           L_80068FD4
    // 0x80068FC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068FD4;
    // 0x80068FC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068FCC: b           L_80068FD4
    // 0x80068FD0: nop

        goto L_80068FD4;
    // 0x80068FD0: nop

L_80068FD4:
    // 0x80068FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068FDC: jr          $ra
    // 0x80068FE0: nop

    return;
    // 0x80068FE0: nop

;}
RECOMP_FUNC void func_8006778C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006778C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067794: jal         0x80061348
    // 0x80067798: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067798: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006779C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800677A0: b           L_800677B0
    // 0x800677A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800677B0;
    // 0x800677A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800677A8: b           L_800677B0
    // 0x800677AC: nop

        goto L_800677B0;
    // 0x800677AC: nop

L_800677B0:
    // 0x800677B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800677B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800677B8: jr          $ra
    // 0x800677BC: nop

    return;
    // 0x800677BC: nop

;}
RECOMP_FUNC void Main_SetContRawStickScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BECCC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BECD0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800BECD4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BECD8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800BECDC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800BECE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BECE4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800BECE8: lw          $t7, 0xDA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XDA8);
    // 0x800BECEC: nop

    // 0x800BECF0: beq         $t7, $zero, L_800BED00
    if (ctx->r15 == 0) {
        // 0x800BECF4: nop
    
            goto L_800BED00;
    }
    // 0x800BECF4: nop

    // 0x800BECF8: b           L_800BED40
    // 0x800BECFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BED40;
    // 0x800BECFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BED00:
    // 0x800BED00: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800BED04: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800BED08: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800BED0C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800BED10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BED14: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BED18: swc1        $f4, 0xDC0($at)
    MEM_W(0XDC0, ctx->r1) = ctx->f4.u32l;
    // 0x800BED1C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BED20: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800BED24: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BED28: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800BED2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BED30: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800BED34: swc1        $f6, 0xDC4($at)
    MEM_W(0XDC4, ctx->r1) = ctx->f6.u32l;
    // 0x800BED38: b           L_800BED40
    // 0x800BED3C: nop

        goto L_800BED40;
    // 0x800BED3C: nop

L_800BED40:
    // 0x800BED40: jr          $ra
    // 0x800BED44: nop

    return;
    // 0x800BED44: nop

;}
RECOMP_FUNC void func_80073360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073368: jal         0x8005F064
    // 0x8007336C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8007336C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_0:
    // 0x80073370: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073374: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073378: bne         $v0, $zero, L_80073390
    if (ctx->r2 != 0) {
        // 0x8007337C: nop
    
            goto L_80073390;
    }
    // 0x8007337C: nop

    // 0x80073380: jal         0x80061488
    // 0x80073384: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80073384: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    after_1:
    // 0x80073388: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007338C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80073390:
    // 0x80073390: b           L_800733A0
    // 0x80073394: nop

        goto L_800733A0;
    // 0x80073394: nop

    // 0x80073398: b           L_800733A0
    // 0x8007339C: nop

        goto L_800733A0;
    // 0x8007339C: nop

L_800733A0:
    // 0x800733A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800733A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800733A8: jr          $ra
    // 0x800733AC: nop

    return;
    // 0x800733AC: nop

;}
RECOMP_FUNC void func_80081B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081B90: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80081B94: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80081B98: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80081B9C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80081BA0: addiu       $t6, $t6, 0x2848
    ctx->r14 = ADD32(ctx->r14, 0X2848);
    // 0x80081BA4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80081BA8: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80081BAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081BB0: beq         $t7, $at, L_80081C98
    if (ctx->r15 == ctx->r1) {
        // 0x80081BB4: nop
    
            goto L_80081C98;
    }
    // 0x80081BB4: nop

L_80081BB8:
    // 0x80081BB8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80081BBC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80081BC0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80081BC4: addiu       $t0, $t0, 0x2848
    ctx->r8 = ADD32(ctx->r8, 0X2848);
    // 0x80081BC8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80081BCC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80081BD0: lb          $t2, 0x3($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X3);
    // 0x80081BD4: nop

    // 0x80081BD8: bne         $t2, $a3, L_80081C70
    if (ctx->r10 != ctx->r7) {
        // 0x80081BDC: nop
    
            goto L_80081C70;
    }
    // 0x80081BDC: nop

    // 0x80081BE0: lb          $t3, 0x4($t1)
    ctx->r11 = MEM_B(ctx->r9, 0X4);
    // 0x80081BE4: lh          $t4, 0x1A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1A);
    // 0x80081BE8: nop

    // 0x80081BEC: bne         $t3, $t4, L_80081C70
    if (ctx->r11 != ctx->r12) {
        // 0x80081BF0: nop
    
            goto L_80081C70;
    }
    // 0x80081BF0: nop

    // 0x80081BF4: lb          $t5, 0x5($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X5);
    // 0x80081BF8: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80081BFC: nop

    // 0x80081C00: bne         $t5, $t6, L_80081C70
    if (ctx->r13 != ctx->r14) {
        // 0x80081C04: nop
    
            goto L_80081C70;
    }
    // 0x80081C04: nop

    // 0x80081C08: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80081C0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80081C10: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80081C14: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80081C18: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80081C1C: lb          $t9, 0x2848($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X2848);
    // 0x80081C20: nop

    // 0x80081C24: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80081C28: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80081C2C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80081C30: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x80081C34: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80081C38: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80081C3C: lb          $t3, 0x2849($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X2849);
    // 0x80081C40: nop

    // 0x80081C44: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80081C48: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80081C4C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80081C50: sll         $t1, $t4, 3
    ctx->r9 = S32(ctx->r12 << 3);
    // 0x80081C54: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x80081C58: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80081C5C: lb          $t5, 0x284A($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X284A);
    // 0x80081C60: nop

    // 0x80081C64: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x80081C68: b           L_80081CE0
    // 0x80081C6C: nop

        goto L_80081CE0;
    // 0x80081C6C: nop

L_80081C70:
    // 0x80081C70: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80081C74: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80081C78: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80081C7C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80081C80: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80081C84: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80081C88: lb          $t9, 0x2848($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X2848);
    // 0x80081C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081C90: bne         $t9, $at, L_80081BB8
    if (ctx->r25 != ctx->r1) {
        // 0x80081C94: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80081BB8;
    }
    // 0x80081C94: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_80081C98:
    // 0x80081C98: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x80081C9C: nop

    // 0x80081CA0: bne         $t0, $zero, L_80081CC0
    if (ctx->r8 != 0) {
        // 0x80081CA4: nop
    
            goto L_80081CC0;
    }
    // 0x80081CA4: nop

    // 0x80081CA8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80081CAC: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x80081CB0: addiu       $t3, $zero, 0x47
    ctx->r11 = ADD32(0, 0X47);
    // 0x80081CB4: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80081CB8: b           L_80081CD8
    // 0x80081CBC: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
        goto L_80081CD8;
    // 0x80081CBC: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
L_80081CC0:
    // 0x80081CC0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80081CC4: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x80081CC8: addiu       $t1, $zero, 0x48
    ctx->r9 = ADD32(0, 0X48);
    // 0x80081CCC: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80081CD0: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80081CD4: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
L_80081CD8:
    // 0x80081CD8: b           L_80081CE0
    // 0x80081CDC: nop

        goto L_80081CE0;
    // 0x80081CDC: nop

L_80081CE0:
    // 0x80081CE0: jr          $ra
    // 0x80081CE4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80081CE4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006BB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BB34: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BB38: nop

    // 0x8006BB3C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BB40: nop

    // 0x8006BB44: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006BB48: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BB4C: jr          $ra
    // 0x8006BB50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BB50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BB54: jr          $ra
    // 0x8006BB58: nop

    return;
    // 0x8006BB58: nop

    // 0x8006BB5C: jr          $ra
    // 0x8006BB60: nop

    return;
    // 0x8006BB60: nop

;}
RECOMP_FUNC void func_800764E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800764E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800764E8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800764EC: nop

    // 0x800764F0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800764F4: nop

    // 0x800764F8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800764FC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076500: jr          $ra
    // 0x80076504: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076504: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076508: jr          $ra
    // 0x8007650C: nop

    return;
    // 0x8007650C: nop

    // 0x80076510: jr          $ra
    // 0x80076514: nop

    return;
    // 0x80076514: nop

;}
RECOMP_FUNC void func_800674E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800674E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800674E4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800674E8: nop

    // 0x800674EC: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x800674F0: nop

    // 0x800674F4: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x800674F8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800674FC: jr          $ra
    // 0x80067500: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067500: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067504: jr          $ra
    // 0x80067508: nop

    return;
    // 0x80067508: nop

    // 0x8006750C: jr          $ra
    // 0x80067510: nop

    return;
    // 0x80067510: nop

;}
RECOMP_FUNC void func_80072FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072FEC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072FF0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072FF4: nop

    // 0x80072FF8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072FFC: nop

    // 0x80073000: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80073004: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073008: jr          $ra
    // 0x8007300C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007300C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073010: jr          $ra
    // 0x80073014: nop

    return;
    // 0x80073014: nop

    // 0x80073018: jr          $ra
    // 0x8007301C: nop

    return;
    // 0x8007301C: nop

;}
RECOMP_FUNC void func_800663C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800663CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800663D0: jal         0x80061348
    // 0x800663D4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800663D4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x800663D8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800663DC: b           L_800663EC
    // 0x800663E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800663EC;
    // 0x800663E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800663E4: b           L_800663EC
    // 0x800663E8: nop

        goto L_800663EC;
    // 0x800663E8: nop

L_800663EC:
    // 0x800663EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800663F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800663F4: jr          $ra
    // 0x800663F8: nop

    return;
    // 0x800663F8: nop

;}
RECOMP_FUNC void func_8002C0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C0FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002C10C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002C110: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8002C114: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C118: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002C11C: nop

    // 0x8002C120: sh          $t7, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r15;
    // 0x8002C124: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8002C128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C12C: sw          $t8, 0x1658($at)
    MEM_W(0X1658, ctx->r1) = ctx->r24;
    // 0x8002C130: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002C134: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C138: sh          $t9, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = ctx->r25;
    // 0x8002C13C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C140: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002C144: jal         0x8002BB04
    // 0x8002C148: nop

    func_8002BB04(rdram, ctx);
        goto after_0;
    // 0x8002C148: nop

    after_0:
    // 0x8002C14C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C150: swc1        $f0, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f0.u32l;
    // 0x8002C154: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002C158: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002C15C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002C160: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002C164: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C168: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002C16C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C170: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002C174: swc1        $f16, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f16.u32l;
    // 0x8002C178: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002C17C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002C180: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C184: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C188: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002C18C: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002C190: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C194: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002C198: swc1        $f10, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f10.u32l;
    // 0x8002C19C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C1A0: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002C1A4: lwc1        $f5, -0x18F0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X18F0);
    // 0x8002C1A8: lwc1        $f4, -0x18EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X18EC);
    // 0x8002C1AC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C1B0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8002C1B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C1B8: neg.d       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = -ctx->f6.d;
    // 0x8002C1BC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002C1C0: swc1        $f10, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->f10.u32l;
    // 0x8002C1C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002C1C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002C1CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C1D0: swc1        $f16, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f16.u32l;
    // 0x8002C1D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C1D8: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002C1DC: jal         0x8002BB9C
    // 0x8002C1E0: nop

    func_8002BB9C(rdram, ctx);
        goto after_1;
    // 0x8002C1E0: nop

    after_1:
    // 0x8002C1E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C1E8: swc1        $f0, -0x69E0($at)
    MEM_W(-0X69E0, ctx->r1) = ctx->f0.u32l;
    // 0x8002C1EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002C1F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C1F4: swc1        $f18, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f18.u32l;
    // 0x8002C1F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C1FC: swc1        $f18, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f18.u32l;
    // 0x8002C200: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C204: swc1        $f18, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f18.u32l;
    // 0x8002C208: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8002C20C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002C210: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C214: swc1        $f4, 0x1650($at)
    MEM_W(0X1650, ctx->r1) = ctx->f4.u32l;
    // 0x8002C218: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8002C21C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C220: sh          $t0, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r8;
    // 0x8002C224: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002C228: lh          $t1, 0x1644($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1644);
    // 0x8002C22C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002C230: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002C234: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8002C238: lhu         $a0, -0x4772($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4772);
    // 0x8002C23C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C240: jal         0x800AFB70
    // 0x8002C244: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x8002C244: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8002C248: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002C24C: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x8002C250: b           L_8002C258
    // 0x8002C254: nop

        goto L_8002C258;
    // 0x8002C254: nop

L_8002C258:
    // 0x8002C258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C260: jr          $ra
    // 0x8002C264: nop

    return;
    // 0x8002C264: nop

    // 0x8002C268: nop

    // 0x8002C26C: nop

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
RECOMP_FUNC void func_800743E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800743E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800743E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800743EC: jal         0x80061348
    // 0x800743F0: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800743F0: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x800743F4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800743F8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800743FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074400: beq         $v0, $zero, L_80074454
    if (ctx->r2 == 0) {
        // 0x80074404: nop
    
            goto L_80074454;
    }
    // 0x80074404: nop

    // 0x80074408: jal         0x80061348
    // 0x8007440C: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007440C: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074410: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074414: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074418: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007441C: beq         $v0, $zero, L_80074454
    if (ctx->r2 == 0) {
        // 0x80074420: nop
    
            goto L_80074454;
    }
    // 0x80074420: nop

    // 0x80074424: jal         0x80061348
    // 0x80074428: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074428: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x8007442C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074430: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074434: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074438: beq         $v0, $zero, L_80074454
    if (ctx->r2 == 0) {
        // 0x8007443C: nop
    
            goto L_80074454;
    }
    // 0x8007443C: nop

    // 0x80074440: jal         0x80061348
    // 0x80074444: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074444: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074448: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007444C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074450: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074454:
    // 0x80074454: b           L_80074464
    // 0x80074458: nop

        goto L_80074464;
    // 0x80074458: nop

    // 0x8007445C: b           L_80074464
    // 0x80074460: nop

        goto L_80074464;
    // 0x80074460: nop

L_80074464:
    // 0x80074464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007446C: jr          $ra
    // 0x80074470: nop

    return;
    // 0x80074470: nop

;}
RECOMP_FUNC void func_80071884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007188C: jal         0x80061348
    // 0x80071890: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071890: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071894: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071898: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007189C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800718A0: beq         $v0, $zero, L_800718F4
    if (ctx->r2 == 0) {
        // 0x800718A4: nop
    
            goto L_800718F4;
    }
    // 0x800718A4: nop

    // 0x800718A8: jal         0x80061348
    // 0x800718AC: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800718AC: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x800718B0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800718B4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800718B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800718BC: beq         $v0, $zero, L_800718F4
    if (ctx->r2 == 0) {
        // 0x800718C0: nop
    
            goto L_800718F4;
    }
    // 0x800718C0: nop

    // 0x800718C4: jal         0x80061348
    // 0x800718C8: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800718C8: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x800718CC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800718D0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800718D4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800718D8: beq         $v0, $zero, L_800718F4
    if (ctx->r2 == 0) {
        // 0x800718DC: nop
    
            goto L_800718F4;
    }
    // 0x800718DC: nop

    // 0x800718E0: jal         0x80061348
    // 0x800718E4: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800718E4: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x800718E8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800718EC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800718F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800718F4:
    // 0x800718F4: b           L_80071904
    // 0x800718F8: nop

        goto L_80071904;
    // 0x800718F8: nop

    // 0x800718FC: b           L_80071904
    // 0x80071900: nop

        goto L_80071904;
    // 0x80071900: nop

L_80071904:
    // 0x80071904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007190C: jr          $ra
    // 0x80071910: nop

    return;
    // 0x80071910: nop

;}
RECOMP_FUNC void func_80071230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071238: jal         0x80061348
    // 0x8007123C: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007123C: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_0:
    // 0x80071240: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071244: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071248: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007124C: beq         $v0, $zero, L_800712A0
    if (ctx->r2 == 0) {
        // 0x80071250: nop
    
            goto L_800712A0;
    }
    // 0x80071250: nop

    // 0x80071254: jal         0x80061348
    // 0x80071258: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071258: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x8007125C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071260: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071264: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071268: beq         $v0, $zero, L_800712A0
    if (ctx->r2 == 0) {
        // 0x8007126C: nop
    
            goto L_800712A0;
    }
    // 0x8007126C: nop

    // 0x80071270: jal         0x80061348
    // 0x80071274: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071274: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80071278: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007127C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071280: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071284: beq         $v0, $zero, L_800712A0
    if (ctx->r2 == 0) {
        // 0x80071288: nop
    
            goto L_800712A0;
    }
    // 0x80071288: nop

    // 0x8007128C: jal         0x80061348
    // 0x80071290: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071290: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_3:
    // 0x80071294: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071298: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007129C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800712A0:
    // 0x800712A0: b           L_800712B0
    // 0x800712A4: nop

        goto L_800712B0;
    // 0x800712A4: nop

    // 0x800712A8: b           L_800712B0
    // 0x800712AC: nop

        goto L_800712B0;
    // 0x800712AC: nop

L_800712B0:
    // 0x800712B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800712B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800712B8: jr          $ra
    // 0x800712BC: nop

    return;
    // 0x800712BC: nop

;}
RECOMP_FUNC void func_8006493C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006493C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064944: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064948: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006494C: nop

    // 0x80064950: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064954: nop

    // 0x80064958: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006495C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064960: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064964: beq         $v0, $zero, L_8006497C
    if (ctx->r2 == 0) {
        // 0x80064968: nop
    
            goto L_8006497C;
    }
    // 0x80064968: nop

    // 0x8006496C: jal         0x8005F064
    // 0x80064970: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064970: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064974: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064978: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006497C:
    // 0x8006497C: b           L_8006498C
    // 0x80064980: nop

        goto L_8006498C;
    // 0x80064980: nop

    // 0x80064984: b           L_8006498C
    // 0x80064988: nop

        goto L_8006498C;
    // 0x80064988: nop

L_8006498C:
    // 0x8006498C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064994: jr          $ra
    // 0x80064998: nop

    return;
    // 0x80064998: nop

;}
RECOMP_FUNC void func_800BD9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD9D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD9D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD9D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BD9DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BD9E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800BD9E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD9E8: beq         $t6, $at, L_800BDA1C
    if (ctx->r14 == ctx->r1) {
        // 0x800BD9EC: nop
    
            goto L_800BDA1C;
    }
    // 0x800BD9EC: nop

    // 0x800BD9F0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800BD9F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD9F8: sw          $t7, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r15;
    // 0x800BD9FC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800BDA00: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800BDA04: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BDA08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800BDA0C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800BDA10: addiu       $t0, $t0, -0x4130
    ctx->r8 = ADD32(ctx->r8, -0X4130);
    // 0x800BDA14: jal         0x800C4640
    // 0x800BDA18: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x800BDA18: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_0:
L_800BDA1C:
    // 0x800BDA1C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDA20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDA24: beq         $t1, $at, L_800BDA40
    if (ctx->r9 == ctx->r1) {
        // 0x800BDA28: nop
    
            goto L_800BDA40;
    }
    // 0x800BDA28: nop

    // 0x800BDA2C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BDA30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BDA34: sw          $t2, 0x168C($at)
    MEM_W(0X168C, ctx->r1) = ctx->r10;
    // 0x800BDA38: jal         0x800CB680
    // 0x800BDA3C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_1;
    // 0x800BDA3C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_1:
L_800BDA40:
    // 0x800BDA40: b           L_800BDA48
    // 0x800BDA44: nop

        goto L_800BDA48;
    // 0x800BDA44: nop

L_800BDA48:
    // 0x800BDA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BDA50: jr          $ra
    // 0x800BDA54: nop

    return;
    // 0x800BDA54: nop

;}
RECOMP_FUNC void func_800736D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800736D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800736D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800736D8: nop

    // 0x800736DC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800736E0: nop

    // 0x800736E4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800736E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800736EC: jr          $ra
    // 0x800736F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800736F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800736F4: jr          $ra
    // 0x800736F8: nop

    return;
    // 0x800736F8: nop

    // 0x800736FC: jr          $ra
    // 0x80073700: nop

    return;
    // 0x80073700: nop

;}
RECOMP_FUNC void alSynSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3E78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D3E7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D3E80: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D3E84: beql        $t6, $zero, L_800D3EE8
    if (ctx->r14 == 0) {
        // 0x800D3E88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3EE8;
    }
    goto skip_0;
    // 0x800D3E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3E8C: jal         0x800C7C00
    // 0x800D3E90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D3E90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D3E94: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3E98: beq         $v0, $zero, L_800D3EE4
    if (ctx->r2 == 0) {
        // 0x800D3E9C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D3EE4;
    }
    // 0x800D3E9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3EA0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D3EA4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D3EA8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800D3EAC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D3EB0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D3EB4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D3EB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D3EBC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D3EC0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D3EC4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D3EC8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D3ECC: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800D3ED0: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800D3ED4: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800D3ED8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D3EDC: jalr        $t9
    // 0x800D3EE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D3EE0: nop

    after_1:
L_800D3EE4:
    // 0x800D3EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3EE8:
    // 0x800D3EE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3EEC: jr          $ra
    // 0x800D3EF0: nop

    return;
    // 0x800D3EF0: nop

;}
RECOMP_FUNC void func_8006CA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CA70: jal         0x8005F064
    // 0x8006CA74: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CA74: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_0:
    // 0x8006CA78: b           L_8006CA88
    // 0x8006CA7C: nop

        goto L_8006CA88;
    // 0x8006CA7C: nop

    // 0x8006CA80: b           L_8006CA88
    // 0x8006CA84: nop

        goto L_8006CA88;
    // 0x8006CA84: nop

L_8006CA88:
    // 0x8006CA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CA8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CA90: jr          $ra
    // 0x8006CA94: nop

    return;
    // 0x8006CA94: nop

;}
RECOMP_FUNC void func_80083AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80083AD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80083AD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80083ADC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083AE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80083AE4: sh          $t6, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r14;
    // 0x80083AE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80083AEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80083AF0: sh          $t7, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r15;
    // 0x80083AF4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083AF8: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083AFC: nop

    // 0x80083B00: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80083B04: nop

    // 0x80083B08: andi        $t0, $t9, 0x800
    ctx->r8 = ctx->r25 & 0X800;
    // 0x80083B0C: beq         $t0, $zero, L_80083B30
    if (ctx->r8 == 0) {
        // 0x80083B10: nop
    
            goto L_80083B30;
    }
    // 0x80083B10: nop

    // 0x80083B14: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80083B18: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80083B1C: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x80083B20: nop

    // 0x80083B24: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80083B28: b           L_80083B48
    // 0x80083B2C: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
        goto L_80083B48;
    // 0x80083B2C: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
L_80083B30:
    // 0x80083B30: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80083B34: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80083B38: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80083B3C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80083B40: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80083B44: sh          $t6, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r14;
L_80083B48:
    // 0x80083B48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80083B4C: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x80083B50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80083B54: lh          $s0, 0xBEC($t7)
    ctx->r16 = MEM_H(ctx->r15, 0XBEC);
    // 0x80083B58: nop

    // 0x80083B5C: beq         $s0, $at, L_80083B78
    if (ctx->r16 == ctx->r1) {
        // 0x80083B60: nop
    
            goto L_80083B78;
    }
    // 0x80083B60: nop

    // 0x80083B64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80083B68: beq         $s0, $at, L_80083B8C
    if (ctx->r16 == ctx->r1) {
        // 0x80083B6C: nop
    
            goto L_80083B8C;
    }
    // 0x80083B6C: nop

    // 0x80083B70: b           L_80083BA0
    // 0x80083B74: nop

        goto L_80083BA0;
    // 0x80083B74: nop

L_80083B78:
    // 0x80083B78: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x80083B7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80083B80: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x80083B84: b           L_80083BB0
    // 0x80083B88: nop

        goto L_80083BB0;
    // 0x80083B88: nop

L_80083B8C:
    // 0x80083B8C: addiu       $t9, $zero, 0x1F6
    ctx->r25 = ADD32(0, 0X1F6);
    // 0x80083B90: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80083B94: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
    // 0x80083B98: b           L_80083BB0
    // 0x80083B9C: nop

        goto L_80083BB0;
    // 0x80083B9C: nop

L_80083BA0:
    // 0x80083BA0: jal         0x80083F28
    // 0x80083BA4: nop

    func_80083F28(rdram, ctx);
        goto after_0;
    // 0x80083BA4: nop

    after_0:
    // 0x80083BA8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80083BAC: sh          $v0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r2;
L_80083BB0:
    // 0x80083BB0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083BB4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083BB8: jal         0x8008AA44
    // 0x80083BBC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_8008AA44(rdram, ctx);
        goto after_1;
    // 0x80083BBC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_1:
    // 0x80083BC0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083BC4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083BC8: jal         0x8008AA44
    // 0x80083BCC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_8008AA44(rdram, ctx);
        goto after_2;
    // 0x80083BCC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_2:
    // 0x80083BD0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083BD4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083BD8: jal         0x8008AA44
    // 0x80083BDC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_8008AA44(rdram, ctx);
        goto after_3;
    // 0x80083BDC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_3:
    // 0x80083BE0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80083BE4: lw          $t0, 0x7B4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B4C);
    // 0x80083BE8: nop

    // 0x80083BEC: lw          $a0, 0x72C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X72C);
    // 0x80083BF0: jal         0x800BC980
    // 0x80083BF4: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x80083BF4: nop

    after_4:
    // 0x80083BF8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083BFC: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083C00: nop

    // 0x80083C04: lw          $t3, 0x734($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X734);
    // 0x80083C08: nop

    // 0x80083C0C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80083C10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80083C14: nop

    // 0x80083C18: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80083C1C: nop

    // 0x80083C20: beq         $t5, $zero, L_80083C64
    if (ctx->r13 == 0) {
        // 0x80083C24: nop
    
            goto L_80083C64;
    }
    // 0x80083C24: nop

L_80083C28:
    // 0x80083C28: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80083C2C: nop

    // 0x80083C30: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80083C34: jal         0x800BC980
    // 0x80083C38: nop

    SysMem_Free(rdram, ctx);
        goto after_5;
    // 0x80083C38: nop

    after_5:
    // 0x80083C3C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80083C40: nop

    // 0x80083C44: addiu       $t7, $t4, 0x4
    ctx->r15 = ADD32(ctx->r12, 0X4);
    // 0x80083C48: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80083C4C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80083C50: nop

    // 0x80083C54: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80083C58: nop

    // 0x80083C5C: bne         $t9, $zero, L_80083C28
    if (ctx->r25 != 0) {
        // 0x80083C60: nop
    
            goto L_80083C28;
    }
    // 0x80083C60: nop

L_80083C64:
    // 0x80083C64: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80083C68: lw          $t0, 0x7B4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B4C);
    // 0x80083C6C: nop

    // 0x80083C70: lw          $a0, 0x734($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X734);
    // 0x80083C74: jal         0x800BC980
    // 0x80083C78: nop

    SysMem_Free(rdram, ctx);
        goto after_6;
    // 0x80083C78: nop

    after_6:
    // 0x80083C7C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083C80: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083C84: nop

    // 0x80083C88: lw          $a0, 0x730($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X730);
    // 0x80083C8C: jal         0x800BC980
    // 0x80083C90: nop

    SysMem_Free(rdram, ctx);
        goto after_7;
    // 0x80083C90: nop

    after_7:
    // 0x80083C94: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083C98: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x80083C9C: nop

    // 0x80083CA0: lw          $t1, 0x738($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X738);
    // 0x80083CA4: nop

    // 0x80083CA8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80083CAC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80083CB0: nop

    // 0x80083CB4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80083CB8: nop

    // 0x80083CBC: beq         $t6, $zero, L_80083D00
    if (ctx->r14 == 0) {
        // 0x80083CC0: nop
    
            goto L_80083D00;
    }
    // 0x80083CC0: nop

L_80083CC4:
    // 0x80083CC4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80083CC8: nop

    // 0x80083CCC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80083CD0: jal         0x800BC980
    // 0x80083CD4: nop

    SysMem_Free(rdram, ctx);
        goto after_8;
    // 0x80083CD4: nop

    after_8:
    // 0x80083CD8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80083CDC: nop

    // 0x80083CE0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80083CE4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80083CE8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80083CEC: nop

    // 0x80083CF0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80083CF4: nop

    // 0x80083CF8: bne         $t0, $zero, L_80083CC4
    if (ctx->r8 != 0) {
        // 0x80083CFC: nop
    
            goto L_80083CC4;
    }
    // 0x80083CFC: nop

L_80083D00:
    // 0x80083D00: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083D04: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083D08: nop

    // 0x80083D0C: lw          $a0, 0x738($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X738);
    // 0x80083D10: jal         0x800BC980
    // 0x80083D14: nop

    SysMem_Free(rdram, ctx);
        goto after_9;
    // 0x80083D14: nop

    after_9:
    // 0x80083D18: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083D1C: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x80083D20: nop

    // 0x80083D24: lw          $a0, 0x728($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X728);
    // 0x80083D28: jal         0x8001AE90
    // 0x80083D2C: nop

    func_8001AE90(rdram, ctx);
        goto after_10;
    // 0x80083D2C: nop

    after_10:
    // 0x80083D30: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083D34: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x80083D38: nop

    // 0x80083D3C: lw          $a0, 0x728($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X728);
    // 0x80083D40: jal         0x800BC980
    // 0x80083D44: nop

    SysMem_Free(rdram, ctx);
        goto after_11;
    // 0x80083D44: nop

    after_11:
    // 0x80083D48: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80083D4C:
    // 0x80083D4C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80083D50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083D54: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083D58: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80083D5C: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80083D60: lw          $t8, 0xC04($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC04);
    // 0x80083D64: nop

    // 0x80083D68: beq         $t8, $zero, L_80083D90
    if (ctx->r24 == 0) {
        // 0x80083D6C: nop
    
            goto L_80083D90;
    }
    // 0x80083D6C: nop

    // 0x80083D70: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80083D74: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083D78: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083D7C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80083D80: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80083D84: lw          $a0, 0xC04($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC04);
    // 0x80083D88: jal         0x800BC980
    // 0x80083D8C: nop

    SysMem_Free(rdram, ctx);
        goto after_12;
    // 0x80083D8C: nop

    after_12:
L_80083D90:
    // 0x80083D90: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80083D94: nop

    // 0x80083D98: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x80083D9C: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80083DA0: bne         $at, $zero, L_80083D4C
    if (ctx->r1 != 0) {
        // 0x80083DA4: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_80083D4C;
    }
    // 0x80083DA4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80083DA8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083DAC: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083DB0: nop

    // 0x80083DB4: lw          $a0, 0xC10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC10);
    // 0x80083DB8: jal         0x800BC980
    // 0x80083DBC: nop

    SysMem_Free(rdram, ctx);
        goto after_13;
    // 0x80083DBC: nop

    after_13:
    // 0x80083DC0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083DC4: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083DC8: jal         0x800BC980
    // 0x80083DCC: nop

    SysMem_Free(rdram, ctx);
        goto after_14;
    // 0x80083DCC: nop

    after_14:
    // 0x80083DD0: jal         0x80031728
    // 0x80083DD4: nop

    func_80031728(rdram, ctx);
        goto after_15;
    // 0x80083DD4: nop

    after_15:
    // 0x80083DD8: jal         0x80031C04
    // 0x80083DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80031C04(rdram, ctx);
        goto after_16;
    // 0x80083DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80083DE0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083DE4: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083DE8: nop

    // 0x80083DEC: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x80083DF0: nop

    // 0x80083DF4: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x80083DF8: bne         $t8, $zero, L_80083E08
    if (ctx->r24 != 0) {
        // 0x80083DFC: nop
    
            goto L_80083E08;
    }
    // 0x80083DFC: nop

    // 0x80083E00: jal         0x80021F20
    // 0x80083E04: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_17;
    // 0x80083E04: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_17:
L_80083E08:
    // 0x80083E08: b           L_80083E18
    // 0x80083E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80083E18;
    // 0x80083E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80083E10: b           L_80083E18
    // 0x80083E14: nop

        goto L_80083E18;
    // 0x80083E14: nop

L_80083E18:
    // 0x80083E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80083E1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80083E20: jr          $ra
    // 0x80083E24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80083E24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006C948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C950: jal         0x8005F064
    // 0x8006C954: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C954: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    after_0:
    // 0x8006C958: b           L_8006C968
    // 0x8006C95C: nop

        goto L_8006C968;
    // 0x8006C95C: nop

    // 0x8006C960: b           L_8006C968
    // 0x8006C964: nop

        goto L_8006C968;
    // 0x8006C964: nop

L_8006C968:
    // 0x8006C968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C96C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C970: jr          $ra
    // 0x8006C974: nop

    return;
    // 0x8006C974: nop

;}
RECOMP_FUNC void func_800857BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800857C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800857C4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800857C8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800857CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800857D0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800857D4: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x800857D8: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x800857DC: lhu         $t9, 0x46($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X46);
    // 0x800857E0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800857E4: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x800857E8: beq         $t0, $zero, L_80085978
    if (ctx->r8 == 0) {
        // 0x800857EC: nop
    
            goto L_80085978;
    }
    // 0x800857EC: nop

    // 0x800857F0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800857F4: jal         0x8008A518
    // 0x800857F8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800857F8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800857FC: beq         $v0, $zero, L_80085978
    if (ctx->r2 == 0) {
        // 0x80085800: nop
    
            goto L_80085978;
    }
    // 0x80085800: nop

    // 0x80085804: lhu         $t1, 0x34($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X34);
    // 0x80085808: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8008580C: bne         $t1, $at, L_80085830
    if (ctx->r9 != ctx->r1) {
        // 0x80085810: nop
    
            goto L_80085830;
    }
    // 0x80085810: nop

    // 0x80085814: jal         0x8008CE48
    // 0x80085818: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80085818: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x8008581C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80085820: nop

    // 0x80085824: sh          $zero, 0xBEC($t2)
    MEM_H(0XBEC, ctx->r10) = 0;
    // 0x80085828: b           L_800859CC
    // 0x8008582C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_800859CC;
    // 0x8008582C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80085830:
    // 0x80085830: lhu         $t3, 0x34($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X34);
    // 0x80085834: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80085838: slt         $at, $t3, $at
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8008583C: bne         $at, $zero, L_80085978
    if (ctx->r1 != 0) {
        // 0x80085840: nop
    
            goto L_80085978;
    }
    // 0x80085840: nop

    // 0x80085844: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80085848: slt         $at, $t3, $at
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8008584C: beq         $at, $zero, L_80085978
    if (ctx->r1 == 0) {
        // 0x80085850: nop
    
            goto L_80085978;
    }
    // 0x80085850: nop

    // 0x80085854: lhu         $t4, 0x34($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X34);
    // 0x80085858: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x8008585C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80085860: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80085864: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80085868: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008586C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80085870: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085874: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x80085878: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x8008587C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80085880: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80085884: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80085888: nop

    // 0x8008588C: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x80085890: nop

    // 0x80085894: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80085898: beq         $t1, $zero, L_80085964
    if (ctx->r9 == 0) {
        // 0x8008589C: nop
    
            goto L_80085964;
    }
    // 0x8008589C: nop

    // 0x800858A0: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x800858A4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800858A8: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800858AC: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800858B0: sh          $t3, 0xBFE($t4)
    MEM_H(0XBFE, ctx->r12) = ctx->r11;
    // 0x800858B4: jal         0x8008CE48
    // 0x800858B8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x800858B8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x800858BC: lh          $t5, 0x3C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3C);
    // 0x800858C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800858C4: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x800858C8: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
    // 0x800858CC: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
    // 0x800858D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800858D4: jal         0x8008A368
    // 0x800858D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8008A368(rdram, ctx);
        goto after_3;
    // 0x800858D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x800858DC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800858E0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800858E4: jal         0x800898D8
    // 0x800858E8: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800898D8(rdram, ctx);
        goto after_4;
    // 0x800858E8: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_4:
    // 0x800858EC: beq         $v0, $zero, L_8008593C
    if (ctx->r2 == 0) {
        // 0x800858F0: nop
    
            goto L_8008593C;
    }
    // 0x800858F0: nop

    // 0x800858F4: lh          $t6, 0x2A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A);
    // 0x800858F8: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    // 0x800858FC: lh          $t8, 0x2C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2C);
    // 0x80085900: lh          $t0, 0x30($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X30);
    // 0x80085904: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80085908: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    // 0x8008590C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80085910: bgez        $a1, L_80085920
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80085914: sra         $t9, $a1, 1
        ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80085920;
    }
    // 0x80085914: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80085918: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8008591C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80085920:
    // 0x80085920: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80085924: bgez        $a2, L_80085934
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80085928: sra         $t1, $a2, 1
        ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80085934;
    }
    // 0x80085928: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x8008592C: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80085930: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80085934:
    // 0x80085934: jal         0x80089B04
    // 0x80085938: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_80089B04(rdram, ctx);
        goto after_5;
    // 0x80085938: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_5:
L_8008593C:
    // 0x8008593C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80085940: nop

    // 0x80085944: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80085948: nop

    // 0x8008594C: ori         $t4, $t3, 0x200
    ctx->r12 = ctx->r11 | 0X200;
    // 0x80085950: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80085954: b           L_800859CC
    // 0x80085958: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_800859CC;
    // 0x80085958: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8008595C: b           L_80085978
    // 0x80085960: nop

        goto L_80085978;
    // 0x80085960: nop

L_80085964:
    // 0x80085964: jal         0x8008CE48
    // 0x80085968: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80085968: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_6:
    // 0x8008596C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80085970: jal         0x8008A730
    // 0x80085974: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_7;
    // 0x80085974: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_7:
L_80085978:
    // 0x80085978: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008597C: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x80085980: lhu         $t5, 0x46($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X46);
    // 0x80085984: nop

    // 0x80085988: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8008598C: beq         $t7, $zero, L_800859B0
    if (ctx->r15 == 0) {
        // 0x80085990: nop
    
            goto L_800859B0;
    }
    // 0x80085990: nop

    // 0x80085994: jal         0x8008CE48
    // 0x80085998: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80085998: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_8:
    // 0x8008599C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800859A0: nop

    // 0x800859A4: sh          $zero, 0xBEC($t9)
    MEM_H(0XBEC, ctx->r25) = 0;
    // 0x800859A8: b           L_800859CC
    // 0x800859AC: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_800859CC;
    // 0x800859AC: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_800859B0:
    // 0x800859B0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800859B4: nop

    // 0x800859B8: lh          $v0, 0x4($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X4);
    // 0x800859BC: b           L_800859CC
    // 0x800859C0: nop

        goto L_800859CC;
    // 0x800859C0: nop

    // 0x800859C4: b           L_800859CC
    // 0x800859C8: nop

        goto L_800859CC;
    // 0x800859C8: nop

L_800859CC:
    // 0x800859CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800859D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800859D4: jr          $ra
    // 0x800859D8: nop

    return;
    // 0x800859D8: nop

;}
