#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8006CCE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CCE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CCEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CCF0: nop

    // 0x8006CCF4: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006CCF8: nop

    // 0x8006CCFC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CD00: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CD04: jr          $ra
    // 0x8006CD08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CD08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CD0C: jr          $ra
    // 0x8006CD10: nop

    return;
    // 0x8006CD10: nop

    // 0x8006CD14: jr          $ra
    // 0x8006CD18: nop

    return;
    // 0x8006CD18: nop

;}
RECOMP_FUNC void func_8001CE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CE54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CE5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001CE60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001CE64: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001CE68: nop

    // 0x8001CE6C: bltz        $t6, L_8001CEB0
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001CE70: nop
    
            goto L_8001CEB0;
    }
    // 0x8001CE70: nop

    // 0x8001CE74: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CE78: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CE7C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CE80: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001CE84: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CE88: nop

    // 0x8001CE8C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CE90: beq         $t0, $zero, L_8001CEB0
    if (ctx->r8 == 0) {
        // 0x8001CE94: nop
    
            goto L_8001CEB0;
    }
    // 0x8001CE94: nop

    // 0x8001CE98: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001CE9C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8001CEA0: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8001CEA4: nop

    // 0x8001CEA8: xori        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 ^ 0X20;
    // 0x8001CEAC: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_8001CEB0:
    // 0x8001CEB0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001CEB4: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001CEB8: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8001CEBC: nop

    // 0x8001CEC0: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x8001CEC4: beq         $t6, $zero, L_8001CEE0
    if (ctx->r14 == 0) {
        // 0x8001CEC8: nop
    
            goto L_8001CEE0;
    }
    // 0x8001CEC8: nop

    // 0x8001CECC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CED0: jal         0x8008ECE4
    // 0x8001CED4: addiu       $a0, $a0, -0x26B4
    ctx->r4 = ADD32(ctx->r4, -0X26B4);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CED4: addiu       $a0, $a0, -0x26B4
    ctx->r4 = ADD32(ctx->r4, -0X26B4);
    after_0:
    // 0x8001CED8: b           L_8001CEEC
    // 0x8001CEDC: nop

        goto L_8001CEEC;
    // 0x8001CEDC: nop

L_8001CEE0:
    // 0x8001CEE0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CEE4: jal         0x8008ECE4
    // 0x8001CEE8: addiu       $a0, $a0, -0x26AC
    ctx->r4 = ADD32(ctx->r4, -0X26AC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CEE8: addiu       $a0, $a0, -0x26AC
    ctx->r4 = ADD32(ctx->r4, -0X26AC);
    after_1:
L_8001CEEC:
    // 0x8001CEEC: b           L_8001CEFC
    // 0x8001CEF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CEFC;
    // 0x8001CEF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CEF4: b           L_8001CEFC
    // 0x8001CEF8: nop

        goto L_8001CEFC;
    // 0x8001CEF8: nop

L_8001CEFC:
    // 0x8001CEFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CF00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CF04: jr          $ra
    // 0x8001CF08: nop

    return;
    // 0x8001CF08: nop

;}
RECOMP_FUNC void alSeqpSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CAD54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CAD58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CAD5C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800CAD60: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800CAD64: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800CAD68: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x800CAD6C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800CAD70: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800CAD74: jal         0x800D3A2C
    // 0x800CAD78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CAD78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CAD7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAD80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CAD84: jr          $ra
    // 0x800CAD88: nop

    return;
    // 0x800CAD88: nop

;}
RECOMP_FUNC void func_800724F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800724FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072500: nop

    // 0x80072504: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80072508: nop

    // 0x8007250C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072510: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072514: jr          $ra
    // 0x80072518: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072518: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007251C: jr          $ra
    // 0x80072520: nop

    return;
    // 0x80072520: nop

    // 0x80072524: jr          $ra
    // 0x80072528: nop

    return;
    // 0x80072528: nop

;}
RECOMP_FUNC void func_80076288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007628C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076290: jal         0x8005F064
    // 0x80076294: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80076294: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x80076298: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8007629C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800762A0: beq         $v0, $zero, L_800762E8
    if (ctx->r2 == 0) {
        // 0x800762A4: nop
    
            goto L_800762E8;
    }
    // 0x800762A4: nop

    // 0x800762A8: jal         0x8005F064
    // 0x800762AC: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x800762AC: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_1:
    // 0x800762B0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800762B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800762B8: beq         $v0, $zero, L_800762E8
    if (ctx->r2 == 0) {
        // 0x800762BC: nop
    
            goto L_800762E8;
    }
    // 0x800762BC: nop

    // 0x800762C0: jal         0x8005F064
    // 0x800762C4: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_8005F064(rdram, ctx);
        goto after_2;
    // 0x800762C4: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_2:
    // 0x800762C8: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800762CC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800762D0: beq         $v0, $zero, L_800762E8
    if (ctx->r2 == 0) {
        // 0x800762D4: nop
    
            goto L_800762E8;
    }
    // 0x800762D4: nop

    // 0x800762D8: jal         0x8005F064
    // 0x800762DC: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    func_8005F064(rdram, ctx);
        goto after_3;
    // 0x800762DC: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    after_3:
    // 0x800762E0: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x800762E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800762E8:
    // 0x800762E8: b           L_800762F8
    // 0x800762EC: nop

        goto L_800762F8;
    // 0x800762EC: nop

    // 0x800762F0: b           L_800762F8
    // 0x800762F4: nop

        goto L_800762F8;
    // 0x800762F4: nop

L_800762F8:
    // 0x800762F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800762FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076300: jr          $ra
    // 0x80076304: nop

    return;
    // 0x80076304: nop

;}
RECOMP_FUNC void __mapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2660: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D2664: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800D2668: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800D266C: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x800D2670: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D2674: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x800D2678: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x800D267C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800D2680: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800D2684: beq         $v1, $zero, L_800D26C8
    if (ctx->r3 == 0) {
        // 0x800D2688: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800D26C8;
    }
    // 0x800D2688: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800D268C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800D2690: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x800D2694: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800D2698: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x800D269C: bnel        $t0, $zero, L_800D26B0
    if (ctx->r8 != 0) {
        // 0x800D26A0: lw          $t1, 0x68($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X68);
            goto L_800D26B0;
    }
    goto skip_0;
    // 0x800D26A0: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    skip_0:
    // 0x800D26A4: b           L_800D26B4
    // 0x800D26A8: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
        goto L_800D26B4;
    // 0x800D26A8: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
    // 0x800D26AC: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
L_800D26B0:
    // 0x800D26B0: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
L_800D26B4:
    // 0x800D26B4: sw          $v1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r3;
    // 0x800D26B8: sb          $a3, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r7;
    // 0x800D26BC: sb          $a1, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r5;
    // 0x800D26C0: sb          $a2, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r6;
    // 0x800D26C4: sw          $v1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r3;
L_800D26C8:
    // 0x800D26C8: jr          $ra
    // 0x800D26CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D26CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80069D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80069D74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80069D78: nop

    // 0x80069D7C: lh          $v0, 0x3A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X3A);
    // 0x80069D80: nop

    // 0x80069D84: xori        $t7, $v0, 0x3E7
    ctx->r15 = ctx->r2 ^ 0X3E7;
    // 0x80069D88: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80069D8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069D90: beq         $v0, $zero, L_80069DAC
    if (ctx->r2 == 0) {
        // 0x80069D94: nop
    
            goto L_80069DAC;
    }
    // 0x80069D94: nop

    // 0x80069D98: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80069D9C: nop

    // 0x80069DA0: xori        $t8, $v0, 0x3E7
    ctx->r24 = ctx->r2 ^ 0X3E7;
    // 0x80069DA4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80069DA8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80069DAC:
    // 0x80069DAC: jr          $ra
    // 0x80069DB0: nop

    return;
    // 0x80069DB0: nop

    // 0x80069DB4: jr          $ra
    // 0x80069DB8: nop

    return;
    // 0x80069DB8: nop

    // 0x80069DBC: jr          $ra
    // 0x80069DC0: nop

    return;
    // 0x80069DC0: nop

;}
RECOMP_FUNC void func_80072938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072938: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007293C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072940: nop

    // 0x80072944: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072948: nop

    // 0x8007294C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80072950: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072954: jr          $ra
    // 0x80072958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007295C: jr          $ra
    // 0x80072960: nop

    return;
    // 0x80072960: nop

    // 0x80072964: jr          $ra
    // 0x80072968: nop

    return;
    // 0x80072968: nop

;}
RECOMP_FUNC void func_80022690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022698: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002269C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800226A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800226A4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800226A8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800226AC: bne         $t0, $zero, L_800226D4
    if (ctx->r8 != 0) {
        // 0x800226B0: andi        $t1, $t9, 0x8000
        ctx->r9 = ctx->r25 & 0X8000;
            goto L_800226D4;
    }
    // 0x800226B0: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x800226B4: bne         $t1, $zero, L_800226D4
    if (ctx->r9 != 0) {
        // 0x800226B8: nop
    
            goto L_800226D4;
    }
    // 0x800226B8: nop

    // 0x800226BC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800226C0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800226C4: bne         $t2, $zero, L_800226D4
    if (ctx->r10 != 0) {
        // 0x800226C8: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_800226D4;
    }
    // 0x800226C8: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x800226CC: beq         $t3, $zero, L_800226DC
    if (ctx->r11 == 0) {
        // 0x800226D0: nop
    
            goto L_800226DC;
    }
    // 0x800226D0: nop

L_800226D4:
    // 0x800226D4: jal         0x80055FB8
    // 0x800226D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80055FB8(rdram, ctx);
        goto after_0;
    // 0x800226D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
L_800226DC:
    // 0x800226DC: b           L_800226E4
    // 0x800226E0: nop

        goto L_800226E4;
    // 0x800226E0: nop

L_800226E4:
    // 0x800226E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800226E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800226EC: jr          $ra
    // 0x800226F0: nop

    return;
    // 0x800226F0: nop

;}
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
    // 0x8008C594: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
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
    // 0x8008C5B0: lbu         $t6, 0x5($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X5);
    // 0x8008C5B4: addu        $t7, $a0, $t4
    ctx->r15 = ADD32(ctx->r4, ctx->r12);
    // 0x8008C5B8: sb          $t6, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r14;
    // 0x8008C5BC: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8008C5C0: nop

    // 0x8008C5C4: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8008C5C8: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
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

    // 0x8008C5DC: sh          $t0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r8;
    // 0x8008C5E0: lhu         $t1, 0x6C($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X6C);
    // 0x8008C5E4: nop

    // 0x8008C5E8: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    // 0x8008C5EC: lbu         $t2, 0x64($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X64);
    // 0x8008C5F0: nop

    // 0x8008C5F4: andi        $t3, $t2, 0xE
    ctx->r11 = ctx->r10 & 0XE;
    // 0x8008C5F8: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8008C5FC: sh          $t5, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r13;
    // 0x8008C600: lbu         $t4, 0x64($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X64);
    // 0x8008C604: nop

    // 0x8008C608: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x8008C60C: sh          $t6, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r14;
    // 0x8008C610: lbu         $t7, 0x64($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X64);
    // 0x8008C614: nop

    // 0x8008C618: andi        $t9, $t7, 0xF0
    ctx->r25 = ctx->r15 & 0XF0;
    // 0x8008C61C: sra         $t8, $t9, 4
    ctx->r24 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8008C620: sh          $t8, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r24;
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
RECOMP_FUNC void alSaveNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF848: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF84C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CF850: addiu       $a2, $a2, 0x1D90
    ctx->r6 = ADD32(ctx->r6, 0X1D90);
    // 0x800CF854: addiu       $a1, $a1, 0x1DC4
    ctx->r5 = ADD32(ctx->r5, 0X1DC4);
    // 0x800CF858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CF85C: jal         0x800D56B0
    // 0x800CF860: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CF860: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x800CF864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CF868: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CF86C: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CF870: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800CF874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF87C: jr          $ra
    // 0x800CF880: nop

    return;
    // 0x800CF880: nop

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
RECOMP_FUNC void func_8008250C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008250C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80082510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082514: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80082518: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008251C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80082520: nop

    // 0x80082524: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x80082528: nop

    // 0x8008252C: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    // 0x80082530: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x80082534: nop

    // 0x80082538: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8008253C: bne         $t9, $zero, L_80082554
    if (ctx->r25 != 0) {
        // 0x80082540: nop
    
            goto L_80082554;
    }
    // 0x80082540: nop

    // 0x80082544: andi        $t0, $t8, 0x7F00
    ctx->r8 = ctx->r24 & 0X7F00;
    // 0x80082548: sra         $t1, $t0, 8
    ctx->r9 = S32(SIGNED(ctx->r8) >> 8);
    // 0x8008254C: bne         $t1, $zero, L_80082938
    if (ctx->r9 != 0) {
        // 0x80082550: nop
    
            goto L_80082938;
    }
    // 0x80082550: nop

L_80082554:
    // 0x80082554: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80082558: addiu       $t2, $t2, 0x3B8C
    ctx->r10 = ADD32(ctx->r10, 0X3B8C);
    // 0x8008255C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80082560: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80082564: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082568: beq         $t3, $at, L_80082938
    if (ctx->r11 == ctx->r1) {
        // 0x8008256C: nop
    
            goto L_80082938;
    }
    // 0x8008256C: nop

L_80082570:
    // 0x80082570: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80082574: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80082578: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008257C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80082580: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80082584: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80082588: lh          $t6, 0x3B8C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X3B8C);
    // 0x8008258C: nop

    // 0x80082590: bne         $t6, $t7, L_80082914
    if (ctx->r14 != ctx->r15) {
        // 0x80082594: nop
    
            goto L_80082914;
    }
    // 0x80082594: nop

    // 0x80082598: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008259C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800825A0: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800825A4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800825A8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800825AC: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x800825B0: lh          $t0, 0x3B8E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3B8E);
    // 0x800825B4: nop

    // 0x800825B8: bne         $t0, $t1, L_80082914
    if (ctx->r8 != ctx->r9) {
        // 0x800825BC: nop
    
            goto L_80082914;
    }
    // 0x800825BC: nop

    // 0x800825C0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800825C4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800825C8: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800825CC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800825D0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800825D4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800825D8: lh          $t9, 0x3B90($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X3B90);
    // 0x800825DC: andi        $t4, $t3, 0x3C
    ctx->r12 = ctx->r11 & 0X3C;
    // 0x800825E0: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x800825E4: bne         $t5, $t9, L_80082914
    if (ctx->r13 != ctx->r25) {
        // 0x800825E8: nop
    
            goto L_80082914;
    }
    // 0x800825E8: nop

    // 0x800825EC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800825F0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800825F4: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800825F8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800825FC: lh          $t1, 0x3B92($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3B92);
    // 0x80082600: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80082604: nop

    // 0x80082608: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x8008260C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80082610: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80082614: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80082618: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8008261C: lh          $t6, 0x3B94($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X3B94);
    // 0x80082620: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80082624: nop

    // 0x80082628: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x8008262C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80082630: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80082634: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80082638: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8008263C: lh          $t8, 0x3B92($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X3B92);
    // 0x80082640: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80082644: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80082648: lbu         $a0, -0x6230($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6230);
    // 0x8008264C: nop

    // 0x80082650: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80082654: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80082658: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008265C: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80082660: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80082664: jal         0x800BC6EC
    // 0x80082668: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80082668: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
    // 0x8008266C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80082670: nop

    // 0x80082674: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x80082678: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008267C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80082680: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80082684: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80082688: lh          $t4, 0x3B92($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X3B92);
    // 0x8008268C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80082690: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80082694: lbu         $a0, -0x6230($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6230);
    // 0x80082698: nop

    // 0x8008269C: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x800826A0: jal         0x800BC6EC
    // 0x800826A4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800826A4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x800826A8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800826AC: nop

    // 0x800826B0: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    // 0x800826B4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800826B8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800826BC: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x800826C0: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800826C4: lh          $t8, 0x3B96($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X3B96);
    // 0x800826C8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800826CC: nop

    // 0x800826D0: sh          $t8, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r24;
    // 0x800826D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800826D8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800826DC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800826E0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800826E4: lh          $t3, 0x3B98($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X3B98);
    // 0x800826E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800826EC: nop

    // 0x800826F0: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
    // 0x800826F4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800826F8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800826FC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80082700: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80082704: lh          $t5, 0x3B9A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X3B9A);
    // 0x80082708: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8008270C: nop

    // 0x80082710: sh          $t5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r13;
    // 0x80082714: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80082718: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008271C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80082720: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80082724: lh          $t2, 0x3B92($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X3B92);
    // 0x80082728: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8008272C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80082730: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x80082734: lbu         $a2, -0x6230($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X6230);
    // 0x80082738: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x8008273C: jal         0x800B1B3C
    // 0x80082740: addiu       $a1, $t8, 0xC
    ctx->r5 = ADD32(ctx->r24, 0XC);
    func_800B1B3C(rdram, ctx);
        goto after_2;
    // 0x80082740: addiu       $a1, $t8, 0xC
    ctx->r5 = ADD32(ctx->r24, 0XC);
    after_2:
    // 0x80082744: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80082748: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8008274C: sw          $t3, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r11;
    // 0x80082750: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80082754: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80082758: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008275C: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80082760: lh          $t5, 0x3B9C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X3B9C);
    // 0x80082764: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80082768: nop

    // 0x8008276C: sw          $t5, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r13;
    // 0x80082770: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80082774: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80082778: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8008277C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80082780: lh          $t1, 0x3B92($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3B92);
    // 0x80082784: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80082788: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8008278C: lbu         $t2, -0x6230($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6230);
    // 0x80082790: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80082794: blez        $t2, L_80082908
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80082798: nop
    
            goto L_80082908;
    }
    // 0x80082798: nop

L_8008279C:
    // 0x8008279C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800827A0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800827A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800827A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800827AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800827B0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800827B4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800827B8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800827BC: jal         0x80099E2C
    // 0x800827C0: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x800827C0: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    after_3:
    // 0x800827C4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800827C8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800827CC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800827D0: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800827D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800827D8: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x800827DC: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800827E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800827E4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x800827E8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800827EC: swc1        $f4, 0xD4($t1)
    MEM_W(0XD4, ctx->r9) = ctx->f4.u32l;
    // 0x800827F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800827F4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800827F8: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800827FC: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x80082800: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082804: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80082808: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008280C: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x80082810: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80082814: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80082818: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8008281C: swc1        $f6, 0xF4($t7)
    MEM_W(0XF4, ctx->r15) = ctx->f6.u32l;
    // 0x80082820: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082824: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80082828: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008282C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80082830: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80082834: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x80082838: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008283C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80082840: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80082844: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80082848: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008284C: swc1        $f8, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f8.u32l;
    // 0x80082850: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80082854: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80082858: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8008285C: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x80082860: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80082864: lw          $t3, 0x8($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X8);
    // 0x80082868: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x8008286C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80082870: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80082874: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x80082878: sh          $t2, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r10;
    // 0x8008287C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80082880: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80082884: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80082888: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x8008288C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80082890: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80082894: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x80082898: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8008289C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x800828A0: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x800828A4: sw          $t9, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r25;
    // 0x800828A8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800828AC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800828B0: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800828B4: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800828B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800828BC: lw          $t2, 0x8($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X8);
    // 0x800828C0: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x800828C4: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800828C8: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800828CC: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800828D0: sh          $t3, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r11;
    // 0x800828D4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800828D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800828DC: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800828E0: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x800828E4: lh          $t7, 0x3B92($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X3B92);
    // 0x800828E8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800828EC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800828F0: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800828F4: lbu         $t5, -0x6230($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X6230);
    // 0x800828F8: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x800828FC: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80082900: bne         $at, $zero, L_8008279C
    if (ctx->r1 != 0) {
        // 0x80082904: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_8008279C;
    }
    // 0x80082904: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_80082908:
    // 0x80082908: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8008290C: b           L_80082948
    // 0x80082910: nop

        goto L_80082948;
    // 0x80082910: nop

L_80082914:
    // 0x80082914: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082918: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008291C: addiu       $t8, $t2, 0x9
    ctx->r24 = ADD32(ctx->r10, 0X9);
    // 0x80082920: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80082924: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80082928: lh          $t1, 0x3B8C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3B8C);
    // 0x8008292C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082930: bne         $t1, $at, L_80082570
    if (ctx->r9 != ctx->r1) {
        // 0x80082934: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80082570;
    }
    // 0x80082934: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80082938:
    // 0x80082938: b           L_80082948
    // 0x8008293C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80082948;
    // 0x8008293C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80082940: b           L_80082948
    // 0x80082944: nop

        goto L_80082948;
    // 0x80082944: nop

L_80082948:
    // 0x80082948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008294C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80082950: jr          $ra
    // 0x80082954: nop

    return;
    // 0x80082954: nop

;}
RECOMP_FUNC void func_80048F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048F40: bne         $a0, $zero, L_80048F50
    if (ctx->r4 != 0) {
        // 0x80048F44: nop
    
            goto L_80048F50;
    }
    // 0x80048F44: nop

    // 0x80048F48: jr          $ra
    // 0x80048F4C: nop

    return;
    // 0x80048F4C: nop

L_80048F50:
    // 0x80048F50: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80048F54: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x80048F58: nop

    // 0x80048F5C: sh          $t6, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r14;
    // 0x80048F60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048F64: nop

    // 0x80048F68: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80048F6C: jr          $ra
    // 0x80048F70: nop

    return;
    // 0x80048F70: nop

    // 0x80048F74: jr          $ra
    // 0x80048F78: nop

    return;
    // 0x80048F78: nop

;}
RECOMP_FUNC void func_80060E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060EA4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80060EA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060EAC: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80060EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80060EB4: bne         $t6, $at, L_80060EC4
    if (ctx->r14 != ctx->r1) {
        // 0x80060EB8: nop
    
            goto L_80060EC4;
    }
    // 0x80060EB8: nop

    // 0x80060EBC: b           L_80060FA4
    // 0x80060EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060FA4;
    // 0x80060EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060EC4:
    // 0x80060EC4: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x80060EC8: lui         $t9, 0x809E
    ctx->r25 = S32(0X809E << 16);
    // 0x80060ECC: addiu       $t9, $t9, 0x55E0
    ctx->r25 = ADD32(ctx->r25, 0X55E0);
    // 0x80060ED0: lui         $a0, 0x6A
    ctx->r4 = S32(0X6A << 16);
    // 0x80060ED4: lui         $a1, 0x809B
    ctx->r5 = S32(0X809B << 16);
    // 0x80060ED8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80060EDC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80060EE0: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x80060EE4: jal         0x800BD1FC
    // 0x80060EE8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80060EE8: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    after_0:
    // 0x80060EEC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80060EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80060EF4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80060EF8: jal         0x800BD218
    // 0x80060EFC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80060EFC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80060F00: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
    // 0x80060F04: nop

    // 0x80060F08: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x80060F0C: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80060F10: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80060F14: nop

    // 0x80060F18: beq         $t2, $zero, L_80060F4C
    if (ctx->r10 == 0) {
        // 0x80060F1C: nop
    
            goto L_80060F4C;
    }
    // 0x80060F1C: nop

    // 0x80060F20: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80060F24: nop

    // 0x80060F28: jalr        $t9
    // 0x80060F2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80060F2C: nop

    after_2:
    // 0x80060F30: beq         $v0, $zero, L_80060F44
    if (ctx->r2 == 0) {
        // 0x80060F34: nop
    
            goto L_80060F44;
    }
    // 0x80060F34: nop

    // 0x80060F38: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x80060F3C: b           L_80060FA4
    // 0x80060F40: nop

        goto L_80060FA4;
    // 0x80060F40: nop

L_80060F44:
    // 0x80060F44: b           L_80060F58
    // 0x80060F48: nop

        goto L_80060F58;
    // 0x80060F48: nop

L_80060F4C:
    // 0x80060F4C: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x80060F50: b           L_80060FA4
    // 0x80060F54: nop

        goto L_80060FA4;
    // 0x80060F54: nop

L_80060F58:
    // 0x80060F58: lhu         $t3, 0x2C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2C);
    // 0x80060F5C: nop

    // 0x80060F60: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80060F64: beq         $t4, $zero, L_80060F80
    if (ctx->r12 == 0) {
        // 0x80060F68: nop
    
            goto L_80060F80;
    }
    // 0x80060F68: nop

    // 0x80060F6C: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80060F70: nop

    // 0x80060F74: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80060F78: b           L_80060F84
    // 0x80060F7C: sh          $t6, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r14;
        goto L_80060F84;
    // 0x80060F7C: sh          $t6, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r14;
L_80060F80:
    // 0x80060F80: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
L_80060F84:
    // 0x80060F84: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x80060F88: nop

    // 0x80060F8C: bne         $t7, $zero, L_80060EC4
    if (ctx->r15 != 0) {
        // 0x80060F90: nop
    
            goto L_80060EC4;
    }
    // 0x80060F90: nop

    // 0x80060F94: b           L_80060FA4
    // 0x80060F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060FA4;
    // 0x80060F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060F9C: b           L_80060FA4
    // 0x80060FA0: nop

        goto L_80060FA4;
    // 0x80060FA0: nop

L_80060FA4:
    // 0x80060FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060FA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060FAC: jr          $ra
    // 0x80060FB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80060FB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
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
RECOMP_FUNC void func_8005A7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A7C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A7C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A7C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005A7CC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8005A7D0: nop

    // 0x8005A7D4: lh          $t7, 0x4E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4E);
    // 0x8005A7D8: nop

    // 0x8005A7DC: beq         $t7, $zero, L_8005A7EC
    if (ctx->r15 == 0) {
        // 0x8005A7E0: nop
    
            goto L_8005A7EC;
    }
    // 0x8005A7E0: nop

    // 0x8005A7E4: b           L_8005A860
    // 0x8005A7E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A860;
    // 0x8005A7E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A7EC:
    // 0x8005A7EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005A7F0: addiu       $t8, $t8, 0x4C20
    ctx->r24 = ADD32(ctx->r24, 0X4C20);
    // 0x8005A7F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8005A7F8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8005A7FC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005A800: beq         $t9, $at, L_8005A850
    if (ctx->r25 == ctx->r1) {
        // 0x8005A804: nop
    
            goto L_8005A850;
    }
    // 0x8005A804: nop

L_8005A808:
    // 0x8005A808: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A80C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A810: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8005A814: lbu         $a0, 0x4C20($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4C20);
    // 0x8005A818: jal         0x8005F064
    // 0x8005A81C: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8005A81C: nop

    after_0:
    // 0x8005A820: bne         $v0, $zero, L_8005A830
    if (ctx->r2 != 0) {
        // 0x8005A824: nop
    
            goto L_8005A830;
    }
    // 0x8005A824: nop

    // 0x8005A828: b           L_8005A860
    // 0x8005A82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A860;
    // 0x8005A82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A830:
    // 0x8005A830: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A834: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8005A838: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8005A83C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005A840: lbu         $t3, 0x4C20($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4C20);
    // 0x8005A844: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005A848: bne         $t3, $at, L_8005A808
    if (ctx->r11 != ctx->r1) {
        // 0x8005A84C: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8005A808;
    }
    // 0x8005A84C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_8005A850:
    // 0x8005A850: b           L_8005A860
    // 0x8005A854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005A860;
    // 0x8005A854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A858: b           L_8005A860
    // 0x8005A85C: nop

        goto L_8005A860;
    // 0x8005A85C: nop

L_8005A860:
    // 0x8005A860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A864: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A868: jr          $ra
    // 0x8005A86C: nop

    return;
    // 0x8005A86C: nop

;}
RECOMP_FUNC void func_80077070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077078: jal         0x8005F064
    // 0x8007707C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8007707C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_0:
    // 0x80077080: b           L_80077090
    // 0x80077084: nop

        goto L_80077090;
    // 0x80077084: nop

    // 0x80077088: b           L_80077090
    // 0x8007708C: nop

        goto L_80077090;
    // 0x8007708C: nop

L_80077090:
    // 0x80077090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077098: jr          $ra
    // 0x8007709C: nop

    return;
    // 0x8007709C: nop

;}
RECOMP_FUNC void AudioDriver_ConfigSeqPlayerVolume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB52C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800BB530: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BB534: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800BB538: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800BB53C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BB540: beq         $a0, $at, L_800BB550
    if (ctx->r4 == ctx->r1) {
        // 0x800BB544: nop
    
            goto L_800BB550;
    }
    // 0x800BB544: nop

    // 0x800BB548: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB54C: sw          $a0, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r4;
L_800BB550:
    // 0x800BB550: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB554: sw          $a1, -0x17B8($at)
    MEM_W(-0X17B8, ctx->r1) = ctx->r5;
    // 0x800BB558: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BB55C: sw          $a2, -0x17B4($at)
    MEM_W(-0X17B4, ctx->r1) = ctx->r6;
    // 0x800BB560: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BB564: sw          $a3, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = ctx->r7;
    // 0x800BB568: jr          $ra
    // 0x800BB56C: nop

    return;
    // 0x800BB56C: nop

    // 0x800BB570: jr          $ra
    // 0x800BB574: nop

    return;
    // 0x800BB574: nop

;}
RECOMP_FUNC void func_8006F1B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F1B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F1BC: jal         0x80061348
    // 0x8006F1C0: addiu       $a0, $zero, 0x2CD
    ctx->r4 = ADD32(0, 0X2CD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F1C0: addiu       $a0, $zero, 0x2CD
    ctx->r4 = ADD32(0, 0X2CD);
    after_0:
    // 0x8006F1C4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F1C8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F1CC: b           L_8006F1DC
    // 0x8006F1D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F1DC;
    // 0x8006F1D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F1D4: b           L_8006F1DC
    // 0x8006F1D8: nop

        goto L_8006F1DC;
    // 0x8006F1D8: nop

L_8006F1DC:
    // 0x8006F1DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F1E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F1E4: jr          $ra
    // 0x8006F1E8: nop

    return;
    // 0x8006F1E8: nop

;}
RECOMP_FUNC void func_8006CBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CBF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CBF8: jal         0x80061488
    // 0x8006CBFC: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006CBFC: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    after_0:
    // 0x8006CC00: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006CC04: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006CC08: b           L_8006CC18
    // 0x8006CC0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006CC18;
    // 0x8006CC0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006CC10: b           L_8006CC18
    // 0x8006CC14: nop

        goto L_8006CC18;
    // 0x8006CC14: nop

L_8006CC18:
    // 0x8006CC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CC1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CC20: jr          $ra
    // 0x8006CC24: nop

    return;
    // 0x8006CC24: nop

;}
RECOMP_FUNC void func_8006EE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EE50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EE54: jal         0x80061348
    // 0x8006EE58: addiu       $a0, $zero, 0x14E
    ctx->r4 = ADD32(0, 0X14E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EE58: addiu       $a0, $zero, 0x14E
    ctx->r4 = ADD32(0, 0X14E);
    after_0:
    // 0x8006EE5C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EE60: b           L_8006EE70
    // 0x8006EE64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EE70;
    // 0x8006EE64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EE68: b           L_8006EE70
    // 0x8006EE6C: nop

        goto L_8006EE70;
    // 0x8006EE6C: nop

L_8006EE70:
    // 0x8006EE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EE74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EE78: jr          $ra
    // 0x8006EE7C: nop

    return;
    // 0x8006EE7C: nop

;}
RECOMP_FUNC void alBnkfNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C83E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C83E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C83EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C83F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C83F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C83F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C83FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C8400: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800C8404: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x800C8408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C840C: bne         $t6, $at, L_800C84C8
    if (ctx->r14 != ctx->r1) {
        // 0x800C8410: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_800C84C8;
    }
    // 0x800C8410: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C8414: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800C8418: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C841C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C8420: blez        $t7, L_800C84C8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C8424: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800C84C8;
    }
    // 0x800C8424: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800C8428: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
L_800C842C:
    // 0x800C842C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800C8430: beq         $t9, $zero, L_800C84B0
    if (ctx->r25 == 0) {
        // 0x800C8434: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_800C84B0;
    }
    // 0x800C8434: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x800C8438: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800C843C: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800C8440: bnel        $t6, $zero, L_800C84B4
    if (ctx->r14 != 0) {
        // 0x800C8444: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C84B4;
    }
    goto skip_0;
    // 0x800C8444: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x800C8448: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x800C844C: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x800C8450: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800C8454: beq         $v0, $zero, L_800C846C
    if (ctx->r2 == 0) {
        // 0x800C8458: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_800C846C;
    }
    // 0x800C8458: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800C845C: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x800C8460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C8464: jal         0x800C82F0
    // 0x800C8468: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_5_800C82F0(rdram, ctx);
        goto after_0;
    // 0x800C8468: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_800C846C:
    // 0x800C846C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x800C8470: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C8474: blezl       $t8, L_800C84B4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C8478: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C84B4;
    }
    goto skip_1;
    // 0x800C8478: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x800C847C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
L_800C8480:
    // 0x800C8480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C8484: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x800C8488: beq         $a0, $zero, L_800C8498
    if (ctx->r4 == 0) {
        // 0x800C848C: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_800C8498;
    }
    // 0x800C848C: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x800C8490: jal         0x800C82F0
    // 0x800C8494: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_5_800C82F0(rdram, ctx);
        goto after_1;
    // 0x800C8494: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_800C8498:
    // 0x800C8498: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800C849C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C84A0: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C84A4: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C84A8: bnel        $at, $zero, L_800C8480
    if (ctx->r1 != 0) {
        // 0x800C84AC: lw          $t9, 0xC($t3)
        ctx->r25 = MEM_W(ctx->r11, 0XC);
            goto L_800C8480;
    }
    goto skip_2;
    // 0x800C84AC: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    skip_2:
L_800C84B0:
    // 0x800C84B0: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_800C84B4:
    // 0x800C84B4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C84B8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C84BC: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C84C0: bnel        $at, $zero, L_800C842C
    if (ctx->r1 != 0) {
        // 0x800C84C4: lw          $t8, 0x4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X4);
            goto L_800C842C;
    }
    goto skip_3;
    // 0x800C84C4: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    skip_3:
L_800C84C8:
    // 0x800C84C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C84CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C84D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C84D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C84D8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C84DC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C84E0: jr          $ra
    // 0x800C84E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C84E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80073228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073228: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007322C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073230: nop

    // 0x80073234: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80073238: nop

    // 0x8007323C: slti        $t7, $v0, 0x1AE
    ctx->r15 = SIGNED(ctx->r2) < 0X1AE ? 1 : 0;
    // 0x80073240: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073244: jr          $ra
    // 0x80073248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007324C: jr          $ra
    // 0x80073250: nop

    return;
    // 0x80073250: nop

    // 0x80073254: jr          $ra
    // 0x80073258: nop

    return;
    // 0x80073258: nop

;}
RECOMP_FUNC void TempHeap_Mark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D520: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000D524: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8000D528: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x8000D52C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8000D530: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8000D534: nop

    // 0x8000D538: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000D53C: nop

    // 0x8000D540: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000D544: bne         $t9, $zero, L_8000D554
    if (ctx->r25 != 0) {
        // 0x8000D548: nop
    
            goto L_8000D554;
    }
    // 0x8000D548: nop

    // 0x8000D54C: b           L_8000D574
    // 0x8000D550: nop

        goto L_8000D574;
    // 0x8000D550: nop

L_8000D554:
    // 0x8000D554: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8000D558: nop

    // 0x8000D55C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000D560: nop

    // 0x8000D564: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8000D568: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8000D56C: b           L_8000D574
    // 0x8000D570: nop

        goto L_8000D574;
    // 0x8000D570: nop

L_8000D574:
    // 0x8000D574: jr          $ra
    // 0x8000D578: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000D578: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80063CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063CAC: jal         0x8005F064
    // 0x80063CB0: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063CB0: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x80063CB4: b           L_80063CC4
    // 0x80063CB8: nop

        goto L_80063CC4;
    // 0x80063CB8: nop

    // 0x80063CBC: b           L_80063CC4
    // 0x80063CC0: nop

        goto L_80063CC4;
    // 0x80063CC0: nop

L_80063CC4:
    // 0x80063CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063CC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063CCC: jr          $ra
    // 0x80063CD0: nop

    return;
    // 0x80063CD0: nop

;}
RECOMP_FUNC void Scheduler_ExecuteTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097DDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80097DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097DE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80097DE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80097DEC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80097DF0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80097DF4: nop

    // 0x80097DF8: beq         $t6, $zero, L_80097E84
    if (ctx->r14 == 0) {
        // 0x80097DFC: nop
    
            goto L_80097E84;
    }
    // 0x80097DFC: nop

    // 0x80097E00: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80097E04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80097E08: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80097E0C: nop

    // 0x80097E10: bne         $t8, $at, L_80097E20
    if (ctx->r24 != ctx->r1) {
        // 0x80097E14: nop
    
            goto L_80097E20;
    }
    // 0x80097E14: nop

    // 0x80097E18: jal         0x800C4270
    // 0x80097E1C: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80097E1C: nop

    after_0:
L_80097E20:
    // 0x80097E20: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097E24: addiu       $at, $zero, -0x31
    ctx->r1 = ADD32(0, -0X31);
    // 0x80097E28: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80097E2C: nop

    // 0x80097E30: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80097E34: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80097E38: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80097E3C: jal         0x800C4F5C
    // 0x80097E40: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_1;
    // 0x80097E40: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x80097E44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80097E48: jal         0x800C50BC
    // 0x80097E4C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_2;
    // 0x80097E4C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_2:
    // 0x80097E50: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80097E54: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80097E58: nop

    // 0x80097E5C: sw          $t2, 0x294($t3)
    MEM_W(0X294, ctx->r11) = ctx->r10;
    // 0x80097E60: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80097E64: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80097E68: nop

    // 0x80097E6C: bne         $t4, $t5, L_80097E84
    if (ctx->r12 != ctx->r13) {
        // 0x80097E70: nop
    
            goto L_80097E84;
    }
    // 0x80097E70: nop

    // 0x80097E74: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097E78: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80097E7C: nop

    // 0x80097E80: sw          $t6, 0x298($t7)
    MEM_W(0X298, ctx->r15) = ctx->r14;
L_80097E84:
    // 0x80097E84: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097E88: nop

    // 0x80097E8C: beq         $t8, $zero, L_80097EEC
    if (ctx->r24 == 0) {
        // 0x80097E90: nop
    
            goto L_80097EEC;
    }
    // 0x80097E90: nop

    // 0x80097E94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097E98: nop

    // 0x80097E9C: beq         $t8, $t0, L_80097EEC
    if (ctx->r24 == ctx->r8) {
        // 0x80097EA0: nop
    
            goto L_80097EEC;
    }
    // 0x80097EA0: nop

    // 0x80097EA4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80097EA8: nop

    // 0x80097EAC: lw          $t9, 0x3C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X3C);
    // 0x80097EB0: lw          $a0, 0x38($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X38);
    // 0x80097EB4: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80097EB8: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x80097EBC: jal         0x800C5100
    // 0x80097EC0: nop

    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80097EC0: nop

    after_3:
    // 0x80097EC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097EC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80097ECC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80097ED0: sw          $t2, -0x734C($at)
    MEM_W(-0X734C, ctx->r1) = ctx->r10;
    // 0x80097ED4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80097ED8: sw          $zero, -0x7348($at)
    MEM_W(-0X7348, ctx->r1) = 0;
    // 0x80097EDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80097EE0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80097EE4: nop

    // 0x80097EE8: sw          $t3, 0x298($t4)
    MEM_W(0X298, ctx->r12) = ctx->r11;
L_80097EEC:
    // 0x80097EEC: b           L_80097EF4
    // 0x80097EF0: nop

        goto L_80097EF4;
    // 0x80097EF0: nop

L_80097EF4:
    // 0x80097EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097EF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097EFC: jr          $ra
    // 0x80097F00: nop

    return;
    // 0x80097F00: nop

;}
RECOMP_FUNC void __voiceNeedsNoteKill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D233C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2340: lw          $a3, 0x50($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X50);
    // 0x800D2344: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D2348: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800D234C: beq         $a3, $zero, L_800D23CC
    if (ctx->r7 == 0) {
        // 0x800D2350: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800D23CC;
    }
    // 0x800D2350: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D2354: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800D2358:
    // 0x800D2358: lh          $t6, 0xC($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XC);
    // 0x800D235C: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x800D2360: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800D2364: bne         $a0, $t6, L_800D23C4
    if (ctx->r4 != ctx->r14) {
        // 0x800D2368: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_800D23C4;
    }
    // 0x800D2368: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x800D236C: lw          $t7, 0x10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X10);
    // 0x800D2370: bne         $a1, $t7, L_800D23C4
    if (ctx->r5 != ctx->r15) {
        // 0x800D2374: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800D23C4;
    }
    // 0x800D2374: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D2378: beq         $at, $zero, L_800D23BC
    if (ctx->r1 == 0) {
        // 0x800D237C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800D23BC;
    }
    // 0x800D237C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D2380: beql        $v0, $zero, L_800D2398
    if (ctx->r2 == 0) {
        // 0x800D2384: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800D2398;
    }
    goto skip_0;
    // 0x800D2384: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    skip_0:
    // 0x800D2388: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800D238C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800D2390: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800D2394: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
L_800D2398:
    // 0x800D2398: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    // 0x800D239C: jal         0x800C7890
    // 0x800D23A0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800D23A0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_0:
    // 0x800D23A4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800D23A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800D23AC: jal         0x800C78C0
    // 0x800D23B0: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800D23B0: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    after_1:
    // 0x800D23B4: b           L_800D23CC
    // 0x800D23B8: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
        goto L_800D23CC;
    // 0x800D23B8: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
L_800D23BC:
    // 0x800D23BC: b           L_800D23CC
    // 0x800D23C0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_800D23CC;
    // 0x800D23C0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800D23C4:
    // 0x800D23C4: bne         $v0, $zero, L_800D2358
    if (ctx->r2 != 0) {
        // 0x800D23C8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800D2358;
    }
    // 0x800D23C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800D23CC:
    // 0x800D23CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D23D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D23D4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D23D8: jr          $ra
    // 0x800D23DC: nop

    return;
    // 0x800D23DC: nop

;}
RECOMP_FUNC void func_800C0194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0194: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C0198: lw          $t6, 0x484($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X484);
    // 0x800C019C: nop

    // 0x800C01A0: beq         $t6, $zero, L_800C01C4
    if (ctx->r14 == 0) {
        // 0x800C01A4: nop
    
            goto L_800C01C4;
    }
    // 0x800C01A4: nop

    // 0x800C01A8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800C01AC: lw          $t7, 0x43C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X43C);
    // 0x800C01B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C01B4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C01B8: sw          $t8, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r24;
    // 0x800C01BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C01C0: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
L_800C01C4:
    // 0x800C01C4: jr          $ra
    // 0x800C01C8: nop

    return;
    // 0x800C01C8: nop

    // 0x800C01CC: jr          $ra
    // 0x800C01D0: nop

    return;
    // 0x800C01D0: nop

;}
RECOMP_FUNC void func_8001173C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001173C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80011740: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80011744: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80011748: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001174C: sb          $zero, 0x39($sp)
    MEM_B(0X39, ctx->r29) = 0;
    // 0x80011750: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80011754: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80011758: jal         0x8000DA44
    // 0x8001175C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x8001175C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80011760: bgez        $v0, L_80011770
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011764: nop
    
            goto L_80011770;
    }
    // 0x80011764: nop

    // 0x80011768: b           L_800119FC
    // 0x8001176C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800119FC;
    // 0x8001176C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011770:
    // 0x80011770: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80011774: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80011778: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x8001177C: nop

    // 0x80011780: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011784: bne         $at, $zero, L_800117A4
    if (ctx->r1 != 0) {
        // 0x80011788: nop
    
            goto L_800117A4;
    }
    // 0x80011788: nop

    // 0x8001178C: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80011790: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011794: beq         $at, $zero, L_800117A4
    if (ctx->r1 == 0) {
        // 0x80011798: nop
    
            goto L_800117A4;
    }
    // 0x80011798: nop

    // 0x8001179C: b           L_800119FC
    // 0x800117A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800119FC;
    // 0x800117A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800117A4:
    // 0x800117A4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800117A8: nop

    // 0x800117AC: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x800117B0: nop

    // 0x800117B4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800117B8: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x800117BC: lhu         $t1, 0xA($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XA);
    // 0x800117C0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800117C4: bne         $t1, $at, L_800117DC
    if (ctx->r9 != ctx->r1) {
        // 0x800117C8: nop
    
            goto L_800117DC;
    }
    // 0x800117C8: nop

    // 0x800117CC: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    // 0x800117D0: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x800117D4: b           L_800117F0
    // 0x800117D8: sh          $t3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r11;
        goto L_800117F0;
    // 0x800117D8: sh          $t3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r11;
L_800117DC:
    // 0x800117DC: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x800117E0: lhu         $a0, 0x4($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X4);
    // 0x800117E4: jal         0x80056E88
    // 0x800117E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80056E88(rdram, ctx);
        goto after_1;
    // 0x800117E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800117EC: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
L_800117F0:
    // 0x800117F0: addiu       $t5, $sp, 0x40
    ctx->r13 = ADD32(ctx->r29, 0X40);
    // 0x800117F4: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x800117F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800117FC: bne         $t6, $at, L_80011814
    if (ctx->r14 != ctx->r1) {
        // 0x80011800: nop
    
            goto L_80011814;
    }
    // 0x80011800: nop

    // 0x80011804: lbu         $t7, 0x39($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X39);
    // 0x80011808: nop

    // 0x8001180C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80011810: sb          $t8, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r24;
L_80011814:
    // 0x80011814: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80011818: lh          $t2, 0x3A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3A);
    // 0x8001181C: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x80011820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011824: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80011828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001182C: addiu       $a0, $t9, 0x60
    ctx->r4 = ADD32(ctx->r25, 0X60);
    // 0x80011830: jal         0x800B3230
    // 0x80011834: or          $a3, $t1, $t2
    ctx->r7 = ctx->r9 | ctx->r10;
    func_800B3230(rdram, ctx);
        goto after_2;
    // 0x80011834: or          $a3, $t1, $t2
    ctx->r7 = ctx->r9 | ctx->r10;
    after_2:
    // 0x80011838: bgez        $v0, L_80011878
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001183C: nop
    
            goto L_80011878;
    }
    // 0x8001183C: nop

    // 0x80011840: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80011844: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80011848: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001184C: nop

    // 0x80011850: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80011854: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
    // 0x80011858: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8001185C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80011860: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80011864: nop

    // 0x80011868: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8001186C: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80011870: b           L_800119FC
    // 0x80011874: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800119FC;
    // 0x80011874: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011878:
    // 0x80011878: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8001187C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80011880: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80011884: nop

    // 0x80011888: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8001188C: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x80011890: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    // 0x80011894: lhu         $t4, 0x8($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X8);
    // 0x80011898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001189C: bne         $t4, $at, L_8001192C
    if (ctx->r12 != ctx->r1) {
        // 0x800118A0: nop
    
            goto L_8001192C;
    }
    // 0x800118A0: nop

    // 0x800118A4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800118A8: nop

    // 0x800118AC: lhu         $t3, 0x60($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X60);
    // 0x800118B0: nop

    // 0x800118B4: andi        $t7, $t3, 0x1
    ctx->r15 = ctx->r11 & 0X1;
    // 0x800118B8: beq         $t7, $zero, L_8001192C
    if (ctx->r15 == 0) {
        // 0x800118BC: nop
    
            goto L_8001192C;
    }
    // 0x800118BC: nop

    // 0x800118C0: lbu         $t8, 0x39($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X39);
    // 0x800118C4: nop

    // 0x800118C8: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x800118CC: sb          $t6, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r14;
    // 0x800118D0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800118D4: nop

    // 0x800118D8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800118DC: nop

    // 0x800118E0: ori         $t9, $t1, 0x10
    ctx->r25 = ctx->r9 | 0X10;
    // 0x800118E4: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800118E8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800118EC: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x800118F0: sh          $t2, 0x62($t4)
    MEM_H(0X62, ctx->r12) = ctx->r10;
    // 0x800118F4: addiu       $t5, $sp, 0x40
    ctx->r13 = ADD32(ctx->r29, 0X40);
    // 0x800118F8: lhu         $t3, 0x2($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X2);
    // 0x800118FC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80011900: nop

    // 0x80011904: sh          $t3, 0x64($t7)
    MEM_H(0X64, ctx->r15) = ctx->r11;
    // 0x80011908: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8001190C: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x80011910: sh          $t8, 0x66($t6)
    MEM_H(0X66, ctx->r14) = ctx->r24;
    // 0x80011914: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80011918: nop

    // 0x8001191C: lw          $t9, 0x1A8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X1A8);
    // 0x80011920: nop

    // 0x80011924: ori         $t0, $t9, 0x100
    ctx->r8 = ctx->r25 | 0X100;
    // 0x80011928: sw          $t0, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r8;
L_8001192C:
    // 0x8001192C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80011930: lh          $t3, 0x3A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X3A);
    // 0x80011934: lw          $t7, 0xC($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XC);
    // 0x80011938: lhu         $t4, 0x2($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X2);
    // 0x8001193C: lwc1        $f4, 0xCC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80011940: lhu         $a3, 0x4($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X4);
    // 0x80011944: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80011948: lbu         $t8, 0x39($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X39);
    // 0x8001194C: lwc1        $f6, 0xD0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x80011950: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80011954: addiu       $a0, $t2, 0xC
    ctx->r4 = ADD32(ctx->r10, 0XC);
    // 0x80011958: addiu       $a1, $t2, 0x10
    ctx->r5 = ADD32(ctx->r10, 0X10);
    // 0x8001195C: or          $a2, $t5, $t3
    ctx->r6 = ctx->r13 | ctx->r11;
    // 0x80011960: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80011964: jal         0x800B202C
    // 0x80011968: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_3;
    // 0x80011968: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8001196C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80011970: nop

    // 0x80011974: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    // 0x80011978: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8001197C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80011980: jal         0x800B334C
    // 0x80011984: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800B334C(rdram, ctx);
        goto after_4;
    // 0x80011984: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_4:
    // 0x80011988: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8001198C: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80011990: lhu         $t0, 0x66($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X66);
    // 0x80011994: nop

    // 0x80011998: and         $t1, $t0, $s0
    ctx->r9 = ctx->r8 & ctx->r16;
    // 0x8001199C: beq         $t1, $zero, L_800119BC
    if (ctx->r9 == 0) {
        // 0x800119A0: nop
    
            goto L_800119BC;
    }
    // 0x800119A0: nop

    // 0x800119A4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800119A8: nop

    // 0x800119AC: sh          $zero, 0x62($t4)
    MEM_H(0X62, ctx->r12) = 0;
    // 0x800119B0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800119B4: jal         0x8000F4B0
    // 0x800119B8: nop

    func_8000F4B0(rdram, ctx);
        goto after_5;
    // 0x800119B8: nop

    after_5:
L_800119BC:
    // 0x800119BC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800119C0: nop

    // 0x800119C4: lhu         $t3, 0x0($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X0);
    // 0x800119C8: nop

    // 0x800119CC: ori         $t2, $t3, 0x2
    ctx->r10 = ctx->r11 | 0X2;
    // 0x800119D0: sh          $t2, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r10;
    // 0x800119D4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800119D8: nop

    // 0x800119DC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800119E0: nop

    // 0x800119E4: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x800119E8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x800119EC: b           L_800119FC
    // 0x800119F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800119FC;
    // 0x800119F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800119F4: b           L_800119FC
    // 0x800119F8: nop

        goto L_800119FC;
    // 0x800119F8: nop

L_800119FC:
    // 0x800119FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80011A00: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80011A04: jr          $ra
    // 0x80011A08: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80011A08: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8007AA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AA90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007AA94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007AA98: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007AA9C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007AAA0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007AAA4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8007AAA8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8007AAAC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007AAB0: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007AAB4: nop

    // 0x8007AAB8: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x8007AABC: beq         $t8, $zero, L_8007AACC
    if (ctx->r24 == 0) {
        // 0x8007AAC0: nop
    
            goto L_8007AACC;
    }
    // 0x8007AAC0: nop

    // 0x8007AAC4: b           L_8007B11C
    // 0x8007AAC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B11C;
    // 0x8007AAC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AACC:
    // 0x8007AACC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007AAD0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8007AAD4: lhu         $t0, 0xEEC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XEEC);
    // 0x8007AAD8: lhu         $t9, 0x7146($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7146);
    // 0x8007AADC: nop

    // 0x8007AAE0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8007AAE4: beq         $t1, $zero, L_8007ACA8
    if (ctx->r9 == 0) {
        // 0x8007AAE8: nop
    
            goto L_8007ACA8;
    }
    // 0x8007AAE8: nop

    // 0x8007AAEC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007AAF0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8007AAF4: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8007AAF8: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8007AAFC: lwc1        $f4, 0x10($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X10);
    // 0x8007AB00: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8007AB04: nop

    // 0x8007AB08: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8007AB0C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007AB10: lbu         $t5, 0x7134($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7134);
    // 0x8007AB14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007AB18: bne         $t5, $at, L_8007ABD8
    if (ctx->r13 != ctx->r1) {
        // 0x8007AB1C: nop
    
            goto L_8007ABD8;
    }
    // 0x8007AB1C: nop

    // 0x8007AB20: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007AB24: lb          $t6, 0x7142($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7142);
    // 0x8007AB28: nop

    // 0x8007AB2C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007AB30: slti        $at, $t7, 0x28
    ctx->r1 = SIGNED(ctx->r15) < 0X28 ? 1 : 0;
    // 0x8007AB34: beq         $at, $zero, L_8007AB9C
    if (ctx->r1 == 0) {
        // 0x8007AB38: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8007AB9C;
    }
    // 0x8007AB38: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007AB3C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007AB40: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007AB44: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007AB48: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007AB4C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007AB50: lh          $t9, 0x2460($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2460);
    // 0x8007AB54: nop

    // 0x8007AB58: bgez        $t9, L_8007AB9C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007AB5C: nop
    
            goto L_8007AB9C;
    }
    // 0x8007AB5C: nop

L_8007AB60:
    // 0x8007AB60: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AB64: nop

    // 0x8007AB68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8007AB6C: slti        $at, $t1, 0x28
    ctx->r1 = SIGNED(ctx->r9) < 0X28 ? 1 : 0;
    // 0x8007AB70: beq         $at, $zero, L_8007AB9C
    if (ctx->r1 == 0) {
        // 0x8007AB74: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8007AB9C;
    }
    // 0x8007AB74: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8007AB78: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007AB7C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8007AB80: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007AB84: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8007AB88: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007AB8C: lh          $t3, 0x2460($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2460);
    // 0x8007AB90: nop

    // 0x8007AB94: bltz        $t3, L_8007AB60
    if (SIGNED(ctx->r11) < 0) {
        // 0x8007AB98: nop
    
            goto L_8007AB60;
    }
    // 0x8007AB98: nop

L_8007AB9C:
    // 0x8007AB9C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007ABA0: nop

    // 0x8007ABA4: slti        $at, $t4, 0x28
    ctx->r1 = SIGNED(ctx->r12) < 0X28 ? 1 : 0;
    // 0x8007ABA8: bne         $at, $zero, L_8007ABBC
    if (ctx->r1 != 0) {
        // 0x8007ABAC: nop
    
            goto L_8007ABBC;
    }
    // 0x8007ABAC: nop

    // 0x8007ABB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ABB4: b           L_8007ABC8
    // 0x8007ABB8: sb          $zero, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = 0;
        goto L_8007ABC8;
    // 0x8007ABB8: sb          $zero, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = 0;
L_8007ABBC:
    // 0x8007ABBC: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x8007ABC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ABC4: sb          $t5, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r13;
L_8007ABC8:
    // 0x8007ABC8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007ABCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007ABD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ABD4: swc1        $f6, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f6.u32l;
L_8007ABD8:
    // 0x8007ABD8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007ABDC: lbu         $t6, 0x7134($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7134);
    // 0x8007ABE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007ABE4: bne         $t6, $at, L_8007AC60
    if (ctx->r14 != ctx->r1) {
        // 0x8007ABE8: nop
    
            goto L_8007AC60;
    }
    // 0x8007ABE8: nop

    // 0x8007ABEC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007ABF0: lw          $a0, 0x70FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70FC);
    // 0x8007ABF4: jal         0x8007A514
    // 0x8007ABF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8007A514(rdram, ctx);
        goto after_0;
    // 0x8007ABF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8007ABFC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007AC00: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007AC04: nop

    // 0x8007AC08: beq         $t7, $zero, L_8007AC20
    if (ctx->r15 == 0) {
        // 0x8007AC0C: nop
    
            goto L_8007AC20;
    }
    // 0x8007AC0C: nop

    // 0x8007AC10: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007AC14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AC18: b           L_8007AC34
    // 0x8007AC1C: sw          $t8, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r24;
        goto L_8007AC34;
    // 0x8007AC1C: sw          $t8, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r24;
L_8007AC20:
    // 0x8007AC20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007AC24: jal         0x8007A514
    // 0x8007AC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8007A514(rdram, ctx);
        goto after_1;
    // 0x8007AC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8007AC2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AC30: sw          $v0, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r2;
L_8007AC34:
    // 0x8007AC34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007AC38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007AC3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AC40: swc1        $f8, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f8.u32l;
    // 0x8007AC44: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007AC48: lw          $t9, 0x70FC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70FC);
    // 0x8007AC4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AC50: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8007AC54: nop

    // 0x8007AC58: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007AC5C: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
L_8007AC60:
    // 0x8007AC60: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007AC64: lbu         $t2, 0x7134($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7134);
    // 0x8007AC68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007AC6C: bne         $t2, $at, L_8007ACA8
    if (ctx->r10 != ctx->r1) {
        // 0x8007AC70: nop
    
            goto L_8007ACA8;
    }
    // 0x8007AC70: nop

    // 0x8007AC74: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007AC78: lh          $t3, 0x7132($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7132);
    // 0x8007AC7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007AC80: beq         $t3, $at, L_8007AC9C
    if (ctx->r11 == ctx->r1) {
        // 0x8007AC84: nop
    
            goto L_8007AC9C;
    }
    // 0x8007AC84: nop

    // 0x8007AC88: beq         $t3, $zero, L_8007AC9C
    if (ctx->r11 == 0) {
        // 0x8007AC8C: nop
    
            goto L_8007AC9C;
    }
    // 0x8007AC8C: nop

    // 0x8007AC90: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007AC94: bne         $t3, $at, L_8007ACA8
    if (ctx->r11 != ctx->r1) {
        // 0x8007AC98: nop
    
            goto L_8007ACA8;
    }
    // 0x8007AC98: nop

L_8007AC9C:
    // 0x8007AC9C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007ACA0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007ACA4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_8007ACA8:
    // 0x8007ACA8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007ACAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007ACB0: lhu         $t6, 0xEC0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XEC0);
    // 0x8007ACB4: lhu         $t5, 0x7146($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7146);
    // 0x8007ACB8: nop

    // 0x8007ACBC: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8007ACC0: beq         $t7, $zero, L_8007AE7C
    if (ctx->r15 == 0) {
        // 0x8007ACC4: nop
    
            goto L_8007AE7C;
    }
    // 0x8007ACC4: nop

    // 0x8007ACC8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007ACCC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007ACD0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8007ACD4: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8007ACD8: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8007ACDC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007ACE0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8007ACE4: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x8007ACE8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007ACEC: lbu         $t1, 0x7134($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7134);
    // 0x8007ACF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007ACF4: bne         $t1, $at, L_8007ADAC
    if (ctx->r9 != ctx->r1) {
        // 0x8007ACF8: nop
    
            goto L_8007ADAC;
    }
    // 0x8007ACF8: nop

    // 0x8007ACFC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007AD00: lb          $t2, 0x7142($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7142);
    // 0x8007AD04: nop

    // 0x8007AD08: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8007AD0C: bltz        $t3, L_8007AD70
    if (SIGNED(ctx->r11) < 0) {
        // 0x8007AD10: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_8007AD70;
    }
    // 0x8007AD10: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8007AD14: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007AD18: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007AD1C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007AD20: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007AD24: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8007AD28: lh          $t5, 0x2460($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2460);
    // 0x8007AD2C: nop

    // 0x8007AD30: bgez        $t5, L_8007AD70
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007AD34: nop
    
            goto L_8007AD70;
    }
    // 0x8007AD34: nop

L_8007AD38:
    // 0x8007AD38: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AD3C: nop

    // 0x8007AD40: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007AD44: bltz        $t7, L_8007AD70
    if (SIGNED(ctx->r15) < 0) {
        // 0x8007AD48: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8007AD70;
    }
    // 0x8007AD48: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007AD4C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007AD50: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007AD54: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007AD58: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007AD5C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007AD60: lh          $t9, 0x2460($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2460);
    // 0x8007AD64: nop

    // 0x8007AD68: bltz        $t9, L_8007AD38
    if (SIGNED(ctx->r25) < 0) {
        // 0x8007AD6C: nop
    
            goto L_8007AD38;
    }
    // 0x8007AD6C: nop

L_8007AD70:
    // 0x8007AD70: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AD74: nop

    // 0x8007AD78: bgez        $t0, L_8007AD90
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007AD7C: nop
    
            goto L_8007AD90;
    }
    // 0x8007AD7C: nop

    // 0x8007AD80: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x8007AD84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AD88: b           L_8007AD9C
    // 0x8007AD8C: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
        goto L_8007AD9C;
    // 0x8007AD8C: sb          $t1, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r9;
L_8007AD90:
    // 0x8007AD90: lh          $t2, 0x1E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1E);
    // 0x8007AD94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AD98: sb          $t2, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r10;
L_8007AD9C:
    // 0x8007AD9C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007ADA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007ADA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ADA8: swc1        $f18, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f18.u32l;
L_8007ADAC:
    // 0x8007ADAC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007ADB0: lbu         $t3, 0x7134($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7134);
    // 0x8007ADB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007ADB8: bne         $t3, $at, L_8007AE34
    if (ctx->r11 != ctx->r1) {
        // 0x8007ADBC: nop
    
            goto L_8007AE34;
    }
    // 0x8007ADBC: nop

    // 0x8007ADC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007ADC4: lw          $a0, 0x70FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70FC);
    // 0x8007ADC8: jal         0x8007A514
    // 0x8007ADCC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8007A514(rdram, ctx);
        goto after_2;
    // 0x8007ADCC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8007ADD0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007ADD4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8007ADD8: nop

    // 0x8007ADDC: beq         $t4, $zero, L_8007ADF4
    if (ctx->r12 == 0) {
        // 0x8007ADE0: nop
    
            goto L_8007ADF4;
    }
    // 0x8007ADE0: nop

    // 0x8007ADE4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007ADE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007ADEC: b           L_8007AE08
    // 0x8007ADF0: sw          $t5, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r13;
        goto L_8007AE08;
    // 0x8007ADF0: sw          $t5, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r13;
L_8007ADF4:
    // 0x8007ADF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007ADF8: jal         0x8007A514
    // 0x8007ADFC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8007A514(rdram, ctx);
        goto after_3;
    // 0x8007ADFC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8007AE00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AE04: sw          $v0, 0x70FC($at)
    MEM_W(0X70FC, ctx->r1) = ctx->r2;
L_8007AE08:
    // 0x8007AE08: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007AE0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007AE10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AE14: swc1        $f4, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f4.u32l;
    // 0x8007AE18: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007AE1C: lw          $t6, 0x70FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70FC);
    // 0x8007AE20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AE24: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8007AE28: nop

    // 0x8007AE2C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007AE30: sb          $t8, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r24;
L_8007AE34:
    // 0x8007AE34: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007AE38: lbu         $t9, 0x7134($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7134);
    // 0x8007AE3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007AE40: bne         $t9, $at, L_8007AE7C
    if (ctx->r25 != ctx->r1) {
        // 0x8007AE44: nop
    
            goto L_8007AE7C;
    }
    // 0x8007AE44: nop

    // 0x8007AE48: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007AE4C: lh          $t0, 0x7132($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7132);
    // 0x8007AE50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007AE54: beq         $t0, $at, L_8007AE70
    if (ctx->r8 == ctx->r1) {
        // 0x8007AE58: nop
    
            goto L_8007AE70;
    }
    // 0x8007AE58: nop

    // 0x8007AE5C: beq         $t0, $zero, L_8007AE70
    if (ctx->r8 == 0) {
        // 0x8007AE60: nop
    
            goto L_8007AE70;
    }
    // 0x8007AE60: nop

    // 0x8007AE64: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007AE68: bne         $t0, $at, L_8007AE7C
    if (ctx->r8 != ctx->r1) {
        // 0x8007AE6C: nop
    
            goto L_8007AE7C;
    }
    // 0x8007AE6C: nop

L_8007AE70:
    // 0x8007AE70: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007AE74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007AE78: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_8007AE7C:
    // 0x8007AE7C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007AE80: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8007AE84: lhu         $t3, 0xE68($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XE68);
    // 0x8007AE88: lhu         $t2, 0x7146($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X7146);
    // 0x8007AE8C: nop

    // 0x8007AE90: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8007AE94: beq         $t4, $zero, L_8007AFAC
    if (ctx->r12 == 0) {
        // 0x8007AE98: nop
    
            goto L_8007AFAC;
    }
    // 0x8007AE98: nop

    // 0x8007AE9C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007AEA0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8007AEA4: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8007AEA8: lwc1        $f6, 0x14($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8007AEAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007AEB0: nop

    // 0x8007AEB4: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8007AEB8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007AEBC: lbu         $t7, 0x7134($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7134);
    // 0x8007AEC0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007AEC4: bne         $t7, $at, L_8007AEF4
    if (ctx->r15 != ctx->r1) {
        // 0x8007AEC8: nop
    
            goto L_8007AEF4;
    }
    // 0x8007AEC8: nop

    // 0x8007AECC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007AED0: lh          $t8, 0x7132($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7132);
    // 0x8007AED4: nop

    // 0x8007AED8: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x8007AEDC: bne         $at, $zero, L_8007AEF4
    if (ctx->r1 != 0) {
        // 0x8007AEE0: nop
    
            goto L_8007AEF4;
    }
    // 0x8007AEE0: nop

    // 0x8007AEE4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8007AEE8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007AEEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007AEF0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_8007AEF4:
    // 0x8007AEF4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007AEF8: lbu         $t1, 0x7134($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7134);
    // 0x8007AEFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007AF00: bne         $t1, $at, L_8007AFAC
    if (ctx->r9 != ctx->r1) {
        // 0x8007AF04: nop
    
            goto L_8007AFAC;
    }
    // 0x8007AF04: nop

    // 0x8007AF08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007AF0C: lh          $t2, 0x7132($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7132);
    // 0x8007AF10: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007AF14: bne         $t2, $at, L_8007AF3C
    if (ctx->r10 != ctx->r1) {
        // 0x8007AF18: nop
    
            goto L_8007AF3C;
    }
    // 0x8007AF18: nop

    // 0x8007AF1C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007AF20: lh          $t3, 0x7144($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7144);
    // 0x8007AF24: addiu       $t5, $zero, -0x6
    ctx->r13 = ADD32(0, -0X6);
    // 0x8007AF28: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8007AF2C: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x8007AF30: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007AF34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007AF38: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_8007AF3C:
    // 0x8007AF3C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007AF40: lh          $t8, 0x7132($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7132);
    // 0x8007AF44: nop

    // 0x8007AF48: blez        $t8, L_8007AFAC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007AF4C: nop
    
            goto L_8007AFAC;
    }
    // 0x8007AF4C: nop

    // 0x8007AF50: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8007AF54: beq         $at, $zero, L_8007AFAC
    if (ctx->r1 == 0) {
        // 0x8007AF58: nop
    
            goto L_8007AFAC;
    }
    // 0x8007AF58: nop

    // 0x8007AF5C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007AF60: lw          $t9, 0x70F8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F8);
    // 0x8007AF64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007AF68: bne         $t9, $at, L_8007AFA0
    if (ctx->r25 != ctx->r1) {
        // 0x8007AF6C: nop
    
            goto L_8007AFA0;
    }
    // 0x8007AF6C: nop

    // 0x8007AF70: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007AF74: lh          $t0, 0x7132($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7132);
    // 0x8007AF78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007AF7C: sh          $t0, 0x7144($at)
    MEM_H(0X7144, ctx->r1) = ctx->r8;
    // 0x8007AF80: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007AF84: lh          $t1, 0x7132($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7132);
    // 0x8007AF88: nop

    // 0x8007AF8C: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8007AF90: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8007AF94: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007AF98: b           L_8007AFAC
    // 0x8007AF9C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
        goto L_8007AFAC;
    // 0x8007AF9C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_8007AFA0:
    // 0x8007AFA0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007AFA4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007AFA8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8007AFAC:
    // 0x8007AFAC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007AFB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007AFB4: lhu         $t6, 0xE74($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XE74);
    // 0x8007AFB8: lhu         $t4, 0x7146($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X7146);
    // 0x8007AFBC: nop

    // 0x8007AFC0: and         $t7, $t4, $t6
    ctx->r15 = ctx->r12 & ctx->r14;
    // 0x8007AFC4: beq         $t7, $zero, L_8007B0B4
    if (ctx->r15 == 0) {
        // 0x8007AFC8: nop
    
            goto L_8007B0B4;
    }
    // 0x8007AFC8: nop

    // 0x8007AFCC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8007AFD0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007AFD4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8007AFD8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8007AFDC: lwc1        $f8, 0x14($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8007AFE0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007AFE4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8007AFE8: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x8007AFEC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007AFF0: lbu         $t1, 0x7134($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7134);
    // 0x8007AFF4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007AFF8: bne         $t1, $at, L_8007B028
    if (ctx->r9 != ctx->r1) {
        // 0x8007AFFC: nop
    
            goto L_8007B028;
    }
    // 0x8007AFFC: nop

    // 0x8007B000: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007B004: lh          $t2, 0x7132($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7132);
    // 0x8007B008: nop

    // 0x8007B00C: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x8007B010: bne         $at, $zero, L_8007B028
    if (ctx->r1 != 0) {
        // 0x8007B014: nop
    
            goto L_8007B028;
    }
    // 0x8007B014: nop

    // 0x8007B018: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007B01C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8007B020: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007B024: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8007B028:
    // 0x8007B028: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B02C: lbu         $t4, 0x7134($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7134);
    // 0x8007B030: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007B034: bne         $t4, $at, L_8007B0B4
    if (ctx->r12 != ctx->r1) {
        // 0x8007B038: nop
    
            goto L_8007B0B4;
    }
    // 0x8007B038: nop

    // 0x8007B03C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B040: lh          $t6, 0x7132($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7132);
    // 0x8007B044: nop

    // 0x8007B048: bne         $t6, $zero, L_8007B068
    if (ctx->r14 != 0) {
        // 0x8007B04C: nop
    
            goto L_8007B068;
    }
    // 0x8007B04C: nop

    // 0x8007B050: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B054: lh          $t7, 0x7144($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7144);
    // 0x8007B058: nop

    // 0x8007B05C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007B060: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007B064: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_8007B068:
    // 0x8007B068: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007B06C: lh          $t9, 0x7132($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7132);
    // 0x8007B070: nop

    // 0x8007B074: blez        $t9, L_8007B0B4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007B078: nop
    
            goto L_8007B0B4;
    }
    // 0x8007B078: nop

    // 0x8007B07C: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x8007B080: beq         $at, $zero, L_8007B0B4
    if (ctx->r1 == 0) {
        // 0x8007B084: nop
    
            goto L_8007B0B4;
    }
    // 0x8007B084: nop

    // 0x8007B088: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007B08C: lh          $t0, 0x7132($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7132);
    // 0x8007B090: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B094: sh          $t0, 0x7144($at)
    MEM_H(0X7144, ctx->r1) = ctx->r8;
    // 0x8007B098: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007B09C: lh          $t1, 0x7132($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7132);
    // 0x8007B0A0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8007B0A4: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x8007B0A8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8007B0AC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007B0B0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_8007B0B4:
    // 0x8007B0B4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007B0B8: nop

    // 0x8007B0BC: bgez        $t4, L_8007B0CC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007B0C0: nop
    
            goto L_8007B0CC;
    }
    // 0x8007B0C0: nop

    // 0x8007B0C4: b           L_8007B11C
    // 0x8007B0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B11C;
    // 0x8007B0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B0CC:
    // 0x8007B0CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007B0D0: nop

    // 0x8007B0D4: beq         $t6, $zero, L_8007B0E8
    if (ctx->r14 == 0) {
        // 0x8007B0D8: nop
    
            goto L_8007B0E8;
    }
    // 0x8007B0D8: nop

    // 0x8007B0DC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B0E0: b           L_8007B11C
    // 0x8007B0E4: nop

        goto L_8007B11C;
    // 0x8007B0E4: nop

L_8007B0E8:
    // 0x8007B0E8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B0EC: lbu         $t7, 0x7134($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7134);
    // 0x8007B0F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8007B0F4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007B0F8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8007B0FC: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x8007B100: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007B104: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8007B108: lh          $v0, 0x23D0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X23D0);
    // 0x8007B10C: b           L_8007B11C
    // 0x8007B110: nop

        goto L_8007B11C;
    // 0x8007B110: nop

    // 0x8007B114: b           L_8007B11C
    // 0x8007B118: nop

        goto L_8007B11C;
    // 0x8007B118: nop

L_8007B11C:
    // 0x8007B11C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B120: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007B124: jr          $ra
    // 0x8007B128: nop

    return;
    // 0x8007B128: nop

;}
RECOMP_FUNC void func_8006837C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006837C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068380: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068384: nop

    // 0x80068388: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006838C: nop

    // 0x80068390: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80068394: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068398: jr          $ra
    // 0x8006839C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006839C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800683A0: jr          $ra
    // 0x800683A4: nop

    return;
    // 0x800683A4: nop

    // 0x800683A8: jr          $ra
    // 0x800683AC: nop

    return;
    // 0x800683AC: nop

;}
RECOMP_FUNC void __alSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6810: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6818: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x800D681C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D6820: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800D6824: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D6828: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D682C: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x800D6830: bne         $at, $zero, L_800D6840
    if (ctx->r1 != 0) {
        // 0x800D6834: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_800D6840;
    }
    // 0x800D6834: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800D6838: b           L_800D6858
    // 0x800D683C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D6858;
    // 0x800D683C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6840:
    // 0x800D6840: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800D6844: jal         0x800D63E8
    // 0x800D6848: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    static_5_800D63E8(rdram, ctx);
        goto after_0;
    // 0x800D6848: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800D684C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800D6850: sw          $a3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r7;
    // 0x800D6854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D6858:
    // 0x800D6858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D685C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D6860: jr          $ra
    // 0x800D6864: nop

    return;
    // 0x800D6864: nop

;}
RECOMP_FUNC void ContPak_SetPakInitializationAttempts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE348: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE34C: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE350: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE354: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x800AE358: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE35C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE360: lw          $t8, 0x1350($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1350);
    // 0x800AE364: addiu       $at, $zero, -0x6
    ctx->r1 = ADD32(0, -0X6);
    // 0x800AE368: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800AE36C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE370: sw          $t9, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r25;
    // 0x800AE374: bgez        $a0, L_800AE380
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800AE378: nop
    
            goto L_800AE380;
    }
    // 0x800AE378: nop

    // 0x800AE37C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800AE380:
    // 0x800AE380: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE384: sw          $a0, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r4;
    // 0x800AE388: jr          $ra
    // 0x800AE38C: nop

    return;
    // 0x800AE38C: nop

    // 0x800AE390: jr          $ra
    // 0x800AE394: nop

    return;
    // 0x800AE394: nop

;}
RECOMP_FUNC void func_80061D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061D20: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061D24: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80061D28: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80061D2C: nop

    // 0x80061D30: lh          $t7, 0x30($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X30);
    // 0x80061D34: nop

    // 0x80061D38: slti        $at, $t7, 0x1F4
    ctx->r1 = SIGNED(ctx->r15) < 0X1F4 ? 1 : 0;
    // 0x80061D3C: beq         $at, $zero, L_80061D80
    if (ctx->r1 == 0) {
        // 0x80061D40: nop
    
            goto L_80061D80;
    }
    // 0x80061D40: nop

    // 0x80061D44: lh          $t8, 0x32($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X32);
    // 0x80061D48: nop

    // 0x80061D4C: slti        $at, $t8, 0x1F4
    ctx->r1 = SIGNED(ctx->r24) < 0X1F4 ? 1 : 0;
    // 0x80061D50: beq         $at, $zero, L_80061D80
    if (ctx->r1 == 0) {
        // 0x80061D54: nop
    
            goto L_80061D80;
    }
    // 0x80061D54: nop

    // 0x80061D58: lh          $t9, 0x34($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X34);
    // 0x80061D5C: nop

    // 0x80061D60: slti        $at, $t9, 0x1F4
    ctx->r1 = SIGNED(ctx->r25) < 0X1F4 ? 1 : 0;
    // 0x80061D64: beq         $at, $zero, L_80061D80
    if (ctx->r1 == 0) {
        // 0x80061D68: nop
    
            goto L_80061D80;
    }
    // 0x80061D68: nop

    // 0x80061D6C: lh          $t0, 0x36($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X36);
    // 0x80061D70: nop

    // 0x80061D74: slti        $at, $t0, 0x1F4
    ctx->r1 = SIGNED(ctx->r8) < 0X1F4 ? 1 : 0;
    // 0x80061D78: bne         $at, $zero, L_80061DFC
    if (ctx->r1 != 0) {
        // 0x80061D7C: nop
    
            goto L_80061DFC;
    }
    // 0x80061D7C: nop

L_80061D80:
    // 0x80061D80: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x80061D84: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x80061D88: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80061D8C: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_80061D90:
    // 0x80061D90: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061D94: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80061D98: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80061D9C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80061DA0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80061DA4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80061DA8: addu        $t0, $t3, $t6
    ctx->r8 = ADD32(ctx->r11, ctx->r14);
    // 0x80061DAC: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80061DB0: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061DB4: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80061DB8: nop

    // 0x80061DBC: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80061DC0: beq         $at, $zero, L_80061DD8
    if (ctx->r1 == 0) {
        // 0x80061DC4: nop
    
            goto L_80061DD8;
    }
    // 0x80061DC4: nop

    // 0x80061DC8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061DCC: nop

    // 0x80061DD0: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80061DD4: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
L_80061DD8:
    // 0x80061DD8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80061DDC: nop

    // 0x80061DE0: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80061DE4: slti        $at, $t7, 0x1B
    ctx->r1 = SIGNED(ctx->r15) < 0X1B ? 1 : 0;
    // 0x80061DE8: bne         $at, $zero, L_80061D90
    if (ctx->r1 != 0) {
        // 0x80061DEC: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80061D90;
    }
    // 0x80061DEC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80061DF0: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80061DF4: b           L_80061E0C
    // 0x80061DF8: nop

        goto L_80061E0C;
    // 0x80061DF8: nop

L_80061DFC:
    // 0x80061DFC: b           L_80061E0C
    // 0x80061E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061E0C;
    // 0x80061E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061E04: b           L_80061E0C
    // 0x80061E08: nop

        goto L_80061E0C;
    // 0x80061E08: nop

L_80061E0C:
    // 0x80061E0C: jr          $ra
    // 0x80061E10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80061E10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800704C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800704C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800704CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800704D0: jal         0x80061348
    // 0x800704D4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800704D4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800704D8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800704DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800704E0: beq         $v0, $zero, L_80070530
    if (ctx->r2 == 0) {
        // 0x800704E4: nop
    
            goto L_80070530;
    }
    // 0x800704E4: nop

    // 0x800704E8: jal         0x80061348
    // 0x800704EC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800704EC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800704F0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800704F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800704F8: beq         $v0, $zero, L_80070530
    if (ctx->r2 == 0) {
        // 0x800704FC: nop
    
            goto L_80070530;
    }
    // 0x800704FC: nop

    // 0x80070500: jal         0x80061348
    // 0x80070504: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070504: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070508: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007050C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070510: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070514: beq         $v0, $zero, L_80070530
    if (ctx->r2 == 0) {
        // 0x80070518: nop
    
            goto L_80070530;
    }
    // 0x80070518: nop

    // 0x8007051C: jal         0x80061348
    // 0x80070520: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070520: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070524: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070528: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007052C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070530:
    // 0x80070530: b           L_80070540
    // 0x80070534: nop

        goto L_80070540;
    // 0x80070534: nop

    // 0x80070538: b           L_80070540
    // 0x8007053C: nop

        goto L_80070540;
    // 0x8007053C: nop

L_80070540:
    // 0x80070540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070544: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070548: jr          $ra
    // 0x8007054C: nop

    return;
    // 0x8007054C: nop

;}
RECOMP_FUNC void func_800732C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800732C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800732C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800732CC: nop

    // 0x800732D0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800732D4: nop

    // 0x800732D8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800732DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800732E0: jr          $ra
    // 0x800732E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800732E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800732E8: jr          $ra
    // 0x800732EC: nop

    return;
    // 0x800732EC: nop

    // 0x800732F0: jr          $ra
    // 0x800732F4: nop

    return;
    // 0x800732F4: nop

;}
RECOMP_FUNC void func_8006F2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F2BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F2C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F2C4: nop

    // 0x8006F2C8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F2CC: nop

    // 0x8006F2D0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F2D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F2D8: jr          $ra
    // 0x8006F2DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F2DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F2E0: jr          $ra
    // 0x8006F2E4: nop

    return;
    // 0x8006F2E4: nop

    // 0x8006F2E8: jr          $ra
    // 0x8006F2EC: nop

    return;
    // 0x8006F2EC: nop

;}
RECOMP_FUNC void func_800B4F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4F68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B4F6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B4F70: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B4F74: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B4F78: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B4F7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B4F80: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B4F84: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B4F88: jal         0x800B5558
    // 0x800B4F8C: nop

    func_800B5558(rdram, ctx);
        goto after_0;
    // 0x800B4F8C: nop

    after_0:
    // 0x800B4F90: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B4F94: nop

    // 0x800B4F98: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x800B4F9C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800B4FA0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B4FA4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B4FA8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800B4FAC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B4FB0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800B4FB4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4FB8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800B4FBC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800B4FC0: lw          $t4, 0xD40($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XD40);
    // 0x800B4FC4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B4FC8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B4FCC: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B4FD0: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B4FD4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800B4FD8: jal         0x800BD1FC
    // 0x800B4FDC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x800B4FDC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x800B4FE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_800B4FE4:
    // 0x800B4FE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800B4FE8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800B4FEC: jal         0x800BD218
    // 0x800B4FF0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800B4FF0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800B4FF4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B4FF8: nop

    // 0x800B4FFC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800B5000: bne         $t6, $zero, L_800B5010
    if (ctx->r14 != 0) {
        // 0x800B5004: nop
    
            goto L_800B5010;
    }
    // 0x800B5004: nop

    // 0x800B5008: b           L_800B5018
    // 0x800B500C: nop

        goto L_800B5018;
    // 0x800B500C: nop

L_800B5010:
    // 0x800B5010: b           L_800B4FE4
    // 0x800B5014: nop

        goto L_800B4FE4;
    // 0x800B5014: nop

L_800B5018:
    // 0x800B5018: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800B501C: nop

    // 0x800B5020: sh          $zero, 0x114($t8)
    MEM_H(0X114, ctx->r24) = 0;
    // 0x800B5024: lbu         $t7, 0x38($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X38);
    // 0x800B5028: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B502C: nop

    // 0x800B5030: sh          $t7, 0x100($t9)
    MEM_H(0X100, ctx->r25) = ctx->r15;
    // 0x800B5034: lbu         $t0, 0x39($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X39);
    // 0x800B5038: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B503C: nop

    // 0x800B5040: sh          $t0, 0x102($t1)
    MEM_H(0X102, ctx->r9) = ctx->r8;
    // 0x800B5044: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800B5048: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B504C: lhu         $t3, 0xA($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XA);
    // 0x800B5050: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800B5054: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800B5058: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800B505C: xor         $t7, $t4, $t8
    ctx->r15 = ctx->r12 ^ ctx->r24;
    // 0x800B5060: beq         $t7, $zero, L_800B5084
    if (ctx->r15 == 0) {
        // 0x800B5064: nop
    
            goto L_800B5084;
    }
    // 0x800B5064: nop

    // 0x800B5068: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B506C: nop

    // 0x800B5070: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800B5074: nop

    // 0x800B5078: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x800B507C: b           L_800B509C
    // 0x800B5080: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
        goto L_800B509C;
    // 0x800B5080: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
L_800B5084:
    // 0x800B5084: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800B5088: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800B508C: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800B5090: nop

    // 0x800B5094: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800B5098: sw          $t5, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r13;
L_800B509C:
    // 0x800B509C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B50A0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B50A4: lhu         $t4, 0xA($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0XA);
    // 0x800B50A8: lbu         $t0, 0x0($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X0);
    // 0x800B50AC: andi        $t8, $t4, 0x2
    ctx->r24 = ctx->r12 & 0X2;
    // 0x800B50B0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800B50B4: xor         $t9, $t8, $t1
    ctx->r25 = ctx->r24 ^ ctx->r9;
    // 0x800B50B8: beq         $t9, $zero, L_800B50DC
    if (ctx->r25 == 0) {
        // 0x800B50BC: nop
    
            goto L_800B50DC;
    }
    // 0x800B50BC: nop

    // 0x800B50C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B50C4: nop

    // 0x800B50C8: lw          $t5, 0xC0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC0);
    // 0x800B50CC: nop

    // 0x800B50D0: ori         $t2, $t5, 0x2
    ctx->r10 = ctx->r13 | 0X2;
    // 0x800B50D4: b           L_800B50F4
    // 0x800B50D8: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
        goto L_800B50F4;
    // 0x800B50D8: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
L_800B50DC:
    // 0x800B50DC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800B50E0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800B50E4: lw          $t4, 0xC0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XC0);
    // 0x800B50E8: nop

    // 0x800B50EC: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x800B50F0: sw          $t7, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r15;
L_800B50F4:
    // 0x800B50F4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800B50F8: nop

    // 0x800B50FC: lhu         $t8, 0xA($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0XA);
    // 0x800B5100: nop

    // 0x800B5104: andi        $t1, $t8, 0x400
    ctx->r9 = ctx->r24 & 0X400;
    // 0x800B5108: beq         $t1, $zero, L_800B512C
    if (ctx->r9 == 0) {
        // 0x800B510C: nop
    
            goto L_800B512C;
    }
    // 0x800B510C: nop

    // 0x800B5110: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B5114: nop

    // 0x800B5118: lw          $t5, 0xC0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC0);
    // 0x800B511C: nop

    // 0x800B5120: ori         $t2, $t5, 0x80
    ctx->r10 = ctx->r13 | 0X80;
    // 0x800B5124: b           L_800B5144
    // 0x800B5128: sw          $t2, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r10;
        goto L_800B5144;
    // 0x800B5128: sw          $t2, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r10;
L_800B512C:
    // 0x800B512C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B5130: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800B5134: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x800B5138: nop

    // 0x800B513C: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x800B5140: sw          $t7, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r15;
L_800B5144:
    // 0x800B5144: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800B5148: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B514C: sh          $t6, 0x116($t0)
    MEM_H(0X116, ctx->r8) = ctx->r14;
    // 0x800B5150: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B5154: lhu         $t8, 0xD54($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XD54);
    // 0x800B5158: nop

    // 0x800B515C: andi        $t1, $t8, 0x1
    ctx->r9 = ctx->r24 & 0X1;
    // 0x800B5160: beq         $t1, $zero, L_800B5184
    if (ctx->r9 == 0) {
        // 0x800B5164: nop
    
            goto L_800B5184;
    }
    // 0x800B5164: nop

    // 0x800B5168: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800B516C: nop

    // 0x800B5170: lw          $t2, 0xC0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0XC0);
    // 0x800B5174: nop

    // 0x800B5178: ori         $t9, $t2, 0x100
    ctx->r25 = ctx->r10 | 0X100;
    // 0x800B517C: b           L_800B519C
    // 0x800B5180: sw          $t9, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r25;
        goto L_800B519C;
    // 0x800B5180: sw          $t9, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r25;
L_800B5184:
    // 0x800B5184: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800B5188: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B518C: lw          $t7, 0xC0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC0);
    // 0x800B5190: nop

    // 0x800B5194: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x800B5198: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
L_800B519C:
    // 0x800B519C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B51A0: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B51A4: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x800B51A8: lhu         $t1, 0x10($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X10);
    // 0x800B51AC: nop

    // 0x800B51B0: beq         $t0, $t1, L_800B5374
    if (ctx->r8 == ctx->r9) {
        // 0x800B51B4: nop
    
            goto L_800B5374;
    }
    // 0x800B51B4: nop

    // 0x800B51B8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B51BC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800B51C0: lbu         $t5, 0x3C($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X3C);
    // 0x800B51C4: nop

    // 0x800B51C8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800B51CC: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x800B51D0: addiu       $t4, $t3, 0x12C
    ctx->r12 = ADD32(ctx->r11, 0X12C);
    // 0x800B51D4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800B51D8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B51DC: nop

    // 0x800B51E0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B51E4: nop

    // 0x800B51E8: beq         $t8, $zero, L_800B5204
    if (ctx->r24 == 0) {
        // 0x800B51EC: nop
    
            goto L_800B5204;
    }
    // 0x800B51EC: nop

    // 0x800B51F0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B51F4: nop

    // 0x800B51F8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B51FC: jal         0x800BC980
    // 0x800B5200: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800B5200: nop

    after_3:
L_800B5204:
    // 0x800B5204: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B5208: lhu         $t1, 0xD54($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XD54);
    // 0x800B520C: nop

    // 0x800B5210: andi        $t9, $t1, 0x2
    ctx->r25 = ctx->r9 & 0X2;
    // 0x800B5214: beq         $t9, $zero, L_800B52D8
    if (ctx->r25 == 0) {
        // 0x800B5218: nop
    
            goto L_800B52D8;
    }
    // 0x800B5218: nop

    // 0x800B521C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800B5220: lw          $t5, 0xD44($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD44);
    // 0x800B5224: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800B5228: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B522C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B5230: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B5234: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B5238: jal         0x800BD1FC
    // 0x800B523C: addu        $a2, $t5, $t2
    ctx->r6 = ADD32(ctx->r13, ctx->r10);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x800B523C: addu        $a2, $t5, $t2
    ctx->r6 = ADD32(ctx->r13, ctx->r10);
    after_4:
    // 0x800B5240: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B5244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B5248: jal         0x800BED70
    // 0x800B524C: nop

    Spi_GetHeader(rdram, ctx);
        goto after_5;
    // 0x800B524C: nop

    after_5:
    // 0x800B5250: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B5254: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B5258: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x800B525C: jal         0x800BC6EC
    // 0x800B5260: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x800B5260: nop

    after_6:
    // 0x800B5264: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5268: nop

    // 0x800B526C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800B5270: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5274: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B5278: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B527C: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x800B5280: jal         0x800BF0B4
    // 0x800B5284: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_7;
    // 0x800B5284: nop

    after_7:
    // 0x800B5288: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B528C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800B5290: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800B5294: nop

    // 0x800B5298: sw          $t6, 0x128($t8)
    MEM_W(0X128, ctx->r24) = ctx->r14;
    // 0x800B529C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800B52A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B52A4: lbu         $t1, 0x3C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3C);
    // 0x800B52A8: nop

    // 0x800B52AC: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x800B52B0: sb          $t9, 0x3C($t0)
    MEM_B(0X3C, ctx->r8) = ctx->r25;
    // 0x800B52B4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B52B8: nop

    // 0x800B52BC: lbu         $t2, 0x3C($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X3C);
    // 0x800B52C0: nop

    // 0x800B52C4: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x800B52C8: mfhi        $t7
    ctx->r15 = hi;
    // 0x800B52CC: sb          $t7, 0x3C($t5)
    MEM_B(0X3C, ctx->r13) = ctx->r15;
    // 0x800B52D0: b           L_800B5360
    // 0x800B52D4: nop

        goto L_800B5360;
    // 0x800B52D4: nop

L_800B52D8:
    // 0x800B52D8: lbu         $t3, 0x38($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X38);
    // 0x800B52DC: lbu         $t4, 0x39($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X39);
    // 0x800B52E0: nop

    // 0x800B52E4: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B52E8: mflo        $a0
    ctx->r4 = lo;
    // 0x800B52EC: jal         0x800BC6EC
    // 0x800B52F0: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x800B52F0: nop

    after_8:
    // 0x800B52F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B52F8: nop

    // 0x800B52FC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800B5300: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B5304: lw          $t8, 0xD44($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD44);
    // 0x800B5308: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B530C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B5310: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B5314: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B5318: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B531C: jal         0x800BD1FC
    // 0x800B5320: addu        $a2, $t8, $t1
    ctx->r6 = ADD32(ctx->r24, ctx->r9);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_9;
    // 0x800B5320: addu        $a2, $t8, $t1
    ctx->r6 = ADD32(ctx->r24, ctx->r9);
    after_9:
    // 0x800B5324: lbu         $t0, 0x38($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X38);
    // 0x800B5328: lbu         $t2, 0x39($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X39);
    // 0x800B532C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5330: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5334: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B5338: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800B533C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B5340: mflo        $a2
    ctx->r6 = lo;
    // 0x800B5344: jal         0x800BD218
    // 0x800B5348: nop

    SysMem_DmaCopy(rdram, ctx);
        goto after_10;
    // 0x800B5348: nop

    after_10:
    // 0x800B534C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5350: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B5354: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x800B5358: nop

    // 0x800B535C: sw          $t5, 0x128($t3)
    MEM_W(0X128, ctx->r11) = ctx->r13;
L_800B5360:
    // 0x800B5360: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B5364: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B5368: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x800B536C: nop

    // 0x800B5370: sh          $t6, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r14;
L_800B5374:
    // 0x800B5374: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B5378: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B537C: lhu         $a2, 0x4A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X4A);
    // 0x800B5380: jal         0x800B53A0
    // 0x800B5384: nop

    LoadPalette(rdram, ctx);
        goto after_11;
    // 0x800B5384: nop

    after_11:
    // 0x800B5388: b           L_800B5390
    // 0x800B538C: nop

        goto L_800B5390;
    // 0x800B538C: nop

L_800B5390:
    // 0x800B5390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5398: jr          $ra
    // 0x800B539C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B539C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void alSndpSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA0B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA0B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CA0BC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800CA0C0: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800CA0C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800CA0C8: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800CA0CC: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x800CA0D0: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800CA0D4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800CA0D8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800CA0DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CA0E0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CA0E4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800CA0E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CA0EC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800CA0F0: jal         0x800D3A2C
    // 0x800CA0F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800CA0F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CA0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA0FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA100: jr          $ra
    // 0x800CA104: nop

    return;
    // 0x800CA104: nop

;}
RECOMP_FUNC void func_8002DC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002DC18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002DC1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002DC20: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002DC24: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002DC28: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002DC2C: lh          $t6, -0x69F0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X69F0);
    // 0x8002DC30: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8002DC34: beq         $t6, $at, L_8002DC54
    if (ctx->r14 == ctx->r1) {
        // 0x8002DC38: nop
    
            goto L_8002DC54;
    }
    // 0x8002DC38: nop

    // 0x8002DC3C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8002DC40: lhu         $t7, -0x6504($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6504);
    // 0x8002DC44: nop

    // 0x8002DC48: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8002DC4C: beq         $t8, $zero, L_8002DC5C
    if (ctx->r24 == 0) {
        // 0x8002DC50: nop
    
            goto L_8002DC5C;
    }
    // 0x8002DC50: nop

L_8002DC54:
    // 0x8002DC54: b           L_8002E3FC
    // 0x8002DC58: nop

        goto L_8002E3FC;
    // 0x8002DC58: nop

L_8002DC5C:
    // 0x8002DC5C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8002DC60: lh          $t9, -0x69F0($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X69F0);
    // 0x8002DC64: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8002DC68: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002DC6C: lw          $t0, -0x73D0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73D0);
    // 0x8002DC70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DC74: swc1        $f6, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f6.u32l;
    // 0x8002DC78: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8002DC7C: lh          $t1, -0x69F0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X69F0);
    // 0x8002DC80: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002DC84: addiu       $t2, $t1, 0x72
    ctx->r10 = ADD32(ctx->r9, 0X72);
    // 0x8002DC88: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8002DC8C: lw          $t3, 0x16C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X16C0);
    // 0x8002DC90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002DC94: swc1        $f10, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f10.u32l;
    // 0x8002DC98: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8002DC9C: lh          $t4, -0x69F0($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X69F0);
    // 0x8002DCA0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8002DCA4: addiu       $t5, $t4, 0x63
    ctx->r13 = ADD32(ctx->r12, 0X63);
    // 0x8002DCA8: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8002DCAC: lw          $t6, -0x4BBC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BBC);
    // 0x8002DCB0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002DCB4: swc1        $f18, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f18.u32l;
    // 0x8002DCB8: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8002DCBC: lh          $t7, -0x69F0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X69F0);
    // 0x8002DCC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002DCC4: addiu       $t8, $t7, 0x6F
    ctx->r24 = ADD32(ctx->r15, 0X6F);
    // 0x8002DCC8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002DCCC: lw          $t9, 0x2648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2648);
    // 0x8002DCD0: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DCD4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002DCD8: swc1        $f20, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f20.u32l;
    // 0x8002DCDC: lw          $t0, 0x2644($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2644);
    // 0x8002DCE0: nop

    // 0x8002DCE4: swc1        $f20, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f20.u32l;
    // 0x8002DCE8: jal         0x800C1754
    // 0x8002DCEC: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8002DCEC: nop

    after_0:
    // 0x8002DCF0: jal         0x800A7160
    // 0x8002DCF4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800A7160(rdram, ctx);
        goto after_1;
    // 0x8002DCF4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8002DCF8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8002DCFC: addiu       $t1, $t1, 0x7340
    ctx->r9 = ADD32(ctx->r9, 0X7340);
    // 0x8002DD00: lwc1        $f12, 0xBF0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XBF0);
    // 0x8002DD04: jal         0x800C2780
    // 0x8002DD08: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8002DD08: nop

    after_2:
    // 0x8002DD0C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002DD10: addiu       $t2, $t2, 0x7340
    ctx->r10 = ADD32(ctx->r10, 0X7340);
    // 0x8002DD14: lwc1        $f12, 0xBEC($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XBEC);
    // 0x8002DD18: jal         0x800C25B8
    // 0x8002DD1C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8002DD1C: nop

    after_3:
    // 0x8002DD20: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002DD24: addiu       $t3, $t3, 0x7340
    ctx->r11 = ADD32(ctx->r11, 0X7340);
    // 0x8002DD28: lwc1        $f12, 0xBE8($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XBE8);
    // 0x8002DD2C: jal         0x800C23E8
    // 0x8002DD30: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8002DD30: nop

    after_4:
    // 0x8002DD34: jal         0x800A72BC
    // 0x8002DD38: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800A72BC(rdram, ctx);
        goto after_5;
    // 0x8002DD38: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_5:
    // 0x8002DD3C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002DD40: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8002DD44: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002DD48: lhu         $t6, -0x6A10($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6A10);
    // 0x8002DD4C: lh          $t5, 0x40($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X40);
    // 0x8002DD50: nop

    // 0x8002DD54: beq         $t5, $t6, L_8002DD64
    if (ctx->r13 == ctx->r14) {
        // 0x8002DD58: nop
    
            goto L_8002DD64;
    }
    // 0x8002DD58: nop

    // 0x8002DD5C: jal         0x8002D598
    // 0x8002DD60: nop

    func_8002D598(rdram, ctx);
        goto after_6;
    // 0x8002DD60: nop

    after_6:
L_8002DD64:
    // 0x8002DD64: jal         0x800C1850
    // 0x8002DD68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_7;
    // 0x8002DD68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8002DD6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002DD70: lw          $a0, 0x16C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C0);
    // 0x8002DD74: jal         0x8009A14C
    // 0x8002DD78: nop

    func_8009A14C(rdram, ctx);
        goto after_8;
    // 0x8002DD78: nop

    after_8:
    // 0x8002DD7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002DD80: lw          $a0, 0x16C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C0);
    // 0x8002DD84: jal         0x800997D8
    // 0x8002DD88: nop

    func_800997D8(rdram, ctx);
        goto after_9;
    // 0x8002DD88: nop

    after_9:
    // 0x8002DD8C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8002DD90: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8002DD94: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8002DD98: nop

    // 0x8002DD9C: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x8002DDA0: beq         $t9, $zero, L_8002DE44
    if (ctx->r25 == 0) {
        // 0x8002DDA4: nop
    
            goto L_8002DE44;
    }
    // 0x8002DDA4: nop

    // 0x8002DDA8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002DDAC: lw          $t0, 0x640($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X640);
    // 0x8002DDB0: nop

    // 0x8002DDB4: bne         $t0, $zero, L_8002DDC4
    if (ctx->r8 != 0) {
        // 0x8002DDB8: nop
    
            goto L_8002DDC4;
    }
    // 0x8002DDB8: nop

    // 0x8002DDBC: b           L_8002DDDC
    // 0x8002DDC0: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
        goto L_8002DDDC;
    // 0x8002DDC0: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
L_8002DDC4:
    // 0x8002DDC4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002DDC8: lw          $t1, 0x640($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X640);
    // 0x8002DDCC: nop

    // 0x8002DDD0: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8002DDD4: nop

    // 0x8002DDD8: sh          $t2, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r10;
L_8002DDDC:
    // 0x8002DDDC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8002DDE0: lw          $t4, -0x4BB8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BB8);
    // 0x8002DDE4: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x8002DDE8: nop

    // 0x8002DDEC: beq         $t3, $t4, L_8002DE1C
    if (ctx->r11 == ctx->r12) {
        // 0x8002DDF0: nop
    
            goto L_8002DE1C;
    }
    // 0x8002DDF0: nop

    // 0x8002DDF4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8002DDF8: lw          $t5, -0x4BBC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4BBC);
    // 0x8002DDFC: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x8002DE00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002DE04: lw          $a1, 0x128($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X128);
    // 0x8002DE08: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002DE0C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8002DE10: sw          $t6, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r14;
    // 0x8002DE14: jal         0x8002D798
    // 0x8002DE18: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    func_8002D798(rdram, ctx);
        goto after_10;
    // 0x8002DE18: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_10:
L_8002DE1C:
    // 0x8002DE1C: jal         0x800C1850
    // 0x8002DE20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_11;
    // 0x8002DE20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8002DE24: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8002DE28: lw          $a0, -0x4BBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BBC);
    // 0x8002DE2C: jal         0x8009A14C
    // 0x8002DE30: nop

    func_8009A14C(rdram, ctx);
        goto after_12;
    // 0x8002DE30: nop

    after_12:
    // 0x8002DE34: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8002DE38: lw          $a0, -0x4BBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4BBC);
    // 0x8002DE3C: jal         0x800997D8
    // 0x8002DE40: nop

    func_800997D8(rdram, ctx);
        goto after_13;
    // 0x8002DE40: nop

    after_13:
L_8002DE44:
    // 0x8002DE44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DE48: lwc1        $f6, 0x25B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DE4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DE50: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002DE54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DE58: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002DE5C: swc1        $f10, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f10.u32l;
    // 0x8002DE60: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002DE64: lh          $s0, 0x25A4($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X25A4);
    // 0x8002DE68: nop

    // 0x8002DE6C: beq         $s0, $zero, L_8002DEA0
    if (ctx->r16 == 0) {
        // 0x8002DE70: nop
    
            goto L_8002DEA0;
    }
    // 0x8002DE70: nop

    // 0x8002DE74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DE78: beq         $s0, $at, L_8002DF4C
    if (ctx->r16 == ctx->r1) {
        // 0x8002DE7C: nop
    
            goto L_8002DF4C;
    }
    // 0x8002DE7C: nop

    // 0x8002DE80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002DE84: beq         $s0, $at, L_8002DFF8
    if (ctx->r16 == ctx->r1) {
        // 0x8002DE88: nop
    
            goto L_8002DFF8;
    }
    // 0x8002DE88: nop

    // 0x8002DE8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002DE90: beq         $s0, $at, L_8002DFF8
    if (ctx->r16 == ctx->r1) {
        // 0x8002DE94: nop
    
            goto L_8002DFF8;
    }
    // 0x8002DE94: nop

    // 0x8002DE98: b           L_8002E0A4
    // 0x8002DE9C: nop

        goto L_8002E0A4;
    // 0x8002DE9C: nop

L_8002DEA0:
    // 0x8002DEA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DEA4: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DEA8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DEAC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002DEB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002DEB4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002DEB8: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8002DEBC: nop

    // 0x8002DEC0: bc1f        L_8002DF44
    if (!c1cs) {
        // 0x8002DEC4: nop
    
            goto L_8002DF44;
    }
    // 0x8002DEC4: nop

L_8002DEC8:
    // 0x8002DEC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002DECC: lw          $t7, 0x2644($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2644);
    // 0x8002DED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DED4: lw          $a0, 0x138($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X138);
    // 0x8002DED8: jal         0x80030438
    // 0x8002DEDC: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80030438(rdram, ctx);
        goto after_14;
    // 0x8002DEDC: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_14:
    // 0x8002DEE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DEE4: lwc1        $f6, 0x25B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DEE8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DEEC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002DEF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002DEF4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002DEF8: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8002DEFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF00: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002DF04: swc1        $f18, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f18.u32l;
    // 0x8002DF08: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002DF0C: lh          $t8, 0x25C4($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X25C4);
    // 0x8002DF10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF14: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002DF18: sh          $t9, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r25;
    // 0x8002DF1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF20: lwc1        $f4, 0x25B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DF24: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DF28: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002DF2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002DF30: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002DF34: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8002DF38: nop

    // 0x8002DF3C: bc1t        L_8002DEC8
    if (c1cs) {
        // 0x8002DF40: nop
    
            goto L_8002DEC8;
    }
    // 0x8002DF40: nop

L_8002DF44:
    // 0x8002DF44: b           L_8002E0A4
    // 0x8002DF48: nop

        goto L_8002E0A4;
    // 0x8002DF48: nop

L_8002DF4C:
    // 0x8002DF4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF50: lwc1        $f10, 0x25B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DF54: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DF58: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002DF5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002DF60: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002DF64: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8002DF68: nop

    // 0x8002DF6C: bc1f        L_8002DFF0
    if (!c1cs) {
        // 0x8002DF70: nop
    
            goto L_8002DFF0;
    }
    // 0x8002DF70: nop

L_8002DF74:
    // 0x8002DF74: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002DF78: lw          $t0, 0x2644($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2644);
    // 0x8002DF7C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8002DF80: lw          $a0, 0x138($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X138);
    // 0x8002DF84: jal         0x80030438
    // 0x8002DF88: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_80030438(rdram, ctx);
        goto after_15;
    // 0x8002DF88: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_15:
    // 0x8002DF8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DF90: lwc1        $f4, 0x25B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DF94: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DF98: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002DF9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002DFA0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002DFA4: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002DFA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DFAC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002DFB0: swc1        $f16, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f16.u32l;
    // 0x8002DFB4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002DFB8: lh          $t1, 0x25C4($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X25C4);
    // 0x8002DFBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DFC0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8002DFC4: sh          $t2, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r10;
    // 0x8002DFC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DFCC: lwc1        $f18, 0x25B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002DFD0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002DFD4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002DFD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002DFDC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002DFE0: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8002DFE4: nop

    // 0x8002DFE8: bc1t        L_8002DF74
    if (c1cs) {
        // 0x8002DFEC: nop
    
            goto L_8002DF74;
    }
    // 0x8002DFEC: nop

L_8002DFF0:
    // 0x8002DFF0: b           L_8002E0A4
    // 0x8002DFF4: nop

        goto L_8002E0A4;
    // 0x8002DFF4: nop

L_8002DFF8:
    // 0x8002DFF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002DFFC: lwc1        $f8, 0x25B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E000: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E004: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E008: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E00C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E010: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x8002E014: nop

    // 0x8002E018: bc1f        L_8002E09C
    if (!c1cs) {
        // 0x8002E01C: nop
    
            goto L_8002E09C;
    }
    // 0x8002E01C: nop

L_8002E020:
    // 0x8002E020: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002E024: lw          $t3, 0x2644($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2644);
    // 0x8002E028: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8002E02C: lw          $a0, 0x138($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X138);
    // 0x8002E030: jal         0x80030438
    // 0x8002E034: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    func_80030438(rdram, ctx);
        goto after_16;
    // 0x8002E034: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    after_16:
    // 0x8002E038: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E03C: lwc1        $f18, 0x25B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E040: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E044: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E048: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E04C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E050: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002E054: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E058: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002E05C: swc1        $f10, 0x25B4($at)
    MEM_W(0X25B4, ctx->r1) = ctx->f10.u32l;
    // 0x8002E060: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002E064: lh          $t4, 0x25C4($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X25C4);
    // 0x8002E068: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E06C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002E070: sh          $t5, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = ctx->r13;
    // 0x8002E074: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E078: lwc1        $f16, 0x25B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B4);
    // 0x8002E07C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E080: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E084: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E088: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E08C: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8002E090: nop

    // 0x8002E094: bc1t        L_8002E020
    if (c1cs) {
        // 0x8002E098: nop
    
            goto L_8002E020;
    }
    // 0x8002E098: nop

L_8002E09C:
    // 0x8002E09C: b           L_8002E0A4
    // 0x8002E0A0: nop

        goto L_8002E0A4;
    // 0x8002E0A0: nop

L_8002E0A4:
    // 0x8002E0A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002E0A8: lh          $t6, 0x25C4($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X25C4);
    // 0x8002E0AC: nop

    // 0x8002E0B0: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x8002E0B4: bne         $at, $zero, L_8002E0F0
    if (ctx->r1 != 0) {
        // 0x8002E0B8: nop
    
            goto L_8002E0F0;
    }
    // 0x8002E0B8: nop

    // 0x8002E0BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E0C0: sh          $zero, 0x25C4($at)
    MEM_H(0X25C4, ctx->r1) = 0;
    // 0x8002E0C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E0C8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8002E0CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E0D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002E0D4: lh          $a1, 0x25A4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X25A4);
    // 0x8002E0D8: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E0DC: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x8002E0E0: jal         0x8002D3B0
    // 0x8002E0E4: nop

    func_8002D3B0(rdram, ctx);
        goto after_17;
    // 0x8002E0E4: nop

    after_17:
    // 0x8002E0E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E0EC: sh          $v0, 0x25A4($at)
    MEM_H(0X25A4, ctx->r1) = ctx->r2;
L_8002E0F0:
    // 0x8002E0F0: jal         0x800C1850
    // 0x8002E0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_18;
    // 0x8002E0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x8002E0F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E0FC: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E100: jal         0x8009A14C
    // 0x8002E104: nop

    func_8009A14C(rdram, ctx);
        goto after_19;
    // 0x8002E104: nop

    after_19:
    // 0x8002E108: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E10C: lw          $a0, 0x2644($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2644);
    // 0x8002E110: jal         0x800997D8
    // 0x8002E114: nop

    func_800997D8(rdram, ctx);
        goto after_20;
    // 0x8002E114: nop

    after_20:
    // 0x8002E118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E11C: lwc1        $f6, 0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E120: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E124: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002E128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E12C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002E130: swc1        $f10, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f10.u32l;
    // 0x8002E134: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002E138: lh          $s0, 0x25AC($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X25AC);
    // 0x8002E13C: nop

    // 0x8002E140: beq         $s0, $zero, L_8002E174
    if (ctx->r16 == 0) {
        // 0x8002E144: nop
    
            goto L_8002E174;
    }
    // 0x8002E144: nop

    // 0x8002E148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002E14C: beq         $s0, $at, L_8002E220
    if (ctx->r16 == ctx->r1) {
        // 0x8002E150: nop
    
            goto L_8002E220;
    }
    // 0x8002E150: nop

    // 0x8002E154: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002E158: beq         $s0, $at, L_8002E2CC
    if (ctx->r16 == ctx->r1) {
        // 0x8002E15C: nop
    
            goto L_8002E2CC;
    }
    // 0x8002E15C: nop

    // 0x8002E160: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E164: beq         $s0, $at, L_8002E2CC
    if (ctx->r16 == ctx->r1) {
        // 0x8002E168: nop
    
            goto L_8002E2CC;
    }
    // 0x8002E168: nop

    // 0x8002E16C: b           L_8002E378
    // 0x8002E170: nop

        goto L_8002E378;
    // 0x8002E170: nop

L_8002E174:
    // 0x8002E174: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E178: lwc1        $f16, 0x25BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E17C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E180: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E184: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E188: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E18C: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8002E190: nop

    // 0x8002E194: bc1f        L_8002E218
    if (!c1cs) {
        // 0x8002E198: nop
    
            goto L_8002E218;
    }
    // 0x8002E198: nop

L_8002E19C:
    // 0x8002E19C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002E1A0: lw          $t8, 0x2648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2648);
    // 0x8002E1A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E1A8: lw          $a0, 0x138($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X138);
    // 0x8002E1AC: jal         0x80030438
    // 0x8002E1B0: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80030438(rdram, ctx);
        goto after_21;
    // 0x8002E1B0: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_21:
    // 0x8002E1B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E1B8: lwc1        $f6, 0x25BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E1BC: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E1C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002E1C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E1C8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002E1CC: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8002E1D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E1D4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002E1D8: swc1        $f18, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f18.u32l;
    // 0x8002E1DC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002E1E0: lh          $t9, 0x25CC($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X25CC);
    // 0x8002E1E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E1E8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8002E1EC: sh          $t0, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r8;
    // 0x8002E1F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E1F4: lwc1        $f4, 0x25BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E1F8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E1FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E200: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E204: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002E208: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x8002E20C: nop

    // 0x8002E210: bc1t        L_8002E19C
    if (c1cs) {
        // 0x8002E214: nop
    
            goto L_8002E19C;
    }
    // 0x8002E214: nop

L_8002E218:
    // 0x8002E218: b           L_8002E378
    // 0x8002E21C: nop

        goto L_8002E378;
    // 0x8002E21C: nop

L_8002E220:
    // 0x8002E220: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E224: lwc1        $f10, 0x25BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E228: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E22C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002E230: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002E234: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002E238: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8002E23C: nop

    // 0x8002E240: bc1f        L_8002E2C4
    if (!c1cs) {
        // 0x8002E244: nop
    
            goto L_8002E2C4;
    }
    // 0x8002E244: nop

L_8002E248:
    // 0x8002E248: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002E24C: lw          $t1, 0x2648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2648);
    // 0x8002E250: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8002E254: lw          $a0, 0x138($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X138);
    // 0x8002E258: jal         0x80030438
    // 0x8002E25C: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_80030438(rdram, ctx);
        goto after_22;
    // 0x8002E25C: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_22:
    // 0x8002E260: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E264: lwc1        $f4, 0x25BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E268: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E26C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E270: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E274: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002E278: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8002E27C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E280: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002E284: swc1        $f16, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f16.u32l;
    // 0x8002E288: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002E28C: lh          $t2, 0x25CC($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X25CC);
    // 0x8002E290: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E294: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8002E298: sh          $t3, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r11;
    // 0x8002E29C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E2A0: lwc1        $f18, 0x25BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E2A4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002E2A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E2AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E2B0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E2B4: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8002E2B8: nop

    // 0x8002E2BC: bc1t        L_8002E248
    if (c1cs) {
        // 0x8002E2C0: nop
    
            goto L_8002E248;
    }
    // 0x8002E2C0: nop

L_8002E2C4:
    // 0x8002E2C4: b           L_8002E378
    // 0x8002E2C8: nop

        goto L_8002E378;
    // 0x8002E2C8: nop

L_8002E2CC:
    // 0x8002E2CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E2D0: lwc1        $f8, 0x25BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E2D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E2D8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E2DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E2E0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002E2E4: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x8002E2E8: nop

    // 0x8002E2EC: bc1f        L_8002E370
    if (!c1cs) {
        // 0x8002E2F0: nop
    
            goto L_8002E370;
    }
    // 0x8002E2F0: nop

L_8002E2F4:
    // 0x8002E2F4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002E2F8: lw          $t4, 0x2648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2648);
    // 0x8002E2FC: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8002E300: lw          $a0, 0x138($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X138);
    // 0x8002E304: jal         0x80030438
    // 0x8002E308: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    func_80030438(rdram, ctx);
        goto after_23;
    // 0x8002E308: addiu       $a2, $zero, 0x5F
    ctx->r6 = ADD32(0, 0X5F);
    after_23:
    // 0x8002E30C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E310: lwc1        $f18, 0x25BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E314: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E318: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002E31C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E320: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E324: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002E328: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E32C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002E330: swc1        $f10, 0x25BC($at)
    MEM_W(0X25BC, ctx->r1) = ctx->f10.u32l;
    // 0x8002E334: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002E338: lh          $t5, 0x25CC($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X25CC);
    // 0x8002E33C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E340: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002E344: sh          $t6, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = ctx->r14;
    // 0x8002E348: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E34C: lwc1        $f16, 0x25BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25BC);
    // 0x8002E350: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E354: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E358: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E35C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002E360: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8002E364: nop

    // 0x8002E368: bc1t        L_8002E2F4
    if (c1cs) {
        // 0x8002E36C: nop
    
            goto L_8002E2F4;
    }
    // 0x8002E36C: nop

L_8002E370:
    // 0x8002E370: b           L_8002E378
    // 0x8002E374: nop

        goto L_8002E378;
    // 0x8002E374: nop

L_8002E378:
    // 0x8002E378: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E37C: lh          $t7, 0x25CC($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X25CC);
    // 0x8002E380: nop

    // 0x8002E384: slti        $at, $t7, 0x1F
    ctx->r1 = SIGNED(ctx->r15) < 0X1F ? 1 : 0;
    // 0x8002E388: bne         $at, $zero, L_8002E3C4
    if (ctx->r1 != 0) {
        // 0x8002E38C: nop
    
            goto L_8002E3C4;
    }
    // 0x8002E38C: nop

    // 0x8002E390: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E394: sh          $zero, 0x25CC($at)
    MEM_H(0X25CC, ctx->r1) = 0;
    // 0x8002E398: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002E39C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8002E3A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E3A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002E3A8: lh          $a1, 0x25AC($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X25AC);
    // 0x8002E3AC: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002E3B0: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    // 0x8002E3B4: jal         0x8002D3B0
    // 0x8002E3B8: nop

    func_8002D3B0(rdram, ctx);
        goto after_24;
    // 0x8002E3B8: nop

    after_24:
    // 0x8002E3BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002E3C0: sh          $v0, 0x25AC($at)
    MEM_H(0X25AC, ctx->r1) = ctx->r2;
L_8002E3C4:
    // 0x8002E3C4: jal         0x800C1850
    // 0x8002E3C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_25;
    // 0x8002E3C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x8002E3CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E3D0: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002E3D4: jal         0x8009A14C
    // 0x8002E3D8: nop

    func_8009A14C(rdram, ctx);
        goto after_26;
    // 0x8002E3D8: nop

    after_26:
    // 0x8002E3DC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002E3E0: lw          $a0, 0x2648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2648);
    // 0x8002E3E4: jal         0x800997D8
    // 0x8002E3E8: nop

    func_800997D8(rdram, ctx);
        goto after_27;
    // 0x8002E3E8: nop

    after_27:
    // 0x8002E3EC: jal         0x800C1A28
    // 0x8002E3F0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_28;
    // 0x8002E3F0: nop

    after_28:
    // 0x8002E3F4: b           L_8002E3FC
    // 0x8002E3F8: nop

        goto L_8002E3FC;
    // 0x8002E3F8: nop

L_8002E3FC:
    // 0x8002E3FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002E400: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002E404: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002E408: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002E40C: jr          $ra
    // 0x8002E410: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002E410: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
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
RECOMP_FUNC void func_800B9568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9568: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B956C: b           L_800B9574
    // 0x800B9570: nop

        goto L_800B9574;
    // 0x800B9570: nop

L_800B9574:
    // 0x800B9574: jr          $ra
    // 0x800B9578: nop

    return;
    // 0x800B9578: nop

    // 0x800B957C: nop

;}
RECOMP_FUNC void func_80070FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070FF8: jal         0x80061348
    // 0x80070FFC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070FFC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_0:
    // 0x80071000: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071004: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071008: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007100C: beq         $v0, $zero, L_80071060
    if (ctx->r2 == 0) {
        // 0x80071010: nop
    
            goto L_80071060;
    }
    // 0x80071010: nop

    // 0x80071014: jal         0x80061348
    // 0x80071018: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071018: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x8007101C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071020: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071024: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071028: beq         $v0, $zero, L_80071060
    if (ctx->r2 == 0) {
        // 0x8007102C: nop
    
            goto L_80071060;
    }
    // 0x8007102C: nop

    // 0x80071030: jal         0x80061348
    // 0x80071034: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071034: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_2:
    // 0x80071038: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007103C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071040: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071044: beq         $v0, $zero, L_80071060
    if (ctx->r2 == 0) {
        // 0x80071048: nop
    
            goto L_80071060;
    }
    // 0x80071048: nop

    // 0x8007104C: jal         0x80061348
    // 0x80071050: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071050: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80071054: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071058: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007105C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071060:
    // 0x80071060: b           L_80071070
    // 0x80071064: nop

        goto L_80071070;
    // 0x80071064: nop

    // 0x80071068: b           L_80071070
    // 0x8007106C: nop

        goto L_80071070;
    // 0x8007106C: nop

L_80071070:
    // 0x80071070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071078: jr          $ra
    // 0x8007107C: nop

    return;
    // 0x8007107C: nop

;}
RECOMP_FUNC void func_80062998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006299C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800629A0: jal         0x8005F064
    // 0x800629A4: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800629A4: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_0:
    // 0x800629A8: b           L_800629B8
    // 0x800629AC: nop

        goto L_800629B8;
    // 0x800629AC: nop

    // 0x800629B0: b           L_800629B8
    // 0x800629B4: nop

        goto L_800629B8;
    // 0x800629B4: nop

L_800629B8:
    // 0x800629B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800629BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800629C0: jr          $ra
    // 0x800629C4: nop

    return;
    // 0x800629C4: nop

;}
RECOMP_FUNC void func_80062E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062E8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062E94: jal         0x8005F064
    // 0x80062E98: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062E98: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80062E9C: b           L_80062EAC
    // 0x80062EA0: nop

        goto L_80062EAC;
    // 0x80062EA0: nop

    // 0x80062EA4: b           L_80062EAC
    // 0x80062EA8: nop

        goto L_80062EAC;
    // 0x80062EA8: nop

L_80062EAC:
    // 0x80062EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062EB4: jr          $ra
    // 0x80062EB8: nop

    return;
    // 0x80062EB8: nop

;}
RECOMP_FUNC void func_8001ACDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ACDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ACE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ACE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001ACE8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001ACEC: nop

    // 0x8001ACF0: lw          $a0, 0x20C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20C);
    // 0x8001ACF4: jal         0x80096374
    // 0x8001ACF8: nop

    func_80096374(rdram, ctx);
        goto after_0;
    // 0x8001ACF8: nop

    after_0:
    // 0x8001ACFC: jal         0x800967D8
    // 0x8001AD00: nop

    func_800967D8(rdram, ctx);
        goto after_1;
    // 0x8001AD00: nop

    after_1:
    // 0x8001AD04: b           L_8001AD14
    // 0x8001AD08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AD14;
    // 0x8001AD08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AD0C: b           L_8001AD14
    // 0x8001AD10: nop

        goto L_8001AD14;
    // 0x8001AD10: nop

L_8001AD14:
    // 0x8001AD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AD18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001AD1C: jr          $ra
    // 0x8001AD20: nop

    return;
    // 0x8001AD20: nop

;}
RECOMP_FUNC void func_8004FE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FE20: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004FE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FE28: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8004FE2C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8004FE30: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8004FE34: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8004FE38: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x8004FE3C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8004FE40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004FE44: nop

    // 0x8004FE48: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8004FE4C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004FE50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004FE54: nop

    // 0x8004FE58: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8004FE5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004FE60: nop

    // 0x8004FE64: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8004FE68: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x8004FE6C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8004FE70: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8004FE74: addiu       $at, $zero, 0xB2
    ctx->r1 = ADD32(0, 0XB2);
    // 0x8004FE78: bne         $t9, $at, L_80050064
    if (ctx->r25 != ctx->r1) {
        // 0x8004FE7C: nop
    
            goto L_80050064;
    }
    // 0x8004FE7C: nop

    // 0x8004FE80: jal         0x80031B6C
    // 0x8004FE84: nop

    func_80031B6C(rdram, ctx);
        goto after_0;
    // 0x8004FE84: nop

    after_0:
    // 0x8004FE88: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8004FE8C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8004FE90: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8004FE94: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004FE98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004FE9C: nop

    // 0x8004FEA0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8004FEA4: jal         0x80016620
    // 0x8004FEA8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_1;
    // 0x8004FEA8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8004FEAC: jal         0x80021F20
    // 0x8004FEB0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_2;
    // 0x8004FEB0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x8004FEB4: jal         0x80016138
    // 0x8004FEB8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_3;
    // 0x8004FEB8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_3:
    // 0x8004FEBC: beq         $v0, $zero, L_8004FEE0
    if (ctx->r2 == 0) {
        // 0x8004FEC0: nop
    
            goto L_8004FEE0;
    }
    // 0x8004FEC0: nop

L_8004FEC4:
    // 0x8004FEC4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8004FEC8: jal         0x800499B0
    // 0x8004FECC: nop

    func_800499B0(rdram, ctx);
        goto after_4;
    // 0x8004FECC: nop

    after_4:
    // 0x8004FED0: jal         0x80016138
    // 0x8004FED4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_5;
    // 0x8004FED4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_5:
    // 0x8004FED8: bne         $v0, $zero, L_8004FEC4
    if (ctx->r2 != 0) {
        // 0x8004FEDC: nop
    
            goto L_8004FEC4;
    }
    // 0x8004FEDC: nop

L_8004FEE0:
    // 0x8004FEE0: jal         0x80021ED0
    // 0x8004FEE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_6;
    // 0x8004FEE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_6:
    // 0x8004FEE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004FEEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004FEF0: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8004FEF4: lwc1        $f5, -0x10E0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X10E0);
    // 0x8004FEF8: lwc1        $f4, -0x10DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X10DC);
    // 0x8004FEFC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8004FF00: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8004FF04: nop

    // 0x8004FF08: bc1f        L_8004FF4C
    if (!c1cs) {
        // 0x8004FF0C: nop
    
            goto L_8004FF4C;
    }
    // 0x8004FF0C: nop

L_8004FF10:
    // 0x8004FF10: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8004FF14: jal         0x800499B0
    // 0x8004FF18: nop

    func_800499B0(rdram, ctx);
        goto after_7;
    // 0x8004FF18: nop

    after_7:
    // 0x8004FF1C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8004FF20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004FF24: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8004FF28: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8004FF2C: lwc1        $f11, -0x10D8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X10D8);
    // 0x8004FF30: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8004FF34: lwc1        $f10, -0x10D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X10D4);
    // 0x8004FF38: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8004FF3C: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004FF40: nop

    // 0x8004FF44: bc1t        L_8004FF10
    if (c1cs) {
        // 0x8004FF48: nop
    
            goto L_8004FF10;
    }
    // 0x8004FF48: nop

L_8004FF4C:
    // 0x8004FF4C: jal         0x80021ED0
    // 0x8004FF50: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_8;
    // 0x8004FF50: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_8:
    // 0x8004FF54: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004FF58: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8004FF5C: nop

    // 0x8004FF60: lh          $t3, 0x40($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X40);
    // 0x8004FF64: nop

    // 0x8004FF68: slti        $at, $t3, 0x3E7
    ctx->r1 = SIGNED(ctx->r11) < 0X3E7 ? 1 : 0;
    // 0x8004FF6C: beq         $at, $zero, L_8004FF90
    if (ctx->r1 == 0) {
        // 0x8004FF70: nop
    
            goto L_8004FF90;
    }
    // 0x8004FF70: nop

    // 0x8004FF74: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004FF78: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x8004FF7C: nop

    // 0x8004FF80: lh          $t5, 0x40($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X40);
    // 0x8004FF84: nop

    // 0x8004FF88: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8004FF8C: sh          $t6, 0x40($t4)
    MEM_H(0X40, ctx->r12) = ctx->r14;
L_8004FF90:
    // 0x8004FF90: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004FF94: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004FF98: nop

    // 0x8004FF9C: lh          $t8, 0x38($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X38);
    // 0x8004FFA0: nop

    // 0x8004FFA4: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x8004FFA8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004FFAC: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8004FFB0: nop

    // 0x8004FFB4: lh          $t0, 0x3A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X3A);
    // 0x8004FFB8: nop

    // 0x8004FFBC: sh          $t0, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r8;
    // 0x8004FFC0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004FFC4: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x8004FFC8: nop

    // 0x8004FFCC: sh          $zero, 0x3C($t1)
    MEM_H(0X3C, ctx->r9) = 0;
    // 0x8004FFD0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004FFD4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8004FFD8: nop

    // 0x8004FFDC: sh          $zero, 0x3E($t2)
    MEM_H(0X3E, ctx->r10) = 0;
    // 0x8004FFE0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004FFE4: lw          $t3, 0x718C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X718C);
    // 0x8004FFE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8004FFEC: addiu       $t5, $t3, -0x32
    ctx->r13 = ADD32(ctx->r11, -0X32);
    // 0x8004FFF0: sw          $t5, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r13;
    // 0x8004FFF4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004FFF8: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004FFFC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80050000: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x80050004: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x80050008: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x8005000C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x80050010: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80050014: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80050018: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8005001C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80050020: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80050024: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80050028: nop

    // 0x8005002C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80050030: jal         0x80016620
    // 0x80050034: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80016620(rdram, ctx);
        goto after_9;
    // 0x80050034: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_9:
    // 0x80050038: jal         0x80016138
    // 0x8005003C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_10;
    // 0x8005003C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_10:
    // 0x80050040: beq         $v0, $zero, L_80050064
    if (ctx->r2 == 0) {
        // 0x80050044: nop
    
            goto L_80050064;
    }
    // 0x80050044: nop

L_80050048:
    // 0x80050048: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8005004C: jal         0x800499B0
    // 0x80050050: nop

    func_800499B0(rdram, ctx);
        goto after_11;
    // 0x80050050: nop

    after_11:
    // 0x80050054: jal         0x80016138
    // 0x80050058: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_12;
    // 0x80050058: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_12:
    // 0x8005005C: bne         $v0, $zero, L_80050048
    if (ctx->r2 != 0) {
        // 0x80050060: nop
    
            goto L_80050048;
    }
    // 0x80050060: nop

L_80050064:
    // 0x80050064: b           L_8005006C
    // 0x80050068: nop

        goto L_8005006C;
    // 0x80050068: nop

L_8005006C:
    // 0x8005006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050070: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80050074: jr          $ra
    // 0x80050078: nop

    return;
    // 0x80050078: nop

;}
RECOMP_FUNC void func_80031728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031728: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003172C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031730: jal         0x80031AC8
    // 0x80031734: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x80031734: nop

    after_0:
    // 0x80031738: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8003173C: bne         $v0, $at, L_8003174C
    if (ctx->r2 != ctx->r1) {
        // 0x80031740: nop
    
            goto L_8003174C;
    }
    // 0x80031740: nop

    // 0x80031744: b           L_800317D4
    // 0x80031748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800317D4;
    // 0x80031748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003174C:
    // 0x8003174C: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_80031750:
    // 0x80031750: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x80031754: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031758: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8003175C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80031760: sw          $zero, 0x79D0($at)
    MEM_W(0X79D0, ctx->r1) = 0;
    // 0x80031764: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x80031768: nop

    // 0x8003176C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80031770: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80031774: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80031778: bne         $at, $zero, L_80031750
    if (ctx->r1 != 0) {
        // 0x8003177C: sh          $t9, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r25;
            goto L_80031750;
    }
    // 0x8003177C: sh          $t9, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r25;
    // 0x80031780: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80031784: sh          $zero, 0x2570($at)
    MEM_H(0X2570, ctx->r1) = 0;
    // 0x80031788: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003178C: sh          $zero, 0x2578($at)
    MEM_H(0X2578, ctx->r1) = 0;
    // 0x80031790: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x80031794: lbu         $t1, -0x6A00($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X6A00);
    // 0x80031798: nop

    // 0x8003179C: beq         $t1, $zero, L_800317B4
    if (ctx->r9 == 0) {
        // 0x800317A0: nop
    
            goto L_800317B4;
    }
    // 0x800317A0: nop

    // 0x800317A4: addiu       $t2, $zero, 0x23
    ctx->r10 = ADD32(0, 0X23);
    // 0x800317A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800317AC: b           L_800317BC
    // 0x800317B0: sh          $t2, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r10;
        goto L_800317BC;
    // 0x800317B0: sh          $t2, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = ctx->r10;
L_800317B4:
    // 0x800317B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800317B8: sh          $zero, 0x2518($at)
    MEM_H(0X2518, ctx->r1) = 0;
L_800317BC:
    // 0x800317BC: jal         0x8009600C
    // 0x800317C0: nop

    func_8009600C(rdram, ctx);
        goto after_1;
    // 0x800317C0: nop

    after_1:
    // 0x800317C4: b           L_800317D4
    // 0x800317C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800317D4;
    // 0x800317C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800317CC: b           L_800317D4
    // 0x800317D0: nop

        goto L_800317D4;
    // 0x800317D0: nop

L_800317D4:
    // 0x800317D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800317D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800317DC: jr          $ra
    // 0x800317E0: nop

    return;
    // 0x800317E0: nop

;}
RECOMP_FUNC void func_8002C270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C278: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002C27C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8002C280: lbu         $t6, 0x448($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X448);
    // 0x8002C284: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002C288: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002C28C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8002C290: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8002C294: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002C298: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002C29C: lw          $t1, 0x1668($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1668);
    // 0x8002C2A0: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    // 0x8002C2A4: beq         $t1, $zero, L_8002C2C8
    if (ctx->r9 == 0) {
        // 0x8002C2A8: nop
    
            goto L_8002C2C8;
    }
    // 0x8002C2A8: nop

    // 0x8002C2AC: lhu         $t2, 0x1E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1E);
    // 0x8002C2B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C2B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8002C2B8: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8002C2BC: lw          $a0, 0x1668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1668);
    // 0x8002C2C0: jal         0x800BC980
    // 0x8002C2C4: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x8002C2C4: nop

    after_0:
L_8002C2C8:
    // 0x8002C2C8: lhu         $t5, 0x1E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X1E);
    // 0x8002C2CC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8002C2D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C2D4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002C2D8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002C2DC: sw          $t4, 0x1668($at)
    MEM_W(0X1668, ctx->r1) = ctx->r12;
    // 0x8002C2E0: b           L_8002C2E8
    // 0x8002C2E4: nop

        goto L_8002C2E8;
    // 0x8002C2E4: nop

L_8002C2E8:
    // 0x8002C2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C2EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C2F0: jr          $ra
    // 0x8002C2F4: nop

    return;
    // 0x8002C2F4: nop

;}
