#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8006829C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006829C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800682A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800682A4: nop

    // 0x800682A8: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x800682AC: nop

    // 0x800682B0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800682B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800682B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800682BC: beq         $v0, $zero, L_800682F4
    if (ctx->r2 == 0) {
        // 0x800682C0: nop
    
            goto L_800682F4;
    }
    // 0x800682C0: nop

    // 0x800682C4: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800682C8: nop

    // 0x800682CC: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800682D0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800682D4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800682D8: beq         $v0, $zero, L_800682F4
    if (ctx->r2 == 0) {
        // 0x800682DC: nop
    
            goto L_800682F4;
    }
    // 0x800682DC: nop

    // 0x800682E0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800682E4: nop

    // 0x800682E8: slti        $t9, $v0, 0x1F4
    ctx->r25 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800682EC: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x800682F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800682F4:
    // 0x800682F4: jr          $ra
    // 0x800682F8: nop

    return;
    // 0x800682F8: nop

    // 0x800682FC: jr          $ra
    // 0x80068300: nop

    return;
    // 0x80068300: nop

    // 0x80068304: jr          $ra
    // 0x80068308: nop

    return;
    // 0x80068308: nop

;}
RECOMP_FUNC void func_8007456C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007456C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074574: jal         0x80061348
    // 0x80074578: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074578: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x8007457C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074580: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074584: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074588: beq         $v0, $zero, L_800745DC
    if (ctx->r2 == 0) {
        // 0x8007458C: nop
    
            goto L_800745DC;
    }
    // 0x8007458C: nop

    // 0x80074590: jal         0x80061348
    // 0x80074594: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074594: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074598: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007459C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800745A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800745A4: beq         $v0, $zero, L_800745DC
    if (ctx->r2 == 0) {
        // 0x800745A8: nop
    
            goto L_800745DC;
    }
    // 0x800745A8: nop

    // 0x800745AC: jal         0x80061348
    // 0x800745B0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800745B0: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x800745B4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800745B8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800745BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800745C0: beq         $v0, $zero, L_800745DC
    if (ctx->r2 == 0) {
        // 0x800745C4: nop
    
            goto L_800745DC;
    }
    // 0x800745C4: nop

    // 0x800745C8: jal         0x80061348
    // 0x800745CC: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800745CC: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x800745D0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800745D4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800745D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800745DC:
    // 0x800745DC: b           L_800745EC
    // 0x800745E0: nop

        goto L_800745EC;
    // 0x800745E0: nop

    // 0x800745E4: b           L_800745EC
    // 0x800745E8: nop

        goto L_800745EC;
    // 0x800745E8: nop

L_800745EC:
    // 0x800745EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800745F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800745F4: jr          $ra
    // 0x800745F8: nop

    return;
    // 0x800745F8: nop

;}
RECOMP_FUNC void func_80072DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072DB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072DBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072DC0: nop

    // 0x80072DC4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072DC8: nop

    // 0x80072DCC: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80072DD0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072DD4: jr          $ra
    // 0x80072DD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072DD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072DDC: jr          $ra
    // 0x80072DE0: nop

    return;
    // 0x80072DE0: nop

    // 0x80072DE4: jr          $ra
    // 0x80072DE8: nop

    return;
    // 0x80072DE8: nop

;}
RECOMP_FUNC void func_80005284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005284: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x80005288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000528C: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x80005290: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
L_80005294:
    // 0x80005294: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x80005298: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000529C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800052A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800052A4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800052A8: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x800052AC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800052B0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800052B4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800052B8: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800052BC: lw          $t1, 0x17C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X17C);
    // 0x800052C0: nop

    // 0x800052C4: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x800052C8: sw          $t2, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r10;
    // 0x800052CC: lw          $t3, 0x178($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X178);
    // 0x800052D0: nop

    // 0x800052D4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800052D8: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800052DC: bne         $at, $zero, L_80005294
    if (ctx->r1 != 0) {
        // 0x800052E0: sw          $t4, 0x178($sp)
        MEM_W(0X178, ctx->r29) = ctx->r12;
            goto L_80005294;
    }
    // 0x800052E0: sw          $t4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r12;
    // 0x800052E4: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800052E8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800052EC: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800052F0: bne         $t7, $zero, L_80005300
    if (ctx->r15 != 0) {
        // 0x800052F4: nop
    
            goto L_80005300;
    }
    // 0x800052F4: nop

    // 0x800052F8: b           L_80005450
    // 0x800052FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80005450;
    // 0x800052FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005300:
    // 0x80005300: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x80005304: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
L_80005308:
    // 0x80005308: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x8000530C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005310: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80005314: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80005318: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000531C: lw          $t6, -0x73DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73DC);
    // 0x80005320: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80005324: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80005328: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x8000532C: lw          $t0, 0xC0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0XC0);
    // 0x80005330: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x80005334: nop

    // 0x80005338: or          $t3, $t2, $t0
    ctx->r11 = ctx->r10 | ctx->r8;
    // 0x8000533C: sw          $t3, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r11;
    // 0x80005340: lw          $t4, 0x178($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X178);
    // 0x80005344: nop

    // 0x80005348: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000534C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80005350: bne         $at, $zero, L_80005308
    if (ctx->r1 != 0) {
        // 0x80005354: sw          $t5, 0x178($sp)
        MEM_W(0X178, ctx->r29) = ctx->r13;
            goto L_80005308;
    }
    // 0x80005354: sw          $t5, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r13;
    // 0x80005358: lw          $t7, 0x17C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X17C);
    // 0x8000535C: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80005360: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80005364: bne         $t8, $zero, L_80005374
    if (ctx->r24 != 0) {
        // 0x80005368: nop
    
            goto L_80005374;
    }
    // 0x80005368: nop

    // 0x8000536C: b           L_80005450
    // 0x80005370: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80005450;
    // 0x80005370: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80005374:
    // 0x80005374: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
L_80005378:
    // 0x80005378: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x8000537C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80005380: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80005384: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80005388: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000538C: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x80005390: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80005394: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80005398: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8000539C: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    // 0x800053A0: jal         0x800BCFCC
    // 0x800053A4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x800053A4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_0:
    // 0x800053A8: jal         0x800C4270
    // 0x800053AC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x800053AC: nop

    after_1:
    // 0x800053B0: lw          $t2, 0x178($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X178);
    // 0x800053B4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800053B8: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x800053BC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800053C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800053C4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800053C8: lw          $t4, -0x73DC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73DC);
    // 0x800053CC: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x800053D0: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800053D4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x800053D8: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    // 0x800053DC: addu        $a1, $t0, $t4
    ctx->r5 = ADD32(ctx->r8, ctx->r12);
    // 0x800053E0: jal         0x800BCFCC
    // 0x800053E4: addu        $a0, $t0, $t3
    ctx->r4 = ADD32(ctx->r8, ctx->r11);
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x800053E4: addu        $a0, $t0, $t3
    ctx->r4 = ADD32(ctx->r8, ctx->r11);
    after_2:
    // 0x800053E8: jal         0x800C4270
    // 0x800053EC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_3;
    // 0x800053EC: nop

    after_3:
    // 0x800053F0: lw          $t5, 0x178($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X178);
    // 0x800053F4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800053F8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800053FC: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80005400: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005404: lw          $t8, -0x73DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73DC);
    // 0x80005408: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8000540C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80005410: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80005414: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    // 0x80005418: jal         0x800BCFCC
    // 0x8000541C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x8000541C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80005420: jal         0x800C4270
    // 0x80005424: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_5;
    // 0x80005424: nop

    after_5:
    // 0x80005428: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x8000542C: nop

    // 0x80005430: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80005434: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80005438: bne         $at, $zero, L_80005378
    if (ctx->r1 != 0) {
        // 0x8000543C: sw          $t9, 0x178($sp)
        MEM_W(0X178, ctx->r29) = ctx->r25;
            goto L_80005378;
    }
    // 0x8000543C: sw          $t9, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r25;
    // 0x80005440: b           L_80005450
    // 0x80005444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005450;
    // 0x80005444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005448: b           L_80005450
    // 0x8000544C: nop

        goto L_80005450;
    // 0x8000544C: nop

L_80005450:
    // 0x80005450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005454: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    // 0x80005458: jr          $ra
    // 0x8000545C: nop

    return;
    // 0x8000545C: nop

;}
RECOMP_FUNC void func_80029C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029C8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029C90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029C94: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029C98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80029C9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80029CA0: sh          $t6, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r14;
    // 0x80029CA4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80029CA8: addiu       $t7, $t7, 0x2578
    ctx->r15 = ADD32(ctx->r15, 0X2578);
    // 0x80029CAC: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80029CB0: nop

    // 0x80029CB4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80029CB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80029CBC: nop

    // 0x80029CC0: beq         $t9, $zero, L_80029D94
    if (ctx->r25 == 0) {
        // 0x80029CC4: nop
    
            goto L_80029D94;
    }
    // 0x80029CC4: nop

L_80029CC8:
    // 0x80029CC8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80029CCC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029CD0: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80029CD4: nop

    // 0x80029CD8: bne         $t1, $at, L_80029CF0
    if (ctx->r9 != ctx->r1) {
        // 0x80029CDC: nop
    
            goto L_80029CF0;
    }
    // 0x80029CDC: nop

    // 0x80029CE0: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80029CE4: nop

    // 0x80029CE8: beq         $t2, $zero, L_80029CF8
    if (ctx->r10 == 0) {
        // 0x80029CEC: nop
    
            goto L_80029CF8;
    }
    // 0x80029CEC: nop

L_80029CF0:
    // 0x80029CF0: b           L_80029D94
    // 0x80029CF4: nop

        goto L_80029D94;
    // 0x80029CF4: nop

L_80029CF8:
    // 0x80029CF8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80029CFC: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80029D00: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80029D04: nop

    // 0x80029D08: bne         $t4, $t5, L_80029D70
    if (ctx->r12 != ctx->r13) {
        // 0x80029D0C: nop
    
            goto L_80029D70;
    }
    // 0x80029D0C: nop

    // 0x80029D10: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80029D14: nop

    // 0x80029D18: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80029D1C: nop

    // 0x80029D20: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80029D24: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80029D28: lw          $t8, 0x3074($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3074);
    // 0x80029D2C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80029D30: nop

    // 0x80029D34: bne         $t8, $t9, L_80029D48
    if (ctx->r24 != ctx->r25) {
        // 0x80029D38: nop
    
            goto L_80029D48;
    }
    // 0x80029D38: nop

    // 0x80029D3C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80029D40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029D44: sw          $t1, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r9;
L_80029D48:
    // 0x80029D48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80029D4C: jal         0x800299C4
    // 0x80029D50: nop

    func_800299C4(rdram, ctx);
        goto after_0;
    // 0x80029D50: nop

    after_0:
    // 0x80029D54: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80029D58: nop

    // 0x80029D5C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80029D60: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x80029D64: nop

    // 0x80029D68: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80029D6C: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
L_80029D70:
    // 0x80029D70: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80029D74: nop

    // 0x80029D78: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x80029D7C: nop

    // 0x80029D80: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80029D84: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80029D88: nop

    // 0x80029D8C: bne         $t6, $zero, L_80029CC8
    if (ctx->r14 != 0) {
        // 0x80029D90: nop
    
            goto L_80029CC8;
    }
    // 0x80029D90: nop

L_80029D94:
    // 0x80029D94: lh          $t7, 0x2C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2C);
    // 0x80029D98: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80029D9C: blez        $t7, L_80029E30
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80029DA0: nop
    
            goto L_80029E30;
    }
    // 0x80029DA0: nop

L_80029DA4:
    // 0x80029DA4: jal         0x80029204
    // 0x80029DA8: nop

    func_80029204(rdram, ctx);
        goto after_1;
    // 0x80029DA8: nop

    after_1:
    // 0x80029DAC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80029DB0: lh          $s0, 0x32($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X32);
    // 0x80029DB4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80029DB8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80029DBC: addiu       $t9, $t9, 0x1B18
    ctx->r25 = ADD32(ctx->r25, 0X1B18);
    // 0x80029DC0: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x80029DC4: sh          $s0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r16;
    // 0x80029DC8: lbu         $t0, 0x0($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X0);
    // 0x80029DCC: addu        $t3, $s0, $t9
    ctx->r11 = ADD32(ctx->r16, ctx->r25);
    // 0x80029DD0: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80029DD4: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x80029DD8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80029DDC: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x80029DE0: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x80029DE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80029DE8: nop

    // 0x80029DEC: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x80029DF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80029DF4: nop

    // 0x80029DF8: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x80029DFC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80029E00: lw          $a1, 0x3074($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3074);
    // 0x80029E04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80029E08: jal         0x800291B4
    // 0x80029E0C: nop

    func_800291B4(rdram, ctx);
        goto after_2;
    // 0x80029E0C: nop

    after_2:
    // 0x80029E10: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x80029E14: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x80029E18: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80029E1C: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x80029E20: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80029E24: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029E28: bne         $at, $zero, L_80029DA4
    if (ctx->r1 != 0) {
        // 0x80029E2C: sh          $t1, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r9;
            goto L_80029DA4;
    }
    // 0x80029E2C: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
L_80029E30:
    // 0x80029E30: b           L_80029E38
    // 0x80029E34: nop

        goto L_80029E38;
    // 0x80029E34: nop

L_80029E38:
    // 0x80029E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029E3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029E40: jr          $ra
    // 0x80029E44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80029E44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80065F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065F6C: jal         0x80061348
    // 0x80065F70: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065F70: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80065F74: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065F78: b           L_80065F88
    // 0x80065F7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065F88;
    // 0x80065F7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065F80: b           L_80065F88
    // 0x80065F84: nop

        goto L_80065F88;
    // 0x80065F84: nop

L_80065F88:
    // 0x80065F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065F90: jr          $ra
    // 0x80065F94: nop

    return;
    // 0x80065F94: nop

;}
RECOMP_FUNC void func_8001CBAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CBAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CBB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CBB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001CBB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CBBC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CBC0: nop

    // 0x8001CBC4: bltz        $t6, L_8001CC20
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001CBC8: nop
    
            goto L_8001CC20;
    }
    // 0x8001CBC8: nop

    // 0x8001CBCC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CBD0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CBD4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CBD8: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001CBDC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CBE0: nop

    // 0x8001CBE4: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CBE8: bne         $t0, $zero, L_8001CC08
    if (ctx->r8 != 0) {
        // 0x8001CBEC: nop
    
            goto L_8001CC08;
    }
    // 0x8001CBEC: nop

    // 0x8001CBF0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001CBF4: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001CBF8: nop

    // 0x8001CBFC: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001CC00: beq         $t2, $zero, L_8001CC20
    if (ctx->r10 == 0) {
        // 0x8001CC04: nop
    
            goto L_8001CC20;
    }
    // 0x8001CC04: nop

L_8001CC08:
    // 0x8001CC08: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001CC0C: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8001CC10: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001CC14: nop

    // 0x8001CC18: xori        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 ^ 0X8;
    // 0x8001CC1C: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
L_8001CC20:
    // 0x8001CC20: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8001CC24: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8001CC28: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8001CC2C: nop

    // 0x8001CC30: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x8001CC34: beq         $t9, $zero, L_8001CC50
    if (ctx->r25 == 0) {
        // 0x8001CC38: nop
    
            goto L_8001CC50;
    }
    // 0x8001CC38: nop

    // 0x8001CC3C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CC40: jal         0x8008ECE4
    // 0x8001CC44: addiu       $a0, $a0, -0x26E4
    ctx->r4 = ADD32(ctx->r4, -0X26E4);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CC44: addiu       $a0, $a0, -0x26E4
    ctx->r4 = ADD32(ctx->r4, -0X26E4);
    after_0:
    // 0x8001CC48: b           L_8001CC5C
    // 0x8001CC4C: nop

        goto L_8001CC5C;
    // 0x8001CC4C: nop

L_8001CC50:
    // 0x8001CC50: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CC54: jal         0x8008ECE4
    // 0x8001CC58: addiu       $a0, $a0, -0x26DC
    ctx->r4 = ADD32(ctx->r4, -0X26DC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CC58: addiu       $a0, $a0, -0x26DC
    ctx->r4 = ADD32(ctx->r4, -0X26DC);
    after_1:
L_8001CC5C:
    // 0x8001CC5C: b           L_8001CC6C
    // 0x8001CC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CC6C;
    // 0x8001CC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CC64: b           L_8001CC6C
    // 0x8001CC68: nop

        goto L_8001CC6C;
    // 0x8001CC68: nop

L_8001CC6C:
    // 0x8001CC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CC70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CC74: jr          $ra
    // 0x8001CC78: nop

    return;
    // 0x8001CC78: nop

;}
RECOMP_FUNC void func_80049438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049438: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004943C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049440: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80049444: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80049448: nop

    // 0x8004944C: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80049450: nop

    // 0x80049454: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80049458: jal         0x800C0B70
    // 0x8004945C: nop

    Thread_DestroyThread(rdram, ctx);
        goto after_0;
    // 0x8004945C: nop

    after_0:
    // 0x80049460: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80049464: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80049468: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x8004946C: nop

    // 0x80049470: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80049474: nop

    // 0x80049478: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x8004947C: lh          $t1, 0x2F7($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2F7);
    // 0x80049480: nop

    // 0x80049484: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80049488: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8004948C: lw          $a0, 0x1028($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1028);
    // 0x80049490: jal         0x800BC980
    // 0x80049494: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80049494: nop

    after_1:
    // 0x80049498: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8004949C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800494A0: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800494A4: nop

    // 0x800494A8: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x800494AC: nop

    // 0x800494B0: addiu       $t6, $t5, 0x7FFF
    ctx->r14 = ADD32(ctx->r13, 0X7FFF);
    // 0x800494B4: lh          $t6, 0x2F7($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2F7);
    // 0x800494B8: nop

    // 0x800494BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800494C0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800494C4: sw          $zero, 0x1028($at)
    MEM_W(0X1028, ctx->r1) = 0;
    // 0x800494C8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800494CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800494D0: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x800494D4: nop

    // 0x800494D8: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x800494DC: nop

    // 0x800494E0: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800494E4: lh          $t1, 0x2F7($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2F7);
    // 0x800494E8: sb          $t2, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r10;
    // 0x800494EC: beq         $t1, $zero, L_80049510
    if (ctx->r9 == 0) {
        // 0x800494F0: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_80049510;
    }
    // 0x800494F0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_800494F4:
    // 0x800494F4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800494F8: lbu         $t5, 0x1B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X1B);
    // 0x800494FC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80049500: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80049504: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x80049508: bne         $t4, $zero, L_800494F4
    if (ctx->r12 != 0) {
        // 0x8004950C: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800494F4;
    }
    // 0x8004950C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
L_80049510:
    // 0x80049510: lbu         $t8, 0x1B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1B);
    // 0x80049514: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80049518: lbu         $t7, 0x1040($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1040);
    // 0x8004951C: nor         $t9, $t8, $zero
    ctx->r25 = ~(ctx->r24 | 0);
    // 0x80049520: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049524: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x80049528: sb          $t0, 0x1040($at)
    MEM_B(0X1040, ctx->r1) = ctx->r8;
    // 0x8004952C: b           L_80049534
    // 0x80049530: nop

        goto L_80049534;
    // 0x80049530: nop

L_80049534:
    // 0x80049534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004953C: jr          $ra
    // 0x80049540: nop

    return;
    // 0x80049540: nop

;}
RECOMP_FUNC void func_8006F954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F954: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F958: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F95C: nop

    // 0x8006F960: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006F964: nop

    // 0x8006F968: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F96C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F974: beq         $v0, $zero, L_8006F990
    if (ctx->r2 == 0) {
        // 0x8006F978: nop
    
            goto L_8006F990;
    }
    // 0x8006F978: nop

    // 0x8006F97C: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x8006F980: nop

    // 0x8006F984: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F988: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006F98C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006F990:
    // 0x8006F990: jr          $ra
    // 0x8006F994: nop

    return;
    // 0x8006F994: nop

    // 0x8006F998: jr          $ra
    // 0x8006F99C: nop

    return;
    // 0x8006F99C: nop

    // 0x8006F9A0: jr          $ra
    // 0x8006F9A4: nop

    return;
    // 0x8006F9A4: nop

;}
RECOMP_FUNC void func_8006DF48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DF48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DF50: jal         0x80061348
    // 0x8006DF54: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DF54: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x8006DF58: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DF5C: b           L_8006DF6C
    // 0x8006DF60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006DF6C;
    // 0x8006DF60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DF64: b           L_8006DF6C
    // 0x8006DF68: nop

        goto L_8006DF6C;
    // 0x8006DF68: nop

L_8006DF6C:
    // 0x8006DF6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DF70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DF74: jr          $ra
    // 0x8006DF78: nop

    return;
    // 0x8006DF78: nop

;}
RECOMP_FUNC void func_8006743C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006743C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067440: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067444: nop

    // 0x80067448: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006744C: nop

    // 0x80067450: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067454: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067458: jr          $ra
    // 0x8006745C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006745C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067460: jr          $ra
    // 0x80067464: nop

    return;
    // 0x80067464: nop

    // 0x80067468: jr          $ra
    // 0x8006746C: nop

    return;
    // 0x8006746C: nop

;}
RECOMP_FUNC void func_800ACE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACE50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ACE54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACE58: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800ACE5C: lw          $t6, 0x6BA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA4);
    // 0x800ACE60: nop

    // 0x800ACE64: bne         $t6, $zero, L_800ACE74
    if (ctx->r14 != 0) {
        // 0x800ACE68: nop
    
            goto L_800ACE74;
    }
    // 0x800ACE68: nop

    // 0x800ACE6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ACE70: sw          $zero, 0x6B9C($at)
    MEM_W(0X6B9C, ctx->r1) = 0;
L_800ACE74:
    // 0x800ACE74: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800ACE78: addiu       $t7, $t7, 0x61D8
    ctx->r15 = ADD32(ctx->r15, 0X61D8);
    // 0x800ACE7C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800ACE80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ACE84: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800ACE88: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800ACE8C:
    // 0x800ACE8C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800ACE90:
    // 0x800ACE90: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800ACE94: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACE98: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800ACE9C: addiu       $t9, $zero, 0x280
    ctx->r25 = ADD32(0, 0X280);
    // 0x800ACEA0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800ACEA4: sh          $t9, 0x80($t3)
    MEM_H(0X80, ctx->r11) = ctx->r25;
    // 0x800ACEA8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800ACEAC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACEB0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800ACEB4: addiu       $t4, $zero, 0x1E0
    ctx->r12 = ADD32(0, 0X1E0);
    // 0x800ACEB8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800ACEBC: sh          $t4, 0x82($t8)
    MEM_H(0X82, ctx->r24) = ctx->r12;
    // 0x800ACEC0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800ACEC4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACEC8: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x800ACECC: addiu       $t1, $zero, 0x1FF
    ctx->r9 = ADD32(0, 0X1FF);
    // 0x800ACED0: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x800ACED4: sh          $t1, 0x84($t3)
    MEM_H(0X84, ctx->r11) = ctx->r9;
    // 0x800ACED8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800ACEDC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACEE0: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x800ACEE4: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x800ACEE8: sh          $zero, 0x86($t4)
    MEM_H(0X86, ctx->r12) = 0;
    // 0x800ACEEC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800ACEF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACEF4: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x800ACEF8: addiu       $t8, $zero, 0x280
    ctx->r24 = ADD32(0, 0X280);
    // 0x800ACEFC: addu        $t1, $t2, $t9
    ctx->r9 = ADD32(ctx->r10, ctx->r25);
    // 0x800ACF00: sh          $t8, 0x88($t1)
    MEM_H(0X88, ctx->r9) = ctx->r24;
    // 0x800ACF04: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800ACF08: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF0C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800ACF10: addiu       $t3, $zero, 0x1E0
    ctx->r11 = ADD32(0, 0X1E0);
    // 0x800ACF14: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x800ACF18: sh          $t3, 0x8A($t4)
    MEM_H(0X8A, ctx->r12) = ctx->r11;
    // 0x800ACF1C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800ACF20: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF24: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800ACF28: addiu       $t0, $zero, 0x1FF
    ctx->r8 = ADD32(0, 0X1FF);
    // 0x800ACF2C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800ACF30: sh          $t0, 0x8C($t1)
    MEM_H(0X8C, ctx->r9) = ctx->r8;
    // 0x800ACF34: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800ACF38: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF3C: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x800ACF40: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x800ACF44: sh          $zero, 0x8E($t3)
    MEM_H(0X8E, ctx->r11) = 0;
    // 0x800ACF48: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800ACF4C: nop

    // 0x800ACF50: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x800ACF54: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x800ACF58: bne         $at, $zero, L_800ACE90
    if (ctx->r1 != 0) {
        // 0x800ACF5C: sw          $t9, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r25;
            goto L_800ACE90;
    }
    // 0x800ACF5C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800ACF60: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800ACF64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACF68: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF6C: nop

    // 0x800ACF70: swc1        $f4, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f4.u32l;
    // 0x800ACF74: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800ACF78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACF7C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF80: nop

    // 0x800ACF84: swc1        $f6, 0xFC($t8)
    MEM_W(0XFC, ctx->r24) = ctx->f6.u32l;
    // 0x800ACF88: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800ACF8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800ACF90: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF94: nop

    // 0x800ACF98: swc1        $f8, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f8.u32l;
    // 0x800ACF9C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800ACFA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ACFA4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFA8: nop

    // 0x800ACFAC: swc1        $f10, 0x104($t1)
    MEM_W(0X104, ctx->r9) = ctx->f10.u32l;
    // 0x800ACFB0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800ACFB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800ACFB8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFBC: nop

    // 0x800ACFC0: swc1        $f16, 0x108($t5)
    MEM_W(0X108, ctx->r13) = ctx->f16.u32l;
    // 0x800ACFC4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800ACFC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ACFCC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFD0: nop

    // 0x800ACFD4: swc1        $f18, 0x10C($t6)
    MEM_W(0X10C, ctx->r14) = ctx->f18.u32l;
    // 0x800ACFD8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800ACFDC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFE0: nop

    // 0x800ACFE4: sw          $t7, 0xE4($t3)
    MEM_W(0XE4, ctx->r11) = ctx->r15;
    // 0x800ACFE8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFEC: nop

    // 0x800ACFF0: sw          $zero, 0xF0($t4)
    MEM_W(0XF0, ctx->r12) = 0;
    // 0x800ACFF4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFF8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800ACFFC: sw          $t9, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->r25;
    // 0x800AD000: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800AD004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD008: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD00C: nop

    // 0x800AD010: swc1        $f4, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f4.u32l;
    // 0x800AD014: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800AD018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD01C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD020: nop

    // 0x800AD024: swc1        $f6, 0xEC($t0)
    MEM_W(0XEC, ctx->r8) = ctx->f6.u32l;
    // 0x800AD028: jal         0x800C1754
    // 0x800AD02C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x800AD02C: nop

    after_0:
    // 0x800AD030: jal         0x800C1B64
    // 0x800AD034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C1B64(rdram, ctx);
        goto after_1;
    // 0x800AD034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800AD038: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800AD03C:
    // 0x800AD03C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800AD040: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD044: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x800AD048: jal         0x800C2AE8
    // 0x800AD04C: addu        $a0, $t1, $t6
    ctx->r4 = ADD32(ctx->r9, ctx->r14);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_2;
    // 0x800AD04C: addu        $a0, $t1, $t6
    ctx->r4 = ADD32(ctx->r9, ctx->r14);
    after_2:
    // 0x800AD050: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AD054: nop

    // 0x800AD058: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x800AD05C: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800AD060: bne         $at, $zero, L_800AD03C
    if (ctx->r1 != 0) {
        // 0x800AD064: sw          $t3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r11;
            goto L_800AD03C;
    }
    // 0x800AD064: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800AD068: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD06C: jal         0x800C1A84
    // 0x800AD070: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_3;
    // 0x800AD070: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_3:
    // 0x800AD074: jal         0x800C1A28
    // 0x800AD078: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_4;
    // 0x800AD078: nop

    after_4:
    // 0x800AD07C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD080: nop

    // 0x800AD084: sw          $zero, 0xE0($t4)
    MEM_W(0XE0, ctx->r12) = 0;
    // 0x800AD088: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD08C: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x800AD090: sw          $t9, 0x120($t2)
    MEM_W(0X120, ctx->r10) = ctx->r25;
    // 0x800AD094: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD098: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800AD09C: sw          $t8, 0x124($t0)
    MEM_W(0X124, ctx->r8) = ctx->r24;
    // 0x800AD0A0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0A4: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x800AD0A8: sw          $t5, 0x128($t1)
    MEM_W(0X128, ctx->r9) = ctx->r13;
    // 0x800AD0AC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0B0: addiu       $t6, $zero, 0xE1
    ctx->r14 = ADD32(0, 0XE1);
    // 0x800AD0B4: sw          $t6, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->r14;
    // 0x800AD0B8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800AD0BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AD0C0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0C4: nop

    // 0x800AD0C8: swc1        $f8, 0x110($t3)
    MEM_W(0X110, ctx->r11) = ctx->f8.u32l;
    // 0x800AD0CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800AD0D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AD0D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0D8: nop

    // 0x800AD0DC: swc1        $f10, 0x114($t4)
    MEM_W(0X114, ctx->r12) = ctx->f10.u32l;
    // 0x800AD0E0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800AD0E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AD0E8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0EC: nop

    // 0x800AD0F0: swc1        $f16, 0x118($t9)
    MEM_W(0X118, ctx->r25) = ctx->f16.u32l;
    // 0x800AD0F4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800AD0F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AD0FC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD100: nop

    // 0x800AD104: swc1        $f18, 0x11C($t2)
    MEM_W(0X11C, ctx->r10) = ctx->f18.u32l;
    // 0x800AD108: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD10C: nop

    // 0x800AD110: addiu       $t0, $t8, 0x138
    ctx->r8 = ADD32(ctx->r24, 0X138);
    // 0x800AD114: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AD118: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800AD11C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800AD120: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x800AD124: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x800AD128: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800AD12C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800AD130: bne         $at, $zero, L_800ACE8C
    if (ctx->r1 != 0) {
        // 0x800AD134: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_800ACE8C;
    }
    // 0x800AD134: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800AD138: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800AD13C: addiu       $t4, $t4, 0x6BB0
    ctx->r12 = ADD32(ctx->r12, 0X6BB0);
    // 0x800AD140: addiu       $t3, $zero, 0x280
    ctx->r11 = ADD32(0, 0X280);
    // 0x800AD144: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x800AD148: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800AD14C: addiu       $t2, $t2, 0x6BB0
    ctx->r10 = ADD32(ctx->r10, 0X6BB0);
    // 0x800AD150: addiu       $t9, $zero, 0x1E0
    ctx->r25 = ADD32(0, 0X1E0);
    // 0x800AD154: sh          $t9, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r25;
    // 0x800AD158: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800AD15C: addiu       $t0, $t0, 0x6BB0
    ctx->r8 = ADD32(ctx->r8, 0X6BB0);
    // 0x800AD160: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x800AD164: sh          $t8, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r24;
    // 0x800AD168: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800AD16C: addiu       $t5, $t5, 0x6BB0
    ctx->r13 = ADD32(ctx->r13, 0X6BB0);
    // 0x800AD170: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800AD174: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800AD178: addiu       $t7, $t7, 0x6BB0
    ctx->r15 = ADD32(ctx->r15, 0X6BB0);
    // 0x800AD17C: addiu       $t6, $zero, 0x280
    ctx->r14 = ADD32(0, 0X280);
    // 0x800AD180: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x800AD184: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800AD188: addiu       $t3, $t3, 0x6BB0
    ctx->r11 = ADD32(ctx->r11, 0X6BB0);
    // 0x800AD18C: addiu       $t1, $zero, 0x1E0
    ctx->r9 = ADD32(0, 0X1E0);
    // 0x800AD190: sh          $t1, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r9;
    // 0x800AD194: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800AD198: addiu       $t9, $t9, 0x6BB0
    ctx->r25 = ADD32(ctx->r25, 0X6BB0);
    // 0x800AD19C: addiu       $t4, $zero, 0x1FF
    ctx->r12 = ADD32(0, 0X1FF);
    // 0x800AD1A0: sh          $t4, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r12;
    // 0x800AD1A4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800AD1A8: addiu       $t2, $t2, 0x6BB0
    ctx->r10 = ADD32(ctx->r10, 0X6BB0);
    // 0x800AD1AC: sh          $zero, 0xE($t2)
    MEM_H(0XE, ctx->r10) = 0;
    // 0x800AD1B0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800AD1B4: jal         0x80099E2C
    // 0x800AD1B8: addiu       $a0, $a0, -0x76B0
    ctx->r4 = ADD32(ctx->r4, -0X76B0);
    func_80099E2C(rdram, ctx);
        goto after_5;
    // 0x800AD1B8: addiu       $a0, $a0, -0x76B0
    ctx->r4 = ADD32(ctx->r4, -0X76B0);
    after_5:
    // 0x800AD1BC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800AD1C0: addiu       $a0, $a0, -0x76B0
    ctx->r4 = ADD32(ctx->r4, -0X76B0);
    // 0x800AD1C4: jal         0x80099E2C
    // 0x800AD1C8: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    func_80099E2C(rdram, ctx);
        goto after_6;
    // 0x800AD1C8: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    after_6:
    // 0x800AD1CC: b           L_800AD1D4
    // 0x800AD1D0: nop

        goto L_800AD1D4;
    // 0x800AD1D0: nop

L_800AD1D4:
    // 0x800AD1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD1D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800AD1DC: jr          $ra
    // 0x800AD1E0: nop

    return;
    // 0x800AD1E0: nop

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
    // 0x80087FFC: lbu         $t4, 0x15($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X15);
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
    // 0x80088028: sb          $t6, 0x15($t9)
    MEM_B(0X15, ctx->r25) = ctx->r14;
    // 0x8008802C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80088030: nop

    // 0x80088034: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80088038: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
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
    // 0x800880CC: lbu         $t0, 0x15($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X15);
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
    // 0x800880E8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
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
    // 0x80088100: lbu         $t5, 0x15($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X15);
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

    // 0x80088118: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
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

    // 0x80088134: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80088138: bne         $at, $zero, L_80088148
    if (ctx->r1 != 0) {
        // 0x8008813C: nop
    
            goto L_80088148;
    }
    // 0x8008813C: nop

    // 0x80088140: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
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
    // 0x80088164: sb          $t2, 0x15($t4)
    MEM_B(0X15, ctx->r12) = ctx->r10;
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
    // 0x80088194: lbu         $t1, 0x15($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X15);
    // 0x80088198: nop

    // 0x8008819C: addiu       $t3, $t1, 0x57
    ctx->r11 = ADD32(ctx->r9, 0X57);
    // 0x800881A0: sb          $t3, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r11;
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
    // 0x800881F8: lbu         $t3, 0x15($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X15);
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
    // 0x80088214: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
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
    // 0x8008822C: lbu         $t4, 0x15($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X15);
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
    // 0x80088278: sb          $t1, 0x15($t5)
    MEM_B(0X15, ctx->r13) = ctx->r9;
        goto L_8008828C;
    // 0x80088278: sb          $t1, 0x15($t5)
    MEM_B(0X15, ctx->r13) = ctx->r9;
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
    // 0x800882B8: lbu         $t9, 0x15($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X15);
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
    // 0x800882E4: sb          $t3, 0x15($t1)
    MEM_B(0X15, ctx->r9) = ctx->r11;
    // 0x800882E8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800882EC: nop

    // 0x800882F0: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800882F4: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
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
RECOMP_FUNC void func_8007ECB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ECB0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007ECB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007ECB8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8007ECBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007ECC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007ECC4: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x8007ECC8: lhu         $t6, 0x4A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4A);
    // 0x8007ECCC: nop

    // 0x8007ECD0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8007ECD4: beq         $t8, $zero, L_8007EE20
    if (ctx->r24 == 0) {
        // 0x8007ECD8: nop
    
            goto L_8007EE20;
    }
    // 0x8007ECD8: nop

    // 0x8007ECDC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007ECE0: lw          $t9, 0x7100($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7100);
    // 0x8007ECE4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007ECE8: bne         $t9, $at, L_8007ED44
    if (ctx->r25 != ctx->r1) {
        // 0x8007ECEC: nop
    
            goto L_8007ED44;
    }
    // 0x8007ECEC: nop

    // 0x8007ECF0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007ECF4: lw          $t0, 0x7104($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7104);
    // 0x8007ECF8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007ECFC: beq         $t0, $at, L_8007ED10
    if (ctx->r8 == ctx->r1) {
        // 0x8007ED00: nop
    
            goto L_8007ED10;
    }
    // 0x8007ED00: nop

    // 0x8007ED04: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007ED08: bne         $t0, $at, L_8007ED44
    if (ctx->r8 != ctx->r1) {
        // 0x8007ED0C: nop
    
            goto L_8007ED44;
    }
    // 0x8007ED0C: nop

L_8007ED10:
    // 0x8007ED10: jal         0x800B9000
    // 0x8007ED14: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x8007ED14: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x8007ED18: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x8007ED1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED20: sh          $t1, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r9;
    // 0x8007ED24: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8007ED28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED2C: sh          $t2, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r10;
    // 0x8007ED30: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007ED34: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007ED38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED3C: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8007ED40: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
L_8007ED44:
    // 0x8007ED44: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007ED48: lw          $t5, 0x7100($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7100);
    // 0x8007ED4C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007ED50: bne         $t5, $at, L_8007EDA0
    if (ctx->r13 != ctx->r1) {
        // 0x8007ED54: nop
    
            goto L_8007EDA0;
    }
    // 0x8007ED54: nop

    // 0x8007ED58: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007ED5C: lw          $t6, 0x7104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7104);
    // 0x8007ED60: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8007ED64: bne         $t6, $at, L_8007EDA0
    if (ctx->r14 != ctx->r1) {
        // 0x8007ED68: nop
    
            goto L_8007EDA0;
    }
    // 0x8007ED68: nop

    // 0x8007ED6C: jal         0x800B9000
    // 0x8007ED70: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8007ED70: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_1:
    // 0x8007ED74: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8007ED78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED7C: sh          $t7, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r15;
    // 0x8007ED80: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8007ED84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED88: sh          $t8, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r24;
    // 0x8007ED8C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007ED90: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007ED94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ED98: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8007ED9C: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
L_8007EDA0:
    // 0x8007EDA0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007EDA4: lw          $t1, 0x7100($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7100);
    // 0x8007EDA8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EDAC: bne         $t1, $at, L_8007EDDC
    if (ctx->r9 != ctx->r1) {
        // 0x8007EDB0: nop
    
            goto L_8007EDDC;
    }
    // 0x8007EDB0: nop

    // 0x8007EDB4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007EDB8: lw          $t2, 0x7104($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7104);
    // 0x8007EDBC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007EDC0: bne         $t2, $at, L_8007EDDC
    if (ctx->r10 != ctx->r1) {
        // 0x8007EDC4: nop
    
            goto L_8007EDDC;
    }
    // 0x8007EDC4: nop

    // 0x8007EDC8: jal         0x800B9000
    // 0x8007EDCC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_2;
    // 0x8007EDCC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x8007EDD0: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8007EDD4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EDD8: sh          $t3, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r11;
L_8007EDDC:
    // 0x8007EDDC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007EDE0: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007EDE4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EDE8: bne         $t4, $at, L_8007EE18
    if (ctx->r12 != ctx->r1) {
        // 0x8007EDEC: nop
    
            goto L_8007EE18;
    }
    // 0x8007EDEC: nop

    // 0x8007EDF0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007EDF4: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007EDF8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007EDFC: bne         $t5, $at, L_8007EE18
    if (ctx->r13 != ctx->r1) {
        // 0x8007EE00: nop
    
            goto L_8007EE18;
    }
    // 0x8007EE00: nop

    // 0x8007EE04: jal         0x800B9000
    // 0x8007EE08: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8007EE08: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_3:
    // 0x8007EE0C: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8007EE10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EE14: sh          $t6, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r14;
L_8007EE18:
    // 0x8007EE18: b           L_8007F868
    // 0x8007EE1C: nop

        goto L_8007F868;
    // 0x8007EE1C: nop

L_8007EE20:
    // 0x8007EE20: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8007EE24: lh          $a3, 0x7132($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7132);
    // 0x8007EE28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007EE2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007EE30: jal         0x8007EB90
    // 0x8007EE34: addiu       $a2, $sp, 0x2E
    ctx->r6 = ADD32(ctx->r29, 0X2E);
    func_8007EB90(rdram, ctx);
        goto after_4;
    // 0x8007EE34: addiu       $a2, $sp, 0x2E
    ctx->r6 = ADD32(ctx->r29, 0X2E);
    after_4:
    // 0x8007EE38: lhu         $t7, 0x2E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2E);
    // 0x8007EE3C: addiu       $at, $zero, 0x2109
    ctx->r1 = ADD32(0, 0X2109);
    // 0x8007EE40: bne         $t7, $at, L_8007EE58
    if (ctx->r15 != ctx->r1) {
        // 0x8007EE44: nop
    
            goto L_8007EE58;
    }
    // 0x8007EE44: nop

    // 0x8007EE48: jal         0x8007B710
    // 0x8007EE4C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8007B710(rdram, ctx);
        goto after_5;
    // 0x8007EE4C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x8007EE50: b           L_8007EE60
    // 0x8007EE54: nop

        goto L_8007EE60;
    // 0x8007EE54: nop

L_8007EE58:
    // 0x8007EE58: jal         0x8007B710
    // 0x8007EE5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007B710(rdram, ctx);
        goto after_6;
    // 0x8007EE5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
L_8007EE60:
    // 0x8007EE60: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007EE64: addiu       $t8, $t8, 0x70F0
    ctx->r24 = ADD32(ctx->r24, 0X70F0);
    // 0x8007EE68: lh          $t9, 0x3C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X3C);
    // 0x8007EE6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007EE70: beq         $t9, $at, L_8007F004
    if (ctx->r25 == ctx->r1) {
        // 0x8007EE74: nop
    
            goto L_8007F004;
    }
    // 0x8007EE74: nop

    // 0x8007EE78: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007EE7C: addiu       $t0, $t0, 0x70F0
    ctx->r8 = ADD32(ctx->r8, 0X70F0);
    // 0x8007EE80: lh          $t1, 0x3C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X3C);
    // 0x8007EE84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EE88: sh          $t1, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r9;
    // 0x8007EE8C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007EE90: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007EE94: lh          $t3, 0x3E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X3E);
    // 0x8007EE98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EE9C: sh          $t3, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r11;
    // 0x8007EEA0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007EEA4: lh          $t4, 0x713A($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X713A);
    // 0x8007EEA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EEAC: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x8007EEB0: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
    // 0x8007EEB4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007EEB8: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007EEBC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EEC0: bne         $t6, $at, L_8007EF1C
    if (ctx->r14 != ctx->r1) {
        // 0x8007EEC4: nop
    
            goto L_8007EF1C;
    }
    // 0x8007EEC4: nop

    // 0x8007EEC8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007EECC: lw          $t7, 0x7104($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7104);
    // 0x8007EED0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8007EED4: bne         $t7, $at, L_8007EF1C
    if (ctx->r15 != ctx->r1) {
        // 0x8007EED8: nop
    
            goto L_8007EF1C;
    }
    // 0x8007EED8: nop

    // 0x8007EEDC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007EEE0: lh          $t8, 0x7132($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7132);
    // 0x8007EEE4: nop

    // 0x8007EEE8: bltz        $t8, L_8007EF1C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007EEEC: nop
    
            goto L_8007EF1C;
    }
    // 0x8007EEEC: nop

    // 0x8007EEF0: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8007EEF4: beq         $at, $zero, L_8007EF1C
    if (ctx->r1 == 0) {
        // 0x8007EEF8: nop
    
            goto L_8007EF1C;
    }
    // 0x8007EEF8: nop

    // 0x8007EEFC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007EF00: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007EF04: lh          $a1, 0x7132($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7132);
    // 0x8007EF08: lb          $a0, 0x7140($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7140);
    // 0x8007EF0C: jal         0x8007F930
    // 0x8007EF10: nop

    func_8007F930(rdram, ctx);
        goto after_7;
    // 0x8007EF10: nop

    after_7:
    // 0x8007EF14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EF18: sb          $v0, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r2;
L_8007EF1C:
    // 0x8007EF1C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007EF20: lw          $t9, 0x7100($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7100);
    // 0x8007EF24: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EF28: bne         $t9, $at, L_8007EFCC
    if (ctx->r25 != ctx->r1) {
        // 0x8007EF2C: nop
    
            goto L_8007EFCC;
    }
    // 0x8007EF2C: nop

    // 0x8007EF30: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007EF34: lw          $t0, 0x7104($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7104);
    // 0x8007EF38: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007EF3C: bne         $t0, $at, L_8007EFCC
    if (ctx->r8 != ctx->r1) {
        // 0x8007EF40: nop
    
            goto L_8007EFCC;
    }
    // 0x8007EF40: nop

    // 0x8007EF44: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007EF48: lh          $t1, 0x7132($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7132);
    // 0x8007EF4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007EF50: bne         $t1, $at, L_8007EFCC
    if (ctx->r9 != ctx->r1) {
        // 0x8007EF54: nop
    
            goto L_8007EFCC;
    }
    // 0x8007EF54: nop

    // 0x8007EF58: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007EF5C: lw          $t2, 0x70FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70FC);
    // 0x8007EF60: nop

    // 0x8007EF64: bne         $t2, $zero, L_8007EFB0
    if (ctx->r10 != 0) {
        // 0x8007EF68: nop
    
            goto L_8007EFB0;
    }
    // 0x8007EF68: nop

    // 0x8007EF6C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007EF70: lw          $a0, 0x70FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70FC);
    // 0x8007EF74: jal         0x8007A514
    // 0x8007EF78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8007A514(rdram, ctx);
        goto after_8;
    // 0x8007EF78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8007EF7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EF80: sw          $v0, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r2;
    // 0x8007EF84: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007EF88: lw          $t3, 0x70FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70FC);
    // 0x8007EF8C: nop

    // 0x8007EF90: bne         $t3, $zero, L_8007EFB0
    if (ctx->r11 != 0) {
        // 0x8007EF94: nop
    
            goto L_8007EFB0;
    }
    // 0x8007EF94: nop

    // 0x8007EF98: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007EF9C: lh          $t4, 0x713A($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X713A);
    // 0x8007EFA0: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8007EFA4: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8007EFA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EFAC: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
L_8007EFB0:
    // 0x8007EFB0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007EFB4: lw          $t6, 0x70FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70FC);
    // 0x8007EFB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007EFBC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8007EFC0: nop

    // 0x8007EFC4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007EFC8: sb          $t8, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r24;
L_8007EFCC:
    // 0x8007EFCC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007EFD0: lw          $t9, 0x7100($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7100);
    // 0x8007EFD4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007EFD8: bne         $t9, $at, L_8007F004
    if (ctx->r25 != ctx->r1) {
        // 0x8007EFDC: nop
    
            goto L_8007F004;
    }
    // 0x8007EFDC: nop

    // 0x8007EFE0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007EFE4: lw          $t0, 0x7104($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7104);
    // 0x8007EFE8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007EFEC: bne         $t0, $at, L_8007F004
    if (ctx->r8 != ctx->r1) {
        // 0x8007EFF0: nop
    
            goto L_8007F004;
    }
    // 0x8007EFF0: nop

    // 0x8007EFF4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007EFF8: lh          $t1, 0x7132($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7132);
    // 0x8007EFFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F000: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
L_8007F004:
    // 0x8007F004: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F008: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007F00C: lh          $t3, 0x3E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X3E);
    // 0x8007F010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F014: bne         $t3, $at, L_8007F054
    if (ctx->r11 != ctx->r1) {
        // 0x8007F018: nop
    
            goto L_8007F054;
    }
    // 0x8007F018: nop

    // 0x8007F01C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007F020: lw          $t4, 0x70F8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F8);
    // 0x8007F024: nop

    // 0x8007F028: bne         $t4, $zero, L_8007F040
    if (ctx->r12 != 0) {
        // 0x8007F02C: nop
    
            goto L_8007F040;
    }
    // 0x8007F02C: nop

    // 0x8007F030: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x8007F034: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F038: b           L_8007F04C
    // 0x8007F03C: sh          $t5, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r13;
        goto L_8007F04C;
    // 0x8007F03C: sh          $t5, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r13;
L_8007F040:
    // 0x8007F040: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8007F044: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F048: sh          $t6, 0x7130($at)
    MEM_H(0X7130, ctx->r1) = ctx->r14;
L_8007F04C:
    // 0x8007F04C: b           L_8007F868
    // 0x8007F050: nop

        goto L_8007F868;
    // 0x8007F050: nop

L_8007F054:
    // 0x8007F054: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F058: addiu       $t7, $t7, 0x70F0
    ctx->r15 = ADD32(ctx->r15, 0X70F0);
    // 0x8007F05C: lh          $t8, 0x3E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X3E);
    // 0x8007F060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F064: bne         $t8, $at, L_8007F0A8
    if (ctx->r24 != ctx->r1) {
        // 0x8007F068: nop
    
            goto L_8007F0A8;
    }
    // 0x8007F068: nop

    // 0x8007F06C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F070: lb          $a0, 0x7140($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7140);
    // 0x8007F074: jal         0x8007F930
    // 0x8007F078: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
    func_8007F930(rdram, ctx);
        goto after_9;
    // 0x8007F078: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
    after_9:
    // 0x8007F07C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F080: sb          $v0, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = ctx->r2;
    // 0x8007F084: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F088: lb          $t9, 0x7140($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7140);
    // 0x8007F08C: nop

    // 0x8007F090: bgez        $t9, L_8007F0A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007F094: nop
    
            goto L_8007F0A0;
    }
    // 0x8007F094: nop

    // 0x8007F098: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F09C: sb          $zero, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = 0;
L_8007F0A0:
    // 0x8007F0A0: b           L_8007F868
    // 0x8007F0A4: nop

        goto L_8007F868;
    // 0x8007F0A4: nop

L_8007F0A8:
    // 0x8007F0A8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F0AC: addiu       $t0, $t0, 0x70F0
    ctx->r8 = ADD32(ctx->r8, 0X70F0);
    // 0x8007F0B0: lh          $t1, 0x3E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X3E);
    // 0x8007F0B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007F0B8: bne         $t1, $at, L_8007F118
    if (ctx->r9 != ctx->r1) {
        // 0x8007F0BC: nop
    
            goto L_8007F118;
    }
    // 0x8007F0BC: nop

    // 0x8007F0C0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F0C4: lb          $a0, 0x7140($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7140);
    // 0x8007F0C8: jal         0x8007F930
    // 0x8007F0CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8007F930(rdram, ctx);
        goto after_10;
    // 0x8007F0CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x8007F0D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F0D4: sb          $v0, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = ctx->r2;
    // 0x8007F0D8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8007F0DC: jal         0x8007F930
    // 0x8007F0E0: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    func_8007F930(rdram, ctx);
        goto after_11;
    // 0x8007F0E0: addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    after_11:
    // 0x8007F0E4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8007F0E8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F0EC: lb          $t2, 0x7140($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7140);
    // 0x8007F0F0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8007F0F4: nop

    // 0x8007F0F8: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007F0FC: bne         $at, $zero, L_8007F110
    if (ctx->r1 != 0) {
        // 0x8007F100: nop
    
            goto L_8007F110;
    }
    // 0x8007F100: nop

    // 0x8007F104: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8007F108: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F10C: sb          $t4, 0x7140($at)
    MEM_B(0X7140, ctx->r1) = ctx->r12;
L_8007F110:
    // 0x8007F110: b           L_8007F868
    // 0x8007F114: nop

        goto L_8007F868;
    // 0x8007F114: nop

L_8007F118:
    // 0x8007F118: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007F11C: addiu       $t5, $t5, 0x70F0
    ctx->r13 = ADD32(ctx->r13, 0X70F0);
    // 0x8007F120: lh          $t6, 0x3E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X3E);
    // 0x8007F124: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007F128: bne         $t6, $at, L_8007F3AC
    if (ctx->r14 != ctx->r1) {
        // 0x8007F12C: nop
    
            goto L_8007F3AC;
    }
    // 0x8007F12C: nop

    // 0x8007F130: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F134: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007F138: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F13C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007F140: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8007F144: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007F148: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8007F14C: lh          $t2, 0x2460($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2460);
    // 0x8007F150: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F154: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007F158: lw          $t8, 0x718C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X718C);
    // 0x8007F15C: lw          $t7, 0x70E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E8);
    // 0x8007F160: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8007F164: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007F168: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8007F16C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007F170: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x8007F174: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8007F178: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8007F17C: nop

    // 0x8007F180: bgez        $t5, L_8007F1D4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007F184: nop
    
            goto L_8007F1D4;
    }
    // 0x8007F184: nop

    // 0x8007F188: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007F18C: addiu       $t6, $t6, 0x2440
    ctx->r14 = ADD32(ctx->r14, 0X2440);
    // 0x8007F190: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F194: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F198: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F19C: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F1A0: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x8007F1A4: jal         0x800BD1FC
    // 0x8007F1A8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_12;
    // 0x8007F1A8: nop

    after_12:
    // 0x8007F1AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F1B0: jal         0x80080910
    // 0x8007F1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_13;
    // 0x8007F1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8007F1B8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F1BC: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007F1C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F1C4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8007F1C8: sh          $t8, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r24;
    // 0x8007F1CC: b           L_8007F868
    // 0x8007F1D0: nop

        goto L_8007F868;
    // 0x8007F1D0: nop

L_8007F1D4:
    // 0x8007F1D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007F1D8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F1DC: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007F1E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007F1E4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8007F1E8: lbu         $t1, 0x1B19($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1B19);
    // 0x8007F1EC: nop

    // 0x8007F1F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8007F1F4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F1F8: lb          $t2, 0x7142($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7142);
    // 0x8007F1FC: nop

    // 0x8007F200: beq         $t2, $zero, L_8007F214
    if (ctx->r10 == 0) {
        // 0x8007F204: nop
    
            goto L_8007F214;
    }
    // 0x8007F204: nop

    // 0x8007F208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F20C: bne         $t2, $at, L_8007F238
    if (ctx->r10 != ctx->r1) {
        // 0x8007F210: nop
    
            goto L_8007F238;
    }
    // 0x8007F210: nop

L_8007F214:
    // 0x8007F214: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F218: lb          $t9, 0x7142($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7142);
    // 0x8007F21C: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8007F220: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x8007F224: lbu         $s0, 0x1B40($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0X1B40);
    // 0x8007F228: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007F22C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8007F230: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8007F234: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_8007F238:
    // 0x8007F238: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F23C: lb          $t6, 0x7142($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7142);
    // 0x8007F240: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007F244: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007F248: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007F24C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F250: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007F254: lh          $t8, 0x2464($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2464);
    // 0x8007F258: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007F25C: nop

    // 0x8007F260: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007F264: bne         $at, $zero, L_8007F300
    if (ctx->r1 != 0) {
        // 0x8007F268: nop
    
            goto L_8007F300;
    }
    // 0x8007F268: nop

    // 0x8007F26C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007F270: nop

    // 0x8007F274: beq         $t0, $zero, L_8007F2B4
    if (ctx->r8 == 0) {
        // 0x8007F278: nop
    
            goto L_8007F2B4;
    }
    // 0x8007F278: nop

    // 0x8007F27C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F280: addiu       $t1, $t1, 0x2440
    ctx->r9 = ADD32(ctx->r9, 0X2440);
    // 0x8007F284: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F288: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F28C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F290: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F294: lw          $a2, 0x14($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X14);
    // 0x8007F298: jal         0x800BD1FC
    // 0x8007F29C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_14;
    // 0x8007F29C: nop

    after_14:
    // 0x8007F2A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F2A4: jal         0x80080910
    // 0x8007F2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_15;
    // 0x8007F2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8007F2AC: b           L_8007F2E4
    // 0x8007F2B0: nop

        goto L_8007F2E4;
    // 0x8007F2B0: nop

L_8007F2B4:
    // 0x8007F2B4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F2B8: addiu       $t2, $t2, 0x2440
    ctx->r10 = ADD32(ctx->r10, 0X2440);
    // 0x8007F2BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F2C0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F2C4: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F2C8: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F2CC: lw          $a2, 0xC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0XC);
    // 0x8007F2D0: jal         0x800BD1FC
    // 0x8007F2D4: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_16;
    // 0x8007F2D4: nop

    after_16:
    // 0x8007F2D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F2DC: jal         0x80080910
    // 0x8007F2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_17;
    // 0x8007F2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_8007F2E4:
    // 0x8007F2E4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F2E8: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007F2EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F2F0: ori         $t3, $t9, 0x10
    ctx->r11 = ctx->r25 | 0X10;
    // 0x8007F2F4: sh          $t3, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r11;
    // 0x8007F2F8: b           L_8007F868
    // 0x8007F2FC: nop

        goto L_8007F868;
    // 0x8007F2FC: nop

L_8007F300:
    // 0x8007F300: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F304: lb          $t6, 0x7142($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7142);
    // 0x8007F308: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007F30C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007F310: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007F314: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F318: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8007F31C: lh          $t5, 0x2460($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2460);
    // 0x8007F320: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007F324: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8007F328: lw          $t4, 0x718C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X718C);
    // 0x8007F32C: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8007F330: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8007F334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F338: subu        $t0, $t4, $t8
    ctx->r8 = SUB32(ctx->r12, ctx->r24);
    // 0x8007F33C: sw          $t0, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r8;
    // 0x8007F340: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F344: addiu       $t1, $t1, 0x2440
    ctx->r9 = ADD32(ctx->r9, 0X2440);
    // 0x8007F348: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F34C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F350: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F354: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F358: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8007F35C: jal         0x800BD1FC
    // 0x8007F360: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_18;
    // 0x8007F360: nop

    after_18:
    // 0x8007F364: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F368: jal         0x80080910
    // 0x8007F36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_19;
    // 0x8007F36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8007F370: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F374: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007F378: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F37C: ori         $t9, $t2, 0x10
    ctx->r25 = ctx->r10 | 0X10;
    // 0x8007F380: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007F384: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007F388: lb          $a0, 0x7142($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X7142);
    // 0x8007F38C: jal         0x80029C8C
    // 0x8007F390: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_80029C8C(rdram, ctx);
        goto after_20;
    // 0x8007F390: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_20:
    // 0x8007F394: jal         0x800B9000
    // 0x8007F398: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800B9000(rdram, ctx);
        goto after_21;
    // 0x8007F398: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_21:
    // 0x8007F39C: jal         0x8007DF3C
    // 0x8007F3A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007DF3C(rdram, ctx);
        goto after_22;
    // 0x8007F3A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x8007F3A4: b           L_8007F868
    // 0x8007F3A8: nop

        goto L_8007F868;
    // 0x8007F3A8: nop

L_8007F3AC:
    // 0x8007F3AC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007F3B0: addiu       $t3, $t3, 0x70F0
    ctx->r11 = ADD32(ctx->r11, 0X70F0);
    // 0x8007F3B4: lh          $t6, 0x3E($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X3E);
    // 0x8007F3B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007F3BC: bne         $t6, $at, L_8007F5A0
    if (ctx->r14 != ctx->r1) {
        // 0x8007F3C0: nop
    
            goto L_8007F5A0;
    }
    // 0x8007F3C0: nop

    // 0x8007F3C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F3C8: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007F3CC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007F3D0: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8007F3D4: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8007F3D8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007F3DC: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F3E0: lh          $t4, 0x2462($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2462);
    // 0x8007F3E4: nop

    // 0x8007F3E8: bgez        $t4, L_8007F43C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007F3EC: nop
    
            goto L_8007F43C;
    }
    // 0x8007F3EC: nop

    // 0x8007F3F0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007F3F4: addiu       $t8, $t8, 0x2440
    ctx->r24 = ADD32(ctx->r24, 0X2440);
    // 0x8007F3F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F3FC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F400: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F404: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F408: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x8007F40C: jal         0x800BD1FC
    // 0x8007F410: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_23;
    // 0x8007F410: nop

    after_23:
    // 0x8007F414: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F418: jal         0x80080910
    // 0x8007F41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_24;
    // 0x8007F41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8007F420: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F424: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007F428: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F42C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8007F430: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007F434: b           L_8007F868
    // 0x8007F438: nop

        goto L_8007F868;
    // 0x8007F438: nop

L_8007F43C:
    // 0x8007F43C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F440: addiu       $t2, $t2, 0x2440
    ctx->r10 = ADD32(ctx->r10, 0X2440);
    // 0x8007F444: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F448: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F44C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F450: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F454: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8007F458: jal         0x800BD1FC
    // 0x8007F45C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_25;
    // 0x8007F45C: nop

    after_25:
    // 0x8007F460: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F464: jal         0x80080910
    // 0x8007F468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_26;
    // 0x8007F468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8007F46C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F470: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007F474: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F478: ori         $t3, $t9, 0x10
    ctx->r11 = ctx->r25 | 0X10;
    // 0x8007F47C: sh          $t3, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r11;
    // 0x8007F480: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F484: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007F488: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007F48C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8007F490: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8007F494: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007F498: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F49C: lh          $t4, 0x2462($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2462);
    // 0x8007F4A0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F4A4: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8007F4A8: lw          $t6, 0x718C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X718C);
    // 0x8007F4AC: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x8007F4B0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8007F4B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F4B8: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x8007F4BC: sw          $t0, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r8;
    // 0x8007F4C0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007F4C4: lw          $t1, 0x70FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70FC);
    // 0x8007F4C8: nop

    // 0x8007F4CC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8007F4D0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8007F4D4: nop

    // 0x8007F4D8: lw          $t9, 0x18($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X18);
    // 0x8007F4DC: nop

    // 0x8007F4E0: beq         $t9, $zero, L_8007F50C
    if (ctx->r25 == 0) {
        // 0x8007F4E4: nop
    
            goto L_8007F50C;
    }
    // 0x8007F4E4: nop

    // 0x8007F4E8: lh          $t3, 0x2($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X2);
    // 0x8007F4EC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007F4F0: bne         $t3, $at, L_8007F50C
    if (ctx->r11 != ctx->r1) {
        // 0x8007F4F4: nop
    
            goto L_8007F50C;
    }
    // 0x8007F4F4: nop

    // 0x8007F4F8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8007F4FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F500: lw          $t5, 0x18($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X18);
    // 0x8007F504: b           L_8007F57C
    // 0x8007F508: sw          $t5, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r13;
        goto L_8007F57C;
    // 0x8007F508: sw          $t5, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r13;
L_8007F50C:
    // 0x8007F50C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8007F510: jal         0x8007A514
    // 0x8007F514: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8007A514(rdram, ctx);
        goto after_27;
    // 0x8007F514: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_27:
    // 0x8007F518: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007F51C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8007F520: nop

    // 0x8007F524: bne         $t4, $zero, L_8007F570
    if (ctx->r12 != 0) {
        // 0x8007F528: nop
    
            goto L_8007F570;
    }
    // 0x8007F528: nop

    // 0x8007F52C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007F530: addiu       $t6, $t6, 0x2440
    ctx->r14 = ADD32(ctx->r14, 0X2440);
    // 0x8007F534: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F538: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F53C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F540: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F544: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x8007F548: jal         0x800BD1FC
    // 0x8007F54C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_28;
    // 0x8007F54C: nop

    after_28:
    // 0x8007F550: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F554: jal         0x80080910
    // 0x8007F558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_29;
    // 0x8007F558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8007F55C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007F560: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007F564: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F568: ori         $t0, $t8, 0x310
    ctx->r8 = ctx->r24 | 0X310;
    // 0x8007F56C: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
L_8007F570:
    // 0x8007F570: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8007F574: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F578: sw          $t1, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r9;
L_8007F57C:
    // 0x8007F57C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8007F580: jal         0x800299C4
    // 0x8007F584: nop

    func_800299C4(rdram, ctx);
        goto after_30;
    // 0x8007F584: nop

    after_30:
    // 0x8007F588: jal         0x800B9000
    // 0x8007F58C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800B9000(rdram, ctx);
        goto after_31;
    // 0x8007F58C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_31:
    // 0x8007F590: jal         0x8007DF3C
    // 0x8007F594: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007DF3C(rdram, ctx);
        goto after_32;
    // 0x8007F594: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_32:
    // 0x8007F598: b           L_8007F868
    // 0x8007F59C: nop

        goto L_8007F868;
    // 0x8007F59C: nop

L_8007F5A0:
    // 0x8007F5A0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F5A4: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007F5A8: lh          $t9, 0x3E($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X3E);
    // 0x8007F5AC: nop

    // 0x8007F5B0: bne         $t9, $zero, L_8007F618
    if (ctx->r25 != 0) {
        // 0x8007F5B4: nop
    
            goto L_8007F618;
    }
    // 0x8007F5B4: nop

    // 0x8007F5B8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007F5BC: lb          $t3, 0x7142($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7142);
    // 0x8007F5C0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007F5C4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8007F5C8: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8007F5CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007F5D0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8007F5D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F5D8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F5DC: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F5E0: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F5E4: lw          $a2, 0x245C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X245C);
    // 0x8007F5E8: jal         0x800BD1FC
    // 0x8007F5EC: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_33;
    // 0x8007F5EC: nop

    after_33:
    // 0x8007F5F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F5F4: jal         0x80080910
    // 0x8007F5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_34;
    // 0x8007F5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8007F5FC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007F600: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007F604: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F608: ori         $t4, $t5, 0x10
    ctx->r12 = ctx->r13 | 0X10;
    // 0x8007F60C: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007F610: b           L_8007F868
    // 0x8007F614: nop

        goto L_8007F868;
    // 0x8007F614: nop

L_8007F618:
    // 0x8007F618: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F61C: addiu       $t6, $t6, 0x70F0
    ctx->r14 = ADD32(ctx->r14, 0X70F0);
    // 0x8007F620: lh          $t8, 0x3E($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X3E);
    // 0x8007F624: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007F628: bne         $t8, $at, L_8007F858
    if (ctx->r24 != ctx->r1) {
        // 0x8007F62C: nop
    
            goto L_8007F858;
    }
    // 0x8007F62C: nop

    // 0x8007F630: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F634: lb          $t0, 0x7142($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7142);
    // 0x8007F638: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F63C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007F640: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007F644: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007F648: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8007F64C: lbu         $a0, 0x27A8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27A8);
    // 0x8007F650: jal         0x8005F064
    // 0x8007F654: nop

    func_8005F064(rdram, ctx);
        goto after_35;
    // 0x8007F654: nop

    after_35:
    // 0x8007F658: bne         $v0, $zero, L_8007F7B8
    if (ctx->r2 != 0) {
        // 0x8007F65C: nop
    
            goto L_8007F7B8;
    }
    // 0x8007F65C: nop

    // 0x8007F660: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007F664: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007F668: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007F66C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8007F670: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x8007F674: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007F678: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F67C: lh          $t4, 0x27AC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X27AC);
    // 0x8007F680: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F684: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F688: lw          $t9, 0x718C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X718C);
    // 0x8007F68C: lw          $t2, 0x70E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70E8);
    // 0x8007F690: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8007F694: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8007F698: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8007F69C: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8007F6A0: subu        $t8, $t3, $t6
    ctx->r24 = SUB32(ctx->r11, ctx->r14);
    // 0x8007F6A4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8007F6A8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007F6AC: nop

    // 0x8007F6B0: bltz        $t0, L_8007F780
    if (SIGNED(ctx->r8) < 0) {
        // 0x8007F6B4: nop
    
            goto L_8007F780;
    }
    // 0x8007F6B4: nop

    // 0x8007F6B8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F6BC: addiu       $t1, $t1, 0x278C
    ctx->r9 = ADD32(ctx->r9, 0X278C);
    // 0x8007F6C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F6C4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F6C8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F6CC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F6D0: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x8007F6D4: jal         0x800BD1FC
    // 0x8007F6D8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_36;
    // 0x8007F6D8: nop

    after_36:
    // 0x8007F6DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F6E0: jal         0x80080910
    // 0x8007F6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_37;
    // 0x8007F6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x8007F6E8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F6EC: lb          $t9, 0x7142($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7142);
    // 0x8007F6F0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007F6F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007F6F8: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x8007F6FC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007F700: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8007F704: lh          $t5, 0x27AC($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X27AC);
    // 0x8007F708: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007F70C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8007F710: lw          $t2, 0x718C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X718C);
    // 0x8007F714: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F718: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8007F71C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F720: subu        $t3, $t2, $t4
    ctx->r11 = SUB32(ctx->r10, ctx->r12);
    // 0x8007F724: sw          $t3, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r11;
    // 0x8007F728: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F72C: lb          $t6, 0x7142($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7142);
    // 0x8007F730: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F734: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8007F738: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8007F73C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007F740: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8007F744: lbu         $a0, 0x27A8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27A8);
    // 0x8007F748: jal         0x8005F0DC
    // 0x8007F74C: nop

    func_8005F0DC(rdram, ctx);
        goto after_38;
    // 0x8007F74C: nop

    after_38:
    // 0x8007F750: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007F754: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007F758: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F75C: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x8007F760: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007F764: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8007F768: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F76C: sh          $t9, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r25;
    // 0x8007F770: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8007F774: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F778: b           L_8007F7B0
    // 0x8007F77C: sh          $t7, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r15;
        goto L_8007F7B0;
    // 0x8007F77C: sh          $t7, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r15;
L_8007F780:
    // 0x8007F780: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007F784: addiu       $t5, $t5, 0x278C
    ctx->r13 = ADD32(ctx->r13, 0X278C);
    // 0x8007F788: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F78C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F790: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F794: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F798: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x8007F79C: jal         0x800BD1FC
    // 0x8007F7A0: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_39;
    // 0x8007F7A0: nop

    after_39:
    // 0x8007F7A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F7A8: jal         0x80080910
    // 0x8007F7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_40;
    // 0x8007F7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
L_8007F7B0:
    // 0x8007F7B0: b           L_8007F83C
    // 0x8007F7B4: nop

        goto L_8007F83C;
    // 0x8007F7B4: nop

L_8007F7B8:
    // 0x8007F7B8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F7BC: addiu       $t2, $t2, 0x278C
    ctx->r10 = ADD32(ctx->r10, 0X278C);
    // 0x8007F7C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007F7C4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007F7C8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8007F7CC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8007F7D0: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x8007F7D4: jal         0x800BD1FC
    // 0x8007F7D8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_41;
    // 0x8007F7D8: nop

    after_41:
    // 0x8007F7DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F7E0: jal         0x80080910
    // 0x8007F7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80080910(rdram, ctx);
        goto after_42;
    // 0x8007F7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8007F7E8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007F7EC: lb          $t4, 0x7142($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X7142);
    // 0x8007F7F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F7F4: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8007F7F8: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x8007F7FC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8007F800: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8007F804: lbu         $a0, 0x27A8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27A8);
    // 0x8007F808: jal         0x8005F0DC
    // 0x8007F80C: nop

    func_8005F0DC(rdram, ctx);
        goto after_43;
    // 0x8007F80C: nop

    after_43:
    // 0x8007F810: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007F814: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007F818: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F81C: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8007F820: sh          $t8, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r24;
    // 0x8007F824: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x8007F828: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F82C: sh          $t0, 0x7136($at)
    MEM_H(0X7136, ctx->r1) = ctx->r8;
    // 0x8007F830: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8007F834: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F838: sh          $t1, 0x7138($at)
    MEM_H(0X7138, ctx->r1) = ctx->r9;
L_8007F83C:
    // 0x8007F83C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007F840: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007F844: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007F848: ori         $t7, $t9, 0x210
    ctx->r15 = ctx->r25 | 0X210;
    // 0x8007F84C: sh          $t7, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r15;
    // 0x8007F850: b           L_8007F868
    // 0x8007F854: nop

        goto L_8007F868;
    // 0x8007F854: nop

L_8007F858:
    // 0x8007F858: b           L_8007F868
    // 0x8007F85C: nop

        goto L_8007F868;
    // 0x8007F85C: nop

    // 0x8007F860: b           L_8007F868
    // 0x8007F864: nop

        goto L_8007F868;
    // 0x8007F864: nop

L_8007F868:
    // 0x8007F868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F86C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007F870: jr          $ra
    // 0x8007F874: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007F874: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
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
RECOMP_FUNC void func_8002A39C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A39C: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x8002A3A0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8002A3A4: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x8002A3A8: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x8002A3AC: swc1        $f31, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002A3B0: swc1        $f30, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f30.u32l;
    // 0x8002A3B4: swc1        $f29, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002A3B8: swc1        $f28, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f28.u32l;
    // 0x8002A3BC: swc1        $f27, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A3C0: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x8002A3C4: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A3C8: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x8002A3CC: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A3D0: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002A3D4: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A3D8: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002A3DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A3E0: nop

    // 0x8002A3E4: swc1        $f4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f4.u32l;
    // 0x8002A3E8: jal         0x800C1680
    // 0x8002A3EC: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x8002A3EC: nop

    after_0:
    // 0x8002A3F0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002A3F4: lw          $t6, 0x306C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X306C);
    // 0x8002A3F8: nop

    // 0x8002A3FC: sw          $t6, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r14;
    // 0x8002A400: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002A404: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x8002A408: nop

    // 0x8002A40C: sh          $t7, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r15;
    // 0x8002A410: lh          $t8, 0x84($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X84);
    // 0x8002A414: sh          $zero, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = 0;
    // 0x8002A418: blez        $t8, L_8002BAB0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8002A41C: nop
    
            goto L_8002BAB0;
    }
    // 0x8002A41C: nop

L_8002A420:
    // 0x8002A420: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8002A424: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002A428: lbu         $t0, 0x10($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X10);
    // 0x8002A42C: nop

    // 0x8002A430: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x8002A434: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002A438: lw          $t2, 0x24F0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X24F0);
    // 0x8002A43C: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
    // 0x8002A440: sw          $t2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r10;
    // 0x8002A444: lh          $t3, 0x18A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X18A);
    // 0x8002A448: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002A44C: addiu       $t5, $t5, 0x24D8
    ctx->r13 = ADD32(ctx->r13, 0X24D8);
    // 0x8002A450: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x8002A454: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8002A458: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
    // 0x8002A45C: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x8002A460: nop

    // 0x8002A464: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8002A468: nop

    // 0x8002A46C: sw          $t8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r24;
    // 0x8002A470: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8002A474: nop

    // 0x8002A478: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8002A47C: nop

    // 0x8002A480: sh          $t0, 0x188($sp)
    MEM_H(0X188, ctx->r29) = ctx->r8;
    // 0x8002A484: lw          $t1, 0x148($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X148);
    // 0x8002A488: nop

    // 0x8002A48C: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8002A490: nop

    // 0x8002A494: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x8002A498: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x8002A49C: nop

    // 0x8002A4A0: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8002A4A4: nop

    // 0x8002A4A8: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002A4AC: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x8002A4B0: nop

    // 0x8002A4B4: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x8002A4B8: nop

    // 0x8002A4BC: sh          $t4, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r12;
    // 0x8002A4C0: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x8002A4C4: nop

    // 0x8002A4C8: lwc1        $f10, 0x8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8002A4CC: nop

    // 0x8002A4D0: swc1        $f10, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f10.u32l;
    // 0x8002A4D4: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002A4D8: jal         0x8002BBE8
    // 0x8002A4DC: nop

    func_8002BBE8(rdram, ctx);
        goto after_1;
    // 0x8002A4DC: nop

    after_1:
    // 0x8002A4E0: sh          $v0, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r2;
    // 0x8002A4E4: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x8002A4E8: nop

    // 0x8002A4EC: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x8002A4F0: nop

    // 0x8002A4F4: sh          $t7, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r15;
    // 0x8002A4F8: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8002A4FC: nop

    // 0x8002A500: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002A504: nop

    // 0x8002A508: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8002A50C: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x8002A510: nop

    // 0x8002A514: lwc1        $f18, 0x4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8002A518: nop

    // 0x8002A51C: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
    // 0x8002A520: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x8002A524: nop

    // 0x8002A528: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8002A52C: nop

    // 0x8002A530: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8002A534: lw          $t1, 0x140($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X140);
    // 0x8002A538: nop

    // 0x8002A53C: lbu         $t2, 0x14($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X14);
    // 0x8002A540: nop

    // 0x8002A544: sb          $t2, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r10;
    // 0x8002A548: lhu         $t3, 0x180($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X180);
    // 0x8002A54C: nop

    // 0x8002A550: sltiu       $at, $t3, 0x38
    ctx->r1 = ctx->r11 < 0X38 ? 1 : 0;
    // 0x8002A554: beq         $at, $zero, L_8002B978
    if (ctx->r1 == 0) {
        // 0x8002A558: nop
    
            goto L_8002B978;
    }
    // 0x8002A558: nop

    // 0x8002A55C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002A560: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002A564: addu        $at, $at, $t3
    gpr jr_addend_8002A570 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8002A568: lw          $t3, -0x1A38($at)
    ctx->r11 = ADD32(ctx->r1, -0X1A38);
    // 0x8002A56C: nop

    // 0x8002A570: jr          $t3
    // 0x8002A574: nop

    switch (jr_addend_8002A570 >> 2) {
        case 0: goto L_8002A578; break;
        case 1: goto L_8002B044; break;
        case 2: goto L_8002B978; break;
        case 3: goto L_8002B978; break;
        case 4: goto L_8002B978; break;
        case 5: goto L_8002B06C; break;
        case 6: goto L_8002B084; break;
        case 7: goto L_8002B978; break;
        case 8: goto L_8002B978; break;
        case 9: goto L_8002B978; break;
        case 10: goto L_8002B06C; break;
        case 11: goto L_8002B150; break;
        case 12: goto L_8002B978; break;
        case 13: goto L_8002B978; break;
        case 14: goto L_8002B978; break;
        case 15: goto L_8002B830; break;
        case 16: goto L_8002B978; break;
        case 17: goto L_8002B978; break;
        case 18: goto L_8002B978; break;
        case 19: goto L_8002B978; break;
        case 20: goto L_8002B06C; break;
        case 21: goto L_8002B238; break;
        case 22: goto L_8002B978; break;
        case 23: goto L_8002B978; break;
        case 24: goto L_8002B978; break;
        case 25: goto L_8002B06C; break;
        case 26: goto L_8002B354; break;
        case 27: goto L_8002B978; break;
        case 28: goto L_8002B978; break;
        case 29: goto L_8002B978; break;
        case 30: goto L_8002B06C; break;
        case 31: goto L_8002B4AC; break;
        case 32: goto L_8002B588; break;
        case 33: goto L_8002B978; break;
        case 34: goto L_8002B978; break;
        case 35: goto L_8002B06C; break;
        case 36: goto L_8002B5D8; break;
        case 37: goto L_8002B978; break;
        case 38: goto L_8002B978; break;
        case 39: goto L_8002B978; break;
        case 40: goto L_8002B6F8; break;
        case 41: goto L_8002B978; break;
        case 42: goto L_8002B978; break;
        case 43: goto L_8002B978; break;
        case 44: goto L_8002B978; break;
        case 45: goto L_8002B06C; break;
        case 46: goto L_8002B770; break;
        case 47: goto L_8002B978; break;
        case 48: goto L_8002B978; break;
        case 49: goto L_8002B978; break;
        case 50: goto L_8002B7B0; break;
        case 51: goto L_8002B978; break;
        case 52: goto L_8002B978; break;
        case 53: goto L_8002B978; break;
        case 54: goto L_8002B978; break;
        case 55: goto L_8002B8F4; break;
        default: switch_error(__func__, 0x8002A570, 0x800EE5C8);
    }
    // 0x8002A574: nop

L_8002A578:
    // 0x8002A578: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002A57C: nop

    // 0x8002A580: swc1        $f6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f6.u32l;
    // 0x8002A584: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8002A588: nop

    // 0x8002A58C: swc1        $f8, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f8.u32l;
    // 0x8002A590: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8002A594: nop

    // 0x8002A598: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x8002A59C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002A5A0: lwc1        $f18, -0x71C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002A5A4: lwc1        $f16, 0x15C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002A5A8: nop

    // 0x8002A5AC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002A5B0: swc1        $f16, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f16.u32l;
    // 0x8002A5B4: bc1f        L_8002A720
    if (!c1cs) {
        // 0x8002A5B8: nop
    
            goto L_8002A720;
    }
    // 0x8002A5B8: nop

    // 0x8002A5BC: lh          $t4, 0x184($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X184);
    // 0x8002A5C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002A5C4: bne         $t4, $at, L_8002A618
    if (ctx->r12 != ctx->r1) {
        // 0x8002A5C8: nop
    
            goto L_8002A618;
    }
    // 0x8002A5C8: nop

    // 0x8002A5CC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002A5D0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8002A5D4: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x8002A5D8: lh          $t6, 0xA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XA);
    // 0x8002A5DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002A5E0: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8002A5E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002A5E8: lwc1        $f9, -0x1958($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1958);
    // 0x8002A5EC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002A5F0: lwc1        $f8, -0x1954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1954);
    // 0x8002A5F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002A5F8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002A5FC: lwc1        $f17, -0x1950($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1950);
    // 0x8002A600: lwc1        $f16, -0x194C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X194C);
    // 0x8002A604: nop

    // 0x8002A608: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8002A60C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002A610: b           L_8002A628
    // 0x8002A614: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
        goto L_8002A628;
    // 0x8002A614: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
L_8002A618:
    // 0x8002A618: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8002A61C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002A620: nop

    // 0x8002A624: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
L_8002A628:
    // 0x8002A628: lh          $t9, 0x184($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X184);
    // 0x8002A62C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002A630: bne         $t9, $at, L_8002A68C
    if (ctx->r25 != ctx->r1) {
        // 0x8002A634: nop
    
            goto L_8002A68C;
    }
    // 0x8002A634: nop

    // 0x8002A638: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002A63C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002A640: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002A644: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002A648: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x8002A64C: nop

    // 0x8002A650: bc1f        L_8002A674
    if (!c1cs) {
        // 0x8002A654: nop
    
            goto L_8002A674;
    }
    // 0x8002A654: nop

    // 0x8002A658: lw          $t0, 0x150($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X150);
    // 0x8002A65C: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002A660: lwc1        $f18, 0xF0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x8002A664: nop

    // 0x8002A668: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8002A66C: b           L_8002A68C
    // 0x8002A670: swc1        $f6, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f6.u32l;
        goto L_8002A68C;
    // 0x8002A670: swc1        $f6, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f6.u32l;
L_8002A674:
    // 0x8002A674: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x8002A678: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002A67C: lwc1        $f8, 0xF0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XF0);
    // 0x8002A680: nop

    // 0x8002A684: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A688: swc1        $f16, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f16.u32l;
L_8002A68C:
    // 0x8002A68C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002A690: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002A694: lwc1        $f18, 0x154($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8002A698: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002A69C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002A6A0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002A6A4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002A6A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002A6AC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002A6B0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002A6B4: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8002A6B8: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x8002A6BC: bc1f        L_8002A6D4
    if (!c1cs) {
        // 0x8002A6C0: nop
    
            goto L_8002A6D4;
    }
    // 0x8002A6C0: nop

    // 0x8002A6C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002A6C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A6CC: nop

    // 0x8002A6D0: swc1        $f4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f4.u32l;
L_8002A6D4:
    // 0x8002A6D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002A6D8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002A6DC: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002A6E0: lwc1        $f16, 0x17C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8002A6E4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002A6E8: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8002A6EC: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002A6F0: swc1        $f18, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f18.u32l;
    // 0x8002A6F4: lwc1        $f4, 0x178($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002A6F8: nop

    // 0x8002A6FC: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8002A700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002A704: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002A708: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002A70C: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002A710: mul.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002A714: add.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8002A718: swc1        $f20, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f20.u32l;
    // 0x8002A71C: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_8002A720:
    // 0x8002A720: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8002A724: addiu       $t2, $t2, 0x5B0
    ctx->r10 = ADD32(ctx->r10, 0X5B0);
    // 0x8002A728: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    // 0x8002A72C: sh          $zero, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = 0;
L_8002A730:
    // 0x8002A730: lh          $t4, 0x18E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X18E);
    // 0x8002A734: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8002A738: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002A73C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002A740: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8002A744: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8002A748: lh          $t6, 0x18C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X18C);
    // 0x8002A74C: nop

    // 0x8002A750: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8002A754: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002A758: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002A75C: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8002A760: bne         $at, $zero, L_8002A730
    if (ctx->r1 != 0) {
        // 0x8002A764: sh          $t8, 0x18C($sp)
        MEM_H(0X18C, ctx->r29) = ctx->r24;
            goto L_8002A730;
    }
    // 0x8002A764: sh          $t8, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r24;
    // 0x8002A768: lh          $t1, 0x18A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X18A);
    // 0x8002A76C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002A770: addiu       $t4, $t4, 0x24D8
    ctx->r12 = ADD32(ctx->r12, 0X24D8);
    // 0x8002A774: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8002A778: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8002A77C: lw          $a1, 0x18($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X18);
    // 0x8002A780: lw          $a2, 0x1C($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X1C);
    // 0x8002A784: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x8002A788: jal         0x800B35D4
    // 0x8002A78C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800B35D4(rdram, ctx);
        goto after_2;
    // 0x8002A78C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8002A790: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8002A794: lwc1        $f8, 0x164($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002A798: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8002A79C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002A7A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002A7A4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A7A8: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8002A7AC: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
    // 0x8002A7B0: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8002A7B4: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002A7B8: lwc1        $f18, 0x8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002A7BC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002A7C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002A7C4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8002A7C8: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8002A7CC: swc1        $f16, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f16.u32l;
    // 0x8002A7D0: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A7D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002A7D8: nop

    // 0x8002A7DC: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8002A7E0: nop

    // 0x8002A7E4: bc1f        L_8002A7F4
    if (!c1cs) {
        // 0x8002A7E8: nop
    
            goto L_8002A7F4;
    }
    // 0x8002A7E8: nop

    // 0x8002A7EC: b           L_8002A800
    // 0x8002A7F0: mov.s       $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = ctx->f10.fl;
        goto L_8002A800;
    // 0x8002A7F0: mov.s       $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = ctx->f10.fl;
L_8002A7F4:
    // 0x8002A7F4: lwc1        $f24, 0x16C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A7F8: nop

    // 0x8002A7FC: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
L_8002A800:
    // 0x8002A800: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A804: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A808: nop

    // 0x8002A80C: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8002A810: nop

    // 0x8002A814: bc1f        L_8002A824
    if (!c1cs) {
        // 0x8002A818: nop
    
            goto L_8002A824;
    }
    // 0x8002A818: nop

    // 0x8002A81C: b           L_8002A830
    // 0x8002A820: mov.s       $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = ctx->f4.fl;
        goto L_8002A830;
    // 0x8002A820: mov.s       $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = ctx->f4.fl;
L_8002A824:
    // 0x8002A824: lwc1        $f22, 0x168($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A828: nop

    // 0x8002A82C: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
L_8002A830:
    // 0x8002A830: sub.s       $f6, $f24, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f24.fl - ctx->f22.fl;
    // 0x8002A834: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002A838: nop

    // 0x8002A83C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8002A840: nop

    // 0x8002A844: bc1f        L_8002A8B4
    if (!c1cs) {
        // 0x8002A848: nop
    
            goto L_8002A8B4;
    }
    // 0x8002A848: nop

    // 0x8002A84C: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A850: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002A854: nop

    // 0x8002A858: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8002A85C: nop

    // 0x8002A860: bc1f        L_8002A870
    if (!c1cs) {
        // 0x8002A864: nop
    
            goto L_8002A870;
    }
    // 0x8002A864: nop

    // 0x8002A868: b           L_8002A87C
    // 0x8002A86C: mov.s       $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    ctx->f28.fl = ctx->f18.fl;
        goto L_8002A87C;
    // 0x8002A86C: mov.s       $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    ctx->f28.fl = ctx->f18.fl;
L_8002A870:
    // 0x8002A870: lwc1        $f28, 0x16C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A874: nop

    // 0x8002A878: neg.s       $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f28.fl = -ctx->f28.fl;
L_8002A87C:
    // 0x8002A87C: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A880: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A884: nop

    // 0x8002A888: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8002A88C: nop

    // 0x8002A890: bc1f        L_8002A8A0
    if (!c1cs) {
        // 0x8002A894: nop
    
            goto L_8002A8A0;
    }
    // 0x8002A894: nop

    // 0x8002A898: b           L_8002A8AC
    // 0x8002A89C: mov.s       $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    ctx->f26.fl = ctx->f8.fl;
        goto L_8002A8AC;
    // 0x8002A89C: mov.s       $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    ctx->f26.fl = ctx->f8.fl;
L_8002A8A0:
    // 0x8002A8A0: lwc1        $f26, 0x168($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A8A4: nop

    // 0x8002A8A8: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = -ctx->f26.fl;
L_8002A8AC:
    // 0x8002A8AC: b           L_8002A928
    // 0x8002A8B0: sub.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f26.fl;
        goto L_8002A928;
    // 0x8002A8B0: sub.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f26.fl;
L_8002A8B4:
    // 0x8002A8B4: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A8B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002A8BC: nop

    // 0x8002A8C0: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8002A8C4: nop

    // 0x8002A8C8: bc1f        L_8002A8D8
    if (!c1cs) {
        // 0x8002A8CC: nop
    
            goto L_8002A8D8;
    }
    // 0x8002A8CC: nop

    // 0x8002A8D0: b           L_8002A8E8
    // 0x8002A8D4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
        goto L_8002A8E8;
    // 0x8002A8D4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
L_8002A8D8:
    // 0x8002A8D8: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A8DC: nop

    // 0x8002A8E0: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8002A8E4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
L_8002A8E8:
    // 0x8002A8E8: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A8EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A8F0: nop

    // 0x8002A8F4: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8002A8F8: nop

    // 0x8002A8FC: bc1f        L_8002A90C
    if (!c1cs) {
        // 0x8002A900: nop
    
            goto L_8002A90C;
    }
    // 0x8002A900: nop

    // 0x8002A904: b           L_8002A918
    // 0x8002A908: mov.s       $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    ctx->f30.fl = ctx->f4.fl;
        goto L_8002A918;
    // 0x8002A908: mov.s       $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    ctx->f30.fl = ctx->f4.fl;
L_8002A90C:
    // 0x8002A90C: lwc1        $f30, 0x168($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A910: nop

    // 0x8002A914: neg.s       $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = -ctx->f30.fl;
L_8002A918:
    // 0x8002A918: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8002A91C: nop

    // 0x8002A920: sub.s       $f20, $f16, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f30.fl;
    // 0x8002A924: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8002A928:
    // 0x8002A928: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002A92C: lwc1        $f11, -0x1948($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1948);
    // 0x8002A930: lwc1        $f10, -0x1944($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1944);
    // 0x8002A934: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x8002A938: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8002A93C: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8002A940: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
    // 0x8002A944: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A948: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x8002A94C: lw          $a3, 0x168($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X168);
    // 0x8002A950: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8002A954: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8002A958: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x8002A95C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002A960: jal         0x800782A8
    // 0x8002A964: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800782A8(rdram, ctx);
        goto after_3;
    // 0x8002A964: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8002A968: beq         $v0, $zero, L_8002AC08
    if (ctx->r2 == 0) {
        // 0x8002A96C: nop
    
            goto L_8002AC08;
    }
    // 0x8002A96C: nop

    // 0x8002A970: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002A974: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002A978: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002A97C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002A980: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002A984: nop

    // 0x8002A988: bc1f        L_8002AABC
    if (!c1cs) {
        // 0x8002A98C: nop
    
            goto L_8002AABC;
    }
    // 0x8002A98C: nop

    // 0x8002A990: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002A994: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8002A998: nop

    // 0x8002A99C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8002A9A0: swc1        $f4, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f4.u32l;
    // 0x8002A9A4: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002A9A8: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002A9AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002A9B0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002A9B4: c.eq.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d == ctx->f10.d;
    // 0x8002A9B8: nop

    // 0x8002A9BC: bc1t        L_8002AA5C
    if (c1cs) {
        // 0x8002A9C0: nop
    
            goto L_8002AA5C;
    }
    // 0x8002A9C0: nop

    // 0x8002A9C4: lh          $t8, 0x188($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X188);
    // 0x8002A9C8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8002A9CC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002A9D0: lbu         $t9, -0x4861($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4861);
    // 0x8002A9D4: nop

    // 0x8002A9D8: sh          $t9, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r25;
    // 0x8002A9DC: jal         0x800220F4
    // 0x8002A9E0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800220F4(rdram, ctx);
        goto after_4;
    // 0x8002A9E0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_4:
    // 0x8002A9E4: lh          $a0, 0x182($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X182);
    // 0x8002A9E8: jal         0x800B9000
    // 0x8002A9EC: nop

    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x8002A9EC: nop

    after_5:
    // 0x8002A9F0: lwc1        $f18, 0x164($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002A9F4: nop

    // 0x8002A9F8: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
    // 0x8002A9FC: lh          $t0, 0x186($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X186);
    // 0x8002AA00: nop

    // 0x8002AA04: beq         $t0, $zero, L_8002AA48
    if (ctx->r8 == 0) {
        // 0x8002AA08: nop
    
            goto L_8002AA48;
    }
    // 0x8002AA08: nop

    // 0x8002AA0C: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AA10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002AA14: nop

    // 0x8002AA18: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8002AA1C: nop

    // 0x8002AA20: bc1f        L_8002AA30
    if (!c1cs) {
        // 0x8002AA24: nop
    
            goto L_8002AA30;
    }
    // 0x8002AA24: nop

    // 0x8002AA28: b           L_8002AA40
    // 0x8002AA2C: nop

        goto L_8002AA40;
    // 0x8002AA2C: nop

L_8002AA30:
    // 0x8002AA30: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AA34: nop

    // 0x8002AA38: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x8002AA3C: swc1        $f6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f6.u32l;
L_8002AA40:
    // 0x8002AA40: b           L_8002AA54
    // 0x8002AA44: nop

        goto L_8002AA54;
    // 0x8002AA44: nop

L_8002AA48:
    // 0x8002AA48: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002AA4C: nop

    // 0x8002AA50: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
L_8002AA54:
    // 0x8002AA54: b           L_8002AAB4
    // 0x8002AA58: nop

        goto L_8002AAB4;
    // 0x8002AA58: nop

L_8002AA5C:
    // 0x8002AA5C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8002AA60: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AA64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002AA68: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002AA6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AA70: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AA74: mul.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8002AA78: lwc1        $f6, 0x160($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002AA7C: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002AA80: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AA84: add.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f10.d + ctx->f16.d;
    // 0x8002AA88: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AA8C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8002AA90: swc1        $f18, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f18.u32l;
    // 0x8002AA94: bc1f        L_8002AAA8
    if (!c1cs) {
        // 0x8002AA98: nop
    
            goto L_8002AAA8;
    }
    // 0x8002AA98: nop

    // 0x8002AA9C: lwc1        $f6, 0x164($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002AAA0: b           L_8002AAB4
    // 0x8002AAA4: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
        goto L_8002AAB4;
    // 0x8002AAA4: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
L_8002AAA8:
    // 0x8002AAA8: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002AAAC: nop

    // 0x8002AAB0: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_8002AAB4:
    // 0x8002AAB4: b           L_8002AC08
    // 0x8002AAB8: nop

        goto L_8002AC08;
    // 0x8002AAB8: nop

L_8002AABC:
    // 0x8002AABC: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002AAC0: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8002AAC4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AAC8: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002AACC: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8002AAD0: nop

    // 0x8002AAD4: bc1f        L_8002AC08
    if (!c1cs) {
        // 0x8002AAD8: nop
    
            goto L_8002AC08;
    }
    // 0x8002AAD8: nop

    // 0x8002AADC: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8002AAE0: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8002AAE4: nop

    // 0x8002AAE8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002AAEC: swc1        $f10, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f10.u32l;
    // 0x8002AAF0: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AAF4: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8002AAF8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AAFC: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002AB00: c.eq.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d == ctx->f18.d;
    // 0x8002AB04: nop

    // 0x8002AB08: bc1t        L_8002ABB0
    if (c1cs) {
        // 0x8002AB0C: nop
    
            goto L_8002ABB0;
    }
    // 0x8002AB0C: nop

    // 0x8002AB10: lh          $t1, 0x188($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X188);
    // 0x8002AB14: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8002AB18: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002AB1C: lbu         $t2, -0x4861($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X4861);
    // 0x8002AB20: nop

    // 0x8002AB24: sh          $t2, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r10;
    // 0x8002AB28: jal         0x800220F4
    // 0x8002AB2C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800220F4(rdram, ctx);
        goto after_6;
    // 0x8002AB2C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x8002AB30: lh          $a0, 0x182($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X182);
    // 0x8002AB34: jal         0x800B9000
    // 0x8002AB38: nop

    func_800B9000(rdram, ctx);
        goto after_7;
    // 0x8002AB38: nop

    after_7:
    // 0x8002AB3C: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002AB40: nop

    // 0x8002AB44: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8002AB48: lh          $t4, 0x186($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X186);
    // 0x8002AB4C: nop

    // 0x8002AB50: beq         $t4, $zero, L_8002AB9C
    if (ctx->r12 == 0) {
        // 0x8002AB54: nop
    
            goto L_8002AB9C;
    }
    // 0x8002AB54: nop

    // 0x8002AB58: lwc1        $f6, 0x170($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AB5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002AB60: nop

    // 0x8002AB64: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8002AB68: nop

    // 0x8002AB6C: bc1f        L_8002AB80
    if (!c1cs) {
        // 0x8002AB70: nop
    
            goto L_8002AB80;
    }
    // 0x8002AB70: nop

    // 0x8002AB74: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = -ctx->f6.fl;
    // 0x8002AB78: b           L_8002AB94
    // 0x8002AB7C: swc1        $f16, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f16.u32l;
        goto L_8002AB94;
    // 0x8002AB7C: swc1        $f16, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f16.u32l;
L_8002AB80:
    // 0x8002AB80: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AB84: nop

    // 0x8002AB88: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x8002AB8C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8002AB90: swc1        $f4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f4.u32l;
L_8002AB94:
    // 0x8002AB94: b           L_8002ABA8
    // 0x8002AB98: nop

        goto L_8002ABA8;
    // 0x8002AB98: nop

L_8002AB9C:
    // 0x8002AB9C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002ABA0: nop

    // 0x8002ABA4: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
L_8002ABA8:
    // 0x8002ABA8: b           L_8002AC08
    // 0x8002ABAC: nop

        goto L_8002AC08;
    // 0x8002ABAC: nop

L_8002ABB0:
    // 0x8002ABB0: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8002ABB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002ABB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002ABBC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002ABC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002ABC4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002ABC8: mul.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002ABCC: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002ABD0: lwc1        $f8, 0x164($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002ABD4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002ABD8: sub.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d - ctx->f18.d;
    // 0x8002ABDC: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8002ABE0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8002ABE4: swc1        $f6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f6.u32l;
    // 0x8002ABE8: bc1f        L_8002ABFC
    if (!c1cs) {
        // 0x8002ABEC: nop
    
            goto L_8002ABFC;
    }
    // 0x8002ABEC: nop

    // 0x8002ABF0: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002ABF4: b           L_8002AC08
    // 0x8002ABF8: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
        goto L_8002AC08;
    // 0x8002ABF8: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
L_8002ABFC:
    // 0x8002ABFC: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002AC00: nop

    // 0x8002AC04: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_8002AC08:
    // 0x8002AC08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AC0C: lwc1        $f16, -0x71C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AC10: lwc1        $f18, 0x17C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8002AC14: nop

    // 0x8002AC18: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002AC1C: nop

    // 0x8002AC20: bc1f        L_8002AC3C
    if (!c1cs) {
        // 0x8002AC24: nop
    
            goto L_8002AC3C;
    }
    // 0x8002AC24: nop

    // 0x8002AC28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AC2C: lwc1        $f6, -0x71C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AC30: nop

    // 0x8002AC34: swc1        $f6, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f6.u32l;
    // 0x8002AC38: swc1        $f6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f6.u32l;
L_8002AC3C:
    // 0x8002AC3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AC40: lwc1        $f4, -0x71C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AC44: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8002AC48: nop

    // 0x8002AC4C: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x8002AC50: nop

    // 0x8002AC54: bc1f        L_8002B024
    if (!c1cs) {
        // 0x8002AC58: nop
    
            goto L_8002B024;
    }
    // 0x8002AC58: nop

    // 0x8002AC5C: lwc1        $f10, 0x178($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002AC60: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002AC64: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002AC68: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002AC6C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AC70: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8002AC74: nop

    // 0x8002AC78: bc1f        L_8002ACAC
    if (!c1cs) {
        // 0x8002AC7C: nop
    
            goto L_8002ACAC;
    }
    // 0x8002AC7C: nop

    // 0x8002AC80: lh          $t3, 0x188($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X188);
    // 0x8002AC84: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8002AC88: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8002AC8C: lbu         $t5, -0x4861($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4861);
    // 0x8002AC90: nop

    // 0x8002AC94: sh          $t5, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r13;
    // 0x8002AC98: jal         0x800220F4
    // 0x8002AC9C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800220F4(rdram, ctx);
        goto after_8;
    // 0x8002AC9C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_8:
    // 0x8002ACA0: lh          $a0, 0x182($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X182);
    // 0x8002ACA4: jal         0x800B9000
    // 0x8002ACA8: nop

    func_800B9000(rdram, ctx);
        goto after_9;
    // 0x8002ACA8: nop

    after_9:
L_8002ACAC:
    // 0x8002ACAC: lh          $t7, 0x184($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X184);
    // 0x8002ACB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002ACB4: bne         $t7, $at, L_8002AE94
    if (ctx->r15 != ctx->r1) {
        // 0x8002ACB8: nop
    
            goto L_8002AE94;
    }
    // 0x8002ACB8: nop

    // 0x8002ACBC: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002ACC0: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8002ACC4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002ACC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002ACCC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002ACD0: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8002ACD4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8002ACD8: swc1        $f18, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f18.u32l;
    // 0x8002ACDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002ACE0: lwc1        $f16, -0x71C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002ACE4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002ACE8: lwc1        $f9, -0x1940($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1940);
    // 0x8002ACEC: lwc1        $f8, -0x193C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X193C);
    // 0x8002ACF0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002ACF4: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x8002ACF8: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8002ACFC: swc1        $f10, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f10.u32l;
    // 0x8002AD00: swc1        $f10, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f10.u32l;
    // 0x8002AD04: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002AD08: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002AD0C: lwc1        $f7, -0x1938($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1938);
    // 0x8002AD10: lwc1        $f6, -0x1934($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1934);
    // 0x8002AD14: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8002AD18: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x8002AD1C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8002AD20: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AD24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AD28: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AD2C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002AD30: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8002AD34: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8002AD38: bc1f        L_8002AD4C
    if (!c1cs) {
        // 0x8002AD3C: nop
    
            goto L_8002AD4C;
    }
    // 0x8002AD3C: nop

    // 0x8002AD40: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002AD44: jal         0x8009A2F4
    // 0x8002AD48: nop

    func_8009A2F4(rdram, ctx);
        goto after_10;
    // 0x8002AD48: nop

    after_10:
L_8002AD4C:
    // 0x8002AD4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002AD50: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AD54: lwc1        $f9, -0x1930($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1930);
    // 0x8002AD58: lwc1        $f8, -0x192C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X192C);
    // 0x8002AD5C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002AD60: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002AD64: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AD68: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8002AD6C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8002AD70: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x8002AD74: bc1f        L_8002ADA0
    if (!c1cs) {
        // 0x8002AD78: nop
    
            goto L_8002ADA0;
    }
    // 0x8002AD78: nop

    // 0x8002AD7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002AD80: lwc1        $f7, -0x1928($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1928);
    // 0x8002AD84: lwc1        $f6, -0x1924($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1924);
    // 0x8002AD88: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AD8C: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x8002AD90: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AD94: swc1        $f4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f4.u32l;
    // 0x8002AD98: b           L_8002ADC4
    // 0x8002AD9C: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
        goto L_8002ADC4;
    // 0x8002AD9C: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_8002ADA0:
    // 0x8002ADA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002ADA4: lwc1        $f18, 0x170($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002ADA8: lwc1        $f17, -0x1920($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1920);
    // 0x8002ADAC: lwc1        $f16, -0x191C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X191C);
    // 0x8002ADB0: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8002ADB4: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8002ADB8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002ADBC: swc1        $f8, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f8.u32l;
    // 0x8002ADC0: neg.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = -ctx->f8.fl;
L_8002ADC4:
    // 0x8002ADC4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002ADC8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002ADCC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002ADD0: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x8002ADD4: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8002ADD8: nop

    // 0x8002ADDC: bc1f        L_8002AE8C
    if (!c1cs) {
        // 0x8002ADE0: nop
    
            goto L_8002AE8C;
    }
    // 0x8002ADE0: nop

    // 0x8002ADE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002ADE8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002ADEC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002ADF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002ADF4: nop

    // 0x8002ADF8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002ADFC: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x8002AE00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002AE04: nop

    // 0x8002AE08: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8002AE0C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002AE10: beq         $t8, $zero, L_8002AE64
    if (ctx->r24 == 0) {
        // 0x8002AE14: nop
    
            goto L_8002AE64;
    }
    // 0x8002AE14: nop

    // 0x8002AE18: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002AE1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002AE20: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002AE24: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002AE28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002AE2C: nop

    // 0x8002AE30: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002AE34: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002AE38: nop

    // 0x8002AE3C: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8002AE40: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002AE44: bne         $t8, $zero, L_8002AE5C
    if (ctx->r24 != 0) {
        // 0x8002AE48: nop
    
            goto L_8002AE5C;
    }
    // 0x8002AE48: nop

    // 0x8002AE4C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8002AE50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002AE54: b           L_8002AE74
    // 0x8002AE58: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8002AE74;
    // 0x8002AE58: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8002AE5C:
    // 0x8002AE5C: b           L_8002AE74
    // 0x8002AE60: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8002AE74;
    // 0x8002AE60: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8002AE64:
    // 0x8002AE64: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8002AE68: nop

    // 0x8002AE6C: bltz        $t8, L_8002AE5C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8002AE70: nop
    
            goto L_8002AE5C;
    }
    // 0x8002AE70: nop

L_8002AE74:
    // 0x8002AE74: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002AE78: sb          $t8, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r24;
    // 0x8002AE7C: nop

    // 0x8002AE80: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002AE84: jal         0x8009A2F4
    // 0x8002AE88: nop

    func_8009A2F4(rdram, ctx);
        goto after_11;
    // 0x8002AE88: nop

    after_11:
L_8002AE8C:
    // 0x8002AE8C: b           L_8002B024
    // 0x8002AE90: nop

        goto L_8002B024;
    // 0x8002AE90: nop

L_8002AE94:
    // 0x8002AE94: lwc1        $f4, 0x158($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8002AE98: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AE9C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002AEA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002AEA4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8002AEA8: mul.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8002AEAC: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002AEB0: nop

    // 0x8002AEB4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AEB8: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x8002AEBC: nop

    // 0x8002AEC0: bc1f        L_8002AF88
    if (!c1cs) {
        // 0x8002AEC4: nop
    
            goto L_8002AF88;
    }
    // 0x8002AEC4: nop

    // 0x8002AEC8: lh          $t9, 0x186($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X186);
    // 0x8002AECC: nop

    // 0x8002AED0: bne         $t9, $zero, L_8002AEE8
    if (ctx->r25 != 0) {
        // 0x8002AED4: nop
    
            goto L_8002AEE8;
    }
    // 0x8002AED4: nop

    // 0x8002AED8: lh          $t0, 0x184($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X184);
    // 0x8002AEDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AEE0: bne         $t0, $at, L_8002AF58
    if (ctx->r8 != ctx->r1) {
        // 0x8002AEE4: nop
    
            goto L_8002AF58;
    }
    // 0x8002AEE4: nop

L_8002AEE8:
    // 0x8002AEE8: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002AEEC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8002AEF0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AEF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AEF8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AEFC: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8002AF00: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8002AF04: swc1        $f8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f8.u32l;
    // 0x8002AF08: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AF0C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AF10: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002AF14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002AF18: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002AF1C: mul.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8002AF20: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8002AF24: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x8002AF28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AF2C: lwc1        $f8, -0x71C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AF30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002AF34: lwc1        $f7, -0x1918($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1918);
    // 0x8002AF38: lwc1        $f6, -0x1914($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1914);
    // 0x8002AF3C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AF40: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x8002AF44: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8002AF48: swc1        $f18, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f18.u32l;
    // 0x8002AF4C: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002AF50: b           L_8002AF80
    // 0x8002AF54: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
        goto L_8002AF80;
    // 0x8002AF54: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
L_8002AF58:
    // 0x8002AF58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002AF5C: nop

    // 0x8002AF60: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x8002AF64: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x8002AF68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AF6C: lwc1        $f8, -0x71C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AF70: nop

    // 0x8002AF74: swc1        $f8, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f8.u32l;
    // 0x8002AF78: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002AF7C: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
L_8002AF80:
    // 0x8002AF80: b           L_8002B024
    // 0x8002AF84: nop

        goto L_8002B024;
    // 0x8002AF84: nop

L_8002AF88:
    // 0x8002AF88: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002AF8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002AF90: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002AF94: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002AF98: nop

    // 0x8002AF9C: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002AFA0: swc1        $f16, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f16.u32l;
    // 0x8002AFA4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002AFA8: swc1        $f16, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f16.u32l;
    // 0x8002AFAC: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8002AFB0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8002AFB4: beq         $t2, $zero, L_8002B008
    if (ctx->r10 == 0) {
        // 0x8002AFB8: nop
    
            goto L_8002B008;
    }
    // 0x8002AFB8: nop

    // 0x8002AFBC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002AFC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002AFC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002AFC8: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8002AFCC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002AFD0: nop

    // 0x8002AFD4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002AFD8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002AFDC: nop

    // 0x8002AFE0: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8002AFE4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8002AFE8: bne         $t2, $zero, L_8002B000
    if (ctx->r10 != 0) {
        // 0x8002AFEC: nop
    
            goto L_8002B000;
    }
    // 0x8002AFEC: nop

    // 0x8002AFF0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8002AFF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002AFF8: b           L_8002B018
    // 0x8002AFFC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8002B018;
    // 0x8002AFFC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8002B000:
    // 0x8002B000: b           L_8002B018
    // 0x8002B004: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8002B018;
    // 0x8002B004: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8002B008:
    // 0x8002B008: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8002B00C: nop

    // 0x8002B010: bltz        $t2, L_8002B000
    if (SIGNED(ctx->r10) < 0) {
        // 0x8002B014: nop
    
            goto L_8002B000;
    }
    // 0x8002B014: nop

L_8002B018:
    // 0x8002B018: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002B01C: sb          $t2, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r10;
    // 0x8002B020: nop

L_8002B024:
    // 0x8002B024: lwc1        $f4, 0x170($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002B028: nop

    // 0x8002B02C: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x8002B030: lwc1        $f18, 0x178($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002B034: nop

    // 0x8002B038: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
    // 0x8002B03C: b           L_8002B978
    // 0x8002B040: nop

        goto L_8002B978;
    // 0x8002B040: nop

L_8002B044:
    // 0x8002B044: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B048: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B04C: nop

    // 0x8002B050: swc1        $f10, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f10.u32l;
    // 0x8002B054: lwc1        $f8, 0x15C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B058: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x8002B05C: nop

    // 0x8002B060: swc1        $f8, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f8.u32l;
    // 0x8002B064: b           L_8002B978
    // 0x8002B068: nop

        goto L_8002B978;
    // 0x8002B068: nop

L_8002B06C:
    // 0x8002B06C: lhu         $t5, 0x180($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X180);
    // 0x8002B070: nop

    // 0x8002B074: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8002B078: sh          $t7, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r15;
    // 0x8002B07C: b           L_8002B978
    // 0x8002B080: nop

        goto L_8002B978;
    // 0x8002B080: nop

L_8002B084:
    // 0x8002B084: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B088: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B08C: jal         0x800B26E0
    // 0x8002B090: nop

    func_800B26E0(rdram, ctx);
        goto after_12;
    // 0x8002B090: nop

    after_12:
    // 0x8002B094: bgez        $v0, L_8002B120
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B098: nop
    
            goto L_8002B120;
    }
    // 0x8002B098: nop

    // 0x8002B09C: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B0A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002B0A4: nop

    // 0x8002B0A8: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8002B0AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002B0B0: nop

    // 0x8002B0B4: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8002B0B8: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B0BC: jal         0x800294D4
    // 0x8002B0C0: nop

    func_800294D4(rdram, ctx);
        goto after_13;
    // 0x8002B0C0: nop

    after_13:
    // 0x8002B0C4: lh          $t8, 0x188($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X188);
    // 0x8002B0C8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B0CC: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8002B0D0: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B0D4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B0D8: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B0DC: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8002B0E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8002B0E4: lbu         $t1, 0x3084($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X3084);
    // 0x8002B0E8: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B0EC: lwc1        $f18, 0x15C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B0F0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8002B0F4: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B0F8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8002B0FC: ori         $t0, $a2, 0x143
    ctx->r8 = ctx->r6 | 0X143;
    // 0x8002B100: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B104: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B108: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8002B10C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B110: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8002B114: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002B118: jal         0x800B1F0C
    // 0x8002B11C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_14;
    // 0x8002B11C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_14:
L_8002B120:
    // 0x8002B120: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x8002B124: nop

    // 0x8002B128: lwc1        $f10, 0xCC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8002B12C: nop

    // 0x8002B130: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
    // 0x8002B134: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B138: nop

    // 0x8002B13C: lwc1        $f8, 0xD0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8002B140: nop

    // 0x8002B144: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B148: b           L_8002B978
    // 0x8002B14C: nop

        goto L_8002B978;
    // 0x8002B14C: nop

L_8002B150:
    // 0x8002B150: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B154: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B158: jal         0x800B26E0
    // 0x8002B15C: nop

    func_800B26E0(rdram, ctx);
        goto after_15;
    // 0x8002B15C: nop

    after_15:
    // 0x8002B160: bgez        $v0, L_8002B208
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B164: nop
    
            goto L_8002B208;
    }
    // 0x8002B164: nop

    // 0x8002B168: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B16C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002B170: lbu         $t3, 0x3084($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3084);
    // 0x8002B174: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8002B178: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x8002B17C: subu        $t6, $t7, $t5
    ctx->r14 = SUB32(ctx->r15, ctx->r13);
    // 0x8002B180: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8002B184: nop

    // 0x8002B188: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002B18C: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x8002B190: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002B194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002B198: nop

    // 0x8002B19C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8002B1A0: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B1A4: jal         0x800294D4
    // 0x8002B1A8: nop

    func_800294D4(rdram, ctx);
        goto after_16;
    // 0x8002B1A8: nop

    after_16:
    // 0x8002B1AC: lh          $t9, 0x188($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X188);
    // 0x8002B1B0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B1B4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8002B1B8: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B1BC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B1C0: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B1C4: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8002B1C8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002B1CC: lbu         $t2, 0x3084($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3084);
    // 0x8002B1D0: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B1D4: lwc1        $f10, 0x15C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B1D8: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8002B1DC: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B1E0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8002B1E4: ori         $t1, $a2, 0x143
    ctx->r9 = ctx->r6 | 0X143;
    // 0x8002B1E8: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B1EC: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B1F0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8002B1F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B1F8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8002B1FC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8002B200: jal         0x800B1F0C
    // 0x8002B204: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_17;
    // 0x8002B204: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_17:
L_8002B208:
    // 0x8002B208: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B20C: nop

    // 0x8002B210: lwc1        $f8, 0xCC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8002B214: nop

    // 0x8002B218: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
    // 0x8002B21C: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x8002B220: nop

    // 0x8002B224: lwc1        $f16, 0xD0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8002B228: nop

    // 0x8002B22C: swc1        $f16, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f16.u32l;
    // 0x8002B230: b           L_8002B978
    // 0x8002B234: nop

        goto L_8002B978;
    // 0x8002B234: nop

L_8002B238:
    // 0x8002B238: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B23C: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B240: jal         0x800B26E0
    // 0x8002B244: nop

    func_800B26E0(rdram, ctx);
        goto after_18;
    // 0x8002B244: nop

    after_18:
    // 0x8002B248: bgez        $v0, L_8002B324
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B24C: nop
    
            goto L_8002B324;
    }
    // 0x8002B24C: nop

    // 0x8002B250: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B254: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002B258: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8002B25C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002B260: lh          $t5, 0xA($t7)
    ctx->r13 = MEM_H(ctx->r15, 0XA);
    // 0x8002B264: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B268: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8002B26C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8002B270: jal         0x80028400
    // 0x8002B274: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_80028400(rdram, ctx);
        goto after_19;
    // 0x8002B274: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_19:
    // 0x8002B278: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002B27C: lbu         $t6, 0x3084($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3084);
    // 0x8002B280: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8002B284: beq         $t6, $zero, L_8002B294
    if (ctx->r14 == 0) {
        // 0x8002B288: nop
    
            goto L_8002B294;
    }
    // 0x8002B288: nop

    // 0x8002B28C: b           L_8002B298
    // 0x8002B290: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8002B298;
    // 0x8002B290: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002B294:
    // 0x8002B294: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8002B298:
    // 0x8002B298: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8002B29C: nop

    // 0x8002B2A0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002B2A4: mul.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8002B2A8: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x8002B2AC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002B2B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002B2B4: nop

    // 0x8002B2B8: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B2BC: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B2C0: jal         0x800294D4
    // 0x8002B2C4: nop

    func_800294D4(rdram, ctx);
        goto after_20;
    // 0x8002B2C4: nop

    after_20:
    // 0x8002B2C8: lh          $t9, 0x188($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X188);
    // 0x8002B2CC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B2D0: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8002B2D4: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B2D8: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B2DC: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B2E0: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8002B2E4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002B2E8: lbu         $t2, 0x3084($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3084);
    // 0x8002B2EC: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B2F0: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B2F4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8002B2F8: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B2FC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8002B300: ori         $t1, $a2, 0x143
    ctx->r9 = ctx->r6 | 0X143;
    // 0x8002B304: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B308: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B30C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8002B310: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B314: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8002B318: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002B31C: jal         0x800B1F0C
    // 0x8002B320: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_21;
    // 0x8002B320: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_21:
L_8002B324:
    // 0x8002B324: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B328: nop

    // 0x8002B32C: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8002B330: nop

    // 0x8002B334: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8002B338: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x8002B33C: nop

    // 0x8002B340: lwc1        $f18, 0xD0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8002B344: nop

    // 0x8002B348: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002B34C: b           L_8002B978
    // 0x8002B350: nop

        goto L_8002B978;
    // 0x8002B350: nop

L_8002B354:
    // 0x8002B354: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B358: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B35C: jal         0x800B26E0
    // 0x8002B360: nop

    func_800B26E0(rdram, ctx);
        goto after_22;
    // 0x8002B360: nop

    after_22:
    // 0x8002B364: bgez        $v0, L_8002B47C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B368: nop
    
            goto L_8002B47C;
    }
    // 0x8002B368: nop

    // 0x8002B36C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002B370: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002B374: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x8002B378: swc1        $f10, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f10.u32l;
    // 0x8002B37C: swc1        $f10, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f10.u32l;
    // 0x8002B380: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002B384: lbu         $t5, 0x3084($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3084);
    // 0x8002B388: nop

    // 0x8002B38C: beq         $t5, $zero, L_8002B3AC
    if (ctx->r13 == 0) {
        // 0x8002B390: nop
    
            goto L_8002B3AC;
    }
    // 0x8002B390: nop

    // 0x8002B394: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002B398: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8002B39C: nop

    // 0x8002B3A0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002B3A4: b           L_8002B3C0
    // 0x8002B3A8: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
        goto L_8002B3C0;
    // 0x8002B3A8: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
L_8002B3AC:
    // 0x8002B3AC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002B3B0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8002B3B4: nop

    // 0x8002B3B8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002B3BC: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
L_8002B3C0:
    // 0x8002B3C0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002B3C4: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8002B3C8: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8002B3CC: lh          $t0, 0xA($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XA);
    // 0x8002B3D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B3D4: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8002B3D8: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x8002B3DC: jal         0x80028400
    // 0x8002B3E0: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_80028400(rdram, ctx);
        goto after_23;
    // 0x8002B3E0: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_23:
    // 0x8002B3E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002B3E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002B3EC: nop

    // 0x8002B3F0: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8002B3F4: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B3F8: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B3FC: jal         0x800294D4
    // 0x8002B400: nop

    func_800294D4(rdram, ctx);
        goto after_24;
    // 0x8002B400: nop

    after_24:
    // 0x8002B404: lh          $t2, 0x188($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X188);
    // 0x8002B408: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B40C: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8002B410: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B414: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B418: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B41C: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x8002B420: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002B424: lbu         $t7, 0x3084($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3084);
    // 0x8002B428: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B42C: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B430: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8002B434: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B438: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8002B43C: ori         $t3, $a2, 0x143
    ctx->r11 = ctx->r6 | 0X143;
    // 0x8002B440: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B444: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B448: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8002B44C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B450: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8002B454: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002B458: jal         0x800B1F0C
    // 0x8002B45C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_25;
    // 0x8002B45C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x8002B460: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B464: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002B468: sb          $t5, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r13;
    // 0x8002B46C: jal         0x800B9000
    // 0x8002B470: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800B9000(rdram, ctx);
        goto after_26;
    // 0x8002B470: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_26:
    // 0x8002B474: b           L_8002B978
    // 0x8002B478: nop

        goto L_8002B978;
    // 0x8002B478: nop

L_8002B47C:
    // 0x8002B47C: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8002B480: nop

    // 0x8002B484: lwc1        $f4, 0xCC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XCC);
    // 0x8002B488: nop

    // 0x8002B48C: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8002B490: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x8002B494: nop

    // 0x8002B498: lwc1        $f18, 0xD0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8002B49C: nop

    // 0x8002B4A0: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002B4A4: b           L_8002B978
    // 0x8002B4A8: nop

        goto L_8002B978;
    // 0x8002B4A8: nop

L_8002B4AC:
    // 0x8002B4AC: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B4B0: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B4B4: jal         0x800B26E0
    // 0x8002B4B8: nop

    func_800B26E0(rdram, ctx);
        goto after_27;
    // 0x8002B4B8: nop

    after_27:
    // 0x8002B4BC: bgez        $v0, L_8002B558
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B4C0: nop
    
            goto L_8002B558;
    }
    // 0x8002B4C0: nop

    // 0x8002B4C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002B4C8: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002B4CC: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x8002B4D0: swc1        $f10, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f10.u32l;
    // 0x8002B4D4: swc1        $f10, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f10.u32l;
    // 0x8002B4D8: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B4DC: jal         0x800294D4
    // 0x8002B4E0: nop

    func_800294D4(rdram, ctx);
        goto after_28;
    // 0x8002B4E0: nop

    after_28:
    // 0x8002B4E4: lh          $t1, 0x188($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X188);
    // 0x8002B4E8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B4EC: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8002B4F0: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B4F4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B4F8: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B4FC: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x8002B500: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002B504: lbu         $t3, 0x3084($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3084);
    // 0x8002B508: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B50C: lwc1        $f16, 0x15C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B510: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x8002B514: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B518: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x8002B51C: ori         $t4, $a2, 0x14D
    ctx->r12 = ctx->r6 | 0X14D;
    // 0x8002B520: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B524: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B528: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8002B52C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B530: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8002B534: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8002B538: jal         0x800B1F0C
    // 0x8002B53C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_29;
    // 0x8002B53C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_29:
    // 0x8002B540: lhu         $t7, 0x180($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X180);
    // 0x8002B544: nop

    // 0x8002B548: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8002B54C: sh          $t5, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r13;
    // 0x8002B550: b           L_8002B978
    // 0x8002B554: nop

        goto L_8002B978;
    // 0x8002B554: nop

L_8002B558:
    // 0x8002B558: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8002B55C: nop

    // 0x8002B560: lwc1        $f6, 0xCC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XCC);
    // 0x8002B564: nop

    // 0x8002B568: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x8002B56C: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x8002B570: nop

    // 0x8002B574: lwc1        $f4, 0xD0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8002B578: nop

    // 0x8002B57C: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    // 0x8002B580: b           L_8002B978
    // 0x8002B584: nop

        goto L_8002B978;
    // 0x8002B584: nop

L_8002B588:
    // 0x8002B588: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B58C: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B590: jal         0x800B26E0
    // 0x8002B594: nop

    func_800B26E0(rdram, ctx);
        goto after_30;
    // 0x8002B594: nop

    after_30:
    // 0x8002B598: bgez        $v0, L_8002B5D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B59C: nop
    
            goto L_8002B5D0;
    }
    // 0x8002B59C: nop

    // 0x8002B5A0: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x8002B5A4: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8002B5A8: nop

    // 0x8002B5AC: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x8002B5B0: nop

    // 0x8002B5B4: sw          $t0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r8;
    // 0x8002B5B8: lw          $a0, 0x148($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X148);
    // 0x8002B5BC: jal         0x800299C4
    // 0x8002B5C0: nop

    func_800299C4(rdram, ctx);
        goto after_31;
    // 0x8002B5C0: nop

    after_31:
    // 0x8002B5C4: lw          $t1, 0x144($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X144);
    // 0x8002B5C8: nop

    // 0x8002B5CC: sw          $t1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r9;
L_8002B5D0:
    // 0x8002B5D0: b           L_8002B978
    // 0x8002B5D4: nop

        goto L_8002B978;
    // 0x8002B5D4: nop

L_8002B5D8:
    // 0x8002B5D8: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B5DC: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B5E0: jal         0x800B26E0
    // 0x8002B5E4: nop

    func_800B26E0(rdram, ctx);
        goto after_32;
    // 0x8002B5E4: nop

    after_32:
    // 0x8002B5E8: bgez        $v0, L_8002B6C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B5EC: nop
    
            goto L_8002B6C8;
    }
    // 0x8002B5EC: nop

    // 0x8002B5F0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002B5F4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8002B5F8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002B5FC: lh          $t4, 0xA($t2)
    ctx->r12 = MEM_H(ctx->r10, 0XA);
    // 0x8002B600: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B604: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8002B608: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x8002B60C: jal         0x80028400
    // 0x8002B610: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_80028400(rdram, ctx);
        goto after_33;
    // 0x8002B610: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_33:
    // 0x8002B614: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002B618: lbu         $t3, 0x3084($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3084);
    // 0x8002B61C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8002B620: beq         $t3, $zero, L_8002B630
    if (ctx->r11 == 0) {
        // 0x8002B624: nop
    
            goto L_8002B630;
    }
    // 0x8002B624: nop

    // 0x8002B628: b           L_8002B634
    // 0x8002B62C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8002B634;
    // 0x8002B62C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002B630:
    // 0x8002B630: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8002B634:
    // 0x8002B634: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x8002B638: nop

    // 0x8002B63C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002B640: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8002B644: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8002B648: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002B64C: nop

    // 0x8002B650: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8002B654: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002B658: sb          $t7, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r15;
    // 0x8002B65C: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B660: jal         0x800294D4
    // 0x8002B664: nop

    func_800294D4(rdram, ctx);
        goto after_34;
    // 0x8002B664: nop

    after_34:
    // 0x8002B668: lh          $t6, 0x188($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X188);
    // 0x8002B66C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B670: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8002B674: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B678: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B67C: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B680: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002B684: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002B688: lbu         $t0, 0x3084($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3084);
    // 0x8002B68C: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B690: lwc1        $f18, 0x15C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B694: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002B698: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B69C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8002B6A0: ori         $t9, $a2, 0x143
    ctx->r25 = ctx->r6 | 0X143;
    // 0x8002B6A4: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B6A8: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B6AC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8002B6B0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B6B4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8002B6B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002B6BC: jal         0x800B1F0C
    // 0x8002B6C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_35;
    // 0x8002B6C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_35:
    // 0x8002B6C4: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
L_8002B6C8:
    // 0x8002B6C8: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x8002B6CC: nop

    // 0x8002B6D0: lwc1        $f10, 0xCC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8002B6D4: nop

    // 0x8002B6D8: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
    // 0x8002B6DC: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x8002B6E0: nop

    // 0x8002B6E4: lwc1        $f8, 0xD0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8002B6E8: nop

    // 0x8002B6EC: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B6F0: b           L_8002B978
    // 0x8002B6F4: nop

        goto L_8002B978;
    // 0x8002B6F4: nop

L_8002B6F8:
    // 0x8002B6F8: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B6FC: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B700: jal         0x800B26E0
    // 0x8002B704: nop

    func_800B26E0(rdram, ctx);
        goto after_36;
    // 0x8002B704: nop

    after_36:
    // 0x8002B708: bgez        $v0, L_8002B740
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B70C: nop
    
            goto L_8002B740;
    }
    // 0x8002B70C: nop

    // 0x8002B710: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x8002B714: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x8002B718: nop

    // 0x8002B71C: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x8002B720: nop

    // 0x8002B724: sw          $t3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r11;
    // 0x8002B728: lw          $a0, 0x148($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X148);
    // 0x8002B72C: jal         0x8002BE00
    // 0x8002B730: nop

    func_8002BE00(rdram, ctx);
        goto after_37;
    // 0x8002B730: nop

    after_37:
    // 0x8002B734: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8002B738: b           L_8002B768
    // 0x8002B73C: sw          $t7, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r15;
        goto L_8002B768;
    // 0x8002B73C: sw          $t7, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r15;
L_8002B740:
    // 0x8002B740: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x8002B744: nop

    // 0x8002B748: lwc1        $f16, 0xCC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8002B74C: nop

    // 0x8002B750: swc1        $f16, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f16.u32l;
    // 0x8002B754: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8002B758: nop

    // 0x8002B75C: lwc1        $f6, 0xD0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8002B760: nop

    // 0x8002B764: swc1        $f6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f6.u32l;
L_8002B768:
    // 0x8002B768: b           L_8002B978
    // 0x8002B76C: nop

        goto L_8002B978;
    // 0x8002B76C: nop

L_8002B770:
    // 0x8002B770: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B774: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B778: jal         0x800B26E0
    // 0x8002B77C: nop

    func_800B26E0(rdram, ctx);
        goto after_38;
    // 0x8002B77C: nop

    after_38:
    // 0x8002B780: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x8002B784: nop

    // 0x8002B788: lwc1        $f4, 0xCC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x8002B78C: nop

    // 0x8002B790: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8002B794: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x8002B798: nop

    // 0x8002B79C: lwc1        $f18, 0xD0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x8002B7A0: nop

    // 0x8002B7A4: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002B7A8: b           L_8002B978
    // 0x8002B7AC: nop

        goto L_8002B978;
    // 0x8002B7AC: nop

L_8002B7B0:
    // 0x8002B7B0: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B7B4: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B7B8: jal         0x800B26E0
    // 0x8002B7BC: nop

    func_800B26E0(rdram, ctx);
        goto after_39;
    // 0x8002B7BC: nop

    after_39:
    // 0x8002B7C0: bgez        $v0, L_8002B800
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B7C4: nop
    
            goto L_8002B800;
    }
    // 0x8002B7C4: nop

    // 0x8002B7C8: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x8002B7CC: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x8002B7D0: nop

    // 0x8002B7D4: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8002B7D8: nop

    // 0x8002B7DC: sw          $t1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r9;
    // 0x8002B7E0: lw          $a0, 0x148($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X148);
    // 0x8002B7E4: jal         0x800299C4
    // 0x8002B7E8: nop

    func_800299C4(rdram, ctx);
        goto after_40;
    // 0x8002B7E8: nop

    after_40:
    // 0x8002B7EC: lw          $t2, 0x144($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X144);
    // 0x8002B7F0: nop

    // 0x8002B7F4: sw          $t2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r10;
    // 0x8002B7F8: b           L_8002B978
    // 0x8002B7FC: nop

        goto L_8002B978;
    // 0x8002B7FC: nop

L_8002B800:
    // 0x8002B800: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B804: nop

    // 0x8002B808: lwc1        $f10, 0xCC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8002B80C: nop

    // 0x8002B810: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
    // 0x8002B814: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x8002B818: nop

    // 0x8002B81C: lwc1        $f8, 0xD0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8002B820: nop

    // 0x8002B824: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B828: b           L_8002B978
    // 0x8002B82C: nop

        goto L_8002B978;
    // 0x8002B82C: nop

L_8002B830:
    // 0x8002B830: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002B834: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8002B838: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8002B83C: lh          $t5, 0xC($t7)
    ctx->r13 = MEM_H(ctx->r15, 0XC);
    // 0x8002B840: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B844: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8002B848: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8002B84C: jal         0x80028400
    // 0x8002B850: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    func_80028400(rdram, ctx);
        goto after_41;
    // 0x8002B850: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    after_41:
    // 0x8002B854: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002B858: lbu         $t6, 0x3084($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3084);
    // 0x8002B85C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8002B860: beq         $t6, $zero, L_8002B870
    if (ctx->r14 == 0) {
        // 0x8002B864: nop
    
            goto L_8002B870;
    }
    // 0x8002B864: nop

    // 0x8002B868: b           L_8002B874
    // 0x8002B86C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8002B874;
    // 0x8002B86C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002B870:
    // 0x8002B870: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8002B874:
    // 0x8002B874: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8002B878: nop

    // 0x8002B87C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002B880: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8002B884: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x8002B888: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002B88C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8002B890: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8002B894: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x8002B898: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B89C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8002B8A0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    // 0x8002B8A4: jal         0x80028400
    // 0x8002B8A8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_80028400(rdram, ctx);
        goto after_42;
    // 0x8002B8A8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_42:
    // 0x8002B8AC: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8002B8B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002B8B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002B8B8: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8002B8BC: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8002B8C0: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8002B8C4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8002B8C8: sb          $t0, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r8;
    // 0x8002B8CC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8002B8D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002B8D4: nop

    // 0x8002B8D8: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x8002B8DC: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B8E0: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B8E4: jal         0x8009A2C4
    // 0x8002B8E8: nop

    func_8009A2C4(rdram, ctx);
        goto after_43;
    // 0x8002B8E8: nop

    after_43:
    // 0x8002B8EC: b           L_8002B978
    // 0x8002B8F0: nop

        goto L_8002B978;
    // 0x8002B8F0: nop

L_8002B8F4:
    // 0x8002B8F4: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B8F8: jal         0x800294D4
    // 0x8002B8FC: nop

    func_800294D4(rdram, ctx);
        goto after_44;
    // 0x8002B8FC: nop

    after_44:
    // 0x8002B900: lh          $t2, 0x188($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X188);
    // 0x8002B904: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B908: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8002B90C: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B910: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B914: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B918: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x8002B91C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002B920: lbu         $t7, 0x3084($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3084);
    // 0x8002B924: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B928: lwc1        $f8, 0x15C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B92C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8002B930: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B934: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8002B938: ori         $t3, $a2, 0x143
    ctx->r11 = ctx->r6 | 0X143;
    // 0x8002B93C: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B940: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B944: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8002B948: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B94C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8002B950: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8002B954: jal         0x800B1F0C
    // 0x8002B958: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_45;
    // 0x8002B958: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_45:
    // 0x8002B95C: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B960: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002B964: nop

    // 0x8002B968: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x8002B96C: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8002B970: b           L_8002B978
    // 0x8002B974: nop

        goto L_8002B978;
    // 0x8002B974: nop

L_8002B978:
    // 0x8002B978: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8002B97C: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x8002B980: nop

    // 0x8002B984: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x8002B988: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8002B98C: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x8002B990: nop

    // 0x8002B994: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x8002B998: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002B99C: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8002B9A0: nop

    // 0x8002B9A4: swc1        $f18, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f18.u32l;
    // 0x8002B9A8: lbu         $t9, 0x87($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X87);
    // 0x8002B9AC: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x8002B9B0: nop

    // 0x8002B9B4: sb          $t9, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r25;
    // 0x8002B9B8: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x8002B9BC: nop

    // 0x8002B9C0: beq         $t1, $zero, L_8002BA60
    if (ctx->r9 == 0) {
        // 0x8002B9C4: nop
    
            goto L_8002BA60;
    }
    // 0x8002B9C4: nop

    // 0x8002B9C8: lhu         $t2, 0x180($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X180);
    // 0x8002B9CC: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x8002B9D0: nop

    // 0x8002B9D4: sh          $t2, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r10;
    // 0x8002B9D8: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B9DC: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x8002B9E0: nop

    // 0x8002B9E4: swc1        $f10, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f10.u32l;
    // 0x8002B9E8: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x8002B9EC: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x8002B9F0: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002B9F4: nop

    // 0x8002B9F8: swc1        $f8, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f8.u32l;
    // 0x8002B9FC: lwc1        $f16, 0x15C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002BA00: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x8002BA04: nop

    // 0x8002BA08: swc1        $f16, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f16.u32l;
    // 0x8002BA0C: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x8002BA10: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x8002BA14: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8002BA18: nop

    // 0x8002BA1C: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8002BA20: jal         0x800C1850
    // 0x8002BA24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_46;
    // 0x8002BA24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_46:
    // 0x8002BA28: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002BA2C: jal         0x8009A14C
    // 0x8002BA30: nop

    func_8009A14C(rdram, ctx);
        goto after_47;
    // 0x8002BA30: nop

    after_47:
    // 0x8002BA34: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002BA38: jal         0x8009A264
    // 0x8002BA3C: nop

    func_8009A264(rdram, ctx);
        goto after_48;
    // 0x8002BA3C: nop

    after_48:
    // 0x8002BA40: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002BA44: jal         0x800997D8
    // 0x8002BA48: nop

    func_800997D8(rdram, ctx);
        goto after_49;
    // 0x8002BA48: nop

    after_49:
    // 0x8002BA4C: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x8002BA50: nop

    // 0x8002BA54: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8002BA58: nop

    // 0x8002BA5C: sw          $t1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r9;
L_8002BA60:
    // 0x8002BA60: addiu       $a0, $sp, 0x14C
    ctx->r4 = ADD32(ctx->r29, 0X14C);
    // 0x8002BA64: jal         0x800B3434
    // 0x8002BA68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_50;
    // 0x8002BA68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_50:
    // 0x8002BA6C: andi        $t2, $v0, 0x4000
    ctx->r10 = ctx->r2 & 0X4000;
    // 0x8002BA70: beq         $t2, $zero, L_8002BA90
    if (ctx->r10 == 0) {
        // 0x8002BA74: nop
    
            goto L_8002BA90;
    }
    // 0x8002BA74: nop

    // 0x8002BA78: addiu       $a0, $sp, 0x14C
    ctx->r4 = ADD32(ctx->r29, 0X14C);
    // 0x8002BA7C: jal         0x800B32E4
    // 0x8002BA80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B32E4(rdram, ctx);
        goto after_51;
    // 0x8002BA80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x8002BA84: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8002BA88: jal         0x800B9000
    // 0x8002BA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_52;
    // 0x8002BA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
L_8002BA90:
    // 0x8002BA90: lh          $t4, 0x18E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X18E);
    // 0x8002BA94: lh          $t6, 0x84($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X84);
    // 0x8002BA98: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8002BA9C: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x8002BAA0: sra         $t5, $t7, 16
    ctx->r13 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BAA4: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002BAA8: bne         $at, $zero, L_8002A420
    if (ctx->r1 != 0) {
        // 0x8002BAAC: sh          $t3, 0x18E($sp)
        MEM_H(0X18E, ctx->r29) = ctx->r11;
            goto L_8002A420;
    }
    // 0x8002BAAC: sh          $t3, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = ctx->r11;
L_8002BAB0:
    // 0x8002BAB0: jal         0x800C1A28
    // 0x8002BAB4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_53;
    // 0x8002BAB4: nop

    after_53:
    // 0x8002BAB8: b           L_8002BAC0
    // 0x8002BABC: nop

        goto L_8002BAC0;
    // 0x8002BABC: nop

L_8002BAC0:
    // 0x8002BAC0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8002BAC4: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002BAC8: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002BACC: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002BAD0: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002BAD4: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002BAD8: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002BADC: lwc1        $f27, 0x38($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002BAE0: lwc1        $f26, 0x3C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002BAE4: lwc1        $f29, 0x40($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002BAE8: lwc1        $f28, 0x44($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002BAEC: lwc1        $f31, 0x48($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8002BAF0: lwc1        $f30, 0x4C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002BAF4: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x8002BAF8: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x8002BAFC: jr          $ra
    // 0x8002BB00: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x8002BB00: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void func_800305A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800305A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800305A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800305AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800305B0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800305B4: lw          $t6, 0x718C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X718C);
    // 0x800305B8: nop

    // 0x800305BC: beq         $t6, $zero, L_8003083C
    if (ctx->r14 == 0) {
        // 0x800305C0: nop
    
            goto L_8003083C;
    }
    // 0x800305C0: nop

    // 0x800305C4: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x800305C8: lbu         $t7, -0x6A00($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6A00);
    // 0x800305CC: nop

    // 0x800305D0: beq         $t7, $zero, L_80030600
    if (ctx->r15 == 0) {
        // 0x800305D4: nop
    
            goto L_80030600;
    }
    // 0x800305D4: nop

    // 0x800305D8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800305DC: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800305E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800305E4: bne         $t8, $at, L_8003083C
    if (ctx->r24 != ctx->r1) {
        // 0x800305E8: nop
    
            goto L_8003083C;
    }
    // 0x800305E8: nop

    // 0x800305EC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800305F0: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x800305F4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800305F8: bne         $t9, $at, L_8003083C
    if (ctx->r25 != ctx->r1) {
        // 0x800305FC: nop
    
            goto L_8003083C;
    }
    // 0x800305FC: nop

L_80030600:
    // 0x80030600: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80030604: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80030608: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8003060C: nop

    // 0x80030610: andi        $t2, $t1, 0x400
    ctx->r10 = ctx->r9 & 0X400;
    // 0x80030614: bne         $t2, $zero, L_8003083C
    if (ctx->r10 != 0) {
        // 0x80030618: nop
    
            goto L_8003083C;
    }
    // 0x80030618: nop

    // 0x8003061C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030620: lwc1        $f4, -0x4BB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BB0);
    // 0x80030624: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80030628: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003062C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80030630: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80030634: nop

    // 0x80030638: bc1f        L_80030650
    if (!c1cs) {
        // 0x8003063C: nop
    
            goto L_80030650;
    }
    // 0x8003063C: nop

    // 0x80030640: jal         0x800220F4
    // 0x80030644: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800220F4(rdram, ctx);
        goto after_0;
    // 0x80030644: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_0:
    // 0x80030648: jal         0x800B9000
    // 0x8003064C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8003064C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_1:
L_80030650:
    // 0x80030650: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030654: lwc1        $f10, -0x4BB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4BB0);
    // 0x80030658: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003065C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80030660: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030664: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80030668: swc1        $f18, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f18.u32l;
    // 0x8003066C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80030670: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80030674: nop

    // 0x80030678: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8003067C: nop

    // 0x80030680: bc1f        L_80030694
    if (!c1cs) {
        // 0x80030684: nop
    
            goto L_80030694;
    }
    // 0x80030684: nop

    // 0x80030688: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003068C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030690: swc1        $f6, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f6.u32l;
L_80030694:
    // 0x80030694: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80030698: lw          $t3, 0x718C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X718C);
    // 0x8003069C: nop

    // 0x800306A0: blez        $t3, L_8003074C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800306A4: nop
    
            goto L_8003074C;
    }
    // 0x800306A4: nop

    // 0x800306A8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800306AC: lw          $t4, 0x718C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X718C);
    // 0x800306B0: nop

    // 0x800306B4: slti        $at, $t4, 0x65
    ctx->r1 = SIGNED(ctx->r12) < 0X65 ? 1 : 0;
    // 0x800306B8: bne         $at, $zero, L_800306E8
    if (ctx->r1 != 0) {
        // 0x800306BC: nop
    
            goto L_800306E8;
    }
    // 0x800306BC: nop

    // 0x800306C0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800306C4: lw          $t5, 0x718C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X718C);
    // 0x800306C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800306CC: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800306D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800306D4: mflo        $s0
    ctx->r16 = lo;
    // 0x800306D8: subu        $t6, $t5, $s0
    ctx->r14 = SUB32(ctx->r13, ctx->r16);
    // 0x800306DC: sw          $t6, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r14;
    // 0x800306E0: b           L_80030744
    // 0x800306E4: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
        goto L_80030744;
    // 0x800306E4: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
L_800306E8:
    // 0x800306E8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800306EC: lw          $t7, 0x718C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X718C);
    // 0x800306F0: nop

    // 0x800306F4: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x800306F8: bne         $at, $zero, L_80030720
    if (ctx->r1 != 0) {
        // 0x800306FC: nop
    
            goto L_80030720;
    }
    // 0x800306FC: nop

    // 0x80030700: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80030704: lw          $t8, 0x718C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X718C);
    // 0x80030708: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8003070C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030710: subu        $t9, $t8, $s0
    ctx->r25 = SUB32(ctx->r24, ctx->r16);
    // 0x80030714: sw          $t9, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r25;
    // 0x80030718: b           L_80030744
    // 0x8003071C: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
        goto L_80030744;
    // 0x8003071C: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
L_80030720:
    // 0x80030720: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80030724: lw          $t0, 0x718C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X718C);
    // 0x80030728: nop

    // 0x8003072C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80030730: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030734: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x80030738: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003073C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030740: swc1        $f8, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f8.u32l;
L_80030744:
    // 0x80030744: b           L_80030824
    // 0x80030748: nop

        goto L_80030824;
    // 0x80030748: nop

L_8003074C:
    // 0x8003074C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80030750: lw          $t1, 0x718C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X718C);
    // 0x80030754: nop

    // 0x80030758: slti        $at, $t1, -0x64
    ctx->r1 = SIGNED(ctx->r9) < -0X64 ? 1 : 0;
    // 0x8003075C: beq         $at, $zero, L_8003078C
    if (ctx->r1 == 0) {
        // 0x80030760: nop
    
            goto L_8003078C;
    }
    // 0x80030760: nop

    // 0x80030764: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80030768: lw          $t2, 0x718C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X718C);
    // 0x8003076C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80030770: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80030774: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030778: mflo        $s0
    ctx->r16 = lo;
    // 0x8003077C: subu        $t3, $t2, $s0
    ctx->r11 = SUB32(ctx->r10, ctx->r16);
    // 0x80030780: sw          $t3, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r11;
    // 0x80030784: b           L_800307E8
    // 0x80030788: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
        goto L_800307E8;
    // 0x80030788: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
L_8003078C:
    // 0x8003078C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80030790: lw          $t4, 0x718C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X718C);
    // 0x80030794: nop

    // 0x80030798: slti        $at, $t4, -0xA
    ctx->r1 = SIGNED(ctx->r12) < -0XA ? 1 : 0;
    // 0x8003079C: beq         $at, $zero, L_800307C4
    if (ctx->r1 == 0) {
        // 0x800307A0: nop
    
            goto L_800307C4;
    }
    // 0x800307A0: nop

    // 0x800307A4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800307A8: lw          $t5, 0x718C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X718C);
    // 0x800307AC: addiu       $s0, $zero, -0xA
    ctx->r16 = ADD32(0, -0XA);
    // 0x800307B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800307B4: subu        $t6, $t5, $s0
    ctx->r14 = SUB32(ctx->r13, ctx->r16);
    // 0x800307B8: sw          $t6, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r14;
    // 0x800307BC: b           L_800307E8
    // 0x800307C0: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
        goto L_800307E8;
    // 0x800307C0: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
L_800307C4:
    // 0x800307C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800307C8: lw          $t7, 0x718C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X718C);
    // 0x800307CC: nop

    // 0x800307D0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800307D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800307D8: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x800307DC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800307E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800307E4: swc1        $f10, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f10.u32l;
L_800307E8:
    // 0x800307E8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800307EC: lw          $t8, 0x70E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70E8);
    // 0x800307F0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800307F4: nop

    // 0x800307F8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800307FC: bgtz        $t0, L_80030824
    if (SIGNED(ctx->r8) > 0) {
        // 0x80030800: nop
    
            goto L_80030824;
    }
    // 0x80030800: nop

    // 0x80030804: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030808: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x8003080C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030810: sw          $zero, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = 0;
    // 0x80030814: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80030818: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003081C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030820: swc1        $f16, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->f16.u32l;
L_80030824:
    // 0x80030824: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80030828: lw          $t1, 0x70E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E8);
    // 0x8003082C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80030830: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030834: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80030838: sw          $t3, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r11;
L_8003083C:
    // 0x8003083C: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80030840: lhu         $t4, -0x6504($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X6504);
    // 0x80030844: nop

    // 0x80030848: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8003084C: beq         $t5, $zero, L_80030884
    if (ctx->r13 == 0) {
        // 0x80030850: nop
    
            goto L_80030884;
    }
    // 0x80030850: nop

    // 0x80030854: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80030858: lh          $t6, -0x69F0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X69F0);
    // 0x8003085C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80030860: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80030864: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80030868: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003086C: bgez        $t9, L_8003087C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80030870: sh          $t7, -0x69F0($at)
        MEM_H(-0X69F0, ctx->r1) = ctx->r15;
            goto L_8003087C;
    }
    // 0x80030870: sh          $t7, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = ctx->r15;
    // 0x80030874: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80030878: sh          $zero, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = 0;
L_8003087C:
    // 0x8003087C: b           L_800308B8
    // 0x80030880: nop

        goto L_800308B8;
    // 0x80030880: nop

L_80030884:
    // 0x80030884: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80030888: lh          $t0, -0x69F0($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X69F0);
    // 0x8003088C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80030890: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x80030894: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80030898: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8003089C: sh          $t1, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = ctx->r9;
    // 0x800308A0: slti        $at, $t3, 0x1B
    ctx->r1 = SIGNED(ctx->r11) < 0X1B ? 1 : 0;
    // 0x800308A4: bne         $at, $zero, L_800308B8
    if (ctx->r1 != 0) {
        // 0x800308A8: nop
    
            goto L_800308B8;
    }
    // 0x800308A8: nop

    // 0x800308AC: addiu       $t4, $zero, 0x1A
    ctx->r12 = ADD32(0, 0X1A);
    // 0x800308B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800308B4: sh          $t4, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = ctx->r12;
L_800308B8:
    // 0x800308B8: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x800308BC: lhu         $t5, -0x6504($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X6504);
    // 0x800308C0: nop

    // 0x800308C4: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x800308C8: beq         $t6, $zero, L_80030900
    if (ctx->r14 == 0) {
        // 0x800308CC: nop
    
            goto L_80030900;
    }
    // 0x800308CC: nop

    // 0x800308D0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x800308D4: lh          $t7, -0x6558($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6558);
    // 0x800308D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800308DC: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800308E0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800308E4: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800308E8: blez        $t0, L_800308F8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800308EC: sh          $t8, -0x6558($at)
        MEM_H(-0X6558, ctx->r1) = ctx->r24;
            goto L_800308F8;
    }
    // 0x800308EC: sh          $t8, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = ctx->r24;
    // 0x800308F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800308F4: sh          $zero, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = 0;
L_800308F8:
    // 0x800308F8: b           L_80030934
    // 0x800308FC: nop

        goto L_80030934;
    // 0x800308FC: nop

L_80030900:
    // 0x80030900: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x80030904: lh          $t1, -0x6558($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6558);
    // 0x80030908: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8003090C: addiu       $t2, $t1, -0x2
    ctx->r10 = ADD32(ctx->r9, -0X2);
    // 0x80030910: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80030914: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80030918: sh          $t2, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = ctx->r10;
    // 0x8003091C: slti        $at, $t4, -0x21
    ctx->r1 = SIGNED(ctx->r12) < -0X21 ? 1 : 0;
    // 0x80030920: beq         $at, $zero, L_80030934
    if (ctx->r1 == 0) {
        // 0x80030924: nop
    
            goto L_80030934;
    }
    // 0x80030924: nop

    // 0x80030928: addiu       $t5, $zero, -0x21
    ctx->r13 = ADD32(0, -0X21);
    // 0x8003092C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80030930: sh          $t5, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = ctx->r13;
L_80030934:
    // 0x80030934: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030938: lh          $t6, 0x2518($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2518);
    // 0x8003093C: nop

    // 0x80030940: slti        $at, $t6, 0x28
    ctx->r1 = SIGNED(ctx->r14) < 0X28 ? 1 : 0;
    // 0x80030944: bne         $at, $zero, L_80030A58
    if (ctx->r1 != 0) {
        // 0x80030948: nop
    
            goto L_80030A58;
    }
    // 0x80030948: nop

    // 0x8003094C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80030950: lbu         $t7, -0x6A00($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6A00);
    // 0x80030954: nop

    // 0x80030958: beq         $t7, $zero, L_80030A58
    if (ctx->r15 == 0) {
        // 0x8003095C: nop
    
            goto L_80030A58;
    }
    // 0x8003095C: nop

    // 0x80030960: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80030964: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80030968: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003096C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80030970: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80030974: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80030978: lwc1        $f8, -0x4BB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4BB4);
    // 0x8003097C: nop

    // 0x80030980: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80030984: swc1        $f10, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f10.u32l;
    // 0x80030988: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8003098C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80030990: nop

    // 0x80030994: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80030998: nop

    // 0x8003099C: bc1f        L_800309B4
    if (!c1cs) {
        // 0x800309A0: nop
    
            goto L_800309B4;
    }
    // 0x800309A0: nop

    // 0x800309A4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800309A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800309AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800309B0: swc1        $f18, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f18.u32l;
L_800309B4:
    // 0x800309B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800309B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800309BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800309C0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800309C4: lwc1        $f4, -0x4BB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BB4);
    // 0x800309C8: nop

    // 0x800309CC: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800309D0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800309D4: nop

    // 0x800309D8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800309DC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800309E0: beq         $t9, $zero, L_80030A34
    if (ctx->r25 == 0) {
        // 0x800309E4: nop
    
            goto L_80030A34;
    }
    // 0x800309E4: nop

    // 0x800309E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800309EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800309F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800309F4: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800309F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800309FC: nop

    // 0x80030A00: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80030A04: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80030A08: nop

    // 0x80030A0C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80030A10: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80030A14: bne         $t9, $zero, L_80030A2C
    if (ctx->r25 != 0) {
        // 0x80030A18: nop
    
            goto L_80030A2C;
    }
    // 0x80030A18: nop

    // 0x80030A1C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80030A20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030A24: b           L_80030A44
    // 0x80030A28: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80030A44;
    // 0x80030A28: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80030A2C:
    // 0x80030A2C: b           L_80030A44
    // 0x80030A30: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80030A44;
    // 0x80030A30: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80030A34:
    // 0x80030A34: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80030A38: nop

    // 0x80030A3C: bltz        $t9, L_80030A2C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80030A40: nop
    
            goto L_80030A2C;
    }
    // 0x80030A40: nop

L_80030A44:
    // 0x80030A44: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80030A48: lw          $t1, -0x73D0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73D0);
    // 0x80030A4C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80030A50: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80030A54: sh          $t0, 0x3DE($t1)
    MEM_H(0X3DE, ctx->r9) = ctx->r8;
L_80030A58:
    // 0x80030A58: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80030A5C: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80030A60: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x80030A64: nop

    // 0x80030A68: sh          $t3, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r11;
    // 0x80030A6C: jal         0x800C1754
    // 0x80030A70: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_2;
    // 0x80030A70: nop

    after_2:
    // 0x80030A74: jal         0x8002DC14
    // 0x80030A78: nop

    func_8002DC14(rdram, ctx);
        goto after_3;
    // 0x80030A78: nop

    after_3:
    // 0x80030A7C: jal         0x8002E414
    // 0x80030A80: nop

    func_8002E414(rdram, ctx);
        goto after_4;
    // 0x80030A80: nop

    after_4:
    // 0x80030A84: jal         0x8002ED14
    // 0x80030A88: nop

    func_8002ED14(rdram, ctx);
        goto after_5;
    // 0x80030A88: nop

    after_5:
    // 0x80030A8C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80030A90: lhu         $t4, 0x2518($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X2518);
    // 0x80030A94: nop

    // 0x80030A98: sltiu       $at, $t4, 0x2E
    ctx->r1 = ctx->r12 < 0X2E ? 1 : 0;
    // 0x80030A9C: beq         $at, $zero, L_8003166C
    if (ctx->r1 == 0) {
        // 0x80030AA0: nop
    
            goto L_8003166C;
    }
    // 0x80030AA0: nop

    // 0x80030AA4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80030AA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80030AAC: addu        $at, $at, $t4
    gpr jr_addend_80030AB8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80030AB0: lw          $t4, -0x182C($at)
    ctx->r12 = ADD32(ctx->r1, -0X182C);
    // 0x80030AB4: nop

    // 0x80030AB8: jr          $t4
    // 0x80030ABC: nop

    switch (jr_addend_80030AB8 >> 2) {
        case 0: goto L_80030AC0; break;
        case 1: goto L_8003166C; break;
        case 2: goto L_8003166C; break;
        case 3: goto L_8003166C; break;
        case 4: goto L_8003166C; break;
        case 5: goto L_8003166C; break;
        case 6: goto L_8003166C; break;
        case 7: goto L_8003166C; break;
        case 8: goto L_8003166C; break;
        case 9: goto L_8003166C; break;
        case 10: goto L_80030AC0; break;
        case 11: goto L_8003166C; break;
        case 12: goto L_8003166C; break;
        case 13: goto L_8003166C; break;
        case 14: goto L_8003166C; break;
        case 15: goto L_8003166C; break;
        case 16: goto L_8003166C; break;
        case 17: goto L_8003166C; break;
        case 18: goto L_8003166C; break;
        case 19: goto L_8003166C; break;
        case 20: goto L_80030AC0; break;
        case 21: goto L_8003166C; break;
        case 22: goto L_8003166C; break;
        case 23: goto L_8003166C; break;
        case 24: goto L_8003166C; break;
        case 25: goto L_8003166C; break;
        case 26: goto L_8003166C; break;
        case 27: goto L_8003166C; break;
        case 28: goto L_8003166C; break;
        case 29: goto L_8003166C; break;
        case 30: goto L_80030AC0; break;
        case 31: goto L_8003166C; break;
        case 32: goto L_8003166C; break;
        case 33: goto L_8003166C; break;
        case 34: goto L_8003166C; break;
        case 35: goto L_80031568; break;
        case 36: goto L_8003166C; break;
        case 37: goto L_8003166C; break;
        case 38: goto L_8003166C; break;
        case 39: goto L_8003166C; break;
        case 40: goto L_80030AC8; break;
        case 41: goto L_8003166C; break;
        case 42: goto L_8003166C; break;
        case 43: goto L_8003166C; break;
        case 44: goto L_8003166C; break;
        case 45: goto L_80030C00; break;
        default: switch_error(__func__, 0x80030AB8, 0x800EE7D4);
    }
    // 0x80030ABC: nop

L_80030AC0:
    // 0x80030AC0: b           L_8003166C
    // 0x80030AC4: nop

        goto L_8003166C;
    // 0x80030AC4: nop

L_80030AC8:
    // 0x80030AC8: jal         0x8002EC90
    // 0x80030ACC: nop

    func_8002EC90(rdram, ctx);
        goto after_6;
    // 0x80030ACC: nop

    after_6:
    // 0x80030AD0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80030AD4: lh          $t5, 0x2570($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2570);
    // 0x80030AD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80030ADC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80030AE0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80030AE4: lw          $t7, 0x79D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X79D0);
    // 0x80030AE8: nop

    // 0x80030AEC: beq         $t7, $zero, L_80030BA8
    if (ctx->r15 == 0) {
        // 0x80030AF0: sw          $t7, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r15;
            goto L_80030BA8;
    }
    // 0x80030AF0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80030AF4: jal         0x8002DA1C
    // 0x80030AF8: nop

    func_8002DA1C(rdram, ctx);
        goto after_7;
    // 0x80030AF8: nop

    after_7:
    // 0x80030AFC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80030B00: lw          $t8, 0x7AE0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7AE0);
    // 0x80030B04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B08: sw          $t8, 0x7B48($at)
    MEM_W(0X7B48, ctx->r1) = ctx->r24;
    // 0x80030B0C: jal         0x80090728
    // 0x80030B10: addiu       $a0, $zero, 0x4A0
    ctx->r4 = ADD32(0, 0X4A0);
    func_80090728(rdram, ctx);
        goto after_8;
    // 0x80030B10: addiu       $a0, $zero, 0x4A0
    ctx->r4 = ADD32(0, 0X4A0);
    after_8:
    // 0x80030B14: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80030B18: addiu       $t9, $t9, 0x5B0
    ctx->r25 = ADD32(ctx->r25, 0X5B0);
    // 0x80030B1C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80030B20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80030B24: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80030B28: jal         0x800BD218
    // 0x80030B2C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    SysMem_DmaCopy(rdram, ctx);
        goto after_9;
    // 0x80030B2C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_9:
    // 0x80030B30: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030B34: lw          $a0, 0x7AE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7AE0);
    // 0x80030B38: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80030B3C: jal         0x8008ED4C
    // 0x80030B40: nop

    func_8008ED4C(rdram, ctx);
        goto after_10;
    // 0x80030B40: nop

    after_10:
    // 0x80030B44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80030B48: jal         0x8008EAA8
    // 0x80030B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_11;
    // 0x80030B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80030B50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80030B58: sh          $zero, 0x2550($at)
    MEM_H(0X2550, ctx->r1) = 0;
    // 0x80030B5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B60: sb          $zero, 0x2614($at)
    MEM_B(0X2614, ctx->r1) = 0;
    // 0x80030B64: bgez        $zero, L_80030B7C
    if (SIGNED(0) >= 0) {
        // 0x80030B68: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80030B7C;
    }
    // 0x80030B68: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80030B6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80030B70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80030B74: nop

    // 0x80030B78: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80030B7C:
    // 0x80030B7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B80: swc1        $f10, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f10.u32l;
    // 0x80030B84: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x80030B88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030B8C: sh          $t0, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r8;
    // 0x80030B90: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80030B94: lh          $t1, 0x1B08($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1B08);
    // 0x80030B98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80030B9C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80030BA0: b           L_80030BF8
    // 0x80030BA4: sh          $t2, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = ctx->r10;
        goto L_80030BF8;
    // 0x80030BA4: sh          $t2, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = ctx->r10;
L_80030BA8:
    // 0x80030BA8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80030BAC: lh          $t3, 0x2580($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2580);
    // 0x80030BB0: nop

    // 0x80030BB4: beq         $t3, $zero, L_80030BF8
    if (ctx->r11 == 0) {
        // 0x80030BB8: nop
    
            goto L_80030BF8;
    }
    // 0x80030BB8: nop

    // 0x80030BBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030BC0: sh          $zero, 0x2580($at)
    MEM_H(0X2580, ctx->r1) = 0;
    // 0x80030BC4: jal         0x8009600C
    // 0x80030BC8: nop

    func_8009600C(rdram, ctx);
        goto after_12;
    // 0x80030BC8: nop

    after_12:
    // 0x80030BCC: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80030BD0: lbu         $t4, -0x6A00($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X6A00);
    // 0x80030BD4: nop

    // 0x80030BD8: beq         $t4, $zero, L_80030BF0
    if (ctx->r12 == 0) {
        // 0x80030BDC: nop
    
            goto L_80030BF0;
    }
    // 0x80030BDC: nop

    // 0x80030BE0: addiu       $t5, $zero, 0x23
    ctx->r13 = ADD32(0, 0X23);
    // 0x80030BE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030BE8: b           L_80030BF8
    // 0x80030BEC: sh          $t5, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r13;
        goto L_80030BF8;
    // 0x80030BEC: sh          $t5, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r13;
L_80030BF0:
    // 0x80030BF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030BF4: sh          $zero, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = 0;
L_80030BF8:
    // 0x80030BF8: b           L_8003166C
    // 0x80030BFC: nop

        goto L_8003166C;
    // 0x80030BFC: nop

L_80030C00:
    // 0x80030C00: jal         0x8002EC90
    // 0x80030C04: nop

    func_8002EC90(rdram, ctx);
        goto after_13;
    // 0x80030C04: nop

    after_13:
    // 0x80030C08: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030C0C: lh          $t6, 0x2550($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2550);
    // 0x80030C10: nop

    // 0x80030C14: bne         $t6, $zero, L_800313B8
    if (ctx->r14 != 0) {
        // 0x80030C18: nop
    
            goto L_800313B8;
    }
    // 0x80030C18: nop

    // 0x80030C1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80030C20: lhu         $t8, 0x10F2($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X10F2);
    // 0x80030C24: lhu         $t7, 0x46($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X46);
    // 0x80030C28: nop

    // 0x80030C2C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80030C30: beq         $t9, $zero, L_80030C40
    if (ctx->r25 == 0) {
        // 0x80030C34: nop
    
            goto L_80030C40;
    }
    // 0x80030C34: nop

    // 0x80030C38: jal         0x80090754
    // 0x80030C3C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_80090754(rdram, ctx);
        goto after_14;
    // 0x80030C3C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_14:
L_80030C40:
    // 0x80030C40: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80030C44: lw          $t0, 0x7B48($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B48);
    // 0x80030C48: nop

    // 0x80030C4C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80030C50: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030C54: lw          $a0, 0x69C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X69C8);
    // 0x80030C58: jal         0x8008ECCC
    // 0x80030C5C: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_15;
    // 0x80030C5C: nop

    after_15:
    // 0x80030C60: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80030C64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80030C68: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80030C6C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80030C70: jal         0x8008EC8C
    // 0x80030C74: nop

    func_8008EC8C(rdram, ctx);
        goto after_16;
    // 0x80030C74: nop

    after_16:
    // 0x80030C78: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80030C7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80030C80: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80030C84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80030C88: jal         0x8008ECAC
    // 0x80030C8C: nop

    func_8008ECAC(rdram, ctx);
        goto after_17;
    // 0x80030C8C: nop

    after_17:
    // 0x80030C90: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80030C94: jal         0x80090E58
    // 0x80030C98: addiu       $a0, $a0, 0x7B48
    ctx->r4 = ADD32(ctx->r4, 0X7B48);
    func_80090E58(rdram, ctx);
        goto after_18;
    // 0x80030C98: addiu       $a0, $a0, 0x7B48
    ctx->r4 = ADD32(ctx->r4, 0X7B48);
    after_18:
    // 0x80030C9C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80030CA0: lw          $t1, 0x7B48($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B48);
    // 0x80030CA4: nop

    // 0x80030CA8: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80030CAC: nop

    // 0x80030CB0: bne         $t2, $zero, L_80030CD8
    if (ctx->r10 != 0) {
        // 0x80030CB4: nop
    
            goto L_80030CD8;
    }
    // 0x80030CB4: nop

    // 0x80030CB8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80030CBC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80030CC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80030CC4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80030CC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030CCC: sh          $t3, 0x2550($at)
    MEM_H(0X2550, ctx->r1) = ctx->r11;
    // 0x80030CD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80030CD4: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
L_80030CD8:
    // 0x80030CD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030CDC: lw          $t6, 0x7B48($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B48);
    // 0x80030CE0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80030CE4: nop

    // 0x80030CE8: beq         $t5, $t6, L_800313B0
    if (ctx->r13 == ctx->r14) {
        // 0x80030CEC: nop
    
            goto L_800313B0;
    }
    // 0x80030CEC: nop

    // 0x80030CF0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80030CF4: lw          $t7, 0x263C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X263C);
    // 0x80030CF8: nop

    // 0x80030CFC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80030D00: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80030D04: lhu         $t8, 0x24FC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X24FC);
    // 0x80030D08: nop

    // 0x80030D0C: beq         $t8, $zero, L_80030D1C
    if (ctx->r24 == 0) {
        // 0x80030D10: nop
    
            goto L_80030D1C;
    }
    // 0x80030D10: nop

    // 0x80030D14: b           L_80030D20
    // 0x80030D18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80030D20;
    // 0x80030D18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80030D1C:
    // 0x80030D1C: addiu       $s0, $zero, 0xD00
    ctx->r16 = ADD32(0, 0XD00);
L_80030D20:
    // 0x80030D20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80030D24: lw          $t9, 0x7B70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B70);
    // 0x80030D28: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80030D2C: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80030D30: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80030D34: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80030D38: nop

    // 0x80030D3C: sw          $t1, 0x128($t2)
    MEM_W(0X128, ctx->r10) = ctx->r9;
    // 0x80030D40: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80030D44: nop

    // 0x80030D48: addiu       $t4, $t3, 0x160
    ctx->r12 = ADD32(ctx->r11, 0X160);
    // 0x80030D4C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80030D50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80030D54: lhu         $t5, 0x24FC($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X24FC);
    // 0x80030D58: nop

    // 0x80030D5C: beq         $t5, $zero, L_80030D6C
    if (ctx->r13 == 0) {
        // 0x80030D60: nop
    
            goto L_80030D6C;
    }
    // 0x80030D60: nop

    // 0x80030D64: b           L_80030D70
    // 0x80030D68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80030D70;
    // 0x80030D68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80030D6C:
    // 0x80030D6C: addiu       $s0, $zero, 0x680
    ctx->r16 = ADD32(0, 0X680);
L_80030D70:
    // 0x80030D70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030D74: lw          $t6, 0x7BBC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7BBC);
    // 0x80030D78: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80030D7C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80030D80: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80030D84: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80030D88: nop

    // 0x80030D8C: sw          $t8, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r24;
    // 0x80030D90: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80030D94: nop

    // 0x80030D98: addiu       $t1, $t0, 0x160
    ctx->r9 = ADD32(ctx->r8, 0X160);
    // 0x80030D9C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80030DA0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80030DA4: lhu         $t2, 0x24FC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X24FC);
    // 0x80030DA8: nop

    // 0x80030DAC: beq         $t2, $zero, L_80030DBC
    if (ctx->r10 == 0) {
        // 0x80030DB0: nop
    
            goto L_80030DBC;
    }
    // 0x80030DB0: nop

    // 0x80030DB4: b           L_80030DC0
    // 0x80030DB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80030DC0;
    // 0x80030DB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80030DBC:
    // 0x80030DBC: addiu       $s0, $zero, 0x4E0
    ctx->r16 = ADD32(0, 0X4E0);
L_80030DC0:
    // 0x80030DC0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80030DC4: lw          $t3, 0x7BD8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7BD8);
    // 0x80030DC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80030DCC: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80030DD0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80030DD4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80030DD8: nop

    // 0x80030DDC: sw          $t5, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->r13;
    // 0x80030DE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80030DE4: lw          $t7, 0x69C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69C8);
    // 0x80030DE8: nop

    // 0x80030DEC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80030DF0: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
L_80030DF4:
    // 0x80030DF4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030DF8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80030DFC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80030E00: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80030E04: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80030E08: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80030E0C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030E10: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80030E14: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030E18: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030E1C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80030E20: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80030E24: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80030E28: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80030E2C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80030E30: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80030E34: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80030E38: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80030E3C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80030E40: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80030E44: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030E48: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80030E4C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80030E50: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80030E54: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030E58: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80030E5C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80030E60: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80030E64: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80030E68: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80030E6C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80030E70: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80030E74: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80030E78: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80030E7C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80030E80: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80030E84: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80030E88: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80030E8C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80030E90: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80030E94: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80030E98: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80030E9C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030EA0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80030EA4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80030EA8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80030EAC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80030EB0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80030EB4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80030EB8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80030EBC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80030EC0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80030EC4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80030EC8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80030ECC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80030ED0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80030ED4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80030ED8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030EDC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80030EE0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80030EE4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030EE8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80030EEC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80030EF0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80030EF4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80030EF8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80030EFC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030F00: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80030F04: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030F08: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030F0C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80030F10: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80030F14: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80030F18: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80030F1C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80030F20: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80030F24: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80030F28: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80030F2C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80030F30: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80030F34: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030F38: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80030F3C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80030F40: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80030F44: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030F48: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80030F4C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80030F50: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80030F54: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80030F58: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80030F5C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80030F60: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80030F64: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80030F68: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80030F6C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80030F70: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80030F74: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80030F78: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80030F7C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80030F80: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80030F84: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80030F88: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80030F8C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030F90: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80030F94: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80030F98: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80030F9C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80030FA0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80030FA4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80030FA8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80030FAC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80030FB0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80030FB4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80030FB8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80030FBC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80030FC0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80030FC4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80030FC8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030FCC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80030FD0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80030FD4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030FD8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80030FDC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80030FE0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80030FE4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80030FE8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80030FEC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80030FF0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80030FF4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80030FF8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80030FFC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80031000: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80031004: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80031008: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8003100C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80031010: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80031014: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80031018: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8003101C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031020: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80031024: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80031028: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003102C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80031030: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80031034: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80031038: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8003103C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80031040: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80031044: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80031048: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8003104C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031050: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80031054: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80031058: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003105C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80031060: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80031064: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031068: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8003106C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80031070: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80031074: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80031078: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8003107C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80031080: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80031084: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80031088: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003108C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80031090: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80031094: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031098: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8003109C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800310A0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800310A4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800310A8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x800310AC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800310B0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800310B4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800310B8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800310BC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x800310C0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800310C4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800310C8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800310CC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800310D0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800310D4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800310D8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800310DC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800310E0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800310E4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800310E8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800310EC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800310F0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800310F4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800310F8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800310FC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80031100: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80031104: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80031108: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8003110C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031110: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80031114: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80031118: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003111C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80031120: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80031124: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80031128: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8003112C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80031130: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80031134: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80031138: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8003113C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031140: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80031144: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80031148: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003114C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80031150: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80031154: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031158: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8003115C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80031160: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80031164: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80031168: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8003116C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80031170: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80031174: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80031178: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003117C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80031180: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80031184: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031188: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003118C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80031190: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80031194: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80031198: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8003119C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800311A0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800311A4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800311A8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800311AC: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800311B0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800311B4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800311B8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800311BC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800311C0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800311C4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800311C8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800311CC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800311D0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800311D4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800311D8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800311DC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800311E0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800311E4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800311E8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800311EC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800311F0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800311F4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800311F8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800311FC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031200: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80031204: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80031208: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8003120C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80031210: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80031214: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80031218: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8003121C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80031220: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80031224: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80031228: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8003122C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031230: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80031234: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80031238: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003123C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80031240: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80031244: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031248: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8003124C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80031250: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80031254: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80031258: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8003125C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80031260: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80031264: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80031268: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003126C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80031270: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80031274: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031278: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8003127C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80031280: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80031284: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80031288: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8003128C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80031290: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80031294: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80031298: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8003129C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800312A0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800312A4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800312A8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800312AC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800312B0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800312B4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800312B8: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800312BC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800312C0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800312C4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800312C8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800312CC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800312D0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800312D4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800312D8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800312DC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800312E0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800312E4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800312E8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800312EC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800312F0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800312F4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800312F8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800312FC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80031300: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80031304: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80031308: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8003130C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80031310: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80031314: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80031318: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8003131C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031320: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80031324: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80031328: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003132C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80031330: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80031334: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80031338: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8003133C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80031340: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80031344: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80031348: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8003134C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80031350: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80031354: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80031358: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003135C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80031360: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80031364: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80031368: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8003136C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80031370: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80031374: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80031378: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8003137C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80031380: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80031384: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80031388: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8003138C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80031390: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80031394: lhu         $t8, 0x4A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4A);
    // 0x80031398: nop

    // 0x8003139C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800313A0: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x800313A4: slti        $at, $t0, 0x1A
    ctx->r1 = SIGNED(ctx->r8) < 0X1A ? 1 : 0;
    // 0x800313A8: bne         $at, $zero, L_80030DF4
    if (ctx->r1 != 0) {
        // 0x800313AC: sh          $t9, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r25;
            goto L_80030DF4;
    }
    // 0x800313AC: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
L_800313B0:
    // 0x800313B0: b           L_800314A4
    // 0x800313B4: nop

        goto L_800314A4;
    // 0x800313B4: nop

L_800313B8:
    // 0x800313B8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800313BC: lbu         $t2, 0x25EC($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X25EC);
    // 0x800313C0: nop

    // 0x800313C4: bne         $t2, $zero, L_800313F0
    if (ctx->r10 != 0) {
        // 0x800313C8: nop
    
            goto L_800313F0;
    }
    // 0x800313C8: nop

    // 0x800313CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800313D0: lwc1        $f8, 0x2530($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2530);
    // 0x800313D4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800313D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800313DC: nop

    // 0x800313E0: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x800313E4: nop

    // 0x800313E8: bc1f        L_800314A4
    if (!c1cs) {
        // 0x800313EC: nop
    
            goto L_800314A4;
    }
    // 0x800313EC: nop

L_800313F0:
    // 0x800313F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800313F4: lwc1        $f16, 0x2530($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2530);
    // 0x800313F8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800313FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031400: nop

    // 0x80031404: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x80031408: nop

    // 0x8003140C: bc1t        L_80031444
    if (c1cs) {
        // 0x80031410: nop
    
            goto L_80031444;
    }
    // 0x80031410: nop

    // 0x80031414: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80031418: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8003141C: lhu         $t3, 0x46($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X46);
    // 0x80031420: nop

    // 0x80031424: and         $t4, $t3, $t1
    ctx->r12 = ctx->r11 & ctx->r9;
    // 0x80031428: beq         $t4, $zero, L_80031488
    if (ctx->r12 == 0) {
        // 0x8003142C: nop
    
            goto L_80031488;
    }
    // 0x8003142C: nop

    // 0x80031430: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x80031434: lbu         $t5, -0x69F8($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X69F8);
    // 0x80031438: nop

    // 0x8003143C: bne         $t5, $zero, L_80031488
    if (ctx->r13 != 0) {
        // 0x80031440: nop
    
            goto L_80031488;
    }
    // 0x80031440: nop

L_80031444:
    // 0x80031444: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80031448: lh          $t6, 0x2570($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2570);
    // 0x8003144C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031450: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031454: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80031458: sw          $zero, 0x79D0($at)
    MEM_W(0X79D0, ctx->r1) = 0;
    // 0x8003145C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80031460: lh          $t8, 0x2570($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2570);
    // 0x80031464: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031468: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8003146C: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x80031470: sh          $t0, 0x2570($at)
    MEM_H(0X2570, ctx->r1) = ctx->r8;
    // 0x80031474: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80031478: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003147C: sh          $t2, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r10;
    // 0x80031480: b           L_8003166C
    // 0x80031484: nop

        goto L_8003166C;
    // 0x80031484: nop

L_80031488:
    // 0x80031488: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003148C: lwc1        $f18, 0x2530($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2530);
    // 0x80031490: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031494: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80031498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003149C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800314A0: swc1        $f8, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f8.u32l;
L_800314A4:
    // 0x800314A4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800314A8: lbu         $t3, 0x2614($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X2614);
    // 0x800314AC: nop

    // 0x800314B0: beq         $t3, $zero, L_80031554
    if (ctx->r11 == 0) {
        // 0x800314B4: nop
    
            goto L_80031554;
    }
    // 0x800314B4: nop

    // 0x800314B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800314BC: lw          $t1, 0x263C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X263C);
    // 0x800314C0: nop

    // 0x800314C4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800314C8: sh          $zero, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = 0;
L_800314CC:
    // 0x800314CC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800314D0: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800314D4: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x800314D8: nop

    // 0x800314DC: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800314E0: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x800314E4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800314E8: lw          $t9, -0x73D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73D0);
    // 0x800314EC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800314F0: lw          $t0, 0x380($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X380);
    // 0x800314F4: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x800314F8: andi        $t2, $t0, 0x200
    ctx->r10 = ctx->r8 & 0X200;
    // 0x800314FC: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x80031500: sw          $t3, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r11;
    // 0x80031504: jal         0x800C1850
    // 0x80031508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_19;
    // 0x80031508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x8003150C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80031510: jal         0x8009A14C
    // 0x80031514: nop

    func_8009A14C(rdram, ctx);
        goto after_20;
    // 0x80031514: nop

    after_20:
    // 0x80031518: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8003151C: nop

    // 0x80031520: addiu       $t5, $t1, 0x160
    ctx->r13 = ADD32(ctx->r9, 0X160);
    // 0x80031524: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80031528: jal         0x800997D8
    // 0x8003152C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800997D8(rdram, ctx);
        goto after_21;
    // 0x8003152C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_21:
    // 0x80031530: lhu         $t6, 0x4A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4A);
    // 0x80031534: nop

    // 0x80031538: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x8003153C: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x80031540: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80031544: bne         $at, $zero, L_800314CC
    if (ctx->r1 != 0) {
        // 0x80031548: sh          $t4, 0x4A($sp)
        MEM_H(0X4A, ctx->r29) = ctx->r12;
            goto L_800314CC;
    }
    // 0x80031548: sh          $t4, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r12;
    // 0x8003154C: b           L_80031560
    // 0x80031550: nop

        goto L_80031560;
    // 0x80031550: nop

L_80031554:
    // 0x80031554: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80031558: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003155C: sb          $t0, 0x2614($at)
    MEM_B(0X2614, ctx->r1) = ctx->r8;
L_80031560:
    // 0x80031560: b           L_8003166C
    // 0x80031564: nop

        goto L_8003166C;
    // 0x80031564: nop

L_80031568:
    // 0x80031568: jal         0x8002EC90
    // 0x8003156C: nop

    func_8002EC90(rdram, ctx);
        goto after_22;
    // 0x8003156C: nop

    after_22:
    // 0x80031570: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80031574: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80031578: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003157C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80031580: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80031584: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80031588: lwc1        $f18, -0x4BB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4BB4);
    // 0x8003158C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80031590: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80031594: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80031598: swc1        $f4, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f4.u32l;
    // 0x8003159C: bc1f        L_800315C0
    if (!c1cs) {
        // 0x800315A0: nop
    
            goto L_800315C0;
    }
    // 0x800315A0: nop

    // 0x800315A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800315A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800315AC: swc1        $f6, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->f6.u32l;
    // 0x800315B0: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x800315B4: lbu         $t8, -0x6A00($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X6A00);
    // 0x800315B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800315BC: sh          $t8, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r24;
L_800315C0:
    // 0x800315C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800315C4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800315C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800315CC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800315D0: lwc1        $f16, -0x4BB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4BB4);
    // 0x800315D4: nop

    // 0x800315D8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800315DC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800315E0: nop

    // 0x800315E4: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800315E8: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800315EC: beq         $t3, $zero, L_80031640
    if (ctx->r11 == 0) {
        // 0x800315F0: nop
    
            goto L_80031640;
    }
    // 0x800315F0: nop

    // 0x800315F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800315F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800315FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80031600: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80031604: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80031608: nop

    // 0x8003160C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80031610: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80031614: nop

    // 0x80031618: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x8003161C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80031620: bne         $t3, $zero, L_80031638
    if (ctx->r11 != 0) {
        // 0x80031624: nop
    
            goto L_80031638;
    }
    // 0x80031624: nop

    // 0x80031628: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8003162C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80031630: b           L_80031650
    // 0x80031634: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80031650;
    // 0x80031634: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80031638:
    // 0x80031638: b           L_80031650
    // 0x8003163C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80031650;
    // 0x8003163C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80031640:
    // 0x80031640: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80031644: nop

    // 0x80031648: bltz        $t3, L_80031638
    if (SIGNED(ctx->r11) < 0) {
        // 0x8003164C: nop
    
            goto L_80031638;
    }
    // 0x8003164C: nop

L_80031650:
    // 0x80031650: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80031654: lw          $t1, -0x73D0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73D0);
    // 0x80031658: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003165C: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x80031660: sh          $t7, 0x3DE($t1)
    MEM_H(0X3DE, ctx->r9) = ctx->r15;
    // 0x80031664: b           L_8003166C
    // 0x80031668: nop

        goto L_8003166C;
    // 0x80031668: nop

L_8003166C:
    // 0x8003166C: jal         0x800C1A28
    // 0x80031670: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_23;
    // 0x80031670: nop

    after_23:
    // 0x80031674: b           L_8003167C
    // 0x80031678: nop

        goto L_8003167C;
    // 0x80031678: nop

L_8003167C:
    // 0x8003167C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80031684: jr          $ra
    // 0x80031688: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80031688: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800679C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800679C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800679C8: nop

    // 0x800679CC: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800679D0: nop

    // 0x800679D4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800679D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800679DC: jr          $ra
    // 0x800679E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800679E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800679E4: jr          $ra
    // 0x800679E8: nop

    return;
    // 0x800679E8: nop

    // 0x800679EC: jr          $ra
    // 0x800679F0: nop

    return;
    // 0x800679F0: nop

;}
RECOMP_FUNC void func_80094230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094230: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80094234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094238: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009423C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80094240: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80094244: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80094248: nop

    // 0x8009424C: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x80094250: beq         $at, $zero, L_80094630
    if (ctx->r1 == 0) {
        // 0x80094254: nop
    
            goto L_80094630;
    }
    // 0x80094254: nop

    // 0x80094258: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8009425C:
    // 0x8009425C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80094260: lw          $t7, 0x6BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA0);
    // 0x80094264: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80094268: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009426C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094270: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80094274: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094278: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8009427C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80094280: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094284: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80094288: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8009428C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80094290: lw          $t9, 0x6B98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6B98);
    // 0x80094294: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80094298: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009429C: lw          $t0, 0x6C14($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C14);
    // 0x800942A0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800942A4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800942A8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800942AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800942B0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800942B4: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800942B8: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800942BC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800942C0: nop

    // 0x800942C4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800942C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800942CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800942D0: nop

    // 0x800942D4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800942D8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800942DC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800942E0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800942E4: nop

    // 0x800942E8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800942EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800942F0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800942F4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800942F8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800942FC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80094300: lw          $t8, -0x780($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X780);
    // 0x80094304: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80094308: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8009430C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80094310: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80094314: nop

    // 0x80094318: sb          $t0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r8;
    // 0x8009431C: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x80094320: nop

    // 0x80094324: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80094328: beq         $t2, $zero, L_80094358
    if (ctx->r10 == 0) {
        // 0x8009432C: nop
    
            goto L_80094358;
    }
    // 0x8009432C: nop

    // 0x80094330: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094334: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094338: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009433C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094340: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094344: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094348: jal         0x80090784
    // 0x8009434C: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x8009434C: nop

    after_0:
    // 0x80094350: b           L_80094378
    // 0x80094354: nop

        goto L_80094378;
    // 0x80094354: nop

L_80094358:
    // 0x80094358: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009435C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094360: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094364: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094368: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009436C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094370: jal         0x80090784
    // 0x80094374: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80094374: nop

    after_1:
L_80094378:
    // 0x80094378: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x8009437C: nop

    // 0x80094380: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x80094384: beq         $t4, $zero, L_800943B4
    if (ctx->r12 == 0) {
        // 0x80094388: nop
    
            goto L_800943B4;
    }
    // 0x80094388: nop

    // 0x8009438C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094390: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094394: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094398: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009439C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800943A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800943A4: jal         0x80090784
    // 0x800943A8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x800943A8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x800943AC: b           L_800943D4
    // 0x800943B0: nop

        goto L_800943D4;
    // 0x800943B0: nop

L_800943B4:
    // 0x800943B4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800943B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800943BC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800943C0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800943C4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800943C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800943CC: jal         0x80090784
    // 0x800943D0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x800943D0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_800943D4:
    // 0x800943D4: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x800943D8: nop

    // 0x800943DC: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x800943E0: beq         $t6, $zero, L_80094410
    if (ctx->r14 == 0) {
        // 0x800943E4: nop
    
            goto L_80094410;
    }
    // 0x800943E4: nop

    // 0x800943E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800943EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800943F0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800943F4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800943F8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800943FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094400: jal         0x80090784
    // 0x80094404: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x80094404: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x80094408: b           L_80094430
    // 0x8009440C: nop

        goto L_80094430;
    // 0x8009440C: nop

L_80094410:
    // 0x80094410: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094414: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094418: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009441C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094420: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094424: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094428: jal         0x80090784
    // 0x8009442C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x8009442C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80094430:
    // 0x80094430: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x80094434: nop

    // 0x80094438: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8009443C: beq         $t8, $zero, L_8009446C
    if (ctx->r24 == 0) {
        // 0x80094440: nop
    
            goto L_8009446C;
    }
    // 0x80094440: nop

    // 0x80094444: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094448: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009444C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094450: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094454: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094458: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009445C: jal         0x80090784
    // 0x80094460: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80094460: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80094464: b           L_8009448C
    // 0x80094468: nop

        goto L_8009448C;
    // 0x80094468: nop

L_8009446C:
    // 0x8009446C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094470: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094474: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094478: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009447C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094480: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094484: jal         0x80090784
    // 0x80094488: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x80094488: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_8009448C:
    // 0x8009448C: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x80094490: nop

    // 0x80094494: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80094498: beq         $t0, $zero, L_800944C8
    if (ctx->r8 == 0) {
        // 0x8009449C: nop
    
            goto L_800944C8;
    }
    // 0x8009449C: nop

    // 0x800944A0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800944A4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800944A8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800944AC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800944B0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800944B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800944B8: jal         0x80090784
    // 0x800944BC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x800944BC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x800944C0: b           L_800944E8
    // 0x800944C4: nop

        goto L_800944E8;
    // 0x800944C4: nop

L_800944C8:
    // 0x800944C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800944CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800944D0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800944D4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800944D8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800944DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800944E0: jal         0x80090784
    // 0x800944E4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x800944E4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_800944E8:
    // 0x800944E8: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x800944EC: nop

    // 0x800944F0: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800944F4: beq         $t2, $zero, L_80094524
    if (ctx->r10 == 0) {
        // 0x800944F8: nop
    
            goto L_80094524;
    }
    // 0x800944F8: nop

    // 0x800944FC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094500: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094504: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094508: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009450C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094510: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094514: jal         0x80090784
    // 0x80094518: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x80094518: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x8009451C: b           L_80094544
    // 0x80094520: nop

        goto L_80094544;
    // 0x80094520: nop

L_80094524:
    // 0x80094524: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094528: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009452C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094530: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094534: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094538: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009453C: jal         0x80090784
    // 0x80094540: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80094540: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80094544:
    // 0x80094544: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x80094548: nop

    // 0x8009454C: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80094550: beq         $t4, $zero, L_80094580
    if (ctx->r12 == 0) {
        // 0x80094554: nop
    
            goto L_80094580;
    }
    // 0x80094554: nop

    // 0x80094558: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009455C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094560: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094564: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094568: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009456C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094570: jal         0x80090784
    // 0x80094574: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80094574: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x80094578: b           L_800945A0
    // 0x8009457C: nop

        goto L_800945A0;
    // 0x8009457C: nop

L_80094580:
    // 0x80094580: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094584: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094588: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009458C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094590: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094594: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094598: jal         0x80090784
    // 0x8009459C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x8009459C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_800945A0:
    // 0x800945A0: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x800945A4: nop

    // 0x800945A8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800945AC: beq         $t6, $zero, L_800945DC
    if (ctx->r14 == 0) {
        // 0x800945B0: nop
    
            goto L_800945DC;
    }
    // 0x800945B0: nop

    // 0x800945B4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800945B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800945BC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800945C0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800945C4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800945C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800945CC: jal         0x80090784
    // 0x800945D0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x800945D0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x800945D4: b           L_800945FC
    // 0x800945D8: nop

        goto L_800945FC;
    // 0x800945D8: nop

L_800945DC:
    // 0x800945DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800945E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800945E4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800945E8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800945EC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800945F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800945F4: jal         0x80090784
    // 0x800945F8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x800945F8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_800945FC:
    // 0x800945FC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80094600: nop

    // 0x80094604: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80094608: slti        $at, $t8, 0xC
    ctx->r1 = SIGNED(ctx->r24) < 0XC ? 1 : 0;
    // 0x8009460C: bne         $at, $zero, L_8009425C
    if (ctx->r1 != 0) {
        // 0x80094610: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_8009425C;
    }
    // 0x80094610: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80094614: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80094618: lw          $t9, 0x6B98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6B98);
    // 0x8009461C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80094620: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094624: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80094628: b           L_80095E60
    // 0x8009462C: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
        goto L_80095E60;
    // 0x8009462C: sw          $t1, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r9;
L_80094630:
    // 0x80094630: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80094634: lh          $t2, -0x4CC8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CC8);
    // 0x80094638: nop

    // 0x8009463C: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x80094640: bne         $t3, $zero, L_80094BB8
    if (ctx->r11 != 0) {
        // 0x80094644: nop
    
            goto L_80094BB8;
    }
    // 0x80094644: nop

    // 0x80094648: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8009464C:
    // 0x8009464C: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80094650: lw          $t4, 0x6BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA0);
    // 0x80094654: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80094658: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8009465C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094660: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80094664: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094668: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8009466C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80094670: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094674: lwc1        $f8, -0x4510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80094678: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8009467C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80094680: lw          $t6, 0x6B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6B98);
    // 0x80094684: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80094688: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8009468C: lw          $t7, 0x6C14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C14);
    // 0x80094690: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80094694: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80094698: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8009469C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800946A0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800946A4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800946A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800946AC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800946B0: nop

    // 0x800946B4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800946B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800946BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800946C0: nop

    // 0x800946C4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800946C8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800946CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800946D0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800946D4: nop

    // 0x800946D8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800946DC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800946E0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800946E4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800946E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800946EC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800946F0: lw          $t6, -0x780($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X780);
    // 0x800946F4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800946F8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800946FC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80094700: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80094704: lbu         $t8, -0x1200($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1200);
    // 0x80094708: nop

    // 0x8009470C: sb          $t8, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r24;
    // 0x80094710: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x80094714: nop

    // 0x80094718: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x8009471C: beq         $t0, $zero, L_8009474C
    if (ctx->r8 == 0) {
        // 0x80094720: nop
    
            goto L_8009474C;
    }
    // 0x80094720: nop

    // 0x80094724: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094728: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009472C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094730: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094734: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094738: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009473C: jal         0x80090784
    // 0x80094740: nop

    func_80090784(rdram, ctx);
        goto after_16;
    // 0x80094740: nop

    after_16:
    // 0x80094744: b           L_8009476C
    // 0x80094748: nop

        goto L_8009476C;
    // 0x80094748: nop

L_8009474C:
    // 0x8009474C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094750: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094754: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094758: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009475C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094760: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094764: jal         0x80090784
    // 0x80094768: nop

    func_80090784(rdram, ctx);
        goto after_17;
    // 0x80094768: nop

    after_17:
L_8009476C:
    // 0x8009476C: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x80094770: nop

    // 0x80094774: andi        $t3, $t1, 0x40
    ctx->r11 = ctx->r9 & 0X40;
    // 0x80094778: beq         $t3, $zero, L_800947A8
    if (ctx->r11 == 0) {
        // 0x8009477C: nop
    
            goto L_800947A8;
    }
    // 0x8009477C: nop

    // 0x80094780: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094784: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094788: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009478C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094790: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094794: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094798: jal         0x80090784
    // 0x8009479C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_18;
    // 0x8009479C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_18:
    // 0x800947A0: b           L_800947C8
    // 0x800947A4: nop

        goto L_800947C8;
    // 0x800947A4: nop

L_800947A8:
    // 0x800947A8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800947AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800947B0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800947B4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800947B8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800947BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800947C0: jal         0x80090784
    // 0x800947C4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_19;
    // 0x800947C4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_19:
L_800947C8:
    // 0x800947C8: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x800947CC: nop

    // 0x800947D0: andi        $t4, $t2, 0x20
    ctx->r12 = ctx->r10 & 0X20;
    // 0x800947D4: beq         $t4, $zero, L_80094804
    if (ctx->r12 == 0) {
        // 0x800947D8: nop
    
            goto L_80094804;
    }
    // 0x800947D8: nop

    // 0x800947DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800947E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800947E4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800947E8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800947EC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800947F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800947F4: jal         0x80090784
    // 0x800947F8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_20;
    // 0x800947F8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_20:
    // 0x800947FC: b           L_80094824
    // 0x80094800: nop

        goto L_80094824;
    // 0x80094800: nop

L_80094804:
    // 0x80094804: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094808: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009480C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094810: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094814: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094818: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009481C: jal         0x80090784
    // 0x80094820: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_21;
    // 0x80094820: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_21:
L_80094824:
    // 0x80094824: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x80094828: nop

    // 0x8009482C: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80094830: beq         $t6, $zero, L_80094860
    if (ctx->r14 == 0) {
        // 0x80094834: nop
    
            goto L_80094860;
    }
    // 0x80094834: nop

    // 0x80094838: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009483C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094840: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094844: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094848: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009484C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094850: jal         0x80090784
    // 0x80094854: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_22;
    // 0x80094854: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_22:
    // 0x80094858: b           L_80094880
    // 0x8009485C: nop

        goto L_80094880;
    // 0x8009485C: nop

L_80094860:
    // 0x80094860: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094864: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094868: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009486C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094870: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094874: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094878: jal         0x80090784
    // 0x8009487C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_23;
    // 0x8009487C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_23:
L_80094880:
    // 0x80094880: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x80094884: nop

    // 0x80094888: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8009488C: beq         $t8, $zero, L_800948BC
    if (ctx->r24 == 0) {
        // 0x80094890: nop
    
            goto L_800948BC;
    }
    // 0x80094890: nop

    // 0x80094894: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094898: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009489C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800948A0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800948A4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800948A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800948AC: jal         0x80090784
    // 0x800948B0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_24;
    // 0x800948B0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_24:
    // 0x800948B4: b           L_800948DC
    // 0x800948B8: nop

        goto L_800948DC;
    // 0x800948B8: nop

L_800948BC:
    // 0x800948BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800948C0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800948C4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800948C8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800948CC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800948D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800948D4: jal         0x80090784
    // 0x800948D8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_25;
    // 0x800948D8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_25:
L_800948DC:
    // 0x800948DC: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x800948E0: nop

    // 0x800948E4: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x800948E8: beq         $t0, $zero, L_80094918
    if (ctx->r8 == 0) {
        // 0x800948EC: nop
    
            goto L_80094918;
    }
    // 0x800948EC: nop

    // 0x800948F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800948F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800948F8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800948FC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094900: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094904: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094908: jal         0x80090784
    // 0x8009490C: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_26;
    // 0x8009490C: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_26:
    // 0x80094910: b           L_80094938
    // 0x80094914: nop

        goto L_80094938;
    // 0x80094914: nop

L_80094918:
    // 0x80094918: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009491C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094920: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094924: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094928: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009492C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094930: jal         0x80090784
    // 0x80094934: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_27;
    // 0x80094934: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_27:
L_80094938:
    // 0x80094938: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x8009493C: nop

    // 0x80094940: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x80094944: beq         $t3, $zero, L_80094974
    if (ctx->r11 == 0) {
        // 0x80094948: nop
    
            goto L_80094974;
    }
    // 0x80094948: nop

    // 0x8009494C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094950: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094954: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094958: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009495C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094960: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094964: jal         0x80090784
    // 0x80094968: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_28;
    // 0x80094968: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_28:
    // 0x8009496C: b           L_80094994
    // 0x80094970: nop

        goto L_80094994;
    // 0x80094970: nop

L_80094974:
    // 0x80094974: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094978: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009497C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094980: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094984: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094988: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009498C: jal         0x80090784
    // 0x80094990: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_29;
    // 0x80094990: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_29:
L_80094994:
    // 0x80094994: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x80094998: nop

    // 0x8009499C: andi        $t4, $t2, 0x1
    ctx->r12 = ctx->r10 & 0X1;
    // 0x800949A0: beq         $t4, $zero, L_800949D0
    if (ctx->r12 == 0) {
        // 0x800949A4: nop
    
            goto L_800949D0;
    }
    // 0x800949A4: nop

    // 0x800949A8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800949AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800949B0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800949B4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800949B8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800949BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800949C0: jal         0x80090784
    // 0x800949C4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_30;
    // 0x800949C4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_30:
    // 0x800949C8: b           L_800949F0
    // 0x800949CC: nop

        goto L_800949F0;
    // 0x800949CC: nop

L_800949D0:
    // 0x800949D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800949D4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800949D8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800949DC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800949E0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800949E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800949E8: jal         0x80090784
    // 0x800949EC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_31;
    // 0x800949EC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_31:
L_800949F0:
    // 0x800949F0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800949F4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800949F8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800949FC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80094A00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80094A04: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80094A08: lw          $t1, -0x780($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X780);
    // 0x80094A0C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80094A10: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80094A14: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80094A18: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80094A1C: lbu         $t2, -0x11FF($t3)
    ctx->r10 = MEM_BU(ctx->r11, -0X11FF);
    // 0x80094A20: nop

    // 0x80094A24: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
    // 0x80094A28: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x80094A2C: nop

    // 0x80094A30: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x80094A34: beq         $t5, $zero, L_80094A64
    if (ctx->r13 == 0) {
        // 0x80094A38: nop
    
            goto L_80094A64;
    }
    // 0x80094A38: nop

    // 0x80094A3C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094A40: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094A44: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094A48: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094A4C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094A50: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094A54: jal         0x80090784
    // 0x80094A58: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_32;
    // 0x80094A58: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_32:
    // 0x80094A5C: b           L_80094A84
    // 0x80094A60: nop

        goto L_80094A84;
    // 0x80094A60: nop

L_80094A64:
    // 0x80094A64: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094A68: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094A6C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094A70: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094A74: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094A78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094A7C: jal         0x80090784
    // 0x80094A80: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_33;
    // 0x80094A80: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_33:
L_80094A84:
    // 0x80094A84: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80094A88: nop

    // 0x80094A8C: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80094A90: beq         $t8, $zero, L_80094AC0
    if (ctx->r24 == 0) {
        // 0x80094A94: nop
    
            goto L_80094AC0;
    }
    // 0x80094A94: nop

    // 0x80094A98: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094A9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094AA0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094AA4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094AA8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094AAC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094AB0: jal         0x80090784
    // 0x80094AB4: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_34;
    // 0x80094AB4: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_34:
    // 0x80094AB8: b           L_80094AE0
    // 0x80094ABC: nop

        goto L_80094AE0;
    // 0x80094ABC: nop

L_80094AC0:
    // 0x80094AC0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094AC4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094AC8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094ACC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094AD0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094AD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094AD8: jal         0x80090784
    // 0x80094ADC: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_35;
    // 0x80094ADC: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_35:
L_80094AE0:
    // 0x80094AE0: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x80094AE4: nop

    // 0x80094AE8: andi        $t9, $t7, 0x20
    ctx->r25 = ctx->r15 & 0X20;
    // 0x80094AEC: beq         $t9, $zero, L_80094B1C
    if (ctx->r25 == 0) {
        // 0x80094AF0: nop
    
            goto L_80094B1C;
    }
    // 0x80094AF0: nop

    // 0x80094AF4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094AF8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094AFC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094B00: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094B04: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B0C: jal         0x80090784
    // 0x80094B10: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_36;
    // 0x80094B10: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_36:
    // 0x80094B14: b           L_80094B3C
    // 0x80094B18: nop

        goto L_80094B3C;
    // 0x80094B18: nop

L_80094B1C:
    // 0x80094B1C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094B20: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094B24: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094B28: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094B2C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094B30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B34: jal         0x80090784
    // 0x80094B38: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_37;
    // 0x80094B38: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_37:
L_80094B3C:
    // 0x80094B3C: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x80094B40: nop

    // 0x80094B44: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80094B48: beq         $t1, $zero, L_80094B78
    if (ctx->r9 == 0) {
        // 0x80094B4C: nop
    
            goto L_80094B78;
    }
    // 0x80094B4C: nop

    // 0x80094B50: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094B54: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094B58: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094B5C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094B60: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094B64: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B68: jal         0x80090784
    // 0x80094B6C: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_38;
    // 0x80094B6C: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_38:
    // 0x80094B70: b           L_80094B98
    // 0x80094B74: nop

        goto L_80094B98;
    // 0x80094B74: nop

L_80094B78:
    // 0x80094B78: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094B7C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094B80: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094B84: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094B88: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094B8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B90: jal         0x80090784
    // 0x80094B94: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_39;
    // 0x80094B94: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_39:
L_80094B98:
    // 0x80094B98: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80094B9C: nop

    // 0x80094BA0: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80094BA4: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x80094BA8: bne         $at, $zero, L_8009464C
    if (ctx->r1 != 0) {
        // 0x80094BAC: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_8009464C;
    }
    // 0x80094BAC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80094BB0: b           L_80095E44
    // 0x80094BB4: nop

        goto L_80095E44;
    // 0x80094BB4: nop

L_80094BB8:
    // 0x80094BB8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80094BBC:
    // 0x80094BBC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80094BC0: lw          $t4, 0x6BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA0);
    // 0x80094BC4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80094BC8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80094BCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094BD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80094BD4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80094BD8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80094BDC: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094BE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80094BE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094BE8: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80094BEC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80094BF0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80094BF4: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x80094BF8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80094BFC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80094C00: lw          $t7, 0x6C14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C14);
    // 0x80094C04: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80094C08: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80094C0C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80094C10: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80094C14: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80094C18: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80094C1C: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80094C20: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80094C24: nop

    // 0x80094C28: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80094C2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80094C30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80094C34: nop

    // 0x80094C38: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80094C3C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80094C40: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80094C44: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80094C48: nop

    // 0x80094C4C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80094C50: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80094C54: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80094C58: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80094C5C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80094C60: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80094C64: lw          $t8, -0x780($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X780);
    // 0x80094C68: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x80094C6C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80094C70: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80094C74: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80094C78: lbu         $t9, -0x1200($t7)
    ctx->r25 = MEM_BU(ctx->r15, -0X1200);
    // 0x80094C7C: nop

    // 0x80094C80: sb          $t9, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r25;
    // 0x80094C84: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x80094C88: nop

    // 0x80094C8C: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80094C90: beq         $t1, $zero, L_80094D4C
    if (ctx->r9 == 0) {
        // 0x80094C94: nop
    
            goto L_80094D4C;
    }
    // 0x80094C94: nop

    // 0x80094C98: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094C9C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80094CA0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80094CA4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80094CA8: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094CAC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094CB0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80094CB4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094CB8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80094CBC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094CC0: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80094CC4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094CC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094CCC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094CD0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80094CD4: beq         $t4, $zero, L_80094D28
    if (ctx->r12 == 0) {
        // 0x80094CD8: nop
    
            goto L_80094D28;
    }
    // 0x80094CD8: nop

    // 0x80094CDC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094CE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80094CE4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80094CE8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80094CEC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80094CF0: nop

    // 0x80094CF4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80094CF8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80094CFC: nop

    // 0x80094D00: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80094D04: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80094D08: bne         $t4, $zero, L_80094D20
    if (ctx->r12 != 0) {
        // 0x80094D0C: nop
    
            goto L_80094D20;
    }
    // 0x80094D0C: nop

    // 0x80094D10: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80094D14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094D18: b           L_80094D38
    // 0x80094D1C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80094D38;
    // 0x80094D1C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80094D20:
    // 0x80094D20: b           L_80094D38
    // 0x80094D24: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80094D38;
    // 0x80094D24: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80094D28:
    // 0x80094D28: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80094D2C: nop

    // 0x80094D30: bltz        $t4, L_80094D20
    if (SIGNED(ctx->r12) < 0) {
        // 0x80094D34: nop
    
            goto L_80094D20;
    }
    // 0x80094D34: nop

L_80094D38:
    // 0x80094D38: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80094D3C: jal         0x800908A0
    // 0x80094D40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800908A0(rdram, ctx);
        goto after_40;
    // 0x80094D40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_40:
    // 0x80094D44: b           L_80094DF8
    // 0x80094D48: nop

        goto L_80094DF8;
    // 0x80094D48: nop

L_80094D4C:
    // 0x80094D4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094D50: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80094D54: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094D58: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80094D5C: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094D60: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094D64: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80094D68: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094D6C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80094D70: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094D74: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80094D78: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094D7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094D80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094D84: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80094D88: beq         $t5, $zero, L_80094DDC
    if (ctx->r13 == 0) {
        // 0x80094D8C: nop
    
            goto L_80094DDC;
    }
    // 0x80094D8C: nop

    // 0x80094D90: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094D94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80094D98: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094D9C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80094DA0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80094DA4: nop

    // 0x80094DA8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80094DAC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80094DB0: nop

    // 0x80094DB4: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80094DB8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80094DBC: bne         $t5, $zero, L_80094DD4
    if (ctx->r13 != 0) {
        // 0x80094DC0: nop
    
            goto L_80094DD4;
    }
    // 0x80094DC0: nop

    // 0x80094DC4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80094DC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094DCC: b           L_80094DEC
    // 0x80094DD0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80094DEC;
    // 0x80094DD0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80094DD4:
    // 0x80094DD4: b           L_80094DEC
    // 0x80094DD8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80094DEC;
    // 0x80094DD8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80094DDC:
    // 0x80094DDC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80094DE0: nop

    // 0x80094DE4: bltz        $t5, L_80094DD4
    if (SIGNED(ctx->r13) < 0) {
        // 0x80094DE8: nop
    
            goto L_80094DD4;
    }
    // 0x80094DE8: nop

L_80094DEC:
    // 0x80094DEC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80094DF0: jal         0x800908A0
    // 0x80094DF4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_41;
    // 0x80094DF4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_41:
L_80094DF8:
    // 0x80094DF8: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80094DFC: nop

    // 0x80094E00: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80094E04: beq         $t8, $zero, L_80094EC0
    if (ctx->r24 == 0) {
        // 0x80094E08: nop
    
            goto L_80094EC0;
    }
    // 0x80094E08: nop

    // 0x80094E0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094E10: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80094E14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80094E18: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80094E1C: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094E20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094E24: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80094E28: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094E2C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80094E30: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094E34: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80094E38: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094E3C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094E40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094E44: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80094E48: beq         $t9, $zero, L_80094E9C
    if (ctx->r25 == 0) {
        // 0x80094E4C: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80094E9C;
    }
    // 0x80094E4C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80094E50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094E54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80094E58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80094E5C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80094E60: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80094E64: nop

    // 0x80094E68: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80094E6C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80094E70: nop

    // 0x80094E74: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80094E78: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80094E7C: bne         $t9, $zero, L_80094E94
    if (ctx->r25 != 0) {
        // 0x80094E80: nop
    
            goto L_80094E94;
    }
    // 0x80094E80: nop

    // 0x80094E84: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80094E88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094E8C: b           L_80094EAC
    // 0x80094E90: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80094EAC;
    // 0x80094E90: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80094E94:
    // 0x80094E94: b           L_80094EAC
    // 0x80094E98: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80094EAC;
    // 0x80094E98: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80094E9C:
    // 0x80094E9C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80094EA0: nop

    // 0x80094EA4: bltz        $t9, L_80094E94
    if (SIGNED(ctx->r25) < 0) {
        // 0x80094EA8: nop
    
            goto L_80094E94;
    }
    // 0x80094EA8: nop

L_80094EAC:
    // 0x80094EAC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80094EB0: jal         0x800908A0
    // 0x80094EB4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_42;
    // 0x80094EB4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_42:
    // 0x80094EB8: b           L_80094F6C
    // 0x80094EBC: nop

        goto L_80094F6C;
    // 0x80094EBC: nop

L_80094EC0:
    // 0x80094EC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094EC4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80094EC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80094ECC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80094ED0: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094ED4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094ED8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80094EDC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094EE0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80094EE4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094EE8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80094EEC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094EF0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094EF4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094EF8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80094EFC: beq         $t1, $zero, L_80094F50
    if (ctx->r9 == 0) {
        // 0x80094F00: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80094F50;
    }
    // 0x80094F00: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80094F04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094F08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80094F0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80094F10: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80094F14: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80094F18: nop

    // 0x80094F1C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80094F20: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80094F24: nop

    // 0x80094F28: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80094F2C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80094F30: bne         $t1, $zero, L_80094F48
    if (ctx->r9 != 0) {
        // 0x80094F34: nop
    
            goto L_80094F48;
    }
    // 0x80094F34: nop

    // 0x80094F38: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80094F3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094F40: b           L_80094F60
    // 0x80094F44: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80094F60;
    // 0x80094F44: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80094F48:
    // 0x80094F48: b           L_80094F60
    // 0x80094F4C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80094F60;
    // 0x80094F4C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80094F50:
    // 0x80094F50: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80094F54: nop

    // 0x80094F58: bltz        $t1, L_80094F48
    if (SIGNED(ctx->r9) < 0) {
        // 0x80094F5C: nop
    
            goto L_80094F48;
    }
    // 0x80094F5C: nop

L_80094F60:
    // 0x80094F60: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80094F64: jal         0x800908A0
    // 0x80094F68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_43;
    // 0x80094F68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_43:
L_80094F6C:
    // 0x80094F6C: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x80094F70: nop

    // 0x80094F74: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80094F78: beq         $t4, $zero, L_80095034
    if (ctx->r12 == 0) {
        // 0x80094F7C: nop
    
            goto L_80095034;
    }
    // 0x80094F7C: nop

    // 0x80094F80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80094F84: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80094F88: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094F8C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80094F90: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80094F94: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80094F98: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80094F9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094FA0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80094FA4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094FA8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80094FAC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094FB0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094FB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80094FB8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80094FBC: beq         $t5, $zero, L_80095010
    if (ctx->r13 == 0) {
        // 0x80094FC0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80095010;
    }
    // 0x80094FC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80094FC4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80094FC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80094FCC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094FD0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80094FD4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80094FD8: nop

    // 0x80094FDC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80094FE0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80094FE4: nop

    // 0x80094FE8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80094FEC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80094FF0: bne         $t5, $zero, L_80095008
    if (ctx->r13 != 0) {
        // 0x80094FF4: nop
    
            goto L_80095008;
    }
    // 0x80094FF4: nop

    // 0x80094FF8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80094FFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095000: b           L_80095020
    // 0x80095004: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80095020;
    // 0x80095004: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80095008:
    // 0x80095008: b           L_80095020
    // 0x8009500C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80095020;
    // 0x8009500C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80095010:
    // 0x80095010: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80095014: nop

    // 0x80095018: bltz        $t5, L_80095008
    if (SIGNED(ctx->r13) < 0) {
        // 0x8009501C: nop
    
            goto L_80095008;
    }
    // 0x8009501C: nop

L_80095020:
    // 0x80095020: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095024: jal         0x800908A0
    // 0x80095028: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_44;
    // 0x80095028: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_44:
    // 0x8009502C: b           L_800950E0
    // 0x80095030: nop

        goto L_800950E0;
    // 0x80095030: nop

L_80095034:
    // 0x80095034: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095038: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009503C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095040: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095044: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095048: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009504C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095050: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095054: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80095058: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009505C: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80095060: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095064: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095068: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009506C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80095070: beq         $t8, $zero, L_800950C4
    if (ctx->r24 == 0) {
        // 0x80095074: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800950C4;
    }
    // 0x80095074: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80095078: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009507C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095080: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095084: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095088: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8009508C: nop

    // 0x80095090: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095094: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80095098: nop

    // 0x8009509C: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800950A0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800950A4: bne         $t8, $zero, L_800950BC
    if (ctx->r24 != 0) {
        // 0x800950A8: nop
    
            goto L_800950BC;
    }
    // 0x800950A8: nop

    // 0x800950AC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800950B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800950B4: b           L_800950D4
    // 0x800950B8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800950D4;
    // 0x800950B8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800950BC:
    // 0x800950BC: b           L_800950D4
    // 0x800950C0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800950D4;
    // 0x800950C0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800950C4:
    // 0x800950C4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800950C8: nop

    // 0x800950CC: bltz        $t8, L_800950BC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800950D0: nop
    
            goto L_800950BC;
    }
    // 0x800950D0: nop

L_800950D4:
    // 0x800950D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800950D8: jal         0x800908A0
    // 0x800950DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_45;
    // 0x800950DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_45:
L_800950E0:
    // 0x800950E0: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x800950E4: nop

    // 0x800950E8: andi        $t9, $t7, 0x10
    ctx->r25 = ctx->r15 & 0X10;
    // 0x800950EC: beq         $t9, $zero, L_800951A8
    if (ctx->r25 == 0) {
        // 0x800950F0: nop
    
            goto L_800951A8;
    }
    // 0x800950F0: nop

    // 0x800950F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800950F8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800950FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095100: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095104: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095108: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009510C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095110: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095114: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095118: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009511C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095120: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095124: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095128: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009512C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095130: beq         $t1, $zero, L_80095184
    if (ctx->r9 == 0) {
        // 0x80095134: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_80095184;
    }
    // 0x80095134: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80095138: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009513C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095140: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095144: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80095148: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009514C: nop

    // 0x80095150: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80095154: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095158: nop

    // 0x8009515C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095160: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095164: bne         $t1, $zero, L_8009517C
    if (ctx->r9 != 0) {
        // 0x80095168: nop
    
            goto L_8009517C;
    }
    // 0x80095168: nop

    // 0x8009516C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80095170: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095174: b           L_80095194
    // 0x80095178: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80095194;
    // 0x80095178: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8009517C:
    // 0x8009517C: b           L_80095194
    // 0x80095180: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80095194;
    // 0x80095180: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80095184:
    // 0x80095184: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80095188: nop

    // 0x8009518C: bltz        $t1, L_8009517C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80095190: nop
    
            goto L_8009517C;
    }
    // 0x80095190: nop

L_80095194:
    // 0x80095194: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80095198: jal         0x800908A0
    // 0x8009519C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_46;
    // 0x8009519C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_46:
    // 0x800951A0: b           L_80095254
    // 0x800951A4: nop

        goto L_80095254;
    // 0x800951A4: nop

L_800951A8:
    // 0x800951A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800951AC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800951B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800951B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800951B8: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800951BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800951C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800951C4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800951C8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800951CC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800951D0: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800951D4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800951D8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800951DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800951E0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800951E4: beq         $t4, $zero, L_80095238
    if (ctx->r12 == 0) {
        // 0x800951E8: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_80095238;
    }
    // 0x800951E8: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x800951EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800951F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800951F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800951F8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800951FC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80095200: nop

    // 0x80095204: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80095208: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8009520C: nop

    // 0x80095210: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80095214: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80095218: bne         $t4, $zero, L_80095230
    if (ctx->r12 != 0) {
        // 0x8009521C: nop
    
            goto L_80095230;
    }
    // 0x8009521C: nop

    // 0x80095220: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80095224: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095228: b           L_80095248
    // 0x8009522C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80095248;
    // 0x8009522C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80095230:
    // 0x80095230: b           L_80095248
    // 0x80095234: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80095248;
    // 0x80095234: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80095238:
    // 0x80095238: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8009523C: nop

    // 0x80095240: bltz        $t4, L_80095230
    if (SIGNED(ctx->r12) < 0) {
        // 0x80095244: nop
    
            goto L_80095230;
    }
    // 0x80095244: nop

L_80095248:
    // 0x80095248: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009524C: jal         0x800908A0
    // 0x80095250: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800908A0(rdram, ctx);
        goto after_47;
    // 0x80095250: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_47:
L_80095254:
    // 0x80095254: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x80095258: nop

    // 0x8009525C: andi        $t5, $t2, 0x8
    ctx->r13 = ctx->r10 & 0X8;
    // 0x80095260: beq         $t5, $zero, L_8009531C
    if (ctx->r13 == 0) {
        // 0x80095264: nop
    
            goto L_8009531C;
    }
    // 0x80095264: nop

    // 0x80095268: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009526C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80095270: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095274: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095278: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009527C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095280: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095284: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095288: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009528C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095290: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80095294: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095298: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009529C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800952A0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800952A4: beq         $t8, $zero, L_800952F8
    if (ctx->r24 == 0) {
        // 0x800952A8: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800952F8;
    }
    // 0x800952A8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800952AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800952B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800952B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800952B8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800952BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800952C0: nop

    // 0x800952C4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800952C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800952CC: nop

    // 0x800952D0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800952D4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800952D8: bne         $t8, $zero, L_800952F0
    if (ctx->r24 != 0) {
        // 0x800952DC: nop
    
            goto L_800952F0;
    }
    // 0x800952DC: nop

    // 0x800952E0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800952E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800952E8: b           L_80095308
    // 0x800952EC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80095308;
    // 0x800952EC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800952F0:
    // 0x800952F0: b           L_80095308
    // 0x800952F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80095308;
    // 0x800952F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800952F8:
    // 0x800952F8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800952FC: nop

    // 0x80095300: bltz        $t8, L_800952F0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80095304: nop
    
            goto L_800952F0;
    }
    // 0x80095304: nop

L_80095308:
    // 0x80095308: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009530C: jal         0x800908A0
    // 0x80095310: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_48;
    // 0x80095310: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_48:
    // 0x80095314: b           L_800953C8
    // 0x80095318: nop

        goto L_800953C8;
    // 0x80095318: nop

L_8009531C:
    // 0x8009531C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095320: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095324: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80095328: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8009532C: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095330: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095334: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095338: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009533C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095340: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095344: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80095348: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009534C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095350: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095354: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80095358: beq         $t9, $zero, L_800953AC
    if (ctx->r25 == 0) {
        // 0x8009535C: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800953AC;
    }
    // 0x8009535C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80095360: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095364: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095368: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009536C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80095370: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80095374: nop

    // 0x80095378: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009537C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095380: nop

    // 0x80095384: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80095388: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8009538C: bne         $t9, $zero, L_800953A4
    if (ctx->r25 != 0) {
        // 0x80095390: nop
    
            goto L_800953A4;
    }
    // 0x80095390: nop

    // 0x80095394: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80095398: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009539C: b           L_800953BC
    // 0x800953A0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800953BC;
    // 0x800953A0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800953A4:
    // 0x800953A4: b           L_800953BC
    // 0x800953A8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800953BC;
    // 0x800953A8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800953AC:
    // 0x800953AC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800953B0: nop

    // 0x800953B4: bltz        $t9, L_800953A4
    if (SIGNED(ctx->r25) < 0) {
        // 0x800953B8: nop
    
            goto L_800953A4;
    }
    // 0x800953B8: nop

L_800953BC:
    // 0x800953BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800953C0: jal         0x800908A0
    // 0x800953C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_49;
    // 0x800953C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_49:
L_800953C8:
    // 0x800953C8: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x800953CC: nop

    // 0x800953D0: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x800953D4: beq         $t1, $zero, L_80095490
    if (ctx->r9 == 0) {
        // 0x800953D8: nop
    
            goto L_80095490;
    }
    // 0x800953D8: nop

    // 0x800953DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800953E0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800953E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800953E8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800953EC: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800953F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800953F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800953F8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800953FC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80095400: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095404: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80095408: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009540C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095410: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095414: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80095418: beq         $t4, $zero, L_8009546C
    if (ctx->r12 == 0) {
        // 0x8009541C: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_8009546C;
    }
    // 0x8009541C: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x80095420: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095424: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095428: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009542C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095430: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80095434: nop

    // 0x80095438: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8009543C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80095440: nop

    // 0x80095444: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80095448: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8009544C: bne         $t4, $zero, L_80095464
    if (ctx->r12 != 0) {
        // 0x80095450: nop
    
            goto L_80095464;
    }
    // 0x80095450: nop

    // 0x80095454: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80095458: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009545C: b           L_8009547C
    // 0x80095460: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8009547C;
    // 0x80095460: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80095464:
    // 0x80095464: b           L_8009547C
    // 0x80095468: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8009547C;
    // 0x80095468: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_8009546C:
    // 0x8009546C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80095470: nop

    // 0x80095474: bltz        $t4, L_80095464
    if (SIGNED(ctx->r12) < 0) {
        // 0x80095478: nop
    
            goto L_80095464;
    }
    // 0x80095478: nop

L_8009547C:
    // 0x8009547C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80095480: jal         0x800908A0
    // 0x80095484: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800908A0(rdram, ctx);
        goto after_50;
    // 0x80095484: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_50:
    // 0x80095488: b           L_8009553C
    // 0x8009548C: nop

        goto L_8009553C;
    // 0x8009548C: nop

L_80095490:
    // 0x80095490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095494: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80095498: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009549C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800954A0: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800954A4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800954A8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800954AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800954B0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800954B4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800954B8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800954BC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800954C0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800954C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800954C8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800954CC: beq         $t5, $zero, L_80095520
    if (ctx->r13 == 0) {
        // 0x800954D0: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_80095520;
    }
    // 0x800954D0: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x800954D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800954D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800954DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800954E0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800954E4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800954E8: nop

    // 0x800954EC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800954F0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800954F4: nop

    // 0x800954F8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800954FC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80095500: bne         $t5, $zero, L_80095518
    if (ctx->r13 != 0) {
        // 0x80095504: nop
    
            goto L_80095518;
    }
    // 0x80095504: nop

    // 0x80095508: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8009550C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095510: b           L_80095530
    // 0x80095514: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80095530;
    // 0x80095514: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80095518:
    // 0x80095518: b           L_80095530
    // 0x8009551C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80095530;
    // 0x8009551C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80095520:
    // 0x80095520: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80095524: nop

    // 0x80095528: bltz        $t5, L_80095518
    if (SIGNED(ctx->r13) < 0) {
        // 0x8009552C: nop
    
            goto L_80095518;
    }
    // 0x8009552C: nop

L_80095530:
    // 0x80095530: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095534: jal         0x800908A0
    // 0x80095538: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_51;
    // 0x80095538: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_51:
L_8009553C:
    // 0x8009553C: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80095540: nop

    // 0x80095544: andi        $t8, $t6, 0x2
    ctx->r24 = ctx->r14 & 0X2;
    // 0x80095548: beq         $t8, $zero, L_80095604
    if (ctx->r24 == 0) {
        // 0x8009554C: nop
    
            goto L_80095604;
    }
    // 0x8009554C: nop

    // 0x80095550: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095554: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095558: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009555C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80095560: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095564: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095568: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8009556C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095570: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095574: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095578: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8009557C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095580: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095584: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095588: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8009558C: beq         $t9, $zero, L_800955E0
    if (ctx->r25 == 0) {
        // 0x80095590: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_800955E0;
    }
    // 0x80095590: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80095594: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095598: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009559C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800955A0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800955A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800955A8: nop

    // 0x800955AC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800955B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800955B4: nop

    // 0x800955B8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800955BC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800955C0: bne         $t9, $zero, L_800955D8
    if (ctx->r25 != 0) {
        // 0x800955C4: nop
    
            goto L_800955D8;
    }
    // 0x800955C4: nop

    // 0x800955C8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800955CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800955D0: b           L_800955F0
    // 0x800955D4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800955F0;
    // 0x800955D4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800955D8:
    // 0x800955D8: b           L_800955F0
    // 0x800955DC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800955F0;
    // 0x800955DC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800955E0:
    // 0x800955E0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800955E4: nop

    // 0x800955E8: bltz        $t9, L_800955D8
    if (SIGNED(ctx->r25) < 0) {
        // 0x800955EC: nop
    
            goto L_800955D8;
    }
    // 0x800955EC: nop

L_800955F0:
    // 0x800955F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800955F4: jal         0x800908A0
    // 0x800955F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_52;
    // 0x800955F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_52:
    // 0x800955FC: b           L_800956B0
    // 0x80095600: nop

        goto L_800956B0;
    // 0x80095600: nop

L_80095604:
    // 0x80095604: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095608: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8009560C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095610: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095614: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095618: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009561C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80095620: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095624: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095628: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009562C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095630: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095634: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095638: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009563C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095640: beq         $t1, $zero, L_80095694
    if (ctx->r9 == 0) {
        // 0x80095644: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_80095694;
    }
    // 0x80095644: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80095648: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009564C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095650: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095654: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095658: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009565C: nop

    // 0x80095660: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80095664: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095668: nop

    // 0x8009566C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095670: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095674: bne         $t1, $zero, L_8009568C
    if (ctx->r9 != 0) {
        // 0x80095678: nop
    
            goto L_8009568C;
    }
    // 0x80095678: nop

    // 0x8009567C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80095680: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095684: b           L_800956A4
    // 0x80095688: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800956A4;
    // 0x80095688: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8009568C:
    // 0x8009568C: b           L_800956A4
    // 0x80095690: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800956A4;
    // 0x80095690: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80095694:
    // 0x80095694: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80095698: nop

    // 0x8009569C: bltz        $t1, L_8009568C
    if (SIGNED(ctx->r9) < 0) {
        // 0x800956A0: nop
    
            goto L_8009568C;
    }
    // 0x800956A0: nop

L_800956A4:
    // 0x800956A4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800956A8: jal         0x800908A0
    // 0x800956AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_53;
    // 0x800956AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_53:
L_800956B0:
    // 0x800956B0: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x800956B4: nop

    // 0x800956B8: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800956BC: beq         $t4, $zero, L_80095778
    if (ctx->r12 == 0) {
        // 0x800956C0: nop
    
            goto L_80095778;
    }
    // 0x800956C0: nop

    // 0x800956C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800956C8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800956CC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800956D0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800956D4: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800956D8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800956DC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800956E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800956E4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800956E8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800956EC: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800956F0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800956F4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800956F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800956FC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80095700: beq         $t5, $zero, L_80095754
    if (ctx->r13 == 0) {
        // 0x80095704: addiu       $a3, $a3, 0xE
        ctx->r7 = ADD32(ctx->r7, 0XE);
            goto L_80095754;
    }
    // 0x80095704: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x80095708: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009570C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095710: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80095714: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095718: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8009571C: nop

    // 0x80095720: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095724: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80095728: nop

    // 0x8009572C: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80095730: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80095734: bne         $t5, $zero, L_8009574C
    if (ctx->r13 != 0) {
        // 0x80095738: nop
    
            goto L_8009574C;
    }
    // 0x80095738: nop

    // 0x8009573C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80095740: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095744: b           L_80095764
    // 0x80095748: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80095764;
    // 0x80095748: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8009574C:
    // 0x8009574C: b           L_80095764
    // 0x80095750: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80095764;
    // 0x80095750: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80095754:
    // 0x80095754: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80095758: nop

    // 0x8009575C: bltz        $t5, L_8009574C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80095760: nop
    
            goto L_8009574C;
    }
    // 0x80095760: nop

L_80095764:
    // 0x80095764: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095768: jal         0x800908A0
    // 0x8009576C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_54;
    // 0x8009576C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_54:
    // 0x80095770: b           L_80095824
    // 0x80095774: nop

        goto L_80095824;
    // 0x80095774: nop

L_80095778:
    // 0x80095778: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009577C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80095780: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095784: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095788: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009578C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095790: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095794: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095798: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8009579C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800957A0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800957A4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800957A8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800957AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800957B0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800957B4: beq         $t8, $zero, L_80095808
    if (ctx->r24 == 0) {
        // 0x800957B8: addiu       $a3, $a3, 0xE
        ctx->r7 = ADD32(ctx->r7, 0XE);
            goto L_80095808;
    }
    // 0x800957B8: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x800957BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800957C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800957C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800957C8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800957CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800957D0: nop

    // 0x800957D4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800957D8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800957DC: nop

    // 0x800957E0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800957E4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800957E8: bne         $t8, $zero, L_80095800
    if (ctx->r24 != 0) {
        // 0x800957EC: nop
    
            goto L_80095800;
    }
    // 0x800957EC: nop

    // 0x800957F0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800957F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800957F8: b           L_80095818
    // 0x800957FC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80095818;
    // 0x800957FC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80095800:
    // 0x80095800: b           L_80095818
    // 0x80095804: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80095818;
    // 0x80095804: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80095808:
    // 0x80095808: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8009580C: nop

    // 0x80095810: bltz        $t8, L_80095800
    if (SIGNED(ctx->r24) < 0) {
        // 0x80095814: nop
    
            goto L_80095800;
    }
    // 0x80095814: nop

L_80095818:
    // 0x80095818: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8009581C: jal         0x800908A0
    // 0x80095820: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_55;
    // 0x80095820: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_55:
L_80095824:
    // 0x80095824: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80095828: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8009582C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80095830: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80095834: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80095838: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8009583C: lw          $t2, -0x780($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X780);
    // 0x80095840: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80095844: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80095848: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8009584C: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x80095850: lbu         $t6, -0x11FF($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X11FF);
    // 0x80095854: nop

    // 0x80095858: sb          $t6, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r14;
    // 0x8009585C: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x80095860: nop

    // 0x80095864: andi        $t7, $t8, 0x80
    ctx->r15 = ctx->r24 & 0X80;
    // 0x80095868: beq         $t7, $zero, L_80095924
    if (ctx->r15 == 0) {
        // 0x8009586C: nop
    
            goto L_80095924;
    }
    // 0x8009586C: nop

    // 0x80095870: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095874: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095878: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009587C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095880: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095884: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095888: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009588C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095890: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095894: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095898: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x8009589C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800958A0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800958A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800958A8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800958AC: beq         $t1, $zero, L_80095900
    if (ctx->r9 == 0) {
        // 0x800958B0: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80095900;
    }
    // 0x800958B0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800958B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800958B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800958BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800958C0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800958C4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800958C8: nop

    // 0x800958CC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800958D0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800958D4: nop

    // 0x800958D8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800958DC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800958E0: bne         $t1, $zero, L_800958F8
    if (ctx->r9 != 0) {
        // 0x800958E4: nop
    
            goto L_800958F8;
    }
    // 0x800958E4: nop

    // 0x800958E8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800958EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800958F0: b           L_80095910
    // 0x800958F4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80095910;
    // 0x800958F4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800958F8:
    // 0x800958F8: b           L_80095910
    // 0x800958FC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80095910;
    // 0x800958FC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80095900:
    // 0x80095900: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80095904: nop

    // 0x80095908: bltz        $t1, L_800958F8
    if (SIGNED(ctx->r9) < 0) {
        // 0x8009590C: nop
    
            goto L_800958F8;
    }
    // 0x8009590C: nop

L_80095910:
    // 0x80095910: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80095914: jal         0x800908A0
    // 0x80095918: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_56;
    // 0x80095918: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_56:
    // 0x8009591C: b           L_800959D0
    // 0x80095920: nop

        goto L_800959D0;
    // 0x80095920: nop

L_80095924:
    // 0x80095924: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095928: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8009592C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095930: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80095934: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095938: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009593C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095940: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095944: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80095948: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009594C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80095950: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095954: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095958: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009595C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80095960: beq         $t3, $zero, L_800959B4
    if (ctx->r11 == 0) {
        // 0x80095964: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800959B4;
    }
    // 0x80095964: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80095968: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009596C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095970: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095974: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095978: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009597C: nop

    // 0x80095980: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095984: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80095988: nop

    // 0x8009598C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80095990: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80095994: bne         $t3, $zero, L_800959AC
    if (ctx->r11 != 0) {
        // 0x80095998: nop
    
            goto L_800959AC;
    }
    // 0x80095998: nop

    // 0x8009599C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800959A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800959A4: b           L_800959C4
    // 0x800959A8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800959C4;
    // 0x800959A8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800959AC:
    // 0x800959AC: b           L_800959C4
    // 0x800959B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800959C4;
    // 0x800959B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800959B4:
    // 0x800959B4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800959B8: nop

    // 0x800959BC: bltz        $t3, L_800959AC
    if (SIGNED(ctx->r11) < 0) {
        // 0x800959C0: nop
    
            goto L_800959AC;
    }
    // 0x800959C0: nop

L_800959C4:
    // 0x800959C4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800959C8: jal         0x800908A0
    // 0x800959CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800908A0(rdram, ctx);
        goto after_57;
    // 0x800959CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_57:
L_800959D0:
    // 0x800959D0: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x800959D4: nop

    // 0x800959D8: andi        $t2, $t4, 0x40
    ctx->r10 = ctx->r12 & 0X40;
    // 0x800959DC: beq         $t2, $zero, L_80095A98
    if (ctx->r10 == 0) {
        // 0x800959E0: nop
    
            goto L_80095A98;
    }
    // 0x800959E0: nop

    // 0x800959E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800959E8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800959EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800959F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800959F4: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800959F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800959FC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095A00: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095A04: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80095A08: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095A0C: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80095A10: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095A14: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095A18: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095A1C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80095A20: beq         $t6, $zero, L_80095A74
    if (ctx->r14 == 0) {
        // 0x80095A24: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80095A74;
    }
    // 0x80095A24: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80095A28: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095A2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095A30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095A34: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80095A38: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80095A3C: nop

    // 0x80095A40: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80095A44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80095A48: nop

    // 0x80095A4C: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80095A50: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80095A54: bne         $t6, $zero, L_80095A6C
    if (ctx->r14 != 0) {
        // 0x80095A58: nop
    
            goto L_80095A6C;
    }
    // 0x80095A58: nop

    // 0x80095A5C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80095A60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095A64: b           L_80095A84
    // 0x80095A68: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80095A84;
    // 0x80095A68: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80095A6C:
    // 0x80095A6C: b           L_80095A84
    // 0x80095A70: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80095A84;
    // 0x80095A70: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80095A74:
    // 0x80095A74: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80095A78: nop

    // 0x80095A7C: bltz        $t6, L_80095A6C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80095A80: nop
    
            goto L_80095A6C;
    }
    // 0x80095A80: nop

L_80095A84:
    // 0x80095A84: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80095A88: jal         0x800908A0
    // 0x80095A8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_58;
    // 0x80095A8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_58:
    // 0x80095A90: b           L_80095B44
    // 0x80095A94: nop

        goto L_80095B44;
    // 0x80095A94: nop

L_80095A98:
    // 0x80095A98: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095A9C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80095AA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095AA4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80095AA8: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095AAC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095AB0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80095AB4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095AB8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095ABC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095AC0: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80095AC4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095AC8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095ACC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095AD0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80095AD4: beq         $t7, $zero, L_80095B28
    if (ctx->r15 == 0) {
        // 0x80095AD8: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80095B28;
    }
    // 0x80095AD8: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80095ADC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095AE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095AE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095AE8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095AEC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80095AF0: nop

    // 0x80095AF4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80095AF8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095AFC: nop

    // 0x80095B00: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80095B04: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80095B08: bne         $t7, $zero, L_80095B20
    if (ctx->r15 != 0) {
        // 0x80095B0C: nop
    
            goto L_80095B20;
    }
    // 0x80095B0C: nop

    // 0x80095B10: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80095B14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095B18: b           L_80095B38
    // 0x80095B1C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80095B38;
    // 0x80095B1C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80095B20:
    // 0x80095B20: b           L_80095B38
    // 0x80095B24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80095B38;
    // 0x80095B24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80095B28:
    // 0x80095B28: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80095B2C: nop

    // 0x80095B30: bltz        $t7, L_80095B20
    if (SIGNED(ctx->r15) < 0) {
        // 0x80095B34: nop
    
            goto L_80095B20;
    }
    // 0x80095B34: nop

L_80095B38:
    // 0x80095B38: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095B3C: jal         0x800908A0
    // 0x80095B40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800908A0(rdram, ctx);
        goto after_59;
    // 0x80095B40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_59:
L_80095B44:
    // 0x80095B44: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x80095B48: nop

    // 0x80095B4C: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x80095B50: beq         $t1, $zero, L_80095C0C
    if (ctx->r9 == 0) {
        // 0x80095B54: nop
    
            goto L_80095C0C;
    }
    // 0x80095B54: nop

    // 0x80095B58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095B5C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80095B60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095B64: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80095B68: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095B6C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095B70: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095B74: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095B78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80095B7C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095B80: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80095B84: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095B88: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095B8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095B90: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80095B94: beq         $t3, $zero, L_80095BE8
    if (ctx->r11 == 0) {
        // 0x80095B98: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_80095BE8;
    }
    // 0x80095B98: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x80095B9C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095BA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095BA4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095BA8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095BAC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80095BB0: nop

    // 0x80095BB4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095BB8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80095BBC: nop

    // 0x80095BC0: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80095BC4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80095BC8: bne         $t3, $zero, L_80095BE0
    if (ctx->r11 != 0) {
        // 0x80095BCC: nop
    
            goto L_80095BE0;
    }
    // 0x80095BCC: nop

    // 0x80095BD0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80095BD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095BD8: b           L_80095BF8
    // 0x80095BDC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80095BF8;
    // 0x80095BDC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80095BE0:
    // 0x80095BE0: b           L_80095BF8
    // 0x80095BE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80095BF8;
    // 0x80095BE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80095BE8:
    // 0x80095BE8: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80095BEC: nop

    // 0x80095BF0: bltz        $t3, L_80095BE0
    if (SIGNED(ctx->r11) < 0) {
        // 0x80095BF4: nop
    
            goto L_80095BE0;
    }
    // 0x80095BF4: nop

L_80095BF8:
    // 0x80095BF8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80095BFC: jal         0x800908A0
    // 0x80095C00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800908A0(rdram, ctx);
        goto after_60;
    // 0x80095C00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_60:
    // 0x80095C04: b           L_80095CB8
    // 0x80095C08: nop

        goto L_80095CB8;
    // 0x80095C08: nop

L_80095C0C:
    // 0x80095C0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095C10: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80095C14: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80095C18: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095C1C: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095C20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095C24: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80095C28: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095C2C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80095C30: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095C34: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80095C38: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095C3C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095C40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095C44: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80095C48: beq         $t2, $zero, L_80095C9C
    if (ctx->r10 == 0) {
        // 0x80095C4C: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_80095C9C;
    }
    // 0x80095C4C: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x80095C50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095C54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095C58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80095C5C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80095C60: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80095C64: nop

    // 0x80095C68: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80095C6C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80095C70: nop

    // 0x80095C74: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80095C78: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80095C7C: bne         $t2, $zero, L_80095C94
    if (ctx->r10 != 0) {
        // 0x80095C80: nop
    
            goto L_80095C94;
    }
    // 0x80095C80: nop

    // 0x80095C84: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80095C88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095C8C: b           L_80095CAC
    // 0x80095C90: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80095CAC;
    // 0x80095C90: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80095C94:
    // 0x80095C94: b           L_80095CAC
    // 0x80095C98: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80095CAC;
    // 0x80095C98: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80095C9C:
    // 0x80095C9C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80095CA0: nop

    // 0x80095CA4: bltz        $t2, L_80095C94
    if (SIGNED(ctx->r10) < 0) {
        // 0x80095CA8: nop
    
            goto L_80095C94;
    }
    // 0x80095CA8: nop

L_80095CAC:
    // 0x80095CAC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80095CB0: jal         0x800908A0
    // 0x80095CB4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_61;
    // 0x80095CB4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_61:
L_80095CB8:
    // 0x80095CB8: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x80095CBC: nop

    // 0x80095CC0: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80095CC4: beq         $t6, $zero, L_80095D80
    if (ctx->r14 == 0) {
        // 0x80095CC8: nop
    
            goto L_80095D80;
    }
    // 0x80095CC8: nop

    // 0x80095CCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095CD0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80095CD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095CD8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80095CDC: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095CE0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095CE4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80095CE8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095CEC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095CF0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095CF4: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80095CF8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095CFC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80095D00: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095D04: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80095D08: beq         $t7, $zero, L_80095D5C
    if (ctx->r15 == 0) {
        // 0x80095D0C: addiu       $a3, $a3, 0x16
        ctx->r7 = ADD32(ctx->r7, 0X16);
            goto L_80095D5C;
    }
    // 0x80095D0C: addiu       $a3, $a3, 0x16
    ctx->r7 = ADD32(ctx->r7, 0X16);
    // 0x80095D10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095D14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095D18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095D1C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095D20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80095D24: nop

    // 0x80095D28: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80095D2C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80095D30: nop

    // 0x80095D34: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80095D38: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80095D3C: bne         $t7, $zero, L_80095D54
    if (ctx->r15 != 0) {
        // 0x80095D40: nop
    
            goto L_80095D54;
    }
    // 0x80095D40: nop

    // 0x80095D44: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80095D48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095D4C: b           L_80095D6C
    // 0x80095D50: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80095D6C;
    // 0x80095D50: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80095D54:
    // 0x80095D54: b           L_80095D6C
    // 0x80095D58: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80095D6C;
    // 0x80095D58: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80095D5C:
    // 0x80095D5C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80095D60: nop

    // 0x80095D64: bltz        $t7, L_80095D54
    if (SIGNED(ctx->r15) < 0) {
        // 0x80095D68: nop
    
            goto L_80095D54;
    }
    // 0x80095D68: nop

L_80095D6C:
    // 0x80095D6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80095D70: jal         0x800908A0
    // 0x80095D74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800908A0(rdram, ctx);
        goto after_62;
    // 0x80095D74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_62:
    // 0x80095D78: b           L_80095E2C
    // 0x80095D7C: nop

        goto L_80095E2C;
    // 0x80095D7C: nop

L_80095D80:
    // 0x80095D80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095D84: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80095D88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095D8C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095D90: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80095D94: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80095D98: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80095D9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095DA0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095DA4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80095DA8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095DAC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80095DB0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80095DB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80095DB8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095DBC: beq         $t1, $zero, L_80095E10
    if (ctx->r9 == 0) {
        // 0x80095DC0: addiu       $a3, $a3, 0x16
        ctx->r7 = ADD32(ctx->r7, 0X16);
            goto L_80095E10;
    }
    // 0x80095DC0: addiu       $a3, $a3, 0x16
    ctx->r7 = ADD32(ctx->r7, 0X16);
    // 0x80095DC4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80095DC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095DCC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095DD0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80095DD4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80095DD8: nop

    // 0x80095DDC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80095DE0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80095DE4: nop

    // 0x80095DE8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80095DEC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80095DF0: bne         $t1, $zero, L_80095E08
    if (ctx->r9 != 0) {
        // 0x80095DF4: nop
    
            goto L_80095E08;
    }
    // 0x80095DF4: nop

    // 0x80095DF8: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80095DFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095E00: b           L_80095E20
    // 0x80095E04: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80095E20;
    // 0x80095E04: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80095E08:
    // 0x80095E08: b           L_80095E20
    // 0x80095E0C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80095E20;
    // 0x80095E0C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80095E10:
    // 0x80095E10: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80095E14: nop

    // 0x80095E18: bltz        $t1, L_80095E08
    if (SIGNED(ctx->r9) < 0) {
        // 0x80095E1C: nop
    
            goto L_80095E08;
    }
    // 0x80095E1C: nop

L_80095E20:
    // 0x80095E20: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80095E24: jal         0x800908A0
    // 0x80095E28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_63;
    // 0x80095E28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_63:
L_80095E2C:
    // 0x80095E2C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80095E30: nop

    // 0x80095E34: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80095E38: slti        $at, $t3, 0xC
    ctx->r1 = SIGNED(ctx->r11) < 0XC ? 1 : 0;
    // 0x80095E3C: bne         $at, $zero, L_80094BBC
    if (ctx->r1 != 0) {
        // 0x80095E40: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_80094BBC;
    }
    // 0x80095E40: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80095E44:
    // 0x80095E44: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80095E48: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80095E4C: lw          $t4, 0x6B98($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6B98);
    // 0x80095E50: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80095E54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80095E58: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80095E5C: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
L_80095E60:
    // 0x80095E60: b           L_80095E68
    // 0x80095E64: nop

        goto L_80095E68;
    // 0x80095E64: nop

L_80095E68:
    // 0x80095E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80095E6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80095E70: jr          $ra
    // 0x80095E74: nop

    return;
    // 0x80095E74: nop

;}
RECOMP_FUNC void func_800724C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800724C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800724CC: nop

    // 0x800724D0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800724D4: nop

    // 0x800724D8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800724DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800724E0: jr          $ra
    // 0x800724E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800724E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800724E8: jr          $ra
    // 0x800724EC: nop

    return;
    // 0x800724EC: nop

    // 0x800724F0: jr          $ra
    // 0x800724F4: nop

    return;
    // 0x800724F4: nop

;}
RECOMP_FUNC void func_8000BC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BC80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BC84: jal         0x800045AC
    // 0x8000BC88: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_0;
    // 0x8000BC88: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8000BC8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000BC90: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BC94: nop

    // 0x8000BC98: bne         $t6, $zero, L_8000BCA8
    if (ctx->r14 != 0) {
        // 0x8000BC9C: nop
    
            goto L_8000BCA8;
    }
    // 0x8000BC9C: nop

    // 0x8000BCA0: b           L_8000BDCC
    // 0x8000BCA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000BDCC;
    // 0x8000BCA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000BCA8:
    // 0x8000BCA8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BCAC: nop

    // 0x8000BCB0: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8000BCB4: nop

    // 0x8000BCB8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000BCBC: beq         $t9, $zero, L_8000BCCC
    if (ctx->r25 == 0) {
        // 0x8000BCC0: nop
    
            goto L_8000BCCC;
    }
    // 0x8000BCC0: nop

    // 0x8000BCC4: jal         0x800B81B4
    // 0x8000BCC8: nop

    func_800B81B4(rdram, ctx);
        goto after_1;
    // 0x8000BCC8: nop

    after_1:
L_8000BCCC:
    // 0x8000BCCC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BCD0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000BCD4: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000BCD8: nop

    // 0x8000BCDC: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8000BCE0: sw          $t2, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r10;
    // 0x8000BCE4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BCE8: nop

    // 0x8000BCEC: lw          $t4, 0x20C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20C);
    // 0x8000BCF0: nop

    // 0x8000BCF4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8000BCF8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8000BCFC: nop

    // 0x8000BD00: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8000BD04: nop

    // 0x8000BD08: bne         $t6, $zero, L_8000BD3C
    if (ctx->r14 != 0) {
        // 0x8000BD0C: nop
    
            goto L_8000BD3C;
    }
    // 0x8000BD0C: nop

    // 0x8000BD10: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8000BD14: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x8000BD18: nop

    // 0x8000BD1C: beq         $t7, $zero, L_8000BD34
    if (ctx->r15 == 0) {
        // 0x8000BD20: nop
    
            goto L_8000BD34;
    }
    // 0x8000BD20: nop

    // 0x8000BD24: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8000BD28: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x8000BD2C: nop

    // 0x8000BD30: sh          $zero, 0x4($t8)
    MEM_H(0X4, ctx->r24) = 0;
L_8000BD34:
    // 0x8000BD34: b           L_8000BD9C
    // 0x8000BD38: nop

        goto L_8000BD9C;
    // 0x8000BD38: nop

L_8000BD3C:
    // 0x8000BD3C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8000BD40: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x8000BD44: nop

    // 0x8000BD48: beq         $t9, $zero, L_8000BD68
    if (ctx->r25 == 0) {
        // 0x8000BD4C: nop
    
            goto L_8000BD68;
    }
    // 0x8000BD4C: nop

    // 0x8000BD50: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000BD54: lw          $a0, 0x3068($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3068);
    // 0x8000BD58: jal         0x8000D390
    // 0x8000BD5C: nop

    TempHeap_Free(rdram, ctx);
        goto after_2;
    // 0x8000BD5C: nop

    after_2:
    // 0x8000BD60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000BD64: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
L_8000BD68:
    // 0x8000BD68: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8000BD6C: nop

    // 0x8000BD70: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8000BD74: nop

    // 0x8000BD78: sw          $zero, 0x1A8($t2)
    MEM_W(0X1A8, ctx->r10) = 0;
    // 0x8000BD7C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000BD80: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8000BD84: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8000BD88: nop

    // 0x8000BD8C: lw          $t4, 0x1A0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A0);
    // 0x8000BD90: nop

    // 0x8000BD94: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8000BD98: sw          $t5, 0x1A0($t3)
    MEM_W(0X1A0, ctx->r11) = ctx->r13;
L_8000BD9C:
    // 0x8000BD9C: jal         0x8005F064
    // 0x8000BDA0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_8005F064(rdram, ctx);
        goto after_3;
    // 0x8000BDA0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_3:
    // 0x8000BDA4: bne         $v0, $zero, L_8000BDB4
    if (ctx->r2 != 0) {
        // 0x8000BDA8: nop
    
            goto L_8000BDB4;
    }
    // 0x8000BDA8: nop

    // 0x8000BDAC: jal         0x80022124
    // 0x8000BDB0: nop

    func_80022124(rdram, ctx);
        goto after_4;
    // 0x8000BDB0: nop

    after_4:
L_8000BDB4:
    // 0x8000BDB4: jal         0x8005F268
    // 0x8000BDB8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_8005F268(rdram, ctx);
        goto after_5;
    // 0x8000BDB8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_5:
    // 0x8000BDBC: b           L_8000BDCC
    // 0x8000BDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000BDCC;
    // 0x8000BDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000BDC4: b           L_8000BDCC
    // 0x8000BDC8: nop

        goto L_8000BDCC;
    // 0x8000BDC8: nop

L_8000BDCC:
    // 0x8000BDCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BDD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BDD4: jr          $ra
    // 0x8000BDD8: nop

    return;
    // 0x8000BDD8: nop

;}
RECOMP_FUNC void func_80071E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071E20: jal         0x80061348
    // 0x80071E24: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071E24: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071E28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071E2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071E30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071E34: beq         $v0, $zero, L_80071E6C
    if (ctx->r2 == 0) {
        // 0x80071E38: nop
    
            goto L_80071E6C;
    }
    // 0x80071E38: nop

    // 0x80071E3C: jal         0x80061348
    // 0x80071E40: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071E40: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071E44: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071E48: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071E4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071E50: beq         $v0, $zero, L_80071E6C
    if (ctx->r2 == 0) {
        // 0x80071E54: nop
    
            goto L_80071E6C;
    }
    // 0x80071E54: nop

    // 0x80071E58: jal         0x80061348
    // 0x80071E5C: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071E5C: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071E60: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071E64: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071E68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071E6C:
    // 0x80071E6C: b           L_80071E7C
    // 0x80071E70: nop

        goto L_80071E7C;
    // 0x80071E70: nop

    // 0x80071E74: b           L_80071E7C
    // 0x80071E78: nop

        goto L_80071E7C;
    // 0x80071E78: nop

L_80071E7C:
    // 0x80071E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071E80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071E84: jr          $ra
    // 0x80071E88: nop

    return;
    // 0x80071E88: nop

;}
RECOMP_FUNC void func_8006739C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006739C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800673A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800673A4: jal         0x80061488
    // 0x800673A8: addiu       $a0, $zero, 0x2E3
    ctx->r4 = ADD32(0, 0X2E3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800673A8: addiu       $a0, $zero, 0x2E3
    ctx->r4 = ADD32(0, 0X2E3);
    after_0:
    // 0x800673AC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800673B0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800673B4: b           L_800673C4
    // 0x800673B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800673C4;
    // 0x800673B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800673BC: b           L_800673C4
    // 0x800673C0: nop

        goto L_800673C4;
    // 0x800673C0: nop

L_800673C4:
    // 0x800673C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800673C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800673CC: jr          $ra
    // 0x800673D0: nop

    return;
    // 0x800673D0: nop

;}
RECOMP_FUNC void func_800B6CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6CC8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B6CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B6CD0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800B6CD4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B6CD8: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x800B6CDC: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x800B6CE0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800B6CE4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800B6CE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B6CEC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B6CF0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B6CF4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B6CF8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B6CFC: nop

    // 0x800B6D00: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800B6D04: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B6D08: nop

    // 0x800B6D0C: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B6D10: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B6D14: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800B6D18: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B6D1C: nop

    // 0x800B6D20: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800B6D24: nop

    // 0x800B6D28: andi        $t0, $t9, 0xF800
    ctx->r8 = ctx->r25 & 0XF800;
    // 0x800B6D2C: sra         $t1, $t0, 8
    ctx->r9 = S32(SIGNED(ctx->r8) >> 8);
    // 0x800B6D30: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800B6D34: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800B6D38: nop

    // 0x800B6D3C: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800B6D40: nop

    // 0x800B6D44: andi        $t4, $t3, 0x7C0
    ctx->r12 = ctx->r11 & 0X7C0;
    // 0x800B6D48: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800B6D4C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800B6D50: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B6D54: nop

    // 0x800B6D58: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x800B6D5C: nop

    // 0x800B6D60: andi        $t8, $t7, 0x3E
    ctx->r24 = ctx->r15 & 0X3E;
    // 0x800B6D64: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B6D68: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800B6D6C: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x800B6D70: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B6D74: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800B6D78: nop

    // 0x800B6D7C: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x800B6D80: nop

    // 0x800B6D84: bne         $t2, $zero, L_800B6D98
    if (ctx->r10 != 0) {
        // 0x800B6D88: nop
    
            goto L_800B6D98;
    }
    // 0x800B6D88: nop

    // 0x800B6D8C: addiu       $t3, $zero, 0xA8
    ctx->r11 = ADD32(0, 0XA8);
    // 0x800B6D90: b           L_800B6DA0
    // 0x800B6D94: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
        goto L_800B6DA0;
    // 0x800B6D94: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_800B6D98:
    // 0x800B6D98: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x800B6D9C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_800B6DA0:
    // 0x800B6DA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B6DA4: nop

    // 0x800B6DA8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800B6DAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B6DB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B6DB4: nop

    // 0x800B6DB8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800B6DBC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B6DC0: nop

    // 0x800B6DC4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x800B6DC8: addiu       $t5, $zero, 0x3E8
    ctx->r13 = ADD32(0, 0X3E8);
    // 0x800B6DCC: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800B6DD0: jal         0x80016620
    // 0x800B6DD4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_0;
    // 0x800B6DD4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800B6DD8: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800B6DDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B6DE0: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
    // 0x800B6DE4: b           L_800B6DF4
    // 0x800B6DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B6DF4;
    // 0x800B6DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B6DEC: b           L_800B6DF4
    // 0x800B6DF0: nop

        goto L_800B6DF4;
    // 0x800B6DF0: nop

L_800B6DF4:
    // 0x800B6DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6DF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800B6DFC: jr          $ra
    // 0x800B6E00: nop

    return;
    // 0x800B6E00: nop

;}
RECOMP_FUNC void func_800667E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800667E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800667E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800667EC: jal         0x80061348
    // 0x800667F0: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800667F0: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_0:
    // 0x800667F4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800667F8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800667FC: b           L_8006680C
    // 0x80066800: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006680C;
    // 0x80066800: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066804: b           L_8006680C
    // 0x80066808: nop

        goto L_8006680C;
    // 0x80066808: nop

L_8006680C:
    // 0x8006680C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066814: jr          $ra
    // 0x80066818: nop

    return;
    // 0x80066818: nop

;}
RECOMP_FUNC void func_80076410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076410: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076414: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076418: nop

    // 0x8007641C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80076420: nop

    // 0x80076424: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076428: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007642C: jr          $ra
    // 0x80076430: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076430: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076434: jr          $ra
    // 0x80076438: nop

    return;
    // 0x80076438: nop

    // 0x8007643C: jr          $ra
    // 0x80076440: nop

    return;
    // 0x80076440: nop

;}
RECOMP_FUNC void func_80065580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065580: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065584: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065588: nop

    // 0x8006558C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80065590: nop

    // 0x80065594: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80065598: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006559C: beq         $v0, $zero, L_800655B8
    if (ctx->r2 == 0) {
        // 0x800655A0: nop
    
            goto L_800655B8;
    }
    // 0x800655A0: nop

    // 0x800655A4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800655A8: nop

    // 0x800655AC: slti        $t8, $v0, 0x12D
    ctx->r24 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x800655B0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800655B4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800655B8:
    // 0x800655B8: jr          $ra
    // 0x800655BC: nop

    return;
    // 0x800655BC: nop

    // 0x800655C0: jr          $ra
    // 0x800655C4: nop

    return;
    // 0x800655C4: nop

    // 0x800655C8: jr          $ra
    // 0x800655CC: nop

    return;
    // 0x800655CC: nop

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
RECOMP_FUNC void func_8006CD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CD74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CD78: nop

    // 0x8006CD7C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x8006CD80: nop

    // 0x8006CD84: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CD88: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CD8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CD90: bne         $v0, $zero, L_8006CDAC
    if (ctx->r2 != 0) {
        // 0x8006CD94: nop
    
            goto L_8006CDAC;
    }
    // 0x8006CD94: nop

    // 0x8006CD98: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006CD9C: nop

    // 0x8006CDA0: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CDA4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006CDA8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CDAC:
    // 0x8006CDAC: jr          $ra
    // 0x8006CDB0: nop

    return;
    // 0x8006CDB0: nop

    // 0x8006CDB4: jr          $ra
    // 0x8006CDB8: nop

    return;
    // 0x8006CDB8: nop

    // 0x8006CDBC: jr          $ra
    // 0x8006CDC0: nop

    return;
    // 0x8006CDC0: nop

;}
RECOMP_FUNC void func_800650F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800650F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800650F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800650FC: jal         0x8005F064
    // 0x80065100: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065100: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x80065104: b           L_80065114
    // 0x80065108: nop

        goto L_80065114;
    // 0x80065108: nop

    // 0x8006510C: b           L_80065114
    // 0x80065110: nop

        goto L_80065114;
    // 0x80065110: nop

L_80065114:
    // 0x80065114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006511C: jr          $ra
    // 0x80065120: nop

    return;
    // 0x80065120: nop

;}
RECOMP_FUNC void func_80077528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077528: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007752C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077530: nop

    // 0x80077534: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80077538: nop

    // 0x8007753C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077540: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077544: jr          $ra
    // 0x80077548: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077548: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007754C: jr          $ra
    // 0x80077550: nop

    return;
    // 0x80077550: nop

    // 0x80077554: jr          $ra
    // 0x80077558: nop

    return;
    // 0x80077558: nop

;}
RECOMP_FUNC void func_8004629C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004629C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800462A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800462A4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800462A8: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800462AC: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800462B0: jal         0x800AF060
    // 0x800462B4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x800462B4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_0:
    // 0x800462B8: jal         0x800A41B4
    // 0x800462BC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    func_800A41B4(rdram, ctx);
        goto after_1;
    // 0x800462BC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_1:
    // 0x800462C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800462C4: addiu       $a1, $a1, -0x3FD0
    ctx->r5 = ADD32(ctx->r5, -0X3FD0);
    // 0x800462C8: jal         0x800A5624
    // 0x800462CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_2;
    // 0x800462CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800462D0: addiu       $a0, $zero, 0x3E0
    ctx->r4 = ADD32(0, 0X3E0);
    // 0x800462D4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x800462D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800462DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800462E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800462E4: jal         0x800A57C4
    // 0x800462E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800A57C4(rdram, ctx);
        goto after_3;
    // 0x800462E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x800462EC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800462F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800462F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800462F8: swc1        $f4, 0x450($at)
    MEM_W(0X450, ctx->r1) = ctx->f4.u32l;
    // 0x800462FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80046300: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80046304: sw          $t6, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r14;
    // 0x80046308: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004630C: lh          $t7, 0x725C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X725C);
    // 0x80046310: nop

    // 0x80046314: andi        $t8, $t7, 0x7FFF
    ctx->r24 = ctx->r15 & 0X7FFF;
    // 0x80046318: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8004631C: sh          $t9, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r25;
    // 0x80046320: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80046324: lh          $t0, 0x7268($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7268);
    // 0x80046328: nop

    // 0x8004632C: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x80046330: sh          $t1, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r9;
    // 0x80046334: jal         0x800BC6EC
    // 0x80046338: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x80046338: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x8004633C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046340: sw          $v0, 0x71FC($at)
    MEM_W(0X71FC, ctx->r1) = ctx->r2;
    // 0x80046344: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80046348: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8004634C: jal         0x800BC6EC
    // 0x80046350: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x80046350: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_5:
    // 0x80046354: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80046358: lw          $t3, 0x71FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X71FC);
    // 0x8004635C: nop

    // 0x80046360: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80046364: lhu         $t4, 0x46($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X46);
    // 0x80046368: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8004636C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80046370: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x80046374: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80046378: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8004637C: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80046380: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80046384: lw          $a2, -0x3F50($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3F50);
    // 0x80046388: jal         0x800BD1FC
    // 0x8004638C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x8004638C: nop

    after_6:
    // 0x80046390: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80046394: lw          $t6, 0x71FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71FC);
    // 0x80046398: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004639C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800463A0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800463A4: jal         0x800BD218
    // 0x800463A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_7;
    // 0x800463A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800463AC: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x800463B0: lw          $a3, 0x71FC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X71FC);
    // 0x800463B4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800463B8: addiu       $a2, $a2, -0x3F3C
    ctx->r6 = ADD32(ctx->r6, -0X3F3C);
    // 0x800463BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800463C0: jal         0x80043F14
    // 0x800463C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80043F14(rdram, ctx);
        goto after_8;
    // 0x800463C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x800463C8: lui         $a0, 0x80A4
    ctx->r4 = S32(0X80A4 << 16);
    // 0x800463CC: jal         0x800AF92C
    // 0x800463D0: addiu       $a0, $a0, -0x4188
    ctx->r4 = ADD32(ctx->r4, -0X4188);
    func_800AF92C(rdram, ctx);
        goto after_9;
    // 0x800463D0: addiu       $a0, $a0, -0x4188
    ctx->r4 = ADD32(ctx->r4, -0X4188);
    after_9:
    // 0x800463D4: lui         $a0, 0x80A3
    ctx->r4 = S32(0X80A3 << 16);
    // 0x800463D8: jal         0x800AF72C
    // 0x800463DC: addiu       $a0, $a0, 0x560C
    ctx->r4 = ADD32(ctx->r4, 0X560C);
    func_800AF72C(rdram, ctx);
        goto after_10;
    // 0x800463DC: addiu       $a0, $a0, 0x560C
    ctx->r4 = ADD32(ctx->r4, 0X560C);
    after_10:
    // 0x800463E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800463E4: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800463E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800463EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800463F0: swc1        $f6, -0x3A7C($at)
    MEM_W(-0X3A7C, ctx->r1) = ctx->f6.u32l;
    // 0x800463F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800463F8: swc1        $f6, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f6.u32l;
    // 0x800463FC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80046400: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046404: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80046408: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8004640C: sh          $t7, -0x7398($at)
    MEM_H(-0X7398, ctx->r1) = ctx->r15;
    // 0x80046410: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80046414: nop

    // 0x80046418: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8004641C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80046420: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80046424: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80046428: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8004642C: jal         0x800BC6EC
    // 0x80046430: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x80046430: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_11:
    // 0x80046434: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80046438: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8004643C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046440: sw          $t0, -0x73A0($at)
    MEM_W(-0X73A0, ctx->r1) = ctx->r8;
    // 0x80046444: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80046448: nop

    // 0x8004644C: sll         $t1, $a0, 6
    ctx->r9 = S32(ctx->r4 << 6);
    // 0x80046450: jal         0x800BC6EC
    // 0x80046454: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_12;
    // 0x80046454: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_12:
    // 0x80046458: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004645C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80046460: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046464: sw          $t2, -0x739C($at)
    MEM_W(-0X739C, ctx->r1) = ctx->r10;
    // 0x80046468: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_8004646C:
    // 0x8004646C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80046470: jal         0x80099E2C
    // 0x80046474: nop

    func_80099E2C(rdram, ctx);
        goto after_13;
    // 0x80046474: nop

    after_13:
    // 0x80046478: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8004647C: lui         $t3, 0x4
    ctx->r11 = S32(0X4 << 16);
    // 0x80046480: ori         $t3, $t3, 0x4
    ctx->r11 = ctx->r11 | 0X4;
    // 0x80046484: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
    // 0x80046488: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004648C: lwc1        $f8, -0x1154($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1154);
    // 0x80046490: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80046494: nop

    // 0x80046498: swc1        $f8, 0xFC($t5)
    MEM_W(0XFC, ctx->r13) = ctx->f8.u32l;
    // 0x8004649C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800464A0: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x800464A4: sw          $t6, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r14;
    // 0x800464A8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800464AC: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800464B0: sh          $t8, 0xC4($t9)
    MEM_H(0XC4, ctx->r25) = ctx->r24;
    // 0x800464B4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800464B8: nop

    // 0x800464BC: addiu       $t1, $t0, 0x160
    ctx->r9 = ADD32(ctx->r8, 0X160);
    // 0x800464C0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800464C4: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800464C8: nop

    // 0x800464CC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800464D0: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x800464D4: bne         $at, $zero, L_8004646C
    if (ctx->r1 != 0) {
        // 0x800464D8: sw          $t3, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r11;
            goto L_8004646C;
    }
    // 0x800464D8: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x800464DC: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800464E0: nop

    // 0x800464E4: addiu       $t5, $t4, -0x420
    ctx->r13 = ADD32(ctx->r12, -0X420);
    // 0x800464E8: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x800464EC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800464F0: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800464F4: jal         0x800B1B3C
    // 0x800464F8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800B1B3C(rdram, ctx);
        goto after_14;
    // 0x800464F8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_14:
    // 0x800464FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046500: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80046504: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80046508: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8004650C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80046510: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80046514: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80046518: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8004651C: jal         0x800B202C
    // 0x80046520: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_15;
    // 0x80046520: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x80046524: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046528: sh          $v0, -0x7396($at)
    MEM_H(-0X7396, ctx->r1) = ctx->r2;
    // 0x8004652C: jal         0x800BC6EC
    // 0x80046530: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_16;
    // 0x80046530: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_16:
    // 0x80046534: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80046538: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8004653C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046540: sw          $t6, -0x73B8($at)
    MEM_W(-0X73B8, ctx->r1) = ctx->r14;
    // 0x80046544: jal         0x800BC6EC
    // 0x80046548: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_17;
    // 0x80046548: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_17:
    // 0x8004654C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80046550: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80046554: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046558: sw          $t7, -0x73B4($at)
    MEM_W(-0X73B4, ctx->r1) = ctx->r15;
    // 0x8004655C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80046560: jal         0x80099E2C
    // 0x80046564: nop

    func_80099E2C(rdram, ctx);
        goto after_18;
    // 0x80046564: nop

    after_18:
    // 0x80046568: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004656C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80046570: nop

    // 0x80046574: swc1        $f18, 0xD4($t8)
    MEM_W(0XD4, ctx->r24) = ctx->f18.u32l;
    // 0x80046578: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8004657C: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x80046580: ori         $t9, $t9, 0x4
    ctx->r25 = ctx->r25 | 0X4;
    // 0x80046584: sw          $t9, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r25;
    // 0x80046588: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004658C: lwc1        $f4, -0x1150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1150);
    // 0x80046590: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80046594: nop

    // 0x80046598: swc1        $f4, 0xFC($t1)
    MEM_W(0XFC, ctx->r9) = ctx->f4.u32l;
    // 0x8004659C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800465A0: nop

    // 0x800465A4: sw          $zero, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = 0;
    // 0x800465A8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800465AC: nop

    // 0x800465B0: sw          $zero, 0x140($t3)
    MEM_W(0X140, ctx->r11) = 0;
    // 0x800465B4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800465B8: nop

    // 0x800465BC: lw          $t5, 0x140($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X140);
    // 0x800465C0: nop

    // 0x800465C4: sw          $t5, 0x13C($t4)
    MEM_W(0X13C, ctx->r12) = ctx->r13;
    // 0x800465C8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800465CC: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800465D0: sh          $t6, 0xC4($t7)
    MEM_H(0XC4, ctx->r15) = ctx->r14;
    // 0x800465D4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800465D8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800465DC: jal         0x800B1B04
    // 0x800465E0: nop

    func_800B1B04(rdram, ctx);
        goto after_19;
    // 0x800465E0: nop

    after_19:
    // 0x800465E4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800465E8: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x800465EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800465F0: lh          $a3, 0x42($t8)
    ctx->r7 = MEM_H(ctx->r24, 0X42);
    // 0x800465F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800465F8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800465FC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80046600: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80046604: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x80046608: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8004660C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80046610: jal         0x800B1F0C
    // 0x80046614: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_20;
    // 0x80046614: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x80046618: addiu       $t9, $zero, 0x27
    ctx->r25 = ADD32(0, 0X27);
    // 0x8004661C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046620: sh          $t9, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r25;
    // 0x80046624: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046628: sh          $zero, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = 0;
    // 0x8004662C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046630: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046634: swc1        $f10, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = ctx->f10.u32l;
    // 0x80046638: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004663C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046640: swc1        $f16, 0x733C($at)
    MEM_W(0X733C, ctx->r1) = ctx->f16.u32l;
    // 0x80046644: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80046648: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004664C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046650: swc1        $f18, -0x73E0($at)
    MEM_W(-0X73E0, ctx->r1) = ctx->f18.u32l;
    // 0x80046654: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80046658: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004665C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80046660: swc1        $f4, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f4.u32l;
    // 0x80046664: lhu         $s0, 0x44($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X44);
    // 0x80046668: nop

    // 0x8004666C: beq         $s0, $zero, L_80046688
    if (ctx->r16 == 0) {
        // 0x80046670: nop
    
            goto L_80046688;
    }
    // 0x80046670: nop

    // 0x80046674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80046678: beq         $s0, $at, L_800466C0
    if (ctx->r16 == ctx->r1) {
        // 0x8004667C: nop
    
            goto L_800466C0;
    }
    // 0x8004667C: nop

    // 0x80046680: b           L_800466F8
    // 0x80046684: nop

        goto L_800466F8;
    // 0x80046684: nop

L_80046688:
    // 0x80046688: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8004668C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046690: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046694: swc1        $f6, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f6.u32l;
    // 0x80046698: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8004669C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800466A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800466A4: swc1        $f8, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f8.u32l;
    // 0x800466A8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800466AC: lwc1        $f10, -0x114C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X114C);
    // 0x800466B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800466B4: swc1        $f10, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f10.u32l;
    // 0x800466B8: b           L_800467C0
    // 0x800466BC: nop

        goto L_800467C0;
    // 0x800466BC: nop

L_800466C0:
    // 0x800466C0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800466C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800466C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800466CC: swc1        $f16, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f16.u32l;
    // 0x800466D0: lui         $at, 0x44B9
    ctx->r1 = S32(0X44B9 << 16);
    // 0x800466D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800466D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800466DC: swc1        $f18, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f18.u32l;
    // 0x800466E0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800466E4: lwc1        $f4, -0x1148($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1148);
    // 0x800466E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800466EC: swc1        $f4, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f4.u32l;
    // 0x800466F0: b           L_800467C0
    // 0x800466F4: nop

        goto L_800467C0;
    // 0x800466F4: nop

L_800466F8:
    // 0x800466F8: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x800466FC: lhu         $t3, 0x44($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X44);
    // 0x80046700: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80046704: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80046708: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8004670C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80046710: lw          $t2, -0x3E74($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3E74);
    // 0x80046714: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80046718: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8004671C: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80046720: addiu       $t6, $t4, -0xC
    ctx->r14 = ADD32(ctx->r12, -0XC);
    // 0x80046724: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80046728: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8004672C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046730: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80046734: nop

    // 0x80046738: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8004673C: nop

    // 0x80046740: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80046744: swc1        $f8, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f8.u32l;
    // 0x80046748: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004674C: swc1        $f8, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f8.u32l;
    // 0x80046750: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80046754: nop

    // 0x80046758: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8004675C: nop

    // 0x80046760: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80046764: bgez        $t0, L_8004677C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80046768: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8004677C;
    }
    // 0x80046768: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004676C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80046770: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80046774: nop

    // 0x80046778: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8004677C:
    // 0x8004677C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046780: swc1        $f16, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f16.u32l;
    // 0x80046784: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80046788: nop

    // 0x8004678C: lhu         $t3, 0x2($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X2);
    // 0x80046790: nop

    // 0x80046794: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80046798: bgez        $t3, L_800467B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8004679C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800467B0;
    }
    // 0x8004679C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800467A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800467A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800467A8: nop

    // 0x800467AC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800467B0:
    // 0x800467B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800467B4: swc1        $f6, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f6.u32l;
    // 0x800467B8: b           L_800467C0
    // 0x800467BC: nop

        goto L_800467C0;
    // 0x800467BC: nop

L_800467C0:
    // 0x800467C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800467C4: lwc1        $f10, -0x1144($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1144);
    // 0x800467C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800467CC: swc1        $f10, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f10.u32l;
    // 0x800467D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800467D4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800467D8: addiu       $t2, $t2, 0x7158
    ctx->r10 = ADD32(ctx->r10, 0X7158);
    // 0x800467DC: swc1        $f18, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f18.u32l;
    // 0x800467E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800467E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800467E8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800467EC: addiu       $t5, $t5, 0x7158
    ctx->r13 = ADD32(ctx->r13, 0X7158);
    // 0x800467F0: swc1        $f16, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f16.u32l;
    // 0x800467F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800467F8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800467FC: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x80046800: swc1        $f4, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f4.u32l;
    // 0x80046804: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046808: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004680C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80046810: addiu       $t6, $t6, 0x7158
    ctx->r14 = ADD32(ctx->r14, 0X7158);
    // 0x80046814: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80046818: addiu       $t7, $t7, 0x7158
    ctx->r15 = ADD32(ctx->r15, 0X7158);
    // 0x8004681C: swc1        $f8, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f8.u32l;
    // 0x80046820: lwc1        $f20, 0x20($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80046824: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80046828: addiu       $t8, $t8, 0x7158
    ctx->r24 = ADD32(ctx->r24, 0X7158);
    // 0x8004682C: swc1        $f20, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f20.u32l;
    // 0x80046830: swc1        $f20, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f20.u32l;
    // 0x80046834: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80046838: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004683C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046840: swc1        $f6, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f6.u32l;
    // 0x80046844: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80046848: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x8004684C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046850: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046854: swc1        $f10, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f10.u32l;
    // 0x80046858: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004685C: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x80046860: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80046864: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80046868: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8004686C: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x80046870: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80046874: jal         0x80044248
    // 0x80046878: addiu       $a3, $zero, 0x58
    ctx->r7 = ADD32(0, 0X58);
    func_80044248(rdram, ctx);
        goto after_21;
    // 0x80046878: addiu       $a3, $zero, 0x58
    ctx->r7 = ADD32(0, 0X58);
    after_21:
    // 0x8004687C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80046880: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x80046884: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80046888: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8004688C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80046890: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80046894: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80046898: jal         0x80044248
    // 0x8004689C: addiu       $a3, $zero, 0x43
    ctx->r7 = ADD32(0, 0X43);
    func_80044248(rdram, ctx);
        goto after_22;
    // 0x8004689C: addiu       $a3, $zero, 0x43
    ctx->r7 = ADD32(0, 0X43);
    after_22:
    // 0x800468A0: lhu         $t2, 0x46($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X46);
    // 0x800468A4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800468A8: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x800468AC: lbu         $t5, -0x3DC0($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X3DC0);
    // 0x800468B0: nop

    // 0x800468B4: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800468B8: lhu         $t4, 0x46($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X46);
    // 0x800468BC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800468C0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800468C4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800468C8: lw          $t7, -0x3DB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3DB8);
    // 0x800468CC: nop

    // 0x800468D0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800468D4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800468D8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800468DC: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x800468E0: blez        $t9, L_80046944
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800468E4: sw          $zero, 0x50($sp)
        MEM_W(0X50, ctx->r29) = 0;
            goto L_80046944;
    }
    // 0x800468E4: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_800468E8:
    // 0x800468E8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800468EC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800468F0: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x800468F4: lhu         $a1, 0x2($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X2);
    // 0x800468F8: lhu         $a2, 0x4($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X4);
    // 0x800468FC: lhu         $a3, 0x6($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X6);
    // 0x80046900: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x80046904: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80046908: jal         0x80044248
    // 0x8004690C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_80044248(rdram, ctx);
        goto after_23;
    // 0x8004690C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_23:
    // 0x80046910: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80046914: nop

    // 0x80046918: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x8004691C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80046920: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80046924: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80046928: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8004692C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80046930: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80046934: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80046938: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8004693C: bne         $at, $zero, L_800468E8
    if (ctx->r1 != 0) {
        // 0x80046940: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_800468E8;
    }
    // 0x80046940: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_80046944:
    // 0x80046944: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x80046948: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8004694C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80046950: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80046954: lw          $t3, -0x3D60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3D60);
    // 0x80046958: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004695C: sw          $t3, 0x7214($at)
    MEM_W(0X7214, ctx->r1) = ctx->r11;
    // 0x80046960: b           L_80046968
    // 0x80046964: nop

        goto L_80046968;
    // 0x80046964: nop

L_80046968:
    // 0x80046968: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8004696C: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80046970: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80046974: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80046978: jr          $ra
    // 0x8004697C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8004697C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80071A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071A14: jal         0x80061348
    // 0x80071A18: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071A18: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    after_0:
    // 0x80071A1C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071A20: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071A24: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071A28: beq         $v0, $zero, L_80071A44
    if (ctx->r2 == 0) {
        // 0x80071A2C: nop
    
            goto L_80071A44;
    }
    // 0x80071A2C: nop

    // 0x80071A30: jal         0x80061348
    // 0x80071A34: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071A34: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    after_1:
    // 0x80071A38: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071A3C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071A40: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071A44:
    // 0x80071A44: b           L_80071A54
    // 0x80071A48: nop

        goto L_80071A54;
    // 0x80071A48: nop

    // 0x80071A4C: b           L_80071A54
    // 0x80071A50: nop

        goto L_80071A54;
    // 0x80071A50: nop

L_80071A54:
    // 0x80071A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071A5C: jr          $ra
    // 0x80071A60: nop

    return;
    // 0x80071A60: nop

;}
RECOMP_FUNC void func_8006C9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C9D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C9DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C9E0: jal         0x8005F064
    // 0x8006C9E4: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C9E4: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_0:
    // 0x8006C9E8: b           L_8006C9F8
    // 0x8006C9EC: nop

        goto L_8006C9F8;
    // 0x8006C9EC: nop

    // 0x8006C9F0: b           L_8006C9F8
    // 0x8006C9F4: nop

        goto L_8006C9F8;
    // 0x8006C9F4: nop

L_8006C9F8:
    // 0x8006C9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CA00: jr          $ra
    // 0x8006CA04: nop

    return;
    // 0x8006CA04: nop

;}
RECOMP_FUNC void func_80067B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B2C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067B30: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067B34: nop

    // 0x80067B38: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80067B3C: nop

    // 0x80067B40: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067B44: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067B48: jr          $ra
    // 0x80067B4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067B4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067B50: jr          $ra
    // 0x80067B54: nop

    return;
    // 0x80067B54: nop

    // 0x80067B58: jr          $ra
    // 0x80067B5C: nop

    return;
    // 0x80067B5C: nop

;}
RECOMP_FUNC void func_800051D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800051D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800051D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800051DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800051E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800051E4: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x800051E8: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x800051EC: jal         0x80004410
    // 0x800051F0: nop

    func_80004410(rdram, ctx);
        goto after_0;
    // 0x800051F0: nop

    after_0:
    // 0x800051F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800051F8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800051FC: nop

    // 0x80005200: bne         $t6, $zero, L_80005210
    if (ctx->r14 != 0) {
        // 0x80005204: nop
    
            goto L_80005210;
    }
    // 0x80005204: nop

    // 0x80005208: b           L_80005274
    // 0x8000520C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80005274;
    // 0x8000520C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005210:
    // 0x80005210: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80005214: nop

    // 0x80005218: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8000521C: nop

    // 0x80005220: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80005224: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80005228: nop

    // 0x8000522C: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x80005230: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80005234: jal         0x800C4270
    // 0x80005238: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x80005238: nop

    after_1:
    // 0x8000523C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80005240: jal         0x80004CD4
    // 0x80005244: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80004CD4(rdram, ctx);
        goto after_2;
    // 0x80005244: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80005248: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000524C: bne         $v0, $at, L_80005264
    if (ctx->r2 != ctx->r1) {
        // 0x80005250: nop
    
            goto L_80005264;
    }
    // 0x80005250: nop

    // 0x80005254: jal         0x800055DC
    // 0x80005258: nop

    func_800055DC(rdram, ctx);
        goto after_3;
    // 0x80005258: nop

    after_3:
    // 0x8000525C: b           L_80005274
    // 0x80005260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80005274;
    // 0x80005260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005264:
    // 0x80005264: b           L_80005274
    // 0x80005268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005274;
    // 0x80005268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000526C: b           L_80005274
    // 0x80005270: nop

        goto L_80005274;
    // 0x80005270: nop

L_80005274:
    // 0x80005274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005278: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000527C: jr          $ra
    // 0x80005280: nop

    return;
    // 0x80005280: nop

;}
RECOMP_FUNC void func_8006C1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C1E8: jal         0x8005F064
    // 0x8006C1EC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C1EC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_0:
    // 0x8006C1F0: b           L_8006C200
    // 0x8006C1F4: nop

        goto L_8006C200;
    // 0x8006C1F4: nop

    // 0x8006C1F8: b           L_8006C200
    // 0x8006C1FC: nop

        goto L_8006C200;
    // 0x8006C1FC: nop

L_8006C200:
    // 0x8006C200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C208: jr          $ra
    // 0x8006C20C: nop

    return;
    // 0x8006C20C: nop

;}
RECOMP_FUNC void func_800574CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800574CC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800574D0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800574D4: addiu       $t6, $a0, -0x104
    ctx->r14 = ADD32(ctx->r4, -0X104);
    // 0x800574D8: sltiu       $at, $t6, 0xE
    ctx->r1 = ctx->r14 < 0XE ? 1 : 0;
    // 0x800574DC: beq         $at, $zero, L_80057520
    if (ctx->r1 == 0) {
        // 0x800574E0: nop
    
            goto L_80057520;
    }
    // 0x800574E0: nop

    // 0x800574E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800574E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800574EC: addu        $at, $at, $t6
    gpr jr_addend_800574F8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800574F0: lw          $t6, -0xF30($at)
    ctx->r14 = ADD32(ctx->r1, -0XF30);
    // 0x800574F4: nop

    // 0x800574F8: jr          $t6
    // 0x800574FC: nop

    switch (jr_addend_800574F8 >> 2) {
        case 0: goto L_80057500; break;
        case 1: goto L_80057508; break;
        case 2: goto L_80057500; break;
        case 3: goto L_80057518; break;
        case 4: goto L_80057510; break;
        case 5: goto L_80057518; break;
        case 6: goto L_80057508; break;
        case 7: goto L_80057510; break;
        case 8: goto L_80057510; break;
        case 9: goto L_80057518; break;
        case 10: goto L_80057518; break;
        case 11: goto L_80057500; break;
        case 12: goto L_80057508; break;
        case 13: goto L_80057500; break;
        default: switch_error(__func__, 0x800574F8, 0x800EF0D0);
    }
    // 0x800574FC: nop

L_80057500:
    // 0x80057500: jr          $ra
    // 0x80057504: addiu       $v0, $zero, 0x69
    ctx->r2 = ADD32(0, 0X69);
    return;
    // 0x80057504: addiu       $v0, $zero, 0x69
    ctx->r2 = ADD32(0, 0X69);
L_80057508:
    // 0x80057508: jr          $ra
    // 0x8005750C: addiu       $v0, $zero, 0x6A
    ctx->r2 = ADD32(0, 0X6A);
    return;
    // 0x8005750C: addiu       $v0, $zero, 0x6A
    ctx->r2 = ADD32(0, 0X6A);
L_80057510:
    // 0x80057510: jr          $ra
    // 0x80057514: addiu       $v0, $zero, 0x6B
    ctx->r2 = ADD32(0, 0X6B);
    return;
    // 0x80057514: addiu       $v0, $zero, 0x6B
    ctx->r2 = ADD32(0, 0X6B);
L_80057518:
    // 0x80057518: jr          $ra
    // 0x8005751C: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    return;
    // 0x8005751C: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
L_80057520:
    // 0x80057520: jr          $ra
    // 0x80057524: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80057524: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80063010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063018: jal         0x8005F064
    // 0x8006301C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006301C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x80063020: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063024: b           L_80063034
    // 0x80063028: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063034;
    // 0x80063028: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006302C: b           L_80063034
    // 0x80063030: nop

        goto L_80063034;
    // 0x80063030: nop

L_80063034:
    // 0x80063034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006303C: jr          $ra
    // 0x80063040: nop

    return;
    // 0x80063040: nop

;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C6EC4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C6EC8: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x800C6ECC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C6ED0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6ED4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C6ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6EDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C6EE0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C6EE4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C6EE8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800C6EEC: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x800C6EF0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800C6EF4: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
    // 0x800C6EF8: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x800C6EFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6F00: beq         $t4, $at, L_800C6F30
    if (ctx->r12 == ctx->r1) {
        // 0x800C6F04: nop
    
            goto L_800C6F30;
    }
    // 0x800C6F04: nop

    // 0x800C6F08: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x800C6F0C: blez        $t5, L_800C6F20
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800C6F10: nop
    
            goto L_800C6F20;
    }
    // 0x800C6F10: nop

    // 0x800C6F14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C6F18: b           L_800C6F54
    // 0x800C6F1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_800C6F54;
    // 0x800C6F1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_800C6F20:
    // 0x800C6F20: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800C6F24: lw          $t9, 0x60($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X60);
    // 0x800C6F28: b           L_800C6F54
    // 0x800C6F2C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_800C6F54;
    // 0x800C6F2C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800C6F30:
    // 0x800C6F30: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x800C6F34: blez        $t2, L_800C6F48
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800C6F38: nop
    
            goto L_800C6F48;
    }
    // 0x800C6F38: nop

    // 0x800C6F3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C6F40: b           L_800C6F54
    // 0x800C6F44: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
        goto L_800C6F54;
    // 0x800C6F44: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_800C6F48:
    // 0x800C6F48: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C6F4C: lw          $t0, 0x60($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X60);
    // 0x800C6F50: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800C6F54:
    // 0x800C6F54: lbu         $t3, 0x25($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X25);
    // 0x800C6F58: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C6F5C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800C6F60: beq         $at, $zero, L_800C6F80
    if (ctx->r1 == 0) {
        // 0x800C6F64: nop
    
            goto L_800C6F80;
    }
    // 0x800C6F64: nop

    // 0x800C6F68: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x800C6F6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6F70: beq         $t5, $at, L_800C6F80
    if (ctx->r13 == ctx->r1) {
        // 0x800C6F74: nop
    
            goto L_800C6F80;
    }
    // 0x800C6F74: nop

    // 0x800C6F78: b           L_800C70E8
    // 0x800C6F7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800C70E8;
    // 0x800C6F7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800C6F80:
    // 0x800C6F80: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x800C6F84: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x800C6F88: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6F8C: sh          $at, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r1;
    // 0x800C6F90: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800C6F94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6F98: bne         $t1, $at, L_800C6FB8
    if (ctx->r9 != ctx->r1) {
        // 0x800C6F9C: nop
    
            goto L_800C6FB8;
    }
    // 0x800C6F9C: nop

    // 0x800C6FA0: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x800C6FA4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6FA8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800C6FAC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800C6FB0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800C6FB4: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_800C6FB8:
    // 0x800C6FB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C6FBC: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x800C6FC0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C6FC4: jal         0x800C70F8
    // 0x800C6FC8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    __osBlockSum(rdram, ctx);
        goto after_0;
    // 0x800C6FC8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x800C6FCC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C6FD0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6FD4: beq         $t9, $zero, L_800C6FE4
    if (ctx->r25 == 0) {
        // 0x800C6FD8: nop
    
            goto L_800C6FE4;
    }
    // 0x800C6FD8: nop

    // 0x800C6FDC: b           L_800C70E8
    // 0x800C6FE0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800C70E8;
    // 0x800C6FE0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800C6FE4:
    // 0x800C6FE4: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x800C6FE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6FEC: bne         $t8, $at, L_800C6FFC
    if (ctx->r24 != ctx->r1) {
        // 0x800C6FF0: nop
    
            goto L_800C6FFC;
    }
    // 0x800C6FF0: nop

    // 0x800C6FF4: b           L_800C70E8
    // 0x800C6FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C70E8;
    // 0x800C6FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C6FFC:
    // 0x800C6FFC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800C7000: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x800C7004: lw          $t1, 0x60($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X60);
    // 0x800C7008: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C700C: bne         $at, $zero, L_800C70A4
    if (ctx->r1 != 0) {
        // 0x800C7010: nop
    
            goto L_800C70A4;
    }
    // 0x800C7010: nop

L_800C7014:
    // 0x800C7014: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x800C7018: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x800C701C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7020: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800C7024: sh          $t3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r11;
    // 0x800C7028: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800C702C: lhu         $at, 0x0($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X0);
    // 0x800C7030: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800C7034: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800C7038: sh          $at, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r1;
    // 0x800C703C: lbu         $t3, 0x21($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X21);
    // 0x800C7040: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7044: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800C7048: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x800C704C: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x800C7050: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    // 0x800C7054: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C7058: lbu         $a1, 0x21($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X21);
    // 0x800C705C: jal         0x800C70F8
    // 0x800C7060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osBlockSum(rdram, ctx);
        goto after_1;
    // 0x800C7060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800C7064: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C7068: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C706C: beq         $t5, $zero, L_800C707C
    if (ctx->r13 == 0) {
        // 0x800C7070: nop
    
            goto L_800C707C;
    }
    // 0x800C7070: nop

    // 0x800C7074: b           L_800C70E8
    // 0x800C7078: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800C70E8;
    // 0x800C7078: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800C707C:
    // 0x800C707C: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x800C7080: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x800C7084: bne         $t8, $t0, L_800C70A4
    if (ctx->r24 != ctx->r8) {
        // 0x800C7088: nop
    
            goto L_800C70A4;
    }
    // 0x800C7088: nop

    // 0x800C708C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800C7090: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x800C7094: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800C7098: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800C709C: beq         $at, $zero, L_800C7014
    if (ctx->r1 == 0) {
        // 0x800C70A0: nop
    
            goto L_800C7014;
    }
    // 0x800C70A0: nop

L_800C70A4:
    // 0x800C70A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C70A8: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x800C70AC: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x800C70B0: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C70B4: bne         $at, $zero, L_800C70D4
    if (ctx->r1 != 0) {
        // 0x800C70B8: nop
    
            goto L_800C70D4;
    }
    // 0x800C70B8: nop

    // 0x800C70BC: lbu         $t8, 0x25($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X25);
    // 0x800C70C0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C70C4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800C70C8: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800C70CC: addu        $t2, $t5, $t0
    ctx->r10 = ADD32(ctx->r13, ctx->r8);
    // 0x800C70D0: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
L_800C70D4:
    // 0x800C70D4: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x800C70D8: lhu         $at, 0x0($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0X0);
    // 0x800C70DC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800C70E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C70E4: sh          $at, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r1;
L_800C70E8:
    // 0x800C70E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C70EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C70F0: jr          $ra
    // 0x800C70F4: nop

    return;
    // 0x800C70F4: nop

;}
RECOMP_FUNC void func_800A42C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A42C8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800A42CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A42D0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800A42D4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800A42D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A42DC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A42E0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A42E4: lw          $t7, -0x727C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X727C);
    // 0x800A42E8: lw          $t6, -0x7284($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7284);
    // 0x800A42EC: nop

    // 0x800A42F0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A42F4: bne         $at, $zero, L_800A4304
    if (ctx->r1 != 0) {
        // 0x800A42F8: nop
    
            goto L_800A4304;
    }
    // 0x800A42F8: nop

    // 0x800A42FC: b           L_800A4628
    // 0x800A4300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A4628;
    // 0x800A4300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A4304:
    // 0x800A4304: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A4308: lw          $t8, -0x7284($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7284);
    // 0x800A430C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A4310: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800A4314: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A4318: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A431C: lw          $t0, -0x728C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X728C);
    // 0x800A4320: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A4324: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800A4328: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800A432C: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800A4330: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4334: lui         $t2, 0x8
    ctx->r10 = S32(0X8 << 16);
    // 0x800A4338: ori         $t2, $t2, 0x4000
    ctx->r10 = ctx->r10 | 0X4000;
    // 0x800A433C: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
    // 0x800A4340: lhu         $t4, 0x76($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X76);
    // 0x800A4344: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4348: nop

    // 0x800A434C: sh          $t4, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r12;
    // 0x800A4350: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800A4354: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4358: nop

    // 0x800A435C: sw          $t6, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->r14;
    // 0x800A4360: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A4364: lw          $t9, 0x70E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70E4);
    // 0x800A4368: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800A436C: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x800A4370: jal         0x800C2AE8
    // 0x800A4374: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_0;
    // 0x800A4374: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    after_0:
    // 0x800A4378: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800A437C: jal         0x800C1A84
    // 0x800A4380: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_1;
    // 0x800A4380: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_1:
    // 0x800A4384: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A4388: lw          $t2, 0x7188($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7188);
    // 0x800A438C: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4390: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4394: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800A4398: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800A439C: sw          $t1, 0x30C8($at)
    MEM_W(0X30C8, ctx->r1) = ctx->r9;
    // 0x800A43A0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A43A4: lw          $t4, 0x7188($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7188);
    // 0x800A43A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A43AC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800A43B0: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800A43B4: sh          $zero, 0x30D0($at)
    MEM_H(0X30D0, ctx->r1) = 0;
    // 0x800A43B8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A43BC: lw          $t6, 0x7238($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7238);
    // 0x800A43C0: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800A43C4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800A43C8: bne         $t7, $zero, L_800A43F4
    if (ctx->r15 != 0) {
        // 0x800A43CC: nop
    
            goto L_800A43F4;
    }
    // 0x800A43CC: nop

    // 0x800A43D0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A43D4: lw          $t8, 0x7188($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7188);
    // 0x800A43D8: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800A43DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A43E0: lwc1        $f4, 0xB8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XB8);
    // 0x800A43E4: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x800A43E8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800A43EC: b           L_800A4478
    // 0x800A43F0: swc1        $f4, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f4.u32l;
        goto L_800A4478;
    // 0x800A43F0: swc1        $f4, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f4.u32l;
L_800A43F4:
    // 0x800A43F4: jal         0x800C1680
    // 0x800A43F8: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_2;
    // 0x800A43F8: nop

    after_2:
    // 0x800A43FC: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4400: nop

    // 0x800A4404: lhu         $a0, 0xC4($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0XC4);
    // 0x800A4408: jal         0x800AD70C
    // 0x800A440C: nop

    func_800AD70C(rdram, ctx);
        goto after_3;
    // 0x800A440C: nop

    after_3:
    // 0x800A4410: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A4414: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800A4418: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x800A441C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800A4420: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x800A4424: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800A4428: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800A442C: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x800A4430: addiu       $t3, $t1, 0xA0
    ctx->r11 = ADD32(ctx->r9, 0XA0);
    // 0x800A4434: jal         0x800C1AF4
    // 0x800A4438: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_4;
    // 0x800A4438: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x800A443C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4440: jal         0x800C1D44
    // 0x800A4444: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_5;
    // 0x800A4444: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_5:
    // 0x800A4448: jal         0x800C1A84
    // 0x800A444C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_6;
    // 0x800A444C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x800A4450: jal         0x800C1A28
    // 0x800A4454: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_7;
    // 0x800A4454: nop

    after_7:
    // 0x800A4458: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A445C: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x800A4460: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800A4464: lwc1        $f6, 0x38($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X38);
    // 0x800A4468: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A446C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800A4470: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A4474: swc1        $f6, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->f6.u32l;
L_800A4478:
    // 0x800A4478: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A447C: lw          $t9, 0x7188($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7188);
    // 0x800A4480: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A4484: addiu       $t0, $t0, 0x30C8
    ctx->r8 = ADD32(ctx->r8, 0X30C8);
    // 0x800A4488: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800A448C: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x800A4490: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A4494: sw          $t2, 0x50D4($at)
    MEM_W(0X50D4, ctx->r1) = ctx->r10;
    // 0x800A4498: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A449C: lw          $t1, 0x7188($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7188);
    // 0x800A44A0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x800A44A4: blez        $t1, L_800A45EC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800A44A8: nop
    
            goto L_800A45EC;
    }
    // 0x800A44A8: nop

L_800A44AC:
    // 0x800A44AC: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800A44B0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A44B4: addiu       $t5, $t5, 0x30C8
    ctx->r13 = ADD32(ctx->r13, 0X30C8);
    // 0x800A44B8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800A44BC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800A44C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A44C4: sw          $t6, 0x50CC($at)
    MEM_W(0X50CC, ctx->r1) = ctx->r14;
    // 0x800A44C8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A44CC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A44D0: lw          $t9, 0x50CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50CC);
    // 0x800A44D4: lw          $t7, 0x50D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50D4);
    // 0x800A44D8: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800A44DC: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800A44E0: nop

    // 0x800A44E4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800A44E8: nop

    // 0x800A44EC: bc1f        L_800A4514
    if (!c1cs) {
        // 0x800A44F0: nop
    
            goto L_800A4514;
    }
    // 0x800A44F0: nop

    // 0x800A44F4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A44F8: lw          $t8, 0x50D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50D4);
    // 0x800A44FC: nop

    // 0x800A4500: lh          $t0, 0x8($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X8);
    // 0x800A4504: nop

    // 0x800A4508: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800A450C: b           L_800A45D0
    // 0x800A4510: sh          $t2, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r10;
        goto L_800A45D0;
    // 0x800A4510: sh          $t2, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r10;
L_800A4514:
    // 0x800A4514: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A4518: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A451C: lw          $t3, 0x50CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50CC);
    // 0x800A4520: lw          $t1, 0x50D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50D4);
    // 0x800A4524: lwc1        $f18, 0xC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800A4528: lwc1        $f16, 0xC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800A452C: nop

    // 0x800A4530: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A4534: nop

    // 0x800A4538: bc1f        L_800A45B4
    if (!c1cs) {
        // 0x800A453C: nop
    
            goto L_800A45B4;
    }
    // 0x800A453C: nop

    // 0x800A4540: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A4544: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A4548: lw          $t7, 0x50D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50D4);
    // 0x800A454C: lw          $t4, 0x50CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50CC);
    // 0x800A4550: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800A4554: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A4558: lw          $t0, 0xC8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC8);
    // 0x800A455C: lw          $t6, 0xC8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC8);
    // 0x800A4560: nop

    // 0x800A4564: slt         $at, $t0, $t6
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A4568: bne         $at, $zero, L_800A4590
    if (ctx->r1 != 0) {
        // 0x800A456C: nop
    
            goto L_800A4590;
    }
    // 0x800A456C: nop

    // 0x800A4570: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A4574: lw          $t2, 0x50CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50CC);
    // 0x800A4578: nop

    // 0x800A457C: lh          $t8, 0x8($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X8);
    // 0x800A4580: nop

    // 0x800A4584: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800A4588: b           L_800A45AC
    // 0x800A458C: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
        goto L_800A45AC;
    // 0x800A458C: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
L_800A4590:
    // 0x800A4590: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A4594: lw          $t3, 0x50D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50D4);
    // 0x800A4598: nop

    // 0x800A459C: lh          $t4, 0x8($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X8);
    // 0x800A45A0: nop

    // 0x800A45A4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800A45A8: sh          $t5, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r13;
L_800A45AC:
    // 0x800A45AC: b           L_800A45D0
    // 0x800A45B0: nop

        goto L_800A45D0;
    // 0x800A45B0: nop

L_800A45B4:
    // 0x800A45B4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A45B8: lw          $t7, 0x50CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50CC);
    // 0x800A45BC: nop

    // 0x800A45C0: lh          $t9, 0x8($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X8);
    // 0x800A45C4: nop

    // 0x800A45C8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800A45CC: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
L_800A45D0:
    // 0x800A45D0: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800A45D4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A45D8: lw          $t1, 0x7188($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7188);
    // 0x800A45DC: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x800A45E0: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A45E4: bne         $at, $zero, L_800A44AC
    if (ctx->r1 != 0) {
        // 0x800A45E8: sw          $t8, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r24;
            goto L_800A44AC;
    }
    // 0x800A45E8: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
L_800A45EC:
    // 0x800A45EC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A45F0: lw          $t2, -0x7284($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7284);
    // 0x800A45F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A45F8: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800A45FC: sw          $t4, -0x7284($at)
    MEM_W(-0X7284, ctx->r1) = ctx->r12;
    // 0x800A4600: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A4604: lw          $t5, 0x7188($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7188);
    // 0x800A4608: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A460C: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x800A4610: sw          $t3, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = ctx->r11;
    // 0x800A4614: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4618: b           L_800A4628
    // 0x800A461C: nop

        goto L_800A4628;
    // 0x800A461C: nop

    // 0x800A4620: b           L_800A4628
    // 0x800A4624: nop

        goto L_800A4628;
    // 0x800A4624: nop

L_800A4628:
    // 0x800A4628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A462C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4630: jr          $ra
    // 0x800A4634: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800A4634: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80075C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075C34: jal         0x80061488
    // 0x80075C38: addiu       $a0, $zero, 0x468
    ctx->r4 = ADD32(0, 0X468);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075C38: addiu       $a0, $zero, 0x468
    ctx->r4 = ADD32(0, 0X468);
    after_0:
    // 0x80075C3C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80075C40: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80075C44: b           L_80075C54
    // 0x80075C48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075C54;
    // 0x80075C48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075C4C: b           L_80075C54
    // 0x80075C50: nop

        goto L_80075C54;
    // 0x80075C50: nop

L_80075C54:
    // 0x80075C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075C5C: jr          $ra
    // 0x80075C60: nop

    return;
    // 0x80075C60: nop

;}
RECOMP_FUNC void func_80009E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009E5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009E60: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80009E64: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80009E68: nop

    // 0x80009E6C: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80009E70: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80009E74:
    // 0x80009E74: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80009E78: lw          $t7, -0x5B28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5B28);
    // 0x80009E7C: nop

    // 0x80009E80: bne         $t7, $zero, L_80009E9C
    if (ctx->r15 != 0) {
        // 0x80009E84: nop
    
            goto L_80009E9C;
    }
    // 0x80009E84: nop

    // 0x80009E88: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80009E8C: lw          $t8, -0x5B30($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B30);
    // 0x80009E90: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80009E94: b           L_80009EC4
    // 0x80009E98: sw          $t8, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r24;
        goto L_80009EC4;
    // 0x80009E98: sw          $t8, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r24;
L_80009E9C:
    // 0x80009E9C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80009EA0: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x80009EA4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80009EA8: lh          $t1, 0x122($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X122);
    // 0x80009EAC: lw          $t4, -0x5B30($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5B30);
    // 0x80009EB0: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80009EB4: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80009EB8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80009EBC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80009EC0: sw          $t5, 0x138($t6)
    MEM_W(0X138, ctx->r14) = ctx->r13;
L_80009EC4:
    // 0x80009EC4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80009EC8: nop

    // 0x80009ECC: addiu       $t8, $t7, 0x160
    ctx->r24 = ADD32(ctx->r15, 0X160);
    // 0x80009ED0: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80009ED4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80009ED8: nop

    // 0x80009EDC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80009EE0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80009EE4: bne         $at, $zero, L_80009E74
    if (ctx->r1 != 0) {
        // 0x80009EE8: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_80009E74;
    }
    // 0x80009EE8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80009EEC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80009EF0: lw          $t1, -0x5B28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5B28);
    // 0x80009EF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80009EF8: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x80009EFC: sw          $t2, -0x5B28($at)
    MEM_W(-0X5B28, ctx->r1) = ctx->r10;
    // 0x80009F00: b           L_80009F08
    // 0x80009F04: nop

        goto L_80009F08;
    // 0x80009F04: nop

L_80009F08:
    // 0x80009F08: jr          $ra
    // 0x80009F0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80009F0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C3808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3808: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C380C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3810: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800C3814: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3818: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C381C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C3820: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C3824: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C3828: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C382C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3830: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C3834: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x800C3838: jal         0x800C42A0
    // 0x800C383C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C383C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_0:
    // 0x800C3840: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C3844: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C3848: jal         0x800C38F4
    // 0x800C384C: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    func_800C38F4(rdram, ctx);
        goto after_1;
    // 0x800C384C: div.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    after_1:
    // 0x800C3850: b           L_800C3860
    // 0x800C3854: nop

        goto L_800C3860;
    // 0x800C3854: nop

    // 0x800C3858: b           L_800C3860
    // 0x800C385C: nop

        goto L_800C3860;
    // 0x800C385C: nop

L_800C3860:
    // 0x800C3860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3864: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C3868: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C386C: jr          $ra
    // 0x800C3870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C3870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006CAF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB00: jal         0x8005F064
    // 0x8006CB04: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CB04: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_0:
    // 0x8006CB08: b           L_8006CB18
    // 0x8006CB0C: nop

        goto L_8006CB18;
    // 0x8006CB0C: nop

    // 0x8006CB10: b           L_8006CB18
    // 0x8006CB14: nop

        goto L_8006CB18;
    // 0x8006CB14: nop

L_8006CB18:
    // 0x8006CB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CB1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CB20: jr          $ra
    // 0x8006CB24: nop

    return;
    // 0x8006CB24: nop

;}
RECOMP_FUNC void func_8006C060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C068: jal         0x8005F064
    // 0x8006C06C: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C06C: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    after_0:
    // 0x8006C070: b           L_8006C080
    // 0x8006C074: nop

        goto L_8006C080;
    // 0x8006C074: nop

    // 0x8006C078: b           L_8006C080
    // 0x8006C07C: nop

        goto L_8006C080;
    // 0x8006C07C: nop

L_8006C080:
    // 0x8006C080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C088: jr          $ra
    // 0x8006C08C: nop

    return;
    // 0x8006C08C: nop

;}
RECOMP_FUNC void func_800656E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800656E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800656EC: jal         0x8005F064
    // 0x800656F0: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800656F0: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x800656F4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800656F8: b           L_80065708
    // 0x800656FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065708;
    // 0x800656FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065700: b           L_80065708
    // 0x80065704: nop

        goto L_80065708;
    // 0x80065704: nop

L_80065708:
    // 0x80065708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006570C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065710: jr          $ra
    // 0x80065714: nop

    return;
    // 0x80065714: nop

;}
RECOMP_FUNC void func_8005D800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D800: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005D804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D808: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D80C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D810: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D814: sw          $zero, 0x640($at)
    MEM_W(0X640, ctx->r1) = 0;
    // 0x8005D818: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D81C: sw          $zero, 0x644($at)
    MEM_W(0X644, ctx->r1) = 0;
    // 0x8005D820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D824: sb          $zero, 0xEE8($at)
    MEM_B(0XEE8, ctx->r1) = 0;
    // 0x8005D828: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D82C: sb          $zero, 0x1018($at)
    MEM_B(0X1018, ctx->r1) = 0;
    // 0x8005D830: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005D834:
    // 0x8005D834: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D838: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D83C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005D840: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005D844: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005D848: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005D84C: sb          $zero, 0xF18($at)
    MEM_B(0XF18, ctx->r1) = 0;
    // 0x8005D850: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D854: nop

    // 0x8005D858: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005D85C: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x8005D860: bne         $at, $zero, L_8005D834
    if (ctx->r1 != 0) {
        // 0x8005D864: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8005D834;
    }
    // 0x8005D864: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8005D868: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D86C: sb          $zero, 0x1040($at)
    MEM_B(0X1040, ctx->r1) = 0;
    // 0x8005D870: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8005D874:
    // 0x8005D874: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D878: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D87C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005D880: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8005D884: sw          $zero, 0x1028($at)
    MEM_W(0X1028, ctx->r1) = 0;
    // 0x8005D888: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D88C: nop

    // 0x8005D890: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005D894: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8005D898: bne         $at, $zero, L_8005D874
    if (ctx->r1 != 0) {
        // 0x8005D89C: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8005D874;
    }
    // 0x8005D89C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8005D8A0: jal         0x800BC6EC
    // 0x8005D8A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8005D8A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_0:
    // 0x8005D8A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D8AC: sw          $v0, 0x640($at)
    MEM_W(0X640, ctx->r1) = ctx->r2;
    // 0x8005D8B0: jal         0x800BC6EC
    // 0x8005D8B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8005D8B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_1:
    // 0x8005D8B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D8BC: sw          $v0, 0x644($at)
    MEM_W(0X644, ctx->r1) = ctx->r2;
    // 0x8005D8C0: jal         0x8005E908
    // 0x8005D8C4: nop

    func_8005E908(rdram, ctx);
        goto after_2;
    // 0x8005D8C4: nop

    after_2:
    // 0x8005D8C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D8CC: sw          $v0, 0xE64($at)
    MEM_W(0XE64, ctx->r1) = ctx->r2;
    // 0x8005D8D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005D8D4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005D8D8: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8005D8DC: ori         $t5, $t5, 0x9
    ctx->r13 = ctx->r13 | 0X9;
    // 0x8005D8E0: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8005D8E4: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8005D8E8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005D8EC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005D8F0: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005D8F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D8F8: sh          $t7, 0x7C($t8)
    MEM_H(0X7C, ctx->r24) = ctx->r15;
    // 0x8005D8FC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005D900: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005D904: nop

    // 0x8005D908: sw          $zero, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = 0;
    // 0x8005D90C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005D910: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005D914: nop

    // 0x8005D918: sw          $zero, 0x58($t0)
    MEM_W(0X58, ctx->r8) = 0;
    // 0x8005D91C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8005D920: jal         0x80056E88
    // 0x8005D924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_3;
    // 0x8005D924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8005D928: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x8005D92C: jal         0x8005EF24
    // 0x8005D930: nop

    func_8005EF24(rdram, ctx);
        goto after_4;
    // 0x8005D930: nop

    after_4:
    // 0x8005D934: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D938: sw          $zero, 0x161C($at)
    MEM_W(0X161C, ctx->r1) = 0;
    // 0x8005D93C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D940: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
    // 0x8005D944: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D948: sw          $zero, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = 0;
    // 0x8005D94C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8005D950: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8005D954: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005D958: bne         $t1, $at, L_8005D974
    if (ctx->r9 != ctx->r1) {
        // 0x8005D95C: nop
    
            goto L_8005D974;
    }
    // 0x8005D95C: nop

    // 0x8005D960: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005D964: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x8005D968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D96C: beq         $t2, $at, L_8005DA64
    if (ctx->r10 == ctx->r1) {
        // 0x8005D970: nop
    
            goto L_8005DA64;
    }
    // 0x8005D970: nop

L_8005D974:
    // 0x8005D974: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005D978: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005D97C: nop

    // 0x8005D980: lh          $t4, 0x30($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X30);
    // 0x8005D984: nop

    // 0x8005D988: slti        $at, $t4, 0x2BC
    ctx->r1 = SIGNED(ctx->r12) < 0X2BC ? 1 : 0;
    // 0x8005D98C: bne         $at, $zero, L_8005D9B0
    if (ctx->r1 != 0) {
        // 0x8005D990: nop
    
            goto L_8005D9B0;
    }
    // 0x8005D990: nop

    // 0x8005D994: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005D998: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8005D99C: nop

    // 0x8005D9A0: lh          $t6, 0x30($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X30);
    // 0x8005D9A4: nop

    // 0x8005D9A8: addiu       $t7, $t6, -0x32
    ctx->r15 = ADD32(ctx->r14, -0X32);
    // 0x8005D9AC: sh          $t7, 0x30($t5)
    MEM_H(0X30, ctx->r13) = ctx->r15;
L_8005D9B0:
    // 0x8005D9B0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005D9B4: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005D9B8: nop

    // 0x8005D9BC: lh          $t9, 0x32($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X32);
    // 0x8005D9C0: nop

    // 0x8005D9C4: slti        $at, $t9, 0x2BC
    ctx->r1 = SIGNED(ctx->r25) < 0X2BC ? 1 : 0;
    // 0x8005D9C8: bne         $at, $zero, L_8005D9EC
    if (ctx->r1 != 0) {
        // 0x8005D9CC: nop
    
            goto L_8005D9EC;
    }
    // 0x8005D9CC: nop

    // 0x8005D9D0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005D9D4: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8005D9D8: nop

    // 0x8005D9DC: lh          $t1, 0x32($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X32);
    // 0x8005D9E0: nop

    // 0x8005D9E4: addiu       $t2, $t1, -0x32
    ctx->r10 = ADD32(ctx->r9, -0X32);
    // 0x8005D9E8: sh          $t2, 0x32($t0)
    MEM_H(0X32, ctx->r8) = ctx->r10;
L_8005D9EC:
    // 0x8005D9EC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005D9F0: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005D9F4: nop

    // 0x8005D9F8: lh          $t4, 0x34($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X34);
    // 0x8005D9FC: nop

    // 0x8005DA00: slti        $at, $t4, 0x2BC
    ctx->r1 = SIGNED(ctx->r12) < 0X2BC ? 1 : 0;
    // 0x8005DA04: bne         $at, $zero, L_8005DA28
    if (ctx->r1 != 0) {
        // 0x8005DA08: nop
    
            goto L_8005DA28;
    }
    // 0x8005DA08: nop

    // 0x8005DA0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005DA10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005DA14: nop

    // 0x8005DA18: lh          $t7, 0x34($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X34);
    // 0x8005DA1C: nop

    // 0x8005DA20: addiu       $t5, $t7, -0x32
    ctx->r13 = ADD32(ctx->r15, -0X32);
    // 0x8005DA24: sh          $t5, 0x34($t6)
    MEM_H(0X34, ctx->r14) = ctx->r13;
L_8005DA28:
    // 0x8005DA28: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005DA2C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005DA30: nop

    // 0x8005DA34: lh          $t9, 0x36($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X36);
    // 0x8005DA38: nop

    // 0x8005DA3C: slti        $at, $t9, 0x2BC
    ctx->r1 = SIGNED(ctx->r25) < 0X2BC ? 1 : 0;
    // 0x8005DA40: bne         $at, $zero, L_8005DA64
    if (ctx->r1 != 0) {
        // 0x8005DA44: nop
    
            goto L_8005DA64;
    }
    // 0x8005DA44: nop

    // 0x8005DA48: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DA4C: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005DA50: nop

    // 0x8005DA54: lh          $t2, 0x36($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X36);
    // 0x8005DA58: nop

    // 0x8005DA5C: addiu       $t0, $t2, -0x32
    ctx->r8 = ADD32(ctx->r10, -0X32);
    // 0x8005DA60: sh          $t0, 0x36($t1)
    MEM_H(0X36, ctx->r9) = ctx->r8;
L_8005DA64:
    // 0x8005DA64: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005DA68: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005DA6C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8005DA70: bne         $t3, $at, L_8005DABC
    if (ctx->r11 != ctx->r1) {
        // 0x8005DA74: nop
    
            goto L_8005DABC;
    }
    // 0x8005DA74: nop

    // 0x8005DA78: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005DA7C: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x8005DA80: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8005DA84: bne         $t4, $at, L_8005DABC
    if (ctx->r12 != ctx->r1) {
        // 0x8005DA88: nop
    
            goto L_8005DABC;
    }
    // 0x8005DA88: nop

    // 0x8005DA8C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005DA90: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8005DA94: nop

    // 0x8005DA98: lh          $t5, 0x38($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X38);
    // 0x8005DA9C: nop

    // 0x8005DAA0: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x8005DAA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005DAA8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005DAAC: nop

    // 0x8005DAB0: lh          $t8, 0x3A($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X3A);
    // 0x8005DAB4: nop

    // 0x8005DAB8: sh          $t8, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r24;
L_8005DABC:
    // 0x8005DABC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8005DAC0: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8005DAC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DAC8: bne         $t9, $at, L_8005DAE4
    if (ctx->r25 != ctx->r1) {
        // 0x8005DACC: nop
    
            goto L_8005DAE4;
    }
    // 0x8005DACC: nop

    // 0x8005DAD0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005DAD4: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x8005DAD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DADC: beq         $t2, $at, L_8005DB34
    if (ctx->r10 == ctx->r1) {
        // 0x8005DAE0: nop
    
            goto L_8005DB34;
    }
    // 0x8005DAE0: nop

L_8005DAE4:
    // 0x8005DAE4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8005DAE8: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8005DAEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DAF0: bne         $t0, $at, L_8005DB0C
    if (ctx->r8 != ctx->r1) {
        // 0x8005DAF4: nop
    
            goto L_8005DB0C;
    }
    // 0x8005DAF4: nop

    // 0x8005DAF8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8005DAFC: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x8005DB00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DB04: beq         $t1, $at, L_8005DB34
    if (ctx->r9 == ctx->r1) {
        // 0x8005DB08: nop
    
            goto L_8005DB34;
    }
    // 0x8005DB08: nop

L_8005DB0C:
    // 0x8005DB0C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005DB10: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005DB14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DB18: bne         $t3, $at, L_8005DB90
    if (ctx->r11 != ctx->r1) {
        // 0x8005DB1C: nop
    
            goto L_8005DB90;
    }
    // 0x8005DB1C: nop

    // 0x8005DB20: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005DB24: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x8005DB28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005DB2C: bne         $t4, $at, L_8005DB90
    if (ctx->r12 != ctx->r1) {
        // 0x8005DB30: nop
    
            goto L_8005DB90;
    }
    // 0x8005DB30: nop

L_8005DB34:
    // 0x8005DB34: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005DB38: lw          $t5, 0x13CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X13CC);
    // 0x8005DB3C: nop

    // 0x8005DB40: bne         $t5, $zero, L_8005DB88
    if (ctx->r13 != 0) {
        // 0x8005DB44: nop
    
            goto L_8005DB88;
    }
    // 0x8005DB44: nop

    // 0x8005DB48: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8005DB4C: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8005DB50: nop

    // 0x8005DB54: bgez        $t7, L_8005DB88
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005DB58: nop
    
            goto L_8005DB88;
    }
    // 0x8005DB58: nop

    // 0x8005DB5C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8005DB60: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8005DB64: lhu         $t6, 0x6($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X6);
    // 0x8005DB68: nop

    // 0x8005DB6C: ori         $t9, $t6, 0x1
    ctx->r25 = ctx->r14 | 0X1;
    // 0x8005DB70: sh          $t9, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r25;
    // 0x8005DB74: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005DB78: lw          $t2, 0x13CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X13CC);
    // 0x8005DB7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005DB80: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8005DB84: sw          $t0, 0x13CC($at)
    MEM_W(0X13CC, ctx->r1) = ctx->r8;
L_8005DB88:
    // 0x8005DB88: b           L_8005DB98
    // 0x8005DB8C: nop

        goto L_8005DB98;
    // 0x8005DB8C: nop

L_8005DB90:
    // 0x8005DB90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005DB94: sw          $zero, 0x13CC($at)
    MEM_W(0X13CC, ctx->r1) = 0;
L_8005DB98:
    // 0x8005DB98: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8005DB9C: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8005DBA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DBA4: bne         $t1, $at, L_8005DC08
    if (ctx->r9 != ctx->r1) {
        // 0x8005DBA8: nop
    
            goto L_8005DC08;
    }
    // 0x8005DBA8: nop

    // 0x8005DBAC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005DBB0: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8005DBB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DBB8: bne         $t3, $at, L_8005DC08
    if (ctx->r11 != ctx->r1) {
        // 0x8005DBBC: nop
    
            goto L_8005DC08;
    }
    // 0x8005DBBC: nop

    // 0x8005DBC0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8005DBC4: lh          $t4, -0x73C0($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X73C0);
    // 0x8005DBC8: nop

    // 0x8005DBCC: bgez        $t4, L_8005DC08
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8005DBD0: nop
    
            goto L_8005DC08;
    }
    // 0x8005DBD0: nop

    // 0x8005DBD4: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x8005DBD8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8005DBDC: lw          $t7, -0x33BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33BC);
    // 0x8005DBE0: lw          $t5, 0x18EC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X18EC);
    // 0x8005DBE4: nop

    // 0x8005DBE8: beq         $t5, $t7, L_8005DC08
    if (ctx->r13 == ctx->r15) {
        // 0x8005DBEC: nop
    
            goto L_8005DC08;
    }
    // 0x8005DBEC: nop

    // 0x8005DBF0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8005DBF4: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8005DBF8: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x8005DBFC: nop

    // 0x8005DC00: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x8005DC04: sh          $t8, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r24;
L_8005DC08:
    // 0x8005DC08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005DC0C: lh          $t2, 0x721C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X721C);
    // 0x8005DC10: nop

    // 0x8005DC14: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8005DC18: beq         $at, $zero, L_8005E070
    if (ctx->r1 == 0) {
        // 0x8005DC1C: nop
    
            goto L_8005E070;
    }
    // 0x8005DC1C: nop

    // 0x8005DC20: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8005DC24: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8005DC28: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8005DC2C: beq         $t0, $at, L_8005E070
    if (ctx->r8 == ctx->r1) {
        // 0x8005DC30: nop
    
            goto L_8005E070;
    }
    // 0x8005DC30: nop

    // 0x8005DC34: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DC38: lbu         $t1, 0xD94($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XD94);
    // 0x8005DC3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DC40: bne         $t1, $at, L_8005DDE4
    if (ctx->r9 != ctx->r1) {
        // 0x8005DC44: nop
    
            goto L_8005DDE4;
    }
    // 0x8005DC44: nop

    // 0x8005DC48: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8005DC4C: jal         0x800047C8
    // 0x8005DC50: addiu       $a0, $a0, 0x61A0
    ctx->r4 = ADD32(ctx->r4, 0X61A0);
    func_800047C8(rdram, ctx);
        goto after_5;
    // 0x8005DC50: addiu       $a0, $a0, 0x61A0
    ctx->r4 = ADD32(ctx->r4, 0X61A0);
    after_5:
    // 0x8005DC54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005DC58: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005DC5C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005DC60: lwc1        $f4, 0x61A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61A0);
    // 0x8005DC64: nop

    // 0x8005DC68: swc1        $f4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f4.u32l;
    // 0x8005DC6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8005DC70: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005DC74: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005DC78: lwc1        $f6, 0x61A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61A4);
    // 0x8005DC7C: nop

    // 0x8005DC80: swc1        $f6, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f6.u32l;
    // 0x8005DC84: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005DC88: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005DC8C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005DC90: lw          $t5, 0xE4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE4C);
    // 0x8005DC94: nop

    // 0x8005DC98: sw          $t5, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r13;
    // 0x8005DC9C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8005DCA0: lhu         $t9, 0x61B8($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X61B8);
    // 0x8005DCA4: nop

    // 0x8005DCA8: beq         $t9, $zero, L_8005DCD8
    if (ctx->r25 == 0) {
        // 0x8005DCAC: nop
    
            goto L_8005DCD8;
    }
    // 0x8005DCAC: nop

    // 0x8005DCB0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005DCB4: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005DCB8: nop

    // 0x8005DCBC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8005DCC0: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8005DCC4: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x8005DCC8: ori         $t3, $t7, 0x8
    ctx->r11 = ctx->r15 | 0X8;
    // 0x8005DCCC: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8005DCD0: b           L_8005DD00
    // 0x8005DCD4: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
        goto L_8005DD00;
    // 0x8005DCD4: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
L_8005DCD8:
    // 0x8005DCD8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005DCDC: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005DCE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005DCE4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8005DCE8: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8005DCEC: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8005DCF0: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005DCF4: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005DCF8: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8005DCFC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_8005DD00:
    // 0x8005DD00: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8005DD04: lhu         $t1, 0x61BC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X61BC);
    // 0x8005DD08: nop

    // 0x8005DD0C: beq         $t1, $zero, L_8005DDDC
    if (ctx->r9 == 0) {
        // 0x8005DD10: nop
    
            goto L_8005DDDC;
    }
    // 0x8005DD10: nop

    // 0x8005DD14: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005DD18: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005DD1C: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8005DD20: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8005DD24: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8005DD28: or          $t4, $t9, $zero
    ctx->r12 = ctx->r25 | 0;
    // 0x8005DD2C: or          $t8, $t2, $zero
    ctx->r24 = ctx->r10 | 0;
    // 0x8005DD30: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x8005DD34: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8005DD38: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8005DD3C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005DD40: lh          $s0, 0xDA4($s0)
    ctx->r16 = MEM_H(ctx->r16, 0XDA4);
    // 0x8005DD44: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x8005DD48: beq         $s0, $at, L_8005DD64
    if (ctx->r16 == ctx->r1) {
        // 0x8005DD4C: nop
    
            goto L_8005DD64;
    }
    // 0x8005DD4C: nop

    // 0x8005DD50: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x8005DD54: beq         $s0, $at, L_8005DD98
    if (ctx->r16 == ctx->r1) {
        // 0x8005DD58: nop
    
            goto L_8005DD98;
    }
    // 0x8005DD58: nop

    // 0x8005DD5C: b           L_8005DDCC
    // 0x8005DD60: nop

        goto L_8005DDCC;
    // 0x8005DD60: nop

L_8005DD64:
    // 0x8005DD64: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005DD68: lh          $t5, 0x12BA($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X12BA);
    // 0x8005DD6C: nop

    // 0x8005DD70: andi        $t6, $t5, 0xC0
    ctx->r14 = ctx->r13 & 0XC0;
    // 0x8005DD74: beq         $t6, $zero, L_8005DD88
    if (ctx->r14 == 0) {
        // 0x8005DD78: nop
    
            goto L_8005DD88;
    }
    // 0x8005DD78: nop

    // 0x8005DD7C: addiu       $t7, $zero, 0xAB
    ctx->r15 = ADD32(0, 0XAB);
    // 0x8005DD80: b           L_8005DD90
    // 0x8005DD84: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
        goto L_8005DD90;
    // 0x8005DD84: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
L_8005DD88:
    // 0x8005DD88: addiu       $t0, $zero, 0xAD
    ctx->r8 = ADD32(0, 0XAD);
    // 0x8005DD8C: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
L_8005DD90:
    // 0x8005DD90: b           L_8005DDDC
    // 0x8005DD94: nop

        goto L_8005DDDC;
    // 0x8005DD94: nop

L_8005DD98:
    // 0x8005DD98: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DD9C: lh          $t1, 0x12BA($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X12BA);
    // 0x8005DDA0: nop

    // 0x8005DDA4: andi        $t2, $t1, 0xC0
    ctx->r10 = ctx->r9 & 0XC0;
    // 0x8005DDA8: beq         $t2, $zero, L_8005DDBC
    if (ctx->r10 == 0) {
        // 0x8005DDAC: nop
    
            goto L_8005DDBC;
    }
    // 0x8005DDAC: nop

    // 0x8005DDB0: addiu       $t3, $zero, 0xAC
    ctx->r11 = ADD32(0, 0XAC);
    // 0x8005DDB4: b           L_8005DDC4
    // 0x8005DDB8: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
        goto L_8005DDC4;
    // 0x8005DDB8: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
L_8005DDBC:
    // 0x8005DDBC: addiu       $t8, $zero, 0xAE
    ctx->r24 = ADD32(0, 0XAE);
    // 0x8005DDC0: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
L_8005DDC4:
    // 0x8005DDC4: b           L_8005DDDC
    // 0x8005DDC8: nop

        goto L_8005DDDC;
    // 0x8005DDC8: nop

L_8005DDCC:
    // 0x8005DDCC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005DDD0: lh          $t9, 0xDA4($t9)
    ctx->r25 = MEM_H(ctx->r25, 0XDA4);
    // 0x8005DDD4: nop

    // 0x8005DDD8: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
L_8005DDDC:
    // 0x8005DDDC: b           L_8005DE74
    // 0x8005DDE0: nop

        goto L_8005DE74;
    // 0x8005DDE0: nop

L_8005DDE4:
    // 0x8005DDE4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005DDE8: lbu         $t4, 0xD94($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0XD94);
    // 0x8005DDEC: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8005DDF0: bne         $t4, $at, L_8005DE74
    if (ctx->r12 != ctx->r1) {
        // 0x8005DDF4: nop
    
            goto L_8005DE74;
    }
    // 0x8005DDF4: nop

    // 0x8005DDF8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8005DDFC: lh          $t5, -0x73C0($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X73C0);
    // 0x8005DE00: nop

    // 0x8005DE04: bgez        $t5, L_8005DE74
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8005DE08: nop
    
            goto L_8005DE74;
    }
    // 0x8005DE08: nop

    // 0x8005DE0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005DE10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005DE14: nop

    // 0x8005DE18: lh          $t7, 0x40($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X40);
    // 0x8005DE1C: nop

    // 0x8005DE20: addiu       $t0, $t7, 0x3
    ctx->r8 = ADD32(ctx->r15, 0X3);
    // 0x8005DE24: sh          $t0, 0x40($t6)
    MEM_H(0X40, ctx->r14) = ctx->r8;
    // 0x8005DE28: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DE2C: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005DE30: nop

    // 0x8005DE34: lh          $t2, 0x40($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X40);
    // 0x8005DE38: nop

    // 0x8005DE3C: slti        $at, $t2, 0x3E8
    ctx->r1 = SIGNED(ctx->r10) < 0X3E8 ? 1 : 0;
    // 0x8005DE40: bne         $at, $zero, L_8005DE58
    if (ctx->r1 != 0) {
        // 0x8005DE44: nop
    
            goto L_8005DE58;
    }
    // 0x8005DE44: nop

    // 0x8005DE48: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005DE4C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8005DE50: addiu       $t3, $zero, 0x3E7
    ctx->r11 = ADD32(0, 0X3E7);
    // 0x8005DE54: sh          $t3, 0x40($t8)
    MEM_H(0X40, ctx->r24) = ctx->r11;
L_8005DE58:
    // 0x8005DE58: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8005DE5C: lw          $t9, 0x718C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X718C);
    // 0x8005DE60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8005DE64: addiu       $t4, $t9, -0x12C
    ctx->r12 = ADD32(ctx->r25, -0X12C);
    // 0x8005DE68: sw          $t4, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r12;
    // 0x8005DE6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005DE70: sb          $zero, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = 0;
L_8005DE74:
    // 0x8005DE74: lh          $t5, 0x2A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2A);
    // 0x8005DE78: addiu       $at, $zero, 0xAD
    ctx->r1 = ADD32(0, 0XAD);
    // 0x8005DE7C: beq         $t5, $at, L_8005DE90
    if (ctx->r13 == ctx->r1) {
        // 0x8005DE80: nop
    
            goto L_8005DE90;
    }
    // 0x8005DE80: nop

    // 0x8005DE84: addiu       $at, $zero, 0xAE
    ctx->r1 = ADD32(0, 0XAE);
    // 0x8005DE88: bne         $t5, $at, L_8005DEBC
    if (ctx->r13 != ctx->r1) {
        // 0x8005DE8C: nop
    
            goto L_8005DEBC;
    }
    // 0x8005DE8C: nop

L_8005DE90:
    // 0x8005DE90: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005DE94: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005DE98: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8005DE9C: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8005DEA0: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8005DEA4: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x8005DEA8: or          $t6, $t0, $zero
    ctx->r14 = ctx->r8 | 0;
    // 0x8005DEAC: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x8005DEB0: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8005DEB4: b           L_8005DF58
    // 0x8005DEB8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
        goto L_8005DF58;
    // 0x8005DEB8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_8005DEBC:
    // 0x8005DEBC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005DEC0: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005DEC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DEC8: beq         $t3, $at, L_8005DF58
    if (ctx->r11 == ctx->r1) {
        // 0x8005DECC: nop
    
            goto L_8005DF58;
    }
    // 0x8005DECC: nop

    // 0x8005DED0: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8005DED4: addiu       $at, $zero, 0x9B
    ctx->r1 = ADD32(0, 0X9B);
    // 0x8005DED8: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DEDC: nop
    
            goto L_8005DF34;
    }
    // 0x8005DEDC: nop

    // 0x8005DEE0: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x8005DEE4: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DEE8: nop
    
            goto L_8005DF34;
    }
    // 0x8005DEE8: nop

    // 0x8005DEEC: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8005DEF0: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DEF4: nop
    
            goto L_8005DF34;
    }
    // 0x8005DEF4: nop

    // 0x8005DEF8: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x8005DEFC: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DF00: nop
    
            goto L_8005DF34;
    }
    // 0x8005DF00: nop

    // 0x8005DF04: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x8005DF08: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DF0C: nop
    
            goto L_8005DF34;
    }
    // 0x8005DF0C: nop

    // 0x8005DF10: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x8005DF14: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DF18: nop
    
            goto L_8005DF34;
    }
    // 0x8005DF18: nop

    // 0x8005DF1C: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x8005DF20: beq         $t8, $at, L_8005DF34
    if (ctx->r24 == ctx->r1) {
        // 0x8005DF24: nop
    
            goto L_8005DF34;
    }
    // 0x8005DF24: nop

    // 0x8005DF28: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x8005DF2C: bne         $t8, $at, L_8005DF58
    if (ctx->r24 != ctx->r1) {
        // 0x8005DF30: nop
    
            goto L_8005DF58;
    }
    // 0x8005DF30: nop

L_8005DF34:
    // 0x8005DF34: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005DF38: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005DF3C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8005DF40: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8005DF44: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8005DF48: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8005DF4C: or          $t1, $t5, $at
    ctx->r9 = ctx->r13 | ctx->r1;
    // 0x8005DF50: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8005DF54: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
L_8005DF58:
    // 0x8005DF58: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8005DF5C: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8005DF60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005DF64: bne         $t6, $at, L_8005E024
    if (ctx->r14 != ctx->r1) {
        // 0x8005DF68: nop
    
            goto L_8005E024;
    }
    // 0x8005DF68: nop

    // 0x8005DF6C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005DF70: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8005DF74: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005DF78: bne         $t7, $at, L_8005E024
    if (ctx->r15 != ctx->r1) {
        // 0x8005DF7C: nop
    
            goto L_8005E024;
    }
    // 0x8005DF7C: nop

    // 0x8005DF80: addiu       $t2, $zero, 0x23
    ctx->r10 = ADD32(0, 0X23);
    // 0x8005DF84: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
    // 0x8005DF88: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005DF8C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005DF90: nop

    // 0x8005DF94: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8005DF98: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8005DF9C: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x8005DFA0: ori         $t5, $t9, 0x20
    ctx->r13 = ctx->r25 | 0X20;
    // 0x8005DFA4: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8005DFA8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8005DFAC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005DFB0: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005DFB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005DFB8: nop

    // 0x8005DFBC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x8005DFC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8005DFC4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005DFC8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005DFCC: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8005DFD0: nop

    // 0x8005DFD4: swc1        $f10, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f10.u32l;
    // 0x8005DFD8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005DFDC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005DFE0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8005DFE4: sw          $t6, 0x9C($t7)
    MEM_W(0X9C, ctx->r15) = ctx->r14;
    // 0x8005DFE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005DFEC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005DFF0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005DFF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005DFF8: nop

    // 0x8005DFFC: swc1        $f16, 0xA0($t2)
    MEM_W(0XA0, ctx->r10) = ctx->f16.u32l;
    // 0x8005E000: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005E004: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005E008: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8005E00C: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x8005E010: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8005E014: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8005E018: or          $t1, $t5, $at
    ctx->r9 = ctx->r13 | ctx->r1;
    // 0x8005E01C: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8005E020: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_8005E024:
    // 0x8005E024: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005E028: lw          $a0, 0xE64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE64);
    // 0x8005E02C: jal         0x8005EC54
    // 0x8005E030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005EC54(rdram, ctx);
        goto after_6;
    // 0x8005E030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8005E034: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    // 0x8005E038: jal         0x80056E88
    // 0x8005E03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_7;
    // 0x8005E03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8005E040: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005E044: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005E048: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8005E04C: sra         $t9, $s1, 16
    ctx->r25 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8005E050: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8005E054: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x8005E058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E05C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005E060: jal         0x8004EF90
    // 0x8005E064: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_8;
    // 0x8005E064: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x8005E068: b           L_8005E098
    // 0x8005E06C: nop

        goto L_8005E098;
    // 0x8005E06C: nop

L_8005E070:
    // 0x8005E070: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005E074: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005E078: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x8005E07C: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8005E080: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x8005E084: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005E088: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x8005E08C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8005E090: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005E094: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
L_8005E098:
    // 0x8005E098: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E09C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005E0A0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E0A4: addiu       $t0, $t0, 0xE80
    ctx->r8 = ADD32(ctx->r8, 0XE80);
    // 0x8005E0A8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8005E0AC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E0B0: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8005E0B4: nop

    // 0x8005E0B8: sb          $zero, 0x7E($t1)
    MEM_B(0X7E, ctx->r9) = 0;
    // 0x8005E0BC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E0C0: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8005E0C4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8005E0C8: sb          $t8, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r24;
    // 0x8005E0CC: addiu       $t2, $zero, 0x12C
    ctx->r10 = ADD32(0, 0X12C);
    // 0x8005E0D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E0D4: sw          $t2, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r10;
    // 0x8005E0D8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005E0DC: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005E0E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005E0E4: bne         $t3, $at, L_8005E10C
    if (ctx->r11 != ctx->r1) {
        // 0x8005E0E8: nop
    
            goto L_8005E10C;
    }
    // 0x8005E0E8: nop

    // 0x8005E0EC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005E0F0: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x8005E0F4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005E0F8: bne         $t4, $at, L_8005E10C
    if (ctx->r12 != ctx->r1) {
        // 0x8005E0FC: nop
    
            goto L_8005E10C;
    }
    // 0x8005E0FC: nop

    // 0x8005E100: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x8005E104: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E108: sw          $t5, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r13;
L_8005E10C:
    // 0x8005E10C: jal         0x80048F80
    // 0x8005E110: nop

    func_80048F80(rdram, ctx);
        goto after_9;
    // 0x8005E110: nop

    after_9:
    // 0x8005E114: jal         0x80062640
    // 0x8005E118: nop

    func_80062640(rdram, ctx);
        goto after_10;
    // 0x8005E118: nop

    after_10:
    // 0x8005E11C: jal         0x800491A0
    // 0x8005E120: nop

    func_800491A0(rdram, ctx);
        goto after_11;
    // 0x8005E120: nop

    after_11:
    // 0x8005E124: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005E128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E12C: swc1        $f18, 0x125C($at)
    MEM_W(0X125C, ctx->r1) = ctx->f18.u32l;
    // 0x8005E130: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8005E134: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8005E138: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005E13C: bne         $t6, $at, L_8005E180
    if (ctx->r14 != ctx->r1) {
        // 0x8005E140: nop
    
            goto L_8005E180;
    }
    // 0x8005E140: nop

    // 0x8005E144: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005E148: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8005E14C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E150: bne         $t7, $at, L_8005E180
    if (ctx->r15 != ctx->r1) {
        // 0x8005E154: nop
    
            goto L_8005E180;
    }
    // 0x8005E154: nop

    // 0x8005E158: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8005E15C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005E160: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E164: swc1        $f4, 0x125C($at)
    MEM_W(0X125C, ctx->r1) = ctx->f4.u32l;
    // 0x8005E168: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005E16C: lw          $a1, 0x125C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X125C);
    // 0x8005E170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E174: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005E178: jal         0x800ACC34
    // 0x8005E17C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800ACC34(rdram, ctx);
        goto after_12;
    // 0x8005E17C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_12:
L_8005E180:
    // 0x8005E180: b           L_8005E188
    // 0x8005E184: nop

        goto L_8005E188;
    // 0x8005E184: nop

L_8005E188:
    // 0x8005E188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E18C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005E190: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005E194: jr          $ra
    // 0x8005E198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005E198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80062D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062D8C: jal         0x80061488
    // 0x80062D90: addiu       $a0, $zero, 0x6A8
    ctx->r4 = ADD32(0, 0X6A8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062D90: addiu       $a0, $zero, 0x6A8
    ctx->r4 = ADD32(0, 0X6A8);
    after_0:
    // 0x80062D94: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062D98: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062D9C: b           L_80062DAC
    // 0x80062DA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062DAC;
    // 0x80062DA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062DA4: b           L_80062DAC
    // 0x80062DA8: nop

        goto L_80062DAC;
    // 0x80062DA8: nop

L_80062DAC:
    // 0x80062DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062DB4: jr          $ra
    // 0x80062DB8: nop

    return;
    // 0x80062DB8: nop

;}
RECOMP_FUNC void func_80044530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044530: addiu       $sp, $sp, -0x168
    ctx->r29 = ADD32(ctx->r29, -0X168);
    // 0x80044534: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80044538: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8004453C: swc1        $f31, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80044540: swc1        $f30, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f30.u32l;
    // 0x80044544: swc1        $f29, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80044548: swc1        $f28, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f28.u32l;
    // 0x8004454C: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80044550: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x80044554: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80044558: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x8004455C: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80044560: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80044564: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80044568: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8004456C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80044570: addiu       $t7, $t7, -0x2B98
    ctx->r15 = ADD32(ctx->r15, -0X2B98);
    // 0x80044574: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80044578: addiu       $t6, $sp, 0xEC
    ctx->r14 = ADD32(ctx->r29, 0XEC);
L_8004457C:
    // 0x8004457C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80044580: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80044584: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80044588: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8004458C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80044590: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80044594: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80044598: bne         $t7, $t9, L_8004457C
    if (ctx->r15 != ctx->r25) {
        // 0x8004459C: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8004457C;
    }
    // 0x8004459C: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800445A0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800445A4: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800445A8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800445AC: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800445B0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800445B4: addiu       $t1, $t1, -0x2B60
    ctx->r9 = ADD32(ctx->r9, -0X2B60);
    // 0x800445B8: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x800445BC: addiu       $t0, $sp, 0xE0
    ctx->r8 = ADD32(ctx->r29, 0XE0);
    // 0x800445C0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800445C4: lhu         $at, 0x8($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X8);
    // 0x800445C8: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x800445CC: sh          $at, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r1;
    // 0x800445D0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x800445D4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800445D8: addiu       $t5, $t5, -0x2B54
    ctx->r13 = ADD32(ctx->r13, -0X2B54);
    // 0x800445DC: addiu       $t9, $t5, 0x24
    ctx->r25 = ADD32(ctx->r13, 0X24);
    // 0x800445E0: addiu       $t4, $sp, 0xB4
    ctx->r12 = ADD32(ctx->r29, 0XB4);
L_800445E4:
    // 0x800445E4: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x800445E8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800445EC: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x800445F0: lw          $at, -0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X8);
    // 0x800445F4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x800445F8: sw          $at, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r1;
    // 0x800445FC: lw          $at, -0x4($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X4);
    // 0x80044600: bne         $t5, $t9, L_800445E4
    if (ctx->r13 != ctx->r25) {
        // 0x80044604: sw          $at, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r1;
            goto L_800445E4;
    }
    // 0x80044604: sw          $at, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r1;
    // 0x80044608: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8004460C: nop

    // 0x80044610: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80044614: lhu         $at, 0x4($t5)
    ctx->r1 = MEM_HU(ctx->r13, 0X4);
    // 0x80044618: nop

    // 0x8004461C: sh          $at, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r1;
    // 0x80044620: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80044624: addiu       $t6, $t6, -0x2B28
    ctx->r14 = ADD32(ctx->r14, -0X2B28);
    // 0x80044628: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x8004462C: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_80044630:
    // 0x80044630: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80044634: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80044638: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8004463C: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x80044640: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80044644: sw          $at, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r1;
    // 0x80044648: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8004464C: bne         $t6, $t0, L_80044630
    if (ctx->r14 != ctx->r8) {
        // 0x80044650: sw          $at, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r1;
            goto L_80044630;
    }
    // 0x80044650: sw          $at, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r1;
    // 0x80044654: jal         0x800AF060
    // 0x80044658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x80044658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x8004465C: jal         0x800A41B4
    // 0x80044660: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    func_800A41B4(rdram, ctx);
        goto after_1;
    // 0x80044660: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    after_1:
    // 0x80044664: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044668: addiu       $a1, $a1, -0x2BF0
    ctx->r5 = ADD32(ctx->r5, -0X2BF0);
    // 0x8004466C: jal         0x800A5624
    // 0x80044670: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_2;
    // 0x80044670: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80044674: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x80044678: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8004467C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80044680: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80044684: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    // 0x80044688: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x8004468C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80044690: jal         0x800A57C4
    // 0x80044694: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800A57C4(rdram, ctx);
        goto after_3;
    // 0x80044694: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80044698: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8004469C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800446A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800446A4: swc1        $f4, 0x450($at)
    MEM_W(0X450, ctx->r1) = ctx->f4.u32l;
    // 0x800446A8: addiu       $t8, $zero, 0x640
    ctx->r24 = ADD32(0, 0X640);
    // 0x800446AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800446B0: sw          $t8, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r24;
    // 0x800446B4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800446B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800446BC: sw          $t9, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r25;
    // 0x800446C0: sh          $zero, 0x166($sp)
    MEM_H(0X166, ctx->r29) = 0;
L_800446C4:
    // 0x800446C4: lh          $t5, 0x166($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X166);
    // 0x800446C8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800446CC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800446D0: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x800446D4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800446D8: lw          $t2, -0x73D0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73D0);
    // 0x800446DC: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x800446E0: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x800446E4: addu        $t0, $t4, $t2
    ctx->r8 = ADD32(ctx->r12, ctx->r10);
    // 0x800446E8: lw          $t6, 0xC0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC0);
    // 0x800446EC: nop

    // 0x800446F0: ori         $t7, $t6, 0x8240
    ctx->r15 = ctx->r14 | 0X8240;
    // 0x800446F4: sw          $t7, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r15;
    // 0x800446F8: lh          $t1, 0x166($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X166);
    // 0x800446FC: nop

    // 0x80044700: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80044704: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x80044708: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004470C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80044710: bne         $at, $zero, L_800446C4
    if (ctx->r1 != 0) {
        // 0x80044714: sh          $t3, 0x166($sp)
        MEM_H(0X166, ctx->r29) = ctx->r11;
            goto L_800446C4;
    }
    // 0x80044714: sh          $t3, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r11;
    // 0x80044718: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8004471C: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x80044720: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80044724: lw          $t4, 0xC0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC0);
    // 0x80044728: nop

    // 0x8004472C: and         $t2, $t4, $at
    ctx->r10 = ctx->r12 & ctx->r1;
    // 0x80044730: beq         $t2, $zero, L_8004479C
    if (ctx->r10 == 0) {
        // 0x80044734: nop
    
            goto L_8004479C;
    }
    // 0x80044734: nop

    // 0x80044738: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004473C: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80044740: nop

    // 0x80044744: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x80044748: nop

    // 0x8004474C: ori         $t0, $t7, 0x8240
    ctx->r8 = ctx->r15 | 0X8240;
    // 0x80044750: sw          $t0, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r8;
    // 0x80044754: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80044758: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x8004475C: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80044760: sh          $t1, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r9;
    // 0x80044764: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80044768: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8004476C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80044770: nop

    // 0x80044774: andi        $t5, $t9, 0x200
    ctx->r13 = ctx->r25 & 0X200;
    // 0x80044778: beq         $t5, $zero, L_8004479C
    if (ctx->r13 == 0) {
        // 0x8004477C: nop
    
            goto L_8004479C;
    }
    // 0x8004477C: nop

    // 0x80044780: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80044784: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x80044788: nop

    // 0x8004478C: lw          $t2, 0xC0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC0);
    // 0x80044790: nop

    // 0x80044794: ori         $t7, $t2, 0x80
    ctx->r15 = ctx->r10 | 0X80;
    // 0x80044798: sw          $t7, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r15;
L_8004479C:
    // 0x8004479C: sh          $zero, 0x166($sp)
    MEM_H(0X166, ctx->r29) = 0;
    // 0x800447A0: jal         0x800BC6EC
    // 0x800447A4: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800447A4: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_4:
    // 0x800447A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800447AC: sw          $v0, 0x722C($at)
    MEM_W(0X722C, ctx->r1) = ctx->r2;
    // 0x800447B0: lh          $t0, 0x166($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X166);
    // 0x800447B4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800447B8: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800447BC: addu        $t1, $sp, $t6
    ctx->r9 = ADD32(ctx->r29, ctx->r14);
    // 0x800447C0: lhu         $t1, 0xB4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XB4);
    // 0x800447C4: nop

    // 0x800447C8: beq         $t1, $at, L_80044834
    if (ctx->r9 == ctx->r1) {
        // 0x800447CC: nop
    
            goto L_80044834;
    }
    // 0x800447CC: nop

L_800447D0:
    // 0x800447D0: lh          $t3, 0x166($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X166);
    // 0x800447D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800447D8: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800447DC: addu        $a0, $sp, $t8
    ctx->r4 = ADD32(ctx->r29, ctx->r24);
    // 0x800447E0: lhu         $a0, 0xB4($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XB4);
    // 0x800447E4: jal         0x800AFB70
    // 0x800447E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_5;
    // 0x800447E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800447EC: lh          $t5, 0x166($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X166);
    // 0x800447F0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800447F4: lw          $t9, 0x722C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X722C);
    // 0x800447F8: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x800447FC: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x80044800: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80044804: lh          $t4, 0x166($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X166);
    // 0x80044808: nop

    // 0x8004480C: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x80044810: sh          $t0, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r8;
    // 0x80044814: lh          $t6, 0x166($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X166);
    // 0x80044818: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004481C: sll         $t1, $t6, 1
    ctx->r9 = S32(ctx->r14 << 1);
    // 0x80044820: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x80044824: lhu         $t3, 0xB4($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XB4);
    // 0x80044828: nop

    // 0x8004482C: bne         $t3, $at, L_800447D0
    if (ctx->r11 != ctx->r1) {
        // 0x80044830: nop
    
            goto L_800447D0;
    }
    // 0x80044830: nop

L_80044834:
    // 0x80044834: jal         0x800BC6EC
    // 0x80044838: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x80044838: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_6:
    // 0x8004483C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044840: sw          $v0, 0x7284($at)
    MEM_W(0X7284, ctx->r1) = ctx->r2;
    // 0x80044844: sh          $zero, 0x166($sp)
    MEM_H(0X166, ctx->r29) = 0;
L_80044848:
    // 0x80044848: jal         0x800BC6EC
    // 0x8004484C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x8004484C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_7:
    // 0x80044850: lh          $t5, 0x166($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X166);
    // 0x80044854: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80044858: lw          $t8, 0x7284($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7284);
    // 0x8004485C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80044860: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80044864: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x80044868: lh          $t7, 0x166($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X166);
    // 0x8004486C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80044870: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80044874: addu        $a2, $sp, $t4
    ctx->r6 = ADD32(ctx->r29, ctx->r12);
    // 0x80044878: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8004487C: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80044880: lw          $a2, 0x84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X84);
    // 0x80044884: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80044888: jal         0x800BD1FC
    // 0x8004488C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_8;
    // 0x8004488C: nop

    after_8:
    // 0x80044890: lh          $t6, 0x166($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X166);
    // 0x80044894: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80044898: lw          $t0, 0x7284($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7284);
    // 0x8004489C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x800448A0: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800448A4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800448A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800448AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800448B0: jal         0x800BD218
    // 0x800448B4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    SysMem_DmaCopy(rdram, ctx);
        goto after_9;
    // 0x800448B4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_9:
    // 0x800448B8: lh          $t5, 0x166($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X166);
    // 0x800448BC: nop

    // 0x800448C0: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800448C4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800448C8: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800448CC: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x800448D0: bne         $at, $zero, L_80044848
    if (ctx->r1 != 0) {
        // 0x800448D4: sh          $t8, 0x166($sp)
        MEM_H(0X166, ctx->r29) = ctx->r24;
            goto L_80044848;
    }
    // 0x800448D4: sh          $t8, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r24;
    // 0x800448D8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800448DC: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x800448E0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800448E4: bne         $t7, $at, L_800448F4
    if (ctx->r15 != ctx->r1) {
        // 0x800448E8: nop
    
            goto L_800448F4;
    }
    // 0x800448E8: nop

    // 0x800448EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800448F0: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
L_800448F4:
    // 0x800448F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800448F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800448FC: sb          $t4, -0x69F8($at)
    MEM_B(-0X69F8, ctx->r1) = ctx->r12;
    // 0x80044900: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80044904: sh          $zero, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = 0;
    // 0x80044908: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004490C: sh          $zero, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = 0;
    // 0x80044910: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80044914: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044918: swc1        $f6, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f6.u32l;
    // 0x8004491C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044920: swc1        $f6, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f6.u32l;
    // 0x80044924: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044928: swc1        $f6, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f6.u32l;
    // 0x8004492C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80044930: swc1        $f6, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f6.u32l;
    // 0x80044934: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044938: sb          $zero, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = 0;
    // 0x8004493C: jal         0x800BC6EC
    // 0x80044940: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_10;
    // 0x80044940: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_10:
    // 0x80044944: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044948: sw          $v0, 0x7278($at)
    MEM_W(0X7278, ctx->r1) = ctx->r2;
    // 0x8004494C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80044950: lw          $t0, 0x7278($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7278);
    // 0x80044954: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80044958: sh          $t6, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r14;
    // 0x8004495C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80044960: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x80044964: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80044968: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004496C: swc1        $f8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f8.u32l;
    // 0x80044970: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x80044974: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80044978: lwc1        $f20, 0x18($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8004497C: nop

    // 0x80044980: swc1        $f20, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f20.u32l;
    // 0x80044984: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x80044988: nop

    // 0x8004498C: swc1        $f20, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f20.u32l;
    // 0x80044990: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80044994: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x80044998: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004499C: bne         $t8, $at, L_80044A04
    if (ctx->r24 != ctx->r1) {
        // 0x800449A0: nop
    
            goto L_80044A04;
    }
    // 0x800449A0: nop

    // 0x800449A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800449A8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800449AC: lw          $t9, 0x7278($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7278);
    // 0x800449B0: lwc1        $f10, -0x1180($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1180);
    // 0x800449B4: nop

    // 0x800449B8: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800449BC: lui         $at, 0x43A2
    ctx->r1 = S32(0X43A2 << 16);
    // 0x800449C0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800449C4: lw          $t2, 0x7278($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7278);
    // 0x800449C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800449CC: nop

    // 0x800449D0: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
    // 0x800449D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800449D8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800449DC: lw          $t7, 0x7278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7278);
    // 0x800449E0: lwc1        $f18, -0x117C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X117C);
    // 0x800449E4: nop

    // 0x800449E8: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
    // 0x800449EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800449F0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800449F4: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x800449F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800449FC: b           L_80044A74
    // 0x80044A00: swc1        $f4, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f4.u32l;
        goto L_80044A74;
    // 0x80044A00: swc1        $f4, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f4.u32l;
L_80044A04:
    // 0x80044A04: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80044A08: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80044A0C: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x80044A10: lwc1        $f6, -0x1178($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1178);
    // 0x80044A14: nop

    // 0x80044A18: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80044A1C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80044A20: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80044A24: lw          $t0, 0x7278($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7278);
    // 0x80044A28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044A2C: nop

    // 0x80044A30: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
    // 0x80044A34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80044A38: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80044A3C: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x80044A40: lwc1        $f10, -0x1174($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1174);
    // 0x80044A44: nop

    // 0x80044A48: swc1        $f10, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f10.u32l;
    // 0x80044A4C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80044A50: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80044A54: lw          $t3, 0x7278($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7278);
    // 0x80044A58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80044A5C: nop

    // 0x80044A60: swc1        $f16, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f16.u32l;
    // 0x80044A64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80044A68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80044A6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044A70: swc1        $f18, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f18.u32l;
L_80044A74:
    // 0x80044A74: jal         0x800BC6EC
    // 0x80044A78: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x80044A78: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_11:
    // 0x80044A7C: sw          $v0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r2;
    // 0x80044A80: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x80044A84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044A88: sw          $t5, 0x7214($at)
    MEM_W(0X7214, ctx->r1) = ctx->r13;
    // 0x80044A8C: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x80044A90: nop

    // 0x80044A94: sh          $zero, 0x2($t8)
    MEM_H(0X2, ctx->r24) = 0;
    // 0x80044A98: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x80044A9C: nop

    // 0x80044AA0: lhu         $t2, 0x2($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X2);
    // 0x80044AA4: nop

    // 0x80044AA8: sh          $t2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r10;
    // 0x80044AAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80044AB0: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x80044AB4: nop

    // 0x80044AB8: swc1        $f4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f4.u32l;
    // 0x80044ABC: lui         $a0, 0x80A4
    ctx->r4 = S32(0X80A4 << 16);
    // 0x80044AC0: jal         0x800AF92C
    // 0x80044AC4: addiu       $a0, $a0, -0x40AC
    ctx->r4 = ADD32(ctx->r4, -0X40AC);
    func_800AF92C(rdram, ctx);
        goto after_12;
    // 0x80044AC4: addiu       $a0, $a0, -0x40AC
    ctx->r4 = ADD32(ctx->r4, -0X40AC);
    after_12:
    // 0x80044AC8: lui         $a0, 0x80A4
    ctx->r4 = S32(0X80A4 << 16);
    // 0x80044ACC: jal         0x800AF72C
    // 0x80044AD0: addiu       $a0, $a0, -0x432C
    ctx->r4 = ADD32(ctx->r4, -0X432C);
    func_800AF72C(rdram, ctx);
        goto after_13;
    // 0x80044AD0: addiu       $a0, $a0, -0x432C
    ctx->r4 = ADD32(ctx->r4, -0X432C);
    after_13:
    // 0x80044AD4: jal         0x800BC6EC
    // 0x80044AD8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_14;
    // 0x80044AD8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_14:
    // 0x80044ADC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044AE0: sw          $v0, 0x71FC($at)
    MEM_W(0X71FC, ctx->r1) = ctx->r2;
    // 0x80044AE4: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80044AE8: sh          $t4, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r12;
    // 0x80044AEC: jal         0x800BC6EC
    // 0x80044AF0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_15;
    // 0x80044AF0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_15:
    // 0x80044AF4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80044AF8: lw          $t6, 0x71FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71FC);
    // 0x80044AFC: nop

    // 0x80044B00: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80044B04: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80044B08: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80044B0C: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80044B10: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80044B14: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x80044B18: jal         0x800BD1FC
    // 0x80044B1C: addiu       $a2, $a2, -0x3CF0
    ctx->r6 = ADD32(ctx->r6, -0X3CF0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_16;
    // 0x80044B1C: addiu       $a2, $a2, -0x3CF0
    ctx->r6 = ADD32(ctx->r6, -0X3CF0);
    after_16:
    // 0x80044B20: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80044B24: lw          $t0, 0x71FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X71FC);
    // 0x80044B28: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80044B2C: lh          $a2, 0x166($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X166);
    // 0x80044B30: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80044B34: jal         0x800BD218
    // 0x80044B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_17;
    // 0x80044B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80044B3C: jal         0x800BC6EC
    // 0x80044B40: addiu       $a0, $zero, 0x6400
    ctx->r4 = ADD32(0, 0X6400);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_18;
    // 0x80044B40: addiu       $a0, $zero, 0x6400
    ctx->r4 = ADD32(0, 0X6400);
    after_18:
    // 0x80044B44: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80044B48: lw          $t1, 0x71FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X71FC);
    // 0x80044B4C: nop

    // 0x80044B50: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x80044B54: jal         0x800BC6EC
    // 0x80044B58: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_19;
    // 0x80044B58: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_19:
    // 0x80044B5C: sw          $v0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r2;
    // 0x80044B60: sh          $zero, 0x166($sp)
    MEM_H(0X166, ctx->r29) = 0;
L_80044B64:
    // 0x80044B64: lh          $t3, 0x166($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X166);
    // 0x80044B68: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80044B6C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80044B70: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x80044B74: lw          $t8, -0x2F0C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2F0C);
    // 0x80044B78: nop

    // 0x80044B7C: sw          $t8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r24;
    // 0x80044B80: lh          $t7, 0x166($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X166);
    // 0x80044B84: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80044B88: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80044B8C: lw          $t2, 0x71FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71FC);
    // 0x80044B90: subu        $t4, $t4, $t7
    ctx->r12 = SUB32(ctx->r12, ctx->r15);
    // 0x80044B94: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80044B98: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80044B9C: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x80044BA0: sll         $t4, $t4, 7
    ctx->r12 = S32(ctx->r12 << 7);
    // 0x80044BA4: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x80044BA8: sw          $t6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r14;
    // 0x80044BAC: sh          $zero, 0x164($sp)
    MEM_H(0X164, ctx->r29) = 0;
L_80044BB0:
    // 0x80044BB0: sh          $zero, 0x162($sp)
    MEM_H(0X162, ctx->r29) = 0;
L_80044BB4:
    // 0x80044BB4: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x80044BB8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80044BBC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80044BC0: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80044BC4: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80044BC8: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80044BCC: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x80044BD0: jal         0x800BD1FC
    // 0x80044BD4: sw          $t1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r9;
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_20;
    // 0x80044BD4: sw          $t1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r9;
    after_20:
    // 0x80044BD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80044BDC: lw          $a1, 0x15C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X15C);
    // 0x80044BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80044BE4: jal         0x800BD218
    // 0x80044BE8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    SysMem_DmaCopy(rdram, ctx);
        goto after_21;
    // 0x80044BE8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_21:
    // 0x80044BEC: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80044BF0: nop

    // 0x80044BF4: sw          $t3, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r11;
    // 0x80044BF8: sh          $zero, 0x160($sp)
    MEM_H(0X160, ctx->r29) = 0;
L_80044BFC:
    // 0x80044BFC: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x80044C00: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x80044C04: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80044C08: nop

    // 0x80044C0C: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x80044C10: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x80044C14: nop

    // 0x80044C18: addiu       $t9, $t7, 0x2
    ctx->r25 = ADD32(ctx->r15, 0X2);
    // 0x80044C1C: sw          $t9, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r25;
    // 0x80044C20: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x80044C24: nop

    // 0x80044C28: addiu       $t6, $t4, 0x14
    ctx->r14 = ADD32(ctx->r12, 0X14);
    // 0x80044C2C: sw          $t6, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r14;
    // 0x80044C30: lh          $t0, 0x160($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X160);
    // 0x80044C34: nop

    // 0x80044C38: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80044C3C: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x80044C40: sra         $t5, $t3, 16
    ctx->r13 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80044C44: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x80044C48: bne         $at, $zero, L_80044BFC
    if (ctx->r1 != 0) {
        // 0x80044C4C: sh          $t1, 0x160($sp)
        MEM_H(0X160, ctx->r29) = ctx->r9;
            goto L_80044BFC;
    }
    // 0x80044C4C: sh          $t1, 0x160($sp)
    MEM_H(0X160, ctx->r29) = ctx->r9;
    // 0x80044C50: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x80044C54: nop

    // 0x80044C58: addiu       $t2, $t8, -0x13E
    ctx->r10 = ADD32(ctx->r24, -0X13E);
    // 0x80044C5C: sw          $t2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r10;
    // 0x80044C60: lh          $t7, 0x162($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X162);
    // 0x80044C64: nop

    // 0x80044C68: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80044C6C: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x80044C70: sra         $t6, $t4, 16
    ctx->r14 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80044C74: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80044C78: bne         $at, $zero, L_80044BB4
    if (ctx->r1 != 0) {
        // 0x80044C7C: sh          $t9, 0x162($sp)
        MEM_H(0X162, ctx->r29) = ctx->r25;
            goto L_80044BB4;
    }
    // 0x80044C7C: sh          $t9, 0x162($sp)
    MEM_H(0X162, ctx->r29) = ctx->r25;
    // 0x80044C80: lw          $t0, 0x158($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X158);
    // 0x80044C84: nop

    // 0x80044C88: addiu       $t1, $t0, 0x12C
    ctx->r9 = ADD32(ctx->r8, 0X12C);
    // 0x80044C8C: sw          $t1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r9;
    // 0x80044C90: lh          $t3, 0x164($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X164);
    // 0x80044C94: nop

    // 0x80044C98: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80044C9C: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x80044CA0: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80044CA4: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x80044CA8: bne         $at, $zero, L_80044BB0
    if (ctx->r1 != 0) {
        // 0x80044CAC: sh          $t5, 0x164($sp)
        MEM_H(0X164, ctx->r29) = ctx->r13;
            goto L_80044BB0;
    }
    // 0x80044CAC: sh          $t5, 0x164($sp)
    MEM_H(0X164, ctx->r29) = ctx->r13;
    // 0x80044CB0: lh          $t7, 0x166($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X166);
    // 0x80044CB4: nop

    // 0x80044CB8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80044CBC: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x80044CC0: sra         $t6, $t4, 16
    ctx->r14 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80044CC4: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80044CC8: bne         $at, $zero, L_80044B64
    if (ctx->r1 != 0) {
        // 0x80044CCC: sh          $t9, 0x166($sp)
        MEM_H(0X166, ctx->r29) = ctx->r25;
            goto L_80044B64;
    }
    // 0x80044CCC: sh          $t9, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r25;
    // 0x80044CD0: lw          $a0, 0x15C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X15C);
    // 0x80044CD4: jal         0x800BC980
    // 0x80044CD8: nop

    SysMem_Free(rdram, ctx);
        goto after_22;
    // 0x80044CD8: nop

    after_22:
    // 0x80044CDC: jal         0x800BC6EC
    // 0x80044CE0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_23;
    // 0x80044CE0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_23:
    // 0x80044CE4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044CE8: sw          $v0, 0x72A4($at)
    MEM_W(0X72A4, ctx->r1) = ctx->r2;
    // 0x80044CEC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80044CF0: lw          $a0, 0x72A4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72A4);
    // 0x80044CF4: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    // 0x80044CF8: jal         0x80048C30
    // 0x80044CFC: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    func_80048C30(rdram, ctx);
        goto after_24;
    // 0x80044CFC: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_24:
    // 0x80044D00: jal         0x800BC6EC
    // 0x80044D04: addiu       $a0, $zero, 0x460
    ctx->r4 = ADD32(0, 0X460);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_25;
    // 0x80044D04: addiu       $a0, $zero, 0x460
    ctx->r4 = ADD32(0, 0X460);
    after_25:
    // 0x80044D08: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044D0C: sw          $v0, 0x72C8($at)
    MEM_W(0X72C8, ctx->r1) = ctx->r2;
    // 0x80044D10: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80044D14: lw          $t0, 0x72C8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X72C8);
    // 0x80044D18: nop

    // 0x80044D1C: sw          $t0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r8;
    // 0x80044D20: sh          $zero, 0x166($sp)
    MEM_H(0X166, ctx->r29) = 0;
L_80044D24:
    // 0x80044D24: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80044D28: lw          $t1, 0x722C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X722C);
    // 0x80044D2C: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    // 0x80044D30: lw          $a1, 0x14($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X14);
    // 0x80044D34: jal         0x800A424C
    // 0x80044D38: nop

    func_800A424C(rdram, ctx);
        goto after_26;
    // 0x80044D38: nop

    after_26:
    // 0x80044D3C: lw          $t5, 0x13C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X13C);
    // 0x80044D40: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80044D44: sh          $t3, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r11;
    // 0x80044D48: lw          $t8, 0x13C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X13C);
    // 0x80044D4C: nop

    // 0x80044D50: lw          $t2, 0xC0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0XC0);
    // 0x80044D54: nop

    // 0x80044D58: ori         $t7, $t2, 0x2000
    ctx->r15 = ctx->r10 | 0X2000;
    // 0x80044D5C: sw          $t7, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r15;
    // 0x80044D60: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80044D64: lw          $t9, 0x72C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72C8);
    // 0x80044D68: nop

    // 0x80044D6C: lw          $t4, 0xC0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XC0);
    // 0x80044D70: nop

    // 0x80044D74: ori         $t6, $t4, 0x200
    ctx->r14 = ctx->r12 | 0X200;
    // 0x80044D78: sw          $t6, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r14;
    // 0x80044D7C: lw          $t0, 0x13C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X13C);
    // 0x80044D80: nop

    // 0x80044D84: addiu       $t1, $t0, 0x118
    ctx->r9 = ADD32(ctx->r8, 0X118);
    // 0x80044D88: sw          $t1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r9;
    // 0x80044D8C: lh          $t3, 0x166($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X166);
    // 0x80044D90: nop

    // 0x80044D94: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80044D98: sll         $t2, $t5, 16
    ctx->r10 = S32(ctx->r13 << 16);
    // 0x80044D9C: sra         $t7, $t2, 16
    ctx->r15 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80044DA0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80044DA4: bne         $at, $zero, L_80044D24
    if (ctx->r1 != 0) {
        // 0x80044DA8: sh          $t5, 0x166($sp)
        MEM_H(0X166, ctx->r29) = ctx->r13;
            goto L_80044D24;
    }
    // 0x80044DA8: sh          $t5, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r13;
    // 0x80044DAC: jal         0x800BC6EC
    // 0x80044DB0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_27;
    // 0x80044DB0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_27:
    // 0x80044DB4: sw          $v0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r2;
    // 0x80044DB8: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x80044DBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044DC0: sw          $t8, 0x7260($at)
    MEM_W(0X7260, ctx->r1) = ctx->r24;
    // 0x80044DC4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80044DC8: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x80044DCC: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x80044DD0: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80044DD4: nop

    // 0x80044DD8: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80044DDC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80044DE0: lw          $t9, 0x7278($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7278);
    // 0x80044DE4: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x80044DE8: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80044DEC: nop

    // 0x80044DF0: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
    // 0x80044DF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80044DF8: lw          $t1, 0x140($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X140);
    // 0x80044DFC: nop

    // 0x80044E00: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x80044E04: lw          $t3, 0x140($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X140);
    // 0x80044E08: nop

    // 0x80044E0C: lwc1        $f16, 0xC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80044E10: nop

    // 0x80044E14: swc1        $f16, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f16.u32l;
    // 0x80044E18: jal         0x800BC6EC
    // 0x80044E1C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_28;
    // 0x80044E1C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_28:
    // 0x80044E20: sw          $v0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r2;
    // 0x80044E24: lw          $t5, 0x148($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X148);
    // 0x80044E28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044E2C: sw          $t5, 0x7220($at)
    MEM_W(0X7220, ctx->r1) = ctx->r13;
    // 0x80044E30: addiu       $t2, $sp, 0xEC
    ctx->r10 = ADD32(ctx->r29, 0XEC);
    // 0x80044E34: sw          $t2, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r10;
    // 0x80044E38: sh          $zero, 0x166($sp)
    MEM_H(0X166, ctx->r29) = 0;
L_80044E3C:
    // 0x80044E3C: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x80044E40: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x80044E44: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80044E48: nop

    // 0x80044E4C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80044E50: nop

    // 0x80044E54: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80044E58: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x80044E5C: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x80044E60: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x80044E64: lh          $t9, 0x2($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X2);
    // 0x80044E68: nop

    // 0x80044E6C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80044E70: nop

    // 0x80044E74: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80044E78: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
    // 0x80044E7C: lw          $t1, 0x144($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X144);
    // 0x80044E80: lw          $t5, 0x148($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X148);
    // 0x80044E84: lh          $t3, 0x4($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X4);
    // 0x80044E88: nop

    // 0x80044E8C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80044E90: nop

    // 0x80044E94: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80044E98: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
    // 0x80044E9C: lw          $t2, 0x144($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X144);
    // 0x80044EA0: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x80044EA4: lh          $t7, 0x6($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X6);
    // 0x80044EA8: nop

    // 0x80044EAC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80044EB0: nop

    // 0x80044EB4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80044EB8: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x80044EBC: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x80044EC0: nop

    // 0x80044EC4: addiu       $t6, $t4, 0x10
    ctx->r14 = ADD32(ctx->r12, 0X10);
    // 0x80044EC8: sw          $t6, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r14;
    // 0x80044ECC: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x80044ED0: nop

    // 0x80044ED4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80044ED8: sw          $t0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r8;
    // 0x80044EDC: lh          $t1, 0x166($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X166);
    // 0x80044EE0: nop

    // 0x80044EE4: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80044EE8: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x80044EEC: sra         $t2, $t5, 16
    ctx->r10 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80044EF0: slti        $at, $t2, 0x7
    ctx->r1 = SIGNED(ctx->r10) < 0X7 ? 1 : 0;
    // 0x80044EF4: bne         $at, $zero, L_80044E3C
    if (ctx->r1 != 0) {
        // 0x80044EF8: sh          $t3, 0x166($sp)
        MEM_H(0X166, ctx->r29) = ctx->r11;
            goto L_80044E3C;
    }
    // 0x80044EF8: sh          $t3, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r11;
    // 0x80044EFC: jal         0x800BC6EC
    // 0x80044F00: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_29;
    // 0x80044F00: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    after_29:
    // 0x80044F04: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    // 0x80044F08: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x80044F0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044F10: sw          $t7, 0x726C($at)
    MEM_W(0X726C, ctx->r1) = ctx->r15;
    // 0x80044F14: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x80044F18: nop

    // 0x80044F1C: sb          $zero, 0x1C9($t8)
    MEM_B(0X1C9, ctx->r24) = 0;
    // 0x80044F20: lw          $t4, 0x138($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X138);
    // 0x80044F24: nop

    // 0x80044F28: lbu         $t6, 0x1C9($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X1C9);
    // 0x80044F2C: nop

    // 0x80044F30: sb          $t6, 0x1C8($t4)
    MEM_B(0X1C8, ctx->r12) = ctx->r14;
    // 0x80044F34: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x80044F38: nop

    // 0x80044F3C: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80044F40: sw          $t0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r8;
    // 0x80044F44: sh          $zero, 0x166($sp)
    MEM_H(0X166, ctx->r29) = 0;
L_80044F48:
    // 0x80044F48: lh          $t3, 0x166($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X166);
    // 0x80044F4C: lw          $t1, 0x128($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X128);
    // 0x80044F50: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80044F54: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80044F58: addu        $t2, $t1, $t5
    ctx->r10 = ADD32(ctx->r9, ctx->r13);
    // 0x80044F5C: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80044F60: lh          $t7, 0x166($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X166);
    // 0x80044F64: nop

    // 0x80044F68: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80044F6C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80044F70: sra         $t4, $t6, 16
    ctx->r12 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80044F74: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80044F78: bne         $at, $zero, L_80044F48
    if (ctx->r1 != 0) {
        // 0x80044F7C: sh          $t8, 0x166($sp)
        MEM_H(0X166, ctx->r29) = ctx->r24;
            goto L_80044F48;
    }
    // 0x80044F7C: sh          $t8, 0x166($sp)
    MEM_H(0X166, ctx->r29) = ctx->r24;
    // 0x80044F80: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x80044F84: nop

    // 0x80044F88: addiu       $t0, $t9, 0x28
    ctx->r8 = ADD32(ctx->r25, 0X28);
    // 0x80044F8C: sw          $t0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r8;
    // 0x80044F90: jal         0x80099E2C
    // 0x80044F94: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80099E2C(rdram, ctx);
        goto after_30;
    // 0x80044F94: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_30:
    // 0x80044F98: lw          $a1, 0x138($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X138);
    // 0x80044F9C: lw          $a0, 0x134($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X134);
    // 0x80044FA0: jal         0x800B1B04
    // 0x80044FA4: addiu       $a1, $a1, 0x188
    ctx->r5 = ADD32(ctx->r5, 0X188);
    func_800B1B04(rdram, ctx);
        goto after_31;
    // 0x80044FA4: addiu       $a1, $a1, 0x188
    ctx->r5 = ADD32(ctx->r5, 0X188);
    after_31:
    // 0x80044FA8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80044FAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044FB0: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x80044FB4: nop

    // 0x80044FB8: swc1        $f8, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->f8.u32l;
    // 0x80044FBC: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x80044FC0: lui         $t1, 0x4
    ctx->r9 = S32(0X4 << 16);
    // 0x80044FC4: ori         $t1, $t1, 0x4
    ctx->r9 = ctx->r9 | 0X4;
    // 0x80044FC8: sw          $t1, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r9;
    // 0x80044FCC: lw          $t7, 0x134($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X134);
    // 0x80044FD0: addiu       $t2, $zero, 0x5A
    ctx->r10 = ADD32(0, 0X5A);
    // 0x80044FD4: sw          $t2, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r10;
    // 0x80044FD8: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x80044FDC: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80044FE0: sh          $t8, 0xC4($t6)
    MEM_H(0XC4, ctx->r14) = ctx->r24;
    // 0x80044FE4: jal         0x800BC6EC
    // 0x80044FE8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_32;
    // 0x80044FE8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_32:
    // 0x80044FEC: sw          $v0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r2;
    // 0x80044FF0: lw          $t4, 0x12C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X12C);
    // 0x80044FF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80044FF8: sw          $t4, 0x7298($at)
    MEM_W(0X7298, ctx->r1) = ctx->r12;
    // 0x80044FFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80045000: lw          $t9, 0x12C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X12C);
    // 0x80045004: nop

    // 0x80045008: swc1        $f10, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f10.u32l;
    // 0x8004500C: lw          $t0, 0x12C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X12C);
    // 0x80045010: nop

    // 0x80045014: lwc1        $f16, 0x18($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80045018: nop

    // 0x8004501C: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x80045020: swc1        $f16, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f16.u32l;
    // 0x80045024: lw          $t3, 0x12C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X12C);
    // 0x80045028: lwc1        $f30, 0x64($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8004502C: nop

    // 0x80045030: swc1        $f30, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f30.u32l;
    // 0x80045034: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x80045038: mov.s       $f28, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    ctx->f28.fl = ctx->f30.fl;
    // 0x8004503C: swc1        $f28, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f28.u32l;
    // 0x80045040: lw          $t5, 0x12C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X12C);
    // 0x80045044: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x80045048: swc1        $f26, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f26.u32l;
    // 0x8004504C: lw          $t2, 0x12C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X12C);
    // 0x80045050: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x80045054: swc1        $f24, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f24.u32l;
    // 0x80045058: lw          $t7, 0x12C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X12C);
    // 0x8004505C: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80045060: swc1        $f22, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f22.u32l;
    // 0x80045064: lw          $t8, 0x12C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X12C);
    // 0x80045068: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8004506C: swc1        $f20, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f20.u32l;
    // 0x80045070: lw          $t6, 0x12C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X12C);
    // 0x80045074: nop

    // 0x80045078: swc1        $f20, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f20.u32l;
    // 0x8004507C: lw          $t4, 0x12C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X12C);
    // 0x80045080: nop

    // 0x80045084: sb          $zero, 0x2D($t4)
    MEM_B(0X2D, ctx->r12) = 0;
    // 0x80045088: jal         0x80044444
    // 0x8004508C: nop

    func_80044444(rdram, ctx);
        goto after_33;
    // 0x8004508C: nop

    after_33:
    // 0x80045090: jal         0x800BC6EC
    // 0x80045094: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_34;
    // 0x80045094: addiu       $a0, $zero, 0x1B0
    ctx->r4 = ADD32(0, 0X1B0);
    after_34:
    // 0x80045098: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x8004509C: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800450A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800450A4: sw          $t9, 0x103C($at)
    MEM_W(0X103C, ctx->r1) = ctx->r25;
    // 0x800450A8: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x800450AC: nop

    // 0x800450B0: sb          $zero, 0x1A8($t0)
    MEM_B(0X1A8, ctx->r8) = 0;
    // 0x800450B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800450B8: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x800450BC: nop

    // 0x800450C0: swc1        $f18, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f18.u32l;
    // 0x800450C4: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800450C8: nop

    // 0x800450CC: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x800450D0: sw          $t5, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r13;
    // 0x800450D4: jal         0x80099E2C
    // 0x800450D8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80099E2C(rdram, ctx);
        goto after_35;
    // 0x800450D8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_35:
    // 0x800450DC: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x800450E0: lw          $a0, 0x134($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X134);
    // 0x800450E4: addiu       $t7, $t2, 0x168
    ctx->r15 = ADD32(ctx->r10, 0X168);
    // 0x800450E8: sw          $t7, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r15;
    // 0x800450EC: jal         0x800B1B04
    // 0x800450F0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_800B1B04(rdram, ctx);
        goto after_36;
    // 0x800450F0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_36:
    // 0x800450F4: lw          $t6, 0x134($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X134);
    // 0x800450F8: ori         $t8, $zero, 0x8214
    ctx->r24 = 0 | 0X8214;
    // 0x800450FC: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x80045100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80045104: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80045108: lw          $a0, 0x134($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X134);
    // 0x8004510C: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80045110: lui         $a2, 0xAE
    ctx->r6 = S32(0XAE << 16);
    // 0x80045114: ori         $a2, $a2, 0x251
    ctx->r6 = ctx->r6 | 0X251;
    // 0x80045118: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x8004511C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80045120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80045124: jal         0x800B1F0C
    // 0x80045128: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_37;
    // 0x80045128: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_37:
    // 0x8004512C: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x80045130: addiu       $t4, $zero, 0x7FFF
    ctx->r12 = ADD32(0, 0X7FFF);
    // 0x80045134: sw          $t4, 0xC8($t9)
    MEM_W(0XC8, ctx->r25) = ctx->r12;
    // 0x80045138: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x8004513C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80045140: sh          $t0, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r8;
    // 0x80045144: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x80045148: nop

    // 0x8004514C: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x80045150: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x80045154: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80045158: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x8004515C: nop

    // 0x80045160: swc1        $f8, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f8.u32l;
    // 0x80045164: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x80045168: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004516C: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x80045170: nop

    // 0x80045174: swc1        $f10, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f10.u32l;
    // 0x80045178: b           L_80045180
    // 0x8004517C: nop

        goto L_80045180;
    // 0x8004517C: nop

L_80045180:
    // 0x80045180: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80045184: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80045188: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004518C: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80045190: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80045194: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80045198: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004519C: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x800451A0: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800451A4: lwc1        $f29, 0x48($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x800451A8: lwc1        $f28, 0x4C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800451AC: lwc1        $f31, 0x50($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x800451B0: lwc1        $f30, 0x54($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800451B4: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800451B8: jr          $ra
    // 0x800451BC: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
    return;
    // 0x800451BC: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
;}
