#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80072654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007265C: jal         0x80061488
    // 0x80072660: addiu       $a0, $zero, 0x519
    ctx->r4 = ADD32(0, 0X519);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072660: addiu       $a0, $zero, 0x519
    ctx->r4 = ADD32(0, 0X519);
    after_0:
    // 0x80072664: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80072668: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007266C: b           L_8007267C
    // 0x80072670: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007267C;
    // 0x80072670: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072674: b           L_8007267C
    // 0x80072678: nop

        goto L_8007267C;
    // 0x80072678: nop

L_8007267C:
    // 0x8007267C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072684: jr          $ra
    // 0x80072688: nop

    return;
    // 0x80072688: nop

;}
RECOMP_FUNC void func_80062BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062BB0: jal         0x8005F064
    // 0x80062BB4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062BB4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80062BB8: b           L_80062BC8
    // 0x80062BBC: nop

        goto L_80062BC8;
    // 0x80062BBC: nop

    // 0x80062BC0: b           L_80062BC8
    // 0x80062BC4: nop

        goto L_80062BC8;
    // 0x80062BC4: nop

L_80062BC8:
    // 0x80062BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062BD0: jr          $ra
    // 0x80062BD4: nop

    return;
    // 0x80062BD4: nop

;}
RECOMP_FUNC void func_80062FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062FB8: jal         0x8005F064
    // 0x80062FBC: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062FBC: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x80062FC0: b           L_80062FD0
    // 0x80062FC4: nop

        goto L_80062FD0;
    // 0x80062FC4: nop

    // 0x80062FC8: b           L_80062FD0
    // 0x80062FCC: nop

        goto L_80062FD0;
    // 0x80062FCC: nop

L_80062FD0:
    // 0x80062FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062FD8: jr          $ra
    // 0x80062FDC: nop

    return;
    // 0x80062FDC: nop

;}
RECOMP_FUNC void func_8001AD98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AD98: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8001AD9C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8001ADA0: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x8001ADA4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001ADA8: sh          $a1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r5;
    // 0x8001ADAC: jr          $ra
    // 0x8001ADB0: nop

    return;
    // 0x8001ADB0: nop

    // 0x8001ADB4: jr          $ra
    // 0x8001ADB8: nop

    return;
    // 0x8001ADB8: nop

;}
RECOMP_FUNC void func_800B4448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B444C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4450: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B4454: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B4458: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B445C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B4460: nop

    // 0x800B4464: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800B4468: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x800B446C: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x800B4470: nop

    // 0x800B4474: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B4478: bne         $at, $zero, L_800B4488
    if (ctx->r1 != 0) {
        // 0x800B447C: nop
    
            goto L_800B4488;
    }
    // 0x800B447C: nop

    // 0x800B4480: b           L_800B4670
    // 0x800B4484: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B4670;
    // 0x800B4484: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B4488:
    // 0x800B4488: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B448C: nop

    // 0x800B4490: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x800B4494: lbu         $t1, 0x30($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X30);
    // 0x800B4498: lbu         $t3, 0x10($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X10);
    // 0x800B449C: nop

    // 0x800B44A0: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B44A4: beq         $at, $zero, L_800B4554
    if (ctx->r1 == 0) {
        // 0x800B44A8: nop
    
            goto L_800B4554;
    }
    // 0x800B44A8: nop

L_800B44AC:
    // 0x800B44AC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B44B0: nop

    // 0x800B44B4: lbu         $t6, 0x30($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X30);
    // 0x800B44B8: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800B44BC: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800B44C0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800B44C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B44C8: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800B44CC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800B44D0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B44D4: nop

    // 0x800B44D8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800B44DC: nop

    // 0x800B44E0: andi        $t2, $t0, 0x8000
    ctx->r10 = ctx->r8 & 0X8000;
    // 0x800B44E4: bne         $t2, $zero, L_800B44F4
    if (ctx->r10 != 0) {
        // 0x800B44E8: nop
    
            goto L_800B44F4;
    }
    // 0x800B44E8: nop

    // 0x800B44EC: b           L_800B4518
    // 0x800B44F0: nop

        goto L_800B4518;
    // 0x800B44F0: nop

L_800B44F4:
    // 0x800B44F4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B44F8: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x800B44FC: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x800B4500: nop

    // 0x800B4504: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x800B4508: bne         $t4, $t6, L_800B4518
    if (ctx->r12 != ctx->r14) {
        // 0x800B450C: nop
    
            goto L_800B4518;
    }
    // 0x800B450C: nop

    // 0x800B4510: b           L_800B4554
    // 0x800B4514: nop

        goto L_800B4554;
    // 0x800B4514: nop

L_800B4518:
    // 0x800B4518: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B451C: nop

    // 0x800B4520: lbu         $t8, 0x30($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X30);
    // 0x800B4524: nop

    // 0x800B4528: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800B452C: sb          $t7, 0x30($t5)
    MEM_B(0X30, ctx->r13) = ctx->r15;
    // 0x800B4530: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B4534: nop

    // 0x800B4538: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x800B453C: lbu         $t0, 0x30($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X30);
    // 0x800B4540: lbu         $t1, 0x10($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X10);
    // 0x800B4544: nop

    // 0x800B4548: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B454C: bne         $at, $zero, L_800B44AC
    if (ctx->r1 != 0) {
        // 0x800B4550: nop
    
            goto L_800B44AC;
    }
    // 0x800B4550: nop

L_800B4554:
    // 0x800B4554: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B4558: nop

    // 0x800B455C: lbu         $t4, 0x30($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X30);
    // 0x800B4560: nop

    // 0x800B4564: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800B4568: sb          $t6, 0x30($t3)
    MEM_B(0X30, ctx->r11) = ctx->r14;
    // 0x800B456C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B4570: nop

    // 0x800B4574: lw          $t5, 0x8($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X8);
    // 0x800B4578: lbu         $t7, 0x30($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X30);
    // 0x800B457C: lbu         $t9, 0x10($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X10);
    // 0x800B4580: nop

    // 0x800B4584: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B4588: bne         $at, $zero, L_800B464C
    if (ctx->r1 != 0) {
        // 0x800B458C: nop
    
            goto L_800B464C;
    }
    // 0x800B458C: nop

    // 0x800B4590: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B4594: nop

    // 0x800B4598: lw          $t0, 0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8);
    // 0x800B459C: nop

    // 0x800B45A0: lbu         $t1, 0x10($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X10);
    // 0x800B45A4: nop

    // 0x800B45A8: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x800B45AC: sb          $t4, 0x30($t2)
    MEM_B(0X30, ctx->r10) = ctx->r12;
    // 0x800B45B0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B45B4: nop

    // 0x800B45B8: lbu         $t3, 0x30($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X30);
    // 0x800B45BC: nop

    // 0x800B45C0: blez        $t3, L_800B4644
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B45C4: nop
    
            goto L_800B4644;
    }
    // 0x800B45C4: nop

L_800B45C8:
    // 0x800B45C8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B45CC: nop

    // 0x800B45D0: lbu         $t7, 0x30($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X30);
    // 0x800B45D4: lw          $t5, 0xC($t8)
    ctx->r13 = MEM_W(ctx->r24, 0XC);
    // 0x800B45D8: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800B45DC: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B45E0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800B45E4: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x800B45E8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B45EC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B45F0: nop

    // 0x800B45F4: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x800B45F8: nop

    // 0x800B45FC: andi        $t2, $t4, 0x8000
    ctx->r10 = ctx->r12 & 0X8000;
    // 0x800B4600: beq         $t2, $zero, L_800B4624
    if (ctx->r10 == 0) {
        // 0x800B4604: nop
    
            goto L_800B4624;
    }
    // 0x800B4604: nop

    // 0x800B4608: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B460C: nop

    // 0x800B4610: lbu         $t3, 0x30($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X30);
    // 0x800B4614: nop

    // 0x800B4618: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x800B461C: b           L_800B462C
    // 0x800B4620: sb          $t8, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r24;
        goto L_800B462C;
    // 0x800B4620: sb          $t8, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r24;
L_800B4624:
    // 0x800B4624: b           L_800B4644
    // 0x800B4628: nop

        goto L_800B4644;
    // 0x800B4628: nop

L_800B462C:
    // 0x800B462C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B4630: nop

    // 0x800B4634: lbu         $t5, 0x30($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X30);
    // 0x800B4638: nop

    // 0x800B463C: bgtz        $t5, L_800B45C8
    if (SIGNED(ctx->r13) > 0) {
        // 0x800B4640: nop
    
            goto L_800B45C8;
    }
    // 0x800B4640: nop

L_800B4644:
    // 0x800B4644: b           L_800B4670
    // 0x800B4648: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B4670;
    // 0x800B4648: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B464C:
    // 0x800B464C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B4650: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4654: lhu         $a2, 0x12($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X12);
    // 0x800B4658: jal         0x800B47A0
    // 0x800B465C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_800B47A0(rdram, ctx);
        goto after_0;
    // 0x800B465C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_0:
    // 0x800B4660: b           L_800B4670
    // 0x800B4664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B4670;
    // 0x800B4664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4668: b           L_800B4670
    // 0x800B466C: nop

        goto L_800B4670;
    // 0x800B466C: nop

L_800B4670:
    // 0x800B4670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4678: jr          $ra
    // 0x800B467C: nop

    return;
    // 0x800B467C: nop

;}
RECOMP_FUNC void MtxUtil_TranslateLocal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2304: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C2308: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x800C230C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2310: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C2314: nop

    // 0x800C2318: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x800C231C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800C2320: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800C2324: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800C2328: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C232C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C2330: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x800C2334: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C2338: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C233C: lwc1        $f18, 0x20($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X20);
    // 0x800C2340: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C2344: nop

    // 0x800C2348: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C234C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C2350: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C2354: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800C2358: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800C235C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x800C2360: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800C2364: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800C2368: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C236C: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800C2370: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C2374: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C2378: lwc1        $f18, 0x24($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X24);
    // 0x800C237C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C2380: nop

    // 0x800C2384: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C2388: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800C238C: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800C2390: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800C2394: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C2398: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
    // 0x800C239C: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800C23A0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C23A4: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800C23A8: lwc1        $f8, 0x18($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X18);
    // 0x800C23AC: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C23B0: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C23B4: lwc1        $f18, 0x28($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X28);
    // 0x800C23B8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C23BC: nop

    // 0x800C23C0: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C23C4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C23C8: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800C23CC: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800C23D0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800C23D4: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
    // 0x800C23D8: b           L_800C23E0
    // 0x800C23DC: nop

        goto L_800C23E0;
    // 0x800C23DC: nop

L_800C23E0:
    // 0x800C23E0: jr          $ra
    // 0x800C23E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C23E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B2CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2CBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B2CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2CC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B2CC8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B2CCC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B2CD0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B2CD4: nop

    // 0x800B2CD8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B2CDC: nop

    // 0x800B2CE0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B2CE4: nop

    // 0x800B2CE8: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x800B2CEC: nop

    // 0x800B2CF0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800B2CF4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B2CF8: nop

    // 0x800B2CFC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B2D00: nop

    // 0x800B2D04: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800B2D08: nop

    // 0x800B2D0C: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800B2D10: beq         $t3, $zero, L_800B2D40
    if (ctx->r11 == 0) {
        // 0x800B2D14: nop
    
            goto L_800B2D40;
    }
    // 0x800B2D14: nop

    // 0x800B2D18: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B2D1C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2D20: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B2D24: nop

    // 0x800B2D28: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B2D2C: nop

    // 0x800B2D30: lbu         $t8, 0xF($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF);
    // 0x800B2D34: nop

    // 0x800B2D38: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800B2D3C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_800B2D40:
    // 0x800B2D40: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2D44: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B2D48: blez        $t0, L_800B2E00
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B2D4C: nop
    
            goto L_800B2E00;
    }
    // 0x800B2D4C: nop

L_800B2D50:
    // 0x800B2D50: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B2D54: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B2D58: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800B2D5C: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x800B2D60: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800B2D64: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B2D68: nop

    // 0x800B2D6C: andi        $t4, $t7, 0x400
    ctx->r12 = ctx->r15 & 0X400;
    // 0x800B2D70: beq         $t4, $zero, L_800B2D80
    if (ctx->r12 == 0) {
        // 0x800B2D74: nop
    
            goto L_800B2D80;
    }
    // 0x800B2D74: nop

    // 0x800B2D78: b           L_800B2DE8
    // 0x800B2D7C: nop

        goto L_800B2DE8;
    // 0x800B2D7C: nop

L_800B2D80:
    // 0x800B2D80: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B2D84: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B2D88: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B2D8C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B2D90: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B2D94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B2D98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B2D9C: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x800B2DA0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B2DA4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800B2DA8: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x800B2DAC: sll         $t5, $t0, 6
    ctx->r13 = S32(ctx->r8 << 6);
    // 0x800B2DB0: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x800B2DB4: jal         0x800B2FB0
    // 0x800B2DB8: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    func_800B2FB0(rdram, ctx);
        goto after_0;
    // 0x800B2DB8: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    after_0:
    // 0x800B2DBC: beq         $v0, $zero, L_800B2DE8
    if (ctx->r2 == 0) {
        // 0x800B2DC0: nop
    
            goto L_800B2DE8;
    }
    // 0x800B2DC0: nop

    // 0x800B2DC4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B2DC8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B2DCC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B2DD0: sll         $t8, $t4, 6
    ctx->r24 = S32(ctx->r12 << 6);
    // 0x800B2DD4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B2DD8: lhu         $t1, 0x3A($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X3A);
    // 0x800B2DDC: nop

    // 0x800B2DE0: ori         $t3, $t1, 0x400
    ctx->r11 = ctx->r9 | 0X400;
    // 0x800B2DE4: sh          $t3, 0x3A($t9)
    MEM_H(0X3A, ctx->r25) = ctx->r11;
L_800B2DE8:
    // 0x800B2DE8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B2DEC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2DF0: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800B2DF4: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B2DF8: bne         $at, $zero, L_800B2D50
    if (ctx->r1 != 0) {
        // 0x800B2DFC: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_800B2D50;
    }
    // 0x800B2DFC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800B2E00:
    // 0x800B2E00: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2E04: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B2E08: blez        $t6, L_800B2E58
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B2E0C: nop
    
            goto L_800B2E58;
    }
    // 0x800B2E0C: nop

L_800B2E10:
    // 0x800B2E10: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B2E14: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B2E18: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800B2E1C: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x800B2E20: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800B2E24: lhu         $t9, 0x3A($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B2E28: nop

    // 0x800B2E2C: andi        $t0, $t9, 0x400
    ctx->r8 = ctx->r25 & 0X400;
    // 0x800B2E30: bne         $t0, $zero, L_800B2E40
    if (ctx->r8 != 0) {
        // 0x800B2E34: nop
    
            goto L_800B2E40;
    }
    // 0x800B2E34: nop

    // 0x800B2E38: b           L_800B2E58
    // 0x800B2E3C: nop

        goto L_800B2E58;
    // 0x800B2E3C: nop

L_800B2E40:
    // 0x800B2E40: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800B2E44: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2E48: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x800B2E4C: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B2E50: bne         $at, $zero, L_800B2E10
    if (ctx->r1 != 0) {
        // 0x800B2E54: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_800B2E10;
    }
    // 0x800B2E54: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
L_800B2E58:
    // 0x800B2E58: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B2E5C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2E60: nop

    // 0x800B2E64: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B2E68: bne         $at, $zero, L_800B2E78
    if (ctx->r1 != 0) {
        // 0x800B2E6C: nop
    
            goto L_800B2E78;
    }
    // 0x800B2E6C: nop

    // 0x800B2E70: b           L_800B2FA0
    // 0x800B2E74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2FA0;
    // 0x800B2E74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B2E78:
    // 0x800B2E78: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B2E7C: nop

    // 0x800B2E80: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x800B2E84: nop

    // 0x800B2E88: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x800B2E8C: nop

    // 0x800B2E90: andi        $t9, $t3, 0x4
    ctx->r25 = ctx->r11 & 0X4;
    // 0x800B2E94: beq         $t9, $zero, L_800B2F08
    if (ctx->r25 == 0) {
        // 0x800B2E98: nop
    
            goto L_800B2F08;
    }
    // 0x800B2E98: nop

    // 0x800B2E9C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B2EA0: nop

    // 0x800B2EA4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B2EA8: nop

    // 0x800B2EAC: lhu         $t5, 0x3A($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X3A);
    // 0x800B2EB0: nop

    // 0x800B2EB4: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x800B2EB8: beq         $t6, $zero, L_800B2F08
    if (ctx->r14 == 0) {
        // 0x800B2EBC: nop
    
            goto L_800B2F08;
    }
    // 0x800B2EBC: nop

    // 0x800B2EC0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B2EC4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B2EC8: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800B2ECC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B2ED0: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x800B2ED4: nop

    // 0x800B2ED8: lbu         $t1, 0xE($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0XE);
    // 0x800B2EDC: nop

    // 0x800B2EE0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800B2EE4: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800B2EE8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B2EEC: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800B2EF0: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800B2EF4: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x800B2EF8: lw          $t5, 0xC0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC0);
    // 0x800B2EFC: nop

    // 0x800B2F00: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x800B2F04: sw          $t6, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r14;
L_800B2F08:
    // 0x800B2F08: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2F0C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B2F10: blez        $t4, L_800B2F8C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B2F14: nop
    
            goto L_800B2F8C;
    }
    // 0x800B2F14: nop

L_800B2F18:
    // 0x800B2F18: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B2F1C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800B2F20: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800B2F24: sll         $t9, $t1, 6
    ctx->r25 = S32(ctx->r9 << 6);
    // 0x800B2F28: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x800B2F2C: lhu         $t0, 0x3A($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B2F30: nop

    // 0x800B2F34: andi        $t5, $t0, 0x400
    ctx->r13 = ctx->r8 & 0X400;
    // 0x800B2F38: beq         $t5, $zero, L_800B2F74
    if (ctx->r13 == 0) {
        // 0x800B2F3C: nop
    
            goto L_800B2F74;
    }
    // 0x800B2F3C: nop

    // 0x800B2F40: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B2F44: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B2F48: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800B2F4C: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x800B2F50: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2F54: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x800B2F58: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x800B2F5C: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800B2F60: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800B2F64: lw          $t7, 0xC0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XC0);
    // 0x800B2F68: nop

    // 0x800B2F6C: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x800B2F70: sw          $t9, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r25;
L_800B2F74:
    // 0x800B2F74: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B2F78: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2F7C: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x800B2F80: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B2F84: bne         $at, $zero, L_800B2F18
    if (ctx->r1 != 0) {
        // 0x800B2F88: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_800B2F18;
    }
    // 0x800B2F88: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800B2F8C:
    // 0x800B2F8C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2F90: b           L_800B2FA0
    // 0x800B2F94: nop

        goto L_800B2FA0;
    // 0x800B2F94: nop

    // 0x800B2F98: b           L_800B2FA0
    // 0x800B2F9C: nop

        goto L_800B2FA0;
    // 0x800B2F9C: nop

L_800B2FA0:
    // 0x800B2FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2FA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B2FA8: jr          $ra
    // 0x800B2FAC: nop

    return;
    // 0x800B2FAC: nop

;}
RECOMP_FUNC void func_800543B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800543B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800543B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800543B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800543BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800543C0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800543C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800543C8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800543CC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800543D0: bne         $t0, $zero, L_800543E0
    if (ctx->r8 != 0) {
        // 0x800543D4: andi        $t1, $t9, 0x80
        ctx->r9 = ctx->r25 & 0X80;
            goto L_800543E0;
    }
    // 0x800543D4: andi        $t1, $t9, 0x80
    ctx->r9 = ctx->r25 & 0X80;
    // 0x800543D8: beq         $t1, $zero, L_80054600
    if (ctx->r9 == 0) {
        // 0x800543DC: nop
    
            goto L_80054600;
    }
    // 0x800543DC: nop

L_800543E0:
    // 0x800543E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800543E4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800543E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800543EC: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x800543F0: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x800543F4: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x800543F8: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800543FC: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80054400: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80054404: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80054408: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005440C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80054410: nop

    // 0x80054414: lw          $t8, 0x94($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X94);
    // 0x80054418: lw          $t9, 0x90($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X90);
    // 0x8005441C: nop

    // 0x80054420: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80054424: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80054428: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005442C: nop

    // 0x80054430: sltiu       $at, $t1, 0x65
    ctx->r1 = ctx->r9 < 0X65 ? 1 : 0;
    // 0x80054434: bne         $at, $zero, L_80054444
    if (ctx->r1 != 0) {
        // 0x80054438: nop
    
            goto L_80054444;
    }
    // 0x80054438: nop

    // 0x8005443C: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80054440: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_80054444:
    // 0x80054444: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80054448: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005444C: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80054450: mflo        $t4
    ctx->r12 = lo;
    // 0x80054454: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80054458: nop

    // 0x8005445C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054460: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x80054464: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80054468: lh          $t7, 0xC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XC);
    // 0x8005446C: nop

    // 0x80054470: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80054474: sh          $t8, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r24;
    // 0x80054478: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005447C: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80054480: nop

    // 0x80054484: lh          $t0, 0xC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XC);
    // 0x80054488: nop

    // 0x8005448C: slti        $at, $t0, 0x3E8
    ctx->r1 = SIGNED(ctx->r8) < 0X3E8 ? 1 : 0;
    // 0x80054490: bne         $at, $zero, L_800544A8
    if (ctx->r1 != 0) {
        // 0x80054494: nop
    
            goto L_800544A8;
    }
    // 0x80054494: nop

    // 0x80054498: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005449C: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x800544A0: addiu       $t1, $zero, 0x3E7
    ctx->r9 = ADD32(0, 0X3E7);
    // 0x800544A4: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
L_800544A8:
    // 0x800544A8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800544AC: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x800544B0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800544B4: lh          $t4, 0xE($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XE);
    // 0x800544B8: nop

    // 0x800544BC: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800544C0: sh          $t6, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r14;
    // 0x800544C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800544C8: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x800544CC: nop

    // 0x800544D0: lh          $t5, 0xE($t8)
    ctx->r13 = MEM_H(ctx->r24, 0XE);
    // 0x800544D4: nop

    // 0x800544D8: slti        $at, $t5, 0x3E8
    ctx->r1 = SIGNED(ctx->r13) < 0X3E8 ? 1 : 0;
    // 0x800544DC: bne         $at, $zero, L_800544F4
    if (ctx->r1 != 0) {
        // 0x800544E0: nop
    
            goto L_800544F4;
    }
    // 0x800544E0: nop

    // 0x800544E4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800544E8: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x800544EC: addiu       $t9, $zero, 0x3E7
    ctx->r25 = ADD32(0, 0X3E7);
    // 0x800544F0: sh          $t9, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r25;
L_800544F4:
    // 0x800544F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800544F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800544FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80054500: jal         0x80052508
    // 0x80054504: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    func_80052508(rdram, ctx);
        goto after_0;
    // 0x80054504: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_0:
    // 0x80054508: jal         0x8005A578
    // 0x8005450C: nop

    func_8005A578(rdram, ctx);
        goto after_1;
    // 0x8005450C: nop

    after_1:
    // 0x80054510: beq         $v0, $zero, L_80054584
    if (ctx->r2 == 0) {
        // 0x80054514: nop
    
            goto L_80054584;
    }
    // 0x80054514: nop

    // 0x80054518: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005451C: lw          $t1, 0x480($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X480);
    // 0x80054520: nop

    // 0x80054524: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80054528: nop

    // 0x8005452C: bne         $t2, $zero, L_80054584
    if (ctx->r10 != 0) {
        // 0x80054530: nop
    
            goto L_80054584;
    }
    // 0x80054530: nop

    // 0x80054534: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054538: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8005453C: nop

    // 0x80054540: lh          $t7, 0xC($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XC);
    // 0x80054544: lh          $t6, 0x50($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X50);
    // 0x80054548: nop

    // 0x8005454C: subu        $t3, $t7, $t6
    ctx->r11 = SUB32(ctx->r15, ctx->r14);
    // 0x80054550: slti        $at, $t3, 0xFA
    ctx->r1 = SIGNED(ctx->r11) < 0XFA ? 1 : 0;
    // 0x80054554: bne         $at, $zero, L_80054584
    if (ctx->r1 != 0) {
        // 0x80054558: nop
    
            goto L_80054584;
    }
    // 0x80054558: nop

    // 0x8005455C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054560: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80054564: nop

    // 0x80054568: lh          $t5, 0xC($t8)
    ctx->r13 = MEM_H(ctx->r24, 0XC);
    // 0x8005456C: nop

    // 0x80054570: sh          $t5, 0x50($t8)
    MEM_H(0X50, ctx->r24) = ctx->r13;
    // 0x80054574: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80054578: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x8005457C: addiu       $t9, $zero, 0x75A
    ctx->r25 = ADD32(0, 0X75A);
    // 0x80054580: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_80054584:
    // 0x80054584: jal         0x8005A578
    // 0x80054588: nop

    func_8005A578(rdram, ctx);
        goto after_2;
    // 0x80054588: nop

    after_2:
    // 0x8005458C: beq         $v0, $zero, L_80054600
    if (ctx->r2 == 0) {
        // 0x80054590: nop
    
            goto L_80054600;
    }
    // 0x80054590: nop

    // 0x80054594: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80054598: lw          $t1, 0x480($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X480);
    // 0x8005459C: nop

    // 0x800545A0: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x800545A4: nop

    // 0x800545A8: bne         $t2, $zero, L_80054600
    if (ctx->r10 != 0) {
        // 0x800545AC: nop
    
            goto L_80054600;
    }
    // 0x800545AC: nop

    // 0x800545B0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800545B4: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x800545B8: nop

    // 0x800545BC: lh          $t7, 0xE($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XE);
    // 0x800545C0: lh          $t6, 0x52($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X52);
    // 0x800545C4: nop

    // 0x800545C8: subu        $t3, $t7, $t6
    ctx->r11 = SUB32(ctx->r15, ctx->r14);
    // 0x800545CC: slti        $at, $t3, 0xFA
    ctx->r1 = SIGNED(ctx->r11) < 0XFA ? 1 : 0;
    // 0x800545D0: bne         $at, $zero, L_80054600
    if (ctx->r1 != 0) {
        // 0x800545D4: nop
    
            goto L_80054600;
    }
    // 0x800545D4: nop

    // 0x800545D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800545DC: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800545E0: nop

    // 0x800545E4: lh          $t8, 0xE($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XE);
    // 0x800545E8: nop

    // 0x800545EC: sh          $t8, 0x52($t5)
    MEM_H(0X52, ctx->r13) = ctx->r24;
    // 0x800545F0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800545F4: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x800545F8: addiu       $t9, $zero, 0x75B
    ctx->r25 = ADD32(0, 0X75B);
    // 0x800545FC: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_80054600:
    // 0x80054600: b           L_80054608
    // 0x80054604: nop

        goto L_80054608;
    // 0x80054604: nop

L_80054608:
    // 0x80054608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005460C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80054610: jr          $ra
    // 0x80054614: nop

    return;
    // 0x80054614: nop

;}
RECOMP_FUNC void func_800883F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800883FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088400: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80088404: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80088408: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008840C: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x80088410: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80088414: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x80088418: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008841C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80088420: nop

    // 0x80088424: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80088428: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x8008842C: nop

    // 0x80088430: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80088434: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80088438: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008843C: nop

    // 0x80088440: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80088444: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80088448: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008844C: nop

    // 0x80088450: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80088454: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80088458: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008845C: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x80088460: nop

    // 0x80088464: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80088468: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008846C: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x80088470: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80088474: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x80088478: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008847C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80088480: nop

    // 0x80088484: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80088488: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x8008848C: nop

    // 0x80088490: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80088494: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80088498: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8008849C: nop

    // 0x800884A0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800884A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800884A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800884AC: nop

    // 0x800884B0: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800884B4: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800884B8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800884BC: sh          $t3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r11;
    // 0x800884C0: nop

    // 0x800884C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800884C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800884CC: addiu       $a0, $a0, -0x611C
    ctx->r4 = ADD32(ctx->r4, -0X611C);
    // 0x800884D0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800884D4: jal         0x8008BE0C
    // 0x800884D8: addiu       $a1, $a1, 0x15
    ctx->r5 = ADD32(ctx->r5, 0X15);
    func_8008BE0C(rdram, ctx);
        goto after_0;
    // 0x800884D8: addiu       $a1, $a1, 0x15
    ctx->r5 = ADD32(ctx->r5, 0X15);
    after_0:
    // 0x800884DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800884E0: jal         0x80089170
    // 0x800884E4: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x800884E4: nop

    after_1:
    // 0x800884E8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800884EC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800884F0: jal         0x800898D8
    // 0x800884F4: addiu       $a2, $zero, 0x4007
    ctx->r6 = ADD32(0, 0X4007);
    func_800898D8(rdram, ctx);
        goto after_2;
    // 0x800884F4: addiu       $a2, $zero, 0x4007
    ctx->r6 = ADD32(0, 0X4007);
    after_2:
    // 0x800884F8: beq         $v0, $zero, L_80088548
    if (ctx->r2 == 0) {
        // 0x800884FC: nop
    
            goto L_80088548;
    }
    // 0x800884FC: nop

    // 0x80088500: lh          $t4, 0x1A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1A);
    // 0x80088504: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x80088508: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x8008850C: lh          $t8, 0x20($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X20);
    // 0x80088510: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80088514: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x80088518: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008851C: bgez        $a1, L_8008852C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80088520: sra         $t6, $a1, 1
        ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8008852C;
    }
    // 0x80088520: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80088524: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80088528: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8008852C:
    // 0x8008852C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80088530: bgez        $a2, L_80088540
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80088534: sra         $t9, $a2, 1
        ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80088540;
    }
    // 0x80088534: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80088538: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x8008853C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80088540:
    // 0x80088540: jal         0x80089B04
    // 0x80088544: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_80089B04(rdram, ctx);
        goto after_3;
    // 0x80088544: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_3:
L_80088548:
    // 0x80088548: b           L_80088558
    // 0x8008854C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_80088558;
    // 0x8008854C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x80088550: b           L_80088558
    // 0x80088554: nop

        goto L_80088558;
    // 0x80088554: nop

L_80088558:
    // 0x80088558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008855C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80088560: jr          $ra
    // 0x80088564: nop

    return;
    // 0x80088564: nop

;}
RECOMP_FUNC void func_80070440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070448: jal         0x80061348
    // 0x8007044C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007044C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070450: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070454: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070458: beq         $v0, $zero, L_800704A8
    if (ctx->r2 == 0) {
        // 0x8007045C: nop
    
            goto L_800704A8;
    }
    // 0x8007045C: nop

    // 0x80070460: jal         0x80061348
    // 0x80070464: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070464: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070468: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007046C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070470: beq         $v0, $zero, L_800704A8
    if (ctx->r2 == 0) {
        // 0x80070474: nop
    
            goto L_800704A8;
    }
    // 0x80070474: nop

    // 0x80070478: jal         0x80061348
    // 0x8007047C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007047C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070480: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070484: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070488: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007048C: beq         $v0, $zero, L_800704A8
    if (ctx->r2 == 0) {
        // 0x80070490: nop
    
            goto L_800704A8;
    }
    // 0x80070490: nop

    // 0x80070494: jal         0x80061348
    // 0x80070498: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070498: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x8007049C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800704A0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800704A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800704A8:
    // 0x800704A8: b           L_800704B8
    // 0x800704AC: nop

        goto L_800704B8;
    // 0x800704AC: nop

    // 0x800704B0: b           L_800704B8
    // 0x800704B4: nop

        goto L_800704B8;
    // 0x800704B4: nop

L_800704B8:
    // 0x800704B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800704BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800704C0: jr          $ra
    // 0x800704C4: nop

    return;
    // 0x800704C4: nop

;}
RECOMP_FUNC void func_80064670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064678: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006467C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064680: nop

    // 0x80064684: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064688: nop

    // 0x8006468C: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80064690: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064694: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064698: beq         $v0, $zero, L_800646B0
    if (ctx->r2 == 0) {
        // 0x8006469C: nop
    
            goto L_800646B0;
    }
    // 0x8006469C: nop

    // 0x800646A0: jal         0x8005F064
    // 0x800646A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800646A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x800646A8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800646AC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800646B0:
    // 0x800646B0: b           L_800646C0
    // 0x800646B4: nop

        goto L_800646C0;
    // 0x800646B4: nop

    // 0x800646B8: b           L_800646C0
    // 0x800646BC: nop

        goto L_800646C0;
    // 0x800646BC: nop

L_800646C0:
    // 0x800646C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800646C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800646C8: jr          $ra
    // 0x800646CC: nop

    return;
    // 0x800646CC: nop

;}
RECOMP_FUNC void func_8006F3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F3A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F3AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F3B0: nop

    // 0x8006F3B4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F3B8: nop

    // 0x8006F3BC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006F3C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F3C4: jr          $ra
    // 0x8006F3C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F3C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F3CC: jr          $ra
    // 0x8006F3D0: nop

    return;
    // 0x8006F3D0: nop

    // 0x8006F3D4: jr          $ra
    // 0x8006F3D8: nop

    return;
    // 0x8006F3D8: nop

;}
RECOMP_FUNC void func_800507AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800507AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800507B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800507B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800507B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800507BC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800507C0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800507C4: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x800507C8: addiu       $at, $zero, 0xCF
    ctx->r1 = ADD32(0, 0XCF);
    // 0x800507CC: bne         $t6, $at, L_800507E4
    if (ctx->r14 != ctx->r1) {
        // 0x800507D0: nop
    
            goto L_800507E4;
    }
    // 0x800507D0: nop

    // 0x800507D4: jal         0x800B9000
    // 0x800507D8: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x800507D8: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_0:
    // 0x800507DC: jal         0x800B9000
    // 0x800507E0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x800507E0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
L_800507E4:
    // 0x800507E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800507E8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800507EC: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x800507F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800507F4: lh          $a1, 0x42($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X42);
    // 0x800507F8: jal         0x8004EF90
    // 0x800507FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_2;
    // 0x800507FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80050800: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050804: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80050808: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005080C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80050810: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80050814: bne         $t2, $zero, L_80050910
    if (ctx->r10 != 0) {
        // 0x80050818: andi        $t3, $t1, 0x2
        ctx->r11 = ctx->r9 & 0X2;
            goto L_80050910;
    }
    // 0x80050818: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x8005081C: bne         $t3, $zero, L_80050910
    if (ctx->r11 != 0) {
        // 0x80050820: nop
    
            goto L_80050910;
    }
    // 0x80050820: nop

L_80050824:
    // 0x80050824: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80050828: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005082C: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x80050830: lh          $t4, 0x4A($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X4A);
    // 0x80050834: nop

    // 0x80050838: andi        $t5, $t4, 0x1FFF
    ctx->r13 = ctx->r12 & 0X1FFF;
    // 0x8005083C: bne         $t5, $at, L_800508E0
    if (ctx->r13 != ctx->r1) {
        // 0x80050840: nop
    
            goto L_800508E0;
    }
    // 0x80050840: nop

    // 0x80050844: lw          $t6, 0x50($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X50);
    // 0x80050848: nop

    // 0x8005084C: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x80050850: nop

    // 0x80050854: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80050858: beq         $at, $zero, L_800508E0
    if (ctx->r1 == 0) {
        // 0x8005085C: nop
    
            goto L_800508E0;
    }
    // 0x8005085C: nop

    // 0x80050860: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050864: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80050868: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005086C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80050870: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80050874: bne         $t2, $zero, L_80050884
    if (ctx->r10 != 0) {
        // 0x80050878: andi        $t3, $t1, 0x8
        ctx->r11 = ctx->r9 & 0X8;
            goto L_80050884;
    }
    // 0x80050878: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x8005087C: beq         $t3, $zero, L_80050898
    if (ctx->r11 == 0) {
        // 0x80050880: nop
    
            goto L_80050898;
    }
    // 0x80050880: nop

L_80050884:
    // 0x80050884: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80050888: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8005088C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80050890: b           L_800508A8
    // 0x80050894: nop

        goto L_800508A8;
    // 0x80050894: nop

L_80050898:
    // 0x80050898: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8005089C: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800508A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800508A4: nop

L_800508A8:
    // 0x800508A8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800508AC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800508B0: nop

    // 0x800508B4: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800508B8: nop

    // 0x800508BC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800508C0: add.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = ctx->f6.d + ctx->f20.d;
    // 0x800508C4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800508C8: swc1        $f10, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f10.u32l;
    // 0x800508CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800508D0: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x800508D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800508D8: jal         0x8005D07C
    // 0x800508DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8005D07C(rdram, ctx);
        goto after_3;
    // 0x800508DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
L_800508E0:
    // 0x800508E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800508E4: jal         0x800499B0
    // 0x800508E8: nop

    func_800499B0(rdram, ctx);
        goto after_4;
    // 0x800508E8: nop

    after_4:
    // 0x800508EC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800508F0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800508F4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800508F8: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x800508FC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80050900: bne         $t8, $zero, L_80050910
    if (ctx->r24 != 0) {
        // 0x80050904: andi        $t9, $t7, 0x2
        ctx->r25 = ctx->r15 & 0X2;
            goto L_80050910;
    }
    // 0x80050904: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x80050908: beq         $t9, $zero, L_80050824
    if (ctx->r25 == 0) {
        // 0x8005090C: nop
    
            goto L_80050824;
    }
    // 0x8005090C: nop

L_80050910:
    // 0x80050910: b           L_80050918
    // 0x80050914: nop

        goto L_80050918;
    // 0x80050914: nop

L_80050918:
    // 0x80050918: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005091C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80050920: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80050924: jr          $ra
    // 0x80050928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80050928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80098CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098CB0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098CB4: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098CB8: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80098CBC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80098CC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098CC4: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098CC8: jr          $ra
    // 0x80098CCC: nop

    return;
    // 0x80098CCC: nop

    // 0x80098CD0: jr          $ra
    // 0x80098CD4: nop

    return;
    // 0x80098CD4: nop

;}
RECOMP_FUNC void func_8008C6E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C6E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008C6E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008C6E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008C6EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C6F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008C6F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C6F8: addiu       $a0, $a0, -0x6110
    ctx->r4 = ADD32(ctx->r4, -0X6110);
    // 0x8008C6FC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8008C700: jal         0x8008BE0C
    // 0x8008C704: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    func_8008BE0C(rdram, ctx);
        goto after_0;
    // 0x8008C704: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_0:
    // 0x8008C708: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008C70C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C710: addiu       $a0, $a0, -0x611C
    ctx->r4 = ADD32(ctx->r4, -0X611C);
    // 0x8008C714: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8008C718: jal         0x8008BE0C
    // 0x8008C71C: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    func_8008BE0C(rdram, ctx);
        goto after_1;
    // 0x8008C71C: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    after_1:
    // 0x8008C720: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008C724: nop

    // 0x8008C728: lhu         $s0, 0x10($t6)
    ctx->r16 = MEM_HU(ctx->r14, 0X10);
    // 0x8008C72C: nop

    // 0x8008C730: beq         $s0, $zero, L_8008C758
    if (ctx->r16 == 0) {
        // 0x8008C734: nop
    
            goto L_8008C758;
    }
    // 0x8008C734: nop

    // 0x8008C738: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C73C: beq         $s0, $at, L_8008C76C
    if (ctx->r16 == ctx->r1) {
        // 0x8008C740: nop
    
            goto L_8008C76C;
    }
    // 0x8008C740: nop

    // 0x8008C744: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008C748: beq         $s0, $at, L_8008C780
    if (ctx->r16 == ctx->r1) {
        // 0x8008C74C: nop
    
            goto L_8008C780;
    }
    // 0x8008C74C: nop

    // 0x8008C750: b           L_8008C78C
    // 0x8008C754: nop

        goto L_8008C78C;
    // 0x8008C754: nop

L_8008C758:
    // 0x8008C758: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8008C75C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008C760: sh          $t7, -0x44C8($at)
    MEM_H(-0X44C8, ctx->r1) = ctx->r15;
    // 0x8008C764: b           L_8008C78C
    // 0x8008C768: nop

        goto L_8008C78C;
    // 0x8008C768: nop

L_8008C76C:
    // 0x8008C76C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8008C770: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008C774: sh          $t8, -0x44C8($at)
    MEM_H(-0X44C8, ctx->r1) = ctx->r24;
    // 0x8008C778: b           L_8008C78C
    // 0x8008C77C: nop

        goto L_8008C78C;
    // 0x8008C77C: nop

L_8008C780:
    // 0x8008C780: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8008C784: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008C788: sh          $t9, -0x44C8($at)
    MEM_H(-0X44C8, ctx->r1) = ctx->r25;
L_8008C78C:
    // 0x8008C78C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008C790: nop

    // 0x8008C794: lhu         $s0, 0x12($t0)
    ctx->r16 = MEM_HU(ctx->r8, 0X12);
    // 0x8008C798: nop

    // 0x8008C79C: beq         $s0, $zero, L_8008C7B8
    if (ctx->r16 == 0) {
        // 0x8008C7A0: nop
    
            goto L_8008C7B8;
    }
    // 0x8008C7A0: nop

    // 0x8008C7A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C7A8: beq         $s0, $at, L_8008C7C8
    if (ctx->r16 == ctx->r1) {
        // 0x8008C7AC: nop
    
            goto L_8008C7C8;
    }
    // 0x8008C7AC: nop

    // 0x8008C7B0: b           L_8008C7D4
    // 0x8008C7B4: nop

        goto L_8008C7D4;
    // 0x8008C7B4: nop

L_8008C7B8:
    // 0x8008C7B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C7BC: sw          $zero, 0x465C($at)
    MEM_W(0X465C, ctx->r1) = 0;
    // 0x8008C7C0: b           L_8008C7D4
    // 0x8008C7C4: nop

        goto L_8008C7D4;
    // 0x8008C7C4: nop

L_8008C7C8:
    // 0x8008C7C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008C7CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C7D0: sw          $t1, 0x465C($at)
    MEM_W(0X465C, ctx->r1) = ctx->r9;
L_8008C7D4:
    // 0x8008C7D4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008C7D8: nop

    // 0x8008C7DC: lhu         $s0, 0x14($t2)
    ctx->r16 = MEM_HU(ctx->r10, 0X14);
    // 0x8008C7E0: nop

    // 0x8008C7E4: beq         $s0, $zero, L_8008C80C
    if (ctx->r16 == 0) {
        // 0x8008C7E8: nop
    
            goto L_8008C80C;
    }
    // 0x8008C7E8: nop

    // 0x8008C7EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C7F0: beq         $s0, $at, L_8008C820
    if (ctx->r16 == ctx->r1) {
        // 0x8008C7F4: nop
    
            goto L_8008C820;
    }
    // 0x8008C7F4: nop

    // 0x8008C7F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008C7FC: beq         $s0, $at, L_8008C830
    if (ctx->r16 == ctx->r1) {
        // 0x8008C800: nop
    
            goto L_8008C830;
    }
    // 0x8008C800: nop

    // 0x8008C804: b           L_8008C83C
    // 0x8008C808: nop

        goto L_8008C83C;
    // 0x8008C808: nop

L_8008C80C:
    // 0x8008C80C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008C810: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008C814: sb          $t3, 0x127D($at)
    MEM_B(0X127D, ctx->r1) = ctx->r11;
    // 0x8008C818: b           L_8008C83C
    // 0x8008C81C: nop

        goto L_8008C83C;
    // 0x8008C81C: nop

L_8008C820:
    // 0x8008C820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008C824: sb          $zero, 0x127D($at)
    MEM_B(0X127D, ctx->r1) = 0;
    // 0x8008C828: b           L_8008C83C
    // 0x8008C82C: nop

        goto L_8008C83C;
    // 0x8008C82C: nop

L_8008C830:
    // 0x8008C830: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8008C834: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008C838: sb          $t4, 0x127D($at)
    MEM_B(0X127D, ctx->r1) = ctx->r12;
L_8008C83C:
    // 0x8008C83C: b           L_8008C844
    // 0x8008C840: nop

        goto L_8008C844;
    // 0x8008C840: nop

L_8008C844:
    // 0x8008C844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C848: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C84C: jr          $ra
    // 0x8008C850: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008C850: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80012164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012164: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80012168: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001216C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80012170: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80012174: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80012178: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8001217C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80012180: jal         0x8000DA44
    // 0x80012184: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012184: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x80012188: bgez        $v0, L_80012198
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001218C: nop
    
            goto L_80012198;
    }
    // 0x8001218C: nop

    // 0x80012190: b           L_80012398
    // 0x80012194: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012398;
    // 0x80012194: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012198:
    // 0x80012198: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8001219C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800121A0: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800121A4: nop

    // 0x800121A8: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800121AC: bne         $at, $zero, L_800121CC
    if (ctx->r1 != 0) {
        // 0x800121B0: nop
    
            goto L_800121CC;
    }
    // 0x800121B0: nop

    // 0x800121B4: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x800121B8: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800121BC: beq         $at, $zero, L_800121CC
    if (ctx->r1 == 0) {
        // 0x800121C0: nop
    
            goto L_800121CC;
    }
    // 0x800121C0: nop

    // 0x800121C4: b           L_80012398
    // 0x800121C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012398;
    // 0x800121C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800121CC:
    // 0x800121CC: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800121D0: nop

    // 0x800121D4: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x800121D8: nop

    // 0x800121DC: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x800121E0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800121E4: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800121E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800121EC: lhu         $t1, 0x60($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X60);
    // 0x800121F0: nop

    // 0x800121F4: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x800121F8: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x800121FC: bne         $t3, $at, L_80012210
    if (ctx->r11 != ctx->r1) {
        // 0x80012200: nop
    
            goto L_80012210;
    }
    // 0x80012200: nop

    // 0x80012204: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80012208: b           L_80012260
    // 0x8001220C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_80012260;
    // 0x8001220C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80012210:
    // 0x80012210: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80012214: nop

    // 0x80012218: lhu         $t6, 0x60($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X60);
    // 0x8001221C: nop

    // 0x80012220: andi        $t7, $t6, 0x60
    ctx->r15 = ctx->r14 & 0X60;
    // 0x80012224: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x80012228: bne         $t8, $zero, L_80012238
    if (ctx->r24 != 0) {
        // 0x8001222C: nop
    
            goto L_80012238;
    }
    // 0x8001222C: nop

    // 0x80012230: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80012234: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80012238:
    // 0x80012238: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8001223C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012240: lhu         $t1, 0x60($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X60);
    // 0x80012244: nop

    // 0x80012248: andi        $t2, $t1, 0x60
    ctx->r10 = ctx->r9 & 0X60;
    // 0x8001224C: sra         $t3, $t2, 5
    ctx->r11 = S32(SIGNED(ctx->r10) >> 5);
    // 0x80012250: bne         $t3, $at, L_80012260
    if (ctx->r11 != ctx->r1) {
        // 0x80012254: nop
    
            goto L_80012260;
    }
    // 0x80012254: nop

    // 0x80012258: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001225C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80012260:
    // 0x80012260: addiu       $t5, $sp, 0x4C
    ctx->r13 = ADD32(ctx->r29, 0X4C);
    // 0x80012264: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x80012268: nop

    // 0x8001226C: bne         $t6, $zero, L_800122CC
    if (ctx->r14 != 0) {
        // 0x80012270: nop
    
            goto L_800122CC;
    }
    // 0x80012270: nop

    // 0x80012274: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x80012278: nop

    // 0x8001227C: bne         $t7, $zero, L_800122CC
    if (ctx->r15 != 0) {
        // 0x80012280: nop
    
            goto L_800122CC;
    }
    // 0x80012280: nop

    // 0x80012284: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80012288: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001228C: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x80012290: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80012294: lwc1        $f6, 0xCC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x80012298: lwc1        $f4, 0xCC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8001229C: nop

    // 0x800122A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800122A4: swc1        $f8, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f8.u32l;
    // 0x800122A8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800122AC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800122B0: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x800122B4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800122B8: lwc1        $f16, 0xD0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x800122BC: lwc1        $f10, 0xD0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x800122C0: nop

    // 0x800122C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800122C8: swc1        $f18, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f18.u32l;
L_800122CC:
    // 0x800122CC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800122D0: nop

    // 0x800122D4: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x800122D8: nop

    // 0x800122DC: lw          $t5, 0xC8($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC8);
    // 0x800122E0: nop

    // 0x800122E4: sw          $t5, 0x94($t4)
    MEM_W(0X94, ctx->r12) = ctx->r13;
    // 0x800122E8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800122EC: nop

    // 0x800122F0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x800122F4: nop

    // 0x800122F8: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x800122FC: nop

    // 0x80012300: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x80012304: beq         $t9, $zero, L_80012314
    if (ctx->r25 == 0) {
        // 0x80012308: nop
    
            goto L_80012314;
    }
    // 0x80012308: nop

    // 0x8001230C: b           L_80012318
    // 0x80012310: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80012318;
    // 0x80012310: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80012314:
    // 0x80012314: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80012318:
    // 0x80012318: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8001231C: addiu       $t3, $sp, 0x4C
    ctx->r11 = ADD32(ctx->r29, 0X4C);
    // 0x80012320: lhu         $t2, 0x6($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X6);
    // 0x80012324: lhu         $a2, 0x2($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X2);
    // 0x80012328: lhu         $a3, 0x4($t3)
    ctx->r7 = MEM_HU(ctx->r11, 0X4);
    // 0x8001232C: lw          $a0, 0xC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC);
    // 0x80012330: lw          $a1, 0x10($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X10);
    // 0x80012334: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80012338: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x8001233C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80012340: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80012344: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80012348: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8001234C: lhu         $t4, 0x4($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X4);
    // 0x80012350: jal         0x80049A00
    // 0x80012354: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_80049A00(rdram, ctx);
        goto after_1;
    // 0x80012354: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_1:
    // 0x80012358: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8001235C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80012360: bne         $s0, $zero, L_80012370
    if (ctx->r16 != 0) {
        // 0x80012364: sw          $s0, 0x7C($t7)
        MEM_W(0X7C, ctx->r15) = ctx->r16;
            goto L_80012370;
    }
    // 0x80012364: sw          $s0, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r16;
    // 0x80012368: b           L_80012398
    // 0x8001236C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012398;
    // 0x8001236C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012370:
    // 0x80012370: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80012374: nop

    // 0x80012378: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x8001237C: nop

    // 0x80012380: ori         $t9, $t0, 0x1
    ctx->r25 = ctx->r8 | 0X1;
    // 0x80012384: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
    // 0x80012388: b           L_80012398
    // 0x8001238C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012398;
    // 0x8001238C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012390: b           L_80012398
    // 0x80012394: nop

        goto L_80012398;
    // 0x80012394: nop

L_80012398:
    // 0x80012398: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001239C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800123A0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800123A4: jr          $ra
    // 0x800123A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800123A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8006DA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DA90: jal         0x80061348
    // 0x8006DA94: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DA94: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006DA98: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DA9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DAA0: beq         $v0, $zero, L_8006DAD0
    if (ctx->r2 == 0) {
        // 0x8006DAA4: nop
    
            goto L_8006DAD0;
    }
    // 0x8006DAA4: nop

    // 0x8006DAA8: jal         0x80061348
    // 0x8006DAAC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DAAC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006DAB0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DAB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DAB8: beq         $v0, $zero, L_8006DAD0
    if (ctx->r2 == 0) {
        // 0x8006DABC: nop
    
            goto L_8006DAD0;
    }
    // 0x8006DABC: nop

    // 0x8006DAC0: jal         0x80061348
    // 0x8006DAC4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006DAC4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_2:
    // 0x8006DAC8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DACC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006DAD0:
    // 0x8006DAD0: b           L_8006DAE0
    // 0x8006DAD4: nop

        goto L_8006DAE0;
    // 0x8006DAD4: nop

    // 0x8006DAD8: b           L_8006DAE0
    // 0x8006DADC: nop

        goto L_8006DAE0;
    // 0x8006DADC: nop

L_8006DAE0:
    // 0x8006DAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DAE8: jr          $ra
    // 0x8006DAEC: nop

    return;
    // 0x8006DAEC: nop

;}
RECOMP_FUNC void MtxUtil_ClearRotation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C197C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1980: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800C1984: bne         $a0, $zero, L_800C199C
    if (ctx->r4 != 0) {
        // 0x800C1988: nop
    
            goto L_800C199C;
    }
    // 0x800C1988: nop

    // 0x800C198C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1990: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1994: nop

    // 0x800C1998: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
L_800C199C:
    // 0x800C199C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800C19A0: nop

    // 0x800C19A4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800C19A8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800C19AC: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_800C19B0:
    // 0x800C19B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C19B4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C19B8: nop

    // 0x800C19BC: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C19C0: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C19C4: nop

    // 0x800C19C8: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C19CC: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x800C19D0: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C19D4: nop

    // 0x800C19D8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800C19DC: bgtz        $t3, L_800C19B0
    if (SIGNED(ctx->r11) > 0) {
        // 0x800C19E0: sw          $t3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r11;
            goto L_800C19B0;
    }
    // 0x800C19E0: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800C19E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C19E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C19EC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C19F0: nop

    // 0x800C19F4: swc1        $f6, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f6.u32l;
    // 0x800C19F8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800C19FC: nop

    // 0x800C1A00: lwc1        $f12, 0x28($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X28);
    // 0x800C1A04: nop

    // 0x800C1A08: swc1        $f12, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f12.u32l;
    // 0x800C1A0C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C1A10: nop

    // 0x800C1A14: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x800C1A18: b           L_800C1A20
    // 0x800C1A1C: nop

        goto L_800C1A20;
    // 0x800C1A1C: nop

L_800C1A20:
    // 0x800C1A20: jr          $ra
    // 0x800C1A24: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1A24: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80072CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072CE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072CEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072CF0: nop

    // 0x80072CF4: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072CF8: nop

    // 0x80072CFC: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072D00: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072D04: jr          $ra
    // 0x80072D08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072D08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072D0C: jr          $ra
    // 0x80072D10: nop

    return;
    // 0x80072D10: nop

    // 0x80072D14: jr          $ra
    // 0x80072D18: nop

    return;
    // 0x80072D18: nop

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
RECOMP_FUNC void func_80039C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039C5C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80039C60: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80039C64: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80039C68: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x80039C6C: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x80039C70: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x80039C74: swc1        $f31, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80039C78: swc1        $f30, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f30.u32l;
    // 0x80039C7C: swc1        $f29, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80039C80: swc1        $f28, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f28.u32l;
    // 0x80039C84: swc1        $f27, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80039C88: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x80039C8C: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80039C90: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x80039C94: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80039C98: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x80039C9C: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80039CA0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80039CA4: sh          $zero, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = 0;
    // 0x80039CA8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80039CAC: lw          $t6, 0x7298($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7298);
    // 0x80039CB0: nop

    // 0x80039CB4: lhu         $t7, 0xAE0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XAE0);
    // 0x80039CB8: nop

    // 0x80039CBC: beq         $t7, $zero, L_80039F28
    if (ctx->r15 == 0) {
        // 0x80039CC0: nop
    
            goto L_80039F28;
    }
    // 0x80039CC0: nop

    // 0x80039CC4: sh          $zero, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = 0;
L_80039CC8:
    // 0x80039CC8: lhu         $t9, 0x7E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X7E);
    // 0x80039CCC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80039CD0: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80039CD4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80039CD8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80039CDC: lw          $t8, 0x7298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7298);
    // 0x80039CE0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80039CE4: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80039CE8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80039CEC: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x80039CF0: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80039CF4: nop

    // 0x80039CF8: lhu         $t3, 0xC($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XC);
    // 0x80039CFC: nop

    // 0x80039D00: beq         $t3, $zero, L_80039F0C
    if (ctx->r11 == 0) {
        // 0x80039D04: nop
    
            goto L_80039F0C;
    }
    // 0x80039D04: nop

    // 0x80039D08: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80039D0C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80039D10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80039D14: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80039D18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80039D1C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80039D20: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80039D24: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80039D28: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80039D2C: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80039D30: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80039D34: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80039D38: jal         0x800C3C80
    // 0x80039D3C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_0;
    // 0x80039D3C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80039D40: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80039D44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039D48: nop

    // 0x80039D4C: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80039D50: nop

    // 0x80039D54: bc1t        L_80039F0C
    if (c1cs) {
        // 0x80039D58: nop
    
            goto L_80039F0C;
    }
    // 0x80039D58: nop

    // 0x80039D5C: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80039D60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039D64: nop

    // 0x80039D68: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80039D6C: nop

    // 0x80039D70: bc1f        L_80039D80
    if (!c1cs) {
        // 0x80039D74: nop
    
            goto L_80039D80;
    }
    // 0x80039D74: nop

    // 0x80039D78: b           L_80039D8C
    // 0x80039D7C: mov.s       $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    ctx->f24.fl = ctx->f18.fl;
        goto L_80039D8C;
    // 0x80039D7C: mov.s       $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    ctx->f24.fl = ctx->f18.fl;
L_80039D80:
    // 0x80039D80: lwc1        $f24, 0x84($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80039D84: nop

    // 0x80039D88: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
L_80039D8C:
    // 0x80039D8C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80039D90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039D94: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80039D98: nop

    // 0x80039D9C: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80039DA0: nop

    // 0x80039DA4: bc1f        L_80039DB4
    if (!c1cs) {
        // 0x80039DA8: nop
    
            goto L_80039DB4;
    }
    // 0x80039DA8: nop

    // 0x80039DAC: b           L_80039DC8
    // 0x80039DB0: mov.s       $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = ctx->f6.fl;
        goto L_80039DC8;
    // 0x80039DB0: mov.s       $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = ctx->f6.fl;
L_80039DB4:
    // 0x80039DB4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80039DB8: nop

    // 0x80039DBC: lwc1        $f22, 0x4($t5)
    ctx->f22.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80039DC0: nop

    // 0x80039DC4: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
L_80039DC8:
    // 0x80039DC8: sub.s       $f10, $f24, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f22.fl;
    // 0x80039DCC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80039DD0: nop

    // 0x80039DD4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80039DD8: nop

    // 0x80039DDC: bc1f        L_80039E58
    if (!c1cs) {
        // 0x80039DE0: nop
    
            goto L_80039E58;
    }
    // 0x80039DE0: nop

    // 0x80039DE4: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80039DE8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039DEC: nop

    // 0x80039DF0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80039DF4: nop

    // 0x80039DF8: bc1f        L_80039E08
    if (!c1cs) {
        // 0x80039DFC: nop
    
            goto L_80039E08;
    }
    // 0x80039DFC: nop

    // 0x80039E00: b           L_80039E14
    // 0x80039E04: mov.s       $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    ctx->f28.fl = ctx->f4.fl;
        goto L_80039E14;
    // 0x80039E04: mov.s       $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    ctx->f28.fl = ctx->f4.fl;
L_80039E08:
    // 0x80039E08: lwc1        $f28, 0x84($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80039E0C: nop

    // 0x80039E10: neg.s       $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f28.fl = -ctx->f28.fl;
L_80039E14:
    // 0x80039E14: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80039E18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80039E1C: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80039E20: nop

    // 0x80039E24: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80039E28: nop

    // 0x80039E2C: bc1f        L_80039E3C
    if (!c1cs) {
        // 0x80039E30: nop
    
            goto L_80039E3C;
    }
    // 0x80039E30: nop

    // 0x80039E34: b           L_80039E50
    // 0x80039E38: mov.s       $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    ctx->f26.fl = ctx->f8.fl;
        goto L_80039E50;
    // 0x80039E38: mov.s       $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    ctx->f26.fl = ctx->f8.fl;
L_80039E3C:
    // 0x80039E3C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80039E40: nop

    // 0x80039E44: lwc1        $f26, 0x4($t7)
    ctx->f26.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80039E48: nop

    // 0x80039E4C: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = -ctx->f26.fl;
L_80039E50:
    // 0x80039E50: b           L_80039ED8
    // 0x80039E54: sub.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f26.fl;
        goto L_80039ED8;
    // 0x80039E54: sub.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f26.fl;
L_80039E58:
    // 0x80039E58: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80039E5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80039E60: nop

    // 0x80039E64: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80039E68: nop

    // 0x80039E6C: bc1f        L_80039E7C
    if (!c1cs) {
        // 0x80039E70: nop
    
            goto L_80039E7C;
    }
    // 0x80039E70: nop

    // 0x80039E74: b           L_80039E8C
    // 0x80039E78: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
        goto L_80039E8C;
    // 0x80039E78: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_80039E7C:
    // 0x80039E7C: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80039E80: nop

    // 0x80039E84: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80039E88: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
L_80039E8C:
    // 0x80039E8C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80039E90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039E94: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80039E98: nop

    // 0x80039E9C: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80039EA0: nop

    // 0x80039EA4: bc1f        L_80039EB4
    if (!c1cs) {
        // 0x80039EA8: nop
    
            goto L_80039EB4;
    }
    // 0x80039EA8: nop

    // 0x80039EAC: b           L_80039EC8
    // 0x80039EB0: mov.s       $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = ctx->f6.fl;
        goto L_80039EC8;
    // 0x80039EB0: mov.s       $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = ctx->f6.fl;
L_80039EB4:
    // 0x80039EB4: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80039EB8: nop

    // 0x80039EBC: lwc1        $f30, 0x4($t8)
    ctx->f30.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80039EC0: nop

    // 0x80039EC4: neg.s       $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = -ctx->f30.fl;
L_80039EC8:
    // 0x80039EC8: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80039ECC: nop

    // 0x80039ED0: sub.s       $f20, $f16, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f30.fl;
    // 0x80039ED4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80039ED8:
    // 0x80039ED8: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80039EDC: nop

    // 0x80039EE0: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x80039EE4: nop

    // 0x80039EE8: bc1f        L_80039F0C
    if (!c1cs) {
        // 0x80039EEC: nop
    
            goto L_80039F0C;
    }
    // 0x80039EEC: nop

    // 0x80039EF0: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80039EF4: nop

    // 0x80039EF8: sh          $zero, 0xC($t0)
    MEM_H(0XC, ctx->r8) = 0;
    // 0x80039EFC: lhu         $t1, 0x7C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X7C);
    // 0x80039F00: nop

    // 0x80039F04: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80039F08: sh          $t3, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r11;
L_80039F0C:
    // 0x80039F0C: lhu         $t2, 0x7E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X7E);
    // 0x80039F10: nop

    // 0x80039F14: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80039F18: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80039F1C: slti        $at, $t5, 0x6
    ctx->r1 = SIGNED(ctx->r13) < 0X6 ? 1 : 0;
    // 0x80039F20: bne         $at, $zero, L_80039CC8
    if (ctx->r1 != 0) {
        // 0x80039F24: sh          $t4, 0x7E($sp)
        MEM_H(0X7E, ctx->r29) = ctx->r12;
            goto L_80039CC8;
    }
    // 0x80039F24: sh          $t4, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r12;
L_80039F28:
    // 0x80039F28: lhu         $v0, 0x7C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X7C);
    // 0x80039F2C: b           L_80039F3C
    // 0x80039F30: nop

        goto L_80039F3C;
    // 0x80039F30: nop

    // 0x80039F34: b           L_80039F3C
    // 0x80039F38: nop

        goto L_80039F3C;
    // 0x80039F38: nop

L_80039F3C:
    // 0x80039F3C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80039F40: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80039F44: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80039F48: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80039F4C: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80039F50: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80039F54: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80039F58: lwc1        $f27, 0x38($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80039F5C: lwc1        $f26, 0x3C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80039F60: lwc1        $f29, 0x40($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80039F64: lwc1        $f28, 0x44($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80039F68: lwc1        $f31, 0x48($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x80039F6C: lwc1        $f30, 0x4C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80039F70: jr          $ra
    // 0x80039F74: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80039F74: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8001EDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EDC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EDC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001EDCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001EDD0: jal         0x800BDA58
    // 0x8001EDD4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800BDA58(rdram, ctx);
        goto after_0;
    // 0x8001EDD4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x8001EDD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001EDDC: lw          $t6, 0x168C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X168C);
    // 0x8001EDE0: nop

    // 0x8001EDE4: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8001EDE8: beq         $t7, $zero, L_8001EE04
    if (ctx->r15 == 0) {
        // 0x8001EDEC: nop
    
            goto L_8001EE04;
    }
    // 0x8001EDEC: nop

    // 0x8001EDF0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EDF4: jal         0x8008ECE4
    // 0x8001EDF8: addiu       $a0, $a0, -0x24CC
    ctx->r4 = ADD32(ctx->r4, -0X24CC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001EDF8: addiu       $a0, $a0, -0x24CC
    ctx->r4 = ADD32(ctx->r4, -0X24CC);
    after_1:
    // 0x8001EDFC: b           L_8001EE10
    // 0x8001EE00: nop

        goto L_8001EE10;
    // 0x8001EE00: nop

L_8001EE04:
    // 0x8001EE04: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EE08: jal         0x8008ECE4
    // 0x8001EE0C: addiu       $a0, $a0, -0x24C4
    ctx->r4 = ADD32(ctx->r4, -0X24C4);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001EE0C: addiu       $a0, $a0, -0x24C4
    ctx->r4 = ADD32(ctx->r4, -0X24C4);
    after_2:
L_8001EE10:
    // 0x8001EE10: b           L_8001EE20
    // 0x8001EE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EE20;
    // 0x8001EE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EE18: b           L_8001EE20
    // 0x8001EE1C: nop

        goto L_8001EE20;
    // 0x8001EE1C: nop

L_8001EE20:
    // 0x8001EE20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EE24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EE28: jr          $ra
    // 0x8001EE2C: nop

    return;
    // 0x8001EE2C: nop

;}
RECOMP_FUNC void func_800666A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800666A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800666AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800666B0: jal         0x80061348
    // 0x800666B4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800666B4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x800666B8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800666BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800666C0: bne         $v0, $zero, L_80066708
    if (ctx->r2 != 0) {
        // 0x800666C4: nop
    
            goto L_80066708;
    }
    // 0x800666C4: nop

    // 0x800666C8: jal         0x80061348
    // 0x800666CC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800666CC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_1:
    // 0x800666D0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800666D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800666D8: bne         $v0, $zero, L_80066708
    if (ctx->r2 != 0) {
        // 0x800666DC: nop
    
            goto L_80066708;
    }
    // 0x800666DC: nop

    // 0x800666E0: jal         0x80061348
    // 0x800666E4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800666E4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_2:
    // 0x800666E8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800666EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800666F0: bne         $v0, $zero, L_80066708
    if (ctx->r2 != 0) {
        // 0x800666F4: nop
    
            goto L_80066708;
    }
    // 0x800666F4: nop

    // 0x800666F8: jal         0x80061348
    // 0x800666FC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800666FC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_3:
    // 0x80066700: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066704: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80066708:
    // 0x80066708: b           L_80066718
    // 0x8006670C: nop

        goto L_80066718;
    // 0x8006670C: nop

    // 0x80066710: b           L_80066718
    // 0x80066714: nop

        goto L_80066718;
    // 0x80066714: nop

L_80066718:
    // 0x80066718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006671C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066720: jr          $ra
    // 0x80066724: nop

    return;
    // 0x80066724: nop

;}
RECOMP_FUNC void func_80031AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031AB8: jr          $ra
    // 0x80031ABC: nop

    return;
    // 0x80031ABC: nop

    // 0x80031AC0: jr          $ra
    // 0x80031AC4: nop

    return;
    // 0x80031AC4: nop

;}
RECOMP_FUNC void __osClearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5ED8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C5EDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C5EE0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C5EE4: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800C5EE8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800C5EEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5EF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C5EF4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C5EF8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800C5EFC: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800C5F00: jal         0x800CE34C
    // 0x800C5F04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800C5F04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800C5F08: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C5F0C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C5F10: beq         $t8, $zero, L_800C5F20
    if (ctx->r24 == 0) {
        // 0x800C5F14: nop
    
            goto L_800C5F20;
    }
    // 0x800C5F14: nop

    // 0x800C5F18: b           L_800C5F88
    // 0x800C5F1C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800C5F88;
    // 0x800C5F1C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C5F20:
    // 0x800C5F20: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800C5F24:
    // 0x800C5F24: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F28: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5F2C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800C5F30: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800C5F34: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800C5F38: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C5F3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C5F40: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800C5F44: jal         0x800CE580
    // 0x800C5F48: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_1;
    // 0x800C5F48: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800C5F4C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C5F50: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C5F54: bne         $t3, $zero, L_800C5F70
    if (ctx->r11 != 0) {
        // 0x800C5F58: nop
    
            goto L_800C5F70;
    }
    // 0x800C5F58: nop

    // 0x800C5F5C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800C5F60: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C5F64: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x800C5F68: bne         $at, $zero, L_800C5F24
    if (ctx->r1 != 0) {
        // 0x800C5F6C: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800C5F24;
    }
    // 0x800C5F6C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800C5F70:
    // 0x800C5F70: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F74: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x800C5F78: jal         0x800CE34C
    // 0x800C5F7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800C5F7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800C5F80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C5F84: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_800C5F88:
    // 0x800C5F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C5F90: jr          $ra
    // 0x800C5F94: nop

    return;
    // 0x800C5F94: nop

;}
RECOMP_FUNC void func_80068544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068544: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068548: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006854C: nop

    // 0x80068550: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068554: nop

    // 0x80068558: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006855C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068560: jr          $ra
    // 0x80068564: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068564: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068568: jr          $ra
    // 0x8006856C: nop

    return;
    // 0x8006856C: nop

    // 0x80068570: jr          $ra
    // 0x80068574: nop

    return;
    // 0x80068574: nop

;}
RECOMP_FUNC void func_80071F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071F30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071F34: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071F38: nop

    // 0x80071F3C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80071F40: nop

    // 0x80071F44: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071F48: jr          $ra
    // 0x80071F4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071F4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071F50: jr          $ra
    // 0x80071F54: nop

    return;
    // 0x80071F54: nop

    // 0x80071F58: jr          $ra
    // 0x80071F5C: nop

    return;
    // 0x80071F5C: nop

;}
RECOMP_FUNC void func_80062D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062D1C: jal         0x80061488
    // 0x80062D20: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062D20: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    after_0:
    // 0x80062D24: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062D28: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062D2C: b           L_80062D3C
    // 0x80062D30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062D3C;
    // 0x80062D30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062D34: b           L_80062D3C
    // 0x80062D38: nop

        goto L_80062D3C;
    // 0x80062D38: nop

L_80062D3C:
    // 0x80062D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062D44: jr          $ra
    // 0x80062D48: nop

    return;
    // 0x80062D48: nop

;}
RECOMP_FUNC void func_800B3590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3590: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B3594: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x800B3598: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800B359C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B35A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B35A4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B35A8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B35AC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800B35B0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800B35B4: nop

    // 0x800B35B8: lhu         $v0, 0xA($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XA);
    // 0x800B35BC: b           L_800B35CC
    // 0x800B35C0: nop

        goto L_800B35CC;
    // 0x800B35C0: nop

    // 0x800B35C4: b           L_800B35CC
    // 0x800B35C8: nop

        goto L_800B35CC;
    // 0x800B35C8: nop

L_800B35CC:
    // 0x800B35CC: jr          $ra
    // 0x800B35D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B35D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800651F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800651F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800651F8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800651FC: nop

    // 0x80065200: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80065204: nop

    // 0x80065208: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006520C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065210: jr          $ra
    // 0x80065214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065218: jr          $ra
    // 0x8006521C: nop

    return;
    // 0x8006521C: nop

    // 0x80065220: jr          $ra
    // 0x80065224: nop

    return;
    // 0x80065224: nop

;}
RECOMP_FUNC void func_800A6670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6670: bne         $a0, $zero, L_800A6684
    if (ctx->r4 != 0) {
        // 0x800A6674: nop
    
            goto L_800A6684;
    }
    // 0x800A6674: nop

    // 0x800A6678: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A667C: b           L_800A66D4
    // 0x800A6680: sw          $a1, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r5;
        goto L_800A66D4;
    // 0x800A6680: sw          $a1, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r5;
L_800A6684:
    // 0x800A6684: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A6688: bne         $a0, $at, L_800A669C
    if (ctx->r4 != ctx->r1) {
        // 0x800A668C: nop
    
            goto L_800A669C;
    }
    // 0x800A668C: nop

    // 0x800A6690: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A6694: b           L_800A66D4
    // 0x800A6698: sw          $a1, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r5;
        goto L_800A66D4;
    // 0x800A6698: sw          $a1, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r5;
L_800A669C:
    // 0x800A669C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A66A0: bne         $a0, $at, L_800A66B4
    if (ctx->r4 != ctx->r1) {
        // 0x800A66A4: nop
    
            goto L_800A66B4;
    }
    // 0x800A66A4: nop

    // 0x800A66A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A66AC: b           L_800A66D4
    // 0x800A66B0: sw          $a1, -0x73D0($at)
    MEM_W(-0X73D0, ctx->r1) = ctx->r5;
        goto L_800A66D4;
    // 0x800A66B0: sw          $a1, -0x73D0($at)
    MEM_W(-0X73D0, ctx->r1) = ctx->r5;
L_800A66B4:
    // 0x800A66B4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800A66B8: bne         $a0, $at, L_800A66CC
    if (ctx->r4 != ctx->r1) {
        // 0x800A66BC: nop
    
            goto L_800A66CC;
    }
    // 0x800A66BC: nop

    // 0x800A66C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A66C4: b           L_800A66D4
    // 0x800A66C8: sw          $a1, -0x73C4($at)
    MEM_W(-0X73C4, ctx->r1) = ctx->r5;
        goto L_800A66D4;
    // 0x800A66C8: sw          $a1, -0x73C4($at)
    MEM_W(-0X73C4, ctx->r1) = ctx->r5;
L_800A66CC:
    // 0x800A66CC: jr          $ra
    // 0x800A66D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800A66D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A66D4:
    // 0x800A66D4: jr          $ra
    // 0x800A66D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A66D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80075CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075CD8: jal         0x80061488
    // 0x80075CDC: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075CDC: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    after_0:
    // 0x80075CE0: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80075CE4: b           L_80075CF4
    // 0x80075CE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075CF4;
    // 0x80075CE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075CEC: b           L_80075CF4
    // 0x80075CF0: nop

        goto L_80075CF4;
    // 0x80075CF0: nop

L_80075CF4:
    // 0x80075CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075CF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075CFC: jr          $ra
    // 0x80075D00: nop

    return;
    // 0x80075D00: nop

;}
RECOMP_FUNC void func_8006EFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EFF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EFF8: jal         0x80061348
    // 0x8006EFFC: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EFFC: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    after_0:
    // 0x8006F000: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F004: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F008: bne         $v0, $zero, L_8006F024
    if (ctx->r2 != 0) {
        // 0x8006F00C: nop
    
            goto L_8006F024;
    }
    // 0x8006F00C: nop

    // 0x8006F010: jal         0x80061348
    // 0x8006F014: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006F014: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    after_1:
    // 0x8006F018: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006F01C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006F020: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006F024:
    // 0x8006F024: b           L_8006F034
    // 0x8006F028: nop

        goto L_8006F034;
    // 0x8006F028: nop

    // 0x8006F02C: b           L_8006F034
    // 0x8006F030: nop

        goto L_8006F034;
    // 0x8006F030: nop

L_8006F034:
    // 0x8006F034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F03C: jr          $ra
    // 0x8006F040: nop

    return;
    // 0x8006F040: nop

;}
RECOMP_FUNC void func_80072378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007237C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072380: jal         0x80061488
    // 0x80072384: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072384: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    after_0:
    // 0x80072388: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8007238C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80072390: b           L_800723A0
    // 0x80072394: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800723A0;
    // 0x80072394: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072398: b           L_800723A0
    // 0x8007239C: nop

        goto L_800723A0;
    // 0x8007239C: nop

L_800723A0:
    // 0x800723A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800723A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800723A8: jr          $ra
    // 0x800723AC: nop

    return;
    // 0x800723AC: nop

;}
RECOMP_FUNC void func_80062B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062B50: jal         0x8005F064
    // 0x80062B54: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062B54: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    after_0:
    // 0x80062B58: b           L_80062B68
    // 0x80062B5C: nop

        goto L_80062B68;
    // 0x80062B5C: nop

    // 0x80062B60: b           L_80062B68
    // 0x80062B64: nop

        goto L_80062B68;
    // 0x80062B64: nop

L_80062B68:
    // 0x80062B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062B70: jr          $ra
    // 0x80062B74: nop

    return;
    // 0x80062B74: nop

;}
RECOMP_FUNC void func_800B08FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B08FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B0900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0904: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B0908: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B090C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B0910: lui         $t6, 0x80A0
    ctx->r14 = S32(0X80A0 << 16);
    // 0x800B0914: addiu       $t6, $t6, 0x4CE0
    ctx->r14 = ADD32(ctx->r14, 0X4CE0);
    // 0x800B0918: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B091C: sw          $t6, -0x478($at)
    MEM_W(-0X478, ctx->r1) = ctx->r14;
    // 0x800B0920: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B0924: addiu       $t7, $t7, 0x5B0
    ctx->r15 = ADD32(ctx->r15, 0X5B0);
    // 0x800B0928: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800B092C: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x800B0930: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800B0934: lw          $t0, -0x478($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X478);
    // 0x800B0938: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B093C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B0940: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800B0944: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800B0948: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B094C: jal         0x800BD1FC
    // 0x800B0950: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800B0950: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x800B0954: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B0958: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B095C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0960: jal         0x800BD218
    // 0x800B0964: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B0964: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800B0968: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B096C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B0970: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B0974: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800B0978: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800B097C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x800B0980: jal         0x800BD1FC
    // 0x800B0984: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B0984: nop

    after_2:
    // 0x800B0988: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B098C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B0990: jal         0x800BED70
    // 0x800B0994: nop

    Spi_GetHeader(rdram, ctx);
        goto after_3;
    // 0x800B0994: nop

    after_3:
    // 0x800B0998: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800B099C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B09A0: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x800B09A4: jal         0x800BC6EC
    // 0x800B09A8: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800B09A8: nop

    after_4:
    // 0x800B09AC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B09B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B09B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800B09B8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800B09BC: jal         0x800BF0B4
    // 0x800B09C0: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_5;
    // 0x800B09C0: nop

    after_5:
    // 0x800B09C4: lh          $t2, 0x3E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3E);
    // 0x800B09C8: nop

    // 0x800B09CC: beq         $t2, $zero, L_800B0A18
    if (ctx->r10 == 0) {
        // 0x800B09D0: nop
    
            goto L_800B0A18;
    }
    // 0x800B09D0: nop

    // 0x800B09D4: jal         0x800BC6EC
    // 0x800B09D8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x800B09D8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_6:
    // 0x800B09DC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800B09E0: lw          $t3, -0x45C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X45C);
    // 0x800B09E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B09E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B09EC: sw          $s0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r16;
    // 0x800B09F0: sw          $s0, -0x45C($at)
    MEM_W(-0X45C, ctx->r1) = ctx->r16;
    // 0x800B09F4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800B09F8: lw          $t5, -0x45C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X45C);
    // 0x800B09FC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B0A00: nop

    // 0x800B0A04: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800B0A08: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B0A0C: lw          $t6, -0x45C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X45C);
    // 0x800B0A10: nop

    // 0x800B0A14: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_800B0A18:
    // 0x800B0A18: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800B0A1C: b           L_800B0A2C
    // 0x800B0A20: nop

        goto L_800B0A2C;
    // 0x800B0A20: nop

    // 0x800B0A24: b           L_800B0A2C
    // 0x800B0A28: nop

        goto L_800B0A2C;
    // 0x800B0A28: nop

L_800B0A2C:
    // 0x800B0A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0A30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0A34: jr          $ra
    // 0x800B0A38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B0A38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80031BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031BB8: jal         0x80031AC8
    // 0x80031BBC: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x80031BBC: nop

    after_0:
    // 0x80031BC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80031BC4: bne         $v0, $at, L_80031BE4
    if (ctx->r2 != ctx->r1) {
        // 0x80031BC8: nop
    
            goto L_80031BE4;
    }
    // 0x80031BC8: nop

    // 0x80031BCC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80031BD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80031BD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031BD8: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x80031BDC: b           L_80031BF4
    // 0x80031BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031BF4;
    // 0x80031BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031BE4:
    // 0x80031BE4: b           L_80031BF4
    // 0x80031BE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80031BF4;
    // 0x80031BE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80031BEC: b           L_80031BF4
    // 0x80031BF0: nop

        goto L_80031BF4;
    // 0x80031BF0: nop

L_80031BF4:
    // 0x80031BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031BFC: jr          $ra
    // 0x80031C00: nop

    return;
    // 0x80031C00: nop

;}
RECOMP_FUNC void func_80071C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071C8C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071C90: nop

    // 0x80071C94: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80071C98: nop

    // 0x80071C9C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071CA0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80071CA4: jr          $ra
    // 0x80071CA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071CA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071CAC: jr          $ra
    // 0x80071CB0: nop

    return;
    // 0x80071CB0: nop

    // 0x80071CB4: jr          $ra
    // 0x80071CB8: nop

    return;
    // 0x80071CB8: nop

;}
RECOMP_FUNC void func_8007391C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007391C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073920: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073924: nop

    // 0x80073928: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8007392C: nop

    // 0x80073930: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073934: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073938: jr          $ra
    // 0x8007393C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007393C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073940: jr          $ra
    // 0x80073944: nop

    return;
    // 0x80073944: nop

    // 0x80073948: jr          $ra
    // 0x8007394C: nop

    return;
    // 0x8007394C: nop

;}
RECOMP_FUNC void func_8000F9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F9D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000F9D4: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x8000F9D8: nop

    // 0x8000F9DC: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8000F9E0: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8000F9E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F9E8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F9EC: lwc1        $f4, 0xA4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XA4);
    // 0x8000F9F0: lwc1        $f10, 0x6C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x8000F9F4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000F9F8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8000F9FC: swc1        $f16, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f16.u32l;
    // 0x8000FA00: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FA08: lwc1        $f18, 0xA4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XA4);
    // 0x8000FA0C: nop

    // 0x8000FA10: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8000FA14: nop

    // 0x8000FA18: bc1f        L_8000FA70
    if (!c1cs) {
        // 0x8000FA1C: nop
    
            goto L_8000FA70;
    }
    // 0x8000FA1C: nop

    // 0x8000FA20: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA24: nop

    // 0x8000FA28: lwc1        $f6, 0x98($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X98);
    // 0x8000FA2C: lwc1        $f10, 0x6C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X6C);
    // 0x8000FA30: nop

    // 0x8000FA34: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8000FA38: nop

    // 0x8000FA3C: bc1f        L_8000FA68
    if (!c1cs) {
        // 0x8000FA40: nop
    
            goto L_8000FA68;
    }
    // 0x8000FA40: nop

    // 0x8000FA44: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA48: nop

    // 0x8000FA4C: lwc1        $f8, 0x98($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X98);
    // 0x8000FA50: nop

    // 0x8000FA54: swc1        $f8, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f8.u32l;
    // 0x8000FA58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FA5C: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA60: nop

    // 0x8000FA64: swc1        $f16, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->f16.u32l;
L_8000FA68:
    // 0x8000FA68: b           L_8000FAD8
    // 0x8000FA6C: nop

        goto L_8000FAD8;
    // 0x8000FA6C: nop

L_8000FA70:
    // 0x8000FA70: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FA78: lwc1        $f18, 0xA4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XA4);
    // 0x8000FA7C: nop

    // 0x8000FA80: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8000FA84: nop

    // 0x8000FA88: bc1f        L_8000FAD8
    if (!c1cs) {
        // 0x8000FA8C: nop
    
            goto L_8000FAD8;
    }
    // 0x8000FA8C: nop

    // 0x8000FA90: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA94: nop

    // 0x8000FA98: lwc1        $f6, 0x98($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X98);
    // 0x8000FA9C: lwc1        $f10, 0x6C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X6C);
    // 0x8000FAA0: nop

    // 0x8000FAA4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8000FAA8: nop

    // 0x8000FAAC: bc1f        L_8000FAD8
    if (!c1cs) {
        // 0x8000FAB0: nop
    
            goto L_8000FAD8;
    }
    // 0x8000FAB0: nop

    // 0x8000FAB4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8000FAB8: nop

    // 0x8000FABC: lwc1        $f8, 0x98($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X98);
    // 0x8000FAC0: nop

    // 0x8000FAC4: swc1        $f8, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f8.u32l;
    // 0x8000FAC8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FACC: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8000FAD0: nop

    // 0x8000FAD4: swc1        $f16, 0xA4($t5)
    MEM_W(0XA4, ctx->r13) = ctx->f16.u32l;
L_8000FAD8:
    // 0x8000FAD8: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000FADC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FAE0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FAE4: lwc1        $f18, 0xA8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XA8);
    // 0x8000FAE8: lwc1        $f10, 0x70($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X70);
    // 0x8000FAEC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000FAF0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000FAF4: swc1        $f8, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f8.u32l;
    // 0x8000FAF8: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8000FAFC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000FB00: lwc1        $f16, 0xA8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XA8);
    // 0x8000FB04: nop

    // 0x8000FB08: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8000FB0C: nop

    // 0x8000FB10: bc1f        L_8000FB68
    if (!c1cs) {
        // 0x8000FB14: nop
    
            goto L_8000FB68;
    }
    // 0x8000FB14: nop

    // 0x8000FB18: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB1C: nop

    // 0x8000FB20: lwc1        $f4, 0x9C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X9C);
    // 0x8000FB24: lwc1        $f10, 0x70($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X70);
    // 0x8000FB28: nop

    // 0x8000FB2C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8000FB30: nop

    // 0x8000FB34: bc1f        L_8000FB60
    if (!c1cs) {
        // 0x8000FB38: nop
    
            goto L_8000FB60;
    }
    // 0x8000FB38: nop

    // 0x8000FB3C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB40: nop

    // 0x8000FB44: lwc1        $f6, 0x9C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X9C);
    // 0x8000FB48: nop

    // 0x8000FB4C: swc1        $f6, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f6.u32l;
    // 0x8000FB50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FB54: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB58: nop

    // 0x8000FB5C: swc1        $f8, 0xA8($t0)
    MEM_W(0XA8, ctx->r8) = ctx->f8.u32l;
L_8000FB60:
    // 0x8000FB60: b           L_8000FBD0
    // 0x8000FB64: nop

        goto L_8000FBD0;
    // 0x8000FB64: nop

L_8000FB68:
    // 0x8000FB68: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000FB70: lwc1        $f16, 0xA8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XA8);
    // 0x8000FB74: nop

    // 0x8000FB78: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8000FB7C: nop

    // 0x8000FB80: bc1f        L_8000FBD0
    if (!c1cs) {
        // 0x8000FB84: nop
    
            goto L_8000FBD0;
    }
    // 0x8000FB84: nop

    // 0x8000FB88: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB8C: nop

    // 0x8000FB90: lwc1        $f4, 0x9C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X9C);
    // 0x8000FB94: lwc1        $f10, 0x70($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X70);
    // 0x8000FB98: nop

    // 0x8000FB9C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8000FBA0: nop

    // 0x8000FBA4: bc1f        L_8000FBD0
    if (!c1cs) {
        // 0x8000FBA8: nop
    
            goto L_8000FBD0;
    }
    // 0x8000FBA8: nop

    // 0x8000FBAC: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8000FBB0: nop

    // 0x8000FBB4: lwc1        $f6, 0x9C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X9C);
    // 0x8000FBB8: nop

    // 0x8000FBBC: swc1        $f6, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f6.u32l;
    // 0x8000FBC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FBC4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8000FBC8: nop

    // 0x8000FBCC: swc1        $f8, 0xA8($t4)
    MEM_W(0XA8, ctx->r12) = ctx->f8.u32l;
L_8000FBD0:
    // 0x8000FBD0: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8000FBD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FBD8: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FBDC: lwc1        $f16, 0xAC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XAC);
    // 0x8000FBE0: lwc1        $f10, 0x74($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X74);
    // 0x8000FBE4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8000FBE8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000FBEC: swc1        $f6, 0x74($t5)
    MEM_W(0X74, ctx->r13) = ctx->f6.u32l;
    // 0x8000FBF0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000FBF4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FBF8: lwc1        $f8, 0xAC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XAC);
    // 0x8000FBFC: nop

    // 0x8000FC00: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8000FC04: nop

    // 0x8000FC08: bc1f        L_8000FC60
    if (!c1cs) {
        // 0x8000FC0C: nop
    
            goto L_8000FC60;
    }
    // 0x8000FC0C: nop

    // 0x8000FC10: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC14: nop

    // 0x8000FC18: lwc1        $f18, 0xA0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XA0);
    // 0x8000FC1C: lwc1        $f10, 0x74($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X74);
    // 0x8000FC20: nop

    // 0x8000FC24: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8000FC28: nop

    // 0x8000FC2C: bc1f        L_8000FC58
    if (!c1cs) {
        // 0x8000FC30: nop
    
            goto L_8000FC58;
    }
    // 0x8000FC30: nop

    // 0x8000FC34: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC38: nop

    // 0x8000FC3C: lwc1        $f4, 0xA0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XA0);
    // 0x8000FC40: nop

    // 0x8000FC44: swc1        $f4, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->f4.u32l;
    // 0x8000FC48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000FC4C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC50: nop

    // 0x8000FC54: swc1        $f6, 0xAC($t9)
    MEM_W(0XAC, ctx->r25) = ctx->f6.u32l;
L_8000FC58:
    // 0x8000FC58: b           L_8000FCC8
    // 0x8000FC5C: nop

        goto L_8000FCC8;
    // 0x8000FC5C: nop

L_8000FC60:
    // 0x8000FC60: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FC68: lwc1        $f8, 0xAC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XAC);
    // 0x8000FC6C: nop

    // 0x8000FC70: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8000FC74: nop

    // 0x8000FC78: bc1f        L_8000FCC8
    if (!c1cs) {
        // 0x8000FC7C: nop
    
            goto L_8000FCC8;
    }
    // 0x8000FC7C: nop

    // 0x8000FC80: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC84: nop

    // 0x8000FC88: lwc1        $f18, 0xA0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XA0);
    // 0x8000FC8C: lwc1        $f10, 0x74($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X74);
    // 0x8000FC90: nop

    // 0x8000FC94: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8000FC98: nop

    // 0x8000FC9C: bc1f        L_8000FCC8
    if (!c1cs) {
        // 0x8000FCA0: nop
    
            goto L_8000FCC8;
    }
    // 0x8000FCA0: nop

    // 0x8000FCA4: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8000FCA8: nop

    // 0x8000FCAC: lwc1        $f4, 0xA0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XA0);
    // 0x8000FCB0: nop

    // 0x8000FCB4: swc1        $f4, 0x74($t2)
    MEM_W(0X74, ctx->r10) = ctx->f4.u32l;
    // 0x8000FCB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000FCBC: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8000FCC0: nop

    // 0x8000FCC4: swc1        $f6, 0xAC($t3)
    MEM_W(0XAC, ctx->r11) = ctx->f6.u32l;
L_8000FCC8:
    // 0x8000FCC8: b           L_8000FCD0
    // 0x8000FCCC: nop

        goto L_8000FCD0;
    // 0x8000FCCC: nop

L_8000FCD0:
    // 0x8000FCD0: jr          $ra
    // 0x8000FCD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000FCD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_80064330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064330: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064334: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064338: nop

    // 0x8006433C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064340: nop

    // 0x80064344: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064348: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006434C: jr          $ra
    // 0x80064350: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064350: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064354: jr          $ra
    // 0x80064358: nop

    return;
    // 0x80064358: nop

    // 0x8006435C: jr          $ra
    // 0x80064360: nop

    return;
    // 0x80064360: nop

;}
RECOMP_FUNC void func_8007468C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007468C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074694: jal         0x80061348
    // 0x80074698: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074698: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x8007469C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800746A0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800746A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800746A8: beq         $v0, $zero, L_800746FC
    if (ctx->r2 == 0) {
        // 0x800746AC: nop
    
            goto L_800746FC;
    }
    // 0x800746AC: nop

    // 0x800746B0: jal         0x80061348
    // 0x800746B4: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800746B4: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x800746B8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800746BC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800746C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800746C4: beq         $v0, $zero, L_800746FC
    if (ctx->r2 == 0) {
        // 0x800746C8: nop
    
            goto L_800746FC;
    }
    // 0x800746C8: nop

    // 0x800746CC: jal         0x80061348
    // 0x800746D0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800746D0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x800746D4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800746D8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800746DC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800746E0: beq         $v0, $zero, L_800746FC
    if (ctx->r2 == 0) {
        // 0x800746E4: nop
    
            goto L_800746FC;
    }
    // 0x800746E4: nop

    // 0x800746E8: jal         0x80061348
    // 0x800746EC: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800746EC: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x800746F0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800746F4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800746F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800746FC:
    // 0x800746FC: b           L_8007470C
    // 0x80074700: nop

        goto L_8007470C;
    // 0x80074700: nop

    // 0x80074704: b           L_8007470C
    // 0x80074708: nop

        goto L_8007470C;
    // 0x80074708: nop

L_8007470C:
    // 0x8007470C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074714: jr          $ra
    // 0x80074718: nop

    return;
    // 0x80074718: nop

;}
RECOMP_FUNC void func_80071110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071118: jal         0x80061348
    // 0x8007111C: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007111C: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_0:
    // 0x80071120: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071124: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071128: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007112C: beq         $v0, $zero, L_80071180
    if (ctx->r2 == 0) {
        // 0x80071130: nop
    
            goto L_80071180;
    }
    // 0x80071130: nop

    // 0x80071134: jal         0x80061348
    // 0x80071138: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071138: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x8007113C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071140: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071148: beq         $v0, $zero, L_80071180
    if (ctx->r2 == 0) {
        // 0x8007114C: nop
    
            goto L_80071180;
    }
    // 0x8007114C: nop

    // 0x80071150: jal         0x80061348
    // 0x80071154: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071154: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80071158: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007115C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071160: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071164: beq         $v0, $zero, L_80071180
    if (ctx->r2 == 0) {
        // 0x80071168: nop
    
            goto L_80071180;
    }
    // 0x80071168: nop

    // 0x8007116C: jal         0x80061348
    // 0x80071170: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071170: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_3:
    // 0x80071174: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071178: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007117C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071180:
    // 0x80071180: b           L_80071190
    // 0x80071184: nop

        goto L_80071190;
    // 0x80071184: nop

    // 0x80071188: b           L_80071190
    // 0x8007118C: nop

        goto L_80071190;
    // 0x8007118C: nop

L_80071190:
    // 0x80071190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071198: jr          $ra
    // 0x8007119C: nop

    return;
    // 0x8007119C: nop

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
RECOMP_FUNC void func_800B7EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7EA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B7EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7EAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B7EB0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B7EB4:
    // 0x800B7EB4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B7EB8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7EBC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7EC0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7EC4: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7EC8: sh          $t7, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r15;
    // 0x800B7ECC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B7ED0: nop

    // 0x800B7ED4: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7ED8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B7EDC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7EE0: nop

    // 0x800B7EE4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7EE8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800B7EEC: bne         $at, $zero, L_800B7EB4
    if (ctx->r1 != 0) {
        // 0x800B7EF0: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B7EB4;
    }
    // 0x800B7EF0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B7EF4: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800B7EF8: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7EFC: jal         0x80029C8C
    // 0x800B7F00: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    func_80029C8C(rdram, ctx);
        goto after_0;
    // 0x800B7F00: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    after_0:
    // 0x800B7F04: jal         0x80029ED8
    // 0x800B7F08: nop

    func_80029ED8(rdram, ctx);
        goto after_1;
    // 0x800B7F08: nop

    after_1:
    // 0x800B7F0C: b           L_800B7F1C
    // 0x800B7F10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B7F1C;
    // 0x800B7F10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7F14: b           L_800B7F1C
    // 0x800B7F18: nop

        goto L_800B7F1C;
    // 0x800B7F18: nop

L_800B7F1C:
    // 0x800B7F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B7F24: jr          $ra
    // 0x800B7F28: nop

    return;
    // 0x800B7F28: nop

;}
RECOMP_FUNC void func_8006EFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EFC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EFC4: jal         0x80061348
    // 0x8006EFC8: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EFC8: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    after_0:
    // 0x8006EFCC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EFD0: b           L_8006EFE0
    // 0x8006EFD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EFE0;
    // 0x8006EFD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EFD8: b           L_8006EFE0
    // 0x8006EFDC: nop

        goto L_8006EFE0;
    // 0x8006EFDC: nop

L_8006EFE0:
    // 0x8006EFE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EFE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EFE8: jr          $ra
    // 0x8006EFEC: nop

    return;
    // 0x8006EFEC: nop

;}
RECOMP_FUNC void func_80066504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006650C: jal         0x80061348
    // 0x80066510: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066510: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x80066514: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066518: b           L_80066528
    // 0x8006651C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066528;
    // 0x8006651C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066520: b           L_80066528
    // 0x80066524: nop

        goto L_80066528;
    // 0x80066524: nop

L_80066528:
    // 0x80066528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006652C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066530: jr          $ra
    // 0x80066534: nop

    return;
    // 0x80066534: nop

;}
RECOMP_FUNC void func_80071FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071FC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071FC4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071FC8: nop

    // 0x80071FCC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80071FD0: nop

    // 0x80071FD4: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071FD8: jr          $ra
    // 0x80071FDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071FDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071FE0: jr          $ra
    // 0x80071FE4: nop

    return;
    // 0x80071FE4: nop

    // 0x80071FE8: jr          $ra
    // 0x80071FEC: nop

    return;
    // 0x80071FEC: nop

;}
RECOMP_FUNC void SysMem_Free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC980: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BC984: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x800BC988: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800BC98C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800BC990: nop

    // 0x800BC994: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800BC998: nop

    // 0x800BC99C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BC9A0: bne         $t9, $zero, L_800BC9B0
    if (ctx->r25 != 0) {
        // 0x800BC9A4: nop
    
            goto L_800BC9B0;
    }
    // 0x800BC9A4: nop

    // 0x800BC9A8: b           L_800BCB08
    // 0x800BC9AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800BCB08;
    // 0x800BC9AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800BC9B0:
    // 0x800BC9B0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800BC9B4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800BC9B8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800BC9BC: nop

    // 0x800BC9C0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800BC9C4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x800BC9C8: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800BC9CC: nop

    // 0x800BC9D0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800BC9D4: nop

    // 0x800BC9D8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800BC9DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BC9E0: lw          $t6, 0x25E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25E8);
    // 0x800BC9E4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800BC9E8: nop

    // 0x800BC9EC: beq         $t5, $t6, L_800BCA5C
    if (ctx->r13 == ctx->r14) {
        // 0x800BC9F0: nop
    
            goto L_800BCA5C;
    }
    // 0x800BC9F0: nop

    // 0x800BC9F4: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x800BC9F8: nop

    // 0x800BC9FC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800BCA00: bne         $t8, $zero, L_800BCA5C
    if (ctx->r24 != 0) {
        // 0x800BCA04: nop
    
            goto L_800BCA5C;
    }
    // 0x800BCA04: nop

    // 0x800BCA08: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800BCA0C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA10: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x800BCA14: nop

    // 0x800BCA18: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800BCA1C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA20: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800BCA24: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x800BCA28: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x800BCA2C: nop

    // 0x800BCA30: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x800BCA34: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
    // 0x800BCA38: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA3C: nop

    // 0x800BCA40: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800BCA44: nop

    // 0x800BCA48: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800BCA4C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA50: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800BCA54: nop

    // 0x800BCA58: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_800BCA5C:
    // 0x800BCA5C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA60: nop

    // 0x800BCA64: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800BCA68: nop

    // 0x800BCA6C: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x800BCA70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BCA74: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BCA78: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800BCA7C: nop

    // 0x800BCA80: beq         $t3, $t6, L_800BCAF8
    if (ctx->r11 == ctx->r14) {
        // 0x800BCA84: nop
    
            goto L_800BCAF8;
    }
    // 0x800BCA84: nop

    // 0x800BCA88: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800BCA8C: nop

    // 0x800BCA90: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x800BCA94: nop

    // 0x800BCA98: andi        $t7, $t0, 0x1
    ctx->r15 = ctx->r8 & 0X1;
    // 0x800BCA9C: bne         $t7, $zero, L_800BCAF8
    if (ctx->r15 != 0) {
        // 0x800BCAA0: nop
    
            goto L_800BCAF8;
    }
    // 0x800BCAA0: nop

    // 0x800BCAA4: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800BCAA8: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800BCAAC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800BCAB0: nop

    // 0x800BCAB4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800BCAB8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800BCABC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800BCAC0: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800BCAC4: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x800BCAC8: nop

    // 0x800BCACC: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x800BCAD0: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x800BCAD4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800BCAD8: nop

    // 0x800BCADC: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x800BCAE0: nop

    // 0x800BCAE4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800BCAE8: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800BCAEC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800BCAF0: nop

    // 0x800BCAF4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_800BCAF8:
    // 0x800BCAF8: b           L_800BCB08
    // 0x800BCAFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BCB08;
    // 0x800BCAFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BCB00: b           L_800BCB08
    // 0x800BCB04: nop

        goto L_800BCB08;
    // 0x800BCB04: nop

L_800BCB08:
    // 0x800BCB08: jr          $ra
    // 0x800BCB0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BCB0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
