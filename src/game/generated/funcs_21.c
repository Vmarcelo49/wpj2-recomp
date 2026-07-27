#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8006BA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BA64: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BA68: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BA6C: nop

    // 0x8006BA70: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BA74: nop

    // 0x8006BA78: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006BA7C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BA80: jr          $ra
    // 0x8006BA84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BA84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BA88: jr          $ra
    // 0x8006BA8C: nop

    return;
    // 0x8006BA8C: nop

    // 0x8006BA90: jr          $ra
    // 0x8006BA94: nop

    return;
    // 0x8006BA94: nop

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
RECOMP_FUNC void func_80076CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076CA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076CAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076CB0: nop

    // 0x80076CB4: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80076CB8: nop

    // 0x80076CBC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80076CC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076CC4: jr          $ra
    // 0x80076CC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076CC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076CCC: jr          $ra
    // 0x80076CD0: nop

    return;
    // 0x80076CD0: nop

    // 0x80076CD4: jr          $ra
    // 0x80076CD8: nop

    return;
    // 0x80076CD8: nop

;}
RECOMP_FUNC void func_8006CD1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CD20: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CD24: nop

    // 0x8006CD28: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x8006CD2C: nop

    // 0x8006CD30: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CD34: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CD38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CD3C: bne         $v0, $zero, L_8006CD58
    if (ctx->r2 != 0) {
        // 0x8006CD40: nop
    
            goto L_8006CD58;
    }
    // 0x8006CD40: nop

    // 0x8006CD44: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8006CD48: nop

    // 0x8006CD4C: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CD50: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006CD54: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CD58:
    // 0x8006CD58: jr          $ra
    // 0x8006CD5C: nop

    return;
    // 0x8006CD5C: nop

    // 0x8006CD60: jr          $ra
    // 0x8006CD64: nop

    return;
    // 0x8006CD64: nop

    // 0x8006CD68: jr          $ra
    // 0x8006CD6C: nop

    return;
    // 0x8006CD6C: nop

;}
RECOMP_FUNC void func_80075A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075A3C: jal         0x80061348
    // 0x80075A40: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075A40: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x80075A44: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075A48: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075A4C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075A50: beq         $v0, $zero, L_80075AA4
    if (ctx->r2 == 0) {
        // 0x80075A54: nop
    
            goto L_80075AA4;
    }
    // 0x80075A54: nop

    // 0x80075A58: jal         0x80061348
    // 0x80075A5C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075A5C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075A60: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075A64: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075A68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075A6C: beq         $v0, $zero, L_80075AA4
    if (ctx->r2 == 0) {
        // 0x80075A70: nop
    
            goto L_80075AA4;
    }
    // 0x80075A70: nop

    // 0x80075A74: jal         0x80061348
    // 0x80075A78: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075A78: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x80075A7C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075A80: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075A84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075A88: beq         $v0, $zero, L_80075AA4
    if (ctx->r2 == 0) {
        // 0x80075A8C: nop
    
            goto L_80075AA4;
    }
    // 0x80075A8C: nop

    // 0x80075A90: jal         0x80061348
    // 0x80075A94: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075A94: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075A98: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075A9C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075AA0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075AA4:
    // 0x80075AA4: b           L_80075AB4
    // 0x80075AA8: nop

        goto L_80075AB4;
    // 0x80075AA8: nop

    // 0x80075AAC: b           L_80075AB4
    // 0x80075AB0: nop

        goto L_80075AB4;
    // 0x80075AB0: nop

L_80075AB4:
    // 0x80075AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075AB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075ABC: jr          $ra
    // 0x80075AC0: nop

    return;
    // 0x80075AC0: nop

;}
RECOMP_FUNC void func_80005758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005758: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000575C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80005760: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80005764:
    // 0x80005764: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80005768: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000576C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80005770: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80005774: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80005778: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8000577C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80005780: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80005784: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80005788: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x8000578C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80005790: nop

    // 0x80005794: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x80005798: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8000579C: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800057A0: nop

    // 0x800057A4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800057A8: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800057AC: bne         $at, $zero, L_80005764
    if (ctx->r1 != 0) {
        // 0x800057B0: sw          $t4, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r12;
            goto L_80005764;
    }
    // 0x800057B0: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x800057B4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800057B8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800057BC: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800057C0: bne         $t7, $zero, L_800057D0
    if (ctx->r15 != 0) {
        // 0x800057C4: nop
    
            goto L_800057D0;
    }
    // 0x800057C4: nop

    // 0x800057C8: b           L_800057E0
    // 0x800057CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800057E0;
    // 0x800057CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800057D0:
    // 0x800057D0: b           L_800057E0
    // 0x800057D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800057E0;
    // 0x800057D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800057D8: b           L_800057E0
    // 0x800057DC: nop

        goto L_800057E0;
    // 0x800057DC: nop

L_800057E0:
    // 0x800057E0: jr          $ra
    // 0x800057E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800057E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800779D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800779D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800779D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800779DC: nop

    // 0x800779E0: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x800779E4: nop

    // 0x800779E8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800779EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800779F0: jr          $ra
    // 0x800779F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800779F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800779F8: jr          $ra
    // 0x800779FC: nop

    return;
    // 0x800779FC: nop

    // 0x80077A00: jr          $ra
    // 0x80077A04: nop

    return;
    // 0x80077A04: nop

;}
RECOMP_FUNC void func_80075258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007525C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075260: jal         0x80061348
    // 0x80075264: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075264: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x80075268: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007526C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075274: beq         $v0, $zero, L_800752C8
    if (ctx->r2 == 0) {
        // 0x80075278: nop
    
            goto L_800752C8;
    }
    // 0x80075278: nop

    // 0x8007527C: jal         0x80061348
    // 0x80075280: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075280: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80075284: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075288: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007528C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075290: beq         $v0, $zero, L_800752C8
    if (ctx->r2 == 0) {
        // 0x80075294: nop
    
            goto L_800752C8;
    }
    // 0x80075294: nop

    // 0x80075298: jal         0x80061348
    // 0x8007529C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007529C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x800752A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800752A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800752A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800752AC: beq         $v0, $zero, L_800752C8
    if (ctx->r2 == 0) {
        // 0x800752B0: nop
    
            goto L_800752C8;
    }
    // 0x800752B0: nop

    // 0x800752B4: jal         0x80061348
    // 0x800752B8: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800752B8: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x800752BC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800752C0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800752C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800752C8:
    // 0x800752C8: b           L_800752D8
    // 0x800752CC: nop

        goto L_800752D8;
    // 0x800752CC: nop

    // 0x800752D0: b           L_800752D8
    // 0x800752D4: nop

        goto L_800752D8;
    // 0x800752D4: nop

L_800752D8:
    // 0x800752D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800752DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800752E0: jr          $ra
    // 0x800752E4: nop

    return;
    // 0x800752E4: nop

;}
RECOMP_FUNC void func_8002A22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A22C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002A230: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002A234: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002A238: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002A23C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002A240: bgtz        $a1, L_8002A258
    if (SIGNED(ctx->r5) > 0) {
        // 0x8002A244: nop
    
            goto L_8002A258;
    }
    // 0x8002A244: nop

    // 0x8002A248: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8002A24C: lw          $v0, 0x3074($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3074);
    // 0x8002A250: b           L_8002A394
    // 0x8002A254: nop

        goto L_8002A394;
    // 0x8002A254: nop

L_8002A258:
    // 0x8002A258: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002A25C: lw          $t6, 0x3074($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3074);
    // 0x8002A260: nop

    // 0x8002A264: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8002A268: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002A26C: lw          $t7, 0x3074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3074);
    // 0x8002A270: nop

    // 0x8002A274: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8002A278: nop

    // 0x8002A27C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8002A280: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8002A284: nop

    // 0x8002A288: sh          $t9, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r25;
    // 0x8002A28C: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x8002A290: nop

    // 0x8002A294: beq         $t0, $zero, L_8002A368
    if (ctx->r8 == 0) {
        // 0x8002A298: nop
    
            goto L_8002A368;
    }
    // 0x8002A298: nop

L_8002A29C:
    // 0x8002A29C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8002A2A0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002A2A4: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8002A2A8: nop

    // 0x8002A2AC: bne         $t2, $at, L_8002A2C4
    if (ctx->r10 != ctx->r1) {
        // 0x8002A2B0: nop
    
            goto L_8002A2C4;
    }
    // 0x8002A2B0: nop

    // 0x8002A2B4: lh          $t3, 0x4($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X4);
    // 0x8002A2B8: nop

    // 0x8002A2BC: beq         $t3, $zero, L_8002A2CC
    if (ctx->r11 == 0) {
        // 0x8002A2C0: nop
    
            goto L_8002A2CC;
    }
    // 0x8002A2C0: nop

L_8002A2C4:
    // 0x8002A2C4: b           L_8002A368
    // 0x8002A2C8: nop

        goto L_8002A368;
    // 0x8002A2C8: nop

L_8002A2CC:
    // 0x8002A2CC: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8002A2D0: lh          $t4, 0xE($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XE);
    // 0x8002A2D4: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8002A2D8: nop

    // 0x8002A2DC: beq         $t4, $t6, L_8002A31C
    if (ctx->r12 == ctx->r14) {
        // 0x8002A2E0: nop
    
            goto L_8002A31C;
    }
    // 0x8002A2E0: nop

    // 0x8002A2E4: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8002A2E8: nop

    // 0x8002A2EC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002A2F0: nop

    // 0x8002A2F4: sh          $t8, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r24;
    // 0x8002A2F8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002A2FC: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8002A300: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002A304: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002A308: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8002A30C: bgtz        $a1, L_8002A31C
    if (SIGNED(ctx->r5) > 0) {
        // 0x8002A310: nop
    
            goto L_8002A31C;
    }
    // 0x8002A310: nop

    // 0x8002A314: b           L_8002A368
    // 0x8002A318: nop

        goto L_8002A368;
    // 0x8002A318: nop

L_8002A31C:
    // 0x8002A31C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8002A320: nop

    // 0x8002A324: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8002A328: beq         $a0, $zero, L_8002A344
    if (ctx->r4 == 0) {
        // 0x8002A32C: nop
    
            goto L_8002A344;
    }
    // 0x8002A32C: nop

    // 0x8002A330: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8002A334: nop

    // 0x8002A338: lw          $t3, 0x14($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X14);
    // 0x8002A33C: b           L_8002A358
    // 0x8002A340: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
        goto L_8002A358;
    // 0x8002A340: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
L_8002A344:
    // 0x8002A344: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8002A348: nop

    // 0x8002A34C: lw          $t4, 0x18($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X18);
    // 0x8002A350: nop

    // 0x8002A354: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
L_8002A358:
    // 0x8002A358: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8002A35C: nop

    // 0x8002A360: bne         $t6, $zero, L_8002A29C
    if (ctx->r14 != 0) {
        // 0x8002A364: nop
    
            goto L_8002A29C;
    }
    // 0x8002A364: nop

L_8002A368:
    // 0x8002A368: beq         $a0, $zero, L_8002A37C
    if (ctx->r4 == 0) {
        // 0x8002A36C: nop
    
            goto L_8002A37C;
    }
    // 0x8002A36C: nop

    // 0x8002A370: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8002A374: b           L_8002A384
    // 0x8002A378: nop

        goto L_8002A384;
    // 0x8002A378: nop

L_8002A37C:
    // 0x8002A37C: lw          $a2, 0x4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4);
    // 0x8002A380: nop

L_8002A384:
    // 0x8002A384: b           L_8002A394
    // 0x8002A388: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_8002A394;
    // 0x8002A388: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8002A38C: b           L_8002A394
    // 0x8002A390: nop

        goto L_8002A394;
    // 0x8002A390: nop

L_8002A394:
    // 0x8002A394: jr          $ra
    // 0x8002A398: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002A398: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8009A14C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A14C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009A150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009A154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009A158: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009A15C: nop

    // 0x8009A160: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8009A164: nop

    // 0x8009A168: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8009A16C: beq         $t8, $zero, L_8009A1B8
    if (ctx->r24 == 0) {
        // 0x8009A170: nop
    
            goto L_8009A1B8;
    }
    // 0x8009A170: nop

    // 0x8009A174: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A178: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x8009A17C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8009A180: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A184: lwc1        $f10, 0x7230($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8009A188: lwc1        $f4, 0xCC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8009A18C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A190: lwc1        $f18, 0x7218($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009A194: lwc1        $f16, 0xD4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XD4);
    // 0x8009A198: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009A19C: lwc1        $f8, 0xD0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x8009A1A0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8009A1A4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8009A1A8: jal         0x800C2304
    // 0x8009A1AC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_0;
    // 0x8009A1AC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8009A1B0: b           L_8009A214
    // 0x8009A1B4: nop

        goto L_8009A214;
    // 0x8009A1B4: nop

L_8009A1B8:
    // 0x8009A1B8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8009A1BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A1C0: lw          $t1, 0xDC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XDC);
    // 0x8009A1C4: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x8009A1C8: lwc1        $f6, 0xCC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x8009A1CC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8009A1D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8009A1D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A1D8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009A1DC: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8009A1E0: lwc1        $f4, 0xD0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x8009A1E4: lw          $t2, 0xE0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XE0);
    // 0x8009A1E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009A1EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A1F0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8009A1F4: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009A1F8: lwc1        $f18, 0xD4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XD4);
    // 0x8009A1FC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8009A200: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8009A204: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009A208: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8009A20C: jal         0x800C2304
    // 0x8009A210: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_1;
    // 0x8009A210: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
L_8009A214:
    // 0x8009A214: b           L_8009A21C
    // 0x8009A218: nop

        goto L_8009A21C;
    // 0x8009A218: nop

L_8009A21C:
    // 0x8009A21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009A220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009A224: jr          $ra
    // 0x8009A228: nop

    return;
    // 0x8009A228: nop

;}
RECOMP_FUNC void func_80077214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007721C: jal         0x80061488
    // 0x80077220: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077220: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    after_0:
    // 0x80077224: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077228: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007722C: b           L_8007723C
    // 0x80077230: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007723C;
    // 0x80077230: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077234: b           L_8007723C
    // 0x80077238: nop

        goto L_8007723C;
    // 0x80077238: nop

L_8007723C:
    // 0x8007723C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077244: jr          $ra
    // 0x80077248: nop

    return;
    // 0x80077248: nop

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
RECOMP_FUNC void func_80075BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075BFC: jal         0x80061488
    // 0x80075C00: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075C00: addiu       $a0, $zero, 0x469
    ctx->r4 = ADD32(0, 0X469);
    after_0:
    // 0x80075C04: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80075C08: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80075C0C: b           L_80075C1C
    // 0x80075C10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075C1C;
    // 0x80075C10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075C14: b           L_80075C1C
    // 0x80075C18: nop

        goto L_80075C1C;
    // 0x80075C18: nop

L_80075C1C:
    // 0x80075C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075C24: jr          $ra
    // 0x80075C28: nop

    return;
    // 0x80075C28: nop

;}
RECOMP_FUNC void func_8006D2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D2F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D300: jal         0x80061348
    // 0x8006D304: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D304: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006D308: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D30C: b           L_8006D31C
    // 0x8006D310: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D31C;
    // 0x8006D310: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D314: b           L_8006D31C
    // 0x8006D318: nop

        goto L_8006D31C;
    // 0x8006D318: nop

L_8006D31C:
    // 0x8006D31C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D324: jr          $ra
    // 0x8006D328: nop

    return;
    // 0x8006D328: nop

;}
RECOMP_FUNC void Main_BootProc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD6F0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800BD6F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BD6F8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800BD6FC: jal         0x800CB170
    // 0x800BD700: nop

    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x800BD700: nop

    after_0:
    // 0x800BD704: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD708: sw          $zero, 0x1698($at)
    MEM_W(0X1698, ctx->r1) = 0;
    // 0x800BD70C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD710: sw          $zero, 0x16C4($at)
    MEM_W(0X16C4, ctx->r1) = 0;
    // 0x800BD714: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BD718: addiu       $t6, $t6, 0x49C8
    ctx->r14 = ADD32(ctx->r14, 0X49C8);
    // 0x800BD71C: addiu       $t7, $t6, 0x2000
    ctx->r15 = ADD32(ctx->r14, 0X2000);
    // 0x800BD720: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD724: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800BD728: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800BD72C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800BD730: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800BD734: addiu       $a2, $a2, -0x2894
    ctx->r6 = ADD32(ctx->r6, -0X2894);
    // 0x800BD738: addiu       $a0, $a0, 0x2650
    ctx->r4 = ADD32(ctx->r4, 0X2650);
    // 0x800BD73C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800BD740: jal         0x800C4800
    // 0x800BD744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800BD744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x800BD748: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BD74C: jal         0x800C4950
    // 0x800BD750: addiu       $a0, $a0, 0x2650
    ctx->r4 = ADD32(ctx->r4, 0X2650);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800BD750: addiu       $a0, $a0, 0x2650
    ctx->r4 = ADD32(ctx->r4, 0X2650);
    after_2:
    // 0x800BD754: b           L_800BD75C
    // 0x800BD758: nop

        goto L_800BD75C;
    // 0x800BD758: nop

L_800BD75C:
    // 0x800BD75C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD760: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800BD764: jr          $ra
    // 0x800BD768: nop

    return;
    // 0x800BD768: nop

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
RECOMP_FUNC void func_80077C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077C40: jal         0x80061488
    // 0x80077C44: addiu       $a0, $zero, 0x5F5
    ctx->r4 = ADD32(0, 0X5F5);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077C44: addiu       $a0, $zero, 0x5F5
    ctx->r4 = ADD32(0, 0X5F5);
    after_0:
    // 0x80077C48: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80077C4C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80077C50: b           L_80077C60
    // 0x80077C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077C60;
    // 0x80077C54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077C58: b           L_80077C60
    // 0x80077C5C: nop

        goto L_80077C60;
    // 0x80077C5C: nop

L_80077C60:
    // 0x80077C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077C68: jr          $ra
    // 0x80077C6C: nop

    return;
    // 0x80077C6C: nop

;}
RECOMP_FUNC void func_80035CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035CF8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80035CFC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80035D00: lw          $t6, 0x7278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7278);
    // 0x80035D04: nop

    // 0x80035D08: lhu         $t7, 0x1C($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X1C);
    // 0x80035D0C: nop

    // 0x80035D10: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80035D14: bne         $at, $zero, L_80035D68
    if (ctx->r1 != 0) {
        // 0x80035D18: nop
    
            goto L_80035D68;
    }
    // 0x80035D18: nop

    // 0x80035D1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80035D20: lw          $t8, 0x103C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X103C);
    // 0x80035D24: nop

    // 0x80035D28: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80035D2C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80035D30: nop

    // 0x80035D34: lh          $t0, 0x126($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X126);
    // 0x80035D38: nop

    // 0x80035D3C: addiu       $t1, $t0, 0x1E
    ctx->r9 = ADD32(ctx->r8, 0X1E);
    // 0x80035D40: sh          $t1, 0x126($t9)
    MEM_H(0X126, ctx->r25) = ctx->r9;
    // 0x80035D44: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80035D48: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80035D4C: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80035D50: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80035D54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80035D58: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80035D5C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80035D60: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80035D64: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
L_80035D68:
    // 0x80035D68: b           L_80035D70
    // 0x80035D6C: nop

        goto L_80035D70;
    // 0x80035D6C: nop

L_80035D70:
    // 0x80035D70: jr          $ra
    // 0x80035D74: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80035D74: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800766B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800766B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800766BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800766C0: nop

    // 0x800766C4: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800766C8: nop

    // 0x800766CC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800766D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800766D4: jr          $ra
    // 0x800766D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800766D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800766DC: jr          $ra
    // 0x800766E0: nop

    return;
    // 0x800766E0: nop

    // 0x800766E4: jr          $ra
    // 0x800766E8: nop

    return;
    // 0x800766E8: nop

;}
RECOMP_FUNC void func_8006CF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CF54: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CF58: nop

    // 0x8006CF5C: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x8006CF60: nop

    // 0x8006CF64: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CF68: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CF6C: jr          $ra
    // 0x8006CF70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CF70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CF74: jr          $ra
    // 0x8006CF78: nop

    return;
    // 0x8006CF78: nop

    // 0x8006CF7C: jr          $ra
    // 0x8006CF80: nop

    return;
    // 0x8006CF80: nop

;}
RECOMP_FUNC void func_80075AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075ACC: jal         0x80061348
    // 0x80075AD0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075AD0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x80075AD4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075AD8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075ADC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075AE0: beq         $v0, $zero, L_80075B34
    if (ctx->r2 == 0) {
        // 0x80075AE4: nop
    
            goto L_80075B34;
    }
    // 0x80075AE4: nop

    // 0x80075AE8: jal         0x80061348
    // 0x80075AEC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075AEC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075AF0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075AF4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075AF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075AFC: beq         $v0, $zero, L_80075B34
    if (ctx->r2 == 0) {
        // 0x80075B00: nop
    
            goto L_80075B34;
    }
    // 0x80075B00: nop

    // 0x80075B04: jal         0x80061348
    // 0x80075B08: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075B08: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x80075B0C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075B10: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075B14: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075B18: beq         $v0, $zero, L_80075B34
    if (ctx->r2 == 0) {
        // 0x80075B1C: nop
    
            goto L_80075B34;
    }
    // 0x80075B1C: nop

    // 0x80075B20: jal         0x80061348
    // 0x80075B24: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075B24: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075B28: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075B2C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075B30: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075B34:
    // 0x80075B34: b           L_80075B44
    // 0x80075B38: nop

        goto L_80075B44;
    // 0x80075B38: nop

    // 0x80075B3C: b           L_80075B44
    // 0x80075B40: nop

        goto L_80075B44;
    // 0x80075B40: nop

L_80075B44:
    // 0x80075B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075B4C: jr          $ra
    // 0x80075B50: nop

    return;
    // 0x80075B50: nop

;}
RECOMP_FUNC void func_8006E628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E62C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E630: jal         0x80061348
    // 0x8006E634: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E634: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x8006E638: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E63C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E640: beq         $v0, $zero, L_8006E658
    if (ctx->r2 == 0) {
        // 0x8006E644: nop
    
            goto L_8006E658;
    }
    // 0x8006E644: nop

    // 0x8006E648: jal         0x80061348
    // 0x8006E64C: addiu       $a0, $zero, 0x14A
    ctx->r4 = ADD32(0, 0X14A);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E64C: addiu       $a0, $zero, 0x14A
    ctx->r4 = ADD32(0, 0X14A);
    after_1:
    // 0x8006E650: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E654: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E658:
    // 0x8006E658: b           L_8006E668
    // 0x8006E65C: nop

        goto L_8006E668;
    // 0x8006E65C: nop

    // 0x8006E660: b           L_8006E668
    // 0x8006E664: nop

        goto L_8006E668;
    // 0x8006E664: nop

L_8006E668:
    // 0x8006E668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E670: jr          $ra
    // 0x8006E674: nop

    return;
    // 0x8006E674: nop

;}
RECOMP_FUNC void func_80067BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067C00: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067C04: nop

    // 0x80067C08: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067C0C: nop

    // 0x80067C10: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067C14: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067C18: jr          $ra
    // 0x80067C1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067C1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067C20: jr          $ra
    // 0x80067C24: nop

    return;
    // 0x80067C24: nop

    // 0x80067C28: jr          $ra
    // 0x80067C2C: nop

    return;
    // 0x80067C2C: nop

;}
RECOMP_FUNC void func_80068EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068EE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068EE8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068EEC: nop

    // 0x80068EF0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80068EF4: nop

    // 0x80068EF8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80068EFC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068F00: jr          $ra
    // 0x80068F04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068F04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068F08: jr          $ra
    // 0x80068F0C: nop

    return;
    // 0x80068F0C: nop

    // 0x80068F10: jr          $ra
    // 0x80068F14: nop

    return;
    // 0x80068F14: nop

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
RECOMP_FUNC void func_8006AF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AF98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006AF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006AFA0: jal         0x80061348
    // 0x8006AFA4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006AFA4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_0:
    // 0x8006AFA8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006AFAC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006AFB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006AFB4: beq         $v0, $zero, L_8006AFF4
    if (ctx->r2 == 0) {
        // 0x8006AFB8: nop
    
            goto L_8006AFF4;
    }
    // 0x8006AFB8: nop

    // 0x8006AFBC: jal         0x80061348
    // 0x8006AFC0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006AFC0: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_1:
    // 0x8006AFC4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006AFC8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006AFCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006AFD0: beq         $v0, $zero, L_8006AFF4
    if (ctx->r2 == 0) {
        // 0x8006AFD4: nop
    
            goto L_8006AFF4;
    }
    // 0x8006AFD4: nop

    // 0x8006AFD8: jal         0x80061348
    // 0x8006AFDC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006AFDC: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_2:
    // 0x8006AFE0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006AFE4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006AFE8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006AFEC: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006AFF0: nop
    
            goto L_8006B238;
    }
    // 0x8006AFF0: nop

L_8006AFF4:
    // 0x8006AFF4: jal         0x80061348
    // 0x8006AFF8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006AFF8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_3:
    // 0x8006AFFC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B000: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B004: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006B008: beq         $v0, $zero, L_8006B048
    if (ctx->r2 == 0) {
        // 0x8006B00C: nop
    
            goto L_8006B048;
    }
    // 0x8006B00C: nop

    // 0x8006B010: jal         0x80061348
    // 0x8006B014: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006B014: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_4:
    // 0x8006B018: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006B01C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006B020: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006B024: beq         $v0, $zero, L_8006B048
    if (ctx->r2 == 0) {
        // 0x8006B028: nop
    
            goto L_8006B048;
    }
    // 0x8006B028: nop

    // 0x8006B02C: jal         0x80061348
    // 0x8006B030: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006B030: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_5:
    // 0x8006B034: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006B038: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006B03C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006B040: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B044: nop
    
            goto L_8006B238;
    }
    // 0x8006B044: nop

L_8006B048:
    // 0x8006B048: jal         0x80061348
    // 0x8006B04C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006B04C: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_6:
    // 0x8006B050: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006B054: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006B058: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006B05C: beq         $v0, $zero, L_8006B09C
    if (ctx->r2 == 0) {
        // 0x8006B060: nop
    
            goto L_8006B09C;
    }
    // 0x8006B060: nop

    // 0x8006B064: jal         0x80061348
    // 0x8006B068: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006B068: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_7:
    // 0x8006B06C: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006B070: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006B074: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006B078: beq         $v0, $zero, L_8006B09C
    if (ctx->r2 == 0) {
        // 0x8006B07C: nop
    
            goto L_8006B09C;
    }
    // 0x8006B07C: nop

    // 0x8006B080: jal         0x80061348
    // 0x8006B084: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006B084: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_8:
    // 0x8006B088: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006B08C: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006B090: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006B094: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B098: nop
    
            goto L_8006B238;
    }
    // 0x8006B098: nop

L_8006B09C:
    // 0x8006B09C: jal         0x80061348
    // 0x8006B0A0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006B0A0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_9:
    // 0x8006B0A4: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006B0A8: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006B0AC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006B0B0: beq         $v0, $zero, L_8006B0F0
    if (ctx->r2 == 0) {
        // 0x8006B0B4: nop
    
            goto L_8006B0F0;
    }
    // 0x8006B0B4: nop

    // 0x8006B0B8: jal         0x80061348
    // 0x8006B0BC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006B0BC: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_10:
    // 0x8006B0C0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B0C4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B0C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B0CC: beq         $v0, $zero, L_8006B0F0
    if (ctx->r2 == 0) {
        // 0x8006B0D0: nop
    
            goto L_8006B0F0;
    }
    // 0x8006B0D0: nop

    // 0x8006B0D4: jal         0x80061348
    // 0x8006B0D8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006B0D8: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_11:
    // 0x8006B0DC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B0E0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B0E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B0E8: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B0EC: nop
    
            goto L_8006B238;
    }
    // 0x8006B0EC: nop

L_8006B0F0:
    // 0x8006B0F0: jal         0x80061348
    // 0x8006B0F4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006B0F4: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_12:
    // 0x8006B0F8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B0FC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B100: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B104: beq         $v0, $zero, L_8006B144
    if (ctx->r2 == 0) {
        // 0x8006B108: nop
    
            goto L_8006B144;
    }
    // 0x8006B108: nop

    // 0x8006B10C: jal         0x80061348
    // 0x8006B110: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006B110: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_13:
    // 0x8006B114: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B118: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B11C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006B120: beq         $v0, $zero, L_8006B144
    if (ctx->r2 == 0) {
        // 0x8006B124: nop
    
            goto L_8006B144;
    }
    // 0x8006B124: nop

    // 0x8006B128: jal         0x80061348
    // 0x8006B12C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006B12C: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_14:
    // 0x8006B130: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x8006B134: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8006B138: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006B13C: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B140: nop
    
            goto L_8006B238;
    }
    // 0x8006B140: nop

L_8006B144:
    // 0x8006B144: jal         0x80061348
    // 0x8006B148: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006B148: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_15:
    // 0x8006B14C: xori        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 ^ 0X1;
    // 0x8006B150: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8006B154: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006B158: beq         $v0, $zero, L_8006B198
    if (ctx->r2 == 0) {
        // 0x8006B15C: nop
    
            goto L_8006B198;
    }
    // 0x8006B15C: nop

    // 0x8006B160: jal         0x80061348
    // 0x8006B164: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006B164: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_16:
    // 0x8006B168: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x8006B16C: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x8006B170: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006B174: beq         $v0, $zero, L_8006B198
    if (ctx->r2 == 0) {
        // 0x8006B178: nop
    
            goto L_8006B198;
    }
    // 0x8006B178: nop

    // 0x8006B17C: jal         0x80061348
    // 0x8006B180: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006B180: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_17:
    // 0x8006B184: xori        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 ^ 0X1;
    // 0x8006B188: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006B18C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006B190: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B194: nop
    
            goto L_8006B238;
    }
    // 0x8006B194: nop

L_8006B198:
    // 0x8006B198: jal         0x80061348
    // 0x8006B19C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006B19C: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_18:
    // 0x8006B1A0: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8006B1A4: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8006B1A8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006B1AC: beq         $v0, $zero, L_8006B1EC
    if (ctx->r2 == 0) {
        // 0x8006B1B0: nop
    
            goto L_8006B1EC;
    }
    // 0x8006B1B0: nop

    // 0x8006B1B4: jal         0x80061348
    // 0x8006B1B8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006B1B8: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
    after_19:
    // 0x8006B1BC: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x8006B1C0: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8006B1C4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006B1C8: beq         $v0, $zero, L_8006B1EC
    if (ctx->r2 == 0) {
        // 0x8006B1CC: nop
    
            goto L_8006B1EC;
    }
    // 0x8006B1CC: nop

    // 0x8006B1D0: jal         0x80061348
    // 0x8006B1D4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006B1D4: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_20:
    // 0x8006B1D8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006B1DC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006B1E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B1E4: bne         $v0, $zero, L_8006B238
    if (ctx->r2 != 0) {
        // 0x8006B1E8: nop
    
            goto L_8006B238;
    }
    // 0x8006B1E8: nop

L_8006B1EC:
    // 0x8006B1EC: jal         0x80061348
    // 0x8006B1F0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006B1F0: addiu       $a0, $zero, 0x75D
    ctx->r4 = ADD32(0, 0X75D);
    after_21:
    // 0x8006B1F4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006B1F8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006B1FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B200: beq         $v0, $zero, L_8006B238
    if (ctx->r2 == 0) {
        // 0x8006B204: nop
    
            goto L_8006B238;
    }
    // 0x8006B204: nop

    // 0x8006B208: jal         0x80061348
    // 0x8006B20C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006B20C: addiu       $a0, $zero, 0x3BD
    ctx->r4 = ADD32(0, 0X3BD);
    after_22:
    // 0x8006B210: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006B214: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006B218: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006B21C: beq         $v0, $zero, L_8006B238
    if (ctx->r2 == 0) {
        // 0x8006B220: nop
    
            goto L_8006B238;
    }
    // 0x8006B220: nop

    // 0x8006B224: jal         0x80061348
    // 0x8006B228: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006B228: addiu       $a0, $zero, 0x382
    ctx->r4 = ADD32(0, 0X382);
    after_23:
    // 0x8006B22C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006B230: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006B234: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006B238:
    // 0x8006B238: b           L_8006B248
    // 0x8006B23C: nop

        goto L_8006B248;
    // 0x8006B23C: nop

    // 0x8006B240: b           L_8006B248
    // 0x8006B244: nop

        goto L_8006B248;
    // 0x8006B244: nop

L_8006B248:
    // 0x8006B248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B24C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B250: jr          $ra
    // 0x8006B254: nop

    return;
    // 0x8006B254: nop

;}
RECOMP_FUNC void func_80066E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066E68: jal         0x80061348
    // 0x80066E6C: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066E6C: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    after_0:
    // 0x80066E70: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066E74: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066E78: b           L_80066E88
    // 0x80066E7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066E88;
    // 0x80066E7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066E80: b           L_80066E88
    // 0x80066E84: nop

        goto L_80066E88;
    // 0x80066E84: nop

L_80066E88:
    // 0x80066E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066E90: jr          $ra
    // 0x80066E94: nop

    return;
    // 0x80066E94: nop

;}
RECOMP_FUNC void func_80063898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063898: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006389C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800638A0: nop

    // 0x800638A4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800638A8: nop

    // 0x800638AC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800638B0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800638B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800638B8: beq         $v0, $zero, L_800638D4
    if (ctx->r2 == 0) {
        // 0x800638BC: nop
    
            goto L_800638D4;
    }
    // 0x800638BC: nop

    // 0x800638C0: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x800638C4: nop

    // 0x800638C8: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800638CC: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800638D0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800638D4:
    // 0x800638D4: jr          $ra
    // 0x800638D8: nop

    return;
    // 0x800638D8: nop

    // 0x800638DC: jr          $ra
    // 0x800638E0: nop

    return;
    // 0x800638E0: nop

    // 0x800638E4: jr          $ra
    // 0x800638E8: nop

    return;
    // 0x800638E8: nop

;}
RECOMP_FUNC void func_80029394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029394: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80029398: lw          $a1, 0x14($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X14);
    // 0x8002939C: nop

    // 0x800293A0: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x800293A4: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x800293A8: nop

    // 0x800293AC: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800293B0: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800293B4: nop

    // 0x800293B8: sw          $t7, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r15;
    // 0x800293BC: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800293C0: nop

    // 0x800293C4: beq         $t8, $zero, L_800293DC
    if (ctx->r24 == 0) {
        // 0x800293C8: nop
    
            goto L_800293DC;
    }
    // 0x800293C8: nop

    // 0x800293CC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800293D0: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800293D4: nop

    // 0x800293D8: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
L_800293DC:
    // 0x800293DC: b           L_800293E4
    // 0x800293E0: nop

        goto L_800293E4;
    // 0x800293E0: nop

L_800293E4:
    // 0x800293E4: jr          $ra
    // 0x800293E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800293E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80066A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066A50: jal         0x80061348
    // 0x80066A54: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066A54: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_0:
    // 0x80066A58: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066A5C: b           L_80066A6C
    // 0x80066A60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066A6C;
    // 0x80066A60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066A64: b           L_80066A6C
    // 0x80066A68: nop

        goto L_80066A6C;
    // 0x80066A68: nop

L_80066A6C:
    // 0x80066A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066A74: jr          $ra
    // 0x80066A78: nop

    return;
    // 0x80066A78: nop

;}
RECOMP_FUNC void func_80071470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071470: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071474: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071478: nop

    // 0x8007147C: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80071480: nop

    // 0x80071484: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80071488: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007148C: jr          $ra
    // 0x80071490: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071490: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071494: jr          $ra
    // 0x80071498: nop

    return;
    // 0x80071498: nop

    // 0x8007149C: jr          $ra
    // 0x800714A0: nop

    return;
    // 0x800714A0: nop

;}
RECOMP_FUNC void func_8007734C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007734C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077354: jal         0x80061488
    // 0x80077358: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077358: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x8007735C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077360: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077364: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077368: beq         $v0, $zero, L_80077390
    if (ctx->r2 == 0) {
        // 0x8007736C: nop
    
            goto L_80077390;
    }
    // 0x8007736C: nop

    // 0x80077370: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80077374: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80077378: nop

    // 0x8007737C: lh          $v0, 0x34($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X34);
    // 0x80077380: nop

    // 0x80077384: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077388: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8007738C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80077390:
    // 0x80077390: b           L_800773A0
    // 0x80077394: nop

        goto L_800773A0;
    // 0x80077394: nop

    // 0x80077398: b           L_800773A0
    // 0x8007739C: nop

        goto L_800773A0;
    // 0x8007739C: nop

L_800773A0:
    // 0x800773A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800773A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800773A8: jr          $ra
    // 0x800773AC: nop

    return;
    // 0x800773AC: nop

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
RECOMP_FUNC void func_8007744C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007744C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077454: jal         0x80061488
    // 0x80077458: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077458: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x8007745C: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80077460: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80077464: b           L_80077474
    // 0x80077468: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077474;
    // 0x80077468: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007746C: b           L_80077474
    // 0x80077470: nop

        goto L_80077474;
    // 0x80077470: nop

L_80077474:
    // 0x80077474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007747C: jr          $ra
    // 0x80077480: nop

    return;
    // 0x80077480: nop

;}
RECOMP_FUNC void func_8006656C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006656C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066574: jal         0x80061348
    // 0x80066578: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066578: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_0:
    // 0x8006657C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066580: b           L_80066590
    // 0x80066584: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066590;
    // 0x80066584: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066588: b           L_80066590
    // 0x8006658C: nop

        goto L_80066590;
    // 0x8006658C: nop

L_80066590:
    // 0x80066590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066598: jr          $ra
    // 0x8006659C: nop

    return;
    // 0x8006659C: nop

;}
RECOMP_FUNC void alSeqpPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CAD24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CAD28: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800CAD2C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800CAD30: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CAD34: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CAD38: jal         0x800D3A2C
    // 0x800CAD3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CAD3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CAD40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAD44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CAD48: jr          $ra
    // 0x800CAD4C: nop

    return;
    // 0x800CAD4C: nop

;}
RECOMP_FUNC void func_80065408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065408: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006540C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065410: nop

    // 0x80065414: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80065418: nop

    // 0x8006541C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80065420: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065424: jr          $ra
    // 0x80065428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006542C: jr          $ra
    // 0x80065430: nop

    return;
    // 0x80065430: nop

    // 0x80065434: jr          $ra
    // 0x80065438: nop

    return;
    // 0x80065438: nop

;}
RECOMP_FUNC void func_80066794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006679C: jal         0x80061348
    // 0x800667A0: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800667A0: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x800667A4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800667A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800667AC: bne         $v0, $zero, L_800667C4
    if (ctx->r2 != 0) {
        // 0x800667B0: nop
    
            goto L_800667C4;
    }
    // 0x800667B0: nop

    // 0x800667B4: jal         0x80061348
    // 0x800667B8: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800667B8: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x800667BC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800667C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800667C4:
    // 0x800667C4: b           L_800667D4
    // 0x800667C8: nop

        goto L_800667D4;
    // 0x800667C8: nop

    // 0x800667CC: b           L_800667D4
    // 0x800667D0: nop

        goto L_800667D4;
    // 0x800667D0: nop

L_800667D4:
    // 0x800667D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800667D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800667DC: jr          $ra
    // 0x800667E0: nop

    return;
    // 0x800667E0: nop

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
RECOMP_FUNC void alSndpPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA170: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA178: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA17C: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x800CA180: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800CA184: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA188: mflo        $t7
    ctx->r15 = lo;
    // 0x800CA18C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800CA190: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x800CA194: bnel        $t9, $zero, L_800CA1C8
    if (ctx->r25 != 0) {
        // 0x800CA198: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CA1C8;
    }
    goto skip_0;
    // 0x800CA198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CA19C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800CA1A0: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA1A4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA1A8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA1AC: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA1B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA1B4: mflo        $t1
    ctx->r9 = lo;
    // 0x800CA1B8: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800CA1BC: jal         0x800D3A2C
    // 0x800CA1C0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA1C0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_0:
    // 0x800CA1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CA1C8:
    // 0x800CA1C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA1CC: jr          $ra
    // 0x800CA1D0: nop

    return;
    // 0x800CA1D0: nop

;}
RECOMP_FUNC void func_80015C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015C30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80015C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015C38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80015C3C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80015C40: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80015C44: jal         0x8000DA44
    // 0x80015C48: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80015C48: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80015C4C: bgez        $v0, L_80015C5C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80015C50: nop
    
            goto L_80015C5C;
    }
    // 0x80015C50: nop

    // 0x80015C54: b           L_80015D64
    // 0x80015C58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80015D64;
    // 0x80015C58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015C5C:
    // 0x80015C5C: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80015C60: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80015C64: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80015C68: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80015C6C: nop

    // 0x80015C70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015C74: swc1        $f6, 0x1B0($t8)
    MEM_W(0X1B0, ctx->r24) = ctx->f6.u32l;
    // 0x80015C78: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x80015C7C: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80015C80: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80015C84: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80015C88: nop

    // 0x80015C8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80015C90: swc1        $f10, 0x1B4($t1)
    MEM_W(0X1B4, ctx->r9) = ctx->f10.u32l;
    // 0x80015C94: addiu       $t2, $sp, 0x1C
    ctx->r10 = ADD32(ctx->r29, 0X1C);
    // 0x80015C98: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x80015C9C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80015CA0: nop

    // 0x80015CA4: sh          $t3, 0x118($t4)
    MEM_H(0X118, ctx->r12) = ctx->r11;
    // 0x80015CA8: addiu       $t5, $sp, 0x1C
    ctx->r13 = ADD32(ctx->r29, 0X1C);
    // 0x80015CAC: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x80015CB0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80015CB4: nop

    // 0x80015CB8: sh          $t6, 0x11A($t7)
    MEM_H(0X11A, ctx->r15) = ctx->r14;
    // 0x80015CBC: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x80015CC0: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x80015CC4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80015CC8: nop

    // 0x80015CCC: sh          $t9, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r25;
    // 0x80015CD0: addiu       $t1, $sp, 0x1C
    ctx->r9 = ADD32(ctx->r29, 0X1C);
    // 0x80015CD4: lhu         $t2, 0xC($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XC);
    // 0x80015CD8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80015CDC: nop

    // 0x80015CE0: sh          $t2, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r10;
    // 0x80015CE4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80015CE8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80015CEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80015CF0: lwc1        $f16, 0x1B0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X1B0);
    // 0x80015CF4: nop

    // 0x80015CF8: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80015CFC: nop

    // 0x80015D00: bc1f        L_80015D1C
    if (!c1cs) {
        // 0x80015D04: nop
    
            goto L_80015D1C;
    }
    // 0x80015D04: nop

    // 0x80015D08: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80015D0C: lwc1        $f4, -0x2A50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A50);
    // 0x80015D10: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80015D14: nop

    // 0x80015D18: swc1        $f4, 0x1B0($t5)
    MEM_W(0X1B0, ctx->r13) = ctx->f4.u32l;
L_80015D1C:
    // 0x80015D1C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80015D20: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80015D24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80015D28: lwc1        $f6, 0x1B4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1B4);
    // 0x80015D2C: nop

    // 0x80015D30: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80015D34: nop

    // 0x80015D38: bc1f        L_80015D54
    if (!c1cs) {
        // 0x80015D3C: nop
    
            goto L_80015D54;
    }
    // 0x80015D3C: nop

    // 0x80015D40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80015D44: lwc1        $f10, -0x2A4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A4C);
    // 0x80015D48: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80015D4C: nop

    // 0x80015D50: swc1        $f10, 0x1B4($t7)
    MEM_W(0X1B4, ctx->r15) = ctx->f10.u32l;
L_80015D54:
    // 0x80015D54: b           L_80015D64
    // 0x80015D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80015D64;
    // 0x80015D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015D5C: b           L_80015D64
    // 0x80015D60: nop

        goto L_80015D64;
    // 0x80015D60: nop

L_80015D64:
    // 0x80015D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015D68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80015D6C: jr          $ra
    // 0x80015D70: nop

    return;
    // 0x80015D70: nop

;}
RECOMP_FUNC void func_8006C240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C248: jal         0x8005F064
    // 0x8006C24C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C24C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_0:
    // 0x8006C250: b           L_8006C260
    // 0x8006C254: nop

        goto L_8006C260;
    // 0x8006C254: nop

    // 0x8006C258: b           L_8006C260
    // 0x8006C25C: nop

        goto L_8006C260;
    // 0x8006C25C: nop

L_8006C260:
    // 0x8006C260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C268: jr          $ra
    // 0x8006C26C: nop

    return;
    // 0x8006C26C: nop

;}
RECOMP_FUNC void func_80066344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006634C: jal         0x80061348
    // 0x80066350: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066350: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066354: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066358: b           L_80066368
    // 0x8006635C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066368;
    // 0x8006635C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066360: b           L_80066368
    // 0x80066364: nop

        goto L_80066368;
    // 0x80066364: nop

L_80066368:
    // 0x80066368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006636C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066370: jr          $ra
    // 0x80066374: nop

    return;
    // 0x80066374: nop

;}
RECOMP_FUNC void func_8005B610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B610: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005B614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005B618: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005B61C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005B620: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005B624: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B628: nop

    // 0x8005B62C: lw          $t7, 0xA4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA4);
    // 0x8005B630: lw          $t8, 0xA8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XA8);
    // 0x8005B634: nop

    // 0x8005B638: beq         $t7, $t8, L_8005B97C
    if (ctx->r15 == ctx->r24) {
        // 0x8005B63C: nop
    
            goto L_8005B97C;
    }
    // 0x8005B63C: nop

    // 0x8005B640: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005B644: nop

    // 0x8005B648: lw          $t0, 0xA8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XA8);
    // 0x8005B64C: nop

    // 0x8005B650: sw          $t0, 0xA4($t9)
    MEM_W(0XA4, ctx->r25) = ctx->r8;
    // 0x8005B654: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005B658: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8005B65C: lh          $t2, 0xAC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XAC);
    // 0x8005B660: nop

    // 0x8005B664: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8005B668: sh          $t3, 0xAC($t1)
    MEM_H(0XAC, ctx->r9) = ctx->r11;
    // 0x8005B66C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005B670: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005B674: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005B678: nop

    // 0x8005B67C: bne         $t4, $t5, L_8005B740
    if (ctx->r12 != ctx->r13) {
        // 0x8005B680: nop
    
            goto L_8005B740;
    }
    // 0x8005B680: nop

    // 0x8005B684: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005B688: lw          $t6, 0xE70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE70);
    // 0x8005B68C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8005B690: lh          $t7, 0xAC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XAC);
    // 0x8005B694: nop

    // 0x8005B698: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8005B69C: sh          $t8, 0xAC($t6)
    MEM_H(0XAC, ctx->r14) = ctx->r24;
    // 0x8005B6A0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005B6A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005B6A8: lw          $t9, 0xA4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XA4);
    // 0x8005B6AC: nop

    // 0x8005B6B0: bne         $t9, $at, L_8005B6EC
    if (ctx->r25 != ctx->r1) {
        // 0x8005B6B4: nop
    
            goto L_8005B6EC;
    }
    // 0x8005B6B4: nop

    // 0x8005B6B8: jal         0x80061E14
    // 0x8005B6BC: nop

    func_80061E14(rdram, ctx);
        goto after_0;
    // 0x8005B6BC: nop

    after_0:
    // 0x8005B6C0: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8005B6C4: bne         $v0, $at, L_8005B6EC
    if (ctx->r2 != ctx->r1) {
        // 0x8005B6C8: nop
    
            goto L_8005B6EC;
    }
    // 0x8005B6C8: nop

    // 0x8005B6CC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005B6D0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8005B6D4: sw          $t2, 0xA8($t3)
    MEM_W(0XA8, ctx->r11) = ctx->r10;
    // 0x8005B6D8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005B6DC: nop

    // 0x8005B6E0: lw          $t4, 0xA8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XA8);
    // 0x8005B6E4: nop

    // 0x8005B6E8: sw          $t4, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->r12;
L_8005B6EC:
    // 0x8005B6EC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8005B6F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005B6F4: lw          $t7, 0xA4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XA4);
    // 0x8005B6F8: nop

    // 0x8005B6FC: bne         $t7, $at, L_8005B738
    if (ctx->r15 != ctx->r1) {
        // 0x8005B700: nop
    
            goto L_8005B738;
    }
    // 0x8005B700: nop

    // 0x8005B704: jal         0x80061E14
    // 0x8005B708: nop

    func_80061E14(rdram, ctx);
        goto after_1;
    // 0x8005B708: nop

    after_1:
    // 0x8005B70C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8005B710: bne         $v0, $at, L_8005B738
    if (ctx->r2 != ctx->r1) {
        // 0x8005B714: nop
    
            goto L_8005B738;
    }
    // 0x8005B714: nop

    // 0x8005B718: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B71C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005B720: sw          $t8, 0xA8($t6)
    MEM_W(0XA8, ctx->r14) = ctx->r24;
    // 0x8005B724: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005B728: nop

    // 0x8005B72C: lw          $t9, 0xA8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XA8);
    // 0x8005B730: nop

    // 0x8005B734: sw          $t9, 0xA4($t0)
    MEM_W(0XA4, ctx->r8) = ctx->r25;
L_8005B738:
    // 0x8005B738: b           L_8005B75C
    // 0x8005B73C: nop

        goto L_8005B75C;
    // 0x8005B73C: nop

L_8005B740:
    // 0x8005B740: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005B744: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005B748: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8005B74C: lh          $t3, 0xAC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XAC);
    // 0x8005B750: nop

    // 0x8005B754: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8005B758: sh          $t4, 0xAC($t2)
    MEM_H(0XAC, ctx->r10) = ctx->r12;
L_8005B75C:
    // 0x8005B75C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8005B760: nop

    // 0x8005B764: lw          $t5, 0xA4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XA4);
    // 0x8005B768: nop

    // 0x8005B76C: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8005B770: bne         $at, $zero, L_8005B85C
    if (ctx->r1 != 0) {
        // 0x8005B774: nop
    
            goto L_8005B85C;
    }
    // 0x8005B774: nop

    // 0x8005B778: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005B77C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8005B780: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
    // 0x8005B784: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B788: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005B78C: lw          $t9, 0xA4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XA4);
    // 0x8005B790: nop

    // 0x8005B794: beq         $t9, $at, L_8005B854
    if (ctx->r25 == ctx->r1) {
        // 0x8005B798: nop
    
            goto L_8005B854;
    }
    // 0x8005B798: nop

    // 0x8005B79C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005B7A0: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005B7A4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005B7A8: nop

    // 0x8005B7AC: bne         $t0, $t3, L_8005B7D8
    if (ctx->r8 != ctx->r11) {
        // 0x8005B7B0: nop
    
            goto L_8005B7D8;
    }
    // 0x8005B7B0: nop

    // 0x8005B7B4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005B7B8: lw          $t4, 0xE70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE70);
    // 0x8005B7BC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005B7C0: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8005B7C4: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8005B7C8: andi        $t9, $t3, 0x8
    ctx->r25 = ctx->r11 & 0X8;
    // 0x8005B7CC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8005B7D0: b           L_8005B7F8
    // 0x8005B7D4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
        goto L_8005B7F8;
    // 0x8005B7D4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8005B7D8:
    // 0x8005B7D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005B7DC: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005B7E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005B7E4: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8005B7E8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8005B7EC: andi        $t1, $t7, 0x8
    ctx->r9 = ctx->r15 & 0X8;
    // 0x8005B7F0: or          $t4, $t1, $zero
    ctx->r12 = ctx->r9 | 0;
    // 0x8005B7F4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8005B7F8:
    // 0x8005B7F8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B7FC: nop

    // 0x8005B800: xori        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 ^ 0X8;
    // 0x8005B804: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8005B808: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005B80C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005B810: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8005B814: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8005B818: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x8005B81C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005B820: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x8005B824: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8005B828: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8005B82C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005B830: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B834: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8005B838: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8005B83C: or          $t7, $t2, $zero
    ctx->r15 = ctx->r10 | 0;
    // 0x8005B840: sra         $t6, $t2, 31
    ctx->r14 = S32(SIGNED(ctx->r10) >> 31);
    // 0x8005B844: or          $t0, $t4, $t6
    ctx->r8 = ctx->r12 | ctx->r14;
    // 0x8005B848: or          $t1, $t5, $t7
    ctx->r9 = ctx->r13 | ctx->r15;
    // 0x8005B84C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x8005B850: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
L_8005B854:
    // 0x8005B854: b           L_8005B894
    // 0x8005B858: nop

        goto L_8005B894;
    // 0x8005B858: nop

L_8005B85C:
    // 0x8005B85C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005B860: nop

    // 0x8005B864: lw          $t8, 0xA4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0XA4);
    // 0x8005B868: nop

    // 0x8005B86C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8005B870: bne         $at, $zero, L_8005B888
    if (ctx->r1 != 0) {
        // 0x8005B874: nop
    
            goto L_8005B888;
    }
    // 0x8005B874: nop

    // 0x8005B878: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8005B87C: addiu       $t2, $zero, 0x3E
    ctx->r10 = ADD32(0, 0X3E);
    // 0x8005B880: b           L_8005B894
    // 0x8005B884: sw          $t2, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r10;
        goto L_8005B894;
    // 0x8005B884: sw          $t2, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r10;
L_8005B888:
    // 0x8005B888: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B88C: addiu       $t5, $zero, 0x3D
    ctx->r13 = ADD32(0, 0X3D);
    // 0x8005B890: sw          $t5, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r13;
L_8005B894:
    // 0x8005B894: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005B898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B89C: lh          $s0, 0x7C($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X7C);
    // 0x8005B8A0: nop

    // 0x8005B8A4: beq         $s0, $at, L_8005B8CC
    if (ctx->r16 == ctx->r1) {
        // 0x8005B8A8: nop
    
            goto L_8005B8CC;
    }
    // 0x8005B8A8: nop

    // 0x8005B8AC: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8005B8B0: beq         $s0, $at, L_8005B904
    if (ctx->r16 == ctx->r1) {
        // 0x8005B8B4: nop
    
            goto L_8005B904;
    }
    // 0x8005B8B4: nop

    // 0x8005B8B8: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8005B8BC: beq         $s0, $at, L_8005B940
    if (ctx->r16 == ctx->r1) {
        // 0x8005B8C0: nop
    
            goto L_8005B940;
    }
    // 0x8005B8C0: nop

    // 0x8005B8C4: b           L_8005B97C
    // 0x8005B8C8: nop

        goto L_8005B97C;
    // 0x8005B8C8: nop

L_8005B8CC:
    // 0x8005B8CC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005B8D0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005B8D4: lw          $t1, 0xA4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XA4);
    // 0x8005B8D8: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8005B8DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005B8E0: sll         $t9, $t1, 1
    ctx->r25 = S32(ctx->r9 << 1);
    // 0x8005B8E4: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8005B8E8: lh          $a0, -0x26E0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X26E0);
    // 0x8005B8EC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8005B8F0: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x8005B8F4: jal         0x8004EF90
    // 0x8005B8F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_2;
    // 0x8005B8F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8005B8FC: b           L_8005B97C
    // 0x8005B900: nop

        goto L_8005B97C;
    // 0x8005B900: nop

L_8005B904:
    // 0x8005B904: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005B908: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005B90C: lw          $t2, 0xA4($t8)
    ctx->r10 = MEM_W(ctx->r24, 0XA4);
    // 0x8005B910: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005B914: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8005B918: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8005B91C: lh          $a1, 0x7C($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X7C);
    // 0x8005B920: lw          $a3, 0x44($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X44);
    // 0x8005B924: lh          $a2, -0x26C4($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X26C4);
    // 0x8005B928: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B92C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8005B930: jal         0x8004F3E8
    // 0x8005B934: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_8004F3E8(rdram, ctx);
        goto after_3;
    // 0x8005B934: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_3:
    // 0x8005B938: b           L_8005B97C
    // 0x8005B93C: nop

        goto L_8005B97C;
    // 0x8005B93C: nop

L_8005B940:
    // 0x8005B940: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8005B944: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005B948: lw          $t7, 0xA4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA4);
    // 0x8005B94C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005B950: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x8005B954: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8005B958: lh          $a1, 0x7C($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X7C);
    // 0x8005B95C: lw          $a3, 0x44($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X44);
    // 0x8005B960: lh          $a2, -0x26A8($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X26A8);
    // 0x8005B964: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B968: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8005B96C: jal         0x8004F3E8
    // 0x8005B970: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_8004F3E8(rdram, ctx);
        goto after_4;
    // 0x8005B970: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_4:
    // 0x8005B974: b           L_8005B97C
    // 0x8005B978: nop

        goto L_8005B97C;
    // 0x8005B978: nop

L_8005B97C:
    // 0x8005B97C: b           L_8005B984
    // 0x8005B980: nop

        goto L_8005B984;
    // 0x8005B980: nop

L_8005B984:
    // 0x8005B984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005B988: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005B98C: jr          $ra
    // 0x8005B990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005B990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8007248C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007248C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072494: jal         0x80061488
    // 0x80072498: addiu       $a0, $zero, 0x51C
    ctx->r4 = ADD32(0, 0X51C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80072498: addiu       $a0, $zero, 0x51C
    ctx->r4 = ADD32(0, 0X51C);
    after_0:
    // 0x8007249C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800724A0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800724A4: b           L_800724B4
    // 0x800724A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800724B4;
    // 0x800724A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800724AC: b           L_800724B4
    // 0x800724B0: nop

        goto L_800724B4;
    // 0x800724B0: nop

L_800724B4:
    // 0x800724B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800724B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800724BC: jr          $ra
    // 0x800724C0: nop

    return;
    // 0x800724C0: nop

;}
RECOMP_FUNC void func_8006C720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C728: jal         0x8005F064
    // 0x8006C72C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C72C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_0:
    // 0x8006C730: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006C734: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006C738: beq         $v0, $zero, L_8006C750
    if (ctx->r2 == 0) {
        // 0x8006C73C: nop
    
            goto L_8006C750;
    }
    // 0x8006C73C: nop

    // 0x8006C740: jal         0x80061348
    // 0x8006C744: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006C744: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_1:
    // 0x8006C748: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C74C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006C750:
    // 0x8006C750: b           L_8006C760
    // 0x8006C754: nop

        goto L_8006C760;
    // 0x8006C754: nop

    // 0x8006C758: b           L_8006C760
    // 0x8006C75C: nop

        goto L_8006C760;
    // 0x8006C75C: nop

L_8006C760:
    // 0x8006C760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C768: jr          $ra
    // 0x8006C76C: nop

    return;
    // 0x8006C76C: nop

;}
RECOMP_FUNC void func_800BE4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE4EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BE4F0: lw          $t6, 0x2528($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2528);
    // 0x800BE4F4: nop

    // 0x800BE4F8: bne         $t6, $zero, L_800BE500
    if (ctx->r14 != 0) {
        // 0x800BE4FC: nop
    
            goto L_800BE500;
    }
    // 0x800BE4FC: nop

L_800BE500:
    // 0x800BE500: jr          $ra
    // 0x800BE504: nop

    return;
    // 0x800BE504: nop

    // 0x800BE508: jr          $ra
    // 0x800BE50C: nop

    return;
    // 0x800BE50C: nop

;}
RECOMP_FUNC void func_800B7510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7510: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B7514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B7518: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B751C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B7520: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800B7524:
    // 0x800B7524: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B7528: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B752C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7530: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7534: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7538: sh          $t7, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r15;
    // 0x800B753C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B7540: nop

    // 0x800B7544: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7548: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B754C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B7550: nop

    // 0x800B7554: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7558: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800B755C: bne         $at, $zero, L_800B7524
    if (ctx->r1 != 0) {
        // 0x800B7560: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_800B7524;
    }
    // 0x800B7560: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B7564: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B7568: lhu         $s0, 0x2($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0X2);
    // 0x800B756C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800B7570: beq         $s0, $at, L_800B758C
    if (ctx->r16 == ctx->r1) {
        // 0x800B7574: nop
    
            goto L_800B758C;
    }
    // 0x800B7574: nop

    // 0x800B7578: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800B757C: beq         $s0, $at, L_800B759C
    if (ctx->r16 == ctx->r1) {
        // 0x800B7580: nop
    
            goto L_800B759C;
    }
    // 0x800B7580: nop

    // 0x800B7584: b           L_800B75BC
    // 0x800B7588: nop

        goto L_800B75BC;
    // 0x800B7588: nop

L_800B758C:
    // 0x800B758C: jal         0x800B8FA8
    // 0x800B7590: nop

    AudioMgr_StopMusic(rdram, ctx);
        goto after_0;
    // 0x800B7590: nop

    after_0:
    // 0x800B7594: b           L_800B75CC
    // 0x800B7598: nop

        goto L_800B75CC;
    // 0x800B7598: nop

L_800B759C:
    // 0x800B759C: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B75A0: lhu         $a0, 0x4($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X4);
    // 0x800B75A4: nop

    // 0x800B75A8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800B75AC: jal         0x80021F20
    // 0x800B75B0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_1;
    // 0x800B75B0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800B75B4: b           L_800B75CC
    // 0x800B75B8: nop

        goto L_800B75CC;
    // 0x800B75B8: nop

L_800B75BC:
    // 0x800B75BC: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800B75C0: lhu         $a0, 0x2($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X2);
    // 0x800B75C4: jal         0x80021ED0
    // 0x800B75C8: nop

    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_2;
    // 0x800B75C8: nop

    after_2:
L_800B75CC:
    // 0x800B75CC: b           L_800B75DC
    // 0x800B75D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B75DC;
    // 0x800B75D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B75D4: b           L_800B75DC
    // 0x800B75D8: nop

        goto L_800B75DC;
    // 0x800B75D8: nop

L_800B75DC:
    // 0x800B75DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B75E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B75E4: jr          $ra
    // 0x800B75E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B75E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800779A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800779A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800779A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800779A8: nop

    // 0x800779AC: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x800779B0: nop

    // 0x800779B4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800779B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800779BC: jr          $ra
    // 0x800779C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800779C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800779C4: jr          $ra
    // 0x800779C8: nop

    return;
    // 0x800779C8: nop

    // 0x800779CC: jr          $ra
    // 0x800779D0: nop

    return;
    // 0x800779D0: nop

;}
