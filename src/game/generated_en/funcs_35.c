#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80084F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084F60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084F64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80084F68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084F6C: jal         0x8008B4EC
    // 0x80084F70: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80084F70: nop

    after_0:
    // 0x80084F74: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80084F78: nop

    // 0x80084F7C: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x80084F80: nop

    // 0x80084F84: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80084F88: beq         $t8, $zero, L_80084FF0
    if (ctx->r24 == 0) {
        // 0x80084F8C: nop

            goto L_80084FF0;
    }
    // 0x80084F8C: nop

    // 0x80084F90: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x80084F94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084F98: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x80084F9C: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80084FA0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084FA4: sw          $t0, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r8;
    // 0x80084FA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084FAC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80084FB0: jal         0x8008B2FC
    // 0x80084FB4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_1;
    // 0x80084FB4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_1:
    // 0x80084FB8: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80084FBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084FC0: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
    // 0x80084FC4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80084FC8: lw          $t2, 0x6BA0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6BA0);
    // 0x80084FCC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80084FD0: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x80084FD4: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x80084FD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084FDC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80084FE0: jal         0x8008B2FC
    // 0x80084FE4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_2;
    // 0x80084FE4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // 0x80084FE8: b           L_800851B4
    // 0x80084FEC: nop

        goto L_800851B4;
    // 0x80084FEC: nop

L_80084FF0:
    // 0x80084FF0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80084FF4: lhu         $t4, 0x7A10($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X7A10);
    // 0x80084FF8: nop

    // 0x80084FFC: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80085000: bne         $t5, $zero, L_80085068
    if (ctx->r13 != 0) {
        // 0x80085004: nop

            goto L_80085068;
    }
    // 0x80085004: nop

    // 0x80085008: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x8008500C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085010: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x80085014: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80085018: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008501C: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x80085020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085024: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80085028: jal         0x8008B2FC
    // 0x8008502C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_3;
    // 0x8008502C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_3:
    // 0x80085030: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x80085034: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085038: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x8008503C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80085040: lw          $t9, 0x6BA0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6BA0);
    // 0x80085044: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085048: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x8008504C: sw          $t0, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r8;
    // 0x80085050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085054: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80085058: jal         0x8008B2FC
    // 0x8008505C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_4;
    // 0x8008505C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_4:
    // 0x80085060: b           L_800851B4
    // 0x80085064: nop

        goto L_800851B4;
    // 0x80085064: nop

L_80085068:
    // 0x80085068: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008506C: lhu         $t1, 0x7A10($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X7A10);
    // 0x80085070: nop

    // 0x80085074: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x80085078: beq         $t2, $zero, L_800850E0
    if (ctx->r10 == 0) {
        // 0x8008507C: nop

            goto L_800850E0;
    }
    // 0x8008507C: nop

    // 0x80085080: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x80085084: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085088: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x8008508C: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80085090: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085094: sw          $t4, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r12;
    // 0x80085098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008509C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x800850A0: jal         0x8008B2FC
    // 0x800850A4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_5;
    // 0x800850A4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_5:
    // 0x800850A8: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x800850AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850B0: sw          $t5, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r13;
    // 0x800850B4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800850B8: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x800850BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850C0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800850C4: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x800850C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800850CC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x800850D0: jal         0x8008B2FC
    // 0x800850D4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_6;
    // 0x800850D4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_6:
    // 0x800850D8: b           L_800851B4
    // 0x800850DC: nop

        goto L_800851B4;
    // 0x800850DC: nop

L_800850E0:
    // 0x800850E0: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x800850E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850E8: sw          $t8, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r24;
    // 0x800850EC: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x800850F0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800850F4: sw          $t9, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r25;
    // 0x800850F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800850FC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80085100: jal         0x8008B2FC
    // 0x80085104: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_7;
    // 0x80085104: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_7:
    // 0x80085108: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8008510C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085110: sw          $t0, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r8;
    // 0x80085114: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80085118: lw          $t1, 0x6BA0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6BA0);
    // 0x8008511C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085120: addiu       $t2, $t1, 0x20
    ctx->r10 = ADD32(ctx->r9, 0X20);
    // 0x80085124: sw          $t2, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r10;
    // 0x80085128: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008512C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80085130: jal         0x8008B2FC
    // 0x80085134: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_8;
    // 0x80085134: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_8:
    // 0x80085138: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8008513C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085140: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x80085144: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80085148: lw          $t4, 0x6BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA0);
    // 0x8008514C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085150: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x80085154: sw          $t5, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r13;
    // 0x80085158: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008515C: addiu       $a0, $a0, -0xAD0
    ctx->r4 = ADD32(ctx->r4, -0XAD0);
    // 0x80085160: jal         0x8008ECE4
    // 0x80085164: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x80085164: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_9:
    // 0x80085168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008516C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80085170: jal         0x8008B2FC
    // 0x80085174: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_10;
    // 0x80085174: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_10:
    // 0x80085178: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8008517C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085180: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x80085184: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80085188: lw          $t7, 0x6BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA0);
    // 0x8008518C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80085190: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80085194: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x80085198: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008519C: lh          $a1, 0x7A12($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7A12);
    // 0x800851A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800851A4: jal         0x8008ECE4
    // 0x800851A8: addiu       $a0, $a0, -0xACC
    ctx->r4 = ADD32(ctx->r4, -0XACC);
    func_8008ECE4(rdram, ctx);
        goto after_11;
    // 0x800851A8: addiu       $a0, $a0, -0xACC
    ctx->r4 = ADD32(ctx->r4, -0XACC);
    after_11:
    // 0x800851AC: b           L_800851B4
    // 0x800851B0: nop

        goto L_800851B4;
    // 0x800851B0: nop

L_800851B4:
    // 0x800851B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800851B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800851BC: jr          $ra
    // 0x800851C0: nop

    return;
    // 0x800851C0: nop

;}
RECOMP_FUNC void func_800851C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800851C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800851CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800851D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800851D4: jal         0x8008A46C
    // 0x800851D8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x800851D8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x800851DC: jal         0x8008C160
    // 0x800851E0: nop

    func_8008C160(rdram, ctx);
        goto after_1;
    // 0x800851E0: nop

    after_1:
    // 0x800851E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800851E8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800851EC: addiu       $t6, $t6, 0x4720
    ctx->r14 = ADD32(ctx->r14, 0X4720);
    // 0x800851F0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800851F4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800851F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800851FC: beq         $t7, $at, L_800852F4
    if (ctx->r15 == ctx->r1) {
        // 0x80085200: nop

            goto L_800852F4;
    }
    // 0x80085200: nop

L_80085204:
    // 0x80085204: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80085208: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008520C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80085210: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80085214: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80085218: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8008521C: lh          $t0, 0x4726($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X4726);
    // 0x80085220: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80085224: bne         $t0, $at, L_800852C8
    if (ctx->r8 != ctx->r1) {
        // 0x80085228: nop

            goto L_800852C8;
    }
    // 0x80085228: nop

    // 0x8008522C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80085230: nop

    // 0x80085234: bne         $t1, $zero, L_80085280
    if (ctx->r9 != 0) {
        // 0x80085238: nop

            goto L_80085280;
    }
    // 0x80085238: nop

    // 0x8008523C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80085240: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085244: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80085248: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008524C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80085250: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80085254: addiu       $t2, $zero, 0x81
    ctx->r10 = ADD32(0, 0X81);
    // 0x80085258: sh          $t2, 0x4728($at)
    MEM_H(0X4728, ctx->r1) = ctx->r10;
    // 0x8008525C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80085260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085264: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80085268: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8008526C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80085270: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80085274: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80085278: b           L_800852C0
    // 0x8008527C: sh          $t5, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r13;
        goto L_800852C0;
    // 0x8008527C: sh          $t5, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r13;
L_80085280:
    // 0x80085280: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80085284: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085288: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008528C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80085290: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80085294: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80085298: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8008529C: sh          $t8, 0x4728($at)
    MEM_H(0X4728, ctx->r1) = ctx->r24;
    // 0x800852A0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800852A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800852A8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x800852AC: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x800852B0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800852B4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800852B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800852BC: sh          $t1, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r9;
L_800852C0:
    // 0x800852C0: b           L_800852F4
    // 0x800852C4: nop

        goto L_800852F4;
    // 0x800852C4: nop

L_800852C8:
    // 0x800852C8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800852CC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800852D0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800852D4: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x800852D8: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x800852DC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800852E0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800852E4: lh          $t7, 0x4720($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X4720);
    // 0x800852E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800852EC: bne         $t7, $at, L_80085204
    if (ctx->r15 != ctx->r1) {
        // 0x800852F0: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_80085204;
    }
    // 0x800852F0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800852F4:
    // 0x800852F4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800852F8: addiu       $t9, $t9, 0x4720
    ctx->r25 = ADD32(ctx->r25, 0X4720);
    // 0x800852FC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80085300: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x80085304: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085308: beq         $t8, $at, L_8008541C
    if (ctx->r24 == ctx->r1) {
        // 0x8008530C: nop

            goto L_8008541C;
    }
    // 0x8008530C: nop

L_80085310:
    // 0x80085310: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80085314: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085318: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8008531C: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x80085320: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80085324: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80085328: lh          $t1, 0x4726($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4726);
    // 0x8008532C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085330: bne         $t1, $at, L_800853F0
    if (ctx->r9 != ctx->r1) {
        // 0x80085334: nop

            goto L_800853F0;
    }
    // 0x80085334: nop

    // 0x80085338: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008533C: nop

    // 0x80085340: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80085344: beq         $at, $zero, L_800853A8
    if (ctx->r1 == 0) {
        // 0x80085348: nop

            goto L_800853A8;
    }
    // 0x80085348: nop

    // 0x8008534C: beq         $t2, $zero, L_80085364
    if (ctx->r10 == 0) {
        // 0x80085350: nop

            goto L_80085364;
    }
    // 0x80085350: nop

    // 0x80085354: jal         0x8008C1F0
    // 0x80085358: nop

    func_8008C1F0(rdram, ctx);
        goto after_2;
    // 0x80085358: nop

    after_2:
    // 0x8008535C: bne         $v0, $zero, L_800853A8
    if (ctx->r2 != 0) {
        // 0x80085360: nop

            goto L_800853A8;
    }
    // 0x80085360: nop

L_80085364:
    // 0x80085364: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80085368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008536C: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80085370: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x80085374: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80085378: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8008537C: addiu       $t4, $zero, 0x81
    ctx->r12 = ADD32(0, 0X81);
    // 0x80085380: sh          $t4, 0x4728($at)
    MEM_H(0X4728, ctx->r1) = ctx->r12;
    // 0x80085384: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80085388: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008538C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80085390: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80085394: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085398: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008539C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800853A0: b           L_800853E8
    // 0x800853A4: sh          $t7, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r15;
        goto L_800853E8;
    // 0x800853A4: sh          $t7, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r15;
L_800853A8:
    // 0x800853A8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800853AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800853B0: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x800853B4: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x800853B8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800853BC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800853C0: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800853C4: sh          $t0, 0x4728($at)
    MEM_H(0X4728, ctx->r1) = ctx->r8;
    // 0x800853C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800853CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800853D0: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800853D4: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x800853D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800853DC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800853E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800853E4: sh          $t2, 0x472A($at)
    MEM_H(0X472A, ctx->r1) = ctx->r10;
L_800853E8:
    // 0x800853E8: b           L_8008541C
    // 0x800853EC: nop

        goto L_8008541C;
    // 0x800853EC: nop

L_800853F0:
    // 0x800853F0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800853F4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800853F8: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x800853FC: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80085400: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x80085404: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80085408: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008540C: lh          $t8, 0x4720($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X4720);
    // 0x80085410: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085414: bne         $t8, $at, L_80085310
    if (ctx->r24 != ctx->r1) {
        // 0x80085418: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_80085310;
    }
    // 0x80085418: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008541C:
    // 0x8008541C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80085420: jal         0x80089170
    // 0x80085424: nop

    func_80089170(rdram, ctx);
        goto after_3;
    // 0x80085424: nop

    after_3:
    // 0x80085428: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8008542C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80085430: jal         0x800898D8
    // 0x80085434: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800898D8(rdram, ctx);
        goto after_4;
    // 0x80085434: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80085438: beq         $v0, $zero, L_80085488
    if (ctx->r2 == 0) {
        // 0x8008543C: nop

            goto L_80085488;
    }
    // 0x8008543C: nop

    // 0x80085440: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80085444: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x80085448: lh          $t6, 0x28($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X28);
    // 0x8008544C: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x80085450: addu        $a1, $t3, $t0
    ctx->r5 = ADD32(ctx->r11, ctx->r8);
    // 0x80085454: addu        $a2, $t6, $t2
    ctx->r6 = ADD32(ctx->r14, ctx->r10);
    // 0x80085458: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008545C: bgez        $a1, L_8008546C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80085460: sra         $t1, $a1, 1
        ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8008546C;
    }
    // 0x80085460: sra         $t1, $a1, 1
    ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80085464: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80085468: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8008546C:
    // 0x8008546C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80085470: bgez        $a2, L_80085480
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80085474: sra         $t4, $a2, 1
        ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80085480;
    }
    // 0x80085474: sra         $t4, $a2, 1
    ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80085478: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x8008547C: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80085480:
    // 0x80085480: jal         0x80089B04
    // 0x80085484: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    func_80089B04(rdram, ctx);
        goto after_5;
    // 0x80085484: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_5:
L_80085488:
    // 0x80085488: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8008548C: nop

    // 0x80085490: lh          $v0, 0x4($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X4);
    // 0x80085494: b           L_800854A4
    // 0x80085498: nop

        goto L_800854A4;
    // 0x80085498: nop

    // 0x8008549C: b           L_800854A4
    // 0x800854A0: nop

        goto L_800854A4;
    // 0x800854A0: nop

L_800854A4:
    // 0x800854A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800854A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800854AC: jr          $ra
    // 0x800854B0: nop

    return;
    // 0x800854B0: nop

;}
RECOMP_FUNC void func_800854B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800854B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800854BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800854C0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800854C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800854C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800854CC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800854D0: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x800854D4: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x800854D8: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x800854DC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800854E0: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x800854E4: beq         $t0, $zero, L_80085688
    if (ctx->r8 == 0) {
        // 0x800854E8: nop

            goto L_80085688;
    }
    // 0x800854E8: nop

    // 0x800854EC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800854F0: jal         0x8008A518
    // 0x800854F4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800854F4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800854F8: beq         $v0, $zero, L_80085688
    if (ctx->r2 == 0) {
        // 0x800854FC: nop

            goto L_80085688;
    }
    // 0x800854FC: nop

    // 0x80085500: lhu         $s0, 0x2C($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X2C);
    // 0x80085504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085508: beq         $s0, $at, L_8008553C
    if (ctx->r16 == ctx->r1) {
        // 0x8008550C: nop

            goto L_8008553C;
    }
    // 0x8008550C: nop

    // 0x80085510: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80085514: beq         $s0, $at, L_8008557C
    if (ctx->r16 == ctx->r1) {
        // 0x80085518: nop

            goto L_8008557C;
    }
    // 0x80085518: nop

    // 0x8008551C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085520: beq         $s0, $at, L_800855B8
    if (ctx->r16 == ctx->r1) {
        // 0x80085524: nop

            goto L_800855B8;
    }
    // 0x80085524: nop

    // 0x80085528: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008552C: beq         $s0, $at, L_8008563C
    if (ctx->r16 == ctx->r1) {
        // 0x80085530: nop

            goto L_8008563C;
    }
    // 0x80085530: nop

    // 0x80085534: b           L_80085688
    // 0x80085538: nop

        goto L_80085688;
    // 0x80085538: nop

L_8008553C:
    // 0x8008553C: jal         0x8008CE48
    // 0x80085540: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80085540: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80085544: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80085548: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8008554C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80085550: nop

    // 0x80085554: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80085558: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x8008555C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80085560: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80085564: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x80085568: nop

    // 0x8008556C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80085570: sh          $t6, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r14;
    // 0x80085574: b           L_800856A4
    // 0x80085578: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_800856A4;
    // 0x80085578: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8008557C:
    // 0x8008557C: jal         0x8008C160
    // 0x80085580: nop

    func_8008C160(rdram, ctx);
        goto after_2;
    // 0x80085580: nop

    after_2:
    // 0x80085584: beq         $v0, $zero, L_8008559C
    if (ctx->r2 == 0) {
        // 0x80085588: nop

            goto L_8008559C;
    }
    // 0x80085588: nop

    // 0x8008558C: jal         0x8008CE48
    // 0x80085590: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80085590: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_3:
    // 0x80085594: b           L_800856A4
    // 0x80085598: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_800856A4;
    // 0x80085598: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8008559C:
    // 0x8008559C: jal         0x8008CE48
    // 0x800855A0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x800855A0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_4:
    // 0x800855A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800855A8: jal         0x8008A730
    // 0x800855AC: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    func_8008A730(rdram, ctx);
        goto after_5;
    // 0x800855AC: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_5:
    // 0x800855B0: b           L_80085688
    // 0x800855B4: nop

        goto L_80085688;
    // 0x800855B4: nop

L_800855B8:
    // 0x800855B8: jal         0x8008C160
    // 0x800855BC: nop

    func_8008C160(rdram, ctx);
        goto after_6;
    // 0x800855BC: nop

    after_6:
    // 0x800855C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800855C4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800855C8: nop

    // 0x800855CC: bne         $t7, $zero, L_800855F0
    if (ctx->r15 != 0) {
        // 0x800855D0: nop

            goto L_800855F0;
    }
    // 0x800855D0: nop

    // 0x800855D4: jal         0x8008CE48
    // 0x800855D8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_7;
    // 0x800855D8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_7:
    // 0x800855DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800855E0: jal         0x8008A730
    // 0x800855E4: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    func_8008A730(rdram, ctx);
        goto after_8;
    // 0x800855E4: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_8:
    // 0x800855E8: b           L_80085688
    // 0x800855EC: nop

        goto L_80085688;
    // 0x800855EC: nop

L_800855F0:
    // 0x800855F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800855F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800855F8: bne         $t9, $at, L_8008562C
    if (ctx->r25 != ctx->r1) {
        // 0x800855FC: nop

            goto L_8008562C;
    }
    // 0x800855FC: nop

    // 0x80085600: jal         0x8008C1F0
    // 0x80085604: nop

    func_8008C1F0(rdram, ctx);
        goto after_9;
    // 0x80085604: nop

    after_9:
    // 0x80085608: bne         $v0, $zero, L_8008562C
    if (ctx->r2 != 0) {
        // 0x8008560C: nop

            goto L_8008562C;
    }
    // 0x8008560C: nop

    // 0x80085610: jal         0x8008CE48
    // 0x80085614: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80085614: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_10:
    // 0x80085618: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008561C: jal         0x8008A730
    // 0x80085620: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    func_8008A730(rdram, ctx);
        goto after_11;
    // 0x80085620: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_11:
    // 0x80085624: b           L_80085688
    // 0x80085628: nop

        goto L_80085688;
    // 0x80085628: nop

L_8008562C:
    // 0x8008562C: jal         0x8008CE48
    // 0x80085630: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_12;
    // 0x80085630: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_12:
    // 0x80085634: b           L_800856A4
    // 0x80085638: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_800856A4;
    // 0x80085638: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_8008563C:
    // 0x8008563C: jal         0x8008CE48
    // 0x80085640: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_13;
    // 0x80085640: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_13:
    // 0x80085644: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80085648: jal         0x8008C0D8
    // 0x8008564C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8008C0D8(rdram, ctx);
        goto after_14;
    // 0x8008564C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_14:
    // 0x80085650: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80085654: nop

    // 0x80085658: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x8008565C: nop

    // 0x80085660: ori         $t2, $t0, 0x800
    ctx->r10 = ctx->r8 | 0X800;
    // 0x80085664: sh          $t2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r10;
    // 0x80085668: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008566C: nop

    // 0x80085670: lhu         $t1, 0x2($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X2);
    // 0x80085674: nop

    // 0x80085678: ori         $t5, $t1, 0x8
    ctx->r13 = ctx->r9 | 0X8;
    // 0x8008567C: sh          $t5, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r13;
    // 0x80085680: b           L_800856A4
    // 0x80085684: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_800856A4;
    // 0x80085684: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80085688:
    // 0x80085688: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008568C: nop

    // 0x80085690: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80085694: b           L_800856A4
    // 0x80085698: nop

        goto L_800856A4;
    // 0x80085698: nop

    // 0x8008569C: b           L_800856A4
    // 0x800856A0: nop

        goto L_800856A4;
    // 0x800856A0: nop

L_800856A4:
    // 0x800856A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800856A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800856AC: jr          $ra
    // 0x800856B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800856B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800856B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800856B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800856BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800856C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800856C4: jal         0x8008B4EC
    // 0x800856C8: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800856C8: nop

    after_0:
    // 0x800856CC: b           L_800856D4
    // 0x800856D0: nop

        goto L_800856D4;
    // 0x800856D0: nop

L_800856D4:
    // 0x800856D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800856D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800856DC: jr          $ra
    // 0x800856E0: nop

    return;
    // 0x800856E0: nop

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
RECOMP_FUNC void func_800859DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800859E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800859E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800859E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800859EC: jal         0x8008B4EC
    // 0x800859F0: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800859F0: nop

    after_0:
    // 0x800859F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800859F8: jal         0x8008B600
    // 0x800859FC: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x800859FC: nop

    after_1:
    // 0x80085A00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085A08: jal         0x8008B738
    // 0x80085A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80085A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80085A10: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80085A14: jal         0x8008A518
    // 0x80085A18: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x80085A18: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80085A1C: beq         $v0, $zero, L_80085AB4
    if (ctx->r2 == 0) {
        // 0x80085A20: nop

            goto L_80085AB4;
    }
    // 0x80085A20: nop

    // 0x80085A24: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80085A28: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80085A2C: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085A30: bne         $at, $zero, L_80085AB4
    if (ctx->r1 != 0) {
        // 0x80085A34: nop

            goto L_80085AB4;
    }
    // 0x80085A34: nop

    // 0x80085A38: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80085A3C: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085A40: beq         $at, $zero, L_80085AB4
    if (ctx->r1 == 0) {
        // 0x80085A44: nop

            goto L_80085AB4;
    }
    // 0x80085A44: nop

    // 0x80085A48: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80085A4C: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80085A50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80085A54: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80085A58: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085A5C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80085A60: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80085A64: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80085A68: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80085A6C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80085A70: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80085A74: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80085A78: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80085A7C: nop

    // 0x80085A80: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80085A84: nop

    // 0x80085A88: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80085A8C: beq         $t4, $zero, L_80085AB4
    if (ctx->r12 == 0) {
        // 0x80085A90: nop

            goto L_80085AB4;
    }
    // 0x80085A90: nop

    // 0x80085A94: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x80085A98: beq         $t5, $zero, L_80085AB4
    if (ctx->r13 == 0) {
        // 0x80085A9C: nop

            goto L_80085AB4;
    }
    // 0x80085A9C: nop

    // 0x80085AA0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80085AA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085AA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085AAC: jal         0x8008B738
    // 0x80085AB0: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80085AB0: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    after_4:
L_80085AB4:
    // 0x80085AB4: b           L_80085ABC
    // 0x80085AB8: nop

        goto L_80085ABC;
    // 0x80085AB8: nop

L_80085ABC:
    // 0x80085ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085AC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80085AC4: jr          $ra
    // 0x80085AC8: nop

    return;
    // 0x80085AC8: nop

;}
RECOMP_FUNC void func_80085ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80085AD8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80085ADC: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80085AE0: jal         0x8008BFF4
    // 0x80085AE4: nop

    func_8008BFF4(rdram, ctx);
        goto after_0;
    // 0x80085AE4: nop

    after_0:
    // 0x80085AE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085AEC: jal         0x80089170
    // 0x80085AF0: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80085AF0: nop

    after_1:
    // 0x80085AF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80085AF8: nop

    // 0x80085AFC: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80085B00: b           L_80085B10
    // 0x80085B04: nop

        goto L_80085B10;
    // 0x80085B04: nop

    // 0x80085B08: b           L_80085B10
    // 0x80085B0C: nop

        goto L_80085B10;
    // 0x80085B0C: nop

L_80085B10:
    // 0x80085B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085B18: jr          $ra
    // 0x80085B1C: nop

    return;
    // 0x80085B1C: nop

;}
RECOMP_FUNC void func_80085B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085B24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80085B28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80085B2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80085B30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80085B34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80085B38: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085B3C: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80085B40: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80085B44: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80085B48: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80085B4C: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80085B50: beq         $t0, $zero, L_80085C14
    if (ctx->r8 == 0) {
        // 0x80085B54: nop

            goto L_80085C14;
    }
    // 0x80085B54: nop

    // 0x80085B58: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80085B5C: jal         0x8008A518
    // 0x80085B60: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80085B60: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80085B64: beq         $v0, $zero, L_80085C14
    if (ctx->r2 == 0) {
        // 0x80085B68: nop

            goto L_80085C14;
    }
    // 0x80085B68: nop

    // 0x80085B6C: lhu         $s0, 0x24($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X24);
    // 0x80085B70: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80085B74: beq         $s0, $at, L_80085B90
    if (ctx->r16 == ctx->r1) {
        // 0x80085B78: nop

            goto L_80085B90;
    }
    // 0x80085B78: nop

    // 0x80085B7C: addiu       $at, $zero, 0x4005
    ctx->r1 = ADD32(0, 0X4005);
    // 0x80085B80: beq         $s0, $at, L_80085BB8
    if (ctx->r16 == ctx->r1) {
        // 0x80085B84: nop

            goto L_80085BB8;
    }
    // 0x80085B84: nop

    // 0x80085B88: b           L_80085C14
    // 0x80085B8C: nop

        goto L_80085C14;
    // 0x80085B8C: nop

L_80085B90:
    // 0x80085B90: jal         0x8008CE48
    // 0x80085B94: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80085B94: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80085B98: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80085B9C: nop

    // 0x80085BA0: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80085BA4: nop

    // 0x80085BA8: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x80085BAC: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80085BB0: b           L_80085C74
    // 0x80085BB4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80085C74;
    // 0x80085BB4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80085BB8:
    // 0x80085BB8: jal         0x8008CE48
    // 0x80085BBC: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80085BBC: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80085BC0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80085BC4: nop

    // 0x80085BC8: lw          $a0, 0xC10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC10);
    // 0x80085BCC: jal         0x8008C854
    // 0x80085BD0: nop

    func_8008C854(rdram, ctx);
        goto after_3;
    // 0x80085BD0: nop

    after_3:
    // 0x80085BD4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80085BD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80085BDC: lh          $t6, 0xBFE($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBFE);
    // 0x80085BE0: nop

    // 0x80085BE4: sh          $t6, 0x7A16($at)
    MEM_H(0X7A16, ctx->r1) = ctx->r14;
    // 0x80085BE8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085BEC: nop

    // 0x80085BF0: sh          $zero, 0xBEC($t7)
    MEM_H(0XBEC, ctx->r15) = 0;
    // 0x80085BF4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80085BF8: nop

    // 0x80085BFC: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x80085C00: nop

    // 0x80085C04: ori         $t0, $t8, 0x200
    ctx->r8 = ctx->r24 | 0X200;
    // 0x80085C08: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x80085C0C: b           L_80085C74
    // 0x80085C10: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80085C74;
    // 0x80085C10: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80085C14:
    // 0x80085C14: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80085C18: lhu         $t3, 0x101C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X101C);
    // 0x80085C1C: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x80085C20: nop

    // 0x80085C24: and         $t1, $t2, $t3
    ctx->r9 = ctx->r10 & ctx->r11;
    // 0x80085C28: beq         $t1, $zero, L_80085C58
    if (ctx->r9 == 0) {
        // 0x80085C2C: nop

            goto L_80085C58;
    }
    // 0x80085C2C: nop

    // 0x80085C30: jal         0x8008CE48
    // 0x80085C34: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x80085C34: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_4:
    // 0x80085C38: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80085C3C: nop

    // 0x80085C40: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80085C44: nop

    // 0x80085C48: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x80085C4C: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80085C50: b           L_80085C74
    // 0x80085C54: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80085C74;
    // 0x80085C54: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80085C58:
    // 0x80085C58: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085C5C: nop

    // 0x80085C60: lh          $v0, 0x4($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X4);
    // 0x80085C64: b           L_80085C74
    // 0x80085C68: nop

        goto L_80085C74;
    // 0x80085C68: nop

    // 0x80085C6C: b           L_80085C74
    // 0x80085C70: nop

        goto L_80085C74;
    // 0x80085C70: nop

L_80085C74:
    // 0x80085C74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80085C78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80085C7C: jr          $ra
    // 0x80085C80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80085C80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80085C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80085C90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085C94: jal         0x8008B4EC
    // 0x80085C98: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80085C98: nop

    after_0:
    // 0x80085C9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CA0: jal         0x8008B600
    // 0x80085CA4: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80085CA4: nop

    after_1:
    // 0x80085CA8: b           L_80085CB0
    // 0x80085CAC: nop

        goto L_80085CB0;
    // 0x80085CAC: nop

L_80085CB0:
    // 0x80085CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085CB8: jr          $ra
    // 0x80085CBC: nop

    return;
    // 0x80085CBC: nop

;}
RECOMP_FUNC void func_80085CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085CC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80085CCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CD0: jal         0x8008A46C
    // 0x80085CD4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80085CD4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80085CD8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80085CDC: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80085CE0: jal         0x8008BFF4
    // 0x80085CE4: nop

    func_8008BFF4(rdram, ctx);
        goto after_1;
    // 0x80085CE4: nop

    after_1:
    // 0x80085CE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CEC: jal         0x80089170
    // 0x80085CF0: nop

    func_80089170(rdram, ctx);
        goto after_2;
    // 0x80085CF0: nop

    after_2:
    // 0x80085CF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80085CF8: jal         0x80089418
    // 0x80085CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80089418(rdram, ctx);
        goto after_3;
    // 0x80085CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80085D00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80085D04: nop

    // 0x80085D08: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80085D0C: b           L_80085D1C
    // 0x80085D10: nop

        goto L_80085D1C;
    // 0x80085D10: nop

    // 0x80085D14: b           L_80085D1C
    // 0x80085D18: nop

        goto L_80085D1C;
    // 0x80085D18: nop

L_80085D1C:
    // 0x80085D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085D24: jr          $ra
    // 0x80085D28: nop

    return;
    // 0x80085D28: nop

;}
RECOMP_FUNC void func_80085D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085D34: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80085D38: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80085D3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80085D40: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085D44: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80085D48: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80085D4C: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80085D50: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80085D54: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80085D58: beq         $t0, $zero, L_80085EC8
    if (ctx->r8 == 0) {
        // 0x80085D5C: nop

            goto L_80085EC8;
    }
    // 0x80085D5C: nop

    // 0x80085D60: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80085D64: jal         0x8008A518
    // 0x80085D68: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80085D68: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80085D6C: beq         $v0, $zero, L_80085EC8
    if (ctx->r2 == 0) {
        // 0x80085D70: nop

            goto L_80085EC8;
    }
    // 0x80085D70: nop

    // 0x80085D74: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x80085D78: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80085D7C: bne         $t1, $at, L_80085D94
    if (ctx->r9 != ctx->r1) {
        // 0x80085D80: nop

            goto L_80085D94;
    }
    // 0x80085D80: nop

    // 0x80085D84: jal         0x8008CE48
    // 0x80085D88: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80085D88: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80085D8C: b           L_80085F10
    // 0x80085D90: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80085F10;
    // 0x80085D90: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80085D94:
    // 0x80085D94: lhu         $t2, 0x24($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X24);
    // 0x80085D98: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80085D9C: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085DA0: bne         $at, $zero, L_80085EC8
    if (ctx->r1 != 0) {
        // 0x80085DA4: nop

            goto L_80085EC8;
    }
    // 0x80085DA4: nop

    // 0x80085DA8: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80085DAC: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085DB0: beq         $at, $zero, L_80085EC8
    if (ctx->r1 == 0) {
        // 0x80085DB4: nop

            goto L_80085EC8;
    }
    // 0x80085DB4: nop

    // 0x80085DB8: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x80085DBC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80085DC0: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80085DC4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80085DC8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80085DCC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80085DD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80085DD4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80085DD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085DDC: addiu       $t7, $t7, 0x7AE8
    ctx->r15 = ADD32(ctx->r15, 0X7AE8);
    // 0x80085DE0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80085DE4: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80085DE8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80085DEC: sh          $t4, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r12;
    // 0x80085DF0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80085DF4: nop

    // 0x80085DF8: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x80085DFC: nop

    // 0x80085E00: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80085E04: beq         $t1, $zero, L_80085EB4
    if (ctx->r9 == 0) {
        // 0x80085E08: nop

            goto L_80085EB4;
    }
    // 0x80085E08: nop

    // 0x80085E0C: lhu         $t2, 0x1E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1E);
    // 0x80085E10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80085E14: sh          $t2, 0x7A16($at)
    MEM_H(0X7A16, ctx->r1) = ctx->r10;
    // 0x80085E18: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80085E1C: nop

    // 0x80085E20: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80085E24: nop

    // 0x80085E28: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x80085E2C: beq         $t5, $zero, L_80085E90
    if (ctx->r13 == 0) {
        // 0x80085E30: nop

            goto L_80085E90;
    }
    // 0x80085E30: nop

    // 0x80085E34: jal         0x8008CE48
    // 0x80085E38: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80085E38: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x80085E3C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80085E40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085E44: addiu       $a0, $a0, -0x6110
    ctx->r4 = ADD32(ctx->r4, -0X6110);
    // 0x80085E48: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80085E4C: jal         0x8008BE0C
    // 0x80085E50: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    func_8008BE0C(rdram, ctx);
        goto after_3;
    // 0x80085E50: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_3:
    // 0x80085E54: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80085E58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085E5C: addiu       $a0, $a0, -0x611C
    ctx->r4 = ADD32(ctx->r4, -0X611C);
    // 0x80085E60: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80085E64: jal         0x8008BE0C
    // 0x80085E68: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    func_8008BE0C(rdram, ctx);
        goto after_4;
    // 0x80085E68: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    after_4:
    // 0x80085E6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80085E70: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80085E74: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80085E78: jal         0x800BCFCC
    // 0x80085E7C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x80085E7C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_5:
    // 0x80085E80: b           L_80085F10
    // 0x80085E84: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_80085F10;
    // 0x80085E84: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x80085E88: b           L_80085EAC
    // 0x80085E8C: nop

        goto L_80085EAC;
    // 0x80085E8C: nop

L_80085E90:
    // 0x80085E90: jal         0x8008CE48
    // 0x80085E94: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80085E94: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_6:
    // 0x80085E98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80085E9C: jal         0x8008C0D8
    // 0x80085EA0: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8008C0D8(rdram, ctx);
        goto after_7;
    // 0x80085EA0: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_7:
    // 0x80085EA4: b           L_80085F10
    // 0x80085EA8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_80085F10;
    // 0x80085EA8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80085EAC:
    // 0x80085EAC: b           L_80085EC8
    // 0x80085EB0: nop

        goto L_80085EC8;
    // 0x80085EB0: nop

L_80085EB4:
    // 0x80085EB4: jal         0x8008CE48
    // 0x80085EB8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80085EB8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_8:
    // 0x80085EBC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80085EC0: jal         0x8008A730
    // 0x80085EC4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_9;
    // 0x80085EC4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_9:
L_80085EC8:
    // 0x80085EC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80085ECC: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x80085ED0: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x80085ED4: nop

    // 0x80085ED8: and         $t9, $t6, $t7
    ctx->r25 = ctx->r14 & ctx->r15;
    // 0x80085EDC: beq         $t9, $zero, L_80085EF4
    if (ctx->r25 == 0) {
        // 0x80085EE0: nop

            goto L_80085EF4;
    }
    // 0x80085EE0: nop

    // 0x80085EE4: jal         0x8008CE48
    // 0x80085EE8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80085EE8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_10:
    // 0x80085EEC: b           L_80085F10
    // 0x80085EF0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80085F10;
    // 0x80085EF0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80085EF4:
    // 0x80085EF4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80085EF8: nop

    // 0x80085EFC: lh          $v0, 0x4($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X4);
    // 0x80085F00: b           L_80085F10
    // 0x80085F04: nop

        goto L_80085F10;
    // 0x80085F04: nop

    // 0x80085F08: b           L_80085F10
    // 0x80085F0C: nop

        goto L_80085F10;
    // 0x80085F0C: nop

L_80085F10:
    // 0x80085F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085F14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80085F18: jr          $ra
    // 0x80085F1C: nop

    return;
    // 0x80085F1C: nop

;}
RECOMP_FUNC void func_80085F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80085F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085F28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80085F2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085F30: jal         0x8008B4EC
    // 0x80085F34: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80085F34: nop

    after_0:
    // 0x80085F38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085F3C: jal         0x8008B600
    // 0x80085F40: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80085F40: nop

    after_1:
    // 0x80085F44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085F4C: jal         0x8008B738
    // 0x80085F50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80085F50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80085F54: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80085F58: jal         0x8008A518
    // 0x80085F5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x80085F5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80085F60: beq         $v0, $zero, L_80085FF8
    if (ctx->r2 == 0) {
        // 0x80085F64: nop

            goto L_80085FF8;
    }
    // 0x80085F64: nop

    // 0x80085F68: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80085F6C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80085F70: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085F74: bne         $at, $zero, L_80085FF8
    if (ctx->r1 != 0) {
        // 0x80085F78: nop

            goto L_80085FF8;
    }
    // 0x80085F78: nop

    // 0x80085F7C: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80085F80: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085F84: beq         $at, $zero, L_80085FF8
    if (ctx->r1 == 0) {
        // 0x80085F88: nop

            goto L_80085FF8;
    }
    // 0x80085F88: nop

    // 0x80085F8C: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80085F90: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80085F94: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80085F98: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80085F9C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085FA0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80085FA4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80085FA8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80085FAC: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80085FB0: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80085FB4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80085FB8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80085FBC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80085FC0: nop

    // 0x80085FC4: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80085FC8: nop

    // 0x80085FCC: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80085FD0: beq         $t4, $zero, L_80085FF8
    if (ctx->r12 == 0) {
        // 0x80085FD4: nop

            goto L_80085FF8;
    }
    // 0x80085FD4: nop

    // 0x80085FD8: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x80085FDC: beq         $t5, $zero, L_80085FF8
    if (ctx->r13 == 0) {
        // 0x80085FE0: nop

            goto L_80085FF8;
    }
    // 0x80085FE0: nop

    // 0x80085FE4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80085FE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085FEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085FF0: jal         0x8008B738
    // 0x80085FF4: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80085FF4: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    after_4:
L_80085FF8:
    // 0x80085FF8: b           L_80086000
    // 0x80085FFC: nop

        goto L_80086000;
    // 0x80085FFC: nop

L_80086000:
    // 0x80086000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086008: jr          $ra
    // 0x8008600C: nop

    return;
    // 0x8008600C: nop

;}
RECOMP_FUNC void func_80086010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008601C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086020: jal         0x8008A46C
    // 0x80086024: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80086024: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80086028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008602C: jal         0x8008BFF4
    // 0x80086030: nop

    func_8008BFF4(rdram, ctx);
        goto after_1;
    // 0x80086030: nop

    after_1:
    // 0x80086034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086038: jal         0x80089170
    // 0x8008603C: nop

    func_80089170(rdram, ctx);
        goto after_2;
    // 0x8008603C: nop

    after_2:
    // 0x80086040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086044: jal         0x80089418
    // 0x80086048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80089418(rdram, ctx);
        goto after_3;
    // 0x80086048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8008604C: b           L_8008605C
    // 0x80086050: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8008605C;
    // 0x80086050: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80086054: b           L_8008605C
    // 0x80086058: nop

        goto L_8008605C;
    // 0x80086058: nop

L_8008605C:
    // 0x8008605C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086064: jr          $ra
    // 0x80086068: nop

    return;
    // 0x80086068: nop

;}
RECOMP_FUNC void func_8008606C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008606C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80086070: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80086074: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80086078: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8008607C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80086080: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80086084: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80086088: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8008608C: lhu         $t9, 0x46($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X46);
    // 0x80086090: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80086094: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80086098: beq         $t0, $zero, L_80086254
    if (ctx->r8 == 0) {
        // 0x8008609C: nop

            goto L_80086254;
    }
    // 0x8008609C: nop

    // 0x800860A0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800860A4: jal         0x8008A518
    // 0x800860A8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800860A8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800860AC: beq         $v0, $zero, L_80086254
    if (ctx->r2 == 0) {
        // 0x800860B0: nop

            goto L_80086254;
    }
    // 0x800860B0: nop

    // 0x800860B4: lhu         $t1, 0x34($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X34);
    // 0x800860B8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x800860BC: bne         $t1, $at, L_800860D4
    if (ctx->r9 != ctx->r1) {
        // 0x800860C0: nop

            goto L_800860D4;
    }
    // 0x800860C0: nop

    // 0x800860C4: jal         0x8008CE48
    // 0x800860C8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x800860C8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x800860CC: b           L_80086290
    // 0x800860D0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086290;
    // 0x800860D0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800860D4:
    // 0x800860D4: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x800860D8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800860DC: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800860E0: bne         $at, $zero, L_80086254
    if (ctx->r1 != 0) {
        // 0x800860E4: nop

            goto L_80086254;
    }
    // 0x800860E4: nop

    // 0x800860E8: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x800860EC: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800860F0: beq         $at, $zero, L_80086254
    if (ctx->r1 == 0) {
        // 0x800860F4: nop

            goto L_80086254;
    }
    // 0x800860F4: nop

    // 0x800860F8: lhu         $t3, 0x34($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X34);
    // 0x800860FC: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086100: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80086104: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80086108: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008610C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80086110: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80086114: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80086118: addiu       $t6, $t6, 0x7AE8
    ctx->r14 = ADD32(ctx->r14, 0X7AE8);
    // 0x8008611C: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80086120: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80086124: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80086128: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008612C: nop

    // 0x80086130: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x80086134: nop

    // 0x80086138: andi        $t0, $t8, 0x8000
    ctx->r8 = ctx->r24 & 0X8000;
    // 0x8008613C: beq         $t0, $zero, L_80086240
    if (ctx->r8 == 0) {
        // 0x80086140: nop

            goto L_80086240;
    }
    // 0x80086140: nop

    // 0x80086144: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80086148: nop

    // 0x8008614C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80086150: nop

    // 0x80086154: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x80086158: beq         $t3, $zero, L_80086224
    if (ctx->r11 == 0) {
        // 0x8008615C: nop

            goto L_80086224;
    }
    // 0x8008615C: nop

    // 0x80086160: jal         0x8008CE48
    // 0x80086164: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80086164: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x80086168: lhu         $t4, 0x34($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X34);
    // 0x8008616C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80086170: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80086174: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80086178: sh          $t5, 0xBE8($t6)
    MEM_H(0XBE8, ctx->r14) = ctx->r13;
    // 0x8008617C: lh          $t7, 0x3C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3C);
    // 0x80086180: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086184: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x80086188: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
    // 0x8008618C: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
    // 0x80086190: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80086194: jal         0x8008A368
    // 0x80086198: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8008A368(rdram, ctx);
        goto after_3;
    // 0x80086198: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8008619C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800861A0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800861A4: jal         0x800898D8
    // 0x800861A8: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800898D8(rdram, ctx);
        goto after_4;
    // 0x800861A8: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_4:
    // 0x800861AC: beq         $v0, $zero, L_800861FC
    if (ctx->r2 == 0) {
        // 0x800861B0: nop

            goto L_800861FC;
    }
    // 0x800861B0: nop

    // 0x800861B4: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x800861B8: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x800861BC: lh          $t1, 0x2C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2C);
    // 0x800861C0: lh          $t2, 0x30($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X30);
    // 0x800861C4: addu        $a1, $t9, $t8
    ctx->r5 = ADD32(ctx->r25, ctx->r24);
    // 0x800861C8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    // 0x800861CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800861D0: bgez        $a1, L_800861E0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800861D4: sra         $t0, $a1, 1
        ctx->r8 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800861E0;
    }
    // 0x800861D4: sra         $t0, $a1, 1
    ctx->r8 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800861D8: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800861DC: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_800861E0:
    // 0x800861E0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800861E4: bgez        $a2, L_800861F4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800861E8: sra         $t3, $a2, 1
        ctx->r11 = S32(SIGNED(ctx->r6) >> 1);
            goto L_800861F4;
    }
    // 0x800861E8: sra         $t3, $a2, 1
    ctx->r11 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800861EC: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x800861F0: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800861F4:
    // 0x800861F4: jal         0x80089B04
    // 0x800861F8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_80089B04(rdram, ctx);
        goto after_5;
    // 0x800861F8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_5:
L_800861FC:
    // 0x800861FC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80086200: nop

    // 0x80086204: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80086208: nop

    // 0x8008620C: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x80086210: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80086214: b           L_80086290
    // 0x80086218: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_80086290;
    // 0x80086218: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8008621C: b           L_80086238
    // 0x80086220: nop

        goto L_80086238;
    // 0x80086220: nop

L_80086224:
    // 0x80086224: jal         0x8008CE48
    // 0x80086228: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80086228: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_6:
    // 0x8008622C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086230: jal         0x8008A730
    // 0x80086234: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_8008A730(rdram, ctx);
        goto after_7;
    // 0x80086234: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_7:
L_80086238:
    // 0x80086238: b           L_80086254
    // 0x8008623C: nop

        goto L_80086254;
    // 0x8008623C: nop

L_80086240:
    // 0x80086240: jal         0x8008CE48
    // 0x80086244: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80086244: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_8:
    // 0x80086248: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8008624C: jal         0x8008A730
    // 0x80086250: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_9;
    // 0x80086250: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_9:
L_80086254:
    // 0x80086254: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80086258: lhu         $t9, 0x101C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X101C);
    // 0x8008625C: lhu         $t7, 0x46($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X46);
    // 0x80086260: nop

    // 0x80086264: and         $t8, $t7, $t9
    ctx->r24 = ctx->r15 & ctx->r25;
    // 0x80086268: beq         $t8, $zero, L_80086280
    if (ctx->r24 == 0) {
        // 0x8008626C: nop

            goto L_80086280;
    }
    // 0x8008626C: nop

    // 0x80086270: jal         0x8008CE48
    // 0x80086274: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80086274: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_10:
    // 0x80086278: b           L_80086290
    // 0x8008627C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086290;
    // 0x8008627C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80086280:
    // 0x80086280: b           L_80086290
    // 0x80086284: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80086290;
    // 0x80086284: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80086288: b           L_80086290
    // 0x8008628C: nop

        goto L_80086290;
    // 0x8008628C: nop

L_80086290:
    // 0x80086290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80086294: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80086298: jr          $ra
    // 0x8008629C: nop

    return;
    // 0x8008629C: nop

;}
RECOMP_FUNC void func_800862A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800862A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800862A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800862AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800862B0: jal         0x8008B4EC
    // 0x800862B4: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800862B4: nop

    after_0:
    // 0x800862B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800862BC: jal         0x8008B600
    // 0x800862C0: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x800862C0: nop

    after_1:
    // 0x800862C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800862C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800862CC: jal         0x8008B738
    // 0x800862D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x800862D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800862D4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800862D8: jal         0x8008A518
    // 0x800862DC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x800862DC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x800862E0: beq         $v0, $zero, L_80086378
    if (ctx->r2 == 0) {
        // 0x800862E4: nop

            goto L_80086378;
    }
    // 0x800862E4: nop

    // 0x800862E8: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x800862EC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800862F0: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800862F4: bne         $at, $zero, L_80086378
    if (ctx->r1 != 0) {
        // 0x800862F8: nop

            goto L_80086378;
    }
    // 0x800862F8: nop

    // 0x800862FC: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80086300: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086304: beq         $at, $zero, L_80086378
    if (ctx->r1 == 0) {
        // 0x80086308: nop

            goto L_80086378;
    }
    // 0x80086308: nop

    // 0x8008630C: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086310: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086314: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086318: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008631C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086320: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086324: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80086328: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008632C: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086330: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80086334: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80086338: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008633C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80086340: nop

    // 0x80086344: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086348: nop

    // 0x8008634C: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80086350: beq         $t4, $zero, L_80086378
    if (ctx->r12 == 0) {
        // 0x80086354: nop

            goto L_80086378;
    }
    // 0x80086354: nop

    // 0x80086358: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x8008635C: beq         $t5, $zero, L_80086378
    if (ctx->r13 == 0) {
        // 0x80086360: nop

            goto L_80086378;
    }
    // 0x80086360: nop

    // 0x80086364: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80086368: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008636C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086370: jal         0x8008B738
    // 0x80086374: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80086374: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    after_4:
L_80086378:
    // 0x80086378: b           L_80086380
    // 0x8008637C: nop

        goto L_80086380;
    // 0x8008637C: nop

L_80086380:
    // 0x80086380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086384: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086388: jr          $ra
    // 0x8008638C: nop

    return;
    // 0x8008638C: nop

;}
RECOMP_FUNC void func_80086390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086398: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008639C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800863A0: jal         0x8008BFF4
    // 0x800863A4: nop

    func_8008BFF4(rdram, ctx);
        goto after_0;
    // 0x800863A4: nop

    after_0:
    // 0x800863A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800863AC: jal         0x80089170
    // 0x800863B0: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x800863B0: nop

    after_1:
    // 0x800863B4: b           L_800863C4
    // 0x800863B8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_800863C4;
    // 0x800863B8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800863BC: b           L_800863C4
    // 0x800863C0: nop

        goto L_800863C4;
    // 0x800863C0: nop

L_800863C4:
    // 0x800863C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800863C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800863CC: jr          $ra
    // 0x800863D0: nop

    return;
    // 0x800863D0: nop

;}
RECOMP_FUNC void func_800863D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800863D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800863DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800863E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800863E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800863E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800863EC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800863F0: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x800863F4: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x800863F8: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x800863FC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80086400: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80086404: beq         $t0, $zero, L_800864B0
    if (ctx->r8 == 0) {
        // 0x80086408: nop

            goto L_800864B0;
    }
    // 0x80086408: nop

    // 0x8008640C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80086410: jal         0x8008A518
    // 0x80086414: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80086414: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80086418: beq         $v0, $zero, L_800864B0
    if (ctx->r2 == 0) {
        // 0x8008641C: nop

            goto L_800864B0;
    }
    // 0x8008641C: nop

    // 0x80086420: lhu         $s0, 0x24($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X24);
    // 0x80086424: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80086428: beq         $s0, $at, L_800864A0
    if (ctx->r16 == ctx->r1) {
        // 0x8008642C: nop

            goto L_800864A0;
    }
    // 0x8008642C: nop

    // 0x80086430: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80086434: beq         $s0, $at, L_80086478
    if (ctx->r16 == ctx->r1) {
        // 0x80086438: nop

            goto L_80086478;
    }
    // 0x80086438: nop

    // 0x8008643C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80086440: beq         $s0, $at, L_80086450
    if (ctx->r16 == ctx->r1) {
        // 0x80086444: nop

            goto L_80086450;
    }
    // 0x80086444: nop

    // 0x80086448: b           L_800864B0
    // 0x8008644C: nop

        goto L_800864B0;
    // 0x8008644C: nop

L_80086450:
    // 0x80086450: jal         0x8008CE48
    // 0x80086454: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80086454: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80086458: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8008645C: nop

    // 0x80086460: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80086464: nop

    // 0x80086468: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x8008646C: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80086470: b           L_80086504
    // 0x80086474: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_80086504;
    // 0x80086474: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_80086478:
    // 0x80086478: jal         0x8008CE48
    // 0x8008647C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x8008647C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_2:
    // 0x80086480: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80086484: nop

    // 0x80086488: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8008648C: nop

    // 0x80086490: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x80086494: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80086498: b           L_80086504
    // 0x8008649C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80086504;
    // 0x8008649C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800864A0:
    // 0x800864A0: jal         0x8008CE48
    // 0x800864A4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x800864A4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x800864A8: b           L_80086504
    // 0x800864AC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086504;
    // 0x800864AC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800864B0:
    // 0x800864B0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800864B4: lhu         $t9, 0x101C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X101C);
    // 0x800864B8: lhu         $t7, 0x36($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X36);
    // 0x800864BC: nop

    // 0x800864C0: and         $t8, $t7, $t9
    ctx->r24 = ctx->r15 & ctx->r25;
    // 0x800864C4: beq         $t8, $zero, L_800864F4
    if (ctx->r24 == 0) {
        // 0x800864C8: nop

            goto L_800864F4;
    }
    // 0x800864C8: nop

    // 0x800864CC: jal         0x8008CE48
    // 0x800864D0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x800864D0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_4:
    // 0x800864D4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800864D8: nop

    // 0x800864DC: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x800864E0: nop

    // 0x800864E4: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x800864E8: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x800864EC: b           L_80086504
    // 0x800864F0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80086504;
    // 0x800864F0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800864F4:
    // 0x800864F4: b           L_80086504
    // 0x800864F8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_80086504;
    // 0x800864F8: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800864FC: b           L_80086504
    // 0x80086500: nop

        goto L_80086504;
    // 0x80086500: nop

L_80086504:
    // 0x80086504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80086508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008650C: jr          $ra
    // 0x80086510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80086510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80086514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008651C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086524: jal         0x8008B4EC
    // 0x80086528: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80086528: nop

    after_0:
    // 0x8008652C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086530: jal         0x8008B600
    // 0x80086534: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80086534: nop

    after_1:
    // 0x80086538: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008653C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80086540: lh          $t7, 0xBE8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XBE8);
    // 0x80086544: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086548: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008654C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086550: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086554: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086558: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8008655C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x80086560: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80086564: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086568: jal         0x8008B738
    // 0x8008656C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x8008656C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x80086570: b           L_80086578
    // 0x80086574: nop

        goto L_80086578;
    // 0x80086574: nop

L_80086578:
    // 0x80086578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008657C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086580: jr          $ra
    // 0x80086584: nop

    return;
    // 0x80086584: nop

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
RECOMP_FUNC void func_80086600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086600: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80086608: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008660C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80086610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80086614: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80086618: nop

    // 0x8008661C: lh          $s0, 0xC14($t6)
    ctx->r16 = MEM_H(ctx->r14, 0XC14);
    // 0x80086620: nop

    // 0x80086624: beq         $s0, $zero, L_80086640
    if (ctx->r16 == 0) {
        // 0x80086628: nop

            goto L_80086640;
    }
    // 0x80086628: nop

    // 0x8008662C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086630: beq         $s0, $at, L_800866D8
    if (ctx->r16 == ctx->r1) {
        // 0x80086634: nop

            goto L_800866D8;
    }
    // 0x80086634: nop

    // 0x80086638: b           L_800867C4
    // 0x8008663C: nop

        goto L_800867C4;
    // 0x8008663C: nop

L_80086640:
    // 0x80086640: jal         0x800AEBF4
    // 0x80086644: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_0;
    // 0x80086644: nop

    after_0:
    // 0x80086648: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008664C: nop

    // 0x80086650: sw          $v0, 0xC00($t7)
    MEM_W(0XC00, ctx->r15) = ctx->r2;
    // 0x80086654: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80086658: nop

    // 0x8008665C: lw          $t9, 0xC00($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC00);
    // 0x80086660: nop

    // 0x80086664: bltz        $t9, L_800866A0
    if (SIGNED(ctx->r25) < 0) {
        // 0x80086668: nop

            goto L_800866A0;
    }
    // 0x80086668: nop

    // 0x8008666C: slti        $at, $t9, 0x1000
    ctx->r1 = SIGNED(ctx->r25) < 0X1000 ? 1 : 0;
    // 0x80086670: beq         $at, $zero, L_800866A0
    if (ctx->r1 == 0) {
        // 0x80086674: nop

            goto L_800866A0;
    }
    // 0x80086674: nop

    // 0x80086678: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008667C: nop

    // 0x80086680: lw          $a0, 0xC00($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC00);
    // 0x80086684: jal         0x800AE5F0
    // 0x80086688: nop

    ContPak_SetFileDeleteParams(rdram, ctx);
        goto after_1;
    // 0x80086688: nop

    after_1:
    // 0x8008668C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80086690: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80086694: sh          $t1, 0xC14($t2)
    MEM_H(0XC14, ctx->r10) = ctx->r9;
    // 0x80086698: b           L_800867C4
    // 0x8008669C: nop

        goto L_800867C4;
    // 0x8008669C: nop

L_800866A0:
    // 0x800866A0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800866A4: nop

    // 0x800866A8: lw          $t4, 0xC00($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC00);
    // 0x800866AC: nop

    // 0x800866B0: slti        $at, $t4, 0x1000
    ctx->r1 = SIGNED(ctx->r12) < 0X1000 ? 1 : 0;
    // 0x800866B4: bne         $at, $zero, L_800866D0
    if (ctx->r1 != 0) {
        // 0x800866B8: nop

            goto L_800866D0;
    }
    // 0x800866B8: nop

    // 0x800866BC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800866C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800866C4: sh          $t5, 0xBEC($t6)
    MEM_H(0XBEC, ctx->r14) = ctx->r13;
    // 0x800866C8: b           L_800867E0
    // 0x800866CC: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800867E0;
    // 0x800866CC: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_800866D0:
    // 0x800866D0: b           L_800867C4
    // 0x800866D4: nop

        goto L_800867C4;
    // 0x800866D4: nop

L_800866D8:
    // 0x800866D8: jal         0x800AE7FC
    // 0x800866DC: nop

    ContPak_GetDeleteFileResult(rdram, ctx);
        goto after_2;
    // 0x800866DC: nop

    after_2:
    // 0x800866E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800866E4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800866E8: nop

    // 0x800866EC: bne         $t7, $zero, L_8008679C
    if (ctx->r15 != 0) {
        // 0x800866F0: nop

            goto L_8008679C;
    }
    // 0x800866F0: nop

    // 0x800866F4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800866F8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800866FC: lh          $t9, 0xBE8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XBE8);
    // 0x80086700: addiu       $t1, $t1, 0x7AE8
    ctx->r9 = ADD32(ctx->r9, 0X7AE8);
    // 0x80086704: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80086708: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8008670C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80086710: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80086714: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80086718: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8008671C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086720: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80086724: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80086728: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x8008672C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80086730: nop

    // 0x80086734: lh          $t6, 0xBE8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBE8);
    // 0x80086738: nop

    // 0x8008673C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80086740: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80086744: lw          $t9, 0xC04($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC04);
    // 0x80086748: nop

    // 0x8008674C: beq         $t9, $zero, L_80086794
    if (ctx->r25 == 0) {
        // 0x80086750: nop

            goto L_80086794;
    }
    // 0x80086750: nop

    // 0x80086754: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80086758: nop

    // 0x8008675C: lh          $t1, 0xBE8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XBE8);
    // 0x80086760: nop

    // 0x80086764: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80086768: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008676C: lw          $a0, 0xC04($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC04);
    // 0x80086770: jal         0x800BC980
    // 0x80086774: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80086774: nop

    after_3:
    // 0x80086778: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008677C: nop

    // 0x80086780: lh          $t6, 0xBE8($t2)
    ctx->r14 = MEM_H(ctx->r10, 0XBE8);
    // 0x80086784: nop

    // 0x80086788: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8008678C: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x80086790: sw          $zero, 0xC04($t7)
    MEM_W(0XC04, ctx->r15) = 0;
L_80086794:
    // 0x80086794: b           L_800867E0
    // 0x80086798: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_800867E0;
    // 0x80086798: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8008679C:
    // 0x8008679C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800867A0: nop

    // 0x800867A4: slti        $at, $t8, 0x1000
    ctx->r1 = SIGNED(ctx->r24) < 0X1000 ? 1 : 0;
    // 0x800867A8: bne         $at, $zero, L_800867C4
    if (ctx->r1 != 0) {
        // 0x800867AC: nop

            goto L_800867C4;
    }
    // 0x800867AC: nop

    // 0x800867B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800867B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800867B8: sh          $t9, 0xBEC($t1)
    MEM_H(0XBEC, ctx->r9) = ctx->r25;
    // 0x800867BC: b           L_800867E0
    // 0x800867C0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_800867E0;
    // 0x800867C0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_800867C4:
    // 0x800867C4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800867C8: nop

    // 0x800867CC: lh          $v0, 0x4($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X4);
    // 0x800867D0: b           L_800867E0
    // 0x800867D4: nop

        goto L_800867E0;
    // 0x800867D4: nop

    // 0x800867D8: b           L_800867E0
    // 0x800867DC: nop

        goto L_800867E0;
    // 0x800867DC: nop

L_800867E0:
    // 0x800867E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800867E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800867E8: jr          $ra
    // 0x800867EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800867EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800867F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800867F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800867F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800867FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086800: jal         0x8008B4EC
    // 0x80086804: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80086804: nop

    after_0:
    // 0x80086808: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008680C: jal         0x8008B600
    // 0x80086810: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80086810: nop

    after_1:
    // 0x80086814: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80086818: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008681C: lh          $t7, 0xBE8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XBE8);
    // 0x80086820: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086824: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086828: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008682C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086830: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086834: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80086838: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x8008683C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80086840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086844: jal         0x8008B738
    // 0x80086848: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80086848: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x8008684C: b           L_80086854
    // 0x80086850: nop

        goto L_80086854;
    // 0x80086850: nop

L_80086854:
    // 0x80086854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008685C: jr          $ra
    // 0x80086860: nop

    return;
    // 0x80086860: nop

;}
RECOMP_FUNC void func_80086864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008686C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086874: jal         0x8008A46C
    // 0x80086878: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80086878: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x8008687C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086880: jal         0x8008BFF4
    // 0x80086884: nop

    func_8008BFF4(rdram, ctx);
        goto after_1;
    // 0x80086884: nop

    after_1:
    // 0x80086888: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008688C: jal         0x80089170
    // 0x80086890: nop

    func_80089170(rdram, ctx);
        goto after_2;
    // 0x80086890: nop

    after_2:
    // 0x80086894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086898: jal         0x80089418
    // 0x8008689C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80089418(rdram, ctx);
        goto after_3;
    // 0x8008689C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800868A0: b           L_800868B0
    // 0x800868A4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_800868B0;
    // 0x800868A4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800868A8: b           L_800868B0
    // 0x800868AC: nop

        goto L_800868B0;
    // 0x800868AC: nop

L_800868B0:
    // 0x800868B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800868B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800868B8: jr          $ra
    // 0x800868BC: nop

    return;
    // 0x800868BC: nop

;}
RECOMP_FUNC void func_800868C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800868C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800868C8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800868CC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800868D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800868D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800868D8: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x800868DC: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x800868E0: lhu         $t9, 0x46($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X46);
    // 0x800868E4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800868E8: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x800868EC: beq         $t0, $zero, L_80086A48
    if (ctx->r8 == 0) {
        // 0x800868F0: nop

            goto L_80086A48;
    }
    // 0x800868F0: nop

    // 0x800868F4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800868F8: jal         0x8008A518
    // 0x800868FC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800868FC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80086900: beq         $v0, $zero, L_80086A48
    if (ctx->r2 == 0) {
        // 0x80086904: nop

            goto L_80086A48;
    }
    // 0x80086904: nop

    // 0x80086908: lhu         $t1, 0x34($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X34);
    // 0x8008690C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80086910: bne         $t1, $at, L_80086928
    if (ctx->r9 != ctx->r1) {
        // 0x80086914: nop

            goto L_80086928;
    }
    // 0x80086914: nop

    // 0x80086918: jal         0x8008CE48
    // 0x8008691C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x8008691C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80086920: b           L_80086A84
    // 0x80086924: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086A84;
    // 0x80086924: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80086928:
    // 0x80086928: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x8008692C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80086930: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086934: bne         $at, $zero, L_80086A48
    if (ctx->r1 != 0) {
        // 0x80086938: nop

            goto L_80086A48;
    }
    // 0x80086938: nop

    // 0x8008693C: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80086940: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086944: beq         $at, $zero, L_80086A48
    if (ctx->r1 == 0) {
        // 0x80086948: nop

            goto L_80086A48;
    }
    // 0x80086948: nop

    // 0x8008694C: lhu         $t3, 0x34($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X34);
    // 0x80086950: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086954: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80086958: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8008695C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80086960: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80086964: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80086968: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008696C: addiu       $t6, $t6, 0x7AE8
    ctx->r14 = ADD32(ctx->r14, 0X7AE8);
    // 0x80086970: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80086974: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80086978: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8008697C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80086980: nop

    // 0x80086984: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x80086988: nop

    // 0x8008698C: andi        $t0, $t8, 0x8000
    ctx->r8 = ctx->r24 & 0X8000;
    // 0x80086990: beq         $t0, $zero, L_80086A34
    if (ctx->r8 == 0) {
        // 0x80086994: nop

            goto L_80086A34;
    }
    // 0x80086994: nop

    // 0x80086998: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8008699C: nop

    // 0x800869A0: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800869A4: nop

    // 0x800869A8: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800869AC: beq         $t3, $zero, L_80086A18
    if (ctx->r11 == 0) {
        // 0x800869B0: nop

            goto L_80086A18;
    }
    // 0x800869B0: nop

    // 0x800869B4: jal         0x8008CE48
    // 0x800869B8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x800869B8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x800869BC: lh          $t4, 0x3C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3C);
    // 0x800869C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800869C4: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x800869C8: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
    // 0x800869CC: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
    // 0x800869D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800869D4: jal         0x8008A368
    // 0x800869D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8008A368(rdram, ctx);
        goto after_3;
    // 0x800869D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x800869DC: lhu         $t5, 0x34($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X34);
    // 0x800869E0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800869E4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800869E8: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x800869EC: sh          $t6, 0xBE8($t7)
    MEM_H(0XBE8, ctx->r15) = ctx->r14;
    // 0x800869F0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800869F4: nop

    // 0x800869F8: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x800869FC: nop

    // 0x80086A00: ori         $t0, $t8, 0x200
    ctx->r8 = ctx->r24 | 0X200;
    // 0x80086A04: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x80086A08: b           L_80086A84
    // 0x80086A0C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80086A84;
    // 0x80086A0C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80086A10: b           L_80086A2C
    // 0x80086A14: nop

        goto L_80086A2C;
    // 0x80086A14: nop

L_80086A18:
    // 0x80086A18: jal         0x8008CE48
    // 0x80086A1C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x80086A1C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_4:
    // 0x80086A20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086A24: jal         0x8008A730
    // 0x80086A28: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_8008A730(rdram, ctx);
        goto after_5;
    // 0x80086A28: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_5:
L_80086A2C:
    // 0x80086A2C: b           L_80086A48
    // 0x80086A30: nop

        goto L_80086A48;
    // 0x80086A30: nop

L_80086A34:
    // 0x80086A34: jal         0x8008CE48
    // 0x80086A38: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80086A38: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_6:
    // 0x80086A3C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086A40: jal         0x8008A730
    // 0x80086A44: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_7;
    // 0x80086A44: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_7:
L_80086A48:
    // 0x80086A48: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80086A4C: lhu         $t2, 0x101C($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X101C);
    // 0x80086A50: lhu         $t1, 0x46($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X46);
    // 0x80086A54: nop

    // 0x80086A58: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80086A5C: beq         $t3, $zero, L_80086A74
    if (ctx->r11 == 0) {
        // 0x80086A60: nop

            goto L_80086A74;
    }
    // 0x80086A60: nop

    // 0x80086A64: jal         0x8008CE48
    // 0x80086A68: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80086A68: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_8:
    // 0x80086A6C: b           L_80086A84
    // 0x80086A70: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086A84;
    // 0x80086A70: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80086A74:
    // 0x80086A74: b           L_80086A84
    // 0x80086A78: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80086A84;
    // 0x80086A78: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80086A7C: b           L_80086A84
    // 0x80086A80: nop

        goto L_80086A84;
    // 0x80086A80: nop

L_80086A84:
    // 0x80086A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80086A88: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80086A8C: jr          $ra
    // 0x80086A90: nop

    return;
    // 0x80086A90: nop

;}
RECOMP_FUNC void func_80086A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086A9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80086AA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086AA4: jal         0x8008B4EC
    // 0x80086AA8: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80086AA8: nop

    after_0:
    // 0x80086AAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086AB0: jal         0x8008B600
    // 0x80086AB4: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80086AB4: nop

    after_1:
    // 0x80086AB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80086AC0: jal         0x8008B738
    // 0x80086AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80086AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80086AC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80086ACC: jal         0x8008A518
    // 0x80086AD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x80086AD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80086AD4: beq         $v0, $zero, L_80086B6C
    if (ctx->r2 == 0) {
        // 0x80086AD8: nop

            goto L_80086B6C;
    }
    // 0x80086AD8: nop

    // 0x80086ADC: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086AE0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80086AE4: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086AE8: bne         $at, $zero, L_80086B6C
    if (ctx->r1 != 0) {
        // 0x80086AEC: nop

            goto L_80086B6C;
    }
    // 0x80086AEC: nop

    // 0x80086AF0: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80086AF4: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086AF8: beq         $at, $zero, L_80086B6C
    if (ctx->r1 == 0) {
        // 0x80086AFC: nop

            goto L_80086B6C;
    }
    // 0x80086AFC: nop

    // 0x80086B00: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086B04: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086B08: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086B0C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086B10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086B14: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086B18: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80086B1C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80086B20: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086B24: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80086B28: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80086B2C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80086B30: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80086B34: nop

    // 0x80086B38: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086B3C: nop

    // 0x80086B40: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80086B44: beq         $t4, $zero, L_80086B6C
    if (ctx->r12 == 0) {
        // 0x80086B48: nop

            goto L_80086B6C;
    }
    // 0x80086B48: nop

    // 0x80086B4C: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x80086B50: beq         $t5, $zero, L_80086B6C
    if (ctx->r13 == 0) {
        // 0x80086B54: nop

            goto L_80086B6C;
    }
    // 0x80086B54: nop

    // 0x80086B58: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80086B5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086B60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086B64: jal         0x8008B738
    // 0x80086B68: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80086B68: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    after_4:
L_80086B6C:
    // 0x80086B6C: b           L_80086B74
    // 0x80086B70: nop

        goto L_80086B74;
    // 0x80086B70: nop

L_80086B74:
    // 0x80086B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086B7C: jr          $ra
    // 0x80086B80: nop

    return;
    // 0x80086B80: nop

;}
RECOMP_FUNC void func_80086B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086B8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086B94: jal         0x8008A46C
    // 0x80086B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80086B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80086B9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086BA0: jal         0x8008A46C
    // 0x80086BA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008A46C(rdram, ctx);
        goto after_1;
    // 0x80086BA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80086BA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086BAC: jal         0x8008BFF4
    // 0x80086BB0: nop

    func_8008BFF4(rdram, ctx);
        goto after_2;
    // 0x80086BB0: nop

    after_2:
    // 0x80086BB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086BB8: jal         0x80089170
    // 0x80086BBC: nop

    func_80089170(rdram, ctx);
        goto after_3;
    // 0x80086BBC: nop

    after_3:
    // 0x80086BC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086BC4: jal         0x80089418
    // 0x80086BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80089418(rdram, ctx);
        goto after_4;
    // 0x80086BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80086BCC: b           L_80086BDC
    // 0x80086BD0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80086BDC;
    // 0x80086BD0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80086BD4: b           L_80086BDC
    // 0x80086BD8: nop

        goto L_80086BDC;
    // 0x80086BD8: nop

L_80086BDC:
    // 0x80086BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086BE4: jr          $ra
    // 0x80086BE8: nop

    return;
    // 0x80086BE8: nop

;}
RECOMP_FUNC void func_80086BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80086BF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80086BF4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80086BF8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80086BFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80086C00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80086C04: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80086C08: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80086C0C: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80086C10: lhu         $t9, 0x4E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4E);
    // 0x80086C14: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80086C18: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80086C1C: beq         $t0, $zero, L_80086E00
    if (ctx->r8 == 0) {
        // 0x80086C20: nop

            goto L_80086E00;
    }
    // 0x80086C20: nop

    // 0x80086C24: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80086C28: jal         0x8008A518
    // 0x80086C2C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80086C2C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80086C30: beq         $v0, $zero, L_80086E00
    if (ctx->r2 == 0) {
        // 0x80086C34: nop

            goto L_80086E00;
    }
    // 0x80086C34: nop

    // 0x80086C38: lhu         $t1, 0x3C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X3C);
    // 0x80086C3C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80086C40: bne         $t1, $at, L_80086C70
    if (ctx->r9 != ctx->r1) {
        // 0x80086C44: nop

            goto L_80086C70;
    }
    // 0x80086C44: nop

    // 0x80086C48: jal         0x8008CE48
    // 0x80086C4C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80086C4C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80086C50: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80086C54: nop

    // 0x80086C58: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086C5C: nop

    // 0x80086C60: ori         $t4, $t3, 0x200
    ctx->r12 = ctx->r11 | 0X200;
    // 0x80086C64: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80086C68: b           L_80086E54
    // 0x80086C6C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80086E54;
    // 0x80086C6C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80086C70:
    // 0x80086C70: lhu         $t5, 0x3C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X3C);
    // 0x80086C74: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80086C78: slt         $at, $t5, $at
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086C7C: bne         $at, $zero, L_80086E00
    if (ctx->r1 != 0) {
        // 0x80086C80: nop

            goto L_80086E00;
    }
    // 0x80086C80: nop

    // 0x80086C84: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80086C88: slt         $at, $t5, $at
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086C8C: beq         $at, $zero, L_80086E00
    if (ctx->r1 == 0) {
        // 0x80086C90: nop

            goto L_80086E00;
    }
    // 0x80086C90: nop

    // 0x80086C94: lhu         $t6, 0x3C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3C);
    // 0x80086C98: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086C9C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80086CA0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80086CA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80086CA8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80086CAC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80086CB0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80086CB4: addiu       $t8, $t8, 0x7AE8
    ctx->r24 = ADD32(ctx->r24, 0X7AE8);
    // 0x80086CB8: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x80086CBC: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80086CC0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80086CC4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80086CC8: nop

    // 0x80086CCC: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80086CD0: nop

    // 0x80086CD4: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80086CD8: beq         $t4, $zero, L_80086DEC
    if (ctx->r12 == 0) {
        // 0x80086CDC: nop

            goto L_80086DEC;
    }
    // 0x80086CDC: nop

    // 0x80086CE0: lhu         $s0, 0x3C($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X3C);
    // 0x80086CE4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80086CE8: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x80086CEC: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x80086CF0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80086CF4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80086CF8: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80086CFC: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80086D00: sh          $s0, 0xBEA($t6)
    MEM_H(0XBEA, ctx->r14) = ctx->r16;
    // 0x80086D04: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80086D08: nop

    // 0x80086D0C: lh          $t9, 0xBE8($t7)
    ctx->r25 = MEM_H(ctx->r15, 0XBE8);
    // 0x80086D10: nop

    // 0x80086D14: bne         $s0, $t9, L_80086D38
    if (ctx->r16 != ctx->r25) {
        // 0x80086D18: nop

            goto L_80086D38;
    }
    // 0x80086D18: nop

    // 0x80086D1C: jal         0x8008CE48
    // 0x80086D20: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80086D20: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x80086D24: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80086D28: jal         0x8008A730
    // 0x80086D2C: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    func_8008A730(rdram, ctx);
        goto after_3;
    // 0x80086D2C: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_3:
    // 0x80086D30: b           L_80086DE4
    // 0x80086D34: nop

        goto L_80086DE4;
    // 0x80086D34: nop

L_80086D38:
    // 0x80086D38: jal         0x8008CE48
    // 0x80086D3C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x80086D3C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x80086D40: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80086D44: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80086D48: jal         0x800898D8
    // 0x80086D4C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800898D8(rdram, ctx);
        goto after_5;
    // 0x80086D4C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_5:
    // 0x80086D50: beq         $v0, $zero, L_80086DA0
    if (ctx->r2 == 0) {
        // 0x80086D54: nop

            goto L_80086DA0;
    }
    // 0x80086D54: nop

    // 0x80086D58: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x80086D5C: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x80086D60: lh          $t3, 0x34($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X34);
    // 0x80086D64: lh          $t4, 0x38($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X38);
    // 0x80086D68: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x80086D6C: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80086D70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80086D74: bgez        $a1, L_80086D84
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80086D78: sra         $t1, $a1, 1
        ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80086D84;
    }
    // 0x80086D78: sra         $t1, $a1, 1
    ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80086D7C: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80086D80: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80086D84:
    // 0x80086D84: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80086D88: bgez        $a2, L_80086D98
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80086D8C: sra         $t2, $a2, 1
        ctx->r10 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80086D98;
    }
    // 0x80086D8C: sra         $t2, $a2, 1
    ctx->r10 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80086D90: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80086D94: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_80086D98:
    // 0x80086D98: jal         0x80089B04
    // 0x80086D9C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    func_80089B04(rdram, ctx);
        goto after_6;
    // 0x80086D9C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_6:
L_80086DA0:
    // 0x80086DA0: lh          $t5, 0x44($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X44);
    // 0x80086DA4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80086DA8: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    // 0x80086DAC: lh          $a2, 0x40($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X40);
    // 0x80086DB0: lh          $a3, 0x42($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X42);
    // 0x80086DB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80086DB8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80086DBC: jal         0x8008A368
    // 0x80086DC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8008A368(rdram, ctx);
        goto after_7;
    // 0x80086DC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x80086DC4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80086DC8: nop

    // 0x80086DCC: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x80086DD0: nop

    // 0x80086DD4: ori         $t8, $t9, 0x200
    ctx->r24 = ctx->r25 | 0X200;
    // 0x80086DD8: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x80086DDC: b           L_80086E54
    // 0x80086DE0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80086E54;
    // 0x80086DE0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80086DE4:
    // 0x80086DE4: b           L_80086E00
    // 0x80086DE8: nop

        goto L_80086E00;
    // 0x80086DE8: nop

L_80086DEC:
    // 0x80086DEC: jal         0x8008CE48
    // 0x80086DF0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80086DF0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_8:
    // 0x80086DF4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80086DF8: jal         0x8008A730
    // 0x80086DFC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_9;
    // 0x80086DFC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_9:
L_80086E00:
    // 0x80086E00: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80086E04: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x80086E08: lhu         $t0, 0x4E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4E);
    // 0x80086E0C: nop

    // 0x80086E10: and         $t3, $t0, $t1
    ctx->r11 = ctx->r8 & ctx->r9;
    // 0x80086E14: beq         $t3, $zero, L_80086E44
    if (ctx->r11 == 0) {
        // 0x80086E18: nop

            goto L_80086E44;
    }
    // 0x80086E18: nop

    // 0x80086E1C: jal         0x8008CE48
    // 0x80086E20: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80086E20: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_10:
    // 0x80086E24: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80086E28: nop

    // 0x80086E2C: lhu         $t2, 0x0($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X0);
    // 0x80086E30: nop

    // 0x80086E34: ori         $t5, $t2, 0x200
    ctx->r13 = ctx->r10 | 0X200;
    // 0x80086E38: sh          $t5, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r13;
    // 0x80086E3C: b           L_80086E54
    // 0x80086E40: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80086E54;
    // 0x80086E40: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80086E44:
    // 0x80086E44: b           L_80086E54
    // 0x80086E48: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80086E54;
    // 0x80086E48: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80086E4C: b           L_80086E54
    // 0x80086E50: nop

        goto L_80086E54;
    // 0x80086E50: nop

L_80086E54:
    // 0x80086E54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80086E58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80086E5C: jr          $ra
    // 0x80086E60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80086E60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80086E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086E6C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80086E70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086E74: jal         0x8008B4EC
    // 0x80086E78: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80086E78: nop

    after_0:
    // 0x80086E7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086E80: jal         0x8008B600
    // 0x80086E84: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80086E84: nop

    after_1:
    // 0x80086E88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80086E90: jal         0x8008B738
    // 0x80086E94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80086E94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80086E98: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80086E9C: jal         0x8008A518
    // 0x80086EA0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x80086EA0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80086EA4: beq         $v0, $zero, L_80086F3C
    if (ctx->r2 == 0) {
        // 0x80086EA8: nop

            goto L_80086F3C;
    }
    // 0x80086EA8: nop

    // 0x80086EAC: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086EB0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80086EB4: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086EB8: bne         $at, $zero, L_80086F3C
    if (ctx->r1 != 0) {
        // 0x80086EBC: nop

            goto L_80086F3C;
    }
    // 0x80086EBC: nop

    // 0x80086EC0: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80086EC4: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80086EC8: beq         $at, $zero, L_80086F3C
    if (ctx->r1 == 0) {
        // 0x80086ECC: nop

            goto L_80086F3C;
    }
    // 0x80086ECC: nop

    // 0x80086ED0: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80086ED4: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086ED8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086EDC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086EE0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086EE4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086EE8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80086EEC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80086EF0: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086EF4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80086EF8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80086EFC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80086F00: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80086F04: nop

    // 0x80086F08: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80086F0C: nop

    // 0x80086F10: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80086F14: beq         $t4, $zero, L_80086F3C
    if (ctx->r12 == 0) {
        // 0x80086F18: nop

            goto L_80086F3C;
    }
    // 0x80086F18: nop

    // 0x80086F1C: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x80086F20: beq         $t5, $zero, L_80086F3C
    if (ctx->r13 == 0) {
        // 0x80086F24: nop

            goto L_80086F3C;
    }
    // 0x80086F24: nop

    // 0x80086F28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80086F2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80086F30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086F34: jal         0x8008B738
    // 0x80086F38: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80086F38: addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    after_4:
L_80086F3C:
    // 0x80086F3C: b           L_80086F44
    // 0x80086F40: nop

        goto L_80086F44;
    // 0x80086F40: nop

L_80086F44:
    // 0x80086F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086F4C: jr          $ra
    // 0x80086F50: nop

    return;
    // 0x80086F50: nop

;}
RECOMP_FUNC void func_80086F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086F60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086F64: jal         0x8008BFF4
    // 0x80086F68: nop

    func_8008BFF4(rdram, ctx);
        goto after_0;
    // 0x80086F68: nop

    after_0:
    // 0x80086F6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086F70: jal         0x80089170
    // 0x80086F74: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80086F74: nop

    after_1:
    // 0x80086F78: b           L_80086F88
    // 0x80086F7C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80086F88;
    // 0x80086F7C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80086F80: b           L_80086F88
    // 0x80086F84: nop

        goto L_80086F88;
    // 0x80086F84: nop

L_80086F88:
    // 0x80086F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086F90: jr          $ra
    // 0x80086F94: nop

    return;
    // 0x80086F94: nop

;}
RECOMP_FUNC void func_80086F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F98: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80086F9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80086FA0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80086FA4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80086FA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80086FAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80086FB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80086FB4: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80086FB8: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80086FBC: lhu         $t9, 0x46($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X46);
    // 0x80086FC0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80086FC4: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80086FC8: beq         $t0, $zero, L_80087058
    if (ctx->r8 == 0) {
        // 0x80086FCC: nop

            goto L_80087058;
    }
    // 0x80086FCC: nop

    // 0x80086FD0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80086FD4: jal         0x8008A518
    // 0x80086FD8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80086FD8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80086FDC: beq         $v0, $zero, L_80087058
    if (ctx->r2 == 0) {
        // 0x80086FE0: nop

            goto L_80087058;
    }
    // 0x80086FE0: nop

    // 0x80086FE4: lhu         $s0, 0x34($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X34);
    // 0x80086FE8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80086FEC: beq         $s0, $at, L_80087008
    if (ctx->r16 == ctx->r1) {
        // 0x80086FF0: nop

            goto L_80087008;
    }
    // 0x80086FF0: nop

    // 0x80086FF4: addiu       $at, $zero, 0x4006
    ctx->r1 = ADD32(0, 0X4006);
    // 0x80086FF8: beq         $s0, $at, L_80087030
    if (ctx->r16 == ctx->r1) {
        // 0x80086FFC: nop

            goto L_80087030;
    }
    // 0x80086FFC: nop

    // 0x80087000: b           L_80087058
    // 0x80087004: nop

        goto L_80087058;
    // 0x80087004: nop

L_80087008:
    // 0x80087008: jal         0x8008CE48
    // 0x8008700C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x8008700C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80087010: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80087014: nop

    // 0x80087018: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8008701C: nop

    // 0x80087020: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x80087024: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80087028: b           L_800870AC
    // 0x8008702C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_800870AC;
    // 0x8008702C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80087030:
    // 0x80087030: jal         0x8008CE48
    // 0x80087034: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80087034: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80087038: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008703C: nop

    // 0x80087040: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80087044: nop

    // 0x80087048: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x8008704C: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80087050: b           L_800870AC
    // 0x80087054: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_800870AC;
    // 0x80087054: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_80087058:
    // 0x80087058: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008705C: lhu         $t9, 0x101C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X101C);
    // 0x80087060: lhu         $t7, 0x46($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X46);
    // 0x80087064: nop

    // 0x80087068: and         $t8, $t7, $t9
    ctx->r24 = ctx->r15 & ctx->r25;
    // 0x8008706C: beq         $t8, $zero, L_8008709C
    if (ctx->r24 == 0) {
        // 0x80087070: nop

            goto L_8008709C;
    }
    // 0x80087070: nop

    // 0x80087074: jal         0x8008CE48
    // 0x80087078: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80087078: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x8008707C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80087080: nop

    // 0x80087084: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x80087088: nop

    // 0x8008708C: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x80087090: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x80087094: b           L_800870AC
    // 0x80087098: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_800870AC;
    // 0x80087098: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8008709C:
    // 0x8008709C: b           L_800870AC
    // 0x800870A0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_800870AC;
    // 0x800870A0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800870A4: b           L_800870AC
    // 0x800870A8: nop

        goto L_800870AC;
    // 0x800870A8: nop

L_800870AC:
    // 0x800870AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800870B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800870B4: jr          $ra
    // 0x800870B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800870B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800870BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800870C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800870C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800870C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800870CC: jal         0x8008B4EC
    // 0x800870D0: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800870D0: nop

    after_0:
    // 0x800870D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800870D8: jal         0x8008B600
    // 0x800870DC: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x800870DC: nop

    after_1:
    // 0x800870E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800870E4: jal         0x8008BA24
    // 0x800870E8: nop

    func_8008BA24(rdram, ctx);
        goto after_2;
    // 0x800870E8: nop

    after_2:
    // 0x800870EC: b           L_800870F4
    // 0x800870F0: nop

        goto L_800870F4;
    // 0x800870F0: nop

L_800870F4:
    // 0x800870F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800870F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800870FC: jr          $ra
    // 0x80087100: nop

    return;
    // 0x80087100: nop

;}
RECOMP_FUNC void func_80087104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008710C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087114: jal         0x8008BFF4
    // 0x80087118: nop

    func_8008BFF4(rdram, ctx);
        goto after_0;
    // 0x80087118: nop

    after_0:
    // 0x8008711C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80087120: nop

    // 0x80087124: sh          $zero, 0xC14($t6)
    MEM_H(0XC14, ctx->r14) = 0;
    // 0x80087128: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008712C: nop

    // 0x80087130: lh          $a1, 0xBE8($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XBE8);
    // 0x80087134: jal         0x8008C2E8
    // 0x80087138: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_1;
    // 0x80087138: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    after_1:
    // 0x8008713C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80087140: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087144: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80087148: jal         0x800AEA98
    // 0x8008714C: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_2;
    // 0x8008714C: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_2:
    // 0x80087150: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80087154: nop

    // 0x80087158: lh          $v0, 0x4($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X4);
    // 0x8008715C: b           L_8008716C
    // 0x80087160: nop

        goto L_8008716C;
    // 0x80087160: nop

    // 0x80087164: b           L_8008716C
    // 0x80087168: nop

        goto L_8008716C;
    // 0x80087168: nop

L_8008716C:
    // 0x8008716C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087174: jr          $ra
    // 0x80087178: nop

    return;
    // 0x80087178: nop

;}
RECOMP_FUNC void func_8008717C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008717C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80087180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087184: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80087188: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008718C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80087190: nop

    // 0x80087194: lhu         $t7, 0xC14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC14);
    // 0x80087198: nop

    // 0x8008719C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x800871A0: beq         $at, $zero, L_8008756C
    if (ctx->r1 == 0) {
        // 0x800871A4: nop

            goto L_8008756C;
    }
    // 0x800871A4: nop

    // 0x800871A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800871AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800871B0: addu        $at, $at, $t7
    gpr jr_addend_800871BC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800871B4: lw          $t7, -0xA80($at)
    ctx->r15 = ADD32(ctx->r1, -0XA80);
    // 0x800871B8: nop

    // 0x800871BC: jr          $t7
    // 0x800871C0: nop

    switch (jr_addend_800871BC >> 2) {
        case 0: goto L_800871C4; break;
        case 1: goto L_80087260; break;
        case 2: goto L_800872E8; break;
        case 3: goto L_800873DC; break;
        case 4: goto L_80087478; break;
        default: switch_error(__func__, 0x800871BC, 0x800EF580);
    }
    // 0x800871C0: nop

L_800871C4:
    // 0x800871C4: jal         0x800AEBF4
    // 0x800871C8: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_0;
    // 0x800871C8: nop

    after_0:
    // 0x800871CC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800871D0: nop

    // 0x800871D4: sw          $v0, 0xC00($t8)
    MEM_W(0XC00, ctx->r24) = ctx->r2;
    // 0x800871D8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800871DC: nop

    // 0x800871E0: lw          $t0, 0xC00($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC00);
    // 0x800871E4: nop

    // 0x800871E8: bltz        $t0, L_80087228
    if (SIGNED(ctx->r8) < 0) {
        // 0x800871EC: nop

            goto L_80087228;
    }
    // 0x800871EC: nop

    // 0x800871F0: slti        $at, $t0, 0x1000
    ctx->r1 = SIGNED(ctx->r8) < 0X1000 ? 1 : 0;
    // 0x800871F4: beq         $at, $zero, L_80087228
    if (ctx->r1 == 0) {
        // 0x800871F8: nop

            goto L_80087228;
    }
    // 0x800871F8: nop

    // 0x800871FC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80087200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087204: lw          $a0, 0xC00($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC00);
    // 0x80087208: lw          $a3, 0xC10($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XC10);
    // 0x8008720C: jal         0x800AEE6C
    // 0x80087210: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileReadParams(rdram, ctx);
        goto after_1;
    // 0x80087210: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_1:
    // 0x80087214: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80087218: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008721C: sh          $t2, 0xC14($t3)
    MEM_H(0XC14, ctx->r11) = ctx->r10;
    // 0x80087220: b           L_8008756C
    // 0x80087224: nop

        goto L_8008756C;
    // 0x80087224: nop

L_80087228:
    // 0x80087228: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8008722C: nop

    // 0x80087230: lw          $t5, 0xC00($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC00);
    // 0x80087234: nop

    // 0x80087238: slti        $at, $t5, 0x1000
    ctx->r1 = SIGNED(ctx->r13) < 0X1000 ? 1 : 0;
    // 0x8008723C: bne         $at, $zero, L_80087258
    if (ctx->r1 != 0) {
        // 0x80087240: nop

            goto L_80087258;
    }
    // 0x80087240: nop

    // 0x80087244: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80087248: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008724C: sh          $t6, 0xBEC($t7)
    MEM_H(0XBEC, ctx->r15) = ctx->r14;
    // 0x80087250: b           L_80087588
    // 0x80087254: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80087588;
    // 0x80087254: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80087258:
    // 0x80087258: b           L_8008756C
    // 0x8008725C: nop

        goto L_8008756C;
    // 0x8008725C: nop

L_80087260:
    // 0x80087260: jal         0x800AEFD4
    // 0x80087264: nop

    ContPak_GetReadFileResult(rdram, ctx);
        goto after_2;
    // 0x80087264: nop

    after_2:
    // 0x80087268: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008726C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80087270: nop

    // 0x80087274: bne         $t8, $zero, L_800872B8
    if (ctx->r24 != 0) {
        // 0x80087278: nop

            goto L_800872B8;
    }
    // 0x80087278: nop

    // 0x8008727C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80087280: nop

    // 0x80087284: lh          $a1, 0xBEA($t9)
    ctx->r5 = MEM_H(ctx->r25, 0XBEA);
    // 0x80087288: jal         0x8008C2E8
    // 0x8008728C: addiu       $a0, $t9, 0xBEE
    ctx->r4 = ADD32(ctx->r25, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_3;
    // 0x8008728C: addiu       $a0, $t9, 0xBEE
    ctx->r4 = ADD32(ctx->r25, 0XBEE);
    after_3:
    // 0x80087290: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80087294: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087298: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x8008729C: jal         0x800AEA98
    // 0x800872A0: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_4;
    // 0x800872A0: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_4:
    // 0x800872A4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800872A8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800872AC: sh          $t0, 0xC14($t1)
    MEM_H(0XC14, ctx->r9) = ctx->r8;
    // 0x800872B0: b           L_8008756C
    // 0x800872B4: nop

        goto L_8008756C;
    // 0x800872B4: nop

L_800872B8:
    // 0x800872B8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800872BC: nop

    // 0x800872C0: slti        $at, $t2, 0x1000
    ctx->r1 = SIGNED(ctx->r10) < 0X1000 ? 1 : 0;
    // 0x800872C4: bne         $at, $zero, L_800872E0
    if (ctx->r1 != 0) {
        // 0x800872C8: nop

            goto L_800872E0;
    }
    // 0x800872C8: nop

    // 0x800872CC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800872D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800872D4: sh          $t3, 0xBEC($t4)
    MEM_H(0XBEC, ctx->r12) = ctx->r11;
    // 0x800872D8: b           L_80087588
    // 0x800872DC: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80087588;
    // 0x800872DC: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_800872E0:
    // 0x800872E0: b           L_8008756C
    // 0x800872E4: nop

        goto L_8008756C;
    // 0x800872E4: nop

L_800872E8:
    // 0x800872E8: jal         0x800AEBF4
    // 0x800872EC: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_5;
    // 0x800872EC: nop

    after_5:
    // 0x800872F0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800872F4: nop

    // 0x800872F8: sw          $v0, 0xC00($t5)
    MEM_W(0XC00, ctx->r13) = ctx->r2;
    // 0x800872FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80087300: nop

    // 0x80087304: lw          $t7, 0xC00($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC00);
    // 0x80087308: nop

    // 0x8008730C: bltz        $t7, L_8008734C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80087310: nop

            goto L_8008734C;
    }
    // 0x80087310: nop

    // 0x80087314: slti        $at, $t7, 0x1000
    ctx->r1 = SIGNED(ctx->r15) < 0X1000 ? 1 : 0;
    // 0x80087318: beq         $at, $zero, L_8008734C
    if (ctx->r1 == 0) {
        // 0x8008731C: nop

            goto L_8008734C;
    }
    // 0x8008731C: nop

    // 0x80087320: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80087324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087328: lw          $a0, 0xC00($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC00);
    // 0x8008732C: lw          $a3, 0xC10($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XC10);
    // 0x80087330: jal         0x800AEC80
    // 0x80087334: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_6;
    // 0x80087334: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_6:
    // 0x80087338: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008733C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80087340: sh          $t9, 0xC14($t0)
    MEM_H(0XC14, ctx->r8) = ctx->r25;
    // 0x80087344: b           L_8008756C
    // 0x80087348: nop

        goto L_8008756C;
    // 0x80087348: nop

L_8008734C:
    // 0x8008734C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80087350: addiu       $at, $zero, 0x1005
    ctx->r1 = ADD32(0, 0X1005);
    // 0x80087354: lw          $t2, 0xC00($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC00);
    // 0x80087358: nop

    // 0x8008735C: bne         $t2, $at, L_800873A4
    if (ctx->r10 != ctx->r1) {
        // 0x80087360: nop

            goto L_800873A4;
    }
    // 0x80087360: nop

    // 0x80087364: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80087368: nop

    // 0x8008736C: lh          $a1, 0xBEA($t3)
    ctx->r5 = MEM_H(ctx->r11, 0XBEA);
    // 0x80087370: jal         0x8008C2E8
    // 0x80087374: addiu       $a0, $t3, 0xBEE
    ctx->r4 = ADD32(ctx->r11, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_7;
    // 0x80087374: addiu       $a0, $t3, 0xBEE
    ctx->r4 = ADD32(ctx->r11, 0XBEE);
    after_7:
    // 0x80087378: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8008737C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087380: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80087384: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    // 0x80087388: jal         0x800AE880
    // 0x8008738C: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetOpenFileParams(rdram, ctx);
        goto after_8;
    // 0x8008738C: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_8:
    // 0x80087390: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80087394: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80087398: sh          $t4, 0xC14($t5)
    MEM_H(0XC14, ctx->r13) = ctx->r12;
    // 0x8008739C: b           L_8008756C
    // 0x800873A0: nop

        goto L_8008756C;
    // 0x800873A0: nop

L_800873A4:
    // 0x800873A4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800873A8: nop

    // 0x800873AC: lw          $t7, 0xC00($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC00);
    // 0x800873B0: nop

    // 0x800873B4: slti        $at, $t7, 0x1000
    ctx->r1 = SIGNED(ctx->r15) < 0X1000 ? 1 : 0;
    // 0x800873B8: bne         $at, $zero, L_800873D4
    if (ctx->r1 != 0) {
        // 0x800873BC: nop

            goto L_800873D4;
    }
    // 0x800873BC: nop

    // 0x800873C0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800873C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800873C8: sh          $t8, 0xBEC($t9)
    MEM_H(0XBEC, ctx->r25) = ctx->r24;
    // 0x800873CC: b           L_80087588
    // 0x800873D0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80087588;
    // 0x800873D0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_800873D4:
    // 0x800873D4: b           L_8008756C
    // 0x800873D8: nop

        goto L_8008756C;
    // 0x800873D8: nop

L_800873DC:
    // 0x800873DC: jal         0x800AEA0C
    // 0x800873E0: nop

    ContPak_GetOpenFileResult(rdram, ctx);
        goto after_9;
    // 0x800873E0: nop

    after_9:
    // 0x800873E4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800873E8: nop

    // 0x800873EC: sw          $v0, 0xC00($t0)
    MEM_W(0XC00, ctx->r8) = ctx->r2;
    // 0x800873F0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800873F4: nop

    // 0x800873F8: lw          $t2, 0xC00($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC00);
    // 0x800873FC: nop

    // 0x80087400: bltz        $t2, L_80087440
    if (SIGNED(ctx->r10) < 0) {
        // 0x80087404: nop

            goto L_80087440;
    }
    // 0x80087404: nop

    // 0x80087408: slti        $at, $t2, 0x1000
    ctx->r1 = SIGNED(ctx->r10) < 0X1000 ? 1 : 0;
    // 0x8008740C: beq         $at, $zero, L_80087440
    if (ctx->r1 == 0) {
        // 0x80087410: nop

            goto L_80087440;
    }
    // 0x80087410: nop

    // 0x80087414: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80087418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008741C: lw          $a0, 0xC00($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC00);
    // 0x80087420: lw          $a3, 0xC10($t3)
    ctx->r7 = MEM_W(ctx->r11, 0XC10);
    // 0x80087424: jal         0x800AEC80
    // 0x80087428: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_10;
    // 0x80087428: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_10:
    // 0x8008742C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80087430: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80087434: sh          $t4, 0xC14($t5)
    MEM_H(0XC14, ctx->r13) = ctx->r12;
    // 0x80087438: b           L_8008756C
    // 0x8008743C: nop

        goto L_8008756C;
    // 0x8008743C: nop

L_80087440:
    // 0x80087440: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80087444: nop

    // 0x80087448: lw          $t7, 0xC00($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC00);
    // 0x8008744C: nop

    // 0x80087450: slti        $at, $t7, 0x1000
    ctx->r1 = SIGNED(ctx->r15) < 0X1000 ? 1 : 0;
    // 0x80087454: bne         $at, $zero, L_80087470
    if (ctx->r1 != 0) {
        // 0x80087458: nop

            goto L_80087470;
    }
    // 0x80087458: nop

    // 0x8008745C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80087460: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80087464: sh          $t8, 0xBEC($t9)
    MEM_H(0XBEC, ctx->r25) = ctx->r24;
    // 0x80087468: b           L_80087588
    // 0x8008746C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80087588;
    // 0x8008746C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80087470:
    // 0x80087470: b           L_8008756C
    // 0x80087474: nop

        goto L_8008756C;
    // 0x80087474: nop

L_80087478:
    // 0x80087478: jal         0x800AEDE8
    // 0x8008747C: nop

    ContPak_GetWriteFileResult(rdram, ctx);
        goto after_11;
    // 0x8008747C: nop

    after_11:
    // 0x80087480: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80087484: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087488: nop

    // 0x8008748C: bne         $t0, $zero, L_8008753C
    if (ctx->r8 != 0) {
        // 0x80087490: nop

            goto L_8008753C;
    }
    // 0x80087490: nop

    // 0x80087494: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80087498: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8008749C: lh          $t2, 0xBEA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XBEA);
    // 0x800874A0: addiu       $t4, $t4, 0x7AE8
    ctx->r12 = ADD32(ctx->r12, 0X7AE8);
    // 0x800874A4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800874A8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800874AC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800874B0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800874B4: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800874B8: lw          $a1, 0xC10($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC10);
    // 0x800874BC: jal         0x8008C558
    // 0x800874C0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    func_8008C558(rdram, ctx);
        goto after_12;
    // 0x800874C0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_12:
    // 0x800874C4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800874C8: nop

    // 0x800874CC: lh          $t6, 0xBEA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBEA);
    // 0x800874D0: nop

    // 0x800874D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800874D8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800874DC: lw          $t9, 0xC04($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC04);
    // 0x800874E0: nop

    // 0x800874E4: bne         $t9, $zero, L_80087510
    if (ctx->r25 != 0) {
        // 0x800874E8: nop

            goto L_80087510;
    }
    // 0x800874E8: nop

    // 0x800874EC: jal         0x800BC6EC
    // 0x800874F0: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_13;
    // 0x800874F0: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    after_13:
    // 0x800874F4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800874F8: nop

    // 0x800874FC: lh          $t2, 0xBEA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XBEA);
    // 0x80087500: nop

    // 0x80087504: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80087508: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008750C: sw          $v0, 0xC04($t4)
    MEM_W(0XC04, ctx->r12) = ctx->r2;
L_80087510:
    // 0x80087510: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80087514: addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    // 0x80087518: lh          $t6, 0xBEA($t1)
    ctx->r14 = MEM_H(ctx->r9, 0XBEA);
    // 0x8008751C: lw          $a1, 0xC10($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC10);
    // 0x80087520: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80087524: addu        $t7, $t1, $t5
    ctx->r15 = ADD32(ctx->r9, ctx->r13);
    // 0x80087528: lw          $a0, 0xC04($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC04);
    // 0x8008752C: jal         0x800BCFCC
    // 0x80087530: nop

    SysMem_Copy8(rdram, ctx);
        goto after_14;
    // 0x80087530: nop

    after_14:
    // 0x80087534: b           L_80087588
    // 0x80087538: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80087588;
    // 0x80087538: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_8008753C:
    // 0x8008753C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80087540: nop

    // 0x80087544: slti        $at, $t8, 0x1000
    ctx->r1 = SIGNED(ctx->r24) < 0X1000 ? 1 : 0;
    // 0x80087548: bne         $at, $zero, L_80087564
    if (ctx->r1 != 0) {
        // 0x8008754C: nop

            goto L_80087564;
    }
    // 0x8008754C: nop

    // 0x80087550: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80087554: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087558: sh          $t9, 0xBEC($t2)
    MEM_H(0XBEC, ctx->r10) = ctx->r25;
    // 0x8008755C: b           L_80087588
    // 0x80087560: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_80087588;
    // 0x80087560: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80087564:
    // 0x80087564: b           L_8008756C
    // 0x80087568: nop

        goto L_8008756C;
    // 0x80087568: nop

L_8008756C:
    // 0x8008756C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80087570: nop

    // 0x80087574: lh          $v0, 0x4($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X4);
    // 0x80087578: b           L_80087588
    // 0x8008757C: nop

        goto L_80087588;
    // 0x8008757C: nop

    // 0x80087580: b           L_80087588
    // 0x80087584: nop

        goto L_80087588;
    // 0x80087584: nop

L_80087588:
    // 0x80087588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008758C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80087590: jr          $ra
    // 0x80087594: nop

    return;
    // 0x80087594: nop

;}
RECOMP_FUNC void func_80087598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008759C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800875A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800875A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800875A8: jal         0x8008B4EC
    // 0x800875AC: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800875AC: nop

    after_0:
    // 0x800875B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800875B4: jal         0x8008B600
    // 0x800875B8: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x800875B8: nop

    after_1:
    // 0x800875BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800875C0: jal         0x8008BA24
    // 0x800875C4: nop

    func_8008BA24(rdram, ctx);
        goto after_2;
    // 0x800875C4: nop

    after_2:
    // 0x800875C8: b           L_800875D0
    // 0x800875CC: nop

        goto L_800875D0;
    // 0x800875CC: nop

L_800875D0:
    // 0x800875D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800875D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800875D8: jr          $ra
    // 0x800875DC: nop

    return;
    // 0x800875DC: nop

;}
RECOMP_FUNC void func_800875E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800875E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800875E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800875EC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800875F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800875F4: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x800875F8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800875FC: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x80087600: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80087604: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80087608: nop

    // 0x8008760C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80087610: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80087614: nop

    // 0x80087618: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8008761C: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80087620: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80087624: nop

    // 0x80087628: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8008762C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80087630: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80087634: nop

    // 0x80087638: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8008763C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80087640: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80087644: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x80087648: nop

    // 0x8008764C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80087650: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80087654: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x80087658: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008765C: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x80087660: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80087664: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80087668: nop

    // 0x8008766C: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80087670: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80087674: nop

    // 0x80087678: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8008767C: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80087680: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80087684: nop

    // 0x80087688: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8008768C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80087690: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80087694: nop

    // 0x80087698: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x8008769C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800876A0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800876A4: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x800876A8: nop

    // 0x800876AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800876B0: jal         0x80089170
    // 0x800876B4: nop

    func_80089170(rdram, ctx);
        goto after_0;
    // 0x800876B4: nop

    after_0:
    // 0x800876B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800876BC: jal         0x80089584
    // 0x800876C0: nop

    func_80089584(rdram, ctx);
        goto after_1;
    // 0x800876C0: nop

    after_1:
    // 0x800876C4: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x800876C8: lh          $t5, 0x2C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2C);
    // 0x800876CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800876D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800876D4: addiu       $t6, $t4, 0xF5
    ctx->r14 = ADD32(ctx->r12, 0XF5);
    // 0x800876D8: addiu       $t7, $t5, -0x1E
    ctx->r15 = ADD32(ctx->r13, -0X1E);
    // 0x800876DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800876E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800876E4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800876E8: ori         $a1, $zero, 0x805A
    ctx->r5 = 0 | 0X805A;
    // 0x800876EC: addiu       $a2, $t4, 0xE1
    ctx->r6 = ADD32(ctx->r12, 0XE1);
    // 0x800876F0: jal         0x800897A8
    // 0x800876F4: addiu       $a3, $t5, -0x28
    ctx->r7 = ADD32(ctx->r13, -0X28);
    func_800897A8(rdram, ctx);
        goto after_2;
    // 0x800876F4: addiu       $a3, $t5, -0x28
    ctx->r7 = ADD32(ctx->r13, -0X28);
    after_2:
    // 0x800876F8: b           L_80087708
    // 0x800876FC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_80087708;
    // 0x800876FC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80087700: b           L_80087708
    // 0x80087704: nop

        goto L_80087708;
    // 0x80087704: nop

L_80087708:
    // 0x80087708: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008770C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80087710: jr          $ra
    // 0x80087714: nop

    return;
    // 0x80087714: nop

;}
RECOMP_FUNC void func_80087718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087718: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008771C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087720: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80087724: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80087728: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008772C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80087730: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80087734: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80087738: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x8008773C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80087740: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80087744: beq         $t0, $zero, L_800879C0
    if (ctx->r8 == 0) {
        // 0x80087748: nop

            goto L_800879C0;
    }
    // 0x80087748: nop

    // 0x8008774C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80087750: jal         0x8008A518
    // 0x80087754: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80087754: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80087758: beq         $v0, $zero, L_800879C0
    if (ctx->r2 == 0) {
        // 0x8008775C: nop

            goto L_800879C0;
    }
    // 0x8008775C: nop

    // 0x80087760: lhu         $t1, 0x2C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087764: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80087768: bne         $t1, $at, L_800877C8
    if (ctx->r9 != ctx->r1) {
        // 0x8008776C: nop

            goto L_800877C8;
    }
    // 0x8008776C: nop

    // 0x80087770: jal         0x8008CE48
    // 0x80087774: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80087774: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80087778: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008777C: nop

    // 0x80087780: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80087784: nop

    // 0x80087788: andi        $t4, $t3, 0x800
    ctx->r12 = ctx->r11 & 0X800;
    // 0x8008778C: beq         $t4, $zero, L_800877C0
    if (ctx->r12 == 0) {
        // 0x80087790: nop

            goto L_800877C0;
    }
    // 0x80087790: nop

    // 0x80087794: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80087798: nop

    // 0x8008779C: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800877A0: nop

    // 0x800877A4: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800877A8: beq         $t7, $zero, L_800877B8
    if (ctx->r15 == 0) {
        // 0x800877AC: nop

            goto L_800877B8;
    }
    // 0x800877AC: nop

    // 0x800877B0: b           L_80087B70
    // 0x800877B4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80087B70;
    // 0x800877B4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800877B8:
    // 0x800877B8: b           L_80087B70
    // 0x800877BC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_80087B70;
    // 0x800877BC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800877C0:
    // 0x800877C0: b           L_80087B70
    // 0x800877C4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80087B70;
    // 0x800877C4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800877C8:
    // 0x800877C8: lhu         $t9, 0x2C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2C);
    // 0x800877CC: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800877D0: bne         $t9, $at, L_80087850
    if (ctx->r25 != ctx->r1) {
        // 0x800877D4: nop

            goto L_80087850;
    }
    // 0x800877D4: nop

    // 0x800877D8: jal         0x8008CE48
    // 0x800877DC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x800877DC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x800877E0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800877E4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800877E8: lbu         $t0, 0x10($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X10);
    // 0x800877EC: nop

    // 0x800877F0: bne         $t0, $at, L_80087830
    if (ctx->r8 != ctx->r1) {
        // 0x800877F4: nop

            goto L_80087830;
    }
    // 0x800877F4: nop

    // 0x800877F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800877FC:
    // 0x800877FC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80087800: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80087804: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80087808: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8008780C: lbu         $t2, 0x4BEC($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4BEC);
    // 0x80087810: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x80087814: sb          $t2, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r10;
    // 0x80087818: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8008781C: nop

    // 0x80087820: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087824: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80087828: bne         $at, $zero, L_800877FC
    if (ctx->r1 != 0) {
        // 0x8008782C: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800877FC;
    }
    // 0x8008782C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80087830:
    // 0x80087830: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80087834: nop

    // 0x80087838: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x8008783C: nop

    // 0x80087840: ori         $t8, $t9, 0x200
    ctx->r24 = ctx->r25 | 0X200;
    // 0x80087844: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x80087848: b           L_80087B70
    // 0x8008784C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087B70;
    // 0x8008784C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80087850:
    // 0x80087850: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087854: ori         $at, $zero, 0x805A
    ctx->r1 = 0 | 0X805A;
    // 0x80087858: bne         $t0, $at, L_80087880
    if (ctx->r8 != ctx->r1) {
        // 0x8008785C: nop

            goto L_80087880;
    }
    // 0x8008785C: nop

    // 0x80087860: jal         0x8008CE48
    // 0x80087864: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80087864: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_3:
    // 0x80087868: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008786C: nop

    // 0x80087870: lhu         $t1, 0x0($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X0);
    // 0x80087874: nop

    // 0x80087878: xori        $t2, $t1, 0x400
    ctx->r10 = ctx->r9 ^ 0X400;
    // 0x8008787C: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
L_80087880:
    // 0x80087880: lhu         $t4, 0x2C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087884: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x80087888: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8008788C: bne         $at, $zero, L_800879C0
    if (ctx->r1 != 0) {
        // 0x80087890: nop

            goto L_800879C0;
    }
    // 0x80087890: nop

    // 0x80087894: ori         $at, $zero, 0x805A
    ctx->r1 = 0 | 0X805A;
    // 0x80087898: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8008789C: beq         $at, $zero, L_800879C0
    if (ctx->r1 == 0) {
        // 0x800878A0: nop

            goto L_800879C0;
    }
    // 0x800878A0: nop

    // 0x800878A4: jal         0x8008CE48
    // 0x800878A8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x800878A8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x800878AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800878B0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800878B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800878B8: lbu         $t6, 0x10($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X10);
    // 0x800878BC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800878C0: beq         $t6, $at, L_800878FC
    if (ctx->r14 == ctx->r1) {
        // 0x800878C4: nop

            goto L_800878FC;
    }
    // 0x800878C4: nop

L_800878C8:
    // 0x800878C8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800878CC: nop

    // 0x800878D0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x800878D4: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x800878D8: beq         $at, $zero, L_800878FC
    if (ctx->r1 == 0) {
        // 0x800878DC: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800878FC;
    }
    // 0x800878DC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800878E0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800878E4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800878E8: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x800878EC: lbu         $t1, 0x10($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X10);
    // 0x800878F0: nop

    // 0x800878F4: bne         $t1, $at, L_800878C8
    if (ctx->r9 != ctx->r1) {
        // 0x800878F8: nop

            goto L_800878C8;
    }
    // 0x800878F8: nop

L_800878FC:
    // 0x800878FC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80087900: nop

    // 0x80087904: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x80087908: bne         $at, $zero, L_80087918
    if (ctx->r1 != 0) {
        // 0x8008790C: nop

            goto L_80087918;
    }
    // 0x8008790C: nop

    // 0x80087910: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80087914: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_80087918:
    // 0x80087918: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008791C: nop

    // 0x80087920: slti        $at, $t4, 0x7
    ctx->r1 = SIGNED(ctx->r12) < 0X7 ? 1 : 0;
    // 0x80087924: bne         $at, $zero, L_80087934
    if (ctx->r1 != 0) {
        // 0x80087928: nop

            goto L_80087934;
    }
    // 0x80087928: nop

    // 0x8008792C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80087930: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
L_80087934:
    // 0x80087934: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087938: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008793C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80087940: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80087944: ori         $at, $at, 0x7FFD
    ctx->r1 = ctx->r1 | 0X7FFD;
    // 0x80087948: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x8008794C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80087950: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80087954: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80087958: nop

    // 0x8008795C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80087960: nop

    // 0x80087964: andi        $t3, $t2, 0x400
    ctx->r11 = ctx->r10 & 0X400;
    // 0x80087968: beq         $t3, $zero, L_80087990
    if (ctx->r11 == 0) {
        // 0x8008796C: nop

            goto L_80087990;
    }
    // 0x8008796C: nop

    // 0x80087970: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80087974: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80087978: nop

    // 0x8008797C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80087980: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x80087984: nop

    // 0x80087988: addiu       $t8, $t7, 0x57
    ctx->r24 = ADD32(ctx->r15, 0X57);
    // 0x8008798C: sb          $t8, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r24;
L_80087990:
    // 0x80087990: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80087994: nop

    // 0x80087998: beq         $t9, $zero, L_800879C0
    if (ctx->r25 == 0) {
        // 0x8008799C: nop

            goto L_800879C0;
    }
    // 0x8008799C: nop

    // 0x800879A0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800879A4: nop

    // 0x800879A8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800879AC: nop

    // 0x800879B0: ori         $t2, $t1, 0x200
    ctx->r10 = ctx->r9 | 0X200;
    // 0x800879B4: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x800879B8: b           L_80087B70
    // 0x800879BC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087B70;
    // 0x800879BC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_800879C0:
    // 0x800879C0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800879C4: lhu         $t4, 0x101C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X101C);
    // 0x800879C8: lhu         $t3, 0x3E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3E);
    // 0x800879CC: nop

    // 0x800879D0: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x800879D4: beq         $t5, $zero, L_80087AC0
    if (ctx->r13 == 0) {
        // 0x800879D8: nop

            goto L_80087AC0;
    }
    // 0x800879D8: nop

    // 0x800879DC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800879E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800879E4: lbu         $t8, 0x10($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X10);
    // 0x800879E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800879EC: beq         $t8, $at, L_80087A28
    if (ctx->r24 == ctx->r1) {
        // 0x800879F0: nop

            goto L_80087A28;
    }
    // 0x800879F0: nop

L_800879F4:
    // 0x800879F4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800879F8: nop

    // 0x800879FC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80087A00: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x80087A04: beq         $at, $zero, L_80087A28
    if (ctx->r1 == 0) {
        // 0x80087A08: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_80087A28;
    }
    // 0x80087A08: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80087A0C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80087A10: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80087A14: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x80087A18: lbu         $t0, 0x10($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X10);
    // 0x80087A1C: nop

    // 0x80087A20: bne         $t0, $at, L_800879F4
    if (ctx->r8 != ctx->r1) {
        // 0x80087A24: nop

            goto L_800879F4;
    }
    // 0x80087A24: nop

L_80087A28:
    // 0x80087A28: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A2C: nop

    // 0x80087A30: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80087A34: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80087A38: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A3C: nop

    // 0x80087A40: bltz        $t5, L_80087A68
    if (SIGNED(ctx->r13) < 0) {
        // 0x80087A44: nop

            goto L_80087A68;
    }
    // 0x80087A44: nop

    // 0x80087A48: jal         0x8008CE48
    // 0x80087A4C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_5;
    // 0x80087A4C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_5:
    // 0x80087A50: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80087A54: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A58: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80087A5C: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x80087A60: b           L_80087AC0
    // 0x80087A64: sb          $t7, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r15;
        goto L_80087AC0;
    // 0x80087A64: sb          $t7, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r15;
L_80087A68:
    // 0x80087A68: jal         0x8008CE48
    // 0x80087A6C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80087A6C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_6:
    // 0x80087A70: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80087A74: nop

    // 0x80087A78: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x80087A7C: nop

    // 0x80087A80: andi        $t0, $t2, 0x800
    ctx->r8 = ctx->r10 & 0X800;
    // 0x80087A84: beq         $t0, $zero, L_80087AB8
    if (ctx->r8 == 0) {
        // 0x80087A88: nop

            goto L_80087AB8;
    }
    // 0x80087A88: nop

    // 0x80087A8C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80087A90: nop

    // 0x80087A94: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x80087A98: nop

    // 0x80087A9C: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x80087AA0: beq         $t5, $zero, L_80087AB0
    if (ctx->r13 == 0) {
        // 0x80087AA4: nop

            goto L_80087AB0;
    }
    // 0x80087AA4: nop

    // 0x80087AA8: b           L_80087B70
    // 0x80087AAC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80087B70;
    // 0x80087AAC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80087AB0:
    // 0x80087AB0: b           L_80087B70
    // 0x80087AB4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_80087B70;
    // 0x80087AB4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80087AB8:
    // 0x80087AB8: b           L_80087B70
    // 0x80087ABC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80087B70;
    // 0x80087ABC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80087AC0:
    // 0x80087AC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80087AC4: lhu         $t6, 0x11A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X11A4);
    // 0x80087AC8: lhu         $t8, 0x3E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3E);
    // 0x80087ACC: nop

    // 0x80087AD0: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x80087AD4: beq         $t7, $zero, L_80087B54
    if (ctx->r15 == 0) {
        // 0x80087AD8: nop

            goto L_80087B54;
    }
    // 0x80087AD8: nop

    // 0x80087ADC: jal         0x8008CE48
    // 0x80087AE0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_7;
    // 0x80087AE0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_7:
    // 0x80087AE4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80087AE8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80087AEC: lbu         $t9, 0x10($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X10);
    // 0x80087AF0: nop

    // 0x80087AF4: bne         $t9, $at, L_80087B34
    if (ctx->r25 != ctx->r1) {
        // 0x80087AF8: nop

            goto L_80087B34;
    }
    // 0x80087AF8: nop

    // 0x80087AFC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80087B00:
    // 0x80087B00: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80087B04: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80087B08: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80087B0C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80087B10: lbu         $t0, 0x4BEC($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X4BEC);
    // 0x80087B14: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80087B18: sb          $t0, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r8;
    // 0x80087B1C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80087B20: nop

    // 0x80087B24: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80087B28: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x80087B2C: bne         $at, $zero, L_80087B00
    if (ctx->r1 != 0) {
        // 0x80087B30: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80087B00;
    }
    // 0x80087B30: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80087B34:
    // 0x80087B34: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80087B38: nop

    // 0x80087B3C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80087B40: nop

    // 0x80087B44: ori         $t1, $t7, 0x200
    ctx->r9 = ctx->r15 | 0X200;
    // 0x80087B48: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x80087B4C: b           L_80087B70
    // 0x80087B50: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087B70;
    // 0x80087B50: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80087B54:
    // 0x80087B54: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80087B58: nop

    // 0x80087B5C: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x80087B60: b           L_80087B70
    // 0x80087B64: nop

        goto L_80087B70;
    // 0x80087B64: nop

    // 0x80087B68: b           L_80087B70
    // 0x80087B6C: nop

        goto L_80087B70;
    // 0x80087B6C: nop

L_80087B70:
    // 0x80087B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087B74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80087B78: jr          $ra
    // 0x80087B7C: nop

    return;
    // 0x80087B7C: nop

;}
RECOMP_FUNC void func_80087B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087B8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087B90: jal         0x8008B4EC
    // 0x80087B94: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80087B94: nop

    after_0:
    // 0x80087B98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087B9C: jal         0x8008BC70
    // 0x80087BA0: nop

    func_8008BC70(rdram, ctx);
        goto after_1;
    // 0x80087BA0: nop

    after_1:
    // 0x80087BA4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80087BA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80087BAC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80087BB0: jal         0x8008B738
    // 0x80087BB4: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80087BB4: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    after_2:
    // 0x80087BB8: addiu       $t7, $zero, 0xE1
    ctx->r15 = ADD32(0, 0XE1);
    // 0x80087BBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80087BC0: sw          $t7, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r15;
    // 0x80087BC4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80087BC8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80087BCC: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x80087BD0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80087BD4: nop

    // 0x80087BD8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80087BDC: nop

    // 0x80087BE0: andi        $t1, $t0, 0x400
    ctx->r9 = ctx->r8 & 0X400;
    // 0x80087BE4: beq         $t1, $zero, L_80087C04
    if (ctx->r9 == 0) {
        // 0x80087BE8: nop

            goto L_80087C04;
    }
    // 0x80087BE8: nop

    // 0x80087BEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087BF0: addiu       $a1, $zero, 0x4003
    ctx->r5 = ADD32(0, 0X4003);
    // 0x80087BF4: jal         0x8008B2FC
    // 0x80087BF8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_3;
    // 0x80087BF8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_3:
    // 0x80087BFC: b           L_80087C14
    // 0x80087C00: nop

        goto L_80087C14;
    // 0x80087C00: nop

L_80087C04:
    // 0x80087C04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087C08: addiu       $a1, $zero, 0x4004
    ctx->r5 = ADD32(0, 0X4004);
    // 0x80087C0C: jal         0x8008B2FC
    // 0x80087C10: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_4;
    // 0x80087C10: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_4:
L_80087C14:
    // 0x80087C14: b           L_80087C1C
    // 0x80087C18: nop

        goto L_80087C1C;
    // 0x80087C18: nop

L_80087C1C:
    // 0x80087C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087C24: jr          $ra
    // 0x80087C28: nop

    return;
    // 0x80087C28: nop

;}
RECOMP_FUNC void func_80087C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80087C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087C34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80087C38: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80087C3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80087C40: lw          $t7, 0x728($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X728);
    // 0x80087C44: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80087C48: lwc1        $f4, 0x1B0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1B0);
    // 0x80087C4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80087C50: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80087C54: nop

    // 0x80087C58: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80087C5C: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80087C60: nop

    // 0x80087C64: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80087C68: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80087C6C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80087C70: nop

    // 0x80087C74: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80087C78: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80087C7C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80087C80: nop

    // 0x80087C84: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80087C88: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80087C8C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80087C90: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x80087C94: nop

    // 0x80087C98: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80087C9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80087CA0: lw          $t1, 0x728($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X728);
    // 0x80087CA4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80087CA8: lwc1        $f8, 0x1B4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B4);
    // 0x80087CAC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80087CB0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80087CB4: nop

    // 0x80087CB8: div.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80087CBC: lwc1        $f4, 0xD0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80087CC0: nop

    // 0x80087CC4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80087CC8: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80087CCC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80087CD0: nop

    // 0x80087CD4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80087CD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80087CDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80087CE0: nop

    // 0x80087CE4: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x80087CE8: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80087CEC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80087CF0: sh          $t3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r11;
    // 0x80087CF4: nop

    // 0x80087CF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80087CFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087D00: addiu       $a0, $a0, -0x6110
    ctx->r4 = ADD32(ctx->r4, -0X6110);
    // 0x80087D04: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80087D08: jal         0x8008BE0C
    // 0x80087D0C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_8008BE0C(rdram, ctx);
        goto after_0;
    // 0x80087D0C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x80087D10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80087D14: jal         0x80089170
    // 0x80087D18: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80087D18: nop

    after_1:
    // 0x80087D1C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80087D20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80087D24: jal         0x800898D8
    // 0x80087D28: addiu       $a2, $zero, 0x4007
    ctx->r6 = ADD32(0, 0X4007);
    func_800898D8(rdram, ctx);
        goto after_2;
    // 0x80087D28: addiu       $a2, $zero, 0x4007
    ctx->r6 = ADD32(0, 0X4007);
    after_2:
    // 0x80087D2C: beq         $v0, $zero, L_80087D7C
    if (ctx->r2 == 0) {
        // 0x80087D30: nop

            goto L_80087D7C;
    }
    // 0x80087D30: nop

    // 0x80087D34: lh          $t4, 0x1A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1A);
    // 0x80087D38: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x80087D3C: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x80087D40: lh          $t8, 0x20($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X20);
    // 0x80087D44: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80087D48: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x80087D4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80087D50: bgez        $a1, L_80087D60
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80087D54: sra         $t6, $a1, 1
        ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80087D60;
    }
    // 0x80087D54: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80087D58: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80087D5C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80087D60:
    // 0x80087D60: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80087D64: bgez        $a2, L_80087D74
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80087D68: sra         $t9, $a2, 1
        ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80087D74;
    }
    // 0x80087D68: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80087D6C: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80087D70: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80087D74:
    // 0x80087D74: jal         0x80089B04
    // 0x80087D78: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_80089B04(rdram, ctx);
        goto after_3;
    // 0x80087D78: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_3:
L_80087D7C:
    // 0x80087D7C: b           L_80087D8C
    // 0x80087D80: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087D8C;
    // 0x80087D80: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x80087D84: b           L_80087D8C
    // 0x80087D88: nop

        goto L_80087D8C;
    // 0x80087D88: nop

L_80087D8C:
    // 0x80087D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80087D94: jr          $ra
    // 0x80087D98: nop

    return;
    // 0x80087D98: nop

;}
RECOMP_FUNC void func_80087D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80087DA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80087DA4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80087DA8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80087DAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80087DB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80087DB4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80087DB8: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80087DBC: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80087DC0: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x80087DC4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80087DC8: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80087DCC: beq         $t0, $zero, L_80087E7C
    if (ctx->r8 == 0) {
        // 0x80087DD0: nop

            goto L_80087E7C;
    }
    // 0x80087DD0: nop

    // 0x80087DD4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80087DD8: jal         0x8008A518
    // 0x80087DDC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80087DDC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80087DE0: beq         $v0, $zero, L_80087E7C
    if (ctx->r2 == 0) {
        // 0x80087DE4: nop

            goto L_80087E7C;
    }
    // 0x80087DE4: nop

    // 0x80087DE8: lhu         $s0, 0x2C($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087DEC: addiu       $at, $zero, 0x4007
    ctx->r1 = ADD32(0, 0X4007);
    // 0x80087DF0: beq         $s0, $at, L_80087E34
    if (ctx->r16 == ctx->r1) {
        // 0x80087DF4: nop

            goto L_80087E34;
    }
    // 0x80087DF4: nop

    // 0x80087DF8: addiu       $at, $zero, 0x4008
    ctx->r1 = ADD32(0, 0X4008);
    // 0x80087DFC: beq         $s0, $at, L_80087E0C
    if (ctx->r16 == ctx->r1) {
        // 0x80087E00: nop

            goto L_80087E0C;
    }
    // 0x80087E00: nop

    // 0x80087E04: b           L_80087E7C
    // 0x80087E08: nop

        goto L_80087E7C;
    // 0x80087E08: nop

L_80087E0C:
    // 0x80087E0C: jal         0x8008CE48
    // 0x80087E10: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80087E10: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80087E14: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80087E18: nop

    // 0x80087E1C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80087E20: nop

    // 0x80087E24: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x80087E28: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80087E2C: b           L_80087ED0
    // 0x80087E30: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_80087ED0;
    // 0x80087E30: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80087E34:
    // 0x80087E34: jal         0x8008CE48
    // 0x80087E38: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80087E38: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80087E3C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80087E40:
    // 0x80087E40: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80087E44: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80087E48: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80087E4C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80087E50: lbu         $t5, 0x4BF4($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4BF4);
    // 0x80087E54: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80087E58: sb          $t5, 0x17($t7)
    MEM_B(0X17, ctx->r15) = ctx->r13;
    // 0x80087E5C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80087E60: nop

    // 0x80087E64: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80087E68: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x80087E6C: bne         $at, $zero, L_80087E40
    if (ctx->r1 != 0) {
        // 0x80087E70: sw          $t8, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r24;
            goto L_80087E40;
    }
    // 0x80087E70: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80087E74: b           L_80087ED0
    // 0x80087E78: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80087ED0;
    // 0x80087E78: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80087E7C:
    // 0x80087E7C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80087E80: lhu         $t2, 0x101C($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X101C);
    // 0x80087E84: lhu         $t0, 0x3E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3E);
    // 0x80087E88: nop

    // 0x80087E8C: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x80087E90: beq         $t3, $zero, L_80087EC0
    if (ctx->r11 == 0) {
        // 0x80087E94: nop

            goto L_80087EC0;
    }
    // 0x80087E94: nop

    // 0x80087E98: jal         0x8008CE48
    // 0x80087E9C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80087E9C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x80087EA0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80087EA4: nop

    // 0x80087EA8: lhu         $t6, 0x0($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X0);
    // 0x80087EAC: nop

    // 0x80087EB0: ori         $t4, $t6, 0x200
    ctx->r12 = ctx->r14 | 0X200;
    // 0x80087EB4: sh          $t4, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r12;
    // 0x80087EB8: b           L_80087ED0
    // 0x80087EBC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_80087ED0;
    // 0x80087EBC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80087EC0:
    // 0x80087EC0: b           L_80087ED0
    // 0x80087EC4: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80087ED0;
    // 0x80087EC4: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x80087EC8: b           L_80087ED0
    // 0x80087ECC: nop

        goto L_80087ED0;
    // 0x80087ECC: nop

L_80087ED0:
    // 0x80087ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80087ED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80087ED8: jr          $ra
    // 0x80087EDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80087EDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80087EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087EEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087EF0: jal         0x8008B4EC
    // 0x80087EF4: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80087EF4: nop

    after_0:
    // 0x80087EF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087EFC: jal         0x8008BC70
    // 0x80087F00: nop

    func_8008BC70(rdram, ctx);
        goto after_1;
    // 0x80087F00: nop

    after_1:
    // 0x80087F04: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80087F08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087F0C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80087F10: jal         0x8008B738
    // 0x80087F14: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80087F14: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    after_2:
    // 0x80087F18: b           L_80087F20
    // 0x80087F1C: nop

        goto L_80087F20;
    // 0x80087F1C: nop

L_80087F20:
    // 0x80087F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087F28: jr          $ra
    // 0x80087F2C: nop

    return;
    // 0x80087F2C: nop

;}
RECOMP_FUNC void func_80087F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087F40: jal         0x8008A46C
    // 0x80087F44: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80087F44: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80087F48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087F4C: jal         0x800875E0
    // 0x80087F50: nop

    func_800875E0(rdram, ctx);
        goto after_1;
    // 0x80087F50: nop

    after_1:
    // 0x80087F54: b           L_80087F64
    // 0x80087F58: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80087F64;
    // 0x80087F58: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80087F5C: b           L_80087F64
    // 0x80087F60: nop

        goto L_80087F64;
    // 0x80087F60: nop

L_80087F64:
    // 0x80087F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087F6C: jr          $ra
    // 0x80087F70: nop

    return;
    // 0x80087F70: nop

;}
RECOMP_FUNC void func_80087F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80087F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087F7C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80087F80: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80087F84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80087F88: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80087F8C: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80087F90: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80087F94: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x80087F98: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80087F9C: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80087FA0: beq         $t0, $zero, L_800881D4
    if (ctx->r8 == 0) {
        // 0x80087FA4: nop

            goto L_800881D4;
    }
    // 0x80087FA4: nop

    // 0x80087FA8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80087FAC: jal         0x8008A518
    // 0x80087FB0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80087FB0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80087FB4: beq         $v0, $zero, L_800881D4
    if (ctx->r2 == 0) {
        // 0x80087FB8: nop

            goto L_800881D4;
    }
    // 0x80087FB8: nop

    // 0x80087FBC: lhu         $t1, 0x2C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087FC0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80087FC4: bne         $t1, $at, L_80087FDC
    if (ctx->r9 != ctx->r1) {
        // 0x80087FC8: nop

            goto L_80087FDC;
    }
    // 0x80087FC8: nop

    // 0x80087FCC: jal         0x8008CE48
    // 0x80087FD0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80087FD0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80087FD4: b           L_8008833C
    // 0x80087FD8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_8008833C;
    // 0x80087FD8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80087FDC:
    // 0x80087FDC: lhu         $t2, 0x2C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2C);
    // 0x80087FE0: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80087FE4: bne         $t2, $at, L_80088064
    if (ctx->r10 != ctx->r1) {
        // 0x80087FE8: nop

            goto L_80088064;
    }
    // 0x80087FE8: nop

    // 0x80087FEC: jal         0x8008CE48
    // 0x80087FF0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80087FF0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x80087FF4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80087FF8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80087FFC: lbu         $t4, 0x17($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X17);
    // 0x80088000: nop

    // 0x80088004: bne         $t4, $at, L_80088044
    if (ctx->r12 != ctx->r1) {
        // 0x80088008: nop

            goto L_80088044;
    }
    // 0x80088008: nop

    // 0x8008800C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80088010:
    // 0x80088010: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80088014: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80088018: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008801C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80088020: lbu         $t6, 0x4BF4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4BF4);
    // 0x80088024: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x80088028: sb          $t6, 0x17($t9)
    MEM_B(0X17, ctx->r25) = ctx->r14;
    // 0x8008802C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80088030: nop

    // 0x80088034: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80088038: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x8008803C: bne         $at, $zero, L_80088010
    if (ctx->r1 != 0) {
        // 0x80088040: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_80088010;
    }
    // 0x80088040: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_80088044:
    // 0x80088044: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80088048: nop

    // 0x8008804C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80088050: nop

    // 0x80088054: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x80088058: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x8008805C: b           L_8008833C
    // 0x80088060: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_8008833C;
    // 0x80088060: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_80088064:
    // 0x80088064: lhu         $t4, 0x2C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2C);
    // 0x80088068: ori         $at, $zero, 0x805A
    ctx->r1 = 0 | 0X805A;
    // 0x8008806C: bne         $t4, $at, L_80088094
    if (ctx->r12 != ctx->r1) {
        // 0x80088070: nop

            goto L_80088094;
    }
    // 0x80088070: nop

    // 0x80088074: jal         0x8008CE48
    // 0x80088078: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80088078: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_3:
    // 0x8008807C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80088080: nop

    // 0x80088084: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x80088088: nop

    // 0x8008808C: xori        $t6, $t5, 0x400
    ctx->r14 = ctx->r13 ^ 0X400;
    // 0x80088090: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_80088094:
    // 0x80088094: lhu         $t9, 0x2C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2C);
    // 0x80088098: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x8008809C: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800880A0: bne         $at, $zero, L_800881D4
    if (ctx->r1 != 0) {
        // 0x800880A4: nop

            goto L_800881D4;
    }
    // 0x800880A4: nop

    // 0x800880A8: ori         $at, $zero, 0x805A
    ctx->r1 = 0 | 0X805A;
    // 0x800880AC: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800880B0: beq         $at, $zero, L_800881D4
    if (ctx->r1 == 0) {
        // 0x800880B4: nop

            goto L_800881D4;
    }
    // 0x800880B4: nop

    // 0x800880B8: jal         0x8008CE48
    // 0x800880BC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x800880BC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x800880C0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800880C4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800880C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800880CC: lbu         $t0, 0x17($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X17);
    // 0x800880D0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800880D4: beq         $t0, $at, L_80088110
    if (ctx->r8 == ctx->r1) {
        // 0x800880D8: nop

            goto L_80088110;
    }
    // 0x800880D8: nop

L_800880DC:
    // 0x800880DC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800880E0: nop

    // 0x800880E4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800880E8: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x800880EC: beq         $at, $zero, L_80088110
    if (ctx->r1 == 0) {
        // 0x800880F0: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_80088110;
    }
    // 0x800880F0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800880F4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800880F8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800880FC: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80088100: lbu         $t5, 0x17($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X17);
    // 0x80088104: nop

    // 0x80088108: bne         $t5, $at, L_800880DC
    if (ctx->r13 != ctx->r1) {
        // 0x8008810C: nop

            goto L_800880DC;
    }
    // 0x8008810C: nop

L_80088110:
    // 0x80088110: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80088114: nop

    // 0x80088118: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x8008811C: bne         $at, $zero, L_8008812C
    if (ctx->r1 != 0) {
        // 0x80088120: nop

            goto L_8008812C;
    }
    // 0x80088120: nop

    // 0x80088124: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80088128: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_8008812C:
    // 0x8008812C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80088130: nop

    // 0x80088134: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x80088138: bne         $at, $zero, L_80088148
    if (ctx->r1 != 0) {
        // 0x8008813C: nop

            goto L_80088148;
    }
    // 0x8008813C: nop

    // 0x80088140: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80088144: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80088148:
    // 0x80088148: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
    // 0x8008814C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80088150: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80088154: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80088158: ori         $at, $at, 0x7FFD
    ctx->r1 = ctx->r1 | 0X7FFD;
    // 0x8008815C: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x80088160: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80088164: sb          $t2, 0x17($t4)
    MEM_B(0X17, ctx->r12) = ctx->r10;
    // 0x80088168: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008816C: nop

    // 0x80088170: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80088174: nop

    // 0x80088178: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x8008817C: beq         $t7, $zero, L_800881A4
    if (ctx->r15 == 0) {
        // 0x80088180: nop

            goto L_800881A4;
    }
    // 0x80088180: nop

    // 0x80088184: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80088188: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008818C: nop

    // 0x80088190: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80088194: lbu         $t1, 0x17($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X17);
    // 0x80088198: nop

    // 0x8008819C: addiu       $t3, $t1, 0x57
    ctx->r11 = ADD32(ctx->r9, 0X57);
    // 0x800881A0: sb          $t3, 0x17($t0)
    MEM_B(0X17, ctx->r8) = ctx->r11;
L_800881A4:
    // 0x800881A4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800881A8: nop

    // 0x800881AC: beq         $t2, $zero, L_800881D4
    if (ctx->r10 == 0) {
        // 0x800881B0: nop

            goto L_800881D4;
    }
    // 0x800881B0: nop

    // 0x800881B4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800881B8: nop

    // 0x800881BC: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800881C0: nop

    // 0x800881C4: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x800881C8: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x800881CC: b           L_8008833C
    // 0x800881D0: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_8008833C;
    // 0x800881D0: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_800881D4:
    // 0x800881D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800881D8: lhu         $t9, 0x101C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X101C);
    // 0x800881DC: lhu         $t7, 0x3E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3E);
    // 0x800881E0: nop

    // 0x800881E4: and         $t8, $t7, $t9
    ctx->r24 = ctx->r15 & ctx->r25;
    // 0x800881E8: beq         $t8, $zero, L_8008828C
    if (ctx->r24 == 0) {
        // 0x800881EC: nop

            goto L_8008828C;
    }
    // 0x800881EC: nop

    // 0x800881F0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800881F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800881F8: lbu         $t3, 0x17($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X17);
    // 0x800881FC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80088200: beq         $t3, $at, L_8008823C
    if (ctx->r11 == ctx->r1) {
        // 0x80088204: nop

            goto L_8008823C;
    }
    // 0x80088204: nop

L_80088208:
    // 0x80088208: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008820C: nop

    // 0x80088210: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80088214: slti        $at, $t2, 0x7
    ctx->r1 = SIGNED(ctx->r10) < 0X7 ? 1 : 0;
    // 0x80088218: beq         $at, $zero, L_8008823C
    if (ctx->r1 == 0) {
        // 0x8008821C: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8008823C;
    }
    // 0x8008821C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80088220: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80088224: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80088228: addu        $t6, $t5, $t2
    ctx->r14 = ADD32(ctx->r13, ctx->r10);
    // 0x8008822C: lbu         $t4, 0x17($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X17);
    // 0x80088230: nop

    // 0x80088234: bne         $t4, $at, L_80088208
    if (ctx->r12 != ctx->r1) {
        // 0x80088238: nop

            goto L_80088208;
    }
    // 0x80088238: nop

L_8008823C:
    // 0x8008823C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80088240: nop

    // 0x80088244: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80088248: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8008824C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80088250: nop

    // 0x80088254: bltz        $t8, L_8008827C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80088258: nop

            goto L_8008827C;
    }
    // 0x80088258: nop

    // 0x8008825C: jal         0x8008CE48
    // 0x80088260: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_5;
    // 0x80088260: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_5:
    // 0x80088264: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80088268: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008826C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80088270: addu        $t5, $t3, $t0
    ctx->r13 = ADD32(ctx->r11, ctx->r8);
    // 0x80088274: b           L_8008828C
    // 0x80088278: sb          $t1, 0x17($t5)
    MEM_B(0X17, ctx->r13) = ctx->r9;
        goto L_8008828C;
    // 0x80088278: sb          $t1, 0x17($t5)
    MEM_B(0X17, ctx->r13) = ctx->r9;
L_8008827C:
    // 0x8008827C: jal         0x8008CE48
    // 0x80088280: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80088280: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_6:
    // 0x80088284: b           L_8008833C
    // 0x80088288: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_8008833C;
    // 0x80088288: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_8008828C:
    // 0x8008828C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80088290: lhu         $t6, 0x11A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X11A4);
    // 0x80088294: lhu         $t2, 0x3E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3E);
    // 0x80088298: nop

    // 0x8008829C: and         $t4, $t2, $t6
    ctx->r12 = ctx->r10 & ctx->r14;
    // 0x800882A0: beq         $t4, $zero, L_80088320
    if (ctx->r12 == 0) {
        // 0x800882A4: nop

            goto L_80088320;
    }
    // 0x800882A4: nop

    // 0x800882A8: jal         0x8008CE48
    // 0x800882AC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_7;
    // 0x800882AC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_7:
    // 0x800882B0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800882B4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800882B8: lbu         $t9, 0x17($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X17);
    // 0x800882BC: nop

    // 0x800882C0: bne         $t9, $at, L_80088300
    if (ctx->r25 != ctx->r1) {
        // 0x800882C4: nop

            goto L_80088300;
    }
    // 0x800882C4: nop

    // 0x800882C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800882CC:
    // 0x800882CC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800882D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800882D4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800882D8: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x800882DC: lbu         $t3, 0x4BF4($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4BF4);
    // 0x800882E0: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x800882E4: sb          $t3, 0x17($t1)
    MEM_B(0X17, ctx->r9) = ctx->r11;
    // 0x800882E8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800882EC: nop

    // 0x800882F0: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800882F4: slti        $at, $t2, 0x7
    ctx->r1 = SIGNED(ctx->r10) < 0X7 ? 1 : 0;
    // 0x800882F8: bne         $at, $zero, L_800882CC
    if (ctx->r1 != 0) {
        // 0x800882FC: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_800882CC;
    }
    // 0x800882FC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_80088300:
    // 0x80088300: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80088304: nop

    // 0x80088308: lhu         $t4, 0x0($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X0);
    // 0x8008830C: nop

    // 0x80088310: ori         $t7, $t4, 0x200
    ctx->r15 = ctx->r12 | 0X200;
    // 0x80088314: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
    // 0x80088318: b           L_8008833C
    // 0x8008831C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_8008833C;
    // 0x8008831C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_80088320:
    // 0x80088320: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80088324: nop

    // 0x80088328: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x8008832C: b           L_8008833C
    // 0x80088330: nop

        goto L_8008833C;
    // 0x80088330: nop

    // 0x80088334: b           L_8008833C
    // 0x80088338: nop

        goto L_8008833C;
    // 0x80088338: nop

L_8008833C:
    // 0x8008833C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088340: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80088344: jr          $ra
    // 0x80088348: nop

    return;
    // 0x80088348: nop

;}
RECOMP_FUNC void func_8008834C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008834C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80088358: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008835C: jal         0x8008B4EC
    // 0x80088360: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80088360: nop

    after_0:
    // 0x80088364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80088368: jal         0x8008BC70
    // 0x8008836C: nop

    func_8008BC70(rdram, ctx);
        goto after_1;
    // 0x8008836C: nop

    after_1:
    // 0x80088370: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80088374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80088378: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008837C: jal         0x8008B738
    // 0x80088380: addiu       $a1, $t6, 0x17
    ctx->r5 = ADD32(ctx->r14, 0X17);
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80088380: addiu       $a1, $t6, 0x17
    ctx->r5 = ADD32(ctx->r14, 0X17);
    after_2:
    // 0x80088384: addiu       $t7, $zero, 0xE1
    ctx->r15 = ADD32(0, 0XE1);
    // 0x80088388: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008838C: sw          $t7, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r15;
    // 0x80088390: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80088394: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80088398: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x8008839C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800883A0: nop

    // 0x800883A4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800883A8: nop

    // 0x800883AC: andi        $t1, $t0, 0x400
    ctx->r9 = ctx->r8 & 0X400;
    // 0x800883B0: beq         $t1, $zero, L_800883D0
    if (ctx->r9 == 0) {
        // 0x800883B4: nop

            goto L_800883D0;
    }
    // 0x800883B4: nop

    // 0x800883B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800883BC: addiu       $a1, $zero, 0x4003
    ctx->r5 = ADD32(0, 0X4003);
    // 0x800883C0: jal         0x8008B2FC
    // 0x800883C4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_3;
    // 0x800883C4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_3:
    // 0x800883C8: b           L_800883E0
    // 0x800883CC: nop

        goto L_800883E0;
    // 0x800883CC: nop

L_800883D0:
    // 0x800883D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800883D4: addiu       $a1, $zero, 0x4004
    ctx->r5 = ADD32(0, 0X4004);
    // 0x800883D8: jal         0x8008B2FC
    // 0x800883DC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_4;
    // 0x800883DC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_4:
L_800883E0:
    // 0x800883E0: b           L_800883E8
    // 0x800883E4: nop

        goto L_800883E8;
    // 0x800883E4: nop

L_800883E8:
    // 0x800883E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800883EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800883F0: jr          $ra
    // 0x800883F4: nop

    return;
    // 0x800883F4: nop

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
    // 0x800884D0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x800884D4: jal         0x8008BE0C
    // 0x800884D8: addiu       $a1, $a1, 0x17
    ctx->r5 = ADD32(ctx->r5, 0X17);
    func_8008BE0C(rdram, ctx);
        goto after_0;
    // 0x800884D8: addiu       $a1, $a1, 0x17
    ctx->r5 = ADD32(ctx->r5, 0X17);
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
RECOMP_FUNC void func_80088568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088568: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008856C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088570: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80088574: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80088578: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008857C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80088580: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80088584: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80088588: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8008858C: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80088590: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80088594: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80088598: beq         $t0, $zero, L_80088610
    if (ctx->r8 == 0) {
        // 0x8008859C: nop

            goto L_80088610;
    }
    // 0x8008859C: nop

    // 0x800885A0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800885A4: jal         0x8008A518
    // 0x800885A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800885A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800885AC: beq         $v0, $zero, L_80088610
    if (ctx->r2 == 0) {
        // 0x800885B0: nop

            goto L_80088610;
    }
    // 0x800885B0: nop

    // 0x800885B4: lhu         $s0, 0x24($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X24);
    // 0x800885B8: addiu       $at, $zero, 0x4007
    ctx->r1 = ADD32(0, 0X4007);
    // 0x800885BC: beq         $s0, $at, L_80088600
    if (ctx->r16 == ctx->r1) {
        // 0x800885C0: nop

            goto L_80088600;
    }
    // 0x800885C0: nop

    // 0x800885C4: addiu       $at, $zero, 0x4008
    ctx->r1 = ADD32(0, 0X4008);
    // 0x800885C8: beq         $s0, $at, L_800885D8
    if (ctx->r16 == ctx->r1) {
        // 0x800885CC: nop

            goto L_800885D8;
    }
    // 0x800885CC: nop

    // 0x800885D0: b           L_80088610
    // 0x800885D4: nop

        goto L_80088610;
    // 0x800885D4: nop

L_800885D8:
    // 0x800885D8: jal         0x8008CE48
    // 0x800885DC: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x800885DC: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x800885E0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800885E4: nop

    // 0x800885E8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800885EC: nop

    // 0x800885F0: ori         $t3, $t2, 0x200
    ctx->r11 = ctx->r10 | 0X200;
    // 0x800885F4: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x800885F8: b           L_80088664
    // 0x800885FC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80088664;
    // 0x800885FC: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80088600:
    // 0x80088600: jal         0x8008CE48
    // 0x80088604: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80088604: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80088608: b           L_80088664
    // 0x8008860C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_80088664;
    // 0x8008860C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_80088610:
    // 0x80088610: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80088614: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x80088618: lhu         $t4, 0x36($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X36);
    // 0x8008861C: nop

    // 0x80088620: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80088624: beq         $t6, $zero, L_80088654
    if (ctx->r14 == 0) {
        // 0x80088628: nop

            goto L_80088654;
    }
    // 0x80088628: nop

    // 0x8008862C: jal         0x8008CE48
    // 0x80088630: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80088630: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
    // 0x80088634: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80088638: nop

    // 0x8008863C: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x80088640: nop

    // 0x80088644: ori         $t8, $t9, 0x200
    ctx->r24 = ctx->r25 | 0X200;
    // 0x80088648: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x8008864C: b           L_80088664
    // 0x80088650: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80088664;
    // 0x80088650: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80088654:
    // 0x80088654: b           L_80088664
    // 0x80088658: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_80088664;
    // 0x80088658: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x8008865C: b           L_80088664
    // 0x80088660: nop

        goto L_80088664;
    // 0x80088660: nop

L_80088664:
    // 0x80088664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80088668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008866C: jr          $ra
    // 0x80088670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80088670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
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
    // 0x800886A8: addiu       $a1, $t6, 0x17
    ctx->r5 = ADD32(ctx->r14, 0X17);
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x800886A8: addiu       $a1, $t6, 0x17
    ctx->r5 = ADD32(ctx->r14, 0X17);
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
RECOMP_FUNC void func_800886C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800886C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800886CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800886D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800886D4: jal         0x80089170
    // 0x800886D8: nop

    func_80089170(rdram, ctx);
        goto after_0;
    // 0x800886D8: nop

    after_0:
    // 0x800886DC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800886E0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800886E4: lbu         $a2, 0x21($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X21);
    // 0x800886E8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800886EC: jal         0x800898D8
    // 0x800886F0: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    func_800898D8(rdram, ctx);
        goto after_1;
    // 0x800886F0: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    after_1:
    // 0x800886F4: beq         $v0, $zero, L_8008871C
    if (ctx->r2 == 0) {
        // 0x800886F8: nop

            goto L_8008871C;
    }
    // 0x800886F8: nop

    // 0x800886FC: lh          $t7, 0x2C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2C);
    // 0x80088700: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80088704: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x80088708: lh          $a2, 0x28($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X28);
    // 0x8008870C: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    // 0x80088710: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80088714: jal         0x8008A368
    // 0x80088718: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8008A368(rdram, ctx);
        goto after_2;
    // 0x80088718: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
L_8008871C:
    // 0x8008871C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80088720: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80088724: lbu         $a2, 0x22($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X22);
    // 0x80088728: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8008872C: jal         0x800898D8
    // 0x80088730: addiu       $a2, $a2, 0xA
    ctx->r6 = ADD32(ctx->r6, 0XA);
    func_800898D8(rdram, ctx);
        goto after_3;
    // 0x80088730: addiu       $a2, $a2, 0xA
    ctx->r6 = ADD32(ctx->r6, 0XA);
    after_3:
    // 0x80088734: beq         $v0, $zero, L_80088760
    if (ctx->r2 == 0) {
        // 0x80088738: nop

            goto L_80088760;
    }
    // 0x80088738: nop

    // 0x8008873C: lh          $t9, 0x2C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2C);
    // 0x80088740: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80088744: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x80088748: lh          $a2, 0x28($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X28);
    // 0x8008874C: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    // 0x80088750: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80088754: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80088758: jal         0x8008A368
    // 0x8008875C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8008A368(rdram, ctx);
        goto after_4;
    // 0x8008875C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
L_80088760:
    // 0x80088760: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80088764: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80088768: lbu         $a2, 0x23($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X23);
    // 0x8008876C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80088770: jal         0x800898D8
    // 0x80088774: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    func_800898D8(rdram, ctx);
        goto after_5;
    // 0x80088774: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    after_5:
    // 0x80088778: beq         $v0, $zero, L_800887A4
    if (ctx->r2 == 0) {
        // 0x8008877C: nop

            goto L_800887A4;
    }
    // 0x8008877C: nop

    // 0x80088780: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x80088784: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80088788: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x8008878C: lh          $a2, 0x28($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X28);
    // 0x80088790: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    // 0x80088794: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80088798: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8008879C: jal         0x8008A368
    // 0x800887A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8008A368(rdram, ctx);
        goto after_6;
    // 0x800887A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_6:
L_800887A4:
    // 0x800887A4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800887A8: jal         0x8008A518
    // 0x800887AC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008A518(rdram, ctx);
        goto after_7;
    // 0x800887AC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_7:
    // 0x800887B0: beq         $v0, $zero, L_800887DC
    if (ctx->r2 == 0) {
        // 0x800887B4: nop

            goto L_800887DC;
    }
    // 0x800887B4: nop

    // 0x800887B8: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x800887BC: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800887C0: bne         $t4, $at, L_800887DC
    if (ctx->r12 != ctx->r1) {
        // 0x800887C4: nop

            goto L_800887DC;
    }
    // 0x800887C4: nop

    // 0x800887C8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800887CC: nop

    // 0x800887D0: lh          $v0, 0x4($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X4);
    // 0x800887D4: b           L_80088858
    // 0x800887D8: nop

        goto L_80088858;
    // 0x800887D8: nop

L_800887DC:
    // 0x800887DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800887E0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800887E4: jal         0x800898D8
    // 0x800887E8: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    func_800898D8(rdram, ctx);
        goto after_8;
    // 0x800887E8: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    after_8:
    // 0x800887EC: beq         $v0, $zero, L_8008883C
    if (ctx->r2 == 0) {
        // 0x800887F0: nop

            goto L_8008883C;
    }
    // 0x800887F0: nop

    // 0x800887F4: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x800887F8: lh          $t7, 0x2A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2A);
    // 0x800887FC: lh          $t9, 0x28($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X28);
    // 0x80088800: lh          $t0, 0x2C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2C);
    // 0x80088804: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80088808: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x8008880C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80088810: bgez        $a1, L_80088820
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80088814: sra         $t8, $a1, 1
        ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80088820;
    }
    // 0x80088814: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80088818: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8008881C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80088820:
    // 0x80088820: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80088824: bgez        $a2, L_80088834
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80088828: sra         $t1, $a2, 1
        ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80088834;
    }
    // 0x80088828: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x8008882C: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80088830: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80088834:
    // 0x80088834: jal         0x80089B04
    // 0x80088838: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_80089B04(rdram, ctx);
        goto after_9;
    // 0x80088838: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_9:
L_8008883C:
    // 0x8008883C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80088840: nop

    // 0x80088844: lh          $v0, 0x4($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X4);
    // 0x80088848: b           L_80088858
    // 0x8008884C: nop

        goto L_80088858;
    // 0x8008884C: nop

    // 0x80088850: b           L_80088858
    // 0x80088854: nop

        goto L_80088858;
    // 0x80088854: nop

L_80088858:
    // 0x80088858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008885C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80088860: jr          $ra
    // 0x80088864: nop

    return;
    // 0x80088864: nop

;}
RECOMP_FUNC void func_80088868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088868: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008886C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80088870: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80088874: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80088878: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008887C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80088880: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80088884: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80088888: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8008888C: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x80088890: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80088894: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80088898: beq         $t0, $zero, L_80088A3C
    if (ctx->r8 == 0) {
        // 0x8008889C: nop

            goto L_80088A3C;
    }
    // 0x8008889C: nop

    // 0x800888A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800888A4: jal         0x8008A518
    // 0x800888A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800888A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800888AC: beq         $v0, $zero, L_80088A3C
    if (ctx->r2 == 0) {
        // 0x800888B0: nop

            goto L_80088A3C;
    }
    // 0x800888B0: nop

    // 0x800888B4: lhu         $s0, 0x2C($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X2C);
    // 0x800888B8: nop

    // 0x800888BC: slti        $at, $s0, 0x4001
    ctx->r1 = SIGNED(ctx->r16) < 0X4001 ? 1 : 0;
    // 0x800888C0: bne         $at, $zero, L_800888DC
    if (ctx->r1 != 0) {
        // 0x800888C4: nop

            goto L_800888DC;
    }
    // 0x800888C4: nop

    // 0x800888C8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x800888CC: beq         $s0, $at, L_800889F0
    if (ctx->r16 == ctx->r1) {
        // 0x800888D0: nop

            goto L_800889F0;
    }
    // 0x800888D0: nop

    // 0x800888D4: b           L_80088A3C
    // 0x800888D8: nop

        goto L_80088A3C;
    // 0x800888D8: nop

L_800888DC:
    // 0x800888DC: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x800888E0: bne         $at, $zero, L_800888FC
    if (ctx->r1 != 0) {
        // 0x800888E4: nop

            goto L_800888FC;
    }
    // 0x800888E4: nop

    // 0x800888E8: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800888EC: beq         $s0, $at, L_80088A20
    if (ctx->r16 == ctx->r1) {
        // 0x800888F0: nop

            goto L_80088A20;
    }
    // 0x800888F0: nop

    // 0x800888F4: b           L_80088A3C
    // 0x800888F8: nop

        goto L_80088A3C;
    // 0x800888F8: nop

L_800888FC:
    // 0x800888FC: addiu       $t1, $s0, -0x6
    ctx->r9 = ADD32(ctx->r16, -0X6);
    // 0x80088900: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x80088904: beq         $at, $zero, L_80088A3C
    if (ctx->r1 == 0) {
        // 0x80088908: nop

            goto L_80088A3C;
    }
    // 0x80088908: nop

    // 0x8008890C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80088910: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80088914: addu        $at, $at, $t1
    gpr jr_addend_80088920 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80088918: lw          $t1, -0xA6C($at)
    ctx->r9 = ADD32(ctx->r1, -0XA6C);
    // 0x8008891C: nop

    // 0x80088920: jr          $t1
    // 0x80088924: nop

    switch (jr_addend_80088920 >> 2) {
        case 0: goto L_80088928; break;
        case 1: goto L_80088928; break;
        case 2: goto L_80088928; break;
        case 3: goto L_80088A3C; break;
        case 4: goto L_80088968; break;
        case 5: goto L_80088968; break;
        case 6: goto L_80088A3C; break;
        case 7: goto L_800889AC; break;
        case 8: goto L_800889AC; break;
        case 9: goto L_800889AC; break;
        default: switch_error(__func__, 0x80088920, 0x800EF594);
    }
    // 0x80088924: nop

L_80088928:
    // 0x80088928: jal         0x8008CE48
    // 0x8008892C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x8008892C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_1:
    // 0x80088930: lhu         $t2, 0x2C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2C);
    // 0x80088934: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80088938: addiu       $t3, $t2, -0x6
    ctx->r11 = ADD32(ctx->r10, -0X6);
    // 0x8008893C: sb          $t3, 0x21($t4)
    MEM_B(0X21, ctx->r12) = ctx->r11;
    // 0x80088940: lh          $t5, 0x34($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X34);
    // 0x80088944: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80088948: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x8008894C: lh          $a2, 0x30($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X30);
    // 0x80088950: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x80088954: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80088958: jal         0x8008A368
    // 0x8008895C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8008A368(rdram, ctx);
        goto after_2;
    // 0x8008895C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x80088960: b           L_80088A3C
    // 0x80088964: nop

        goto L_80088A3C;
    // 0x80088964: nop

L_80088968:
    // 0x80088968: jal         0x8008CE48
    // 0x8008896C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x8008896C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_3:
    // 0x80088970: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x80088974: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80088978: addiu       $t7, $t6, -0xA
    ctx->r15 = ADD32(ctx->r14, -0XA);
    // 0x8008897C: sb          $t7, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r15;
    // 0x80088980: lh          $t8, 0x34($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X34);
    // 0x80088984: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80088988: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x8008898C: lh          $a2, 0x30($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X30);
    // 0x80088990: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x80088994: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80088998: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8008899C: jal         0x8008A368
    // 0x800889A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8008A368(rdram, ctx);
        goto after_4;
    // 0x800889A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_4:
    // 0x800889A4: b           L_80088A3C
    // 0x800889A8: nop

        goto L_80088A3C;
    // 0x800889A8: nop

L_800889AC:
    // 0x800889AC: jal         0x8008CE48
    // 0x800889B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_5;
    // 0x800889B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_5:
    // 0x800889B4: lhu         $t1, 0x2C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2C);
    // 0x800889B8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800889BC: addiu       $t2, $t1, -0xD
    ctx->r10 = ADD32(ctx->r9, -0XD);
    // 0x800889C0: sb          $t2, 0x23($t3)
    MEM_B(0X23, ctx->r11) = ctx->r10;
    // 0x800889C4: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800889C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800889CC: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x800889D0: lh          $a2, 0x30($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X30);
    // 0x800889D4: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x800889D8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800889DC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800889E0: jal         0x8008A368
    // 0x800889E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8008A368(rdram, ctx);
        goto after_6;
    // 0x800889E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x800889E8: b           L_80088A3C
    // 0x800889EC: nop

        goto L_80088A3C;
    // 0x800889EC: nop

L_800889F0:
    // 0x800889F0: jal         0x8008CE48
    // 0x800889F4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_7;
    // 0x800889F4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_7:
    // 0x800889F8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800889FC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80088A00: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x80088A04: nop

    // 0x80088A08: bne         $t7, $at, L_80088A18
    if (ctx->r15 != ctx->r1) {
        // 0x80088A0C: nop

            goto L_80088A18;
    }
    // 0x80088A0C: nop

    // 0x80088A10: b           L_80088ADC
    // 0x80088A14: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80088ADC;
    // 0x80088A14: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80088A18:
    // 0x80088A18: b           L_80088ADC
    // 0x80088A1C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80088ADC;
    // 0x80088A1C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80088A20:
    // 0x80088A20: jal         0x8008CE48
    // 0x80088A24: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80088A24: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_8:
    // 0x80088A28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80088A2C: jal         0x8008CA00
    // 0x80088A30: nop

    func_8008CA00(rdram, ctx);
        goto after_9;
    // 0x80088A30: nop

    after_9:
    // 0x80088A34: b           L_80088ADC
    // 0x80088A38: nop

        goto L_80088ADC;
    // 0x80088A38: nop

L_80088A3C:
    // 0x80088A3C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80088A40: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x80088A44: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x80088A48: nop

    // 0x80088A4C: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80088A50: beq         $t0, $zero, L_80088A88
    if (ctx->r8 == 0) {
        // 0x80088A54: nop

            goto L_80088A88;
    }
    // 0x80088A54: nop

    // 0x80088A58: jal         0x8008CE48
    // 0x80088A5C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80088A5C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_10:
    // 0x80088A60: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80088A64: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80088A68: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x80088A6C: nop

    // 0x80088A70: bne         $t2, $at, L_80088A80
    if (ctx->r10 != ctx->r1) {
        // 0x80088A74: nop

            goto L_80088A80;
    }
    // 0x80088A74: nop

    // 0x80088A78: b           L_80088ADC
    // 0x80088A7C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_80088ADC;
    // 0x80088A7C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80088A80:
    // 0x80088A80: b           L_80088ADC
    // 0x80088A84: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80088ADC;
    // 0x80088A84: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80088A88:
    // 0x80088A88: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80088A8C: lhu         $t4, 0x11A4($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X11A4);
    // 0x80088A90: lhu         $t3, 0x3E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3E);
    // 0x80088A94: nop

    // 0x80088A98: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80088A9C: beq         $t5, $zero, L_80088AC0
    if (ctx->r13 == 0) {
        // 0x80088AA0: nop

            goto L_80088AC0;
    }
    // 0x80088AA0: nop

    // 0x80088AA4: jal         0x8008CE48
    // 0x80088AA8: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_11;
    // 0x80088AA8: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_11:
    // 0x80088AAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80088AB0: jal         0x8008CA00
    // 0x80088AB4: nop

    func_8008CA00(rdram, ctx);
        goto after_12;
    // 0x80088AB4: nop

    after_12:
    // 0x80088AB8: b           L_80088ADC
    // 0x80088ABC: nop

        goto L_80088ADC;
    // 0x80088ABC: nop

L_80088AC0:
    // 0x80088AC0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80088AC4: nop

    // 0x80088AC8: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80088ACC: b           L_80088ADC
    // 0x80088AD0: nop

        goto L_80088ADC;
    // 0x80088AD0: nop

    // 0x80088AD4: b           L_80088ADC
    // 0x80088AD8: nop

        goto L_80088ADC;
    // 0x80088AD8: nop

L_80088ADC:
    // 0x80088ADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80088AE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80088AE4: jr          $ra
    // 0x80088AE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80088AE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80088AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088AF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80088AF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80088AFC: jal         0x8008B4EC
    // 0x80088B00: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80088B00: nop

    after_0:
    // 0x80088B04: b           L_80088B0C
    // 0x80088B08: nop

        goto L_80088B0C;
    // 0x80088B08: nop

L_80088B0C:
    // 0x80088B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088B14: jr          $ra
    // 0x80088B18: nop

    return;
    // 0x80088B18: nop

;}
RECOMP_FUNC void func_80088B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80088B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088B24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80088B28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80088B2C: jal         0x8008A46C
    // 0x80088B30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80088B30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80088B34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80088B38: jal         0x80089170
    // 0x80088B3C: nop

    func_80089170(rdram, ctx);
        goto after_1;
    // 0x80088B3C: nop

    after_1:
    // 0x80088B40: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80088B44: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80088B48: jal         0x800898D8
    // 0x80088B4C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800898D8(rdram, ctx);
        goto after_2;
    // 0x80088B4C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_2:
    // 0x80088B50: beq         $v0, $zero, L_80088BA0
    if (ctx->r2 == 0) {
        // 0x80088B54: nop

            goto L_80088BA0;
    }
    // 0x80088B54: nop

    // 0x80088B58: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80088B5C: lh          $t7, 0x22($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X22);
    // 0x80088B60: lh          $t9, 0x20($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20);
    // 0x80088B64: lh          $t0, 0x24($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X24);
    // 0x80088B68: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80088B6C: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x80088B70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80088B74: bgez        $a1, L_80088B84
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80088B78: sra         $t8, $a1, 1
        ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80088B84;
    }
    // 0x80088B78: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80088B7C: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80088B80: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80088B84:
    // 0x80088B84: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80088B88: bgez        $a2, L_80088B98
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80088B8C: sra         $t1, $a2, 1
        ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
            goto L_80088B98;
    }
    // 0x80088B8C: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80088B90: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x80088B94: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80088B98:
    // 0x80088B98: jal         0x80089B04
    // 0x80088B9C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    func_80089B04(rdram, ctx);
        goto after_3;
    // 0x80088B9C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_3:
L_80088BA0:
    // 0x80088BA0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80088BA4: nop

    // 0x80088BA8: lh          $v0, 0x4($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X4);
    // 0x80088BAC: b           L_80088BBC
    // 0x80088BB0: nop

        goto L_80088BBC;
    // 0x80088BB0: nop

    // 0x80088BB4: b           L_80088BBC
    // 0x80088BB8: nop

        goto L_80088BBC;
    // 0x80088BB8: nop

L_80088BBC:
    // 0x80088BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088BC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80088BC4: jr          $ra
    // 0x80088BC8: nop

    return;
    // 0x80088BC8: nop

;}
