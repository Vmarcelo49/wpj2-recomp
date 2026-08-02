#include "recomp.h"
#include "shims.h"
#include "funcs.h"

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
RECOMP_FUNC void func_8007A514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A514: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A51C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007A520: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007A524: jal         0x80029ED8
    // 0x8007A528: nop

    func_80029ED8(rdram, ctx);
        goto after_0;
    // 0x8007A528: nop

    after_0:
    // 0x8007A52C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A530: nop

    // 0x8007A534: bltz        $t6, L_8007A620
    if (SIGNED(ctx->r14) < 0) {
        // 0x8007A538: nop
    
            goto L_8007A620;
    }
    // 0x8007A538: nop

    // 0x8007A53C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007A540: nop

    // 0x8007A544: bne         $t7, $zero, L_8007A564
    if (ctx->r15 != 0) {
        // 0x8007A548: nop
    
            goto L_8007A564;
    }
    // 0x8007A548: nop

    // 0x8007A54C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A550: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x8007A554: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007A558: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8007A55C: b           L_8007A578
    // 0x8007A560: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
        goto L_8007A578;
    // 0x8007A560: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
L_8007A564:
    // 0x8007A564: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007A568: nop

    // 0x8007A56C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8007A570: nop

    // 0x8007A574: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
L_8007A578:
    // 0x8007A578: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007A57C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007A580: nop

    // 0x8007A584: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x8007A588: nop

    // 0x8007A58C: beq         $t3, $zero, L_8007A5FC
    if (ctx->r11 == 0) {
        // 0x8007A590: nop
    
            goto L_8007A5FC;
    }
    // 0x8007A590: nop

L_8007A594:
    // 0x8007A594: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007A598: nop

    // 0x8007A59C: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x8007A5A0: nop

    // 0x8007A5A4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8007A5A8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007A5AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A5B0: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x8007A5B4: nop

    // 0x8007A5B8: bne         $t7, $at, L_8007A5E4
    if (ctx->r15 != ctx->r1) {
        // 0x8007A5BC: nop
    
            goto L_8007A5E4;
    }
    // 0x8007A5BC: nop

    // 0x8007A5C0: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8007A5C4: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8007A5C8: nop

    // 0x8007A5CC: beq         $t8, $t9, L_8007A5E4
    if (ctx->r24 == ctx->r25) {
        // 0x8007A5D0: nop
    
            goto L_8007A5E4;
    }
    // 0x8007A5D0: nop

    // 0x8007A5D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007A5D8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8007A5DC: b           L_8007A5FC
    // 0x8007A5E0: nop

        goto L_8007A5FC;
    // 0x8007A5E0: nop

L_8007A5E4:
    // 0x8007A5E4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A5E8: nop

    // 0x8007A5EC: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x8007A5F0: nop

    // 0x8007A5F4: bne         $t2, $zero, L_8007A594
    if (ctx->r10 != 0) {
        // 0x8007A5F8: nop
    
            goto L_8007A594;
    }
    // 0x8007A5F8: nop

L_8007A5FC:
    // 0x8007A5FC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007A600: nop

    // 0x8007A604: bne         $t3, $zero, L_8007A614
    if (ctx->r11 != 0) {
        // 0x8007A608: nop
    
            goto L_8007A614;
    }
    // 0x8007A608: nop

    // 0x8007A60C: b           L_8007A8A8
    // 0x8007A610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007A8A8;
    // 0x8007A610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A614:
    // 0x8007A614: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007A618: b           L_8007A8A8
    // 0x8007A61C: nop

        goto L_8007A8A8;
    // 0x8007A61C: nop

L_8007A620:
    // 0x8007A620: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007A624: nop

    // 0x8007A628: bne         $t4, $zero, L_8007A744
    if (ctx->r12 != 0) {
        // 0x8007A62C: nop
    
            goto L_8007A744;
    }
    // 0x8007A62C: nop

    // 0x8007A630: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A634: addiu       $t5, $t5, 0x2578
    ctx->r13 = ADD32(ctx->r13, 0X2578);
    // 0x8007A638: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8007A63C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007A640: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007A644: nop

    // 0x8007A648: lw          $t6, 0x18($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X18);
    // 0x8007A64C: nop

    // 0x8007A650: beq         $t6, $zero, L_8007A6AC
    if (ctx->r14 == 0) {
        // 0x8007A654: nop
    
            goto L_8007A6AC;
    }
    // 0x8007A654: nop

L_8007A658:
    // 0x8007A658: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007A65C: nop

    // 0x8007A660: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8007A664: nop

    // 0x8007A668: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007A66C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007A670: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A674: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x8007A678: nop

    // 0x8007A67C: bne         $t1, $at, L_8007A694
    if (ctx->r9 != ctx->r1) {
        // 0x8007A680: nop
    
            goto L_8007A694;
    }
    // 0x8007A680: nop

    // 0x8007A684: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007A688: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8007A68C: b           L_8007A6AC
    // 0x8007A690: nop

        goto L_8007A6AC;
    // 0x8007A690: nop

L_8007A694:
    // 0x8007A694: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007A698: nop

    // 0x8007A69C: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8007A6A0: nop

    // 0x8007A6A4: bne         $t4, $zero, L_8007A658
    if (ctx->r12 != 0) {
        // 0x8007A6A8: nop
    
            goto L_8007A658;
    }
    // 0x8007A6A8: nop

L_8007A6AC:
    // 0x8007A6AC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007A6B0: nop

    // 0x8007A6B4: bne         $t5, $zero, L_8007A6C4
    if (ctx->r13 != 0) {
        // 0x8007A6B8: nop
    
            goto L_8007A6C4;
    }
    // 0x8007A6B8: nop

    // 0x8007A6BC: b           L_8007A8A8
    // 0x8007A6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007A8A8;
    // 0x8007A6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A6C4:
    // 0x8007A6C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A6C8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007A6CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007A6D0: nop

    // 0x8007A6D4: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8007A6D8: nop

    // 0x8007A6DC: beq         $t8, $zero, L_8007A738
    if (ctx->r24 == 0) {
        // 0x8007A6E0: nop
    
            goto L_8007A738;
    }
    // 0x8007A6E0: nop

L_8007A6E4:
    // 0x8007A6E4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007A6E8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A6EC: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x8007A6F0: nop

    // 0x8007A6F4: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x8007A6F8: nop

    // 0x8007A6FC: beq         $t1, $at, L_8007A70C
    if (ctx->r9 == ctx->r1) {
        // 0x8007A700: nop
    
            goto L_8007A70C;
    }
    // 0x8007A700: nop

    // 0x8007A704: b           L_8007A738
    // 0x8007A708: nop

        goto L_8007A738;
    // 0x8007A708: nop

L_8007A70C:
    // 0x8007A70C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007A710: nop

    // 0x8007A714: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x8007A718: nop

    // 0x8007A71C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8007A720: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007A724: nop

    // 0x8007A728: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x8007A72C: nop

    // 0x8007A730: bne         $t5, $zero, L_8007A6E4
    if (ctx->r13 != 0) {
        // 0x8007A734: nop
    
            goto L_8007A6E4;
    }
    // 0x8007A734: nop

L_8007A738:
    // 0x8007A738: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8007A73C: b           L_8007A75C
    // 0x8007A740: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
        goto L_8007A75C;
    // 0x8007A740: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
L_8007A744:
    // 0x8007A744: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8007A748: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007A74C: nop

    // 0x8007A750: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8007A754: nop

    // 0x8007A758: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
L_8007A75C:
    // 0x8007A75C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A760: nop

    // 0x8007A764: beq         $t9, $zero, L_8007A778
    if (ctx->r25 == 0) {
        // 0x8007A768: nop
    
            goto L_8007A778;
    }
    // 0x8007A768: nop

    // 0x8007A76C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007A770: b           L_8007A814
    // 0x8007A774: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_8007A814;
    // 0x8007A774: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8007A778:
    // 0x8007A778: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007A77C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A780: nop

    // 0x8007A784: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8007A788: nop

    // 0x8007A78C: beq         $t2, $zero, L_8007A7FC
    if (ctx->r10 == 0) {
        // 0x8007A790: nop
    
            goto L_8007A7FC;
    }
    // 0x8007A790: nop

L_8007A794:
    // 0x8007A794: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007A798: nop

    // 0x8007A79C: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8007A7A0: nop

    // 0x8007A7A4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8007A7A8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8007A7AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A7B0: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x8007A7B4: nop

    // 0x8007A7B8: bne         $t7, $at, L_8007A7E4
    if (ctx->r15 != ctx->r1) {
        // 0x8007A7BC: nop
    
            goto L_8007A7E4;
    }
    // 0x8007A7BC: nop

    // 0x8007A7C0: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8007A7C4: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x8007A7C8: nop

    // 0x8007A7CC: beq         $t6, $t8, L_8007A7E4
    if (ctx->r14 == ctx->r24) {
        // 0x8007A7D0: nop
    
            goto L_8007A7E4;
    }
    // 0x8007A7D0: nop

    // 0x8007A7D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007A7D8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8007A7DC: b           L_8007A7FC
    // 0x8007A7E0: nop

        goto L_8007A7FC;
    // 0x8007A7E0: nop

L_8007A7E4:
    // 0x8007A7E4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007A7E8: nop

    // 0x8007A7EC: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8007A7F0: nop

    // 0x8007A7F4: bne         $t1, $zero, L_8007A794
    if (ctx->r9 != 0) {
        // 0x8007A7F8: nop
    
            goto L_8007A794;
    }
    // 0x8007A7F8: nop

L_8007A7FC:
    // 0x8007A7FC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8007A800: nop

    // 0x8007A804: bne         $t2, $zero, L_8007A814
    if (ctx->r10 != 0) {
        // 0x8007A808: nop
    
            goto L_8007A814;
    }
    // 0x8007A808: nop

    // 0x8007A80C: b           L_8007A8A8
    // 0x8007A810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007A8A8;
    // 0x8007A810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A814:
    // 0x8007A814: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007A818: nop

    // 0x8007A81C: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8007A820: nop

    // 0x8007A824: sh          $t4, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r12;
    // 0x8007A828: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007A82C: nop

    // 0x8007A830: lw          $t5, 0x14($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X14);
    // 0x8007A834: nop

    // 0x8007A838: beq         $t5, $zero, L_8007A894
    if (ctx->r13 == 0) {
        // 0x8007A83C: nop
    
            goto L_8007A894;
    }
    // 0x8007A83C: nop

L_8007A840:
    // 0x8007A840: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007A844: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x8007A848: lw          $t8, 0x14($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14);
    // 0x8007A84C: nop

    // 0x8007A850: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8007A854: nop

    // 0x8007A858: beq         $t9, $t0, L_8007A868
    if (ctx->r25 == ctx->r8) {
        // 0x8007A85C: nop
    
            goto L_8007A868;
    }
    // 0x8007A85C: nop

    // 0x8007A860: b           L_8007A894
    // 0x8007A864: nop

        goto L_8007A894;
    // 0x8007A864: nop

L_8007A868:
    // 0x8007A868: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A86C: nop

    // 0x8007A870: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8007A874: nop

    // 0x8007A878: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8007A87C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007A880: nop

    // 0x8007A884: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8007A888: nop

    // 0x8007A88C: bne         $t4, $zero, L_8007A840
    if (ctx->r12 != 0) {
        // 0x8007A890: nop
    
            goto L_8007A840;
    }
    // 0x8007A890: nop

L_8007A894:
    // 0x8007A894: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007A898: b           L_8007A8A8
    // 0x8007A89C: nop

        goto L_8007A8A8;
    // 0x8007A89C: nop

    // 0x8007A8A0: b           L_8007A8A8
    // 0x8007A8A4: nop

        goto L_8007A8A8;
    // 0x8007A8A4: nop

L_8007A8A8:
    // 0x8007A8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A8AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A8B0: jr          $ra
    // 0x8007A8B4: nop

    return;
    // 0x8007A8B4: nop

;}
RECOMP_FUNC void func_80065984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006598C: jal         0x80061488
    // 0x80065990: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065990: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    after_0:
    // 0x80065994: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80065998: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006599C: b           L_800659AC
    // 0x800659A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800659AC;
    // 0x800659A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800659A4: b           L_800659AC
    // 0x800659A8: nop

        goto L_800659AC;
    // 0x800659A8: nop

L_800659AC:
    // 0x800659AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800659B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800659B4: jr          $ra
    // 0x800659B8: nop

    return;
    // 0x800659B8: nop

;}
RECOMP_FUNC void func_80068888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068888: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006888C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068890: nop

    // 0x80068894: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80068898: nop

    // 0x8006889C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800688A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800688A4: jr          $ra
    // 0x800688A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800688A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800688AC: jr          $ra
    // 0x800688B0: nop

    return;
    // 0x800688B0: nop

    // 0x800688B4: jr          $ra
    // 0x800688B8: nop

    return;
    // 0x800688B8: nop

;}
RECOMP_FUNC void func_800B7500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7500: jr          $ra
    // 0x800B7504: nop

    return;
    // 0x800B7504: nop

    // 0x800B7508: jr          $ra
    // 0x800B750C: nop

    return;
    // 0x800B750C: nop

;}
RECOMP_FUNC void func_800720FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800720FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072104: jal         0x80061348
    // 0x80072108: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80072108: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x8007210C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80072110: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072114: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072118: beq         $v0, $zero, L_80072150
    if (ctx->r2 == 0) {
        // 0x8007211C: nop
    
            goto L_80072150;
    }
    // 0x8007211C: nop

    // 0x80072120: jal         0x80061348
    // 0x80072124: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80072124: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x80072128: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007212C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80072130: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072134: beq         $v0, $zero, L_80072150
    if (ctx->r2 == 0) {
        // 0x80072138: nop
    
            goto L_80072150;
    }
    // 0x80072138: nop

    // 0x8007213C: jal         0x80061348
    // 0x80072140: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80072140: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x80072144: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80072148: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007214C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80072150:
    // 0x80072150: b           L_80072160
    // 0x80072154: nop

        goto L_80072160;
    // 0x80072154: nop

    // 0x80072158: b           L_80072160
    // 0x8007215C: nop

        goto L_80072160;
    // 0x8007215C: nop

L_80072160:
    // 0x80072160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072168: jr          $ra
    // 0x8007216C: nop

    return;
    // 0x8007216C: nop

;}
RECOMP_FUNC void func_8006329C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006329C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800632A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800632A4: jal         0x80061488
    // 0x800632A8: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800632A8: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    after_0:
    // 0x800632AC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800632B0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800632B4: b           L_800632C4
    // 0x800632B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800632C4;
    // 0x800632B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800632BC: b           L_800632C4
    // 0x800632C0: nop

        goto L_800632C4;
    // 0x800632C0: nop

L_800632C4:
    // 0x800632C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800632C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800632CC: jr          $ra
    // 0x800632D0: nop

    return;
    // 0x800632D0: nop

;}
RECOMP_FUNC void func_800670A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800670A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800670AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800670B0: nop

    // 0x800670B4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800670B8: nop

    // 0x800670BC: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x800670C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800670C4: jr          $ra
    // 0x800670C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800670C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800670CC: jr          $ra
    // 0x800670D0: nop

    return;
    // 0x800670D0: nop

    // 0x800670D4: jr          $ra
    // 0x800670D8: nop

    return;
    // 0x800670D8: nop

;}
RECOMP_FUNC void func_80072E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072E8C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072E90: nop

    // 0x80072E94: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072E98: nop

    // 0x80072E9C: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x80072EA0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072EA4: jr          $ra
    // 0x80072EA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072EA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072EAC: jr          $ra
    // 0x80072EB0: nop

    return;
    // 0x80072EB0: nop

    // 0x80072EB4: jr          $ra
    // 0x80072EB8: nop

    return;
    // 0x80072EB8: nop

;}
RECOMP_FUNC void func_800668D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800668D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800668D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800668DC: jal         0x80061348
    // 0x800668E0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800668E0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800668E4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800668E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800668EC: beq         $v0, $zero, L_80066904
    if (ctx->r2 == 0) {
        // 0x800668F0: nop
    
            goto L_80066904;
    }
    // 0x800668F0: nop

    // 0x800668F4: jal         0x80061348
    // 0x800668F8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800668F8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x800668FC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066900: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066904:
    // 0x80066904: b           L_80066914
    // 0x80066908: nop

        goto L_80066914;
    // 0x80066908: nop

    // 0x8006690C: b           L_80066914
    // 0x80066910: nop

        goto L_80066914;
    // 0x80066910: nop

L_80066914:
    // 0x80066914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006691C: jr          $ra
    // 0x80066920: nop

    return;
    // 0x80066920: nop

;}
RECOMP_FUNC void alMainBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D00B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D00B4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D00B8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D00BC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D00C0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D00C4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D00C8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D00CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D00D0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D00D4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D00D8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D00DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D00E0: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800D00E4: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800D00E8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800D00EC: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800D00F0: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x800D00F4: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x800D00F8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800D00FC: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800D0100: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800D0104: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800D0108: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800D010C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800D0110: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800D0114: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x800D0118: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D011C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D0120: blez        $t8, L_800D019C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800D0124: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_800D019C;
    }
    // 0x800D0124: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x800D0128: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x800D012C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x800D0130: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800D0134: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_800D0138:
    // 0x800D0138: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800D013C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800D0140: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D0144: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800D0148: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800D014C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800D0150: jalr        $t9
    // 0x800D0154: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D0154: nop

    after_0:
    // 0x800D0158: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800D015C: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800D0160: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x800D0164: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x800D0168: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x800D016C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800D0170: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x800D0174: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800D0178: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x800D017C: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800D0180: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x800D0184: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x800D0188: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D018C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800D0190: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800D0194: bne         $at, $zero, L_800D0138
    if (ctx->r1 != 0) {
        // 0x800D0198: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_800D0138;
    }
    // 0x800D0198: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_800D019C:
    // 0x800D019C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D01A0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800D01A4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D01A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D01AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D01B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D01B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D01B8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D01BC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D01C0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D01C4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D01C8: jr          $ra
    // 0x800D01CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D01CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800759A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800759A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800759A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800759AC: jal         0x80061348
    // 0x800759B0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800759B0: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x800759B4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800759B8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800759BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800759C0: beq         $v0, $zero, L_80075A14
    if (ctx->r2 == 0) {
        // 0x800759C4: nop
    
            goto L_80075A14;
    }
    // 0x800759C4: nop

    // 0x800759C8: jal         0x80061348
    // 0x800759CC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800759CC: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x800759D0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800759D4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800759D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800759DC: beq         $v0, $zero, L_80075A14
    if (ctx->r2 == 0) {
        // 0x800759E0: nop
    
            goto L_80075A14;
    }
    // 0x800759E0: nop

    // 0x800759E4: jal         0x80061348
    // 0x800759E8: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800759E8: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x800759EC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800759F0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800759F4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800759F8: beq         $v0, $zero, L_80075A14
    if (ctx->r2 == 0) {
        // 0x800759FC: nop
    
            goto L_80075A14;
    }
    // 0x800759FC: nop

    // 0x80075A00: jal         0x80061348
    // 0x80075A04: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075A04: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075A08: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075A0C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075A10: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075A14:
    // 0x80075A14: b           L_80075A24
    // 0x80075A18: nop

        goto L_80075A24;
    // 0x80075A18: nop

    // 0x80075A1C: b           L_80075A24
    // 0x80075A20: nop

        goto L_80075A24;
    // 0x80075A20: nop

L_80075A24:
    // 0x80075A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075A2C: jr          $ra
    // 0x80075A30: nop

    return;
    // 0x80075A30: nop

;}
RECOMP_FUNC void alSynSetFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D42B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D42B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D42B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D42BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D42C0: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D42C4: beql        $t6, $zero, L_800D4338
    if (ctx->r14 == 0) {
        // 0x800D42C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D4338;
    }
    goto skip_0;
    // 0x800D42C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D42CC: jal         0x800C7C00
    // 0x800D42D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D42D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D42D4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D42D8: beq         $v0, $zero, L_800D4334
    if (ctx->r2 == 0) {
        // 0x800D42DC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D4334;
    }
    // 0x800D42DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D42E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D42E4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D42E8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800D42EC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D42F0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D42F4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D42F8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D42FC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D4300: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x800D4304: bgez        $v1, L_800D4314
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D4308: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_800D4314;
    }
    // 0x800D4308: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800D430C: b           L_800D4318
    // 0x800D4310: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_800D4318;
    // 0x800D4310: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_800D4314:
    // 0x800D4314: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800D4318:
    // 0x800D4318: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D431C: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800D4320: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D4324: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800D4328: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D432C: jalr        $t9
    // 0x800D4330: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D4330: nop

    after_1:
L_800D4334:
    // 0x800D4334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4338:
    // 0x800D4338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D433C: jr          $ra
    // 0x800D4340: nop

    return;
    // 0x800D4340: nop

;}
RECOMP_FUNC void func_8007289C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007289C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800728A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800728A4: nop

    // 0x800728A8: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x800728AC: nop

    // 0x800728B0: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x800728B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800728B8: jr          $ra
    // 0x800728BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800728BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800728C0: jr          $ra
    // 0x800728C4: nop

    return;
    // 0x800728C4: nop

    // 0x800728C8: jr          $ra
    // 0x800728CC: nop

    return;
    // 0x800728CC: nop

;}
RECOMP_FUNC void func_80065D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065D34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065D38: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065D3C: nop

    // 0x80065D40: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80065D44: nop

    // 0x80065D48: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065D4C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065D50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065D54: beq         $v0, $zero, L_80065D6C
    if (ctx->r2 == 0) {
        // 0x80065D58: nop
    
            goto L_80065D6C;
    }
    // 0x80065D58: nop

    // 0x80065D5C: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80065D60: nop

    // 0x80065D64: slti        $t8, $v0, 0x321
    ctx->r24 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80065D68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065D6C:
    // 0x80065D6C: jr          $ra
    // 0x80065D70: nop

    return;
    // 0x80065D70: nop

    // 0x80065D74: jr          $ra
    // 0x80065D78: nop

    return;
    // 0x80065D78: nop

    // 0x80065D7C: jr          $ra
    // 0x80065D80: nop

    return;
    // 0x80065D80: nop

;}
RECOMP_FUNC void func_80075D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075D0C: jal         0x80061488
    // 0x80075D10: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80075D10: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    after_0:
    // 0x80075D14: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80075D18: b           L_80075D28
    // 0x80075D1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075D28;
    // 0x80075D1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075D20: b           L_80075D28
    // 0x80075D24: nop

        goto L_80075D28;
    // 0x80075D24: nop

L_80075D28:
    // 0x80075D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075D30: jr          $ra
    // 0x80075D34: nop

    return;
    // 0x80075D34: nop

;}
RECOMP_FUNC void func_80063370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063378: jal         0x80061488
    // 0x8006337C: addiu       $a0, $zero, 0x612
    ctx->r4 = ADD32(0, 0X612);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006337C: addiu       $a0, $zero, 0x612
    ctx->r4 = ADD32(0, 0X612);
    after_0:
    // 0x80063380: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063384: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063388: b           L_80063398
    // 0x8006338C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063398;
    // 0x8006338C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063390: b           L_80063398
    // 0x80063394: nop

        goto L_80063398;
    // 0x80063394: nop

L_80063398:
    // 0x80063398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006339C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800633A0: jr          $ra
    // 0x800633A4: nop

    return;
    // 0x800633A4: nop

;}
RECOMP_FUNC void func_800A19B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A19B0: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x800A19B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A19B8: sw          $a0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r4;
    // 0x800A19BC: sw          $a1, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r5;
    // 0x800A19C0: sw          $a2, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r6;
    // 0x800A19C4: sw          $a3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r7;
    // 0x800A19C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A19CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A19D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A19D4: jal         0x800C1680
    // 0x800A19D8: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800A19D8: nop

    after_0:
    // 0x800A19DC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A19E0: jal         0x800C1AF4
    // 0x800A19E4: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_1;
    // 0x800A19E4: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    after_1:
    // 0x800A19E8: jal         0x800C1B64
    // 0x800A19EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C1B64(rdram, ctx);
        goto after_2;
    // 0x800A19EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800A19F0: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x800A19F4: jal         0x800C1D44
    // 0x800A19F8: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    func_800C1D44(rdram, ctx);
        goto after_3;
    // 0x800A19F8: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_3:
    // 0x800A19FC: lw          $a0, 0x194($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X194);
    // 0x800A1A00: jal         0x800C1D44
    // 0x800A1A04: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_4;
    // 0x800A1A04: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_4:
    // 0x800A1A08: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A1A0C: jal         0x800C1A84
    // 0x800A1A10: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_5;
    // 0x800A1A10: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_5:
    // 0x800A1A14: jal         0x800C1A28
    // 0x800A1A18: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x800A1A18: nop

    after_6:
    // 0x800A1A1C: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x800A1A20: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A1A24: lw          $t8, 0x7250($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7250);
    // 0x800A1A28: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800A1A2C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A1A30: lw          $t0, 0x7258($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7258);
    // 0x800A1A34: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800A1A38: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800A1A3C: sw          $t1, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r9;
    // 0x800A1A40: lw          $t2, 0x180($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X180);
    // 0x800A1A44: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800A1A48: ori         $at, $at, 0x200
    ctx->r1 = ctx->r1 | 0X200;
    // 0x800A1A4C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A1A50: bne         $t3, $zero, L_800A1A90
    if (ctx->r11 != 0) {
        // 0x800A1A54: nop
    
            goto L_800A1A90;
    }
    // 0x800A1A54: nop

    // 0x800A1A58: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800A1A5C: addiu       $t4, $t4, 0x6BC8
    ctx->r12 = ADD32(ctx->r12, 0X6BC8);
    // 0x800A1A60: lwc1        $f4, 0x38($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X38);
    // 0x800A1A64: lw          $a0, 0x190($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X190);
    // 0x800A1A68: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A1A6C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A1A70: jal         0x8009A084
    // 0x800A1A74: nop

    func_8009A084(rdram, ctx);
        goto after_7;
    // 0x800A1A74: nop

    after_7:
    // 0x800A1A78: bgez        $v0, L_800A1A88
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A1A7C: nop
    
            goto L_800A1A88;
    }
    // 0x800A1A7C: nop

    // 0x800A1A80: b           L_800A3900
    // 0x800A1A84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A3900;
    // 0x800A1A84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A1A88:
    // 0x800A1A88: b           L_800A1B30
    // 0x800A1A8C: nop

        goto L_800A1B30;
    // 0x800A1A8C: nop

L_800A1A90:
    // 0x800A1A90: lw          $t5, 0x180($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X180);
    // 0x800A1A94: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800A1A98: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800A1A9C: beq         $t6, $zero, L_800A1ADC
    if (ctx->r14 == 0) {
        // 0x800A1AA0: nop
    
            goto L_800A1ADC;
    }
    // 0x800A1AA0: nop

    // 0x800A1AA4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800A1AA8: addiu       $t7, $t7, 0x6BC8
    ctx->r15 = ADD32(ctx->r15, 0X6BC8);
    // 0x800A1AAC: lwc1        $f8, 0x38($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X38);
    // 0x800A1AB0: lw          $a0, 0x190($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X190);
    // 0x800A1AB4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A1AB8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A1ABC: jal         0x8009A084
    // 0x800A1AC0: nop

    func_8009A084(rdram, ctx);
        goto after_8;
    // 0x800A1AC0: nop

    after_8:
    // 0x800A1AC4: bgez        $v0, L_800A1AD4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A1AC8: nop
    
            goto L_800A1AD4;
    }
    // 0x800A1AC8: nop

    // 0x800A1ACC: b           L_800A3900
    // 0x800A1AD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A3900;
    // 0x800A1AD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A1AD4:
    // 0x800A1AD4: b           L_800A1B30
    // 0x800A1AD8: nop

        goto L_800A1B30;
    // 0x800A1AD8: nop

L_800A1ADC:
    // 0x800A1ADC: lw          $t8, 0x180($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X180);
    // 0x800A1AE0: nop

    // 0x800A1AE4: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x800A1AE8: beq         $t9, $zero, L_800A1B30
    if (ctx->r25 == 0) {
        // 0x800A1AEC: nop
    
            goto L_800A1B30;
    }
    // 0x800A1AEC: nop

    // 0x800A1AF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A1AF4: lwc1        $f16, 0x25A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25A8);
    // 0x800A1AF8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800A1AFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A1B00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A1B04: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A1B08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A1B0C: lw          $a0, 0x190($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X190);
    // 0x800A1B10: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1B14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A1B18: jal         0x8009A084
    // 0x800A1B1C: nop

    func_8009A084(rdram, ctx);
        goto after_9;
    // 0x800A1B1C: nop

    after_9:
    // 0x800A1B20: bgez        $v0, L_800A1B30
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A1B24: nop
    
            goto L_800A1B30;
    }
    // 0x800A1B24: nop

    // 0x800A1B28: b           L_800A3900
    // 0x800A1B2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A3900;
    // 0x800A1B2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A1B30:
    // 0x800A1B30: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x800A1B34: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x800A1B38: lh          $t1, 0x11E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X11E);
    // 0x800A1B3C: lwc1        $f18, 0xE8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x800A1B40: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A1B44: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1B48: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A1B4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A1B50: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A1B54: nop

    // 0x800A1B58: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1B5C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A1B60: nop

    // 0x800A1B64: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A1B68: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1B6C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1B70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A1B74: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1B78: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A1B7C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A1B80: sh          $t4, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r12;
    // 0x800A1B84: nop

    // 0x800A1B88: jal         0x800C1680
    // 0x800A1B8C: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_10;
    // 0x800A1B8C: nop

    after_10:
    // 0x800A1B90: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x800A1B94: jal         0x800C1AF4
    // 0x800A1B98: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_11;
    // 0x800A1B98: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_11:
    // 0x800A1B9C: lw          $a0, 0x194($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X194);
    // 0x800A1BA0: jal         0x800C1D44
    // 0x800A1BA4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_12;
    // 0x800A1BA4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_12:
    // 0x800A1BA8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A1BAC: jal         0x800C1A84
    // 0x800A1BB0: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_13;
    // 0x800A1BB0: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_13:
    // 0x800A1BB4: jal         0x800C1A28
    // 0x800A1BB8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_14;
    // 0x800A1BB8: nop

    after_14:
    // 0x800A1BBC: lw          $t5, 0x190($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X190);
    // 0x800A1BC0: nop

    // 0x800A1BC4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A1BC8: nop

    // 0x800A1BCC: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A1BD0: lwc1        $f16, 0x1A0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x800A1BD4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A1BD8: nop

    // 0x800A1BDC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A1BE0: nop

    // 0x800A1BE4: bc1f        L_800A1BFC
    if (!c1cs) {
        // 0x800A1BE8: nop
    
            goto L_800A1BFC;
    }
    // 0x800A1BE8: nop

    // 0x800A1BEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1BF0: lwc1        $f4, -0x7B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7B4);
    // 0x800A1BF4: nop

    // 0x800A1BF8: swc1        $f4, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->f4.u32l;
L_800A1BFC:
    // 0x800A1BFC: lwc1        $f6, 0x1A4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x800A1C00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A1C04: nop

    // 0x800A1C08: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800A1C0C: nop

    // 0x800A1C10: bc1f        L_800A1C28
    if (!c1cs) {
        // 0x800A1C14: nop
    
            goto L_800A1C28;
    }
    // 0x800A1C14: nop

    // 0x800A1C18: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1C1C: lwc1        $f10, -0x7B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7B0);
    // 0x800A1C20: nop

    // 0x800A1C24: swc1        $f10, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->f10.u32l;
L_800A1C28:
    // 0x800A1C28: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x800A1C2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A1C30: lwc1        $f16, 0xF4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x800A1C34: lwc1        $f18, 0xFC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x800A1C38: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A1C3C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A1C40: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800A1C44: addiu       $t8, $t8, 0x6BC8
    ctx->r24 = ADD32(ctx->r24, 0X6BC8);
    // 0x800A1C48: lwc1        $f10, 0x38($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X38);
    // 0x800A1C4C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1C50: nop

    // 0x800A1C54: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1C58: swc1        $f16, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f16.u32l;
    // 0x800A1C5C: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x800A1C60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A1C64: lwc1        $f18, 0xF8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x800A1C68: lwc1        $f4, 0xFC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XFC);
    // 0x800A1C6C: lwc1        $f8, 0x7218($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A1C70: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A1C74: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800A1C78: addiu       $t0, $t0, 0x6BC8
    ctx->r8 = ADD32(ctx->r8, 0X6BC8);
    // 0x800A1C7C: lwc1        $f16, 0x38($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X38);
    // 0x800A1C80: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A1C84: nop

    // 0x800A1C88: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A1C8C: swc1        $f18, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f18.u32l;
    // 0x800A1C90: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800A1C94: addiu       $t1, $t1, 0x6BC8
    ctx->r9 = ADD32(ctx->r9, 0X6BC8);
    // 0x800A1C98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A1C9C: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A1CA0: lwc1        $f6, 0x38($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X38);
    // 0x800A1CA4: nop

    // 0x800A1CA8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1CAC: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x800A1CB0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1CB4: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800A1CB8: lwc1        $f19, -0x7A8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X7A8);
    // 0x800A1CBC: lwc1        $f18, -0x7A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7A4);
    // 0x800A1CC0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800A1CC4: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x800A1CC8: nop

    // 0x800A1CCC: bc1f        L_800A1D04
    if (!c1cs) {
        // 0x800A1CD0: nop
    
            goto L_800A1D04;
    }
    // 0x800A1CD0: nop

    // 0x800A1CD4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1CD8: lwc1        $f5, -0x7A0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X7A0);
    // 0x800A1CDC: lwc1        $f4, -0x79C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X79C);
    // 0x800A1CE0: nop

    // 0x800A1CE4: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x800A1CE8: nop

    // 0x800A1CEC: bc1f        L_800A1D04
    if (!c1cs) {
        // 0x800A1CF0: nop
    
            goto L_800A1D04;
    }
    // 0x800A1CF0: nop

    // 0x800A1CF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A1CF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A1CFC: nop

    // 0x800A1D00: swc1        $f6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f6.u32l;
L_800A1D04:
    // 0x800A1D04: lwc1        $f8, 0x124($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800A1D08: nop

    // 0x800A1D0C: swc1        $f8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f8.u32l;
    // 0x800A1D10: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800A1D14: nop

    // 0x800A1D18: swc1        $f10, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f10.u32l;
    // 0x800A1D1C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800A1D20: addiu       $t2, $t2, 0x6BC8
    ctx->r10 = ADD32(ctx->r10, 0X6BC8);
    // 0x800A1D24: lwc1        $f18, 0x30($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X30);
    // 0x800A1D28: lwc1        $f16, 0x124($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800A1D2C: lwc1        $f6, 0x1A0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x800A1D30: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A1D34: nop

    // 0x800A1D38: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1D3C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A1D40: nop

    // 0x800A1D44: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A1D48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1D4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1D50: nop

    // 0x800A1D54: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1D58: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A1D5C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A1D60: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800A1D64: nop

    // 0x800A1D68: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A1D6C: swc1        $f16, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f16.u32l;
    // 0x800A1D70: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800A1D74: addiu       $t5, $t5, 0x6BC8
    ctx->r13 = ADD32(ctx->r13, 0X6BC8);
    // 0x800A1D78: lwc1        $f4, 0x34($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X34);
    // 0x800A1D7C: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800A1D80: lwc1        $f10, 0x1A4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x800A1D84: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A1D88: nop

    // 0x800A1D8C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1D90: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A1D94: nop

    // 0x800A1D98: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A1D9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1DA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1DA4: nop

    // 0x800A1DA8: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A1DAC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800A1DB0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1DB4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800A1DB8: nop

    // 0x800A1DBC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A1DC0: swc1        $f6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f6.u32l;
    // 0x800A1DC4: lw          $t8, 0x180($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X180);
    // 0x800A1DC8: nop

    // 0x800A1DCC: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x800A1DD0: beq         $t9, $zero, L_800A1E48
    if (ctx->r25 == 0) {
        // 0x800A1DD4: nop
    
            goto L_800A1E48;
    }
    // 0x800A1DD4: nop

    // 0x800A1DD8: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x800A1DDC: nop

    // 0x800A1DE0: lwc1        $f8, 0xF4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XF4);
    // 0x800A1DE4: lwc1        $f10, 0xFC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XFC);
    // 0x800A1DE8: nop

    // 0x800A1DEC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1DF0: swc1        $f18, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f18.u32l;
    // 0x800A1DF4: lw          $t1, 0x194($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X194);
    // 0x800A1DF8: nop

    // 0x800A1DFC: lwc1        $f16, 0xF8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x800A1E00: lwc1        $f4, 0xFC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XFC);
    // 0x800A1E04: nop

    // 0x800A1E08: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800A1E0C: swc1        $f6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f6.u32l;
    // 0x800A1E10: lw          $t2, 0x194($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X194);
    // 0x800A1E14: nop

    // 0x800A1E18: lwc1        $f8, 0xF4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XF4);
    // 0x800A1E1C: lwc1        $f10, 0xFC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XFC);
    // 0x800A1E20: nop

    // 0x800A1E24: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1E28: swc1        $f18, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f18.u32l;
    // 0x800A1E2C: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x800A1E30: nop

    // 0x800A1E34: lwc1        $f16, 0xF8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XF8);
    // 0x800A1E38: lwc1        $f4, 0xFC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XFC);
    // 0x800A1E3C: nop

    // 0x800A1E40: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800A1E44: swc1        $f6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f6.u32l;
L_800A1E48:
    // 0x800A1E48: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A1E4C: lwc1        $f10, 0x1A0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x800A1E50: nop

    // 0x800A1E54: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1E58: swc1        $f18, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f18.u32l;
    // 0x800A1E5C: lwc1        $f16, 0x138($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800A1E60: lwc1        $f4, 0x1A4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x800A1E64: nop

    // 0x800A1E68: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800A1E6C: swc1        $f6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f6.u32l;
    // 0x800A1E70: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A1E74: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A1E78: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A1E7C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A1E80: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800A1E84: nop

    // 0x800A1E88: div.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f18.d);
    // 0x800A1E8C: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800A1E90: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A1E94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A1E98: nop

    // 0x800A1E9C: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x800A1EA0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A1EA4: nop

    // 0x800A1EA8: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A1EAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1EB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1EB4: nop

    // 0x800A1EB8: cvt.w.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_D(ctx->f6.d);
    // 0x800A1EBC: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800A1EC0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A1EC4: sh          $t5, 0x15E($sp)
    MEM_H(0X15E, ctx->r29) = ctx->r13;
    // 0x800A1EC8: nop

    // 0x800A1ECC: lwc1        $f18, 0x138($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800A1ED0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A1ED4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A1ED8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A1EDC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800A1EE0: nop

    // 0x800A1EE4: div.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f16.d);
    // 0x800A1EE8: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800A1EEC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A1EF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A1EF4: nop

    // 0x800A1EF8: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800A1EFC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A1F00: nop

    // 0x800A1F04: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A1F08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1F0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1F10: nop

    // 0x800A1F14: cvt.w.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_D(ctx->f10.d);
    // 0x800A1F18: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800A1F1C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1F20: sh          $t7, 0x15C($sp)
    MEM_H(0X15C, ctx->r29) = ctx->r15;
    // 0x800A1F24: nop

    // 0x800A1F28: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x800A1F2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A1F30: lh          $t9, 0x116($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X116);
    // 0x800A1F34: nop

    // 0x800A1F38: bne         $t9, $at, L_800A1F48
    if (ctx->r25 != ctx->r1) {
        // 0x800A1F3C: nop
    
            goto L_800A1F48;
    }
    // 0x800A1F3C: nop

    // 0x800A1F40: b           L_800A3900
    // 0x800A1F44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A3900;
    // 0x800A1F44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A1F48:
    // 0x800A1F48: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x800A1F4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A1F50: lw          $t1, 0x128($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X128);
    // 0x800A1F54: nop

    // 0x800A1F58: sw          $t1, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r9;
    // 0x800A1F5C: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1F60: nop

    // 0x800A1F64: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A1F68: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A1F6C: sw          $t2, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r10;
    // 0x800A1F70: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    // 0x800A1F74: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800A1F78: ori         $t4, $t4, 0x1402
    ctx->r12 = ctx->r12 | 0X1402;
    // 0x800A1F7C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A1F80: lw          $t6, 0x11C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X11C);
    // 0x800A1F84: nop

    // 0x800A1F88: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A1F8C: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1F90: nop

    // 0x800A1F94: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A1F98: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A1F9C: sw          $t7, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r15;
    // 0x800A1FA0: lw          $t0, 0x118($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X118);
    // 0x800A1FA4: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x800A1FA8: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x800A1FAC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A1FB0: lw          $t2, 0x118($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X118);
    // 0x800A1FB4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800A1FB8: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x800A1FBC: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A1FC0: lw          $t3, 0x180($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X180);
    // 0x800A1FC4: nop

    // 0x800A1FC8: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x800A1FCC: beq         $t4, $zero, L_800A2078
    if (ctx->r12 == 0) {
        // 0x800A1FD0: nop
    
            goto L_800A2078;
    }
    // 0x800A1FD0: nop

    // 0x800A1FD4: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A1FD8: nop

    // 0x800A1FDC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A1FE0: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A1FE4: sw          $t5, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r13;
    // 0x800A1FE8: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x800A1FEC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800A1FF0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A1FF4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800A1FF8: lh          $t9, -0x4CDC($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4CDC);
    // 0x800A1FFC: lw          $t1, 0x114($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X114);
    // 0x800A2000: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800A2004: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A2008: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A200C: nop

    // 0x800A2010: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A2014: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A2018: sw          $t2, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r10;
    // 0x800A201C: lw          $t5, 0x110($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X110);
    // 0x800A2020: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x800A2024: ori         $t4, $t4, 0x97FF
    ctx->r12 = ctx->r12 | 0X97FF;
    // 0x800A2028: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A202C: lw          $t7, 0x110($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X110);
    // 0x800A2030: lui         $t6, 0xFF2C
    ctx->r14 = S32(0XFF2C << 16);
    // 0x800A2034: ori         $t6, $t6, 0xFE7F
    ctx->r14 = ctx->r14 | 0XFE7F;
    // 0x800A2038: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A203C: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2040: nop

    // 0x800A2044: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A2048: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A204C: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x800A2050: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
    // 0x800A2054: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x800A2058: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x800A205C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A2060: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    // 0x800A2064: lui         $t2, 0xF0A
    ctx->r10 = S32(0XF0A << 16);
    // 0x800A2068: ori         $t2, $t2, 0x233
    ctx->r10 = ctx->r10 | 0X233;
    // 0x800A206C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A2070: b           L_800A2198
    // 0x800A2074: nop

        goto L_800A2198;
    // 0x800A2074: nop

L_800A2078:
    // 0x800A2078: lw          $t4, 0x180($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X180);
    // 0x800A207C: nop

    // 0x800A2080: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x800A2084: beq         $t5, $zero, L_800A2130
    if (ctx->r13 == 0) {
        // 0x800A2088: nop
    
            goto L_800A2130;
    }
    // 0x800A2088: nop

    // 0x800A208C: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2090: nop

    // 0x800A2094: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A2098: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A209C: sw          $t6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r14;
    // 0x800A20A0: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800A20A4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A20A8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A20AC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800A20B0: lh          $t0, -0x4CDC($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CDC);
    // 0x800A20B4: lw          $t2, 0x108($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X108);
    // 0x800A20B8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800A20BC: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A20C0: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A20C4: nop

    // 0x800A20C8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A20CC: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A20D0: sw          $t3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r11;
    // 0x800A20D4: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800A20D8: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x800A20DC: ori         $t5, $t5, 0x97FF
    ctx->r13 = ctx->r13 | 0X97FF;
    // 0x800A20E0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A20E4: lw          $t8, 0x104($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X104);
    // 0x800A20E8: lui         $t7, 0xFF2C
    ctx->r15 = S32(0XFF2C << 16);
    // 0x800A20EC: ori         $t7, $t7, 0xFE7F
    ctx->r15 = ctx->r15 | 0XFE7F;
    // 0x800A20F0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A20F4: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A20F8: nop

    // 0x800A20FC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A2100: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A2104: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x800A2108: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x800A210C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x800A2110: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x800A2114: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A2118: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x800A211C: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x800A2120: ori         $t3, $t3, 0x4A50
    ctx->r11 = ctx->r11 | 0X4A50;
    // 0x800A2124: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A2128: b           L_800A2198
    // 0x800A212C: nop

        goto L_800A2198;
    // 0x800A212C: nop

L_800A2130:
    // 0x800A2130: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2134: nop

    // 0x800A2138: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A213C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A2140: sw          $t5, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r13;
    // 0x800A2144: lw          $t8, 0xFC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XFC);
    // 0x800A2148: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x800A214C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800A2150: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A2154: lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XFC);
    // 0x800A2158: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x800A215C: ori         $t9, $t9, 0xF279
    ctx->r25 = ctx->r25 | 0XF279;
    // 0x800A2160: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A2164: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2168: nop

    // 0x800A216C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A2170: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A2174: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x800A2178: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x800A217C: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A2180: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x800A2184: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A2188: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    // 0x800A218C: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x800A2190: ori         $t5, $t5, 0x3078
    ctx->r13 = ctx->r13 | 0X3078;
    // 0x800A2194: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_800A2198:
    // 0x800A2198: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A219C: nop

    // 0x800A21A0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A21A4: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A21A8: sw          $t7, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r15;
    // 0x800A21AC: lw          $t0, 0xF4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF4);
    // 0x800A21B0: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x800A21B4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A21B8: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800A21BC: addiu       $t1, $zero, 0x205
    ctx->r9 = ADD32(0, 0X205);
    // 0x800A21C0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A21C4: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A21C8: nop

    // 0x800A21CC: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A21D0: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A21D4: sw          $t3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r11;
    // 0x800A21D8: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x800A21DC: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A21E0: ori         $t5, $t5, 0x1301
    ctx->r13 = ctx->r13 | 0X1301;
    // 0x800A21E4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A21E8: lw          $t7, 0xF0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF0);
    // 0x800A21EC: nop

    // 0x800A21F0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A21F4: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A21F8: nop

    // 0x800A21FC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A2200: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A2204: sw          $t8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r24;
    // 0x800A2208: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x800A220C: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x800A2210: ori         $t0, $t0, 0x1102
    ctx->r8 = ctx->r8 | 0X1102;
    // 0x800A2214: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A2218: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x800A221C: nop

    // 0x800A2220: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800A2224: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2228: nop

    // 0x800A222C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A2230: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A2234: sw          $t3, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r11;
    // 0x800A2238: lw          $t6, 0xE8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE8);
    // 0x800A223C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A2240: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x800A2244: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A2248: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x800A224C: nop

    // 0x800A2250: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A2254: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x800A2258: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A225C: lh          $t9, 0x116($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X116);
    // 0x800A2260: nop

    // 0x800A2264: beq         $t9, $at, L_800A24F4
    if (ctx->r25 == ctx->r1) {
        // 0x800A2268: nop
    
            goto L_800A24F4;
    }
    // 0x800A2268: nop

    // 0x800A226C: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x800A2270: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A2274: lh          $t1, 0x116($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X116);
    // 0x800A2278: nop

    // 0x800A227C: bne         $t1, $at, L_800A23A4
    if (ctx->r9 != ctx->r1) {
        // 0x800A2280: nop
    
            goto L_800A23A4;
    }
    // 0x800A2280: nop

    // 0x800A2284: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2288: nop

    // 0x800A228C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A2290: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A2294: sw          $t2, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r10;
    // 0x800A2298: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x800A229C: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x800A22A0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A22A4: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x800A22A8: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x800A22AC: lw          $t7, 0x138($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X138);
    // 0x800A22B0: nop

    // 0x800A22B4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A22B8: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A22BC: nop

    // 0x800A22C0: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A22C4: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A22C8: sw          $t9, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r25;
    // 0x800A22CC: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x800A22D0: lui         $t1, 0xE800
    ctx->r9 = S32(0XE800 << 16);
    // 0x800A22D4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A22D8: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x800A22DC: nop

    // 0x800A22E0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A22E4: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A22E8: nop

    // 0x800A22EC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A22F0: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A22F4: sw          $t4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r12;
    // 0x800A22F8: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x800A22FC: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x800A2300: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x800A2304: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A2308: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x800A230C: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x800A2310: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A2314: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2318: nop

    // 0x800A231C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A2320: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A2324: sw          $t0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r8;
    // 0x800A2328: lw          $t3, 0xD8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD8);
    // 0x800A232C: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x800A2330: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A2334: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x800A2338: nop

    // 0x800A233C: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800A2340: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2344: nop

    // 0x800A2348: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A234C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A2350: sw          $t5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r13;
    // 0x800A2354: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x800A2358: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x800A235C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A2360: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x800A2364: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x800A2368: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x800A236C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A2370: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2374: nop

    // 0x800A2378: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A237C: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A2380: sw          $t1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r9;
    // 0x800A2384: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    // 0x800A2388: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800A238C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A2390: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x800A2394: nop

    // 0x800A2398: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A239C: b           L_800A24BC
    // 0x800A23A0: nop

        goto L_800A24BC;
    // 0x800A23A0: nop

L_800A23A4:
    // 0x800A23A4: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A23A8: nop

    // 0x800A23AC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A23B0: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A23B4: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800A23B8: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x800A23BC: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800A23C0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A23C4: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x800A23C8: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x800A23CC: lw          $t1, 0x138($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X138);
    // 0x800A23D0: nop

    // 0x800A23D4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A23D8: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A23DC: nop

    // 0x800A23E0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A23E4: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A23E8: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x800A23EC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800A23F0: lui         $t5, 0xE800
    ctx->r13 = S32(0XE800 << 16);
    // 0x800A23F4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A23F8: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x800A23FC: nop

    // 0x800A2400: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A2404: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2408: nop

    // 0x800A240C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A2410: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A2414: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A2418: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A241C: lui         $t0, 0xF500
    ctx->r8 = S32(0XF500 << 16);
    // 0x800A2420: ori         $t0, $t0, 0x100
    ctx->r8 = ctx->r8 | 0X100;
    // 0x800A2424: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A2428: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A242C: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x800A2430: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A2434: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2438: nop

    // 0x800A243C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A2440: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A2444: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800A2448: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800A244C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800A2450: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A2454: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x800A2458: nop

    // 0x800A245C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800A2460: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2464: nop

    // 0x800A2468: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A246C: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A2470: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x800A2474: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x800A2478: lui         $t1, 0xF000
    ctx->r9 = S32(0XF000 << 16);
    // 0x800A247C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A2480: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x800A2484: lui         $t3, 0x703
    ctx->r11 = S32(0X703 << 16);
    // 0x800A2488: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x800A248C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A2490: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2494: nop

    // 0x800A2498: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A249C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A24A0: sw          $t5, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r13;
    // 0x800A24A4: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x800A24A8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800A24AC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A24B0: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x800A24B4: nop

    // 0x800A24B8: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_800A24BC:
    // 0x800A24BC: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A24C0: nop

    // 0x800A24C4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A24C8: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A24CC: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x800A24D0: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x800A24D4: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x800A24D8: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x800A24DC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A24E0: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x800A24E4: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x800A24E8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A24EC: b           L_800A2524
    // 0x800A24F0: nop

        goto L_800A2524;
    // 0x800A24F0: nop

L_800A24F4:
    // 0x800A24F4: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A24F8: nop

    // 0x800A24FC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A2500: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A2504: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x800A2508: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x800A250C: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800A2510: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x800A2514: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A2518: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x800A251C: nop

    // 0x800A2520: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800A2524:
    // 0x800A2524: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2528: nop

    // 0x800A252C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A2530: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A2534: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x800A2538: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x800A253C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800A2540: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A2544: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x800A2548: nop

    // 0x800A254C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A2550: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2554: nop

    // 0x800A2558: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A255C: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A2560: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x800A2564: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2568: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800A256C: ori         $t8, $t8, 0x903
    ctx->r24 = ctx->r24 | 0X903;
    // 0x800A2570: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A2574: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2578: addiu       $t0, $zero, 0xC00
    ctx->r8 = ADD32(0, 0XC00);
    // 0x800A257C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A2580: lw          $t2, 0x180($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X180);
    // 0x800A2584: nop

    // 0x800A2588: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800A258C: bne         $t3, $zero, L_800A25CC
    if (ctx->r11 != 0) {
        // 0x800A2590: nop
    
            goto L_800A25CC;
    }
    // 0x800A2590: nop

    // 0x800A2594: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2598: nop

    // 0x800A259C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A25A0: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A25A4: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
    // 0x800A25A8: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800A25AC: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800A25B0: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x800A25B4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A25B8: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x800A25BC: nop

    // 0x800A25C0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800A25C4: b           L_800A25FC
    // 0x800A25C8: nop

        goto L_800A25FC;
    // 0x800A25C8: nop

L_800A25CC:
    // 0x800A25CC: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A25D0: nop

    // 0x800A25D4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A25D8: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A25DC: sw          $t9, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r25;
    // 0x800A25E0: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A25E4: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x800A25E8: ori         $t1, $t1, 0xC02
    ctx->r9 = ctx->r9 | 0XC02;
    // 0x800A25EC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A25F0: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A25F4: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x800A25F8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_800A25FC:
    // 0x800A25FC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A2600: lw          $t5, 0x72D0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72D0);
    // 0x800A2604: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A2608: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x800A260C: addiu       $t7, $t5, 0x2
    ctx->r15 = ADD32(ctx->r13, 0X2);
    // 0x800A2610: sw          $t7, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r15;
    // 0x800A2614: sh          $t6, 0x15A($sp)
    MEM_H(0X15A, ctx->r29) = ctx->r14;
    // 0x800A2618: lh          $t8, 0x15A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X15A);
    // 0x800A261C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800A2620: bne         $t8, $at, L_800A2630
    if (ctx->r24 != ctx->r1) {
        // 0x800A2624: nop
    
            goto L_800A2630;
    }
    // 0x800A2624: nop

    // 0x800A2628: b           L_800A38B4
    // 0x800A262C: nop

        goto L_800A38B4;
    // 0x800A262C: nop

L_800A2630:
    // 0x800A2630: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A2634: lw          $t9, 0x72D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72D0);
    // 0x800A2638: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A263C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800A2640: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x800A2644: sw          $t1, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r9;
    // 0x800A2648: sh          $t0, 0x158($sp)
    MEM_H(0X158, ctx->r29) = ctx->r8;
    // 0x800A264C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A2650: lw          $t2, 0x72D0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72D0);
    // 0x800A2654: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A2658: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x800A265C: addiu       $t4, $t2, 0x2
    ctx->r12 = ADD32(ctx->r10, 0X2);
    // 0x800A2660: sw          $t4, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r12;
    // 0x800A2664: sw          $t3, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r11;
    // 0x800A2668: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A266C: lw          $t6, 0x72D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72D0);
    // 0x800A2670: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A2674: lh          $t5, 0x0($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X0);
    // 0x800A2678: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800A267C: sw          $t7, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r15;
    // 0x800A2680: sw          $t5, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r13;
    // 0x800A2684: lw          $t8, 0x180($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X180);
    // 0x800A2688: nop

    // 0x800A268C: andi        $t0, $t8, 0x1000
    ctx->r8 = ctx->r24 & 0X1000;
    // 0x800A2690: bne         $t0, $zero, L_800A2734
    if (ctx->r8 != 0) {
        // 0x800A2694: nop
    
            goto L_800A2734;
    }
    // 0x800A2694: nop

    // 0x800A2698: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A269C: lw          $t9, 0x72D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72D0);
    // 0x800A26A0: nop

    // 0x800A26A4: sw          $t9, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r25;
    // 0x800A26A8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A26AC: lw          $t1, 0x72D0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72D0);
    // 0x800A26B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A26B4: sw          $t1, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r9;
    // 0x800A26B8: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x800A26BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A26C0: lh          $t2, 0x116($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X116);
    // 0x800A26C4: nop

    // 0x800A26C8: bne         $t2, $at, L_800A26F8
    if (ctx->r10 != ctx->r1) {
        // 0x800A26CC: nop
    
            goto L_800A26F8;
    }
    // 0x800A26CC: nop

    // 0x800A26D0: lw          $t4, 0x188($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X188);
    // 0x800A26D4: lw          $t5, 0x184($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X184);
    // 0x800A26D8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A26DC: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A26E0: lw          $t7, 0x72E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E0);
    // 0x800A26E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A26E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800A26EC: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800A26F0: b           L_800A2720
    // 0x800A26F4: sw          $t8, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r24;
        goto L_800A2720;
    // 0x800A26F4: sw          $t8, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r24;
L_800A26F8:
    // 0x800A26F8: lw          $t0, 0x188($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X188);
    // 0x800A26FC: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800A2700: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A2704: multu       $t0, $t9
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2708: lw          $t2, 0x72E0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72E0);
    // 0x800A270C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A2710: mflo        $t1
    ctx->r9 = lo;
    // 0x800A2714: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x800A2718: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800A271C: sw          $t4, 0x72E0($at)
    MEM_W(0X72E0, ctx->r1) = ctx->r12;
L_800A2720:
    // 0x800A2720: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A2724: lw          $t5, 0x72E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E0);
    // 0x800A2728: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A272C: b           L_800A2760
    // 0x800A2730: sw          $t5, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r13;
        goto L_800A2760;
    // 0x800A2730: sw          $t5, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r13;
L_800A2734:
    // 0x800A2734: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A2738: lw          $t7, 0x72D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72D0);
    // 0x800A273C: nop

    // 0x800A2740: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800A2744: nop

    // 0x800A2748: sw          $t6, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r14;
    // 0x800A274C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A2750: lw          $t8, 0x72D0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72D0);
    // 0x800A2754: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A2758: addiu       $t0, $t8, 0x4
    ctx->r8 = ADD32(ctx->r24, 0X4);
    // 0x800A275C: sw          $t0, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r8;
L_800A2760:
    // 0x800A2760: lw          $t9, 0x188($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X188);
    // 0x800A2764: nop

    // 0x800A2768: bgez        $t9, L_800A2778
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A276C: sra         $t1, $t9, 1
        ctx->r9 = S32(SIGNED(ctx->r25) >> 1);
            goto L_800A2778;
    }
    // 0x800A276C: sra         $t1, $t9, 1
    ctx->r9 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800A2770: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x800A2774: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800A2778:
    // 0x800A2778: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800A277C: sw          $t2, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r10;
    // 0x800A2780: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800A2784: sw          $t3, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r11;
L_800A2788:
    // 0x800A2788: lw          $t4, 0x174($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X174);
    // 0x800A278C: nop

    // 0x800A2790: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800A2794: beq         $t5, $zero, L_800A27BC
    if (ctx->r13 == 0) {
        // 0x800A2798: nop
    
            goto L_800A27BC;
    }
    // 0x800A2798: nop

    // 0x800A279C: lw          $t7, 0x174($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X174);
    // 0x800A27A0: nop

    // 0x800A27A4: andi        $t6, $t7, 0x7F
    ctx->r14 = ctx->r15 & 0X7F;
    // 0x800A27A8: beq         $t6, $zero, L_800A27B4
    if (ctx->r14 == 0) {
        // 0x800A27AC: nop
    
            goto L_800A27B4;
    }
    // 0x800A27AC: nop

    // 0x800A27B0: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
L_800A27B4:
    // 0x800A27B4: b           L_800A27E0
    // 0x800A27B8: nop

        goto L_800A27E0;
    // 0x800A27B8: nop

L_800A27BC:
    // 0x800A27BC: lw          $t8, 0x174($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X174);
    // 0x800A27C0: nop

    // 0x800A27C4: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800A27C8: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    // 0x800A27CC: lw          $t9, 0x17C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X17C);
    // 0x800A27D0: nop

    // 0x800A27D4: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800A27D8: bgtz        $t1, L_800A2788
    if (SIGNED(ctx->r9) > 0) {
        // 0x800A27DC: sw          $t1, 0x17C($sp)
        MEM_W(0X17C, ctx->r29) = ctx->r9;
            goto L_800A2788;
    }
    // 0x800A27DC: sw          $t1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r9;
L_800A27E0:
    // 0x800A27E0: lw          $t2, 0x184($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X184);
    // 0x800A27E4: nop

    // 0x800A27E8: bgez        $t2, L_800A27F8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A27EC: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800A27F8;
    }
    // 0x800A27EC: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A27F0: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800A27F4: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800A27F8:
    // 0x800A27F8: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800A27FC: sw          $t4, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r12;
    // 0x800A2800: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800A2804: sw          $t5, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r13;
L_800A2808:
    // 0x800A2808: lw          $t7, 0x174($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X174);
    // 0x800A280C: nop

    // 0x800A2810: andi        $t6, $t7, 0x80
    ctx->r14 = ctx->r15 & 0X80;
    // 0x800A2814: beq         $t6, $zero, L_800A283C
    if (ctx->r14 == 0) {
        // 0x800A2818: nop
    
            goto L_800A283C;
    }
    // 0x800A2818: nop

    // 0x800A281C: lw          $t8, 0x174($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X174);
    // 0x800A2820: nop

    // 0x800A2824: andi        $t0, $t8, 0x7F
    ctx->r8 = ctx->r24 & 0X7F;
    // 0x800A2828: beq         $t0, $zero, L_800A2834
    if (ctx->r8 == 0) {
        // 0x800A282C: nop
    
            goto L_800A2834;
    }
    // 0x800A282C: nop

    // 0x800A2830: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
L_800A2834:
    // 0x800A2834: b           L_800A2860
    // 0x800A2838: nop

        goto L_800A2860;
    // 0x800A2838: nop

L_800A283C:
    // 0x800A283C: lw          $t9, 0x174($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X174);
    // 0x800A2840: nop

    // 0x800A2844: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800A2848: sw          $t1, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r9;
    // 0x800A284C: lw          $t2, 0x178($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X178);
    // 0x800A2850: nop

    // 0x800A2854: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800A2858: bgtz        $t3, L_800A2808
    if (SIGNED(ctx->r11) > 0) {
        // 0x800A285C: sw          $t3, 0x178($sp)
        MEM_W(0X178, ctx->r29) = ctx->r11;
            goto L_800A2808;
    }
    // 0x800A285C: sw          $t3, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r11;
L_800A2860:
    // 0x800A2860: lw          $t4, 0x180($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X180);
    // 0x800A2864: nop

    // 0x800A2868: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800A286C: bne         $t5, $zero, L_800A28C8
    if (ctx->r13 != 0) {
        // 0x800A2870: nop
    
            goto L_800A28C8;
    }
    // 0x800A2870: nop

    // 0x800A2874: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x800A2878: lh          $t7, 0x15A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X15A);
    // 0x800A287C: lw          $t8, 0x104($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X104);
    // 0x800A2880: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A2884: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800A2888: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A288C: lwc1        $f18, 0x13C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A2890: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800A2894: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A2898: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800A289C: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800A28A0: lwc1        $f6, 0x198($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X198);
    // 0x800A28A4: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A28A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A28AC: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800A28B0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A28B4: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A28B8: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
    // 0x800A28BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A28C0: b           L_800A2938
    // 0x800A28C4: swc1        $f4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f4.u32l;
        goto L_800A2938;
    // 0x800A28C4: swc1        $f4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f4.u32l;
L_800A28C8:
    // 0x800A28C8: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x800A28CC: lw          $t2, 0x188($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X188);
    // 0x800A28D0: lw          $t9, 0x104($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X104);
    // 0x800A28D4: lh          $t4, 0x15A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X15A);
    // 0x800A28D8: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x800A28DC: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800A28E0: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800A28E4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800A28E8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A28EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A28F0: lwc1        $f4, 0x13C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A28F4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800A28F8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A28FC: lwc1        $f16, 0x12C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800A2900: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800A2904: lwc1        $f10, 0x198($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X198);
    // 0x800A2908: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800A290C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2910: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800A2914: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800A2918: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A291C: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x800A2920: lw          $t7, 0x188($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X188);
    // 0x800A2924: nop

    // 0x800A2928: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800A292C: nop

    // 0x800A2930: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A2934: swc1        $f10, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f10.u32l;
L_800A2938:
    // 0x800A2938: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x800A293C: lwc1        $f4, 0x13C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A2940: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A2944: lwc1        $f16, 0x154($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800A2948: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A294C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A2950: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800A2954: swc1        $f10, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f10.u32l;
    // 0x800A2958: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800A295C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800A2960: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A2964: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x800A2968: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x800A296C: nop

    // 0x800A2970: bc1f        L_800A299C
    if (!c1cs) {
        // 0x800A2974: nop
    
            goto L_800A299C;
    }
    // 0x800A2974: nop

    // 0x800A2978: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800A297C: lwc1        $f16, 0x13C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A2980: lwc1        $f8, 0x144($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A2984: div.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800A2988: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A298C: swc1        $f18, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f18.u32l;
    // 0x800A2990: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A2994: b           L_800A29F0
    // 0x800A2998: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
        goto L_800A29F0;
    // 0x800A2998: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
L_800A299C:
    // 0x800A299C: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800A29A0: lui         $at, 0x4074
    ctx->r1 = S32(0X4074 << 16);
    // 0x800A29A4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A29A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A29AC: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x800A29B0: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800A29B4: nop

    // 0x800A29B8: bc1f        L_800A29F0
    if (!c1cs) {
        // 0x800A29BC: nop
    
            goto L_800A29F0;
    }
    // 0x800A29BC: nop

    // 0x800A29C0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800A29C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A29C8: lwc1        $f18, 0x154($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800A29CC: lwc1        $f6, 0x13C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A29D0: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A29D4: nop

    // 0x800A29D8: div.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A29DC: swc1        $f16, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f16.u32l;
    // 0x800A29E0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800A29E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A29E8: nop

    // 0x800A29EC: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
L_800A29F0:
    // 0x800A29F0: lwc1        $f10, 0x14C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800A29F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A29F8: nop

    // 0x800A29FC: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800A2A00: nop

    // 0x800A2A04: bc1f        L_800A2A18
    if (!c1cs) {
        // 0x800A2A08: nop
    
            goto L_800A2A18;
    }
    // 0x800A2A08: nop

    // 0x800A2A0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A2A10: b           L_800A2A48
    // 0x800A2A14: swc1        $f4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f4.u32l;
        goto L_800A2A48;
    // 0x800A2A14: swc1        $f4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f4.u32l;
L_800A2A18:
    // 0x800A2A18: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800A2A1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2A20: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800A2A24: nop

    // 0x800A2A28: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800A2A2C: nop

    // 0x800A2A30: bc1f        L_800A2A48
    if (!c1cs) {
        // 0x800A2A34: nop
    
            goto L_800A2A48;
    }
    // 0x800A2A34: nop

    // 0x800A2A38: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800A2A3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2A40: nop

    // 0x800A2A44: swc1        $f8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f8.u32l;
L_800A2A48:
    // 0x800A2A48: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A2A4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A2A50: lwc1        $f10, 0x154($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800A2A54: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A2A58: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A2A5C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A2A60: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A2A64: nop

    // 0x800A2A68: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A2A6C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A2A70: nop

    // 0x800A2A74: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x800A2A78: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800A2A7C: beq         $t0, $zero, L_800A2AD0
    if (ctx->r8 == 0) {
        // 0x800A2A80: nop
    
            goto L_800A2AD0;
    }
    // 0x800A2A80: nop

    // 0x800A2A84: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A2A88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A2A8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A2A90: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A2A94: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A2A98: nop

    // 0x800A2A9C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A2AA0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A2AA4: nop

    // 0x800A2AA8: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x800A2AAC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800A2AB0: bne         $t0, $zero, L_800A2AC8
    if (ctx->r8 != 0) {
        // 0x800A2AB4: nop
    
            goto L_800A2AC8;
    }
    // 0x800A2AB4: nop

    // 0x800A2AB8: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800A2ABC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2AC0: b           L_800A2AE0
    // 0x800A2AC4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800A2AE0;
    // 0x800A2AC4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800A2AC8:
    // 0x800A2AC8: b           L_800A2AE0
    // 0x800A2ACC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800A2AE0;
    // 0x800A2ACC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A2AD0:
    // 0x800A2AD0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800A2AD4: nop

    // 0x800A2AD8: bltz        $t0, L_800A2AC8
    if (SIGNED(ctx->r8) < 0) {
        // 0x800A2ADC: nop
    
            goto L_800A2AC8;
    }
    // 0x800A2ADC: nop

L_800A2AE0:
    // 0x800A2AE0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A2AE4: sw          $t0, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r8;
    // 0x800A2AE8: nop

    // 0x800A2AEC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A2AF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2AF4: lwc1        $f16, 0x14C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800A2AF8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A2AFC: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800A2B00: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A2B04: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A2B08: nop

    // 0x800A2B0C: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A2B10: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A2B14: nop

    // 0x800A2B18: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800A2B1C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800A2B20: beq         $t1, $zero, L_800A2B74
    if (ctx->r9 == 0) {
        // 0x800A2B24: nop
    
            goto L_800A2B74;
    }
    // 0x800A2B24: nop

    // 0x800A2B28: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A2B2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A2B30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A2B34: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A2B38: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A2B3C: nop

    // 0x800A2B40: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A2B44: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A2B48: nop

    // 0x800A2B4C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800A2B50: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800A2B54: bne         $t1, $zero, L_800A2B6C
    if (ctx->r9 != 0) {
        // 0x800A2B58: nop
    
            goto L_800A2B6C;
    }
    // 0x800A2B58: nop

    // 0x800A2B5C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800A2B60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2B64: b           L_800A2B84
    // 0x800A2B68: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800A2B84;
    // 0x800A2B68: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800A2B6C:
    // 0x800A2B6C: b           L_800A2B84
    // 0x800A2B70: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800A2B84;
    // 0x800A2B70: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800A2B74:
    // 0x800A2B74: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800A2B78: nop

    // 0x800A2B7C: bltz        $t1, L_800A2B6C
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A2B80: nop
    
            goto L_800A2B6C;
    }
    // 0x800A2B80: nop

L_800A2B84:
    // 0x800A2B84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A2B88: sw          $t1, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r9;
    // 0x800A2B8C: nop

    // 0x800A2B90: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800A2B94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A2B98: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A2B9C: nop

    // 0x800A2BA0: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A2BA4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A2BA8: nop

    // 0x800A2BAC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A2BB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2BB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2BB8: nop

    // 0x800A2BBC: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A2BC0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800A2BC4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A2BC8: sh          $t3, 0x162($sp)
    MEM_H(0X162, ctx->r29) = ctx->r11;
    // 0x800A2BCC: nop

    // 0x800A2BD0: lw          $t4, 0x170($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X170);
    // 0x800A2BD4: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x800A2BD8: nop

    // 0x800A2BDC: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x800A2BE0: beq         $at, $zero, L_800A38AC
    if (ctx->r1 == 0) {
        // 0x800A2BE4: nop
    
            goto L_800A38AC;
    }
    // 0x800A2BE4: nop

    // 0x800A2BE8: lw          $t7, 0x180($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X180);
    // 0x800A2BEC: nop

    // 0x800A2BF0: andi        $t6, $t7, 0x2
    ctx->r14 = ctx->r15 & 0X2;
    // 0x800A2BF4: bne         $t6, $zero, L_800A2C50
    if (ctx->r14 != 0) {
        // 0x800A2BF8: nop
    
            goto L_800A2C50;
    }
    // 0x800A2BF8: nop

    // 0x800A2BFC: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x800A2C00: lh          $t8, 0x158($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X158);
    // 0x800A2C04: lw          $t9, 0x108($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X108);
    // 0x800A2C08: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A2C0C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800A2C10: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A2C14: lwc1        $f8, 0x138($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800A2C18: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800A2C1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A2C20: lwc1        $f4, 0x128($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X128);
    // 0x800A2C24: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800A2C28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A2C2C: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800A2C30: lwc1        $f16, 0x19C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X19C);
    // 0x800A2C34: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800A2C38: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800A2C3C: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800A2C40: swc1        $f10, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f10.u32l;
    // 0x800A2C44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A2C48: b           L_800A2CC4
    // 0x800A2C4C: swc1        $f4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f4.u32l;
        goto L_800A2CC4;
    // 0x800A2C4C: swc1        $f4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f4.u32l;
L_800A2C50:
    // 0x800A2C50: lh          $t1, 0x158($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X158);
    // 0x800A2C54: lw          $t3, 0x194($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X194);
    // 0x800A2C58: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x800A2C5C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A2C60: lw          $t5, 0x184($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X184);
    // 0x800A2C64: lw          $t4, 0x108($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X108);
    // 0x800A2C68: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A2C6C: lwc1        $f18, 0x138($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800A2C70: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x800A2C74: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x800A2C78: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A2C7C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800A2C80: lwc1        $f10, 0x128($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X128);
    // 0x800A2C84: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800A2C88: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A2C8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A2C90: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A2C94: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A2C98: lwc1        $f16, 0x19C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X19C);
    // 0x800A2C9C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800A2CA0: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800A2CA4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800A2CA8: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
    // 0x800A2CAC: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x800A2CB0: nop

    // 0x800A2CB4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800A2CB8: nop

    // 0x800A2CBC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A2CC0: swc1        $f6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f6.u32l;
L_800A2CC4:
    // 0x800A2CC4: lw          $t0, 0x184($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X184);
    // 0x800A2CC8: lwc1        $f18, 0x138($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800A2CCC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A2CD0: lwc1        $f8, 0x150($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800A2CD4: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A2CD8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A2CDC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800A2CE0: swc1        $f6, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f6.u32l;
    // 0x800A2CE4: lwc1        $f16, 0x150($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800A2CE8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A2CEC: nop

    // 0x800A2CF0: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800A2CF4: nop

    // 0x800A2CF8: bc1f        L_800A2D24
    if (!c1cs) {
        // 0x800A2CFC: nop
    
            goto L_800A2D24;
    }
    // 0x800A2CFC: nop

    // 0x800A2D00: lwc1        $f18, 0x150($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800A2D04: lwc1        $f4, 0x138($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800A2D08: lwc1        $f6, 0x140($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A2D0C: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A2D10: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A2D14: swc1        $f16, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f16.u32l;
    // 0x800A2D18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A2D1C: b           L_800A2D74
    // 0x800A2D20: swc1        $f10, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f10.u32l;
        goto L_800A2D74;
    // 0x800A2D20: swc1        $f10, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f10.u32l;
L_800A2D24:
    // 0x800A2D24: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A2D28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2D2C: lwc1        $f18, 0x150($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800A2D30: nop

    // 0x800A2D34: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800A2D38: nop

    // 0x800A2D3C: bc1f        L_800A2D74
    if (!c1cs) {
        // 0x800A2D40: nop
    
            goto L_800A2D74;
    }
    // 0x800A2D40: nop

    // 0x800A2D44: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A2D48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A2D4C: lwc1        $f8, 0x150($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800A2D50: lwc1        $f10, 0x138($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800A2D54: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A2D58: nop

    // 0x800A2D5C: div.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800A2D60: swc1        $f18, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f18.u32l;
    // 0x800A2D64: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A2D68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2D6C: nop

    // 0x800A2D70: swc1        $f4, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->f4.u32l;
L_800A2D74:
    // 0x800A2D74: lwc1        $f6, 0x148($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800A2D78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A2D7C: nop

    // 0x800A2D80: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800A2D84: nop

    // 0x800A2D88: bc1f        L_800A2D9C
    if (!c1cs) {
        // 0x800A2D8C: nop
    
            goto L_800A2D9C;
    }
    // 0x800A2D8C: nop

    // 0x800A2D90: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A2D94: b           L_800A2DCC
    // 0x800A2D98: swc1        $f16, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f16.u32l;
        goto L_800A2DCC;
    // 0x800A2D98: swc1        $f16, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f16.u32l;
L_800A2D9C:
    // 0x800A2D9C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A2DA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A2DA4: lwc1        $f10, 0x148($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800A2DA8: nop

    // 0x800A2DAC: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800A2DB0: nop

    // 0x800A2DB4: bc1f        L_800A2DCC
    if (!c1cs) {
        // 0x800A2DB8: nop
    
            goto L_800A2DCC;
    }
    // 0x800A2DB8: nop

    // 0x800A2DBC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800A2DC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2DC4: nop

    // 0x800A2DC8: swc1        $f4, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f4.u32l;
L_800A2DCC:
    // 0x800A2DCC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A2DD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2DD4: lwc1        $f6, 0x150($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800A2DD8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A2DDC: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A2DE0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A2DE4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A2DE8: nop

    // 0x800A2DEC: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A2DF0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A2DF4: nop

    // 0x800A2DF8: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800A2DFC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800A2E00: beq         $t1, $zero, L_800A2E54
    if (ctx->r9 == 0) {
        // 0x800A2E04: nop
    
            goto L_800A2E54;
    }
    // 0x800A2E04: nop

    // 0x800A2E08: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A2E0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2E10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A2E14: sub.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800A2E18: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A2E1C: nop

    // 0x800A2E20: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A2E24: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A2E28: nop

    // 0x800A2E2C: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800A2E30: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800A2E34: bne         $t1, $zero, L_800A2E4C
    if (ctx->r9 != 0) {
        // 0x800A2E38: nop
    
            goto L_800A2E4C;
    }
    // 0x800A2E38: nop

    // 0x800A2E3C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800A2E40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2E44: b           L_800A2E64
    // 0x800A2E48: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800A2E64;
    // 0x800A2E48: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800A2E4C:
    // 0x800A2E4C: b           L_800A2E64
    // 0x800A2E50: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800A2E64;
    // 0x800A2E50: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800A2E54:
    // 0x800A2E54: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800A2E58: nop

    // 0x800A2E5C: bltz        $t1, L_800A2E4C
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A2E60: nop
    
            goto L_800A2E4C;
    }
    // 0x800A2E60: nop

L_800A2E64:
    // 0x800A2E64: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A2E68: sw          $t1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r9;
    // 0x800A2E6C: nop

    // 0x800A2E70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A2E74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2E78: lwc1        $f18, 0x148($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800A2E7C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A2E80: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A2E84: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A2E88: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A2E8C: nop

    // 0x800A2E90: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A2E94: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A2E98: nop

    // 0x800A2E9C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800A2EA0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800A2EA4: beq         $t3, $zero, L_800A2EF8
    if (ctx->r11 == 0) {
        // 0x800A2EA8: nop
    
            goto L_800A2EF8;
    }
    // 0x800A2EA8: nop

    // 0x800A2EAC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A2EB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2EB4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A2EB8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A2EBC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A2EC0: nop

    // 0x800A2EC4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A2EC8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A2ECC: nop

    // 0x800A2ED0: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800A2ED4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800A2ED8: bne         $t3, $zero, L_800A2EF0
    if (ctx->r11 != 0) {
        // 0x800A2EDC: nop
    
            goto L_800A2EF0;
    }
    // 0x800A2EDC: nop

    // 0x800A2EE0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800A2EE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2EE8: b           L_800A2F08
    // 0x800A2EEC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800A2F08;
    // 0x800A2EEC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800A2EF0:
    // 0x800A2EF0: b           L_800A2F08
    // 0x800A2EF4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800A2F08;
    // 0x800A2EF4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800A2EF8:
    // 0x800A2EF8: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800A2EFC: nop

    // 0x800A2F00: bltz        $t3, L_800A2EF0
    if (SIGNED(ctx->r11) < 0) {
        // 0x800A2F04: nop
    
            goto L_800A2EF0;
    }
    // 0x800A2F04: nop

L_800A2F08:
    // 0x800A2F08: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A2F0C: sw          $t3, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r11;
    // 0x800A2F10: nop

    // 0x800A2F14: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800A2F18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2F1C: lwc1        $f16, 0x140($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A2F20: nop

    // 0x800A2F24: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800A2F28: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A2F2C: nop

    // 0x800A2F30: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A2F34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2F38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2F3C: nop

    // 0x800A2F40: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A2F44: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800A2F48: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A2F4C: sh          $t5, 0x160($sp)
    MEM_H(0X160, ctx->r29) = ctx->r13;
    // 0x800A2F50: nop

    // 0x800A2F54: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x800A2F58: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A2F5C: nop

    // 0x800A2F60: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x800A2F64: beq         $at, $zero, L_800A38AC
    if (ctx->r1 == 0) {
        // 0x800A2F68: nop
    
            goto L_800A38AC;
    }
    // 0x800A2F68: nop

    // 0x800A2F6C: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x800A2F70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A2F74: lh          $t0, 0x116($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X116);
    // 0x800A2F78: nop

    // 0x800A2F7C: bne         $t0, $at, L_800A324C
    if (ctx->r8 != ctx->r1) {
        // 0x800A2F80: nop
    
            goto L_800A324C;
    }
    // 0x800A2F80: nop

    // 0x800A2F84: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2F88: nop

    // 0x800A2F8C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x800A2F90: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A2F94: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x800A2F98: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x800A2F9C: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x800A2FA0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A2FA4: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x800A2FA8: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x800A2FAC: nop

    // 0x800A2FB0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A2FB4: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A2FB8: nop

    // 0x800A2FBC: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x800A2FC0: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800A2FC4: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800A2FC8: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800A2FCC: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x800A2FD0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800A2FD4: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x800A2FD8: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800A2FDC: andi        $t1, $t9, 0xF
    ctx->r9 = ctx->r25 & 0XF;
    // 0x800A2FE0: sll         $t2, $t1, 14
    ctx->r10 = S32(ctx->r9 << 14);
    // 0x800A2FE4: lui         $at, 0x704
    ctx->r1 = S32(0X704 << 16);
    // 0x800A2FE8: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800A2FEC: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x800A2FF0: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x800A2FF4: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x800A2FF8: ori         $t4, $t3, 0x100
    ctx->r12 = ctx->r11 | 0X100;
    // 0x800A2FFC: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x800A3000: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800A3004: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3008: nop

    // 0x800A300C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x800A3010: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A3014: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800A3018: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x800A301C: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x800A3020: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A3024: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x800A3028: nop

    // 0x800A302C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A3030: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3034: nop

    // 0x800A3038: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x800A303C: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A3040: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x800A3044: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800A3048: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800A304C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800A3050: lw          $t0, 0x188($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X188);
    // 0x800A3054: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800A3058: nop

    // 0x800A305C: multu       $t0, $t9
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A3060: mflo        $t1
    ctx->r9 = lo;
    // 0x800A3064: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800A3068: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A306C: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800A3070: slti        $at, $t5, 0x7FF
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF ? 1 : 0;
    // 0x800A3074: beq         $at, $zero, L_800A3084
    if (ctx->r1 == 0) {
        // 0x800A3078: nop
    
            goto L_800A3084;
    }
    // 0x800A3078: nop

    // 0x800A307C: b           L_800A3088
    // 0x800A3080: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
        goto L_800A3088;
    // 0x800A3080: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
L_800A3084:
    // 0x800A3084: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_800A3088:
    // 0x800A3088: lw          $t7, 0x188($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X188);
    // 0x800A308C: nop

    // 0x800A3090: bgez        $t7, L_800A30A0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800A3094: sra         $t4, $t7, 3
        ctx->r12 = S32(SIGNED(ctx->r15) >> 3);
            goto L_800A30A0;
    }
    // 0x800A3094: sra         $t4, $t7, 3
    ctx->r12 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800A3098: addiu       $at, $t7, 0x7
    ctx->r1 = ADD32(ctx->r15, 0X7);
    // 0x800A309C: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800A30A0:
    // 0x800A30A0: bgtz        $t4, L_800A30B0
    if (SIGNED(ctx->r12) > 0) {
        // 0x800A30A4: nop
    
            goto L_800A30B0;
    }
    // 0x800A30A4: nop

    // 0x800A30A8: b           L_800A30CC
    // 0x800A30AC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800A30CC;
    // 0x800A30AC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800A30B0:
    // 0x800A30B0: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x800A30B4: nop

    // 0x800A30B8: bgez        $s1, L_800A30C8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800A30BC: sra         $t6, $s1, 3
        ctx->r14 = S32(SIGNED(ctx->r17) >> 3);
            goto L_800A30C8;
    }
    // 0x800A30BC: sra         $t6, $s1, 3
    ctx->r14 = S32(SIGNED(ctx->r17) >> 3);
    // 0x800A30C0: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x800A30C4: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800A30C8:
    // 0x800A30C8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_800A30CC:
    // 0x800A30CC: lw          $t8, 0x188($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X188);
    // 0x800A30D0: nop

    // 0x800A30D4: bgez        $t8, L_800A30E4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A30D8: sra         $t0, $t8, 3
        ctx->r8 = S32(SIGNED(ctx->r24) >> 3);
            goto L_800A30E4;
    }
    // 0x800A30D8: sra         $t0, $t8, 3
    ctx->r8 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800A30DC: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x800A30E0: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_800A30E4:
    // 0x800A30E4: bgtz        $t0, L_800A30F4
    if (SIGNED(ctx->r8) > 0) {
        // 0x800A30E8: nop
    
            goto L_800A30F4;
    }
    // 0x800A30E8: nop

    // 0x800A30EC: b           L_800A3110
    // 0x800A30F0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800A3110;
    // 0x800A30F0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800A30F4:
    // 0x800A30F4: lw          $s0, 0x188($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X188);
    // 0x800A30F8: nop

    // 0x800A30FC: bgez        $s0, L_800A310C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800A3100: sra         $t9, $s0, 3
        ctx->r25 = S32(SIGNED(ctx->r16) >> 3);
            goto L_800A310C;
    }
    // 0x800A3100: sra         $t9, $s0, 3
    ctx->r25 = S32(SIGNED(ctx->r16) >> 3);
    // 0x800A3104: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x800A3108: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800A310C:
    // 0x800A310C: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800A3110:
    // 0x800A3110: addiu       $t1, $s1, 0x7FF
    ctx->r9 = ADD32(ctx->r17, 0X7FF);
    // 0x800A3114: div         $zero, $t1, $s0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r16)));
    // 0x800A3118: andi        $t5, $s2, 0xFFF
    ctx->r13 = ctx->r18 & 0XFFF;
    // 0x800A311C: bne         $s0, $zero, L_800A3128
    if (ctx->r16 != 0) {
        // 0x800A3120: nop
    
            goto L_800A3128;
    }
    // 0x800A3120: nop

    // 0x800A3124: break       7
    do_break(2148151588);
L_800A3128:
    // 0x800A3128: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A312C: bne         $s0, $at, L_800A3140
    if (ctx->r16 != ctx->r1) {
        // 0x800A3130: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A3140;
    }
    // 0x800A3130: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A3134: bne         $t1, $at, L_800A3140
    if (ctx->r9 != ctx->r1) {
        // 0x800A3138: nop
    
            goto L_800A3140;
    }
    // 0x800A3138: nop

    // 0x800A313C: break       6
    do_break(2148151612);
L_800A3140:
    // 0x800A3140: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800A3144: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x800A3148: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800A314C: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x800A3150: mflo        $t2
    ctx->r10 = lo;
    // 0x800A3154: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800A3158: or          $t6, $t3, $t4
    ctx->r14 = ctx->r11 | ctx->r12;
    // 0x800A315C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x800A3160: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3164: nop

    // 0x800A3168: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800A316C: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A3170: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x800A3174: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x800A3178: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x800A317C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A3180: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x800A3184: nop

    // 0x800A3188: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A318C: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3190: nop

    // 0x800A3194: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x800A3198: sw          $t3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r11;
    // 0x800A319C: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    // 0x800A31A0: lw          $t4, 0x188($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X188);
    // 0x800A31A4: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800A31A8: addiu       $t6, $t4, 0x7
    ctx->r14 = ADD32(ctx->r12, 0X7);
    // 0x800A31AC: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800A31B0: andi        $t0, $t8, 0x1FF
    ctx->r8 = ctx->r24 & 0X1FF;
    // 0x800A31B4: sll         $t9, $t0, 9
    ctx->r25 = S32(ctx->r8 << 9);
    // 0x800A31B8: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x800A31BC: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x800A31C0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A31C4: lw          $t5, 0x178($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X178);
    // 0x800A31C8: lw          $t8, 0x17C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X17C);
    // 0x800A31CC: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x800A31D0: sll         $t3, $t7, 14
    ctx->r11 = S32(ctx->r15 << 14);
    // 0x800A31D4: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800A31D8: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800A31DC: andi        $t0, $t8, 0xF
    ctx->r8 = ctx->r24 & 0XF;
    // 0x800A31E0: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800A31E4: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x800A31E8: ori         $t6, $t4, 0x100
    ctx->r14 = ctx->r12 | 0X100;
    // 0x800A31EC: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x800A31F0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A31F4: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A31F8: nop

    // 0x800A31FC: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x800A3200: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A3204: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    // 0x800A3208: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x800A320C: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x800A3210: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A3214: lw          $t8, 0x188($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X188);
    // 0x800A3218: lw          $t2, 0x184($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X184);
    // 0x800A321C: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x800A3220: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x800A3224: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x800A3228: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800A322C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800A3230: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x800A3234: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x800A3238: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x800A323C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800A3240: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x800A3244: b           L_800A3778
    // 0x800A3248: nop

        goto L_800A3778;
    // 0x800A3248: nop

L_800A324C:
    // 0x800A324C: lw          $t0, 0x194($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X194);
    // 0x800A3250: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3254: lh          $t6, 0x116($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X116);
    // 0x800A3258: nop

    // 0x800A325C: bne         $t6, $at, L_800A3540
    if (ctx->r14 != ctx->r1) {
        // 0x800A3260: nop
    
            goto L_800A3540;
    }
    // 0x800A3260: nop

    // 0x800A3264: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3268: nop

    // 0x800A326C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800A3270: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A3274: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x800A3278: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800A327C: lui         $t5, 0xFD10
    ctx->r13 = S32(0XFD10 << 16);
    // 0x800A3280: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800A3284: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x800A3288: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x800A328C: nop

    // 0x800A3290: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800A3294: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3298: nop

    // 0x800A329C: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800A32A0: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A32A4: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800A32A8: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A32AC: lui         $t0, 0xF510
    ctx->r8 = S32(0XF510 << 16);
    // 0x800A32B0: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x800A32B4: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x800A32B8: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x800A32BC: andi        $t2, $t9, 0xF
    ctx->r10 = ctx->r25 & 0XF;
    // 0x800A32C0: sll         $t5, $t2, 14
    ctx->r13 = S32(ctx->r10 << 14);
    // 0x800A32C4: lui         $at, 0x704
    ctx->r1 = S32(0X704 << 16);
    // 0x800A32C8: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800A32CC: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x800A32D0: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A32D4: sll         $t8, $t4, 4
    ctx->r24 = S32(ctx->r12 << 4);
    // 0x800A32D8: ori         $t1, $t7, 0x100
    ctx->r9 = ctx->r15 | 0X100;
    // 0x800A32DC: or          $t0, $t1, $t8
    ctx->r8 = ctx->r9 | ctx->r24;
    // 0x800A32E0: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800A32E4: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A32E8: nop

    // 0x800A32EC: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800A32F0: sw          $t2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r10;
    // 0x800A32F4: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x800A32F8: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800A32FC: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800A3300: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800A3304: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x800A3308: nop

    // 0x800A330C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A3310: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3314: nop

    // 0x800A3318: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x800A331C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A3320: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x800A3324: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800A3328: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800A332C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800A3330: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x800A3334: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800A3338: nop

    // 0x800A333C: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A3340: mflo        $t2
    ctx->r10 = lo;
    // 0x800A3344: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x800A3348: slti        $at, $t5, 0x7FF
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF ? 1 : 0;
    // 0x800A334C: beq         $at, $zero, L_800A335C
    if (ctx->r1 == 0) {
        // 0x800A3350: nop
    
            goto L_800A335C;
    }
    // 0x800A3350: nop

    // 0x800A3354: b           L_800A3360
    // 0x800A3358: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
        goto L_800A3360;
    // 0x800A3358: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
L_800A335C:
    // 0x800A335C: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_800A3360:
    // 0x800A3360: lw          $t7, 0x188($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X188);
    // 0x800A3364: nop

    // 0x800A3368: sll         $t3, $t7, 1
    ctx->r11 = S32(ctx->r15 << 1);
    // 0x800A336C: bgez        $t3, L_800A337C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A3370: sra         $t4, $t3, 3
        ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
            goto L_800A337C;
    }
    // 0x800A3370: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x800A3374: addiu       $at, $t3, 0x7
    ctx->r1 = ADD32(ctx->r11, 0X7);
    // 0x800A3378: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800A337C:
    // 0x800A337C: bgtz        $t4, L_800A338C
    if (SIGNED(ctx->r12) > 0) {
        // 0x800A3380: nop
    
            goto L_800A338C;
    }
    // 0x800A3380: nop

    // 0x800A3384: b           L_800A33B0
    // 0x800A3388: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800A33B0;
    // 0x800A3388: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800A338C:
    // 0x800A338C: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x800A3390: nop

    // 0x800A3394: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x800A3398: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800A339C: bgez        $s1, L_800A33AC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800A33A0: sra         $t8, $s1, 3
        ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
            goto L_800A33AC;
    }
    // 0x800A33A0: sra         $t8, $s1, 3
    ctx->r24 = S32(SIGNED(ctx->r17) >> 3);
    // 0x800A33A4: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x800A33A8: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800A33AC:
    // 0x800A33AC: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
L_800A33B0:
    // 0x800A33B0: lw          $t0, 0x188($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X188);
    // 0x800A33B4: nop

    // 0x800A33B8: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800A33BC: bgez        $t6, L_800A33CC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800A33C0: sra         $t9, $t6, 3
        ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
            goto L_800A33CC;
    }
    // 0x800A33C0: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800A33C4: addiu       $at, $t6, 0x7
    ctx->r1 = ADD32(ctx->r14, 0X7);
    // 0x800A33C8: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800A33CC:
    // 0x800A33CC: bgtz        $t9, L_800A33DC
    if (SIGNED(ctx->r25) > 0) {
        // 0x800A33D0: nop
    
            goto L_800A33DC;
    }
    // 0x800A33D0: nop

    // 0x800A33D4: b           L_800A3400
    // 0x800A33D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800A3400;
    // 0x800A33D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800A33DC:
    // 0x800A33DC: lw          $s0, 0x188($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X188);
    // 0x800A33E0: nop

    // 0x800A33E4: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x800A33E8: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800A33EC: bgez        $s0, L_800A33FC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800A33F0: sra         $t5, $s0, 3
        ctx->r13 = S32(SIGNED(ctx->r16) >> 3);
            goto L_800A33FC;
    }
    // 0x800A33F0: sra         $t5, $s0, 3
    ctx->r13 = S32(SIGNED(ctx->r16) >> 3);
    // 0x800A33F4: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x800A33F8: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_800A33FC:
    // 0x800A33FC: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_800A3400:
    // 0x800A3400: addiu       $t7, $s1, 0x7FF
    ctx->r15 = ADD32(ctx->r17, 0X7FF);
    // 0x800A3404: div         $zero, $t7, $s0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r16)));
    // 0x800A3408: andi        $t1, $s2, 0xFFF
    ctx->r9 = ctx->r18 & 0XFFF;
    // 0x800A340C: bne         $s0, $zero, L_800A3418
    if (ctx->r16 != 0) {
        // 0x800A3410: nop
    
            goto L_800A3418;
    }
    // 0x800A3410: nop

    // 0x800A3414: break       7
    do_break(2148152340);
L_800A3418:
    // 0x800A3418: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A341C: bne         $s0, $at, L_800A3430
    if (ctx->r16 != ctx->r1) {
        // 0x800A3420: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A3430;
    }
    // 0x800A3420: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A3424: bne         $t7, $at, L_800A3430
    if (ctx->r15 != ctx->r1) {
        // 0x800A3428: nop
    
            goto L_800A3430;
    }
    // 0x800A3428: nop

    // 0x800A342C: break       6
    do_break(2148152364);
L_800A3430:
    // 0x800A3430: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800A3434: sll         $t8, $t1, 12
    ctx->r24 = S32(ctx->r9 << 12);
    // 0x800A3438: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800A343C: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x800A3440: mflo        $t3
    ctx->r11 = lo;
    // 0x800A3444: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x800A3448: or          $t6, $t4, $t0
    ctx->r14 = ctx->r12 | ctx->r8;
    // 0x800A344C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800A3450: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3454: nop

    // 0x800A3458: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A345C: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A3460: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x800A3464: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800A3468: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800A346C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x800A3470: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800A3474: nop

    // 0x800A3478: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A347C: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3480: nop

    // 0x800A3484: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x800A3488: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A348C: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x800A3490: lw          $t0, 0x188($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X188);
    // 0x800A3494: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800A3498: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800A349C: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x800A34A0: sra         $t2, $t9, 3
    ctx->r10 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800A34A4: andi        $t5, $t2, 0x1FF
    ctx->r13 = ctx->r10 & 0X1FF;
    // 0x800A34A8: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x800A34AC: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800A34B0: or          $t3, $t7, $at
    ctx->r11 = ctx->r15 | ctx->r1;
    // 0x800A34B4: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x800A34B8: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x800A34BC: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800A34C0: andi        $t4, $t8, 0xF
    ctx->r12 = ctx->r24 & 0XF;
    // 0x800A34C4: sll         $t0, $t4, 14
    ctx->r8 = S32(ctx->r12 << 14);
    // 0x800A34C8: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800A34CC: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x800A34D0: andi        $t5, $t2, 0xF
    ctx->r13 = ctx->r10 & 0XF;
    // 0x800A34D4: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800A34D8: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x800A34DC: ori         $t9, $t6, 0x100
    ctx->r25 = ctx->r14 | 0X100;
    // 0x800A34E0: or          $t3, $t9, $t7
    ctx->r11 = ctx->r25 | ctx->r15;
    // 0x800A34E4: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x800A34E8: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A34EC: nop

    // 0x800A34F0: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x800A34F4: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A34F8: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800A34FC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800A3500: lui         $t0, 0xF200
    ctx->r8 = S32(0XF200 << 16);
    // 0x800A3504: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x800A3508: lw          $t2, 0x188($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X188);
    // 0x800A350C: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A3510: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x800A3514: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800A3518: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x800A351C: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x800A3520: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800A3524: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800A3528: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x800A352C: andi        $t0, $t4, 0xFFF
    ctx->r8 = ctx->r12 & 0XFFF;
    // 0x800A3530: or          $t6, $t3, $t0
    ctx->r14 = ctx->r11 | ctx->r8;
    // 0x800A3534: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x800A3538: b           L_800A3778
    // 0x800A353C: nop

        goto L_800A3778;
    // 0x800A353C: nop

L_800A3540:
    // 0x800A3540: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3544: nop

    // 0x800A3548: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800A354C: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A3550: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x800A3554: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800A3558: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x800A355C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800A3560: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x800A3564: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800A3568: nop

    // 0x800A356C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x800A3570: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3574: nop

    // 0x800A3578: addiu       $t0, $t3, 0x8
    ctx->r8 = ADD32(ctx->r11, 0X8);
    // 0x800A357C: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A3580: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800A3584: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800A3588: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x800A358C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800A3590: lw          $t5, 0x178($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X178);
    // 0x800A3594: lw          $t4, 0x17C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X17C);
    // 0x800A3598: andi        $t9, $t5, 0xF
    ctx->r25 = ctx->r13 & 0XF;
    // 0x800A359C: sll         $t7, $t9, 14
    ctx->r15 = S32(ctx->r25 << 14);
    // 0x800A35A0: lui         $at, 0x704
    ctx->r1 = S32(0X704 << 16);
    // 0x800A35A4: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x800A35A8: andi        $t3, $t4, 0xF
    ctx->r11 = ctx->r12 & 0XF;
    // 0x800A35AC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800A35B0: sll         $t0, $t3, 4
    ctx->r8 = S32(ctx->r11 << 4);
    // 0x800A35B4: ori         $t8, $t1, 0x100
    ctx->r24 = ctx->r9 | 0X100;
    // 0x800A35B8: or          $t6, $t8, $t0
    ctx->r14 = ctx->r24 | ctx->r8;
    // 0x800A35BC: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x800A35C0: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    // 0x800A35C4: nop

    // 0x800A35C8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800A35CC: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A35D0: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x800A35D4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800A35D8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800A35DC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800A35E0: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800A35E4: nop

    // 0x800A35E8: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800A35EC: lw          $t3, 0x18C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18C);
    // 0x800A35F0: nop

    // 0x800A35F4: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x800A35F8: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A35FC: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x800A3600: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800A3604: lui         $t0, 0xF300
    ctx->r8 = S32(0XF300 << 16);
    // 0x800A3608: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x800A360C: lw          $t2, 0x188($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X188);
    // 0x800A3610: lw          $t5, 0x184($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X184);
    // 0x800A3614: nop

    // 0x800A3618: multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A361C: mflo        $t9
    ctx->r25 = lo;
    // 0x800A3620: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x800A3624: sra         $t1, $t7, 2
    ctx->r9 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800A3628: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x800A362C: slti        $at, $t4, 0x7FF
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF ? 1 : 0;
    // 0x800A3630: beq         $at, $zero, L_800A3640
    if (ctx->r1 == 0) {
        // 0x800A3634: nop
    
            goto L_800A3640;
    }
    // 0x800A3634: nop

    // 0x800A3638: b           L_800A3644
    // 0x800A363C: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
        goto L_800A3644;
    // 0x800A363C: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
L_800A3640:
    // 0x800A3640: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_800A3644:
    // 0x800A3644: b           L_800A3650
    // 0x800A3648: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800A3650;
    // 0x800A3648: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800A364C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800A3650:
    // 0x800A3650: b           L_800A365C
    // 0x800A3654: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800A365C;
    // 0x800A3654: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800A3658: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800A365C:
    // 0x800A365C: addiu       $t3, $s1, 0x7FF
    ctx->r11 = ADD32(ctx->r17, 0X7FF);
    // 0x800A3660: div         $zero, $t3, $s0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r16)));
    // 0x800A3664: andi        $t6, $s2, 0xFFF
    ctx->r14 = ctx->r18 & 0XFFF;
    // 0x800A3668: bne         $s0, $zero, L_800A3674
    if (ctx->r16 != 0) {
        // 0x800A366C: nop
    
            goto L_800A3674;
    }
    // 0x800A366C: nop

    // 0x800A3670: break       7
    do_break(2148152944);
L_800A3674:
    // 0x800A3674: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A3678: bne         $s0, $at, L_800A368C
    if (ctx->r16 != ctx->r1) {
        // 0x800A367C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A368C;
    }
    // 0x800A367C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A3680: bne         $t3, $at, L_800A368C
    if (ctx->r11 != ctx->r1) {
        // 0x800A3684: nop
    
            goto L_800A368C;
    }
    // 0x800A3684: nop

    // 0x800A3688: break       6
    do_break(2148152968);
L_800A368C:
    // 0x800A368C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800A3690: sll         $t2, $t6, 12
    ctx->r10 = S32(ctx->r14 << 12);
    // 0x800A3694: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800A3698: or          $t5, $t2, $at
    ctx->r13 = ctx->r10 | ctx->r1;
    // 0x800A369C: mflo        $t8
    ctx->r24 = lo;
    // 0x800A36A0: andi        $t0, $t8, 0xFFF
    ctx->r8 = ctx->r24 & 0XFFF;
    // 0x800A36A4: or          $t9, $t0, $t5
    ctx->r25 = ctx->r8 | ctx->r13;
    // 0x800A36A8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800A36AC: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A36B0: nop

    // 0x800A36B4: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x800A36B8: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A36BC: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800A36C0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800A36C4: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800A36C8: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800A36CC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800A36D0: nop

    // 0x800A36D4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A36D8: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A36DC: nop

    // 0x800A36E0: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A36E4: sw          $t0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r8;
    // 0x800A36E8: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x800A36EC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800A36F0: lui         $t5, 0xF540
    ctx->r13 = S32(0XF540 << 16);
    // 0x800A36F4: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800A36F8: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x800A36FC: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x800A3700: andi        $t1, $t7, 0xF
    ctx->r9 = ctx->r15 & 0XF;
    // 0x800A3704: sll         $t4, $t1, 14
    ctx->r12 = S32(ctx->r9 << 14);
    // 0x800A3708: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800A370C: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x800A3710: andi        $t2, $t6, 0xF
    ctx->r10 = ctx->r14 & 0XF;
    // 0x800A3714: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800A3718: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x800A371C: ori         $t8, $t3, 0x100
    ctx->r24 = ctx->r11 | 0X100;
    // 0x800A3720: or          $t5, $t8, $t0
    ctx->r13 = ctx->r24 | ctx->r8;
    // 0x800A3724: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x800A3728: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A372C: nop

    // 0x800A3730: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x800A3734: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A3738: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800A373C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A3740: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x800A3744: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A3748: lw          $t6, 0x188($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X188);
    // 0x800A374C: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800A3750: addiu       $t2, $t6, -0x1
    ctx->r10 = ADD32(ctx->r14, -0X1);
    // 0x800A3754: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x800A3758: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x800A375C: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x800A3760: andi        $t0, $t8, 0xFFF
    ctx->r8 = ctx->r24 & 0XFFF;
    // 0x800A3764: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A3768: sll         $t5, $t0, 12
    ctx->r13 = S32(ctx->r8 << 12);
    // 0x800A376C: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x800A3770: or          $t3, $t5, $t4
    ctx->r11 = ctx->r13 | ctx->r12;
    // 0x800A3774: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
L_800A3778:
    // 0x800A3778: lw          $t2, 0x18C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18C);
    // 0x800A377C: nop

    // 0x800A3780: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x800A3784: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800A3788: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800A378C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800A3790: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x800A3794: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800A3798: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800A379C: nop

    // 0x800A37A0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A37A4: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800A37A8: nop

    // 0x800A37AC: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x800A37B0: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800A37B4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x800A37B8: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x800A37BC: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x800A37C0: andi        $t3, $t4, 0xFFF
    ctx->r11 = ctx->r12 & 0XFFF;
    // 0x800A37C4: sll         $t6, $t3, 12
    ctx->r14 = S32(ctx->r11 << 12);
    // 0x800A37C8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800A37CC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A37D0: or          $t2, $t6, $at
    ctx->r10 = ctx->r14 | ctx->r1;
    // 0x800A37D4: andi        $t0, $t8, 0xFFF
    ctx->r8 = ctx->r24 & 0XFFF;
    // 0x800A37D8: or          $t9, $t2, $t0
    ctx->r25 = ctx->r10 | ctx->r8;
    // 0x800A37DC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A37E0: lw          $t1, 0x170($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X170);
    // 0x800A37E4: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x800A37E8: andi        $t5, $t1, 0xFFF
    ctx->r13 = ctx->r9 & 0XFFF;
    // 0x800A37EC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A37F0: sll         $t4, $t5, 12
    ctx->r12 = S32(ctx->r13 << 12);
    // 0x800A37F4: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x800A37F8: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x800A37FC: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x800A3800: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3804: nop

    // 0x800A3808: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800A380C: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A3810: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800A3814: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800A3818: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x800A381C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800A3820: lh          $t5, 0x162($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X162);
    // 0x800A3824: lh          $t6, 0x160($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X160);
    // 0x800A3828: andi        $t3, $t5, 0xFFFF
    ctx->r11 = ctx->r13 & 0XFFFF;
    // 0x800A382C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A3830: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800A3834: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800A3838: or          $t2, $t4, $t8
    ctx->r10 = ctx->r12 | ctx->r24;
    // 0x800A383C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800A3840: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3844: nop

    // 0x800A3848: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x800A384C: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800A3850: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800A3854: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A3858: lui         $t1, 0xB300
    ctx->r9 = S32(0XB300 << 16);
    // 0x800A385C: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
    // 0x800A3860: lh          $t3, 0x15E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X15E);
    // 0x800A3864: lh          $t8, 0x15C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X15C);
    // 0x800A3868: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800A386C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800A3870: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x800A3874: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x800A3878: or          $t0, $t4, $t2
    ctx->r8 = ctx->r12 | ctx->r10;
    // 0x800A387C: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800A3880: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A3884: nop

    // 0x800A3888: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x800A388C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800A3890: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800A3894: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800A3898: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800A389C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800A38A0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800A38A4: nop

    // 0x800A38A8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_800A38AC:
    // 0x800A38AC: b           L_800A25FC
    // 0x800A38B0: nop

        goto L_800A25FC;
    // 0x800A38B0: nop

L_800A38B4:
    // 0x800A38B4: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A38B8: nop

    // 0x800A38BC: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x800A38C0: sw          $t4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r12;
    // 0x800A38C4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800A38C8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800A38CC: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800A38D0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A38D4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800A38D8: nop

    // 0x800A38DC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A38E0: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800A38E4: lw          $t1, 0x190($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X190);
    // 0x800A38E8: nop

    // 0x800A38EC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800A38F0: b           L_800A3900
    // 0x800A38F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A3900;
    // 0x800A38F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A38F8: b           L_800A3900
    // 0x800A38FC: nop

        goto L_800A3900;
    // 0x800A38FC: nop

L_800A3900:
    // 0x800A3900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A3904: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A3908: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A390C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A3910: jr          $ra
    // 0x800A3914: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x800A3914: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void func_80063188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006318C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063190: jal         0x80061488
    // 0x80063194: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063194: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x80063198: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006319C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800631A0: b           L_800631B0
    // 0x800631A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800631B0;
    // 0x800631A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800631A8: b           L_800631B0
    // 0x800631AC: nop

        goto L_800631B0;
    // 0x800631AC: nop

L_800631B0:
    // 0x800631B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800631B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800631B8: jr          $ra
    // 0x800631BC: nop

    return;
    // 0x800631BC: nop

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
RECOMP_FUNC void func_80068928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006892C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068930: jal         0x80061488
    // 0x80068934: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068934: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    after_0:
    // 0x80068938: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006893C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068940: b           L_80068950
    // 0x80068944: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068950;
    // 0x80068944: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068948: b           L_80068950
    // 0x8006894C: nop

        goto L_80068950;
    // 0x8006894C: nop

L_80068950:
    // 0x80068950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068958: jr          $ra
    // 0x8006895C: nop

    return;
    // 0x8006895C: nop

;}
RECOMP_FUNC void func_800ACB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACB48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ACB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACB50: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800ACB54: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x800ACB58: nop

    // 0x800ACB5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800ACB60: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800ACB64:
    // 0x800ACB64: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800ACB68: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800ACB6C: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x800ACB70: nop

    // 0x800ACB74: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800ACB78: beq         $t9, $zero, L_800ACC04
    if (ctx->r25 == 0) {
        // 0x800ACB7C: nop
    
            goto L_800ACC04;
    }
    // 0x800ACB7C: nop

    // 0x800ACB80: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACB84: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800ACB88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACB8C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800ACB90: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800ACB94: lwc1        $f6, -0x7390($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7390);
    // 0x800ACB98: lwc1        $f4, 0xCC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x800ACB9C: nop

    // 0x800ACBA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACBA4: swc1        $f8, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f8.u32l;
    // 0x800ACBA8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACBAC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800ACBB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACBB4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800ACBB8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800ACBBC: lwc1        $f16, -0x738C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X738C);
    // 0x800ACBC0: lwc1        $f10, 0xD0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x800ACBC4: nop

    // 0x800ACBC8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ACBCC: swc1        $f18, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f18.u32l;
    // 0x800ACBD0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACBD4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800ACBD8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACBDC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800ACBE0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800ACBE4: lwc1        $f6, -0x7388($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7388);
    // 0x800ACBE8: lwc1        $f4, 0xD4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XD4);
    // 0x800ACBEC: nop

    // 0x800ACBF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACBF4: swc1        $f8, 0xD4($t6)
    MEM_W(0XD4, ctx->r14) = ctx->f8.u32l;
    // 0x800ACBF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACBFC: jal         0x800AC978
    // 0x800ACC00: nop

    func_800AC978(rdram, ctx);
        goto after_0;
    // 0x800ACC00: nop

    after_0:
L_800ACC04:
    // 0x800ACC04: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACC08: nop

    // 0x800ACC0C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800ACC10: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x800ACC14: bne         $at, $zero, L_800ACB64
    if (ctx->r1 != 0) {
        // 0x800ACC18: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_800ACB64;
    }
    // 0x800ACC18: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800ACC1C: b           L_800ACC24
    // 0x800ACC20: nop

        goto L_800ACC24;
    // 0x800ACC20: nop

L_800ACC24:
    // 0x800ACC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ACC28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800ACC2C: jr          $ra
    // 0x800ACC30: nop

    return;
    // 0x800ACC30: nop

;}
RECOMP_FUNC void func_800C3A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3A34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3A3C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800C3A40: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800C3A44: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3A48: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800C3A4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3A50: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C3A54: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x800C3A58: nop

    // 0x800C3A5C: bc1f        L_800C3A70
    if (!c1cs) {
        // 0x800C3A60: nop
    
            goto L_800C3A70;
    }
    // 0x800C3A60: nop

    // 0x800C3A64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3A68: b           L_800C3BA0
    // 0x800C3A6C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
        goto L_800C3BA0;
    // 0x800C3A6C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_800C3A70:
    // 0x800C3A70: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3A74: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800C3A78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3A7C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C3A80: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x800C3A84: nop

    // 0x800C3A88: bc1f        L_800C3B00
    if (!c1cs) {
        // 0x800C3A8C: nop
    
            goto L_800C3B00;
    }
    // 0x800C3A8C: nop

    // 0x800C3A90: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3A94: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800C3A98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3A9C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C3AA0: c.le.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d <= ctx->f8.d;
    // 0x800C3AA4: nop

    // 0x800C3AA8: bc1f        L_800C3AC8
    if (!c1cs) {
        // 0x800C3AAC: nop
    
            goto L_800C3AC8;
    }
    // 0x800C3AAC: nop

    // 0x800C3AB0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3AB4: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3AB8: jal         0x800C38F4
    // 0x800C3ABC: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    func_800C38F4(rdram, ctx);
        goto after_0;
    // 0x800C3ABC: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_0:
    // 0x800C3AC0: b           L_800C3AF8
    // 0x800C3AC4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_800C3AF8;
    // 0x800C3AC4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_800C3AC8:
    // 0x800C3AC8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3ACC: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3AD0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800C3AD4: jal         0x800C38F4
    // 0x800C3AD8: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    func_800C38F4(rdram, ctx);
        goto after_1;
    // 0x800C3AD8: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    after_1:
    // 0x800C3ADC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3AE0: lwc1        $f11, -0x138($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X138);
    // 0x800C3AE4: lwc1        $f10, -0x134($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X134);
    // 0x800C3AE8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800C3AEC: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x800C3AF0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800C3AF4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
L_800C3AF8:
    // 0x800C3AF8: b           L_800C3BA0
    // 0x800C3AFC: nop

        goto L_800C3BA0;
    // 0x800C3AFC: nop

L_800C3B00:
    // 0x800C3B00: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3B04: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800C3B08: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C3B0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3B10: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800C3B14: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800C3B18: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800C3B1C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800C3B20: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3B24: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800C3B28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3B2C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C3B30: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x800C3B34: nop

    // 0x800C3B38: bc1f        L_800C3B70
    if (!c1cs) {
        // 0x800C3B3C: nop
    
            goto L_800C3B70;
    }
    // 0x800C3B3C: nop

    // 0x800C3B40: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3B44: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3B48: jal         0x800C38F4
    // 0x800C3B4C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    func_800C38F4(rdram, ctx);
        goto after_2;
    // 0x800C3B4C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    after_2:
    // 0x800C3B50: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3B54: lwc1        $f19, -0x130($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X130);
    // 0x800C3B58: lwc1        $f18, -0x12C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X12C);
    // 0x800C3B5C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800C3B60: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x800C3B64: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800C3B68: b           L_800C3BA0
    // 0x800C3B6C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
        goto L_800C3BA0;
    // 0x800C3B6C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_800C3B70:
    // 0x800C3B70: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3B74: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3B78: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800C3B7C: jal         0x800C38F4
    // 0x800C3B80: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    func_800C38F4(rdram, ctx);
        goto after_3;
    // 0x800C3B80: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_3:
    // 0x800C3B84: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3B88: lwc1        $f7, -0x128($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X128);
    // 0x800C3B8C: lwc1        $f6, -0x124($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X124);
    // 0x800C3B90: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800C3B94: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800C3B98: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800C3B9C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_800C3BA0:
    // 0x800C3BA0: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3BA4: b           L_800C3BB4
    // 0x800C3BA8: nop

        goto L_800C3BB4;
    // 0x800C3BA8: nop

    // 0x800C3BAC: b           L_800C3BB4
    // 0x800C3BB0: nop

        goto L_800C3BB4;
    // 0x800C3BB0: nop

L_800C3BB4:
    // 0x800C3BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3BB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3BBC: jr          $ra
    // 0x800C3BC0: nop

    return;
    // 0x800C3BC0: nop

;}
RECOMP_FUNC void __lookupSoundQuick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D26D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D26D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800D26D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800D26DC: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x800D26E0: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x800D26E4: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800D26E8: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x800D26EC: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800D26F0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D26F4: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x800D26F8: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x800D26FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D2700: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x800D2704: blez        $t0, L_800D27C0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800D2708: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_800D27C0;
    }
    // 0x800D2708: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_800D270C:
    // 0x800D270C: bgez        $a1, L_800D271C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800D2710: sra         $t5, $a1, 1
        ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800D271C;
    }
    // 0x800D2710: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800D2714: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800D2718: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800D271C:
    // 0x800D271C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800D2720: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800D2724: lw          $a3, 0xC($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC);
    // 0x800D2728: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800D272C: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x800D2730: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x800D2734: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800D2738: bnel        $at, $zero, L_800D2780
    if (ctx->r1 != 0) {
        // 0x800D273C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D2780;
    }
    goto skip_0;
    // 0x800D273C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_0:
    // 0x800D2740: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x800D2744: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D2748: bnel        $at, $zero, L_800D2780
    if (ctx->r1 != 0) {
        // 0x800D274C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D2780;
    }
    goto skip_1;
    // 0x800D274C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_1:
    // 0x800D2750: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800D2754: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800D2758: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D275C: bnel        $at, $zero, L_800D2780
    if (ctx->r1 != 0) {
        // 0x800D2760: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D2780;
    }
    goto skip_2;
    // 0x800D2760: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_2:
    // 0x800D2764: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x800D2768: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D276C: bnel        $at, $zero, L_800D2780
    if (ctx->r1 != 0) {
        // 0x800D2770: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800D2780;
    }
    goto skip_3;
    // 0x800D2770: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x800D2774: jr          $ra
    // 0x800D2778: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800D2778: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800D277C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_800D2780:
    // 0x800D2780: bne         $at, $zero, L_800D27A8
    if (ctx->r1 != 0) {
        // 0x800D2784: nop
    
            goto L_800D27A8;
    }
    // 0x800D2784: nop

    // 0x800D2788: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800D278C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800D2790: beql        $at, $zero, L_800D27B4
    if (ctx->r1 == 0) {
        // 0x800D2794: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_800D27B4;
    }
    goto skip_4;
    // 0x800D2794: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x800D2798: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x800D279C: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D27A0: bnel        $at, $zero, L_800D27B4
    if (ctx->r1 != 0) {
        // 0x800D27A4: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_800D27B4;
    }
    goto skip_5;
    // 0x800D27A4: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_5:
L_800D27A8:
    // 0x800D27A8: b           L_800D27B4
    // 0x800D27AC: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_800D27B4;
    // 0x800D27AC: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x800D27B0: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_800D27B4:
    // 0x800D27B4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D27B8: beql        $at, $zero, L_800D270C
    if (ctx->r1 == 0) {
        // 0x800D27BC: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_800D270C;
    }
    goto skip_6;
    // 0x800D27BC: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    skip_6:
L_800D27C0:
    // 0x800D27C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D27C4: jr          $ra
    // 0x800D27C8: nop

    return;
    // 0x800D27C8: nop

;}
RECOMP_FUNC void func_8001AC74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AC74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001AC78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AC7C: jal         0x80016074
    // 0x8001AC80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x8001AC80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001AC84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001AC88: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AC8C: nop

    // 0x8001AC90: bne         $t6, $zero, L_8001ACA0
    if (ctx->r14 != 0) {
        // 0x8001AC94: nop
    
            goto L_8001ACA0;
    }
    // 0x8001AC94: nop

    // 0x8001AC98: b           L_8001ACCC
    // 0x8001AC9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001ACCC;
    // 0x8001AC9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001ACA0:
    // 0x8001ACA0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ACA4: nop

    // 0x8001ACA8: lw          $a0, 0x20C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X20C);
    // 0x8001ACAC: jal         0x80096374
    // 0x8001ACB0: nop

    func_80096374(rdram, ctx);
        goto after_1;
    // 0x8001ACB0: nop

    after_1:
    // 0x8001ACB4: jal         0x800967D8
    // 0x8001ACB8: nop

    func_800967D8(rdram, ctx);
        goto after_2;
    // 0x8001ACB8: nop

    after_2:
    // 0x8001ACBC: b           L_8001ACCC
    // 0x8001ACC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001ACCC;
    // 0x8001ACC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001ACC4: b           L_8001ACCC
    // 0x8001ACC8: nop

        goto L_8001ACCC;
    // 0x8001ACC8: nop

L_8001ACCC:
    // 0x8001ACCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ACD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001ACD4: jr          $ra
    // 0x8001ACD8: nop

    return;
    // 0x8001ACD8: nop

;}
RECOMP_FUNC void func_8007369C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007369C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800736A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800736A4: nop

    // 0x800736A8: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800736AC: nop

    // 0x800736B0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800736B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800736B8: jr          $ra
    // 0x800736BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800736BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800736C0: jr          $ra
    // 0x800736C4: nop

    return;
    // 0x800736C4: nop

    // 0x800736C8: jr          $ra
    // 0x800736CC: nop

    return;
    // 0x800736CC: nop

;}
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
RECOMP_FUNC void func_8007150C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007150C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071514: jal         0x80061348
    // 0x80071518: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071518: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_0:
    // 0x8007151C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80071520: b           L_80071530
    // 0x80071524: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80071530;
    // 0x80071524: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071528: b           L_80071530
    // 0x8007152C: nop

        goto L_80071530;
    // 0x8007152C: nop

L_80071530:
    // 0x80071530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071538: jr          $ra
    // 0x8007153C: nop

    return;
    // 0x8007153C: nop

;}
RECOMP_FUNC void ObjectCheckDebugMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F390: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001F394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F398: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001F39C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F3A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001F3A4: jal         0x8008EAA8
    // 0x8001F3A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001F3A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001F3AC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001F3B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F3B4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001F3B8: jal         0x8008ECE4
    // 0x8001F3BC: addiu       $a0, $a0, -0x2480
    ctx->r4 = ADD32(ctx->r4, -0X2480);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001F3BC: addiu       $a0, $a0, -0x2480
    ctx->r4 = ADD32(ctx->r4, -0X2480);
    after_1:
    // 0x8001F3C0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001F3C4: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x8001F3C8: nop

    // 0x8001F3CC: beq         $s0, $zero, L_8001F3E8
    if (ctx->r16 == 0) {
        // 0x8001F3D0: nop
    
            goto L_8001F3E8;
    }
    // 0x8001F3D0: nop

    // 0x8001F3D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F3D8: beq         $s0, $at, L_8001F53C
    if (ctx->r16 == ctx->r1) {
        // 0x8001F3DC: nop
    
            goto L_8001F53C;
    }
    // 0x8001F3DC: nop

    // 0x8001F3E0: b           L_8001F54C
    // 0x8001F3E4: nop

        goto L_8001F54C;
    // 0x8001F3E4: nop

L_8001F3E8:
    // 0x8001F3E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8001F3EC:
    // 0x8001F3EC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F3F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F3F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001F3F8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001F3FC: sw          $zero, 0x25F0($at)
    MEM_W(0X25F0, ctx->r1) = 0;
    // 0x8001F400: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F404: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F408: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001F40C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8001F410: sw          $zero, 0x2618($at)
    MEM_W(0X2618, ctx->r1) = 0;
    // 0x8001F414: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F418: nop

    // 0x8001F41C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001F420: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8001F424: bne         $at, $zero, L_8001F3EC
    if (ctx->r1 != 0) {
        // 0x8001F428: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_8001F3EC;
    }
    // 0x8001F428: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8001F42C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8001F430: addiu       $a0, $a0, 0x25F0
    ctx->r4 = ADD32(ctx->r4, 0X25F0);
    // 0x8001F434: jal         0x8001F60C
    // 0x8001F438: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    ObjectCheckDebugMenu_LoadSpriteHeader(rdram, ctx);
        goto after_2;
    // 0x8001F438: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x8001F43C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F440: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x8001F444: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x8001F448: lui         $t4, 0x807A
    ctx->r12 = S32(0X807A << 16);
    // 0x8001F44C: lui         $t5, 0x8079
    ctx->r13 = S32(0X8079 << 16);
    // 0x8001F450: addiu       $t5, $t5, -0x2E40
    ctx->r13 = ADD32(ctx->r13, -0X2E40);
    // 0x8001F454: addiu       $t4, $t4, -0x6E40
    ctx->r12 = ADD32(ctx->r12, -0X6E40);
    // 0x8001F458: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8001F45C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001F460: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001F464: bgez        $t6, L_8001F474
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001F468: sra         $t7, $t6, 9
        ctx->r15 = S32(SIGNED(ctx->r14) >> 9);
            goto L_8001F474;
    }
    // 0x8001F468: sra         $t7, $t6, 9
    ctx->r15 = S32(SIGNED(ctx->r14) >> 9);
    // 0x8001F46C: addiu       $at, $t6, 0x1FF
    ctx->r1 = ADD32(ctx->r14, 0X1FF);
    // 0x8001F470: sra         $t7, $at, 9
    ctx->r15 = S32(SIGNED(ctx->r1) >> 9);
L_8001F474:
    // 0x8001F474: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x8001F478: jal         0x800BC6EC
    // 0x8001F47C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x8001F47C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_3:
    // 0x8001F480: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F484: addiu       $t9, $t9, 0x2618
    ctx->r25 = ADD32(ctx->r25, 0X2618);
    // 0x8001F488: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x8001F48C: jal         0x800BC6EC
    // 0x8001F490: addiu       $a0, $zero, 0xB00
    ctx->r4 = ADD32(0, 0XB00);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8001F490: addiu       $a0, $zero, 0xB00
    ctx->r4 = ADD32(0, 0XB00);
    after_4:
    // 0x8001F494: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001F498: addiu       $t0, $t0, 0x2618
    ctx->r8 = ADD32(ctx->r8, 0X2618);
    // 0x8001F49C: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x8001F4A0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F4A4: addiu       $t1, $t1, 0x2618
    ctx->r9 = ADD32(ctx->r9, 0X2618);
    // 0x8001F4A8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8001F4AC: nop

    // 0x8001F4B0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8001F4B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F4B8: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x8001F4BC: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8001F4C0: nop

    // 0x8001F4C4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8001F4C8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8001F4CC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8001F4D0: jal         0x800B1B3C
    // 0x8001F4D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800B1B3C(rdram, ctx);
        goto after_5;
    // 0x8001F4D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x8001F4D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F4DC: addiu       $t5, $t5, 0x2618
    ctx->r13 = ADD32(ctx->r13, 0X2618);
    // 0x8001F4E0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8001F4E4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8001F4E8: nop

    // 0x8001F4EC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8001F4F0:
    // 0x8001F4F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001F4F4: jal         0x80099E2C
    // 0x8001F4F8: nop

    func_80099E2C(rdram, ctx);
        goto after_6;
    // 0x8001F4F8: nop

    after_6:
    // 0x8001F4FC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001F500: nop

    // 0x8001F504: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x8001F508: nop

    // 0x8001F50C: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x8001F510: sw          $t9, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r25;
    // 0x8001F514: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F518: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8001F51C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001F520: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8001F524: addiu       $t3, $t2, 0x160
    ctx->r11 = ADD32(ctx->r10, 0X160);
    // 0x8001F528: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8001F52C: bne         $at, $zero, L_8001F4F0
    if (ctx->r1 != 0) {
        // 0x8001F530: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_8001F4F0;
    }
    // 0x8001F530: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8001F534: b           L_8001F54C
    // 0x8001F538: nop

        goto L_8001F54C;
    // 0x8001F538: nop

L_8001F53C:
    // 0x8001F53C: jal         0x8001F800
    // 0x8001F540: nop

    ObjectCheckDebugMenu_Update(rdram, ctx);
        goto after_7;
    // 0x8001F540: nop

    after_7:
    // 0x8001F544: jal         0x8001F6B8
    // 0x8001F548: nop

    ObjectCheckDebugMenu_DrawUI(rdram, ctx);
        goto after_8;
    // 0x8001F548: nop

    after_8:
L_8001F54C:
    // 0x8001F54C: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001F550: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8001F554: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001F558: lhu         $t6, 0x11A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X11A4);
    // 0x8001F55C: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8001F560: nop

    // 0x8001F564: and         $t8, $t5, $t6
    ctx->r24 = ctx->r13 & ctx->r14;
    // 0x8001F568: beq         $t8, $zero, L_8001F5EC
    if (ctx->r24 == 0) {
        // 0x8001F56C: nop
    
            goto L_8001F5EC;
    }
    // 0x8001F56C: nop

    // 0x8001F570: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F574: addiu       $t9, $t9, 0x2618
    ctx->r25 = ADD32(ctx->r25, 0X2618);
    // 0x8001F578: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001F57C: jal         0x800BC980
    // 0x8001F580: nop

    SysMem_Free(rdram, ctx);
        goto after_9;
    // 0x8001F580: nop

    after_9:
    // 0x8001F584: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001F588: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8001F58C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8001F590: nop

    // 0x8001F594: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8001F598: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001F59C: addiu       $t2, $t2, 0x2618
    ctx->r10 = ADD32(ctx->r10, 0X2618);
    // 0x8001F5A0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8001F5A4: nop

    // 0x8001F5A8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8001F5AC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8001F5B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8001F5B4: jal         0x800B1C10
    // 0x8001F5B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800B1C10(rdram, ctx);
        goto after_10;
    // 0x8001F5B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_10:
    // 0x8001F5BC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F5C0: addiu       $t1, $t1, 0x2618
    ctx->r9 = ADD32(ctx->r9, 0X2618);
    // 0x8001F5C4: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x8001F5C8: jal         0x800BC980
    // 0x8001F5CC: nop

    SysMem_Free(rdram, ctx);
        goto after_11;
    // 0x8001F5CC: nop

    after_11:
    // 0x8001F5D0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001F5D4: addiu       $t4, $t4, 0x2618
    ctx->r12 = ADD32(ctx->r12, 0X2618);
    // 0x8001F5D8: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x8001F5DC: jal         0x800BC980
    // 0x8001F5E0: nop

    SysMem_Free(rdram, ctx);
        goto after_12;
    // 0x8001F5E0: nop

    after_12:
    // 0x8001F5E4: b           L_8001F5FC
    // 0x8001F5E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001F5FC;
    // 0x8001F5E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001F5EC:
    // 0x8001F5EC: b           L_8001F5FC
    // 0x8001F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F5FC;
    // 0x8001F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F5F4: b           L_8001F5FC
    // 0x8001F5F8: nop

        goto L_8001F5FC;
    // 0x8001F5F8: nop

L_8001F5FC:
    // 0x8001F5FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F600: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F604: jr          $ra
    // 0x8001F608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001F608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80067988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006798C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067990: jal         0x80061488
    // 0x80067994: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067994: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    after_0:
    // 0x80067998: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006799C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800679A0: b           L_800679B0
    // 0x800679A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800679B0;
    // 0x800679A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800679A8: b           L_800679B0
    // 0x800679AC: nop

        goto L_800679B0;
    // 0x800679AC: nop

L_800679B0:
    // 0x800679B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800679B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800679B8: jr          $ra
    // 0x800679BC: nop

    return;
    // 0x800679BC: nop

;}
RECOMP_FUNC void func_8006CFB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CFB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CFBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CFC0: nop

    // 0x8006CFC4: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x8006CFC8: nop

    // 0x8006CFCC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CFD0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CFD4: jr          $ra
    // 0x8006CFD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CFD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CFDC: jr          $ra
    // 0x8006CFE0: nop

    return;
    // 0x8006CFE0: nop

    // 0x8006CFE4: jr          $ra
    // 0x8006CFE8: nop

    return;
    // 0x8006CFE8: nop

;}
RECOMP_FUNC void func_8000F4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F4B0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000F4B4: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x8000F4B8: nop

    // 0x8000F4BC: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8000F4C0: lw          $t7, 0x1A8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1A8);
    // 0x8000F4C4: nop

    // 0x8000F4C8: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8000F4CC: beq         $t8, $zero, L_8000F4EC
    if (ctx->r24 == 0) {
        // 0x8000F4D0: nop
    
            goto L_8000F4EC;
    }
    // 0x8000F4D0: nop

    // 0x8000F4D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F4D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000F4DC: lwc1        $f4, 0x1F0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1F0);
    // 0x8000F4E0: nop

    // 0x8000F4E4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000F4E8: swc1        $f8, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f8.u32l;
L_8000F4EC:
    // 0x8000F4EC: lw          $t9, 0x1A8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1A8);
    // 0x8000F4F0: nop

    // 0x8000F4F4: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x8000F4F8: beq         $t0, $zero, L_8000F51C
    if (ctx->r8 == 0) {
        // 0x8000F4FC: nop
    
            goto L_8000F51C;
    }
    // 0x8000F4FC: nop

    // 0x8000F500: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8000F504: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x8000F508: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x8000F50C: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x8000F510: nop

    // 0x8000F514: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8000F518: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
L_8000F51C:
    // 0x8000F51C: lw          $t4, 0x1A8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1A8);
    // 0x8000F520: addiu       $at, $zero, -0x181
    ctx->r1 = ADD32(0, -0X181);
    // 0x8000F524: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8000F528: sw          $t5, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->r13;
    // 0x8000F52C: b           L_8000F534
    // 0x8000F530: nop

        goto L_8000F534;
    // 0x8000F530: nop

L_8000F534:
    // 0x8000F534: jr          $ra
    // 0x8000F538: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000F538: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_80061488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061488: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006148C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80061490: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80061494: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x80061498: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006149C: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x800614A0: nop

    // 0x800614A4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800614A8: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800614AC: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800614B0: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800614B4: nop

    // 0x800614B8: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800614BC: bne         $at, $zero, L_800615B0
    if (ctx->r1 != 0) {
        // 0x800614C0: nop
    
            goto L_800615B0;
    }
    // 0x800614C0: nop

L_800614C4:
    // 0x800614C4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800614C8: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800614CC: nop

    // 0x800614D0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800614D4: bgez        $t2, L_800614E4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800614D8: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800614E4;
    }
    // 0x800614D8: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800614DC: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800614E0: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800614E4:
    // 0x800614E4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800614E8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800614EC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800614F0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800614F4: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x800614F8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800614FC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80061500: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80061504: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061508: nop

    // 0x8006150C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061510: beq         $at, $zero, L_8006152C
    if (ctx->r1 == 0) {
        // 0x80061514: nop
    
            goto L_8006152C;
    }
    // 0x80061514: nop

    // 0x80061518: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8006151C: nop

    // 0x80061520: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80061524: b           L_80061598
    // 0x80061528: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_80061598;
    // 0x80061528: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_8006152C:
    // 0x8006152C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061530: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80061534: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80061538: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x8006153C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80061540: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80061544: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80061548: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8006154C: nop

    // 0x80061550: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80061554: beq         $at, $zero, L_80061570
    if (ctx->r1 == 0) {
        // 0x80061558: nop
    
            goto L_80061570;
    }
    // 0x80061558: nop

    // 0x8006155C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80061560: nop

    // 0x80061564: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80061568: b           L_80061598
    // 0x8006156C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_80061598;
    // 0x8006156C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_80061570:
    // 0x80061570: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80061574: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80061578: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006157C: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x80061580: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80061584: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80061588: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x8006158C: lbu         $v0, 0x3($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X3);
    // 0x80061590: b           L_800615C0
    // 0x80061594: nop

        goto L_800615C0;
    // 0x80061594: nop

L_80061598:
    // 0x80061598: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8006159C: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800615A0: nop

    // 0x800615A4: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800615A8: beq         $at, $zero, L_800614C4
    if (ctx->r1 == 0) {
        // 0x800615AC: nop
    
            goto L_800614C4;
    }
    // 0x800615AC: nop

L_800615B0:
    // 0x800615B0: b           L_800615C0
    // 0x800615B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800615C0;
    // 0x800615B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800615B8: b           L_800615C0
    // 0x800615BC: nop

        goto L_800615C0;
    // 0x800615BC: nop

L_800615C0:
    // 0x800615C0: jr          $ra
    // 0x800615C4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800615C4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80074F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074F40: jal         0x80061348
    // 0x80074F44: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074F44: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x80074F48: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80074F4C: b           L_80074F5C
    // 0x80074F50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80074F5C;
    // 0x80074F50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074F54: b           L_80074F5C
    // 0x80074F58: nop

        goto L_80074F5C;
    // 0x80074F58: nop

L_80074F5C:
    // 0x80074F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074F64: jr          $ra
    // 0x80074F68: nop

    return;
    // 0x80074F68: nop

;}
RECOMP_FUNC void func_800712C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800712C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800712C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800712C8: jal         0x80061348
    // 0x800712CC: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800712CC: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_0:
    // 0x800712D0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800712D4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800712D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800712DC: beq         $v0, $zero, L_80071330
    if (ctx->r2 == 0) {
        // 0x800712E0: nop
    
            goto L_80071330;
    }
    // 0x800712E0: nop

    // 0x800712E4: jal         0x80061348
    // 0x800712E8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800712E8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x800712EC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800712F0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800712F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800712F8: beq         $v0, $zero, L_80071330
    if (ctx->r2 == 0) {
        // 0x800712FC: nop
    
            goto L_80071330;
    }
    // 0x800712FC: nop

    // 0x80071300: jal         0x80061348
    // 0x80071304: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071304: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80071308: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007130C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071310: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071314: beq         $v0, $zero, L_80071330
    if (ctx->r2 == 0) {
        // 0x80071318: nop
    
            goto L_80071330;
    }
    // 0x80071318: nop

    // 0x8007131C: jal         0x80061348
    // 0x80071320: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071320: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_3:
    // 0x80071324: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071328: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007132C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071330:
    // 0x80071330: b           L_80071340
    // 0x80071334: nop

        goto L_80071340;
    // 0x80071334: nop

    // 0x80071338: b           L_80071340
    // 0x8007133C: nop

        goto L_80071340;
    // 0x8007133C: nop

L_80071340:
    // 0x80071340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071348: jr          $ra
    // 0x8007134C: nop

    return;
    // 0x8007134C: nop

;}
RECOMP_FUNC void func_800B7F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7F2C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B7F30: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800B7F34:
    // 0x800B7F34: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800B7F38: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B7F3C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B7F40: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x800B7F44: sh          $t6, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r14;
    // 0x800B7F48: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7F4C: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800B7F50: nop

    // 0x800B7F54: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B7F58: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x800B7F5C: bne         $at, $zero, L_800B7F34
    if (ctx->r1 != 0) {
        // 0x800B7F60: sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
            goto L_800B7F34;
    }
    // 0x800B7F60: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800B7F64: addiu       $t2, $sp, 0x4
    ctx->r10 = ADD32(ctx->r29, 0X4);
    // 0x800B7F68: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x800B7F6C: nop

    // 0x800B7F70: bne         $t3, $zero, L_800B7F98
    if (ctx->r11 != 0) {
        // 0x800B7F74: nop
    
            goto L_800B7F98;
    }
    // 0x800B7F74: nop

    // 0x800B7F78: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800B7F7C: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x800B7F80: nop

    // 0x800B7F84: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800B7F88: nop

    // 0x800B7F8C: ori         $t7, $t5, 0x200
    ctx->r15 = ctx->r13 | 0X200;
    // 0x800B7F90: b           L_800B7FB4
    // 0x800B7F94: sh          $t7, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r15;
        goto L_800B7FB4;
    // 0x800B7F94: sh          $t7, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r15;
L_800B7F98:
    // 0x800B7F98: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B7F9C: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B7FA0: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800B7FA4: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800B7FA8: nop

    // 0x800B7FAC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800B7FB0: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
L_800B7FB4:
    // 0x800B7FB4: b           L_800B7FC4
    // 0x800B7FB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B7FC4;
    // 0x800B7FB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B7FBC: b           L_800B7FC4
    // 0x800B7FC0: nop

        goto L_800B7FC4;
    // 0x800B7FC0: nop

L_800B7FC4:
    // 0x800B7FC4: jr          $ra
    // 0x800B7FC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B7FC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8007332C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007332C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073334: jal         0x80061488
    // 0x80073338: addiu       $a0, $zero, 0x518
    ctx->r4 = ADD32(0, 0X518);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073338: addiu       $a0, $zero, 0x518
    ctx->r4 = ADD32(0, 0X518);
    after_0:
    // 0x8007333C: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80073340: b           L_80073350
    // 0x80073344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073350;
    // 0x80073344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073348: b           L_80073350
    // 0x8007334C: nop

        goto L_80073350;
    // 0x8007334C: nop

L_80073350:
    // 0x80073350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073358: jr          $ra
    // 0x8007335C: nop

    return;
    // 0x8007335C: nop

;}
RECOMP_FUNC void func_80063F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063F74: jal         0x80061488
    // 0x80063F78: addiu       $a0, $zero, 0x5E1
    ctx->r4 = ADD32(0, 0X5E1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063F78: addiu       $a0, $zero, 0x5E1
    ctx->r4 = ADD32(0, 0X5E1);
    after_0:
    // 0x80063F7C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063F80: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063F84: b           L_80063F94
    // 0x80063F88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063F94;
    // 0x80063F88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063F8C: b           L_80063F94
    // 0x80063F90: nop

        goto L_80063F94;
    // 0x80063F90: nop

L_80063F94:
    // 0x80063F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063F9C: jr          $ra
    // 0x80063FA0: nop

    return;
    // 0x80063FA0: nop

;}
RECOMP_FUNC void func_8005F01C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F01C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005F020: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F024:
    // 0x8005F024: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005F028: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005F02C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8005F030: sb          $zero, 0x680($at)
    MEM_B(0X680, ctx->r1) = 0;
    // 0x8005F034: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005F038: nop

    // 0x8005F03C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8005F040: slti        $at, $t8, 0x40
    ctx->r1 = SIGNED(ctx->r24) < 0X40 ? 1 : 0;
    // 0x8005F044: bne         $at, $zero, L_8005F024
    if (ctx->r1 != 0) {
        // 0x8005F048: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_8005F024;
    }
    // 0x8005F048: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8005F04C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8005F050: sb          $zero, 0x7208($at)
    MEM_B(0X7208, ctx->r1) = 0;
    // 0x8005F054: b           L_8005F05C
    // 0x8005F058: nop

        goto L_8005F05C;
    // 0x8005F058: nop

L_8005F05C:
    // 0x8005F05C: jr          $ra
    // 0x8005F060: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005F060: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005218C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005218C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052194: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80052198: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005219C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800521A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800521A4: jal         0x80016138
    // 0x800521A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_0;
    // 0x800521A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x800521AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800521B0: bne         $v0, $at, L_800521D8
    if (ctx->r2 != ctx->r1) {
        // 0x800521B4: nop
    
            goto L_800521D8;
    }
    // 0x800521B4: nop

L_800521B8:
    // 0x800521B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800521BC: jal         0x800499B0
    // 0x800521C0: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x800521C0: nop

    after_1:
    // 0x800521C4: jal         0x80016138
    // 0x800521C8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_2;
    // 0x800521C8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_2:
    // 0x800521CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800521D0: beq         $v0, $at, L_800521B8
    if (ctx->r2 == ctx->r1) {
        // 0x800521D4: nop
    
            goto L_800521B8;
    }
    // 0x800521D4: nop

L_800521D8:
    // 0x800521D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800521DC: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800521E0: addiu       $at, $zero, 0xAD
    ctx->r1 = ADD32(0, 0XAD);
    // 0x800521E4: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x800521E8: nop

    // 0x800521EC: beq         $t7, $at, L_80052200
    if (ctx->r15 == ctx->r1) {
        // 0x800521F0: nop
    
            goto L_80052200;
    }
    // 0x800521F0: nop

    // 0x800521F4: addiu       $at, $zero, 0xAE
    ctx->r1 = ADD32(0, 0XAE);
    // 0x800521F8: bne         $t7, $at, L_8005220C
    if (ctx->r15 != ctx->r1) {
        // 0x800521FC: nop
    
            goto L_8005220C;
    }
    // 0x800521FC: nop

L_80052200:
    // 0x80052200: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052204: jal         0x800507AC
    // 0x80052208: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    func_800507AC(rdram, ctx);
        goto after_3;
    // 0x80052208: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_3:
L_8005220C:
    // 0x8005220C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052210: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052214: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80052218: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005221C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80052220: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80052224: bne         $t2, $zero, L_80052234
    if (ctx->r10 != 0) {
        // 0x80052228: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80052234;
    }
    // 0x80052228: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8005222C: beq         $t3, $zero, L_80052294
    if (ctx->r11 == 0) {
        // 0x80052230: nop
    
            goto L_80052294;
    }
    // 0x80052230: nop

L_80052234:
    // 0x80052234: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052238: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x8005223C: jal         0x80051804
    // 0x80052240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80051804(rdram, ctx);
        goto after_4;
    // 0x80052240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80052244: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    // 0x80052248: jal         0x80056E88
    // 0x8005224C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_5;
    // 0x8005224C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80052250: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80052254: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80052258: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8005225C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052260: jal         0x800507AC
    // 0x80052264: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_6;
    // 0x80052264: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80052268: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005226C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80052270: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052274: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80052278: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8005227C: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80052280: lui         $at, 0xFFEF
    ctx->r1 = S32(0XFFEF << 16);
    // 0x80052284: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80052288: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8005228C: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80052290: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_80052294:
    // 0x80052294: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80052298: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005229C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800522A0: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x800522A4: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x800522A8: bne         $t2, $zero, L_800522B8
    if (ctx->r10 != 0) {
        // 0x800522AC: andi        $t3, $t1, 0x10
        ctx->r11 = ctx->r9 & 0X10;
            goto L_800522B8;
    }
    // 0x800522AC: andi        $t3, $t1, 0x10
    ctx->r11 = ctx->r9 & 0X10;
    // 0x800522B0: beq         $t3, $zero, L_800523A0
    if (ctx->r11 == 0) {
        // 0x800522B4: nop
    
            goto L_800523A0;
    }
    // 0x800522B4: nop

L_800522B8:
    // 0x800522B8: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x800522BC: jal         0x800574CC
    // 0x800522C0: nop

    func_800574CC(rdram, ctx);
        goto after_7;
    // 0x800522C0: nop

    after_7:
    // 0x800522C4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800522C8: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800522CC: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800522D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800522D4: jal         0x80056E88
    // 0x800522D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_8;
    // 0x800522D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800522DC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800522E0: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800522E4: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800522E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800522EC: jal         0x800507AC
    // 0x800522F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_9;
    // 0x800522F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800522F4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800522F8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800522FC: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80052300: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80052304: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x80052308: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x8005230C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052310: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x80052314: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80052318: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8005231C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x80052320: jal         0x80056E88
    // 0x80052324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_10;
    // 0x80052324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80052328: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8005232C: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80052330: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80052334: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052338: jal         0x800507AC
    // 0x8005233C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_11;
    // 0x8005233C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80052340: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80052344: jal         0x80056E88
    // 0x80052348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_12;
    // 0x80052348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8005234C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052350: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80052354: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80052358: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005235C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80052360: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80052364: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80052368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005236C: jal         0x8004EF90
    // 0x80052370: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_13;
    // 0x80052370: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80052374: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052378: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005237C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052380: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x80052384: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x80052388: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x8005238C: addiu       $at, $zero, -0x71
    ctx->r1 = ADD32(0, -0X71);
    // 0x80052390: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x80052394: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80052398: b           L_800524EC
    // 0x8005239C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
        goto L_800524EC;
    // 0x8005239C: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
L_800523A0:
    // 0x800523A0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800523A4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x800523A8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800523AC: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800523B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800523B4: bne         $t2, $zero, L_800523C4
    if (ctx->r10 != 0) {
        // 0x800523B8: andi        $t3, $t9, 0x20
        ctx->r11 = ctx->r25 & 0X20;
            goto L_800523C4;
    }
    // 0x800523B8: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x800523BC: beq         $t3, $zero, L_80052448
    if (ctx->r11 == 0) {
        // 0x800523C0: nop
    
            goto L_80052448;
    }
    // 0x800523C0: nop

L_800523C4:
    // 0x800523C4: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x800523C8: jal         0x80056E88
    // 0x800523CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_14;
    // 0x800523CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x800523D0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800523D4: sra         $t4, $s0, 16
    ctx->r12 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800523D8: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x800523DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800523E0: jal         0x800507AC
    // 0x800523E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_15;
    // 0x800523E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x800523E8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x800523EC: jal         0x80056E88
    // 0x800523F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_16;
    // 0x800523F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x800523F4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800523F8: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x800523FC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80052400: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80052404: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80052408: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8005240C: lh          $a1, 0x42($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X42);
    // 0x80052410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052414: jal         0x8004EF90
    // 0x80052418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_17;
    // 0x80052418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x8005241C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052420: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80052424: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052428: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8005242C: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x80052430: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80052434: addiu       $at, $zero, -0x61
    ctx->r1 = ADD32(0, -0X61);
    // 0x80052438: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8005243C: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80052440: b           L_800524EC
    // 0x80052444: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
        goto L_800524EC;
    // 0x80052444: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_80052448:
    // 0x80052448: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005244C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80052450: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80052454: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80052458: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8005245C: bne         $t0, $zero, L_8005246C
    if (ctx->r8 != 0) {
        // 0x80052460: andi        $t1, $t5, 0x40
        ctx->r9 = ctx->r13 & 0X40;
            goto L_8005246C;
    }
    // 0x80052460: andi        $t1, $t5, 0x40
    ctx->r9 = ctx->r13 & 0X40;
    // 0x80052464: beq         $t1, $zero, L_800524EC
    if (ctx->r9 == 0) {
        // 0x80052468: nop
    
            goto L_800524EC;
    }
    // 0x80052468: nop

L_8005246C:
    // 0x8005246C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x80052470: jal         0x80056E88
    // 0x80052474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_18;
    // 0x80052474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80052478: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8005247C: sra         $t3, $s0, 16
    ctx->r11 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80052480: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80052484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052488: jal         0x800507AC
    // 0x8005248C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_19;
    // 0x8005248C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x80052490: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80052494: jal         0x80056E88
    // 0x80052498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_20;
    // 0x80052498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8005249C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800524A0: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800524A4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800524A8: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800524AC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800524B0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800524B4: lh          $a1, 0x42($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X42);
    // 0x800524B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800524BC: jal         0x8004EF90
    // 0x800524C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_21;
    // 0x800524C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x800524C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800524C8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800524CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800524D0: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800524D4: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x800524D8: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x800524DC: addiu       $at, $zero, -0x61
    ctx->r1 = ADD32(0, -0X61);
    // 0x800524E0: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800524E4: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x800524E8: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
L_800524EC:
    // 0x800524EC: b           L_800524F4
    // 0x800524F0: nop

        goto L_800524F4;
    // 0x800524F0: nop

L_800524F4:
    // 0x800524F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800524F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800524FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80052500: jr          $ra
    // 0x80052504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80052504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800ABAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABAC8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800ABACC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800ABAD0:
    // 0x800ABAD0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800ABAD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABAD8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800ABADC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800ABAE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800ABAE4: sh          $t6, -0x4CB8($at)
    MEM_H(-0X4CB8, ctx->r1) = ctx->r14;
    // 0x800ABAE8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800ABAEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABAF0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800ABAF4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800ABAF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ABAFC: sh          $t9, -0x4CB6($at)
    MEM_H(-0X4CB6, ctx->r1) = ctx->r25;
    // 0x800ABB00: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800ABB04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABB08: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800ABB0C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800ABB10: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ABB14: sh          $t2, -0x4CB4($at)
    MEM_H(-0X4CB4, ctx->r1) = ctx->r10;
    // 0x800ABB18: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800ABB1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABB20: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800ABB24: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800ABB28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ABB2C: sh          $t5, -0x4CB2($at)
    MEM_H(-0X4CB2, ctx->r1) = ctx->r13;
    // 0x800ABB30: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800ABB34: nop

    // 0x800ABB38: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800ABB3C: slti        $at, $t0, 0xF0
    ctx->r1 = SIGNED(ctx->r8) < 0XF0 ? 1 : 0;
    // 0x800ABB40: bne         $at, $zero, L_800ABAD0
    if (ctx->r1 != 0) {
        // 0x800ABB44: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_800ABAD0;
    }
    // 0x800ABB44: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800ABB48: b           L_800ABB50
    // 0x800ABB4C: nop

        goto L_800ABB50;
    // 0x800ABB4C: nop

L_800ABB50:
    // 0x800ABB50: jr          $ra
    // 0x800ABB54: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800ABB54: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_800723E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800723E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800723EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800723F0: jal         0x80061488
    // 0x800723F4: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800723F4: addiu       $a0, $zero, 0x44C
    ctx->r4 = ADD32(0, 0X44C);
    after_0:
    // 0x800723F8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800723FC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80072400: b           L_80072410
    // 0x80072404: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072410;
    // 0x80072404: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072408: b           L_80072410
    // 0x8007240C: nop

        goto L_80072410;
    // 0x8007240C: nop

L_80072410:
    // 0x80072410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072418: jr          $ra
    // 0x8007241C: nop

    return;
    // 0x8007241C: nop

;}
RECOMP_FUNC void alEvtqPostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3A2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D3A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3A34: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D3A38: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D3A3C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800D3A40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D3A44: jal         0x800C41A0
    // 0x800D3A48: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3A48: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D3A4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800D3A50: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D3A54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D3A58: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800D3A5C: bne         $t0, $zero, L_800D3A74
    if (ctx->r8 != 0) {
        // 0x800D3A60: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800D3A74;
    }
    // 0x800D3A60: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800D3A64: jal         0x800C41A0
    // 0x800D3A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D3A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D3A6C: b           L_800D3B44
    // 0x800D3A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3B44;
    // 0x800D3A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3A74:
    // 0x800D3A74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D3A78: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800D3A7C: jal         0x800C7890
    // 0x800D3A80: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800D3A80: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800D3A84: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3A88: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800D3A8C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800D3A90: jal         0x800D6320
    // 0x800D3A94: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alCopy(rdram, ctx);
        goto after_3;
    // 0x800D3A94: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800D3A98: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800D3A9C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800D3AA0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D3AA4: bne         $a3, $at, L_800D3AB4
    if (ctx->r7 != ctx->r1) {
        // 0x800D3AA8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800D3AB4;
    }
    // 0x800D3AA8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3AAC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D3AB0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800D3AB4:
    // 0x800D3AB4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800D3AB8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D3ABC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D3AC0: beq         $v0, $at, L_800D3B38
    if (ctx->r2 == ctx->r1) {
        // 0x800D3AC4: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_800D3B38;
    }
    // 0x800D3AC4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_800D3AC8:
    // 0x800D3AC8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800D3ACC: bnel        $v0, $zero, L_800D3AFC
    if (ctx->r2 != 0) {
        // 0x800D3AD0: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800D3AFC;
    }
    goto skip_0;
    // 0x800D3AD0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800D3AD4: beql        $t8, $zero, L_800D3AE8
    if (ctx->r24 == 0) {
        // 0x800D3AD8: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_800D3AE8;
    }
    goto skip_1;
    // 0x800D3AD8: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x800D3ADC: b           L_800D3AE8
    // 0x800D3AE0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_800D3AE8;
    // 0x800D3AE0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x800D3AE4: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_800D3AE8:
    // 0x800D3AE8: jal         0x800C78C0
    // 0x800D3AEC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800D3AEC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x800D3AF0: b           L_800D3B38
    // 0x800D3AF4: nop

        goto L_800D3B38;
    // 0x800D3AF4: nop

    // 0x800D3AF8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800D3AFC:
    // 0x800D3AFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3B00: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D3B04: beql        $at, $zero, L_800D3B30
    if (ctx->r1 == 0) {
        // 0x800D3B08: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D3B30;
    }
    goto skip_2;
    // 0x800D3B08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x800D3B0C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x800D3B10: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800D3B14: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800D3B18: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x800D3B1C: jal         0x800C78C0
    // 0x800D3B20: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800D3B20: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    after_5:
    // 0x800D3B24: b           L_800D3B38
    // 0x800D3B28: nop

        goto L_800D3B38;
    // 0x800D3B28: nop

    // 0x800D3B2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D3B30:
    // 0x800D3B30: bne         $v0, $zero, L_800D3AC8
    if (ctx->r2 != 0) {
        // 0x800D3B34: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_800D3AC8;
    }
    // 0x800D3B34: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_800D3B38:
    // 0x800D3B38: jal         0x800C41A0
    // 0x800D3B3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800D3B3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x800D3B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3B44:
    // 0x800D3B44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D3B48: jr          $ra
    // 0x800D3B4C: nop

    return;
    // 0x800D3B4C: nop

;}
RECOMP_FUNC void func_80060FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060FB8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80060FBC: addiu       $t7, $t7, -0x24B0
    ctx->r15 = ADD32(ctx->r15, -0X24B0);
    // 0x80060FC0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80060FC4: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80060FC8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80060FCC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80060FD0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80060FD4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80060FD8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80060FDC: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80060FE0: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80060FE4: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x80060FE8: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80060FEC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80060FF0: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x80060FF4: bne         $at, $zero, L_80061000
    if (ctx->r1 != 0) {
        // 0x80060FF8: nop
    
            goto L_80061000;
    }
    // 0x80060FF8: nop

    // 0x80060FFC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80061000:
    // 0x80061000: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80061004: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80061008: lw          $t2, 0x4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4);
    // 0x8006100C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80061010: lw          $t4, 0x644($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X644);
    // 0x80061014: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80061018: b           L_80061028
    // 0x8006101C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
        goto L_80061028;
    // 0x8006101C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80061020: b           L_80061028
    // 0x80061024: nop

        goto L_80061028;
    // 0x80061024: nop

L_80061028:
    // 0x80061028: jr          $ra
    // 0x8006102C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006102C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80066F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066F10: jal         0x80061348
    // 0x80066F14: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066F14: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80066F18: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066F20: bne         $v0, $zero, L_80066F68
    if (ctx->r2 != 0) {
        // 0x80066F24: nop
    
            goto L_80066F68;
    }
    // 0x80066F24: nop

    // 0x80066F28: jal         0x80061348
    // 0x80066F2C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066F2C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x80066F30: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066F38: bne         $v0, $zero, L_80066F68
    if (ctx->r2 != 0) {
        // 0x80066F3C: nop
    
            goto L_80066F68;
    }
    // 0x80066F3C: nop

    // 0x80066F40: jal         0x80061348
    // 0x80066F44: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80066F44: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_2:
    // 0x80066F48: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F4C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80066F50: bne         $v0, $zero, L_80066F68
    if (ctx->r2 != 0) {
        // 0x80066F54: nop
    
            goto L_80066F68;
    }
    // 0x80066F54: nop

    // 0x80066F58: jal         0x80061348
    // 0x80066F5C: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80066F5C: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_3:
    // 0x80066F60: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F64: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80066F68:
    // 0x80066F68: b           L_80066F78
    // 0x80066F6C: nop

        goto L_80066F78;
    // 0x80066F6C: nop

    // 0x80066F70: b           L_80066F78
    // 0x80066F74: nop

        goto L_80066F78;
    // 0x80066F74: nop

L_80066F78:
    // 0x80066F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066F80: jr          $ra
    // 0x80066F84: nop

    return;
    // 0x80066F84: nop

;}
RECOMP_FUNC void func_80096EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096EB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80096EB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80096EB8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80096EBC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80096EC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80096EC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096EC8: sw          $t6, 0x4CA4($at)
    MEM_W(0X4CA4, ctx->r1) = ctx->r14;
    // 0x80096ECC: b           L_80096ED4
    // 0x80096ED0: nop

        goto L_80096ED4;
    // 0x80096ED0: nop

L_80096ED4:
    // 0x80096ED4: jr          $ra
    // 0x80096ED8: nop

    return;
    // 0x80096ED8: nop

;}
RECOMP_FUNC void func_80066274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006627C: jal         0x80061348
    // 0x80066280: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066280: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80066284: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066288: b           L_80066298
    // 0x8006628C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066298;
    // 0x8006628C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066290: b           L_80066298
    // 0x80066294: nop

        goto L_80066298;
    // 0x80066294: nop

L_80066298:
    // 0x80066298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006629C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800662A0: jr          $ra
    // 0x800662A4: nop

    return;
    // 0x800662A4: nop

;}
RECOMP_FUNC void func_800B3314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B331C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B3320: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3324: jal         0x800B3590
    // 0x800B3328: nop

    func_800B3590(rdram, ctx);
        goto after_0;
    // 0x800B3328: nop

    after_0:
    // 0x800B332C: b           L_800B333C
    // 0x800B3330: nop

        goto L_800B333C;
    // 0x800B3330: nop

    // 0x800B3334: b           L_800B333C
    // 0x800B3338: nop

        goto L_800B333C;
    // 0x800B3338: nop

L_800B333C:
    // 0x800B333C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3344: jr          $ra
    // 0x800B3348: nop

    return;
    // 0x800B3348: nop

;}
