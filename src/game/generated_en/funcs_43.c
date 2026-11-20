#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800B8038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B803C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B8044: jal         0x80031728
    // 0x800B8048: nop

    func_80031728(rdram, ctx);
        goto after_0;
    // 0x800B8048: nop

    after_0:
    // 0x800B804C: ori         $t6, $zero, 0xC00A
    ctx->r14 = 0 | 0XC00A;
    // 0x800B8050: addiu       $t7, $sp, 0x18
    ctx->r15 = ADD32(ctx->r29, 0X18);
    // 0x800B8054: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x800B8058: ori         $t8, $zero, 0xE007
    ctx->r24 = 0 | 0XE007;
    // 0x800B805C: addiu       $t9, $sp, 0x18
    ctx->r25 = ADD32(ctx->r29, 0X18);
    // 0x800B8060: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x800B8064: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x800B8068: addiu       $t1, $sp, 0x18
    ctx->r9 = ADD32(ctx->r29, 0X18);
    // 0x800B806C: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
    // 0x800B8070: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800B8074: addiu       $t3, $sp, 0x18
    ctx->r11 = ADD32(ctx->r29, 0X18);
    // 0x800B8078: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
    // 0x800B807C: jal         0x800B77D8
    // 0x800B8080: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800B77D8(rdram, ctx);
        goto after_1;
    // 0x800B8080: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800B8084: b           L_800B8094
    // 0x800B8088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B8094;
    // 0x800B8088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B808C: b           L_800B8094
    // 0x800B8090: nop

        goto L_800B8094;
    // 0x800B8090: nop

L_800B8094:
    // 0x800B8094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B809C: jr          $ra
    // 0x800B80A0: nop

    return;
    // 0x800B80A0: nop

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
RECOMP_FUNC void func_800B8104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8104: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800B8108: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800B810C:
    // 0x800B810C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800B8110: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B8114: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B8118: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B811C: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x800B8120: nop

    // 0x800B8124: beq         $t8, $zero, L_800B8184
    if (ctx->r24 == 0) {
        // 0x800B8128: sw          $t8, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r24;
            goto L_800B8184;
    }
    // 0x800B8128: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800B812C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800B8130: nop

    // 0x800B8134: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x800B8138: nop

    // 0x800B813C: beq         $t0, $zero, L_800B8184
    if (ctx->r8 == 0) {
        // 0x800B8140: sw          $t0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r8;
            goto L_800B8184;
    }
    // 0x800B8140: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x800B8144: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800B8148: nop

    // 0x800B814C: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x800B8150: nop

    // 0x800B8154: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x800B8158: bne         $t3, $zero, L_800B817C
    if (ctx->r11 != 0) {
        // 0x800B815C: nop

            goto L_800B817C;
    }
    // 0x800B815C: nop

    // 0x800B8160: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x800B8164: nop

    // 0x800B8168: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800B816C: nop

    // 0x800B8170: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800B8174: beq         $t6, $zero, L_800B8184
    if (ctx->r14 == 0) {
        // 0x800B8178: nop

            goto L_800B8184;
    }
    // 0x800B8178: nop

L_800B817C:
    // 0x800B817C: b           L_800B81AC
    // 0x800B8180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B81AC;
    // 0x800B8180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B8184:
    // 0x800B8184: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800B8188: nop

    // 0x800B818C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B8190: slti        $at, $t8, 0x14
    ctx->r1 = SIGNED(ctx->r24) < 0X14 ? 1 : 0;
    // 0x800B8194: bne         $at, $zero, L_800B810C
    if (ctx->r1 != 0) {
        // 0x800B8198: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_800B810C;
    }
    // 0x800B8198: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800B819C: b           L_800B81AC
    // 0x800B81A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B81AC;
    // 0x800B81A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B81A4: b           L_800B81AC
    // 0x800B81A8: nop

        goto L_800B81AC;
    // 0x800B81A8: nop

L_800B81AC:
    // 0x800B81AC: jr          $ra
    // 0x800B81B0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800B81B0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800B81B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B81B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B81B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B81BC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B81C0:
    // 0x800B81C0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B81C4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B81C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B81CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B81D0: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x800B81D4: nop

    // 0x800B81D8: beq         $t8, $zero, L_800B82A8
    if (ctx->r24 == 0) {
        // 0x800B81DC: sw          $t8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r24;
            goto L_800B82A8;
    }
    // 0x800B81DC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B81E0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B81E4: nop

    // 0x800B81E8: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x800B81EC: nop

    // 0x800B81F0: beq         $t0, $zero, L_800B8294
    if (ctx->r8 == 0) {
        // 0x800B81F4: nop

            goto L_800B8294;
    }
    // 0x800B81F4: nop

    // 0x800B81F8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800B81FC: nop

    // 0x800B8200: lw          $t2, 0x1AC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1AC);
    // 0x800B8204: nop

    // 0x800B8208: slti        $at, $t2, 0x4000
    ctx->r1 = SIGNED(ctx->r10) < 0X4000 ? 1 : 0;
    // 0x800B820C: bne         $at, $zero, L_800B8224
    if (ctx->r1 != 0) {
        // 0x800B8210: nop

            goto L_800B8224;
    }
    // 0x800B8210: nop

    // 0x800B8214: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x800B8218: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800B821C: bne         $at, $zero, L_800B8294
    if (ctx->r1 != 0) {
        // 0x800B8220: nop

            goto L_800B8294;
    }
    // 0x800B8220: nop

L_800B8224:
    // 0x800B8224: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B8228: nop

    // 0x800B822C: lw          $t4, 0x20C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20C);
    // 0x800B8230: nop

    // 0x800B8234: beq         $t4, $zero, L_800B8294
    if (ctx->r12 == 0) {
        // 0x800B8238: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B8294;
    }
    // 0x800B8238: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B823C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8240: nop

    // 0x800B8244: lhu         $a2, 0x6($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X6);
    // 0x800B8248: addiu       $a0, $t5, 0xC
    ctx->r4 = ADD32(ctx->r13, 0XC);
    // 0x800B824C: jal         0x800B1C10
    // 0x800B8250: addiu       $a1, $t5, 0x10
    ctx->r5 = ADD32(ctx->r13, 0X10);
    func_800B1C10(rdram, ctx);
        goto after_0;
    // 0x800B8250: addiu       $a1, $t5, 0x10
    ctx->r5 = ADD32(ctx->r13, 0X10);
    after_0:
    // 0x800B8254: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B8258: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B825C: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800B8260: nop

    // 0x800B8264: bne         $t7, $at, L_800B8294
    if (ctx->r15 != ctx->r1) {
        // 0x800B8268: nop

            goto L_800B8294;
    }
    // 0x800B8268: nop

    // 0x800B826C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8270: nop

    // 0x800B8274: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800B8278: nop

    // 0x800B827C: andi        $t0, $t9, 0x200
    ctx->r8 = ctx->r25 & 0X200;
    // 0x800B8280: beq         $t0, $zero, L_800B8294
    if (ctx->r8 == 0) {
        // 0x800B8284: nop

            goto L_800B8294;
    }
    // 0x800B8284: nop

    // 0x800B8288: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B828C: jal         0x800B82D8
    // 0x800B8290: nop

    func_800B82D8(rdram, ctx);
        goto after_1;
    // 0x800B8290: nop

    after_1:
L_800B8294:
    // 0x800B8294: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B8298: jal         0x8000D74C
    // 0x800B829C: nop

    func_8000D74C(rdram, ctx);
        goto after_2;
    // 0x800B829C: nop

    after_2:
    // 0x800B82A0: beq         $v0, $zero, L_800B82A8
    if (ctx->r2 == 0) {
        // 0x800B82A4: nop

            goto L_800B82A8;
    }
    // 0x800B82A4: nop

L_800B82A8:
    // 0x800B82A8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B82AC: nop

    // 0x800B82B0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B82B4: slti        $at, $t2, 0x14
    ctx->r1 = SIGNED(ctx->r10) < 0X14 ? 1 : 0;
    // 0x800B82B8: bne         $at, $zero, L_800B81C0
    if (ctx->r1 != 0) {
        // 0x800B82BC: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800B81C0;
    }
    // 0x800B82BC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800B82C0: b           L_800B82C8
    // 0x800B82C4: nop

        goto L_800B82C8;
    // 0x800B82C4: nop

L_800B82C8:
    // 0x800B82C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B82CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B82D0: jr          $ra
    // 0x800B82D4: nop

    return;
    // 0x800B82D4: nop

;}
RECOMP_FUNC void func_800B82D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B82D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B82DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B82E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B82E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B82E8: nop

    // 0x800B82EC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800B82F0: nop

    // 0x800B82F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800B82F8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B82FC: nop

    // 0x800B8300: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x800B8304: nop

    // 0x800B8308: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800B830C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B8310: nop

    // 0x800B8314: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B8318: jal         0x8001AE90
    // 0x800B831C: nop

    func_8001AE90(rdram, ctx);
        goto after_0;
    // 0x800B831C: nop

    after_0:
    // 0x800B8320: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800B8324: nop

    // 0x800B8328: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800B832C: jal         0x8000D390
    // 0x800B8330: nop

    TempHeap_Free(rdram, ctx);
        goto after_1;
    // 0x800B8330: nop

    after_1:
    // 0x800B8334: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8338: nop

    // 0x800B833C: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x800B8340: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B8344: nop

    // 0x800B8348: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B834C: jal         0x8000D390
    // 0x800B8350: nop

    TempHeap_Free(rdram, ctx);
        goto after_2;
    // 0x800B8350: nop

    after_2:
    // 0x800B8354: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B8358: nop

    // 0x800B835C: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x800B8360: jal         0x8000D390
    // 0x800B8364: nop

    TempHeap_Free(rdram, ctx);
        goto after_3;
    // 0x800B8364: nop

    after_3:
    // 0x800B8368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B836C: jal         0x8000D390
    // 0x800B8370: nop

    TempHeap_Free(rdram, ctx);
        goto after_4;
    // 0x800B8370: nop

    after_4:
    // 0x800B8374: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8378: nop

    // 0x800B837C: sw          $zero, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = 0;
    // 0x800B8380: b           L_800B8388
    // 0x800B8384: nop

        goto L_800B8388;
    // 0x800B8384: nop

L_800B8388:
    // 0x800B8388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B838C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B8390: jr          $ra
    // 0x800B8394: nop

    return;
    // 0x800B8394: nop

;}
RECOMP_FUNC void func_800B8398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8398: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B839C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B83A0: sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // 0x800B83A4: jal         0x80016074
    // 0x800B83A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800B83A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x800B83AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B83B0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B83B4: nop

    // 0x800B83B8: beq         $t6, $zero, L_800B83EC
    if (ctx->r14 == 0) {
        // 0x800B83BC: nop

            goto L_800B83EC;
    }
    // 0x800B83BC: nop

    // 0x800B83C0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B83C4: nop

    // 0x800B83C8: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x800B83CC: nop

    // 0x800B83D0: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800B83D4: bne         $t9, $zero, L_800B83EC
    if (ctx->r25 != 0) {
        // 0x800B83D8: nop

            goto L_800B83EC;
    }
    // 0x800B83D8: nop

    // 0x800B83DC: lhu         $t0, 0x1A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B83E0: nop

    // 0x800B83E4: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x800B83E8: sh          $t1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r9;
L_800B83EC:
    // 0x800B83EC: jal         0x80016074
    // 0x800B83F0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80016074(rdram, ctx);
        goto after_1;
    // 0x800B83F0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x800B83F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B83F8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B83FC: nop

    // 0x800B8400: beq         $t2, $zero, L_800B8434
    if (ctx->r10 == 0) {
        // 0x800B8404: nop

            goto L_800B8434;
    }
    // 0x800B8404: nop

    // 0x800B8408: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B840C: nop

    // 0x800B8410: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x800B8414: nop

    // 0x800B8418: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800B841C: bne         $t5, $zero, L_800B8434
    if (ctx->r13 != 0) {
        // 0x800B8420: nop

            goto L_800B8434;
    }
    // 0x800B8420: nop

    // 0x800B8424: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B8428: nop

    // 0x800B842C: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x800B8430: sh          $t7, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r15;
L_800B8434:
    // 0x800B8434: jal         0x80016074
    // 0x800B8438: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_2;
    // 0x800B8438: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x800B843C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B8440: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8444: nop

    // 0x800B8448: beq         $t8, $zero, L_800B847C
    if (ctx->r24 == 0) {
        // 0x800B844C: nop

            goto L_800B847C;
    }
    // 0x800B844C: nop

    // 0x800B8450: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8454: nop

    // 0x800B8458: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x800B845C: nop

    // 0x800B8460: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800B8464: bne         $t1, $zero, L_800B847C
    if (ctx->r9 != 0) {
        // 0x800B8468: nop

            goto L_800B847C;
    }
    // 0x800B8468: nop

    // 0x800B846C: lhu         $t2, 0x1A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B8470: nop

    // 0x800B8474: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x800B8478: sh          $t3, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r11;
L_800B847C:
    // 0x800B847C: jal         0x80016074
    // 0x800B8480: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_3;
    // 0x800B8480: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_3:
    // 0x800B8484: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B8488: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B848C: nop

    // 0x800B8490: beq         $t4, $zero, L_800B84C4
    if (ctx->r12 == 0) {
        // 0x800B8494: nop

            goto L_800B84C4;
    }
    // 0x800B8494: nop

    // 0x800B8498: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B849C: nop

    // 0x800B84A0: lw          $t6, 0x1A8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1A8);
    // 0x800B84A4: nop

    // 0x800B84A8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x800B84AC: bne         $t7, $zero, L_800B84C4
    if (ctx->r15 != 0) {
        // 0x800B84B0: nop

            goto L_800B84C4;
    }
    // 0x800B84B0: nop

    // 0x800B84B4: lhu         $t8, 0x1A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B84B8: nop

    // 0x800B84BC: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x800B84C0: sh          $t9, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r25;
L_800B84C4:
    // 0x800B84C4: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x800B84C8: b           L_800B84D8
    // 0x800B84CC: nop

        goto L_800B84D8;
    // 0x800B84CC: nop

    // 0x800B84D0: b           L_800B84D8
    // 0x800B84D4: nop

        goto L_800B84D8;
    // 0x800B84D4: nop

L_800B84D8:
    // 0x800B84D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B84DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B84E0: jr          $ra
    // 0x800B84E4: nop

    return;
    // 0x800B84E4: nop

    // 0x800B84E8: nop

    // 0x800B84EC: nop

;}
RECOMP_FUNC void func_800B84F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B84F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B84F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B84F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B84FC: sw          $zero, -0x3068($at)
    MEM_W(-0X3068, ctx->r1) = 0;
    // 0x800B8500: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8504: sw          $zero, -0x33C0($at)
    MEM_W(-0X33C0, ctx->r1) = 0;
    // 0x800B8508: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B850C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8510: sw          $t6, -0x3464($at)
    MEM_W(-0X3464, ctx->r1) = ctx->r14;
    // 0x800B8514: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8518: sw          $zero, -0x3364($at)
    MEM_W(-0X3364, ctx->r1) = 0;
    // 0x800B851C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8520: sb          $zero, -0x3370($at)
    MEM_B(-0X3370, ctx->r1) = 0;
    // 0x800B8524: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8528: sw          $zero, -0x33B4($at)
    MEM_W(-0X33B4, ctx->r1) = 0;
    // 0x800B852C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B8530: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B8534: addiu       $a1, $a1, -0x1E30
    ctx->r5 = ADD32(ctx->r5, -0X1E30);
    // 0x800B8538: addiu       $a0, $a0, -0x1E48
    ctx->r4 = ADD32(ctx->r4, -0X1E48);
    // 0x800B853C: jal         0x800C42B0
    // 0x800B8540: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800B8540: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800B8544: lui         $a0, 0x5
    ctx->r4 = S32(0X5 << 16);
    // 0x800B8548: jal         0x800BC918
    // 0x800B854C: ori         $a0, $a0, 0xF380
    ctx->r4 = ctx->r4 | 0XF380;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_1;
    // 0x800B854C: ori         $a0, $a0, 0xF380
    ctx->r4 = ctx->r4 | 0XF380;
    after_1:
    // 0x800B8550: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8554: sw          $v0, -0x307C($at)
    MEM_W(-0X307C, ctx->r1) = ctx->r2;
    // 0x800B8558: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800B855C: lw          $t7, -0x307C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X307C);
    // 0x800B8560: nop

    // 0x800B8564: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x800B8568: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B856C: lw          $t8, -0x307C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X307C);
    // 0x800B8570: lui         $a2, 0x5
    ctx->r6 = S32(0X5 << 16);
    // 0x800B8574: ori         $a2, $a2, 0xF37F
    ctx->r6 = ctx->r6 | 0XF37F;
    // 0x800B8578: addiu       $a0, $t8, 0x1
    ctx->r4 = ADD32(ctx->r24, 0X1);
    // 0x800B857C: jal         0x800BCFCC
    // 0x800B8580: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x800B8580: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_2:
    // 0x800B8584: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B8588: lw          $a1, -0x307C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X307C);
    // 0x800B858C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800B8590: addiu       $a1, $a1, 0xF
    ctx->r5 = ADD32(ctx->r5, 0XF);
    // 0x800B8594: and         $t9, $a1, $at
    ctx->r25 = ctx->r5 & ctx->r1;
    // 0x800B8598: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B859C: lui         $a2, 0x5
    ctx->r6 = S32(0X5 << 16);
    // 0x800B85A0: ori         $a2, $a2, 0xF370
    ctx->r6 = ctx->r6 | 0XF370;
    // 0x800B85A4: addiu       $a0, $a0, -0x3078
    ctx->r4 = ADD32(ctx->r4, -0X3078);
    // 0x800B85A8: jal         0x800C76F0
    // 0x800B85AC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    alHeapInit(rdram, ctx);
        goto after_3;
    // 0x800B85AC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_3:
    // 0x800B85B0: jal         0x800C7730
    // 0x800B85B4: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_4;
    // 0x800B85B4: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    after_4:
    // 0x800B85B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B85BC: sw          $v0, -0x33F8($at)
    MEM_W(-0X33F8, ctx->r1) = ctx->r2;
    // 0x800B85C0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B85C4: lw          $t0, -0x33F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X33F8);
    // 0x800B85C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B85CC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B85D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B85D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B85D8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800B85DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B85E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B85E4: nop

    // 0x800B85E8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B85EC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800B85F0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B85F4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B85F8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B85FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B8600: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B8604: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8608: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B860C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B8610: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B8614: sw          $t2, -0x33CC($at)
    MEM_W(-0X33CC, ctx->r1) = ctx->r10;
    // 0x800B8618: nop

    // 0x800B861C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800B8620: lw          $t3, -0x33CC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X33CC);
    // 0x800B8624: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B8628: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800B862C: nop

    // 0x800B8630: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B8634: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800B8638: nop

    // 0x800B863C: bc1f        L_800B8658
    if (!c1cs) {
        // 0x800B8640: nop

            goto L_800B8658;
    }
    // 0x800B8640: nop

    // 0x800B8644: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800B8648: lw          $t4, -0x33CC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X33CC);
    // 0x800B864C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8650: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B8654: sw          $t5, -0x33CC($at)
    MEM_W(-0X33CC, ctx->r1) = ctx->r13;
L_800B8658:
    // 0x800B8658: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B865C: lw          $t6, -0x33CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33CC);
    // 0x800B8660: nop

    // 0x800B8664: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800B8668: beq         $t7, $zero, L_800B868C
    if (ctx->r15 == 0) {
        // 0x800B866C: nop

            goto L_800B868C;
    }
    // 0x800B866C: nop

    // 0x800B8670: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B8674: lw          $t8, -0x33CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X33CC);
    // 0x800B8678: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800B867C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800B8680: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800B8684: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8688: sw          $t0, -0x33CC($at)
    MEM_W(-0X33CC, ctx->r1) = ctx->r8;
L_800B868C:
    // 0x800B868C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B8690: lw          $t1, -0x33CC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33CC);
    // 0x800B8694: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8698: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x800B869C: sw          $t2, -0x33C8($at)
    MEM_W(-0X33C8, ctx->r1) = ctx->r10;
    // 0x800B86A0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800B86A4: lw          $t3, -0x33CC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X33CC);
    // 0x800B86A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B86AC: addiu       $t4, $t3, 0x60
    ctx->r12 = ADD32(ctx->r11, 0X60);
    // 0x800B86B0: sw          $t4, -0x33C4($at)
    MEM_W(-0X33C4, ctx->r1) = ctx->r12;
    // 0x800B86B4: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x800B86B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B86BC: sw          $t5, -0x3410($at)
    MEM_W(-0X3410, ctx->r1) = ctx->r13;
    // 0x800B86C0: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x800B86C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B86C8: sw          $t6, -0x340C($at)
    MEM_W(-0X340C, ctx->r1) = ctx->r14;
    // 0x800B86CC: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800B86D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B86D4: sw          $t7, -0x3408($at)
    MEM_W(-0X3408, ctx->r1) = ctx->r15;
    // 0x800B86D8: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800B86DC: addiu       $t8, $t8, -0x6C84
    ctx->r24 = ADD32(ctx->r24, -0X6C84);
    // 0x800B86E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B86E4: sw          $t8, -0x3400($at)
    MEM_W(-0X3400, ctx->r1) = ctx->r24;
    // 0x800B86E8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B86EC: addiu       $t9, $t9, -0x3078
    ctx->r25 = ADD32(ctx->r25, -0X3078);
    // 0x800B86F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B86F4: sw          $t9, -0x33FC($at)
    MEM_W(-0X33FC, ctx->r1) = ctx->r25;
    // 0x800B86F8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800B86FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8700: sb          $t0, -0x33F4($at)
    MEM_B(-0X33F4, ctx->r1) = ctx->r8;
    // 0x800B8704: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B8708: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B870C: addiu       $a1, $a1, -0x3410
    ctx->r5 = ADD32(ctx->r5, -0X3410);
    // 0x800B8710: jal         0x800C791C
    // 0x800B8714: addiu       $a0, $a0, -0x3460
    ctx->r4 = ADD32(ctx->r4, -0X3460);
    alInit(rdram, ctx);
        goto after_5;
    // 0x800B8714: addiu       $a0, $a0, -0x3460
    ctx->r4 = ADD32(ctx->r4, -0X3460);
    after_5:
    // 0x800B8718: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B871C:
    // 0x800B871C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B8720: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8724: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B8728: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B872C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B8730: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800B8734: sw          $zero, -0x25C4($at)
    MEM_W(-0X25C4, ctx->r1) = 0;
    // 0x800B8738: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B873C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8740: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B8744: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B8748: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B874C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B8750: sw          $zero, -0x25C8($at)
    MEM_W(-0X25C8, ctx->r1) = 0;
    // 0x800B8754: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B8758: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B875C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B8760: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800B8764: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B8768: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B876C: sw          $zero, -0x25C0($at)
    MEM_W(-0X25C0, ctx->r1) = 0;
    // 0x800B8770: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B8774: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8778: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B877C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B8780: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B8784: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B8788: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800B878C: sw          $t7, -0x25BC($at)
    MEM_W(-0X25BC, ctx->r1) = ctx->r15;
    // 0x800B8790: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B8794: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8798: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B879C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800B87A0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B87A4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800B87A8: sw          $zero, -0x25B8($at)
    MEM_W(-0X25B8, ctx->r1) = 0;
    // 0x800B87AC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B87B0: nop

    // 0x800B87B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B87B8: slti        $at, $t3, 0x60
    ctx->r1 = SIGNED(ctx->r11) < 0X60 ? 1 : 0;
    // 0x800B87BC: bne         $at, $zero, L_800B871C
    if (ctx->r1 != 0) {
        // 0x800B87C0: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_800B871C;
    }
    // 0x800B87C0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800B87C4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B87C8:
    // 0x800B87C8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B87CC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B87D0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B87D4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800B87D8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B87DC: addiu       $t6, $t5, 0x14
    ctx->r14 = ADD32(ctx->r13, 0X14);
    // 0x800B87E0: addiu       $t8, $t8, -0x25C8
    ctx->r24 = ADD32(ctx->r24, -0X25C8);
    // 0x800B87E4: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800B87E8: jal         0x800C78C0
    // 0x800B87EC: addu        $a1, $t5, $t8
    ctx->r5 = ADD32(ctx->r13, ctx->r24);
    alLink(rdram, ctx);
        goto after_6;
    // 0x800B87EC: addu        $a1, $t5, $t8
    ctx->r5 = ADD32(ctx->r13, ctx->r24);
    after_6:
    // 0x800B87F0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B87F4: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B87F8: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x800B87FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800B8800: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B8804: addiu       $a0, $a0, -0x520
    ctx->r4 = ADD32(ctx->r4, -0X520);
    // 0x800B8808: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x800B880C: jal         0x800C7950
    // 0x800B8810: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_7;
    // 0x800B8810: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x800B8814: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B8818: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B881C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800B8820: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B8824: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800B8828: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800B882C: sw          $v0, -0x25B8($at)
    MEM_W(-0X25B8, ctx->r1) = ctx->r2;
    // 0x800B8830: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B8834: nop

    // 0x800B8838: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B883C: slti        $at, $t2, 0x5F
    ctx->r1 = SIGNED(ctx->r10) < 0X5F ? 1 : 0;
    // 0x800B8840: bne         $at, $zero, L_800B87C8
    if (ctx->r1 != 0) {
        // 0x800B8844: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800B87C8;
    }
    // 0x800B8844: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800B8848: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B884C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B8850: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x800B8854: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800B8858: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B885C: addiu       $a0, $a0, -0x50C
    ctx->r4 = ADD32(ctx->r4, -0X50C);
    // 0x800B8860: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x800B8864: jal         0x800C7950
    // 0x800B8868: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x800B8868: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x800B886C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B8870: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8874: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800B8878: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800B887C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B8880: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B8884: sw          $v0, -0x25B8($at)
    MEM_W(-0X25B8, ctx->r1) = ctx->r2;
    // 0x800B8888: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B888C:
    // 0x800B888C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8890: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B8894: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x800B8898: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800B889C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B88A0: addiu       $a0, $a0, -0x4F8
    ctx->r4 = ADD32(ctx->r4, -0X4F8);
    // 0x800B88A4: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x800B88A8: jal         0x800C7950
    // 0x800B88AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_9;
    // 0x800B88AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x800B88B0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B88B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B88B8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800B88BC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B88C0: sw          $v0, -0x34B0($at)
    MEM_W(-0X34B0, ctx->r1) = ctx->r2;
    // 0x800B88C4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B88C8: nop

    // 0x800B88CC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B88D0: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800B88D4: bne         $at, $zero, L_800B888C
    if (ctx->r1 != 0) {
        // 0x800B88D8: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_800B888C;
    }
    // 0x800B88D8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800B88DC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B88E0:
    // 0x800B88E0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B88E4: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B88E8: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x800B88EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800B88F0: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B88F4: addiu       $a0, $a0, -0x4E4
    ctx->r4 = ADD32(ctx->r4, -0X4E4);
    // 0x800B88F8: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    // 0x800B88FC: jal         0x800C7950
    // 0x800B8900: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x800B8900: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x800B8904: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B8908: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B890C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B8910: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800B8914: sw          $v0, -0x34A8($at)
    MEM_W(-0X34A8, ctx->r1) = ctx->r2;
    // 0x800B8918: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B891C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B8920: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x800B8924: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x800B8928: lw          $t8, -0x34A8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X34A8);
    // 0x800B892C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800B8930: sh          $t4, 0x60($t8)
    MEM_H(0X60, ctx->r24) = ctx->r12;
    // 0x800B8934: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8938: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B893C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B8940: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B8944: lw          $t0, -0x34A8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X34A8);
    // 0x800B8948: nop

    // 0x800B894C: sw          $t0, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->r8;
    // 0x800B8950: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B8954: lw          $t1, -0x33C4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33C4);
    // 0x800B8958: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B895C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B8960: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B8964: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800B8968: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B896C: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    // 0x800B8970: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    // 0x800B8974: jal         0x800C7950
    // 0x800B8978: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_11;
    // 0x800B8978: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x800B897C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B8980: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800B8984: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800B8988: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800B898C: lw          $t5, -0x34A8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X34A8);
    // 0x800B8990: nop

    // 0x800B8994: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x800B8998: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B899C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800B89A0: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800B89A4: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800B89A8: lw          $t7, -0x34A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X34A8);
    // 0x800B89AC: nop

    // 0x800B89B0: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x800B89B4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B89B8: nop

    // 0x800B89BC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B89C0: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800B89C4: bne         $at, $zero, L_800B88E0
    if (ctx->r1 != 0) {
        // 0x800B89C8: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_800B88E0;
    }
    // 0x800B89C8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800B89CC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B89D0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B89D4: addiu       $a1, $a1, -0x3048
    ctx->r5 = ADD32(ctx->r5, -0X3048);
    // 0x800B89D8: addiu       $a0, $a0, -0x3060
    ctx->r4 = ADD32(ctx->r4, -0X3060);
    // 0x800B89DC: jal         0x800C42B0
    // 0x800B89E0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_12;
    // 0x800B89E0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_12:
    // 0x800B89E4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B89E8: addiu       $t1, $t1, -0x34B0
    ctx->r9 = ADD32(ctx->r9, -0X34B0);
    // 0x800B89EC: addiu       $a0, $t1, 0x14
    ctx->r4 = ADD32(ctx->r9, 0X14);
    // 0x800B89F0: addiu       $a1, $t1, 0x2C
    ctx->r5 = ADD32(ctx->r9, 0X2C);
    // 0x800B89F4: jal         0x800C42B0
    // 0x800B89F8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_13;
    // 0x800B89F8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_13:
    // 0x800B89FC: jal         0x800B9580
    // 0x800B8A00: nop

    AudioDriver_Init(rdram, ctx);
        goto after_14;
    // 0x800B8A00: nop

    after_14:
    // 0x800B8A04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8A08: sw          $zero, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = 0;
    // 0x800B8A0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8A10: sw          $zero, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = 0;
    // 0x800B8A14: b           L_800B8A1C
    // 0x800B8A18: nop

        goto L_800B8A1C;
    // 0x800B8A18: nop

L_800B8A1C:
    // 0x800B8A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8A20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B8A24: jr          $ra
    // 0x800B8A28: nop

    return;
    // 0x800B8A28: nop

;}
RECOMP_FUNC void AudioMgr_InitThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8A2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B8A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8A34: jal         0x800B84F0
    // 0x800B8A38: nop

    func_800B84F0(rdram, ctx);
        goto after_0;
    // 0x800B8A38: nop

    after_0:
    // 0x800B8A3C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800B8A40: addiu       $a0, $a0, -0x7584
    ctx->r4 = ADD32(ctx->r4, -0X7584);
    // 0x800B8A44: jal         0x800C0780
    // 0x800B8A48: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    Thread_CreateExtended(rdram, ctx);
        goto after_1;
    // 0x800B8A48: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x800B8A4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B8A50: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8A54: nop

    // 0x800B8A58: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800B8A5C: jal         0x800C0C8C
    // 0x800B8A60: nop

    Thread_Start(rdram, ctx);
        goto after_2;
    // 0x800B8A60: nop

    after_2:
    // 0x800B8A64: b           L_800B8A6C
    // 0x800B8A68: nop

        goto L_800B8A6C;
    // 0x800B8A68: nop

L_800B8A6C:
    // 0x800B8A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B8A74: jr          $ra
    // 0x800B8A78: nop

    return;
    // 0x800B8A78: nop

;}
RECOMP_FUNC void AudioMgr_AudioThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8A7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B8A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8A84: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B8A88: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B8A8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B8A90: nop

    // 0x800B8A94: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B8A98: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8A9C: nop

    // 0x800B8AA0: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800B8AA4: nop

    // 0x800B8AA8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B8AAC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B8AB0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800B8AB4: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800B8AB8: addiu       $t1, $t1, 0x3DF8
    ctx->r9 = ADD32(ctx->r9, 0X3DF8);
    // 0x800B8ABC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800B8AC0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800B8AC4: nop

    // 0x800B8AC8: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x800B8ACC: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x800B8AD0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B8AD4: nop

    // 0x800B8AD8: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x800B8ADC: jal         0x80098688
    // 0x800B8AE0: nop

    func_80098688(rdram, ctx);
        goto after_0;
    // 0x800B8AE0: nop

    after_0:
    // 0x800B8AE4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B8AE8: nop

    // 0x800B8AEC: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x800B8AF0: jal         0x80098894
    // 0x800B8AF4: nop

    func_80098894(rdram, ctx);
        goto after_1;
    // 0x800B8AF4: nop

    after_1:
L_800B8AF8:
    // 0x800B8AF8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B8AFC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800B8B00: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x800B8B04: jal         0x800C143C
    // 0x800B8B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_2;
    // 0x800B8B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800B8B0C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8B10: nop

    // 0x800B8B14: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800B8B18: nop

    // 0x800B8B1C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B8B20: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x800B8B24: beq         $at, $zero, L_800B8C78
    if (ctx->r1 == 0) {
        // 0x800B8B28: nop

            goto L_800B8C78;
    }
    // 0x800B8B28: nop

    // 0x800B8B2C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B8B30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B8B34: addu        $at, $at, $t8
    gpr jr_addend_800B8B40 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B8B38: lw          $t8, -0x4A8($at)
    ctx->r24 = ADD32(ctx->r1, -0X4A8);
    // 0x800B8B3C: nop

    // 0x800B8B40: jr          $t8
    // 0x800B8B44: nop

    switch (jr_addend_800B8B40 >> 2) {
        case 0: goto L_800B8B48; break;
        case 1: goto L_800B8C78; break;
        case 2: goto L_800B8C78; break;
        case 3: goto L_800B8C58; break;
        case 4: goto L_800B8B48; break;
        case 5: goto L_800B8C78; break;
        case 6: goto L_800B8C78; break;
        case 7: goto L_800B8C78; break;
        case 8: goto L_800B8C78; break;
        case 9: goto L_800B8C68; break;
        case 10: goto L_800B8C70; break;
        default: switch_error(__func__, 0x800B8B40, 0x800EFB58);
    }
    // 0x800B8B44: nop

L_800B8B48:
    // 0x800B8B48: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B8B4C: nop

    // 0x800B8B50: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x800B8B54: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x800B8B58: nop

    // 0x800B8B5C: bne         $t0, $zero, L_800B8C38
    if (ctx->r8 != 0) {
        // 0x800B8B60: nop

            goto L_800B8C38;
    }
    // 0x800B8B60: nop

    // 0x800B8B64: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B8B68: lw          $t1, -0x3364($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3364);
    // 0x800B8B6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B8B70: divu        $zero, $t1, $at
    lo = S32(U32(ctx->r9) / U32(ctx->r1)); hi = S32(U32(ctx->r9) % U32(ctx->r1));
    // 0x800B8B74: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B8B78: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B8B7C: mfhi        $t2
    ctx->r10 = hi;
    // 0x800B8B80: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B8B84: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x800B8B88: lw          $a0, -0x34A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34A8);
    // 0x800B8B8C: jal         0x800B8CA0
    // 0x800B8B90: nop

    AudioMgr_HandleFrameMsg(rdram, ctx);
        goto after_3;
    // 0x800B8B90: nop

    after_3:
    // 0x800B8B94: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B8B98: jal         0x800BAD4C
    // 0x800B8B9C: nop

    AudioDriver_Update(rdram, ctx);
        goto after_4;
    // 0x800B8B9C: nop

    after_4:
    // 0x800B8BA0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800B8BA4: nop

    // 0x800B8BA8: beq         $t4, $zero, L_800B8C18
    if (ctx->r12 == 0) {
        // 0x800B8BAC: nop

            goto L_800B8C18;
    }
    // 0x800B8BAC: nop

    // 0x800B8BB0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B8BB4: addiu       $a0, $a0, -0x34B0
    ctx->r4 = ADD32(ctx->r4, -0X34B0);
    // 0x800B8BB8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800B8BBC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800B8BC0: jal         0x800C1570
    // 0x800B8BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsg(rdram, ctx);
        goto after_5;
    // 0x800B8BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800B8BC8: jal         0x800C79B0
    // 0x800B8BCC: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_6;
    // 0x800B8BCC: nop

    after_6:
    // 0x800B8BD0: srl         $t5, $v0, 2
    ctx->r13 = S32(U32(ctx->r2) >> 2);
    // 0x800B8BD4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800B8BD8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B8BDC: nop

    // 0x800B8BE0: bne         $t6, $zero, L_800B8C04
    if (ctx->r14 != 0) {
        // 0x800B8BE4: nop

            goto L_800B8C04;
    }
    // 0x800B8BE4: nop

    // 0x800B8BE8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800B8BEC: lw          $t7, -0x3464($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3464);
    // 0x800B8BF0: nop

    // 0x800B8BF4: bne         $t7, $zero, L_800B8C04
    if (ctx->r15 != 0) {
        // 0x800B8BF8: nop

            goto L_800B8C04;
    }
    // 0x800B8BF8: nop

    // 0x800B8BFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8C00: sw          $zero, -0x3464($at)
    MEM_W(-0X3464, ctx->r1) = 0;
L_800B8C04:
    // 0x800B8C04: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8C08: nop

    // 0x800B8C0C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800B8C10: nop

    // 0x800B8C14: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800B8C18:
    // 0x800B8C18: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B8C1C: nop

    // 0x800B8C20: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800B8C24: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x800B8C28: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x800B8C2C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B8C30: b           L_800B8C50
    // 0x800B8C34: sw          $t2, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r10;
        goto L_800B8C50;
    // 0x800B8C34: sw          $t2, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r10;
L_800B8C38:
    // 0x800B8C38: jal         0x800BAD4C
    // 0x800B8C3C: nop

    AudioDriver_Update(rdram, ctx);
        goto after_7;
    // 0x800B8C3C: nop

    after_7:
    // 0x800B8C40: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B8C44: nop

    // 0x800B8C48: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x800B8C4C: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
L_800B8C50:
    // 0x800B8C50: b           L_800B8C80
    // 0x800B8C54: nop

        goto L_800B8C80;
    // 0x800B8C54: nop

L_800B8C58:
    // 0x800B8C58: b           L_800B8C58
    pause_self(rdram);
    // 0x800B8C5C: nop

    // 0x800B8C60: b           L_800B8C80
    // 0x800B8C64: nop

        goto L_800B8C80;
    // 0x800B8C64: nop

L_800B8C68:
    // 0x800B8C68: b           L_800B8C80
    // 0x800B8C6C: nop

        goto L_800B8C80;
    // 0x800B8C6C: nop

L_800B8C70:
    // 0x800B8C70: b           L_800B8C80
    // 0x800B8C74: nop

        goto L_800B8C80;
    // 0x800B8C74: nop

L_800B8C78:
    // 0x800B8C78: b           L_800B8C80
    // 0x800B8C7C: nop

        goto L_800B8C80;
    // 0x800B8C7C: nop

L_800B8C80:
    // 0x800B8C80: b           L_800B8AF8
    // 0x800B8C84: nop

        goto L_800B8AF8;
    // 0x800B8C84: nop

    // 0x800B8C88: b           L_800B8C90
    // 0x800B8C8C: nop

        goto L_800B8C90;
    // 0x800B8C8C: nop

L_800B8C90:
    // 0x800B8C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8C94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B8C98: jr          $ra
    // 0x800B8C9C: nop

    return;
    // 0x800B8C9C: nop

;}
RECOMP_FUNC void AudioMgr_HandleFrameMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8CA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B8CA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B8CA8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B8CAC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B8CB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B8CB4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800B8CB8: jal         0x800B93E0
    // 0x800B8CBC: nop

    AudioMgr_ClearAudioDMA(rdram, ctx);
        goto after_0;
    // 0x800B8CBC: nop

    after_0:
    // 0x800B8CC0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B8CC4: nop

    // 0x800B8CC8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800B8CCC: jal         0x800C79C0
    // 0x800B8CD0: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800B8CD0: nop

    after_1:
    // 0x800B8CD4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800B8CD8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B8CDC: nop

    // 0x800B8CE0: beq         $t7, $zero, L_800B8D04
    if (ctx->r15 == 0) {
        // 0x800B8CE4: nop

            goto L_800B8D04;
    }
    // 0x800B8CE4: nop

    // 0x800B8CE8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800B8CEC: nop

    // 0x800B8CF0: lh          $a1, 0x4($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X4);
    // 0x800B8CF4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800B8CF8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800B8CFC: jal         0x800C7A40
    // 0x800B8D00: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x800B8D00: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_2:
L_800B8D04:
    // 0x800B8D04: jal         0x800C79B0
    // 0x800B8D08: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_3;
    // 0x800B8D08: nop

    after_3:
    // 0x800B8D0C: srl         $t0, $v0, 2
    ctx->r8 = S32(U32(ctx->r2) >> 2);
    // 0x800B8D10: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B8D14: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B8D18: lw          $t1, -0x33CC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33CC);
    // 0x800B8D1C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800B8D20: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B8D24: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800B8D28: addiu       $t4, $t3, 0x60
    ctx->r12 = ADD32(ctx->r11, 0X60);
    // 0x800B8D2C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800B8D30: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800B8D34: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x800B8D38: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800B8D3C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B8D40: lw          $t9, -0x33C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33C8);
    // 0x800B8D44: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x800B8D48: nop

    // 0x800B8D4C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B8D50: beq         $at, $zero, L_800B8D6C
    if (ctx->r1 == 0) {
        // 0x800B8D54: nop

            goto L_800B8D6C;
    }
    // 0x800B8D54: nop

    // 0x800B8D58: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B8D5C: lw          $t0, -0x33C8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X33C8);
    // 0x800B8D60: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B8D64: nop

    // 0x800B8D68: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
L_800B8D6C:
    // 0x800B8D6C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800B8D70: lw          $t2, -0x33C0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X33C0);
    // 0x800B8D74: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B8D78: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B8D7C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B8D80: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x800B8D84: lw          $a0, -0x34B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34B0);
    // 0x800B8D88: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B8D8C: lh          $a3, 0x4($t4)
    ctx->r7 = MEM_H(ctx->r12, 0X4);
    // 0x800B8D90: jal         0x800C7C38
    // 0x800B8D94: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    alAudioFrame(rdram, ctx);
        goto after_4;
    // 0x800B8D94: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x800B8D98: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B8D9C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B8DA0: nop

    // 0x800B8DA4: bne         $t5, $zero, L_800B8DB4
    if (ctx->r13 != 0) {
        // 0x800B8DA8: nop

            goto L_800B8DB4;
    }
    // 0x800B8DA8: nop

    // 0x800B8DAC: b           L_800B8F5C
    // 0x800B8DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B8F5C;
    // 0x800B8DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B8DB4:
    // 0x800B8DB4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B8DB8: nop

    // 0x800B8DBC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800B8DC0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800B8DC4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DC8: nop

    // 0x800B8DCC: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800B8DD0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B8DD4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DD8: addiu       $t9, $t9, -0x34B0
    ctx->r25 = ADD32(ctx->r25, -0X34B0);
    // 0x800B8DDC: addiu       $t0, $t9, 0x14
    ctx->r8 = ADD32(ctx->r25, 0X14);
    // 0x800B8DE0: sw          $t0, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->r8;
    // 0x800B8DE4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B8DE8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DEC: addiu       $t3, $t2, 0x60
    ctx->r11 = ADD32(ctx->r10, 0X60);
    // 0x800B8DF0: sw          $t3, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->r11;
    // 0x800B8DF4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B8DF8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800B8DFC: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x800B8E00: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E04: nop

    // 0x800B8E08: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x800B8E0C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B8E10: lw          $t8, -0x33C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X33C0);
    // 0x800B8E14: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B8E18: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B8E1C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B8E20: lw          $t0, -0x34B0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X34B0);
    // 0x800B8E24: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E28: nop

    // 0x800B8E2C: sw          $t0, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->r8;
    // 0x800B8E30: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800B8E34: lw          $t3, -0x33C0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X33C0);
    // 0x800B8E38: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800B8E3C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B8E40: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800B8E44: lw          $t5, -0x34B0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X34B0);
    // 0x800B8E48: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B8E4C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E50: subu        $t6, $t2, $t5
    ctx->r14 = SUB32(ctx->r10, ctx->r13);
    // 0x800B8E54: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B8E58: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B8E5C: sw          $t8, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r24;
    // 0x800B8E60: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E64: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800B8E68: sw          $t0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r8;
    // 0x800B8E6C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E70: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800B8E74: addiu       $t3, $t3, 0x6B70
    ctx->r11 = ADD32(ctx->r11, 0X6B70);
    // 0x800B8E78: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
    // 0x800B8E7C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800B8E80: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800B8E84: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E88: addiu       $t5, $t5, 0x6B70
    ctx->r13 = ADD32(ctx->r13, 0X6B70);
    // 0x800B8E8C: addiu       $t2, $t2, 0x6C40
    ctx->r10 = ADD32(ctx->r10, 0X6C40);
    // 0x800B8E90: subu        $t6, $t2, $t5
    ctx->r14 = SUB32(ctx->r10, ctx->r13);
    // 0x800B8E94: sw          $t6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r14;
    // 0x800B8E98: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B8E9C: nop

    // 0x800B8EA0: sw          $zero, 0x14($t8)
    MEM_W(0X14, ctx->r24) = 0;
    // 0x800B8EA4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EA8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B8EAC: addiu       $t9, $t9, -0x7050
    ctx->r25 = ADD32(ctx->r25, -0X7050);
    // 0x800B8EB0: sw          $t9, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r25;
    // 0x800B8EB4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EB8: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800B8EBC: addiu       $t1, $t1, 0x1620
    ctx->r9 = ADD32(ctx->r9, 0X1620);
    // 0x800B8EC0: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x800B8EC4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EC8: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x800B8ECC: sw          $t4, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r12;
    // 0x800B8ED0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B8ED4: nop

    // 0x800B8ED8: sw          $zero, 0x48($t5)
    MEM_W(0X48, ctx->r13) = 0;
    // 0x800B8EDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EE0: nop

    // 0x800B8EE4: sw          $zero, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = 0;
    // 0x800B8EE8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EEC: nop

    // 0x800B8EF0: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x800B8EF4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B8EF8: nop

    // 0x800B8EFC: sw          $zero, 0x34($t8)
    MEM_W(0X34, ctx->r24) = 0;
    // 0x800B8F00: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B8F04: nop

    // 0x800B8F08: sw          $zero, 0x38($t9)
    MEM_W(0X38, ctx->r25) = 0;
    // 0x800B8F0C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B8F10: nop

    // 0x800B8F14: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x800B8F18: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B8F1C: jal         0x80097408
    // 0x800B8F20: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    func_80097408(rdram, ctx);
        goto after_5;
    // 0x800B8F20: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_5:
    // 0x800B8F24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B8F28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B8F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B8F30: jal         0x800C4AA0
    // 0x800B8F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800B8F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x800B8F38: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B8F3C: lw          $t1, -0x33C0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33C0);
    // 0x800B8F40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8F44: xori        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 ^ 0X1;
    // 0x800B8F48: sw          $t3, -0x33C0($at)
    MEM_W(-0X33C0, ctx->r1) = ctx->r11;
    // 0x800B8F4C: b           L_800B8F5C
    // 0x800B8F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B8F5C;
    // 0x800B8F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B8F54: b           L_800B8F5C
    // 0x800B8F58: nop

        goto L_800B8F5C;
    // 0x800B8F58: nop

L_800B8F5C:
    // 0x800B8F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8F60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B8F64: jr          $ra
    // 0x800B8F68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B8F68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B8F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B8F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8F74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B8F78: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800B8F7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8F80: sw          $t6, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r14;
    // 0x800B8F84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B8F88: jal         0x800BB3D4
    // 0x800B8F8C: nop

    AudioDriver_UpdateSeqID(rdram, ctx);
        goto after_0;
    // 0x800B8F8C: nop

    after_0:
    // 0x800B8F90: b           L_800B8F98
    // 0x800B8F94: nop

        goto L_800B8F98;
    // 0x800B8F94: nop

L_800B8F98:
    // 0x800B8F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B8FA0: jr          $ra
    // 0x800B8FA4: nop

    return;
    // 0x800B8FA4: nop

;}
RECOMP_FUNC void AudioMgr_StopMusic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B8FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8FB0: jal         0x800BB3EC
    // 0x800B8FB4: nop

    AudioDriver_StopSeqplayer(rdram, ctx);
        goto after_0;
    // 0x800B8FB4: nop

    after_0:
    // 0x800B8FB8: b           L_800B8FC0
    // 0x800B8FBC: nop

        goto L_800B8FC0;
    // 0x800B8FBC: nop

L_800B8FC0:
    // 0x800B8FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B8FC8: jr          $ra
    // 0x800B8FCC: nop

    return;
    // 0x800B8FCC: nop

    // 0x800B8FD0: jr          $ra
    // 0x800B8FD4: nop

    return;
    // 0x800B8FD4: nop

    // 0x800B8FD8: jr          $ra
    // 0x800B8FDC: nop

    return;
    // 0x800B8FDC: nop

    // 0x800B8FE0: jr          $ra
    // 0x800B8FE4: nop

    return;
    // 0x800B8FE4: nop

    // 0x800B8FE8: jr          $ra
    // 0x800B8FEC: nop

    return;
    // 0x800B8FEC: nop

    // 0x800B8FF0: jr          $ra
    // 0x800B8FF4: nop

    return;
    // 0x800B8FF4: nop

    // 0x800B8FF8: jr          $ra
    // 0x800B8FFC: nop

    return;
    // 0x800B8FFC: nop

;}
RECOMP_FUNC void func_800B9000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B9004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B9008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B900C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B9010: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B9014: jal         0x800BB448
    // 0x800B9018: nop

    func_800BB448(rdram, ctx);
        goto after_0;
    // 0x800B9018: nop

    after_0:
    // 0x800B901C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B9020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B9024: jal         0x800BB4B4
    // 0x800B9028: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BB4B4(rdram, ctx);
        goto after_1;
    // 0x800B9028: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800B902C: b           L_800B9034
    // 0x800B9030: nop

        goto L_800B9034;
    // 0x800B9030: nop

L_800B9034:
    // 0x800B9034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9038: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B903C: jr          $ra
    // 0x800B9040: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B9040: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void n_alSynFreeFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9044: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B9048: b           L_800B9050
    // 0x800B904C: nop

        goto L_800B9050;
    // 0x800B904C: nop

L_800B9050:
    // 0x800B9050: jr          $ra
    // 0x800B9054: nop

    return;
    // 0x800B9054: nop

    // 0x800B9058: jr          $ra
    // 0x800B905C: nop

    return;
    // 0x800B905C: nop

    // 0x800B9060: jr          $ra
    // 0x800B9064: nop

    return;
    // 0x800B9064: nop

;}
RECOMP_FUNC void func_800B9068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9068: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B906C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B9070: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800B9074: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800B9078: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B907C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800B9080: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800B9084: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B9088: lw          $t6, -0x336C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X336C);
    // 0x800B908C: nop

    // 0x800B9090: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800B9094: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B9098: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800B909C: nop

    // 0x800B90A0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B90A4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800B90A8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B90AC: nop

    // 0x800B90B0: beq         $t0, $zero, L_800B9198
    if (ctx->r8 == 0) {
        // 0x800B90B4: nop

            goto L_800B9198;
    }
    // 0x800B90B4: nop

L_800B90B8:
    // 0x800B90B8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B90BC: nop

    // 0x800B90C0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B90C4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800B90C8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B90CC: nop

    // 0x800B90D0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800B90D4: nop

    // 0x800B90D8: addiu       $t5, $t4, 0x800
    ctx->r13 = ADD32(ctx->r12, 0X800);
    // 0x800B90DC: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800B90E0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B90E4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B90E8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800B90EC: nop

    // 0x800B90F0: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B90F4: beq         $at, $zero, L_800B910C
    if (ctx->r1 == 0) {
        // 0x800B90F8: nop

            goto L_800B910C;
    }
    // 0x800B90F8: nop

    // 0x800B90FC: b           L_800B9198
    // 0x800B9100: nop

        goto L_800B9198;
    // 0x800B9100: nop

    // 0x800B9104: b           L_800B9168
    // 0x800B9108: nop

        goto L_800B9168;
    // 0x800B9108: nop

L_800B910C:
    // 0x800B910C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B9110: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800B9114: nop

    // 0x800B9118: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B911C: bne         $at, $zero, L_800B9168
    if (ctx->r1 != 0) {
        // 0x800B9120: nop

            goto L_800B9168;
    }
    // 0x800B9120: nop

    // 0x800B9124: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B9128: lw          $t1, -0x3364($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3364);
    // 0x800B912C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800B9130: nop

    // 0x800B9134: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
    // 0x800B9138: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B913C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800B9140: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x800B9144: lw          $t7, 0x8($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X8);
    // 0x800B9148: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800B914C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B9150: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800B9154: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B9158: jal         0x800C79C0
    // 0x800B915C: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800B915C: nop

    after_0:
    // 0x800B9160: b           L_800B936C
    // 0x800B9164: nop

        goto L_800B936C;
    // 0x800B9164: nop

L_800B9168:
    // 0x800B9168: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800B916C: nop

    // 0x800B9170: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800B9174: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B9178: nop

    // 0x800B917C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B9180: nop

    // 0x800B9184: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800B9188: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800B918C: nop

    // 0x800B9190: bne         $t2, $zero, L_800B90B8
    if (ctx->r10 != 0) {
        // 0x800B9194: nop

            goto L_800B90B8;
    }
    // 0x800B9194: nop

L_800B9198:
    // 0x800B9198: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800B919C: lw          $t4, -0x7320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7320);
    // 0x800B91A0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B91A4: nop

    // 0x800B91A8: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B91AC: beq         $at, $zero, L_800B91C0
    if (ctx->r1 == 0) {
        // 0x800B91B0: nop

            goto L_800B91C0;
    }
    // 0x800B91B0: nop

    // 0x800B91B4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B91B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B91BC: sw          $t3, -0x7320($at)
    MEM_W(-0X7320, ctx->r1) = ctx->r11;
L_800B91C0:
    // 0x800B91C0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B91C4: lw          $t6, -0x3368($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3368);
    // 0x800B91C8: nop

    // 0x800B91CC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800B91D0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800B91D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B91D8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800B91DC: nop

    // 0x800B91E0: sw          $t8, -0x3368($at)
    MEM_W(-0X3368, ctx->r1) = ctx->r24;
    // 0x800B91E4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B91E8: jal         0x800C7890
    // 0x800B91EC: nop

    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800B91EC: nop

    after_1:
    // 0x800B91F0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800B91F4: nop

    // 0x800B91F8: beq         $t9, $zero, L_800B9218
    if (ctx->r25 == 0) {
        // 0x800B91FC: nop

            goto L_800B9218;
    }
    // 0x800B91FC: nop

    // 0x800B9200: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B9204: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B9208: jal         0x800C78C0
    // 0x800B920C: nop

    alLink(rdram, ctx);
        goto after_2;
    // 0x800B920C: nop

    after_2:
    // 0x800B9210: b           L_800B9298
    // 0x800B9214: nop

        goto L_800B9298;
    // 0x800B9214: nop

L_800B9218:
    // 0x800B9218: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B921C: lw          $t0, -0x336C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X336C);
    // 0x800B9220: nop

    // 0x800B9224: beq         $t0, $zero, L_800B9274
    if (ctx->r8 == 0) {
        // 0x800B9228: nop

            goto L_800B9274;
    }
    // 0x800B9228: nop

    // 0x800B922C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B9230: lw          $t1, -0x336C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X336C);
    // 0x800B9234: nop

    // 0x800B9238: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800B923C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800B9240: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9244: sw          $t2, -0x336C($at)
    MEM_W(-0X336C, ctx->r1) = ctx->r10;
    // 0x800B9248: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B924C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B9250: nop

    // 0x800B9254: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800B9258: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B925C: nop

    // 0x800B9260: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800B9264: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B9268: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800B926C: b           L_800B9298
    // 0x800B9270: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
        goto L_800B9298;
    // 0x800B9270: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
L_800B9274:
    // 0x800B9274: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800B9278: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B927C: sw          $t8, -0x336C($at)
    MEM_W(-0X336C, ctx->r1) = ctx->r24;
    // 0x800B9280: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800B9284: nop

    // 0x800B9288: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800B928C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B9290: nop

    // 0x800B9294: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800B9298:
    // 0x800B9298: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B929C: nop

    // 0x800B92A0: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x800B92A4: nop

    // 0x800B92A8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800B92AC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800B92B0: nop

    // 0x800B92B4: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800B92B8: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800B92BC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800B92C0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800B92C4: nop

    // 0x800B92C8: subu        $t7, $t3, $t6
    ctx->r15 = SUB32(ctx->r11, ctx->r14);
    // 0x800B92CC: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800B92D0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B92D4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800B92D8: nop

    // 0x800B92DC: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x800B92E0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B92E4: lw          $t0, -0x3364($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3364);
    // 0x800B92E8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B92EC: nop

    // 0x800B92F0: sw          $t0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r8;
    // 0x800B92F4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800B92F8: lw          $t2, -0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3068);
    // 0x800B92FC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B9300: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800B9304: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800B9308: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800B930C: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x800B9310: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800B9314: addiu       $t7, $t7, -0x3060
    ctx->r15 = ADD32(ctx->r15, -0X3060);
    // 0x800B9318: addiu       $t5, $t5, -0x2EC8
    ctx->r13 = ADD32(ctx->r13, -0X2EC8);
    // 0x800B931C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800B9320: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x800B9324: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9328: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x800B932C: sw          $t8, -0x3068($at)
    MEM_W(-0X3068, ctx->r1) = ctx->r24;
    // 0x800B9330: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800B9334: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800B9338: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800B933C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B9340: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B9344: jal         0x800C81D0
    // 0x800B9348: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x800B9348: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_3:
    // 0x800B934C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B9350: jal         0x800C79C0
    // 0x800B9354: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800B9354: nop

    after_4:
    // 0x800B9358: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B935C: b           L_800B936C
    // 0x800B9360: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
        goto L_800B936C;
    // 0x800B9360: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800B9364: b           L_800B936C
    // 0x800B9368: nop

        goto L_800B936C;
    // 0x800B9368: nop

L_800B936C:
    // 0x800B936C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B9370: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800B9374: jr          $ra
    // 0x800B9378: nop

    return;
    // 0x800B9378: nop

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
RECOMP_FUNC void AudioMgr_ClearAudioDMA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B93E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B93E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B93E8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B93EC: lw          $t6, -0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3068);
    // 0x800B93F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800B93F4: blez        $t6, L_800B9438
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B93F8: nop

            goto L_800B9438;
    }
    // 0x800B93F8: nop

L_800B93FC:
    // 0x800B93FC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9400: addiu       $a0, $a0, -0x3060
    ctx->r4 = ADD32(ctx->r4, -0X3060);
    // 0x800B9404: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800B9408: jal         0x800C1570
    // 0x800B940C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_ReceiveMsg(rdram, ctx);
        goto after_0;
    // 0x800B940C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800B9410: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9414: bne         $v0, $at, L_800B941C
    if (ctx->r2 != ctx->r1) {
        // 0x800B9418: nop

            goto L_800B941C;
    }
    // 0x800B9418: nop

L_800B941C:
    // 0x800B941C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B9420: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B9424: lw          $t9, -0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3068);
    // 0x800B9428: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B942C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B9430: bne         $at, $zero, L_800B93FC
    if (ctx->r1 != 0) {
        // 0x800B9434: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_800B93FC;
    }
    // 0x800B9434: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_800B9438:
    // 0x800B9438: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B943C: lw          $t0, -0x336C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X336C);
    // 0x800B9440: nop

    // 0x800B9444: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B9448: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B944C: nop

    // 0x800B9450: beq         $t1, $zero, L_800B9534
    if (ctx->r9 == 0) {
        // 0x800B9454: nop

            goto L_800B9534;
    }
    // 0x800B9454: nop

L_800B9458:
    // 0x800B9458: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B945C: nop

    // 0x800B9460: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B9464: nop

    // 0x800B9468: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800B946C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9470: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800B9474: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800B9478: lw          $t4, -0x3364($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3364);
    // 0x800B947C: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x800B9480: sltu        $at, $t7, $t4
    ctx->r1 = ctx->r15 < ctx->r12 ? 1 : 0;
    // 0x800B9484: beq         $at, $zero, L_800B9518
    if (ctx->r1 == 0) {
        // 0x800B9488: nop

            goto L_800B9518;
    }
    // 0x800B9488: nop

    // 0x800B948C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9490: lw          $t8, -0x336C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X336C);
    // 0x800B9494: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9498: nop

    // 0x800B949C: bne         $t8, $t9, L_800B94B8
    if (ctx->r24 != ctx->r25) {
        // 0x800B94A0: nop

            goto L_800B94B8;
    }
    // 0x800B94A0: nop

    // 0x800B94A4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B94A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B94AC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B94B0: nop

    // 0x800B94B4: sw          $t1, -0x336C($at)
    MEM_W(-0X336C, ctx->r1) = ctx->r9;
L_800B94B8:
    // 0x800B94B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B94BC: jal         0x800C7890
    // 0x800B94C0: nop

    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800B94C0: nop

    after_1:
    // 0x800B94C4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800B94C8: lw          $t2, -0x3368($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3368);
    // 0x800B94CC: nop

    // 0x800B94D0: beq         $t2, $zero, L_800B94F4
    if (ctx->r10 == 0) {
        // 0x800B94D4: nop

            goto L_800B94F4;
    }
    // 0x800B94D4: nop

    // 0x800B94D8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B94DC: lw          $a1, -0x3368($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3368);
    // 0x800B94E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800B94E4: jal         0x800C78C0
    // 0x800B94E8: nop

    alLink(rdram, ctx);
        goto after_2;
    // 0x800B94E8: nop

    after_2:
    // 0x800B94EC: b           L_800B9518
    // 0x800B94F0: nop

        goto L_800B9518;
    // 0x800B94F0: nop

L_800B94F4:
    // 0x800B94F4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B94F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B94FC: sw          $t3, -0x3368($at)
    MEM_W(-0X3368, ctx->r1) = ctx->r11;
    // 0x800B9500: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9504: nop

    // 0x800B9508: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800B950C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9510: nop

    // 0x800B9514: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_800B9518:
    // 0x800B9518: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B951C: nop

    // 0x800B9520: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B9524: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9528: nop

    // 0x800B952C: bne         $t7, $zero, L_800B9458
    if (ctx->r15 != 0) {
        // 0x800B9530: nop

            goto L_800B9458;
    }
    // 0x800B9530: nop

L_800B9534:
    // 0x800B9534: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9538: sw          $zero, -0x3068($at)
    MEM_W(-0X3068, ctx->r1) = 0;
    // 0x800B953C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9540: lw          $t8, -0x3364($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3364);
    // 0x800B9544: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9548: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B954C: sw          $t9, -0x3364($at)
    MEM_W(-0X3364, ctx->r1) = ctx->r25;
    // 0x800B9550: b           L_800B9558
    // 0x800B9554: nop

        goto L_800B9558;
    // 0x800B9554: nop

L_800B9558:
    // 0x800B9558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B955C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B9560: jr          $ra
    // 0x800B9564: nop

    return;
    // 0x800B9564: nop

;}
RECOMP_FUNC void func_800B9568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9568: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B956C: b           L_800B9574
    // 0x800B9570: nop

        goto L_800B9574;
    // 0x800B9570: nop

L_800B9574:
    // 0x800B9574: jr          $ra
    // 0x800B9578: nop

    return;
    // 0x800B9578: nop

    // 0x800B957C: nop

;}
RECOMP_FUNC void AudioDriver_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9580: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B9584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9588: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B958C: sw          $zero, -0x17AC($at)
    MEM_W(-0X17AC, ctx->r1) = 0;
    // 0x800B9590: jal         0x800B96D4
    // 0x800B9594: nop

    AudioDriver_LoadBanks(rdram, ctx);
        goto after_0;
    // 0x800B9594: nop

    after_0:
    // 0x800B9598: jal         0x800B95D0
    // 0x800B959C: nop

    AudioDriver_LoadSequences(rdram, ctx);
        goto after_1;
    // 0x800B959C: nop

    after_1:
    // 0x800B95A0: jal         0x800B9890
    // 0x800B95A4: nop

    AudioDriver_InitSeqPlayer(rdram, ctx);
        goto after_2;
    // 0x800B95A4: nop

    after_2:
    // 0x800B95A8: jal         0x800B9C74
    // 0x800B95AC: nop

    AudioDriver_InitSoundPlayer(rdram, ctx);
        goto after_3;
    // 0x800B95AC: nop

    after_3:
    // 0x800B95B0: jal         0x800B9CEC
    // 0x800B95B4: nop

    func_800B9CEC(rdram, ctx);
        goto after_4;
    // 0x800B95B4: nop

    after_4:
    // 0x800B95B8: b           L_800B95C0
    // 0x800B95BC: nop

        goto L_800B95C0;
    // 0x800B95BC: nop

L_800B95C0:
    // 0x800B95C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B95C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B95C8: jr          $ra
    // 0x800B95CC: nop

    return;
    // 0x800B95CC: nop

;}
RECOMP_FUNC void AudioDriver_LoadSequences(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B95D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B95D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B95D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B95DC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B95E0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800B95E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B95E8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B95EC: addiu       $a0, $a0, -0x398
    ctx->r4 = ADD32(ctx->r4, -0X398);
    // 0x800B95F0: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x800B95F4: jal         0x800C7950
    // 0x800B95F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800B95F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800B95FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9600: sw          $v0, -0x17E0($at)
    MEM_W(-0X17E0, ctx->r1) = ctx->r2;
    // 0x800B9604: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9608: lw          $a1, -0x17E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17E0);
    // 0x800B960C: lui         $a0, 0x73
    ctx->r4 = S32(0X73 << 16);
    // 0x800B9610: addiu       $a0, $a0, 0xE80
    ctx->r4 = ADD32(ctx->r4, 0XE80);
    // 0x800B9614: jal         0x800BC590
    // 0x800B9618: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    AudioDmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B9618: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800B961C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800B9620: lw          $t7, -0x17E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X17E0);
    // 0x800B9624: nop

    // 0x800B9628: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800B962C: nop

    // 0x800B9630: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B9634: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800B9638: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800B963C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B9640: lw          $t1, -0x17E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17E0);
    // 0x800B9644: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9648: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x800B964C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9650: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800B9654: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x800B9658: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800B965C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9660: addiu       $a0, $a0, -0x388
    ctx->r4 = ADD32(ctx->r4, -0X388);
    // 0x800B9664: addiu       $a1, $zero, 0x9E
    ctx->r5 = ADD32(0, 0X9E);
    // 0x800B9668: jal         0x800C7950
    // 0x800B966C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800B966C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800B9670: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9674: sw          $v0, -0x17E0($at)
    MEM_W(-0X17E0, ctx->r1) = ctx->r2;
    // 0x800B9678: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B967C: lw          $a1, -0x17E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17E0);
    // 0x800B9680: lui         $a0, 0x73
    ctx->r4 = S32(0X73 << 16);
    // 0x800B9684: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B9688: jal         0x800BC590
    // 0x800B968C: addiu       $a0, $a0, 0xE80
    ctx->r4 = ADD32(ctx->r4, 0XE80);
    AudioDmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B968C: addiu       $a0, $a0, 0xE80
    ctx->r4 = ADD32(ctx->r4, 0XE80);
    after_3:
    // 0x800B9690: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9694: lw          $a0, -0x17E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17E0);
    // 0x800B9698: lui         $a1, 0x73
    ctx->r5 = S32(0X73 << 16);
    // 0x800B969C: jal         0x800C84E8
    // 0x800B96A0: addiu       $a1, $a1, 0xE80
    ctx->r5 = ADD32(ctx->r5, 0XE80);
    alSeqFileNew(rdram, ctx);
        goto after_4;
    // 0x800B96A0: addiu       $a1, $a1, 0xE80
    ctx->r5 = ADD32(ctx->r5, 0XE80);
    after_4:
    // 0x800B96A4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800B96A8: lw          $t5, -0x17E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X17E0);
    // 0x800B96AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B96B0: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x800B96B4: nop

    // 0x800B96B8: sw          $t6, -0x17D0($at)
    MEM_W(-0X17D0, ctx->r1) = ctx->r14;
    // 0x800B96BC: b           L_800B96C4
    // 0x800B96C0: nop

        goto L_800B96C4;
    // 0x800B96C0: nop

L_800B96C4:
    // 0x800B96C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B96C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B96CC: jr          $ra
    // 0x800B96D0: nop

    return;
    // 0x800B96D0: nop

;}
RECOMP_FUNC void AudioDriver_LoadBanks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B96D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B96D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B96DC: lui         $t6, 0x76
    ctx->r14 = S32(0X76 << 16);
    // 0x800B96E0: lui         $t7, 0x75
    ctx->r15 = S32(0X75 << 16);
    // 0x800B96E4: addiu       $t7, $t7, 0x6140
    ctx->r15 = ADD32(ctx->r15, 0X6140);
    // 0x800B96E8: addiu       $t6, $t6, -0x69F0
    ctx->r14 = ADD32(ctx->r14, -0X69F0);
    // 0x800B96EC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B96F0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800B96F4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B96F8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B96FC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9700: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9704: addiu       $a0, $a0, -0x370
    ctx->r4 = ADD32(ctx->r4, -0X370);
    // 0x800B9708: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x800B970C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B9710: jal         0x800C7950
    // 0x800B9714: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800B9714: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x800B9718: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B971C: lui         $a0, 0x75
    ctx->r4 = S32(0X75 << 16);
    // 0x800B9720: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B9724: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B9728: jal         0x800BC590
    // 0x800B972C: addiu       $a0, $a0, 0x6140
    ctx->r4 = ADD32(ctx->r4, 0X6140);
    AudioDmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B972C: addiu       $a0, $a0, 0x6140
    ctx->r4 = ADD32(ctx->r4, 0X6140);
    after_1:
    // 0x800B9730: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B9734: lui         $a1, 0x76
    ctx->r5 = S32(0X76 << 16);
    // 0x800B9738: jal         0x800C83E4
    // 0x800B973C: addiu       $a1, $a1, -0x69F0
    ctx->r5 = ADD32(ctx->r5, -0X69F0);
    alBnkfNew(rdram, ctx);
        goto after_2;
    // 0x800B973C: addiu       $a1, $a1, -0x69F0
    ctx->r5 = ADD32(ctx->r5, -0X69F0);
    after_2:
    // 0x800B9740: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B9744: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9748: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800B974C: nop

    // 0x800B9750: sw          $t1, -0x17E8($at)
    MEM_W(-0X17E8, ctx->r1) = ctx->r9;
    // 0x800B9754: lui         $t2, 0x79
    ctx->r10 = S32(0X79 << 16);
    // 0x800B9758: lui         $t3, 0x78
    ctx->r11 = S32(0X78 << 16);
    // 0x800B975C: addiu       $t3, $t3, 0x5F70
    ctx->r11 = ADD32(ctx->r11, 0X5F70);
    // 0x800B9760: addiu       $t2, $t2, -0x5490
    ctx->r10 = ADD32(ctx->r10, -0X5490);
    // 0x800B9764: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800B9768: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B976C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B9770: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9774: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9778: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B977C: addiu       $a0, $a0, -0x360
    ctx->r4 = ADD32(ctx->r4, -0X360);
    // 0x800B9780: addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    // 0x800B9784: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B9788: jal         0x800C7950
    // 0x800B978C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800B978C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x800B9790: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800B9794: lui         $a0, 0x78
    ctx->r4 = S32(0X78 << 16);
    // 0x800B9798: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B979C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B97A0: jal         0x800BC590
    // 0x800B97A4: addiu       $a0, $a0, 0x5F70
    ctx->r4 = ADD32(ctx->r4, 0X5F70);
    AudioDmaCopy(rdram, ctx);
        goto after_4;
    // 0x800B97A4: addiu       $a0, $a0, 0x5F70
    ctx->r4 = ADD32(ctx->r4, 0X5F70);
    after_4:
    // 0x800B97A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B97AC: lui         $a1, 0x79
    ctx->r5 = S32(0X79 << 16);
    // 0x800B97B0: jal         0x800C83E4
    // 0x800B97B4: addiu       $a1, $a1, -0x5490
    ctx->r5 = ADD32(ctx->r5, -0X5490);
    alBnkfNew(rdram, ctx);
        goto after_5;
    // 0x800B97B4: addiu       $a1, $a1, -0x5490
    ctx->r5 = ADD32(ctx->r5, -0X5490);
    after_5:
    // 0x800B97B8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B97BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B97C0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B97C4: nop

    // 0x800B97C8: sw          $t7, -0x17E4($at)
    MEM_W(-0X17E4, ctx->r1) = ctx->r15;
    // 0x800B97CC: b           L_800B97D4
    // 0x800B97D0: nop

        goto L_800B97D4;
    // 0x800B97D0: nop

L_800B97D4:
    // 0x800B97D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B97D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B97DC: jr          $ra
    // 0x800B97E0: nop

    return;
    // 0x800B97E0: nop

;}
RECOMP_FUNC void AudioDriver_GetSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B97E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B97E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B97EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B97F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B97F4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B97F8: lw          $t6, -0x17E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17E0);
    // 0x800B97FC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B9800: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B9804: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800B9808: nop

    // 0x800B980C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800B9810: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800B9814: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B9818: lw          $t1, -0x17E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17E0);
    // 0x800B981C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800B9820: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800B9824: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800B9828: nop

    // 0x800B982C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800B9830: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9834: nop

    // 0x800B9838: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x800B983C: beq         $t6, $zero, L_800B9854
    if (ctx->r14 == 0) {
        // 0x800B9840: nop

            goto L_800B9854;
    }
    // 0x800B9840: nop

    // 0x800B9844: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9848: nop

    // 0x800B984C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B9850: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_800B9854:
    // 0x800B9854: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9858: lw          $a1, -0x17D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17D4);
    // 0x800B985C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B9860: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9864: jal         0x800BC590
    // 0x800B9868: nop

    AudioDmaCopy(rdram, ctx);
        goto after_0;
    // 0x800B9868: nop

    after_0:
    // 0x800B986C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9870: b           L_800B9880
    // 0x800B9874: nop

        goto L_800B9880;
    // 0x800B9874: nop

    // 0x800B9878: b           L_800B9880
    // 0x800B987C: nop

        goto L_800B9880;
    // 0x800B987C: nop

L_800B9880:
    // 0x800B9880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9888: jr          $ra
    // 0x800B988C: nop

    return;
    // 0x800B988C: nop

;}
RECOMP_FUNC void AudioDriver_InitSeqPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9890: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B9894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B9898: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x800B989C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B98A0: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800B98A4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800B98A8: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800B98AC: sb          $t8, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r24;
    // 0x800B98B0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B98B4: addiu       $t9, $t9, -0x3078
    ctx->r25 = ADD32(ctx->r25, -0X3078);
    // 0x800B98B8: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800B98BC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800B98C0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B98C4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800B98C8: jal         0x800BC4CC
    // 0x800B98CC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    AudioDriver_SetupOsc(rdram, ctx);
        goto after_0;
    // 0x800B98CC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800B98D0: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800B98D4: sb          $t0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r8;
    // 0x800B98D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B98DC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B98E0: addiu       $t1, $zero, 0x7C
    ctx->r9 = ADD32(0, 0X7C);
    // 0x800B98E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800B98E8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B98EC: addiu       $a0, $a0, -0x340
    ctx->r4 = ADD32(ctx->r4, -0X340);
    // 0x800B98F0: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x800B98F4: jal         0x800C7950
    // 0x800B98F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800B98F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800B98FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9900: sw          $v0, -0x17DC($at)
    MEM_W(-0X17DC, ctx->r1) = ctx->r2;
    // 0x800B9904: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9908: lw          $a0, -0x17DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17DC);
    // 0x800B990C: jal         0x800C95F0
    // 0x800B9910: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    alCSPNew(rdram, ctx);
        goto after_2;
    // 0x800B9910: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x800B9914: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9918: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B991C: addiu       $t2, $zero, 0x3000
    ctx->r10 = ADD32(0, 0X3000);
    // 0x800B9920: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800B9924: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9928: addiu       $a0, $a0, -0x330
    ctx->r4 = ADD32(ctx->r4, -0X330);
    // 0x800B992C: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x800B9930: jal         0x800C7950
    // 0x800B9934: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800B9934: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800B9938: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B993C: sw          $v0, -0x17D4($at)
    MEM_W(-0X17D4, ctx->r1) = ctx->r2;
    // 0x800B9940: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9944: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9948: addiu       $t3, $zero, 0xF8
    ctx->r11 = ADD32(0, 0XF8);
    // 0x800B994C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800B9950: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9954: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    // 0x800B9958: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x800B995C: jal         0x800C7950
    // 0x800B9960: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x800B9960: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x800B9964: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9968: sw          $v0, -0x17D8($at)
    MEM_W(-0X17D8, ctx->r1) = ctx->r2;
    // 0x800B996C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B9970: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9974: sw          $t4, -0x17C8($at)
    MEM_W(-0X17C8, ctx->r1) = ctx->r12;
    // 0x800B9978: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B997C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9980: sw          $t5, -0x7310($at)
    MEM_W(-0X7310, ctx->r1) = ctx->r13;
    // 0x800B9984: addiu       $t6, $zero, 0x7FFF
    ctx->r14 = ADD32(0, 0X7FFF);
    // 0x800B9988: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B998C: sw          $t6, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r14;
    // 0x800B9990: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9994: sw          $zero, -0x17BC($at)
    MEM_W(-0X17BC, ctx->r1) = 0;
    // 0x800B9998: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x800B999C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B99A0: sw          $t7, -0x17B4($at)
    MEM_W(-0X17B4, ctx->r1) = ctx->r15;
    // 0x800B99A4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B99A8: sw          $zero, -0x17B8($at)
    MEM_W(-0X17B8, ctx->r1) = 0;
    // 0x800B99AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B99B0: sw          $zero, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = 0;
    // 0x800B99B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B99B8: sw          $zero, -0x7304($at)
    MEM_W(-0X7304, ctx->r1) = 0;
    // 0x800B99BC: b           L_800B99C4
    // 0x800B99C0: nop

        goto L_800B99C4;
    // 0x800B99C0: nop

L_800B99C4:
    // 0x800B99C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B99C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B99CC: jr          $ra
    // 0x800B99D0: nop

    return;
    // 0x800B99D0: nop

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
RECOMP_FUNC void AudioDriver_ProcessSoundDeallocRequests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9A18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B9A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B9A20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B9A24: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800B9A28: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800B9A2C:
    // 0x800B9A2C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9A30: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x800B9A34: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B9A38: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800B9A3C: lw          $s0, -0x1E0C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X1E0C);
    // 0x800B9A40: nop

    // 0x800B9A44: beq         $s0, $zero, L_800B9A6C
    if (ctx->r16 == 0) {
        // 0x800B9A48: nop

            goto L_800B9A6C;
    }
    // 0x800B9A48: nop

    // 0x800B9A4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B9A50: beq         $s0, $at, L_800B9A74
    if (ctx->r16 == ctx->r1) {
        // 0x800B9A54: nop

            goto L_800B9A74;
    }
    // 0x800B9A54: nop

    // 0x800B9A58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B9A5C: beq         $s0, $at, L_800B9AD8
    if (ctx->r16 == ctx->r1) {
        // 0x800B9A60: nop

            goto L_800B9AD8;
    }
    // 0x800B9A60: nop

    // 0x800B9A64: b           L_800B9B64
    // 0x800B9A68: nop

        goto L_800B9B64;
    // 0x800B9A68: nop

L_800B9A6C:
    // 0x800B9A6C: b           L_800B9B64
    // 0x800B9A70: nop

        goto L_800B9B64;
    // 0x800B9A70: nop

L_800B9A74:
    // 0x800B9A74: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800B9A78: nop

    // 0x800B9A7C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B9A80: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800B9A84: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9A88: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9A8C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800B9A90: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x800B9A94: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9A98: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9A9C: lh          $a1, -0x1E10($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1E10);
    // 0x800B9AA0: jal         0x800C9760
    // 0x800B9AA4: nop

    alSndpSetSound(rdram, ctx);
        goto after_0;
    // 0x800B9AA4: nop

    after_0:
    // 0x800B9AA8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9AAC: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9AB0: jal         0x800C9780
    // 0x800B9AB4: nop

    alSndpStop(rdram, ctx);
        goto after_1;
    // 0x800B9AB4: nop

    after_1:
    // 0x800B9AB8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9ABC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9AC0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800B9AC4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B9AC8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800B9ACC: sw          $t2, -0x1E0C($at)
    MEM_W(-0X1E0C, ctx->r1) = ctx->r10;
    // 0x800B9AD0: b           L_800B9B64
    // 0x800B9AD4: nop

        goto L_800B9B64;
    // 0x800B9AD4: nop

L_800B9AD8:
    // 0x800B9AD8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800B9ADC: nop

    // 0x800B9AE0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B9AE4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800B9AE8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9AEC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9AF0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B9AF4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800B9AF8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9AFC: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9B00: lh          $a1, -0x1E10($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1E10);
    // 0x800B9B04: jal         0x800C9760
    // 0x800B9B08: nop

    alSndpSetSound(rdram, ctx);
        goto after_2;
    // 0x800B9B08: nop

    after_2:
    // 0x800B9B0C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9B10: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9B14: jal         0x800C97D0
    // 0x800B9B18: nop

    alSndpGetState(rdram, ctx);
        goto after_3;
    // 0x800B9B18: nop

    after_3:
    // 0x800B9B1C: bne         $v0, $zero, L_800B9B5C
    if (ctx->r2 != 0) {
        // 0x800B9B20: nop

            goto L_800B9B5C;
    }
    // 0x800B9B20: nop

    // 0x800B9B24: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9B28: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9B2C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B9B30: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x800B9B34: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9B38: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9B3C: lh          $a1, -0x1E10($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1E10);
    // 0x800B9B40: jal         0x800C97F0
    // 0x800B9B44: nop

    alSndpDeallocate(rdram, ctx);
        goto after_4;
    // 0x800B9B44: nop

    after_4:
    // 0x800B9B48: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9B4C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9B50: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x800B9B54: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800B9B58: sw          $zero, -0x1E0C($at)
    MEM_W(-0X1E0C, ctx->r1) = 0;
L_800B9B5C:
    // 0x800B9B5C: b           L_800B9B64
    // 0x800B9B60: nop

        goto L_800B9B64;
    // 0x800B9B60: nop

L_800B9B64:
    // 0x800B9B64: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9B68: nop

    // 0x800B9B6C: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800B9B70: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x800B9B74: bne         $at, $zero, L_800B9A2C
    if (ctx->r1 != 0) {
        // 0x800B9B78: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_800B9A2C;
    }
    // 0x800B9B78: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800B9B7C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800B9B80: nop

    // 0x800B9B84: beq         $t5, $zero, L_800B9BA4
    if (ctx->r13 == 0) {
        // 0x800B9B88: nop

            goto L_800B9BA4;
    }
    // 0x800B9B88: nop

    // 0x800B9B8C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800B9B90: lw          $t6, -0x730C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X730C);
    // 0x800B9B94: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9B98: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x800B9B9C: b           L_800B9BBC
    // 0x800B9BA0: sw          $t7, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r15;
        goto L_800B9BBC;
    // 0x800B9BA0: sw          $t7, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r15;
L_800B9BA4:
    // 0x800B9BA4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800B9BA8: lw          $t8, -0x730C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X730C);
    // 0x800B9BAC: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B9BB0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800B9BB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9BB8: sw          $t9, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r25;
L_800B9BBC:
    // 0x800B9BBC: b           L_800B9BC4
    // 0x800B9BC0: nop

        goto L_800B9BC4;
    // 0x800B9BC0: nop

L_800B9BC4:
    // 0x800B9BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9BC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B9BCC: jr          $ra
    // 0x800B9BD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B9BD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
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
RECOMP_FUNC void AudioDriver_InitSoundPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9C74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B9C78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B9C7C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x800B9C80: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B9C84: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800B9C88: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800B9C8C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9C90: addiu       $t8, $t8, -0x3078
    ctx->r24 = ADD32(ctx->r24, -0X3078);
    // 0x800B9C94: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800B9C98: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9C9C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9CA0: addiu       $t9, $zero, 0x54
    ctx->r25 = ADD32(0, 0X54);
    // 0x800B9CA4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800B9CA8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9CAC: addiu       $a0, $a0, -0x2F8
    ctx->r4 = ADD32(ctx->r4, -0X2F8);
    // 0x800B9CB0: addiu       $a1, $zero, 0x159
    ctx->r5 = ADD32(0, 0X159);
    // 0x800B9CB4: jal         0x800C7950
    // 0x800B9CB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800B9CB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800B9CBC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9CC0: sw          $v0, -0x17B0($at)
    MEM_W(-0X17B0, ctx->r1) = ctx->r2;
    // 0x800B9CC4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9CC8: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9CCC: jal         0x800C9E14
    // 0x800B9CD0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    alSndpNew(rdram, ctx);
        goto after_1;
    // 0x800B9CD0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800B9CD4: b           L_800B9CDC
    // 0x800B9CD8: nop

        goto L_800B9CDC;
    // 0x800B9CD8: nop

L_800B9CDC:
    // 0x800B9CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9CE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B9CE4: jr          $ra
    // 0x800B9CE8: nop

    return;
    // 0x800B9CE8: nop

;}
RECOMP_FUNC void func_800B9CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9CEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9CF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B9CF8:
    // 0x800B9CF8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9CFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9D00: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B9D04: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B9D08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9D0C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B9D10: sw          $zero, -0x1A64($at)
    MEM_W(-0X1A64, ctx->r1) = 0;
    // 0x800B9D14: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9D18: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B9D1C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B9D20: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B9D24: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B9D28: sll         $t2, $t8, 3
    ctx->r10 = S32(ctx->r24 << 3);
    // 0x800B9D2C: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x800B9D30: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B9D34: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B9D38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B9D3C: addiu       $t0, $t0, -0x1988
    ctx->r8 = ADD32(ctx->r8, -0X1988);
    // 0x800B9D40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9D44: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800B9D48: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B9D4C: sw          $t1, -0x1A68($at)
    MEM_W(-0X1A68, ctx->r1) = ctx->r9;
    // 0x800B9D50: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9D54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9D58: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B9D5C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800B9D60: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B9D64: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B9D68: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B9D6C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B9D70: sw          $t3, -0x1988($at)
    MEM_W(-0X1988, ctx->r1) = ctx->r11;
    // 0x800B9D74: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9D78: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9D7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B9D80: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B9D84: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9D88: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B9D8C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9D90: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B9D94: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B9D98: sh          $t5, -0x1970($at)
    MEM_H(-0X1970, ctx->r1) = ctx->r13;
    // 0x800B9D9C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9DA0: nop

    // 0x800B9DA4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B9DA8: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800B9DAC: bne         $at, $zero, L_800B9CF8
    if (ctx->r1 != 0) {
        // 0x800B9DB0: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800B9CF8;
    }
    // 0x800B9DB0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B9DB4: jal         0x800B99D4
    // 0x800B9DB8: nop

    AudioDriver_InitSoundDeallocRequests(rdram, ctx);
        goto after_0;
    // 0x800B9DB8: nop

    after_0:
    // 0x800B9DBC: b           L_800B9DC4
    // 0x800B9DC0: nop

        goto L_800B9DC4;
    // 0x800B9DC0: nop

L_800B9DC4:
    // 0x800B9DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9DCC: jr          $ra
    // 0x800B9DD0: nop

    return;
    // 0x800B9DD0: nop

;}
RECOMP_FUNC void func_800B9DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9DD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9DDC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800B9DE0: lw          $t6, -0x730C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X730C);
    // 0x800B9DE4: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800B9DE8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800B9DEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9DF0: sw          $t7, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r15;
    // 0x800B9DF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B9DF8:
    // 0x800B9DF8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9DFC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800B9E00: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B9E04: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B9E08: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B9E0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B9E10: lw          $t0, -0x1A64($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1A64);
    // 0x800B9E14: nop

    // 0x800B9E18: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800B9E1C: beq         $t1, $zero, L_800B9E58
    if (ctx->r9 == 0) {
        // 0x800B9E20: nop

            goto L_800B9E58;
    }
    // 0x800B9E20: nop

    // 0x800B9E24: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800B9E28: lw          $t2, -0x730C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X730C);
    // 0x800B9E2C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9E30: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x800B9E34: sw          $t3, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r11;
    // 0x800B9E38: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9E3C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800B9E40: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800B9E44: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B9E48: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B9E4C: addiu       $t6, $t6, -0x1A68
    ctx->r14 = ADD32(ctx->r14, -0X1A68);
    // 0x800B9E50: jal         0x800B9F48
    // 0x800B9E54: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    func_800B9F48(rdram, ctx);
        goto after_0;
    // 0x800B9E54: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_0:
L_800B9E58:
    // 0x800B9E58: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9E5C: nop

    // 0x800B9E60: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B9E64: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x800B9E68: bne         $at, $zero, L_800B9DF8
    if (ctx->r1 != 0) {
        // 0x800B9E6C: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800B9DF8;
    }
    // 0x800B9E6C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800B9E70: b           L_800B9E78
    // 0x800B9E74: nop

        goto L_800B9E78;
    // 0x800B9E74: nop

L_800B9E78:
    // 0x800B9E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9E80: jr          $ra
    // 0x800B9E84: nop

    return;
    // 0x800B9E84: nop

;}
RECOMP_FUNC void func_800B9E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9E90: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B9E94:
    // 0x800B9E94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9E98: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800B9E9C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B9EA0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B9EA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9EA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B9EAC: lw          $t8, -0x1A64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1A64);
    // 0x800B9EB0: nop

    // 0x800B9EB4: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800B9EB8: beq         $t9, $zero, L_800B9EE0
    if (ctx->r25 == 0) {
        // 0x800B9EBC: nop

            goto L_800B9EE0;
    }
    // 0x800B9EBC: nop

    // 0x800B9EC0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9EC4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800B9EC8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800B9ECC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B9ED0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B9ED4: addiu       $t2, $t2, -0x1A68
    ctx->r10 = ADD32(ctx->r10, -0X1A68);
    // 0x800B9ED8: jal         0x800BA748
    // 0x800B9EDC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    func_800BA748(rdram, ctx);
        goto after_0;
    // 0x800B9EDC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_0:
L_800B9EE0:
    // 0x800B9EE0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9EE4: nop

    // 0x800B9EE8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B9EEC: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800B9EF0: bne         $at, $zero, L_800B9E94
    if (ctx->r1 != 0) {
        // 0x800B9EF4: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B9E94;
    }
    // 0x800B9EF4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B9EF8: b           L_800B9F00
    // 0x800B9EFC: nop

        goto L_800B9F00;
    // 0x800B9EFC: nop

L_800B9F00:
    // 0x800B9F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9F04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9F08: jr          $ra
    // 0x800B9F0C: nop

    return;
    // 0x800B9F0C: nop

;}
RECOMP_FUNC void AudioDriver_UpdateSounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9F10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9F18: jal         0x800B9A18
    // 0x800B9F1C: nop

    AudioDriver_ProcessSoundDeallocRequests(rdram, ctx);
        goto after_0;
    // 0x800B9F1C: nop

    after_0:
    // 0x800B9F20: jal         0x800B9DD4
    // 0x800B9F24: nop

    func_800B9DD4(rdram, ctx);
        goto after_1;
    // 0x800B9F24: nop

    after_1:
    // 0x800B9F28: jal         0x800B9E88
    // 0x800B9F2C: nop

    func_800B9E88(rdram, ctx);
        goto after_2;
    // 0x800B9F2C: nop

    after_2:
    // 0x800B9F30: b           L_800B9F38
    // 0x800B9F34: nop

        goto L_800B9F38;
    // 0x800B9F34: nop

L_800B9F38:
    // 0x800B9F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9F3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9F40: jr          $ra
    // 0x800B9F44: nop

    return;
    // 0x800B9F44: nop

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
RECOMP_FUNC void AudioDriver_DeallocSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA1E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA1F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BA1F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800BA1F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA1FC: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x800BA200: nop

    // 0x800BA204: beq         $t7, $at, L_800BA22C
    if (ctx->r15 == ctx->r1) {
        // 0x800BA208: nop

            goto L_800BA22C;
    }
    // 0x800BA208: nop

    // 0x800BA20C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800BA210: nop

    // 0x800BA214: lh          $a0, 0x18($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X18);
    // 0x800BA218: jal         0x800B9BD4
    // 0x800BA21C: nop

    AudioDriver_RequestSoundDealloc(rdram, ctx);
        goto after_0;
    // 0x800BA21C: nop

    after_0:
    // 0x800BA220: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800BA224: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BA228: sh          $t9, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r25;
L_800BA22C:
    // 0x800BA22C: b           L_800BA234
    // 0x800BA230: nop

        goto L_800BA234;
    // 0x800BA230: nop

L_800BA234:
    // 0x800BA234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA23C: jr          $ra
    // 0x800BA240: nop

    return;
    // 0x800BA240: nop

;}
RECOMP_FUNC void func_800BA244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA244: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BA248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA24C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BA250: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800BA254: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BA258: nop

    // 0x800BA25C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800BA260: nop

    // 0x800BA264: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800BA268: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x800BA26C: nop

    // 0x800BA270: addiu       $t9, $t8, -0x4000
    ctx->r25 = ADD32(ctx->r24, -0X4000);
    // 0x800BA274: sltiu       $at, $t9, 0x10
    ctx->r1 = ctx->r25 < 0X10 ? 1 : 0;
    // 0x800BA278: beq         $at, $zero, L_800BA730
    if (ctx->r1 == 0) {
        // 0x800BA27C: nop

            goto L_800BA730;
    }
    // 0x800BA27C: nop

    // 0x800BA280: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BA284: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BA288: addu        $at, $at, $t9
    gpr jr_addend_800BA294 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800BA28C: lw          $t9, -0x284($at)
    ctx->r25 = ADD32(ctx->r1, -0X284);
    // 0x800BA290: nop

    // 0x800BA294: jr          $t9
    // 0x800BA298: nop

    switch (jr_addend_800BA294 >> 2) {
        case 0: goto L_800BA29C; break;
        case 1: goto L_800BA2F0; break;
        case 2: goto L_800BA39C; break;
        case 3: goto L_800BA448; break;
        case 4: goto L_800BA4B0; break;
        case 5: goto L_800BA504; break;
        case 6: goto L_800BA570; break;
        case 7: goto L_800BA584; break;
        case 8: goto L_800BA5E4; break;
        case 9: goto L_800BA634; break;
        case 10: goto L_800BA344; break;
        case 11: goto L_800BA6B8; break;
        case 12: goto L_800BA680; break;
        case 13: goto L_800BA69C; break;
        case 14: goto L_800BA3F0; break;
        case 15: goto L_800BA524; break;
        default: switch_error(__func__, 0x800BA294, 0x800EFD7C);
    }
    // 0x800BA298: nop

L_800BA29C:
    // 0x800BA29C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA2A0: jal         0x800BA1E8
    // 0x800BA2A4: nop

    AudioDriver_DeallocSound(rdram, ctx);
        goto after_0;
    // 0x800BA2A4: nop

    after_0:
    // 0x800BA2A8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA2AC: nop

    // 0x800BA2B0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800BA2B4: nop

    // 0x800BA2B8: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x800BA2BC: nop

    // 0x800BA2C0: sw          $t2, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r10;
    // 0x800BA2C4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA2C8: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800BA2CC: sw          $t3, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r11;
    // 0x800BA2D0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA2D4: nop

    // 0x800BA2D8: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800BA2DC: nop

    // 0x800BA2E0: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800BA2E4: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x800BA2E8: b           L_800BA730
    // 0x800BA2EC: nop

        goto L_800BA730;
    // 0x800BA2EC: nop

L_800BA2F0:
    // 0x800BA2F0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA2F4: nop

    // 0x800BA2F8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BA2FC: nop

    // 0x800BA300: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x800BA304: nop

    // 0x800BA308: sw          $t1, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r9;
    // 0x800BA30C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA310: nop

    // 0x800BA314: lw          $t0, 0x1C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X1C);
    // 0x800BA318: nop

    // 0x800BA31C: ori         $t3, $t0, 0x1
    ctx->r11 = ctx->r8 | 0X1;
    // 0x800BA320: sw          $t3, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r11;
    // 0x800BA324: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA328: nop

    // 0x800BA32C: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x800BA330: nop

    // 0x800BA334: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800BA338: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
    // 0x800BA33C: b           L_800BA730
    // 0x800BA340: nop

        goto L_800BA730;
    // 0x800BA340: nop

L_800BA344:
    // 0x800BA344: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA348: nop

    // 0x800BA34C: lw          $t1, 0xC($t5)
    ctx->r9 = MEM_W(ctx->r13, 0XC);
    // 0x800BA350: lw          $t9, 0x24($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X24);
    // 0x800BA354: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x800BA358: nop

    // 0x800BA35C: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x800BA360: sw          $t0, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r8;
    // 0x800BA364: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA368: nop

    // 0x800BA36C: lw          $t2, 0x1C($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X1C);
    // 0x800BA370: nop

    // 0x800BA374: ori         $t6, $t2, 0x1
    ctx->r14 = ctx->r10 | 0X1;
    // 0x800BA378: sw          $t6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r14;
    // 0x800BA37C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA380: nop

    // 0x800BA384: lw          $t4, 0xC($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XC);
    // 0x800BA388: nop

    // 0x800BA38C: addiu       $t1, $t4, 0x2
    ctx->r9 = ADD32(ctx->r12, 0X2);
    // 0x800BA390: sw          $t1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r9;
    // 0x800BA394: b           L_800BA730
    // 0x800BA398: nop

        goto L_800BA730;
    // 0x800BA398: nop

L_800BA39C:
    // 0x800BA39C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA3A0: nop

    // 0x800BA3A4: lw          $t8, 0xC($t9)
    ctx->r24 = MEM_W(ctx->r25, 0XC);
    // 0x800BA3A8: nop

    // 0x800BA3AC: lh          $t0, 0x0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X0);
    // 0x800BA3B0: nop

    // 0x800BA3B4: sh          $t0, 0x2C($t9)
    MEM_H(0X2C, ctx->r25) = ctx->r8;
    // 0x800BA3B8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA3BC: nop

    // 0x800BA3C0: lw          $t2, 0x1C($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X1C);
    // 0x800BA3C4: nop

    // 0x800BA3C8: ori         $t6, $t2, 0x2
    ctx->r14 = ctx->r10 | 0X2;
    // 0x800BA3CC: sw          $t6, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r14;
    // 0x800BA3D0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA3D4: nop

    // 0x800BA3D8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x800BA3DC: nop

    // 0x800BA3E0: addiu       $t1, $t4, 0x2
    ctx->r9 = ADD32(ctx->r12, 0X2);
    // 0x800BA3E4: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800BA3E8: b           L_800BA730
    // 0x800BA3EC: nop

        goto L_800BA730;
    // 0x800BA3EC: nop

L_800BA3F0:
    // 0x800BA3F0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA3F4: nop

    // 0x800BA3F8: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800BA3FC: lh          $t8, 0x2C($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2C);
    // 0x800BA400: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x800BA404: nop

    // 0x800BA408: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800BA40C: sh          $t2, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r10;
    // 0x800BA410: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA414: nop

    // 0x800BA418: lw          $t5, 0x1C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X1C);
    // 0x800BA41C: nop

    // 0x800BA420: ori         $t4, $t5, 0x2
    ctx->r12 = ctx->r13 | 0X2;
    // 0x800BA424: sw          $t4, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r12;
    // 0x800BA428: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA42C: nop

    // 0x800BA430: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x800BA434: nop

    // 0x800BA438: addiu       $t0, $t3, 0x2
    ctx->r8 = ADD32(ctx->r11, 0X2);
    // 0x800BA43C: sw          $t0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r8;
    // 0x800BA440: b           L_800BA730
    // 0x800BA444: nop

        goto L_800BA730;
    // 0x800BA444: nop

L_800BA448:
    // 0x800BA448: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA44C: nop

    // 0x800BA450: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800BA454: nop

    // 0x800BA458: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x800BA45C: nop

    // 0x800BA460: sb          $t2, 0x31($t8)
    MEM_B(0X31, ctx->r24) = ctx->r10;
    // 0x800BA464: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA468: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800BA46C: lbu         $t5, 0x31($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X31);
    // 0x800BA470: nop

    // 0x800BA474: sb          $t5, 0x1A($t4)
    MEM_B(0X1A, ctx->r12) = ctx->r13;
    // 0x800BA478: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA47C: nop

    // 0x800BA480: lw          $t3, 0x1C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X1C);
    // 0x800BA484: nop

    // 0x800BA488: ori         $t0, $t3, 0x4
    ctx->r8 = ctx->r11 | 0X4;
    // 0x800BA48C: sw          $t0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r8;
    // 0x800BA490: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA494: nop

    // 0x800BA498: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x800BA49C: nop

    // 0x800BA4A0: addiu       $t2, $t9, 0x2
    ctx->r10 = ADD32(ctx->r25, 0X2);
    // 0x800BA4A4: sw          $t2, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r10;
    // 0x800BA4A8: b           L_800BA730
    // 0x800BA4AC: nop

        goto L_800BA730;
    // 0x800BA4AC: nop

L_800BA4B0:
    // 0x800BA4B0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA4B4: nop

    // 0x800BA4B8: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x800BA4BC: nop

    // 0x800BA4C0: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800BA4C4: nop

    // 0x800BA4C8: sb          $t5, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r13;
    // 0x800BA4CC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA4D0: nop

    // 0x800BA4D4: lw          $t3, 0x1C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X1C);
    // 0x800BA4D8: nop

    // 0x800BA4DC: ori         $t0, $t3, 0x8
    ctx->r8 = ctx->r11 | 0X8;
    // 0x800BA4E0: sw          $t0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r8;
    // 0x800BA4E4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA4E8: nop

    // 0x800BA4EC: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800BA4F0: nop

    // 0x800BA4F4: addiu       $t2, $t9, 0x2
    ctx->r10 = ADD32(ctx->r25, 0X2);
    // 0x800BA4F8: sw          $t2, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r10;
    // 0x800BA4FC: b           L_800BA730
    // 0x800BA500: nop

        goto L_800BA730;
    // 0x800BA500: nop

L_800BA504:
    // 0x800BA504: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA508: nop

    // 0x800BA50C: lw          $t7, 0x1C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1C);
    // 0x800BA510: nop

    // 0x800BA514: ori         $t5, $t7, 0x1F
    ctx->r13 = ctx->r15 | 0X1F;
    // 0x800BA518: sw          $t5, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r13;
    // 0x800BA51C: b           L_800BA730
    // 0x800BA520: nop

        goto L_800BA730;
    // 0x800BA520: nop

L_800BA524:
    // 0x800BA524: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA528: nop

    // 0x800BA52C: sb          $zero, 0x32($t8)
    MEM_B(0X32, ctx->r24) = 0;
    // 0x800BA530: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA534: nop

    // 0x800BA538: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x800BA53C: nop

    // 0x800BA540: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x800BA544: jal         0x800BB16C
    // 0x800BA548: nop

    func_800BB16C(rdram, ctx);
        goto after_1;
    // 0x800BA548: nop

    after_1:
    // 0x800BA54C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA550: nop

    // 0x800BA554: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x800BA558: nop

    // 0x800BA55C: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x800BA560: nop

    // 0x800BA564: sb          $t2, 0x32($t4)
    MEM_B(0X32, ctx->r12) = ctx->r10;
    // 0x800BA568: b           L_800BA730
    // 0x800BA56C: nop

        goto L_800BA730;
    // 0x800BA56C: nop

L_800BA570:
    // 0x800BA570: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA574: jal         0x800BA1E8
    // 0x800BA578: nop

    AudioDriver_DeallocSound(rdram, ctx);
        goto after_2;
    // 0x800BA578: nop

    after_2:
    // 0x800BA57C: b           L_800BA730
    // 0x800BA580: nop

        goto L_800BA730;
    // 0x800BA580: nop

L_800BA584:
    // 0x800BA584: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA588: jal         0x800BA1E8
    // 0x800BA58C: nop

    AudioDriver_DeallocSound(rdram, ctx);
        goto after_3;
    // 0x800BA58C: nop

    after_3:
    // 0x800BA590: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BA594: nop

    // 0x800BA598: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800BA59C: nop

    // 0x800BA5A0: andi        $t5, $t7, 0x4
    ctx->r13 = ctx->r15 & 0X4;
    // 0x800BA5A4: beq         $t5, $zero, L_800BA5B8
    if (ctx->r13 == 0) {
        // 0x800BA5A8: nop

            goto L_800BA5B8;
    }
    // 0x800BA5A8: nop

    // 0x800BA5AC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800BA5B0: b           L_800BA5D0
    // 0x800BA5B4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
        goto L_800BA5D0;
    // 0x800BA5B4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
L_800BA5B8:
    // 0x800BA5B8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800BA5BC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800BA5C0: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x800BA5C4: nop

    // 0x800BA5C8: and         $t0, $t3, $at
    ctx->r8 = ctx->r11 & ctx->r1;
    // 0x800BA5CC: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
L_800BA5D0:
    // 0x800BA5D0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA5D4: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x800BA5D8: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800BA5DC: b           L_800BA730
    // 0x800BA5E0: nop

        goto L_800BA730;
    // 0x800BA5E0: nop

L_800BA5E4:
    // 0x800BA5E4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA5E8: nop

    // 0x800BA5EC: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x800BA5F0: nop

    // 0x800BA5F4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800BA5F8: nop

    // 0x800BA5FC: sh          $t7, 0x2E($t4)
    MEM_H(0X2E, ctx->r12) = ctx->r15;
    // 0x800BA600: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA604: nop

    // 0x800BA608: lw          $t1, 0xC($t5)
    ctx->r9 = MEM_W(ctx->r13, 0XC);
    // 0x800BA60C: nop

    // 0x800BA610: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x800BA614: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
    // 0x800BA618: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA61C: nop

    // 0x800BA620: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    // 0x800BA624: nop

    // 0x800BA628: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x800BA62C: b           L_800BA730
    // 0x800BA630: nop

        goto L_800BA730;
    // 0x800BA630: nop

L_800BA634:
    // 0x800BA634: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA638: nop

    // 0x800BA63C: lh          $t2, 0x2E($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X2E);
    // 0x800BA640: nop

    // 0x800BA644: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x800BA648: sh          $t6, 0x2E($t9)
    MEM_H(0X2E, ctx->r25) = ctx->r14;
    // 0x800BA64C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA650: nop

    // 0x800BA654: lh          $t4, 0x2E($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X2E);
    // 0x800BA658: nop

    // 0x800BA65C: beq         $t4, $zero, L_800BA678
    if (ctx->r12 == 0) {
        // 0x800BA660: nop

            goto L_800BA678;
    }
    // 0x800BA660: nop

    // 0x800BA664: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA668: nop

    // 0x800BA66C: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x800BA670: nop

    // 0x800BA674: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
L_800BA678:
    // 0x800BA678: b           L_800BA730
    // 0x800BA67C: nop

        goto L_800BA730;
    // 0x800BA67C: nop

L_800BA680:
    // 0x800BA680: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA684: nop

    // 0x800BA688: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x800BA68C: nop

    // 0x800BA690: sw          $t8, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r24;
    // 0x800BA694: b           L_800BA730
    // 0x800BA698: nop

        goto L_800BA730;
    // 0x800BA698: nop

L_800BA69C:
    // 0x800BA69C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA6A0: nop

    // 0x800BA6A4: lw          $t2, 0x14($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X14);
    // 0x800BA6A8: nop

    // 0x800BA6AC: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x800BA6B0: b           L_800BA730
    // 0x800BA6B4: nop

        goto L_800BA730;
    // 0x800BA6B4: nop

L_800BA6B8:
    // 0x800BA6B8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA6BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA6C0: lh          $t9, 0x18($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X18);
    // 0x800BA6C4: nop

    // 0x800BA6C8: beq         $t9, $at, L_800BA728
    if (ctx->r25 == ctx->r1) {
        // 0x800BA6CC: nop

            goto L_800BA728;
    }
    // 0x800BA6CC: nop

    // 0x800BA6D0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA6D4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA6D8: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA6DC: lh          $a1, 0x18($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X18);
    // 0x800BA6E0: jal         0x800C9760
    // 0x800BA6E4: nop

    alSndpSetSound(rdram, ctx);
        goto after_4;
    // 0x800BA6E4: nop

    after_4:
    // 0x800BA6E8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA6EC: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA6F0: jal         0x800C97D0
    // 0x800BA6F4: nop

    alSndpGetState(rdram, ctx);
        goto after_5;
    // 0x800BA6F4: nop

    after_5:
    // 0x800BA6F8: beq         $v0, $zero, L_800BA728
    if (ctx->r2 == 0) {
        // 0x800BA6FC: nop

            goto L_800BA728;
    }
    // 0x800BA6FC: nop

    // 0x800BA700: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA704: nop

    // 0x800BA708: lw          $t3, 0xC($t4)
    ctx->r11 = MEM_W(ctx->r12, 0XC);
    // 0x800BA70C: nop

    // 0x800BA710: addiu       $t1, $t3, -0x2
    ctx->r9 = ADD32(ctx->r11, -0X2);
    // 0x800BA714: sw          $t1, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r9;
    // 0x800BA718: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA71C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BA720: b           L_800BA728
    // 0x800BA724: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
        goto L_800BA728;
    // 0x800BA724: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
L_800BA728:
    // 0x800BA728: b           L_800BA730
    // 0x800BA72C: nop

        goto L_800BA730;
    // 0x800BA72C: nop

L_800BA730:
    // 0x800BA730: b           L_800BA738
    // 0x800BA734: nop

        goto L_800BA738;
    // 0x800BA734: nop

L_800BA738:
    // 0x800BA738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA73C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BA740: jr          $ra
    // 0x800BA744: nop

    return;
    // 0x800BA744: nop

;}
RECOMP_FUNC void func_800BA748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA748: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BA74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA750: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BA754: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800BA758: nop

    // 0x800BA75C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800BA760: nop

    // 0x800BA764: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800BA768: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA76C: nop

    // 0x800BA770: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x800BA774: nop

    // 0x800BA778: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x800BA77C: beq         $t0, $zero, L_800BA7E8
    if (ctx->r8 == 0) {
        // 0x800BA780: nop

            goto L_800BA7E8;
    }
    // 0x800BA780: nop

    // 0x800BA784: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA788: nop

    // 0x800BA78C: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x800BA790: nop

    // 0x800BA794: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800BA798: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800BA79C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800BA7A0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA7A4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BA7A8: lw          $t4, -0x17E4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X17E4);
    // 0x800BA7AC: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x800BA7B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800BA7B4: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800BA7B8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800BA7BC: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800BA7C0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800BA7C4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA7C8: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x800BA7CC: lw          $a1, 0x10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X10);
    // 0x800BA7D0: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA7D4: jal         0x800C9F50
    // 0x800BA7D8: nop

    alSndpAllocate(rdram, ctx);
        goto after_0;
    // 0x800BA7D8: nop

    after_0:
    // 0x800BA7DC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA7E0: nop

    // 0x800BA7E4: sh          $v0, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r2;
L_800BA7E8:
    // 0x800BA7E8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA7EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA7F0: lh          $t6, 0x18($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X18);
    // 0x800BA7F4: nop

    // 0x800BA7F8: beq         $t6, $at, L_800BA9B0
    if (ctx->r14 == ctx->r1) {
        // 0x800BA7FC: nop

            goto L_800BA9B0;
    }
    // 0x800BA7FC: nop

    // 0x800BA800: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA804: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA808: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA80C: lh          $a1, 0x18($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X18);
    // 0x800BA810: jal         0x800C9760
    // 0x800BA814: nop

    alSndpSetSound(rdram, ctx);
        goto after_1;
    // 0x800BA814: nop

    after_1:
    // 0x800BA818: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA81C: nop

    // 0x800BA820: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x800BA824: nop

    // 0x800BA828: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800BA82C: beq         $t1, $zero, L_800BA8AC
    if (ctx->r9 == 0) {
        // 0x800BA830: nop

            goto L_800BA8AC;
    }
    // 0x800BA830: nop

    // 0x800BA834: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA838: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA83C: lw          $t2, 0x24($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X24);
    // 0x800BA840: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA844: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800BA848: bgez        $t2, L_800BA860
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BA84C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BA860;
    }
    // 0x800BA84C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BA850: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BA854: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BA858: nop

    // 0x800BA85C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800BA860:
    // 0x800BA860: lw          $t3, 0x28($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X28);
    // 0x800BA864: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BA868: lwc1        $f10, -0x244($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X244);
    // 0x800BA86C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800BA870: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BA874: bgez        $t3, L_800BA88C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BA878: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BA88C;
    }
    // 0x800BA878: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BA87C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BA880: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BA884: nop

    // 0x800BA888: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800BA88C:
    // 0x800BA88C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BA890: lwc1        $f6, -0x240($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X240);
    // 0x800BA894: nop

    // 0x800BA898: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800BA89C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800BA8A0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800BA8A4: jal         0x800C9FF0
    // 0x800BA8A8: nop

    alSndpSetPitch(rdram, ctx);
        goto after_2;
    // 0x800BA8A8: nop

    after_2:
L_800BA8AC:
    // 0x800BA8AC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA8B0: nop

    // 0x800BA8B4: lw          $t4, 0x1C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X1C);
    // 0x800BA8B8: nop

    // 0x800BA8BC: andi        $t6, $t4, 0x8
    ctx->r14 = ctx->r12 & 0X8;
    // 0x800BA8C0: beq         $t6, $zero, L_800BA8E0
    if (ctx->r14 == 0) {
        // 0x800BA8C4: nop

            goto L_800BA8E0;
    }
    // 0x800BA8C4: nop

    // 0x800BA8C8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA8CC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA8D0: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA8D4: lbu         $a1, 0x30($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X30);
    // 0x800BA8D8: jal         0x800CA050
    // 0x800BA8DC: nop

    alSndpSetFXMix(rdram, ctx);
        goto after_3;
    // 0x800BA8DC: nop

    after_3:
L_800BA8E0:
    // 0x800BA8E0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA8E4: nop

    // 0x800BA8E8: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x800BA8EC: nop

    // 0x800BA8F0: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x800BA8F4: beq         $t1, $zero, L_800BA914
    if (ctx->r9 == 0) {
        // 0x800BA8F8: nop

            goto L_800BA914;
    }
    // 0x800BA8F8: nop

    // 0x800BA8FC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA900: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA904: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA908: lbu         $a1, 0x31($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X31);
    // 0x800BA90C: jal         0x800CA0B0
    // 0x800BA910: nop

    alSndpSetPan(rdram, ctx);
        goto after_4;
    // 0x800BA910: nop

    after_4:
L_800BA914:
    // 0x800BA914: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA918: nop

    // 0x800BA91C: lw          $t3, 0x1C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X1C);
    // 0x800BA920: nop

    // 0x800BA924: andi        $t5, $t3, 0x2
    ctx->r13 = ctx->r11 & 0X2;
    // 0x800BA928: beq         $t5, $zero, L_800BA984
    if (ctx->r13 == 0) {
        // 0x800BA92C: nop

            goto L_800BA984;
    }
    // 0x800BA92C: nop

    // 0x800BA930: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA934: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800BA938: lh          $t6, 0x2C($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X2C);
    // 0x800BA93C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x800BA940: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x800BA944: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA948: mflo        $t0
    ctx->r8 = lo;
    // 0x800BA94C: nop

    // 0x800BA950: nop

    // 0x800BA954: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800BA958: mflo        $t1
    ctx->r9 = lo;
    // 0x800BA95C: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x800BA960: sra         $t2, $t1, 31
    ctx->r10 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800BA964: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800BA968: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800BA96C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800BA970: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA974: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA978: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800BA97C: jal         0x800CA110
    // 0x800BA980: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    alSndpSetVol(rdram, ctx);
        goto after_5;
    // 0x800BA980: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_5:
L_800BA984:
    // 0x800BA984: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA988: nop

    // 0x800BA98C: lw          $t4, 0x1C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X1C);
    // 0x800BA990: nop

    // 0x800BA994: andi        $t7, $t4, 0x10
    ctx->r15 = ctx->r12 & 0X10;
    // 0x800BA998: beq         $t7, $zero, L_800BA9B0
    if (ctx->r15 == 0) {
        // 0x800BA99C: nop

            goto L_800BA9B0;
    }
    // 0x800BA99C: nop

    // 0x800BA9A0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BA9A4: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800BA9A8: jal         0x800CA170
    // 0x800BA9AC: nop

    alSndpPlay(rdram, ctx);
        goto after_6;
    // 0x800BA9AC: nop

    after_6:
L_800BA9B0:
    // 0x800BA9B0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA9B4: nop

    // 0x800BA9B8: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    // 0x800BA9BC: b           L_800BA9C4
    // 0x800BA9C0: nop

        goto L_800BA9C4;
    // 0x800BA9C0: nop

L_800BA9C4:
    // 0x800BA9C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA9C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BA9CC: jr          $ra
    // 0x800BA9D0: nop

    return;
    // 0x800BA9D0: nop

;}
RECOMP_FUNC void AudioDriver_UpdateSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA9D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BA9D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BA9DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BA9E0: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x800BA9E4: lw          $s0, -0x7310($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7310);
    // 0x800BA9E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BA9EC: beq         $s0, $at, L_800BAA60
    if (ctx->r16 == ctx->r1) {
        // 0x800BA9F0: nop

            goto L_800BAA60;
    }
    // 0x800BA9F0: nop

    // 0x800BA9F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BA9F8: beq         $s0, $at, L_800BAA08
    if (ctx->r16 == ctx->r1) {
        // 0x800BA9FC: nop

            goto L_800BAA08;
    }
    // 0x800BA9FC: nop

    // 0x800BAA00: b           L_800BAA8C
    // 0x800BAA04: nop

        goto L_800BAA8C;
    // 0x800BAA04: nop

L_800BAA08:
    // 0x800BAA08: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BAA0C: lw          $t6, -0x17DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17DC);
    // 0x800BAA10: nop

    // 0x800BAA14: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x800BAA18: nop

    // 0x800BAA1C: bne         $t7, $zero, L_800BAA58
    if (ctx->r15 != 0) {
        // 0x800BAA20: nop

            goto L_800BAA58;
    }
    // 0x800BAA20: nop

    // 0x800BAA24: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BAA28: lw          $t8, -0x17CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17CC);
    // 0x800BAA2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAA30: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800BAA34: sw          $t9, -0x17CC($at)
    MEM_W(-0X17CC, ctx->r1) = ctx->r25;
    // 0x800BAA38: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800BAA3C: lw          $t0, -0x17CC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X17CC);
    // 0x800BAA40: nop

    // 0x800BAA44: bne         $t0, $zero, L_800BAA58
    if (ctx->r8 != 0) {
        // 0x800BAA48: nop

            goto L_800BAA58;
    }
    // 0x800BAA48: nop

    // 0x800BAA4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800BAA50: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BAA54: sw          $t1, -0x7310($at)
    MEM_W(-0X7310, ctx->r1) = ctx->r9;
L_800BAA58:
    // 0x800BAA58: b           L_800BAA8C
    // 0x800BAA5C: nop

        goto L_800BAA8C;
    // 0x800BAA5C: nop

L_800BAA60:
    // 0x800BAA60: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800BAA64: lw          $t2, -0x17DC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X17DC);
    // 0x800BAA68: nop

    // 0x800BAA6C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x800BAA70: nop

    // 0x800BAA74: bne         $t3, $zero, L_800BAA84
    if (ctx->r11 != 0) {
        // 0x800BAA78: nop

            goto L_800BAA84;
    }
    // 0x800BAA78: nop

    // 0x800BAA7C: jal         0x800BB3EC
    // 0x800BAA80: nop

    AudioDriver_StopSeqplayer(rdram, ctx);
        goto after_0;
    // 0x800BAA80: nop

    after_0:
L_800BAA84:
    // 0x800BAA84: b           L_800BAA8C
    // 0x800BAA88: nop

        goto L_800BAA8C;
    // 0x800BAA88: nop

L_800BAA8C:
    // 0x800BAA8C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BAA90: lw          $t4, -0x17C8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X17C8);
    // 0x800BAA94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BAA98: beq         $t4, $at, L_800BABA4
    if (ctx->r12 == ctx->r1) {
        // 0x800BAA9C: nop

            goto L_800BABA4;
    }
    // 0x800BAA9C: nop

    // 0x800BAAA0: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800BAAA4: lw          $t5, -0x7310($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7310);
    // 0x800BAAA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BAAAC: bne         $t5, $at, L_800BAABC
    if (ctx->r13 != ctx->r1) {
        // 0x800BAAB0: nop

            goto L_800BAABC;
    }
    // 0x800BAAB0: nop

    // 0x800BAAB4: jal         0x800BB3EC
    // 0x800BAAB8: nop

    AudioDriver_StopSeqplayer(rdram, ctx);
        goto after_1;
    // 0x800BAAB8: nop

    after_1:
L_800BAABC:
    // 0x800BAABC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BAAC0: lw          $t6, -0x17C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17C8);
    // 0x800BAAC4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800BAAC8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800BAACC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800BAAD0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800BAAD4: lw          $t9, -0x17D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X17D0);
    // 0x800BAAD8: lw          $t8, -0x5A44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A44);
    // 0x800BAADC: nop

    // 0x800BAAE0: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BAAE4: beq         $at, $zero, L_800BABA4
    if (ctx->r1 == 0) {
        // 0x800BAAE8: nop

            goto L_800BABA4;
    }
    // 0x800BAAE8: nop

    // 0x800BAAEC: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800BAAF0: lw          $t0, -0x7310($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7310);
    // 0x800BAAF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BAAF8: bne         $t0, $at, L_800BABA4
    if (ctx->r8 != ctx->r1) {
        // 0x800BAAFC: nop

            goto L_800BABA4;
    }
    // 0x800BAAFC: nop

    // 0x800BAB00: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800BAB04: lw          $t1, -0x17C8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17C8);
    // 0x800BAB08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAB0C: sw          $t1, -0x17C4($at)
    MEM_W(-0X17C4, ctx->r1) = ctx->r9;
    // 0x800BAB10: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800BAB14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAB18: sw          $t2, -0x17C8($at)
    MEM_W(-0X17C8, ctx->r1) = ctx->r10;
    // 0x800BAB1C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800BAB20: lw          $t3, -0x17C4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X17C4);
    // 0x800BAB24: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800BAB28: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800BAB2C: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x800BAB30: lw          $a0, -0x5A44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5A44);
    // 0x800BAB34: jal         0x800B97E4
    // 0x800BAB38: nop

    AudioDriver_GetSequence(rdram, ctx);
        goto after_2;
    // 0x800BAB38: nop

    after_2:
    // 0x800BAB3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BAB40: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BAB44: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800BAB48: lw          $a1, -0x17D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17D4);
    // 0x800BAB4C: lw          $a0, -0x17D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17D8);
    // 0x800BAB50: jal         0x800CA73C
    // 0x800BAB54: nop

    alCSeqNew(rdram, ctx);
        goto after_3;
    // 0x800BAB54: nop

    after_3:
    // 0x800BAB58: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BAB5C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800BAB60: lw          $a1, -0x17D8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17D8);
    // 0x800BAB64: lw          $a0, -0x17DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17DC);
    // 0x800BAB68: jal         0x800CACA0
    // 0x800BAB6C: nop

    alSeqpSetSeq(rdram, ctx);
        goto after_4;
    // 0x800BAB6C: nop

    after_4:
    // 0x800BAB70: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BAB74: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800BAB78: lw          $a1, -0x17E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17E8);
    // 0x800BAB7C: lw          $a0, -0x17DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17DC);
    // 0x800BAB80: jal         0x800CACE0
    // 0x800BAB84: nop

    alSeqpSetBank(rdram, ctx);
        goto after_5;
    // 0x800BAB84: nop

    after_5:
    // 0x800BAB88: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BAB8C: lw          $a0, -0x17DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17DC);
    // 0x800BAB90: jal         0x800CAD20
    // 0x800BAB94: nop

    alSeqpPlay(rdram, ctx);
        goto after_6;
    // 0x800BAB94: nop

    after_6:
    // 0x800BAB98: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800BAB9C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BABA0: sw          $t5, -0x7310($at)
    MEM_W(-0X7310, ctx->r1) = ctx->r13;
L_800BABA4:
    // 0x800BABA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BABA8: sw          $zero, -0x7304($at)
    MEM_W(-0X7304, ctx->r1) = 0;
    // 0x800BABAC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800BABB0: lw          $t6, -0x7310($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7310);
    // 0x800BABB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BABB8: bne         $t6, $at, L_800BAD34
    if (ctx->r14 != ctx->r1) {
        // 0x800BABBC: nop

            goto L_800BAD34;
    }
    // 0x800BABBC: nop

    // 0x800BABC0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800BABC4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BABC8: lw          $t8, -0x17B4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17B4);
    // 0x800BABCC: lw          $t7, -0x17C0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X17C0);
    // 0x800BABD0: nop

    // 0x800BABD4: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BABD8: beq         $at, $zero, L_800BAC3C
    if (ctx->r1 == 0) {
        // 0x800BABDC: nop

            goto L_800BAC3C;
    }
    // 0x800BABDC: nop

    // 0x800BABE0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800BABE4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800BABE8: lw          $t0, -0x17B8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X17B8);
    // 0x800BABEC: lw          $t9, -0x17C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X17C0);
    // 0x800BABF0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BABF4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800BABF8: sw          $t1, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r9;
    // 0x800BABFC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800BAC00: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800BAC04: lw          $t3, -0x17B4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X17B4);
    // 0x800BAC08: lw          $t2, -0x17C0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X17C0);
    // 0x800BAC0C: nop

    // 0x800BAC10: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BAC14: bne         $at, $zero, L_800BAC30
    if (ctx->r1 != 0) {
        // 0x800BAC18: nop

            goto L_800BAC30;
    }
    // 0x800BAC18: nop

    // 0x800BAC1C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BAC20: lw          $t4, -0x17B4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X17B4);
    // 0x800BAC24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAC28: b           L_800BAC3C
    // 0x800BAC2C: sw          $t4, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r12;
        goto L_800BAC3C;
    // 0x800BAC2C: sw          $t4, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r12;
L_800BAC30:
    // 0x800BAC30: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x800BAC34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BAC38: sw          $t5, -0x7304($at)
    MEM_W(-0X7304, ctx->r1) = ctx->r13;
L_800BAC3C:
    // 0x800BAC3C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BAC40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800BAC44: lw          $t7, -0x17B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X17B4);
    // 0x800BAC48: lw          $t6, -0x17C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17C0);
    // 0x800BAC4C: nop

    // 0x800BAC50: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BAC54: beq         $at, $zero, L_800BACF0
    if (ctx->r1 == 0) {
        // 0x800BAC58: nop

            goto L_800BACF0;
    }
    // 0x800BAC58: nop

    // 0x800BAC5C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BAC60: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800BAC64: lw          $t9, -0x17B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X17B8);
    // 0x800BAC68: lw          $t8, -0x17C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17C0);
    // 0x800BAC6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAC70: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800BAC74: sw          $t0, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r8;
    // 0x800BAC78: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800BAC7C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800BAC80: lw          $t2, -0x17B4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X17B4);
    // 0x800BAC84: lw          $t1, -0x17C0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17C0);
    // 0x800BAC88: nop

    // 0x800BAC8C: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800BAC90: bne         $at, $zero, L_800BACE4
    if (ctx->r1 != 0) {
        // 0x800BAC94: nop

            goto L_800BACE4;
    }
    // 0x800BAC94: nop

    // 0x800BAC98: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800BAC9C: lw          $t3, -0x17B4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X17B4);
    // 0x800BACA0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BACA4: sw          $t3, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r11;
    // 0x800BACA8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BACAC: lw          $t4, -0x17C0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X17C0);
    // 0x800BACB0: nop

    // 0x800BACB4: bne         $t4, $zero, L_800BACDC
    if (ctx->r12 != 0) {
        // 0x800BACB8: nop

            goto L_800BACDC;
    }
    // 0x800BACB8: nop

    // 0x800BACBC: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800BACC0: lw          $t5, -0x7308($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7308);
    // 0x800BACC4: nop

    // 0x800BACC8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800BACCC: beq         $t6, $zero, L_800BACDC
    if (ctx->r14 == 0) {
        // 0x800BACD0: nop

            goto L_800BACDC;
    }
    // 0x800BACD0: nop

    // 0x800BACD4: jal         0x800BB3EC
    // 0x800BACD8: nop

    AudioDriver_StopSeqplayer(rdram, ctx);
        goto after_7;
    // 0x800BACD8: nop

    after_7:
L_800BACDC:
    // 0x800BACDC: b           L_800BACF0
    // 0x800BACE0: nop

        goto L_800BACF0;
    // 0x800BACE0: nop

L_800BACE4:
    // 0x800BACE4: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800BACE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BACEC: sw          $t7, -0x7304($at)
    MEM_W(-0X7304, ctx->r1) = ctx->r15;
L_800BACF0:
    // 0x800BACF0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BACF4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800BACF8: lw          $t9, -0x17BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X17BC);
    // 0x800BACFC: lw          $t8, -0x17C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17C0);
    // 0x800BAD00: nop

    // 0x800BAD04: beq         $t8, $t9, L_800BAD34
    if (ctx->r24 == ctx->r25) {
        // 0x800BAD08: nop

            goto L_800BAD34;
    }
    // 0x800BAD08: nop

    // 0x800BAD0C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800BAD10: lw          $t0, -0x17C0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X17C0);
    // 0x800BAD14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAD18: sw          $t0, -0x17BC($at)
    MEM_W(-0X17BC, ctx->r1) = ctx->r8;
    // 0x800BAD1C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BAD20: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800BAD24: lw          $a1, -0x17C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17C0);
    // 0x800BAD28: lw          $a0, -0x17DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17DC);
    // 0x800BAD2C: jal         0x800CAD50
    // 0x800BAD30: nop

    alSeqpSetVol(rdram, ctx);
        goto after_8;
    // 0x800BAD30: nop

    after_8:
L_800BAD34:
    // 0x800BAD34: b           L_800BAD3C
    // 0x800BAD38: nop

        goto L_800BAD3C;
    // 0x800BAD38: nop

L_800BAD3C:
    // 0x800BAD3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAD40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BAD44: jr          $ra
    // 0x800BAD48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800BAD48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void AudioDriver_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAD4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BAD50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BAD54: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BAD58: lw          $t6, -0x17AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17AC);
    // 0x800BAD5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAD60: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BAD64: sw          $t7, -0x17AC($at)
    MEM_W(-0X17AC, ctx->r1) = ctx->r15;
    // 0x800BAD68: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BAD6C: lw          $t8, -0x17AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17AC);
    // 0x800BAD70: nop

    // 0x800BAD74: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BAD78: beq         $t9, $zero, L_800BAD90
    if (ctx->r25 == 0) {
        // 0x800BAD7C: nop

            goto L_800BAD90;
    }
    // 0x800BAD7C: nop

    // 0x800BAD80: jal         0x800BA9D4
    // 0x800BAD84: nop

    AudioDriver_UpdateSequence(rdram, ctx);
        goto after_0;
    // 0x800BAD84: nop

    after_0:
    // 0x800BAD88: jal         0x800B9F10
    // 0x800BAD8C: nop

    AudioDriver_UpdateSounds(rdram, ctx);
        goto after_1;
    // 0x800BAD8C: nop

    after_1:
L_800BAD90:
    // 0x800BAD90: b           L_800BAD98
    // 0x800BAD94: nop

        goto L_800BAD98;
    // 0x800BAD94: nop

L_800BAD98:
    // 0x800BAD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BAD9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BADA0: jr          $ra
    // 0x800BADA4: nop

    return;
    // 0x800BADA4: nop

;}
RECOMP_FUNC void func_800BADA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BADA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BADAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BADB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BADB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BADB8:
    // 0x800BADB8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BADBC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BADC0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BADC4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BADC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BADCC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800BADD0: lw          $t8, -0x1A64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1A64);
    // 0x800BADD4: nop

    // 0x800BADD8: bne         $t8, $zero, L_800BADE8
    if (ctx->r24 != 0) {
        // 0x800BADDC: nop

            goto L_800BADE8;
    }
    // 0x800BADDC: nop

    // 0x800BADE0: b           L_800BAE00
    // 0x800BADE4: nop

        goto L_800BAE00;
    // 0x800BADE4: nop

L_800BADE8:
    // 0x800BADE8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BADEC: nop

    // 0x800BADF0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BADF4: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800BADF8: bne         $at, $zero, L_800BADB8
    if (ctx->r1 != 0) {
        // 0x800BADFC: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800BADB8;
    }
    // 0x800BADFC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_800BAE00:
    // 0x800BAE00: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE04: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BAE08: bne         $t1, $at, L_800BAE18
    if (ctx->r9 != ctx->r1) {
        // 0x800BAE0C: nop

            goto L_800BAE18;
    }
    // 0x800BAE0C: nop

    // 0x800BAE10: b           L_800BB15C
    // 0x800BAE14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BB15C;
    // 0x800BAE14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BAE18:
    // 0x800BAE18: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAE20: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800BAE24: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800BAE28: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BAE2C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800BAE30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800BAE34: sw          $t2, -0x1A64($at)
    MEM_W(-0X1A64, ctx->r1) = ctx->r10;
    // 0x800BAE38: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE3C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BAE40: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BAE44: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BAE48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BAE4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800BAE50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BAE54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAE58: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BAE5C: sw          $t5, -0x1980($at)
    MEM_W(-0X1980, ctx->r1) = ctx->r13;
    // 0x800BAE60: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE64: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAE68: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BAE6C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800BAE70: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BAE74: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800BAE78: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BAE7C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800BAE80: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800BAE84: sh          $t8, -0x1970($at)
    MEM_H(-0X1970, ctx->r1) = ctx->r24;
    // 0x800BAE88: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAE8C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800BAE90: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800BAE94: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800BAE98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BAE9C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800BAEA0: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x800BAEA4: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x800BAEA8: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800BAEAC: lw          $t2, -0x5EBC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5EBC);
    // 0x800BAEB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BAEB4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAEB8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800BAEBC: sw          $t2, -0x197C($at)
    MEM_W(-0X197C, ctx->r1) = ctx->r10;
    // 0x800BAEC0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAEC4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800BAEC8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800BAECC: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800BAED0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BAED4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800BAED8: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800BAEDC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800BAEE0: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800BAEE4: lbu         $t9, -0x5EB8($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X5EB8);
    // 0x800BAEE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BAEEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAEF0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800BAEF4: sb          $t9, -0x1956($at)
    MEM_B(-0X1956, ctx->r1) = ctx->r25;
    // 0x800BAEF8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAEFC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800BAF00: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800BAF04: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800BAF08: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800BAF0C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800BAF10: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800BAF14: addiu       $t4, $t4, -0x1988
    ctx->r12 = ADD32(ctx->r12, -0X1988);
    // 0x800BAF18: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x800BAF1C: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x800BAF20: nop

    // 0x800BAF24: sw          $t6, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r14;
    // 0x800BAF28: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAF2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAF30: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BAF34: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BAF38: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BAF3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800BAF40: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BAF44: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BAF48: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800BAF4C: sw          $t5, -0x1984($at)
    MEM_W(-0X1984, ctx->r1) = ctx->r13;
    // 0x800BAF50: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAF54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAF58: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BAF5C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800BAF60: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BAF64: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BAF68: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BAF6C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800BAF70: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800BAF74: sh          $t9, -0x195C($at)
    MEM_H(-0X195C, ctx->r1) = ctx->r25;
    // 0x800BAF78: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAF7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAF80: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800BAF84: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800BAF88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BAF8C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800BAF90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BAF94: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800BAF98: addiu       $t3, $zero, 0x2710
    ctx->r11 = ADD32(0, 0X2710);
    // 0x800BAF9C: sw          $t3, -0x1964($at)
    MEM_W(-0X1964, ctx->r1) = ctx->r11;
    // 0x800BAFA0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAFA4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAFA8: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800BAFAC: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x800BAFB0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BAFB4: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800BAFB8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BAFBC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800BAFC0: addiu       $t2, $zero, 0x2710
    ctx->r10 = ADD32(0, 0X2710);
    // 0x800BAFC4: sw          $t2, -0x1960($at)
    MEM_W(-0X1960, ctx->r1) = ctx->r10;
    // 0x800BAFC8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAFCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAFD0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800BAFD4: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x800BAFD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BAFDC: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x800BAFE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BAFE4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800BAFE8: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800BAFEC: sb          $t8, -0x1957($at)
    MEM_B(-0X1957, ctx->r1) = ctx->r24;
    // 0x800BAFF0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAFF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAFF8: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800BAFFC: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800BB000: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB004: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x800BB008: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB00C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800BB010: sb          $zero, -0x1958($at)
    MEM_B(-0X1958, ctx->r1) = 0;
    // 0x800BB014: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB018: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB01C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BB020: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BB024: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BB028: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BB02C: addiu       $t3, $zero, 0x2710
    ctx->r11 = ADD32(0, 0X2710);
    // 0x800BB030: sw          $t3, -0x1A60($at)
    MEM_W(-0X1A60, ctx->r1) = ctx->r11;
    // 0x800BB034: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB038: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB03C: sll         $t0, $t5, 3
    ctx->r8 = S32(ctx->r13 << 3);
    // 0x800BB040: subu        $t0, $t0, $t5
    ctx->r8 = SUB32(ctx->r8, ctx->r13);
    // 0x800BB044: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BB048: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800BB04C: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800BB050: sb          $t2, -0x1A4E($at)
    MEM_B(-0X1A4E, ctx->r1) = ctx->r10;
    // 0x800BB054: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB058: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB05C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BB060: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800BB064: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BB068: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800BB06C: sb          $zero, -0x1A4D($at)
    MEM_B(-0X1A4D, ctx->r1) = 0;
    // 0x800BB070: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB074: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB078: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x800BB07C: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800BB080: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB084: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800BB088: addiu       $t1, $zero, 0x7FFF
    ctx->r9 = ADD32(0, 0X7FFF);
    // 0x800BB08C: sw          $t1, -0x1A5C($at)
    MEM_W(-0X1A5C, ctx->r1) = ctx->r9;
    // 0x800BB090: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB094: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB098: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x800BB09C: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x800BB0A0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BB0A4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800BB0A8: addiu       $t3, $zero, 0x7FFF
    ctx->r11 = ADD32(0, 0X7FFF);
    // 0x800BB0AC: sh          $t3, -0x1A50($at)
    MEM_H(-0X1A50, ctx->r1) = ctx->r11;
    // 0x800BB0B0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB0B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB0B8: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x800BB0BC: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800BB0C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BB0C4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BB0C8: addiu       $t2, $zero, 0x7FFF
    ctx->r10 = ADD32(0, 0X7FFF);
    // 0x800BB0CC: sw          $t2, -0x1A58($at)
    MEM_W(-0X1A58, ctx->r1) = ctx->r10;
    // 0x800BB0D0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB0D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB0D8: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x800BB0DC: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x800BB0E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB0E4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800BB0E8: sw          $zero, -0x1A54($at)
    MEM_W(-0X1A54, ctx->r1) = 0;
    // 0x800BB0EC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB0F0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800BB0F4: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x800BB0F8: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x800BB0FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB100: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x800BB104: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB108: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800BB10C: lbu         $t7, -0x1956($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1956);
    // 0x800BB110: nop

    // 0x800BB114: beq         $t7, $zero, L_800BB148
    if (ctx->r15 == 0) {
        // 0x800BB118: nop

            goto L_800BB148;
    }
    // 0x800BB118: nop

    // 0x800BB11C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB120: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800BB124: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800BB128: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x800BB12C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BB130: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800BB134: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BB138: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800BB13C: lbu         $a0, -0x1956($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1956);
    // 0x800BB140: jal         0x800BB16C
    // 0x800BB144: nop

    func_800BB16C(rdram, ctx);
        goto after_0;
    // 0x800BB144: nop

    after_0:
L_800BB148:
    // 0x800BB148: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB14C: b           L_800BB15C
    // 0x800BB150: nop

        goto L_800BB15C;
    // 0x800BB150: nop

    // 0x800BB154: b           L_800BB15C
    // 0x800BB158: nop

        goto L_800BB15C;
    // 0x800BB158: nop

L_800BB15C:
    // 0x800BB15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BB160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BB164: jr          $ra
    // 0x800BB168: nop

    return;
    // 0x800BB168: nop

;}
RECOMP_FUNC void func_800BB16C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB16C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BB170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB174: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BB178: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BB17C:
    // 0x800BB17C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB180: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BB184: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BB188: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BB18C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BB190: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800BB194: lw          $t8, -0x1A64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1A64);
    // 0x800BB198: nop

    // 0x800BB19C: beq         $t8, $zero, L_800BB21C
    if (ctx->r24 == 0) {
        // 0x800BB1A0: nop

            goto L_800BB21C;
    }
    // 0x800BB1A0: nop

    // 0x800BB1A4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB1A8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800BB1AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BB1B0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800BB1B4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BB1B8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800BB1BC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BB1C0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BB1C4: lbu         $t1, -0x1956($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1956);
    // 0x800BB1C8: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x800BB1CC: nop

    // 0x800BB1D0: bne         $t1, $t2, L_800BB21C
    if (ctx->r9 != ctx->r10) {
        // 0x800BB1D4: nop

            goto L_800BB21C;
    }
    // 0x800BB1D4: nop

    // 0x800BB1D8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB1DC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800BB1E0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800BB1E4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800BB1E8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB1EC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800BB1F0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB1F4: addiu       $t5, $t5, -0x1988
    ctx->r13 = ADD32(ctx->r13, -0X1988);
    // 0x800BB1F8: jal         0x800BA1E8
    // 0x800BB1FC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    AudioDriver_DeallocSound(rdram, ctx);
        goto after_0;
    // 0x800BB1FC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_0:
    // 0x800BB200: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB204: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB208: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BB20C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BB210: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BB214: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BB218: sw          $zero, -0x1A64($at)
    MEM_W(-0X1A64, ctx->r1) = 0;
L_800BB21C:
    // 0x800BB21C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB220: nop

    // 0x800BB224: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BB228: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800BB22C: bne         $at, $zero, L_800BB17C
    if (ctx->r1 != 0) {
        // 0x800BB230: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_800BB17C;
    }
    // 0x800BB230: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800BB234: b           L_800BB23C
    // 0x800BB238: nop

        goto L_800BB23C;
    // 0x800BB238: nop

L_800BB23C:
    // 0x800BB23C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BB240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BB244: jr          $ra
    // 0x800BB248: nop

    return;
    // 0x800BB248: nop

;}
RECOMP_FUNC void func_800BB24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB24C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BB250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB254: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BB258: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800BB25C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BB260: bne         $t6, $at, L_800BB2F8
    if (ctx->r14 != ctx->r1) {
        // 0x800BB264: nop

            goto L_800BB2F8;
    }
    // 0x800BB264: nop

    // 0x800BB268: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BB26C:
    // 0x800BB26C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB270: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800BB274: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800BB278: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BB27C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BB280: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800BB284: lw          $t9, -0x1A64($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1A64);
    // 0x800BB288: nop

    // 0x800BB28C: beq         $t9, $zero, L_800BB2D8
    if (ctx->r25 == 0) {
        // 0x800BB290: nop

            goto L_800BB2D8;
    }
    // 0x800BB290: nop

    // 0x800BB294: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB298: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800BB29C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BB2A0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800BB2A4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BB2A8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BB2AC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BB2B0: addiu       $t2, $t2, -0x1988
    ctx->r10 = ADD32(ctx->r10, -0X1988);
    // 0x800BB2B4: jal         0x800BA1E8
    // 0x800BB2B8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    AudioDriver_DeallocSound(rdram, ctx);
        goto after_0;
    // 0x800BB2B8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_0:
    // 0x800BB2BC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB2C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB2C4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800BB2C8: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800BB2CC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BB2D0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800BB2D4: sw          $zero, -0x1A64($at)
    MEM_W(-0X1A64, ctx->r1) = 0;
L_800BB2D8:
    // 0x800BB2D8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB2DC: nop

    // 0x800BB2E0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800BB2E4: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800BB2E8: bne         $at, $zero, L_800BB26C
    if (ctx->r1 != 0) {
        // 0x800BB2EC: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800BB26C;
    }
    // 0x800BB2EC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800BB2F0: b           L_800BB3B4
    // 0x800BB2F4: nop

        goto L_800BB3B4;
    // 0x800BB2F4: nop

L_800BB2F8:
    // 0x800BB2F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800BB2FC:
    // 0x800BB2FC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB300: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800BB304: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800BB308: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BB30C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BB310: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800BB314: lw          $t9, -0x1A64($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1A64);
    // 0x800BB318: nop

    // 0x800BB31C: beq         $t9, $zero, L_800BB39C
    if (ctx->r25 == 0) {
        // 0x800BB320: nop

            goto L_800BB39C;
    }
    // 0x800BB320: nop

    // 0x800BB324: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB328: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800BB32C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BB330: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800BB334: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BB338: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BB33C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BB340: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800BB344: lw          $t2, -0x1980($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1980);
    // 0x800BB348: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800BB34C: nop

    // 0x800BB350: bne         $t2, $t3, L_800BB39C
    if (ctx->r10 != ctx->r11) {
        // 0x800BB354: nop

            goto L_800BB39C;
    }
    // 0x800BB354: nop

    // 0x800BB358: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB35C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BB360: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800BB364: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800BB368: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BB36C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800BB370: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800BB374: addiu       $t6, $t6, -0x1988
    ctx->r14 = ADD32(ctx->r14, -0X1988);
    // 0x800BB378: jal         0x800BA1E8
    // 0x800BB37C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    AudioDriver_DeallocSound(rdram, ctx);
        goto after_1;
    // 0x800BB37C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_1:
    // 0x800BB380: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB384: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB388: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800BB38C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BB390: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BB394: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800BB398: sw          $zero, -0x1A64($at)
    MEM_W(-0X1A64, ctx->r1) = 0;
L_800BB39C:
    // 0x800BB39C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB3A0: nop

    // 0x800BB3A4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BB3A8: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800BB3AC: bne         $at, $zero, L_800BB2FC
    if (ctx->r1 != 0) {
        // 0x800BB3B0: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800BB2FC;
    }
    // 0x800BB3B0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_800BB3B4:
    // 0x800BB3B4: b           L_800BB3C4
    // 0x800BB3B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BB3C4;
    // 0x800BB3B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BB3BC: b           L_800BB3C4
    // 0x800BB3C0: nop

        goto L_800BB3C4;
    // 0x800BB3C0: nop

L_800BB3C4:
    // 0x800BB3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BB3C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BB3CC: jr          $ra
    // 0x800BB3D0: nop

    return;
    // 0x800BB3D0: nop

;}
RECOMP_FUNC void AudioDriver_UpdateSeqID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB3D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB3D8: sw          $a0, -0x17C8($at)
    MEM_W(-0X17C8, ctx->r1) = ctx->r4;
    // 0x800BB3DC: jr          $ra
    // 0x800BB3E0: nop

    return;
    // 0x800BB3E0: nop

    // 0x800BB3E4: jr          $ra
    // 0x800BB3E8: nop

    return;
    // 0x800BB3E8: nop

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
RECOMP_FUNC void func_800BB448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BB44C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB450: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BB454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BB458: jal         0x800BADA8
    // 0x800BB45C: nop

    func_800BADA8(rdram, ctx);
        goto after_0;
    // 0x800BB45C: nop

    after_0:
    // 0x800BB460: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BB464: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB468: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BB46C: bne         $t6, $at, L_800BB47C
    if (ctx->r14 != ctx->r1) {
        // 0x800BB470: nop

            goto L_800BB47C;
    }
    // 0x800BB470: nop

    // 0x800BB474: b           L_800BB4A4
    // 0x800BB478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BB4A4;
    // 0x800BB478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BB47C:
    // 0x800BB47C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800BB480: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800BB484: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800BB488: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BB48C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BB490: addiu       $t9, $t9, -0x1A68
    ctx->r25 = ADD32(ctx->r25, -0X1A68);
    // 0x800BB494: b           L_800BB4A4
    // 0x800BB498: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
        goto L_800BB4A4;
    // 0x800BB498: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800BB49C: b           L_800BB4A4
    // 0x800BB4A0: nop

        goto L_800BB4A4;
    // 0x800BB4A0: nop

L_800BB4A4:
    // 0x800BB4A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BB4A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BB4AC: jr          $ra
    // 0x800BB4B0: nop

    return;
    // 0x800BB4B0: nop

;}
RECOMP_FUNC void func_800BB4B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB4B4: beq         $a0, $zero, L_800BB4CC
    if (ctx->r4 == 0) {
        // 0x800BB4B8: nop

            goto L_800BB4CC;
    }
    // 0x800BB4B8: nop

    // 0x800BB4BC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800BB4C0: ori         $t7, $a1, 0x2
    ctx->r15 = ctx->r5 | 0X2;
    // 0x800BB4C4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800BB4C8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
L_800BB4CC:
    // 0x800BB4CC: jr          $ra
    // 0x800BB4D0: nop

    return;
    // 0x800BB4D0: nop

    // 0x800BB4D4: jr          $ra
    // 0x800BB4D8: nop

    return;
    // 0x800BB4D8: nop

;}
RECOMP_FUNC void func_800BB4DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB4DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BB4E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB4E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BB4E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BB4EC: jal         0x800BB24C
    // 0x800BB4F0: nop

    func_800BB24C(rdram, ctx);
        goto after_0;
    // 0x800BB4F0: nop

    after_0:
    // 0x800BB4F4: b           L_800BB4FC
    // 0x800BB4F8: nop

        goto L_800BB4FC;
    // 0x800BB4F8: nop

L_800BB4FC:
    // 0x800BB4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BB500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BB504: jr          $ra
    // 0x800BB508: nop

    return;
    // 0x800BB508: nop

;}
RECOMP_FUNC void AudioDriver_SetSeqVolume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB50C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB510: sw          $a0, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r4;
    // 0x800BB514: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB518: sw          $a0, -0x17B4($at)
    MEM_W(-0X17B4, ctx->r1) = ctx->r4;
    // 0x800BB51C: jr          $ra
    // 0x800BB520: nop

    return;
    // 0x800BB520: nop

    // 0x800BB524: jr          $ra
    // 0x800BB528: nop

    return;
    // 0x800BB528: nop

;}
RECOMP_FUNC void AudioDriver_ConfigSeqPlayerVolume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB52C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800BB530: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BB534: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800BB538: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800BB53C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BB540: beq         $a0, $at, L_800BB550
    if (ctx->r4 == ctx->r1) {
        // 0x800BB544: nop

            goto L_800BB550;
    }
    // 0x800BB544: nop

    // 0x800BB548: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB54C: sw          $a0, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r4;
L_800BB550:
    // 0x800BB550: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB554: sw          $a1, -0x17B8($at)
    MEM_W(-0X17B8, ctx->r1) = ctx->r5;
    // 0x800BB558: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB55C: sw          $a2, -0x17B4($at)
    MEM_W(-0X17B4, ctx->r1) = ctx->r6;
    // 0x800BB560: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BB564: sw          $a3, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = ctx->r7;
    // 0x800BB568: jr          $ra
    // 0x800BB56C: nop

    return;
    // 0x800BB56C: nop

    // 0x800BB570: jr          $ra
    // 0x800BB574: nop

    return;
    // 0x800BB574: nop

;}
RECOMP_FUNC void func_800BB578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB578: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800BB57C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800BB580: lw          $t7, -0x7304($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7304);
    // 0x800BB584: lw          $t6, -0x7310($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7310);
    // 0x800BB588: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800BB58C: lw          $t9, -0x730C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X730C);
    // 0x800BB590: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800BB594: jr          $ra
    // 0x800BB598: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    return;
    // 0x800BB598: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    // 0x800BB59C: jr          $ra
    // 0x800BB5A0: nop

    return;
    // 0x800BB5A0: nop

    // 0x800BB5A4: jr          $ra
    // 0x800BB5A8: nop

    return;
    // 0x800BB5A8: nop

;}
RECOMP_FUNC void AudioDriver_DepthToCents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB5AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BB5B0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800BB5B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BB5B8: lwc1        $f4, -0x23C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X23C);
    // 0x800BB5BC: nop

    // 0x800BB5C0: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800BB5C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB5C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BB5CC: nop

    // 0x800BB5D0: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x800BB5D4: beq         $a0, $zero, L_800BB624
    if (ctx->r4 == 0) {
        // 0x800BB5D8: nop

            goto L_800BB624;
    }
    // 0x800BB5D8: nop

L_800BB5DC:
    // 0x800BB5DC: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800BB5E0: beq         $t6, $zero, L_800BB5FC
    if (ctx->r14 == 0) {
        // 0x800BB5E4: nop

            goto L_800BB5FC;
    }
    // 0x800BB5E4: nop

    // 0x800BB5E8: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800BB5EC: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800BB5F0: nop

    // 0x800BB5F4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BB5F8: swc1        $f16, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f16.u32l;
L_800BB5FC:
    // 0x800BB5FC: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800BB600: nop

    // 0x800BB604: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800BB608: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800BB60C: srl         $t7, $a0, 1
    ctx->r15 = S32(U32(ctx->r4) >> 1);
    // 0x800BB610: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800BB614: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800BB618: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800BB61C: bne         $a0, $zero, L_800BB5DC
    if (ctx->r4 != 0) {
        // 0x800BB620: nop

            goto L_800BB5DC;
    }
    // 0x800BB620: nop

L_800BB624:
    // 0x800BB624: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800BB628: b           L_800BB638
    // 0x800BB62C: nop

        goto L_800BB638;
    // 0x800BB62C: nop

    // 0x800BB630: b           L_800BB638
    // 0x800BB634: nop

        goto L_800BB638;
    // 0x800BB634: nop

L_800BB638:
    // 0x800BB638: jr          $ra
    // 0x800BB63C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BB63C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
