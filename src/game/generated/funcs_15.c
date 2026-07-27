#include "recomp.h"
#include "funcs.h"

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
RECOMP_FUNC void func_80072454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007245C: jal         0x80061488
    // 0x80072460: addiu       $a0, $zero, 0x51C
    ctx->r4 = ADD32(0, 0X51C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072460: addiu       $a0, $zero, 0x51C
    ctx->r4 = ADD32(0, 0X51C);
    after_0:
    // 0x80072464: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80072468: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007246C: b           L_8007247C
    // 0x80072470: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007247C;
    // 0x80072470: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072474: b           L_8007247C
    // 0x80072478: nop

        goto L_8007247C;
    // 0x80072478: nop

L_8007247C:
    // 0x8007247C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072484: jr          $ra
    // 0x80072488: nop

    return;
    // 0x80072488: nop

;}
RECOMP_FUNC void func_80004410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004410: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80004414: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80004418: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8000441C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004420: lw          $t6, 0x1148($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1148);
    // 0x80004424: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80004428: blez        $t6, L_800044A4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000442C: nop
    
            goto L_800044A4;
    }
    // 0x8000442C: nop

L_80004430:
    // 0x80004430: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80004434: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80004438: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8000443C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80004440: lw          $t9, 0x114C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X114C);
    // 0x80004444: nop

    // 0x80004448: bne         $t9, $a0, L_80004488
    if (ctx->r25 != ctx->r4) {
        // 0x8000444C: nop
    
            goto L_80004488;
    }
    // 0x8000444C: nop

    // 0x80004450: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80004454: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80004458: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8000445C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80004460: lw          $t2, 0x1150($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1150);
    // 0x80004464: nop

    // 0x80004468: bne         $t2, $a1, L_80004488
    if (ctx->r10 != ctx->r5) {
        // 0x8000446C: nop
    
            goto L_80004488;
    }
    // 0x8000446C: nop

    // 0x80004470: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80004474: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80004478: addiu       $t5, $t5, 0x114C
    ctx->r13 = ADD32(ctx->r13, 0X114C);
    // 0x8000447C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80004480: b           L_800044B4
    // 0x80004484: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
        goto L_800044B4;
    // 0x80004484: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_80004488:
    // 0x80004488: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8000448C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80004490: lw          $t8, 0x1148($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1148);
    // 0x80004494: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80004498: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000449C: bne         $at, $zero, L_80004430
    if (ctx->r1 != 0) {
        // 0x800044A0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80004430;
    }
    // 0x800044A0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_800044A4:
    // 0x800044A4: b           L_800044B4
    // 0x800044A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800044B4;
    // 0x800044A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800044AC: b           L_800044B4
    // 0x800044B0: nop

        goto L_800044B4;
    // 0x800044B0: nop

L_800044B4:
    // 0x800044B4: jr          $ra
    // 0x800044B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800044B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006F694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F694: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F698: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F69C: nop

    // 0x8006F6A0: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x8006F6A4: nop

    // 0x8006F6A8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F6AC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F6B0: jr          $ra
    // 0x8006F6B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F6B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F6B8: jr          $ra
    // 0x8006F6BC: nop

    return;
    // 0x8006F6BC: nop

    // 0x8006F6C0: jr          $ra
    // 0x8006F6C4: nop

    return;
    // 0x8006F6C4: nop

;}
RECOMP_FUNC void func_8007296C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007296C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072970: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072974: nop

    // 0x80072978: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x8007297C: nop

    // 0x80072980: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072984: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072988: jr          $ra
    // 0x8007298C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007298C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072990: jr          $ra
    // 0x80072994: nop

    return;
    // 0x80072994: nop

    // 0x80072998: jr          $ra
    // 0x8007299C: nop

    return;
    // 0x8007299C: nop

;}
RECOMP_FUNC void func_80066CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066CC0: jal         0x80061348
    // 0x80066CC4: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066CC4: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    after_0:
    // 0x80066CC8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066CCC: b           L_80066CDC
    // 0x80066CD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066CDC;
    // 0x80066CD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066CD4: b           L_80066CDC
    // 0x80066CD8: nop

        goto L_80066CDC;
    // 0x80066CD8: nop

L_80066CDC:
    // 0x80066CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066CE4: jr          $ra
    // 0x80066CE8: nop

    return;
    // 0x80066CE8: nop

;}
RECOMP_FUNC void alCSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA9BC: jr          $ra
    // 0x800CA9C0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x800CA9C0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_80074D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074D80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80074D84: nop

    // 0x80074D88: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80074D8C: nop

    // 0x80074D90: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80074D94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80074D98: jr          $ra
    // 0x80074D9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80074D9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074DA0: jr          $ra
    // 0x80074DA4: nop

    return;
    // 0x80074DA4: nop

    // 0x80074DA8: jr          $ra
    // 0x80074DAC: nop

    return;
    // 0x80074DAC: nop

;}
RECOMP_FUNC void func_80088674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008867C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80088680: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80088684: jal         0x8008B4EC
    // 0x80088688: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80088688: nop

    after_0:
    // 0x8008868C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80088690: jal         0x8008BC70
    // 0x80088694: nop

    func_8008BC70(rdram, ctx);
        goto after_1;
    // 0x80088694: nop

    after_1:
    // 0x80088698: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008869C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800886A0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800886A4: jal         0x8008B738
    // 0x800886A8: addiu       $a1, $t6, 0x15
    ctx->r5 = ADD32(ctx->r14, 0X15);
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x800886A8: addiu       $a1, $t6, 0x15
    ctx->r5 = ADD32(ctx->r14, 0X15);
    after_2:
    // 0x800886AC: b           L_800886B4
    // 0x800886B0: nop

        goto L_800886B4;
    // 0x800886B0: nop

L_800886B4:
    // 0x800886B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800886B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800886BC: jr          $ra
    // 0x800886C0: nop

    return;
    // 0x800886C0: nop

;}
RECOMP_FUNC void AudioDriver_InitOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB640: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BB644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BB648: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800BB64C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800BB650: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800BB654: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800BB658: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BB65C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800BB660: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BB664: lw          $t6, -0x1D90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1D90);
    // 0x800BB668: nop

    // 0x800BB66C: beq         $t6, $zero, L_800BBB98
    if (ctx->r14 == 0) {
        // 0x800BB670: nop
    
            goto L_800BBB98;
    }
    // 0x800BB670: nop

    // 0x800BB674: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800BB678: lw          $t7, -0x1D90($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1D90);
    // 0x800BB67C: nop

    // 0x800BB680: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800BB684: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BB688: lw          $t8, -0x1D90($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1D90);
    // 0x800BB68C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB690: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800BB694: nop

    // 0x800BB698: sw          $t9, -0x1D90($at)
    MEM_W(-0X1D90, ctx->r1) = ctx->r25;
    // 0x800BB69C: lbu         $t0, 0x43($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X43);
    // 0x800BB6A0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800BB6A4: nop

    // 0x800BB6A8: sb          $t0, 0x4($t1)
    MEM_B(0X4, ctx->r9) = ctx->r8;
    // 0x800BB6AC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800BB6B0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800BB6B4: nop

    // 0x800BB6B8: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800BB6BC: lbu         $t4, 0x4F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4F);
    // 0x800BB6C0: nop

    // 0x800BB6C4: sll         $t5, $t4, 14
    ctx->r13 = S32(ctx->r12 << 14);
    // 0x800BB6C8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800BB6CC: lbu         $s0, 0x43($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X43);
    // 0x800BB6D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BB6D4: beq         $s0, $at, L_800BB738
    if (ctx->r16 == ctx->r1) {
        // 0x800BB6D8: nop
    
            goto L_800BB738;
    }
    // 0x800BB6D8: nop

    // 0x800BB6DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BB6E0: beq         $s0, $at, L_800BB7C0
    if (ctx->r16 == ctx->r1) {
        // 0x800BB6E4: nop
    
            goto L_800BB7C0;
    }
    // 0x800BB6E4: nop

    // 0x800BB6E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BB6EC: beq         $s0, $at, L_800BB83C
    if (ctx->r16 == ctx->r1) {
        // 0x800BB6F0: nop
    
            goto L_800BB83C;
    }
    // 0x800BB6F0: nop

    // 0x800BB6F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BB6F8: beq         $s0, $at, L_800BB8B8
    if (ctx->r16 == ctx->r1) {
        // 0x800BB6FC: nop
    
            goto L_800BB8B8;
    }
    // 0x800BB6FC: nop

    // 0x800BB700: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800BB704: beq         $s0, $at, L_800BB93C
    if (ctx->r16 == ctx->r1) {
        // 0x800BB708: nop
    
            goto L_800BB93C;
    }
    // 0x800BB708: nop

    // 0x800BB70C: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x800BB710: beq         $s0, $at, L_800BB990
    if (ctx->r16 == ctx->r1) {
        // 0x800BB714: nop
    
            goto L_800BB990;
    }
    // 0x800BB714: nop

    // 0x800BB718: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x800BB71C: beq         $s0, $at, L_800BBA48
    if (ctx->r16 == ctx->r1) {
        // 0x800BB720: nop
    
            goto L_800BBA48;
    }
    // 0x800BB720: nop

    // 0x800BB724: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x800BB728: beq         $s0, $at, L_800BBAF0
    if (ctx->r16 == ctx->r1) {
        // 0x800BB72C: nop
    
            goto L_800BBAF0;
    }
    // 0x800BB72C: nop

    // 0x800BB730: b           L_800BBB98
    // 0x800BB734: nop

        goto L_800BBB98;
    // 0x800BB734: nop

L_800BB738:
    // 0x800BB738: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800BB73C: nop

    // 0x800BB740: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800BB744: lbu         $t7, 0x47($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X47);
    // 0x800BB748: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800BB74C: addiu       $t8, $zero, 0x103
    ctx->r24 = ADD32(0, 0X103);
    // 0x800BB750: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800BB754: sh          $t9, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r25;
    // 0x800BB758: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BB75C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BB760: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800BB764: sb          $t2, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r10;
    // 0x800BB768: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800BB76C: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800BB770: lbu         $t5, 0xC($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XC);
    // 0x800BB774: nop

    // 0x800BB778: subu        $t8, $t6, $t5
    ctx->r24 = SUB32(ctx->r14, ctx->r13);
    // 0x800BB77C: sb          $t8, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r24;
    // 0x800BB780: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800BB784: nop

    // 0x800BB788: lbu         $t9, 0xD($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XD);
    // 0x800BB78C: nop

    // 0x800BB790: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BB794: bgez        $t9, L_800BB7AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BB798: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BB7AC;
    }
    // 0x800BB798: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB79C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BB7A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BB7A4: nop

    // 0x800BB7A8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800BB7AC:
    // 0x800BB7AC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800BB7B0: nop

    // 0x800BB7B4: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x800BB7B8: b           L_800BBB98
    // 0x800BB7BC: nop

        goto L_800BBB98;
    // 0x800BB7BC: nop

L_800BB7C0:
    // 0x800BB7C0: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x800BB7C4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800BB7C8: addiu       $t2, $zero, 0x100
    ctx->r10 = ADD32(0, 0X100);
    // 0x800BB7CC: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x800BB7D0: sh          $t3, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r11;
    // 0x800BB7D4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800BB7D8: nop

    // 0x800BB7DC: lhu         $t8, 0x6($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X6);
    // 0x800BB7E0: nop

    // 0x800BB7E4: sh          $t8, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r24;
    // 0x800BB7E8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800BB7EC: nop

    // 0x800BB7F0: sb          $zero, 0x5($t4)
    MEM_B(0X5, ctx->r12) = 0;
    // 0x800BB7F4: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BB7F8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800BB7FC: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x800BB800: subu        $t0, $t9, $t7
    ctx->r8 = SUB32(ctx->r25, ctx->r15);
    // 0x800BB804: sb          $t0, 0xE($t2)
    MEM_B(0XE, ctx->r10) = ctx->r8;
    // 0x800BB808: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BB80C: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x800BB810: sb          $t1, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r9;
    // 0x800BB814: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BB818: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800BB81C: sb          $t6, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r14;
    // 0x800BB820: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BB824: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB828: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800BB82C: nop

    // 0x800BB830: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800BB834: b           L_800BBB98
    // 0x800BB838: nop

        goto L_800BBB98;
    // 0x800BB838: nop

L_800BB83C:
    // 0x800BB83C: lbu         $t4, 0x47($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X47);
    // 0x800BB840: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800BB844: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x800BB848: subu        $t7, $t9, $t4
    ctx->r15 = SUB32(ctx->r25, ctx->r12);
    // 0x800BB84C: sh          $t7, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r15;
    // 0x800BB850: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800BB854: nop

    // 0x800BB858: sh          $zero, 0x8($t2)
    MEM_H(0X8, ctx->r10) = 0;
    // 0x800BB85C: lbu         $t1, 0x4B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BB860: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BB864: nop

    // 0x800BB868: sb          $t1, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r9;
    // 0x800BB86C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BB870: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800BB874: sb          $t6, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r14;
    // 0x800BB878: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800BB87C: nop

    // 0x800BB880: lbu         $t9, 0xC($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0XC);
    // 0x800BB884: nop

    // 0x800BB888: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800BB88C: bgez        $t9, L_800BB8A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BB890: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800BB8A4;
    }
    // 0x800BB890: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BB894: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BB898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BB89C: nop

    // 0x800BB8A0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800BB8A4:
    // 0x800BB8A4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800BB8A8: nop

    // 0x800BB8AC: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x800BB8B0: b           L_800BBB98
    // 0x800BB8B4: nop

        goto L_800BBB98;
    // 0x800BB8B4: nop

L_800BB8B8:
    // 0x800BB8B8: lbu         $t7, 0x47($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X47);
    // 0x800BB8BC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800BB8C0: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x800BB8C4: subu        $t2, $t0, $t7
    ctx->r10 = SUB32(ctx->r8, ctx->r15);
    // 0x800BB8C8: sh          $t2, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r10;
    // 0x800BB8CC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BB8D0: nop

    // 0x800BB8D4: sh          $zero, 0x8($t3)
    MEM_H(0X8, ctx->r11) = 0;
    // 0x800BB8D8: lbu         $t6, 0x4B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BB8DC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BB8E0: nop

    // 0x800BB8E4: sb          $t6, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r14;
    // 0x800BB8E8: lbu         $t5, 0x4B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BB8EC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800BB8F0: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x800BB8F4: subu        $t4, $t9, $t5
    ctx->r12 = SUB32(ctx->r25, ctx->r13);
    // 0x800BB8F8: sb          $t4, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r12;
    // 0x800BB8FC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800BB900: nop

    // 0x800BB904: lbu         $t2, 0xC($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0XC);
    // 0x800BB908: nop

    // 0x800BB90C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800BB910: bgez        $t2, L_800BB928
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BB914: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BB928;
    }
    // 0x800BB914: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB918: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BB91C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB920: nop

    // 0x800BB924: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800BB928:
    // 0x800BB928: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800BB92C: nop

    // 0x800BB930: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x800BB934: b           L_800BBB98
    // 0x800BB938: nop

        goto L_800BBB98;
    // 0x800BB938: nop

L_800BB93C:
    // 0x800BB93C: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BB940: jal         0x800BB5AC
    // 0x800BB944: nop

    AudioDriver_DepthToCents(rdram, ctx);
        goto after_0;
    // 0x800BB944: nop

    after_0:
    // 0x800BB948: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BB94C: nop

    // 0x800BB950: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    // 0x800BB954: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800BB958: nop

    // 0x800BB95C: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800BB960: lbu         $t8, 0x47($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X47);
    // 0x800BB964: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800BB968: addiu       $t9, $zero, 0x103
    ctx->r25 = ADD32(0, 0X103);
    // 0x800BB96C: subu        $t5, $t9, $t8
    ctx->r13 = SUB32(ctx->r25, ctx->r24);
    // 0x800BB970: sh          $t5, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r13;
    // 0x800BB974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB978: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BB97C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800BB980: nop

    // 0x800BB984: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x800BB988: b           L_800BBB98
    // 0x800BB98C: nop

        goto L_800BBB98;
    // 0x800BB98C: nop

L_800BB990:
    // 0x800BB990: lbu         $t7, 0x47($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X47);
    // 0x800BB994: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800BB998: addiu       $t2, $zero, 0x100
    ctx->r10 = ADD32(0, 0X100);
    // 0x800BB99C: subu        $t1, $t2, $t7
    ctx->r9 = SUB32(ctx->r10, ctx->r15);
    // 0x800BB9A0: sh          $t1, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r9;
    // 0x800BB9A4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800BB9A8: nop

    // 0x800BB9AC: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x800BB9B0: nop

    // 0x800BB9B4: sh          $t9, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r25;
    // 0x800BB9B8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BB9BC: nop

    // 0x800BB9C0: sb          $zero, 0x5($t8)
    MEM_B(0X5, ctx->r24) = 0;
    // 0x800BB9C4: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BB9C8: jal         0x800BB5AC
    // 0x800BB9CC: nop

    AudioDriver_DepthToCents(rdram, ctx);
        goto after_1;
    // 0x800BB9CC: nop

    after_1:
    // 0x800BB9D0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800BB9D4: nop

    // 0x800BB9D8: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800BB9DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BB9E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BB9E4: nop

    // 0x800BB9E8: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800BB9EC: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x800BB9F0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800BB9F4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800BB9F8: nop

    // 0x800BB9FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BBA00: jal         0x800CADC0
    // 0x800BBA04: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    alCents2Ratio(rdram, ctx);
        goto after_2;
    // 0x800BBA04: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    after_2:
    // 0x800BBA08: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800BBA0C: nop

    // 0x800BBA10: swc1        $f0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f0.u32l;
    // 0x800BBA14: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BBA18: jal         0x800CADC0
    // 0x800BBA1C: nop

    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x800BBA1C: nop

    after_3:
    // 0x800BBA20: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800BBA24: nop

    // 0x800BBA28: swc1        $f0, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f0.u32l;
    // 0x800BBA2C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800BBA30: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800BBA34: lwc1        $f18, 0x10($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X10);
    // 0x800BBA38: nop

    // 0x800BBA3C: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x800BBA40: b           L_800BBB98
    // 0x800BBA44: nop

        goto L_800BBB98;
    // 0x800BBA44: nop

L_800BBA48:
    // 0x800BBA48: lbu         $t3, 0x47($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X47);
    // 0x800BBA4C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BBA50: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x800BBA54: subu        $t6, $t9, $t3
    ctx->r14 = SUB32(ctx->r25, ctx->r11);
    // 0x800BBA58: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
    // 0x800BBA5C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800BBA60: nop

    // 0x800BBA64: lhu         $t4, 0x6($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X6);
    // 0x800BBA68: nop

    // 0x800BBA6C: sh          $t4, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r12;
    // 0x800BBA70: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BBA74: jal         0x800BB5AC
    // 0x800BBA78: nop

    AudioDriver_DepthToCents(rdram, ctx);
        goto after_4;
    // 0x800BBA78: nop

    after_4:
    // 0x800BBA7C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800BBA80: nop

    // 0x800BBA84: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800BBA88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BBA8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BBA90: nop

    // 0x800BBA94: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800BBA98: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x800BBA9C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800BBAA0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800BBAA4: nop

    // 0x800BBAA8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BBAAC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800BBAB0: nop

    // 0x800BBAB4: sw          $t7, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r15;
    // 0x800BBAB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BBABC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800BBAC0: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x800BBAC4: sw          $t3, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r11;
    // 0x800BBAC8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800BBACC: nop

    // 0x800BBAD0: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    // 0x800BBAD4: jal         0x800CADC0
    // 0x800BBAD8: nop

    alCents2Ratio(rdram, ctx);
        goto after_5;
    // 0x800BBAD8: nop

    after_5:
    // 0x800BBADC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800BBAE0: nop

    // 0x800BBAE4: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x800BBAE8: b           L_800BBB98
    // 0x800BBAEC: nop

        goto L_800BBB98;
    // 0x800BBAEC: nop

L_800BBAF0:
    // 0x800BBAF0: lbu         $t5, 0x47($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X47);
    // 0x800BBAF4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800BBAF8: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x800BBAFC: subu        $t2, $t0, $t5
    ctx->r10 = SUB32(ctx->r8, ctx->r13);
    // 0x800BBB00: sh          $t2, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r10;
    // 0x800BBB04: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800BBB08: nop

    // 0x800BBB0C: lhu         $t9, 0x6($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X6);
    // 0x800BBB10: nop

    // 0x800BBB14: sh          $t9, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r25;
    // 0x800BBB18: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    // 0x800BBB1C: jal         0x800BB5AC
    // 0x800BBB20: nop

    AudioDriver_DepthToCents(rdram, ctx);
        goto after_6;
    // 0x800BBB20: nop

    after_6:
    // 0x800BBB24: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BBB28: nop

    // 0x800BBB2C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800BBB30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BBB34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BBB38: nop

    // 0x800BBB3C: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800BBB40: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800BBB44: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BBB48: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800BBB4C: nop

    // 0x800BBB50: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BBB54: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800BBB58: negu        $t4, $t8
    ctx->r12 = SUB32(0, ctx->r24);
    // 0x800BBB5C: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x800BBB60: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800BBB64: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800BBB68: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x800BBB6C: sw          $t2, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r10;
    // 0x800BBB70: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800BBB74: nop

    // 0x800BBB78: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x800BBB7C: jal         0x800CADC0
    // 0x800BBB80: nop

    alCents2Ratio(rdram, ctx);
        goto after_7;
    // 0x800BBB80: nop

    after_7:
    // 0x800BBB84: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800BBB88: nop

    // 0x800BBB8C: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x800BBB90: b           L_800BBB98
    // 0x800BBB94: nop

        goto L_800BBB98;
    // 0x800BBB94: nop

L_800BBB98:
    // 0x800BBB98: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800BBB9C: b           L_800BBBAC
    // 0x800BBBA0: nop

        goto L_800BBBAC;
    // 0x800BBBA0: nop

    // 0x800BBBA4: b           L_800BBBAC
    // 0x800BBBA8: nop

        goto L_800BBBAC;
    // 0x800BBBA8: nop

L_800BBBAC:
    // 0x800BBBAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BBBB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BBBB4: jr          $ra
    // 0x800BBBB8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800BBBB8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006DDB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DDB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DDBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DDC0: jal         0x80061348
    // 0x8006DDC4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DDC4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x8006DDC8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DDCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DDD0: beq         $v0, $zero, L_8006DDE8
    if (ctx->r2 == 0) {
        // 0x8006DDD4: nop
    
            goto L_8006DDE8;
    }
    // 0x8006DDD4: nop

    // 0x8006DDD8: jal         0x80061348
    // 0x8006DDDC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DDDC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_1:
    // 0x8006DDE0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DDE4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DDE8:
    // 0x8006DDE8: b           L_8006DDF8
    // 0x8006DDEC: nop

        goto L_8006DDF8;
    // 0x8006DDEC: nop

    // 0x8006DDF0: b           L_8006DDF8
    // 0x8006DDF4: nop

        goto L_8006DDF8;
    // 0x8006DDF4: nop

L_8006DDF8:
    // 0x8006DDF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DDFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DE00: jr          $ra
    // 0x8006DE04: nop

    return;
    // 0x8006DE04: nop

;}
RECOMP_FUNC void func_8008C528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C528: lhu         $t6, 0x14($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X14);
    // 0x8008C52C: lhu         $t8, 0x10($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X10);
    // 0x8008C530: lhu         $t1, 0x12($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X12);
    // 0x8008C534: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8008C538: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8008C53C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8008C540: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x8008C544: sb          $t2, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r10;
    // 0x8008C548: jr          $ra
    // 0x8008C54C: nop

    return;
    // 0x8008C54C: nop

    // 0x8008C550: jr          $ra
    // 0x8008C554: nop

    return;
    // 0x8008C554: nop

;}
RECOMP_FUNC void func_80058B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80058B50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058B54: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80058B58: addiu       $t6, $t6, 0xE80
    ctx->r14 = ADD32(ctx->r14, 0XE80);
    // 0x80058B5C: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80058B60: nop

    // 0x80058B64: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80058B68: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80058B6C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80058B70: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80058B74: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80058B78: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80058B7C: bne         $t2, $zero, L_80058B8C
    if (ctx->r10 != 0) {
        // 0x80058B80: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80058B8C;
    }
    // 0x80058B80: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80058B84: beq         $t3, $zero, L_80058E60
    if (ctx->r11 == 0) {
        // 0x80058B88: nop
    
            goto L_80058E60;
    }
    // 0x80058B88: nop

L_80058B8C:
    // 0x80058B8C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80058B90: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80058B94: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80058B98: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80058B9C: bne         $t6, $zero, L_80058CE8
    if (ctx->r14 != 0) {
        // 0x80058BA0: andi        $t7, $t5, 0x1
        ctx->r15 = ctx->r13 & 0X1;
            goto L_80058CE8;
    }
    // 0x80058BA0: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80058BA4: bne         $t7, $zero, L_80058CE8
    if (ctx->r15 != 0) {
        // 0x80058BA8: nop
    
            goto L_80058CE8;
    }
    // 0x80058BA8: nop

    // 0x80058BAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80058BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058BB4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80058BB8: nop

    // 0x80058BBC: swc1        $f4, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f4.u32l;
    // 0x80058BC0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80058BC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058BC8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80058BCC: nop

    // 0x80058BD0: swc1        $f6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f6.u32l;
    // 0x80058BD4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80058BD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058BDC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80058BE0: nop

    // 0x80058BE4: swc1        $f8, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f8.u32l;
    // 0x80058BE8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80058BEC: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80058BF0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80058BF4: lwc1        $f10, 0x10($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80058BF8: nop

    // 0x80058BFC: swc1        $f10, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f10.u32l;
    // 0x80058C00: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058C04: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80058C08: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80058C0C: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80058C10: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80058C14: bne         $t6, $zero, L_80058C24
    if (ctx->r14 != 0) {
        // 0x80058C18: andi        $t7, $t5, 0x8
        ctx->r15 = ctx->r13 & 0X8;
            goto L_80058C24;
    }
    // 0x80058C18: andi        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 & 0X8;
    // 0x80058C1C: beq         $t7, $zero, L_80058C68
    if (ctx->r15 == 0) {
        // 0x80058C20: nop
    
            goto L_80058C68;
    }
    // 0x80058C20: nop

L_80058C24:
    // 0x80058C24: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80058C28: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80058C2C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80058C30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80058C34: lwc1        $f16, 0xC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80058C38: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80058C3C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80058C40: swc1        $f4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f4.u32l;
    // 0x80058C44: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80058C48: nop

    // 0x80058C4C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80058C50: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80058C54: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x80058C58: ori         $t5, $t3, 0x8
    ctx->r13 = ctx->r11 | 0X8;
    // 0x80058C5C: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80058C60: b           L_80058CAC
    // 0x80058C64: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80058CAC;
    // 0x80058C64: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80058C68:
    // 0x80058C68: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058C6C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80058C70: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80058C74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058C78: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80058C7C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80058C80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80058C84: swc1        $f10, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f10.u32l;
    // 0x80058C88: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80058C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058C90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80058C94: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80058C98: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80058C9C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80058CA0: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80058CA4: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x80058CA8: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
L_80058CAC:
    // 0x80058CAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80058CB0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80058CB4: addiu       $a2, $zero, 0x143
    ctx->r6 = ADD32(0, 0X143);
    // 0x80058CB8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80058CBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80058CC0: jal         0x8004F3E8
    // 0x80058CC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8004F3E8(rdram, ctx);
        goto after_0;
    // 0x80058CC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x80058CC8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80058CCC: nop

    // 0x80058CD0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80058CD4: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80058CD8: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x80058CDC: ori         $t7, $t5, 0x1
    ctx->r15 = ctx->r13 | 0X1;
    // 0x80058CE0: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80058CE4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_80058CE8:
    // 0x80058CE8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80058CEC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80058CF0: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80058CF4: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80058CF8: bne         $t0, $zero, L_80058D08
    if (ctx->r8 != 0) {
        // 0x80058CFC: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_80058D08;
    }
    // 0x80058CFC: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x80058D00: beq         $t1, $zero, L_80058D2C
    if (ctx->r9 == 0) {
        // 0x80058D04: nop
    
            goto L_80058D2C;
    }
    // 0x80058D04: nop

L_80058D08:
    // 0x80058D08: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80058D0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D10: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D14: lwc1        $f16, 0x24($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X24);
    // 0x80058D18: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80058D1C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80058D20: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80058D24: b           L_80058D4C
    // 0x80058D28: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
        goto L_80058D4C;
    // 0x80058D28: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
L_80058D2C:
    // 0x80058D2C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80058D30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D34: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D38: lwc1        $f10, 0x24($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X24);
    // 0x80058D3C: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80058D40: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80058D44: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80058D48: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
L_80058D4C:
    // 0x80058D4C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80058D50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D54: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D58: lwc1        $f8, 0x28($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80058D5C: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80058D60: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80058D64: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80058D68: swc1        $f18, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f18.u32l;
    // 0x80058D6C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80058D70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D74: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D78: lwc1        $f4, 0x30($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X30);
    // 0x80058D7C: lwc1        $f6, 0x28($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X28);
    // 0x80058D80: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80058D84: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80058D88: swc1        $f16, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f16.u32l;
    // 0x80058D8C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80058D90: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80058D94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058D98: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80058D9C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80058DA0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80058DA4: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80058DA8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80058DAC: nop

    // 0x80058DB0: lwc1        $f10, 0x20($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80058DB4: nop

    // 0x80058DB8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80058DBC: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x80058DC0: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80058DC4: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
    // 0x80058DC8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80058DCC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80058DD0: lwc1        $f8, 0x20($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80058DD4: lwc1        $f17, -0xEB0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XEB0);
    // 0x80058DD8: lwc1        $f16, -0xEAC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEAC);
    // 0x80058DDC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80058DE0: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80058DE4: nop

    // 0x80058DE8: bc1f        L_80058E14
    if (!c1cs) {
        // 0x80058DEC: nop
    
            goto L_80058E14;
    }
    // 0x80058DEC: nop

    // 0x80058DF0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80058DF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80058DF8: lwc1        $f6, 0x20($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80058DFC: lwc1        $f19, -0xEA8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XEA8);
    // 0x80058E00: lwc1        $f18, -0xEA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEA4);
    // 0x80058E04: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80058E08: sub.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
    // 0x80058E0C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80058E10: swc1        $f10, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f10.u32l;
L_80058E14:
    // 0x80058E14: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80058E18: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x80058E1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058E20: lwc1        $f16, 0x10($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80058E24: nop

    // 0x80058E28: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80058E2C: nop

    // 0x80058E30: bc1f        L_80058E60
    if (!c1cs) {
        // 0x80058E34: nop
    
            goto L_80058E60;
    }
    // 0x80058E34: nop

    // 0x80058E38: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80058E3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058E40: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80058E44: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80058E48: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80058E4C: lui         $at, 0xFF7F
    ctx->r1 = S32(0XFF7F << 16);
    // 0x80058E50: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x80058E54: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80058E58: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80058E5C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_80058E60:
    // 0x80058E60: b           L_80058E68
    // 0x80058E64: nop

        goto L_80058E68;
    // 0x80058E64: nop

L_80058E68:
    // 0x80058E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80058E6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80058E70: jr          $ra
    // 0x80058E74: nop

    return;
    // 0x80058E74: nop

;}
RECOMP_FUNC void MtxUtil_RotateY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C25B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C25BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C25C0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C25C4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C25C8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C25CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C25D0: jal         0x800C1A84
    // 0x800C25D4: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_0;
    // 0x800C25D4: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    after_0:
    // 0x800C25D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C25DC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C25E0: lwc1        $f9, -0x190($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X190);
    // 0x800C25E4: lwc1        $f8, -0x18C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X18C);
    // 0x800C25E8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C25EC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800C25F0: jal         0x800C3338
    // 0x800C25F4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Cosf(rdram, ctx);
        goto after_1;
    // 0x800C25F4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_1:
    // 0x800C25F8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800C25FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C2600: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C2604: lwc1        $f5, -0x188($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X188);
    // 0x800C2608: lwc1        $f4, -0x184($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X184);
    // 0x800C260C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C2610: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C2614: jal         0x800C3070
    // 0x800C2618: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_2;
    // 0x800C2618: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_2:
    // 0x800C261C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800C2620: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2624: nop

    // 0x800C2628: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800C262C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800C2630: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2634: addiu       $t6, $t6, 0xCF0
    ctx->r14 = ADD32(ctx->r14, 0XCF0);
    // 0x800C2638: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800C263C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800C2640: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800C2644: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C2648: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C264C: nop

    // 0x800C2650: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800C2654: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800C2658: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800C265C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C2660: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C2664: lwc1        $f20, 0x0($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C2668: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C266C: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2670: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C2674: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2678: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C267C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C2680: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800C2684: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2688: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C268C: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x800C2690: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2694: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2698: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C269C: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C26A0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C26A4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C26A8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C26AC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C26B0: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x800C26B4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800C26B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C26BC: lwc1        $f20, 0x4($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C26C0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C26C4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C26C8: lwc1        $f18, 0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4);
    // 0x800C26CC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C26D0: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C26D4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C26D8: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800C26DC: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C26E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C26E4: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x800C26E8: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C26EC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C26F0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C26F4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C26F8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C26FC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2700: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C2704: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C2708: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x800C270C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C2710: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C2714: lwc1        $f20, 0x8($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800C2718: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C271C: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800C2720: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800C2724: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2728: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C272C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C2730: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800C2734: mul.s       $f16, $f20, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800C2738: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C273C: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x800C2740: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2744: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2748: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C274C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C2750: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2754: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2758: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C275C: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800C2760: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x800C2764: b           L_800C276C
    // 0x800C2768: nop

        goto L_800C276C;
    // 0x800C2768: nop

L_800C276C:
    // 0x800C276C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2770: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C2774: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C2778: jr          $ra
    // 0x800C277C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C277C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8006807C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006807C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068080: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068084: nop

    // 0x80068088: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006808C: nop

    // 0x80068090: slti        $t7, $v0, 0x190
    ctx->r15 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80068094: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068098: jr          $ra
    // 0x8006809C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006809C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800680A0: jr          $ra
    // 0x800680A4: nop

    return;
    // 0x800680A4: nop

    // 0x800680A8: jr          $ra
    // 0x800680AC: nop

    return;
    // 0x800680AC: nop

;}
RECOMP_FUNC void func_80061FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061FFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80062000: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062004: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80062008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006200C: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x80062010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80062014: beq         $t6, $at, L_80062090
    if (ctx->r14 == ctx->r1) {
        // 0x80062018: nop
    
            goto L_80062090;
    }
    // 0x80062018: nop

L_8006201C:
    // 0x8006201C: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x80062020: lui         $t9, 0x809D
    ctx->r25 = S32(0X809D << 16);
    // 0x80062024: addiu       $t9, $t9, 0x546C
    ctx->r25 = ADD32(ctx->r25, 0X546C);
    // 0x80062028: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x8006202C: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80062030: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80062034: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80062038: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x8006203C: jal         0x800BD1FC
    // 0x80062040: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80062040: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_0:
    // 0x80062044: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80062048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006204C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80062050: jal         0x800BD218
    // 0x80062054: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80062054: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x80062058: jal         0x800620A8
    // 0x8006205C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800620A8(rdram, ctx);
        goto after_2;
    // 0x8006205C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80062060: beq         $v0, $zero, L_8006207C
    if (ctx->r2 == 0) {
        // 0x80062064: nop
    
            goto L_8006207C;
    }
    // 0x80062064: nop

    // 0x80062068: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x8006206C: nop

    // 0x80062070: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80062074: b           L_80062080
    // 0x80062078: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
        goto L_80062080;
    // 0x80062078: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
L_8006207C:
    // 0x8006207C: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
L_80062080:
    // 0x80062080: lh          $t2, 0x3A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3A);
    // 0x80062084: nop

    // 0x80062088: bne         $t2, $zero, L_8006201C
    if (ctx->r10 != 0) {
        // 0x8006208C: nop
    
            goto L_8006201C;
    }
    // 0x8006208C: nop

L_80062090:
    // 0x80062090: b           L_80062098
    // 0x80062094: nop

        goto L_80062098;
    // 0x80062094: nop

L_80062098:
    // 0x80062098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006209C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800620A0: jr          $ra
    // 0x800620A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800620A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800ACD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACD90: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800ACD94: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800ACD98: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800ACD9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800ACDA0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800ACDA4: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x800ACDA8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800ACDAC: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800ACDB0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800ACDB4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800ACDB8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800ACDBC: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800ACDC0: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800ACDC4: nop

    // 0x800ACDC8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800ACDCC: beq         $t1, $zero, L_800ACE30
    if (ctx->r9 == 0) {
        // 0x800ACDD0: nop
    
            goto L_800ACE30;
    }
    // 0x800ACDD0: nop

    // 0x800ACDD4: beq         $a1, $zero, L_800ACDF0
    if (ctx->r5 == 0) {
        // 0x800ACDD8: nop
    
            goto L_800ACDF0;
    }
    // 0x800ACDD8: nop

    // 0x800ACDDC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800ACDE0: nop

    // 0x800ACDE4: lwc1        $f4, 0xCC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x800ACDE8: nop

    // 0x800ACDEC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_800ACDF0:
    // 0x800ACDF0: beq         $a2, $zero, L_800ACE0C
    if (ctx->r6 == 0) {
        // 0x800ACDF4: nop
    
            goto L_800ACE0C;
    }
    // 0x800ACDF4: nop

    // 0x800ACDF8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800ACDFC: nop

    // 0x800ACE00: lwc1        $f6, 0xD0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x800ACE04: nop

    // 0x800ACE08: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_800ACE0C:
    // 0x800ACE0C: beq         $a3, $zero, L_800ACE28
    if (ctx->r7 == 0) {
        // 0x800ACE10: nop
    
            goto L_800ACE28;
    }
    // 0x800ACE10: nop

    // 0x800ACE14: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800ACE18: nop

    // 0x800ACE1C: lwc1        $f8, 0xD4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD4);
    // 0x800ACE20: nop

    // 0x800ACE24: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_800ACE28:
    // 0x800ACE28: b           L_800ACE38
    // 0x800ACE2C: nop

        goto L_800ACE38;
    // 0x800ACE2C: nop

L_800ACE30:
    // 0x800ACE30: b           L_800ACE48
    // 0x800ACE34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ACE48;
    // 0x800ACE34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800ACE38:
    // 0x800ACE38: b           L_800ACE48
    // 0x800ACE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ACE48;
    // 0x800ACE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ACE40: b           L_800ACE48
    // 0x800ACE44: nop

        goto L_800ACE48;
    // 0x800ACE44: nop

L_800ACE48:
    // 0x800ACE48: jr          $ra
    // 0x800ACE4C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800ACE4C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C055C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C055C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C0560: lw          $t6, 0x42C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X42C);
    // 0x800C0564: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0568: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800C056C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C0570: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C0574: sw          $a0, 0x228($at)
    MEM_W(0X228, ctx->r1) = ctx->r4;
    // 0x800C0578: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800C057C: lw          $t9, 0x42C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X42C);
    // 0x800C0580: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0584: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C0588: sw          $t0, 0x42C($at)
    MEM_W(0X42C, ctx->r1) = ctx->r8;
    // 0x800C058C: jr          $ra
    // 0x800C0590: nop

    return;
    // 0x800C0590: nop

    // 0x800C0594: jr          $ra
    // 0x800C0598: nop

    return;
    // 0x800C0598: nop

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
RECOMP_FUNC void func_80090E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090E58: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80090E5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80090E60: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80090E64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80090E68: jal         0x80090A7C
    // 0x80090E6C: nop

    func_80090A7C(rdram, ctx);
        goto after_0;
    // 0x80090E6C: nop

    after_0:
    // 0x80090E70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090E74: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80090E78: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090E7C: lwc1        $f6, -0x4510($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80090E80: nop

    // 0x80090E84: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80090E88: nop

    // 0x80090E8C: bc1f        L_80090EA0
    if (!c1cs) {
        // 0x80090E90: nop
    
            goto L_80090EA0;
    }
    // 0x80090E90: nop

    // 0x80090E94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090E98: b           L_80090EEC
    // 0x80090E9C: sw          $zero, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = 0;
        goto L_80090EEC;
    // 0x80090E9C: sw          $zero, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = 0;
L_80090EA0:
    // 0x80090EA0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80090EA4: lw          $t6, 0x61CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X61CC);
    // 0x80090EA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090EAC: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80090EB0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80090EB4: lwc1        $f16, -0x4510($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80090EB8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80090EBC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80090EC0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80090EC4: nop

    // 0x80090EC8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80090ECC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80090ED0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090ED4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090ED8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80090EDC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80090EE0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80090EE4: sw          $t9, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = ctx->r25;
    // 0x80090EE8: nop

L_80090EEC:
    // 0x80090EEC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80090EF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80090EF4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80090EF8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80090EFC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80090F00: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80090F04: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80090F08: nop

    // 0x80090F0C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80090F10: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80090F14: nop

    // 0x80090F18: beq         $t3, $zero, L_800919AC
    if (ctx->r11 == 0) {
        // 0x80090F1C: nop
    
            goto L_800919AC;
    }
    // 0x80090F1C: nop

L_80090F20:
    // 0x80090F20: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80090F24: nop

    // 0x80090F28: beq         $t4, $zero, L_80090FD8
    if (ctx->r12 == 0) {
        // 0x80090F2C: nop
    
            goto L_80090FD8;
    }
    // 0x80090F2C: nop

    // 0x80090F30: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80090F34: lh          $t5, -0x4CC8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4CC8);
    // 0x80090F38: nop

    // 0x80090F3C: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x80090F40: beq         $t6, $zero, L_80090FD8
    if (ctx->r14 == 0) {
        // 0x80090F44: nop
    
            goto L_80090FD8;
    }
    // 0x80090F44: nop

    // 0x80090F48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090F4C: lwc1        $f6, -0x44D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X44D0);
    // 0x80090F50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80090F54: nop

    // 0x80090F58: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80090F5C: nop

    // 0x80090F60: bc1f        L_80090FAC
    if (!c1cs) {
        // 0x80090F64: nop
    
            goto L_80090FAC;
    }
    // 0x80090F64: nop

    // 0x80090F68: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80090F6C: nop

    // 0x80090F70: bne         $t7, $zero, L_80090FA4
    if (ctx->r15 != 0) {
        // 0x80090F74: nop
    
            goto L_80090FA4;
    }
    // 0x80090F74: nop

    // 0x80090F78: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090F7C: lwc1        $f10, -0x44D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X44D0);
    // 0x80090F80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80090F84: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80090F88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090F8C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80090F90: swc1        $f18, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f18.u32l;
    // 0x80090F94: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80090F98: nop

    // 0x80090F9C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80090FA0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_80090FA4:
    // 0x80090FA4: b           L_800919AC
    // 0x80090FA8: nop

        goto L_800919AC;
    // 0x80090FA8: nop

L_80090FAC:
    // 0x80090FAC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090FB0: lhu         $t0, -0x44C0($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44C0);
    // 0x80090FB4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80090FB8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80090FBC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80090FC0: lh          $t2, -0x3AB8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X3AB8);
    // 0x80090FC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090FC8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80090FCC: nop

    // 0x80090FD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090FD4: swc1        $f6, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f6.u32l;
L_80090FD8:
    // 0x80090FD8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80090FDC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80090FE0: nop

    // 0x80090FE4: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80090FE8: nop

    // 0x80090FEC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80090FF0: sltiu       $at, $t5, 0xD
    ctx->r1 = ctx->r13 < 0XD ? 1 : 0;
    // 0x80090FF4: beq         $at, $zero, L_800912DC
    if (ctx->r1 == 0) {
        // 0x80090FF8: nop
    
            goto L_800912DC;
    }
    // 0x80090FF8: nop

    // 0x80090FFC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80091000: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80091004: addu        $at, $at, $t5
    gpr jr_addend_80091010 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80091008: lw          $t5, -0x8A8($at)
    ctx->r13 = ADD32(ctx->r1, -0X8A8);
    // 0x8009100C: nop

    // 0x80091010: jr          $t5
    // 0x80091014: nop

    switch (jr_addend_80091010 >> 2) {
        case 0: goto L_8009113C; break;
        case 1: goto L_80091168; break;
        case 2: goto L_80091194; break;
        case 3: goto L_800911C0; break;
        case 4: goto L_800911EC; break;
        case 5: goto L_8009125C; break;
        case 6: goto L_800912DC; break;
        case 7: goto L_800912DC; break;
        case 8: goto L_800910A0; break;
        case 9: goto L_80091028; break;
        case 10: goto L_800912DC; break;
        case 11: goto L_800912DC; break;
        case 12: goto L_80091018; break;
        default: switch_error(__func__, 0x80091010, 0x800EF758);
    }
    // 0x80091014: nop

L_80091018:
    // 0x80091018: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009101C: sw          $zero, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = 0;
    // 0x80091020: b           L_80091964
    // 0x80091024: nop

        goto L_80091964;
    // 0x80091024: nop

L_80091028:
    // 0x80091028: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8009102C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80091030: lw          $t7, 0x61D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X61D4);
    // 0x80091034: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x80091038: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009103C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80091040: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x80091044: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091048: sw          $zero, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = 0;
    // 0x8009104C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80091050: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091054: lwc1        $f8, -0x4534($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x80091058: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8009105C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80091060: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80091064: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80091068: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009106C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80091070: lw          $t2, 0x61D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X61D4);
    // 0x80091074: lw          $t1, 0x6BA0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6BA0);
    // 0x80091078: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8009107C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80091080: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80091084: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80091088: beq         $at, $zero, L_80091098
    if (ctx->r1 == 0) {
        // 0x8009108C: nop
    
            goto L_80091098;
    }
    // 0x8009108C: nop

    // 0x80091090: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091094: sw          $zero, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = 0;
L_80091098:
    // 0x80091098: b           L_80091964
    // 0x8009109C: nop

        goto L_80091964;
    // 0x8009109C: nop

L_800910A0:
    // 0x800910A0: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800910A4: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800910A8: lw          $t5, 0x61CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X61CC);
    // 0x800910AC: lw          $t4, 0x6B98($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6B98);
    // 0x800910B0: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800910B4: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x800910B8: lw          $t7, 0x6BA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA8);
    // 0x800910BC: bne         $t5, $zero, L_800910C8
    if (ctx->r13 != 0) {
        // 0x800910C0: nop
    
            goto L_800910C8;
    }
    // 0x800910C0: nop

    // 0x800910C4: break       7
    do_break(2148077764);
L_800910C8:
    // 0x800910C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800910CC: bne         $t5, $at, L_800910E0
    if (ctx->r13 != ctx->r1) {
        // 0x800910D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800910E0;
    }
    // 0x800910D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800910D4: bne         $t4, $at, L_800910E0
    if (ctx->r12 != ctx->r1) {
        // 0x800910D8: nop
    
            goto L_800910E0;
    }
    // 0x800910D8: nop

    // 0x800910DC: break       6
    do_break(2148077788);
L_800910E0:
    // 0x800910E0: mflo        $t6
    ctx->r14 = lo;
    // 0x800910E4: nop

    // 0x800910E8: nop

    // 0x800910EC: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x800910F0: bne         $t7, $zero, L_800910FC
    if (ctx->r15 != 0) {
        // 0x800910F4: nop
    
            goto L_800910FC;
    }
    // 0x800910F4: nop

    // 0x800910F8: break       7
    do_break(2148077816);
L_800910FC:
    // 0x800910FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80091100: bne         $t7, $at, L_80091114
    if (ctx->r15 != ctx->r1) {
        // 0x80091104: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80091114;
    }
    // 0x80091104: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80091108: bne         $t6, $at, L_80091114
    if (ctx->r14 != ctx->r1) {
        // 0x8009110C: nop
    
            goto L_80091114;
    }
    // 0x8009110C: nop

    // 0x80091110: break       6
    do_break(2148077840);
L_80091114:
    // 0x80091114: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091118: mfhi        $t8
    ctx->r24 = hi;
    // 0x8009111C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80091120: nop

    // 0x80091124: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091128: mflo        $t1
    ctx->r9 = lo;
    // 0x8009112C: addu        $t2, $t4, $t1
    ctx->r10 = ADD32(ctx->r12, ctx->r9);
    // 0x80091130: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x80091134: b           L_80091964
    // 0x80091138: nop

        goto L_80091964;
    // 0x80091138: nop

L_8009113C:
    // 0x8009113C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80091140: nop

    // 0x80091144: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80091148: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8009114C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80091150: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091154: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80091158: nop

    // 0x8009115C: sw          $t7, 0x6BA8($at)
    MEM_W(0X6BA8, ctx->r1) = ctx->r15;
    // 0x80091160: b           L_80091964
    // 0x80091164: nop

        goto L_80091964;
    // 0x80091164: nop

L_80091168:
    // 0x80091168: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8009116C: nop

    // 0x80091170: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80091174: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80091178: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8009117C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091180: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x80091184: nop

    // 0x80091188: sw          $t4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r12;
    // 0x8009118C: b           L_80091964
    // 0x80091190: nop

        goto L_80091964;
    // 0x80091190: nop

L_80091194:
    // 0x80091194: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80091198: nop

    // 0x8009119C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800911A0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800911A4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800911A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800911AC: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x800911B0: nop

    // 0x800911B4: sw          $t3, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r11;
    // 0x800911B8: b           L_80091964
    // 0x800911BC: nop

        goto L_80091964;
    // 0x800911BC: nop

L_800911C0:
    // 0x800911C0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800911C4: nop

    // 0x800911C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800911CC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800911D0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800911D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800911D8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800911DC: nop

    // 0x800911E0: sw          $t9, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r25;
    // 0x800911E4: b           L_80091964
    // 0x800911E8: nop

        goto L_80091964;
    // 0x800911E8: nop

L_800911EC:
    // 0x800911EC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800911F0: nop

    // 0x800911F4: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800911F8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800911FC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80091200: nop

    // 0x80091204: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80091208: nop

    // 0x8009120C: sll         $t0, $t2, 8
    ctx->r8 = S32(ctx->r10 << 8);
    // 0x80091210: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
    // 0x80091214: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80091218: nop

    // 0x8009121C: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80091220: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80091224: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80091228: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x8009122C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80091230: nop

    // 0x80091234: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x80091238: sh          $t5, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r13;
    // 0x8009123C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80091240: lh          $t4, -0x4CC8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CC8);
    // 0x80091244: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x80091248: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009124C: or          $t2, $t4, $t1
    ctx->r10 = ctx->r12 | ctx->r9;
    // 0x80091250: sh          $t2, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = ctx->r10;
    // 0x80091254: b           L_80091964
    // 0x80091258: nop

        goto L_80091964;
    // 0x80091258: nop

L_8009125C:
    // 0x8009125C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80091260: nop

    // 0x80091264: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80091268: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8009126C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80091270: nop

    // 0x80091274: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80091278: nop

    // 0x8009127C: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80091280: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x80091284: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80091288: nop

    // 0x8009128C: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x80091290: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80091294: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80091298: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8009129C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800912A0: nop

    // 0x800912A4: or          $t0, $t4, $t2
    ctx->r8 = ctx->r12 | ctx->r10;
    // 0x800912A8: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
    // 0x800912AC: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x800912B0: nop

    // 0x800912B4: xori        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 ^ 0XFFFF;
    // 0x800912B8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x800912BC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800912C0: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x800912C4: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x800912C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800912CC: and         $t9, $t8, $t7
    ctx->r25 = ctx->r24 & ctx->r15;
    // 0x800912D0: sh          $t9, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = ctx->r25;
    // 0x800912D4: b           L_80091964
    // 0x800912D8: nop

        goto L_80091964;
    // 0x800912D8: nop

L_800912DC:
    // 0x800912DC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800912E0: nop

    // 0x800912E4: lbu         $t1, 0x0($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X0);
    // 0x800912E8: nop

    // 0x800912EC: slti        $at, $t1, 0xE1
    ctx->r1 = SIGNED(ctx->r9) < 0XE1 ? 1 : 0;
    // 0x800912F0: bne         $at, $zero, L_80091378
    if (ctx->r1 != 0) {
        // 0x800912F4: nop
    
            goto L_80091378;
    }
    // 0x800912F4: nop

    // 0x800912F8: slti        $at, $t1, 0xE2
    ctx->r1 = SIGNED(ctx->r9) < 0XE2 ? 1 : 0;
    // 0x800912FC: beq         $at, $zero, L_80091378
    if (ctx->r1 == 0) {
        // 0x80091300: nop
    
            goto L_80091378;
    }
    // 0x80091300: nop

    // 0x80091304: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80091308: nop

    // 0x8009130C: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80091310: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80091314: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80091318: nop

    // 0x8009131C: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x80091320: nop

    // 0x80091324: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x80091328: sh          $t6, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r14;
    // 0x8009132C: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x80091330: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80091334: bne         $t8, $at, L_8009134C
    if (ctx->r24 != ctx->r1) {
        // 0x80091338: nop
    
            goto L_8009134C;
    }
    // 0x80091338: nop

    // 0x8009133C: jal         0x80096250
    // 0x80091340: nop

    func_80096250(rdram, ctx);
        goto after_1;
    // 0x80091340: nop

    after_1:
    // 0x80091344: b           L_80091964
    // 0x80091348: nop

        goto L_80091964;
    // 0x80091348: nop

L_8009134C:
    // 0x8009134C: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x80091350: nop

    // 0x80091354: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80091358: sh          $t9, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r25;
    // 0x8009135C: lhu         $a0, 0x24($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X24);
    // 0x80091360: jal         0x80096198
    // 0x80091364: nop

    func_80096198(rdram, ctx);
        goto after_2;
    // 0x80091364: nop

    after_2:
    // 0x80091368: b           L_80091964
    // 0x8009136C: nop

        goto L_80091964;
    // 0x8009136C: nop

    // 0x80091370: b           L_8009153C
    // 0x80091374: nop

        goto L_8009153C;
    // 0x80091374: nop

L_80091378:
    // 0x80091378: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8009137C: nop

    // 0x80091380: lbu         $t1, 0x0($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X0);
    // 0x80091384: nop

    // 0x80091388: slti        $at, $t1, 0xE2
    ctx->r1 = SIGNED(ctx->r9) < 0XE2 ? 1 : 0;
    // 0x8009138C: bne         $at, $zero, L_8009153C
    if (ctx->r1 != 0) {
        // 0x80091390: nop
    
            goto L_8009153C;
    }
    // 0x80091390: nop

    // 0x80091394: slti        $at, $t1, 0xF0
    ctx->r1 = SIGNED(ctx->r9) < 0XF0 ? 1 : 0;
    // 0x80091398: beq         $at, $zero, L_8009153C
    if (ctx->r1 == 0) {
        // 0x8009139C: nop
    
            goto L_8009153C;
    }
    // 0x8009139C: nop

    // 0x800913A0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800913A4: nop

    // 0x800913A8: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x800913AC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800913B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800913B4: nop

    // 0x800913B8: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x800913BC: nop

    // 0x800913C0: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x800913C4: sh          $t6, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r14;
    // 0x800913C8: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x800913CC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800913D0: bne         $t8, $at, L_800913E8
    if (ctx->r24 != ctx->r1) {
        // 0x800913D4: nop
    
            goto L_800913E8;
    }
    // 0x800913D4: nop

    // 0x800913D8: jal         0x80090DC0
    // 0x800913DC: nop

    func_80090DC0(rdram, ctx);
        goto after_3;
    // 0x800913DC: nop

    after_3:
    // 0x800913E0: b           L_80091964
    // 0x800913E4: nop

        goto L_80091964;
    // 0x800913E4: nop

L_800913E8:
    // 0x800913E8: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x800913EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800913F0: bne         $t7, $at, L_8009141C
    if (ctx->r15 != ctx->r1) {
        // 0x800913F4: nop
    
            goto L_8009141C;
    }
    // 0x800913F4: nop

    // 0x800913F8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800913FC: lh          $t9, -0x4CC8($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4CC8);
    // 0x80091400: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091404: xori        $t5, $t9, 0x100
    ctx->r13 = ctx->r25 ^ 0X100;
    // 0x80091408: sh          $t5, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = ctx->r13;
    // 0x8009140C: jal         0x80090A7C
    // 0x80091410: nop

    func_80090A7C(rdram, ctx);
        goto after_4;
    // 0x80091410: nop

    after_4:
    // 0x80091414: b           L_80091964
    // 0x80091418: nop

        goto L_80091964;
    // 0x80091418: nop

L_8009141C:
    // 0x8009141C: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x80091420: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80091424: bne         $t1, $at, L_800914B4
    if (ctx->r9 != ctx->r1) {
        // 0x80091428: nop
    
            goto L_800914B4;
    }
    // 0x80091428: nop

    // 0x8009142C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80091430: nop

    // 0x80091434: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80091438: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8009143C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80091440: nop

    // 0x80091444: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x80091448: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8009144C: andi        $t6, $t3, 0x7F
    ctx->r14 = ctx->r11 & 0X7F;
    // 0x80091450: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80091454: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80091458: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8009145C: nop

    // 0x80091460: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80091464: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80091468: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8009146C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80091470: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80091474: nop

    // 0x80091478: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x8009147C: addu        $t3, $t5, $t2
    ctx->r11 = ADD32(ctx->r13, ctx->r10);
    // 0x80091480: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80091484: lhu         $t0, 0x24($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X24);
    // 0x80091488: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8009148C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091490: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x80091494: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80091498: sh          $t6, -0x3AB8($at)
    MEM_H(-0X3AB8, ctx->r1) = ctx->r14;
    // 0x8009149C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800914A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800914A4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800914A8: nop

    // 0x800914AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800914B0: swc1        $f18, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f18.u32l;
L_800914B4:
    // 0x800914B4: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x800914B8: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800914BC: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800914C0: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x800914C4: lh          $t4, -0x39B8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X39B8);
    // 0x800914C8: nop

    // 0x800914CC: bne         $t4, $zero, L_800914E8
    if (ctx->r12 != 0) {
        // 0x800914D0: nop
    
            goto L_800914E8;
    }
    // 0x800914D0: nop

    // 0x800914D4: lhu         $a0, 0x24($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X24);
    // 0x800914D8: jal         0x80090C94
    // 0x800914DC: nop

    func_80090C94(rdram, ctx);
        goto after_5;
    // 0x800914DC: nop

    after_5:
    // 0x800914E0: b           L_800914F4
    // 0x800914E4: nop

        goto L_800914F4;
    // 0x800914E4: nop

L_800914E8:
    // 0x800914E8: lhu         $a0, 0x24($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X24);
    // 0x800914EC: jal         0x80090D34
    // 0x800914F0: nop

    func_80090D34(rdram, ctx);
        goto after_6;
    // 0x800914F0: nop

    after_6:
L_800914F4:
    // 0x800914F4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800914F8: lhu         $t5, -0x44C0($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X44C0);
    // 0x800914FC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80091500: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x80091504: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80091508: lh          $t3, -0x3AB8($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X3AB8);
    // 0x8009150C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091510: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80091514: nop

    // 0x80091518: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009151C: swc1        $f6, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f6.u32l;
    // 0x80091520: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80091524: nop

    // 0x80091528: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x8009152C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80091530: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80091534: b           L_80091964
    // 0x80091538: nop

        goto L_80091964;
    // 0x80091538: nop

L_8009153C:
    // 0x8009153C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80091540: nop

    // 0x80091544: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80091548: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8009154C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80091550: nop

    // 0x80091554: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x80091558: nop

    // 0x8009155C: slti        $at, $t1, 0x80
    ctx->r1 = SIGNED(ctx->r9) < 0X80 ? 1 : 0;
    // 0x80091560: beq         $at, $zero, L_8009164C
    if (ctx->r1 == 0) {
        // 0x80091564: nop
    
            goto L_8009164C;
    }
    // 0x80091564: nop

    // 0x80091568: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8009156C: nop

    // 0x80091570: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80091574: nop

    // 0x80091578: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8009157C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80091580: nop

    // 0x80091584: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x80091588: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8009158C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80091590: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x80091594: nop

    // 0x80091598: andi        $t6, $t0, 0x20
    ctx->r14 = ctx->r8 & 0X20;
    // 0x8009159C: beq         $t6, $zero, L_80091644
    if (ctx->r14 == 0) {
        // 0x800915A0: nop
    
            goto L_80091644;
    }
    // 0x800915A0: nop

    // 0x800915A4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800915A8: nop

    // 0x800915AC: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800915B0: nop

    // 0x800915B4: slti        $at, $t7, 0x41
    ctx->r1 = SIGNED(ctx->r15) < 0X41 ? 1 : 0;
    // 0x800915B8: beq         $at, $zero, L_800915FC
    if (ctx->r1 == 0) {
        // 0x800915BC: nop
    
            goto L_800915FC;
    }
    // 0x800915BC: nop

    // 0x800915C0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800915C4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800915C8: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x800915CC: addiu       $t2, $t2, 0x4C60
    ctx->r10 = ADD32(ctx->r10, 0X4C60);
    // 0x800915D0: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x800915D4: addiu       $t5, $t4, -0x40
    ctx->r13 = ADD32(ctx->r12, -0X40);
    // 0x800915D8: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    // 0x800915DC: jal         0x80095E78
    // 0x800915E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_7;
    // 0x800915E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800915E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800915E8: jal         0x80095F9C
    // 0x800915EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_8;
    // 0x800915EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800915F0: andi        $t3, $v0, 0x7FFF
    ctx->r11 = ctx->r2 & 0X7FFF;
    // 0x800915F4: b           L_80091644
    // 0x800915F8: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
        goto L_80091644;
    // 0x800915F8: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_800915FC:
    // 0x800915FC: addiu       $t0, $zero, 0xA3
    ctx->r8 = ADD32(0, 0XA3);
    // 0x80091600: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80091604: sb          $t0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r8;
    // 0x80091608: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8009160C: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x80091610: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x80091614: nop

    // 0x80091618: andi        $t9, $t7, 0x7F
    ctx->r25 = ctx->r15 & 0X7F;
    // 0x8009161C: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x80091620: sb          $t1, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r9;
    // 0x80091624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80091628: jal         0x80095E78
    // 0x8009162C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80095E78(rdram, ctx);
        goto after_9;
    // 0x8009162C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
    // 0x80091630: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80091634: jal         0x80095F9C
    // 0x80091638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_10;
    // 0x80091638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8009163C: andi        $t5, $v0, 0x7FFF
    ctx->r13 = ctx->r2 & 0X7FFF;
    // 0x80091640: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
L_80091644:
    // 0x80091644: b           L_80091694
    // 0x80091648: nop

        goto L_80091694;
    // 0x80091648: nop

L_8009164C:
    // 0x8009164C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80091650: nop

    // 0x80091654: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80091658: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x8009165C: andi        $t0, $t3, 0x7F
    ctx->r8 = ctx->r11 & 0X7F;
    // 0x80091660: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80091664: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80091668: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8009166C: nop

    // 0x80091670: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80091674: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80091678: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8009167C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80091680: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x80091684: nop

    // 0x80091688: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8009168C: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x80091690: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_80091694:
    // 0x80091694: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80091698: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x8009169C: nop

    // 0x800916A0: andi        $t2, $t0, 0x200
    ctx->r10 = ctx->r8 & 0X200;
    // 0x800916A4: beq         $t2, $zero, L_8009179C
    if (ctx->r10 == 0) {
        // 0x800916A8: nop
    
            goto L_8009179C;
    }
    // 0x800916A8: nop

    // 0x800916AC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800916B0: nop

    // 0x800916B4: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x800916B8: bne         $at, $zero, L_80091778
    if (ctx->r1 != 0) {
        // 0x800916BC: nop
    
            goto L_80091778;
    }
    // 0x800916BC: nop

    // 0x800916C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800916C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800916C8: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800916CC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800916D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800916D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800916D8: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800916DC: lw          $t4, 0x61CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X61CC);
    // 0x800916E0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800916E4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800916E8: lw          $t1, 0x6B98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6B98);
    // 0x800916EC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800916F0: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x800916F4: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x800916F8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800916FC: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80091700: beq         $at, $zero, L_8009172C
    if (ctx->r1 == 0) {
        // 0x80091704: nop
    
            goto L_8009172C;
    }
    // 0x80091704: nop

    // 0x80091708: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8009170C: sw          $zero, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = 0;
    // 0x80091710: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80091714: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80091718: lw          $t0, 0x61D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X61D4);
    // 0x8009171C: lw          $t3, 0x6BA0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6BA0);
    // 0x80091720: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091724: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x80091728: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
L_8009172C:
    // 0x8009172C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80091730: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091734: lwc1        $f16, -0x4534($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x80091738: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8009173C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80091740: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80091744: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80091748: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8009174C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80091750: lw          $t1, 0x61D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X61D4);
    // 0x80091754: lw          $t4, 0x6BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA0);
    // 0x80091758: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8009175C: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x80091760: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80091764: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80091768: beq         $at, $zero, L_80091778
    if (ctx->r1 == 0) {
        // 0x8009176C: nop
    
            goto L_80091778;
    }
    // 0x8009176C: nop

    // 0x80091770: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091774: sw          $zero, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = 0;
L_80091778:
    // 0x80091778: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8009177C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80091780: lw          $a2, 0x61D4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X61D4);
    // 0x80091784: lw          $a1, 0x61CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X61CC);
    // 0x80091788: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8009178C: jal         0x80094230
    // 0x80091790: nop

    func_80094230(rdram, ctx);
        goto after_11;
    // 0x80091790: nop

    after_11:
    // 0x80091794: b           L_80091864
    // 0x80091798: nop

        goto L_80091864;
    // 0x80091798: nop

L_8009179C:
    // 0x8009179C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800917A0: lh          $t7, -0x4CC8($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4CC8);
    // 0x800917A4: nop

    // 0x800917A8: andi        $t5, $t7, 0x40
    ctx->r13 = ctx->r15 & 0X40;
    // 0x800917AC: beq         $t5, $zero, L_800917D0
    if (ctx->r13 == 0) {
        // 0x800917B0: nop
    
            goto L_800917D0;
    }
    // 0x800917B0: nop

    // 0x800917B4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800917B8: lw          $a1, 0x61CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X61CC);
    // 0x800917BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800917C0: jal         0x80093B30
    // 0x800917C4: nop

    func_80093B30(rdram, ctx);
        goto after_12;
    // 0x800917C4: nop

    after_12:
    // 0x800917C8: b           L_80091864
    // 0x800917CC: nop

        goto L_80091864;
    // 0x800917CC: nop

L_800917D0:
    // 0x800917D0: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800917D4: lh          $t3, -0x4CC8($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4CC8);
    // 0x800917D8: nop

    // 0x800917DC: andi        $t0, $t3, 0x10
    ctx->r8 = ctx->r11 & 0X10;
    // 0x800917E0: beq         $t0, $zero, L_80091804
    if (ctx->r8 == 0) {
        // 0x800917E4: nop
    
            goto L_80091804;
    }
    // 0x800917E4: nop

    // 0x800917E8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800917EC: lw          $a1, 0x61CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X61CC);
    // 0x800917F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800917F4: jal         0x80091E34
    // 0x800917F8: nop

    func_80091E34(rdram, ctx);
        goto after_13;
    // 0x800917F8: nop

    after_13:
    // 0x800917FC: b           L_80091864
    // 0x80091800: nop

        goto L_80091864;
    // 0x80091800: nop

L_80091804:
    // 0x80091804: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80091808: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x8009180C: nop

    // 0x80091810: andi        $t6, $t2, 0x20
    ctx->r14 = ctx->r10 & 0X20;
    // 0x80091814: beq         $t6, $zero, L_80091850
    if (ctx->r14 == 0) {
        // 0x80091818: nop
    
            goto L_80091850;
    }
    // 0x80091818: nop

    // 0x8009181C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80091820: lw          $a1, 0x61CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X61CC);
    // 0x80091824: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80091828: lw          $a2, 0x61D4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X61D4);
    // 0x8009182C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80091830: bgez        $a1, L_80091840
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80091834: sra         $t4, $a1, 1
        ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80091840;
    }
    // 0x80091834: sra         $t4, $a1, 1
    ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80091838: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8009183C: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80091840:
    // 0x80091840: jal         0x80094230
    // 0x80091844: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    func_80094230(rdram, ctx);
        goto after_14;
    // 0x80091844: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_14:
    // 0x80091848: b           L_80091864
    // 0x8009184C: nop

        goto L_80091864;
    // 0x8009184C: nop

L_80091850:
    // 0x80091850: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80091854: lw          $a1, 0x61CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X61CC);
    // 0x80091858: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8009185C: jal         0x80091A04
    // 0x80091860: nop

    func_80091A04(rdram, ctx);
        goto after_15;
    // 0x80091860: nop

    after_15:
L_80091864:
    // 0x80091864: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80091868: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009186C: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80091870: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80091874: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80091878: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009187C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80091880: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80091884: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80091888: lw          $t7, 0x61CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X61CC);
    // 0x8009188C: lw          $t9, 0x6B98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6B98);
    // 0x80091890: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80091894: addu        $t5, $t9, $t7
    ctx->r13 = ADD32(ctx->r25, ctx->r15);
    // 0x80091898: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009189C: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800918A0: beq         $at, $zero, L_80091910
    if (ctx->r1 == 0) {
        // 0x800918A4: nop
    
            goto L_80091910;
    }
    // 0x800918A4: nop

    // 0x800918A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800918AC: sw          $zero, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = 0;
    // 0x800918B0: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800918B4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800918B8: lw          $t0, 0x61D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X61D4);
    // 0x800918BC: lw          $t3, 0x6BA0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6BA0);
    // 0x800918C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800918C4: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x800918C8: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x800918CC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800918D0: nop

    // 0x800918D4: lbu         $t4, 0x1($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X1);
    // 0x800918D8: nop

    // 0x800918DC: xori        $t1, $t4, 0xA
    ctx->r9 = ctx->r12 ^ 0XA;
    // 0x800918E0: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x800918E4: bne         $t1, $zero, L_80091900
    if (ctx->r9 != 0) {
        // 0x800918E8: nop
    
            goto L_80091900;
    }
    // 0x800918E8: nop

    // 0x800918EC: bne         $t1, $zero, L_80091900
    if (ctx->r9 != 0) {
        // 0x800918F0: nop
    
            goto L_80091900;
    }
    // 0x800918F0: nop

    // 0x800918F4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800918F8: bne         $t4, $at, L_80091910
    if (ctx->r12 != ctx->r1) {
        // 0x800918FC: nop
    
            goto L_80091910;
    }
    // 0x800918FC: nop

L_80091900:
    // 0x80091900: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80091904: nop

    // 0x80091908: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8009190C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80091910:
    // 0x80091910: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80091914: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091918: lwc1        $f8, -0x4534($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x8009191C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80091920: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80091924: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80091928: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8009192C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80091930: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80091934: lw          $t0, 0x61D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X61D4);
    // 0x80091938: lw          $t3, 0x6BA0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6BA0);
    // 0x8009193C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80091940: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x80091944: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80091948: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009194C: beq         $at, $zero, L_8009195C
    if (ctx->r1 == 0) {
        // 0x80091950: nop
    
            goto L_8009195C;
    }
    // 0x80091950: nop

    // 0x80091954: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091958: sw          $zero, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = 0;
L_8009195C:
    // 0x8009195C: b           L_80091964
    // 0x80091960: nop

        goto L_80091964;
    // 0x80091960: nop

L_80091964:
    // 0x80091964: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80091968: nop

    // 0x8009196C: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x80091970: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80091974: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80091978: lhu         $t4, -0x44C0($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X44C0);
    // 0x8009197C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091980: bne         $t4, $at, L_8009198C
    if (ctx->r12 != ctx->r1) {
        // 0x80091984: nop
    
            goto L_8009198C;
    }
    // 0x80091984: nop

    // 0x80091988: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8009198C:
    // 0x8009198C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80091990: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80091994: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80091998: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8009199C: lbu         $t3, 0x0($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X0);
    // 0x800919A0: nop

    // 0x800919A4: bne         $t3, $zero, L_80090F20
    if (ctx->r11 != 0) {
        // 0x800919A8: nop
    
            goto L_80090F20;
    }
    // 0x800919A8: nop

L_800919AC:
    // 0x800919AC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800919B0: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800919B4: nop

    // 0x800919B8: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x800919BC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800919C0: nop

    // 0x800919C4: lbu         $t6, 0x0($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X0);
    // 0x800919C8: nop

    // 0x800919CC: bne         $t6, $zero, L_800919E0
    if (ctx->r14 != 0) {
        // 0x800919D0: nop
    
            goto L_800919E0;
    }
    // 0x800919D0: nop

    // 0x800919D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800919D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800919DC: swc1        $f16, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f16.u32l;
L_800919E0:
    // 0x800919E0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800919E4: b           L_800919F4
    // 0x800919E8: nop

        goto L_800919F4;
    // 0x800919E8: nop

    // 0x800919EC: b           L_800919F4
    // 0x800919F0: nop

        goto L_800919F4;
    // 0x800919F0: nop

L_800919F4:
    // 0x800919F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800919F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800919FC: jr          $ra
    // 0x80091A00: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80091A00: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80063E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063E1C: jal         0x80061348
    // 0x80063E20: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80063E20: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_0:
    // 0x80063E24: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063E28: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063E2C: bne         $v0, $zero, L_80063E44
    if (ctx->r2 != 0) {
        // 0x80063E30: nop
    
            goto L_80063E44;
    }
    // 0x80063E30: nop

    // 0x80063E34: jal         0x80061348
    // 0x80063E38: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80063E38: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_1:
    // 0x80063E3C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063E40: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80063E44:
    // 0x80063E44: b           L_80063E54
    // 0x80063E48: nop

        goto L_80063E54;
    // 0x80063E48: nop

    // 0x80063E4C: b           L_80063E54
    // 0x80063E50: nop

        goto L_80063E54;
    // 0x80063E50: nop

L_80063E54:
    // 0x80063E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063E5C: jr          $ra
    // 0x80063E60: nop

    return;
    // 0x80063E60: nop

;}
RECOMP_FUNC void func_8000FCD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FCD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000FCDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FCE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000FCE4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000FCE8: jal         0x8000FE48
    // 0x8000FCEC: nop

    func_8000FE48(rdram, ctx);
        goto after_0;
    // 0x8000FCEC: nop

    after_0:
    // 0x8000FCF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000FCF4: nop

    // 0x8000FCF8: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000FCFC: nop

    // 0x8000FD00: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8000FD04: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000FD08: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000FD0C: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000FD10: nop

    // 0x8000FD14: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000FD18: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x8000FD1C: nop

    // 0x8000FD20: blez        $t0, L_8000FE30
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000FD24: nop
    
            goto L_8000FE30;
    }
    // 0x8000FD24: nop

L_8000FD28:
    // 0x8000FD28: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000FD2C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000FD30: lwc1        $f4, 0x18($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X18);
    // 0x8000FD34: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000FD38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FD3C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000FD40: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8000FD44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FD48: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FD4C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FD50: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8000FD54: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8000FD58: lwc1        $f6, 0xE8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x8000FD5C: nop

    // 0x8000FD60: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000FD64: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x8000FD68: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8000FD6C: swc1        $f10, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f10.u32l;
    // 0x8000FD70: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8000FD74: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000FD78: lwc1        $f18, 0x1C($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8000FD7C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000FD80: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FD84: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8000FD88: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8000FD8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FD90: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FD94: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FD98: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8000FD9C: mul.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x8000FDA0: lwc1        $f6, 0xEC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XEC);
    // 0x8000FDA4: nop

    // 0x8000FDA8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000FDAC: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x8000FDB0: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8000FDB4: swc1        $f4, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f4.u32l;
    // 0x8000FDB8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8000FDBC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000FDC0: lwc1        $f10, 0x20($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8000FDC4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000FDC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FDCC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8000FDD0: mul.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8000FDD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FDD8: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FDDC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FDE0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8000FDE4: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8000FDE8: lwc1        $f6, 0xF0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XF0);
    // 0x8000FDEC: nop

    // 0x8000FDF0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000FDF4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8000FDF8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8000FDFC: swc1        $f18, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f18.u32l;
    // 0x8000FE00: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000FE04: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FE08: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000FE0C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000FE10: addiu       $t0, $t8, 0x160
    ctx->r8 = ADD32(ctx->r24, 0X160);
    // 0x8000FE14: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8000FE18: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8000FE1C: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8000FE20: nop

    // 0x8000FE24: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000FE28: bne         $at, $zero, L_8000FD28
    if (ctx->r1 != 0) {
        // 0x8000FE2C: nop
    
            goto L_8000FD28;
    }
    // 0x8000FE2C: nop

L_8000FE30:
    // 0x8000FE30: b           L_8000FE38
    // 0x8000FE34: nop

        goto L_8000FE38;
    // 0x8000FE34: nop

L_8000FE38:
    // 0x8000FE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FE3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000FE40: jr          $ra
    // 0x8000FE44: nop

    return;
    // 0x8000FE44: nop

;}
RECOMP_FUNC void _ldexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1020: beq         $a2, $zero, L_800D1040
    if (ctx->r6 == 0) {
        // 0x800D1024: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800D1040;
    }
    // 0x800D1024: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D1028: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x800D102C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800D1030: nop

    // 0x800D1034: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800D1038: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x800D103C: nop

L_800D1040:
    // 0x800D1040: jr          $ra
    // 0x800D1044: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x800D1044: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
;}
RECOMP_FUNC void func_8006721C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006721C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067224: jal         0x80061488
    // 0x80067228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8006722C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067230: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067234: b           L_80067244
    // 0x80067238: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067244;
    // 0x80067238: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006723C: b           L_80067244
    // 0x80067240: nop

        goto L_80067244;
    // 0x80067240: nop

L_80067244:
    // 0x80067244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006724C: jr          $ra
    // 0x80067250: nop

    return;
    // 0x80067250: nop

;}
RECOMP_FUNC void func_8006BE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BE80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BE84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BE88: jal         0x8005F064
    // 0x8006BE8C: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BE8C: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_0:
    // 0x8006BE90: b           L_8006BEA0
    // 0x8006BE94: nop

        goto L_8006BEA0;
    // 0x8006BE94: nop

    // 0x8006BE98: b           L_8006BEA0
    // 0x8006BE9C: nop

        goto L_8006BEA0;
    // 0x8006BE9C: nop

L_8006BEA0:
    // 0x8006BEA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BEA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BEA8: jr          $ra
    // 0x8006BEAC: nop

    return;
    // 0x8006BEAC: nop

;}
RECOMP_FUNC void func_800770A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800770A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800770A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800770A8: jal         0x8005F064
    // 0x800770AC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800770AC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_0:
    // 0x800770B0: b           L_800770C0
    // 0x800770B4: nop

        goto L_800770C0;
    // 0x800770B4: nop

    // 0x800770B8: b           L_800770C0
    // 0x800770BC: nop

        goto L_800770C0;
    // 0x800770BC: nop

L_800770C0:
    // 0x800770C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800770C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800770C8: jr          $ra
    // 0x800770CC: nop

    return;
    // 0x800770CC: nop

;}
RECOMP_FUNC void func_80073594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007359C: jal         0x8005F064
    // 0x800735A0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800735A0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_0:
    // 0x800735A4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800735A8: b           L_800735B8
    // 0x800735AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800735B8;
    // 0x800735AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800735B0: b           L_800735B8
    // 0x800735B4: nop

        goto L_800735B8;
    // 0x800735B4: nop

L_800735B8:
    // 0x800735B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800735BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800735C0: jr          $ra
    // 0x800735C4: nop

    return;
    // 0x800735C4: nop

;}
RECOMP_FUNC void func_800A424C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A424C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A4250: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x800A4254: ori         $t6, $t6, 0x4000
    ctx->r14 = ctx->r14 | 0X4000;
    // 0x800A4258: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
    // 0x800A425C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800A4260: sh          $t7, 0xC4($a0)
    MEM_H(0XC4, ctx->r4) = ctx->r15;
    // 0x800A4264: sw          $a1, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->r5;
    // 0x800A4268: sw          $zero, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = 0;
    // 0x800A426C: sh          $zero, 0xD0($a0)
    MEM_H(0XD0, ctx->r4) = 0;
    // 0x800A4270: lh          $a2, 0xD0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0XD0);
    // 0x800A4274: nop

    // 0x800A4278: sh          $a2, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r6;
    // 0x800A427C: sh          $a2, 0xCC($a0)
    MEM_H(0XCC, ctx->r4) = ctx->r6;
    // 0x800A4280: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A4284: sh          $t8, 0xD2($a0)
    MEM_H(0XD2, ctx->r4) = ctx->r24;
    // 0x800A4288: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800A428C:
    // 0x800A428C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A4290: nop

    // 0x800A4294: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800A4298: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800A429C: sw          $zero, 0xE0($t1)
    MEM_W(0XE0, ctx->r9) = 0;
    // 0x800A42A0: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A42A4: nop

    // 0x800A42A8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800A42AC: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x800A42B0: bne         $at, $zero, L_800A428C
    if (ctx->r1 != 0) {
        // 0x800A42B4: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_800A428C;
    }
    // 0x800A42B4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800A42B8: b           L_800A42C0
    // 0x800A42BC: nop

        goto L_800A42C0;
    // 0x800A42BC: nop

L_800A42C0:
    // 0x800A42C0: jr          $ra
    // 0x800A42C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A42C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8002BD8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BD8C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BD90: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BD94: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8002BD98: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8002BD9C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002BDA0: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BDA4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8002BDA8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8002BDAC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8002BDB0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002BDB4: lh          $t9, -0x4574($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4574);
    // 0x8002BDB8: nop

    // 0x8002BDBC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002BDC0: nop

    // 0x8002BDC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002BDC8: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8002BDCC: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8002BDD0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8002BDD4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002BDD8: lh          $t1, -0x4572($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4572);
    // 0x8002BDDC: nop

    // 0x8002BDE0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8002BDE4: nop

    // 0x8002BDE8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002BDEC: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x8002BDF0: jr          $ra
    // 0x8002BDF4: nop

    return;
    // 0x8002BDF4: nop

    // 0x8002BDF8: jr          $ra
    // 0x8002BDFC: nop

    return;
    // 0x8002BDFC: nop

;}
RECOMP_FUNC void func_8006C5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C5D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C5D8: jal         0x8005F064
    // 0x8006C5DC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C5DC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x8006C5E0: b           L_8006C5F0
    // 0x8006C5E4: nop

        goto L_8006C5F0;
    // 0x8006C5E4: nop

    // 0x8006C5E8: b           L_8006C5F0
    // 0x8006C5EC: nop

        goto L_8006C5F0;
    // 0x8006C5EC: nop

L_8006C5F0:
    // 0x8006C5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C5F8: jr          $ra
    // 0x8006C5FC: nop

    return;
    // 0x8006C5FC: nop

;}
RECOMP_FUNC void func_80062818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006281C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062820: jal         0x8005F064
    // 0x80062824: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062824: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    after_0:
    // 0x80062828: b           L_80062838
    // 0x8006282C: nop

        goto L_80062838;
    // 0x8006282C: nop

    // 0x80062830: b           L_80062838
    // 0x80062834: nop

        goto L_80062838;
    // 0x80062834: nop

L_80062838:
    // 0x80062838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006283C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062840: jr          $ra
    // 0x80062844: nop

    return;
    // 0x80062844: nop

;}
RECOMP_FUNC void func_80070BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070BF0: jal         0x80061348
    // 0x80070BF4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070BF4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_0:
    // 0x80070BF8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070BFC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070C00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070C04: beq         $v0, $zero, L_80070C58
    if (ctx->r2 == 0) {
        // 0x80070C08: nop
    
            goto L_80070C58;
    }
    // 0x80070C08: nop

    // 0x80070C0C: jal         0x80061348
    // 0x80070C10: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070C10: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070C14: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070C18: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070C1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070C20: beq         $v0, $zero, L_80070C58
    if (ctx->r2 == 0) {
        // 0x80070C24: nop
    
            goto L_80070C58;
    }
    // 0x80070C24: nop

    // 0x80070C28: jal         0x80061348
    // 0x80070C2C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070C2C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070C30: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070C34: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070C38: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070C3C: beq         $v0, $zero, L_80070C58
    if (ctx->r2 == 0) {
        // 0x80070C40: nop
    
            goto L_80070C58;
    }
    // 0x80070C40: nop

    // 0x80070C44: jal         0x80061348
    // 0x80070C48: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070C48: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070C4C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070C50: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070C54: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070C58:
    // 0x80070C58: b           L_80070C68
    // 0x80070C5C: nop

        goto L_80070C68;
    // 0x80070C5C: nop

    // 0x80070C60: b           L_80070C68
    // 0x80070C64: nop

        goto L_80070C68;
    // 0x80070C64: nop

L_80070C68:
    // 0x80070C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070C6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070C70: jr          $ra
    // 0x80070C74: nop

    return;
    // 0x80070C74: nop

;}
RECOMP_FUNC void func_800620A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800620A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800620AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800620B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800620B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800620B8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800620BC: nop

    // 0x800620C0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800620C4: nop

    // 0x800620C8: beq         $t7, $zero, L_800620F8
    if (ctx->r15 == 0) {
        // 0x800620CC: nop
    
            goto L_800620F8;
    }
    // 0x800620CC: nop

    // 0x800620D0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800620D4: nop

    // 0x800620D8: lbu         $t1, 0x4($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X4);
    // 0x800620DC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800620E0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800620E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800620E8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800620EC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800620F0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800620F4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_800620F8:
    // 0x800620F8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800620FC: nop

    // 0x80062100: lh          $t5, 0xC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XC);
    // 0x80062104: nop

    // 0x80062108: beq         $t5, $zero, L_800625D8
    if (ctx->r13 == 0) {
        // 0x8006210C: nop
    
            goto L_800625D8;
    }
    // 0x8006210C: nop

    // 0x80062110: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80062114: nop

    // 0x80062118: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8006211C: nop

    // 0x80062120: beq         $t7, $zero, L_80062174
    if (ctx->r15 == 0) {
        // 0x80062124: nop
    
            goto L_80062174;
    }
    // 0x80062124: nop

    // 0x80062128: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8006212C: nop

    // 0x80062130: lw          $t9, 0x8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X8);
    // 0x80062134: nop

    // 0x80062138: jalr        $t9
    // 0x8006213C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8006213C: nop

    after_0:
    // 0x80062140: bne         $v0, $zero, L_80062174
    if (ctx->r2 != 0) {
        // 0x80062144: nop
    
            goto L_80062174;
    }
    // 0x80062144: nop

    // 0x80062148: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006214C: nop

    // 0x80062150: lbu         $v0, 0xE($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0XE);
    // 0x80062154: nop

    // 0x80062158: andi        $t1, $v0, 0x80
    ctx->r9 = ctx->r2 & 0X80;
    // 0x8006215C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80062160: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80062164: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80062168: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006216C: b           L_8006260C
    // 0x80062170: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8006260C;
    // 0x80062170: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80062174:
    // 0x80062174: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80062178: nop

    // 0x8006217C: lbu         $t4, 0xE($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XE);
    // 0x80062180: nop

    // 0x80062184: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x80062188: sltiu       $at, $t5, 0xA
    ctx->r1 = ctx->r13 < 0XA ? 1 : 0;
    // 0x8006218C: beq         $at, $zero, L_800625D8
    if (ctx->r1 == 0) {
        // 0x80062190: nop
    
            goto L_800625D8;
    }
    // 0x80062190: nop

    // 0x80062194: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80062198: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8006219C: addu        $at, $at, $t5
    gpr jr_addend_800621A8 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800621A0: lw          $t5, -0xE30($at)
    ctx->r13 = ADD32(ctx->r1, -0XE30);
    // 0x800621A4: nop

    // 0x800621A8: jr          $t5
    // 0x800621AC: nop

    switch (jr_addend_800621A8 >> 2) {
        case 0: goto L_800623F0; break;
        case 1: goto L_800621B0; break;
        case 2: goto L_8006228C; break;
        case 3: goto L_80062350; break;
        case 4: goto L_80062370; break;
        case 5: goto L_80062390; break;
        case 6: goto L_800623B0; break;
        case 7: goto L_800623D0; break;
        case 8: goto L_80062578; break;
        case 9: goto L_800625A8; break;
        default: switch_error(__func__, 0x800621A8, 0x800EF1D0);
    }
    // 0x800621AC: nop

L_800621B0:
    // 0x800621B0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800621B4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800621B8: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800621BC: lh          $t8, 0xC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0XC);
    // 0x800621C0: nop

    // 0x800621C4: bne         $t7, $t8, L_800621E4
    if (ctx->r15 != ctx->r24) {
        // 0x800621C8: nop
    
            goto L_800621E4;
    }
    // 0x800621C8: nop

    // 0x800621CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800621D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800621D4: jal         0x8006261C
    // 0x800621D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8006261C(rdram, ctx);
        goto after_1;
    // 0x800621D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800621DC: b           L_80062284
    // 0x800621E0: nop

        goto L_80062284;
    // 0x800621E0: nop

L_800621E4:
    // 0x800621E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800621E8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800621EC: lh          $t0, 0x2($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2);
    // 0x800621F0: lh          $t3, 0xC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XC);
    // 0x800621F4: nop

    // 0x800621F8: bne         $t0, $t3, L_8006221C
    if (ctx->r8 != ctx->r11) {
        // 0x800621FC: nop
    
            goto L_8006221C;
    }
    // 0x800621FC: nop

    // 0x80062200: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062204: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80062208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006220C: jal         0x8006261C
    // 0x80062210: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    func_8006261C(rdram, ctx);
        goto after_2;
    // 0x80062210: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_2:
    // 0x80062214: b           L_80062284
    // 0x80062218: nop

        goto L_80062284;
    // 0x80062218: nop

L_8006221C:
    // 0x8006221C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80062220: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80062224: lh          $t5, 0x4($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4);
    // 0x80062228: lh          $t9, 0xC($t6)
    ctx->r25 = MEM_H(ctx->r14, 0XC);
    // 0x8006222C: nop

    // 0x80062230: bne         $t5, $t9, L_80062254
    if (ctx->r13 != ctx->r25) {
        // 0x80062234: nop
    
            goto L_80062254;
    }
    // 0x80062234: nop

    // 0x80062238: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006223C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80062240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062244: jal         0x8006261C
    // 0x80062248: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8006261C(rdram, ctx);
        goto after_3;
    // 0x80062248: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x8006224C: b           L_80062284
    // 0x80062250: nop

        goto L_80062284;
    // 0x80062250: nop

L_80062254:
    // 0x80062254: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80062258: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8006225C: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80062260: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x80062264: nop

    // 0x80062268: bne         $t8, $t2, L_80062284
    if (ctx->r24 != ctx->r10) {
        // 0x8006226C: nop
    
            goto L_80062284;
    }
    // 0x8006226C: nop

    // 0x80062270: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062274: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80062278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006227C: jal         0x8006261C
    // 0x80062280: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    func_8006261C(rdram, ctx);
        goto after_4;
    // 0x80062280: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    after_4:
L_80062284:
    // 0x80062284: b           L_800625D8
    // 0x80062288: nop

        goto L_800625D8;
    // 0x80062288: nop

L_8006228C:
    // 0x8006228C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80062290: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80062294: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80062298: lh          $t6, 0xC($t4)
    ctx->r14 = MEM_H(ctx->r12, 0XC);
    // 0x8006229C: nop

    // 0x800622A0: beq         $t3, $t6, L_800622B8
    if (ctx->r11 == ctx->r14) {
        // 0x800622A4: nop
    
            goto L_800622B8;
    }
    // 0x800622A4: nop

    // 0x800622A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800622AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800622B0: jal         0x8006261C
    // 0x800622B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8006261C(rdram, ctx);
        goto after_5;
    // 0x800622B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_800622B8:
    // 0x800622B8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800622BC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800622C0: lh          $t9, 0x2($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X2);
    // 0x800622C4: lh          $t1, 0xC($t7)
    ctx->r9 = MEM_H(ctx->r15, 0XC);
    // 0x800622C8: nop

    // 0x800622CC: beq         $t9, $t1, L_800622E8
    if (ctx->r25 == ctx->r9) {
        // 0x800622D0: nop
    
            goto L_800622E8;
    }
    // 0x800622D0: nop

    // 0x800622D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800622D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800622DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800622E0: jal         0x8006261C
    // 0x800622E4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    func_8006261C(rdram, ctx);
        goto after_6;
    // 0x800622E4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_6:
L_800622E8:
    // 0x800622E8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800622EC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800622F0: lh          $t2, 0x4($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X4);
    // 0x800622F4: lh          $t4, 0xC($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XC);
    // 0x800622F8: nop

    // 0x800622FC: beq         $t2, $t4, L_80062318
    if (ctx->r10 == ctx->r12) {
        // 0x80062300: nop
    
            goto L_80062318;
    }
    // 0x80062300: nop

    // 0x80062304: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062308: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006230C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062310: jal         0x8006261C
    // 0x80062314: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8006261C(rdram, ctx);
        goto after_7;
    // 0x80062314: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
L_80062318:
    // 0x80062318: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8006231C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80062320: lh          $t6, 0x6($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X6);
    // 0x80062324: lh          $t7, 0xC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XC);
    // 0x80062328: nop

    // 0x8006232C: beq         $t6, $t7, L_80062348
    if (ctx->r14 == ctx->r15) {
        // 0x80062330: nop
    
            goto L_80062348;
    }
    // 0x80062330: nop

    // 0x80062334: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062338: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006233C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062340: jal         0x8006261C
    // 0x80062344: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    func_8006261C(rdram, ctx);
        goto after_8;
    // 0x80062344: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    after_8:
L_80062348:
    // 0x80062348: b           L_800625D8
    // 0x8006234C: nop

        goto L_800625D8;
    // 0x8006234C: nop

L_80062350:
    // 0x80062350: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80062354: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062358: lh          $a1, 0xC($t9)
    ctx->r5 = MEM_H(ctx->r25, 0XC);
    // 0x8006235C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80062360: jal         0x8006261C
    // 0x80062364: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8006261C(rdram, ctx);
        goto after_9;
    // 0x80062364: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_9:
    // 0x80062368: b           L_800625D8
    // 0x8006236C: nop

        goto L_800625D8;
    // 0x8006236C: nop

L_80062370:
    // 0x80062370: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80062374: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062378: lh          $a1, 0xC($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XC);
    // 0x8006237C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80062380: jal         0x8006261C
    // 0x80062384: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    func_8006261C(rdram, ctx);
        goto after_10;
    // 0x80062384: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    after_10:
    // 0x80062388: b           L_800625D8
    // 0x8006238C: nop

        goto L_800625D8;
    // 0x8006238C: nop

L_80062390:
    // 0x80062390: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80062394: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062398: lh          $a1, 0xC($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XC);
    // 0x8006239C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800623A0: jal         0x8006261C
    // 0x800623A4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_8006261C(rdram, ctx);
        goto after_11;
    // 0x800623A4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_11:
    // 0x800623A8: b           L_800625D8
    // 0x800623AC: nop

        goto L_800625D8;
    // 0x800623AC: nop

L_800623B0:
    // 0x800623B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800623B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800623B8: lh          $a1, 0xC($t0)
    ctx->r5 = MEM_H(ctx->r8, 0XC);
    // 0x800623BC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800623C0: jal         0x8006261C
    // 0x800623C4: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8006261C(rdram, ctx);
        goto after_12;
    // 0x800623C4: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_12:
    // 0x800623C8: b           L_800625D8
    // 0x800623CC: nop

        goto L_800625D8;
    // 0x800623CC: nop

L_800623D0:
    // 0x800623D0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800623D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800623D8: lh          $a1, 0xC($t2)
    ctx->r5 = MEM_H(ctx->r10, 0XC);
    // 0x800623DC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800623E0: jal         0x8006261C
    // 0x800623E4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_8006261C(rdram, ctx);
        goto after_13;
    // 0x800623E4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_13:
    // 0x800623E8: b           L_800625D8
    // 0x800623EC: nop

        goto L_800625D8;
    // 0x800623EC: nop

L_800623F0:
    // 0x800623F0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800623F4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800623F8: lh          $t3, 0x0($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X0);
    // 0x800623FC: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x80062400: nop

    // 0x80062404: beq         $t3, $t6, L_80062570
    if (ctx->r11 == ctx->r14) {
        // 0x80062408: nop
    
            goto L_80062570;
    }
    // 0x80062408: nop

    // 0x8006240C: lh          $t7, 0x2($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2);
    // 0x80062410: nop

    // 0x80062414: beq         $t7, $t6, L_80062570
    if (ctx->r15 == ctx->r14) {
        // 0x80062418: nop
    
            goto L_80062570;
    }
    // 0x80062418: nop

    // 0x8006241C: lh          $t9, 0x4($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X4);
    // 0x80062420: nop

    // 0x80062424: beq         $t9, $t6, L_80062570
    if (ctx->r25 == ctx->r14) {
        // 0x80062428: nop
    
            goto L_80062570;
    }
    // 0x80062428: nop

    // 0x8006242C: lh          $t1, 0x6($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X6);
    // 0x80062430: nop

    // 0x80062434: beq         $t1, $t6, L_80062570
    if (ctx->r9 == ctx->r14) {
        // 0x80062438: nop
    
            goto L_80062570;
    }
    // 0x80062438: nop

    // 0x8006243C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80062440: nop

    // 0x80062444: lh          $a0, 0xC($t8)
    ctx->r4 = MEM_H(ctx->r24, 0XC);
    // 0x80062448: jal         0x800615C8
    // 0x8006244C: nop

    func_800615C8(rdram, ctx);
        goto after_14;
    // 0x8006244C: nop

    after_14:
    // 0x80062450: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80062454: bne         $v0, $at, L_8006249C
    if (ctx->r2 != ctx->r1) {
        // 0x80062458: nop
    
            goto L_8006249C;
    }
    // 0x80062458: nop

    // 0x8006245C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80062460: nop

    // 0x80062464: sh          $zero, 0x2($t0)
    MEM_H(0X2, ctx->r8) = 0;
    // 0x80062468: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8006246C: nop

    // 0x80062470: sh          $zero, 0x4($t2)
    MEM_H(0X4, ctx->r10) = 0;
    // 0x80062474: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80062478: nop

    // 0x8006247C: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x80062480: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80062484: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062488: lh          $a1, 0xC($t3)
    ctx->r5 = MEM_H(ctx->r11, 0XC);
    // 0x8006248C: jal         0x8006261C
    // 0x80062490: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_8006261C(rdram, ctx);
        goto after_15;
    // 0x80062490: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_15:
    // 0x80062494: b           L_80062570
    // 0x80062498: nop

        goto L_80062570;
    // 0x80062498: nop

L_8006249C:
    // 0x8006249C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800624A0: nop

    // 0x800624A4: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x800624A8: nop

    // 0x800624AC: bne         $t9, $zero, L_800624D0
    if (ctx->r25 != 0) {
        // 0x800624B0: nop
    
            goto L_800624D0;
    }
    // 0x800624B0: nop

    // 0x800624B4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800624B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800624BC: lh          $a1, 0xC($t4)
    ctx->r5 = MEM_H(ctx->r12, 0XC);
    // 0x800624C0: jal         0x8006261C
    // 0x800624C4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    func_8006261C(rdram, ctx);
        goto after_16;
    // 0x800624C4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_16:
    // 0x800624C8: b           L_80062570
    // 0x800624CC: nop

        goto L_80062570;
    // 0x800624CC: nop

L_800624D0:
    // 0x800624D0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800624D4: nop

    // 0x800624D8: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x800624DC: nop

    // 0x800624E0: bne         $t6, $zero, L_80062508
    if (ctx->r14 != 0) {
        // 0x800624E4: nop
    
            goto L_80062508;
    }
    // 0x800624E4: nop

    // 0x800624E8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800624EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800624F0: lh          $a1, 0xC($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XC);
    // 0x800624F4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800624F8: jal         0x8006261C
    // 0x800624FC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    func_8006261C(rdram, ctx);
        goto after_17;
    // 0x800624FC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_17:
    // 0x80062500: b           L_80062570
    // 0x80062504: nop

        goto L_80062570;
    // 0x80062504: nop

L_80062508:
    // 0x80062508: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006250C: nop

    // 0x80062510: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80062514: nop

    // 0x80062518: bne         $t2, $zero, L_80062540
    if (ctx->r10 != 0) {
        // 0x8006251C: nop
    
            goto L_80062540;
    }
    // 0x8006251C: nop

    // 0x80062520: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80062524: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062528: lh          $a1, 0xC($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XC);
    // 0x8006252C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80062530: jal         0x8006261C
    // 0x80062534: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8006261C(rdram, ctx);
        goto after_18;
    // 0x80062534: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_18:
    // 0x80062538: b           L_80062570
    // 0x8006253C: nop

        goto L_80062570;
    // 0x8006253C: nop

L_80062540:
    // 0x80062540: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80062544: nop

    // 0x80062548: lh          $t7, 0x6($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X6);
    // 0x8006254C: nop

    // 0x80062550: bne         $t7, $zero, L_80062570
    if (ctx->r15 != 0) {
        // 0x80062554: nop
    
            goto L_80062570;
    }
    // 0x80062554: nop

    // 0x80062558: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8006255C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062560: lh          $a1, 0xC($t9)
    ctx->r5 = MEM_H(ctx->r25, 0XC);
    // 0x80062564: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80062568: jal         0x8006261C
    // 0x8006256C: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    func_8006261C(rdram, ctx);
        goto after_19;
    // 0x8006256C: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    after_19:
L_80062570:
    // 0x80062570: b           L_800625D8
    // 0x80062574: nop

        goto L_800625D8;
    // 0x80062574: nop

L_80062578:
    // 0x80062578: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006257C: nop

    // 0x80062580: lh          $a0, 0xC($t4)
    ctx->r4 = MEM_H(ctx->r12, 0XC);
    // 0x80062584: jal         0x8005F0DC
    // 0x80062588: nop

    func_8005F0DC(rdram, ctx);
        goto after_20;
    // 0x80062588: nop

    after_20:
    // 0x8006258C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80062590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80062594: lh          $a1, 0xC($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XC);
    // 0x80062598: jal         0x8006261C
    // 0x8006259C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_8006261C(rdram, ctx);
        goto after_21;
    // 0x8006259C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_21:
    // 0x800625A0: b           L_800625D8
    // 0x800625A4: nop

        goto L_800625D8;
    // 0x800625A4: nop

L_800625A8:
    // 0x800625A8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800625AC: nop

    // 0x800625B0: lh          $a0, 0xC($t6)
    ctx->r4 = MEM_H(ctx->r14, 0XC);
    // 0x800625B4: jal         0x8005F268
    // 0x800625B8: nop

    func_8005F268(rdram, ctx);
        goto after_22;
    // 0x800625B8: nop

    after_22:
    // 0x800625BC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800625C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800625C4: lh          $a1, 0xC($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XC);
    // 0x800625C8: jal         0x8006261C
    // 0x800625CC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_8006261C(rdram, ctx);
        goto after_23;
    // 0x800625CC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_23:
    // 0x800625D0: b           L_800625D8
    // 0x800625D4: nop

        goto L_800625D8;
    // 0x800625D4: nop

L_800625D8:
    // 0x800625D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800625DC: nop

    // 0x800625E0: lbu         $v0, 0xE($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XE);
    // 0x800625E4: nop

    // 0x800625E8: andi        $t2, $v0, 0x80
    ctx->r10 = ctx->r2 & 0X80;
    // 0x800625EC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800625F0: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x800625F4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800625F8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800625FC: b           L_8006260C
    // 0x80062600: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_8006260C;
    // 0x80062600: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80062604: b           L_8006260C
    // 0x80062608: nop

        goto L_8006260C;
    // 0x80062608: nop

L_8006260C:
    // 0x8006260C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80062614: jr          $ra
    // 0x80062618: nop

    return;
    // 0x80062618: nop

;}
RECOMP_FUNC void func_8006C090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C098: jal         0x8005F064
    // 0x8006C09C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C09C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x8006C0A0: b           L_8006C0B0
    // 0x8006C0A4: nop

        goto L_8006C0B0;
    // 0x8006C0A4: nop

    // 0x8006C0A8: b           L_8006C0B0
    // 0x8006C0AC: nop

        goto L_8006C0B0;
    // 0x8006C0AC: nop

L_8006C0B0:
    // 0x8006C0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C0B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C0B8: jr          $ra
    // 0x8006C0BC: nop

    return;
    // 0x8006C0BC: nop

;}
RECOMP_FUNC void func_8006717C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006717C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067184: jal         0x80061488
    // 0x80067188: addiu       $a0, $zero, 0x2D3
    ctx->r4 = ADD32(0, 0X2D3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067188: addiu       $a0, $zero, 0x2D3
    ctx->r4 = ADD32(0, 0X2D3);
    after_0:
    // 0x8006718C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80067190: b           L_800671A0
    // 0x80067194: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800671A0;
    // 0x80067194: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067198: b           L_800671A0
    // 0x8006719C: nop

        goto L_800671A0;
    // 0x8006719C: nop

L_800671A0:
    // 0x800671A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800671A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800671A8: jr          $ra
    // 0x800671AC: nop

    return;
    // 0x800671AC: nop

;}
RECOMP_FUNC void ContThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADC50: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800ADC54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ADC58: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800ADC5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ADC60: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800ADC64: addiu       $t7, $t7, -0x700
    ctx->r15 = ADD32(ctx->r15, -0X700);
    // 0x800ADC68: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800ADC6C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800ADC70: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800ADC74: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800ADC78: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800ADC7C: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x800ADC80: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800ADC84: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x800ADC88: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800ADC8C: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x800ADC90: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x800ADC94: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x800ADC98: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x800ADC9C: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x800ADCA0: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x800ADCA4: sw          $t9, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r25;
    // 0x800ADCA8: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x800ADCAC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800ADCB0: nop

    // 0x800ADCB4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x800ADCB8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800ADCBC: nop

    // 0x800ADCC0: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x800ADCC4: nop

    // 0x800ADCC8: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_800ADCCC:
    // 0x800ADCCC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800ADCD0: lw          $t3, 0x24D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X24D4);
    // 0x800ADCD4: nop

    // 0x800ADCD8: beq         $t3, $zero, L_800ADDEC
    if (ctx->r11 == 0) {
        // 0x800ADCDC: nop
    
            goto L_800ADDEC;
    }
    // 0x800ADCDC: nop

    // 0x800ADCE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADCE4: sw          $zero, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = 0;
    // 0x800ADCE8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ADCEC: lw          $t4, 0x1350($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1350);
    // 0x800ADCF0: nop

    // 0x800ADCF4: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800ADCF8: beq         $t5, $zero, L_800ADD20
    if (ctx->r13 == 0) {
        // 0x800ADCFC: nop
    
            goto L_800ADD20;
    }
    // 0x800ADCFC: nop

    // 0x800ADD00: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800ADD04: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADD08: jal         0x800AE0EC
    // 0x800ADD0C: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    ContPak_InitializePak(rdram, ctx);
        goto after_0;
    // 0x800ADD0C: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_0:
    // 0x800ADD10: jal         0x800AE40C
    // 0x800ADD14: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_1;
    // 0x800ADD14: nop

    after_1:
    // 0x800ADD18: b           L_800ADDE0
    // 0x800ADD1C: nop

        goto L_800ADDE0;
    // 0x800ADD1C: nop

L_800ADD20:
    // 0x800ADD20: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800ADD24: lw          $t8, 0x1350($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1350);
    // 0x800ADD28: nop

    // 0x800ADD2C: andi        $t6, $t8, 0x10
    ctx->r14 = ctx->r24 & 0X10;
    // 0x800ADD30: beq         $t6, $zero, L_800ADD48
    if (ctx->r14 == 0) {
        // 0x800ADD34: nop
    
            goto L_800ADD48;
    }
    // 0x800ADD34: nop

    // 0x800ADD38: jal         0x800AE664
    // 0x800ADD3C: nop

    ContPak_DeleteFile(rdram, ctx);
        goto after_2;
    // 0x800ADD3C: nop

    after_2:
    // 0x800ADD40: b           L_800ADDE0
    // 0x800ADD44: nop

        goto L_800ADDE0;
    // 0x800ADD44: nop

L_800ADD48:
    // 0x800ADD48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800ADD4C: lw          $t7, 0x1350($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1350);
    // 0x800ADD50: nop

    // 0x800ADD54: andi        $t9, $t7, 0x20
    ctx->r25 = ctx->r15 & 0X20;
    // 0x800ADD58: beq         $t9, $zero, L_800ADD70
    if (ctx->r25 == 0) {
        // 0x800ADD5C: nop
    
            goto L_800ADD70;
    }
    // 0x800ADD5C: nop

    // 0x800ADD60: jal         0x800AE904
    // 0x800ADD64: nop

    ContPak_OpenFile(rdram, ctx);
        goto after_3;
    // 0x800ADD64: nop

    after_3:
    // 0x800ADD68: b           L_800ADDE0
    // 0x800ADD6C: nop

        goto L_800ADDE0;
    // 0x800ADD6C: nop

L_800ADD70:
    // 0x800ADD70: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800ADD74: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800ADD78: nop

    // 0x800ADD7C: andi        $t1, $t0, 0x100
    ctx->r9 = ctx->r8 & 0X100;
    // 0x800ADD80: beq         $t1, $zero, L_800ADD98
    if (ctx->r9 == 0) {
        // 0x800ADD84: nop
    
            goto L_800ADD98;
    }
    // 0x800ADD84: nop

    // 0x800ADD88: jal         0x800AEB14
    // 0x800ADD8C: nop

    ContPak_FindFile(rdram, ctx);
        goto after_4;
    // 0x800ADD8C: nop

    after_4:
    // 0x800ADD90: b           L_800ADDE0
    // 0x800ADD94: nop

        goto L_800ADDE0;
    // 0x800ADD94: nop

L_800ADD98:
    // 0x800ADD98: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800ADD9C: lw          $t2, 0x1350($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1350);
    // 0x800ADDA0: nop

    // 0x800ADDA4: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x800ADDA8: beq         $t3, $zero, L_800ADDC0
    if (ctx->r11 == 0) {
        // 0x800ADDAC: nop
    
            goto L_800ADDC0;
    }
    // 0x800ADDAC: nop

    // 0x800ADDB0: jal         0x800AED0C
    // 0x800ADDB4: nop

    ContPak_WriteFile(rdram, ctx);
        goto after_5;
    // 0x800ADDB4: nop

    after_5:
    // 0x800ADDB8: b           L_800ADDE0
    // 0x800ADDBC: nop

        goto L_800ADDE0;
    // 0x800ADDBC: nop

L_800ADDC0:
    // 0x800ADDC0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ADDC4: lw          $t4, 0x1350($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1350);
    // 0x800ADDC8: nop

    // 0x800ADDCC: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x800ADDD0: beq         $t5, $zero, L_800ADDE0
    if (ctx->r13 == 0) {
        // 0x800ADDD4: nop
    
            goto L_800ADDE0;
    }
    // 0x800ADDD4: nop

    // 0x800ADDD8: jal         0x800AEEF8
    // 0x800ADDDC: nop

    ContPak_ReadFile(rdram, ctx);
        goto after_6;
    // 0x800ADDDC: nop

    after_6:
L_800ADDE0:
    // 0x800ADDE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ADDE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADDE8: sw          $t8, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = ctx->r24;
L_800ADDEC:
    // 0x800ADDEC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800ADDF0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800ADDF4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800ADDF8: jal         0x800C143C
    // 0x800ADDFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_7;
    // 0x800ADDFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800ADE00: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800ADE04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800ADE08: lh          $s0, 0x0($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X0);
    // 0x800ADE0C: nop

    // 0x800ADE10: beq         $s0, $at, L_800ADE58
    if (ctx->r16 == ctx->r1) {
        // 0x800ADE14: nop
    
            goto L_800ADE58;
    }
    // 0x800ADE14: nop

    // 0x800ADE18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ADE1C: beq         $s0, $at, L_800ADE38
    if (ctx->r16 == ctx->r1) {
        // 0x800ADE20: nop
    
            goto L_800ADE38;
    }
    // 0x800ADE20: nop

    // 0x800ADE24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800ADE28: beq         $s0, $at, L_800ADE78
    if (ctx->r16 == ctx->r1) {
        // 0x800ADE2C: nop
    
            goto L_800ADE78;
    }
    // 0x800ADE2C: nop

    // 0x800ADE30: b           L_800ADE9C
    // 0x800ADE34: nop

        goto L_800ADE9C;
    // 0x800ADE34: nop

L_800ADE38:
    // 0x800ADE38: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800ADE3C: jal         0x800C5654
    // 0x800ADE40: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    osContGetReadData_recomp(rdram, ctx);
        goto after_8;
    // 0x800ADE40: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    after_8:
    // 0x800ADE44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ADE48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADE4C: sw          $t9, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = ctx->r25;
    // 0x800ADE50: b           L_800ADEA4
    // 0x800ADE54: nop

        goto L_800ADEA4;
    // 0x800ADE54: nop

L_800ADE58:
    // 0x800ADE58: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800ADE5C: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADE60: jal         0x800C5590
    // 0x800ADE64: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    osContStartReadData_recomp(rdram, ctx);
        goto after_9;
    // 0x800ADE64: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_9:
    // 0x800ADE68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADE6C: sw          $zero, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = 0;
    // 0x800ADE70: b           L_800ADEA4
    // 0x800ADE74: nop

        goto L_800ADEA4;
    // 0x800ADE74: nop

L_800ADE78:
    // 0x800ADE78: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800ADE7C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800ADE80: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x800ADE84: jal         0x800C143C
    // 0x800ADE88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_10;
    // 0x800ADE88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x800ADE8C: b           L_800ADE78
    // 0x800ADE90: nop

        goto L_800ADE78;
    // 0x800ADE90: nop

    // 0x800ADE94: b           L_800ADEA4
    // 0x800ADE98: nop

        goto L_800ADEA4;
    // 0x800ADE98: nop

L_800ADE9C:
    // 0x800ADE9C: b           L_800ADEA4
    // 0x800ADEA0: nop

        goto L_800ADEA4;
    // 0x800ADEA0: nop

L_800ADEA4:
    // 0x800ADEA4: b           L_800ADCCC
    // 0x800ADEA8: nop

        goto L_800ADCCC;
    // 0x800ADEA8: nop

    // 0x800ADEAC: b           L_800ADEB4
    // 0x800ADEB0: nop

        goto L_800ADEB4;
    // 0x800ADEB0: nop

L_800ADEB4:
    // 0x800ADEB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADEB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ADEBC: jr          $ra
    // 0x800ADEC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800ADEC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80075534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075534: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075538: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007553C: nop

    // 0x80075540: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80075544: nop

    // 0x80075548: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007554C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075550: jr          $ra
    // 0x80075554: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075554: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075558: jr          $ra
    // 0x8007555C: nop

    return;
    // 0x8007555C: nop

    // 0x80075560: jr          $ra
    // 0x80075564: nop

    return;
    // 0x80075564: nop

;}
RECOMP_FUNC void func_8000B340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B340: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000B344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B348: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8000B34C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8000B350: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8000B354: nop

    // 0x8000B358: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000B35C: nop

    // 0x8000B360: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8000B364: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000B368: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x8000B36C: nop

    // 0x8000B370: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8000B374: beq         $t9, $zero, L_8000B638
    if (ctx->r25 == 0) {
        // 0x8000B378: nop
    
            goto L_8000B638;
    }
    // 0x8000B378: nop

    // 0x8000B37C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8000B380: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8000B384: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000B388: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8000B38C: lw          $t2, 0x15D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X15D8);
    // 0x8000B390: nop

    // 0x8000B394: bne         $t2, $zero, L_8000B638
    if (ctx->r10 != 0) {
        // 0x8000B398: nop
    
            goto L_8000B638;
    }
    // 0x8000B398: nop

    // 0x8000B39C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8000B3A0: addiu       $t3, $sp, 0x18
    ctx->r11 = ADD32(ctx->r29, 0X18);
    // 0x8000B3A4: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x8000B3A8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8000B3AC: nop

    // 0x8000B3B0: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8000B3B4: beq         $at, $zero, L_8000B460
    if (ctx->r1 == 0) {
        // 0x8000B3B8: nop
    
            goto L_8000B460;
    }
    // 0x8000B3B8: nop

L_8000B3BC:
    // 0x8000B3BC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8000B3C0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8000B3C4: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8000B3C8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000B3CC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000B3D0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8000B3D4: lbu         $t9, 0x13DE($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X13DE);
    // 0x8000B3D8: nop

    // 0x8000B3DC: bne         $t9, $zero, L_8000B3EC
    if (ctx->r25 != 0) {
        // 0x8000B3E0: sb          $t9, 0x3F($sp)
        MEM_B(0X3F, ctx->r29) = ctx->r25;
            goto L_8000B3EC;
    }
    // 0x8000B3E0: sb          $t9, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r25;
    // 0x8000B3E4: b           L_8000B460
    // 0x8000B3E8: nop

        goto L_8000B460;
    // 0x8000B3E8: nop

L_8000B3EC:
    // 0x8000B3EC: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B3F0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8000B3F4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8000B3F8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000B3FC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8000B400: lbu         $t2, -0x5BF0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X5BF0);
    // 0x8000B404: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8000B408: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x8000B40C: sb          $t2, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r10;
    // 0x8000B410: lbu         $t6, 0x3F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B414: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8000B418: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000B41C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000B420: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000B424: lbu         $t8, -0x5BEF($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X5BEF);
    // 0x8000B428: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8000B42C: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x8000B430: sb          $t8, 0x19($t1)
    MEM_B(0X19, ctx->r9) = ctx->r24;
    // 0x8000B434: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8000B438: nop

    // 0x8000B43C: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x8000B440: addu        $t4, $sp, $t2
    ctx->r12 = ADD32(ctx->r29, ctx->r10);
    // 0x8000B444: sb          $zero, 0x1A($t4)
    MEM_B(0X1A, ctx->r12) = 0;
    // 0x8000B448: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8000B44C: nop

    // 0x8000B450: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000B454: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8000B458: bne         $at, $zero, L_8000B3BC
    if (ctx->r1 != 0) {
        // 0x8000B45C: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8000B3BC;
    }
    // 0x8000B45C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_8000B460:
    // 0x8000B460: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8000B464: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000B468: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x8000B46C: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8000B470: lbu         $t8, 0x13DA($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X13DA);
    // 0x8000B474: nop

    // 0x8000B478: beq         $t8, $zero, L_8000B57C
    if (ctx->r24 == 0) {
        // 0x8000B47C: nop
    
            goto L_8000B57C;
    }
    // 0x8000B47C: nop

    // 0x8000B480: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8000B484: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    // 0x8000B488: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B48C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8000B490: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8000B494: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x8000B498: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8000B49C: lbu         $t2, -0x5BF0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X5BF0);
    // 0x8000B4A0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8000B4A4: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8000B4A8: sb          $t2, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r10;
    // 0x8000B4AC: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B4B0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8000B4B4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000B4B8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8000B4BC: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8000B4C0: lbu         $t8, -0x5BEF($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X5BEF);
    // 0x8000B4C4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000B4C8: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x8000B4CC: sb          $t8, 0x19($t3)
    MEM_B(0X19, ctx->r11) = ctx->r24;
    // 0x8000B4D0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8000B4D4: nop

    // 0x8000B4D8: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8000B4DC: addu        $t5, $sp, $t2
    ctx->r13 = ADD32(ctx->r29, ctx->r10);
    // 0x8000B4E0: sb          $zero, 0x1A($t5)
    MEM_B(0X1A, ctx->r13) = 0;
    // 0x8000B4E4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000B4E8: nop

    // 0x8000B4EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000B4F0: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8000B4F4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8000B4F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000B4FC: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8000B500: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x8000B504: lbu         $t8, 0x13DA($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X13DA);
    // 0x8000B508: nop

    // 0x8000B50C: sb          $t8, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r24;
    // 0x8000B510: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B514: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B518: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8000B51C: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x8000B520: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8000B524: lbu         $t4, -0x5BF0($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X5BF0);
    // 0x8000B528: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x8000B52C: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8000B530: sb          $t4, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r12;
    // 0x8000B534: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B538: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000B53C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000B540: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8000B544: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8000B548: lbu         $t0, -0x5BEF($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X5BEF);
    // 0x8000B54C: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8000B550: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x8000B554: sb          $t0, 0x19($t3)
    MEM_B(0X19, ctx->r11) = ctx->r8;
    // 0x8000B558: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B55C: nop

    // 0x8000B560: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8000B564: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x8000B568: sb          $zero, 0x1A($t5)
    MEM_B(0X1A, ctx->r13) = 0;
    // 0x8000B56C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000B570: nop

    // 0x8000B574: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000B578: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_8000B57C:
    // 0x8000B57C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000B580: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8000B584: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x8000B588: beq         $at, $zero, L_8000B604
    if (ctx->r1 == 0) {
        // 0x8000B58C: sb          $t9, 0x3F($sp)
        MEM_B(0X3F, ctx->r29) = ctx->r25;
            goto L_8000B604;
    }
    // 0x8000B58C: sb          $t9, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r25;
L_8000B590:
    // 0x8000B590: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B594: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B598: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8000B59C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000B5A0: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8000B5A4: lbu         $t3, -0x5BF0($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X5BF0);
    // 0x8000B5A8: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8000B5AC: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x8000B5B0: sb          $t3, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r11;
    // 0x8000B5B4: lbu         $t6, 0x3F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B5B8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000B5BC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000B5C0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000B5C4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8000B5C8: lbu         $t9, -0x5BEF($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X5BEF);
    // 0x8000B5CC: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8000B5D0: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x8000B5D4: sb          $t9, 0x19($t1)
    MEM_B(0X19, ctx->r9) = ctx->r25;
    // 0x8000B5D8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B5DC: nop

    // 0x8000B5E0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8000B5E4: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8000B5E8: sb          $zero, 0x1A($t4)
    MEM_B(0X1A, ctx->r12) = 0;
    // 0x8000B5EC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8000B5F0: nop

    // 0x8000B5F4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000B5F8: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8000B5FC: bne         $at, $zero, L_8000B590
    if (ctx->r1 != 0) {
        // 0x8000B600: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8000B590;
    }
    // 0x8000B600: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_8000B604:
    // 0x8000B604: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8000B608: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8000B60C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8000B610: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8000B614: lw          $a2, 0x13D0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X13D0);
    // 0x8000B618: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000B61C: srl         $t9, $a2, 8
    ctx->r25 = S32(U32(ctx->r6) >> 8);
    // 0x8000B620: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8000B624: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x8000B628: jal         0x8008ECE4
    // 0x8000B62C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8000B62C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8000B630: b           L_8000B644
    // 0x8000B634: nop

        goto L_8000B644;
    // 0x8000B634: nop

L_8000B638:
    // 0x8000B638: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000B63C: jal         0x8008ECE4
    // 0x8000B640: addiu       $a0, $a0, -0x2CE8
    ctx->r4 = ADD32(ctx->r4, -0X2CE8);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8000B640: addiu       $a0, $a0, -0x2CE8
    ctx->r4 = ADD32(ctx->r4, -0X2CE8);
    after_1:
L_8000B644:
    // 0x8000B644: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8000B648: nop

    // 0x8000B64C: bltz        $t0, L_8000B774
    if (SIGNED(ctx->r8) < 0) {
        // 0x8000B650: nop
    
            goto L_8000B774;
    }
    // 0x8000B650: nop

    // 0x8000B654: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000B658: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8000B65C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000B660: lhu         $t3, 0x101C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X101C);
    // 0x8000B664: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8000B668: nop

    // 0x8000B66C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8000B670: beq         $t4, $zero, L_8000B680
    if (ctx->r12 == 0) {
        // 0x8000B674: nop
    
            goto L_8000B680;
    }
    // 0x8000B674: nop

    // 0x8000B678: b           L_8000B784
    // 0x8000B67C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000B784;
    // 0x8000B67C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000B680:
    // 0x8000B680: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000B684: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8000B688: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000B68C: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x8000B690: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x8000B694: nop

    // 0x8000B698: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8000B69C: beq         $t8, $zero, L_8000B6E4
    if (ctx->r24 == 0) {
        // 0x8000B6A0: nop
    
            goto L_8000B6E4;
    }
    // 0x8000B6A0: nop

    // 0x8000B6A4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000B6A8: lw          $t9, 0x129C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X129C);
    // 0x8000B6AC: nop

    // 0x8000B6B0: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8000B6B4: beq         $t0, $zero, L_8000B6E4
    if (ctx->r8 == 0) {
        // 0x8000B6B8: nop
    
            goto L_8000B6E4;
    }
    // 0x8000B6B8: nop

    // 0x8000B6BC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8000B6C0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000B6C4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000B6C8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8000B6CC: lw          $t3, 0x15D8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X15D8);
    // 0x8000B6D0: nop

    // 0x8000B6D4: bne         $t3, $zero, L_8000B6E4
    if (ctx->r11 != 0) {
        // 0x8000B6D8: nop
    
            goto L_8000B6E4;
    }
    // 0x8000B6D8: nop

    // 0x8000B6DC: b           L_8000B784
    // 0x8000B6E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000B784;
    // 0x8000B6E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000B6E4:
    // 0x8000B6E4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000B6E8: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8000B6EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8000B6F0: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8000B6F4: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8000B6F8: nop

    // 0x8000B6FC: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8000B700: beq         $t7, $zero, L_8000B774
    if (ctx->r15 == 0) {
        // 0x8000B704: nop
    
            goto L_8000B774;
    }
    // 0x8000B704: nop

    // 0x8000B708: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000B70C: lw          $t8, -0x5B18($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B18);
    // 0x8000B710: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000B714: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000B718: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8000B71C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8000B720: lw          $t0, -0x5750($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5750);
    // 0x8000B724: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000B728: bne         $t0, $t2, L_8000B744
    if (ctx->r8 != ctx->r10) {
        // 0x8000B72C: nop
    
            goto L_8000B744;
    }
    // 0x8000B72C: nop

    // 0x8000B730: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000B734: lw          $t3, -0x5B18($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5B18);
    // 0x8000B738: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000B73C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000B740: sw          $t4, -0x5B18($at)
    MEM_W(-0X5B18, ctx->r1) = ctx->r12;
L_8000B744:
    // 0x8000B744: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000B748: lw          $t5, -0x5B18($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B18);
    // 0x8000B74C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000B750: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000B754: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000B758: lw          $t7, -0x5750($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5750);
    // 0x8000B75C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B760: bne         $t7, $at, L_8000B774
    if (ctx->r15 != ctx->r1) {
        // 0x8000B764: nop
    
            goto L_8000B774;
    }
    // 0x8000B764: nop

    // 0x8000B768: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000B76C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000B770: sw          $t8, -0x5B14($at)
    MEM_W(-0X5B14, ctx->r1) = ctx->r24;
L_8000B774:
    // 0x8000B774: b           L_8000B784
    // 0x8000B778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B784;
    // 0x8000B778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000B77C: b           L_8000B784
    // 0x8000B780: nop

        goto L_8000B784;
    // 0x8000B780: nop

L_8000B784:
    // 0x8000B784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B788: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000B78C: jr          $ra
    // 0x8000B790: nop

    return;
    // 0x8000B790: nop

    // 0x8000B794: nop

    // 0x8000B798: nop

    // 0x8000B79C: nop

;}
RECOMP_FUNC void func_80037578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037578: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x8003757C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80037580: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80037584: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80037588: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003758C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80037590: jal         0x80031AC8
    // 0x80037594: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x80037594: nop

    after_0:
    // 0x80037598: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8003759C: bne         $v0, $at, L_800377A0
    if (ctx->r2 != ctx->r1) {
        // 0x800375A0: nop
    
            goto L_800377A0;
    }
    // 0x800375A0: nop

    // 0x800375A4: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x800375A8: lbu         $t6, -0x69F8($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X69F8);
    // 0x800375AC: nop

    // 0x800375B0: beq         $t6, $zero, L_800377A0
    if (ctx->r14 == 0) {
        // 0x800375B4: nop
    
            goto L_800377A0;
    }
    // 0x800375B4: nop

    // 0x800375B8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800375BC: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800375C0: nop

    // 0x800375C4: addiu       $t8, $t7, 0x4A
    ctx->r24 = ADD32(ctx->r15, 0X4A);
    // 0x800375C8: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x800375CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800375D0: lwc1        $f4, -0x76B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800375D4: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800375D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800375DC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800375E0: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x800375E4: nop

    // 0x800375E8: bc1t        L_8003764C
    if (c1cs) {
        // 0x800375EC: nop
    
            goto L_8003764C;
    }
    // 0x800375EC: nop

    // 0x800375F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800375F4: lw          $t9, 0x258C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X258C);
    // 0x800375F8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800375FC: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x80037600: mfhi        $t0
    ctx->r8 = hi;
    // 0x80037604: bne         $t0, $zero, L_8003764C
    if (ctx->r8 != 0) {
        // 0x80037608: nop
    
            goto L_8003764C;
    }
    // 0x80037608: nop

    // 0x8003760C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80037610: nop

    // 0x80037614: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80037618: nop

    // 0x8003761C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80037620: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80037624: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80037628: nop

    // 0x8003762C: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80037630: nop

    // 0x80037634: slti        $at, $t5, 0x2711
    ctx->r1 = SIGNED(ctx->r13) < 0X2711 ? 1 : 0;
    // 0x80037638: bne         $at, $zero, L_8003764C
    if (ctx->r1 != 0) {
        // 0x8003763C: nop
    
            goto L_8003764C;
    }
    // 0x8003763C: nop

    // 0x80037640: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80037644: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x80037648: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_8003764C:
    // 0x8003764C: sh          $zero, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = 0;
    // 0x80037650: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80037654: nop

    // 0x80037658: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8003765C: nop

    // 0x80037660: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80037664: nop

    // 0x80037668: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003766C: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    // 0x80037670: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80037674: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037678: lwc1        $f18, 0xD8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8003767C: nop

    // 0x80037680: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80037684: nop

    // 0x80037688: bc1f        L_800376C4
    if (!c1cs) {
        // 0x8003768C: nop
    
            goto L_800376C4;
    }
    // 0x8003768C: nop

    // 0x80037690: jal         0x8005F064
    // 0x80037694: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80037694: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    after_1:
    // 0x80037698: bne         $v0, $zero, L_800376C4
    if (ctx->r2 != 0) {
        // 0x8003769C: nop
    
            goto L_800376C4;
    }
    // 0x8003769C: nop

    // 0x800376A0: jal         0x80031874
    // 0x800376A4: nop

    func_80031874(rdram, ctx);
        goto after_2;
    // 0x800376A4: nop

    after_2:
    // 0x800376A8: bne         $v0, $zero, L_800376C4
    if (ctx->r2 != 0) {
        // 0x800376AC: nop
    
            goto L_800376C4;
    }
    // 0x800376AC: nop

    // 0x800376B0: jal         0x8005F0DC
    // 0x800376B4: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    func_8005F0DC(rdram, ctx);
        goto after_3;
    // 0x800376B4: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    after_3:
    // 0x800376B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800376BC: b           L_80037768
    // 0x800376C0: sh          $t0, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = ctx->r8;
        goto L_80037768;
    // 0x800376C0: sh          $t0, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = ctx->r8;
L_800376C4:
    // 0x800376C4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800376C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800376CC: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800376D0: nop

    // 0x800376D4: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800376D8: nop

    // 0x800376DC: bc1f        L_80037718
    if (!c1cs) {
        // 0x800376E0: nop
    
            goto L_80037718;
    }
    // 0x800376E0: nop

    // 0x800376E4: jal         0x8005F064
    // 0x800376E8: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    func_8005F064(rdram, ctx);
        goto after_4;
    // 0x800376E8: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    after_4:
    // 0x800376EC: bne         $v0, $zero, L_80037718
    if (ctx->r2 != 0) {
        // 0x800376F0: nop
    
            goto L_80037718;
    }
    // 0x800376F0: nop

    // 0x800376F4: jal         0x80031874
    // 0x800376F8: nop

    func_80031874(rdram, ctx);
        goto after_5;
    // 0x800376F8: nop

    after_5:
    // 0x800376FC: bne         $v0, $zero, L_80037718
    if (ctx->r2 != 0) {
        // 0x80037700: nop
    
            goto L_80037718;
    }
    // 0x80037700: nop

    // 0x80037704: jal         0x8005F0DC
    // 0x80037708: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    func_8005F0DC(rdram, ctx);
        goto after_6;
    // 0x80037708: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    after_6:
    // 0x8003770C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80037710: b           L_80037768
    // 0x80037714: sh          $t2, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = ctx->r10;
        goto L_80037768;
    // 0x80037714: sh          $t2, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = ctx->r10;
L_80037718:
    // 0x80037718: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x8003771C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80037720: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80037724: nop

    // 0x80037728: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8003772C: nop

    // 0x80037730: bc1f        L_80037768
    if (!c1cs) {
        // 0x80037734: nop
    
            goto L_80037768;
    }
    // 0x80037734: nop

    // 0x80037738: jal         0x8005F064
    // 0x8003773C: addiu       $a0, $zero, 0x1FB
    ctx->r4 = ADD32(0, 0X1FB);
    func_8005F064(rdram, ctx);
        goto after_7;
    // 0x8003773C: addiu       $a0, $zero, 0x1FB
    ctx->r4 = ADD32(0, 0X1FB);
    after_7:
    // 0x80037740: bne         $v0, $zero, L_80037768
    if (ctx->r2 != 0) {
        // 0x80037744: nop
    
            goto L_80037768;
    }
    // 0x80037744: nop

    // 0x80037748: jal         0x80031874
    // 0x8003774C: nop

    func_80031874(rdram, ctx);
        goto after_8;
    // 0x8003774C: nop

    after_8:
    // 0x80037750: bne         $v0, $zero, L_80037768
    if (ctx->r2 != 0) {
        // 0x80037754: nop
    
            goto L_80037768;
    }
    // 0x80037754: nop

    // 0x80037758: jal         0x8005F0DC
    // 0x8003775C: addiu       $a0, $zero, 0x1FB
    ctx->r4 = ADD32(0, 0X1FB);
    func_8005F0DC(rdram, ctx);
        goto after_9;
    // 0x8003775C: addiu       $a0, $zero, 0x1FB
    ctx->r4 = ADD32(0, 0X1FB);
    after_9:
    // 0x80037760: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80037764: sh          $t3, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = ctx->r11;
L_80037768:
    // 0x80037768: lhu         $t1, 0xF8($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XF8);
    // 0x8003776C: nop

    // 0x80037770: beq         $t1, $zero, L_800377A0
    if (ctx->r9 == 0) {
        // 0x80037774: nop
    
            goto L_800377A0;
    }
    // 0x80037774: nop

    // 0x80037778: jal         0x800B9000
    // 0x8003777C: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    func_800B9000(rdram, ctx);
        goto after_10;
    // 0x8003777C: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    after_10:
    // 0x80037780: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80037784: lw          $t4, 0x7284($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7284);
    // 0x80037788: nop

    // 0x8003778C: lw          $a0, 0x14($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X14);
    // 0x80037790: jal         0x800319B0
    // 0x80037794: nop

    func_800319B0(rdram, ctx);
        goto after_11;
    // 0x80037794: nop

    after_11:
    // 0x80037798: jal         0x80031B6C
    // 0x8003779C: nop

    func_80031B6C(rdram, ctx);
        goto after_12;
    // 0x8003779C: nop

    after_12:
L_800377A0:
    // 0x800377A0: jal         0x8005F064
    // 0x800377A4: addiu       $a0, $zero, 0x1FB
    ctx->r4 = ADD32(0, 0X1FB);
    func_8005F064(rdram, ctx);
        goto after_13;
    // 0x800377A4: addiu       $a0, $zero, 0x1FB
    ctx->r4 = ADD32(0, 0X1FB);
    after_13:
    // 0x800377A8: beq         $v0, $zero, L_800377C0
    if (ctx->r2 == 0) {
        // 0x800377AC: nop
    
            goto L_800377C0;
    }
    // 0x800377AC: nop

    // 0x800377B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800377B4: lwc1        $f18, -0x1600($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1600);
    // 0x800377B8: b           L_80037810
    // 0x800377BC: swc1        $f18, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f18.u32l;
        goto L_80037810;
    // 0x800377BC: swc1        $f18, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f18.u32l;
L_800377C0:
    // 0x800377C0: jal         0x8005F064
    // 0x800377C4: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    func_8005F064(rdram, ctx);
        goto after_14;
    // 0x800377C4: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    after_14:
    // 0x800377C8: beq         $v0, $zero, L_800377E0
    if (ctx->r2 == 0) {
        // 0x800377CC: nop
    
            goto L_800377E0;
    }
    // 0x800377CC: nop

    // 0x800377D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800377D4: lwc1        $f4, -0x15FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X15FC);
    // 0x800377D8: b           L_80037810
    // 0x800377DC: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
        goto L_80037810;
    // 0x800377DC: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
L_800377E0:
    // 0x800377E0: jal         0x8005F064
    // 0x800377E4: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    func_8005F064(rdram, ctx);
        goto after_15;
    // 0x800377E4: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    after_15:
    // 0x800377E8: beq         $v0, $zero, L_80037800
    if (ctx->r2 == 0) {
        // 0x800377EC: nop
    
            goto L_80037800;
    }
    // 0x800377EC: nop

    // 0x800377F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800377F4: lwc1        $f6, -0x15F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15F8);
    // 0x800377F8: b           L_80037810
    // 0x800377FC: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
        goto L_80037810;
    // 0x800377FC: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
L_80037800:
    // 0x80037800: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037804: lwc1        $f8, -0x15F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X15F4);
    // 0x80037808: nop

    // 0x8003780C: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
L_80037810:
    // 0x80037810: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x80037814: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037818: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8003781C: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x80037820: swc1        $f10, 0x72C($t5)
    MEM_W(0X72C, ctx->r13) = ctx->f10.u32l;
    // 0x80037824: lui         $at, 0x4317
    ctx->r1 = S32(0X4317 << 16);
    // 0x80037828: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003782C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80037830: addiu       $t6, $t6, 0x61D8
    ctx->r14 = ADD32(ctx->r14, 0X61D8);
    // 0x80037834: swc1        $f16, 0x734($t6)
    MEM_W(0X734, ctx->r14) = ctx->f16.u32l;
    // 0x80037838: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003783C: lwc1        $f18, 0x50C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80037840: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80037844: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80037848: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003784C: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80037850: nop

    // 0x80037854: bc1f        L_80037874
    if (!c1cs) {
        // 0x80037858: nop
    
            goto L_80037874;
    }
    // 0x80037858: nop

    // 0x8003785C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80037860: lhu         $t7, 0x728E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X728E);
    // 0x80037864: nop

    // 0x80037868: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8003786C: beq         $t8, $zero, L_80037898
    if (ctx->r24 == 0) {
        // 0x80037870: nop
    
            goto L_80037898;
    }
    // 0x80037870: nop

L_80037874:
    // 0x80037874: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80037878: nop

    // 0x8003787C: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x80037880: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80037884: nop

    // 0x80037888: swc1        $f10, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f10.u32l;
    // 0x8003788C: sh          $zero, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = 0;
    // 0x80037890: b           L_80037A54
    // 0x80037894: sh          $zero, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = 0;
        goto L_80037A54;
    // 0x80037894: sh          $zero, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = 0;
L_80037898:
    // 0x80037898: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8003789C: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x800378A0: lwc1        $f16, 0x10($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800378A4: nop

    // 0x800378A8: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    // 0x800378AC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800378B0: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x800378B4: lwc1        $f18, 0x14($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800378B8: nop

    // 0x800378BC: swc1        $f18, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f18.u32l;
    // 0x800378C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800378C4: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800378C8: lwc1        $f9, -0x15F0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X15F0);
    // 0x800378CC: lwc1        $f8, -0x15EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X15EC);
    // 0x800378D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800378D4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800378D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800378DC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800378E0: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800378E4: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    // 0x800378E8: bc1f        L_80037914
    if (!c1cs) {
        // 0x800378EC: nop
    
            goto L_80037914;
    }
    // 0x800378EC: nop

    // 0x800378F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800378F4: lwc1        $f7, -0x15E8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X15E8);
    // 0x800378F8: lwc1        $f6, -0x15E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15E4);
    // 0x800378FC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80037900: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80037904: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80037908: swc1        $f10, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f10.u32l;
    // 0x8003790C: b           L_80037938
    // 0x80037910: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
        goto L_80037938;
    // 0x80037910: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
L_80037914:
    // 0x80037914: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037918: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8003791C: lwc1        $f5, -0x15E0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X15E0);
    // 0x80037920: lwc1        $f4, -0x15DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X15DC);
    // 0x80037924: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80037928: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x8003792C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80037930: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x80037934: neg.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = -ctx->f8.fl;
L_80037938:
    // 0x80037938: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8003793C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80037940: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80037944: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x80037948: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8003794C: nop

    // 0x80037950: bc1f        L_80037964
    if (!c1cs) {
        // 0x80037954: nop
    
            goto L_80037964;
    }
    // 0x80037954: nop

    // 0x80037958: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003795C: nop

    // 0x80037960: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
L_80037964:
    // 0x80037964: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037968: lwc1        $f4, 0x100($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8003796C: lwc1        $f9, -0x15D8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X15D8);
    // 0x80037970: lwc1        $f8, -0x15D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X15D4);
    // 0x80037974: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80037978: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003797C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80037980: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80037984: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80037988: swc1        $f18, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f18.u32l;
    // 0x8003798C: bc1f        L_800379B8
    if (!c1cs) {
        // 0x80037990: nop
    
            goto L_800379B8;
    }
    // 0x80037990: nop

    // 0x80037994: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037998: lwc1        $f7, -0x15D0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X15D0);
    // 0x8003799C: lwc1        $f6, -0x15CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15CC);
    // 0x800379A0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800379A4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800379A8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800379AC: swc1        $f10, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f10.u32l;
    // 0x800379B0: b           L_800379DC
    // 0x800379B4: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
        goto L_800379DC;
    // 0x800379B4: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
L_800379B8:
    // 0x800379B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800379BC: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800379C0: lwc1        $f5, -0x15C8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X15C8);
    // 0x800379C4: lwc1        $f4, -0x15C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X15C4);
    // 0x800379C8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800379CC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800379D0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800379D4: swc1        $f8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f8.u32l;
    // 0x800379D8: neg.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = -ctx->f8.fl;
L_800379DC:
    // 0x800379DC: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800379E0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800379E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800379E8: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x800379EC: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x800379F0: nop

    // 0x800379F4: bc1f        L_80037A08
    if (!c1cs) {
        // 0x800379F8: nop
    
            goto L_80037A08;
    }
    // 0x800379F8: nop

    // 0x800379FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80037A00: nop

    // 0x80037A04: swc1        $f18, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f18.u32l;
L_80037A08:
    // 0x80037A08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80037A0C: lh          $t2, 0x7254($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7254);
    // 0x80037A10: nop

    // 0x80037A14: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x80037A18: beq         $t3, $zero, L_80037A2C
    if (ctx->r11 == 0) {
        // 0x80037A1C: nop
    
            goto L_80037A2C;
    }
    // 0x80037A1C: nop

    // 0x80037A20: sh          $zero, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = 0;
    // 0x80037A24: b           L_80037A54
    // 0x80037A28: sh          $zero, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = 0;
        goto L_80037A54;
    // 0x80037A28: sh          $zero, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = 0;
L_80037A2C:
    // 0x80037A2C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80037A30: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x80037A34: lhu         $t4, 0x6($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X6);
    // 0x80037A38: nop

    // 0x80037A3C: sh          $t4, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r12;
    // 0x80037A40: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80037A44: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80037A48: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x80037A4C: nop

    // 0x80037A50: sh          $t6, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = ctx->r14;
L_80037A54:
    // 0x80037A54: jal         0x800C1754
    // 0x80037A58: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_16;
    // 0x80037A58: nop

    after_16:
    // 0x80037A5C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80037A60: lw          $t7, 0x7214($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7214);
    // 0x80037A64: nop

    // 0x80037A68: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x80037A6C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80037A70: nop

    // 0x80037A74: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80037A78: nop

    // 0x80037A7C: sh          $t9, 0xFA($sp)
    MEM_H(0XFA, ctx->r29) = ctx->r25;
    // 0x80037A80: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80037A84: lhu         $t0, 0x728E($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X728E);
    // 0x80037A88: nop

    // 0x80037A8C: andi        $t2, $t0, 0x4
    ctx->r10 = ctx->r8 & 0X4;
    // 0x80037A90: beq         $t2, $zero, L_80037AA8
    if (ctx->r10 == 0) {
        // 0x80037A94: nop
    
            goto L_80037AA8;
    }
    // 0x80037A94: nop

    // 0x80037A98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80037A9C: nop

    // 0x80037AA0: swc1        $f4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f4.u32l;
    // 0x80037AA4: swc1        $f4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f4.u32l;
L_80037AA8:
    // 0x80037AA8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80037AAC: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x80037AB0: nop

    // 0x80037AB4: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80037AB8: nop

    // 0x80037ABC: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80037AC0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80037AC4: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x80037AC8: nop

    // 0x80037ACC: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80037AD0: nop

    // 0x80037AD4: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x80037AD8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80037ADC: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x80037AE0: nop

    // 0x80037AE4: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80037AE8: nop

    // 0x80037AEC: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x80037AF0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80037AF4: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x80037AF8: nop

    // 0x80037AFC: lwc1        $f16, 0xC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80037B00: nop

    // 0x80037B04: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
    // 0x80037B08: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80037B0C: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x80037B10: nop

    // 0x80037B14: lwc1        $f18, 0x10($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80037B18: nop

    // 0x80037B1C: swc1        $f18, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f18.u32l;
    // 0x80037B20: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80037B24: lw          $t7, 0x7278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7278);
    // 0x80037B28: nop

    // 0x80037B2C: lwc1        $f4, 0x14($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X14);
    // 0x80037B30: nop

    // 0x80037B34: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
    // 0x80037B38: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80037B3C: lw          $t8, 0x7278($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7278);
    // 0x80037B40: nop

    // 0x80037B44: lwc1        $f6, 0x18($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X18);
    // 0x80037B48: nop

    // 0x80037B4C: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x80037B50: lwc1        $f12, 0xE8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80037B54: jal         0x800C23E8
    // 0x80037B58: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_17;
    // 0x80037B58: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_17:
    // 0x80037B5C: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80037B60: jal         0x800C2780
    // 0x80037B64: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateZ(rdram, ctx);
        goto after_18;
    // 0x80037B64: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_18:
    // 0x80037B68: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80037B6C: jal         0x800C25B8
    // 0x80037B70: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_19;
    // 0x80037B70: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_19:
    // 0x80037B74: lwc1        $f8, 0xEC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80037B78: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80037B7C: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80037B80: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80037B84: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80037B88: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80037B8C: jal         0x800C2304
    // 0x80037B90: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_20;
    // 0x80037B90: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_20:
    // 0x80037B94: jal         0x800C1A84
    // 0x80037B98: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_21;
    // 0x80037B98: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_21:
    // 0x80037B9C: jal         0x800AD680
    // 0x80037BA0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800AD680(rdram, ctx);
        goto after_22;
    // 0x80037BA0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_22:
    // 0x80037BA4: jal         0x800C1850
    // 0x80037BA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_23;
    // 0x80037BA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80037BAC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80037BB0: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80037BB4: jal         0x800AD1E4
    // 0x80037BB8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_24;
    // 0x80037BB8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_24:
    // 0x80037BBC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80037BC0: lw          $t9, -0x4CCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CCC);
    // 0x80037BC4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80037BC8: subu        $t2, $t0, $t9
    ctx->r10 = SUB32(ctx->r8, ctx->r25);
    // 0x80037BCC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80037BD0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80037BD4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80037BD8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80037BDC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80037BE0: jal         0x800C2304
    // 0x80037BE4: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_25;
    // 0x80037BE4: nop

    after_25:
    // 0x80037BE8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80037BEC: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x80037BF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037BF4: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80037BF8: sw          $t1, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r9;
    // 0x80037BFC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80037C00: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80037C04: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80037C08: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80037C0C: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x80037C10: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x80037C14: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80037C18: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80037C1C: addiu       $t6, $t6, 0x158
    ctx->r14 = ADD32(ctx->r14, 0X158);
    // 0x80037C20: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80037C24: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80037C28: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80037C2C: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x80037C30: addiu       $a1, $a1, 0x2D8
    ctx->r5 = ADD32(ctx->r5, 0X2D8);
    // 0x80037C34: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80037C38: jal         0x800B18C4
    // 0x80037C3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800B18C4(rdram, ctx);
        goto after_26;
    // 0x80037C3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_26:
    // 0x80037C40: jal         0x800C1850
    // 0x80037C44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_27;
    // 0x80037C44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x80037C48: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80037C4C: addiu       $t0, $t0, 0x2618
    ctx->r8 = ADD32(ctx->r8, 0X2618);
    // 0x80037C50: lw          $t9, 0x1C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X1C);
    // 0x80037C54: nop

    // 0x80037C58: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80037C5C: jal         0x8009A14C
    // 0x80037C60: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8009A14C(rdram, ctx);
        goto after_28;
    // 0x80037C60: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_28:
    // 0x80037C64: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80037C68: jal         0x800C2780
    // 0x80037C6C: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_29;
    // 0x80037C6C: nop

    after_29:
    // 0x80037C70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80037C74: jal         0x800997D8
    // 0x80037C78: nop

    func_800997D8(rdram, ctx);
        goto after_30;
    // 0x80037C78: nop

    after_30:
    // 0x80037C7C: jal         0x80037344
    // 0x80037C80: nop

    func_80037344(rdram, ctx);
        goto after_31;
    // 0x80037C80: nop

    after_31:
    // 0x80037C84: jal         0x800C1AF4
    // 0x80037C88: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_32;
    // 0x80037C88: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_32:
    // 0x80037C8C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80037C90: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80037C94: lui         $at, 0x4516
    ctx->r1 = S32(0X4516 << 16);
    // 0x80037C98: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80037C9C: jal         0x800AF184
    // 0x80037CA0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_800AF184(rdram, ctx);
        goto after_33;
    // 0x80037CA0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_33:
    // 0x80037CA4: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80037CA8: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80037CAC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80037CB0: jal         0x80034F90
    // 0x80037CB4: nop

    func_80034F90(rdram, ctx);
        goto after_34;
    // 0x80037CB4: nop

    after_34:
    // 0x80037CB8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80037CBC: lw          $t2, 0x71FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71FC);
    // 0x80037CC0: lwc1        $f18, 0xEC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80037CC4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80037CC8: lw          $a3, 0xF4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF4);
    // 0x80037CCC: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80037CD0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80037CD4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80037CD8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80037CDC: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    // 0x80037CE0: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x80037CE4: jal         0x800349C0
    // 0x80037CE8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800349C0(rdram, ctx);
        goto after_35;
    // 0x80037CE8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_35:
    // 0x80037CEC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80037CF0: lw          $t4, 0x7260($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7260);
    // 0x80037CF4: nop

    // 0x80037CF8: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x80037CFC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80037D00: lw          $t5, 0x72C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72C8);
    // 0x80037D04: nop

    // 0x80037D08: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x80037D0C: jal         0x800C1850
    // 0x80037D10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_36;
    // 0x80037D10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x80037D14: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80037D18: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80037D1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037D20: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80037D24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037D28: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80037D2C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80037D30: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80037D34: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80037D38: jal         0x800C2304
    // 0x80037D3C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_37;
    // 0x80037D3C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_37:
    // 0x80037D40: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80037D44: jal         0x800A4638
    // 0x80037D48: nop

    func_800A4638(rdram, ctx);
        goto after_38;
    // 0x80037D48: nop

    after_38:
    // 0x80037D4C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80037D50: nop

    // 0x80037D54: addiu       $t8, $t7, 0x118
    ctx->r24 = ADD32(ctx->r15, 0X118);
    // 0x80037D58: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80037D5C: jal         0x800C1850
    // 0x80037D60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_39;
    // 0x80037D60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_39:
    // 0x80037D64: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80037D68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037D6C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80037D70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80037D74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037D78: lwc1        $f8, -0x15C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X15C0);
    // 0x80037D7C: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80037D80: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80037D84: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80037D88: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80037D8C: jal         0x800C2304
    // 0x80037D90: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_40;
    // 0x80037D90: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_40:
    // 0x80037D94: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80037D98: jal         0x800A4638
    // 0x80037D9C: nop

    func_800A4638(rdram, ctx);
        goto after_41;
    // 0x80037D9C: nop

    after_41:
    // 0x80037DA0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80037DA4: nop

    // 0x80037DA8: addiu       $t2, $t9, 0x118
    ctx->r10 = ADD32(ctx->r25, 0X118);
    // 0x80037DAC: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80037DB0: jal         0x800C1850
    // 0x80037DB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_42;
    // 0x80037DB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_42:
    // 0x80037DB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037DBC: lwc1        $f18, -0x15BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X15BC);
    // 0x80037DC0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80037DC4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80037DC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037DCC: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80037DD0: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80037DD4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80037DD8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80037DDC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80037DE0: jal         0x800C2304
    // 0x80037DE4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_43;
    // 0x80037DE4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_43:
    // 0x80037DE8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80037DEC: jal         0x800A4638
    // 0x80037DF0: nop

    func_800A4638(rdram, ctx);
        goto after_44;
    // 0x80037DF0: nop

    after_44:
    // 0x80037DF4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80037DF8: nop

    // 0x80037DFC: addiu       $t4, $t1, 0x118
    ctx->r12 = ADD32(ctx->r9, 0X118);
    // 0x80037E00: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80037E04: jal         0x800C1850
    // 0x80037E08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_45;
    // 0x80037E08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_45:
    // 0x80037E0C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037E10: lwc1        $f16, -0x15B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X15B8);
    // 0x80037E14: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80037E18: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80037E1C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80037E20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037E24: lwc1        $f4, -0x15B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X15B4);
    // 0x80037E28: lwc1        $f18, 0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80037E2C: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80037E30: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80037E34: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80037E38: jal         0x800C2304
    // 0x80037E3C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_46;
    // 0x80037E3C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_46:
    // 0x80037E40: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80037E44: jal         0x800A4638
    // 0x80037E48: nop

    func_800A4638(rdram, ctx);
        goto after_47;
    // 0x80037E48: nop

    after_47:
    // 0x80037E4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037E50: lwc1        $f8, 0x50C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80037E54: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80037E58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80037E5C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80037E60: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80037E64: nop

    // 0x80037E68: bc1f        L_80037EB4
    if (!c1cs) {
        // 0x80037E6C: nop
    
            goto L_80037EB4;
    }
    // 0x80037E6C: nop

    // 0x80037E70: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037E74: lwc1        $f19, -0x15B0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X15B0);
    // 0x80037E78: lwc1        $f18, -0x15AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X15AC);
    // 0x80037E7C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80037E80: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x80037E84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80037E88: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80037E8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037E90: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80037E94: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80037E98: swc1        $f6, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f6.u32l;
    // 0x80037E9C: bc1f        L_80037EB4
    if (!c1cs) {
        // 0x80037EA0: nop
    
            goto L_80037EB4;
    }
    // 0x80037EA0: nop

    // 0x80037EA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80037EA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037EAC: b           L_80037F18
    // 0x80037EB0: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
        goto L_80037F18;
    // 0x80037EB0: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
L_80037EB4:
    // 0x80037EB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037EB8: lwc1        $f18, 0x50C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80037EBC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80037EC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80037EC4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80037EC8: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80037ECC: nop

    // 0x80037ED0: bc1f        L_80037F18
    if (!c1cs) {
        // 0x80037ED4: nop
    
            goto L_80037F18;
    }
    // 0x80037ED4: nop

    // 0x80037ED8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037EDC: lwc1        $f9, -0x15A8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X15A8);
    // 0x80037EE0: lwc1        $f8, -0x15A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X15A4);
    // 0x80037EE4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80037EE8: add.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d + ctx->f8.d;
    // 0x80037EEC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80037EF0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80037EF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037EF8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80037EFC: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x80037F00: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
    // 0x80037F04: bc1f        L_80037F18
    if (!c1cs) {
        // 0x80037F08: nop
    
            goto L_80037F18;
    }
    // 0x80037F08: nop

    // 0x80037F0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80037F10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037F14: swc1        $f4, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f4.u32l;
L_80037F18:
    // 0x80037F18: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80037F1C: lwc1        $f16, 0xC0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80037F20: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80037F24: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80037F28: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80037F2C: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    // 0x80037F30: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80037F34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037F38: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80037F3C: nop

    // 0x80037F40: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x80037F44: nop

    // 0x80037F48: bc1f        L_80037F98
    if (!c1cs) {
        // 0x80037F4C: nop
    
            goto L_80037F98;
    }
    // 0x80037F4C: nop

    // 0x80037F50: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80037F54: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80037F58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80037F5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80037F60: c.le.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d <= ctx->f18.d;
    // 0x80037F64: nop

    // 0x80037F68: bc1f        L_80037F98
    if (!c1cs) {
        // 0x80037F6C: nop
    
            goto L_80037F98;
    }
    // 0x80037F6C: nop

    // 0x80037F70: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80037F74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80037F78: nop

    // 0x80037F7C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80037F80: nop

    // 0x80037F84: bc1f        L_80037F98
    if (!c1cs) {
        // 0x80037F88: nop
    
            goto L_80037F98;
    }
    // 0x80037F88: nop

    // 0x80037F8C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80037F90: nop

    // 0x80037F94: swc1        $f8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f8.u32l;
L_80037F98:
    // 0x80037F98: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80037F9C: lwc1        $f18, 0xC0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80037FA0: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80037FA4: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80037FA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037FAC: lwc1        $f17, -0x15A0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X15A0);
    // 0x80037FB0: lwc1        $f16, -0x159C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X159C);
    // 0x80037FB4: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80037FB8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80037FBC: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x80037FC0: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x80037FC4: bc1f        L_80037FDC
    if (!c1cs) {
        // 0x80037FC8: nop
    
            goto L_80037FDC;
    }
    // 0x80037FC8: nop

    // 0x80037FCC: lui         $at, 0x42A4
    ctx->r1 = S32(0X42A4 << 16);
    // 0x80037FD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80037FD4: b           L_80038010
    // 0x80037FD8: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
        goto L_80038010;
    // 0x80037FD8: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_80037FDC:
    // 0x80037FDC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80037FE0: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80037FE4: lwc1        $f5, -0x1598($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1598);
    // 0x80037FE8: lwc1        $f4, -0x1594($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1594);
    // 0x80037FEC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80037FF0: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x80037FF4: nop

    // 0x80037FF8: bc1f        L_80038010
    if (!c1cs) {
        // 0x80037FFC: nop
    
            goto L_80038010;
    }
    // 0x80037FFC: nop

    // 0x80038000: lui         $at, 0xC2A4
    ctx->r1 = S32(0XC2A4 << 16);
    // 0x80038004: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80038008: nop

    // 0x8003800C: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
L_80038010:
    // 0x80038010: jal         0x800C1850
    // 0x80038014: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_48;
    // 0x80038014: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_48:
    // 0x80038018: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8003801C: jal         0x800C25B8
    // 0x80038020: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_49;
    // 0x80038020: nop

    after_49:
    // 0x80038024: lwc1        $f12, 0xE8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80038028: jal         0x800C23E8
    // 0x8003802C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_50;
    // 0x8003802C: nop

    after_50:
    // 0x80038030: jal         0x800C1680
    // 0x80038034: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_51;
    // 0x80038034: nop

    after_51:
    // 0x80038038: jal         0x800C1680
    // 0x8003803C: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_52;
    // 0x8003803C: nop

    after_52:
    // 0x80038040: jal         0x800C1680
    // 0x80038044: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_53;
    // 0x80038044: nop

    after_53:
    // 0x80038048: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003804C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80038050: jal         0x800C2304
    // 0x80038054: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_54;
    // 0x80038054: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_54:
    // 0x80038058: jal         0x800B1844
    // 0x8003805C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800B1844(rdram, ctx);
        goto after_55;
    // 0x8003805C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_55:
    // 0x80038060: addiu       $t6, $sp, 0x74
    ctx->r14 = ADD32(ctx->r29, 0X74);
    // 0x80038064: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80038068: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003806C: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80038070: nop

    // 0x80038074: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80038078: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x8003807C: addiu       $t7, $sp, 0x74
    ctx->r15 = ADD32(ctx->r29, 0X74);
    // 0x80038080: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80038084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038088: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8003808C: nop

    // 0x80038090: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80038094: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    // 0x80038098: addiu       $t8, $sp, 0x74
    ctx->r24 = ADD32(ctx->r29, 0X74);
    // 0x8003809C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800380A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800380A4: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800380A8: nop

    // 0x800380AC: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800380B0: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x800380B4: jal         0x800C1A28
    // 0x800380B8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_56;
    // 0x800380B8: nop

    after_56:
    // 0x800380BC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800380C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800380C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800380C8: jal         0x800C2304
    // 0x800380CC: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_57;
    // 0x800380CC: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_57:
    // 0x800380D0: jal         0x800B1844
    // 0x800380D4: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800B1844(rdram, ctx);
        goto after_58;
    // 0x800380D4: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_58:
    // 0x800380D8: jal         0x800C1A28
    // 0x800380DC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_59;
    // 0x800380DC: nop

    after_59:
    // 0x800380E0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x800380E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800380E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800380EC: jal         0x800C2304
    // 0x800380F0: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_60;
    // 0x800380F0: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_60:
    // 0x800380F4: jal         0x800B1844
    // 0x800380F8: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_800B1844(rdram, ctx);
        goto after_61;
    // 0x800380F8: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_61:
    // 0x800380FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038100: lwc1        $f10, -0x76B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80038104: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80038108: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003810C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80038110: c.eq.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d == ctx->f8.d;
    // 0x80038114: nop

    // 0x80038118: bc1t        L_800382A4
    if (c1cs) {
        // 0x8003811C: nop
    
            goto L_800382A4;
    }
    // 0x8003811C: nop

    // 0x80038120: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80038124: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80038128: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8003812C: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80038130: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80038134: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80038138: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003813C: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80038140: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80038144: jal         0x80034CA0
    // 0x80038148: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    func_80034CA0(rdram, ctx);
        goto after_62;
    // 0x80038148: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    after_62:
    // 0x8003814C: bne         $v0, $zero, L_8003821C
    if (ctx->r2 != 0) {
        // 0x80038150: nop
    
            goto L_8003821C;
    }
    // 0x80038150: nop

    // 0x80038154: addiu       $t0, $sp, 0x74
    ctx->r8 = ADD32(ctx->r29, 0X74);
    // 0x80038158: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003815C: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80038160: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80038164: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80038168: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003816C: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80038170: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80038174: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80038178: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8003817C: jal         0x80034CA0
    // 0x80038180: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    func_80034CA0(rdram, ctx);
        goto after_63;
    // 0x80038180: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    after_63:
    // 0x80038184: bne         $v0, $zero, L_8003821C
    if (ctx->r2 != 0) {
        // 0x80038188: nop
    
            goto L_8003821C;
    }
    // 0x80038188: nop

    // 0x8003818C: addiu       $t9, $sp, 0x68
    ctx->r25 = ADD32(ctx->r29, 0X68);
    // 0x80038190: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80038194: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80038198: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8003819C: lwc1        $f18, 0xEC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800381A0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800381A4: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800381A8: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800381AC: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800381B0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800381B4: jal         0x80034CA0
    // 0x800381B8: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    func_80034CA0(rdram, ctx);
        goto after_64;
    // 0x800381B8: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    after_64:
    // 0x800381BC: bne         $v0, $zero, L_8003821C
    if (ctx->r2 != 0) {
        // 0x800381C0: nop
    
            goto L_8003821C;
    }
    // 0x800381C0: nop

    // 0x800381C4: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800381C8: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800381CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800381D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800381D4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800381D8: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800381DC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800381E0: jal         0x80034CA0
    // 0x800381E4: add.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f16.fl;
    func_80034CA0(rdram, ctx);
        goto after_65;
    // 0x800381E4: add.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f16.fl;
    after_65:
    // 0x800381E8: bne         $v0, $zero, L_8003821C
    if (ctx->r2 != 0) {
        // 0x800381EC: nop
    
            goto L_8003821C;
    }
    // 0x800381EC: nop

    // 0x800381F0: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800381F4: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800381F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800381FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038200: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80038204: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80038208: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x8003820C: jal         0x80034CA0
    // 0x80038210: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    func_80034CA0(rdram, ctx);
        goto after_66;
    // 0x80038210: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    after_66:
    // 0x80038214: beq         $v0, $zero, L_800382A4
    if (ctx->r2 == 0) {
        // 0x80038218: nop
    
            goto L_800382A4;
    }
    // 0x80038218: nop

L_8003821C:
    // 0x8003821C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80038220: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038224: swc1        $f8, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f8.u32l;
    // 0x80038228: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003822C: lhu         $t2, 0x728E($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X728E);
    // 0x80038230: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038234: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80038238: sh          $t3, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r11;
    // 0x8003823C: jal         0x800B9000
    // 0x80038240: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800B9000(rdram, ctx);
        goto after_67;
    // 0x80038240: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_67:
    // 0x80038244: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80038248: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x8003824C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80038250: lhu         $t4, 0x1C($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X1C);
    // 0x80038254: nop

    // 0x80038258: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8003825C: sh          $t5, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r13;
    // 0x80038260: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x80038264: nop

    // 0x80038268: lhu         $t7, 0x1C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1C);
    // 0x8003826C: nop

    // 0x80038270: bne         $t7, $zero, L_8003828C
    if (ctx->r15 != 0) {
        // 0x80038274: nop
    
            goto L_8003828C;
    }
    // 0x80038274: nop

    // 0x80038278: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003827C: lhu         $t8, 0x728E($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X728E);
    // 0x80038280: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038284: ori         $t0, $t8, 0xC
    ctx->r8 = ctx->r24 | 0XC;
    // 0x80038288: sh          $t0, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r8;
L_8003828C:
    // 0x8003828C: jal         0x80035CF8
    // 0x80038290: nop

    func_80035CF8(rdram, ctx);
        goto after_68;
    // 0x80038290: nop

    after_68:
    // 0x80038294: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038298: lwc1        $f16, -0x1590($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1590);
    // 0x8003829C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800382A0: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
L_800382A4:
    // 0x800382A4: jal         0x800C1A28
    // 0x800382A8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_69;
    // 0x800382A8: nop

    after_69:
    // 0x800382AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800382B0: lwc1        $f18, -0x76B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800382B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800382B8: lwc1        $f6, 0x50C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x800382BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800382C0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800382C4: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800382C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800382CC: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800382D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800382D4: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800382D8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800382DC: jal         0x800C2304
    // 0x800382E0: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_70;
    // 0x800382E0: nop

    after_70:
    // 0x800382E4: jal         0x800B1844
    // 0x800382E8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800B1844(rdram, ctx);
        goto after_71;
    // 0x800382E8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_71:
    // 0x800382EC: addiu       $t9, $sp, 0x74
    ctx->r25 = ADD32(ctx->r29, 0X74);
    // 0x800382F0: lwc1        $f20, 0x0($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800382F4: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800382F8: swc1        $f20, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f20.u32l;
    // 0x800382FC: add.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x80038300: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80038304: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80038308: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8003830C: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80038310: nop

    // 0x80038314: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80038318: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
    // 0x8003831C: addiu       $t3, $sp, 0x74
    ctx->r11 = ADD32(ctx->r29, 0X74);
    // 0x80038320: lwc1        $f20, 0x8($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80038324: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80038328: swc1        $f20, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f20.u32l;
    // 0x8003832C: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80038330: swc1        $f18, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f18.u32l;
    // 0x80038334: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80038338: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8003833C: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80038340: nop

    // 0x80038344: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80038348: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x8003834C: addiu       $t5, $sp, 0x74
    ctx->r13 = ADD32(ctx->r29, 0X74);
    // 0x80038350: lwc1        $f16, 0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80038354: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80038358: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003835C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038360: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80038364: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x80038368: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x8003836C: bc1f        L_800383E0
    if (!c1cs) {
        // 0x80038370: nop
    
            goto L_800383E0;
    }
    // 0x80038370: nop

    // 0x80038374: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80038378: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003837C: nop

    // 0x80038380: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80038384: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80038388: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003838C: nop

    // 0x80038390: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80038394: nop

    // 0x80038398: bc1f        L_800383E0
    if (!c1cs) {
        // 0x8003839C: nop
    
            goto L_800383E0;
    }
    // 0x8003839C: nop

    // 0x800383A0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800383A4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800383A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800383AC: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800383B0: sub.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d - ctx->f18.d;
    // 0x800383B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800383B8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800383BC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800383C0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800383C4: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x800383C8: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x800383CC: bc1f        L_800383E0
    if (!c1cs) {
        // 0x800383D0: nop
    
            goto L_800383E0;
    }
    // 0x800383D0: nop

    // 0x800383D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800383D8: nop

    // 0x800383DC: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
L_800383E0:
    // 0x800383E0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800383E4: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800383E8: lhu         $t6, 0x0($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X0);
    // 0x800383EC: nop

    // 0x800383F0: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x800383F4: beq         $t7, $zero, L_80038428
    if (ctx->r15 == 0) {
        // 0x800383F8: nop
    
            goto L_80038428;
    }
    // 0x800383F8: nop

    // 0x800383FC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80038400: lw          $t8, 0x7278($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7278);
    // 0x80038404: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80038408: lhu         $t0, 0x1C($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X1C);
    // 0x8003840C: nop

    // 0x80038410: beq         $t0, $at, L_80038428
    if (ctx->r8 == ctx->r1) {
        // 0x80038414: nop
    
            goto L_80038428;
    }
    // 0x80038414: nop

    // 0x80038418: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003841C: lw          $t2, 0x7278($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7278);
    // 0x80038420: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80038424: sh          $t9, 0x1C($t2)
    MEM_H(0X1C, ctx->r10) = ctx->r25;
L_80038428:
    // 0x80038428: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8003842C: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80038430: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80038434: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80038438: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003843C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80038440: c.eq.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d == ctx->f4.d;
    // 0x80038444: nop

    // 0x80038448: bc1f        L_80038520
    if (!c1cs) {
        // 0x8003844C: nop
    
            goto L_80038520;
    }
    // 0x8003844C: nop

    // 0x80038450: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80038454: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80038458: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003845C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80038460: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x80038464: nop

    // 0x80038468: bc1t        L_80038520
    if (c1cs) {
        // 0x8003846C: nop
    
            goto L_80038520;
    }
    // 0x8003846C: nop

    // 0x80038470: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80038474: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80038478: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003847C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80038480: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80038484: nop

    // 0x80038488: bc1f        L_800384DC
    if (!c1cs) {
        // 0x8003848C: nop
    
            goto L_800384DC;
    }
    // 0x8003848C: nop

    // 0x80038490: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80038494: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80038498: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8003849C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800384A0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800384A4: sub.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d - ctx->f6.d;
    // 0x800384A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800384AC: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800384B0: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x800384B4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800384B8: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x800384BC: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x800384C0: bc1f        L_800384D4
    if (!c1cs) {
        // 0x800384C4: nop
    
            goto L_800384D4;
    }
    // 0x800384C4: nop

    // 0x800384C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800384CC: nop

    // 0x800384D0: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800384D4:
    // 0x800384D4: b           L_80038520
    // 0x800384D8: nop

        goto L_80038520;
    // 0x800384D8: nop

L_800384DC:
    // 0x800384DC: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800384E0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800384E4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800384E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800384EC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800384F0: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x800384F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800384F8: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x800384FC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80038500: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80038504: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x80038508: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
    // 0x8003850C: bc1f        L_80038520
    if (!c1cs) {
        // 0x80038510: nop
    
            goto L_80038520;
    }
    // 0x80038510: nop

    // 0x80038514: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80038518: nop

    // 0x8003851C: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_80038520:
    // 0x80038520: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80038524: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80038528: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003852C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80038530: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80038534: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x80038538: nop

    // 0x8003853C: bc1f        L_800385E4
    if (!c1cs) {
        // 0x80038540: nop
    
            goto L_800385E4;
    }
    // 0x80038540: nop

    // 0x80038544: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80038548: lhu         $t3, 0x728E($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X728E);
    // 0x8003854C: nop

    // 0x80038550: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80038554: bne         $t4, $zero, L_800385E4
    if (ctx->r12 != 0) {
        // 0x80038558: nop
    
            goto L_800385E4;
    }
    // 0x80038558: nop

    // 0x8003855C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038560: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038564: swc1        $f18, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f18.u32l;
    // 0x80038568: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003856C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038570: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038574: swc1        $f6, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f6.u32l;
    // 0x80038578: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8003857C: lhu         $t5, 0x728E($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X728E);
    // 0x80038580: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038584: ori         $t1, $t5, 0x2
    ctx->r9 = ctx->r13 | 0X2;
    // 0x80038588: sh          $t1, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r9;
    // 0x8003858C: jal         0x800B9000
    // 0x80038590: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800B9000(rdram, ctx);
        goto after_72;
    // 0x80038590: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_72:
    // 0x80038594: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80038598: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x8003859C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800385A0: lhu         $t7, 0x1C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1C);
    // 0x800385A4: nop

    // 0x800385A8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800385AC: sh          $t8, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = ctx->r24;
    // 0x800385B0: lw          $t0, 0x7278($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7278);
    // 0x800385B4: nop

    // 0x800385B8: lhu         $t9, 0x1C($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X1C);
    // 0x800385BC: nop

    // 0x800385C0: bne         $t9, $zero, L_800385DC
    if (ctx->r25 != 0) {
        // 0x800385C4: nop
    
            goto L_800385DC;
    }
    // 0x800385C4: nop

    // 0x800385C8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800385CC: lhu         $t2, 0x728E($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X728E);
    // 0x800385D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800385D4: ori         $t3, $t2, 0xC
    ctx->r11 = ctx->r10 | 0XC;
    // 0x800385D8: sh          $t3, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r11;
L_800385DC:
    // 0x800385DC: jal         0x80035CF8
    // 0x800385E0: nop

    func_80035CF8(rdram, ctx);
        goto after_73;
    // 0x800385E0: nop

    after_73:
L_800385E4:
    // 0x800385E4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800385E8: lhu         $t4, 0x728E($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X728E);
    // 0x800385EC: nop

    // 0x800385F0: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800385F4: bne         $t5, $zero, L_800386E8
    if (ctx->r13 != 0) {
        // 0x800385F8: nop
    
            goto L_800386E8;
    }
    // 0x800385F8: nop

    // 0x800385FC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80038600: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80038604: lhu         $t1, 0xFC($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XFC);
    // 0x80038608: nop

    // 0x8003860C: and         $t8, $t1, $t7
    ctx->r24 = ctx->r9 & ctx->r15;
    // 0x80038610: beq         $t8, $zero, L_80038678
    if (ctx->r24 == 0) {
        // 0x80038614: nop
    
            goto L_80038678;
    }
    // 0x80038614: nop

    // 0x80038618: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003861C: lwc1        $f10, -0x76B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80038620: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038624: lwc1        $f5, -0x1588($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1588);
    // 0x80038628: lwc1        $f4, -0x1584($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1584);
    // 0x8003862C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80038630: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x80038634: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038638: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8003863C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80038640: swc1        $f18, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f18.u32l;
    // 0x80038644: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80038648: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003864C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80038650: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x80038654: nop

    // 0x80038658: bc1f        L_80038670
    if (!c1cs) {
        // 0x8003865C: nop
    
            goto L_80038670;
    }
    // 0x8003865C: nop

    // 0x80038660: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038664: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80038668: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003866C: swc1        $f8, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f8.u32l;
L_80038670:
    // 0x80038670: b           L_800386E8
    // 0x80038674: nop

        goto L_800386E8;
    // 0x80038674: nop

L_80038678:
    // 0x80038678: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8003867C: lhu         $t0, 0x101C($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X101C);
    // 0x80038680: lhu         $t6, 0xFC($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XFC);
    // 0x80038684: nop

    // 0x80038688: and         $t9, $t6, $t0
    ctx->r25 = ctx->r14 & ctx->r8;
    // 0x8003868C: beq         $t9, $zero, L_800386E8
    if (ctx->r25 == 0) {
        // 0x80038690: nop
    
            goto L_800386E8;
    }
    // 0x80038690: nop

    // 0x80038694: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038698: lwc1        $f4, -0x76B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x8003869C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800386A0: lwc1        $f19, -0x1580($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1580);
    // 0x800386A4: lwc1        $f18, -0x157C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X157C);
    // 0x800386A8: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800386AC: sub.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d - ctx->f18.d;
    // 0x800386B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800386B4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800386B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800386BC: swc1        $f10, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f10.u32l;
    // 0x800386C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800386C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800386C8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800386CC: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x800386D0: nop

    // 0x800386D4: bc1f        L_800386E8
    if (!c1cs) {
        // 0x800386D8: nop
    
            goto L_800386E8;
    }
    // 0x800386D8: nop

    // 0x800386DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800386E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800386E4: swc1        $f16, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f16.u32l;
L_800386E8:
    // 0x800386E8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800386EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800386F0: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800386F4: lwc1        $f11, -0x1578($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1578);
    // 0x800386F8: lwc1        $f10, -0x1574($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1574);
    // 0x800386FC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80038700: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80038704: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80038708: swc1        $f4, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f4.u32l;
    // 0x8003870C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80038710: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038714: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80038718: lwc1        $f7, -0x1570($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1570);
    // 0x8003871C: lwc1        $f6, -0x156C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X156C);
    // 0x80038720: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80038724: add.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d + ctx->f6.d;
    // 0x80038728: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8003872C: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x80038730: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80038734: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038738: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003873C: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80038740: nop

    // 0x80038744: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80038748: nop

    // 0x8003874C: bc1f        L_8003878C
    if (!c1cs) {
        // 0x80038750: nop
    
            goto L_8003878C;
    }
    // 0x80038750: nop

    // 0x80038754: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80038758: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003875C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038760: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80038764: nop

    // 0x80038768: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003876C: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80038770: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80038774: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038778: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003877C: lwc1        $f8, 0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X10);
    // 0x80038780: nop

    // 0x80038784: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80038788: swc1        $f16, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f16.u32l;
L_8003878C:
    // 0x8003878C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80038790: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038794: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038798: lwc1        $f18, 0x8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8003879C: nop

    // 0x800387A0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x800387A4: nop

    // 0x800387A8: bc1f        L_800387EC
    if (!c1cs) {
        // 0x800387AC: nop
    
            goto L_800387EC;
    }
    // 0x800387AC: nop

    // 0x800387B0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800387B4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800387B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800387BC: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800387C0: nop

    // 0x800387C4: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800387C8: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800387CC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800387D0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800387D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800387D8: lwc1        $f16, 0x8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800387DC: nop

    // 0x800387E0: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800387E4: b           L_80038848
    // 0x800387E8: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
        goto L_80038848;
    // 0x800387E8: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
L_800387EC:
    // 0x800387EC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800387F0: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800387F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800387F8: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800387FC: nop

    // 0x80038800: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80038804: nop

    // 0x80038808: bc1f        L_80038848
    if (!c1cs) {
        // 0x8003880C: nop
    
            goto L_80038848;
    }
    // 0x8003880C: nop

    // 0x80038810: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80038814: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038818: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003881C: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80038820: nop

    // 0x80038824: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80038828: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x8003882C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80038830: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038834: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038838: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8003883C: nop

    // 0x80038840: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80038844: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
L_80038848:
    // 0x80038848: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8003884C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038850: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80038854: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80038858: nop

    // 0x8003885C: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80038860: nop

    // 0x80038864: bc1f        L_800388A8
    if (!c1cs) {
        // 0x80038868: nop
    
            goto L_800388A8;
    }
    // 0x80038868: nop

    // 0x8003886C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80038870: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038878: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8003887C: nop

    // 0x80038880: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80038884: swc1        $f10, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f10.u32l;
    // 0x80038888: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8003888C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038890: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038894: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80038898: nop

    // 0x8003889C: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800388A0: b           L_80038904
    // 0x800388A4: swc1        $f16, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f16.u32l;
        goto L_80038904;
    // 0x800388A4: swc1        $f16, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f16.u32l;
L_800388A8:
    // 0x800388A8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800388AC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800388B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800388B4: lwc1        $f18, 0xC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800388B8: nop

    // 0x800388BC: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800388C0: nop

    // 0x800388C4: bc1f        L_80038904
    if (!c1cs) {
        // 0x800388C8: nop
    
            goto L_80038904;
    }
    // 0x800388C8: nop

    // 0x800388CC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800388D0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800388D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800388D8: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800388DC: nop

    // 0x800388E0: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800388E4: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x800388E8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800388EC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800388F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800388F4: lwc1        $f16, 0xC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800388F8: nop

    // 0x800388FC: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80038900: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
L_80038904:
    // 0x80038904: lhu         $t6, 0xFA($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XFA);
    // 0x80038908: nop

    // 0x8003890C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80038910: beq         $at, $zero, L_80038E94
    if (ctx->r1 == 0) {
        // 0x80038914: nop
    
            goto L_80038E94;
    }
    // 0x80038914: nop

    // 0x80038918: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003891C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038920: addu        $at, $at, $t6
    gpr jr_addend_8003892C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80038924: lw          $t6, -0x1568($at)
    ctx->r14 = ADD32(ctx->r1, -0X1568);
    // 0x80038928: nop

    // 0x8003892C: jr          $t6
    // 0x80038930: nop

    switch (jr_addend_8003892C >> 2) {
        case 0: goto L_80038934; break;
        case 1: goto L_80038AEC; break;
        case 2: goto L_80038D10; break;
        case 3: goto L_80038D7C; break;
        case 4: goto L_80038E34; break;
        default: switch_error(__func__, 0x8003892C, 0x800EEA98);
    }
    // 0x80038930: nop

L_80038934:
    // 0x80038934: jal         0x8005F064
    // 0x80038938: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    func_8005F064(rdram, ctx);
        goto after_74;
    // 0x80038938: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    after_74:
    // 0x8003893C: bne         $v0, $zero, L_80038AE4
    if (ctx->r2 != 0) {
        // 0x80038940: nop
    
            goto L_80038AE4;
    }
    // 0x80038940: nop

    // 0x80038944: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80038948: lh          $t0, 0x7254($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7254);
    // 0x8003894C: nop

    // 0x80038950: andi        $t9, $t0, 0x8000
    ctx->r25 = ctx->r8 & 0X8000;
    // 0x80038954: bne         $t9, $zero, L_80038AE4
    if (ctx->r25 != 0) {
        // 0x80038958: nop
    
            goto L_80038AE4;
    }
    // 0x80038958: nop

    // 0x8003895C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80038960: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80038964: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80038968: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8003896C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80038970: lwc1        $f19, -0x1550($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1550);
    // 0x80038974: lwc1        $f18, -0x154C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X154C);
    // 0x80038978: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8003897C: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x80038980: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x80038984: bc1f        L_800389AC
    if (!c1cs) {
        // 0x80038988: nop
    
            goto L_800389AC;
    }
    // 0x80038988: nop

    // 0x8003898C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038990: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80038994: lwc1        $f9, -0x1548($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1548);
    // 0x80038998: lwc1        $f8, -0x1544($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1544);
    // 0x8003899C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800389A0: sub.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d - ctx->f8.d;
    // 0x800389A4: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x800389A8: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
L_800389AC:
    // 0x800389AC: jal         0x80031AC8
    // 0x800389B0: nop

    func_80031AC8(rdram, ctx);
        goto after_75;
    // 0x800389B0: nop

    after_75:
    // 0x800389B4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800389B8: bne         $v0, $at, L_80038AE4
    if (ctx->r2 != ctx->r1) {
        // 0x800389BC: nop
    
            goto L_80038AE4;
    }
    // 0x800389BC: nop

    // 0x800389C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800389C4: lwc1        $f12, -0x1540($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1540);
    // 0x800389C8: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x800389CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800389D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800389D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800389D8: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800389DC: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800389E0: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800389E4: lui         $a2, 0x4566
    ctx->r6 = S32(0X4566 << 16);
    // 0x800389E8: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    // 0x800389EC: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x800389F0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800389F4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800389F8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800389FC: jal         0x800C3C80
    // 0x80038A00: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_76;
    // 0x80038A00: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_76:
    // 0x80038A04: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80038A08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038A0C: nop

    // 0x80038A10: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80038A14: nop

    // 0x80038A18: bc1t        L_80038AE4
    if (c1cs) {
        // 0x80038A1C: nop
    
            goto L_80038AE4;
    }
    // 0x80038A1C: nop

    // 0x80038A20: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80038A24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038A28: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80038A2C: nop

    // 0x80038A30: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80038A34: nop

    // 0x80038A38: bc1f        L_80038AE4
    if (!c1cs) {
        // 0x80038A3C: nop
    
            goto L_80038AE4;
    }
    // 0x80038A3C: nop

    // 0x80038A40: jal         0x80031874
    // 0x80038A44: nop

    func_80031874(rdram, ctx);
        goto after_77;
    // 0x80038A44: nop

    after_77:
    // 0x80038A48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80038A4C: sb          $zero, 0x25EC($at)
    MEM_B(0X25EC, ctx->r1) = 0;
    // 0x80038A50: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80038A54: lw          $t2, 0x7284($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7284);
    // 0x80038A58: nop

    // 0x80038A5C: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x80038A60: jal         0x800319B0
    // 0x80038A64: nop

    func_800319B0(rdram, ctx);
        goto after_78;
    // 0x80038A64: nop

    after_78:
    // 0x80038A68: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80038A6C: lw          $a0, 0x72A4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72A4);
    // 0x80038A70: jal         0x80048F40
    // 0x80038A74: nop

    func_80048F40(rdram, ctx);
        goto after_79;
    // 0x80038A74: nop

    after_79:
    // 0x80038A78: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80038A7C: lhu         $t3, 0x728E($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X728E);
    // 0x80038A80: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038A84: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x80038A88: sh          $t4, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r12;
    // 0x80038A8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80038A90: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038A94: swc1        $f6, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f6.u32l;
    // 0x80038A98: lhu         $t5, 0xFA($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XFA);
    // 0x80038A9C: nop

    // 0x80038AA0: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x80038AA4: sh          $t1, 0xFA($sp)
    MEM_H(0XFA, ctx->r29) = ctx->r9;
    // 0x80038AA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038AAC: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80038AB0: lwc1        $f12, -0x153C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X153C);
    // 0x80038AB4: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80038AB8: lwc1        $f8, 0xEC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80038ABC: lui         $at, 0x43A6
    ctx->r1 = S32(0X43A6 << 16);
    // 0x80038AC0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80038AC4: lui         $a2, 0x4569
    ctx->r6 = S32(0X4569 << 16);
    // 0x80038AC8: lw          $a3, 0xF4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF4);
    // 0x80038ACC: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80038AD0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80038AD4: ori         $a2, $a2, 0x2000
    ctx->r6 = ctx->r6 | 0X2000;
    // 0x80038AD8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80038ADC: jal         0x800C3D70
    // 0x80038AE0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800C3D70(rdram, ctx);
        goto after_80;
    // 0x80038AE0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_80:
L_80038AE4:
    // 0x80038AE4: b           L_80038E94
    // 0x80038AE8: nop

        goto L_80038E94;
    // 0x80038AE8: nop

L_80038AEC:
    // 0x80038AEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038AF4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80038AF8: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    // 0x80038AFC: addiu       $a2, $sp, 0xF0
    ctx->r6 = ADD32(ctx->r29, 0XF0);
    // 0x80038B00: addiu       $a3, $sp, 0xEC
    ctx->r7 = ADD32(ctx->r29, 0XEC);
    // 0x80038B04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80038B08: jal         0x800C3F2C
    // 0x80038B0C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800C3F2C(rdram, ctx);
        goto after_81;
    // 0x80038B0C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_81:
    // 0x80038B10: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80038B14: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80038B18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80038B1C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80038B20: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x80038B24: nop

    // 0x80038B28: bc1f        L_80038B9C
    if (!c1cs) {
        // 0x80038B2C: nop
    
            goto L_80038B9C;
    }
    // 0x80038B2C: nop

    // 0x80038B30: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80038B34: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80038B38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80038B3C: nop

    // 0x80038B40: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x80038B44: nop

    // 0x80038B48: bc1f        L_80038B9C
    if (!c1cs) {
        // 0x80038B4C: nop
    
            goto L_80038B9C;
    }
    // 0x80038B4C: nop

    // 0x80038B50: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80038B54: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80038B58: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80038B5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80038B60: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80038B64: sub.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d - ctx->f16.d;
    // 0x80038B68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80038B6C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80038B70: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80038B74: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80038B78: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80038B7C: swc1        $f18, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f18.u32l;
    // 0x80038B80: bc1f        L_80038B94
    if (!c1cs) {
        // 0x80038B84: nop
    
            goto L_80038B94;
    }
    // 0x80038B84: nop

    // 0x80038B88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80038B8C: nop

    // 0x80038B90: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
L_80038B94:
    // 0x80038B94: b           L_80038C04
    // 0x80038B98: nop

        goto L_80038C04;
    // 0x80038B98: nop

L_80038B9C:
    // 0x80038B9C: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80038BA0: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80038BA4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038BA8: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80038BAC: c.eq.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d == ctx->f18.d;
    // 0x80038BB0: nop

    // 0x80038BB4: bc1t        L_80038C04
    if (c1cs) {
        // 0x80038BB8: nop
    
            goto L_80038C04;
    }
    // 0x80038BB8: nop

    // 0x80038BBC: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80038BC0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80038BC4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80038BC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80038BCC: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80038BD0: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x80038BD4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038BD8: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x80038BDC: lwc1        $f11, -0x1538($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1538);
    // 0x80038BE0: lwc1        $f10, -0x1534($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1534);
    // 0x80038BE4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80038BE8: c.le.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d <= ctx->f18.d;
    // 0x80038BEC: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    // 0x80038BF0: bc1f        L_80038C04
    if (!c1cs) {
        // 0x80038BF4: nop
    
            goto L_80038C04;
    }
    // 0x80038BF4: nop

    // 0x80038BF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80038BFC: nop

    // 0x80038C00: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
L_80038C04:
    // 0x80038C04: lhu         $t6, 0xFE($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XFE);
    // 0x80038C08: nop

    // 0x80038C0C: beq         $t6, $zero, L_80038C1C
    if (ctx->r14 == 0) {
        // 0x80038C10: nop
    
            goto L_80038C1C;
    }
    // 0x80038C10: nop

    // 0x80038C14: jal         0x800B9000
    // 0x80038C18: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    func_800B9000(rdram, ctx);
        goto after_82;
    // 0x80038C18: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_82:
L_80038C1C:
    // 0x80038C1C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80038C20: lw          $t0, 0x72A4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X72A4);
    // 0x80038C24: nop

    // 0x80038C28: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80038C2C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80038C30: jal         0x80048DC4
    // 0x80038C34: nop

    func_80048DC4(rdram, ctx);
        goto after_83;
    // 0x80038C34: nop

    after_83:
    // 0x80038C38: sh          $v0, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = ctx->r2;
    // 0x80038C3C: lhu         $t9, 0xF8($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XF8);
    // 0x80038C40: nop

    // 0x80038C44: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x80038C48: beq         $t2, $zero, L_80038D08
    if (ctx->r10 == 0) {
        // 0x80038C4C: nop
    
            goto L_80038D08;
    }
    // 0x80038C4C: nop

    // 0x80038C50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80038C54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80038C58: sb          $t3, 0x25EC($at)
    MEM_B(0X25EC, ctx->r1) = ctx->r11;
    // 0x80038C5C: jal         0x80031B6C
    // 0x80038C60: nop

    func_80031B6C(rdram, ctx);
        goto after_84;
    // 0x80038C60: nop

    after_84:
    // 0x80038C64: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80038C68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038C6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80038C70: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x80038C74: lhu         $t4, 0xF8($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XF8);
    // 0x80038C78: nop

    // 0x80038C7C: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x80038C80: beq         $t5, $zero, L_80038CCC
    if (ctx->r13 == 0) {
        // 0x80038C84: nop
    
            goto L_80038CCC;
    }
    // 0x80038C84: nop

    // 0x80038C88: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80038C8C: lw          $t1, 0x7284($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7284);
    // 0x80038C90: nop

    // 0x80038C94: lw          $a0, 0x10($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X10);
    // 0x80038C98: jal         0x800319B0
    // 0x80038C9C: nop

    func_800319B0(rdram, ctx);
        goto after_85;
    // 0x80038C9C: nop

    after_85:
    // 0x80038CA0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80038CA4: lhu         $t7, 0x728E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X728E);
    // 0x80038CA8: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80038CAC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80038CB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038CB4: sh          $t8, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r24;
    // 0x80038CB8: lhu         $t6, 0xFA($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XFA);
    // 0x80038CBC: nop

    // 0x80038CC0: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x80038CC4: b           L_80038D08
    // 0x80038CC8: sh          $t0, 0xFA($sp)
    MEM_H(0XFA, ctx->r29) = ctx->r8;
        goto L_80038D08;
    // 0x80038CC8: sh          $t0, 0xFA($sp)
    MEM_H(0XFA, ctx->r29) = ctx->r8;
L_80038CCC:
    // 0x80038CCC: lhu         $t9, 0xF8($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XF8);
    // 0x80038CD0: nop

    // 0x80038CD4: andi        $t2, $t9, 0x8000
    ctx->r10 = ctx->r25 & 0X8000;
    // 0x80038CD8: beq         $t2, $zero, L_80038D08
    if (ctx->r10 == 0) {
        // 0x80038CDC: nop
    
            goto L_80038D08;
    }
    // 0x80038CDC: nop

    // 0x80038CE0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80038CE4: lw          $t3, 0x7284($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7284);
    // 0x80038CE8: nop

    // 0x80038CEC: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80038CF0: jal         0x800319B0
    // 0x80038CF4: nop

    func_800319B0(rdram, ctx);
        goto after_86;
    // 0x80038CF4: nop

    after_86:
    // 0x80038CF8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80038CFC: sh          $t4, 0xFA($sp)
    MEM_H(0XFA, ctx->r29) = ctx->r12;
    // 0x80038D00: jal         0x800B9000
    // 0x80038D04: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800B9000(rdram, ctx);
        goto after_87;
    // 0x80038D04: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_87:
L_80038D08:
    // 0x80038D08: b           L_80038E94
    // 0x80038D0C: nop

        goto L_80038E94;
    // 0x80038D0C: nop

L_80038D10:
    // 0x80038D10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038D14: lwc1        $f12, -0x1530($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1530);
    // 0x80038D18: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x80038D1C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80038D20: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80038D24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038D28: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80038D2C: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80038D30: lwc1        $f18, 0xEC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80038D34: lui         $a2, 0x4566
    ctx->r6 = S32(0X4566 << 16);
    // 0x80038D38: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    // 0x80038D3C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80038D40: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80038D44: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80038D48: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80038D4C: jal         0x800C3C80
    // 0x80038D50: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_88;
    // 0x80038D50: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_88:
    // 0x80038D54: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80038D58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80038D5C: nop

    // 0x80038D60: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80038D64: nop

    // 0x80038D68: bc1f        L_80038D74
    if (!c1cs) {
        // 0x80038D6C: nop
    
            goto L_80038D74;
    }
    // 0x80038D6C: nop

    // 0x80038D70: sh          $zero, 0xFA($sp)
    MEM_H(0XFA, ctx->r29) = 0;
L_80038D74:
    // 0x80038D74: b           L_80038E94
    // 0x80038D78: nop

        goto L_80038E94;
    // 0x80038D78: nop

L_80038D7C:
    // 0x80038D7C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80038D80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80038D84: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80038D88: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80038D8C: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80038D90: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80038D94: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80038D98: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
    // 0x80038D9C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80038DA0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80038DA4: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80038DA8: nop

    // 0x80038DAC: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80038DB0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80038DB4: nop

    // 0x80038DB8: bc1f        L_80038E2C
    if (!c1cs) {
        // 0x80038DBC: nop
    
            goto L_80038E2C;
    }
    // 0x80038DBC: nop

    // 0x80038DC0: lhu         $t7, 0xFA($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XFA);
    // 0x80038DC4: nop

    // 0x80038DC8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80038DCC: sh          $t8, 0xFA($sp)
    MEM_H(0XFA, ctx->r29) = ctx->r24;
    // 0x80038DD0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80038DD4: sw          $zero, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = 0;
    // 0x80038DD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80038DDC: sw          $zero, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = 0;
    // 0x80038DE0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80038DE4: sw          $zero, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = 0;
    // 0x80038DE8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80038DEC: lh          $t6, 0x7254($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7254);
    // 0x80038DF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038DF4: ori         $t0, $t6, 0x8000
    ctx->r8 = ctx->r14 | 0X8000;
    // 0x80038DF8: sh          $t0, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r8;
    // 0x80038DFC: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80038E00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038E04: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
    // 0x80038E08: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80038E0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038E10: sw          $t2, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r10;
    // 0x80038E14: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80038E18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038E1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80038E20: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x80038E24: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80038E28: sb          $zero, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = 0;
L_80038E2C:
    // 0x80038E2C: b           L_80038E94
    // 0x80038E30: nop

        goto L_80038E94;
    // 0x80038E30: nop

L_80038E34:
    // 0x80038E34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038E38: lwc1        $f16, -0x76B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80038E3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038E40: lwc1        $f19, -0x1528($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1528);
    // 0x80038E44: lwc1        $f18, -0x1524($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1524);
    // 0x80038E48: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80038E4C: add.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f6.d + ctx->f18.d;
    // 0x80038E50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038E54: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80038E58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80038E5C: swc1        $f8, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f8.u32l;
    // 0x80038E60: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80038E64: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80038E68: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80038E6C: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80038E70: nop

    // 0x80038E74: bc1f        L_80038E8C
    if (!c1cs) {
        // 0x80038E78: nop
    
            goto L_80038E8C;
    }
    // 0x80038E78: nop

    // 0x80038E7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038E80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038E84: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038E88: swc1        $f6, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f6.u32l;
L_80038E8C:
    // 0x80038E8C: b           L_80038E94
    // 0x80038E90: nop

        goto L_80038E94;
    // 0x80038E90: nop

L_80038E94:
    // 0x80038E94: jal         0x800C1AF4
    // 0x80038E98: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_89;
    // 0x80038E98: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_89:
    // 0x80038E9C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038EA0: lwc1        $f12, -0x1520($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1520);
    // 0x80038EA4: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x80038EA8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80038EAC: lui         $a2, 0x4566
    ctx->r6 = S32(0X4566 << 16);
    // 0x80038EB0: jal         0x800C2304
    // 0x80038EB4: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_90;
    // 0x80038EB4: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    after_90:
    // 0x80038EB8: jal         0x800B1844
    // 0x80038EBC: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800B1844(rdram, ctx);
        goto after_91;
    // 0x80038EBC: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_91:
    // 0x80038EC0: addiu       $t3, $sp, 0x74
    ctx->r11 = ADD32(ctx->r29, 0X74);
    // 0x80038EC4: lwc1        $f12, 0x0($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80038EC8: lwc1        $f14, 0x4($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80038ECC: lw          $a2, 0x8($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X8);
    // 0x80038ED0: jal         0x800AF1F0
    // 0x80038ED4: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    func_800AF1F0(rdram, ctx);
        goto after_92;
    // 0x80038ED4: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    after_92:
    // 0x80038ED8: beq         $v0, $zero, L_80038F84
    if (ctx->r2 == 0) {
        // 0x80038EDC: nop
    
            goto L_80038F84;
    }
    // 0x80038EDC: nop

    // 0x80038EE0: jal         0x800C1850
    // 0x80038EE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_93;
    // 0x80038EE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_93:
    // 0x80038EE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038EEC: lwc1        $f12, -0x151C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X151C);
    // 0x80038EF0: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x80038EF4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80038EF8: lui         $a2, 0x4566
    ctx->r6 = S32(0X4566 << 16);
    // 0x80038EFC: jal         0x800C2304
    // 0x80038F00: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_94;
    // 0x80038F00: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    after_94:
    // 0x80038F04: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80038F08: nop

    // 0x80038F0C: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80038F10: nop

    // 0x80038F14: swc1        $f18, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f18.u32l;
    // 0x80038F18: jal         0x800C25B8
    // 0x80038F1C: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_95;
    // 0x80038F1C: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    after_95:
    // 0x80038F20: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80038F24: lw          $t5, 0x722C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X722C);
    // 0x80038F28: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80038F2C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80038F30: jal         0x800A42C8
    // 0x80038F34: nop

    func_800A42C8(rdram, ctx);
        goto after_96;
    // 0x80038F34: nop

    after_96:
    // 0x80038F38: jal         0x800C1850
    // 0x80038F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_97;
    // 0x80038F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_97:
    // 0x80038F40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80038F44: lwc1        $f12, -0x1518($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1518);
    // 0x80038F48: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x80038F4C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80038F50: lui         $a2, 0x4566
    ctx->r6 = S32(0X4566 << 16);
    // 0x80038F54: jal         0x800C2304
    // 0x80038F58: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_98;
    // 0x80038F58: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    after_98:
    // 0x80038F5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80038F60: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80038F64: jal         0x800C25B8
    // 0x80038F68: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_99;
    // 0x80038F68: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    after_99:
    // 0x80038F6C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80038F70: lw          $t1, 0x722C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X722C);
    // 0x80038F74: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80038F78: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x80038F7C: jal         0x800A42C8
    // 0x80038F80: nop

    func_800A42C8(rdram, ctx);
        goto after_100;
    // 0x80038F80: nop

    after_100:
L_80038F84:
    // 0x80038F84: jal         0x80035D78
    // 0x80038F88: nop

    func_80035D78(rdram, ctx);
        goto after_101;
    // 0x80038F88: nop

    after_101:
    // 0x80038F8C: sh          $v0, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = ctx->r2;
    // 0x80038F90: lhu         $t7, 0xF8($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XF8);
    // 0x80038F94: nop

    // 0x80038F98: beq         $t7, $zero, L_80038FE4
    if (ctx->r15 == 0) {
        // 0x80038F9C: nop
    
            goto L_80038FE4;
    }
    // 0x80038F9C: nop

    // 0x80038FA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80038FA4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80038FA8: swc1        $f4, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f4.u32l;
    // 0x80038FAC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80038FB0: lhu         $t8, 0x728E($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X728E);
    // 0x80038FB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038FB8: ori         $t6, $t8, 0x2
    ctx->r14 = ctx->r24 | 0X2;
    // 0x80038FBC: sh          $t6, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r14;
    // 0x80038FC0: lhu         $t0, 0xF8($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XF8);
    // 0x80038FC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80038FC8: bne         $t0, $at, L_80038FE4
    if (ctx->r8 != ctx->r1) {
        // 0x80038FCC: nop
    
            goto L_80038FE4;
    }
    // 0x80038FCC: nop

    // 0x80038FD0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80038FD4: lhu         $t9, 0x728E($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X728E);
    // 0x80038FD8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80038FDC: ori         $t2, $t9, 0x8
    ctx->r10 = ctx->r25 | 0X8;
    // 0x80038FE0: sh          $t2, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r10;
L_80038FE4:
    // 0x80038FE4: lhu         $t3, 0xFA($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XFA);
    // 0x80038FE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80038FEC: bne         $t3, $at, L_80038FF8
    if (ctx->r11 != ctx->r1) {
        // 0x80038FF0: sh          $t3, 0xF8($sp)
        MEM_H(0XF8, ctx->r29) = ctx->r11;
            goto L_80038FF8;
    }
    // 0x80038FF0: sh          $t3, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = ctx->r11;
    // 0x80038FF4: sh          $zero, 0xF8($sp)
    MEM_H(0XF8, ctx->r29) = 0;
L_80038FF8:
    // 0x80038FF8: lhu         $a0, 0xF8($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XF8);
    // 0x80038FFC: jal         0x8003547C
    // 0x80039000: nop

    func_8003547C(rdram, ctx);
        goto after_102;
    // 0x80039000: nop

    after_102:
    // 0x80039004: lhu         $t4, 0xF8($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XF8);
    // 0x80039008: nop

    // 0x8003900C: bne         $t4, $zero, L_8003901C
    if (ctx->r12 != 0) {
        // 0x80039010: nop
    
            goto L_8003901C;
    }
    // 0x80039010: nop

    // 0x80039014: jal         0x80034360
    // 0x80039018: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    func_80034360(rdram, ctx);
        goto after_103;
    // 0x80039018: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_103:
L_8003901C:
    // 0x8003901C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80039020: lhu         $t5, 0x728E($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X728E);
    // 0x80039024: nop

    // 0x80039028: andi        $t1, $t5, 0x2
    ctx->r9 = ctx->r13 & 0X2;
    // 0x8003902C: beq         $t1, $zero, L_800391D8
    if (ctx->r9 == 0) {
        // 0x80039030: nop
    
            goto L_800391D8;
    }
    // 0x80039030: nop

    // 0x80039034: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039038: lwc1        $f16, 0x720C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x8003903C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80039040: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80039044: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039048: add.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8003904C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039050: swc1        $f18, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f18.u32l;
    // 0x80039054: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80039058: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003905C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80039060: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80039064: nop

    // 0x80039068: bc1f        L_800390AC
    if (!c1cs) {
        // 0x8003906C: nop
    
            goto L_800390AC;
    }
    // 0x8003906C: nop

    // 0x80039070: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80039074: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80039078: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003907C: jal         0x80099F90
    // 0x80039080: nop

    func_80099F90(rdram, ctx);
        goto after_104;
    // 0x80039080: nop

    after_104:
    // 0x80039084: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039088: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003908C: swc1        $f4, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f4.u32l;
    // 0x80039090: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80039094: lhu         $t7, 0x728E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X728E);
    // 0x80039098: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8003909C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800390A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800390A4: b           L_80039124
    // 0x800390A8: sh          $t8, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r24;
        goto L_80039124;
    // 0x800390A8: sh          $t8, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r24;
L_800390AC:
    // 0x800390AC: jal         0x800C4240
    // 0x800390B0: nop

    guRandom(rdram, ctx);
        goto after_105;
    // 0x800390B0: nop

    after_105:
    // 0x800390B4: jal         0x800C4240
    // 0x800390B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    guRandom(rdram, ctx);
        goto after_106;
    // 0x800390B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_106:
    // 0x800390BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800390C0: bgez        $s1, L_800390D4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800390C4: andi        $t6, $s1, 0xF
        ctx->r14 = ctx->r17 & 0XF;
            goto L_800390D4;
    }
    // 0x800390C4: andi        $t6, $s1, 0xF
    ctx->r14 = ctx->r17 & 0XF;
    // 0x800390C8: beq         $t6, $zero, L_800390D4
    if (ctx->r14 == 0) {
        // 0x800390CC: nop
    
            goto L_800390D4;
    }
    // 0x800390CC: nop

    // 0x800390D0: addiu       $t6, $t6, -0x10
    ctx->r14 = ADD32(ctx->r14, -0X10);
L_800390D4:
    // 0x800390D4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800390D8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800390DC: cvt.d.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.d = CVT_D_W(ctx->f16.u32l);
    // 0x800390E0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800390E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800390E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800390EC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800390F0: sub.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f6.d - ctx->f18.d;
    // 0x800390F4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800390F8: bgez        $s0, L_8003910C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800390FC: andi        $t0, $s0, 0xF
        ctx->r8 = ctx->r16 & 0XF;
            goto L_8003910C;
    }
    // 0x800390FC: andi        $t0, $s0, 0xF
    ctx->r8 = ctx->r16 & 0XF;
    // 0x80039100: beq         $t0, $zero, L_8003910C
    if (ctx->r8 == 0) {
        // 0x80039104: nop
    
            goto L_8003910C;
    }
    // 0x80039104: nop

    // 0x80039108: addiu       $t0, $t0, -0x10
    ctx->r8 = ADD32(ctx->r8, -0X10);
L_8003910C:
    // 0x8003910C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80039110: nop

    // 0x80039114: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x80039118: sub.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d - ctx->f16.d;
    // 0x8003911C: jal         0x80099F90
    // 0x80039120: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    func_80099F90(rdram, ctx);
        goto after_107;
    // 0x80039120: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    after_107:
L_80039124:
    // 0x80039124: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80039128: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003912C: lwc1        $f18, 0x61C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x80039130: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80039134: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80039138: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003913C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80039140: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80039144: lwc1        $f8, 0x61C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80039148: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8003914C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80039150: nop

    // 0x80039154: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80039158: nop

    // 0x8003915C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80039160: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80039164: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80039168: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8003916C: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80039170: lwc1        $f16, 0x61C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x80039174: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80039178: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003917C: nop

    // 0x80039180: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80039184: nop

    // 0x80039188: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8003918C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80039190: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80039194: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80039198: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003919C: lwc1        $f18, 0x61D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800391A0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800391A4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800391A8: nop

    // 0x800391AC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800391B0: nop

    // 0x800391B4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800391B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800391BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800391C0: nop

    // 0x800391C4: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800391C8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800391CC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800391D0: jal         0x800AC0A4
    // 0x800391D4: nop

    func_800AC0A4(rdram, ctx);
        goto after_108;
    // 0x800391D4: nop

    after_108:
L_800391D8:
    // 0x800391D8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800391DC: lhu         $t5, 0x728E($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X728E);
    // 0x800391E0: nop

    // 0x800391E4: andi        $t1, $t5, 0x8
    ctx->r9 = ctx->r13 & 0X8;
    // 0x800391E8: beq         $t1, $zero, L_80039220
    if (ctx->r9 == 0) {
        // 0x800391EC: nop
    
            goto L_80039220;
    }
    // 0x800391EC: nop

    // 0x800391F0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800391F4: lhu         $t7, 0x728E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X728E);
    // 0x800391F8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800391FC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80039200: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039204: sh          $t8, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = ctx->r24;
    // 0x80039208: jal         0x80059D80
    // 0x8003920C: nop

    func_80059D80(rdram, ctx);
        goto after_109;
    // 0x8003920C: nop

    after_109:
    // 0x80039210: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80039214: sb          $zero, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = 0;
    // 0x80039218: jal         0x80031728
    // 0x8003921C: nop

    func_80031728(rdram, ctx);
        goto after_110;
    // 0x8003921C: nop

    after_110:
L_80039220:
    // 0x80039220: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80039224: jal         0x80033CF0
    // 0x80039228: nop

    func_80033CF0(rdram, ctx);
        goto after_111;
    // 0x80039228: nop

    after_111:
    // 0x8003922C: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    // 0x80039230: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80039234: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x80039238: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8003923C: nop

    // 0x80039240: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x80039244: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80039248: lw          $t0, 0x7278($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7278);
    // 0x8003924C: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80039250: nop

    // 0x80039254: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x80039258: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8003925C: lw          $t9, 0x7278($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7278);
    // 0x80039260: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80039264: nop

    // 0x80039268: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    // 0x8003926C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80039270: lw          $t2, 0x7278($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7278);
    // 0x80039274: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80039278: nop

    // 0x8003927C: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    // 0x80039280: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80039284: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x80039288: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8003928C: nop

    // 0x80039290: swc1        $f18, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f18.u32l;
    // 0x80039294: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80039298: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x8003929C: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800392A0: nop

    // 0x800392A4: swc1        $f10, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f10.u32l;
    // 0x800392A8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800392AC: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x800392B0: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800392B4: nop

    // 0x800392B8: swc1        $f8, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f8.u32l;
    // 0x800392BC: lhu         $t1, 0xFA($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XFA);
    // 0x800392C0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800392C4: nop

    // 0x800392C8: sh          $t1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r9;
    // 0x800392CC: jal         0x800C1A28
    // 0x800392D0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_112;
    // 0x800392D0: nop

    after_112:
    // 0x800392D4: b           L_800392DC
    // 0x800392D8: nop

        goto L_800392DC;
    // 0x800392D8: nop

L_800392DC:
    // 0x800392DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800392E0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800392E4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800392E8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800392EC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800392F0: jr          $ra
    // 0x800392F4: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800392F4: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_800775F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800775F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800775FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077600: nop

    // 0x80077604: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80077608: nop

    // 0x8007760C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077610: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077614: jr          $ra
    // 0x80077618: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077618: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007761C: jr          $ra
    // 0x80077620: nop

    return;
    // 0x80077620: nop

    // 0x80077624: jr          $ra
    // 0x80077628: nop

    return;
    // 0x80077628: nop

;}
RECOMP_FUNC void AudioDriver_InitSoundDeallocRequests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B99D4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B99D8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800B99DC:
    // 0x800B99DC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B99E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B99E4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B99E8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B99EC: sw          $zero, -0x1E0C($at)
    MEM_W(-0X1E0C, ctx->r1) = 0;
    // 0x800B99F0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800B99F4: nop

    // 0x800B99F8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B99FC: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800B9A00: bne         $at, $zero, L_800B99DC
    if (ctx->r1 != 0) {
        // 0x800B9A04: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_800B99DC;
    }
    // 0x800B9A04: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800B9A08: b           L_800B9A10
    // 0x800B9A0C: nop

        goto L_800B9A10;
    // 0x800B9A0C: nop

L_800B9A10:
    // 0x800B9A10: jr          $ra
    // 0x800B9A14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B9A14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80067368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067368: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006736C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067370: nop

    // 0x80067374: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80067378: nop

    // 0x8006737C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067380: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067384: jr          $ra
    // 0x80067388: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067388: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006738C: jr          $ra
    // 0x80067390: nop

    return;
    // 0x80067390: nop

    // 0x80067394: jr          $ra
    // 0x80067398: nop

    return;
    // 0x80067398: nop

;}
RECOMP_FUNC void func_8006FFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FFE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FFEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FFF0: jal         0x80061348
    // 0x8006FFF4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FFF4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x8006FFF8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006FFFC: b           L_8007000C
    // 0x80070000: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007000C;
    // 0x80070000: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070004: b           L_8007000C
    // 0x80070008: nop

        goto L_8007000C;
    // 0x80070008: nop

L_8007000C:
    // 0x8007000C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070014: jr          $ra
    // 0x80070018: nop

    return;
    // 0x80070018: nop

;}
RECOMP_FUNC void func_8006B548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B548: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B54C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B550: nop

    // 0x8006B554: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B558: nop

    // 0x8006B55C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B560: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B564: jr          $ra
    // 0x8006B568: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B568: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B56C: jr          $ra
    // 0x8006B570: nop

    return;
    // 0x8006B570: nop

    // 0x8006B574: jr          $ra
    // 0x8006B578: nop

    return;
    // 0x8006B578: nop

;}
RECOMP_FUNC void func_80063868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006386C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063870: jal         0x8005F064
    // 0x80063874: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063874: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063878: b           L_80063888
    // 0x8006387C: nop

        goto L_80063888;
    // 0x8006387C: nop

    // 0x80063880: b           L_80063888
    // 0x80063884: nop

        goto L_80063888;
    // 0x80063884: nop

L_80063888:
    // 0x80063888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006388C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063890: jr          $ra
    // 0x80063894: nop

    return;
    // 0x80063894: nop

;}
RECOMP_FUNC void AudioDriver_SetupOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC4CC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BC4D0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BC4D4: addiu       $t6, $t6, -0x1D88
    ctx->r14 = ADD32(ctx->r14, -0X1D88);
    // 0x800BC4D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BC4DC: sw          $t6, -0x1D90($at)
    MEM_W(-0X1D90, ctx->r1) = ctx->r14;
    // 0x800BC4E0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800BC4E4: addiu       $t7, $t7, -0x1D88
    ctx->r15 = ADD32(ctx->r15, -0X1D88);
    // 0x800BC4E8: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800BC4EC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800BC4F0:
    // 0x800BC4F0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800BC4F4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800BC4F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BC4FC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800BC500: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BC504: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800BC508: addiu       $t0, $t9, 0x14
    ctx->r8 = ADD32(ctx->r25, 0X14);
    // 0x800BC50C: addiu       $t1, $t1, -0x1D88
    ctx->r9 = ADD32(ctx->r9, -0X1D88);
    // 0x800BC510: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800BC514: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800BC518: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800BC51C: nop

    // 0x800BC520: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800BC524: nop

    // 0x800BC528: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x800BC52C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BC530: nop

    // 0x800BC534: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BC538: slti        $at, $t7, 0x27
    ctx->r1 = SIGNED(ctx->r15) < 0X27 ? 1 : 0;
    // 0x800BC53C: bne         $at, $zero, L_800BC4F0
    if (ctx->r1 != 0) {
        // 0x800BC540: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800BC4F0;
    }
    // 0x800BC540: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800BC544: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BC548: nop

    // 0x800BC54C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BC550: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800BC554: addiu       $t9, $t9, -0x49C0
    ctx->r25 = ADD32(ctx->r25, -0X49C0);
    // 0x800BC558: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x800BC55C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800BC560: addiu       $t0, $t0, -0x4444
    ctx->r8 = ADD32(ctx->r8, -0X4444);
    // 0x800BC564: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x800BC568: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800BC56C: addiu       $t1, $t1, -0x3B5C
    ctx->r9 = ADD32(ctx->r9, -0X3B5C);
    // 0x800BC570: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x800BC574: b           L_800BC57C
    // 0x800BC578: nop

        goto L_800BC57C;
    // 0x800BC578: nop

L_800BC57C:
    // 0x800BC57C: jr          $ra
    // 0x800BC580: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BC580: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80049A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049A00: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80049A04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80049A08: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80049A0C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80049A10: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80049A14: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80049A18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80049A1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80049A20: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    // 0x80049A24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049A28: bne         $t6, $at, L_80049A38
    if (ctx->r14 != ctx->r1) {
        // 0x80049A2C: nop
    
            goto L_80049A38;
    }
    // 0x80049A2C: nop

    // 0x80049A30: b           L_80049A3C
    // 0x80049A34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80049A3C;
    // 0x80049A34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80049A38:
    // 0x80049A38: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80049A3C:
    // 0x80049A3C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80049A40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80049A44: jal         0x8005EB00
    // 0x80049A48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8005EB00(rdram, ctx);
        goto after_0;
    // 0x80049A48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80049A4C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80049A50: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80049A54: nop

    // 0x80049A58: beq         $t7, $zero, L_8004A02C
    if (ctx->r15 == 0) {
        // 0x80049A5C: nop
    
            goto L_8004A02C;
    }
    // 0x80049A5C: nop

    // 0x80049A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049A64: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80049A68: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80049A6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80049A70: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80049A74: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80049A78: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x80049A7C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80049A80: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80049A84: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80049A88: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80049A8C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80049A90: nop

    // 0x80049A94: beq         $t9, $zero, L_80049AA8
    if (ctx->r25 == 0) {
        // 0x80049A98: nop
    
            goto L_80049AA8;
    }
    // 0x80049A98: nop

    // 0x80049A9C: lui         $s0, 0x80
    ctx->r16 = S32(0X80 << 16);
    // 0x80049AA0: b           L_80049AAC
    // 0x80049AA4: ori         $s0, $s0, 0x8
    ctx->r16 = ctx->r16 | 0X8;
        goto L_80049AAC;
    // 0x80049AA4: ori         $s0, $s0, 0x8
    ctx->r16 = ctx->r16 | 0X8;
L_80049AA8:
    // 0x80049AA8: lui         $s0, 0x80
    ctx->r16 = S32(0X80 << 16);
L_80049AAC:
    // 0x80049AAC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80049AB0: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x80049AB4: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80049AB8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80049ABC: sra         $t0, $s0, 31
    ctx->r8 = S32(SIGNED(ctx->r16) >> 31);
    // 0x80049AC0: or          $t2, $t6, $t0
    ctx->r10 = ctx->r14 | ctx->r8;
    // 0x80049AC4: or          $t3, $t7, $t1
    ctx->r11 = ctx->r15 | ctx->r9;
    // 0x80049AC8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80049ACC: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80049AD0: lh          $t5, 0x56($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X56);
    // 0x80049AD4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80049AD8: nop

    // 0x80049ADC: sh          $t5, 0x48($t8)
    MEM_H(0X48, ctx->r24) = ctx->r13;
    // 0x80049AE0: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80049AE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80049AE8: nop

    // 0x80049AEC: sw          $t9, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r25;
    // 0x80049AF0: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x80049AF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049AF8: beq         $s0, $at, L_80049B20
    if (ctx->r16 == ctx->r1) {
        // 0x80049AFC: nop
    
            goto L_80049B20;
    }
    // 0x80049AFC: nop

    // 0x80049B00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80049B04: beq         $s0, $at, L_80049B48
    if (ctx->r16 == ctx->r1) {
        // 0x80049B08: nop
    
            goto L_80049B48;
    }
    // 0x80049B08: nop

    // 0x80049B0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049B10: beq         $s0, $at, L_80049B70
    if (ctx->r16 == ctx->r1) {
        // 0x80049B14: nop
    
            goto L_80049B70;
    }
    // 0x80049B14: nop

    // 0x80049B18: b           L_80049B98
    // 0x80049B1C: nop

        goto L_80049B98;
    // 0x80049B1C: nop

L_80049B20:
    // 0x80049B20: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80049B24: nop

    // 0x80049B28: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80049B2C: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80049B30: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80049B34: ori         $t3, $t1, 0x20
    ctx->r11 = ctx->r9 | 0X20;
    // 0x80049B38: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x80049B3C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80049B40: b           L_80049B98
    // 0x80049B44: nop

        goto L_80049B98;
    // 0x80049B44: nop

L_80049B48:
    // 0x80049B48: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80049B4C: nop

    // 0x80049B50: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80049B54: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80049B58: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x80049B5C: ori         $t7, $t9, 0x40
    ctx->r15 = ctx->r25 | 0X40;
    // 0x80049B60: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80049B64: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80049B68: b           L_80049B98
    // 0x80049B6C: nop

        goto L_80049B98;
    // 0x80049B6C: nop

L_80049B70:
    // 0x80049B70: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80049B74: nop

    // 0x80049B78: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x80049B7C: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x80049B80: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80049B84: ori         $t3, $t1, 0x10
    ctx->r11 = ctx->r9 | 0X10;
    // 0x80049B88: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80049B8C: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80049B90: b           L_80049B98
    // 0x80049B94: nop

        goto L_80049B98;
    // 0x80049B94: nop

L_80049B98:
    // 0x80049B98: lh          $t8, 0x4A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4A);
    // 0x80049B9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049BA0: bne         $t8, $at, L_80049F6C
    if (ctx->r24 != ctx->r1) {
        // 0x80049BA4: nop
    
            goto L_80049F6C;
    }
    // 0x80049BA4: nop

    // 0x80049BA8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80049BAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049BB0: sw          $t9, 0xE64($at)
    MEM_W(0XE64, ctx->r1) = ctx->r25;
    // 0x80049BB4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80049BB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049BBC: sh          $t6, 0x10F0($at)
    MEM_H(0X10F0, ctx->r1) = ctx->r14;
    // 0x80049BC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80049BC4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80049BC8: nop

    // 0x80049BCC: sw          $zero, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = 0;
    // 0x80049BD0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80049BD4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80049BD8: lh          $t4, 0x4A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X4A);
    // 0x80049BDC: nop

    // 0x80049BE0: sh          $t4, 0x7C($t0)
    MEM_H(0X7C, ctx->r8) = ctx->r12;
    // 0x80049BE4: lbu         $t1, 0x4F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049BE8: nop

    // 0x80049BEC: beq         $t1, $zero, L_80049F64
    if (ctx->r9 == 0) {
        // 0x80049BF0: nop
    
            goto L_80049F64;
    }
    // 0x80049BF0: nop

    // 0x80049BF4: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049BF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049BFC: bne         $t2, $at, L_80049C10
    if (ctx->r10 != ctx->r1) {
        // 0x80049C00: nop
    
            goto L_80049C10;
    }
    // 0x80049C00: nop

    // 0x80049C04: lbu         $t3, 0x53($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X53);
    // 0x80049C08: b           L_80049C20
    // 0x80049C0C: sb          $t3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r11;
        goto L_80049C20;
    // 0x80049C0C: sb          $t3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r11;
L_80049C10:
    // 0x80049C10: lbu         $t5, 0x53($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X53);
    // 0x80049C14: nop

    // 0x80049C18: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x80049C1C: sb          $t8, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r24;
L_80049C20:
    // 0x80049C20: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049C24: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80049C28: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80049C2C: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80049C30: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80049C34: lw          $t7, -0x2864($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2864);
    // 0x80049C38: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80049C3C: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80049C40: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80049C44: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80049C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80049C4C: jal         0x80060440
    // 0x80049C50: addu        $a0, $t4, $t1
    ctx->r4 = ADD32(ctx->r12, ctx->r9);
    func_80060440(rdram, ctx);
        goto after_1;
    // 0x80049C50: addu        $a0, $t4, $t1
    ctx->r4 = ADD32(ctx->r12, ctx->r9);
    after_1:
    // 0x80049C54: bne         $v0, $zero, L_80049C5C
    if (ctx->r2 != 0) {
        // 0x80049C58: nop
    
            goto L_80049C5C;
    }
    // 0x80049C58: nop

L_80049C5C:
    // 0x80049C5C: lbu         $s0, 0x4F($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049C60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049C64: beq         $s0, $at, L_80049C80
    if (ctx->r16 == ctx->r1) {
        // 0x80049C68: nop
    
            goto L_80049C80;
    }
    // 0x80049C68: nop

    // 0x80049C6C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80049C70: beq         $s0, $at, L_80049DD0
    if (ctx->r16 == ctx->r1) {
        // 0x80049C74: nop
    
            goto L_80049DD0;
    }
    // 0x80049C74: nop

    // 0x80049C78: b           L_80049F64
    // 0x80049C7C: nop

        goto L_80049F64;
    // 0x80049C7C: nop

L_80049C80:
    // 0x80049C80: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80049C84: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80049C88: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80049C8C: lw          $t2, 0x306C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X306C);
    // 0x80049C90: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80049C94: blez        $t3, L_80049DA4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80049C98: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_80049DA4;
    }
    // 0x80049C98: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80049C9C: beq         $t2, $zero, L_80049DA4
    if (ctx->r10 == 0) {
        // 0x80049CA0: nop
    
            goto L_80049DA4;
    }
    // 0x80049CA0: nop

    // 0x80049CA4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80049CA8: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80049CAC: lh          $t5, 0x2($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X2);
    // 0x80049CB0: nop

    // 0x80049CB4: bne         $t5, $t8, L_80049DA4
    if (ctx->r13 != ctx->r24) {
        // 0x80049CB8: nop
    
            goto L_80049DA4;
    }
    // 0x80049CB8: nop

    // 0x80049CBC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80049CC0: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x80049CC4: lh          $t9, 0x4($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X4);
    // 0x80049CC8: nop

    // 0x80049CCC: bne         $t9, $t6, L_80049DA4
    if (ctx->r25 != ctx->r14) {
        // 0x80049CD0: nop
    
            goto L_80049DA4;
    }
    // 0x80049CD0: nop

L_80049CD4:
    // 0x80049CD4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80049CD8: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x80049CDC: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x80049CE0: slti        $t1, $t4, 0x2A
    ctx->r9 = SIGNED(ctx->r12) < 0X2A ? 1 : 0;
    // 0x80049CE4: xori        $t1, $t1, 0x1
    ctx->r9 = ctx->r9 ^ 0X1;
    // 0x80049CE8: bne         $t0, $t1, L_80049D08
    if (ctx->r8 != ctx->r9) {
        // 0x80049CEC: nop
    
            goto L_80049D08;
    }
    // 0x80049CEC: nop

    // 0x80049CF0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80049CF4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80049CF8: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x80049CFC: lw          $s0, -0x28DC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X28DC);
    // 0x80049D00: b           L_80049D10
    // 0x80049D04: nop

        goto L_80049D10;
    // 0x80049D04: nop

L_80049D08:
    // 0x80049D08: lbu         $s0, 0x53($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X53);
    // 0x80049D0C: nop

L_80049D10:
    // 0x80049D10: beq         $s0, $zero, L_80049D50
    if (ctx->r16 == 0) {
        // 0x80049D14: nop
    
            goto L_80049D50;
    }
    // 0x80049D14: nop

    // 0x80049D18: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80049D1C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80049D20: nop

    // 0x80049D24: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80049D28: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x80049D2C: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
    // 0x80049D30: ori         $t3, $t9, 0x8000
    ctx->r11 = ctx->r25 | 0X8000;
    // 0x80049D34: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80049D38: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80049D3C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80049D40: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80049D44: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80049D48: nop

    // 0x80049D4C: sw          $t6, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->r14;
L_80049D50:
    // 0x80049D50: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80049D54: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80049D58: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80049D5C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80049D60: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x80049D64: blez        $t1, L_80049DA4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80049D68: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_80049DA4;
    }
    // 0x80049D68: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80049D6C: beq         $t8, $zero, L_80049DA4
    if (ctx->r24 == 0) {
        // 0x80049D70: nop
    
            goto L_80049DA4;
    }
    // 0x80049D70: nop

    // 0x80049D74: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80049D78: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x80049D7C: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80049D80: nop

    // 0x80049D84: bne         $t9, $t2, L_80049DA4
    if (ctx->r25 != ctx->r10) {
        // 0x80049D88: nop
    
            goto L_80049DA4;
    }
    // 0x80049D88: nop

    // 0x80049D8C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80049D90: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80049D94: lh          $t3, 0x4($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X4);
    // 0x80049D98: nop

    // 0x80049D9C: beq         $t3, $t5, L_80049CD4
    if (ctx->r11 == ctx->r13) {
        // 0x80049DA0: nop
    
            goto L_80049CD4;
    }
    // 0x80049DA0: nop

L_80049DA4:
    // 0x80049DA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80049DA8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80049DAC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80049DB0: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80049DB4: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80049DB8: bne         $t4, $zero, L_80049DC8
    if (ctx->r12 != 0) {
        // 0x80049DBC: andi        $t5, $t1, 0x8000
        ctx->r13 = ctx->r9 & 0X8000;
            goto L_80049DC8;
    }
    // 0x80049DBC: andi        $t5, $t1, 0x8000
    ctx->r13 = ctx->r9 & 0X8000;
    // 0x80049DC0: bne         $t5, $zero, L_80049DC8
    if (ctx->r13 != 0) {
        // 0x80049DC4: nop
    
            goto L_80049DC8;
    }
    // 0x80049DC4: nop

L_80049DC8:
    // 0x80049DC8: b           L_80049F64
    // 0x80049DCC: nop

        goto L_80049F64;
    // 0x80049DCC: nop

L_80049DD0:
    // 0x80049DD0: lbu         $a0, 0x53($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X53);
    // 0x80049DD4: jal         0x80056DF4
    // 0x80049DD8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80056DF4(rdram, ctx);
        goto after_2;
    // 0x80049DD8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_2:
    // 0x80049DDC: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80049DE0: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80049DE4: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80049DE8: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x80049DEC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80049DF0: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80049DF4: lh          $t2, 0x2C50($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2C50);
    // 0x80049DF8: nop

    // 0x80049DFC: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80049E00: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80049E04: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80049E08: nop

    // 0x80049E0C: lw          $t3, 0x144($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X144);
    // 0x80049E10: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80049E14: beq         $t3, $zero, L_80049F34
    if (ctx->r11 == 0) {
        // 0x80049E18: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_80049F34;
    }
    // 0x80049E18: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80049E1C: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x80049E20: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80049E24: bne         $t6, $at, L_80049E3C
    if (ctx->r14 != ctx->r1) {
        // 0x80049E28: nop
    
            goto L_80049E3C;
    }
    // 0x80049E28: nop

    // 0x80049E2C: lhu         $t0, 0x2($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X2);
    // 0x80049E30: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80049E34: beq         $t0, $at, L_80049F34
    if (ctx->r8 == ctx->r1) {
        // 0x80049E38: nop
    
            goto L_80049F34;
    }
    // 0x80049E38: nop

L_80049E3C:
    // 0x80049E3C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80049E40: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80049E44: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x80049E48: nop

    // 0x80049E4C: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80049E50: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x80049E54: bne         $t7, $t9, L_80049EF8
    if (ctx->r15 != ctx->r25) {
        // 0x80049E58: nop
    
            goto L_80049EF8;
    }
    // 0x80049E58: nop

    // 0x80049E5C: sra         $t2, $t4, 8
    ctx->r10 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80049E60: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x80049E64: bne         $t8, $zero, L_80049EF8
    if (ctx->r24 != 0) {
        // 0x80049E68: nop
    
            goto L_80049EF8;
    }
    // 0x80049E68: nop

    // 0x80049E6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80049E70: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80049E74: jal         0x8007959C
    // 0x80049E78: addiu       $a0, $a0, 0x11B0
    ctx->r4 = ADD32(ctx->r4, 0X11B0);
    func_8007959C(rdram, ctx);
        goto after_3;
    // 0x80049E78: addiu       $a0, $a0, 0x11B0
    ctx->r4 = ADD32(ctx->r4, 0X11B0);
    after_3:
    // 0x80049E7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80049E80: lw          $t6, 0x11C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11C8);
    // 0x80049E84: nop

    // 0x80049E88: beq         $t6, $zero, L_80049EA0
    if (ctx->r14 == 0) {
        // 0x80049E8C: nop
    
            goto L_80049EA0;
    }
    // 0x80049E8C: nop

    // 0x80049E90: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80049E94: lw          $a0, 0x11C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11C8);
    // 0x80049E98: jal         0x800BC980
    // 0x80049E9C: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x80049E9C: nop

    after_4:
L_80049EA0:
    // 0x80049EA0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80049EA4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80049EA8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80049EAC: addiu       $t3, $t3, 0x11B0
    ctx->r11 = ADD32(ctx->r11, 0X11B0);
    // 0x80049EB0: sw          $t3, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r11;
    // 0x80049EB4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80049EB8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80049EBC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80049EC0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80049EC4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x80049EC8: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80049ECC: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x80049ED0: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80049ED4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80049ED8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80049EDC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80049EE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80049EE4: lw          $t9, 0x58($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X58);
    // 0x80049EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80049EEC: lbu         $a0, 0x16($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X16);
    // 0x80049EF0: jal         0x8008312C
    // 0x80049EF4: nop

    func_8008312C(rdram, ctx);
        goto after_5;
    // 0x80049EF4: nop

    after_5:
L_80049EF8:
    // 0x80049EF8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80049EFC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80049F00: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80049F04: addiu       $t4, $t0, 0x10
    ctx->r12 = ADD32(ctx->r8, 0X10);
    // 0x80049F08: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80049F0C: beq         $t4, $zero, L_80049F34
    if (ctx->r12 == 0) {
        // 0x80049F10: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80049F34;
    }
    // 0x80049F10: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80049F14: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80049F18: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80049F1C: bne         $t5, $at, L_80049E3C
    if (ctx->r13 != ctx->r1) {
        // 0x80049F20: nop
    
            goto L_80049E3C;
    }
    // 0x80049F20: nop

    // 0x80049F24: lhu         $t2, 0x2($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X2);
    // 0x80049F28: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80049F2C: bne         $t2, $at, L_80049E3C
    if (ctx->r10 != ctx->r1) {
        // 0x80049F30: nop
    
            goto L_80049E3C;
    }
    // 0x80049F30: nop

L_80049F34:
    // 0x80049F34: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80049F38: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80049F3C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80049F40: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80049F44: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80049F48: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80049F4C: bne         $t6, $zero, L_80049F5C
    if (ctx->r14 != 0) {
        // 0x80049F50: and         $t7, $t9, $at
        ctx->r15 = ctx->r25 & ctx->r1;
            goto L_80049F5C;
    }
    // 0x80049F50: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80049F54: bne         $t7, $zero, L_80049F5C
    if (ctx->r15 != 0) {
        // 0x80049F58: nop
    
            goto L_80049F5C;
    }
    // 0x80049F58: nop

L_80049F5C:
    // 0x80049F5C: b           L_80049F64
    // 0x80049F60: nop

        goto L_80049F64;
    // 0x80049F60: nop

L_80049F64:
    // 0x80049F64: b           L_8004A02C
    // 0x80049F68: nop

        goto L_8004A02C;
    // 0x80049F68: nop

L_80049F6C:
    // 0x80049F6C: lh          $t1, 0x4A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X4A);
    // 0x80049F70: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80049F74: nop

    // 0x80049F78: sh          $t1, 0x7C($t0)
    MEM_H(0X7C, ctx->r8) = ctx->r9;
    // 0x80049F7C: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x80049F80: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80049F84: nop

    // 0x80049F88: sw          $t5, 0x80($t4)
    MEM_W(0X80, ctx->r12) = ctx->r13;
    // 0x80049F8C: lbu         $t2, 0x53($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X53);
    // 0x80049F90: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80049F94: nop

    // 0x80049F98: sw          $t2, 0x84($t3)
    MEM_W(0X84, ctx->r11) = ctx->r10;
    // 0x80049F9C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80049FA0: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80049FA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049FA8: bne         $t8, $at, L_80049FDC
    if (ctx->r24 != ctx->r1) {
        // 0x80049FAC: nop
    
            goto L_80049FDC;
    }
    // 0x80049FAC: nop

    // 0x80049FB0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80049FB4: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x80049FB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049FBC: bne         $t9, $at, L_80049FDC
    if (ctx->r25 != ctx->r1) {
        // 0x80049FC0: nop
    
            goto L_80049FDC;
    }
    // 0x80049FC0: nop

    // 0x80049FC4: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80049FC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80049FCC: jal         0x800490C0
    // 0x80049FD0: addiu       $a0, $a0, 0x7AB8
    ctx->r4 = ADD32(ctx->r4, 0X7AB8);
    func_800490C0(rdram, ctx);
        goto after_6;
    // 0x80049FD0: addiu       $a0, $a0, 0x7AB8
    ctx->r4 = ADD32(ctx->r4, 0X7AB8);
    after_6:
    // 0x80049FD4: b           L_8004A02C
    // 0x80049FD8: nop

        goto L_8004A02C;
    // 0x80049FD8: nop

L_80049FDC:
    // 0x80049FDC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80049FE0: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x80049FE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80049FE8: bne         $t6, $at, L_8004A01C
    if (ctx->r14 != ctx->r1) {
        // 0x80049FEC: nop
    
            goto L_8004A01C;
    }
    // 0x80049FEC: nop

    // 0x80049FF0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80049FF4: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x80049FF8: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80049FFC: bne         $t7, $at, L_8004A01C
    if (ctx->r15 != ctx->r1) {
        // 0x8004A000: nop
    
            goto L_8004A01C;
    }
    // 0x8004A000: nop

    // 0x8004A004: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8004A008: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004A00C: jal         0x800490C0
    // 0x8004A010: addiu       $a0, $a0, -0x5248
    ctx->r4 = ADD32(ctx->r4, -0X5248);
    func_800490C0(rdram, ctx);
        goto after_7;
    // 0x8004A010: addiu       $a0, $a0, -0x5248
    ctx->r4 = ADD32(ctx->r4, -0X5248);
    after_7:
    // 0x8004A014: b           L_8004A02C
    // 0x8004A018: nop

        goto L_8004A02C;
    // 0x8004A018: nop

L_8004A01C:
    // 0x8004A01C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8004A020: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004A024: jal         0x800490C0
    // 0x8004A028: addiu       $a0, $a0, -0x4890
    ctx->r4 = ADD32(ctx->r4, -0X4890);
    func_800490C0(rdram, ctx);
        goto after_8;
    // 0x8004A028: addiu       $a0, $a0, -0x4890
    ctx->r4 = ADD32(ctx->r4, -0X4890);
    after_8:
L_8004A02C:
    // 0x8004A02C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8004A030: b           L_8004A040
    // 0x8004A034: nop

        goto L_8004A040;
    // 0x8004A034: nop

    // 0x8004A038: b           L_8004A040
    // 0x8004A03C: nop

        goto L_8004A040;
    // 0x8004A03C: nop

L_8004A040:
    // 0x8004A040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A044: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004A048: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004A04C: jr          $ra
    // 0x8004A050: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8004A050: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80072ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072ADC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072AE0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072AE4: nop

    // 0x80072AE8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072AEC: nop

    // 0x80072AF0: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80072AF4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072AF8: jr          $ra
    // 0x80072AFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072AFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072B00: jr          $ra
    // 0x80072B04: nop

    return;
    // 0x80072B04: nop

    // 0x80072B08: jr          $ra
    // 0x80072B0C: nop

    return;
    // 0x80072B0C: nop

;}
RECOMP_FUNC void func_80008F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008F58: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80008F5C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80008F60: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80008F64: nop

    // 0x80008F68: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80008F6C: nop

    // 0x80008F70: beq         $t7, $zero, L_80008FD8
    if (ctx->r15 == 0) {
        // 0x80008F74: nop
    
            goto L_80008FD8;
    }
    // 0x80008F74: nop

    // 0x80008F78: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80008F7C: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80008F80: lw          $t0, 0x344($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X344);
    // 0x80008F84: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x80008F88: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80008F8C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80008F90: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80008F94: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80008F98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008F9C: lhu         $t4, 0xA($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XA);
    // 0x80008FA0: nop

    // 0x80008FA4: sh          $t4, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r12;
    // 0x80008FA8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80008FAC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008FB0: lhu         $t6, 0xC($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0XC);
    // 0x80008FB4: nop

    // 0x80008FB8: sh          $t6, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r14;
    // 0x80008FBC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80008FC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008FC4: lhu         $t8, 0xE($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XE);
    // 0x80008FC8: nop

    // 0x80008FCC: sh          $t8, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r24;
    // 0x80008FD0: b           L_80008FE8
    // 0x80008FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80008FE8;
    // 0x80008FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80008FD8:
    // 0x80008FD8: b           L_80008FE8
    // 0x80008FDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80008FE8;
    // 0x80008FDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80008FE0: b           L_80008FE8
    // 0x80008FE4: nop

        goto L_80008FE8;
    // 0x80008FE4: nop

L_80008FE8:
    // 0x80008FE8: jr          $ra
    // 0x80008FEC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80008FEC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B0D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0D30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B0D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B0D38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B0D3C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B0D40: nop

    // 0x800B0D44: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B0D48: nop

    // 0x800B0D4C: beq         $t7, $zero, L_800B0DE4
    if (ctx->r15 == 0) {
        // 0x800B0D50: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_800B0DE4;
    }
    // 0x800B0D50: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800B0D54: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B0D58: nop

    // 0x800B0D5C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_800B0D60:
    // 0x800B0D60: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0D64: nop

    // 0x800B0D68: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800B0D6C: nop

    // 0x800B0D70: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800B0D74: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0D78: nop

    // 0x800B0D7C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800B0D80: nop

    // 0x800B0D84: beq         $t2, $zero, L_800B0D98
    if (ctx->r10 == 0) {
        // 0x800B0D88: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800B0D98;
    }
    // 0x800B0D88: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800B0D8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800B0D90: jal         0x800BC980
    // 0x800B0D94: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800B0D94: nop

    after_0:
L_800B0D98:
    // 0x800B0D98: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0D9C: jal         0x800BC980
    // 0x800B0DA0: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800B0DA0: nop

    after_1:
    // 0x800B0DA4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B0DA8: nop

    // 0x800B0DAC: bne         $t3, $zero, L_800B0DBC
    if (ctx->r11 != 0) {
        // 0x800B0DB0: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_800B0DBC;
    }
    // 0x800B0DB0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800B0DB4: b           L_800B0DC4
    // 0x800B0DB8: nop

        goto L_800B0DC4;
    // 0x800B0DB8: nop

L_800B0DBC:
    // 0x800B0DBC: b           L_800B0D60
    // 0x800B0DC0: nop

        goto L_800B0D60;
    // 0x800B0DC0: nop

L_800B0DC4:
    // 0x800B0DC4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800B0DC8: nop

    // 0x800B0DCC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800B0DD0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800B0DD4: nop

    // 0x800B0DD8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x800B0DDC: nop

    // 0x800B0DE0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_800B0DE4:
    // 0x800B0DE4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800B0DE8: b           L_800B0DF8
    // 0x800B0DEC: nop

        goto L_800B0DF8;
    // 0x800B0DEC: nop

    // 0x800B0DF0: b           L_800B0DF8
    // 0x800B0DF4: nop

        goto L_800B0DF8;
    // 0x800B0DF4: nop

L_800B0DF8:
    // 0x800B0DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B0DFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B0E00: jr          $ra
    // 0x800B0E04: nop

    return;
    // 0x800B0E04: nop

;}
