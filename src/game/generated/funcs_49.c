#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80021EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021EC8: nop

    // 0x80021ECC: nop

;}
RECOMP_FUNC void func_8002214C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002214C: nop

;}
RECOMP_FUNC void func_8002D3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D3A8: nop

    // 0x8002D3AC: nop

;}
RECOMP_FUNC void func_80048F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048F7C: nop

;}
RECOMP_FUNC void func_80077FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FE4: nop

    // 0x80077FE8: nop

    // 0x80077FEC: nop

;}
RECOMP_FUNC void func_80096EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096EDC: nop

;}
RECOMP_FUNC void func_800983AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800983AC: nop

;}
RECOMP_FUNC void func_800ADEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADEC4: nop

    // 0x800ADEC8: nop

    // 0x800ADECC: nop

;}
RECOMP_FUNC void func_800AF058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF058: nop

    // 0x800AF05C: nop

;}
RECOMP_FUNC void func_800B1A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1A4C: nop

;}
RECOMP_FUNC void func_800BC584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC584: nop

    // 0x800BC588: nop

    // 0x800BC58C: nop

;}
RECOMP_FUNC void func_800BC614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC614: nop

    // 0x800BC618: nop

    // 0x800BC61C: nop

;}
RECOMP_FUNC void func_800BD6E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD6E8: nop

    // 0x800BD6EC: nop

;}
RECOMP_FUNC void func_800BED68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED68: nop

    // 0x800BED6C: nop

;}
RECOMP_FUNC void func_800C00A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C00A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C00A8: blez        $a2, L_800C00EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800C00AC: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_800C00EC;
    }
    // 0x800C00AC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800C00B0:
    // 0x800C00B0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800C00B4: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800C00B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C00BC: xor         $a3, $t6, $t7
    ctx->r7 = ctx->r14 ^ ctx->r15;
    // 0x800C00C0: sltu        $a3, $zero, $a3
    ctx->r7 = 0 < ctx->r7 ? 1 : 0;
    // 0x800C00C4: beq         $a3, $zero, L_800C00D4
    if (ctx->r7 == 0) {
        // 0x800C00C8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800C00D4;
    }
    // 0x800C00C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C00CC: b           L_800C00EC
    // 0x800C00D0: nop

        goto L_800C00EC;
    // 0x800C00D0: nop

L_800C00D4:
    // 0x800C00D4: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800C00D8: nop

    // 0x800C00DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C00E0: slt         $at, $t9, $a2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C00E4: bne         $at, $zero, L_800C00B0
    if (ctx->r1 != 0) {
        // 0x800C00E8: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_800C00B0;
    }
    // 0x800C00E8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_800C00EC:
    // 0x800C00EC: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800C00F0: b           L_800C0100
    // 0x800C00F4: nop

        goto L_800C0100;
    // 0x800C00F4: nop

    // 0x800C00F8: b           L_800C0100
    // 0x800C00FC: nop

        goto L_800C0100;
    // 0x800C00FC: nop

L_800C0100:
    // 0x800C0100: jr          $ra
    // 0x800C0104: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C0104: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C059C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C059C: nop

;}
RECOMP_FUNC void func_800C15B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C15B8: nop

    // 0x800C15BC: nop

;}
RECOMP_FUNC void func_800C3064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3064: nop

    // 0x800C3068: nop

    // 0x800C306C: nop

;}
RECOMP_FUNC void func_800C4078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4078: nop

    // 0x800C407C: nop

;}
RECOMP_FUNC void func_800C4154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4154: nop

    // 0x800C4158: nop

    // 0x800C415C: nop

;}
RECOMP_FUNC void func_800C426C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C426C: nop

;}
RECOMP_FUNC void func_800C4298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4298: nop

    // 0x800C429C: nop

;}
RECOMP_FUNC void func_800C42A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C42A8: nop

    // 0x800C42AC: nop

;}
RECOMP_FUNC void func_800C42DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C42DC: nop

;}
RECOMP_FUNC void func_800C4468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4468: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C446C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4470: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C4474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C4478: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800C447C: jal         0x800CC000
    // 0x800C4480: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    __osViGetCurrentContext_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4480: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_0:
    // 0x800C4484: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800C4488: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800C448C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C4490: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800C4494: bne         $t7, $zero, L_800C44A8
    if (ctx->r15 != 0) {
        // 0x800C4498: sh          $t7, -0x590($at)
        MEM_H(-0X590, ctx->r1) = ctx->r15;
            goto L_800C44A8;
    }
    // 0x800C4498: sh          $t7, -0x590($at)
    MEM_H(-0X590, ctx->r1) = ctx->r15;
    // 0x800C449C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C44A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C44A4: sh          $t8, -0x590($at)
    MEM_H(-0X590, ctx->r1) = ctx->r24;
L_800C44A8:
    // 0x800C44A8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800C44AC: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_800C44B0:
    // 0x800C44B0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C44B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800C44B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C44BC: jal         0x800C4C40
    // 0x800C44C0: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800C44C0: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    after_1:
    // 0x800C44C4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C44C8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800C44CC: lhu         $s0, 0x0($t1)
    ctx->r16 = MEM_HU(ctx->r9, 0X0);
    // 0x800C44D0: beq         $s0, $at, L_800C44E8
    if (ctx->r16 == ctx->r1) {
        // 0x800C44D4: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_800C44E8;
    }
    // 0x800C44D4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800C44D8: beq         $s0, $at, L_800C45F8
    if (ctx->r16 == ctx->r1) {
        // 0x800C44DC: nop
    
            goto L_800C45F8;
    }
    // 0x800C44DC: nop

    // 0x800C44E0: b           L_800C44B0
    // 0x800C44E4: nop

        goto L_800C44B0;
    // 0x800C44E4: nop

L_800C44E8:
    // 0x800C44E8: jal         0x800CC010
    // 0x800C44EC: nop

    __osViSwapContext_recomp(rdram, ctx);
        goto after_2;
    // 0x800C44EC: nop

    after_2:
    // 0x800C44F0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800C44F4: lhu         $t2, -0x590($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X590);
    // 0x800C44F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C44FC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800C4500: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800C4504: bne         $t4, $zero, L_800C4548
    if (ctx->r12 != 0) {
        // 0x800C4508: sh          $t3, -0x590($at)
        MEM_H(-0X590, ctx->r1) = ctx->r11;
            goto L_800C4548;
    }
    // 0x800C4508: sh          $t3, -0x590($at)
    MEM_H(-0X590, ctx->r1) = ctx->r11;
    // 0x800C450C: jal         0x800CC000
    // 0x800C4510: nop

    __osViGetCurrentContext_recomp(rdram, ctx);
        goto after_3;
    // 0x800C4510: nop

    after_3:
    // 0x800C4514: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800C4518: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800C451C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800C4520: beq         $t6, $zero, L_800C4538
    if (ctx->r14 == 0) {
        // 0x800C4524: nop
    
            goto L_800C4538;
    }
    // 0x800C4524: nop

    // 0x800C4528: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C452C: lw          $a1, 0x14($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X14);
    // 0x800C4530: jal         0x800C4AA0
    // 0x800C4534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800C4534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_800C4538:
    // 0x800C4538: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800C453C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C4540: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x800C4544: sh          $t8, -0x590($at)
    MEM_H(-0X590, ctx->r1) = ctx->r24;
L_800C4548:
    // 0x800C4548: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800C454C: lw          $t9, 0xE1C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE1C);
    // 0x800C4550: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C4554: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C4558: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C455C: beq         $t1, $zero, L_800C4590
    if (ctx->r9 == 0) {
        // 0x800C4560: sw          $t0, 0xE1C($at)
        MEM_W(0XE1C, ctx->r1) = ctx->r8;
            goto L_800C4590;
    }
    // 0x800C4560: sw          $t0, 0xE1C($at)
    MEM_W(0XE1C, ctx->r1) = ctx->r8;
    // 0x800C4564: jal         0x800CBBB0
    // 0x800C4568: nop

    osGetCount_recomp(rdram, ctx);
        goto after_5;
    // 0x800C4568: nop

    after_5:
    // 0x800C456C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C4570: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800C4574: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x800C4578: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C457C: sw          $t4, 0xE10($at)
    MEM_W(0XE10, ctx->r1) = ctx->r12;
    // 0x800C4580: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C4584: or          $t5, $t2, $zero
    ctx->r13 = ctx->r10 | 0;
    // 0x800C4588: sw          $t5, 0xE14($at)
    MEM_W(0XE14, ctx->r1) = ctx->r13;
    // 0x800C458C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_800C4590:
    // 0x800C4590: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800C4594: lw          $t3, 0xE18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE18);
    // 0x800C4598: jal         0x800CBBB0
    // 0x800C459C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    osGetCount_recomp(rdram, ctx);
        goto after_6;
    // 0x800C459C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_6:
    // 0x800C45A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C45A4: sw          $v0, 0xE18($at)
    MEM_W(0XE18, ctx->r1) = ctx->r2;
    // 0x800C45A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800C45AC: lw          $t6, 0xE18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE18);
    // 0x800C45B0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C45B4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800C45B8: lw          $t3, 0xE14($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE14);
    // 0x800C45BC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800C45C0: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800C45C4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800C45C8: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x800C45CC: lw          $t2, 0xE10($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE10);
    // 0x800C45D0: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800C45D4: sltu        $at, $t5, $t3
    ctx->r1 = ctx->r13 < ctx->r11 ? 1 : 0;
    // 0x800C45D8: addu        $t4, $at, $t0
    ctx->r12 = ADD32(ctx->r1, ctx->r8);
    // 0x800C45DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C45E0: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800C45E4: sw          $t4, 0xE10($at)
    MEM_W(0XE10, ctx->r1) = ctx->r12;
    // 0x800C45E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C45EC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800C45F0: b           L_800C44B0
    // 0x800C45F4: sw          $t5, 0xE14($at)
    MEM_W(0XE14, ctx->r1) = ctx->r13;
        goto L_800C44B0;
    // 0x800C45F4: sw          $t5, 0xE14($at)
    MEM_W(0XE14, ctx->r1) = ctx->r13;
L_800C45F8:
    // 0x800C45F8: jal         0x800CBC4C
    // 0x800C45FC: nop

    __osTimerInterrupt_recomp(rdram, ctx);
        goto after_7;
    // 0x800C45FC: nop

    after_7:
    // 0x800C4600: b           L_800C44B0
    // 0x800C4604: nop

        goto L_800C44B0;
    // 0x800C4604: nop

    // 0x800C4608: nop

    // 0x800C460C: nop

    // 0x800C4610: nop

    // 0x800C4614: nop

    // 0x800C4618: nop

    // 0x800C461C: nop

    // 0x800C4620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4624: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C4628: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C462C: jr          $ra
    // 0x800C4630: nop

    return;
    // 0x800C4630: nop

    // 0x800C4634: nop

    // 0x800C4638: nop

    // 0x800C463C: nop

;}
RECOMP_FUNC void func_800C46A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C46A8: nop

    // 0x800C46AC: nop

;}
RECOMP_FUNC void func_800C4788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4788: nop

    // 0x800C478C: nop

;}
RECOMP_FUNC void func_800C47FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C47FC: nop

;}
RECOMP_FUNC void func_800C4944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4944: nop

    // 0x800C4948: nop

    // 0x800C494C: nop

;}
RECOMP_FUNC void func_800C4BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4BEC: nop

;}
RECOMP_FUNC void func_800C4C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4C3C: nop

;}
RECOMP_FUNC void func_800C4D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4D78: nop

    // 0x800C4D7C: nop

;}
RECOMP_FUNC void func_800C4E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4E44: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800C4E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4E4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C4E50: addiu       $t6, $t6, -0x500
    ctx->r14 = ADD32(ctx->r14, -0X500);
    // 0x800C4E54: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800C4E58: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C4E5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C4E60: jal         0x800CCC80
    // 0x800C4E64: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    bcopy_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4E64: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x800C4E68: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4E6C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x800C4E70: beq         $t8, $zero, L_800C4E88
    if (ctx->r24 == 0) {
        // 0x800C4E74: nop
    
            goto L_800C4E88;
    }
    // 0x800C4E74: nop

    // 0x800C4E78: jal         0x800C79C0
    // 0x800C4E7C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800C4E7C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800C4E80: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4E84: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
L_800C4E88:
    // 0x800C4E88: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4E8C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x800C4E90: beq         $t1, $zero, L_800C4EA8
    if (ctx->r9 == 0) {
        // 0x800C4E94: nop
    
            goto L_800C4EA8;
    }
    // 0x800C4E94: nop

    // 0x800C4E98: jal         0x800C79C0
    // 0x800C4E9C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800C4E9C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x800C4EA0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EA4: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
L_800C4EA8:
    // 0x800C4EA8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EAC: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x800C4EB0: beq         $t4, $zero, L_800C4EC8
    if (ctx->r12 == 0) {
        // 0x800C4EB4: nop
    
            goto L_800C4EC8;
    }
    // 0x800C4EB4: nop

    // 0x800C4EB8: jal         0x800C79C0
    // 0x800C4EBC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800C4EBC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x800C4EC0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EC4: sw          $v0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r2;
L_800C4EC8:
    // 0x800C4EC8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4ECC: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x800C4ED0: beq         $t7, $zero, L_800C4EE8
    if (ctx->r15 == 0) {
        // 0x800C4ED4: nop
    
            goto L_800C4EE8;
    }
    // 0x800C4ED4: nop

    // 0x800C4ED8: jal         0x800C79C0
    // 0x800C4EDC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800C4EDC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x800C4EE0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EE4: sw          $v0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r2;
L_800C4EE8:
    // 0x800C4EE8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4EEC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x800C4EF0: beq         $t0, $zero, L_800C4F08
    if (ctx->r8 == 0) {
        // 0x800C4EF4: nop
    
            goto L_800C4F08;
    }
    // 0x800C4EF4: nop

    // 0x800C4EF8: jal         0x800C79C0
    // 0x800C4EFC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800C4EFC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x800C4F00: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F04: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
L_800C4F08:
    // 0x800C4F08: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F0C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x800C4F10: beq         $t3, $zero, L_800C4F28
    if (ctx->r11 == 0) {
        // 0x800C4F14: nop
    
            goto L_800C4F28;
    }
    // 0x800C4F14: nop

    // 0x800C4F18: jal         0x800C79C0
    // 0x800C4F1C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800C4F1C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x800C4F20: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F24: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
L_800C4F28:
    // 0x800C4F28: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F2C: lw          $t6, 0x38($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X38);
    // 0x800C4F30: beq         $t6, $zero, L_800C4F48
    if (ctx->r14 == 0) {
        // 0x800C4F34: nop
    
            goto L_800C4F48;
    }
    // 0x800C4F34: nop

    // 0x800C4F38: jal         0x800C79C0
    // 0x800C4F3C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x800C4F3C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_7:
    // 0x800C4F40: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F44: sw          $v0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r2;
L_800C4F48:
    // 0x800C4F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4F4C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4F50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4F54: jr          $ra
    // 0x800C4F58: nop

    return;
    // 0x800C4F58: nop

;}
RECOMP_FUNC void func_800C50FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C50FC: nop

;}
RECOMP_FUNC void func_800C51A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C51A8: nop

    // 0x800C51AC: nop

;}
RECOMP_FUNC void func_800C558C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C558C: nop

;}
RECOMP_FUNC void func_800C56FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56FC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C5700: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800C5704: addiu       $t6, $t6, -0x4C0
    ctx->r14 = ADD32(ctx->r14, -0X4C0);
    // 0x800C5708: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C570C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C5710:
    // 0x800C5710: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800C5714: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800C5718: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C571C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C5720: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C5724: sw          $zero, -0x4C0($at)
    MEM_W(-0X4C0, ctx->r1) = 0;
    // 0x800C5728: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C572C: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800C5730: bne         $at, $zero, L_800C5710
    if (ctx->r1 != 0) {
        // 0x800C5734: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_800C5710;
    }
    // 0x800C5734: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x800C5738: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800C573C: lbu         $t9, -0x47F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X47F);
    // 0x800C5740: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C5744: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C5748: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C574C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C5750: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C5754: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C5758: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800C575C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C5760: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C5764: sw          $t1, -0x484($at)
    MEM_W(-0X484, ctx->r1) = ctx->r9;
    // 0x800C5768: sb          $t2, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r10;
    // 0x800C576C: sb          $t3, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r11;
    // 0x800C5770: sb          $t4, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r12;
    // 0x800C5774: sb          $t5, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r13;
    // 0x800C5778: sh          $t6, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r14;
    // 0x800C577C: sb          $t7, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r15;
    // 0x800C5780: sb          $t8, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r24;
    // 0x800C5784: blez        $t9, L_800C57D4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800C5788: sw          $zero, 0x0($sp)
        MEM_W(0X0, ctx->r29) = 0;
            goto L_800C57D4;
    }
    // 0x800C5788: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C578C:
    // 0x800C578C: addiu       $t1, $sp, 0x4
    ctx->r9 = ADD32(ctx->r29, 0X4);
    // 0x800C5790: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x800C5794: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C5798: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800C579C: swl         $at, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r1);
    // 0x800C57A0: swr         $at, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r1);
    // 0x800C57A4: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x800C57A8: swl         $t3, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r11);
    // 0x800C57AC: swr         $t3, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r11);
    // 0x800C57B0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C57B4: lbu         $t8, -0x47F($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X47F);
    // 0x800C57B8: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C57BC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C57C0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C57C4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800C57C8: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800C57CC: bne         $at, $zero, L_800C578C
    if (ctx->r1 != 0) {
        // 0x800C57D0: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C578C;
    }
    // 0x800C57D0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_800C57D4:
    // 0x800C57D4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C57D8: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x800C57DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800C57E0: jr          $ra
    // 0x800C57E4: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    return;
    // 0x800C57E4: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x800C57E8: nop

    // 0x800C57EC: nop

;}
RECOMP_FUNC void func_800C5F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5F98: nop

    // 0x800C5F9C: nop

;}
RECOMP_FUNC void func_800C6118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6118: nop

    // 0x800C611C: nop

;}
RECOMP_FUNC void func_800C648C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C648C: nop

;}
RECOMP_FUNC void func_800C6794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6794: nop

    // 0x800C6798: nop

    // 0x800C679C: nop

;}
RECOMP_FUNC void func_800C6BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6BDC: nop

;}
RECOMP_FUNC void func_800C71E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C71E8: nop

    // 0x800C71EC: nop

    // 0x800C71F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C71F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C71F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C71FC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7200: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C7204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7208: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C720C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C7210: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800C7214: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800C7218: beq         $t7, $t9, L_800C7254
    if (ctx->r15 == ctx->r25) {
        // 0x800C721C: nop
    
            goto L_800C7254;
    }
    // 0x800C721C: nop

    // 0x800C7220: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800C7224: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800C7228: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800C722C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C7230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C7234: jal         0x800CE02C
    // 0x800C7238: lbu         $a3, 0x0($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X0);
    __osPfsRWInode_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7238: lbu         $a3, 0x0($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X0);
    after_0:
    // 0x800C723C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C7240: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7244: beq         $t1, $zero, L_800C7254
    if (ctx->r9 == 0) {
        // 0x800C7248: nop
    
            goto L_800C7254;
    }
    // 0x800C7248: nop

    // 0x800C724C: b           L_800C72DC
    // 0x800C7250: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800C72DC;
    // 0x800C7250: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800C7254:
    // 0x800C7254: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7258: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800C725C: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x800C7260: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800C7264: addu        $t8, $t3, $t5
    ctx->r24 = ADD32(ctx->r11, ctx->r13);
    // 0x800C7268: lhu         $at, 0x0($t8)
    ctx->r1 = MEM_HU(ctx->r24, 0X0);
    // 0x800C726C: sh          $at, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r1;
    // 0x800C7270: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800C7274: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7278: lw          $t4, 0x60($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X60);
    // 0x800C727C: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x800C7280: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800C7284: bne         $at, $zero, L_800C72B4
    if (ctx->r1 != 0) {
        // 0x800C7288: nop
    
            goto L_800C72B4;
    }
    // 0x800C7288: nop

    // 0x800C728C: lbu         $t3, 0x0($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X0);
    // 0x800C7290: lbu         $t5, 0x64($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X64);
    // 0x800C7294: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C7298: beq         $at, $zero, L_800C72B4
    if (ctx->r1 == 0) {
        // 0x800C729C: nop
    
            goto L_800C72B4;
    }
    // 0x800C729C: nop

    // 0x800C72A0: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x800C72A4: blez        $t7, L_800C72B4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C72A8: slti        $at, $t7, 0x80
        ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
            goto L_800C72B4;
    }
    // 0x800C72A8: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800C72AC: bne         $at, $zero, L_800C72D8
    if (ctx->r1 != 0) {
        // 0x800C72B0: nop
    
            goto L_800C72D8;
    }
    // 0x800C72B0: nop

L_800C72B4:
    // 0x800C72B4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C72B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C72BC: lhu         $t8, 0x0($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X0);
    // 0x800C72C0: bne         $t8, $at, L_800C72D0
    if (ctx->r24 != ctx->r1) {
        // 0x800C72C4: nop
    
            goto L_800C72D0;
    }
    // 0x800C72C4: nop

    // 0x800C72C8: b           L_800C72DC
    // 0x800C72CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800C72DC;
    // 0x800C72CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800C72D0:
    // 0x800C72D0: b           L_800C72DC
    // 0x800C72D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800C72DC;
    // 0x800C72D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800C72D8:
    // 0x800C72D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C72DC:
    // 0x800C72DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C72E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C72E4: jr          $ra
    // 0x800C72E8: nop

    return;
    // 0x800C72E8: nop

;}
RECOMP_FUNC void func_800C76EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76EC: nop

;}
RECOMP_FUNC void func_800C7724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7724: nop

    // 0x800C7728: nop

    // 0x800C772C: nop

;}
RECOMP_FUNC void func_800C79A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79A4: nop

    // 0x800C79A8: nop

    // 0x800C79AC: nop

;}
RECOMP_FUNC void func_800C79BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79BC: nop

;}
RECOMP_FUNC void func_800C7A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A3C: nop

;}
RECOMP_FUNC void func_800C7AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AE8: nop

    // 0x800C7AEC: nop

    // 0x800C7AF0: jr          $ra
    // 0x800C7AF4: nop

    return;
    // 0x800C7AF4: nop

;}
RECOMP_FUNC void func_800C7C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C30: jr          $ra
    // 0x800C7C34: nop

    return;
    // 0x800C7C34: nop

;}
