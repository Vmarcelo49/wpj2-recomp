#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80073984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073984: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073988: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007398C: nop

    // 0x80073990: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80073994: nop

    // 0x80073998: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007399C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800739A0: jr          $ra
    // 0x800739A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800739A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800739A8: jr          $ra
    // 0x800739AC: nop

    return;
    // 0x800739AC: nop

    // 0x800739B0: jr          $ra
    // 0x800739B4: nop

    return;
    // 0x800739B4: nop

;}
RECOMP_FUNC void func_80068FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068FEC: jal         0x80061348
    // 0x80068FF0: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80068FF0: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    after_0:
    // 0x80068FF4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80068FF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068FFC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069000: beq         $v0, $zero, L_8006901C
    if (ctx->r2 == 0) {
        // 0x80069004: nop
    
            goto L_8006901C;
    }
    // 0x80069004: nop

    // 0x80069008: jal         0x80061348
    // 0x8006900C: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006900C: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    after_1:
    // 0x80069010: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069014: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069018: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006901C:
    // 0x8006901C: b           L_8006902C
    // 0x80069020: nop

        goto L_8006902C;
    // 0x80069020: nop

    // 0x80069024: b           L_8006902C
    // 0x80069028: nop

        goto L_8006902C;
    // 0x80069028: nop

L_8006902C:
    // 0x8006902C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069034: jr          $ra
    // 0x80069038: nop

    return;
    // 0x80069038: nop

;}
RECOMP_FUNC void func_80077484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007748C: jal         0x80061348
    // 0x80077490: addiu       $a0, $zero, 0x493
    ctx->r4 = ADD32(0, 0X493);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80077490: addiu       $a0, $zero, 0x493
    ctx->r4 = ADD32(0, 0X493);
    after_0:
    // 0x80077494: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077498: b           L_800774A8
    // 0x8007749C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800774A8;
    // 0x8007749C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800774A0: b           L_800774A8
    // 0x800774A4: nop

        goto L_800774A8;
    // 0x800774A4: nop

L_800774A8:
    // 0x800774A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800774AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800774B0: jr          $ra
    // 0x800774B4: nop

    return;
    // 0x800774B4: nop

;}
RECOMP_FUNC void func_80068EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068EB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068EB4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068EB8: nop

    // 0x80068EBC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068EC0: nop

    // 0x80068EC4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068EC8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068ECC: jr          $ra
    // 0x80068ED0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068ED0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068ED4: jr          $ra
    // 0x80068ED8: nop

    return;
    // 0x80068ED8: nop

    // 0x80068EDC: jr          $ra
    // 0x80068EE0: nop

    return;
    // 0x80068EE0: nop

;}
RECOMP_FUNC void func_8008A368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A368: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8008A36C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8008A370: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8008A374: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8008A378: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8008A37C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8008A380: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x8008A384: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8008A388: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008A38C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008A390: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008A394: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008A398: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008A39C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8008A3A0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008A3A4: swc1        $f6, 0x274($t8)
    MEM_W(0X274, ctx->r24) = ctx->f6.u32l;
    // 0x8008A3A8: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8008A3AC: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x8008A3B0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008A3B4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8008A3B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008A3BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008A3C0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8008A3C4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8008A3C8: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8008A3CC: swc1        $f10, 0x278($t1)
    MEM_W(0X278, ctx->r9) = ctx->f10.u32l;
    // 0x8008A3D0: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x8008A3D4: subu        $t2, $a3, $a1
    ctx->r10 = SUB32(ctx->r7, ctx->r5);
    // 0x8008A3D8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8008A3DC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008A3E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A3E4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008A3E8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8008A3EC: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8008A3F0: sh          $t2, 0x2A8($t5)
    MEM_H(0X2A8, ctx->r13) = ctx->r10;
    // 0x8008A3F4: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x8008A3F8: lh          $t6, 0x12($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X12);
    // 0x8008A3FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008A400: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008A404: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A408: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008A40C: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8008A410: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8008A414: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x8008A418: sh          $t7, 0x2AA($t0)
    MEM_H(0X2AA, ctx->r8) = ctx->r15;
    // 0x8008A41C: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x8008A420: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8008A424: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8008A428: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8008A42C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008A430: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8008A434: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8008A438: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8008A43C: lw          $t2, 0x268($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X268);
    // 0x8008A440: addu        $t6, $a0, $t3
    ctx->r14 = ADD32(ctx->r4, ctx->r11);
    // 0x8008A444: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x8008A448: sw          $t5, 0x268($t6)
    MEM_W(0X268, ctx->r14) = ctx->r13;
    // 0x8008A44C: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x8008A450: nop

    // 0x8008A454: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8008A458: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8008A45C: jr          $ra
    // 0x8008A460: nop

    return;
    // 0x8008A460: nop

    // 0x8008A464: jr          $ra
    // 0x8008A468: nop

    return;
    // 0x8008A468: nop

;}
RECOMP_FUNC void func_80065880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065880: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065884: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065888: nop

    // 0x8006588C: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x80065890: nop

    // 0x80065894: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065898: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006589C: jr          $ra
    // 0x800658A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800658A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800658A4: jr          $ra
    // 0x800658A8: nop

    return;
    // 0x800658A8: nop

    // 0x800658AC: jr          $ra
    // 0x800658B0: nop

    return;
    // 0x800658B0: nop

;}
RECOMP_FUNC void func_80077D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077D74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077D78: nop

    // 0x80077D7C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80077D80: nop

    // 0x80077D84: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80077D88: jr          $ra
    // 0x80077D8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077D8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077D90: jr          $ra
    // 0x80077D94: nop

    return;
    // 0x80077D94: nop

    // 0x80077D98: jr          $ra
    // 0x80077D9C: nop

    return;
    // 0x80077D9C: nop

;}
RECOMP_FUNC void func_800228A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800228AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800228B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800228B4: lbu         $t6, 0x11AE($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X11AE);
    // 0x800228B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800228BC: bne         $t6, $at, L_80022900
    if (ctx->r14 != ctx->r1) {
        // 0x800228C0: nop
    
            goto L_80022900;
    }
    // 0x800228C0: nop

    // 0x800228C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800228C8: lw          $t7, 0x307C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X307C);
    // 0x800228CC: nop

    // 0x800228D0: beq         $t7, $zero, L_80022900
    if (ctx->r15 == 0) {
        // 0x800228D4: nop
    
            goto L_80022900;
    }
    // 0x800228D4: nop

    // 0x800228D8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800228DC: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x800228E0: jal         0x8002C270
    // 0x800228E4: nop

    func_8002C270(rdram, ctx);
        goto after_0;
    // 0x800228E4: nop

    after_0:
    // 0x800228E8: jal         0x800B0E08
    // 0x800228EC: nop

    func_800B0E08(rdram, ctx);
        goto after_1;
    // 0x800228EC: nop

    after_1:
    // 0x800228F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800228F4: sb          $zero, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = 0;
    // 0x800228F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800228FC: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_80022900:
    // 0x80022900: b           L_80022908
    // 0x80022904: nop

        goto L_80022908;
    // 0x80022904: nop

L_80022908:
    // 0x80022908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002290C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022910: jr          $ra
    // 0x80022914: nop

    return;
    // 0x80022914: nop

;}
RECOMP_FUNC void func_80064A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064A70: jal         0x80061488
    // 0x80064A74: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064A74: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064A78: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064A7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064A80: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064A84: nop
    
            goto L_80064B14;
    }
    // 0x80064A84: nop

    // 0x80064A88: jal         0x80061488
    // 0x80064A8C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064A8C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064A90: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064A98: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064A9C: nop
    
            goto L_80064B14;
    }
    // 0x80064A9C: nop

    // 0x80064AA0: jal         0x80061488
    // 0x80064AA4: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064AA4: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x80064AA8: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064AAC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064AB0: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064AB4: nop
    
            goto L_80064B14;
    }
    // 0x80064AB4: nop

    // 0x80064AB8: jal         0x80061488
    // 0x80064ABC: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x80064ABC: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064AC0: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064AC4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80064AC8: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064ACC: nop
    
            goto L_80064B14;
    }
    // 0x80064ACC: nop

    // 0x80064AD0: jal         0x80061488
    // 0x80064AD4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064AD4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x80064AD8: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064ADC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80064AE0: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064AE4: nop
    
            goto L_80064B14;
    }
    // 0x80064AE4: nop

    // 0x80064AE8: jal         0x8005F064
    // 0x80064AEC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x80064AEC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x80064AF0: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80064AF4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064AF8: beq         $v0, $zero, L_80064B14
    if (ctx->r2 == 0) {
        // 0x80064AFC: nop
    
            goto L_80064B14;
    }
    // 0x80064AFC: nop

    // 0x80064B00: jal         0x80061348
    // 0x80064B04: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x80064B04: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x80064B08: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064B0C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80064B10: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064B14:
    // 0x80064B14: b           L_80064B24
    // 0x80064B18: nop

        goto L_80064B24;
    // 0x80064B18: nop

    // 0x80064B1C: b           L_80064B24
    // 0x80064B20: nop

        goto L_80064B24;
    // 0x80064B20: nop

L_80064B24:
    // 0x80064B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064B2C: jr          $ra
    // 0x80064B30: nop

    return;
    // 0x80064B30: nop

;}
RECOMP_FUNC void func_80074164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007416C: jal         0x80061348
    // 0x80074170: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074170: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x80074174: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074178: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007417C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074180: beq         $v0, $zero, L_8007419C
    if (ctx->r2 == 0) {
        // 0x80074184: nop
    
            goto L_8007419C;
    }
    // 0x80074184: nop

    // 0x80074188: jal         0x80061348
    // 0x8007418C: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007418C: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074190: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074194: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074198: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8007419C:
    // 0x8007419C: b           L_800741AC
    // 0x800741A0: nop

        goto L_800741AC;
    // 0x800741A0: nop

    // 0x800741A4: b           L_800741AC
    // 0x800741A8: nop

        goto L_800741AC;
    // 0x800741A8: nop

L_800741AC:
    // 0x800741AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800741B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800741B4: jr          $ra
    // 0x800741B8: nop

    return;
    // 0x800741B8: nop

;}
RECOMP_FUNC void func_8000BDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BDDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000BDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BDE4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000BDE8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8000BDEC: nop

    // 0x8000BDF0: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000BDF4: nop

    // 0x8000BDF8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8000BDFC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BE00: nop

    // 0x8000BE04: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000BE08: nop

    // 0x8000BE0C: beq         $t9, $zero, L_8000BE4C
    if (ctx->r25 == 0) {
        // 0x8000BE10: nop
    
            goto L_8000BE4C;
    }
    // 0x8000BE10: nop

    // 0x8000BE14: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BE18: nop

    // 0x8000BE1C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000BE20: nop

    // 0x8000BE24: lw          $t2, 0x1A0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A0);
    // 0x8000BE28: nop

    // 0x8000BE2C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8000BE30: beq         $t3, $zero, L_8000BE4C
    if (ctx->r11 == 0) {
        // 0x8000BE34: nop
    
            goto L_8000BE4C;
    }
    // 0x8000BE34: nop

    // 0x8000BE38: andi        $t4, $t2, 0x8
    ctx->r12 = ctx->r10 & 0X8;
    // 0x8000BE3C: bne         $t4, $zero, L_8000BE4C
    if (ctx->r12 != 0) {
        // 0x8000BE40: nop
    
            goto L_8000BE4C;
    }
    // 0x8000BE40: nop

    // 0x8000BE44: b           L_8000C3A0
    // 0x8000BE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C3A0;
    // 0x8000BE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BE4C:
    // 0x8000BE4C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BE50: nop

    // 0x8000BE54: lhu         $t6, 0x14($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X14);
    // 0x8000BE58: nop

    // 0x8000BE5C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000BE60: bne         $t7, $zero, L_8000BF5C
    if (ctx->r15 != 0) {
        // 0x8000BE64: nop
    
            goto L_8000BF5C;
    }
    // 0x8000BE64: nop

    // 0x8000BE68: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000BE6C: lh          $t8, -0x73C0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X73C0);
    // 0x8000BE70: nop

    // 0x8000BE74: bltz        $t8, L_8000BF10
    if (SIGNED(ctx->r24) < 0) {
        // 0x8000BE78: nop
    
            goto L_8000BF10;
    }
    // 0x8000BE78: nop

    // 0x8000BE7C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000BE80: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8000BE84: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8000BE88: nop

    // 0x8000BE8C: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x8000BE90: bne         $t1, $zero, L_8000BEC4
    if (ctx->r9 != 0) {
        // 0x8000BE94: nop
    
            goto L_8000BEC4;
    }
    // 0x8000BE94: nop

    // 0x8000BE98: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000BE9C: lh          $a1, -0x73C0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73C0);
    // 0x8000BEA0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BEA4: jal         0x8000C584
    // 0x8000BEA8: nop

    func_8000C584(rdram, ctx);
        goto after_0;
    // 0x8000BEA8: nop

    after_0:
    // 0x8000BEAC: bgez        $v0, L_8000BEBC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BEB0: nop
    
            goto L_8000BEBC;
    }
    // 0x8000BEB0: nop

    // 0x8000BEB4: b           L_8000C3A0
    // 0x8000BEB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000C3A0;
    // 0x8000BEB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000BEBC:
    // 0x8000BEBC: b           L_8000BF08
    // 0x8000BEC0: nop

        goto L_8000BF08;
    // 0x8000BEC0: nop

L_8000BEC4:
    // 0x8000BEC4: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000BEC8: lh          $a1, -0x73C0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73C0);
    // 0x8000BECC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BED0: jal         0x8000C584
    // 0x8000BED4: nop

    func_8000C584(rdram, ctx);
        goto after_1;
    // 0x8000BED4: nop

    after_1:
    // 0x8000BED8: bgez        $v0, L_8000BEF8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BEDC: nop
    
            goto L_8000BEF8;
    }
    // 0x8000BEDC: nop

    // 0x8000BEE0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000BEE4: lh          $t3, -0x73C0($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X73C0);
    // 0x8000BEE8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000BEEC: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8000BEF0: b           L_8000BF00
    // 0x8000BEF4: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
        goto L_8000BF00;
    // 0x8000BEF4: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
L_8000BEF8:
    // 0x8000BEF8: b           L_8000BF08
    // 0x8000BEFC: nop

        goto L_8000BF08;
    // 0x8000BEFC: nop

L_8000BF00:
    // 0x8000BF00: b           L_8000BEC4
    // 0x8000BF04: nop

        goto L_8000BEC4;
    // 0x8000BF04: nop

L_8000BF08:
    // 0x8000BF08: b           L_8000BF2C
    // 0x8000BF0C: nop

        goto L_8000BF2C;
    // 0x8000BF0C: nop

L_8000BF10:
    // 0x8000BF10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF14: jal         0x8000C778
    // 0x8000BF18: nop

    func_8000C778(rdram, ctx);
        goto after_2;
    // 0x8000BF18: nop

    after_2:
    // 0x8000BF1C: bgez        $v0, L_8000BF2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BF20: nop
    
            goto L_8000BF2C;
    }
    // 0x8000BF20: nop

    // 0x8000BF24: b           L_8000C3A0
    // 0x8000BF28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000C3A0;
    // 0x8000BF28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000BF2C:
    // 0x8000BF2C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF30: nop

    // 0x8000BF34: lhu         $t5, 0x14($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X14);
    // 0x8000BF38: nop

    // 0x8000BF3C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8000BF40: sh          $t6, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r14;
    // 0x8000BF44: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF48: nop

    // 0x8000BF4C: lhu         $t8, 0x14($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X14);
    // 0x8000BF50: nop

    // 0x8000BF54: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8000BF58: sh          $t9, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r25;
L_8000BF5C:
    // 0x8000BF5C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF60: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x8000BF64: lh          $t1, 0x1C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X1C);
    // 0x8000BF68: nop

    // 0x8000BF6C: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
    // 0x8000BF70: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF74: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x8000BF78: lh          $t5, 0x1E($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X1E);
    // 0x8000BF7C: nop

    // 0x8000BF80: sh          $t5, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r13;
    // 0x8000BF84: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF88: jal         0x8000CC44
    // 0x8000BF8C: nop

    func_8000CC44(rdram, ctx);
        goto after_3;
    // 0x8000BF8C: nop

    after_3:
    // 0x8000BF90: bgez        $v0, L_8000C0DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BF94: nop
    
            goto L_8000C0DC;
    }
    // 0x8000BF94: nop

    // 0x8000BF98: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8000BF9C: nop

    // 0x8000BFA0: lw          $t8, 0x20C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X20C);
    // 0x8000BFA4: nop

    // 0x8000BFA8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8000BFAC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BFB0: nop

    // 0x8000BFB4: beq         $t9, $zero, L_8000BFEC
    if (ctx->r25 == 0) {
        // 0x8000BFB8: nop
    
            goto L_8000BFEC;
    }
    // 0x8000BFB8: nop

    // 0x8000BFBC: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8000BFC0: nop

    // 0x8000BFC4: beq         $t7, $zero, L_8000BFEC
    if (ctx->r15 == 0) {
        // 0x8000BFC8: nop
    
            goto L_8000BFEC;
    }
    // 0x8000BFC8: nop

    // 0x8000BFCC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BFD0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000BFD4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000BFD8: nop

    // 0x8000BFDC: lw          $t3, 0x1A0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X1A0);
    // 0x8000BFE0: nop

    // 0x8000BFE4: and         $t2, $t3, $at
    ctx->r10 = ctx->r11 & ctx->r1;
    // 0x8000BFE8: sw          $t2, 0x1A0($t1)
    MEM_W(0X1A0, ctx->r9) = ctx->r10;
L_8000BFEC:
    // 0x8000BFEC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000BFF0: lw          $a0, -0x2828($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2828);
    // 0x8000BFF4: jal         0x800BCCE4
    // 0x8000BFF8: nop

    func_800BCCE4(rdram, ctx);
        goto after_4;
    // 0x8000BFF8: nop

    after_4:
    // 0x8000BFFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000C000: sw          $zero, -0x2828($at)
    MEM_W(-0X2828, ctx->r1) = 0;
    // 0x8000C004: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000C008: lw          $t5, 0x3070($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3070);
    // 0x8000C00C: nop

    // 0x8000C010: beq         $t5, $zero, L_8000C030
    if (ctx->r13 == 0) {
        // 0x8000C014: nop
    
            goto L_8000C030;
    }
    // 0x8000C014: nop

    // 0x8000C018: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C01C: lw          $a0, 0x3070($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3070);
    // 0x8000C020: jal         0x800BCCE4
    // 0x8000C024: nop

    func_800BCCE4(rdram, ctx);
        goto after_5;
    // 0x8000C024: nop

    after_5:
    // 0x8000C028: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C02C: sw          $zero, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = 0;
L_8000C030:
    // 0x8000C030: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8000C034: lw          $t6, 0x3078($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3078);
    // 0x8000C038: nop

    // 0x8000C03C: beq         $t6, $zero, L_8000C05C
    if (ctx->r14 == 0) {
        // 0x8000C040: nop
    
            goto L_8000C05C;
    }
    // 0x8000C040: nop

    // 0x8000C044: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C048: lw          $a0, 0x3078($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3078);
    // 0x8000C04C: jal         0x800BCCE4
    // 0x8000C050: nop

    func_800BCCE4(rdram, ctx);
        goto after_6;
    // 0x8000C050: nop

    after_6:
    // 0x8000C054: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C058: sw          $zero, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = 0;
L_8000C05C:
    // 0x8000C05C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8000C060: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000C064: lw          $t8, 0x1A0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1A0);
    // 0x8000C068: nop

    // 0x8000C06C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000C070: sw          $t9, 0x1A0($t4)
    MEM_W(0X1A0, ctx->r12) = ctx->r25;
    // 0x8000C074: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8000C078: nop

    // 0x8000C07C: lw          $t0, 0x1A0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X1A0);
    // 0x8000C080: nop

    // 0x8000C084: ori         $t3, $t0, 0x8
    ctx->r11 = ctx->r8 | 0X8;
    // 0x8000C088: sw          $t3, 0x1A0($t7)
    MEM_W(0X1A0, ctx->r15) = ctx->r11;
    // 0x8000C08C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000C090: nop

    // 0x8000C094: lw          $t1, 0x1A8($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X1A8);
    // 0x8000C098: nop

    // 0x8000C09C: ori         $t5, $t1, 0x1
    ctx->r13 = ctx->r9 | 0X1;
    // 0x8000C0A0: sw          $t5, 0x1A8($t2)
    MEM_W(0X1A8, ctx->r10) = ctx->r13;
    // 0x8000C0A4: jal         0x80016264
    // 0x8000C0A8: nop

    func_80016264(rdram, ctx);
        goto after_7;
    // 0x8000C0A8: nop

    after_7:
    // 0x8000C0AC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000C0B0: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000C0B4: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x8000C0B8: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8000C0BC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000C0C0: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x8000C0C4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000C0C8: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000C0CC: lhu         $t0, 0x6($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0X6);
    // 0x8000C0D0: nop

    // 0x8000C0D4: ori         $t3, $t0, 0x4000
    ctx->r11 = ctx->r8 | 0X4000;
    // 0x8000C0D8: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
L_8000C0DC:
    // 0x8000C0DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C0E0: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x8000C0E4: lh          $t2, 0x0($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X0);
    // 0x8000C0E8: lh          $t1, 0x1C($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X1C);
    // 0x8000C0EC: nop

    // 0x8000C0F0: bne         $t1, $t2, L_8000C128
    if (ctx->r9 != ctx->r10) {
        // 0x8000C0F4: nop
    
            goto L_8000C128;
    }
    // 0x8000C0F4: nop

    // 0x8000C0F8: lh          $t8, 0x1E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X1E);
    // 0x8000C0FC: lh          $t9, 0x2($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X2);
    // 0x8000C100: nop

    // 0x8000C104: bne         $t8, $t9, L_8000C128
    if (ctx->r24 != ctx->r25) {
        // 0x8000C108: nop
    
            goto L_8000C128;
    }
    // 0x8000C108: nop

    // 0x8000C10C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8000C110: nop

    // 0x8000C114: lw          $t0, 0x1A0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X1A0);
    // 0x8000C118: nop

    // 0x8000C11C: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x8000C120: bne         $t3, $zero, L_8000C2D4
    if (ctx->r11 != 0) {
        // 0x8000C124: nop
    
            goto L_8000C2D4;
    }
    // 0x8000C124: nop

L_8000C128:
    // 0x8000C128: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C12C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C130: lh          $t1, 0x1C($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X1C);
    // 0x8000C134: nop

    // 0x8000C138: sh          $t1, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r9;
    // 0x8000C13C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C140: nop

    // 0x8000C144: lhu         $t7, 0x14($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X14);
    // 0x8000C148: nop

    // 0x8000C14C: andi        $t5, $t7, 0x2
    ctx->r13 = ctx->r15 & 0X2;
    // 0x8000C150: beq         $t5, $zero, L_8000C184
    if (ctx->r13 == 0) {
        // 0x8000C154: nop
    
            goto L_8000C184;
    }
    // 0x8000C154: nop

    // 0x8000C158: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8000C15C: lh          $t8, 0x7254($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7254);
    // 0x8000C160: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C164: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x8000C168: sh          $t9, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r25;
    // 0x8000C16C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C170: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000C174: lhu         $t0, 0x14($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X14);
    // 0x8000C178: nop

    // 0x8000C17C: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8000C180: sh          $t3, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r11;
L_8000C184:
    // 0x8000C184: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C188: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C18C: lh          $t1, 0x1E($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X1E);
    // 0x8000C190: nop

    // 0x8000C194: sh          $t1, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r9;
    // 0x8000C198: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C19C: sh          $zero, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = 0;
    // 0x8000C1A0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C1A4: nop

    // 0x8000C1A8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8000C1AC: nop

    // 0x8000C1B0: beq         $t7, $zero, L_8000C1EC
    if (ctx->r15 == 0) {
        // 0x8000C1B4: nop
    
            goto L_8000C1EC;
    }
    // 0x8000C1B4: nop

    // 0x8000C1B8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8000C1BC: nop

    // 0x8000C1C0: lw          $t8, 0x1A0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000C1C4: nop

    // 0x8000C1C8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8000C1CC: beq         $t9, $zero, L_8000C1EC
    if (ctx->r25 == 0) {
        // 0x8000C1D0: nop
    
            goto L_8000C1EC;
    }
    // 0x8000C1D0: nop

    // 0x8000C1D4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000C1D8: nop

    // 0x8000C1DC: lw          $t3, 0x1A8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000C1E0: nop

    // 0x8000C1E4: ori         $t6, $t3, 0x1
    ctx->r14 = ctx->r11 | 0X1;
    // 0x8000C1E8: sw          $t6, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r14;
L_8000C1EC:
    // 0x8000C1EC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8000C1F0: nop

    // 0x8000C1F4: lw          $t1, 0x1A0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X1A0);
    // 0x8000C1F8: nop

    // 0x8000C1FC: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000C200: bne         $t2, $zero, L_8000C2BC
    if (ctx->r10 != 0) {
        // 0x8000C204: nop
    
            goto L_8000C2BC;
    }
    // 0x8000C204: nop

    // 0x8000C208: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8000C20C: lh          $t7, 0x7254($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7254);
    // 0x8000C210: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C214: ori         $t5, $t7, 0x8000
    ctx->r13 = ctx->r15 | 0X8000;
    // 0x8000C218: sh          $t5, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r13;
    // 0x8000C21C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000C220: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8000C224: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x8000C228: nop

    // 0x8000C22C: andi        $t3, $t9, 0x2000
    ctx->r11 = ctx->r25 & 0X2000;
    // 0x8000C230: bne         $t3, $zero, L_8000C248
    if (ctx->r11 != 0) {
        // 0x8000C234: nop
    
            goto L_8000C248;
    }
    // 0x8000C234: nop

    // 0x8000C238: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x8000C23C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C240: b           L_8000C25C
    // 0x8000C244: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
        goto L_8000C25C;
    // 0x8000C244: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
L_8000C248:
    // 0x8000C248: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000C24C: lh          $t0, -0x73C0($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X73C0);
    // 0x8000C250: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C254: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x8000C258: sh          $t4, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r12;
L_8000C25C:
    // 0x8000C25C: jal         0x80031728
    // 0x8000C260: nop

    func_80031728(rdram, ctx);
        goto after_8;
    // 0x8000C260: nop

    after_8:
    // 0x8000C264: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C268: nop

    // 0x8000C26C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8000C270: nop

    // 0x8000C274: beq         $t2, $zero, L_8000C29C
    if (ctx->r10 == 0) {
        // 0x8000C278: nop
    
            goto L_8000C29C;
    }
    // 0x8000C278: nop

    // 0x8000C27C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C280: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x8000C284: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x8000C288: nop

    // 0x8000C28C: lw          $t8, 0x1A0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000C290: nop

    // 0x8000C294: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000C298: sw          $t9, 0x1A0($t5)
    MEM_W(0X1A0, ctx->r13) = ctx->r25;
L_8000C29C:
    // 0x8000C29C: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8000C2A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C2A4: sw          $t3, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r11;
    // 0x8000C2A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000C2AC: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000C2B0: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x8000C2B4: b           L_8000C3A0
    // 0x8000C2B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000C3A0;
    // 0x8000C2B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000C2BC:
    // 0x8000C2BC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000C2C0: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8000C2C4: lhu         $t4, 0x0($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X0);
    // 0x8000C2C8: nop

    // 0x8000C2CC: ori         $t1, $t4, 0x80
    ctx->r9 = ctx->r12 | 0X80;
    // 0x8000C2D0: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
L_8000C2D4:
    // 0x8000C2D4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C2D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C2DC: lh          $t7, 0x16($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X16);
    // 0x8000C2E0: nop

    // 0x8000C2E4: sh          $t7, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r15;
    // 0x8000C2E8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C2EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C2F0: lh          $t9, 0x18($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X18);
    // 0x8000C2F4: nop

    // 0x8000C2F8: sh          $t9, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = ctx->r25;
    // 0x8000C2FC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C300: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C304: lh          $t3, 0x1A($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X1A);
    // 0x8000C308: nop

    // 0x8000C30C: sh          $t3, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = ctx->r11;
    // 0x8000C310: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C314: nop

    // 0x8000C318: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8000C31C: nop

    // 0x8000C320: beq         $t4, $zero, L_8000C390
    if (ctx->r12 == 0) {
        // 0x8000C324: nop
    
            goto L_8000C390;
    }
    // 0x8000C324: nop

    // 0x8000C328: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8000C32C: nop

    // 0x8000C330: lw          $t0, 0x1A8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X1A8);
    // 0x8000C334: nop

    // 0x8000C338: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8000C33C: bne         $t2, $zero, L_8000C390
    if (ctx->r10 != 0) {
        // 0x8000C340: nop
    
            goto L_8000C390;
    }
    // 0x8000C340: nop

    // 0x8000C344: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C348: lw          $a0, 0x3068($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3068);
    // 0x8000C34C: jal         0x8000D390
    // 0x8000C350: nop

    TempHeap_Free(rdram, ctx);
        goto after_9;
    // 0x8000C350: nop

    after_9:
    // 0x8000C354: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C358: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
    // 0x8000C35C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C360: nop

    // 0x8000C364: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000C368: nop

    // 0x8000C36C: sw          $zero, 0x1A8($t8)
    MEM_W(0X1A8, ctx->r24) = 0;
    // 0x8000C370: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C374: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8000C378: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8000C37C: nop

    // 0x8000C380: lw          $t3, 0x1A0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000C384: nop

    // 0x8000C388: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x8000C38C: sw          $t6, 0x1A0($t5)
    MEM_W(0X1A0, ctx->r13) = ctx->r14;
L_8000C390:
    // 0x8000C390: b           L_8000C3A0
    // 0x8000C394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C3A0;
    // 0x8000C394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C398: b           L_8000C3A0
    // 0x8000C39C: nop

        goto L_8000C3A0;
    // 0x8000C39C: nop

L_8000C3A0:
    // 0x8000C3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C3A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000C3A8: jr          $ra
    // 0x8000C3AC: nop

    return;
    // 0x8000C3AC: nop

;}
RECOMP_FUNC void func_8005618C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005618C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80056190: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056194: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80056198: nop

    // 0x8005619C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800561A0: nop

    // 0x800561A4: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x800561A8: bne         $at, $zero, L_800561C4
    if (ctx->r1 != 0) {
        // 0x800561AC: nop
    
            goto L_800561C4;
    }
    // 0x800561AC: nop

    // 0x800561B0: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x800561B4: nop

    // 0x800561B8: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x800561BC: beq         $at, $zero, L_800561CC
    if (ctx->r1 == 0) {
        // 0x800561C0: nop
    
            goto L_800561CC;
    }
    // 0x800561C0: nop

L_800561C4:
    // 0x800561C4: b           L_800561DC
    // 0x800561C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800561DC;
    // 0x800561C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800561CC:
    // 0x800561CC: b           L_800561DC
    // 0x800561D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800561DC;
    // 0x800561D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800561D4: b           L_800561DC
    // 0x800561D8: nop

        goto L_800561DC;
    // 0x800561D8: nop

L_800561DC:
    // 0x800561DC: jr          $ra
    // 0x800561E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800561E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8007EB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EB90: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007EB94: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007EB98: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007EB9C: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8007EBA0: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007EBA4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8007EBA8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007EBAC: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8007EBB0: beq         $a0, $zero, L_8007EC18
    if (ctx->r4 == 0) {
        // 0x8007EBB4: nop
    
            goto L_8007EC18;
    }
    // 0x8007EBB4: nop

    // 0x8007EBB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007EBBC: lwc1        $f4, -0x3890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3890);
    // 0x8007EBC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007EBC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007EBC8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8007EBCC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007EBD0: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8007EBD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007EBD8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8007EBDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007EBE0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007EBE4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8007EBE8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007EBEC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8007EBF0: nop

    // 0x8007EBF4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8007EBF8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007EBFC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007EC00: nop

    // 0x8007EC04: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007EC08: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8007EC0C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8007EC10: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8007EC14: nop

L_8007EC18:
    // 0x8007EC18: beq         $a1, $zero, L_8007EC84
    if (ctx->r5 == 0) {
        // 0x8007EC1C: nop
    
            goto L_8007EC84;
    }
    // 0x8007EC1C: nop

    // 0x8007EC20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007EC24: lwc1        $f16, -0x388C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X388C);
    // 0x8007EC28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8007EC2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007EC30: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8007EC34: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8007EC38: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8007EC3C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007EC40: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x8007EC44: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8007EC48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007EC4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007EC50: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8007EC54: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8007EC58: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007EC5C: nop

    // 0x8007EC60: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8007EC64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007EC68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007EC6C: nop

    // 0x8007EC70: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007EC74: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8007EC78: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007EC7C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EC80: nop

L_8007EC84:
    // 0x8007EC84: beq         $a2, $zero, L_8007ECA0
    if (ctx->r6 == 0) {
        // 0x8007EC88: nop
    
            goto L_8007ECA0;
    }
    // 0x8007EC88: nop

    // 0x8007EC8C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8007EC90: nop

    // 0x8007EC94: lhu         $t1, 0xA($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XA);
    // 0x8007EC98: nop

    // 0x8007EC9C: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
L_8007ECA0:
    // 0x8007ECA0: b           L_8007ECA8
    // 0x8007ECA4: nop

        goto L_8007ECA8;
    // 0x8007ECA4: nop

L_8007ECA8:
    // 0x8007ECA8: jr          $ra
    // 0x8007ECAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007ECAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80011A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011A0C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80011A10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011A14: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80011A18: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80011A1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80011A20: jal         0x8000DA44
    // 0x80011A24: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80011A24: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80011A28: bgez        $v0, L_80011A38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011A2C: nop
    
            goto L_80011A38;
    }
    // 0x80011A2C: nop

    // 0x80011A30: b           L_80011B78
    // 0x80011A34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011B78;
    // 0x80011A34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011A38:
    // 0x80011A38: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80011A3C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80011A40: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x80011A44: nop

    // 0x80011A48: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011A4C: bne         $at, $zero, L_80011A6C
    if (ctx->r1 != 0) {
        // 0x80011A50: nop
    
            goto L_80011A6C;
    }
    // 0x80011A50: nop

    // 0x80011A54: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80011A58: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011A5C: beq         $at, $zero, L_80011A6C
    if (ctx->r1 == 0) {
        // 0x80011A60: nop
    
            goto L_80011A6C;
    }
    // 0x80011A60: nop

    // 0x80011A64: b           L_80011B78
    // 0x80011A68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011B78;
    // 0x80011A68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011A6C:
    // 0x80011A6C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80011A70: lh          $t8, -0x7290($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7290);
    // 0x80011A74: nop

    // 0x80011A78: slti        $at, $t8, 0x1F4
    ctx->r1 = SIGNED(ctx->r24) < 0X1F4 ? 1 : 0;
    // 0x80011A7C: beq         $at, $zero, L_80011ACC
    if (ctx->r1 == 0) {
        // 0x80011A80: nop
    
            goto L_80011ACC;
    }
    // 0x80011A80: nop

    // 0x80011A84: lui         $t9, 0x8098
    ctx->r25 = S32(0X8098 << 16);
    // 0x80011A88: addiu       $t9, $t9, -0xB30
    ctx->r25 = ADD32(ctx->r25, -0XB30);
    // 0x80011A8C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80011A90: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80011A94: lw          $t0, 0x3070($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3070);
    // 0x80011A98: nop

    // 0x80011A9C: bne         $t0, $zero, L_80011AB4
    if (ctx->r8 != 0) {
        // 0x80011AA0: nop
    
            goto L_80011AB4;
    }
    // 0x80011AA0: nop

    // 0x80011AA4: lui         $t1, 0x8098
    ctx->r9 = S32(0X8098 << 16);
    // 0x80011AA8: addiu       $t1, $t1, 0x1A00
    ctx->r9 = ADD32(ctx->r9, 0X1A00);
    // 0x80011AAC: b           L_80011AC4
    // 0x80011AB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
        goto L_80011AC4;
    // 0x80011AB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80011AB4:
    // 0x80011AB4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80011AB8: lw          $t2, 0x3070($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3070);
    // 0x80011ABC: nop

    // 0x80011AC0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_80011AC4:
    // 0x80011AC4: b           L_80011B0C
    // 0x80011AC8: nop

        goto L_80011B0C;
    // 0x80011AC8: nop

L_80011ACC:
    // 0x80011ACC: lui         $t3, 0x8099
    ctx->r11 = S32(0X8099 << 16);
    // 0x80011AD0: addiu       $t3, $t3, 0x68B0
    ctx->r11 = ADD32(ctx->r11, 0X68B0);
    // 0x80011AD4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80011AD8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80011ADC: lw          $t4, 0x3078($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3078);
    // 0x80011AE0: nop

    // 0x80011AE4: bne         $t4, $zero, L_80011AFC
    if (ctx->r12 != 0) {
        // 0x80011AE8: nop
    
            goto L_80011AFC;
    }
    // 0x80011AE8: nop

    // 0x80011AEC: lui         $t5, 0x80B0
    ctx->r13 = S32(0X80B0 << 16);
    // 0x80011AF0: addiu       $t5, $t5, 0x4E40
    ctx->r13 = ADD32(ctx->r13, 0X4E40);
    // 0x80011AF4: b           L_80011B0C
    // 0x80011AF8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
        goto L_80011B0C;
    // 0x80011AF8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_80011AFC:
    // 0x80011AFC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80011B00: lw          $t6, 0x3078($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3078);
    // 0x80011B04: nop

    // 0x80011B08: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80011B0C:
    // 0x80011B0C: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x80011B10: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80011B14: addiu       $t8, $sp, 0x3C
    ctx->r24 = ADD32(ctx->r29, 0X3C);
    // 0x80011B18: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x80011B1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80011B20: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80011B24: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80011B28: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80011B2C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80011B30: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80011B34: jal         0x80096B38
    // 0x80011B38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_80096B38(rdram, ctx);
        goto after_1;
    // 0x80011B38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x80011B3C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80011B40: jal         0x80031874
    // 0x80011B44: nop

    func_80031874(rdram, ctx);
        goto after_2;
    // 0x80011B44: nop

    after_2:
    // 0x80011B48: beq         $v0, $zero, L_80011B50
    if (ctx->r2 == 0) {
        // 0x80011B4C: nop
    
            goto L_80011B50;
    }
    // 0x80011B4C: nop

L_80011B50:
    // 0x80011B50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80011B54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80011B58: jal         0x80096C6C
    // 0x80011B5C: nop

    func_80096C6C(rdram, ctx);
        goto after_3;
    // 0x80011B5C: nop

    after_3:
    // 0x80011B60: jal         0x80031B6C
    // 0x80011B64: nop

    func_80031B6C(rdram, ctx);
        goto after_4;
    // 0x80011B64: nop

    after_4:
    // 0x80011B68: b           L_80011B78
    // 0x80011B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011B78;
    // 0x80011B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011B70: b           L_80011B78
    // 0x80011B74: nop

        goto L_80011B78;
    // 0x80011B74: nop

L_80011B78:
    // 0x80011B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011B7C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80011B80: jr          $ra
    // 0x80011B84: nop

    return;
    // 0x80011B84: nop

;}
RECOMP_FUNC void func_80075074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075074: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075078: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007507C: nop

    // 0x80075080: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075084: nop

    // 0x80075088: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007508C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075090: jr          $ra
    // 0x80075094: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075094: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075098: jr          $ra
    // 0x8007509C: nop

    return;
    // 0x8007509C: nop

    // 0x800750A0: jr          $ra
    // 0x800750A4: nop

    return;
    // 0x800750A4: nop

;}
RECOMP_FUNC void func_800763DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800763E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800763E4: nop

    // 0x800763E8: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800763EC: nop

    // 0x800763F0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800763F4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800763F8: jr          $ra
    // 0x800763FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800763FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076400: jr          $ra
    // 0x80076404: nop

    return;
    // 0x80076404: nop

    // 0x80076408: jr          $ra
    // 0x8007640C: nop

    return;
    // 0x8007640C: nop

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
RECOMP_FUNC void func_80065F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065FA0: jal         0x80061348
    // 0x80065FA4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065FA4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80065FA8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065FAC: b           L_80065FBC
    // 0x80065FB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065FBC;
    // 0x80065FB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065FB4: b           L_80065FBC
    // 0x80065FB8: nop

        goto L_80065FBC;
    // 0x80065FB8: nop

L_80065FBC:
    // 0x80065FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065FC4: jr          $ra
    // 0x80065FC8: nop

    return;
    // 0x80065FC8: nop

;}
RECOMP_FUNC void func_8008B494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B494: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B49C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008B4A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008B4A4: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x8008B4A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008B4AC: sh          $t6, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r14;
    // 0x8008B4B0: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x8008B4B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008B4B8: sh          $t7, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r15;
    // 0x8008B4BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B4C0: lbu         $a0, 0x1918($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1918);
    // 0x8008B4C4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008B4C8: addiu       $a1, $a1, -0x820
    ctx->r5 = ADD32(ctx->r5, -0X820);
    // 0x8008B4CC: jal         0x800C1264
    // 0x8008B4D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x8008B4D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8008B4D4: b           L_8008B4DC
    // 0x8008B4D8: nop

        goto L_8008B4DC;
    // 0x8008B4D8: nop

L_8008B4DC:
    // 0x8008B4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B4E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B4E4: jr          $ra
    // 0x8008B4E8: nop

    return;
    // 0x8008B4E8: nop

;}
RECOMP_FUNC void func_80065354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065354: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065358: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006535C: nop

    // 0x80065360: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80065364: nop

    // 0x80065368: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x8006536C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065370: beq         $v0, $zero, L_80065388
    if (ctx->r2 == 0) {
        // 0x80065374: nop
    
            goto L_80065388;
    }
    // 0x80065374: nop

    // 0x80065378: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x8006537C: nop

    // 0x80065380: slti        $t8, $v0, 0x1F5
    ctx->r24 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80065384: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065388:
    // 0x80065388: jr          $ra
    // 0x8006538C: nop

    return;
    // 0x8006538C: nop

    // 0x80065390: jr          $ra
    // 0x80065394: nop

    return;
    // 0x80065394: nop

    // 0x80065398: jr          $ra
    // 0x8006539C: nop

    return;
    // 0x8006539C: nop

;}
RECOMP_FUNC void func_8003AEB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AEB0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003AEB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003AEB8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8003AEBC: lw          $t6, 0x7214($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7214);
    // 0x8003AEC0: nop

    // 0x8003AEC4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8003AEC8: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
    // 0x8003AECC: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
L_8003AED0:
    // 0x8003AED0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8003AED4: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x8003AED8: nop

    // 0x8003AEDC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003AEE0: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8003AEE4: nop

    // 0x8003AEE8: beq         $t0, $zero, L_8003B11C
    if (ctx->r8 == 0) {
        // 0x8003AEEC: nop
    
            goto L_8003B11C;
    }
    // 0x8003AEEC: nop

    // 0x8003AEF0: lh          $t2, 0x4E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4E);
    // 0x8003AEF4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8003AEF8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8003AEFC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8003AF00: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8003AF04: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8003AF08: addiu       $t5, $t4, 0xC
    ctx->r13 = ADD32(ctx->r12, 0XC);
    // 0x8003AF0C: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x8003AF10: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8003AF14: nop

    // 0x8003AF18: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003AF1C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8003AF20: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8003AF24: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8003AF28: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x8003AF2C: lw          $t0, 0x72B8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X72B8);
    // 0x8003AF30: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8003AF34: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x8003AF38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003AF3C: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8003AF40: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8003AF44: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x8003AF48: addiu       $t3, $t1, 0x10
    ctx->r11 = ADD32(ctx->r9, 0X10);
    // 0x8003AF4C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8003AF50: sh          $t9, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r25;
    // 0x8003AF54: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8003AF58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003AF5C: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003AF60: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003AF64: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AF68: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003AF6C: lwc1        $f10, 0xCC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8003AF70: nop

    // 0x8003AF74: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8003AF78: swc1        $f16, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f16.u32l;
    // 0x8003AF7C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AF80: nop

    // 0x8003AF84: lwc1        $f18, 0xCC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XCC);
    // 0x8003AF88: nop

    // 0x8003AF8C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x8003AF90: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8003AF94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003AF98: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003AF9C: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8003AFA0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AFA4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003AFA8: lwc1        $f8, 0xD0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8003AFAC: nop

    // 0x8003AFB0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003AFB4: swc1        $f16, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f16.u32l;
    // 0x8003AFB8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AFBC: nop

    // 0x8003AFC0: lwc1        $f18, 0xD0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x8003AFC4: nop

    // 0x8003AFC8: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x8003AFCC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003AFD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003AFD4: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003AFD8: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8003AFDC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AFE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003AFE4: lwc1        $f10, 0xD4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XD4);
    // 0x8003AFE8: nop

    // 0x8003AFEC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8003AFF0: swc1        $f16, 0xD4($t2)
    MEM_W(0XD4, ctx->r10) = ctx->f16.u32l;
    // 0x8003AFF4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AFF8: nop

    // 0x8003AFFC: lwc1        $f18, 0xD4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XD4);
    // 0x8003B000: nop

    // 0x8003B004: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8003B008: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8003B00C: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x8003B010: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8003B014: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8003B018: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B01C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003B020: lwc1        $f6, 0x4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8003B024: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003B028: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8003B02C: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8003B030: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8003B034: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8003B038: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8003B03C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8003B040: jal         0x800C3C80
    // 0x8003B044: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_0;
    // 0x8003B044: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8003B048: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8003B04C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003B050: nop

    // 0x8003B054: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8003B058: nop

    // 0x8003B05C: bc1t        L_8003B06C
    if (c1cs) {
        // 0x8003B060: nop
    
            goto L_8003B06C;
    }
    // 0x8003B060: nop

    // 0x8003B064: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003B068: sh          $t4, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r12;
L_8003B06C:
    // 0x8003B06C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8003B070: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003B074: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003B078: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003B07C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003B080: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003B084: mul.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8003B088: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8003B08C: nop

    // 0x8003B090: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003B094: nop

    // 0x8003B098: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8003B09C: sub.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d - ctx->f10.d;
    // 0x8003B0A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003B0A4: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8003B0A8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8003B0AC: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x8003B0B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8003B0B4: nop

    // 0x8003B0B8: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8003B0BC: nop

    // 0x8003B0C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003B0C4: c.le.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d <= ctx->f16.d;
    // 0x8003B0C8: nop

    // 0x8003B0CC: bc1t        L_8003B0E4
    if (c1cs) {
        // 0x8003B0D0: nop
    
            goto L_8003B0E4;
    }
    // 0x8003B0D0: nop

    // 0x8003B0D4: lh          $t7, 0x4A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4A);
    // 0x8003B0D8: nop

    // 0x8003B0DC: beq         $t7, $zero, L_8003B11C
    if (ctx->r15 == 0) {
        // 0x8003B0E0: nop
    
            goto L_8003B11C;
    }
    // 0x8003B0E0: nop

L_8003B0E4:
    // 0x8003B0E4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003B0E8: lw          $t8, 0x72B8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72B8);
    // 0x8003B0EC: lh          $t9, 0x4C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4C);
    // 0x8003B0F0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003B0F4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8003B0F8: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8003B0FC: lh          $t1, 0x4C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X4C);
    // 0x8003B100: lw          $t2, 0x72B8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72B8);
    // 0x8003B104: lh          $t6, 0x4E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4E);
    // 0x8003B108: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8003B10C: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x8003B110: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8003B114: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8003B118: sb          $t4, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r12;
L_8003B11C:
    // 0x8003B11C: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x8003B120: nop

    // 0x8003B124: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003B128: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x8003B12C: sra         $t2, $t0, 16
    ctx->r10 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8003B130: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x8003B134: bne         $at, $zero, L_8003AED0
    if (ctx->r1 != 0) {
        // 0x8003B138: sh          $t9, 0x4E($sp)
        MEM_H(0X4E, ctx->r29) = ctx->r25;
            goto L_8003AED0;
    }
    // 0x8003B138: sh          $t9, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r25;
    // 0x8003B13C: lh          $v0, 0x4A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X4A);
    // 0x8003B140: b           L_8003B150
    // 0x8003B144: nop

        goto L_8003B150;
    // 0x8003B144: nop

    // 0x8003B148: b           L_8003B150
    // 0x8003B14C: nop

        goto L_8003B150;
    // 0x8003B14C: nop

L_8003B150:
    // 0x8003B150: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003B154: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8003B158: jr          $ra
    // 0x8003B15C: nop

    return;
    // 0x8003B15C: nop

;}
RECOMP_FUNC void __postNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2450: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D2454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2458: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800D245C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D2460: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D2464: bne         $t6, $at, L_800D251C
    if (ctx->r14 != ctx->r1) {
        // 0x800D2468: lw          $a2, 0x18($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X18);
            goto L_800D251C;
    }
    // 0x800D2468: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x800D246C: beq         $a2, $zero, L_800D251C
    if (ctx->r6 == 0) {
        // 0x800D2470: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800D251C;
    }
    // 0x800D2470: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D2474: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800D2478: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D247C: jal         0x800D6810
    // 0x800D2480: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    __alSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x800D2480: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D2484: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800D2488: beq         $v0, $zero, L_800D251C
    if (ctx->r2 == 0) {
        // 0x800D248C: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_800D251C;
    }
    // 0x800D248C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D2490: lw          $t7, 0x84($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X84);
    // 0x800D2494: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D2498: beql        $t7, $zero, L_800D24FC
    if (ctx->r15 == 0) {
        // 0x800D249C: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_800D24FC;
    }
    goto skip_0;
    // 0x800D249C: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_0:
    // 0x800D24A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D24A4: jal         0x800D63D8
    // 0x800D24A8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    alSeqGetTicks(rdram, ctx);
        goto after_1;
    // 0x800D24A8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x800D24AC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D24B0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800D24B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800D24B8: lw          $t0, 0x80($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X80);
    // 0x800D24BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800D24C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D24C4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800D24C8: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D24CC: bnel        $at, $zero, L_800D24FC
    if (ctx->r1 != 0) {
        // 0x800D24D0: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_800D24FC;
    }
    goto skip_1;
    // 0x800D24D0: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_1:
    // 0x800D24D4: lw          $a1, 0x7C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X7C);
    // 0x800D24D8: jal         0x800D63BC
    // 0x800D24DC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    alSeqSetLoc(rdram, ctx);
        goto after_2;
    // 0x800D24DC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x800D24E0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D24E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D24E8: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x800D24EC: beq         $v0, $at, L_800D24F8
    if (ctx->r2 == ctx->r1) {
        // 0x800D24F0: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800D24F8;
    }
    // 0x800D24F0: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800D24F4: sw          $t2, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r10;
L_800D24F8:
    // 0x800D24F8: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
L_800D24FC:
    // 0x800D24FC: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    // 0x800D2500: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800D2504: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x800D2508: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800D250C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2510: mflo        $a2
    ctx->r6 = lo;
    // 0x800D2514: jal         0x800D3A2C
    // 0x800D2518: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x800D2518: nop

    after_3:
L_800D251C:
    // 0x800D251C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800D2524: jr          $ra
    // 0x800D2528: nop

    return;
    // 0x800D2528: nop

;}
RECOMP_FUNC void func_800629C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800629C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800629CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800629D0: jal         0x8005F064
    // 0x800629D4: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800629D4: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x800629D8: b           L_800629E8
    // 0x800629DC: nop

        goto L_800629E8;
    // 0x800629DC: nop

    // 0x800629E0: b           L_800629E8
    // 0x800629E4: nop

        goto L_800629E8;
    // 0x800629E4: nop

L_800629E8:
    // 0x800629E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800629EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800629F0: jr          $ra
    // 0x800629F4: nop

    return;
    // 0x800629F4: nop

;}
RECOMP_FUNC void func_80072020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072020: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072024: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072028: nop

    // 0x8007202C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80072030: nop

    // 0x80072034: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072038: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007203C: jr          $ra
    // 0x80072040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072044: jr          $ra
    // 0x80072048: nop

    return;
    // 0x80072048: nop

    // 0x8007204C: jr          $ra
    // 0x80072050: nop

    return;
    // 0x80072050: nop

;}
RECOMP_FUNC void Spi_DecompressAsset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF0B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BF0B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF0BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BF0C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BF0C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BF0C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF0CC: jal         0x800BC6EC
    // 0x800BF0D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800BF0D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x800BF0D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BF0D8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF0DC: nop

    // 0x800BF0E0: bne         $t6, $zero, L_800BF0F0
    if (ctx->r14 != 0) {
        // 0x800BF0E4: nop
    
            goto L_800BF0F0;
    }
    // 0x800BF0E4: nop

    // 0x800BF0E8: b           L_800BF2D8
    // 0x800BF0EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BF2D8;
    // 0x800BF0EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BF0F0:
    // 0x800BF0F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF0F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800BF0F8: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x800BF0FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF100: bgez        $a2, L_800BF110
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BF104: sra         $t7, $a2, 3
        ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
            goto L_800BF110;
    }
    // 0x800BF104: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800BF108: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x800BF10C: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800BF110:
    // 0x800BF110: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800BF114: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800BF118: jal         0x800BD218
    // 0x800BF11C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800BF11C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_1:
    // 0x800BF120: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF124: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF128: sw          $t9, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r25;
    // 0x800BF12C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800BF130: lw          $t0, 0x434($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X434);
    // 0x800BF134: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF138: sw          $t0, 0x458($at)
    MEM_W(0X458, ctx->r1) = ctx->r8;
    // 0x800BF13C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BF140: addiu       $t1, $t1, 0x490
    ctx->r9 = ADD32(ctx->r9, 0X490);
    // 0x800BF144: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800BF148: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800BF14C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF150: sw          $t2, 0x454($at)
    MEM_W(0X454, ctx->r1) = ctx->r10;
    // 0x800BF154: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BF158:
    // 0x800BF158: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF15C: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BF160: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BF164: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800BF168: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF16C: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x800BF170: lw          $t8, 0x434($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434);
    // 0x800BF174: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BF178: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF17C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BF180: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BF184: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800BF188: sw          $t9, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r25;
    // 0x800BF18C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800BF190: nop

    // 0x800BF194: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BF198: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x800BF19C: bne         $at, $zero, L_800BF158
    if (ctx->r1 != 0) {
        // 0x800BF1A0: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_800BF158;
    }
    // 0x800BF1A0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800BF1A4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF1A8: addiu       $t2, $t2, 0x490
    ctx->r10 = ADD32(ctx->r10, 0X490);
    // 0x800BF1AC: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x800BF1B0: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800BF1B4: beq         $t3, $at, L_800BF2B4
    if (ctx->r11 == ctx->r1) {
        // 0x800BF1B8: nop
    
            goto L_800BF2B4;
    }
    // 0x800BF1B8: nop

    // 0x800BF1BC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BF1C0:
    // 0x800BF1C0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF1C4: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BF1C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BF1CC: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800BF1D0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF1D4: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800BF1D8: lw          $t9, 0x434($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X434);
    // 0x800BF1DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800BF1E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF1E4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BF1E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BF1EC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800BF1F0: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
    // 0x800BF1F4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800BF1F8: nop

    // 0x800BF1FC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BF200: sltiu       $at, $t2, 0xC
    ctx->r1 = ctx->r10 < 0XC ? 1 : 0;
    // 0x800BF204: bne         $at, $zero, L_800BF1C0
    if (ctx->r1 != 0) {
        // 0x800BF208: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800BF1C0;
    }
    // 0x800BF208: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800BF20C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF210: lw          $t3, 0x434($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X434);
    // 0x800BF214: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF218: sw          $t3, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r11;
    // 0x800BF21C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF220: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF224: lw          $t5, 0x498($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X498);
    // 0x800BF228: lw          $t4, 0x434($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X434);
    // 0x800BF22C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF230: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800BF234: sw          $t6, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r14;
    // 0x800BF238: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800BF23C: lw          $t7, 0x434($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X434);
    // 0x800BF240: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF244: sw          $t7, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r15;
    // 0x800BF248: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800BF24C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF250: lw          $t9, 0x49C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X49C);
    // 0x800BF254: lw          $t8, 0x434($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434);
    // 0x800BF258: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF25C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BF260: sw          $t0, 0x434($at)
    MEM_W(0X434, ctx->r1) = ctx->r8;
    // 0x800BF264: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BF268: lw          $t1, 0x434($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X434);
    // 0x800BF26C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF270: sw          $t1, 0x444($at)
    MEM_W(0X444, ctx->r1) = ctx->r9;
    // 0x800BF274: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800BF278: lw          $t2, 0x454($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X454);
    // 0x800BF27C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF280: sw          $t2, 0x46C($at)
    MEM_W(0X46C, ctx->r1) = ctx->r10;
    // 0x800BF284: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BF288: lw          $t3, 0x43C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X43C);
    // 0x800BF28C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF290: sw          $t3, 0x45C($at)
    MEM_W(0X45C, ctx->r1) = ctx->r11;
    // 0x800BF294: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800BF298: lw          $t4, 0x444($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X444);
    // 0x800BF29C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF2A0: sw          $t4, 0x460($at)
    MEM_W(0X460, ctx->r1) = ctx->r12;
    // 0x800BF2A4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BF2A8: lw          $t5, 0x44C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X44C);
    // 0x800BF2AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BF2B0: sw          $t5, 0x464($at)
    MEM_W(0X464, ctx->r1) = ctx->r13;
L_800BF2B4:
    // 0x800BF2B4: jal         0x800BFB60
    // 0x800BF2B8: nop

    Spi_Decompress(rdram, ctx);
        goto after_2;
    // 0x800BF2B8: nop

    after_2:
    // 0x800BF2BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF2C0: jal         0x800BC980
    // 0x800BF2C4: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800BF2C4: nop

    after_3:
    // 0x800BF2C8: b           L_800BF2D8
    // 0x800BF2CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF2D8;
    // 0x800BF2CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF2D0: b           L_800BF2D8
    // 0x800BF2D4: nop

        goto L_800BF2D8;
    // 0x800BF2D4: nop

L_800BF2D8:
    // 0x800BF2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF2DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BF2E0: jr          $ra
    // 0x800BF2E4: nop

    return;
    // 0x800BF2E4: nop

;}
RECOMP_FUNC void func_800742A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800742A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800742A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800742AC: jal         0x80061348
    // 0x800742B0: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800742B0: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x800742B4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800742B8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800742BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800742C0: beq         $v0, $zero, L_800742DC
    if (ctx->r2 == 0) {
        // 0x800742C4: nop
    
            goto L_800742DC;
    }
    // 0x800742C4: nop

    // 0x800742C8: jal         0x80061348
    // 0x800742CC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800742CC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x800742D0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800742D4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800742D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800742DC:
    // 0x800742DC: b           L_800742EC
    // 0x800742E0: nop

        goto L_800742EC;
    // 0x800742E0: nop

    // 0x800742E4: b           L_800742EC
    // 0x800742E8: nop

        goto L_800742EC;
    // 0x800742E8: nop

L_800742EC:
    // 0x800742EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800742F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800742F4: jr          $ra
    // 0x800742F8: nop

    return;
    // 0x800742F8: nop

;}
RECOMP_FUNC void func_8006D1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D1F8: jal         0x80061348
    // 0x8006D1FC: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D1FC: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x8006D200: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D204: b           L_8006D214
    // 0x8006D208: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D214;
    // 0x8006D208: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D20C: b           L_8006D214
    // 0x8006D210: nop

        goto L_8006D214;
    // 0x8006D210: nop

L_8006D214:
    // 0x8006D214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D21C: jr          $ra
    // 0x8006D220: nop

    return;
    // 0x8006D220: nop

;}
RECOMP_FUNC void func_80075C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075C6C: jal         0x80061488
    // 0x80075C70: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075C70: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    after_0:
    // 0x80075C74: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80075C78: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80075C7C: b           L_80075C8C
    // 0x80075C80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075C8C;
    // 0x80075C80: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075C84: b           L_80075C8C
    // 0x80075C88: nop

        goto L_80075C8C;
    // 0x80075C88: nop

L_80075C8C:
    // 0x80075C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075C94: jr          $ra
    // 0x80075C98: nop

    return;
    // 0x80075C98: nop

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
RECOMP_FUNC void func_800714A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800714A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800714A8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800714AC: nop

    // 0x800714B0: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800714B4: nop

    // 0x800714B8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800714BC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800714C0: jr          $ra
    // 0x800714C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800714C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800714C8: jr          $ra
    // 0x800714CC: nop

    return;
    // 0x800714CC: nop

    // 0x800714D0: jr          $ra
    // 0x800714D4: nop

    return;
    // 0x800714D4: nop

;}
RECOMP_FUNC void AudioDriver_StopSeqplayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB3EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BB3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB3F4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800BB3F8: lw          $t6, -0x7310($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7310);
    // 0x800BB3FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BB400: bne         $t6, $at, L_800BB430
    if (ctx->r14 != ctx->r1) {
        // 0x800BB404: nop
    
            goto L_800BB430;
    }
    // 0x800BB404: nop

    // 0x800BB408: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BB40C: lw          $a0, -0x17DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17DC);
    // 0x800BB410: jal         0x800CAD90
    // 0x800BB414: nop

    alSeqpStop(rdram, ctx);
        goto after_0;
    // 0x800BB414: nop

    after_0:
    // 0x800BB418: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800BB41C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BB420: sw          $t7, -0x7310($at)
    MEM_W(-0X7310, ctx->r1) = ctx->r15;
    // 0x800BB424: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800BB428: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB42C: sw          $t8, -0x17CC($at)
    MEM_W(-0X17CC, ctx->r1) = ctx->r24;
L_800BB430:
    // 0x800BB430: b           L_800BB438
    // 0x800BB434: nop

        goto L_800BB438;
    // 0x800BB434: nop

L_800BB438:
    // 0x800BB438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BB43C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BB440: jr          $ra
    // 0x800BB444: nop

    return;
    // 0x800BB444: nop

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
RECOMP_FUNC void func_80047734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047734: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80047738: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8004773C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80047740: addu        $t6, $a0, $a3
    ctx->r14 = ADD32(ctx->r4, ctx->r7);
    // 0x80047744: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80047748: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8004774C: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x80047750: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80047754: xor         $t9, $a2, $at
    ctx->r25 = ctx->r6 ^ ctx->r1;
    // 0x80047758: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8004775C: sb          $t0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r8;
    // 0x80047760: andi        $t1, $a2, 0x8
    ctx->r9 = ctx->r6 & 0X8;
    // 0x80047764: beq         $t1, $zero, L_80047784
    if (ctx->r9 == 0) {
        // 0x80047768: nop
    
            goto L_80047784;
    }
    // 0x80047768: nop

    // 0x8004776C: beq         $a1, $zero, L_80047784
    if (ctx->r5 == 0) {
        // 0x80047770: nop
    
            goto L_80047784;
    }
    // 0x80047770: nop

    // 0x80047774: lbu         $t2, -0x4($a3)
    ctx->r10 = MEM_BU(ctx->r7, -0X4);
    // 0x80047778: nop

    // 0x8004777C: andi        $t3, $t2, 0xB
    ctx->r11 = ctx->r10 & 0XB;
    // 0x80047780: sb          $t3, -0x4($a3)
    MEM_B(-0X4, ctx->r7) = ctx->r11;
L_80047784:
    // 0x80047784: andi        $t4, $a2, 0x4
    ctx->r12 = ctx->r6 & 0X4;
    // 0x80047788: beq         $t4, $zero, L_800477AC
    if (ctx->r12 == 0) {
        // 0x8004778C: nop
    
            goto L_800477AC;
    }
    // 0x8004778C: nop

    // 0x80047790: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80047794: beq         $a1, $at, L_800477AC
    if (ctx->r5 == ctx->r1) {
        // 0x80047798: nop
    
            goto L_800477AC;
    }
    // 0x80047798: nop

    // 0x8004779C: lbu         $t5, 0x4($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X4);
    // 0x800477A0: nop

    // 0x800477A4: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x800477A8: sb          $t6, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r14;
L_800477AC:
    // 0x800477AC: andi        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 & 0X2;
    // 0x800477B0: beq         $t7, $zero, L_800477D0
    if (ctx->r15 == 0) {
        // 0x800477B4: nop
    
            goto L_800477D0;
    }
    // 0x800477B4: nop

    // 0x800477B8: beq         $a0, $zero, L_800477D0
    if (ctx->r4 == 0) {
        // 0x800477BC: nop
    
            goto L_800477D0;
    }
    // 0x800477BC: nop

    // 0x800477C0: lbu         $t8, -0x1($a3)
    ctx->r24 = MEM_BU(ctx->r7, -0X1);
    // 0x800477C4: nop

    // 0x800477C8: andi        $t9, $t8, 0xE
    ctx->r25 = ctx->r24 & 0XE;
    // 0x800477CC: sb          $t9, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r25;
L_800477D0:
    // 0x800477D0: andi        $t0, $a2, 0x1
    ctx->r8 = ctx->r6 & 0X1;
    // 0x800477D4: beq         $t0, $zero, L_800477F8
    if (ctx->r8 == 0) {
        // 0x800477D8: nop
    
            goto L_800477F8;
    }
    // 0x800477D8: nop

    // 0x800477DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800477E0: beq         $a0, $at, L_800477F8
    if (ctx->r4 == ctx->r1) {
        // 0x800477E4: nop
    
            goto L_800477F8;
    }
    // 0x800477E4: nop

    // 0x800477E8: lbu         $t1, 0x1($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X1);
    // 0x800477EC: nop

    // 0x800477F0: andi        $t2, $t1, 0xD
    ctx->r10 = ctx->r9 & 0XD;
    // 0x800477F4: sb          $t2, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r10;
L_800477F8:
    // 0x800477F8: jr          $ra
    // 0x800477FC: nop

    return;
    // 0x800477FC: nop

    // 0x80047800: jr          $ra
    // 0x80047804: nop

    return;
    // 0x80047804: nop

;}
RECOMP_FUNC void AudioDriver_RequestSoundDealloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9BD4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800B9BD8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B9BDC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B9BE0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800B9BE4:
    // 0x800B9BE4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B9BE8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9BEC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B9BF0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B9BF4: lw          $t8, -0x1E0C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1E0C);
    // 0x800B9BF8: nop

    // 0x800B9BFC: bne         $t8, $zero, L_800B9C0C
    if (ctx->r24 != 0) {
        // 0x800B9C00: nop
    
            goto L_800B9C0C;
    }
    // 0x800B9C00: nop

    // 0x800B9C04: b           L_800B9C24
    // 0x800B9C08: nop

        goto L_800B9C24;
    // 0x800B9C08: nop

L_800B9C0C:
    // 0x800B9C0C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800B9C10: nop

    // 0x800B9C14: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B9C18: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800B9C1C: bne         $at, $zero, L_800B9BE4
    if (ctx->r1 != 0) {
        // 0x800B9C20: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_800B9BE4;
    }
    // 0x800B9C20: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
L_800B9C24:
    // 0x800B9C24: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800B9C28: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B9C2C: beq         $t1, $at, L_800B9C64
    if (ctx->r9 == ctx->r1) {
        // 0x800B9C30: nop
    
            goto L_800B9C64;
    }
    // 0x800B9C30: nop

    // 0x800B9C34: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800B9C38: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9C3C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800B9C40: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800B9C44: sh          $a0, -0x1E10($at)
    MEM_H(-0X1E10, ctx->r1) = ctx->r4;
    // 0x800B9C48: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800B9C4C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9C50: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800B9C54: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B9C58: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800B9C5C: b           L_800B9C64
    // 0x800B9C60: sw          $t4, -0x1E0C($at)
    MEM_W(-0X1E0C, ctx->r1) = ctx->r12;
        goto L_800B9C64;
    // 0x800B9C60: sw          $t4, -0x1E0C($at)
    MEM_W(-0X1E0C, ctx->r1) = ctx->r12;
L_800B9C64:
    // 0x800B9C64: b           L_800B9C6C
    // 0x800B9C68: nop

        goto L_800B9C6C;
    // 0x800B9C68: nop

L_800B9C6C:
    // 0x800B9C6C: jr          $ra
    // 0x800B9C70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B9C70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B1E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1E58: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B1E5C: beq         $a0, $zero, L_800B1E94
    if (ctx->r4 == 0) {
        // 0x800B1E60: nop
    
            goto L_800B1E94;
    }
    // 0x800B1E60: nop

    // 0x800B1E64: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800B1E68:
    // 0x800B1E68: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B1E6C: nop

    // 0x800B1E70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B1E74: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800B1E78: sw          $zero, 0x12C($t8)
    MEM_W(0X12C, ctx->r24) = 0;
    // 0x800B1E7C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800B1E80: nop

    // 0x800B1E84: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B1E88: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800B1E8C: bne         $at, $zero, L_800B1E68
    if (ctx->r1 != 0) {
        // 0x800B1E90: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_800B1E68;
    }
    // 0x800B1E90: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
L_800B1E94:
    // 0x800B1E94: bne         $a1, $zero, L_800B1EA4
    if (ctx->r5 != 0) {
        // 0x800B1E98: nop
    
            goto L_800B1EA4;
    }
    // 0x800B1E98: nop

    // 0x800B1E9C: b           L_800B1F04
    // 0x800B1EA0: nop

        goto L_800B1F04;
    // 0x800B1EA0: nop

L_800B1EA4:
    // 0x800B1EA4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800B1EA8:
    // 0x800B1EA8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800B1EAC: nop

    // 0x800B1EB0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B1EB4: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x800B1EB8: sw          $zero, 0x14($t3)
    MEM_W(0X14, ctx->r11) = 0;
    // 0x800B1EBC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800B1EC0: nop

    // 0x800B1EC4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B1EC8: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800B1ECC: bne         $at, $zero, L_800B1EA8
    if (ctx->r1 != 0) {
        // 0x800B1ED0: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_800B1EA8;
    }
    // 0x800B1ED0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800B1ED4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800B1ED8: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800B1EDC: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800B1EE0: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800B1EE4: sh          $t6, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r14;
    // 0x800B1EE8: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800B1EEC: sh          $t7, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r15;
    // 0x800B1EF0: sh          $zero, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = 0;
    // 0x800B1EF4: sb          $zero, 0x3C($a1)
    MEM_B(0X3C, ctx->r5) = 0;
    // 0x800B1EF8: sb          $zero, 0x3D($a1)
    MEM_B(0X3D, ctx->r5) = 0;
    // 0x800B1EFC: b           L_800B1F04
    // 0x800B1F00: nop

        goto L_800B1F04;
    // 0x800B1F00: nop

L_800B1F04:
    // 0x800B1F04: jr          $ra
    // 0x800B1F08: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B1F08: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80019FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019FA0: lw          $t6, 0x1A0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A0);
    // 0x80019FA4: nop

    // 0x80019FA8: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80019FAC: sw          $t7, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->r15;
    // 0x80019FB0: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80019FB4: sw          $zero, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = 0;
    // 0x80019FB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80019FBC: nop

    // 0x80019FC0: swc1        $f4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f4.u32l;
    // 0x80019FC4: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80019FC8: nop

    // 0x80019FCC: swc1        $f6, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f6.u32l;
    // 0x80019FD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80019FD4: nop

    // 0x80019FD8: swc1        $f8, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->f8.u32l;
    // 0x80019FDC: lwc1        $f10, 0x1F4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x80019FE0: nop

    // 0x80019FE4: swc1        $f10, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f10.u32l;
    // 0x80019FE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80019FEC: nop

    // 0x80019FF0: swc1        $f16, 0x1FC($a0)
    MEM_W(0X1FC, ctx->r4) = ctx->f16.u32l;
    // 0x80019FF4: lwc1        $f18, 0x1FC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1FC);
    // 0x80019FF8: nop

    // 0x80019FFC: swc1        $f18, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->f18.u32l;
    // 0x8001A000: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001A004: nop

    // 0x8001A008: swc1        $f4, 0x204($a0)
    MEM_W(0X204, ctx->r4) = ctx->f4.u32l;
    // 0x8001A00C: lwc1        $f6, 0x204($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X204);
    // 0x8001A010: nop

    // 0x8001A014: swc1        $f6, 0x200($a0)
    MEM_W(0X200, ctx->r4) = ctx->f6.u32l;
    // 0x8001A018: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8001A01C: lw          $t8, -0x4538($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4538);
    // 0x8001A020: nop

    // 0x8001A024: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x8001A028: jr          $ra
    // 0x8001A02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001A02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A030: jr          $ra
    // 0x8001A034: nop

    return;
    // 0x8001A034: nop

    // 0x8001A038: jr          $ra
    // 0x8001A03C: nop

    return;
    // 0x8001A03C: nop

;}
RECOMP_FUNC void func_8008C2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C2E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C2EC: bne         $a1, $zero, L_8008C2FC
    if (ctx->r5 != 0) {
        // 0x8008C2F0: nop
    
            goto L_8008C2FC;
    }
    // 0x8008C2F0: nop

    // 0x8008C2F4: b           L_8008C30C
    // 0x8008C2F8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
        goto L_8008C30C;
    // 0x8008C2F8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8008C2FC:
    // 0x8008C2FC: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8008C300: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8008C304: addiu       $t8, $t7, 0x1A
    ctx->r24 = ADD32(ctx->r15, 0X1A);
    // 0x8008C308: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
L_8008C30C:
    // 0x8008C30C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008C310: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_8008C314:
    // 0x8008C314: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008C318: nop

    // 0x8008C31C: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8008C320: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x8008C324: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008C328: nop

    // 0x8008C32C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008C330: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8008C334: bne         $at, $zero, L_8008C314
    if (ctx->r1 != 0) {
        // 0x8008C338: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8008C314;
    }
    // 0x8008C338: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8008C33C: b           L_8008C344
    // 0x8008C340: nop

        goto L_8008C344;
    // 0x8008C340: nop

L_8008C344:
    // 0x8008C344: jr          $ra
    // 0x8008C348: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C348: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800677F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800677F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800677F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800677FC: jal         0x80061348
    // 0x80067800: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067800: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80067804: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80067808: b           L_80067818
    // 0x8006780C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067818;
    // 0x8006780C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067810: b           L_80067818
    // 0x80067814: nop

        goto L_80067818;
    // 0x80067814: nop

L_80067818:
    // 0x80067818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006781C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067820: jr          $ra
    // 0x80067824: nop

    return;
    // 0x80067824: nop

;}
RECOMP_FUNC void func_8006D6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D6FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D704: jal         0x80061488
    // 0x8006D708: addiu       $a0, $zero, 0x580
    ctx->r4 = ADD32(0, 0X580);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006D708: addiu       $a0, $zero, 0x580
    ctx->r4 = ADD32(0, 0X580);
    after_0:
    // 0x8006D70C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006D710: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006D714: b           L_8006D724
    // 0x8006D718: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D724;
    // 0x8006D718: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D71C: b           L_8006D724
    // 0x8006D720: nop

        goto L_8006D724;
    // 0x8006D720: nop

L_8006D724:
    // 0x8006D724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D72C: jr          $ra
    // 0x8006D730: nop

    return;
    // 0x8006D730: nop

;}
RECOMP_FUNC void func_80076B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076B18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076B1C: nop

    // 0x80076B20: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076B24: nop

    // 0x80076B28: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076B2C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076B30: jr          $ra
    // 0x80076B34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076B34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076B38: jr          $ra
    // 0x80076B3C: nop

    return;
    // 0x80076B3C: nop

    // 0x80076B40: jr          $ra
    // 0x80076B44: nop

    return;
    // 0x80076B44: nop

;}
RECOMP_FUNC void func_800770D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800770D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800770D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800770D8: nop

    // 0x800770DC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800770E0: nop

    // 0x800770E4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800770E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800770EC: jr          $ra
    // 0x800770F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800770F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800770F4: jr          $ra
    // 0x800770F8: nop

    return;
    // 0x800770F8: nop

    // 0x800770FC: jr          $ra
    // 0x80077100: nop

    return;
    // 0x80077100: nop

;}
RECOMP_FUNC void func_8006B610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B610: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B614: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B618: nop

    // 0x8006B61C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B620: nop

    // 0x8006B624: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B628: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B62C: jr          $ra
    // 0x8006B630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B630: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B634: jr          $ra
    // 0x8006B638: nop

    return;
    // 0x8006B638: nop

    // 0x8006B63C: jr          $ra
    // 0x8006B640: nop

    return;
    // 0x8006B640: nop

;}
RECOMP_FUNC void Thread_CreateMesgQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C14E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C14E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C14E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C14EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C14F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C14F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C14F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C14FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C1500: jal         0x800C42B0
    // 0x800C1504: nop

    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1504: nop

    after_0:
    // 0x800C1508: b           L_800C1518
    // 0x800C150C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1518;
    // 0x800C150C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1510: b           L_800C1518
    // 0x800C1514: nop

        goto L_800C1518;
    // 0x800C1514: nop

L_800C1518:
    // 0x800C1518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C151C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1520: jr          $ra
    // 0x800C1524: nop

    return;
    // 0x800C1524: nop

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
RECOMP_FUNC void func_80073A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073A64: jal         0x80061488
    // 0x80073A68: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073A68: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073A6C: xori        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 ^ 0X4;
    // 0x80073A70: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073A74: b           L_80073A84
    // 0x80073A78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073A84;
    // 0x80073A78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073A7C: b           L_80073A84
    // 0x80073A80: nop

        goto L_80073A84;
    // 0x80073A80: nop

L_80073A84:
    // 0x80073A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073A8C: jr          $ra
    // 0x80073A90: nop

    return;
    // 0x80073A90: nop

;}
RECOMP_FUNC void func_8006C0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C0F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C0F8: jal         0x8005F064
    // 0x8006C0FC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C0FC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_0:
    // 0x8006C100: b           L_8006C110
    // 0x8006C104: nop

        goto L_8006C110;
    // 0x8006C104: nop

    // 0x8006C108: b           L_8006C110
    // 0x8006C10C: nop

        goto L_8006C110;
    // 0x8006C10C: nop

L_8006C110:
    // 0x8006C110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C118: jr          $ra
    // 0x8006C11C: nop

    return;
    // 0x8006C11C: nop

;}
RECOMP_FUNC void func_80090754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090754: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80090758: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009075C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090760: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80090764: xori        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 ^ 0XFFFF;
    // 0x80090768: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009076C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80090770: sh          $t8, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = ctx->r24;
    // 0x80090774: jr          $ra
    // 0x80090778: nop

    return;
    // 0x80090778: nop

    // 0x8009077C: jr          $ra
    // 0x80090780: nop

    return;
    // 0x80090780: nop

;}
RECOMP_FUNC void func_80082DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082DDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80082DE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80082DE4: nop

    // 0x80082DE8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80082DEC: nop

    // 0x80082DF0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80082DF4: beq         $t8, $zero, L_80082E18
    if (ctx->r24 == 0) {
        // 0x80082DF8: nop
    
            goto L_80082E18;
    }
    // 0x80082DF8: nop

    // 0x80082DFC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082E00: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80082E04: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80082E08: nop

    // 0x80082E0C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80082E10: b           L_80082E80
    // 0x80082E14: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
        goto L_80082E80;
    // 0x80082E14: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
L_80082E18:
    // 0x80082E18: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80082E1C: nop

    // 0x80082E20: addiu       $a0, $t2, 0x24
    ctx->r4 = ADD32(ctx->r10, 0X24);
    // 0x80082E24: jal         0x800B2748
    // 0x80082E28: addiu       $a1, $t2, 0x28
    ctx->r5 = ADD32(ctx->r10, 0X28);
    func_800B2748(rdram, ctx);
        goto after_0;
    // 0x80082E28: addiu       $a1, $t2, 0x28
    ctx->r5 = ADD32(ctx->r10, 0X28);
    after_0:
    // 0x80082E2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80082E30: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80082E34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082E38: beq         $t3, $at, L_80082E68
    if (ctx->r11 == ctx->r1) {
        // 0x80082E3C: nop
    
            goto L_80082E68;
    }
    // 0x80082E3C: nop

    // 0x80082E40: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80082E44: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80082E48: nop

    // 0x80082E4C: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
    // 0x80082E50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80082E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082E58: jal         0x8005A5F4
    // 0x80082E5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8005A5F4(rdram, ctx);
        goto after_1;
    // 0x80082E5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x80082E60: b           L_80082E80
    // 0x80082E64: nop

        goto L_80082E80;
    // 0x80082E64: nop

L_80082E68:
    // 0x80082E68: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80082E6C: nop

    // 0x80082E70: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80082E74: nop

    // 0x80082E78: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80082E7C: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
L_80082E80:
    // 0x80082E80: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80082E84: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80082E88: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80082E8C: nop

    // 0x80082E90: blez        $t1, L_80083074
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80082E94: nop
    
            goto L_80083074;
    }
    // 0x80082E94: nop

L_80082E98:
    // 0x80082E98: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80082E9C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082EA0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80082EA4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80082EA8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082EAC: lw          $t2, 0x24($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X24);
    // 0x80082EB0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80082EB4: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80082EB8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80082EBC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80082EC0: swc1        $f4, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f4.u32l;
    // 0x80082EC4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80082EC8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082ECC: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80082ED0: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80082ED4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80082ED8: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80082EDC: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80082EE0: lwc1        $f6, 0x18($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X18);
    // 0x80082EE4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80082EE8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80082EEC: swc1        $f6, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f6.u32l;
    // 0x80082EF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80082EF4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082EF8: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80082EFC: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80082F00: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082F04: lw          $t3, 0x24($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X24);
    // 0x80082F08: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80082F0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082F10: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80082F14: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80082F18: swc1        $f8, 0xD4($t5)
    MEM_W(0XD4, ctx->r13) = ctx->f8.u32l;
    // 0x80082F1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80082F20: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082F24: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80082F28: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80082F2C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80082F30: lw          $t6, 0x24($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X24);
    // 0x80082F34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80082F38: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80082F3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082F40: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80082F44: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x80082F48: swc1        $f10, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f10.u32l;
    // 0x80082F4C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80082F50: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082F54: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80082F58: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80082F5C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082F60: lw          $t2, 0x24($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X24);
    // 0x80082F64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80082F68: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80082F6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80082F70: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80082F74: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80082F78: swc1        $f16, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f16.u32l;
    // 0x80082F7C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80082F80: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082F84: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80082F88: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80082F8C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80082F90: lw          $t6, 0x24($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X24);
    // 0x80082F94: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80082F98: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80082F9C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80082FA0: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x80082FA4: sh          $t8, 0x11E($t9)
    MEM_H(0X11E, ctx->r25) = ctx->r24;
    // 0x80082FA8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80082FAC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80082FB0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80082FB4: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80082FB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80082FBC: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x80082FC0: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80082FC4: lw          $t2, 0x38($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X38);
    // 0x80082FC8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80082FCC: addu        $t0, $t4, $t7
    ctx->r8 = ADD32(ctx->r12, ctx->r15);
    // 0x80082FD0: sw          $t2, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->r10;
    // 0x80082FD4: jal         0x800C1754
    // 0x80082FD8: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_2;
    // 0x80082FD8: nop

    after_2:
    // 0x80082FDC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80082FE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80082FE4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80082FE8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80082FEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80082FF0: lw          $t1, 0x24($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X24);
    // 0x80082FF4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80082FF8: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80082FFC: jal         0x8009A14C
    // 0x80083000: addu        $a0, $t1, $t9
    ctx->r4 = ADD32(ctx->r9, ctx->r25);
    func_8009A14C(rdram, ctx);
        goto after_3;
    // 0x80083000: addu        $a0, $t1, $t9
    ctx->r4 = ADD32(ctx->r9, ctx->r25);
    after_3:
    // 0x80083004: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80083008: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8008300C: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x80083010: nop

    // 0x80083014: andi        $t4, $t5, 0x200
    ctx->r12 = ctx->r13 & 0X200;
    // 0x80083018: bne         $t4, $zero, L_80083048
    if (ctx->r12 != 0) {
        // 0x8008301C: nop
    
            goto L_80083048;
    }
    // 0x8008301C: nop

    // 0x80083020: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80083024: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80083028: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8008302C: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x80083030: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083034: lw          $t2, 0x24($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X24);
    // 0x80083038: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x8008303C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80083040: jal         0x800997D8
    // 0x80083044: addu        $a0, $t2, $t6
    ctx->r4 = ADD32(ctx->r10, ctx->r14);
    func_800997D8(rdram, ctx);
        goto after_4;
    // 0x80083044: addu        $a0, $t2, $t6
    ctx->r4 = ADD32(ctx->r10, ctx->r14);
    after_4:
L_80083048:
    // 0x80083048: jal         0x800C1A28
    // 0x8008304C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_5;
    // 0x8008304C: nop

    after_5:
    // 0x80083050: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80083054: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80083058: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x8008305C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083060: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80083064: nop

    // 0x80083068: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8008306C: bne         $at, $zero, L_80082E98
    if (ctx->r1 != 0) {
        // 0x80083070: nop
    
            goto L_80082E98;
    }
    // 0x80083070: nop

L_80083074:
    // 0x80083074: b           L_8008307C
    // 0x80083078: nop

        goto L_8008307C;
    // 0x80083078: nop

L_8008307C:
    // 0x8008307C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083084: jr          $ra
    // 0x80083088: nop

    return;
    // 0x80083088: nop

;}
RECOMP_FUNC void func_80070F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070F68: jal         0x80061348
    // 0x80070F6C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070F6C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_0:
    // 0x80070F70: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070F74: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070F78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070F7C: beq         $v0, $zero, L_80070FD0
    if (ctx->r2 == 0) {
        // 0x80070F80: nop
    
            goto L_80070FD0;
    }
    // 0x80070F80: nop

    // 0x80070F84: jal         0x80061348
    // 0x80070F88: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070F88: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070F8C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070F90: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070F94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070F98: beq         $v0, $zero, L_80070FD0
    if (ctx->r2 == 0) {
        // 0x80070F9C: nop
    
            goto L_80070FD0;
    }
    // 0x80070F9C: nop

    // 0x80070FA0: jal         0x80061348
    // 0x80070FA4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070FA4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_2:
    // 0x80070FA8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070FAC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070FB0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070FB4: beq         $v0, $zero, L_80070FD0
    if (ctx->r2 == 0) {
        // 0x80070FB8: nop
    
            goto L_80070FD0;
    }
    // 0x80070FB8: nop

    // 0x80070FBC: jal         0x80061348
    // 0x80070FC0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070FC0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070FC4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070FC8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070FCC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070FD0:
    // 0x80070FD0: b           L_80070FE0
    // 0x80070FD4: nop

        goto L_80070FE0;
    // 0x80070FD4: nop

    // 0x80070FD8: b           L_80070FE0
    // 0x80070FDC: nop

        goto L_80070FE0;
    // 0x80070FDC: nop

L_80070FE0:
    // 0x80070FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070FE8: jr          $ra
    // 0x80070FEC: nop

    return;
    // 0x80070FEC: nop

;}
RECOMP_FUNC void func_800784E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800784E8: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800784EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800784F0: sw          $a0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r4;
    // 0x800784F4: sw          $a1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r5;
    // 0x800784F8: sw          $a2, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r6;
    // 0x800784FC: sw          $a3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r7;
    // 0x80078500: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    // 0x80078504: lw          $a2, 0x140($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X140);
    // 0x80078508: lw          $a3, 0x144($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X144);
    // 0x8007850C: jal         0x800B35D4
    // 0x80078510: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    func_800B35D4(rdram, ctx);
        goto after_0;
    // 0x80078510: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    after_0:
    // 0x80078514: sw          $v0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r2;
    // 0x80078518: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x8007851C: nop

    // 0x80078520: bne         $t6, $zero, L_80078530
    if (ctx->r14 != 0) {
        // 0x80078524: nop
    
            goto L_80078530;
    }
    // 0x80078524: nop

    // 0x80078528: b           L_80078618
    // 0x8007852C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078618;
    // 0x8007852C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078530:
    // 0x80078530: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x80078534: lw          $a2, 0x150($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X150);
    // 0x80078538: lw          $a3, 0x154($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X154);
    // 0x8007853C: jal         0x800B35D4
    // 0x80078540: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800B35D4(rdram, ctx);
        goto after_1;
    // 0x80078540: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80078544: sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    // 0x80078548: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x8007854C: nop

    // 0x80078550: bne         $t7, $zero, L_80078560
    if (ctx->r15 != 0) {
        // 0x80078554: nop
    
            goto L_80078560;
    }
    // 0x80078554: nop

    // 0x80078558: b           L_80078618
    // 0x8007855C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078618;
    // 0x8007855C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078560:
    // 0x80078560: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x80078564: lw          $a1, 0x134($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X134);
    // 0x80078568: addiu       $t9, $sp, 0x128
    ctx->r25 = ADD32(ctx->r29, 0X128);
    // 0x8007856C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80078570: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80078574: addiu       $a2, $sp, 0x12C
    ctx->r6 = ADD32(ctx->r29, 0X12C);
    // 0x80078578: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8007857C: jal         0x80078A8C
    // 0x80078580: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80078A8C(rdram, ctx);
        goto after_2;
    // 0x80078580: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x80078584: beq         $v0, $zero, L_80078608
    if (ctx->r2 == 0) {
        // 0x80078588: nop
    
            goto L_80078608;
    }
    // 0x80078588: nop

    // 0x8007858C: sw          $zero, 0x124($sp)
    MEM_W(0X124, ctx->r29) = 0;
L_80078590:
    // 0x80078590: lw          $t0, 0x12C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X12C);
    // 0x80078594: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80078598: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007859C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800785A0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800785A4: lw          $t6, 0x138($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X138);
    // 0x800785A8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800785AC: lwc1        $f4, 0xA4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XA4);
    // 0x800785B0: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800785B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800785B8: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800785BC: lw          $t9, 0x128($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X128);
    // 0x800785C0: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800785C4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800785C8: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800785CC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800785D0: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x800785D4: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800785D8: lwc1        $f6, 0x24($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X24);
    // 0x800785DC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x800785E0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x800785E4: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800785E8: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x800785EC: nop

    // 0x800785F0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800785F4: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800785F8: bne         $at, $zero, L_80078590
    if (ctx->r1 != 0) {
        // 0x800785FC: sw          $t9, 0x124($sp)
        MEM_W(0X124, ctx->r29) = ctx->r25;
            goto L_80078590;
    }
    // 0x800785FC: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80078600: b           L_80078618
    // 0x80078604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078618;
    // 0x80078604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80078608:
    // 0x80078608: b           L_80078618
    // 0x8007860C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80078618;
    // 0x8007860C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80078610: b           L_80078618
    // 0x80078614: nop

        goto L_80078618;
    // 0x80078614: nop

L_80078618:
    // 0x80078618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007861C: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x80078620: jr          $ra
    // 0x80078624: nop

    return;
    // 0x80078624: nop

;}
