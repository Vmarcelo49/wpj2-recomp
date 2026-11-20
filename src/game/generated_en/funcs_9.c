#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8005A768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A768: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A770: jal         0x80061F08
    // 0x8005A774: nop

    func_80061F08(rdram, ctx);
        goto after_0;
    // 0x8005A774: nop

    after_0:
    // 0x8005A778: beq         $v0, $zero, L_8005A788
    if (ctx->r2 == 0) {
        // 0x8005A77C: nop

            goto L_8005A788;
    }
    // 0x8005A77C: nop

    // 0x8005A780: b           L_8005A7B0
    // 0x8005A784: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_8005A7B0;
    // 0x8005A784: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_8005A788:
    // 0x8005A788: jal         0x80061E14
    // 0x8005A78C: nop

    func_80061E14(rdram, ctx);
        goto after_1;
    // 0x8005A78C: nop

    after_1:
    // 0x8005A790: beq         $v0, $zero, L_8005A7A0
    if (ctx->r2 == 0) {
        // 0x8005A794: nop

            goto L_8005A7A0;
    }
    // 0x8005A794: nop

    // 0x8005A798: b           L_8005A7B0
    // 0x8005A79C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
        goto L_8005A7B0;
    // 0x8005A79C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_8005A7A0:
    // 0x8005A7A0: b           L_8005A7B0
    // 0x8005A7A4: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
        goto L_8005A7B0;
    // 0x8005A7A4: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // 0x8005A7A8: b           L_8005A7B0
    // 0x8005A7AC: nop

        goto L_8005A7B0;
    // 0x8005A7AC: nop

L_8005A7B0:
    // 0x8005A7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A7B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A7B8: jr          $ra
    // 0x8005A7BC: nop

    return;
    // 0x8005A7BC: nop

;}
RECOMP_FUNC void func_8005A7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A7C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A7C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A7C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A7CC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005A7D0: nop

    // 0x8005A7D4: lh          $t7, 0x4E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4E);
    // 0x8005A7D8: nop

    // 0x8005A7DC: beq         $t7, $zero, L_8005A7EC
    if (ctx->r15 == 0) {
        // 0x8005A7E0: nop

            goto L_8005A7EC;
    }
    // 0x8005A7E0: nop

    // 0x8005A7E4: b           L_8005A860
    // 0x8005A7E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A860;
    // 0x8005A7E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A7EC:
    // 0x8005A7EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005A7F0: addiu       $t8, $t8, 0x4C20
    ctx->r24 = ADD32(ctx->r24, 0X4C20);
    // 0x8005A7F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005A7F8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8005A7FC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005A800: beq         $t9, $at, L_8005A850
    if (ctx->r25 == ctx->r1) {
        // 0x8005A804: nop

            goto L_8005A850;
    }
    // 0x8005A804: nop

L_8005A808:
    // 0x8005A808: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A80C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A810: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8005A814: lbu         $a0, 0x4C20($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4C20);
    // 0x8005A818: jal         0x8005F064
    // 0x8005A81C: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8005A81C: nop

    after_0:
    // 0x8005A820: bne         $v0, $zero, L_8005A830
    if (ctx->r2 != 0) {
        // 0x8005A824: nop

            goto L_8005A830;
    }
    // 0x8005A824: nop

    // 0x8005A828: b           L_8005A860
    // 0x8005A82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A860;
    // 0x8005A82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A830:
    // 0x8005A830: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A834: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8005A838: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8005A83C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005A840: lbu         $t3, 0x4C20($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4C20);
    // 0x8005A844: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005A848: bne         $t3, $at, L_8005A808
    if (ctx->r11 != ctx->r1) {
        // 0x8005A84C: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8005A808;
    }
    // 0x8005A84C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_8005A850:
    // 0x8005A850: b           L_8005A860
    // 0x8005A854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005A860;
    // 0x8005A854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A858: b           L_8005A860
    // 0x8005A85C: nop

        goto L_8005A860;
    // 0x8005A85C: nop

L_8005A860:
    // 0x8005A860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A864: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A868: jr          $ra
    // 0x8005A86C: nop

    return;
    // 0x8005A86C: nop

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
RECOMP_FUNC void func_8005A9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A9A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005A9A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005A9A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005A9AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005A9B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A9B4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005A9B8: nop

    // 0x8005A9BC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8005A9C0: jal         0x8005F268
    // 0x8005A9C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F268(rdram, ctx);
        goto after_0;
    // 0x8005A9C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8005A9C8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8005A9CC: nop

    // 0x8005A9D0: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8005A9D4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005A9D8: nop

    // 0x8005A9DC: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8005A9E0: nop

    // 0x8005A9E4: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8005A9E8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005A9EC: nop

    // 0x8005A9F0: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8005A9F4: jal         0x80098754
    // 0x8005A9F8: nop

    func_80098754(rdram, ctx);
        goto after_1;
    // 0x8005A9F8: nop

    after_1:
    // 0x8005A9FC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AA00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005AA04: sh          $t1, 0x7C($t2)
    MEM_H(0X7C, ctx->r10) = ctx->r9;
    // 0x8005AA08: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005AA0C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005AA10: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005AA14: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8005AA18: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005AA1C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8005AA20: bne         $t6, $zero, L_8005AA64
    if (ctx->r14 != 0) {
        // 0x8005AA24: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_8005AA64;
    }
    // 0x8005AA24: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005AA28: bne         $t7, $zero, L_8005AA64
    if (ctx->r15 != 0) {
        // 0x8005AA2C: nop

            goto L_8005AA64;
    }
    // 0x8005AA2C: nop

L_8005AA30:
    // 0x8005AA30: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AA34: jal         0x800499B0
    // 0x8005AA38: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8005AA38: nop

    after_2:
    // 0x8005AA3C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005AA40: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005AA44: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005AA48: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005AA4C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005AA50: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005AA54: bne         $t2, $zero, L_8005AA64
    if (ctx->r10 != 0) {
        // 0x8005AA58: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8005AA64;
    }
    // 0x8005AA58: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8005AA5C: beq         $t3, $zero, L_8005AA30
    if (ctx->r11 == 0) {
        // 0x8005AA60: nop

            goto L_8005AA30;
    }
    // 0x8005AA60: nop

L_8005AA64:
    // 0x8005AA64: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8005AA68: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8005AA6C: lhu         $t4, 0x0($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X0);
    // 0x8005AA70: nop

    // 0x8005AA74: andi        $t5, $t4, 0x402
    ctx->r13 = ctx->r12 & 0X402;
    // 0x8005AA78: beq         $t5, $zero, L_8005AAA8
    if (ctx->r13 == 0) {
        // 0x8005AA7C: nop

            goto L_8005AAA8;
    }
    // 0x8005AA7C: nop

L_8005AA80:
    // 0x8005AA80: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AA84: jal         0x800499B0
    // 0x8005AA88: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8005AA88: nop

    after_3:
    // 0x8005AA8C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8005AA90: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8005AA94: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8005AA98: nop

    // 0x8005AA9C: andi        $t8, $t7, 0x402
    ctx->r24 = ctx->r15 & 0X402;
    // 0x8005AAA0: bne         $t8, $zero, L_8005AA80
    if (ctx->r24 != 0) {
        // 0x8005AAA4: nop

            goto L_8005AA80;
    }
    // 0x8005AAA4: nop

L_8005AAA8:
    // 0x8005AAA8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005AAAC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005AAB0: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005AAB4: lw          $t0, 0xE70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE70);
    // 0x8005AAB8: nop

    // 0x8005AABC: sw          $t0, 0xB0($t1)
    MEM_W(0XB0, ctx->r9) = ctx->r8;
    // 0x8005AAC0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005AAC4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8005AAC8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005AACC: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8005AAD0: addiu       $t9, $t9, 0x1270
    ctx->r25 = ADD32(ctx->r25, 0X1270);
    // 0x8005AAD4: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x8005AAD8: jal         0x8005F064
    // 0x8005AADC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_8005F064(rdram, ctx);
        goto after_4;
    // 0x8005AADC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_4:
    // 0x8005AAE0: beq         $v0, $zero, L_8005AAFC
    if (ctx->r2 == 0) {
        // 0x8005AAE4: nop

            goto L_8005AAFC;
    }
    // 0x8005AAE4: nop

    // 0x8005AAE8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005AAEC: addiu       $t5, $t5, 0x1270
    ctx->r13 = ADD32(ctx->r13, 0X1270);
    // 0x8005AAF0: addiu       $t4, $zero, 0x3E7
    ctx->r12 = ADD32(0, 0X3E7);
    // 0x8005AAF4: b           L_8005AB48
    // 0x8005AAF8: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
        goto L_8005AB48;
    // 0x8005AAF8: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
L_8005AAFC:
    // 0x8005AAFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005AB00: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005AB04: nop

    // 0x8005AB08: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x8005AB0C: nop

    // 0x8005AB10: slti        $at, $t7, 0x399
    ctx->r1 = SIGNED(ctx->r15) < 0X399 ? 1 : 0;
    // 0x8005AB14: bne         $at, $zero, L_8005AB30
    if (ctx->r1 != 0) {
        // 0x8005AB18: nop

            goto L_8005AB30;
    }
    // 0x8005AB18: nop

    // 0x8005AB1C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005AB20: addiu       $t0, $t0, 0x1270
    ctx->r8 = ADD32(ctx->r8, 0X1270);
    // 0x8005AB24: addiu       $t8, $zero, 0x398
    ctx->r24 = ADD32(0, 0X398);
    // 0x8005AB28: b           L_8005AB48
    // 0x8005AB2C: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
        goto L_8005AB48;
    // 0x8005AB2C: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
L_8005AB30:
    // 0x8005AB30: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005AB34: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005AB38: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005AB3C: lh          $t2, 0x6($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6);
    // 0x8005AB40: addiu       $t3, $t3, 0x1270
    ctx->r11 = ADD32(ctx->r11, 0X1270);
    // 0x8005AB44: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
L_8005AB48:
    // 0x8005AB48: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005AB4C: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8005AB50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005AB54: lh          $t4, 0x8($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X8);
    // 0x8005AB58: addiu       $t5, $t5, 0x1270
    ctx->r13 = ADD32(ctx->r13, 0X1270);
    // 0x8005AB5C: sh          $t4, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r12;
    // 0x8005AB60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005AB64: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005AB68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005AB6C: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8005AB70: addiu       $t8, $t8, 0x1270
    ctx->r24 = ADD32(ctx->r24, 0X1270);
    // 0x8005AB74: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x8005AB78: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005AB7C: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8005AB80: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005AB84: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8005AB88: addiu       $t2, $t2, 0x1270
    ctx->r10 = ADD32(ctx->r10, 0X1270);
    // 0x8005AB8C: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x8005AB90: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005AB94: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005AB98: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005AB9C: lh          $t9, 0x28($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X28);
    // 0x8005ABA0: addiu       $t4, $t4, 0x1270
    ctx->r12 = ADD32(ctx->r12, 0X1270);
    // 0x8005ABA4: sh          $t9, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r25;
    // 0x8005ABA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005ABAC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005ABB0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005ABB4: addiu       $t5, $t5, 0x1270
    ctx->r13 = ADD32(ctx->r13, 0X1270);
    // 0x8005ABB8: sw          $t5, 0xB4($t6)
    MEM_W(0XB4, ctx->r14) = ctx->r13;
    // 0x8005ABBC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005ABC0: jal         0x800507AC
    // 0x8005ABC4: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    func_800507AC(rdram, ctx);
        goto after_5;
    // 0x8005ABC4: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    after_5:
    // 0x8005ABC8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ABCC: nop

    // 0x8005ABD0: sw          $zero, 0xA8($t7)
    MEM_W(0XA8, ctx->r15) = 0;
    // 0x8005ABD4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ABD8: nop

    // 0x8005ABDC: lw          $t0, 0xA8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XA8);
    // 0x8005ABE0: nop

    // 0x8005ABE4: sw          $t0, 0xA4($t8)
    MEM_W(0XA4, ctx->r24) = ctx->r8;
    // 0x8005ABE8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ABEC: nop

    // 0x8005ABF0: lh          $t2, 0xAC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XAC);
    // 0x8005ABF4: nop

    // 0x8005ABF8: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8005ABFC: sh          $t3, 0xAC($t1)
    MEM_H(0XAC, ctx->r9) = ctx->r11;
    // 0x8005AC00: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8005AC04:
    // 0x8005AC04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005AC08: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005AC0C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005AC10: lh          $t4, 0x7C($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X7C);
    // 0x8005AC14: nop

    // 0x8005AC18: bne         $t4, $at, L_8005AC2C
    if (ctx->r12 != ctx->r1) {
        // 0x8005AC1C: nop

            goto L_8005AC2C;
    }
    // 0x8005AC1C: nop

    // 0x8005AC20: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AC24: b           L_8005AC34
    // 0x8005AC28: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
        goto L_8005AC34;
    // 0x8005AC28: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
L_8005AC2C:
    // 0x8005AC2C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AC30: addiu       $s0, $s0, 0x1290
    ctx->r16 = ADD32(ctx->r16, 0X1290);
L_8005AC34:
    // 0x8005AC34: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AC38: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AC3C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005AC40: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005AC44: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x8005AC48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005AC4C: jal         0x8005B110
    // 0x8005AC50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8005B110(rdram, ctx);
        goto after_6;
    // 0x8005AC50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_6:
    // 0x8005AC54: beq         $v0, $zero, L_8005AC70
    if (ctx->r2 == 0) {
        // 0x8005AC58: nop

            goto L_8005AC70;
    }
    // 0x8005AC58: nop

    // 0x8005AC5C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AC60: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005AC64: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005AC68: jal         0x8005B490
    // 0x8005AC6C: addiu       $a2, $a2, 0x1270
    ctx->r6 = ADD32(ctx->r6, 0X1270);
    func_8005B490(rdram, ctx);
        goto after_7;
    // 0x8005AC6C: addiu       $a2, $a2, 0x1270
    ctx->r6 = ADD32(ctx->r6, 0X1270);
    after_7:
L_8005AC70:
    // 0x8005AC70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AC74: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AC78: jal         0x8005B610
    // 0x8005AC7C: nop

    func_8005B610(rdram, ctx);
        goto after_8;
    // 0x8005AC7C: nop

    after_8:
    // 0x8005AC80: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AC84: jal         0x800499B0
    // 0x8005AC88: nop

    func_800499B0(rdram, ctx);
        goto after_9;
    // 0x8005AC88: nop

    after_9:
    // 0x8005AC8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005AC90: nop

    // 0x8005AC94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005AC98: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8005AC9C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ACA0: nop

    // 0x8005ACA4: lh          $t8, 0xAC($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XAC);
    // 0x8005ACA8: nop

    // 0x8005ACAC: andi        $t2, $t8, 0x40
    ctx->r10 = ctx->r24 & 0X40;
    // 0x8005ACB0: bne         $t2, $zero, L_8005ACE4
    if (ctx->r10 != 0) {
        // 0x8005ACB4: nop

            goto L_8005ACE4;
    }
    // 0x8005ACB4: nop

    // 0x8005ACB8: lw          $t3, 0xA4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XA4);
    // 0x8005ACBC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8005ACC0: bne         $t3, $at, L_8005AC04
    if (ctx->r11 != ctx->r1) {
        // 0x8005ACC4: nop

            goto L_8005AC04;
    }
    // 0x8005ACC4: nop

    // 0x8005ACC8: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8005ACCC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005ACD0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005ACD4: bne         $t6, $zero, L_8005ACE4
    if (ctx->r14 != 0) {
        // 0x8005ACD8: andi        $t7, $t5, 0x2
        ctx->r15 = ctx->r13 & 0X2;
            goto L_8005ACE4;
    }
    // 0x8005ACD8: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x8005ACDC: beq         $t7, $zero, L_8005AC04
    if (ctx->r15 == 0) {
        // 0x8005ACE0: nop

            goto L_8005AC04;
    }
    // 0x8005ACE0: nop

L_8005ACE4:
    // 0x8005ACE4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005ACE8: nop

    // 0x8005ACEC: lh          $t9, 0xAC($t1)
    ctx->r25 = MEM_H(ctx->r9, 0XAC);
    // 0x8005ACF0: nop

    // 0x8005ACF4: andi        $t8, $t9, 0x40
    ctx->r24 = ctx->r25 & 0X40;
    // 0x8005ACF8: bne         $t8, $zero, L_8005AD10
    if (ctx->r24 != 0) {
        // 0x8005ACFC: nop

            goto L_8005AD10;
    }
    // 0x8005ACFC: nop

    // 0x8005AD00: jal         0x8005F0DC
    // 0x8005AD04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8005F0DC(rdram, ctx);
        goto after_10;
    // 0x8005AD04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x8005AD08: b           L_8005AD28
    // 0x8005AD0C: nop

        goto L_8005AD28;
    // 0x8005AD0C: nop

L_8005AD10:
    // 0x8005AD10: addiu       $t2, $zero, 0xFE
    ctx->r10 = ADD32(0, 0XFE);
    // 0x8005AD14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005AD18: sb          $t2, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r10;
    // 0x8005AD1C: addiu       $t3, $zero, 0x1F
    ctx->r11 = ADD32(0, 0X1F);
    // 0x8005AD20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005AD24: sh          $t3, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r11;
L_8005AD28:
    // 0x8005AD28: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AD2C: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8005AD30: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8005AD34: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005AD38: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005AD3C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005AD40: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005AD44: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8005AD48: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005AD4C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD50: nop

    // 0x8005AD54: sb          $zero, 0x20($t1)
    MEM_B(0X20, ctx->r9) = 0;
    // 0x8005AD58: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD5C: nop

    // 0x8005AD60: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8005AD64: jal         0x80098AD8
    // 0x8005AD68: nop

    func_80098AD8(rdram, ctx);
        goto after_11;
    // 0x8005AD68: nop

    after_11:
    // 0x8005AD6C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD70: jal         0x80049544
    // 0x8005AD74: nop

    func_80049544(rdram, ctx);
        goto after_12;
    // 0x8005AD74: nop

    after_12:
    // 0x8005AD78: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD7C: nop

    // 0x8005AD80: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8005AD84: jal         0x800C0D34
    // 0x8005AD88: nop

    Thread_StopThread(rdram, ctx);
        goto after_13;
    // 0x8005AD88: nop

    after_13:
L_8005AD8C:
    // 0x8005AD8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AD90: jal         0x800499B0
    // 0x8005AD94: nop

    func_800499B0(rdram, ctx);
        goto after_14;
    // 0x8005AD94: nop

    after_14:
    // 0x8005AD98: b           L_8005AD8C
    // 0x8005AD9C: nop

        goto L_8005AD8C;
    // 0x8005AD9C: nop

    // 0x8005ADA0: b           L_8005ADA8
    // 0x8005ADA4: nop

        goto L_8005ADA8;
    // 0x8005ADA4: nop

L_8005ADA8:
    // 0x8005ADA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005ADAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005ADB0: jr          $ra
    // 0x8005ADB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005ADB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005ADB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ADB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005ADBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005ADC0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005ADC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005ADC8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8005ADCC: nop

    // 0x8005ADD0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8005ADD4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005ADD8: nop

    // 0x8005ADDC: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8005ADE0: nop

    // 0x8005ADE4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8005ADE8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005ADEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005ADF0: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x8005ADF4: lw          $t0, 0x2F9($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2F9);
    // 0x8005ADF8: nop

    // 0x8005ADFC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8005AE00: sw          $t0, 0xE70($at)
    MEM_W(0XE70, ctx->r1) = ctx->r8;
    // 0x8005AE04: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005AE08: lw          $t1, 0xE70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE70);
    // 0x8005AE0C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005AE10: lh          $t2, 0x7C($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X7C);
    // 0x8005AE14: nop

    // 0x8005AE18: bne         $t2, $at, L_8005AE30
    if (ctx->r10 != ctx->r1) {
        // 0x8005AE1C: nop

            goto L_8005AE30;
    }
    // 0x8005AE1C: nop

    // 0x8005AE20: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005AE24: addiu       $t3, $t3, 0x1280
    ctx->r11 = ADD32(ctx->r11, 0X1280);
    // 0x8005AE28: b           L_8005AE44
    // 0x8005AE2C: sw          $t3, 0xB4($t1)
    MEM_W(0XB4, ctx->r9) = ctx->r11;
        goto L_8005AE44;
    // 0x8005AE2C: sw          $t3, 0xB4($t1)
    MEM_W(0XB4, ctx->r9) = ctx->r11;
L_8005AE30:
    // 0x8005AE30: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005AE34: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x8005AE38: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005AE3C: addiu       $t4, $t4, 0x1290
    ctx->r12 = ADD32(ctx->r12, 0X1290);
    // 0x8005AE40: sw          $t4, 0xB4($t5)
    MEM_W(0XB4, ctx->r13) = ctx->r12;
L_8005AE44:
    // 0x8005AE44: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AE48: nop

    // 0x8005AE4C: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8005AE50: jal         0x80098754
    // 0x8005AE54: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8005AE54: nop

    after_0:
    // 0x8005AE58: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AE5C: jal         0x80032410
    // 0x8005AE60: nop

    func_80032410(rdram, ctx);
        goto after_1;
    // 0x8005AE60: nop

    after_1:
    // 0x8005AE64: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005AE68: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005AE6C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005AE70: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8005AE74: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005AE78: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005AE7C: bne         $t0, $zero, L_8005AEC0
    if (ctx->r8 != 0) {
        // 0x8005AE80: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8005AEC0;
    }
    // 0x8005AE80: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005AE84: bne         $t1, $zero, L_8005AEC0
    if (ctx->r9 != 0) {
        // 0x8005AE88: nop

            goto L_8005AEC0;
    }
    // 0x8005AE88: nop

L_8005AE8C:
    // 0x8005AE8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AE90: jal         0x800499B0
    // 0x8005AE94: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8005AE94: nop

    after_2:
    // 0x8005AE98: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005AE9C: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005AEA0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005AEA4: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8005AEA8: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005AEAC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8005AEB0: bne         $t6, $zero, L_8005AEC0
    if (ctx->r14 != 0) {
        // 0x8005AEB4: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_8005AEC0;
    }
    // 0x8005AEB4: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005AEB8: beq         $t7, $zero, L_8005AE8C
    if (ctx->r15 == 0) {
        // 0x8005AEBC: nop

            goto L_8005AE8C;
    }
    // 0x8005AEBC: nop

L_8005AEC0:
    // 0x8005AEC0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8005AEC4: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8005AEC8: lhu         $t8, 0x0($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X0);
    // 0x8005AECC: nop

    // 0x8005AED0: andi        $t9, $t8, 0x402
    ctx->r25 = ctx->r24 & 0X402;
    // 0x8005AED4: beq         $t9, $zero, L_8005AF04
    if (ctx->r25 == 0) {
        // 0x8005AED8: nop

            goto L_8005AF04;
    }
    // 0x8005AED8: nop

L_8005AEDC:
    // 0x8005AEDC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AEE0: jal         0x800499B0
    // 0x8005AEE4: nop

    func_800499B0(rdram, ctx);
        goto after_3;
    // 0x8005AEE4: nop

    after_3:
    // 0x8005AEE8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8005AEEC: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8005AEF0: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8005AEF4: nop

    // 0x8005AEF8: andi        $t2, $t1, 0x402
    ctx->r10 = ctx->r9 & 0X402;
    // 0x8005AEFC: bne         $t2, $zero, L_8005AEDC
    if (ctx->r10 != 0) {
        // 0x8005AF00: nop

            goto L_8005AEDC;
    }
    // 0x8005AF00: nop

L_8005AF04:
    // 0x8005AF04: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005AF08: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005AF0C: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x8005AF10: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005AF14: nop

    // 0x8005AF18: sw          $t4, 0xB0($t5)
    MEM_W(0XB0, ctx->r13) = ctx->r12;
    // 0x8005AF1C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF20: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AF24: lh          $a2, 0x7C($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X7C);
    // 0x8005AF28: lw          $a3, 0x44($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X44);
    // 0x8005AF2C: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x8005AF30: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005AF34: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005AF38: jal         0x80050A24
    // 0x8005AF3C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80050A24(rdram, ctx);
        goto after_4;
    // 0x8005AF3C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_4:
    // 0x8005AF40: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF44: nop

    // 0x8005AF48: sw          $zero, 0xA8($t3)
    MEM_W(0XA8, ctx->r11) = 0;
    // 0x8005AF4C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF50: nop

    // 0x8005AF54: lw          $t9, 0xA8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XA8);
    // 0x8005AF58: nop

    // 0x8005AF5C: sw          $t9, 0xA4($t8)
    MEM_W(0XA4, ctx->r24) = ctx->r25;
    // 0x8005AF60: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF64: nop

    // 0x8005AF68: lh          $t1, 0xAC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XAC);
    // 0x8005AF6C: nop

    // 0x8005AF70: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x8005AF74: sh          $t2, 0xAC($t0)
    MEM_H(0XAC, ctx->r8) = ctx->r10;
    // 0x8005AF78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005AF7C:
    // 0x8005AF7C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005AF80: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005AF84: lh          $t5, 0x7C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X7C);
    // 0x8005AF88: nop

    // 0x8005AF8C: bne         $t5, $at, L_8005AFA0
    if (ctx->r13 != ctx->r1) {
        // 0x8005AF90: nop

            goto L_8005AFA0;
    }
    // 0x8005AF90: nop

    // 0x8005AF94: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AF98: b           L_8005AFA8
    // 0x8005AF9C: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
        goto L_8005AFA8;
    // 0x8005AF9C: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
L_8005AFA0:
    // 0x8005AFA0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AFA4: addiu       $s0, $s0, 0x1290
    ctx->r16 = ADD32(ctx->r16, 0X1290);
L_8005AFA8:
    // 0x8005AFA8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005AFAC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005AFB0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AFB4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005AFB8: addiu       $a2, $a2, 0x1270
    ctx->r6 = ADD32(ctx->r6, 0X1270);
    // 0x8005AFBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005AFC0: jal         0x8005B110
    // 0x8005AFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8005B110(rdram, ctx);
        goto after_5;
    // 0x8005AFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_5:
    // 0x8005AFC8: beq         $v0, $zero, L_8005B00C
    if (ctx->r2 == 0) {
        // 0x8005AFCC: nop

            goto L_8005B00C;
    }
    // 0x8005AFCC: nop

    // 0x8005AFD0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005AFD4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005AFD8: lh          $t3, 0x7C($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X7C);
    // 0x8005AFDC: nop

    // 0x8005AFE0: bne         $t3, $at, L_8005AFF4
    if (ctx->r11 != ctx->r1) {
        // 0x8005AFE4: nop

            goto L_8005AFF4;
    }
    // 0x8005AFE4: nop

    // 0x8005AFE8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AFEC: b           L_8005AFFC
    // 0x8005AFF0: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
        goto L_8005AFFC;
    // 0x8005AFF0: addiu       $s0, $s0, 0x1280
    ctx->r16 = ADD32(ctx->r16, 0X1280);
L_8005AFF4:
    // 0x8005AFF4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005AFF8: addiu       $s0, $s0, 0x1290
    ctx->r16 = ADD32(ctx->r16, 0X1290);
L_8005AFFC:
    // 0x8005AFFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005B000: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B004: jal         0x8005B490
    // 0x8005B008: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8005B490(rdram, ctx);
        goto after_6;
    // 0x8005B008: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
L_8005B00C:
    // 0x8005B00C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005B010: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B014: jal         0x8005B610
    // 0x8005B018: nop

    func_8005B610(rdram, ctx);
        goto after_7;
    // 0x8005B018: nop

    after_7:
    // 0x8005B01C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B020: jal         0x800499B0
    // 0x8005B024: nop

    func_800499B0(rdram, ctx);
        goto after_8;
    // 0x8005B024: nop

    after_8:
    // 0x8005B028: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B02C: nop

    // 0x8005B030: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8005B034: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8005B038: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005B03C: nop

    // 0x8005B040: lh          $t2, 0xAC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XAC);
    // 0x8005B044: nop

    // 0x8005B048: andi        $t0, $t2, 0x40
    ctx->r8 = ctx->r10 & 0X40;
    // 0x8005B04C: bne         $t0, $zero, L_8005B080
    if (ctx->r8 != 0) {
        // 0x8005B050: nop

            goto L_8005B080;
    }
    // 0x8005B050: nop

    // 0x8005B054: lw          $t4, 0xA4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XA4);
    // 0x8005B058: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8005B05C: bne         $t4, $at, L_8005AF7C
    if (ctx->r12 != ctx->r1) {
        // 0x8005B060: nop

            goto L_8005AF7C;
    }
    // 0x8005B060: nop

    // 0x8005B064: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8005B068: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8005B06C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005B070: bne         $t8, $zero, L_8005B080
    if (ctx->r24 != 0) {
        // 0x8005B074: andi        $t9, $t7, 0x2
        ctx->r25 = ctx->r15 & 0X2;
            goto L_8005B080;
    }
    // 0x8005B074: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x8005B078: beq         $t9, $zero, L_8005AF7C
    if (ctx->r25 == 0) {
        // 0x8005B07C: nop

            goto L_8005AF7C;
    }
    // 0x8005B07C: nop

L_8005B080:
    // 0x8005B080: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8005B084: lui         $at, 0x7F7F
    ctx->r1 = S32(0X7F7F << 16);
    // 0x8005B088: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8005B08C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005B090: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005B094: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8005B098: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8005B09C: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8005B0A0: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x8005B0A4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0A8: nop

    // 0x8005B0AC: sb          $zero, 0x20($t4)
    MEM_B(0X20, ctx->r12) = 0;
    // 0x8005B0B0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0B4: nop

    // 0x8005B0B8: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8005B0BC: jal         0x80098AD8
    // 0x8005B0C0: nop

    func_80098AD8(rdram, ctx);
        goto after_9;
    // 0x8005B0C0: nop

    after_9:
    // 0x8005B0C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0C8: jal         0x80049544
    // 0x8005B0CC: nop

    func_80049544(rdram, ctx);
        goto after_10;
    // 0x8005B0CC: nop

    after_10:
    // 0x8005B0D0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0D4: nop

    // 0x8005B0D8: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8005B0DC: jal         0x800C0D34
    // 0x8005B0E0: nop

    Thread_StopThread(rdram, ctx);
        goto after_11;
    // 0x8005B0E0: nop

    after_11:
L_8005B0E4:
    // 0x8005B0E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B0E8: jal         0x800499B0
    // 0x8005B0EC: nop

    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x8005B0EC: nop

    after_12:
    // 0x8005B0F0: b           L_8005B0E4
    // 0x8005B0F4: nop

        goto L_8005B0E4;
    // 0x8005B0F4: nop

    // 0x8005B0F8: b           L_8005B100
    // 0x8005B0FC: nop

        goto L_8005B100;
    // 0x8005B0FC: nop

L_8005B100:
    // 0x8005B100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005B104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005B108: jr          $ra
    // 0x8005B10C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005B10C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005B110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B110: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005B114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005B118: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005B11C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005B120: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005B124: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8005B128: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005B12C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B130: nop

    // 0x8005B134: lh          $t7, 0xAC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XAC);
    // 0x8005B138: nop

    // 0x8005B13C: andi        $t8, $t7, 0xD
    ctx->r24 = ctx->r15 & 0XD;
    // 0x8005B140: beq         $t8, $zero, L_8005B470
    if (ctx->r24 == 0) {
        // 0x8005B144: nop

            goto L_8005B470;
    }
    // 0x8005B144: nop

    // 0x8005B148: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B14C: nop

    // 0x8005B150: lh          $t0, 0xAC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XAC);
    // 0x8005B154: nop

    // 0x8005B158: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8005B15C: beq         $t1, $zero, L_8005B2B0
    if (ctx->r9 == 0) {
        // 0x8005B160: nop

            goto L_8005B2B0;
    }
    // 0x8005B160: nop

    // 0x8005B164: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005B168: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8005B16C: lh          $t3, 0xAC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XAC);
    // 0x8005B170: nop

    // 0x8005B174: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8005B178: sh          $t4, 0xAC($t2)
    MEM_H(0XAC, ctx->r10) = ctx->r12;
    // 0x8005B17C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005B180: nop

    // 0x8005B184: lh          $t6, 0xAC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XAC);
    // 0x8005B188: nop

    // 0x8005B18C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8005B190: sh          $t7, 0xAC($t5)
    MEM_H(0XAC, ctx->r13) = ctx->r15;
    // 0x8005B194: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B198: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8005B19C: sw          $t8, 0xA8($t9)
    MEM_W(0XA8, ctx->r25) = ctx->r24;
    // 0x8005B1A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005B1A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005B1A8: sw          $t0, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->r8;
    // 0x8005B1AC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005B1B0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005B1B4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005B1B8: nop

    // 0x8005B1BC: bne         $t3, $t4, L_8005B1D4
    if (ctx->r11 != ctx->r12) {
        // 0x8005B1C0: nop

            goto L_8005B1D4;
    }
    // 0x8005B1C0: nop

    // 0x8005B1C4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005B1C8: lw          $s0, 0xE70($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XE70);
    // 0x8005B1CC: b           L_8005B1E0
    // 0x8005B1D0: nop

        goto L_8005B1E0;
    // 0x8005B1D0: nop

L_8005B1D4:
    // 0x8005B1D4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005B1D8: lw          $s0, 0xE64($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XE64);
    // 0x8005B1DC: nop

L_8005B1E0:
    // 0x8005B1E0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005B1E4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8005B1E8: jal         0x8005CB6C
    // 0x8005B1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005CB6C(rdram, ctx);
        goto after_0;
    // 0x8005B1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8005B1F0: bne         $v0, $zero, L_8005B20C
    if (ctx->r2 != 0) {
        // 0x8005B1F4: nop

            goto L_8005B20C;
    }
    // 0x8005B1F4: nop

    // 0x8005B1F8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B1FC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8005B200: sw          $t2, 0xA8($t6)
    MEM_W(0XA8, ctx->r14) = ctx->r10;
    // 0x8005B204: b           L_8005B480
    // 0x8005B208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B20C:
    // 0x8005B20C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005B210: nop

    // 0x8005B214: lh          $t5, 0xAC($t7)
    ctx->r13 = MEM_H(ctx->r15, 0XAC);
    // 0x8005B218: nop

    // 0x8005B21C: andi        $t8, $t5, 0x80
    ctx->r24 = ctx->r13 & 0X80;
    // 0x8005B220: beq         $t8, $zero, L_8005B2A0
    if (ctx->r24 == 0) {
        // 0x8005B224: nop

            goto L_8005B2A0;
    }
    // 0x8005B224: nop

    // 0x8005B228: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B22C: nop

    // 0x8005B230: lwc1        $f4, 0x24($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X24);
    // 0x8005B234: nop

    // 0x8005B238: add.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x8005B23C: swc1        $f6, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f6.u32l;
    // 0x8005B240: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005B244: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8005B248: lh          $t1, 0xAC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XAC);
    // 0x8005B24C: nop

    // 0x8005B250: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8005B254: sh          $t3, 0xAC($t0)
    MEM_H(0XAC, ctx->r8) = ctx->r11;
    // 0x8005B258: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005B25C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005B260: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8005B264: nop

    // 0x8005B268: bne         $t4, $t2, L_8005B2A0
    if (ctx->r12 != ctx->r10) {
        // 0x8005B26C: nop

            goto L_8005B2A0;
    }
    // 0x8005B26C: nop

    // 0x8005B270: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005B274: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B278: nop

    // 0x8005B27C: swc1        $f8, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f8.u32l;
    // 0x8005B280: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005B284: nop

    // 0x8005B288: lwc1        $f10, 0x30($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8005B28C: nop

    // 0x8005B290: swc1        $f10, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f10.u32l;
    // 0x8005B294: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005B298: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8005B29C: sw          $t5, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = ctx->r13;
L_8005B2A0:
    // 0x8005B2A0: b           L_8005B480
    // 0x8005B2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005B2A8: b           L_8005B470
    // 0x8005B2AC: nop

        goto L_8005B470;
    // 0x8005B2AC: nop

L_8005B2B0:
    // 0x8005B2B0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B2B4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005B2B8: lw          $t1, 0xA4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XA4);
    // 0x8005B2BC: nop

    // 0x8005B2C0: beq         $t1, $at, L_8005B39C
    if (ctx->r9 == ctx->r1) {
        // 0x8005B2C4: nop

            goto L_8005B39C;
    }
    // 0x8005B2C4: nop

    // 0x8005B2C8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005B2CC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005B2D0: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8005B2D4: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8005B2D8: bne         $t4, $zero, L_8005B2E8
    if (ctx->r12 != 0) {
        // 0x8005B2DC: andi        $t5, $t1, 0x8
        ctx->r13 = ctx->r9 & 0X8;
            goto L_8005B2E8;
    }
    // 0x8005B2DC: andi        $t5, $t1, 0x8
    ctx->r13 = ctx->r9 & 0X8;
    // 0x8005B2E0: beq         $t5, $zero, L_8005B304
    if (ctx->r13 == 0) {
        // 0x8005B2E4: nop

            goto L_8005B304;
    }
    // 0x8005B2E4: nop

L_8005B2E8:
    // 0x8005B2E8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005B2EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005B2F0: lw          $a1, 0x24($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X24);
    // 0x8005B2F4: jal         0x8005D07C
    // 0x8005B2F8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_8005D07C(rdram, ctx);
        goto after_1;
    // 0x8005B2F8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
    // 0x8005B2FC: b           L_8005B324
    // 0x8005B300: nop

        goto L_8005B324;
    // 0x8005B300: nop

L_8005B304:
    // 0x8005B304: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B308: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005B30C: lwc1        $f16, 0x24($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X24);
    // 0x8005B310: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8005B314: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8005B318: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005B31C: jal         0x8005D07C
    // 0x8005B320: nop

    func_8005D07C(rdram, ctx);
        goto after_2;
    // 0x8005B320: nop

    after_2:
L_8005B324:
    // 0x8005B324: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005B328: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8005B32C: lwc1        $f4, 0x24($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X24);
    // 0x8005B330: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8005B334: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005B338: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005B33C: swc1        $f8, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f8.u32l;
    // 0x8005B340: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005B344: nop

    // 0x8005B348: lwc1        $f10, 0x24($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X24);
    // 0x8005B34C: nop

    // 0x8005B350: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B354: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x8005B358: nop

    // 0x8005B35C: bc1f        L_8005B39C
    if (!c1cs) {
        // 0x8005B360: nop

            goto L_8005B39C;
    }
    // 0x8005B360: nop

    // 0x8005B364: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B368: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B36C: nop

    // 0x8005B370: swc1        $f4, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f4.u32l;
    // 0x8005B374: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005B378: nop

    // 0x8005B37C: lwc1        $f6, 0x30($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X30);
    // 0x8005B380: nop

    // 0x8005B384: swc1        $f6, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f6.u32l;
    // 0x8005B388: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005B38C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005B390: addiu       $a0, $t0, 0x4C
    ctx->r4 = ADD32(ctx->r8, 0X4C);
    // 0x8005B394: jal         0x800B2CBC
    // 0x8005B398: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    func_800B2CBC(rdram, ctx);
        goto after_3;
    // 0x8005B398: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    after_3:
L_8005B39C:
    // 0x8005B39C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005B3A0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005B3A4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8005B3A8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8005B3AC: bne         $t2, $zero, L_8005B3BC
    if (ctx->r10 != 0) {
        // 0x8005B3B0: andi        $t3, $t5, 0x2
        ctx->r11 = ctx->r13 & 0X2;
            goto L_8005B3BC;
    }
    // 0x8005B3B0: andi        $t3, $t5, 0x2
    ctx->r11 = ctx->r13 & 0X2;
    // 0x8005B3B4: beq         $t3, $zero, L_8005B468
    if (ctx->r11 == 0) {
        // 0x8005B3B8: nop

            goto L_8005B468;
    }
    // 0x8005B3B8: nop

L_8005B3BC:
    // 0x8005B3BC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005B3C0: nop

    // 0x8005B3C4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005B3C8: nop

    // 0x8005B3CC: beq         $t7, $zero, L_8005B448
    if (ctx->r15 == 0) {
        // 0x8005B3D0: nop

            goto L_8005B448;
    }
    // 0x8005B3D0: nop

    // 0x8005B3D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005B3D8: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x8005B3DC: lh          $t9, 0x4A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4A);
    // 0x8005B3E0: nop

    // 0x8005B3E4: bne         $t9, $at, L_8005B420
    if (ctx->r25 != ctx->r1) {
        // 0x8005B3E8: nop

            goto L_8005B420;
    }
    // 0x8005B3E8: nop

    // 0x8005B3EC: lw          $t0, 0xA4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XA4);
    // 0x8005B3F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005B3F4: bne         $t0, $at, L_8005B420
    if (ctx->r8 != ctx->r1) {
        // 0x8005B3F8: nop

            goto L_8005B420;
    }
    // 0x8005B3F8: nop

    // 0x8005B3FC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005B400: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005B404: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8005B408: lh          $a1, 0x42($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X42);
    // 0x8005B40C: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    // 0x8005B410: jal         0x8004EF90
    // 0x8005B414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_4;
    // 0x8005B414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8005B418: b           L_8005B480
    // 0x8005B41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B420:
    // 0x8005B420: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8005B424: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8005B428: lh          $t5, 0xAC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XAC);
    // 0x8005B42C: nop

    // 0x8005B430: and         $t2, $t5, $at
    ctx->r10 = ctx->r13 & ctx->r1;
    // 0x8005B434: sh          $t2, 0xAC($t4)
    MEM_H(0XAC, ctx->r12) = ctx->r10;
    // 0x8005B438: b           L_8005B480
    // 0x8005B43C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005B480;
    // 0x8005B43C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005B440: b           L_8005B468
    // 0x8005B444: nop

        goto L_8005B468;
    // 0x8005B444: nop

L_8005B448:
    // 0x8005B448: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005B44C: nop

    // 0x8005B450: lh          $t6, 0xAC($t3)
    ctx->r14 = MEM_H(ctx->r11, 0XAC);
    // 0x8005B454: nop

    // 0x8005B458: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8005B45C: sh          $t7, 0xAC($t3)
    MEM_H(0XAC, ctx->r11) = ctx->r15;
    // 0x8005B460: b           L_8005B480
    // 0x8005B464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B468:
    // 0x8005B468: b           L_8005B480
    // 0x8005B46C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B46C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B470:
    // 0x8005B470: b           L_8005B480
    // 0x8005B474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005B480;
    // 0x8005B474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005B478: b           L_8005B480
    // 0x8005B47C: nop

        goto L_8005B480;
    // 0x8005B47C: nop

L_8005B480:
    // 0x8005B480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B484: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005B488: jr          $ra
    // 0x8005B48C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005B48C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
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
RECOMP_FUNC void func_8005B610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B610: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005B614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005B618: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005B61C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005B620: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005B624: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B628: nop

    // 0x8005B62C: lw          $t7, 0xA4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA4);
    // 0x8005B630: lw          $t8, 0xA8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XA8);
    // 0x8005B634: nop

    // 0x8005B638: beq         $t7, $t8, L_8005B97C
    if (ctx->r15 == ctx->r24) {
        // 0x8005B63C: nop

            goto L_8005B97C;
    }
    // 0x8005B63C: nop

    // 0x8005B640: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005B644: nop

    // 0x8005B648: lw          $t0, 0xA8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XA8);
    // 0x8005B64C: nop

    // 0x8005B650: sw          $t0, 0xA4($t9)
    MEM_W(0XA4, ctx->r25) = ctx->r8;
    // 0x8005B654: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005B658: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8005B65C: lh          $t2, 0xAC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XAC);
    // 0x8005B660: nop

    // 0x8005B664: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8005B668: sh          $t3, 0xAC($t1)
    MEM_H(0XAC, ctx->r9) = ctx->r11;
    // 0x8005B66C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005B670: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005B674: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005B678: nop

    // 0x8005B67C: bne         $t4, $t5, L_8005B740
    if (ctx->r12 != ctx->r13) {
        // 0x8005B680: nop

            goto L_8005B740;
    }
    // 0x8005B680: nop

    // 0x8005B684: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005B688: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005B68C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8005B690: lh          $t7, 0xAC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XAC);
    // 0x8005B694: nop

    // 0x8005B698: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8005B69C: sh          $t8, 0xAC($t6)
    MEM_H(0XAC, ctx->r14) = ctx->r24;
    // 0x8005B6A0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005B6A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005B6A8: lw          $t9, 0xA4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XA4);
    // 0x8005B6AC: nop

    // 0x8005B6B0: bne         $t9, $at, L_8005B6EC
    if (ctx->r25 != ctx->r1) {
        // 0x8005B6B4: nop

            goto L_8005B6EC;
    }
    // 0x8005B6B4: nop

    // 0x8005B6B8: jal         0x80061E14
    // 0x8005B6BC: nop

    func_80061E14(rdram, ctx);
        goto after_0;
    // 0x8005B6BC: nop

    after_0:
    // 0x8005B6C0: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8005B6C4: bne         $v0, $at, L_8005B6EC
    if (ctx->r2 != ctx->r1) {
        // 0x8005B6C8: nop

            goto L_8005B6EC;
    }
    // 0x8005B6C8: nop

    // 0x8005B6CC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005B6D0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8005B6D4: sw          $t2, 0xA8($t3)
    MEM_W(0XA8, ctx->r11) = ctx->r10;
    // 0x8005B6D8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005B6DC: nop

    // 0x8005B6E0: lw          $t4, 0xA8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XA8);
    // 0x8005B6E4: nop

    // 0x8005B6E8: sw          $t4, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->r12;
L_8005B6EC:
    // 0x8005B6EC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8005B6F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005B6F4: lw          $t7, 0xA4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XA4);
    // 0x8005B6F8: nop

    // 0x8005B6FC: bne         $t7, $at, L_8005B738
    if (ctx->r15 != ctx->r1) {
        // 0x8005B700: nop

            goto L_8005B738;
    }
    // 0x8005B700: nop

    // 0x8005B704: jal         0x80061E14
    // 0x8005B708: nop

    func_80061E14(rdram, ctx);
        goto after_1;
    // 0x8005B708: nop

    after_1:
    // 0x8005B70C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8005B710: bne         $v0, $at, L_8005B738
    if (ctx->r2 != ctx->r1) {
        // 0x8005B714: nop

            goto L_8005B738;
    }
    // 0x8005B714: nop

    // 0x8005B718: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B71C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005B720: sw          $t8, 0xA8($t6)
    MEM_W(0XA8, ctx->r14) = ctx->r24;
    // 0x8005B724: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005B728: nop

    // 0x8005B72C: lw          $t9, 0xA8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XA8);
    // 0x8005B730: nop

    // 0x8005B734: sw          $t9, 0xA4($t0)
    MEM_W(0XA4, ctx->r8) = ctx->r25;
L_8005B738:
    // 0x8005B738: b           L_8005B75C
    // 0x8005B73C: nop

        goto L_8005B75C;
    // 0x8005B73C: nop

L_8005B740:
    // 0x8005B740: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005B744: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005B748: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8005B74C: lh          $t3, 0xAC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XAC);
    // 0x8005B750: nop

    // 0x8005B754: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8005B758: sh          $t4, 0xAC($t2)
    MEM_H(0XAC, ctx->r10) = ctx->r12;
L_8005B75C:
    // 0x8005B75C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005B760: nop

    // 0x8005B764: lw          $t5, 0xA4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XA4);
    // 0x8005B768: nop

    // 0x8005B76C: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8005B770: bne         $at, $zero, L_8005B85C
    if (ctx->r1 != 0) {
        // 0x8005B774: nop

            goto L_8005B85C;
    }
    // 0x8005B774: nop

    // 0x8005B778: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005B77C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8005B780: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
    // 0x8005B784: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B788: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005B78C: lw          $t9, 0xA4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XA4);
    // 0x8005B790: nop

    // 0x8005B794: beq         $t9, $at, L_8005B854
    if (ctx->r25 == ctx->r1) {
        // 0x8005B798: nop

            goto L_8005B854;
    }
    // 0x8005B798: nop

    // 0x8005B79C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005B7A0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005B7A4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005B7A8: nop

    // 0x8005B7AC: bne         $t0, $t3, L_8005B7D8
    if (ctx->r8 != ctx->r11) {
        // 0x8005B7B0: nop

            goto L_8005B7D8;
    }
    // 0x8005B7B0: nop

    // 0x8005B7B4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005B7B8: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005B7BC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005B7C0: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8005B7C4: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8005B7C8: andi        $t9, $t3, 0x8
    ctx->r25 = ctx->r11 & 0X8;
    // 0x8005B7CC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8005B7D0: b           L_8005B7F8
    // 0x8005B7D4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
        goto L_8005B7F8;
    // 0x8005B7D4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8005B7D8:
    // 0x8005B7D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005B7DC: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005B7E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005B7E4: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8005B7E8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8005B7EC: andi        $t1, $t7, 0x8
    ctx->r9 = ctx->r15 & 0X8;
    // 0x8005B7F0: or          $t4, $t1, $zero
    ctx->r12 = ctx->r9 | 0;
    // 0x8005B7F4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8005B7F8:
    // 0x8005B7F8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B7FC: nop

    // 0x8005B800: xori        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 ^ 0X8;
    // 0x8005B804: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8005B808: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005B80C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005B810: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8005B814: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8005B818: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x8005B81C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005B820: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x8005B824: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8005B828: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8005B82C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005B830: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B834: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8005B838: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8005B83C: or          $t7, $t2, $zero
    ctx->r15 = ctx->r10 | 0;
    // 0x8005B840: sra         $t6, $t2, 31
    ctx->r14 = S32(SIGNED(ctx->r10) >> 31);
    // 0x8005B844: or          $t0, $t4, $t6
    ctx->r8 = ctx->r12 | ctx->r14;
    // 0x8005B848: or          $t1, $t5, $t7
    ctx->r9 = ctx->r13 | ctx->r15;
    // 0x8005B84C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8005B850: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
L_8005B854:
    // 0x8005B854: b           L_8005B894
    // 0x8005B858: nop

        goto L_8005B894;
    // 0x8005B858: nop

L_8005B85C:
    // 0x8005B85C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005B860: nop

    // 0x8005B864: lw          $t8, 0xA4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0XA4);
    // 0x8005B868: nop

    // 0x8005B86C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8005B870: bne         $at, $zero, L_8005B888
    if (ctx->r1 != 0) {
        // 0x8005B874: nop

            goto L_8005B888;
    }
    // 0x8005B874: nop

    // 0x8005B878: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005B87C: addiu       $t2, $zero, 0x3E
    ctx->r10 = ADD32(0, 0X3E);
    // 0x8005B880: b           L_8005B894
    // 0x8005B884: sw          $t2, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r10;
        goto L_8005B894;
    // 0x8005B884: sw          $t2, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r10;
L_8005B888:
    // 0x8005B888: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B88C: addiu       $t5, $zero, 0x3D
    ctx->r13 = ADD32(0, 0X3D);
    // 0x8005B890: sw          $t5, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r13;
L_8005B894:
    // 0x8005B894: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005B898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B89C: lh          $s0, 0x7C($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X7C);
    // 0x8005B8A0: nop

    // 0x8005B8A4: beq         $s0, $at, L_8005B8CC
    if (ctx->r16 == ctx->r1) {
        // 0x8005B8A8: nop

            goto L_8005B8CC;
    }
    // 0x8005B8A8: nop

    // 0x8005B8AC: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005B8B0: beq         $s0, $at, L_8005B904
    if (ctx->r16 == ctx->r1) {
        // 0x8005B8B4: nop

            goto L_8005B904;
    }
    // 0x8005B8B4: nop

    // 0x8005B8B8: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8005B8BC: beq         $s0, $at, L_8005B940
    if (ctx->r16 == ctx->r1) {
        // 0x8005B8C0: nop

            goto L_8005B940;
    }
    // 0x8005B8C0: nop

    // 0x8005B8C4: b           L_8005B97C
    // 0x8005B8C8: nop

        goto L_8005B97C;
    // 0x8005B8C8: nop

L_8005B8CC:
    // 0x8005B8CC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005B8D0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005B8D4: lw          $t1, 0xA4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XA4);
    // 0x8005B8D8: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005B8DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005B8E0: sll         $t9, $t1, 1
    ctx->r25 = S32(ctx->r9 << 1);
    // 0x8005B8E4: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8005B8E8: lh          $a0, -0x26E0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X26E0);
    // 0x8005B8EC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8005B8F0: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x8005B8F4: jal         0x8004EF90
    // 0x8005B8F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_2;
    // 0x8005B8F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8005B8FC: b           L_8005B97C
    // 0x8005B900: nop

        goto L_8005B97C;
    // 0x8005B900: nop

L_8005B904:
    // 0x8005B904: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005B908: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005B90C: lw          $t2, 0xA4($t8)
    ctx->r10 = MEM_W(ctx->r24, 0XA4);
    // 0x8005B910: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005B914: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8005B918: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8005B91C: lh          $a1, 0x7C($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X7C);
    // 0x8005B920: lw          $a3, 0x44($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X44);
    // 0x8005B924: lh          $a2, -0x26C4($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X26C4);
    // 0x8005B928: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B92C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8005B930: jal         0x8004F3E8
    // 0x8005B934: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_8004F3E8(rdram, ctx);
        goto after_3;
    // 0x8005B934: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_3:
    // 0x8005B938: b           L_8005B97C
    // 0x8005B93C: nop

        goto L_8005B97C;
    // 0x8005B93C: nop

L_8005B940:
    // 0x8005B940: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B944: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005B948: lw          $t7, 0xA4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA4);
    // 0x8005B94C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005B950: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x8005B954: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8005B958: lh          $a1, 0x7C($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X7C);
    // 0x8005B95C: lw          $a3, 0x44($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X44);
    // 0x8005B960: lh          $a2, -0x26A8($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X26A8);
    // 0x8005B964: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B968: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8005B96C: jal         0x8004F3E8
    // 0x8005B970: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_8004F3E8(rdram, ctx);
        goto after_4;
    // 0x8005B970: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_4:
    // 0x8005B974: b           L_8005B97C
    // 0x8005B978: nop

        goto L_8005B97C;
    // 0x8005B978: nop

L_8005B97C:
    // 0x8005B97C: b           L_8005B984
    // 0x8005B980: nop

        goto L_8005B984;
    // 0x8005B980: nop

L_8005B984:
    // 0x8005B984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005B988: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005B98C: jr          $ra
    // 0x8005B990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005B990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005B994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B994: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B998: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005B99C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005B9A0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005B9A4: nop

    // 0x8005B9A8: bne         $a0, $t6, L_8005B9C0
    if (ctx->r4 != ctx->r14) {
        // 0x8005B9AC: nop

            goto L_8005B9C0;
    }
    // 0x8005B9AC: nop

    // 0x8005B9B0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005B9B4: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005B9B8: b           L_8005B9D0
    // 0x8005B9BC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
        goto L_8005B9D0;
    // 0x8005B9BC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_8005B9C0:
    // 0x8005B9C0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005B9C4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005B9C8: nop

    // 0x8005B9CC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_8005B9D0:
    // 0x8005B9D0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005B9D4: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005B9D8: nop

    // 0x8005B9DC: bne         $a0, $t9, L_8005B9F0
    if (ctx->r4 != ctx->r25) {
        // 0x8005B9E0: nop

            goto L_8005B9F0;
    }
    // 0x8005B9E0: nop

    // 0x8005B9E4: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8005B9E8: b           L_8005B9F8
    // 0x8005B9EC: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
        goto L_8005B9F8;
    // 0x8005B9EC: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
L_8005B9F0:
    // 0x8005B9F0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8005B9F4: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
L_8005B9F8:
    // 0x8005B9F8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005B9FC: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BA00: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8005BA04: nop

    // 0x8005BA08: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005BA0C: nop

    // 0x8005BA10: bc1f        L_8005BA3C
    if (!c1cs) {
        // 0x8005BA14: nop

            goto L_8005BA3C;
    }
    // 0x8005BA14: nop

    // 0x8005BA18: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BA20: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8005BA24: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8005BA28: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005BA2C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005BA30: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8005BA34: b           L_8005BA54
    // 0x8005BA38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
        goto L_8005BA54;
    // 0x8005BA38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8005BA3C:
    // 0x8005BA3C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BA40: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8005BA44: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8005BA48: ori         $t1, $t9, 0x8
    ctx->r9 = ctx->r25 | 0X8;
    // 0x8005BA4C: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8005BA50: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8005BA54:
    // 0x8005BA54: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005BA58: nop

    // 0x8005BA5C: lh          $t2, 0xAC($t3)
    ctx->r10 = MEM_H(ctx->r11, 0XAC);
    // 0x8005BA60: nop

    // 0x8005BA64: andi        $t4, $t2, 0x40
    ctx->r12 = ctx->r10 & 0X40;
    // 0x8005BA68: beq         $t4, $zero, L_8005BA78
    if (ctx->r12 == 0) {
        // 0x8005BA6C: nop

            goto L_8005BA78;
    }
    // 0x8005BA6C: nop

    // 0x8005BA70: b           L_8005C2FC
    // 0x8005BA74: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_8005C2FC;
    // 0x8005BA74: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_8005BA78:
    // 0x8005BA78: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005BA7C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005BA80: nop

    // 0x8005BA84: bne         $a0, $t5, L_8005BB54
    if (ctx->r4 != ctx->r13) {
        // 0x8005BA88: nop

            goto L_8005BB54;
    }
    // 0x8005BA88: nop

    // 0x8005BA8C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005BA90: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005BA94: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BA98: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8005BA9C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005BAA0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005BAA4: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8005BAA8: nop

    // 0x8005BAAC: bc1f        L_8005BAC8
    if (!c1cs) {
        // 0x8005BAB0: nop

            goto L_8005BAC8;
    }
    // 0x8005BAB0: nop

    // 0x8005BAB4: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BAB8: nop

    // 0x8005BABC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8005BAC0: b           L_8005BAE4
    // 0x8005BAC4: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
        goto L_8005BAE4;
    // 0x8005BAC4: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
L_8005BAC8:
    // 0x8005BAC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005BACC: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005BAD0: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BAD4: lwc1        $f16, 0xC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005BAD8: nop

    // 0x8005BADC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8005BAE0: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
L_8005BAE4:
    // 0x8005BAE4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BAE8: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BAEC: lwc1        $f7, -0xE70($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XE70);
    // 0x8005BAF0: lwc1        $f6, -0xE6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XE6C);
    // 0x8005BAF4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BAF8: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005BAFC: nop

    // 0x8005BB00: bc1f        L_8005BB14
    if (!c1cs) {
        // 0x8005BB04: nop

            goto L_8005BB14;
    }
    // 0x8005BB04: nop

    // 0x8005BB08: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8005BB0C: b           L_8005BB4C
    // 0x8005BB10: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
        goto L_8005BB4C;
    // 0x8005BB10: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
L_8005BB14:
    // 0x8005BB14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BB18: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BB1C: lwc1        $f19, -0xE68($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XE68);
    // 0x8005BB20: lwc1        $f18, -0xE64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XE64);
    // 0x8005BB24: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005BB28: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8005BB2C: nop

    // 0x8005BB30: bc1f        L_8005BB44
    if (!c1cs) {
        // 0x8005BB34: nop

            goto L_8005BB44;
    }
    // 0x8005BB34: nop

    // 0x8005BB38: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8005BB3C: b           L_8005BB4C
    // 0x8005BB40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
        goto L_8005BB4C;
    // 0x8005BB40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_8005BB44:
    // 0x8005BB44: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8005BB48: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
L_8005BB4C:
    // 0x8005BB4C: b           L_8005BCF8
    // 0x8005BB50: nop

        goto L_8005BCF8;
    // 0x8005BB50: nop

L_8005BB54:
    // 0x8005BB54: lh          $t1, 0x7C($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X7C);
    // 0x8005BB58: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005BB5C: bne         $t1, $at, L_8005BC28
    if (ctx->r9 != ctx->r1) {
        // 0x8005BB60: nop

            goto L_8005BC28;
    }
    // 0x8005BB60: nop

    // 0x8005BB64: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005BB68: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005BB6C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BB70: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x8005BB74: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BB78: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8005BB7C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8005BB80: nop

    // 0x8005BB84: bc1f        L_8005BBA0
    if (!c1cs) {
        // 0x8005BB88: nop

            goto L_8005BBA0;
    }
    // 0x8005BB88: nop

    // 0x8005BB8C: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BB90: nop

    // 0x8005BB94: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8005BB98: b           L_8005BBBC
    // 0x8005BB9C: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
        goto L_8005BBBC;
    // 0x8005BB9C: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
L_8005BBA0:
    // 0x8005BBA0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005BBA4: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005BBA8: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BBAC: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8005BBB0: nop

    // 0x8005BBB4: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005BBB8: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
L_8005BBBC:
    // 0x8005BBBC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BBC0: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BBC4: lwc1        $f19, -0xE60($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XE60);
    // 0x8005BBC8: lwc1        $f18, -0xE5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XE5C);
    // 0x8005BBCC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BBD0: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8005BBD4: nop

    // 0x8005BBD8: bc1f        L_8005BBE8
    if (!c1cs) {
        // 0x8005BBDC: nop

            goto L_8005BBE8;
    }
    // 0x8005BBDC: nop

    // 0x8005BBE0: b           L_8005BC20
    // 0x8005BBE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
        goto L_8005BC20;
    // 0x8005BBE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
L_8005BBE8:
    // 0x8005BBE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BBEC: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BBF0: lwc1        $f11, -0xE58($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XE58);
    // 0x8005BBF4: lwc1        $f10, -0xE54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE54);
    // 0x8005BBF8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BBFC: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8005BC00: nop

    // 0x8005BC04: bc1f        L_8005BC18
    if (!c1cs) {
        // 0x8005BC08: nop

            goto L_8005BC18;
    }
    // 0x8005BC08: nop

    // 0x8005BC0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005BC10: b           L_8005BC20
    // 0x8005BC14: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
        goto L_8005BC20;
    // 0x8005BC14: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
L_8005BC18:
    // 0x8005BC18: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005BC1C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
L_8005BC20:
    // 0x8005BC20: b           L_8005BCF8
    // 0x8005BC24: nop

        goto L_8005BCF8;
    // 0x8005BC24: nop

L_8005BC28:
    // 0x8005BC28: lh          $t6, 0x7C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X7C);
    // 0x8005BC2C: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8005BC30: bne         $t6, $at, L_8005BCF8
    if (ctx->r14 != ctx->r1) {
        // 0x8005BC34: nop

            goto L_8005BCF8;
    }
    // 0x8005BC34: nop

    // 0x8005BC38: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005BC3C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005BC40: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BC44: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005BC48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005BC4C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8005BC50: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8005BC54: nop

    // 0x8005BC58: bc1f        L_8005BC74
    if (!c1cs) {
        // 0x8005BC5C: nop

            goto L_8005BC74;
    }
    // 0x8005BC5C: nop

    // 0x8005BC60: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BC64: nop

    // 0x8005BC68: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005BC6C: b           L_8005BC90
    // 0x8005BC70: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
        goto L_8005BC90;
    // 0x8005BC70: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
L_8005BC74:
    // 0x8005BC74: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005BC78: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005BC7C: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BC80: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8005BC84: nop

    // 0x8005BC88: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005BC8C: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
L_8005BC90:
    // 0x8005BC90: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BC94: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BC98: lwc1        $f11, -0xE50($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XE50);
    // 0x8005BC9C: lwc1        $f10, -0xE4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE4C);
    // 0x8005BCA0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BCA4: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8005BCA8: nop

    // 0x8005BCAC: bc1f        L_8005BCC0
    if (!c1cs) {
        // 0x8005BCB0: nop

            goto L_8005BCC0;
    }
    // 0x8005BCB0: nop

    // 0x8005BCB4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8005BCB8: b           L_8005BCF8
    // 0x8005BCBC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
        goto L_8005BCF8;
    // 0x8005BCBC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_8005BCC0:
    // 0x8005BCC0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005BCC4: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8005BCC8: lwc1        $f5, -0xE48($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XE48);
    // 0x8005BCCC: lwc1        $f4, -0xE44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XE44);
    // 0x8005BCD0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8005BCD4: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8005BCD8: nop

    // 0x8005BCDC: bc1f        L_8005BCF0
    if (!c1cs) {
        // 0x8005BCE0: nop

            goto L_8005BCF0;
    }
    // 0x8005BCE0: nop

    // 0x8005BCE4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8005BCE8: b           L_8005BCF8
    // 0x8005BCEC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
        goto L_8005BCF8;
    // 0x8005BCEC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
L_8005BCF0:
    // 0x8005BCF0: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8005BCF4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
L_8005BCF8:
    // 0x8005BCF8: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x8005BCFC: nop

    // 0x8005BD00: andi        $t2, $t3, 0x3
    ctx->r10 = ctx->r11 & 0X3;
    // 0x8005BD04: beq         $t2, $zero, L_8005BDDC
    if (ctx->r10 == 0) {
        // 0x8005BD08: nop

            goto L_8005BDDC;
    }
    // 0x8005BD08: nop

    // 0x8005BD0C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005BD10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005BD14: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BD18: nop

    // 0x8005BD1C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8005BD20: nop

    // 0x8005BD24: bc1f        L_8005BD48
    if (!c1cs) {
        // 0x8005BD28: nop

            goto L_8005BD48;
    }
    // 0x8005BD28: nop

    // 0x8005BD2C: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8005BD30: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD34: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8005BD38: bne         $t6, $zero, L_8005BD84
    if (ctx->r14 != 0) {
        // 0x8005BD3C: andi        $t7, $t5, 0x8
        ctx->r15 = ctx->r13 & 0X8;
            goto L_8005BD84;
    }
    // 0x8005BD3C: andi        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 & 0X8;
    // 0x8005BD40: bne         $t7, $zero, L_8005BD84
    if (ctx->r15 != 0) {
        // 0x8005BD44: nop

            goto L_8005BD84;
    }
    // 0x8005BD44: nop

L_8005BD48:
    // 0x8005BD48: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8005BD4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005BD50: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005BD54: nop

    // 0x8005BD58: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005BD5C: nop

    // 0x8005BD60: bc1f        L_8005BDDC
    if (!c1cs) {
        // 0x8005BD64: nop

            goto L_8005BDDC;
    }
    // 0x8005BD64: nop

    // 0x8005BD68: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8005BD6C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005BD70: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005BD74: bne         $t0, $zero, L_8005BDDC
    if (ctx->r8 != 0) {
        // 0x8005BD78: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_8005BDDC;
    }
    // 0x8005BD78: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x8005BD7C: bne         $t1, $zero, L_8005BDDC
    if (ctx->r9 != 0) {
        // 0x8005BD80: nop

            goto L_8005BDDC;
    }
    // 0x8005BD80: nop

L_8005BD84:
    // 0x8005BD84: lh          $a3, 0x7C($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X7C);
    // 0x8005BD88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005BD8C: beq         $a3, $at, L_8005BDB4
    if (ctx->r7 == ctx->r1) {
        // 0x8005BD90: nop

            goto L_8005BDB4;
    }
    // 0x8005BD90: nop

    // 0x8005BD94: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005BD98: beq         $a3, $at, L_8005BDC4
    if (ctx->r7 == ctx->r1) {
        // 0x8005BD9C: nop

            goto L_8005BDC4;
    }
    // 0x8005BD9C: nop

    // 0x8005BDA0: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8005BDA4: beq         $a3, $at, L_8005BDD4
    if (ctx->r7 == ctx->r1) {
        // 0x8005BDA8: nop

            goto L_8005BDD4;
    }
    // 0x8005BDA8: nop

    // 0x8005BDAC: b           L_8005BDDC
    // 0x8005BDB0: nop

        goto L_8005BDDC;
    // 0x8005BDB0: nop

L_8005BDB4:
    // 0x8005BDB4: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8005BDB8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8005BDBC: b           L_8005BDDC
    // 0x8005BDC0: nop

        goto L_8005BDDC;
    // 0x8005BDC0: nop

L_8005BDC4:
    // 0x8005BDC4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8005BDC8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005BDCC: b           L_8005BDDC
    // 0x8005BDD0: nop

        goto L_8005BDDC;
    // 0x8005BDD0: nop

L_8005BDD4:
    // 0x8005BDD4: b           L_8005BDDC
    // 0x8005BDD8: nop

        goto L_8005BDDC;
    // 0x8005BDD8: nop

L_8005BDDC:
    // 0x8005BDDC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005BDE0: lw          $t4, 0x670($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X670);
    // 0x8005BDE4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005BDE8: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x8005BDEC: mfhi        $t5
    ctx->r13 = hi;
    // 0x8005BDF0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8005BDF4: nop

    // 0x8005BDF8: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x8005BDFC: nop

    // 0x8005BE00: bgez        $t6, L_8005BE14
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005BE04: andi        $t7, $t6, 0x3
        ctx->r15 = ctx->r14 & 0X3;
            goto L_8005BE14;
    }
    // 0x8005BE04: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8005BE08: beq         $t7, $zero, L_8005BE14
    if (ctx->r15 == 0) {
        // 0x8005BE0C: nop

            goto L_8005BE14;
    }
    // 0x8005BE0C: nop

    // 0x8005BE10: addiu       $t7, $t7, -0x4
    ctx->r15 = ADD32(ctx->r15, -0X4);
L_8005BE14:
    // 0x8005BE14: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8005BE18: beq         $at, $zero, L_8005BF20
    if (ctx->r1 == 0) {
        // 0x8005BE1C: nop

            goto L_8005BF20;
    }
    // 0x8005BE1C: nop

    // 0x8005BE20: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005BE24: nop

    // 0x8005BE28: lw          $t9, 0xA4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XA4);
    // 0x8005BE2C: nop

    // 0x8005BE30: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8005BE34: bne         $at, $zero, L_8005BF20
    if (ctx->r1 != 0) {
        // 0x8005BE38: nop

            goto L_8005BF20;
    }
    // 0x8005BE38: nop

    // 0x8005BE3C: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x8005BE40: beq         $at, $zero, L_8005BF20
    if (ctx->r1 == 0) {
        // 0x8005BE44: nop

            goto L_8005BF20;
    }
    // 0x8005BE44: nop

    // 0x8005BE48: lh          $t0, 0xAC($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XAC);
    // 0x8005BE4C: nop

    // 0x8005BE50: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8005BE54: bne         $t1, $zero, L_8005BF20
    if (ctx->r9 != 0) {
        // 0x8005BE58: nop

            goto L_8005BF20;
    }
    // 0x8005BE58: nop

    // 0x8005BE5C: lh          $t3, 0xAC($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XAC);
    // 0x8005BE60: nop

    // 0x8005BE64: ori         $t2, $t3, 0x10
    ctx->r10 = ctx->r11 | 0X10;
    // 0x8005BE68: sh          $t2, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = ctx->r10;
    // 0x8005BE6C: lw          $t5, 0xB4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XB4);
    // 0x8005BE70: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005BE74: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x8005BE78: lw          $t4, 0x670($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X670);
    // 0x8005BE7C: bgez        $t6, L_8005BE8C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005BE80: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8005BE8C;
    }
    // 0x8005BE80: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8005BE84: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8005BE88: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8005BE8C:
    // 0x8005BE8C: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005BE90: beq         $at, $zero, L_8005BF20
    if (ctx->r1 == 0) {
        // 0x8005BE94: nop

            goto L_8005BF20;
    }
    // 0x8005BE94: nop

    // 0x8005BE98: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005BE9C: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x8005BEA0: nop

    // 0x8005BEA4: bne         $a0, $t8, L_8005BEBC
    if (ctx->r4 != ctx->r24) {
        // 0x8005BEA8: nop

            goto L_8005BEBC;
    }
    // 0x8005BEA8: nop

    // 0x8005BEAC: b           L_8005C2FC
    // 0x8005BEB0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8005C2FC;
    // 0x8005BEB0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005BEB4: b           L_8005BF20
    // 0x8005BEB8: nop

        goto L_8005BF20;
    // 0x8005BEB8: nop

L_8005BEBC:
    // 0x8005BEBC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005BEC0: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005BEC4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005BEC8: lh          $t0, 0x7C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X7C);
    // 0x8005BECC: nop

    // 0x8005BED0: bne         $t0, $at, L_8005BEE0
    if (ctx->r8 != ctx->r1) {
        // 0x8005BED4: nop

            goto L_8005BEE0;
    }
    // 0x8005BED4: nop

    // 0x8005BED8: b           L_8005BEE8
    // 0x8005BEDC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
        goto L_8005BEE8;
    // 0x8005BEDC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005BEE0:
    // 0x8005BEE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005BEE4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_8005BEE8:
    // 0x8005BEE8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005BEEC: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x8005BEF0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8005BEF4: lw          $t6, 0xA4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XA4);
    // 0x8005BEF8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8005BEFC: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8005BF00: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005BF04: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x8005BF08: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8005BF0C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BF10: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8005BF14: lh          $v0, -0x2554($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2554);
    // 0x8005BF18: b           L_8005C2FC
    // 0x8005BF1C: nop

        goto L_8005C2FC;
    // 0x8005BF1C: nop

L_8005BF20:
    // 0x8005BF20: lw          $t8, 0xB4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XB4);
    // 0x8005BF24: addiu       $t0, $zero, 0x3E8
    ctx->r8 = ADD32(0, 0X3E8);
    // 0x8005BF28: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8005BF2C: nop

    // 0x8005BF30: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x8005BF34: bgez        $t1, L_8005BF44
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005BF38: sra         $t3, $t1, 2
        ctx->r11 = S32(SIGNED(ctx->r9) >> 2);
            goto L_8005BF44;
    }
    // 0x8005BF38: sra         $t3, $t1, 2
    ctx->r11 = S32(SIGNED(ctx->r9) >> 2);
    // 0x8005BF3C: addiu       $at, $t1, 0x3
    ctx->r1 = ADD32(ctx->r9, 0X3);
    // 0x8005BF40: sra         $t3, $at, 2
    ctx->r11 = S32(SIGNED(ctx->r1) >> 2);
L_8005BF44:
    // 0x8005BF44: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005BF48: lw          $a3, 0x14($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X14);
    // 0x8005BF4C: nop

    // 0x8005BF50: bgez        $a3, L_8005BF64
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8005BF54: andi        $t5, $a3, 0x3
        ctx->r13 = ctx->r7 & 0X3;
            goto L_8005BF64;
    }
    // 0x8005BF54: andi        $t5, $a3, 0x3
    ctx->r13 = ctx->r7 & 0X3;
    // 0x8005BF58: beq         $t5, $zero, L_8005BF64
    if (ctx->r13 == 0) {
        // 0x8005BF5C: nop

            goto L_8005BF64;
    }
    // 0x8005BF5C: nop

    // 0x8005BF60: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
L_8005BF64:
    // 0x8005BF64: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8005BF68: beq         $a3, $zero, L_8005C1A8
    if (ctx->r7 == 0) {
        // 0x8005BF6C: nop

            goto L_8005C1A8;
    }
    // 0x8005BF6C: nop

    // 0x8005BF70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005BF74: beq         $a3, $at, L_8005BFCC
    if (ctx->r7 == ctx->r1) {
        // 0x8005BF78: nop

            goto L_8005BFCC;
    }
    // 0x8005BF78: nop

    // 0x8005BF7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005BF80: beq         $a3, $at, L_8005BF9C
    if (ctx->r7 == ctx->r1) {
        // 0x8005BF84: nop

            goto L_8005BF9C;
    }
    // 0x8005BF84: nop

    // 0x8005BF88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005BF8C: beq         $a3, $at, L_8005BF9C
    if (ctx->r7 == ctx->r1) {
        // 0x8005BF90: nop

            goto L_8005BF9C;
    }
    // 0x8005BF90: nop

    // 0x8005BF94: b           L_8005C2F4
    // 0x8005BF98: nop

        goto L_8005C2F4;
    // 0x8005BF98: nop

L_8005BF9C:
    // 0x8005BF9C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x8005BFA0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BFA4: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8005BFA8: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8005BFAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8005BFB0: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8005BFB4: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8005BFB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BFBC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8005BFC0: lh          $v0, -0x268C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X268C);
    // 0x8005BFC4: b           L_8005C2FC
    // 0x8005BFC8: nop

        goto L_8005C2FC;
    // 0x8005BFC8: nop

L_8005BFCC:
    // 0x8005BFCC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8005BFD0: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x8005BFD4: nop

    // 0x8005BFD8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8005BFDC: addiu       $t3, $t1, 0xA
    ctx->r11 = ADD32(ctx->r9, 0XA);
    // 0x8005BFE0: div         $zero, $a1, $t3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r11)));
    // 0x8005BFE4: bne         $t3, $zero, L_8005BFF0
    if (ctx->r11 != 0) {
        // 0x8005BFE8: nop

            goto L_8005BFF0;
    }
    // 0x8005BFE8: nop

    // 0x8005BFEC: break       7
    do_break(2147860460);
L_8005BFF0:
    // 0x8005BFF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BFF4: bne         $t3, $at, L_8005C008
    if (ctx->r11 != ctx->r1) {
        // 0x8005BFF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005C008;
    }
    // 0x8005BFF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005BFFC: bne         $a1, $at, L_8005C008
    if (ctx->r5 != ctx->r1) {
        // 0x8005C000: nop

            goto L_8005C008;
    }
    // 0x8005C000: nop

    // 0x8005C004: break       6
    do_break(2147860484);
L_8005C008:
    // 0x8005C008: mfhi        $t5
    ctx->r13 = hi;
    // 0x8005C00C: bne         $t5, $zero, L_8005C02C
    if (ctx->r13 != 0) {
        // 0x8005C010: nop

            goto L_8005C02C;
    }
    // 0x8005C010: nop

    // 0x8005C014: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005C018: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005C01C: lw          $t4, 0xA4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XA4);
    // 0x8005C020: nop

    // 0x8005C024: bne         $t4, $at, L_8005C064
    if (ctx->r12 != ctx->r1) {
        // 0x8005C028: nop

            goto L_8005C064;
    }
    // 0x8005C028: nop

L_8005C02C:
    // 0x8005C02C: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8005C030: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C034: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8005C038: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x8005C03C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005C040: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8005C044: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8005C048: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C04C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8005C050: lh          $v0, -0x268C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X268C);
    // 0x8005C054: b           L_8005C2FC
    // 0x8005C058: nop

        goto L_8005C2FC;
    // 0x8005C058: nop

    // 0x8005C05C: b           L_8005C1A8
    // 0x8005C060: nop

        goto L_8005C1A8;
    // 0x8005C060: nop

L_8005C064:
    // 0x8005C064: lh          $t1, 0x7C($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X7C);
    // 0x8005C068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C06C: bne         $t1, $at, L_8005C138
    if (ctx->r9 != ctx->r1) {
        // 0x8005C070: nop

            goto L_8005C138;
    }
    // 0x8005C070: nop

    // 0x8005C074: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005C078: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005C07C: nop

    // 0x8005C080: lh          $t5, 0xE($t3)
    ctx->r13 = MEM_H(ctx->r11, 0XE);
    // 0x8005C084: nop

    // 0x8005C088: slti        $at, $t5, 0x190
    ctx->r1 = SIGNED(ctx->r13) < 0X190 ? 1 : 0;
    // 0x8005C08C: beq         $at, $zero, L_8005C0C0
    if (ctx->r1 == 0) {
        // 0x8005C090: nop

            goto L_8005C0C0;
    }
    // 0x8005C090: nop

    // 0x8005C094: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C098: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C09C: bgez        $t6, L_8005C0AC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005C0A0: sra         $t4, $t6, 1
        ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8005C0AC;
    }
    // 0x8005C0A0: sra         $t4, $t6, 1
    ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8005C0A4: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8005C0A8: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8005C0AC:
    // 0x8005C0AC: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8005C0B0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8005C0B4: lh          $v0, -0x256A($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X256A);
    // 0x8005C0B8: b           L_8005C2FC
    // 0x8005C0BC: nop

        goto L_8005C2FC;
    // 0x8005C0BC: nop

L_8005C0C0:
    // 0x8005C0C0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005C0C4: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005C0C8: nop

    // 0x8005C0CC: lh          $t7, 0xE($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XE);
    // 0x8005C0D0: nop

    // 0x8005C0D4: slti        $at, $t7, 0x2BC
    ctx->r1 = SIGNED(ctx->r15) < 0X2BC ? 1 : 0;
    // 0x8005C0D8: beq         $at, $zero, L_8005C10C
    if (ctx->r1 == 0) {
        // 0x8005C0DC: nop

            goto L_8005C10C;
    }
    // 0x8005C0DC: nop

    // 0x8005C0E0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C0E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C0E8: bgez        $t0, L_8005C0F8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005C0EC: sra         $t9, $t0, 1
        ctx->r25 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8005C0F8;
    }
    // 0x8005C0EC: sra         $t9, $t0, 1
    ctx->r25 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005C0F0: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8005C0F4: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8005C0F8:
    // 0x8005C0F8: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8005C0FC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8005C100: lh          $v0, -0x2560($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2560);
    // 0x8005C104: b           L_8005C2FC
    // 0x8005C108: nop

        goto L_8005C2FC;
    // 0x8005C108: nop

L_8005C10C:
    // 0x8005C10C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C110: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C114: bgez        $t3, L_8005C124
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8005C118: sra         $t5, $t3, 1
        ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8005C124;
    }
    // 0x8005C118: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005C11C: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8005C120: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8005C124:
    // 0x8005C124: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8005C128: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005C12C: lh          $v0, -0x2556($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2556);
    // 0x8005C130: b           L_8005C2FC
    // 0x8005C134: nop

        goto L_8005C2FC;
    // 0x8005C134: nop

L_8005C138:
    // 0x8005C138: lh          $t4, 0x7C($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X7C);
    // 0x8005C13C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005C140: bne         $t4, $at, L_8005C17C
    if (ctx->r12 != ctx->r1) {
        // 0x8005C144: nop

            goto L_8005C17C;
    }
    // 0x8005C144: nop

    // 0x8005C148: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C14C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C150: bgez        $t2, L_8005C160
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8005C154: sra         $t8, $t2, 1
        ctx->r24 = S32(SIGNED(ctx->r10) >> 1);
            goto L_8005C160;
    }
    // 0x8005C154: sra         $t8, $t2, 1
    ctx->r24 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8005C158: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x8005C15C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8005C160:
    // 0x8005C160: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8005C164: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8005C168: lh          $v0, -0x2592($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2592);
    // 0x8005C16C: b           L_8005C2FC
    // 0x8005C170: nop

        goto L_8005C2FC;
    // 0x8005C170: nop

    // 0x8005C174: b           L_8005C1A8
    // 0x8005C178: nop

        goto L_8005C1A8;
    // 0x8005C178: nop

L_8005C17C:
    // 0x8005C17C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C180: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C184: bgez        $t0, L_8005C194
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005C188: sra         $t9, $t0, 1
        ctx->r25 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8005C194;
    }
    // 0x8005C188: sra         $t9, $t0, 1
    ctx->r25 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005C18C: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8005C190: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8005C194:
    // 0x8005C194: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8005C198: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8005C19C: lh          $v0, -0x257E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X257E);
    // 0x8005C1A0: b           L_8005C2FC
    // 0x8005C1A4: nop

        goto L_8005C2FC;
    // 0x8005C1A4: nop

L_8005C1A8:
    // 0x8005C1A8: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8005C1AC: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x8005C1B0: nop

    // 0x8005C1B4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8005C1B8: div         $zero, $a1, $t6
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r14)));
    // 0x8005C1BC: bne         $t6, $zero, L_8005C1C8
    if (ctx->r14 != 0) {
        // 0x8005C1C0: nop

            goto L_8005C1C8;
    }
    // 0x8005C1C0: nop

    // 0x8005C1C4: break       7
    do_break(2147860932);
L_8005C1C8:
    // 0x8005C1C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005C1CC: bne         $t6, $at, L_8005C1E0
    if (ctx->r14 != ctx->r1) {
        // 0x8005C1D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005C1E0;
    }
    // 0x8005C1D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005C1D4: bne         $a1, $at, L_8005C1E0
    if (ctx->r5 != ctx->r1) {
        // 0x8005C1D8: nop

            goto L_8005C1E0;
    }
    // 0x8005C1D8: nop

    // 0x8005C1DC: break       6
    do_break(2147860956);
L_8005C1E0:
    // 0x8005C1E0: mfhi        $t4
    ctx->r12 = hi;
    // 0x8005C1E4: bne         $t4, $zero, L_8005C210
    if (ctx->r12 != 0) {
        // 0x8005C1E8: nop

            goto L_8005C210;
    }
    // 0x8005C1E8: nop

    // 0x8005C1EC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005C1F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005C1F4: lw          $t8, 0xA4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XA4);
    // 0x8005C1F8: nop

    // 0x8005C1FC: beq         $t8, $at, L_8005C210
    if (ctx->r24 == ctx->r1) {
        // 0x8005C200: nop

            goto L_8005C210;
    }
    // 0x8005C200: nop

    // 0x8005C204: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8005C208: bne         $t8, $at, L_8005C248
    if (ctx->r24 != ctx->r1) {
        // 0x8005C20C: nop

            goto L_8005C248;
    }
    // 0x8005C20C: nop

L_8005C210:
    // 0x8005C210: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8005C214: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C218: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8005C21C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8005C220: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8005C224: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8005C228: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x8005C22C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C230: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8005C234: lh          $v0, -0x268C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X268C);
    // 0x8005C238: b           L_8005C2FC
    // 0x8005C23C: nop

        goto L_8005C2FC;
    // 0x8005C23C: nop

    // 0x8005C240: b           L_8005C2F4
    // 0x8005C244: nop

        goto L_8005C2F4;
    // 0x8005C244: nop

L_8005C248:
    // 0x8005C248: lh          $t5, 0x7C($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X7C);
    // 0x8005C24C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C250: bne         $t5, $at, L_8005C284
    if (ctx->r13 != ctx->r1) {
        // 0x8005C254: nop

            goto L_8005C284;
    }
    // 0x8005C254: nop

    // 0x8005C258: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C25C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C260: bgez        $t6, L_8005C270
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005C264: sra         $t4, $t6, 1
        ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8005C270;
    }
    // 0x8005C264: sra         $t4, $t6, 1
    ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8005C268: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8005C26C: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8005C270:
    // 0x8005C270: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8005C274: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8005C278: lh          $v0, -0x2574($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2574);
    // 0x8005C27C: b           L_8005C2FC
    // 0x8005C280: nop

        goto L_8005C2FC;
    // 0x8005C280: nop

L_8005C284:
    // 0x8005C284: lh          $t8, 0x7C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X7C);
    // 0x8005C288: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005C28C: bne         $t8, $at, L_8005C2C8
    if (ctx->r24 != ctx->r1) {
        // 0x8005C290: nop

            goto L_8005C2C8;
    }
    // 0x8005C290: nop

    // 0x8005C294: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C298: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C29C: bgez        $t7, L_8005C2AC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005C2A0: sra         $t9, $t7, 1
        ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8005C2AC;
    }
    // 0x8005C2A0: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005C2A4: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8005C2A8: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8005C2AC:
    // 0x8005C2AC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8005C2B0: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8005C2B4: lh          $v0, -0x259C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X259C);
    // 0x8005C2B8: b           L_8005C2FC
    // 0x8005C2BC: nop

        goto L_8005C2FC;
    // 0x8005C2BC: nop

    // 0x8005C2C0: b           L_8005C2F4
    // 0x8005C2C4: nop

        goto L_8005C2F4;
    // 0x8005C2C4: nop

L_8005C2C8:
    // 0x8005C2C8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C2CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005C2D0: bgez        $t1, L_8005C2E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005C2D4: sra         $t3, $t1, 1
        ctx->r11 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8005C2E0;
    }
    // 0x8005C2D4: sra         $t3, $t1, 1
    ctx->r11 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8005C2D8: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8005C2DC: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8005C2E0:
    // 0x8005C2E0: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8005C2E4: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x8005C2E8: lh          $v0, -0x2588($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2588);
    // 0x8005C2EC: b           L_8005C2FC
    // 0x8005C2F0: nop

        goto L_8005C2FC;
    // 0x8005C2F0: nop

L_8005C2F4:
    // 0x8005C2F4: b           L_8005C2FC
    // 0x8005C2F8: nop

        goto L_8005C2FC;
    // 0x8005C2F8: nop

L_8005C2FC:
    // 0x8005C2FC: jr          $ra
    // 0x8005C300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005C300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005C304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C304: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005C308: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005C30C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C310: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005C314: nop

    // 0x8005C318: beq         $t6, $zero, L_8005C374
    if (ctx->r14 == 0) {
        // 0x8005C31C: nop

            goto L_8005C374;
    }
    // 0x8005C31C: nop

    // 0x8005C320: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C324: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005C328: nop

    // 0x8005C32C: beq         $t7, $zero, L_8005C374
    if (ctx->r15 == 0) {
        // 0x8005C330: nop

            goto L_8005C374;
    }
    // 0x8005C330: nop

    // 0x8005C334: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005C338: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8005C33C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005C340: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005C344: bne         $t0, $zero, L_8005C354
    if (ctx->r8 != 0) {
        // 0x8005C348: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8005C354;
    }
    // 0x8005C348: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005C34C: beq         $t1, $zero, L_8005C374
    if (ctx->r9 == 0) {
        // 0x8005C350: nop

            goto L_8005C374;
    }
    // 0x8005C350: nop

L_8005C354:
    // 0x8005C354: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8005C358: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8005C35C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005C360: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005C364: bne         $t4, $zero, L_8005C37C
    if (ctx->r12 != 0) {
        // 0x8005C368: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8005C37C;
    }
    // 0x8005C368: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8005C36C: bne         $t5, $zero, L_8005C37C
    if (ctx->r13 != 0) {
        // 0x8005C370: nop

            goto L_8005C37C;
    }
    // 0x8005C370: nop

L_8005C374:
    // 0x8005C374: b           L_8005C8FC
    // 0x8005C378: nop

        goto L_8005C8FC;
    // 0x8005C378: nop

L_8005C37C:
    // 0x8005C37C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C380: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005C384: nop

    // 0x8005C388: lh          $t8, 0xAC($t6)
    ctx->r24 = MEM_H(ctx->r14, 0XAC);
    // 0x8005C38C: nop

    // 0x8005C390: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8005C394: bne         $t9, $zero, L_8005C5EC
    if (ctx->r25 != 0) {
        // 0x8005C398: nop

            goto L_8005C5EC;
    }
    // 0x8005C398: nop

    // 0x8005C39C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005C3A0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005C3A4: nop

    // 0x8005C3A8: lh          $t1, 0xAC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XAC);
    // 0x8005C3AC: nop

    // 0x8005C3B0: andi        $t7, $t1, 0x1
    ctx->r15 = ctx->r9 & 0X1;
    // 0x8005C3B4: bne         $t7, $zero, L_8005C478
    if (ctx->r15 != 0) {
        // 0x8005C3B8: nop

            goto L_8005C478;
    }
    // 0x8005C3B8: nop

    // 0x8005C3BC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C3C0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005C3C4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C3C8: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005C3CC: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x8005C3D0: lw          $a1, 0x4C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4C);
    // 0x8005C3D4: lw          $a2, 0x50($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X50);
    // 0x8005C3D8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005C3DC: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8005C3E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005C3E4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005C3E8: lw          $t6, 0x50($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X50);
    // 0x8005C3EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8005C3F0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005C3F4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005C3F8: jal         0x800784E8
    // 0x8005C3FC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800784E8(rdram, ctx);
        goto after_0;
    // 0x8005C3FC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8005C400: beq         $v0, $zero, L_8005C478
    if (ctx->r2 == 0) {
        // 0x8005C404: nop

            goto L_8005C478;
    }
    // 0x8005C404: nop

    // 0x8005C408: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C40C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005C410: nop

    // 0x8005C414: lh          $t0, 0xAC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XAC);
    // 0x8005C418: nop

    // 0x8005C41C: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x8005C420: sh          $t1, 0xAC($t9)
    MEM_H(0XAC, ctx->r25) = ctx->r9;
    // 0x8005C424: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C428: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005C42C: nop

    // 0x8005C430: lh          $t2, 0xAC($t7)
    ctx->r10 = MEM_H(ctx->r15, 0XAC);
    // 0x8005C434: nop

    // 0x8005C438: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8005C43C: sh          $t3, 0xAC($t7)
    MEM_H(0XAC, ctx->r15) = ctx->r11;
    // 0x8005C440: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8005C444: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005C448: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005C44C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005C450: nop

    // 0x8005C454: swc1        $f4, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f4.u32l;
    // 0x8005C458: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005C45C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C460: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005C464: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005C468: nop

    // 0x8005C46C: swc1        $f6, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f6.u32l;
    // 0x8005C470: jal         0x800B9000
    // 0x8005C474: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8005C474: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
L_8005C478:
    // 0x8005C478: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C47C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005C480: nop

    // 0x8005C484: lh          $t8, 0xAC($t6)
    ctx->r24 = MEM_H(ctx->r14, 0XAC);
    // 0x8005C488: nop

    // 0x8005C48C: andi        $t0, $t8, 0x8
    ctx->r8 = ctx->r24 & 0X8;
    // 0x8005C490: bne         $t0, $zero, L_8005C5EC
    if (ctx->r8 != 0) {
        // 0x8005C494: nop

            goto L_8005C5EC;
    }
    // 0x8005C494: nop

    // 0x8005C498: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005C49C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005C4A0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C4A4: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005C4A8: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x8005C4AC: lw          $a1, 0x4C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4C);
    // 0x8005C4B0: lw          $a2, 0x50($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X50);
    // 0x8005C4B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005C4B8: lw          $t3, 0x4C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4C);
    // 0x8005C4BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005C4C0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8005C4C4: lw          $t7, 0x50($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X50);
    // 0x8005C4C8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8005C4CC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005C4D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005C4D4: jal         0x800784E8
    // 0x8005C4D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800784E8(rdram, ctx);
        goto after_2;
    // 0x8005C4D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_2:
    // 0x8005C4DC: beq         $v0, $zero, L_8005C5EC
    if (ctx->r2 == 0) {
        // 0x8005C4E0: nop

            goto L_8005C5EC;
    }
    // 0x8005C4E0: nop

    // 0x8005C4E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C4E8: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005C4EC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C4F0: lw          $t8, 0xB4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XB4);
    // 0x8005C4F4: lw          $t4, 0x670($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X670);
    // 0x8005C4F8: lh          $t0, 0xA($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XA);
    // 0x8005C4FC: nop

    // 0x8005C500: bgez        $t0, L_8005C510
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005C504: sra         $t1, $t0, 2
        ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
            goto L_8005C510;
    }
    // 0x8005C504: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8005C508: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
    // 0x8005C50C: sra         $t1, $at, 2
    ctx->r9 = S32(SIGNED(ctx->r1) >> 2);
L_8005C510:
    // 0x8005C510: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005C514: beq         $at, $zero, L_8005C54C
    if (ctx->r1 == 0) {
        // 0x8005C518: nop

            goto L_8005C54C;
    }
    // 0x8005C518: nop

    // 0x8005C51C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C520: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005C524: nop

    // 0x8005C528: lh          $t3, 0xAC($t9)
    ctx->r11 = MEM_H(ctx->r25, 0XAC);
    // 0x8005C52C: nop

    // 0x8005C530: ori         $t2, $t3, 0x80
    ctx->r10 = ctx->r11 | 0X80;
    // 0x8005C534: sh          $t2, 0xAC($t9)
    MEM_H(0XAC, ctx->r25) = ctx->r10;
    // 0x8005C538: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005C53C: lw          $a0, 0xE70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE70);
    // 0x8005C540: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8005C544: jal         0x8005C90C
    // 0x8005C548: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8005C90C(rdram, ctx);
        goto after_3;
    // 0x8005C548: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_3:
L_8005C54C:
    // 0x8005C54C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C550: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005C554: nop

    // 0x8005C558: lh          $t5, 0xAC($t7)
    ctx->r13 = MEM_H(ctx->r15, 0XAC);
    // 0x8005C55C: nop

    // 0x8005C560: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x8005C564: sh          $t6, 0xAC($t7)
    MEM_H(0XAC, ctx->r15) = ctx->r14;
    // 0x8005C568: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005C56C: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x8005C570: nop

    // 0x8005C574: lh          $t0, 0xAC($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XAC);
    // 0x8005C578: nop

    // 0x8005C57C: ori         $t4, $t0, 0x2
    ctx->r12 = ctx->r8 | 0X2;
    // 0x8005C580: sh          $t4, 0xAC($t8)
    MEM_H(0XAC, ctx->r24) = ctx->r12;
    // 0x8005C584: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8005C588: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005C58C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005C590: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005C594: nop

    // 0x8005C598: swc1        $f8, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f8.u32l;
    // 0x8005C59C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005C5A0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005C5A4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005C5A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005C5AC: nop

    // 0x8005C5B0: swc1        $f10, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f10.u32l;
    // 0x8005C5B4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C5B8: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005C5BC: nop

    // 0x8005C5C0: lh          $t9, 0xAC($t2)
    ctx->r25 = MEM_H(ctx->r10, 0XAC);
    // 0x8005C5C4: nop

    // 0x8005C5C8: andi        $t5, $t9, 0x80
    ctx->r13 = ctx->r25 & 0X80;
    // 0x8005C5CC: beq         $t5, $zero, L_8005C5E4
    if (ctx->r13 == 0) {
        // 0x8005C5D0: nop

            goto L_8005C5E4;
    }
    // 0x8005C5D0: nop

    // 0x8005C5D4: jal         0x800B9000
    // 0x8005C5D8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_800B9000(rdram, ctx);
        goto after_4;
    // 0x8005C5D8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_4:
    // 0x8005C5DC: b           L_8005C5EC
    // 0x8005C5E0: nop

        goto L_8005C5EC;
    // 0x8005C5E0: nop

L_8005C5E4:
    // 0x8005C5E4: jal         0x800B9000
    // 0x8005C5E8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x8005C5E8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_5:
L_8005C5EC:
    // 0x8005C5EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C5F0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005C5F4: nop

    // 0x8005C5F8: lh          $t7, 0xAC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XAC);
    // 0x8005C5FC: nop

    // 0x8005C600: andi        $t0, $t7, 0x2
    ctx->r8 = ctx->r15 & 0X2;
    // 0x8005C604: bne         $t0, $zero, L_8005C8F4
    if (ctx->r8 != 0) {
        // 0x8005C608: nop

            goto L_8005C8F4;
    }
    // 0x8005C608: nop

    // 0x8005C60C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C610: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005C614: nop

    // 0x8005C618: lh          $t8, 0xAC($t4)
    ctx->r24 = MEM_H(ctx->r12, 0XAC);
    // 0x8005C61C: nop

    // 0x8005C620: andi        $t1, $t8, 0x1
    ctx->r9 = ctx->r24 & 0X1;
    // 0x8005C624: bne         $t1, $zero, L_8005C730
    if (ctx->r9 != 0) {
        // 0x8005C628: nop

            goto L_8005C730;
    }
    // 0x8005C628: nop

    // 0x8005C62C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005C630: lw          $t3, 0xE70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE70);
    // 0x8005C634: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C638: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005C63C: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x8005C640: lw          $a1, 0x4C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4C);
    // 0x8005C644: lw          $a2, 0x50($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X50);
    // 0x8005C648: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005C64C: lw          $t5, 0x4C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4C);
    // 0x8005C650: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005C654: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005C658: lw          $t6, 0x50($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X50);
    // 0x8005C65C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8005C660: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005C664: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005C668: jal         0x800784E8
    // 0x8005C66C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800784E8(rdram, ctx);
        goto after_6;
    // 0x8005C66C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_6:
    // 0x8005C670: beq         $v0, $zero, L_8005C730
    if (ctx->r2 == 0) {
        // 0x8005C674: nop

            goto L_8005C730;
    }
    // 0x8005C674: nop

    // 0x8005C678: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005C67C: lw          $t0, 0xE70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE70);
    // 0x8005C680: nop

    // 0x8005C684: lh          $t4, 0xAC($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XAC);
    // 0x8005C688: nop

    // 0x8005C68C: ori         $t8, $t4, 0x8
    ctx->r24 = ctx->r12 | 0X8;
    // 0x8005C690: sh          $t8, 0xAC($t0)
    MEM_H(0XAC, ctx->r8) = ctx->r24;
    // 0x8005C694: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005C698: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005C69C: nop

    // 0x8005C6A0: lh          $t3, 0xAC($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XAC);
    // 0x8005C6A4: nop

    // 0x8005C6A8: ori         $t2, $t3, 0x2
    ctx->r10 = ctx->r11 | 0X2;
    // 0x8005C6AC: sh          $t2, 0xAC($t1)
    MEM_H(0XAC, ctx->r9) = ctx->r10;
    // 0x8005C6B0: jal         0x800B9000
    // 0x8005C6B4: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    func_800B9000(rdram, ctx);
        goto after_7;
    // 0x8005C6B4: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    after_7:
    // 0x8005C6B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005C6BC: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005C6C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005C6C4: jal         0x800B334C
    // 0x8005C6C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_8;
    // 0x8005C6C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_8:
    // 0x8005C6CC: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
    // 0x8005C6D0: beq         $t5, $zero, L_8005C700
    if (ctx->r13 == 0) {
        // 0x8005C6D4: nop

            goto L_8005C700;
    }
    // 0x8005C6D4: nop

    // 0x8005C6D8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C6DC: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005C6E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C6E4: nop

    // 0x8005C6E8: swc1        $f16, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f16.u32l;
    // 0x8005C6EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C6F0: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005C6F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005C6F8: b           L_8005C730
    // 0x8005C6FC: swc1        $f18, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f18.u32l;
        goto L_8005C730;
    // 0x8005C6FC: swc1        $f18, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f18.u32l;
L_8005C700:
    // 0x8005C700: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8005C704: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C708: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005C70C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005C710: nop

    // 0x8005C714: swc1        $f4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f4.u32l;
    // 0x8005C718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005C71C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C720: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005C724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005C728: nop

    // 0x8005C72C: swc1        $f6, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f6.u32l;
L_8005C730:
    // 0x8005C730: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005C734: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x8005C738: nop

    // 0x8005C73C: lh          $t0, 0xAC($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XAC);
    // 0x8005C740: nop

    // 0x8005C744: andi        $t3, $t0, 0x8
    ctx->r11 = ctx->r8 & 0X8;
    // 0x8005C748: bne         $t3, $zero, L_8005C8F4
    if (ctx->r11 != 0) {
        // 0x8005C74C: nop

            goto L_8005C8F4;
    }
    // 0x8005C74C: nop

    // 0x8005C750: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C754: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005C758: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005C75C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005C760: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x8005C764: lw          $a1, 0x4C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4C);
    // 0x8005C768: lw          $a2, 0x50($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X50);
    // 0x8005C76C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005C770: lw          $t9, 0x4C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4C);
    // 0x8005C774: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005C778: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8005C77C: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x8005C780: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8005C784: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005C788: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005C78C: jal         0x800784E8
    // 0x8005C790: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800784E8(rdram, ctx);
        goto after_9;
    // 0x8005C790: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_9:
    // 0x8005C794: beq         $v0, $zero, L_8005C8F4
    if (ctx->r2 == 0) {
        // 0x8005C798: nop

            goto L_8005C8F4;
    }
    // 0x8005C798: nop

    // 0x8005C79C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005C7A0: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005C7A4: nop

    // 0x8005C7A8: lh          $t8, 0xAC($t4)
    ctx->r24 = MEM_H(ctx->r12, 0XAC);
    // 0x8005C7AC: nop

    // 0x8005C7B0: ori         $t0, $t8, 0x4
    ctx->r8 = ctx->r24 | 0X4;
    // 0x8005C7B4: sh          $t0, 0xAC($t4)
    MEM_H(0XAC, ctx->r12) = ctx->r8;
    // 0x8005C7B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005C7BC: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005C7C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005C7C4: jal         0x800B334C
    // 0x8005C7C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_10;
    // 0x8005C7C8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_10:
    // 0x8005C7CC: andi        $t3, $v0, 0x2000
    ctx->r11 = ctx->r2 & 0X2000;
    // 0x8005C7D0: beq         $t3, $zero, L_8005C808
    if (ctx->r11 == 0) {
        // 0x8005C7D4: nop

            goto L_8005C808;
    }
    // 0x8005C7D4: nop

    // 0x8005C7D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005C7DC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C7E0: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005C7E4: lwc1        $f8, -0xE40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE40);
    // 0x8005C7E8: nop

    // 0x8005C7EC: swc1        $f8, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f8.u32l;
    // 0x8005C7F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005C7F4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005C7F8: lw          $t1, 0xE70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE70);
    // 0x8005C7FC: lwc1        $f10, -0xE3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE3C);
    // 0x8005C800: b           L_8005C8BC
    // 0x8005C804: swc1        $f10, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f10.u32l;
        goto L_8005C8BC;
    // 0x8005C804: swc1        $f10, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f10.u32l;
L_8005C808:
    // 0x8005C808: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005C80C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005C810: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C814: lw          $t6, 0xB4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XB4);
    // 0x8005C818: lw          $t9, 0x670($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X670);
    // 0x8005C81C: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8005C820: nop

    // 0x8005C824: bgez        $t7, L_8005C834
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005C828: sra         $t8, $t7, 2
        ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
            goto L_8005C834;
    }
    // 0x8005C828: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8005C82C: addiu       $at, $t7, 0x3
    ctx->r1 = ADD32(ctx->r15, 0X3);
    // 0x8005C830: sra         $t8, $at, 2
    ctx->r24 = S32(SIGNED(ctx->r1) >> 2);
L_8005C834:
    // 0x8005C834: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8005C838: beq         $at, $zero, L_8005C870
    if (ctx->r1 == 0) {
        // 0x8005C83C: nop

            goto L_8005C870;
    }
    // 0x8005C83C: nop

    // 0x8005C840: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005C844: lw          $t0, 0xE70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE70);
    // 0x8005C848: nop

    // 0x8005C84C: lh          $t4, 0xAC($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XAC);
    // 0x8005C850: nop

    // 0x8005C854: ori         $t3, $t4, 0x80
    ctx->r11 = ctx->r12 | 0X80;
    // 0x8005C858: sh          $t3, 0xAC($t0)
    MEM_H(0XAC, ctx->r8) = ctx->r11;
    // 0x8005C85C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005C860: lw          $a0, 0xE70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE70);
    // 0x8005C864: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8005C868: jal         0x8005C90C
    // 0x8005C86C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8005C90C(rdram, ctx);
        goto after_11;
    // 0x8005C86C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_11:
L_8005C870:
    // 0x8005C870: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005C874: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005C878: nop

    // 0x8005C87C: lh          $t1, 0xAC($t2)
    ctx->r9 = MEM_H(ctx->r10, 0XAC);
    // 0x8005C880: nop

    // 0x8005C884: ori         $t5, $t1, 0x2
    ctx->r13 = ctx->r9 | 0X2;
    // 0x8005C888: sh          $t5, 0xAC($t2)
    MEM_H(0XAC, ctx->r10) = ctx->r13;
    // 0x8005C88C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8005C890: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005C894: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005C898: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005C89C: nop

    // 0x8005C8A0: swc1        $f16, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f16.u32l;
    // 0x8005C8A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005C8A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005C8AC: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005C8B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005C8B4: nop

    // 0x8005C8B8: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
L_8005C8BC:
    // 0x8005C8BC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005C8C0: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005C8C4: nop

    // 0x8005C8C8: lh          $t8, 0xAC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0XAC);
    // 0x8005C8CC: nop

    // 0x8005C8D0: andi        $t4, $t8, 0x80
    ctx->r12 = ctx->r24 & 0X80;
    // 0x8005C8D4: beq         $t4, $zero, L_8005C8EC
    if (ctx->r12 == 0) {
        // 0x8005C8D8: nop

            goto L_8005C8EC;
    }
    // 0x8005C8D8: nop

    // 0x8005C8DC: jal         0x800B9000
    // 0x8005C8E0: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_800B9000(rdram, ctx);
        goto after_12;
    // 0x8005C8E0: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_12:
    // 0x8005C8E4: b           L_8005C8F4
    // 0x8005C8E8: nop

        goto L_8005C8F4;
    // 0x8005C8E8: nop

L_8005C8EC:
    // 0x8005C8EC: jal         0x800B9000
    // 0x8005C8F0: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800B9000(rdram, ctx);
        goto after_13;
    // 0x8005C8F0: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_13:
L_8005C8F4:
    // 0x8005C8F4: b           L_8005C8FC
    // 0x8005C8F8: nop

        goto L_8005C8FC;
    // 0x8005C8F8: nop

L_8005C8FC:
    // 0x8005C8FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005C900: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005C904: jr          $ra
    // 0x8005C908: nop

    return;
    // 0x8005C908: nop

;}
RECOMP_FUNC void func_8005C90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C90C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005C910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005C914: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005C918: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005C91C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8005C920: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005C924: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005C928: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005C92C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8005C930: nop

    // 0x8005C934: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005C938: nop

    // 0x8005C93C: bc1f        L_8005C94C
    if (!c1cs) {
        // 0x8005C940: nop

            goto L_8005C94C;
    }
    // 0x8005C940: nop

    // 0x8005C944: b           L_8005C960
    // 0x8005C948: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
        goto L_8005C960;
    // 0x8005C948: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_8005C94C:
    // 0x8005C94C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005C950: nop

    // 0x8005C954: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8005C958: nop

    // 0x8005C95C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
L_8005C960:
    // 0x8005C960: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005C964: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005C968: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8005C96C: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8005C970: nop

    // 0x8005C974: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005C978: nop

    // 0x8005C97C: bc1f        L_8005C98C
    if (!c1cs) {
        // 0x8005C980: nop

            goto L_8005C98C;
    }
    // 0x8005C980: nop

    // 0x8005C984: b           L_8005C9A0
    // 0x8005C988: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
        goto L_8005C9A0;
    // 0x8005C988: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
L_8005C98C:
    // 0x8005C98C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005C990: nop

    // 0x8005C994: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8005C998: nop

    // 0x8005C99C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_8005C9A0:
    // 0x8005C9A0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005C9A4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005C9A8: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8005C9AC: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8005C9B0: nop

    // 0x8005C9B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005C9B8: nop

    // 0x8005C9BC: bc1f        L_8005C9CC
    if (!c1cs) {
        // 0x8005C9C0: nop

            goto L_8005C9CC;
    }
    // 0x8005C9C0: nop

    // 0x8005C9C4: b           L_8005C9E0
    // 0x8005C9C8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
        goto L_8005C9E0;
    // 0x8005C9C8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
L_8005C9CC:
    // 0x8005C9CC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005C9D0: nop

    // 0x8005C9D4: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8005C9D8: nop

    // 0x8005C9DC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
L_8005C9E0:
    // 0x8005C9E0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005C9E4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005C9E8: lwc1        $f16, 0xC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8005C9EC: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8005C9F0: nop

    // 0x8005C9F4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8005C9F8: nop

    // 0x8005C9FC: bc1f        L_8005CA0C
    if (!c1cs) {
        // 0x8005CA00: nop

            goto L_8005CA0C;
    }
    // 0x8005CA00: nop

    // 0x8005CA04: b           L_8005CA20
    // 0x8005CA08: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
        goto L_8005CA20;
    // 0x8005CA08: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
L_8005CA0C:
    // 0x8005CA0C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005CA10: nop

    // 0x8005CA14: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005CA18: nop

    // 0x8005CA1C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
L_8005CA20:
    // 0x8005CA20: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005CA24: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005CA28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005CA2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005CA30: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8005CA34: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005CA38: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005CA3C: nop

    // 0x8005CA40: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8005CA44: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005CA48: addiu       $t8, $t8, 0xE80
    ctx->r24 = ADD32(ctx->r24, 0XE80);
    // 0x8005CA4C: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8005CA50: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005CA54: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x8005CA58: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005CA5C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005CA60: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005CA64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005CA68: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005CA6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005CA70: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005CA74: nop

    // 0x8005CA78: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x8005CA7C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005CA80: addiu       $t0, $t0, 0xE80
    ctx->r8 = ADD32(ctx->r8, 0XE80);
    // 0x8005CA84: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8005CA88: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005CA8C: swc1        $f6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f6.u32l;
    // 0x8005CA90: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005CA94: addiu       $t2, $t2, 0xE80
    ctx->r10 = ADD32(ctx->r10, 0XE80);
    // 0x8005CA98: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x8005CA9C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005CAA0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8005CAA4: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8005CAA8: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x8005CAAC: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8005CAB0: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8005CAB4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8005CAB8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005CABC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005CAC0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005CAC4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005CAC8: bne         $t2, $zero, L_8005CAD8
    if (ctx->r10 != 0) {
        // 0x8005CACC: andi        $t3, $t1, 0x8
        ctx->r11 = ctx->r9 & 0X8;
            goto L_8005CAD8;
    }
    // 0x8005CACC: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x8005CAD0: beq         $t3, $zero, L_8005CB04
    if (ctx->r11 == 0) {
        // 0x8005CAD4: nop

            goto L_8005CB04;
    }
    // 0x8005CAD4: nop

L_8005CAD8:
    // 0x8005CAD8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005CADC: addiu       $t9, $t9, 0xE80
    ctx->r25 = ADD32(ctx->r25, 0XE80);
    // 0x8005CAE0: lw          $t4, 0x18($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X18);
    // 0x8005CAE4: nop

    // 0x8005CAE8: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8005CAEC: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8005CAF0: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8005CAF4: ori         $t9, $t7, 0x8
    ctx->r25 = ctx->r15 | 0X8;
    // 0x8005CAF8: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8005CAFC: b           L_8005CB30
    // 0x8005CB00: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
        goto L_8005CB30;
    // 0x8005CB00: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_8005CB04:
    // 0x8005CB04: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005CB08: addiu       $t5, $t5, 0xE80
    ctx->r13 = ADD32(ctx->r13, 0XE80);
    // 0x8005CB0C: lw          $t0, 0x18($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X18);
    // 0x8005CB10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005CB14: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8005CB18: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8005CB1C: and         $t6, $t2, $at
    ctx->r14 = ctx->r10 & ctx->r1;
    // 0x8005CB20: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005CB24: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8005CB28: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8005CB2C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_8005CB30:
    // 0x8005CB30: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005CB34: addiu       $t1, $t1, 0xE80
    ctx->r9 = ADD32(ctx->r9, 0XE80);
    // 0x8005CB38: lw          $a0, 0x18($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X18);
    // 0x8005CB3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005CB40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005CB44: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8005CB48: addiu       $a2, $zero, 0x19A
    ctx->r6 = ADD32(0, 0X19A);
    // 0x8005CB4C: jal         0x8004F3E8
    // 0x8005CB50: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    func_8004F3E8(rdram, ctx);
        goto after_0;
    // 0x8005CB50: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    after_0:
    // 0x8005CB54: b           L_8005CB5C
    // 0x8005CB58: nop

        goto L_8005CB5C;
    // 0x8005CB58: nop

L_8005CB5C:
    // 0x8005CB5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CB60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005CB64: jr          $ra
    // 0x8005CB68: nop

    return;
    // 0x8005CB68: nop

;}
RECOMP_FUNC void func_8005CB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CB6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005CB70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CB74: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005CB78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005CB7C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8005CB80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005CB84: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005CB88: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005CB8C: lw          $s0, 0xA4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0XA4);
    // 0x8005CB90: nop

    // 0x8005CB94: beq         $s0, $at, L_8005CBC8
    if (ctx->r16 == ctx->r1) {
        // 0x8005CB98: nop

            goto L_8005CBC8;
    }
    // 0x8005CB98: nop

    // 0x8005CB9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005CBA0: beq         $s0, $at, L_8005CBC8
    if (ctx->r16 == ctx->r1) {
        // 0x8005CBA4: nop

            goto L_8005CBC8;
    }
    // 0x8005CBA4: nop

    // 0x8005CBA8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005CBAC: beq         $s0, $at, L_8005CC2C
    if (ctx->r16 == ctx->r1) {
        // 0x8005CBB0: nop

            goto L_8005CC2C;
    }
    // 0x8005CBB0: nop

    // 0x8005CBB4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005CBB8: beq         $s0, $at, L_8005CC2C
    if (ctx->r16 == ctx->r1) {
        // 0x8005CBBC: nop

            goto L_8005CC2C;
    }
    // 0x8005CBBC: nop

    // 0x8005CBC0: b           L_8005CC3C
    // 0x8005CBC4: nop

        goto L_8005CC3C;
    // 0x8005CBC4: nop

L_8005CBC8:
    // 0x8005CBC8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005CBCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CBD0: lh          $t8, 0x7C($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X7C);
    // 0x8005CBD4: nop

    // 0x8005CBD8: bne         $t8, $at, L_8005CC1C
    if (ctx->r24 != ctx->r1) {
        // 0x8005CBDC: nop

            goto L_8005CC1C;
    }
    // 0x8005CBDC: nop

    // 0x8005CBE0: lw          $t9, 0xA4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XA4);
    // 0x8005CBE4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005CBE8: bne         $t9, $at, L_8005CC1C
    if (ctx->r25 != ctx->r1) {
        // 0x8005CBEC: nop

            goto L_8005CC1C;
    }
    // 0x8005CBEC: nop

    // 0x8005CBF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005CBF4: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005CBF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CBFC: jal         0x800B334C
    // 0x8005CC00: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800B334C(rdram, ctx);
        goto after_0;
    // 0x8005CC00: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x8005CC04: andi        $t0, $v0, 0x2000
    ctx->r8 = ctx->r2 & 0X2000;
    // 0x8005CC08: bne         $t0, $zero, L_8005CC1C
    if (ctx->r8 != 0) {
        // 0x8005CC0C: nop

            goto L_8005CC1C;
    }
    // 0x8005CC0C: nop

    // 0x8005CC10: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8005CC14: b           L_8005CC24
    // 0x8005CC18: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
        goto L_8005CC24;
    // 0x8005CC18: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8005CC1C:
    // 0x8005CC1C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8005CC20: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8005CC24:
    // 0x8005CC24: b           L_8005CC4C
    // 0x8005CC28: nop

        goto L_8005CC4C;
    // 0x8005CC28: nop

L_8005CC2C:
    // 0x8005CC2C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005CC30: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8005CC34: b           L_8005CC4C
    // 0x8005CC38: nop

        goto L_8005CC4C;
    // 0x8005CC38: nop

L_8005CC3C:
    // 0x8005CC3C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8005CC40: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8005CC44: b           L_8005CC4C
    // 0x8005CC48: nop

        goto L_8005CC4C;
    // 0x8005CC48: nop

L_8005CC4C:
    // 0x8005CC4C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CC50: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005CC54: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8005CC58: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x8005CC5C: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x8005CC60: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005CC64: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8005CC68: mflo        $t0
    ctx->r8 = lo;
    // 0x8005CC6C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8005CC70: nop

    // 0x8005CC74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005CC78: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8005CC7C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CC80: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005CC84: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8005CC88: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005CC8C: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
    // 0x8005CC90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005CC94: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8005CC98: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005CC9C: nop

    // 0x8005CCA0: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x8005CCA4: mflo        $t5
    ctx->r13 = lo;
    // 0x8005CCA8: subu        $t9, $t7, $t5
    ctx->r25 = SUB32(ctx->r15, ctx->r13);
    // 0x8005CCAC: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
    // 0x8005CCB0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005CCB4: nop

    // 0x8005CCB8: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8005CCBC: nop

    // 0x8005CCC0: bgez        $t2, L_8005CCD4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8005CCC4: nop

            goto L_8005CCD4;
    }
    // 0x8005CCC4: nop

    // 0x8005CCC8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CCCC: nop

    // 0x8005CCD0: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
L_8005CCD4:
    // 0x8005CCD4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005CCD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CCDC: lh          $t4, 0x7C($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X7C);
    // 0x8005CCE0: nop

    // 0x8005CCE4: beq         $t4, $at, L_8005CD24
    if (ctx->r12 == ctx->r1) {
        // 0x8005CCE8: nop

            goto L_8005CD24;
    }
    // 0x8005CCE8: nop

    // 0x8005CCEC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005CCF0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005CCF4: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8005CCF8: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005CCFC: nop

    // 0x8005CD00: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x8005CD04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005CD08: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005CD0C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005CD10: lwc1        $f8, 0x24($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X24);
    // 0x8005CD14: nop

    // 0x8005CD18: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8005CD1C: b           L_8005CD90
    // 0x8005CD20: swc1        $f16, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f16.u32l;
        goto L_8005CD90;
    // 0x8005CD20: swc1        $f16, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f16.u32l;
L_8005CD24:
    // 0x8005CD24: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005CD28: lw          $t8, 0xE70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE70);
    // 0x8005CD2C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8005CD30: lwc1        $f4, -0xE38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XE38);
    // 0x8005CD34: lwc1        $f18, 0x30($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X30);
    // 0x8005CD38: nop

    // 0x8005CD3C: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8005CD40: nop

    // 0x8005CD44: bc1t        L_8005CD6C
    if (c1cs) {
        // 0x8005CD48: nop

            goto L_8005CD6C;
    }
    // 0x8005CD48: nop

    // 0x8005CD4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005CD50: lw          $t0, 0xE70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE70);
    // 0x8005CD54: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005CD58: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8005CD5C: nop

    // 0x8005CD60: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005CD64: b           L_8005CD90
    // 0x8005CD68: swc1        $f10, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f10.u32l;
        goto L_8005CD90;
    // 0x8005CD68: swc1        $f10, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f10.u32l;
L_8005CD6C:
    // 0x8005CD6C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8005CD70: nop

    // 0x8005CD74: lh          $t1, 0x0($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X0);
    // 0x8005CD78: nop

    // 0x8005CD7C: bne         $t1, $zero, L_8005CD90
    if (ctx->r9 != 0) {
        // 0x8005CD80: nop

            goto L_8005CD90;
    }
    // 0x8005CD80: nop

    // 0x8005CD84: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005CD88: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005CD8C: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
L_8005CD90:
    // 0x8005CD90: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005CD94: nop

    // 0x8005CD98: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x8005CD9C: b           L_8005CDAC
    // 0x8005CDA0: nop

        goto L_8005CDAC;
    // 0x8005CDA0: nop

    // 0x8005CDA4: b           L_8005CDAC
    // 0x8005CDA8: nop

        goto L_8005CDAC;
    // 0x8005CDA8: nop

L_8005CDAC:
    // 0x8005CDAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CDB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005CDB4: jr          $ra
    // 0x8005CDB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005CDB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005CDBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CDBC: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8005CDC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005CDC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005CDC8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005CDCC: nop

    // 0x8005CDD0: beq         $t6, $zero, L_8005CE2C
    if (ctx->r14 == 0) {
        // 0x8005CDD4: nop

            goto L_8005CE2C;
    }
    // 0x8005CDD4: nop

    // 0x8005CDD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005CDDC: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005CDE0: nop

    // 0x8005CDE4: beq         $t7, $zero, L_8005CE2C
    if (ctx->r15 == 0) {
        // 0x8005CDE8: nop

            goto L_8005CE2C;
    }
    // 0x8005CDE8: nop

    // 0x8005CDEC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005CDF0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8005CDF4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005CDF8: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005CDFC: bne         $t0, $zero, L_8005CE0C
    if (ctx->r8 != 0) {
        // 0x8005CE00: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8005CE0C;
    }
    // 0x8005CE00: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005CE04: beq         $t1, $zero, L_8005CE2C
    if (ctx->r9 == 0) {
        // 0x8005CE08: nop

            goto L_8005CE2C;
    }
    // 0x8005CE08: nop

L_8005CE0C:
    // 0x8005CE0C: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8005CE10: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8005CE14: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005CE18: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005CE1C: bne         $t4, $zero, L_8005CE34
    if (ctx->r12 != 0) {
        // 0x8005CE20: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8005CE34;
    }
    // 0x8005CE20: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8005CE24: bne         $t5, $zero, L_8005CE34
    if (ctx->r13 != 0) {
        // 0x8005CE28: nop

            goto L_8005CE34;
    }
    // 0x8005CE28: nop

L_8005CE2C:
    // 0x8005CE2C: b           L_8005D06C
    // 0x8005CE30: nop

        goto L_8005D06C;
    // 0x8005CE30: nop

L_8005CE34:
    // 0x8005CE34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005CE38: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005CE3C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005CE40: lw          $t9, 0xE70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE70);
    // 0x8005CE44: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x8005CE48: lw          $a1, 0x4C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4C);
    // 0x8005CE4C: lw          $a2, 0x50($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X50);
    // 0x8005CE50: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005CE54: lw          $t0, 0x4C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4C);
    // 0x8005CE58: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8005CE5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8005CE60: lw          $t1, 0x50($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X50);
    // 0x8005CE64: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005CE68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005CE6C: jal         0x800784E8
    // 0x8005CE70: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_800784E8(rdram, ctx);
        goto after_0;
    // 0x8005CE70: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x8005CE74: beq         $v0, $zero, L_8005CF54
    if (ctx->r2 == 0) {
        // 0x8005CE78: nop

            goto L_8005CF54;
    }
    // 0x8005CE78: nop

    // 0x8005CE7C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005CE80: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005CE84: lw          $t2, 0xE70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE70);
    // 0x8005CE88: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005CE8C: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8005CE90: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005CE94: nop

    // 0x8005CE98: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005CE9C: nop

    // 0x8005CEA0: bc1f        L_8005CEEC
    if (!c1cs) {
        // 0x8005CEA4: nop

            goto L_8005CEEC;
    }
    // 0x8005CEA4: nop

    // 0x8005CEA8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005CEAC: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005CEB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CEB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005CEB8: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x8005CEBC: nop

    // 0x8005CEC0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8005CEC4: swc1        $f16, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f16.u32l;
    // 0x8005CEC8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005CECC: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005CED0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CED4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005CED8: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8005CEDC: nop

    // 0x8005CEE0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005CEE4: b           L_8005CF2C
    // 0x8005CEE8: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
        goto L_8005CF2C;
    // 0x8005CEE8: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
L_8005CEEC:
    // 0x8005CEEC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005CEF0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005CEF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CEF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005CEFC: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8005CF00: nop

    // 0x8005CF04: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005CF08: swc1        $f16, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f16.u32l;
    // 0x8005CF0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005CF10: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005CF14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005CF18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005CF1C: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8005CF20: nop

    // 0x8005CF24: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8005CF28: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
L_8005CF2C:
    // 0x8005CF2C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005CF30: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005CF34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8005CF38: jal         0x8005D07C
    // 0x8005CF3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_1;
    // 0x8005CF3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x8005CF40: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005CF44: lw          $a0, 0xE70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE70);
    // 0x8005CF48: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8005CF4C: jal         0x8005D07C
    // 0x8005CF50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_2;
    // 0x8005CF50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
L_8005CF54:
    // 0x8005CF54: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005CF58: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005CF5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005CF60: lw          $a1, 0x4C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4C);
    // 0x8005CF64: lw          $a2, 0x50($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X50);
    // 0x8005CF68: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005CF6C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8005CF70: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005CF74: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8005CF78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005CF7C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8005CF80: jal         0x80077FF0
    // 0x8005CF84: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80077FF0(rdram, ctx);
        goto after_3;
    // 0x8005CF84: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8005CF88: beq         $v0, $zero, L_8005CFDC
    if (ctx->r2 == 0) {
        // 0x8005CF8C: nop

            goto L_8005CFDC;
    }
    // 0x8005CF8C: nop

    // 0x8005CF90: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005CF94: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005CF98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005CF9C: lw          $a3, 0x4C($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4C);
    // 0x8005CFA0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005CFA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005CFA8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8005CFAC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8005CFB0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8005CFB4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8005CFB8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8005CFBC: jal         0x80078168
    // 0x8005CFC0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80078168(rdram, ctx);
        goto after_4;
    // 0x8005CFC0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8005CFC4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005CFC8: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005CFCC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8005CFD0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8005CFD4: jal         0x8005D07C
    // 0x8005CFD8: nop

    func_8005D07C(rdram, ctx);
        goto after_5;
    // 0x8005CFD8: nop

    after_5:
L_8005CFDC:
    // 0x8005CFDC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005CFE0: lw          $t7, 0xE70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE70);
    // 0x8005CFE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005CFE8: lw          $a1, 0x4C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4C);
    // 0x8005CFEC: lw          $a2, 0x50($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X50);
    // 0x8005CFF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005CFF4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8005CFF8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8005CFFC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8005D000: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005D004: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8005D008: jal         0x80077FF0
    // 0x8005D00C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80077FF0(rdram, ctx);
        goto after_6;
    // 0x8005D00C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8005D010: beq         $v0, $zero, L_8005D064
    if (ctx->r2 == 0) {
        // 0x8005D014: nop

            goto L_8005D064;
    }
    // 0x8005D014: nop

    // 0x8005D018: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005D01C: lw          $t3, 0xE70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE70);
    // 0x8005D020: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005D024: lw          $a3, 0x4C($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4C);
    // 0x8005D028: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005D02C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005D030: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8005D034: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8005D038: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8005D03C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8005D040: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8005D044: jal         0x80078168
    // 0x8005D048: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80078168(rdram, ctx);
        goto after_7;
    // 0x8005D048: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x8005D04C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005D050: lw          $a0, 0xE70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE70);
    // 0x8005D054: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8005D058: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8005D05C: jal         0x8005D07C
    // 0x8005D060: nop

    func_8005D07C(rdram, ctx);
        goto after_8;
    // 0x8005D060: nop

    after_8:
L_8005D064:
    // 0x8005D064: b           L_8005D06C
    // 0x8005D068: nop

        goto L_8005D06C;
    // 0x8005D068: nop

L_8005D06C:
    // 0x8005D06C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005D070: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    // 0x8005D074: jr          $ra
    // 0x8005D078: nop

    return;
    // 0x8005D078: nop

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
RECOMP_FUNC void func_8005D150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D150: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D158: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005D15C: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D160: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D164: lui         $a2, 0x809E
    ctx->r6 = S32(0X809E << 16);
    // 0x8005D168: addiu       $a2, $a2, 0x55D8
    ctx->r6 = ADD32(ctx->r6, 0X55D8);
    // 0x8005D16C: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D170: jal         0x800BD1FC
    // 0x8005D174: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8005D174: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_0:
    // 0x8005D178: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D17C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005D180: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x8005D184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D188: jal         0x800BD218
    // 0x8005D18C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8005D18C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8005D190: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005D194: addiu       $t6, $t6, 0x5B0
    ctx->r14 = ADD32(ctx->r14, 0X5B0);
    // 0x8005D198: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8005D19C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D1A0: sw          $t7, 0x658($at)
    MEM_W(0X658, ctx->r1) = ctx->r15;
    // 0x8005D1A4: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D1A8: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D1AC: lui         $a2, 0x809E
    ctx->r6 = S32(0X809E << 16);
    // 0x8005D1B0: addiu       $a2, $a2, 0x55D4
    ctx->r6 = ADD32(ctx->r6, 0X55D4);
    // 0x8005D1B4: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D1B8: jal         0x800BD1FC
    // 0x8005D1BC: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8005D1BC: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_2:
    // 0x8005D1C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D1C4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005D1C8: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x8005D1CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D1D0: jal         0x800BD218
    // 0x8005D1D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8005D1D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8005D1D8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8005D1DC: addiu       $t8, $t8, 0x5B0
    ctx->r24 = ADD32(ctx->r24, 0X5B0);
    // 0x8005D1E0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005D1E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D1E8: sw          $t9, 0x660($at)
    MEM_W(0X660, ctx->r1) = ctx->r25;
    // 0x8005D1EC: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D1F0: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D1F4: lui         $a2, 0x809E
    ctx->r6 = S32(0X809E << 16);
    // 0x8005D1F8: addiu       $a2, $a2, 0x55DC
    ctx->r6 = ADD32(ctx->r6, 0X55DC);
    // 0x8005D1FC: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D200: jal         0x800BD1FC
    // 0x8005D204: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x8005D204: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_4:
    // 0x8005D208: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D20C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005D210: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x8005D214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D218: jal         0x800BD218
    // 0x8005D21C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x8005D21C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x8005D220: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8005D224:
    // 0x8005D224: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8005D228: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8005D22C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8005D230: lbu         $t1, 0x5B0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X5B0);
    // 0x8005D234: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D238: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8005D23C: sb          $t1, 0x668($at)
    MEM_B(0X668, ctx->r1) = ctx->r9;
    // 0x8005D240: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005D244: nop

    // 0x8005D248: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005D24C: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8005D250: bne         $at, $zero, L_8005D224
    if (ctx->r1 != 0) {
        // 0x8005D254: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8005D224;
    }
    // 0x8005D254: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8005D258: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D25C: sw          $zero, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = 0;
    // 0x8005D260: jal         0x8005D394
    // 0x8005D264: nop

    func_8005D394(rdram, ctx);
        goto after_6;
    // 0x8005D264: nop

    after_6:
    // 0x8005D268: jal         0x8005D2B0
    // 0x8005D26C: nop

    func_8005D2B0(rdram, ctx);
        goto after_7;
    // 0x8005D26C: nop

    after_7:
    // 0x8005D270: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D274: sw          $v0, 0x648($at)
    MEM_W(0X648, ctx->r1) = ctx->r2;
    // 0x8005D278: jal         0x8005D6BC
    // 0x8005D27C: nop

    func_8005D6BC(rdram, ctx);
        goto after_8;
    // 0x8005D27C: nop

    after_8:
    // 0x8005D280: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D284: sw          $v0, 0x650($at)
    MEM_W(0X650, ctx->r1) = ctx->r2;
    // 0x8005D288: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D28C: sw          $zero, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = 0;
    // 0x8005D290: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D294: sw          $zero, 0xE64($at)
    MEM_W(0XE64, ctx->r1) = 0;
    // 0x8005D298: b           L_8005D2A0
    // 0x8005D29C: nop

        goto L_8005D2A0;
    // 0x8005D29C: nop

L_8005D2A0:
    // 0x8005D2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D2A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D2A8: jr          $ra
    // 0x8005D2AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005D2AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005D2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D2B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D2B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D2B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D2BC: sb          $zero, 0xD74($at)
    MEM_B(0XD74, ctx->r1) = 0;
    // 0x8005D2C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D2C4: sb          $zero, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = 0;
    // 0x8005D2C8: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8005D2CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D2D0: sh          $t6, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r14;
    // 0x8005D2D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D2D8: sw          $zero, 0x13CC($at)
    MEM_W(0X13CC, ctx->r1) = 0;
    // 0x8005D2DC: jal         0x800BC918
    // 0x8005D2E0: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_0;
    // 0x8005D2E0: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_0:
    // 0x8005D2E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D2E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005D2EC:
    // 0x8005D2EC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005D2F0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D2F4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005D2F8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8005D2FC: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x8005D300: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005D304: nop

    // 0x8005D308: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8005D30C: slti        $at, $t2, 0x2A
    ctx->r1 = SIGNED(ctx->r10) < 0X2A ? 1 : 0;
    // 0x8005D310: bne         $at, $zero, L_8005D2EC
    if (ctx->r1 != 0) {
        // 0x8005D314: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_8005D2EC;
    }
    // 0x8005D314: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8005D318: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D31C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005D320: sh          $t3, 0x40($t4)
    MEM_H(0X40, ctx->r12) = ctx->r11;
    // 0x8005D324: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D328: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8005D32C: sh          $t5, 0x42($t6)
    MEM_H(0X42, ctx->r14) = ctx->r13;
    // 0x8005D330: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D334: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x8005D338: sh          $t8, 0x38($t7)
    MEM_H(0X38, ctx->r15) = ctx->r24;
    // 0x8005D33C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D340: nop

    // 0x8005D344: lh          $t0, 0x38($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X38);
    // 0x8005D348: nop

    // 0x8005D34C: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x8005D350: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D354: addiu       $t1, $zero, 0x12C
    ctx->r9 = ADD32(0, 0X12C);
    // 0x8005D358: sh          $t1, 0x3A($t2)
    MEM_H(0X3A, ctx->r10) = ctx->r9;
    // 0x8005D35C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D360: nop

    // 0x8005D364: lh          $t4, 0x3A($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X3A);
    // 0x8005D368: nop

    // 0x8005D36C: sh          $t4, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r12;
    // 0x8005D370: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D374: b           L_8005D384
    // 0x8005D378: nop

        goto L_8005D384;
    // 0x8005D378: nop

    // 0x8005D37C: b           L_8005D384
    // 0x8005D380: nop

        goto L_8005D384;
    // 0x8005D380: nop

L_8005D384:
    // 0x8005D384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D388: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D38C: jr          $ra
    // 0x8005D390: nop

    return;
    // 0x8005D390: nop

;}
RECOMP_FUNC void func_8005D394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D394: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005D398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D39C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D3A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D3A4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8005D3A8: addiu       $t7, $t7, -0x24E8
    ctx->r15 = ADD32(ctx->r15, -0X24E8);
    // 0x8005D3AC: addiu       $t9, $t7, 0x24
    ctx->r25 = ADD32(ctx->r15, 0X24);
    // 0x8005D3B0: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
L_8005D3B4:
    // 0x8005D3B4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005D3B8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8005D3BC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005D3C0: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8005D3C4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8005D3C8: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8005D3CC: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8005D3D0: bne         $t7, $t9, L_8005D3B4
    if (ctx->r15 != ctx->r25) {
        // 0x8005D3D4: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8005D3B4;
    }
    // 0x8005D3D4: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8005D3D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005D3DC: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8005D3E0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005D3E4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8005D3E8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8005D3EC:
    // 0x8005D3EC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005D3F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D3F4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005D3F8: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8005D3FC: lw          $a0, -0x2514($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2514);
    // 0x8005D400: nop

    // 0x8005D404: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x8005D408: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8005D40C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005D410: jal         0x800BC918
    // 0x8005D414: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_0;
    // 0x8005D414: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_0:
    // 0x8005D418: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005D41C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005D420: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005D424: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005D428: lw          $t5, -0x2540($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2540);
    // 0x8005D42C: nop

    // 0x8005D430: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8005D434: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005D438: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D43C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005D440: addu        $a2, $sp, $t9
    ctx->r6 = ADD32(ctx->r29, ctx->r25);
    // 0x8005D444: lw          $a2, 0x3C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3C);
    // 0x8005D448: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D44C: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D450: jal         0x800BD1FC
    // 0x8005D454: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x8005D454: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_1:
    // 0x8005D458: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005D45C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D460: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8005D464: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005D468: lw          $a0, -0x2514($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2514);
    // 0x8005D46C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8005D470: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x8005D474: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8005D478: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005D47C: jal         0x800BC6EC
    // 0x8005D480: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8005D480: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
    // 0x8005D484: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005D488: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005D48C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8005D490: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8005D494: lw          $a2, -0x2514($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2514);
    // 0x8005D498: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D49C: sll         $t3, $a2, 3
    ctx->r11 = S32(ctx->r6 << 3);
    // 0x8005D4A0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8005D4A4: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x8005D4A8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8005D4AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D4B0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8005D4B4: jal         0x800BD218
    // 0x8005D4B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8005D4B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8005D4BC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005D4C0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005D4C4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005D4C8: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8005D4CC: lw          $t8, -0x2540($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2540);
    // 0x8005D4D0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8005D4D4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005D4D8: lw          $t7, -0x2514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2514);
    // 0x8005D4DC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005D4E0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8005D4E4: blez        $t7, L_8005D67C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005D4E8: sw          $t9, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r25;
            goto L_8005D67C;
    }
    // 0x8005D4E8: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_8005D4EC:
    // 0x8005D4EC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005D4F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D4F4: sll         $t0, $t6, 3
    ctx->r8 = S32(ctx->r14 << 3);
    // 0x8005D4F8: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8005D4FC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005D500: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005D504: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8005D508: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8005D50C: addu        $t8, $t4, $t0
    ctx->r24 = ADD32(ctx->r12, ctx->r8);
    // 0x8005D510: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x8005D514: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005D518: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D51C: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x8005D520: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8005D524: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8005D528: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8005D52C: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8005D530: lh          $t1, 0x2($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X2);
    // 0x8005D534: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x8005D538: sh          $t1, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r9;
    // 0x8005D53C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005D540: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D544: sll         $t3, $t0, 3
    ctx->r11 = S32(ctx->r8 << 3);
    // 0x8005D548: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8005D54C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8005D550: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005D554: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x8005D558: lh          $t7, 0x4($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X4);
    // 0x8005D55C: addu        $t2, $t6, $t3
    ctx->r10 = ADD32(ctx->r14, ctx->r11);
    // 0x8005D560: sh          $t7, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r15;
    // 0x8005D564: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005D568: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D56C: sll         $t1, $t5, 3
    ctx->r9 = S32(ctx->r13 << 3);
    // 0x8005D570: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8005D574: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005D578: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005D57C: addu        $t0, $t1, $t4
    ctx->r8 = ADD32(ctx->r9, ctx->r12);
    // 0x8005D580: lh          $t8, 0x6($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X6);
    // 0x8005D584: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x8005D588: sh          $t8, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r24;
    // 0x8005D58C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8005D590: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D594: sll         $t7, $t3, 3
    ctx->r15 = S32(ctx->r11 << 3);
    // 0x8005D598: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8005D59C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8005D5A0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005D5A4: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x8005D5A8: lh          $t4, 0x8($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X8);
    // 0x8005D5AC: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x8005D5B0: sh          $t4, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r12;
    // 0x8005D5B4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005D5B8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D5BC: sll         $t8, $t1, 3
    ctx->r24 = S32(ctx->r9 << 3);
    // 0x8005D5C0: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8005D5C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8005D5C8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8005D5CC: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8005D5D0: lh          $t2, 0xA($t3)
    ctx->r10 = MEM_H(ctx->r11, 0XA);
    // 0x8005D5D4: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x8005D5D8: sh          $t2, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r10;
    // 0x8005D5DC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005D5E0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D5E4: sll         $t4, $t7, 3
    ctx->r12 = S32(ctx->r15 << 3);
    // 0x8005D5E8: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8005D5EC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8005D5F0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005D5F4: addu        $t1, $t4, $t9
    ctx->r9 = ADD32(ctx->r12, ctx->r25);
    // 0x8005D5F8: lh          $t6, 0xC($t1)
    ctx->r14 = MEM_H(ctx->r9, 0XC);
    // 0x8005D5FC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8005D600: sh          $t6, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r14;
    // 0x8005D604: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005D608: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D60C: sll         $t2, $t8, 3
    ctx->r10 = S32(ctx->r24 << 3);
    // 0x8005D610: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8005D614: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005D618: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005D61C: addu        $t7, $t2, $t0
    ctx->r15 = ADD32(ctx->r10, ctx->r8);
    // 0x8005D620: lh          $t9, 0xE($t7)
    ctx->r25 = MEM_H(ctx->r15, 0XE);
    // 0x8005D624: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8005D628: sh          $t9, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r25;
    // 0x8005D62C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8005D630: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D634: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x8005D638: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8005D63C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005D640: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005D644: addu        $t8, $t6, $t5
    ctx->r24 = ADD32(ctx->r14, ctx->r13);
    // 0x8005D648: lh          $t0, 0x10($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X10);
    // 0x8005D64C: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x8005D650: sh          $t0, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r8;
    // 0x8005D654: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005D658: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005D65C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005D660: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005D664: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005D668: lw          $t5, -0x2514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2514);
    // 0x8005D66C: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8005D670: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005D674: bne         $at, $zero, L_8005D4EC
    if (ctx->r1 != 0) {
        // 0x8005D678: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_8005D4EC;
    }
    // 0x8005D678: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8005D67C:
    // 0x8005D67C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D680: jal         0x800BC980
    // 0x8005D684: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x8005D684: nop

    after_4:
    // 0x8005D688: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005D68C: nop

    // 0x8005D690: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8005D694: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x8005D698: bne         $at, $zero, L_8005D3EC
    if (ctx->r1 != 0) {
        // 0x8005D69C: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_8005D3EC;
    }
    // 0x8005D69C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8005D6A0: b           L_8005D6A8
    // 0x8005D6A4: nop

        goto L_8005D6A8;
    // 0x8005D6A4: nop

L_8005D6A8:
    // 0x8005D6A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D6AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005D6B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005D6B4: jr          $ra
    // 0x8005D6B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8005D6B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8005D6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D6BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005D6C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D6C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D6C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D6CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005D6D0: lw          $a0, 0x658($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X658);
    // 0x8005D6D4: nop

    // 0x8005D6D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8005D6DC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8005D6E0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005D6E4: jal         0x800BC918
    // 0x8005D6E8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_0;
    // 0x8005D6E8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8005D6EC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8005D6F0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8005D6F4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x8005D6F8: lui         $a2, 0x809E
    ctx->r6 = S32(0X809E << 16);
    // 0x8005D6FC: addiu       $a2, $a2, -0xE3C
    ctx->r6 = ADD32(ctx->r6, -0XE3C);
    // 0x8005D700: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8005D704: jal         0x800BD1FC
    // 0x8005D708: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x8005D708: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_1:
    // 0x8005D70C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005D710: lw          $a0, 0x660($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X660);
    // 0x8005D714: jal         0x800BC6EC
    // 0x8005D718: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8005D718: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_2:
    // 0x8005D71C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D720: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005D724: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005D728: lw          $a2, 0x660($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X660);
    // 0x8005D72C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8005D730: jal         0x800BD218
    // 0x8005D734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8005D734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8005D738: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005D73C: lw          $t8, 0x658($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X658);
    // 0x8005D740: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005D744: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8005D748: beq         $t8, $zero, L_8005D7CC
    if (ctx->r24 == 0) {
        // 0x8005D74C: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_8005D7CC;
    }
    // 0x8005D74C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8005D750:
    // 0x8005D750: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005D754: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005D758: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8005D75C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8005D760: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005D764: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8005D768: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8005D76C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D770: nop

    // 0x8005D774: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8005D778: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D77C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8005D780: sb          $t5, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r13;
    // 0x8005D784: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D788: nop

    // 0x8005D78C: sb          $zero, 0x3($t7)
    MEM_B(0X3, ctx->r15) = 0;
    // 0x8005D790: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005D794: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D798: lbu         $t9, 0xA($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XA);
    // 0x8005D79C: nop

    // 0x8005D7A0: sb          $t9, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r25;
    // 0x8005D7A4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005D7A8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005D7AC: lw          $t5, 0x658($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X658);
    // 0x8005D7B0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D7B4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8005D7B8: sltu        $at, $t2, $t5
    ctx->r1 = ctx->r10 < ctx->r13 ? 1 : 0;
    // 0x8005D7BC: addiu       $t4, $t3, 0x6
    ctx->r12 = ADD32(ctx->r11, 0X6);
    // 0x8005D7C0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8005D7C4: bne         $at, $zero, L_8005D750
    if (ctx->r1 != 0) {
        // 0x8005D7C8: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_8005D750;
    }
    // 0x8005D7C8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_8005D7CC:
    // 0x8005D7CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005D7D0: jal         0x800BC980
    // 0x8005D7D4: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x8005D7D4: nop

    after_4:
    // 0x8005D7D8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8005D7DC: b           L_8005D7EC
    // 0x8005D7E0: nop

        goto L_8005D7EC;
    // 0x8005D7E0: nop

    // 0x8005D7E4: b           L_8005D7EC
    // 0x8005D7E8: nop

        goto L_8005D7EC;
    // 0x8005D7E8: nop

L_8005D7EC:
    // 0x8005D7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D7F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005D7F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005D7F8: jr          $ra
    // 0x8005D7FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005D7FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005D800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D800: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005D804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D808: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D80C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D810: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D814: sw          $zero, 0x640($at)
    MEM_W(0X640, ctx->r1) = 0;
    // 0x8005D818: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D81C: sw          $zero, 0x644($at)
    MEM_W(0X644, ctx->r1) = 0;
    // 0x8005D820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D824: sb          $zero, 0xEE8($at)
    MEM_B(0XEE8, ctx->r1) = 0;
    // 0x8005D828: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D82C: sb          $zero, 0x1018($at)
    MEM_B(0X1018, ctx->r1) = 0;
    // 0x8005D830: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005D834:
    // 0x8005D834: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D838: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D83C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005D840: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005D844: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005D848: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005D84C: sb          $zero, 0xF18($at)
    MEM_B(0XF18, ctx->r1) = 0;
    // 0x8005D850: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D854: nop

    // 0x8005D858: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005D85C: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x8005D860: bne         $at, $zero, L_8005D834
    if (ctx->r1 != 0) {
        // 0x8005D864: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8005D834;
    }
    // 0x8005D864: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8005D868: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D86C: sb          $zero, 0x1040($at)
    MEM_B(0X1040, ctx->r1) = 0;
    // 0x8005D870: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005D874:
    // 0x8005D874: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D878: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D87C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005D880: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8005D884: sw          $zero, 0x1028($at)
    MEM_W(0X1028, ctx->r1) = 0;
    // 0x8005D888: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D88C: nop

    // 0x8005D890: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005D894: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8005D898: bne         $at, $zero, L_8005D874
    if (ctx->r1 != 0) {
        // 0x8005D89C: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8005D874;
    }
    // 0x8005D89C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8005D8A0: jal         0x800BC6EC
    // 0x8005D8A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8005D8A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_0:
    // 0x8005D8A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D8AC: sw          $v0, 0x640($at)
    MEM_W(0X640, ctx->r1) = ctx->r2;
    // 0x8005D8B0: jal         0x800BC6EC
    // 0x8005D8B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8005D8B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_1:
    // 0x8005D8B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D8BC: sw          $v0, 0x644($at)
    MEM_W(0X644, ctx->r1) = ctx->r2;
    // 0x8005D8C0: jal         0x8005E908
    // 0x8005D8C4: nop

    func_8005E908(rdram, ctx);
        goto after_2;
    // 0x8005D8C4: nop

    after_2:
    // 0x8005D8C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D8CC: sw          $v0, 0xE64($at)
    MEM_W(0XE64, ctx->r1) = ctx->r2;
    // 0x8005D8D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005D8D4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005D8D8: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8005D8DC: ori         $t5, $t5, 0x9
    ctx->r13 = ctx->r13 | 0X9;
    // 0x8005D8E0: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8005D8E4: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8005D8E8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005D8EC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005D8F0: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005D8F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D8F8: sh          $t7, 0x7C($t8)
    MEM_H(0X7C, ctx->r24) = ctx->r15;
    // 0x8005D8FC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005D900: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005D904: nop

    // 0x8005D908: sw          $zero, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = 0;
    // 0x8005D90C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005D910: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005D914: nop

    // 0x8005D918: sw          $zero, 0x58($t0)
    MEM_W(0X58, ctx->r8) = 0;
    // 0x8005D91C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8005D920: jal         0x80056E88
    // 0x8005D924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_3;
    // 0x8005D924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8005D928: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x8005D92C: jal         0x8005EF24
    // 0x8005D930: nop

    func_8005EF24(rdram, ctx);
        goto after_4;
    // 0x8005D930: nop

    after_4:
    // 0x8005D934: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D938: sw          $zero, 0x161C($at)
    MEM_W(0X161C, ctx->r1) = 0;
    // 0x8005D93C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D940: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
    // 0x8005D944: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D948: sw          $zero, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = 0;
    // 0x8005D94C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8005D950: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8005D954: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005D958: bne         $t1, $at, L_8005D974
    if (ctx->r9 != ctx->r1) {
        // 0x8005D95C: nop

            goto L_8005D974;
    }
    // 0x8005D95C: nop

    // 0x8005D960: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005D964: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x8005D968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D96C: beq         $t2, $at, L_8005DA64
    if (ctx->r10 == ctx->r1) {
        // 0x8005D970: nop

            goto L_8005DA64;
    }
    // 0x8005D970: nop

L_8005D974:
    // 0x8005D974: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005D978: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005D97C: nop

    // 0x8005D980: lh          $t4, 0x30($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X30);
    // 0x8005D984: nop

    // 0x8005D988: slti        $at, $t4, 0x2BC
    ctx->r1 = SIGNED(ctx->r12) < 0X2BC ? 1 : 0;
    // 0x8005D98C: bne         $at, $zero, L_8005D9B0
    if (ctx->r1 != 0) {
        // 0x8005D990: nop

            goto L_8005D9B0;
    }
    // 0x8005D990: nop

    // 0x8005D994: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005D998: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8005D99C: nop

    // 0x8005D9A0: lh          $t6, 0x30($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X30);
    // 0x8005D9A4: nop

    // 0x8005D9A8: addiu       $t7, $t6, -0x32
    ctx->r15 = ADD32(ctx->r14, -0X32);
    // 0x8005D9AC: sh          $t7, 0x30($t5)
    MEM_H(0X30, ctx->r13) = ctx->r15;
L_8005D9B0:
    // 0x8005D9B0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005D9B4: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005D9B8: nop

    // 0x8005D9BC: lh          $t9, 0x32($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X32);
    // 0x8005D9C0: nop

    // 0x8005D9C4: slti        $at, $t9, 0x2BC
    ctx->r1 = SIGNED(ctx->r25) < 0X2BC ? 1 : 0;
    // 0x8005D9C8: bne         $at, $zero, L_8005D9EC
    if (ctx->r1 != 0) {
        // 0x8005D9CC: nop

            goto L_8005D9EC;
    }
    // 0x8005D9CC: nop

    // 0x8005D9D0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005D9D4: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8005D9D8: nop

    // 0x8005D9DC: lh          $t1, 0x32($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X32);
    // 0x8005D9E0: nop

    // 0x8005D9E4: addiu       $t2, $t1, -0x32
    ctx->r10 = ADD32(ctx->r9, -0X32);
    // 0x8005D9E8: sh          $t2, 0x32($t0)
    MEM_H(0X32, ctx->r8) = ctx->r10;
L_8005D9EC:
    // 0x8005D9EC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005D9F0: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005D9F4: nop

    // 0x8005D9F8: lh          $t4, 0x34($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X34);
    // 0x8005D9FC: nop

    // 0x8005DA00: slti        $at, $t4, 0x2BC
    ctx->r1 = SIGNED(ctx->r12) < 0X2BC ? 1 : 0;
    // 0x8005DA04: bne         $at, $zero, L_8005DA28
    if (ctx->r1 != 0) {
        // 0x8005DA08: nop

            goto L_8005DA28;
    }
    // 0x8005DA08: nop

    // 0x8005DA0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005DA10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005DA14: nop

    // 0x8005DA18: lh          $t7, 0x34($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X34);
    // 0x8005DA1C: nop

    // 0x8005DA20: addiu       $t5, $t7, -0x32
    ctx->r13 = ADD32(ctx->r15, -0X32);
    // 0x8005DA24: sh          $t5, 0x34($t6)
    MEM_H(0X34, ctx->r14) = ctx->r13;
L_8005DA28:
    // 0x8005DA28: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005DA2C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005DA30: nop

    // 0x8005DA34: lh          $t9, 0x36($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X36);
    // 0x8005DA38: nop

    // 0x8005DA3C: slti        $at, $t9, 0x2BC
    ctx->r1 = SIGNED(ctx->r25) < 0X2BC ? 1 : 0;
    // 0x8005DA40: bne         $at, $zero, L_8005DA64
    if (ctx->r1 != 0) {
        // 0x8005DA44: nop

            goto L_8005DA64;
    }
    // 0x8005DA44: nop

    // 0x8005DA48: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DA4C: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005DA50: nop

    // 0x8005DA54: lh          $t2, 0x36($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X36);
    // 0x8005DA58: nop

    // 0x8005DA5C: addiu       $t0, $t2, -0x32
    ctx->r8 = ADD32(ctx->r10, -0X32);
    // 0x8005DA60: sh          $t0, 0x36($t1)
    MEM_H(0X36, ctx->r9) = ctx->r8;
L_8005DA64:
    // 0x8005DA64: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005DA68: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005DA6C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8005DA70: bne         $t3, $at, L_8005DABC
    if (ctx->r11 != ctx->r1) {
        // 0x8005DA74: nop

            goto L_8005DABC;
    }
    // 0x8005DA74: nop

    // 0x8005DA78: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005DA7C: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x8005DA80: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8005DA84: bne         $t4, $at, L_8005DABC
    if (ctx->r12 != ctx->r1) {
        // 0x8005DA88: nop

            goto L_8005DABC;
    }
    // 0x8005DA88: nop

    // 0x8005DA8C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005DA90: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8005DA94: nop

    // 0x8005DA98: lh          $t5, 0x38($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X38);
    // 0x8005DA9C: nop

    // 0x8005DAA0: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x8005DAA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005DAA8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005DAAC: nop

    // 0x8005DAB0: lh          $t8, 0x3A($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X3A);
    // 0x8005DAB4: nop

    // 0x8005DAB8: sh          $t8, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r24;
L_8005DABC:
    // 0x8005DABC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8005DAC0: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8005DAC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DAC8: bne         $t9, $at, L_8005DAE4
    if (ctx->r25 != ctx->r1) {
        // 0x8005DACC: nop

            goto L_8005DAE4;
    }
    // 0x8005DACC: nop

    // 0x8005DAD0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005DAD4: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x8005DAD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DADC: beq         $t2, $at, L_8005DB34
    if (ctx->r10 == ctx->r1) {
        // 0x8005DAE0: nop

            goto L_8005DB34;
    }
    // 0x8005DAE0: nop

L_8005DAE4:
    // 0x8005DAE4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8005DAE8: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8005DAEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DAF0: bne         $t0, $at, L_8005DB0C
    if (ctx->r8 != ctx->r1) {
        // 0x8005DAF4: nop

            goto L_8005DB0C;
    }
    // 0x8005DAF4: nop

    // 0x8005DAF8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8005DAFC: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x8005DB00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DB04: beq         $t1, $at, L_8005DB34
    if (ctx->r9 == ctx->r1) {
        // 0x8005DB08: nop

            goto L_8005DB34;
    }
    // 0x8005DB08: nop

L_8005DB0C:
    // 0x8005DB0C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005DB10: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005DB14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DB18: bne         $t3, $at, L_8005DB90
    if (ctx->r11 != ctx->r1) {
        // 0x8005DB1C: nop

            goto L_8005DB90;
    }
    // 0x8005DB1C: nop

    // 0x8005DB20: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005DB24: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x8005DB28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005DB2C: bne         $t4, $at, L_8005DB90
    if (ctx->r12 != ctx->r1) {
        // 0x8005DB30: nop

            goto L_8005DB90;
    }
    // 0x8005DB30: nop

L_8005DB34:
    // 0x8005DB34: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005DB38: lw          $t5, 0x13CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X13CC);
    // 0x8005DB3C: nop

    // 0x8005DB40: bne         $t5, $zero, L_8005DB88
    if (ctx->r13 != 0) {
        // 0x8005DB44: nop

            goto L_8005DB88;
    }
    // 0x8005DB44: nop

    // 0x8005DB48: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8005DB4C: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8005DB50: nop

    // 0x8005DB54: bgez        $t7, L_8005DB88
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005DB58: nop

            goto L_8005DB88;
    }
    // 0x8005DB58: nop

    // 0x8005DB5C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8005DB60: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8005DB64: lhu         $t6, 0x6($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X6);
    // 0x8005DB68: nop

    // 0x8005DB6C: ori         $t9, $t6, 0x1
    ctx->r25 = ctx->r14 | 0X1;
    // 0x8005DB70: sh          $t9, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r25;
    // 0x8005DB74: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005DB78: lw          $t2, 0x13CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X13CC);
    // 0x8005DB7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005DB80: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8005DB84: sw          $t0, 0x13CC($at)
    MEM_W(0X13CC, ctx->r1) = ctx->r8;
L_8005DB88:
    // 0x8005DB88: b           L_8005DB98
    // 0x8005DB8C: nop

        goto L_8005DB98;
    // 0x8005DB8C: nop

L_8005DB90:
    // 0x8005DB90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005DB94: sw          $zero, 0x13CC($at)
    MEM_W(0X13CC, ctx->r1) = 0;
L_8005DB98:
    // 0x8005DB98: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8005DB9C: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8005DBA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DBA4: bne         $t1, $at, L_8005DC08
    if (ctx->r9 != ctx->r1) {
        // 0x8005DBA8: nop

            goto L_8005DC08;
    }
    // 0x8005DBA8: nop

    // 0x8005DBAC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005DBB0: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8005DBB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DBB8: bne         $t3, $at, L_8005DC08
    if (ctx->r11 != ctx->r1) {
        // 0x8005DBBC: nop

            goto L_8005DC08;
    }
    // 0x8005DBBC: nop

    // 0x8005DBC0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8005DBC4: lh          $t4, -0x73C0($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X73C0);
    // 0x8005DBC8: nop

    // 0x8005DBCC: bgez        $t4, L_8005DC08
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8005DBD0: nop

            goto L_8005DC08;
    }
    // 0x8005DBD0: nop

    // 0x8005DBD4: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x8005DBD8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8005DBDC: lw          $t7, -0x33BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33BC);
    // 0x8005DBE0: lw          $t5, 0x18EC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X18EC);
    // 0x8005DBE4: nop

    // 0x8005DBE8: beq         $t5, $t7, L_8005DC08
    if (ctx->r13 == ctx->r15) {
        // 0x8005DBEC: nop

            goto L_8005DC08;
    }
    // 0x8005DBEC: nop

    // 0x8005DBF0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8005DBF4: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8005DBF8: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x8005DBFC: nop

    // 0x8005DC00: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x8005DC04: sh          $t8, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r24;
L_8005DC08:
    // 0x8005DC08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005DC0C: lh          $t2, 0x721C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X721C);
    // 0x8005DC10: nop

    // 0x8005DC14: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8005DC18: beq         $at, $zero, L_8005E070
    if (ctx->r1 == 0) {
        // 0x8005DC1C: nop

            goto L_8005E070;
    }
    // 0x8005DC1C: nop

    // 0x8005DC20: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8005DC24: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8005DC28: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8005DC2C: beq         $t0, $at, L_8005E070
    if (ctx->r8 == ctx->r1) {
        // 0x8005DC30: nop

            goto L_8005E070;
    }
    // 0x8005DC30: nop

    // 0x8005DC34: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DC38: lbu         $t1, 0xD94($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XD94);
    // 0x8005DC3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DC40: bne         $t1, $at, L_8005DDE4
    if (ctx->r9 != ctx->r1) {
        // 0x8005DC44: nop

            goto L_8005DDE4;
    }
    // 0x8005DC44: nop

    // 0x8005DC48: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005DC4C: jal         0x800047C8
    // 0x8005DC50: addiu       $a0, $a0, 0x61A0
    ctx->r4 = ADD32(ctx->r4, 0X61A0);
    func_800047C8(rdram, ctx);
        goto after_5;
    // 0x8005DC50: addiu       $a0, $a0, 0x61A0
    ctx->r4 = ADD32(ctx->r4, 0X61A0);
    after_5:
    // 0x8005DC54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005DC58: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005DC5C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005DC60: lwc1        $f4, 0x61A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61A0);
    // 0x8005DC64: nop

    // 0x8005DC68: swc1        $f4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f4.u32l;
    // 0x8005DC6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005DC70: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005DC74: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005DC78: lwc1        $f6, 0x61A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61A4);
    // 0x8005DC7C: nop

    // 0x8005DC80: swc1        $f6, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f6.u32l;
    // 0x8005DC84: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005DC88: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005DC8C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005DC90: lw          $t5, 0xE4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE4C);
    // 0x8005DC94: nop

    // 0x8005DC98: sw          $t5, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r13;
    // 0x8005DC9C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8005DCA0: lhu         $t9, 0x61B8($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X61B8);
    // 0x8005DCA4: nop

    // 0x8005DCA8: beq         $t9, $zero, L_8005DCD8
    if (ctx->r25 == 0) {
        // 0x8005DCAC: nop

            goto L_8005DCD8;
    }
    // 0x8005DCAC: nop

    // 0x8005DCB0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005DCB4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005DCB8: nop

    // 0x8005DCBC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8005DCC0: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8005DCC4: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x8005DCC8: ori         $t3, $t7, 0x8
    ctx->r11 = ctx->r15 | 0X8;
    // 0x8005DCCC: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8005DCD0: b           L_8005DD00
    // 0x8005DCD4: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
        goto L_8005DD00;
    // 0x8005DCD4: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
L_8005DCD8:
    // 0x8005DCD8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005DCDC: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005DCE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005DCE4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005DCE8: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8005DCEC: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8005DCF0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005DCF4: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005DCF8: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8005DCFC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_8005DD00:
    // 0x8005DD00: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8005DD04: lhu         $t1, 0x61BC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X61BC);
    // 0x8005DD08: nop

    // 0x8005DD0C: beq         $t1, $zero, L_8005DDDC
    if (ctx->r9 == 0) {
        // 0x8005DD10: nop

            goto L_8005DDDC;
    }
    // 0x8005DD10: nop

    // 0x8005DD14: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005DD18: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005DD1C: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8005DD20: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8005DD24: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8005DD28: or          $t4, $t9, $zero
    ctx->r12 = ctx->r25 | 0;
    // 0x8005DD2C: or          $t8, $t2, $zero
    ctx->r24 = ctx->r10 | 0;
    // 0x8005DD30: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x8005DD34: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8005DD38: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8005DD3C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005DD40: lh          $s0, 0xDA4($s0)
    ctx->r16 = MEM_H(ctx->r16, 0XDA4);
    // 0x8005DD44: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x8005DD48: beq         $s0, $at, L_8005DD64
    if (ctx->r16 == ctx->r1) {
        // 0x8005DD4C: nop

            goto L_8005DD64;
    }
    // 0x8005DD4C: nop

    // 0x8005DD50: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x8005DD54: beq         $s0, $at, L_8005DD98
    if (ctx->r16 == ctx->r1) {
        // 0x8005DD58: nop

            goto L_8005DD98;
    }
    // 0x8005DD58: nop

    // 0x8005DD5C: b           L_8005DDCC
    // 0x8005DD60: nop

        goto L_8005DDCC;
    // 0x8005DD60: nop

L_8005DD64:
    // 0x8005DD64: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005DD68: lh          $t5, 0x12BA($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X12BA);
    // 0x8005DD6C: nop

    // 0x8005DD70: andi        $t6, $t5, 0xC0
    ctx->r14 = ctx->r13 & 0XC0;
    // 0x8005DD74: beq         $t6, $zero, L_8005DD88
    if (ctx->r14 == 0) {
        // 0x8005DD78: nop

            goto L_8005DD88;
    }
    // 0x8005DD78: nop

    // 0x8005DD7C: addiu       $t7, $zero, 0xAB
    ctx->r15 = ADD32(0, 0XAB);
    // 0x8005DD80: b           L_8005DD90
    // 0x8005DD84: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
        goto L_8005DD90;
    // 0x8005DD84: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
L_8005DD88:
    // 0x8005DD88: addiu       $t0, $zero, 0xAD
    ctx->r8 = ADD32(0, 0XAD);
    // 0x8005DD8C: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
L_8005DD90:
    // 0x8005DD90: b           L_8005DDDC
    // 0x8005DD94: nop

        goto L_8005DDDC;
    // 0x8005DD94: nop

L_8005DD98:
    // 0x8005DD98: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DD9C: lh          $t1, 0x12BA($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X12BA);
    // 0x8005DDA0: nop

    // 0x8005DDA4: andi        $t2, $t1, 0xC0
    ctx->r10 = ctx->r9 & 0XC0;
    // 0x8005DDA8: beq         $t2, $zero, L_8005DDBC
    if (ctx->r10 == 0) {
        // 0x8005DDAC: nop

            goto L_8005DDBC;
    }
    // 0x8005DDAC: nop

    // 0x8005DDB0: addiu       $t3, $zero, 0xAC
    ctx->r11 = ADD32(0, 0XAC);
    // 0x8005DDB4: b           L_8005DDC4
    // 0x8005DDB8: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
        goto L_8005DDC4;
    // 0x8005DDB8: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
L_8005DDBC:
    // 0x8005DDBC: addiu       $t8, $zero, 0xAE
    ctx->r24 = ADD32(0, 0XAE);
    // 0x8005DDC0: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
L_8005DDC4:
    // 0x8005DDC4: b           L_8005DDDC
    // 0x8005DDC8: nop

        goto L_8005DDDC;
    // 0x8005DDC8: nop

L_8005DDCC:
    // 0x8005DDCC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005DDD0: lh          $t9, 0xDA4($t9)
    ctx->r25 = MEM_H(ctx->r25, 0XDA4);
    // 0x8005DDD4: nop

    // 0x8005DDD8: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
L_8005DDDC:
    // 0x8005DDDC: b           L_8005DE74
    // 0x8005DDE0: nop

        goto L_8005DE74;
    // 0x8005DDE0: nop

L_8005DDE4:
    // 0x8005DDE4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005DDE8: lbu         $t4, 0xD94($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0XD94);
    // 0x8005DDEC: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8005DDF0: bne         $t4, $at, L_8005DE74
    if (ctx->r12 != ctx->r1) {
        // 0x8005DDF4: nop

            goto L_8005DE74;
    }
    // 0x8005DDF4: nop

    // 0x8005DDF8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8005DDFC: lh          $t5, -0x73C0($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X73C0);
    // 0x8005DE00: nop

    // 0x8005DE04: bgez        $t5, L_8005DE74
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8005DE08: nop

            goto L_8005DE74;
    }
    // 0x8005DE08: nop

    // 0x8005DE0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005DE10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005DE14: nop

    // 0x8005DE18: lh          $t7, 0x40($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X40);
    // 0x8005DE1C: nop

    // 0x8005DE20: addiu       $t0, $t7, 0x3
    ctx->r8 = ADD32(ctx->r15, 0X3);
    // 0x8005DE24: sh          $t0, 0x40($t6)
    MEM_H(0X40, ctx->r14) = ctx->r8;
    // 0x8005DE28: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DE2C: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005DE30: nop

    // 0x8005DE34: lh          $t2, 0x40($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X40);
    // 0x8005DE38: nop

    // 0x8005DE3C: slti        $at, $t2, 0x3E8
    ctx->r1 = SIGNED(ctx->r10) < 0X3E8 ? 1 : 0;
    // 0x8005DE40: bne         $at, $zero, L_8005DE58
    if (ctx->r1 != 0) {
        // 0x8005DE44: nop

            goto L_8005DE58;
    }
    // 0x8005DE44: nop

    // 0x8005DE48: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005DE4C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005DE50: addiu       $t3, $zero, 0x3E7
    ctx->r11 = ADD32(0, 0X3E7);
    // 0x8005DE54: sh          $t3, 0x40($t8)
    MEM_H(0X40, ctx->r24) = ctx->r11;
L_8005DE58:
    // 0x8005DE58: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8005DE5C: lw          $t9, 0x718C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X718C);
    // 0x8005DE60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8005DE64: addiu       $t4, $t9, -0x12C
    ctx->r12 = ADD32(ctx->r25, -0X12C);
    // 0x8005DE68: sw          $t4, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r12;
    // 0x8005DE6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005DE70: sb          $zero, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = 0;
L_8005DE74:
    // 0x8005DE74: lh          $t5, 0x2A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2A);
    // 0x8005DE78: addiu       $at, $zero, 0xAD
    ctx->r1 = ADD32(0, 0XAD);
    // 0x8005DE7C: beq         $t5, $at, L_8005DE90
    if (ctx->r13 == ctx->r1) {
        // 0x8005DE80: nop

            goto L_8005DE90;
    }
    // 0x8005DE80: nop

    // 0x8005DE84: addiu       $at, $zero, 0xAE
    ctx->r1 = ADD32(0, 0XAE);
    // 0x8005DE88: bne         $t5, $at, L_8005DEBC
    if (ctx->r13 != ctx->r1) {
        // 0x8005DE8C: nop

            goto L_8005DEBC;
    }
    // 0x8005DE8C: nop

L_8005DE90:
    // 0x8005DE90: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005DE94: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005DE98: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8005DE9C: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8005DEA0: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8005DEA4: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x8005DEA8: or          $t6, $t0, $zero
    ctx->r14 = ctx->r8 | 0;
    // 0x8005DEAC: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x8005DEB0: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8005DEB4: b           L_8005DF58
    // 0x8005DEB8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
        goto L_8005DF58;
    // 0x8005DEB8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_8005DEBC:
    // 0x8005DEBC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005DEC0: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005DEC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DEC8: beq         $t3, $at, L_8005DF58
    if (ctx->r11 == ctx->r1) {
        // 0x8005DECC: nop

            goto L_8005DF58;
    }
    // 0x8005DECC: nop

    // 0x8005DED0: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8005DED4: addiu       $at, $zero, 0x9B
    ctx->r1 = ADD32(0, 0X9B);
    // 0x8005DED8: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DEDC: nop

            goto L_8005DF34;
    }
    // 0x8005DEDC: nop

    // 0x8005DEE0: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x8005DEE4: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DEE8: nop

            goto L_8005DF34;
    }
    // 0x8005DEE8: nop

    // 0x8005DEEC: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8005DEF0: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DEF4: nop

            goto L_8005DF34;
    }
    // 0x8005DEF4: nop

    // 0x8005DEF8: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x8005DEFC: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DF00: nop

            goto L_8005DF34;
    }
    // 0x8005DF00: nop

    // 0x8005DF04: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x8005DF08: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DF0C: nop

            goto L_8005DF34;
    }
    // 0x8005DF0C: nop

    // 0x8005DF10: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x8005DF14: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DF18: nop

            goto L_8005DF34;
    }
    // 0x8005DF18: nop

    // 0x8005DF1C: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x8005DF20: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DF24: nop

            goto L_8005DF34;
    }
    // 0x8005DF24: nop

    // 0x8005DF28: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x8005DF2C: bne         $t8, $at, L_8005DF58
    if (ctx->r24 != ctx->r1) {
        // 0x8005DF30: nop

            goto L_8005DF58;
    }
    // 0x8005DF30: nop

L_8005DF34:
    // 0x8005DF34: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005DF38: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005DF3C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8005DF40: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8005DF44: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8005DF48: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8005DF4C: or          $t1, $t5, $at
    ctx->r9 = ctx->r13 | ctx->r1;
    // 0x8005DF50: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8005DF54: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
L_8005DF58:
    // 0x8005DF58: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8005DF5C: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8005DF60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005DF64: bne         $t6, $at, L_8005E024
    if (ctx->r14 != ctx->r1) {
        // 0x8005DF68: nop

            goto L_8005E024;
    }
    // 0x8005DF68: nop

    // 0x8005DF6C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005DF70: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8005DF74: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005DF78: bne         $t7, $at, L_8005E024
    if (ctx->r15 != ctx->r1) {
        // 0x8005DF7C: nop

            goto L_8005E024;
    }
    // 0x8005DF7C: nop

    // 0x8005DF80: addiu       $t2, $zero, 0x23
    ctx->r10 = ADD32(0, 0X23);
    // 0x8005DF84: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
    // 0x8005DF88: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005DF8C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005DF90: nop

    // 0x8005DF94: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8005DF98: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8005DF9C: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x8005DFA0: ori         $t5, $t9, 0x20
    ctx->r13 = ctx->r25 | 0X20;
    // 0x8005DFA4: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8005DFA8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8005DFAC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005DFB0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005DFB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005DFB8: nop

    // 0x8005DFBC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x8005DFC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8005DFC4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DFC8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005DFCC: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8005DFD0: nop

    // 0x8005DFD4: swc1        $f10, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f10.u32l;
    // 0x8005DFD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005DFDC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005DFE0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8005DFE4: sw          $t6, 0x9C($t7)
    MEM_W(0X9C, ctx->r15) = ctx->r14;
    // 0x8005DFE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005DFEC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005DFF0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005DFF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005DFF8: nop

    // 0x8005DFFC: swc1        $f16, 0xA0($t2)
    MEM_W(0XA0, ctx->r10) = ctx->f16.u32l;
    // 0x8005E000: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005E004: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005E008: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8005E00C: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x8005E010: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8005E014: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8005E018: or          $t1, $t5, $at
    ctx->r9 = ctx->r13 | ctx->r1;
    // 0x8005E01C: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8005E020: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_8005E024:
    // 0x8005E024: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005E028: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005E02C: jal         0x8005EC54
    // 0x8005E030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005EC54(rdram, ctx);
        goto after_6;
    // 0x8005E030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8005E034: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    // 0x8005E038: jal         0x80056E88
    // 0x8005E03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_7;
    // 0x8005E03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8005E040: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005E044: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005E048: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8005E04C: sra         $t9, $s1, 16
    ctx->r25 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8005E050: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8005E054: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x8005E058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E05C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005E060: jal         0x8004EF90
    // 0x8005E064: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_8;
    // 0x8005E064: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x8005E068: b           L_8005E098
    // 0x8005E06C: nop

        goto L_8005E098;
    // 0x8005E06C: nop

L_8005E070:
    // 0x8005E070: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005E074: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005E078: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x8005E07C: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8005E080: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x8005E084: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005E088: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x8005E08C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8005E090: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005E094: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
L_8005E098:
    // 0x8005E098: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E09C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005E0A0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E0A4: addiu       $t0, $t0, 0xE80
    ctx->r8 = ADD32(ctx->r8, 0XE80);
    // 0x8005E0A8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8005E0AC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E0B0: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005E0B4: nop

    // 0x8005E0B8: sb          $zero, 0x7E($t1)
    MEM_B(0X7E, ctx->r9) = 0;
    // 0x8005E0BC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E0C0: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005E0C4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8005E0C8: sb          $t8, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r24;
    // 0x8005E0CC: addiu       $t2, $zero, 0x12C
    ctx->r10 = ADD32(0, 0X12C);
    // 0x8005E0D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E0D4: sw          $t2, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r10;
    // 0x8005E0D8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005E0DC: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005E0E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005E0E4: bne         $t3, $at, L_8005E10C
    if (ctx->r11 != ctx->r1) {
        // 0x8005E0E8: nop

            goto L_8005E10C;
    }
    // 0x8005E0E8: nop

    // 0x8005E0EC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005E0F0: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x8005E0F4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005E0F8: bne         $t4, $at, L_8005E10C
    if (ctx->r12 != ctx->r1) {
        // 0x8005E0FC: nop

            goto L_8005E10C;
    }
    // 0x8005E0FC: nop

    // 0x8005E100: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x8005E104: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E108: sw          $t5, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r13;
L_8005E10C:
    // 0x8005E10C: jal         0x80048F80
    // 0x8005E110: nop

    func_80048F80(rdram, ctx);
        goto after_9;
    // 0x8005E110: nop

    after_9:
    // 0x8005E114: jal         0x80062640
    // 0x8005E118: nop

    func_80062640(rdram, ctx);
        goto after_10;
    // 0x8005E118: nop

    after_10:
    // 0x8005E11C: jal         0x800491A0
    // 0x8005E120: nop

    func_800491A0(rdram, ctx);
        goto after_11;
    // 0x8005E120: nop

    after_11:
    // 0x8005E124: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005E128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E12C: swc1        $f18, 0x125C($at)
    MEM_W(0X125C, ctx->r1) = ctx->f18.u32l;
    // 0x8005E130: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8005E134: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8005E138: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005E13C: bne         $t6, $at, L_8005E180
    if (ctx->r14 != ctx->r1) {
        // 0x8005E140: nop

            goto L_8005E180;
    }
    // 0x8005E140: nop

    // 0x8005E144: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005E148: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8005E14C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E150: bne         $t7, $at, L_8005E180
    if (ctx->r15 != ctx->r1) {
        // 0x8005E154: nop

            goto L_8005E180;
    }
    // 0x8005E154: nop

    // 0x8005E158: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8005E15C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005E160: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E164: swc1        $f4, 0x125C($at)
    MEM_W(0X125C, ctx->r1) = ctx->f4.u32l;
    // 0x8005E168: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005E16C: lw          $a1, 0x125C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X125C);
    // 0x8005E170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E174: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005E178: jal         0x800ACC34
    // 0x8005E17C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800ACC34(rdram, ctx);
        goto after_12;
    // 0x8005E17C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_12:
L_8005E180:
    // 0x8005E180: b           L_8005E188
    // 0x8005E184: nop

        goto L_8005E188;
    // 0x8005E184: nop

L_8005E188:
    // 0x8005E188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E18C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005E190: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005E194: jr          $ra
    // 0x8005E198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005E198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005E19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E19C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005E1A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005E1A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E1A8: sw          $zero, 0xE70($at)
    MEM_W(0XE70, ctx->r1) = 0;
    // 0x8005E1AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005E1B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8005E1B4:
    // 0x8005E1B4: jal         0x8005E908
    // 0x8005E1B8: nop

    func_8005E908(rdram, ctx);
        goto after_0;
    // 0x8005E1B8: nop

    after_0:
    // 0x8005E1BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005E1C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E1C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005E1C8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8005E1CC: sw          $v0, 0xE80($at)
    MEM_W(0XE80, ctx->r1) = ctx->r2;
    // 0x8005E1D0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005E1D4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E1D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005E1DC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8005E1E0: lw          $t1, 0xE80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE80);
    // 0x8005E1E4: nop

    // 0x8005E1E8: sb          $t9, 0x7E($t1)
    MEM_B(0X7E, ctx->r9) = ctx->r25;
    // 0x8005E1EC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005E1F0: nop

    // 0x8005E1F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005E1F8: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8005E1FC: bne         $at, $zero, L_8005E1B4
    if (ctx->r1 != 0) {
        // 0x8005E200: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8005E1B4;
    }
    // 0x8005E200: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8005E204: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005E208: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x8005E20C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005E210: bne         $t4, $at, L_8005E2EC
    if (ctx->r12 != ctx->r1) {
        // 0x8005E214: nop

            goto L_8005E2EC;
    }
    // 0x8005E214: nop

    // 0x8005E218: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8005E21C: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x8005E220: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8005E224: bne         $t5, $at, L_8005E2EC
    if (ctx->r13 != ctx->r1) {
        // 0x8005E228: nop

            goto L_8005E2EC;
    }
    // 0x8005E228: nop

    // 0x8005E22C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E230: addiu       $t7, $t7, 0x1280
    ctx->r15 = ADD32(ctx->r15, 0X1280);
    // 0x8005E234: addiu       $t6, $zero, 0x258
    ctx->r14 = ADD32(0, 0X258);
    // 0x8005E238: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8005E23C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E240: addiu       $t0, $t0, 0x1280
    ctx->r8 = ADD32(ctx->r8, 0X1280);
    // 0x8005E244: addiu       $t8, $zero, 0x258
    ctx->r24 = ADD32(0, 0X258);
    // 0x8005E248: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
    // 0x8005E24C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E250: addiu       $t1, $t1, 0x1280
    ctx->r9 = ADD32(ctx->r9, 0X1280);
    // 0x8005E254: addiu       $t9, $zero, 0x258
    ctx->r25 = ADD32(0, 0X258);
    // 0x8005E258: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
    // 0x8005E25C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005E260: addiu       $t3, $t3, 0x1280
    ctx->r11 = ADD32(ctx->r11, 0X1280);
    // 0x8005E264: addiu       $t2, $zero, 0x258
    ctx->r10 = ADD32(0, 0X258);
    // 0x8005E268: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
    // 0x8005E26C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005E270: addiu       $t5, $t5, 0x1280
    ctx->r13 = ADD32(ctx->r13, 0X1280);
    // 0x8005E274: addiu       $t4, $zero, 0x258
    ctx->r12 = ADD32(0, 0X258);
    // 0x8005E278: sh          $t4, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r12;
    // 0x8005E27C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E280: addiu       $t7, $t7, 0x1280
    ctx->r15 = ADD32(ctx->r15, 0X1280);
    // 0x8005E284: addiu       $t6, $zero, 0x258
    ctx->r14 = ADD32(0, 0X258);
    // 0x8005E288: sh          $t6, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r14;
    // 0x8005E28C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E290: addiu       $t0, $t0, 0x1290
    ctx->r8 = ADD32(ctx->r8, 0X1290);
    // 0x8005E294: addiu       $t8, $zero, 0x3E7
    ctx->r24 = ADD32(0, 0X3E7);
    // 0x8005E298: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8005E29C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E2A0: addiu       $t1, $t1, 0x1290
    ctx->r9 = ADD32(ctx->r9, 0X1290);
    // 0x8005E2A4: addiu       $t9, $zero, 0x384
    ctx->r25 = ADD32(0, 0X384);
    // 0x8005E2A8: sh          $t9, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r25;
    // 0x8005E2AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005E2B0: addiu       $t3, $t3, 0x1290
    ctx->r11 = ADD32(ctx->r11, 0X1290);
    // 0x8005E2B4: addiu       $t2, $zero, 0x5DC
    ctx->r10 = ADD32(0, 0X5DC);
    // 0x8005E2B8: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x8005E2BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005E2C0: addiu       $t5, $t5, 0x1290
    ctx->r13 = ADD32(ctx->r13, 0X1290);
    // 0x8005E2C4: addiu       $t4, $zero, 0x384
    ctx->r12 = ADD32(0, 0X384);
    // 0x8005E2C8: sh          $t4, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r12;
    // 0x8005E2CC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E2D0: addiu       $t7, $t7, 0x1290
    ctx->r15 = ADD32(ctx->r15, 0X1290);
    // 0x8005E2D4: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x8005E2D8: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x8005E2DC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E2E0: addiu       $t0, $t0, 0x1290
    ctx->r8 = ADD32(ctx->r8, 0X1290);
    // 0x8005E2E4: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x8005E2E8: sh          $t8, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r24;
L_8005E2EC:
    // 0x8005E2EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E2F0: addiu       $t9, $t9, 0xE80
    ctx->r25 = ADD32(ctx->r25, 0XE80);
    // 0x8005E2F4: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8005E2F8: nop

    // 0x8005E2FC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8005E300: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E304: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8005E308: nop

    // 0x8005E30C: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x8005E310: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005E314: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8005E318: nop

    // 0x8005E31C: swc1        $f6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f6.u32l;
    // 0x8005E320: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005E324: addiu       $t4, $zero, 0x3E
    ctx->r12 = ADD32(0, 0X3E);
    // 0x8005E328: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x8005E32C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005E330: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x8005E334: sh          $t6, 0x7C($t7)
    MEM_H(0X7C, ctx->r15) = ctx->r14;
    // 0x8005E338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005E33C: jal         0x8005EC54
    // 0x8005E340: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_8005EC54(rdram, ctx);
        goto after_1;
    // 0x8005E340: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_1:
    // 0x8005E344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005E348: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8005E34C: addiu       $a2, $zero, 0x19A
    ctx->r6 = ADD32(0, 0X19A);
    // 0x8005E350: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    // 0x8005E354: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E358: jal         0x8004F3E8
    // 0x8005E35C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004F3E8(rdram, ctx);
        goto after_2;
    // 0x8005E35C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8005E360: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005E364: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E368: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005E36C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005E370: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8005E374: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x8005E378: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8005E37C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005E380: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E384: addiu       $t9, $t9, 0xE80
    ctx->r25 = ADD32(ctx->r25, 0XE80);
    // 0x8005E388: lw          $t4, 0x1C($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X1C);
    // 0x8005E38C: nop

    // 0x8005E390: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8005E394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005E398: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005E39C: nop

    // 0x8005E3A0: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x8005E3A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005E3A8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3AC: nop

    // 0x8005E3B0: swc1        $f10, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f10.u32l;
    // 0x8005E3B4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8005E3B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005E3BC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3C0: nop

    // 0x8005E3C4: swc1        $f16, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f16.u32l;
    // 0x8005E3C8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3CC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005E3D0: lw          $t1, 0x38($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X38);
    // 0x8005E3D4: nop

    // 0x8005E3D8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8005E3DC: sw          $t2, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r10;
    // 0x8005E3E0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3E4: nop

    // 0x8005E3E8: lw          $t8, 0x38($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X38);
    // 0x8005E3EC: nop

    // 0x8005E3F0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8005E3F4: sw          $t9, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->r25;
    // 0x8005E3F8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005E3FC: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8005E400: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x8005E404: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005E408: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x8005E40C: sh          $t6, 0x7C($t7)
    MEM_H(0X7C, ctx->r15) = ctx->r14;
    // 0x8005E410: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005E414: jal         0x8005EC54
    // 0x8005E418: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_8005EC54(rdram, ctx);
        goto after_3;
    // 0x8005E418: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_3:
    // 0x8005E41C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005E420: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8005E424: addiu       $a2, $zero, 0x143
    ctx->r6 = ADD32(0, 0X143);
    // 0x8005E428: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8005E42C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E430: jal         0x8004F3E8
    // 0x8005E434: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004F3E8(rdram, ctx);
        goto after_4;
    // 0x8005E434: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x8005E438: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005E43C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E440: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8005E444: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8005E448: or          $t8, $t1, $zero
    ctx->r24 = ctx->r9 | 0;
    // 0x8005E44C: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x8005E450: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8005E454: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8005E458: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8005E45C: b           L_8005E464
    // 0x8005E460: nop

        goto L_8005E464;
    // 0x8005E460: nop

L_8005E464:
    // 0x8005E464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E468: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005E46C: jr          $ra
    // 0x8005E470: nop

    return;
    // 0x8005E470: nop

;}
RECOMP_FUNC void func_8005E474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E474: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005E478: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E47C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E480: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005E484: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8005E488: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_8005E48C:
    // 0x8005E48C: jal         0x8005E908
    // 0x8005E490: nop

    func_8005E908(rdram, ctx);
        goto after_0;
    // 0x8005E490: nop

    after_0:
    // 0x8005E494: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E49C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005E4A0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8005E4A4: sw          $v0, 0xE80($at)
    MEM_W(0XE80, ctx->r1) = ctx->r2;
    // 0x8005E4A8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E4AC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005E4B0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005E4B4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005E4B8: lw          $t2, 0xE80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE80);
    // 0x8005E4BC: addiu       $t0, $t9, -0x8
    ctx->r8 = ADD32(ctx->r25, -0X8);
    // 0x8005E4C0: sb          $t0, 0x7E($t2)
    MEM_B(0X7E, ctx->r10) = ctx->r8;
    // 0x8005E4C4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E4C8: nop

    // 0x8005E4CC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005E4D0: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8005E4D4: bne         $at, $zero, L_8005E48C
    if (ctx->r1 != 0) {
        // 0x8005E4D8: sw          $t4, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r12;
            goto L_8005E48C;
    }
    // 0x8005E4D8: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8005E4DC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005E4E0: addiu       $t5, $t5, 0x2A9C
    ctx->r13 = ADD32(ctx->r13, 0X2A9C);
    // 0x8005E4E4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8005E4E8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8005E4EC: nop

    // 0x8005E4F0: beq         $t6, $zero, L_8005E8EC
    if (ctx->r14 == 0) {
        // 0x8005E4F4: nop

            goto L_8005E8EC;
    }
    // 0x8005E4F4: nop

    // 0x8005E4F8: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x8005E4FC: nop

    // 0x8005E500: beq         $t7, $zero, L_8005E8EC
    if (ctx->r15 == 0) {
        // 0x8005E504: nop

            goto L_8005E8EC;
    }
    // 0x8005E504: nop

L_8005E508:
    // 0x8005E508: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E50C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8005E510: addiu       $t1, $t1, 0x2A9C
    ctx->r9 = ADD32(ctx->r9, 0X2A9C);
    // 0x8005E514: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005E518: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x8005E51C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005E520: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005E524: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8005E528: nop

    // 0x8005E52C: bne         $t2, $t3, L_8005E8B0
    if (ctx->r10 != ctx->r11) {
        // 0x8005E530: nop

            goto L_8005E8B0;
    }
    // 0x8005E530: nop

    // 0x8005E534: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8005E538: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8005E53C: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x8005E540: nop

    // 0x8005E544: bne         $t4, $t6, L_8005E8B0
    if (ctx->r12 != ctx->r14) {
        // 0x8005E548: nop

            goto L_8005E8B0;
    }
    // 0x8005E548: nop

    // 0x8005E54C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8005E550: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E554: addiu       $t7, $t7, 0xE80
    ctx->r15 = ADD32(ctx->r15, 0XE80);
    // 0x8005E558: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8005E55C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8005E560: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005E564: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x8005E568: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E56C: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8005E570: bne         $t0, $zero, L_8005E580
    if (ctx->r8 != 0) {
        // 0x8005E574: and         $t1, $t3, $at
        ctx->r9 = ctx->r11 & ctx->r1;
            goto L_8005E580;
    }
    // 0x8005E574: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8005E578: beq         $t1, $zero, L_8005E5C8
    if (ctx->r9 == 0) {
        // 0x8005E57C: nop

            goto L_8005E5C8;
    }
    // 0x8005E57C: nop

L_8005E580:
    // 0x8005E580: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E584: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005E588: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8005E58C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8005E590: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8005E594: lw          $t5, 0xE80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE80);
    // 0x8005E598: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8005E59C: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8005E5A0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005E5A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E5A8: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8005E5AC: bne         $t2, $zero, L_8005E5BC
    if (ctx->r10 != 0) {
        // 0x8005E5B0: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_8005E5BC;
    }
    // 0x8005E5B0: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x8005E5B4: beq         $t3, $zero, L_8005E5C8
    if (ctx->r11 == 0) {
        // 0x8005E5B8: nop

            goto L_8005E5C8;
    }
    // 0x8005E5B8: nop

L_8005E5BC:
    // 0x8005E5BC: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8005E5C0: bne         $at, $zero, L_8005E580
    if (ctx->r1 != 0) {
        // 0x8005E5C4: nop

            goto L_8005E580;
    }
    // 0x8005E5C4: nop

L_8005E5C8:
    // 0x8005E5C8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005E5CC: nop

    // 0x8005E5D0: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x8005E5D4: beq         $at, $zero, L_8005E8B0
    if (ctx->r1 == 0) {
        // 0x8005E5D8: nop

            goto L_8005E8B0;
    }
    // 0x8005E5D8: nop

    // 0x8005E5DC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E5E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005E5E4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8005E5E8: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8005E5EC: lh          $t6, 0x2AA6($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2AA6);
    // 0x8005E5F0: nop

    // 0x8005E5F4: beq         $t6, $zero, L_8005E62C
    if (ctx->r14 == 0) {
        // 0x8005E5F8: nop

            goto L_8005E62C;
    }
    // 0x8005E5F8: nop

    // 0x8005E5FC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005E600: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E604: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8005E608: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005E60C: lw          $t9, 0xE80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE80);
    // 0x8005E610: nop

    // 0x8005E614: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8005E618: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8005E61C: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x8005E620: ori         $t5, $t3, 0x8
    ctx->r13 = ctx->r11 | 0X8;
    // 0x8005E624: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x8005E628: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
L_8005E62C:
    // 0x8005E62C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005E630: nop

    // 0x8005E634: bgez        $t7, L_8005E648
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005E638: andi        $t0, $t7, 0x1
        ctx->r8 = ctx->r15 & 0X1;
            goto L_8005E648;
    }
    // 0x8005E638: andi        $t0, $t7, 0x1
    ctx->r8 = ctx->r15 & 0X1;
    // 0x8005E63C: beq         $t0, $zero, L_8005E648
    if (ctx->r8 == 0) {
        // 0x8005E640: nop

            goto L_8005E648;
    }
    // 0x8005E640: nop

    // 0x8005E644: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_8005E648:
    // 0x8005E648: beq         $t0, $zero, L_8005E670
    if (ctx->r8 == 0) {
        // 0x8005E64C: nop

            goto L_8005E670;
    }
    // 0x8005E64C: nop

    // 0x8005E650: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E654: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8005E658: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005E65C: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8005E660: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005E664: lw          $t6, 0xE80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE80);
    // 0x8005E668: b           L_8005E698
    // 0x8005E66C: swc1        $f6, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f6.u32l;
        goto L_8005E698;
    // 0x8005E66C: swc1        $f6, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f6.u32l;
L_8005E670:
    // 0x8005E670: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8005E674: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x8005E678: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8005E67C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005E680: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005E684: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005E688: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8005E68C: lw          $t4, 0xE80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE80);
    // 0x8005E690: nop

    // 0x8005E694: swc1        $f10, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f10.u32l;
L_8005E698:
    // 0x8005E698: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005E69C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E6A0: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8005E6A4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8005E6A8: lw          $t0, 0xE80($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE80);
    // 0x8005E6AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E6B0: nop

    // 0x8005E6B4: swc1        $f16, 0xA0($t0)
    MEM_W(0XA0, ctx->r8) = ctx->f16.u32l;
    // 0x8005E6B8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005E6BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005E6C0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8005E6C4: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8005E6C8: lw          $t6, 0xE80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE80);
    // 0x8005E6CC: nop

    // 0x8005E6D0: sw          $zero, 0x88($t6)
    MEM_W(0X88, ctx->r14) = 0;
    // 0x8005E6D4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E6D8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8005E6DC: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x8005E6E0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005E6E4: lh          $t3, 0x2AA0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2AA0);
    // 0x8005E6E8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005E6EC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8005E6F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E6F4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005E6F8: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005E6FC: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8005E700: lw          $t9, 0xE80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE80);
    // 0x8005E704: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E708: swc1        $f20, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f20.u32l;
    // 0x8005E70C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005E710: nop

    // 0x8005E714: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8005E718: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8005E71C: lw          $t1, 0xE80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE80);
    // 0x8005E720: nop

    // 0x8005E724: swc1        $f20, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f20.u32l;
    // 0x8005E728: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E72C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8005E730: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8005E734: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8005E738: lh          $t2, 0x2AA2($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2AA2);
    // 0x8005E73C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005E740: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8005E744: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005E748: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005E74C: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005E750: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005E754: lw          $t5, 0xE80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE80);
    // 0x8005E758: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E75C: swc1        $f20, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f20.u32l;
    // 0x8005E760: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E764: nop

    // 0x8005E768: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005E76C: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8005E770: lw          $t7, 0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE80);
    // 0x8005E774: nop

    // 0x8005E778: swc1        $f20, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f20.u32l;
    // 0x8005E77C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005E780: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E784: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005E788: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005E78C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8005E790: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x8005E794: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x8005E798: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005E79C: lw          $a0, 0xE80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE80);
    // 0x8005E7A0: lh          $a1, 0x2AA4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2AA4);
    // 0x8005E7A4: jal         0x8005EC54
    // 0x8005E7A8: nop

    func_8005EC54(rdram, ctx);
        goto after_1;
    // 0x8005E7A8: nop

    after_1:
    // 0x8005E7AC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E7B0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E7B4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005E7B8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E7BC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8005E7C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005E7C4: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8005E7C8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005E7CC: lh          $t5, 0x2AA4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2AA4);
    // 0x8005E7D0: lw          $t7, 0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE80);
    // 0x8005E7D4: nop

    // 0x8005E7D8: sh          $t5, 0x7C($t7)
    MEM_H(0X7C, ctx->r15) = ctx->r13;
    // 0x8005E7DC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E7E0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005E7E4: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x8005E7E8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8005E7EC: lh          $t8, 0x2AA4($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2AA4);
    // 0x8005E7F0: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8005E7F4: bne         $t8, $at, L_8005E81C
    if (ctx->r24 != ctx->r1) {
        // 0x8005E7F8: nop

            goto L_8005E81C;
    }
    // 0x8005E7F8: nop

    // 0x8005E7FC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005E800: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E804: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005E808: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8005E80C: lw          $t9, 0xE80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE80);
    // 0x8005E810: addiu       $t2, $zero, 0x3F
    ctx->r10 = ADD32(0, 0X3F);
    // 0x8005E814: b           L_8005E838
    // 0x8005E818: sw          $t2, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r10;
        goto L_8005E838;
    // 0x8005E818: sw          $t2, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r10;
L_8005E81C:
    // 0x8005E81C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005E820: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E824: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8005E828: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8005E82C: lw          $t1, 0xE80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE80);
    // 0x8005E830: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8005E834: sw          $t0, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r8;
L_8005E838:
    // 0x8005E838: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005E83C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005E840: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8005E844: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E848: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x8005E84C: lw          $t3, 0xE80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE80);
    // 0x8005E850: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005E854: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8005E858: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x8005E85C: lw          $a3, 0x44($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X44);
    // 0x8005E860: lh          $a1, 0x2AA4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2AA4);
    // 0x8005E864: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005E868: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E86C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8005E870: jal         0x8004F3E8
    // 0x8005E874: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_8004F3E8(rdram, ctx);
        goto after_2;
    // 0x8005E874: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_2:
    // 0x8005E878: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E87C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E880: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005E884: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005E888: lw          $t7, 0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE80);
    // 0x8005E88C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E890: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8005E894: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8005E898: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x8005E89C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005E8A0: or          $t6, $t0, $zero
    ctx->r14 = ctx->r8 | 0;
    // 0x8005E8A4: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x8005E8A8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8005E8AC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_8005E8B0:
    // 0x8005E8B0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E8B4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8005E8B8: addiu       $t2, $t4, 0x6
    ctx->r10 = ADD32(ctx->r12, 0X6);
    // 0x8005E8BC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8005E8C0: addiu       $t9, $t9, 0x2A9C
    ctx->r25 = ADD32(ctx->r25, 0X2A9C);
    // 0x8005E8C4: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x8005E8C8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8005E8CC: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x8005E8D0: nop

    // 0x8005E8D4: beq         $t0, $zero, L_8005E8EC
    if (ctx->r8 == 0) {
        // 0x8005E8D8: nop

            goto L_8005E8EC;
    }
    // 0x8005E8D8: nop

    // 0x8005E8DC: lh          $t1, 0x2($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X2);
    // 0x8005E8E0: nop

    // 0x8005E8E4: bne         $t1, $zero, L_8005E508
    if (ctx->r9 != 0) {
        // 0x8005E8E8: nop

            goto L_8005E508;
    }
    // 0x8005E8E8: nop

L_8005E8EC:
    // 0x8005E8EC: b           L_8005E8F4
    // 0x8005E8F0: nop

        goto L_8005E8F4;
    // 0x8005E8F0: nop

L_8005E8F4:
    // 0x8005E8F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005E8F8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005E8FC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005E900: jr          $ra
    // 0x8005E904: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005E904: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005E908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E908: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005E90C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E910: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8005E914: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8005E918: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E91C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8005E920: jal         0x800BC6EC
    // 0x8005E924: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8005E924: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x8005E928: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005E92C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E930: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005E934: nop

    // 0x8005E938: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    // 0x8005E93C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005E940: nop

    // 0x8005E944: lwc1        $f20, 0x20($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8005E948: nop

    // 0x8005E94C: swc1        $f20, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f20.u32l;
    // 0x8005E950: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005E954: nop

    // 0x8005E958: swc1        $f20, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f20.u32l;
    // 0x8005E95C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005E964: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005E968: nop

    // 0x8005E96C: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x8005E970: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005E974: nop

    // 0x8005E978: lwc1        $f8, 0x1C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8005E97C: nop

    // 0x8005E980: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x8005E984: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8005E988: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8005E98C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005E990: nop

    // 0x8005E994: swc1        $f10, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f10.u32l;
    // 0x8005E998: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E99C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9A0: nop

    // 0x8005E9A4: swc1        $f16, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->f16.u32l;
    // 0x8005E9A8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9AC: nop

    // 0x8005E9B0: lwc1        $f22, 0x30($t3)
    ctx->f22.u32l = MEM_W(ctx->r11, 0X30);
    // 0x8005E9B4: nop

    // 0x8005E9B8: swc1        $f22, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f22.u32l;
    // 0x8005E9BC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9C0: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8005E9C4: swc1        $f20, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f20.u32l;
    // 0x8005E9C8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9CC: nop

    // 0x8005E9D0: swc1        $f20, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f20.u32l;
    // 0x8005E9D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005E9D8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9DC: nop

    // 0x8005E9E0: swc1        $f18, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f18.u32l;
    // 0x8005E9E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E9E8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9EC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8005E9F0: swc1        $f4, 0xA0($t7)
    MEM_W(0XA0, ctx->r15) = ctx->f4.u32l;
    // 0x8005E9F4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9F8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8005E9FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005EA00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005EA04: lwc1        $f6, 0xA0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XA0);
    // 0x8005EA08: nop

    // 0x8005EA0C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005EA10: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8005EA14: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8005EA18: sw          $t0, 0x9C($t8)
    MEM_W(0X9C, ctx->r24) = ctx->r8;
    // 0x8005EA1C: nop

    // 0x8005EA20: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA24: nop

    // 0x8005EA28: sw          $zero, 0xB8($t1)
    MEM_W(0XB8, ctx->r9) = 0;
    // 0x8005EA2C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005EA30: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x8005EA34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005EA38: bne         $t2, $at, L_8005EA64
    if (ctx->r10 != ctx->r1) {
        // 0x8005EA3C: nop

            goto L_8005EA64;
    }
    // 0x8005EA3C: nop

    // 0x8005EA40: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005EA44: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8005EA48: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005EA4C: bne         $t3, $at, L_8005EA64
    if (ctx->r11 != ctx->r1) {
        // 0x8005EA50: nop

            goto L_8005EA64;
    }
    // 0x8005EA50: nop

    // 0x8005EA54: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA58: addiu       $t4, $zero, 0x4C
    ctx->r12 = ADD32(0, 0X4C);
    // 0x8005EA5C: b           L_8005EA70
    // 0x8005EA60: sw          $t4, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r12;
        goto L_8005EA70;
    // 0x8005EA60: sw          $t4, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r12;
L_8005EA64:
    // 0x8005EA64: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA68: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x8005EA6C: sw          $t6, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r14;
L_8005EA70:
    // 0x8005EA70: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA74: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8005EA78: sw          $t9, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r25;
    // 0x8005EA7C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA80: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8005EA84: sw          $t8, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r24;
    // 0x8005EA88: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA8C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8005EA90: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8005EA94: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8005EA98: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8005EA9C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005EAA0: nop

    // 0x8005EAA4: sh          $zero, 0xAC($t5)
    MEM_H(0XAC, ctx->r13) = 0;
    // 0x8005EAA8: jal         0x800BC6EC
    // 0x8005EAAC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8005EAAC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_1:
    // 0x8005EAB0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005EAB4: nop

    // 0x8005EAB8: sw          $v0, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r2;
    // 0x8005EABC: jal         0x800BC6EC
    // 0x8005EAC0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8005EAC0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_2:
    // 0x8005EAC4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005EAC8: nop

    // 0x8005EACC: sw          $v0, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r2;
    // 0x8005EAD0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8005EAD4: b           L_8005EAE4
    // 0x8005EAD8: nop

        goto L_8005EAE4;
    // 0x8005EAD8: nop

    // 0x8005EADC: b           L_8005EAE4
    // 0x8005EAE0: nop

        goto L_8005EAE4;
    // 0x8005EAE0: nop

L_8005EAE4:
    // 0x8005EAE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005EAE8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8005EAEC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005EAF0: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005EAF4: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005EAF8: jr          $ra
    // 0x8005EAFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005EAFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005EB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EB00: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005EB04: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x8005EB08: beq         $at, $zero, L_8005EC3C
    if (ctx->r1 == 0) {
        // 0x8005EB0C: nop

            goto L_8005EC3C;
    }
    // 0x8005EB0C: nop

L_8005EB10:
    // 0x8005EB10: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8005EB14: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005EB18: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005EB1C: lw          $t7, 0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE80);
    // 0x8005EB20: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005EB24: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8005EB28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005EB2C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005EB30: bne         $t0, $zero, L_8005EC2C
    if (ctx->r8 != 0) {
        // 0x8005EB34: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8005EC2C;
    }
    // 0x8005EB34: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005EB38: bne         $t1, $zero, L_8005EC2C
    if (ctx->r9 != 0) {
        // 0x8005EB3C: nop

            goto L_8005EC2C;
    }
    // 0x8005EB3C: nop

    // 0x8005EB40: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8005EB44: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005EB48: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005EB4C: lw          $t3, 0xE80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE80);
    // 0x8005EB50: nop

    // 0x8005EB54: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8005EB58: lwc1        $f4, 0xCC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8005EB5C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8005EB60: nop

    // 0x8005EB64: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x8005EB68: lwc1        $f6, 0xD0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XD0);
    // 0x8005EB6C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005EB70: nop

    // 0x8005EB74: swc1        $f6, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f6.u32l;
    // 0x8005EB78: lwc1        $f8, 0xD4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XD4);
    // 0x8005EB7C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005EB80: nop

    // 0x8005EB84: swc1        $f8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f8.u32l;
    // 0x8005EB88: lwc1        $f10, 0xF0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XF0);
    // 0x8005EB8C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005EB90: nop

    // 0x8005EB94: swc1        $f10, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f10.u32l;
    // 0x8005EB98: lwc1        $f16, 0xF4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x8005EB9C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBA0: nop

    // 0x8005EBA4: swc1        $f16, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f16.u32l;
    // 0x8005EBA8: lwc1        $f18, 0xF8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x8005EBAC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBB0: nop

    // 0x8005EBB4: swc1        $f18, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f18.u32l;
    // 0x8005EBB8: lw          $t0, 0xC0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC0);
    // 0x8005EBBC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBC0: nop

    // 0x8005EBC4: sw          $t0, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->r8;
    // 0x8005EBC8: lh          $t2, 0x11E($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X11E);
    // 0x8005EBCC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBD0: nop

    // 0x8005EBD4: sw          $t2, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->r10;
    // 0x8005EBD8: lw          $t4, 0xC8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC8);
    // 0x8005EBDC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBE0: nop

    // 0x8005EBE4: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x8005EBE8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBEC: nop

    // 0x8005EBF0: sw          $a0, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r4;
    // 0x8005EBF4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBF8: nop

    // 0x8005EBFC: sw          $a1, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r5;
    // 0x8005EC00: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005EC04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005EC08: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005EC0C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005EC10: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8005EC14: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x8005EC18: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8005EC1C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8005EC20: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8005EC24: b           L_8005EC4C
    // 0x8005EC28: nop

        goto L_8005EC4C;
    // 0x8005EC28: nop

L_8005EC2C:
    // 0x8005EC2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005EC30: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x8005EC34: bne         $at, $zero, L_8005EB10
    if (ctx->r1 != 0) {
        // 0x8005EC38: nop

            goto L_8005EB10;
    }
    // 0x8005EC38: nop

L_8005EC3C:
    // 0x8005EC3C: b           L_8005EC4C
    // 0x8005EC40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005EC4C;
    // 0x8005EC40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005EC44: b           L_8005EC4C
    // 0x8005EC48: nop

        goto L_8005EC4C;
    // 0x8005EC48: nop

L_8005EC4C:
    // 0x8005EC4C: jr          $ra
    // 0x8005EC50: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005EC50: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005EC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005EC58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005EC5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005EC60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005EC64: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x8005EC68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005EC6C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005EC70: lbu         $a0, -0x6230($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6230);
    // 0x8005EC74: nop

    // 0x8005EC78: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8005EC7C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8005EC80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EC84: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8005EC88: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005EC8C: jal         0x800BC6EC
    // 0x8005EC90: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8005EC90: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x8005EC94: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005EC98: nop

    // 0x8005EC9C: sw          $v0, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->r2;
    // 0x8005ECA0: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8005ECA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005ECA8: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8005ECAC: lbu         $a0, -0x6230($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6230);
    // 0x8005ECB0: nop

    // 0x8005ECB4: sll         $t0, $a0, 6
    ctx->r8 = S32(ctx->r4 << 6);
    // 0x8005ECB8: jal         0x800BC6EC
    // 0x8005ECBC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8005ECBC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x8005ECC0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005ECC4: nop

    // 0x8005ECC8: sw          $v0, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->r2;
    // 0x8005ECCC: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8005ECD0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8005ECD4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005ECD8: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x8005ECDC: lbu         $a2, -0x6230($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X6230);
    // 0x8005ECE0: addiu       $a0, $t2, 0x4C
    ctx->r4 = ADD32(ctx->r10, 0X4C);
    // 0x8005ECE4: jal         0x800B1B3C
    // 0x8005ECE8: addiu       $a1, $t2, 0x50
    ctx->r5 = ADD32(ctx->r10, 0X50);
    func_800B1B3C(rdram, ctx);
        goto after_2;
    // 0x8005ECE8: addiu       $a1, $t2, 0x50
    ctx->r5 = ADD32(ctx->r10, 0X50);
    after_2:
    // 0x8005ECEC: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8005ECF0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005ECF4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005ECF8: lbu         $t5, -0x6230($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X6230);
    // 0x8005ECFC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005ED00: blez        $t5, L_8005EF0C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005ED04: nop

            goto L_8005EF0C;
    }
    // 0x8005ED04: nop

L_8005ED08:
    // 0x8005ED08: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED0C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005ED10: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005ED14: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005ED18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005ED1C: lw          $t7, 0x4C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4C);
    // 0x8005ED20: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005ED24: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8005ED28: jal         0x80099E2C
    // 0x8005ED2C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x8005ED2C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_3:
    // 0x8005ED30: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED34: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005ED38: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005ED3C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005ED40: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8005ED44: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x8005ED48: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005ED4C: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8005ED50: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8005ED54: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005ED58: swc1        $f4, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f4.u32l;
    // 0x8005ED5C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED60: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005ED64: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8005ED68: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8005ED6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005ED70: lw          $t6, 0x4C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4C);
    // 0x8005ED74: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8005ED78: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x8005ED7C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005ED80: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8005ED84: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8005ED88: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005ED8C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005ED90: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8005ED94: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8005ED98: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8005ED9C: lw          $t2, 0x4C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4C);
    // 0x8005EDA0: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8005EDA4: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8005EDA8: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8005EDAC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8005EDB0: swc1        $f8, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f8.u32l;
    // 0x8005EDB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EDB8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005EDBC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005EDC0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005EDC4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EDC8: lw          $t8, 0x4C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4C);
    // 0x8005EDCC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005EDD0: lwc1        $f10, 0x20($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8005EDD4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005EDD8: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8005EDDC: swc1        $f10, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f10.u32l;
    // 0x8005EDE0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EDE4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005EDE8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005EDEC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005EDF0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8005EDF4: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x8005EDF8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005EDFC: lwc1        $f16, 0x18($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8005EE00: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8005EE04: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005EE08: swc1        $f16, 0xF4($t4)
    MEM_W(0XF4, ctx->r12) = ctx->f16.u32l;
    // 0x8005EE0C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE10: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE14: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8005EE18: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8005EE1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EE20: lw          $t6, 0x4C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4C);
    // 0x8005EE24: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8005EE28: lwc1        $f18, 0x1C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8005EE2C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005EE30: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8005EE34: swc1        $f18, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f18.u32l;
    // 0x8005EE38: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE3C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE40: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005EE44: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8005EE48: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8005EE4C: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x8005EE50: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8005EE54: lw          $t2, 0x40($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X40);
    // 0x8005EE58: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8005EE5C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8005EE60: sh          $t2, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r10;
    // 0x8005EE64: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE68: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE6C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005EE70: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8005EE74: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8005EE78: lw          $t7, 0x4C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4C);
    // 0x8005EE7C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8005EE80: lw          $t6, 0x3C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X3C);
    // 0x8005EE84: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8005EE88: addu        $t3, $t7, $t0
    ctx->r11 = ADD32(ctx->r15, ctx->r8);
    // 0x8005EE8C: sw          $t6, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r14;
    // 0x8005EE90: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EE94: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE98: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8005EE9C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8005EEA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005EEA4: lw          $t2, 0x4C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4C);
    // 0x8005EEA8: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8005EEAC: lw          $t4, 0x38($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X38);
    // 0x8005EEB0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8005EEB4: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x8005EEB8: sw          $t4, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r12;
    // 0x8005EEBC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EEC0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005EEC4: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8005EEC8: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x8005EECC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8005EED0: lw          $t6, 0x4C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4C);
    // 0x8005EED4: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x8005EED8: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x8005EEDC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8005EEE0: addu        $t5, $t6, $t1
    ctx->r13 = ADD32(ctx->r14, ctx->r9);
    // 0x8005EEE4: sh          $t7, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r15;
    // 0x8005EEE8: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8005EEEC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8005EEF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EEF4: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8005EEF8: lbu         $t9, -0x6230($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6230);
    // 0x8005EEFC: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8005EF00: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8005EF04: bne         $at, $zero, L_8005ED08
    if (ctx->r1 != 0) {
        // 0x8005EF08: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_8005ED08;
    }
    // 0x8005EF08: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_8005EF0C:
    // 0x8005EF0C: b           L_8005EF14
    // 0x8005EF10: nop

        goto L_8005EF14;
    // 0x8005EF10: nop

L_8005EF14:
    // 0x8005EF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005EF18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005EF1C: jr          $ra
    // 0x8005EF20: nop

    return;
    // 0x8005EF20: nop

;}
RECOMP_FUNC void func_8005EF24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EF24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005EF28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005EF2C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005EF30: addiu       $t6, $t6, 0x28E4
    ctx->r14 = ADD32(ctx->r14, 0X28E4);
    // 0x8005EF34: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8005EF38: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005EF3C: nop

    // 0x8005EF40: beq         $t7, $zero, L_8005EFFC
    if (ctx->r15 == 0) {
        // 0x8005EF44: nop

            goto L_8005EFFC;
    }
    // 0x8005EF44: nop

L_8005EF48:
    // 0x8005EF48: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005EF4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8005EF50: addiu       $t0, $t0, 0x28E4
    ctx->r8 = ADD32(ctx->r8, 0X28E4);
    // 0x8005EF54: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005EF58: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8005EF5C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005EF60: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005EF64: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8005EF68: nop

    // 0x8005EF6C: bne         $t2, $t3, L_8005EFD8
    if (ctx->r10 != ctx->r11) {
        // 0x8005EF70: nop

            goto L_8005EFD8;
    }
    // 0x8005EF70: nop

    // 0x8005EF74: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8005EF78: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x8005EF7C: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x8005EF80: nop

    // 0x8005EF84: bne         $t4, $t5, L_8005EFD8
    if (ctx->r12 != ctx->r13) {
        // 0x8005EF88: nop

            goto L_8005EFD8;
    }
    // 0x8005EF88: nop

    // 0x8005EF8C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005EF90: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005EF94: addiu       $t8, $t8, 0x28E4
    ctx->r24 = ADD32(ctx->r24, 0X28E4);
    // 0x8005EF98: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8005EF9C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005EFA0: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x8005EFA4: lh          $t2, 0x8($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X8);
    // 0x8005EFA8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8005EFAC: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8005EFB0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005EFB4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8005EFB8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8005EFBC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005EFC0: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x8005EFC4: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x8005EFC8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8005EFCC: lh          $a2, 0x4($t9)
    ctx->r6 = MEM_H(ctx->r25, 0X4);
    // 0x8005EFD0: jal         0x800298A4
    // 0x8005EFD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800298A4(rdram, ctx);
        goto after_0;
    // 0x8005EFD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
L_8005EFD8:
    // 0x8005EFD8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005EFDC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005EFE0: addiu       $t1, $t3, 0x5
    ctx->r9 = ADD32(ctx->r11, 0X5);
    // 0x8005EFE4: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8005EFE8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005EFEC: lh          $t5, 0x28E4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X28E4);
    // 0x8005EFF0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8005EFF4: bne         $t5, $zero, L_8005EF48
    if (ctx->r13 != 0) {
        // 0x8005EFF8: nop

            goto L_8005EF48;
    }
    // 0x8005EFF8: nop

L_8005EFFC:
    // 0x8005EFFC: b           L_8005F00C
    // 0x8005F000: nop

        goto L_8005F00C;
    // 0x8005F000: nop

    // 0x8005F004: b           L_8005F00C
    // 0x8005F008: nop

        goto L_8005F00C;
    // 0x8005F008: nop

L_8005F00C:
    // 0x8005F00C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005F014: jr          $ra
    // 0x8005F018: nop

    return;
    // 0x8005F018: nop

;}
RECOMP_FUNC void func_8005F01C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F01C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005F020: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F024:
    // 0x8005F024: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005F028: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005F02C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8005F030: sb          $zero, 0x680($at)
    MEM_B(0X680, ctx->r1) = 0;
    // 0x8005F034: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005F038: nop

    // 0x8005F03C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8005F040: slti        $at, $t8, 0x40
    ctx->r1 = SIGNED(ctx->r24) < 0X40 ? 1 : 0;
    // 0x8005F044: bne         $at, $zero, L_8005F024
    if (ctx->r1 != 0) {
        // 0x8005F048: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_8005F024;
    }
    // 0x8005F048: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8005F04C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8005F050: sb          $zero, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = 0;
    // 0x8005F054: b           L_8005F05C
    // 0x8005F058: nop

        goto L_8005F05C;
    // 0x8005F058: nop

L_8005F05C:
    // 0x8005F05C: jr          $ra
    // 0x8005F060: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005F060: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005F064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F064: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005F068: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8005F06C: bgez        $a0, L_8005F07C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005F070: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8005F07C;
    }
    // 0x8005F070: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8005F074: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8005F078: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8005F07C:
    // 0x8005F07C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8005F080: bgez        $a0, L_8005F094
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005F084: andi        $t7, $a0, 0x7
        ctx->r15 = ctx->r4 & 0X7;
            goto L_8005F094;
    }
    // 0x8005F084: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x8005F088: beq         $t7, $zero, L_8005F094
    if (ctx->r15 == 0) {
        // 0x8005F08C: nop

            goto L_8005F094;
    }
    // 0x8005F08C: nop

    // 0x8005F090: addiu       $t7, $t7, -0x8
    ctx->r15 = ADD32(ctx->r15, -0X8);
L_8005F094:
    // 0x8005F094: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8005F098: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005F09C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005F0A0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005F0A4: lbu         $t9, 0x680($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X680);
    // 0x8005F0A8: nop

    // 0x8005F0AC: srav        $t0, $t9, $a0
    ctx->r8 = S32(SIGNED(ctx->r25) >> (ctx->r4 & 31));
    // 0x8005F0B0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8005F0B4: beq         $t1, $zero, L_8005F0C4
    if (ctx->r9 == 0) {
        // 0x8005F0B8: nop

            goto L_8005F0C4;
    }
    // 0x8005F0B8: nop

    // 0x8005F0BC: b           L_8005F0D4
    // 0x8005F0C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005F0D4;
    // 0x8005F0C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005F0C4:
    // 0x8005F0C4: b           L_8005F0D4
    // 0x8005F0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005F0D4;
    // 0x8005F0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F0CC: b           L_8005F0D4
    // 0x8005F0D0: nop

        goto L_8005F0D4;
    // 0x8005F0D0: nop

L_8005F0D4:
    // 0x8005F0D4: jr          $ra
    // 0x8005F0D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005F0D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005F0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F0DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F0E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005F0E8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005F0EC: nop

    // 0x8005F0F0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8005F0F4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005F0F8: nop

    // 0x8005F0FC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8005F100: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8005F104: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8005F108: nop

    // 0x8005F10C: bgez        $t9, L_8005F11C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005F110: sra         $t0, $t9, 3
        ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
            goto L_8005F11C;
    }
    // 0x8005F110: sra         $t0, $t9, 3
    ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8005F114: addiu       $at, $t9, 0x7
    ctx->r1 = ADD32(ctx->r25, 0X7);
    // 0x8005F118: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_8005F11C:
    // 0x8005F11C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8005F120: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005F124: nop

    // 0x8005F128: bgez        $t1, L_8005F13C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005F12C: andi        $t2, $t1, 0x7
        ctx->r10 = ctx->r9 & 0X7;
            goto L_8005F13C;
    }
    // 0x8005F12C: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x8005F130: beq         $t2, $zero, L_8005F13C
    if (ctx->r10 == 0) {
        // 0x8005F134: nop

            goto L_8005F13C;
    }
    // 0x8005F134: nop

    // 0x8005F138: addiu       $t2, $t2, -0x8
    ctx->r10 = ADD32(ctx->r10, -0X8);
L_8005F13C:
    // 0x8005F13C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8005F140: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F144: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005F148: addiu       $t4, $t4, 0x680
    ctx->r12 = ADD32(ctx->r12, 0X680);
    // 0x8005F14C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005F150: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8005F154: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8005F158: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005F15C: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x8005F160: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x8005F164: sb          $t0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r8;
    // 0x8005F168: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005F16C: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x8005F170: beq         $t1, $at, L_8005F190
    if (ctx->r9 == ctx->r1) {
        // 0x8005F174: nop

            goto L_8005F190;
    }
    // 0x8005F174: nop

    // 0x8005F178: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8005F17C: beq         $t1, $at, L_8005F190
    if (ctx->r9 == ctx->r1) {
        // 0x8005F180: nop

            goto L_8005F190;
    }
    // 0x8005F180: nop

    // 0x8005F184: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x8005F188: bne         $t1, $at, L_8005F198
    if (ctx->r9 != ctx->r1) {
        // 0x8005F18C: nop

            goto L_8005F198;
    }
    // 0x8005F18C: nop

L_8005F190:
    // 0x8005F190: b           L_8005F258
    // 0x8005F194: nop

        goto L_8005F258;
    // 0x8005F194: nop

L_8005F198:
    // 0x8005F198: jal         0x8005F31C
    // 0x8005F19C: nop

    func_8005F31C(rdram, ctx);
        goto after_0;
    // 0x8005F19C: nop

    after_0:
    // 0x8005F1A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8005F1A4: sb          $v0, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = ctx->r2;
    // 0x8005F1A8: jal         0x8005F064
    // 0x8005F1AC: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x8005F1AC: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    after_1:
    // 0x8005F1B0: bne         $v0, $zero, L_8005F1E0
    if (ctx->r2 != 0) {
        // 0x8005F1B4: nop

            goto L_8005F1E0;
    }
    // 0x8005F1B4: nop

    // 0x8005F1B8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005F1BC: lbu         $t2, 0x7208($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7208);
    // 0x8005F1C0: nop

    // 0x8005F1C4: slti        $at, $t2, 0x32
    ctx->r1 = SIGNED(ctx->r10) < 0X32 ? 1 : 0;
    // 0x8005F1C8: bne         $at, $zero, L_8005F1D8
    if (ctx->r1 != 0) {
        // 0x8005F1CC: nop

            goto L_8005F1D8;
    }
    // 0x8005F1CC: nop

    // 0x8005F1D0: jal         0x8005F0DC
    // 0x8005F1D4: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    func_8005F0DC(rdram, ctx);
        goto after_2;
    // 0x8005F1D4: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    after_2:
L_8005F1D8:
    // 0x8005F1D8: b           L_8005F258
    // 0x8005F1DC: nop

        goto L_8005F258;
    // 0x8005F1DC: nop

L_8005F1E0:
    // 0x8005F1E0: jal         0x8005F064
    // 0x8005F1E4: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    func_8005F064(rdram, ctx);
        goto after_3;
    // 0x8005F1E4: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    after_3:
    // 0x8005F1E8: bne         $v0, $zero, L_8005F218
    if (ctx->r2 != 0) {
        // 0x8005F1EC: nop

            goto L_8005F218;
    }
    // 0x8005F1EC: nop

    // 0x8005F1F0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005F1F4: lbu         $t3, 0x7208($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7208);
    // 0x8005F1F8: nop

    // 0x8005F1FC: slti        $at, $t3, 0x46
    ctx->r1 = SIGNED(ctx->r11) < 0X46 ? 1 : 0;
    // 0x8005F200: bne         $at, $zero, L_8005F210
    if (ctx->r1 != 0) {
        // 0x8005F204: nop

            goto L_8005F210;
    }
    // 0x8005F204: nop

    // 0x8005F208: jal         0x8005F0DC
    // 0x8005F20C: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    func_8005F0DC(rdram, ctx);
        goto after_4;
    // 0x8005F20C: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    after_4:
L_8005F210:
    // 0x8005F210: b           L_8005F258
    // 0x8005F214: nop

        goto L_8005F258;
    // 0x8005F214: nop

L_8005F218:
    // 0x8005F218: jal         0x8005F064
    // 0x8005F21C: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x8005F21C: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_5:
    // 0x8005F220: bne         $v0, $zero, L_8005F250
    if (ctx->r2 != 0) {
        // 0x8005F224: nop

            goto L_8005F250;
    }
    // 0x8005F224: nop

    // 0x8005F228: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005F22C: lbu         $t4, 0x7208($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7208);
    // 0x8005F230: nop

    // 0x8005F234: slti        $at, $t4, 0x64
    ctx->r1 = SIGNED(ctx->r12) < 0X64 ? 1 : 0;
    // 0x8005F238: bne         $at, $zero, L_8005F248
    if (ctx->r1 != 0) {
        // 0x8005F23C: nop

            goto L_8005F248;
    }
    // 0x8005F23C: nop

    // 0x8005F240: jal         0x8005F0DC
    // 0x8005F244: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_8005F0DC(rdram, ctx);
        goto after_6;
    // 0x8005F244: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_6:
L_8005F248:
    // 0x8005F248: b           L_8005F258
    // 0x8005F24C: nop

        goto L_8005F258;
    // 0x8005F24C: nop

L_8005F250:
    // 0x8005F250: b           L_8005F258
    // 0x8005F254: nop

        goto L_8005F258;
    // 0x8005F254: nop

L_8005F258:
    // 0x8005F258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F25C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F260: jr          $ra
    // 0x8005F264: nop

    return;
    // 0x8005F264: nop

;}
RECOMP_FUNC void func_8005F268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F268: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F26C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F270: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005F274: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005F278: nop

    // 0x8005F27C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005F280: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8005F284: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005F288: nop

    // 0x8005F28C: bgez        $t8, L_8005F29C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005F290: sra         $t9, $t8, 3
        ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
            goto L_8005F29C;
    }
    // 0x8005F290: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8005F294: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x8005F298: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8005F29C:
    // 0x8005F29C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8005F2A0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005F2A4: nop

    // 0x8005F2A8: bgez        $t0, L_8005F2BC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005F2AC: andi        $t1, $t0, 0x7
        ctx->r9 = ctx->r8 & 0X7;
            goto L_8005F2BC;
    }
    // 0x8005F2AC: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x8005F2B0: beq         $t1, $zero, L_8005F2BC
    if (ctx->r9 == 0) {
        // 0x8005F2B4: nop

            goto L_8005F2BC;
    }
    // 0x8005F2B4: nop

    // 0x8005F2B8: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
L_8005F2BC:
    // 0x8005F2BC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8005F2C0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F2C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005F2C8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005F2CC: addiu       $t3, $t3, 0x680
    ctx->r11 = ADD32(ctx->r11, 0X680);
    // 0x8005F2D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005F2D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005F2D8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8005F2DC: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8005F2E0: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005F2E4: xor         $t9, $t8, $at
    ctx->r25 = ctx->r24 ^ ctx->r1;
    // 0x8005F2E8: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8005F2EC: and         $t1, $t5, $t0
    ctx->r9 = ctx->r13 & ctx->r8;
    // 0x8005F2F0: sb          $t1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r9;
    // 0x8005F2F4: jal         0x8005F31C
    // 0x8005F2F8: nop

    func_8005F31C(rdram, ctx);
        goto after_0;
    // 0x8005F2F8: nop

    after_0:
    // 0x8005F2FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8005F300: sb          $v0, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = ctx->r2;
    // 0x8005F304: b           L_8005F30C
    // 0x8005F308: nop

        goto L_8005F30C;
    // 0x8005F308: nop

L_8005F30C:
    // 0x8005F30C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F314: jr          $ra
    // 0x8005F318: nop

    return;
    // 0x8005F318: nop

;}
RECOMP_FUNC void func_8005F31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F31C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005F320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F324: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005F328: addiu       $t6, $t6, 0x4C20
    ctx->r14 = ADD32(ctx->r14, 0X4C20);
    // 0x8005F32C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8005F330: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005F334: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8005F338: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8005F33C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005F340: beq         $t7, $at, L_8005F3A4
    if (ctx->r15 == ctx->r1) {
        // 0x8005F344: nop

            goto L_8005F3A4;
    }
    // 0x8005F344: nop

L_8005F348:
    // 0x8005F348: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005F34C: nop

    // 0x8005F350: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8005F354: jal         0x8005F064
    // 0x8005F358: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8005F358: nop

    after_0:
    // 0x8005F35C: bne         $v0, $zero, L_8005F36C
    if (ctx->r2 != 0) {
        // 0x8005F360: nop

            goto L_8005F36C;
    }
    // 0x8005F360: nop

    // 0x8005F364: b           L_8005F37C
    // 0x8005F368: nop

        goto L_8005F37C;
    // 0x8005F368: nop

L_8005F36C:
    // 0x8005F36C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F370: nop

    // 0x8005F374: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005F378: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_8005F37C:
    // 0x8005F37C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005F380: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005F384: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8005F388: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F38C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8005F390: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8005F394: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005F398: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005F39C: bne         $t5, $at, L_8005F348
    if (ctx->r13 != ctx->r1) {
        // 0x8005F3A0: nop

            goto L_8005F348;
    }
    // 0x8005F3A0: nop

L_8005F3A4:
    // 0x8005F3A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F3A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005F3AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005F3B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005F3B4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005F3B8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005F3BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005F3C0: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8005F3C4: bne         $t8, $zero, L_8005F3D0
    if (ctx->r24 != 0) {
        // 0x8005F3C8: nop

            goto L_8005F3D0;
    }
    // 0x8005F3C8: nop

    // 0x8005F3CC: break       7
    do_break(2147873740);
L_8005F3D0:
    // 0x8005F3D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005F3D4: bne         $t8, $at, L_8005F3E8
    if (ctx->r24 != ctx->r1) {
        // 0x8005F3D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005F3E8;
    }
    // 0x8005F3D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005F3DC: bne         $t7, $at, L_8005F3E8
    if (ctx->r15 != ctx->r1) {
        // 0x8005F3E0: nop

            goto L_8005F3E8;
    }
    // 0x8005F3E0: nop

    // 0x8005F3E4: break       6
    do_break(2147873764);
L_8005F3E8:
    // 0x8005F3E8: mflo        $v0
    ctx->r2 = lo;
    // 0x8005F3EC: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8005F3F0: b           L_8005F400
    // 0x8005F3F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005F400;
    // 0x8005F3F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8005F3F8: b           L_8005F400
    // 0x8005F3FC: nop

        goto L_8005F400;
    // 0x8005F3FC: nop

L_8005F400:
    // 0x8005F400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005F408: jr          $ra
    // 0x8005F40C: nop

    return;
    // 0x8005F40C: nop

;}
RECOMP_FUNC void func_8005F410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F410: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005F414: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005F418: lbu         $t6, 0xD74($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0XD74);
    // 0x8005F41C: nop

    // 0x8005F420: sb          $t6, 0x1726($a0)
    MEM_B(0X1726, ctx->r4) = ctx->r14;
    // 0x8005F424: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F428:
    // 0x8005F428: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005F42C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005F430: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005F434: lbu         $t8, 0x668($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X668);
    // 0x8005F438: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x8005F43C: sb          $t8, 0x172C($t9)
    MEM_B(0X172C, ctx->r25) = ctx->r24;
    // 0x8005F440: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005F444: nop

    // 0x8005F448: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005F44C: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8005F450: bne         $at, $zero, L_8005F428
    if (ctx->r1 != 0) {
        // 0x8005F454: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8005F428;
    }
    // 0x8005F454: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8005F458: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F45C:
    // 0x8005F45C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005F460: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005F464: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005F468: lbu         $t3, 0x680($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X680);
    // 0x8005F46C: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8005F470: sb          $t3, 0x16E6($t4)
    MEM_B(0X16E6, ctx->r12) = ctx->r11;
    // 0x8005F474: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F478: nop

    // 0x8005F47C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005F480: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x8005F484: bne         $at, $zero, L_8005F45C
    if (ctx->r1 != 0) {
        // 0x8005F488: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_8005F45C;
    }
    // 0x8005F488: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8005F48C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F490:
    // 0x8005F490: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005F494: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005F498: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8005F49C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005F4A0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8005F4A4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8005F4A8: addu        $t2, $a0, $t9
    ctx->r10 = ADD32(ctx->r4, ctx->r25);
    // 0x8005F4AC: sh          $t1, 0x6E($t2)
    MEM_H(0X6E, ctx->r10) = ctx->r9;
    // 0x8005F4B0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F4B4: nop

    // 0x8005F4B8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F4BC: slti        $at, $t4, 0x2A
    ctx->r1 = SIGNED(ctx->r12) < 0X2A ? 1 : 0;
    // 0x8005F4C0: bne         $at, $zero, L_8005F490
    if (ctx->r1 != 0) {
        // 0x8005F4C4: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F490;
    }
    // 0x8005F4C4: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F4C8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F4CC:
    // 0x8005F4CC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F4D0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8005F4D4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005F4D8: lw          $t7, 0x468($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X468);
    // 0x8005F4DC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005F4E0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005F4E4: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8005F4E8: lwl         $at, 0x0($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X0);
    // 0x8005F4EC: lwr         $at, 0x3($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0X3);
    // 0x8005F4F0: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x8005F4F4: swl         $at, 0xAF2($t8)
    do_swl(rdram, 0XAF2, ctx->r24, ctx->r1);
    // 0x8005F4F8: swr         $at, 0xAF5($t8)
    do_swr(rdram, 0XAF5, ctx->r24, ctx->r1);
    // 0x8005F4FC: lwl         $t2, 0x4($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0X4);
    // 0x8005F500: lwr         $t2, 0x7($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0X7);
    // 0x8005F504: nop

    // 0x8005F508: swl         $t2, 0xAF6($t8)
    do_swl(rdram, 0XAF6, ctx->r24, ctx->r10);
    // 0x8005F50C: swr         $t2, 0xAF9($t8)
    do_swr(rdram, 0XAF9, ctx->r24, ctx->r10);
    // 0x8005F510: lwl         $at, 0x8($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X8);
    // 0x8005F514: lwr         $at, 0xB($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0XB);
    // 0x8005F518: nop

    // 0x8005F51C: swl         $at, 0xAFA($t8)
    do_swl(rdram, 0XAFA, ctx->r24, ctx->r1);
    // 0x8005F520: swr         $at, 0xAFD($t8)
    do_swr(rdram, 0XAFD, ctx->r24, ctx->r1);
    // 0x8005F524: lwl         $t2, 0xC($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0XC);
    // 0x8005F528: lwr         $t2, 0xF($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0XF);
    // 0x8005F52C: nop

    // 0x8005F530: swl         $t2, 0xAFE($t8)
    do_swl(rdram, 0XAFE, ctx->r24, ctx->r10);
    // 0x8005F534: swr         $t2, 0xB01($t8)
    do_swr(rdram, 0XB01, ctx->r24, ctx->r10);
    // 0x8005F538: lhu         $at, 0x10($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X10);
    // 0x8005F53C: nop

    // 0x8005F540: sh          $at, 0xB02($t8)
    MEM_H(0XB02, ctx->r24) = ctx->r1;
    // 0x8005F544: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F548: nop

    // 0x8005F54C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F550: slti        $at, $t4, 0x11
    ctx->r1 = SIGNED(ctx->r12) < 0X11 ? 1 : 0;
    // 0x8005F554: bne         $at, $zero, L_8005F4CC
    if (ctx->r1 != 0) {
        // 0x8005F558: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F4CC;
    }
    // 0x8005F558: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F55C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F560:
    // 0x8005F560: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F564: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005F568: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8005F56C: lw          $t1, 0x470($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X470);
    // 0x8005F570: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005F574: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8005F578: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x8005F57C: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8005F580: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8005F584: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x8005F588: swl         $at, 0xD0E($t6)
    do_swl(rdram, 0XD0E, ctx->r14, ctx->r1);
    // 0x8005F58C: swr         $at, 0xD11($t6)
    do_swr(rdram, 0XD11, ctx->r14, ctx->r1);
    // 0x8005F590: lwl         $t2, 0x4($t9)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r25, 0X4);
    // 0x8005F594: lwr         $t2, 0x7($t9)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r25, 0X7);
    // 0x8005F598: nop

    // 0x8005F59C: swl         $t2, 0xD12($t6)
    do_swl(rdram, 0XD12, ctx->r14, ctx->r10);
    // 0x8005F5A0: swr         $t2, 0xD15($t6)
    do_swr(rdram, 0XD15, ctx->r14, ctx->r10);
    // 0x8005F5A4: lwl         $at, 0x8($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X8);
    // 0x8005F5A8: lwr         $at, 0xB($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0XB);
    // 0x8005F5AC: nop

    // 0x8005F5B0: swl         $at, 0xD16($t6)
    do_swl(rdram, 0XD16, ctx->r14, ctx->r1);
    // 0x8005F5B4: swr         $at, 0xD19($t6)
    do_swr(rdram, 0XD19, ctx->r14, ctx->r1);
    // 0x8005F5B8: lwl         $t2, 0xC($t9)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r25, 0XC);
    // 0x8005F5BC: lwr         $t2, 0xF($t9)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r25, 0XF);
    // 0x8005F5C0: nop

    // 0x8005F5C4: swl         $t2, 0xD1A($t6)
    do_swl(rdram, 0XD1A, ctx->r14, ctx->r10);
    // 0x8005F5C8: swr         $t2, 0xD1D($t6)
    do_swr(rdram, 0XD1D, ctx->r14, ctx->r10);
    // 0x8005F5CC: lhu         $at, 0x10($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X10);
    // 0x8005F5D0: nop

    // 0x8005F5D4: sh          $at, 0xD1E($t6)
    MEM_H(0XD1E, ctx->r14) = ctx->r1;
    // 0x8005F5D8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F5DC: nop

    // 0x8005F5E0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F5E4: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8005F5E8: bne         $at, $zero, L_8005F560
    if (ctx->r1 != 0) {
        // 0x8005F5EC: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F560;
    }
    // 0x8005F5EC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F5F0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F5F4:
    // 0x8005F5F4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F5F8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005F5FC: sll         $t1, $t5, 3
    ctx->r9 = S32(ctx->r13 << 3);
    // 0x8005F600: lw          $t0, 0x478($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X478);
    // 0x8005F604: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8005F608: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005F60C: addu        $t8, $t0, $t1
    ctx->r24 = ADD32(ctx->r8, ctx->r9);
    // 0x8005F610: lwl         $at, 0x0($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X0);
    // 0x8005F614: lwr         $at, 0x3($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0X3);
    // 0x8005F618: addu        $t7, $a0, $t1
    ctx->r15 = ADD32(ctx->r4, ctx->r9);
    // 0x8005F61C: swl         $at, 0xD56($t7)
    do_swl(rdram, 0XD56, ctx->r15, ctx->r1);
    // 0x8005F620: swr         $at, 0xD59($t7)
    do_swr(rdram, 0XD59, ctx->r15, ctx->r1);
    // 0x8005F624: lwl         $t2, 0x4($t8)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r24, 0X4);
    // 0x8005F628: lwr         $t2, 0x7($t8)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r24, 0X7);
    // 0x8005F62C: nop

    // 0x8005F630: swl         $t2, 0xD5A($t7)
    do_swl(rdram, 0XD5A, ctx->r15, ctx->r10);
    // 0x8005F634: swr         $t2, 0xD5D($t7)
    do_swr(rdram, 0XD5D, ctx->r15, ctx->r10);
    // 0x8005F638: lwl         $at, 0x8($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X8);
    // 0x8005F63C: lwr         $at, 0xB($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0XB);
    // 0x8005F640: nop

    // 0x8005F644: swl         $at, 0xD5E($t7)
    do_swl(rdram, 0XD5E, ctx->r15, ctx->r1);
    // 0x8005F648: swr         $at, 0xD61($t7)
    do_swr(rdram, 0XD61, ctx->r15, ctx->r1);
    // 0x8005F64C: lwl         $t2, 0xC($t8)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r24, 0XC);
    // 0x8005F650: lwr         $t2, 0xF($t8)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r24, 0XF);
    // 0x8005F654: nop

    // 0x8005F658: swl         $t2, 0xD62($t7)
    do_swl(rdram, 0XD62, ctx->r15, ctx->r10);
    // 0x8005F65C: swr         $t2, 0xD65($t7)
    do_swr(rdram, 0XD65, ctx->r15, ctx->r10);
    // 0x8005F660: lhu         $at, 0x10($t8)
    ctx->r1 = MEM_HU(ctx->r24, 0X10);
    // 0x8005F664: nop

    // 0x8005F668: sh          $at, 0xD66($t7)
    MEM_H(0XD66, ctx->r15) = ctx->r1;
    // 0x8005F66C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F670: nop

    // 0x8005F674: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F678: slti        $at, $t4, 0x2F
    ctx->r1 = SIGNED(ctx->r12) < 0X2F ? 1 : 0;
    // 0x8005F67C: bne         $at, $zero, L_8005F5F4
    if (ctx->r1 != 0) {
        // 0x8005F680: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F5F4;
    }
    // 0x8005F680: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F684: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F688:
    // 0x8005F688: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F68C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005F690: sll         $t0, $t5, 3
    ctx->r8 = S32(ctx->r13 << 3);
    // 0x8005F694: lw          $t9, 0x488($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X488);
    // 0x8005F698: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x8005F69C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005F6A0: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8005F6A4: lwl         $at, 0x0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X0);
    // 0x8005F6A8: lwr         $at, 0x3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X3);
    // 0x8005F6AC: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8005F6B0: swl         $at, 0xC24($t1)
    do_swl(rdram, 0XC24, ctx->r9, ctx->r1);
    // 0x8005F6B4: swr         $at, 0xC27($t1)
    do_swr(rdram, 0XC27, ctx->r9, ctx->r1);
    // 0x8005F6B8: lwl         $t2, 0x4($t6)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r14, 0X4);
    // 0x8005F6BC: lwr         $t2, 0x7($t6)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r14, 0X7);
    // 0x8005F6C0: nop

    // 0x8005F6C4: swl         $t2, 0xC28($t1)
    do_swl(rdram, 0XC28, ctx->r9, ctx->r10);
    // 0x8005F6C8: swr         $t2, 0xC2B($t1)
    do_swr(rdram, 0XC2B, ctx->r9, ctx->r10);
    // 0x8005F6CC: lwl         $at, 0x8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X8);
    // 0x8005F6D0: lwr         $at, 0xB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XB);
    // 0x8005F6D4: nop

    // 0x8005F6D8: swl         $at, 0xC2C($t1)
    do_swl(rdram, 0XC2C, ctx->r9, ctx->r1);
    // 0x8005F6DC: swr         $at, 0xC2F($t1)
    do_swr(rdram, 0XC2F, ctx->r9, ctx->r1);
    // 0x8005F6E0: lwl         $t2, 0xC($t6)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r14, 0XC);
    // 0x8005F6E4: lwr         $t2, 0xF($t6)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r14, 0XF);
    // 0x8005F6E8: nop

    // 0x8005F6EC: swl         $t2, 0xC30($t1)
    do_swl(rdram, 0XC30, ctx->r9, ctx->r10);
    // 0x8005F6F0: swr         $t2, 0xC33($t1)
    do_swr(rdram, 0XC33, ctx->r9, ctx->r10);
    // 0x8005F6F4: lhu         $at, 0x10($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0X10);
    // 0x8005F6F8: nop

    // 0x8005F6FC: sh          $at, 0xC34($t1)
    MEM_H(0XC34, ctx->r9) = ctx->r1;
    // 0x8005F700: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F704: nop

    // 0x8005F708: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F70C: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x8005F710: bne         $at, $zero, L_8005F688
    if (ctx->r1 != 0) {
        // 0x8005F714: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F688;
    }
    // 0x8005F714: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F718: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F71C:
    // 0x8005F71C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F720: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8005F724: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x8005F728: lw          $t8, 0x4A4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4A4);
    // 0x8005F72C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8005F730: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005F734: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8005F738: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x8005F73C: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x8005F740: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8005F744: swl         $at, 0xCD8($t0)
    do_swl(rdram, 0XCD8, ctx->r8, ctx->r1);
    // 0x8005F748: swr         $at, 0xCDB($t0)
    do_swr(rdram, 0XCDB, ctx->r8, ctx->r1);
    // 0x8005F74C: lwl         $t2, 0x4($t7)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r15, 0X4);
    // 0x8005F750: lwr         $t2, 0x7($t7)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r15, 0X7);
    // 0x8005F754: nop

    // 0x8005F758: swl         $t2, 0xCDC($t0)
    do_swl(rdram, 0XCDC, ctx->r8, ctx->r10);
    // 0x8005F75C: swr         $t2, 0xCDF($t0)
    do_swr(rdram, 0XCDF, ctx->r8, ctx->r10);
    // 0x8005F760: lwl         $at, 0x8($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X8);
    // 0x8005F764: lwr         $at, 0xB($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0XB);
    // 0x8005F768: nop

    // 0x8005F76C: swl         $at, 0xCE0($t0)
    do_swl(rdram, 0XCE0, ctx->r8, ctx->r1);
    // 0x8005F770: swr         $at, 0xCE3($t0)
    do_swr(rdram, 0XCE3, ctx->r8, ctx->r1);
    // 0x8005F774: lwl         $t2, 0xC($t7)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r15, 0XC);
    // 0x8005F778: lwr         $t2, 0xF($t7)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r15, 0XF);
    // 0x8005F77C: nop

    // 0x8005F780: swl         $t2, 0xCE4($t0)
    do_swl(rdram, 0XCE4, ctx->r8, ctx->r10);
    // 0x8005F784: swr         $t2, 0xCE7($t0)
    do_swr(rdram, 0XCE7, ctx->r8, ctx->r10);
    // 0x8005F788: lhu         $at, 0x10($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X10);
    // 0x8005F78C: nop

    // 0x8005F790: sh          $at, 0xCE8($t0)
    MEM_H(0XCE8, ctx->r8) = ctx->r1;
    // 0x8005F794: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F798: nop

    // 0x8005F79C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F7A0: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8005F7A4: bne         $at, $zero, L_8005F71C
    if (ctx->r1 != 0) {
        // 0x8005F7A8: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F71C;
    }
    // 0x8005F7A8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F7AC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F7B0:
    // 0x8005F7B0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F7B4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005F7B8: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x8005F7BC: lw          $t6, 0x5A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5A8);
    // 0x8005F7C0: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8005F7C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8005F7C8: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8005F7CC: lwl         $at, 0x0($t1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r9, 0X0);
    // 0x8005F7D0: lwr         $at, 0x3($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0X3);
    // 0x8005F7D4: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8005F7D8: swl         $at, 0xC48($t9)
    do_swl(rdram, 0XC48, ctx->r25, ctx->r1);
    // 0x8005F7DC: swr         $at, 0xC4B($t9)
    do_swr(rdram, 0XC4B, ctx->r25, ctx->r1);
    // 0x8005F7E0: lwl         $t2, 0x4($t1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r9, 0X4);
    // 0x8005F7E4: lwr         $t2, 0x7($t1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r9, 0X7);
    // 0x8005F7E8: nop

    // 0x8005F7EC: swl         $t2, 0xC4C($t9)
    do_swl(rdram, 0XC4C, ctx->r25, ctx->r10);
    // 0x8005F7F0: swr         $t2, 0xC4F($t9)
    do_swr(rdram, 0XC4F, ctx->r25, ctx->r10);
    // 0x8005F7F4: lwl         $at, 0x8($t1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r9, 0X8);
    // 0x8005F7F8: lwr         $at, 0xB($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0XB);
    // 0x8005F7FC: nop

    // 0x8005F800: swl         $at, 0xC50($t9)
    do_swl(rdram, 0XC50, ctx->r25, ctx->r1);
    // 0x8005F804: swr         $at, 0xC53($t9)
    do_swr(rdram, 0XC53, ctx->r25, ctx->r1);
    // 0x8005F808: lwl         $t2, 0xC($t1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r9, 0XC);
    // 0x8005F80C: lwr         $t2, 0xF($t1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r9, 0XF);
    // 0x8005F810: nop

    // 0x8005F814: swl         $t2, 0xC54($t9)
    do_swl(rdram, 0XC54, ctx->r25, ctx->r10);
    // 0x8005F818: swr         $t2, 0xC57($t9)
    do_swr(rdram, 0XC57, ctx->r25, ctx->r10);
    // 0x8005F81C: lhu         $at, 0x10($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X10);
    // 0x8005F820: nop

    // 0x8005F824: sh          $at, 0xC58($t9)
    MEM_H(0XC58, ctx->r25) = ctx->r1;
    // 0x8005F828: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F82C: nop

    // 0x8005F830: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F834: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8005F838: bne         $at, $zero, L_8005F7B0
    if (ctx->r1 != 0) {
        // 0x8005F83C: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F7B0;
    }
    // 0x8005F83C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F840: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F844:
    // 0x8005F844: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F848: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005F84C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005F850: lw          $t7, 0x630($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X630);
    // 0x8005F854: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005F858: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005F85C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8005F860: lwl         $at, 0x0($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X0);
    // 0x8005F864: lwr         $at, 0x3($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0X3);
    // 0x8005F868: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x8005F86C: swl         $at, 0x10A4($t8)
    do_swl(rdram, 0X10A4, ctx->r24, ctx->r1);
    // 0x8005F870: swr         $at, 0x10A7($t8)
    do_swr(rdram, 0X10A7, ctx->r24, ctx->r1);
    // 0x8005F874: lwl         $t2, 0x4($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0X4);
    // 0x8005F878: lwr         $t2, 0x7($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0X7);
    // 0x8005F87C: nop

    // 0x8005F880: swl         $t2, 0x10A8($t8)
    do_swl(rdram, 0X10A8, ctx->r24, ctx->r10);
    // 0x8005F884: swr         $t2, 0x10AB($t8)
    do_swr(rdram, 0X10AB, ctx->r24, ctx->r10);
    // 0x8005F888: lwl         $at, 0x8($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X8);
    // 0x8005F88C: lwr         $at, 0xB($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0XB);
    // 0x8005F890: nop

    // 0x8005F894: swl         $at, 0x10AC($t8)
    do_swl(rdram, 0X10AC, ctx->r24, ctx->r1);
    // 0x8005F898: swr         $at, 0x10AF($t8)
    do_swr(rdram, 0X10AF, ctx->r24, ctx->r1);
    // 0x8005F89C: lwl         $t2, 0xC($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0XC);
    // 0x8005F8A0: lwr         $t2, 0xF($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0XF);
    // 0x8005F8A4: nop

    // 0x8005F8A8: swl         $t2, 0x10B0($t8)
    do_swl(rdram, 0X10B0, ctx->r24, ctx->r10);
    // 0x8005F8AC: swr         $t2, 0x10B3($t8)
    do_swr(rdram, 0X10B3, ctx->r24, ctx->r10);
    // 0x8005F8B0: lhu         $at, 0x10($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X10);
    // 0x8005F8B4: nop

    // 0x8005F8B8: sh          $at, 0x10B4($t8)
    MEM_H(0X10B4, ctx->r24) = ctx->r1;
    // 0x8005F8BC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F8C0: nop

    // 0x8005F8C4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F8C8: slti        $at, $t4, 0x2E
    ctx->r1 = SIGNED(ctx->r12) < 0X2E ? 1 : 0;
    // 0x8005F8CC: bne         $at, $zero, L_8005F844
    if (ctx->r1 != 0) {
        // 0x8005F8D0: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F844;
    }
    // 0x8005F8D0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F8D4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F8D8:
    // 0x8005F8D8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F8DC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005F8E0: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8005F8E4: lw          $t1, 0x634($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X634);
    // 0x8005F8E8: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005F8EC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8005F8F0: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x8005F8F4: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8005F8F8: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8005F8FC: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x8005F900: swl         $at, 0x1548($t6)
    do_swl(rdram, 0X1548, ctx->r14, ctx->r1);
    // 0x8005F904: swr         $at, 0x154B($t6)
    do_swr(rdram, 0X154B, ctx->r14, ctx->r1);
    // 0x8005F908: lwl         $t2, 0x4($t9)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r25, 0X4);
    // 0x8005F90C: lwr         $t2, 0x7($t9)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r25, 0X7);
    // 0x8005F910: nop

    // 0x8005F914: swl         $t2, 0x154C($t6)
    do_swl(rdram, 0X154C, ctx->r14, ctx->r10);
    // 0x8005F918: swr         $t2, 0x154F($t6)
    do_swr(rdram, 0X154F, ctx->r14, ctx->r10);
    // 0x8005F91C: lwl         $at, 0x8($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X8);
    // 0x8005F920: lwr         $at, 0xB($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0XB);
    // 0x8005F924: nop

    // 0x8005F928: swl         $at, 0x1550($t6)
    do_swl(rdram, 0X1550, ctx->r14, ctx->r1);
    // 0x8005F92C: swr         $at, 0x1553($t6)
    do_swr(rdram, 0X1553, ctx->r14, ctx->r1);
    // 0x8005F930: lwl         $t2, 0xC($t9)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r25, 0XC);
    // 0x8005F934: lwr         $t2, 0xF($t9)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r25, 0XF);
    // 0x8005F938: nop

    // 0x8005F93C: swl         $t2, 0x1554($t6)
    do_swl(rdram, 0X1554, ctx->r14, ctx->r10);
    // 0x8005F940: swr         $t2, 0x1557($t6)
    do_swr(rdram, 0X1557, ctx->r14, ctx->r10);
    // 0x8005F944: lhu         $at, 0x10($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X10);
    // 0x8005F948: nop

    // 0x8005F94C: sh          $at, 0x1558($t6)
    MEM_H(0X1558, ctx->r14) = ctx->r1;
    // 0x8005F950: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F954: nop

    // 0x8005F958: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F95C: slti        $at, $t4, 0x17
    ctx->r1 = SIGNED(ctx->r12) < 0X17 ? 1 : 0;
    // 0x8005F960: bne         $at, $zero, L_8005F8D8
    if (ctx->r1 != 0) {
        // 0x8005F964: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F8D8;
    }
    // 0x8005F964: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F968: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F96C:
    // 0x8005F96C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F970: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005F974: sll         $t1, $t5, 3
    ctx->r9 = S32(ctx->r13 << 3);
    // 0x8005F978: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x8005F97C: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8005F980: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005F984: addu        $t8, $t0, $t1
    ctx->r24 = ADD32(ctx->r8, ctx->r9);
    // 0x8005F988: lwl         $at, 0x0($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X0);
    // 0x8005F98C: lwr         $at, 0x3($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0X3);
    // 0x8005F990: addu        $t7, $a0, $t1
    ctx->r15 = ADD32(ctx->r4, ctx->r9);
    // 0x8005F994: swl         $at, 0x13E0($t7)
    do_swl(rdram, 0X13E0, ctx->r15, ctx->r1);
    // 0x8005F998: swr         $at, 0x13E3($t7)
    do_swr(rdram, 0X13E3, ctx->r15, ctx->r1);
    // 0x8005F99C: lwl         $t2, 0x4($t8)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r24, 0X4);
    // 0x8005F9A0: lwr         $t2, 0x7($t8)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r24, 0X7);
    // 0x8005F9A4: nop

    // 0x8005F9A8: swl         $t2, 0x13E4($t7)
    do_swl(rdram, 0X13E4, ctx->r15, ctx->r10);
    // 0x8005F9AC: swr         $t2, 0x13E7($t7)
    do_swr(rdram, 0X13E7, ctx->r15, ctx->r10);
    // 0x8005F9B0: lwl         $at, 0x8($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X8);
    // 0x8005F9B4: lwr         $at, 0xB($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0XB);
    // 0x8005F9B8: nop

    // 0x8005F9BC: swl         $at, 0x13E8($t7)
    do_swl(rdram, 0X13E8, ctx->r15, ctx->r1);
    // 0x8005F9C0: swr         $at, 0x13EB($t7)
    do_swr(rdram, 0X13EB, ctx->r15, ctx->r1);
    // 0x8005F9C4: lwl         $t2, 0xC($t8)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r24, 0XC);
    // 0x8005F9C8: lwr         $t2, 0xF($t8)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r24, 0XF);
    // 0x8005F9CC: nop

    // 0x8005F9D0: swl         $t2, 0x13EC($t7)
    do_swl(rdram, 0X13EC, ctx->r15, ctx->r10);
    // 0x8005F9D4: swr         $t2, 0x13EF($t7)
    do_swr(rdram, 0X13EF, ctx->r15, ctx->r10);
    // 0x8005F9D8: lhu         $at, 0x10($t8)
    ctx->r1 = MEM_HU(ctx->r24, 0X10);
    // 0x8005F9DC: nop

    // 0x8005F9E0: sh          $at, 0x13F0($t7)
    MEM_H(0X13F0, ctx->r15) = ctx->r1;
    // 0x8005F9E4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F9E8: nop

    // 0x8005F9EC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F9F0: slti        $at, $t4, 0x14
    ctx->r1 = SIGNED(ctx->r12) < 0X14 ? 1 : 0;
    // 0x8005F9F4: bne         $at, $zero, L_8005F96C
    if (ctx->r1 != 0) {
        // 0x8005F9F8: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F96C;
    }
    // 0x8005F9F8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F9FC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FA00:
    // 0x8005FA00: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005FA04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005FA08: sll         $t0, $t5, 3
    ctx->r8 = S32(ctx->r13 << 3);
    // 0x8005FA0C: lw          $t9, 0x638($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X638);
    // 0x8005FA10: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x8005FA14: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005FA18: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8005FA1C: lwl         $at, 0x0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X0);
    // 0x8005FA20: lwr         $at, 0x3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X3);
    // 0x8005FA24: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8005FA28: swl         $at, 0xA86($t1)
    do_swl(rdram, 0XA86, ctx->r9, ctx->r1);
    // 0x8005FA2C: swr         $at, 0xA89($t1)
    do_swr(rdram, 0XA89, ctx->r9, ctx->r1);
    // 0x8005FA30: lwl         $t2, 0x4($t6)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r14, 0X4);
    // 0x8005FA34: lwr         $t2, 0x7($t6)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r14, 0X7);
    // 0x8005FA38: nop

    // 0x8005FA3C: swl         $t2, 0xA8A($t1)
    do_swl(rdram, 0XA8A, ctx->r9, ctx->r10);
    // 0x8005FA40: swr         $t2, 0xA8D($t1)
    do_swr(rdram, 0XA8D, ctx->r9, ctx->r10);
    // 0x8005FA44: lwl         $at, 0x8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X8);
    // 0x8005FA48: lwr         $at, 0xB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XB);
    // 0x8005FA4C: nop

    // 0x8005FA50: swl         $at, 0xA8E($t1)
    do_swl(rdram, 0XA8E, ctx->r9, ctx->r1);
    // 0x8005FA54: swr         $at, 0xA91($t1)
    do_swr(rdram, 0XA91, ctx->r9, ctx->r1);
    // 0x8005FA58: lwl         $t2, 0xC($t6)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r14, 0XC);
    // 0x8005FA5C: lwr         $t2, 0xF($t6)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r14, 0XF);
    // 0x8005FA60: nop

    // 0x8005FA64: swl         $t2, 0xA92($t1)
    do_swl(rdram, 0XA92, ctx->r9, ctx->r10);
    // 0x8005FA68: swr         $t2, 0xA95($t1)
    do_swr(rdram, 0XA95, ctx->r9, ctx->r10);
    // 0x8005FA6C: lhu         $at, 0x10($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0X10);
    // 0x8005FA70: nop

    // 0x8005FA74: sh          $at, 0xA96($t1)
    MEM_H(0XA96, ctx->r9) = ctx->r1;
    // 0x8005FA78: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005FA7C: nop

    // 0x8005FA80: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005FA84: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8005FA88: bne         $at, $zero, L_8005FA00
    if (ctx->r1 != 0) {
        // 0x8005FA8C: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005FA00;
    }
    // 0x8005FA8C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005FA90: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FA94:
    // 0x8005FA94: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005FA98: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005FA9C: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x8005FAA0: lw          $t8, 0x63C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63C);
    // 0x8005FAA4: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8005FAA8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005FAAC: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8005FAB0: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x8005FAB4: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x8005FAB8: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8005FABC: swl         $at, 0xABC($t0)
    do_swl(rdram, 0XABC, ctx->r8, ctx->r1);
    // 0x8005FAC0: swr         $at, 0xABF($t0)
    do_swr(rdram, 0XABF, ctx->r8, ctx->r1);
    // 0x8005FAC4: lwl         $t2, 0x4($t7)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r15, 0X4);
    // 0x8005FAC8: lwr         $t2, 0x7($t7)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r15, 0X7);
    // 0x8005FACC: nop

    // 0x8005FAD0: swl         $t2, 0xAC0($t0)
    do_swl(rdram, 0XAC0, ctx->r8, ctx->r10);
    // 0x8005FAD4: swr         $t2, 0xAC3($t0)
    do_swr(rdram, 0XAC3, ctx->r8, ctx->r10);
    // 0x8005FAD8: lwl         $at, 0x8($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X8);
    // 0x8005FADC: lwr         $at, 0xB($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0XB);
    // 0x8005FAE0: nop

    // 0x8005FAE4: swl         $at, 0xAC4($t0)
    do_swl(rdram, 0XAC4, ctx->r8, ctx->r1);
    // 0x8005FAE8: swr         $at, 0xAC7($t0)
    do_swr(rdram, 0XAC7, ctx->r8, ctx->r1);
    // 0x8005FAEC: lwl         $t2, 0xC($t7)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r15, 0XC);
    // 0x8005FAF0: lwr         $t2, 0xF($t7)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r15, 0XF);
    // 0x8005FAF4: nop

    // 0x8005FAF8: swl         $t2, 0xAC8($t0)
    do_swl(rdram, 0XAC8, ctx->r8, ctx->r10);
    // 0x8005FAFC: swr         $t2, 0xACB($t0)
    do_swr(rdram, 0XACB, ctx->r8, ctx->r10);
    // 0x8005FB00: lhu         $at, 0x10($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X10);
    // 0x8005FB04: nop

    // 0x8005FB08: sh          $at, 0xACC($t0)
    MEM_H(0XACC, ctx->r8) = ctx->r1;
    // 0x8005FB0C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005FB10: nop

    // 0x8005FB14: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005FB18: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8005FB1C: bne         $at, $zero, L_8005FA94
    if (ctx->r1 != 0) {
        // 0x8005FB20: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005FA94;
    }
    // 0x8005FB20: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005FB24: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005FB28: lw          $t5, 0x658($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X658);
    // 0x8005FB2C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8005FB30: beq         $t5, $zero, L_8005FBF8
    if (ctx->r13 == 0) {
        // 0x8005FB34: nop

            goto L_8005FBF8;
    }
    // 0x8005FB34: nop

L_8005FB38:
    // 0x8005FB38: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005FB3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005FB40: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005FB44: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8005FB48: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005FB4C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005FB50: addu        $t1, $t9, $t6
    ctx->r9 = ADD32(ctx->r25, ctx->r14);
    // 0x8005FB54: lbu         $t0, 0x2($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X2);
    // 0x8005FB58: addu        $t2, $a0, $t8
    ctx->r10 = ADD32(ctx->r4, ctx->r24);
    // 0x8005FB5C: andi        $t7, $t0, 0x3
    ctx->r15 = ctx->r8 & 0X3;
    // 0x8005FB60: sb          $t7, 0xC2($t2)
    MEM_B(0XC2, ctx->r10) = ctx->r15;
    // 0x8005FB64: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8005FB68: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005FB6C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005FB70: lw          $t3, 0x650($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X650);
    // 0x8005FB74: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8005FB78: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8005FB7C: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x8005FB80: lbu         $t6, 0x3($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X3);
    // 0x8005FB84: addu        $t8, $a0, $t4
    ctx->r24 = ADD32(ctx->r4, ctx->r12);
    // 0x8005FB88: lbu         $t7, 0xC2($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XC2);
    // 0x8005FB8C: andi        $t1, $t6, 0xF
    ctx->r9 = ctx->r14 & 0XF;
    // 0x8005FB90: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8005FB94: addu        $t3, $a0, $t4
    ctx->r11 = ADD32(ctx->r4, ctx->r12);
    // 0x8005FB98: or          $t2, $t7, $t0
    ctx->r10 = ctx->r15 | ctx->r8;
    // 0x8005FB9C: sb          $t2, 0xC2($t3)
    MEM_B(0XC2, ctx->r11) = ctx->r10;
    // 0x8005FBA0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FBA4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005FBA8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8005FBAC: lw          $t5, 0x650($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X650);
    // 0x8005FBB0: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8005FBB4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005FBB8: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x8005FBBC: lbu         $t8, 0x4($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X4);
    // 0x8005FBC0: addu        $t4, $a0, $t9
    ctx->r12 = ADD32(ctx->r4, ctx->r25);
    // 0x8005FBC4: lbu         $t2, 0xC2($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0XC2);
    // 0x8005FBC8: andi        $t7, $t8, 0x3
    ctx->r15 = ctx->r24 & 0X3;
    // 0x8005FBCC: sll         $t0, $t7, 6
    ctx->r8 = S32(ctx->r15 << 6);
    // 0x8005FBD0: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x8005FBD4: or          $t3, $t2, $t0
    ctx->r11 = ctx->r10 | ctx->r8;
    // 0x8005FBD8: sb          $t3, 0xC2($t5)
    MEM_B(0XC2, ctx->r13) = ctx->r11;
    // 0x8005FBDC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005FBE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005FBE4: lw          $t8, 0x658($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X658);
    // 0x8005FBE8: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x8005FBEC: sltu        $at, $t1, $t8
    ctx->r1 = ctx->r9 < ctx->r24 ? 1 : 0;
    // 0x8005FBF0: bne         $at, $zero, L_8005FB38
    if (ctx->r1 != 0) {
        // 0x8005FBF4: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8005FB38;
    }
    // 0x8005FBF4: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_8005FBF8:
    // 0x8005FBF8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005FBFC: lw          $t7, 0x658($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X658);
    // 0x8005FC00: nop

    // 0x8005FC04: sw          $t7, 0x1728($a0)
    MEM_W(0X1728, ctx->r4) = ctx->r15;
    // 0x8005FC08: b           L_8005FC10
    // 0x8005FC0C: nop

        goto L_8005FC10;
    // 0x8005FC0C: nop

L_8005FC10:
    // 0x8005FC10: jr          $ra
    // 0x8005FC14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005FC14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005FC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FC18: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005FC1C: lbu         $t6, 0x1726($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1726);
    // 0x8005FC20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005FC24: sb          $t6, 0xD74($at)
    MEM_B(0XD74, ctx->r1) = ctx->r14;
    // 0x8005FC28: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FC2C:
    // 0x8005FC2C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005FC30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005FC34: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8005FC38: lbu         $t9, 0x16E6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X16E6);
    // 0x8005FC3C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005FC40: sb          $t9, 0x680($at)
    MEM_B(0X680, ctx->r1) = ctx->r25;
    // 0x8005FC44: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005FC48: nop

    // 0x8005FC4C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005FC50: slti        $at, $t1, 0x40
    ctx->r1 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // 0x8005FC54: bne         $at, $zero, L_8005FC2C
    if (ctx->r1 != 0) {
        // 0x8005FC58: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8005FC2C;
    }
    // 0x8005FC58: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8005FC5C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FC60:
    // 0x8005FC60: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005FC64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005FC68: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8005FC6C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005FC70: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8005FC74: lh          $t5, 0x6E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6E);
    // 0x8005FC78: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x8005FC7C: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x8005FC80: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FC84: nop

    // 0x8005FC88: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FC8C: slti        $at, $t7, 0x2A
    ctx->r1 = SIGNED(ctx->r15) < 0X2A ? 1 : 0;
    // 0x8005FC90: bne         $at, $zero, L_8005FC60
    if (ctx->r1 != 0) {
        // 0x8005FC94: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FC60;
    }
    // 0x8005FC94: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FC98: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FC9C:
    // 0x8005FC9C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005FCA0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005FCA4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8005FCA8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005FCAC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FCB0: addu        $t6, $a0, $t2
    ctx->r14 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FCB4: lw          $t0, 0x468($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X468);
    // 0x8005FCB8: lwl         $at, 0xAF2($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0XAF2);
    // 0x8005FCBC: lwr         $at, 0xAF5($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XAF5);
    // 0x8005FCC0: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x8005FCC4: swl         $at, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r1);
    // 0x8005FCC8: swr         $at, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r1);
    // 0x8005FCCC: lwl         $t8, 0xAF6($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0XAF6);
    // 0x8005FCD0: lwr         $t8, 0xAF9($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XAF9);
    // 0x8005FCD4: nop

    // 0x8005FCD8: swl         $t8, 0x4($t4)
    do_swl(rdram, 0X4, ctx->r12, ctx->r24);
    // 0x8005FCDC: swr         $t8, 0x7($t4)
    do_swr(rdram, 0X7, ctx->r12, ctx->r24);
    // 0x8005FCE0: lwl         $at, 0xAFA($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0XAFA);
    // 0x8005FCE4: lwr         $at, 0xAFD($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XAFD);
    // 0x8005FCE8: nop

    // 0x8005FCEC: swl         $at, 0x8($t4)
    do_swl(rdram, 0X8, ctx->r12, ctx->r1);
    // 0x8005FCF0: swr         $at, 0xB($t4)
    do_swr(rdram, 0XB, ctx->r12, ctx->r1);
    // 0x8005FCF4: lwl         $t8, 0xAFE($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0XAFE);
    // 0x8005FCF8: lwr         $t8, 0xB01($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XB01);
    // 0x8005FCFC: nop

    // 0x8005FD00: swl         $t8, 0xC($t4)
    do_swl(rdram, 0XC, ctx->r12, ctx->r24);
    // 0x8005FD04: swr         $t8, 0xF($t4)
    do_swr(rdram, 0XF, ctx->r12, ctx->r24);
    // 0x8005FD08: lhu         $at, 0xB02($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0XB02);
    // 0x8005FD0C: nop

    // 0x8005FD10: sh          $at, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r1;
    // 0x8005FD14: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FD18: nop

    // 0x8005FD1C: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FD20: slti        $at, $t7, 0x11
    ctx->r1 = SIGNED(ctx->r15) < 0X11 ? 1 : 0;
    // 0x8005FD24: bne         $at, $zero, L_8005FC9C
    if (ctx->r1 != 0) {
        // 0x8005FD28: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FC9C;
    }
    // 0x8005FD28: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FD2C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FD30:
    // 0x8005FD30: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005FD34: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005FD38: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8005FD3C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8005FD40: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FD44: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FD48: lw          $t1, 0x470($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X470);
    // 0x8005FD4C: lwl         $at, 0xD0E($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XD0E);
    // 0x8005FD50: lwr         $at, 0xD11($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XD11);
    // 0x8005FD54: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x8005FD58: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x8005FD5C: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x8005FD60: lwl         $t8, 0xD12($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XD12);
    // 0x8005FD64: lwr         $t8, 0xD15($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XD15);
    // 0x8005FD68: nop

    // 0x8005FD6C: swl         $t8, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r24);
    // 0x8005FD70: swr         $t8, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r24);
    // 0x8005FD74: lwl         $at, 0xD16($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XD16);
    // 0x8005FD78: lwr         $at, 0xD19($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XD19);
    // 0x8005FD7C: nop

    // 0x8005FD80: swl         $at, 0x8($t5)
    do_swl(rdram, 0X8, ctx->r13, ctx->r1);
    // 0x8005FD84: swr         $at, 0xB($t5)
    do_swr(rdram, 0XB, ctx->r13, ctx->r1);
    // 0x8005FD88: lwl         $t8, 0xD1A($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XD1A);
    // 0x8005FD8C: lwr         $t8, 0xD1D($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XD1D);
    // 0x8005FD90: nop

    // 0x8005FD94: swl         $t8, 0xC($t5)
    do_swl(rdram, 0XC, ctx->r13, ctx->r24);
    // 0x8005FD98: swr         $t8, 0xF($t5)
    do_swr(rdram, 0XF, ctx->r13, ctx->r24);
    // 0x8005FD9C: lhu         $at, 0xD1E($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0XD1E);
    // 0x8005FDA0: nop

    // 0x8005FDA4: sh          $at, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r1;
    // 0x8005FDA8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FDAC: nop

    // 0x8005FDB0: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FDB4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8005FDB8: bne         $at, $zero, L_8005FD30
    if (ctx->r1 != 0) {
        // 0x8005FDBC: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FD30;
    }
    // 0x8005FDBC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FDC0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FDC4:
    // 0x8005FDC4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005FDC8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005FDCC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8005FDD0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005FDD4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FDD8: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FDDC: lw          $t0, 0x478($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X478);
    // 0x8005FDE0: lwl         $at, 0xD56($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0XD56);
    // 0x8005FDE4: lwr         $at, 0xD59($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XD59);
    // 0x8005FDE8: addu        $t6, $t0, $t2
    ctx->r14 = ADD32(ctx->r8, ctx->r10);
    // 0x8005FDEC: swl         $at, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r1);
    // 0x8005FDF0: swr         $at, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r1);
    // 0x8005FDF4: lwl         $t8, 0xD5A($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0XD5A);
    // 0x8005FDF8: lwr         $t8, 0xD5D($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0XD5D);
    // 0x8005FDFC: nop

    // 0x8005FE00: swl         $t8, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r24);
    // 0x8005FE04: swr         $t8, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r24);
    // 0x8005FE08: lwl         $at, 0xD5E($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0XD5E);
    // 0x8005FE0C: lwr         $at, 0xD61($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XD61);
    // 0x8005FE10: nop

    // 0x8005FE14: swl         $at, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r1);
    // 0x8005FE18: swr         $at, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r1);
    // 0x8005FE1C: lwl         $t8, 0xD62($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0XD62);
    // 0x8005FE20: lwr         $t8, 0xD65($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0XD65);
    // 0x8005FE24: nop

    // 0x8005FE28: swl         $t8, 0xC($t6)
    do_swl(rdram, 0XC, ctx->r14, ctx->r24);
    // 0x8005FE2C: swr         $t8, 0xF($t6)
    do_swr(rdram, 0XF, ctx->r14, ctx->r24);
    // 0x8005FE30: lhu         $at, 0xD66($t4)
    ctx->r1 = MEM_HU(ctx->r12, 0XD66);
    // 0x8005FE34: nop

    // 0x8005FE38: sh          $at, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r1;
    // 0x8005FE3C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FE40: nop

    // 0x8005FE44: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FE48: slti        $at, $t7, 0x2F
    ctx->r1 = SIGNED(ctx->r15) < 0X2F ? 1 : 0;
    // 0x8005FE4C: bne         $at, $zero, L_8005FDC4
    if (ctx->r1 != 0) {
        // 0x8005FE50: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FDC4;
    }
    // 0x8005FE50: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FE54: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FE58:
    // 0x8005FE58: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005FE5C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005FE60: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8005FE64: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8005FE68: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FE6C: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FE70: lw          $t1, 0x488($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X488);
    // 0x8005FE74: lwl         $at, 0xC24($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0XC24);
    // 0x8005FE78: lwr         $at, 0xC27($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0XC27);
    // 0x8005FE7C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8005FE80: swl         $at, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r1);
    // 0x8005FE84: swr         $at, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r1);
    // 0x8005FE88: lwl         $t8, 0xC28($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0XC28);
    // 0x8005FE8C: lwr         $t8, 0xC2B($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0XC2B);
    // 0x8005FE90: nop

    // 0x8005FE94: swl         $t8, 0x4($t3)
    do_swl(rdram, 0X4, ctx->r11, ctx->r24);
    // 0x8005FE98: swr         $t8, 0x7($t3)
    do_swr(rdram, 0X7, ctx->r11, ctx->r24);
    // 0x8005FE9C: lwl         $at, 0xC2C($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0XC2C);
    // 0x8005FEA0: lwr         $at, 0xC2F($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0XC2F);
    // 0x8005FEA4: nop

    // 0x8005FEA8: swl         $at, 0x8($t3)
    do_swl(rdram, 0X8, ctx->r11, ctx->r1);
    // 0x8005FEAC: swr         $at, 0xB($t3)
    do_swr(rdram, 0XB, ctx->r11, ctx->r1);
    // 0x8005FEB0: lwl         $t8, 0xC30($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0XC30);
    // 0x8005FEB4: lwr         $t8, 0xC33($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0XC33);
    // 0x8005FEB8: nop

    // 0x8005FEBC: swl         $t8, 0xC($t3)
    do_swl(rdram, 0XC, ctx->r11, ctx->r24);
    // 0x8005FEC0: swr         $t8, 0xF($t3)
    do_swr(rdram, 0XF, ctx->r11, ctx->r24);
    // 0x8005FEC4: lhu         $at, 0xC34($t5)
    ctx->r1 = MEM_HU(ctx->r13, 0XC34);
    // 0x8005FEC8: nop

    // 0x8005FECC: sh          $at, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r1;
    // 0x8005FED0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FED4: nop

    // 0x8005FED8: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FEDC: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8005FEE0: bne         $at, $zero, L_8005FE58
    if (ctx->r1 != 0) {
        // 0x8005FEE4: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FE58;
    }
    // 0x8005FEE4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FEE8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FEEC:
    // 0x8005FEEC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8005FEF0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005FEF4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8005FEF8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005FEFC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FF00: addu        $t6, $a0, $t2
    ctx->r14 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FF04: lw          $t0, 0x4A4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4A4);
    // 0x8005FF08: lwl         $at, 0xCD8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0XCD8);
    // 0x8005FF0C: lwr         $at, 0xCDB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XCDB);
    // 0x8005FF10: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x8005FF14: swl         $at, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r1);
    // 0x8005FF18: swr         $at, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r1);
    // 0x8005FF1C: lwl         $t8, 0xCDC($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0XCDC);
    // 0x8005FF20: lwr         $t8, 0xCDF($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XCDF);
    // 0x8005FF24: nop

    // 0x8005FF28: swl         $t8, 0x4($t4)
    do_swl(rdram, 0X4, ctx->r12, ctx->r24);
    // 0x8005FF2C: swr         $t8, 0x7($t4)
    do_swr(rdram, 0X7, ctx->r12, ctx->r24);
    // 0x8005FF30: lwl         $at, 0xCE0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0XCE0);
    // 0x8005FF34: lwr         $at, 0xCE3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XCE3);
    // 0x8005FF38: nop

    // 0x8005FF3C: swl         $at, 0x8($t4)
    do_swl(rdram, 0X8, ctx->r12, ctx->r1);
    // 0x8005FF40: swr         $at, 0xB($t4)
    do_swr(rdram, 0XB, ctx->r12, ctx->r1);
    // 0x8005FF44: lwl         $t8, 0xCE4($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0XCE4);
    // 0x8005FF48: lwr         $t8, 0xCE7($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XCE7);
    // 0x8005FF4C: nop

    // 0x8005FF50: swl         $t8, 0xC($t4)
    do_swl(rdram, 0XC, ctx->r12, ctx->r24);
    // 0x8005FF54: swr         $t8, 0xF($t4)
    do_swr(rdram, 0XF, ctx->r12, ctx->r24);
    // 0x8005FF58: lhu         $at, 0xCE8($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0XCE8);
    // 0x8005FF5C: nop

    // 0x8005FF60: sh          $at, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r1;
    // 0x8005FF64: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FF68: nop

    // 0x8005FF6C: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8005FF70: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8005FF74: bne         $at, $zero, L_8005FEEC
    if (ctx->r1 != 0) {
        // 0x8005FF78: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FEEC;
    }
    // 0x8005FF78: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8005FF7C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FF80:
    // 0x8005FF80: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005FF84: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8005FF88: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8005FF8C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8005FF90: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005FF94: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8005FF98: lw          $t1, 0x5A8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5A8);
    // 0x8005FF9C: lwl         $at, 0xC48($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XC48);
    // 0x8005FFA0: lwr         $at, 0xC4B($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XC4B);
    // 0x8005FFA4: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x8005FFA8: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x8005FFAC: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x8005FFB0: lwl         $t8, 0xC4C($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XC4C);
    // 0x8005FFB4: lwr         $t8, 0xC4F($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XC4F);
    // 0x8005FFB8: nop

    // 0x8005FFBC: swl         $t8, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r24);
    // 0x8005FFC0: swr         $t8, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r24);
    // 0x8005FFC4: lwl         $at, 0xC50($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XC50);
    // 0x8005FFC8: lwr         $at, 0xC53($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XC53);
    // 0x8005FFCC: nop

    // 0x8005FFD0: swl         $at, 0x8($t5)
    do_swl(rdram, 0X8, ctx->r13, ctx->r1);
    // 0x8005FFD4: swr         $at, 0xB($t5)
    do_swr(rdram, 0XB, ctx->r13, ctx->r1);
    // 0x8005FFD8: lwl         $t8, 0xC54($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XC54);
    // 0x8005FFDC: lwr         $t8, 0xC57($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XC57);
    // 0x8005FFE0: nop

    // 0x8005FFE4: swl         $t8, 0xC($t5)
    do_swl(rdram, 0XC, ctx->r13, ctx->r24);
    // 0x8005FFE8: swr         $t8, 0xF($t5)
    do_swr(rdram, 0XF, ctx->r13, ctx->r24);
    // 0x8005FFEC: lhu         $at, 0xC58($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0XC58);
    // 0x8005FFF0: nop

    // 0x8005FFF4: sh          $at, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r1;
    // 0x8005FFF8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FFFC: nop

    // 0x80060000: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80060004: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80060008: bne         $at, $zero, L_8005FF80
    if (ctx->r1 != 0) {
        // 0x8006000C: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8005FF80;
    }
    // 0x8006000C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80060010: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80060014:
    // 0x80060014: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80060018: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006001C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80060020: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80060024: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80060028: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8006002C: lw          $t0, 0x630($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X630);
    // 0x80060030: lwl         $at, 0x10A4($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X10A4);
    // 0x80060034: lwr         $at, 0x10A7($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0X10A7);
    // 0x80060038: addu        $t6, $t0, $t2
    ctx->r14 = ADD32(ctx->r8, ctx->r10);
    // 0x8006003C: swl         $at, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r1);
    // 0x80060040: swr         $at, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r1);
    // 0x80060044: lwl         $t8, 0x10A8($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0X10A8);
    // 0x80060048: lwr         $t8, 0x10AB($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0X10AB);
    // 0x8006004C: nop

    // 0x80060050: swl         $t8, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r24);
    // 0x80060054: swr         $t8, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r24);
    // 0x80060058: lwl         $at, 0x10AC($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X10AC);
    // 0x8006005C: lwr         $at, 0x10AF($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0X10AF);
    // 0x80060060: nop

    // 0x80060064: swl         $at, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r1);
    // 0x80060068: swr         $at, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r1);
    // 0x8006006C: lwl         $t8, 0x10B0($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0X10B0);
    // 0x80060070: lwr         $t8, 0x10B3($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0X10B3);
    // 0x80060074: nop

    // 0x80060078: swl         $t8, 0xC($t6)
    do_swl(rdram, 0XC, ctx->r14, ctx->r24);
    // 0x8006007C: swr         $t8, 0xF($t6)
    do_swr(rdram, 0XF, ctx->r14, ctx->r24);
    // 0x80060080: lhu         $at, 0x10B4($t4)
    ctx->r1 = MEM_HU(ctx->r12, 0X10B4);
    // 0x80060084: nop

    // 0x80060088: sh          $at, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r1;
    // 0x8006008C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80060090: nop

    // 0x80060094: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80060098: slti        $at, $t7, 0x2E
    ctx->r1 = SIGNED(ctx->r15) < 0X2E ? 1 : 0;
    // 0x8006009C: bne         $at, $zero, L_80060014
    if (ctx->r1 != 0) {
        // 0x800600A0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80060014;
    }
    // 0x800600A0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800600A4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800600A8:
    // 0x800600A8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800600AC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800600B0: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x800600B4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800600B8: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800600BC: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x800600C0: lw          $t1, 0x634($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X634);
    // 0x800600C4: lwl         $at, 0x1548($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X1548);
    // 0x800600C8: lwr         $at, 0x154B($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X154B);
    // 0x800600CC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800600D0: swl         $at, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r1);
    // 0x800600D4: swr         $at, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r1);
    // 0x800600D8: lwl         $t8, 0x154C($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0X154C);
    // 0x800600DC: lwr         $t8, 0x154F($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0X154F);
    // 0x800600E0: nop

    // 0x800600E4: swl         $t8, 0x4($t3)
    do_swl(rdram, 0X4, ctx->r11, ctx->r24);
    // 0x800600E8: swr         $t8, 0x7($t3)
    do_swr(rdram, 0X7, ctx->r11, ctx->r24);
    // 0x800600EC: lwl         $at, 0x1550($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X1550);
    // 0x800600F0: lwr         $at, 0x1553($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X1553);
    // 0x800600F4: nop

    // 0x800600F8: swl         $at, 0x8($t3)
    do_swl(rdram, 0X8, ctx->r11, ctx->r1);
    // 0x800600FC: swr         $at, 0xB($t3)
    do_swr(rdram, 0XB, ctx->r11, ctx->r1);
    // 0x80060100: lwl         $t8, 0x1554($t5)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r13, 0X1554);
    // 0x80060104: lwr         $t8, 0x1557($t5)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r13, 0X1557);
    // 0x80060108: nop

    // 0x8006010C: swl         $t8, 0xC($t3)
    do_swl(rdram, 0XC, ctx->r11, ctx->r24);
    // 0x80060110: swr         $t8, 0xF($t3)
    do_swr(rdram, 0XF, ctx->r11, ctx->r24);
    // 0x80060114: lhu         $at, 0x1558($t5)
    ctx->r1 = MEM_HU(ctx->r13, 0X1558);
    // 0x80060118: nop

    // 0x8006011C: sh          $at, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r1;
    // 0x80060120: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80060124: nop

    // 0x80060128: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8006012C: slti        $at, $t7, 0x17
    ctx->r1 = SIGNED(ctx->r15) < 0X17 ? 1 : 0;
    // 0x80060130: bne         $at, $zero, L_800600A8
    if (ctx->r1 != 0) {
        // 0x80060134: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800600A8;
    }
    // 0x80060134: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80060138: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8006013C:
    // 0x8006013C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80060140: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80060144: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80060148: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8006014C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80060150: addu        $t6, $a0, $t2
    ctx->r14 = ADD32(ctx->r4, ctx->r10);
    // 0x80060154: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x80060158: lwl         $at, 0x13E0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X13E0);
    // 0x8006015C: lwr         $at, 0x13E3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X13E3);
    // 0x80060160: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x80060164: swl         $at, 0x0($t4)
    do_swl(rdram, 0X0, ctx->r12, ctx->r1);
    // 0x80060168: swr         $at, 0x3($t4)
    do_swr(rdram, 0X3, ctx->r12, ctx->r1);
    // 0x8006016C: lwl         $t8, 0x13E4($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X13E4);
    // 0x80060170: lwr         $t8, 0x13E7($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X13E7);
    // 0x80060174: nop

    // 0x80060178: swl         $t8, 0x4($t4)
    do_swl(rdram, 0X4, ctx->r12, ctx->r24);
    // 0x8006017C: swr         $t8, 0x7($t4)
    do_swr(rdram, 0X7, ctx->r12, ctx->r24);
    // 0x80060180: lwl         $at, 0x13E8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X13E8);
    // 0x80060184: lwr         $at, 0x13EB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X13EB);
    // 0x80060188: nop

    // 0x8006018C: swl         $at, 0x8($t4)
    do_swl(rdram, 0X8, ctx->r12, ctx->r1);
    // 0x80060190: swr         $at, 0xB($t4)
    do_swr(rdram, 0XB, ctx->r12, ctx->r1);
    // 0x80060194: lwl         $t8, 0x13EC($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X13EC);
    // 0x80060198: lwr         $t8, 0x13EF($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X13EF);
    // 0x8006019C: nop

    // 0x800601A0: swl         $t8, 0xC($t4)
    do_swl(rdram, 0XC, ctx->r12, ctx->r24);
    // 0x800601A4: swr         $t8, 0xF($t4)
    do_swr(rdram, 0XF, ctx->r12, ctx->r24);
    // 0x800601A8: lhu         $at, 0x13F0($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0X13F0);
    // 0x800601AC: nop

    // 0x800601B0: sh          $at, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r1;
    // 0x800601B4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800601B8: nop

    // 0x800601BC: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800601C0: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x800601C4: bne         $at, $zero, L_8006013C
    if (ctx->r1 != 0) {
        // 0x800601C8: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8006013C;
    }
    // 0x800601C8: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800601CC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800601D0:
    // 0x800601D0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800601D4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800601D8: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x800601DC: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800601E0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800601E4: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x800601E8: lw          $t1, 0x638($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X638);
    // 0x800601EC: lwl         $at, 0xA86($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XA86);
    // 0x800601F0: lwr         $at, 0xA89($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XA89);
    // 0x800601F4: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x800601F8: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x800601FC: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x80060200: lwl         $t8, 0xA8A($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XA8A);
    // 0x80060204: lwr         $t8, 0xA8D($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XA8D);
    // 0x80060208: nop

    // 0x8006020C: swl         $t8, 0x4($t5)
    do_swl(rdram, 0X4, ctx->r13, ctx->r24);
    // 0x80060210: swr         $t8, 0x7($t5)
    do_swr(rdram, 0X7, ctx->r13, ctx->r24);
    // 0x80060214: lwl         $at, 0xA8E($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0XA8E);
    // 0x80060218: lwr         $at, 0xA91($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0XA91);
    // 0x8006021C: nop

    // 0x80060220: swl         $at, 0x8($t5)
    do_swl(rdram, 0X8, ctx->r13, ctx->r1);
    // 0x80060224: swr         $at, 0xB($t5)
    do_swr(rdram, 0XB, ctx->r13, ctx->r1);
    // 0x80060228: lwl         $t8, 0xA92($t3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r11, 0XA92);
    // 0x8006022C: lwr         $t8, 0xA95($t3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r11, 0XA95);
    // 0x80060230: nop

    // 0x80060234: swl         $t8, 0xC($t5)
    do_swl(rdram, 0XC, ctx->r13, ctx->r24);
    // 0x80060238: swr         $t8, 0xF($t5)
    do_swr(rdram, 0XF, ctx->r13, ctx->r24);
    // 0x8006023C: lhu         $at, 0xA96($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0XA96);
    // 0x80060240: nop

    // 0x80060244: sh          $at, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r1;
    // 0x80060248: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8006024C: nop

    // 0x80060250: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80060254: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80060258: bne         $at, $zero, L_800601D0
    if (ctx->r1 != 0) {
        // 0x8006025C: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800601D0;
    }
    // 0x8006025C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80060260: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80060264:
    // 0x80060264: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80060268: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006026C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80060270: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80060274: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80060278: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8006027C: lw          $t0, 0x63C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X63C);
    // 0x80060280: lwl         $at, 0xABC($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0XABC);
    // 0x80060284: lwr         $at, 0xABF($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XABF);
    // 0x80060288: addu        $t6, $t0, $t2
    ctx->r14 = ADD32(ctx->r8, ctx->r10);
    // 0x8006028C: swl         $at, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r1);
    // 0x80060290: swr         $at, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r1);
    // 0x80060294: lwl         $t8, 0xAC0($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0XAC0);
    // 0x80060298: lwr         $t8, 0xAC3($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0XAC3);
    // 0x8006029C: nop

    // 0x800602A0: swl         $t8, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r24);
    // 0x800602A4: swr         $t8, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r24);
    // 0x800602A8: lwl         $at, 0xAC4($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0XAC4);
    // 0x800602AC: lwr         $at, 0xAC7($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0XAC7);
    // 0x800602B0: nop

    // 0x800602B4: swl         $at, 0x8($t6)
    do_swl(rdram, 0X8, ctx->r14, ctx->r1);
    // 0x800602B8: swr         $at, 0xB($t6)
    do_swr(rdram, 0XB, ctx->r14, ctx->r1);
    // 0x800602BC: lwl         $t8, 0xAC8($t4)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r12, 0XAC8);
    // 0x800602C0: lwr         $t8, 0xACB($t4)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r12, 0XACB);
    // 0x800602C4: nop

    // 0x800602C8: swl         $t8, 0xC($t6)
    do_swl(rdram, 0XC, ctx->r14, ctx->r24);
    // 0x800602CC: swr         $t8, 0xF($t6)
    do_swr(rdram, 0XF, ctx->r14, ctx->r24);
    // 0x800602D0: lhu         $at, 0xACC($t4)
    ctx->r1 = MEM_HU(ctx->r12, 0XACC);
    // 0x800602D4: nop

    // 0x800602D8: sh          $at, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r1;
    // 0x800602DC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800602E0: nop

    // 0x800602E4: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800602E8: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x800602EC: bne         $at, $zero, L_80060264
    if (ctx->r1 != 0) {
        // 0x800602F0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80060264;
    }
    // 0x800602F0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800602F4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800602F8:
    // 0x800602F8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800602FC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80060300: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80060304: addu        $t0, $a0, $t1
    ctx->r8 = ADD32(ctx->r4, ctx->r9);
    // 0x80060308: lbu         $t2, 0x172C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X172C);
    // 0x8006030C: lbu         $t3, 0x668($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X668);
    // 0x80060310: nop

    // 0x80060314: beq         $t2, $t3, L_80060324
    if (ctx->r10 == ctx->r11) {
        // 0x80060318: nop

            goto L_80060324;
    }
    // 0x80060318: nop

    // 0x8006031C: b           L_8006042C
    // 0x80060320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006042C;
    // 0x80060320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060324:
    // 0x80060324: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80060328: nop

    // 0x8006032C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80060330: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80060334: bne         $at, $zero, L_800602F8
    if (ctx->r1 != 0) {
        // 0x80060338: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800602F8;
    }
    // 0x80060338: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8006033C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80060340: lw          $t4, 0x658($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X658);
    // 0x80060344: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80060348: beq         $t4, $zero, L_80060408
    if (ctx->r12 == 0) {
        // 0x8006034C: nop

            goto L_80060408;
    }
    // 0x8006034C: nop

L_80060350:
    // 0x80060350: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80060354: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80060358: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8006035C: lw          $t2, 0x650($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X650);
    // 0x80060360: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80060364: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80060368: lbu         $t7, 0xC2($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XC2);
    // 0x8006036C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80060370: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80060374: lbu         $t6, 0x4($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4);
    // 0x80060378: sra         $t0, $t7, 6
    ctx->r8 = S32(SIGNED(ctx->r15) >> 6);
    // 0x8006037C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80060380: beq         $t1, $t6, L_80060390
    if (ctx->r9 == ctx->r14) {
        // 0x80060384: nop

            goto L_80060390;
    }
    // 0x80060384: nop

    // 0x80060388: b           L_8006042C
    // 0x8006038C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006042C;
    // 0x8006038C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060390:
    // 0x80060390: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80060394: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060398: addu        $t9, $a0, $t4
    ctx->r25 = ADD32(ctx->r4, ctx->r12);
    // 0x8006039C: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x800603A0: lbu         $t7, 0xC2($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XC2);
    // 0x800603A4: lw          $t8, 0x650($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X650);
    // 0x800603A8: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x800603AC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800603B0: andi        $t0, $t7, 0x3
    ctx->r8 = ctx->r15 & 0X3;
    // 0x800603B4: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x800603B8: sb          $t0, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r8;
    // 0x800603BC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800603C0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800603C4: addu        $t1, $a0, $t5
    ctx->r9 = ADD32(ctx->r4, ctx->r13);
    // 0x800603C8: lbu         $t6, 0xC2($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XC2);
    // 0x800603CC: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800603D0: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x800603D4: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800603D8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800603DC: sra         $t9, $t6, 2
    ctx->r25 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800603E0: andi        $t7, $t9, 0xF
    ctx->r15 = ctx->r25 & 0XF;
    // 0x800603E4: addu        $t2, $t4, $t8
    ctx->r10 = ADD32(ctx->r12, ctx->r24);
    // 0x800603E8: sb          $t7, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r15;
    // 0x800603EC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800603F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800603F4: lw          $t1, 0x658($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X658);
    // 0x800603F8: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x800603FC: sltu        $at, $t3, $t1
    ctx->r1 = ctx->r11 < ctx->r9 ? 1 : 0;
    // 0x80060400: bne         $at, $zero, L_80060350
    if (ctx->r1 != 0) {
        // 0x80060404: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_80060350;
    }
    // 0x80060404: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_80060408:
    // 0x80060408: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8006040C: lw          $t9, 0x658($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X658);
    // 0x80060410: lw          $t6, 0x1728($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1728);
    // 0x80060414: nop

    // 0x80060418: xor         $v0, $t6, $t9
    ctx->r2 = ctx->r14 ^ ctx->r25;
    // 0x8006041C: b           L_8006042C
    // 0x80060420: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_8006042C;
    // 0x80060420: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80060424: b           L_8006042C
    // 0x80060428: nop

        goto L_8006042C;
    // 0x80060428: nop

L_8006042C:
    // 0x8006042C: jr          $ra
    // 0x80060430: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80060430: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80060434: nop

    // 0x80060438: nop

    // 0x8006043C: nop

;}
RECOMP_FUNC void func_80060440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060440: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80060444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060448: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8006044C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80060450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060454: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80060458: nop

    // 0x8006045C: beq         $t6, $zero, L_8006046C
    if (ctx->r14 == 0) {
        // 0x80060460: nop

            goto L_8006046C;
    }
    // 0x80060460: nop

    // 0x80060464: b           L_80060478
    // 0x80060468: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
        goto L_80060478;
    // 0x80060468: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8006046C:
    // 0x8006046C: jal         0x80061E14
    // 0x80060470: nop

    func_80061E14(rdram, ctx);
        goto after_0;
    // 0x80060470: nop

    after_0:
    // 0x80060474: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80060478:
    // 0x80060478: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8006047C: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80060480: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80060484: bne         $t7, $at, L_800604BC
    if (ctx->r15 != ctx->r1) {
        // 0x80060488: nop

            goto L_800604BC;
    }
    // 0x80060488: nop

    // 0x8006048C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80060490: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x80060494: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80060498: bne         $t8, $at, L_800604BC
    if (ctx->r24 != ctx->r1) {
        // 0x8006049C: nop

            goto L_800604BC;
    }
    // 0x8006049C: nop

    // 0x800604A0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800604A4: lw          $t9, 0x1358($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1358);
    // 0x800604A8: nop

    // 0x800604AC: addiu       $t0, $t9, 0xFA0
    ctx->r8 = ADD32(ctx->r25, 0XFA0);
    // 0x800604B0: sh          $t0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r8;
    // 0x800604B4: b           L_800607DC
    // 0x800604B8: nop

        goto L_800607DC;
    // 0x800604B8: nop

L_800604BC:
    // 0x800604BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800604C0: jal         0x8005A144
    // 0x800604C4: nop

    func_8005A144(rdram, ctx);
        goto after_1;
    // 0x800604C4: nop

    after_1:
    // 0x800604C8: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x800604CC: lh          $t1, 0x36($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X36);
    // 0x800604D0: nop

    // 0x800604D4: blez        $t1, L_800604E4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800604D8: nop

            goto L_800604E4;
    }
    // 0x800604D8: nop

    // 0x800604DC: b           L_800607DC
    // 0x800604E0: nop

        goto L_800607DC;
    // 0x800604E0: nop

L_800604E4:
    // 0x800604E4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800604E8: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800604EC: beq         $s0, $at, L_80060520
    if (ctx->r16 == ctx->r1) {
        // 0x800604F0: nop

            goto L_80060520;
    }
    // 0x800604F0: nop

    // 0x800604F4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800604F8: beq         $s0, $at, L_80060574
    if (ctx->r16 == ctx->r1) {
        // 0x800604FC: nop

            goto L_80060574;
    }
    // 0x800604FC: nop

    // 0x80060500: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80060504: beq         $s0, $at, L_800605C8
    if (ctx->r16 == ctx->r1) {
        // 0x80060508: nop

            goto L_800605C8;
    }
    // 0x80060508: nop

    // 0x8006050C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80060510: beq         $s0, $at, L_8006061C
    if (ctx->r16 == ctx->r1) {
        // 0x80060514: nop

            goto L_8006061C;
    }
    // 0x80060514: nop

    // 0x80060518: b           L_80060670
    // 0x8006051C: nop

        goto L_80060670;
    // 0x8006051C: nop

L_80060520:
    // 0x80060520: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80060524: nop

    // 0x80060528: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x8006052C: nop

    // 0x80060530: bne         $t3, $zero, L_80060540
    if (ctx->r11 != 0) {
        // 0x80060534: nop

            goto L_80060540;
    }
    // 0x80060534: nop

    // 0x80060538: b           L_80060670
    // 0x8006053C: nop

        goto L_80060670;
    // 0x8006053C: nop

L_80060540:
    // 0x80060540: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80060544: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060548: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006054C: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x80060550: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x80060554: lh          $a0, 0x8($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X8);
    // 0x80060558: jal         0x80061990
    // 0x8006055C: nop

    func_80061990(rdram, ctx);
        goto after_2;
    // 0x8006055C: nop

    after_2:
    // 0x80060560: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80060564: nop

    // 0x80060568: lh          $v0, 0x8($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X8);
    // 0x8006056C: b           L_8006080C
    // 0x80060570: nop

        goto L_8006080C;
    // 0x80060570: nop

L_80060574:
    // 0x80060574: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80060578: nop

    // 0x8006057C: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x80060580: nop

    // 0x80060584: bne         $t7, $zero, L_80060594
    if (ctx->r15 != 0) {
        // 0x80060588: nop

            goto L_80060594;
    }
    // 0x80060588: nop

    // 0x8006058C: b           L_80060670
    // 0x80060590: nop

        goto L_80060670;
    // 0x80060590: nop

L_80060594:
    // 0x80060594: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80060598: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8006059C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800605A0: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x800605A4: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x800605A8: lh          $a0, 0xA($t8)
    ctx->r4 = MEM_H(ctx->r24, 0XA);
    // 0x800605AC: jal         0x80061990
    // 0x800605B0: nop

    func_80061990(rdram, ctx);
        goto after_3;
    // 0x800605B0: nop

    after_3:
    // 0x800605B4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800605B8: nop

    // 0x800605BC: lh          $v0, 0xA($t9)
    ctx->r2 = MEM_H(ctx->r25, 0XA);
    // 0x800605C0: b           L_8006080C
    // 0x800605C4: nop

        goto L_8006080C;
    // 0x800605C4: nop

L_800605C8:
    // 0x800605C8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800605CC: nop

    // 0x800605D0: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x800605D4: nop

    // 0x800605D8: bne         $t1, $zero, L_800605E8
    if (ctx->r9 != 0) {
        // 0x800605DC: nop

            goto L_800605E8;
    }
    // 0x800605DC: nop

    // 0x800605E0: b           L_80060670
    // 0x800605E4: nop

        goto L_80060670;
    // 0x800605E4: nop

L_800605E8:
    // 0x800605E8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800605EC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800605F0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800605F4: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x800605F8: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x800605FC: lh          $a0, 0xC($t2)
    ctx->r4 = MEM_H(ctx->r10, 0XC);
    // 0x80060600: jal         0x80061990
    // 0x80060604: nop

    func_80061990(rdram, ctx);
        goto after_4;
    // 0x80060604: nop

    after_4:
    // 0x80060608: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8006060C: nop

    // 0x80060610: lh          $v0, 0xC($t3)
    ctx->r2 = MEM_H(ctx->r11, 0XC);
    // 0x80060614: b           L_8006080C
    // 0x80060618: nop

        goto L_8006080C;
    // 0x80060618: nop

L_8006061C:
    // 0x8006061C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80060620: nop

    // 0x80060624: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x80060628: nop

    // 0x8006062C: bne         $t5, $zero, L_8006063C
    if (ctx->r13 != 0) {
        // 0x80060630: nop

            goto L_8006063C;
    }
    // 0x80060630: nop

    // 0x80060634: b           L_80060670
    // 0x80060638: nop

        goto L_80060670;
    // 0x80060638: nop

L_8006063C:
    // 0x8006063C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80060640: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060644: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80060648: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x8006064C: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x80060650: lh          $a0, 0xE($t6)
    ctx->r4 = MEM_H(ctx->r14, 0XE);
    // 0x80060654: jal         0x80061990
    // 0x80060658: nop

    func_80061990(rdram, ctx);
        goto after_5;
    // 0x80060658: nop

    after_5:
    // 0x8006065C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80060660: nop

    // 0x80060664: lh          $v0, 0xE($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XE);
    // 0x80060668: b           L_8006080C
    // 0x8006066C: nop

        goto L_8006080C;
    // 0x8006066C: nop

L_80060670:
    // 0x80060670: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80060674: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80060678: nop

    // 0x8006067C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80060680: nop

    // 0x80060684: beq         $t9, $zero, L_800606B4
    if (ctx->r25 == 0) {
        // 0x80060688: nop

            goto L_800606B4;
    }
    // 0x80060688: nop

    // 0x8006068C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80060690: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80060694: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80060698: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8006069C: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x800606A0: sh          $t1, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r9;
    // 0x800606A4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800606A8: nop

    // 0x800606AC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800606B0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800606B4:
    // 0x800606B4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800606B8: nop

    // 0x800606BC: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800606C0: nop

    // 0x800606C4: beq         $t8, $zero, L_800606F4
    if (ctx->r24 == 0) {
        // 0x800606C8: nop

            goto L_800606F4;
    }
    // 0x800606C8: nop

    // 0x800606CC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800606D0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800606D4: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x800606D8: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x800606DC: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x800606E0: sh          $t0, 0x38($t3)
    MEM_H(0X38, ctx->r11) = ctx->r8;
    // 0x800606E4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800606E8: nop

    // 0x800606EC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800606F0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_800606F4:
    // 0x800606F4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800606F8: nop

    // 0x800606FC: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80060700: nop

    // 0x80060704: beq         $t7, $zero, L_80060734
    if (ctx->r15 == 0) {
        // 0x80060708: nop

            goto L_80060734;
    }
    // 0x80060708: nop

    // 0x8006070C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80060710: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80060714: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80060718: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x8006071C: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x80060720: sh          $t9, 0x38($t1)
    MEM_H(0X38, ctx->r9) = ctx->r25;
    // 0x80060724: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80060728: nop

    // 0x8006072C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80060730: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_80060734:
    // 0x80060734: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80060738: nop

    // 0x8006073C: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x80060740: nop

    // 0x80060744: beq         $t6, $zero, L_80060774
    if (ctx->r14 == 0) {
        // 0x80060748: nop

            goto L_80060774;
    }
    // 0x80060748: nop

    // 0x8006074C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80060750: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80060754: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80060758: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x8006075C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x80060760: sh          $t8, 0x38($t0)
    MEM_H(0X38, ctx->r8) = ctx->r24;
    // 0x80060764: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80060768: nop

    // 0x8006076C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80060770: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_80060774:
    // 0x80060774: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80060778: nop

    // 0x8006077C: bne         $t4, $zero, L_800607A4
    if (ctx->r12 != 0) {
        // 0x80060780: nop

            goto L_800607A4;
    }
    // 0x80060780: nop

    // 0x80060784: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060788: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006078C: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x80060790: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x80060794: jal         0x80061990
    // 0x80060798: addiu       $a0, $zero, 0x1386
    ctx->r4 = ADD32(0, 0X1386);
    func_80061990(rdram, ctx);
        goto after_6;
    // 0x80060798: addiu       $a0, $zero, 0x1386
    ctx->r4 = ADD32(0, 0X1386);
    after_6:
    // 0x8006079C: b           L_8006080C
    // 0x800607A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006080C;
    // 0x800607A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800607A4:
    // 0x800607A4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800607A8: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x800607AC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800607B0: nop

    // 0x800607B4: divu        $zero, $t5, $t6
    lo = S32(U32(ctx->r13) / U32(ctx->r14)); hi = S32(U32(ctx->r13) % U32(ctx->r14));
    // 0x800607B8: bne         $t6, $zero, L_800607C4
    if (ctx->r14 != 0) {
        // 0x800607BC: nop

            goto L_800607C4;
    }
    // 0x800607BC: nop

    // 0x800607C0: break       7
    do_break(2147878848);
L_800607C4:
    // 0x800607C4: mfhi        $t7
    ctx->r15 = hi;
    // 0x800607C8: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x800607CC: addu        $t8, $sp, $t2
    ctx->r24 = ADD32(ctx->r29, ctx->r10);
    // 0x800607D0: lh          $t8, 0x38($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X38);
    // 0x800607D4: nop

    // 0x800607D8: sh          $t8, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r24;
L_800607DC:
    // 0x800607DC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800607E0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800607E4: lw          $a2, 0x644($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X644);
    // 0x800607E8: lw          $a1, 0x640($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X640);
    // 0x800607EC: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x800607F0: jal         0x80061990
    // 0x800607F4: nop

    func_80061990(rdram, ctx);
        goto after_7;
    // 0x800607F4: nop

    after_7:
    // 0x800607F8: lh          $v0, 0x36($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X36);
    // 0x800607FC: b           L_8006080C
    // 0x80060800: nop

        goto L_8006080C;
    // 0x80060800: nop

    // 0x80060804: b           L_8006080C
    // 0x80060808: nop

        goto L_8006080C;
    // 0x80060808: nop

L_8006080C:
    // 0x8006080C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060814: jr          $ra
    // 0x80060818: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80060818: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006081C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006081C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060820: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060824: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80060828: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006082C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060830: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80060834: nop

    // 0x80060838: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8006083C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060840: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80060844: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80060848: nop

    // 0x8006084C: bne         $t7, $t8, L_80060868
    if (ctx->r15 != ctx->r24) {
        // 0x80060850: nop

            goto L_80060868;
    }
    // 0x80060850: nop

    // 0x80060854: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80060858: nop

    // 0x8006085C: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    // 0x80060860: jal         0x80061030
    // 0x80060864: nop

    func_80061030(rdram, ctx);
        goto after_0;
    // 0x80060864: nop

    after_0:
L_80060868:
    // 0x80060868: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8006086C: nop

    // 0x80060870: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80060874: nop

    // 0x80060878: sh          $t1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r9;
    // 0x8006087C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80060880: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80060884: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x80060888: nop

    // 0x8006088C: beq         $t3, $at, L_80060948
    if (ctx->r11 == ctx->r1) {
        // 0x80060890: sh          $t3, 0x30($sp)
        MEM_H(0X30, ctx->r29) = ctx->r11;
            goto L_80060948;
    }
    // 0x80060890: sh          $t3, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r11;
L_80060894:
    // 0x80060894: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
    // 0x80060898: lui         $t6, 0x809F
    ctx->r14 = S32(0X809F << 16);
    // 0x8006089C: addiu       $t6, $t6, -0x5918
    ctx->r14 = ADD32(ctx->r14, -0X5918);
    // 0x800608A0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x800608A4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x800608A8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800608AC: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x800608B0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x800608B4: jal         0x800BD1FC
    // 0x800608B8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x800608B8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_1:
    // 0x800608BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800608C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800608C4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800608C8: jal         0x800BD218
    // 0x800608CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800608CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800608D0: lhu         $t7, 0x2C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2C);
    // 0x800608D4: nop

    // 0x800608D8: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x800608DC: beq         $t8, $zero, L_800608F4
    if (ctx->r24 == 0) {
        // 0x800608E0: nop

            goto L_800608F4;
    }
    // 0x800608E0: nop

    // 0x800608E4: lh          $t9, 0x30($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X30);
    // 0x800608E8: nop

    // 0x800608EC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800608F0: sh          $t0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r8;
L_800608F4:
    // 0x800608F4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800608F8: nop

    // 0x800608FC: jalr        $t9
    // 0x80060900: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80060900: nop

    after_3:
    // 0x80060904: bne         $v0, $zero, L_80060920
    if (ctx->r2 != 0) {
        // 0x80060908: nop

            goto L_80060920;
    }
    // 0x80060908: nop

    // 0x8006090C: lhu         $t1, 0x2C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2C);
    // 0x80060910: nop

    // 0x80060914: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x80060918: bne         $t2, $zero, L_80060894
    if (ctx->r10 != 0) {
        // 0x8006091C: nop

            goto L_80060894;
    }
    // 0x8006091C: nop

L_80060920:
    // 0x80060920: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80060924: nop

    // 0x80060928: jalr        $t9
    // 0x8006092C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8006092C: nop

    after_4:
    // 0x80060930: beq         $v0, $zero, L_80060948
    if (ctx->r2 == 0) {
        // 0x80060934: nop

            goto L_80060948;
    }
    // 0x80060934: nop

    // 0x80060938: lhu         $t3, 0x2C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2C);
    // 0x8006093C: nop

    // 0x80060940: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x80060944: sh          $t4, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r12;
L_80060948:
    // 0x80060948: lh          $a0, 0x32($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X32);
    // 0x8006094C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80060950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060954: jal         0x8004BA04
    // 0x80060958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004BA04(rdram, ctx);
        goto after_5;
    // 0x80060958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8006095C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80060960: nop

    // 0x80060964: lbu         $t6, 0xA($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XA);
    // 0x80060968: nop

    // 0x8006096C: beq         $t6, $zero, L_800609E4
    if (ctx->r14 == 0) {
        // 0x80060970: nop

            goto L_800609E4;
    }
    // 0x80060970: nop

    // 0x80060974: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80060978: nop

    // 0x8006097C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80060980: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80060984: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x80060988: bne         $t0, $zero, L_80060998
    if (ctx->r8 != 0) {
        // 0x8006098C: andi        $t1, $t9, 0x0
        ctx->r9 = ctx->r25 & 0X0;
            goto L_80060998;
    }
    // 0x8006098C: andi        $t1, $t9, 0x0
    ctx->r9 = ctx->r25 & 0X0;
    // 0x80060990: beq         $t1, $zero, L_800609A0
    if (ctx->r9 == 0) {
        // 0x80060994: nop

            goto L_800609A0;
    }
    // 0x80060994: nop

L_80060998:
    // 0x80060998: b           L_800609F4
    // 0x8006099C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800609F4;
    // 0x8006099C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800609A0:
    // 0x800609A0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800609A4: nop

    // 0x800609A8: lh          $a0, 0xC($t2)
    ctx->r4 = MEM_H(ctx->r10, 0XC);
    // 0x800609AC: jal         0x80061B38
    // 0x800609B0: nop

    func_80061B38(rdram, ctx);
        goto after_6;
    // 0x800609B0: nop

    after_6:
    // 0x800609B4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800609B8: nop

    // 0x800609BC: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    // 0x800609C0: jal         0x80061FFC
    // 0x800609C4: nop

    func_80061FFC(rdram, ctx);
        goto after_7;
    // 0x800609C4: nop

    after_7:
    // 0x800609C8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800609CC: nop

    // 0x800609D0: lh          $a0, 0xE($t4)
    ctx->r4 = MEM_H(ctx->r12, 0XE);
    // 0x800609D4: jal         0x80060E9C
    // 0x800609D8: nop

    func_80060E9C(rdram, ctx);
        goto after_8;
    // 0x800609D8: nop

    after_8:
    // 0x800609DC: b           L_800609F4
    // 0x800609E0: nop

        goto L_800609F4;
    // 0x800609E0: nop

L_800609E4:
    // 0x800609E4: b           L_800609F4
    // 0x800609E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800609F4;
    // 0x800609E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800609EC: b           L_800609F4
    // 0x800609F0: nop

        goto L_800609F4;
    // 0x800609F0: nop

L_800609F4:
    // 0x800609F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800609F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800609FC: jr          $ra
    // 0x80060A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80060A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80060A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80060A10: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80060A14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060A18: bne         $t6, $at, L_80060A2C
    if (ctx->r14 != ctx->r1) {
        // 0x80060A1C: nop

            goto L_80060A2C;
    }
    // 0x80060A1C: nop

    // 0x80060A20: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80060A24: b           L_80060ABC
    // 0x80060A28: nop

        goto L_80060ABC;
    // 0x80060A28: nop

L_80060A2C:
    // 0x80060A2C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80060A30: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80060A34: nop

    // 0x80060A38: lh          $t8, 0x2E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2E);
    // 0x80060A3C: nop

    // 0x80060A40: slti        $at, $t8, 0x2BC
    ctx->r1 = SIGNED(ctx->r24) < 0X2BC ? 1 : 0;
    // 0x80060A44: beq         $at, $zero, L_80060A58
    if (ctx->r1 == 0) {
        // 0x80060A48: nop

            goto L_80060A58;
    }
    // 0x80060A48: nop

    // 0x80060A4C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80060A50: b           L_80060ABC
    // 0x80060A54: nop

        goto L_80060ABC;
    // 0x80060A54: nop

L_80060A58:
    // 0x80060A58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80060A5C: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80060A60: nop

    // 0x80060A64: lh          $t0, 0x2E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2E);
    // 0x80060A68: nop

    // 0x80060A6C: slti        $at, $t0, 0x384
    ctx->r1 = SIGNED(ctx->r8) < 0X384 ? 1 : 0;
    // 0x80060A70: beq         $at, $zero, L_80060AA8
    if (ctx->r1 == 0) {
        // 0x80060A74: nop

            goto L_80060AA8;
    }
    // 0x80060A74: nop

    // 0x80060A78: jal         0x800C4240
    // 0x80060A7C: nop

    guRandom(rdram, ctx);
        goto after_0;
    // 0x80060A7C: nop

    after_0:
    // 0x80060A80: bgez        $v0, L_80060A94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80060A84: andi        $t1, $v0, 0x1
        ctx->r9 = ctx->r2 & 0X1;
            goto L_80060A94;
    }
    // 0x80060A84: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80060A88: beq         $t1, $zero, L_80060A94
    if (ctx->r9 == 0) {
        // 0x80060A8C: nop

            goto L_80060A94;
    }
    // 0x80060A8C: nop

    // 0x80060A90: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
L_80060A94:
    // 0x80060A94: beq         $t1, $zero, L_80060AA8
    if (ctx->r9 == 0) {
        // 0x80060A98: nop

            goto L_80060AA8;
    }
    // 0x80060A98: nop

    // 0x80060A9C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80060AA0: b           L_80060ABC
    // 0x80060AA4: nop

        goto L_80060ABC;
    // 0x80060AA4: nop

L_80060AA8:
    // 0x80060AA8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80060AAC: b           L_80060ABC
    // 0x80060AB0: nop

        goto L_80060ABC;
    // 0x80060AB0: nop

    // 0x80060AB4: b           L_80060ABC
    // 0x80060AB8: nop

        goto L_80060ABC;
    // 0x80060AB8: nop

L_80060ABC:
    // 0x80060ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060AC4: jr          $ra
    // 0x80060AC8: nop

    return;
    // 0x80060AC8: nop

;}
RECOMP_FUNC void func_80060ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060ACC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060AD4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80060AD8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80060ADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060AE0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80060AE4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060AE8: lw          $t8, 0x644($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X644);
    // 0x80060AEC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80060AF0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80060AF4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80060AF8: jal         0x800BC6EC
    // 0x80060AFC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80060AFC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_0:
    // 0x80060B00: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80060B04: jal         0x80061E14
    // 0x80060B08: nop

    func_80061E14(rdram, ctx);
        goto after_1;
    // 0x80060B08: nop

    after_1:
    // 0x80060B0C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80060B10: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80060B14: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80060B18: jal         0x80060A04
    // 0x80060B1C: nop

    func_80060A04(rdram, ctx);
        goto after_2;
    // 0x80060B1C: nop

    after_2:
    // 0x80060B20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80060B24: jal         0x800611EC
    // 0x80060B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800611EC(rdram, ctx);
        goto after_3;
    // 0x80060B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80060B2C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80060B30: nop

    // 0x80060B34: beq         $t0, $zero, L_80060B98
    if (ctx->r8 == 0) {
        // 0x80060B38: nop

            goto L_80060B98;
    }
    // 0x80060B38: nop

    // 0x80060B3C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80060B40: nop

    // 0x80060B44: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80060B48: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80060B4C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80060B50: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80060B54: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80060B58: addiu       $t5, $t4, -0x2C1
    ctx->r13 = ADD32(ctx->r12, -0X2C1);
    // 0x80060B5C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80060B60: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80060B64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80060B68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80060B6C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80060B70: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80060B74: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80060B78: nop

    // 0x80060B7C: slti        $at, $t0, 0x320
    ctx->r1 = SIGNED(ctx->r8) < 0X320 ? 1 : 0;
    // 0x80060B80: bne         $at, $zero, L_80060B98
    if (ctx->r1 != 0) {
        // 0x80060B84: nop

            goto L_80060B98;
    }
    // 0x80060B84: nop

    // 0x80060B88: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80060B8C: nop

    // 0x80060B90: addiu       $t2, $t1, 0xF
    ctx->r10 = ADD32(ctx->r9, 0XF);
    // 0x80060B94: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80060B98:
    // 0x80060B98: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80060B9C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80060BA0: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80060BA4: nop

    // 0x80060BA8: beq         $t4, $at, L_80060DBC
    if (ctx->r12 == ctx->r1) {
        // 0x80060BAC: nop

            goto L_80060DBC;
    }
    // 0x80060BAC: nop

    // 0x80060BB0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80060BB4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80060BB8: lui         $a2, 0x809F
    ctx->r6 = S32(0X809F << 16);
    // 0x80060BBC: addiu       $a2, $a2, -0x4798
    ctx->r6 = ADD32(ctx->r6, -0X4798);
    // 0x80060BC0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80060BC4: jal         0x800BD1FC
    // 0x80060BC8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x80060BC8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_4:
    // 0x80060BCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80060BD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80060BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80060BD8: jal         0x800BD218
    // 0x80060BDC: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x80060BDC: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_5:
    // 0x80060BE0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80060BE4: nop

    // 0x80060BE8: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x80060BEC: nop

    // 0x80060BF0: bltz        $t7, L_80060C18
    if (SIGNED(ctx->r15) < 0) {
        // 0x80060BF4: nop

            goto L_80060C18;
    }
    // 0x80060BF4: nop

    // 0x80060BF8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80060BFC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060C00: lh          $a0, 0x2($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2);
    // 0x80060C04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060C08: jal         0x8004BA04
    // 0x80060C0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_6;
    // 0x80060C0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80060C10: b           L_80060DBC
    // 0x80060C14: nop

        goto L_80060DBC;
    // 0x80060C14: nop

L_80060C18:
    // 0x80060C18: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060C1C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80060C20: nop

    // 0x80060C24: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x80060C28: nop

    // 0x80060C2C: slti        $at, $t9, 0x384
    ctx->r1 = SIGNED(ctx->r25) < 0X384 ? 1 : 0;
    // 0x80060C30: bne         $at, $zero, L_80060C74
    if (ctx->r1 != 0) {
        // 0x80060C34: nop

            goto L_80060C74;
    }
    // 0x80060C34: nop

    // 0x80060C38: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80060C3C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80060C40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80060C44: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80060C48: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060C4C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80060C50: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80060C54: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80060C58: lh          $a0, 0x8($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X8);
    // 0x80060C5C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060C64: jal         0x8004BA04
    // 0x80060C68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_7;
    // 0x80060C68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80060C6C: b           L_80060DBC
    // 0x80060C70: nop

        goto L_80060DBC;
    // 0x80060C70: nop

L_80060C74:
    // 0x80060C74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80060C78: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80060C7C: nop

    // 0x80060C80: lh          $t8, 0x2E($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2E);
    // 0x80060C84: nop

    // 0x80060C88: slti        $at, $t8, 0x2BC
    ctx->r1 = SIGNED(ctx->r24) < 0X2BC ? 1 : 0;
    // 0x80060C8C: bne         $at, $zero, L_80060CD0
    if (ctx->r1 != 0) {
        // 0x80060C90: nop

            goto L_80060CD0;
    }
    // 0x80060C90: nop

    // 0x80060C94: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80060C98: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80060C9C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80060CA0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80060CA4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060CA8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80060CAC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80060CB0: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x80060CB4: lh          $a0, 0x6($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X6);
    // 0x80060CB8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060CBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060CC0: jal         0x8004BA04
    // 0x80060CC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_8;
    // 0x80060CC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80060CC8: b           L_80060DBC
    // 0x80060CCC: nop

        goto L_80060DBC;
    // 0x80060CCC: nop

L_80060CD0:
    // 0x80060CD0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80060CD4: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80060CD8: nop

    // 0x80060CDC: lh          $t6, 0x2C($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X2C);
    // 0x80060CE0: nop

    // 0x80060CE4: slti        $at, $t6, 0x384
    ctx->r1 = SIGNED(ctx->r14) < 0X384 ? 1 : 0;
    // 0x80060CE8: bne         $at, $zero, L_80060D2C
    if (ctx->r1 != 0) {
        // 0x80060CEC: nop

            goto L_80060D2C;
    }
    // 0x80060CEC: nop

    // 0x80060CF0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80060CF4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80060CF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80060CFC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80060D00: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060D04: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80060D08: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80060D0C: addu        $t3, $t5, $t2
    ctx->r11 = ADD32(ctx->r13, ctx->r10);
    // 0x80060D10: lh          $a0, 0x4($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X4);
    // 0x80060D14: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060D18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060D1C: jal         0x8004BA04
    // 0x80060D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_9;
    // 0x80060D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80060D24: b           L_80060DBC
    // 0x80060D28: nop

        goto L_80060DBC;
    // 0x80060D28: nop

L_80060D2C:
    // 0x80060D2C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80060D30: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x80060D34: nop

    // 0x80060D38: lh          $t7, 0x2C($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2C);
    // 0x80060D3C: nop

    // 0x80060D40: slti        $at, $t7, 0x2BC
    ctx->r1 = SIGNED(ctx->r15) < 0X2BC ? 1 : 0;
    // 0x80060D44: bne         $at, $zero, L_80060D88
    if (ctx->r1 != 0) {
        // 0x80060D48: nop

            goto L_80060D88;
    }
    // 0x80060D48: nop

    // 0x80060D4C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80060D50: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80060D54: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80060D58: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80060D5C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80060D60: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80060D64: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80060D68: addu        $t2, $t5, $t1
    ctx->r10 = ADD32(ctx->r13, ctx->r9);
    // 0x80060D6C: lh          $a0, 0x4($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X4);
    // 0x80060D70: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060D78: jal         0x8004BA04
    // 0x80060D7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_10;
    // 0x80060D7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80060D80: b           L_80060DBC
    // 0x80060D84: nop

        goto L_80060DBC;
    // 0x80060D84: nop

L_80060D88:
    // 0x80060D88: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80060D8C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80060D90: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80060D94: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80060D98: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80060D9C: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80060DA0: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80060DA4: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80060DA8: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x80060DAC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80060DB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80060DB4: jal         0x8004BA04
    // 0x80060DB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004BA04(rdram, ctx);
        goto after_11;
    // 0x80060DB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
L_80060DBC:
    // 0x80060DBC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80060DC0: nop

    // 0x80060DC4: lh          $a0, 0x0($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X0);
    // 0x80060DC8: jal         0x80061B38
    // 0x80060DCC: nop

    func_80061B38(rdram, ctx);
        goto after_12;
    // 0x80060DCC: nop

    after_12:
    // 0x80060DD0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80060DD4: nop

    // 0x80060DD8: lh          $a0, 0x6($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X6);
    // 0x80060DDC: jal         0x80061FFC
    // 0x80060DE0: nop

    func_80061FFC(rdram, ctx);
        goto after_13;
    // 0x80060DE0: nop

    after_13:
    // 0x80060DE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80060DE8: jal         0x800BC980
    // 0x80060DEC: nop

    SysMem_Free(rdram, ctx);
        goto after_14;
    // 0x80060DEC: nop

    after_14:
    // 0x80060DF0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80060DF4: nop

    // 0x80060DF8: lh          $a0, 0x4($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X4);
    // 0x80060DFC: jal         0x80060E9C
    // 0x80060E00: nop

    func_80060E9C(rdram, ctx);
        goto after_15;
    // 0x80060E00: nop

    after_15:
    // 0x80060E04: b           L_80060E14
    // 0x80060E08: nop

        goto L_80060E14;
    // 0x80060E08: nop

    // 0x80060E0C: b           L_80060E14
    // 0x80060E10: nop

        goto L_80060E14;
    // 0x80060E10: nop

L_80060E14:
    // 0x80060E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060E18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060E1C: jr          $ra
    // 0x80060E20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80060E20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80060E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E24: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80060E28: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80060E2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060E30: beq         $a1, $at, L_80060E64
    if (ctx->r5 == ctx->r1) {
        // 0x80060E34: nop

            goto L_80060E64;
    }
    // 0x80060E34: nop

    // 0x80060E38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060E3C: beq         $a1, $at, L_80060E6C
    if (ctx->r5 == ctx->r1) {
        // 0x80060E40: nop

            goto L_80060E6C;
    }
    // 0x80060E40: nop

    // 0x80060E44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80060E48: beq         $a1, $at, L_80060E74
    if (ctx->r5 == ctx->r1) {
        // 0x80060E4C: nop

            goto L_80060E74;
    }
    // 0x80060E4C: nop

    // 0x80060E50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80060E54: beq         $a1, $at, L_80060E7C
    if (ctx->r5 == ctx->r1) {
        // 0x80060E58: nop

            goto L_80060E7C;
    }
    // 0x80060E58: nop

    // 0x80060E5C: b           L_80060E84
    // 0x80060E60: nop

        goto L_80060E84;
    // 0x80060E60: nop

L_80060E64:
    // 0x80060E64: b           L_80060E94
    // 0x80060E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060E94;
    // 0x80060E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060E6C:
    // 0x80060E6C: b           L_80060E94
    // 0x80060E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060E94;
    // 0x80060E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060E74:
    // 0x80060E74: b           L_80060E94
    // 0x80060E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060E94;
    // 0x80060E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060E7C:
    // 0x80060E7C: b           L_80060E94
    // 0x80060E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80060E94;
    // 0x80060E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060E84:
    // 0x80060E84: b           L_80060E94
    // 0x80060E88: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80060E94;
    // 0x80060E88: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80060E8C: b           L_80060E94
    // 0x80060E90: nop

        goto L_80060E94;
    // 0x80060E90: nop

L_80060E94:
    // 0x80060E94: jr          $ra
    // 0x80060E98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80060E98: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80060E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060EA4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80060EA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060EAC: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80060EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80060EB4: bne         $t6, $at, L_80060EC4
    if (ctx->r14 != ctx->r1) {
        // 0x80060EB8: nop

            goto L_80060EC4;
    }
    // 0x80060EB8: nop

    // 0x80060EBC: b           L_80060FA4
    // 0x80060EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060FA4;
    // 0x80060EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060EC4:
    // 0x80060EC4: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x80060EC8: lui         $t9, 0x809E
    ctx->r25 = S32(0X809E << 16);
    // 0x80060ECC: addiu       $t9, $t9, 0x55E0
    ctx->r25 = ADD32(ctx->r25, 0X55E0);
    // 0x80060ED0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80060ED4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80060ED8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80060EDC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80060EE0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80060EE4: jal         0x800BD1FC
    // 0x80060EE8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80060EE8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_0:
    // 0x80060EEC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80060EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80060EF4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80060EF8: jal         0x800BD218
    // 0x80060EFC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80060EFC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80060F00: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
    // 0x80060F04: nop

    // 0x80060F08: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x80060F0C: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80060F10: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80060F14: nop

    // 0x80060F18: beq         $t2, $zero, L_80060F4C
    if (ctx->r10 == 0) {
        // 0x80060F1C: nop

            goto L_80060F4C;
    }
    // 0x80060F1C: nop

    // 0x80060F20: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80060F24: nop

    // 0x80060F28: jalr        $t9
    // 0x80060F2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80060F2C: nop

    after_2:
    // 0x80060F30: beq         $v0, $zero, L_80060F44
    if (ctx->r2 == 0) {
        // 0x80060F34: nop

            goto L_80060F44;
    }
    // 0x80060F34: nop

    // 0x80060F38: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x80060F3C: b           L_80060FA4
    // 0x80060F40: nop

        goto L_80060FA4;
    // 0x80060F40: nop

L_80060F44:
    // 0x80060F44: b           L_80060F58
    // 0x80060F48: nop

        goto L_80060F58;
    // 0x80060F48: nop

L_80060F4C:
    // 0x80060F4C: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x80060F50: b           L_80060FA4
    // 0x80060F54: nop

        goto L_80060FA4;
    // 0x80060F54: nop

L_80060F58:
    // 0x80060F58: lhu         $t3, 0x2C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2C);
    // 0x80060F5C: nop

    // 0x80060F60: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80060F64: beq         $t4, $zero, L_80060F80
    if (ctx->r12 == 0) {
        // 0x80060F68: nop

            goto L_80060F80;
    }
    // 0x80060F68: nop

    // 0x80060F6C: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80060F70: nop

    // 0x80060F74: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80060F78: b           L_80060F84
    // 0x80060F7C: sh          $t6, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r14;
        goto L_80060F84;
    // 0x80060F7C: sh          $t6, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r14;
L_80060F80:
    // 0x80060F80: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
L_80060F84:
    // 0x80060F84: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x80060F88: nop

    // 0x80060F8C: bne         $t7, $zero, L_80060EC4
    if (ctx->r15 != 0) {
        // 0x80060F90: nop

            goto L_80060EC4;
    }
    // 0x80060F90: nop

    // 0x80060F94: b           L_80060FA4
    // 0x80060F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060FA4;
    // 0x80060F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060F9C: b           L_80060FA4
    // 0x80060FA0: nop

        goto L_80060FA4;
    // 0x80060FA0: nop

L_80060FA4:
    // 0x80060FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060FA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060FAC: jr          $ra
    // 0x80060FB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80060FB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80060FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060FB8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80060FBC: addiu       $t7, $t7, -0x24B0
    ctx->r15 = ADD32(ctx->r15, -0X24B0);
    // 0x80060FC0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80060FC4: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80060FC8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80060FCC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80060FD0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80060FD4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80060FD8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80060FDC: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80060FE0: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80060FE4: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x80060FE8: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80060FEC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80060FF0: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x80060FF4: bne         $at, $zero, L_80061000
    if (ctx->r1 != 0) {
        // 0x80060FF8: nop

            goto L_80061000;
    }
    // 0x80060FF8: nop

    // 0x80060FFC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80061000:
    // 0x80061000: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80061004: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80061008: lw          $t2, 0x4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4);
    // 0x8006100C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80061010: lw          $t4, 0x644($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X644);
    // 0x80061014: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80061018: b           L_80061028
    // 0x8006101C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
        goto L_80061028;
    // 0x8006101C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80061020: b           L_80061028
    // 0x80061024: nop

        goto L_80061028;
    // 0x80061024: nop

L_80061028:
    // 0x80061028: jr          $ra
    // 0x8006102C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006102C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80061030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061030: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80061034: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80061038: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8006103C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061040: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061044: nop

    // 0x80061048: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006104C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80061050: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061054: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061058: nop

    // 0x8006105C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061060: bne         $at, $zero, L_800611D4
    if (ctx->r1 != 0) {
        // 0x80061064: nop

            goto L_800611D4;
    }
    // 0x80061064: nop

L_80061068:
    // 0x80061068: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8006106C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80061070: nop

    // 0x80061074: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061078: bgez        $t2, L_80061088
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006107C: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80061088;
    }
    // 0x8006107C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80061080: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061084: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80061088:
    // 0x80061088: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8006108C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80061090: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061094: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061098: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8006109C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800610A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800610A4: lw          $t4, 0x640($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X640);
    // 0x800610A8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800610AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800610B0: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800610B4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800610B8: nop

    // 0x800610BC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800610C0: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x800610C4: nop

            goto L_800610DC;
    }
    // 0x800610C4: nop

    // 0x800610C8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800610CC: nop

    // 0x800610D0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800610D4: b           L_800611BC
    // 0x800610D8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
        goto L_800611BC;
    // 0x800610D8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_800610DC:
    // 0x800610DC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800610E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800610E4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800610E8: lw          $t7, 0x650($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X650);
    // 0x800610EC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800610F0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800610F4: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x800610F8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800610FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80061100: lh          $t5, 0x0($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X0);
    // 0x80061104: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80061108: nop

    // 0x8006110C: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80061110: beq         $at, $zero, L_8006112C
    if (ctx->r1 == 0) {
        // 0x80061114: nop

            goto L_8006112C;
    }
    // 0x80061114: nop

    // 0x80061118: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8006111C: nop

    // 0x80061120: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80061124: b           L_800611BC
    // 0x80061128: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
        goto L_800611BC;
    // 0x80061128: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
L_8006112C:
    // 0x8006112C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061130: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061134: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80061138: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8006113C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80061140: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80061144: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80061148: lbu         $t8, 0x3($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3);
    // 0x8006114C: nop

    // 0x80061150: slti        $at, $t8, 0xF
    ctx->r1 = SIGNED(ctx->r24) < 0XF ? 1 : 0;
    // 0x80061154: beq         $at, $zero, L_8006118C
    if (ctx->r1 == 0) {
        // 0x80061158: nop

            goto L_8006118C;
    }
    // 0x80061158: nop

    // 0x8006115C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80061160: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80061164: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80061168: lw          $t9, 0x650($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X650);
    // 0x8006116C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80061170: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80061174: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
    // 0x80061178: lbu         $t1, 0x3($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3);
    // 0x8006117C: nop

    // 0x80061180: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80061184: b           L_800611B0
    // 0x80061188: sb          $t2, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r10;
        goto L_800611B0;
    // 0x80061188: sb          $t2, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r10;
L_8006118C:
    // 0x8006118C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80061190: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061194: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061198: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8006119C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800611A0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800611A4: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800611A8: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x800611AC: sb          $t3, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r11;
L_800611B0:
    // 0x800611B0: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800611B4: b           L_800611E4
    // 0x800611B8: nop

        goto L_800611E4;
    // 0x800611B8: nop

L_800611BC:
    // 0x800611BC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800611C0: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800611C4: nop

    // 0x800611C8: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800611CC: beq         $at, $zero, L_80061068
    if (ctx->r1 == 0) {
        // 0x800611D0: nop

            goto L_80061068;
    }
    // 0x800611D0: nop

L_800611D4:
    // 0x800611D4: b           L_800611E4
    // 0x800611D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800611E4;
    // 0x800611D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800611DC: b           L_800611E4
    // 0x800611E0: nop

        goto L_800611E4;
    // 0x800611E0: nop

L_800611E4:
    // 0x800611E4: jr          $ra
    // 0x800611E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800611E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800611EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800611EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800611F0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800611F4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800611F8: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x800611FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061200: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061204: nop

    // 0x80061208: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006120C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80061210: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061214: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061218: nop

    // 0x8006121C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061220: bne         $at, $zero, L_80061330
    if (ctx->r1 != 0) {
        // 0x80061224: nop

            goto L_80061330;
    }
    // 0x80061224: nop

L_80061228:
    // 0x80061228: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8006122C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80061230: nop

    // 0x80061234: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061238: bgez        $t2, L_80061248
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006123C: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80061248;
    }
    // 0x8006123C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80061240: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061244: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80061248:
    // 0x80061248: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8006124C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80061250: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061254: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061258: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8006125C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80061260: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80061264: lw          $t4, 0x640($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X640);
    // 0x80061268: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006126C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80061270: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80061274: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80061278: nop

    // 0x8006127C: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80061280: beq         $at, $zero, L_8006129C
    if (ctx->r1 == 0) {
        // 0x80061284: nop

            goto L_8006129C;
    }
    // 0x80061284: nop

    // 0x80061288: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8006128C: nop

    // 0x80061290: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80061294: b           L_80061318
    // 0x80061298: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
        goto L_80061318;
    // 0x80061298: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_8006129C:
    // 0x8006129C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800612A0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800612A4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800612A8: lw          $t7, 0x650($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X650);
    // 0x800612AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800612B0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800612B4: lw          $t3, 0x640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X640);
    // 0x800612B8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800612BC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800612C0: lh          $t5, 0x0($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X0);
    // 0x800612C4: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800612C8: nop

    // 0x800612CC: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800612D0: beq         $at, $zero, L_800612EC
    if (ctx->r1 == 0) {
        // 0x800612D4: nop

            goto L_800612EC;
    }
    // 0x800612D4: nop

    // 0x800612D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800612DC: nop

    // 0x800612E0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800612E4: b           L_80061318
    // 0x800612E8: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
        goto L_80061318;
    // 0x800612E8: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
L_800612EC:
    // 0x800612EC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800612F0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800612F4: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800612F8: lw          $t2, 0x650($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X650);
    // 0x800612FC: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80061300: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80061304: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80061308: sb          $a0, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r4;
    // 0x8006130C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80061310: b           L_80061340
    // 0x80061314: nop

        goto L_80061340;
    // 0x80061314: nop

L_80061318:
    // 0x80061318: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8006131C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061320: nop

    // 0x80061324: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061328: beq         $at, $zero, L_80061228
    if (ctx->r1 == 0) {
        // 0x8006132C: nop

            goto L_80061228;
    }
    // 0x8006132C: nop

L_80061330:
    // 0x80061330: b           L_80061340
    // 0x80061334: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80061340;
    // 0x80061334: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80061338: b           L_80061340
    // 0x8006133C: nop

        goto L_80061340;
    // 0x8006133C: nop

L_80061340:
    // 0x80061340: jr          $ra
    // 0x80061344: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80061344: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80061348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061348: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006134C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80061350: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80061354: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x80061358: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006135C: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061360: nop

    // 0x80061364: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80061368: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8006136C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061370: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061374: nop

    // 0x80061378: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006137C: bne         $at, $zero, L_80061470
    if (ctx->r1 != 0) {
        // 0x80061380: nop

            goto L_80061470;
    }
    // 0x80061380: nop

L_80061384:
    // 0x80061384: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80061388: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8006138C: nop

    // 0x80061390: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061394: bgez        $t2, L_800613A4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061398: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800613A4;
    }
    // 0x80061398: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8006139C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800613A0: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800613A4:
    // 0x800613A4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800613A8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800613AC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800613B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800613B4: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x800613B8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800613BC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800613C0: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800613C4: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800613C8: nop

    // 0x800613CC: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800613D0: beq         $at, $zero, L_800613EC
    if (ctx->r1 == 0) {
        // 0x800613D4: nop

            goto L_800613EC;
    }
    // 0x800613D4: nop

    // 0x800613D8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800613DC: nop

    // 0x800613E0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800613E4: b           L_80061458
    // 0x800613E8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_80061458;
    // 0x800613E8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_800613EC:
    // 0x800613EC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800613F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800613F4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800613F8: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x800613FC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80061400: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80061404: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80061408: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8006140C: nop

    // 0x80061410: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80061414: beq         $at, $zero, L_80061430
    if (ctx->r1 == 0) {
        // 0x80061418: nop

            goto L_80061430;
    }
    // 0x80061418: nop

    // 0x8006141C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80061420: nop

    // 0x80061424: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80061428: b           L_80061458
    // 0x8006142C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_80061458;
    // 0x8006142C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80061430:
    // 0x80061430: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80061434: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80061438: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006143C: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x80061440: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80061444: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80061448: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x8006144C: lbu         $v0, 0x2($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X2);
    // 0x80061450: b           L_80061480
    // 0x80061454: nop

        goto L_80061480;
    // 0x80061454: nop

L_80061458:
    // 0x80061458: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8006145C: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80061460: nop

    // 0x80061464: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80061468: beq         $at, $zero, L_80061384
    if (ctx->r1 == 0) {
        // 0x8006146C: nop

            goto L_80061384;
    }
    // 0x8006146C: nop

L_80061470:
    // 0x80061470: b           L_80061480
    // 0x80061474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80061480;
    // 0x80061474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80061478: b           L_80061480
    // 0x8006147C: nop

        goto L_80061480;
    // 0x8006147C: nop

L_80061480:
    // 0x80061480: jr          $ra
    // 0x80061484: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80061484: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80061488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061488: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006148C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80061490: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80061494: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x80061498: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006149C: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x800614A0: nop

    // 0x800614A4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800614A8: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800614AC: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800614B0: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800614B4: nop

    // 0x800614B8: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800614BC: bne         $at, $zero, L_800615B0
    if (ctx->r1 != 0) {
        // 0x800614C0: nop

            goto L_800615B0;
    }
    // 0x800614C0: nop

L_800614C4:
    // 0x800614C4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800614C8: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800614CC: nop

    // 0x800614D0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800614D4: bgez        $t2, L_800614E4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800614D8: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800614E4;
    }
    // 0x800614D8: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800614DC: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800614E0: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800614E4:
    // 0x800614E4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800614E8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800614EC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800614F0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800614F4: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x800614F8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800614FC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80061500: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80061504: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061508: nop

    // 0x8006150C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061510: beq         $at, $zero, L_8006152C
    if (ctx->r1 == 0) {
        // 0x80061514: nop

            goto L_8006152C;
    }
    // 0x80061514: nop

    // 0x80061518: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8006151C: nop

    // 0x80061520: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80061524: b           L_80061598
    // 0x80061528: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_80061598;
    // 0x80061528: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_8006152C:
    // 0x8006152C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061530: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80061534: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80061538: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x8006153C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80061540: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80061544: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80061548: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8006154C: nop

    // 0x80061550: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80061554: beq         $at, $zero, L_80061570
    if (ctx->r1 == 0) {
        // 0x80061558: nop

            goto L_80061570;
    }
    // 0x80061558: nop

    // 0x8006155C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80061560: nop

    // 0x80061564: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80061568: b           L_80061598
    // 0x8006156C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_80061598;
    // 0x8006156C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80061570:
    // 0x80061570: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80061574: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80061578: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006157C: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x80061580: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80061584: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80061588: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x8006158C: lbu         $v0, 0x3($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X3);
    // 0x80061590: b           L_800615C0
    // 0x80061594: nop

        goto L_800615C0;
    // 0x80061594: nop

L_80061598:
    // 0x80061598: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8006159C: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800615A0: nop

    // 0x800615A4: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800615A8: beq         $at, $zero, L_800614C4
    if (ctx->r1 == 0) {
        // 0x800615AC: nop

            goto L_800614C4;
    }
    // 0x800615AC: nop

L_800615B0:
    // 0x800615B0: b           L_800615C0
    // 0x800615B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800615C0;
    // 0x800615B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800615B8: b           L_800615C0
    // 0x800615BC: nop

        goto L_800615C0;
    // 0x800615BC: nop

L_800615C0:
    // 0x800615C0: jr          $ra
    // 0x800615C4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800615C4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800615C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800615C8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800615CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800615D0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800615D4: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x800615D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800615DC: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x800615E0: nop

    // 0x800615E4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800615E8: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800615EC: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800615F0: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800615F4: nop

    // 0x800615F8: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800615FC: bne         $at, $zero, L_800616F0
    if (ctx->r1 != 0) {
        // 0x80061600: nop

            goto L_800616F0;
    }
    // 0x80061600: nop

L_80061604:
    // 0x80061604: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80061608: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8006160C: nop

    // 0x80061610: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061614: bgez        $t2, L_80061624
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061618: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80061624;
    }
    // 0x80061618: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8006161C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061620: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80061624:
    // 0x80061624: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x80061628: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8006162C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80061630: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80061634: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x80061638: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8006163C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80061640: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80061644: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061648: nop

    // 0x8006164C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061650: beq         $at, $zero, L_8006166C
    if (ctx->r1 == 0) {
        // 0x80061654: nop

            goto L_8006166C;
    }
    // 0x80061654: nop

    // 0x80061658: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8006165C: nop

    // 0x80061660: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80061664: b           L_800616D8
    // 0x80061668: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_800616D8;
    // 0x80061668: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_8006166C:
    // 0x8006166C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061670: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80061674: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80061678: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x8006167C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80061680: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80061684: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80061688: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8006168C: nop

    // 0x80061690: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80061694: beq         $at, $zero, L_800616B0
    if (ctx->r1 == 0) {
        // 0x80061698: nop

            goto L_800616B0;
    }
    // 0x80061698: nop

    // 0x8006169C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800616A0: nop

    // 0x800616A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800616A8: b           L_800616D8
    // 0x800616AC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_800616D8;
    // 0x800616AC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800616B0:
    // 0x800616B0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800616B4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800616B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800616BC: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x800616C0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800616C4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800616C8: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x800616CC: lbu         $v0, 0x4($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X4);
    // 0x800616D0: b           L_80061700
    // 0x800616D4: nop

        goto L_80061700;
    // 0x800616D4: nop

L_800616D8:
    // 0x800616D8: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800616DC: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800616E0: nop

    // 0x800616E4: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800616E8: beq         $at, $zero, L_80061604
    if (ctx->r1 == 0) {
        // 0x800616EC: nop

            goto L_80061604;
    }
    // 0x800616EC: nop

L_800616F0:
    // 0x800616F0: b           L_80061700
    // 0x800616F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80061700;
    // 0x800616F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800616F8: b           L_80061700
    // 0x800616FC: nop

        goto L_80061700;
    // 0x800616FC: nop

L_80061700:
    // 0x80061700: jr          $ra
    // 0x80061704: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80061704: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80061708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061708: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006170C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80061710: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80061714: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x80061718: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006171C: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061720: nop

    // 0x80061724: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80061728: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8006172C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061730: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80061734: nop

    // 0x80061738: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006173C: bne         $at, $zero, L_80061828
    if (ctx->r1 != 0) {
        // 0x80061740: nop

            goto L_80061828;
    }
    // 0x80061740: nop

L_80061744:
    // 0x80061744: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80061748: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8006174C: nop

    // 0x80061750: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061754: bgez        $t2, L_80061764
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061758: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80061764;
    }
    // 0x80061758: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8006175C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061760: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80061764:
    // 0x80061764: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x80061768: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8006176C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80061770: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80061774: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x80061778: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8006177C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80061780: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80061784: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061788: nop

    // 0x8006178C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061790: beq         $at, $zero, L_800617AC
    if (ctx->r1 == 0) {
        // 0x80061794: nop

            goto L_800617AC;
    }
    // 0x80061794: nop

    // 0x80061798: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8006179C: nop

    // 0x800617A0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800617A4: b           L_80061810
    // 0x800617A8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_80061810;
    // 0x800617A8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_800617AC:
    // 0x800617AC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800617B0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800617B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800617B8: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x800617BC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800617C0: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800617C4: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x800617C8: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x800617CC: nop

    // 0x800617D0: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800617D4: beq         $at, $zero, L_800617F0
    if (ctx->r1 == 0) {
        // 0x800617D8: nop

            goto L_800617F0;
    }
    // 0x800617D8: nop

    // 0x800617DC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800617E0: nop

    // 0x800617E4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800617E8: b           L_80061810
    // 0x800617EC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_80061810;
    // 0x800617EC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800617F0:
    // 0x800617F0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800617F4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800617F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800617FC: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x80061800: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80061804: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80061808: b           L_80061838
    // 0x8006180C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
        goto L_80061838;
    // 0x8006180C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
L_80061810:
    // 0x80061810: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80061814: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80061818: nop

    // 0x8006181C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80061820: beq         $at, $zero, L_80061744
    if (ctx->r1 == 0) {
        // 0x80061824: nop

            goto L_80061744;
    }
    // 0x80061824: nop

L_80061828:
    // 0x80061828: b           L_80061838
    // 0x8006182C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061838;
    // 0x8006182C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061830: b           L_80061838
    // 0x80061834: nop

        goto L_80061838;
    // 0x80061834: nop

L_80061838:
    // 0x80061838: jr          $ra
    // 0x8006183C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006183C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80061840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061840: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80061844: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80061848: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006184C: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x80061850: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061854: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x80061858: nop

    // 0x8006185C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80061860: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80061864: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80061868: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8006186C: nop

    // 0x80061870: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061874: bne         $at, $zero, L_80061978
    if (ctx->r1 != 0) {
        // 0x80061878: nop

            goto L_80061978;
    }
    // 0x80061878: nop

L_8006187C:
    // 0x8006187C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80061880: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80061884: nop

    // 0x80061888: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8006188C: bgez        $t2, L_8006189C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061890: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_8006189C;
    }
    // 0x80061890: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80061894: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061898: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8006189C:
    // 0x8006189C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800618A0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800618A4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800618A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800618AC: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x800618B0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800618B4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800618B8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800618BC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800618C0: nop

    // 0x800618C4: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800618C8: beq         $at, $zero, L_800618E4
    if (ctx->r1 == 0) {
        // 0x800618CC: nop

            goto L_800618E4;
    }
    // 0x800618CC: nop

    // 0x800618D0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800618D4: nop

    // 0x800618D8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800618DC: b           L_80061960
    // 0x800618E0: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_80061960;
    // 0x800618E0: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_800618E4:
    // 0x800618E4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800618E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800618EC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800618F0: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x800618F4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800618F8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800618FC: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80061900: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x80061904: nop

    // 0x80061908: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006190C: beq         $at, $zero, L_80061928
    if (ctx->r1 == 0) {
        // 0x80061910: nop

            goto L_80061928;
    }
    // 0x80061910: nop

    // 0x80061914: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80061918: nop

    // 0x8006191C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80061920: b           L_80061960
    // 0x80061924: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_80061960;
    // 0x80061924: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80061928:
    // 0x80061928: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8006192C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80061930: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80061934: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x80061938: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8006193C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80061940: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80061944: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80061948: subu        $v0, $t2, $t0
    ctx->r2 = SUB32(ctx->r10, ctx->r8);
    // 0x8006194C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80061950: mflo        $t1
    ctx->r9 = lo;
    // 0x80061954: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80061958: b           L_80061988
    // 0x8006195C: nop

        goto L_80061988;
    // 0x8006195C: nop

L_80061960:
    // 0x80061960: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x80061964: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x80061968: nop

    // 0x8006196C: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061970: beq         $at, $zero, L_8006187C
    if (ctx->r1 == 0) {
        // 0x80061974: nop

            goto L_8006187C;
    }
    // 0x80061974: nop

L_80061978:
    // 0x80061978: b           L_80061988
    // 0x8006197C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80061988;
    // 0x8006197C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80061980: b           L_80061988
    // 0x80061984: nop

        goto L_80061988;
    // 0x80061984: nop

L_80061988:
    // 0x80061988: jr          $ra
    // 0x8006198C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006198C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80061990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061990: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80061994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061998: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8006199C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800619A0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800619A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800619A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800619AC: lh          $a0, 0x42($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X42);
    // 0x800619B0: jal         0x80061348
    // 0x800619B4: nop

    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800619B4: nop

    after_0:
    // 0x800619B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800619BC: bne         $v0, $at, L_800619CC
    if (ctx->r2 != ctx->r1) {
        // 0x800619C0: nop

            goto L_800619CC;
    }
    // 0x800619C0: nop

    // 0x800619C4: addiu       $t6, $zero, 0x1387
    ctx->r14 = ADD32(0, 0X1387);
    // 0x800619C8: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
L_800619CC:
    // 0x800619CC: lh          $t7, 0x42($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X42);
    // 0x800619D0: addiu       $at, $zero, 0x64D
    ctx->r1 = ADD32(0, 0X64D);
    // 0x800619D4: bne         $t7, $at, L_80061A00
    if (ctx->r15 != ctx->r1) {
        // 0x800619D8: nop

            goto L_80061A00;
    }
    // 0x800619D8: nop

    // 0x800619DC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800619E0: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800619E4: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x800619E8: nop

    // 0x800619EC: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x800619F0: beq         $t0, $zero, L_80061A00
    if (ctx->r8 == 0) {
        // 0x800619F4: nop

            goto L_80061A00;
    }
    // 0x800619F4: nop

    // 0x800619F8: addiu       $t1, $zero, 0x64E
    ctx->r9 = ADD32(0, 0X64E);
    // 0x800619FC: sh          $t1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r9;
L_80061A00:
    // 0x80061A00: lh          $a0, 0x42($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X42);
    // 0x80061A04: jal         0x80061840
    // 0x80061A08: nop

    func_80061840(rdram, ctx);
        goto after_1;
    // 0x80061A08: nop

    after_1:
    // 0x80061A0C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80061A10: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
    // 0x80061A14: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80061A18: lui         $t3, 0x809E
    ctx->r11 = S32(0X809E << 16);
    // 0x80061A1C: addiu       $t3, $t3, -0xE3C
    ctx->r11 = ADD32(ctx->r11, -0XE3C);
    // 0x80061A20: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80061A24: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80061A28: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80061A2C: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80061A30: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    // 0x80061A34: jal         0x800BD1FC
    // 0x80061A38: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x80061A38: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x80061A3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80061A40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80061A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061A48: jal         0x800BD218
    // 0x80061A4C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x80061A4C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_3:
    // 0x80061A50: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80061A54: lui         $t7, 0x809F
    ctx->r15 = S32(0X809F << 16);
    // 0x80061A58: lbu         $t5, 0x6($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X6);
    // 0x80061A5C: addiu       $t7, $t7, -0x4AB0
    ctx->r15 = ADD32(ctx->r15, -0X4AB0);
    // 0x80061A60: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80061A64: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80061A68: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80061A6C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80061A70: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80061A74: jal         0x800BD1FC
    // 0x80061A78: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x80061A78: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_4:
    // 0x80061A7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80061A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061A84: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80061A88: jal         0x800BD218
    // 0x80061A8C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x80061A8C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x80061A90: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80061A94: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80061A98: lbu         $t9, 0x6($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X6);
    // 0x80061A9C: nop

    // 0x80061AA0: beq         $t9, $at, L_80061AD0
    if (ctx->r25 == ctx->r1) {
        // 0x80061AA4: nop

            goto L_80061AD0;
    }
    // 0x80061AA4: nop

    // 0x80061AA8: lh          $t0, 0x2C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2C);
    // 0x80061AAC: nop

    // 0x80061AB0: beq         $t0, $zero, L_80061AD0
    if (ctx->r8 == 0) {
        // 0x80061AB4: sh          $t0, 0x42($sp)
        MEM_H(0X42, ctx->r29) = ctx->r8;
            goto L_80061AD0;
    }
    // 0x80061AB4: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x80061AB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80061ABC: nop

    // 0x80061AC0: jalr        $t9
    // 0x80061AC4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80061AC4: nop

    after_6:
    // 0x80061AC8: beq         $v0, $zero, L_80061A00
    if (ctx->r2 == 0) {
        // 0x80061ACC: nop

            goto L_80061A00;
    }
    // 0x80061ACC: nop

L_80061AD0:
    // 0x80061AD0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80061AD4: lui         $t4, 0x809E
    ctx->r12 = S32(0X809E << 16);
    // 0x80061AD8: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x80061ADC: addiu       $t4, $t4, 0x7530
    ctx->r12 = ADD32(ctx->r12, 0X7530);
    // 0x80061AE0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80061AE4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80061AE8: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80061AEC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80061AF0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80061AF4: jal         0x800BD1FC
    // 0x80061AF8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_7;
    // 0x80061AF8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_7:
    // 0x80061AFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80061B00: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80061B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061B08: jal         0x800BD218
    // 0x80061B0C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    SysMem_DmaCopy(rdram, ctx);
        goto after_8;
    // 0x80061B0C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_8:
    // 0x80061B10: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80061B14: b           L_80061B24
    // 0x80061B18: nop

        goto L_80061B24;
    // 0x80061B18: nop

    // 0x80061B1C: b           L_80061B24
    // 0x80061B20: nop

        goto L_80061B24;
    // 0x80061B20: nop

L_80061B24:
    // 0x80061B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80061B28: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80061B2C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80061B30: jr          $ra
    // 0x80061B34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80061B34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80061B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061B38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061B3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061B40: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80061B44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061B48: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80061B4C: nop

    // 0x80061B50: bltz        $t6, L_80061D08
    if (SIGNED(ctx->r14) < 0) {
        // 0x80061B54: nop

            goto L_80061D08;
    }
    // 0x80061B54: nop

L_80061B58:
    // 0x80061B58: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x80061B5C: lui         $t9, 0x809E
    ctx->r25 = S32(0X809E << 16);
    // 0x80061B60: addiu       $t9, $t9, -0x44B4
    ctx->r25 = ADD32(ctx->r25, -0X44B4);
    // 0x80061B64: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80061B68: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80061B6C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061B70: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80061B74: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x80061B78: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80061B7C: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80061B80: jal         0x800BD1FC
    // 0x80061B84: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80061B84: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_0:
    // 0x80061B88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80061B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061B90: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80061B94: jal         0x800BD218
    // 0x80061B98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80061B98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80061B9C: lbu         $t1, 0x2C($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2C);
    // 0x80061BA0: nop

    // 0x80061BA4: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80061BA8: sb          $t2, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r10;
    // 0x80061BAC: lbu         $s0, 0x29($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X29);
    // 0x80061BB0: nop

    // 0x80061BB4: beq         $s0, $zero, L_80061BD0
    if (ctx->r16 == 0) {
        // 0x80061BB8: nop

            goto L_80061BD0;
    }
    // 0x80061BB8: nop

    // 0x80061BBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80061BC0: beq         $s0, $at, L_80061BF0
    if (ctx->r16 == ctx->r1) {
        // 0x80061BC4: nop

            goto L_80061BF0;
    }
    // 0x80061BC4: nop

    // 0x80061BC8: b           L_80061C10
    // 0x80061BCC: nop

        goto L_80061C10;
    // 0x80061BCC: nop

L_80061BD0:
    // 0x80061BD0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061BD4: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80061BD8: nop

    // 0x80061BDC: lh          $t4, 0x38($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X38);
    // 0x80061BE0: nop

    // 0x80061BE4: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    // 0x80061BE8: b           L_80061C18
    // 0x80061BEC: nop

        goto L_80061C18;
    // 0x80061BEC: nop

L_80061BF0:
    // 0x80061BF0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80061BF4: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80061BF8: nop

    // 0x80061BFC: lh          $t6, 0x3A($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X3A);
    // 0x80061C00: nop

    // 0x80061C04: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x80061C08: b           L_80061C18
    // 0x80061C0C: nop

        goto L_80061C18;
    // 0x80061C0C: nop

L_80061C10:
    // 0x80061C10: addiu       $t8, $zero, 0x3E7
    ctx->r24 = ADD32(0, 0X3E7);
    // 0x80061C14: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
L_80061C18:
    // 0x80061C18: lbu         $t9, 0x29($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X29);
    // 0x80061C1C: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80061C20: bne         $t9, $at, L_80061C48
    if (ctx->r25 != ctx->r1) {
        // 0x80061C24: nop

            goto L_80061C48;
    }
    // 0x80061C24: nop

    // 0x80061C28: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80061C2C: lw          $t7, 0x718C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X718C);
    // 0x80061C30: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
    // 0x80061C34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80061C38: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80061C3C: sw          $t1, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r9;
    // 0x80061C40: b           L_80061CF4
    // 0x80061C44: nop

        goto L_80061CF4;
    // 0x80061C44: nop

L_80061C48:
    // 0x80061C48: lbu         $t3, 0x29($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X29);
    // 0x80061C4C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80061C50: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80061C54: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80061C58: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80061C5C: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80061C60: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x80061C64: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80061C68: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80061C6C: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
    // 0x80061C70: lbu         $t0, 0x29($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X29);
    // 0x80061C74: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80061C78: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80061C7C: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x80061C80: lh          $t2, 0x0($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X0);
    // 0x80061C84: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x80061C88: nop

    // 0x80061C8C: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80061C90: bne         $at, $zero, L_80061CB8
    if (ctx->r1 != 0) {
        // 0x80061C94: nop

            goto L_80061CB8;
    }
    // 0x80061C94: nop

    // 0x80061C98: lbu         $t9, 0x29($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X29);
    // 0x80061C9C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80061CA0: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80061CA4: lh          $t6, 0x2A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A);
    // 0x80061CA8: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80061CAC: addu        $t0, $t8, $t5
    ctx->r8 = ADD32(ctx->r24, ctx->r13);
    // 0x80061CB0: b           L_80061CF4
    // 0x80061CB4: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
        goto L_80061CF4;
    // 0x80061CB4: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
L_80061CB8:
    // 0x80061CB8: lbu         $t1, 0x29($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X29);
    // 0x80061CBC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80061CC0: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80061CC4: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80061CC8: addu        $t2, $t7, $t3
    ctx->r10 = ADD32(ctx->r15, ctx->r11);
    // 0x80061CCC: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80061CD0: nop

    // 0x80061CD4: bgez        $t4, L_80061CF4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80061CD8: nop

            goto L_80061CF4;
    }
    // 0x80061CD8: nop

    // 0x80061CDC: lbu         $t8, 0x29($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X29);
    // 0x80061CE0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80061CE4: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80061CE8: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80061CEC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80061CF0: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
L_80061CF4:
    // 0x80061CF4: lbu         $t0, 0x2C($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2C);
    // 0x80061CF8: nop

    // 0x80061CFC: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80061D00: bne         $t1, $zero, L_80061B58
    if (ctx->r9 != 0) {
        // 0x80061D04: nop

            goto L_80061B58;
    }
    // 0x80061D04: nop

L_80061D08:
    // 0x80061D08: b           L_80061D10
    // 0x80061D0C: nop

        goto L_80061D10;
    // 0x80061D0C: nop

L_80061D10:
    // 0x80061D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80061D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061D18: jr          $ra
    // 0x80061D1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80061D1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80061D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061D20: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061D24: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061D28: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80061D2C: nop

    // 0x80061D30: lh          $t7, 0x30($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X30);
    // 0x80061D34: nop

    // 0x80061D38: slti        $at, $t7, 0x1F4
    ctx->r1 = SIGNED(ctx->r15) < 0X1F4 ? 1 : 0;
    // 0x80061D3C: beq         $at, $zero, L_80061D80
    if (ctx->r1 == 0) {
        // 0x80061D40: nop

            goto L_80061D80;
    }
    // 0x80061D40: nop

    // 0x80061D44: lh          $t8, 0x32($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X32);
    // 0x80061D48: nop

    // 0x80061D4C: slti        $at, $t8, 0x1F4
    ctx->r1 = SIGNED(ctx->r24) < 0X1F4 ? 1 : 0;
    // 0x80061D50: beq         $at, $zero, L_80061D80
    if (ctx->r1 == 0) {
        // 0x80061D54: nop

            goto L_80061D80;
    }
    // 0x80061D54: nop

    // 0x80061D58: lh          $t9, 0x34($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X34);
    // 0x80061D5C: nop

    // 0x80061D60: slti        $at, $t9, 0x1F4
    ctx->r1 = SIGNED(ctx->r25) < 0X1F4 ? 1 : 0;
    // 0x80061D64: beq         $at, $zero, L_80061D80
    if (ctx->r1 == 0) {
        // 0x80061D68: nop

            goto L_80061D80;
    }
    // 0x80061D68: nop

    // 0x80061D6C: lh          $t0, 0x36($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X36);
    // 0x80061D70: nop

    // 0x80061D74: slti        $at, $t0, 0x1F4
    ctx->r1 = SIGNED(ctx->r8) < 0X1F4 ? 1 : 0;
    // 0x80061D78: bne         $at, $zero, L_80061DFC
    if (ctx->r1 != 0) {
        // 0x80061D7C: nop

            goto L_80061DFC;
    }
    // 0x80061D7C: nop

L_80061D80:
    // 0x80061D80: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x80061D84: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x80061D88: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80061D8C: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_80061D90:
    // 0x80061D90: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061D94: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80061D98: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80061D9C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80061DA0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80061DA4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80061DA8: addu        $t0, $t3, $t6
    ctx->r8 = ADD32(ctx->r11, ctx->r14);
    // 0x80061DAC: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80061DB0: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061DB4: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80061DB8: nop

    // 0x80061DBC: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80061DC0: beq         $at, $zero, L_80061DD8
    if (ctx->r1 == 0) {
        // 0x80061DC4: nop

            goto L_80061DD8;
    }
    // 0x80061DC4: nop

    // 0x80061DC8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061DCC: nop

    // 0x80061DD0: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80061DD4: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
L_80061DD8:
    // 0x80061DD8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80061DDC: nop

    // 0x80061DE0: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80061DE4: slti        $at, $t7, 0x1B
    ctx->r1 = SIGNED(ctx->r15) < 0X1B ? 1 : 0;
    // 0x80061DE8: bne         $at, $zero, L_80061D90
    if (ctx->r1 != 0) {
        // 0x80061DEC: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80061D90;
    }
    // 0x80061DEC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80061DF0: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80061DF4: b           L_80061E0C
    // 0x80061DF8: nop

        goto L_80061E0C;
    // 0x80061DF8: nop

L_80061DFC:
    // 0x80061DFC: b           L_80061E0C
    // 0x80061E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061E0C;
    // 0x80061E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061E04: b           L_80061E0C
    // 0x80061E08: nop

        goto L_80061E0C;
    // 0x80061E08: nop

L_80061E0C:
    // 0x80061E0C: jr          $ra
    // 0x80061E10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80061E10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80061E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E14: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061E18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061E1C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80061E20: nop

    // 0x80061E24: lh          $t7, 0x30($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X30);
    // 0x80061E28: nop

    // 0x80061E2C: slti        $at, $t7, 0x2BC
    ctx->r1 = SIGNED(ctx->r15) < 0X2BC ? 1 : 0;
    // 0x80061E30: beq         $at, $zero, L_80061E74
    if (ctx->r1 == 0) {
        // 0x80061E34: nop

            goto L_80061E74;
    }
    // 0x80061E34: nop

    // 0x80061E38: lh          $t8, 0x32($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X32);
    // 0x80061E3C: nop

    // 0x80061E40: slti        $at, $t8, 0x2BC
    ctx->r1 = SIGNED(ctx->r24) < 0X2BC ? 1 : 0;
    // 0x80061E44: beq         $at, $zero, L_80061E74
    if (ctx->r1 == 0) {
        // 0x80061E48: nop

            goto L_80061E74;
    }
    // 0x80061E48: nop

    // 0x80061E4C: lh          $t9, 0x34($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X34);
    // 0x80061E50: nop

    // 0x80061E54: slti        $at, $t9, 0x2BC
    ctx->r1 = SIGNED(ctx->r25) < 0X2BC ? 1 : 0;
    // 0x80061E58: beq         $at, $zero, L_80061E74
    if (ctx->r1 == 0) {
        // 0x80061E5C: nop

            goto L_80061E74;
    }
    // 0x80061E5C: nop

    // 0x80061E60: lh          $t0, 0x36($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X36);
    // 0x80061E64: nop

    // 0x80061E68: slti        $at, $t0, 0x2BC
    ctx->r1 = SIGNED(ctx->r8) < 0X2BC ? 1 : 0;
    // 0x80061E6C: bne         $at, $zero, L_80061EF0
    if (ctx->r1 != 0) {
        // 0x80061E70: nop

            goto L_80061EF0;
    }
    // 0x80061E70: nop

L_80061E74:
    // 0x80061E74: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x80061E78: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x80061E7C: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80061E80: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_80061E84:
    // 0x80061E84: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061E88: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80061E8C: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80061E90: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80061E94: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80061E98: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80061E9C: addu        $t0, $t3, $t6
    ctx->r8 = ADD32(ctx->r11, ctx->r14);
    // 0x80061EA0: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80061EA4: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061EA8: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80061EAC: nop

    // 0x80061EB0: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80061EB4: beq         $at, $zero, L_80061ECC
    if (ctx->r1 == 0) {
        // 0x80061EB8: nop

            goto L_80061ECC;
    }
    // 0x80061EB8: nop

    // 0x80061EBC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061EC0: nop

    // 0x80061EC4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80061EC8: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
L_80061ECC:
    // 0x80061ECC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80061ED0: nop

    // 0x80061ED4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80061ED8: slti        $at, $t7, 0x1B
    ctx->r1 = SIGNED(ctx->r15) < 0X1B ? 1 : 0;
    // 0x80061EDC: bne         $at, $zero, L_80061E84
    if (ctx->r1 != 0) {
        // 0x80061EE0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80061E84;
    }
    // 0x80061EE0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80061EE4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80061EE8: b           L_80061F00
    // 0x80061EEC: nop

        goto L_80061F00;
    // 0x80061EEC: nop

L_80061EF0:
    // 0x80061EF0: b           L_80061F00
    // 0x80061EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061F00;
    // 0x80061EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061EF8: b           L_80061F00
    // 0x80061EFC: nop

        goto L_80061F00;
    // 0x80061EFC: nop

L_80061F00:
    // 0x80061F00: jr          $ra
    // 0x80061F04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80061F04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
