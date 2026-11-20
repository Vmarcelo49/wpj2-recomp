#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80088BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80088BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088BD4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80088BD8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80088BDC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80088BE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80088BE4: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80088BE8: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80088BEC: lhu         $t9, 0x2E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2E);
    // 0x80088BF0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80088BF4: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80088BF8: beq         $t0, $zero, L_80088C3C
    if (ctx->r8 == 0) {
        // 0x80088BFC: nop

            goto L_80088C3C;
    }
    // 0x80088BFC: nop

    // 0x80088C00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80088C04: jal         0x8008A518
    // 0x80088C08: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80088C08: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80088C0C: beq         $v0, $zero, L_80088C3C
    if (ctx->r2 == 0) {
        // 0x80088C10: nop

            goto L_80088C3C;
    }
    // 0x80088C10: nop

    // 0x80088C14: lhu         $t1, 0x1C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X1C);
    // 0x80088C18: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80088C1C: bne         $t1, $at, L_80088C3C
    if (ctx->r9 != ctx->r1) {
        // 0x80088C20: nop

            goto L_80088C3C;
    }
    // 0x80088C20: nop

    // 0x80088C24: b           L_80088C2C
    // 0x80088C28: nop

        goto L_80088C2C;
    // 0x80088C28: nop

L_80088C2C:
    // 0x80088C2C: jal         0x8008CE48
    // 0x80088C30: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80088C30: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80088C34: b           L_80088C84
    // 0x80088C38: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80088C84;
    // 0x80088C38: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80088C3C:
    // 0x80088C3C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80088C40: lhu         $t3, 0x101C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X101C);
    // 0x80088C44: lhu         $t2, 0x2E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2E);
    // 0x80088C48: nop

    // 0x80088C4C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80088C50: beq         $t4, $zero, L_80088C68
    if (ctx->r12 == 0) {
        // 0x80088C54: nop

            goto L_80088C68;
    }
    // 0x80088C54: nop

    // 0x80088C58: jal         0x8008CE48
    // 0x80088C5C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80088C5C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80088C60: b           L_80088C84
    // 0x80088C64: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80088C84;
    // 0x80088C64: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80088C68:
    // 0x80088C68: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80088C6C: nop

    // 0x80088C70: lh          $v0, 0x4($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X4);
    // 0x80088C74: b           L_80088C84
    // 0x80088C78: nop

        goto L_80088C84;
    // 0x80088C78: nop

    // 0x80088C7C: b           L_80088C84
    // 0x80088C80: nop

        goto L_80088C84;
    // 0x80088C80: nop

L_80088C84:
    // 0x80088C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088C88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80088C8C: jr          $ra
    // 0x80088C90: nop

    return;
    // 0x80088C90: nop

;}
RECOMP_FUNC void func_80088C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088C9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80088CA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80088CA4: jal         0x8008B4EC
    // 0x80088CA8: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80088CA8: nop

    after_0:
    // 0x80088CAC: b           L_80088CB4
    // 0x80088CB0: nop

        goto L_80088CB4;
    // 0x80088CB0: nop

L_80088CB4:
    // 0x80088CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088CBC: jr          $ra
    // 0x80088CC0: nop

    return;
    // 0x80088CC0: nop

;}
RECOMP_FUNC void func_80088CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80088CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088CCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80088CD0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80088CD4: nop

    // 0x80088CD8: lw          $a0, 0x728($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X728);
    // 0x80088CDC: jal         0x8008A674
    // 0x80088CE0: nop

    func_8008A674(rdram, ctx);
        goto after_0;
    // 0x80088CE0: nop

    after_0:
L_80088CE4:
    // 0x80088CE4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80088CE8: nop

    // 0x80088CEC: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80088CF0: nop

    // 0x80088CF4: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    // 0x80088CF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80088CFC: jal         0x8008A788
    // 0x80088D00: nop

    func_8008A788(rdram, ctx);
        goto after_1;
    // 0x80088D00: nop

    after_1:
    // 0x80088D04: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80088D08: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x80088D0C: sh          $t9, 0x750($t0)
    MEM_H(0X750, ctx->r8) = ctx->r25;
    // 0x80088D10: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80088D14: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80088D18: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80088D1C: nop

    // 0x80088D20: beq         $t2, $at, L_80088D90
    if (ctx->r10 == ctx->r1) {
        // 0x80088D24: nop

            goto L_80088D90;
    }
    // 0x80088D24: nop

    // 0x80088D28: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80088D2C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80088D30: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80088D34: nop

    // 0x80088D38: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80088D3C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80088D40: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80088D44: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80088D48: lw          $t6, 0x4530($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4530);
    // 0x80088D4C: nop

    // 0x80088D50: beq         $t6, $zero, L_80088D88
    if (ctx->r14 == 0) {
        // 0x80088D54: nop

            goto L_80088D88;
    }
    // 0x80088D54: nop

    // 0x80088D58: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80088D5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D60: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80088D64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80088D68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80088D6C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80088D70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80088D74: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80088D78: lw          $t9, 0x4530($at)
    ctx->r25 = MEM_W(ctx->r1, 0X4530);
    // 0x80088D7C: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80088D80: jalr        $t9
    // 0x80088D84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80088D84: nop

    after_2:
L_80088D88:
    // 0x80088D88: b           L_80088DB0
    // 0x80088D8C: nop

        goto L_80088DB0;
    // 0x80088D8C: nop

L_80088D90:
    // 0x80088D90: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80088D94: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80088D98: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x80088D9C: nop

    // 0x80088DA0: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80088DA4: sh          $t2, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r10;
    // 0x80088DA8: b           L_80088DE4
    // 0x80088DAC: nop

        goto L_80088DE4;
    // 0x80088DAC: nop

L_80088DB0:
    // 0x80088DB0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80088DB4: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x80088DB8: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80088DBC: nop

    // 0x80088DC0: bne         $t4, $t5, L_80088CE4
    if (ctx->r12 != ctx->r13) {
        // 0x80088DC4: nop

            goto L_80088CE4;
    }
    // 0x80088DC4: nop

    // 0x80088DC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80088DCC: jal         0x8008997C
    // 0x80088DD0: nop

    func_8008997C(rdram, ctx);
        goto after_3;
    // 0x80088DD0: nop

    after_3:
    // 0x80088DD4: b           L_80088DE4
    // 0x80088DD8: nop

        goto L_80088DE4;
    // 0x80088DD8: nop

    // 0x80088DDC: b           L_80088DE4
    // 0x80088DE0: nop

        goto L_80088DE4;
    // 0x80088DE0: nop

L_80088DE4:
    // 0x80088DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80088DEC: jr          $ra
    // 0x80088DF0: nop

    return;
    // 0x80088DF0: nop

;}
RECOMP_FUNC void func_80088DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DF4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80088DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088DFC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80088E00: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80088E04: nop

    // 0x80088E08: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80088E0C: nop

    // 0x80088E10: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x80088E14: beq         $t8, $zero, L_80088EB4
    if (ctx->r24 == 0) {
        // 0x80088E18: nop

            goto L_80088EB4;
    }
    // 0x80088E18: nop

    // 0x80088E1C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80088E20: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80088E24: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x80088E28: nop

    // 0x80088E2C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80088E30: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80088E34: lh          $t2, 0x4660($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X4660);
    // 0x80088E38: nop

    // 0x80088E3C: sh          $t2, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r10;
    // 0x80088E40: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80088E44: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80088E48: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x80088E4C: nop

    // 0x80088E50: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80088E54: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80088E58: lh          $t6, 0x4662($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X4662);
    // 0x80088E5C: nop

    // 0x80088E60: sh          $t6, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r14;
    // 0x80088E64: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80088E68: nop

    // 0x80088E6C: lh          $a0, 0xA($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XA);
    // 0x80088E70: lh          $a1, 0xC($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XC);
    // 0x80088E74: jal         0x8008B494
    // 0x80088E78: nop

    func_8008B494(rdram, ctx);
        goto after_0;
    // 0x80088E78: nop

    after_0:
    // 0x80088E7C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80088E80: nop

    // 0x80088E84: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x80088E88: nop

    // 0x80088E8C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80088E90: sh          $t1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r9;
    // 0x80088E94: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80088E98: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80088E9C: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x80088EA0: nop

    // 0x80088EA4: and         $t4, $t9, $at
    ctx->r12 = ctx->r25 & ctx->r1;
    // 0x80088EA8: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80088EAC: b           L_80088F40
    // 0x80088EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80088F40;
    // 0x80088EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80088EB4:
    // 0x80088EB4: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80088EB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80088EBC: nop

    // 0x80088EC0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80088EC4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80088EC8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80088ECC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80088ED0: addiu       $t5, $zero, 0x140
    ctx->r13 = ADD32(0, 0X140);
    // 0x80088ED4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80088ED8: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x80088EDC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80088EE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80088EE4: nop

    // 0x80088EE8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80088EEC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80088EF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80088EF4: nop

    // 0x80088EF8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80088EFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80088F00: nop

    // 0x80088F04: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80088F08: addiu       $t3, $zero, 0x3E8
    ctx->r11 = ADD32(0, 0X3E8);
    // 0x80088F0C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80088F10: jal         0x80016620
    // 0x80088F14: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_1;
    // 0x80088F14: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80088F18: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80088F1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80088F20: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
    // 0x80088F24: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80088F28: nop

    // 0x80088F2C: sh          $zero, 0xBD0($t0)
    MEM_H(0XBD0, ctx->r8) = 0;
    // 0x80088F30: b           L_80088F40
    // 0x80088F34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80088F40;
    // 0x80088F34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80088F38: b           L_80088F40
    // 0x80088F3C: nop

        goto L_80088F40;
    // 0x80088F3C: nop

L_80088F40:
    // 0x80088F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088F44: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80088F48: jr          $ra
    // 0x80088F4C: nop

    return;
    // 0x80088F4C: nop

;}
RECOMP_FUNC void func_80088F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F50: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80088F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088F58: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80088F5C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80088F60: nop

    // 0x80088F64: lhu         $t7, 0xBD0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XBD0);
    // 0x80088F68: nop

    // 0x80088F6C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80088F70: beq         $at, $zero, L_80089150
    if (ctx->r1 == 0) {
        // 0x80088F74: nop

            goto L_80089150;
    }
    // 0x80088F74: nop

    // 0x80088F78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80088F7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80088F80: addu        $at, $at, $t7
    gpr jr_addend_80088F8C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80088F84: lw          $t7, -0xA44($at)
    ctx->r15 = ADD32(ctx->r1, -0XA44);
    // 0x80088F88: nop

    // 0x80088F8C: jr          $t7
    // 0x80088F90: nop

    switch (jr_addend_80088F8C >> 2) {
        case 0: goto L_80088F94; break;
        case 1: goto L_80088FE0; break;
        case 2: goto L_8008906C; break;
        case 3: goto L_800890F0; break;
        case 4: goto L_8008913C; break;
        default: switch_error(__func__, 0x80088F8C, 0x800EF5BC);
    }
    // 0x80088F90: nop

L_80088F94:
    // 0x80088F94: jal         0x80016074
    // 0x80088F98: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80088F98: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80088F9C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80088FA0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80088FA4: nop

    // 0x80088FA8: beq         $t8, $zero, L_80088FD8
    if (ctx->r24 == 0) {
        // 0x80088FAC: nop

            goto L_80088FD8;
    }
    // 0x80088FAC: nop

    // 0x80088FB0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80088FB4: nop

    // 0x80088FB8: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x80088FBC: nop

    // 0x80088FC0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80088FC4: beq         $t1, $zero, L_80088FD8
    if (ctx->r9 == 0) {
        // 0x80088FC8: nop

            goto L_80088FD8;
    }
    // 0x80088FC8: nop

    // 0x80088FCC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80088FD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80088FD4: sh          $t2, 0xBD0($t3)
    MEM_H(0XBD0, ctx->r11) = ctx->r10;
L_80088FD8:
    // 0x80088FD8: b           L_80089150
    // 0x80088FDC: nop

        goto L_80089150;
    // 0x80088FDC: nop

L_80088FE0:
    // 0x80088FE0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80088FE4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80088FE8: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x80088FEC: nop

    // 0x80088FF0: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80088FF4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80088FF8: lh          $t7, 0x4660($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X4660);
    // 0x80088FFC: nop

    // 0x80089000: sh          $t7, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r15;
    // 0x80089004: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80089008: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008900C: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x80089010: nop

    // 0x80089014: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80089018: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8008901C: lh          $t1, 0x4662($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4662);
    // 0x80089020: nop

    // 0x80089024: sh          $t1, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r9;
    // 0x80089028: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008902C: nop

    // 0x80089030: lh          $a0, 0xA($t2)
    ctx->r4 = MEM_H(ctx->r10, 0XA);
    // 0x80089034: lh          $a1, 0xC($t2)
    ctx->r5 = MEM_H(ctx->r10, 0XC);
    // 0x80089038: jal         0x8008B494
    // 0x8008903C: nop

    func_8008B494(rdram, ctx);
        goto after_1;
    // 0x8008903C: nop

    after_1:
    // 0x80089040: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80089044: nop

    // 0x80089048: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x8008904C: nop

    // 0x80089050: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80089054: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
    // 0x80089058: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8008905C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80089060: sh          $t7, 0xBD0($t4)
    MEM_H(0XBD0, ctx->r12) = ctx->r15;
    // 0x80089064: b           L_80089150
    // 0x80089068: nop

        goto L_80089150;
    // 0x80089068: nop

L_8008906C:
    // 0x8008906C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80089070: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80089074: nop

    // 0x80089078: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8008907C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80089080: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80089084: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80089088: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x8008908C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80089090: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x80089094: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80089098: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008909C: nop

    // 0x800890A0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x800890A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800890A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800890AC: nop

    // 0x800890B0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800890B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800890B8: nop

    // 0x800890BC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800890C0: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x800890C4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800890C8: jal         0x80016620
    // 0x800890CC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_2;
    // 0x800890CC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800890D0: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x800890D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800890D8: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
    // 0x800890DC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800890E0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800890E4: sh          $t2, 0xBD0($t5)
    MEM_H(0XBD0, ctx->r13) = ctx->r10;
    // 0x800890E8: b           L_80089150
    // 0x800890EC: nop

        goto L_80089150;
    // 0x800890EC: nop

L_800890F0:
    // 0x800890F0: jal         0x80016074
    // 0x800890F4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_3;
    // 0x800890F4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_3:
    // 0x800890F8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800890FC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80089100: nop

    // 0x80089104: beq         $t6, $zero, L_80089134
    if (ctx->r14 == 0) {
        // 0x80089108: nop

            goto L_80089134;
    }
    // 0x80089108: nop

    // 0x8008910C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80089110: nop

    // 0x80089114: lw          $t7, 0x1A8($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X1A8);
    // 0x80089118: nop

    // 0x8008911C: andi        $t4, $t7, 0x2
    ctx->r12 = ctx->r15 & 0X2;
    // 0x80089120: beq         $t4, $zero, L_80089134
    if (ctx->r12 == 0) {
        // 0x80089124: nop

            goto L_80089134;
    }
    // 0x80089124: nop

    // 0x80089128: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8008912C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80089130: sh          $t9, 0xBD0($t0)
    MEM_H(0XBD0, ctx->r8) = ctx->r25;
L_80089134:
    // 0x80089134: b           L_80089150
    // 0x80089138: nop

        goto L_80089150;
    // 0x80089138: nop

L_8008913C:
    // 0x8008913C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80089140: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80089144: sh          $t1, 0xBD0($t8)
    MEM_H(0XBD0, ctx->r24) = ctx->r9;
    // 0x80089148: b           L_80089160
    // 0x8008914C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80089160;
    // 0x8008914C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80089150:
    // 0x80089150: b           L_80089160
    // 0x80089154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80089160;
    // 0x80089154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80089158: b           L_80089160
    // 0x8008915C: nop

        goto L_80089160;
    // 0x8008915C: nop

L_80089160:
    // 0x80089160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089164: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80089168: jr          $ra
    // 0x8008916C: nop

    return;
    // 0x8008916C: nop

;}
RECOMP_FUNC void func_80089170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089170: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80089174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089178: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8008917C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80089180: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80089184: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x80089188: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008918C: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x80089190: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80089194: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80089198: nop

    // 0x8008919C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800891A0: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800891A4: nop

    // 0x800891A8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800891AC: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x800891B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800891B4: nop

    // 0x800891B8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800891BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800891C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800891C4: nop

    // 0x800891C8: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800891CC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800891D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800891D4: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x800891D8: nop

    // 0x800891DC: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800891E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800891E4: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x800891E8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800891EC: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x800891F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800891F4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800891F8: nop

    // 0x800891FC: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80089200: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80089204: nop

    // 0x80089208: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008920C: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80089210: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80089214: nop

    // 0x80089218: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8008921C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80089220: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80089224: nop

    // 0x80089228: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x8008922C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80089230: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80089234: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x80089238: nop

    // 0x8008923C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80089240: addiu       $t4, $t4, 0x4720
    ctx->r12 = ADD32(ctx->r12, 0X4720);
    // 0x80089244: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80089248: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8008924C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80089250: beq         $t5, $at, L_80089400
    if (ctx->r13 == ctx->r1) {
        // 0x80089254: nop

            goto L_80089400;
    }
    // 0x80089254: nop

L_80089258:
    // 0x80089258: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8008925C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80089260: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80089264: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80089268: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8008926C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089270: addiu       $t8, $t8, 0x4720
    ctx->r24 = ADD32(ctx->r24, 0X4720);
    // 0x80089274: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80089278: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8008927C: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80089280: nop

    // 0x80089284: bne         $t0, $t2, L_800893D4
    if (ctx->r8 != ctx->r10) {
        // 0x80089288: nop

            goto L_800893D4;
    }
    // 0x80089288: nop

    // 0x8008928C: lh          $t3, 0xA($t9)
    ctx->r11 = MEM_H(ctx->r25, 0XA);
    // 0x80089290: nop

    // 0x80089294: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80089298: beq         $t4, $zero, L_800893D4
    if (ctx->r12 == 0) {
        // 0x8008929C: nop

            goto L_800893D4;
    }
    // 0x8008929C: nop

    // 0x800892A0: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800892A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800892A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800892AC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800892B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800892B4: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800892B8: lh          $a2, 0x4726($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X4726);
    // 0x800892BC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800892C0: jal         0x8008B388
    // 0x800892C4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8008B388(rdram, ctx);
        goto after_0;
    // 0x800892C4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800892C8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800892CC: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800892D0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800892D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800892D8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800892DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800892E0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800892E4: lh          $t1, 0x4726($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4726);
    // 0x800892E8: nop

    // 0x800892EC: slti        $at, $t1, 0x4000
    ctx->r1 = SIGNED(ctx->r9) < 0X4000 ? 1 : 0;
    // 0x800892F0: bne         $at, $zero, L_80089368
    if (ctx->r1 != 0) {
        // 0x800892F4: nop

            goto L_80089368;
    }
    // 0x800892F4: nop

    // 0x800892F8: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800892FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80089300: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80089304: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80089308: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008930C: addiu       $t9, $t9, 0x4720
    ctx->r25 = ADD32(ctx->r25, 0X4720);
    // 0x80089310: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x80089314: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80089318: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x8008931C: lh          $t5, 0x2E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2E);
    // 0x80089320: lh          $t8, 0x4($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X4);
    // 0x80089324: lh          $t7, 0x2C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2C);
    // 0x80089328: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8008932C: lh          $a1, 0x6($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X6);
    // 0x80089330: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80089334: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80089338: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x8008933C: subu        $t1, $t7, $t8
    ctx->r9 = SUB32(ctx->r15, ctx->r24);
    // 0x80089340: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80089344: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089348: lh          $t4, 0xA($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XA);
    // 0x8008934C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80089350: addiu       $a3, $t1, -0xA
    ctx->r7 = ADD32(ctx->r9, -0XA);
    // 0x80089354: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80089358: jal         0x800897A8
    // 0x8008935C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_800897A8(rdram, ctx);
        goto after_1;
    // 0x8008935C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_1:
    // 0x80089360: b           L_800893D4
    // 0x80089364: nop

        goto L_800893D4;
    // 0x80089364: nop

L_80089368:
    // 0x80089368: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8008936C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80089370: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80089374: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80089378: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008937C: addiu       $t8, $t8, 0x4720
    ctx->r24 = ADD32(ctx->r24, 0X4720);
    // 0x80089380: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80089384: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80089388: lh          $t6, 0x2($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X2);
    // 0x8008938C: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x80089390: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80089394: lh          $t3, 0x4($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X4);
    // 0x80089398: lh          $t1, 0x2C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2C);
    // 0x8008939C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800893A0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800893A4: lh          $a1, 0x6($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X6);
    // 0x800893A8: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x800893AC: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800893B0: subu        $t4, $t1, $t3
    ctx->r12 = SUB32(ctx->r9, ctx->r11);
    // 0x800893B4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800893B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800893BC: lh          $t6, 0xA($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XA);
    // 0x800893C0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800893C4: addiu       $a3, $t4, -0xC
    ctx->r7 = ADD32(ctx->r12, -0XC);
    // 0x800893C8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800893CC: jal         0x800897A8
    // 0x800893D0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800897A8(rdram, ctx);
        goto after_2;
    // 0x800893D0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_2:
L_800893D4:
    // 0x800893D4: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x800893D8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800893DC: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800893E0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800893E4: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800893E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800893EC: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800893F0: lh          $t5, 0x4720($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X4720);
    // 0x800893F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800893F8: bne         $t5, $at, L_80089258
    if (ctx->r13 != ctx->r1) {
        // 0x800893FC: sw          $t1, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r9;
            goto L_80089258;
    }
    // 0x800893FC: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
L_80089400:
    // 0x80089400: b           L_80089408
    // 0x80089404: nop

        goto L_80089408;
    // 0x80089404: nop

L_80089408:
    // 0x80089408: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008940C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80089410: jr          $ra
    // 0x80089414: nop

    return;
    // 0x80089414: nop

;}
RECOMP_FUNC void func_80089418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089418: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008941C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80089420: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80089424: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80089428: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008942C: addiu       $t6, $zero, 0x2A
    ctx->r14 = ADD32(0, 0X2A);
    // 0x80089430: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
    // 0x80089434: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80089438: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x8008943C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80089440: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80089444:
    // 0x80089444: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80089448: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8008944C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80089450: nop

    // 0x80089454: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80089458: nop

    // 0x8008945C: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80089460: bne         $t1, $zero, L_80089478
    if (ctx->r9 != 0) {
        // 0x80089464: nop

            goto L_80089478;
    }
    // 0x80089464: nop

    // 0x80089468: lhu         $t2, 0x3A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3A);
    // 0x8008946C: nop

    // 0x80089470: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80089474: sh          $t3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r11;
L_80089478:
    // 0x80089478: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8008947C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089480: beq         $s0, $at, L_8008949C
    if (ctx->r16 == ctx->r1) {
        // 0x80089484: nop

            goto L_8008949C;
    }
    // 0x80089484: nop

    // 0x80089488: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008948C: beq         $s0, $at, L_800894D0
    if (ctx->r16 == ctx->r1) {
        // 0x80089490: nop

            goto L_800894D0;
    }
    // 0x80089490: nop

    // 0x80089494: b           L_80089504
    // 0x80089498: nop

        goto L_80089504;
    // 0x80089498: nop

L_8008949C:
    // 0x8008949C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800894A0: nop

    // 0x800894A4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800894A8: nop

    // 0x800894AC: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x800894B0: bne         $t6, $zero, L_800894C8
    if (ctx->r14 != 0) {
        // 0x800894B4: nop

            goto L_800894C8;
    }
    // 0x800894B4: nop

    // 0x800894B8: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x800894BC: nop

    // 0x800894C0: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x800894C4: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
L_800894C8:
    // 0x800894C8: b           L_80089504
    // 0x800894CC: nop

        goto L_80089504;
    // 0x800894CC: nop

L_800894D0:
    // 0x800894D0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800894D4: nop

    // 0x800894D8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800894DC: nop

    // 0x800894E0: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x800894E4: beq         $t1, $zero, L_800894FC
    if (ctx->r9 == 0) {
        // 0x800894E8: nop

            goto L_800894FC;
    }
    // 0x800894E8: nop

    // 0x800894EC: lhu         $t2, 0x3A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3A);
    // 0x800894F0: nop

    // 0x800894F4: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x800894F8: sh          $t3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r11;
L_800894FC:
    // 0x800894FC: b           L_80089504
    // 0x80089500: nop

        goto L_80089504;
    // 0x80089500: nop

L_80089504:
    // 0x80089504: lh          $t4, 0x42($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X42);
    // 0x80089508: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8008950C: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x80089510: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80089514: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80089518: addiu       $t5, $zero, 0x31
    ctx->r13 = ADD32(0, 0X31);
    // 0x8008951C: addiu       $t6, $t4, 0x28
    ctx->r14 = ADD32(ctx->r12, 0X28);
    // 0x80089520: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80089524: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80089528: addiu       $a2, $zero, -0x71
    ctx->r6 = ADD32(0, -0X71);
    // 0x8008952C: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x80089530: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x80089534: jal         0x800897A8
    // 0x80089538: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800897A8(rdram, ctx);
        goto after_0;
    // 0x80089538: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8008953C: lh          $t8, 0x42($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X42);
    // 0x80089540: nop

    // 0x80089544: addiu       $t9, $t8, -0x30
    ctx->r25 = ADD32(ctx->r24, -0X30);
    // 0x80089548: sh          $t9, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r25;
    // 0x8008954C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80089550: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80089554: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80089558: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8008955C: addiu       $t3, $t2, 0x16
    ctx->r11 = ADD32(ctx->r10, 0X16);
    // 0x80089560: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80089564: bne         $at, $zero, L_80089444
    if (ctx->r1 != 0) {
        // 0x80089568: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_80089444;
    }
    // 0x80089568: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8008956C: b           L_80089574
    // 0x80089570: nop

        goto L_80089574;
    // 0x80089570: nop

L_80089574:
    // 0x80089574: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80089578: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008957C: jr          $ra
    // 0x80089580: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80089580: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80089584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089584: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80089588: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008958C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80089590: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80089594: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80089598: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x8008959C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800895A0: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x800895A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800895A8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800895AC: nop

    // 0x800895B0: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800895B4: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800895B8: nop

    // 0x800895BC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800895C0: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x800895C4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800895C8: nop

    // 0x800895CC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800895D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800895D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800895D8: nop

    // 0x800895DC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800895E0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800895E4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800895E8: sh          $t9, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r25;
    // 0x800895EC: nop

    // 0x800895F0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800895F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800895F8: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x800895FC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80089600: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x80089604: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80089608: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8008960C: nop

    // 0x80089610: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80089614: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80089618: nop

    // 0x8008961C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80089620: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80089624: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80089628: nop

    // 0x8008962C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80089630: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80089634: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80089638: nop

    // 0x8008963C: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x80089640: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80089644: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80089648: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    // 0x8008964C: nop

    // 0x80089650: ori         $t4, $zero, 0x8003
    ctx->r12 = 0 | 0X8003;
    // 0x80089654: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80089658: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8008965C:
    // 0x8008965C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80089660:
    // 0x80089660: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80089664: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80089668: bne         $t5, $at, L_8008968C
    if (ctx->r13 != ctx->r1) {
        // 0x8008966C: nop

            goto L_8008968C;
    }
    // 0x8008966C: nop

    // 0x80089670: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80089674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089678: beq         $t6, $at, L_800896AC
    if (ctx->r14 == ctx->r1) {
        // 0x8008967C: nop

            goto L_800896AC;
    }
    // 0x8008967C: nop

    // 0x80089680: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80089684: beq         $t6, $at, L_800896AC
    if (ctx->r14 == ctx->r1) {
        // 0x80089688: nop

            goto L_800896AC;
    }
    // 0x80089688: nop

L_8008968C:
    // 0x8008968C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80089690: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80089694: bne         $t7, $at, L_800896B4
    if (ctx->r15 != ctx->r1) {
        // 0x80089698: nop

            goto L_800896B4;
    }
    // 0x80089698: nop

    // 0x8008969C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800896A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800896A4: bne         $t8, $at, L_800896B4
    if (ctx->r24 != ctx->r1) {
        // 0x800896A8: nop

            goto L_800896B4;
    }
    // 0x800896A8: nop

L_800896AC:
    // 0x800896AC: b           L_80089760
    // 0x800896B0: nop

        goto L_80089760;
    // 0x800896B0: nop

L_800896B4:
    // 0x800896B4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800896B8: nop

    // 0x800896BC: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800896C0: addiu       $t1, $t0, 0x6
    ctx->r9 = ADD32(ctx->r8, 0X6);
    // 0x800896C4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800896C8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800896CC: nop

    // 0x800896D0: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x800896D4: bne         $at, $zero, L_800896EC
    if (ctx->r1 != 0) {
        // 0x800896D8: nop

            goto L_800896EC;
    }
    // 0x800896D8: nop

    // 0x800896DC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800896E0: nop

    // 0x800896E4: addiu       $t4, $t3, 0x56
    ctx->r12 = ADD32(ctx->r11, 0X56);
    // 0x800896E8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_800896EC:
    // 0x800896EC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800896F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800896F4: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800896F8: mfhi        $t6
    ctx->r14 = hi;
    // 0x800896FC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80089700: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80089704: addiu       $t8, $t7, 0x5
    ctx->r24 = ADD32(ctx->r15, 0X5);
    // 0x80089708: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008970C: lh          $t9, 0x2C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2C);
    // 0x80089710: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80089714: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x80089718: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8008971C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80089720: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80089724: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80089728: addiu       $t5, $t1, 0xE
    ctx->r13 = ADD32(ctx->r9, 0XE);
    // 0x8008972C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80089730: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x80089734: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089738: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8008973C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80089740: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80089744: addiu       $a3, $t4, -0xD
    ctx->r7 = ADD32(ctx->r12, -0XD);
    // 0x80089748: jal         0x800897A8
    // 0x8008974C: addiu       $a2, $t1, -0x2
    ctx->r6 = ADD32(ctx->r9, -0X2);
    func_800897A8(rdram, ctx);
        goto after_0;
    // 0x8008974C: addiu       $a2, $t1, -0x2
    ctx->r6 = ADD32(ctx->r9, -0X2);
    after_0:
    // 0x80089750: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x80089754: nop

    // 0x80089758: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008975C: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
L_80089760:
    // 0x80089760: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80089764: nop

    // 0x80089768: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8008976C: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x80089770: bne         $at, $zero, L_80089660
    if (ctx->r1 != 0) {
        // 0x80089774: sw          $t2, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r10;
            goto L_80089660;
    }
    // 0x80089774: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80089778: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008977C: nop

    // 0x80089780: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x80089784: slti        $at, $t1, 0x12
    ctx->r1 = SIGNED(ctx->r9) < 0X12 ? 1 : 0;
    // 0x80089788: bne         $at, $zero, L_8008965C
    if (ctx->r1 != 0) {
        // 0x8008978C: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_8008965C;
    }
    // 0x8008978C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80089790: b           L_80089798
    // 0x80089794: nop

        goto L_80089798;
    // 0x80089794: nop

L_80089798:
    // 0x80089798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008979C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800897A0: jr          $ra
    // 0x800897A4: nop

    return;
    // 0x800897A4: nop

;}
RECOMP_FUNC void func_800897A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897A8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800897AC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x800897B0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800897B4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800897B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800897BC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800897C0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800897C4: lhu         $t6, 0x750($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X750);
    // 0x800897C8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800897CC: beq         $t6, $at, L_80089804
    if (ctx->r14 == ctx->r1) {
        // 0x800897D0: nop

            goto L_80089804;
    }
    // 0x800897D0: nop

L_800897D4:
    // 0x800897D4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800897D8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800897DC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800897E0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800897E4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800897E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800897EC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x800897F0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800897F4: lhu         $t1, 0x750($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X750);
    // 0x800897F8: nop

    // 0x800897FC: bne         $t1, $at, L_800897D4
    if (ctx->r9 != ctx->r1) {
        // 0x80089800: nop

            goto L_800897D4;
    }
    // 0x80089800: nop

L_80089804:
    // 0x80089804: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80089808: nop

    // 0x8008980C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80089810: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80089814: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80089818: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8008981C: sh          $a1, 0x750($t4)
    MEM_H(0X750, ctx->r12) = ctx->r5;
    // 0x80089820: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80089824: nop

    // 0x80089828: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8008982C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80089830: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80089834: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80089838: sh          $a2, 0x752($t7)
    MEM_H(0X752, ctx->r15) = ctx->r6;
    // 0x8008983C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80089840: nop

    // 0x80089844: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80089848: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008984C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80089850: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80089854: sh          $a3, 0x754($t0)
    MEM_H(0X754, ctx->r8) = ctx->r7;
    // 0x80089858: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008985C: lh          $t1, 0x1A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X1A);
    // 0x80089860: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80089864: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80089868: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008986C: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80089870: sh          $t1, 0x756($t4)
    MEM_H(0X756, ctx->r12) = ctx->r9;
    // 0x80089874: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80089878: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x8008987C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80089880: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80089884: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089888: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008988C: sh          $t5, 0x758($t8)
    MEM_H(0X758, ctx->r24) = ctx->r13;
    // 0x80089890: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80089894: lhu         $t9, 0x22($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X22);
    // 0x80089898: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8008989C: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x800898A0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800898A4: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x800898A8: sh          $t9, 0x75A($t3)
    MEM_H(0X75A, ctx->r11) = ctx->r25;
    // 0x800898AC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800898B0: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x800898B4: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800898B8: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800898BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800898C0: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800898C4: sh          $t1, 0x75C($t7)
    MEM_H(0X75C, ctx->r15) = ctx->r9;
    // 0x800898C8: b           L_800898D0
    // 0x800898CC: nop

        goto L_800898D0;
    // 0x800898CC: nop

L_800898D0:
    // 0x800898D0: jr          $ra
    // 0x800898D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800898D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800898D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800898DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800898E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800898E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800898E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800898EC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800898F0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800898F4: addiu       $t7, $t6, 0x750
    ctx->r15 = ADD32(ctx->r14, 0X750);
    // 0x800898F8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800898FC: lhu         $t8, 0x750($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X750);
    // 0x80089900: nop

    // 0x80089904: beq         $t8, $at, L_8008995C
    if (ctx->r24 == ctx->r1) {
        // 0x80089908: nop

            goto L_8008995C;
    }
    // 0x80089908: nop

L_8008990C:
    // 0x8008990C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80089910: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x80089914: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80089918: nop

    // 0x8008991C: bne         $t0, $t1, L_8008993C
    if (ctx->r8 != ctx->r9) {
        // 0x80089920: nop

            goto L_8008993C;
    }
    // 0x80089920: nop

    // 0x80089924: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80089928: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008992C: jal         0x800BCFCC
    // 0x80089930: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x80089930: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x80089934: b           L_8008996C
    // 0x80089938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008996C;
    // 0x80089938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008993C:
    // 0x8008993C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80089940: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80089944: addiu       $t3, $t2, 0xC
    ctx->r11 = ADD32(ctx->r10, 0XC);
    // 0x80089948: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8008994C: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80089950: nop

    // 0x80089954: bne         $t4, $at, L_8008990C
    if (ctx->r12 != ctx->r1) {
        // 0x80089958: nop

            goto L_8008990C;
    }
    // 0x80089958: nop

L_8008995C:
    // 0x8008995C: b           L_8008996C
    // 0x80089960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008996C;
    // 0x80089960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80089964: b           L_8008996C
    // 0x80089968: nop

        goto L_8008996C;
    // 0x80089968: nop

L_8008996C:
    // 0x8008996C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80089974: jr          $ra
    // 0x80089978: nop

    return;
    // 0x80089978: nop

;}
RECOMP_FUNC void func_8008997C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008997C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80089980: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80089984: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80089988: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008998C: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80089990: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089994: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80089998: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008999C: lh          $t9, 0x4666($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4666);
    // 0x800899A0: nop

    // 0x800899A4: bne         $t9, $at, L_80089AD4
    if (ctx->r25 != ctx->r1) {
        // 0x800899A8: nop

            goto L_80089AD4;
    }
    // 0x800899A8: nop

    // 0x800899AC: addiu       $t0, $zero, 0x7B
    ctx->r8 = ADD32(0, 0X7B);
    // 0x800899B0: sh          $t0, 0x748($a0)
    MEM_H(0X748, ctx->r4) = ctx->r8;
    // 0x800899B4: addiu       $t1, $zero, 0x5E
    ctx->r9 = ADD32(0, 0X5E);
    // 0x800899B8: sh          $t1, 0x74A($a0)
    MEM_H(0X74A, ctx->r4) = ctx->r9;
    // 0x800899BC: addiu       $t2, $zero, -0x8C
    ctx->r10 = ADD32(0, -0X8C);
    // 0x800899C0: sh          $t2, 0x74C($a0)
    MEM_H(0X74C, ctx->r4) = ctx->r10;
    // 0x800899C4: addiu       $t3, $zero, -0x35
    ctx->r11 = ADD32(0, -0X35);
    // 0x800899C8: sh          $t3, 0x74E($a0)
    MEM_H(0X74E, ctx->r4) = ctx->r11;
    // 0x800899CC: addiu       $t4, $a0, 0x750
    ctx->r12 = ADD32(ctx->r4, 0X750);
    // 0x800899D0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800899D4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800899D8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800899DC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800899E0: nop

    // 0x800899E4: beq         $t6, $at, L_80089ACC
    if (ctx->r14 == ctx->r1) {
        // 0x800899E8: nop

            goto L_80089ACC;
    }
    // 0x800899E8: nop

L_800899EC:
    // 0x800899EC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800899F0: lh          $t9, 0x748($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X748);
    // 0x800899F4: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800899F8: nop

    // 0x800899FC: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80089A00: beq         $at, $zero, L_80089A1C
    if (ctx->r1 == 0) {
        // 0x80089A04: nop

            goto L_80089A1C;
    }
    // 0x80089A04: nop

    // 0x80089A08: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80089A0C: nop

    // 0x80089A10: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80089A14: nop

    // 0x80089A18: sh          $t1, 0x748($a0)
    MEM_H(0X748, ctx->r4) = ctx->r9;
L_80089A1C:
    // 0x80089A1C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80089A20: lh          $t4, 0x74A($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X74A);
    // 0x80089A24: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x80089A28: nop

    // 0x80089A2C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80089A30: beq         $at, $zero, L_80089A4C
    if (ctx->r1 == 0) {
        // 0x80089A34: nop

            goto L_80089A4C;
    }
    // 0x80089A34: nop

    // 0x80089A38: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80089A3C: nop

    // 0x80089A40: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80089A44: nop

    // 0x80089A48: sh          $t6, 0x74A($a0)
    MEM_H(0X74A, ctx->r4) = ctx->r14;
L_80089A4C:
    // 0x80089A4C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80089A50: lh          $t9, 0x74C($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X74C);
    // 0x80089A54: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80089A58: nop

    // 0x80089A5C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80089A60: beq         $at, $zero, L_80089A7C
    if (ctx->r1 == 0) {
        // 0x80089A64: nop

            goto L_80089A7C;
    }
    // 0x80089A64: nop

    // 0x80089A68: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80089A6C: nop

    // 0x80089A70: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x80089A74: nop

    // 0x80089A78: sh          $t1, 0x74C($a0)
    MEM_H(0X74C, ctx->r4) = ctx->r9;
L_80089A7C:
    // 0x80089A7C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80089A80: lh          $t4, 0x74E($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X74E);
    // 0x80089A84: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x80089A88: nop

    // 0x80089A8C: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80089A90: beq         $at, $zero, L_80089AAC
    if (ctx->r1 == 0) {
        // 0x80089A94: nop

            goto L_80089AAC;
    }
    // 0x80089A94: nop

    // 0x80089A98: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80089A9C: nop

    // 0x80089AA0: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x80089AA4: nop

    // 0x80089AA8: sh          $t6, 0x74E($a0)
    MEM_H(0X74E, ctx->r4) = ctx->r14;
L_80089AAC:
    // 0x80089AAC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80089AB0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80089AB4: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80089AB8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80089ABC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80089AC0: nop

    // 0x80089AC4: bne         $t9, $at, L_800899EC
    if (ctx->r25 != ctx->r1) {
        // 0x80089AC8: nop

            goto L_800899EC;
    }
    // 0x80089AC8: nop

L_80089ACC:
    // 0x80089ACC: b           L_80089AFC
    // 0x80089AD0: nop

        goto L_80089AFC;
    // 0x80089AD0: nop

L_80089AD4:
    // 0x80089AD4: addiu       $t0, $zero, -0x8C
    ctx->r8 = ADD32(0, -0X8C);
    // 0x80089AD8: sh          $t0, 0x748($a0)
    MEM_H(0X748, ctx->r4) = ctx->r8;
    // 0x80089ADC: addiu       $t1, $zero, -0x35
    ctx->r9 = ADD32(0, -0X35);
    // 0x80089AE0: sh          $t1, 0x74A($a0)
    MEM_H(0X74A, ctx->r4) = ctx->r9;
    // 0x80089AE4: addiu       $t2, $zero, 0x7B
    ctx->r10 = ADD32(0, 0X7B);
    // 0x80089AE8: sh          $t2, 0x74C($a0)
    MEM_H(0X74C, ctx->r4) = ctx->r10;
    // 0x80089AEC: addiu       $t3, $zero, 0x5E
    ctx->r11 = ADD32(0, 0X5E);
    // 0x80089AF0: sh          $t3, 0x74E($a0)
    MEM_H(0X74E, ctx->r4) = ctx->r11;
    // 0x80089AF4: b           L_80089AFC
    // 0x80089AF8: nop

        goto L_80089AFC;
    // 0x80089AF8: nop

L_80089AFC:
    // 0x80089AFC: jr          $ra
    // 0x80089B00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80089B00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80089B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B04: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80089B08: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80089B0C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80089B10: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80089B14: sh          $a1, 0xBDA($a0)
    MEM_H(0XBDA, ctx->r4) = ctx->r5;
    // 0x80089B18: sh          $a2, 0xBDC($a0)
    MEM_H(0XBDC, ctx->r4) = ctx->r6;
    // 0x80089B1C: lh          $t6, 0xBDA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XBDA);
    // 0x80089B20: lwc1        $f8, 0x740($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X740);
    // 0x80089B24: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80089B28: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80089B2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80089B30: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80089B34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80089B38: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80089B3C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80089B40: nop

    // 0x80089B44: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80089B48: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80089B4C: swc1        $f6, 0xBE0($a0)
    MEM_W(0XBE0, ctx->r4) = ctx->f6.u32l;
    // 0x80089B50: lh          $t7, 0xBDC($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XBDC);
    // 0x80089B54: lwc1        $f16, 0x744($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X744);
    // 0x80089B58: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80089B5C: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80089B60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089B64: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80089B68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80089B6C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80089B70: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80089B74: nop

    // 0x80089B78: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80089B7C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80089B80: swc1        $f10, 0xBE4($a0)
    MEM_W(0XBE4, ctx->r4) = ctx->f10.u32l;
    // 0x80089B84: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x80089B88: nop

    // 0x80089B8C: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x80089B90: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80089B94: jr          $ra
    // 0x80089B98: nop

    return;
    // 0x80089B98: nop

    // 0x80089B9C: jr          $ra
    // 0x80089BA0: nop

    return;
    // 0x80089BA0: nop

;}
RECOMP_FUNC void func_80089BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BA4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80089BA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80089BAC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80089BB0: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80089BB4: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80089BB8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80089BBC: nop

    // 0x80089BC0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80089BC4: nop

    // 0x80089BC8: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x80089BCC: beq         $t8, $zero, L_80089DE4
    if (ctx->r24 == 0) {
        // 0x80089BD0: nop

            goto L_80089DE4;
    }
    // 0x80089BD0: nop

    // 0x80089BD4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80089BD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80089BDC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80089BE0: lwc1        $f4, 0xBE0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XBE0);
    // 0x80089BE4: lwc1        $f10, 0x740($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X740);
    // 0x80089BE8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80089BEC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80089BF0: swc1        $f16, 0x740($t9)
    MEM_W(0X740, ctx->r25) = ctx->f16.u32l;
    // 0x80089BF4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80089BF8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80089BFC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80089C00: lwc1        $f18, 0xBE0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XBE0);
    // 0x80089C04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80089C08: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80089C0C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80089C10: nop

    // 0x80089C14: bc1f        L_80089C58
    if (!c1cs) {
        // 0x80089C18: nop

            goto L_80089C58;
    }
    // 0x80089C18: nop

    // 0x80089C1C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80089C20: nop

    // 0x80089C24: lh          $t2, 0xBDA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XBDA);
    // 0x80089C28: lwc1        $f10, 0x740($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X740);
    // 0x80089C2C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80089C30: nop

    // 0x80089C34: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089C38: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80089C3C: nop

    // 0x80089C40: bc1f        L_80089C50
    if (!c1cs) {
        // 0x80089C44: nop

            goto L_80089C50;
    }
    // 0x80089C44: nop

    // 0x80089C48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80089C4C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_80089C50:
    // 0x80089C50: b           L_80089C8C
    // 0x80089C54: nop

        goto L_80089C8C;
    // 0x80089C54: nop

L_80089C58:
    // 0x80089C58: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80089C5C: nop

    // 0x80089C60: lh          $t5, 0xBDA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XBDA);
    // 0x80089C64: lwc1        $f18, 0x740($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X740);
    // 0x80089C68: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80089C6C: nop

    // 0x80089C70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80089C74: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x80089C78: nop

    // 0x80089C7C: bc1f        L_80089C8C
    if (!c1cs) {
        // 0x80089C80: nop

            goto L_80089C8C;
    }
    // 0x80089C80: nop

    // 0x80089C84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089C88: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80089C8C:
    // 0x80089C8C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80089C90: nop

    // 0x80089C94: beq         $t7, $zero, L_80089CBC
    if (ctx->r15 == 0) {
        // 0x80089C98: nop

            goto L_80089CBC;
    }
    // 0x80089C98: nop

    // 0x80089C9C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80089CA0: nop

    // 0x80089CA4: lh          $t9, 0xBDA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XBDA);
    // 0x80089CA8: nop

    // 0x80089CAC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80089CB0: nop

    // 0x80089CB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089CB8: swc1        $f10, 0x740($t8)
    MEM_W(0X740, ctx->r24) = ctx->f10.u32l;
L_80089CBC:
    // 0x80089CBC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80089CC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80089CC4: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80089CC8: lwc1        $f16, 0xBE4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XBE4);
    // 0x80089CCC: lwc1        $f6, 0x744($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X744);
    // 0x80089CD0: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80089CD4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80089CD8: swc1        $f8, 0x744($t0)
    MEM_W(0X744, ctx->r8) = ctx->f8.u32l;
    // 0x80089CDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80089CE0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80089CE4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80089CE8: lwc1        $f10, 0xBE4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XBE4);
    // 0x80089CEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80089CF0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80089CF4: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x80089CF8: nop

    // 0x80089CFC: bc1f        L_80089D40
    if (!c1cs) {
        // 0x80089D00: nop

            goto L_80089D40;
    }
    // 0x80089D00: nop

    // 0x80089D04: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80089D08: nop

    // 0x80089D0C: lh          $t3, 0xBDC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XBDC);
    // 0x80089D10: lwc1        $f6, 0x744($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X744);
    // 0x80089D14: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80089D18: nop

    // 0x80089D1C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80089D20: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80089D24: nop

    // 0x80089D28: bc1f        L_80089D38
    if (!c1cs) {
        // 0x80089D2C: nop

            goto L_80089D38;
    }
    // 0x80089D2C: nop

    // 0x80089D30: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80089D34: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80089D38:
    // 0x80089D38: b           L_80089D74
    // 0x80089D3C: nop

        goto L_80089D74;
    // 0x80089D3C: nop

L_80089D40:
    // 0x80089D40: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80089D44: nop

    // 0x80089D48: lh          $t6, 0xBDC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBDC);
    // 0x80089D4C: lwc1        $f10, 0x744($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X744);
    // 0x80089D50: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80089D54: nop

    // 0x80089D58: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80089D5C: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x80089D60: nop

    // 0x80089D64: bc1f        L_80089D74
    if (!c1cs) {
        // 0x80089D68: nop

            goto L_80089D74;
    }
    // 0x80089D68: nop

    // 0x80089D6C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089D70: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089D74:
    // 0x80089D74: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80089D78: nop

    // 0x80089D7C: beq         $t9, $zero, L_80089DA4
    if (ctx->r25 == 0) {
        // 0x80089D80: nop

            goto L_80089DA4;
    }
    // 0x80089D80: nop

    // 0x80089D84: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80089D88: nop

    // 0x80089D8C: lh          $t0, 0xBDC($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XBDC);
    // 0x80089D90: nop

    // 0x80089D94: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80089D98: nop

    // 0x80089D9C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80089DA0: swc1        $f6, 0x744($t8)
    MEM_W(0X744, ctx->r24) = ctx->f6.u32l;
L_80089DA4:
    // 0x80089DA4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80089DA8: nop

    // 0x80089DAC: beq         $t1, $zero, L_80089DDC
    if (ctx->r9 == 0) {
        // 0x80089DB0: nop

            goto L_80089DDC;
    }
    // 0x80089DB0: nop

    // 0x80089DB4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80089DB8: nop

    // 0x80089DBC: beq         $t2, $zero, L_80089DDC
    if (ctx->r10 == 0) {
        // 0x80089DC0: nop

            goto L_80089DDC;
    }
    // 0x80089DC0: nop

    // 0x80089DC4: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80089DC8: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x80089DCC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80089DD0: nop

    // 0x80089DD4: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80089DD8: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
L_80089DDC:
    // 0x80089DDC: b           L_8008A06C
    // 0x80089DE0: nop

        goto L_8008A06C;
    // 0x80089DE0: nop

L_80089DE4:
    // 0x80089DE4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80089DE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80089DEC: lwc1        $f8, 0xC18($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC18);
    // 0x80089DF0: nop

    // 0x80089DF4: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80089DF8: nop

    // 0x80089DFC: bc1f        L_80089E0C
    if (!c1cs) {
        // 0x80089E00: nop

            goto L_80089E0C;
    }
    // 0x80089E00: nop

    // 0x80089E04: b           L_80089E20
    // 0x80089E08: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
        goto L_80089E20;
    // 0x80089E08: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
L_80089E0C:
    // 0x80089E0C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80089E10: nop

    // 0x80089E14: lwc1        $f20, 0xC18($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0XC18);
    // 0x80089E18: nop

    // 0x80089E1C: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f20.fl = -ctx->f20.fl;
L_80089E20:
    // 0x80089E20: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80089E24: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80089E28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80089E2C: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x80089E30: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80089E34: nop

    // 0x80089E38: bc1f        L_80089F28
    if (!c1cs) {
        // 0x80089E3C: nop

            goto L_80089F28;
    }
    // 0x80089E3C: nop

    // 0x80089E40: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80089E44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80089E48: lwc1        $f18, 0xC18($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC18);
    // 0x80089E4C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80089E50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80089E54: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80089E58: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80089E5C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80089E60: lwc1        $f11, -0xA30($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XA30);
    // 0x80089E64: lwc1        $f10, -0xA2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XA2C);
    // 0x80089E68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80089E6C: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80089E70: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80089E74: lwc1        $f8, 0x740($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X740);
    // 0x80089E78: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80089E7C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80089E80: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80089E84: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80089E88: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80089E8C: swc1        $f4, 0x740($t9)
    MEM_W(0X740, ctx->r25) = ctx->f4.u32l;
    // 0x80089E90: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80089E94: nop

    // 0x80089E98: lh          $t8, 0x748($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X748);
    // 0x80089E9C: lwc1        $f6, 0x740($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X740);
    // 0x80089EA0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80089EA4: nop

    // 0x80089EA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089EAC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80089EB0: nop

    // 0x80089EB4: bc1f        L_80089EDC
    if (!c1cs) {
        // 0x80089EB8: nop

            goto L_80089EDC;
    }
    // 0x80089EB8: nop

    // 0x80089EBC: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80089EC0: nop

    // 0x80089EC4: lh          $t2, 0x748($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X748);
    // 0x80089EC8: nop

    // 0x80089ECC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80089ED0: nop

    // 0x80089ED4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80089ED8: swc1        $f18, 0x740($t1)
    MEM_W(0X740, ctx->r9) = ctx->f18.u32l;
L_80089EDC:
    // 0x80089EDC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80089EE0: nop

    // 0x80089EE4: lh          $t5, 0x74C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X74C);
    // 0x80089EE8: lwc1        $f4, 0x740($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X740);
    // 0x80089EEC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80089EF0: nop

    // 0x80089EF4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089EF8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80089EFC: nop

    // 0x80089F00: bc1f        L_80089F28
    if (!c1cs) {
        // 0x80089F04: nop

            goto L_80089F28;
    }
    // 0x80089F04: nop

    // 0x80089F08: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80089F0C: nop

    // 0x80089F10: lh          $t6, 0x74C($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X74C);
    // 0x80089F14: nop

    // 0x80089F18: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80089F1C: nop

    // 0x80089F20: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80089F24: swc1        $f16, 0x740($t3)
    MEM_W(0X740, ctx->r11) = ctx->f16.u32l;
L_80089F28:
    // 0x80089F28: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80089F2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80089F30: lwc1        $f18, 0xC1C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC1C);
    // 0x80089F34: nop

    // 0x80089F38: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80089F3C: nop

    // 0x80089F40: bc1f        L_80089F50
    if (!c1cs) {
        // 0x80089F44: nop

            goto L_80089F50;
    }
    // 0x80089F44: nop

    // 0x80089F48: b           L_80089F64
    // 0x80089F4C: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
        goto L_80089F64;
    // 0x80089F4C: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_80089F50:
    // 0x80089F50: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80089F54: nop

    // 0x80089F58: lwc1        $f20, 0xC1C($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XC1C);
    // 0x80089F5C: nop

    // 0x80089F60: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f20.fl = -ctx->f20.fl;
L_80089F64:
    // 0x80089F64: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80089F68: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80089F6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80089F70: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x80089F74: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80089F78: nop

    // 0x80089F7C: bc1f        L_8008A06C
    if (!c1cs) {
        // 0x80089F80: nop

            goto L_8008A06C;
    }
    // 0x80089F80: nop

    // 0x80089F84: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80089F88: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80089F8C: lwc1        $f10, 0xC1C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC1C);
    // 0x80089F90: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80089F94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80089F98: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80089F9C: mul.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80089FA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80089FA4: lwc1        $f5, -0xA28($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XA28);
    // 0x80089FA8: lwc1        $f4, -0xA24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XA24);
    // 0x80089FAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80089FB0: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x80089FB4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80089FB8: lwc1        $f18, 0x744($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X744);
    // 0x80089FBC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80089FC0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80089FC4: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80089FC8: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80089FCC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80089FD0: swc1        $f6, 0x744($t0)
    MEM_W(0X744, ctx->r8) = ctx->f6.u32l;
    // 0x80089FD4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80089FD8: nop

    // 0x80089FDC: lh          $t2, 0x74A($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X74A);
    // 0x80089FE0: lwc1        $f16, 0x744($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X744);
    // 0x80089FE4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80089FE8: nop

    // 0x80089FEC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80089FF0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80089FF4: nop

    // 0x80089FF8: bc1f        L_8008A020
    if (!c1cs) {
        // 0x80089FFC: nop

            goto L_8008A020;
    }
    // 0x80089FFC: nop

    // 0x8008A000: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8008A004: nop

    // 0x8008A008: lh          $t4, 0x74A($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X74A);
    // 0x8008A00C: nop

    // 0x8008A010: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8008A014: nop

    // 0x8008A018: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008A01C: swc1        $f10, 0x744($t1)
    MEM_W(0X744, ctx->r9) = ctx->f10.u32l;
L_8008A020:
    // 0x8008A020: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008A024: nop

    // 0x8008A028: lh          $t6, 0x74E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X74E);
    // 0x8008A02C: lwc1        $f6, 0x744($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X744);
    // 0x8008A030: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8008A034: nop

    // 0x8008A038: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008A03C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8008A040: nop

    // 0x8008A044: bc1f        L_8008A06C
    if (!c1cs) {
        // 0x8008A048: nop

            goto L_8008A06C;
    }
    // 0x8008A048: nop

    // 0x8008A04C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8008A050: nop

    // 0x8008A054: lh          $t7, 0x74E($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X74E);
    // 0x8008A058: nop

    // 0x8008A05C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8008A060: nop

    // 0x8008A064: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008A068: swc1        $f8, 0x744($t3)
    MEM_W(0X744, ctx->r11) = ctx->f8.u32l;
L_8008A06C:
    // 0x8008A06C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8008A070: nop

    // 0x8008A074: lhu         $t0, 0xC20($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XC20);
    // 0x8008A078: nop

    // 0x8008A07C: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x8008A080: jal         0x80031AC8
    // 0x8008A084: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x8008A084: nop

    after_0:
    // 0x8008A088: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8008A08C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8008A090: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008A094: lh          $t2, 0x4($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X4);
    // 0x8008A098: lh          $t5, 0x73C($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X73C);
    // 0x8008A09C: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x8008A0A0: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x8008A0A4: lh          $t1, 0x4664($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4664);
    // 0x8008A0A8: nop

    // 0x8008A0AC: beq         $t1, $t5, L_8008A0C4
    if (ctx->r9 == ctx->r13) {
        // 0x8008A0B0: nop

            goto L_8008A0C4;
    }
    // 0x8008A0B0: nop

    // 0x8008A0B4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A0B8: nop

    // 0x8008A0BC: bne         $t6, $zero, L_8008A118
    if (ctx->r14 != 0) {
        // 0x8008A0C0: nop

            goto L_8008A118;
    }
    // 0x8008A0C0: nop

L_8008A0C4:
    // 0x8008A0C4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8008A0C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008A0CC: lh          $t3, 0x4($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X4);
    // 0x8008A0D0: lh          $t2, 0x73C($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X73C);
    // 0x8008A0D4: sll         $t9, $t3, 3
    ctx->r25 = S32(ctx->r11 << 3);
    // 0x8008A0D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8008A0DC: lh          $t0, 0x4664($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X4664);
    // 0x8008A0E0: nop

    // 0x8008A0E4: bne         $t0, $t2, L_8008A0FC
    if (ctx->r8 != ctx->r10) {
        // 0x8008A0E8: nop

            goto L_8008A0FC;
    }
    // 0x8008A0E8: nop

    // 0x8008A0EC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A0F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008A0F4: beq         $t4, $at, L_8008A118
    if (ctx->r12 == ctx->r1) {
        // 0x8008A0F8: nop

            goto L_8008A118;
    }
    // 0x8008A0F8: nop

L_8008A0FC:
    // 0x8008A0FC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8008A100: nop

    // 0x8008A104: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x8008A108: nop

    // 0x8008A10C: andi        $t5, $t1, 0x100
    ctx->r13 = ctx->r9 & 0X100;
    // 0x8008A110: beq         $t5, $zero, L_8008A148
    if (ctx->r13 == 0) {
        // 0x8008A114: nop

            goto L_8008A148;
    }
    // 0x8008A114: nop

L_8008A118:
    // 0x8008A118: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008A11C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008A120: lhu         $t3, 0xFF4($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XFF4);
    // 0x8008A124: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8008A128: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008A12C: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x8008A130: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x8008A134: lhu         $t4, 0x42($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X42);
    // 0x8008A138: or          $t0, $t9, $t7
    ctx->r8 = ctx->r25 | ctx->r15;
    // 0x8008A13C: nor         $t2, $t0, $zero
    ctx->r10 = ~(ctx->r8 | 0);
    // 0x8008A140: and         $t8, $t4, $t2
    ctx->r24 = ctx->r12 & ctx->r10;
    // 0x8008A144: sh          $t8, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r24;
L_8008A148:
    // 0x8008A148: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008A14C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008A150: lhu         $t5, 0xFF4($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XFF4);
    // 0x8008A154: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8008A158: lhu         $t3, 0x42($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X42);
    // 0x8008A15C: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x8008A160: and         $t9, $t3, $t6
    ctx->r25 = ctx->r11 & ctx->r14;
    // 0x8008A164: beq         $t9, $zero, L_8008A1A4
    if (ctx->r25 == 0) {
        // 0x8008A168: nop

            goto L_8008A1A4;
    }
    // 0x8008A168: nop

    // 0x8008A16C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8008A170: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x8008A174: lwc1        $f10, 0x740($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X740);
    // 0x8008A178: ori         $a2, $a2, 0x22A
    ctx->r6 = ctx->r6 | 0X22A;
    // 0x8008A17C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8008A180: lwc1        $f18, 0x744($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X744);
    // 0x8008A184: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008A188: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8008A18C: addiu       $a0, $t7, 0x3C
    ctx->r4 = ADD32(ctx->r15, 0X3C);
    // 0x8008A190: addiu       $a1, $t7, 0x40
    ctx->r5 = ADD32(ctx->r15, 0X40);
    // 0x8008A194: jal         0x800B202C
    // 0x8008A198: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B202C(rdram, ctx);
        goto after_1;
    // 0x8008A198: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8008A19C: b           L_8008A200
    // 0x8008A1A0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
        goto L_8008A200;
    // 0x8008A1A0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_8008A1A4:
    // 0x8008A1A4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8008A1A8: nop

    // 0x8008A1AC: addiu       $a0, $t0, 0x3C
    ctx->r4 = ADD32(ctx->r8, 0X3C);
    // 0x8008A1B0: jal         0x800B2748
    // 0x8008A1B4: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    func_800B2748(rdram, ctx);
        goto after_2;
    // 0x8008A1B4: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    after_2:
    // 0x8008A1B8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8008A1BC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8008A1C0: nop

    // 0x8008A1C4: bgez        $t4, L_8008A200
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8008A1C8: nop

            goto L_8008A200;
    }
    // 0x8008A1C8: nop

    // 0x8008A1CC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8008A1D0: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x8008A1D4: lwc1        $f6, 0x740($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X740);
    // 0x8008A1D8: ori         $a2, $a2, 0x229
    ctx->r6 = ctx->r6 | 0X229;
    // 0x8008A1DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8008A1E0: lwc1        $f16, 0x744($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X744);
    // 0x8008A1E4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008A1E8: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8008A1EC: addiu       $a0, $t2, 0x3C
    ctx->r4 = ADD32(ctx->r10, 0X3C);
    // 0x8008A1F0: addiu       $a1, $t2, 0x40
    ctx->r5 = ADD32(ctx->r10, 0X40);
    // 0x8008A1F4: jal         0x800B202C
    // 0x8008A1F8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_3;
    // 0x8008A1F8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8008A1FC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_8008A200:
    // 0x8008A200: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8008A204: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8008A208: nop

    // 0x8008A20C: sh          $t8, 0x46($t1)
    MEM_H(0X46, ctx->r9) = ctx->r24;
    // 0x8008A210: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008A214: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8008A218: lw          $t3, 0x3C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X3C);
    // 0x8008A21C: nop

    // 0x8008A220: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8008A224: lhu         $t6, 0x44($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X44);
    // 0x8008A228: nop

    // 0x8008A22C: blez        $t6, L_8008A28C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8008A230: nop

            goto L_8008A28C;
    }
    // 0x8008A230: nop

L_8008A234:
    // 0x8008A234: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8008A238: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A23C: lwc1        $f4, 0x740($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X740);
    // 0x8008A240: nop

    // 0x8008A244: swc1        $f4, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f4.u32l;
    // 0x8008A248: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8008A24C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A250: lwc1        $f8, 0x744($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X744);
    // 0x8008A254: nop

    // 0x8008A258: swc1        $f8, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f8.u32l;
    // 0x8008A25C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8008A260: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A264: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008A268: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8008A26C: addiu       $t3, $t1, 0x160
    ctx->r11 = ADD32(ctx->r9, 0X160);
    // 0x8008A270: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8008A274: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x8008A278: lhu         $t6, 0x44($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X44);
    // 0x8008A27C: nop

    // 0x8008A280: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008A284: bne         $at, $zero, L_8008A234
    if (ctx->r1 != 0) {
        // 0x8008A288: nop

            goto L_8008A234;
    }
    // 0x8008A288: nop

L_8008A28C:
    // 0x8008A28C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8008A290: jal         0x8008A518
    // 0x8008A294: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_8008A518(rdram, ctx);
        goto after_4;
    // 0x8008A294: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x8008A298: beq         $v0, $zero, L_8008A328
    if (ctx->r2 == 0) {
        // 0x8008A29C: nop

            goto L_8008A328;
    }
    // 0x8008A29C: nop

    // 0x8008A2A0: lhu         $t9, 0x4E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4E);
    // 0x8008A2A4: nop

    // 0x8008A2A8: andi        $t7, $t9, 0x2
    ctx->r15 = ctx->r25 & 0X2;
    // 0x8008A2AC: bne         $t7, $zero, L_8008A328
    if (ctx->r15 != 0) {
        // 0x8008A2B0: nop

            goto L_8008A328;
    }
    // 0x8008A2B0: nop

    // 0x8008A2B4: lh          $t0, 0x46($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X46);
    // 0x8008A2B8: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8008A2BC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8008A2C0: nop

    // 0x8008A2C4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008A2C8: swc1        $f18, 0x114($t4)
    MEM_W(0X114, ctx->r12) = ctx->f18.u32l;
    // 0x8008A2CC: lh          $t2, 0x48($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X48);
    // 0x8008A2D0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8008A2D4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8008A2D8: nop

    // 0x8008A2DC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008A2E0: swc1        $f16, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->f16.u32l;
    // 0x8008A2E4: lh          $t3, 0x4A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X4A);
    // 0x8008A2E8: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x8008A2EC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8008A2F0: subu        $t8, $t3, $t5
    ctx->r24 = SUB32(ctx->r11, ctx->r13);
    // 0x8008A2F4: sh          $t8, 0x148($t6)
    MEM_H(0X148, ctx->r14) = ctx->r24;
    // 0x8008A2F8: lh          $t9, 0x4C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4C);
    // 0x8008A2FC: lh          $t7, 0x48($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X48);
    // 0x8008A300: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8008A304: subu        $t0, $t9, $t7
    ctx->r8 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A308: sh          $t0, 0x14A($t4)
    MEM_H(0X14A, ctx->r12) = ctx->r8;
    // 0x8008A30C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8008A310: nop

    // 0x8008A314: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x8008A318: nop

    // 0x8008A31C: ori         $t3, $t1, 0x4
    ctx->r11 = ctx->r9 | 0X4;
    // 0x8008A320: b           L_8008A340
    // 0x8008A324: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
        goto L_8008A340;
    // 0x8008A324: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
L_8008A328:
    // 0x8008A328: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008A32C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8008A330: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x8008A334: nop

    // 0x8008A338: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8008A33C: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_8008A340:
    // 0x8008A340: lhu         $v0, 0x42($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X42);
    // 0x8008A344: b           L_8008A354
    // 0x8008A348: nop

        goto L_8008A354;
    // 0x8008A348: nop

    // 0x8008A34C: b           L_8008A354
    // 0x8008A350: nop

        goto L_8008A354;
    // 0x8008A350: nop

L_8008A354:
    // 0x8008A354: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A358: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8008A35C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8008A360: jr          $ra
    // 0x8008A364: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008A364: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
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
RECOMP_FUNC void func_8008A46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A46C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008A470: bgez        $a1, L_8008A4CC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008A474: nop

            goto L_8008A4CC;
    }
    // 0x8008A474: nop

    // 0x8008A478: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008A47C:
    // 0x8008A47C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008A480: nop

    // 0x8008A484: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008A488: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008A48C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008A490: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008A494: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8008A498: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008A49C: lw          $t9, 0x268($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X268);
    // 0x8008A4A0: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x8008A4A4: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8008A4A8: sw          $t0, 0x268($t1)
    MEM_W(0X268, ctx->r9) = ctx->r8;
    // 0x8008A4AC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008A4B0: nop

    // 0x8008A4B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008A4B8: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8008A4BC: bne         $at, $zero, L_8008A47C
    if (ctx->r1 != 0) {
        // 0x8008A4C0: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8008A47C;
    }
    // 0x8008A4C0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8008A4C4: b           L_8008A510
    // 0x8008A4C8: nop

        goto L_8008A510;
    // 0x8008A4C8: nop

L_8008A4CC:
    // 0x8008A4CC: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8008A4D0: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8008A4D4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A4D8: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x8008A4DC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8008A4E0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8008A4E4: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8008A4E8: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8008A4EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A4F0: lw          $t6, 0x268($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X268);
    // 0x8008A4F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8008A4F8: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8008A4FC: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x8008A500: ori         $t8, $t6, 0x80
    ctx->r24 = ctx->r14 | 0X80;
    // 0x8008A504: sw          $t8, 0x268($t7)
    MEM_W(0X268, ctx->r15) = ctx->r24;
    // 0x8008A508: b           L_8008A510
    // 0x8008A50C: nop

        goto L_8008A510;
    // 0x8008A50C: nop

L_8008A510:
    // 0x8008A510: jr          $ra
    // 0x8008A514: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008A514: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008A518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008A51C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A520: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008A524: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008A528: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008A52C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8008A530: lhu         $t7, 0x750($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X750);
    // 0x8008A534: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8008A538: beq         $t7, $at, L_8008A654
    if (ctx->r15 == ctx->r1) {
        // 0x8008A53C: nop

            goto L_8008A654;
    }
    // 0x8008A53C: nop

L_8008A540:
    // 0x8008A540: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A544: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008A548: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008A54C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8008A550: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008A554: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008A558: lh          $t2, 0x752($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X752);
    // 0x8008A55C: lwc1        $f4, 0x740($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X740);
    // 0x8008A560: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8008A564: nop

    // 0x8008A568: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008A56C: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8008A570: nop

    // 0x8008A574: bc1f        L_8008A618
    if (!c1cs) {
        // 0x8008A578: nop

            goto L_8008A618;
    }
    // 0x8008A578: nop

    // 0x8008A57C: lh          $t3, 0x756($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X756);
    // 0x8008A580: nop

    // 0x8008A584: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8008A588: nop

    // 0x8008A58C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008A590: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x8008A594: nop

    // 0x8008A598: bc1f        L_8008A618
    if (!c1cs) {
        // 0x8008A59C: nop

            goto L_8008A618;
    }
    // 0x8008A59C: nop

    // 0x8008A5A0: lh          $t4, 0x754($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X754);
    // 0x8008A5A4: lwc1        $f18, 0x744($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X744);
    // 0x8008A5A8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8008A5AC: nop

    // 0x8008A5B0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008A5B4: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8008A5B8: nop

    // 0x8008A5BC: bc1f        L_8008A618
    if (!c1cs) {
        // 0x8008A5C0: nop

            goto L_8008A618;
    }
    // 0x8008A5C0: nop

    // 0x8008A5C4: lh          $t5, 0x758($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X758);
    // 0x8008A5C8: nop

    // 0x8008A5CC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8008A5D0: nop

    // 0x8008A5D4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008A5D8: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x8008A5DC: nop

    // 0x8008A5E0: bc1f        L_8008A618
    if (!c1cs) {
        // 0x8008A5E4: nop

            goto L_8008A618;
    }
    // 0x8008A5E4: nop

    // 0x8008A5E8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A5EC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008A5F0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8008A5F4: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A5F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A5FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008A600: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    // 0x8008A604: addiu       $a1, $a1, 0x750
    ctx->r5 = ADD32(ctx->r5, 0X750);
    // 0x8008A608: jal         0x800BCFCC
    // 0x8008A60C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x8008A60C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x8008A610: b           L_8008A664
    // 0x8008A614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008A664;
    // 0x8008A614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008A618:
    // 0x8008A618: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A61C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008A620: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8008A624: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8008A628: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x8008A62C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008A630: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8008A634: addu        $t4, $t3, $t8
    ctx->r12 = ADD32(ctx->r11, ctx->r24);
    // 0x8008A638: lhu         $t1, 0x750($t4)
    ctx->r9 = MEM_HU(ctx->r12, 0X750);
    // 0x8008A63C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8008A640: beq         $t1, $at, L_8008A654
    if (ctx->r9 == ctx->r1) {
        // 0x8008A644: nop

            goto L_8008A654;
    }
    // 0x8008A644: nop

    // 0x8008A648: slti        $at, $t2, 0x60
    ctx->r1 = SIGNED(ctx->r10) < 0X60 ? 1 : 0;
    // 0x8008A64C: bne         $at, $zero, L_8008A540
    if (ctx->r1 != 0) {
        // 0x8008A650: nop

            goto L_8008A540;
    }
    // 0x8008A650: nop

L_8008A654:
    // 0x8008A654: b           L_8008A664
    // 0x8008A658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008A664;
    // 0x8008A658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008A65C: b           L_8008A664
    // 0x8008A660: nop

        goto L_8008A664;
    // 0x8008A660: nop

L_8008A664:
    // 0x8008A664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A668: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008A66C: jr          $ra
    // 0x8008A670: nop

    return;
    // 0x8008A670: nop

;}
RECOMP_FUNC void func_8008A674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A674: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008A678: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8008A67C:
    // 0x8008A67C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8008A680: nop

    // 0x8008A684: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008A688: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008A68C: lw          $t9, 0x12C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X12C);
    // 0x8008A690: nop

    // 0x8008A694: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8008A698: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8008A69C: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008A6A0: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008A6A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008A6A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008A6AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008A6B0: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8008A6B4: nop

    // 0x8008A6B8: bc1f        L_8008A708
    if (!c1cs) {
        // 0x8008A6BC: nop

            goto L_8008A708;
    }
    // 0x8008A6BC: nop

L_8008A6C0:
    // 0x8008A6C0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008A6C4: nop

    // 0x8008A6C8: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8008A6CC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008A6D0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008A6D4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008A6D8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008A6DC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008A6E0: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8008A6E4: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008A6E8: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008A6EC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8008A6F0: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008A6F4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008A6F8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008A6FC: nop

    // 0x8008A700: bc1t        L_8008A6C0
    if (c1cs) {
        // 0x8008A704: nop

            goto L_8008A6C0;
    }
    // 0x8008A704: nop

L_8008A708:
    // 0x8008A708: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8008A70C: nop

    // 0x8008A710: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008A714: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8008A718: bne         $at, $zero, L_8008A67C
    if (ctx->r1 != 0) {
        // 0x8008A71C: sw          $t6, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r14;
            goto L_8008A67C;
    }
    // 0x8008A71C: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8008A720: b           L_8008A728
    // 0x8008A724: nop

        goto L_8008A728;
    // 0x8008A724: nop

L_8008A728:
    // 0x8008A728: jr          $ra
    // 0x8008A72C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008A72C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8008A730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008A73C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008A740: jal         0x80031BB0
    // 0x8008A744: nop

    func_80031BB0(rdram, ctx);
        goto after_0;
    // 0x8008A744: nop

    after_0:
    // 0x8008A748: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8008A74C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008A750: nop

    // 0x8008A754: sh          $t6, 0x73C($t7)
    MEM_H(0X73C, ctx->r15) = ctx->r14;
    // 0x8008A758: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008A75C: nop

    // 0x8008A760: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8008A764: nop

    // 0x8008A768: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8008A76C: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x8008A770: b           L_8008A778
    // 0x8008A774: nop

        goto L_8008A778;
    // 0x8008A774: nop

L_8008A778:
    // 0x8008A778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A780: jr          $ra
    // 0x8008A784: nop

    return;
    // 0x8008A784: nop

;}
RECOMP_FUNC void func_8008A788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A78C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008A794: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008A798: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008A79C: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x8008A7A0: lh          $t0, 0x73C($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X73C);
    // 0x8008A7A4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008A7A8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008A7AC: lh          $t9, 0x4664($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4664);
    // 0x8008A7B0: nop

    // 0x8008A7B4: bne         $t9, $t0, L_8008A7C4
    if (ctx->r25 != ctx->r8) {
        // 0x8008A7B8: nop

            goto L_8008A7C4;
    }
    // 0x8008A7B8: nop

    // 0x8008A7BC: b           L_8008A7F8
    // 0x8008A7C0: nop

        goto L_8008A7F8;
    // 0x8008A7C0: nop

L_8008A7C4:
    // 0x8008A7C4: jal         0x80031AC8
    // 0x8008A7C8: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x8008A7C8: nop

    after_0:
    // 0x8008A7CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008A7D0: bne         $v0, $at, L_8008A7E8
    if (ctx->r2 != ctx->r1) {
        // 0x8008A7D4: nop

            goto L_8008A7E8;
    }
    // 0x8008A7D4: nop

    // 0x8008A7D8: jal         0x800317E4
    // 0x8008A7DC: nop

    func_800317E4(rdram, ctx);
        goto after_1;
    // 0x8008A7DC: nop

    after_1:
    // 0x8008A7E0: b           L_8008A7F0
    // 0x8008A7E4: nop

        goto L_8008A7F0;
    // 0x8008A7E4: nop

L_8008A7E8:
    // 0x8008A7E8: jal         0x80031BB0
    // 0x8008A7EC: nop

    func_80031BB0(rdram, ctx);
        goto after_2;
    // 0x8008A7EC: nop

    after_2:
L_8008A7F0:
    // 0x8008A7F0: b           L_8008A7F8
    // 0x8008A7F4: nop

        goto L_8008A7F8;
    // 0x8008A7F4: nop

L_8008A7F8:
    // 0x8008A7F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A7FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A800: jr          $ra
    // 0x8008A804: nop

    return;
    // 0x8008A804: nop

;}
RECOMP_FUNC void func_8008A808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A808: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008A80C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008A810: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008A814: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008A818: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008A81C: jal         0x80031AC8
    // 0x8008A820: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x8008A820: nop

    after_0:
    // 0x8008A824: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8008A828: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8008A82C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008A830: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x8008A834: lh          $t0, 0x73C($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X73C);
    // 0x8008A838: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008A83C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008A840: lh          $t9, 0x4664($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4664);
    // 0x8008A844: nop

    // 0x8008A848: bne         $t9, $t0, L_8008A894
    if (ctx->r25 != ctx->r8) {
        // 0x8008A84C: nop

            goto L_8008A894;
    }
    // 0x8008A84C: nop

    // 0x8008A850: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A854: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008A858: beq         $t1, $at, L_8008A88C
    if (ctx->r9 == ctx->r1) {
        // 0x8008A85C: nop

            goto L_8008A88C;
    }
    // 0x8008A85C: nop

    // 0x8008A860: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008A864: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008A868: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
    // 0x8008A86C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8008A870: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008A874: lhu         $t4, 0x10F2($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X10F2);
    // 0x8008A878: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8008A87C: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x8008A880: nor         $t5, $t4, $zero
    ctx->r13 = ~(ctx->r12 | 0);
    // 0x8008A884: and         $t7, $t3, $t5
    ctx->r15 = ctx->r11 & ctx->r13;
    // 0x8008A888: sh          $t7, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r15;
L_8008A88C:
    // 0x8008A88C: b           L_8008A950
    // 0x8008A890: nop

        goto L_8008A950;
    // 0x8008A890: nop

L_8008A894:
    // 0x8008A894: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A898: nop

    // 0x8008A89C: bne         $t8, $zero, L_8008A948
    if (ctx->r24 != 0) {
        // 0x8008A8A0: nop

            goto L_8008A948;
    }
    // 0x8008A8A0: nop

    // 0x8008A8A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8008A8A8: nop

    // 0x8008A8AC: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x8008A8B0: nop

    // 0x8008A8B4: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x8008A8B8: beq         $t0, $zero, L_8008A8DC
    if (ctx->r8 == 0) {
        // 0x8008A8BC: nop

            goto L_8008A8DC;
    }
    // 0x8008A8BC: nop

    // 0x8008A8C0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8008A8C4: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8008A8C8: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x8008A8CC: nop

    // 0x8008A8D0: and         $t3, $t4, $at
    ctx->r11 = ctx->r12 & ctx->r1;
    // 0x8008A8D4: b           L_8008A90C
    // 0x8008A8D8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
        goto L_8008A90C;
    // 0x8008A8D8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_8008A8DC:
    // 0x8008A8DC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8008A8E0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008A8E4: lh          $t7, 0x4($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X4);
    // 0x8008A8E8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8008A8EC: sll         $t2, $t7, 3
    ctx->r10 = S32(ctx->r15 << 3);
    // 0x8008A8F0: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x8008A8F4: lh          $s0, 0x4664($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X4664);
    // 0x8008A8F8: nop

    // 0x8008A8FC: bne         $s0, $at, L_8008A90C
    if (ctx->r16 != ctx->r1) {
        // 0x8008A900: sh          $s0, 0x73C($t5)
        MEM_H(0X73C, ctx->r13) = ctx->r16;
            goto L_8008A90C;
    }
    // 0x8008A900: sh          $s0, 0x73C($t5)
    MEM_H(0X73C, ctx->r13) = ctx->r16;
    // 0x8008A904: b           L_8008A950
    // 0x8008A908: nop

        goto L_8008A950;
    // 0x8008A908: nop

L_8008A90C:
    // 0x8008A90C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8008A910: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008A914: lh          $t9, 0x73C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X73C);
    // 0x8008A918: lw          $t6, 0x72C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X72C);
    // 0x8008A91C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008A920: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008A924: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x8008A928: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x8008A92C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008A930: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008A934: jal         0x800BD1FC
    // 0x8008A938: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x8008A938: nop

    after_1:
    // 0x8008A93C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8008A940: jal         0x800319B0
    // 0x8008A944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800319B0(rdram, ctx);
        goto after_2;
    // 0x8008A944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_8008A948:
    // 0x8008A948: b           L_8008A950
    // 0x8008A94C: nop

        goto L_8008A950;
    // 0x8008A94C: nop

L_8008A950:
    // 0x8008A950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A954: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008A958: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008A95C: jr          $ra
    // 0x8008A960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008A960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8008A964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A96C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008A970: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008A974: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8008A978: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008A97C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8008A980: lbu         $t7, -0x6230($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6230);
    // 0x8008A984: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008A988: nop

    // 0x8008A98C: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x8008A990: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008A994: nop

    // 0x8008A998: sh          $zero, 0xA($t9)
    MEM_H(0XA, ctx->r25) = 0;
    // 0x8008A99C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008A9A0: nop

    // 0x8008A9A4: lhu         $a0, 0x8($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X8);
    // 0x8008A9A8: nop

    // 0x8008A9AC: sll         $t1, $a0, 6
    ctx->r9 = S32(ctx->r4 << 6);
    // 0x8008A9B0: jal         0x800BC6EC
    // 0x8008A9B4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008A9B4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
    // 0x8008A9B8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008A9BC: nop

    // 0x8008A9C0: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x8008A9C4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008A9C8: nop

    // 0x8008A9CC: lhu         $a0, 0x8($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X8);
    // 0x8008A9D0: nop

    // 0x8008A9D4: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8008A9D8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8008A9DC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008A9E0: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8008A9E4: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8008A9E8: jal         0x800BC6EC
    // 0x8008A9EC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8008A9EC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_1:
    // 0x8008A9F0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8008A9F4: nop

    // 0x8008A9F8: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8008A9FC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA00: nop

    // 0x8008AA04: lhu         $a2, 0x8($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X8);
    // 0x8008AA08: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008AA0C: jal         0x800B1B3C
    // 0x8008AA10: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    func_800B1B3C(rdram, ctx);
        goto after_2;
    // 0x8008AA10: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_2:
    // 0x8008AA14: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AA1C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8008AA20: lhu         $a1, 0x8($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X8);
    // 0x8008AA24: jal         0x8008AAA8
    // 0x8008AA28: nop

    func_8008AAA8(rdram, ctx);
        goto after_3;
    // 0x8008AA28: nop

    after_3:
    // 0x8008AA2C: b           L_8008AA34
    // 0x8008AA30: nop

        goto L_8008AA34;
    // 0x8008AA30: nop

L_8008AA34:
    // 0x8008AA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AA38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AA3C: jr          $ra
    // 0x8008AA40: nop

    return;
    // 0x8008AA40: nop

;}
RECOMP_FUNC void func_8008AA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AA44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008AA48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AA4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008AA50: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA54: nop

    // 0x8008AA58: lhu         $a2, 0x8($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X8);
    // 0x8008AA5C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008AA60: jal         0x800B1C10
    // 0x8008AA64: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    func_800B1C10(rdram, ctx);
        goto after_0;
    // 0x8008AA64: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x8008AA68: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA6C: nop

    // 0x8008AA70: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x8008AA74: jal         0x800BC980
    // 0x8008AA78: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x8008AA78: nop

    after_1:
    // 0x8008AA7C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008AA80: nop

    // 0x8008AA84: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8008AA88: jal         0x800BC980
    // 0x8008AA8C: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8008AA8C: nop

    after_2:
    // 0x8008AA90: b           L_8008AA98
    // 0x8008AA94: nop

        goto L_8008AA98;
    // 0x8008AA94: nop

L_8008AA98:
    // 0x8008AA98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AA9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AAA0: jr          $ra
    // 0x8008AAA4: nop

    return;
    // 0x8008AAA4: nop

;}
RECOMP_FUNC void func_8008AAA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AAA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008AAAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AAB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008AAB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008AAB8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008AABC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008AAC0: nop

    // 0x8008AAC4: bne         $t6, $zero, L_8008AB48
    if (ctx->r14 != 0) {
        // 0x8008AAC8: nop

            goto L_8008AB48;
    }
    // 0x8008AAC8: nop

    // 0x8008AACC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008AAD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008AAD4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008AAD8: blez        $t8, L_8008AB40
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008AADC: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8008AB40;
    }
    // 0x8008AADC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8008AAE0:
    // 0x8008AAE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AAE4: jal         0x80099E2C
    // 0x8008AAE8: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x8008AAE8: nop

    after_0:
    // 0x8008AAEC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AAF0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8008AAF4: sh          $t9, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r25;
    // 0x8008AAF8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AAFC: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x8008AB00: sw          $t1, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r9;
    // 0x8008AB04: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AB08: nop

    // 0x8008AB0C: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x8008AB10: nop

    // 0x8008AB14: ori         $t5, $t4, 0xC
    ctx->r13 = ctx->r12 | 0XC;
    // 0x8008AB18: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x8008AB1C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008AB20: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AB24: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8008AB28: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008AB2C: addiu       $t9, $t8, 0x160
    ctx->r25 = ADD32(ctx->r24, 0X160);
    // 0x8008AB30: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8008AB34: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8008AB38: bne         $at, $zero, L_8008AAE0
    if (ctx->r1 != 0) {
        // 0x8008AB3C: sw          $t7, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r15;
            goto L_8008AAE0;
    }
    // 0x8008AB3C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_8008AB40:
    // 0x8008AB40: b           L_8008ABA4
    // 0x8008AB44: nop

        goto L_8008ABA4;
    // 0x8008AB44: nop

L_8008AB48:
    // 0x8008AB48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB4C: jal         0x80099E2C
    // 0x8008AB50: nop

    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x8008AB50: nop

    after_1:
    // 0x8008AB54: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB58: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8008AB5C: sw          $t1, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r9;
    // 0x8008AB60: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB64: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8008AB68: sh          $t4, 0x116($t5)
    MEM_H(0X116, ctx->r13) = ctx->r12;
    // 0x8008AB6C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB70: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8008AB74: sh          $t3, 0x114($t6)
    MEM_H(0X114, ctx->r14) = ctx->r11;
    // 0x8008AB78: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB7C: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8008AB80: sw          $t8, 0xC8($t9)
    MEM_W(0XC8, ctx->r25) = ctx->r24;
    // 0x8008AB84: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB88: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8008AB8C: sh          $t7, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r15;
    // 0x8008AB90: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB94: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8008AB98: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x8008AB9C: b           L_8008ABA4
    // 0x8008ABA0: nop

        goto L_8008ABA4;
    // 0x8008ABA0: nop

L_8008ABA4:
    // 0x8008ABA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008ABA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008ABAC: jr          $ra
    // 0x8008ABB0: nop

    return;
    // 0x8008ABB0: nop

;}
RECOMP_FUNC void func_8008ABB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ABB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008ABB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008ABBC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008ABC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008ABC4: lui         $t6, 0x809A
    ctx->r14 = S32(0X809A << 16);
    // 0x8008ABC8: lui         $t7, 0x809A
    ctx->r15 = S32(0X809A << 16);
    // 0x8008ABCC: addiu       $t7, $t7, -0x6FD8
    ctx->r15 = ADD32(ctx->r15, -0X6FD8);
    // 0x8008ABD0: addiu       $t6, $t6, -0x6F10
    ctx->r14 = ADD32(ctx->r14, -0X6F10);
    // 0x8008ABD4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8008ABD8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008ABDC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008ABE0: jal         0x800BC6EC
    // 0x8008ABE4: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008ABE4: nop

    after_0:
    // 0x8008ABE8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008ABEC: nop

    // 0x8008ABF0: sw          $v0, 0x72C($t9)
    MEM_W(0X72C, ctx->r25) = ctx->r2;
    // 0x8008ABF4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008ABF8: jal         0x800BC6EC
    // 0x8008ABFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8008ABFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8008AC00: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008AC04: nop

    // 0x8008AC08: sw          $v0, 0x734($t0)
    MEM_W(0X734, ctx->r8) = ctx->r2;
    // 0x8008AC0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008AC10: jal         0x800BC6EC
    // 0x8008AC14: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8008AC14: nop

    after_2:
    // 0x8008AC18: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8008AC1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008AC20: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008AC24: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008AC28: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008AC2C: lui         $a2, 0x809A
    ctx->r6 = S32(0X809A << 16);
    // 0x8008AC30: jal         0x800BD1FC
    // 0x8008AC34: addiu       $a2, $a2, -0x6FD8
    ctx->r6 = ADD32(ctx->r6, -0X6FD8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8008AC34: addiu       $a2, $a2, -0x6FD8
    ctx->r6 = ADD32(ctx->r6, -0X6FD8);
    after_3:
    // 0x8008AC38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008AC3C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AC40: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8008AC44: jal         0x800BD218
    // 0x8008AC48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x8008AC48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008AC4C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AC50: nop

    // 0x8008AC54: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8008AC58: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008AC5C: nop

    // 0x8008AC60: lw          $t3, 0x72C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X72C);
    // 0x8008AC64: nop

    // 0x8008AC68: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8008AC6C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008AC70: nop

    // 0x8008AC74: lw          $t5, 0x734($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X734);
    // 0x8008AC78: nop

    // 0x8008AC7C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8008AC80:
    // 0x8008AC80: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008AC84: nop

    // 0x8008AC88: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008AC8C: nop

    // 0x8008AC90: bne         $t7, $zero, L_8008ACA0
    if (ctx->r15 != 0) {
        // 0x8008AC94: nop

            goto L_8008ACA0;
    }
    // 0x8008AC94: nop

    // 0x8008AC98: b           L_8008AD58
    // 0x8008AC9C: nop

        goto L_8008AD58;
    // 0x8008AC9C: nop

L_8008ACA0:
    // 0x8008ACA0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008ACA4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008ACA8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008ACAC: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008ACB0: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008ACB4: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x8008ACB8: jal         0x800BD1FC
    // 0x8008ACBC: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8008ACBC: nop

    after_5:
    // 0x8008ACC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008ACC4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008ACC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008ACCC: jal         0x800BD218
    // 0x8008ACD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_6;
    // 0x8008ACD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x8008ACD4: jal         0x800BC6EC
    // 0x8008ACD8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x8008ACD8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_7:
    // 0x8008ACDC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008ACE0: nop

    // 0x8008ACE4: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8008ACE8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008ACEC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008ACF0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008ACF4: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008ACF8: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008ACFC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8008AD00: jal         0x800BD1FC
    // 0x8008AD04: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_8;
    // 0x8008AD04: nop

    after_8:
    // 0x8008AD08: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8008AD0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008AD10: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8008AD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AD18: jal         0x800BD218
    // 0x8008AD1C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    SysMem_DmaCopy(rdram, ctx);
        goto after_9;
    // 0x8008AD1C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_9:
    // 0x8008AD20: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008AD24: nop

    // 0x8008AD28: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8008AD2C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8008AD30: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AD34: nop

    // 0x8008AD38: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x8008AD3C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8008AD40: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008AD44: nop

    // 0x8008AD48: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8008AD4C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008AD50: b           L_8008AC80
    // 0x8008AD54: nop

        goto L_8008AC80;
    // 0x8008AD54: nop

L_8008AD58:
    // 0x8008AD58: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8008AD5C: nop

    // 0x8008AD60: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8008AD64: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AD68: jal         0x800BC980
    // 0x8008AD6C: nop

    SysMem_Free(rdram, ctx);
        goto after_10;
    // 0x8008AD6C: nop

    after_10:
    // 0x8008AD70: b           L_8008AD78
    // 0x8008AD74: nop

        goto L_8008AD78;
    // 0x8008AD74: nop

L_8008AD78:
    // 0x8008AD78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AD7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AD80: jr          $ra
    // 0x8008AD84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008AD84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8008AD88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AD88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008AD8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AD90: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008AD94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008AD98: lui         $t6, 0x809A
    ctx->r14 = S32(0X809A << 16);
    // 0x8008AD9C: lui         $t7, 0x809A
    ctx->r15 = S32(0X809A << 16);
    // 0x8008ADA0: addiu       $t7, $t7, -0x6940
    ctx->r15 = ADD32(ctx->r15, -0X6940);
    // 0x8008ADA4: addiu       $t6, $t6, -0x6914
    ctx->r14 = ADD32(ctx->r14, -0X6914);
    // 0x8008ADA8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8008ADAC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8008ADB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008ADB4: jal         0x800BC6EC
    // 0x8008ADB8: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8008ADB8: nop

    after_0:
    // 0x8008ADBC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008ADC0: nop

    // 0x8008ADC4: sw          $v0, 0x730($t9)
    MEM_W(0X730, ctx->r25) = ctx->r2;
    // 0x8008ADC8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008ADCC: jal         0x800BC6EC
    // 0x8008ADD0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8008ADD0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8008ADD4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008ADD8: nop

    // 0x8008ADDC: sw          $v0, 0x738($t0)
    MEM_W(0X738, ctx->r8) = ctx->r2;
    // 0x8008ADE0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008ADE4: jal         0x800BC6EC
    // 0x8008ADE8: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8008ADE8: nop

    after_2:
    // 0x8008ADEC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8008ADF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008ADF4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008ADF8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008ADFC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008AE00: lui         $a2, 0x809A
    ctx->r6 = S32(0X809A << 16);
    // 0x8008AE04: jal         0x800BD1FC
    // 0x8008AE08: addiu       $a2, $a2, -0x6940
    ctx->r6 = ADD32(ctx->r6, -0X6940);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x8008AE08: addiu       $a2, $a2, -0x6940
    ctx->r6 = ADD32(ctx->r6, -0X6940);
    after_3:
    // 0x8008AE0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008AE10: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AE14: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8008AE18: jal         0x800BD218
    // 0x8008AE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x8008AE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008AE20: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AE24: nop

    // 0x8008AE28: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8008AE2C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008AE30: nop

    // 0x8008AE34: lw          $t3, 0x730($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X730);
    // 0x8008AE38: nop

    // 0x8008AE3C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8008AE40: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008AE44: nop

    // 0x8008AE48: lw          $t5, 0x738($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X738);
    // 0x8008AE4C: nop

    // 0x8008AE50: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8008AE54:
    // 0x8008AE54: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008AE58: nop

    // 0x8008AE5C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008AE60: nop

    // 0x8008AE64: bne         $t7, $zero, L_8008AE74
    if (ctx->r15 != 0) {
        // 0x8008AE68: nop

            goto L_8008AE74;
    }
    // 0x8008AE68: nop

    // 0x8008AE6C: b           L_8008AF2C
    // 0x8008AE70: nop

        goto L_8008AF2C;
    // 0x8008AE70: nop

L_8008AE74:
    // 0x8008AE74: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008AE78: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008AE7C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008AE80: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008AE84: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008AE88: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x8008AE8C: jal         0x800BD1FC
    // 0x8008AE90: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8008AE90: nop

    after_5:
    // 0x8008AE94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008AE98: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AE9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AEA0: jal         0x800BD218
    // 0x8008AEA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_6;
    // 0x8008AEA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x8008AEA8: jal         0x800BC6EC
    // 0x8008AEAC: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x8008AEAC: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_7:
    // 0x8008AEB0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008AEB4: nop

    // 0x8008AEB8: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8008AEBC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AEC0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008AEC4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008AEC8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8008AECC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8008AED0: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8008AED4: jal         0x800BD1FC
    // 0x8008AED8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_8;
    // 0x8008AED8: nop

    after_8:
    // 0x8008AEDC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8008AEE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008AEE4: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8008AEE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AEEC: jal         0x800BD218
    // 0x8008AEF0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    SysMem_DmaCopy(rdram, ctx);
        goto after_9;
    // 0x8008AEF0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_9:
    // 0x8008AEF4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008AEF8: nop

    // 0x8008AEFC: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8008AF00: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8008AF04: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AF08: nop

    // 0x8008AF0C: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x8008AF10: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8008AF14: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008AF18: nop

    // 0x8008AF1C: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8008AF20: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008AF24: b           L_8008AE54
    // 0x8008AF28: nop

        goto L_8008AE54;
    // 0x8008AF28: nop

L_8008AF2C:
    // 0x8008AF2C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8008AF30: nop

    // 0x8008AF34: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8008AF38: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AF3C: jal         0x800BC980
    // 0x8008AF40: nop

    SysMem_Free(rdram, ctx);
        goto after_10;
    // 0x8008AF40: nop

    after_10:
    // 0x8008AF44: b           L_8008AF4C
    // 0x8008AF48: nop

        goto L_8008AF4C;
    // 0x8008AF48: nop

L_8008AF4C:
    // 0x8008AF4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AF50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AF54: jr          $ra
    // 0x8008AF58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008AF58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8008AF5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AF5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008AF60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008AF64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008AF68: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008AF6C: nop

    // 0x8008AF70: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008AF74: nop

    // 0x8008AF78: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x8008AF7C: bne         $t8, $zero, L_8008AFE4
    if (ctx->r24 != 0) {
        // 0x8008AF80: nop

            goto L_8008AFE4;
    }
    // 0x8008AF80: nop

    // 0x8008AF84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AF88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008AF8C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008AF90: lui         $at, 0xC254
    ctx->r1 = S32(0XC254 << 16);
    // 0x8008AF94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008AF98: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x8008AF9C: ori         $a2, $a2, 0x227
    ctx->r6 = ctx->r6 | 0X227;
    // 0x8008AFA0: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8008AFA4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008AFA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8008AFAC: addiu       $a0, $t9, 0x24
    ctx->r4 = ADD32(ctx->r25, 0X24);
    // 0x8008AFB0: addiu       $a1, $t9, 0x28
    ctx->r5 = ADD32(ctx->r25, 0X28);
    // 0x8008AFB4: jal         0x800B202C
    // 0x8008AFB8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_0;
    // 0x8008AFB8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8008AFBC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008AFC0: nop

    // 0x8008AFC4: sh          $v0, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r2;
    // 0x8008AFC8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8008AFCC: nop

    // 0x8008AFD0: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8008AFD4: nop

    // 0x8008AFD8: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8008AFDC: b           L_8008B004
    // 0x8008AFE0: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
        goto L_8008B004;
    // 0x8008AFE0: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_8008AFE4:
    // 0x8008AFE4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008AFE8: nop

    // 0x8008AFEC: addiu       $a0, $t4, 0x24
    ctx->r4 = ADD32(ctx->r12, 0X24);
    // 0x8008AFF0: jal         0x800B2748
    // 0x8008AFF4: addiu       $a1, $t4, 0x28
    ctx->r5 = ADD32(ctx->r12, 0X28);
    func_800B2748(rdram, ctx);
        goto after_1;
    // 0x8008AFF4: addiu       $a1, $t4, 0x28
    ctx->r5 = ADD32(ctx->r12, 0X28);
    after_1:
    // 0x8008AFF8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8008AFFC: nop

    // 0x8008B000: sh          $v0, 0x2E($t5)
    MEM_H(0X2E, ctx->r13) = ctx->r2;
L_8008B004:
    // 0x8008B004: jal         0x80031AC8
    // 0x8008B008: nop

    func_80031AC8(rdram, ctx);
        goto after_2;
    // 0x8008B008: nop

    after_2:
    // 0x8008B00C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B010: bne         $v0, $at, L_8008B0BC
    if (ctx->r2 != ctx->r1) {
        // 0x8008B014: nop

            goto L_8008B0BC;
    }
    // 0x8008B014: nop

    // 0x8008B018: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008B01C: nop

    // 0x8008B020: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008B024: nop

    // 0x8008B028: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8008B02C: bne         $t8, $zero, L_8008B094
    if (ctx->r24 != 0) {
        // 0x8008B030: nop

            goto L_8008B094;
    }
    // 0x8008B030: nop

    // 0x8008B034: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008B03C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008B040: lui         $at, 0xC254
    ctx->r1 = S32(0XC254 << 16);
    // 0x8008B044: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008B048: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x8008B04C: ori         $a2, $a2, 0x228
    ctx->r6 = ctx->r6 | 0X228;
    // 0x8008B050: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8008B054: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008B058: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8008B05C: addiu       $a0, $t9, 0x30
    ctx->r4 = ADD32(ctx->r25, 0X30);
    // 0x8008B060: addiu       $a1, $t9, 0x34
    ctx->r5 = ADD32(ctx->r25, 0X34);
    // 0x8008B064: jal         0x800B202C
    // 0x8008B068: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B202C(rdram, ctx);
        goto after_3;
    // 0x8008B068: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8008B06C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008B070: nop

    // 0x8008B074: sh          $v0, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r2;
    // 0x8008B078: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008B07C: nop

    // 0x8008B080: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8008B084: nop

    // 0x8008B088: ori         $t1, $t3, 0x10
    ctx->r9 = ctx->r11 | 0X10;
    // 0x8008B08C: b           L_8008B0B4
    // 0x8008B090: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
        goto L_8008B0B4;
    // 0x8008B090: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
L_8008B094:
    // 0x8008B094: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008B098: nop

    // 0x8008B09C: addiu       $a0, $t4, 0x30
    ctx->r4 = ADD32(ctx->r12, 0X30);
    // 0x8008B0A0: jal         0x800B2748
    // 0x8008B0A4: addiu       $a1, $t4, 0x34
    ctx->r5 = ADD32(ctx->r12, 0X34);
    func_800B2748(rdram, ctx);
        goto after_4;
    // 0x8008B0A4: addiu       $a1, $t4, 0x34
    ctx->r5 = ADD32(ctx->r12, 0X34);
    after_4:
    // 0x8008B0A8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8008B0AC: nop

    // 0x8008B0B0: sh          $v0, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r2;
L_8008B0B4:
    // 0x8008B0B4: b           L_8008B0F0
    // 0x8008B0B8: nop

        goto L_8008B0F0;
    // 0x8008B0B8: nop

L_8008B0BC:
    // 0x8008B0BC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008B0C0: nop

    // 0x8008B0C4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008B0C8: nop

    // 0x8008B0CC: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8008B0D0: beq         $t8, $zero, L_8008B0F0
    if (ctx->r24 == 0) {
        // 0x8008B0D4: nop

            goto L_8008B0F0;
    }
    // 0x8008B0D4: nop

    // 0x8008B0D8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008B0DC: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8008B0E0: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8008B0E4: nop

    // 0x8008B0E8: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8008B0EC: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
L_8008B0F0:
    // 0x8008B0F0: b           L_8008B0F8
    // 0x8008B0F4: nop

        goto L_8008B0F8;
    // 0x8008B0F4: nop

L_8008B0F8:
    // 0x8008B0F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008B0FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008B100: jr          $ra
    // 0x8008B104: nop

    return;
    // 0x8008B104: nop

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
RECOMP_FUNC void func_8008B18C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B18C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008B198: jal         0x800C1754
    // 0x8008B19C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8008B19C: nop

    after_0:
    // 0x8008B1A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1A4: jal         0x8009A14C
    // 0x8008B1A8: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x8008B1A8: nop

    after_1:
    // 0x8008B1AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1B0: jal         0x800997D8
    // 0x8008B1B4: nop

    func_800997D8(rdram, ctx);
        goto after_2;
    // 0x8008B1B4: nop

    after_2:
    // 0x8008B1B8: jal         0x800C1A28
    // 0x8008B1BC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x8008B1BC: nop

    after_3:
    // 0x8008B1C0: b           L_8008B1C8
    // 0x8008B1C4: nop

        goto L_8008B1C8;
    // 0x8008B1C4: nop

L_8008B1C8:
    // 0x8008B1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B1CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B1D0: jr          $ra
    // 0x8008B1D4: nop

    return;
    // 0x8008B1D4: nop

;}
RECOMP_FUNC void func_8008B1D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B1DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B1E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008B1E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008B1E8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008B1F0: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008B1F4: lwc1        $f4, 0xC28($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC28);
    // 0x8008B1F8: lwc1        $f10, 0xC24($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC24);
    // 0x8008B1FC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008B200: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8008B204: swc1        $f16, 0xC24($t6)
    MEM_W(0XC24, ctx->r14) = ctx->f16.u32l;
    // 0x8008B208: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008B20C: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8008B210: lwc1        $f18, 0xC24($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC24);
    // 0x8008B214: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008B218: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008B21C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8008B220: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8008B224: nop

    // 0x8008B228: bc1f        L_8008B25C
    if (!c1cs) {
        // 0x8008B22C: nop

            goto L_8008B25C;
    }
    // 0x8008B22C: nop

    // 0x8008B230: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8008B234: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008B238: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008B23C: nop

    // 0x8008B240: swc1        $f10, 0xC24($t8)
    MEM_W(0XC24, ctx->r24) = ctx->f10.u32l;
    // 0x8008B244: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008B248: nop

    // 0x8008B24C: lwc1        $f8, 0xC28($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC28);
    // 0x8008B250: nop

    // 0x8008B254: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8008B258: swc1        $f16, 0xC28($t9)
    MEM_W(0XC28, ctx->r25) = ctx->f16.u32l;
L_8008B25C:
    // 0x8008B25C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008B260: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8008B264: lwc1        $f18, 0xC24($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XC24);
    // 0x8008B268: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008B26C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8008B270: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8008B274: nop

    // 0x8008B278: bc1f        L_8008B2A8
    if (!c1cs) {
        // 0x8008B27C: nop

            goto L_8008B2A8;
    }
    // 0x8008B27C: nop

    // 0x8008B280: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008B284: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008B288: nop

    // 0x8008B28C: swc1        $f10, 0xC24($t1)
    MEM_W(0XC24, ctx->r9) = ctx->f10.u32l;
    // 0x8008B290: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008B294: nop

    // 0x8008B298: lwc1        $f8, 0xC28($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC28);
    // 0x8008B29C: nop

    // 0x8008B2A0: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8008B2A4: swc1        $f16, 0xC28($t2)
    MEM_W(0XC28, ctx->r10) = ctx->f16.u32l;
L_8008B2A8:
    // 0x8008B2A8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8008B2AC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8008B2B0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8008B2B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008B2B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008B2BC: lwc1        $f18, 0xC24($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC24);
    // 0x8008B2C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B2C4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8008B2C8: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8008B2CC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8008B2D0: sh          $t5, 0x11E($t6)
    MEM_H(0X11E, ctx->r14) = ctx->r13;
    // 0x8008B2D4: nop

    // 0x8008B2D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B2DC: jal         0x8008B18C
    // 0x8008B2E0: nop

    func_8008B18C(rdram, ctx);
        goto after_0;
    // 0x8008B2E0: nop

    after_0:
    // 0x8008B2E4: b           L_8008B2EC
    // 0x8008B2E8: nop

        goto L_8008B2EC;
    // 0x8008B2E8: nop

L_8008B2EC:
    // 0x8008B2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B2F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B2F4: jr          $ra
    // 0x8008B2F8: nop

    return;
    // 0x8008B2F8: nop

;}
RECOMP_FUNC void func_8008B2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2FC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008B300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B304: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8008B308: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8008B30C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8008B310: lhu         $t6, 0x5E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X5E);
    // 0x8008B314: nop

    // 0x8008B318: slti        $at, $t6, 0x4000
    ctx->r1 = SIGNED(ctx->r14) < 0X4000 ? 1 : 0;
    // 0x8008B31C: bne         $at, $zero, L_8008B33C
    if (ctx->r1 != 0) {
        // 0x8008B320: nop

            goto L_8008B33C;
    }
    // 0x8008B320: nop

    // 0x8008B324: jal         0x80090754
    // 0x8008B328: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090754(rdram, ctx);
        goto after_0;
    // 0x8008B328: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x8008B32C: jal         0x80090728
    // 0x8008B330: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090728(rdram, ctx);
        goto after_1;
    // 0x8008B330: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x8008B334: b           L_8008B34C
    // 0x8008B338: nop

        goto L_8008B34C;
    // 0x8008B338: nop

L_8008B33C:
    // 0x8008B33C: jal         0x80090754
    // 0x8008B340: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090754(rdram, ctx);
        goto after_2;
    // 0x8008B340: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x8008B344: jal         0x80090728
    // 0x8008B348: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090728(rdram, ctx);
        goto after_3;
    // 0x8008B348: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_3:
L_8008B34C:
    // 0x8008B34C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8008B350: lhu         $a2, 0x5E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X5E);
    // 0x8008B354: jal         0x8008B388
    // 0x8008B358: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008B388(rdram, ctx);
        goto after_4;
    // 0x8008B358: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8008B35C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B360: lhu         $a1, 0x62($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X62);
    // 0x8008B364: addiu       $a0, $a0, -0xAB8
    ctx->r4 = ADD32(ctx->r4, -0XAB8);
    // 0x8008B368: jal         0x8008ECE4
    // 0x8008B36C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8008B36C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x8008B370: b           L_8008B378
    // 0x8008B374: nop

        goto L_8008B378;
    // 0x8008B374: nop

L_8008B378:
    // 0x8008B378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B37C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8008B380: jr          $ra
    // 0x8008B384: nop

    return;
    // 0x8008B384: nop

;}
RECOMP_FUNC void func_8008B388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B38C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B390: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B394: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008B398: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008B39C: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x8008B3A0: nop

    // 0x8008B3A4: slti        $at, $t6, 0x4000
    ctx->r1 = SIGNED(ctx->r14) < 0X4000 ? 1 : 0;
    // 0x8008B3A8: bne         $at, $zero, L_8008B3EC
    if (ctx->r1 != 0) {
        // 0x8008B3AC: nop

            goto L_8008B3EC;
    }
    // 0x8008B3AC: nop

    // 0x8008B3B0: lhu         $t7, 0x2A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2A);
    // 0x8008B3B4: nop

    // 0x8008B3B8: addiu       $t8, $t7, -0x4000
    ctx->r24 = ADD32(ctx->r15, -0X4000);
    // 0x8008B3BC: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
    // 0x8008B3C0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008B3C4: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x8008B3C8: lw          $t0, 0x738($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X738);
    // 0x8008B3CC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008B3D0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8008B3D4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x8008B3D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008B3DC: jal         0x800BCFCC
    // 0x8008B3E0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x8008B3E0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_0:
    // 0x8008B3E4: b           L_8008B410
    // 0x8008B3E8: nop

        goto L_8008B410;
    // 0x8008B3E8: nop

L_8008B3EC:
    // 0x8008B3EC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8008B3F0: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x8008B3F4: lw          $t5, 0x734($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X734);
    // 0x8008B3F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008B3FC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8008B400: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8008B404: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008B408: jal         0x800BCFCC
    // 0x8008B40C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x8008B40C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_1:
L_8008B410:
    // 0x8008B410: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008B414: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008B418: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008B41C:
    // 0x8008B41C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B420: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008B424: lbu         $t0, 0x0($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X0);
    // 0x8008B428: nop

    // 0x8008B42C: beq         $t0, $at, L_8008B43C
    if (ctx->r8 == ctx->r1) {
        // 0x8008B430: nop

            goto L_8008B43C;
    }
    // 0x8008B430: nop

    // 0x8008B434: bne         $t0, $zero, L_8008B444
    if (ctx->r8 != 0) {
        // 0x8008B438: nop

            goto L_8008B444;
    }
    // 0x8008B438: nop

L_8008B43C:
    // 0x8008B43C: b           L_8008B464
    // 0x8008B440: nop

        goto L_8008B464;
    // 0x8008B440: nop

L_8008B444:
    // 0x8008B444: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008B448: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B44C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008B450: slti        $at, $t3, 0x30
    ctx->r1 = SIGNED(ctx->r11) < 0X30 ? 1 : 0;
    // 0x8008B454: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8008B458: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8008B45C: bne         $at, $zero, L_8008B41C
    if (ctx->r1 != 0) {
        // 0x8008B460: sw          $t3, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r11;
            goto L_8008B41C;
    }
    // 0x8008B460: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_8008B464:
    // 0x8008B464: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B468: nop

    // 0x8008B46C: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x8008B470: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8008B474: b           L_8008B484
    // 0x8008B478: nop

        goto L_8008B484;
    // 0x8008B478: nop

    // 0x8008B47C: b           L_8008B484
    // 0x8008B480: nop

        goto L_8008B484;
    // 0x8008B480: nop

L_8008B484:
    // 0x8008B484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B48C: jr          $ra
    // 0x8008B490: nop

    return;
    // 0x8008B490: nop

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
RECOMP_FUNC void func_8008B4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B4EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B4F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B4F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B4F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B4FC: addiu       $t6, $t6, 0x4720
    ctx->r14 = ADD32(ctx->r14, 0X4720);
    // 0x8008B500: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8008B504: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8008B508: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B50C: beq         $t7, $at, L_8008B5E8
    if (ctx->r15 == ctx->r1) {
        // 0x8008B510: nop

            goto L_8008B5E8;
    }
    // 0x8008B510: nop

L_8008B514:
    // 0x8008B514: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B518: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8008B51C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008B520: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008B524: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008B528: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008B52C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8008B530: lh          $t0, 0x4720($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X4720);
    // 0x8008B534: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x8008B538: nop

    // 0x8008B53C: bne         $t0, $t2, L_8008B5BC
    if (ctx->r8 != ctx->r10) {
        // 0x8008B540: nop

            goto L_8008B5BC;
    }
    // 0x8008B540: nop

    // 0x8008B544: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B548: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008B54C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8008B550: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008B554: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008B558: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8008B55C: lh          $t5, 0x4722($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X4722);
    // 0x8008B560: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B564: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x8008B568: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B56C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008B570: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008B574: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008B578: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008B57C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008B580: lh          $t8, 0x4724($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X4724);
    // 0x8008B584: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B588: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x8008B58C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B590: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008B594: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8008B598: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8008B59C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008B5A0: addiu       $t0, $t0, 0x4720
    ctx->r8 = ADD32(ctx->r8, 0X4720);
    // 0x8008B5A4: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8008B5A8: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
    // 0x8008B5AC: lh          $a2, 0x8($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X8);
    // 0x8008B5B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008B5B4: jal         0x8008B2FC
    // 0x8008B5B8: nop

    func_8008B2FC(rdram, ctx);
        goto after_0;
    // 0x8008B5B8: nop

    after_0:
L_8008B5BC:
    // 0x8008B5BC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B5C0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B5C4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008B5C8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008B5CC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008B5D0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B5D4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008B5D8: lh          $t6, 0x4720($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X4720);
    // 0x8008B5DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008B5E0: bne         $t6, $at, L_8008B514
    if (ctx->r14 != ctx->r1) {
        // 0x8008B5E4: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_8008B514;
    }
    // 0x8008B5E4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
L_8008B5E8:
    // 0x8008B5E8: b           L_8008B5F0
    // 0x8008B5EC: nop

        goto L_8008B5F0;
    // 0x8008B5EC: nop

L_8008B5F0:
    // 0x8008B5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B5F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B5F8: jr          $ra
    // 0x8008B5FC: nop

    return;
    // 0x8008B5FC: nop

;}
RECOMP_FUNC void func_8008B600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B600: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008B604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B608: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008B60C: jal         0x80090754
    // 0x8008B610: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090754(rdram, ctx);
        goto after_0;
    // 0x8008B610: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8008B614: jal         0x80090728
    // 0x8008B618: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090728(rdram, ctx);
        goto after_1;
    // 0x8008B618: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x8008B61C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B620: addiu       $a0, $a0, -0xAB0
    ctx->r4 = ADD32(ctx->r4, -0XAB0);
    // 0x8008B624: jal         0x8008ECE4
    // 0x8008B628: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8008B628: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x8008B62C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8008B630: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8008B634: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008B638: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x8008B63C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8008B640: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8008B644:
    // 0x8008B644: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008B648: nop

    // 0x8008B64C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8008B650: nop

    // 0x8008B654: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x8008B658: beq         $t0, $zero, L_8008B6F0
    if (ctx->r8 == 0) {
        // 0x8008B65C: nop

            goto L_8008B6F0;
    }
    // 0x8008B65C: nop

    // 0x8008B660: andi        $t1, $t9, 0x4000
    ctx->r9 = ctx->r25 & 0X4000;
    // 0x8008B664: beq         $t1, $zero, L_8008B6F0
    if (ctx->r9 == 0) {
        // 0x8008B668: nop

            goto L_8008B6F0;
    }
    // 0x8008B668: nop

    // 0x8008B66C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008B670: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B674: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x8008B678: addiu       $t3, $zero, 0x22
    ctx->r11 = ADD32(0, 0X22);
    // 0x8008B67C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B680: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x8008B684: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008B688: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8008B68C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8008B690: jal         0x8008BE0C
    // 0x8008B694: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    func_8008BE0C(rdram, ctx);
        goto after_3;
    // 0x8008B694: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_3:
    // 0x8008B698: jal         0x8008ECE4
    // 0x8008B69C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8008B69C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x8008B6A0: addiu       $t4, $zero, 0x6E
    ctx->r12 = ADD32(0, 0X6E);
    // 0x8008B6A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B6A8: sw          $t4, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r12;
    // 0x8008B6AC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8008B6B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B6B4: lhu         $a1, 0x10($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X10);
    // 0x8008B6B8: jal         0x8008ECE4
    // 0x8008B6BC: addiu       $a0, $a0, -0xAAC
    ctx->r4 = ADD32(ctx->r4, -0XAAC);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8008B6BC: addiu       $a0, $a0, -0xAAC
    ctx->r4 = ADD32(ctx->r4, -0XAAC);
    after_5:
    // 0x8008B6C0: addiu       $t6, $zero, 0x76
    ctx->r14 = ADD32(0, 0X76);
    // 0x8008B6C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B6C8: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x8008B6CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008B6D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B6D4: addiu       $t8, $t7, 0xF
    ctx->r24 = ADD32(ctx->r15, 0XF);
    // 0x8008B6D8: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x8008B6DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8008B6E0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B6E4: lbu         $a1, 0x12($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X12);
    // 0x8008B6E8: jal         0x8008ECE4
    // 0x8008B6EC: addiu       $a0, $a0, -0xAA8
    ctx->r4 = ADD32(ctx->r4, -0XAA8);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8008B6EC: addiu       $a0, $a0, -0xAA8
    ctx->r4 = ADD32(ctx->r4, -0XAA8);
    after_6:
L_8008B6F0:
    // 0x8008B6F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008B6F4: nop

    // 0x8008B6F8: addiu       $t1, $t9, 0x30
    ctx->r9 = ADD32(ctx->r25, 0X30);
    // 0x8008B6FC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8008B700: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B704: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8008B708: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008B70C: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x8008B710: addiu       $t5, $t4, 0x16
    ctx->r13 = ADD32(ctx->r12, 0X16);
    // 0x8008B714: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8008B718: bne         $at, $zero, L_8008B644
    if (ctx->r1 != 0) {
        // 0x8008B71C: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8008B644;
    }
    // 0x8008B71C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8008B720: b           L_8008B728
    // 0x8008B724: nop

        goto L_8008B728;
    // 0x8008B724: nop

L_8008B728:
    // 0x8008B728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B72C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008B730: jr          $ra
    // 0x8008B734: nop

    return;
    // 0x8008B734: nop

;}
RECOMP_FUNC void func_8008B738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B738: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008B73C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B740: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8008B744: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8008B748: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8008B74C: jal         0x80090754
    // 0x8008B750: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090754(rdram, ctx);
        goto after_0;
    // 0x8008B750: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8008B754: jal         0x80090728
    // 0x8008B758: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090728(rdram, ctx);
        goto after_1;
    // 0x8008B758: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x8008B75C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B760: nop

    // 0x8008B764: beq         $t6, $zero, L_8008B794
    if (ctx->r14 == 0) {
        // 0x8008B768: nop

            goto L_8008B794;
    }
    // 0x8008B768: nop

    // 0x8008B76C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B770: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8008B774: jal         0x8008BE0C
    // 0x8008B778: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8008BE0C(rdram, ctx);
        goto after_2;
    // 0x8008B778: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_2:
    // 0x8008B77C: bgez        $v0, L_8008B78C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008B780: sra         $t7, $v0, 1
        ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8008B78C;
    }
    // 0x8008B780: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008B784: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8008B788: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8008B78C:
    // 0x8008B78C: b           L_8008B798
    // 0x8008B790: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_8008B798;
    // 0x8008B790: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8008B794:
    // 0x8008B794: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008B798:
    // 0x8008B798: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B79C: nop

    // 0x8008B7A0: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x8008B7A4: beq         $at, $zero, L_8008B7E4
    if (ctx->r1 == 0) {
        // 0x8008B7A8: sw          $t8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r24;
            goto L_8008B7E4;
    }
    // 0x8008B7A8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_8008B7AC:
    // 0x8008B7AC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008B7B0: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x8008B7B4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008B7B8: sll         $t0, $t9, 0
    ctx->r8 = S32(ctx->r25 << 0);
    // 0x8008B7BC: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x8008B7C0: addiu       $a1, $a1, -0xAA4
    ctx->r5 = ADD32(ctx->r5, -0XAA4);
    // 0x8008B7C4: jal         0x800BCFCC
    // 0x8008B7C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x8008B7C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8008B7CC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008B7D0: nop

    // 0x8008B7D4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008B7D8: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x8008B7DC: bne         $at, $zero, L_8008B7AC
    if (ctx->r1 != 0) {
        // 0x8008B7E0: sw          $t3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r11;
            goto L_8008B7AC;
    }
    // 0x8008B7E0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
L_8008B7E4:
    // 0x8008B7E4: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x8008B7E8: sb          $zero, 0x7($t4)
    MEM_B(0X7, ctx->r12) = 0;
    // 0x8008B7EC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B7F0: addiu       $a0, $a0, -0xAA0
    ctx->r4 = ADD32(ctx->r4, -0XAA0);
    // 0x8008B7F4: jal         0x8008ECE4
    // 0x8008B7F8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8008B7F8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_4:
    // 0x8008B7FC: addiu       $t5, $zero, 0xBB
    ctx->r13 = ADD32(0, 0XBB);
    // 0x8008B800: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B804: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x8008B808: addiu       $t6, $zero, 0x82
    ctx->r14 = ADD32(0, 0X82);
    // 0x8008B80C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B810: sw          $t6, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r14;
    // 0x8008B814: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x8008B818: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8008B81C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8008B820: nop

    // 0x8008B824: beq         $t8, $zero, L_8008B880
    if (ctx->r24 == 0) {
        // 0x8008B828: nop

            goto L_8008B880;
    }
    // 0x8008B828: nop

L_8008B82C:
    // 0x8008B82C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008B830: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8008B834: jal         0x800BCFCC
    // 0x8008B838: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x8008B838: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8008B83C: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x8008B840: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
    // 0x8008B844: jal         0x8008ECE4
    // 0x8008B848: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8008B848: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x8008B84C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8008B850: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x8008B854: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B858: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008B85C: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8008B860: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008B864: nop

    // 0x8008B868: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008B86C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8008B870: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8008B874: nop

    // 0x8008B878: bne         $t4, $zero, L_8008B82C
    if (ctx->r12 != 0) {
        // 0x8008B87C: nop

            goto L_8008B82C;
    }
    // 0x8008B87C: nop

L_8008B880:
    // 0x8008B880: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008B884: nop

    // 0x8008B888: bne         $t5, $zero, L_8008B8C0
    if (ctx->r13 != 0) {
        // 0x8008B88C: nop

            goto L_8008B8C0;
    }
    // 0x8008B88C: nop

    // 0x8008B890: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008B894: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008B898: nop

    // 0x8008B89C: swc1        $f4, 0xBD4($t6)
    MEM_W(0XBD4, ctx->r14) = ctx->f4.u32l;
    // 0x8008B8A0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008B8A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008B8A8: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x8008B8AC: nop

    // 0x8008B8B0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8008B8B4: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x8008B8B8: b           L_8008BA14
    // 0x8008B8BC: nop

        goto L_8008BA14;
    // 0x8008B8BC: nop

L_8008B8C0:
    // 0x8008B8C0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8008B8C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008B8C8: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008B8CC: lwc1        $f6, 0xBD4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XBD4);
    // 0x8008B8D0: nop

    // 0x8008B8D4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008B8D8: swc1        $f10, 0xBD4($t0)
    MEM_W(0XBD4, ctx->r8) = ctx->f10.u32l;
    // 0x8008B8DC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008B8E0: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8008B8E4: lwc1        $f16, 0xBD4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XBD4);
    // 0x8008B8E8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8008B8EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008B8F0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8008B8F4: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8008B8F8: nop

    // 0x8008B8FC: bc1f        L_8008B968
    if (!c1cs) {
        // 0x8008B900: nop

            goto L_8008B968;
    }
    // 0x8008B900: nop

L_8008B904:
    // 0x8008B904: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008B908: nop

    // 0x8008B90C: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x8008B910: nop

    // 0x8008B914: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x8008B918: sh          $t4, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r12;
    // 0x8008B91C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008B920: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8008B924: lwc1        $f6, 0xBD4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XBD4);
    // 0x8008B928: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8008B92C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008B930: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8008B934: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8008B938: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8008B93C: swc1        $f18, 0xBD4($t5)
    MEM_W(0XBD4, ctx->r13) = ctx->f18.u32l;
    // 0x8008B940: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008B944: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x8008B948: lwc1        $f4, 0xBD4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XBD4);
    // 0x8008B94C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008B950: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008B954: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008B958: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8008B95C: nop

    // 0x8008B960: bc1t        L_8008B904
    if (c1cs) {
        // 0x8008B964: nop

            goto L_8008B904;
    }
    // 0x8008B964: nop

L_8008B968:
    // 0x8008B968: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B96C: nop

    // 0x8008B970: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x8008B974: bne         $at, $zero, L_8008B984
    if (ctx->r1 != 0) {
        // 0x8008B978: nop

            goto L_8008B984;
    }
    // 0x8008B978: nop

    // 0x8008B97C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8008B980: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008B984:
    // 0x8008B984: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B988: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B98C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8008B990: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B994: mflo        $t0
    ctx->r8 = lo;
    // 0x8008B998: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8008B99C: addiu       $t1, $t0, 0xBB
    ctx->r9 = ADD32(ctx->r8, 0XBB);
    // 0x8008B9A0: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x8008B9A4: addiu       $t3, $zero, 0x82
    ctx->r11 = ADD32(0, 0X82);
    // 0x8008B9A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008B9AC: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8008B9B0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008B9B4: nop

    // 0x8008B9B8: lhu         $t2, 0x2($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X2);
    // 0x8008B9BC: nop

    // 0x8008B9C0: andi        $t5, $t2, 0x1
    ctx->r13 = ctx->r10 & 0X1;
    // 0x8008B9C4: beq         $t5, $zero, L_8008B9E0
    if (ctx->r13 == 0) {
        // 0x8008B9C8: nop

            goto L_8008B9E0;
    }
    // 0x8008B9C8: nop

    // 0x8008B9CC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B9D0: jal         0x8008ECE4
    // 0x8008B9D4: addiu       $a0, $a0, -0xA9C
    ctx->r4 = ADD32(ctx->r4, -0XA9C);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8008B9D4: addiu       $a0, $a0, -0xA9C
    ctx->r4 = ADD32(ctx->r4, -0XA9C);
    after_7:
    // 0x8008B9D8: b           L_8008BA0C
    // 0x8008B9DC: nop

        goto L_8008BA0C;
    // 0x8008B9DC: nop

L_8008B9E0:
    // 0x8008B9E0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B9E4: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x8008B9E8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8008B9EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8008B9F0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8008B9F4: jal         0x800BCFCC
    // 0x8008B9F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_8;
    // 0x8008B9F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x8008B9FC: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x8008BA00: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
    // 0x8008BA04: jal         0x8008ECE4
    // 0x8008BA08: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8008BA08: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_9:
L_8008BA0C:
    // 0x8008BA0C: b           L_8008BA14
    // 0x8008BA10: nop

        goto L_8008BA14;
    // 0x8008BA10: nop

L_8008BA14:
    // 0x8008BA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BA18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008BA1C: jr          $ra
    // 0x8008BA20: nop

    return;
    // 0x8008BA20: nop

;}
RECOMP_FUNC void func_8008BA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BA24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008BA28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BA2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008BA30: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008BA34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8008BA38: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8008BA3C: lwc1        $f4, 0xBD4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XBD4);
    // 0x8008BA40: nop

    // 0x8008BA44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008BA48: swc1        $f8, 0xBD4($t6)
    MEM_W(0XBD4, ctx->r14) = ctx->f8.u32l;
    // 0x8008BA4C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008BA50: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8008BA54: lwc1        $f10, 0xBD4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XBD4);
    // 0x8008BA58: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008BA5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008BA60: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8008BA64: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8008BA68: nop

    // 0x8008BA6C: bc1f        L_8008BAEC
    if (!c1cs) {
        // 0x8008BA70: nop

            goto L_8008BAEC;
    }
    // 0x8008BA70: nop

L_8008BA74:
    // 0x8008BA74: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8008BA78: nop

    // 0x8008BA7C: lh          $t9, 0xBD8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XBD8);
    // 0x8008BA80: nop

    // 0x8008BA84: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008BA88: bgez        $t0, L_8008BA9C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8008BA8C: andi        $t1, $t0, 0x3
        ctx->r9 = ctx->r8 & 0X3;
            goto L_8008BA9C;
    }
    // 0x8008BA8C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x8008BA90: beq         $t1, $zero, L_8008BA9C
    if (ctx->r9 == 0) {
        // 0x8008BA94: nop

            goto L_8008BA9C;
    }
    // 0x8008BA94: nop

    // 0x8008BA98: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_8008BA9C:
    // 0x8008BA9C: sh          $t1, 0xBD8($t8)
    MEM_H(0XBD8, ctx->r24) = ctx->r9;
    // 0x8008BAA0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008BAA4: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8008BAA8: lwc1        $f4, 0xBD4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XBD4);
    // 0x8008BAAC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008BAB0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008BAB4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008BAB8: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8008BABC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8008BAC0: swc1        $f16, 0xBD4($t2)
    MEM_W(0XBD4, ctx->r10) = ctx->f16.u32l;
    // 0x8008BAC4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8008BAC8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8008BACC: lwc1        $f18, 0xBD4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XBD4);
    // 0x8008BAD0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008BAD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008BAD8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8008BADC: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8008BAE0: nop

    // 0x8008BAE4: bc1t        L_8008BA74
    if (c1cs) {
        // 0x8008BAE8: nop

            goto L_8008BA74;
    }
    // 0x8008BAE8: nop

L_8008BAEC:
    // 0x8008BAEC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008BAF0: addiu       $a0, $a0, -0xA98
    ctx->r4 = ADD32(ctx->r4, -0XA98);
    // 0x8008BAF4: jal         0x8008ECE4
    // 0x8008BAF8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8008BAF8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_0:
    // 0x8008BAFC: addiu       $t4, $zero, 0xBB
    ctx->r12 = ADD32(0, 0XBB);
    // 0x8008BB00: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BB04: sw          $t4, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r12;
    // 0x8008BB08: addiu       $t5, $zero, 0x82
    ctx->r13 = ADD32(0, 0X82);
    // 0x8008BB0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BB10: sw          $t5, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r13;
    // 0x8008BB14: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8008BB18:
    // 0x8008BB18: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008BB1C: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x8008BB20: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008BB24: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008BB28: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x8008BB2C: addiu       $a1, $a1, -0xA94
    ctx->r5 = ADD32(ctx->r5, -0XA94);
    // 0x8008BB30: jal         0x800BCFCC
    // 0x8008BB34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x8008BB34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x8008BB38: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008BB3C: nop

    // 0x8008BB40: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008BB44: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8008BB48: bne         $at, $zero, L_8008BB18
    if (ctx->r1 != 0) {
        // 0x8008BB4C: sw          $t1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r9;
            goto L_8008BB18;
    }
    // 0x8008BB4C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008BB50: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x8008BB54: sb          $zero, 0xA($t8)
    MEM_B(0XA, ctx->r24) = 0;
    // 0x8008BB58: jal         0x8008ECE4
    // 0x8008BB5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8008BB5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8008BB60: addiu       $t2, $zero, 0xBB
    ctx->r10 = ADD32(0, 0XBB);
    // 0x8008BB64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BB68: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x8008BB6C: addiu       $t3, $zero, 0x82
    ctx->r11 = ADD32(0, 0X82);
    // 0x8008BB70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BB74: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8008BB78: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008BB7C: addiu       $a1, $a1, -0xA90
    ctx->r5 = ADD32(ctx->r5, -0XA90);
    // 0x8008BB80: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8008BB84: jal         0x800BCFCC
    // 0x8008BB88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x8008BB88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x8008BB8C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008BB90: addiu       $t4, $sp, 0x1C
    ctx->r12 = ADD32(ctx->r29, 0X1C);
    // 0x8008BB94: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x8008BB98: lh          $t7, 0xBE8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XBE8);
    // 0x8008BB9C: nop

    // 0x8008BBA0: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8008BBA4: sb          $t9, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r25;
    // 0x8008BBA8: jal         0x8008ECE4
    // 0x8008BBAC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8008BBAC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x8008BBB0: addiu       $t0, $zero, 0xEF
    ctx->r8 = ADD32(0, 0XEF);
    // 0x8008BBB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BBB8: sw          $t0, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r8;
    // 0x8008BBBC: addiu       $t1, $zero, 0x82
    ctx->r9 = ADD32(0, 0X82);
    // 0x8008BBC0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BBC4: sw          $t1, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r9;
    // 0x8008BBC8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008BBCC: addiu       $a1, $a1, -0xA8C
    ctx->r5 = ADD32(ctx->r5, -0XA8C);
    // 0x8008BBD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8008BBD4: jal         0x800BCFCC
    // 0x8008BBD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x8008BBD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x8008BBDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8008BBE0: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x8008BBE4: lbu         $t2, 0x1($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X1);
    // 0x8008BBE8: lh          $t6, 0xBEA($t3)
    ctx->r14 = MEM_H(ctx->r11, 0XBEA);
    // 0x8008BBEC: nop

    // 0x8008BBF0: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x8008BBF4: sb          $t5, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r13;
    // 0x8008BBF8: jal         0x8008ECE4
    // 0x8008BBFC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8008BBFC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_6:
    // 0x8008BC00: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008BC04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008BC08: lh          $t9, 0xBD8($t7)
    ctx->r25 = MEM_H(ctx->r15, 0XBD8);
    // 0x8008BC0C: nop

    // 0x8008BC10: beq         $t9, $at, L_8008BC58
    if (ctx->r25 == ctx->r1) {
        // 0x8008BC14: nop

            goto L_8008BC58;
    }
    // 0x8008BC14: nop

    // 0x8008BC18: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008BC1C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BC20: lh          $t0, 0xBD8($t4)
    ctx->r8 = MEM_H(ctx->r12, 0XBD8);
    // 0x8008BC24: nop

    // 0x8008BC28: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8008BC2C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8008BC30: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008BC34: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8008BC38: addiu       $t3, $t1, 0xC8
    ctx->r11 = ADD32(ctx->r9, 0XC8);
    // 0x8008BC3C: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x8008BC40: addiu       $t2, $zero, 0x82
    ctx->r10 = ADD32(0, 0X82);
    // 0x8008BC44: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BC48: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x8008BC4C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008BC50: jal         0x8008ECE4
    // 0x8008BC54: addiu       $a0, $a0, -0xA88
    ctx->r4 = ADD32(ctx->r4, -0XA88);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8008BC54: addiu       $a0, $a0, -0xA88
    ctx->r4 = ADD32(ctx->r4, -0XA88);
    after_7:
L_8008BC58:
    // 0x8008BC58: b           L_8008BC60
    // 0x8008BC5C: nop

        goto L_8008BC60;
    // 0x8008BC5C: nop

L_8008BC60:
    // 0x8008BC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BC64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008BC68: jr          $ra
    // 0x8008BC6C: nop

    return;
    // 0x8008BC6C: nop

;}
RECOMP_FUNC void func_8008BC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008BC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BC78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008BC7C: jal         0x80090754
    // 0x8008BC80: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090754(rdram, ctx);
        goto after_0;
    // 0x8008BC80: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8008BC84: jal         0x80090728
    // 0x8008BC88: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090728(rdram, ctx);
        goto after_1;
    // 0x8008BC88: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x8008BC8C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008BC90: nop

    // 0x8008BC94: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008BC98: nop

    // 0x8008BC9C: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x8008BCA0: beq         $t8, $zero, L_8008BCB4
    if (ctx->r24 == 0) {
        // 0x8008BCA4: nop

            goto L_8008BCB4;
    }
    // 0x8008BCA4: nop

    // 0x8008BCA8: addiu       $t9, $zero, 0x57
    ctx->r25 = ADD32(0, 0X57);
    // 0x8008BCAC: b           L_8008BCB8
    // 0x8008BCB0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_8008BCB8;
    // 0x8008BCB0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008BCB4:
    // 0x8008BCB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008BCB8:
    // 0x8008BCB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008BCBC: addiu       $a0, $a0, -0xA84
    ctx->r4 = ADD32(ctx->r4, -0XA84);
    // 0x8008BCC0: jal         0x8008ECE4
    // 0x8008BCC4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8008BCC4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x8008BCC8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8008BCCC:
    // 0x8008BCCC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8008BCD0:
    // 0x8008BCD0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008BCD4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8008BCD8: bne         $t0, $at, L_8008BCFC
    if (ctx->r8 != ctx->r1) {
        // 0x8008BCDC: nop

            goto L_8008BCFC;
    }
    // 0x8008BCDC: nop

    // 0x8008BCE0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8008BCE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BCE8: beq         $t1, $at, L_8008BD1C
    if (ctx->r9 == ctx->r1) {
        // 0x8008BCEC: nop

            goto L_8008BD1C;
    }
    // 0x8008BCEC: nop

    // 0x8008BCF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008BCF4: beq         $t1, $at, L_8008BD1C
    if (ctx->r9 == ctx->r1) {
        // 0x8008BCF8: nop

            goto L_8008BD1C;
    }
    // 0x8008BCF8: nop

L_8008BCFC:
    // 0x8008BCFC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008BD00: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008BD04: bne         $t2, $at, L_8008BD24
    if (ctx->r10 != ctx->r1) {
        // 0x8008BD08: nop

            goto L_8008BD24;
    }
    // 0x8008BD08: nop

    // 0x8008BD0C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008BD10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008BD14: bne         $t3, $at, L_8008BD24
    if (ctx->r11 != ctx->r1) {
        // 0x8008BD18: nop

            goto L_8008BD24;
    }
    // 0x8008BD18: nop

L_8008BD1C:
    // 0x8008BD1C: b           L_8008BDC4
    // 0x8008BD20: nop

        goto L_8008BDC4;
    // 0x8008BD20: nop

L_8008BD24:
    // 0x8008BD24: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8008BD28: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BD2C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8008BD30: addiu       $t6, $t5, 0x6
    ctx->r14 = ADD32(ctx->r13, 0X6);
    // 0x8008BD34: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x8008BD38: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008BD3C: nop

    // 0x8008BD40: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x8008BD44: bne         $at, $zero, L_8008BD60
    if (ctx->r1 != 0) {
        // 0x8008BD48: nop

            goto L_8008BD60;
    }
    // 0x8008BD48: nop

    // 0x8008BD4C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008BD50: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x8008BD54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BD58: addiu       $t9, $t8, 0x56
    ctx->r25 = ADD32(ctx->r24, 0X56);
    // 0x8008BD5C: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
L_8008BD60:
    // 0x8008BD60: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008BD64: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008BD68: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x8008BD6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BD70: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008BD74: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8008BD78: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8008BD7C: addiu       $t3, $t2, 0x5
    ctx->r11 = ADD32(ctx->r10, 0X5);
    // 0x8008BD80: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8008BD84: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BD88: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008BD8C: addiu       $t6, $t6, 0x4930
    ctx->r14 = ADD32(ctx->r14, 0X4930);
    // 0x8008BD90: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008BD94: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8008BD98: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8008BD9C: jal         0x800BCFCC
    // 0x8008BDA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x8008BDA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x8008BDA4: addiu       $t7, $sp, 0x18
    ctx->r15 = ADD32(ctx->r29, 0X18);
    // 0x8008BDA8: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
    // 0x8008BDAC: jal         0x8008ECE4
    // 0x8008BDB0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8008BDB0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x8008BDB4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BDB8: nop

    // 0x8008BDBC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008BDC0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008BDC4:
    // 0x8008BDC4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8008BDC8: nop

    // 0x8008BDCC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008BDD0: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8008BDD4: bne         $at, $zero, L_8008BCD0
    if (ctx->r1 != 0) {
        // 0x8008BDD8: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8008BCD0;
    }
    // 0x8008BDD8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8008BDDC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008BDE0: nop

    // 0x8008BDE4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008BDE8: slti        $at, $t3, 0x12
    ctx->r1 = SIGNED(ctx->r11) < 0X12 ? 1 : 0;
    // 0x8008BDEC: bne         $at, $zero, L_8008BCCC
    if (ctx->r1 != 0) {
        // 0x8008BDF0: sw          $t3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r11;
            goto L_8008BCCC;
    }
    // 0x8008BDF0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8008BDF4: b           L_8008BDFC
    // 0x8008BDF8: nop

        goto L_8008BDFC;
    // 0x8008BDF8: nop

L_8008BDFC:
    // 0x8008BDFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BE00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008BE04: jr          $ra
    // 0x8008BE08: nop

    return;
    // 0x8008BE08: nop

;}
RECOMP_FUNC void func_8008BE0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BE0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008BE10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BE14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008BE18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008BE1C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8008BE20: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BE24: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008BE28: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8008BE2C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8008BE30: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8008BE34: blez        $t8, L_8008BEB0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008BE38: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8008BEB0;
    }
    // 0x8008BE38: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8008BE3C:
    // 0x8008BE3C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008BE40: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008BE44: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008BE48: nop

    // 0x8008BE4C: bne         $t0, $at, L_8008BE5C
    if (ctx->r8 != ctx->r1) {
        // 0x8008BE50: nop

            goto L_8008BE5C;
    }
    // 0x8008BE50: nop

    // 0x8008BE54: b           L_8008BEB0
    // 0x8008BE58: nop

        goto L_8008BEB0;
    // 0x8008BE58: nop

L_8008BE5C:
    // 0x8008BE5C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8008BE60: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008BE64: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x8008BE68: addiu       $t4, $t4, 0x4930
    ctx->r12 = ADD32(ctx->r12, 0X4930);
    // 0x8008BE6C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BE70: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008BE74: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8008BE78: jal         0x800BCFCC
    // 0x8008BE7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x8008BE7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8008BE80: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8008BE84: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008BE88: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BE8C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8008BE90: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x8008BE94: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008BE98: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008BE9C: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8008BEA0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8008BEA4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8008BEA8: bne         $at, $zero, L_8008BE3C
    if (ctx->r1 != 0) {
        // 0x8008BEAC: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_8008BE3C;
    }
    // 0x8008BEAC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8008BEB0:
    // 0x8008BEB0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BEB4: nop

    // 0x8008BEB8: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x8008BEBC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8008BEC0: b           L_8008BED0
    // 0x8008BEC4: nop

        goto L_8008BED0;
    // 0x8008BEC4: nop

    // 0x8008BEC8: b           L_8008BED0
    // 0x8008BECC: nop

        goto L_8008BED0;
    // 0x8008BECC: nop

L_8008BED0:
    // 0x8008BED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BED4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008BED8: jr          $ra
    // 0x8008BEDC: nop

    return;
    // 0x8008BEDC: nop

;}
RECOMP_FUNC void func_8008BEE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BEE0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008BEE4: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8008BEE8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8008BEEC: nop

    // 0x8008BEF0: beq         $t6, $zero, L_8008BF98
    if (ctx->r14 == 0) {
        // 0x8008BEF4: nop

            goto L_8008BF98;
    }
    // 0x8008BEF4: nop

    // 0x8008BEF8: blez        $a2, L_8008BF98
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008BEFC: nop

            goto L_8008BF98;
    }
    // 0x8008BEFC: nop

L_8008BF00:
    // 0x8008BF00: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008BF04: addiu       $t7, $t7, 0x4930
    ctx->r15 = ADD32(ctx->r15, 0X4930);
    // 0x8008BF08: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8008BF0C: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8008BF10:
    // 0x8008BF10: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008BF14: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x8008BF18: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008BF1C: nop

    // 0x8008BF20: bne         $t8, $t0, L_8008BF50
    if (ctx->r24 != ctx->r8) {
        // 0x8008BF24: nop

            goto L_8008BF50;
    }
    // 0x8008BF24: nop

    // 0x8008BF28: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x8008BF2C: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x8008BF30: nop

    // 0x8008BF34: bne         $t1, $t2, L_8008BF50
    if (ctx->r9 != ctx->r10) {
        // 0x8008BF38: nop

            goto L_8008BF50;
    }
    // 0x8008BF38: nop

    // 0x8008BF3C: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x8008BF40: nop

    // 0x8008BF44: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x8008BF48: b           L_8008BF6C
    // 0x8008BF4C: nop

        goto L_8008BF6C;
    // 0x8008BF4C: nop

L_8008BF50:
    // 0x8008BF50: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x8008BF54: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008BF58: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8008BF5C: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8008BF60: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8008BF64: b           L_8008BF10
    // 0x8008BF68: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
        goto L_8008BF10;
    // 0x8008BF68: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
L_8008BF6C:
    // 0x8008BF6C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008BF70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008BF74: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8008BF78: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8008BF7C: lbu         $t9, 0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1);
    // 0x8008BF80: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008BF84: beq         $t9, $zero, L_8008BF98
    if (ctx->r25 == 0) {
        // 0x8008BF88: nop

            goto L_8008BF98;
    }
    // 0x8008BF88: nop

    // 0x8008BF8C: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8008BF90: bne         $at, $zero, L_8008BF00
    if (ctx->r1 != 0) {
        // 0x8008BF94: nop

            goto L_8008BF00;
    }
    // 0x8008BF94: nop

L_8008BF98:
    // 0x8008BF98: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008BF9C: nop

    // 0x8008BFA0: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x8008BFA4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8008BFA8: nop

    // 0x8008BFAC: slt         $at, $t2, $a2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8008BFB0: beq         $at, $zero, L_8008BFD8
    if (ctx->r1 == 0) {
        // 0x8008BFB4: nop

            goto L_8008BFD8;
    }
    // 0x8008BFB4: nop

L_8008BFB8:
    // 0x8008BFB8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8008BFBC: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x8008BFC0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008BFC4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008BFC8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8008BFCC: slt         $at, $t5, $a2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8008BFD0: bne         $at, $zero, L_8008BFB8
    if (ctx->r1 != 0) {
        // 0x8008BFD4: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_8008BFB8;
    }
    // 0x8008BFD4: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
L_8008BFD8:
    // 0x8008BFD8: lw          $v0, 0x8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8);
    // 0x8008BFDC: b           L_8008BFEC
    // 0x8008BFE0: nop

        goto L_8008BFEC;
    // 0x8008BFE0: nop

    // 0x8008BFE4: b           L_8008BFEC
    // 0x8008BFE8: nop

        goto L_8008BFEC;
    // 0x8008BFE8: nop

L_8008BFEC:
    // 0x8008BFEC: jr          $ra
    // 0x8008BFF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008BFF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8008BFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BFF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008BFF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BFFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008C000: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008C004: addiu       $t6, $t6, 0x7AE8
    ctx->r14 = ADD32(ctx->r14, 0X7AE8);
    // 0x8008C008: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8008C00C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8008C010:
    // 0x8008C010: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008C014: nop

    // 0x8008C018: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8008C01C: nop

    // 0x8008C020: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008C024: bne         $t9, $zero, L_8008C06C
    if (ctx->r25 != 0) {
        // 0x8008C028: nop

            goto L_8008C06C;
    }
    // 0x8008C028: nop

    // 0x8008C02C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8008C030: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8008C034: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008C038: lw          $t1, 0x138($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X138);
    // 0x8008C03C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8008C040: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8008C044: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8008C048: addiu       $t6, $t5, 0xA0
    ctx->r14 = ADD32(ctx->r13, 0XA0);
    // 0x8008C04C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8008C050: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008C054: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8008C058: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C05C: lw          $a1, 0x138($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X138);
    // 0x8008C060: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8008C064: jal         0x800BCFCC
    // 0x8008C068: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, 0X1E0);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x8008C068: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, 0X1E0);
    after_0:
L_8008C06C:
    // 0x8008C06C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008C070: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008C074: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008C078: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8008C07C: addiu       $t2, $t0, 0x16
    ctx->r10 = ADD32(ctx->r8, 0X16);
    // 0x8008C080: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8008C084: bne         $at, $zero, L_8008C010
    if (ctx->r1 != 0) {
        // 0x8008C088: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8008C010;
    }
    // 0x8008C088: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8008C08C: b           L_8008C094
    // 0x8008C090: nop

        goto L_8008C094;
    // 0x8008C090: nop

L_8008C094:
    // 0x8008C094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C098: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008C09C: jr          $ra
    // 0x8008C0A0: nop

    return;
    // 0x8008C0A0: nop

;}
RECOMP_FUNC void func_8008C0A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0A4: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8008C0A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008C0AC: sh          $t6, 0x100($t7)
    MEM_H(0X100, ctx->r15) = ctx->r14;
    // 0x8008C0B0: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8008C0B4: ori         $t8, $zero, 0xD6B5
    ctx->r24 = 0 | 0XD6B5;
    // 0x8008C0B8: sh          $t8, 0x102($t9)
    MEM_H(0X102, ctx->r25) = ctx->r24;
    // 0x8008C0BC: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x8008C0C0: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8008C0C4: sh          $t0, 0x104($t1)
    MEM_H(0X104, ctx->r9) = ctx->r8;
    // 0x8008C0C8: jr          $ra
    // 0x8008C0CC: nop

    return;
    // 0x8008C0CC: nop

    // 0x8008C0D0: jr          $ra
    // 0x8008C0D4: nop

    return;
    // 0x8008C0D4: nop

;}
RECOMP_FUNC void func_8008C0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0D8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C0DC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8008C0E0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008C0E4:
    // 0x8008C0E4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008C0E8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008C0EC: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008C0F0: sb          $t6, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r14;
    // 0x8008C0F4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008C0F8: nop

    // 0x8008C0FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008C100: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8008C104: bne         $at, $zero, L_8008C0E4
    if (ctx->r1 != 0) {
        // 0x8008C108: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_8008C0E4;
    }
    // 0x8008C108: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8008C10C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008C110:
    // 0x8008C110: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008C114: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008C118: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8008C11C: sb          $t1, 0x7($t3)
    MEM_B(0X7, ctx->r11) = ctx->r9;
    // 0x8008C120: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8008C124: nop

    // 0x8008C128: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8008C12C: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8008C130: bne         $at, $zero, L_8008C110
    if (ctx->r1 != 0) {
        // 0x8008C134: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_8008C110;
    }
    // 0x8008C134: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8008C138: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008C13C: sh          $t7, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r15;
    // 0x8008C140: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x8008C144: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x8008C148: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x8008C14C: sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // 0x8008C150: b           L_8008C158
    // 0x8008C154: nop

        goto L_8008C158;
    // 0x8008C154: nop

L_8008C158:
    // 0x8008C158: jr          $ra
    // 0x8008C15C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C15C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008C160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C160: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C164: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8008C168: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8008C16C:
    // 0x8008C16C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008C170: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008C174: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008C178: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008C17C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008C180: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008C184: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8008C188: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008C18C: lhu         $t8, 0x7AE8($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7AE8);
    // 0x8008C190: nop

    // 0x8008C194: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008C198: beq         $t9, $zero, L_8008C1BC
    if (ctx->r25 == 0) {
        // 0x8008C19C: nop

            goto L_8008C1BC;
    }
    // 0x8008C19C: nop

    // 0x8008C1A0: andi        $t0, $t8, 0x4000
    ctx->r8 = ctx->r24 & 0X4000;
    // 0x8008C1A4: beq         $t0, $zero, L_8008C1BC
    if (ctx->r8 == 0) {
        // 0x8008C1A8: nop

            goto L_8008C1BC;
    }
    // 0x8008C1A8: nop

    // 0x8008C1AC: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8008C1B0: nop

    // 0x8008C1B4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008C1B8: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_8008C1BC:
    // 0x8008C1BC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008C1C0: nop

    // 0x8008C1C4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008C1C8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8008C1CC: bne         $at, $zero, L_8008C16C
    if (ctx->r1 != 0) {
        // 0x8008C1D0: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8008C16C;
    }
    // 0x8008C1D0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008C1D4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008C1D8: b           L_8008C1E8
    // 0x8008C1DC: nop

        goto L_8008C1E8;
    // 0x8008C1DC: nop

    // 0x8008C1E0: b           L_8008C1E8
    // 0x8008C1E4: nop

        goto L_8008C1E8;
    // 0x8008C1E4: nop

L_8008C1E8:
    // 0x8008C1E8: jr          $ra
    // 0x8008C1EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C1EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008C1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1F0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C1F4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8008C1F8: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8008C1FC:
    // 0x8008C1FC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008C200: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008C204: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008C208: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008C20C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008C210: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008C214: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8008C218: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008C21C: lhu         $t8, 0x7AE8($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7AE8);
    // 0x8008C220: nop

    // 0x8008C224: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008C228: beq         $t9, $zero, L_8008C24C
    if (ctx->r25 == 0) {
        // 0x8008C22C: nop

            goto L_8008C24C;
    }
    // 0x8008C22C: nop

    // 0x8008C230: andi        $t0, $t8, 0x4000
    ctx->r8 = ctx->r24 & 0X4000;
    // 0x8008C234: bne         $t0, $zero, L_8008C24C
    if (ctx->r8 != 0) {
        // 0x8008C238: nop

            goto L_8008C24C;
    }
    // 0x8008C238: nop

    // 0x8008C23C: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8008C240: nop

    // 0x8008C244: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008C248: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_8008C24C:
    // 0x8008C24C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008C250: nop

    // 0x8008C254: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008C258: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8008C25C: bne         $at, $zero, L_8008C1FC
    if (ctx->r1 != 0) {
        // 0x8008C260: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8008C1FC;
    }
    // 0x8008C260: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008C264: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008C268: b           L_8008C278
    // 0x8008C26C: nop

        goto L_8008C278;
    // 0x8008C26C: nop

    // 0x8008C270: b           L_8008C278
    // 0x8008C274: nop

        goto L_8008C278;
    // 0x8008C274: nop

L_8008C278:
    // 0x8008C278: jr          $ra
    // 0x8008C27C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C27C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008C280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C280: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C284: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008C288: lh          $t6, 0x7A12($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7A12);
    // 0x8008C28C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8008C290: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x8008C294: mflo        $t7
    ctx->r15 = lo;
    // 0x8008C298: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8008C29C: nop

    // 0x8008C2A0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008C2A4: lh          $t9, 0x7A14($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7A14);
    // 0x8008C2A8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8008C2AC: nop

    // 0x8008C2B0: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8008C2B4: beq         $at, $zero, L_8008C2CC
    if (ctx->r1 == 0) {
        // 0x8008C2B8: nop

            goto L_8008C2CC;
    }
    // 0x8008C2B8: nop

    // 0x8008C2BC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008C2C0: lh          $t0, 0x7A14($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7A14);
    // 0x8008C2C4: nop

    // 0x8008C2C8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
L_8008C2CC:
    // 0x8008C2CC: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8008C2D0: b           L_8008C2E0
    // 0x8008C2D4: nop

        goto L_8008C2E0;
    // 0x8008C2D4: nop

    // 0x8008C2D8: b           L_8008C2E0
    // 0x8008C2DC: nop

        goto L_8008C2E0;
    // 0x8008C2DC: nop

L_8008C2E0:
    // 0x8008C2E0: jr          $ra
    // 0x8008C2E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C2E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_8008C34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C34C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C354: jal         0x800AE398
    // 0x8008C358: nop

    ContPak_GetPakInitilizationResult(rdram, ctx);
        goto after_0;
    // 0x8008C358: nop

    after_0:
    // 0x8008C35C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008C360: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C364: nop

    // 0x8008C368: bne         $t6, $zero, L_8008C3B0
    if (ctx->r14 != 0) {
        // 0x8008C36C: nop

            goto L_8008C3B0;
    }
    // 0x8008C36C: nop

    // 0x8008C370: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008C374: lw          $t7, 0x1350($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1350);
    // 0x8008C378: nop

    // 0x8008C37C: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8008C380: beq         $t8, $zero, L_8008C3A8
    if (ctx->r24 == 0) {
        // 0x8008C384: nop

            goto L_8008C3A8;
    }
    // 0x8008C384: nop

    // 0x8008C388: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008C38C: lw          $t9, 0x129C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X129C);
    // 0x8008C390: nop

    // 0x8008C394: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8008C398: beq         $t0, $zero, L_8008C3A8
    if (ctx->r8 == 0) {
        // 0x8008C39C: nop

            goto L_8008C3A8;
    }
    // 0x8008C39C: nop

    // 0x8008C3A0: b           L_8008C3C4
    // 0x8008C3A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C3C4;
    // 0x8008C3A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C3A8:
    // 0x8008C3A8: b           L_8008C3C4
    // 0x8008C3AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008C3C4;
    // 0x8008C3AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008C3B0:
    // 0x8008C3B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C3B4: b           L_8008C3C4
    // 0x8008C3B8: nop

        goto L_8008C3C4;
    // 0x8008C3B8: nop

    // 0x8008C3BC: b           L_8008C3C4
    // 0x8008C3C0: nop

        goto L_8008C3C4;
    // 0x8008C3C0: nop

L_8008C3C4:
    // 0x8008C3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C3C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008C3CC: jr          $ra
    // 0x8008C3D0: nop

    return;
    // 0x8008C3D0: nop

;}
RECOMP_FUNC void func_8008C3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C3D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C3D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C3DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008C3E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008C3E4:
    // 0x8008C3E4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008C3E8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C3EC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008C3F0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8008C3F4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8008C3F8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C3FC: nop

    // 0x8008C400: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008C404: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8008C408: bne         $at, $zero, L_8008C3E4
    if (ctx->r1 != 0) {
        // 0x8008C40C: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8008C3E4;
    }
    // 0x8008C40C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8008C410: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008C414:
    // 0x8008C414: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8008C418: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C41C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008C420: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8008C424: sb          $t2, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r10;
    // 0x8008C428: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C42C: nop

    // 0x8008C430: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008C434: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8008C438: bne         $at, $zero, L_8008C414
    if (ctx->r1 != 0) {
        // 0x8008C43C: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_8008C414;
    }
    // 0x8008C43C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8008C440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008C444: jal         0x80028F74
    // 0x8008C448: nop

    func_80028F74(rdram, ctx);
        goto after_0;
    // 0x8008C448: nop

    after_0:
    // 0x8008C44C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8008C450: nop

    // 0x8008C454: sb          $zero, 0x64($t6)
    MEM_B(0X64, ctx->r14) = 0;
    // 0x8008C458: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8008C45C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8008C460: lw          $t0, 0x70E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70E8);
    // 0x8008C464: lw          $t9, 0x718C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X718C);
    // 0x8008C468: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8008C46C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8008C470: sw          $t1, 0x68($t3)
    MEM_W(0X68, ctx->r11) = ctx->r9;
    // 0x8008C474: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8008C478: lbu         $t4, 0x7208($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7208);
    // 0x8008C47C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008C480: nop

    // 0x8008C484: sh          $t4, 0x6C($t2)
    MEM_H(0X6C, ctx->r10) = ctx->r12;
    // 0x8008C488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008C48C: jal         0x8005F410
    // 0x8008C490: nop

    func_8005F410(rdram, ctx);
        goto after_1;
    // 0x8008C490: nop

    after_1:
    // 0x8008C494: b           L_8008C49C
    // 0x8008C498: nop

        goto L_8008C49C;
    // 0x8008C498: nop

L_8008C49C:
    // 0x8008C49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C4A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008C4A4: jr          $ra
    // 0x8008C4A8: nop

    return;
    // 0x8008C4A8: nop

;}
RECOMP_FUNC void func_8008C4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C4AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C4B0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008C4B4:
    // 0x8008C4B4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008C4B8: nop

    // 0x8008C4BC: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8008C4C0: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x8008C4C4: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x8008C4C8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8008C4CC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008C4D0: nop

    // 0x8008C4D4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008C4D8: slti        $at, $t1, 0x7
    ctx->r1 = SIGNED(ctx->r9) < 0X7 ? 1 : 0;
    // 0x8008C4DC: bne         $at, $zero, L_8008C4B4
    if (ctx->r1 != 0) {
        // 0x8008C4E0: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8008C4B4;
    }
    // 0x8008C4E0: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8008C4E4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008C4E8:
    // 0x8008C4E8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008C4EC: nop

    // 0x8008C4F0: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8008C4F4: lbu         $t4, 0x9($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X9);
    // 0x8008C4F8: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x8008C4FC: sb          $t4, 0x651($t5)
    MEM_B(0X651, ctx->r13) = ctx->r12;
    // 0x8008C500: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008C504: nop

    // 0x8008C508: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8008C50C: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x8008C510: bne         $at, $zero, L_8008C4E8
    if (ctx->r1 != 0) {
        // 0x8008C514: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_8008C4E8;
    }
    // 0x8008C514: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008C518: b           L_8008C520
    // 0x8008C51C: nop

        goto L_8008C520;
    // 0x8008C51C: nop

L_8008C520:
    // 0x8008C520: jr          $ra
    // 0x8008C524: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C524: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8008C528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C528: lbu         $t6, 0x15($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X15);
    // 0x8008C52C: lbu         $t8, 0x13($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X13);
    // 0x8008C530: lbu         $t1, 0x14($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X14);
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
