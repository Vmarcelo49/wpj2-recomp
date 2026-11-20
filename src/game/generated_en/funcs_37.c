#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8008C558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C558: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008C55C: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8008C560: nop

    // 0x8008C564: ori         $t7, $t6, 0xC000
    ctx->r15 = ctx->r14 | 0XC000;
    // 0x8008C568: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8008C56C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8008C570:
    // 0x8008C570: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8008C574: nop

    // 0x8008C578: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8008C57C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008C580: addu        $t1, $a0, $t8
    ctx->r9 = ADD32(ctx->r4, ctx->r24);
    // 0x8008C584: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x8008C588: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8008C58C: nop

    // 0x8008C590: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008C594: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x8008C598: bne         $at, $zero, L_8008C570
    if (ctx->r1 != 0) {
        // 0x8008C59C: sw          $t3, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r11;
            goto L_8008C570;
    }
    // 0x8008C59C: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x8008C5A0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8008C5A4:
    // 0x8008C5A4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8008C5A8: nop

    // 0x8008C5AC: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8008C5B0: lbu         $t6, 0x651($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X651);
    // 0x8008C5B4: addu        $t7, $a0, $t4
    ctx->r15 = ADD32(ctx->r4, ctx->r12);
    // 0x8008C5B8: sb          $t6, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r14;
    // 0x8008C5BC: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8008C5C0: nop

    // 0x8008C5C4: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8008C5C8: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x8008C5CC: bne         $at, $zero, L_8008C5A4
    if (ctx->r1 != 0) {
        // 0x8008C5D0: sw          $t8, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r24;
            goto L_8008C5A4;
    }
    // 0x8008C5D0: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8008C5D4: lh          $t0, 0xAE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XAE);
    // 0x8008C5D8: nop

    // 0x8008C5DC: sh          $t0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r8;
    // 0x8008C5E0: lhu         $t1, 0x6C($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X6C);
    // 0x8008C5E4: nop

    // 0x8008C5E8: sb          $t1, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r9;
    // 0x8008C5EC: lbu         $t2, 0x64($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X64);
    // 0x8008C5F0: nop

    // 0x8008C5F4: andi        $t3, $t2, 0xE
    ctx->r11 = ctx->r10 & 0XE;
    // 0x8008C5F8: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8008C5FC: sb          $t5, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r13;
    // 0x8008C600: lbu         $t4, 0x64($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X64);
    // 0x8008C604: nop

    // 0x8008C608: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x8008C60C: sb          $t6, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r14;
    // 0x8008C610: lbu         $t7, 0x64($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X64);
    // 0x8008C614: nop

    // 0x8008C618: andi        $t9, $t7, 0xF0
    ctx->r25 = ctx->r15 & 0XF0;
    // 0x8008C61C: sra         $t8, $t9, 4
    ctx->r24 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8008C620: sb          $t8, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r24;
    // 0x8008C624: b           L_8008C62C
    // 0x8008C628: nop

        goto L_8008C62C;
    // 0x8008C628: nop

L_8008C62C:
    // 0x8008C62C: jr          $ra
    // 0x8008C630: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008C630: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8008C634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C63C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C640: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008C644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008C648: jal         0x8005FC18
    // 0x8008C64C: nop

    func_8005FC18(rdram, ctx);
        goto after_0;
    // 0x8008C64C: nop

    after_0:
    // 0x8008C650: bne         $v0, $zero, L_8008C678
    if (ctx->r2 != 0) {
        // 0x8008C654: nop

            goto L_8008C678;
    }
    // 0x8008C654: nop

    // 0x8008C658: jal         0x8005D150
    // 0x8008C65C: nop

    func_8005D150(rdram, ctx);
        goto after_1;
    // 0x8008C65C: nop

    after_1:
    // 0x8008C660: jal         0x8005F01C
    // 0x8008C664: nop

    func_8005F01C(rdram, ctx);
        goto after_2;
    // 0x8008C664: nop

    after_2:
    // 0x8008C668: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008C66C: sb          $zero, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = 0;
    // 0x8008C670: b           L_8008C6D0
    // 0x8008C674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008C6D0;
    // 0x8008C674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008C678:
    // 0x8008C678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008C67C: jal         0x80028B94
    // 0x8008C680: nop

    func_80028B94(rdram, ctx);
        goto after_3;
    // 0x8008C680: nop

    after_3:
    // 0x8008C684: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008C688: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008C68C: lw          $t7, 0x68($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X68);
    // 0x8008C690: nop

    // 0x8008C694: sw          $t7, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r15;
    // 0x8008C698: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008C69C: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x8008C6A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008C6A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8008C6A8: lhu         $t9, 0x6C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6C);
    // 0x8008C6AC: nop

    // 0x8008C6B0: sb          $t9, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = ctx->r25;
    // 0x8008C6B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C6B8: jal         0x8008C6E0
    // 0x8008C6BC: nop

    func_8008C6E0(rdram, ctx);
        goto after_4;
    // 0x8008C6BC: nop

    after_4:
    // 0x8008C6C0: b           L_8008C6D0
    // 0x8008C6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C6D0;
    // 0x8008C6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008C6C8: b           L_8008C6D0
    // 0x8008C6CC: nop

        goto L_8008C6D0;
    // 0x8008C6CC: nop

L_8008C6D0:
    // 0x8008C6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C6D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C6D8: jr          $ra
    // 0x8008C6DC: nop

    return;
    // 0x8008C6DC: nop

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
    // 0x8008C6FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
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
    // 0x8008C714: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8008C718: jal         0x8008BE0C
    // 0x8008C71C: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    func_8008BE0C(rdram, ctx);
        goto after_1;
    // 0x8008C71C: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    after_1:
    // 0x8008C720: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008C724: nop

    // 0x8008C728: lbu         $s0, 0x13($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X13);
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

    // 0x8008C794: lbu         $s0, 0x14($t0)
    ctx->r16 = MEM_BU(ctx->r8, 0X14);
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

    // 0x8008C7DC: lbu         $s0, 0x15($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0X15);
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
RECOMP_FUNC void func_8008C854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C854: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008C858: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008C85C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008C860: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C864: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8008C868: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008C86C: addiu       $a1, $a1, -0x6110
    ctx->r5 = ADD32(ctx->r5, -0X6110);
    // 0x8008C870: jal         0x8008BEE0
    // 0x8008C874: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_8008BEE0(rdram, ctx);
        goto after_0;
    // 0x8008C874: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_0:
    // 0x8008C878: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8008C87C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008C880: addiu       $a1, $a1, -0x611C
    ctx->r5 = ADD32(ctx->r5, -0X611C);
    // 0x8008C884: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8008C888: jal         0x8008BEE0
    // 0x8008C88C: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    func_8008BEE0(rdram, ctx);
        goto after_1;
    // 0x8008C88C: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    after_1:
    // 0x8008C890: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8008C894: jal         0x80028F74
    // 0x8008C898: nop

    func_80028F74(rdram, ctx);
        goto after_2;
    // 0x8008C898: nop

    after_2:
    // 0x8008C89C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008C8A0: lhu         $s0, -0x44C8($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X44C8);
    // 0x8008C8A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008C8A8: beq         $s0, $at, L_8008C8DC
    if (ctx->r16 == ctx->r1) {
        // 0x8008C8AC: nop

            goto L_8008C8DC;
    }
    // 0x8008C8AC: nop

    // 0x8008C8B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008C8B4: beq         $s0, $at, L_8008C8D0
    if (ctx->r16 == ctx->r1) {
        // 0x8008C8B8: nop

            goto L_8008C8D0;
    }
    // 0x8008C8B8: nop

    // 0x8008C8BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008C8C0: beq         $s0, $at, L_8008C8EC
    if (ctx->r16 == ctx->r1) {
        // 0x8008C8C4: nop

            goto L_8008C8EC;
    }
    // 0x8008C8C4: nop

    // 0x8008C8C8: b           L_8008C8F4
    // 0x8008C8CC: nop

        goto L_8008C8F4;
    // 0x8008C8CC: nop

L_8008C8D0:
    // 0x8008C8D0: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x8008C8D4: b           L_8008C8F4
    // 0x8008C8D8: nop

        goto L_8008C8F4;
    // 0x8008C8D8: nop

L_8008C8DC:
    // 0x8008C8DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008C8E0: sh          $t6, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r14;
    // 0x8008C8E4: b           L_8008C8F4
    // 0x8008C8E8: nop

        goto L_8008C8F4;
    // 0x8008C8E8: nop

L_8008C8EC:
    // 0x8008C8EC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8008C8F0: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
L_8008C8F4:
    // 0x8008C8F4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008C8F8: lw          $s0, 0x465C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X465C);
    // 0x8008C8FC: nop

    // 0x8008C900: beq         $s0, $zero, L_8008C91C
    if (ctx->r16 == 0) {
        // 0x8008C904: nop

            goto L_8008C91C;
    }
    // 0x8008C904: nop

    // 0x8008C908: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C90C: beq         $s0, $at, L_8008C928
    if (ctx->r16 == ctx->r1) {
        // 0x8008C910: nop

            goto L_8008C928;
    }
    // 0x8008C910: nop

    // 0x8008C914: b           L_8008C930
    // 0x8008C918: nop

        goto L_8008C930;
    // 0x8008C918: nop

L_8008C91C:
    // 0x8008C91C: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // 0x8008C920: b           L_8008C930
    // 0x8008C924: nop

        goto L_8008C930;
    // 0x8008C924: nop

L_8008C928:
    // 0x8008C928: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008C92C: sh          $t8, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r24;
L_8008C930:
    // 0x8008C930: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8008C934: lbu         $s0, 0x127D($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0X127D);
    // 0x8008C938: nop

    // 0x8008C93C: beq         $s0, $zero, L_8008C970
    if (ctx->r16 == 0) {
        // 0x8008C940: nop

            goto L_8008C970;
    }
    // 0x8008C940: nop

    // 0x8008C944: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C948: beq         $s0, $at, L_8008C964
    if (ctx->r16 == ctx->r1) {
        // 0x8008C94C: nop

            goto L_8008C964;
    }
    // 0x8008C94C: nop

    // 0x8008C950: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008C954: beq         $s0, $at, L_8008C980
    if (ctx->r16 == ctx->r1) {
        // 0x8008C958: nop

            goto L_8008C980;
    }
    // 0x8008C958: nop

    // 0x8008C95C: b           L_8008C988
    // 0x8008C960: nop

        goto L_8008C988;
    // 0x8008C960: nop

L_8008C964:
    // 0x8008C964: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
    // 0x8008C968: b           L_8008C988
    // 0x8008C96C: nop

        goto L_8008C988;
    // 0x8008C96C: nop

L_8008C970:
    // 0x8008C970: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008C974: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x8008C978: b           L_8008C988
    // 0x8008C97C: nop

        goto L_8008C988;
    // 0x8008C97C: nop

L_8008C980:
    // 0x8008C980: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008C984: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
L_8008C988:
    // 0x8008C988: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x8008C98C: lhu         $t3, 0x2E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2E);
    // 0x8008C990: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x8008C994: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8008C998: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8008C99C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008C9A0: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8008C9A4: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8008C9A8: sb          $t7, 0x64($t8)
    MEM_B(0X64, ctx->r24) = ctx->r15;
    // 0x8008C9AC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8008C9B0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8008C9B4: lw          $t0, 0x70E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70E8);
    // 0x8008C9B8: lw          $t9, 0x718C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X718C);
    // 0x8008C9BC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008C9C0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8008C9C4: sw          $t1, 0x68($t3)
    MEM_W(0X68, ctx->r11) = ctx->r9;
    // 0x8008C9C8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8008C9CC: lbu         $t2, 0x7208($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7208);
    // 0x8008C9D0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008C9D4: nop

    // 0x8008C9D8: sh          $t2, 0x6C($t4)
    MEM_H(0X6C, ctx->r12) = ctx->r10;
    // 0x8008C9DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8008C9E0: jal         0x8005F410
    // 0x8008C9E4: nop

    func_8005F410(rdram, ctx);
        goto after_3;
    // 0x8008C9E4: nop

    after_3:
    // 0x8008C9E8: b           L_8008C9F0
    // 0x8008C9EC: nop

        goto L_8008C9F0;
    // 0x8008C9EC: nop

L_8008C9F0:
    // 0x8008C9F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C9F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C9F8: jr          $ra
    // 0x8008C9FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008C9FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8008CA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CA00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CA04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CA08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008CA0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA10: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8008CA14: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x8008CA18: nop

    // 0x8008CA1C: bne         $t7, $at, L_8008CAAC
    if (ctx->r15 != ctx->r1) {
        // 0x8008CA20: nop

            goto L_8008CAAC;
    }
    // 0x8008CA20: nop

    // 0x8008CA24: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA28: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8008CA2C: sh          $t8, 0xBEC($t9)
    MEM_H(0XBEC, ctx->r25) = ctx->r24;
    // 0x8008CA30: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA34: nop

    // 0x8008CA38: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8008CA3C: nop

    // 0x8008CA40: andi        $t2, $t1, 0x800
    ctx->r10 = ctx->r9 & 0X800;
    // 0x8008CA44: beq         $t2, $zero, L_8008CA60
    if (ctx->r10 == 0) {
        // 0x8008CA48: nop

            goto L_8008CA60;
    }
    // 0x8008CA48: nop

    // 0x8008CA4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA50: jal         0x8008C6E0
    // 0x8008CA54: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8008C6E0(rdram, ctx);
        goto after_0;
    // 0x8008CA54: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_0:
    // 0x8008CA58: b           L_8008CBF8
    // 0x8008CA5C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_8008CBF8;
    // 0x8008CA5C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_8008CA60:
    // 0x8008CA60: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA64: nop

    // 0x8008CA68: lw          $a0, 0xC10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC10);
    // 0x8008CA6C: jal         0x8008C3D4
    // 0x8008CA70: nop

    func_8008C3D4(rdram, ctx);
        goto after_1;
    // 0x8008CA70: nop

    after_1:
    // 0x8008CA74: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA78: nop

    // 0x8008CA7C: lw          $a0, 0xC10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC10);
    // 0x8008CA80: jal         0x8008C4AC
    // 0x8008CA84: addiu       $a1, $t4, 0xE
    ctx->r5 = ADD32(ctx->r12, 0XE);
    func_8008C4AC(rdram, ctx);
        goto after_2;
    // 0x8008CA84: addiu       $a1, $t4, 0xE
    ctx->r5 = ADD32(ctx->r12, 0XE);
    after_2:
    // 0x8008CA88: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008CA8C: nop

    // 0x8008CA90: lw          $a0, 0xC10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC10);
    // 0x8008CA94: jal         0x8008C528
    // 0x8008CA98: addiu       $a1, $t5, 0xE
    ctx->r5 = ADD32(ctx->r13, 0XE);
    func_8008C528(rdram, ctx);
        goto after_3;
    // 0x8008CA98: addiu       $a1, $t5, 0xE
    ctx->r5 = ADD32(ctx->r13, 0XE);
    after_3:
    // 0x8008CA9C: b           L_8008CBF8
    // 0x8008CAA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8008CBF8;
    // 0x8008CAA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8008CAA4: b           L_8008CBF0
    // 0x8008CAA8: nop

        goto L_8008CBF0;
    // 0x8008CAA8: nop

L_8008CAAC:
    // 0x8008CAAC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008CAB0: nop

    // 0x8008CAB4: sh          $zero, 0xBEC($t6)
    MEM_H(0XBEC, ctx->r14) = 0;
    // 0x8008CAB8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008CABC: lh          $t7, 0x7A16($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7A16);
    // 0x8008CAC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008CAC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008CAC8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008CACC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008CAD0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008CAD4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008CAD8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8008CADC: addiu       $t9, $t9, 0x7AE8
    ctx->r25 = ADD32(ctx->r25, 0X7AE8);
    // 0x8008CAE0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8008CAE4: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x8008CAE8: lbu         $t3, 0x21($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X21);
    // 0x8008CAEC: nop

    // 0x8008CAF0: bne         $t1, $t3, L_8008CB70
    if (ctx->r9 != ctx->r11) {
        // 0x8008CAF4: nop

            goto L_8008CB70;
    }
    // 0x8008CAF4: nop

    // 0x8008CAF8: lbu         $t4, 0x14($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X14);
    // 0x8008CAFC: lbu         $t5, 0x22($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X22);
    // 0x8008CB00: nop

    // 0x8008CB04: bne         $t4, $t5, L_8008CB70
    if (ctx->r12 != ctx->r13) {
        // 0x8008CB08: nop

            goto L_8008CB70;
    }
    // 0x8008CB08: nop

    // 0x8008CB0C: lbu         $t6, 0x15($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X15);
    // 0x8008CB10: lbu         $t7, 0x23($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X23);
    // 0x8008CB14: nop

    // 0x8008CB18: bne         $t6, $t7, L_8008CB70
    if (ctx->r14 != ctx->r15) {
        // 0x8008CB1C: nop

            goto L_8008CB70;
    }
    // 0x8008CB1C: nop

    // 0x8008CB20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008CB24: lh          $t9, 0x7A16($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7A16);
    // 0x8008CB28: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB2C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8008CB30: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x8008CB34: lw          $a0, 0xC04($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC04);
    // 0x8008CB38: jal         0x8008C634
    // 0x8008CB3C: addiu       $a1, $t8, 0xE
    ctx->r5 = ADD32(ctx->r24, 0XE);
    func_8008C634(rdram, ctx);
        goto after_4;
    // 0x8008CB3C: addiu       $a1, $t8, 0xE
    ctx->r5 = ADD32(ctx->r24, 0XE);
    after_4:
    // 0x8008CB40: beq         $v0, $zero, L_8008CB68
    if (ctx->r2 == 0) {
        // 0x8008CB44: nop

            goto L_8008CB68;
    }
    // 0x8008CB44: nop

    // 0x8008CB48: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB4C: nop

    // 0x8008CB50: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x8008CB54: nop

    // 0x8008CB58: ori         $t0, $t5, 0x4
    ctx->r8 = ctx->r13 | 0X4;
    // 0x8008CB5C: sh          $t0, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r8;
    // 0x8008CB60: b           L_8008CBF8
    // 0x8008CB64: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8008CBF8;
    // 0x8008CB64: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8008CB68:
    // 0x8008CB68: b           L_8008CBF8
    // 0x8008CB6C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_8008CBF8;
    // 0x8008CB6C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_8008CB70:
    // 0x8008CB70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008CB74: lh          $t6, 0x7A16($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7A16);
    // 0x8008CB78: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008CB80: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x8008CB84: lw          $t1, 0xC04($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC04);
    // 0x8008CB88: nop

    // 0x8008CB8C: bne         $t1, $zero, L_8008CBB0
    if (ctx->r9 != 0) {
        // 0x8008CB90: nop

            goto L_8008CBB0;
    }
    // 0x8008CB90: nop

    // 0x8008CB94: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB98: nop

    // 0x8008CB9C: lhu         $t8, 0x2($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X2);
    // 0x8008CBA0: nop

    // 0x8008CBA4: ori         $t5, $t8, 0x2
    ctx->r13 = ctx->r24 | 0X2;
    // 0x8008CBA8: b           L_8008CBE8
    // 0x8008CBAC: sh          $t5, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r13;
        goto L_8008CBE8;
    // 0x8008CBAC: sh          $t5, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r13;
L_8008CBB0:
    // 0x8008CBB0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008CBB4: lh          $t4, 0x7A16($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7A16);
    // 0x8008CBB8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008CBBC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8008CBC0: addu        $t2, $t0, $t6
    ctx->r10 = ADD32(ctx->r8, ctx->r14);
    // 0x8008CBC4: lw          $a1, 0xC04($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC04);
    // 0x8008CBC8: lw          $a0, 0xC10($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC10);
    // 0x8008CBCC: jal         0x800BCFCC
    // 0x8008CBD0: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x8008CBD0: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_5:
    // 0x8008CBD4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008CBD8: nop

    // 0x8008CBDC: lw          $a0, 0xC10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC10);
    // 0x8008CBE0: jal         0x8008C528
    // 0x8008CBE4: addiu       $a1, $t7, 0xE
    ctx->r5 = ADD32(ctx->r15, 0XE);
    func_8008C528(rdram, ctx);
        goto after_6;
    // 0x8008CBE4: addiu       $a1, $t7, 0xE
    ctx->r5 = ADD32(ctx->r15, 0XE);
    after_6:
L_8008CBE8:
    // 0x8008CBE8: b           L_8008CBF8
    // 0x8008CBEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8008CBF8;
    // 0x8008CBEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8008CBF0:
    // 0x8008CBF0: b           L_8008CBF8
    // 0x8008CBF4: nop

        goto L_8008CBF8;
    // 0x8008CBF4: nop

L_8008CBF8:
    // 0x8008CBF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CBFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CC00: jr          $ra
    // 0x8008CC04: nop

    return;
    // 0x8008CC04: nop

;}
RECOMP_FUNC void func_8008CC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CC08: b           L_8008CDFC
    // 0x8008CC0C: nop

        goto L_8008CDFC;
    // 0x8008CC0C: nop

    // 0x8008CC10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008CC14: nop

    // 0x8008CC18: swc1        $f4, 0xC1C($a0)
    MEM_W(0XC1C, ctx->r4) = ctx->f4.u32l;
    // 0x8008CC1C: lwc1        $f6, 0xC1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC1C);
    // 0x8008CC20: nop

    // 0x8008CC24: swc1        $f6, 0xC18($a0)
    MEM_W(0XC18, ctx->r4) = ctx->f6.u32l;
    // 0x8008CC28: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8008CC2C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8008CC30: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008CC34: lhu         $t8, 0x1038($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1038);
    // 0x8008CC38: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8008CC3C: nop

    // 0x8008CC40: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8008CC44: beq         $t9, $zero, L_8008CD24
    if (ctx->r25 == 0) {
        // 0x8008CC48: nop

            goto L_8008CD24;
    }
    // 0x8008CC48: nop

    // 0x8008CC4C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008CC50: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8008CC54: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8008CC58: lhu         $t2, 0xE68($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XE68);
    // 0x8008CC5C: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x8008CC60: nop

    // 0x8008CC64: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8008CC68: beq         $t3, $zero, L_8008CC80
    if (ctx->r11 == 0) {
        // 0x8008CC6C: nop

            goto L_8008CC80;
    }
    // 0x8008CC6C: nop

    // 0x8008CC70: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8008CC74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008CC78: nop

    // 0x8008CC7C: swc1        $f8, 0xC1C($a0)
    MEM_W(0XC1C, ctx->r4) = ctx->f8.u32l;
L_8008CC80:
    // 0x8008CC80: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8008CC84: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8008CC88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008CC8C: lhu         $t6, 0xE74($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XE74);
    // 0x8008CC90: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x8008CC94: nop

    // 0x8008CC98: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8008CC9C: beq         $t7, $zero, L_8008CCB4
    if (ctx->r15 == 0) {
        // 0x8008CCA0: nop

            goto L_8008CCB4;
    }
    // 0x8008CCA0: nop

    // 0x8008CCA4: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x8008CCA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008CCAC: nop

    // 0x8008CCB0: swc1        $f10, 0xC1C($a0)
    MEM_W(0XC1C, ctx->r4) = ctx->f10.u32l;
L_8008CCB4:
    // 0x8008CCB4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008CCB8: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8008CCBC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008CCC0: lhu         $t0, 0xEEC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XEEC);
    // 0x8008CCC4: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x8008CCC8: nop

    // 0x8008CCCC: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8008CCD0: beq         $t1, $zero, L_8008CCE8
    if (ctx->r9 == 0) {
        // 0x8008CCD4: nop

            goto L_8008CCE8;
    }
    // 0x8008CCD4: nop

    // 0x8008CCD8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8008CCDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008CCE0: nop

    // 0x8008CCE4: swc1        $f16, 0xC18($a0)
    MEM_W(0XC18, ctx->r4) = ctx->f16.u32l;
L_8008CCE8:
    // 0x8008CCE8: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8008CCEC: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8008CCF0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008CCF4: lhu         $t4, 0xEC0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XEC0);
    // 0x8008CCF8: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x8008CCFC: nop

    // 0x8008CD00: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x8008CD04: beq         $t5, $zero, L_8008CD1C
    if (ctx->r13 == 0) {
        // 0x8008CD08: nop

            goto L_8008CD1C;
    }
    // 0x8008CD08: nop

    // 0x8008CD0C: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x8008CD10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008CD14: nop

    // 0x8008CD18: swc1        $f18, 0xC18($a0)
    MEM_W(0XC18, ctx->r4) = ctx->f18.u32l;
L_8008CD1C:
    // 0x8008CD1C: b           L_8008CDF4
    // 0x8008CD20: nop

        goto L_8008CDF4;
    // 0x8008CD20: nop

L_8008CD24:
    // 0x8008CD24: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8008CD28: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8008CD2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008CD30: lhu         $t8, 0xE68($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XE68);
    // 0x8008CD34: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8008CD38: nop

    // 0x8008CD3C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8008CD40: beq         $t9, $zero, L_8008CD58
    if (ctx->r25 == 0) {
        // 0x8008CD44: nop

            goto L_8008CD58;
    }
    // 0x8008CD44: nop

    // 0x8008CD48: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8008CD4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008CD50: nop

    // 0x8008CD54: swc1        $f4, 0xC1C($a0)
    MEM_W(0XC1C, ctx->r4) = ctx->f4.u32l;
L_8008CD58:
    // 0x8008CD58: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008CD5C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8008CD60: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8008CD64: lhu         $t2, 0xE74($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XE74);
    // 0x8008CD68: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x8008CD6C: nop

    // 0x8008CD70: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8008CD74: beq         $t3, $zero, L_8008CD8C
    if (ctx->r11 == 0) {
        // 0x8008CD78: nop

            goto L_8008CD8C;
    }
    // 0x8008CD78: nop

    // 0x8008CD7C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8008CD80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008CD84: nop

    // 0x8008CD88: swc1        $f6, 0xC1C($a0)
    MEM_W(0XC1C, ctx->r4) = ctx->f6.u32l;
L_8008CD8C:
    // 0x8008CD8C: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8008CD90: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8008CD94: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008CD98: lhu         $t6, 0xEEC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XEEC);
    // 0x8008CD9C: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x8008CDA0: nop

    // 0x8008CDA4: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8008CDA8: beq         $t7, $zero, L_8008CDC0
    if (ctx->r15 == 0) {
        // 0x8008CDAC: nop

            goto L_8008CDC0;
    }
    // 0x8008CDAC: nop

    // 0x8008CDB0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8008CDB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008CDB8: nop

    // 0x8008CDBC: swc1        $f8, 0xC18($a0)
    MEM_W(0XC18, ctx->r4) = ctx->f8.u32l;
L_8008CDC0:
    // 0x8008CDC0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008CDC4: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8008CDC8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008CDCC: lhu         $t0, 0xEC0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XEC0);
    // 0x8008CDD0: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x8008CDD4: nop

    // 0x8008CDD8: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8008CDDC: beq         $t1, $zero, L_8008CDF4
    if (ctx->r9 == 0) {
        // 0x8008CDE0: nop

            goto L_8008CDF4;
    }
    // 0x8008CDE0: nop

    // 0x8008CDE4: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8008CDE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008CDEC: nop

    // 0x8008CDF0: swc1        $f10, 0xC18($a0)
    MEM_W(0XC18, ctx->r4) = ctx->f10.u32l;
L_8008CDF4:
    // 0x8008CDF4: b           L_8008CE24
    // 0x8008CDF8: nop

        goto L_8008CE24;
    // 0x8008CDF8: nop

L_8008CDFC:
    // 0x8008CDFC: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8008CE00: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8008CE04: lwc1        $f16, 0x10($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8008CE08: nop

    // 0x8008CE0C: swc1        $f16, 0xC18($a0)
    MEM_W(0XC18, ctx->r4) = ctx->f16.u32l;
    // 0x8008CE10: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8008CE14: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8008CE18: lwc1        $f18, 0x14($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X14);
    // 0x8008CE1C: nop

    // 0x8008CE20: swc1        $f18, 0xC1C($a0)
    MEM_W(0XC1C, ctx->r4) = ctx->f18.u32l;
L_8008CE24:
    // 0x8008CE24: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8008CE28: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8008CE2C: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8008CE30: nop

    // 0x8008CE34: sh          $t5, 0xC20($a0)
    MEM_H(0XC20, ctx->r4) = ctx->r13;
    // 0x8008CE38: jr          $ra
    // 0x8008CE3C: nop

    return;
    // 0x8008CE3C: nop

    // 0x8008CE40: jr          $ra
    // 0x8008CE44: nop

    return;
    // 0x8008CE44: nop

;}
RECOMP_FUNC void func_8008CE48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CE48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CE4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CE50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008CE54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008CE58: jal         0x800220F4
    // 0x8008CE5C: nop

    func_800220F4(rdram, ctx);
        goto after_0;
    // 0x8008CE5C: nop

    after_0:
    // 0x8008CE60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008CE64: jal         0x800B9000
    // 0x8008CE68: nop

    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8008CE68: nop

    after_1:
    // 0x8008CE6C: b           L_8008CE74
    // 0x8008CE70: nop

        goto L_8008CE74;
    // 0x8008CE70: nop

L_8008CE74:
    // 0x8008CE74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CE78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CE7C: jr          $ra
    // 0x8008CE80: nop

    return;
    // 0x8008CE80: nop

    // 0x8008CE84: nop

    // 0x8008CE88: nop

    // 0x8008CE8C: nop

;}
RECOMP_FUNC void func_8008CE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CE90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CE98: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8008CE9C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8008CEA0: jal         0x80021FF8
    // 0x8008CEA4: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_80021FF8(rdram, ctx);
        goto after_0;
    // 0x8008CEA4: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_0:
    // 0x8008CEA8: jal         0x80098BF4
    // 0x8008CEAC: nop

    func_80098BF4(rdram, ctx);
        goto after_1;
    // 0x8008CEAC: nop

    after_1:
    // 0x8008CEB0: jal         0x800BC6EC
    // 0x8008CEB4: addiu       $a0, $zero, 0x3B8
    ctx->r4 = ADD32(0, 0X3B8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8008CEB4: addiu       $a0, $zero, 0x3B8
    ctx->r4 = ADD32(0, 0X3B8);
    after_2:
    // 0x8008CEB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8008CEBC: sw          $v0, -0x76BC($at)
    MEM_W(-0X76BC, ctx->r1) = ctx->r2;
    // 0x8008CEC0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008CEC4: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8008CEC8: nop

    // 0x8008CECC: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
    // 0x8008CED0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008CED4: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x8008CED8: nop

    // 0x8008CEDC: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x8008CEE0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008CEE4: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008CEE8: jal         0x8008D29C
    // 0x8008CEEC: nop

    func_8008D29C(rdram, ctx);
        goto after_3;
    // 0x8008CEEC: nop

    after_3:
    // 0x8008CEF0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008CEF4: lw          $t8, -0x76BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76BC);
    // 0x8008CEF8: nop

    // 0x8008CEFC: sh          $zero, 0x4($t8)
    MEM_H(0X4, ctx->r24) = 0;
    // 0x8008CF00: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008CF04: lw          $t9, -0x76BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76BC);
    // 0x8008CF08: nop

    // 0x8008CF0C: sh          $zero, 0x168($t9)
    MEM_H(0X168, ctx->r25) = 0;
    // 0x8008CF10: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8008CF14: lw          $t1, -0x76BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76BC);
    // 0x8008CF18: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8008CF1C: sh          $t0, 0x16A($t1)
    MEM_H(0X16A, ctx->r9) = ctx->r8;
    // 0x8008CF20: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008CF24: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008CF28: jal         0x8008E2E0
    // 0x8008CF2C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8008E2E0(rdram, ctx);
        goto after_4;
    // 0x8008CF2C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_4:
    // 0x8008CF30: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8008CF34: lw          $t3, -0x76BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76BC);
    // 0x8008CF38: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008CF3C: sh          $t2, 0x120($t3)
    MEM_H(0X120, ctx->r11) = ctx->r10;
    // 0x8008CF40: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8008CF44: lw          $t4, -0x76BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76BC);
    // 0x8008CF48: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8008CF4C: sh          $zero, 0x124($t4)
    MEM_H(0X124, ctx->r12) = 0;
    // 0x8008CF50: lw          $t5, -0x76BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76BC);
    // 0x8008CF54: nop

    // 0x8008CF58: lh          $t6, 0x124($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X124);
    // 0x8008CF5C: nop

    // 0x8008CF60: sh          $t6, 0x122($t5)
    MEM_H(0X122, ctx->r13) = ctx->r14;
    // 0x8008CF64: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008CF68: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008CF6C: jal         0x8008DFA8
    // 0x8008CF70: nop

    func_8008DFA8(rdram, ctx);
        goto after_5;
    // 0x8008CF70: nop

    after_5:
    // 0x8008CF74: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008CF78: lw          $t8, -0x76BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76BC);
    // 0x8008CF7C: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x8008CF80: sh          $t7, 0x126($t8)
    MEM_H(0X126, ctx->r24) = ctx->r15;
    // 0x8008CF84: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8008CF88: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008CF8C: lw          $t9, -0x76BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76BC);
    // 0x8008CF90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008CF94: nop

    // 0x8008CF98: swc1        $f4, 0x320($t9)
    MEM_W(0X320, ctx->r25) = ctx->f4.u32l;
    // 0x8008CF9C: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x8008CFA0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8008CFA4: lw          $t0, -0x76BC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76BC);
    // 0x8008CFA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008CFAC: nop

    // 0x8008CFB0: swc1        $f6, 0x324($t0)
    MEM_W(0X324, ctx->r8) = ctx->f6.u32l;
    // 0x8008CFB4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008CFB8: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008CFBC: jal         0x8001A690
    // 0x8008CFC0: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001A690(rdram, ctx);
        goto after_6;
    // 0x8008CFC0: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_6:
    // 0x8008CFC4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8008CFC8: lw          $t2, -0x76BC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76BC);
    // 0x8008CFCC: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8008CFD0: sh          $t1, 0x234($t2)
    MEM_H(0X234, ctx->r10) = ctx->r9;
    // 0x8008CFD4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8008CFD8: lw          $t3, -0x76BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76BC);
    // 0x8008CFDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008CFE0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8008CFE4: swc1        $f8, 0x240($t3)
    MEM_W(0X240, ctx->r11) = ctx->f8.u32l;
    // 0x8008CFE8: lw          $t4, -0x76BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76BC);
    // 0x8008CFEC: nop

    // 0x8008CFF0: lwc1        $f10, 0x240($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X240);
    // 0x8008CFF4: nop

    // 0x8008CFF8: swc1        $f10, 0x23C($t4)
    MEM_W(0X23C, ctx->r12) = ctx->f10.u32l;
    // 0x8008CFFC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8008D000: lw          $t5, -0x76BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76BC);
    // 0x8008D004: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8008D008: sw          $t6, 0x238($t5)
    MEM_W(0X238, ctx->r13) = ctx->r14;
    // 0x8008D00C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D010: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D014: jal         0x8008E358
    // 0x8008D018: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8008E358(rdram, ctx);
        goto after_7;
    // 0x8008D018: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_7:
    // 0x8008D01C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D020: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D028: jal         0x8008E184
    // 0x8008D02C: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8008E184(rdram, ctx);
        goto after_8;
    // 0x8008D02C: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_8:
    // 0x8008D030: jal         0x8008DD40
    // 0x8008D034: nop

    func_8008DD40(rdram, ctx);
        goto after_9;
    // 0x8008D034: nop

    after_9:
    // 0x8008D038: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008D03C: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x8008D040: nop

    // 0x8008D044: sw          $v0, 0x3A8($t7)
    MEM_W(0X3A8, ctx->r15) = ctx->r2;
    // 0x8008D048: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008D04C: lw          $t8, -0x76BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76BC);
    // 0x8008D050: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008D054: addiu       $t9, $t9, 0x4C20
    ctx->r25 = ADD32(ctx->r25, 0X4C20);
    // 0x8008D058: sh          $zero, 0x3AC($t8)
    MEM_H(0X3AC, ctx->r24) = 0;
    // 0x8008D05C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8008D060: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008D064: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008D068: beq         $t0, $at, L_8008D0AC
    if (ctx->r8 == ctx->r1) {
        // 0x8008D06C: nop

            goto L_8008D0AC;
    }
    // 0x8008D06C: nop

L_8008D070:
    // 0x8008D070: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8008D074: lw          $t1, -0x76BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76BC);
    // 0x8008D078: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008D07C: lh          $t2, 0x3AC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X3AC);
    // 0x8008D080: nop

    // 0x8008D084: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008D088: sh          $t3, 0x3AC($t1)
    MEM_H(0X3AC, ctx->r9) = ctx->r11;
    // 0x8008D08C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D090: nop

    // 0x8008D094: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8008D098: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8008D09C: lbu         $t5, 0x0($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X0);
    // 0x8008D0A0: nop

    // 0x8008D0A4: bne         $t5, $at, L_8008D070
    if (ctx->r13 != ctx->r1) {
        // 0x8008D0A8: nop

            goto L_8008D070;
    }
    // 0x8008D0A8: nop

L_8008D0AC:
    // 0x8008D0AC: b           L_8008D0BC
    // 0x8008D0B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D0BC;
    // 0x8008D0B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D0B4: b           L_8008D0BC
    // 0x8008D0B8: nop

        goto L_8008D0BC;
    // 0x8008D0B8: nop

L_8008D0BC:
    // 0x8008D0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D0C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008D0C4: jr          $ra
    // 0x8008D0C8: nop

    return;
    // 0x8008D0C8: nop

;}
RECOMP_FUNC void func_8008D0CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D0CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008D0D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008D0D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008D0D8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D0DC: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8008D0E0: nop

    // 0x8008D0E4: lh          $s0, 0x2($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X2);
    // 0x8008D0E8: nop

    // 0x8008D0EC: beq         $s0, $zero, L_8008D120
    if (ctx->r16 == 0) {
        // 0x8008D0F0: nop

            goto L_8008D120;
    }
    // 0x8008D0F0: nop

    // 0x8008D0F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D0F8: beq         $s0, $at, L_8008D13C
    if (ctx->r16 == ctx->r1) {
        // 0x8008D0FC: nop

            goto L_8008D13C;
    }
    // 0x8008D0FC: nop

    // 0x8008D100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008D104: beq         $s0, $at, L_8008D158
    if (ctx->r16 == ctx->r1) {
        // 0x8008D108: nop

            goto L_8008D158;
    }
    // 0x8008D108: nop

    // 0x8008D10C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008D110: beq         $s0, $at, L_8008D174
    if (ctx->r16 == ctx->r1) {
        // 0x8008D114: nop

            goto L_8008D174;
    }
    // 0x8008D114: nop

    // 0x8008D118: b           L_8008D17C
    // 0x8008D11C: nop

        goto L_8008D17C;
    // 0x8008D11C: nop

L_8008D120:
    // 0x8008D120: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D124: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D128: jal         0x8008D45C
    // 0x8008D12C: nop

    func_8008D45C(rdram, ctx);
        goto after_0;
    // 0x8008D12C: nop

    after_0:
    // 0x8008D130: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8008D134: b           L_8008D17C
    // 0x8008D138: nop

        goto L_8008D17C;
    // 0x8008D138: nop

L_8008D13C:
    // 0x8008D13C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D140: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D144: jal         0x8008D728
    // 0x8008D148: nop

    func_8008D728(rdram, ctx);
        goto after_1;
    // 0x8008D148: nop

    after_1:
    // 0x8008D14C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8008D150: b           L_8008D17C
    // 0x8008D154: nop

        goto L_8008D17C;
    // 0x8008D154: nop

L_8008D158:
    // 0x8008D158: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D15C: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D160: jal         0x8008D9E4
    // 0x8008D164: nop

    func_8008D9E4(rdram, ctx);
        goto after_2;
    // 0x8008D164: nop

    after_2:
    // 0x8008D168: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8008D16C: b           L_8008D17C
    // 0x8008D170: nop

        goto L_8008D17C;
    // 0x8008D170: nop

L_8008D174:
    // 0x8008D174: b           L_8008D22C
    // 0x8008D178: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008D22C;
    // 0x8008D178: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008D17C:
    // 0x8008D17C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008D180: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x8008D184: nop

    // 0x8008D188: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8008D18C: nop

    // 0x8008D190: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8008D194: beq         $t9, $zero, L_8008D1CC
    if (ctx->r25 == 0) {
        // 0x8008D198: nop

            goto L_8008D1CC;
    }
    // 0x8008D198: nop

    // 0x8008D19C: jal         0x800C1754
    // 0x8008D1A0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_3;
    // 0x8008D1A0: nop

    after_3:
    // 0x8008D1A4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D1A8: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D1AC: jal         0x8009A14C
    // 0x8008D1B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8009A14C(rdram, ctx);
        goto after_4;
    // 0x8008D1B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_4:
    // 0x8008D1B4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D1B8: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D1BC: jal         0x800997D8
    // 0x8008D1C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800997D8(rdram, ctx);
        goto after_5;
    // 0x8008D1C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_5:
    // 0x8008D1C4: jal         0x800C1A28
    // 0x8008D1C8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x8008D1C8: nop

    after_6:
L_8008D1CC:
    // 0x8008D1CC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8008D1D0: lw          $t1, -0x76BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76BC);
    // 0x8008D1D4: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x8008D1D8: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8008D1DC: nop

    // 0x8008D1E0: beq         $t0, $t2, L_8008D20C
    if (ctx->r8 == ctx->r10) {
        // 0x8008D1E4: nop

            goto L_8008D20C;
    }
    // 0x8008D1E4: nop

    // 0x8008D1E8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8008D1EC: lw          $t4, -0x76BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76BC);
    // 0x8008D1F0: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8008D1F4: nop

    // 0x8008D1F8: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x8008D1FC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D200: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D204: jal         0x8008D29C
    // 0x8008D208: nop

    func_8008D29C(rdram, ctx);
        goto after_7;
    // 0x8008D208: nop

    after_7:
L_8008D20C:
    // 0x8008D20C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D210: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D214: jal         0x8008DB7C
    // 0x8008D218: nop

    func_8008DB7C(rdram, ctx);
        goto after_8;
    // 0x8008D218: nop

    after_8:
    // 0x8008D21C: b           L_8008D22C
    // 0x8008D220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D22C;
    // 0x8008D220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D224: b           L_8008D22C
    // 0x8008D228: nop

        goto L_8008D22C;
    // 0x8008D228: nop

L_8008D22C:
    // 0x8008D22C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008D234: jr          $ra
    // 0x8008D238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008D238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8008D23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D23C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D244: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D248: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D24C: jal         0x8001AE90
    // 0x8008D250: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001AE90(rdram, ctx);
        goto after_0;
    // 0x8008D250: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_0:
    // 0x8008D254: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D258: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8008D25C: nop

    // 0x8008D260: lw          $a0, 0x3A8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3A8);
    // 0x8008D264: jal         0x800BC980
    // 0x8008D268: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x8008D268: nop

    after_1:
    // 0x8008D26C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D270: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D274: jal         0x800BC980
    // 0x8008D278: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8008D278: nop

    after_2:
    // 0x8008D27C: b           L_8008D28C
    // 0x8008D280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D28C;
    // 0x8008D280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D284: b           L_8008D28C
    // 0x8008D288: nop

        goto L_8008D28C;
    // 0x8008D288: nop

L_8008D28C:
    // 0x8008D28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D294: jr          $ra
    // 0x8008D298: nop

    return;
    // 0x8008D298: nop

;}
RECOMP_FUNC void func_8008D29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D29C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008D2A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008D2A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008D2A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008D2AC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008D2B0: nop

    // 0x8008D2B4: lh          $s0, 0x2($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X2);
    // 0x8008D2B8: nop

    // 0x8008D2BC: beq         $s0, $zero, L_8008D2F0
    if (ctx->r16 == 0) {
        // 0x8008D2C0: nop

            goto L_8008D2F0;
    }
    // 0x8008D2C0: nop

    // 0x8008D2C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D2C8: beq         $s0, $at, L_8008D304
    if (ctx->r16 == ctx->r1) {
        // 0x8008D2CC: nop

            goto L_8008D304;
    }
    // 0x8008D2CC: nop

    // 0x8008D2D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008D2D4: beq         $s0, $at, L_8008D318
    if (ctx->r16 == ctx->r1) {
        // 0x8008D2D8: nop

            goto L_8008D318;
    }
    // 0x8008D2D8: nop

    // 0x8008D2DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008D2E0: beq         $s0, $at, L_8008D32C
    if (ctx->r16 == ctx->r1) {
        // 0x8008D2E4: nop

            goto L_8008D32C;
    }
    // 0x8008D2E4: nop

    // 0x8008D2E8: b           L_8008D334
    // 0x8008D2EC: nop

        goto L_8008D334;
    // 0x8008D2EC: nop

L_8008D2F0:
    // 0x8008D2F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008D2F4: jal         0x8008D34C
    // 0x8008D2F8: nop

    func_8008D34C(rdram, ctx);
        goto after_0;
    // 0x8008D2F8: nop

    after_0:
    // 0x8008D2FC: b           L_8008D334
    // 0x8008D300: nop

        goto L_8008D334;
    // 0x8008D300: nop

L_8008D304:
    // 0x8008D304: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008D308: jal         0x8008D708
    // 0x8008D30C: nop

    func_8008D708(rdram, ctx);
        goto after_1;
    // 0x8008D30C: nop

    after_1:
    // 0x8008D310: b           L_8008D334
    // 0x8008D314: nop

        goto L_8008D334;
    // 0x8008D314: nop

L_8008D318:
    // 0x8008D318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008D31C: jal         0x8008D90C
    // 0x8008D320: nop

    func_8008D90C(rdram, ctx);
        goto after_2;
    // 0x8008D320: nop

    after_2:
    // 0x8008D324: b           L_8008D334
    // 0x8008D328: nop

        goto L_8008D334;
    // 0x8008D328: nop

L_8008D32C:
    // 0x8008D32C: b           L_8008D334
    // 0x8008D330: nop

        goto L_8008D334;
    // 0x8008D330: nop

L_8008D334:
    // 0x8008D334: b           L_8008D33C
    // 0x8008D338: nop

        goto L_8008D33C;
    // 0x8008D338: nop

L_8008D33C:
    // 0x8008D33C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008D344: jr          $ra
    // 0x8008D348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008D348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8008D34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D34C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008D350: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D354: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008D358: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8008D35C: beq         $t6, $zero, L_8008D42C
    if (ctx->r14 == 0) {
        // 0x8008D360: sw          $t6, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r14;
            goto L_8008D42C;
    }
    // 0x8008D360: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
L_8008D364:
    // 0x8008D364: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8008D368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D36C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8008D370: nop

    // 0x8008D374: swc1        $f4, 0xE8($t7)
    MEM_W(0XE8, ctx->r15) = ctx->f4.u32l;
    // 0x8008D378: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8008D37C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008D380: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008D384: nop

    // 0x8008D388: swc1        $f6, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f6.u32l;
    // 0x8008D38C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008D390: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008D394: lwc1        $f8, 0xE8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XE8);
    // 0x8008D398: lwc1        $f17, -0xA10($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XA10);
    // 0x8008D39C: lwc1        $f16, -0xA0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XA0C);
    // 0x8008D3A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8008D3A4: nop

    // 0x8008D3A8: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8008D3AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8008D3B0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8008D3B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008D3B8: nop

    // 0x8008D3BC: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x8008D3C0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8008D3C4: swc1        $f12, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f12.u32l;
    // 0x8008D3C8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008D3CC: nop

    // 0x8008D3D0: swc1        $f12, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->f12.u32l;
    // 0x8008D3D4: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008D3D8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8008D3DC: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x8008D3E0: nop

    // 0x8008D3E4: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8008D3E8: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
    // 0x8008D3EC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008D3F0: nop

    // 0x8008D3F4: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x8008D3F8: nop

    // 0x8008D3FC: ori         $t6, $t5, 0x810
    ctx->r14 = ctx->r13 | 0X810;
    // 0x8008D400: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x8008D404: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8008D408: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008D40C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008D410: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8008D414: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x8008D418: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8008D41C: beq         $at, $zero, L_8008D42C
    if (ctx->r1 == 0) {
        // 0x8008D420: sw          $t8, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r24;
            goto L_8008D42C;
    }
    // 0x8008D420: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8008D424: bne         $t0, $zero, L_8008D364
    if (ctx->r8 != 0) {
        // 0x8008D428: nop

            goto L_8008D364;
    }
    // 0x8008D428: nop

L_8008D42C:
    // 0x8008D42C: lw          $t2, 0x230($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X230);
    // 0x8008D430: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8008D434: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8008D438: sw          $t3, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r11;
    // 0x8008D43C: lw          $t1, 0x230($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X230);
    // 0x8008D440: nop

    // 0x8008D444: ori         $t5, $t1, 0x810
    ctx->r13 = ctx->r9 | 0X810;
    // 0x8008D448: sw          $t5, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r13;
    // 0x8008D44C: b           L_8008D454
    // 0x8008D450: nop

        goto L_8008D454;
    // 0x8008D450: nop

L_8008D454:
    // 0x8008D454: jr          $ra
    // 0x8008D458: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008D458: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8008D45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D45C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008D460: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D464: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008D468: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8008D46C: lwc1        $f4, 0xE8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8008D470: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008D474: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008D478: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8008D47C: nop

    // 0x8008D480: bc1f        L_8008D5D0
    if (!c1cs) {
        // 0x8008D484: nop

            goto L_8008D5D0;
    }
    // 0x8008D484: nop

    // 0x8008D488: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008D48C: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008D490: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8008D494: beq         $t7, $zero, L_8008D584
    if (ctx->r15 == 0) {
        // 0x8008D498: sw          $t7, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r15;
            goto L_8008D584;
    }
    // 0x8008D498: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_8008D49C:
    // 0x8008D49C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8008D4A0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8008D4A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008D4A8: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008D4AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008D4B0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8008D4B4: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8008D4B8: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008D4BC: nop

    // 0x8008D4C0: lwc1        $f6, 0xE8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8008D4C4: nop

    // 0x8008D4C8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008D4CC: sub.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = ctx->f8.d - ctx->f4.d;
    // 0x8008D4D0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8008D4D4: swc1        $f10, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f10.u32l;
    // 0x8008D4D8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8008D4DC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008D4E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008D4E4: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008D4E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008D4EC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008D4F0: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8008D4F4: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008D4F8: nop

    // 0x8008D4FC: lwc1        $f16, 0xF0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x8008D500: nop

    // 0x8008D504: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8008D508: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x8008D50C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8008D510: swc1        $f18, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f18.u32l;
    // 0x8008D514: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008D518: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008D51C: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8008D520: lwc1        $f11, -0xA08($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XA08);
    // 0x8008D524: lwc1        $f10, -0xA04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XA04);
    // 0x8008D528: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8008D52C: nop

    // 0x8008D530: div.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x8008D534: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8008D538: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008D53C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008D540: nop

    // 0x8008D544: sub.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f18.d = ctx->f6.d - ctx->f4.d;
    // 0x8008D548: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x8008D54C: swc1        $f12, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f12.u32l;
    // 0x8008D550: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008D554: nop

    // 0x8008D558: swc1        $f12, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f12.u32l;
    // 0x8008D55C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8008D560: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008D564: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008D568: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8008D56C: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x8008D570: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x8008D574: beq         $at, $zero, L_8008D584
    if (ctx->r1 == 0) {
        // 0x8008D578: sw          $t3, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r11;
            goto L_8008D584;
    }
    // 0x8008D578: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x8008D57C: bne         $t5, $zero, L_8008D49C
    if (ctx->r13 != 0) {
        // 0x8008D580: nop

            goto L_8008D49C;
    }
    // 0x8008D580: nop

L_8008D584:
    // 0x8008D584: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D588: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008D58C: nop

    // 0x8008D590: lwc1        $f12, 0xF4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XF4);
    // 0x8008D594: nop

    // 0x8008D598: swc1        $f12, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->f12.u32l;
    // 0x8008D59C: swc1        $f12, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->f12.u32l;
    // 0x8008D5A0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008D5A4: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008D5A8: nop

    // 0x8008D5AC: lwc1        $f8, 0xE8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x8008D5B0: nop

    // 0x8008D5B4: swc1        $f8, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->f8.u32l;
    // 0x8008D5B8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008D5BC: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8008D5C0: nop

    // 0x8008D5C4: lwc1        $f16, 0xF0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8008D5C8: b           L_8008D6F0
    // 0x8008D5CC: swc1        $f16, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f16.u32l;
        goto L_8008D6F0;
    // 0x8008D5CC: swc1        $f16, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f16.u32l;
L_8008D5D0:
    // 0x8008D5D0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008D5D4: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8008D5D8: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8008D5DC: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
L_8008D5E0:
    // 0x8008D5E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008D5E4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008D5E8: nop

    // 0x8008D5EC: swc1        $f10, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f10.u32l;
    // 0x8008D5F0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008D5F4: nop

    // 0x8008D5F8: lwc1        $f6, 0xF0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XF0);
    // 0x8008D5FC: nop

    // 0x8008D600: swc1        $f6, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f6.u32l;
    // 0x8008D604: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8008D608: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8008D60C: lw          $t4, 0xC0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC0);
    // 0x8008D610: nop

    // 0x8008D614: and         $t3, $t4, $at
    ctx->r11 = ctx->r12 & ctx->r1;
    // 0x8008D618: sw          $t3, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r11;
    // 0x8008D61C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8008D620: nop

    // 0x8008D624: lw          $t6, 0xC0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC0);
    // 0x8008D628: nop

    // 0x8008D62C: ori         $t7, $t6, 0x48
    ctx->r15 = ctx->r14 | 0X48;
    // 0x8008D630: sw          $t7, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r15;
    // 0x8008D634: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008D638: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D63C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008D640: nop

    // 0x8008D644: swc1        $f4, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f4.u32l;
    // 0x8008D648: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008D64C: nop

    // 0x8008D650: lwc1        $f18, 0xF8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x8008D654: nop

    // 0x8008D658: swc1        $f18, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f18.u32l;
    // 0x8008D65C: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x8008D660: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008D664: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008D668: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8008D66C: addiu       $t3, $t4, 0x160
    ctx->r11 = ADD32(ctx->r12, 0X160);
    // 0x8008D670: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8008D674: bne         $at, $zero, L_8008D5E0
    if (ctx->r1 != 0) {
        // 0x8008D678: sw          $t1, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r9;
            goto L_8008D5E0;
    }
    // 0x8008D678: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8008D67C: lw          $t2, 0x230($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X230);
    // 0x8008D680: addiu       $at, $zero, -0x811
    ctx->r1 = ADD32(0, -0X811);
    // 0x8008D684: and         $t6, $t2, $at
    ctx->r14 = ctx->r10 & ctx->r1;
    // 0x8008D688: sw          $t6, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r14;
    // 0x8008D68C: lw          $t7, 0x230($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X230);
    // 0x8008D690: nop

    // 0x8008D694: ori         $t5, $t7, 0x48
    ctx->r13 = ctx->r15 | 0X48;
    // 0x8008D698: sw          $t5, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r13;
    // 0x8008D69C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008D6A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008D6A4: nop

    // 0x8008D6A8: swc1        $f8, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->f8.u32l;
    // 0x8008D6AC: lwc1        $f16, 0x268($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X268);
    // 0x8008D6B0: nop

    // 0x8008D6B4: swc1        $f16, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->f16.u32l;
    // 0x8008D6B8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008D6BC: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8008D6C0: nop

    // 0x8008D6C4: lwc1        $f10, 0xE8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8008D6C8: nop

    // 0x8008D6CC: swc1        $f10, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->f10.u32l;
    // 0x8008D6D0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8008D6D4: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8008D6D8: nop

    // 0x8008D6DC: lwc1        $f6, 0xF0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x8008D6E0: nop

    // 0x8008D6E4: swc1        $f6, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f6.u32l;
    // 0x8008D6E8: b           L_8008D700
    // 0x8008D6EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008D700;
    // 0x8008D6EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008D6F0:
    // 0x8008D6F0: b           L_8008D700
    // 0x8008D6F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D700;
    // 0x8008D6F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D6F8: b           L_8008D700
    // 0x8008D6FC: nop

        goto L_8008D700;
    // 0x8008D6FC: nop

L_8008D700:
    // 0x8008D700: jr          $ra
    // 0x8008D704: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008D704: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8008D708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D708: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8008D70C: nop

    // 0x8008D710: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8008D714: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8008D718: jr          $ra
    // 0x8008D71C: nop

    return;
    // 0x8008D71C: nop

    // 0x8008D720: jr          $ra
    // 0x8008D724: nop

    return;
    // 0x8008D724: nop

;}
RECOMP_FUNC void func_8008D728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D72C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D738: jal         0x8008E0A8
    // 0x8008D73C: nop

    func_8008E0A8(rdram, ctx);
        goto after_0;
    // 0x8008D73C: nop

    after_0:
    // 0x8008D740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D744: jal         0x8008E380
    // 0x8008D748: nop

    func_8008E380(rdram, ctx);
        goto after_1;
    // 0x8008D748: nop

    after_1:
    // 0x8008D74C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008D750: nop

    // 0x8008D754: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008D758: nop

    // 0x8008D75C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8008D760: beq         $t8, $zero, L_8008D790
    if (ctx->r24 == 0) {
        // 0x8008D764: nop

            goto L_8008D790;
    }
    // 0x8008D764: nop

    // 0x8008D768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D76C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008D770: jal         0x8008E184
    // 0x8008D774: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8008E184(rdram, ctx);
        goto after_2;
    // 0x8008D774: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_2:
    // 0x8008D778: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008D77C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8008D780: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8008D784: nop

    // 0x8008D788: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8008D78C: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_8008D790:
    // 0x8008D790: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008D794: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8008D798: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008D79C: lhu         $t3, 0xFF4($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XFF4);
    // 0x8008D7A0: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x8008D7A4: lhu         $t6, 0x3B0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X3B0);
    // 0x8008D7A8: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8008D7AC: and         $t7, $t6, $t4
    ctx->r15 = ctx->r14 & ctx->r12;
    // 0x8008D7B0: beq         $t7, $zero, L_8008D858
    if (ctx->r15 == 0) {
        // 0x8008D7B4: nop

            goto L_8008D858;
    }
    // 0x8008D7B4: nop

    // 0x8008D7B8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008D7BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D7C0: lh          $t0, 0x168($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X168);
    // 0x8008D7C4: nop

    // 0x8008D7C8: bne         $t0, $at, L_8008D7E0
    if (ctx->r8 != ctx->r1) {
        // 0x8008D7CC: nop

            goto L_8008D7E0;
    }
    // 0x8008D7CC: nop

    // 0x8008D7D0: jal         0x800B9000
    // 0x8008D7D4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8008D7D4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x8008D7D8: b           L_8008D8FC
    // 0x8008D7DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008D8FC;
    // 0x8008D7DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8008D7E0:
    // 0x8008D7E0: jal         0x800B9000
    // 0x8008D7E4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_800B9000(rdram, ctx);
        goto after_4;
    // 0x8008D7E4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x8008D7E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D7EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008D7F0: jal         0x8008E184
    // 0x8008D7F4: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8008E184(rdram, ctx);
        goto after_5;
    // 0x8008D7F4: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_5:
    // 0x8008D7F8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008D7FC: nop

    // 0x8008D800: lhu         $t9, 0x0($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X0);
    // 0x8008D804: nop

    // 0x8008D808: ori         $t2, $t9, 0x2
    ctx->r10 = ctx->r25 | 0X2;
    // 0x8008D80C: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x8008D810: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008D814: nop

    // 0x8008D818: lhu         $t5, 0x4($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X4);
    // 0x8008D81C: nop

    // 0x8008D820: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008D824: sh          $t6, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r14;
    // 0x8008D828: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008D82C: nop

    // 0x8008D830: lhu         $t7, 0x4($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X4);
    // 0x8008D834: lh          $t0, 0x3AC($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X3AC);
    // 0x8008D838: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008D83C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008D840: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8008D844: bne         $at, $zero, L_8008D858
    if (ctx->r1 != 0) {
        // 0x8008D848: nop

            goto L_8008D858;
    }
    // 0x8008D848: nop

    // 0x8008D84C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008D850: nop

    // 0x8008D854: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
L_8008D858:
    // 0x8008D858: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008D85C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008D860: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8008D864: lhu         $t1, 0x3B0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X3B0);
    // 0x8008D868: nop

    // 0x8008D86C: and         $t6, $t1, $t5
    ctx->r14 = ctx->r9 & ctx->r13;
    // 0x8008D870: beq         $t6, $zero, L_8008D888
    if (ctx->r14 == 0) {
        // 0x8008D874: nop

            goto L_8008D888;
    }
    // 0x8008D874: nop

    // 0x8008D878: jal         0x800B9000
    // 0x8008D87C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_6;
    // 0x8008D87C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_6:
    // 0x8008D880: b           L_8008D8FC
    // 0x8008D884: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008D8FC;
    // 0x8008D884: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8008D888:
    // 0x8008D888: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008D88C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008D890: lhu         $t4, 0xEEC($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XEEC);
    // 0x8008D894: lhu         $t7, 0x3AE($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X3AE);
    // 0x8008D898: nop

    // 0x8008D89C: and         $t8, $t7, $t4
    ctx->r24 = ctx->r15 & ctx->r12;
    // 0x8008D8A0: beq         $t8, $zero, L_8008D8B4
    if (ctx->r24 == 0) {
        // 0x8008D8A4: nop

            goto L_8008D8B4;
    }
    // 0x8008D8A4: nop

    // 0x8008D8A8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008D8AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008D8B0: sh          $t0, 0x168($t9)
    MEM_H(0X168, ctx->r25) = ctx->r8;
L_8008D8B4:
    // 0x8008D8B4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008D8B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008D8BC: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x8008D8C0: lhu         $t1, 0x3AE($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X3AE);
    // 0x8008D8C4: nop

    // 0x8008D8C8: and         $t6, $t1, $t5
    ctx->r14 = ctx->r9 & ctx->r13;
    // 0x8008D8CC: beq         $t6, $zero, L_8008D8E0
    if (ctx->r14 == 0) {
        // 0x8008D8D0: nop

            goto L_8008D8E0;
    }
    // 0x8008D8D0: nop

    // 0x8008D8D4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008D8D8: nop

    // 0x8008D8DC: sh          $zero, 0x168($t3)
    MEM_H(0X168, ctx->r11) = 0;
L_8008D8E0:
    // 0x8008D8E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D8E4: jal         0x8008DFA8
    // 0x8008D8E8: nop

    func_8008DFA8(rdram, ctx);
        goto after_7;
    // 0x8008D8E8: nop

    after_7:
    // 0x8008D8EC: b           L_8008D8FC
    // 0x8008D8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008D8FC;
    // 0x8008D8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008D8F4: b           L_8008D8FC
    // 0x8008D8F8: nop

        goto L_8008D8FC;
    // 0x8008D8F8: nop

L_8008D8FC:
    // 0x8008D8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D904: jr          $ra
    // 0x8008D908: nop

    return;
    // 0x8008D908: nop

;}
RECOMP_FUNC void func_8008D90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D90C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008D910: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8008D914: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008D918: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8008D91C: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8008D920: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008D924: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8008D928: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8008D92C: beq         $t8, $zero, L_8008D9B4
    if (ctx->r24 == 0) {
        // 0x8008D930: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_8008D9B4;
    }
    // 0x8008D930: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_8008D934:
    // 0x8008D934: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8008D938: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D93C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008D940: nop

    // 0x8008D944: swc1        $f4, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f4.u32l;
    // 0x8008D948: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008D94C: nop

    // 0x8008D950: lwc1        $f6, 0xF0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x8008D954: nop

    // 0x8008D958: swc1        $f6, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f6.u32l;
    // 0x8008D95C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8008D960: addiu       $at, $zero, -0x49
    ctx->r1 = ADD32(0, -0X49);
    // 0x8008D964: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x8008D968: nop

    // 0x8008D96C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8008D970: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
    // 0x8008D974: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8008D978: nop

    // 0x8008D97C: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x8008D980: nop

    // 0x8008D984: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8008D988: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x8008D98C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8008D990: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008D994: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008D998: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8008D99C: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x8008D9A0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8008D9A4: beq         $at, $zero, L_8008D9B4
    if (ctx->r1 == 0) {
        // 0x8008D9A8: sw          $t8, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r24;
            goto L_8008D9B4;
    }
    // 0x8008D9A8: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8008D9AC: bne         $t0, $zero, L_8008D934
    if (ctx->r8 != 0) {
        // 0x8008D9B0: nop

            goto L_8008D934;
    }
    // 0x8008D9B0: nop

L_8008D9B4:
    // 0x8008D9B4: lw          $t2, 0x230($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X230);
    // 0x8008D9B8: addiu       $at, $zero, -0x49
    ctx->r1 = ADD32(0, -0X49);
    // 0x8008D9BC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8008D9C0: sw          $t3, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r11;
    // 0x8008D9C4: lw          $t1, 0x230($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X230);
    // 0x8008D9C8: nop

    // 0x8008D9CC: ori         $t5, $t1, 0x10
    ctx->r13 = ctx->r9 | 0X10;
    // 0x8008D9D0: sw          $t5, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r13;
    // 0x8008D9D4: b           L_8008D9DC
    // 0x8008D9D8: nop

        goto L_8008D9DC;
    // 0x8008D9D8: nop

L_8008D9DC:
    // 0x8008D9DC: jr          $ra
    // 0x8008D9E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008D9E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008D9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D9E4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008D9E8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D9EC: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008D9F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008D9F4: lwc1        $f4, 0xE8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8008D9F8: lwc1        $f9, -0xA00($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0XA00);
    // 0x8008D9FC: lwc1        $f8, -0x9FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X9FC);
    // 0x8008DA00: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008DA04: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8008DA08: nop

    // 0x8008DA0C: bc1f        L_8008DB5C
    if (!c1cs) {
        // 0x8008DA10: nop

            goto L_8008DB5C;
    }
    // 0x8008DA10: nop

    // 0x8008DA14: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008DA18: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008DA1C: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8008DA20: beq         $t7, $zero, L_8008DB10
    if (ctx->r15 == 0) {
        // 0x8008DA24: sw          $t7, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r15;
            goto L_8008DB10;
    }
    // 0x8008DA24: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_8008DA28:
    // 0x8008DA28: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8008DA2C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8008DA30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008DA34: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008DA38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008DA3C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8008DA40: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8008DA44: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008DA48: nop

    // 0x8008DA4C: lwc1        $f6, 0xE8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8008DA50: nop

    // 0x8008DA54: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008DA58: sub.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = ctx->f8.d - ctx->f4.d;
    // 0x8008DA5C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8008DA60: swc1        $f10, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f10.u32l;
    // 0x8008DA64: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8008DA68: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008DA6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008DA70: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008DA74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008DA78: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008DA7C: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8008DA80: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008DA84: nop

    // 0x8008DA88: lwc1        $f16, 0xF0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x8008DA8C: nop

    // 0x8008DA90: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8008DA94: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x8008DA98: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8008DA9C: swc1        $f18, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f18.u32l;
    // 0x8008DAA0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008DAA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008DAA8: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8008DAAC: lwc1        $f11, -0x9F8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X9F8);
    // 0x8008DAB0: lwc1        $f10, -0x9F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X9F4);
    // 0x8008DAB4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8008DAB8: nop

    // 0x8008DABC: div.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f10.d);
    // 0x8008DAC0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8008DAC4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008DAC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008DACC: nop

    // 0x8008DAD0: sub.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f18.d = ctx->f6.d - ctx->f4.d;
    // 0x8008DAD4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x8008DAD8: swc1        $f12, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f12.u32l;
    // 0x8008DADC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008DAE0: nop

    // 0x8008DAE4: swc1        $f12, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f12.u32l;
    // 0x8008DAE8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8008DAEC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008DAF0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008DAF4: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8008DAF8: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x8008DAFC: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x8008DB00: beq         $at, $zero, L_8008DB10
    if (ctx->r1 == 0) {
        // 0x8008DB04: sw          $t3, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r11;
            goto L_8008DB10;
    }
    // 0x8008DB04: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x8008DB08: bne         $t5, $zero, L_8008DA28
    if (ctx->r13 != 0) {
        // 0x8008DB0C: nop

            goto L_8008DA28;
    }
    // 0x8008DB0C: nop

L_8008DB10:
    // 0x8008DB10: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008DB14: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008DB18: nop

    // 0x8008DB1C: lwc1        $f12, 0xF4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XF4);
    // 0x8008DB20: nop

    // 0x8008DB24: swc1        $f12, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->f12.u32l;
    // 0x8008DB28: swc1        $f12, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->f12.u32l;
    // 0x8008DB2C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008DB30: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008DB34: nop

    // 0x8008DB38: lwc1        $f8, 0xE8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x8008DB3C: nop

    // 0x8008DB40: swc1        $f8, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->f8.u32l;
    // 0x8008DB44: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008DB48: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8008DB4C: nop

    // 0x8008DB50: lwc1        $f16, 0xF0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8008DB54: b           L_8008DB64
    // 0x8008DB58: swc1        $f16, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f16.u32l;
        goto L_8008DB64;
    // 0x8008DB58: swc1        $f16, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f16.u32l;
L_8008DB5C:
    // 0x8008DB5C: b           L_8008DB74
    // 0x8008DB60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8008DB74;
    // 0x8008DB60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8008DB64:
    // 0x8008DB64: b           L_8008DB74
    // 0x8008DB68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008DB74;
    // 0x8008DB68: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8008DB6C: b           L_8008DB74
    // 0x8008DB70: nop

        goto L_8008DB74;
    // 0x8008DB70: nop

L_8008DB74:
    // 0x8008DB74: jr          $ra
    // 0x8008DB78: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008DB78: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8008DB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DB7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008DB80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DB84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008DB88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DB8C: jal         0x8001ABEC
    // 0x8008DB90: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001ABEC(rdram, ctx);
        goto after_0;
    // 0x8008DB90: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_0:
    // 0x8008DB94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008DB98:
    // 0x8008DB98: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008DB9C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DBA0: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8008DBA4: nop

    // 0x8008DBA8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008DBAC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008DBB0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8008DBB4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8008DBB8: lh          $t1, 0x3AC($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X3AC);
    // 0x8008DBBC: nop

    // 0x8008DBC0: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8008DBC4: bne         $at, $zero, L_8008DBD4
    if (ctx->r1 != 0) {
        // 0x8008DBC8: nop

            goto L_8008DBD4;
    }
    // 0x8008DBC8: nop

    // 0x8008DBCC: b           L_8008DC7C
    // 0x8008DBD0: nop

        goto L_8008DC7C;
    // 0x8008DBD0: nop

L_8008DBD4:
    // 0x8008DBD4: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8008DBD8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DBDC: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x8008DBE0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DBE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DBE8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8008DBEC: addiu       $t5, $t4, 0x11
    ctx->r13 = ADD32(ctx->r12, 0X11);
    // 0x8008DBF0: sw          $t5, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r13;
    // 0x8008DBF4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8008DBF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008DBFC: addiu       $a0, $a0, -0xA20
    ctx->r4 = ADD32(ctx->r4, -0XA20);
    // 0x8008DC00: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x8008DC04: jal         0x8008ECE4
    // 0x8008DC08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8008DC08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_1:
    // 0x8008DC0C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008DC10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008DC14: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008DC18: lbu         $a0, 0x4C20($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4C20);
    // 0x8008DC1C: jal         0x8005F064
    // 0x8008DC20: nop

    func_8005F064(rdram, ctx);
        goto after_2;
    // 0x8008DC20: nop

    after_2:
    // 0x8008DC24: bne         $v0, $zero, L_8008DC34
    if (ctx->r2 != 0) {
        // 0x8008DC28: nop

            goto L_8008DC34;
    }
    // 0x8008DC28: nop

    // 0x8008DC2C: b           L_8008DC64
    // 0x8008DC30: nop

        goto L_8008DC64;
    // 0x8008DC30: nop

L_8008DC34:
    // 0x8008DC34: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x8008DC38: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DC3C: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x8008DC40: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DC44: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DC48: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8008DC4C: addiu       $t0, $t6, 0x11
    ctx->r8 = ADD32(ctx->r14, 0X11);
    // 0x8008DC50: sw          $t0, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r8;
    // 0x8008DC54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DC58: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008DC5C: jal         0x8008DE78
    // 0x8008DC60: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008DE78(rdram, ctx);
        goto after_3;
    // 0x8008DC60: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_3:
L_8008DC64:
    // 0x8008DC64: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DC68: nop

    // 0x8008DC6C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008DC70: slti        $at, $t2, 0x7
    ctx->r1 = SIGNED(ctx->r10) < 0X7 ? 1 : 0;
    // 0x8008DC74: bne         $at, $zero, L_8008DB98
    if (ctx->r1 != 0) {
        // 0x8008DC78: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8008DB98;
    }
    // 0x8008DC78: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_8008DC7C:
    // 0x8008DC7C: addiu       $t3, $zero, 0x55
    ctx->r11 = ADD32(0, 0X55);
    // 0x8008DC80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DC84: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x8008DC88: addiu       $t4, $zero, 0x84
    ctx->r12 = ADD32(0, 0X84);
    // 0x8008DC8C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DC90: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x8008DC94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DC98: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8008DC9C: jal         0x8008DE78
    // 0x8008DCA0: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    func_8008DE78(rdram, ctx);
        goto after_4;
    // 0x8008DCA0: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    after_4:
    // 0x8008DCA4: addiu       $t5, $zero, 0x88
    ctx->r13 = ADD32(0, 0X88);
    // 0x8008DCA8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DCAC: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x8008DCB0: addiu       $t7, $zero, 0x84
    ctx->r15 = ADD32(0, 0X84);
    // 0x8008DCB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008DCB8: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x8008DCBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DCC0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8008DCC4: jal         0x8008DE78
    // 0x8008DCC8: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    func_8008DE78(rdram, ctx);
        goto after_5;
    // 0x8008DCC8: addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    after_5:
    // 0x8008DCCC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8008DCD0: nop

    // 0x8008DCD4: lw          $t9, 0x2A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2A8);
    // 0x8008DCD8: nop

    // 0x8008DCDC: sh          $zero, 0x20($t9)
    MEM_H(0X20, ctx->r25) = 0;
    // 0x8008DCE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DCE4: jal         0x8001ACDC
    // 0x8008DCE8: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001ACDC(rdram, ctx);
        goto after_6;
    // 0x8008DCE8: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_6:
    // 0x8008DCEC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008DCF0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8008DCF4: lw          $t0, 0x230($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X230);
    // 0x8008DCF8: nop

    // 0x8008DCFC: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8008DD00: sw          $t1, 0x230($t6)
    MEM_W(0X230, ctx->r14) = ctx->r9;
    // 0x8008DD04: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008DD08: nop

    // 0x8008DD0C: lw          $t3, 0x230($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X230);
    // 0x8008DD10: nop

    // 0x8008DD14: ori         $t4, $t3, 0x810
    ctx->r12 = ctx->r11 | 0X810;
    // 0x8008DD18: sw          $t4, 0x230($t2)
    MEM_W(0X230, ctx->r10) = ctx->r12;
    // 0x8008DD1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008DD20: jal         0x8001ADBC
    // 0x8008DD24: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    func_8001ADBC(rdram, ctx);
        goto after_7;
    // 0x8008DD24: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_7:
    // 0x8008DD28: b           L_8008DD30
    // 0x8008DD2C: nop

        goto L_8008DD30;
    // 0x8008DD2C: nop

L_8008DD30:
    // 0x8008DD30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DD34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008DD38: jr          $ra
    // 0x8008DD3C: nop

    return;
    // 0x8008DD3C: nop

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
RECOMP_FUNC void func_8008DE78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DE78: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008DE7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DE80: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8008DE84: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8008DE88: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8008DE8C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008DE90: lhu         $a2, 0x4E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X4E);
    // 0x8008DE94: jal         0x8008DEC8
    // 0x8008DE98: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008DEC8(rdram, ctx);
        goto after_0;
    // 0x8008DE98: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8008DE9C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008DEA0: lhu         $a1, 0x52($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X52);
    // 0x8008DEA4: addiu       $a0, $a0, -0xA18
    ctx->r4 = ADD32(ctx->r4, -0XA18);
    // 0x8008DEA8: jal         0x8008ECE4
    // 0x8008DEAC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8008DEAC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8008DEB0: b           L_8008DEB8
    // 0x8008DEB4: nop

        goto L_8008DEB8;
    // 0x8008DEB4: nop

L_8008DEB8:
    // 0x8008DEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DEBC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008DEC0: jr          $ra
    // 0x8008DEC4: nop

    return;
    // 0x8008DEC4: nop

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
RECOMP_FUNC void func_8008DFA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DFA8: lh          $t6, 0x168($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X168);
    // 0x8008DFAC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008DFB0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8008DFB4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008DFB8: lh          $t8, 0x4C3C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X4C3C);
    // 0x8008DFBC: nop

    // 0x8008DFC0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008DFC4: nop

    // 0x8008DFC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008DFCC: swc1        $f6, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->f6.u32l;
    // 0x8008DFD0: lh          $t9, 0x168($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X168);
    // 0x8008DFD4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008DFD8: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8008DFDC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8008DFE0: lh          $t1, 0x4C3E($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4C3E);
    // 0x8008DFE4: nop

    // 0x8008DFE8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8008DFEC: nop

    // 0x8008DFF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008DFF4: swc1        $f10, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->f10.u32l;
    // 0x8008DFF8: lh          $t2, 0x168($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X168);
    // 0x8008DFFC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008E000: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8008E004: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8008E008: lh          $t4, 0x4C40($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X4C40);
    // 0x8008E00C: nop

    // 0x8008E010: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8008E014: nop

    // 0x8008E018: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008E01C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8008E020: nop

    // 0x8008E024: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8008E028: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008E02C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008E030: nop

    // 0x8008E034: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8008E038: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8008E03C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8008E040: sh          $t6, 0x108($a0)
    MEM_H(0X108, ctx->r4) = ctx->r14;
    // 0x8008E044: nop

    // 0x8008E048: lh          $t7, 0x168($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X168);
    // 0x8008E04C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008E050: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008E054: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008E058: lh          $t9, 0x4C42($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4C42);
    // 0x8008E05C: nop

    // 0x8008E060: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8008E064: nop

    // 0x8008E068: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008E06C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8008E070: nop

    // 0x8008E074: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8008E078: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008E07C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008E080: nop

    // 0x8008E084: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008E088: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8008E08C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8008E090: sh          $t1, 0x10A($a0)
    MEM_H(0X10A, ctx->r4) = ctx->r9;
    // 0x8008E094: nop

    // 0x8008E098: jr          $ra
    // 0x8008E09C: nop

    return;
    // 0x8008E09C: nop

    // 0x8008E0A0: jr          $ra
    // 0x8008E0A4: nop

    return;
    // 0x8008E0A4: nop

;}
RECOMP_FUNC void func_8008E0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E0A8: lh          $t6, 0x126($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X126);
    // 0x8008E0AC: lh          $t7, 0x16A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X16A);
    // 0x8008E0B0: nop

    // 0x8008E0B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008E0B8: sh          $t8, 0x126($a0)
    MEM_H(0X126, ctx->r4) = ctx->r24;
    // 0x8008E0BC: lh          $t9, 0x126($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X126);
    // 0x8008E0C0: nop

    // 0x8008E0C4: bgez        $t9, L_8008E114
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8008E0C8: nop

            goto L_8008E114;
    }
    // 0x8008E0C8: nop

    // 0x8008E0CC: sh          $zero, 0x126($a0)
    MEM_H(0X126, ctx->r4) = 0;
    // 0x8008E0D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008E0D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008E0D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008E0DC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008E0E0: nop

    // 0x8008E0E4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008E0E8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8008E0EC: nop

    // 0x8008E0F0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8008E0F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008E0F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008E0FC: nop

    // 0x8008E100: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008E104: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8008E108: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8008E10C: sh          $t1, 0x16A($a0)
    MEM_H(0X16A, ctx->r4) = ctx->r9;
    // 0x8008E110: nop

L_8008E114:
    // 0x8008E114: lh          $t2, 0x126($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X126);
    // 0x8008E118: nop

    // 0x8008E11C: slti        $at, $t2, 0xC9
    ctx->r1 = SIGNED(ctx->r10) < 0XC9 ? 1 : 0;
    // 0x8008E120: bne         $at, $zero, L_8008E174
    if (ctx->r1 != 0) {
        // 0x8008E124: nop

            goto L_8008E174;
    }
    // 0x8008E124: nop

    // 0x8008E128: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8008E12C: sh          $t3, 0x126($a0)
    MEM_H(0X126, ctx->r4) = ctx->r11;
    // 0x8008E130: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8008E134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008E138: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008E13C: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008E140: nop

    // 0x8008E144: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8008E148: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8008E14C: nop

    // 0x8008E150: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8008E154: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008E158: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008E15C: nop

    // 0x8008E160: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008E164: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8008E168: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8008E16C: sh          $t5, 0x16A($a0)
    MEM_H(0X16A, ctx->r4) = ctx->r13;
    // 0x8008E170: nop

L_8008E174:
    // 0x8008E174: jr          $ra
    // 0x8008E178: nop

    return;
    // 0x8008E178: nop

    // 0x8008E17C: jr          $ra
    // 0x8008E180: nop

    return;
    // 0x8008E180: nop

;}
RECOMP_FUNC void func_8008E184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E184: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008E188: beq         $a1, $zero, L_8008E228
    if (ctx->r5 == 0) {
        // 0x8008E18C: nop

            goto L_8008E228;
    }
    // 0x8008E18C: nop

    // 0x8008E190: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008E194: lhu         $t6, 0x24FC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X24FC);
    // 0x8008E198: nop

    // 0x8008E19C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008E1A0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008E1A4: lw          $t9, 0x12C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X12C);
    // 0x8008E1A8: nop

    // 0x8008E1AC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8008E1B0: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8008E1B4: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008E1B8: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008E1BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008E1C0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008E1C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008E1C8: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8008E1CC: nop

    // 0x8008E1D0: bc1f        L_8008E220
    if (!c1cs) {
        // 0x8008E1D4: nop

            goto L_8008E220;
    }
    // 0x8008E1D4: nop

L_8008E1D8:
    // 0x8008E1D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008E1DC: nop

    // 0x8008E1E0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8008E1E4: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008E1E8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008E1EC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008E1F0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008E1F4: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008E1F8: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8008E1FC: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008E200: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008E204: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8008E208: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008E20C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008E210: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008E214: nop

    // 0x8008E218: bc1t        L_8008E1D8
    if (c1cs) {
        // 0x8008E21C: nop

            goto L_8008E1D8;
    }
    // 0x8008E21C: nop

L_8008E220:
    // 0x8008E220: b           L_8008E2D8
    // 0x8008E224: nop

        goto L_8008E2D8;
    // 0x8008E224: nop

L_8008E228:
    // 0x8008E228: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8008E22C:
    // 0x8008E22C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8008E230: nop

    // 0x8008E234: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8008E238: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8008E23C: lw          $t8, 0x12C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X12C);
    // 0x8008E240: nop

    // 0x8008E244: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8008E248: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8008E24C: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008E250: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008E254: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8008E258: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008E25C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008E260: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8008E264: nop

    // 0x8008E268: bc1f        L_8008E2B8
    if (!c1cs) {
        // 0x8008E26C: nop

            goto L_8008E2B8;
    }
    // 0x8008E26C: nop

L_8008E270:
    // 0x8008E270: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008E274: nop

    // 0x8008E278: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8008E27C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008E280: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008E284: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008E288: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008E28C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008E290: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8008E294: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008E298: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008E29C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8008E2A0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008E2A4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008E2A8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8008E2AC: nop

    // 0x8008E2B0: bc1t        L_8008E270
    if (c1cs) {
        // 0x8008E2B4: nop

            goto L_8008E270;
    }
    // 0x8008E2B4: nop

L_8008E2B8:
    // 0x8008E2B8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8008E2BC: nop

    // 0x8008E2C0: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8008E2C4: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x8008E2C8: bne         $at, $zero, L_8008E22C
    if (ctx->r1 != 0) {
        // 0x8008E2CC: sw          $t5, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r13;
            goto L_8008E22C;
    }
    // 0x8008E2CC: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8008E2D0: b           L_8008E2D8
    // 0x8008E2D4: nop

        goto L_8008E2D8;
    // 0x8008E2D4: nop

L_8008E2D8:
    // 0x8008E2D8: jr          $ra
    // 0x8008E2DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008E2DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8008E2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E2E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E2E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E2E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008E2EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008E2F0: jal         0x80099E2C
    // 0x8008E2F4: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x8008E2F4: nop

    after_0:
    // 0x8008E2F8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008E2FC: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8008E300: sw          $t6, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r14;
    // 0x8008E304: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008E308: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8008E30C: sh          $t8, 0x116($t9)
    MEM_H(0X116, ctx->r25) = ctx->r24;
    // 0x8008E310: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008E314: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8008E318: sh          $t0, 0x114($t1)
    MEM_H(0X114, ctx->r9) = ctx->r8;
    // 0x8008E31C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008E320: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8008E324: sw          $t2, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r10;
    // 0x8008E328: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008E32C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8008E330: sh          $t4, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r12;
    // 0x8008E334: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008E338: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8008E33C: sh          $t6, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r14;
    // 0x8008E340: b           L_8008E348
    // 0x8008E344: nop

        goto L_8008E348;
    // 0x8008E344: nop

L_8008E348:
    // 0x8008E348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E34C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E350: jr          $ra
    // 0x8008E354: nop

    return;
    // 0x8008E354: nop

;}
RECOMP_FUNC void func_8008E358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E358: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8008E35C: addiu       $t6, $zero, 0x4A8B
    ctx->r14 = ADD32(0, 0X4A8B);
    // 0x8008E360: sh          $t6, 0x100($t7)
    MEM_H(0X100, ctx->r15) = ctx->r14;
    // 0x8008E364: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8008E368: ori         $t8, $zero, 0x8457
    ctx->r24 = 0 | 0X8457;
    // 0x8008E36C: sh          $t8, 0x102($t9)
    MEM_H(0X102, ctx->r25) = ctx->r24;
    // 0x8008E370: jr          $ra
    // 0x8008E374: nop

    return;
    // 0x8008E374: nop

    // 0x8008E378: jr          $ra
    // 0x8008E37C: nop

    return;
    // 0x8008E37C: nop

;}
RECOMP_FUNC void func_8008E380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E380: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008E384: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008E388: lhu         $t7, 0xE74($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XE74);
    // 0x8008E38C: lhu         $t6, 0xE68($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XE68);
    // 0x8008E390: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008E394: lhu         $t9, 0xEEC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEEC);
    // 0x8008E398: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008E39C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8008E3A0: lhu         $t1, 0xEC0($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XEC0);
    // 0x8008E3A4: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8008E3A8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8008E3AC: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x8008E3B0: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x8008E3B4: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x8008E3B8: and         $t5, $t4, $t2
    ctx->r13 = ctx->r12 & ctx->r10;
    // 0x8008E3BC: beq         $t5, $zero, L_8008E3D8
    if (ctx->r13 == 0) {
        // 0x8008E3C0: nop

            goto L_8008E3D8;
    }
    // 0x8008E3C0: nop

    // 0x8008E3C4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8008E3C8: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8008E3CC: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8008E3D0: b           L_8008E4EC
    // 0x8008E3D4: sh          $t7, 0x3AE($a0)
    MEM_H(0X3AE, ctx->r4) = ctx->r15;
        goto L_8008E4EC;
    // 0x8008E3D4: sh          $t7, 0x3AE($a0)
    MEM_H(0X3AE, ctx->r4) = ctx->r15;
L_8008E3D8:
    // 0x8008E3D8: sh          $zero, 0x3AE($a0)
    MEM_H(0X3AE, ctx->r4) = 0;
    // 0x8008E3DC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008E3E0: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8008E3E4: lwc1        $f4, 0x10($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8008E3E8: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8008E3EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008E3F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008E3F4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008E3F8: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8008E3FC: nop

    // 0x8008E400: bc1f        L_8008E420
    if (!c1cs) {
        // 0x8008E404: nop

            goto L_8008E420;
    }
    // 0x8008E404: nop

    // 0x8008E408: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008E40C: lhu         $t0, 0xEEC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XEEC);
    // 0x8008E410: lhu         $t9, 0x3AE($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X3AE);
    // 0x8008E414: nop

    // 0x8008E418: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8008E41C: sh          $t1, 0x3AE($a0)
    MEM_H(0X3AE, ctx->r4) = ctx->r9;
L_8008E420:
    // 0x8008E420: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8008E424: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8008E428: lwc1        $f10, 0x10($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X10);
    // 0x8008E42C: lui         $at, 0xC02E
    ctx->r1 = S32(0XC02E << 16);
    // 0x8008E430: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008E434: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008E438: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8008E43C: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8008E440: nop

    // 0x8008E444: bc1f        L_8008E464
    if (!c1cs) {
        // 0x8008E448: nop

            goto L_8008E464;
    }
    // 0x8008E448: nop

    // 0x8008E44C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8008E450: lhu         $t2, 0xEC0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XEC0);
    // 0x8008E454: lhu         $t4, 0x3AE($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X3AE);
    // 0x8008E458: nop

    // 0x8008E45C: or          $t5, $t4, $t2
    ctx->r13 = ctx->r12 | ctx->r10;
    // 0x8008E460: sh          $t5, 0x3AE($a0)
    MEM_H(0X3AE, ctx->r4) = ctx->r13;
L_8008E464:
    // 0x8008E464: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8008E468: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8008E46C: lwc1        $f4, 0x14($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8008E470: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8008E474: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008E478: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008E47C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008E480: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8008E484: nop

    // 0x8008E488: bc1f        L_8008E4A8
    if (!c1cs) {
        // 0x8008E48C: nop

            goto L_8008E4A8;
    }
    // 0x8008E48C: nop

    // 0x8008E490: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008E494: lhu         $t8, 0xE68($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XE68);
    // 0x8008E498: lhu         $t7, 0x3AE($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X3AE);
    // 0x8008E49C: nop

    // 0x8008E4A0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8008E4A4: sh          $t9, 0x3AE($a0)
    MEM_H(0X3AE, ctx->r4) = ctx->r25;
L_8008E4A8:
    // 0x8008E4A8: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008E4AC: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8008E4B0: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8008E4B4: lui         $at, 0xC02E
    ctx->r1 = S32(0XC02E << 16);
    // 0x8008E4B8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008E4BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008E4C0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8008E4C4: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8008E4C8: nop

    // 0x8008E4CC: bc1f        L_8008E4EC
    if (!c1cs) {
        // 0x8008E4D0: nop

            goto L_8008E4EC;
    }
    // 0x8008E4D0: nop

    // 0x8008E4D4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008E4D8: lhu         $t3, 0xE74($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XE74);
    // 0x8008E4DC: lhu         $t1, 0x3AE($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X3AE);
    // 0x8008E4E0: nop

    // 0x8008E4E4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8008E4E8: sh          $t4, 0x3AE($a0)
    MEM_H(0X3AE, ctx->r4) = ctx->r12;
L_8008E4EC:
    // 0x8008E4EC: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8008E4F0: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8008E4F4: lhu         $t5, 0x6($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X6);
    // 0x8008E4F8: nop

    // 0x8008E4FC: sh          $t5, 0x3B0($a0)
    MEM_H(0X3B0, ctx->r4) = ctx->r13;
    // 0x8008E500: jr          $ra
    // 0x8008E504: nop

    return;
    // 0x8008E504: nop

    // 0x8008E508: jr          $ra
    // 0x8008E50C: nop

    return;
    // 0x8008E50C: nop

;}
RECOMP_FUNC void func_8008E510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E510: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008E514: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8008E518: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8008E51C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008E520: addiu       $t6, $t6, 0x4C50
    ctx->r14 = ADD32(ctx->r14, 0X4C50);
    // 0x8008E524: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_8008E528:
    // 0x8008E528: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008E52C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8008E530: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8008E534: nop

    // 0x8008E538: bne         $t8, $at, L_8008E548
    if (ctx->r24 != ctx->r1) {
        // 0x8008E53C: nop

            goto L_8008E548;
    }
    // 0x8008E53C: nop

    // 0x8008E540: b           L_8008E594
    // 0x8008E544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E594;
    // 0x8008E544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E548:
    // 0x8008E548: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008E54C: nop

    // 0x8008E550: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8008E554: nop

    // 0x8008E558: bne         $t0, $a0, L_8008E578
    if (ctx->r8 != ctx->r4) {
        // 0x8008E55C: nop

            goto L_8008E578;
    }
    // 0x8008E55C: nop

    // 0x8008E560: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x8008E564: nop

    // 0x8008E568: bne         $t1, $a1, L_8008E578
    if (ctx->r9 != ctx->r5) {
        // 0x8008E56C: nop

            goto L_8008E578;
    }
    // 0x8008E56C: nop

    // 0x8008E570: b           L_8008E594
    // 0x8008E574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008E594;
    // 0x8008E574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E578:
    // 0x8008E578: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008E57C: nop

    // 0x8008E580: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8008E584: b           L_8008E528
    // 0x8008E588: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
        goto L_8008E528;
    // 0x8008E588: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8008E58C: b           L_8008E594
    // 0x8008E590: nop

        goto L_8008E594;
    // 0x8008E590: nop

L_8008E594:
    // 0x8008E594: jr          $ra
    // 0x8008E598: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008E598: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008E59C: nop

;}
RECOMP_FUNC void func_8008E5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E5A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008E5A4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008E5A8:
    // 0x8008E5A8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008E5AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E5B0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8008E5B4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008E5B8: sw          $zero, -0x38B8($at)
    MEM_W(-0X38B8, ctx->r1) = 0;
    // 0x8008E5BC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8008E5C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E5C4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8008E5C8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008E5CC: sw          $zero, -0x38B4($at)
    MEM_W(-0X38B4, ctx->r1) = 0;
    // 0x8008E5D0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8008E5D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E5D8: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8008E5DC: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008E5E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008E5E4: sw          $t0, -0x38B0($at)
    MEM_W(-0X38B0, ctx->r1) = ctx->r8;
    // 0x8008E5E8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008E5EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E5F0: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8008E5F4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8008E5F8: sw          $zero, -0x38AC($at)
    MEM_W(-0X38AC, ctx->r1) = 0;
    // 0x8008E5FC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8008E600: nop

    // 0x8008E604: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008E608: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008E60C: bne         $at, $zero, L_8008E5A8
    if (ctx->r1 != 0) {
        // 0x8008E610: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_8008E5A8;
    }
    // 0x8008E610: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008E614: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8008E618: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E61C: sh          $t7, -0x44C8($at)
    MEM_H(-0X44C8, ctx->r1) = ctx->r15;
    // 0x8008E620: b           L_8008E628
    // 0x8008E624: nop

        goto L_8008E628;
    // 0x8008E624: nop

L_8008E628:
    // 0x8008E628: jr          $ra
    // 0x8008E62C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008E62C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008E630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E630: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008E634: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008E638: sw          $zero, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = 0;
    // 0x8008E63C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008E640: sw          $zero, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = 0;
    // 0x8008E644: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8008E648: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008E64C: sw          $t6, 0x6BA8($at)
    MEM_W(0X6BA8, ctx->r1) = ctx->r14;
    // 0x8008E650: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008E654:
    // 0x8008E654: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008E658: nop

    // 0x8008E65C: bne         $t7, $zero, L_8008E680
    if (ctx->r15 != 0) {
        // 0x8008E660: nop

            goto L_8008E680;
    }
    // 0x8008E660: nop

    // 0x8008E664: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8008E668: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E66C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8008E670: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8008E674: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8008E678: b           L_8008E69C
    // 0x8008E67C: sh          $zero, -0x44B8($at)
    MEM_H(-0X44B8, ctx->r1) = 0;
        goto L_8008E69C;
    // 0x8008E67C: sh          $zero, -0x44B8($at)
    MEM_H(-0X44B8, ctx->r1) = 0;
L_8008E680:
    // 0x8008E680: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008E684: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E688: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8008E68C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8008E690: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8008E694: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008E698: sh          $t1, -0x44B8($at)
    MEM_H(-0X44B8, ctx->r1) = ctx->r9;
L_8008E69C:
    // 0x8008E69C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008E6A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E6A4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8008E6A8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008E6AC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008E6B0: addiu       $t5, $zero, 0x6FFF
    ctx->r13 = ADD32(0, 0X6FFF);
    // 0x8008E6B4: sh          $t5, -0x44B6($at)
    MEM_H(-0X44B6, ctx->r1) = ctx->r13;
    // 0x8008E6B8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008E6BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E6C0: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x8008E6C4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008E6C8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8008E6CC: addiu       $t9, $zero, 0x7C1
    ctx->r25 = ADD32(0, 0X7C1);
    // 0x8008E6D0: sh          $t9, -0x44B4($at)
    MEM_H(-0X44B4, ctx->r1) = ctx->r25;
    // 0x8008E6D4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8008E6D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E6DC: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8008E6E0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008E6E4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008E6E8: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8008E6EC: sh          $t1, -0x44B2($at)
    MEM_H(-0X44B2, ctx->r1) = ctx->r9;
    // 0x8008E6F0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8008E6F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E6F8: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x8008E6FC: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x8008E700: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008E704: ori         $t5, $zero, 0xF801
    ctx->r13 = 0 | 0XF801;
    // 0x8008E708: sh          $t5, -0x44B0($at)
    MEM_H(-0X44B0, ctx->r1) = ctx->r13;
    // 0x8008E70C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008E710: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E714: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8008E718: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8008E71C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008E720: ori         $t9, $zero, 0xF83F
    ctx->r25 = 0 | 0XF83F;
    // 0x8008E724: sh          $t9, -0x44AE($at)
    MEM_H(-0X44AE, ctx->r1) = ctx->r25;
    // 0x8008E728: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008E72C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E730: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8008E734: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8008E738: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8008E73C: ori         $t1, $zero, 0xFFC1
    ctx->r9 = 0 | 0XFFC1;
    // 0x8008E740: sh          $t1, -0x44AC($at)
    MEM_H(-0X44AC, ctx->r1) = ctx->r9;
    // 0x8008E744: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008E748: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E74C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8008E750: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8008E754: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8008E758: ori         $t5, $zero, 0xFFFF
    ctx->r13 = 0 | 0XFFFF;
    // 0x8008E75C: sh          $t5, -0x44AA($at)
    MEM_H(-0X44AA, ctx->r1) = ctx->r13;
    // 0x8008E760: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008E764: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E768: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8008E76C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008E770: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008E774: addiu       $t9, $zero, 0x7BDF
    ctx->r25 = ADD32(0, 0X7BDF);
    // 0x8008E778: sh          $t9, -0x44A8($at)
    MEM_H(-0X44A8, ctx->r1) = ctx->r25;
    // 0x8008E77C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008E780: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E784: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x8008E788: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008E78C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8008E790: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x8008E794: sh          $t1, -0x44A6($at)
    MEM_H(-0X44A6, ctx->r1) = ctx->r9;
    // 0x8008E798: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8008E79C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E7A0: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8008E7A4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008E7A8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008E7AC: addiu       $t5, $zero, 0x3C1
    ctx->r13 = ADD32(0, 0X3C1);
    // 0x8008E7B0: sh          $t5, -0x44A4($at)
    MEM_H(-0X44A4, ctx->r1) = ctx->r13;
    // 0x8008E7B4: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8008E7B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E7BC: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x8008E7C0: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x8008E7C4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008E7C8: addiu       $t9, $zero, 0x3DF
    ctx->r25 = ADD32(0, 0X3DF);
    // 0x8008E7CC: sh          $t9, -0x44A2($at)
    MEM_H(-0X44A2, ctx->r1) = ctx->r25;
    // 0x8008E7D0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008E7D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E7D8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8008E7DC: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8008E7E0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008E7E4: addiu       $t1, $zero, 0x7801
    ctx->r9 = ADD32(0, 0X7801);
    // 0x8008E7E8: sh          $t1, -0x44A0($at)
    MEM_H(-0X44A0, ctx->r1) = ctx->r9;
    // 0x8008E7EC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008E7F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E7F4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8008E7F8: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8008E7FC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8008E800: addiu       $t5, $zero, 0x781F
    ctx->r13 = ADD32(0, 0X781F);
    // 0x8008E804: sh          $t5, -0x449E($at)
    MEM_H(-0X449E, ctx->r1) = ctx->r13;
    // 0x8008E808: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008E80C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E810: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8008E814: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8008E818: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8008E81C: addiu       $t9, $zero, 0x7BC1
    ctx->r25 = ADD32(0, 0X7BC1);
    // 0x8008E820: sh          $t9, -0x449C($at)
    MEM_H(-0X449C, ctx->r1) = ctx->r25;
    // 0x8008E824: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008E828: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E82C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8008E830: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008E834: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008E838: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x8008E83C: sh          $t1, -0x449A($at)
    MEM_H(-0X449A, ctx->r1) = ctx->r9;
    // 0x8008E840: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8008E844: nop

    // 0x8008E848: addiu       $t0, $t5, 0x1
    ctx->r8 = ADD32(ctx->r13, 0X1);
    // 0x8008E84C: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8008E850: bne         $at, $zero, L_8008E654
    if (ctx->r1 != 0) {
        // 0x8008E854: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_8008E654;
    }
    // 0x8008E854: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8008E858: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E85C: sw          $zero, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = 0;
    // 0x8008E860: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008E864: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E868: sw          $t2, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r10;
    // 0x8008E86C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8008E870: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E874: sw          $t3, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r11;
    // 0x8008E878: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E87C: sh          $zero, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = 0;
    // 0x8008E880: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8008E884: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008E888: sw          $t9, 0x6C08($at)
    MEM_W(0X6C08, ctx->r1) = ctx->r25;
    // 0x8008E88C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008E890: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8008E894: sw          $t4, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r12;
    // 0x8008E898: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8008E89C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008E8A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E8A4: swc1        $f4, -0x4CBC($at)
    MEM_W(-0X4CBC, ctx->r1) = ctx->f4.u32l;
    // 0x8008E8A8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8008E8AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008E8B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E8B4: swc1        $f6, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f6.u32l;
    // 0x8008E8B8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8008E8BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008E8C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E8C4: swc1        $f8, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f8.u32l;
    // 0x8008E8C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8008E8CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008E8D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E8D4: swc1        $f10, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f10.u32l;
    // 0x8008E8D8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008E8DC:
    // 0x8008E8DC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008E8E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E8E4: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8008E8E8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8008E8EC: addiu       $t7, $t6, 0xF0
    ctx->r15 = ADD32(ctx->r14, 0XF0);
    // 0x8008E8F0: sw          $t7, -0x42B8($at)
    MEM_W(-0X42B8, ctx->r1) = ctx->r15;
    // 0x8008E8F4: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8008E8F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E8FC: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8008E900: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8008E904: sw          $zero, -0x3EB8($at)
    MEM_W(-0X3EB8, ctx->r1) = 0;
    // 0x8008E908: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008E90C: nop

    // 0x8008E910: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8008E914: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8008E918: bne         $at, $zero, L_8008E8DC
    if (ctx->r1 != 0) {
        // 0x8008E91C: sw          $t2, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r10;
            goto L_8008E8DC;
    }
    // 0x8008E91C: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8008E920: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8008E924: addiu       $t3, $t3, -0x3AB8
    ctx->r11 = ADD32(ctx->r11, -0X3AB8);
    // 0x8008E928: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x8008E92C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8008E930: addiu       $t4, $t4, -0x3AB8
    ctx->r12 = ADD32(ctx->r12, -0X3AB8);
    // 0x8008E934: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8008E938: sh          $t9, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r25;
    // 0x8008E93C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8008E940: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, -0X3AB8);
    // 0x8008E944: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8008E948: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x8008E94C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8008E950: addiu       $t8, $t8, -0x3AB8
    ctx->r24 = ADD32(ctx->r24, -0X3AB8);
    // 0x8008E954: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8008E958: sh          $t1, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r9;
    // 0x8008E95C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8008E960: addiu       $t5, $t5, -0x3AB8
    ctx->r13 = ADD32(ctx->r13, -0X3AB8);
    // 0x8008E964: sh          $zero, 0xC($t5)
    MEM_H(0XC, ctx->r13) = 0;
    // 0x8008E968: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008E96C: addiu       $t0, $t0, -0x3AB8
    ctx->r8 = ADD32(ctx->r8, -0X3AB8);
    // 0x8008E970: sh          $zero, 0x104($t0)
    MEM_H(0X104, ctx->r8) = 0;
    // 0x8008E974: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8008E978: addiu       $t2, $t2, -0x3AB8
    ctx->r10 = ADD32(ctx->r10, -0X3AB8);
    // 0x8008E97C: sh          $zero, 0x106($t2)
    MEM_H(0X106, ctx->r10) = 0;
    // 0x8008E980: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8008E984: addiu       $t3, $t3, -0x3AB8
    ctx->r11 = ADD32(ctx->r11, -0X3AB8);
    // 0x8008E988: sh          $zero, 0x108($t3)
    MEM_H(0X108, ctx->r11) = 0;
    // 0x8008E98C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8008E990: addiu       $t9, $t9, -0x3AB8
    ctx->r25 = ADD32(ctx->r25, -0X3AB8);
    // 0x8008E994: sh          $zero, 0x10A($t9)
    MEM_H(0X10A, ctx->r25) = 0;
    // 0x8008E998: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8008E99C: addiu       $t4, $t4, -0x3AB8
    ctx->r12 = ADD32(ctx->r12, -0X3AB8);
    // 0x8008E9A0: sh          $zero, 0x10C($t4)
    MEM_H(0X10C, ctx->r12) = 0;
    // 0x8008E9A4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008E9A8: addiu       $t6, $t6, -0x28B8
    ctx->r14 = ADD32(ctx->r14, -0X28B8);
    // 0x8008E9AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E9B0: sw          $t6, -0x2878($at)
    MEM_W(-0X2878, ctx->r1) = ctx->r14;
    // 0x8008E9B4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8008E9B8: addiu       $t7, $t7, -0x2870
    ctx->r15 = ADD32(ctx->r15, -0X2870);
    // 0x8008E9BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E9C0: sw          $t7, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r15;
    // 0x8008E9C4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8008E9C8: addiu       $t1, $t1, -0x2820
    ctx->r9 = ADD32(ctx->r9, -0X2820);
    // 0x8008E9CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E9D0: sw          $t1, -0x800($at)
    MEM_W(-0X800, ctx->r1) = ctx->r9;
    // 0x8008E9D4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8008E9D8: lhu         $t8, -0x44C8($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X44C8);
    // 0x8008E9DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E9E0: sh          $t8, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r24;
    // 0x8008E9E4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8008E9E8: lhu         $t5, -0x44C0($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X44C0);
    // 0x8008E9EC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8008E9F0: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x8008E9F4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8008E9F8: lh          $t2, -0x3AB8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X3AB8);
    // 0x8008E9FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EA00: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8008EA04: nop

    // 0x8008EA08: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008EA0C: swc1        $f18, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f18.u32l;
    // 0x8008EA10: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8008EA14: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8008EA18: lw          $t9, -0x2878($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2878);
    // 0x8008EA1C: lw          $t3, -0x4CD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CD8);
    // 0x8008EA20: nop

    // 0x8008EA24: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x8008EA28: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8008EA2C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008EA30: lw          $t6, -0x282C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X282C);
    // 0x8008EA34: lhu         $t4, -0x44C0($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X44C0);
    // 0x8008EA38: nop

    // 0x8008EA3C: sh          $t4, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r12;
    // 0x8008EA40: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8008EA44: lw          $t7, -0x7F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7F8);
    // 0x8008EA48: nop

    // 0x8008EA4C: bne         $t7, $zero, L_8008EA98
    if (ctx->r15 != 0) {
        // 0x8008EA50: nop

            goto L_8008EA98;
    }
    // 0x8008EA50: nop

    // 0x8008EA54: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8008EA58: lw          $t1, -0x7F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7F8);
    // 0x8008EA5C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EA60: addiu       $t8, $t1, 0x1
    ctx->r24 = ADD32(ctx->r9, 0X1);
    // 0x8008EA64: sw          $t8, -0x7F8($at)
    MEM_W(-0X7F8, ctx->r1) = ctx->r24;
    // 0x8008EA68: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x8008EA6C: addiu       $t5, $t5, -0x5540
    ctx->r13 = ADD32(ctx->r13, -0X5540);
    // 0x8008EA70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EA74: sw          $t5, -0x7F0($at)
    MEM_W(-0X7F0, ctx->r1) = ctx->r13;
    // 0x8008EA78: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8008EA7C: addiu       $t0, $t0, -0x5140
    ctx->r8 = ADD32(ctx->r8, -0X5140);
    // 0x8008EA80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EA84: sw          $t0, -0x798($at)
    MEM_W(-0X798, ctx->r1) = ctx->r8;
    // 0x8008EA88: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008EA8C: addiu       $t2, $t2, 0x4CB0
    ctx->r10 = ADD32(ctx->r10, 0X4CB0);
    // 0x8008EA90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EA94: sw          $t2, -0x790($at)
    MEM_W(-0X790, ctx->r1) = ctx->r10;
L_8008EA98:
    // 0x8008EA98: b           L_8008EAA0
    // 0x8008EA9C: nop

        goto L_8008EAA0;
    // 0x8008EA9C: nop

L_8008EAA0:
    // 0x8008EAA0: jr          $ra
    // 0x8008EAA4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008EAA4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008EAA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EAA8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008EAAC: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x8008EAB0: nop

    // 0x8008EAB4: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8008EAB8: beq         $t7, $zero, L_8008EADC
    if (ctx->r15 == 0) {
        // 0x8008EABC: nop

            goto L_8008EADC;
    }
    // 0x8008EABC: nop

    // 0x8008EAC0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8008EAC4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EAC8: sw          $t8, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r24;
    // 0x8008EACC: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8008EAD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EAD4: b           L_8008EB90
    // 0x8008EAD8: sw          $t9, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r25;
        goto L_8008EB90;
    // 0x8008EAD8: sw          $t9, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r25;
L_8008EADC:
    // 0x8008EADC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008EAE0: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x8008EAE4: nop

    // 0x8008EAE8: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8008EAEC: beq         $t1, $zero, L_8008EB10
    if (ctx->r9 == 0) {
        // 0x8008EAF0: nop

            goto L_8008EB10;
    }
    // 0x8008EAF0: nop

    // 0x8008EAF4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008EAF8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EAFC: sw          $t2, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r10;
    // 0x8008EB00: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8008EB04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB08: b           L_8008EB90
    // 0x8008EB0C: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
        goto L_8008EB90;
    // 0x8008EB0C: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
L_8008EB10:
    // 0x8008EB10: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8008EB14: lh          $t4, -0x4CC8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CC8);
    // 0x8008EB18: nop

    // 0x8008EB1C: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x8008EB20: beq         $t5, $zero, L_8008EB44
    if (ctx->r13 == 0) {
        // 0x8008EB24: nop

            goto L_8008EB44;
    }
    // 0x8008EB24: nop

    // 0x8008EB28: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8008EB2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB30: sw          $t6, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r14;
    // 0x8008EB34: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8008EB38: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB3C: b           L_8008EB90
    // 0x8008EB40: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
        goto L_8008EB90;
    // 0x8008EB40: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
L_8008EB44:
    // 0x8008EB44: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8008EB48: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x8008EB4C: nop

    // 0x8008EB50: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x8008EB54: beq         $t9, $zero, L_8008EB78
    if (ctx->r25 == 0) {
        // 0x8008EB58: nop

            goto L_8008EB78;
    }
    // 0x8008EB58: nop

    // 0x8008EB5C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8008EB60: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB64: sw          $t0, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r8;
    // 0x8008EB68: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008EB6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB70: b           L_8008EB90
    // 0x8008EB74: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
        goto L_8008EB90;
    // 0x8008EB74: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
L_8008EB78:
    // 0x8008EB78: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8008EB7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB80: sw          $t2, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r10;
    // 0x8008EB84: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8008EB88: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB8C: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
L_8008EB90:
    // 0x8008EB90: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8008EB94: lw          $t4, 0x61CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X61CC);
    // 0x8008EB98: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EB9C: multu       $a0, $t4
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EBA0: mflo        $t5
    ctx->r13 = lo;
    // 0x8008EBA4: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x8008EBA8: nop

    // 0x8008EBAC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8008EBB0: lw          $t6, 0x61D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X61D4);
    // 0x8008EBB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EBB8: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EBBC: mflo        $t7
    ctx->r15 = lo;
    // 0x8008EBC0: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x8008EBC4: nop

    // 0x8008EBC8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008EBCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EBD0: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8008EBD4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8008EBD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008EBDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008EBE0: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008EBE4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008EBE8: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8008EBEC: lw          $t1, 0x61CC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X61CC);
    // 0x8008EBF0: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x8008EBF4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8008EBF8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8008EBFC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008EC00: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008EC04: beq         $at, $zero, L_8008EC30
    if (ctx->r1 == 0) {
        // 0x8008EC08: nop

            goto L_8008EC30;
    }
    // 0x8008EC08: nop

    // 0x8008EC0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EC10: sw          $zero, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = 0;
    // 0x8008EC14: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8008EC18: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8008EC1C: lw          $t4, 0x61D4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X61D4);
    // 0x8008EC20: lw          $t3, 0x6BA0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6BA0);
    // 0x8008EC24: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EC28: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8008EC2C: sw          $t5, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r13;
L_8008EC30:
    // 0x8008EC30: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8008EC34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EC38: lwc1        $f8, -0x4534($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x8008EC3C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8008EC40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008EC44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008EC48: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008EC4C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008EC50: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008EC54: lw          $t0, 0x61D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X61D4);
    // 0x8008EC58: lw          $t8, 0x6BA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6BA0);
    // 0x8008EC5C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8008EC60: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008EC64: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8008EC68: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8008EC6C: beq         $at, $zero, L_8008EC7C
    if (ctx->r1 == 0) {
        // 0x8008EC70: nop

            goto L_8008EC7C;
    }
    // 0x8008EC70: nop

    // 0x8008EC74: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008EC78: sw          $zero, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = 0;
L_8008EC7C:
    // 0x8008EC7C: jr          $ra
    // 0x8008EC80: nop

    return;
    // 0x8008EC80: nop

    // 0x8008EC84: jr          $ra
    // 0x8008EC88: nop

    return;
    // 0x8008EC88: nop

;}
RECOMP_FUNC void func_8008EC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EC8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EC90: swc1        $f12, -0x4CBC($at)
    MEM_W(-0X4CBC, ctx->r1) = ctx->f12.u32l;
    // 0x8008EC94: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008EC98: swc1        $f14, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f14.u32l;
    // 0x8008EC9C: jr          $ra
    // 0x8008ECA0: nop

    return;
    // 0x8008ECA0: nop

    // 0x8008ECA4: jr          $ra
    // 0x8008ECA8: nop

    return;
    // 0x8008ECA8: nop

;}
RECOMP_FUNC void func_8008ECAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ECAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008ECB0: swc1        $f12, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f12.u32l;
    // 0x8008ECB4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008ECB8: swc1        $f14, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f14.u32l;
    // 0x8008ECBC: jr          $ra
    // 0x8008ECC0: nop

    return;
    // 0x8008ECC0: nop

    // 0x8008ECC4: jr          $ra
    // 0x8008ECC8: nop

    return;
    // 0x8008ECC8: nop

;}
RECOMP_FUNC void Sys_SwapFrameBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ECCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008ECD0: sw          $a0, -0x44BC($at)
    MEM_W(-0X44BC, ctx->r1) = ctx->r4;
    // 0x8008ECD4: jr          $ra
    // 0x8008ECD8: nop

    return;
    // 0x8008ECD8: nop

    // 0x8008ECDC: jr          $ra
    // 0x8008ECE0: nop

    return;
    // 0x8008ECE0: nop

;}
RECOMP_FUNC void func_8008ECE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ECE4: addiu       $sp, $sp, -0x420
    ctx->r29 = ADD32(ctx->r29, -0X420);
    // 0x8008ECE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008ECEC: sw          $a0, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r4;
    // 0x8008ECF0: sw          $a1, 0x424($sp)
    MEM_W(0X424, ctx->r29) = ctx->r5;
    // 0x8008ECF4: sw          $a2, 0x428($sp)
    MEM_W(0X428, ctx->r29) = ctx->r6;
    // 0x8008ECF8: sw          $a3, 0x42C($sp)
    MEM_W(0X42C, ctx->r29) = ctx->r7;
    // 0x8008ECFC: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
    // 0x8008ED00: sw          $t6, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r14;
    // 0x8008ED04: addiu       $t7, $sp, 0x420
    ctx->r15 = ADD32(ctx->r29, 0X420);
    // 0x8008ED08: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8008ED0C: sw          $t8, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r24;
    // 0x8008ED10: lw          $a0, 0x418($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X418);
    // 0x8008ED14: lw          $a1, 0x420($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X420);
    // 0x8008ED18: lw          $a2, 0x41C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X41C);
    // 0x8008ED1C: jal         0x8008EDA4
    // 0x8008ED20: nop

    vsprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008ED20: nop

    after_0:
    // 0x8008ED24: jal         0x80090E58
    // 0x8008ED28: addiu       $a0, $sp, 0x418
    ctx->r4 = ADD32(ctx->r29, 0X418);
    func_80090E58(rdram, ctx);
        goto after_1;
    // 0x8008ED28: addiu       $a0, $sp, 0x418
    ctx->r4 = ADD32(ctx->r29, 0X418);
    after_1:
    // 0x8008ED2C: b           L_8008ED3C
    // 0x8008ED30: nop

        goto L_8008ED3C;
    // 0x8008ED30: nop

    // 0x8008ED34: b           L_8008ED3C
    // 0x8008ED38: nop

        goto L_8008ED3C;
    // 0x8008ED38: nop

L_8008ED3C:
    // 0x8008ED3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008ED40: addiu       $sp, $sp, 0x420
    ctx->r29 = ADD32(ctx->r29, 0X420);
    // 0x8008ED44: jr          $ra
    // 0x8008ED48: nop

    return;
    // 0x8008ED48: nop

;}
RECOMP_FUNC void func_8008ED4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ED4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008ED50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008ED54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008ED58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008ED5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008ED60: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008ED64: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8008ED68: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8008ED6C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8008ED70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008ED74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008ED78: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008ED7C: jal         0x8008EDA4
    // 0x8008ED80: nop

    vsprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008ED80: nop

    after_0:
    // 0x8008ED84: b           L_8008ED94
    // 0x8008ED88: nop

        goto L_8008ED94;
    // 0x8008ED88: nop

    // 0x8008ED8C: b           L_8008ED94
    // 0x8008ED90: nop

        goto L_8008ED94;
    // 0x8008ED90: nop

L_8008ED94:
    // 0x8008ED94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008ED98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008ED9C: jr          $ra
    // 0x8008EDA0: nop

    return;
    // 0x8008EDA0: nop

;}
RECOMP_FUNC void vsprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EDA4: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8008EDA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008EDAC: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x8008EDB0: sw          $a1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r5;
    // 0x8008EDB4: sw          $a2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r6;
    // 0x8008EDB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008EDBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008EDC0: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x8008EDC4: nop

    // 0x8008EDC8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x8008EDCC: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EDD0: nop

    // 0x8008EDD4: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8008EDD8: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x8008EDDC: nop

    // 0x8008EDE0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x8008EDE4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8008EDE8: nop

    // 0x8008EDEC: beq         $t9, $zero, L_800906D0
    if (ctx->r25 == 0) {
        // 0x8008EDF0: nop

            goto L_800906D0;
    }
    // 0x8008EDF0: nop

L_8008EDF4:
    // 0x8008EDF4: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x8008EDF8: nop

    // 0x8008EDFC: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8008EE00: nop

    // 0x8008EE04: slti        $at, $t1, 0xE0
    ctx->r1 = SIGNED(ctx->r9) < 0XE0 ? 1 : 0;
    // 0x8008EE08: bne         $at, $zero, L_8008EFF4
    if (ctx->r1 != 0) {
        // 0x8008EE0C: nop

            goto L_8008EFF4;
    }
    // 0x8008EE0C: nop

    // 0x8008EE10: slti        $at, $t1, 0xE1
    ctx->r1 = SIGNED(ctx->r9) < 0XE1 ? 1 : 0;
    // 0x8008EE14: beq         $at, $zero, L_8008EFF4
    if (ctx->r1 == 0) {
        // 0x8008EE18: nop

            goto L_8008EFF4;
    }
    // 0x8008EE18: nop

    // 0x8008EE1C: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008EE20: nop

    // 0x8008EE24: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008EE28: sw          $t3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r11;
    // 0x8008EE2C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x8008EE30: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8008EE34: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8008EE38: addiu       $t8, $t8, -0x38B8
    ctx->r24 = ADD32(ctx->r24, -0X38B8);
    // 0x8008EE3C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8008EE40: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x8008EE44: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8008EE48: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8008EE4C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EE50: nop

    // 0x8008EE54: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8008EE58: nop

    // 0x8008EE5C: bne         $t1, $zero, L_8008EE6C
    if (ctx->r9 != 0) {
        // 0x8008EE60: nop

            goto L_8008EE6C;
    }
    // 0x8008EE60: nop

    // 0x8008EE64: b           L_800906B0
    // 0x8008EE68: nop

        goto L_800906B0;
    // 0x8008EE68: nop

L_8008EE6C:
    // 0x8008EE6C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EE70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008EE74: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8008EE78: nop

    // 0x8008EE7C: bne         $t3, $at, L_8008EEAC
    if (ctx->r11 != ctx->r1) {
        // 0x8008EE80: nop

            goto L_8008EEAC;
    }
    // 0x8008EE80: nop

    // 0x8008EE84: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EE88: nop

    // 0x8008EE8C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8008EE90: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x8008EE94: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8008EE98: jal         0x80096E58
    // 0x8008EE9C: nop

    func_80096E58(rdram, ctx);
        goto after_0;
    // 0x8008EE9C: nop

    after_0:
    // 0x8008EEA0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EEA4: nop

    // 0x8008EEA8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_8008EEAC:
    // 0x8008EEAC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EEB0: nop

    // 0x8008EEB4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8008EEB8: nop

    // 0x8008EEBC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
    // 0x8008EEC0: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EEC4: nop

    // 0x8008EEC8: beq         $t9, $zero, L_8008EFE4
    if (ctx->r25 == 0) {
        // 0x8008EECC: nop

            goto L_8008EFE4;
    }
    // 0x8008EECC: nop

    // 0x8008EED0: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EED4: nop

    // 0x8008EED8: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8008EEDC: nop

    // 0x8008EEE0: beq         $t1, $zero, L_8008EFB8
    if (ctx->r9 == 0) {
        // 0x8008EEE4: nop

            goto L_8008EFB8;
    }
    // 0x8008EEE4: nop

L_8008EEE8:
    // 0x8008EEE8: lw          $t2, 0xD4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EEEC: nop

    // 0x8008EEF0: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8008EEF4: nop

    // 0x8008EEF8: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x8008EEFC: bne         $at, $zero, L_8008EF74
    if (ctx->r1 != 0) {
        // 0x8008EF00: nop

            goto L_8008EF74;
    }
    // 0x8008EF00: nop

    // 0x8008EF04: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EF08: jal         0x80095E78
    // 0x8008EF0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_1;
    // 0x8008EF0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008EF10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008EF14: jal         0x80095F9C
    // 0x8008EF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_2;
    // 0x8008EF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008EF1C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008EF20: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008EF24: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF28: srl         $t4, $t5, 8
    ctx->r12 = S32(U32(ctx->r13) >> 8);
    // 0x8008EF2C: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x8008EF30: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF34: nop

    // 0x8008EF38: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008EF3C: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x8008EF40: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008EF44: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF48: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8008EF4C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x8008EF50: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF54: nop

    // 0x8008EF58: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008EF5C: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8008EF60: lw          $t5, 0xD4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EF64: nop

    // 0x8008EF68: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008EF6C: b           L_8008EF98
    // 0x8008EF70: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
        goto L_8008EF98;
    // 0x8008EF70: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
L_8008EF74:
    // 0x8008EF74: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EF78: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF7C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8008EF80: nop

    // 0x8008EF84: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008EF88: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF8C: nop

    // 0x8008EF90: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008EF94: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
L_8008EF98:
    // 0x8008EF98: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EF9C: nop

    // 0x8008EFA0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008EFA4: sw          $t2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r10;
    // 0x8008EFA8: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8008EFAC: nop

    // 0x8008EFB0: bne         $t3, $zero, L_8008EEE8
    if (ctx->r11 != 0) {
        // 0x8008EFB4: nop

            goto L_8008EEE8;
    }
    // 0x8008EFB4: nop

L_8008EFB8:
    // 0x8008EFB8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EFBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008EFC0: lw          $t4, 0xC($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC);
    // 0x8008EFC4: nop

    // 0x8008EFC8: beq         $t4, $at, L_8008EFE4
    if (ctx->r12 == ctx->r1) {
        // 0x8008EFCC: nop

            goto L_8008EFE4;
    }
    // 0x8008EFCC: nop

    // 0x8008EFD0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EFD4: nop

    // 0x8008EFD8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8008EFDC: jal         0x800BC980
    // 0x8008EFE0: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x8008EFE0: nop

    after_3:
L_8008EFE4:
    // 0x8008EFE4: b           L_800906B0
    // 0x8008EFE8: nop

        goto L_800906B0;
    // 0x8008EFE8: nop

    // 0x8008EFEC: b           L_8008F0FC
    // 0x8008EFF0: nop

        goto L_8008F0FC;
    // 0x8008EFF0: nop

L_8008EFF4:
    // 0x8008EFF4: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8008EFF8: nop

    // 0x8008EFFC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8008F000: nop

    // 0x8008F004: slti        $at, $t8, 0xE1
    ctx->r1 = SIGNED(ctx->r24) < 0XE1 ? 1 : 0;
    // 0x8008F008: bne         $at, $zero, L_8008F0FC
    if (ctx->r1 != 0) {
        // 0x8008F00C: nop

            goto L_8008F0FC;
    }
    // 0x8008F00C: nop

    // 0x8008F010: slti        $at, $t8, 0xF0
    ctx->r1 = SIGNED(ctx->r24) < 0XF0 ? 1 : 0;
    // 0x8008F014: beq         $at, $zero, L_8008F0FC
    if (ctx->r1 == 0) {
        // 0x8008F018: nop

            goto L_8008F0FC;
    }
    // 0x8008F018: nop

    // 0x8008F01C: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F020: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F024: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008F028: nop

    // 0x8008F02C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x8008F030: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F034: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F038: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008F03C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008F040: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8008F044: sw          $t4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r12;
    // 0x8008F048: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F04C: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F050: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8008F054: nop

    // 0x8008F058: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F05C: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F060: nop

    // 0x8008F064: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F068: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8008F06C: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F070: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x8008F074: lbu         $t2, -0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, -0X1);
    // 0x8008F078: nop

    // 0x8008F07C: bne         $t2, $at, L_8008F0F4
    if (ctx->r10 != ctx->r1) {
        // 0x8008F080: nop

            goto L_8008F0F4;
    }
    // 0x8008F080: nop

    // 0x8008F084: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8008F088: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8008F08C: bne         $t3, $at, L_8008F0F4
    if (ctx->r11 != ctx->r1) {
        // 0x8008F090: nop

            goto L_8008F0F4;
    }
    // 0x8008F090: nop

    // 0x8008F094: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F098: nop

    // 0x8008F09C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008F0A0: sw          $t4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r12;
    // 0x8008F0A4: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F0A8: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F0AC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8008F0B0: nop

    // 0x8008F0B4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F0B8: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F0BC: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F0C0: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8008F0C4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F0C8: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8008F0CC: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
    // 0x8008F0D0: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F0D4: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F0D8: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x8008F0DC: nop

    // 0x8008F0E0: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8008F0E4: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F0E8: nop

    // 0x8008F0EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008F0F0: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
L_8008F0F4:
    // 0x8008F0F4: b           L_800906B0
    // 0x8008F0F8: nop

        goto L_800906B0;
    // 0x8008F0F8: nop

L_8008F0FC:
    // 0x8008F0FC: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F100: nop

    // 0x8008F104: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8008F108: nop

    // 0x8008F10C: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x8008F110: bne         $at, $zero, L_8008F284
    if (ctx->r1 != 0) {
        // 0x8008F114: nop

            goto L_8008F284;
    }
    // 0x8008F114: nop

    // 0x8008F118: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F11C: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x8008F120: nop

    // 0x8008F124: andi        $t2, $t0, 0x200
    ctx->r10 = ctx->r8 & 0X200;
    // 0x8008F128: bne         $t2, $zero, L_8008F210
    if (ctx->r10 != 0) {
        // 0x8008F12C: nop

            goto L_8008F210;
    }
    // 0x8008F12C: nop

    // 0x8008F130: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8008F134: lh          $t1, -0x4CC8($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CC8);
    // 0x8008F138: nop

    // 0x8008F13C: andi        $t3, $t1, 0x10
    ctx->r11 = ctx->r9 & 0X10;
    // 0x8008F140: beq         $t3, $zero, L_8008F19C
    if (ctx->r11 == 0) {
        // 0x8008F144: nop

            goto L_8008F19C;
    }
    // 0x8008F144: nop

    // 0x8008F148: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F14C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F150: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008F154: nop

    // 0x8008F158: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x8008F15C: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F160: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F164: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F168: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008F16C: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x8008F170: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8008F174: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F178: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F17C: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8008F180: nop

    // 0x8008F184: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x8008F188: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F18C: nop

    // 0x8008F190: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008F194: b           L_8008F208
    // 0x8008F198: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
        goto L_8008F208;
    // 0x8008F198: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
L_8008F19C:
    // 0x8008F19C: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F1A0: jal         0x80095E78
    // 0x8008F1A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_4;
    // 0x8008F1A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8008F1A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008F1AC: jal         0x80095F9C
    // 0x8008F1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_5;
    // 0x8008F1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8008F1B4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008F1B8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008F1BC: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F1C0: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x8008F1C4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F1C8: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F1CC: nop

    // 0x8008F1D0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F1D4: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8008F1D8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008F1DC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F1E0: andi        $t1, $t2, 0xFF
    ctx->r9 = ctx->r10 & 0XFF;
    // 0x8008F1E4: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x8008F1E8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F1EC: nop

    // 0x8008F1F0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008F1F4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x8008F1F8: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F1FC: nop

    // 0x8008F200: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008F204: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_8008F208:
    // 0x8008F208: b           L_8008F27C
    // 0x8008F20C: nop

        goto L_8008F27C;
    // 0x8008F20C: nop

L_8008F210:
    // 0x8008F210: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F214: jal         0x80095E78
    // 0x8008F218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_6;
    // 0x8008F218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8008F21C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008F220: jal         0x80095F9C
    // 0x8008F224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_7;
    // 0x8008F224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8008F228: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008F22C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008F230: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F234: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x8008F238: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8008F23C: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F240: nop

    // 0x8008F244: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8008F248: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x8008F24C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008F250: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F254: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x8008F258: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8008F25C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F260: nop

    // 0x8008F264: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008F268: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x8008F26C: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F270: nop

    // 0x8008F274: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008F278: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
L_8008F27C:
    // 0x8008F27C: b           L_800906B0
    // 0x8008F280: nop

        goto L_800906B0;
    // 0x8008F280: nop

L_8008F284:
    // 0x8008F284: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F288: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8008F28C: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x8008F290: nop

    // 0x8008F294: beq         $t2, $at, L_8008F2C8
    if (ctx->r10 == ctx->r1) {
        // 0x8008F298: nop

            goto L_8008F2C8;
    }
    // 0x8008F298: nop

    // 0x8008F29C: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F2A0: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F2A4: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8008F2A8: nop

    // 0x8008F2AC: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x8008F2B0: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F2B4: nop

    // 0x8008F2B8: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8008F2BC: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x8008F2C0: b           L_800906B0
    // 0x8008F2C4: nop

        goto L_800906B0;
    // 0x8008F2C4: nop

L_8008F2C8:
    // 0x8008F2C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008F2CC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8008F2D0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8008F2D4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8008F2D8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8008F2DC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8008F2E0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F2E4: nop

    // 0x8008F2E8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008F2EC: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
    // 0x8008F2F0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8008F2F4: nop

    // 0x8008F2F8: beq         $t0, $zero, L_800906B0
    if (ctx->r8 == 0) {
        // 0x8008F2FC: nop

            goto L_800906B0;
    }
    // 0x8008F2FC: nop

L_8008F300:
    // 0x8008F300: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F304: nop

    // 0x8008F308: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8008F30C: nop

    // 0x8008F310: addiu       $t3, $t1, -0x2E
    ctx->r11 = ADD32(ctx->r9, -0X2E);
    // 0x8008F314: sltiu       $at, $t3, 0x4B
    ctx->r1 = ctx->r11 < 0X4B ? 1 : 0;
    // 0x8008F318: beq         $at, $zero, L_800906A0
    if (ctx->r1 == 0) {
        // 0x8008F31C: nop

            goto L_800906A0;
    }
    // 0x8008F31C: nop

    // 0x8008F320: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008F324: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008F328: addu        $at, $at, $t3
    gpr jr_addend_8008F334 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8008F32C: lw          $t3, -0x9EC($at)
    ctx->r11 = ADD32(ctx->r1, -0X9EC);
    // 0x8008F330: nop

    // 0x8008F334: jr          $t3
    // 0x8008F338: nop

    switch (jr_addend_8008F334 >> 2) {
        case 0: goto L_8008F42C; break;
        case 1: goto L_800906A0; break;
        case 2: goto L_8008F33C; break;
        case 3: goto L_8008F398; break;
        case 4: goto L_8008F398; break;
        case 5: goto L_8008F398; break;
        case 6: goto L_8008F398; break;
        case 7: goto L_8008F398; break;
        case 8: goto L_8008F398; break;
        case 9: goto L_8008F398; break;
        case 10: goto L_8008F398; break;
        case 11: goto L_8008F398; break;
        case 12: goto L_800906A0; break;
        case 13: goto L_800906A0; break;
        case 14: goto L_800906A0; break;
        case 15: goto L_800906A0; break;
        case 16: goto L_800906A0; break;
        case 17: goto L_800906A0; break;
        case 18: goto L_800906A0; break;
        case 19: goto L_800906A0; break;
        case 20: goto L_800906A0; break;
        case 21: goto L_800906A0; break;
        case 22: goto L_8008F478; break;
        case 23: goto L_800906A0; break;
        case 24: goto L_8008FE1C; break;
        case 25: goto L_800906A0; break;
        case 26: goto L_800906A0; break;
        case 27: goto L_800906A0; break;
        case 28: goto L_800906A0; break;
        case 29: goto L_800906A0; break;
        case 30: goto L_800906A0; break;
        case 31: goto L_800906A0; break;
        case 32: goto L_800906A0; break;
        case 33: goto L_800906A0; break;
        case 34: goto L_800906A0; break;
        case 35: goto L_800906A0; break;
        case 36: goto L_800906A0; break;
        case 37: goto L_800906A0; break;
        case 38: goto L_800906A0; break;
        case 39: goto L_800906A0; break;
        case 40: goto L_800906A0; break;
        case 41: goto L_800906A0; break;
        case 42: goto L_8008F780; break;
        case 43: goto L_800906A0; break;
        case 44: goto L_800906A0; break;
        case 45: goto L_800906A0; break;
        case 46: goto L_800906A0; break;
        case 47: goto L_800906A0; break;
        case 48: goto L_800906A0; break;
        case 49: goto L_800906A0; break;
        case 50: goto L_800906A0; break;
        case 51: goto L_80090588; break;
        case 52: goto L_800904B0; break;
        case 53: goto L_800906A0; break;
        case 54: goto L_8008F478; break;
        case 55: goto L_800906A0; break;
        case 56: goto L_8008FE1C; break;
        case 57: goto L_8009051C; break;
        case 58: goto L_800906A0; break;
        case 59: goto L_800906A0; break;
        case 60: goto L_800906A0; break;
        case 61: goto L_800906A0; break;
        case 62: goto L_80090444; break;
        case 63: goto L_800906A0; break;
        case 64: goto L_80090614; break;
        case 65: goto L_800906A0; break;
        case 66: goto L_800906A0; break;
        case 67: goto L_800906A0; break;
        case 68: goto L_800906A0; break;
        case 69: goto L_8008FB50; break;
        case 70: goto L_800903D8; break;
        case 71: goto L_800906A0; break;
        case 72: goto L_800906A0; break;
        case 73: goto L_800906A0; break;
        case 74: goto L_8008F780; break;
        default: switch_error(__func__, 0x8008F334, 0x800EF614);
    }
    // 0x8008F338: nop

L_8008F33C:
    // 0x8008F33C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F340: nop

    // 0x8008F344: bne         $t5, $zero, L_8008F398
    if (ctx->r13 != 0) {
        // 0x8008F348: nop

            goto L_8008F398;
    }
    // 0x8008F348: nop

    // 0x8008F34C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008F350: nop

    // 0x8008F354: bne         $t4, $zero, L_8008F398
    if (ctx->r12 != 0) {
        // 0x8008F358: nop

            goto L_8008F398;
    }
    // 0x8008F358: nop

    // 0x8008F35C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8008F360: nop

    // 0x8008F364: bne         $t6, $zero, L_8008F398
    if (ctx->r14 != 0) {
        // 0x8008F368: nop

            goto L_8008F398;
    }
    // 0x8008F368: nop

    // 0x8008F36C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F370: nop

    // 0x8008F374: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8008F378: nop

    // 0x8008F37C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8008F380: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F384: nop

    // 0x8008F388: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F38C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8008F390: b           L_800906A0
    // 0x8008F394: nop

        goto L_800906A0;
    // 0x8008F394: nop

L_8008F398:
    // 0x8008F398: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8008F39C: nop

    // 0x8008F3A0: bne         $t2, $zero, L_8008F3E4
    if (ctx->r10 != 0) {
        // 0x8008F3A4: nop

            goto L_8008F3E4;
    }
    // 0x8008F3A4: nop

    // 0x8008F3A8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008F3AC: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F3B0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8008F3B4: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008F3B8: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8008F3BC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8008F3C0: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8008F3C4: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8008F3C8: addiu       $t8, $t7, -0x30
    ctx->r24 = ADD32(ctx->r15, -0X30);
    // 0x8008F3CC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8008F3D0: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F3D4: nop

    // 0x8008F3D8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F3DC: b           L_8008F424
    // 0x8008F3E0: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
        goto L_8008F424;
    // 0x8008F3E0: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
L_8008F3E4:
    // 0x8008F3E4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8008F3E8: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F3EC: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8008F3F0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8008F3F4: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x8008F3F8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8008F3FC: addu        $t1, $t5, $t4
    ctx->r9 = ADD32(ctx->r13, ctx->r12);
    // 0x8008F400: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
    // 0x8008F404: addiu       $t7, $t6, -0x30
    ctx->r15 = ADD32(ctx->r14, -0X30);
    // 0x8008F408: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8008F40C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008F410: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8008F414: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F418: nop

    // 0x8008F41C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F420: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
L_8008F424:
    // 0x8008F424: b           L_800906A0
    // 0x8008F428: nop

        goto L_800906A0;
    // 0x8008F428: nop

L_8008F42C:
    // 0x8008F42C: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F430: nop

    // 0x8008F434: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8008F438: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
    // 0x8008F43C: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F440: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8008F444: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8008F448: nop

    // 0x8008F44C: addu        $t6, $t4, $t1
    ctx->r14 = ADD32(ctx->r12, ctx->r9);
    // 0x8008F450: addiu       $t7, $t6, -0x30
    ctx->r15 = ADD32(ctx->r14, -0X30);
    // 0x8008F454: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8008F458: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008F45C: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8008F460: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F464: nop

    // 0x8008F468: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F46C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8008F470: b           L_800906A0
    // 0x8008F474: nop

        goto L_800906A0;
    // 0x8008F474: nop

L_8008F478:
    // 0x8008F478: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8008F47C: sb          $t3, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r11;
    // 0x8008F480: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8008F484: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008F488: addiu       $t2, $t5, 0x3
    ctx->r10 = ADD32(ctx->r13, 0X3);
    // 0x8008F48C: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8008F490: addiu       $t1, $t4, 0x4
    ctx->r9 = ADD32(ctx->r12, 0X4);
    // 0x8008F494: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x8008F498: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8008F49C: nop

    // 0x8008F4A0: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x8008F4A4: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F4A8: nop

    // 0x8008F4AC: bgez        $t7, L_8008F4CC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8008F4B0: nop

            goto L_8008F4CC;
    }
    // 0x8008F4B0: nop

    // 0x8008F4B4: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8008F4B8: sb          $t8, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r24;
    // 0x8008F4BC: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F4C0: nop

    // 0x8008F4C4: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8008F4C8: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
L_8008F4CC:
    // 0x8008F4CC: lui         $t3, 0x3B9A
    ctx->r11 = S32(0X3B9A << 16);
    // 0x8008F4D0: ori         $t3, $t3, 0xCA00
    ctx->r11 = ctx->r11 | 0XCA00;
    // 0x8008F4D4: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8008F4D8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008F4DC:
    // 0x8008F4DC: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F4E0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8008F4E4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008F4E8: div         $zero, $t5, $t2
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r10)));
    // 0x8008F4EC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8008F4F0: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x8008F4F4: bne         $t2, $zero, L_8008F500
    if (ctx->r10 != 0) {
        // 0x8008F4F8: nop

            goto L_8008F500;
    }
    // 0x8008F4F8: nop

    // 0x8008F4FC: break       7
    do_break(2148070652);
L_8008F500:
    // 0x8008F500: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008F504: bne         $t2, $at, L_8008F518
    if (ctx->r10 != ctx->r1) {
        // 0x8008F508: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008F518;
    }
    // 0x8008F508: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008F50C: bne         $t5, $at, L_8008F518
    if (ctx->r13 != ctx->r1) {
        // 0x8008F510: nop

            goto L_8008F518;
    }
    // 0x8008F510: nop

    // 0x8008F514: break       6
    do_break(2148070676);
L_8008F518:
    // 0x8008F518: mflo        $t1
    ctx->r9 = lo;
    // 0x8008F51C: sw          $t1, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r9;
    // 0x8008F520: nop

    // 0x8008F524: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F528: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8008F52C: nop

    // 0x8008F530: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x8008F534: bne         $t9, $zero, L_8008F540
    if (ctx->r25 != 0) {
        // 0x8008F538: nop

            goto L_8008F540;
    }
    // 0x8008F538: nop

    // 0x8008F53C: break       7
    do_break(2148070716);
L_8008F540:
    // 0x8008F540: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008F544: bne         $t9, $at, L_8008F558
    if (ctx->r25 != ctx->r1) {
        // 0x8008F548: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008F558;
    }
    // 0x8008F548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008F54C: bne         $t8, $at, L_8008F558
    if (ctx->r24 != ctx->r1) {
        // 0x8008F550: nop

            goto L_8008F558;
    }
    // 0x8008F550: nop

    // 0x8008F554: break       6
    do_break(2148070740);
L_8008F558:
    // 0x8008F558: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008F55C: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    // 0x8008F560: nop

    // 0x8008F564: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008F568: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008F56C: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8008F570: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008F574: nop

    // 0x8008F578: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8008F57C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8008F580: mflo        $t5
    ctx->r13 = lo;
    // 0x8008F584: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8008F588: bgtz        $t5, L_8008F4DC
    if (SIGNED(ctx->r13) > 0) {
        // 0x8008F58C: nop

            goto L_8008F4DC;
    }
    // 0x8008F58C: nop

    // 0x8008F590: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008F594: nop

    // 0x8008F598: addiu       $t6, $t1, -0xB
    ctx->r14 = ADD32(ctx->r9, -0XB);
    // 0x8008F59C: blez        $t6, L_8008F5DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8008F5A0: sw          $t6, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r14;
            goto L_8008F5DC;
    }
    // 0x8008F5A0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_8008F5A4:
    // 0x8008F5A4: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F5A8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8008F5AC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F5B0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F5B4: nop

    // 0x8008F5B8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F5BC: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8008F5C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008F5C4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008F5C8: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x8008F5CC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8008F5D0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8008F5D4: bgtz        $t2, L_8008F5A4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8008F5D8: sw          $t2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r10;
            goto L_8008F5A4;
    }
    // 0x8008F5D8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
L_8008F5DC:
    // 0x8008F5DC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008F5E0:
    // 0x8008F5E0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008F5E4: nop

    // 0x8008F5E8: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008F5EC: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x8008F5F0: lw          $t7, 0x4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4C);
    // 0x8008F5F4: nop

    // 0x8008F5F8: bne         $t7, $zero, L_8008F674
    if (ctx->r15 != 0) {
        // 0x8008F5FC: nop

            goto L_8008F674;
    }
    // 0x8008F5FC: nop

    // 0x8008F600: lbu         $t8, 0xC7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F604: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008F608: beq         $t8, $at, L_8008F650
    if (ctx->r24 == ctx->r1) {
        // 0x8008F60C: nop

            goto L_8008F650;
    }
    // 0x8008F60C: nop

    // 0x8008F610: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008F614: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008F618: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8008F61C: subu        $t4, $t3, $t0
    ctx->r12 = SUB32(ctx->r11, ctx->r8);
    // 0x8008F620: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008F624: bne         $at, $zero, L_8008F648
    if (ctx->r1 != 0) {
        // 0x8008F628: nop

            goto L_8008F648;
    }
    // 0x8008F628: nop

    // 0x8008F62C: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F630: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x8008F634: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8008F638: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F63C: nop

    // 0x8008F640: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F644: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_8008F648:
    // 0x8008F648: b           L_8008F66C
    // 0x8008F64C: nop

        goto L_8008F66C;
    // 0x8008F64C: nop

L_8008F650:
    // 0x8008F650: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F654: addiu       $t7, $zero, 0x30
    ctx->r15 = ADD32(0, 0X30);
    // 0x8008F658: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F65C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F660: nop

    // 0x8008F664: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x8008F668: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
L_8008F66C:
    // 0x8008F66C: b           L_8008F6EC
    // 0x8008F670: nop

        goto L_8008F6EC;
    // 0x8008F670: nop

L_8008F674:
    // 0x8008F674: lbu         $t9, 0xC7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F678: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008F67C: beq         $t9, $at, L_8008F6BC
    if (ctx->r25 == ctx->r1) {
        // 0x8008F680: nop

            goto L_8008F6BC;
    }
    // 0x8008F680: nop

    // 0x8008F684: lbu         $t4, 0xC7($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F688: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8008F68C: bne         $t4, $at, L_8008F6B4
    if (ctx->r12 != ctx->r1) {
        // 0x8008F690: nop

            goto L_8008F6B4;
    }
    // 0x8008F690: nop

    // 0x8008F694: lbu         $t5, 0xC7($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F698: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F69C: nop

    // 0x8008F6A0: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8008F6A4: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F6A8: nop

    // 0x8008F6AC: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F6B0: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_8008F6B4:
    // 0x8008F6B4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8008F6B8: sb          $t7, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r15;
L_8008F6BC:
    // 0x8008F6BC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008F6C0: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F6C4: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8008F6C8: addu        $t0, $sp, $t3
    ctx->r8 = ADD32(ctx->r29, ctx->r11);
    // 0x8008F6CC: lw          $t0, 0x4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4C);
    // 0x8008F6D0: nop

    // 0x8008F6D4: addiu       $t9, $t0, 0x30
    ctx->r25 = ADD32(ctx->r8, 0X30);
    // 0x8008F6D8: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    // 0x8008F6DC: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F6E0: nop

    // 0x8008F6E4: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x8008F6E8: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
L_8008F6EC:
    // 0x8008F6EC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008F6F0: nop

    // 0x8008F6F4: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F6F8: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x8008F6FC: bne         $at, $zero, L_8008F5E0
    if (ctx->r1 != 0) {
        // 0x8008F700: sw          $t6, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r14;
            goto L_8008F5E0;
    }
    // 0x8008F700: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8008F704: lbu         $t7, 0xC7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F708: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008F70C: beq         $t7, $at, L_8008F744
    if (ctx->r15 == ctx->r1) {
        // 0x8008F710: nop

            goto L_8008F744;
    }
    // 0x8008F710: nop

    // 0x8008F714: lbu         $t8, 0xC7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F718: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8008F71C: bne         $t8, $at, L_8008F744
    if (ctx->r24 != ctx->r1) {
        // 0x8008F720: nop

            goto L_8008F744;
    }
    // 0x8008F720: nop

    // 0x8008F724: lbu         $t3, 0xC7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F728: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F72C: nop

    // 0x8008F730: sb          $t3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r11;
    // 0x8008F734: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F738: nop

    // 0x8008F73C: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8008F740: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
L_8008F744:
    // 0x8008F744: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008F748: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F74C: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8008F750: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x8008F754: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x8008F758: nop

    // 0x8008F75C: addiu       $t6, $t1, 0x30
    ctx->r14 = ADD32(ctx->r9, 0X30);
    // 0x8008F760: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8008F764: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F768: nop

    // 0x8008F76C: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8008F770: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8008F774: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8008F778: b           L_800906A0
    // 0x8008F77C: nop

        goto L_800906A0;
    // 0x8008F77C: nop

L_8008F780:
    // 0x8008F780: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8008F784: sb          $t0, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r8;
    // 0x8008F788: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8008F78C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008F790: addiu       $t4, $t9, 0x3
    ctx->r12 = ADD32(ctx->r25, 0X3);
    // 0x8008F794: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8008F798: addiu       $t2, $t5, 0x4
    ctx->r10 = ADD32(ctx->r13, 0X4);
    // 0x8008F79C: sw          $t2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r10;
    // 0x8008F7A0: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x8008F7A4: nop

    // 0x8008F7A8: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
    // 0x8008F7AC: lui         $t6, 0x1000
    ctx->r14 = S32(0X1000 << 16);
    // 0x8008F7B0: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8008F7B4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008F7B8:
    // 0x8008F7B8: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F7BC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8008F7C0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008F7C4: divu        $zero, $t7, $t8
    lo = S32(U32(ctx->r15) / U32(ctx->r24)); hi = S32(U32(ctx->r15) % U32(ctx->r24));
    // 0x8008F7C8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8008F7CC: addu        $t4, $sp, $t9
    ctx->r12 = ADD32(ctx->r29, ctx->r25);
    // 0x8008F7D0: bne         $t8, $zero, L_8008F7DC
    if (ctx->r24 != 0) {
        // 0x8008F7D4: nop

            goto L_8008F7DC;
    }
    // 0x8008F7D4: nop

    // 0x8008F7D8: break       7
    do_break(2148071384);
L_8008F7DC:
    // 0x8008F7DC: mflo        $t3
    ctx->r11 = lo;
    // 0x8008F7E0: sw          $t3, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->r11;
    // 0x8008F7E4: nop

    // 0x8008F7E8: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F7EC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008F7F0: nop

    // 0x8008F7F4: divu        $zero, $t2, $t5
    lo = S32(U32(ctx->r10) / U32(ctx->r13)); hi = S32(U32(ctx->r10) % U32(ctx->r13));
    // 0x8008F7F8: bne         $t5, $zero, L_8008F804
    if (ctx->r13 != 0) {
        // 0x8008F7FC: nop

            goto L_8008F804;
    }
    // 0x8008F7FC: nop

    // 0x8008F800: break       7
    do_break(2148071424);
L_8008F804:
    // 0x8008F804: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008F808: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
    // 0x8008F80C: nop

    // 0x8008F810: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008F814: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008F818: bgez        $t6, L_8008F828
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008F81C: sra         $t7, $t6, 4
        ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
            goto L_8008F828;
    }
    // 0x8008F81C: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x8008F820: addiu       $at, $t6, 0xF
    ctx->r1 = ADD32(ctx->r14, 0XF);
    // 0x8008F824: sra         $t7, $at, 4
    ctx->r15 = S32(SIGNED(ctx->r1) >> 4);
L_8008F828:
    // 0x8008F828: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8008F82C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8008F830: bgtz        $t7, L_8008F7B8
    if (SIGNED(ctx->r15) > 0) {
        // 0x8008F834: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_8008F7B8;
    }
    // 0x8008F834: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8008F838: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008F83C: nop

    // 0x8008F840: addiu       $t9, $t3, -0x9
    ctx->r25 = ADD32(ctx->r11, -0X9);
    // 0x8008F844: blez        $t9, L_8008F8B4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8008F848: sw          $t9, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r25;
            goto L_8008F8B4;
    }
    // 0x8008F848: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_8008F84C:
    // 0x8008F84C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F850: nop

    // 0x8008F854: beq         $t4, $zero, L_8008F87C
    if (ctx->r12 == 0) {
        // 0x8008F858: nop

            goto L_8008F87C;
    }
    // 0x8008F858: nop

    // 0x8008F85C: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F860: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x8008F864: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8008F868: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F86C: nop

    // 0x8008F870: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F874: b           L_8008F898
    // 0x8008F878: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
        goto L_8008F898;
    // 0x8008F878: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_8008F87C:
    // 0x8008F87C: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F880: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8008F884: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x8008F888: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F88C: nop

    // 0x8008F890: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x8008F894: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
L_8008F898:
    // 0x8008F898: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008F89C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008F8A0: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x8008F8A4: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x8008F8A8: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8008F8AC: bgtz        $t4, L_8008F84C
    if (SIGNED(ctx->r12) > 0) {
        // 0x8008F8B0: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_8008F84C;
    }
    // 0x8008F8B0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_8008F8B4:
    // 0x8008F8B4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008F8B8:
    // 0x8008F8B8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008F8BC: nop

    // 0x8008F8C0: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008F8C4: addu        $t8, $sp, $t6
    ctx->r24 = ADD32(ctx->r29, ctx->r14);
    // 0x8008F8C8: lw          $t8, 0x4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C);
    // 0x8008F8CC: nop

    // 0x8008F8D0: bne         $t8, $zero, L_8008F97C
    if (ctx->r24 != 0) {
        // 0x8008F8D4: nop

            goto L_8008F97C;
    }
    // 0x8008F8D4: nop

    // 0x8008F8D8: lbu         $t0, 0xC7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F8DC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008F8E0: beq         $t0, $at, L_8008F958
    if (ctx->r8 == ctx->r1) {
        // 0x8008F8E4: nop

            goto L_8008F958;
    }
    // 0x8008F8E4: nop

    // 0x8008F8E8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008F8EC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008F8F0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8008F8F4: subu        $t2, $t9, $t3
    ctx->r10 = SUB32(ctx->r25, ctx->r11);
    // 0x8008F8F8: slt         $at, $t7, $t2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008F8FC: bne         $at, $zero, L_8008F950
    if (ctx->r1 != 0) {
        // 0x8008F900: nop

            goto L_8008F950;
    }
    // 0x8008F900: nop

    // 0x8008F904: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F908: nop

    // 0x8008F90C: beq         $t5, $zero, L_8008F934
    if (ctx->r13 == 0) {
        // 0x8008F910: nop

            goto L_8008F934;
    }
    // 0x8008F910: nop

    // 0x8008F914: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F918: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x8008F91C: sb          $t4, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r12;
    // 0x8008F920: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F924: nop

    // 0x8008F928: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8008F92C: b           L_8008F950
    // 0x8008F930: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
        goto L_8008F950;
    // 0x8008F930: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
L_8008F934:
    // 0x8008F934: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F938: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8008F93C: sb          $t0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r8;
    // 0x8008F940: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F944: nop

    // 0x8008F948: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x8008F94C: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
L_8008F950:
    // 0x8008F950: b           L_8008F974
    // 0x8008F954: nop

        goto L_8008F974;
    // 0x8008F954: nop

L_8008F958:
    // 0x8008F958: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F95C: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x8008F960: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8008F964: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F968: nop

    // 0x8008F96C: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008F970: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
L_8008F974:
    // 0x8008F974: b           L_8008FA58
    // 0x8008F978: nop

        goto L_8008FA58;
    // 0x8008F978: nop

L_8008F97C:
    // 0x8008F97C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008F980: sb          $t6, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r14;
    // 0x8008F984: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008F988: nop

    // 0x8008F98C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8008F990: addu        $t9, $sp, $t0
    ctx->r25 = ADD32(ctx->r29, ctx->r8);
    // 0x8008F994: lw          $t9, 0x4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4C);
    // 0x8008F998: nop

    // 0x8008F99C: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8008F9A0: beq         $at, $zero, L_8008F9DC
    if (ctx->r1 == 0) {
        // 0x8008F9A4: nop

            goto L_8008F9DC;
    }
    // 0x8008F9A4: nop

    // 0x8008F9A8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008F9AC: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F9B0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8008F9B4: addu        $t2, $sp, $t7
    ctx->r10 = ADD32(ctx->r29, ctx->r15);
    // 0x8008F9B8: lw          $t2, 0x4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4C);
    // 0x8008F9BC: nop

    // 0x8008F9C0: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x8008F9C4: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8008F9C8: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F9CC: nop

    // 0x8008F9D0: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F9D4: b           L_8008FA58
    // 0x8008F9D8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
        goto L_8008FA58;
    // 0x8008F9D8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_8008F9DC:
    // 0x8008F9DC: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F9E0: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8008F9E4: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x8008F9E8: nop

    // 0x8008F9EC: bne         $t0, $at, L_8008FA28
    if (ctx->r8 != ctx->r1) {
        // 0x8008F9F0: nop

            goto L_8008FA28;
    }
    // 0x8008F9F0: nop

    // 0x8008F9F4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008F9F8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F9FC: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8008FA00: addu        $t7, $sp, $t3
    ctx->r15 = ADD32(ctx->r29, ctx->r11);
    // 0x8008FA04: lw          $t7, 0x4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4C);
    // 0x8008FA08: nop

    // 0x8008FA0C: addiu       $t2, $t7, 0x57
    ctx->r10 = ADD32(ctx->r15, 0X57);
    // 0x8008FA10: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8008FA14: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FA18: nop

    // 0x8008FA1C: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008FA20: b           L_8008FA58
    // 0x8008FA24: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
        goto L_8008FA58;
    // 0x8008FA24: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
L_8008FA28:
    // 0x8008FA28: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008FA2C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FA30: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8008FA34: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x8008FA38: lw          $t0, 0x4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4C);
    // 0x8008FA3C: nop

    // 0x8008FA40: addiu       $t9, $t0, 0x37
    ctx->r25 = ADD32(ctx->r8, 0X37);
    // 0x8008FA44: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
    // 0x8008FA48: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FA4C: nop

    // 0x8008FA50: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8008FA54: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
L_8008FA58:
    // 0x8008FA58: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008FA5C: nop

    // 0x8008FA60: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008FA64: slti        $at, $t4, 0x7
    ctx->r1 = SIGNED(ctx->r12) < 0X7 ? 1 : 0;
    // 0x8008FA68: bne         $at, $zero, L_8008F8B8
    if (ctx->r1 != 0) {
        // 0x8008FA6C: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_8008F8B8;
    }
    // 0x8008FA6C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8008FA70: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008FA74: nop

    // 0x8008FA78: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008FA7C: addu        $t8, $sp, $t6
    ctx->r24 = ADD32(ctx->r29, ctx->r14);
    // 0x8008FA80: lw          $t8, 0x4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C);
    // 0x8008FA84: nop

    // 0x8008FA88: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x8008FA8C: beq         $at, $zero, L_8008FAC8
    if (ctx->r1 == 0) {
        // 0x8008FA90: nop

            goto L_8008FAC8;
    }
    // 0x8008FA90: nop

    // 0x8008FA94: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008FA98: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FA9C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8008FAA0: addu        $t3, $sp, $t9
    ctx->r11 = ADD32(ctx->r29, ctx->r25);
    // 0x8008FAA4: lw          $t3, 0x4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4C);
    // 0x8008FAA8: nop

    // 0x8008FAAC: addiu       $t7, $t3, 0x30
    ctx->r15 = ADD32(ctx->r11, 0X30);
    // 0x8008FAB0: sb          $t7, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r15;
    // 0x8008FAB4: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FAB8: nop

    // 0x8008FABC: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008FAC0: b           L_8008FB44
    // 0x8008FAC4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
        goto L_8008FB44;
    // 0x8008FAC4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
L_8008FAC8:
    // 0x8008FAC8: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8008FACC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8008FAD0: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x8008FAD4: nop

    // 0x8008FAD8: bne         $t6, $at, L_8008FB14
    if (ctx->r14 != ctx->r1) {
        // 0x8008FADC: nop

            goto L_8008FB14;
    }
    // 0x8008FADC: nop

    // 0x8008FAE0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008FAE4: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FAE8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8008FAEC: addu        $t9, $sp, $t0
    ctx->r25 = ADD32(ctx->r29, ctx->r8);
    // 0x8008FAF0: lw          $t9, 0x4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4C);
    // 0x8008FAF4: nop

    // 0x8008FAF8: addiu       $t3, $t9, 0x57
    ctx->r11 = ADD32(ctx->r25, 0X57);
    // 0x8008FAFC: sb          $t3, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r11;
    // 0x8008FB00: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FB04: nop

    // 0x8008FB08: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8008FB0C: b           L_8008FB44
    // 0x8008FB10: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
        goto L_8008FB44;
    // 0x8008FB10: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
L_8008FB14:
    // 0x8008FB14: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008FB18: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FB1C: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8008FB20: addu        $t6, $sp, $t1
    ctx->r14 = ADD32(ctx->r29, ctx->r9);
    // 0x8008FB24: lw          $t6, 0x4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4C);
    // 0x8008FB28: nop

    // 0x8008FB2C: addiu       $t8, $t6, 0x37
    ctx->r24 = ADD32(ctx->r14, 0X37);
    // 0x8008FB30: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x8008FB34: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FB38: nop

    // 0x8008FB3C: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x8008FB40: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
L_8008FB44:
    // 0x8008FB44: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8008FB48: b           L_800906A0
    // 0x8008FB4C: nop

        goto L_800906A0;
    // 0x8008FB4C: nop

L_8008FB50:
    // 0x8008FB50: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8008FB54: lh          $t7, -0x4CC8($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4CC8);
    // 0x8008FB58: nop

    // 0x8008FB5C: andi        $t2, $t7, 0x200
    ctx->r10 = ctx->r15 & 0X200;
    // 0x8008FB60: bne         $t2, $zero, L_8008FD0C
    if (ctx->r10 != 0) {
        // 0x8008FB64: nop

            goto L_8008FD0C;
    }
    // 0x8008FB64: nop

    // 0x8008FB68: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8008FB6C: lh          $t5, -0x4CC8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4CC8);
    // 0x8008FB70: nop

    // 0x8008FB74: andi        $t4, $t5, 0x10
    ctx->r12 = ctx->r13 & 0X10;
    // 0x8008FB78: beq         $t4, $zero, L_8008FC00
    if (ctx->r12 == 0) {
        // 0x8008FB7C: nop

            goto L_8008FC00;
    }
    // 0x8008FB7C: nop

    // 0x8008FB80: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FB84: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008FB88: addiu       $t6, $t1, 0x3
    ctx->r14 = ADD32(ctx->r9, 0X3);
    // 0x8008FB8C: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8008FB90: addiu       $t0, $t8, 0x4
    ctx->r8 = ADD32(ctx->r24, 0X4);
    // 0x8008FB94: sw          $t0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r8;
    // 0x8008FB98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008FB9C: nop

    // 0x8008FBA0: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    // 0x8008FBA4: lbu         $t3, 0x0($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X0);
    // 0x8008FBA8: nop

    // 0x8008FBAC: beq         $t3, $zero, L_8008FBF8
    if (ctx->r11 == 0) {
        // 0x8008FBB0: nop

            goto L_8008FBF8;
    }
    // 0x8008FBB0: nop

L_8008FBB4:
    // 0x8008FBB4: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FBB8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FBBC: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x8008FBC0: nop

    // 0x8008FBC4: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8008FBC8: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FBCC: nop

    // 0x8008FBD0: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008FBD4: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x8008FBD8: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FBDC: nop

    // 0x8008FBE0: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8008FBE4: sw          $t0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r8;
    // 0x8008FBE8: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x8008FBEC: nop

    // 0x8008FBF0: bne         $t8, $zero, L_8008FBB4
    if (ctx->r24 != 0) {
        // 0x8008FBF4: nop

            goto L_8008FBB4;
    }
    // 0x8008FBF4: nop

L_8008FBF8:
    // 0x8008FBF8: b           L_8008FD04
    // 0x8008FBFC: nop

        goto L_8008FD04;
    // 0x8008FBFC: nop

L_8008FC00:
    // 0x8008FC00: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FC04: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008FC08: addiu       $t3, $t9, 0x3
    ctx->r11 = ADD32(ctx->r25, 0X3);
    // 0x8008FC0C: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8008FC10: addiu       $t2, $t7, 0x4
    ctx->r10 = ADD32(ctx->r15, 0X4);
    // 0x8008FC14: sw          $t2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r10;
    // 0x8008FC18: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x8008FC1C: nop

    // 0x8008FC20: sw          $t5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r13;
    // 0x8008FC24: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008FC28: nop

    // 0x8008FC2C: beq         $t4, $zero, L_8008FD04
    if (ctx->r12 == 0) {
        // 0x8008FC30: nop

            goto L_8008FD04;
    }
    // 0x8008FC30: nop

L_8008FC34:
    // 0x8008FC34: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FC38: nop

    // 0x8008FC3C: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x8008FC40: nop

    // 0x8008FC44: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x8008FC48: bne         $at, $zero, L_8008FCC0
    if (ctx->r1 != 0) {
        // 0x8008FC4C: nop

            goto L_8008FCC0;
    }
    // 0x8008FC4C: nop

    // 0x8008FC50: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FC54: jal         0x80095E78
    // 0x8008FC58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_8;
    // 0x8008FC58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8008FC5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008FC60: jal         0x80095F9C
    // 0x8008FC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_9;
    // 0x8008FC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8008FC68: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008FC6C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008FC70: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FC74: srl         $t8, $t0, 8
    ctx->r24 = S32(U32(ctx->r8) >> 8);
    // 0x8008FC78: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8008FC7C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FC80: nop

    // 0x8008FC84: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8008FC88: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x8008FC8C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008FC90: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FC94: andi        $t5, $t7, 0xFF
    ctx->r13 = ctx->r15 & 0XFF;
    // 0x8008FC98: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8008FC9C: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FCA0: nop

    // 0x8008FCA4: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008FCA8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x8008FCAC: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FCB0: nop

    // 0x8008FCB4: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8008FCB8: b           L_8008FCE4
    // 0x8008FCBC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_8008FCE4;
    // 0x8008FCBC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_8008FCC0:
    // 0x8008FCC0: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FCC4: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FCC8: lbu         $t3, 0x0($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X0);
    // 0x8008FCCC: nop

    // 0x8008FCD0: sb          $t3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r11;
    // 0x8008FCD4: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FCD8: nop

    // 0x8008FCDC: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8008FCE0: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
L_8008FCE4:
    // 0x8008FCE4: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FCE8: nop

    // 0x8008FCEC: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008FCF0: sw          $t1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r9;
    // 0x8008FCF4: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x8008FCF8: nop

    // 0x8008FCFC: bne         $t6, $zero, L_8008FC34
    if (ctx->r14 != 0) {
        // 0x8008FD00: nop

            goto L_8008FC34;
    }
    // 0x8008FD00: nop

L_8008FD04:
    // 0x8008FD04: b           L_8008FE10
    // 0x8008FD08: nop

        goto L_8008FE10;
    // 0x8008FD08: nop

L_8008FD0C:
    // 0x8008FD0C: lw          $t0, 0xF8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FD10: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008FD14: addiu       $t8, $t0, 0x3
    ctx->r24 = ADD32(ctx->r8, 0X3);
    // 0x8008FD18: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8008FD1C: addiu       $t3, $t9, 0x4
    ctx->r11 = ADD32(ctx->r25, 0X4);
    // 0x8008FD20: sw          $t3, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r11;
    // 0x8008FD24: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8008FD28: nop

    // 0x8008FD2C: sw          $t2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r10;
    // 0x8008FD30: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    // 0x8008FD34: nop

    // 0x8008FD38: beq         $t7, $zero, L_8008FE10
    if (ctx->r15 == 0) {
        // 0x8008FD3C: nop

            goto L_8008FE10;
    }
    // 0x8008FD3C: nop

L_8008FD40:
    // 0x8008FD40: lw          $t5, 0xD4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FD44: nop

    // 0x8008FD48: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008FD4C: nop

    // 0x8008FD50: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x8008FD54: bne         $at, $zero, L_8008FDCC
    if (ctx->r1 != 0) {
        // 0x8008FD58: nop

            goto L_8008FDCC;
    }
    // 0x8008FD58: nop

    // 0x8008FD5C: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FD60: jal         0x80095E78
    // 0x8008FD64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_10;
    // 0x8008FD64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8008FD68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008FD6C: jal         0x80095F9C
    // 0x8008FD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_11;
    // 0x8008FD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8008FD74: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008FD78: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008FD7C: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FD80: srl         $t6, $t1, 8
    ctx->r14 = S32(U32(ctx->r9) >> 8);
    // 0x8008FD84: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
    // 0x8008FD88: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FD8C: nop

    // 0x8008FD90: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8008FD94: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8008FD98: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008FD9C: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FDA0: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x8008FDA4: sb          $t2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r10;
    // 0x8008FDA8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FDAC: nop

    // 0x8008FDB0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008FDB4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x8008FDB8: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FDBC: nop

    // 0x8008FDC0: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008FDC4: b           L_8008FDF0
    // 0x8008FDC8: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
        goto L_8008FDF0;
    // 0x8008FDC8: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
L_8008FDCC:
    // 0x8008FDCC: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FDD0: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FDD4: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x8008FDD8: nop

    // 0x8008FDDC: sb          $t8, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r24;
    // 0x8008FDE0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FDE4: nop

    // 0x8008FDE8: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8008FDEC: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
L_8008FDF0:
    // 0x8008FDF0: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FDF4: nop

    // 0x8008FDF8: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8008FDFC: sw          $t5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r13;
    // 0x8008FE00: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008FE04: nop

    // 0x8008FE08: bne         $t4, $zero, L_8008FD40
    if (ctx->r12 != 0) {
        // 0x8008FE0C: nop

            goto L_8008FD40;
    }
    // 0x8008FE0C: nop

L_8008FE10:
    // 0x8008FE10: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8008FE14: b           L_800906A0
    // 0x8008FE18: nop

        goto L_800906A0;
    // 0x8008FE18: nop

L_8008FE1C:
    // 0x8008FE1C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8008FE20: nop

    // 0x8008FE24: bne         $t1, $zero, L_8008FE34
    if (ctx->r9 != 0) {
        // 0x8008FE28: nop

            goto L_8008FE34;
    }
    // 0x8008FE28: nop

    // 0x8008FE2C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8008FE30: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_8008FE34:
    // 0x8008FE34: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8008FE38: sb          $t0, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r8;
    // 0x8008FE3C: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FE40: nop

    // 0x8008FE44: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x8008FE48: beq         $t3, $zero, L_8008FE60
    if (ctx->r11 == 0) {
        // 0x8008FE4C: nop

            goto L_8008FE60;
    }
    // 0x8008FE4C: nop

    // 0x8008FE50: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x8008FE54: sw          $t9, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r25;
    // 0x8008FE58: b           L_8008FEA4
    // 0x8008FE5C: addiu       $s0, $t9, -0x16
    ctx->r16 = ADD32(ctx->r25, -0X16);
        goto L_8008FEA4;
    // 0x8008FE5C: addiu       $s0, $t9, -0x16
    ctx->r16 = ADD32(ctx->r25, -0X16);
L_8008FE60:
    // 0x8008FE60: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FE64: nop

    // 0x8008FE68: andi        $t7, $t2, 0x2
    ctx->r15 = ctx->r10 & 0X2;
    // 0x8008FE6C: beq         $t7, $zero, L_8008FE84
    if (ctx->r15 == 0) {
        // 0x8008FE70: nop

            goto L_8008FE84;
    }
    // 0x8008FE70: nop

    // 0x8008FE74: addiu       $t5, $t2, 0xA
    ctx->r13 = ADD32(ctx->r10, 0XA);
    // 0x8008FE78: sw          $t5, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r13;
    // 0x8008FE7C: b           L_8008FEA0
    // 0x8008FE80: addiu       $s1, $t5, -0x28
    ctx->r17 = ADD32(ctx->r13, -0X28);
        goto L_8008FEA0;
    // 0x8008FE80: addiu       $s1, $t5, -0x28
    ctx->r17 = ADD32(ctx->r13, -0X28);
L_8008FE84:
    // 0x8008FE84: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FE88: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8008FE8C: addiu       $t1, $t4, 0x7
    ctx->r9 = ADD32(ctx->r12, 0X7);
    // 0x8008FE90: and         $t6, $t1, $at
    ctx->r14 = ctx->r9 & ctx->r1;
    // 0x8008FE94: addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
    // 0x8008FE98: sw          $t0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r8;
    // 0x8008FE9C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
L_8008FEA0:
    // 0x8008FEA0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8008FEA4:
    // 0x8008FEA4: lwc1        $f5, -0x8($s0)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r16, -0X8);
    // 0x8008FEA8: lwc1        $f4, -0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X4);
    // 0x8008FEAC: swc1        $f5, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x8008FEB0: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x8008FEB4: lwc1        $f7, 0xE0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x8008FEB8: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8008FEBC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8008FEC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008FEC4: nop

    // 0x8008FEC8: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8008FECC: nop

    // 0x8008FED0: bc1f        L_8008FEF8
    if (!c1cs) {
        // 0x8008FED4: nop

            goto L_8008FEF8;
    }
    // 0x8008FED4: nop

    // 0x8008FED8: addiu       $t3, $zero, 0x2D
    ctx->r11 = ADD32(0, 0X2D);
    // 0x8008FEDC: sb          $t3, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r11;
    // 0x8008FEE0: lwc1        $f11, 0xE0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x8008FEE4: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8008FEE8: nop

    // 0x8008FEEC: neg.d       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.d = -ctx->f10.d;
    // 0x8008FEF0: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x8008FEF4: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
L_8008FEF8:
    // 0x8008FEF8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8008FEFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008FF00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008FF04: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8008FF08: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8008FF0C: swc1        $f19, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x8008FF10: blez        $t8, L_8008FF50
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008FF14: swc1        $f18, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
            goto L_8008FF50;
    }
    // 0x8008FF14: swc1        $f18, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
L_8008FF18:
    // 0x8008FF18: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8008FF1C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008FF20: lwc1        $f5, 0xD8($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x8008FF24: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8008FF28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008FF2C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008FF30: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8008FF34: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8008FF38: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8008FF3C: slt         $at, $t7, $t2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008FF40: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8008FF44: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x8008FF48: bne         $at, $zero, L_8008FF18
    if (ctx->r1 != 0) {
        // 0x8008FF4C: swc1        $f9, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
            goto L_8008FF18;
    }
    // 0x8008FF4C: swc1        $f9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
L_8008FF50:
    // 0x8008FF50: lwc1        $f11, 0xE0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x8008FF54: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8008FF58: lwc1        $f17, 0xD8($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x8008FF5C: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8008FF60: nop

    // 0x8008FF64: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8008FF68: swc1        $f18, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f18.u32l;
    // 0x8008FF6C: swc1        $f19, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x8008FF70: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008FF74: lwc1        $f5, -0x8C0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X8C0);
    // 0x8008FF78: lwc1        $f4, -0x8BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X8BC);
    // 0x8008FF7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008FF80: lwc1        $f7, -0x8B8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X8B8);
    // 0x8008FF84: lwc1        $f6, -0x8B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X8B4);
    // 0x8008FF88: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8008FF8C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8008FF90: swc1        $f5, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x8008FF94: bc1f        L_80090060
    if (!c1cs) {
        // 0x8008FF98: swc1        $f4, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
            goto L_80090060;
    }
    // 0x8008FF98: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
L_8008FF9C:
    // 0x8008FF9C: lwc1        $f9, 0xE0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x8008FFA0: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8008FFA4: lwc1        $f11, 0xD8($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x8008FFA8: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8008FFAC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008FFB0: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8008FFB4: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8008FFB8: addu        $t6, $sp, $t1
    ctx->r14 = ADD32(ctx->r29, ctx->r9);
    // 0x8008FFBC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8008FFC0: nop

    // 0x8008FFC4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8008FFC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008FFCC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008FFD0: nop

    // 0x8008FFD4: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x8008FFD8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8008FFDC: swc1        $f18, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f18.u32l;
    // 0x8008FFE0: nop

    // 0x8008FFE4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008FFE8: lwc1        $f9, 0xD8($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x8008FFEC: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8008FFF0: addu        $t8, $sp, $t3
    ctx->r24 = ADD32(ctx->r29, ctx->r11);
    // 0x8008FFF4: lw          $t8, 0x4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C);
    // 0x8008FFF8: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8008FFFC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80090000: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x80090004: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80090008: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8009000C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80090010: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x80090014: swc1        $f18, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f18.u32l;
    // 0x80090018: swc1        $f19, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x8009001C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80090020: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80090024: lwc1        $f5, 0xD8($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x80090028: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8009002C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80090030: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80090034: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80090038: lwc1        $f17, -0x8B0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X8B0);
    // 0x8009003C: lwc1        $f16, -0x8AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X8AC);
    // 0x80090040: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80090044: nop

    // 0x80090048: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8009004C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80090050: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x80090054: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x80090058: bc1t        L_8008FF9C
    if (c1cs) {
        // 0x8009005C: swc1        $f9, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
            goto L_8008FF9C;
    }
    // 0x8009005C: swc1        $f9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
L_80090060:
    // 0x80090060: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80090064: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80090068: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x8009006C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80090070: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80090074:
    // 0x80090074: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80090078: nop

    // 0x8009007C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80090080: addu        $t0, $sp, $t6
    ctx->r8 = ADD32(ctx->r29, ctx->r14);
    // 0x80090084: lw          $t0, 0x4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4C);
    // 0x80090088: nop

    // 0x8009008C: blez        $t0, L_800900A8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80090090: nop

            goto L_800900A8;
    }
    // 0x80090090: nop

    // 0x80090094: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x80090098: beq         $at, $zero, L_800900A8
    if (ctx->r1 == 0) {
        // 0x8009009C: nop

            goto L_800900A8;
    }
    // 0x8009009C: nop

    // 0x800900A0: b           L_800900D8
    // 0x800900A4: nop

        goto L_800900D8;
    // 0x800900A4: nop

L_800900A8:
    // 0x800900A8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800900AC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800900B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800900B4: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x800900B8: sw          $t3, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r11;
    // 0x800900BC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800900C0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800900C4: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x800900C8: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x800900CC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800900D0: bgtz        $t5, L_80090074
    if (SIGNED(ctx->r13) > 0) {
        // 0x800900D4: sw          $t5, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r13;
            goto L_80090074;
    }
    // 0x800900D4: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800900D8:
    // 0x800900D8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800900DC: nop

    // 0x800900E0: addiu       $t0, $t6, -0xB
    ctx->r8 = ADD32(ctx->r14, -0XB);
    // 0x800900E4: blez        $t0, L_80090124
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800900E8: sw          $t0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r8;
            goto L_80090124;
    }
    // 0x800900E8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_800900EC:
    // 0x800900EC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800900F0: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800900F4: sb          $t8, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r24;
    // 0x800900F8: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800900FC: nop

    // 0x80090100: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80090104: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80090108: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8009010C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80090110: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80090114: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x80090118: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8009011C: bgtz        $t4, L_800900EC
    if (SIGNED(ctx->r12) > 0) {
        // 0x80090120: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_800900EC;
    }
    // 0x80090120: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_80090124:
    // 0x80090124: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80090128:
    // 0x80090128: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8009012C: nop

    // 0x80090130: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80090134: addu        $t8, $sp, $t0
    ctx->r24 = ADD32(ctx->r29, ctx->r8);
    // 0x80090138: lw          $t8, 0x4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C);
    // 0x8009013C: nop

    // 0x80090140: bne         $t8, $zero, L_800901BC
    if (ctx->r24 != 0) {
        // 0x80090144: nop

            goto L_800901BC;
    }
    // 0x80090144: nop

    // 0x80090148: lbu         $t3, 0xC7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XC7);
    // 0x8009014C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80090150: beq         $t3, $at, L_80090198
    if (ctx->r11 == ctx->r1) {
        // 0x80090154: nop

            goto L_80090198;
    }
    // 0x80090154: nop

    // 0x80090158: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8009015C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80090160: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80090164: subu        $t1, $t2, $t7
    ctx->r9 = SUB32(ctx->r10, ctx->r15);
    // 0x80090168: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8009016C: bne         $at, $zero, L_80090190
    if (ctx->r1 != 0) {
        // 0x80090170: nop

            goto L_80090190;
    }
    // 0x80090170: nop

    // 0x80090174: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80090178: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x8009017C: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x80090180: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80090184: nop

    // 0x80090188: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8009018C: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
L_80090190:
    // 0x80090190: b           L_800901B4
    // 0x80090194: nop

        goto L_800901B4;
    // 0x80090194: nop

L_80090198:
    // 0x80090198: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8009019C: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800901A0: sb          $t8, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r24;
    // 0x800901A4: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800901A8: nop

    // 0x800901AC: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x800901B0: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
L_800901B4:
    // 0x800901B4: b           L_80090234
    // 0x800901B8: nop

        goto L_80090234;
    // 0x800901B8: nop

L_800901BC:
    // 0x800901BC: lbu         $t9, 0xC7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XC7);
    // 0x800901C0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800901C4: beq         $t9, $at, L_80090204
    if (ctx->r25 == ctx->r1) {
        // 0x800901C8: nop

            goto L_80090204;
    }
    // 0x800901C8: nop

    // 0x800901CC: lbu         $t1, 0xC7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XC7);
    // 0x800901D0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800901D4: bne         $t1, $at, L_800901FC
    if (ctx->r9 != ctx->r1) {
        // 0x800901D8: nop

            goto L_800901FC;
    }
    // 0x800901D8: nop

    // 0x800901DC: lbu         $t5, 0xC7($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XC7);
    // 0x800901E0: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800901E4: nop

    // 0x800901E8: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x800901EC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800901F0: nop

    // 0x800901F4: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x800901F8: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
L_800901FC:
    // 0x800901FC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80090200: sb          $t8, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r24;
L_80090204:
    // 0x80090204: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80090208: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8009020C: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80090210: addu        $t7, $sp, $t2
    ctx->r15 = ADD32(ctx->r29, ctx->r10);
    // 0x80090214: lw          $t7, 0x4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4C);
    // 0x80090218: nop

    // 0x8009021C: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80090220: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x80090224: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80090228: nop

    // 0x8009022C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80090230: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
L_80090234:
    // 0x80090234: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80090238: nop

    // 0x8009023C: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x80090240: slti        $at, $t0, 0x9
    ctx->r1 = SIGNED(ctx->r8) < 0X9 ? 1 : 0;
    // 0x80090244: bne         $at, $zero, L_80090128
    if (ctx->r1 != 0) {
        // 0x80090248: sw          $t0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r8;
            goto L_80090128;
    }
    // 0x80090248: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8009024C: lbu         $t8, 0xC7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XC7);
    // 0x80090250: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80090254: beq         $t8, $at, L_8009028C
    if (ctx->r24 == ctx->r1) {
        // 0x80090258: nop

            goto L_8009028C;
    }
    // 0x80090258: nop

    // 0x8009025C: lbu         $t3, 0xC7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XC7);
    // 0x80090260: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80090264: bne         $t3, $at, L_8009028C
    if (ctx->r11 != ctx->r1) {
        // 0x80090268: nop

            goto L_8009028C;
    }
    // 0x80090268: nop

    // 0x8009026C: lbu         $t2, 0xC7($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XC7);
    // 0x80090270: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80090274: nop

    // 0x80090278: sb          $t2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r10;
    // 0x8009027C: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80090280: nop

    // 0x80090284: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80090288: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
L_8009028C:
    // 0x8009028C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80090290: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80090294: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80090298: addu        $t6, $sp, $t4
    ctx->r14 = ADD32(ctx->r29, ctx->r12);
    // 0x8009029C: lw          $t6, 0x4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4C);
    // 0x800902A0: nop

    // 0x800902A4: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x800902A8: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    // 0x800902AC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800902B0: nop

    // 0x800902B4: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x800902B8: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x800902BC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800902C0: nop

    // 0x800902C4: beq         $t7, $zero, L_800903CC
    if (ctx->r15 == 0) {
        // 0x800902C8: nop

            goto L_800903CC;
    }
    // 0x800902C8: nop

    // 0x800902CC: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x800902D0: addiu       $t9, $zero, 0x2E
    ctx->r25 = ADD32(0, 0X2E);
    // 0x800902D4: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x800902D8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800902DC: nop

    // 0x800902E0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800902E4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x800902E8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800902EC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_800902F0:
    // 0x800902F0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800902F4: nop

    // 0x800902F8: bgtz        $t0, L_80090308
    if (SIGNED(ctx->r8) > 0) {
        // 0x800902FC: nop

            goto L_80090308;
    }
    // 0x800902FC: nop

    // 0x80090300: b           L_80090380
    // 0x80090304: nop

        goto L_80090380;
    // 0x80090304: nop

L_80090308:
    // 0x80090308: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8009030C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80090310: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80090314: addu        $t2, $sp, $t3
    ctx->r10 = ADD32(ctx->r29, ctx->r11);
    // 0x80090318: lw          $t2, 0x4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4C);
    // 0x8009031C: nop

    // 0x80090320: bne         $t2, $at, L_80090330
    if (ctx->r10 != ctx->r1) {
        // 0x80090324: nop

            goto L_80090330;
    }
    // 0x80090324: nop

    // 0x80090328: b           L_80090380
    // 0x8009032C: nop

        goto L_80090380;
    // 0x8009032C: nop

L_80090330:
    // 0x80090330: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80090334: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80090338: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8009033C: addu        $t1, $sp, $t9
    ctx->r9 = ADD32(ctx->r29, ctx->r25);
    // 0x80090340: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80090344: nop

    // 0x80090348: addiu       $t5, $t1, 0x30
    ctx->r13 = ADD32(ctx->r9, 0X30);
    // 0x8009034C: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x80090350: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80090354: nop

    // 0x80090358: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8009035C: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x80090360: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80090364: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80090368: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8009036C: slti        $at, $t3, 0x13
    ctx->r1 = SIGNED(ctx->r11) < 0X13 ? 1 : 0;
    // 0x80090370: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x80090374: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80090378: bne         $at, $zero, L_800902F0
    if (ctx->r1 != 0) {
        // 0x8009037C: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_800902F0;
    }
    // 0x8009037C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_80090380:
    // 0x80090380: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80090384: nop

    // 0x80090388: blez        $t9, L_800903CC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8009038C: nop

            goto L_800903CC;
    }
    // 0x8009038C: nop

L_80090390:
    // 0x80090390: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80090394: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x80090398: sb          $t1, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r9;
    // 0x8009039C: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800903A0: nop

    // 0x800903A4: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800903A8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x800903AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800903B0: nop

    // 0x800903B4: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x800903B8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800903BC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800903C0: nop

    // 0x800903C4: bgtz        $t2, L_80090390
    if (SIGNED(ctx->r10) > 0) {
        // 0x800903C8: nop

            goto L_80090390;
    }
    // 0x800903C8: nop

L_800903CC:
    // 0x800903CC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800903D0: b           L_800906A0
    // 0x800903D4: nop

        goto L_800906A0;
    // 0x800903D4: nop

L_800903D8:
    // 0x800903D8: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x800903DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800903E0: addiu       $t3, $t7, 0x3
    ctx->r11 = ADD32(ctx->r15, 0X3);
    // 0x800903E4: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x800903E8: addiu       $t1, $t9, 0x4
    ctx->r9 = ADD32(ctx->r25, 0X4);
    // 0x800903EC: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x800903F0: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x800903F4: nop

    // 0x800903F8: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
    // 0x800903FC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80090400: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80090404: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x80090408: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8009040C: nop

    // 0x80090410: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x80090414: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80090418: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8009041C: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80090420: nop

    // 0x80090424: sb          $t2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r10;
    // 0x80090428: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8009042C: nop

    // 0x80090430: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x80090434: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x80090438: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8009043C: b           L_800906A0
    // 0x80090440: nop

        goto L_800906A0;
    // 0x80090440: nop

L_80090444:
    // 0x80090444: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x80090448: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8009044C: addiu       $t5, $t9, 0x3
    ctx->r13 = ADD32(ctx->r25, 0X3);
    // 0x80090450: and         $t4, $t5, $at
    ctx->r12 = ctx->r13 & ctx->r1;
    // 0x80090454: addiu       $t6, $t4, 0x4
    ctx->r14 = ADD32(ctx->r12, 0X4);
    // 0x80090458: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
    // 0x8009045C: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80090460: nop

    // 0x80090464: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    // 0x80090468: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8009046C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80090470: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x80090474: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80090478: nop

    // 0x8009047C: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x80090480: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x80090484: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x80090488: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8009048C: nop

    // 0x80090490: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
    // 0x80090494: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80090498: nop

    // 0x8009049C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800904A0: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x800904A4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800904A8: b           L_800906A0
    // 0x800904AC: nop

        goto L_800906A0;
    // 0x800904AC: nop

L_800904B0:
    // 0x800904B0: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x800904B4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800904B8: addiu       $t0, $t4, 0x3
    ctx->r8 = ADD32(ctx->r12, 0X3);
    // 0x800904BC: and         $t8, $t0, $at
    ctx->r24 = ctx->r8 & ctx->r1;
    // 0x800904C0: addiu       $t2, $t8, 0x4
    ctx->r10 = ADD32(ctx->r24, 0X4);
    // 0x800904C4: sw          $t2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r10;
    // 0x800904C8: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800904CC: nop

    // 0x800904D0: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
    // 0x800904D4: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x800904D8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800904DC: sb          $t3, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r11;
    // 0x800904E0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800904E4: nop

    // 0x800904E8: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x800904EC: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
    // 0x800904F0: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x800904F4: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800904F8: nop

    // 0x800904FC: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
    // 0x80090500: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x80090504: nop

    // 0x80090508: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8009050C: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x80090510: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80090514: b           L_800906A0
    // 0x80090518: nop

        goto L_800906A0;
    // 0x80090518: nop

L_8009051C:
    // 0x8009051C: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x80090520: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80090524: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x80090528: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8009052C: addiu       $t1, $t3, 0x4
    ctx->r9 = ADD32(ctx->r11, 0X4);
    // 0x80090530: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x80090534: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80090538: nop

    // 0x8009053C: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
    // 0x80090540: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80090544: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80090548: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8009054C: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80090550: nop

    // 0x80090554: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x80090558: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8009055C: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x80090560: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80090564: nop

    // 0x80090568: sb          $t2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r10;
    // 0x8009056C: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80090570: nop

    // 0x80090574: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80090578: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x8009057C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80090580: b           L_800906A0
    // 0x80090584: nop

        goto L_800906A0;
    // 0x80090584: nop

L_80090588:
    // 0x80090588: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8009058C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80090590: addiu       $t9, $t3, 0x3
    ctx->r25 = ADD32(ctx->r11, 0X3);
    // 0x80090594: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x80090598: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8009059C: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
    // 0x800905A0: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x800905A4: nop

    // 0x800905A8: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
    // 0x800905AC: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800905B0: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800905B4: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
    // 0x800905B8: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x800905BC: nop

    // 0x800905C0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800905C4: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x800905C8: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x800905CC: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800905D0: sra         $t3, $t1, 8
    ctx->r11 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800905D4: sb          $t3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r11;
    // 0x800905D8: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800905DC: nop

    // 0x800905E0: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x800905E4: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
    // 0x800905E8: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
    // 0x800905EC: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x800905F0: nop

    // 0x800905F4: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
    // 0x800905F8: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800905FC: nop

    // 0x80090600: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x80090604: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80090608: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8009060C: b           L_800906A0
    // 0x80090610: nop

        goto L_800906A0;
    // 0x80090610: nop

L_80090614:
    // 0x80090614: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x80090618: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8009061C: addiu       $t1, $t7, 0x3
    ctx->r9 = ADD32(ctx->r15, 0X3);
    // 0x80090620: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80090624: addiu       $t9, $t3, 0x4
    ctx->r25 = ADD32(ctx->r11, 0X4);
    // 0x80090628: sw          $t9, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r25;
    // 0x8009062C: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80090630: nop

    // 0x80090634: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x80090638: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8009063C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80090640: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x80090644: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x80090648: nop

    // 0x8009064C: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80090650: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x80090654: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x80090658: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8009065C: sra         $t7, $t8, 8
    ctx->r15 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80090660: sb          $t7, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r15;
    // 0x80090664: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80090668: nop

    // 0x8009066C: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80090670: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x80090674: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x80090678: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8009067C: nop

    // 0x80090680: sb          $t6, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r14;
    // 0x80090684: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80090688: nop

    // 0x8009068C: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x80090690: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x80090694: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80090698: b           L_800906A0
    // 0x8009069C: nop

        goto L_800906A0;
    // 0x8009069C: nop

L_800906A0:
    // 0x800906A0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800906A4: nop

    // 0x800906A8: bne         $t2, $zero, L_8008F300
    if (ctx->r10 != 0) {
        // 0x800906AC: nop

            goto L_8008F300;
    }
    // 0x800906AC: nop

L_800906B0:
    // 0x800906B0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x800906B4: nop

    // 0x800906B8: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800906BC: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x800906C0: lbu         $t1, 0x0($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X0);
    // 0x800906C4: nop

    // 0x800906C8: bne         $t1, $zero, L_8008EDF4
    if (ctx->r9 != 0) {
        // 0x800906CC: nop

            goto L_8008EDF4;
    }
    // 0x800906CC: nop

L_800906D0:
    // 0x800906D0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800906D4: nop

    // 0x800906D8: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800906DC: b           L_800906E4
    // 0x800906E0: nop

        goto L_800906E4;
    // 0x800906E0: nop

L_800906E4:
    // 0x800906E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800906E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800906EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800906F0: jr          $ra
    // 0x800906F4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x800906F4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_800906F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800906F8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800906FC: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80090700: sra         $t7, $a1, 15
    ctx->r15 = S32(SIGNED(ctx->r5) >> 15);
    // 0x80090704: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80090708: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009070C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80090710: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80090714: sh          $t8, -0x44B8($at)
    MEM_H(-0X44B8, ctx->r1) = ctx->r24;
    // 0x80090718: jr          $ra
    // 0x8009071C: nop

    return;
    // 0x8009071C: nop

    // 0x80090720: jr          $ra
    // 0x80090724: nop

    return;
    // 0x80090724: nop

;}
RECOMP_FUNC void func_80090728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090728: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8009072C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80090730: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090734: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80090738: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009073C: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x80090740: sh          $t7, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = ctx->r15;
    // 0x80090744: jr          $ra
    // 0x80090748: nop

    return;
    // 0x80090748: nop

    // 0x8009074C: jr          $ra
    // 0x80090750: nop

    return;
    // 0x80090750: nop

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
RECOMP_FUNC void func_80090784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090784: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80090788: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8009078C: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80090790: nop

    // 0x80090794: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80090798: bne         $t7, $zero, L_800907B0
    if (ctx->r15 != 0) {
        // 0x8009079C: nop

            goto L_800907B0;
    }
    // 0x8009079C: nop

    // 0x800907A0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800907A4: lw          $t8, -0x4CD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CD8);
    // 0x800907A8: b           L_800907C0
    // 0x800907AC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
        goto L_800907C0;
    // 0x800907AC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_800907B0:
    // 0x800907B0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800907B4: lw          $t9, -0x4CE0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CE0);
    // 0x800907B8: nop

    // 0x800907BC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_800907C0:
    // 0x800907C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800907C4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800907C8: nop

    // 0x800907CC: bne         $a0, $t0, L_8009082C
    if (ctx->r4 != ctx->r8) {
        // 0x800907D0: nop

            goto L_8009082C;
    }
    // 0x800907D0: nop

    // 0x800907D4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800907D8: lh          $t1, -0x4CC8($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CC8);
    // 0x800907DC: nop

    // 0x800907E0: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x800907E4: beq         $t2, $zero, L_8009082C
    if (ctx->r10 == 0) {
        // 0x800907E8: nop

            goto L_8009082C;
    }
    // 0x800907E8: nop

    // 0x800907EC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800907F0: lw          $t3, -0x4CD0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CD0);
    // 0x800907F4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800907F8: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800907FC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80090800: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80090804: lhu         $t6, -0x44B8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X44B8);
    // 0x80090808: nop

    // 0x8009080C: sh          $t6, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r14;
    // 0x80090810: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090814: lw          $t7, -0x4CD0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CD0);
    // 0x80090818: nop

    // 0x8009081C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80090820: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80090824: b           L_80090844
    // 0x80090828: nop

        goto L_80090844;
    // 0x80090828: nop

L_8009082C:
    // 0x8009082C: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80090830: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090834: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80090838: lhu         $t0, -0x44B8($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44B8);
    // 0x8009083C: nop

    // 0x80090840: sh          $t0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r8;
L_80090844:
    // 0x80090844: lhu         $t1, 0xE($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XE);
    // 0x80090848: nop

    // 0x8009084C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80090850: beq         $t2, $zero, L_80090890
    if (ctx->r10 == 0) {
        // 0x80090854: nop

            goto L_80090890;
    }
    // 0x80090854: nop

    // 0x80090858: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8009085C: lh          $t3, -0x4CC8($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4CC8);
    // 0x80090860: nop

    // 0x80090864: andi        $t4, $t3, 0x400
    ctx->r12 = ctx->r11 & 0X400;
    // 0x80090868: bne         $t4, $zero, L_80090884
    if (ctx->r12 != 0) {
        // 0x8009086C: nop

            goto L_80090884;
    }
    // 0x8009086C: nop

    // 0x80090870: lhu         $t5, 0xE($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XE);
    // 0x80090874: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x80090878: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8009087C: b           L_80090890
    // 0x80090880: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
        goto L_80090890;
    // 0x80090880: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
L_80090884:
    // 0x80090884: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80090888: addu        $t9, $a2, $a3
    ctx->r25 = ADD32(ctx->r6, ctx->r7);
    // 0x8009088C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_80090890:
    // 0x80090890: b           L_80090898
    // 0x80090894: nop

        goto L_80090898;
    // 0x80090894: nop

L_80090898:
    // 0x80090898: jr          $ra
    // 0x8009089C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8009089C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800908A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800908A0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800908A4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800908A8: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x800908AC: nop

    // 0x800908B0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800908B4: bne         $t7, $zero, L_800908CC
    if (ctx->r15 != 0) {
        // 0x800908B8: nop

            goto L_800908CC;
    }
    // 0x800908B8: nop

    // 0x800908BC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800908C0: lw          $t8, -0x4CD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CD8);
    // 0x800908C4: b           L_800908DC
    // 0x800908C8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
        goto L_800908DC;
    // 0x800908C8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_800908CC:
    // 0x800908CC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800908D0: lw          $t9, -0x4CE0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CE0);
    // 0x800908D4: nop

    // 0x800908D8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_800908DC:
    // 0x800908DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800908E0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800908E4: nop

    // 0x800908E8: bne         $a0, $t0, L_80090948
    if (ctx->r4 != ctx->r8) {
        // 0x800908EC: nop

            goto L_80090948;
    }
    // 0x800908EC: nop

    // 0x800908F0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800908F4: lh          $t1, -0x4CC8($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CC8);
    // 0x800908F8: nop

    // 0x800908FC: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x80090900: beq         $t2, $zero, L_80090948
    if (ctx->r10 == 0) {
        // 0x80090904: nop

            goto L_80090948;
    }
    // 0x80090904: nop

    // 0x80090908: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8009090C: lw          $t3, -0x4CD0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CD0);
    // 0x80090910: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090914: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x80090918: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8009091C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80090920: lhu         $t6, -0x44B8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X44B8);
    // 0x80090924: nop

    // 0x80090928: sh          $t6, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r14;
    // 0x8009092C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090930: lw          $t7, -0x4CD0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CD0);
    // 0x80090934: nop

    // 0x80090938: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8009093C: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80090940: b           L_80090960
    // 0x80090944: nop

        goto L_80090960;
    // 0x80090944: nop

L_80090948:
    // 0x80090948: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x8009094C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090950: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80090954: lhu         $t0, -0x44B8($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44B8);
    // 0x80090958: nop

    // 0x8009095C: sh          $t0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r8;
L_80090960:
    // 0x80090960: lhu         $t1, 0xE($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XE);
    // 0x80090964: nop

    // 0x80090968: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8009096C: beq         $t2, $zero, L_80090A28
    if (ctx->r10 == 0) {
        // 0x80090970: nop

            goto L_80090A28;
    }
    // 0x80090970: nop

    // 0x80090974: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80090978: lh          $t3, -0x4CC8($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4CC8);
    // 0x8009097C: nop

    // 0x80090980: andi        $t4, $t3, 0x400
    ctx->r12 = ctx->r11 & 0X400;
    // 0x80090984: bne         $t4, $zero, L_800909E8
    if (ctx->r12 != 0) {
        // 0x80090988: nop

            goto L_800909E8;
    }
    // 0x80090988: nop

    // 0x8009098C: lhu         $t5, 0xE($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XE);
    // 0x80090990: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x80090994: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80090998: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x8009099C: lhu         $t8, 0xE($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XE);
    // 0x800909A0: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800909A4: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x800909A8: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
    // 0x800909AC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800909B0: sll         $t2, $a3, 1
    ctx->r10 = S32(ctx->r7 << 1);
    // 0x800909B4: lhu         $t1, 0xE($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XE);
    // 0x800909B8: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x800909BC: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800909C0: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x800909C4: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
    // 0x800909C8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800909CC: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800909D0: lhu         $t7, 0xE($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XE);
    // 0x800909D4: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800909D8: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x800909DC: addu        $t4, $t8, $t2
    ctx->r12 = ADD32(ctx->r24, ctx->r10);
    // 0x800909E0: b           L_80090A28
    // 0x800909E4: sh          $t7, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r15;
        goto L_80090A28;
    // 0x800909E4: sh          $t7, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r15;
L_800909E8:
    // 0x800909E8: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800909EC: addu        $t6, $a2, $a3
    ctx->r14 = ADD32(ctx->r6, ctx->r7);
    // 0x800909F0: sb          $t3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r11;
    // 0x800909F4: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800909F8: addu        $t5, $a2, $a3
    ctx->r13 = ADD32(ctx->r6, ctx->r7);
    // 0x800909FC: sb          $t1, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r9;
    // 0x80090A00: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80090A04: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80090A08: addu        $t0, $a2, $a3
    ctx->r8 = ADD32(ctx->r6, ctx->r7);
    // 0x80090A0C: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x80090A10: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x80090A14: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80090A18: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80090A1C: addu        $t4, $a2, $a3
    ctx->r12 = ADD32(ctx->r6, ctx->r7);
    // 0x80090A20: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80090A24: sb          $t7, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r15;
L_80090A28:
    // 0x80090A28: b           L_80090A30
    // 0x80090A2C: nop

        goto L_80090A30;
    // 0x80090A2C: nop

L_80090A30:
    // 0x80090A30: jr          $ra
    // 0x80090A34: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80090A34: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80090A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090A3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090A40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090A44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090A48: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80090A4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80090A50: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80090A54: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x80090A58: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80090A5C: jal         0x800BCFCC
    // 0x80090A60: addiu       $a1, $a1, -0x44B8
    ctx->r5 = ADD32(ctx->r5, -0X44B8);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x80090A60: addiu       $a1, $a1, -0x44B8
    ctx->r5 = ADD32(ctx->r5, -0X44B8);
    after_0:
    // 0x80090A64: b           L_80090A6C
    // 0x80090A68: nop

        goto L_80090A6C;
    // 0x80090A68: nop

L_80090A6C:
    // 0x80090A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090A74: jr          $ra
    // 0x80090A78: nop

    return;
    // 0x80090A78: nop

;}
RECOMP_FUNC void func_80090A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A7C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090A80: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80090A84: nop

    // 0x80090A88: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x80090A8C: bne         $t7, $zero, L_80090C84
    if (ctx->r15 != 0) {
        // 0x80090A90: nop

            goto L_80090C84;
    }
    // 0x80090A90: nop

    // 0x80090A94: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090A98: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x80090A9C: nop

    // 0x80090AA0: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x80090AA4: bne         $t9, $zero, L_80090B9C
    if (ctx->r25 != 0) {
        // 0x80090AA8: nop

            goto L_80090B9C;
    }
    // 0x80090AA8: nop

    // 0x80090AAC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090AB0: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x80090AB4: nop

    // 0x80090AB8: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x80090ABC: beq         $t1, $zero, L_80090AE0
    if (ctx->r9 == 0) {
        // 0x80090AC0: nop

            goto L_80090AE0;
    }
    // 0x80090AC0: nop

    // 0x80090AC4: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80090AC8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090ACC: sw          $t2, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r10;
    // 0x80090AD0: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80090AD4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090AD8: b           L_80090B94
    // 0x80090ADC: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
        goto L_80090B94;
    // 0x80090ADC: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
L_80090AE0:
    // 0x80090AE0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80090AE4: lh          $t4, -0x4CC8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CC8);
    // 0x80090AE8: nop

    // 0x80090AEC: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80090AF0: beq         $t5, $zero, L_80090B14
    if (ctx->r13 == 0) {
        // 0x80090AF4: nop

            goto L_80090B14;
    }
    // 0x80090AF4: nop

    // 0x80090AF8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80090AFC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B00: sw          $t6, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r14;
    // 0x80090B04: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80090B08: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B0C: b           L_80090B94
    // 0x80090B10: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
        goto L_80090B94;
    // 0x80090B10: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
L_80090B14:
    // 0x80090B14: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090B18: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x80090B1C: nop

    // 0x80090B20: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x80090B24: beq         $t9, $zero, L_80090B48
    if (ctx->r25 == 0) {
        // 0x80090B28: nop

            goto L_80090B48;
    }
    // 0x80090B28: nop

    // 0x80090B2C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80090B30: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B34: sw          $t0, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r8;
    // 0x80090B38: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x80090B3C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B40: b           L_80090B94
    // 0x80090B44: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
        goto L_80090B94;
    // 0x80090B44: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
L_80090B48:
    // 0x80090B48: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80090B4C: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x80090B50: nop

    // 0x80090B54: andi        $t3, $t2, 0x200
    ctx->r11 = ctx->r10 & 0X200;
    // 0x80090B58: beq         $t3, $zero, L_80090B7C
    if (ctx->r11 == 0) {
        // 0x80090B5C: nop

            goto L_80090B7C;
    }
    // 0x80090B5C: nop

    // 0x80090B60: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80090B64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B68: sw          $t4, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r12;
    // 0x80090B6C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80090B70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B74: b           L_80090B94
    // 0x80090B78: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
        goto L_80090B94;
    // 0x80090B78: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
L_80090B7C:
    // 0x80090B7C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80090B80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B84: sw          $t6, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r14;
    // 0x80090B88: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80090B8C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090B90: sw          $t7, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r15;
L_80090B94:
    // 0x80090B94: b           L_80090C84
    // 0x80090B98: nop

        goto L_80090C84;
    // 0x80090B98: nop

L_80090B9C:
    // 0x80090B9C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090BA0: lh          $t8, -0x4CC8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CC8);
    // 0x80090BA4: nop

    // 0x80090BA8: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x80090BAC: beq         $t9, $zero, L_80090BD0
    if (ctx->r25 == 0) {
        // 0x80090BB0: nop

            goto L_80090BD0;
    }
    // 0x80090BB0: nop

    // 0x80090BB4: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80090BB8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090BBC: sw          $t0, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r8;
    // 0x80090BC0: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80090BC4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090BC8: b           L_80090C84
    // 0x80090BCC: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
        goto L_80090C84;
    // 0x80090BCC: sw          $t1, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r9;
L_80090BD0:
    // 0x80090BD0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80090BD4: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x80090BD8: nop

    // 0x80090BDC: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80090BE0: beq         $t3, $zero, L_80090C04
    if (ctx->r11 == 0) {
        // 0x80090BE4: nop

            goto L_80090C04;
    }
    // 0x80090BE4: nop

    // 0x80090BE8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80090BEC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090BF0: sw          $t4, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r12;
    // 0x80090BF4: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80090BF8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090BFC: b           L_80090C84
    // 0x80090C00: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
        goto L_80090C84;
    // 0x80090C00: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
L_80090C04:
    // 0x80090C04: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090C08: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80090C0C: nop

    // 0x80090C10: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80090C14: beq         $t7, $zero, L_80090C38
    if (ctx->r15 == 0) {
        // 0x80090C18: nop

            goto L_80090C38;
    }
    // 0x80090C18: nop

    // 0x80090C1C: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80090C20: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C24: sw          $t8, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r24;
    // 0x80090C28: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x80090C2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C30: b           L_80090C84
    // 0x80090C34: sw          $t9, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r25;
        goto L_80090C84;
    // 0x80090C34: sw          $t9, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r25;
L_80090C38:
    // 0x80090C38: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090C3C: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x80090C40: nop

    // 0x80090C44: andi        $t1, $t0, 0x200
    ctx->r9 = ctx->r8 & 0X200;
    // 0x80090C48: beq         $t1, $zero, L_80090C6C
    if (ctx->r9 == 0) {
        // 0x80090C4C: nop

            goto L_80090C6C;
    }
    // 0x80090C4C: nop

    // 0x80090C50: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80090C54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C58: sw          $t2, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r10;
    // 0x80090C5C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80090C60: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C64: b           L_80090C84
    // 0x80090C68: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
        goto L_80090C84;
    // 0x80090C68: sw          $t3, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r11;
L_80090C6C:
    // 0x80090C6C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80090C70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C74: sw          $t4, 0x61CC($at)
    MEM_W(0X61CC, ctx->r1) = ctx->r12;
    // 0x80090C78: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80090C7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80090C80: sw          $t5, 0x61D4($at)
    MEM_W(0X61D4, ctx->r1) = ctx->r13;
L_80090C84:
    // 0x80090C84: jr          $ra
    // 0x80090C88: nop

    return;
    // 0x80090C88: nop

    // 0x80090C8C: jr          $ra
    // 0x80090C90: nop

    return;
    // 0x80090C90: nop

;}
RECOMP_FUNC void func_80090C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090C94: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80090C98: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090C9C: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, -0X3AB8);
    // 0x80090CA0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80090CA4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80090CA8: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x80090CAC: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80090CB0: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x80090CB4: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x80090CB8: sh          $t0, 0x100($t2)
    MEM_H(0X100, ctx->r10) = ctx->r8;
    // 0x80090CBC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80090CC0: lw          $t3, -0x282C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X282C);
    // 0x80090CC4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80090CC8: addiu       $t4, $t4, -0x2870
    ctx->r12 = ADD32(ctx->r12, -0X2870);
    // 0x80090CCC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80090CD0: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80090CD4: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80090CD8: beq         $at, $zero, L_80090D04
    if (ctx->r1 == 0) {
        // 0x80090CDC: nop

            goto L_80090D04;
    }
    // 0x80090CDC: nop

    // 0x80090CE0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090CE4: lw          $t8, -0x282C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X282C);
    // 0x80090CE8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80090CEC: lhu         $t1, -0x44C0($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X44C0);
    // 0x80090CF0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090CF4: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x80090CF8: sw          $t9, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r25;
    // 0x80090CFC: b           L_80090D1C
    // 0x80090D00: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
        goto L_80090D1C;
    // 0x80090D00: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_80090D04:
    // 0x80090D04: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090D08: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090D0C: lw          $t0, -0x282C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X282C);
    // 0x80090D10: lhu         $t7, -0x44C0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X44C0);
    // 0x80090D14: nop

    // 0x80090D18: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
L_80090D1C:
    // 0x80090D1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090D20: sh          $a0, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r4;
    // 0x80090D24: jr          $ra
    // 0x80090D28: nop

    return;
    // 0x80090D28: nop

    // 0x80090D2C: jr          $ra
    // 0x80090D30: nop

    return;
    // 0x80090D30: nop

;}
RECOMP_FUNC void func_80090D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090D34: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80090D38: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090D3C: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, -0X3AB8);
    // 0x80090D40: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80090D44: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80090D48: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x80090D4C: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80090D50: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x80090D54: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x80090D58: sh          $t0, 0x100($t2)
    MEM_H(0X100, ctx->r10) = ctx->r8;
    // 0x80090D5C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80090D60: lw          $t4, -0x282C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X282C);
    // 0x80090D64: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80090D68: addiu       $t3, $t3, -0x2870
    ctx->r11 = ADD32(ctx->r11, -0X2870);
    // 0x80090D6C: beq         $t3, $t4, L_80090D98
    if (ctx->r11 == ctx->r12) {
        // 0x80090D70: nop

            goto L_80090D98;
    }
    // 0x80090D70: nop

    // 0x80090D74: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80090D78: lw          $t5, -0x282C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X282C);
    // 0x80090D7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090D80: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80090D84: addiu       $t8, $t5, -0x2
    ctx->r24 = ADD32(ctx->r13, -0X2);
    // 0x80090D88: sh          $t6, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r14;
    // 0x80090D8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090D90: b           L_80090DB0
    // 0x80090D94: sw          $t8, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r24;
        goto L_80090DB0;
    // 0x80090D94: sw          $t8, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r24;
L_80090D98:
    // 0x80090D98: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80090D9C: lw          $t9, -0x282C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X282C);
    // 0x80090DA0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090DA4: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x80090DA8: nop

    // 0x80090DAC: sh          $t1, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r9;
L_80090DB0:
    // 0x80090DB0: jr          $ra
    // 0x80090DB4: nop

    return;
    // 0x80090DB4: nop

    // 0x80090DB8: jr          $ra
    // 0x80090DBC: nop

    return;
    // 0x80090DBC: nop

;}
RECOMP_FUNC void func_80090DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090DC0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80090DC4: addiu       $t6, $t6, -0x3AB8
    ctx->r14 = ADD32(ctx->r14, -0X3AB8);
    // 0x80090DC8: sh          $zero, 0x104($t6)
    MEM_H(0X104, ctx->r14) = 0;
    // 0x80090DCC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80090DD0: addiu       $t7, $t7, -0x3AB8
    ctx->r15 = ADD32(ctx->r15, -0X3AB8);
    // 0x80090DD4: sh          $zero, 0x106($t7)
    MEM_H(0X106, ctx->r15) = 0;
    // 0x80090DD8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80090DDC: addiu       $t8, $t8, -0x3AB8
    ctx->r24 = ADD32(ctx->r24, -0X3AB8);
    // 0x80090DE0: sh          $zero, 0x108($t8)
    MEM_H(0X108, ctx->r24) = 0;
    // 0x80090DE4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80090DE8: addiu       $t9, $t9, -0x3AB8
    ctx->r25 = ADD32(ctx->r25, -0X3AB8);
    // 0x80090DEC: sh          $zero, 0x10A($t9)
    MEM_H(0X10A, ctx->r25) = 0;
    // 0x80090DF0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80090DF4: addiu       $t0, $t0, -0x3AB8
    ctx->r8 = ADD32(ctx->r8, -0X3AB8);
    // 0x80090DF8: sh          $zero, 0x10C($t0)
    MEM_H(0X10C, ctx->r8) = 0;
    // 0x80090DFC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80090E00: addiu       $t1, $t1, -0x2870
    ctx->r9 = ADD32(ctx->r9, -0X2870);
    // 0x80090E04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090E08: sw          $t1, -0x282C($at)
    MEM_W(-0X282C, ctx->r1) = ctx->r9;
    // 0x80090E0C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80090E10: lhu         $t2, -0x44C8($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X44C8);
    // 0x80090E14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090E18: sh          $t2, -0x44C0($at)
    MEM_H(-0X44C0, ctx->r1) = ctx->r10;
    // 0x80090E1C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80090E20: lhu         $t3, -0x44C0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X44C0);
    // 0x80090E24: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80090E28: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80090E2C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80090E30: lh          $t5, -0x3AB8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X3AB8);
    // 0x80090E34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80090E38: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80090E3C: nop

    // 0x80090E40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090E44: swc1        $f6, -0x44D0($at)
    MEM_W(-0X44D0, ctx->r1) = ctx->f6.u32l;
    // 0x80090E48: jr          $ra
    // 0x80090E4C: nop

    return;
    // 0x80090E4C: nop

    // 0x80090E50: jr          $ra
    // 0x80090E54: nop

    return;
    // 0x80090E54: nop

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
RECOMP_FUNC void func_80091A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091A0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80091A10: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80091A14: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80091A18:
    // 0x80091A18: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80091A1C: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x80091A20: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80091A24: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80091A28: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091A2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80091A30: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80091A34: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80091A38: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80091A3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091A40: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80091A44: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80091A48: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80091A4C: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x80091A50: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80091A54: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80091A58: lw          $t9, 0x6C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C14);
    // 0x80091A5C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80091A60: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80091A64: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80091A68: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80091A6C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80091A70: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80091A74: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80091A78: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80091A7C: nop

    // 0x80091A80: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80091A84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80091A88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80091A8C: nop

    // 0x80091A90: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80091A94: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80091A98: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80091A9C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80091AA0: nop

    // 0x80091AA4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80091AA8: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x80091AAC: nop

    // 0x80091AB0: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80091AB4: beq         $t3, $zero, L_80091AE4
    if (ctx->r11 == 0) {
        // 0x80091AB8: nop

            goto L_80091AE4;
    }
    // 0x80091AB8: nop

    // 0x80091ABC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80091AC0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80091AC4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80091AC8: lw          $t8, -0x798($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X798);
    // 0x80091ACC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80091AD0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80091AD4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80091AD8: lbu         $t0, -0x100($t9)
    ctx->r8 = MEM_BU(ctx->r25, -0X100);
    // 0x80091ADC: b           L_80091B0C
    // 0x80091AE0: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
        goto L_80091B0C;
    // 0x80091AE0: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
L_80091AE4:
    // 0x80091AE4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80091AE8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80091AEC: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80091AF0: lw          $t5, -0x7F0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7F0);
    // 0x80091AF4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80091AF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80091AFC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80091B00: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80091B04: nop

    // 0x80091B08: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
L_80091B0C:
    // 0x80091B0C: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091B10: nop

    // 0x80091B14: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x80091B18: beq         $t9, $zero, L_80091B48
    if (ctx->r25 == 0) {
        // 0x80091B1C: nop

            goto L_80091B48;
    }
    // 0x80091B1C: nop

    // 0x80091B20: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091B24: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091B28: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091B2C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091B30: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091B34: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091B38: jal         0x80090784
    // 0x80091B3C: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x80091B3C: nop

    after_0:
    // 0x80091B40: b           L_80091B68
    // 0x80091B44: nop

        goto L_80091B68;
    // 0x80091B44: nop

L_80091B48:
    // 0x80091B48: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091B4C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091B50: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091B54: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091B58: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091B5C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091B60: jal         0x80090784
    // 0x80091B64: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80091B64: nop

    after_1:
L_80091B68:
    // 0x80091B68: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091B6C: nop

    // 0x80091B70: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x80091B74: beq         $t1, $zero, L_80091BA4
    if (ctx->r9 == 0) {
        // 0x80091B78: nop

            goto L_80091BA4;
    }
    // 0x80091B78: nop

    // 0x80091B7C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091B80: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091B84: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091B88: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091B8C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091B90: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091B94: jal         0x80090784
    // 0x80091B98: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x80091B98: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x80091B9C: b           L_80091BC4
    // 0x80091BA0: nop

        goto L_80091BC4;
    // 0x80091BA0: nop

L_80091BA4:
    // 0x80091BA4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091BA8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091BAC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091BB0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091BB4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091BB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091BBC: jal         0x80090784
    // 0x80091BC0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x80091BC0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_80091BC4:
    // 0x80091BC4: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091BC8: nop

    // 0x80091BCC: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80091BD0: beq         $t3, $zero, L_80091C00
    if (ctx->r11 == 0) {
        // 0x80091BD4: nop

            goto L_80091C00;
    }
    // 0x80091BD4: nop

    // 0x80091BD8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091BDC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091BE0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091BE4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091BE8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091BEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091BF0: jal         0x80090784
    // 0x80091BF4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x80091BF4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x80091BF8: b           L_80091C20
    // 0x80091BFC: nop

        goto L_80091C20;
    // 0x80091BFC: nop

L_80091C00:
    // 0x80091C00: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091C04: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091C08: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091C0C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091C10: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091C14: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091C18: jal         0x80090784
    // 0x80091C1C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x80091C1C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80091C20:
    // 0x80091C20: lbu         $t4, 0x1F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091C24: nop

    // 0x80091C28: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80091C2C: beq         $t5, $zero, L_80091C5C
    if (ctx->r13 == 0) {
        // 0x80091C30: nop

            goto L_80091C5C;
    }
    // 0x80091C30: nop

    // 0x80091C34: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091C38: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091C3C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091C40: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091C44: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091C48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091C4C: jal         0x80090784
    // 0x80091C50: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80091C50: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80091C54: b           L_80091C7C
    // 0x80091C58: nop

        goto L_80091C7C;
    // 0x80091C58: nop

L_80091C5C:
    // 0x80091C5C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091C60: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091C64: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091C68: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091C6C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091C70: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091C74: jal         0x80090784
    // 0x80091C78: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x80091C78: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_80091C7C:
    // 0x80091C7C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091C80: nop

    // 0x80091C84: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80091C88: beq         $t7, $zero, L_80091CB8
    if (ctx->r15 == 0) {
        // 0x80091C8C: nop

            goto L_80091CB8;
    }
    // 0x80091C8C: nop

    // 0x80091C90: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091C94: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091C98: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091C9C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091CA0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091CA4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091CA8: jal         0x80090784
    // 0x80091CAC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x80091CAC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x80091CB0: b           L_80091CD8
    // 0x80091CB4: nop

        goto L_80091CD8;
    // 0x80091CB4: nop

L_80091CB8:
    // 0x80091CB8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091CBC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091CC0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091CC4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091CC8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091CCC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091CD0: jal         0x80090784
    // 0x80091CD4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x80091CD4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_80091CD8:
    // 0x80091CD8: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091CDC: nop

    // 0x80091CE0: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80091CE4: beq         $t9, $zero, L_80091D14
    if (ctx->r25 == 0) {
        // 0x80091CE8: nop

            goto L_80091D14;
    }
    // 0x80091CE8: nop

    // 0x80091CEC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091CF0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091CF4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091CF8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091CFC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091D00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091D04: jal         0x80090784
    // 0x80091D08: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x80091D08: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x80091D0C: b           L_80091D34
    // 0x80091D10: nop

        goto L_80091D34;
    // 0x80091D10: nop

L_80091D14:
    // 0x80091D14: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091D18: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091D1C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091D20: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091D24: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091D28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091D2C: jal         0x80090784
    // 0x80091D30: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80091D30: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80091D34:
    // 0x80091D34: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091D38: nop

    // 0x80091D3C: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80091D40: beq         $t1, $zero, L_80091D70
    if (ctx->r9 == 0) {
        // 0x80091D44: nop

            goto L_80091D70;
    }
    // 0x80091D44: nop

    // 0x80091D48: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091D4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091D50: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091D54: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091D58: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091D5C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091D60: jal         0x80090784
    // 0x80091D64: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80091D64: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x80091D68: b           L_80091D90
    // 0x80091D6C: nop

        goto L_80091D90;
    // 0x80091D6C: nop

L_80091D70:
    // 0x80091D70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091D74: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091D78: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091D7C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091D80: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091D84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091D88: jal         0x80090784
    // 0x80091D8C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x80091D8C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_80091D90:
    // 0x80091D90: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091D94: nop

    // 0x80091D98: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80091D9C: beq         $t3, $zero, L_80091DCC
    if (ctx->r11 == 0) {
        // 0x80091DA0: nop

            goto L_80091DCC;
    }
    // 0x80091DA0: nop

    // 0x80091DA4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091DA8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091DAC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091DB0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091DB4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091DB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091DBC: jal         0x80090784
    // 0x80091DC0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x80091DC0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x80091DC4: b           L_80091DEC
    // 0x80091DC8: nop

        goto L_80091DEC;
    // 0x80091DC8: nop

L_80091DCC:
    // 0x80091DCC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091DD0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091DD4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091DD8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091DDC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091DE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091DE4: jal         0x80090784
    // 0x80091DE8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x80091DE8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_80091DEC:
    // 0x80091DEC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80091DF0: nop

    // 0x80091DF4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80091DF8: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80091DFC: bne         $at, $zero, L_80091A18
    if (ctx->r1 != 0) {
        // 0x80091E00: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80091A18;
    }
    // 0x80091E00: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80091E04: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80091E08: lw          $t6, 0x6B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B98);
    // 0x80091E0C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80091E10: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80091E14: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80091E18: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x80091E1C: b           L_80091E24
    // 0x80091E20: nop

        goto L_80091E24;
    // 0x80091E20: nop

L_80091E24:
    // 0x80091E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091E28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80091E2C: jr          $ra
    // 0x80091E30: nop

    return;
    // 0x80091E30: nop

;}
RECOMP_FUNC void func_80091E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091E3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80091E40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80091E44: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80091E48:
    // 0x80091E48: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80091E4C: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x80091E50: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80091E54: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80091E58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091E5C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80091E60: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80091E64: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80091E68: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80091E6C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091E70: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80091E74: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80091E78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80091E7C: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x80091E80: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80091E84: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80091E88: lw          $t9, 0x6C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C14);
    // 0x80091E8C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80091E90: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80091E94: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80091E98: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80091E9C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80091EA0: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80091EA4: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80091EA8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80091EAC: nop

    // 0x80091EB0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80091EB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80091EB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80091EBC: nop

    // 0x80091EC0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80091EC4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80091EC8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80091ECC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80091ED0: nop

    // 0x80091ED4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80091ED8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80091EDC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80091EE0: lw          $t7, -0x790($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X790);
    // 0x80091EE4: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80091EE8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80091EEC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80091EF0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80091EF4: lbu         $t9, -0x400($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X400);
    // 0x80091EF8: nop

    // 0x80091EFC: sb          $t9, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r25;
    // 0x80091F00: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091F04: nop

    // 0x80091F08: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80091F0C: beq         $t1, $zero, L_80091F3C
    if (ctx->r9 == 0) {
        // 0x80091F10: nop

            goto L_80091F3C;
    }
    // 0x80091F10: nop

    // 0x80091F14: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091F18: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091F1C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091F20: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091F24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091F28: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091F2C: jal         0x80090784
    // 0x80091F30: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x80091F30: nop

    after_0:
    // 0x80091F34: b           L_80091F5C
    // 0x80091F38: nop

        goto L_80091F5C;
    // 0x80091F38: nop

L_80091F3C:
    // 0x80091F3C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091F40: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091F44: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091F48: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091F4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091F50: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091F54: jal         0x80090784
    // 0x80091F58: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80091F58: nop

    after_1:
L_80091F5C:
    // 0x80091F5C: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091F60: nop

    // 0x80091F64: andi        $t4, $t2, 0x40
    ctx->r12 = ctx->r10 & 0X40;
    // 0x80091F68: beq         $t4, $zero, L_80091F98
    if (ctx->r12 == 0) {
        // 0x80091F6C: nop

            goto L_80091F98;
    }
    // 0x80091F6C: nop

    // 0x80091F70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091F74: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091F78: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091F7C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091F80: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091F84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091F88: jal         0x80090784
    // 0x80091F8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x80091F8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x80091F90: b           L_80091FB8
    // 0x80091F94: nop

        goto L_80091FB8;
    // 0x80091F94: nop

L_80091F98:
    // 0x80091F98: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091F9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091FA0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091FA4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091FA8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091FAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091FB0: jal         0x80090784
    // 0x80091FB4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x80091FB4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_80091FB8:
    // 0x80091FB8: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091FBC: nop

    // 0x80091FC0: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x80091FC4: beq         $t5, $zero, L_80091FF4
    if (ctx->r13 == 0) {
        // 0x80091FC8: nop

            goto L_80091FF4;
    }
    // 0x80091FC8: nop

    // 0x80091FCC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091FD0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091FD4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091FD8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091FDC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091FE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091FE4: jal         0x80090784
    // 0x80091FE8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x80091FE8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x80091FEC: b           L_80092014
    // 0x80091FF0: nop

        goto L_80092014;
    // 0x80091FF0: nop

L_80091FF4:
    // 0x80091FF4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091FF8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091FFC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092000: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092004: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092008: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009200C: jal         0x80090784
    // 0x80092010: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x80092010: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80092014:
    // 0x80092014: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80092018: nop

    // 0x8009201C: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80092020: beq         $t7, $zero, L_80092050
    if (ctx->r15 == 0) {
        // 0x80092024: nop

            goto L_80092050;
    }
    // 0x80092024: nop

    // 0x80092028: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009202C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092030: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092034: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092038: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009203C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092040: jal         0x80090784
    // 0x80092044: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80092044: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80092048: b           L_80092070
    // 0x8009204C: nop

        goto L_80092070;
    // 0x8009204C: nop

L_80092050:
    // 0x80092050: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092054: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092058: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009205C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092060: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092064: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092068: jal         0x80090784
    // 0x8009206C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x8009206C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_80092070:
    // 0x80092070: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x80092074: nop

    // 0x80092078: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8009207C: beq         $t9, $zero, L_800920AC
    if (ctx->r25 == 0) {
        // 0x80092080: nop

            goto L_800920AC;
    }
    // 0x80092080: nop

    // 0x80092084: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092088: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009208C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092090: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092094: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092098: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009209C: jal         0x80090784
    // 0x800920A0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x800920A0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x800920A4: b           L_800920CC
    // 0x800920A8: nop

        goto L_800920CC;
    // 0x800920A8: nop

L_800920AC:
    // 0x800920AC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800920B0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800920B4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800920B8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800920BC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800920C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800920C4: jal         0x80090784
    // 0x800920C8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x800920C8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_800920CC:
    // 0x800920CC: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x800920D0: nop

    // 0x800920D4: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x800920D8: beq         $t1, $zero, L_80092108
    if (ctx->r9 == 0) {
        // 0x800920DC: nop

            goto L_80092108;
    }
    // 0x800920DC: nop

    // 0x800920E0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800920E4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800920E8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800920EC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800920F0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800920F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800920F8: jal         0x80090784
    // 0x800920FC: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x800920FC: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x80092100: b           L_80092128
    // 0x80092104: nop

        goto L_80092128;
    // 0x80092104: nop

L_80092108:
    // 0x80092108: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009210C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092110: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092114: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092118: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009211C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092120: jal         0x80090784
    // 0x80092124: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80092124: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80092128:
    // 0x80092128: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8009212C: nop

    // 0x80092130: andi        $t4, $t2, 0x2
    ctx->r12 = ctx->r10 & 0X2;
    // 0x80092134: beq         $t4, $zero, L_80092164
    if (ctx->r12 == 0) {
        // 0x80092138: nop

            goto L_80092164;
    }
    // 0x80092138: nop

    // 0x8009213C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092140: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092144: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092148: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009214C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092150: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092154: jal         0x80090784
    // 0x80092158: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80092158: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x8009215C: b           L_80092184
    // 0x80092160: nop

        goto L_80092184;
    // 0x80092160: nop

L_80092164:
    // 0x80092164: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092168: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009216C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092170: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092174: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092178: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009217C: jal         0x80090784
    // 0x80092180: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x80092180: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_80092184:
    // 0x80092184: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80092188: beq         $zero, $t3, L_800921E0
    if (0 == ctx->r11) {
        // 0x8009218C: nop

            goto L_800921E0;
    }
    // 0x8009218C: nop

    // 0x80092190: b           L_80092268
    // 0x80092194: nop

        goto L_80092268;
    // 0x80092194: nop

    // 0x80092198: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009219C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800921A0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800921A4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800921A8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800921AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800921B0: jal         0x80090784
    // 0x800921B4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x800921B4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x800921B8: b           L_800921E0
    // 0x800921BC: nop

        goto L_800921E0;
    // 0x800921BC: nop

    // 0x800921C0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800921C4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800921C8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800921CC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800921D0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800921D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800921D8: jal         0x80090784
    // 0x800921DC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x800921DC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_800921E0:
    // 0x800921E0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800921E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800921E8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800921EC: lw          $t1, -0x790($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X790);
    // 0x800921F0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800921F4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800921F8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800921FC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80092200: lbu         $t4, -0x3FF($t2)
    ctx->r12 = MEM_BU(ctx->r10, -0X3FF);
    // 0x80092204: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80092208: beq         $t4, $zero, L_80092268
    if (ctx->r12 == 0) {
        // 0x8009220C: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_80092268;
    }
    // 0x8009220C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80092210: sltiu       $t1, $t4, 0x9
    ctx->r9 = ctx->r12 < 0X9 ? 1 : 0;
    // 0x80092214: beq         $t1, $zero, L_80092268
    if (ctx->r9 == 0) {
        // 0x80092218: nop

            goto L_80092268;
    }
    // 0x80092218: nop

    // 0x8009221C: b           L_80092268
    // 0x80092220: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_80092268;
    // 0x80092220: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80092224: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092228: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009222C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092230: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092238: jal         0x80090784
    // 0x8009223C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_16;
    // 0x8009223C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_16:
    // 0x80092240: b           L_80092268
    // 0x80092244: nop

        goto L_80092268;
    // 0x80092244: nop

    // 0x80092248: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009224C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092250: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092254: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092258: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009225C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092260: jal         0x80090784
    // 0x80092264: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_17;
    // 0x80092264: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_17:
L_80092268:
    // 0x80092268: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8009226C: nop

    // 0x80092270: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80092274: beq         $t8, $zero, L_800922A4
    if (ctx->r24 == 0) {
        // 0x80092278: nop

            goto L_800922A4;
    }
    // 0x80092278: nop

    // 0x8009227C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092280: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092284: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092288: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009228C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092290: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092294: jal         0x80090784
    // 0x80092298: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_18;
    // 0x80092298: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_18:
    // 0x8009229C: b           L_800922C4
    // 0x800922A0: nop

        goto L_800922C4;
    // 0x800922A0: nop

L_800922A4:
    // 0x800922A4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800922A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800922AC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800922B0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800922B4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800922B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800922BC: jal         0x80090784
    // 0x800922C0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_19;
    // 0x800922C0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_19:
L_800922C4:
    // 0x800922C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800922C8: nop

    // 0x800922CC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800922D0: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x800922D4: bne         $at, $zero, L_80091E48
    if (ctx->r1 != 0) {
        // 0x800922D8: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_80091E48;
    }
    // 0x800922D8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800922DC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800922E0: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x800922E4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800922E8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800922EC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800922F0: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x800922F4: b           L_800922FC
    // 0x800922F8: nop

        goto L_800922FC;
    // 0x800922F8: nop

L_800922FC:
    // 0x800922FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80092304: jr          $ra
    // 0x80092308: nop

    return;
    // 0x80092308: nop

;}
