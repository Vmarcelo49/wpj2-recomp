#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800731C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800731C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800731C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800731C8: nop

    // 0x800731CC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800731D0: nop

    // 0x800731D4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800731D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800731DC: jr          $ra
    // 0x800731E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800731E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800731E4: jr          $ra
    // 0x800731E8: nop

    return;
    // 0x800731E8: nop

    // 0x800731EC: jr          $ra
    // 0x800731F0: nop

    return;
    // 0x800731F0: nop

;}
RECOMP_FUNC void ContPak_SetFileWriteParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEC80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEC84: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEC88: nop

    // 0x800AEC8C: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AEC90: beq         $t7, $zero, L_800AECA0
    if (ctx->r15 == 0) {
        // 0x800AEC94: nop
    
            goto L_800AECA0;
    }
    // 0x800AEC94: nop

    // 0x800AEC98: jr          $ra
    // 0x800AEC9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEC9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AECA0:
    // 0x800AECA0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AECA4: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AECA8: nop

    // 0x800AECAC: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AECB0: beq         $t9, $zero, L_800AECC0
    if (ctx->r25 == 0) {
        // 0x800AECB4: nop
    
            goto L_800AECC0;
    }
    // 0x800AECB4: nop

    // 0x800AECB8: jr          $ra
    // 0x800AECBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AECBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AECC0:
    // 0x800AECC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AECC4: sw          $a0, 0x167C($at)
    MEM_W(0X167C, ctx->r1) = ctx->r4;
    // 0x800AECC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AECCC: sw          $a1, 0x1678($at)
    MEM_W(0X1678, ctx->r1) = ctx->r5;
    // 0x800AECD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AECD4: sw          $a2, 0x1674($at)
    MEM_W(0X1674, ctx->r1) = ctx->r6;
    // 0x800AECD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AECDC: sw          $a3, 0x1670($at)
    MEM_W(0X1670, ctx->r1) = ctx->r7;
    // 0x800AECE0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AECE4: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800AECE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AECEC: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x800AECF0: sw          $t1, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r9;
    // 0x800AECF4: jr          $ra
    // 0x800AECF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AECF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AECFC: jr          $ra
    // 0x800AED00: nop

    return;
    // 0x800AED00: nop

    // 0x800AED04: jr          $ra
    // 0x800AED08: nop

    return;
    // 0x800AED08: nop

;}
RECOMP_FUNC void __resetPerfChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2024: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x800D2028: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x800D202C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x800D2030: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800D2034: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x800D2038: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x800D203C: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x800D2040: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800D2044: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800D2048: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x800D204C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x800D2050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D2058: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800D205C: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x800D2060: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x800D2064: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x800D2068: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800D206C: sb          $t3, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r11;
    // 0x800D2070: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800D2074: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800D2078: sb          $t6, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r14;
    // 0x800D207C: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x800D2080: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800D2084: sb          $zero, 0xB($t1)
    MEM_B(0XB, ctx->r9) = 0;
    // 0x800D2088: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x800D208C: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x800D2090: sh          $t0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r8;
    // 0x800D2094: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x800D2098: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x800D209C: jr          $ra
    // 0x800D20A0: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    return;
    // 0x800D20A0: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800661D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800661D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800661DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800661E0: jal         0x80061348
    // 0x800661E4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800661E4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x800661E8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800661EC: b           L_800661FC
    // 0x800661F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800661FC;
    // 0x800661F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800661F4: b           L_800661FC
    // 0x800661F8: nop

        goto L_800661FC;
    // 0x800661F8: nop

L_800661FC:
    // 0x800661FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066204: jr          $ra
    // 0x80066208: nop

    return;
    // 0x80066208: nop

;}
RECOMP_FUNC void func_8006F3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F3DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F3E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F3E4: nop

    // 0x8006F3E8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F3EC: nop

    // 0x8006F3F0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006F3F4: jr          $ra
    // 0x8006F3F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F3F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F3FC: jr          $ra
    // 0x8006F400: nop

    return;
    // 0x8006F400: nop

    // 0x8006F404: jr          $ra
    // 0x8006F408: nop

    return;
    // 0x8006F408: nop

;}
RECOMP_FUNC void func_8008312C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008312C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80083130: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083134: lw          $t6, 0x165C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X165C);
    // 0x80083138: nop

    // 0x8008313C: bne         $t6, $zero, L_8008314C
    if (ctx->r14 != 0) {
        // 0x80083140: nop
    
            goto L_8008314C;
    }
    // 0x80083140: nop

    // 0x80083144: b           L_800831D8
    // 0x80083148: nop

        goto L_800831D8;
    // 0x80083148: nop

L_8008314C:
    // 0x8008314C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80083150: lw          $t7, 0x165C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X165C);
    // 0x80083154: nop

    // 0x80083158: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_8008315C:
    // 0x8008315C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80083160: nop

    // 0x80083164: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x80083168: nop

    // 0x8008316C: bne         $t9, $a0, L_800831B8
    if (ctx->r25 != ctx->r4) {
        // 0x80083170: nop
    
            goto L_800831B8;
    }
    // 0x80083170: nop

    // 0x80083174: beq         $a2, $zero, L_80083198
    if (ctx->r6 == 0) {
        // 0x80083178: nop
    
            goto L_80083198;
    }
    // 0x80083178: nop

    // 0x8008317C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80083180: nop

    // 0x80083184: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80083188: nop

    // 0x8008318C: or          $t2, $t1, $a1
    ctx->r10 = ctx->r9 | ctx->r5;
    // 0x80083190: b           L_800831B0
    // 0x80083194: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
        goto L_800831B0;
    // 0x80083194: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
L_80083198:
    // 0x80083198: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008319C: nor         $t5, $a1, $zero
    ctx->r13 = ~(ctx->r5 | 0);
    // 0x800831A0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800831A4: nop

    // 0x800831A8: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x800831AC: sb          $t6, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r14;
L_800831B0:
    // 0x800831B0: b           L_800831D0
    // 0x800831B4: nop

        goto L_800831D0;
    // 0x800831B4: nop

L_800831B8:
    // 0x800831B8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800831BC: nop

    // 0x800831C0: lw          $t8, 0x44($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X44);
    // 0x800831C4: nop

    // 0x800831C8: bne         $t8, $zero, L_8008315C
    if (ctx->r24 != 0) {
        // 0x800831CC: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_8008315C;
    }
    // 0x800831CC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_800831D0:
    // 0x800831D0: b           L_800831D8
    // 0x800831D4: nop

        goto L_800831D8;
    // 0x800831D4: nop

L_800831D8:
    // 0x800831D8: jr          $ra
    // 0x800831DC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800831DC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80086588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008658C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086594: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086598: jal         0x8008BFF4
    // 0x8008659C: nop

    func_8008BFF4(rdram, ctx);
        goto after_0;
    // 0x8008659C: nop

    after_0:
    // 0x800865A0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800865A4: nop

    // 0x800865A8: sh          $zero, 0xC14($t6)
    MEM_H(0XC14, ctx->r14) = 0;
    // 0x800865AC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800865B0: nop

    // 0x800865B4: lh          $a1, 0xBE8($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XBE8);
    // 0x800865B8: jal         0x8008C2E8
    // 0x800865BC: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_1;
    // 0x800865BC: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    after_1:
    // 0x800865C0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800865C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800865C8: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x800865CC: jal         0x800AEA98
    // 0x800865D0: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_2;
    // 0x800865D0: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_2:
    // 0x800865D4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800865D8: nop

    // 0x800865DC: lh          $v0, 0x4($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X4);
    // 0x800865E0: b           L_800865F0
    // 0x800865E4: nop

        goto L_800865F0;
    // 0x800865E4: nop

    // 0x800865E8: b           L_800865F0
    // 0x800865EC: nop

        goto L_800865F0;
    // 0x800865EC: nop

L_800865F0:
    // 0x800865F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800865F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800865F8: jr          $ra
    // 0x800865FC: nop

    return;
    // 0x800865FC: nop

;}
RECOMP_FUNC void func_80064FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064FB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064FBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064FC0: nop

    // 0x80064FC4: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x80064FC8: nop

    // 0x80064FCC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064FD0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064FD4: jr          $ra
    // 0x80064FD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064FD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064FDC: jr          $ra
    // 0x80064FE0: nop

    return;
    // 0x80064FE0: nop

    // 0x80064FE4: jr          $ra
    // 0x80064FE8: nop

    return;
    // 0x80064FE8: nop

;}
RECOMP_FUNC void func_8000E678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E678: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E680: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000E684: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000E688: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000E68C: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x8000E690: nop

    // 0x8000E694: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E698: bne         $at, $zero, L_8000E6E8
    if (ctx->r1 != 0) {
        // 0x8000E69C: nop
    
            goto L_8000E6E8;
    }
    // 0x8000E69C: nop

    // 0x8000E6A0: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x8000E6A4: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E6A8: beq         $at, $zero, L_8000E6E8
    if (ctx->r1 == 0) {
        // 0x8000E6AC: nop
    
            goto L_8000E6E8;
    }
    // 0x8000E6AC: nop

    // 0x8000E6B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000E6B4: nop

    // 0x8000E6B8: lw          $t9, 0x1A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A8);
    // 0x8000E6BC: nop

    // 0x8000E6C0: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8000E6C4: beq         $t0, $zero, L_8000E6E0
    if (ctx->r8 == 0) {
        // 0x8000E6C8: nop
    
            goto L_8000E6E0;
    }
    // 0x8000E6C8: nop

    // 0x8000E6CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E6D0: jal         0x8000D74C
    // 0x8000E6D4: nop

    func_8000D74C(rdram, ctx);
        goto after_0;
    // 0x8000E6D4: nop

    after_0:
    // 0x8000E6D8: b           L_8000E7D4
    // 0x8000E6DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E7D4;
    // 0x8000E6DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E6E0:
    // 0x8000E6E0: b           L_8000E7C4
    // 0x8000E6E4: nop

        goto L_8000E7C4;
    // 0x8000E6E4: nop

L_8000E6E8:
    // 0x8000E6E8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8000E6EC: nop

    // 0x8000E6F0: lw          $t2, 0x1AC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1AC);
    // 0x8000E6F4: nop

    // 0x8000E6F8: slti        $at, $t2, 0x4000
    ctx->r1 = SIGNED(ctx->r10) < 0X4000 ? 1 : 0;
    // 0x8000E6FC: bne         $at, $zero, L_8000E758
    if (ctx->r1 != 0) {
        // 0x8000E700: nop
    
            goto L_8000E758;
    }
    // 0x8000E700: nop

    // 0x8000E704: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000E708: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E70C: beq         $at, $zero, L_8000E758
    if (ctx->r1 == 0) {
        // 0x8000E710: nop
    
            goto L_8000E758;
    }
    // 0x8000E710: nop

    // 0x8000E714: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8000E718: nop

    // 0x8000E71C: lw          $t4, 0x20C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20C);
    // 0x8000E720: nop

    // 0x8000E724: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8000E728: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E72C: nop

    // 0x8000E730: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8000E734: nop

    // 0x8000E738: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8000E73C: beq         $t7, $zero, L_8000E750
    if (ctx->r15 == 0) {
        // 0x8000E740: nop
    
            goto L_8000E750;
    }
    // 0x8000E740: nop

    // 0x8000E744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E748: jal         0x80015BD0
    // 0x8000E74C: nop

    func_80015BD0(rdram, ctx);
        goto after_1;
    // 0x8000E74C: nop

    after_1:
L_8000E750:
    // 0x8000E750: b           L_8000E7C4
    // 0x8000E754: nop

        goto L_8000E7C4;
    // 0x8000E754: nop

L_8000E758:
    // 0x8000E758: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000E75C: nop

    // 0x8000E760: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x8000E764: nop

    // 0x8000E768: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000E76C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E770: nop

    // 0x8000E774: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000E778: nop

    // 0x8000E77C: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x8000E780: beq         $t2, $zero, L_8000E79C
    if (ctx->r10 == 0) {
        // 0x8000E784: nop
    
            goto L_8000E79C;
    }
    // 0x8000E784: nop

    // 0x8000E788: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E78C: jal         0x8000F53C
    // 0x8000E790: nop

    func_8000F53C(rdram, ctx);
        goto after_2;
    // 0x8000E790: nop

    after_2:
    // 0x8000E794: b           L_8000E7D4
    // 0x8000E798: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E7D4;
    // 0x8000E798: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E79C:
    // 0x8000E79C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E7A0: nop

    // 0x8000E7A4: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000E7A8: nop

    // 0x8000E7AC: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8000E7B0: beq         $t5, $zero, L_8000E7C4
    if (ctx->r13 == 0) {
        // 0x8000E7B4: nop
    
            goto L_8000E7C4;
    }
    // 0x8000E7B4: nop

    // 0x8000E7B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E7BC: jal         0x8000F598
    // 0x8000E7C0: nop

    func_8000F598(rdram, ctx);
        goto after_3;
    // 0x8000E7C0: nop

    after_3:
L_8000E7C4:
    // 0x8000E7C4: b           L_8000E7D4
    // 0x8000E7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E7D4;
    // 0x8000E7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E7CC: b           L_8000E7D4
    // 0x8000E7D0: nop

        goto L_8000E7D4;
    // 0x8000E7D0: nop

L_8000E7D4:
    // 0x8000E7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E7D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E7DC: jr          $ra
    // 0x8000E7E0: nop

    return;
    // 0x8000E7E0: nop

;}
RECOMP_FUNC void func_800766EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800766EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800766F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800766F4: jal         0x80061348
    // 0x800766F8: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800766F8: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x800766FC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076700: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076704: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076708: beq         $v0, $zero, L_80076740
    if (ctx->r2 == 0) {
        // 0x8007670C: nop
    
            goto L_80076740;
    }
    // 0x8007670C: nop

    // 0x80076710: jal         0x80061348
    // 0x80076714: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076714: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x80076718: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007671C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076720: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076724: beq         $v0, $zero, L_80076740
    if (ctx->r2 == 0) {
        // 0x80076728: nop
    
            goto L_80076740;
    }
    // 0x80076728: nop

    // 0x8007672C: jal         0x80061348
    // 0x80076730: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076730: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x80076734: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80076738: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007673C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80076740:
    // 0x80076740: b           L_80076750
    // 0x80076744: nop

        goto L_80076750;
    // 0x80076744: nop

    // 0x80076748: b           L_80076750
    // 0x8007674C: nop

        goto L_80076750;
    // 0x8007674C: nop

L_80076750:
    // 0x80076750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076758: jr          $ra
    // 0x8007675C: nop

    return;
    // 0x8007675C: nop

;}
RECOMP_FUNC void func_800848B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800848B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800848BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800848C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800848C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800848C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800848CC: nop

    // 0x800848D0: lh          $s0, 0xC14($t6)
    ctx->r16 = MEM_H(ctx->r14, 0XC14);
    // 0x800848D4: nop

    // 0x800848D8: beq         $s0, $zero, L_8008490C
    if (ctx->r16 == 0) {
        // 0x800848DC: nop
    
            goto L_8008490C;
    }
    // 0x800848DC: nop

    // 0x800848E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800848E4: beq         $s0, $at, L_80084A70
    if (ctx->r16 == ctx->r1) {
        // 0x800848E8: nop
    
            goto L_80084A70;
    }
    // 0x800848E8: nop

    // 0x800848EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800848F0: beq         $s0, $at, L_80084B34
    if (ctx->r16 == ctx->r1) {
        // 0x800848F4: nop
    
            goto L_80084B34;
    }
    // 0x800848F4: nop

    // 0x800848F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800848FC: beq         $s0, $at, L_80084C80
    if (ctx->r16 == ctx->r1) {
        // 0x80084900: nop
    
            goto L_80084C80;
    }
    // 0x80084900: nop

    // 0x80084904: b           L_80084D2C
    // 0x80084908: nop

        goto L_80084D2C;
    // 0x80084908: nop

L_8008490C:
    // 0x8008490C: jal         0x800AEBF4
    // 0x80084910: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_0;
    // 0x80084910: nop

    after_0:
    // 0x80084914: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80084918: nop

    // 0x8008491C: sw          $v0, 0xC00($t7)
    MEM_W(0XC00, ctx->r15) = ctx->r2;
    // 0x80084920: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084924: addiu       $at, $zero, 0x1005
    ctx->r1 = ADD32(0, 0X1005);
    // 0x80084928: lw          $t9, 0xC00($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC00);
    // 0x8008492C: nop

    // 0x80084930: bne         $t9, $at, L_80084978
    if (ctx->r25 != ctx->r1) {
        // 0x80084934: nop
    
            goto L_80084978;
    }
    // 0x80084934: nop

    // 0x80084938: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008493C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80084940: lh          $a1, 0x7A16($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7A16);
    // 0x80084944: jal         0x8008C2E8
    // 0x80084948: addiu       $a0, $a0, 0xBEE
    ctx->r4 = ADD32(ctx->r4, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_1;
    // 0x80084948: addiu       $a0, $a0, 0xBEE
    ctx->r4 = ADD32(ctx->r4, 0XBEE);
    after_1:
    // 0x8008494C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80084950: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084954: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80084958: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    // 0x8008495C: jal         0x800AE880
    // 0x80084960: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetOpenFileParams(rdram, ctx);
        goto after_2;
    // 0x80084960: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_2:
    // 0x80084964: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084968: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008496C: sh          $t0, 0xC14($t1)
    MEM_H(0XC14, ctx->r9) = ctx->r8;
    // 0x80084970: b           L_80084D2C
    // 0x80084974: nop

        goto L_80084D2C;
    // 0x80084974: nop

L_80084978:
    // 0x80084978: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008497C: nop

    // 0x80084980: lw          $t3, 0xC00($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC00);
    // 0x80084984: nop

    // 0x80084988: bltz        $t3, L_80084A10
    if (SIGNED(ctx->r11) < 0) {
        // 0x8008498C: nop
    
            goto L_80084A10;
    }
    // 0x8008498C: nop

    // 0x80084990: slti        $at, $t3, 0x1000
    ctx->r1 = SIGNED(ctx->r11) < 0X1000 ? 1 : 0;
    // 0x80084994: beq         $at, $zero, L_80084A10
    if (ctx->r1 == 0) {
        // 0x80084998: nop
    
            goto L_80084A10;
    }
    // 0x80084998: nop

    // 0x8008499C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800849A0: nop

    // 0x800849A4: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x800849A8: nop

    // 0x800849AC: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x800849B0: beq         $t6, $zero, L_800849E4
    if (ctx->r14 == 0) {
        // 0x800849B4: nop
    
            goto L_800849E4;
    }
    // 0x800849B4: nop

    // 0x800849B8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800849BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800849C0: lw          $a0, 0xC00($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC00);
    // 0x800849C4: lw          $a3, 0xC10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC10);
    // 0x800849C8: jal         0x800AEE6C
    // 0x800849CC: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileReadParams(rdram, ctx);
        goto after_3;
    // 0x800849CC: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_3:
    // 0x800849D0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800849D4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800849D8: sh          $t8, 0xC14($t9)
    MEM_H(0XC14, ctx->r25) = ctx->r24;
    // 0x800849DC: b           L_80084D2C
    // 0x800849E0: nop

        goto L_80084D2C;
    // 0x800849E0: nop

L_800849E4:
    // 0x800849E4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800849E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800849EC: lw          $a0, 0xC00($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC00);
    // 0x800849F0: lw          $a3, 0xC10($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC10);
    // 0x800849F4: jal         0x800AEC80
    // 0x800849F8: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_4;
    // 0x800849F8: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_4:
    // 0x800849FC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80084A00: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80084A04: sh          $t1, 0xC14($t2)
    MEM_H(0XC14, ctx->r10) = ctx->r9;
    // 0x80084A08: b           L_80084D2C
    // 0x80084A0C: nop

        goto L_80084D2C;
    // 0x80084A0C: nop

L_80084A10:
    // 0x80084A10: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084A14: nop

    // 0x80084A18: lw          $t4, 0xC00($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC00);
    // 0x80084A1C: nop

    // 0x80084A20: slti        $at, $t4, 0x1000
    ctx->r1 = SIGNED(ctx->r12) < 0X1000 ? 1 : 0;
    // 0x80084A24: bne         $at, $zero, L_80084A68
    if (ctx->r1 != 0) {
        // 0x80084A28: nop
    
            goto L_80084A68;
    }
    // 0x80084A28: nop

    // 0x80084A2C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084A30: nop

    // 0x80084A34: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80084A38: nop

    // 0x80084A3C: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80084A40: beq         $t7, $zero, L_80084A54
    if (ctx->r15 == 0) {
        // 0x80084A44: nop
    
            goto L_80084A54;
    }
    // 0x80084A44: nop

    // 0x80084A48: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084A4C: b           L_80084A60
    // 0x80084A50: sh          $zero, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = 0;
        goto L_80084A60;
    // 0x80084A50: sh          $zero, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = 0;
L_80084A54:
    // 0x80084A54: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084A58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80084A5C: sh          $t9, 0xBEC($t0)
    MEM_H(0XBEC, ctx->r8) = ctx->r25;
L_80084A60:
    // 0x80084A60: b           L_80084D48
    // 0x80084A64: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80084D48;
    // 0x80084A64: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084A68:
    // 0x80084A68: b           L_80084D2C
    // 0x80084A6C: nop

        goto L_80084D2C;
    // 0x80084A6C: nop

L_80084A70:
    // 0x80084A70: jal         0x800AEA0C
    // 0x80084A74: nop

    ContPak_GetOpenFileResult(rdram, ctx);
        goto after_5;
    // 0x80084A74: nop

    after_5:
    // 0x80084A78: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084A7C: nop

    // 0x80084A80: sw          $v0, 0xC00($t1)
    MEM_W(0XC00, ctx->r9) = ctx->r2;
    // 0x80084A84: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80084A88: nop

    // 0x80084A8C: lw          $t3, 0xC00($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC00);
    // 0x80084A90: nop

    // 0x80084A94: bltz        $t3, L_80084AD4
    if (SIGNED(ctx->r11) < 0) {
        // 0x80084A98: nop
    
            goto L_80084AD4;
    }
    // 0x80084A98: nop

    // 0x80084A9C: slti        $at, $t3, 0x1000
    ctx->r1 = SIGNED(ctx->r11) < 0X1000 ? 1 : 0;
    // 0x80084AA0: beq         $at, $zero, L_80084AD4
    if (ctx->r1 == 0) {
        // 0x80084AA4: nop
    
            goto L_80084AD4;
    }
    // 0x80084AA4: nop

    // 0x80084AA8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80084AAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084AB0: lw          $a0, 0xC00($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC00);
    // 0x80084AB4: lw          $a3, 0xC10($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XC10);
    // 0x80084AB8: jal         0x800AEC80
    // 0x80084ABC: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_6;
    // 0x80084ABC: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_6:
    // 0x80084AC0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80084AC4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80084AC8: sh          $t5, 0xC14($t6)
    MEM_H(0XC14, ctx->r14) = ctx->r13;
    // 0x80084ACC: b           L_80084D2C
    // 0x80084AD0: nop

        goto L_80084D2C;
    // 0x80084AD0: nop

L_80084AD4:
    // 0x80084AD4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80084AD8: nop

    // 0x80084ADC: lw          $t8, 0xC00($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC00);
    // 0x80084AE0: nop

    // 0x80084AE4: slti        $at, $t8, 0x1000
    ctx->r1 = SIGNED(ctx->r24) < 0X1000 ? 1 : 0;
    // 0x80084AE8: bne         $at, $zero, L_80084B2C
    if (ctx->r1 != 0) {
        // 0x80084AEC: nop
    
            goto L_80084B2C;
    }
    // 0x80084AEC: nop

    // 0x80084AF0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084AF4: nop

    // 0x80084AF8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80084AFC: nop

    // 0x80084B00: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80084B04: beq         $t1, $zero, L_80084B18
    if (ctx->r9 == 0) {
        // 0x80084B08: nop
    
            goto L_80084B18;
    }
    // 0x80084B08: nop

    // 0x80084B0C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80084B10: b           L_80084B24
    // 0x80084B14: sh          $zero, 0xBEC($t2)
    MEM_H(0XBEC, ctx->r10) = 0;
        goto L_80084B24;
    // 0x80084B14: sh          $zero, 0xBEC($t2)
    MEM_H(0XBEC, ctx->r10) = 0;
L_80084B18:
    // 0x80084B18: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80084B1C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80084B20: sh          $t3, 0xBEC($t4)
    MEM_H(0XBEC, ctx->r12) = ctx->r11;
L_80084B24:
    // 0x80084B24: b           L_80084D48
    // 0x80084B28: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80084D48;
    // 0x80084B28: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084B2C:
    // 0x80084B2C: b           L_80084D2C
    // 0x80084B30: nop

        goto L_80084D2C;
    // 0x80084B30: nop

L_80084B34:
    // 0x80084B34: jal         0x800AEDE8
    // 0x80084B38: nop

    ContPak_GetWriteFileResult(rdram, ctx);
        goto after_7;
    // 0x80084B38: nop

    after_7:
    // 0x80084B3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80084B40: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80084B44: nop

    // 0x80084B48: bne         $t5, $zero, L_80084C28
    if (ctx->r13 != 0) {
        // 0x80084B4C: nop
    
            goto L_80084C28;
    }
    // 0x80084B4C: nop

    // 0x80084B50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80084B54: lh          $t6, 0x7A16($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7A16);
    // 0x80084B58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80084B5C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80084B60: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80084B64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80084B68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80084B6C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80084B70: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80084B74: addiu       $t8, $t8, 0x7AE8
    ctx->r24 = ADD32(ctx->r24, 0X7AE8);
    // 0x80084B78: lw          $a1, 0xC10($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC10);
    // 0x80084B7C: jal         0x8008C558
    // 0x80084B80: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    func_8008C558(rdram, ctx);
        goto after_8;
    // 0x80084B80: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_8:
    // 0x80084B84: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084B88: nop

    // 0x80084B8C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80084B90: nop

    // 0x80084B94: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x80084B98: bne         $t2, $zero, L_80084C20
    if (ctx->r10 != 0) {
        // 0x80084B9C: nop
    
            goto L_80084C20;
    }
    // 0x80084B9C: nop

    // 0x80084BA0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084BA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80084BA8: lh          $t4, 0xBEC($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XBEC);
    // 0x80084BAC: nop

    // 0x80084BB0: bne         $t4, $at, L_80084BEC
    if (ctx->r12 != ctx->r1) {
        // 0x80084BB4: nop
    
            goto L_80084BEC;
    }
    // 0x80084BB4: nop

    // 0x80084BB8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80084BBC: lh          $t5, 0x7A16($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7A16);
    // 0x80084BC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80084BC4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80084BC8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80084BCC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80084BD0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80084BD4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80084BD8: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x80084BDC: jal         0x8008C6E0
    // 0x80084BE0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    func_8008C6E0(rdram, ctx);
        goto after_9;
    // 0x80084BE0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_9:
    // 0x80084BE4: b           L_80084C20
    // 0x80084BE8: nop

        goto L_80084C20;
    // 0x80084BE8: nop

L_80084BEC:
    // 0x80084BEC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80084BF0: lh          $t9, 0x7A16($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7A16);
    // 0x80084BF4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084BF8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80084BFC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80084C00: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80084C04: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80084C08: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80084C0C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80084C10: addiu       $t1, $t1, 0x7AE8
    ctx->r9 = ADD32(ctx->r9, 0X7AE8);
    // 0x80084C14: lw          $a0, 0xC10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC10);
    // 0x80084C18: jal         0x8008C634
    // 0x80084C1C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_8008C634(rdram, ctx);
        goto after_10;
    // 0x80084C1C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_10:
L_80084C20:
    // 0x80084C20: b           L_80084D48
    // 0x80084C24: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80084D48;
    // 0x80084C24: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80084C28:
    // 0x80084C28: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80084C2C: nop

    // 0x80084C30: slti        $at, $t2, 0x1000
    ctx->r1 = SIGNED(ctx->r10) < 0X1000 ? 1 : 0;
    // 0x80084C34: bne         $at, $zero, L_80084C78
    if (ctx->r1 != 0) {
        // 0x80084C38: nop
    
            goto L_80084C78;
    }
    // 0x80084C38: nop

    // 0x80084C3C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084C40: nop

    // 0x80084C44: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80084C48: nop

    // 0x80084C4C: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80084C50: beq         $t5, $zero, L_80084C64
    if (ctx->r13 == 0) {
        // 0x80084C54: nop
    
            goto L_80084C64;
    }
    // 0x80084C54: nop

    // 0x80084C58: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80084C5C: b           L_80084C70
    // 0x80084C60: sh          $zero, 0xBEC($t6)
    MEM_H(0XBEC, ctx->r14) = 0;
        goto L_80084C70;
    // 0x80084C60: sh          $zero, 0xBEC($t6)
    MEM_H(0XBEC, ctx->r14) = 0;
L_80084C64:
    // 0x80084C64: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084C68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80084C6C: sh          $t7, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = ctx->r15;
L_80084C70:
    // 0x80084C70: b           L_80084D48
    // 0x80084C74: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80084D48;
    // 0x80084C74: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084C78:
    // 0x80084C78: b           L_80084D2C
    // 0x80084C7C: nop

        goto L_80084D2C;
    // 0x80084C7C: nop

L_80084C80:
    // 0x80084C80: jal         0x800AEFD4
    // 0x80084C84: nop

    ContPak_GetReadFileResult(rdram, ctx);
        goto after_11;
    // 0x80084C84: nop

    after_11:
    // 0x80084C88: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80084C8C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80084C90: nop

    // 0x80084C94: bne         $t9, $zero, L_80084CDC
    if (ctx->r25 != 0) {
        // 0x80084C98: nop
    
            goto L_80084CDC;
    }
    // 0x80084C98: nop

    // 0x80084C9C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084CA0: nop

    // 0x80084CA4: lw          $a0, 0xC10($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC10);
    // 0x80084CA8: jal         0x8008C528
    // 0x80084CAC: addiu       $a1, $t0, 0xE
    ctx->r5 = ADD32(ctx->r8, 0XE);
    func_8008C528(rdram, ctx);
        goto after_12;
    // 0x80084CAC: addiu       $a1, $t0, 0xE
    ctx->r5 = ADD32(ctx->r8, 0XE);
    after_12:
    // 0x80084CB0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084CB8: lw          $a0, 0xC00($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC00);
    // 0x80084CBC: lw          $a3, 0xC10($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XC10);
    // 0x80084CC0: jal         0x800AEC80
    // 0x80084CC4: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_13;
    // 0x80084CC4: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_13:
    // 0x80084CC8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80084CCC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80084CD0: sh          $t2, 0xC14($t3)
    MEM_H(0XC14, ctx->r11) = ctx->r10;
    // 0x80084CD4: b           L_80084D2C
    // 0x80084CD8: nop

        goto L_80084D2C;
    // 0x80084CD8: nop

L_80084CDC:
    // 0x80084CDC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80084CE0: nop

    // 0x80084CE4: slti        $at, $t4, 0x1000
    ctx->r1 = SIGNED(ctx->r12) < 0X1000 ? 1 : 0;
    // 0x80084CE8: bne         $at, $zero, L_80084D2C
    if (ctx->r1 != 0) {
        // 0x80084CEC: nop
    
            goto L_80084D2C;
    }
    // 0x80084CEC: nop

    // 0x80084CF0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80084CF4: nop

    // 0x80084CF8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80084CFC: nop

    // 0x80084D00: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80084D04: beq         $t7, $zero, L_80084D18
    if (ctx->r15 == 0) {
        // 0x80084D08: nop
    
            goto L_80084D18;
    }
    // 0x80084D08: nop

    // 0x80084D0C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80084D10: b           L_80084D24
    // 0x80084D14: sh          $zero, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = 0;
        goto L_80084D24;
    // 0x80084D14: sh          $zero, 0xBEC($t8)
    MEM_H(0XBEC, ctx->r24) = 0;
L_80084D18:
    // 0x80084D18: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80084D1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80084D20: sh          $t9, 0xBEC($t0)
    MEM_H(0XBEC, ctx->r8) = ctx->r25;
L_80084D24:
    // 0x80084D24: b           L_80084D48
    // 0x80084D28: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80084D48;
    // 0x80084D28: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80084D2C:
    // 0x80084D2C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80084D30: nop

    // 0x80084D34: lh          $v0, 0x4($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X4);
    // 0x80084D38: b           L_80084D48
    // 0x80084D3C: nop

        goto L_80084D48;
    // 0x80084D3C: nop

    // 0x80084D40: b           L_80084D48
    // 0x80084D44: nop

        goto L_80084D48;
    // 0x80084D44: nop

L_80084D48:
    // 0x80084D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80084D4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084D50: jr          $ra
    // 0x80084D54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80084D54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001ABEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ABEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ABF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ABF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001ABF8: jal         0x80096474
    // 0x8001ABFC: nop

    func_80096474(rdram, ctx);
        goto after_0;
    // 0x8001ABFC: nop

    after_0:
    // 0x8001AC00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001AC04: nop

    // 0x8001AC08: lw          $a0, 0x20C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20C);
    // 0x8001AC0C: jal         0x800962B0
    // 0x8001AC10: nop

    func_800962B0(rdram, ctx);
        goto after_1;
    // 0x8001AC10: nop

    after_1:
    // 0x8001AC14: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001AC18: lhu         $t8, 0x24FC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X24FC);
    // 0x8001AC1C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8001AC20: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001AC24: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001AC28: lw          $a0, 0x12C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X12C);
    // 0x8001AC2C: jal         0x8008ECCC
    // 0x8001AC30: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_2;
    // 0x8001AC30: nop

    after_2:
    // 0x8001AC34: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001AC38: lhu         $t2, 0x24FC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X24FC);
    // 0x8001AC3C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8001AC40: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001AC44: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8001AC48: lw          $t5, 0x12C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12C);
    // 0x8001AC4C: nop

    // 0x8001AC50: sw          $t5, 0x128($t1)
    MEM_W(0X128, ctx->r9) = ctx->r13;
    // 0x8001AC54: b           L_8001AC64
    // 0x8001AC58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AC64;
    // 0x8001AC58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AC5C: b           L_8001AC64
    // 0x8001AC60: nop

        goto L_8001AC64;
    // 0x8001AC60: nop

L_8001AC64:
    // 0x8001AC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001AC6C: jr          $ra
    // 0x8001AC70: nop

    return;
    // 0x8001AC70: nop

;}
RECOMP_FUNC void func_800632D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800632D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800632D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800632DC: jal         0x8005F064
    // 0x800632E0: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800632E0: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_0:
    // 0x800632E4: b           L_800632F4
    // 0x800632E8: nop

        goto L_800632F4;
    // 0x800632E8: nop

    // 0x800632EC: b           L_800632F4
    // 0x800632F0: nop

        goto L_800632F4;
    // 0x800632F0: nop

L_800632F4:
    // 0x800632F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800632F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800632FC: jr          $ra
    // 0x80063300: nop

    return;
    // 0x80063300: nop

;}
RECOMP_FUNC void func_800C38F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C38F4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C38F8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800C38FC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3900: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3904: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3908: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C390C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800C3910: nop

    // 0x800C3914: bc1f        L_800C394C
    if (!c1cs) {
        // 0x800C3918: nop
    
            goto L_800C394C;
    }
    // 0x800C3918: nop

    // 0x800C391C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C3920: nop

    // 0x800C3924: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C3928: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800C392C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3930: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C3934: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3938: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x800C393C: nop

    // 0x800C3940: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800C3944: b           L_800C3998
    // 0x800C3948: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
        goto L_800C3998;
    // 0x800C3948: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
L_800C394C:
    // 0x800C394C: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800C3950: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C3954: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3958: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x800C395C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x800C3960: nop

    // 0x800C3964: bc1f        L_800C3998
    if (!c1cs) {
        // 0x800C3968: nop
    
            goto L_800C3998;
    }
    // 0x800C3968: nop

    // 0x800C396C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800C3970: nop

    // 0x800C3974: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C3978: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800C397C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3980: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3984: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3988: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800C398C: nop

    // 0x800C3990: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800C3994: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_800C3998:
    // 0x800C3998: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C399C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C39A0: lwc1        $f5, -0x148($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X148);
    // 0x800C39A4: lwc1        $f4, -0x144($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X144);
    // 0x800C39A8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C39AC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C39B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C39B4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C39B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C39BC: nop

    // 0x800C39C0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800C39C4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800C39C8: nop

    // 0x800C39CC: div.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x800C39D0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800C39D4: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x800C39D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C39DC: nop

    // 0x800C39E0: beq         $t0, $zero, L_800C3A18
    if (ctx->r8 == 0) {
        // 0x800C39E4: nop
    
            goto L_800C3A18;
    }
    // 0x800C39E4: nop

    // 0x800C39E8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800C39EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C39F0: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800C39F4: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800C39F8: lwc1        $f9, -0x140($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X140);
    // 0x800C39FC: lwc1        $f8, -0x13C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X13C);
    // 0x800C3A00: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800C3A04: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x800C3A08: sub.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d - ctx->f16.d;
    // 0x800C3A0C: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800C3A10: b           L_800C3A2C
    // 0x800C3A14: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
        goto L_800C3A2C;
    // 0x800C3A14: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_800C3A18:
    // 0x800C3A18: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800C3A1C: b           L_800C3A2C
    // 0x800C3A20: nop

        goto L_800C3A2C;
    // 0x800C3A20: nop

    // 0x800C3A24: b           L_800C3A2C
    // 0x800C3A28: nop

        goto L_800C3A2C;
    // 0x800C3A28: nop

L_800C3A2C:
    // 0x800C3A2C: jr          $ra
    // 0x800C3A30: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C3A30: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80067AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067ACC: jal         0x80061348
    // 0x80067AD0: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067AD0: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    after_0:
    // 0x80067AD4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80067AD8: b           L_80067AE8
    // 0x80067ADC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067AE8;
    // 0x80067ADC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067AE0: b           L_80067AE8
    // 0x80067AE4: nop

        goto L_80067AE8;
    // 0x80067AE4: nop

L_80067AE8:
    // 0x80067AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067AF0: jr          $ra
    // 0x80067AF4: nop

    return;
    // 0x80067AF4: nop

;}
RECOMP_FUNC void func_80081B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081B00: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80081B04: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80081B08: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80081B0C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80081B10: addiu       $t6, $t6, 0x2830
    ctx->r14 = ADD32(ctx->r14, 0X2830);
    // 0x80081B14: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80081B18: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80081B1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081B20: beq         $t7, $at, L_80081B78
    if (ctx->r15 == ctx->r1) {
        // 0x80081B24: nop
    
            goto L_80081B78;
    }
    // 0x80081B24: nop

L_80081B28:
    // 0x80081B28: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80081B2C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80081B30: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80081B34: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80081B38: lh          $t0, 0x2830($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X2830);
    // 0x80081B3C: nop

    // 0x80081B40: bne         $t0, $a0, L_80081B54
    if (ctx->r8 != ctx->r4) {
        // 0x80081B44: nop
    
            goto L_80081B54;
    }
    // 0x80081B44: nop

    // 0x80081B48: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80081B4C: b           L_80081B88
    // 0x80081B50: nop

        goto L_80081B88;
    // 0x80081B50: nop

L_80081B54:
    // 0x80081B54: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80081B58: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80081B5C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80081B60: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80081B64: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80081B68: lh          $t4, 0x2830($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2830);
    // 0x80081B6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081B70: bne         $t4, $at, L_80081B28
    if (ctx->r12 != ctx->r1) {
        // 0x80081B74: sw          $t2, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r10;
            goto L_80081B28;
    }
    // 0x80081B74: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
L_80081B78:
    // 0x80081B78: b           L_80081B88
    // 0x80081B7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80081B88;
    // 0x80081B7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80081B80: b           L_80081B88
    // 0x80081B84: nop

        goto L_80081B88;
    // 0x80081B84: nop

L_80081B88:
    // 0x80081B88: jr          $ra
    // 0x80081B8C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80081B8C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C3F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3F2C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C3F30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C3F34: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800C3F38: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C3F3C: nop

    // 0x800C3F40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C3F44: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C3F48: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800C3F4C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800C3F50: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800C3F54: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C3F58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3F5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C3F60: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x800C3F64: nop

    // 0x800C3F68: bc1t        L_800C4060
    if (c1cs) {
        // 0x800C3F6C: nop
    
            goto L_800C4060;
    }
    // 0x800C3F6C: nop

    // 0x800C3F70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C3F74: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C3F78: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C3F7C: nop

    // 0x800C3F80: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800C3F84: nop

    // 0x800C3F88: bc1f        L_800C4028
    if (!c1cs) {
        // 0x800C3F8C: nop
    
            goto L_800C4028;
    }
    // 0x800C3F8C: nop

    // 0x800C3F90: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C3F94: nop

    // 0x800C3F98: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800C3F9C: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800C3FA0: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C3FA4: nop

    // 0x800C3FA8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800C3FAC: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800C3FB0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C3FB4: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C3FB8: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800C3FBC: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C3FC0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C3FC4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800C3FC8: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800C3FCC: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800C3FD0: nop

    // 0x800C3FD4: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800C3FD8: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x800C3FDC: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800C3FE0: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C3FE4: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C3FE8: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C3FEC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C3FF0: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800C3FF4: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x800C3FF8: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800C3FFC: nop

    // 0x800C4000: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C4004: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800C4008: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800C400C: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C4010: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C4014: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800C4018: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C401C: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800C4020: b           L_800C4058
    // 0x800C4024: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
        goto L_800C4058;
    // 0x800C4024: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_800C4028:
    // 0x800C4028: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C402C: nop

    // 0x800C4030: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800C4034: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800C4038: nop

    // 0x800C403C: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800C4040: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800C4044: nop

    // 0x800C4048: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x800C404C: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800C4050: nop

    // 0x800C4054: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
L_800C4058:
    // 0x800C4058: b           L_800C4070
    // 0x800C405C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C4070;
    // 0x800C405C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C4060:
    // 0x800C4060: b           L_800C4070
    // 0x800C4064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C4070;
    // 0x800C4064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C4068: b           L_800C4070
    // 0x800C406C: nop

        goto L_800C4070;
    // 0x800C406C: nop

L_800C4070:
    // 0x800C4070: jr          $ra
    // 0x800C4074: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C4074: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059D48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80059D4C: lbu         $t6, 0xD94($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0XD94);
    // 0x80059D50: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80059D54: beq         $t6, $at, L_80059D64
    if (ctx->r14 == ctx->r1) {
        // 0x80059D58: nop
    
            goto L_80059D64;
    }
    // 0x80059D58: nop

    // 0x80059D5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059D60: sb          $zero, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = 0;
L_80059D64:
    // 0x80059D64: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x80059D68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059D6C: sh          $t7, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r15;
    // 0x80059D70: jr          $ra
    // 0x80059D74: nop

    return;
    // 0x80059D74: nop

    // 0x80059D78: jr          $ra
    // 0x80059D7C: nop

    return;
    // 0x80059D7C: nop

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
RECOMP_FUNC void func_80072088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007208C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072090: jal         0x80061348
    // 0x80072094: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80072094: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x80072098: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007209C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800720A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800720A4: beq         $v0, $zero, L_800720DC
    if (ctx->r2 == 0) {
        // 0x800720A8: nop
    
            goto L_800720DC;
    }
    // 0x800720A8: nop

    // 0x800720AC: jal         0x80061348
    // 0x800720B0: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800720B0: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x800720B4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800720B8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800720BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800720C0: beq         $v0, $zero, L_800720DC
    if (ctx->r2 == 0) {
        // 0x800720C4: nop
    
            goto L_800720DC;
    }
    // 0x800720C4: nop

    // 0x800720C8: jal         0x80061348
    // 0x800720CC: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800720CC: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x800720D0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800720D4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800720D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800720DC:
    // 0x800720DC: b           L_800720EC
    // 0x800720E0: nop

        goto L_800720EC;
    // 0x800720E0: nop

    // 0x800720E4: b           L_800720EC
    // 0x800720E8: nop

        goto L_800720EC;
    // 0x800720E8: nop

L_800720EC:
    // 0x800720EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800720F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800720F4: jr          $ra
    // 0x800720F8: nop

    return;
    // 0x800720F8: nop

;}
RECOMP_FUNC void func_8002BB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BB9C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BBA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BBA4: slti        $at, $a0, 0x2A
    ctx->r1 = SIGNED(ctx->r4) < 0X2A ? 1 : 0;
    // 0x8002BBA8: bne         $at, $zero, L_8002BBC0
    if (ctx->r1 != 0) {
        // 0x8002BBAC: nop
    
            goto L_8002BBC0;
    }
    // 0x8002BBAC: nop

    // 0x8002BBB0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002BBB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002BBB8: jr          $ra
    // 0x8002BBBC: nop

    return;
    // 0x8002BBBC: nop

L_8002BBC0:
    // 0x8002BBC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BBC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002BBC8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002BBCC: lwc1        $f0, -0x44D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X44D0);
    // 0x8002BBD0: jr          $ra
    // 0x8002BBD4: nop

    return;
    // 0x8002BBD4: nop

    // 0x8002BBD8: jr          $ra
    // 0x8002BBDC: nop

    return;
    // 0x8002BBDC: nop

    // 0x8002BBE0: jr          $ra
    // 0x8002BBE4: nop

    return;
    // 0x8002BBE4: nop

;}
RECOMP_FUNC void func_80023634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023634: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80023638: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002363C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023640: swc1        $f4, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f4.u32l;
    // 0x80023644: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023648: swc1        $f4, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f4.u32l;
    // 0x8002364C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80023650: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80023654: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80023658: nop

    // 0x8002365C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80023660: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80023664: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80023668: lwc1        $f8, 0x14($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X14);
    // 0x8002366C: nop

    // 0x80023670: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80023674: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80023678: nop

    // 0x8002367C: sh          $t8, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r24;
    // 0x80023680: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80023684: lh          $t9, 0x66C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X66C);
    // 0x80023688: nop

    // 0x8002368C: beq         $t9, $zero, L_800236B4
    if (ctx->r25 == 0) {
        // 0x80023690: nop
    
            goto L_800236B4;
    }
    // 0x80023690: nop

    // 0x80023694: lh          $t0, 0x12($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X12);
    // 0x80023698: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002369C: beq         $t0, $at, L_800236B0
    if (ctx->r8 == ctx->r1) {
        // 0x800236A0: nop
    
            goto L_800236B0;
    }
    // 0x800236A0: nop

    // 0x800236A4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800236A8: bne         $t0, $at, L_800236B4
    if (ctx->r8 != ctx->r1) {
        // 0x800236AC: nop
    
            goto L_800236B4;
    }
    // 0x800236AC: nop

L_800236B0:
    // 0x800236B0: sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
L_800236B4:
    // 0x800236B4: lw          $t1, 0x20C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20C);
    // 0x800236B8: nop

    // 0x800236BC: lh          $t2, 0x24($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X24);
    // 0x800236C0: nop

    // 0x800236C4: sh          $t2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r10;
    // 0x800236C8: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800236CC: nop

    // 0x800236D0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800236D4: lwc1        $f10, 0x1B0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x800236D8: nop

    // 0x800236DC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800236E0: lwc1        $f16, 0x1B4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x800236E4: nop

    // 0x800236E8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800236EC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800236F0: lbu         $a3, 0x127D($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X127D);
    // 0x800236F4: nop

    // 0x800236F8: beq         $a3, $zero, L_80023720
    if (ctx->r7 == 0) {
        // 0x800236FC: nop
    
            goto L_80023720;
    }
    // 0x800236FC: nop

    // 0x80023700: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023704: beq         $a3, $at, L_80023738
    if (ctx->r7 == ctx->r1) {
        // 0x80023708: nop
    
            goto L_80023738;
    }
    // 0x80023708: nop

    // 0x8002370C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023710: beq         $a3, $at, L_80023750
    if (ctx->r7 == ctx->r1) {
        // 0x80023714: nop
    
            goto L_80023750;
    }
    // 0x80023714: nop

    // 0x80023718: b           L_80023768
    // 0x8002371C: nop

        goto L_80023768;
    // 0x8002371C: nop

L_80023720:
    // 0x80023720: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023724: lwc1        $f18, -0x1C60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1C60);
    // 0x80023728: nop

    // 0x8002372C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80023730: b           L_80023768
    // 0x80023734: nop

        goto L_80023768;
    // 0x80023734: nop

L_80023738:
    // 0x80023738: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002373C: lwc1        $f4, -0x1C5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C5C);
    // 0x80023740: nop

    // 0x80023744: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80023748: b           L_80023768
    // 0x8002374C: nop

        goto L_80023768;
    // 0x8002374C: nop

L_80023750:
    // 0x80023750: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023754: lwc1        $f6, -0x1C58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C58);
    // 0x80023758: nop

    // 0x8002375C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80023760: b           L_80023768
    // 0x80023764: nop

        goto L_80023768;
    // 0x80023764: nop

L_80023768:
    // 0x80023768: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002376C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023770: nop

    // 0x80023774: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80023778: nop

    // 0x8002377C: bc1f        L_8002378C
    if (!c1cs) {
        // 0x80023780: nop
    
            goto L_8002378C;
    }
    // 0x80023780: nop

    // 0x80023784: b           L_80023798
    // 0x80023788: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
        goto L_80023798;
    // 0x80023788: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
L_8002378C:
    // 0x8002378C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80023790: nop

    // 0x80023794: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_80023798:
    // 0x80023798: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8002379C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800237A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800237A4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800237A8: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x800237AC: nop

    // 0x800237B0: bc1f        L_800238D8
    if (!c1cs) {
        // 0x800237B4: nop
    
            goto L_800238D8;
    }
    // 0x800237B4: nop

    // 0x800237B8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800237BC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800237C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800237C4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800237C8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800237CC: nop

    // 0x800237D0: bc1f        L_800237E0
    if (!c1cs) {
        // 0x800237D4: nop
    
            goto L_800237E0;
    }
    // 0x800237D4: nop

    // 0x800237D8: b           L_800237F4
    // 0x800237DC: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
        goto L_800237F4;
    // 0x800237DC: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
L_800237E0:
    // 0x800237E0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800237E4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800237E8: nop

    // 0x800237EC: mul.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800237F0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_800237F4:
    // 0x800237F4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800237F8: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x800237FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80023800: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023804: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80023808: nop

    // 0x8002380C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80023810: cvt.d.s     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.d = CVT_D_S(ctx->f14.fl);
    // 0x80023814: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023818: lwc1        $f4, 0x1020($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1020);
    // 0x8002381C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023820: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80023824: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80023828: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002382C: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80023830: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80023834: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023838: swc1        $f12, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f12.u32l;
    // 0x8002383C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023840: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80023844: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80023848: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8002384C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80023850: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80023854: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80023858: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8002385C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80023860: bc1f        L_80023888
    if (!c1cs) {
        // 0x80023864: nop
    
            goto L_80023888;
    }
    // 0x80023864: nop

    // 0x80023868: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8002386C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023870: nop

    // 0x80023874: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80023878: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002387C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023880: b           L_800238D8
    // 0x80023884: swc1        $f16, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f16.u32l;
        goto L_800238D8;
    // 0x80023884: swc1        $f16, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f16.u32l;
L_80023888:
    // 0x80023888: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002388C: lwc1        $f18, -0x71C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x80023890: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80023894: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80023898: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002389C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800238A0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800238A4: nop

    // 0x800238A8: bc1f        L_800238D8
    if (!c1cs) {
        // 0x800238AC: nop
    
            goto L_800238D8;
    }
    // 0x800238AC: nop

    // 0x800238B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800238B4: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x800238B8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800238BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800238C0: nop

    // 0x800238C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800238C8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800238CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800238D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800238D4: swc1        $f6, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f6.u32l;
L_800238D8:
    // 0x800238D8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800238DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800238E0: nop

    // 0x800238E4: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800238E8: nop

    // 0x800238EC: bc1f        L_800238FC
    if (!c1cs) {
        // 0x800238F0: nop
    
            goto L_800238FC;
    }
    // 0x800238F0: nop

    // 0x800238F4: b           L_80023908
    // 0x800238F8: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
        goto L_80023908;
    // 0x800238F8: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
L_800238FC:
    // 0x800238FC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023900: nop

    // 0x80023904: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_80023908:
    // 0x80023908: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8002390C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80023910: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80023914: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80023918: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x8002391C: nop

    // 0x80023920: bc1f        L_80023AC0
    if (!c1cs) {
        // 0x80023924: nop
    
            goto L_80023AC0;
    }
    // 0x80023924: nop

    // 0x80023928: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002392C: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80023930: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023934: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80023938: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8002393C: nop

    // 0x80023940: bc1f        L_80023950
    if (!c1cs) {
        // 0x80023944: nop
    
            goto L_80023950;
    }
    // 0x80023944: nop

    // 0x80023948: b           L_80023964
    // 0x8002394C: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
        goto L_80023964;
    // 0x8002394C: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
L_80023950:
    // 0x80023950: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023954: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80023958: nop

    // 0x8002395C: mul.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023960: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80023964:
    // 0x80023964: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023968: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8002396C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80023970: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023974: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80023978: nop

    // 0x8002397C: div.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f4.d);
    // 0x80023980: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80023984: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023988: lwc1        $f18, 0x1020($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1020);
    // 0x8002398C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023990: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80023994: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80023998: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002399C: mul.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800239A0: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800239A4: swc1        $f12, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f12.u32l;
    // 0x800239A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800239AC: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800239B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800239B4: mul.s       $f18, $f12, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800239B8: lwc1        $f5, -0x1C50($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1C50);
    // 0x800239BC: lwc1        $f4, -0x1C4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C4C);
    // 0x800239C0: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800239C4: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x800239C8: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800239CC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800239D0: bc1f        L_800239F8
    if (!c1cs) {
        // 0x800239D4: nop
    
            goto L_800239F8;
    }
    // 0x800239D4: nop

    // 0x800239D8: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x800239DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800239E0: nop

    // 0x800239E4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800239E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800239EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800239F0: b           L_80023A38
    // 0x800239F4: swc1        $f10, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f10.u32l;
        goto L_80023A38;
    // 0x800239F4: swc1        $f10, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f10.u32l;
L_800239F8:
    // 0x800239F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800239FC: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80023A00: lwc1        $f7, -0x1C48($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1C48);
    // 0x80023A04: lwc1        $f6, -0x1C44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C44);
    // 0x80023A08: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80023A0C: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x80023A10: nop

    // 0x80023A14: bc1f        L_80023A38
    if (!c1cs) {
        // 0x80023A18: nop
    
            goto L_80023A38;
    }
    // 0x80023A18: nop

    // 0x80023A1C: lui         $at, 0xC302
    ctx->r1 = S32(0XC302 << 16);
    // 0x80023A20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80023A24: nop

    // 0x80023A28: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80023A2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023A30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023A34: swc1        $f8, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f8.u32l;
L_80023A38:
    // 0x80023A38: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023A3C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80023A40: nop

    // 0x80023A44: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80023A48: nop

    // 0x80023A4C: bc1f        L_80023A7C
    if (!c1cs) {
        // 0x80023A50: nop
    
            goto L_80023A7C;
    }
    // 0x80023A50: nop

    // 0x80023A54: lh          $t4, 0x10($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X10);
    // 0x80023A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023A5C: bne         $t4, $at, L_80023A7C
    if (ctx->r12 != ctx->r1) {
        // 0x80023A60: nop
    
            goto L_80023A7C;
    }
    // 0x80023A60: nop

    // 0x80023A64: sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    // 0x80023A68: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80023A6C: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80023A70: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80023A74: b           L_80023AC0
    // 0x80023A78: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
        goto L_80023AC0;
    // 0x80023A78: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
L_80023A7C:
    // 0x80023A7C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023A80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80023A84: nop

    // 0x80023A88: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80023A8C: nop

    // 0x80023A90: bc1f        L_80023AC0
    if (!c1cs) {
        // 0x80023A94: nop
    
            goto L_80023AC0;
    }
    // 0x80023A94: nop

    // 0x80023A98: lh          $t7, 0x10($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X10);
    // 0x80023A9C: nop

    // 0x80023AA0: bne         $t7, $zero, L_80023AC0
    if (ctx->r15 != 0) {
        // 0x80023AA4: nop
    
            goto L_80023AC0;
    }
    // 0x80023AA4: nop

    // 0x80023AA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80023AAC: sh          $t8, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r24;
    // 0x80023AB0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80023AB4: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80023AB8: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80023ABC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
L_80023AC0:
    // 0x80023AC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023AC4: lwc1        $f4, 0xDA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XDA0);
    // 0x80023AC8: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80023ACC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023AD0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80023AD4: c.eq.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d == ctx->f10.d;
    // 0x80023AD8: nop

    // 0x80023ADC: bc1f        L_80023B08
    if (!c1cs) {
        // 0x80023AE0: nop
    
            goto L_80023B08;
    }
    // 0x80023AE0: nop

    // 0x80023AE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023AE8: lwc1        $f18, 0xE48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XE48);
    // 0x80023AEC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80023AF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80023AF4: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80023AF8: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x80023AFC: nop

    // 0x80023B00: bc1t        L_80023B38
    if (c1cs) {
        // 0x80023B04: nop
    
            goto L_80023B38;
    }
    // 0x80023B04: nop

L_80023B08:
    // 0x80023B08: lh          $t1, 0x12($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X12);
    // 0x80023B0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023B10: beq         $t1, $at, L_80023B30
    if (ctx->r9 == ctx->r1) {
        // 0x80023B14: nop
    
            goto L_80023B30;
    }
    // 0x80023B14: nop

    // 0x80023B18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80023B1C: sh          $t2, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r10;
    // 0x80023B20: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x80023B24: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80023B28: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80023B2C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
L_80023B30:
    // 0x80023B30: b           L_80023B94
    // 0x80023B34: nop

        goto L_80023B94;
    // 0x80023B34: nop

L_80023B38:
    // 0x80023B38: lh          $t5, 0x12($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X12);
    // 0x80023B3C: nop

    // 0x80023B40: beq         $t5, $zero, L_80023B94
    if (ctx->r13 == 0) {
        // 0x80023B44: nop
    
            goto L_80023B94;
    }
    // 0x80023B44: nop

    // 0x80023B48: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80023B4C: nop

    // 0x80023B50: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80023B54: bne         $t7, $zero, L_80023B94
    if (ctx->r15 != 0) {
        // 0x80023B58: nop
    
            goto L_80023B94;
    }
    // 0x80023B58: nop

    // 0x80023B5C: sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    // 0x80023B60: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80023B64: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80023B68: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80023B6C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80023B70: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80023B74: lh          $t0, 0x66C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X66C);
    // 0x80023B78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023B7C: bne         $t0, $at, L_80023B94
    if (ctx->r8 != ctx->r1) {
        // 0x80023B80: nop
    
            goto L_80023B94;
    }
    // 0x80023B80: nop

    // 0x80023B84: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80023B88: nop

    // 0x80023B8C: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80023B90: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
L_80023B94:
    // 0x80023B94: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80023B98: lh          $t3, 0x664($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X664);
    // 0x80023B9C: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80023BA0: bne         $t3, $at, L_80023BC4
    if (ctx->r11 != ctx->r1) {
        // 0x80023BA4: nop
    
            goto L_80023BC4;
    }
    // 0x80023BA4: nop

    // 0x80023BA8: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80023BAC: nop

    // 0x80023BB0: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80023BB4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80023BB8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80023BBC: b           L_80023C10
    // 0x80023BC0: sh          $t6, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r14;
        goto L_80023C10;
    // 0x80023BC0: sh          $t6, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r14;
L_80023BC4:
    // 0x80023BC4: lh          $t7, 0x12($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X12);
    // 0x80023BC8: nop

    // 0x80023BCC: bne         $t7, $zero, L_80023C10
    if (ctx->r15 != 0) {
        // 0x80023BD0: nop
    
            goto L_80023C10;
    }
    // 0x80023BD0: nop

    // 0x80023BD4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80023BD8: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x80023BDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023BE0: bne         $t8, $at, L_80023BF4
    if (ctx->r24 != ctx->r1) {
        // 0x80023BE4: nop
    
            goto L_80023BF4;
    }
    // 0x80023BE4: nop

    // 0x80023BE8: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x80023BEC: b           L_80023C10
    // 0x80023BF0: sh          $t9, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r25;
        goto L_80023C10;
    // 0x80023BF0: sh          $t9, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r25;
L_80023BF4:
    // 0x80023BF4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80023BF8: lh          $t0, 0x66C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X66C);
    // 0x80023BFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023C00: bne         $t0, $at, L_80023C10
    if (ctx->r8 != ctx->r1) {
        // 0x80023C04: nop
    
            goto L_80023C10;
    }
    // 0x80023C04: nop

    // 0x80023C08: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80023C0C: sh          $t1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r9;
L_80023C10:
    // 0x80023C10: lh          $t2, 0x12($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X12);
    // 0x80023C14: nop

    // 0x80023C18: sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
    // 0x80023C1C: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x80023C20: nop

    // 0x80023C24: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80023C28: lh          $t4, 0x10($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X10);
    // 0x80023C2C: lw          $t5, 0x20C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X20C);
    // 0x80023C30: nop

    // 0x80023C34: sh          $t4, 0x24($t5)
    MEM_H(0X24, ctx->r13) = ctx->r12;
    // 0x80023C38: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80023C3C: nop

    // 0x80023C40: swc1        $f4, 0x1B0($a0)
    MEM_W(0X1B0, ctx->r4) = ctx->f4.u32l;
    // 0x80023C44: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80023C48: nop

    // 0x80023C4C: swc1        $f8, 0x1B4($a0)
    MEM_W(0X1B4, ctx->r4) = ctx->f8.u32l;
    // 0x80023C50: b           L_80023C58
    // 0x80023C54: nop

        goto L_80023C58;
    // 0x80023C54: nop

L_80023C58:
    // 0x80023C58: jr          $ra
    // 0x80023C5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80023C5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006346C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006346C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063474: jal         0x80061348
    // 0x80063478: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80063478: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_0:
    // 0x8006347C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063480: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063484: bne         $v0, $zero, L_800634C4
    if (ctx->r2 != 0) {
        // 0x80063488: nop
    
            goto L_800634C4;
    }
    // 0x80063488: nop

    // 0x8006348C: jal         0x80061348
    // 0x80063490: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80063490: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_1:
    // 0x80063494: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063498: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006349C: bne         $v0, $zero, L_800634C4
    if (ctx->r2 != 0) {
        // 0x800634A0: nop
    
            goto L_800634C4;
    }
    // 0x800634A0: nop

    // 0x800634A4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800634A8: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x800634AC: nop

    // 0x800634B0: lh          $v0, 0x20($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X20);
    // 0x800634B4: nop

    // 0x800634B8: slti        $t9, $v0, 0x12C
    ctx->r25 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800634BC: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x800634C0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800634C4:
    // 0x800634C4: b           L_800634D4
    // 0x800634C8: nop

        goto L_800634D4;
    // 0x800634C8: nop

    // 0x800634CC: b           L_800634D4
    // 0x800634D0: nop

        goto L_800634D4;
    // 0x800634D0: nop

L_800634D4:
    // 0x800634D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800634D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800634DC: jr          $ra
    // 0x800634E0: nop

    return;
    // 0x800634E0: nop

;}
RECOMP_FUNC void func_8004D768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D768: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004D76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D770: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8004D774: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8004D778: nop

    // 0x8004D77C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8004D780: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8004D784: nop

    // 0x8004D788: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8004D78C: nop

    // 0x8004D790: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8004D794: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8004D798: nop

    // 0x8004D79C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8004D7A0: jal         0x80098754
    // 0x8004D7A4: nop

    func_80098754(rdram, ctx);
        goto after_0;
    // 0x8004D7A4: nop

    after_0:
    // 0x8004D7A8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8004D7AC: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8004D7B0: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8004D7B4: nop

    // 0x8004D7B8: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8004D7BC: beq         $t2, $zero, L_8004D7EC
    if (ctx->r10 == 0) {
        // 0x8004D7C0: nop
    
            goto L_8004D7EC;
    }
    // 0x8004D7C0: nop

L_8004D7C4:
    // 0x8004D7C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8004D7C8: jal         0x800499B0
    // 0x8004D7CC: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x8004D7CC: nop

    after_1:
    // 0x8004D7D0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8004D7D4: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8004D7D8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8004D7DC: nop

    // 0x8004D7E0: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8004D7E4: bne         $t5, $zero, L_8004D7C4
    if (ctx->r13 != 0) {
        // 0x8004D7E8: nop
    
            goto L_8004D7C4;
    }
    // 0x8004D7E8: nop

L_8004D7EC:
    // 0x8004D7EC: jal         0x80058824
    // 0x8004D7F0: nop

    func_80058824(rdram, ctx);
        goto after_2;
    // 0x8004D7F0: nop

    after_2:
    // 0x8004D7F4: jal         0x80058B4C
    // 0x8004D7F8: nop

    func_80058B4C(rdram, ctx);
        goto after_3;
    // 0x8004D7F8: nop

    after_3:
    // 0x8004D7FC: jal         0x80058E78
    // 0x8004D800: nop

    func_80058E78(rdram, ctx);
        goto after_4;
    // 0x8004D800: nop

    after_4:
    // 0x8004D804: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8004D808:
    // 0x8004D808: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8004D80C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004D810: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004D814: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8004D818: lw          $t8, 0xE80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE80);
    // 0x8004D81C: nop

    // 0x8004D820: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8004D824: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8004D828: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004D82C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004D830: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004D834: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004D838: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004D83C: bne         $t2, $zero, L_8004D84C
    if (ctx->r10 != 0) {
        // 0x8004D840: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8004D84C;
    }
    // 0x8004D840: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8004D844: beq         $t3, $zero, L_8004DBBC
    if (ctx->r11 == 0) {
        // 0x8004D848: nop
    
            goto L_8004DBBC;
    }
    // 0x8004D848: nop

L_8004D84C:
    // 0x8004D84C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8004D850: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004D854: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004D858: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004D85C: bne         $t8, $zero, L_8004DBB0
    if (ctx->r24 != 0) {
        // 0x8004D860: andi        $t9, $t7, 0x4
        ctx->r25 = ctx->r15 & 0X4;
            goto L_8004DBB0;
    }
    // 0x8004D860: andi        $t9, $t7, 0x4
    ctx->r25 = ctx->r15 & 0X4;
    // 0x8004D864: bne         $t9, $zero, L_8004DBB0
    if (ctx->r25 != 0) {
        // 0x8004D868: nop
    
            goto L_8004DBB0;
    }
    // 0x8004D868: nop

    // 0x8004D86C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8004D870: nop

    // 0x8004D874: addiu       $a0, $t5, 0x4C
    ctx->r4 = ADD32(ctx->r13, 0X4C);
    // 0x8004D878: jal         0x800B2748
    // 0x8004D87C: addiu       $a1, $t5, 0x50
    ctx->r5 = ADD32(ctx->r13, 0X50);
    func_800B2748(rdram, ctx);
        goto after_5;
    // 0x8004D87C: addiu       $a1, $t5, 0x50
    ctx->r5 = ADD32(ctx->r13, 0X50);
    after_5:
    // 0x8004D880: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8004D884: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8004D888: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D88C: beq         $t0, $at, L_8004D920
    if (ctx->r8 == ctx->r1) {
        // 0x8004D890: nop
    
            goto L_8004D920;
    }
    // 0x8004D890: nop

    // 0x8004D894: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8004D898: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8004D89C: nop

    // 0x8004D8A0: sh          $t1, 0x48($t2)
    MEM_H(0X48, ctx->r10) = ctx->r9;
    // 0x8004D8A4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004D8A8: nop

    // 0x8004D8AC: lw          $t4, 0x4C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4C);
    // 0x8004D8B0: nop

    // 0x8004D8B4: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8004D8B8: nop

    // 0x8004D8BC: swc1        $f4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f4.u32l;
    // 0x8004D8C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8004D8C4: nop

    // 0x8004D8C8: lw          $t7, 0x4C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4C);
    // 0x8004D8CC: nop

    // 0x8004D8D0: lwc1        $f6, 0xD0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x8004D8D4: nop

    // 0x8004D8D8: swc1        $f6, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f6.u32l;
    // 0x8004D8DC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8004D8E0: nop

    // 0x8004D8E4: addiu       $a0, $t8, 0x50
    ctx->r4 = ADD32(ctx->r24, 0X50);
    // 0x8004D8E8: jal         0x8005A5F4
    // 0x8004D8EC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8005A5F4(rdram, ctx);
        goto after_6;
    // 0x8004D8EC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_6:
    // 0x8004D8F0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004D8F4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004D8F8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8004D8FC: nop

    // 0x8004D900: bne         $t9, $t5, L_8004D918
    if (ctx->r25 != ctx->r13) {
        // 0x8004D904: nop
    
            goto L_8004D918;
    }
    // 0x8004D904: nop

    // 0x8004D908: jal         0x80056848
    // 0x8004D90C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80056848(rdram, ctx);
        goto after_7;
    // 0x8004D90C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8004D910: jal         0x8005A870
    // 0x8004D914: nop

    func_8005A870(rdram, ctx);
        goto after_8;
    // 0x8004D914: nop

    after_8:
L_8004D918:
    // 0x8004D918: b           L_8004DB90
    // 0x8004D91C: nop

        goto L_8004DB90;
    // 0x8004D91C: nop

L_8004D920:
    // 0x8004D920: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8004D924: nop

    // 0x8004D928: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004D92C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004D930: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x8004D934: ori         $t5, $t3, 0x2
    ctx->r13 = ctx->r11 | 0X2;
    // 0x8004D938: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8004D93C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8004D940: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004D944: nop

    // 0x8004D948: lh          $t7, 0x4A($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X4A);
    // 0x8004D94C: nop

    // 0x8004D950: andi        $t6, $t7, 0x1FFF
    ctx->r14 = ctx->r15 & 0X1FFF;
    // 0x8004D954: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8004D958: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8004D95C: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8004D960: lh          $t9, 0x7C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X7C);
    // 0x8004D964: nop

    // 0x8004D968: bne         $t9, $at, L_8004D9A8
    if (ctx->r25 != ctx->r1) {
        // 0x8004D96C: nop
    
            goto L_8004D9A8;
    }
    // 0x8004D96C: nop

    // 0x8004D970: lh          $t2, 0x4A($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X4A);
    // 0x8004D974: addiu       $at, $zero, 0x19A
    ctx->r1 = ADD32(0, 0X19A);
    // 0x8004D978: bne         $t2, $at, L_8004D9A8
    if (ctx->r10 != ctx->r1) {
        // 0x8004D97C: nop
    
            goto L_8004D9A8;
    }
    // 0x8004D97C: nop

    // 0x8004D980: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004D984: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D988: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8004D98C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8004D990: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x8004D994: lui         $at, 0xFF7F
    ctx->r1 = S32(0XFF7F << 16);
    // 0x8004D998: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004D99C: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x8004D9A0: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x8004D9A4: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
L_8004D9A8:
    // 0x8004D9A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004D9AC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004D9B0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8004D9B4: nop

    // 0x8004D9B8: bne         $t7, $t6, L_8004DB90
    if (ctx->r15 != ctx->r14) {
        // 0x8004D9BC: nop
    
            goto L_8004DB90;
    }
    // 0x8004D9BC: nop

    // 0x8004D9C0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004D9C4: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8004D9C8: beq         $t9, $at, L_8004D9F4
    if (ctx->r25 == ctx->r1) {
        // 0x8004D9CC: nop
    
            goto L_8004D9F4;
    }
    // 0x8004D9CC: nop

    // 0x8004D9D0: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x8004D9D4: beq         $t9, $at, L_8004D9F4
    if (ctx->r25 == ctx->r1) {
        // 0x8004D9D8: nop
    
            goto L_8004D9F4;
    }
    // 0x8004D9D8: nop

    // 0x8004D9DC: addiu       $at, $zero, 0x6B
    ctx->r1 = ADD32(0, 0X6B);
    // 0x8004D9E0: beq         $t9, $at, L_8004D9F4
    if (ctx->r25 == ctx->r1) {
        // 0x8004D9E4: nop
    
            goto L_8004D9F4;
    }
    // 0x8004D9E4: nop

    // 0x8004D9E8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x8004D9EC: bne         $t9, $at, L_8004DA00
    if (ctx->r25 != ctx->r1) {
        // 0x8004D9F0: nop
    
            goto L_8004DA00;
    }
    // 0x8004D9F0: nop

L_8004D9F4:
    // 0x8004D9F4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8004D9F8: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8004D9FC: sw          $t8, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r24;
L_8004DA00:
    // 0x8004DA00: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8004DA04: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x8004DA08: beq         $t4, $at, L_8004DA34
    if (ctx->r12 == ctx->r1) {
        // 0x8004DA0C: nop
    
            goto L_8004DA34;
    }
    // 0x8004DA0C: nop

    // 0x8004DA10: addiu       $at, $zero, 0x56
    ctx->r1 = ADD32(0, 0X56);
    // 0x8004DA14: beq         $t4, $at, L_8004DA34
    if (ctx->r12 == ctx->r1) {
        // 0x8004DA18: nop
    
            goto L_8004DA34;
    }
    // 0x8004DA18: nop

    // 0x8004DA1C: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8004DA20: beq         $t4, $at, L_8004DA34
    if (ctx->r12 == ctx->r1) {
        // 0x8004DA24: nop
    
            goto L_8004DA34;
    }
    // 0x8004DA24: nop

    // 0x8004DA28: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8004DA2C: bne         $t4, $at, L_8004DA54
    if (ctx->r12 != ctx->r1) {
        // 0x8004DA30: nop
    
            goto L_8004DA54;
    }
    // 0x8004DA30: nop

L_8004DA34:
    // 0x8004DA34: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8004DA38: nop

    // 0x8004DA3C: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x8004DA40: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x8004DA44: or          $t6, $t0, $zero
    ctx->r14 = ctx->r8 | 0;
    // 0x8004DA48: xori        $t7, $t1, 0x8
    ctx->r15 = ctx->r9 ^ 0X8;
    // 0x8004DA4C: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8004DA50: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_8004DA54:
    // 0x8004DA54: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004DA58: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004DA5C: lh          $a3, 0x4A($t3)
    ctx->r7 = MEM_H(ctx->r11, 0X4A);
    // 0x8004DA60: addiu       $a0, $sp, 0x1E
    ctx->r4 = ADD32(ctx->r29, 0X1E);
    // 0x8004DA64: andi        $t9, $a3, 0x1FFF
    ctx->r25 = ctx->r7 & 0X1FFF;
    // 0x8004DA68: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8004DA6C: or          $t8, $a3, $at
    ctx->r24 = ctx->r7 | ctx->r1;
    // 0x8004DA70: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8004DA74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004DA78: jal         0x800B3230
    // 0x8004DA7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_9;
    // 0x8004DA7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8004DA80: lhu         $t2, 0x1E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1E);
    // 0x8004DA84: nop

    // 0x8004DA88: andi        $t4, $t2, 0x60
    ctx->r12 = ctx->r10 & 0X60;
    // 0x8004DA8C: sra         $t0, $t4, 5
    ctx->r8 = S32(SIGNED(ctx->r12) >> 5);
    // 0x8004DA90: bne         $t0, $zero, L_8004DAE4
    if (ctx->r8 != 0) {
        // 0x8004DA94: nop
    
            goto L_8004DAE4;
    }
    // 0x8004DA94: nop

    // 0x8004DA98: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004DA9C: nop

    // 0x8004DAA0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8004DAA4: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8004DAA8: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8004DAAC: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x8004DAB0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8004DAB4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8004DAB8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8004DABC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DAC0: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8004DAC4: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x8004DAC8: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004DACC: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8004DAD0: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8004DAD4: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004DAD8: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8004DADC: b           L_8004DB90
    // 0x8004DAE0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
        goto L_8004DB90;
    // 0x8004DAE0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_8004DAE4:
    // 0x8004DAE4: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x8004DAE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004DAEC: andi        $t7, $t6, 0x60
    ctx->r15 = ctx->r14 & 0X60;
    // 0x8004DAF0: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x8004DAF4: bne         $t8, $at, L_8004DB48
    if (ctx->r24 != ctx->r1) {
        // 0x8004DAF8: nop
    
            goto L_8004DB48;
    }
    // 0x8004DAF8: nop

    // 0x8004DAFC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DB04: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8004DB08: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8004DB0C: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004DB10: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8004DB14: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004DB18: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x8004DB1C: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x8004DB20: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB24: nop

    // 0x8004DB28: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8004DB2C: or          $t6, $t1, $zero
    ctx->r14 = ctx->r9 | 0;
    // 0x8004DB30: lw          $t1, 0x4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4);
    // 0x8004DB34: or          $t8, $t0, $zero
    ctx->r24 = ctx->r8 | 0;
    // 0x8004DB38: ori         $t9, $t1, 0x40
    ctx->r25 = ctx->r9 | 0X40;
    // 0x8004DB3C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8004DB40: b           L_8004DB90
    // 0x8004DB44: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_8004DB90;
    // 0x8004DB44: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_8004DB48:
    // 0x8004DB48: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DB50: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8004DB54: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8004DB58: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004DB5C: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8004DB60: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004DB64: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8004DB68: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8004DB6C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DB74: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8004DB78: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8004DB7C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004DB80: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8004DB84: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8004DB88: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8004DB8C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_8004DB90:
    // 0x8004DB90: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB94: nop

    // 0x8004DB98: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004DB9C: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8004DBA0: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x8004DBA4: ori         $t5, $t3, 0x4
    ctx->r13 = ctx->r11 | 0X4;
    // 0x8004DBA8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8004DBAC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_8004DBB0:
    // 0x8004DBB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004DBB4: jal         0x8004DCE8
    // 0x8004DBB8: nop

    func_8004DCE8(rdram, ctx);
        goto after_10;
    // 0x8004DBB8: nop

    after_10:
L_8004DBBC:
    // 0x8004DBBC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8004DBC0: nop

    // 0x8004DBC4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8004DBC8: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x8004DBCC: bne         $at, $zero, L_8004D808
    if (ctx->r1 != 0) {
        // 0x8004DBD0: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8004D808;
    }
    // 0x8004DBD0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8004DBD4: jal         0x80016138
    // 0x8004DBD8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_11;
    // 0x8004DBD8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_11:
    // 0x8004DBDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004DBE0: beq         $v0, $at, L_8004DCAC
    if (ctx->r2 == ctx->r1) {
        // 0x8004DBE4: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DBE4: nop

    // 0x8004DBE8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004DBEC: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004DBF0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004DBF4: nop

    // 0x8004DBF8: andi        $t0, $t7, 0x2
    ctx->r8 = ctx->r15 & 0X2;
    // 0x8004DBFC: bne         $t0, $zero, L_8004DCAC
    if (ctx->r8 != 0) {
        // 0x8004DC00: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC00: nop

    // 0x8004DC04: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004DC08: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x8004DC0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004DC10: bne         $t2, $at, L_8004DCAC
    if (ctx->r10 != ctx->r1) {
        // 0x8004DC14: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC14: nop

    // 0x8004DC18: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004DC1C: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8004DC20: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8004DC24: bne         $t3, $at, L_8004DCAC
    if (ctx->r11 != ctx->r1) {
        // 0x8004DC28: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC28: nop

    // 0x8004DC2C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004DC30: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004DC34: nop

    // 0x8004DC38: beq         $t4, $zero, L_8004DCAC
    if (ctx->r12 == 0) {
        // 0x8004DC3C: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC3C: nop

    // 0x8004DC40: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004DC44: lw          $t5, 0xE70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE70);
    // 0x8004DC48: nop

    // 0x8004DC4C: beq         $t5, $zero, L_8004DCAC
    if (ctx->r13 == 0) {
        // 0x8004DC50: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC50: nop

    // 0x8004DC54: lw          $t1, 0xA4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XA4);
    // 0x8004DC58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004DC5C: beq         $t1, $at, L_8004DCAC
    if (ctx->r9 == ctx->r1) {
        // 0x8004DC60: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC60: nop

    // 0x8004DC64: lw          $t8, 0xA4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XA4);
    // 0x8004DC68: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004DC6C: beq         $t8, $at, L_8004DCAC
    if (ctx->r24 == ctx->r1) {
        // 0x8004DC70: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC70: nop

    // 0x8004DC74: lh          $t9, 0xAC($t4)
    ctx->r25 = MEM_H(ctx->r12, 0XAC);
    // 0x8004DC78: nop

    // 0x8004DC7C: andi        $t6, $t9, 0x20
    ctx->r14 = ctx->r25 & 0X20;
    // 0x8004DC80: beq         $t6, $zero, L_8004DCAC
    if (ctx->r14 == 0) {
        // 0x8004DC84: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC84: nop

    // 0x8004DC88: lh          $t7, 0xAC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XAC);
    // 0x8004DC8C: nop

    // 0x8004DC90: andi        $t0, $t7, 0x20
    ctx->r8 = ctx->r15 & 0X20;
    // 0x8004DC94: beq         $t0, $zero, L_8004DCAC
    if (ctx->r8 == 0) {
        // 0x8004DC98: nop
    
            goto L_8004DCAC;
    }
    // 0x8004DC98: nop

    // 0x8004DC9C: jal         0x8005C304
    // 0x8004DCA0: nop

    func_8005C304(rdram, ctx);
        goto after_12;
    // 0x8004DCA0: nop

    after_12:
    // 0x8004DCA4: jal         0x8005CDBC
    // 0x8004DCA8: nop

    func_8005CDBC(rdram, ctx);
        goto after_13;
    // 0x8004DCA8: nop

    after_13:
L_8004DCAC:
    // 0x8004DCAC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004DCB0: lw          $t2, 0x258C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X258C);
    // 0x8004DCB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DCB8: sw          $t2, 0xE58($at)
    MEM_W(0XE58, ctx->r1) = ctx->r10;
    // 0x8004DCBC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8004DCC0: jal         0x800499B0
    // 0x8004DCC4: nop

    func_800499B0(rdram, ctx);
        goto after_14;
    // 0x8004DCC4: nop

    after_14:
    // 0x8004DCC8: b           L_8004D7EC
    // 0x8004DCCC: nop

        goto L_8004D7EC;
    // 0x8004DCCC: nop

    // 0x8004DCD0: b           L_8004DCD8
    // 0x8004DCD4: nop

        goto L_8004DCD8;
    // 0x8004DCD4: nop

L_8004DCD8:
    // 0x8004DCD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004DCDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8004DCE0: jr          $ra
    // 0x8004DCE4: nop

    return;
    // 0x8004DCE4: nop

;}
RECOMP_FUNC void alCSeqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA73C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA740: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800CA744: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800CA748: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CA74C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CA750: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CA754: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CA758: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CA75C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CA760: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800CA764: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800CA768: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CA76C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800CA770: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800CA774: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800CA778: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CA77C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CA780: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x800CA784: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800CA788: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_800CA78C:
    // 0x800CA78C: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x800CA790: sw          $zero, 0x58($t4)
    MEM_W(0X58, ctx->r12) = 0;
    // 0x800CA794: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x800CA798: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800CA79C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CA7A0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800CA7A4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800CA7A8: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800CA7AC: beq         $v0, $zero, L_800CA7D8
    if (ctx->r2 == 0) {
        // 0x800CA7B0: addu        $t6, $s4, $v0
        ctx->r14 = ADD32(ctx->r20, ctx->r2);
            goto L_800CA7D8;
    }
    // 0x800CA7B0: addu        $t6, $s4, $v0
    ctx->r14 = ADD32(ctx->r20, ctx->r2);
    // 0x800CA7B4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800CA7B8: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800CA7BC: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800CA7C0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800CA7C4: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800CA7C8: jal         0x800CA3E4
    // 0x800CA7CC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    static_5_800CA3E4(rdram, ctx);
        goto after_0;
    // 0x800CA7CC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    after_0:
    // 0x800CA7D0: b           L_800CA7DC
    // 0x800CA7D4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
        goto L_800CA7DC;
    // 0x800CA7D4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
L_800CA7D8:
    // 0x800CA7D8: sw          $zero, 0x18($t4)
    MEM_W(0X18, ctx->r12) = 0;
L_800CA7DC:
    // 0x800CA7DC: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800CA7E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CA7E4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800CA7E8: bne         $t5, $s3, L_800CA78C
    if (ctx->r13 != ctx->r19) {
        // 0x800CA7EC: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_800CA78C;
    }
    // 0x800CA7EC: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800CA7F0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800CA7F4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CA7F8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800CA7FC: lw          $t7, 0x40($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X40);
    // 0x800CA800: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CA804: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CA808: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800CA80C: bgez        $t7, L_800CA820
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CA810: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800CA820;
    }
    // 0x800CA810: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CA814: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800CA818: nop

    // 0x800CA81C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800CA820:
    // 0x800CA820: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800CA824: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800CA828: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800CA82C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800CA830: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA834: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800CA838: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800CA83C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CA840: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CA848: jr          $ra
    // 0x800CA84C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CA84C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alSeqpNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3784: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D3788: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D378C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D3790: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D3794: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x800D3798: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800D379C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800D37A0: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800D37A4: lw          $t6, -0x33E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33E0);
    // 0x800D37A8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800D37AC: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800D37B0: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800D37B4: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x800D37B8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800D37BC: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800D37C0: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800D37C4: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x800D37C8: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800D37CC: lbu         $t0, 0x9($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X9);
    // 0x800D37D0: addiu       $t1, $zero, 0x3E80
    ctx->r9 = ADD32(0, 0X3E80);
    // 0x800D37D4: sw          $t1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r9;
    // 0x800D37D8: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800D37DC: sb          $t0, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r8;
    // 0x800D37E0: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x800D37E4: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x800D37E8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800D37EC: sw          $t2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r10;
    // 0x800D37F0: lw          $t3, 0x14($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X14);
    // 0x800D37F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D37F8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800D37FC: sw          $t3, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r11;
    // 0x800D3800: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    // 0x800D3804: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x800D3808: sw          $zero, 0x80($a0)
    MEM_W(0X80, ctx->r4) = 0;
    // 0x800D380C: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x800D3810: sh          $t5, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r13;
    // 0x800D3814: sw          $t4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r12;
    // 0x800D3818: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800D381C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3820: sb          $t6, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r14;
    // 0x800D3824: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x800D3828: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800D382C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D3830: jal         0x800C7950
    // 0x800D3834: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800D3834: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D3838: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x800D383C: jal         0x800D3714
    // 0x800D3840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __initChanState(rdram, ctx);
        goto after_1;
    // 0x800D3840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D3844: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800D3848: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x800D384C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800D3850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D3854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3858: jal         0x800C7950
    // 0x800D385C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800D385C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800D3860: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800D3864: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800D3868: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D386C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3870: blez        $t9, L_800D38A0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D3874: addiu       $t2, $zero, 0x1C
        ctx->r10 = ADD32(0, 0X1C);
            goto L_800D38A0;
    }
    // 0x800D3874: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800D3878: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D387C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
L_800D3880:
    // 0x800D3880: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D3884: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800D3888: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x800D388C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800D3890: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800D3894: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D3898: bnel        $at, $zero, L_800D3880
    if (ctx->r1 != 0) {
        // 0x800D389C: lw          $t0, 0x6C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X6C);
            goto L_800D3880;
    }
    goto skip_0;
    // 0x800D389C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    skip_0:
L_800D38A0:
    // 0x800D38A0: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800D38A4: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800D38A8: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x800D38AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800D38B0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800D38B4: jal         0x800C7950
    // 0x800D38B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800D38B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800D38BC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800D38C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D38C4: jal         0x800D3BDC
    // 0x800D38C8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x800D38C8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x800D38CC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800D38D0: addiu       $t3, $t3, 0x2FEC
    ctx->r11 = ADD32(ctx->r11, 0X2FEC);
    // 0x800D38D4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800D38D8: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x800D38DC: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800D38E0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D38E4: lw          $a0, -0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33E0);
    // 0x800D38E8: jal         0x800D3C50
    // 0x800D38EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x800D38EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800D38F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D38F4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D38F8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D38FC: jr          $ra
    // 0x800D3900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800D3900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80074E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074E20: jal         0x80061348
    // 0x80074E24: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074E24: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80074E28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074E2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074E30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074E34: beq         $v0, $zero, L_80074E88
    if (ctx->r2 == 0) {
        // 0x80074E38: nop
    
            goto L_80074E88;
    }
    // 0x80074E38: nop

    // 0x80074E3C: jal         0x80061348
    // 0x80074E40: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074E40: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80074E44: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074E48: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074E4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074E50: beq         $v0, $zero, L_80074E88
    if (ctx->r2 == 0) {
        // 0x80074E54: nop
    
            goto L_80074E88;
    }
    // 0x80074E54: nop

    // 0x80074E58: jal         0x80061348
    // 0x80074E5C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074E5C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x80074E60: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074E64: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074E68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074E6C: beq         $v0, $zero, L_80074E88
    if (ctx->r2 == 0) {
        // 0x80074E70: nop
    
            goto L_80074E88;
    }
    // 0x80074E70: nop

    // 0x80074E74: jal         0x80061348
    // 0x80074E78: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074E78: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x80074E7C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074E80: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074E84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074E88:
    // 0x80074E88: b           L_80074E98
    // 0x80074E8C: nop

        goto L_80074E98;
    // 0x80074E8C: nop

    // 0x80074E90: b           L_80074E98
    // 0x80074E94: nop

        goto L_80074E98;
    // 0x80074E94: nop

L_80074E98:
    // 0x80074E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074EA0: jr          $ra
    // 0x80074EA4: nop

    return;
    // 0x80074EA4: nop

;}
RECOMP_FUNC void func_8008B108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B108: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B10C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B110: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B114: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008B118: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8008B11C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008B120: nop

    // 0x8008B124: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8008B128: lhu         $t8, 0xA($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0XA);
    // 0x8008B12C: nop

    // 0x8008B130: blez        $t8, L_8008B174
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008B134: nop
    
            goto L_8008B174;
    }
    // 0x8008B134: nop

L_8008B138:
    // 0x8008B138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008B13C: jal         0x8008B18C
    // 0x8008B140: nop

    func_8008B18C(rdram, ctx);
        goto after_0;
    // 0x8008B140: nop

    after_0:
    // 0x8008B144: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B148: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008B14C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8008B150: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008B154: addiu       $t2, $t1, 0x160
    ctx->r10 = ADD32(ctx->r9, 0X160);
    // 0x8008B158: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8008B15C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8008B160: lhu         $t4, 0xA($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XA);
    // 0x8008B164: nop

    // 0x8008B168: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008B16C: bne         $at, $zero, L_8008B138
    if (ctx->r1 != 0) {
        // 0x8008B170: nop
    
            goto L_8008B138;
    }
    // 0x8008B170: nop

L_8008B174:
    // 0x8008B174: b           L_8008B17C
    // 0x8008B178: nop

        goto L_8008B17C;
    // 0x8008B178: nop

L_8008B17C:
    // 0x8008B17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B184: jr          $ra
    // 0x8008B188: nop

    return;
    // 0x8008B188: nop

;}
RECOMP_FUNC void func_8006681C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006681C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066824: jal         0x80061348
    // 0x80066828: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066828: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    after_0:
    // 0x8006682C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066830: b           L_80066840
    // 0x80066834: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066840;
    // 0x80066834: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066838: b           L_80066840
    // 0x8006683C: nop

        goto L_80066840;
    // 0x8006683C: nop

L_80066840:
    // 0x80066840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066848: jr          $ra
    // 0x8006684C: nop

    return;
    // 0x8006684C: nop

;}
RECOMP_FUNC void func_8000F53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F53C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F544: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000F548: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000F54C: nop

    // 0x8000F550: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000F554: nop

    // 0x8000F558: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8000F55C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F560: nop

    // 0x8000F564: lhu         $a2, 0x6($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X6);
    // 0x8000F568: addiu       $a0, $t8, 0xC
    ctx->r4 = ADD32(ctx->r24, 0XC);
    // 0x8000F56C: jal         0x800B1C10
    // 0x8000F570: addiu       $a1, $t8, 0x10
    ctx->r5 = ADD32(ctx->r24, 0X10);
    func_800B1C10(rdram, ctx);
        goto after_0;
    // 0x8000F570: addiu       $a1, $t8, 0x10
    ctx->r5 = ADD32(ctx->r24, 0X10);
    after_0:
    // 0x8000F574: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000F578: jal         0x8000D74C
    // 0x8000F57C: nop

    func_8000D74C(rdram, ctx);
        goto after_1;
    // 0x8000F57C: nop

    after_1:
    // 0x8000F580: b           L_8000F588
    // 0x8000F584: nop

        goto L_8000F588;
    // 0x8000F584: nop

L_8000F588:
    // 0x8000F588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F58C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F590: jr          $ra
    // 0x8000F594: nop

    return;
    // 0x8000F594: nop

;}
RECOMP_FUNC void func_80051700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005170C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051710: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80051714: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051718: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005171C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80051720: bne         $t0, $zero, L_80051730
    if (ctx->r8 != 0) {
        // 0x80051724: andi        $t1, $t9, 0x10
        ctx->r9 = ctx->r25 & 0X10;
            goto L_80051730;
    }
    // 0x80051724: andi        $t1, $t9, 0x10
    ctx->r9 = ctx->r25 & 0X10;
    // 0x80051728: beq         $t1, $zero, L_80051760
    if (ctx->r9 == 0) {
        // 0x8005172C: nop
    
            goto L_80051760;
    }
    // 0x8005172C: nop

L_80051730:
    // 0x80051730: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051734: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051738: nop

    // 0x8005173C: lh          $v0, 0x4A($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X4A);
    // 0x80051740: nop

    // 0x80051744: andi        $t2, $v0, 0x1FFF
    ctx->r10 = ctx->r2 & 0X1FFF;
    // 0x80051748: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8005174C: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80051750: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80051754: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80051758: b           L_800517F4
    // 0x8005175C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800517F4;
    // 0x8005175C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80051760:
    // 0x80051760: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80051764: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80051768: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005176C: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80051770: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80051774: bne         $t8, $zero, L_80051784
    if (ctx->r24 != 0) {
        // 0x80051778: andi        $t9, $t7, 0x40
        ctx->r25 = ctx->r15 & 0X40;
            goto L_80051784;
    }
    // 0x80051778: andi        $t9, $t7, 0x40
    ctx->r25 = ctx->r15 & 0X40;
    // 0x8005177C: beq         $t9, $zero, L_80051798
    if (ctx->r25 == 0) {
        // 0x80051780: nop
    
            goto L_80051798;
    }
    // 0x80051780: nop

L_80051784:
    // 0x80051784: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80051788: jal         0x80056E88
    // 0x8005178C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_0;
    // 0x8005178C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80051790: b           L_800517F4
    // 0x80051794: nop

        goto L_800517F4;
    // 0x80051794: nop

L_80051798:
    // 0x80051798: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005179C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800517A0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800517A4: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800517A8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800517AC: bne         $t4, $zero, L_800517BC
    if (ctx->r12 != 0) {
        // 0x800517B0: andi        $t5, $t3, 0x20
        ctx->r13 = ctx->r11 & 0X20;
            goto L_800517BC;
    }
    // 0x800517B0: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x800517B4: beq         $t5, $zero, L_800517D8
    if (ctx->r13 == 0) {
        // 0x800517B8: nop
    
            goto L_800517D8;
    }
    // 0x800517B8: nop

L_800517BC:
    // 0x800517BC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x800517C0: jal         0x80056E88
    // 0x800517C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_1;
    // 0x800517C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800517C8: b           L_800517F4
    // 0x800517CC: nop

        goto L_800517F4;
    // 0x800517CC: nop

    // 0x800517D0: b           L_800517EC
    // 0x800517D4: nop

        goto L_800517EC;
    // 0x800517D4: nop

L_800517D8:
    // 0x800517D8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x800517DC: jal         0x80056E88
    // 0x800517E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_2;
    // 0x800517E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800517E4: b           L_800517F4
    // 0x800517E8: nop

        goto L_800517F4;
    // 0x800517E8: nop

L_800517EC:
    // 0x800517EC: b           L_800517F4
    // 0x800517F0: nop

        goto L_800517F4;
    // 0x800517F0: nop

L_800517F4:
    // 0x800517F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800517F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800517FC: jr          $ra
    // 0x80051800: nop

    return;
    // 0x80051800: nop

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
RECOMP_FUNC void func_80076D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076D88: jal         0x80061348
    // 0x80076D8C: addiu       $a0, $zero, 0x553
    ctx->r4 = ADD32(0, 0X553);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076D8C: addiu       $a0, $zero, 0x553
    ctx->r4 = ADD32(0, 0X553);
    after_0:
    // 0x80076D90: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076D94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076D98: b           L_80076DA8
    // 0x80076D9C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80076DA8;
    // 0x80076D9C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076DA0: b           L_80076DA8
    // 0x80076DA4: nop

        goto L_80076DA8;
    // 0x80076DA4: nop

L_80076DA8:
    // 0x80076DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076DB0: jr          $ra
    // 0x80076DB4: nop

    return;
    // 0x80076DB4: nop

;}
RECOMP_FUNC void func_80071A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071A6C: jal         0x80061348
    // 0x80071A70: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071A70: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    after_0:
    // 0x80071A74: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071A78: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071A7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071A80: beq         $v0, $zero, L_80071A9C
    if (ctx->r2 == 0) {
        // 0x80071A84: nop
    
            goto L_80071A9C;
    }
    // 0x80071A84: nop

    // 0x80071A88: jal         0x80061348
    // 0x80071A8C: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071A8C: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    after_1:
    // 0x80071A90: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071A94: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071A98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071A9C:
    // 0x80071A9C: b           L_80071AAC
    // 0x80071AA0: nop

        goto L_80071AAC;
    // 0x80071AA0: nop

    // 0x80071AA4: b           L_80071AAC
    // 0x80071AA8: nop

        goto L_80071AAC;
    // 0x80071AA8: nop

L_80071AAC:
    // 0x80071AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071AB4: jr          $ra
    // 0x80071AB8: nop

    return;
    // 0x80071AB8: nop

;}
RECOMP_FUNC void func_80067704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067704: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067708: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006770C: nop

    // 0x80067710: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067714: nop

    // 0x80067718: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006771C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067720: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067724: beq         $v0, $zero, L_80067740
    if (ctx->r2 == 0) {
        // 0x80067728: nop
    
            goto L_80067740;
    }
    // 0x80067728: nop

    // 0x8006772C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067730: nop

    // 0x80067734: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067738: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006773C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067740:
    // 0x80067740: jr          $ra
    // 0x80067744: nop

    return;
    // 0x80067744: nop

    // 0x80067748: jr          $ra
    // 0x8006774C: nop

    return;
    // 0x8006774C: nop

    // 0x80067750: jr          $ra
    // 0x80067754: nop

    return;
    // 0x80067754: nop

;}
RECOMP_FUNC void Main_GfxInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE0FC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BE100: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800BE104: lw          $t6, 0x1B14($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B14);
    // 0x800BE108: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BE10C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BE110: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800BE114: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE118: mfhi        $t8
    ctx->r24 = hi;
    // 0x800BE11C: sw          $t8, 0x1B14($at)
    MEM_W(0X1B14, ctx->r1) = ctx->r24;
    // 0x800BE120: nop

    // 0x800BE124: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BE128: lhu         $t9, 0x24FC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X24FC);
    // 0x800BE12C: nop

    // 0x800BE130: beq         $t9, $zero, L_800BE140
    if (ctx->r25 == 0) {
        // 0x800BE134: nop
    
            goto L_800BE140;
    }
    // 0x800BE134: nop

    // 0x800BE138: b           L_800BE144
    // 0x800BE13C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800BE144;
    // 0x800BE13C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BE140:
    // 0x800BE140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800BE144:
    // 0x800BE144: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x800BE148: addiu       $t1, $t1, -0x64F8
    ctx->r9 = ADD32(ctx->r9, -0X64F8);
    // 0x800BE14C: sll         $t0, $a0, 15
    ctx->r8 = S32(ctx->r4 << 15);
    // 0x800BE150: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800BE154: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800BE158: sw          $t2, -0x6508($at)
    MEM_W(-0X6508, ctx->r1) = ctx->r10;
    // 0x800BE15C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x800BE160: lw          $t3, -0x6508($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6508);
    // 0x800BE164: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE168: sw          $t3, 0x1B4C($at)
    MEM_W(0X1B4C, ctx->r1) = ctx->r11;
    // 0x800BE16C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800BE170: lw          $t4, 0x1B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B4C);
    // 0x800BE174: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800BE178: sw          $t4, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r12;
    // 0x800BE17C: b           L_800BE184
    // 0x800BE180: nop

        goto L_800BE184;
    // 0x800BE180: nop

L_800BE184:
    // 0x800BE184: jr          $ra
    // 0x800BE188: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BE188: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006F730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F738: jal         0x8005F064
    // 0x8006F73C: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006F73C: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    after_0:
    // 0x8006F740: b           L_8006F750
    // 0x8006F744: nop

        goto L_8006F750;
    // 0x8006F744: nop

    // 0x8006F748: b           L_8006F750
    // 0x8006F74C: nop

        goto L_8006F750;
    // 0x8006F74C: nop

L_8006F750:
    // 0x8006F750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F758: jr          $ra
    // 0x8006F75C: nop

    return;
    // 0x8006F75C: nop

;}
RECOMP_FUNC void func_8006DEA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DEA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DEAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DEB0: jal         0x80061348
    // 0x8006DEB4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DEB4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006DEB8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DEBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DEC0: beq         $v0, $zero, L_8006DED8
    if (ctx->r2 == 0) {
        // 0x8006DEC4: nop
    
            goto L_8006DED8;
    }
    // 0x8006DEC4: nop

    // 0x8006DEC8: jal         0x80061348
    // 0x8006DECC: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DECC: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x8006DED0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DED4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DED8:
    // 0x8006DED8: b           L_8006DEE8
    // 0x8006DEDC: nop

        goto L_8006DEE8;
    // 0x8006DEDC: nop

    // 0x8006DEE0: b           L_8006DEE8
    // 0x8006DEE4: nop

        goto L_8006DEE8;
    // 0x8006DEE4: nop

L_8006DEE8:
    // 0x8006DEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DEEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DEF0: jr          $ra
    // 0x8006DEF4: nop

    return;
    // 0x8006DEF4: nop

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
RECOMP_FUNC void func_8006D2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D2C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D2CC: jal         0x80061348
    // 0x8006D2D0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D2D0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006D2D4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D2D8: b           L_8006D2E8
    // 0x8006D2DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D2E8;
    // 0x8006D2DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D2E0: b           L_8006D2E8
    // 0x8006D2E4: nop

        goto L_8006D2E8;
    // 0x8006D2E4: nop

L_8006D2E8:
    // 0x8006D2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D2EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D2F0: jr          $ra
    // 0x8006D2F4: nop

    return;
    // 0x8006D2F4: nop

;}
RECOMP_FUNC void func_800B937C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B937C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B9380: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B9384: lbu         $t6, -0x3370($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3370);
    // 0x800B9388: nop

    // 0x800B938C: bne         $t6, $zero, L_800B93B8
    if (ctx->r14 != 0) {
        // 0x800B9390: nop
    
            goto L_800B93B8;
    }
    // 0x800B9390: nop

    // 0x800B9394: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9398: sw          $zero, -0x336C($at)
    MEM_W(-0X336C, ctx->r1) = 0;
    // 0x800B939C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800B93A0: addiu       $t7, $t7, -0x25C8
    ctx->r15 = ADD32(ctx->r15, -0X25C8);
    // 0x800B93A4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B93A8: sw          $t7, -0x3368($at)
    MEM_W(-0X3368, ctx->r1) = ctx->r15;
    // 0x800B93AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B93B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B93B4: sb          $t8, -0x3370($at)
    MEM_B(-0X3370, ctx->r1) = ctx->r24;
L_800B93B8:
    // 0x800B93B8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B93BC: addiu       $t9, $t9, -0x3370
    ctx->r25 = ADD32(ctx->r25, -0X3370);
    // 0x800B93C0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B93C4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800B93C8: b           L_800B93D8
    // 0x800B93CC: addiu       $v0, $v0, -0x6F98
    ctx->r2 = ADD32(ctx->r2, -0X6F98);
        goto L_800B93D8;
    // 0x800B93CC: addiu       $v0, $v0, -0x6F98
    ctx->r2 = ADD32(ctx->r2, -0X6F98);
    // 0x800B93D0: b           L_800B93D8
    // 0x800B93D4: nop

        goto L_800B93D8;
    // 0x800B93D4: nop

L_800B93D8:
    // 0x800B93D8: jr          $ra
    // 0x800B93DC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B93DC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void TempHeap_Alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D164: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000D168: addiu       $t6, $a0, 0xF
    ctx->r14 = ADD32(ctx->r4, 0XF);
    // 0x8000D16C: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x8000D170: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000D174: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8000D178: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000D17C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000D180: lw          $t0, -0x5B0C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B0C);
    // 0x8000D184: lw          $t9, -0x5B10($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B10);
    // 0x8000D188: nop

    // 0x8000D18C: beq         $t9, $t0, L_8000D378
    if (ctx->r25 == ctx->r8) {
        // 0x8000D190: sw          $t9, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r25;
            goto L_8000D378;
    }
    // 0x8000D190: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
L_8000D194:
    // 0x8000D194: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8000D198: nop

    // 0x8000D19C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000D1A0: nop

    // 0x8000D1A4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8000D1A8: beq         $t3, $zero, L_8000D1B8
    if (ctx->r11 == 0) {
        // 0x8000D1AC: nop
    
            goto L_8000D1B8;
    }
    // 0x8000D1AC: nop

    // 0x8000D1B0: b           L_8000D354
    // 0x8000D1B4: nop

        goto L_8000D354;
    // 0x8000D1B4: nop

L_8000D1B8:
    // 0x8000D1B8: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8000D1BC: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000D1C0: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8000D1C4: nop

    // 0x8000D1C8: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x8000D1CC: bne         $at, $zero, L_8000D354
    if (ctx->r1 != 0) {
        // 0x8000D1D0: nop
    
            goto L_8000D354;
    }
    // 0x8000D1D0: nop

    // 0x8000D1D4: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8000D1D8: nop

    // 0x8000D1DC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8000D1E0: nop

    // 0x8000D1E4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8000D1E8: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000D1EC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D1F0: nop

    // 0x8000D1F4: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8000D1F8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000D1FC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D200: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8000D204: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8000D208: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x8000D20C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8000D210: nop

    // 0x8000D214: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8000D218: nop

    // 0x8000D21C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8000D220: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x8000D224: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8000D228: nop

    // 0x8000D22C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8000D230: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8000D234: nop

    // 0x8000D238: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8000D23C: nop

    // 0x8000D240: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8000D244: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8000D248: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8000D24C: nop

    // 0x8000D250: beq         $t1, $t2, L_8000D348
    if (ctx->r9 == ctx->r10) {
        // 0x8000D254: nop
    
            goto L_8000D348;
    }
    // 0x8000D254: nop

    // 0x8000D258: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x8000D25C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D260: nop

    // 0x8000D264: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8000D268: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8000D26C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8000D270: nop

    // 0x8000D274: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8000D278: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8000D27C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8000D280: nop

    // 0x8000D284: subu        $t9, $t5, $t8
    ctx->r25 = SUB32(ctx->r13, ctx->r24);
    // 0x8000D288: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8000D28C: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x8000D290: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8000D294: nop

    // 0x8000D298: sw          $zero, 0xC($t1)
    MEM_W(0XC, ctx->r9) = 0;
    // 0x8000D29C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8000D2A0: nop

    // 0x8000D2A4: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8000D2A8: nop

    // 0x8000D2AC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8000D2B0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000D2B4: lw          $t6, -0x5B0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B0C);
    // 0x8000D2B8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8000D2BC: nop

    // 0x8000D2C0: beq         $t3, $t6, L_8000D348
    if (ctx->r11 == ctx->r14) {
        // 0x8000D2C4: nop
    
            goto L_8000D348;
    }
    // 0x8000D2C4: nop

    // 0x8000D2C8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8000D2CC: nop

    // 0x8000D2D0: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x8000D2D4: nop

    // 0x8000D2D8: andi        $t9, $t5, 0x1
    ctx->r25 = ctx->r13 & 0X1;
    // 0x8000D2DC: beq         $t9, $zero, L_8000D2F4
    if (ctx->r25 == 0) {
        // 0x8000D2E0: nop
    
            goto L_8000D2F4;
    }
    // 0x8000D2E0: nop

    // 0x8000D2E4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D2E8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8000D2EC: b           L_8000D348
    // 0x8000D2F0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
        goto L_8000D348;
    // 0x8000D2F0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_8000D2F4:
    // 0x8000D2F4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8000D2F8: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8000D2FC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8000D300: nop

    // 0x8000D304: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8000D308: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D30C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8000D310: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x8000D314: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x8000D318: nop

    // 0x8000D31C: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x8000D320: sw          $t9, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r25;
    // 0x8000D324: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D328: nop

    // 0x8000D32C: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8000D330: nop

    // 0x8000D334: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8000D338: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8000D33C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8000D340: nop

    // 0x8000D344: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8000D348:
    // 0x8000D348: lw          $v0, 0x8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8);
    // 0x8000D34C: b           L_8000D388
    // 0x8000D350: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
        goto L_8000D388;
    // 0x8000D350: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_8000D354:
    // 0x8000D354: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8000D358: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000D35C: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8000D360: lw          $t5, -0x5B0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B0C);
    // 0x8000D364: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8000D368: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8000D36C: nop

    // 0x8000D370: bne         $t6, $t5, L_8000D194
    if (ctx->r14 != ctx->r13) {
        // 0x8000D374: nop
    
            goto L_8000D194;
    }
    // 0x8000D374: nop

L_8000D378:
    // 0x8000D378: b           L_8000D388
    // 0x8000D37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D388;
    // 0x8000D37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D380: b           L_8000D388
    // 0x8000D384: nop

        goto L_8000D388;
    // 0x8000D384: nop

L_8000D388:
    // 0x8000D388: jr          $ra
    // 0x8000D38C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000D38C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800299C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800299C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800299C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800299CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800299D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800299D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800299D8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800299DC: nop

    // 0x800299E0: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800299E4: nop

    // 0x800299E8: sh          $t7, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r15;
    // 0x800299EC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800299F0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800299F4: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x800299F8: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800299FC: nop

    // 0x80029A00: bne         $t9, $t0, L_80029AA0
    if (ctx->r25 != ctx->r8) {
        // 0x80029A04: nop
    
            goto L_80029AA0;
    }
    // 0x80029A04: nop

    // 0x80029A08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80029A0C: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x80029A10: lh          $t1, 0x4($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X4);
    // 0x80029A14: nop

    // 0x80029A18: bne         $t1, $t2, L_80029AA0
    if (ctx->r9 != ctx->r10) {
        // 0x80029A1C: nop
    
            goto L_80029AA0;
    }
    // 0x80029A1C: nop

    // 0x80029A20: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80029A24: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80029A28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029A2C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80029A30: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80029A34: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80029A38: bne         $t6, $zero, L_80029A4C
    if (ctx->r14 != 0) {
        // 0x80029A3C: sh          $t4, 0x1B48($at)
        MEM_H(0X1B48, ctx->r1) = ctx->r12;
            goto L_80029A4C;
    }
    // 0x80029A3C: sh          $t4, 0x1B48($at)
    MEM_H(0X1B48, ctx->r1) = ctx->r12;
    // 0x80029A40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029A44: b           L_80029A78
    // 0x80029A48: sw          $zero, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = 0;
        goto L_80029A78;
    // 0x80029A48: sw          $zero, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = 0;
L_80029A4C:
    // 0x80029A4C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80029A50: lw          $t9, 0x306C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X306C);
    // 0x80029A54: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80029A58: nop

    // 0x80029A5C: bne         $t7, $t9, L_80029A78
    if (ctx->r15 != ctx->r25) {
        // 0x80029A60: nop
    
            goto L_80029A78;
    }
    // 0x80029A60: nop

    // 0x80029A64: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80029A68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029A6C: lw          $t8, 0x18($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X18);
    // 0x80029A70: nop

    // 0x80029A74: sw          $t8, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = ctx->r24;
L_80029A78:
    // 0x80029A78: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80029A7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029A80: lbu         $t2, 0x10($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X10);
    // 0x80029A84: nop

    // 0x80029A88: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80029A8C: sb          $zero, 0x1B0C($at)
    MEM_B(0X1B0C, ctx->r1) = 0;
    // 0x80029A90: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80029A94: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80029A98: b           L_80029AD0
    // 0x80029A9C: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
        goto L_80029AD0;
    // 0x80029A9C: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
L_80029AA0:
    // 0x80029AA0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80029AA4: lw          $t5, 0x3074($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3074);
    // 0x80029AA8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80029AAC: nop

    // 0x80029AB0: bne         $t5, $t6, L_80029AD0
    if (ctx->r13 != ctx->r14) {
        // 0x80029AB4: nop
    
            goto L_80029AD0;
    }
    // 0x80029AB4: nop

    // 0x80029AB8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80029ABC: lw          $t7, 0x3074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3074);
    // 0x80029AC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029AC4: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x80029AC8: nop

    // 0x80029ACC: sw          $t9, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r25;
L_80029AD0:
    // 0x80029AD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029AD4: jal         0x80029394
    // 0x80029AD8: nop

    func_80029394(rdram, ctx);
        goto after_0;
    // 0x80029AD8: nop

    after_0:
    // 0x80029ADC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80029AE0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029AE4: lh          $t8, 0x2($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X2);
    // 0x80029AE8: nop

    // 0x80029AEC: bne         $t8, $at, L_80029BD4
    if (ctx->r24 != ctx->r1) {
        // 0x80029AF0: nop
    
            goto L_80029BD4;
    }
    // 0x80029AF0: nop

    // 0x80029AF4: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80029AF8: nop

    // 0x80029AFC: bne         $t1, $zero, L_80029BD4
    if (ctx->r9 != 0) {
        // 0x80029B00: nop
    
            goto L_80029BD4;
    }
    // 0x80029B00: nop

    // 0x80029B04: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80029B08: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80029B0C: jal         0x8002A0F8
    // 0x80029B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_1;
    // 0x80029B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80029B14: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80029B18: beq         $at, $zero, L_80029BD4
    if (ctx->r1 == 0) {
        // 0x80029B1C: nop
    
            goto L_80029BD4;
    }
    // 0x80029B1C: nop

    // 0x80029B20: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80029B24: lw          $t2, 0x3074($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3074);
    // 0x80029B28: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029B2C: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x80029B30: nop

    // 0x80029B34: bne         $t3, $at, L_80029BD4
    if (ctx->r11 != ctx->r1) {
        // 0x80029B38: nop
    
            goto L_80029BD4;
    }
    // 0x80029B38: nop

    // 0x80029B3C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80029B40: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    // 0x80029B44: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80029B48: nop

    // 0x80029B4C: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x80029B50: nop

    // 0x80029B54: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80029B58: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80029B5C: nop

    // 0x80029B60: beq         $t7, $zero, L_80029B90
    if (ctx->r15 == 0) {
        // 0x80029B64: nop
    
            goto L_80029B90;
    }
    // 0x80029B64: nop

    // 0x80029B68: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x80029B6C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029B70: bne         $t9, $at, L_80029B90
    if (ctx->r25 != ctx->r1) {
        // 0x80029B74: nop
    
            goto L_80029B90;
    }
    // 0x80029B74: nop

    // 0x80029B78: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80029B7C: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
    // 0x80029B80: nop

    // 0x80029B84: bne         $t8, $t0, L_80029B90
    if (ctx->r24 != ctx->r8) {
        // 0x80029B88: nop
    
            goto L_80029B90;
    }
    // 0x80029B88: nop

    // 0x80029B8C: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
L_80029B90:
    // 0x80029B90: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x80029B94: nop

    // 0x80029B98: beq         $t1, $zero, L_80029BD4
    if (ctx->r9 == 0) {
        // 0x80029B9C: nop
    
            goto L_80029BD4;
    }
    // 0x80029B9C: nop

    // 0x80029BA0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80029BA4: lhu         $t5, 0x2C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2C);
    // 0x80029BA8: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80029BAC: nop

    // 0x80029BB0: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80029BB4: nop

    // 0x80029BB8: beq         $t4, $t5, L_80029BD4
    if (ctx->r12 == ctx->r13) {
        // 0x80029BBC: nop
    
            goto L_80029BD4;
    }
    // 0x80029BBC: nop

    // 0x80029BC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80029BC4: jal         0x8002A22C
    // 0x80029BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8002A22C(rdram, ctx);
        goto after_2;
    // 0x80029BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80029BCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029BD0: sw          $v0, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r2;
L_80029BD4:
    // 0x80029BD4: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x80029BD8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80029BDC: addiu       $t9, $t9, 0x1B18
    ctx->r25 = ADD32(ctx->r25, 0X1B18);
    // 0x80029BE0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80029BE4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80029BE8: nop

    // 0x80029BEC: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x80029BF0: sb          $t0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r8;
    // 0x80029BF4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80029BF8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80029BFC: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
    // 0x80029C00: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80029C04: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x80029C08: lh          $s1, 0x4($t2)
    ctx->r17 = MEM_H(ctx->r10, 0X4);
    // 0x80029C0C: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80029C10: sh          $s1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r17;
    // 0x80029C14: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
    // 0x80029C18: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80029C1C: sra         $t3, $s0, 16
    ctx->r11 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80029C20: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80029C24: sh          $s0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r16;
    // 0x80029C28: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80029C2C: nop

    // 0x80029C30: subu        $t9, $t5, $t6
    ctx->r25 = SUB32(ctx->r13, ctx->r14);
    // 0x80029C34: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80029C38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029C3C: mflo        $t8
    ctx->r24 = lo;
    // 0x80029C40: sll         $t0, $t8, 16
    ctx->r8 = S32(ctx->r24 << 16);
    // 0x80029C44: sra         $t7, $t0, 16
    ctx->r15 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80029C48: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80029C4C: sb          $s0, -0x6550($at)
    MEM_B(-0X6550, ctx->r1) = ctx->r16;
    // 0x80029C50: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80029C54: nop

    // 0x80029C58: sw          $zero, 0x18($t1)
    MEM_W(0X18, ctx->r9) = 0;
    // 0x80029C5C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80029C60: nop

    // 0x80029C64: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80029C68: nop

    // 0x80029C6C: sw          $t3, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r11;
    // 0x80029C70: b           L_80029C78
    // 0x80029C74: nop

        goto L_80029C78;
    // 0x80029C74: nop

L_80029C78:
    // 0x80029C78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029C7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80029C80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80029C84: jr          $ra
    // 0x80029C88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80029C88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80068E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068E84: jal         0x8005F064
    // 0x80068E88: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80068E88: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    after_0:
    // 0x80068E8C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80068E90: b           L_80068EA0
    // 0x80068E94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068EA0;
    // 0x80068E94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068E98: b           L_80068EA0
    // 0x80068E9C: nop

        goto L_80068EA0;
    // 0x80068E9C: nop

L_80068EA0:
    // 0x80068EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068EA8: jr          $ra
    // 0x80068EAC: nop

    return;
    // 0x80068EAC: nop

;}
RECOMP_FUNC void func_80074D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074D4C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80074D50: nop

    // 0x80074D54: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80074D58: nop

    // 0x80074D5C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80074D60: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80074D64: jr          $ra
    // 0x80074D68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80074D68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074D6C: jr          $ra
    // 0x80074D70: nop

    return;
    // 0x80074D70: nop

    // 0x80074D74: jr          $ra
    // 0x80074D78: nop

    return;
    // 0x80074D78: nop

;}
RECOMP_FUNC void func_80068F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068F1C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068F20: nop

    // 0x80068F24: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068F28: nop

    // 0x80068F2C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068F30: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068F34: jr          $ra
    // 0x80068F38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068F38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068F3C: jr          $ra
    // 0x80068F40: nop

    return;
    // 0x80068F40: nop

    // 0x80068F44: jr          $ra
    // 0x80068F48: nop

    return;
    // 0x80068F48: nop

;}
RECOMP_FUNC void func_80075378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007537C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075380: jal         0x80061348
    // 0x80075384: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075384: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80075388: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007538C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075390: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075394: beq         $v0, $zero, L_800753E8
    if (ctx->r2 == 0) {
        // 0x80075398: nop
    
            goto L_800753E8;
    }
    // 0x80075398: nop

    // 0x8007539C: jal         0x80061348
    // 0x800753A0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800753A0: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x800753A4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800753A8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800753AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800753B0: beq         $v0, $zero, L_800753E8
    if (ctx->r2 == 0) {
        // 0x800753B4: nop
    
            goto L_800753E8;
    }
    // 0x800753B4: nop

    // 0x800753B8: jal         0x80061348
    // 0x800753BC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800753BC: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x800753C0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800753C4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800753C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800753CC: beq         $v0, $zero, L_800753E8
    if (ctx->r2 == 0) {
        // 0x800753D0: nop
    
            goto L_800753E8;
    }
    // 0x800753D0: nop

    // 0x800753D4: jal         0x80061348
    // 0x800753D8: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800753D8: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x800753DC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800753E0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800753E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800753E8:
    // 0x800753E8: b           L_800753F8
    // 0x800753EC: nop

        goto L_800753F8;
    // 0x800753EC: nop

    // 0x800753F0: b           L_800753F8
    // 0x800753F4: nop

        goto L_800753F8;
    // 0x800753F4: nop

L_800753F8:
    // 0x800753F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800753FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075400: jr          $ra
    // 0x80075404: nop

    return;
    // 0x80075404: nop

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
RECOMP_FUNC void alRaw16Pull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D03A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D03A8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800D03AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D03B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D03B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D03B8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800D03BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D03C0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D03C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D03C8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800D03CC: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800D03D0: bne         $a2, $zero, L_800D03E0
    if (ctx->r6 != 0) {
        // 0x800D03D4: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_800D03E0;
    }
    // 0x800D03D4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800D03D8: b           L_800D0734
    // 0x800D03DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800D0734;
    // 0x800D03DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800D03E0:
    // 0x800D03E0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800D03E4: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800D03E8: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x800D03EC: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800D03F0: beql        $at, $zero, L_800D0604
    if (ctx->r1 == 0) {
        // 0x800D03F4: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800D0604;
    }
    goto skip_0;
    // 0x800D03F4: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x800D03F8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D03FC: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x800D0400: beql        $t7, $zero, L_800D0604
    if (ctx->r15 == 0) {
        // 0x800D0404: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800D0604;
    }
    goto skip_1;
    // 0x800D0404: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x800D0408: blez        $s2, L_800D0484
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800D040C: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_800D0484;
    }
    // 0x800D040C: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800D0410: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800D0414: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800D0418: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800D041C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D0420: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D0424: jalr        $t9
    // 0x800D0428: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D0428: nop

    after_0:
    // 0x800D042C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800D0430: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800D0434: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800D0438: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800D043C: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x800D0440: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x800D0444: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x800D0448: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D044C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x800D0450: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800D0454: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D0458: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800D045C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D0460: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D0464: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x800D0468: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800D046C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800D0470: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800D0474: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800D0478: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D047C: b           L_800D0488
    // 0x800D0480: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D0488;
    // 0x800D0480: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D0484:
    // 0x800D0484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800D0488:
    // 0x800D0488: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x800D048C: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D0490: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800D0494: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x800D0498: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800D049C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800D04A0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800D04A4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800D04A8: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800D04AC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D04B0: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x800D04B4: beq         $at, $zero, L_800D05DC
    if (ctx->r1 == 0) {
        // 0x800D04B8: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_800D05DC;
    }
    // 0x800D04B8: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x800D04BC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800D04C0:
    // 0x800D04C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D04C4: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x800D04C8: beq         $v0, $at, L_800D04DC
    if (ctx->r2 == ctx->r1) {
        // 0x800D04CC: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_800D04DC;
    }
    // 0x800D04CC: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800D04D0: beq         $v0, $zero, L_800D04DC
    if (ctx->r2 == 0) {
        // 0x800D04D4: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800D04DC;
    }
    // 0x800D04D4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800D04D8: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_800D04DC:
    // 0x800D04DC: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800D04E0: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x800D04E4: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x800D04E8: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800D04EC: beq         $at, $zero, L_800D04FC
    if (ctx->r1 == 0) {
        // 0x800D04F0: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800D04FC;
    }
    // 0x800D04F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800D04F4: b           L_800D04FC
    // 0x800D04F8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_800D04FC;
    // 0x800D04F8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_800D04FC:
    // 0x800D04FC: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800D0500: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800D0504: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800D0508: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800D050C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D0510: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800D0514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D0518: jalr        $t9
    // 0x800D051C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D051C: nop

    after_1:
    // 0x800D0520: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0524: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x800D0528: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800D052C: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800D0530: beq         $v1, $zero, L_800D0544
    if (ctx->r3 == 0) {
        // 0x800D0534: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_800D0544;
    }
    // 0x800D0534: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x800D0538: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800D053C: b           L_800D0548
    // 0x800D0540: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_800D0548;
    // 0x800D0540: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_800D0544:
    // 0x800D0544: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800D0548:
    // 0x800D0548: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x800D054C: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x800D0550: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x800D0554: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D0558: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D055C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0560: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800D0564: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D0568: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800D056C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800D0570: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D0574: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800D0578: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800D057C: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x800D0580: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x800D0584: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800D0588: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800D058C: bne         $a1, $zero, L_800D0598
    if (ctx->r5 != 0) {
        // 0x800D0590: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800D0598;
    }
    // 0x800D0590: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D0594: beq         $a2, $zero, L_800D05D0
    if (ctx->r6 == 0) {
        // 0x800D0598: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_800D05D0;
    }
L_800D0598:
    // 0x800D0598: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x800D059C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D05A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D05A4: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800D05A8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800D05AC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D05B0: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800D05B4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800D05B8: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800D05BC: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x800D05C0: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x800D05C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D05C8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800D05CC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D05D0:
    // 0x800D05D0: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D05D4: bnel        $at, $zero, L_800D04C0
    if (ctx->r1 != 0) {
        // 0x800D05D8: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800D04C0;
    }
    goto skip_2;
    // 0x800D05D8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_800D05DC:
    // 0x800D05DC: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x800D05E0: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800D05E4: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800D05E8: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x800D05EC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800D05F0: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x800D05F4: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x800D05F8: b           L_800D0734
    // 0x800D05FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800D0734;
    // 0x800D05FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D0600: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_800D0604:
    // 0x800D0604: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800D0608: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x800D060C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D0610: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800D0614: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x800D0618: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x800D061C: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x800D0620: bgezl       $s2, L_800D0630
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800D0624: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800D0630;
    }
    goto skip_3;
    // 0x800D0624: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x800D0628: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D062C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_800D0630:
    // 0x800D0630: beql        $at, $zero, L_800D0640
    if (ctx->r1 == 0) {
        // 0x800D0634: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_800D0640;
    }
    goto skip_4;
    // 0x800D0634: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x800D0638: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800D063C: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_800D0640:
    // 0x800D0640: beql        $at, $zero, L_800D06F4
    if (ctx->r1 == 0) {
        // 0x800D0644: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_800D06F4;
    }
    goto skip_5;
    // 0x800D0644: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x800D0648: blez        $s3, L_800D06C8
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800D064C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800D06C8;
    }
    // 0x800D064C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D0650: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800D0654: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x800D0658: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800D065C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800D0660: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D0664: jalr        $t9
    // 0x800D0668: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D0668: nop

    after_2:
    // 0x800D066C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800D0670: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800D0674: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800D0678: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x800D067C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800D0680: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x800D0684: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x800D0688: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x800D068C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0690: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800D0694: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D0698: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800D069C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800D06A0: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800D06A4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D06A8: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x800D06AC: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800D06B0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800D06B4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800D06B8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800D06BC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800D06C0: b           L_800D06C8
    // 0x800D06C4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D06C8;
    // 0x800D06C4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D06C8:
    // 0x800D06C8: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x800D06CC: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800D06D0: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x800D06D4: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800D06D8: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800D06DC: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x800D06E0: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x800D06E4: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x800D06E8: b           L_800D06F4
    // 0x800D06EC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_800D06F4;
    // 0x800D06EC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x800D06F0: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_800D06F4:
    // 0x800D06F4: beq         $s2, $zero, L_800D0730
    if (ctx->r18 == 0) {
        // 0x800D06F8: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_800D0730;
    }
    // 0x800D06F8: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x800D06FC: bgez        $v1, L_800D0708
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0700: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800D0708;
    }
    // 0x800D0700: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D0704: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D0708:
    // 0x800D0708: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x800D070C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D0710: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D0714: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800D0718: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D071C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800D0720: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800D0724: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800D0728: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x800D072C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D0730:
    // 0x800D0730: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800D0734:
    // 0x800D0734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D0738: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D073C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D0740: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0744: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D0748: jr          $ra
    // 0x800D074C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D074C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8005092C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005092C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005093C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80050940: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80050944: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x80050948: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8005094C: lh          $a1, 0x42($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X42);
    // 0x80050950: jal         0x8004EF90
    // 0x80050954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_0;
    // 0x80050954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80050958: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005095C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80050960: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80050964: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80050968: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x8005096C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80050970: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80050974: bne         $t0, $zero, L_800509BC
    if (ctx->r8 != 0) {
        // 0x80050978: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_800509BC;
    }
    // 0x80050978: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005097C: bne         $t1, $zero, L_800509BC
    if (ctx->r9 != 0) {
        // 0x80050980: nop
    
            goto L_800509BC;
    }
    // 0x80050980: nop

L_80050984:
    // 0x80050984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80050988: jal         0x800499B0
    // 0x8005098C: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x8005098C: nop

    after_1:
    // 0x80050990: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80050994: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80050998: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8005099C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800509A0: ori         $at, $at, 0x2
    ctx->r1 = ctx->r1 | 0X2;
    // 0x800509A4: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800509A8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800509AC: bne         $t6, $zero, L_800509BC
    if (ctx->r14 != 0) {
        // 0x800509B0: and         $t7, $t5, $at
        ctx->r15 = ctx->r13 & ctx->r1;
            goto L_800509BC;
    }
    // 0x800509B0: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800509B4: beq         $t7, $zero, L_80050984
    if (ctx->r15 == 0) {
        // 0x800509B8: nop
    
            goto L_80050984;
    }
    // 0x800509B8: nop

L_800509BC:
    // 0x800509BC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800509C0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800509C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800509C8: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x800509CC: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800509D0: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800509D4: bne         $t0, $zero, L_800509E4
    if (ctx->r8 != 0) {
        // 0x800509D8: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_800509E4;
    }
    // 0x800509D8: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800509DC: beq         $t1, $zero, L_80050A0C
    if (ctx->r9 == 0) {
        // 0x800509E0: nop
    
            goto L_80050A0C;
    }
    // 0x800509E0: nop

L_800509E4:
    // 0x800509E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800509E8: jal         0x800507AC
    // 0x800509EC: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    func_800507AC(rdram, ctx);
        goto after_2;
    // 0x800509EC: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    after_2:
    // 0x800509F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800509F4: jal         0x800507AC
    // 0x800509F8: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800507AC(rdram, ctx);
        goto after_3;
    // 0x800509F8: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_3:
    // 0x800509FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80050A00: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    // 0x80050A04: jal         0x80052508
    // 0x80050A08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052508(rdram, ctx);
        goto after_4;
    // 0x80050A08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80050A0C:
    // 0x80050A0C: b           L_80050A14
    // 0x80050A10: nop

        goto L_80050A14;
    // 0x80050A10: nop

L_80050A14:
    // 0x80050A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050A1C: jr          $ra
    // 0x80050A20: nop

    return;
    // 0x80050A20: nop

;}
