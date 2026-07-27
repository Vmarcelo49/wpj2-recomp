#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80066170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066178: jal         0x80061348
    // 0x8006617C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006617C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066180: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066184: b           L_80066194
    // 0x80066188: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066194;
    // 0x80066188: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006618C: b           L_80066194
    // 0x80066190: nop

        goto L_80066194;
    // 0x80066190: nop

L_80066194:
    // 0x80066194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006619C: jr          $ra
    // 0x800661A0: nop

    return;
    // 0x800661A0: nop

;}
RECOMP_FUNC void func_80075B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075B5C: jal         0x80061348
    // 0x80075B60: addiu       $a0, $zero, 0x45C
    ctx->r4 = ADD32(0, 0X45C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075B60: addiu       $a0, $zero, 0x45C
    ctx->r4 = ADD32(0, 0X45C);
    after_0:
    // 0x80075B64: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075B68: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075B6C: b           L_80075B7C
    // 0x80075B70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075B7C;
    // 0x80075B70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075B74: b           L_80075B7C
    // 0x80075B78: nop

        goto L_80075B7C;
    // 0x80075B78: nop

L_80075B7C:
    // 0x80075B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075B84: jr          $ra
    // 0x80075B88: nop

    return;
    // 0x80075B88: nop

;}
RECOMP_FUNC void func_8006BE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BE50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BE54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BE58: jal         0x8005F064
    // 0x8006BE5C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BE5C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_0:
    // 0x8006BE60: b           L_8006BE70
    // 0x8006BE64: nop

        goto L_8006BE70;
    // 0x8006BE64: nop

    // 0x8006BE68: b           L_8006BE70
    // 0x8006BE6C: nop

        goto L_8006BE70;
    // 0x8006BE6C: nop

L_8006BE70:
    // 0x8006BE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BE74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BE78: jr          $ra
    // 0x8006BE7C: nop

    return;
    // 0x8006BE7C: nop

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
RECOMP_FUNC void func_80076F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076F28: jal         0x80061488
    // 0x80076F2C: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076F2C: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076F30: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076F34: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076F38: b           L_80076F48
    // 0x80076F3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076F48;
    // 0x80076F3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076F40: b           L_80076F48
    // 0x80076F44: nop

        goto L_80076F48;
    // 0x80076F44: nop

L_80076F48:
    // 0x80076F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076F50: jr          $ra
    // 0x80076F54: nop

    return;
    // 0x80076F54: nop

;}
RECOMP_FUNC void func_80014BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014BD4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80014BD8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80014BDC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80014BE0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80014BE4: bgez        $t7, L_80014BF4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80014BE8: sra         $t8, $t7, 8
        ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
            goto L_80014BF4;
    }
    // 0x80014BE8: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80014BEC: addiu       $at, $t7, 0xFF
    ctx->r1 = ADD32(ctx->r15, 0XFF);
    // 0x80014BF0: sra         $t8, $at, 8
    ctx->r24 = S32(SIGNED(ctx->r1) >> 8);
L_80014BF4:
    // 0x80014BF4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80014BF8: andi        $t9, $a0, 0x8000
    ctx->r25 = ctx->r4 & 0X8000;
    // 0x80014BFC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80014C00: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80014C04: bne         $at, $zero, L_80014C20
    if (ctx->r1 != 0) {
        // 0x80014C08: nop
    
            goto L_80014C20;
    }
    // 0x80014C08: nop

    // 0x80014C0C: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x80014C10: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80014C14: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80014C18: b           L_80014C28
    // 0x80014C1C: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
        goto L_80014C28;
    // 0x80014C1C: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_80014C20:
    // 0x80014C20: andi        $t2, $a0, 0xFF
    ctx->r10 = ctx->r4 & 0XFF;
    // 0x80014C24: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_80014C28:
    // 0x80014C28: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x80014C2C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80014C30: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80014C34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80014C38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80014C3C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80014C40: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80014C44: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80014C48: nop

    // 0x80014C4C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80014C50: b           L_80014C60
    // 0x80014C54: add.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f10.fl;
        goto L_80014C60;
    // 0x80014C54: add.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80014C58: b           L_80014C60
    // 0x80014C5C: nop

        goto L_80014C60;
    // 0x80014C5C: nop

L_80014C60:
    // 0x80014C60: jr          $ra
    // 0x80014C64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80014C64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80028B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028B94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028B9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80028BA0: jal         0x80028468
    // 0x80028BA4: nop

    func_80028468(rdram, ctx);
        goto after_0;
    // 0x80028BA4: nop

    after_0:
    // 0x80028BA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80028BAC: nop

    // 0x80028BB0: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x80028BB4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80028BB8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80028BBC: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x80028BC0: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x80028BC4: nop

    // 0x80028BC8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80028BCC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80028BD0: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
    // 0x80028BD4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80028BD8: nop

    // 0x80028BDC: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80028BE0: nop

    // 0x80028BE4: beq         $t2, $zero, L_80028D38
    if (ctx->r10 == 0) {
        // 0x80028BE8: sh          $t2, 0x24($sp)
        MEM_H(0X24, ctx->r29) = ctx->r10;
            goto L_80028D38;
    }
    // 0x80028BE8: sh          $t2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r10;
L_80028BEC:
    // 0x80028BEC: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x80028BF0: nop

    // 0x80028BF4: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x80028BF8: beq         $t4, $zero, L_80028C08
    if (ctx->r12 == 0) {
        // 0x80028BFC: nop
    
            goto L_80028C08;
    }
    // 0x80028BFC: nop

    // 0x80028C00: b           L_80028D38
    // 0x80028C04: nop

        goto L_80028D38;
    // 0x80028C04: nop

L_80028C08:
    // 0x80028C08: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x80028C0C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80028C10: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80028C14: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80028C18: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80028C1C: addiu       $t7, $t7, 0x2578
    ctx->r15 = ADD32(ctx->r15, 0X2578);
    // 0x80028C20: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80028C24: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80028C28: lh          $t9, 0x24($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X24);
    // 0x80028C2C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80028C30: nop

    // 0x80028C34: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80028C38: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80028C3C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80028C40: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
    // 0x80028C44: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80028C48: addiu       $t3, $zero, -0x2
    ctx->r11 = ADD32(0, -0X2);
    // 0x80028C4C: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x80028C50: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80028C54: nop

    // 0x80028C58: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x80028C5C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80028C60: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80028C64: nop

    // 0x80028C68: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x80028C6C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80028C70: nop

    // 0x80028C74: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80028C78: nop

    // 0x80028C7C: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x80028C80: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80028C84: nop

    // 0x80028C88: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x80028C8C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80028C90: nop

    // 0x80028C94: sw          $zero, 0x18($t9)
    MEM_W(0X18, ctx->r25) = 0;
    // 0x80028C98: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x80028C9C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80028CA0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80028CA4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80028CA8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80028CAC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80028CB0: addiu       $t2, $t1, -0x28
    ctx->r10 = ADD32(ctx->r9, -0X28);
    // 0x80028CB4: addiu       $t3, $t3, 0x2578
    ctx->r11 = ADD32(ctx->r11, 0X2578);
    // 0x80028CB8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80028CBC: sw          $t4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r12;
    // 0x80028CC0: lh          $t6, 0x24($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X24);
    // 0x80028CC4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80028CC8: addiu       $t7, $t7, 0x1B18
    ctx->r15 = ADD32(ctx->r15, 0X1B18);
    // 0x80028CCC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80028CD0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80028CD4: nop

    // 0x80028CD8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80028CDC: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    // 0x80028CE0: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x80028CE4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80028CE8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80028CEC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80028CF0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80028CF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028CF8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80028CFC: sw          $t1, 0x2568($at)
    MEM_W(0X2568, ctx->r1) = ctx->r9;
    // 0x80028D00: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x80028D04: nop

    // 0x80028D08: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80028D0C: sh          $t5, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r13;
    // 0x80028D10: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80028D14: nop

    // 0x80028D18: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80028D1C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80028D20: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80028D24: nop

    // 0x80028D28: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80028D2C: nop

    // 0x80028D30: bne         $t0, $zero, L_80028BEC
    if (ctx->r8 != 0) {
        // 0x80028D34: sh          $t0, 0x24($sp)
        MEM_H(0X24, ctx->r29) = ctx->r8;
            goto L_80028BEC;
    }
    // 0x80028D34: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
L_80028D38:
    // 0x80028D38: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x80028D3C: addiu       $t2, $t2, -0x6550
    ctx->r10 = ADD32(ctx->r10, -0X6550);
    // 0x80028D40: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80028D44: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x80028D48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80028D4C: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
L_80028D50:
    // 0x80028D50: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80028D54: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80028D58: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80028D5C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80028D60: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80028D64: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80028D68: lh          $t5, 0x2578($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2578);
    // 0x80028D6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80028D70: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80028D74: sb          $t5, -0x6550($at)
    MEM_B(-0X6550, ctx->r1) = ctx->r13;
    // 0x80028D78: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x80028D7C: nop

    // 0x80028D80: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80028D84: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80028D88: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80028D8C: slti        $at, $t0, 0x46
    ctx->r1 = SIGNED(ctx->r8) < 0X46 ? 1 : 0;
    // 0x80028D90: bne         $at, $zero, L_80028D50
    if (ctx->r1 != 0) {
        // 0x80028D94: sh          $t7, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r15;
            goto L_80028D50;
    }
    // 0x80028D94: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x80028D98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80028D9C: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
L_80028DA0:
    // 0x80028DA0: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x80028DA4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80028DA8: jal         0x80028A20
    // 0x80028DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80028A20(rdram, ctx);
        goto after_1;
    // 0x80028DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80028DB0: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x80028DB4: nop

    // 0x80028DB8: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x80028DBC: sll         $t4, $t1, 16
    ctx->r12 = S32(ctx->r9 << 16);
    // 0x80028DC0: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80028DC4: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80028DC8: bne         $at, $zero, L_80028DA0
    if (ctx->r1 != 0) {
        // 0x80028DCC: sh          $t1, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r9;
            goto L_80028DA0;
    }
    // 0x80028DCC: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80028DD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80028DD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80028DD8: jal         0x80028A20
    // 0x80028DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80028A20(rdram, ctx);
        goto after_2;
    // 0x80028DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80028DE0: b           L_80028DE8
    // 0x80028DE4: nop

        goto L_80028DE8;
    // 0x80028DE4: nop

L_80028DE8:
    // 0x80028DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028DEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80028DF0: jr          $ra
    // 0x80028DF4: nop

    return;
    // 0x80028DF4: nop

;}
RECOMP_FUNC void MtxUtil_MtxToMtxF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2D10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C2D14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2D18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D1C: nop

    // 0x800C2D20: bne         $t6, $zero, L_800C2D44
    if (ctx->r14 != 0) {
        // 0x800C2D24: nop
    
            goto L_800C2D44;
    }
    // 0x800C2D24: nop

    // 0x800C2D28: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C2D2C: lw          $a0, 0xCE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE4);
    // 0x800C2D30: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D34: jal         0x800C2F1C
    // 0x800C2D38: nop

    MtxUtil__MtxToMtxF(rdram, ctx);
        goto after_0;
    // 0x800C2D38: nop

    after_0:
    // 0x800C2D3C: b           L_800C2D54
    // 0x800C2D40: nop

        goto L_800C2D54;
    // 0x800C2D40: nop

L_800C2D44:
    // 0x800C2D44: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D48: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D4C: jal         0x800C2F1C
    // 0x800C2D50: nop

    MtxUtil__MtxToMtxF(rdram, ctx);
        goto after_1;
    // 0x800C2D50: nop

    after_1:
L_800C2D54:
    // 0x800C2D54: b           L_800C2D5C
    // 0x800C2D58: nop

        goto L_800C2D5C;
    // 0x800C2D58: nop

L_800C2D5C:
    // 0x800C2D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2D64: jr          $ra
    // 0x800C2D68: nop

    return;
    // 0x800C2D68: nop

;}
RECOMP_FUNC void func_80040D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040D08: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80040D0C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80040D10: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80040D14: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80040D18: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80040D1C: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80040D20: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80040D24: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80040D28: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80040D2C: sh          $zero, 0xF2($sp)
    MEM_H(0XF2, ctx->r29) = 0;
    // 0x80040D30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80040D34: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x80040D38: nop

    // 0x80040D3C: beq         $t6, $zero, L_80040D58
    if (ctx->r14 == 0) {
        // 0x80040D40: nop
    
            goto L_80040D58;
    }
    // 0x80040D40: nop

    // 0x80040D44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80040D48: nop

    // 0x80040D4C: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x80040D50: b           L_80040DB0
    // 0x80040D54: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
        goto L_80040DB0;
    // 0x80040D54: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
L_80040D58:
    // 0x80040D58: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80040D5C: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80040D60: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80040D64: nop

    // 0x80040D68: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
    // 0x80040D6C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80040D70: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80040D74: lwc1        $f8, 0x14($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X14);
    // 0x80040D78: nop

    // 0x80040D7C: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x80040D80: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040D84: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80040D88: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80040D8C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80040D90: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80040D94: c.eq.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d == ctx->f18.d;
    // 0x80040D98: nop

    // 0x80040D9C: bc1f        L_80040DB0
    if (!c1cs) {
        // 0x80040DA0: nop
    
            goto L_80040DB0;
    }
    // 0x80040DA0: nop

    // 0x80040DA4: addiu       $a0, $sp, 0xE8
    ctx->r4 = ADD32(ctx->r29, 0XE8);
    // 0x80040DA8: jal         0x80034048
    // 0x80040DAC: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    func_80034048(rdram, ctx);
        goto after_0;
    // 0x80040DAC: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    after_0:
L_80040DB0:
    // 0x80040DB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040DB4: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80040DB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80040DBC: lwc1        $f9, -0x1338($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1338);
    // 0x80040DC0: lwc1        $f8, -0x1334($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1334);
    // 0x80040DC4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80040DC8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80040DCC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80040DD0: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x80040DD4: jal         0x800C3070
    // 0x80040DD8: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x80040DD8: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    after_1:
    // 0x80040DDC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040DE0: lwc1        $f18, 0x720C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x80040DE4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040DE8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80040DEC: lwc1        $f6, -0x73EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80040DF0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80040DF4: addiu       $t9, $t9, 0x7158
    ctx->r25 = ADD32(ctx->r25, 0X7158);
    // 0x80040DF8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80040DFC: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x80040E00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040E04: lwc1        $f10, -0x73E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x80040E08: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80040E0C: addiu       $t0, $t0, 0x7158
    ctx->r8 = ADD32(ctx->r8, 0X7158);
    // 0x80040E10: swc1        $f10, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f10.u32l;
    // 0x80040E14: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80040E18: jal         0x800C3338
    // 0x80040E1C: nop

    MathUtil_Cosf(rdram, ctx);
        goto after_2;
    // 0x80040E1C: nop

    after_2:
    // 0x80040E20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040E24: lwc1        $f16, 0x720C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x80040E28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040E2C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80040E30: lwc1        $f4, -0x73D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80040E34: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80040E38: addiu       $t1, $t1, 0x7158
    ctx->r9 = ADD32(ctx->r9, 0X7158);
    // 0x80040E3C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80040E40: swc1        $f6, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f6.u32l;
    // 0x80040E44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040E48: lwc1        $f8, -0x73EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80040E4C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80040E50: addiu       $t2, $t2, 0x7158
    ctx->r10 = ADD32(ctx->r10, 0X7158);
    // 0x80040E54: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x80040E58: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040E5C: lwc1        $f10, -0x73E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x80040E60: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80040E64: addiu       $t3, $t3, 0x7158
    ctx->r11 = ADD32(ctx->r11, 0X7158);
    // 0x80040E68: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x80040E6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80040E70: lwc1        $f16, -0x73D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80040E74: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80040E78: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x80040E7C: swc1        $f16, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f16.u32l;
    // 0x80040E80: jal         0x800C1754
    // 0x80040E84: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_3;
    // 0x80040E84: nop

    after_3:
    // 0x80040E88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80040E8C: lwc1        $f12, 0x72E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X72E8);
    // 0x80040E90: jal         0x800C23E8
    // 0x80040E94: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x80040E94: nop

    after_4:
    // 0x80040E98: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80040E9C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80040EA0: addiu       $a1, $a1, 0x7158
    ctx->r5 = ADD32(ctx->r5, 0X7158);
    // 0x80040EA4: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80040EA8: jal         0x800B1250
    // 0x80040EAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800B1250(rdram, ctx);
        goto after_5;
    // 0x80040EAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80040EB0: jal         0x800C1A84
    // 0x80040EB4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_6;
    // 0x80040EB4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_6:
    // 0x80040EB8: jal         0x800AD680
    // 0x80040EBC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800AD680(rdram, ctx);
        goto after_7;
    // 0x80040EBC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_7:
    // 0x80040EC0: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80040EC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80040EC8: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80040ECC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80040ED0: jal         0x800AF184
    // 0x80040ED4: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    func_800AF184(rdram, ctx);
        goto after_8;
    // 0x80040ED4: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    after_8:
    // 0x80040ED8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80040EDC: lw          $t5, 0x7214($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7214);
    // 0x80040EE0: nop

    // 0x80040EE4: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x80040EE8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80040EEC: nop

    // 0x80040EF0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80040EF4: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x80040EF8: jal         0x800C1850
    // 0x80040EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_9;
    // 0x80040EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80040F00: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80040F04: lw          $t8, 0x258C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X258C);
    // 0x80040F08: nop

    // 0x80040F0C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80040F10: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80040F14: bgez        $t9, L_80040F2C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80040F18: cvt.s.w     $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80040F2C;
    }
    // 0x80040F18: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040F1C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80040F20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040F24: nop

    // 0x80040F28: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_80040F2C:
    // 0x80040F2C: jal         0x800C25B8
    // 0x80040F30: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_10;
    // 0x80040F30: nop

    after_10:
    // 0x80040F34: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80040F38: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x80040F3C: nop

    // 0x80040F40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80040F44: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80040F48: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80040F4C: bgez        $t1, L_80040F64
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80040F50: cvt.s.w     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80040F64;
    }
    // 0x80040F50: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80040F54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80040F58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040F5C: nop

    // 0x80040F60: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_80040F64:
    // 0x80040F64: jal         0x800C23E8
    // 0x80040F68: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_11;
    // 0x80040F68: nop

    after_11:
    // 0x80040F6C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80040F70: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80040F74: jal         0x800C2304
    // 0x80040F78: lui         $a2, 0x42FE
    ctx->r6 = S32(0X42FE << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_12;
    // 0x80040F78: lui         $a2, 0x42FE
    ctx->r6 = S32(0X42FE << 16);
    after_12:
    // 0x80040F7C: jal         0x800B1844
    // 0x80040F80: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800B1844(rdram, ctx);
        goto after_13;
    // 0x80040F80: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_13:
    // 0x80040F84: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80040F88: addiu       $t2, $sp, 0x6C
    ctx->r10 = ADD32(ctx->r29, 0X6C);
    // 0x80040F8C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80040F90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80040F94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80040F98: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80040F9C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80040FA0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80040FA4: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80040FA8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80040FAC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80040FB0: sb          $t5, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r13;
    // 0x80040FB4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80040FB8: addiu       $t7, $sp, 0x6C
    ctx->r15 = ADD32(ctx->r29, 0X6C);
    // 0x80040FBC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80040FC0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80040FC4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80040FC8: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80040FCC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80040FD0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80040FD4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80040FD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80040FDC: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80040FE0: sb          $t0, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r8;
    // 0x80040FE4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80040FE8: addiu       $t2, $sp, 0x6C
    ctx->r10 = ADD32(ctx->r29, 0X6C);
    // 0x80040FEC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80040FF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80040FF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80040FF8: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80040FFC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80041000: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80041004: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80041008: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8004100C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80041010: sb          $t5, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r13;
    // 0x80041014: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80041018: nop

    // 0x8004101C: addiu       $t8, $t7, 0x18
    ctx->r24 = ADD32(ctx->r15, 0X18);
    // 0x80041020: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80041024: jal         0x800C1850
    // 0x80041028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_14;
    // 0x80041028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8004102C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80041030: lw          $t9, 0x258C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X258C);
    // 0x80041034: nop

    // 0x80041038: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8004103C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80041040: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80041044: bgez        $t0, L_8004105C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80041048: cvt.s.w     $f12, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8004105C;
    }
    // 0x80041048: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004104C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041050: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041054: nop

    // 0x80041058: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
L_8004105C:
    // 0x8004105C: jal         0x800C25B8
    // 0x80041060: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_15;
    // 0x80041060: nop

    after_15:
    // 0x80041064: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80041068: lw          $t1, 0x258C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X258C);
    // 0x8004106C: nop

    // 0x80041070: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80041074: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80041078: bgez        $t2, L_80041090
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8004107C: cvt.s.w     $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80041090;
    }
    // 0x8004107C: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80041080: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80041088: nop

    // 0x8004108C: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_80041090:
    // 0x80041090: jal         0x800C23E8
    // 0x80041094: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_16;
    // 0x80041094: nop

    after_16:
    // 0x80041098: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8004109C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800410A0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800410A4: jal         0x800C2304
    // 0x800410A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_17;
    // 0x800410A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_17:
    // 0x800410AC: jal         0x800B1844
    // 0x800410B0: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800B1844(rdram, ctx);
        goto after_18;
    // 0x800410B0: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_18:
    // 0x800410B4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800410B8: addiu       $t3, $sp, 0x6C
    ctx->r11 = ADD32(ctx->r29, 0X6C);
    // 0x800410BC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800410C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800410C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800410C8: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800410CC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800410D0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800410D4: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800410D8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800410DC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800410E0: sb          $t6, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r14;
    // 0x800410E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800410E8: addiu       $t8, $sp, 0x6C
    ctx->r24 = ADD32(ctx->r29, 0X6C);
    // 0x800410EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800410F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800410F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800410F8: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800410FC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80041100: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80041104: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80041108: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004110C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80041110: sb          $t1, 0x9($t2)
    MEM_B(0X9, ctx->r10) = ctx->r9;
    // 0x80041114: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80041118: addiu       $t3, $sp, 0x6C
    ctx->r11 = ADD32(ctx->r29, 0X6C);
    // 0x8004111C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80041120: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80041124: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80041128: lwc1        $f18, 0x8($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8004112C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80041130: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80041134: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80041138: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8004113C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80041140: sb          $t6, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r14;
    // 0x80041144: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80041148: jal         0x800A5624
    // 0x8004114C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_19;
    // 0x8004114C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_19:
    // 0x80041150: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80041154: lw          $t8, 0x7260($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7260);
    // 0x80041158: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004115C: lwc1        $f6, 0x14($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X14);
    // 0x80041160: nop

    // 0x80041164: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80041168: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x8004116C: bc1t        L_800419CC
    if (c1cs) {
        // 0x80041170: nop
    
            goto L_800419CC;
    }
    // 0x80041170: nop

    // 0x80041174: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80041178: lw          $t9, 0x726C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X726C);
    // 0x8004117C: nop

    // 0x80041180: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80041184: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x80041188: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004118C: lw          $t1, 0x726C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X726C);
    // 0x80041190: nop

    // 0x80041194: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x80041198: nop

    // 0x8004119C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800411A0: nop

    // 0x800411A4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800411A8: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    // 0x800411AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800411B0: lw          $t3, 0x258C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X258C);
    // 0x800411B4: nop

    // 0x800411B8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800411BC: bgez        $t3, L_800411D8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800411C0: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_800411D8;
    }
    // 0x800411C0: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800411C4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800411C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800411CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800411D0: nop

    // 0x800411D4: add.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d + ctx->f6.d;
L_800411D8:
    // 0x800411D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800411DC: lwc1        $f9, -0x1330($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1330);
    // 0x800411E0: lwc1        $f8, -0x132C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X132C);
    // 0x800411E4: nop

    // 0x800411E8: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800411EC: jal         0x800C3070
    // 0x800411F0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_20;
    // 0x800411F0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_20:
    // 0x800411F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800411F8: nop

    // 0x800411FC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80041200: nop

    // 0x80041204: bc1f        L_8004125C
    if (!c1cs) {
        // 0x80041208: nop
    
            goto L_8004125C;
    }
    // 0x80041208: nop

    // 0x8004120C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80041210: lw          $t4, 0x258C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X258C);
    // 0x80041214: nop

    // 0x80041218: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8004121C: bgez        $t4, L_80041238
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80041220: cvt.d.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
            goto L_80041238;
    }
    // 0x80041220: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80041224: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80041228: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004122C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80041230: nop

    // 0x80041234: add.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f6.d + ctx->f4.d;
L_80041238:
    // 0x80041238: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004123C: lwc1        $f9, -0x1328($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1328);
    // 0x80041240: lwc1        $f8, -0x1324($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1324);
    // 0x80041244: nop

    // 0x80041248: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004124C: jal         0x800C3070
    // 0x80041250: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_21;
    // 0x80041250: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_21:
    // 0x80041254: b           L_800412A8
    // 0x80041258: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_800412A8;
    // 0x80041258: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8004125C:
    // 0x8004125C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80041260: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x80041264: nop

    // 0x80041268: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8004126C: bgez        $t5, L_80041288
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80041270: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_80041288;
    }
    // 0x80041270: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80041274: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80041278: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004127C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80041280: nop

    // 0x80041284: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_80041288:
    // 0x80041288: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004128C: lwc1        $f7, -0x1320($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1320);
    // 0x80041290: lwc1        $f6, -0x131C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X131C);
    // 0x80041294: nop

    // 0x80041298: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8004129C: jal         0x800C3070
    // 0x800412A0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_22;
    // 0x800412A0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_22:
    // 0x800412A4: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_800412A8:
    // 0x800412A8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800412AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800412B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800412B4: mul.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x800412B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800412BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800412C0: nop

    // 0x800412C4: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800412C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800412CC: nop

    // 0x800412D0: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x800412D4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800412D8: beq         $t7, $zero, L_8004132C
    if (ctx->r15 == 0) {
        // 0x800412DC: nop
    
            goto L_8004132C;
    }
    // 0x800412DC: nop

    // 0x800412E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800412E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800412E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800412EC: sub.s       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800412F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800412F4: nop

    // 0x800412F8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800412FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80041300: nop

    // 0x80041304: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80041308: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8004130C: bne         $t7, $zero, L_80041324
    if (ctx->r15 != 0) {
        // 0x80041310: nop
    
            goto L_80041324;
    }
    // 0x80041310: nop

    // 0x80041314: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80041318: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004131C: b           L_8004133C
    // 0x80041320: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8004133C;
    // 0x80041320: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80041324:
    // 0x80041324: b           L_8004133C
    // 0x80041328: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8004133C;
    // 0x80041328: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8004132C:
    // 0x8004132C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80041330: nop

    // 0x80041334: bltz        $t7, L_80041324
    if (SIGNED(ctx->r15) < 0) {
        // 0x80041338: nop
    
            goto L_80041324;
    }
    // 0x80041338: nop

L_8004133C:
    // 0x8004133C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80041340: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80041344: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80041348: addiu       $t9, $t8, 0x64
    ctx->r25 = ADD32(ctx->r24, 0X64);
    // 0x8004134C: sh          $t9, 0xD2($t0)
    MEM_H(0XD2, ctx->r8) = ctx->r25;
    // 0x80041350: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80041354: lbu         $t1, 0x7256($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7256);
    // 0x80041358: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004135C: bne         $t1, $at, L_80041644
    if (ctx->r9 != ctx->r1) {
        // 0x80041360: nop
    
            goto L_80041644;
    }
    // 0x80041360: nop

    // 0x80041364: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80041368: lw          $t2, 0x258C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X258C);
    // 0x8004136C: nop

    // 0x80041370: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80041374: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80041378: bgez        $t3, L_80041394
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8004137C: cvt.d.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
            goto L_80041394;
    }
    // 0x8004137C: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80041380: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80041384: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80041388: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004138C: nop

    // 0x80041390: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_80041394:
    // 0x80041394: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80041398: lwc1        $f11, -0x1318($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1318);
    // 0x8004139C: lwc1        $f10, -0x1314($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1314);
    // 0x800413A0: nop

    // 0x800413A4: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800413A8: jal         0x800C3070
    // 0x800413AC: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_23;
    // 0x800413AC: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_23:
    // 0x800413B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800413B4: nop

    // 0x800413B8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800413BC: nop

    // 0x800413C0: bc1f        L_8004141C
    if (!c1cs) {
        // 0x800413C4: nop
    
            goto L_8004141C;
    }
    // 0x800413C4: nop

    // 0x800413C8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800413CC: lw          $t4, 0x258C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X258C);
    // 0x800413D0: nop

    // 0x800413D4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800413D8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800413DC: bgez        $t5, L_800413F8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800413E0: cvt.d.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
            goto L_800413F8;
    }
    // 0x800413E0: cvt.d.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
    // 0x800413E4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800413E8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800413EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800413F0: nop

    // 0x800413F4: add.d       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f8.d + ctx->f6.d;
L_800413F8:
    // 0x800413F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800413FC: lwc1        $f11, -0x1310($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1310);
    // 0x80041400: lwc1        $f10, -0x130C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X130C);
    // 0x80041404: nop

    // 0x80041408: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8004140C: jal         0x800C3070
    // 0x80041410: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_24;
    // 0x80041410: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_24:
    // 0x80041414: b           L_8004146C
    // 0x80041418: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8004146C;
    // 0x80041418: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8004141C:
    // 0x8004141C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80041420: lw          $t6, 0x258C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X258C);
    // 0x80041424: nop

    // 0x80041428: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8004142C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80041430: bgez        $t7, L_8004144C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80041434: cvt.d.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
            goto L_8004144C;
    }
    // 0x80041434: cvt.d.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
    // 0x80041438: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004143C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80041440: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80041444: nop

    // 0x80041448: add.d       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f18.d + ctx->f6.d;
L_8004144C:
    // 0x8004144C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80041450: lwc1        $f9, -0x1308($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1308);
    // 0x80041454: lwc1        $f8, -0x1304($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1304);
    // 0x80041458: nop

    // 0x8004145C: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80041460: jal         0x800C3070
    // 0x80041464: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_25;
    // 0x80041464: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_25:
    // 0x80041468: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_8004146C:
    // 0x8004146C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80041470: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041474: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80041478: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8004147C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80041480: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80041484: nop

    // 0x80041488: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8004148C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80041490: nop

    // 0x80041494: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80041498: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8004149C: beq         $t9, $zero, L_800414F0
    if (ctx->r25 == 0) {
        // 0x800414A0: nop
    
            goto L_800414F0;
    }
    // 0x800414A0: nop

    // 0x800414A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800414A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800414AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800414B0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800414B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800414B8: nop

    // 0x800414BC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800414C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800414C4: nop

    // 0x800414C8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800414CC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800414D0: bne         $t9, $zero, L_800414E8
    if (ctx->r25 != 0) {
        // 0x800414D4: nop
    
            goto L_800414E8;
    }
    // 0x800414D4: nop

    // 0x800414D8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800414DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800414E0: b           L_80041500
    // 0x800414E4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80041500;
    // 0x800414E4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800414E8:
    // 0x800414E8: b           L_80041500
    // 0x800414EC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80041500;
    // 0x800414EC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800414F0:
    // 0x800414F0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800414F4: nop

    // 0x800414F8: bltz        $t9, L_800414E8
    if (SIGNED(ctx->r25) < 0) {
        // 0x800414FC: nop
    
            goto L_800414E8;
    }
    // 0x800414FC: nop

L_80041500:
    // 0x80041500: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80041504: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80041508: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8004150C: sh          $t0, 0xCE($t1)
    MEM_H(0XCE, ctx->r9) = ctx->r8;
    // 0x80041510: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80041514: lh          $t2, 0x6C0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X6C0);
    // 0x80041518: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004151C: beq         $t2, $at, L_8004163C
    if (ctx->r10 == ctx->r1) {
        // 0x80041520: nop
    
            goto L_8004163C;
    }
    // 0x80041520: nop

    // 0x80041524: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80041528: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8004152C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80041530: lwc1        $f14, -0x73D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80041534: lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XDC);
    // 0x80041538: lw          $a3, 0xD8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD8);
    // 0x8004153C: jal         0x800C3C08
    // 0x80041540: nop

    MathUtil_GetDistance2D(rdram, ctx);
        goto after_26;
    // 0x80041540: nop

    after_26:
    // 0x80041544: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80041548: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004154C: nop

    // 0x80041550: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80041554: nop

    // 0x80041558: bc1f        L_8004163C
    if (!c1cs) {
        // 0x8004155C: nop
    
            goto L_8004163C;
    }
    // 0x8004155C: nop

    // 0x80041560: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80041564: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041568: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x8004156C: jal         0x800C4240
    // 0x80041570: nop

    guRandom(rdram, ctx);
        goto after_27;
    // 0x80041570: nop

    after_27:
    // 0x80041574: bgez        $v0, L_80041588
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80041578: andi        $t4, $v0, 0xFF
        ctx->r12 = ctx->r2 & 0XFF;
            goto L_80041588;
    }
    // 0x80041578: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x8004157C: beq         $t4, $zero, L_80041588
    if (ctx->r12 == 0) {
        // 0x80041580: nop
    
            goto L_80041588;
    }
    // 0x80041580: nop

    // 0x80041584: addiu       $t4, $t4, -0x100
    ctx->r12 = ADD32(ctx->r12, -0X100);
L_80041588:
    // 0x80041588: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8004158C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80041590: sw          $t5, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = ctx->r13;
    // 0x80041594: jal         0x800C4240
    // 0x80041598: nop

    guRandom(rdram, ctx);
        goto after_28;
    // 0x80041598: nop

    after_28:
    // 0x8004159C: bgez        $v0, L_800415B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800415A0: andi        $t6, $v0, 0xFF
        ctx->r14 = ctx->r2 & 0XFF;
            goto L_800415B0;
    }
    // 0x800415A0: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800415A4: beq         $t6, $zero, L_800415B0
    if (ctx->r14 == 0) {
        // 0x800415A8: nop
    
            goto L_800415B0;
    }
    // 0x800415A8: nop

    // 0x800415AC: addiu       $t6, $t6, -0x100
    ctx->r14 = ADD32(ctx->r14, -0X100);
L_800415B0:
    // 0x800415B0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800415B4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800415B8: sw          $t7, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = ctx->r15;
    // 0x800415BC: jal         0x800C4240
    // 0x800415C0: nop

    guRandom(rdram, ctx);
        goto after_29;
    // 0x800415C0: nop

    after_29:
    // 0x800415C4: bgez        $v0, L_800415D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800415C8: andi        $t8, $v0, 0xFF
        ctx->r24 = ctx->r2 & 0XFF;
            goto L_800415D8;
    }
    // 0x800415C8: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x800415CC: beq         $t8, $zero, L_800415D8
    if (ctx->r24 == 0) {
        // 0x800415D0: nop
    
            goto L_800415D8;
    }
    // 0x800415D0: nop

    // 0x800415D4: addiu       $t8, $t8, -0x100
    ctx->r24 = ADD32(ctx->r24, -0X100);
L_800415D8:
    // 0x800415D8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800415DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800415E0: sw          $t9, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = ctx->r25;
    // 0x800415E4: addiu       $t0, $zero, -0x7FF4
    ctx->r8 = ADD32(0, -0X7FF4);
    // 0x800415E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800415EC: sh          $t0, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r8;
    // 0x800415F0: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x800415F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800415F8: sh          $t1, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r9;
    // 0x800415FC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80041600: lh          $t2, 0x7268($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7268);
    // 0x80041604: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80041608: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8004160C: sh          $t3, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r11;
    // 0x80041610: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80041614: sb          $zero, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = 0;
    // 0x80041618: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004161C: lw          $t5, 0x7260($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7260);
    // 0x80041620: addiu       $t4, $zero, 0x2D0
    ctx->r12 = ADD32(0, 0X2D0);
    // 0x80041624: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80041628: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8004162C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041630: sh          $t6, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r14;
    // 0x80041634: jal         0x800B9000
    // 0x80041638: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800B9000(rdram, ctx);
        goto after_30;
    // 0x80041638: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_30:
L_8004163C:
    // 0x8004163C: b           L_800417F0
    // 0x80041640: nop

        goto L_800417F0;
    // 0x80041640: nop

L_80041644:
    // 0x80041644: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80041648: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x8004164C: nop

    // 0x80041650: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80041654: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80041658: bgez        $t8, L_80041674
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8004165C: cvt.d.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
            goto L_80041674;
    }
    // 0x8004165C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80041660: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80041664: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80041668: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004166C: nop

    // 0x80041670: add.d       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f10.d + ctx->f16.d;
L_80041674:
    // 0x80041674: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80041678: lwc1        $f5, -0x1300($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1300);
    // 0x8004167C: lwc1        $f4, -0x12FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X12FC);
    // 0x80041680: nop

    // 0x80041684: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80041688: jal         0x800C3070
    // 0x8004168C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_31;
    // 0x8004168C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_31:
    // 0x80041690: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80041694: nop

    // 0x80041698: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8004169C: nop

    // 0x800416A0: bc1f        L_800416FC
    if (!c1cs) {
        // 0x800416A4: nop
    
            goto L_800416FC;
    }
    // 0x800416A4: nop

    // 0x800416A8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800416AC: lw          $t9, 0x258C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X258C);
    // 0x800416B0: nop

    // 0x800416B4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800416B8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800416BC: bgez        $t0, L_800416D8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800416C0: cvt.d.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
            goto L_800416D8;
    }
    // 0x800416C0: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800416C4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800416C8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800416CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800416D0: nop

    // 0x800416D4: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_800416D8:
    // 0x800416D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800416DC: lwc1        $f5, -0x12F8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X12F8);
    // 0x800416E0: lwc1        $f4, -0x12F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X12F4);
    // 0x800416E4: nop

    // 0x800416E8: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x800416EC: jal         0x800C3070
    // 0x800416F0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_32;
    // 0x800416F0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_32:
    // 0x800416F4: b           L_8004174C
    // 0x800416F8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8004174C;
    // 0x800416F8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_800416FC:
    // 0x800416FC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80041700: lw          $t1, 0x258C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X258C);
    // 0x80041704: nop

    // 0x80041708: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8004170C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80041710: bgez        $t2, L_8004172C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80041714: cvt.d.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
            goto L_8004172C;
    }
    // 0x80041714: cvt.d.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.d = CVT_D_W(ctx->f18.u32l);
    // 0x80041718: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004171C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80041720: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80041724: nop

    // 0x80041728: add.d       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f8.d + ctx->f10.d;
L_8004172C:
    // 0x8004172C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80041730: lwc1        $f17, -0x12F0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X12F0);
    // 0x80041734: lwc1        $f16, -0x12EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X12EC);
    // 0x80041738: nop

    // 0x8004173C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80041740: jal         0x800C3070
    // 0x80041744: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_33;
    // 0x80041744: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_33:
    // 0x80041748: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_8004174C:
    // 0x8004174C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80041750: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041754: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80041758: mul.s       $f18, $f20, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8004175C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80041760: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80041764: nop

    // 0x80041768: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8004176C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80041770: nop

    // 0x80041774: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80041778: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8004177C: beq         $t4, $zero, L_800417D0
    if (ctx->r12 == 0) {
        // 0x80041780: nop
    
            goto L_800417D0;
    }
    // 0x80041780: nop

    // 0x80041784: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80041788: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004178C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80041790: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80041794: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80041798: nop

    // 0x8004179C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800417A0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800417A4: nop

    // 0x800417A8: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800417AC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800417B0: bne         $t4, $zero, L_800417C8
    if (ctx->r12 != 0) {
        // 0x800417B4: nop
    
            goto L_800417C8;
    }
    // 0x800417B4: nop

    // 0x800417B8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800417BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800417C0: b           L_800417E0
    // 0x800417C4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800417E0;
    // 0x800417C4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800417C8:
    // 0x800417C8: b           L_800417E0
    // 0x800417CC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800417E0;
    // 0x800417CC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800417D0:
    // 0x800417D0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800417D4: nop

    // 0x800417D8: bltz        $t4, L_800417C8
    if (SIGNED(ctx->r12) < 0) {
        // 0x800417DC: nop
    
            goto L_800417C8;
    }
    // 0x800417DC: nop

L_800417E0:
    // 0x800417E0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800417E4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800417E8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800417EC: sh          $t5, 0xD0($t6)
    MEM_H(0XD0, ctx->r14) = ctx->r13;
L_800417F0:
    // 0x800417F0: jal         0x800C1850
    // 0x800417F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_34;
    // 0x800417F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x800417F8: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800417FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80041800: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80041804: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x80041808: jal         0x800C2304
    // 0x8004180C: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_35;
    // 0x8004180C: nop

    after_35:
    // 0x80041810: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80041814: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x80041818: nop

    // 0x8004181C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80041820: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80041824: bgez        $t8, L_8004183C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80041828: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8004183C;
    }
    // 0x80041828: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004182C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041830: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041834: nop

    // 0x80041838: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
L_8004183C:
    // 0x8004183C: jal         0x800C25B8
    // 0x80041840: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_36;
    // 0x80041840: nop

    after_36:
    // 0x80041844: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80041848: lw          $t9, 0x258C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X258C);
    // 0x8004184C: nop

    // 0x80041850: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80041854: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80041858: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8004185C: bgez        $t0, L_80041878
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80041860: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_80041878;
    }
    // 0x80041860: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80041864: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80041868: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004186C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80041870: nop

    // 0x80041874: add.d       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f6.d + ctx->f18.d;
L_80041878:
    // 0x80041878: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004187C: lwc1        $f11, -0x12E8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X12E8);
    // 0x80041880: lwc1        $f10, -0x12E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X12E4);
    // 0x80041884: nop

    // 0x80041888: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8004188C: jal         0x800C3070
    // 0x80041890: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_37;
    // 0x80041890: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_37:
    // 0x80041894: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80041898: lw          $t1, 0x258C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X258C);
    // 0x8004189C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800418A0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800418A4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800418A8: addiu       $t3, $t2, 0xB4
    ctx->r11 = ADD32(ctx->r10, 0XB4);
    // 0x800418AC: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800418B0: bgez        $t3, L_800418CC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800418B4: cvt.d.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
            goto L_800418CC;
    }
    // 0x800418B4: cvt.d.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
    // 0x800418B8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800418BC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800418C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800418C4: nop

    // 0x800418C8: add.d       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f4.d + ctx->f18.d;
L_800418CC:
    // 0x800418CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800418D0: lwc1        $f7, -0x12E0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X12E0);
    // 0x800418D4: lwc1        $f6, -0x12DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X12DC);
    // 0x800418D8: nop

    // 0x800418DC: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800418E0: jal         0x800C3070
    // 0x800418E4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_38;
    // 0x800418E4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_38:
    // 0x800418E8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800418EC: lw          $t4, 0x258C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X258C);
    // 0x800418F0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800418F4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800418F8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800418FC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80041900: bgez        $t5, L_8004191C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80041904: cvt.d.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
            goto L_8004191C;
    }
    // 0x80041904: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80041908: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004190C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80041910: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80041914: nop

    // 0x80041918: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_8004191C:
    // 0x8004191C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80041920: lwc1        $f5, -0x12D8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X12D8);
    // 0x80041924: lwc1        $f4, -0x12D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X12D4);
    // 0x80041928: nop

    // 0x8004192C: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80041930: jal         0x800C3070
    // 0x80041934: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_39;
    // 0x80041934: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_39:
    // 0x80041938: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004193C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80041940: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80041944: cvt.d.s     $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.d = CVT_D_S(ctx->f24.fl);
    // 0x80041948: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8004194C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80041950: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80041954: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80041958: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004195C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80041960: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80041964: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x80041968: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8004196C: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x80041970: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80041974: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80041978: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004197C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80041980: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80041984: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80041988: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004198C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80041990: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x80041994: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80041998: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x8004199C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800419A0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800419A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800419A8: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x800419AC: add.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d + ctx->f8.d;
    // 0x800419B0: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x800419B4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800419B8: jal         0x800C2948
    // 0x800419BC: nop

    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_40;
    // 0x800419BC: nop

    after_40:
    // 0x800419C0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800419C4: jal         0x800A4638
    // 0x800419C8: nop

    func_800A4638(rdram, ctx);
        goto after_41;
    // 0x800419C8: nop

    after_41:
L_800419CC:
    // 0x800419CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800419D0: lh          $t6, 0x6C0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6C0);
    // 0x800419D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800419D8: beq         $t6, $at, L_80041A40
    if (ctx->r14 == ctx->r1) {
        // 0x800419DC: nop
    
            goto L_80041A40;
    }
    // 0x800419DC: nop

    // 0x800419E0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800419E4: lw          $t7, -0x73B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73B8);
    // 0x800419E8: nop

    // 0x800419EC: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800419F0: jal         0x800C1850
    // 0x800419F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_42;
    // 0x800419F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_42:
    // 0x800419F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800419FC: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80041A00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80041A04: lwc1        $f4, -0x73E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x80041A08: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80041A0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041A10: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80041A14: lw          $a2, -0x73D4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X73D4);
    // 0x80041A18: jal         0x800C2304
    // 0x80041A1C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_43;
    // 0x80041A1C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_43:
    // 0x80041A20: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80041A24: jal         0x800997D8
    // 0x80041A28: nop

    func_800997D8(rdram, ctx);
        goto after_44;
    // 0x80041A28: nop

    after_44:
    // 0x80041A2C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80041A30: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x80041A34: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80041A38: jal         0x800B26E0
    // 0x80041A3C: nop

    func_800B26E0(rdram, ctx);
        goto after_45;
    // 0x80041A3C: nop

    after_45:
L_80041A40:
    // 0x80041A40: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80041A44: lw          $a0, -0x73B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B4);
    // 0x80041A48: jal         0x80033C60
    // 0x80041A4C: nop

    func_80033C60(rdram, ctx);
        goto after_46;
    // 0x80041A4C: nop

    after_46:
    // 0x80041A50: jal         0x800C1AF4
    // 0x80041A54: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_47;
    // 0x80041A54: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_47:
    // 0x80041A58: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80041A5C: lw          $t8, 0x71FC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X71FC);
    // 0x80041A60: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80041A64: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80041A68: lwc1        $f10, -0x73D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80041A6C: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x80041A70: lw          $a3, -0x73EC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X73EC);
    // 0x80041A74: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80041A78: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80041A7C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80041A80: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80041A84: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80041A88: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80041A8C: jal         0x800349C0
    // 0x80041A90: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800349C0(rdram, ctx);
        goto after_48;
    // 0x80041A90: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_48:
    // 0x80041A94: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80041A98: lw          $t1, 0x724C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X724C);
    // 0x80041A9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80041AA0: lbu         $t2, 0x1A8($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1A8);
    // 0x80041AA4: nop

    // 0x80041AA8: beq         $t2, $at, L_80041EA8
    if (ctx->r10 == ctx->r1) {
        // 0x80041AAC: nop
    
            goto L_80041EA8;
    }
    // 0x80041AAC: nop

    // 0x80041AB0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80041AB4: lw          $t3, 0x724C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X724C);
    // 0x80041AB8: nop

    // 0x80041ABC: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80041AC0: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x80041AC4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80041AC8: lw          $t5, 0x724C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X724C);
    // 0x80041ACC: nop

    // 0x80041AD0: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80041AD4: nop

    // 0x80041AD8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80041ADC: nop

    // 0x80041AE0: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041AE4: swc1        $f18, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
    // 0x80041AE8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80041AEC: lw          $t7, 0x724C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X724C);
    // 0x80041AF0: nop

    // 0x80041AF4: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80041AF8: nop

    // 0x80041AFC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80041B00: nop

    // 0x80041B04: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80041B08: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x80041B0C: jal         0x800C1850
    // 0x80041B10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_49;
    // 0x80041B10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_49:
    // 0x80041B14: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80041B18: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041B1C: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x80041B20: jal         0x800C2304
    // 0x80041B24: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_50;
    // 0x80041B24: nop

    after_50:
    // 0x80041B28: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80041B2C: jal         0x800997D8
    // 0x80041B30: nop

    func_800997D8(rdram, ctx);
        goto after_51;
    // 0x80041B30: nop

    after_51:
    // 0x80041B34: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80041B38: lw          $a1, 0x724C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X724C);
    // 0x80041B3C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80041B40: jal         0x800B26E0
    // 0x80041B44: addiu       $a1, $a1, 0x168
    ctx->r5 = ADD32(ctx->r5, 0X168);
    func_800B26E0(rdram, ctx);
        goto after_52;
    // 0x80041B44: addiu       $a1, $a1, 0x168
    ctx->r5 = ADD32(ctx->r5, 0X168);
    after_52:
    // 0x80041B48: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80041B4C: lwc1        $f10, -0x73EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80041B50: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80041B54: nop

    // 0x80041B58: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80041B5C: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x80041B60: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80041B64: lwc1        $f16, -0x73D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80041B68: lwc1        $f18, 0xD8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80041B6C: nop

    // 0x80041B70: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80041B74: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
    // 0x80041B78: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80041B7C: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80041B80: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80041B84: nop

    // 0x80041B88: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80041B8C: jal         0x800C42A0
    // 0x80041B90: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_53;
    // 0x80041B90: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_53:
    // 0x80041B94: swc1        $f0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f0.u32l;
    // 0x80041B98: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80041B9C: lw          $t9, 0x724C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X724C);
    // 0x80041BA0: nop

    // 0x80041BA4: lbu         $t0, 0x1A8($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1A8);
    // 0x80041BA8: nop

    // 0x80041BAC: bne         $t0, $zero, L_80041C00
    if (ctx->r8 != 0) {
        // 0x80041BB0: nop
    
            goto L_80041C00;
    }
    // 0x80041BB0: nop

    // 0x80041BB4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80041BB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80041BBC: lwc1        $f16, 0xD4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041BC0: nop

    // 0x80041BC4: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80041BC8: nop

    // 0x80041BCC: bc1f        L_80041C00
    if (!c1cs) {
        // 0x80041BD0: nop
    
            goto L_80041C00;
    }
    // 0x80041BD0: nop

    // 0x80041BD4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80041BD8: lw          $t2, 0x724C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X724C);
    // 0x80041BDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80041BE0: sb          $t1, 0x1A8($t2)
    MEM_B(0X1A8, ctx->r10) = ctx->r9;
    // 0x80041BE4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80041BE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041BEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80041BF0: swc1        $f6, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f6.u32l;
    // 0x80041BF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80041BF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041BFC: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
L_80041C00:
    // 0x80041C00: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80041C04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80041C08: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041C0C: nop

    // 0x80041C10: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80041C14: nop

    // 0x80041C18: bc1f        L_80041C2C
    if (!c1cs) {
        // 0x80041C1C: nop
    
            goto L_80041C2C;
    }
    // 0x80041C1C: nop

    // 0x80041C20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041C24: b           L_80041D08
    // 0x80041C28: sh          $zero, 0x6C8($at)
    MEM_H(0X6C8, ctx->r1) = 0;
        goto L_80041D08;
    // 0x80041C28: sh          $zero, 0x6C8($at)
    MEM_H(0X6C8, ctx->r1) = 0;
L_80041C2C:
    // 0x80041C2C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80041C30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80041C34: lwc1        $f16, 0xD4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041C38: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80041C3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041C40: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80041C44: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80041C48: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80041C4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80041C50: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041C54: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80041C58: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80041C5C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80041C60: nop

    // 0x80041C64: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80041C68: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80041C6C: nop

    // 0x80041C70: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80041C74: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80041C78: beq         $t5, $zero, L_80041CCC
    if (ctx->r13 == 0) {
        // 0x80041C7C: nop
    
            goto L_80041CCC;
    }
    // 0x80041C7C: nop

    // 0x80041C80: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80041C84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041C88: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041C8C: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80041C90: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80041C94: nop

    // 0x80041C98: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80041C9C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80041CA0: nop

    // 0x80041CA4: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80041CA8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80041CAC: bne         $t5, $zero, L_80041CC4
    if (ctx->r13 != 0) {
        // 0x80041CB0: nop
    
            goto L_80041CC4;
    }
    // 0x80041CB0: nop

    // 0x80041CB4: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80041CB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80041CBC: b           L_80041CDC
    // 0x80041CC0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80041CDC;
    // 0x80041CC0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80041CC4:
    // 0x80041CC4: b           L_80041CDC
    // 0x80041CC8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80041CDC;
    // 0x80041CC8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80041CCC:
    // 0x80041CCC: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80041CD0: nop

    // 0x80041CD4: bltz        $t5, L_80041CC4
    if (SIGNED(ctx->r13) < 0) {
        // 0x80041CD8: nop
    
            goto L_80041CC4;
    }
    // 0x80041CD8: nop

L_80041CDC:
    // 0x80041CDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041CE0: sh          $t5, 0x6C8($at)
    MEM_H(0X6C8, ctx->r1) = ctx->r13;
    // 0x80041CE4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80041CE8: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80041CEC: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80041CF0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80041CF4: bne         $at, $zero, L_80041D08
    if (ctx->r1 != 0) {
        // 0x80041CF8: nop
    
            goto L_80041D08;
    }
    // 0x80041CF8: nop

    // 0x80041CFC: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80041D00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041D04: sh          $t7, 0x6C8($at)
    MEM_H(0X6C8, ctx->r1) = ctx->r15;
L_80041D08:
    // 0x80041D08: jal         0x800C1850
    // 0x80041D0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_54;
    // 0x80041D0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
    // 0x80041D10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80041D14: lwc1        $f12, 0x7324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80041D18: jal         0x800C25B8
    // 0x80041D1C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_55;
    // 0x80041D1C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_55:
    // 0x80041D20: lwc1        $f12, 0xCC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80041D24: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041D28: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x80041D2C: jal         0x800C2304
    // 0x80041D30: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_56;
    // 0x80041D30: nop

    after_56:
    // 0x80041D34: jal         0x800B1844
    // 0x80041D38: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800B1844(rdram, ctx);
        goto after_57;
    // 0x80041D38: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_57:
    // 0x80041D3C: addiu       $t8, $sp, 0x6C
    ctx->r24 = ADD32(ctx->r29, 0X6C);
    // 0x80041D40: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80041D44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041D48: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80041D4C: nop

    // 0x80041D50: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80041D54: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x80041D58: bc1f        L_80041D70
    if (!c1cs) {
        // 0x80041D5C: nop
    
            goto L_80041D70;
    }
    // 0x80041D5C: nop

    // 0x80041D60: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80041D64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80041D68: b           L_80041DA0
    // 0x80041D6C: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
        goto L_80041DA0;
    // 0x80041D6C: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
L_80041D70:
    // 0x80041D70: lui         $at, 0xC2FE
    ctx->r1 = S32(0XC2FE << 16);
    // 0x80041D74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80041D78: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041D7C: nop

    // 0x80041D80: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80041D84: nop

    // 0x80041D88: bc1f        L_80041DA0
    if (!c1cs) {
        // 0x80041D8C: nop
    
            goto L_80041DA0;
    }
    // 0x80041D8C: nop

    // 0x80041D90: lui         $at, 0xC2FE
    ctx->r1 = S32(0XC2FE << 16);
    // 0x80041D94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041D98: nop

    // 0x80041D9C: swc1        $f16, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f16.u32l;
L_80041DA0:
    // 0x80041DA0: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80041DA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041DA8: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041DAC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80041DB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80041DB4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80041DB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80041DBC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80041DC0: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80041DC4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80041DC8: nop

    // 0x80041DCC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80041DD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80041DD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80041DD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041DDC: cvt.w.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_D(ctx->f16.d);
    // 0x80041DE0: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80041DE4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80041DE8: sh          $t0, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = ctx->r8;
    // 0x80041DEC: nop

    // 0x80041DF0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80041DF4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80041DF8: lh          $a3, 0x65C($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X65C);
    // 0x80041DFC: lhu         $a2, 0x6C8($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X6C8);
    // 0x80041E00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80041E04: jal         0x80031C90
    // 0x80041E08: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    func_80031C90(rdram, ctx);
        goto after_58;
    // 0x80041E08: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    after_58:
    // 0x80041E0C: bne         $v0, $zero, L_80041E70
    if (ctx->r2 != 0) {
        // 0x80041E10: nop
    
            goto L_80041E70;
    }
    // 0x80041E10: nop

    // 0x80041E14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041E18: lwc1        $f6, 0xE6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE6C);
    // 0x80041E1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041E20: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80041E24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041E28: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80041E2C: swc1        $f10, 0xE6C($at)
    MEM_W(0XE6C, ctx->r1) = ctx->f10.u32l;
    // 0x80041E30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041E34: lwc1        $f18, 0xE60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80041E38: nop

    // 0x80041E3C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80041E40: nop

    // 0x80041E44: bc1f        L_80041E68
    if (!c1cs) {
        // 0x80041E48: nop
    
            goto L_80041E68;
    }
    // 0x80041E48: nop

    // 0x80041E4C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80041E50: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80041E54: lh          $a3, 0x65C($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X65C);
    // 0x80041E58: lhu         $a2, 0x6C8($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X6C8);
    // 0x80041E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80041E60: jal         0x80031C90
    // 0x80041E64: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    func_80031C90(rdram, ctx);
        goto after_59;
    // 0x80041E64: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    after_59:
L_80041E68:
    // 0x80041E68: b           L_80041EA8
    // 0x80041E6C: nop

        goto L_80041EA8;
    // 0x80041E6C: nop

L_80041E70:
    // 0x80041E70: jal         0x800C4240
    // 0x80041E74: nop

    guRandom(rdram, ctx);
        goto after_60;
    // 0x80041E74: nop

    after_60:
    // 0x80041E78: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80041E7C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80041E80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041E84: mfhi        $t1
    ctx->r9 = hi;
    // 0x80041E88: addiu       $t2, $t1, 0xA
    ctx->r10 = ADD32(ctx->r9, 0XA);
    // 0x80041E8C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80041E90: nop

    // 0x80041E94: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80041E98: swc1        $f4, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f4.u32l;
    // 0x80041E9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80041EA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80041EA4: swc1        $f6, 0xE6C($at)
    MEM_W(0XE6C, ctx->r1) = ctx->f6.u32l;
L_80041EA8:
    // 0x80041EA8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80041EAC: lh          $t3, 0x7268($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7268);
    // 0x80041EB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80041EB4: bne         $t3, $at, L_8004214C
    if (ctx->r11 != ctx->r1) {
        // 0x80041EB8: nop
    
            goto L_8004214C;
    }
    // 0x80041EB8: nop

    // 0x80041EBC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80041EC0: lw          $t4, 0x7220($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7220);
    // 0x80041EC4: nop

    // 0x80041EC8: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80041ECC: nop

    // 0x80041ED0: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x80041ED4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80041ED8: lw          $t5, 0x7220($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7220);
    // 0x80041EDC: nop

    // 0x80041EE0: lwc1        $f10, 0x4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80041EE4: nop

    // 0x80041EE8: swc1        $f10, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f10.u32l;
    // 0x80041EEC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80041EF0: lw          $t6, 0x7220($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7220);
    // 0x80041EF4: nop

    // 0x80041EF8: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80041EFC: nop

    // 0x80041F00: swc1        $f18, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
    // 0x80041F04: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80041F08: lw          $t7, 0x7220($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7220);
    // 0x80041F0C: nop

    // 0x80041F10: lhu         $t8, 0x10($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X10);
    // 0x80041F14: nop

    // 0x80041F18: sh          $t8, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r24;
    // 0x80041F1C: lhu         $s0, 0xF6($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0XF6);
    // 0x80041F20: nop

    // 0x80041F24: beq         $s0, $zero, L_80041F58
    if (ctx->r16 == 0) {
        // 0x80041F28: nop
    
            goto L_80041F58;
    }
    // 0x80041F28: nop

    // 0x80041F2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80041F30: beq         $s0, $at, L_80041FC8
    if (ctx->r16 == ctx->r1) {
        // 0x80041F34: nop
    
            goto L_80041FC8;
    }
    // 0x80041F34: nop

    // 0x80041F38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80041F3C: beq         $s0, $at, L_80042018
    if (ctx->r16 == ctx->r1) {
        // 0x80041F40: nop
    
            goto L_80042018;
    }
    // 0x80041F40: nop

    // 0x80041F44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80041F48: beq         $s0, $at, L_80042064
    if (ctx->r16 == ctx->r1) {
        // 0x80041F4C: nop
    
            goto L_80042064;
    }
    // 0x80041F4C: nop

    // 0x80041F50: b           L_800420A8
    // 0x80041F54: nop

        goto L_800420A8;
    // 0x80041F54: nop

L_80041F58:
    // 0x80041F58: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80041F5C: lbu         $t9, 0x7256($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7256);
    // 0x80041F60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80041F64: bne         $t9, $at, L_80041FC0
    if (ctx->r25 != ctx->r1) {
        // 0x80041F68: nop
    
            goto L_80041FC0;
    }
    // 0x80041F68: nop

    // 0x80041F6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80041F70: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80041F74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80041F78: lwc1        $f14, -0x73D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80041F7C: lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XDC);
    // 0x80041F80: lw          $a3, 0xD8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD8);
    // 0x80041F84: jal         0x800C3C08
    // 0x80041F88: nop

    MathUtil_GetDistance2D(rdram, ctx);
        goto after_61;
    // 0x80041F88: nop

    after_61:
    // 0x80041F8C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80041F90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041F94: nop

    // 0x80041F98: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80041F9C: nop

    // 0x80041FA0: bc1f        L_80041FC0
    if (!c1cs) {
        // 0x80041FA4: nop
    
            goto L_80041FC0;
    }
    // 0x80041FA4: nop

    // 0x80041FA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80041FAC: sh          $t0, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r8;
    // 0x80041FB0: jal         0x800220F4
    // 0x80041FB4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    func_800220F4(rdram, ctx);
        goto after_62;
    // 0x80041FB4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_62:
    // 0x80041FB8: jal         0x800B9000
    // 0x80041FBC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    func_800B9000(rdram, ctx);
        goto after_63;
    // 0x80041FBC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_63:
L_80041FC0:
    // 0x80041FC0: b           L_800420A8
    // 0x80041FC4: nop

        goto L_800420A8;
    // 0x80041FC4: nop

L_80041FC8:
    // 0x80041FC8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80041FCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041FD0: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041FD4: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80041FD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80041FDC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80041FE0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80041FE4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80041FE8: c.le.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d <= ctx->f10.d;
    // 0x80041FEC: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    // 0x80041FF0: bc1f        L_80042010
    if (!c1cs) {
        // 0x80041FF4: nop
    
            goto L_80042010;
    }
    // 0x80041FF4: nop

    // 0x80041FF8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80041FFC: sh          $t1, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r9;
    // 0x80042000: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80042004: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80042008: nop

    // 0x8004200C: swc1        $f16, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f16.u32l;
L_80042010:
    // 0x80042010: b           L_800420A8
    // 0x80042014: nop

        goto L_800420A8;
    // 0x80042014: nop

L_80042018:
    // 0x80042018: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004201C: lwc1        $f12, -0x73EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x80042020: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80042024: lwc1        $f14, -0x73D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x80042028: lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XDC);
    // 0x8004202C: lw          $a3, 0xD8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD8);
    // 0x80042030: jal         0x800C3C08
    // 0x80042034: nop

    MathUtil_GetDistance2D(rdram, ctx);
        goto after_64;
    // 0x80042034: nop

    after_64:
    // 0x80042038: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004203C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80042040: nop

    // 0x80042044: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80042048: nop

    // 0x8004204C: bc1f        L_8004205C
    if (!c1cs) {
        // 0x80042050: nop
    
            goto L_8004205C;
    }
    // 0x80042050: nop

    // 0x80042054: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80042058: sh          $t2, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = ctx->r10;
L_8004205C:
    // 0x8004205C: b           L_800420A8
    // 0x80042060: nop

        goto L_800420A8;
    // 0x80042060: nop

L_80042064:
    // 0x80042064: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80042068: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004206C: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80042070: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80042074: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80042078: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004207C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80042080: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x80042084: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x80042088: bc1f        L_800420A0
    if (!c1cs) {
        // 0x8004208C: nop
    
            goto L_800420A0;
    }
    // 0x8004208C: nop

    // 0x80042090: sh          $zero, 0xF6($sp)
    MEM_H(0XF6, ctx->r29) = 0;
    // 0x80042094: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80042098: nop

    // 0x8004209C: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
L_800420A0:
    // 0x800420A0: b           L_800420A8
    // 0x800420A4: nop

        goto L_800420A8;
    // 0x800420A4: nop

L_800420A8:
    // 0x800420A8: jal         0x800C1AF4
    // 0x800420AC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_65;
    // 0x800420AC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_65:
    // 0x800420B0: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800420B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800420B8: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x800420BC: jal         0x800C2304
    // 0x800420C0: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_66;
    // 0x800420C0: nop

    after_66:
    // 0x800420C4: jal         0x800B1844
    // 0x800420C8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800B1844(rdram, ctx);
        goto after_67;
    // 0x800420C8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_67:
    // 0x800420CC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800420D0: lw          $t3, 0x7220($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7220);
    // 0x800420D4: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800420D8: nop

    // 0x800420DC: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x800420E0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800420E4: lw          $t5, 0x7220($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7220);
    // 0x800420E8: lhu         $t4, 0xF6($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XF6);
    // 0x800420EC: nop

    // 0x800420F0: sh          $t4, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r12;
    // 0x800420F4: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x800420F8: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800420FC: lwc1        $f14, 0x4($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80042100: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    // 0x80042104: jal         0x800AF1F0
    // 0x80042108: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_800AF1F0(rdram, ctx);
        goto after_68;
    // 0x80042108: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_68:
    // 0x8004210C: beq         $v0, $zero, L_8004214C
    if (ctx->r2 == 0) {
        // 0x80042110: nop
    
            goto L_8004214C;
    }
    // 0x80042110: nop

    // 0x80042114: jal         0x800C1850
    // 0x80042118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_69;
    // 0x80042118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_69:
    // 0x8004211C: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80042120: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80042124: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80042128: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x8004212C: jal         0x800C2304
    // 0x80042130: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_70;
    // 0x80042130: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_70:
    // 0x80042134: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80042138: lw          $t7, 0x722C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X722C);
    // 0x8004213C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80042140: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80042144: jal         0x800A42C8
    // 0x80042148: nop

    func_800A42C8(rdram, ctx);
        goto after_71;
    // 0x80042148: nop

    after_71:
L_8004214C:
    // 0x8004214C: jal         0x800C1850
    // 0x80042150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_72;
    // 0x80042150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_72:
    // 0x80042154: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042158: lwc1        $f12, 0x7324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8004215C: jal         0x800C25B8
    // 0x80042160: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_73;
    // 0x80042160: nop

    after_73:
    // 0x80042164: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80042168: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004216C: jal         0x800C2304
    // 0x80042170: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_74;
    // 0x80042170: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_74:
    // 0x80042174: jal         0x800B1844
    // 0x80042178: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800B1844(rdram, ctx);
        goto after_75;
    // 0x80042178: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_75:
    // 0x8004217C: addiu       $t8, $sp, 0x6C
    ctx->r24 = ADD32(ctx->r29, 0X6C);
    // 0x80042180: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80042184: nop

    // 0x80042188: swc1        $f18, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
    // 0x8004218C: addiu       $t9, $sp, 0x6C
    ctx->r25 = ADD32(ctx->r29, 0X6C);
    // 0x80042190: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80042194: nop

    // 0x80042198: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    // 0x8004219C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800421A0: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x800421A4: nop

    // 0x800421A8: bne         $t0, $zero, L_80042284
    if (ctx->r8 != 0) {
        // 0x800421AC: nop
    
            goto L_80042284;
    }
    // 0x800421AC: nop

    // 0x800421B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800421B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800421B8: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800421BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800421C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800421C4: lwc1        $f10, -0x73EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x800421C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800421CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800421D0: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800421D4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800421D8: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800421DC: lw          $t1, 0x71FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X71FC);
    // 0x800421E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800421E4: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x800421E8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800421EC: lwc1        $f8, -0x73D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x800421F0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800421F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800421F8: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x800421FC: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x80042200: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80042204: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80042208: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8004220C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80042210: jal         0x800346E4
    // 0x80042214: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800346E4(rdram, ctx);
        goto after_76;
    // 0x80042214: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_76:
    // 0x80042218: sh          $v0, 0xF2($sp)
    MEM_H(0XF2, ctx->r29) = ctx->r2;
    // 0x8004221C: lhu         $t4, 0xF2($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XF2);
    // 0x80042220: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042224: bne         $t4, $at, L_80042284
    if (ctx->r12 != ctx->r1) {
        // 0x80042228: nop
    
            goto L_80042284;
    }
    // 0x80042228: nop

    // 0x8004222C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80042230: lw          $a0, 0x7260($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7260);
    // 0x80042234: jal         0x800BCCE4
    // 0x80042238: nop

    func_800BCCE4(rdram, ctx);
        goto after_77;
    // 0x80042238: nop

    after_77:
    // 0x8004223C: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80042240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80042244: sh          $t5, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r13;
    // 0x80042248: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8004224C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80042250: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042254: swc1        $f18, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f18.u32l;
    // 0x80042258: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8004225C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80042260: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
    // 0x80042264: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80042268: lh          $t7, 0x7254($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7254);
    // 0x8004226C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042270: ori         $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 | 0X8000;
    // 0x80042274: sh          $t8, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r24;
    // 0x80042278: addiu       $t9, $zero, 0x39
    ctx->r25 = ADD32(0, 0X39);
    // 0x8004227C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80042280: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
L_80042284:
    // 0x80042284: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80042288: lhu         $t0, 0x6C0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X6C0);
    // 0x8004228C: nop

    // 0x80042290: sltiu       $at, $t0, 0xC
    ctx->r1 = ctx->r8 < 0XC ? 1 : 0;
    // 0x80042294: beq         $at, $zero, L_80042500
    if (ctx->r1 == 0) {
        // 0x80042298: nop
    
            goto L_80042500;
    }
    // 0x80042298: nop

    // 0x8004229C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800422A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800422A4: addu        $at, $at, $t0
    gpr jr_addend_800422B0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800422A8: lw          $t0, -0x12D0($at)
    ctx->r8 = ADD32(ctx->r1, -0X12D0);
    // 0x800422AC: nop

    // 0x800422B0: jr          $t0
    // 0x800422B4: nop

    switch (jr_addend_800422B0 >> 2) {
        case 0: goto L_800422B8; break;
        case 1: goto L_8004230C; break;
        case 2: goto L_80042400; break;
        case 3: goto L_80042500; break;
        case 4: goto L_80042500; break;
        case 5: goto L_80042430; break;
        case 6: goto L_80042500; break;
        case 7: goto L_80042500; break;
        case 8: goto L_80042500; break;
        case 9: goto L_80042500; break;
        case 10: goto L_80042460; break;
        case 11: goto L_80042498; break;
        default: switch_error(__func__, 0x800422B0, 0x800EED30);
    }
    // 0x800422B4: nop

L_800422B8:
    // 0x800422B8: lhu         $t1, 0xF2($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XF2);
    // 0x800422BC: nop

    // 0x800422C0: beq         $t1, $zero, L_80042304
    if (ctx->r9 == 0) {
        // 0x800422C4: nop
    
            goto L_80042304;
    }
    // 0x800422C4: nop

    // 0x800422C8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800422CC: beq         $t1, $at, L_80042304
    if (ctx->r9 == ctx->r1) {
        // 0x800422D0: nop
    
            goto L_80042304;
    }
    // 0x800422D0: nop

    // 0x800422D4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800422D8: lh          $t2, 0x6C0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X6C0);
    // 0x800422DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800422E0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800422E4: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x800422E8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800422EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800422F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800422F4: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
    // 0x800422F8: lhu         $t4, 0xF2($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XF2);
    // 0x800422FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042300: sh          $t4, 0x7236($at)
    MEM_H(0X7236, ctx->r1) = ctx->r12;
L_80042304:
    // 0x80042304: b           L_80042500
    // 0x80042308: nop

        goto L_80042500;
    // 0x80042308: nop

L_8004230C:
    // 0x8004230C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042310: lwc1        $f4, 0x720C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x80042314: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80042318: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004231C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042320: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80042324: swc1        $f8, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f8.u32l;
    // 0x80042328: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004232C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80042330: nop

    // 0x80042334: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80042338: nop

    // 0x8004233C: bc1f        L_800423F8
    if (!c1cs) {
        // 0x80042340: nop
    
            goto L_800423F8;
    }
    // 0x80042340: nop

    // 0x80042344: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042348: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004234C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042350: swc1        $f18, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f18.u32l;
    // 0x80042354: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80042358: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004235C: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
    // 0x80042360: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80042364: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80042368: sh          $t5, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r13;
    // 0x8004236C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80042370: lw          $a1, 0x724C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X724C);
    // 0x80042374: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80042378: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004237C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80042380: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80042384: ori         $a2, $a2, 0x49
    ctx->r6 = ctx->r6 | 0X49;
    // 0x80042388: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8004238C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80042390: addiu       $a1, $a1, 0x168
    ctx->r5 = ADD32(ctx->r5, 0X168);
    // 0x80042394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80042398: jal         0x800B1F0C
    // 0x8004239C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_78;
    // 0x8004239C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_78:
    // 0x800423A0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800423A4: lh          $t6, 0x7268($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7268);
    // 0x800423A8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800423AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800423B0: lbu         $t8, 0x7256($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7256);
    // 0x800423B4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800423B8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800423BC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800423C0: addiu       $t0, $t9, -0xA
    ctx->r8 = ADD32(ctx->r25, -0XA);
    // 0x800423C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800423C8: sw          $t0, 0x1358($at)
    MEM_W(0X1358, ctx->r1) = ctx->r8;
    // 0x800423CC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800423D0: lbu         $t1, 0x7256($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7256);
    // 0x800423D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800423D8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800423DC: sb          $t2, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = ctx->r10;
    // 0x800423E0: addiu       $t3, $zero, -0x7FF6
    ctx->r11 = ADD32(0, -0X7FF6);
    // 0x800423E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800423E8: sh          $t3, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r11;
    // 0x800423EC: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x800423F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800423F4: sh          $t4, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r12;
L_800423F8:
    // 0x800423F8: b           L_80042500
    // 0x800423FC: nop

        goto L_80042500;
    // 0x800423FC: nop

L_80042400:
    // 0x80042400: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042404: lwc1        $f8, 0x720C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x80042408: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004240C: lwc1        $f19, -0x12A0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X12A0);
    // 0x80042410: lwc1        $f18, -0x129C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X129C);
    // 0x80042414: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80042418: add.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d + ctx->f18.d;
    // 0x8004241C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042420: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80042424: swc1        $f4, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f4.u32l;
    // 0x80042428: b           L_80042500
    // 0x8004242C: nop

        goto L_80042500;
    // 0x8004242C: nop

L_80042430:
    // 0x80042430: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042434: lwc1        $f6, 0x720C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x80042438: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004243C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80042440: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80042444: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80042448: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8004244C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042450: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80042454: swc1        $f16, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f16.u32l;
    // 0x80042458: b           L_80042500
    // 0x8004245C: nop

        goto L_80042500;
    // 0x8004245C: nop

L_80042460:
    // 0x80042460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80042464: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80042468: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004246C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80042470: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80042474: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80042478: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004247C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80042480: lwc1        $f18, -0x73E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X73E0);
    // 0x80042484: nop

    // 0x80042488: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8004248C: add.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d + ctx->f10.d;
    // 0x80042490: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80042494: swc1        $f6, -0x73E0($at)
    MEM_W(-0X73E0, ctx->r1) = ctx->f6.u32l;
L_80042498:
    // 0x80042498: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004249C: lwc1        $f8, 0x7324($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x800424A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800424A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800424A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800424AC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800424B0: swc1        $f16, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f16.u32l;
    // 0x800424B4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800424B8: lw          $t5, 0x7260($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7260);
    // 0x800424BC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800424C0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800424C4: nop

    // 0x800424C8: addiu       $t7, $t6, -0xA
    ctx->r15 = ADD32(ctx->r14, -0XA);
    // 0x800424CC: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800424D0: lw          $t8, 0x7260($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7260);
    // 0x800424D4: nop

    // 0x800424D8: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800424DC: nop

    // 0x800424E0: bne         $t9, $zero, L_800424F8
    if (ctx->r25 != 0) {
        // 0x800424E4: nop
    
            goto L_800424F8;
    }
    // 0x800424E4: nop

    // 0x800424E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800424EC: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x800424F0: jal         0x800220F4
    // 0x800424F4: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800220F4(rdram, ctx);
        goto after_79;
    // 0x800424F4: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_79:
L_800424F8:
    // 0x800424F8: b           L_80042500
    // 0x800424FC: nop

        goto L_80042500;
    // 0x800424FC: nop

L_80042500:
    // 0x80042500: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042504: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80042508: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8004250C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80042510: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80042514: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80042518: nop

    // 0x8004251C: bc1t        L_80042678
    if (c1cs) {
        // 0x80042520: nop
    
            goto L_80042678;
    }
    // 0x80042520: nop

    // 0x80042524: lhu         $t0, 0xF2($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XF2);
    // 0x80042528: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8004252C: bne         $t0, $at, L_80042584
    if (ctx->r8 != ctx->r1) {
        // 0x80042530: nop
    
            goto L_80042584;
    }
    // 0x80042530: nop

    // 0x80042534: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80042538: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004253C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80042540: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80042544: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x80042548: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x8004254C: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80042550: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x80042554: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80042558: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8004255C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80042560: jal         0x800B1F0C
    // 0x80042564: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_80;
    // 0x80042564: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_80:
    // 0x80042568: addiu       $t1, $zero, 0x27
    ctx->r9 = ADD32(0, 0X27);
    // 0x8004256C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042570: sh          $t1, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r9;
    // 0x80042574: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80042578: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004257C: b           L_800425D8
    // 0x80042580: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
        goto L_800425D8;
    // 0x80042580: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
L_80042584:
    // 0x80042584: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80042588: lhu         $t2, 0x70E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X70E0);
    // 0x8004258C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80042590: beq         $t2, $at, L_800425D8
    if (ctx->r10 == ctx->r1) {
        // 0x80042594: nop
    
            goto L_800425D8;
    }
    // 0x80042594: nop

    // 0x80042598: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004259C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800425A0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800425A4: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800425A8: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x800425AC: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x800425B0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800425B4: ori         $a2, $a2, 0x90
    ctx->r6 = ctx->r6 | 0X90;
    // 0x800425B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800425BC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800425C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800425C4: jal         0x800B1F0C
    // 0x800425C8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_81;
    // 0x800425C8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_81:
    // 0x800425CC: addiu       $t3, $zero, 0x90
    ctx->r11 = ADD32(0, 0X90);
    // 0x800425D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800425D4: sh          $t3, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r11;
L_800425D8:
    // 0x800425D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800425DC: lwc1        $f6, 0x50C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x800425E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800425E4: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800425E8: nop

    // 0x800425EC: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800425F0: nop

    // 0x800425F4: bc1f        L_8004261C
    if (!c1cs) {
        // 0x800425F8: nop
    
            goto L_8004261C;
    }
    // 0x800425F8: nop

    // 0x800425FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042600: lwc1        $f18, 0x50C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80042604: nop

    // 0x80042608: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x8004260C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80042610: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042614: b           L_80042638
    // 0x80042618: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
        goto L_80042638;
    // 0x80042618: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
L_8004261C:
    // 0x8004261C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80042620: lwc1        $f20, 0x257C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80042624: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042628: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x8004262C: swc1        $f20, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f20.u32l;
    // 0x80042630: sub.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x80042634: swc1        $f4, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f4.u32l;
L_80042638:
    // 0x80042638: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8004263C: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80042640: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80042644: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80042648: lwc1        $f16, -0x73EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X73EC);
    // 0x8004264C: nop

    // 0x80042650: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80042654: swc1        $f10, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f10.u32l;
    // 0x80042658: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8004265C: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80042660: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80042664: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80042668: lwc1        $f16, -0x73D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8004266C: nop

    // 0x80042670: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80042674: swc1        $f18, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f18.u32l;
L_80042678:
    // 0x80042678: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004267C: lwc1        $f10, 0x50D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x80042680: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80042684: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80042688: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004268C: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80042690: nop

    // 0x80042694: bc1t        L_80042788
    if (c1cs) {
        // 0x80042698: nop
    
            goto L_80042788;
    }
    // 0x80042698: nop

    // 0x8004269C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800426A0: lhu         $t4, 0x70E0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X70E0);
    // 0x800426A4: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x800426A8: beq         $t4, $at, L_800426F0
    if (ctx->r12 == ctx->r1) {
        // 0x800426AC: nop
    
            goto L_800426F0;
    }
    // 0x800426AC: nop

    // 0x800426B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800426B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800426B8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800426BC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800426C0: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x800426C4: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x800426C8: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800426CC: ori         $a2, $a2, 0x59
    ctx->r6 = ctx->r6 | 0X59;
    // 0x800426D0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800426D4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800426D8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800426DC: jal         0x800B1F0C
    // 0x800426E0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_82;
    // 0x800426E0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_82:
    // 0x800426E4: addiu       $t6, $zero, 0x59
    ctx->r14 = ADD32(0, 0X59);
    // 0x800426E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800426EC: sh          $t6, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r14;
L_800426F0:
    // 0x800426F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800426F4: lwc1        $f18, 0x50D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x800426F8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800426FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80042700: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80042704: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80042708: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8004270C: nop

    // 0x80042710: bc1f        L_80042738
    if (!c1cs) {
        // 0x80042714: nop
    
            goto L_80042738;
    }
    // 0x80042714: nop

    // 0x80042718: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004271C: lwc1        $f6, 0x50D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x80042720: nop

    // 0x80042724: swc1        $f6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f6.u32l;
    // 0x80042728: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004272C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042730: b           L_80042770
    // 0x80042734: swc1        $f16, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f16.u32l;
        goto L_80042770;
    // 0x80042734: swc1        $f16, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f16.u32l;
L_80042738:
    // 0x80042738: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004273C: lwc1        $f8, 0x50D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x80042740: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80042744: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80042748: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004274C: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80042750: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80042754: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042758: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004275C: swc1        $f6, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f6.u32l;
    // 0x80042760: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80042764: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80042768: nop

    // 0x8004276C: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
L_80042770:
    // 0x80042770: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042774: lwc1        $f8, 0x7324($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80042778: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8004277C: nop

    // 0x80042780: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80042784: swc1        $f10, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f10.u32l;
L_80042788:
    // 0x80042788: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004278C: lwc1        $f4, 0x50D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80042790: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80042794: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80042798: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004279C: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x800427A0: nop

    // 0x800427A4: bc1t        L_8004289C
    if (c1cs) {
        // 0x800427A8: nop
    
            goto L_8004289C;
    }
    // 0x800427A8: nop

    // 0x800427AC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800427B0: lhu         $t7, 0x70E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X70E0);
    // 0x800427B4: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x800427B8: beq         $t7, $at, L_80042804
    if (ctx->r15 == ctx->r1) {
        // 0x800427BC: nop
    
            goto L_80042804;
    }
    // 0x800427BC: nop

    // 0x800427C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800427C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800427C8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800427CC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800427D0: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x800427D4: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x800427D8: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800427DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800427E0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800427E4: ori         $a2, $a2, 0x59
    ctx->r6 = ctx->r6 | 0X59;
    // 0x800427E8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800427EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800427F0: jal         0x800B1F0C
    // 0x800427F4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_83;
    // 0x800427F4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_83:
    // 0x800427F8: addiu       $t8, $zero, 0x59
    ctx->r24 = ADD32(0, 0X59);
    // 0x800427FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042800: sh          $t8, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r24;
L_80042804:
    // 0x80042804: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042808: lwc1        $f10, 0x50D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x8004280C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80042810: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80042814: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80042818: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004281C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80042820: nop

    // 0x80042824: bc1f        L_8004284C
    if (!c1cs) {
        // 0x80042828: nop
    
            goto L_8004284C;
    }
    // 0x80042828: nop

    // 0x8004282C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042830: lwc1        $f16, 0x50D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80042834: nop

    // 0x80042838: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
    // 0x8004283C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80042840: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042844: b           L_80042884
    // 0x80042848: swc1        $f8, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f8.u32l;
        goto L_80042884;
    // 0x80042848: swc1        $f8, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f8.u32l;
L_8004284C:
    // 0x8004284C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042850: lwc1        $f18, 0x50D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80042854: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80042858: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004285C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80042860: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80042864: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x80042868: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004286C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80042870: swc1        $f16, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f16.u32l;
    // 0x80042874: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80042878: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004287C: nop

    // 0x80042880: swc1        $f8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f8.u32l;
L_80042884:
    // 0x80042884: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042888: lwc1        $f18, 0x7324($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x8004288C: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042890: nop

    // 0x80042894: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80042898: swc1        $f4, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f4.u32l;
L_8004289C:
    // 0x8004289C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800428A0: lwc1        $f6, 0x7324($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x800428A4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800428A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800428AC: nop

    // 0x800428B0: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x800428B4: nop

    // 0x800428B8: bc1f        L_800428E0
    if (!c1cs) {
        // 0x800428BC: nop
    
            goto L_800428E0;
    }
    // 0x800428BC: nop

    // 0x800428C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800428C4: lwc1        $f8, 0x7324($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x800428C8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800428CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800428D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800428D4: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800428D8: b           L_8004291C
    // 0x800428DC: swc1        $f10, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f10.u32l;
        goto L_8004291C;
    // 0x800428DC: swc1        $f10, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f10.u32l;
L_800428E0:
    // 0x800428E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800428E4: lwc1        $f4, 0x7324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x800428E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800428EC: nop

    // 0x800428F0: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x800428F4: nop

    // 0x800428F8: bc1f        L_8004291C
    if (!c1cs) {
        // 0x800428FC: nop
    
            goto L_8004291C;
    }
    // 0x800428FC: nop

    // 0x80042900: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042904: lwc1        $f16, 0x7324($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80042908: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8004290C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80042910: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042914: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80042918: swc1        $f18, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f18.u32l;
L_8004291C:
    // 0x8004291C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80042920: lh          $t9, 0x6C0($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X6C0);
    // 0x80042924: nop

    // 0x80042928: beq         $t9, $zero, L_80042940
    if (ctx->r25 == 0) {
        // 0x8004292C: nop
    
            goto L_80042940;
    }
    // 0x8004292C: nop

    // 0x80042930: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80042934: nop

    // 0x80042938: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    // 0x8004293C: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_80042940:
    // 0x80042940: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042944: lwc1        $f4, 0x50D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x80042948: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004294C: lwc1        $f6, 0x50D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80042950: nop

    // 0x80042954: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80042958: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
    // 0x8004295C: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042960: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80042964: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80042968: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8004296C: c.eq.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d == ctx->f10.d;
    // 0x80042970: nop

    // 0x80042974: bc1f        L_800429FC
    if (!c1cs) {
        // 0x80042978: nop
    
            goto L_800429FC;
    }
    // 0x80042978: nop

    // 0x8004297C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042980: lwc1        $f4, 0x50C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80042984: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80042988: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004298C: nop

    // 0x80042990: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80042994: nop

    // 0x80042998: bc1f        L_800429FC
    if (!c1cs) {
        // 0x8004299C: nop
    
            goto L_800429FC;
    }
    // 0x8004299C: nop

    // 0x800429A0: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800429A4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800429A8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800429AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800429B0: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x800429B4: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x800429B8: nop

    // 0x800429BC: bc1f        L_800429FC
    if (!c1cs) {
        // 0x800429C0: nop
    
            goto L_800429FC;
    }
    // 0x800429C0: nop

    // 0x800429C4: lhu         $t0, 0xF2($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XF2);
    // 0x800429C8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800429CC: beq         $t0, $at, L_800429FC
    if (ctx->r8 == ctx->r1) {
        // 0x800429D0: nop
    
            goto L_800429FC;
    }
    // 0x800429D0: nop

    // 0x800429D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800429D8: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x800429DC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800429E0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800429E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800429E8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800429EC: add.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f4.d + ctx->f6.d;
    // 0x800429F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800429F4: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x800429F8: swc1        $f8, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f8.u32l;
L_800429FC:
    // 0x800429FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042A00: lwc1        $f10, 0x50C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X50C8);
    // 0x80042A04: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042A08: nop

    // 0x80042A0C: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80042A10: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
    // 0x80042A14: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042A18: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80042A1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80042A20: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80042A24: c.eq.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d == ctx->f8.d;
    // 0x80042A28: nop

    // 0x80042A2C: bc1f        L_80042AF4
    if (!c1cs) {
        // 0x80042A30: nop
    
            goto L_80042AF4;
    }
    // 0x80042A30: nop

    // 0x80042A34: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80042A38: lhu         $t1, 0x70E0($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X70E0);
    // 0x80042A3C: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80042A40: beq         $t1, $at, L_80042AF4
    if (ctx->r9 == ctx->r1) {
        // 0x80042A44: nop
    
            goto L_80042AF4;
    }
    // 0x80042A44: nop

    // 0x80042A48: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80042A4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80042A50: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80042A54: nop

    // 0x80042A58: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80042A5C: nop

    // 0x80042A60: bc1f        L_80042AF4
    if (!c1cs) {
        // 0x80042A64: nop
    
            goto L_80042AF4;
    }
    // 0x80042A64: nop

    // 0x80042A68: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80042A6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80042A70: nop

    // 0x80042A74: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80042A78: nop

    // 0x80042A7C: bc1f        L_80042A8C
    if (!c1cs) {
        // 0x80042A80: nop
    
            goto L_80042A8C;
    }
    // 0x80042A80: nop

    // 0x80042A84: b           L_80042A98
    // 0x80042A88: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
        goto L_80042A98;
    // 0x80042A88: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_80042A8C:
    // 0x80042A8C: lwc1        $f20, 0xE8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80042A90: nop

    // 0x80042A94: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80042A98:
    // 0x80042A98: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80042A9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80042AA0: nop

    // 0x80042AA4: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x80042AA8: nop

    // 0x80042AAC: bc1f        L_80042AF4
    if (!c1cs) {
        // 0x80042AB0: nop
    
            goto L_80042AF4;
    }
    // 0x80042AB0: nop

    // 0x80042AB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80042AB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80042ABC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80042AC0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80042AC4: lw          $a1, -0x73B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73B4);
    // 0x80042AC8: lw          $a0, -0x73B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73B8);
    // 0x80042ACC: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80042AD0: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x80042AD4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80042AD8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80042ADC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80042AE0: jal         0x800B1F0C
    // 0x80042AE4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_84;
    // 0x80042AE4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_84:
    // 0x80042AE8: addiu       $t2, $zero, 0x27
    ctx->r10 = ADD32(0, 0X27);
    // 0x80042AEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042AF0: sh          $t2, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r10;
L_80042AF4:
    // 0x80042AF4: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042AF8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80042AFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80042B00: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80042B04: c.eq.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d == ctx->f4.d;
    // 0x80042B08: nop

    // 0x80042B0C: bc1f        L_80042B64
    if (!c1cs) {
        // 0x80042B10: nop
    
            goto L_80042B64;
    }
    // 0x80042B10: nop

    // 0x80042B14: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80042B18: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80042B1C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80042B20: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80042B24: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80042B28: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x80042B2C: nop

    // 0x80042B30: bc1f        L_80042B64
    if (!c1cs) {
        // 0x80042B34: nop
    
            goto L_80042B64;
    }
    // 0x80042B34: nop

    // 0x80042B38: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80042B3C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80042B40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042B44: swc1        $f22, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f22.u32l;
    // 0x80042B48: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80042B4C: lwc1        $f10, -0x3A80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x80042B50: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042B54: add.s       $f20, $f10, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x80042B58: add.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80042B5C: swc1        $f20, -0x3A80($at)
    MEM_W(-0X3A80, ctx->r1) = ctx->f20.u32l;
    // 0x80042B60: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
L_80042B64:
    // 0x80042B64: lwc1        $f16, 0xE0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042B68: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80042B6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80042B70: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80042B74: c.eq.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d == ctx->f18.d;
    // 0x80042B78: nop

    // 0x80042B7C: bc1f        L_80042BD4
    if (!c1cs) {
        // 0x80042B80: nop
    
            goto L_80042BD4;
    }
    // 0x80042B80: nop

    // 0x80042B84: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80042B88: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80042B8C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80042B90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80042B94: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80042B98: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80042B9C: nop

    // 0x80042BA0: bc1f        L_80042BD4
    if (!c1cs) {
        // 0x80042BA4: nop
    
            goto L_80042BD4;
    }
    // 0x80042BA4: nop

    // 0x80042BA8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80042BAC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80042BB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042BB4: swc1        $f22, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f22.u32l;
    // 0x80042BB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80042BBC: lwc1        $f16, -0x3A7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x80042BC0: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042BC4: add.s       $f20, $f16, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80042BC8: add.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80042BCC: swc1        $f20, -0x3A7C($at)
    MEM_W(-0X3A7C, ctx->r1) = ctx->f20.u32l;
    // 0x80042BD0: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
L_80042BD4:
    // 0x80042BD4: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80042BD8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80042BDC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80042BE0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80042BE4: c.eq.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d == ctx->f4.d;
    // 0x80042BE8: nop

    // 0x80042BEC: bc1f        L_80042C28
    if (!c1cs) {
        // 0x80042BF0: nop
    
            goto L_80042C28;
    }
    // 0x80042BF0: nop

    // 0x80042BF4: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80042BF8: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80042BFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80042C00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80042C04: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80042C08: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x80042C0C: nop

    // 0x80042C10: bc1f        L_80042C28
    if (!c1cs) {
        // 0x80042C14: nop
    
            goto L_80042C28;
    }
    // 0x80042C14: nop

    // 0x80042C18: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80042C1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80042C20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80042C24: swc1        $f10, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f10.u32l;
L_80042C28:
    // 0x80042C28: jal         0x800C1A28
    // 0x80042C2C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_85;
    // 0x80042C2C: nop

    after_85:
    // 0x80042C30: b           L_80042C38
    // 0x80042C34: nop

        goto L_80042C38;
    // 0x80042C34: nop

L_80042C38:
    // 0x80042C38: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80042C3C: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80042C40: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80042C44: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80042C48: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80042C4C: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80042C50: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80042C54: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80042C58: jr          $ra
    // 0x80042C5C: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80042C5C: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80067514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006751C: jal         0x80061488
    // 0x80067520: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067520: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80067524: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80067528: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006752C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067530: beq         $v0, $zero, L_80067548
    if (ctx->r2 == 0) {
        // 0x80067534: nop
    
            goto L_80067548;
    }
    // 0x80067534: nop

    // 0x80067538: jal         0x80061348
    // 0x8006753C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006753C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_1:
    // 0x80067540: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80067544: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80067548:
    // 0x80067548: b           L_80067558
    // 0x8006754C: nop

        goto L_80067558;
    // 0x8006754C: nop

    // 0x80067550: b           L_80067558
    // 0x80067554: nop

        goto L_80067558;
    // 0x80067554: nop

L_80067558:
    // 0x80067558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006755C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067560: jr          $ra
    // 0x80067564: nop

    return;
    // 0x80067564: nop

;}
RECOMP_FUNC void func_800B7678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7678: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B767C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7680: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B7684: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800B7688:
    // 0x800B7688: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B768C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B7690: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7694: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7698: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B769C: sh          $t7, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r15;
    // 0x800B76A0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B76A4: nop

    // 0x800B76A8: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B76AC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B76B0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B76B4: nop

    // 0x800B76B8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B76BC: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800B76C0: bne         $at, $zero, L_800B7688
    if (ctx->r1 != 0) {
        // 0x800B76C4: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800B7688;
    }
    // 0x800B76C4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800B76C8: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x800B76CC: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x800B76D0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B76D4: bne         $t6, $at, L_800B76E8
    if (ctx->r14 != ctx->r1) {
        // 0x800B76D8: nop
    
            goto L_800B76E8;
    }
    // 0x800B76D8: nop

    // 0x800B76DC: addiu       $t8, $zero, 0x7FFF
    ctx->r24 = ADD32(0, 0X7FFF);
    // 0x800B76E0: b           L_800B76F8
    // 0x800B76E4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_800B76F8;
    // 0x800B76E4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_800B76E8:
    // 0x800B76E8: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800B76EC: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800B76F0: nop

    // 0x800B76F4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800B76F8:
    // 0x800B76F8: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x800B76FC: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x800B7700: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B7704: bne         $t1, $at, L_800B7718
    if (ctx->r9 != ctx->r1) {
        // 0x800B7708: nop
    
            goto L_800B7718;
    }
    // 0x800B7708: nop

    // 0x800B770C: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800B7710: b           L_800B7728
    // 0x800B7714: sb          $t2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r10;
        goto L_800B7728;
    // 0x800B7714: sb          $t2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r10;
L_800B7718:
    // 0x800B7718: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x800B771C: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x800B7720: nop

    // 0x800B7724: sb          $t4, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r12;
L_800B7728:
    // 0x800B7728: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B772C: nop

    // 0x800B7730: bne         $t5, $zero, L_800B7750
    if (ctx->r13 != 0) {
        // 0x800B7734: nop
    
            goto L_800B7750;
    }
    // 0x800B7734: nop

    // 0x800B7738: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800B773C: lhu         $a0, 0x2($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X2);
    // 0x800B7740: jal         0x800220F4
    // 0x800B7744: nop

    func_800220F4(rdram, ctx);
        goto after_0;
    // 0x800B7744: nop

    after_0:
    // 0x800B7748: b           L_800B7768
    // 0x800B774C: nop

        goto L_800B7768;
    // 0x800B774C: nop

L_800B7750:
    // 0x800B7750: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800B7754: lhu         $a0, 0x2($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X2);
    // 0x800B7758: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B775C: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    // 0x800B7760: jal         0x8002206C
    // 0x800B7764: nop

    func_8002206C(rdram, ctx);
        goto after_1;
    // 0x800B7764: nop

    after_1:
L_800B7768:
    // 0x800B7768: b           L_800B7778
    // 0x800B776C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B7778;
    // 0x800B776C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800B7770: b           L_800B7778
    // 0x800B7774: nop

        goto L_800B7778;
    // 0x800B7774: nop

L_800B7778:
    // 0x800B7778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B777C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B7780: jr          $ra
    // 0x800B7784: nop

    return;
    // 0x800B7784: nop

;}
RECOMP_FUNC void func_800685AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800685B0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800685B4: nop

    // 0x800685B8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800685BC: nop

    // 0x800685C0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800685C4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800685C8: jr          $ra
    // 0x800685CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800685CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800685D0: jr          $ra
    // 0x800685D4: nop

    return;
    // 0x800685D4: nop

    // 0x800685D8: jr          $ra
    // 0x800685DC: nop

    return;
    // 0x800685DC: nop

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
RECOMP_FUNC void func_8006C450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C458: jal         0x8005F064
    // 0x8006C45C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C45C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_0:
    // 0x8006C460: b           L_8006C470
    // 0x8006C464: nop

        goto L_8006C470;
    // 0x8006C464: nop

    // 0x8006C468: b           L_8006C470
    // 0x8006C46C: nop

        goto L_8006C470;
    // 0x8006C46C: nop

L_8006C470:
    // 0x8006C470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C478: jr          $ra
    // 0x8006C47C: nop

    return;
    // 0x8006C47C: nop

;}
RECOMP_FUNC void func_800AC254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC254: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800AC258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC25C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AC260: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC264: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC268: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC26C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AC270: nop

    // 0x800AC274: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AC278: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC27C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC280: nop

    // 0x800AC284: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AC288: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800AC28C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AC290: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800AC294: nop

    // 0x800AC298: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800AC29C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC2A0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800AC2A4: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC2A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AC2AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AC2B0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AC2B4: nop

    // 0x800AC2B8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800AC2BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC2C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC2C4: nop

    // 0x800AC2C8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC2CC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800AC2D0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AC2D4: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800AC2D8: nop

    // 0x800AC2DC: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800AC2E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC2E4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800AC2E8: lwc1        $f4, 0x7230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC2EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AC2F0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800AC2F4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AC2F8: nop

    // 0x800AC2FC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AC300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC308: nop

    // 0x800AC30C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC310: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800AC314: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AC318: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800AC31C: nop

    // 0x800AC320: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC324: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC328: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AC32C: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC330: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC334: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AC338: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC33C: nop

    // 0x800AC340: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC344: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC348: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC34C: nop

    // 0x800AC350: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC354: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800AC358: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC35C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800AC360: nop

    // 0x800AC364: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800AC368: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC36C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800AC370: lwc1        $f16, 0x6190($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC374: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AC378: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800AC37C: nop

    // 0x800AC380: bc1f        L_800AC3B8
    if (!c1cs) {
        // 0x800AC384: nop
    
            goto L_800AC3B8;
    }
    // 0x800AC384: nop

    // 0x800AC388: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AC38C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC390: lwc1        $f18, 0x6190($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC394: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AC398: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC39C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC3A0: nop

    // 0x800AC3A4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AC3A8: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800AC3AC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AC3B0: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800AC3B4: nop

L_800AC3B8:
    // 0x800AC3B8: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800AC3BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC3C0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800AC3C4: lwc1        $f10, 0x6194($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC3C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AC3CC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800AC3D0: nop

    // 0x800AC3D4: bc1f        L_800AC40C
    if (!c1cs) {
        // 0x800AC3D8: nop
    
            goto L_800AC40C;
    }
    // 0x800AC3D8: nop

    // 0x800AC3DC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AC3E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC3E4: lwc1        $f16, 0x6194($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC3E8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AC3EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC3F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC3F4: nop

    // 0x800AC3F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AC3FC: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800AC400: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AC404: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800AC408: nop

L_800AC40C:
    // 0x800AC40C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800AC410: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC414: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800AC418: lwc1        $f8, 0x6198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC41C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC420: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800AC424: nop

    // 0x800AC428: bc1f        L_800AC460
    if (!c1cs) {
        // 0x800AC42C: nop
    
            goto L_800AC460;
    }
    // 0x800AC42C: nop

    // 0x800AC430: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AC434: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC438: lwc1        $f10, 0x6198($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC43C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AC440: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC444: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC448: nop

    // 0x800AC44C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AC450: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800AC454: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AC458: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AC45C: nop

L_800AC460:
    // 0x800AC460: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800AC464: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC468: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800AC46C: lwc1        $f6, 0x619C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC470: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AC474: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800AC478: nop

    // 0x800AC47C: bc1f        L_800AC4B4
    if (!c1cs) {
        // 0x800AC480: nop
    
            goto L_800AC4B4;
    }
    // 0x800AC480: nop

    // 0x800AC484: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AC488: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC48C: lwc1        $f8, 0x619C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC490: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AC494: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC498: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC49C: nop

    // 0x800AC4A0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC4A4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AC4A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AC4AC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800AC4B0: nop

L_800AC4B4:
    // 0x800AC4B4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800AC4B8: nop

    // 0x800AC4BC: bgez        $t0, L_800AC4C8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AC4C0: nop
    
            goto L_800AC4C8;
    }
    // 0x800AC4C0: nop

    // 0x800AC4C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800AC4C8:
    // 0x800AC4C8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800AC4CC: nop

    // 0x800AC4D0: slti        $at, $t1, 0x141
    ctx->r1 = SIGNED(ctx->r9) < 0X141 ? 1 : 0;
    // 0x800AC4D4: bne         $at, $zero, L_800AC4E4
    if (ctx->r1 != 0) {
        // 0x800AC4D8: nop
    
            goto L_800AC4E4;
    }
    // 0x800AC4D8: nop

    // 0x800AC4DC: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x800AC4E0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_800AC4E4:
    // 0x800AC4E4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800AC4E8: nop

    // 0x800AC4EC: bgez        $t3, L_800AC4F8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AC4F0: nop
    
            goto L_800AC4F8;
    }
    // 0x800AC4F0: nop

    // 0x800AC4F4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800AC4F8:
    // 0x800AC4F8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800AC4FC: nop

    // 0x800AC500: slti        $at, $t4, 0xF1
    ctx->r1 = SIGNED(ctx->r12) < 0XF1 ? 1 : 0;
    // 0x800AC504: bne         $at, $zero, L_800AC514
    if (ctx->r1 != 0) {
        // 0x800AC508: nop
    
            goto L_800AC514;
    }
    // 0x800AC508: nop

    // 0x800AC50C: addiu       $t5, $zero, 0xF0
    ctx->r13 = ADD32(0, 0XF0);
    // 0x800AC510: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_800AC514:
    // 0x800AC514: jr          $ra
    // 0x800AC518: nop

    return;
    // 0x800AC518: nop

    // 0x800AC51C: jr          $ra
    // 0x800AC520: nop

    return;
    // 0x800AC520: nop

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
    // 0x800886E4: lhu         $a2, 0x1E($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X1E);
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
    // 0x80088724: lhu         $a2, 0x20($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X20);
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
    // 0x80088768: lhu         $a2, 0x22($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X22);
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
RECOMP_FUNC void func_8001C5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C5E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C5E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C5E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001C5EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001C5F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C5F4: nop

    // 0x8001C5F8: bltz        $t6, L_8001C81C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001C5FC: nop
    
            goto L_8001C81C;
    }
    // 0x8001C5FC: nop

    // 0x8001C600: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C604: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C608: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C60C: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001C610: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001C614: nop

    // 0x8001C618: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C61C: beq         $t0, $zero, L_8001C638
    if (ctx->r8 == 0) {
        // 0x8001C620: nop
    
            goto L_8001C638;
    }
    // 0x8001C620: nop

    // 0x8001C624: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001C628: lh          $t1, -0x73C0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X73C0);
    // 0x8001C62C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C630: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001C634: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
L_8001C638:
    // 0x8001C638: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C63C: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C640: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C644: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001C648: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001C64C: nop

    // 0x8001C650: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C654: beq         $t6, $zero, L_8001C670
    if (ctx->r14 == 0) {
        // 0x8001C658: nop
    
            goto L_8001C670;
    }
    // 0x8001C658: nop

    // 0x8001C65C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8001C660: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8001C664: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C668: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001C66C: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
L_8001C670:
    // 0x8001C670: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001C674: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001C678: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001C67C: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001C680: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001C684: nop

    // 0x8001C688: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001C68C: beq         $t2, $zero, L_8001C6A8
    if (ctx->r10 == 0) {
        // 0x8001C690: nop
    
            goto L_8001C6A8;
    }
    // 0x8001C690: nop

    // 0x8001C694: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001C698: lh          $t3, -0x73C0($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X73C0);
    // 0x8001C69C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C6A0: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x8001C6A4: sh          $t4, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r12;
L_8001C6A8:
    // 0x8001C6A8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001C6AC: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001C6B0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001C6B4: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001C6B8: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001C6BC: nop

    // 0x8001C6C0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001C6C4: beq         $t8, $zero, L_8001C6E0
    if (ctx->r24 == 0) {
        // 0x8001C6C8: nop
    
            goto L_8001C6E0;
    }
    // 0x8001C6C8: nop

    // 0x8001C6CC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001C6D0: lh          $t9, -0x73C0($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X73C0);
    // 0x8001C6D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C6D8: addiu       $t0, $t9, -0xA
    ctx->r8 = ADD32(ctx->r25, -0XA);
    // 0x8001C6DC: sh          $t0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r8;
L_8001C6E0:
    // 0x8001C6E0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001C6E4: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001C6E8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001C6EC: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001C6F0: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001C6F4: nop

    // 0x8001C6F8: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001C6FC: beq         $t4, $zero, L_8001C718
    if (ctx->r12 == 0) {
        // 0x8001C700: nop
    
            goto L_8001C718;
    }
    // 0x8001C700: nop

    // 0x8001C704: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001C708: lh          $t5, -0x73C0($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X73C0);
    // 0x8001C70C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C710: addiu       $t6, $t5, 0x64
    ctx->r14 = ADD32(ctx->r13, 0X64);
    // 0x8001C714: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
L_8001C718:
    // 0x8001C718: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C71C: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C720: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C724: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001C728: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001C72C: nop

    // 0x8001C730: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C734: beq         $t0, $zero, L_8001C750
    if (ctx->r8 == 0) {
        // 0x8001C738: nop
    
            goto L_8001C750;
    }
    // 0x8001C738: nop

    // 0x8001C73C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001C740: lh          $t1, -0x73C0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X73C0);
    // 0x8001C744: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C748: addiu       $t2, $t1, -0x64
    ctx->r10 = ADD32(ctx->r9, -0X64);
    // 0x8001C74C: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
L_8001C750:
    // 0x8001C750: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C754: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C758: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C75C: lhu         $t5, 0x1042($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1042);
    // 0x8001C760: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001C764: nop

    // 0x8001C768: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C76C: beq         $t6, $zero, L_8001C7A4
    if (ctx->r14 == 0) {
        // 0x8001C770: nop
    
            goto L_8001C7A4;
    }
    // 0x8001C770: nop

    // 0x8001C774: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8001C778: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8001C77C: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x8001C780: beq         $t7, $at, L_8001C798
    if (ctx->r15 == ctx->r1) {
        // 0x8001C784: nop
    
            goto L_8001C798;
    }
    // 0x8001C784: nop

    // 0x8001C788: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x8001C78C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C790: b           L_8001C7A4
    // 0x8001C794: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
        goto L_8001C7A4;
    // 0x8001C794: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
L_8001C798:
    // 0x8001C798: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x8001C79C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C7A0: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
L_8001C7A4:
    // 0x8001C7A4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001C7A8: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001C7AC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001C7B0: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x8001C7B4: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x8001C7B8: nop

    // 0x8001C7BC: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8001C7C0: beq         $t3, $zero, L_8001C7E0
    if (ctx->r11 == 0) {
        // 0x8001C7C4: nop
    
            goto L_8001C7E0;
    }
    // 0x8001C7C4: nop

    // 0x8001C7C8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001C7CC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001C7D0: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8001C7D4: nop

    // 0x8001C7D8: xori        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 ^ 0X1000;
    // 0x8001C7DC: sh          $t6, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r14;
L_8001C7E0:
    // 0x8001C7E0: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C7E4: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C7E8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C7EC: lhu         $t9, 0xEEC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEEC);
    // 0x8001C7F0: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x8001C7F4: nop

    // 0x8001C7F8: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C7FC: beq         $t0, $zero, L_8001C81C
    if (ctx->r8 == 0) {
        // 0x8001C800: nop
    
            goto L_8001C81C;
    }
    // 0x8001C800: nop

    // 0x8001C804: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001C808: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8001C80C: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8001C810: nop

    // 0x8001C814: xori        $t3, $t2, 0x2000
    ctx->r11 = ctx->r10 ^ 0X2000;
    // 0x8001C818: sh          $t3, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r11;
L_8001C81C:
    // 0x8001C81C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001C820: lh          $t5, -0x73C0($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X73C0);
    // 0x8001C824: nop

    // 0x8001C828: slti        $at, $t5, -0x2
    ctx->r1 = SIGNED(ctx->r13) < -0X2 ? 1 : 0;
    // 0x8001C82C: beq         $at, $zero, L_8001C840
    if (ctx->r1 == 0) {
        // 0x8001C830: nop
    
            goto L_8001C840;
    }
    // 0x8001C830: nop

    // 0x8001C834: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x8001C838: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C83C: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
L_8001C840:
    // 0x8001C840: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001C844: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001C848: lhu         $t7, 0x6($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X6);
    // 0x8001C84C: nop

    // 0x8001C850: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x8001C854: beq         $t8, $zero, L_8001C870
    if (ctx->r24 == 0) {
        // 0x8001C858: nop
    
            goto L_8001C870;
    }
    // 0x8001C858: nop

    // 0x8001C85C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001C860: jal         0x8008ECE4
    // 0x8001C864: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001C864: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    after_0:
    // 0x8001C868: b           L_8001C87C
    // 0x8001C86C: nop

        goto L_8001C87C;
    // 0x8001C86C: nop

L_8001C870:
    // 0x8001C870: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001C874: jal         0x8008ECE4
    // 0x8001C878: addiu       $a0, $a0, -0x274C
    ctx->r4 = ADD32(ctx->r4, -0X274C);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001C878: addiu       $a0, $a0, -0x274C
    ctx->r4 = ADD32(ctx->r4, -0X274C);
    after_1:
L_8001C87C:
    // 0x8001C87C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001C880: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8001C884: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8001C888: nop

    // 0x8001C88C: andi        $t2, $t0, 0x1000
    ctx->r10 = ctx->r8 & 0X1000;
    // 0x8001C890: beq         $t2, $zero, L_8001C8B4
    if (ctx->r10 == 0) {
        // 0x8001C894: nop
    
            goto L_8001C8B4;
    }
    // 0x8001C894: nop

    // 0x8001C898: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001C89C: lh          $a1, -0x73C0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73C0);
    // 0x8001C8A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001C8A4: jal         0x8008ECE4
    // 0x8001C8A8: addiu       $a0, $a0, -0x2748
    ctx->r4 = ADD32(ctx->r4, -0X2748);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001C8A8: addiu       $a0, $a0, -0x2748
    ctx->r4 = ADD32(ctx->r4, -0X2748);
    after_2:
    // 0x8001C8AC: b           L_8001C92C
    // 0x8001C8B0: nop

        goto L_8001C92C;
    // 0x8001C8B0: nop

L_8001C8B4:
    // 0x8001C8B4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001C8B8: lh          $t3, -0x73C0($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X73C0);
    // 0x8001C8BC: nop

    // 0x8001C8C0: bltz        $t3, L_8001C8E4
    if (SIGNED(ctx->r11) < 0) {
        // 0x8001C8C4: nop
    
            goto L_8001C8E4;
    }
    // 0x8001C8C4: nop

    // 0x8001C8C8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001C8CC: lh          $a1, -0x73C0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73C0);
    // 0x8001C8D0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001C8D4: jal         0x8008ECE4
    // 0x8001C8D8: addiu       $a0, $a0, -0x2734
    ctx->r4 = ADD32(ctx->r4, -0X2734);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001C8D8: addiu       $a0, $a0, -0x2734
    ctx->r4 = ADD32(ctx->r4, -0X2734);
    after_3:
    // 0x8001C8DC: b           L_8001C92C
    // 0x8001C8E0: nop

        goto L_8001C92C;
    // 0x8001C8E0: nop

L_8001C8E4:
    // 0x8001C8E4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001C8E8: lh          $t1, -0x73C0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X73C0);
    // 0x8001C8EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001C8F0: bne         $t1, $at, L_8001C90C
    if (ctx->r9 != ctx->r1) {
        // 0x8001C8F4: nop
    
            goto L_8001C90C;
    }
    // 0x8001C8F4: nop

    // 0x8001C8F8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001C8FC: jal         0x8008ECE4
    // 0x8001C900: addiu       $a0, $a0, -0x2720
    ctx->r4 = ADD32(ctx->r4, -0X2720);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8001C900: addiu       $a0, $a0, -0x2720
    ctx->r4 = ADD32(ctx->r4, -0X2720);
    after_4:
    // 0x8001C904: b           L_8001C92C
    // 0x8001C908: nop

        goto L_8001C92C;
    // 0x8001C908: nop

L_8001C90C:
    // 0x8001C90C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001C910: lh          $t5, -0x73C0($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X73C0);
    // 0x8001C914: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001C918: bne         $t5, $at, L_8001C92C
    if (ctx->r13 != ctx->r1) {
        // 0x8001C91C: nop
    
            goto L_8001C92C;
    }
    // 0x8001C91C: nop

    // 0x8001C920: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001C924: jal         0x8008ECE4
    // 0x8001C928: addiu       $a0, $a0, -0x270C
    ctx->r4 = ADD32(ctx->r4, -0X270C);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8001C928: addiu       $a0, $a0, -0x270C
    ctx->r4 = ADD32(ctx->r4, -0X270C);
    after_5:
L_8001C92C:
    // 0x8001C92C: b           L_8001C93C
    // 0x8001C930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001C93C;
    // 0x8001C930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001C934: b           L_8001C93C
    // 0x8001C938: nop

        goto L_8001C93C;
    // 0x8001C938: nop

L_8001C93C:
    // 0x8001C93C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C944: jr          $ra
    // 0x8001C948: nop

    return;
    // 0x8001C948: nop

;}
RECOMP_FUNC void func_800763A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800763AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800763B0: nop

    // 0x800763B4: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800763B8: nop

    // 0x800763BC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800763C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800763C4: jr          $ra
    // 0x800763C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800763C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800763CC: jr          $ra
    // 0x800763D0: nop

    return;
    // 0x800763D0: nop

    // 0x800763D4: jr          $ra
    // 0x800763D8: nop

    return;
    // 0x800763D8: nop

;}
RECOMP_FUNC void func_800AC0A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC0A4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800AC0A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC0AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC0B0: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC0B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC0B8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC0BC: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x800AC0C0: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800AC0C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC0C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AC0CC: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC0D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC0D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC0D8: swc1        $f6, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f6.u32l;
    // 0x800AC0DC: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800AC0E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC0E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AC0E8: lwc1        $f16, 0x7230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC0EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC0F0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800AC0F4: swc1        $f18, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f18.u32l;
    // 0x800AC0F8: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800AC0FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC100: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC104: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC108: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC10C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AC110: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
    // 0x800AC114: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC118: lwc1        $f16, 0x6190($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC11C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC120: lwc1        $f18, 0x61C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800AC124: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC128: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC12C: nop

    // 0x800AC130: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC134: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800AC138: nop

    // 0x800AC13C: bc1f        L_800AC160
    if (!c1cs) {
        // 0x800AC140: nop
    
            goto L_800AC160;
    }
    // 0x800AC140: nop

    // 0x800AC144: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC148: lwc1        $f8, 0x61C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800AC14C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC150: lwc1        $f10, 0x7224($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC154: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC158: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AC15C: swc1        $f18, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f18.u32l;
L_800AC160:
    // 0x800AC160: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC164: lwc1        $f4, 0x6194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC168: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC16C: lwc1        $f16, 0x61C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800AC170: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC174: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC178: nop

    // 0x800AC17C: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AC180: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800AC184: nop

    // 0x800AC188: bc1f        L_800AC1AC
    if (!c1cs) {
        // 0x800AC18C: nop
    
            goto L_800AC1AC;
    }
    // 0x800AC18C: nop

    // 0x800AC190: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC194: lwc1        $f10, 0x61C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800AC198: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC19C: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC1A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1A4: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AC1A8: swc1        $f16, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f16.u32l;
L_800AC1AC:
    // 0x800AC1AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1B0: lwc1        $f6, 0x6198($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC1B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1B8: lwc1        $f4, 0x61C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x800AC1BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC1C0: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC1C4: nop

    // 0x800AC1C8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AC1CC: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800AC1D0: nop

    // 0x800AC1D4: bc1f        L_800AC1F8
    if (!c1cs) {
        // 0x800AC1D8: nop
    
            goto L_800AC1F8;
    }
    // 0x800AC1D8: nop

    // 0x800AC1DC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1E0: lwc1        $f18, 0x61C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x800AC1E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC1E8: lwc1        $f16, 0x7224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC1EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1F0: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AC1F4: swc1        $f4, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f4.u32l;
L_800AC1F8:
    // 0x800AC1F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1FC: lwc1        $f8, 0x619C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC200: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC204: lwc1        $f6, 0x61D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800AC208: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC20C: lwc1        $f10, 0x7230($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC210: nop

    // 0x800AC214: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800AC218: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800AC21C: nop

    // 0x800AC220: bc1f        L_800AC244
    if (!c1cs) {
        // 0x800AC224: nop
    
            goto L_800AC244;
    }
    // 0x800AC224: nop

    // 0x800AC228: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC22C: lwc1        $f16, 0x61D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800AC230: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC234: lwc1        $f4, 0x7230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC238: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC23C: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800AC240: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
L_800AC244:
    // 0x800AC244: jr          $ra
    // 0x800AC248: nop

    return;
    // 0x800AC248: nop

    // 0x800AC24C: jr          $ra
    // 0x800AC250: nop

    return;
    // 0x800AC250: nop

;}
RECOMP_FUNC void ObjectCheckDebugMenu_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F800: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8001F804: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001F808: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8001F80C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8001F810: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001F814: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8001F818: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001F81C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8001F820: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001F824: lhu         $t8, 0xE68($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XE68);
    // 0x8001F828: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x8001F82C: nop

    // 0x8001F830: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8001F834: beq         $t9, $zero, L_8001FAAC
    if (ctx->r25 == 0) {
        // 0x8001F838: nop
    
            goto L_8001FAAC;
    }
    // 0x8001F838: nop

    // 0x8001F83C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001F840: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001F844: lw          $s0, 0x14($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X14);
    // 0x8001F848: nop

    // 0x8001F84C: beq         $s0, $zero, L_8001F880
    if (ctx->r16 == 0) {
        // 0x8001F850: nop
    
            goto L_8001F880;
    }
    // 0x8001F850: nop

    // 0x8001F854: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F858: beq         $s0, $at, L_8001F994
    if (ctx->r16 == ctx->r1) {
        // 0x8001F85C: nop
    
            goto L_8001F994;
    }
    // 0x8001F85C: nop

    // 0x8001F860: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001F864: beq         $s0, $at, L_8001F9E8
    if (ctx->r16 == ctx->r1) {
        // 0x8001F868: nop
    
            goto L_8001F9E8;
    }
    // 0x8001F868: nop

    // 0x8001F86C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001F870: beq         $s0, $at, L_8001FA94
    if (ctx->r16 == ctx->r1) {
        // 0x8001F874: nop
    
            goto L_8001FA94;
    }
    // 0x8001F874: nop

    // 0x8001F878: b           L_8001FAAC
    // 0x8001F87C: nop

        goto L_8001FAAC;
    // 0x8001F87C: nop

L_8001F880:
    // 0x8001F880: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F884: addiu       $t1, $t1, 0x2618
    ctx->r9 = ADD32(ctx->r9, 0X2618);
    // 0x8001F888: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001F88C: nop

    // 0x8001F890: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8001F894: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F898: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001F89C: lw          $s0, 0x4($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X4);
    // 0x8001F8A0: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8001F8A4: sll         $t5, $s0, 4
    ctx->r13 = S32(ctx->r16 << 4);
    // 0x8001F8A8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8001F8AC: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8001F8B0: sw          $s0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r16;
    // 0x8001F8B4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8001F8B8: nop

    // 0x8001F8BC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001F8C0: nop

    // 0x8001F8C4: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x8001F8C8: sh          $t9, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r25;
    // 0x8001F8CC: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F8D0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8001F8D4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001F8D8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001F8DC: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x8001F8E0: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x8001F8E4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x8001F8E8: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001F8EC: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8001F8F0: nop

    // 0x8001F8F4: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001F8F8: beq         $at, $zero, L_8001F95C
    if (ctx->r1 == 0) {
        // 0x8001F8FC: nop
    
            goto L_8001F95C;
    }
    // 0x8001F8FC: nop

    // 0x8001F900: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001F904: lhu         $t8, 0x5A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X5A);
    // 0x8001F908: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8001F90C: bne         $t7, $t8, L_8001F95C
    if (ctx->r15 != ctx->r24) {
        // 0x8001F910: nop
    
            goto L_8001F95C;
    }
    // 0x8001F910: nop

L_8001F914:
    // 0x8001F914: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F918: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8001F91C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F920: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8001F924: addiu       $t4, $t2, 0x10
    ctx->r12 = ADD32(ctx->r10, 0X10);
    // 0x8001F928: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x8001F92C: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x8001F930: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001F934: lw          $t5, 0xC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XC);
    // 0x8001F938: nop

    // 0x8001F93C: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001F940: beq         $at, $zero, L_8001F95C
    if (ctx->r1 == 0) {
        // 0x8001F944: nop
    
            goto L_8001F95C;
    }
    // 0x8001F944: nop

    // 0x8001F948: lw          $t3, 0x0($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X0);
    // 0x8001F94C: lhu         $t7, 0x5A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X5A);
    // 0x8001F950: srl         $t6, $t3, 16
    ctx->r14 = S32(U32(ctx->r11) >> 16);
    // 0x8001F954: beq         $t6, $t7, L_8001F914
    if (ctx->r14 == ctx->r15) {
        // 0x8001F958: nop
    
            goto L_8001F914;
    }
    // 0x8001F958: nop

L_8001F95C:
    // 0x8001F95C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F960: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001F964: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8001F968: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F96C: nop

    // 0x8001F970: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001F974: beq         $at, $zero, L_8001F98C
    if (ctx->r1 == 0) {
        // 0x8001F978: nop
    
            goto L_8001F98C;
    }
    // 0x8001F978: nop

    // 0x8001F97C: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F980: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001F984: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001F988: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
L_8001F98C:
    // 0x8001F98C: b           L_8001FAAC
    // 0x8001F990: nop

        goto L_8001FAAC;
    // 0x8001F990: nop

L_8001F994:
    // 0x8001F994: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F998: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001F99C: lw          $t4, 0x4($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X4);
    // 0x8001F9A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001F9A4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8001F9A8: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x8001F9AC: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001F9B0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001F9B4: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x8001F9B8: nop

    // 0x8001F9BC: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001F9C0: bne         $at, $zero, L_8001F9E0
    if (ctx->r1 != 0) {
        // 0x8001F9C4: nop
    
            goto L_8001F9E0;
    }
    // 0x8001F9C4: nop

    // 0x8001F9C8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001F9CC: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001F9D0: lw          $t2, 0xC($t8)
    ctx->r10 = MEM_W(ctx->r24, 0XC);
    // 0x8001F9D4: nop

    // 0x8001F9D8: addiu       $t1, $t2, -0x1
    ctx->r9 = ADD32(ctx->r10, -0X1);
    // 0x8001F9DC: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
L_8001F9E0:
    // 0x8001F9E0: b           L_8001FAAC
    // 0x8001F9E4: nop

        goto L_8001FAAC;
    // 0x8001F9E4: nop

L_8001F9E8:
    // 0x8001F9E8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001F9EC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001F9F0: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
    // 0x8001F9F4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F9F8: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8001F9FC: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8001FA00: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001FA04: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8001FA08: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8001FA0C: nop

    // 0x8001FA10: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001FA14: bne         $at, $zero, L_8001FA34
    if (ctx->r1 != 0) {
        // 0x8001FA18: nop
    
            goto L_8001FA34;
    }
    // 0x8001FA18: nop

    // 0x8001FA1C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001FA20: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001FA24: lw          $t2, 0x10($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X10);
    // 0x8001FA28: nop

    // 0x8001FA2C: addiu       $t1, $t2, -0x1
    ctx->r9 = ADD32(ctx->r10, -0X1);
    // 0x8001FA30: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
L_8001FA34:
    // 0x8001FA34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001FA38: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001FA3C: lw          $t4, 0x1C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X1C);
    // 0x8001FA40: nop

    // 0x8001FA44: blez        $t4, L_8001FA8C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8001FA48: nop
    
            goto L_8001FA8C;
    }
    // 0x8001FA48: nop

    // 0x8001FA4C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001FA50: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x8001FA54: lw          $t0, 0x4($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X4);
    // 0x8001FA58: nop

    // 0x8001FA5C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8001FA60: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001FA64: addiu       $t5, $t5, 0x2618
    ctx->r13 = ADD32(ctx->r13, 0X2618);
    // 0x8001FA68: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8001FA6C: nop

    // 0x8001FA70: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8001FA74: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001FA78: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001FA7C: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x8001FA80: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8001FA84: jal         0x800B3DBC
    // 0x8001FA88: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800B3DBC(rdram, ctx);
        goto after_0;
    // 0x8001FA88: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_0:
L_8001FA8C:
    // 0x8001FA8C: b           L_8001FAAC
    // 0x8001FA90: nop

        goto L_8001FAAC;
    // 0x8001FA90: nop

L_8001FA94:
    // 0x8001FA94: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001FA98: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001FA9C: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x8001FAA0: nop

    // 0x8001FAA4: xori        $t9, $t1, 0x4
    ctx->r25 = ctx->r9 ^ 0X4;
    // 0x8001FAA8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_8001FAAC:
    // 0x8001FAAC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001FAB0: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001FAB4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001FAB8: lhu         $t3, 0xE74($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XE74);
    // 0x8001FABC: lhu         $t4, 0x8($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X8);
    // 0x8001FAC0: nop

    // 0x8001FAC4: and         $t0, $t4, $t3
    ctx->r8 = ctx->r12 & ctx->r11;
    // 0x8001FAC8: beq         $t0, $zero, L_8001FCD8
    if (ctx->r8 == 0) {
        // 0x8001FACC: nop
    
            goto L_8001FCD8;
    }
    // 0x8001FACC: nop

    // 0x8001FAD0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001FAD4: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001FAD8: lw          $s0, 0x14($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X14);
    // 0x8001FADC: nop

    // 0x8001FAE0: beq         $s0, $zero, L_8001FB14
    if (ctx->r16 == 0) {
        // 0x8001FAE4: nop
    
            goto L_8001FB14;
    }
    // 0x8001FAE4: nop

    // 0x8001FAE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FAEC: beq         $s0, $at, L_8001FBE8
    if (ctx->r16 == ctx->r1) {
        // 0x8001FAF0: nop
    
            goto L_8001FBE8;
    }
    // 0x8001FAF0: nop

    // 0x8001FAF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FAF8: beq         $s0, $at, L_8001FC28
    if (ctx->r16 == ctx->r1) {
        // 0x8001FAFC: nop
    
            goto L_8001FC28;
    }
    // 0x8001FAFC: nop

    // 0x8001FB00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001FB04: beq         $s0, $at, L_8001FCC0
    if (ctx->r16 == ctx->r1) {
        // 0x8001FB08: nop
    
            goto L_8001FCC0;
    }
    // 0x8001FB08: nop

    // 0x8001FB0C: b           L_8001FCD8
    // 0x8001FB10: nop

        goto L_8001FCD8;
    // 0x8001FB10: nop

L_8001FB14:
    // 0x8001FB14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001FB18: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x8001FB1C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001FB20: nop

    // 0x8001FB24: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8001FB28: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001FB2C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001FB30: lw          $s0, 0x4($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X4);
    // 0x8001FB34: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8001FB38: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
    // 0x8001FB3C: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x8001FB40: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8001FB44: sw          $s0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r16;
    // 0x8001FB48: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8001FB4C: nop

    // 0x8001FB50: lw          $t3, 0x0($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X0);
    // 0x8001FB54: nop

    // 0x8001FB58: srl         $t0, $t3, 16
    ctx->r8 = S32(U32(ctx->r11) >> 16);
    // 0x8001FB5C: sh          $t0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r8;
    // 0x8001FB60: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8001FB64: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8001FB68: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8001FB6C: addiu       $t1, $t7, -0x10
    ctx->r9 = ADD32(ctx->r15, -0X10);
    // 0x8001FB70: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x8001FB74: bltz        $t6, L_8001FBC0
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001FB78: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_8001FBC0;
    }
    // 0x8001FB78: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8001FB7C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8001FB80: lhu         $t8, 0x5A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X5A);
    // 0x8001FB84: srl         $t2, $t9, 16
    ctx->r10 = S32(U32(ctx->r25) >> 16);
    // 0x8001FB88: bne         $t2, $t8, L_8001FBC0
    if (ctx->r10 != ctx->r24) {
        // 0x8001FB8C: nop
    
            goto L_8001FBC0;
    }
    // 0x8001FB8C: nop

L_8001FB90:
    // 0x8001FB90: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8001FB94: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8001FB98: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x8001FB9C: addiu       $t5, $t0, -0x10
    ctx->r13 = ADD32(ctx->r8, -0X10);
    // 0x8001FBA0: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x8001FBA4: bltz        $t3, L_8001FBC0
    if (SIGNED(ctx->r11) < 0) {
        // 0x8001FBA8: sw          $t3, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r11;
            goto L_8001FBC0;
    }
    // 0x8001FBA8: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8001FBAC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001FBB0: lhu         $t1, 0x5A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X5A);
    // 0x8001FBB4: srl         $t6, $t7, 16
    ctx->r14 = S32(U32(ctx->r15) >> 16);
    // 0x8001FBB8: beq         $t6, $t1, L_8001FB90
    if (ctx->r14 == ctx->r9) {
        // 0x8001FBBC: nop
    
            goto L_8001FB90;
    }
    // 0x8001FBBC: nop

L_8001FBC0:
    // 0x8001FBC0: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8001FBC4: nop

    // 0x8001FBC8: bltz        $t9, L_8001FBE0
    if (SIGNED(ctx->r25) < 0) {
        // 0x8001FBCC: nop
    
            goto L_8001FBE0;
    }
    // 0x8001FBCC: nop

    // 0x8001FBD0: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8001FBD4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001FBD8: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001FBDC: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
L_8001FBE0:
    // 0x8001FBE0: b           L_8001FCD8
    // 0x8001FBE4: nop

        goto L_8001FCD8;
    // 0x8001FBE4: nop

L_8001FBE8:
    // 0x8001FBE8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001FBEC: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001FBF0: lw          $t0, 0x4($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X4);
    // 0x8001FBF4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001FBF8: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x8001FBFC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8001FC00: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001FC04: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8001FC08: nop

    // 0x8001FC0C: bgez        $t7, L_8001FC20
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001FC10: nop
    
            goto L_8001FC20;
    }
    // 0x8001FC10: nop

    // 0x8001FC14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001FC18: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001FC1C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_8001FC20:
    // 0x8001FC20: b           L_8001FCD8
    // 0x8001FC24: nop

        goto L_8001FCD8;
    // 0x8001FC24: nop

L_8001FC28:
    // 0x8001FC28: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001FC2C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001FC30: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x8001FC34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001FC38: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x8001FC3C: sw          $t2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r10;
    // 0x8001FC40: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001FC44: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8001FC48: nop

    // 0x8001FC4C: bgez        $t0, L_8001FC60
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001FC50: nop
    
            goto L_8001FC60;
    }
    // 0x8001FC50: nop

    // 0x8001FC54: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001FC58: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001FC5C: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
L_8001FC60:
    // 0x8001FC60: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001FC64: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001FC68: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x8001FC6C: nop

    // 0x8001FC70: blez        $t5, L_8001FCB8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8001FC74: nop
    
            goto L_8001FCB8;
    }
    // 0x8001FC74: nop

    // 0x8001FC78: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001FC7C: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8001FC80: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x8001FC84: nop

    // 0x8001FC88: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8001FC8C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001FC90: addiu       $t9, $t9, 0x2618
    ctx->r25 = ADD32(ctx->r25, 0X2618);
    // 0x8001FC94: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x8001FC98: nop

    // 0x8001FC9C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8001FCA0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001FCA4: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001FCA8: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x8001FCAC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8001FCB0: jal         0x800B3DBC
    // 0x8001FCB4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800B3DBC(rdram, ctx);
        goto after_1;
    // 0x8001FCB4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_1:
L_8001FCB8:
    // 0x8001FCB8: b           L_8001FCD8
    // 0x8001FCBC: nop

        goto L_8001FCD8;
    // 0x8001FCBC: nop

L_8001FCC0:
    // 0x8001FCC0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001FCC4: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001FCC8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8001FCCC: nop

    // 0x8001FCD0: xori        $t3, $t0, 0x4
    ctx->r11 = ctx->r8 ^ 0X4;
    // 0x8001FCD4: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
L_8001FCD8:
    // 0x8001FCD8: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001FCDC: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8001FCE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001FCE4: lhu         $t7, 0xEEC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XEEC);
    // 0x8001FCE8: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8001FCEC: nop

    // 0x8001FCF0: and         $t6, $t5, $t7
    ctx->r14 = ctx->r13 & ctx->r15;
    // 0x8001FCF4: beq         $t6, $zero, L_8001FD3C
    if (ctx->r14 == 0) {
        // 0x8001FCF8: nop
    
            goto L_8001FD3C;
    }
    // 0x8001FCF8: nop

    // 0x8001FCFC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001FD00: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001FD04: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x8001FD08: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001FD0C: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8001FD10: sw          $t1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r9;
    // 0x8001FD14: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001FD18: lw          $t3, 0x14($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X14);
    // 0x8001FD1C: nop

    // 0x8001FD20: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8001FD24: bne         $at, $zero, L_8001FD3C
    if (ctx->r1 != 0) {
        // 0x8001FD28: nop
    
            goto L_8001FD3C;
    }
    // 0x8001FD28: nop

    // 0x8001FD2C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001FD30: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001FD34: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8001FD38: sw          $t8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r24;
L_8001FD3C:
    // 0x8001FD3C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001FD40: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001FD44: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001FD48: lhu         $t6, 0xEC0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XEC0);
    // 0x8001FD4C: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x8001FD50: nop

    // 0x8001FD54: and         $t2, $t7, $t6
    ctx->r10 = ctx->r15 & ctx->r14;
    // 0x8001FD58: beq         $t2, $zero, L_8001FD98
    if (ctx->r10 == 0) {
        // 0x8001FD5C: nop
    
            goto L_8001FD98;
    }
    // 0x8001FD5C: nop

    // 0x8001FD60: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001FD64: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001FD68: lw          $t9, 0x14($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X14);
    // 0x8001FD6C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001FD70: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8001FD74: sw          $t0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r8;
    // 0x8001FD78: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001FD7C: lw          $t8, 0x14($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X14);
    // 0x8001FD80: nop

    // 0x8001FD84: bgez        $t8, L_8001FD98
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8001FD88: nop
    
            goto L_8001FD98;
    }
    // 0x8001FD88: nop

    // 0x8001FD8C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001FD90: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001FD94: sw          $zero, 0x14($t4)
    MEM_W(0X14, ctx->r12) = 0;
L_8001FD98:
    // 0x8001FD98: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001FD9C: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001FDA0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001FDA4: lhu         $t6, 0xFF4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XFF4);
    // 0x8001FDA8: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x8001FDAC: nop

    // 0x8001FDB0: and         $t2, $t7, $t6
    ctx->r10 = ctx->r15 & ctx->r14;
    // 0x8001FDB4: beq         $t2, $zero, L_8001FEDC
    if (ctx->r10 == 0) {
        // 0x8001FDB8: nop
    
            goto L_8001FEDC;
    }
    // 0x8001FDB8: nop

    // 0x8001FDBC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001FDC0: addiu       $t9, $t9, 0x2618
    ctx->r25 = ADD32(ctx->r25, 0X2618);
    // 0x8001FDC4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8001FDC8: nop

    // 0x8001FDCC: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8001FDD0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001FDD4: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001FDD8: lw          $t8, 0x4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X4);
    // 0x8001FDDC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8001FDE0: sll         $t4, $t8, 4
    ctx->r12 = S32(ctx->r24 << 4);
    // 0x8001FDE4: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8001FDE8: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x8001FDEC: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8001FDF0: nop

    // 0x8001FDF4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001FDF8: nop

    // 0x8001FDFC: srl         $t2, $t6, 16
    ctx->r10 = S32(U32(ctx->r14) >> 16);
    // 0x8001FE00: sh          $t2, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r10;
    // 0x8001FE04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001FE08: addiu       $t9, $t9, 0x2618
    ctx->r25 = ADD32(ctx->r25, 0X2618);
    // 0x8001FE0C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8001FE10: nop

    // 0x8001FE14: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8001FE18: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001FE1C: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x8001FE20: lw          $t8, 0x8($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X8);
    // 0x8001FE24: nop

    // 0x8001FE28: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8001FE2C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001FE30: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001FE34: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8001FE38: nop

    // 0x8001FE3C: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8001FE40: beq         $t5, $zero, L_8001FE54
    if (ctx->r13 == 0) {
        // 0x8001FE44: nop
    
            goto L_8001FE54;
    }
    // 0x8001FE44: nop

    // 0x8001FE48: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8001FE4C: b           L_8001FE58
    // 0x8001FE50: sb          $t7, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r15;
        goto L_8001FE58;
    // 0x8001FE50: sb          $t7, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r15;
L_8001FE54:
    // 0x8001FE54: sb          $zero, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = 0;
L_8001FE58:
    // 0x8001FE58: jal         0x80022124
    // 0x8001FE5C: nop

    func_80022124(rdram, ctx);
        goto after_2;
    // 0x8001FE5C: nop

    after_2:
    // 0x8001FE60: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8001FE64: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8001FE68: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001FE6C: lwc1        $f4, 0xCC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8001FE70: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001FE74: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x8001FE78: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8001FE7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001FE80: lbu         $t0, 0x4B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4B);
    // 0x8001FE84: lwc1        $f6, 0xD0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x8001FE88: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8001FE8C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8001FE90: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8001FE94: jal         0x800B202C
    // 0x8001FE98: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_3;
    // 0x8001FE98: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8001FE9C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001FEA0: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001FEA4: sw          $v0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r2;
    // 0x8001FEA8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001FEAC: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001FEB0: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x8001FEB4: nop

    // 0x8001FEB8: ori         $t4, $t1, 0x2
    ctx->r12 = ctx->r9 | 0X2;
    // 0x8001FEBC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8001FEC0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001FEC4: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001FEC8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001FECC: nop

    // 0x8001FED0: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x8001FED4: b           L_8001FF84
    // 0x8001FED8: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_8001FF84;
    // 0x8001FED8: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_8001FEDC:
    // 0x8001FEDC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001FEE0: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001FEE4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8001FEE8: nop

    // 0x8001FEEC: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8001FEF0: beq         $t0, $zero, L_8001FF84
    if (ctx->r8 == 0) {
        // 0x8001FEF4: nop
    
            goto L_8001FF84;
    }
    // 0x8001FEF4: nop

    // 0x8001FEF8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001FEFC: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x8001FF00: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8001FF04: nop

    // 0x8001FF08: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8001FF0C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001FF10: addiu       $t4, $t4, 0x2618
    ctx->r12 = ADD32(ctx->r12, 0X2618);
    // 0x8001FF14: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x8001FF18: nop

    // 0x8001FF1C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8001FF20: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8001FF24: jal         0x800B2748
    // 0x8001FF28: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800B2748(rdram, ctx);
        goto after_4;
    // 0x8001FF28: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x8001FF2C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8001FF30: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8001FF34: nop

    // 0x8001FF38: bgez        $t7, L_8001FF74
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001FF3C: nop
    
            goto L_8001FF74;
    }
    // 0x8001FF3C: nop

    // 0x8001FF40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001FF44: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001FF48: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x8001FF4C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8001FF50: and         $t2, $t5, $at
    ctx->r10 = ctx->r13 & ctx->r1;
    // 0x8001FF54: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8001FF58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001FF5C: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001FF60: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8001FF64: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001FF68: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8001FF6C: b           L_8001FF84
    // 0x8001FF70: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
        goto L_8001FF84;
    // 0x8001FF70: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
L_8001FF74:
    // 0x8001FF74: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8001FF78: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001FF7C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001FF80: sw          $t1, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r9;
L_8001FF84:
    // 0x8001FF84: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001FF88: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001FF8C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001FF90: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001FF94: lhu         $t7, 0x6($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X6);
    // 0x8001FF98: nop

    // 0x8001FF9C: and         $t2, $t7, $t5
    ctx->r10 = ctx->r15 & ctx->r13;
    // 0x8001FFA0: beq         $t2, $zero, L_80020158
    if (ctx->r10 == 0) {
        // 0x8001FFA4: nop
    
            goto L_80020158;
    }
    // 0x8001FFA4: nop

    // 0x8001FFA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001FFAC: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001FFB0: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8001FFB4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8001FFB8: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8001FFBC: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8001FFC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001FFC4: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001FFC8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8001FFCC: nop

    // 0x8001FFD0: andi        $t4, $t1, 0x1
    ctx->r12 = ctx->r9 & 0X1;
    // 0x8001FFD4: bne         $t4, $zero, L_800200E4
    if (ctx->r12 != 0) {
        // 0x8001FFD8: nop
    
            goto L_800200E4;
    }
    // 0x8001FFD8: nop

    // 0x8001FFDC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001FFE0: addiu       $t8, $t8, 0x2618
    ctx->r24 = ADD32(ctx->r24, 0X2618);
    // 0x8001FFE4: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8001FFE8: nop

    // 0x8001FFEC: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8001FFF0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001FFF4: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001FFF8: lw          $t0, 0x4($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4);
    // 0x8001FFFC: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80020000: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x80020004: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x80020008: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8002000C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80020010: nop

    // 0x80020014: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80020018: nop

    // 0x8002001C: srl         $t4, $t1, 16
    ctx->r12 = S32(U32(ctx->r9) >> 16);
    // 0x80020020: sh          $t4, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r12;
    // 0x80020024: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020028: addiu       $t8, $t8, 0x2618
    ctx->r24 = ADD32(ctx->r24, 0X2618);
    // 0x8002002C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80020030: nop

    // 0x80020034: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80020038: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002003C: addiu       $t2, $t2, 0x2618
    ctx->r10 = ADD32(ctx->r10, 0X2618);
    // 0x80020040: lw          $t0, 0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8);
    // 0x80020044: nop

    // 0x80020048: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8002004C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020050: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020054: lw          $t3, 0x0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X0);
    // 0x80020058: nop

    // 0x8002005C: andi        $t6, $t3, 0x4
    ctx->r14 = ctx->r11 & 0X4;
    // 0x80020060: beq         $t6, $zero, L_80020074
    if (ctx->r14 == 0) {
        // 0x80020064: nop
    
            goto L_80020074;
    }
    // 0x80020064: nop

    // 0x80020068: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8002006C: b           L_80020078
    // 0x80020070: sb          $t9, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r25;
        goto L_80020078;
    // 0x80020070: sb          $t9, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r25;
L_80020074:
    // 0x80020074: sb          $zero, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = 0;
L_80020078:
    // 0x80020078: jal         0x80022124
    // 0x8002007C: nop

    func_80022124(rdram, ctx);
        goto after_5;
    // 0x8002007C: nop

    after_5:
    // 0x80020080: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80020084: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80020088: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002008C: lwc1        $f8, 0xCC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x80020090: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x80020094: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    // 0x80020098: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8002009C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800200A0: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x800200A4: lwc1        $f10, 0xD0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x800200A8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800200AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800200B0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800200B4: jal         0x800B202C
    // 0x800200B8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B202C(rdram, ctx);
        goto after_6;
    // 0x800200B8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x800200BC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800200C0: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x800200C4: sw          $v0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r2;
    // 0x800200C8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800200CC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x800200D0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800200D4: nop

    // 0x800200D8: ori         $t3, $t5, 0x1
    ctx->r11 = ctx->r13 | 0X1;
    // 0x800200DC: b           L_80020158
    // 0x800200E0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
        goto L_80020158;
    // 0x800200E0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_800200E4:
    // 0x800200E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800200E8: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x800200EC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800200F0: nop

    // 0x800200F4: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800200F8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800200FC: addiu       $t1, $t1, 0x2618
    ctx->r9 = ADD32(ctx->r9, 0X2618);
    // 0x80020100: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x80020104: nop

    // 0x80020108: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x8002010C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80020110: jal         0x800B2748
    // 0x80020114: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800B2748(rdram, ctx);
        goto after_7;
    // 0x80020114: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x80020118: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8002011C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80020120: nop

    // 0x80020124: bgez        $t8, L_80020148
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80020128: nop
    
            goto L_80020148;
    }
    // 0x80020128: nop

    // 0x8002012C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80020130: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80020134: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80020138: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002013C: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x80020140: b           L_80020158
    // 0x80020144: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
        goto L_80020158;
    // 0x80020144: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
L_80020148:
    // 0x80020148: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8002014C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020150: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020154: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
L_80020158:
    // 0x80020158: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8002015C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80020160: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80020164: lhu         $t1, 0xFF4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XFF4);
    // 0x80020168: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x8002016C: nop

    // 0x80020170: and         $t4, $t9, $t1
    ctx->r12 = ctx->r25 & ctx->r9;
    // 0x80020174: beq         $t4, $zero, L_80020218
    if (ctx->r12 == 0) {
        // 0x80020178: nop
    
            goto L_80020218;
    }
    // 0x80020178: nop

    // 0x8002017C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020180: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x80020184: nop

    // 0x80020188: and         $t2, $t9, $t8
    ctx->r10 = ctx->r25 & ctx->r24;
    // 0x8002018C: beq         $t2, $zero, L_80020218
    if (ctx->r10 == 0) {
        // 0x80020190: nop
    
            goto L_80020218;
    }
    // 0x80020190: nop

    // 0x80020194: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020198: addiu       $t5, $t5, 0x2618
    ctx->r13 = ADD32(ctx->r13, 0X2618);
    // 0x8002019C: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x800201A0: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x800201A4: nop

    // 0x800201A8: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
L_800201AC:
    // 0x800201AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800201B0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800201B4: nop

    // 0x800201B8: swc1        $f16, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f16.u32l;
    // 0x800201BC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800201C0: nop

    // 0x800201C4: lwc1        $f18, 0xD0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x800201C8: nop

    // 0x800201CC: swc1        $f18, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f18.u32l;
    // 0x800201D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800201D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800201D8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800201DC: nop

    // 0x800201E0: swc1        $f4, 0xF8($t6)
    MEM_W(0XF8, ctx->r14) = ctx->f4.u32l;
    // 0x800201E4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800201E8: nop

    // 0x800201EC: lwc1        $f6, 0xF8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x800201F0: nop

    // 0x800201F4: swc1        $f6, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f6.u32l;
    // 0x800201F8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800201FC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80020200: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x80020204: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80020208: addiu       $t2, $t8, 0x160
    ctx->r10 = ADD32(ctx->r24, 0X160);
    // 0x8002020C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80020210: bne         $at, $zero, L_800201AC
    if (ctx->r1 != 0) {
        // 0x80020214: sw          $t9, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r25;
            goto L_800201AC;
    }
    // 0x80020214: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
L_80020218:
    // 0x80020218: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8002021C: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80020220: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80020224: lhu         $t3, 0x10F2($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X10F2);
    // 0x80020228: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x8002022C: nop

    // 0x80020230: and         $t0, $t7, $t3
    ctx->r8 = ctx->r15 & ctx->r11;
    // 0x80020234: beq         $t0, $zero, L_800202B4
    if (ctx->r8 == 0) {
        // 0x80020238: nop
    
            goto L_800202B4;
    }
    // 0x80020238: nop

    // 0x8002023C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80020240: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x80020244: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80020248: nop

    // 0x8002024C: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80020250: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80020254: addiu       $t4, $t4, 0x2618
    ctx->r12 = ADD32(ctx->r12, 0X2618);
    // 0x80020258: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x8002025C: nop

    // 0x80020260: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80020264: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80020268: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8002026C: jal         0x800B2CBC
    // 0x80020270: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800B2CBC(rdram, ctx);
        goto after_8;
    // 0x80020270: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x80020274: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80020278: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8002027C: nop

    // 0x80020280: bgez        $t2, L_800202A4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80020284: nop
    
            goto L_800202A4;
    }
    // 0x80020284: nop

    // 0x80020288: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002028C: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x80020290: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80020294: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80020298: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8002029C: b           L_800202B4
    // 0x800202A0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
        goto L_800202B4;
    // 0x800202A0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
L_800202A4:
    // 0x800202A4: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800202A8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800202AC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x800202B0: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
L_800202B4:
    // 0x800202B4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800202B8: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x800202BC: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x800202C0: nop

    // 0x800202C4: andi        $t4, $t1, 0x1
    ctx->r12 = ctx->r9 & 0X1;
    // 0x800202C8: beq         $t4, $zero, L_800203CC
    if (ctx->r12 == 0) {
        // 0x800202CC: nop
    
            goto L_800203CC;
    }
    // 0x800202CC: nop

    // 0x800202D0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800202D4: addiu       $t8, $t8, 0x2618
    ctx->r24 = ADD32(ctx->r24, 0X2618);
    // 0x800202D8: lw          $t2, 0x4($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X4);
    // 0x800202DC: nop

    // 0x800202E0: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x800202E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800202E8: addiu       $t5, $t5, 0x2618
    ctx->r13 = ADD32(ctx->r13, 0X2618);
    // 0x800202EC: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x800202F0: nop

    // 0x800202F4: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800202F8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800202FC: jal         0x800B3434
    // 0x80020300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_9;
    // 0x80020300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80020304: sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
    // 0x80020308: lhu         $t9, 0x48($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X48);
    // 0x8002030C: nop

    // 0x80020310: andi        $t3, $t9, 0x4000
    ctx->r11 = ctx->r25 & 0X4000;
    // 0x80020314: beq         $t3, $zero, L_80020334
    if (ctx->r11 == 0) {
        // 0x80020318: nop
    
            goto L_80020334;
    }
    // 0x80020318: nop

    // 0x8002031C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80020320: jal         0x800B32E4
    // 0x80020324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B32E4(rdram, ctx);
        goto after_10;
    // 0x80020324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80020328: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x8002032C: jal         0x800B9000
    // 0x80020330: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B9000(rdram, ctx);
        goto after_11;
    // 0x80020330: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
L_80020334:
    // 0x80020334: lhu         $t0, 0x48($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X48);
    // 0x80020338: nop

    // 0x8002033C: andi        $t6, $t0, 0x8000
    ctx->r14 = ctx->r8 & 0X8000;
    // 0x80020340: beq         $t6, $zero, L_80020360
    if (ctx->r14 == 0) {
        // 0x80020344: nop
    
            goto L_80020360;
    }
    // 0x80020344: nop

    // 0x80020348: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8002034C: jal         0x800B32E4
    // 0x80020350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800B32E4(rdram, ctx);
        goto after_12;
    // 0x80020350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80020354: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80020358: jal         0x800B9000
    // 0x8002035C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B9000(rdram, ctx);
        goto after_13;
    // 0x8002035C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
L_80020360:
    // 0x80020360: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80020364: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80020368: lhu         $t4, 0x1258($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1258);
    // 0x8002036C: lhu         $t1, 0x11AC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X11AC);
    // 0x80020370: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80020374: lhu         $t2, 0x126C($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X126C);
    // 0x80020378: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002037C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80020380: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x80020384: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80020388: or          $t8, $t1, $t4
    ctx->r24 = ctx->r9 | ctx->r12;
    // 0x8002038C: lhu         $t0, 0x4($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X4);
    // 0x80020390: or          $t5, $t8, $t2
    ctx->r13 = ctx->r24 | ctx->r10;
    // 0x80020394: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x80020398: and         $t6, $t0, $t9
    ctx->r14 = ctx->r8 & ctx->r25;
    // 0x8002039C: beq         $t6, $zero, L_800203BC
    if (ctx->r14 == 0) {
        // 0x800203A0: nop
    
            goto L_800203BC;
    }
    // 0x800203A0: nop

    // 0x800203A4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800203A8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800203AC: jal         0x800B2CBC
    // 0x800203B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800B2CBC(rdram, ctx);
        goto after_14;
    // 0x800203B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_14:
    // 0x800203B4: b           L_800203CC
    // 0x800203B8: nop

        goto L_800203CC;
    // 0x800203B8: nop

L_800203BC:
    // 0x800203BC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800203C0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800203C4: jal         0x800B2CBC
    // 0x800203C8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800B2CBC(rdram, ctx);
        goto after_15;
    // 0x800203C8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_15:
L_800203CC:
    // 0x800203CC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800203D0: addiu       $t1, $t1, 0x2618
    ctx->r9 = ADD32(ctx->r9, 0X2618);
    // 0x800203D4: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x800203D8: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x800203DC: nop

    // 0x800203E0: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
L_800203E4:
    // 0x800203E4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800203E8: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800203EC: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x800203F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800203F4: nop

    // 0x800203F8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800203FC: nop

    // 0x80020400: bc1f        L_80020410
    if (!c1cs) {
        // 0x80020404: nop
    
            goto L_80020410;
    }
    // 0x80020404: nop

    // 0x80020408: b           L_80020424
    // 0x8002040C: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
        goto L_80020424;
    // 0x8002040C: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
L_80020410:
    // 0x80020410: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80020414: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80020418: lwc1        $f20, 0x10($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8002041C: nop

    // 0x80020420: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80020424:
    // 0x80020424: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80020428: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002042C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80020430: cvt.d.s     $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f16.d = CVT_D_S(ctx->f20.fl);
    // 0x80020434: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x80020438: nop

    // 0x8002043C: bc1f        L_80020484
    if (!c1cs) {
        // 0x80020440: nop
    
            goto L_80020484;
    }
    // 0x80020440: nop

    // 0x80020444: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80020448: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8002044C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020450: lwc1        $f4, 0x10($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X10);
    // 0x80020454: lwc1        $f11, -0x23C0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X23C0);
    // 0x80020458: lwc1        $f10, -0x23BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X23BC);
    // 0x8002045C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80020460: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80020464: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80020468: nop

    // 0x8002046C: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80020470: nop

    // 0x80020474: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80020478: add.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f18.d + ctx->f8.d;
    // 0x8002047C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80020480: swc1        $f6, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f6.u32l;
L_80020484:
    // 0x80020484: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80020488: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8002048C: lwc1        $f10, 0x14($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80020490: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80020494: nop

    // 0x80020498: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8002049C: nop

    // 0x800204A0: bc1f        L_800204B0
    if (!c1cs) {
        // 0x800204A4: nop
    
            goto L_800204B0;
    }
    // 0x800204A4: nop

    // 0x800204A8: b           L_800204C4
    // 0x800204AC: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
        goto L_800204C4;
    // 0x800204AC: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
L_800204B0:
    // 0x800204B0: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800204B4: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x800204B8: lwc1        $f20, 0x14($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800204BC: nop

    // 0x800204C0: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_800204C4:
    // 0x800204C4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800204C8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800204CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800204D0: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x800204D4: c.le.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d <= ctx->f18.d;
    // 0x800204D8: nop

    // 0x800204DC: bc1f        L_80020524
    if (!c1cs) {
        // 0x800204E0: nop
    
            goto L_80020524;
    }
    // 0x800204E0: nop

    // 0x800204E4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800204E8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x800204EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800204F0: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800204F4: lwc1        $f17, -0x23B8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X23B8);
    // 0x800204F8: lwc1        $f16, -0x23B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X23B4);
    // 0x800204FC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80020500: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80020504: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80020508: nop

    // 0x8002050C: lwc1        $f18, 0xD0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x80020510: nop

    // 0x80020514: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80020518: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8002051C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80020520: swc1        $f6, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f6.u32l;
L_80020524:
    // 0x80020524: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80020528: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8002052C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020530: lhu         $t8, 0x1042($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1042);
    // 0x80020534: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x80020538: nop

    // 0x8002053C: and         $t2, $t4, $t8
    ctx->r10 = ctx->r12 & ctx->r24;
    // 0x80020540: beq         $t2, $zero, L_80020580
    if (ctx->r10 == 0) {
        // 0x80020544: nop
    
            goto L_80020580;
    }
    // 0x80020544: nop

    // 0x80020548: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002054C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020550: lwc1        $f16, 0xF4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XF4);
    // 0x80020554: lwc1        $f9, -0x23B0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X23B0);
    // 0x80020558: lwc1        $f8, -0x23AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X23AC);
    // 0x8002055C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80020560: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x80020564: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80020568: swc1        $f4, 0xF4($t5)
    MEM_W(0XF4, ctx->r13) = ctx->f4.u32l;
    // 0x8002056C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80020570: nop

    // 0x80020574: lwc1        $f6, 0xF4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x80020578: nop

    // 0x8002057C: swc1        $f6, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->f6.u32l;
L_80020580:
    // 0x80020580: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80020584: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80020588: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002058C: lhu         $t9, 0x1038($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1038);
    // 0x80020590: lhu         $t0, 0x8($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X8);
    // 0x80020594: nop

    // 0x80020598: and         $t6, $t0, $t9
    ctx->r14 = ctx->r8 & ctx->r25;
    // 0x8002059C: beq         $t6, $zero, L_80020628
    if (ctx->r14 == 0) {
        // 0x800205A0: nop
    
            goto L_80020628;
    }
    // 0x800205A0: nop

    // 0x800205A4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800205A8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800205AC: lwc1        $f16, 0xF4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XF4);
    // 0x800205B0: lwc1        $f9, -0x23A8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X23A8);
    // 0x800205B4: lwc1        $f8, -0x23A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X23A4);
    // 0x800205B8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800205BC: sub.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d - ctx->f8.d;
    // 0x800205C0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800205C4: swc1        $f4, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f4.u32l;
    // 0x800205C8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800205CC: nop

    // 0x800205D0: lwc1        $f6, 0xF4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x800205D4: nop

    // 0x800205D8: swc1        $f6, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f6.u32l;
    // 0x800205DC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800205E0: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800205E4: lwc1        $f16, 0xF8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x800205E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800205EC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800205F0: c.le.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d <= ctx->f8.d;
    // 0x800205F4: nop

    // 0x800205F8: bc1f        L_80020628
    if (!c1cs) {
        // 0x800205FC: nop
    
            goto L_80020628;
    }
    // 0x800205FC: nop

    // 0x80020600: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020604: lwc1        $f10, -0x23A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X23A0);
    // 0x80020608: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002060C: nop

    // 0x80020610: swc1        $f10, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f10.u32l;
    // 0x80020614: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80020618: nop

    // 0x8002061C: lwc1        $f4, 0xF4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XF4);
    // 0x80020620: nop

    // 0x80020624: swc1        $f4, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f4.u32l;
L_80020628:
    // 0x80020628: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8002062C: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80020630: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020634: lhu         $t0, 0x1042($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X1042);
    // 0x80020638: lhu         $t3, 0x6($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X6);
    // 0x8002063C: nop

    // 0x80020640: and         $t9, $t3, $t0
    ctx->r25 = ctx->r11 & ctx->r8;
    // 0x80020644: beq         $t9, $zero, L_8002068C
    if (ctx->r25 == 0) {
        // 0x80020648: nop
    
            goto L_8002068C;
    }
    // 0x80020648: nop

    // 0x8002064C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80020650: lhu         $t6, 0x1038($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1038);
    // 0x80020654: nop

    // 0x80020658: and         $t1, $t3, $t6
    ctx->r9 = ctx->r11 & ctx->r14;
    // 0x8002065C: beq         $t1, $zero, L_8002068C
    if (ctx->r9 == 0) {
        // 0x80020660: nop
    
            goto L_8002068C;
    }
    // 0x80020660: nop

    // 0x80020664: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80020668: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002066C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80020670: nop

    // 0x80020674: swc1        $f6, 0xF4($t4)
    MEM_W(0XF4, ctx->r12) = ctx->f6.u32l;
    // 0x80020678: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002067C: nop

    // 0x80020680: lwc1        $f16, 0xF4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x80020684: nop

    // 0x80020688: swc1        $f16, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f16.u32l;
L_8002068C:
    // 0x8002068C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020690: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020694: lw          $t7, 0x1C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1C);
    // 0x80020698: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8002069C: nop

    // 0x800206A0: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800206A4: bne         $at, $zero, L_800206B4
    if (ctx->r1 != 0) {
        // 0x800206A8: nop
    
            goto L_800206B4;
    }
    // 0x800206A8: nop

    // 0x800206AC: b           L_800206DC
    // 0x800206B0: nop

        goto L_800206DC;
    // 0x800206B0: nop

L_800206B4:
    // 0x800206B4: jal         0x800C1754
    // 0x800206B8: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_16;
    // 0x800206B8: nop

    after_16:
    // 0x800206BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800206C0: jal         0x8009A14C
    // 0x800206C4: nop

    func_8009A14C(rdram, ctx);
        goto after_17;
    // 0x800206C4: nop

    after_17:
    // 0x800206C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800206CC: jal         0x800997D8
    // 0x800206D0: nop

    func_800997D8(rdram, ctx);
        goto after_18;
    // 0x800206D0: nop

    after_18:
    // 0x800206D4: jal         0x800C1A28
    // 0x800206D8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_19;
    // 0x800206D8: nop

    after_19:
L_800206DC:
    // 0x800206DC: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800206E0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800206E4: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800206E8: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800206EC: addiu       $t6, $t3, 0x160
    ctx->r14 = ADD32(ctx->r11, 0X160);
    // 0x800206F0: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800206F4: bne         $at, $zero, L_800203E4
    if (ctx->r1 != 0) {
        // 0x800206F8: sw          $t9, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r25;
            goto L_800203E4;
    }
    // 0x800206F8: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x800206FC: b           L_80020704
    // 0x80020700: nop

        goto L_80020704;
    // 0x80020700: nop

L_80020704:
    // 0x80020704: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80020708: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002070C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80020710: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80020714: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80020718: jr          $ra
    // 0x8002071C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8002071C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8000DD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DD94: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x8000DD98: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8000DD9C: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x8000DDA0: nop

    // 0x8000DDA4: beq         $t6, $zero, L_8000DDBC
    if (ctx->r14 == 0) {
        // 0x8000DDA8: nop
    
            goto L_8000DDBC;
    }
    // 0x8000DDA8: nop

    // 0x8000DDAC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8000DDB0: lw          $t7, 0x3068($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3068);
    // 0x8000DDB4: nop

    // 0x8000DDB8: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
L_8000DDBC:
    // 0x8000DDBC: jr          $ra
    // 0x8000DDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000DDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DDC4: jr          $ra
    // 0x8000DDC8: nop

    return;
    // 0x8000DDC8: nop

    // 0x8000DDCC: jr          $ra
    // 0x8000DDD0: nop

    return;
    // 0x8000DDD0: nop

;}
RECOMP_FUNC void func_8006B518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B518: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B51C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B520: nop

    // 0x8006B524: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006B528: nop

    // 0x8006B52C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8006B530: jr          $ra
    // 0x8006B534: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B534: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B538: jr          $ra
    // 0x8006B53C: nop

    return;
    // 0x8006B53C: nop

    // 0x8006B540: jr          $ra
    // 0x8006B544: nop

    return;
    // 0x8006B544: nop

;}
RECOMP_FUNC void func_8006BAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BAFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006BB00: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006BB04: nop

    // 0x8006BB08: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006BB0C: nop

    // 0x8006BB10: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006BB14: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006BB18: jr          $ra
    // 0x8006BB1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006BB1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006BB20: jr          $ra
    // 0x8006BB24: nop

    return;
    // 0x8006BB24: nop

    // 0x8006BB28: jr          $ra
    // 0x8006BB2C: nop

    return;
    // 0x8006BB2C: nop

;}
RECOMP_FUNC void func_80000C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C90: addiu       $sp, $sp, -0x430
    ctx->r29 = ADD32(ctx->r29, -0X430);
    // 0x80000C94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000C98: sw          $a0, 0x430($sp)
    MEM_W(0X430, ctx->r29) = ctx->r4;
    // 0x80000C9C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80000CA0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000CA4: sw          $zero, 0x3DF4($at)
    MEM_W(0X3DF4, ctx->r1) = 0;
    // 0x80000CA8: lw          $t6, 0x430($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X430);
    // 0x80000CAC: nop

    // 0x80000CB0: sw          $t6, 0x414($sp)
    MEM_W(0X414, ctx->r29) = ctx->r14;
    // 0x80000CB4: lw          $t7, 0x414($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X414);
    // 0x80000CB8: nop

    // 0x80000CBC: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80000CC0: nop

    // 0x80000CC4: sw          $t8, 0x410($sp)
    MEM_W(0X410, ctx->r29) = ctx->r24;
    // 0x80000CC8: sw          $zero, 0x420($sp)
    MEM_W(0X420, ctx->r29) = 0;
    // 0x80000CCC: sw          $zero, 0x428($sp)
    MEM_W(0X428, ctx->r29) = 0;
    // 0x80000CD0: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80000CD4: sh          $t9, 0x3EC($sp)
    MEM_H(0X3EC, ctx->r29) = ctx->r25;
    // 0x80000CD8: addiu       $t0, $zero, 0x21
    ctx->r8 = ADD32(0, 0X21);
    // 0x80000CDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000CE0: sh          $t0, -0x820($at)
    MEM_H(-0X820, ctx->r1) = ctx->r8;
    // 0x80000CE4: jal         0x80098820
    // 0x80000CE8: nop

    func_80098820(rdram, ctx);
        goto after_0;
    // 0x80000CE8: nop

    after_0:
    // 0x80000CEC: jal         0x80098868
    // 0x80000CF0: nop

    func_80098868(rdram, ctx);
        goto after_1;
    // 0x80000CF0: nop

    after_1:
    // 0x80000CF4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80000CF8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80000CFC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80000D00: nop

    // 0x80000D04: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80000D08: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80000D0C: lw          $t4, 0x414($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X414);
    // 0x80000D10: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x80000D14: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x80000D18: jal         0x800C1264
    // 0x80000D1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_2;
    // 0x80000D1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80000D20: lw          $t5, 0x428($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X428);
    // 0x80000D24: nop

    // 0x80000D28: bne         $t5, $zero, L_80001F3C
    if (ctx->r13 != 0) {
        // 0x80000D2C: nop
    
            goto L_80001F3C;
    }
    // 0x80000D2C: nop

L_80000D30:
    // 0x80000D30: lw          $t6, 0x414($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X414);
    // 0x80000D34: addiu       $a1, $sp, 0x40C
    ctx->r5 = ADD32(ctx->r29, 0X40C);
    // 0x80000D38: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80000D3C: jal         0x800C143C
    // 0x80000D40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_3;
    // 0x80000D40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80000D44: lw          $t7, 0x40C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40C);
    // 0x80000D48: nop

    // 0x80000D4C: lh          $s0, 0x0($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X0);
    // 0x80000D50: nop

    // 0x80000D54: slti        $at, $s0, 0x21
    ctx->r1 = SIGNED(ctx->r16) < 0X21 ? 1 : 0;
    // 0x80000D58: bne         $at, $zero, L_80000D74
    if (ctx->r1 != 0) {
        // 0x80000D5C: nop
    
            goto L_80000D74;
    }
    // 0x80000D5C: nop

    // 0x80000D60: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80000D64: beq         $s0, $at, L_80001DAC
    if (ctx->r16 == ctx->r1) {
        // 0x80000D68: nop
    
            goto L_80001DAC;
    }
    // 0x80000D68: nop

    // 0x80000D6C: b           L_80001F24
    // 0x80000D70: nop

        goto L_80001F24;
    // 0x80000D70: nop

L_80000D74:
    // 0x80000D74: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80000D78: bne         $at, $zero, L_80000D94
    if (ctx->r1 != 0) {
        // 0x80000D7C: nop
    
            goto L_80000D94;
    }
    // 0x80000D7C: nop

    // 0x80000D80: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80000D84: beq         $s0, $at, L_80000DC0
    if (ctx->r16 == ctx->r1) {
        // 0x80000D88: nop
    
            goto L_80000DC0;
    }
    // 0x80000D88: nop

    // 0x80000D8C: b           L_80001F24
    // 0x80000D90: nop

        goto L_80001F24;
    // 0x80000D90: nop

L_80000D94:
    // 0x80000D94: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x80000D98: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80000D9C: beq         $at, $zero, L_80001F24
    if (ctx->r1 == 0) {
        // 0x80000DA0: nop
    
            goto L_80001F24;
    }
    // 0x80000DA0: nop

    // 0x80000DA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80000DA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80000DAC: addu        $at, $at, $t8
    gpr jr_addend_80000DB8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80000DB0: lw          $t8, -0x2EC0($at)
    ctx->r24 = ADD32(ctx->r1, -0X2EC0);
    // 0x80000DB4: nop

    // 0x80000DB8: jr          $t8
    // 0x80000DBC: nop

    switch (jr_addend_80000DB8 >> 2) {
        case 0: goto L_800012FC; break;
        case 1: goto L_80001878; break;
        case 2: goto L_80001F1C; break;
        case 3: goto L_80001F04; break;
        case 4: goto L_800019A4; break;
        default: switch_error(__func__, 0x80000DB8, 0x800ED140);
    }
    // 0x80000DBC: nop

L_80000DC0:
    // 0x80000DC0: jal         0x80098BF4
    // 0x80000DC4: nop

    func_80098BF4(rdram, ctx);
        goto after_4;
    // 0x80000DC4: nop

    after_4:
    // 0x80000DC8: sw          $zero, 0x418($sp)
    MEM_W(0X418, ctx->r29) = 0;
L_80000DCC:
    // 0x80000DCC: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80000DD0: addiu       $a1, $sp, 0x40C
    ctx->r5 = ADD32(ctx->r29, 0X40C);
    // 0x80000DD4: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80000DD8: jal         0x800C143C
    // 0x80000DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_5;
    // 0x80000DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80000DE0: lw          $t0, 0x40C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40C);
    // 0x80000DE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000DE8: lh          $s0, 0x0($t0)
    ctx->r16 = MEM_H(ctx->r8, 0X0);
    // 0x80000DEC: nop

    // 0x80000DF0: beq         $s0, $at, L_80000E18
    if (ctx->r16 == ctx->r1) {
        // 0x80000DF4: nop
    
            goto L_80000E18;
    }
    // 0x80000DF4: nop

    // 0x80000DF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80000DFC: beq         $s0, $at, L_80000E30
    if (ctx->r16 == ctx->r1) {
        // 0x80000E00: nop
    
            goto L_80000E30;
    }
    // 0x80000E00: nop

    // 0x80000E04: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80000E08: beq         $s0, $at, L_80000E18
    if (ctx->r16 == ctx->r1) {
        // 0x80000E0C: nop
    
            goto L_80000E18;
    }
    // 0x80000E0C: nop

    // 0x80000E10: b           L_80000E60
    // 0x80000E14: nop

        goto L_80000E60;
    // 0x80000E14: nop

L_80000E18:
    // 0x80000E18: lw          $t2, 0x418($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X418);
    // 0x80000E1C: nop

    // 0x80000E20: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80000E24: sw          $t3, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r11;
    // 0x80000E28: b           L_80000E60
    // 0x80000E2C: nop

        goto L_80000E60;
    // 0x80000E2C: nop

L_80000E30:
    // 0x80000E30: jal         0x80099520
    // 0x80000E34: nop

    func_80099520(rdram, ctx);
        goto after_6;
    // 0x80000E34: nop

    after_6:
    // 0x80000E38: lw          $t1, 0x410($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X410);
    // 0x80000E3C: nop

    // 0x80000E40: addiu       $t4, $t1, 0x7FFF
    ctx->r12 = ADD32(ctx->r9, 0X7FFF);
    // 0x80000E44: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x80000E48: addiu       $at, $t1, 0x7FFF
    ctx->r1 = ADD32(ctx->r9, 0X7FFF);
    // 0x80000E4C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80000E50: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
    // 0x80000E54: sw          $zero, 0x418($sp)
    MEM_W(0X418, ctx->r29) = 0;
    // 0x80000E58: b           L_80000E60
    // 0x80000E5C: nop

        goto L_80000E60;
    // 0x80000E5C: nop

L_80000E60:
    // 0x80000E60: lw          $t6, 0x418($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X418);
    // 0x80000E64: nop

    // 0x80000E68: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80000E6C: bne         $at, $zero, L_80000DCC
    if (ctx->r1 != 0) {
        // 0x80000E70: nop
    
            goto L_80000DCC;
    }
    // 0x80000E70: nop

    // 0x80000E74: jal         0x80098820
    // 0x80000E78: nop

    func_80098820(rdram, ctx);
        goto after_7;
    // 0x80000E78: nop

    after_7:
    // 0x80000E7C: jal         0x80098868
    // 0x80000E80: nop

    func_80098868(rdram, ctx);
        goto after_8;
    // 0x80000E80: nop

    after_8:
    // 0x80000E84: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80000E88: lw          $t7, 0x60E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X60E4);
    // 0x80000E8C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80000E90: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80000E94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000E98: sw          $t8, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r24;
    // 0x80000E9C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80000EA0: lw          $t9, 0x60E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X60E4);
    // 0x80000EA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000EA8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80000EAC: sw          $t0, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r8;
    // 0x80000EB0: sw          $zero, 0x420($sp)
    MEM_W(0X420, ctx->r29) = 0;
    // 0x80000EB4: jal         0x80002F20
    // 0x80000EB8: nop

    func_80002F20(rdram, ctx);
        goto after_9;
    // 0x80000EB8: nop

    after_9:
    // 0x80000EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000EC0: bne         $v0, $at, L_80000ED0
    if (ctx->r2 != ctx->r1) {
        // 0x80000EC4: nop
    
            goto L_80000ED0;
    }
    // 0x80000EC4: nop

L_80000EC8:
    // 0x80000EC8: b           L_80000EC8
    pause_self(rdram);
    // 0x80000ECC: nop

L_80000ED0:
    // 0x80000ED0: addiu       $t2, $sp, 0x38
    ctx->r10 = ADD32(ctx->r29, 0X38);
    // 0x80000ED4: sw          $t2, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r10;
    // 0x80000ED8: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80000EDC: jal         0x80099E2C
    // 0x80000EE0: nop

    func_80099E2C(rdram, ctx);
        goto after_10;
    // 0x80000EE0: nop

    after_10:
    // 0x80000EE4: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80000EE8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80000EEC: jal         0x800B1B04
    // 0x80000EF0: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    func_800B1B04(rdram, ctx);
        goto after_11;
    // 0x80000EF0: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    after_11:
    // 0x80000EF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80000EF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80000EFC: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80000F00: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80000F04: lui         $a2, 0x69
    ctx->r6 = S32(0X69 << 16);
    // 0x80000F08: ori         $a2, $a2, 0x221
    ctx->r6 = ctx->r6 | 0X221;
    // 0x80000F0C: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    // 0x80000F10: addiu       $a3, $zero, 0x5F
    ctx->r7 = ADD32(0, 0X5F);
    // 0x80000F14: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80000F18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80000F1C: jal         0x800B1F0C
    // 0x80000F20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_12;
    // 0x80000F20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x80000F24: lw          $t3, 0x280($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X280);
    // 0x80000F28: nop

    // 0x80000F2C: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80000F30: nop

    // 0x80000F34: ori         $t5, $t4, 0x208
    ctx->r13 = ctx->r12 | 0X208;
    // 0x80000F38: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x80000F3C: lw          $t6, 0x280($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X280);
    // 0x80000F40: lui         $t1, 0x7FFF
    ctx->r9 = S32(0X7FFF << 16);
    // 0x80000F44: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80000F48: sw          $t1, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r9;
    // 0x80000F4C: jal         0x800AD774
    // 0x80000F50: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800AD774(rdram, ctx);
        goto after_13;
    // 0x80000F50: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80000F54: lw          $t7, 0x280($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X280);
    // 0x80000F58: nop

    // 0x80000F5C: sh          $v0, 0xC4($t7)
    MEM_H(0XC4, ctx->r15) = ctx->r2;
    // 0x80000F60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80000F64: sw          $t8, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r24;
    // 0x80000F68: lw          $t9, 0x410($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X410);
    // 0x80000F6C: nop

    // 0x80000F70: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80000F74: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80000F78: jal         0x80098820
    // 0x80000F7C: nop

    func_80098820(rdram, ctx);
        goto after_14;
    // 0x80000F7C: nop

    after_14:
    // 0x80000F80: jal         0x80098868
    // 0x80000F84: nop

    func_80098868(rdram, ctx);
        goto after_15;
    // 0x80000F84: nop

    after_15:
    // 0x80000F88: lw          $t0, 0x414($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X414);
    // 0x80000F8C: nop

    // 0x80000F90: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80000F94: jal         0x800C13B8
    // 0x80000F98: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_16;
    // 0x80000F98: nop

    after_16:
    // 0x80000F9C: lw          $t2, 0x414($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X414);
    // 0x80000FA0: nop

    // 0x80000FA4: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x80000FA8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80000FAC: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80000FB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000FB4: sh          $t4, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r12;
    // 0x80000FB8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80000FBC: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80000FC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000FC4: sh          $t5, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r13;
    // 0x80000FC8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80000FCC: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80000FD0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80000FD4: bne         $t3, $at, L_80000FF0
    if (ctx->r11 != ctx->r1) {
        // 0x80000FD8: nop
    
            goto L_80000FF0;
    }
    // 0x80000FD8: nop

    // 0x80000FDC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80000FE0: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x80000FE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000FE8: beq         $t1, $at, L_80001018
    if (ctx->r9 == ctx->r1) {
        // 0x80000FEC: nop
    
            goto L_80001018;
    }
    // 0x80000FEC: nop

L_80000FF0:
    // 0x80000FF0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80000FF4: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x80000FF8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80000FFC: bne         $t6, $at, L_8000105C
    if (ctx->r14 != ctx->r1) {
        // 0x80001000: nop
    
            goto L_8000105C;
    }
    // 0x80001000: nop

    // 0x80001004: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80001008: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8000100C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001010: bne         $t7, $at, L_8000105C
    if (ctx->r15 != ctx->r1) {
        // 0x80001014: nop
    
            goto L_8000105C;
    }
    // 0x80001014: nop

L_80001018:
    // 0x80001018: jal         0x80098BF4
    // 0x8000101C: nop

    func_80098BF4(rdram, ctx);
        goto after_17;
    // 0x8000101C: nop

    after_17:
    // 0x80001020: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x80001024: jal         0x800077A0
    // 0x80001028: nop

    func_800077A0(rdram, ctx);
        goto after_18;
    // 0x80001028: nop

    after_18:
    // 0x8000102C: lw          $t8, 0x414($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X414);
    // 0x80001030: nop

    // 0x80001034: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80001038: jal         0x800C13B8
    // 0x8000103C: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_19;
    // 0x8000103C: nop

    after_19:
    // 0x80001040: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80001044: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x80001048: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8000104C: jal         0x800C1264
    // 0x80001050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_20;
    // 0x80001050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x80001054: b           L_800012F4
    // 0x80001058: nop

        goto L_800012F4;
    // 0x80001058: nop

L_8000105C:
    // 0x8000105C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80001060: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x80001064: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80001068: bne         $t0, $at, L_8000118C
    if (ctx->r8 != ctx->r1) {
        // 0x8000106C: nop
    
            goto L_8000118C;
    }
    // 0x8000106C: nop

    // 0x80001070: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80001074: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x80001078: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8000107C: bne         $t2, $at, L_8000118C
    if (ctx->r10 != ctx->r1) {
        // 0x80001080: nop
    
            goto L_8000118C;
    }
    // 0x80001080: nop

    // 0x80001084: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80001088: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000108C: sh          $t4, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r12;
    // 0x80001090: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x80001094: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001098: sh          $t5, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r13;
    // 0x8000109C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800010A0: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x800010A4: lhu         $t1, 0x6($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X6);
    // 0x800010A8: nop

    // 0x800010AC: ori         $t6, $t1, 0x8000
    ctx->r14 = ctx->r9 | 0X8000;
    // 0x800010B0: sh          $t6, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r14;
    // 0x800010B4: jal         0x80098BF4
    // 0x800010B8: nop

    func_80098BF4(rdram, ctx);
        goto after_21;
    // 0x800010B8: nop

    after_21:
    // 0x800010BC: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x800010C0: jal         0x80005880
    // 0x800010C4: nop

    func_80005880(rdram, ctx);
        goto after_22;
    // 0x800010C4: nop

    after_22:
    // 0x800010C8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800010CC: lh          $t7, 0x7254($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7254);
    // 0x800010D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800010D4: andi        $t8, $t7, 0x7FFF
    ctx->r24 = ctx->r15 & 0X7FFF;
    // 0x800010D8: sh          $t8, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r24;
    // 0x800010DC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800010E0: lh          $t9, 0x725C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X725C);
    // 0x800010E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800010E8: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x800010EC: sh          $t0, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r8;
    // 0x800010F0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800010F4: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800010F8: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x800010FC: nop

    // 0x80001100: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80001104: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x80001108: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8000110C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80001110: sh          $zero, 0x2($t1)
    MEM_H(0X2, ctx->r9) = 0;
    // 0x80001114: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80001118: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000111C: lhu         $t3, 0x6($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0X6);
    // 0x80001120: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80001124: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80001128: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8000112C: sh          $t7, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r15;
    // 0x80001130: jal         0x80016074
    // 0x80001134: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_23;
    // 0x80001134: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_23:
    // 0x80001138: sw          $v0, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r2;
    // 0x8000113C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80001140: lw          $t8, 0x274($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X274);
    // 0x80001144: nop

    // 0x80001148: swc1        $f8, 0x1E8($t8)
    MEM_W(0X1E8, ctx->r24) = ctx->f8.u32l;
    // 0x8000114C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80001150: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001154: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001158: swc1        $f10, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f10.u32l;
    // 0x8000115C: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80001160: nop

    // 0x80001164: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80001168: jal         0x800C13B8
    // 0x8000116C: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_24;
    // 0x8000116C: nop

    after_24:
    // 0x80001170: lw          $t0, 0x414($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X414);
    // 0x80001174: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x80001178: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8000117C: jal         0x800C1264
    // 0x80001180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_25;
    // 0x80001180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x80001184: b           L_800012F4
    // 0x80001188: nop

        goto L_800012F4;
    // 0x80001188: nop

L_8000118C:
    // 0x8000118C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80001190: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80001194: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80001198: bne         $t4, $at, L_800012F4
    if (ctx->r12 != ctx->r1) {
        // 0x8000119C: nop
    
            goto L_800012F4;
    }
    // 0x8000119C: nop

    // 0x800011A0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800011A4: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x800011A8: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800011AC: bne         $t5, $at, L_800012F4
    if (ctx->r13 != ctx->r1) {
        // 0x800011B0: nop
    
            goto L_800012F4;
    }
    // 0x800011B0: nop

    // 0x800011B4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800011B8: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800011BC: lhu         $t1, 0x4($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X4);
    // 0x800011C0: nop

    // 0x800011C4: andi        $t3, $t1, 0x10
    ctx->r11 = ctx->r9 & 0X10;
    // 0x800011C8: bne         $t3, $zero, L_80001268
    if (ctx->r11 != 0) {
        // 0x800011CC: nop
    
            goto L_80001268;
    }
    // 0x800011CC: nop

    // 0x800011D0: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x800011D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800011D8: sh          $t7, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r15;
    // 0x800011DC: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x800011E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800011E4: sh          $t6, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r14;
    // 0x800011E8: jal         0x80098BF4
    // 0x800011EC: nop

    func_80098BF4(rdram, ctx);
        goto after_26;
    // 0x800011EC: nop

    after_26:
    // 0x800011F0: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x800011F4: jal         0x80005880
    // 0x800011F8: nop

    func_80005880(rdram, ctx);
        goto after_27;
    // 0x800011F8: nop

    after_27:
    // 0x800011FC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80001200: lh          $t8, 0x7254($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7254);
    // 0x80001204: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001208: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x8000120C: sh          $t9, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r25;
    // 0x80001210: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80001214: lh          $t0, 0x725C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X725C);
    // 0x80001218: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000121C: andi        $t4, $t0, 0x7FFF
    ctx->r12 = ctx->r8 & 0X7FFF;
    // 0x80001220: sh          $t4, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r12;
    // 0x80001224: jal         0x80016074
    // 0x80001228: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_28;
    // 0x80001228: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_28:
    // 0x8000122C: sw          $v0, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r2;
    // 0x80001230: lw          $t5, 0x274($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X274);
    // 0x80001234: nop

    // 0x80001238: beq         $t5, $zero, L_80001260
    if (ctx->r13 == 0) {
        // 0x8000123C: nop
    
            goto L_80001260;
    }
    // 0x8000123C: nop

    // 0x80001240: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80001244: lw          $t2, 0x274($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X274);
    // 0x80001248: nop

    // 0x8000124C: swc1        $f16, 0x1E8($t2)
    MEM_W(0X1E8, ctx->r10) = ctx->f16.u32l;
    // 0x80001250: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80001254: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80001258: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000125C: swc1        $f18, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f18.u32l;
L_80001260:
    // 0x80001260: b           L_800012A8
    // 0x80001264: nop

        goto L_800012A8;
    // 0x80001264: nop

L_80001268:
    // 0x80001268: jal         0x80083F28
    // 0x8000126C: nop

    func_80083F28(rdram, ctx);
        goto after_29;
    // 0x8000126C: nop

    after_29:
    // 0x80001270: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80001274: sh          $v0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r2;
    // 0x80001278: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000127C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001280: sh          $t1, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r9;
    // 0x80001284: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001288: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000128C: sh          $t3, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r11;
    // 0x80001290: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80001294: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001298: sh          $t7, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r15;
    // 0x8000129C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800012A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800012A4: sh          $t6, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r14;
L_800012A8:
    // 0x800012A8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800012AC: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800012B0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800012B4: nop

    // 0x800012B8: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x800012BC: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x800012C0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800012C4: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x800012C8: sh          $zero, 0x2($t4)
    MEM_H(0X2, ctx->r12) = 0;
    // 0x800012CC: lw          $t5, 0x414($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X414);
    // 0x800012D0: nop

    // 0x800012D4: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x800012D8: jal         0x800C13B8
    // 0x800012DC: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_30;
    // 0x800012DC: nop

    after_30:
    // 0x800012E0: lw          $t2, 0x414($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X414);
    // 0x800012E4: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x800012E8: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x800012EC: jal         0x800C1264
    // 0x800012F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_31;
    // 0x800012F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
L_800012F4:
    // 0x800012F4: b           L_80001F2C
    // 0x800012F8: nop

        goto L_80001F2C;
    // 0x800012F8: nop

L_800012FC:
    // 0x800012FC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80001300: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80001304: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80001308: nop

    // 0x8000130C: andi        $t7, $t3, 0x2
    ctx->r15 = ctx->r11 & 0X2;
    // 0x80001310: bne         $t7, $zero, L_80001870
    if (ctx->r15 != 0) {
        // 0x80001314: nop
    
            goto L_80001870;
    }
    // 0x80001314: nop

    // 0x80001318: lw          $t6, 0x410($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X410);
    // 0x8000131C: nop

    // 0x80001320: addiu       $t9, $t6, 0x7FFF
    ctx->r25 = ADD32(ctx->r14, 0X7FFF);
    // 0x80001324: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x80001328: nop

    // 0x8000132C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80001330: beq         $at, $zero, L_80001870
    if (ctx->r1 == 0) {
        // 0x80001334: nop
    
            goto L_80001870;
    }
    // 0x80001334: nop

    // 0x80001338: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000133C: lw          $t0, 0x60E4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X60E4);
    // 0x80001340: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80001344: and         $t8, $t0, $at
    ctx->r24 = ctx->r8 & ctx->r1;
    // 0x80001348: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000134C: sw          $t8, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r24;
    // 0x80001350: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80001354: lw          $t4, 0x60E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X60E4);
    // 0x80001358: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000135C: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80001360: sw          $t5, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r13;
    // 0x80001364: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80001368: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000136C: sw          $t2, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = ctx->r10;
    // 0x80001370: jal         0x80032380
    // 0x80001374: nop

    func_80032380(rdram, ctx);
        goto after_32;
    // 0x80001374: nop

    after_32:
    // 0x80001378: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000137C: lw          $t1, 0x60E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X60E4);
    // 0x80001380: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80001384: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80001388: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000138C: sw          $t3, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r11;
    // 0x80001390: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80001394: lw          $t7, 0x60E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X60E4);
    // 0x80001398: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000139C: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x800013A0: sw          $t6, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r14;
    // 0x800013A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800013A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800013AC: sw          $t9, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = ctx->r25;
    // 0x800013B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800013B4: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x800013B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800013BC: sw          $t0, 0x30AC($at)
    MEM_W(0X30AC, ctx->r1) = ctx->r8;
    // 0x800013C0: jal         0x80099768
    // 0x800013C4: nop

    func_80099768(rdram, ctx);
        goto after_33;
    // 0x800013C4: nop

    after_33:
    // 0x800013C8: jal         0x800AFB28
    // 0x800013CC: nop

    func_800AFB28(rdram, ctx);
        goto after_34;
    // 0x800013CC: nop

    after_34:
    // 0x800013D0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800013D4: lw          $t4, -0x4CC4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CC4);
    // 0x800013D8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800013DC: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800013E0: lw          $t8, -0x4CCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CCC);
    // 0x800013E4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800013E8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800013EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800013F0: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x800013F4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800013F8: jal         0x800BE510
    // 0x800013FC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800BE510(rdram, ctx);
        goto after_35;
    // 0x800013FC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_35:
    // 0x80001400: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80001404: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80001408: lw          $t2, -0x4CC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CC4);
    // 0x8000140C: lw          $t5, -0x4CCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CCC);
    // 0x80001410: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80001414: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80001418: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000141C: jal         0x8009A04C
    // 0x80001420: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_8009A04C(rdram, ctx);
        goto after_36;
    // 0x80001420: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_36:
    // 0x80001424: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80001428: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000142C: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80001430: nop

    // 0x80001434: andi        $t7, $t3, 0x8
    ctx->r15 = ctx->r11 & 0X8;
    // 0x80001438: beq         $t7, $zero, L_80001448
    if (ctx->r15 == 0) {
        // 0x8000143C: nop
    
            goto L_80001448;
    }
    // 0x8000143C: nop

    // 0x80001440: jal         0x80033788
    // 0x80001444: nop

    func_80033788(rdram, ctx);
        goto after_37;
    // 0x80001444: nop

    after_37:
L_80001448:
    // 0x80001448: jal         0x80032604
    // 0x8000144C: nop

    func_80032604(rdram, ctx);
        goto after_38;
    // 0x8000144C: nop

    after_38:
    // 0x80001450: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80001454: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x80001458: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000145C: jal         0x8000262C
    // 0x80001460: addiu       $a1, $t6, 0x580
    ctx->r5 = ADD32(ctx->r14, 0X580);
    func_8000262C(rdram, ctx);
        goto after_39;
    // 0x80001460: addiu       $a1, $t6, 0x580
    ctx->r5 = ADD32(ctx->r14, 0X580);
    after_39:
    // 0x80001464: jal         0x80002824
    // 0x80001468: nop

    func_80002824(rdram, ctx);
        goto after_40;
    // 0x80001468: nop

    after_40:
    // 0x8000146C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80001470: lh          $t9, 0x721C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X721C);
    // 0x80001474: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001478: bne         $t9, $at, L_80001488
    if (ctx->r25 != ctx->r1) {
        // 0x8000147C: nop
    
            goto L_80001488;
    }
    // 0x8000147C: nop

    // 0x80001480: jal         0x80034310
    // 0x80001484: nop

    func_80034310(rdram, ctx);
        goto after_41;
    // 0x80001484: nop

    after_41:
L_80001488:
    // 0x80001488: jal         0x8004DEA4
    // 0x8000148C: nop

    func_8004DEA4(rdram, ctx);
        goto after_42;
    // 0x8000148C: nop

    after_42:
    // 0x80001490: jal         0x800305A4
    // 0x80001494: nop

    func_800305A4(rdram, ctx);
        goto after_43;
    // 0x80001494: nop

    after_43:
    // 0x80001498: jal         0x8002A39C
    // 0x8000149C: nop

    func_8002A39C(rdram, ctx);
        goto after_44;
    // 0x8000149C: nop

    after_44:
    // 0x800014A0: jal         0x80082958
    // 0x800014A4: nop

    func_80082958(rdram, ctx);
        goto after_45;
    // 0x800014A4: nop

    after_45:
    // 0x800014A8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800014AC: lw          $t0, -0x73AC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73AC);
    // 0x800014B0: nop

    // 0x800014B4: beq         $t0, $zero, L_80001508
    if (ctx->r8 == 0) {
        // 0x800014B8: sw          $t0, 0x284($sp)
        MEM_W(0X284, ctx->r29) = ctx->r8;
            goto L_80001508;
    }
    // 0x800014B8: sw          $t0, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r8;
L_800014BC:
    // 0x800014BC: jal         0x800C1754
    // 0x800014C0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_46;
    // 0x800014C0: nop

    after_46:
    // 0x800014C4: lw          $a0, 0x284($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X284);
    // 0x800014C8: jal         0x8009A14C
    // 0x800014CC: nop

    func_8009A14C(rdram, ctx);
        goto after_47;
    // 0x800014CC: nop

    after_47:
    // 0x800014D0: lw          $a0, 0x284($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X284);
    // 0x800014D4: jal         0x800997D8
    // 0x800014D8: nop

    func_800997D8(rdram, ctx);
        goto after_48;
    // 0x800014D8: nop

    after_48:
    // 0x800014DC: jal         0x800C1A28
    // 0x800014E0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_49;
    // 0x800014E0: nop

    after_49:
    // 0x800014E4: lw          $t8, 0x284($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X284);
    // 0x800014E8: nop

    // 0x800014EC: lw          $t4, 0x14C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X14C);
    // 0x800014F0: nop

    // 0x800014F4: sw          $t4, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r12;
    // 0x800014F8: lw          $t5, 0x284($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X284);
    // 0x800014FC: nop

    // 0x80001500: bne         $t5, $zero, L_800014BC
    if (ctx->r13 != 0) {
        // 0x80001504: nop
    
            goto L_800014BC;
    }
    // 0x80001504: nop

L_80001508:
    // 0x80001508: sw          $zero, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = 0;
    // 0x8000150C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80001510: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80001514: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x80001518: nop

    // 0x8000151C: andi        $t3, $t1, 0x4000
    ctx->r11 = ctx->r9 & 0X4000;
    // 0x80001520: bne         $t3, $zero, L_800015D8
    if (ctx->r11 != 0) {
        // 0x80001524: nop
    
            goto L_800015D8;
    }
    // 0x80001524: nop

    // 0x80001528: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8000152C: lw          $t7, 0x72DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72DC);
    // 0x80001530: nop

    // 0x80001534: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x80001538: bne         $t6, $zero, L_800015D8
    if (ctx->r14 != 0) {
        // 0x8000153C: nop
    
            goto L_800015D8;
    }
    // 0x8000153C: nop

    // 0x80001540: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x80001544: nop

    // 0x80001548: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x8000154C: bne         $t0, $zero, L_800015D8
    if (ctx->r8 != 0) {
        // 0x80001550: nop
    
            goto L_800015D8;
    }
    // 0x80001550: nop

    // 0x80001554: andi        $t8, $t9, 0x400
    ctx->r24 = ctx->r25 & 0X400;
    // 0x80001558: bne         $t8, $zero, L_800015D8
    if (ctx->r24 != 0) {
        // 0x8000155C: nop
    
            goto L_800015D8;
    }
    // 0x8000155C: nop

    // 0x80001560: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80001564: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80001568: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8000156C: lhu         $t1, 0x11A4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X11A4);
    // 0x80001570: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80001574: nop

    // 0x80001578: and         $t3, $t5, $t1
    ctx->r11 = ctx->r13 & ctx->r9;
    // 0x8000157C: beq         $t3, $zero, L_800015D8
    if (ctx->r11 == 0) {
        // 0x80001580: nop
    
            goto L_800015D8;
    }
    // 0x80001580: nop

    // 0x80001584: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80001588: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8000158C: nop

    // 0x80001590: bgez        $t7, L_800015AC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80001594: nop
    
            goto L_800015AC;
    }
    // 0x80001594: nop

    // 0x80001598: lw          $t6, 0x41C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X41C);
    // 0x8000159C: nop

    // 0x800015A0: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x800015A4: b           L_800015D8
    // 0x800015A8: sw          $t2, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r10;
        goto L_800015D8;
    // 0x800015A8: sw          $t2, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r10;
L_800015AC:
    // 0x800015AC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800015B0: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x800015B4: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x800015B8: nop

    // 0x800015BC: andi        $t8, $t9, 0x4000
    ctx->r24 = ctx->r25 & 0X4000;
    // 0x800015C0: beq         $t8, $zero, L_800015D8
    if (ctx->r24 == 0) {
        // 0x800015C4: nop
    
            goto L_800015D8;
    }
    // 0x800015C4: nop

    // 0x800015C8: lw          $t4, 0x41C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X41C);
    // 0x800015CC: nop

    // 0x800015D0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800015D4: sw          $t5, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r13;
L_800015D8:
    // 0x800015D8: lw          $t1, 0x41C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X41C);
    // 0x800015DC: nop

    // 0x800015E0: beq         $t1, $zero, L_800016C4
    if (ctx->r9 == 0) {
        // 0x800015E4: nop
    
            goto L_800016C4;
    }
    // 0x800015E4: nop

    // 0x800015E8: jal         0x80098BB8
    // 0x800015EC: nop

    func_80098BB8(rdram, ctx);
        goto after_50;
    // 0x800015EC: nop

    after_50:
    // 0x800015F0: sw          $zero, 0x424($sp)
    MEM_W(0X424, ctx->r29) = 0;
    // 0x800015F4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800015F8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800015FC: jal         0x80021FF8
    // 0x80001600: addiu       $a2, $zero, 0x3FFF
    ctx->r6 = ADD32(0, 0X3FFF);
    func_80021FF8(rdram, ctx);
        goto after_51;
    // 0x80001600: addiu       $a2, $zero, 0x3FFF
    ctx->r6 = ADD32(0, 0X3FFF);
    after_51:
    // 0x80001604: addiu       $t3, $sp, 0x38
    ctx->r11 = ADD32(ctx->r29, 0X38);
    // 0x80001608: sw          $t3, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r11;
    // 0x8000160C: lw          $t7, 0x420($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X420);
    // 0x80001610: nop

    // 0x80001614: beq         $t7, $zero, L_80001634
    if (ctx->r15 == 0) {
        // 0x80001618: nop
    
            goto L_80001634;
    }
    // 0x80001618: nop

    // 0x8000161C: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80001620: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80001624: jal         0x800B1BC8
    // 0x80001628: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    func_800B1BC8(rdram, ctx);
        goto after_52;
    // 0x80001628: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    after_52:
    // 0x8000162C: b           L_80001640
    // 0x80001630: nop

        goto L_80001640;
    // 0x80001630: nop

L_80001634:
    // 0x80001634: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80001638: jal         0x80099E2C
    // 0x8000163C: nop

    func_80099E2C(rdram, ctx);
        goto after_53;
    // 0x8000163C: nop

    after_53:
L_80001640:
    // 0x80001640: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80001644: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80001648: jal         0x800B1B04
    // 0x8000164C: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    func_800B1B04(rdram, ctx);
        goto after_54;
    // 0x8000164C: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    after_54:
    // 0x80001650: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80001654: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80001658: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x8000165C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80001660: lui         $a2, 0x69
    ctx->r6 = S32(0X69 << 16);
    // 0x80001664: ori         $a2, $a2, 0x221
    ctx->r6 = ctx->r6 | 0X221;
    // 0x80001668: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    // 0x8000166C: addiu       $a3, $zero, 0x5F
    ctx->r7 = ADD32(0, 0X5F);
    // 0x80001670: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80001674: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80001678: jal         0x800B1F0C
    // 0x8000167C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_55;
    // 0x8000167C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_55:
    // 0x80001680: lw          $t6, 0x280($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X280);
    // 0x80001684: nop

    // 0x80001688: lw          $t2, 0xC0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0XC0);
    // 0x8000168C: nop

    // 0x80001690: ori         $t0, $t2, 0x208
    ctx->r8 = ctx->r10 | 0X208;
    // 0x80001694: sw          $t0, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r8;
    // 0x80001698: lw          $t8, 0x280($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X280);
    // 0x8000169C: lui         $t9, 0x7FFF
    ctx->r25 = S32(0X7FFF << 16);
    // 0x800016A0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800016A4: sw          $t9, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r25;
    // 0x800016A8: jal         0x800AD774
    // 0x800016AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800AD774(rdram, ctx);
        goto after_56;
    // 0x800016AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_56:
    // 0x800016B0: lw          $t4, 0x280($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X280);
    // 0x800016B4: nop

    // 0x800016B8: sh          $v0, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r2;
    // 0x800016BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800016C0: sw          $t5, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r13;
L_800016C4:
    // 0x800016C4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800016C8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800016CC: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x800016D0: nop

    // 0x800016D4: andi        $t7, $t3, 0x100
    ctx->r15 = ctx->r11 & 0X100;
    // 0x800016D8: bne         $t7, $zero, L_800016FC
    if (ctx->r15 != 0) {
        // 0x800016DC: nop
    
            goto L_800016FC;
    }
    // 0x800016DC: nop

    // 0x800016E0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800016E4: jal         0x8009A664
    // 0x800016E8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_57;
    // 0x800016E8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_57:
    // 0x800016EC: jal         0x8002C2F8
    // 0x800016F0: nop

    func_8002C2F8(rdram, ctx);
        goto after_58;
    // 0x800016F0: nop

    after_58:
    // 0x800016F4: b           L_80001710
    // 0x800016F8: nop

        goto L_80001710;
    // 0x800016F8: nop

L_800016FC:
    // 0x800016FC: jal         0x8002C2F8
    // 0x80001700: nop

    func_8002C2F8(rdram, ctx);
        goto after_59;
    // 0x80001700: nop

    after_59:
    // 0x80001704: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80001708: jal         0x8009A664
    // 0x8000170C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_60;
    // 0x8000170C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_60:
L_80001710:
    // 0x80001710: jal         0x8001635C
    // 0x80001714: nop

    func_8001635C(rdram, ctx);
        goto after_61;
    // 0x80001714: nop

    after_61:
    // 0x80001718: jal         0x800BE684
    // 0x8000171C: nop

    func_800BE684(rdram, ctx);
        goto after_62;
    // 0x8000171C: nop

    after_62:
    // 0x80001720: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80001724: lw          $t2, 0x72DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72DC);
    // 0x80001728: nop

    // 0x8000172C: andi        $t0, $t2, 0x1
    ctx->r8 = ctx->r10 & 0X1;
    // 0x80001730: beq         $t0, $zero, L_800017C0
    if (ctx->r8 == 0) {
        // 0x80001734: nop
    
            goto L_800017C0;
    }
    // 0x80001734: nop

    // 0x80001738: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8000173C: sw          $t6, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r14;
    // 0x80001740: jal         0x800C1754
    // 0x80001744: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_63;
    // 0x80001744: nop

    after_63:
    // 0x80001748: lui         $at, 0xC2B0
    ctx->r1 = S32(0XC2B0 << 16);
    // 0x8000174C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001750: lw          $t9, 0x280($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X280);
    // 0x80001754: nop

    // 0x80001758: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x8000175C: lui         $at, 0xC228
    ctx->r1 = S32(0XC228 << 16);
    // 0x80001760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001764: lw          $t8, 0x280($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X280);
    // 0x80001768: nop

    // 0x8000176C: swc1        $f6, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f6.u32l;
    // 0x80001770: jal         0x80031AC8
    // 0x80001774: nop

    func_80031AC8(rdram, ctx);
        goto after_64;
    // 0x80001774: nop

    after_64:
    // 0x80001778: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000177C: beq         $v0, $at, L_800017A0
    if (ctx->r2 == ctx->r1) {
        // 0x80001780: nop
    
            goto L_800017A0;
    }
    // 0x80001780: nop

    // 0x80001784: lw          $t4, 0x280($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X280);
    // 0x80001788: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8000178C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001790: lwc1        $f8, 0xD0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x80001794: nop

    // 0x80001798: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000179C: swc1        $f16, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f16.u32l;
L_800017A0:
    // 0x800017A0: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x800017A4: jal         0x8009A14C
    // 0x800017A8: nop

    func_8009A14C(rdram, ctx);
        goto after_65;
    // 0x800017A8: nop

    after_65:
    // 0x800017AC: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x800017B0: jal         0x800997D8
    // 0x800017B4: nop

    func_800997D8(rdram, ctx);
        goto after_66;
    // 0x800017B4: nop

    after_66:
    // 0x800017B8: jal         0x800C1A28
    // 0x800017BC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_67;
    // 0x800017BC: nop

    after_67:
L_800017C0:
    // 0x800017C0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800017C4: jal         0x8009A664
    // 0x800017C8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_68;
    // 0x800017C8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_68:
    // 0x800017CC: jal         0x800BE610
    // 0x800017D0: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_69;
    // 0x800017D0: nop

    after_69:
    // 0x800017D4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800017D8: lw          $t5, 0x1B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B4C);
    // 0x800017DC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800017E0: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x800017E4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800017E8: jal         0x8009908C
    // 0x800017EC: subu        $a1, $t1, $t5
    ctx->r5 = SUB32(ctx->r9, ctx->r13);
    CreateGfxTask(rdram, ctx);
        goto after_70;
    // 0x800017EC: subu        $a1, $t1, $t5
    ctx->r5 = SUB32(ctx->r9, ctx->r13);
    after_70:
    // 0x800017F0: lw          $t3, 0x414($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X414);
    // 0x800017F4: nop

    // 0x800017F8: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x800017FC: jal         0x80098D24
    // 0x80001800: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_71;
    // 0x80001800: nop

    after_71:
    // 0x80001804: jal         0x80099450
    // 0x80001808: nop

    func_80099450(rdram, ctx);
        goto after_72;
    // 0x80001808: nop

    after_72:
    // 0x8000180C: jal         0x80001F54
    // 0x80001810: nop

    func_80001F54(rdram, ctx);
        goto after_73;
    // 0x80001810: nop

    after_73:
    // 0x80001814: jal         0x800020A8
    // 0x80001818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800020A8(rdram, ctx);
        goto after_74;
    // 0x80001818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_74:
    // 0x8000181C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001820: bne         $v0, $at, L_80001854
    if (ctx->r2 != ctx->r1) {
        // 0x80001824: nop
    
            goto L_80001854;
    }
    // 0x80001824: nop

    // 0x80001828: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000182C: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80001830: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x80001834: nop

    // 0x80001838: ori         $t0, $t2, 0x2
    ctx->r8 = ctx->r10 | 0X2;
    // 0x8000183C: sh          $t0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r8;
    // 0x80001840: lw          $t6, 0x414($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X414);
    // 0x80001844: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x80001848: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8000184C: jal         0x800C1264
    // 0x80001850: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_75;
    // 0x80001850: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_75:
L_80001854:
    // 0x80001854: lw          $t9, 0x410($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X410);
    // 0x80001858: nop

    // 0x8000185C: addiu       $t8, $t9, 0x7FFF
    ctx->r24 = ADD32(ctx->r25, 0X7FFF);
    // 0x80001860: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80001864: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80001868: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8000186C: sw          $t4, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r12;
L_80001870:
    // 0x80001870: b           L_80001F2C
    // 0x80001874: nop

        goto L_80001F2C;
    // 0x80001874: nop

L_80001878:
    // 0x80001878: lw          $t1, 0x410($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X410);
    // 0x8000187C: nop

    // 0x80001880: addiu       $t5, $t1, 0x7FFF
    ctx->r13 = ADD32(ctx->r9, 0X7FFF);
    // 0x80001884: lw          $t5, 0x2ED($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2ED);
    // 0x80001888: nop

    // 0x8000188C: beq         $t5, $zero, L_800018D0
    if (ctx->r13 == 0) {
        // 0x80001890: nop
    
            goto L_800018D0;
    }
    // 0x80001890: nop

    // 0x80001894: jal         0x80099520
    // 0x80001898: nop

    func_80099520(rdram, ctx);
        goto after_76;
    // 0x80001898: nop

    after_76:
    // 0x8000189C: lw          $t3, 0x410($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X410);
    // 0x800018A0: nop

    // 0x800018A4: addiu       $t2, $t3, 0x7FFF
    ctx->r10 = ADD32(ctx->r11, 0X7FFF);
    // 0x800018A8: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800018AC: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x800018B0: addiu       $t0, $t2, -0x1
    ctx->r8 = ADD32(ctx->r10, -0X1);
    // 0x800018B4: sw          $t0, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r8;
    // 0x800018B8: jal         0x800C40D0
    // 0x800018BC: nop

    osGetTime_recomp(rdram, ctx);
        goto after_77;
    // 0x800018BC: nop

    after_77:
    // 0x800018C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800018C4: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x800018C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800018CC: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
L_800018D0:
    // 0x800018D0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800018D4: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800018D8: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800018DC: nop

    // 0x800018E0: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x800018E4: beq         $t8, $zero, L_80001954
    if (ctx->r24 == 0) {
        // 0x800018E8: nop
    
            goto L_80001954;
    }
    // 0x800018E8: nop

    // 0x800018EC: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x800018F0: jal         0x800065BC
    // 0x800018F4: nop

    func_800065BC(rdram, ctx);
        goto after_78;
    // 0x800018F4: nop

    after_78:
    // 0x800018F8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800018FC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80001900: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x80001904: lh          $t4, 0x7320($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7320);
    // 0x80001908: nop

    // 0x8000190C: bne         $t4, $t9, L_80001930
    if (ctx->r12 != ctx->r25) {
        // 0x80001910: nop
    
            goto L_80001930;
    }
    // 0x80001910: nop

    // 0x80001914: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80001918: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000191C: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80001920: lh          $t1, 0x7338($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7338);
    // 0x80001924: nop

    // 0x80001928: beq         $t1, $t5, L_80001954
    if (ctx->r9 == ctx->r13) {
        // 0x8000192C: nop
    
            goto L_80001954;
    }
    // 0x8000192C: nop

L_80001930:
    // 0x80001930: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80001934: lh          $t2, 0x7320($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7320);
    // 0x80001938: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000193C: ori         $t0, $t2, 0x8000
    ctx->r8 = ctx->r10 | 0X8000;
    // 0x80001940: sh          $t0, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r8;
    // 0x80001944: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80001948: lh          $t3, 0x7338($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7338);
    // 0x8000194C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001950: sh          $t3, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r11;
L_80001954:
    // 0x80001954: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80001958: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000195C: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x80001960: nop

    // 0x80001964: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80001968: beq         $t8, $zero, L_8000199C
    if (ctx->r24 == 0) {
        // 0x8000196C: nop
    
            goto L_8000199C;
    }
    // 0x8000196C: nop

    // 0x80001970: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80001974: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80001978: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x8000197C: nop

    // 0x80001980: ori         $t1, $t9, 0x4
    ctx->r9 = ctx->r25 | 0X4;
    // 0x80001984: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
    // 0x80001988: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x8000198C: jal         0x80005880
    // 0x80001990: nop

    func_80005880(rdram, ctx);
        goto after_79;
    // 0x80001990: nop

    after_79:
    // 0x80001994: b           L_80001F2C
    // 0x80001998: nop

        goto L_80001F2C;
    // 0x80001998: nop

L_8000199C:
    // 0x8000199C: b           L_80001F2C
    // 0x800019A0: nop

        goto L_80001F2C;
    // 0x800019A0: nop

L_800019A4:
    // 0x800019A4: jal         0x80032604
    // 0x800019A8: nop

    func_80032604(rdram, ctx);
        goto after_80;
    // 0x800019A8: nop

    after_80:
    // 0x800019AC: lw          $t5, 0x410($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X410);
    // 0x800019B0: nop

    // 0x800019B4: addiu       $t2, $t5, 0x7FFF
    ctx->r10 = ADD32(ctx->r13, 0X7FFF);
    // 0x800019B8: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800019BC: nop

    // 0x800019C0: bgtz        $t2, L_80001A4C
    if (SIGNED(ctx->r10) > 0) {
        // 0x800019C4: nop
    
            goto L_80001A4C;
    }
    // 0x800019C4: nop

    // 0x800019C8: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800019CC: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x800019D0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800019D4: lhu         $t7, 0x11A4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X11A4);
    // 0x800019D8: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x800019DC: nop

    // 0x800019E0: and         $t6, $t3, $t7
    ctx->r14 = ctx->r11 & ctx->r15;
    // 0x800019E4: beq         $t6, $zero, L_80001A4C
    if (ctx->r14 == 0) {
        // 0x800019E8: nop
    
            goto L_80001A4C;
    }
    // 0x800019E8: nop

    // 0x800019EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800019F0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800019F4: jal         0x80021FF8
    // 0x800019F8: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_80021FF8(rdram, ctx);
        goto after_81;
    // 0x800019F8: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_81:
    // 0x800019FC: jal         0x80098BF4
    // 0x80001A00: nop

    func_80098BF4(rdram, ctx);
        goto after_82;
    // 0x80001A00: nop

    after_82:
    // 0x80001A04: lw          $t8, 0x410($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X410);
    // 0x80001A08: nop

    // 0x80001A0C: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x80001A10: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80001A14: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80001A18: nop

    // 0x80001A1C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80001A20: jal         0x800C13B8
    // 0x80001A24: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_83;
    // 0x80001A24: nop

    after_83:
    // 0x80001A28: jal         0x80098820
    // 0x80001A2C: nop

    func_80098820(rdram, ctx);
        goto after_84;
    // 0x80001A2C: nop

    after_84:
    // 0x80001A30: lw          $t1, 0x414($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X414);
    // 0x80001A34: nop

    // 0x80001A38: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80001A3C: jal         0x80098D24
    // 0x80001A40: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_85;
    // 0x80001A40: nop

    after_85:
    // 0x80001A44: b           L_80001F2C
    // 0x80001A48: nop

        goto L_80001F2C;
    // 0x80001A48: nop

L_80001A4C:
    // 0x80001A4C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80001A50: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80001A54: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80001A58: nop

    // 0x80001A5C: andi        $t2, $t5, 0x20
    ctx->r10 = ctx->r13 & 0X20;
    // 0x80001A60: beq         $t2, $zero, L_80001B0C
    if (ctx->r10 == 0) {
        // 0x80001A64: nop
    
            goto L_80001B0C;
    }
    // 0x80001A64: nop

    // 0x80001A68: jal         0x80096474
    // 0x80001A6C: nop

    func_80096474(rdram, ctx);
        goto after_86;
    // 0x80001A6C: nop

    after_86:
    // 0x80001A70: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80001A74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001A78: sw          $t0, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r8;
    // 0x80001A7C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80001A80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001A84: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
    // 0x80001A88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001A8C: sh          $zero, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = 0;
    // 0x80001A90: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80001A94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80001A98: sw          $t7, 0x6C08($at)
    MEM_W(0X6C08, ctx->r1) = ctx->r15;
    // 0x80001A9C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80001AA0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80001AA4: sw          $t6, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r14;
    // 0x80001AA8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80001AAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80001AB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001AB4: swc1        $f18, -0x4CBC($at)
    MEM_W(-0X4CBC, ctx->r1) = ctx->f18.u32l;
    // 0x80001AB8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80001ABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001AC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001AC4: swc1        $f4, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f4.u32l;
    // 0x80001AC8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80001ACC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001AD0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001AD4: swc1        $f6, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f6.u32l;
    // 0x80001AD8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80001ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001AE0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001AE4: swc1        $f8, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f8.u32l;
    // 0x80001AE8: jal         0x80090728
    // 0x80001AEC: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_80090728(rdram, ctx);
        goto after_87;
    // 0x80001AEC: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_87:
    // 0x80001AF0: jal         0x800C4160
    // 0x80001AF4: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_88;
    // 0x80001AF4: nop

    after_88:
    // 0x80001AF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80001AFC: jal         0x8008ECCC
    // 0x80001B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_89;
    // 0x80001B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x80001B04: jal         0x800967D8
    // 0x80001B08: nop

    func_800967D8(rdram, ctx);
        goto after_90;
    // 0x80001B08: nop

    after_90:
L_80001B0C:
    // 0x80001B0C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80001B10: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80001B14: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80001B18: nop

    // 0x80001B1C: andi        $t1, $t9, 0x4000
    ctx->r9 = ctx->r25 & 0X4000;
    // 0x80001B20: beq         $t1, $zero, L_80001D90
    if (ctx->r9 == 0) {
        // 0x80001B24: nop
    
            goto L_80001D90;
    }
    // 0x80001B24: nop

    // 0x80001B28: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80001B2C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80001B30: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80001B34: lhu         $t2, 0x1038($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1038);
    // 0x80001B38: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80001B3C: nop

    // 0x80001B40: and         $t0, $t5, $t2
    ctx->r8 = ctx->r13 & ctx->r10;
    // 0x80001B44: beq         $t0, $zero, L_80001B84
    if (ctx->r8 == 0) {
        // 0x80001B48: nop
    
            goto L_80001B84;
    }
    // 0x80001B48: nop

    // 0x80001B4C: jal         0x80098868
    // 0x80001B50: nop

    func_80098868(rdram, ctx);
        goto after_91;
    // 0x80001B50: nop

    after_91:
    // 0x80001B54: jal         0x80098C1C
    // 0x80001B58: nop

    func_80098C1C(rdram, ctx);
        goto after_92;
    // 0x80001B58: nop

    after_92:
    // 0x80001B5C: jal         0x80098820
    // 0x80001B60: nop

    func_80098820(rdram, ctx);
        goto after_93;
    // 0x80001B60: nop

    after_93:
    // 0x80001B64: lw          $t3, 0x414($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X414);
    // 0x80001B68: nop

    // 0x80001B6C: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80001B70: jal         0x80098D24
    // 0x80001B74: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_94;
    // 0x80001B74: nop

    after_94:
    // 0x80001B78: sw          $zero, 0x424($sp)
    MEM_W(0X424, ctx->r29) = 0;
    // 0x80001B7C: b           L_80001F2C
    // 0x80001B80: nop

        goto L_80001F2C;
    // 0x80001B80: nop

L_80001B84:
    // 0x80001B84: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80001B88: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80001B8C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80001B90: lhu         $t8, 0x1038($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1038);
    // 0x80001B94: lhu         $t6, 0x2C($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X2C);
    // 0x80001B98: nop

    // 0x80001B9C: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x80001BA0: beq         $t9, $zero, L_80001BF4
    if (ctx->r25 == 0) {
        // 0x80001BA4: nop
    
            goto L_80001BF4;
    }
    // 0x80001BA4: nop

    // 0x80001BA8: lw          $t1, 0x424($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X424);
    // 0x80001BAC: nop

    // 0x80001BB0: xori        $t4, $t1, 0x1
    ctx->r12 = ctx->r9 ^ 0X1;
    // 0x80001BB4: sw          $t4, 0x424($sp)
    MEM_W(0X424, ctx->r29) = ctx->r12;
    // 0x80001BB8: lw          $t5, 0x424($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X424);
    // 0x80001BBC: nop

    // 0x80001BC0: beq         $t5, $zero, L_80001BEC
    if (ctx->r13 == 0) {
        // 0x80001BC4: nop
    
            goto L_80001BEC;
    }
    // 0x80001BC4: nop

    // 0x80001BC8: jal         0x80098868
    // 0x80001BCC: nop

    func_80098868(rdram, ctx);
        goto after_95;
    // 0x80001BCC: nop

    after_95:
    // 0x80001BD0: jal         0x80098C1C
    // 0x80001BD4: nop

    func_80098C1C(rdram, ctx);
        goto after_96;
    // 0x80001BD4: nop

    after_96:
    // 0x80001BD8: lw          $t2, 0x414($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X414);
    // 0x80001BDC: nop

    // 0x80001BE0: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80001BE4: jal         0x80098D24
    // 0x80001BE8: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_97;
    // 0x80001BE8: nop

    after_97:
L_80001BEC:
    // 0x80001BEC: b           L_80001F2C
    // 0x80001BF0: nop

        goto L_80001F2C;
    // 0x80001BF0: nop

L_80001BF4:
    // 0x80001BF4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80001BF8: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80001BFC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80001C00: lhu         $t7, 0x1042($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1042);
    // 0x80001C04: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x80001C08: nop

    // 0x80001C0C: and         $t6, $t3, $t7
    ctx->r14 = ctx->r11 & ctx->r15;
    // 0x80001C10: beq         $t6, $zero, L_80001D90
    if (ctx->r14 == 0) {
        // 0x80001C14: nop
    
            goto L_80001D90;
    }
    // 0x80001C14: nop

    // 0x80001C18: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80001C1C: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80001C20: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80001C24: nop

    // 0x80001C28: ori         $t1, $t9, 0x8004
    ctx->r9 = ctx->r25 | 0X8004;
    // 0x80001C2C: sh          $t1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r9;
    // 0x80001C30: jal         0x80098CD8
    // 0x80001C34: nop

    func_80098CD8(rdram, ctx);
        goto after_98;
    // 0x80001C34: nop

    after_98:
    // 0x80001C38: jal         0x80098BF4
    // 0x80001C3C: nop

    func_80098BF4(rdram, ctx);
        goto after_99;
    // 0x80001C3C: nop

    after_99:
    // 0x80001C40: jal         0x80098820
    // 0x80001C44: nop

    func_80098820(rdram, ctx);
        goto after_100;
    // 0x80001C44: nop

    after_100:
    // 0x80001C48: jal         0x80098868
    // 0x80001C4C: nop

    func_80098868(rdram, ctx);
        goto after_101;
    // 0x80001C4C: nop

    after_101:
    // 0x80001C50: lw          $t4, 0x410($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X410);
    // 0x80001C54: nop

    // 0x80001C58: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80001C5C: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80001C60: lw          $t5, 0x414($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X414);
    // 0x80001C64: nop

    // 0x80001C68: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80001C6C: jal         0x800C13B8
    // 0x80001C70: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_102;
    // 0x80001C70: nop

    after_102:
    // 0x80001C74: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x80001C78: jal         0x800065BC
    // 0x80001C7C: nop

    func_800065BC(rdram, ctx);
        goto after_103;
    // 0x80001C7C: nop

    after_103:
    // 0x80001C80: jal         0x80098CFC
    // 0x80001C84: nop

    func_80098CFC(rdram, ctx);
        goto after_104;
    // 0x80001C84: nop

    after_104:
    // 0x80001C88: jal         0x80098BB8
    // 0x80001C8C: nop

    func_80098BB8(rdram, ctx);
        goto after_105;
    // 0x80001C8C: nop

    after_105:
    // 0x80001C90: jal         0x80098C1C
    // 0x80001C94: nop

    func_80098C1C(rdram, ctx);
        goto after_106;
    // 0x80001C94: nop

    after_106:
    // 0x80001C98: jal         0x80098868
    // 0x80001C9C: nop

    func_80098868(rdram, ctx);
        goto after_107;
    // 0x80001C9C: nop

    after_107:
    // 0x80001CA0: jal         0x80098820
    // 0x80001CA4: nop

    func_80098820(rdram, ctx);
        goto after_108;
    // 0x80001CA4: nop

    after_108:
    // 0x80001CA8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80001CAC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80001CB0: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x80001CB4: lh          $t2, 0x7320($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7320);
    // 0x80001CB8: nop

    // 0x80001CBC: bne         $t2, $t0, L_80001CE0
    if (ctx->r10 != ctx->r8) {
        // 0x80001CC0: nop
    
            goto L_80001CE0;
    }
    // 0x80001CC0: nop

    // 0x80001CC4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80001CC8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80001CCC: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x80001CD0: lh          $t3, 0x7338($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7338);
    // 0x80001CD4: nop

    // 0x80001CD8: beq         $t3, $t7, L_80001D1C
    if (ctx->r11 == ctx->r15) {
        // 0x80001CDC: nop
    
            goto L_80001D1C;
    }
    // 0x80001CDC: nop

L_80001CE0:
    // 0x80001CE0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80001CE4: lh          $t6, 0x7320($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7320);
    // 0x80001CE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001CEC: ori         $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 | 0X8000;
    // 0x80001CF0: sh          $t9, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r25;
    // 0x80001CF4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80001CF8: lh          $t1, 0x7338($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7338);
    // 0x80001CFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001D00: sh          $t1, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r9;
    // 0x80001D04: jal         0x80098BF4
    // 0x80001D08: nop

    func_80098BF4(rdram, ctx);
        goto after_109;
    // 0x80001D08: nop

    after_109:
    // 0x80001D0C: jal         0x80098820
    // 0x80001D10: nop

    func_80098820(rdram, ctx);
        goto after_110;
    // 0x80001D10: nop

    after_110:
    // 0x80001D14: b           L_80001D74
    // 0x80001D18: nop

        goto L_80001D74;
    // 0x80001D18: nop

L_80001D1C:
    // 0x80001D1C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80001D20: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80001D24: lhu         $t4, 0x0($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X0);
    // 0x80001D28: nop

    // 0x80001D2C: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80001D30: beq         $t5, $zero, L_80001D74
    if (ctx->r13 == 0) {
        // 0x80001D34: nop
    
            goto L_80001D74;
    }
    // 0x80001D34: nop

    // 0x80001D38: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80001D3C: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80001D40: lhu         $t0, 0x0($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0X0);
    // 0x80001D44: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80001D48: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x80001D4C: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x80001D50: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80001D54: lh          $t7, 0x7254($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7254);
    // 0x80001D58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001D5C: ori         $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 | 0X8000;
    // 0x80001D60: sh          $t6, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r14;
    // 0x80001D64: jal         0x80098BF4
    // 0x80001D68: nop

    func_80098BF4(rdram, ctx);
        goto after_111;
    // 0x80001D68: nop

    after_111:
    // 0x80001D6C: jal         0x80098820
    // 0x80001D70: nop

    func_80098820(rdram, ctx);
        goto after_112;
    // 0x80001D70: nop

    after_112:
L_80001D74:
    // 0x80001D74: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80001D78: nop

    // 0x80001D7C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80001D80: jal         0x80098D24
    // 0x80001D84: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_113;
    // 0x80001D84: nop

    after_113:
    // 0x80001D88: b           L_80001F2C
    // 0x80001D8C: nop

        goto L_80001F2C;
    // 0x80001D8C: nop

L_80001D90:
    // 0x80001D90: lw          $t1, 0x414($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X414);
    // 0x80001D94: nop

    // 0x80001D98: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80001D9C: jal         0x80098D24
    // 0x80001DA0: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_114;
    // 0x80001DA0: nop

    after_114:
    // 0x80001DA4: b           L_80001F2C
    // 0x80001DA8: nop

        goto L_80001F2C;
    // 0x80001DA8: nop

L_80001DAC:
    // 0x80001DAC: lw          $t8, 0x414($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X414);
    // 0x80001DB0: addiu       $a1, $sp, 0x40C
    ctx->r5 = ADD32(ctx->r29, 0X40C);
    // 0x80001DB4: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80001DB8: jal         0x800C143C
    // 0x80001DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_115;
    // 0x80001DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_115:
    // 0x80001DC0: lw          $t4, 0x40C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40C);
    // 0x80001DC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001DC8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80001DCC: nop

    // 0x80001DD0: bne         $t5, $at, L_80001E0C
    if (ctx->r13 != ctx->r1) {
        // 0x80001DD4: nop
    
            goto L_80001E0C;
    }
    // 0x80001DD4: nop

    // 0x80001DD8: b           L_80001DE0
    // 0x80001DDC: nop

        goto L_80001DE0;
    // 0x80001DDC: nop

L_80001DE0:
    // 0x80001DE0: jal         0x80099520
    // 0x80001DE4: nop

    func_80099520(rdram, ctx);
        goto after_116;
    // 0x80001DE4: nop

    after_116:
    // 0x80001DE8: lw          $t0, 0x410($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X410);
    // 0x80001DEC: nop

    // 0x80001DF0: addiu       $t3, $t0, 0x7FFF
    ctx->r11 = ADD32(ctx->r8, 0X7FFF);
    // 0x80001DF4: lw          $t3, 0x2ED($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2ED);
    // 0x80001DF8: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x80001DFC: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x80001E00: sw          $t2, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r10;
    // 0x80001E04: b           L_80001E0C
    // 0x80001E08: nop

        goto L_80001E0C;
    // 0x80001E08: nop

L_80001E0C:
    // 0x80001E0C: lw          $t7, 0x410($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X410);
    // 0x80001E10: nop

    // 0x80001E14: addiu       $t6, $t7, 0x7FFF
    ctx->r14 = ADD32(ctx->r15, 0X7FFF);
    // 0x80001E18: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x80001E1C: nop

    // 0x80001E20: bne         $t6, $zero, L_80001E30
    if (ctx->r14 != 0) {
        // 0x80001E24: nop
    
            goto L_80001E30;
    }
    // 0x80001E24: nop

    // 0x80001E28: b           L_80001E38
    // 0x80001E2C: nop

        goto L_80001E38;
    // 0x80001E2C: nop

L_80001E30:
    // 0x80001E30: b           L_80001DAC
    // 0x80001E34: nop

        goto L_80001DAC;
    // 0x80001E34: nop

L_80001E38:
    // 0x80001E38: jal         0x80005460
    // 0x80001E3C: nop

    func_80005460(rdram, ctx);
        goto after_117;
    // 0x80001E3C: nop

    after_117:
    // 0x80001E40: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80001E44: lw          $a1, -0x73E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73E8);
    // 0x80001E48: addiu       $a0, $sp, 0x288
    ctx->r4 = ADD32(ctx->r29, 0X288);
    // 0x80001E4C: jal         0x800BCFCC
    // 0x80001E50: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    SysMem_Copy8(rdram, ctx);
        goto after_118;
    // 0x80001E50: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    after_118:
    // 0x80001E54: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80001E58: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80001E5C: lh          $a1, -0x73E4($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73E4);
    // 0x80001E60: lh          $a0, -0x73F0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X73F0);
    // 0x80001E64: jal         0x80005124
    // 0x80001E68: nop

    func_80005124(rdram, ctx);
        goto after_119;
    // 0x80001E68: nop

    after_119:
    // 0x80001E6C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80001E70: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x80001E74: lwc1        $f10, 0x354($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X354);
    // 0x80001E78: nop

    // 0x80001E7C: swc1        $f10, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f10.u32l;
    // 0x80001E80: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80001E84: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x80001E88: lwc1        $f16, 0x358($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X358);
    // 0x80001E8C: nop

    // 0x80001E90: swc1        $f16, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f16.u32l;
    // 0x80001E94: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80001E98: lh          $t8, -0x73F0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X73F0);
    // 0x80001E9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001EA0: sh          $t8, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r24;
    // 0x80001EA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001EA8: sh          $t8, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r24;
    // 0x80001EAC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80001EB0: lh          $t4, -0x73E4($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X73E4);
    // 0x80001EB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001EB8: sh          $t4, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r12;
    // 0x80001EBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001EC0: sh          $t4, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r12;
    // 0x80001EC4: lw          $t5, 0x410($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X410);
    // 0x80001EC8: nop

    // 0x80001ECC: addiu       $at, $t5, 0x7FFF
    ctx->r1 = ADD32(ctx->r13, 0X7FFF);
    // 0x80001ED0: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80001ED4: lw          $t3, 0x414($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X414);
    // 0x80001ED8: nop

    // 0x80001EDC: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80001EE0: jal         0x800C13B8
    // 0x80001EE4: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_120;
    // 0x80001EE4: nop

    after_120:
    // 0x80001EE8: jal         0x80098820
    // 0x80001EEC: nop

    func_80098820(rdram, ctx);
        goto after_121;
    // 0x80001EEC: nop

    after_121:
    // 0x80001EF0: lw          $t2, 0x414($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X414);
    // 0x80001EF4: nop

    // 0x80001EF8: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x80001EFC: b           L_80001F2C
    // 0x80001F00: nop

        goto L_80001F2C;
    // 0x80001F00: nop

L_80001F04:
    // 0x80001F04: jal         0x800029BC
    // 0x80001F08: nop

    func_800029BC(rdram, ctx);
        goto after_122;
    // 0x80001F08: nop

    after_122:
L_80001F0C:
    // 0x80001F0C: b           L_80001F0C
    pause_self(rdram);
    // 0x80001F10: nop

    // 0x80001F14: b           L_80001F2C
    // 0x80001F18: nop

        goto L_80001F2C;
    // 0x80001F18: nop

L_80001F1C:
    // 0x80001F1C: b           L_80001F2C
    // 0x80001F20: nop

        goto L_80001F2C;
    // 0x80001F20: nop

L_80001F24:
    // 0x80001F24: b           L_80001F2C
    // 0x80001F28: nop

        goto L_80001F2C;
    // 0x80001F28: nop

L_80001F2C:
    // 0x80001F2C: lw          $t0, 0x428($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X428);
    // 0x80001F30: nop

    // 0x80001F34: beq         $t0, $zero, L_80000D30
    if (ctx->r8 == 0) {
        // 0x80001F38: nop
    
            goto L_80000D30;
    }
    // 0x80001F38: nop

L_80001F3C:
    // 0x80001F3C: b           L_80001F44
    // 0x80001F40: nop

        goto L_80001F44;
    // 0x80001F40: nop

L_80001F44:
    // 0x80001F44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80001F48: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80001F4C: jr          $ra
    // 0x80001F50: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
    return;
    // 0x80001F50: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
;}
RECOMP_FUNC void func_8006C330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C338: jal         0x8005F064
    // 0x8006C33C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C33C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_0:
    // 0x8006C340: b           L_8006C350
    // 0x8006C344: nop

        goto L_8006C350;
    // 0x8006C344: nop

    // 0x8006C348: b           L_8006C350
    // 0x8006C34C: nop

        goto L_8006C350;
    // 0x8006C34C: nop

L_8006C350:
    // 0x8006C350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C358: jr          $ra
    // 0x8006C35C: nop

    return;
    // 0x8006C35C: nop

;}
RECOMP_FUNC void func_80076760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076768: jal         0x80061348
    // 0x8007676C: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007676C: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x80076770: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076774: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076778: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007677C: beq         $v0, $zero, L_800767B4
    if (ctx->r2 == 0) {
        // 0x80076780: nop
    
            goto L_800767B4;
    }
    // 0x80076780: nop

    // 0x80076784: jal         0x80061348
    // 0x80076788: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076788: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x8007678C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80076790: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076794: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076798: beq         $v0, $zero, L_800767B4
    if (ctx->r2 == 0) {
        // 0x8007679C: nop
    
            goto L_800767B4;
    }
    // 0x8007679C: nop

    // 0x800767A0: jal         0x80061348
    // 0x800767A4: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800767A4: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x800767A8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800767AC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800767B0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800767B4:
    // 0x800767B4: b           L_800767C4
    // 0x800767B8: nop

        goto L_800767C4;
    // 0x800767B8: nop

    // 0x800767BC: b           L_800767C4
    // 0x800767C0: nop

        goto L_800767C4;
    // 0x800767C0: nop

L_800767C4:
    // 0x800767C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800767C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800767CC: jr          $ra
    // 0x800767D0: nop

    return;
    // 0x800767D0: nop

;}
RECOMP_FUNC void func_8004DEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DEA4: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8004DEA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004DEAC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004DEB0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004DEB4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004DEB8: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004DEBC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004DEC0: nop

    // 0x8004DEC4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8004DEC8: beq         $t8, $zero, L_8004DED8
    if (ctx->r24 == 0) {
        // 0x8004DECC: nop
    
            goto L_8004DED8;
    }
    // 0x8004DECC: nop

    // 0x8004DED0: b           L_8004EC94
    // 0x8004DED4: nop

        goto L_8004EC94;
    // 0x8004DED4: nop

L_8004DED8:
    // 0x8004DED8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004DEDC: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8004DEE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004DEE4: bne         $t9, $at, L_8004DF08
    if (ctx->r25 != ctx->r1) {
        // 0x8004DEE8: nop
    
            goto L_8004DF08;
    }
    // 0x8004DEE8: nop

    // 0x8004DEEC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004DEF0: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004DEF4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8004DEF8: bne         $t0, $at, L_8004DF08
    if (ctx->r8 != ctx->r1) {
        // 0x8004DEFC: nop
    
            goto L_8004DF08;
    }
    // 0x8004DEFC: nop

    // 0x8004DF00: jal         0x8005CDBC
    // 0x8004DF04: nop

    func_8005CDBC(rdram, ctx);
        goto after_0;
    // 0x8004DF04: nop

    after_0:
L_8004DF08:
    // 0x8004DF08: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004DF0C: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x8004DF10: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8004DF14: bne         $t1, $at, L_8004DF84
    if (ctx->r9 != ctx->r1) {
        // 0x8004DF18: nop
    
            goto L_8004DF84;
    }
    // 0x8004DF18: nop

    // 0x8004DF1C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004DF20: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x8004DF24: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004DF28: bne         $t2, $at, L_8004DF84
    if (ctx->r10 != ctx->r1) {
        // 0x8004DF2C: nop
    
            goto L_8004DF84;
    }
    // 0x8004DF2C: nop

    // 0x8004DF30: jal         0x8005F064
    // 0x8004DF34: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x8004DF34: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    after_1:
    // 0x8004DF38: bne         $v0, $zero, L_8004DF84
    if (ctx->r2 != 0) {
        // 0x8004DF3C: nop
    
            goto L_8004DF84;
    }
    // 0x8004DF3C: nop

    // 0x8004DF40: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004DF44: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004DF48: nop

    // 0x8004DF4C: lh          $t4, 0x48($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X48);
    // 0x8004DF50: nop

    // 0x8004DF54: slti        $at, $t4, 0x32
    ctx->r1 = SIGNED(ctx->r12) < 0X32 ? 1 : 0;
    // 0x8004DF58: bne         $at, $zero, L_8004DF84
    if (ctx->r1 != 0) {
        // 0x8004DF5C: nop
    
            goto L_8004DF84;
    }
    // 0x8004DF5C: nop

    // 0x8004DF60: jal         0x8005F0DC
    // 0x8004DF64: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    func_8005F0DC(rdram, ctx);
        goto after_2;
    // 0x8004DF64: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    after_2:
    // 0x8004DF68: jal         0x80021F20
    // 0x8004DF6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_3;
    // 0x8004DF6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x8004DF70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004DF74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DF78: sw          $t5, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = ctx->r13;
    // 0x8004DF7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DF80: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
L_8004DF84:
    // 0x8004DF84: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8004DF88: lw          $s0, 0x1634($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X1634);
    // 0x8004DF8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004DF90: beq         $s0, $at, L_8004DFB8
    if (ctx->r16 == ctx->r1) {
        // 0x8004DF94: nop
    
            goto L_8004DFB8;
    }
    // 0x8004DF94: nop

    // 0x8004DF98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004DF9C: beq         $s0, $at, L_8004E004
    if (ctx->r16 == ctx->r1) {
        // 0x8004DFA0: nop
    
            goto L_8004E004;
    }
    // 0x8004DFA0: nop

    // 0x8004DFA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004DFA8: beq         $s0, $at, L_8004E050
    if (ctx->r16 == ctx->r1) {
        // 0x8004DFAC: nop
    
            goto L_8004E050;
    }
    // 0x8004DFAC: nop

    // 0x8004DFB0: b           L_8004E090
    // 0x8004DFB4: nop

        goto L_8004E090;
    // 0x8004DFB4: nop

L_8004DFB8:
    // 0x8004DFB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004DFBC: lw          $t6, 0x1628($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1628);
    // 0x8004DFC0: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8004DFC4: slt         $s1, $at, $t6
    ctx->r17 = SIGNED(ctx->r1) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004DFC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DFCC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004DFD0: beq         $s1, $zero, L_8004DFFC
    if (ctx->r17 == 0) {
        // 0x8004DFD4: sw          $t7, 0x1628($at)
        MEM_W(0X1628, ctx->r1) = ctx->r15;
            goto L_8004DFFC;
    }
    // 0x8004DFD4: sw          $t7, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = ctx->r15;
    // 0x8004DFD8: jal         0x80021ED0
    // 0x8004DFDC: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_4;
    // 0x8004DFDC: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_4:
    // 0x8004DFE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004DFE4: lw          $t8, 0x1634($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1634);
    // 0x8004DFE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DFEC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8004DFF0: sw          $t9, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = ctx->r25;
    // 0x8004DFF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004DFF8: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
L_8004DFFC:
    // 0x8004DFFC: b           L_8004E090
    // 0x8004E000: nop

        goto L_8004E090;
    // 0x8004E000: nop

L_8004E004:
    // 0x8004E004: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E008: lw          $t0, 0x1628($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1628);
    // 0x8004E00C: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8004E010: slt         $s0, $at, $t0
    ctx->r16 = SIGNED(ctx->r1) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004E014: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E018: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8004E01C: beq         $s0, $zero, L_8004E048
    if (ctx->r16 == 0) {
        // 0x8004E020: sw          $t1, 0x1628($at)
        MEM_W(0X1628, ctx->r1) = ctx->r9;
            goto L_8004E048;
    }
    // 0x8004E020: sw          $t1, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = ctx->r9;
    // 0x8004E024: jal         0x80021F20
    // 0x8004E028: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_5;
    // 0x8004E028: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x8004E02C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E030: lw          $t2, 0x1634($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1634);
    // 0x8004E034: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E038: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8004E03C: sw          $t3, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = ctx->r11;
    // 0x8004E040: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E044: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
L_8004E048:
    // 0x8004E048: b           L_8004E090
    // 0x8004E04C: nop

        goto L_8004E090;
    // 0x8004E04C: nop

L_8004E050:
    // 0x8004E050: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E054: lw          $t4, 0x1628($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1628);
    // 0x8004E058: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004E05C: slt         $s0, $at, $t4
    ctx->r16 = SIGNED(ctx->r1) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8004E060: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E064: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8004E068: beq         $s0, $zero, L_8004E088
    if (ctx->r16 == 0) {
        // 0x8004E06C: sw          $t5, 0x1628($at)
        MEM_W(0X1628, ctx->r1) = ctx->r13;
            goto L_8004E088;
    }
    // 0x8004E06C: sw          $t5, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = ctx->r13;
    // 0x8004E070: jal         0x80021ED0
    // 0x8004E074: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_6;
    // 0x8004E074: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_6:
    // 0x8004E078: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E07C: sw          $zero, 0x1634($at)
    MEM_W(0X1634, ctx->r1) = 0;
    // 0x8004E080: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E084: sw          $zero, 0x1628($at)
    MEM_W(0X1628, ctx->r1) = 0;
L_8004E088:
    // 0x8004E088: b           L_8004E090
    // 0x8004E08C: nop

        goto L_8004E090;
    // 0x8004E08C: nop

L_8004E090:
    // 0x8004E090: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8004E094: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8004E098: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8004E09C: nop

    // 0x8004E0A0: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x8004E0A4: bne         $t8, $zero, L_8004E2C0
    if (ctx->r24 != 0) {
        // 0x8004E0A8: nop
    
            goto L_8004E2C0;
    }
    // 0x8004E0A8: nop

    // 0x8004E0AC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004E0B0: lh          $t9, 0x721C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X721C);
    // 0x8004E0B4: nop

    // 0x8004E0B8: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8004E0BC: beq         $at, $zero, L_8004E2C0
    if (ctx->r1 == 0) {
        // 0x8004E0C0: nop
    
            goto L_8004E2C0;
    }
    // 0x8004E0C0: nop

    // 0x8004E0C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E0C8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004E0CC: nop

    // 0x8004E0D0: beq         $t0, $zero, L_8004E2C0
    if (ctx->r8 == 0) {
        // 0x8004E0D4: nop
    
            goto L_8004E2C0;
    }
    // 0x8004E0D4: nop

    // 0x8004E0D8: jal         0x8005A578
    // 0x8004E0DC: nop

    func_8005A578(rdram, ctx);
        goto after_7;
    // 0x8004E0DC: nop

    after_7:
    // 0x8004E0E0: beq         $v0, $zero, L_8004E2C0
    if (ctx->r2 == 0) {
        // 0x8004E0E4: nop
    
            goto L_8004E2C0;
    }
    // 0x8004E0E4: nop

    // 0x8004E0E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004E0EC: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004E0F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E0F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004E0F8: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x8004E0FC: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x8004E100: andi        $t4, $t2, 0x8
    ctx->r12 = ctx->r10 & 0X8;
    // 0x8004E104: bne         $t4, $zero, L_8004E14C
    if (ctx->r12 != 0) {
        // 0x8004E108: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_8004E14C;
    }
    // 0x8004E108: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004E10C: bne         $t5, $zero, L_8004E14C
    if (ctx->r13 != 0) {
        // 0x8004E110: nop
    
            goto L_8004E14C;
    }
    // 0x8004E110: nop

    // 0x8004E114: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8004E118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E11C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004E120: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8004E124: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004E128: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004E12C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004E130: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8004E134: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8004E138: lh          $t7, 0x3E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X3E);
    // 0x8004E13C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8004E140: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8004E144: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8004E148: sh          $t0, 0x3E($t6)
    MEM_H(0X3E, ctx->r14) = ctx->r8;
L_8004E14C:
    // 0x8004E14C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004E150: lw          $t1, 0x70E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E8);
    // 0x8004E154: nop

    // 0x8004E158: sltiu       $at, $t1, 0x7531
    ctx->r1 = ctx->r9 < 0X7531 ? 1 : 0;
    // 0x8004E15C: bne         $at, $zero, L_8004E178
    if (ctx->r1 != 0) {
        // 0x8004E160: nop
    
            goto L_8004E178;
    }
    // 0x8004E160: nop

    // 0x8004E164: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004E168: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004E16C: addiu       $t2, $zero, 0x7530
    ctx->r10 = ADD32(0, 0X7530);
    // 0x8004E170: b           L_8004E190
    // 0x8004E174: sh          $t2, 0x44($t3)
    MEM_H(0X44, ctx->r11) = ctx->r10;
        goto L_8004E190;
    // 0x8004E174: sh          $t2, 0x44($t3)
    MEM_H(0X44, ctx->r11) = ctx->r10;
L_8004E178:
    // 0x8004E178: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8004E17C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004E180: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8004E184: lw          $t4, 0x70E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70E8);
    // 0x8004E188: nop

    // 0x8004E18C: sh          $t4, 0x44($t5)
    MEM_H(0X44, ctx->r13) = ctx->r12;
L_8004E190:
    // 0x8004E190: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004E194: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004E198: nop

    // 0x8004E19C: lh          $t7, 0x3E($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X3E);
    // 0x8004E1A0: nop

    // 0x8004E1A4: andi        $t9, $t7, 0x1F
    ctx->r25 = ctx->r15 & 0X1F;
    // 0x8004E1A8: bne         $t9, $zero, L_8004E2C0
    if (ctx->r25 != 0) {
        // 0x8004E1AC: nop
    
            goto L_8004E2C0;
    }
    // 0x8004E1AC: nop

    // 0x8004E1B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E1B4: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8004E1B8: nop

    // 0x8004E1BC: lh          $t6, 0x30($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X30);
    // 0x8004E1C0: nop

    // 0x8004E1C4: blez        $t6, L_8004E1F4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004E1C8: nop
    
            goto L_8004E1F4;
    }
    // 0x8004E1C8: nop

    // 0x8004E1CC: slti        $at, $t6, 0x2BC
    ctx->r1 = SIGNED(ctx->r14) < 0X2BC ? 1 : 0;
    // 0x8004E1D0: beq         $at, $zero, L_8004E1F4
    if (ctx->r1 == 0) {
        // 0x8004E1D4: nop
    
            goto L_8004E1F4;
    }
    // 0x8004E1D4: nop

    // 0x8004E1D8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004E1DC: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8004E1E0: nop

    // 0x8004E1E4: lh          $t2, 0x30($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X30);
    // 0x8004E1E8: nop

    // 0x8004E1EC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8004E1F0: sh          $t3, 0x30($t1)
    MEM_H(0X30, ctx->r9) = ctx->r11;
L_8004E1F4:
    // 0x8004E1F4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E1F8: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004E1FC: nop

    // 0x8004E200: lh          $t5, 0x32($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X32);
    // 0x8004E204: nop

    // 0x8004E208: blez        $t5, L_8004E238
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004E20C: nop
    
            goto L_8004E238;
    }
    // 0x8004E20C: nop

    // 0x8004E210: slti        $at, $t5, 0x2BC
    ctx->r1 = SIGNED(ctx->r13) < 0X2BC ? 1 : 0;
    // 0x8004E214: beq         $at, $zero, L_8004E238
    if (ctx->r1 == 0) {
        // 0x8004E218: nop
    
            goto L_8004E238;
    }
    // 0x8004E218: nop

    // 0x8004E21C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004E220: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8004E224: nop

    // 0x8004E228: lh          $t7, 0x32($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X32);
    // 0x8004E22C: nop

    // 0x8004E230: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8004E234: sh          $t9, 0x32($t8)
    MEM_H(0X32, ctx->r24) = ctx->r25;
L_8004E238:
    // 0x8004E238: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E23C: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x8004E240: nop

    // 0x8004E244: lh          $t6, 0x34($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X34);
    // 0x8004E248: nop

    // 0x8004E24C: blez        $t6, L_8004E27C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004E250: nop
    
            goto L_8004E27C;
    }
    // 0x8004E250: nop

    // 0x8004E254: slti        $at, $t6, 0x2BC
    ctx->r1 = SIGNED(ctx->r14) < 0X2BC ? 1 : 0;
    // 0x8004E258: beq         $at, $zero, L_8004E27C
    if (ctx->r1 == 0) {
        // 0x8004E25C: nop
    
            goto L_8004E27C;
    }
    // 0x8004E25C: nop

    // 0x8004E260: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E264: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8004E268: nop

    // 0x8004E26C: lh          $t3, 0x34($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X34);
    // 0x8004E270: nop

    // 0x8004E274: addiu       $t1, $t3, -0x1
    ctx->r9 = ADD32(ctx->r11, -0X1);
    // 0x8004E278: sh          $t1, 0x34($t2)
    MEM_H(0X34, ctx->r10) = ctx->r9;
L_8004E27C:
    // 0x8004E27C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E280: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004E284: nop

    // 0x8004E288: lh          $t5, 0x36($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X36);
    // 0x8004E28C: nop

    // 0x8004E290: blez        $t5, L_8004E2C0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004E294: nop
    
            goto L_8004E2C0;
    }
    // 0x8004E294: nop

    // 0x8004E298: slti        $at, $t5, 0x2BC
    ctx->r1 = SIGNED(ctx->r13) < 0X2BC ? 1 : 0;
    // 0x8004E29C: beq         $at, $zero, L_8004E2C0
    if (ctx->r1 == 0) {
        // 0x8004E2A0: nop
    
            goto L_8004E2C0;
    }
    // 0x8004E2A0: nop

    // 0x8004E2A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004E2A8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004E2AC: nop

    // 0x8004E2B0: lh          $t9, 0x36($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X36);
    // 0x8004E2B4: nop

    // 0x8004E2B8: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8004E2BC: sh          $t8, 0x36($t7)
    MEM_H(0X36, ctx->r15) = ctx->r24;
L_8004E2C0:
    // 0x8004E2C0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004E2C4: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8004E2C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004E2CC: bne         $t0, $at, L_8004E2F0
    if (ctx->r8 != ctx->r1) {
        // 0x8004E2D0: nop
    
            goto L_8004E2F0;
    }
    // 0x8004E2D0: nop

    // 0x8004E2D4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004E2D8: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8004E2DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004E2E0: bne         $t6, $at, L_8004E2F0
    if (ctx->r14 != ctx->r1) {
        // 0x8004E2E4: nop
    
            goto L_8004E2F0;
    }
    // 0x8004E2E4: nop

    // 0x8004E2E8: jal         0x800226F4
    // 0x8004E2EC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800226F4(rdram, ctx);
        goto after_8;
    // 0x8004E2EC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_8:
L_8004E2F0:
    // 0x8004E2F0: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
L_8004E2F4:
    // 0x8004E2F4: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004E2F8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E2FC: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8004E300: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8004E304: lw          $t2, 0xE80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE80);
    // 0x8004E308: nop

    // 0x8004E30C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8004E310: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E314: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004E318: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8004E31C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004E320: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004E324: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8004E328: bne         $t0, $zero, L_8004E338
    if (ctx->r8 != 0) {
        // 0x8004E32C: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8004E338;
    }
    // 0x8004E32C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8004E330: beq         $t1, $zero, L_8004EB34
    if (ctx->r9 == 0) {
        // 0x8004E334: nop
    
            goto L_8004EB34;
    }
    // 0x8004E334: nop

L_8004E338:
    // 0x8004E338: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004E33C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004E340: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E344: nop

    // 0x8004E348: bne         $t5, $t7, L_8004E7BC
    if (ctx->r13 != ctx->r15) {
        // 0x8004E34C: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E34C: nop

    // 0x8004E350: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004E354: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004E358: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004E35C: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004E360: bne         $t2, $zero, L_8004E7BC
    if (ctx->r10 != 0) {
        // 0x8004E364: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_8004E7BC;
    }
    // 0x8004E364: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8004E368: bne         $t3, $zero, L_8004E7BC
    if (ctx->r11 != 0) {
        // 0x8004E36C: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E36C: nop

    // 0x8004E370: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E374: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E378: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004E37C: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8004E380: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8004E384: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8004E388: bne         $t0, $zero, L_8004E7BC
    if (ctx->r8 != 0) {
        // 0x8004E38C: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_8004E7BC;
    }
    // 0x8004E38C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8004E390: bne         $t1, $zero, L_8004E7BC
    if (ctx->r9 != 0) {
        // 0x8004E394: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E394: nop

    // 0x8004E398: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004E39C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004E3A0: lh          $t6, 0x7254($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7254);
    // 0x8004E3A4: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x8004E3A8: nop

    // 0x8004E3AC: bne         $t5, $t6, L_8004E7BC
    if (ctx->r13 != ctx->r14) {
        // 0x8004E3B0: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E3B0: nop

    // 0x8004E3B4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004E3B8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004E3BC: lh          $t2, 0x725C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X725C);
    // 0x8004E3C0: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8004E3C4: nop

    // 0x8004E3C8: bne         $t7, $t2, L_8004E7BC
    if (ctx->r15 != ctx->r10) {
        // 0x8004E3CC: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E3CC: nop

    // 0x8004E3D0: andi        $t3, $t5, 0x8000
    ctx->r11 = ctx->r13 & 0X8000;
    // 0x8004E3D4: bne         $t3, $zero, L_8004E7BC
    if (ctx->r11 != 0) {
        // 0x8004E3D8: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E3D8: nop

    // 0x8004E3DC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E3E0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E3E4: addiu       $at, $zero, 0x98
    ctx->r1 = ADD32(0, 0X98);
    // 0x8004E3E8: lh          $t8, 0x4A($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X4A);
    // 0x8004E3EC: nop

    // 0x8004E3F0: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x8004E3F4: beq         $t9, $at, L_8004E41C
    if (ctx->r25 == ctx->r1) {
        // 0x8004E3F8: nop
    
            goto L_8004E41C;
    }
    // 0x8004E3F8: nop

    // 0x8004E3FC: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x8004E400: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8004E404: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8004E408: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8004E40C: bne         $t6, $zero, L_8004E554
    if (ctx->r14 != 0) {
        // 0x8004E410: and         $t7, $t1, $at
        ctx->r15 = ctx->r9 & ctx->r1;
            goto L_8004E554;
    }
    // 0x8004E410: and         $t7, $t1, $at
    ctx->r15 = ctx->r9 & ctx->r1;
    // 0x8004E414: bne         $t7, $zero, L_8004E554
    if (ctx->r15 != 0) {
        // 0x8004E418: nop
    
            goto L_8004E554;
    }
    // 0x8004E418: nop

L_8004E41C:
    // 0x8004E41C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E420: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004E424: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004E428: lw          $a1, 0x4C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4C);
    // 0x8004E42C: lw          $a2, 0x50($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X50);
    // 0x8004E430: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004E434: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8004E438: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8004E43C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8004E440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8004E444: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8004E448: jal         0x80077FF0
    // 0x8004E44C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80077FF0(rdram, ctx);
        goto after_9;
    // 0x8004E44C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8004E450: beq         $v0, $zero, L_8004E54C
    if (ctx->r2 == 0) {
        // 0x8004E454: nop
    
            goto L_8004E54C;
    }
    // 0x8004E454: nop

    // 0x8004E458: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004E45C: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8004E460: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004E464: lw          $a3, 0x4C($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4C);
    // 0x8004E468: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004E46C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004E470: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8004E474: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8004E478: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8004E47C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8004E480: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8004E484: jal         0x80078168
    // 0x8004E488: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80078168(rdram, ctx);
        goto after_10;
    // 0x8004E488: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x8004E48C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004E490: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004E494: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004E498: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8004E49C: nop

    // 0x8004E4A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E4A4: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
    // 0x8004E4A8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E4AC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E4B0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004E4B4: lwc1        $f10, 0x10($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8004E4B8: nop

    // 0x8004E4BC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004E4C0: swc1        $f18, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f18.u32l;
    // 0x8004E4C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E4C8: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x8004E4CC: addiu       $t7, $t1, 0xA8
    ctx->r15 = ADD32(ctx->r9, 0XA8);
    // 0x8004E4D0: addiu       $t0, $t0, 0x12A8
    ctx->r8 = ADD32(ctx->r8, 0X12A8);
L_8004E4D4:
    // 0x8004E4D4: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8004E4D8: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8004E4DC: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8004E4E0: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x8004E4E4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8004E4E8: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8004E4EC: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x8004E4F0: bne         $t1, $t7, L_8004E4D4
    if (ctx->r9 != ctx->r15) {
        // 0x8004E4F4: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_8004E4D4;
    }
    // 0x8004E4F4: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x8004E4F8: jal         0x8005A6BC
    // 0x8004E4FC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_8005A6BC(rdram, ctx);
        goto after_11;
    // 0x8004E4FC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_11:
    // 0x8004E500: beq         $v0, $zero, L_8004E54C
    if (ctx->r2 == 0) {
        // 0x8004E504: nop
    
            goto L_8004E54C;
    }
    // 0x8004E504: nop

    // 0x8004E508: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004E50C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004E510: addiu       $at, $zero, 0x98
    ctx->r1 = ADD32(0, 0X98);
    // 0x8004E514: lh          $t5, 0x4A($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X4A);
    // 0x8004E518: nop

    // 0x8004E51C: andi        $t3, $t5, 0x1FFF
    ctx->r11 = ctx->r13 & 0X1FFF;
    // 0x8004E520: beq         $t3, $at, L_8004E54C
    if (ctx->r11 == ctx->r1) {
        // 0x8004E524: nop
    
            goto L_8004E54C;
    }
    // 0x8004E524: nop

    // 0x8004E528: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004E52C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004E530: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8004E534: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x8004E538: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8004E53C: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x8004E540: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8004E544: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8004E548: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_8004E54C:
    // 0x8004E54C: b           L_8004E7BC
    // 0x8004E550: nop

        goto L_8004E7BC;
    // 0x8004E550: nop

L_8004E554:
    // 0x8004E554: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004E558: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004E55C: lh          $t1, 0x7254($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7254);
    // 0x8004E560: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8004E564: nop

    // 0x8004E568: bne         $t9, $t1, L_8004E7BC
    if (ctx->r25 != ctx->r9) {
        // 0x8004E56C: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E56C: nop

    // 0x8004E570: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8004E574: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8004E578: lh          $t2, 0x725C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X725C);
    // 0x8004E57C: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x8004E580: nop

    // 0x8004E584: bne         $t0, $t2, L_8004E7BC
    if (ctx->r8 != ctx->r10) {
        // 0x8004E588: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E588: nop

    // 0x8004E58C: andi        $t3, $t9, 0x8000
    ctx->r11 = ctx->r25 & 0X8000;
    // 0x8004E590: bne         $t3, $zero, L_8004E7BC
    if (ctx->r11 != 0) {
        // 0x8004E594: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E594: nop

    // 0x8004E598: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E59C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E5A0: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004E5A4: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8004E5A8: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x8004E5AC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004E5B0: bne         $t8, $zero, L_8004E5E0
    if (ctx->r24 != 0) {
        // 0x8004E5B4: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004E5E0;
    }
    // 0x8004E5B4: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004E5B8: bne         $t9, $zero, L_8004E5E0
    if (ctx->r25 != 0) {
        // 0x8004E5BC: nop
    
            goto L_8004E5E0;
    }
    // 0x8004E5BC: nop

    // 0x8004E5C0: lh          $t5, 0x4A($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4A);
    // 0x8004E5C4: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x8004E5C8: andi        $t1, $t5, 0x1FFF
    ctx->r9 = ctx->r13 & 0X1FFF;
    // 0x8004E5CC: beq         $t1, $at, L_8004E5E0
    if (ctx->r9 == ctx->r1) {
        // 0x8004E5D0: nop
    
            goto L_8004E5E0;
    }
    // 0x8004E5D0: nop

    // 0x8004E5D4: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x8004E5D8: bne         $t1, $at, L_8004E7BC
    if (ctx->r9 != ctx->r1) {
        // 0x8004E5DC: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E5DC: nop

L_8004E5E0:
    // 0x8004E5E0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E5E4: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004E5E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004E5EC: lw          $a1, 0x4C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4C);
    // 0x8004E5F0: lw          $a2, 0x50($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X50);
    // 0x8004E5F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E5F8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8004E5FC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8004E600: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8004E604: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8004E608: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8004E60C: jal         0x80077FF0
    // 0x8004E610: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80077FF0(rdram, ctx);
        goto after_12;
    // 0x8004E610: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8004E614: beq         $v0, $zero, L_8004E7BC
    if (ctx->r2 == 0) {
        // 0x8004E618: nop
    
            goto L_8004E7BC;
    }
    // 0x8004E618: nop

    // 0x8004E61C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004E620: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8004E624: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004E628: bne         $t3, $at, L_8004E68C
    if (ctx->r11 != ctx->r1) {
        // 0x8004E62C: nop
    
            goto L_8004E68C;
    }
    // 0x8004E62C: nop

    // 0x8004E630: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8004E634: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8004E638: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x8004E63C: bne         $t6, $at, L_8004E68C
    if (ctx->r14 != ctx->r1) {
        // 0x8004E640: nop
    
            goto L_8004E68C;
    }
    // 0x8004E640: nop

    // 0x8004E644: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004E648: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004E64C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004E650: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8004E654: nop

    // 0x8004E658: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8004E65C: nop

    // 0x8004E660: bc1f        L_8004E68C
    if (!c1cs) {
        // 0x8004E664: nop
    
            goto L_8004E68C;
    }
    // 0x8004E664: nop

    // 0x8004E668: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8004E66C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004E670: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x8004E674: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004E678: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8004E67C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E680: ori         $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 | 0X8000;
    // 0x8004E684: b           L_8004E7BC
    // 0x8004E688: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
        goto L_8004E7BC;
    // 0x8004E688: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
L_8004E68C:
    // 0x8004E68C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8004E690: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x8004E694: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004E698: bne         $t5, $at, L_8004E6FC
    if (ctx->r13 != ctx->r1) {
        // 0x8004E69C: nop
    
            goto L_8004E6FC;
    }
    // 0x8004E69C: nop

    // 0x8004E6A0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8004E6A4: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x8004E6A8: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x8004E6AC: bne         $t1, $at, L_8004E6FC
    if (ctx->r9 != ctx->r1) {
        // 0x8004E6B0: nop
    
            goto L_8004E6FC;
    }
    // 0x8004E6B0: nop

    // 0x8004E6B4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004E6B8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004E6BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004E6C0: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8004E6C4: nop

    // 0x8004E6C8: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8004E6CC: nop

    // 0x8004E6D0: bc1f        L_8004E6FC
    if (!c1cs) {
        // 0x8004E6D4: nop
    
            goto L_8004E6FC;
    }
    // 0x8004E6D4: nop

    // 0x8004E6D8: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x8004E6DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004E6E0: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
    // 0x8004E6E4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004E6E8: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8004E6EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E6F0: ori         $t6, $t3, 0x8000
    ctx->r14 = ctx->r11 | 0X8000;
    // 0x8004E6F4: b           L_8004E7BC
    // 0x8004E6F8: sh          $t6, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r14;
        goto L_8004E7BC;
    // 0x8004E6F8: sh          $t6, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r14;
L_8004E6FC:
    // 0x8004E6FC: lh          $t7, 0x68($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X68);
    // 0x8004E700: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E704: ori         $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 | 0X8000;
    // 0x8004E708: sh          $t8, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r24;
    // 0x8004E70C: lh          $t9, 0x6A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6A);
    // 0x8004E710: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E714: ori         $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 | 0X8000;
    // 0x8004E718: sh          $t4, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r12;
    // 0x8004E71C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004E720: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x8004E724: addiu       $t3, $t1, 0xA8
    ctx->r11 = ADD32(ctx->r9, 0XA8);
    // 0x8004E728: addiu       $t5, $t5, 0x12A8
    ctx->r13 = ADD32(ctx->r13, 0X12A8);
L_8004E72C:
    // 0x8004E72C: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8004E730: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8004E734: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8004E738: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x8004E73C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8004E740: sw          $at, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r1;
    // 0x8004E744: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x8004E748: bne         $t1, $t3, L_8004E72C
    if (ctx->r9 != ctx->r11) {
        // 0x8004E74C: sw          $at, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r1;
            goto L_8004E72C;
    }
    // 0x8004E74C: sw          $at, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r1;
    // 0x8004E750: lh          $t6, 0x6C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6C);
    // 0x8004E754: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004E758: sh          $t6, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r14;
    // 0x8004E75C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E760: sb          $t6, 0xD9C($at)
    MEM_B(0XD9C, ctx->r1) = ctx->r14;
    // 0x8004E764: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004E768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E76C: sb          $t7, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r15;
    // 0x8004E770: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004E774: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004E778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E77C: lh          $t9, 0x4A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4A);
    // 0x8004E780: nop

    // 0x8004E784: sh          $t9, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r25;
    // 0x8004E788: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004E78C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8004E790: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004E794: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8004E798: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8004E79C: and         $t0, $t2, $at
    ctx->r8 = ctx->r10 & ctx->r1;
    // 0x8004E7A0: lui         $at, 0xFFDF
    ctx->r1 = S32(0XFFDF << 16);
    // 0x8004E7A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004E7A8: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8004E7AC: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8004E7B0: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x8004E7B4: jal         0x80031914
    // 0x8004E7B8: nop

    func_80031914(rdram, ctx);
        goto after_13;
    // 0x8004E7B8: nop

    after_13:
L_8004E7BC:
    // 0x8004E7BC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E7C0: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x8004E7C4: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8004E7C8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004E7CC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004E7D0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8004E7D4: bne         $t8, $zero, L_8004E7E4
    if (ctx->r24 != 0) {
        // 0x8004E7D8: and         $t9, $t7, $at
        ctx->r25 = ctx->r15 & ctx->r1;
            goto L_8004E7E4;
    }
    // 0x8004E7D8: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8004E7DC: beq         $t9, $zero, L_8004EB34
    if (ctx->r25 == 0) {
        // 0x8004E7E0: nop
    
            goto L_8004EB34;
    }
    // 0x8004E7E0: nop

L_8004E7E4:
    // 0x8004E7E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E7E8: jal         0x8004ECA8
    // 0x8004E7EC: nop

    func_8004ECA8(rdram, ctx);
        goto after_14;
    // 0x8004E7EC: nop

    after_14:
    // 0x8004E7F0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E7F4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8004E7F8: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8004E7FC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8004E800: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8004E804: bne         $t4, $zero, L_8004E814
    if (ctx->r12 != 0) {
        // 0x8004E808: and         $t5, $t1, $at
        ctx->r13 = ctx->r9 & ctx->r1;
            goto L_8004E814;
    }
    // 0x8004E808: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x8004E80C: beq         $t5, $zero, L_8004E850
    if (ctx->r13 == 0) {
        // 0x8004E810: nop
    
            goto L_8004E850;
    }
    // 0x8004E810: nop

L_8004E814:
    // 0x8004E814: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E818: nop

    // 0x8004E81C: lw          $t6, 0x8C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8C);
    // 0x8004E820: nop

    // 0x8004E824: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004E828: sw          $t7, 0x8C($t3)
    MEM_W(0X8C, ctx->r11) = ctx->r15;
    // 0x8004E82C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E830: nop

    // 0x8004E834: lw          $t9, 0x8C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8C);
    // 0x8004E838: nop

    // 0x8004E83C: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x8004E840: beq         $t2, $zero, L_8004E850
    if (ctx->r10 == 0) {
        // 0x8004E844: nop
    
            goto L_8004E850;
    }
    // 0x8004E844: nop

    // 0x8004E848: b           L_8004EB10
    // 0x8004E84C: nop

        goto L_8004EB10;
    // 0x8004E84C: nop

L_8004E850:
    // 0x8004E850: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E854: sw          $zero, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = 0;
    // 0x8004E858: lh          $t1, 0x48($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X48);
    // 0x8004E85C: nop

    // 0x8004E860: blez        $t1, L_8004EB10
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8004E864: nop
    
            goto L_8004EB10;
    }
    // 0x8004E864: nop

L_8004E868:
    // 0x8004E868: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E86C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E870: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004E874: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004E878: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004E87C: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8004E880: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004E884: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8004E888: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8004E88C: addu        $t3, $t5, $t7
    ctx->r11 = ADD32(ctx->r13, ctx->r15);
    // 0x8004E890: swc1        $f4, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f4.u32l;
    // 0x8004E894: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E898: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E89C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8004E8A0: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8004E8A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8004E8A8: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x8004E8AC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8004E8B0: lwc1        $f6, 0x10($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8004E8B4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8004E8B8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8004E8BC: swc1        $f6, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f6.u32l;
    // 0x8004E8C0: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E8C4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E8C8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8004E8CC: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8004E8D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004E8D4: lw          $t6, 0x4C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4C);
    // 0x8004E8D8: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8004E8DC: lwc1        $f8, 0x14($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8004E8E0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8004E8E4: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x8004E8E8: swc1        $f8, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f8.u32l;
    // 0x8004E8EC: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E8F0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E8F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8004E8F8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8004E8FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8004E900: lw          $t2, 0x4C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X4C);
    // 0x8004E904: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8004E908: lwc1        $f10, 0x20($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8004E90C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8004E910: addu        $t1, $t2, $t0
    ctx->r9 = ADD32(ctx->r10, ctx->r8);
    // 0x8004E914: swc1        $f10, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f10.u32l;
    // 0x8004E918: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E91C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E920: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004E924: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004E928: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004E92C: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8004E930: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004E934: lwc1        $f16, 0x18($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8004E938: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8004E93C: addu        $t3, $t5, $t7
    ctx->r11 = ADD32(ctx->r13, ctx->r15);
    // 0x8004E940: swc1        $f16, 0xF4($t3)
    MEM_W(0XF4, ctx->r11) = ctx->f16.u32l;
    // 0x8004E944: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E948: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E94C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8004E950: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8004E954: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8004E958: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x8004E95C: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8004E960: lwc1        $f18, 0x1C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8004E964: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8004E968: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8004E96C: swc1        $f18, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f18.u32l;
    // 0x8004E970: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E974: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E978: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8004E97C: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x8004E980: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004E984: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8004E988: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x8004E98C: lw          $t6, 0x40($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X40);
    // 0x8004E990: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8004E994: addu        $t8, $t5, $t3
    ctx->r24 = ADD32(ctx->r13, ctx->r11);
    // 0x8004E998: sh          $t6, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = ctx->r14;
    // 0x8004E99C: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E9A0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E9A4: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8004E9A8: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8004E9AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8004E9B0: lw          $t0, 0x4C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4C);
    // 0x8004E9B4: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8004E9B8: lw          $t9, 0x3C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X3C);
    // 0x8004E9BC: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8004E9C0: addu        $t7, $t0, $t4
    ctx->r15 = ADD32(ctx->r8, ctx->r12);
    // 0x8004E9C4: sw          $t9, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r25;
    // 0x8004E9C8: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8004E9CC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8004E9D0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8004E9D4: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8004E9D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004E9DC: lw          $t3, 0x4C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4C);
    // 0x8004E9E0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8004E9E4: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8004E9E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004E9EC: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x8004E9F0: lwc1        $f4, 0xCC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8004E9F4: lwc1        $f6, 0x125C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X125C);
    // 0x8004E9F8: nop

    // 0x8004E9FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004EA00: swc1        $f8, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f8.u32l;
    // 0x8004EA04: jal         0x800C1754
    // 0x8004EA08: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_15;
    // 0x8004EA08: nop

    after_15:
    // 0x8004EA0C: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EA10: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EA14: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8004EA18: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x8004EA1C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004EA20: lw          $t0, 0x4C($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4C);
    // 0x8004EA24: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x8004EA28: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8004EA2C: jal         0x8009A14C
    // 0x8004EA30: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    func_8009A14C(rdram, ctx);
        goto after_16;
    // 0x8004EA30: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    after_16:
    // 0x8004EA34: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EA38: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EA3C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8004EA40: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8004EA44: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004EA48: lw          $t5, 0x4C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4C);
    // 0x8004EA4C: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8004EA50: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8004EA54: addu        $t8, $t5, $t3
    ctx->r24 = ADD32(ctx->r13, ctx->r11);
    // 0x8004EA58: lwc1        $f12, 0xF0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8004EA5C: jal         0x800C2780
    // 0x8004EA60: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_17;
    // 0x8004EA60: nop

    after_17:
    // 0x8004EA64: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8004EA68: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x8004EA6C: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x8004EA70: nop

    // 0x8004EA74: andi        $t4, $t1, 0x200
    ctx->r12 = ctx->r9 & 0X200;
    // 0x8004EA78: bne         $t4, $zero, L_8004EAA8
    if (ctx->r12 != 0) {
        // 0x8004EA7C: nop
    
            goto L_8004EAA8;
    }
    // 0x8004EA7C: nop

    // 0x8004EA80: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EA84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EA88: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8004EA8C: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8004EA90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004EA94: lw          $t9, 0x4C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4C);
    // 0x8004EA98: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8004EA9C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8004EAA0: jal         0x800997D8
    // 0x8004EAA4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    func_800997D8(rdram, ctx);
        goto after_18;
    // 0x8004EAA4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    after_18:
L_8004EAA8:
    // 0x8004EAA8: jal         0x800C1A28
    // 0x8004EAAC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_19;
    // 0x8004EAAC: nop

    after_19:
    // 0x8004EAB0: lw          $t8, 0xFC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EAB4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EAB8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x8004EABC: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x8004EAC0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8004EAC4: lw          $t3, 0x4C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4C);
    // 0x8004EAC8: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x8004EACC: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8004EAD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EAD4: addu        $t1, $t3, $t2
    ctx->r9 = ADD32(ctx->r11, ctx->r10);
    // 0x8004EAD8: lwc1        $f10, 0xCC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8004EADC: lwc1        $f16, 0x125C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X125C);
    // 0x8004EAE0: nop

    // 0x8004EAE4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8004EAE8: swc1        $f18, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f18.u32l;
    // 0x8004EAEC: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8004EAF0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EAF4: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x8004EAF8: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    // 0x8004EAFC: lh          $t9, 0x48($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X48);
    // 0x8004EB00: nop

    // 0x8004EB04: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8004EB08: bne         $at, $zero, L_8004E868
    if (ctx->r1 != 0) {
        // 0x8004EB0C: nop
    
            goto L_8004E868;
    }
    // 0x8004EB0C: nop

L_8004EB10:
    // 0x8004EB10: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8004EB14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EB18: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8004EB1C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8004EB20: and         $t2, $t8, $at
    ctx->r10 = ctx->r24 & ctx->r1;
    // 0x8004EB24: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8004EB28: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x8004EB2C: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8004EB30: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
L_8004EB34:
    // 0x8004EB34: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004EB38: nop

    // 0x8004EB3C: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x8004EB40: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8004EB44: bne         $at, $zero, L_8004E2F4
    if (ctx->r1 != 0) {
        // 0x8004EB48: sw          $t1, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->r9;
            goto L_8004E2F4;
    }
    // 0x8004EB48: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x8004EB4C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8004EB50: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8004EB54: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x8004EB58: nop

    // 0x8004EB5C: andi        $t0, $t7, 0x40
    ctx->r8 = ctx->r15 & 0X40;
    // 0x8004EB60: bne         $t0, $zero, L_8004EC38
    if (ctx->r8 != 0) {
        // 0x8004EB64: nop
    
            goto L_8004EC38;
    }
    // 0x8004EB64: nop

    // 0x8004EB68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004EB6C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004EB70: nop

    // 0x8004EB74: beq         $t8, $zero, L_8004EC38
    if (ctx->r24 == 0) {
        // 0x8004EB78: nop
    
            goto L_8004EC38;
    }
    // 0x8004EB78: nop

    // 0x8004EB7C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8004EB80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EB84: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004EB88: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8004EB8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004EB90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004EB94: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004EB98: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8004EB9C: lw          $t9, 0x6CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CC);
    // 0x8004EBA0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8004EBA4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8004EBA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EBAC: subu        $t6, $t9, $t3
    ctx->r14 = SUB32(ctx->r25, ctx->r11);
    // 0x8004EBB0: sw          $t6, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = ctx->r14;
    // 0x8004EBB4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004EBB8: lw          $t5, 0x6CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6CC);
    // 0x8004EBBC: nop

    // 0x8004EBC0: bgez        $t5, L_8004EBD0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8004EBC4: nop
    
            goto L_8004EBD0;
    }
    // 0x8004EBC4: nop

    // 0x8004EBC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EBCC: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
L_8004EBD0:
    // 0x8004EBD0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004EBD4: lw          $t1, 0xCD4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XCD4);
    // 0x8004EBD8: nop

    // 0x8004EBDC: beq         $t1, $zero, L_8004EC1C
    if (ctx->r9 == 0) {
        // 0x8004EBE0: nop
    
            goto L_8004EC1C;
    }
    // 0x8004EBE0: nop

    // 0x8004EBE4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004EBE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EBEC: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8004EBF0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8004EBF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004EBF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004EBFC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004EC00: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004EC04: lw          $t4, 0xCD4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XCD4);
    // 0x8004EC08: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004EC0C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8004EC10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC14: subu        $t8, $t4, $t0
    ctx->r24 = SUB32(ctx->r12, ctx->r8);
    // 0x8004EC18: sw          $t8, 0xCD4($at)
    MEM_W(0XCD4, ctx->r1) = ctx->r24;
L_8004EC1C:
    // 0x8004EC1C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004EC20: lw          $t2, 0xCD4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCD4);
    // 0x8004EC24: nop

    // 0x8004EC28: bgez        $t2, L_8004EC38
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8004EC2C: nop
    
            goto L_8004EC38;
    }
    // 0x8004EC2C: nop

    // 0x8004EC30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC34: sw          $zero, 0xCD4($at)
    MEM_W(0XCD4, ctx->r1) = 0;
L_8004EC38:
    // 0x8004EC38: jal         0x800C4240
    // 0x8004EC3C: nop

    guRandom(rdram, ctx);
        goto after_20;
    // 0x8004EC3C: nop

    after_20:
    // 0x8004EC40: addiu       $at, $zero, 0x2710
    ctx->r1 = ADD32(0, 0X2710);
    // 0x8004EC44: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8004EC48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC4C: mfhi        $t9
    ctx->r25 = hi;
    // 0x8004EC50: sw          $t9, 0x678($at)
    MEM_W(0X678, ctx->r1) = ctx->r25;
    // 0x8004EC54: nop

    // 0x8004EC58: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004EC5C: lw          $t3, 0x678($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X678);
    // 0x8004EC60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004EC64: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8004EC68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC6C: mflo        $t6
    ctx->r14 = lo;
    // 0x8004EC70: sw          $t6, 0x670($at)
    MEM_W(0X670, ctx->r1) = ctx->r14;
    // 0x8004EC74: nop

    // 0x8004EC78: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004EC7C: lw          $t5, 0x1268($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1268);
    // 0x8004EC80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC84: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x8004EC88: sw          $t1, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r9;
    // 0x8004EC8C: b           L_8004EC94
    // 0x8004EC90: nop

        goto L_8004EC94;
    // 0x8004EC90: nop

L_8004EC94:
    // 0x8004EC94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004EC98: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004EC9C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8004ECA0: jr          $ra
    // 0x8004ECA4: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8004ECA4: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_80034E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034E9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80034EA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80034EA4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80034EA8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80034EAC: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80034EB0: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80034EB4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80034EB8: lw          $t6, 0x726C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X726C);
    // 0x80034EBC: nop

    // 0x80034EC0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80034EC4: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80034EC8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80034ECC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80034ED0: lbu         $t8, 0x1C8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1C8);
    // 0x80034ED4: nop

    // 0x80034ED8: bne         $t8, $at, L_80034F6C
    if (ctx->r24 != ctx->r1) {
        // 0x80034EDC: nop
    
            goto L_80034F6C;
    }
    // 0x80034EDC: nop

    // 0x80034EE0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80034EE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034EE8: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80034EEC: nop

    // 0x80034EF0: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80034EF4: nop

    // 0x80034EF8: bc1f        L_80034F6C
    if (!c1cs) {
        // 0x80034EFC: nop
    
            goto L_80034F6C;
    }
    // 0x80034EFC: nop

    // 0x80034F00: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80034F04: lwc1        $f14, 0x4($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80034F08: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x80034F0C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80034F10: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80034F14: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80034F18: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80034F1C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80034F20: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80034F24: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80034F28: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80034F2C: jal         0x800C3C80
    // 0x80034F30: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_0;
    // 0x80034F30: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80034F34: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80034F38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034F3C: nop

    // 0x80034F40: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80034F44: nop

    // 0x80034F48: bc1t        L_80034F6C
    if (c1cs) {
        // 0x80034F4C: nop
    
            goto L_80034F6C;
    }
    // 0x80034F4C: nop

    // 0x80034F50: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80034F54: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80034F58: sb          $t9, 0x1C8($t0)
    MEM_B(0X1C8, ctx->r8) = ctx->r25;
    // 0x80034F5C: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x80034F60: nop

    // 0x80034F64: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80034F68: sh          $t2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r10;
L_80034F6C:
    // 0x80034F6C: lh          $v0, 0x2E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2E);
    // 0x80034F70: b           L_80034F80
    // 0x80034F74: nop

        goto L_80034F80;
    // 0x80034F74: nop

    // 0x80034F78: b           L_80034F80
    // 0x80034F7C: nop

        goto L_80034F80;
    // 0x80034F7C: nop

L_80034F80:
    // 0x80034F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80034F84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80034F88: jr          $ra
    // 0x80034F8C: nop

    return;
    // 0x80034F8C: nop

;}
RECOMP_FUNC void func_80065BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BF0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065BF4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065BF8: nop

    // 0x80065BFC: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80065C00: nop

    // 0x80065C04: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065C08: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065C0C: jr          $ra
    // 0x80065C10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065C10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065C14: jr          $ra
    // 0x80065C18: nop

    return;
    // 0x80065C18: nop

    // 0x80065C1C: jr          $ra
    // 0x80065C20: nop

    return;
    // 0x80065C20: nop

;}
RECOMP_FUNC void func_80068D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D78: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068D7C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068D80: nop

    // 0x80068D84: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80068D88: nop

    // 0x80068D8C: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80068D90: jr          $ra
    // 0x80068D94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068D94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068D98: jr          $ra
    // 0x80068D9C: nop

    return;
    // 0x80068D9C: nop

    // 0x80068DA0: jr          $ra
    // 0x80068DA4: nop

    return;
    // 0x80068DA4: nop

;}
RECOMP_FUNC void func_80064DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064DF0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064DF4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064DF8: nop

    // 0x80064DFC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064E00: nop

    // 0x80064E04: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064E08: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064E0C: jr          $ra
    // 0x80064E10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064E10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064E14: jr          $ra
    // 0x80064E18: nop

    return;
    // 0x80064E18: nop

    // 0x80064E1C: jr          $ra
    // 0x80064E20: nop

    return;
    // 0x80064E20: nop

;}
RECOMP_FUNC void func_80063AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063AF0: jal         0x8005F064
    // 0x80063AF4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063AF4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063AF8: b           L_80063B08
    // 0x80063AFC: nop

        goto L_80063B08;
    // 0x80063AFC: nop

    // 0x80063B00: b           L_80063B08
    // 0x80063B04: nop

        goto L_80063B08;
    // 0x80063B04: nop

L_80063B08:
    // 0x80063B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063B10: jr          $ra
    // 0x80063B14: nop

    return;
    // 0x80063B14: nop

;}
RECOMP_FUNC void func_80098C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098C64: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80098C68: lw          $t6, 0x72DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72DC);
    // 0x80098C6C: addiu       $at, $zero, -0x19
    ctx->r1 = ADD32(0, -0X19);
    // 0x80098C70: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80098C74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80098C78: sw          $t7, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r15;
    // 0x80098C7C: jr          $ra
    // 0x80098C80: nop

    return;
    // 0x80098C80: nop

    // 0x80098C84: jr          $ra
    // 0x80098C88: nop

    return;
    // 0x80098C88: nop

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
RECOMP_FUNC void alLoadNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF9B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CF9B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CF9BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800CF9C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CF9C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CF9C8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF9CC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF9D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CF9D4: addiu       $a1, $a1, 0x87C
    ctx->r5 = ADD32(ctx->r5, 0X87C);
    // 0x800CF9D8: addiu       $a2, $a2, 0x1D0
    ctx->r6 = ADD32(ctx->r6, 0X1D0);
    // 0x800CF9DC: jal         0x800D56B0
    // 0x800CF9E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF9E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800CF9E4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800CF9E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CF9EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CF9F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CF9F4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800CF9F8: jal         0x800C7950
    // 0x800CF9FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CF9FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CFA00: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800CFA04: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x800CFA08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CFA0C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800CFA10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFA14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFA18: jal         0x800C7950
    // 0x800CFA1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800CFA1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800CFA20: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800CFA24: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800CFA28: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800CFA2C: jalr        $t9
    // 0x800CFA30: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800CFA30: nop

    after_3:
    // 0x800CFA34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CFA38: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800CFA3C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800CFA40: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x800CFA44: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800CFA48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CFA4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CFA50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CFA54: jr          $ra
    // 0x800CFA58: nop

    return;
    // 0x800CFA58: nop

;}
RECOMP_FUNC void func_800220F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800220F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800220F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800220FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80022100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80022104: jal         0x800BB4DC
    // 0x80022108: nop

    func_800BB4DC(rdram, ctx);
        goto after_0;
    // 0x80022108: nop

    after_0:
    // 0x8002210C: b           L_80022114
    // 0x80022110: nop

        goto L_80022114;
    // 0x80022110: nop

L_80022114:
    // 0x80022114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002211C: jr          $ra
    // 0x80022120: nop

    return;
    // 0x80022120: nop

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
    // 0x80088380: addiu       $a1, $t6, 0x15
    ctx->r5 = ADD32(ctx->r14, 0X15);
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80088380: addiu       $a1, $t6, 0x15
    ctx->r5 = ADD32(ctx->r14, 0X15);
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
RECOMP_FUNC void func_80072A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072A40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072A44: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072A48: nop

    // 0x80072A4C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072A50: nop

    // 0x80072A54: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072A58: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072A5C: jr          $ra
    // 0x80072A60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072A60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072A64: jr          $ra
    // 0x80072A68: nop

    return;
    // 0x80072A68: nop

    // 0x80072A6C: jr          $ra
    // 0x80072A70: nop

    return;
    // 0x80072A70: nop

;}
RECOMP_FUNC void func_80065814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006581C: jal         0x80061488
    // 0x80065820: addiu       $a0, $zero, 0x5F1
    ctx->r4 = ADD32(0, 0X5F1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065820: addiu       $a0, $zero, 0x5F1
    ctx->r4 = ADD32(0, 0X5F1);
    after_0:
    // 0x80065824: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80065828: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006582C: b           L_8006583C
    // 0x80065830: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006583C;
    // 0x80065830: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065834: b           L_8006583C
    // 0x80065838: nop

        goto L_8006583C;
    // 0x80065838: nop

L_8006583C:
    // 0x8006583C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065844: jr          $ra
    // 0x80065848: nop

    return;
    // 0x80065848: nop

;}
RECOMP_FUNC void func_800319B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800319B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800319B4: lh          $t6, 0x2524($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2524);
    // 0x800319B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800319BC: bne         $t6, $at, L_800319F8
    if (ctx->r14 != ctx->r1) {
        // 0x800319C0: nop
    
            goto L_800319F8;
    }
    // 0x800319C0: nop

    // 0x800319C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800319C8: lh          $t7, 0x2518($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2518);
    // 0x800319CC: nop

    // 0x800319D0: slti        $at, $t7, 0x28
    ctx->r1 = SIGNED(ctx->r15) < 0X28 ? 1 : 0;
    // 0x800319D4: bne         $at, $zero, L_800319E8
    if (ctx->r1 != 0) {
        // 0x800319D8: nop
    
            goto L_800319E8;
    }
    // 0x800319D8: nop

    // 0x800319DC: slti        $at, $t7, 0x2E
    ctx->r1 = SIGNED(ctx->r15) < 0X2E ? 1 : 0;
    // 0x800319E0: bne         $at, $zero, L_800319F8
    if (ctx->r1 != 0) {
        // 0x800319E4: nop
    
            goto L_800319F8;
    }
    // 0x800319E4: nop

L_800319E8:
    // 0x800319E8: jr          $ra
    // 0x800319EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800319EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800319F0: b           L_80031A54
    // 0x800319F4: nop

        goto L_80031A54;
    // 0x800319F4: nop

L_800319F8:
    // 0x800319F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800319FC: lh          $t8, 0x2524($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2524);
    // 0x80031A00: nop

    // 0x80031A04: bne         $t8, $zero, L_80031A54
    if (ctx->r24 != 0) {
        // 0x80031A08: nop
    
            goto L_80031A54;
    }
    // 0x80031A08: nop

    // 0x80031A0C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80031A10: lh          $t9, 0x2578($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2578);
    // 0x80031A14: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80031A18: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80031A1C: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x80031A20: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80031A24: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80031A28: lw          $t3, 0x79D0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X79D0);
    // 0x80031A2C: nop

    // 0x80031A30: bne         $t3, $zero, L_80031A4C
    if (ctx->r11 != 0) {
        // 0x80031A34: nop
    
            goto L_80031A4C;
    }
    // 0x80031A34: nop

    // 0x80031A38: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80031A3C: lh          $t4, 0x2518($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2518);
    // 0x80031A40: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80031A44: beq         $t4, $at, L_80031A54
    if (ctx->r12 == ctx->r1) {
        // 0x80031A48: nop
    
            goto L_80031A54;
    }
    // 0x80031A48: nop

L_80031A4C:
    // 0x80031A4C: jr          $ra
    // 0x80031A50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80031A50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80031A54:
    // 0x80031A54: beq         $a0, $zero, L_80031A9C
    if (ctx->r4 == 0) {
        // 0x80031A58: nop
    
            goto L_80031A9C;
    }
    // 0x80031A58: nop

    // 0x80031A5C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80031A60: lh          $t5, 0x2578($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2578);
    // 0x80031A64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031A68: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80031A6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80031A70: lh          $t7, 0x2578($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2578);
    // 0x80031A74: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80031A78: sw          $a0, 0x79D0($at)
    MEM_W(0X79D0, ctx->r1) = ctx->r4;
    // 0x80031A7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031A80: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80031A84: sh          $t8, 0x2578($at)
    MEM_H(0X2578, ctx->r1) = ctx->r24;
    // 0x80031A88: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80031A8C: lh          $t9, 0x2578($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2578);
    // 0x80031A90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031A94: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x80031A98: sh          $t0, 0x2578($at)
    MEM_H(0X2578, ctx->r1) = ctx->r8;
L_80031A9C:
    // 0x80031A9C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80031AA0: lh          $t1, 0x1B08($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1B08);
    // 0x80031AA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80031AA8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80031AAC: sh          $t2, 0x1B08($at)
    MEM_H(0X1B08, ctx->r1) = ctx->r10;
    // 0x80031AB0: jr          $ra
    // 0x80031AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80068AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068AA8: jal         0x80061488
    // 0x80068AAC: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068AAC: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_0:
    // 0x80068AB0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068AB4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068AB8: b           L_80068AC8
    // 0x80068ABC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068AC8;
    // 0x80068ABC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068AC0: b           L_80068AC8
    // 0x80068AC4: nop

        goto L_80068AC8;
    // 0x80068AC4: nop

L_80068AC8:
    // 0x80068AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068AD0: jr          $ra
    // 0x80068AD4: nop

    return;
    // 0x80068AD4: nop

;}
RECOMP_FUNC void func_8006F660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F660: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F664: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F668: nop

    // 0x8006F66C: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x8006F670: nop

    // 0x8006F674: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F678: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F67C: jr          $ra
    // 0x8006F680: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F680: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F684: jr          $ra
    // 0x8006F688: nop

    return;
    // 0x8006F688: nop

    // 0x8006F68C: jr          $ra
    // 0x8006F690: nop

    return;
    // 0x8006F690: nop

;}
RECOMP_FUNC void func_8006BEE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BEE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BEE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BEE8: jal         0x8005F064
    // 0x8006BEEC: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BEEC: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_0:
    // 0x8006BEF0: b           L_8006BF00
    // 0x8006BEF4: nop

        goto L_8006BF00;
    // 0x8006BEF4: nop

    // 0x8006BEF8: b           L_8006BF00
    // 0x8006BEFC: nop

        goto L_8006BF00;
    // 0x8006BEFC: nop

L_8006BF00:
    // 0x8006BF00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BF08: jr          $ra
    // 0x8006BF0C: nop

    return;
    // 0x8006BF0C: nop

;}
RECOMP_FUNC void func_800665F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800665F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800665F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800665F8: jal         0x80061488
    // 0x800665FC: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800665FC: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    after_0:
    // 0x80066600: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80066604: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80066608: b           L_80066618
    // 0x8006660C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066618;
    // 0x8006660C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066610: b           L_80066618
    // 0x80066614: nop

        goto L_80066618;
    // 0x80066614: nop

L_80066618:
    // 0x80066618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006661C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066620: jr          $ra
    // 0x80066624: nop

    return;
    // 0x80066624: nop

;}
RECOMP_FUNC void func_800B3434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B343C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B3440: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B3444: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x800B3448: nop

    // 0x800B344C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800B3450: bne         $t7, $zero, L_800B3474
    if (ctx->r15 != 0) {
        // 0x800B3454: nop
    
            goto L_800B3474;
    }
    // 0x800B3454: nop

    // 0x800B3458: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B345C: nop

    // 0x800B3460: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800B3464: jal         0x800B351C
    // 0x800B3468: nop

    func_800B351C(rdram, ctx);
        goto after_0;
    // 0x800B3468: nop

    after_0:
    // 0x800B346C: b           L_800B350C
    // 0x800B3470: nop

        goto L_800B350C;
    // 0x800B3470: nop

L_800B3474:
    // 0x800B3474: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800B3478: nop

    // 0x800B347C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B3480: nop

    // 0x800B3484: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800B3488: nop

    // 0x800B348C: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800B3490: bne         $t2, $zero, L_800B34A0
    if (ctx->r10 != 0) {
        // 0x800B3494: nop
    
            goto L_800B34A0;
    }
    // 0x800B3494: nop

    // 0x800B3498: b           L_800B350C
    // 0x800B349C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B350C;
    // 0x800B349C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B34A0:
    // 0x800B34A0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B34A4: nop

    // 0x800B34A8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800B34AC: nop

    // 0x800B34B0: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800B34B4: nop

    // 0x800B34B8: lbu         $t6, 0xF($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XF);
    // 0x800B34BC: nop

    // 0x800B34C0: bne         $t6, $zero, L_800B34D0
    if (ctx->r14 != 0) {
        // 0x800B34C4: nop
    
            goto L_800B34D0;
    }
    // 0x800B34C4: nop

    // 0x800B34C8: b           L_800B350C
    // 0x800B34CC: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
        goto L_800B350C;
    // 0x800B34CC: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_800B34D0:
    // 0x800B34D0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800B34D4: nop

    // 0x800B34D8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800B34DC: nop

    // 0x800B34E0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800B34E4: nop

    // 0x800B34E8: lbu         $t0, 0xE($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XE);
    // 0x800B34EC: nop

    // 0x800B34F0: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x800B34F4: jal         0x800B351C
    // 0x800B34F8: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    func_800B351C(rdram, ctx);
        goto after_1;
    // 0x800B34F8: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    after_1:
    // 0x800B34FC: b           L_800B350C
    // 0x800B3500: nop

        goto L_800B350C;
    // 0x800B3500: nop

    // 0x800B3504: b           L_800B350C
    // 0x800B3508: nop

        goto L_800B350C;
    // 0x800B3508: nop

L_800B350C:
    // 0x800B350C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3514: jr          $ra
    // 0x800B3518: nop

    return;
    // 0x800B3518: nop

;}
RECOMP_FUNC void func_8005B110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B110: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005B114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005B118: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005B11C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005B120: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005B124: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8005B128: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005B12C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B130: nop

    // 0x8005B134: lh          $t7, 0xAC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XAC);
    // 0x8005B138: nop

    // 0x8005B13C: andi        $t8, $t7, 0xD
    ctx->r24 = ctx->r15 & 0XD;
    // 0x8005B140: beq         $t8, $zero, L_8005B470
    if (ctx->r24 == 0) {
        // 0x8005B144: nop
    
            goto L_8005B470;
    }
    // 0x8005B144: nop

    // 0x8005B148: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B14C: nop

    // 0x8005B150: lh          $t0, 0xAC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XAC);
    // 0x8005B154: nop

    // 0x8005B158: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8005B15C: beq         $t1, $zero, L_8005B2B0
    if (ctx->r9 == 0) {
        // 0x8005B160: nop
    
            goto L_8005B2B0;
    }
    // 0x8005B160: nop

    // 0x8005B164: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005B168: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8005B16C: lh          $t3, 0xAC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XAC);
    // 0x8005B170: nop

    // 0x8005B174: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8005B178: sh          $t4, 0xAC($t2)
    MEM_H(0XAC, ctx->r10) = ctx->r12;
    // 0x8005B17C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005B180: nop

    // 0x8005B184: lh          $t6, 0xAC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XAC);
    // 0x8005B188: nop

    // 0x8005B18C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8005B190: sh          $t7, 0xAC($t5)
    MEM_H(0XAC, ctx->r13) = ctx->r15;
    // 0x8005B194: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B198: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8005B19C: sw          $t8, 0xA8($t9)
    MEM_W(0XA8, ctx->r25) = ctx->r24;
    // 0x8005B1A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005B1A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005B1A8: sw          $t0, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->r8;
    // 0x8005B1AC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005B1B0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x8005B1B4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005B1B8: nop

    // 0x8005B1BC: bne         $t3, $t4, L_8005B1D4
    if (ctx->r11 != ctx->r12) {
        // 0x8005B1C0: nop
    
            goto L_8005B1D4;
    }
    // 0x8005B1C0: nop

    // 0x8005B1C4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005B1C8: lw          $s0, 0xE70($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XE70);
    // 0x8005B1CC: b           L_8005B1E0
    // 0x8005B1D0: nop

        goto L_8005B1E0;
    // 0x8005B1D0: nop

L_8005B1D4:
    // 0x8005B1D4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005B1D8: lw          $s0, 0xE64($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XE64);
    // 0x8005B1DC: nop

L_8005B1E0:
    // 0x8005B1E0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005B1E4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8005B1E8: jal         0x8005CB6C
    // 0x8005B1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005CB6C(rdram, ctx);
        goto after_0;
    // 0x8005B1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8005B1F0: bne         $v0, $zero, L_8005B20C
    if (ctx->r2 != 0) {
        // 0x8005B1F4: nop
    
            goto L_8005B20C;
    }
    // 0x8005B1F4: nop

    // 0x8005B1F8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B1FC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8005B200: sw          $t2, 0xA8($t6)
    MEM_W(0XA8, ctx->r14) = ctx->r10;
    // 0x8005B204: b           L_8005B480
    // 0x8005B208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B20C:
    // 0x8005B20C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005B210: nop

    // 0x8005B214: lh          $t5, 0xAC($t7)
    ctx->r13 = MEM_H(ctx->r15, 0XAC);
    // 0x8005B218: nop

    // 0x8005B21C: andi        $t8, $t5, 0x80
    ctx->r24 = ctx->r13 & 0X80;
    // 0x8005B220: beq         $t8, $zero, L_8005B2A0
    if (ctx->r24 == 0) {
        // 0x8005B224: nop
    
            goto L_8005B2A0;
    }
    // 0x8005B224: nop

    // 0x8005B228: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B22C: nop

    // 0x8005B230: lwc1        $f4, 0x24($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X24);
    // 0x8005B234: nop

    // 0x8005B238: add.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x8005B23C: swc1        $f6, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f6.u32l;
    // 0x8005B240: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005B244: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8005B248: lh          $t1, 0xAC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XAC);
    // 0x8005B24C: nop

    // 0x8005B250: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8005B254: sh          $t3, 0xAC($t0)
    MEM_H(0XAC, ctx->r8) = ctx->r11;
    // 0x8005B258: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005B25C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8005B260: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8005B264: nop

    // 0x8005B268: bne         $t4, $t2, L_8005B2A0
    if (ctx->r12 != ctx->r10) {
        // 0x8005B26C: nop
    
            goto L_8005B2A0;
    }
    // 0x8005B26C: nop

    // 0x8005B270: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005B274: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B278: nop

    // 0x8005B27C: swc1        $f8, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f8.u32l;
    // 0x8005B280: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005B284: nop

    // 0x8005B288: lwc1        $f10, 0x30($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8005B28C: nop

    // 0x8005B290: swc1        $f10, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f10.u32l;
    // 0x8005B294: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005B298: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8005B29C: sw          $t5, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = ctx->r13;
L_8005B2A0:
    // 0x8005B2A0: b           L_8005B480
    // 0x8005B2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005B2A8: b           L_8005B470
    // 0x8005B2AC: nop

        goto L_8005B470;
    // 0x8005B2AC: nop

L_8005B2B0:
    // 0x8005B2B0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B2B4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005B2B8: lw          $t1, 0xA4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XA4);
    // 0x8005B2BC: nop

    // 0x8005B2C0: beq         $t1, $at, L_8005B39C
    if (ctx->r9 == ctx->r1) {
        // 0x8005B2C4: nop
    
            goto L_8005B39C;
    }
    // 0x8005B2C4: nop

    // 0x8005B2C8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005B2CC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005B2D0: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8005B2D4: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8005B2D8: bne         $t4, $zero, L_8005B2E8
    if (ctx->r12 != 0) {
        // 0x8005B2DC: andi        $t5, $t1, 0x8
        ctx->r13 = ctx->r9 & 0X8;
            goto L_8005B2E8;
    }
    // 0x8005B2DC: andi        $t5, $t1, 0x8
    ctx->r13 = ctx->r9 & 0X8;
    // 0x8005B2E0: beq         $t5, $zero, L_8005B304
    if (ctx->r13 == 0) {
        // 0x8005B2E4: nop
    
            goto L_8005B304;
    }
    // 0x8005B2E4: nop

L_8005B2E8:
    // 0x8005B2E8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8005B2EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005B2F0: lw          $a1, 0x24($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X24);
    // 0x8005B2F4: jal         0x8005D07C
    // 0x8005B2F8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_8005D07C(rdram, ctx);
        goto after_1;
    // 0x8005B2F8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
    // 0x8005B2FC: b           L_8005B324
    // 0x8005B300: nop

        goto L_8005B324;
    // 0x8005B300: nop

L_8005B304:
    // 0x8005B304: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B308: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005B30C: lwc1        $f16, 0x24($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X24);
    // 0x8005B310: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8005B314: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8005B318: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005B31C: jal         0x8005D07C
    // 0x8005B320: nop

    func_8005D07C(rdram, ctx);
        goto after_2;
    // 0x8005B320: nop

    after_2:
L_8005B324:
    // 0x8005B324: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005B328: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8005B32C: lwc1        $f4, 0x24($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X24);
    // 0x8005B330: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8005B334: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005B338: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005B33C: swc1        $f8, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f8.u32l;
    // 0x8005B340: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005B344: nop

    // 0x8005B348: lwc1        $f10, 0x24($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X24);
    // 0x8005B34C: nop

    // 0x8005B350: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B354: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x8005B358: nop

    // 0x8005B35C: bc1f        L_8005B39C
    if (!c1cs) {
        // 0x8005B360: nop
    
            goto L_8005B39C;
    }
    // 0x8005B360: nop

    // 0x8005B364: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B368: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005B36C: nop

    // 0x8005B370: swc1        $f4, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f4.u32l;
    // 0x8005B374: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005B378: nop

    // 0x8005B37C: lwc1        $f6, 0x30($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X30);
    // 0x8005B380: nop

    // 0x8005B384: swc1        $f6, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f6.u32l;
    // 0x8005B388: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005B38C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005B390: addiu       $a0, $t0, 0x4C
    ctx->r4 = ADD32(ctx->r8, 0X4C);
    // 0x8005B394: jal         0x800B2CBC
    // 0x8005B398: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    func_800B2CBC(rdram, ctx);
        goto after_3;
    // 0x8005B398: addiu       $a1, $t0, 0x50
    ctx->r5 = ADD32(ctx->r8, 0X50);
    after_3:
L_8005B39C:
    // 0x8005B39C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005B3A0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005B3A4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8005B3A8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8005B3AC: bne         $t2, $zero, L_8005B3BC
    if (ctx->r10 != 0) {
        // 0x8005B3B0: andi        $t3, $t5, 0x2
        ctx->r11 = ctx->r13 & 0X2;
            goto L_8005B3BC;
    }
    // 0x8005B3B0: andi        $t3, $t5, 0x2
    ctx->r11 = ctx->r13 & 0X2;
    // 0x8005B3B4: beq         $t3, $zero, L_8005B468
    if (ctx->r11 == 0) {
        // 0x8005B3B8: nop
    
            goto L_8005B468;
    }
    // 0x8005B3B8: nop

L_8005B3BC:
    // 0x8005B3BC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005B3C0: nop

    // 0x8005B3C4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005B3C8: nop

    // 0x8005B3CC: beq         $t7, $zero, L_8005B448
    if (ctx->r15 == 0) {
        // 0x8005B3D0: nop
    
            goto L_8005B448;
    }
    // 0x8005B3D0: nop

    // 0x8005B3D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005B3D8: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x8005B3DC: lh          $t9, 0x4A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4A);
    // 0x8005B3E0: nop

    // 0x8005B3E4: bne         $t9, $at, L_8005B420
    if (ctx->r25 != ctx->r1) {
        // 0x8005B3E8: nop
    
            goto L_8005B420;
    }
    // 0x8005B3E8: nop

    // 0x8005B3EC: lw          $t0, 0xA4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XA4);
    // 0x8005B3F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005B3F4: bne         $t0, $at, L_8005B420
    if (ctx->r8 != ctx->r1) {
        // 0x8005B3F8: nop
    
            goto L_8005B420;
    }
    // 0x8005B3F8: nop

    // 0x8005B3FC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005B400: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8005B404: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8005B408: lh          $a1, 0x42($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X42);
    // 0x8005B40C: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    // 0x8005B410: jal         0x8004EF90
    // 0x8005B414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004EF90(rdram, ctx);
        goto after_4;
    // 0x8005B414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8005B418: b           L_8005B480
    // 0x8005B41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B420:
    // 0x8005B420: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8005B424: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8005B428: lh          $t5, 0xAC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XAC);
    // 0x8005B42C: nop

    // 0x8005B430: and         $t2, $t5, $at
    ctx->r10 = ctx->r13 & ctx->r1;
    // 0x8005B434: sh          $t2, 0xAC($t4)
    MEM_H(0XAC, ctx->r12) = ctx->r10;
    // 0x8005B438: b           L_8005B480
    // 0x8005B43C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005B480;
    // 0x8005B43C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005B440: b           L_8005B468
    // 0x8005B444: nop

        goto L_8005B468;
    // 0x8005B444: nop

L_8005B448:
    // 0x8005B448: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005B44C: nop

    // 0x8005B450: lh          $t6, 0xAC($t3)
    ctx->r14 = MEM_H(ctx->r11, 0XAC);
    // 0x8005B454: nop

    // 0x8005B458: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8005B45C: sh          $t7, 0xAC($t3)
    MEM_H(0XAC, ctx->r11) = ctx->r15;
    // 0x8005B460: b           L_8005B480
    // 0x8005B464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B468:
    // 0x8005B468: b           L_8005B480
    // 0x8005B46C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B480;
    // 0x8005B46C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B470:
    // 0x8005B470: b           L_8005B480
    // 0x8005B474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005B480;
    // 0x8005B474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005B478: b           L_8005B480
    // 0x8005B47C: nop

        goto L_8005B480;
    // 0x8005B47C: nop

L_8005B480:
    // 0x8005B480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B484: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005B488: jr          $ra
    // 0x8005B48C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005B48C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005F410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F410: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005F414: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005F418: lbu         $t6, 0xD74($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0XD74);
    // 0x8005F41C: nop

    // 0x8005F420: sb          $t6, 0x1726($a0)
    MEM_B(0X1726, ctx->r4) = ctx->r14;
    // 0x8005F424: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F428:
    // 0x8005F428: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005F42C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005F430: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005F434: lbu         $t8, 0x668($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X668);
    // 0x8005F438: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x8005F43C: sb          $t8, 0x172C($t9)
    MEM_B(0X172C, ctx->r25) = ctx->r24;
    // 0x8005F440: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8005F444: nop

    // 0x8005F448: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005F44C: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8005F450: bne         $at, $zero, L_8005F428
    if (ctx->r1 != 0) {
        // 0x8005F454: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8005F428;
    }
    // 0x8005F454: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8005F458: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F45C:
    // 0x8005F45C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005F460: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005F464: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005F468: lbu         $t3, 0x680($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X680);
    // 0x8005F46C: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8005F470: sb          $t3, 0x16E6($t4)
    MEM_B(0X16E6, ctx->r12) = ctx->r11;
    // 0x8005F474: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F478: nop

    // 0x8005F47C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8005F480: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x8005F484: bne         $at, $zero, L_8005F45C
    if (ctx->r1 != 0) {
        // 0x8005F488: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_8005F45C;
    }
    // 0x8005F488: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8005F48C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F490:
    // 0x8005F490: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005F494: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005F498: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8005F49C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005F4A0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8005F4A4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8005F4A8: addu        $t2, $a0, $t9
    ctx->r10 = ADD32(ctx->r4, ctx->r25);
    // 0x8005F4AC: sh          $t1, 0x6E($t2)
    MEM_H(0X6E, ctx->r10) = ctx->r9;
    // 0x8005F4B0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F4B4: nop

    // 0x8005F4B8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F4BC: slti        $at, $t4, 0x2A
    ctx->r1 = SIGNED(ctx->r12) < 0X2A ? 1 : 0;
    // 0x8005F4C0: bne         $at, $zero, L_8005F490
    if (ctx->r1 != 0) {
        // 0x8005F4C4: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F490;
    }
    // 0x8005F4C4: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F4C8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F4CC:
    // 0x8005F4CC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F4D0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8005F4D4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005F4D8: lw          $t7, 0x468($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X468);
    // 0x8005F4DC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005F4E0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005F4E4: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8005F4E8: lwl         $at, 0x0($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X0);
    // 0x8005F4EC: lwr         $at, 0x3($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0X3);
    // 0x8005F4F0: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x8005F4F4: swl         $at, 0xAF2($t8)
    do_swl(rdram, 0XAF2, ctx->r24, ctx->r1);
    // 0x8005F4F8: swr         $at, 0xAF5($t8)
    do_swr(rdram, 0XAF5, ctx->r24, ctx->r1);
    // 0x8005F4FC: lwl         $t2, 0x4($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0X4);
    // 0x8005F500: lwr         $t2, 0x7($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0X7);
    // 0x8005F504: nop

    // 0x8005F508: swl         $t2, 0xAF6($t8)
    do_swl(rdram, 0XAF6, ctx->r24, ctx->r10);
    // 0x8005F50C: swr         $t2, 0xAF9($t8)
    do_swr(rdram, 0XAF9, ctx->r24, ctx->r10);
    // 0x8005F510: lwl         $at, 0x8($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X8);
    // 0x8005F514: lwr         $at, 0xB($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0XB);
    // 0x8005F518: nop

    // 0x8005F51C: swl         $at, 0xAFA($t8)
    do_swl(rdram, 0XAFA, ctx->r24, ctx->r1);
    // 0x8005F520: swr         $at, 0xAFD($t8)
    do_swr(rdram, 0XAFD, ctx->r24, ctx->r1);
    // 0x8005F524: lwl         $t2, 0xC($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0XC);
    // 0x8005F528: lwr         $t2, 0xF($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0XF);
    // 0x8005F52C: nop

    // 0x8005F530: swl         $t2, 0xAFE($t8)
    do_swl(rdram, 0XAFE, ctx->r24, ctx->r10);
    // 0x8005F534: swr         $t2, 0xB01($t8)
    do_swr(rdram, 0XB01, ctx->r24, ctx->r10);
    // 0x8005F538: lhu         $at, 0x10($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X10);
    // 0x8005F53C: nop

    // 0x8005F540: sh          $at, 0xB02($t8)
    MEM_H(0XB02, ctx->r24) = ctx->r1;
    // 0x8005F544: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F548: nop

    // 0x8005F54C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F550: slti        $at, $t4, 0x11
    ctx->r1 = SIGNED(ctx->r12) < 0X11 ? 1 : 0;
    // 0x8005F554: bne         $at, $zero, L_8005F4CC
    if (ctx->r1 != 0) {
        // 0x8005F558: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F4CC;
    }
    // 0x8005F558: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F55C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F560:
    // 0x8005F560: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F564: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8005F568: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8005F56C: lw          $t1, 0x470($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X470);
    // 0x8005F570: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005F574: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8005F578: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x8005F57C: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8005F580: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8005F584: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x8005F588: swl         $at, 0xD0E($t6)
    do_swl(rdram, 0XD0E, ctx->r14, ctx->r1);
    // 0x8005F58C: swr         $at, 0xD11($t6)
    do_swr(rdram, 0XD11, ctx->r14, ctx->r1);
    // 0x8005F590: lwl         $t2, 0x4($t9)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r25, 0X4);
    // 0x8005F594: lwr         $t2, 0x7($t9)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r25, 0X7);
    // 0x8005F598: nop

    // 0x8005F59C: swl         $t2, 0xD12($t6)
    do_swl(rdram, 0XD12, ctx->r14, ctx->r10);
    // 0x8005F5A0: swr         $t2, 0xD15($t6)
    do_swr(rdram, 0XD15, ctx->r14, ctx->r10);
    // 0x8005F5A4: lwl         $at, 0x8($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X8);
    // 0x8005F5A8: lwr         $at, 0xB($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0XB);
    // 0x8005F5AC: nop

    // 0x8005F5B0: swl         $at, 0xD16($t6)
    do_swl(rdram, 0XD16, ctx->r14, ctx->r1);
    // 0x8005F5B4: swr         $at, 0xD19($t6)
    do_swr(rdram, 0XD19, ctx->r14, ctx->r1);
    // 0x8005F5B8: lwl         $t2, 0xC($t9)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r25, 0XC);
    // 0x8005F5BC: lwr         $t2, 0xF($t9)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r25, 0XF);
    // 0x8005F5C0: nop

    // 0x8005F5C4: swl         $t2, 0xD1A($t6)
    do_swl(rdram, 0XD1A, ctx->r14, ctx->r10);
    // 0x8005F5C8: swr         $t2, 0xD1D($t6)
    do_swr(rdram, 0XD1D, ctx->r14, ctx->r10);
    // 0x8005F5CC: lhu         $at, 0x10($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X10);
    // 0x8005F5D0: nop

    // 0x8005F5D4: sh          $at, 0xD1E($t6)
    MEM_H(0XD1E, ctx->r14) = ctx->r1;
    // 0x8005F5D8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F5DC: nop

    // 0x8005F5E0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F5E4: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8005F5E8: bne         $at, $zero, L_8005F560
    if (ctx->r1 != 0) {
        // 0x8005F5EC: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F560;
    }
    // 0x8005F5EC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F5F0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F5F4:
    // 0x8005F5F4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F5F8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005F5FC: sll         $t1, $t5, 3
    ctx->r9 = S32(ctx->r13 << 3);
    // 0x8005F600: lw          $t0, 0x478($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X478);
    // 0x8005F604: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8005F608: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005F60C: addu        $t8, $t0, $t1
    ctx->r24 = ADD32(ctx->r8, ctx->r9);
    // 0x8005F610: lwl         $at, 0x0($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X0);
    // 0x8005F614: lwr         $at, 0x3($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0X3);
    // 0x8005F618: addu        $t7, $a0, $t1
    ctx->r15 = ADD32(ctx->r4, ctx->r9);
    // 0x8005F61C: swl         $at, 0xD56($t7)
    do_swl(rdram, 0XD56, ctx->r15, ctx->r1);
    // 0x8005F620: swr         $at, 0xD59($t7)
    do_swr(rdram, 0XD59, ctx->r15, ctx->r1);
    // 0x8005F624: lwl         $t2, 0x4($t8)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r24, 0X4);
    // 0x8005F628: lwr         $t2, 0x7($t8)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r24, 0X7);
    // 0x8005F62C: nop

    // 0x8005F630: swl         $t2, 0xD5A($t7)
    do_swl(rdram, 0XD5A, ctx->r15, ctx->r10);
    // 0x8005F634: swr         $t2, 0xD5D($t7)
    do_swr(rdram, 0XD5D, ctx->r15, ctx->r10);
    // 0x8005F638: lwl         $at, 0x8($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X8);
    // 0x8005F63C: lwr         $at, 0xB($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0XB);
    // 0x8005F640: nop

    // 0x8005F644: swl         $at, 0xD5E($t7)
    do_swl(rdram, 0XD5E, ctx->r15, ctx->r1);
    // 0x8005F648: swr         $at, 0xD61($t7)
    do_swr(rdram, 0XD61, ctx->r15, ctx->r1);
    // 0x8005F64C: lwl         $t2, 0xC($t8)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r24, 0XC);
    // 0x8005F650: lwr         $t2, 0xF($t8)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r24, 0XF);
    // 0x8005F654: nop

    // 0x8005F658: swl         $t2, 0xD62($t7)
    do_swl(rdram, 0XD62, ctx->r15, ctx->r10);
    // 0x8005F65C: swr         $t2, 0xD65($t7)
    do_swr(rdram, 0XD65, ctx->r15, ctx->r10);
    // 0x8005F660: lhu         $at, 0x10($t8)
    ctx->r1 = MEM_HU(ctx->r24, 0X10);
    // 0x8005F664: nop

    // 0x8005F668: sh          $at, 0xD66($t7)
    MEM_H(0XD66, ctx->r15) = ctx->r1;
    // 0x8005F66C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F670: nop

    // 0x8005F674: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F678: slti        $at, $t4, 0x2F
    ctx->r1 = SIGNED(ctx->r12) < 0X2F ? 1 : 0;
    // 0x8005F67C: bne         $at, $zero, L_8005F5F4
    if (ctx->r1 != 0) {
        // 0x8005F680: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F5F4;
    }
    // 0x8005F680: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F684: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F688:
    // 0x8005F688: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F68C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005F690: sll         $t0, $t5, 3
    ctx->r8 = S32(ctx->r13 << 3);
    // 0x8005F694: lw          $t9, 0x488($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X488);
    // 0x8005F698: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x8005F69C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005F6A0: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8005F6A4: lwl         $at, 0x0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X0);
    // 0x8005F6A8: lwr         $at, 0x3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X3);
    // 0x8005F6AC: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8005F6B0: swl         $at, 0xC24($t1)
    do_swl(rdram, 0XC24, ctx->r9, ctx->r1);
    // 0x8005F6B4: swr         $at, 0xC27($t1)
    do_swr(rdram, 0XC27, ctx->r9, ctx->r1);
    // 0x8005F6B8: lwl         $t2, 0x4($t6)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r14, 0X4);
    // 0x8005F6BC: lwr         $t2, 0x7($t6)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r14, 0X7);
    // 0x8005F6C0: nop

    // 0x8005F6C4: swl         $t2, 0xC28($t1)
    do_swl(rdram, 0XC28, ctx->r9, ctx->r10);
    // 0x8005F6C8: swr         $t2, 0xC2B($t1)
    do_swr(rdram, 0XC2B, ctx->r9, ctx->r10);
    // 0x8005F6CC: lwl         $at, 0x8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X8);
    // 0x8005F6D0: lwr         $at, 0xB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XB);
    // 0x8005F6D4: nop

    // 0x8005F6D8: swl         $at, 0xC2C($t1)
    do_swl(rdram, 0XC2C, ctx->r9, ctx->r1);
    // 0x8005F6DC: swr         $at, 0xC2F($t1)
    do_swr(rdram, 0XC2F, ctx->r9, ctx->r1);
    // 0x8005F6E0: lwl         $t2, 0xC($t6)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r14, 0XC);
    // 0x8005F6E4: lwr         $t2, 0xF($t6)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r14, 0XF);
    // 0x8005F6E8: nop

    // 0x8005F6EC: swl         $t2, 0xC30($t1)
    do_swl(rdram, 0XC30, ctx->r9, ctx->r10);
    // 0x8005F6F0: swr         $t2, 0xC33($t1)
    do_swr(rdram, 0XC33, ctx->r9, ctx->r10);
    // 0x8005F6F4: lhu         $at, 0x10($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0X10);
    // 0x8005F6F8: nop

    // 0x8005F6FC: sh          $at, 0xC34($t1)
    MEM_H(0XC34, ctx->r9) = ctx->r1;
    // 0x8005F700: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F704: nop

    // 0x8005F708: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F70C: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x8005F710: bne         $at, $zero, L_8005F688
    if (ctx->r1 != 0) {
        // 0x8005F714: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F688;
    }
    // 0x8005F714: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F718: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F71C:
    // 0x8005F71C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F720: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8005F724: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x8005F728: lw          $t8, 0x4A4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4A4);
    // 0x8005F72C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8005F730: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005F734: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8005F738: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x8005F73C: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x8005F740: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8005F744: swl         $at, 0xCD8($t0)
    do_swl(rdram, 0XCD8, ctx->r8, ctx->r1);
    // 0x8005F748: swr         $at, 0xCDB($t0)
    do_swr(rdram, 0XCDB, ctx->r8, ctx->r1);
    // 0x8005F74C: lwl         $t2, 0x4($t7)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r15, 0X4);
    // 0x8005F750: lwr         $t2, 0x7($t7)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r15, 0X7);
    // 0x8005F754: nop

    // 0x8005F758: swl         $t2, 0xCDC($t0)
    do_swl(rdram, 0XCDC, ctx->r8, ctx->r10);
    // 0x8005F75C: swr         $t2, 0xCDF($t0)
    do_swr(rdram, 0XCDF, ctx->r8, ctx->r10);
    // 0x8005F760: lwl         $at, 0x8($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X8);
    // 0x8005F764: lwr         $at, 0xB($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0XB);
    // 0x8005F768: nop

    // 0x8005F76C: swl         $at, 0xCE0($t0)
    do_swl(rdram, 0XCE0, ctx->r8, ctx->r1);
    // 0x8005F770: swr         $at, 0xCE3($t0)
    do_swr(rdram, 0XCE3, ctx->r8, ctx->r1);
    // 0x8005F774: lwl         $t2, 0xC($t7)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r15, 0XC);
    // 0x8005F778: lwr         $t2, 0xF($t7)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r15, 0XF);
    // 0x8005F77C: nop

    // 0x8005F780: swl         $t2, 0xCE4($t0)
    do_swl(rdram, 0XCE4, ctx->r8, ctx->r10);
    // 0x8005F784: swr         $t2, 0xCE7($t0)
    do_swr(rdram, 0XCE7, ctx->r8, ctx->r10);
    // 0x8005F788: lhu         $at, 0x10($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X10);
    // 0x8005F78C: nop

    // 0x8005F790: sh          $at, 0xCE8($t0)
    MEM_H(0XCE8, ctx->r8) = ctx->r1;
    // 0x8005F794: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F798: nop

    // 0x8005F79C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F7A0: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8005F7A4: bne         $at, $zero, L_8005F71C
    if (ctx->r1 != 0) {
        // 0x8005F7A8: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F71C;
    }
    // 0x8005F7A8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F7AC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F7B0:
    // 0x8005F7B0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F7B4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005F7B8: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x8005F7BC: lw          $t6, 0x5A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5A8);
    // 0x8005F7C0: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8005F7C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8005F7C8: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8005F7CC: lwl         $at, 0x0($t1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r9, 0X0);
    // 0x8005F7D0: lwr         $at, 0x3($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0X3);
    // 0x8005F7D4: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8005F7D8: swl         $at, 0xC48($t9)
    do_swl(rdram, 0XC48, ctx->r25, ctx->r1);
    // 0x8005F7DC: swr         $at, 0xC4B($t9)
    do_swr(rdram, 0XC4B, ctx->r25, ctx->r1);
    // 0x8005F7E0: lwl         $t2, 0x4($t1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r9, 0X4);
    // 0x8005F7E4: lwr         $t2, 0x7($t1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r9, 0X7);
    // 0x8005F7E8: nop

    // 0x8005F7EC: swl         $t2, 0xC4C($t9)
    do_swl(rdram, 0XC4C, ctx->r25, ctx->r10);
    // 0x8005F7F0: swr         $t2, 0xC4F($t9)
    do_swr(rdram, 0XC4F, ctx->r25, ctx->r10);
    // 0x8005F7F4: lwl         $at, 0x8($t1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r9, 0X8);
    // 0x8005F7F8: lwr         $at, 0xB($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0XB);
    // 0x8005F7FC: nop

    // 0x8005F800: swl         $at, 0xC50($t9)
    do_swl(rdram, 0XC50, ctx->r25, ctx->r1);
    // 0x8005F804: swr         $at, 0xC53($t9)
    do_swr(rdram, 0XC53, ctx->r25, ctx->r1);
    // 0x8005F808: lwl         $t2, 0xC($t1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r9, 0XC);
    // 0x8005F80C: lwr         $t2, 0xF($t1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r9, 0XF);
    // 0x8005F810: nop

    // 0x8005F814: swl         $t2, 0xC54($t9)
    do_swl(rdram, 0XC54, ctx->r25, ctx->r10);
    // 0x8005F818: swr         $t2, 0xC57($t9)
    do_swr(rdram, 0XC57, ctx->r25, ctx->r10);
    // 0x8005F81C: lhu         $at, 0x10($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X10);
    // 0x8005F820: nop

    // 0x8005F824: sh          $at, 0xC58($t9)
    MEM_H(0XC58, ctx->r25) = ctx->r1;
    // 0x8005F828: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F82C: nop

    // 0x8005F830: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F834: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8005F838: bne         $at, $zero, L_8005F7B0
    if (ctx->r1 != 0) {
        // 0x8005F83C: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F7B0;
    }
    // 0x8005F83C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F840: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F844:
    // 0x8005F844: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F848: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005F84C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005F850: lw          $t7, 0x630($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X630);
    // 0x8005F854: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8005F858: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005F85C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8005F860: lwl         $at, 0x0($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X0);
    // 0x8005F864: lwr         $at, 0x3($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0X3);
    // 0x8005F868: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x8005F86C: swl         $at, 0x10A4($t8)
    do_swl(rdram, 0X10A4, ctx->r24, ctx->r1);
    // 0x8005F870: swr         $at, 0x10A7($t8)
    do_swr(rdram, 0X10A7, ctx->r24, ctx->r1);
    // 0x8005F874: lwl         $t2, 0x4($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0X4);
    // 0x8005F878: lwr         $t2, 0x7($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0X7);
    // 0x8005F87C: nop

    // 0x8005F880: swl         $t2, 0x10A8($t8)
    do_swl(rdram, 0X10A8, ctx->r24, ctx->r10);
    // 0x8005F884: swr         $t2, 0x10AB($t8)
    do_swr(rdram, 0X10AB, ctx->r24, ctx->r10);
    // 0x8005F888: lwl         $at, 0x8($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X8);
    // 0x8005F88C: lwr         $at, 0xB($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0XB);
    // 0x8005F890: nop

    // 0x8005F894: swl         $at, 0x10AC($t8)
    do_swl(rdram, 0X10AC, ctx->r24, ctx->r1);
    // 0x8005F898: swr         $at, 0x10AF($t8)
    do_swr(rdram, 0X10AF, ctx->r24, ctx->r1);
    // 0x8005F89C: lwl         $t2, 0xC($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0XC);
    // 0x8005F8A0: lwr         $t2, 0xF($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0XF);
    // 0x8005F8A4: nop

    // 0x8005F8A8: swl         $t2, 0x10B0($t8)
    do_swl(rdram, 0X10B0, ctx->r24, ctx->r10);
    // 0x8005F8AC: swr         $t2, 0x10B3($t8)
    do_swr(rdram, 0X10B3, ctx->r24, ctx->r10);
    // 0x8005F8B0: lhu         $at, 0x10($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X10);
    // 0x8005F8B4: nop

    // 0x8005F8B8: sh          $at, 0x10B4($t8)
    MEM_H(0X10B4, ctx->r24) = ctx->r1;
    // 0x8005F8BC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F8C0: nop

    // 0x8005F8C4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F8C8: slti        $at, $t4, 0x2E
    ctx->r1 = SIGNED(ctx->r12) < 0X2E ? 1 : 0;
    // 0x8005F8CC: bne         $at, $zero, L_8005F844
    if (ctx->r1 != 0) {
        // 0x8005F8D0: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F844;
    }
    // 0x8005F8D0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F8D4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F8D8:
    // 0x8005F8D8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F8DC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005F8E0: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8005F8E4: lw          $t1, 0x634($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X634);
    // 0x8005F8E8: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005F8EC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8005F8F0: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x8005F8F4: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x8005F8F8: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8005F8FC: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x8005F900: swl         $at, 0x1548($t6)
    do_swl(rdram, 0X1548, ctx->r14, ctx->r1);
    // 0x8005F904: swr         $at, 0x154B($t6)
    do_swr(rdram, 0X154B, ctx->r14, ctx->r1);
    // 0x8005F908: lwl         $t2, 0x4($t9)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r25, 0X4);
    // 0x8005F90C: lwr         $t2, 0x7($t9)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r25, 0X7);
    // 0x8005F910: nop

    // 0x8005F914: swl         $t2, 0x154C($t6)
    do_swl(rdram, 0X154C, ctx->r14, ctx->r10);
    // 0x8005F918: swr         $t2, 0x154F($t6)
    do_swr(rdram, 0X154F, ctx->r14, ctx->r10);
    // 0x8005F91C: lwl         $at, 0x8($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X8);
    // 0x8005F920: lwr         $at, 0xB($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0XB);
    // 0x8005F924: nop

    // 0x8005F928: swl         $at, 0x1550($t6)
    do_swl(rdram, 0X1550, ctx->r14, ctx->r1);
    // 0x8005F92C: swr         $at, 0x1553($t6)
    do_swr(rdram, 0X1553, ctx->r14, ctx->r1);
    // 0x8005F930: lwl         $t2, 0xC($t9)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r25, 0XC);
    // 0x8005F934: lwr         $t2, 0xF($t9)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r25, 0XF);
    // 0x8005F938: nop

    // 0x8005F93C: swl         $t2, 0x1554($t6)
    do_swl(rdram, 0X1554, ctx->r14, ctx->r10);
    // 0x8005F940: swr         $t2, 0x1557($t6)
    do_swr(rdram, 0X1557, ctx->r14, ctx->r10);
    // 0x8005F944: lhu         $at, 0x10($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X10);
    // 0x8005F948: nop

    // 0x8005F94C: sh          $at, 0x1558($t6)
    MEM_H(0X1558, ctx->r14) = ctx->r1;
    // 0x8005F950: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F954: nop

    // 0x8005F958: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F95C: slti        $at, $t4, 0x17
    ctx->r1 = SIGNED(ctx->r12) < 0X17 ? 1 : 0;
    // 0x8005F960: bne         $at, $zero, L_8005F8D8
    if (ctx->r1 != 0) {
        // 0x8005F964: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F8D8;
    }
    // 0x8005F964: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F968: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005F96C:
    // 0x8005F96C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005F970: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8005F974: sll         $t1, $t5, 3
    ctx->r9 = S32(ctx->r13 << 3);
    // 0x8005F978: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x8005F97C: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8005F980: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005F984: addu        $t8, $t0, $t1
    ctx->r24 = ADD32(ctx->r8, ctx->r9);
    // 0x8005F988: lwl         $at, 0x0($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X0);
    // 0x8005F98C: lwr         $at, 0x3($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0X3);
    // 0x8005F990: addu        $t7, $a0, $t1
    ctx->r15 = ADD32(ctx->r4, ctx->r9);
    // 0x8005F994: swl         $at, 0x13E0($t7)
    do_swl(rdram, 0X13E0, ctx->r15, ctx->r1);
    // 0x8005F998: swr         $at, 0x13E3($t7)
    do_swr(rdram, 0X13E3, ctx->r15, ctx->r1);
    // 0x8005F99C: lwl         $t2, 0x4($t8)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r24, 0X4);
    // 0x8005F9A0: lwr         $t2, 0x7($t8)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r24, 0X7);
    // 0x8005F9A4: nop

    // 0x8005F9A8: swl         $t2, 0x13E4($t7)
    do_swl(rdram, 0X13E4, ctx->r15, ctx->r10);
    // 0x8005F9AC: swr         $t2, 0x13E7($t7)
    do_swr(rdram, 0X13E7, ctx->r15, ctx->r10);
    // 0x8005F9B0: lwl         $at, 0x8($t8)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r24, 0X8);
    // 0x8005F9B4: lwr         $at, 0xB($t8)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r24, 0XB);
    // 0x8005F9B8: nop

    // 0x8005F9BC: swl         $at, 0x13E8($t7)
    do_swl(rdram, 0X13E8, ctx->r15, ctx->r1);
    // 0x8005F9C0: swr         $at, 0x13EB($t7)
    do_swr(rdram, 0X13EB, ctx->r15, ctx->r1);
    // 0x8005F9C4: lwl         $t2, 0xC($t8)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r24, 0XC);
    // 0x8005F9C8: lwr         $t2, 0xF($t8)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r24, 0XF);
    // 0x8005F9CC: nop

    // 0x8005F9D0: swl         $t2, 0x13EC($t7)
    do_swl(rdram, 0X13EC, ctx->r15, ctx->r10);
    // 0x8005F9D4: swr         $t2, 0x13EF($t7)
    do_swr(rdram, 0X13EF, ctx->r15, ctx->r10);
    // 0x8005F9D8: lhu         $at, 0x10($t8)
    ctx->r1 = MEM_HU(ctx->r24, 0X10);
    // 0x8005F9DC: nop

    // 0x8005F9E0: sh          $at, 0x13F0($t7)
    MEM_H(0X13F0, ctx->r15) = ctx->r1;
    // 0x8005F9E4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005F9E8: nop

    // 0x8005F9EC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F9F0: slti        $at, $t4, 0x14
    ctx->r1 = SIGNED(ctx->r12) < 0X14 ? 1 : 0;
    // 0x8005F9F4: bne         $at, $zero, L_8005F96C
    if (ctx->r1 != 0) {
        // 0x8005F9F8: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005F96C;
    }
    // 0x8005F9F8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005F9FC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FA00:
    // 0x8005FA00: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005FA04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005FA08: sll         $t0, $t5, 3
    ctx->r8 = S32(ctx->r13 << 3);
    // 0x8005FA0C: lw          $t9, 0x638($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X638);
    // 0x8005FA10: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x8005FA14: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8005FA18: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8005FA1C: lwl         $at, 0x0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X0);
    // 0x8005FA20: lwr         $at, 0x3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X3);
    // 0x8005FA24: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8005FA28: swl         $at, 0xA86($t1)
    do_swl(rdram, 0XA86, ctx->r9, ctx->r1);
    // 0x8005FA2C: swr         $at, 0xA89($t1)
    do_swr(rdram, 0XA89, ctx->r9, ctx->r1);
    // 0x8005FA30: lwl         $t2, 0x4($t6)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r14, 0X4);
    // 0x8005FA34: lwr         $t2, 0x7($t6)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r14, 0X7);
    // 0x8005FA38: nop

    // 0x8005FA3C: swl         $t2, 0xA8A($t1)
    do_swl(rdram, 0XA8A, ctx->r9, ctx->r10);
    // 0x8005FA40: swr         $t2, 0xA8D($t1)
    do_swr(rdram, 0XA8D, ctx->r9, ctx->r10);
    // 0x8005FA44: lwl         $at, 0x8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X8);
    // 0x8005FA48: lwr         $at, 0xB($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0XB);
    // 0x8005FA4C: nop

    // 0x8005FA50: swl         $at, 0xA8E($t1)
    do_swl(rdram, 0XA8E, ctx->r9, ctx->r1);
    // 0x8005FA54: swr         $at, 0xA91($t1)
    do_swr(rdram, 0XA91, ctx->r9, ctx->r1);
    // 0x8005FA58: lwl         $t2, 0xC($t6)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r14, 0XC);
    // 0x8005FA5C: lwr         $t2, 0xF($t6)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r14, 0XF);
    // 0x8005FA60: nop

    // 0x8005FA64: swl         $t2, 0xA92($t1)
    do_swl(rdram, 0XA92, ctx->r9, ctx->r10);
    // 0x8005FA68: swr         $t2, 0xA95($t1)
    do_swr(rdram, 0XA95, ctx->r9, ctx->r10);
    // 0x8005FA6C: lhu         $at, 0x10($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0X10);
    // 0x8005FA70: nop

    // 0x8005FA74: sh          $at, 0xA96($t1)
    MEM_H(0XA96, ctx->r9) = ctx->r1;
    // 0x8005FA78: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005FA7C: nop

    // 0x8005FA80: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005FA84: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8005FA88: bne         $at, $zero, L_8005FA00
    if (ctx->r1 != 0) {
        // 0x8005FA8C: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005FA00;
    }
    // 0x8005FA8C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005FA90: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8005FA94:
    // 0x8005FA94: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005FA98: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005FA9C: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x8005FAA0: lw          $t8, 0x63C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63C);
    // 0x8005FAA4: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8005FAA8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005FAAC: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8005FAB0: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x8005FAB4: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x8005FAB8: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8005FABC: swl         $at, 0xABC($t0)
    do_swl(rdram, 0XABC, ctx->r8, ctx->r1);
    // 0x8005FAC0: swr         $at, 0xABF($t0)
    do_swr(rdram, 0XABF, ctx->r8, ctx->r1);
    // 0x8005FAC4: lwl         $t2, 0x4($t7)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r15, 0X4);
    // 0x8005FAC8: lwr         $t2, 0x7($t7)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r15, 0X7);
    // 0x8005FACC: nop

    // 0x8005FAD0: swl         $t2, 0xAC0($t0)
    do_swl(rdram, 0XAC0, ctx->r8, ctx->r10);
    // 0x8005FAD4: swr         $t2, 0xAC3($t0)
    do_swr(rdram, 0XAC3, ctx->r8, ctx->r10);
    // 0x8005FAD8: lwl         $at, 0x8($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X8);
    // 0x8005FADC: lwr         $at, 0xB($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0XB);
    // 0x8005FAE0: nop

    // 0x8005FAE4: swl         $at, 0xAC4($t0)
    do_swl(rdram, 0XAC4, ctx->r8, ctx->r1);
    // 0x8005FAE8: swr         $at, 0xAC7($t0)
    do_swr(rdram, 0XAC7, ctx->r8, ctx->r1);
    // 0x8005FAEC: lwl         $t2, 0xC($t7)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r15, 0XC);
    // 0x8005FAF0: lwr         $t2, 0xF($t7)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r15, 0XF);
    // 0x8005FAF4: nop

    // 0x8005FAF8: swl         $t2, 0xAC8($t0)
    do_swl(rdram, 0XAC8, ctx->r8, ctx->r10);
    // 0x8005FAFC: swr         $t2, 0xACB($t0)
    do_swr(rdram, 0XACB, ctx->r8, ctx->r10);
    // 0x8005FB00: lhu         $at, 0x10($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X10);
    // 0x8005FB04: nop

    // 0x8005FB08: sh          $at, 0xACC($t0)
    MEM_H(0XACC, ctx->r8) = ctx->r1;
    // 0x8005FB0C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005FB10: nop

    // 0x8005FB14: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005FB18: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8005FB1C: bne         $at, $zero, L_8005FA94
    if (ctx->r1 != 0) {
        // 0x8005FB20: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_8005FA94;
    }
    // 0x8005FB20: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8005FB24: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005FB28: lw          $t5, 0x658($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X658);
    // 0x8005FB2C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8005FB30: beq         $t5, $zero, L_8005FBF8
    if (ctx->r13 == 0) {
        // 0x8005FB34: nop
    
            goto L_8005FBF8;
    }
    // 0x8005FB34: nop

L_8005FB38:
    // 0x8005FB38: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8005FB3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005FB40: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005FB44: lw          $t6, 0x650($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X650);
    // 0x8005FB48: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005FB4C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005FB50: addu        $t1, $t9, $t6
    ctx->r9 = ADD32(ctx->r25, ctx->r14);
    // 0x8005FB54: lbu         $t0, 0x2($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X2);
    // 0x8005FB58: addu        $t2, $a0, $t8
    ctx->r10 = ADD32(ctx->r4, ctx->r24);
    // 0x8005FB5C: andi        $t7, $t0, 0x3
    ctx->r15 = ctx->r8 & 0X3;
    // 0x8005FB60: sb          $t7, 0xC2($t2)
    MEM_B(0XC2, ctx->r10) = ctx->r15;
    // 0x8005FB64: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8005FB68: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005FB6C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005FB70: lw          $t3, 0x650($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X650);
    // 0x8005FB74: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8005FB78: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8005FB7C: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x8005FB80: lbu         $t6, 0x3($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X3);
    // 0x8005FB84: addu        $t8, $a0, $t4
    ctx->r24 = ADD32(ctx->r4, ctx->r12);
    // 0x8005FB88: lbu         $t7, 0xC2($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XC2);
    // 0x8005FB8C: andi        $t1, $t6, 0xF
    ctx->r9 = ctx->r14 & 0XF;
    // 0x8005FB90: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8005FB94: addu        $t3, $a0, $t4
    ctx->r11 = ADD32(ctx->r4, ctx->r12);
    // 0x8005FB98: or          $t2, $t7, $t0
    ctx->r10 = ctx->r15 | ctx->r8;
    // 0x8005FB9C: sb          $t2, 0xC2($t3)
    MEM_B(0XC2, ctx->r11) = ctx->r10;
    // 0x8005FBA0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8005FBA4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005FBA8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8005FBAC: lw          $t5, 0x650($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X650);
    // 0x8005FBB0: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8005FBB4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005FBB8: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x8005FBBC: lbu         $t8, 0x4($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X4);
    // 0x8005FBC0: addu        $t4, $a0, $t9
    ctx->r12 = ADD32(ctx->r4, ctx->r25);
    // 0x8005FBC4: lbu         $t2, 0xC2($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0XC2);
    // 0x8005FBC8: andi        $t7, $t8, 0x3
    ctx->r15 = ctx->r24 & 0X3;
    // 0x8005FBCC: sll         $t0, $t7, 6
    ctx->r8 = S32(ctx->r15 << 6);
    // 0x8005FBD0: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x8005FBD4: or          $t3, $t2, $t0
    ctx->r11 = ctx->r10 | ctx->r8;
    // 0x8005FBD8: sb          $t3, 0xC2($t5)
    MEM_B(0XC2, ctx->r13) = ctx->r11;
    // 0x8005FBDC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8005FBE0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005FBE4: lw          $t8, 0x658($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X658);
    // 0x8005FBE8: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x8005FBEC: sltu        $at, $t1, $t8
    ctx->r1 = ctx->r9 < ctx->r24 ? 1 : 0;
    // 0x8005FBF0: bne         $at, $zero, L_8005FB38
    if (ctx->r1 != 0) {
        // 0x8005FBF4: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8005FB38;
    }
    // 0x8005FBF4: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_8005FBF8:
    // 0x8005FBF8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005FBFC: lw          $t7, 0x658($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X658);
    // 0x8005FC00: nop

    // 0x8005FC04: sw          $t7, 0x1728($a0)
    MEM_W(0X1728, ctx->r4) = ctx->r15;
    // 0x8005FC08: b           L_8005FC10
    // 0x8005FC0C: nop

        goto L_8005FC10;
    // 0x8005FC0C: nop

L_8005FC10:
    // 0x8005FC10: jr          $ra
    // 0x8005FC14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005FC14: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800BCF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCF78: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCF7C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800BCF80: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800BCF84: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800BCF88: beq         $a1, $zero, L_800BCFBC
    if (ctx->r5 == 0) {
        // 0x800BCF8C: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_800BCFBC;
    }
    // 0x800BCF8C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800BCF90:
    // 0x800BCF90: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800BCF94: nop

    // 0x800BCF98: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BCF9C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800BCFA0: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800BCFA4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800BCFA8: nop

    // 0x800BCFAC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BCFB0: sltu        $at, $t1, $a1
    ctx->r1 = ctx->r9 < ctx->r5 ? 1 : 0;
    // 0x800BCFB4: bne         $at, $zero, L_800BCF90
    if (ctx->r1 != 0) {
        // 0x800BCFB8: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800BCF90;
    }
    // 0x800BCFB8: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_800BCFBC:
    // 0x800BCFBC: b           L_800BCFC4
    // 0x800BCFC0: nop

        goto L_800BCFC4;
    // 0x800BCFC0: nop

L_800BCFC4:
    // 0x800BCFC4: jr          $ra
    // 0x800BCFC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BCFC8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80066E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066E30: jal         0x80061348
    // 0x80066E34: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066E34: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x80066E38: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066E3C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066E40: b           L_80066E50
    // 0x80066E44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066E50;
    // 0x80066E44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066E48: b           L_80066E50
    // 0x80066E4C: nop

        goto L_80066E50;
    // 0x80066E4C: nop

L_80066E50:
    // 0x80066E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066E58: jr          $ra
    // 0x80066E5C: nop

    return;
    // 0x80066E5C: nop

;}
