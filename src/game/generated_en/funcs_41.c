#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void ContPak_GetAvailableSlots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE580: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AE584: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800AE588: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800AE58C:
    // 0x800AE58C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AE590: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE594: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AE598: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AE59C: lw          $t8, 0x15D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X15D8);
    // 0x800AE5A0: nop

    // 0x800AE5A4: bne         $t8, $zero, L_800AE5BC
    if (ctx->r24 != 0) {
        // 0x800AE5A8: nop

            goto L_800AE5BC;
    }
    // 0x800AE5A8: nop

    // 0x800AE5AC: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800AE5B0: nop

    // 0x800AE5B4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800AE5B8: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_800AE5BC:
    // 0x800AE5BC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800AE5C0: nop

    // 0x800AE5C4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800AE5C8: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x800AE5CC: bne         $at, $zero, L_800AE58C
    if (ctx->r1 != 0) {
        // 0x800AE5D0: sw          $t2, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r10;
            goto L_800AE58C;
    }
    // 0x800AE5D0: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800AE5D4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800AE5D8: b           L_800AE5E8
    // 0x800AE5DC: nop

        goto L_800AE5E8;
    // 0x800AE5DC: nop

    // 0x800AE5E0: b           L_800AE5E8
    // 0x800AE5E4: nop

        goto L_800AE5E8;
    // 0x800AE5E4: nop

L_800AE5E8:
    // 0x800AE5E8: jr          $ra
    // 0x800AE5EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AE5EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void ContPak_SetFileDeleteParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE5F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE5F4: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE5F8: nop

    // 0x800AE5FC: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AE600: beq         $t7, $zero, L_800AE610
    if (ctx->r15 == 0) {
        // 0x800AE604: nop

            goto L_800AE610;
    }
    // 0x800AE604: nop

    // 0x800AE608: jr          $ra
    // 0x800AE60C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE60C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE610:
    // 0x800AE610: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE614: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE618: nop

    // 0x800AE61C: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AE620: beq         $t9, $zero, L_800AE630
    if (ctx->r25 == 0) {
        // 0x800AE624: nop

            goto L_800AE630;
    }
    // 0x800AE624: nop

    // 0x800AE628: jr          $ra
    // 0x800AE62C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE62C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE630:
    // 0x800AE630: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE634: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800AE638: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE63C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x800AE640: sw          $t1, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r9;
    // 0x800AE644: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE648: sw          $a0, 0x1640($at)
    MEM_W(0X1640, ctx->r1) = ctx->r4;
    // 0x800AE64C: jr          $ra
    // 0x800AE650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE654: jr          $ra
    // 0x800AE658: nop

    return;
    // 0x800AE658: nop

    // 0x800AE65C: jr          $ra
    // 0x800AE660: nop

    return;
    // 0x800AE660: nop

;}
RECOMP_FUNC void ContPak_DeleteFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE664: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AE66C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE670: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE674: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800AE678: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE67C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE680: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE684: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE688: lw          $t8, 0x1640($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1640);
    // 0x800AE68C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE690: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AE694: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800AE698: lw          $t0, 0x15D8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X15D8);
    // 0x800AE69C: nop

    // 0x800AE6A0: bne         $t0, $zero, L_800AE798
    if (ctx->r8 != 0) {
        // 0x800AE6A4: nop

            goto L_800AE798;
    }
    // 0x800AE6A4: nop

    // 0x800AE6A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE6AC: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE6B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE6B4: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x800AE6B8: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
    // 0x800AE6BC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE6C0: lw          $t3, 0x1640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1640);
    // 0x800AE6C4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE6C8: addiu       $t5, $t5, 0x13D0
    ctx->r13 = ADD32(ctx->r13, 0X13D0);
    // 0x800AE6CC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800AE6D0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AE6D4: lhu         $a1, 0x8($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X8);
    // 0x800AE6D8: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x800AE6DC: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x800AE6E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE6E4: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AE6E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800AE6EC: jal         0x800C6BE0
    // 0x800AE6F0: addiu       $a3, $t6, 0xE
    ctx->r7 = ADD32(ctx->r14, 0XE);
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE6F0: addiu       $a3, $t6, 0xE
    ctx->r7 = ADD32(ctx->r14, 0XE);
    after_0:
    // 0x800AE6F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE6F8: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AE6FC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE700: lw          $t8, 0x1684($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1684);
    // 0x800AE704: nop

    // 0x800AE708: bne         $t8, $zero, L_800AE790
    if (ctx->r24 != 0) {
        // 0x800AE70C: nop

            goto L_800AE790;
    }
    // 0x800AE70C: nop

    // 0x800AE710: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE714: lw          $t0, 0x1640($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1640);
    // 0x800AE718: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE71C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AE720: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800AE724: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800AE728: sw          $t9, 0x15D8($at)
    MEM_W(0X15D8, ctx->r1) = ctx->r25;
    // 0x800AE72C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE730: lw          $t3, 0x1640($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1640);
    // 0x800AE734: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE738: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800AE73C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800AE740: lw          $t5, 0x13D0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X13D0);
    // 0x800AE744: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AE748: lw          $t2, 0x1638($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1638);
    // 0x800AE74C: addiu       $t6, $t5, 0xFF
    ctx->r14 = ADD32(ctx->r13, 0XFF);
    // 0x800AE750: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x800AE754: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE758: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800AE75C: sw          $t8, 0x1638($at)
    MEM_W(0X1638, ctx->r1) = ctx->r24;
    // 0x800AE760: jal         0x800AE40C
    // 0x800AE764: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_1;
    // 0x800AE764: nop

    after_1:
    // 0x800AE768: bgez        $v0, L_800AE790
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AE76C: nop

            goto L_800AE790;
    }
    // 0x800AE76C: nop

    // 0x800AE770: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE774: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AE778: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800AE77C: and         $t9, $t0, $at
    ctx->r25 = ctx->r8 & ctx->r1;
    // 0x800AE780: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE784: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AE788: b           L_800AE7EC
    // 0x800AE78C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE7EC;
    // 0x800AE78C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE790:
    // 0x800AE790: b           L_800AE7C4
    // 0x800AE794: nop

        goto L_800AE7C4;
    // 0x800AE794: nop

L_800AE798:
    // 0x800AE798: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE79C: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE7A0: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800AE7A4: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800AE7A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE7AC: sw          $t3, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r11;
    // 0x800AE7B0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800AE7B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE7B8: sw          $t4, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r12;
    // 0x800AE7BC: b           L_800AE7EC
    // 0x800AE7C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE7EC;
    // 0x800AE7C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE7C4:
    // 0x800AE7C4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE7C8: lw          $t5, 0x129C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X129C);
    // 0x800AE7CC: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800AE7D0: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800AE7D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE7D8: sw          $t6, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r14;
    // 0x800AE7DC: b           L_800AE7EC
    // 0x800AE7E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE7EC;
    // 0x800AE7E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE7E4: b           L_800AE7EC
    // 0x800AE7E8: nop

        goto L_800AE7EC;
    // 0x800AE7E8: nop

L_800AE7EC:
    // 0x800AE7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE7F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE7F4: jr          $ra
    // 0x800AE7F8: nop

    return;
    // 0x800AE7F8: nop

;}
RECOMP_FUNC void ContPak_GetDeleteFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE7FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE800: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE804: nop

    // 0x800AE808: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x800AE80C: beq         $t7, $zero, L_800AE81C
    if (ctx->r15 == 0) {
        // 0x800AE810: nop

            goto L_800AE81C;
    }
    // 0x800AE810: nop

    // 0x800AE814: jr          $ra
    // 0x800AE818: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE818: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE81C:
    // 0x800AE81C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE820: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE824: nop

    // 0x800AE828: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x800AE82C: beq         $t9, $zero, L_800AE83C
    if (ctx->r25 == 0) {
        // 0x800AE830: nop

            goto L_800AE83C;
    }
    // 0x800AE830: nop

    // 0x800AE834: jr          $ra
    // 0x800AE838: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE838: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE83C:
    // 0x800AE83C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE840: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AE844: nop

    // 0x800AE848: beq         $t0, $zero, L_800AE868
    if (ctx->r8 == 0) {
        // 0x800AE84C: nop

            goto L_800AE868;
    }
    // 0x800AE84C: nop

    // 0x800AE850: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AE854: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AE858: nop

    // 0x800AE85C: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AE860: jr          $ra
    // 0x800AE864: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AE864: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AE868:
    // 0x800AE868: jr          $ra
    // 0x800AE86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE870: jr          $ra
    // 0x800AE874: nop

    return;
    // 0x800AE874: nop

    // 0x800AE878: jr          $ra
    // 0x800AE87C: nop

    return;
    // 0x800AE87C: nop

;}
RECOMP_FUNC void ContPak_SetOpenFileParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE880: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE884: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE888: nop

    // 0x800AE88C: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AE890: beq         $t7, $zero, L_800AE8A0
    if (ctx->r15 == 0) {
        // 0x800AE894: nop

            goto L_800AE8A0;
    }
    // 0x800AE894: nop

    // 0x800AE898: jr          $ra
    // 0x800AE89C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE89C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE8A0:
    // 0x800AE8A0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE8A4: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE8A8: nop

    // 0x800AE8AC: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AE8B0: beq         $t9, $zero, L_800AE8C0
    if (ctx->r25 == 0) {
        // 0x800AE8B4: nop

            goto L_800AE8C0;
    }
    // 0x800AE8B4: nop

    // 0x800AE8B8: jr          $ra
    // 0x800AE8BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE8BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE8C0:
    // 0x800AE8C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE8C4: sw          $a0, 0x1654($at)
    MEM_W(0X1654, ctx->r1) = ctx->r4;
    // 0x800AE8C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE8CC: sw          $a1, 0x1660($at)
    MEM_W(0X1660, ctx->r1) = ctx->r5;
    // 0x800AE8D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE8D4: sw          $a2, 0x1674($at)
    MEM_W(0X1674, ctx->r1) = ctx->r6;
    // 0x800AE8D8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE8DC: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800AE8E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE8E4: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x800AE8E8: sw          $t1, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r9;
    // 0x800AE8EC: jr          $ra
    // 0x800AE8F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE8F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE8F4: jr          $ra
    // 0x800AE8F8: nop

    return;
    // 0x800AE8F8: nop

    // 0x800AE8FC: jr          $ra
    // 0x800AE900: nop

    return;
    // 0x800AE900: nop

;}
RECOMP_FUNC void ContPak_OpenFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE904: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AE908: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AE90C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE910: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE914: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800AE918: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE91C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE920: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE924: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE928: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE92C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE930: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x800AE934: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AE938: jal         0x800AE40C
    // 0x800AE93C: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_0;
    // 0x800AE93C: nop

    after_0:
    // 0x800AE940: bgez        $v0, L_800AE968
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AE944: nop

            goto L_800AE968;
    }
    // 0x800AE944: nop

    // 0x800AE948: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE94C: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AE950: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800AE954: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AE958: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE95C: sw          $t1, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r9;
    // 0x800AE960: b           L_800AE9FC
    // 0x800AE964: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE9FC;
    // 0x800AE964: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE968:
    // 0x800AE968: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AE96C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE970: lw          $t3, 0x1674($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1674);
    // 0x800AE974: lw          $t2, 0x1660($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1660);
    // 0x800AE978: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE97C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800AE980: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800AE984: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AE988: addiu       $t4, $t4, 0x167C
    ctx->r12 = ADD32(ctx->r12, 0X167C);
    // 0x800AE98C: lw          $a3, 0x1654($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1654);
    // 0x800AE990: lw          $a2, 0x164C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X164C);
    // 0x800AE994: lhu         $a1, 0x1646($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X1646);
    // 0x800AE998: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE99C: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AE9A0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800AE9A4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AE9A8: jal         0x800AE01C
    // 0x800AE9AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    ContPak_GetPfsFile(rdram, ctx);
        goto after_1;
    // 0x800AE9AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x800AE9B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE9B4: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AE9B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE9BC: lw          $t5, 0x1684($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1684);
    // 0x800AE9C0: nop

    // 0x800AE9C4: bne         $t5, $zero, L_800AE9D4
    if (ctx->r13 != 0) {
        // 0x800AE9C8: nop

            goto L_800AE9D4;
    }
    // 0x800AE9C8: nop

    // 0x800AE9CC: jal         0x800AE40C
    // 0x800AE9D0: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_2;
    // 0x800AE9D0: nop

    after_2:
L_800AE9D4:
    // 0x800AE9D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE9D8: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x800AE9DC: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800AE9E0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE9E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE9E8: sw          $t7, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r15;
    // 0x800AE9EC: b           L_800AE9FC
    // 0x800AE9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE9FC;
    // 0x800AE9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE9F4: b           L_800AE9FC
    // 0x800AE9F8: nop

        goto L_800AE9FC;
    // 0x800AE9F8: nop

L_800AE9FC:
    // 0x800AE9FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AEA00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800AEA04: jr          $ra
    // 0x800AEA08: nop

    return;
    // 0x800AEA08: nop

;}
RECOMP_FUNC void ContPak_GetOpenFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEA10: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEA14: nop

    // 0x800AEA18: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x800AEA1C: beq         $t7, $zero, L_800AEA2C
    if (ctx->r15 == 0) {
        // 0x800AEA20: nop

            goto L_800AEA2C;
    }
    // 0x800AEA20: nop

    // 0x800AEA24: jr          $ra
    // 0x800AEA28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEA28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEA2C:
    // 0x800AEA2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEA30: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEA34: nop

    // 0x800AEA38: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x800AEA3C: beq         $t9, $zero, L_800AEA4C
    if (ctx->r25 == 0) {
        // 0x800AEA40: nop

            goto L_800AEA4C;
    }
    // 0x800AEA40: nop

    // 0x800AEA44: jr          $ra
    // 0x800AEA48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEA48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEA4C:
    // 0x800AEA4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEA50: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AEA54: nop

    // 0x800AEA58: beq         $t0, $zero, L_800AEA78
    if (ctx->r8 == 0) {
        // 0x800AEA5C: nop

            goto L_800AEA78;
    }
    // 0x800AEA5C: nop

    // 0x800AEA60: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEA64: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AEA68: nop

    // 0x800AEA6C: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AEA70: jr          $ra
    // 0x800AEA74: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AEA74: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AEA78:
    // 0x800AEA78: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEA7C: lw          $v0, 0x167C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X167C);
    // 0x800AEA80: jr          $ra
    // 0x800AEA84: nop

    return;
    // 0x800AEA84: nop

    // 0x800AEA88: jr          $ra
    // 0x800AEA8C: nop

    return;
    // 0x800AEA8C: nop

    // 0x800AEA90: jr          $ra
    // 0x800AEA94: nop

    return;
    // 0x800AEA94: nop

;}
RECOMP_FUNC void ContPak_SetFileFindParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEA98: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEA9C: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEAA0: nop

    // 0x800AEAA4: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AEAA8: beq         $t7, $zero, L_800AEAB8
    if (ctx->r15 == 0) {
        // 0x800AEAAC: nop

            goto L_800AEAB8;
    }
    // 0x800AEAAC: nop

    // 0x800AEAB0: jr          $ra
    // 0x800AEAB4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEAB4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEAB8:
    // 0x800AEAB8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEABC: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEAC0: nop

    // 0x800AEAC4: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AEAC8: beq         $t9, $zero, L_800AEAD8
    if (ctx->r25 == 0) {
        // 0x800AEACC: nop

            goto L_800AEAD8;
    }
    // 0x800AEACC: nop

    // 0x800AEAD0: jr          $ra
    // 0x800AEAD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEAD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEAD8:
    // 0x800AEAD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEADC: sw          $a0, 0x1654($at)
    MEM_W(0X1654, ctx->r1) = ctx->r4;
    // 0x800AEAE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEAE4: sw          $a1, 0x1660($at)
    MEM_W(0X1660, ctx->r1) = ctx->r5;
    // 0x800AEAE8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEAEC: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800AEAF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEAF4: ori         $t1, $t0, 0x100
    ctx->r9 = ctx->r8 | 0X100;
    // 0x800AEAF8: sw          $t1, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r9;
    // 0x800AEAFC: jr          $ra
    // 0x800AEB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AEB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEB04: jr          $ra
    // 0x800AEB08: nop

    return;
    // 0x800AEB08: nop

    // 0x800AEB0C: jr          $ra
    // 0x800AEB10: nop

    return;
    // 0x800AEB10: nop

;}
RECOMP_FUNC void ContPak_FindFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEB14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AEB18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AEB1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEB20: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEB24: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800AEB28: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AEB2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEB30: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AEB34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEB38: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEB3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEB40: ori         $t9, $t8, 0x200
    ctx->r25 = ctx->r24 | 0X200;
    // 0x800AEB44: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AEB48: jal         0x800AE40C
    // 0x800AEB4C: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_0;
    // 0x800AEB4C: nop

    after_0:
    // 0x800AEB50: bgez        $v0, L_800AEB78
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AEB54: nop

            goto L_800AEB78;
    }
    // 0x800AEB54: nop

    // 0x800AEB58: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEB5C: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AEB60: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800AEB64: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AEB68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEB6C: sw          $t1, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r9;
    // 0x800AEB70: b           L_800AEBE4
    // 0x800AEB74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AEBE4;
    // 0x800AEB74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEB78:
    // 0x800AEB78: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AEB7C: lw          $t2, 0x1660($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1660);
    // 0x800AEB80: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AEB84: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800AEB88: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800AEB8C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AEB90: addiu       $t3, $t3, 0x167C
    ctx->r11 = ADD32(ctx->r11, 0X167C);
    // 0x800AEB94: lw          $a3, 0x1654($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1654);
    // 0x800AEB98: lw          $a2, 0x164C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X164C);
    // 0x800AEB9C: lhu         $a1, 0x1646($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X1646);
    // 0x800AEBA0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AEBA4: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AEBA8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AEBAC: jal         0x800ADED0
    // 0x800AEBB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    ContPak_FindPfsSlot(rdram, ctx);
        goto after_1;
    // 0x800AEBB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x800AEBB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEBB8: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AEBBC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AEBC0: lw          $t4, 0x129C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X129C);
    // 0x800AEBC4: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800AEBC8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800AEBCC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEBD0: sw          $t5, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r13;
    // 0x800AEBD4: b           L_800AEBE4
    // 0x800AEBD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AEBE4;
    // 0x800AEBD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEBDC: b           L_800AEBE4
    // 0x800AEBE0: nop

        goto L_800AEBE4;
    // 0x800AEBE0: nop

L_800AEBE4:
    // 0x800AEBE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEBE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AEBEC: jr          $ra
    // 0x800AEBF0: nop

    return;
    // 0x800AEBF0: nop

;}
RECOMP_FUNC void ContPak_GetFindFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEBF4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEBF8: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEBFC: nop

    // 0x800AEC00: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x800AEC04: beq         $t7, $zero, L_800AEC14
    if (ctx->r15 == 0) {
        // 0x800AEC08: nop

            goto L_800AEC14;
    }
    // 0x800AEC08: nop

    // 0x800AEC0C: jr          $ra
    // 0x800AEC10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEC10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEC14:
    // 0x800AEC14: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEC18: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEC1C: nop

    // 0x800AEC20: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x800AEC24: beq         $t9, $zero, L_800AEC34
    if (ctx->r25 == 0) {
        // 0x800AEC28: nop

            goto L_800AEC34;
    }
    // 0x800AEC28: nop

    // 0x800AEC2C: jr          $ra
    // 0x800AEC30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEC30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEC34:
    // 0x800AEC34: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEC38: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AEC3C: nop

    // 0x800AEC40: beq         $t0, $zero, L_800AEC60
    if (ctx->r8 == 0) {
        // 0x800AEC44: nop

            goto L_800AEC60;
    }
    // 0x800AEC44: nop

    // 0x800AEC48: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEC4C: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AEC50: nop

    // 0x800AEC54: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AEC58: jr          $ra
    // 0x800AEC5C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AEC5C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AEC60:
    // 0x800AEC60: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEC64: lw          $v0, 0x167C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X167C);
    // 0x800AEC68: jr          $ra
    // 0x800AEC6C: nop

    return;
    // 0x800AEC6C: nop

    // 0x800AEC70: jr          $ra
    // 0x800AEC74: nop

    return;
    // 0x800AEC74: nop

    // 0x800AEC78: jr          $ra
    // 0x800AEC7C: nop

    return;
    // 0x800AEC7C: nop

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
RECOMP_FUNC void ContPak_WriteFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AED0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AED10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AED14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AED18: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AED1C: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800AED20: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AED24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AED28: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AED2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AED30: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AED34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AED38: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800AED3C: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AED40: jal         0x800AE40C
    // 0x800AED44: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_0;
    // 0x800AED44: nop

    after_0:
    // 0x800AED48: bgez        $v0, L_800AED70
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AED4C: nop

            goto L_800AED70;
    }
    // 0x800AED4C: nop

    // 0x800AED50: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AED54: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AED58: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800AED5C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AED60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AED64: sw          $t1, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r9;
    // 0x800AED68: b           L_800AEDD8
    // 0x800AED6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AEDD8;
    // 0x800AED6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AED70:
    // 0x800AED70: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AED74: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AED78: lw          $t3, 0x1670($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1670);
    // 0x800AED7C: lw          $t2, 0x1674($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1674);
    // 0x800AED80: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AED84: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800AED88: lw          $a3, 0x1678($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1678);
    // 0x800AED8C: lw          $a1, 0x167C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X167C);
    // 0x800AED90: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AED94: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AED98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AED9C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AEDA0: jal         0x800C72EC
    // 0x800AEDA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_1;
    // 0x800AEDA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x800AEDA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEDAC: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AEDB0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AEDB4: lw          $t4, 0x129C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X129C);
    // 0x800AEDB8: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800AEDBC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800AEDC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEDC4: sw          $t5, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r13;
    // 0x800AEDC8: b           L_800AEDD8
    // 0x800AEDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AEDD8;
    // 0x800AEDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEDD0: b           L_800AEDD8
    // 0x800AEDD4: nop

        goto L_800AEDD8;
    // 0x800AEDD4: nop

L_800AEDD8:
    // 0x800AEDD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEDDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AEDE0: jr          $ra
    // 0x800AEDE4: nop

    return;
    // 0x800AEDE4: nop

;}
RECOMP_FUNC void ContPak_GetWriteFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEDE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEDEC: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEDF0: nop

    // 0x800AEDF4: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800AEDF8: beq         $t7, $zero, L_800AEE08
    if (ctx->r15 == 0) {
        // 0x800AEDFC: nop

            goto L_800AEE08;
    }
    // 0x800AEDFC: nop

    // 0x800AEE00: jr          $ra
    // 0x800AEE04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEE04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEE08:
    // 0x800AEE08: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEE0C: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEE10: nop

    // 0x800AEE14: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x800AEE18: beq         $t9, $zero, L_800AEE28
    if (ctx->r25 == 0) {
        // 0x800AEE1C: nop

            goto L_800AEE28;
    }
    // 0x800AEE1C: nop

    // 0x800AEE20: jr          $ra
    // 0x800AEE24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEE24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEE28:
    // 0x800AEE28: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEE2C: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AEE30: nop

    // 0x800AEE34: beq         $t0, $zero, L_800AEE54
    if (ctx->r8 == 0) {
        // 0x800AEE38: nop

            goto L_800AEE54;
    }
    // 0x800AEE38: nop

    // 0x800AEE3C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEE40: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AEE44: nop

    // 0x800AEE48: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AEE4C: jr          $ra
    // 0x800AEE50: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AEE50: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AEE54:
    // 0x800AEE54: jr          $ra
    // 0x800AEE58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AEE58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEE5C: jr          $ra
    // 0x800AEE60: nop

    return;
    // 0x800AEE60: nop

    // 0x800AEE64: jr          $ra
    // 0x800AEE68: nop

    return;
    // 0x800AEE68: nop

;}
RECOMP_FUNC void ContPak_SetFileReadParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEE6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEE70: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEE74: nop

    // 0x800AEE78: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AEE7C: beq         $t7, $zero, L_800AEE8C
    if (ctx->r15 == 0) {
        // 0x800AEE80: nop

            goto L_800AEE8C;
    }
    // 0x800AEE80: nop

    // 0x800AEE84: jr          $ra
    // 0x800AEE88: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEE88: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEE8C:
    // 0x800AEE8C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEE90: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEE94: nop

    // 0x800AEE98: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AEE9C: beq         $t9, $zero, L_800AEEAC
    if (ctx->r25 == 0) {
        // 0x800AEEA0: nop

            goto L_800AEEAC;
    }
    // 0x800AEEA0: nop

    // 0x800AEEA4: jr          $ra
    // 0x800AEEA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEEA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEEAC:
    // 0x800AEEAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEEB0: sw          $a0, 0x167C($at)
    MEM_W(0X167C, ctx->r1) = ctx->r4;
    // 0x800AEEB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEEB8: sw          $a1, 0x1678($at)
    MEM_W(0X1678, ctx->r1) = ctx->r5;
    // 0x800AEEBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEEC0: sw          $a2, 0x1674($at)
    MEM_W(0X1674, ctx->r1) = ctx->r6;
    // 0x800AEEC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEEC8: sw          $a3, 0x1670($at)
    MEM_W(0X1670, ctx->r1) = ctx->r7;
    // 0x800AEECC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEED0: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800AEED4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEED8: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x800AEEDC: sw          $t1, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r9;
    // 0x800AEEE0: jr          $ra
    // 0x800AEEE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AEEE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEEE8: jr          $ra
    // 0x800AEEEC: nop

    return;
    // 0x800AEEEC: nop

    // 0x800AEEF0: jr          $ra
    // 0x800AEEF4: nop

    return;
    // 0x800AEEF4: nop

;}
RECOMP_FUNC void ContPak_ReadFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEEF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AEEFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AEF00: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEF04: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEF08: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800AEF0C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AEF10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEF14: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AEF18: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEF1C: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEF20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEF24: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x800AEF28: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AEF2C: jal         0x800AE40C
    // 0x800AEF30: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_0;
    // 0x800AEF30: nop

    after_0:
    // 0x800AEF34: bgez        $v0, L_800AEF5C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AEF38: nop

            goto L_800AEF5C;
    }
    // 0x800AEF38: nop

    // 0x800AEF3C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEF40: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AEF44: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800AEF48: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AEF4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEF50: sw          $t1, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r9;
    // 0x800AEF54: b           L_800AEFC4
    // 0x800AEF58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AEFC4;
    // 0x800AEF58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEF5C:
    // 0x800AEF5C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AEF60: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AEF64: lw          $t3, 0x1670($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1670);
    // 0x800AEF68: lw          $t2, 0x1674($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1674);
    // 0x800AEF6C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AEF70: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800AEF74: lw          $a3, 0x1678($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1678);
    // 0x800AEF78: lw          $a1, 0x167C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X167C);
    // 0x800AEF7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AEF80: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AEF84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AEF88: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AEF8C: jal         0x800C72EC
    // 0x800AEF90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_1;
    // 0x800AEF90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x800AEF94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEF98: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AEF9C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AEFA0: lw          $t4, 0x129C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X129C);
    // 0x800AEFA4: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800AEFA8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800AEFAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AEFB0: sw          $t5, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r13;
    // 0x800AEFB4: b           L_800AEFC4
    // 0x800AEFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AEFC4;
    // 0x800AEFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEFBC: b           L_800AEFC4
    // 0x800AEFC0: nop

        goto L_800AEFC4;
    // 0x800AEFC0: nop

L_800AEFC4:
    // 0x800AEFC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEFC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AEFCC: jr          $ra
    // 0x800AEFD0: nop

    return;
    // 0x800AEFD0: nop

;}
RECOMP_FUNC void ContPak_GetReadFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEFD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEFD8: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEFDC: nop

    // 0x800AEFE0: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x800AEFE4: beq         $t7, $zero, L_800AEFF4
    if (ctx->r15 == 0) {
        // 0x800AEFE8: nop

            goto L_800AEFF4;
    }
    // 0x800AEFE8: nop

    // 0x800AEFEC: jr          $ra
    // 0x800AEFF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEFF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEFF4:
    // 0x800AEFF4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEFF8: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEFFC: nop

    // 0x800AF000: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800AF004: beq         $t9, $zero, L_800AF014
    if (ctx->r25 == 0) {
        // 0x800AF008: nop

            goto L_800AF014;
    }
    // 0x800AF008: nop

    // 0x800AF00C: jr          $ra
    // 0x800AF010: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AF010: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AF014:
    // 0x800AF014: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AF018: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AF01C: nop

    // 0x800AF020: beq         $t0, $zero, L_800AF040
    if (ctx->r8 == 0) {
        // 0x800AF024: nop

            goto L_800AF040;
    }
    // 0x800AF024: nop

    // 0x800AF028: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AF02C: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AF030: nop

    // 0x800AF034: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AF038: jr          $ra
    // 0x800AF03C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AF03C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AF040:
    // 0x800AF040: jr          $ra
    // 0x800AF044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AF044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AF048: jr          $ra
    // 0x800AF04C: nop

    return;
    // 0x800AF04C: nop

    // 0x800AF050: jr          $ra
    // 0x800AF054: nop

    return;
    // 0x800AF054: nop

;}
RECOMP_FUNC void func_800AF058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF058: nop

    // 0x800AF05C: nop

;}
RECOMP_FUNC void func_800AF060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF060: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AF064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF068: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800AF06C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AF070: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AF074: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x800AF078: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF07C: sh          $t6, -0x490($at)
    MEM_H(-0X490, ctx->r1) = ctx->r14;
    // 0x800AF080: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x800AF084: nop

    // 0x800AF088: addu        $a0, $t7, $t7
    ctx->r4 = ADD32(ctx->r15, ctx->r15);
    // 0x800AF08C: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x800AF090: jal         0x800BC6EC
    // 0x800AF094: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800AF094: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x800AF098: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF09C: sw          $v0, -0x784($at)
    MEM_W(-0X784, ctx->r1) = ctx->r2;
    // 0x800AF0A0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800AF0A4: lw          $t9, -0x784($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X784);
    // 0x800AF0A8: nop

    // 0x800AF0AC: bne         $t9, $zero, L_800AF0BC
    if (ctx->r25 != 0) {
        // 0x800AF0B0: nop

            goto L_800AF0BC;
    }
    // 0x800AF0B0: nop

    // 0x800AF0B4: b           L_800AF170
    // 0x800AF0B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AF170;
    // 0x800AF0B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AF0BC:
    // 0x800AF0BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF0C0: sb          $zero, 0x448($at)
    MEM_B(0X448, ctx->r1) = 0;
    // 0x800AF0C4: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
L_800AF0C8:
    // 0x800AF0C8: lhu         $t0, 0x2E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF0CC: lhu         $t2, 0x2E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF0D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF0D4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800AF0D8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800AF0DC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800AF0E0: addiu       $t4, $t4, -0x450
    ctx->r12 = ADD32(ctx->r12, -0X450);
    // 0x800AF0E4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800AF0E8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800AF0EC: sw          $zero, -0x44C($at)
    MEM_W(-0X44C, ctx->r1) = 0;
    // 0x800AF0F0: lw          $s1, 0x4($t5)
    ctx->r17 = MEM_W(ctx->r13, 0X4);
    // 0x800AF0F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF0F8: sw          $s1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r17;
    // 0x800AF0FC: lhu         $t6, 0x2E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF100: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF104: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800AF108: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AF10C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800AF110: sw          $s0, -0x46C($at)
    MEM_W(-0X46C, ctx->r1) = ctx->r16;
    // 0x800AF114: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF118: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800AF11C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AF120: sw          $s0, -0x470($at)
    MEM_W(-0X470, ctx->r1) = ctx->r16;
    // 0x800AF124: lhu         $t0, 0x2E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2E);
    // 0x800AF128: nop

    // 0x800AF12C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800AF130: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800AF134: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800AF138: bne         $at, $zero, L_800AF0C8
    if (ctx->r1 != 0) {
        // 0x800AF13C: sh          $t1, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r9;
            goto L_800AF0C8;
    }
    // 0x800AF13C: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x800AF140: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800AF144: addiu       $t3, $t3, -0x470
    ctx->r11 = ADD32(ctx->r11, -0X470);
    // 0x800AF148: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF14C: sw          $t3, -0x45C($at)
    MEM_W(-0X45C, ctx->r1) = ctx->r11;
    // 0x800AF150: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800AF154: addiu       $t4, $t4, -0x450
    ctx->r12 = ADD32(ctx->r12, -0X450);
    // 0x800AF158: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF15C: sw          $t4, -0x440($at)
    MEM_W(-0X440, ctx->r1) = ctx->r12;
    // 0x800AF160: b           L_800AF170
    // 0x800AF164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AF170;
    // 0x800AF164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AF168: b           L_800AF170
    // 0x800AF16C: nop

        goto L_800AF170;
    // 0x800AF16C: nop

L_800AF170:
    // 0x800AF170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF174: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AF178: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AF17C: jr          $ra
    // 0x800AF180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AF180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800AF184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AF188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AF18C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800AF190: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800AF194: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800AF198: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800AF19C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF1A0: swc1        $f4, 0x430($at)
    MEM_W(0X430, ctx->r1) = ctx->f4.u32l;
    // 0x800AF1A4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AF1A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF1AC: swc1        $f6, 0x438($at)
    MEM_W(0X438, ctx->r1) = ctx->f6.u32l;
    // 0x800AF1B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AF1B4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF1B8: lwc1        $f17, -0x6E0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X6E0);
    // 0x800AF1BC: lwc1        $f16, -0x6DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6DC);
    // 0x800AF1C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AF1C4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800AF1C8: jal         0x800C3650
    // 0x800AF1CC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    func_800C3650(rdram, ctx);
        goto after_0;
    // 0x800AF1CC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x800AF1D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF1D4: swc1        $f0, 0x440($at)
    MEM_W(0X440, ctx->r1) = ctx->f0.u32l;
    // 0x800AF1D8: b           L_800AF1E0
    // 0x800AF1DC: nop

        goto L_800AF1E0;
    // 0x800AF1DC: nop

L_800AF1E0:
    // 0x800AF1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AF1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AF1E8: jr          $ra
    // 0x800AF1EC: nop

    return;
    // 0x800AF1EC: nop

;}
RECOMP_FUNC void func_800AF1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AF1F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800AF1F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800AF1FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800AF200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AF204: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF208: nop

    // 0x800AF20C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AF210: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800AF214: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF218: lwc1        $f4, 0x430($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X430);
    // 0x800AF21C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF220: nop

    // 0x800AF224: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x800AF228: nop

    // 0x800AF22C: bc1f        L_800AF318
    if (!c1cs) {
        // 0x800AF230: nop

            goto L_800AF318;
    }
    // 0x800AF230: nop

    // 0x800AF234: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF238: lwc1        $f6, 0x438($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X438);
    // 0x800AF23C: nop

    // 0x800AF240: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x800AF244: nop

    // 0x800AF248: bc1f        L_800AF318
    if (!c1cs) {
        // 0x800AF24C: nop

            goto L_800AF318;
    }
    // 0x800AF24C: nop

    // 0x800AF250: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AF258: nop

    // 0x800AF25C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800AF260: nop

    // 0x800AF264: bc1f        L_800AF274
    if (!c1cs) {
        // 0x800AF268: nop

            goto L_800AF274;
    }
    // 0x800AF268: nop

    // 0x800AF26C: b           L_800AF284
    // 0x800AF270: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
        goto L_800AF284;
    // 0x800AF270: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
L_800AF274:
    // 0x800AF274: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AF278: nop

    // 0x800AF27C: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800AF280: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
L_800AF284:
    // 0x800AF284: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF288: lwc1        $f8, 0x440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X440);
    // 0x800AF28C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800AF290: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AF294: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800AF298: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AF29C: nop

    // 0x800AF2A0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800AF2A4: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AF2A8: bc1f        L_800AF2B8
    if (!c1cs) {
        // 0x800AF2AC: swc1        $f18, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
            goto L_800AF2B8;
    }
    // 0x800AF2AC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800AF2B0: b           L_800AF2BC
    // 0x800AF2B4: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
        goto L_800AF2BC;
    // 0x800AF2B4: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_800AF2B8:
    // 0x800AF2B8: neg.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f16.fl = -ctx->f12.fl;
L_800AF2BC:
    // 0x800AF2BC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x800AF2C0: nop

    // 0x800AF2C4: bc1f        L_800AF318
    if (!c1cs) {
        // 0x800AF2C8: nop

            goto L_800AF318;
    }
    // 0x800AF2C8: nop

    // 0x800AF2CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AF2D0: nop

    // 0x800AF2D4: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x800AF2D8: nop

    // 0x800AF2DC: bc1f        L_800AF2EC
    if (!c1cs) {
        // 0x800AF2E0: nop

            goto L_800AF2EC;
    }
    // 0x800AF2E0: nop

    // 0x800AF2E4: b           L_800AF2F4
    // 0x800AF2E8: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
        goto L_800AF2F4;
    // 0x800AF2E8: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
L_800AF2EC:
    // 0x800AF2EC: neg.s       $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f10.fl = -ctx->f14.fl;
    // 0x800AF2F0: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
L_800AF2F4:
    // 0x800AF2F4: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AF2F8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800AF2FC: nop

    // 0x800AF300: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x800AF304: nop

    // 0x800AF308: bc1f        L_800AF318
    if (!c1cs) {
        // 0x800AF30C: nop

            goto L_800AF318;
    }
    // 0x800AF30C: nop

    // 0x800AF310: b           L_800AF328
    // 0x800AF314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800AF328;
    // 0x800AF314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AF318:
    // 0x800AF318: b           L_800AF328
    // 0x800AF31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AF328;
    // 0x800AF31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AF320: b           L_800AF328
    // 0x800AF324: nop

        goto L_800AF328;
    // 0x800AF324: nop

L_800AF328:
    // 0x800AF328: jr          $ra
    // 0x800AF32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AF32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800AF330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF330: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800AF334: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AF338: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800AF33C: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800AF340: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x800AF344: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800AF348: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800AF34C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800AF350: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800AF354: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AF358: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800AF35C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AF360: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800AF364: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AF368: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800AF36C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF370: lw          $t6, -0x4CC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CC4);
    // 0x800AF374: addiu       $t7, $zero, -0x14
    ctx->r15 = ADD32(0, -0X14);
    // 0x800AF378: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800AF37C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AF380: nop

    // 0x800AF384: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AF388: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x800AF38C: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x800AF390: nop

    // 0x800AF394: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800AF398: nop

    // 0x800AF39C: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    // 0x800AF3A0: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x800AF3A4: nop

    // 0x800AF3A8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800AF3AC: sw          $t2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r10;
    // 0x800AF3B0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800AF3B4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800AF3B8: lui         $t3, 0x106
    ctx->r11 = S32(0X106 << 16);
    // 0x800AF3BC: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x800AF3C0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800AF3C4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800AF3C8: lhu         $t5, -0x778($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X778);
    // 0x800AF3CC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF3D0: lw          $t6, -0x77C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77C);
    // 0x800AF3D4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800AF3D8: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x800AF3DC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800AF3E0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800AF3E4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800AF3E8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800AF3EC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800AF3F0: jal         0x800C1680
    // 0x800AF3F4: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800AF3F4: nop

    after_0:
    // 0x800AF3F8: jal         0x800C1850
    // 0x800AF3FC: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    MtxUtil_Identity(rdram, ctx);
        goto after_1;
    // 0x800AF3FC: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    after_1:
    // 0x800AF400: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800AF404: addiu       $t1, $sp, 0xBC
    ctx->r9 = ADD32(ctx->r29, 0XBC);
    // 0x800AF408: swc1        $f8, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f8.u32l;
    // 0x800AF40C: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800AF410: addiu       $t2, $sp, 0xBC
    ctx->r10 = ADD32(ctx->r29, 0XBC);
    // 0x800AF414: swc1        $f10, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f10.u32l;
    // 0x800AF418: lwc1        $f16, 0x110($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800AF41C: addiu       $t3, $sp, 0xBC
    ctx->r11 = ADD32(ctx->r29, 0XBC);
    // 0x800AF420: swc1        $f16, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f16.u32l;
    // 0x800AF424: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x800AF428: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800AF42C: lhu         $t5, 0xC($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XC);
    // 0x800AF430: nop

    // 0x800AF434: beq         $t5, $at, L_800AF6B0
    if (ctx->r13 == ctx->r1) {
        // 0x800AF438: nop

            goto L_800AF6B0;
    }
    // 0x800AF438: nop

L_800AF43C:
    // 0x800AF43C: jal         0x800C1AF4
    // 0x800AF440: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_2;
    // 0x800AF440: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    after_2:
    // 0x800AF444: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x800AF448: nop

    // 0x800AF44C: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x800AF450: lh          $t9, 0x4($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X4);
    // 0x800AF454: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800AF458: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800AF45C: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800AF460: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AF464: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AF468: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800AF46C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800AF470: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AF474: jal         0x800C2304
    // 0x800AF478: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_3;
    // 0x800AF478: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_3:
    // 0x800AF47C: lw          $t0, 0x104($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X104);
    // 0x800AF480: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AF484: addiu       $t1, $t0, 0xA
    ctx->r9 = ADD32(ctx->r8, 0XA);
    // 0x800AF488: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x800AF48C: lh          $t2, 0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XA);
    // 0x800AF490: nop

    // 0x800AF494: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800AF498: nop

    // 0x800AF49C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AF4A0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800AF4A4: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x800AF4A8: bc1t        L_800AF4BC
    if (c1cs) {
        // 0x800AF4AC: nop

            goto L_800AF4BC;
    }
    // 0x800AF4AC: nop

    // 0x800AF4B0: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AF4B4: jal         0x800C2780
    // 0x800AF4B8: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_4;
    // 0x800AF4B8: nop

    after_4:
L_800AF4BC:
    // 0x800AF4BC: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800AF4C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AF4C4: lh          $t4, -0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, -0X2);
    // 0x800AF4C8: nop

    // 0x800AF4CC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800AF4D0: nop

    // 0x800AF4D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AF4D8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800AF4DC: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x800AF4E0: bc1t        L_800AF4F4
    if (c1cs) {
        // 0x800AF4E4: nop

            goto L_800AF4F4;
    }
    // 0x800AF4E4: nop

    // 0x800AF4E8: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AF4EC: jal         0x800C25B8
    // 0x800AF4F0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_5;
    // 0x800AF4F0: nop

    after_5:
L_800AF4F4:
    // 0x800AF4F4: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800AF4F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AF4FC: lh          $t6, -0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, -0X4);
    // 0x800AF500: nop

    // 0x800AF504: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800AF508: nop

    // 0x800AF50C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AF510: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800AF514: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x800AF518: bc1t        L_800AF52C
    if (c1cs) {
        // 0x800AF51C: nop

            goto L_800AF52C;
    }
    // 0x800AF51C: nop

    // 0x800AF520: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AF524: jal         0x800C23E8
    // 0x800AF528: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_6;
    // 0x800AF528: nop

    after_6:
L_800AF52C:
    // 0x800AF52C: jal         0x800C2070
    // 0x800AF530: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    func_800C2070(rdram, ctx);
        goto after_7;
    // 0x800AF530: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    after_7:
    // 0x800AF534: addiu       $t8, $sp, 0x7C
    ctx->r24 = ADD32(ctx->r29, 0X7C);
    // 0x800AF538: lwc1        $f18, 0x30($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X30);
    // 0x800AF53C: nop

    // 0x800AF540: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x800AF544: addiu       $t7, $sp, 0x7C
    ctx->r15 = ADD32(ctx->r29, 0X7C);
    // 0x800AF548: lwc1        $f4, 0x34($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X34);
    // 0x800AF54C: nop

    // 0x800AF550: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800AF554: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800AF558: lwc1        $f6, 0x38($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X38);
    // 0x800AF55C: nop

    // 0x800AF560: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AF564: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800AF568: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF56C: lwc1        $f16, 0x430($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X430);
    // 0x800AF570: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800AF574: nop

    // 0x800AF578: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x800AF57C: nop

    // 0x800AF580: bc1f        L_800AF690
    if (!c1cs) {
        // 0x800AF584: nop

            goto L_800AF690;
    }
    // 0x800AF584: nop

    // 0x800AF588: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF58C: lwc1        $f18, 0x438($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X438);
    // 0x800AF590: nop

    // 0x800AF594: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x800AF598: nop

    // 0x800AF59C: bc1f        L_800AF690
    if (!c1cs) {
        // 0x800AF5A0: nop

            goto L_800AF690;
    }
    // 0x800AF5A0: nop

    // 0x800AF5A4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800AF5A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AF5AC: nop

    // 0x800AF5B0: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800AF5B4: nop

    // 0x800AF5B8: bc1f        L_800AF5C8
    if (!c1cs) {
        // 0x800AF5BC: nop

            goto L_800AF5C8;
    }
    // 0x800AF5BC: nop

    // 0x800AF5C0: b           L_800AF5D4
    // 0x800AF5C4: mov.s       $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    ctx->f24.fl = ctx->f4.fl;
        goto L_800AF5D4;
    // 0x800AF5C4: mov.s       $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    ctx->f24.fl = ctx->f4.fl;
L_800AF5C8:
    // 0x800AF5C8: lwc1        $f24, 0x70($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800AF5CC: nop

    // 0x800AF5D0: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl);
    ctx->f24.fl = -ctx->f24.fl;
L_800AF5D4:
    // 0x800AF5D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF5D8: lwc1        $f8, 0x440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X440);
    // 0x800AF5DC: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AF5E0: mul.s       $f16, $f24, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x800AF5E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AF5E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF5EC: lwc1        $f10, 0x450($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X450);
    // 0x800AF5F0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x800AF5F4: add.s       $f22, $f16, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f22.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800AF5F8: bc1f        L_800AF608
    if (!c1cs) {
        // 0x800AF5FC: swc1        $f22, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f22.u32l;
            goto L_800AF608;
    }
    // 0x800AF5FC: swc1        $f22, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f22.u32l;
    // 0x800AF600: b           L_800AF614
    // 0x800AF604: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
        goto L_800AF614;
    // 0x800AF604: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_800AF608:
    // 0x800AF608: lwc1        $f20, 0x78($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AF60C: nop

    // 0x800AF610: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f20.fl = -ctx->f20.fl;
L_800AF614:
    // 0x800AF614: c.le.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl <= ctx->f22.fl;
    // 0x800AF618: nop

    // 0x800AF61C: bc1f        L_800AF690
    if (!c1cs) {
        // 0x800AF620: nop

            goto L_800AF690;
    }
    // 0x800AF620: nop

    // 0x800AF624: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800AF628: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AF62C: nop

    // 0x800AF630: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800AF634: nop

    // 0x800AF638: bc1f        L_800AF648
    if (!c1cs) {
        // 0x800AF63C: nop

            goto L_800AF648;
    }
    // 0x800AF63C: nop

    // 0x800AF640: b           L_800AF654
    // 0x800AF644: mov.s       $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = ctx->f4.fl;
        goto L_800AF654;
    // 0x800AF644: mov.s       $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = ctx->f4.fl;
L_800AF648:
    // 0x800AF648: lwc1        $f26, 0x74($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800AF64C: nop

    // 0x800AF650: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl);
    ctx->f26.fl = -ctx->f26.fl;
L_800AF654:
    // 0x800AF654: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800AF658: nop

    // 0x800AF65C: c.le.s      $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f26.fl <= ctx->f16.fl;
    // 0x800AF660: nop

    // 0x800AF664: bc1f        L_800AF690
    if (!c1cs) {
        // 0x800AF668: nop

            goto L_800AF690;
    }
    // 0x800AF668: nop

    // 0x800AF66C: lw          $t0, 0x104($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X104);
    // 0x800AF670: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800AF674: lhu         $t2, 0xC($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0XC);
    // 0x800AF678: lw          $t1, 0x1C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1C8);
    // 0x800AF67C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AF680: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800AF684: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x800AF688: jal         0x800A42C8
    // 0x800AF68C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800A42C8(rdram, ctx);
        goto after_8;
    // 0x800AF68C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_8:
L_800AF690:
    // 0x800AF690: lw          $t5, 0x104($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X104);
    // 0x800AF694: nop

    // 0x800AF698: lhu         $s0, 0xE($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0XE);
    // 0x800AF69C: addiu       $t8, $t5, 0x10
    ctx->r24 = ADD32(ctx->r13, 0X10);
    // 0x800AF6A0: sltiu       $t6, $s0, 0x1
    ctx->r14 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x800AF6A4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800AF6A8: bne         $s0, $zero, L_800AF43C
    if (ctx->r16 != 0) {
        // 0x800AF6AC: sw          $t8, 0x104($sp)
        MEM_W(0X104, ctx->r29) = ctx->r24;
            goto L_800AF43C;
    }
    // 0x800AF6AC: sw          $t8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r24;
L_800AF6B0:
    // 0x800AF6B0: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x800AF6B4: nop

    // 0x800AF6B8: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800AF6BC: sw          $t9, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r25;
    // 0x800AF6C0: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x800AF6C4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800AF6C8: lui         $t0, 0xBD00
    ctx->r8 = S32(0XBD00 << 16);
    // 0x800AF6CC: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800AF6D0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800AF6D4: nop

    // 0x800AF6D8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AF6DC: jal         0x800C1A28
    // 0x800AF6E0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_9;
    // 0x800AF6E0: nop

    after_9:
    // 0x800AF6E4: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x800AF6E8: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x800AF6EC: nop

    // 0x800AF6F0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800AF6F4: b           L_800AF6FC
    // 0x800AF6F8: nop

        goto L_800AF6FC;
    // 0x800AF6F8: nop

L_800AF6FC:
    // 0x800AF6FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF700: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800AF704: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AF708: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800AF70C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AF710: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800AF714: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AF718: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800AF71C: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AF720: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800AF724: jr          $ra
    // 0x800AF728: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800AF728: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_800AF72C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF72C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AF730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AF734: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800AF738: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF73C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF740: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF744: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF748: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800AF74C: jal         0x800BD1FC
    // 0x800AF750: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800AF750: nop

    after_0:
    // 0x800AF754: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF758: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF75C: addiu       $t6, $t6, 0x4A8
    ctx->r14 = ADD32(ctx->r14, 0X4A8);
    // 0x800AF760: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800AF764: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF768: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800AF76C: jal         0x800BD218
    // 0x800AF770: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800AF770: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800AF774: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AF778: nop

    // 0x800AF77C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800AF780: nop

    // 0x800AF784: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800AF788: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800AF78C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF790: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF794: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF798: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF79C: jal         0x800BD1FC
    // 0x800AF7A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800AF7A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_2:
    // 0x800AF7A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF7A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF7AC: nop

    // 0x800AF7B0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800AF7B4: jal         0x800BC6EC
    // 0x800AF7B8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800AF7B8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x800AF7BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800AF7C0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800AF7C4: nop

    // 0x800AF7C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800AF7CC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800AF7D0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF7D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF7D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800AF7DC: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x800AF7E0: jal         0x800BD218
    // 0x800AF7E4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x800AF7E4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_4:
    // 0x800AF7E8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF7EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF7F0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800AF7F4: sh          $t3, 0x1D8($at)
    MEM_H(0X1D8, ctx->r1) = ctx->r11;
    // 0x800AF7F8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF7FC: lhu         $a0, 0x1D8($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1D8);
    // 0x800AF800: nop

    // 0x800AF804: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800AF808: jal         0x800BC6EC
    // 0x800AF80C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x800AF80C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_5:
    // 0x800AF810: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF814: sw          $v0, 0x1D4($at)
    MEM_W(0X1D4, ctx->r1) = ctx->r2;
    // 0x800AF818: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800AF81C: lw          $t5, 0x1D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1D4);
    // 0x800AF820: nop

    // 0x800AF824: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800AF828: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF82C: lhu         $t6, 0x1D8($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1D8);
    // 0x800AF830: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800AF834: blez        $t6, L_800AF908
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AF838: nop

            goto L_800AF908;
    }
    // 0x800AF838: nop

L_800AF83C:
    // 0x800AF83C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800AF840: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF844: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF848: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF84C: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF850: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x800AF854: jal         0x800BD1FC
    // 0x800AF858: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x800AF858: nop

    after_6:
    // 0x800AF85C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF860: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF864: jal         0x800BED70
    // 0x800AF868: nop

    Spi_GetHeader(rdram, ctx);
        goto after_7;
    // 0x800AF868: nop

    after_7:
    // 0x800AF86C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800AF870: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800AF874: addiu       $t8, $t8, 0x4A8
    ctx->r24 = ADD32(ctx->r24, 0X4A8);
    // 0x800AF878: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800AF87C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF880: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800AF884: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800AF888: jal         0x800BF0B4
    // 0x800AF88C: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_8;
    // 0x800AF88C: nop

    after_8:
    // 0x800AF890: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800AF894: lw          $t9, 0x494($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X494);
    // 0x800AF898: nop

    // 0x800AF89C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800AF8A0: jal         0x800BC6EC
    // 0x800AF8A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_9;
    // 0x800AF8A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_9:
    // 0x800AF8A8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800AF8AC: nop

    // 0x800AF8B0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800AF8B4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800AF8B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AF8BC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF8C0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800AF8C4: jal         0x800BD218
    // 0x800AF8C8: nop

    SysMem_DmaCopy(rdram, ctx);
        goto after_10;
    // 0x800AF8C8: nop

    after_10:
    // 0x800AF8CC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800AF8D0: nop

    // 0x800AF8D4: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800AF8D8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800AF8DC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800AF8E0: nop

    // 0x800AF8E4: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800AF8E8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800AF8EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF8F0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800AF8F4: lhu         $t8, 0x1D8($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1D8);
    // 0x800AF8F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800AF8FC: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AF900: bne         $at, $zero, L_800AF83C
    if (ctx->r1 != 0) {
        // 0x800AF904: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_800AF83C;
    }
    // 0x800AF904: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_800AF908:
    // 0x800AF908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800AF90C: jal         0x800BC980
    // 0x800AF910: nop

    SysMem_Free(rdram, ctx);
        goto after_11;
    // 0x800AF910: nop

    after_11:
    // 0x800AF914: b           L_800AF91C
    // 0x800AF918: nop

        goto L_800AF91C;
    // 0x800AF918: nop

L_800AF91C:
    // 0x800AF91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AF920: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AF924: jr          $ra
    // 0x800AF928: nop

    return;
    // 0x800AF928: nop

;}
RECOMP_FUNC void func_800AF92C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF92C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AF934: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800AF938: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF93C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF940: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF944: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF948: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF94C: jal         0x800BD1FC
    // 0x800AF950: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800AF950: nop

    after_0:
    // 0x800AF954: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AF958: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800AF95C: addiu       $t6, $t6, 0x4A8
    ctx->r14 = ADD32(ctx->r14, 0X4A8);
    // 0x800AF960: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800AF964: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800AF968: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF96C: jal         0x800BD218
    // 0x800AF970: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800AF970: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800AF974: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF978: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AF97C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800AF980: nop

    // 0x800AF984: sh          $t8, 0x1D0($at)
    MEM_H(0X1D0, ctx->r1) = ctx->r24;
    // 0x800AF988: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF98C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF990: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AF994: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AF998: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AF99C: jal         0x800BD1FC
    // 0x800AF9A0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800AF9A0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_2:
    // 0x800AF9A4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AF9A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF9AC: lhu         $a0, 0x1D0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1D0);
    // 0x800AF9B0: nop

    // 0x800AF9B4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800AF9B8: jal         0x800BC6EC
    // 0x800AF9BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800AF9BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x800AF9C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800AF9C4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF9C8: nop

    // 0x800AF9CC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800AF9D0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800AF9D4: lhu         $a2, 0x1D0($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X1D0);
    // 0x800AF9D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800AF9DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF9E0: sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6 << 1);
    // 0x800AF9E4: jal         0x800BD218
    // 0x800AF9E8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x800AF9E8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_4:
    // 0x800AF9EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AF9F0: lhu         $a0, 0x1D0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1D0);
    // 0x800AF9F4: nop

    // 0x800AF9F8: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800AF9FC: jal         0x800BC6EC
    // 0x800AFA00: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x800AFA00: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_5:
    // 0x800AFA04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AFA08: sw          $v0, 0x1C8($at)
    MEM_W(0X1C8, ctx->r1) = ctx->r2;
    // 0x800AFA0C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800AFA10: lw          $t3, 0x1C8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1C8);
    // 0x800AFA14: nop

    // 0x800AFA18: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800AFA1C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800AFA20: lhu         $t4, 0x1D0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1D0);
    // 0x800AFA24: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800AFA28: blez        $t4, L_800AFA8C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800AFA2C: nop

            goto L_800AFA8C;
    }
    // 0x800AFA2C: nop

L_800AFA30:
    // 0x800AFA30: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800AFA34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AFA38: lhu         $a0, 0x0($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X0);
    // 0x800AFA3C: jal         0x800AFB70
    // 0x800AFA40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_6;
    // 0x800AFA40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x800AFA44: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AFA48: nop

    // 0x800AFA4C: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800AFA50: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AFA54: nop

    // 0x800AFA58: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800AFA5C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800AFA60: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800AFA64: nop

    // 0x800AFA68: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x800AFA6C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800AFA70: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800AFA74: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800AFA78: lhu         $t3, 0x1D0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1D0);
    // 0x800AFA7C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800AFA80: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AFA84: bne         $at, $zero, L_800AFA30
    if (ctx->r1 != 0) {
        // 0x800AFA88: sw          $t2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r10;
            goto L_800AFA30;
    }
    // 0x800AFA88: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_800AFA8C:
    // 0x800AFA8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AFA90: jal         0x800BC980
    // 0x800AFA94: nop

    SysMem_Free(rdram, ctx);
        goto after_7;
    // 0x800AFA94: nop

    after_7:
    // 0x800AFA98: b           L_800AFAA0
    // 0x800AFA9C: nop

        goto L_800AFAA0;
    // 0x800AFA9C: nop

L_800AFAA0:
    // 0x800AFAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AFAA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800AFAA8: jr          $ra
    // 0x800AFAAC: nop

    return;
    // 0x800AFAAC: nop

;}
RECOMP_FUNC void func_800AFAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFAB0: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x800AFAB4: sra         $a2, $a2, 24
    ctx->r6 = S32(SIGNED(ctx->r6) >> 24);
    // 0x800AFAB8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AFABC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800AFAC0: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x800AFAC4: lb          $t7, 0xC($t6)
    ctx->r15 = MEM_B(ctx->r14, 0XC);
    // 0x800AFAC8: nop

    // 0x800AFACC: sb          $t7, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r15;
    // 0x800AFAD0: lhu         $t8, 0x6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6);
    // 0x800AFAD4: nop

    // 0x800AFAD8: beq         $t8, $zero, L_800AFAEC
    if (ctx->r24 == 0) {
        // 0x800AFADC: nop

            goto L_800AFAEC;
    }
    // 0x800AFADC: nop

    // 0x800AFAE0: sb          $a2, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r6;
    // 0x800AFAE4: b           L_800AFB0C
    // 0x800AFAE8: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
        goto L_800AFB0C;
    // 0x800AFAE8: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
L_800AFAEC:
    // 0x800AFAEC: lb          $t9, 0x6($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X6);
    // 0x800AFAF0: nop

    // 0x800AFAF4: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x800AFAF8: bgez        $t0, L_800AFB08
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AFAFC: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_800AFB08;
    }
    // 0x800AFAFC: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800AFB00: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x800AFB04: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800AFB08:
    // 0x800AFB08: sb          $t1, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r9;
L_800AFB0C:
    // 0x800AFB0C: lb          $t2, 0x6($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X6);
    // 0x800AFB10: addu        $t3, $a0, $a1
    ctx->r11 = ADD32(ctx->r4, ctx->r5);
    // 0x800AFB14: sb          $t2, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r10;
    // 0x800AFB18: b           L_800AFB20
    // 0x800AFB1C: nop

        goto L_800AFB20;
    // 0x800AFB1C: nop

L_800AFB20:
    // 0x800AFB20: jr          $ra
    // 0x800AFB24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AFB24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800AFB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFB28: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AFB2C: sh          $zero, -0x778($at)
    MEM_H(-0X778, ctx->r1) = 0;
    // 0x800AFB30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AFB34: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800AFB38: lh          $t7, -0x490($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X490);
    // 0x800AFB3C: lhu         $t6, 0x24FC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X24FC);
    // 0x800AFB40: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800AFB44: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFB48: lw          $t0, -0x784($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X784);
    // 0x800AFB4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AFB50: mflo        $t8
    ctx->r24 = lo;
    // 0x800AFB54: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800AFB58: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800AFB5C: sw          $t1, -0x77C($at)
    MEM_W(-0X77C, ctx->r1) = ctx->r9;
    // 0x800AFB60: jr          $ra
    // 0x800AFB64: nop

    return;
    // 0x800AFB64: nop

    // 0x800AFB68: jr          $ra
    // 0x800AFB6C: nop

    return;
    // 0x800AFB6C: nop

;}
RECOMP_FUNC void func_800AFB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFB70: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x800AFB74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AFB78: sw          $a0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r4;
    // 0x800AFB7C: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x800AFB80: sw          $a2, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r6;
    // 0x800AFB84: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800AFB88: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800AFB8C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800AFB90: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AFB94: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800AFB98: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AFB9C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800AFBA0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AFBA4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800AFBA8: lhu         $t6, 0x162($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X162);
    // 0x800AFBAC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AFBB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFBB4: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800AFBB8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800AFBBC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800AFBC0: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800AFBC4: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800AFBC8: lw          $a2, 0x4110($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4110);
    // 0x800AFBCC: jal         0x800BD1FC
    // 0x800AFBD0: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800AFBD0: nop

    after_0:
    // 0x800AFBD4: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x800AFBD8: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x800AFBDC: jal         0x800BED70
    // 0x800AFBE0: nop

    Spi_GetHeader(rdram, ctx);
        goto after_1;
    // 0x800AFBE0: nop

    after_1:
    // 0x800AFBE4: sw          $v0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r2;
    // 0x800AFBE8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800AFBEC: addiu       $t8, $t8, 0x4A8
    ctx->r24 = ADD32(ctx->r24, 0X4A8);
    // 0x800AFBF0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800AFBF4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800AFBF8: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x800AFBFC: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x800AFC00: lw          $a1, 0x15C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X15C);
    // 0x800AFC04: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x800AFC08: jal         0x800BF0B4
    // 0x800AFC0C: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_2;
    // 0x800AFC0C: nop

    after_2:
    // 0x800AFC10: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800AFC14: lw          $t0, 0x494($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X494);
    // 0x800AFC18: nop

    // 0x800AFC1C: sw          $t0, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r8;
    // 0x800AFC20: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800AFC24: lw          $t2, 0x154($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X154);
    // 0x800AFC28: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800AFC2C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800AFC30: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x800AFC34: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x800AFC38: nop

    // 0x800AFC3C: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x800AFC40: beq         $t5, $zero, L_800AFC60
    if (ctx->r13 == 0) {
        // 0x800AFC44: sw          $t5, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r13;
            goto L_800AFC60;
    }
    // 0x800AFC44: sw          $t5, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r13;
    // 0x800AFC48: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800AFC4C: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x800AFC50: nop

    // 0x800AFC54: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800AFC58: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800AFC5C: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
L_800AFC60:
    // 0x800AFC60: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800AFC64: nop

    // 0x800AFC68: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x800AFC6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800AFC70: sw          $t1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r9;
    // 0x800AFC74: sw          $zero, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = 0;
    // 0x800AFC78: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800AFC7C: nop

    // 0x800AFC80: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800AFC84: sw          $t3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r11;
    // 0x800AFC88: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x800AFC8C: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x800AFC90: lui         $t4, 0xBB00
    ctx->r12 = S32(0XBB00 << 16);
    // 0x800AFC94: ori         $t4, $t4, 0x1
    ctx->r12 = ctx->r12 | 0X1;
    // 0x800AFC98: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800AFC9C: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800AFCA0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800AFCA4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800AFCA8: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x800AFCAC: nop

    // 0x800AFCB0: blez        $t8, L_800B085C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AFCB4: nop

            goto L_800B085C;
    }
    // 0x800AFCB4: nop

L_800AFCB8:
    // 0x800AFCB8: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x800AFCBC: nop

    // 0x800AFCC0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800AFCC4: sw          $t0, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r8;
    // 0x800AFCC8: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x800AFCCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AFCD0: lbu         $s0, 0x0($t1)
    ctx->r16 = MEM_BU(ctx->r9, 0X0);
    // 0x800AFCD4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800AFCD8: beq         $s0, $at, L_800AFD00
    if (ctx->r16 == ctx->r1) {
        // 0x800AFCDC: sw          $t2, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r10;
            goto L_800AFD00;
    }
    // 0x800AFCDC: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800AFCE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AFCE4: beq         $s0, $at, L_800B0270
    if (ctx->r16 == ctx->r1) {
        // 0x800AFCE8: nop

            goto L_800B0270;
    }
    // 0x800AFCE8: nop

    // 0x800AFCEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AFCF0: beq         $s0, $at, L_800B03E0
    if (ctx->r16 == ctx->r1) {
        // 0x800AFCF4: nop

            goto L_800B03E0;
    }
    // 0x800AFCF4: nop

    // 0x800AFCF8: b           L_800B084C
    // 0x800AFCFC: nop

        goto L_800B084C;
    // 0x800AFCFC: nop

L_800AFD00:
    // 0x800AFD00: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800AFD04: nop

    // 0x800AFD08: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x800AFD0C: nop

    // 0x800AFD10: sh          $t4, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r12;
    // 0x800AFD14: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x800AFD18: nop

    // 0x800AFD1C: lbu         $t6, 0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2);
    // 0x800AFD20: nop

    // 0x800AFD24: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x800AFD28: sh          $t7, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r15;
    // 0x800AFD2C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800AFD30: nop

    // 0x800AFD34: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x800AFD38: nop

    // 0x800AFD3C: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x800AFD40: sh          $t0, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r8;
    // 0x800AFD44: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800AFD48: nop

    // 0x800AFD4C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800AFD50: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800AFD54: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x800AFD58: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800AFD5C: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
    // 0x800AFD60: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800AFD64: lh          $t5, 0x14A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X14A);
    // 0x800AFD68: lh          $t9, 0x148($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X148);
    // 0x800AFD6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AFD70: lh          $t4, 0x146($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X146);
    // 0x800AFD74: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800AFD78: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800AFD7C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800AFD80: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800AFD84: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800AFD88: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFD8C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800AFD90: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800AFD94: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800AFD98: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800AFD9C: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800AFDA0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800AFDA4: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800AFDA8: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800AFDAC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800AFDB0: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800AFDB4: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800AFDB8: lw          $t0, 0x15C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X15C);
    // 0x800AFDBC: nop

    // 0x800AFDC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800AFDC4: sw          $t1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r9;
    // 0x800AFDC8: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800AFDCC: nop

    // 0x800AFDD0: addiu       $t2, $t8, 0x3
    ctx->r10 = ADD32(ctx->r24, 0X3);
    // 0x800AFDD4: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800AFDD8: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800AFDDC: nop

    // 0x800AFDE0: addiu       $t5, $t4, -0x3
    ctx->r13 = ADD32(ctx->r12, -0X3);
    // 0x800AFDE4: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x800AFDE8: lh          $t3, 0x166($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X166);
    // 0x800AFDEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AFDF0: bne         $t3, $at, L_800B0268
    if (ctx->r11 != ctx->r1) {
        // 0x800AFDF4: nop

            goto L_800B0268;
    }
    // 0x800AFDF4: nop

    // 0x800AFDF8: lh          $t6, 0x14A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X14A);
    // 0x800AFDFC: nop

    // 0x800AFE00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFE04: addu        $t9, $sp, $t7
    ctx->r25 = ADD32(ctx->r29, ctx->r15);
    // 0x800AFE08: lw          $t9, 0x9C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X9C);
    // 0x800AFE0C: nop

    // 0x800AFE10: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x800AFE14: lh          $t0, 0x148($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X148);
    // 0x800AFE18: nop

    // 0x800AFE1C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AFE20: addu        $t8, $sp, $t1
    ctx->r24 = ADD32(ctx->r29, ctx->r9);
    // 0x800AFE24: lw          $t8, 0x9C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X9C);
    // 0x800AFE28: nop

    // 0x800AFE2C: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x800AFE30: lh          $t2, 0x146($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X146);
    // 0x800AFE34: nop

    // 0x800AFE38: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800AFE3C: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800AFE40: lw          $t5, 0x9C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X9C);
    // 0x800AFE44: nop

    // 0x800AFE48: sw          $t5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r13;
    // 0x800AFE4C: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x800AFE50: nop

    // 0x800AFE54: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x800AFE58: nop

    // 0x800AFE5C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AFE60: nop

    // 0x800AFE64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AFE68: swc1        $f6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f6.u32l;
    // 0x800AFE6C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x800AFE70: nop

    // 0x800AFE74: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x800AFE78: nop

    // 0x800AFE7C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AFE80: nop

    // 0x800AFE84: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AFE88: swc1        $f10, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f10.u32l;
    // 0x800AFE8C: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x800AFE90: nop

    // 0x800AFE94: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x800AFE98: nop

    // 0x800AFE9C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800AFEA0: nop

    // 0x800AFEA4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AFEA8: swc1        $f18, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f18.u32l;
    // 0x800AFEAC: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x800AFEB0: nop

    // 0x800AFEB4: lh          $t2, 0x0($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X0);
    // 0x800AFEB8: nop

    // 0x800AFEBC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800AFEC0: nop

    // 0x800AFEC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AFEC8: swc1        $f6, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f6.u32l;
    // 0x800AFECC: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x800AFED0: nop

    // 0x800AFED4: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x800AFED8: nop

    // 0x800AFEDC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800AFEE0: nop

    // 0x800AFEE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AFEE8: swc1        $f10, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f10.u32l;
    // 0x800AFEEC: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x800AFEF0: nop

    // 0x800AFEF4: lh          $t6, 0x4($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X4);
    // 0x800AFEF8: nop

    // 0x800AFEFC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800AFF00: nop

    // 0x800AFF04: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AFF08: swc1        $f18, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f18.u32l;
    // 0x800AFF0C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x800AFF10: nop

    // 0x800AFF14: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x800AFF18: nop

    // 0x800AFF1C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800AFF20: nop

    // 0x800AFF24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AFF28: swc1        $f6, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f6.u32l;
    // 0x800AFF2C: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800AFF30: nop

    // 0x800AFF34: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x800AFF38: nop

    // 0x800AFF3C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800AFF40: nop

    // 0x800AFF44: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AFF48: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
    // 0x800AFF4C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800AFF50: nop

    // 0x800AFF54: lh          $t2, 0x4($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X4);
    // 0x800AFF58: nop

    // 0x800AFF5C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800AFF60: nop

    // 0x800AFF64: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AFF68: swc1        $f18, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f18.u32l;
    // 0x800AFF6C: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800AFF70: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800AFF74: lwc1        $f8, 0x128($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X128);
    // 0x800AFF78: lwc1        $f16, 0x130($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X130);
    // 0x800AFF7C: lwc1        $f18, 0x11C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AFF80: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x800AFF84: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AFF88: sub.s       $f20, $f6, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f20.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800AFF8C: swc1        $f24, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f24.u32l;
    // 0x800AFF90: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800AFF94: swc1        $f20, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f20.u32l;
    // 0x800AFF98: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AFF9C: swc1        $f4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f4.u32l;
    // 0x800AFFA0: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AFFA4: swc1        $f22, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f22.u32l;
    // 0x800AFFA8: mul.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl);
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800AFFAC: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800AFFB0: swc1        $f16, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f16.u32l;
    // 0x800AFFB4: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800AFFB8: lwc1        $f4, 0x138($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800AFFBC: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800AFFC0: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800AFFC4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800AFFC8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AFFCC: sub.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f20.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800AFFD0: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800AFFD4: swc1        $f20, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f20.u32l;
    // 0x800AFFD8: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800AFFDC: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x800AFFE0: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800AFFE4: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    // 0x800AFFE8: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800AFFEC: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800AFFF0: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800AFFF4: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800AFFF8: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800AFFFC: nop

    // 0x800B0000: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800B0004: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B0008: swc1        $f6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f6.u32l;
    // 0x800B000C: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B0010: lwc1        $f16, 0x110($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B0014: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B0018: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B001C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800B0020: nop

    // 0x800B0024: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B0028: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B002C: jal         0x800C42A0
    // 0x800B0030: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B0030: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_3:
    // 0x800B0034: swc1        $f0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f0.u32l;
    // 0x800B0038: lwc1        $f16, 0x108($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B003C: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800B0040: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B0044: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x800B0048: c.eq.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d == ctx->f18.d;
    // 0x800B004C: nop

    // 0x800B0050: bc1t        L_800B0268
    if (c1cs) {
        // 0x800B0054: nop

            goto L_800B0268;
    }
    // 0x800B0054: nop

    // 0x800B0058: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B005C: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B0060: lwc1        $f7, -0x6D8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X6D8);
    // 0x800B0064: lwc1        $f6, -0x6D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6D4);
    // 0x800B0068: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800B006C: nop

    // 0x800B0070: div.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x800B0074: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x800B0078: swc1        $f8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f8.u32l;
    // 0x800B007C: lwc1        $f18, 0x114($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B0080: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B0084: nop

    // 0x800B0088: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B008C: swc1        $f6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f6.u32l;
    // 0x800B0090: lwc1        $f10, 0x110($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B0094: lwc1        $f16, 0x108($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B0098: nop

    // 0x800B009C: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B00A0: swc1        $f8, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f8.u32l;
    // 0x800B00A4: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B00A8: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800B00AC: nop

    // 0x800B00B0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B00B4: swc1        $f6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f6.u32l;
    // 0x800B00B8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B00BC: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B00C0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B00C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B00C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B00CC: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x800B00D0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B00D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B00D8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800B00DC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B00E0: jal         0x800AFAB0
    // 0x800B00E4: nop

    func_800AFAB0(rdram, ctx);
        goto after_4;
    // 0x800B00E4: nop

    after_4:
    // 0x800B00E8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B00EC: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B00F0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B00F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B00F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B00FC: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800B0100: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B0104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B0108: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800B010C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B0110: jal         0x800AFAB0
    // 0x800B0114: nop

    func_800AFAB0(rdram, ctx);
        goto after_5;
    // 0x800B0114: nop

    after_5:
    // 0x800B0118: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B011C: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B0120: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B0124: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0128: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B012C: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800B0130: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B0134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B0138: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B013C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B0140: jal         0x800AFAB0
    // 0x800B0144: nop

    func_800AFAB0(rdram, ctx);
        goto after_6;
    // 0x800B0144: nop

    after_6:
    // 0x800B0148: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B014C: lwc1        $f10, 0x110($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B0150: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B0154: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0158: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B015C: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x800B0160: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B0164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B0168: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800B016C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B0170: jal         0x800AFAB0
    // 0x800B0174: nop

    func_800AFAB0(rdram, ctx);
        goto after_7;
    // 0x800B0174: nop

    after_7:
    // 0x800B0178: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B017C: lwc1        $f8, 0x110($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B0180: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B0184: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0188: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B018C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800B0190: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B0194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B0198: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800B019C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B01A0: jal         0x800AFAB0
    // 0x800B01A4: nop

    func_800AFAB0(rdram, ctx);
        goto after_8;
    // 0x800B01A4: nop

    after_8:
    // 0x800B01A8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B01AC: lwc1        $f4, 0x110($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800B01B0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B01B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B01B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B01BC: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800B01C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B01C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B01C8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B01CC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B01D0: jal         0x800AFAB0
    // 0x800B01D4: nop

    func_800AFAB0(rdram, ctx);
        goto after_9;
    // 0x800B01D4: nop

    after_9:
    // 0x800B01D8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800B01DC: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B01E0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800B01E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B01E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B01EC: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x800B01F0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B01F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B01F8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800B01FC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800B0200: jal         0x800AFAB0
    // 0x800B0204: nop

    func_800AFAB0(rdram, ctx);
        goto after_10;
    // 0x800B0204: nop

    after_10:
    // 0x800B0208: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B020C: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B0210: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B0214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B021C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800B0220: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B0224: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B0228: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800B022C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B0230: jal         0x800AFAB0
    // 0x800B0234: nop

    func_800AFAB0(rdram, ctx);
        goto after_11;
    // 0x800B0234: nop

    after_11:
    // 0x800B0238: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B023C: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800B0240: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B0244: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0248: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B024C: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800B0250: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B0254: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B0258: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B025C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B0260: jal         0x800AFAB0
    // 0x800B0264: nop

    func_800AFAB0(rdram, ctx);
        goto after_12;
    // 0x800B0264: nop

    after_12:
L_800B0268:
    // 0x800B0268: b           L_800B084C
    // 0x800B026C: nop

        goto L_800B084C;
    // 0x800B026C: nop

L_800B0270:
    // 0x800B0270: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x800B0274: nop

    // 0x800B0278: bne         $t2, $zero, L_800B02A0
    if (ctx->r10 != 0) {
        // 0x800B027C: nop

            goto L_800B02A0;
    }
    // 0x800B027C: nop

    // 0x800B0280: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x800B0284: lh          $a1, 0x16A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X16A);
    // 0x800B0288: lbu         $at, 0x1($t4)
    ctx->r1 = MEM_BU(ctx->r12, 0X1);
    // 0x800B028C: lbu         $a0, 0x2($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X2);
    // 0x800B0290: sll         $at, $at, 8
    ctx->r1 = S32(ctx->r1 << 8);
    // 0x800B0294: jal         0x800B0A3C
    // 0x800B0298: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_800B0A3C(rdram, ctx);
        goto after_13;
    // 0x800B0298: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_13:
    // 0x800B029C: sw          $v0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r2;
L_800B02A0:
    // 0x800B02A0: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x800B02A4: nop

    // 0x800B02A8: lbu         $at, 0x3($t5)
    ctx->r1 = MEM_BU(ctx->r13, 0X3);
    // 0x800B02AC: lbu         $t3, 0x4($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X4);
    // 0x800B02B0: sll         $at, $at, 8
    ctx->r1 = S32(ctx->r1 << 8);
    // 0x800B02B4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
    // 0x800B02B8: sh          $t3, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r11;
    // 0x800B02BC: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800B02C0: nop

    // 0x800B02C4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800B02C8: nop

    // 0x800B02CC: sra         $t9, $t7, 4
    ctx->r25 = S32(SIGNED(ctx->r15) >> 4);
    // 0x800B02D0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B02D4: sh          $t0, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r8;
    // 0x800B02D8: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x800B02DC: nop

    // 0x800B02E0: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x800B02E4: nop

    // 0x800B02E8: andi        $t2, $t8, 0xF
    ctx->r10 = ctx->r24 & 0XF;
    // 0x800B02EC: sh          $t2, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r10;
    // 0x800B02F0: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800B02F4: nop

    // 0x800B02F8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800B02FC: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    // 0x800B0300: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800B0304: lh          $t3, 0x148($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X148);
    // 0x800B0308: lh          $t9, 0x146($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X146);
    // 0x800B030C: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x800B0310: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800B0314: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x800B0318: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800B031C: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x800B0320: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B0324: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800B0328: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800B032C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800B0330: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x800B0334: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800B0338: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800B033C: lh          $t9, 0x14A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X14A);
    // 0x800B0340: lw          $t1, 0xE8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE8);
    // 0x800B0344: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800B0348: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800B034C: addu        $t8, $t0, $t1
    ctx->r24 = ADD32(ctx->r8, ctx->r9);
    // 0x800B0350: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x800B0354: lh          $t4, 0x148($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X148);
    // 0x800B0358: sw          $zero, 0x158($sp)
    MEM_W(0X158, ctx->r29) = 0;
    // 0x800B035C: blez        $t4, L_800B03A8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B0360: nop

            goto L_800B03A8;
    }
    // 0x800B0360: nop

L_800B0364:
    // 0x800B0364: lw          $t5, 0x158($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X158);
    // 0x800B0368: lh          $t2, 0x14A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X14A);
    // 0x800B036C: lh          $t1, 0x146($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X146);
    // 0x800B0370: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
    // 0x800B0374: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800B0378: addu        $t8, $t1, $t5
    ctx->r24 = ADD32(ctx->r9, ctx->r13);
    // 0x800B037C: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x800B0380: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800B0384: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x800B0388: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B038C: sw          $t0, 0x9C($t4)
    MEM_W(0X9C, ctx->r12) = ctx->r8;
    // 0x800B0390: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800B0394: lh          $t7, 0x148($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X148);
    // 0x800B0398: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800B039C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B03A0: bne         $at, $zero, L_800B0364
    if (ctx->r1 != 0) {
        // 0x800B03A4: sw          $t6, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r14;
            goto L_800B0364;
    }
    // 0x800B03A4: sw          $t6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r14;
L_800B03A8:
    // 0x800B03A8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800B03AC: nop

    // 0x800B03B0: addiu       $t1, $t9, 0x5
    ctx->r9 = ADD32(ctx->r25, 0X5);
    // 0x800B03B4: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800B03B8: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x800B03BC: nop

    // 0x800B03C0: addiu       $t8, $t5, -0x5
    ctx->r24 = ADD32(ctx->r13, -0X5);
    // 0x800B03C4: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
    // 0x800B03C8: lw          $t0, 0x15C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X15C);
    // 0x800B03CC: nop

    // 0x800B03D0: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x800B03D4: sw          $t3, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r11;
    // 0x800B03D8: b           L_800B084C
    // 0x800B03DC: nop

        goto L_800B084C;
    // 0x800B03DC: nop

L_800B03E0:
    // 0x800B03E0: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x800B03E4: nop

    // 0x800B03E8: lbu         $at, 0x1($t4)
    ctx->r1 = MEM_BU(ctx->r12, 0X1);
    // 0x800B03EC: lbu         $t2, 0x2($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X2);
    // 0x800B03F0: sll         $at, $at, 8
    ctx->r1 = S32(ctx->r1 << 8);
    // 0x800B03F4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
    // 0x800B03F8: sh          $t2, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r10;
    // 0x800B03FC: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800B0400: nop

    // 0x800B0404: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x800B0408: nop

    // 0x800B040C: sh          $t7, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r15;
    // 0x800B0410: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800B0414: nop

    // 0x800B0418: lbu         $t1, 0x4($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X4);
    // 0x800B041C: nop

    // 0x800B0420: sh          $t1, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r9;
    // 0x800B0424: lh          $t5, 0x148($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X148);
    // 0x800B0428: nop

    // 0x800B042C: andi        $t8, $t5, 0x80
    ctx->r24 = ctx->r13 & 0X80;
    // 0x800B0430: beq         $t8, $zero, L_800B0444
    if (ctx->r24 == 0) {
        // 0x800B0434: nop

            goto L_800B0444;
    }
    // 0x800B0434: nop

    // 0x800B0438: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800B043C: b           L_800B0448
    // 0x800B0440: sw          $t0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r8;
        goto L_800B0448;
    // 0x800B0440: sw          $t0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r8;
L_800B0444:
    // 0x800B0444: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
L_800B0448:
    // 0x800B0448: lh          $t3, 0x148($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X148);
    // 0x800B044C: nop

    // 0x800B0450: andi        $t4, $t3, 0x7F
    ctx->r12 = ctx->r11 & 0X7F;
    // 0x800B0454: sh          $t4, 0x148($sp)
    MEM_H(0X148, ctx->r29) = ctx->r12;
    // 0x800B0458: lh          $t2, 0x146($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X146);
    // 0x800B045C: nop

    // 0x800B0460: andi        $t6, $t2, 0x80
    ctx->r14 = ctx->r10 & 0X80;
    // 0x800B0464: beq         $t6, $zero, L_800B0478
    if (ctx->r14 == 0) {
        // 0x800B0468: nop

            goto L_800B0478;
    }
    // 0x800B0468: nop

    // 0x800B046C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800B0470: b           L_800B047C
    // 0x800B0474: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
        goto L_800B047C;
    // 0x800B0474: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
L_800B0478:
    // 0x800B0478: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800B047C:
    // 0x800B047C: lh          $t9, 0x146($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X146);
    // 0x800B0480: nop

    // 0x800B0484: andi        $t1, $t9, 0x7F
    ctx->r9 = ctx->r25 & 0X7F;
    // 0x800B0488: sh          $t1, 0x146($sp)
    MEM_H(0X146, ctx->r29) = ctx->r9;
    // 0x800B048C: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
    // 0x800B0490: sh          $zero, 0x140($sp)
    MEM_H(0X140, ctx->r29) = 0;
    // 0x800B0494: lh          $t5, 0x148($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X148);
    // 0x800B0498: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B049C: beq         $t5, $at, L_800B04C8
    if (ctx->r13 == ctx->r1) {
        // 0x800B04A0: sw          $t5, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r13;
            goto L_800B04C8;
    }
    // 0x800B04A0: sw          $t5, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r13;
L_800B04A4:
    // 0x800B04A4: lhu         $t8, 0x140($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X140);
    // 0x800B04A8: nop

    // 0x800B04AC: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800B04B0: sh          $t0, 0x140($sp)
    MEM_H(0X140, ctx->r29) = ctx->r8;
    // 0x800B04B4: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x800B04B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B04BC: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800B04C0: bne         $t4, $at, L_800B04A4
    if (ctx->r12 != ctx->r1) {
        // 0x800B04C4: sw          $t4, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r12;
            goto L_800B04A4;
    }
    // 0x800B04C4: sw          $t4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r12;
L_800B04C8:
    // 0x800B04C8: lh          $t2, 0x146($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X146);
    // 0x800B04CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B04D0: beq         $t2, $at, L_800B04FC
    if (ctx->r10 == ctx->r1) {
        // 0x800B04D4: sw          $t2, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r10;
            goto L_800B04FC;
    }
    // 0x800B04D4: sw          $t2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r10;
L_800B04D8:
    // 0x800B04D8: lhu         $t6, 0x13E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X13E);
    // 0x800B04DC: nop

    // 0x800B04E0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B04E4: sh          $t7, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r15;
    // 0x800B04E8: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800B04EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B04F0: sra         $t1, $t9, 1
    ctx->r9 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800B04F4: bne         $t1, $at, L_800B04D8
    if (ctx->r9 != ctx->r1) {
        // 0x800B04F8: sw          $t1, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r9;
            goto L_800B04D8;
    }
    // 0x800B04F8: sw          $t1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r9;
L_800B04FC:
    // 0x800B04FC: lh          $a0, 0x14A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X14A);
    // 0x800B0500: lh          $a1, 0x16A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X16A);
    // 0x800B0504: jal         0x800B08FC
    // 0x800B0508: nop

    func_800B08FC(rdram, ctx);
        goto after_14;
    // 0x800B0508: nop

    after_14:
    // 0x800B050C: sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
    // 0x800B0510: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x800B0514: nop

    // 0x800B0518: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x800B051C: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x800B0520: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x800B0524: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x800B0528: lui         $t0, 0xFD10
    ctx->r8 = S32(0XFD10 << 16);
    // 0x800B052C: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800B0530: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
    // 0x800B0534: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800B0538: nop

    // 0x800B053C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x800B0540: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800B0544: nop

    // 0x800B0548: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800B054C: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B0550: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x800B0554: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800B0558: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x800B055C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800B0560: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x800B0564: lhu         $t4, 0x13E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X13E);
    // 0x800B0568: andi        $t8, $t5, 0x3
    ctx->r24 = ctx->r13 & 0X3;
    // 0x800B056C: sll         $t0, $t8, 18
    ctx->r8 = S32(ctx->r24 << 18);
    // 0x800B0570: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0574: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x800B0578: or          $t3, $t0, $at
    ctx->r11 = ctx->r8 | ctx->r1;
    // 0x800B057C: andi        $t2, $t4, 0xF
    ctx->r10 = ctx->r12 & 0XF;
    // 0x800B0580: lhu         $t0, 0x140($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X140);
    // 0x800B0584: sll         $t6, $t2, 14
    ctx->r14 = S32(ctx->r10 << 14);
    // 0x800B0588: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800B058C: andi        $t1, $t9, 0x3
    ctx->r9 = ctx->r25 & 0X3;
    // 0x800B0590: sll         $t5, $t1, 8
    ctx->r13 = S32(ctx->r9 << 8);
    // 0x800B0594: andi        $t4, $t0, 0xF
    ctx->r12 = ctx->r8 & 0XF;
    // 0x800B0598: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800B059C: sll         $t2, $t4, 4
    ctx->r10 = S32(ctx->r12 << 4);
    // 0x800B05A0: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x800B05A4: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800B05A8: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800B05AC: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x800B05B0: nop

    // 0x800B05B4: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x800B05B8: sw          $t1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r9;
    // 0x800B05BC: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x800B05C0: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800B05C4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B05C8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800B05CC: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800B05D0: nop

    // 0x800B05D4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800B05D8: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x800B05DC: nop

    // 0x800B05E0: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800B05E4: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x800B05E8: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x800B05EC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800B05F0: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x800B05F4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800B05F8: lh          $t6, 0x148($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X148);
    // 0x800B05FC: lh          $t9, 0x146($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X146);
    // 0x800B0600: nop

    // 0x800B0604: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B0608: mflo        $t1
    ctx->r9 = lo;
    // 0x800B060C: addiu       $t7, $t1, -0x1
    ctx->r15 = ADD32(ctx->r9, -0X1);
    // 0x800B0610: slti        $at, $t7, 0x7FF
    ctx->r1 = SIGNED(ctx->r15) < 0X7FF ? 1 : 0;
    // 0x800B0614: beq         $at, $zero, L_800B0624
    if (ctx->r1 == 0) {
        // 0x800B0618: nop

            goto L_800B0624;
    }
    // 0x800B0618: nop

    // 0x800B061C: b           L_800B0628
    // 0x800B0620: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
        goto L_800B0628;
    // 0x800B0620: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800B0624:
    // 0x800B0624: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_800B0628:
    // 0x800B0628: lh          $t5, 0x148($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X148);
    // 0x800B062C: nop

    // 0x800B0630: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x800B0634: bgez        $t0, L_800B0644
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B0638: sra         $t4, $t0, 3
        ctx->r12 = S32(SIGNED(ctx->r8) >> 3);
            goto L_800B0644;
    }
    // 0x800B0638: sra         $t4, $t0, 3
    ctx->r12 = S32(SIGNED(ctx->r8) >> 3);
    // 0x800B063C: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x800B0640: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800B0644:
    // 0x800B0644: bgtz        $t4, L_800B0654
    if (SIGNED(ctx->r12) > 0) {
        // 0x800B0648: nop

            goto L_800B0654;
    }
    // 0x800B0648: nop

    // 0x800B064C: b           L_800B0678
    // 0x800B0650: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800B0678;
    // 0x800B0650: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800B0654:
    // 0x800B0654: lh          $s1, 0x148($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X148);
    // 0x800B0658: nop

    // 0x800B065C: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x800B0660: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800B0664: bgez        $s1, L_800B0674
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800B0668: sra         $t2, $s1, 3
        ctx->r10 = S32(SIGNED(ctx->r17) >> 3);
            goto L_800B0674;
    }
    // 0x800B0668: sra         $t2, $s1, 3
    ctx->r10 = S32(SIGNED(ctx->r17) >> 3);
    // 0x800B066C: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x800B0670: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_800B0674:
    // 0x800B0674: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
L_800B0678:
    // 0x800B0678: lh          $t3, 0x148($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X148);
    // 0x800B067C: nop

    // 0x800B0680: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800B0684: bgez        $t6, L_800B0694
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B0688: sra         $t9, $t6, 3
        ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
            goto L_800B0694;
    }
    // 0x800B0688: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B068C: addiu       $at, $t6, 0x7
    ctx->r1 = ADD32(ctx->r14, 0X7);
    // 0x800B0690: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800B0694:
    // 0x800B0694: bgtz        $t9, L_800B06A4
    if (SIGNED(ctx->r25) > 0) {
        // 0x800B0698: nop

            goto L_800B06A4;
    }
    // 0x800B0698: nop

    // 0x800B069C: b           L_800B06C8
    // 0x800B06A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800B06C8;
    // 0x800B06A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800B06A4:
    // 0x800B06A4: lh          $s0, 0x148($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X148);
    // 0x800B06A8: nop

    // 0x800B06AC: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x800B06B0: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x800B06B4: bgez        $s0, L_800B06C4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800B06B8: sra         $t7, $s0, 3
        ctx->r15 = S32(SIGNED(ctx->r16) >> 3);
            goto L_800B06C4;
    }
    // 0x800B06B8: sra         $t7, $s0, 3
    ctx->r15 = S32(SIGNED(ctx->r16) >> 3);
    // 0x800B06BC: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x800B06C0: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800B06C4:
    // 0x800B06C4: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_800B06C8:
    // 0x800B06C8: addiu       $t5, $s1, 0x7FF
    ctx->r13 = ADD32(ctx->r17, 0X7FF);
    // 0x800B06CC: div         $zero, $t5, $s0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r16)));
    // 0x800B06D0: andi        $t8, $s2, 0xFFF
    ctx->r24 = ctx->r18 & 0XFFF;
    // 0x800B06D4: bne         $s0, $zero, L_800B06E0
    if (ctx->r16 != 0) {
        // 0x800B06D8: nop

            goto L_800B06E0;
    }
    // 0x800B06D8: nop

    // 0x800B06DC: break       7
    do_break(2148206300);
L_800B06E0:
    // 0x800B06E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B06E4: bne         $s0, $at, L_800B06F8
    if (ctx->r16 != ctx->r1) {
        // 0x800B06E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B06F8;
    }
    // 0x800B06E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B06EC: bne         $t5, $at, L_800B06F8
    if (ctx->r13 != ctx->r1) {
        // 0x800B06F0: nop

            goto L_800B06F8;
    }
    // 0x800B06F0: nop

    // 0x800B06F4: break       6
    do_break(2148206324);
L_800B06F8:
    // 0x800B06F8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B06FC: sll         $t2, $t8, 12
    ctx->r10 = S32(ctx->r24 << 12);
    // 0x800B0700: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800B0704: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800B0708: mflo        $t0
    ctx->r8 = lo;
    // 0x800B070C: andi        $t4, $t0, 0xFFF
    ctx->r12 = ctx->r8 & 0XFFF;
    // 0x800B0710: or          $t6, $t4, $t3
    ctx->r14 = ctx->r12 | ctx->r11;
    // 0x800B0714: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800B0718: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800B071C: nop

    // 0x800B0720: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800B0724: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B0728: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x800B072C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800B0730: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800B0734: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800B0738: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800B073C: nop

    // 0x800B0740: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800B0744: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800B0748: nop

    // 0x800B074C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800B0750: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x800B0754: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x800B0758: lh          $t3, 0x148($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X148);
    // 0x800B075C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800B0760: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800B0764: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x800B0768: sra         $t1, $t9, 3
    ctx->r9 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800B076C: andi        $t7, $t1, 0x1FF
    ctx->r15 = ctx->r9 & 0X1FF;
    // 0x800B0770: sll         $t5, $t7, 9
    ctx->r13 = S32(ctx->r15 << 9);
    // 0x800B0774: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800B0778: or          $t0, $t5, $at
    ctx->r8 = ctx->r13 | ctx->r1;
    // 0x800B077C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800B0780: lw          $t2, 0x14C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14C);
    // 0x800B0784: lhu         $t6, 0x13E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X13E);
    // 0x800B0788: andi        $t4, $t2, 0x3
    ctx->r12 = ctx->r10 & 0X3;
    // 0x800B078C: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800B0790: sll         $t3, $t4, 18
    ctx->r11 = S32(ctx->r12 << 18);
    // 0x800B0794: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x800B0798: lhu         $t4, 0x140($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X140);
    // 0x800B079C: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x800B07A0: or          $t7, $t3, $t1
    ctx->r15 = ctx->r11 | ctx->r9;
    // 0x800B07A4: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x800B07A8: sll         $t8, $t0, 8
    ctx->r24 = S32(ctx->r8 << 8);
    // 0x800B07AC: andi        $t6, $t4, 0xF
    ctx->r14 = ctx->r12 & 0XF;
    // 0x800B07B0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800B07B4: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x800B07B8: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x800B07BC: or          $t3, $t2, $t9
    ctx->r11 = ctx->r10 | ctx->r25;
    // 0x800B07C0: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x800B07C4: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x800B07C8: nop

    // 0x800B07CC: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800B07D0: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x800B07D4: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x800B07D8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800B07DC: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800B07E0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800B07E4: lh          $t4, 0x148($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X148);
    // 0x800B07E8: lh          $t1, 0x146($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X146);
    // 0x800B07EC: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x800B07F0: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x800B07F4: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x800B07F8: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x800B07FC: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x800B0800: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800B0804: sll         $t3, $t9, 12
    ctx->r11 = S32(ctx->r25 << 12);
    // 0x800B0808: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x800B080C: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800B0810: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x800B0814: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800B0818: nop

    // 0x800B081C: addiu       $t2, $t6, 0x5
    ctx->r10 = ADD32(ctx->r14, 0X5);
    // 0x800B0820: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800B0824: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x800B0828: nop

    // 0x800B082C: addiu       $t1, $t9, -0x5
    ctx->r9 = ADD32(ctx->r25, -0X5);
    // 0x800B0830: sw          $t1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r9;
    // 0x800B0834: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x800B0838: nop

    // 0x800B083C: addiu       $t0, $t5, 0x7
    ctx->r8 = ADD32(ctx->r13, 0X7);
    // 0x800B0840: sw          $t0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r8;
    // 0x800B0844: b           L_800B084C
    // 0x800B0848: nop

        goto L_800B084C;
    // 0x800B0848: nop

L_800B084C:
    // 0x800B084C: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x800B0850: nop

    // 0x800B0854: bgtz        $t3, L_800AFCB8
    if (SIGNED(ctx->r11) > 0) {
        // 0x800B0858: nop

            goto L_800AFCB8;
    }
    // 0x800B0858: nop

L_800B085C:
    // 0x800B085C: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x800B0860: nop

    // 0x800B0864: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800B0868: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x800B086C: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800B0870: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800B0874: lui         $t4, 0xB800
    ctx->r12 = S32(0XB800 << 16);
    // 0x800B0878: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800B087C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800B0880: nop

    // 0x800B0884: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800B0888: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x800B088C: nop

    // 0x800B0890: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800B0894: sw          $t1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r9;
    // 0x800B0898: jal         0x800BC6EC
    // 0x800B089C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_15;
    // 0x800B089C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_15:
    // 0x800B08A0: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x800B08A4: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800B08A8: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x800B08AC: lw          $a2, 0x158($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X158);
    // 0x800B08B0: jal         0x800BD218
    // 0x800B08B4: nop

    SysMem_DmaCopy(rdram, ctx);
        goto after_16;
    // 0x800B08B4: nop

    after_16:
    // 0x800B08B8: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x800B08BC: b           L_800B08CC
    // 0x800B08C0: nop

        goto L_800B08CC;
    // 0x800B08C0: nop

    // 0x800B08C4: b           L_800B08CC
    // 0x800B08C8: nop

        goto L_800B08CC;
    // 0x800B08C8: nop

L_800B08CC:
    // 0x800B08CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B08D0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B08D4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B08D8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B08DC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B08E0: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800B08E4: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B08E8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800B08EC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800B08F0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800B08F4: jr          $ra
    // 0x800B08F8: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x800B08F8: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
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
RECOMP_FUNC void func_800B0A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0A3C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B0A40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B0A44: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800B0A48: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800B0A4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B0A50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B0A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B0A58: lui         $t6, 0x80A2
    ctx->r14 = S32(0X80A2 << 16);
    // 0x800B0A5C: addiu       $t6, $t6, 0x25B0
    ctx->r14 = ADD32(ctx->r14, 0X25B0);
    // 0x800B0A60: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0A64: sw          $t6, -0x458($at)
    MEM_W(-0X458, ctx->r1) = ctx->r14;
    // 0x800B0A68: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B0A6C: addiu       $t7, $t7, 0x5B0
    ctx->r15 = ADD32(ctx->r15, 0X5B0);
    // 0x800B0A70: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800B0A74: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x800B0A78: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800B0A7C: lw          $t0, -0x458($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X458);
    // 0x800B0A80: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B0A84: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B0A88: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800B0A8C: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800B0A90: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B0A94: jal         0x800BD1FC
    // 0x800B0A98: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x800B0A98: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x800B0A9C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B0AA0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0AA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800B0AA8: jal         0x800BD218
    // 0x800B0AAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B0AAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800B0AB0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B0AB4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B0AB8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B0ABC: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800B0AC0: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800B0AC4: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x800B0AC8: jal         0x800BD1FC
    // 0x800B0ACC: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B0ACC: nop

    after_2:
    // 0x800B0AD0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B0AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0AD8: jal         0x800BED70
    // 0x800B0ADC: nop

    Spi_GetHeader(rdram, ctx);
        goto after_3;
    // 0x800B0ADC: nop

    after_3:
    // 0x800B0AE0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800B0AE4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800B0AE8: lw          $t2, 0x494($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X494);
    // 0x800B0AEC: nop

    // 0x800B0AF0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800B0AF4: bgez        $t2, L_800B0B10
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B0AF8: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_800B0B10;
    }
    // 0x800B0AF8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800B0AFC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800B0B00: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B0B04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B0B08: nop

    // 0x800B0B0C: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_800B0B10:
    // 0x800B0B10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0B14: lwc1        $f11, -0x6D0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6D0);
    // 0x800B0B18: lwc1        $f10, -0x6CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6CC);
    // 0x800B0B1C: nop

    // 0x800B0B20: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800B0B24: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B0B28: nop

    // 0x800B0B2C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B0B30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0B34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B0B38: nop

    // 0x800B0B3C: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800B0B40: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800B0B44: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B0B48: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x800B0B4C: jal         0x800BC6EC
    // 0x800B0B50: sll         $a0, $t4, 4
    ctx->r4 = S32(ctx->r12 << 4);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800B0B50: sll         $a0, $t4, 4
    ctx->r4 = S32(ctx->r12 << 4);
    after_4:
    // 0x800B0B54: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800B0B58: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0B5C: nop

    // 0x800B0B60: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800B0B64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0B68: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0B6C: jal         0x800BEE48
    // 0x800B0B70: nop

    Spi_LimitedDecompress(rdram, ctx);
        goto after_5;
    // 0x800B0B70: nop

    after_5:
    // 0x800B0B74: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B0B78: addiu       $t6, $t6, 0x4A8
    ctx->r14 = ADD32(ctx->r14, 0X4A8);
    // 0x800B0B7C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800B0B80: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B0B84: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800B0B88: blez        $t7, L_800B0CB0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B0B8C: nop

            goto L_800B0CB0;
    }
    // 0x800B0B8C: nop

L_800B0B90:
    // 0x800B0B90: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B0B94: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0B98: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800B0B9C: nop

    // 0x800B0BA0: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800B0BA4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BA8: nop

    // 0x800B0BAC: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B0BB0: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B0BB4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BB8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0BBC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800B0BC0: nop

    // 0x800B0BC4: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x800B0BC8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BCC: nop

    // 0x800B0BD0: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800B0BD4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800B0BD8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BDC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0BE0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800B0BE4: nop

    // 0x800B0BE8: sh          $t9, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r25;
    // 0x800B0BEC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B0BF0: nop

    // 0x800B0BF4: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B0BF8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B0BFC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B0C04: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x800B0C08: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C0C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C10: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x800B0C14: nop

    // 0x800B0C18: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x800B0C1C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C20: nop

    // 0x800B0C24: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x800B0C28: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800B0C2C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C30: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C34: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800B0C38: nop

    // 0x800B0C3C: sh          $t1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r9;
    // 0x800B0C40: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C44: nop

    // 0x800B0C48: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800B0C4C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800B0C50: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C54: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800B0C58: sb          $t5, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r13;
    // 0x800B0C5C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C60: nop

    // 0x800B0C64: lbu         $s1, 0xF($t7)
    ctx->r17 = MEM_BU(ctx->r15, 0XF);
    // 0x800B0C68: nop

    // 0x800B0C6C: sb          $s1, 0xE($t7)
    MEM_B(0XE, ctx->r15) = ctx->r17;
    // 0x800B0C70: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C74: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800B0C78: sb          $s0, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r16;
    // 0x800B0C7C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C80: nop

    // 0x800B0C84: sb          $s0, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r16;
    // 0x800B0C88: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C8C: nop

    // 0x800B0C90: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800B0C94: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800B0C98: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800B0C9C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800B0CA0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B0CA4: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B0CA8: bne         $at, $zero, L_800B0B90
    if (ctx->r1 != 0) {
        // 0x800B0CAC: sw          $t3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r11;
            goto L_800B0B90;
    }
    // 0x800B0CAC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800B0CB0:
    // 0x800B0CB0: lh          $t5, 0x56($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X56);
    // 0x800B0CB4: nop

    // 0x800B0CB8: beq         $t5, $zero, L_800B0D04
    if (ctx->r13 == 0) {
        // 0x800B0CBC: nop

            goto L_800B0D04;
    }
    // 0x800B0CBC: nop

    // 0x800B0CC0: jal         0x800BC6EC
    // 0x800B0CC4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x800B0CC4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_6:
    // 0x800B0CC8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B0CCC: lw          $t6, -0x440($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X440);
    // 0x800B0CD0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800B0CD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0CD8: sw          $s2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r18;
    // 0x800B0CDC: sw          $s2, -0x440($at)
    MEM_W(-0X440, ctx->r1) = ctx->r18;
    // 0x800B0CE0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B0CE4: lw          $t8, -0x440($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X440);
    // 0x800B0CE8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800B0CEC: nop

    // 0x800B0CF0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800B0CF4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B0CF8: lw          $t9, -0x440($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X440);
    // 0x800B0CFC: nop

    // 0x800B0D00: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_800B0D04:
    // 0x800B0D04: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800B0D08: b           L_800B0D18
    // 0x800B0D0C: nop

        goto L_800B0D18;
    // 0x800B0D0C: nop

    // 0x800B0D10: b           L_800B0D18
    // 0x800B0D14: nop

        goto L_800B0D18;
    // 0x800B0D14: nop

L_800B0D18:
    // 0x800B0D18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B0D1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0D20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0D24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B0D28: jr          $ra
    // 0x800B0D2C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B0D2C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
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
RECOMP_FUNC void func_800B0E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B0E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B0E10: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B0E14: lbu         $t6, 0x448($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X448);
    // 0x800B0E18: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0E1C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B0E20: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800B0E24: sb          $t8, 0x448($at)
    MEM_B(0X448, ctx->r1) = ctx->r24;
    // 0x800B0E28: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B0E2C: lbu         $t9, 0x448($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X448);
    // 0x800B0E30: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B0E34: addiu       $t1, $t1, -0x470
    ctx->r9 = ADD32(ctx->r9, -0X470);
    // 0x800B0E38: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B0E3C: jal         0x800B0D30
    // 0x800B0E40: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    func_800B0D30(rdram, ctx);
        goto after_0;
    // 0x800B0E40: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x800B0E44: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0E48: sw          $v0, -0x45C($at)
    MEM_W(-0X45C, ctx->r1) = ctx->r2;
    // 0x800B0E4C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800B0E50: lbu         $t2, 0x448($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X448);
    // 0x800B0E54: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800B0E58: addiu       $t4, $t4, -0x450
    ctx->r12 = ADD32(ctx->r12, -0X450);
    // 0x800B0E5C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800B0E60: jal         0x800B0D30
    // 0x800B0E64: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    func_800B0D30(rdram, ctx);
        goto after_1;
    // 0x800B0E64: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x800B0E68: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0E6C: sw          $v0, -0x440($at)
    MEM_W(-0X440, ctx->r1) = ctx->r2;
    // 0x800B0E70: b           L_800B0E78
    // 0x800B0E74: nop

        goto L_800B0E78;
    // 0x800B0E74: nop

L_800B0E78:
    // 0x800B0E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B0E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B0E80: jr          $ra
    // 0x800B0E84: nop

    return;
    // 0x800B0E84: nop

;}
RECOMP_FUNC void func_800B0E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0E88: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800B0E8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B0E90: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800B0E94: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800B0E98: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800B0E9C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800B0EA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B0EA4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B0EA8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B0EAC: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B0EB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0EB4: swc1        $f4, 0x220($at)
    MEM_W(0X220, ctx->r1) = ctx->f4.u32l;
    // 0x800B0EB8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B0EBC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B0EC0: swc1        $f6, 0x428($at)
    MEM_W(0X428, ctx->r1) = ctx->f6.u32l;
    // 0x800B0EC4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800B0EC8: nop

    // 0x800B0ECC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B0ED0: nop

    // 0x800B0ED4: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800B0ED8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B0EDC: addiu       $t8, $t8, 0x1E0
    ctx->r24 = ADD32(ctx->r24, 0X1E0);
    // 0x800B0EE0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800B0EE4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800B0EE8: lw          $t9, 0x1B14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1B14);
    // 0x800B0EEC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B0EF0: addiu       $t1, $t1, -0x770
    ctx->r9 = ADD32(ctx->r9, -0X770);
    // 0x800B0EF4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800B0EF8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B0EFC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800B0F00: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B0F04: lw          $t3, 0x1B14($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B14);
    // 0x800B0F08: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800B0F0C: addiu       $t5, $t5, -0x558
    ctx->r13 = ADD32(ctx->r13, -0X558);
    // 0x800B0F10: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x800B0F14: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800B0F18: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800B0F1C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
L_800B0F20:
    // 0x800B0F20: lh          $t8, 0x56($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X56);
    // 0x800B0F24: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0F28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B0F2C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B0F30: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B0F34: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x800B0F38: lh          $t1, 0x56($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X56);
    // 0x800B0F3C: nop

    // 0x800B0F40: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B0F44: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800B0F48: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800B0F4C: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x800B0F50: bne         $at, $zero, L_800B0F20
    if (ctx->r1 != 0) {
        // 0x800B0F54: sh          $t2, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r10;
            goto L_800B0F20;
    }
    // 0x800B0F54: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x800B0F58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0F5C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B0F60: lwc1        $f19, -0x6C8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X6C8);
    // 0x800B0F64: lwc1        $f18, -0x6C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6C4);
    // 0x800B0F68: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800B0F6C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B0F70: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800B0F74: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800B0F78: jal         0x800C3338
    // 0x800B0F7C: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    MathUtil_Cosf(rdram, ctx);
        goto after_0;
    // 0x800B0F7C: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    after_0:
    // 0x800B0F80: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B0F84: jal         0x800C3070
    // 0x800B0F88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x800B0F88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x800B0F8C: nop

    // 0x800B0F90: div.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl);
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800B0F94: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B0F98: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B0F9C: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B0FA0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0FA4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800B0FA8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0FAC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B0FB0: nop

    // 0x800B0FB4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0FB8: nop

    // 0x800B0FBC: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B0FC0: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800B0FC4: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B0FC8: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B0FCC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0FD0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800B0FD4: swc1        $f6, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f6.u32l;
    // 0x800B0FD8: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B0FDC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B0FE0: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B0FE4: add.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f20.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B0FE8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0FEC: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800B0FF0: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800B0FF4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x800B0FF8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800B0FFC: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B1000: swc1        $f6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f6.u32l;
    // 0x800B1004: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B1008: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800B100C: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = -ctx->f18.fl;
    // 0x800B1010: swc1        $f8, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f8.u32l;
    // 0x800B1014: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B1018: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B101C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B1020: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B1024: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800B1028: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800B102C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B1030: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B1034: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800B1038: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B103C: mul.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800B1040: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800B1044: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B1048: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x800B104C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B1050: nop

    // 0x800B1054: div.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f8.d);
    // 0x800B1058: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x800B105C: swc1        $f16, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f16.u32l;
    // 0x800B1060: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B1064: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B1068: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B106C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B1070: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800B1074: c.le.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d <= ctx->f18.d;
    // 0x800B1078: nop

    // 0x800B107C: bc1f        L_800B1094
    if (!c1cs) {
        // 0x800B1080: nop

            goto L_800B1094;
    }
    // 0x800B1080: nop

    // 0x800B1084: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1088: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x800B108C: b           L_800B1150
    // 0x800B1090: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
        goto L_800B1150;
    // 0x800B1090: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
L_800B1094:
    // 0x800B1094: lui         $at, 0x4800
    ctx->r1 = S32(0X4800 << 16);
    // 0x800B1098: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B109C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B10A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800B10A4: div.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800B10A8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B10AC: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800B10B0: nop

    // 0x800B10B4: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B10B8: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800B10BC: nop

    // 0x800B10C0: andi        $at, $s0, 0x4
    ctx->r1 = ctx->r16 & 0X4;
    // 0x800B10C4: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800B10C8: beq         $s0, $zero, L_800B111C
    if (ctx->r16 == 0) {
        // 0x800B10CC: nop

            goto L_800B111C;
    }
    // 0x800B10CC: nop

    // 0x800B10D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B10D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B10D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800B10DC: sub.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800B10E0: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x800B10E4: nop

    // 0x800B10E8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B10EC: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x800B10F0: nop

    // 0x800B10F4: andi        $at, $s0, 0x4
    ctx->r1 = ctx->r16 & 0X4;
    // 0x800B10F8: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x800B10FC: bne         $s0, $zero, L_800B1114
    if (ctx->r16 != 0) {
        // 0x800B1100: nop

            goto L_800B1114;
    }
    // 0x800B1100: nop

    // 0x800B1104: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x800B1108: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B110C: b           L_800B112C
    // 0x800B1110: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_800B112C;
    // 0x800B1110: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_800B1114:
    // 0x800B1114: b           L_800B112C
    // 0x800B1118: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_800B112C;
    // 0x800B1118: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_800B111C:
    // 0x800B111C: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x800B1120: nop

    // 0x800B1124: bltz        $s0, L_800B1114
    if (SIGNED(ctx->r16) < 0) {
        // 0x800B1128: nop

            goto L_800B1114;
    }
    // 0x800B1128: nop

L_800B112C:
    // 0x800B112C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1130: andi        $t3, $s0, 0xFFFF
    ctx->r11 = ctx->r16 & 0XFFFF;
    // 0x800B1134: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x800B1138: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B113C: bgtz        $s0, L_800B1150
    if (SIGNED(ctx->r16) > 0) {
        // 0x800B1140: sh          $s0, 0x0($t4)
        MEM_H(0X0, ctx->r12) = ctx->r16;
            goto L_800B1150;
    }
    // 0x800B1140: sh          $s0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r16;
    // 0x800B1144: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1148: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B114C: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_800B1150:
    // 0x800B1150: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B1154: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800B1158: jal         0x800C2D6C
    // 0x800B115C: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    MtxUtil_MtxFToMtx(rdram, ctx);
        goto after_2;
    // 0x800B115C: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    after_2:
    // 0x800B1160: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B1164: lhu         $t8, -0x778($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X778);
    // 0x800B1168: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B116C: lw          $t9, -0x77C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X77C);
    // 0x800B1170: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B1174: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x800B1178: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    // 0x800B117C: jal         0x800C2D6C
    // 0x800B1180: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    MtxUtil_MtxFToMtx(rdram, ctx);
        goto after_3;
    // 0x800B1180: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    after_3:
    // 0x800B1184: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800B1188: nop

    // 0x800B118C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800B1190: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800B1194: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B1198: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B119C: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800B11A0: ori         $t2, $t2, 0xE
    ctx->r10 = ctx->r10 | 0XE;
    // 0x800B11A4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800B11A8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B11AC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B11B0: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800B11B4: nop

    // 0x800B11B8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800B11BC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800B11C0: nop

    // 0x800B11C4: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800B11C8: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800B11CC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800B11D0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B11D4: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x800B11D8: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x800B11DC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B11E0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B11E4: lhu         $t1, -0x778($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X778);
    // 0x800B11E8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800B11EC: lw          $t3, -0x77C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X77C);
    // 0x800B11F0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800B11F4: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x800B11F8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B11FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B1200: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B1204: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800B1208: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B120C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800B1210: lhu         $t8, -0x778($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X778);
    // 0x800B1214: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1218: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800B121C: sh          $t7, -0x778($at)
    MEM_H(-0X778, ctx->r1) = ctx->r15;
    // 0x800B1220: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800B1224: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800B1228: nop

    // 0x800B122C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B1230: b           L_800B1238
    // 0x800B1234: nop

        goto L_800B1238;
    // 0x800B1234: nop

L_800B1238:
    // 0x800B1238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B123C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B1240: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B1244: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B1248: jr          $ra
    // 0x800B124C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800B124C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800B1250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1250: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800B1254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1258: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800B125C: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800B1260: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800B1264: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800B1268: nop

    // 0x800B126C: addiu       $t7, $t6, 0x18
    ctx->r15 = ADD32(ctx->r14, 0X18);
    // 0x800B1270: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800B1274: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B1278: nop

    // 0x800B127C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800B1280: nop

    // 0x800B1284: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x800B1288: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B128C: nop

    // 0x800B1290: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800B1294: nop

    // 0x800B1298: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800B129C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B12A0: nop

    // 0x800B12A4: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800B12A8: nop

    // 0x800B12AC: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800B12B0: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x800B12B4: nop

    // 0x800B12B8: addiu       $t2, $t1, 0x24
    ctx->r10 = ADD32(ctx->r9, 0X24);
    // 0x800B12BC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800B12C0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B12C4: nop

    // 0x800B12C8: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800B12CC: nop

    // 0x800B12D0: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x800B12D4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B12D8: nop

    // 0x800B12DC: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800B12E0: nop

    // 0x800B12E4: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x800B12E8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B12EC: nop

    // 0x800B12F0: lwc1        $f18, 0x8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X8);
    // 0x800B12F4: nop

    // 0x800B12F8: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800B12FC: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800B1300: nop

    // 0x800B1304: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B1308: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800B130C: nop

    // 0x800B1310: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x800B1314: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B1318: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B131C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B1320: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800B1324: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B1328: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B132C: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x800B1330: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B1334: nop

    // 0x800B1338: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800B133C: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800B1340: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x800B1344: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800B1348: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B134C: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800B1350: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B1354: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B1358: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x800B135C: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800B1360: nop

    // 0x800B1364: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800B1368: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B136C: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x800B1370: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B1374: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B1378: lwc1        $f4, 0x8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800B137C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B1380: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800B1384: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800B1388: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800B138C: nop

    // 0x800B1390: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800B1394: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B1398: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x800B139C: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B13A0: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B13A4: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800B13A8: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B13AC: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800B13B0: nop

    // 0x800B13B4: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800B13B8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B13BC: jal         0x800C42A0
    // 0x800B13C0: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B13C0: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_0:
    // 0x800B13C4: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800B13C8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800B13CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B13D0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800B13D4: nop

    // 0x800B13D8: div.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d);
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f8.d);
    // 0x800B13DC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x800B13E0: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x800B13E4: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B13E8: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B13EC: nop

    // 0x800B13F0: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800B13F4: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
    // 0x800B13F8: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B13FC: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B1400: nop

    // 0x800B1404: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800B1408: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x800B140C: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B1410: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B1414: nop

    // 0x800B1418: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800B141C: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x800B1420: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1424: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B1428: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B142C: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800B1430: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B1434: nop

    // 0x800B1438: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800B143C: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800B1440: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800B1444: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B1448: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B144C: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B1450: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B1454: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B1458: nop

    // 0x800B145C: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B1460: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B1464: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x800B1468: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B146C: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B1470: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1474: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B1478: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B147C: nop

    // 0x800B1480: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800B1484: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800B1488: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x800B148C: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800B1490: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1494: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800B1498: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B149C: mul.s       $f16, $f8, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800B14A0: nop

    // 0x800B14A4: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B14A8: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800B14AC: jal         0x800C42A0
    // 0x800B14B0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B14B0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_1:
    // 0x800B14B4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B14B8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B14BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B14C0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800B14C4: nop

    // 0x800B14C8: div.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x800B14CC: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800B14D0: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x800B14D4: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800B14D8: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B14DC: nop

    // 0x800B14E0: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B14E4: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800B14E8: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B14EC: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B14F0: nop

    // 0x800B14F4: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800B14F8: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x800B14FC: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1500: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B1504: nop

    // 0x800B1508: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B150C: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x800B1510: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B1514: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1518: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B151C: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800B1520: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1524: nop

    // 0x800B1528: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B152C: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800B1530: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x800B1534: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B1538: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800B153C: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B1540: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800B1544: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1548: nop

    // 0x800B154C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800B1550: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B1554: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x800B1558: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B155C: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1560: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B1564: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B1568: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800B156C: nop

    // 0x800B1570: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B1574: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800B1578: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800B157C: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B1580: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1584: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B1588: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B158C: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800B1590: nop

    // 0x800B1594: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B1598: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B159C: jal         0x800C42A0
    // 0x800B15A0: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B15A0: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_2:
    // 0x800B15A4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B15A8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B15AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B15B0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x800B15B4: nop

    // 0x800B15B8: div.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f18.d);
    // 0x800B15BC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800B15C0: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x800B15C4: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B15C8: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B15CC: nop

    // 0x800B15D0: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800B15D4: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x800B15D8: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B15DC: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B15E0: nop

    // 0x800B15E4: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B15E8: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x800B15EC: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B15F0: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B15F4: nop

    // 0x800B15F8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800B15FC: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x800B1600: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800B1604: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B1608: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x800B160C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1610: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B1614: swc1        $f8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f8.u32l;
    // 0x800B1618: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B161C: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800B1620: swc1        $f6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f6.u32l;
    // 0x800B1624: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B1628: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800B162C: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B1630: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800B1634: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1638: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B163C: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B1640: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B1644: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1648: nop

    // 0x800B164C: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B1650: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B1654: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800B1658: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B165C: swc1        $f6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f6.u32l;
    // 0x800B1660: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B1664: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x800B1668: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
    // 0x800B166C: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1670: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B1674: swc1        $f18, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f18.u32l;
    // 0x800B1678: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B167C: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x800B1680: swc1        $f16, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f16.u32l;
    // 0x800B1684: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B1688: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B168C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B1690: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800B1694: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1698: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B169C: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x800B16A0: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B16A4: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B16A8: nop

    // 0x800B16AC: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B16B0: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800B16B4: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B16B8: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = -ctx->f6.fl;
    // 0x800B16BC: swc1        $f16, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f16.u32l;
    // 0x800B16C0: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B16C4: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x800B16C8: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x800B16CC: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B16D0: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x800B16D4: swc1        $f10, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f10.u32l;
    // 0x800B16D8: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B16DC: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B16E0: swc1        $f8, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f8.u32l;
    // 0x800B16E4: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B16E8: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B16EC: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B16F0: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800B16F4: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B16F8: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B16FC: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B1700: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B1704: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B1708: nop

    // 0x800B170C: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B1710: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800B1714: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800B1718: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = -ctx->f16.fl;
    // 0x800B171C: swc1        $f8, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f8.u32l;
    // 0x800B1720: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B1724: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800B1728: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x800B172C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B1730: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B1734: swc1        $f4, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f4.u32l;
    // 0x800B1738: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B173C: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x800B1740: swc1        $f18, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f18.u32l;
    // 0x800B1744: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B1748: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B174C: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B1750: swc1        $f10, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f10.u32l;
    // 0x800B1754: lhu         $t1, 0xB2($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XB2);
    // 0x800B1758: nop

    // 0x800B175C: bne         $t1, $zero, L_800B176C
    if (ctx->r9 != 0) {
        // 0x800B1760: nop

            goto L_800B176C;
    }
    // 0x800B1760: nop

    // 0x800B1764: jal         0x800C1850
    // 0x800B1768: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_3;
    // 0x800B1768: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_800B176C:
    // 0x800B176C: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B1770: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B1774: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800B1778: jal         0x800C2948
    // 0x800B177C: nop

    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_4;
    // 0x800B177C: nop

    after_4:
    // 0x800B1780: jal         0x800C1D44
    // 0x800B1784: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800C1D44(rdram, ctx);
        goto after_5;
    // 0x800B1784: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x800B1788: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800B178C: lhu         $t2, -0x778($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X778);
    // 0x800B1790: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800B1794: lw          $t4, -0x77C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X77C);
    // 0x800B1798: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x800B179C: jal         0x800C2AE8
    // 0x800B17A0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_6;
    // 0x800B17A0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_6:
    // 0x800B17A4: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x800B17A8: nop

    // 0x800B17AC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B17B0: nop

    // 0x800B17B4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800B17B8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B17BC: nop

    // 0x800B17C0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800B17C4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800B17C8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800B17CC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B17D0: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x800B17D4: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x800B17D8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B17DC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B17E0: lhu         $t1, -0x778($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X778);
    // 0x800B17E4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800B17E8: lw          $t3, -0x77C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X77C);
    // 0x800B17EC: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800B17F0: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x800B17F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800B17F8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B17FC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B1800: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800B1804: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800B1808: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800B180C: lhu         $t7, -0x778($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X778);
    // 0x800B1810: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1814: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B1818: sh          $t8, -0x778($at)
    MEM_H(-0X778, ctx->r1) = ctx->r24;
    // 0x800B181C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1820: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x800B1824: nop

    // 0x800B1828: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B182C: b           L_800B1834
    // 0x800B1830: nop

        goto L_800B1834;
    // 0x800B1830: nop

L_800B1834:
    // 0x800B1834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1838: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800B183C: jr          $ra
    // 0x800B1840: nop

    return;
    // 0x800B1840: nop

;}
RECOMP_FUNC void func_800B1844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1844: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800B1848: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B184C: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800B1850: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B1854: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x800B1858: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800B185C: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x800B1860: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x800B1864: nop

    // 0x800B1868: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800B186C: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800B1870: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800B1874: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800B1878: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800B187C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800B1880: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800B1884: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800B1888: nop

    // 0x800B188C: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800B1890: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800B1894: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800B1898: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800B189C: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800B18A0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800B18A4: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800B18A8: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800B18AC: nop

    // 0x800B18B0: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800B18B4: b           L_800B18BC
    // 0x800B18B8: nop

        goto L_800B18BC;
    // 0x800B18B8: nop

L_800B18BC:
    // 0x800B18BC: jr          $ra
    // 0x800B18C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800B18C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800B18C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B18C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B18C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B18CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B18D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800B18D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B18D8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800B18DC: addiu       $t7, $t7, -0x7330
    ctx->r15 = ADD32(ctx->r15, -0X7330);
    // 0x800B18E0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800B18E4: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800B18E8: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800B18EC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800B18F0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800B18F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800B18F8: nop

    // 0x800B18FC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B1900: nop

    // 0x800B1904: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800B1908: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800B190C: lhu         $t2, -0x778($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X778);
    // 0x800B1910: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800B1914: lw          $t4, -0x77C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X77C);
    // 0x800B1918: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x800B191C: jal         0x800C2AE8
    // 0x800B1920: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_0;
    // 0x800B1920: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x800B1924: jal         0x800C1850
    // 0x800B1928: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_1;
    // 0x800B1928: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800B192C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1930: nop

    // 0x800B1934: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x800B1938: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800B193C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800B1940: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x800B1944: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800B1948: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B194C: addu        $t9, $sp, $t7
    ctx->r25 = ADD32(ctx->r29, ctx->r15);
    // 0x800B1950: lh          $t9, 0x24($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X24);
    // 0x800B1954: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800B1958: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800B195C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800B1960: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800B1964: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x800B1968: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800B196C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800B1970: lhu         $t5, -0x778($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X778);
    // 0x800B1974: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B1978: lw          $t6, -0x77C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77C);
    // 0x800B197C: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800B1980: sll         $t8, $t5, 6
    ctx->r24 = S32(ctx->r13 << 6);
    // 0x800B1984: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B1988: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B198C: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800B1990: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800B1994: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B1998: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800B199C: lhu         $t1, -0x778($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X778);
    // 0x800B19A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B19A4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B19A8: sh          $t2, -0x778($at)
    MEM_H(-0X778, ctx->r1) = ctx->r10;
    // 0x800B19AC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B19B0: nop

    // 0x800B19B4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800B19B8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800B19BC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800B19C0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B19C4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800B19C8: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800B19CC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B19D0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800B19D4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B19D8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B19DC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800B19E0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800B19E4: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x800B19E8: nop

    // 0x800B19EC: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800B19F0: beq         $at, $zero, L_800B1A24
    if (ctx->r1 == 0) {
        // 0x800B19F4: nop

            goto L_800B1A24;
    }
    // 0x800B19F4: nop

    // 0x800B19F8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B19FC: nop

    // 0x800B1A00: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800B1A04: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800B1A08: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800B1A0C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B1A10: lui         $t3, 0xBD00
    ctx->r11 = S32(0XBD00 << 16);
    // 0x800B1A14: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800B1A18: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800B1A1C: nop

    // 0x800B1A20: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
L_800B1A24:
    // 0x800B1A24: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1A28: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B1A2C: nop

    // 0x800B1A30: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800B1A34: b           L_800B1A3C
    // 0x800B1A38: nop

        goto L_800B1A3C;
    // 0x800B1A38: nop

L_800B1A3C:
    // 0x800B1A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1A40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B1A44: jr          $ra
    // 0x800B1A48: nop

    return;
    // 0x800B1A48: nop

;}
RECOMP_FUNC void func_800B1A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1A4C: nop

;}
RECOMP_FUNC void func_800B1A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1A50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A54: sw          $a0, 0xD30($at)
    MEM_W(0XD30, ctx->r1) = ctx->r4;
    // 0x800B1A58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A5C: sw          $a1, 0xD34($at)
    MEM_W(0XD34, ctx->r1) = ctx->r5;
    // 0x800B1A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A64: sw          $a2, 0xD38($at)
    MEM_W(0XD38, ctx->r1) = ctx->r6;
    // 0x800B1A68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A6C: sw          $a3, 0xD3C($at)
    MEM_W(0XD3C, ctx->r1) = ctx->r7;
    // 0x800B1A70: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800B1A74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A78: sw          $t6, 0xD40($at)
    MEM_W(0XD40, ctx->r1) = ctx->r14;
    // 0x800B1A7C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800B1A80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A84: sw          $t7, 0xD44($at)
    MEM_W(0XD44, ctx->r1) = ctx->r15;
    // 0x800B1A88: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B1A8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A90: sw          $t8, 0xD48($at)
    MEM_W(0XD48, ctx->r1) = ctx->r24;
    // 0x800B1A94: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1A98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1A9C: sw          $t9, 0xD4C($at)
    MEM_W(0XD4C, ctx->r1) = ctx->r25;
    // 0x800B1AA0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B1AA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AA8: sw          $t0, 0xD50($at)
    MEM_W(0XD50, ctx->r1) = ctx->r8;
    // 0x800B1AAC: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x800B1AB0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AB4: sh          $t1, 0xD54($at)
    MEM_H(0XD54, ctx->r1) = ctx->r9;
    // 0x800B1AB8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800B1ABC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AC0: sw          $t2, 0xD60($at)
    MEM_W(0XD60, ctx->r1) = ctx->r10;
    // 0x800B1AC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AC8: sw          $zero, 0xD64($at)
    MEM_W(0XD64, ctx->r1) = 0;
    // 0x800B1ACC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AD0: sh          $zero, 0xD68($at)
    MEM_H(0XD68, ctx->r1) = 0;
    // 0x800B1AD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AD8: sh          $zero, 0xD6A($at)
    MEM_H(0XD6A, ctx->r1) = 0;
    // 0x800B1ADC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AE0: sh          $zero, 0xD6C($at)
    MEM_H(0XD6C, ctx->r1) = 0;
    // 0x800B1AE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AE8: sb          $zero, 0xD6E($at)
    MEM_B(0XD6E, ctx->r1) = 0;
    // 0x800B1AEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1AF0: sb          $zero, 0xD6F($at)
    MEM_B(0XD6F, ctx->r1) = 0;
    // 0x800B1AF4: jr          $ra
    // 0x800B1AF8: nop

    return;
    // 0x800B1AF8: nop

    // 0x800B1AFC: jr          $ra
    // 0x800B1B00: nop

    return;
    // 0x800B1B00: nop

;}
RECOMP_FUNC void func_800B1B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1B0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1B10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B1B14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B1B18: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1B1C: jal         0x800B1E58
    // 0x800B1B20: nop

    func_800B1E58(rdram, ctx);
        goto after_0;
    // 0x800B1B20: nop

    after_0:
    // 0x800B1B24: b           L_800B1B2C
    // 0x800B1B28: nop

        goto L_800B1B2C;
    // 0x800B1B28: nop

L_800B1B2C:
    // 0x800B1B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1B34: jr          $ra
    // 0x800B1B38: nop

    return;
    // 0x800B1B38: nop

;}
RECOMP_FUNC void func_800B1B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1B48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B1B4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B1B50: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B1B54: nop

    // 0x800B1B58: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B1B5C: bltz        $t7, L_800B1BB0
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B1B60: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_800B1BB0;
    }
    // 0x800B1B60: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800B1B64:
    // 0x800B1B64: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B1B68: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B1B6C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B1B70: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1B74: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1B78: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B1B7C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B1B80: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B1B84: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1B88: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800B1B8C: sll         $t4, $t0, 6
    ctx->r12 = S32(ctx->r8 << 6);
    // 0x800B1B90: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x800B1B94: jal         0x800B1E58
    // 0x800B1B98: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    func_800B1E58(rdram, ctx);
        goto after_0;
    // 0x800B1B98: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x800B1B9C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800B1BA0: nop

    // 0x800B1BA4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B1BA8: bgez        $t6, L_800B1B64
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B1BAC: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_800B1B64;
    }
    // 0x800B1BAC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_800B1BB0:
    // 0x800B1BB0: b           L_800B1BB8
    // 0x800B1BB4: nop

        goto L_800B1BB8;
    // 0x800B1BB4: nop

L_800B1BB8:
    // 0x800B1BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1BC0: jr          $ra
    // 0x800B1BC4: nop

    return;
    // 0x800B1BC4: nop

;}
RECOMP_FUNC void func_800B1BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B1BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1BD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B1BD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B1BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B1BDC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1BE0: jal         0x800B1CD4
    // 0x800B1BE4: nop

    func_800B1CD4(rdram, ctx);
        goto after_0;
    // 0x800B1BE4: nop

    after_0:
    // 0x800B1BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B1BEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1BF0: jal         0x800B1E58
    // 0x800B1BF4: nop

    func_800B1E58(rdram, ctx);
        goto after_1;
    // 0x800B1BF4: nop

    after_1:
    // 0x800B1BF8: b           L_800B1C00
    // 0x800B1BFC: nop

        goto L_800B1C00;
    // 0x800B1BFC: nop

L_800B1C00:
    // 0x800B1C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B1C08: jr          $ra
    // 0x800B1C0C: nop

    return;
    // 0x800B1C0C: nop

;}
RECOMP_FUNC void func_800B1C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1C10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B1C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1C18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B1C1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B1C20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B1C24: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B1C28: nop

    // 0x800B1C2C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B1C30: bltz        $t7, L_800B1CBC
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B1C34: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_800B1CBC;
    }
    // 0x800B1C34: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_800B1C38:
    // 0x800B1C38: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1C3C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B1C40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B1C44: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B1C48: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1C4C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B1C50: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B1C54: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B1C58: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1C5C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800B1C60: sll         $t4, $t0, 6
    ctx->r12 = S32(ctx->r8 << 6);
    // 0x800B1C64: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x800B1C68: jal         0x800B1CD4
    // 0x800B1C6C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    func_800B1CD4(rdram, ctx);
        goto after_0;
    // 0x800B1C6C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x800B1C70: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800B1C74: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800B1C78: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B1C7C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B1C80: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B1C84: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B1C88: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B1C8C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800B1C90: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B1C94: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800B1C98: sll         $t2, $t7, 6
    ctx->r10 = S32(ctx->r15 << 6);
    // 0x800B1C9C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800B1CA0: jal         0x800B1E58
    // 0x800B1CA4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    func_800B1E58(rdram, ctx);
        goto after_1;
    // 0x800B1CA4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800B1CA8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1CAC: nop

    // 0x800B1CB0: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x800B1CB4: bgez        $t3, L_800B1C38
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B1CB8: sw          $t3, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r11;
            goto L_800B1C38;
    }
    // 0x800B1CB8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_800B1CBC:
    // 0x800B1CBC: b           L_800B1CC4
    // 0x800B1CC0: nop

        goto L_800B1CC4;
    // 0x800B1CC0: nop

L_800B1CC4:
    // 0x800B1CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1CC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B1CCC: jr          $ra
    // 0x800B1CD0: nop

    return;
    // 0x800B1CD0: nop

;}
RECOMP_FUNC void func_800B1CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1CD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B1CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1CDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B1CE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B1CE4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B1CE8: nop

    // 0x800B1CEC: beq         $t6, $zero, L_800B1D4C
    if (ctx->r14 == 0) {
        // 0x800B1CF0: nop

            goto L_800B1D4C;
    }
    // 0x800B1CF0: nop

    // 0x800B1CF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B1CF8:
    // 0x800B1CF8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1CFC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B1D00: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B1D04: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B1D08: lw          $t1, 0x12C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X12C);
    // 0x800B1D0C: nop

    // 0x800B1D10: beq         $t1, $zero, L_800B1D34
    if (ctx->r9 == 0) {
        // 0x800B1D14: nop

            goto L_800B1D34;
    }
    // 0x800B1D14: nop

    // 0x800B1D18: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D1C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800B1D20: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B1D24: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800B1D28: lw          $a0, 0x12C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X12C);
    // 0x800B1D2C: jal         0x800BC980
    // 0x800B1D30: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800B1D30: nop

    after_0:
L_800B1D34:
    // 0x800B1D34: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D38: nop

    // 0x800B1D3C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800B1D40: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800B1D44: bne         $at, $zero, L_800B1CF8
    if (ctx->r1 != 0) {
        // 0x800B1D48: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800B1CF8;
    }
    // 0x800B1D48: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_800B1D4C:
    // 0x800B1D4C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B1D50: nop

    // 0x800B1D54: bne         $t7, $zero, L_800B1D64
    if (ctx->r15 != 0) {
        // 0x800B1D58: nop

            goto L_800B1D64;
    }
    // 0x800B1D58: nop

    // 0x800B1D5C: b           L_800B1E48
    // 0x800B1D60: nop

        goto L_800B1E48;
    // 0x800B1D60: nop

L_800B1D64:
    // 0x800B1D64: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B1D68:
    // 0x800B1D68: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D6C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B1D70: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B1D74: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800B1D78: lw          $t2, 0x14($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X14);
    // 0x800B1D7C: nop

    // 0x800B1D80: beq         $t2, $zero, L_800B1DA4
    if (ctx->r10 == 0) {
        // 0x800B1D84: nop

            goto L_800B1DA4;
    }
    // 0x800B1D84: nop

    // 0x800B1D88: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1D8C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B1D90: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B1D94: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x800B1D98: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x800B1D9C: jal         0x800BC980
    // 0x800B1DA0: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800B1DA0: nop

    after_1:
L_800B1DA4:
    // 0x800B1DA4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1DA8: nop

    // 0x800B1DAC: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800B1DB0: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800B1DB4: bne         $at, $zero, L_800B1D68
    if (ctx->r1 != 0) {
        // 0x800B1DB8: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800B1D68;
    }
    // 0x800B1DB8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B1DBC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B1DC0: nop

    // 0x800B1DC4: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x800B1DC8: nop

    // 0x800B1DCC: beq         $t1, $zero, L_800B1DE8
    if (ctx->r9 == 0) {
        // 0x800B1DD0: nop

            goto L_800B1DE8;
    }
    // 0x800B1DD0: nop

    // 0x800B1DD4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B1DD8: nop

    // 0x800B1DDC: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B1DE0: jal         0x800BC980
    // 0x800B1DE4: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x800B1DE4: nop

    after_2:
L_800B1DE8:
    // 0x800B1DE8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B1DEC: nop

    // 0x800B1DF0: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x800B1DF4: nop

    // 0x800B1DF8: beq         $t5, $zero, L_800B1E14
    if (ctx->r13 == 0) {
        // 0x800B1DFC: nop

            goto L_800B1E14;
    }
    // 0x800B1DFC: nop

    // 0x800B1E00: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B1E04: nop

    // 0x800B1E08: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x800B1E0C: jal         0x800BC980
    // 0x800B1E10: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800B1E10: nop

    after_3:
L_800B1E14:
    // 0x800B1E14: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B1E18: nop

    // 0x800B1E1C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800B1E20: nop

    // 0x800B1E24: beq         $t8, $zero, L_800B1E40
    if (ctx->r24 == 0) {
        // 0x800B1E28: nop

            goto L_800B1E40;
    }
    // 0x800B1E28: nop

    // 0x800B1E2C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B1E30: nop

    // 0x800B1E34: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x800B1E38: jal         0x800BC980
    // 0x800B1E3C: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x800B1E3C: nop

    after_4:
L_800B1E40:
    // 0x800B1E40: b           L_800B1E48
    // 0x800B1E44: nop

        goto L_800B1E48;
    // 0x800B1E44: nop

L_800B1E48:
    // 0x800B1E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B1E50: jr          $ra
    // 0x800B1E54: nop

    return;
    // 0x800B1E54: nop

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
RECOMP_FUNC void func_800B1F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1F0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B1F10: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B1F14: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B1F18: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B1F1C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800B1F20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800B1F24: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B1F28: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F2C: nop

    // 0x800B1F30: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B1F34: nop

    // 0x800B1F38: bne         $t7, $zero, L_800B1F54
    if (ctx->r15 != 0) {
        // 0x800B1F3C: nop

            goto L_800B1F54;
    }
    // 0x800B1F3C: nop

    // 0x800B1F40: jal         0x800BC6EC
    // 0x800B1F44: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800B1F44: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800B1F48: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F4C: nop

    // 0x800B1F50: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
L_800B1F54:
    // 0x800B1F54: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F58: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B1F5C: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800B1F60: jal         0x800B3EC0
    // 0x800B1F64: nop

    func_800B3EC0(rdram, ctx);
        goto after_1;
    // 0x800B1F64: nop

    after_1:
    // 0x800B1F68: beq         $v0, $zero, L_800B1F78
    if (ctx->r2 == 0) {
        // 0x800B1F6C: nop

            goto L_800B1F78;
    }
    // 0x800B1F6C: nop

    // 0x800B1F70: b           L_800B201C
    // 0x800B1F74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B201C;
    // 0x800B1F74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B1F78:
    // 0x800B1F78: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F7C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800B1F80: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800B1F84: lw          $t3, 0xD34($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD34);
    // 0x800B1F88: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800B1F8C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B1F90: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B1F94: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B1F98: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B1F9C: jal         0x800BD1FC
    // 0x800B1FA0: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B1FA0: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x800B1FA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B1FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1FAC: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x800B1FB0: jal         0x800BD218
    // 0x800B1FB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B1FB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x800B1FB8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B1FBC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B1FC0: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x800B1FC4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B1FC8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1FCC: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x800B1FD0: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x800B1FD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B1FD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800B1FDC: jal         0x800B23C4
    // 0x800B1FE0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_800B23C4(rdram, ctx);
        goto after_4;
    // 0x800B1FE0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_4:
    // 0x800B1FE4: beq         $v0, $zero, L_800B200C
    if (ctx->r2 == 0) {
        // 0x800B1FE8: nop

            goto L_800B200C;
    }
    // 0x800B1FE8: nop

    // 0x800B1FEC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1FF0: nop

    // 0x800B1FF4: lhu         $t6, 0x3A($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B1FF8: nop

    // 0x800B1FFC: ori         $t7, $t6, 0x400
    ctx->r15 = ctx->r14 | 0X400;
    // 0x800B2000: sh          $t7, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r15;
    // 0x800B2004: b           L_800B201C
    // 0x800B2008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B201C;
    // 0x800B2008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B200C:
    // 0x800B200C: b           L_800B201C
    // 0x800B2010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B201C;
    // 0x800B2010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B2014: b           L_800B201C
    // 0x800B2018: nop

        goto L_800B201C;
    // 0x800B2018: nop

L_800B201C:
    // 0x800B201C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2020: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B2024: jr          $ra
    // 0x800B2028: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B2028: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B202C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B202C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800B2030: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B2034: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800B2038: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800B203C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800B2040: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800B2044: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B2048: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800B204C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800B2050: nop

    // 0x800B2054: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B2058: nop

    // 0x800B205C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B2060: nop

    // 0x800B2064: bne         $t8, $zero, L_800B2088
    if (ctx->r24 != 0) {
        // 0x800B2068: nop

            goto L_800B2088;
    }
    // 0x800B2068: nop

    // 0x800B206C: jal         0x800BC6EC
    // 0x800B2070: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800B2070: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800B2074: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800B2078: nop

    // 0x800B207C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B2080: nop

    // 0x800B2084: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_800B2088:
    // 0x800B2088: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800B208C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800B2090: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800B2094: nop

    // 0x800B2098: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x800B209C: jal         0x800B3EC0
    // 0x800B20A0: nop

    func_800B3EC0(rdram, ctx);
        goto after_1;
    // 0x800B20A0: nop

    after_1:
    // 0x800B20A4: beq         $v0, $zero, L_800B20B4
    if (ctx->r2 == 0) {
        // 0x800B20A8: nop

            goto L_800B20B4;
    }
    // 0x800B20A8: nop

    // 0x800B20AC: b           L_800B23B4
    // 0x800B20B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B23B4;
    // 0x800B20B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B20B4:
    // 0x800B20B4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800B20B8: nop

    // 0x800B20BC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800B20C0: nop

    // 0x800B20C4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800B20C8: nop

    // 0x800B20CC: lbu         $t6, 0xE($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XE);
    // 0x800B20D0: nop

    // 0x800B20D4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800B20D8: lbu         $t7, 0x7B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X7B);
    // 0x800B20DC: nop

    // 0x800B20E0: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800B20E4: beq         $t8, $zero, L_800B2114
    if (ctx->r24 == 0) {
        // 0x800B20E8: nop

            goto L_800B2114;
    }
    // 0x800B20E8: nop

    // 0x800B20EC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800B20F0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B20F4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B20F8: nop

    // 0x800B20FC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800B2100: nop

    // 0x800B2104: lbu         $t3, 0xF($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XF);
    // 0x800B2108: nop

    // 0x800B210C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800B2110: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_800B2114:
    // 0x800B2114: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800B2118: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B211C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B2120: lw          $t0, 0xD34($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD34);
    // 0x800B2124: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B2128: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B212C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B2130: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B2134: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B2138: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B213C: jal         0x800BD1FC
    // 0x800B2140: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B2140: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_2:
    // 0x800B2144: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2148: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B214C: sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6 << 1);
    // 0x800B2150: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800B2154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B2158: jal         0x800BD218
    // 0x800B215C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B215C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x800B2160: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2164: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B2168: blez        $t2, L_800B2214
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B216C: nop

            goto L_800B2214;
    }
    // 0x800B216C: nop

L_800B2170:
    // 0x800B2170: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B2174: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800B2178: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800B217C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B2180: sll         $t0, $t4, 1
    ctx->r8 = S32(ctx->r12 << 1);
    // 0x800B2184: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x800B2188: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B218C: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x800B2190: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B2194: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B2198: lhu         $a2, 0x40($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X40);
    // 0x800B219C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B21A0: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B21A4: lbu         $t1, 0x7B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7B);
    // 0x800B21A8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B21AC: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800B21B0: lhu         $a3, 0x6E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X6E);
    // 0x800B21B4: sll         $t8, $t4, 6
    ctx->r24 = S32(ctx->r12 << 6);
    // 0x800B21B8: addu        $a0, $t3, $t5
    ctx->r4 = ADD32(ctx->r11, ctx->r13);
    // 0x800B21BC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800B21C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B21C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800B21C8: jal         0x800B23C4
    // 0x800B21CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_800B23C4(rdram, ctx);
        goto after_4;
    // 0x800B21CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_4:
    // 0x800B21D0: beq         $v0, $zero, L_800B21FC
    if (ctx->r2 == 0) {
        // 0x800B21D4: nop

            goto L_800B21FC;
    }
    // 0x800B21D4: nop

    // 0x800B21D8: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800B21DC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B21E0: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800B21E4: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x800B21E8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800B21EC: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B21F0: nop

    // 0x800B21F4: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x800B21F8: sh          $t8, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r24;
L_800B21FC:
    // 0x800B21FC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B2200: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2204: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x800B2208: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B220C: bne         $at, $zero, L_800B2170
    if (ctx->r1 != 0) {
        // 0x800B2210: sw          $t0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r8;
            goto L_800B2170;
    }
    // 0x800B2210: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_800B2214:
    // 0x800B2214: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2218: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B221C: blez        $t2, L_800B226C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B2220: nop

            goto L_800B226C;
    }
    // 0x800B2220: nop

L_800B2224:
    // 0x800B2224: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800B2228: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B222C: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800B2230: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x800B2234: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800B2238: lhu         $t6, 0x3A($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X3A);
    // 0x800B223C: nop

    // 0x800B2240: andi        $t4, $t6, 0x400
    ctx->r12 = ctx->r14 & 0X400;
    // 0x800B2244: bne         $t4, $zero, L_800B2254
    if (ctx->r12 != 0) {
        // 0x800B2248: nop

            goto L_800B2254;
    }
    // 0x800B2248: nop

    // 0x800B224C: b           L_800B226C
    // 0x800B2250: nop

        goto L_800B226C;
    // 0x800B2250: nop

L_800B2254:
    // 0x800B2254: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800B2258: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B225C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B2260: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B2264: bne         $at, $zero, L_800B2224
    if (ctx->r1 != 0) {
        // 0x800B2268: sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
            goto L_800B2224;
    }
    // 0x800B2268: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
L_800B226C:
    // 0x800B226C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B2270: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2274: nop

    // 0x800B2278: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B227C: bne         $at, $zero, L_800B228C
    if (ctx->r1 != 0) {
        // 0x800B2280: nop

            goto L_800B228C;
    }
    // 0x800B2280: nop

    // 0x800B2284: b           L_800B23B4
    // 0x800B2288: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B23B4;
    // 0x800B2288: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B228C:
    // 0x800B228C: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800B2290: nop

    // 0x800B2294: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B2298: nop

    // 0x800B229C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800B22A0: nop

    // 0x800B22A4: andi        $t6, $t8, 0x4
    ctx->r14 = ctx->r24 & 0X4;
    // 0x800B22A8: beq         $t6, $zero, L_800B231C
    if (ctx->r14 == 0) {
        // 0x800B22AC: nop

            goto L_800B231C;
    }
    // 0x800B22AC: nop

    // 0x800B22B0: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800B22B4: nop

    // 0x800B22B8: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x800B22BC: nop

    // 0x800B22C0: lhu         $t1, 0x3A($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X3A);
    // 0x800B22C4: nop

    // 0x800B22C8: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x800B22CC: beq         $t2, $zero, L_800B231C
    if (ctx->r10 == 0) {
        // 0x800B22D0: nop

            goto L_800B231C;
    }
    // 0x800B22D0: nop

    // 0x800B22D4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800B22D8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800B22DC: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800B22E0: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x800B22E4: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x800B22E8: nop

    // 0x800B22EC: lbu         $t7, 0xE($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XE);
    // 0x800B22F0: nop

    // 0x800B22F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B22F8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B22FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2300: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B2304: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800B2308: addu        $t0, $t8, $t4
    ctx->r8 = ADD32(ctx->r24, ctx->r12);
    // 0x800B230C: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x800B2310: nop

    // 0x800B2314: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x800B2318: sw          $t2, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r10;
L_800B231C:
    // 0x800B231C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2320: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B2324: blez        $t3, L_800B23A0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B2328: nop

            goto L_800B23A0;
    }
    // 0x800B2328: nop

L_800B232C:
    // 0x800B232C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800B2330: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800B2334: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800B2338: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x800B233C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800B2340: lhu         $t4, 0x3A($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X3A);
    // 0x800B2344: nop

    // 0x800B2348: andi        $t1, $t4, 0x400
    ctx->r9 = ctx->r12 & 0X400;
    // 0x800B234C: beq         $t1, $zero, L_800B2388
    if (ctx->r9 == 0) {
        // 0x800B2350: nop

            goto L_800B2388;
    }
    // 0x800B2350: nop

    // 0x800B2354: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800B2358: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800B235C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800B2360: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x800B2364: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B2368: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x800B236C: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x800B2370: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800B2374: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x800B2378: lw          $t9, 0xC0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC0);
    // 0x800B237C: nop

    // 0x800B2380: ori         $t6, $t9, 0x80
    ctx->r14 = ctx->r25 | 0X80;
    // 0x800B2384: sw          $t6, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r14;
L_800B2388:
    // 0x800B2388: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B238C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2390: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x800B2394: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B2398: bne         $at, $zero, L_800B232C
    if (ctx->r1 != 0) {
        // 0x800B239C: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_800B232C;
    }
    // 0x800B239C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_800B23A0:
    // 0x800B23A0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800B23A4: b           L_800B23B4
    // 0x800B23A8: nop

        goto L_800B23B4;
    // 0x800B23A8: nop

    // 0x800B23AC: b           L_800B23B4
    // 0x800B23B0: nop

        goto L_800B23B4;
    // 0x800B23B0: nop

L_800B23B4:
    // 0x800B23B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B23B8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B23BC: jr          $ra
    // 0x800B23C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800B23C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800B23C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B23C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B23C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B23CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B23D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B23D4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B23D8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800B23DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B23E0: lbu         $t6, 0x43($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X43);
    // 0x800B23E4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B23E8: nop

    // 0x800B23EC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800B23F0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B23F4: nop

    // 0x800B23F8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800B23FC: nop

    // 0x800B2400: bne         $t9, $zero, L_800B241C
    if (ctx->r25 != 0) {
        // 0x800B2404: nop

            goto L_800B241C;
    }
    // 0x800B2404: nop

    // 0x800B2408: jal         0x800BC6EC
    // 0x800B240C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800B240C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x800B2410: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2414: nop

    // 0x800B2418: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
L_800B241C:
    // 0x800B241C: lhu         $t1, 0x32($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X32);
    // 0x800B2420: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800B2424: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B2428: lw          $t3, 0xD38($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD38);
    // 0x800B242C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B2430: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B2434: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B2438: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B243C: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B2440: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B2444: jal         0x800BD1FC
    // 0x800B2448: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x800B2448: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x800B244C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2450: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B2454: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x800B2458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B245C: jal         0x800BD218
    // 0x800B2460: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800B2460: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_2:
    // 0x800B2464: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2468: nop

    // 0x800B246C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800B2470: nop

    // 0x800B2474: bne         $t6, $zero, L_800B2490
    if (ctx->r14 != 0) {
        // 0x800B2478: nop

            goto L_800B2490;
    }
    // 0x800B2478: nop

    // 0x800B247C: jal         0x800BC6EC
    // 0x800B2480: addiu       $a0, $zero, 0x380
    ctx->r4 = ADD32(0, 0X380);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800B2480: addiu       $a0, $zero, 0x380
    ctx->r4 = ADD32(0, 0X380);
    after_3:
    // 0x800B2484: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2488: nop

    // 0x800B248C: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
L_800B2490:
    // 0x800B2490: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2494: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B2498: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800B249C: lw          $t1, 0xD3C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD3C);
    // 0x800B24A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B24A4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B24A8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B24AC: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B24B0: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B24B4: jal         0x800BD1FC
    // 0x800B24B8: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x800B24B8: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    after_4:
    // 0x800B24BC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B24C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B24C4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800B24C8: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x800B24CC: lbu         $a2, 0x10($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X10);
    // 0x800B24D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B24D4: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x800B24D8: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x800B24DC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800B24E0: jal         0x800BD218
    // 0x800B24E4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x800B24E4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_5:
    // 0x800B24E8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B24EC: nop

    // 0x800B24F0: sb          $zero, 0x30($t5)
    MEM_B(0X30, ctx->r13) = 0;
    // 0x800B24F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B24F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B24FC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800B2500: lwc1        $f9, -0x6C0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X6C0);
    // 0x800B2504: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x800B2508: lwc1        $f8, -0x6BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6BC);
    // 0x800B250C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B2510: nop

    // 0x800B2514: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800B2518: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800B251C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800B2520: swc1        $f16, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f16.u32l;
    // 0x800B2524: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2528: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B252C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800B2530: lwc1        $f7, -0x6B8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X6B8);
    // 0x800B2534: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x800B2538: lwc1        $f6, -0x6B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6B4);
    // 0x800B253C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800B2540: nop

    // 0x800B2544: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800B2548: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800B254C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B2550: swc1        $f10, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f10.u32l;
    // 0x800B2554: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2558: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B255C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800B2560: lwc1        $f5, -0x6B0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X6B0);
    // 0x800B2564: lh          $t4, 0x8($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X8);
    // 0x800B2568: lwc1        $f4, -0x6AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6AC);
    // 0x800B256C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800B2570: nop

    // 0x800B2574: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800B2578: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800B257C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B2580: swc1        $f8, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f8.u32l;
    // 0x800B2584: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2588: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B258C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x800B2590: lwc1        $f19, -0x6A8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X6A8);
    // 0x800B2594: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x800B2598: lwc1        $f18, -0x6A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6A4);
    // 0x800B259C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800B25A0: nop

    // 0x800B25A4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800B25A8: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B25AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800B25B0: swc1        $f6, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->f6.u32l;
    // 0x800B25B4: lbu         $t6, 0x43($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X43);
    // 0x800B25B8: nop

    // 0x800B25BC: andi        $t0, $t6, 0x1
    ctx->r8 = ctx->r14 & 0X1;
    // 0x800B25C0: beq         $t0, $zero, L_800B25F8
    if (ctx->r8 == 0) {
        // 0x800B25C4: nop

            goto L_800B25F8;
    }
    // 0x800B25C4: nop

    // 0x800B25C8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B25CC: nop

    // 0x800B25D0: lwc1        $f8, 0x20($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800B25D4: nop

    // 0x800B25D8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B25DC: swc1        $f10, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f10.u32l;
    // 0x800B25E0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B25E4: nop

    // 0x800B25E8: lwc1        $f16, 0x28($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X28);
    // 0x800B25EC: nop

    // 0x800B25F0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B25F4: swc1        $f18, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f18.u32l;
L_800B25F8:
    // 0x800B25F8: lbu         $t3, 0x43($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X43);
    // 0x800B25FC: nop

    // 0x800B2600: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x800B2604: beq         $t4, $zero, L_800B263C
    if (ctx->r12 == 0) {
        // 0x800B2608: nop

            goto L_800B263C;
    }
    // 0x800B2608: nop

    // 0x800B260C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2610: nop

    // 0x800B2614: lwc1        $f4, 0x24($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X24);
    // 0x800B2618: nop

    // 0x800B261C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B2620: swc1        $f6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f6.u32l;
    // 0x800B2624: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2628: nop

    // 0x800B262C: lwc1        $f8, 0x2C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x800B2630: nop

    // 0x800B2634: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B2638: swc1        $f10, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f10.u32l;
L_800B263C:
    // 0x800B263C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B2640: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2644: nop

    // 0x800B2648: swc1        $f16, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f16.u32l;
    // 0x800B264C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2650: nop

    // 0x800B2654: sb          $zero, 0x38($t5)
    MEM_B(0X38, ctx->r13) = 0;
    // 0x800B2658: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B265C: nop

    // 0x800B2660: sh          $zero, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = 0;
    // 0x800B2664: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B2668: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B266C: nop

    // 0x800B2670: swc1        $f18, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f18.u32l;
    // 0x800B2674: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B2678: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B267C: nop

    // 0x800B2680: swc1        $f4, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f4.u32l;
    // 0x800B2684: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800B2688: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800B268C: lw          $t3, 0xC0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XC0);
    // 0x800B2690: nop

    // 0x800B2694: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800B2698: sw          $t4, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r12;
    // 0x800B269C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B26A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800B26A4: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x800B26A8: jal         0x800B407C
    // 0x800B26AC: nop

    func_800B407C(rdram, ctx);
        goto after_6;
    // 0x800B26AC: nop

    after_6:
    // 0x800B26B0: beq         $v0, $zero, L_800B26C0
    if (ctx->r2 == 0) {
        // 0x800B26B4: nop

            goto L_800B26C0;
    }
    // 0x800B26B4: nop

    // 0x800B26B8: b           L_800B26D0
    // 0x800B26BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B26D0;
    // 0x800B26BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B26C0:
    // 0x800B26C0: b           L_800B26D0
    // 0x800B26C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B26D0;
    // 0x800B26C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B26C8: b           L_800B26D0
    // 0x800B26CC: nop

        goto L_800B26D0;
    // 0x800B26CC: nop

L_800B26D0:
    // 0x800B26D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B26D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B26D8: jr          $ra
    // 0x800B26DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B26DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800B26E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B26E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B26E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B26E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B26EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B26F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B26F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B26F8: jal         0x800B2A34
    // 0x800B26FC: nop

    func_800B2A34(rdram, ctx);
        goto after_0;
    // 0x800B26FC: nop

    after_0:
    // 0x800B2700: beq         $v0, $zero, L_800B2728
    if (ctx->r2 == 0) {
        // 0x800B2704: nop

            goto L_800B2728;
    }
    // 0x800B2704: nop

    // 0x800B2708: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B270C: nop

    // 0x800B2710: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B2714: nop

    // 0x800B2718: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x800B271C: sh          $t8, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r24;
    // 0x800B2720: b           L_800B2738
    // 0x800B2724: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2738;
    // 0x800B2724: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B2728:
    // 0x800B2728: b           L_800B2738
    // 0x800B272C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B2738;
    // 0x800B272C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B2730: b           L_800B2738
    // 0x800B2734: nop

        goto L_800B2738;
    // 0x800B2734: nop

L_800B2738:
    // 0x800B2738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B273C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2740: jr          $ra
    // 0x800B2744: nop

    return;
    // 0x800B2744: nop

;}
RECOMP_FUNC void func_800B2748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B274C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2750: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B2754: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B2758: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B275C: nop

    // 0x800B2760: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B2764: nop

    // 0x800B2768: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800B276C: nop

    // 0x800B2770: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x800B2774: nop

    // 0x800B2778: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800B277C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B2780: nop

    // 0x800B2784: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800B2788: nop

    // 0x800B278C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800B2790: nop

    // 0x800B2794: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800B2798: beq         $t3, $zero, L_800B27C8
    if (ctx->r11 == 0) {
        // 0x800B279C: nop

            goto L_800B27C8;
    }
    // 0x800B279C: nop

    // 0x800B27A0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B27A4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B27A8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B27AC: nop

    // 0x800B27B0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800B27B4: nop

    // 0x800B27B8: lbu         $t8, 0xF($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF);
    // 0x800B27BC: nop

    // 0x800B27C0: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800B27C4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_800B27C8:
    // 0x800B27C8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B27CC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B27D0: blez        $t0, L_800B2884
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B27D4: nop

            goto L_800B2884;
    }
    // 0x800B27D4: nop

L_800B27D8:
    // 0x800B27D8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B27DC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B27E0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800B27E4: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x800B27E8: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800B27EC: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B27F0: nop

    // 0x800B27F4: andi        $t4, $t7, 0x400
    ctx->r12 = ctx->r15 & 0X400;
    // 0x800B27F8: beq         $t4, $zero, L_800B2808
    if (ctx->r12 == 0) {
        // 0x800B27FC: nop

            goto L_800B2808;
    }
    // 0x800B27FC: nop

    // 0x800B2800: b           L_800B286C
    // 0x800B2804: nop

        goto L_800B286C;
    // 0x800B2804: nop

L_800B2808:
    // 0x800B2808: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B280C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B2810: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B2814: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B2818: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B281C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B2820: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B2824: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x800B2828: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B282C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800B2830: sll         $t5, $t0, 6
    ctx->r13 = S32(ctx->r8 << 6);
    // 0x800B2834: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x800B2838: jal         0x800B2A34
    // 0x800B283C: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    func_800B2A34(rdram, ctx);
        goto after_0;
    // 0x800B283C: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    after_0:
    // 0x800B2840: beq         $v0, $zero, L_800B286C
    if (ctx->r2 == 0) {
        // 0x800B2844: nop

            goto L_800B286C;
    }
    // 0x800B2844: nop

    // 0x800B2848: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B284C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B2850: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B2854: sll         $t8, $t4, 6
    ctx->r24 = S32(ctx->r12 << 6);
    // 0x800B2858: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B285C: lhu         $t1, 0x3A($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X3A);
    // 0x800B2860: nop

    // 0x800B2864: ori         $t3, $t1, 0x400
    ctx->r11 = ctx->r9 | 0X400;
    // 0x800B2868: sh          $t3, 0x3A($t9)
    MEM_H(0X3A, ctx->r25) = ctx->r11;
L_800B286C:
    // 0x800B286C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B2870: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2874: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800B2878: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B287C: bne         $at, $zero, L_800B27D8
    if (ctx->r1 != 0) {
        // 0x800B2880: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_800B27D8;
    }
    // 0x800B2880: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800B2884:
    // 0x800B2884: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2888: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B288C: blez        $t6, L_800B28DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B2890: nop

            goto L_800B28DC;
    }
    // 0x800B2890: nop

L_800B2894:
    // 0x800B2894: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B2898: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B289C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800B28A0: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x800B28A4: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800B28A8: lhu         $t9, 0x3A($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B28AC: nop

    // 0x800B28B0: andi        $t0, $t9, 0x400
    ctx->r8 = ctx->r25 & 0X400;
    // 0x800B28B4: bne         $t0, $zero, L_800B28C4
    if (ctx->r8 != 0) {
        // 0x800B28B8: nop

            goto L_800B28C4;
    }
    // 0x800B28B8: nop

    // 0x800B28BC: b           L_800B28DC
    // 0x800B28C0: nop

        goto L_800B28DC;
    // 0x800B28C0: nop

L_800B28C4:
    // 0x800B28C4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800B28C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B28CC: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x800B28D0: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B28D4: bne         $at, $zero, L_800B2894
    if (ctx->r1 != 0) {
        // 0x800B28D8: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_800B2894;
    }
    // 0x800B28D8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
L_800B28DC:
    // 0x800B28DC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B28E0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B28E4: nop

    // 0x800B28E8: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B28EC: bne         $at, $zero, L_800B28FC
    if (ctx->r1 != 0) {
        // 0x800B28F0: nop

            goto L_800B28FC;
    }
    // 0x800B28F0: nop

    // 0x800B28F4: b           L_800B2A24
    // 0x800B28F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2A24;
    // 0x800B28F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B28FC:
    // 0x800B28FC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B2900: nop

    // 0x800B2904: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x800B2908: nop

    // 0x800B290C: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x800B2910: nop

    // 0x800B2914: andi        $t9, $t3, 0x4
    ctx->r25 = ctx->r11 & 0X4;
    // 0x800B2918: beq         $t9, $zero, L_800B298C
    if (ctx->r25 == 0) {
        // 0x800B291C: nop

            goto L_800B298C;
    }
    // 0x800B291C: nop

    // 0x800B2920: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B2924: nop

    // 0x800B2928: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B292C: nop

    // 0x800B2930: lhu         $t5, 0x3A($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X3A);
    // 0x800B2934: nop

    // 0x800B2938: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x800B293C: beq         $t6, $zero, L_800B298C
    if (ctx->r14 == 0) {
        // 0x800B2940: nop

            goto L_800B298C;
    }
    // 0x800B2940: nop

    // 0x800B2944: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B2948: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B294C: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800B2950: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B2954: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x800B2958: nop

    // 0x800B295C: lbu         $t1, 0xE($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0XE);
    // 0x800B2960: nop

    // 0x800B2964: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800B2968: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800B296C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B2970: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800B2974: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800B2978: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x800B297C: lw          $t5, 0xC0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC0);
    // 0x800B2980: nop

    // 0x800B2984: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x800B2988: sw          $t6, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r14;
L_800B298C:
    // 0x800B298C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2990: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B2994: blez        $t4, L_800B2A10
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B2998: nop

            goto L_800B2A10;
    }
    // 0x800B2998: nop

L_800B299C:
    // 0x800B299C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B29A0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800B29A4: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800B29A8: sll         $t9, $t1, 6
    ctx->r25 = S32(ctx->r9 << 6);
    // 0x800B29AC: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x800B29B0: lhu         $t0, 0x3A($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X3A);
    // 0x800B29B4: nop

    // 0x800B29B8: andi        $t5, $t0, 0x400
    ctx->r13 = ctx->r8 & 0X400;
    // 0x800B29BC: beq         $t5, $zero, L_800B29F8
    if (ctx->r13 == 0) {
        // 0x800B29C0: nop

            goto L_800B29F8;
    }
    // 0x800B29C0: nop

    // 0x800B29C4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B29C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B29CC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800B29D0: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x800B29D4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B29D8: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x800B29DC: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x800B29E0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800B29E4: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800B29E8: lw          $t7, 0xC0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XC0);
    // 0x800B29EC: nop

    // 0x800B29F0: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x800B29F4: sw          $t9, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r25;
L_800B29F8:
    // 0x800B29F8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B29FC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2A00: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x800B2A04: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B2A08: bne         $at, $zero, L_800B299C
    if (ctx->r1 != 0) {
        // 0x800B2A0C: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_800B299C;
    }
    // 0x800B2A0C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800B2A10:
    // 0x800B2A10: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2A14: b           L_800B2A24
    // 0x800B2A18: nop

        goto L_800B2A24;
    // 0x800B2A18: nop

    // 0x800B2A1C: b           L_800B2A24
    // 0x800B2A20: nop

        goto L_800B2A24;
    // 0x800B2A20: nop

L_800B2A24:
    // 0x800B2A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B2A2C: jr          $ra
    // 0x800B2A30: nop

    return;
    // 0x800B2A30: nop

;}
RECOMP_FUNC void func_800B2A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B2A40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B2A44: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2A48: nop

    // 0x800B2A4C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800B2A50: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x800B2A54: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x800B2A58: nop

    // 0x800B2A5C: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B2A60: bne         $at, $zero, L_800B2A70
    if (ctx->r1 != 0) {
        // 0x800B2A64: nop

            goto L_800B2A70;
    }
    // 0x800B2A64: nop

    // 0x800B2A68: b           L_800B2C3C
    // 0x800B2A6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2C3C;
    // 0x800B2A6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B2A70:
    // 0x800B2A70: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2A74: nop

    // 0x800B2A78: lhu         $t1, 0x3A($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X3A);
    // 0x800B2A7C: nop

    // 0x800B2A80: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x800B2A84: beq         $t2, $zero, L_800B2A94
    if (ctx->r10 == 0) {
        // 0x800B2A88: nop

            goto L_800B2A94;
    }
    // 0x800B2A88: nop

    // 0x800B2A8C: b           L_800B2C3C
    // 0x800B2A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B2C3C;
    // 0x800B2A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2A94:
    // 0x800B2A94: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2A98: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800B2A9C: lwc1        $f4, 0x34($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X34);
    // 0x800B2AA0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B2AA4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B2AA8: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800B2AAC: nop

    // 0x800B2AB0: bc1f        L_800B2BA4
    if (!c1cs) {
        // 0x800B2AB4: nop

            goto L_800B2BA4;
    }
    // 0x800B2AB4: nop

    // 0x800B2AB8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2ABC: nop

    // 0x800B2AC0: lhu         $t5, 0x3A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X3A);
    // 0x800B2AC4: nop

    // 0x800B2AC8: andi        $t6, $t5, 0x8F
    ctx->r14 = ctx->r13 & 0X8F;
    // 0x800B2ACC: bne         $t6, $zero, L_800B2B58
    if (ctx->r14 != 0) {
        // 0x800B2AD0: nop

            goto L_800B2B58;
    }
    // 0x800B2AD0: nop

    // 0x800B2AD4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2AD8: nop

    // 0x800B2ADC: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800B2AE0: nop

    // 0x800B2AE4: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800B2AE8: beq         $t9, $zero, L_800B2B18
    if (ctx->r25 == 0) {
        // 0x800B2AEC: nop

            goto L_800B2B18;
    }
    // 0x800B2AEC: nop

    // 0x800B2AF0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2AF4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B2AF8: lwc1        $f10, 0x34($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X34);
    // 0x800B2AFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B2B00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B2B04: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800B2B08: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x800B2B0C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800B2B10: b           L_800B2B58
    // 0x800B2B14: swc1        $f6, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f6.u32l;
        goto L_800B2B58;
    // 0x800B2B14: swc1        $f6, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f6.u32l;
L_800B2B18:
    // 0x800B2B18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B2B1C: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800B2B20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B2B24: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800B2B28: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B2B2C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B2B30: nop

    // 0x800B2B34: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x800B2B38: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2B3C: nop

    // 0x800B2B40: lwc1        $f4, 0x34($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X34);
    // 0x800B2B44: nop

    // 0x800B2B48: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B2B4C: sub.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = ctx->f6.d - ctx->f18.d;
    // 0x800B2B50: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B2B54: swc1        $f10, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f10.u32l;
L_800B2B58:
    // 0x800B2B58: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2B5C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800B2B60: lwc1        $f16, 0x34($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800B2B64: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B2B68: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800B2B6C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800B2B70: nop

    // 0x800B2B74: bc1f        L_800B2BA4
    if (!c1cs) {
        // 0x800B2B78: nop

            goto L_800B2BA4;
    }
    // 0x800B2B78: nop

    // 0x800B2B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B2B80: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2B84: jal         0x800B4AB4
    // 0x800B2B88: nop

    func_800B4AB4(rdram, ctx);
        goto after_0;
    // 0x800B2B88: nop

    after_0:
    // 0x800B2B8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B2B90: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2B94: jal         0x800B5558
    // 0x800B2B98: nop

    func_800B5558(rdram, ctx);
        goto after_1;
    // 0x800B2B98: nop

    after_1:
    // 0x800B2B9C: b           L_800B2C3C
    // 0x800B2BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B2C3C;
    // 0x800B2BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2BA4:
    // 0x800B2BA4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2BA8: nop

    // 0x800B2BAC: lbu         $t4, 0x30($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X30);
    // 0x800B2BB0: nop

    // 0x800B2BB4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B2BB8: sb          $t5, 0x30($t3)
    MEM_B(0X30, ctx->r11) = ctx->r13;
    // 0x800B2BBC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2BC0: nop

    // 0x800B2BC4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800B2BC8: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x800B2BCC: lbu         $t9, 0x10($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X10);
    // 0x800B2BD0: nop

    // 0x800B2BD4: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B2BD8: bne         $at, $zero, L_800B2C08
    if (ctx->r1 != 0) {
        // 0x800B2BDC: nop

            goto L_800B2C08;
    }
    // 0x800B2BDC: nop

    // 0x800B2BE0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2BE4: nop

    // 0x800B2BE8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800B2BEC: nop

    // 0x800B2BF0: lbu         $t2, 0x10($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X10);
    // 0x800B2BF4: nop

    // 0x800B2BF8: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x800B2BFC: sb          $t4, 0x30($t0)
    MEM_B(0X30, ctx->r8) = ctx->r12;
    // 0x800B2C00: b           L_800B2C3C
    // 0x800B2C04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2C3C;
    // 0x800B2C04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B2C08:
    // 0x800B2C08: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B2C10: lhu         $a2, 0x12($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X12);
    // 0x800B2C14: jal         0x800B407C
    // 0x800B2C18: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    func_800B407C(rdram, ctx);
        goto after_2;
    // 0x800B2C18: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_2:
    // 0x800B2C1C: beq         $v0, $zero, L_800B2C2C
    if (ctx->r2 == 0) {
        // 0x800B2C20: nop

            goto L_800B2C2C;
    }
    // 0x800B2C20: nop

    // 0x800B2C24: b           L_800B2C3C
    // 0x800B2C28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2C3C;
    // 0x800B2C28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B2C2C:
    // 0x800B2C2C: b           L_800B2C3C
    // 0x800B2C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B2C3C;
    // 0x800B2C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B2C34: b           L_800B2C3C
    // 0x800B2C38: nop

        goto L_800B2C3C;
    // 0x800B2C38: nop

L_800B2C3C:
    // 0x800B2C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2C40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2C44: jr          $ra
    // 0x800B2C48: nop

    return;
    // 0x800B2C48: nop

;}
RECOMP_FUNC void func_800B2C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2C4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2C54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B2C58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B2C5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B2C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B2C64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2C68: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x800B2C6C: jal         0x800B2FB0
    // 0x800B2C70: nop

    func_800B2FB0(rdram, ctx);
        goto after_0;
    // 0x800B2C70: nop

    after_0:
    // 0x800B2C74: beq         $v0, $zero, L_800B2C9C
    if (ctx->r2 == 0) {
        // 0x800B2C78: nop

            goto L_800B2C9C;
    }
    // 0x800B2C78: nop

    // 0x800B2C7C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2C80: nop

    // 0x800B2C84: lhu         $t7, 0x3A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B2C88: nop

    // 0x800B2C8C: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x800B2C90: sh          $t8, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r24;
    // 0x800B2C94: b           L_800B2CAC
    // 0x800B2C98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B2CAC;
    // 0x800B2C98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B2C9C:
    // 0x800B2C9C: b           L_800B2CAC
    // 0x800B2CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B2CAC;
    // 0x800B2CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B2CA4: b           L_800B2CAC
    // 0x800B2CA8: nop

        goto L_800B2CAC;
    // 0x800B2CA8: nop

L_800B2CAC:
    // 0x800B2CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2CB4: jr          $ra
    // 0x800B2CB8: nop

    return;
    // 0x800B2CB8: nop

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
