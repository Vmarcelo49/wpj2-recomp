#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006A930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A938: jal         0x80061348
    // 0x8006A93C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006A93C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x8006A940: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A944: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A948: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A94C: beq         $v0, $zero, L_8006A968
    if (ctx->r2 == 0) {
        // 0x8006A950: nop
    
            goto L_8006A968;
    }
    // 0x8006A950: nop

    // 0x8006A954: jal         0x80061348
    // 0x8006A958: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006A958: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    after_1:
    // 0x8006A95C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A960: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006A964: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8006A968:
    // 0x8006A968: b           L_8006A978
    // 0x8006A96C: nop

        goto L_8006A978;
    // 0x8006A96C: nop

    // 0x8006A970: b           L_8006A978
    // 0x8006A974: nop

        goto L_8006A978;
    // 0x8006A974: nop

L_8006A978:
    // 0x8006A978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A980: jr          $ra
    // 0x8006A984: nop

    return;
    // 0x8006A984: nop

;}
RECOMP_FUNC void func_800752E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800752E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800752EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800752F0: jal         0x80061348
    // 0x800752F4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800752F4: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    after_0:
    // 0x800752F8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800752FC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075300: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075304: beq         $v0, $zero, L_80075358
    if (ctx->r2 == 0) {
        // 0x80075308: nop
    
            goto L_80075358;
    }
    // 0x80075308: nop

    // 0x8007530C: jal         0x80061348
    // 0x80075310: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075310: addiu       $a0, $zero, 0x4DF
    ctx->r4 = ADD32(0, 0X4DF);
    after_1:
    // 0x80075314: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075318: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007531C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075320: beq         $v0, $zero, L_80075358
    if (ctx->r2 == 0) {
        // 0x80075324: nop
    
            goto L_80075358;
    }
    // 0x80075324: nop

    // 0x80075328: jal         0x80061348
    // 0x8007532C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007532C: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    after_2:
    // 0x80075330: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075334: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075338: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007533C: beq         $v0, $zero, L_80075358
    if (ctx->r2 == 0) {
        // 0x80075340: nop
    
            goto L_80075358;
    }
    // 0x80075340: nop

    // 0x80075344: jal         0x80061348
    // 0x80075348: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075348: addiu       $a0, $zero, 0x4E1
    ctx->r4 = ADD32(0, 0X4E1);
    after_3:
    // 0x8007534C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075350: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075354: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075358:
    // 0x80075358: b           L_80075368
    // 0x8007535C: nop

        goto L_80075368;
    // 0x8007535C: nop

    // 0x80075360: b           L_80075368
    // 0x80075364: nop

        goto L_80075368;
    // 0x80075364: nop

L_80075368:
    // 0x80075368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007536C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075370: jr          $ra
    // 0x80075374: nop

    return;
    // 0x80075374: nop

;}
RECOMP_FUNC void func_80062CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062CA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062CB0: jal         0x80061348
    // 0x80062CB4: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80062CB4: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    after_0:
    // 0x80062CB8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80062CBC: b           L_80062CCC
    // 0x80062CC0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062CCC;
    // 0x80062CC0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062CC4: b           L_80062CCC
    // 0x80062CC8: nop

        goto L_80062CCC;
    // 0x80062CC8: nop

L_80062CCC:
    // 0x80062CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062CD4: jr          $ra
    // 0x80062CD8: nop

    return;
    // 0x80062CD8: nop

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
RECOMP_FUNC void func_80064604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064604: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064608: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006460C: nop

    // 0x80064610: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064614: nop

    // 0x80064618: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006461C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064620: jr          $ra
    // 0x80064624: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064624: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064628: jr          $ra
    // 0x8006462C: nop

    return;
    // 0x8006462C: nop

    // 0x80064630: jr          $ra
    // 0x80064634: nop

    return;
    // 0x80064634: nop

;}
RECOMP_FUNC void __allocParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C00: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C7C04: lw          $v0, -0x33E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33E0);
    // 0x800C7C08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C7C0C: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x800C7C10: beq         $a0, $zero, L_800C7C28
    if (ctx->r4 == 0) {
        // 0x800C7C14: nop
    
            goto L_800C7C28;
    }
    // 0x800C7C14: nop

    // 0x800C7C18: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C7C1C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7C20: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x800C7C24: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800C7C28:
    // 0x800C7C28: jr          $ra
    // 0x800C7C2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C7C2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
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
RECOMP_FUNC void ContPak_GetPakInitilizationResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE398: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE39C: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE3A0: nop

    // 0x800AE3A4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800AE3A8: beq         $t7, $zero, L_800AE3B8
    if (ctx->r15 == 0) {
        // 0x800AE3AC: nop
    
            goto L_800AE3B8;
    }
    // 0x800AE3AC: nop

    // 0x800AE3B0: jr          $ra
    // 0x800AE3B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE3B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE3B8:
    // 0x800AE3B8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE3BC: lw          $t8, 0x1350($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1350);
    // 0x800AE3C0: nop

    // 0x800AE3C4: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800AE3C8: beq         $t9, $zero, L_800AE3D8
    if (ctx->r25 == 0) {
        // 0x800AE3CC: nop
    
            goto L_800AE3D8;
    }
    // 0x800AE3CC: nop

    // 0x800AE3D0: jr          $ra
    // 0x800AE3D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE3D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE3D8:
    // 0x800AE3D8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE3DC: lw          $t0, 0x1690($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1690);
    // 0x800AE3E0: nop

    // 0x800AE3E4: beq         $t0, $zero, L_800AE3F4
    if (ctx->r8 == 0) {
        // 0x800AE3E8: nop
    
            goto L_800AE3F4;
    }
    // 0x800AE3E8: nop

    // 0x800AE3EC: jr          $ra
    // 0x800AE3F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800AE3F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AE3F4:
    // 0x800AE3F4: jr          $ra
    // 0x800AE3F8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    return;
    // 0x800AE3F8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x800AE3FC: jr          $ra
    // 0x800AE400: nop

    return;
    // 0x800AE400: nop

    // 0x800AE404: jr          $ra
    // 0x800AE408: nop

    return;
    // 0x800AE408: nop

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
RECOMP_FUNC void func_8005C90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C90C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005C910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005C914: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8005C918: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8005C91C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8005C920: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005C924: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005C928: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005C92C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8005C930: nop

    // 0x8005C934: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8005C938: nop

    // 0x8005C93C: bc1f        L_8005C94C
    if (!c1cs) {
        // 0x8005C940: nop
    
            goto L_8005C94C;
    }
    // 0x8005C940: nop

    // 0x8005C944: b           L_8005C960
    // 0x8005C948: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
        goto L_8005C960;
    // 0x8005C948: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_8005C94C:
    // 0x8005C94C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8005C950: nop

    // 0x8005C954: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8005C958: nop

    // 0x8005C95C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
L_8005C960:
    // 0x8005C960: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005C964: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005C968: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8005C96C: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8005C970: nop

    // 0x8005C974: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005C978: nop

    // 0x8005C97C: bc1f        L_8005C98C
    if (!c1cs) {
        // 0x8005C980: nop
    
            goto L_8005C98C;
    }
    // 0x8005C980: nop

    // 0x8005C984: b           L_8005C9A0
    // 0x8005C988: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
        goto L_8005C9A0;
    // 0x8005C988: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
L_8005C98C:
    // 0x8005C98C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005C990: nop

    // 0x8005C994: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8005C998: nop

    // 0x8005C99C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_8005C9A0:
    // 0x8005C9A0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005C9A4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005C9A8: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8005C9AC: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8005C9B0: nop

    // 0x8005C9B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005C9B8: nop

    // 0x8005C9BC: bc1f        L_8005C9CC
    if (!c1cs) {
        // 0x8005C9C0: nop
    
            goto L_8005C9CC;
    }
    // 0x8005C9C0: nop

    // 0x8005C9C4: b           L_8005C9E0
    // 0x8005C9C8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
        goto L_8005C9E0;
    // 0x8005C9C8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
L_8005C9CC:
    // 0x8005C9CC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005C9D0: nop

    // 0x8005C9D4: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8005C9D8: nop

    // 0x8005C9DC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
L_8005C9E0:
    // 0x8005C9E0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005C9E4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005C9E8: lwc1        $f16, 0xC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8005C9EC: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8005C9F0: nop

    // 0x8005C9F4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8005C9F8: nop

    // 0x8005C9FC: bc1f        L_8005CA0C
    if (!c1cs) {
        // 0x8005CA00: nop
    
            goto L_8005CA0C;
    }
    // 0x8005CA00: nop

    // 0x8005CA04: b           L_8005CA20
    // 0x8005CA08: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
        goto L_8005CA20;
    // 0x8005CA08: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
L_8005CA0C:
    // 0x8005CA0C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005CA10: nop

    // 0x8005CA14: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005CA18: nop

    // 0x8005CA1C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
L_8005CA20:
    // 0x8005CA20: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005CA24: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005CA28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005CA2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005CA30: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8005CA34: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005CA38: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005CA3C: nop

    // 0x8005CA40: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8005CA44: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005CA48: addiu       $t8, $t8, 0xE80
    ctx->r24 = ADD32(ctx->r24, 0XE80);
    // 0x8005CA4C: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8005CA50: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005CA54: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x8005CA58: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005CA5C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005CA60: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005CA64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005CA68: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005CA6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005CA70: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005CA74: nop

    // 0x8005CA78: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x8005CA7C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005CA80: addiu       $t0, $t0, 0xE80
    ctx->r8 = ADD32(ctx->r8, 0XE80);
    // 0x8005CA84: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8005CA88: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005CA8C: swc1        $f6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f6.u32l;
    // 0x8005CA90: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005CA94: addiu       $t2, $t2, 0xE80
    ctx->r10 = ADD32(ctx->r10, 0XE80);
    // 0x8005CA98: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x8005CA9C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8005CAA0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8005CAA4: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8005CAA8: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x8005CAAC: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8005CAB0: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8005CAB4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8005CAB8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005CABC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005CAC0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8005CAC4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005CAC8: bne         $t2, $zero, L_8005CAD8
    if (ctx->r10 != 0) {
        // 0x8005CACC: andi        $t3, $t1, 0x8
        ctx->r11 = ctx->r9 & 0X8;
            goto L_8005CAD8;
    }
    // 0x8005CACC: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x8005CAD0: beq         $t3, $zero, L_8005CB04
    if (ctx->r11 == 0) {
        // 0x8005CAD4: nop
    
            goto L_8005CB04;
    }
    // 0x8005CAD4: nop

L_8005CAD8:
    // 0x8005CAD8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005CADC: addiu       $t9, $t9, 0xE80
    ctx->r25 = ADD32(ctx->r25, 0XE80);
    // 0x8005CAE0: lw          $t4, 0x18($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X18);
    // 0x8005CAE4: nop

    // 0x8005CAE8: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8005CAEC: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8005CAF0: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x8005CAF4: ori         $t9, $t7, 0x8
    ctx->r25 = ctx->r15 | 0X8;
    // 0x8005CAF8: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8005CAFC: b           L_8005CB30
    // 0x8005CB00: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
        goto L_8005CB30;
    // 0x8005CB00: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_8005CB04:
    // 0x8005CB04: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005CB08: addiu       $t5, $t5, 0xE80
    ctx->r13 = ADD32(ctx->r13, 0XE80);
    // 0x8005CB0C: lw          $t0, 0x18($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X18);
    // 0x8005CB10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005CB14: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8005CB18: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8005CB1C: and         $t6, $t2, $at
    ctx->r14 = ctx->r10 & ctx->r1;
    // 0x8005CB20: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8005CB24: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8005CB28: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8005CB2C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_8005CB30:
    // 0x8005CB30: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005CB34: addiu       $t1, $t1, 0xE80
    ctx->r9 = ADD32(ctx->r9, 0XE80);
    // 0x8005CB38: lw          $a0, 0x18($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X18);
    // 0x8005CB3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005CB40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005CB44: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8005CB48: addiu       $a2, $zero, 0x19A
    ctx->r6 = ADD32(0, 0X19A);
    // 0x8005CB4C: jal         0x8004F3E8
    // 0x8005CB50: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    func_8004F3E8(rdram, ctx);
        goto after_0;
    // 0x8005CB50: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    after_0:
    // 0x8005CB54: b           L_8005CB5C
    // 0x8005CB58: nop

        goto L_8005CB5C;
    // 0x8005CB58: nop

L_8005CB5C:
    // 0x8005CB5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CB60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005CB64: jr          $ra
    // 0x8005CB68: nop

    return;
    // 0x8005CB68: nop

;}
RECOMP_FUNC void func_8006F4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F4A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F4AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F4B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F4B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F4B8: nop

    // 0x8006F4BC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006F4C0: nop

    // 0x8006F4C4: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x8006F4C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F4CC: beq         $v0, $zero, L_8006F4E8
    if (ctx->r2 == 0) {
        // 0x8006F4D0: nop
    
            goto L_8006F4E8;
    }
    // 0x8006F4D0: nop

    // 0x8006F4D4: jal         0x80061488
    // 0x8006F4D8: addiu       $a0, $zero, 0x575
    ctx->r4 = ADD32(0, 0X575);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006F4D8: addiu       $a0, $zero, 0x575
    ctx->r4 = ADD32(0, 0X575);
    after_0:
    // 0x8006F4DC: slti        $t8, $v0, 0x2
    ctx->r24 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006F4E0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006F4E4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006F4E8:
    // 0x8006F4E8: b           L_8006F4F8
    // 0x8006F4EC: nop

        goto L_8006F4F8;
    // 0x8006F4EC: nop

    // 0x8006F4F0: b           L_8006F4F8
    // 0x8006F4F4: nop

        goto L_8006F4F8;
    // 0x8006F4F4: nop

L_8006F4F8:
    // 0x8006F4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F500: jr          $ra
    // 0x8006F504: nop

    return;
    // 0x8006F504: nop

;}
RECOMP_FUNC void func_800A66EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A66EC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A66F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A66F4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800A66F8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800A66FC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800A6700: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800A6704: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A6708: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A670C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800A6710: nop

    // 0x800A6714: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800A6718: nop

    // 0x800A671C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800A6720: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800A6724: nop

    // 0x800A6728: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800A672C: jal         0x800BC6EC
    // 0x800A6730: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800A6730: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x800A6734: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800A6738: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A673C: nop

    // 0x800A6740: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A6744: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A6748: nop

    // 0x800A674C: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800A6750: beq         $at, $zero, L_800A6788
    if (ctx->r1 == 0) {
        // 0x800A6754: nop
    
            goto L_800A6788;
    }
    // 0x800A6754: nop

    // 0x800A6758: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800A675C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800A6760: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800A6764: lw          $t3, 0x193C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X193C);
    // 0x800A6768: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800A676C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800A6770: sll         $t4, $a2, 1
    ctx->r12 = S32(ctx->r6 << 1);
    // 0x800A6774: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800A6778: jal         0x800BD218
    // 0x800A677C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800A677C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x800A6780: b           L_800A67B0
    // 0x800A6784: nop

        goto L_800A67B0;
    // 0x800A6784: nop

L_800A6788:
    // 0x800A6788: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800A678C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800A6790: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800A6794: lw          $t7, 0x3DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3DB0);
    // 0x800A6798: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800A679C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800A67A0: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800A67A4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800A67A8: jal         0x800BD218
    // 0x800A67AC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800A67AC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_2:
L_800A67B0:
    // 0x800A67B0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A67B4: nop

    // 0x800A67B8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800A67BC: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x800A67C0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800A67C4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800A67C8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800A67CC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800A67D0: blez        $t2, L_800A6EF8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800A67D4: nop
    
            goto L_800A6EF8;
    }
    // 0x800A67D4: nop

L_800A67D8:
    // 0x800A67D8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800A67DC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800A67E0: nop

    // 0x800A67E4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A67E8: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x800A67EC: bne         $at, $zero, L_800A67FC
    if (ctx->r1 != 0) {
        // 0x800A67F0: nop
    
            goto L_800A67FC;
    }
    // 0x800A67F0: nop

    // 0x800A67F4: b           L_800A6F0C
    // 0x800A67F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A6F0C;
    // 0x800A67F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A67FC:
    // 0x800A67FC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800A6800: nop

    // 0x800A6804: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800A6808: beq         $at, $zero, L_800A6858
    if (ctx->r1 == 0) {
        // 0x800A680C: nop
    
            goto L_800A6858;
    }
    // 0x800A680C: nop

    // 0x800A6810: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A6814: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A6818: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A681C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A6820: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A6824: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A6828: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A682C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A6830: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x800A6834: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A6838: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A683C: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800A6840: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A6844: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800A6848: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800A684C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800A6850: b           L_800A6960
    // 0x800A6854: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
        goto L_800A6960;
    // 0x800A6854: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_800A6858:
    // 0x800A6858: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800A685C: nop

    // 0x800A6860: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800A6864: beq         $at, $zero, L_800A68B8
    if (ctx->r1 == 0) {
        // 0x800A6868: nop
    
            goto L_800A68B8;
    }
    // 0x800A6868: nop

    // 0x800A686C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800A6870: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800A6874: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A6878: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800A687C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800A6880: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A6884: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A6888: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800A688C: lw          $t7, -0x73DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73DC);
    // 0x800A6890: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800A6894: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800A6898: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800A689C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800A68A0: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800A68A4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A68A8: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x800A68AC: addiu       $t2, $t9, -0x580
    ctx->r10 = ADD32(ctx->r25, -0X580);
    // 0x800A68B0: b           L_800A6960
    // 0x800A68B4: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
        goto L_800A6960;
    // 0x800A68B4: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_800A68B8:
    // 0x800A68B8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800A68BC: nop

    // 0x800A68C0: slti        $at, $t3, 0xC
    ctx->r1 = SIGNED(ctx->r11) < 0XC ? 1 : 0;
    // 0x800A68C4: beq         $at, $zero, L_800A6918
    if (ctx->r1 == 0) {
        // 0x800A68C8: nop
    
            goto L_800A6918;
    }
    // 0x800A68C8: nop

    // 0x800A68CC: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800A68D0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800A68D4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800A68D8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A68DC: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800A68E0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A68E4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A68E8: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800A68EC: lw          $t6, -0x73D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73D0);
    // 0x800A68F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A68F4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A68F8: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800A68FC: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800A6900: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800A6904: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800A6908: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x800A690C: addiu       $t9, $t1, -0xB00
    ctx->r25 = ADD32(ctx->r9, -0XB00);
    // 0x800A6910: b           L_800A6960
    // 0x800A6914: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
        goto L_800A6960;
    // 0x800A6914: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_800A6918:
    // 0x800A6918: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800A691C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A6920: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A6924: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800A6928: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x800A692C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A6930: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A6934: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800A6938: lw          $t4, -0x73C4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73C4);
    // 0x800A693C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800A6940: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800A6944: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800A6948: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800A694C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x800A6950: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A6954: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x800A6958: addiu       $t8, $t7, -0x1080
    ctx->r24 = ADD32(ctx->r15, -0X1080);
    // 0x800A695C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
L_800A6960:
    // 0x800A6960: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6964: jal         0x800A6514
    // 0x800A6968: nop

    func_800A6514(rdram, ctx);
        goto after_3;
    // 0x800A6968: nop

    after_3:
    // 0x800A696C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A6970: nop

    // 0x800A6974: bne         $t1, $zero, L_800A6CEC
    if (ctx->r9 != 0) {
        // 0x800A6978: nop
    
            goto L_800A6CEC;
    }
    // 0x800A6978: nop

    // 0x800A697C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A6980: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6984: lhu         $t2, 0x4($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X4);
    // 0x800A6988: nop

    // 0x800A698C: sh          $t2, 0x10C($t3)
    MEM_H(0X10C, ctx->r11) = ctx->r10;
    // 0x800A6990: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A6994: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6998: lhu         $t6, 0x6($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X6);
    // 0x800A699C: nop

    // 0x800A69A0: sh          $t6, 0x10E($t5)
    MEM_H(0X10E, ctx->r13) = ctx->r14;
    // 0x800A69A4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A69A8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800A69AC: lhu         $t7, 0x8($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X8);
    // 0x800A69B0: nop

    // 0x800A69B4: sw          $t7, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->r15;
    // 0x800A69B8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800A69BC: nop

    // 0x800A69C0: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x800A69C4: beq         $at, $zero, L_800A6A3C
    if (ctx->r1 == 0) {
        // 0x800A69C8: nop
    
            goto L_800A6A3C;
    }
    // 0x800A69C8: nop

    // 0x800A69CC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800A69D0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A69D4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800A69D8: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x800A69DC: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x800A69E0: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x800A69E4: jal         0x800BD1FC
    // 0x800A69E8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x800A69E8: nop

    after_4:
    // 0x800A69EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A69F0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800A69F4: nop

    // 0x800A69F8: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800A69FC: nop

    // 0x800A6A00: beq         $t3, $zero, L_800A6A30
    if (ctx->r11 == 0) {
        // 0x800A6A04: nop
    
            goto L_800A6A30;
    }
    // 0x800A6A04: nop

    // 0x800A6A08: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A0C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A6A10: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800A6A14: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x800A6A18: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x800A6A1C: lw          $a2, 0x8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X8);
    // 0x800A6A20: jal         0x800BD1FC
    // 0x800A6A24: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x800A6A24: nop

    after_5:
    // 0x800A6A28: b           L_800A6A34
    // 0x800A6A2C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_800A6A34;
    // 0x800A6A2C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_800A6A30:
    // 0x800A6A30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A6A34:
    // 0x800A6A34: b           L_800A6AA4
    // 0x800A6A38: nop

        goto L_800A6AA4;
    // 0x800A6A38: nop

L_800A6A3C:
    // 0x800A6A3C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A40: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A6A44: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800A6A48: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800A6A4C: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800A6A50: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x800A6A54: jal         0x800BD1FC
    // 0x800A6A58: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x800A6A58: nop

    after_6:
    // 0x800A6A5C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A6A60: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A64: nop

    // 0x800A6A68: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x800A6A6C: nop

    // 0x800A6A70: beq         $t0, $zero, L_800A6AA0
    if (ctx->r8 == 0) {
        // 0x800A6A74: nop
    
            goto L_800A6AA0;
    }
    // 0x800A6A74: nop

    // 0x800A6A78: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A7C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A6A80: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800A6A84: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800A6A88: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800A6A8C: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x800A6A90: jal         0x800BD1FC
    // 0x800A6A94: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_7;
    // 0x800A6A94: nop

    after_7:
    // 0x800A6A98: b           L_800A6AA4
    // 0x800A6A9C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_800A6AA4;
    // 0x800A6A9C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_800A6AA0:
    // 0x800A6AA0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A6AA4:
    // 0x800A6AA4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800A6AA8: nop

    // 0x800A6AAC: beq         $t8, $zero, L_800A6BAC
    if (ctx->r24 == 0) {
        // 0x800A6AB0: nop
    
            goto L_800A6BAC;
    }
    // 0x800A6AB0: nop

    // 0x800A6AB4: jal         0x800BC6EC
    // 0x800A6AB8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x800A6AB8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_8:
    // 0x800A6ABC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6AC0: nop

    // 0x800A6AC4: sw          $v0, 0x144($t1)
    MEM_W(0X144, ctx->r9) = ctx->r2;
    // 0x800A6AC8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800A6ACC:
    // 0x800A6ACC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800A6AD0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6AD4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800A6AD8: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800A6ADC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800A6AE0: lw          $a1, 0x144($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X144);
    // 0x800A6AE4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800A6AE8: jal         0x800BD218
    // 0x800A6AEC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    SysMem_DmaCopy(rdram, ctx);
        goto after_9;
    // 0x800A6AEC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_9:
    // 0x800A6AF0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6AF4: nop

    // 0x800A6AF8: lw          $t0, 0x144($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X144);
    // 0x800A6AFC: nop

    // 0x800A6B00: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x800A6B04: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x800A6B08: nop

    // 0x800A6B0C: bne         $t7, $t8, L_800A6B28
    if (ctx->r15 != ctx->r24) {
        // 0x800A6B10: nop
    
            goto L_800A6B28;
    }
    // 0x800A6B10: nop

    // 0x800A6B14: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800A6B18: bne         $t8, $at, L_800A6B28
    if (ctx->r24 != ctx->r1) {
        // 0x800A6B1C: nop
    
            goto L_800A6B28;
    }
    // 0x800A6B1C: nop

    // 0x800A6B20: b           L_800A6B3C
    // 0x800A6B24: nop

        goto L_800A6B3C;
    // 0x800A6B24: nop

L_800A6B28:
    // 0x800A6B28: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800A6B2C: nop

    // 0x800A6B30: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x800A6B34: b           L_800A6ACC
    // 0x800A6B38: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
        goto L_800A6ACC;
    // 0x800A6B38: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_800A6B3C:
    // 0x800A6B3C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6B40: nop

    // 0x800A6B44: lw          $a0, 0x144($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X144);
    // 0x800A6B48: jal         0x800BC980
    // 0x800A6B4C: nop

    SysMem_Free(rdram, ctx);
        goto after_10;
    // 0x800A6B4C: nop

    after_10:
    // 0x800A6B50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800A6B54: nop

    // 0x800A6B58: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800A6B5C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800A6B60: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x800A6B64: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800A6B68: jal         0x800BC6EC
    // 0x800A6B6C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x800A6B6C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_11:
    // 0x800A6B70: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6B74: nop

    // 0x800A6B78: sw          $v0, 0x144($t6)
    MEM_W(0X144, ctx->r14) = ctx->r2;
    // 0x800A6B7C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800A6B80: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6B84: sll         $t0, $a2, 3
    ctx->r8 = S32(ctx->r6 << 3);
    // 0x800A6B88: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800A6B8C: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800A6B90: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800A6B94: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A6B98: lw          $a1, 0x144($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X144);
    // 0x800A6B9C: jal         0x800BD218
    // 0x800A6BA0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_12;
    // 0x800A6BA0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_12:
    // 0x800A6BA4: b           L_800A6BB8
    // 0x800A6BA8: nop

        goto L_800A6BB8;
    // 0x800A6BA8: nop

L_800A6BAC:
    // 0x800A6BAC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6BB0: nop

    // 0x800A6BB4: sw          $zero, 0x144($t8)
    MEM_W(0X144, ctx->r24) = 0;
L_800A6BB8:
    // 0x800A6BB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A6BBC: jal         0x800BED70
    // 0x800A6BC0: nop

    Spi_GetHeader(rdram, ctx);
        goto after_13;
    // 0x800A6BC0: nop

    after_13:
    // 0x800A6BC4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800A6BC8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A6BCC: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x800A6BD0: jal         0x800BC6EC
    // 0x800A6BD4: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_14;
    // 0x800A6BD4: nop

    after_14:
    // 0x800A6BD8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6BDC: nop

    // 0x800A6BE0: sw          $v0, 0x128($t1)
    MEM_W(0X128, ctx->r9) = ctx->r2;
    // 0x800A6BE4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6BE8: nop

    // 0x800A6BEC: lw          $t2, 0x128($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X128);
    // 0x800A6BF0: nop

    // 0x800A6BF4: sw          $t2, 0x12C($t9)
    MEM_W(0X12C, ctx->r25) = ctx->r10;
    // 0x800A6BF8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6BFC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A6C00: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800A6C04: lw          $a2, 0x128($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X128);
    // 0x800A6C08: jal         0x800BF0B4
    // 0x800A6C0C: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_15;
    // 0x800A6C0C: nop

    after_15:
    // 0x800A6C10: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800A6C14: nop

    // 0x800A6C18: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800A6C1C: nop

    // 0x800A6C20: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x800A6C24: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800A6C28: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x800A6C2C: jal         0x800BC6EC
    // 0x800A6C30: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_16;
    // 0x800A6C30: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_16:
    // 0x800A6C34: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C38: nop

    // 0x800A6C3C: sw          $v0, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r2;
    // 0x800A6C40: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800A6C44: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C48: lw          $a2, 0xC($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XC);
    // 0x800A6C4C: lw          $a1, 0x128($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X128);
    // 0x800A6C50: sll         $t1, $a2, 8
    ctx->r9 = S32(ctx->r6 << 8);
    // 0x800A6C54: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800A6C58: jal         0x800AC7F8
    // 0x800A6C5C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800AC7F8(rdram, ctx);
        goto after_17;
    // 0x800A6C5C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_17:
    // 0x800A6C60: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800A6C64: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C68: lw          $t9, 0xC($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XC);
    // 0x800A6C6C: nop

    // 0x800A6C70: sh          $t9, 0x122($t3)
    MEM_H(0X122, ctx->r11) = ctx->r25;
    // 0x800A6C74: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800A6C78: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C7C: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x800A6C80: lw          $t6, 0x128($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X128);
    // 0x800A6C84: sll         $t7, $t0, 8
    ctx->r15 = S32(ctx->r8 << 8);
    // 0x800A6C88: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800A6C8C: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x800A6C90: sw          $t1, 0x128($t4)
    MEM_W(0X128, ctx->r12) = ctx->r9;
    // 0x800A6C94: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A6C98: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C9C: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x800A6CA0: lw          $t7, 0x128($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X128);
    // 0x800A6CA4: sll         $t3, $t9, 6
    ctx->r11 = S32(ctx->r25 << 6);
    // 0x800A6CA8: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x800A6CAC: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x800A6CB0: sw          $t6, 0x140($t0)
    MEM_W(0X140, ctx->r8) = ctx->r14;
    // 0x800A6CB4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800A6CB8: nop

    // 0x800A6CBC: addiu       $t1, $t8, 0xA
    ctx->r9 = ADD32(ctx->r24, 0XA);
    // 0x800A6CC0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800A6CC4: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6CC8: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x800A6CCC: lw          $t2, 0xC0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC0);
    // 0x800A6CD0: nop

    // 0x800A6CD4: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800A6CD8: sw          $t9, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r25;
    // 0x800A6CDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A6CE0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6CE4: b           L_800A6D94
    // 0x800A6CE8: sw          $t3, 0x130($t5)
    MEM_W(0X130, ctx->r13) = ctx->r11;
        goto L_800A6D94;
    // 0x800A6CE8: sw          $t3, 0x130($t5)
    MEM_W(0X130, ctx->r13) = ctx->r11;
L_800A6CEC:
    // 0x800A6CEC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A6CF0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6CF4: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800A6CF8: nop

    // 0x800A6CFC: sh          $t6, 0x10C($t0)
    MEM_H(0X10C, ctx->r8) = ctx->r14;
    // 0x800A6D00: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800A6D04: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D08: lhu         $t1, 0x2($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X2);
    // 0x800A6D0C: nop

    // 0x800A6D10: sh          $t1, 0x10E($t2)
    MEM_H(0X10E, ctx->r10) = ctx->r9;
    // 0x800A6D14: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D18: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D1C: lw          $t4, 0x110($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X110);
    // 0x800A6D20: nop

    // 0x800A6D24: sw          $t4, 0x110($t3)
    MEM_W(0X110, ctx->r11) = ctx->r12;
    // 0x800A6D28: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D2C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D30: lw          $t7, 0x128($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X128);
    // 0x800A6D34: nop

    // 0x800A6D38: sw          $t7, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->r15;
    // 0x800A6D3C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D40: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D44: lw          $t8, 0x138($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X138);
    // 0x800A6D48: nop

    // 0x800A6D4C: sw          $t8, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->r24;
    // 0x800A6D50: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D54: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D58: lh          $t9, 0x122($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X122);
    // 0x800A6D5C: nop

    // 0x800A6D60: sh          $t9, 0x122($t4)
    MEM_H(0X122, ctx->r12) = ctx->r25;
    // 0x800A6D64: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D68: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D6C: lw          $t5, 0x140($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X140);
    // 0x800A6D70: nop

    // 0x800A6D74: sw          $t5, 0x140($t7)
    MEM_W(0X140, ctx->r15) = ctx->r13;
    // 0x800A6D78: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D7C: nop

    // 0x800A6D80: sw          $zero, 0x144($t6)
    MEM_W(0X144, ctx->r14) = 0;
    // 0x800A6D84: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A6D88: nop

    // 0x800A6D8C: addiu       $t8, $t0, 0x4
    ctx->r24 = ADD32(ctx->r8, 0X4);
    // 0x800A6D90: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800A6D94:
    // 0x800A6D94: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A6D98: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D9C: nop

    // 0x800A6DA0: sw          $t1, 0x13C($t2)
    MEM_W(0X13C, ctx->r10) = ctx->r9;
    // 0x800A6DA4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A6DA8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DAC: nop

    // 0x800A6DB0: sh          $t9, 0x116($t4)
    MEM_H(0X116, ctx->r12) = ctx->r25;
    // 0x800A6DB4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DB8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A6DBC: sh          $t3, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r11;
    // 0x800A6DC0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DC4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800A6DC8: lw          $t6, 0xC0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC0);
    // 0x800A6DCC: nop

    // 0x800A6DD0: or          $t8, $t6, $t0
    ctx->r24 = ctx->r14 | ctx->r8;
    // 0x800A6DD4: sw          $t8, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r24;
    // 0x800A6DD8: lhu         $t1, 0x6E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X6E);
    // 0x800A6DDC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DE0: nop

    // 0x800A6DE4: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
    // 0x800A6DE8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800A6DEC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DF0: nop

    // 0x800A6DF4: sw          $t9, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r25;
    // 0x800A6DF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A6DFC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E00: nop

    // 0x800A6E04: swc1        $f4, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f4.u32l;
    // 0x800A6E08: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E0C: nop

    // 0x800A6E10: lwc1        $f20, 0xD4($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0XD4);
    // 0x800A6E14: nop

    // 0x800A6E18: swc1        $f20, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f20.u32l;
    // 0x800A6E1C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E20: nop

    // 0x800A6E24: swc1        $f20, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f20.u32l;
    // 0x800A6E28: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E2C: nop

    // 0x800A6E30: sw          $zero, 0xE0($t0)
    MEM_W(0XE0, ctx->r8) = 0;
    // 0x800A6E34: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E38: nop

    // 0x800A6E3C: lw          $t7, 0xE0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XE0);
    // 0x800A6E40: nop

    // 0x800A6E44: sw          $t7, 0xDC($t8)
    MEM_W(0XDC, ctx->r24) = ctx->r15;
    // 0x800A6E48: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800A6E4C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E50: nop

    // 0x800A6E54: swc1        $f6, 0xE4($t1)
    MEM_W(0XE4, ctx->r9) = ctx->f6.u32l;
    // 0x800A6E58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A6E5C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E60: nop

    // 0x800A6E64: swc1        $f8, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f8.u32l;
    // 0x800A6E68: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E6C: nop

    // 0x800A6E70: lwc1        $f20, 0xF0($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x800A6E74: nop

    // 0x800A6E78: swc1        $f20, 0xEC($t9)
    MEM_W(0XEC, ctx->r25) = ctx->f20.u32l;
    // 0x800A6E7C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E80: nop

    // 0x800A6E84: swc1        $f20, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f20.u32l;
    // 0x800A6E88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A6E8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A6E90: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E94: nop

    // 0x800A6E98: swc1        $f10, 0xF8($t3)
    MEM_W(0XF8, ctx->r11) = ctx->f10.u32l;
    // 0x800A6E9C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6EA0: nop

    // 0x800A6EA4: lwc1        $f16, 0xF8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x800A6EA8: nop

    // 0x800A6EAC: swc1        $f16, 0xF4($t5)
    MEM_W(0XF4, ctx->r13) = ctx->f16.u32l;
    // 0x800A6EB0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6EB4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A6EB8: lh          $t0, 0x10C($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X10C);
    // 0x800A6EBC: lh          $t7, 0x10E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10E);
    // 0x800A6EC0: nop

    // 0x800A6EC4: multu       $t0, $t7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6EC8: mflo        $t8
    ctx->r24 = lo;
    // 0x800A6ECC: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x800A6ED0: addu        $t9, $t2, $t1
    ctx->r25 = ADD32(ctx->r10, ctx->r9);
    // 0x800A6ED4: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A6ED8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800A6EDC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800A6EE0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6EE4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800A6EE8: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A6EEC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800A6EF0: bne         $at, $zero, L_800A67D8
    if (ctx->r1 != 0) {
        // 0x800A6EF4: sw          $t5, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r13;
            goto L_800A67D8;
    }
    // 0x800A6EF4: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
L_800A6EF8:
    // 0x800A6EF8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800A6EFC: b           L_800A6F0C
    // 0x800A6F00: nop

        goto L_800A6F0C;
    // 0x800A6F00: nop

    // 0x800A6F04: b           L_800A6F0C
    // 0x800A6F08: nop

        goto L_800A6F0C;
    // 0x800A6F08: nop

L_800A6F0C:
    // 0x800A6F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6F10: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800A6F14: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A6F18: jr          $ra
    // 0x800A6F1C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A6F1C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void alSynSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D422C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D4230: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D4234: beql        $t6, $zero, L_800D4298
    if (ctx->r14 == 0) {
        // 0x800D4238: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D4298;
    }
    goto skip_0;
    // 0x800D4238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D423C: jal         0x800C7C00
    // 0x800D4240: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800D4240: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D4244: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4248: beq         $v0, $zero, L_800D4294
    if (ctx->r2 == 0) {
        // 0x800D424C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D4294;
    }
    // 0x800D424C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D4250: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D4254: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D4258: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800D425C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D4260: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D4264: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D4268: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D426C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D4270: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D4274: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x800D4278: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D427C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D4280: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800D4284: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800D4288: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D428C: jalr        $t9
    // 0x800D4290: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D4290: nop

    after_1:
L_800D4294:
    // 0x800D4294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4298:
    // 0x800D4298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D429C: jr          $ra
    // 0x800D42A0: nop

    return;
    // 0x800D42A0: nop

;}
RECOMP_FUNC void func_800392F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800392F8: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x800392FC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80039300: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80039304: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80039308: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8003930C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80039310: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80039314: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80039318: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8003931C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80039320: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80039324: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80039328: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8003932C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80039330: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039334: addiu       $t6, $sp, 0xC8
    ctx->r14 = ADD32(ctx->r29, 0XC8);
    // 0x80039338: addiu       $t7, $sp, 0xC8
    ctx->r15 = ADD32(ctx->r29, 0XC8);
    // 0x8003933C: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x80039340: lwc1        $f6, 0x14($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X14);
    // 0x80039344: nop

    // 0x80039348: swc1        $f6, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f6.u32l;
    // 0x8003934C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039350: addiu       $t8, $sp, 0xC8
    ctx->r24 = ADD32(ctx->r29, 0XC8);
    // 0x80039354: addiu       $t9, $sp, 0xC8
    ctx->r25 = ADD32(ctx->r29, 0XC8);
    // 0x80039358: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x8003935C: lwc1        $f28, 0x8($t9)
    ctx->f28.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80039360: addiu       $t0, $sp, 0xC8
    ctx->r8 = ADD32(ctx->r29, 0XC8);
    // 0x80039364: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x80039368: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x8003936C: swc1        $f28, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f28.u32l;
    // 0x80039370: swc1        $f26, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f26.u32l;
    // 0x80039374: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80039378: addiu       $t1, $sp, 0xC8
    ctx->r9 = ADD32(ctx->r29, 0XC8);
    // 0x8003937C: swc1        $f24, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f24.u32l;
    // 0x80039380: addiu       $t2, $sp, 0xC8
    ctx->r10 = ADD32(ctx->r29, 0XC8);
    // 0x80039384: swc1        $f22, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f22.u32l;
    // 0x80039388: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8003938C: addiu       $t3, $sp, 0xC8
    ctx->r11 = ADD32(ctx->r29, 0XC8);
    // 0x80039390: swc1        $f20, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f20.u32l;
    // 0x80039394: addiu       $t4, $sp, 0xC8
    ctx->r12 = ADD32(ctx->r29, 0XC8);
    // 0x80039398: swc1        $f20, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f20.u32l;
    // 0x8003939C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800393A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800393A4: addiu       $t5, $sp, 0xC8
    ctx->r13 = ADD32(ctx->r29, 0XC8);
    // 0x800393A8: addiu       $t6, $sp, 0xC8
    ctx->r14 = ADD32(ctx->r29, 0XC8);
    // 0x800393AC: swc1        $f10, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f10.u32l;
    // 0x800393B0: lwc1        $f20, 0x20($t6)
    ctx->f20.u32l = MEM_W(ctx->r14, 0X20);
    // 0x800393B4: addiu       $t7, $sp, 0xC8
    ctx->r15 = ADD32(ctx->r29, 0XC8);
    // 0x800393B8: swc1        $f20, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f20.u32l;
    // 0x800393BC: swc1        $f20, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f20.u32l;
    // 0x800393C0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800393C4: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800393C8: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x800393CC: jal         0x800B1250
    // 0x800393D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_0;
    // 0x800393D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800393D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800393D8: lw          $t8, 0x1B44($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B44);
    // 0x800393DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800393E0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800393E4: sw          $t9, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r25;
    // 0x800393E8: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x800393EC: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800393F0: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x800393F4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800393F8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800393FC: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x80039400: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80039404: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80039408: addiu       $t2, $t2, -0x47F8
    ctx->r10 = ADD32(ctx->r10, -0X47F8);
    // 0x8003940C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80039410: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80039414: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80039418: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x8003941C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039420: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80039424: sw          $t6, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r14;
    // 0x80039428: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8003942C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80039430: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80039434: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x80039438: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8003943C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80039440: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80039444: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x80039448: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8003944C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80039450: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x80039454: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039458: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8003945C: sw          $t2, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r10;
    // 0x80039460: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x80039464: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80039468: lui         $t3, 0x386
    ctx->r11 = S32(0X386 << 16);
    // 0x8003946C: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x80039470: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80039474: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80039478: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8003947C: addiu       $t5, $t5, -0x3FF8
    ctx->r13 = ADD32(ctx->r13, -0X3FF8);
    // 0x80039480: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80039484: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80039488: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003948C: lw          $t8, 0x1B44($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B44);
    // 0x80039490: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039494: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80039498: sw          $t9, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r25;
    // 0x8003949C: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x800394A0: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800394A4: lui         $t0, 0x388
    ctx->r8 = S32(0X388 << 16);
    // 0x800394A8: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800394AC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800394B0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800394B4: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x800394B8: addiu       $t2, $t2, -0x3FF8
    ctx->r10 = ADD32(ctx->r10, -0X3FF8);
    // 0x800394BC: addiu       $t3, $t2, 0x18
    ctx->r11 = ADD32(ctx->r10, 0X18);
    // 0x800394C0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800394C4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800394C8: lw          $t5, 0x1B44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B44);
    // 0x800394CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800394D0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800394D4: sw          $t6, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r14;
    // 0x800394D8: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800394DC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800394E0: lui         $t7, 0x38A
    ctx->r15 = S32(0X38A << 16);
    // 0x800394E4: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800394E8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800394EC: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800394F0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800394F4: addiu       $t9, $t9, -0x3FF8
    ctx->r25 = ADD32(ctx->r25, -0X3FF8);
    // 0x800394F8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800394FC: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80039500: lhu         $s0, -0x73C8($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X73C8);
    // 0x80039504: nop

    // 0x80039508: beq         $s0, $zero, L_8003953C
    if (ctx->r16 == 0) {
        // 0x8003950C: nop
    
            goto L_8003953C;
    }
    // 0x8003950C: nop

    // 0x80039510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80039514: beq         $s0, $at, L_800395F8
    if (ctx->r16 == ctx->r1) {
        // 0x80039518: nop
    
            goto L_800395F8;
    }
    // 0x80039518: nop

    // 0x8003951C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80039520: beq         $s0, $at, L_8003968C
    if (ctx->r16 == ctx->r1) {
        // 0x80039524: nop
    
            goto L_8003968C;
    }
    // 0x80039524: nop

    // 0x80039528: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003952C: beq         $s0, $at, L_80039720
    if (ctx->r16 == ctx->r1) {
        // 0x80039530: nop
    
            goto L_80039720;
    }
    // 0x80039530: nop

    // 0x80039534: b           L_800399FC
    // 0x80039538: nop

        goto L_800399FC;
    // 0x80039538: nop

L_8003953C:
    // 0x8003953C: jal         0x800C1850
    // 0x80039540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_1;
    // 0x80039540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80039544: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039548: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003954C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039550: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80039554: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x80039558: lwc1        $f14, -0x73E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x8003955C: jal         0x800C2304
    // 0x80039560: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_2;
    // 0x80039560: nop

    after_2:
    // 0x80039564: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80039568: lw          $t1, 0x258C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X258C);
    // 0x8003956C: nop

    // 0x80039570: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80039574: bgez        $t1, L_8003958C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80039578: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8003958C;
    }
    // 0x80039578: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003957C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80039580: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039584: nop

    // 0x80039588: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8003958C:
    // 0x8003958C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039590: lwc1        $f6, 0x72E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X72E8);
    // 0x80039594: jal         0x800C23E8
    // 0x80039598: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_3;
    // 0x80039598: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_3:
    // 0x8003959C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800395A0: lwc1        $f12, 0x7324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x800395A4: jal         0x800C25B8
    // 0x800395A8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_4;
    // 0x800395A8: nop

    after_4:
    // 0x800395AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800395B0: lwc1        $f12, 0x733C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X733C);
    // 0x800395B4: jal         0x800C2780
    // 0x800395B8: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_5;
    // 0x800395B8: nop

    after_5:
    // 0x800395BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800395C0: lwc1        $f8, -0x76B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800395C4: nop

    // 0x800395C8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800395CC: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    // 0x800395D0: jal         0x800C2948
    // 0x800395D4: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_6;
    // 0x800395D4: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
    after_6:
    // 0x800395D8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800395DC: lw          $a1, -0x3A44($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A44);
    // 0x800395E0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800395E4: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800395E8: jal         0x800B18C4
    // 0x800395EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_7;
    // 0x800395EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800395F0: b           L_800399FC
    // 0x800395F4: nop

        goto L_800399FC;
    // 0x800395F4: nop

L_800395F8:
    // 0x800395F8: jal         0x800C1850
    // 0x800395FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_8;
    // 0x800395FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80039600: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039604: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80039608: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003960C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80039610: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x80039614: lwc1        $f14, -0x73E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x80039618: jal         0x800C2304
    // 0x8003961C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_9;
    // 0x8003961C: nop

    after_9:
    // 0x80039620: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039624: lwc1        $f12, 0x72E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X72E8);
    // 0x80039628: jal         0x800C23E8
    // 0x8003962C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_10;
    // 0x8003962C: nop

    after_10:
    // 0x80039630: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039634: lwc1        $f12, 0x7324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80039638: jal         0x800C25B8
    // 0x8003963C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_11;
    // 0x8003963C: nop

    after_11:
    // 0x80039640: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039644: lwc1        $f12, 0x733C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X733C);
    // 0x80039648: jal         0x800C2780
    // 0x8003964C: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_12;
    // 0x8003964C: nop

    after_12:
    // 0x80039650: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039654: lwc1        $f10, -0x76B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80039658: nop

    // 0x8003965C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80039660: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x80039664: jal         0x800C2948
    // 0x80039668: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_13;
    // 0x80039668: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    after_13:
    // 0x8003966C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80039670: lw          $a1, -0x3A48($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A48);
    // 0x80039674: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039678: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8003967C: jal         0x800B18C4
    // 0x80039680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_14;
    // 0x80039680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80039684: b           L_800399FC
    // 0x80039688: nop

        goto L_800399FC;
    // 0x80039688: nop

L_8003968C:
    // 0x8003968C: jal         0x800C1850
    // 0x80039690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_15;
    // 0x80039690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80039694: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039698: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8003969C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800396A0: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800396A4: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x800396A8: lwc1        $f14, -0x73E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x800396AC: jal         0x800C2304
    // 0x800396B0: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_16;
    // 0x800396B0: nop

    after_16:
    // 0x800396B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800396B8: lwc1        $f12, 0x72E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X72E8);
    // 0x800396BC: jal         0x800C23E8
    // 0x800396C0: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_17;
    // 0x800396C0: nop

    after_17:
    // 0x800396C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800396C8: lwc1        $f12, 0x7324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x800396CC: jal         0x800C25B8
    // 0x800396D0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_18;
    // 0x800396D0: nop

    after_18:
    // 0x800396D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800396D8: lwc1        $f12, 0x733C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X733C);
    // 0x800396DC: jal         0x800C2780
    // 0x800396E0: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_19;
    // 0x800396E0: nop

    after_19:
    // 0x800396E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800396E8: lwc1        $f16, -0x76B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800396EC: nop

    // 0x800396F0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800396F4: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x800396F8: jal         0x800C2948
    // 0x800396FC: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_20;
    // 0x800396FC: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    after_20:
    // 0x80039700: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80039704: lw          $a1, -0x3A4C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A4C);
    // 0x80039708: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8003970C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80039710: jal         0x800B18C4
    // 0x80039714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_21;
    // 0x80039714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x80039718: b           L_800399FC
    // 0x8003971C: nop

        goto L_800399FC;
    // 0x8003971C: nop

L_80039720:
    // 0x80039720: jal         0x800C1850
    // 0x80039724: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_22;
    // 0x80039724: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x80039728: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003972C: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80039730: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039734: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80039738: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x8003973C: lwc1        $f14, -0x73E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x80039740: jal         0x800C2304
    // 0x80039744: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_23;
    // 0x80039744: nop

    after_23:
    // 0x80039748: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003974C: lwc1        $f12, 0x72E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X72E8);
    // 0x80039750: jal         0x800C23E8
    // 0x80039754: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_24;
    // 0x80039754: nop

    after_24:
    // 0x80039758: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003975C: lwc1        $f12, 0x7324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80039760: jal         0x800C25B8
    // 0x80039764: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_25;
    // 0x80039764: nop

    after_25:
    // 0x80039768: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003976C: lwc1        $f12, 0x733C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X733C);
    // 0x80039770: jal         0x800C2780
    // 0x80039774: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_26;
    // 0x80039774: nop

    after_26:
    // 0x80039778: jal         0x800C1A84
    // 0x8003977C: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_27;
    // 0x8003977C: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_27:
    // 0x80039780: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039784: lwc1        $f4, -0x76B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80039788: nop

    // 0x8003978C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80039790: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x80039794: jal         0x800C2948
    // 0x80039798: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_28;
    // 0x80039798: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_28:
    // 0x8003979C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800397A0: lw          $a1, -0x3A60($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A60);
    // 0x800397A4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800397A8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800397AC: jal         0x800B18C4
    // 0x800397B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_29;
    // 0x800397B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_29:
    // 0x800397B4: jal         0x800C1AF4
    // 0x800397B8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_30;
    // 0x800397B8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_30:
    // 0x800397BC: lui         $at, 0x42F6
    ctx->r1 = S32(0X42F6 << 16);
    // 0x800397C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800397C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800397C8: lwc1        $f6, -0x76B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800397CC: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x800397D0: mul.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800397D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800397D8: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x800397DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800397E0: mul.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800397E4: nop

    // 0x800397E8: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800397EC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800397F0: jal         0x800C2304
    // 0x800397F4: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_31;
    // 0x800397F4: nop

    after_31:
    // 0x800397F8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800397FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80039800: jal         0x800C25B8
    // 0x80039804: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_32;
    // 0x80039804: nop

    after_32:
    // 0x80039808: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003980C: lwc1        $f12, -0x3FFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3FFC);
    // 0x80039810: jal         0x800C23E8
    // 0x80039814: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_33;
    // 0x80039814: nop

    after_33:
    // 0x80039818: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003981C: lwc1        $f4, -0x76B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80039820: nop

    // 0x80039824: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80039828: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x8003982C: jal         0x800C2948
    // 0x80039830: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_34;
    // 0x80039830: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_34:
    // 0x80039834: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80039838: lw          $a1, -0x3A5C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A5C);
    // 0x8003983C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039840: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80039844: jal         0x800B18C4
    // 0x80039848: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_35;
    // 0x80039848: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x8003984C: jal         0x800C1AF4
    // 0x80039850: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_36;
    // 0x80039850: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_36:
    // 0x80039854: lui         $at, 0xC2F6
    ctx->r1 = S32(0XC2F6 << 16);
    // 0x80039858: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003985C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039860: lwc1        $f8, -0x76B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80039864: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80039868: mul.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8003986C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80039870: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x80039874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80039878: mul.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003987C: nop

    // 0x80039880: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80039884: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80039888: jal         0x800C2304
    // 0x8003988C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_37;
    // 0x8003988C: nop

    after_37:
    // 0x80039890: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80039894: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80039898: jal         0x800C25B8
    // 0x8003989C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_38;
    // 0x8003989C: nop

    after_38:
    // 0x800398A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800398A4: lwc1        $f12, -0x3FFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3FFC);
    // 0x800398A8: jal         0x800C23E8
    // 0x800398AC: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_39;
    // 0x800398AC: nop

    after_39:
    // 0x800398B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800398B4: lwc1        $f4, -0x76B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800398B8: nop

    // 0x800398BC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800398C0: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x800398C4: jal         0x800C2948
    // 0x800398C8: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_40;
    // 0x800398C8: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_40:
    // 0x800398CC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800398D0: lw          $a1, -0x3A58($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A58);
    // 0x800398D4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800398D8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800398DC: jal         0x800B18C4
    // 0x800398E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_41;
    // 0x800398E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_41:
    // 0x800398E4: jal         0x800C1AF4
    // 0x800398E8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_42;
    // 0x800398E8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_42:
    // 0x800398EC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800398F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800398F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800398F8: lwc1        $f10, -0x76B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800398FC: lui         $at, 0xC198
    ctx->r1 = S32(0XC198 << 16);
    // 0x80039900: mul.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80039904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80039908: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x8003990C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80039910: mul.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80039914: nop

    // 0x80039918: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003991C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80039920: jal         0x800C2304
    // 0x80039924: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_43;
    // 0x80039924: nop

    after_43:
    // 0x80039928: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003992C: lwc1        $f12, -0x4000($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4000);
    // 0x80039930: jal         0x800C25B8
    // 0x80039934: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_44;
    // 0x80039934: nop

    after_44:
    // 0x80039938: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8003993C: lwc1        $f4, -0x76B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80039940: nop

    // 0x80039944: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80039948: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x8003994C: jal         0x800C2948
    // 0x80039950: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_45;
    // 0x80039950: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_45:
    // 0x80039954: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80039958: lw          $a1, -0x3A54($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A54);
    // 0x8003995C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80039960: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80039964: jal         0x800B18C4
    // 0x80039968: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_46;
    // 0x80039968: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_46:
    // 0x8003996C: jal         0x800C1AF4
    // 0x80039970: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_47;
    // 0x80039970: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_47:
    // 0x80039974: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80039978: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003997C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039980: lwc1        $f6, -0x76B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80039984: lui         $at, 0xC198
    ctx->r1 = S32(0XC198 << 16);
    // 0x80039988: mul.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8003998C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80039990: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x80039994: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80039998: mul.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8003999C: nop

    // 0x800399A0: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800399A4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800399A8: jal         0x800C2304
    // 0x800399AC: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_48;
    // 0x800399AC: nop

    after_48:
    // 0x800399B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800399B4: lwc1        $f12, -0x4000($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4000);
    // 0x800399B8: jal         0x800C25B8
    // 0x800399BC: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_49;
    // 0x800399BC: nop

    after_49:
    // 0x800399C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800399C4: lwc1        $f4, -0x76B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800399C8: nop

    // 0x800399CC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800399D0: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x800399D4: jal         0x800C2948
    // 0x800399D8: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_50;
    // 0x800399D8: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    after_50:
    // 0x800399DC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800399E0: lw          $a1, -0x3A50($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A50);
    // 0x800399E4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800399E8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x800399EC: jal         0x800B18C4
    // 0x800399F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B18C4(rdram, ctx);
        goto after_51;
    // 0x800399F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_51:
    // 0x800399F4: b           L_800399FC
    // 0x800399F8: nop

        goto L_800399FC;
    // 0x800399F8: nop

L_800399FC:
    // 0x800399FC: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80039A00: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80039A04: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80039A08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80039A0C: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80039A10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039A14: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80039A18: swc1        $f10, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f10.u32l;
    // 0x80039A1C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80039A20: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80039A24: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80039A28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039A2C: lwc1        $f6, 0x14($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80039A30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039A34: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80039A38: swc1        $f4, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = ctx->f4.u32l;
    // 0x80039A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039A40: lwc1        $f18, -0x4000($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4000);
    // 0x80039A44: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80039A48: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80039A4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039A50: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80039A54: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x80039A58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039A5C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80039A60: swc1        $f16, -0x4000($at)
    MEM_W(-0X4000, ctx->r1) = ctx->f16.u32l;
    // 0x80039A64: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80039A68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039A6C: nop

    // 0x80039A70: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80039A74: nop

    // 0x80039A78: bc1f        L_80039AA8
    if (!c1cs) {
        // 0x80039A7C: nop
    
            goto L_80039AA8;
    }
    // 0x80039A7C: nop

    // 0x80039A80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039A84: lwc1        $f18, -0x4000($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4000);
    // 0x80039A88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80039A8C: lwc1        $f11, -0x1510($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1510);
    // 0x80039A90: lwc1        $f10, -0x150C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X150C);
    // 0x80039A94: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80039A98: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x80039A9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039AA0: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80039AA4: swc1        $f16, -0x4000($at)
    MEM_W(-0X4000, ctx->r1) = ctx->f16.u32l;
L_80039AA8:
    // 0x80039AA8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80039AAC: lw          $t4, 0x258C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X258C);
    // 0x80039AB0: nop

    // 0x80039AB4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80039AB8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80039ABC: bgez        $t5, L_80039AD8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80039AC0: cvt.d.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
            goto L_80039AD8;
    }
    // 0x80039AC0: cvt.d.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
    // 0x80039AC4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80039AC8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80039ACC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039AD0: nop

    // 0x80039AD4: add.d       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f18.d + ctx->f8.d;
L_80039AD8:
    // 0x80039AD8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80039ADC: lwc1        $f11, -0x1508($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1508);
    // 0x80039AE0: lwc1        $f10, -0x1504($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1504);
    // 0x80039AE4: nop

    // 0x80039AE8: mul.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80039AEC: jal         0x800C3070
    // 0x80039AF0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_52;
    // 0x80039AF0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_52:
    // 0x80039AF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80039AF8: lwc1        $f5, -0x1500($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1500);
    // 0x80039AFC: lwc1        $f4, -0x14FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14FC);
    // 0x80039B00: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80039B04: mul.d       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80039B08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039B0C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80039B10: swc1        $f18, -0x3FFC($at)
    MEM_W(-0X3FFC, ctx->r1) = ctx->f18.u32l;
    // 0x80039B14: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80039B18: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x80039B1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80039B20: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80039B24: sw          $t7, 0x1B44($at)
    MEM_W(0X1B44, ctx->r1) = ctx->r15;
    // 0x80039B28: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80039B2C: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80039B30: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x80039B34: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80039B38: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80039B3C: lui         $t0, 0x1F
    ctx->r8 = S32(0X1F << 16);
    // 0x80039B40: ori         $t0, $t0, 0x3204
    ctx->r8 = ctx->r8 | 0X3204;
    // 0x80039B44: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80039B48: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80039B4C: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80039B50: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80039B54: lhu         $t4, 0xE68($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XE68);
    // 0x80039B58: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x80039B5C: nop

    // 0x80039B60: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80039B64: beq         $t5, $zero, L_80039B94
    if (ctx->r13 == 0) {
        // 0x80039B68: nop
    
            goto L_80039B94;
    }
    // 0x80039B68: nop

    // 0x80039B6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039B70: lwc1        $f10, -0x76B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80039B74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80039B78: lwc1        $f17, -0x14F8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X14F8);
    // 0x80039B7C: lwc1        $f16, -0x14F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X14F4);
    // 0x80039B80: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80039B84: add.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f6.d + ctx->f16.d;
    // 0x80039B88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039B8C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80039B90: swc1        $f8, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f8.u32l;
L_80039B94:
    // 0x80039B94: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80039B98: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80039B9C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80039BA0: lhu         $t8, 0xE74($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XE74);
    // 0x80039BA4: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x80039BA8: nop

    // 0x80039BAC: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80039BB0: beq         $t9, $zero, L_80039BE0
    if (ctx->r25 == 0) {
        // 0x80039BB4: nop
    
            goto L_80039BE0;
    }
    // 0x80039BB4: nop

    // 0x80039BB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039BBC: lwc1        $f18, -0x76B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x80039BC0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80039BC4: lwc1        $f7, -0x14F0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X14F0);
    // 0x80039BC8: lwc1        $f6, -0x14EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X14EC);
    // 0x80039BCC: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80039BD0: sub.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f10.d - ctx->f6.d;
    // 0x80039BD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039BD8: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80039BDC: swc1        $f4, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f4.u32l;
L_80039BE0:
    // 0x80039BE0: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80039BE4: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80039BE8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80039BEC: lhu         $t2, 0x1038($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1038);
    // 0x80039BF0: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x80039BF4: nop

    // 0x80039BF8: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80039BFC: beq         $t3, $zero, L_80039C1C
    if (ctx->r11 == 0) {
        // 0x80039C00: nop
    
            goto L_80039C1C;
    }
    // 0x80039C00: nop

    // 0x80039C04: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80039C08: lhu         $t4, -0x73C8($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X73C8);
    // 0x80039C0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80039C10: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80039C14: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x80039C18: sh          $t6, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r14;
L_80039C1C:
    // 0x80039C1C: b           L_80039C24
    // 0x80039C20: nop

        goto L_80039C24;
    // 0x80039C20: nop

L_80039C24:
    // 0x80039C24: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80039C28: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80039C2C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80039C30: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80039C34: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80039C38: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80039C3C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80039C40: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80039C44: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80039C48: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80039C4C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80039C50: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80039C54: jr          $ra
    // 0x80039C58: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80039C58: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_800716FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800716FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071700: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071704: nop

    // 0x80071708: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8007170C: nop

    // 0x80071710: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071714: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80071718: jr          $ra
    // 0x8007171C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007171C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071720: jr          $ra
    // 0x80071724: nop

    return;
    // 0x80071724: nop

    // 0x80071728: jr          $ra
    // 0x8007172C: nop

    return;
    // 0x8007172C: nop

;}
RECOMP_FUNC void func_8009A3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A3E8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009A3EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009A3F0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8009A3F4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8009A3F8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8009A3FC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009A400: lw          $t6, 0x70E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70E4);
    // 0x8009A404: nop

    // 0x8009A408: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8009A40C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8009A410: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8009A414: nop

    // 0x8009A418: bgez        $t8, L_8009A428
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8009A41C: nop
    
            goto L_8009A428;
    }
    // 0x8009A41C: nop

    // 0x8009A420: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009A424: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8009A428:
    // 0x8009A428: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8009A42C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8009A430: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x8009A434: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8009A438: jal         0x800C2D08
    // 0x8009A43C: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    MtxUtil_MtxToMtxF(rdram, ctx);
        goto after_0;
    // 0x8009A43C: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    after_0:
    // 0x8009A440: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x8009A444: lwc1        $f4, 0x38($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X38);
    // 0x8009A448: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8009A44C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009A450: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8009A454: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8009A458: nop

    // 0x8009A45C: bc1f        L_8009A46C
    if (!c1cs) {
        // 0x8009A460: nop
    
            goto L_8009A46C;
    }
    // 0x8009A460: nop

    // 0x8009A464: b           L_8009A654
    // 0x8009A468: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8009A654;
    // 0x8009A468: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009A46C:
    // 0x8009A46C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8009A470: nop

    // 0x8009A474: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x8009A478: nop

    // 0x8009A47C: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x8009A480: beq         $t6, $zero, L_8009A4EC
    if (ctx->r14 == 0) {
        // 0x8009A484: nop
    
            goto L_8009A4EC;
    }
    // 0x8009A484: nop

    // 0x8009A488: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A48C: addiu       $t7, $sp, 0x20
    ctx->r15 = ADD32(ctx->r29, 0X20);
    // 0x8009A490: lwc1        $f16, 0x38($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X38);
    // 0x8009A494: lwc1        $f10, 0x7218($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009A498: lwc1        $f4, 0x30($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8009A49C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009A4A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A4A4: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x8009A4A8: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8009A4AC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009A4B0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009A4B4: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x8009A4B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A4BC: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x8009A4C0: lwc1        $f18, 0x38($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X38);
    // 0x8009A4C4: lwc1        $f16, 0x7218($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009A4C8: lwc1        $f6, 0x34($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X34);
    // 0x8009A4CC: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009A4D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A4D4: lwc1        $f10, 0x7230($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8009A4D8: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8009A4DC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009A4E0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8009A4E4: b           L_8009A574
    // 0x8009A4E8: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
        goto L_8009A574;
    // 0x8009A4E8: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
L_8009A4EC:
    // 0x8009A4EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A4F0: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x8009A4F4: lwc1        $f4, 0x38($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X38);
    // 0x8009A4F8: lwc1        $f18, 0x7218($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009A4FC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8009A500: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009A504: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8009A508: lw          $t3, 0xDC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XDC);
    // 0x8009A50C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A510: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8009A514: lwc1        $f16, 0x7224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x8009A518: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8009A51C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009A520: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A524: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8009A528: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8009A52C: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8009A530: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A534: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x8009A538: lwc1        $f16, 0x38($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X38);
    // 0x8009A53C: lwc1        $f10, 0x7218($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x8009A540: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8009A544: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009A548: lwc1        $f18, 0x34($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X34);
    // 0x8009A54C: lw          $t7, 0xE0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XE0);
    // 0x8009A550: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A554: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8009A558: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8009A55C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8009A560: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8009A564: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009A568: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009A56C: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8009A570: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
L_8009A574:
    // 0x8009A574: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8009A578: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8009A57C: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8009A580: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009A584: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009A588: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009A58C: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8009A590: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009A594: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8009A598: nop

    // 0x8009A59C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8009A5A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009A5A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009A5A8: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8009A5AC: cvt.w.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_D(ctx->f10.d);
    // 0x8009A5B0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009A5B4: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8009A5B8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009A5BC: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8009A5C0: nop

    // 0x8009A5C4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009A5C8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009A5CC: nop

    // 0x8009A5D0: div.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f16.d);
    // 0x8009A5D4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8009A5D8: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x8009A5DC: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8009A5E0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8009A5E4: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8009A5E8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8009A5EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009A5F0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8009A5F4: mul.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8009A5F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009A5FC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8009A600: nop

    // 0x8009A604: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8009A608: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009A60C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009A610: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8009A614: cvt.w.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_D(ctx->f16.d);
    // 0x8009A618: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8009A61C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8009A620: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009A624: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8009A628: nop

    // 0x8009A62C: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A630: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8009A634: nop

    // 0x8009A638: div.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8009A63C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8009A640: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x8009A644: b           L_8009A654
    // 0x8009A648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A654;
    // 0x8009A648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009A64C: b           L_8009A654
    // 0x8009A650: nop

        goto L_8009A654;
    // 0x8009A650: nop

L_8009A654:
    // 0x8009A654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009A658: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8009A65C: jr          $ra
    // 0x8009A660: nop

    return;
    // 0x8009A660: nop

;}
RECOMP_FUNC void func_80032380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032380: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80032384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032388: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8003238C: addiu       $t6, $t6, 0x3E30
    ctx->r14 = ADD32(ctx->r14, 0X3E30);
    // 0x80032390: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80032394: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80032398: lw          $t7, 0x6C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C4);
    // 0x8003239C: nop

    // 0x800323A0: bne         $t7, $zero, L_800323BC
    if (ctx->r15 != 0) {
        // 0x800323A4: nop
    
            goto L_800323BC;
    }
    // 0x800323A4: nop

    // 0x800323A8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800323AC: jal         0x800974C0
    // 0x800323B0: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    func_800974C0(rdram, ctx);
        goto after_0;
    // 0x800323B0: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_0:
    // 0x800323B4: b           L_800323F8
    // 0x800323B8: nop

        goto L_800323F8;
    // 0x800323B8: nop

L_800323BC:
    // 0x800323BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800323C0: lbu         $a0, 0xFF8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XFF8);
    // 0x800323C4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800323C8: jal         0x800C1264
    // 0x800323CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_1;
    // 0x800323CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_800323D0:
    // 0x800323D0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800323D4: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x800323D8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800323DC: jal         0x800C1570
    // 0x800323E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsg(rdram, ctx);
        goto after_2;
    // 0x800323E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800323E4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800323E8: lw          $t8, -0x3788($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3788);
    // 0x800323EC: nop

    // 0x800323F0: bne         $t8, $zero, L_800323D0
    if (ctx->r24 != 0) {
        // 0x800323F4: nop
    
            goto L_800323D0;
    }
    // 0x800323F4: nop

L_800323F8:
    // 0x800323F8: b           L_80032400
    // 0x800323FC: nop

        goto L_80032400;
    // 0x800323FC: nop

L_80032400:
    // 0x80032400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032404: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80032408: jr          $ra
    // 0x8003240C: nop

    return;
    // 0x8003240C: nop

;}
RECOMP_FUNC void func_80065EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065F04: jal         0x80061348
    // 0x80065F08: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065F08: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80065F0C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065F10: b           L_80065F20
    // 0x80065F14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065F20;
    // 0x80065F14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065F18: b           L_80065F20
    // 0x80065F1C: nop

        goto L_80065F20;
    // 0x80065F1C: nop

L_80065F20:
    // 0x80065F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065F28: jr          $ra
    // 0x80065F2C: nop

    return;
    // 0x80065F2C: nop

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
RECOMP_FUNC void __vsPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D25A4: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x800D25A8: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x800D25AC: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x800D25B0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800D25B4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800D25B8: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x800D25BC: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x800D25C0: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x800D25C4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800D25C8: bgtzl       $v1, L_800D25D8
    if (SIGNED(ctx->r3) > 0) {
        // 0x800D25CC: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800D25D8;
    }
    goto skip_0;
    // 0x800D25CC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_0:
    // 0x800D25D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D25D4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800D25D8:
    // 0x800D25D8: bne         $at, $zero, L_800D25E4
    if (ctx->r1 != 0) {
        // 0x800D25DC: nop
    
            goto L_800D25E4;
    }
    // 0x800D25DC: nop

    // 0x800D25E0: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_800D25E4:
    // 0x800D25E4: jr          $ra
    // 0x800D25E8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x800D25E8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void alEvtqFlush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D39BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D39C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D39C4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D39C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D39CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D39D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D39D4: jal         0x800C41A0
    // 0x800D39D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D39D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D39DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D39E0: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800D39E4: beq         $s0, $zero, L_800D3A0C
    if (ctx->r16 == 0) {
        // 0x800D39E8: nop
    
            goto L_800D3A0C;
    }
    // 0x800D39E8: nop

L_800D39EC:
    // 0x800D39EC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D39F0: jal         0x800C7890
    // 0x800D39F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800D39F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D39F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D39FC: jal         0x800C78C0
    // 0x800D3A00: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800D3A00: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800D3A04: bne         $s1, $zero, L_800D39EC
    if (ctx->r17 != 0) {
        // 0x800D3A08: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D39EC;
    }
    // 0x800D3A08: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800D3A0C:
    // 0x800D3A0C: jal         0x800C41A0
    // 0x800D3A10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800D3A10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800D3A14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D3A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3A1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3A20: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D3A24: jr          $ra
    // 0x800D3A28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D3A28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80075408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007540C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075410: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075414: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075418: nop

    // 0x8007541C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80075420: nop

    // 0x80075424: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80075428: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007542C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075430: beq         $v0, $zero, L_80075464
    if (ctx->r2 == 0) {
        // 0x80075434: nop
    
            goto L_80075464;
    }
    // 0x80075434: nop

    // 0x80075438: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x8007543C: nop

    // 0x80075440: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80075444: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80075448: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007544C: beq         $v0, $zero, L_80075464
    if (ctx->r2 == 0) {
        // 0x80075450: nop
    
            goto L_80075464;
    }
    // 0x80075450: nop

    // 0x80075454: jal         0x8005F064
    // 0x80075458: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80075458: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    after_0:
    // 0x8007545C: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80075460: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075464:
    // 0x80075464: b           L_80075474
    // 0x80075468: nop

        goto L_80075474;
    // 0x80075468: nop

    // 0x8007546C: b           L_80075474
    // 0x80075470: nop

        goto L_80075474;
    // 0x80075470: nop

L_80075474:
    // 0x80075474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007547C: jr          $ra
    // 0x80075480: nop

    return;
    // 0x80075480: nop

;}
RECOMP_FUNC void func_8006FE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FE5C: jal         0x80061348
    // 0x8006FE60: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FE60: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    after_0:
    // 0x8006FE64: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006FE68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FE6C: bne         $v0, $zero, L_8006FE88
    if (ctx->r2 != 0) {
        // 0x8006FE70: nop
    
            goto L_8006FE88;
    }
    // 0x8006FE70: nop

    // 0x8006FE74: jal         0x80061348
    // 0x8006FE78: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FE78: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x8006FE7C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FE80: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FE84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006FE88:
    // 0x8006FE88: b           L_8006FE98
    // 0x8006FE8C: nop

        goto L_8006FE98;
    // 0x8006FE8C: nop

    // 0x8006FE90: b           L_8006FE98
    // 0x8006FE94: nop

        goto L_8006FE98;
    // 0x8006FE94: nop

L_8006FE98:
    // 0x8006FE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FE9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FEA0: jr          $ra
    // 0x8006FEA4: nop

    return;
    // 0x8006FEA4: nop

;}
RECOMP_FUNC void func_80062640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062648: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8006264C: sh          $zero, 0xCE0($at)
    MEM_H(0XCE0, ctx->r1) = 0;
    // 0x80062650: jal         0x800BC6EC
    // 0x80062654: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80062654: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x80062658: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8006265C: sw          $v0, 0xCEC($at)
    MEM_W(0XCEC, ctx->r1) = ctx->r2;
    // 0x80062660: b           L_80062668
    // 0x80062664: nop

        goto L_80062668;
    // 0x80062664: nop

L_80062668:
    // 0x80062668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006266C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062670: jr          $ra
    // 0x80062674: nop

    return;
    // 0x80062674: nop

;}
RECOMP_FUNC void func_8006E958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E960: jal         0x80061348
    // 0x8006E964: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E964: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E968: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006E96C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006E970: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E974: beq         $v0, $zero, L_8006E98C
    if (ctx->r2 == 0) {
        // 0x8006E978: nop
    
            goto L_8006E98C;
    }
    // 0x8006E978: nop

    // 0x8006E97C: jal         0x80061348
    // 0x8006E980: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E980: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    after_1:
    // 0x8006E984: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E988: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E98C:
    // 0x8006E98C: b           L_8006E99C
    // 0x8006E990: nop

        goto L_8006E99C;
    // 0x8006E990: nop

    // 0x8006E994: b           L_8006E99C
    // 0x8006E998: nop

        goto L_8006E99C;
    // 0x8006E998: nop

L_8006E99C:
    // 0x8006E99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E9A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E9A4: jr          $ra
    // 0x8006E9A8: nop

    return;
    // 0x8006E9A8: nop

;}
RECOMP_FUNC void MtxUtil_MtxFToMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2D74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C2D78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2D7C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D80: nop

    // 0x800C2D84: bne         $t6, $zero, L_800C2DA8
    if (ctx->r14 != 0) {
        // 0x800C2D88: nop
    
            goto L_800C2DA8;
    }
    // 0x800C2D88: nop

    // 0x800C2D8C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2D90: lw          $a0, 0xCE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE4);
    // 0x800C2D94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D98: jal         0x800C2DD0
    // 0x800C2D9C: nop

    MtxUtil__MtxFToMtx(rdram, ctx);
        goto after_0;
    // 0x800C2D9C: nop

    after_0:
    // 0x800C2DA0: b           L_800C2DB8
    // 0x800C2DA4: nop

        goto L_800C2DB8;
    // 0x800C2DA4: nop

L_800C2DA8:
    // 0x800C2DA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C2DAC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2DB0: jal         0x800C2DD0
    // 0x800C2DB4: nop

    MtxUtil__MtxFToMtx(rdram, ctx);
        goto after_1;
    // 0x800C2DB4: nop

    after_1:
L_800C2DB8:
    // 0x800C2DB8: b           L_800C2DC0
    // 0x800C2DBC: nop

        goto L_800C2DC0;
    // 0x800C2DBC: nop

L_800C2DC0:
    // 0x800C2DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2DC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2DC8: jr          $ra
    // 0x800C2DCC: nop

    return;
    // 0x800C2DCC: nop

;}
RECOMP_FUNC void func_80016430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016430: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80016434: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016438: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001643C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80016440: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016444: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80016448: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001644C: nop

    // 0x80016450: lw          $t7, 0x1A0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A0);
    // 0x80016454: nop

    // 0x80016458: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x8001645C: sw          $t8, 0x1A0($t6)
    MEM_W(0X1A0, ctx->r14) = ctx->r24;
    // 0x80016460: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80016464: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80016468: sw          $t9, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r25;
    // 0x8001646C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80016470: nop

    // 0x80016474: sw          $zero, 0x1AC($t1)
    MEM_W(0X1AC, ctx->r9) = 0;
    // 0x80016478: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001647C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80016480: nop

    // 0x80016484: swc1        $f4, 0x1EC($t2)
    MEM_W(0X1EC, ctx->r10) = ctx->f4.u32l;
    // 0x80016488: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001648C: nop

    // 0x80016490: lwc1        $f6, 0x1EC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1EC);
    // 0x80016494: nop

    // 0x80016498: swc1        $f6, 0x1E8($t3)
    MEM_W(0X1E8, ctx->r11) = ctx->f6.u32l;
    // 0x8001649C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800164A0: nop

    // 0x800164A4: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x800164A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800164AC: jal         0x80099E2C
    // 0x800164B0: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x800164B0: nop

    after_0:
    // 0x800164B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800164B8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800164BC: nop

    // 0x800164C0: swc1        $f8, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f8.u32l;
    // 0x800164C4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800164C8: nop

    // 0x800164CC: lwc1        $f10, 0xD0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x800164D0: nop

    // 0x800164D4: swc1        $f10, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f10.u32l;
    // 0x800164D8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800164DC: lw          $t8, -0x4CCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CCC);
    // 0x800164E0: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x800164E4: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x800164E8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800164EC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800164F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800164F4: swc1        $f18, 0xD4($t0)
    MEM_W(0XD4, ctx->r8) = ctx->f18.u32l;
    // 0x800164F8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800164FC: nop

    // 0x80016500: sw          $zero, 0x108($t1)
    MEM_W(0X108, ctx->r9) = 0;
    // 0x80016504: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80016508: nop

    // 0x8001650C: lw          $t3, 0x108($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X108);
    // 0x80016510: nop

    // 0x80016514: sw          $t3, 0x104($t2)
    MEM_W(0X104, ctx->r10) = ctx->r11;
    // 0x80016518: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001651C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80016520: nop

    // 0x80016524: swc1        $f4, 0xF0($t4)
    MEM_W(0XF0, ctx->r12) = ctx->f4.u32l;
    // 0x80016528: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8001652C: nop

    // 0x80016530: lwc1        $f20, 0xF0($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0XF0);
    // 0x80016534: nop

    // 0x80016538: swc1        $f20, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f20.u32l;
    // 0x8001653C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80016540: nop

    // 0x80016544: swc1        $f20, 0xE8($t7)
    MEM_W(0XE8, ctx->r15) = ctx->f20.u32l;
    // 0x80016548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001654C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016550: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80016554: nop

    // 0x80016558: swc1        $f6, 0xF8($t6)
    MEM_W(0XF8, ctx->r14) = ctx->f6.u32l;
    // 0x8001655C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80016560: nop

    // 0x80016564: lwc1        $f8, 0xF8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x80016568: nop

    // 0x8001656C: swc1        $f8, 0xF4($t8)
    MEM_W(0XF4, ctx->r24) = ctx->f8.u32l;
    // 0x80016570: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80016574: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80016578: sw          $t9, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r25;
    // 0x8001657C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80016580: nop

    // 0x80016584: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x80016588: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8001658C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80016590: sh          $t3, 0x116($t2)
    MEM_H(0X116, ctx->r10) = ctx->r11;
    // 0x80016594: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80016598: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001659C: sh          $t4, 0x114($t5)
    MEM_H(0X114, ctx->r13) = ctx->r12;
    // 0x800165A0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800165A4: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x800165A8: sh          $t7, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r15;
    // 0x800165AC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800165B0: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x800165B4: sh          $t8, 0x102($t9)
    MEM_H(0X102, ctx->r25) = ctx->r24;
    // 0x800165B8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800165BC: nop

    // 0x800165C0: sh          $zero, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = 0;
    // 0x800165C4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800165C8: nop

    // 0x800165CC: lh          $s0, 0x11C($t1)
    ctx->r16 = MEM_H(ctx->r9, 0X11C);
    // 0x800165D0: nop

    // 0x800165D4: sh          $s0, 0x11A($t1)
    MEM_H(0X11A, ctx->r9) = ctx->r16;
    // 0x800165D8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800165DC: nop

    // 0x800165E0: sh          $s0, 0x118($t3)
    MEM_H(0X118, ctx->r11) = ctx->r16;
    // 0x800165E4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800165E8: lw          $t4, -0x4538($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4538);
    // 0x800165EC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800165F0: nop

    // 0x800165F4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800165F8: b           L_80016608
    // 0x800165FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016608;
    // 0x800165FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016600: b           L_80016608
    // 0x80016604: nop

        goto L_80016608;
    // 0x80016604: nop

L_80016608:
    // 0x80016608: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001660C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80016610: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80016614: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80016618: jr          $ra
    // 0x8001661C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001661C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80073668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073668: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007366C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073670: nop

    // 0x80073674: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073678: nop

    // 0x8007367C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073680: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073684: jr          $ra
    // 0x80073688: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073688: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007368C: jr          $ra
    // 0x80073690: nop

    return;
    // 0x80073690: nop

    // 0x80073694: jr          $ra
    // 0x80073698: nop

    return;
    // 0x80073698: nop

;}
RECOMP_FUNC void func_80049544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80049548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004954C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80049550: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80049554: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80049558: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004955C: nop

    // 0x80049560: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80049564: bne         $t8, $zero, L_80049724
    if (ctx->r24 != 0) {
        // 0x80049568: nop
    
            goto L_80049724;
    }
    // 0x80049568: nop

    // 0x8004956C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80049570: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80049574: lbu         $t1, 0xFF8($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XFF8);
    // 0x80049578: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8004957C: nop

    // 0x80049580: bne         $t0, $t1, L_80049614
    if (ctx->r8 != ctx->r9) {
        // 0x80049584: nop
    
            goto L_80049614;
    }
    // 0x80049584: nop

    // 0x80049588: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004958C: lbu         $t2, 0xEE8($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0XEE8);
    // 0x80049590: nop

    // 0x80049594: beq         $t2, $zero, L_800495BC
    if (ctx->r10 == 0) {
        // 0x80049598: nop
    
            goto L_800495BC;
    }
    // 0x80049598: nop

    // 0x8004959C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800495A0: lbu         $a0, 0xEC8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XEC8);
    // 0x800495A4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800495A8: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x800495AC: jal         0x800C1264
    // 0x800495B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x800495B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800495B4: b           L_8004974C
    // 0x800495B8: nop

        goto L_8004974C;
    // 0x800495B8: nop

L_800495BC:
    // 0x800495BC: jal         0x8004975C
    // 0x800495C0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_8004975C(rdram, ctx);
        goto after_1;
    // 0x800495C0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_1:
    // 0x800495C4: beq         $v0, $zero, L_800495D4
    if (ctx->r2 == 0) {
        // 0x800495C8: nop
    
            goto L_800495D4;
    }
    // 0x800495C8: nop

    // 0x800495CC: b           L_8004974C
    // 0x800495D0: nop

        goto L_8004974C;
    // 0x800495D0: nop

L_800495D4:
    // 0x800495D4: jal         0x800498CC
    // 0x800495D8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_800498CC(rdram, ctx);
        goto after_2;
    // 0x800495D8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_2:
    // 0x800495DC: beq         $v0, $zero, L_800495EC
    if (ctx->r2 == 0) {
        // 0x800495E0: nop
    
            goto L_800495EC;
    }
    // 0x800495E0: nop

    // 0x800495E4: b           L_8004974C
    // 0x800495E8: nop

        goto L_8004974C;
    // 0x800495E8: nop

L_800495EC:
    // 0x800495EC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800495F0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800495F4: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x800495F8: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x800495FC: jal         0x800C1528
    // 0x80049600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMsg(rdram, ctx);
        goto after_3;
    // 0x80049600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80049604: b           L_8004974C
    // 0x80049608: nop

        goto L_8004974C;
    // 0x80049608: nop

    // 0x8004960C: b           L_80049724
    // 0x80049610: nop

        goto L_80049724;
    // 0x80049610: nop

L_80049614:
    // 0x80049614: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80049618: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004961C: lbu         $t5, 0xEC8($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0XEC8);
    // 0x80049620: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80049624: nop

    // 0x80049628: bne         $t4, $t5, L_80049688
    if (ctx->r12 != ctx->r13) {
        // 0x8004962C: nop
    
            goto L_80049688;
    }
    // 0x8004962C: nop

    // 0x80049630: jal         0x8004975C
    // 0x80049634: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_8004975C(rdram, ctx);
        goto after_4;
    // 0x80049634: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_4:
    // 0x80049638: beq         $v0, $zero, L_80049648
    if (ctx->r2 == 0) {
        // 0x8004963C: nop
    
            goto L_80049648;
    }
    // 0x8004963C: nop

    // 0x80049640: b           L_8004974C
    // 0x80049644: nop

        goto L_8004974C;
    // 0x80049644: nop

L_80049648:
    // 0x80049648: jal         0x800498CC
    // 0x8004964C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_800498CC(rdram, ctx);
        goto after_5;
    // 0x8004964C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_5:
    // 0x80049650: beq         $v0, $zero, L_80049660
    if (ctx->r2 == 0) {
        // 0x80049654: nop
    
            goto L_80049660;
    }
    // 0x80049654: nop

    // 0x80049658: b           L_8004974C
    // 0x8004965C: nop

        goto L_8004974C;
    // 0x8004965C: nop

L_80049660:
    // 0x80049660: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80049664: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80049668: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x8004966C: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x80049670: jal         0x800C1528
    // 0x80049674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMsg(rdram, ctx);
        goto after_6;
    // 0x80049674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80049678: b           L_8004974C
    // 0x8004967C: nop

        goto L_8004974C;
    // 0x8004967C: nop

    // 0x80049680: b           L_80049724
    // 0x80049684: nop

        goto L_80049724;
    // 0x80049684: nop

L_80049688:
    // 0x80049688: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004968C: jal         0x8004984C
    // 0x80049690: nop

    func_8004984C(rdram, ctx);
        goto after_7;
    // 0x80049690: nop

    after_7:
    // 0x80049694: beq         $v0, $zero, L_80049700
    if (ctx->r2 == 0) {
        // 0x80049698: nop
    
            goto L_80049700;
    }
    // 0x80049698: nop

    // 0x8004969C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800496A0: nop

    // 0x800496A4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800496A8: jal         0x8004975C
    // 0x800496AC: nop

    func_8004975C(rdram, ctx);
        goto after_8;
    // 0x800496AC: nop

    after_8:
    // 0x800496B0: beq         $v0, $zero, L_800496C0
    if (ctx->r2 == 0) {
        // 0x800496B4: nop
    
            goto L_800496C0;
    }
    // 0x800496B4: nop

    // 0x800496B8: b           L_8004974C
    // 0x800496BC: nop

        goto L_8004974C;
    // 0x800496BC: nop

L_800496C0:
    // 0x800496C0: jal         0x800498CC
    // 0x800496C4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_800498CC(rdram, ctx);
        goto after_9;
    // 0x800496C4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_9:
    // 0x800496C8: beq         $v0, $zero, L_800496D8
    if (ctx->r2 == 0) {
        // 0x800496CC: nop
    
            goto L_800496D8;
    }
    // 0x800496CC: nop

    // 0x800496D0: b           L_8004974C
    // 0x800496D4: nop

        goto L_8004974C;
    // 0x800496D4: nop

L_800496D8:
    // 0x800496D8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800496DC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800496E0: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x800496E4: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x800496E8: jal         0x800C1528
    // 0x800496EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMsg(rdram, ctx);
        goto after_10;
    // 0x800496EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x800496F0: b           L_8004974C
    // 0x800496F4: nop

        goto L_8004974C;
    // 0x800496F4: nop

    // 0x800496F8: b           L_80049724
    // 0x800496FC: nop

        goto L_80049724;
    // 0x800496FC: nop

L_80049700:
    // 0x80049700: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80049704: nop

    // 0x80049708: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8004970C: jal         0x800498CC
    // 0x80049710: nop

    func_800498CC(rdram, ctx);
        goto after_11;
    // 0x80049710: nop

    after_11:
    // 0x80049714: beq         $v0, $zero, L_80049724
    if (ctx->r2 == 0) {
        // 0x80049718: nop
    
            goto L_80049724;
    }
    // 0x80049718: nop

    // 0x8004971C: b           L_8004974C
    // 0x80049720: nop

        goto L_8004974C;
    // 0x80049720: nop

L_80049724:
    // 0x80049724: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80049728: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8004972C: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x80049730: addiu       $a0, $a0, -0x3790
    ctx->r4 = ADD32(ctx->r4, -0X3790);
    // 0x80049734: jal         0x800C1528
    // 0x80049738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMsg(rdram, ctx);
        goto after_12;
    // 0x80049738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x8004973C: b           L_8004974C
    // 0x80049740: nop

        goto L_8004974C;
    // 0x80049740: nop

    // 0x80049744: b           L_8004974C
    // 0x80049748: nop

        goto L_8004974C;
    // 0x80049748: nop

L_8004974C:
    // 0x8004974C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80049754: jr          $ra
    // 0x80049758: nop

    return;
    // 0x80049758: nop

;}
RECOMP_FUNC void __seqpReleaseVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D220C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D2210: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D2214: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D2218: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D221C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D2220: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D2224: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D2228: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D222C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D2230: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800D2234: lw          $s6, 0x10($a1)
    ctx->r22 = MEM_W(ctx->r5, 0X10);
    // 0x800D2238: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D223C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800D2240: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x800D2244: bnel        $t6, $zero, L_800D22B0
    if (ctx->r14 != 0) {
        // 0x800D2248: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_800D22B0;
    }
    goto skip_0;
    // 0x800D2248: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_0:
    // 0x800D224C: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x800D2250: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x800D2254: beql        $s0, $zero, L_800D22B0
    if (ctx->r16 == 0) {
        // 0x800D2258: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_800D22B0;
    }
    goto skip_1;
    // 0x800D2258: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_1:
L_800D225C:
    // 0x800D225C: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x800D2260: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D2264: bne         $s3, $t7, L_800D22A4
    if (ctx->r19 != ctx->r15) {
        // 0x800D2268: nop
    
            goto L_800D22A4;
    }
    // 0x800D2268: nop

    // 0x800D226C: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800D2270: bne         $s5, $t8, L_800D22A4
    if (ctx->r21 != ctx->r24) {
        // 0x800D2274: nop
    
            goto L_800D22A4;
    }
    // 0x800D2274: nop

    // 0x800D2278: beq         $s1, $zero, L_800D2290
    if (ctx->r17 == 0) {
        // 0x800D227C: addiu       $s2, $s4, 0x48
        ctx->r18 = ADD32(ctx->r20, 0X48);
            goto L_800D2290;
    }
    // 0x800D227C: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    // 0x800D2280: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800D2284: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x800D2288: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800D228C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_800D2290:
    // 0x800D2290: jal         0x800C7890
    // 0x800D2294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800D2294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D2298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D229C: jal         0x800C78C0
    // 0x800D22A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x800D22A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_800D22A4:
    // 0x800D22A4: bne         $s1, $zero, L_800D225C
    if (ctx->r17 != 0) {
        // 0x800D22A8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D225C;
    }
    // 0x800D22A8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D22AC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_800D22B0:
    // 0x800D22B0: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x800D22B4: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x800D22B8: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x800D22BC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800D22C0: lw          $t3, 0x1C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C);
    // 0x800D22C4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D22C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D22CC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800D22D0: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x800D22D4: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x800D22D8: jal         0x800D69C0
    // 0x800D22DC: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    alSynSetPriority(rdram, ctx);
        goto after_2;
    // 0x800D22DC: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    after_2:
    // 0x800D22E0: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x800D22E4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D22E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D22EC: jal         0x800D3DD0
    // 0x800D22F0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    alSynSetVol(rdram, ctx);
        goto after_3;
    // 0x800D22F0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x800D22F4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800D22F8: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x800D22FC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800D2300: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D2304: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800D2308: jal         0x800D3A2C
    // 0x800D230C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x800D230C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x800D2310: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D2314: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D2318: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D231C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D2320: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D2324: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D2328: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D232C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D2330: jr          $ra
    // 0x800D2334: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D2334: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80067008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067008: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006700C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067010: nop

    // 0x80067014: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80067018: nop

    // 0x8006701C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067020: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067024: jr          $ra
    // 0x80067028: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067028: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006702C: jr          $ra
    // 0x80067030: nop

    return;
    // 0x80067030: nop

    // 0x80067034: jr          $ra
    // 0x80067038: nop

    return;
    // 0x80067038: nop

;}
RECOMP_FUNC void func_8004FA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FA58: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8004FA5C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004FA60: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x8004FA64: beq         $a0, $at, L_8004FA90
    if (ctx->r4 == ctx->r1) {
        // 0x8004FA68: nop
    
            goto L_8004FA90;
    }
    // 0x8004FA68: nop

    // 0x8004FA6C: addiu       $at, $zero, 0x79
    ctx->r1 = ADD32(0, 0X79);
    // 0x8004FA70: beq         $a0, $at, L_8004FA90
    if (ctx->r4 == ctx->r1) {
        // 0x8004FA74: nop
    
            goto L_8004FA90;
    }
    // 0x8004FA74: nop

    // 0x8004FA78: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
    // 0x8004FA7C: beq         $a0, $at, L_8004FA90
    if (ctx->r4 == ctx->r1) {
        // 0x8004FA80: nop
    
            goto L_8004FA90;
    }
    // 0x8004FA80: nop

    // 0x8004FA84: addiu       $at, $zero, 0x7B
    ctx->r1 = ADD32(0, 0X7B);
    // 0x8004FA88: bne         $a0, $at, L_8004FA98
    if (ctx->r4 != ctx->r1) {
        // 0x8004FA8C: nop
    
            goto L_8004FA98;
    }
    // 0x8004FA8C: nop

L_8004FA90:
    // 0x8004FA90: jr          $ra
    // 0x8004FA94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8004FA94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004FA98:
    // 0x8004FA98: jr          $ra
    // 0x8004FA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8004FA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8006EDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EDE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EDE8: jal         0x80061348
    // 0x8006EDEC: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EDEC: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_0:
    // 0x8006EDF0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EDF4: b           L_8006EE04
    // 0x8006EDF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EE04;
    // 0x8006EDF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EDFC: b           L_8006EE04
    // 0x8006EE00: nop

        goto L_8006EE04;
    // 0x8006EE00: nop

L_8006EE04:
    // 0x8006EE04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EE08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EE0C: jr          $ra
    // 0x8006EE10: nop

    return;
    // 0x8006EE10: nop

;}
RECOMP_FUNC void func_8006C690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C698: jal         0x8005F064
    // 0x8006C69C: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C69C: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_0:
    // 0x8006C6A0: b           L_8006C6B0
    // 0x8006C6A4: nop

        goto L_8006C6B0;
    // 0x8006C6A4: nop

    // 0x8006C6A8: b           L_8006C6B0
    // 0x8006C6AC: nop

        goto L_8006C6B0;
    // 0x8006C6AC: nop

L_8006C6B0:
    // 0x8006C6B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C6B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C6B8: jr          $ra
    // 0x8006C6BC: nop

    return;
    // 0x8006C6BC: nop

;}
RECOMP_FUNC void Scheduler_IsTaskComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097C5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80097C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097C64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80097C68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097C6C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80097C70: nop

    // 0x80097C74: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80097C78: nop

    // 0x80097C7C: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x80097C80: bne         $t8, $zero, L_80097D24
    if (ctx->r24 != 0) {
        // 0x80097C84: nop
    
            goto L_80097D24;
    }
    // 0x80097C84: nop

    // 0x80097C88: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80097C90: lw          $a0, 0x50($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X50);
    // 0x80097C94: lw          $a1, 0x54($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X54);
    // 0x80097C98: jal         0x800C4AA0
    // 0x80097C9C: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80097C9C: nop

    after_0:
    // 0x80097CA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097CA4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097CA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80097CAC: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80097CB0: nop

    // 0x80097CB4: bne         $t1, $at, L_80097D1C
    if (ctx->r9 != ctx->r1) {
        // 0x80097CB8: nop
    
            goto L_80097D1C;
    }
    // 0x80097CB8: nop

    // 0x80097CBC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80097CC0: nop

    // 0x80097CC4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80097CC8: nop

    // 0x80097CCC: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x80097CD0: beq         $t4, $zero, L_80097D1C
    if (ctx->r12 == 0) {
        // 0x80097CD4: nop
    
            goto L_80097D1C;
    }
    // 0x80097CD4: nop

    // 0x80097CD8: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x80097CDC: beq         $t5, $zero, L_80097D1C
    if (ctx->r13 == 0) {
        // 0x80097CE0: nop
    
            goto L_80097D1C;
    }
    // 0x80097CE0: nop

    // 0x80097CE4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80097CE8: lw          $t6, -0x7344($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7344);
    // 0x80097CEC: nop

    // 0x80097CF0: beq         $t6, $zero, L_80097D08
    if (ctx->r14 == 0) {
        // 0x80097CF4: nop
    
            goto L_80097D08;
    }
    // 0x80097CF4: nop

    // 0x80097CF8: jal         0x800C46B0
    // 0x80097CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x80097CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80097D00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80097D04: sw          $zero, -0x7344($at)
    MEM_W(-0X7344, ctx->r1) = 0;
L_80097D08:
    // 0x80097D08: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097D0C: nop

    // 0x80097D10: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x80097D14: jal         0x800C4080
    // 0x80097D18: nop

    osViSwapBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x80097D18: nop

    after_2:
L_80097D1C:
    // 0x80097D1C: b           L_80097D34
    // 0x80097D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80097D34;
    // 0x80097D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80097D24:
    // 0x80097D24: b           L_80097D34
    // 0x80097D28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097D34;
    // 0x80097D28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097D2C: b           L_80097D34
    // 0x80097D30: nop

        goto L_80097D34;
    // 0x80097D30: nop

L_80097D34:
    // 0x80097D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097D38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097D3C: jr          $ra
    // 0x80097D40: nop

    return;
    // 0x80097D40: nop

;}
RECOMP_FUNC void func_80059ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059ED0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80059ED4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059ED8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80059EDC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80059EE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80059EE4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80059EE8: nop

    // 0x80059EEC: lw          $t7, 0x58($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X58);
    // 0x80059EF0: nop

    // 0x80059EF4: lbu         $t8, 0x16($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X16);
    // 0x80059EF8: nop

    // 0x80059EFC: sb          $t8, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r24;
    // 0x80059F00: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80059F04: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80059F08: nop

    // 0x80059F0C: lw          $a0, 0x58($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X58);
    // 0x80059F10: jal         0x80056C60
    // 0x80059F14: nop

    func_80056C60(rdram, ctx);
        goto after_0;
    // 0x80059F14: nop

    after_0:
    // 0x80059F18: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80059F1C: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80059F20: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80059F24: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x80059F28: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80059F2C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80059F30: lh          $t2, 0x2C52($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2C52);
    // 0x80059F34: nop

    // 0x80059F38: sh          $t2, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r10;
    // 0x80059F3C: jal         0x80059E28
    // 0x80059F40: nop

    func_80059E28(rdram, ctx);
        goto after_1;
    // 0x80059F40: nop

    after_1:
    // 0x80059F44: bne         $v0, $zero, L_80059F54
    if (ctx->r2 != 0) {
        // 0x80059F48: nop
    
            goto L_80059F54;
    }
    // 0x80059F48: nop

    // 0x80059F4C: b           L_8005A130
    // 0x80059F50: nop

        goto L_8005A130;
    // 0x80059F50: nop

L_80059F54:
    // 0x80059F54: lh          $t3, 0x34($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X34);
    // 0x80059F58: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80059F5C: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F60: nop
    
            goto L_80059FC0;
    }
    // 0x80059F60: nop

    // 0x80059F64: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80059F68: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F6C: nop
    
            goto L_80059FC0;
    }
    // 0x80059F6C: nop

    // 0x80059F70: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80059F74: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F78: nop
    
            goto L_80059FC0;
    }
    // 0x80059F78: nop

    // 0x80059F7C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80059F80: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F84: nop
    
            goto L_80059FC0;
    }
    // 0x80059F84: nop

    // 0x80059F88: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80059F8C: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F90: nop
    
            goto L_80059FC0;
    }
    // 0x80059F90: nop

    // 0x80059F94: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80059F98: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059F9C: nop
    
            goto L_80059FC0;
    }
    // 0x80059F9C: nop

    // 0x80059FA0: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80059FA4: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059FA8: nop
    
            goto L_80059FC0;
    }
    // 0x80059FA8: nop

    // 0x80059FAC: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80059FB0: beq         $t3, $at, L_80059FC0
    if (ctx->r11 == ctx->r1) {
        // 0x80059FB4: nop
    
            goto L_80059FC0;
    }
    // 0x80059FB4: nop

    // 0x80059FB8: b           L_8005A130
    // 0x80059FBC: nop

        goto L_8005A130;
    // 0x80059FBC: nop

L_80059FC0:
    // 0x80059FC0: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x80059FC4: nop

    // 0x80059FC8: bne         $t4, $zero, L_80059FFC
    if (ctx->r12 != 0) {
        // 0x80059FCC: nop
    
            goto L_80059FFC;
    }
    // 0x80059FCC: nop

    // 0x80059FD0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80059FD4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80059FD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059FDC: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80059FE0: nop

    // 0x80059FE4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80059FE8: nop

    // 0x80059FEC: bc1f        L_80059FFC
    if (!c1cs) {
        // 0x80059FF0: nop
    
            goto L_80059FFC;
    }
    // 0x80059FF0: nop

    // 0x80059FF4: b           L_8005A130
    // 0x80059FF8: nop

        goto L_8005A130;
    // 0x80059FF8: nop

L_80059FFC:
    // 0x80059FFC: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x8005A000: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A004: bne         $t6, $at, L_8005A038
    if (ctx->r14 != ctx->r1) {
        // 0x8005A008: nop
    
            goto L_8005A038;
    }
    // 0x8005A008: nop

    // 0x8005A00C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A010: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A014: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005A018: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8005A01C: nop

    // 0x8005A020: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8005A024: nop

    // 0x8005A028: bc1f        L_8005A038
    if (!c1cs) {
        // 0x8005A02C: nop
    
            goto L_8005A038;
    }
    // 0x8005A02C: nop

    // 0x8005A030: b           L_8005A130
    // 0x8005A034: nop

        goto L_8005A130;
    // 0x8005A034: nop

L_8005A038:
    // 0x8005A038: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005A03C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005A040: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A044: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005A048: lw          $a0, 0x58($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X58);
    // 0x8005A04C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005A050: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8005A054: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8005A058: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    // 0x8005A05C: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x8005A060: jal         0x800782A8
    // 0x8005A064: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800782A8(rdram, ctx);
        goto after_2;
    // 0x8005A064: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8005A068: bne         $v0, $zero, L_8005A078
    if (ctx->r2 != 0) {
        // 0x8005A06C: nop
    
            goto L_8005A078;
    }
    // 0x8005A06C: nop

    // 0x8005A070: b           L_8005A130
    // 0x8005A074: nop

        goto L_8005A130;
    // 0x8005A074: nop

L_8005A078:
    // 0x8005A078: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005A07C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005A080: lbu         $t3, 0x37($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X37);
    // 0x8005A084: lw          $t1, 0x58($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X58);
    // 0x8005A088: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8005A08C: lbu         $t2, 0x16($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X16);
    // 0x8005A090: nop

    // 0x8005A094: beq         $t2, $t4, L_8005A0A4
    if (ctx->r10 == ctx->r12) {
        // 0x8005A098: nop
    
            goto L_8005A0A4;
    }
    // 0x8005A098: nop

    // 0x8005A09C: b           L_8005A0A8
    // 0x8005A0A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8005A0A8;
    // 0x8005A0A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8005A0A4:
    // 0x8005A0A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8005A0A8:
    // 0x8005A0A8: beq         $s1, $zero, L_8005A128
    if (ctx->r17 == 0) {
        // 0x8005A0AC: nop
    
            goto L_8005A128;
    }
    // 0x8005A0AC: nop

L_8005A0B0:
    // 0x8005A0B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005A0B4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8005A0B8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A0BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005A0C0: lw          $a0, 0x58($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X58);
    // 0x8005A0C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A0C8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005A0CC: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8005A0D0: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    // 0x8005A0D4: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    // 0x8005A0D8: jal         0x800783EC
    // 0x8005A0DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800783EC(rdram, ctx);
        goto after_3;
    // 0x8005A0DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8005A0E0: bne         $v0, $zero, L_8005A0F0
    if (ctx->r2 != 0) {
        // 0x8005A0E4: nop
    
            goto L_8005A0F0;
    }
    // 0x8005A0E4: nop

    // 0x8005A0E8: b           L_8005A130
    // 0x8005A0EC: nop

        goto L_8005A130;
    // 0x8005A0EC: nop

L_8005A0F0:
    // 0x8005A0F0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005A0F4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8005A0F8: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x8005A0FC: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x8005A100: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8005A104: lbu         $t9, 0x16($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X16);
    // 0x8005A108: nop

    // 0x8005A10C: beq         $t9, $t1, L_8005A11C
    if (ctx->r25 == ctx->r9) {
        // 0x8005A110: nop
    
            goto L_8005A11C;
    }
    // 0x8005A110: nop

    // 0x8005A114: b           L_8005A120
    // 0x8005A118: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8005A120;
    // 0x8005A118: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8005A11C:
    // 0x8005A11C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8005A120:
    // 0x8005A120: bne         $s1, $zero, L_8005A0B0
    if (ctx->r17 != 0) {
        // 0x8005A124: nop
    
            goto L_8005A0B0;
    }
    // 0x8005A124: nop

L_8005A128:
    // 0x8005A128: b           L_8005A130
    // 0x8005A12C: nop

        goto L_8005A130;
    // 0x8005A12C: nop

L_8005A130:
    // 0x8005A130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005A134: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A138: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005A13C: jr          $ra
    // 0x8005A140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005A140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
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
RECOMP_FUNC void func_80063B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B20: jal         0x8005F064
    // 0x80063B24: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063B24: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063B28: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063B2C: b           L_80063B3C
    // 0x80063B30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063B3C;
    // 0x80063B30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063B34: b           L_80063B3C
    // 0x80063B38: nop

        goto L_80063B3C;
    // 0x80063B38: nop

L_80063B3C:
    // 0x80063B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063B44: jr          $ra
    // 0x80063B48: nop

    return;
    // 0x80063B48: nop

;}
RECOMP_FUNC void func_80072D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072D84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072D88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072D8C: nop

    // 0x80072D90: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072D94: nop

    // 0x80072D98: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072D9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072DA0: jr          $ra
    // 0x80072DA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072DA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072DA8: jr          $ra
    // 0x80072DAC: nop

    return;
    // 0x80072DAC: nop

    // 0x80072DB0: jr          $ra
    // 0x80072DB4: nop

    return;
    // 0x80072DB4: nop

;}
RECOMP_FUNC void func_80067A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A5C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067A60: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067A64: nop

    // 0x80067A68: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80067A6C: nop

    // 0x80067A70: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067A74: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067A78: jr          $ra
    // 0x80067A7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067A7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067A80: jr          $ra
    // 0x80067A84: nop

    return;
    // 0x80067A84: nop

    // 0x80067A88: jr          $ra
    // 0x80067A8C: nop

    return;
    // 0x80067A8C: nop

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
RECOMP_FUNC void alSndpSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9FF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9FF8: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800C9FFC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800CA000: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800CA004: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA008: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA00C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA010: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CA014: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CA018: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800CA01C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CA020: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800CA024: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA02C: jal         0x800D3A2C
    // 0x800CA030: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA030: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800CA034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA038: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA03C: jr          $ra
    // 0x800CA040: nop

    return;
    // 0x800CA040: nop

;}
RECOMP_FUNC void alSeqpSetSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CACA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CACA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CACA8: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x800CACAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CACB0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800CACB4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CACB8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CACBC: jal         0x800D3A2C
    // 0x800CACC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CACC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CACC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CACC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CACCC: jr          $ra
    // 0x800CACD0: nop

    return;
    // 0x800CACD0: nop

;}
RECOMP_FUNC void func_80052508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052508: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005250C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052510: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80052514: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80052518: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005251C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052520: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80052524: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80052528: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005252C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052530: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80052534: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x80052538: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8005253C: nop

    // 0x80052540: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80052544: nop

    // 0x80052548: bgez        $t1, L_80052560
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005254C: nop
    
            goto L_80052560;
    }
    // 0x8005254C: nop

    // 0x80052550: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052554: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80052558: nop

    // 0x8005255C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_80052560:
    // 0x80052560: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052564: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80052568: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005256C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80052570: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80052574: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x80052578: sh          $t7, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r15;
    // 0x8005257C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80052580: nop

    // 0x80052584: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80052588: nop

    // 0x8005258C: bgez        $t9, L_800525A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80052590: nop
    
            goto L_800525A4;
    }
    // 0x80052590: nop

    // 0x80052594: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052598: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005259C: nop

    // 0x800525A0: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
L_800525A4:
    // 0x800525A4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800525A8: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x800525AC: nop

    // 0x800525B0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800525B4: nop

    // 0x800525B8: beq         $t1, $zero, L_800525D0
    if (ctx->r9 == 0) {
        // 0x800525BC: nop
    
            goto L_800525D0;
    }
    // 0x800525BC: nop

    // 0x800525C0: lh          $t2, 0x2($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X2);
    // 0x800525C4: nop

    // 0x800525C8: bne         $t2, $zero, L_80052650
    if (ctx->r10 != 0) {
        // 0x800525CC: nop
    
            goto L_80052650;
    }
    // 0x800525CC: nop

L_800525D0:
    // 0x800525D0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800525D4: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800525D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800525DC: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800525E0: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x800525E4: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800525E8: lui         $at, 0xFEFF
    ctx->r1 = S32(0XFEFF << 16);
    // 0x800525EC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800525F0: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800525F4: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x800525F8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800525FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80052600: jal         0x800507AC
    // 0x80052604: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    func_800507AC(rdram, ctx);
        goto after_0;
    // 0x80052604: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    after_0:
    // 0x80052608: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8005260C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80052610: sh          $t5, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r13;
    // 0x80052614: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80052618:
    // 0x80052618: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005261C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80052620: bne         $t3, $at, L_80052630
    if (ctx->r11 != ctx->r1) {
        // 0x80052624: nop
    
            goto L_80052630;
    }
    // 0x80052624: nop

    // 0x80052628: jal         0x80059D80
    // 0x8005262C: nop

    func_80059D80(rdram, ctx);
        goto after_1;
    // 0x8005262C: nop

    after_1:
L_80052630:
    // 0x80052630: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80052634: jal         0x800499B0
    // 0x80052638: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x80052638: nop

    after_2:
    // 0x8005263C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80052640: nop

    // 0x80052644: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80052648: b           L_80052618
    // 0x8005264C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
        goto L_80052618;
    // 0x8005264C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_80052650:
    // 0x80052650: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80052654: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x80052658: nop

    // 0x8005265C: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x80052660: nop

    // 0x80052664: slti        $at, $t8, 0x3D
    ctx->r1 = SIGNED(ctx->r24) < 0X3D ? 1 : 0;
    // 0x80052668: beq         $at, $zero, L_80052678
    if (ctx->r1 == 0) {
        // 0x8005266C: nop
    
            goto L_80052678;
    }
    // 0x8005266C: nop

    // 0x80052670: b           L_800526B0
    // 0x80052674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800526B0;
    // 0x80052674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052678:
    // 0x80052678: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005267C: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80052680: nop

    // 0x80052684: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x80052688: nop

    // 0x8005268C: slti        $at, $t6, 0x3D
    ctx->r1 = SIGNED(ctx->r14) < 0X3D ? 1 : 0;
    // 0x80052690: beq         $at, $zero, L_800526A0
    if (ctx->r1 == 0) {
        // 0x80052694: nop
    
            goto L_800526A0;
    }
    // 0x80052694: nop

    // 0x80052698: b           L_800526B0
    // 0x8005269C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800526B0;
    // 0x8005269C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800526A0:
    // 0x800526A0: b           L_800526B0
    // 0x800526A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800526B0;
    // 0x800526A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800526A8: b           L_800526B0
    // 0x800526AC: nop

        goto L_800526B0;
    // 0x800526AC: nop

L_800526B0:
    // 0x800526B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800526B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800526B8: jr          $ra
    // 0x800526BC: nop

    return;
    // 0x800526BC: nop

;}
RECOMP_FUNC void func_8006D3CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D3CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D3D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D3D4: jal         0x80061488
    // 0x8006D3D8: addiu       $a0, $zero, 0x574
    ctx->r4 = ADD32(0, 0X574);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006D3D8: addiu       $a0, $zero, 0x574
    ctx->r4 = ADD32(0, 0X574);
    after_0:
    // 0x8006D3DC: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006D3E0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006D3E4: b           L_8006D3F4
    // 0x8006D3E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D3F4;
    // 0x8006D3E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D3EC: b           L_8006D3F4
    // 0x8006D3F0: nop

        goto L_8006D3F4;
    // 0x8006D3F0: nop

L_8006D3F4:
    // 0x8006D3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D3F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D3FC: jr          $ra
    // 0x8006D400: nop

    return;
    // 0x8006D400: nop

;}
RECOMP_FUNC void func_80044248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044248: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8004424C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80044250: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80044254: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80044258: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8004425C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80044260: lw          $t6, 0x71FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71FC);
    // 0x80044264: nop

    // 0x80044268: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8004426C: nop

    // 0x80044270: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80044274: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80044278: bgez        $a0, L_80044294
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8004427C: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_80044294;
    }
    // 0x8004427C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80044280: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80044284: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80044288: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004428C: nop

    // 0x80044290: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_80044294:
    // 0x80044294: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80044298: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004429C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800442A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800442A4: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800442A8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800442AC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800442B0: nop

    // 0x800442B4: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800442B8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800442BC: nop

    // 0x800442C0: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800442C4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800442C8: beq         $t9, $zero, L_80044320
    if (ctx->r25 == 0) {
        // 0x800442CC: nop
    
            goto L_80044320;
    }
    // 0x800442CC: nop

    // 0x800442D0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800442D4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800442D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800442DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800442E0: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x800442E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800442E8: nop

    // 0x800442EC: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x800442F0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800442F4: nop

    // 0x800442F8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800442FC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80044300: bne         $t9, $zero, L_80044318
    if (ctx->r25 != 0) {
        // 0x80044304: nop
    
            goto L_80044318;
    }
    // 0x80044304: nop

    // 0x80044308: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8004430C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80044310: b           L_80044330
    // 0x80044314: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80044330;
    // 0x80044314: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80044318:
    // 0x80044318: b           L_80044330
    // 0x8004431C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80044330;
    // 0x8004431C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80044320:
    // 0x80044320: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80044324: nop

    // 0x80044328: bltz        $t9, L_80044318
    if (SIGNED(ctx->r25) < 0) {
        // 0x8004432C: nop
    
            goto L_80044318;
    }
    // 0x8004432C: nop

L_80044330:
    // 0x80044330: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80044334: sh          $t9, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r25;
    // 0x80044338: nop

    // 0x8004433C: sh          $a1, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r5;
    // 0x80044340: lhu         $t0, 0xC($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XC);
    // 0x80044344: nop

    // 0x80044348: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004434C: bne         $at, $zero, L_80044434
    if (ctx->r1 != 0) {
        // 0x80044350: nop
    
            goto L_80044434;
    }
    // 0x80044350: nop

L_80044354:
    // 0x80044354: lhu         $t4, 0xC($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XC);
    // 0x80044358: lhu         $t5, 0x26($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X26);
    // 0x8004435C: lhu         $t1, 0xA($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XA);
    // 0x80044360: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80044364: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80044368: nop

    // 0x8004436C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80044370: mflo        $t6
    ctx->r14 = lo;
    // 0x80044374: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80044378: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8004437C: sh          $a0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r4;
    // 0x80044380: lhu         $t8, 0xE($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XE);
    // 0x80044384: nop

    // 0x80044388: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8004438C: bne         $at, $zero, L_80044418
    if (ctx->r1 != 0) {
        // 0x80044390: nop
    
            goto L_80044418;
    }
    // 0x80044390: nop

L_80044394:
    // 0x80044394: lhu         $t9, 0xE($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XE);
    // 0x80044398: nop

    // 0x8004439C: bgez        $t9, L_800443B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800443A0: andi        $t0, $t9, 0x1
        ctx->r8 = ctx->r25 & 0X1;
            goto L_800443B0;
    }
    // 0x800443A0: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800443A4: beq         $t0, $zero, L_800443B0
    if (ctx->r8 == 0) {
        // 0x800443A8: nop
    
            goto L_800443B0;
    }
    // 0x800443A8: nop

    // 0x800443AC: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_800443B0:
    // 0x800443B0: beq         $t0, $zero, L_800443E4
    if (ctx->r8 == 0) {
        // 0x800443B4: nop
    
            goto L_800443E4;
    }
    // 0x800443B4: nop

    // 0x800443B8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800443BC: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x800443C0: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800443C4: nop

    // 0x800443C8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800443CC: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
    // 0x800443D0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800443D4: nop

    // 0x800443D8: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x800443DC: b           L_800443FC
    // 0x800443E0: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
        goto L_800443FC;
    // 0x800443E0: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_800443E4:
    // 0x800443E4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800443E8: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x800443EC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800443F0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800443F4: or          $t2, $t8, $t0
    ctx->r10 = ctx->r24 | ctx->r8;
    // 0x800443F8: sb          $t2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r10;
L_800443FC:
    // 0x800443FC: lhu         $t4, 0xE($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XE);
    // 0x80044400: nop

    // 0x80044404: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80044408: andi        $t1, $t5, 0xFFFF
    ctx->r9 = ctx->r13 & 0XFFFF;
    // 0x8004440C: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80044410: beq         $at, $zero, L_80044394
    if (ctx->r1 == 0) {
        // 0x80044414: sh          $t5, 0xE($sp)
        MEM_H(0XE, ctx->r29) = ctx->r13;
            goto L_80044394;
    }
    // 0x80044414: sh          $t5, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r13;
L_80044418:
    // 0x80044418: lhu         $t3, 0xC($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XC);
    // 0x8004441C: nop

    // 0x80044420: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80044424: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x80044428: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8004442C: beq         $at, $zero, L_80044354
    if (ctx->r1 == 0) {
        // 0x80044430: sh          $t6, 0xC($sp)
        MEM_H(0XC, ctx->r29) = ctx->r14;
            goto L_80044354;
    }
    // 0x80044430: sh          $t6, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r14;
L_80044434:
    // 0x80044434: b           L_8004443C
    // 0x80044438: nop

        goto L_8004443C;
    // 0x80044438: nop

L_8004443C:
    // 0x8004443C: jr          $ra
    // 0x80044440: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80044440: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800664B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800664B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800664B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800664BC: jal         0x80061348
    // 0x800664C0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800664C0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x800664C4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800664C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800664CC: beq         $v0, $zero, L_800664E4
    if (ctx->r2 == 0) {
        // 0x800664D0: nop
    
            goto L_800664E4;
    }
    // 0x800664D0: nop

    // 0x800664D4: jal         0x80061348
    // 0x800664D8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800664D8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x800664DC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800664E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800664E4:
    // 0x800664E4: b           L_800664F4
    // 0x800664E8: nop

        goto L_800664F4;
    // 0x800664E8: nop

    // 0x800664EC: b           L_800664F4
    // 0x800664F0: nop

        goto L_800664F4;
    // 0x800664F0: nop

L_800664F4:
    // 0x800664F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800664F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800664FC: jr          $ra
    // 0x80066500: nop

    return;
    // 0x80066500: nop

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
