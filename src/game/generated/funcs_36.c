#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80074FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074FF8: jal         0x80061348
    // 0x80074FFC: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074FFC: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
    after_0:
    // 0x80075000: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80075004: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075008: bne         $v0, $zero, L_80075020
    if (ctx->r2 != 0) {
        // 0x8007500C: nop
    
            goto L_80075020;
    }
    // 0x8007500C: nop

    // 0x80075010: jal         0x80061348
    // 0x80075014: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075014: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
    after_1:
    // 0x80075018: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007501C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80075020:
    // 0x80075020: b           L_80075030
    // 0x80075024: nop

        goto L_80075030;
    // 0x80075024: nop

    // 0x80075028: b           L_80075030
    // 0x8007502C: nop

        goto L_80075030;
    // 0x8007502C: nop

L_80075030:
    // 0x80075030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075038: jr          $ra
    // 0x8007503C: nop

    return;
    // 0x8007503C: nop

;}
RECOMP_FUNC void AudioDriver_ProcessSoundDeallocRequests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9A18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B9A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B9A20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B9A24: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800B9A28: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800B9A2C:
    // 0x800B9A2C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9A30: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x800B9A34: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B9A38: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800B9A3C: lw          $s0, -0x1E0C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X1E0C);
    // 0x800B9A40: nop

    // 0x800B9A44: beq         $s0, $zero, L_800B9A6C
    if (ctx->r16 == 0) {
        // 0x800B9A48: nop
    
            goto L_800B9A6C;
    }
    // 0x800B9A48: nop

    // 0x800B9A4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B9A50: beq         $s0, $at, L_800B9A74
    if (ctx->r16 == ctx->r1) {
        // 0x800B9A54: nop
    
            goto L_800B9A74;
    }
    // 0x800B9A54: nop

    // 0x800B9A58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B9A5C: beq         $s0, $at, L_800B9AD8
    if (ctx->r16 == ctx->r1) {
        // 0x800B9A60: nop
    
            goto L_800B9AD8;
    }
    // 0x800B9A60: nop

    // 0x800B9A64: b           L_800B9B64
    // 0x800B9A68: nop

        goto L_800B9B64;
    // 0x800B9A68: nop

L_800B9A6C:
    // 0x800B9A6C: b           L_800B9B64
    // 0x800B9A70: nop

        goto L_800B9B64;
    // 0x800B9A70: nop

L_800B9A74:
    // 0x800B9A74: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800B9A78: nop

    // 0x800B9A7C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B9A80: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800B9A84: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9A88: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9A8C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800B9A90: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x800B9A94: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9A98: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9A9C: lh          $a1, -0x1E10($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1E10);
    // 0x800B9AA0: jal         0x800C9760
    // 0x800B9AA4: nop

    alSndpSetSound(rdram, ctx);
        goto after_0;
    // 0x800B9AA4: nop

    after_0:
    // 0x800B9AA8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9AAC: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9AB0: jal         0x800C9780
    // 0x800B9AB4: nop

    alSndpStop(rdram, ctx);
        goto after_1;
    // 0x800B9AB4: nop

    after_1:
    // 0x800B9AB8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9ABC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9AC0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800B9AC4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B9AC8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800B9ACC: sw          $t2, -0x1E0C($at)
    MEM_W(-0X1E0C, ctx->r1) = ctx->r10;
    // 0x800B9AD0: b           L_800B9B64
    // 0x800B9AD4: nop

        goto L_800B9B64;
    // 0x800B9AD4: nop

L_800B9AD8:
    // 0x800B9AD8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800B9ADC: nop

    // 0x800B9AE0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B9AE4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800B9AE8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9AEC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9AF0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B9AF4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800B9AF8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9AFC: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9B00: lh          $a1, -0x1E10($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1E10);
    // 0x800B9B04: jal         0x800C9760
    // 0x800B9B08: nop

    alSndpSetSound(rdram, ctx);
        goto after_2;
    // 0x800B9B08: nop

    after_2:
    // 0x800B9B0C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9B10: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9B14: jal         0x800C97D0
    // 0x800B9B18: nop

    alSndpGetState(rdram, ctx);
        goto after_3;
    // 0x800B9B18: nop

    after_3:
    // 0x800B9B1C: bne         $v0, $zero, L_800B9B5C
    if (ctx->r2 != 0) {
        // 0x800B9B20: nop
    
            goto L_800B9B5C;
    }
    // 0x800B9B20: nop

    // 0x800B9B24: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9B28: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9B2C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B9B30: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x800B9B34: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9B38: lw          $a0, -0x17B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17B0);
    // 0x800B9B3C: lh          $a1, -0x1E10($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X1E10);
    // 0x800B9B40: jal         0x800C97F0
    // 0x800B9B44: nop

    alSndpDeallocate(rdram, ctx);
        goto after_4;
    // 0x800B9B44: nop

    after_4:
    // 0x800B9B48: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9B4C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9B50: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x800B9B54: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800B9B58: sw          $zero, -0x1E0C($at)
    MEM_W(-0X1E0C, ctx->r1) = 0;
L_800B9B5C:
    // 0x800B9B5C: b           L_800B9B64
    // 0x800B9B60: nop

        goto L_800B9B64;
    // 0x800B9B60: nop

L_800B9B64:
    // 0x800B9B64: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9B68: nop

    // 0x800B9B6C: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800B9B70: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x800B9B74: bne         $at, $zero, L_800B9A2C
    if (ctx->r1 != 0) {
        // 0x800B9B78: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_800B9A2C;
    }
    // 0x800B9B78: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800B9B7C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800B9B80: nop

    // 0x800B9B84: beq         $t5, $zero, L_800B9BA4
    if (ctx->r13 == 0) {
        // 0x800B9B88: nop
    
            goto L_800B9BA4;
    }
    // 0x800B9B88: nop

    // 0x800B9B8C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800B9B90: lw          $t6, -0x730C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X730C);
    // 0x800B9B94: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9B98: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x800B9B9C: b           L_800B9BBC
    // 0x800B9BA0: sw          $t7, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r15;
        goto L_800B9BBC;
    // 0x800B9BA0: sw          $t7, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r15;
L_800B9BA4:
    // 0x800B9BA4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800B9BA8: lw          $t8, -0x730C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X730C);
    // 0x800B9BAC: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800B9BB0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800B9BB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9BB8: sw          $t9, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r25;
L_800B9BBC:
    // 0x800B9BBC: b           L_800B9BC4
    // 0x800B9BC0: nop

        goto L_800B9BC4;
    // 0x800B9BC0: nop

L_800B9BC4:
    // 0x800B9BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9BC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B9BCC: jr          $ra
    // 0x800B9BD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B9BD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
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
RECOMP_FUNC void func_80065EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065ED0: jal         0x80061348
    // 0x80065ED4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065ED4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80065ED8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065EDC: b           L_80065EEC
    // 0x80065EE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065EEC;
    // 0x80065EE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065EE4: b           L_80065EEC
    // 0x80065EE8: nop

        goto L_80065EEC;
    // 0x80065EE8: nop

L_80065EEC:
    // 0x80065EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065EF4: jr          $ra
    // 0x80065EF8: nop

    return;
    // 0x80065EF8: nop

;}
RECOMP_FUNC void func_80097420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097420: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80097424: lw          $t6, 0x280($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X280);
    // 0x80097428: nop

    // 0x8009742C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80097430: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80097434: nop

    // 0x80097438: beq         $t7, $zero, L_80097488
    if (ctx->r15 == 0) {
        // 0x8009743C: nop
    
            goto L_80097488;
    }
    // 0x8009743C: nop

L_80097440:
    // 0x80097440: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80097444: nop

    // 0x80097448: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8009744C: nop

    // 0x80097450: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80097454: bne         $t0, $zero, L_80097470
    if (ctx->r8 != 0) {
        // 0x80097458: nop
    
            goto L_80097470;
    }
    // 0x80097458: nop

    // 0x8009745C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80097460: nop

    // 0x80097464: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80097468: nop

    // 0x8009746C: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
L_80097470:
    // 0x80097470: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80097474: nop

    // 0x80097478: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009747C: nop

    // 0x80097480: bne         $t4, $zero, L_80097440
    if (ctx->r12 != 0) {
        // 0x80097484: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_80097440;
    }
    // 0x80097484: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
L_80097488:
    // 0x80097488: b           L_80097490
    // 0x8009748C: nop

        goto L_80097490;
    // 0x8009748C: nop

L_80097490:
    // 0x80097490: jr          $ra
    // 0x80097494: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80097494: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006584C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006584C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065850: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065854: nop

    // 0x80065858: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x8006585C: nop

    // 0x80065860: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80065864: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065868: jr          $ra
    // 0x8006586C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006586C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065870: jr          $ra
    // 0x80065874: nop

    return;
    // 0x80065874: nop

    // 0x80065878: jr          $ra
    // 0x8006587C: nop

    return;
    // 0x8006587C: nop

;}
RECOMP_FUNC void func_80076924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007692C: jal         0x80061348
    // 0x80076930: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076930: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x80076934: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076938: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007693C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076940: beq         $v0, $zero, L_80076978
    if (ctx->r2 == 0) {
        // 0x80076944: nop
    
            goto L_80076978;
    }
    // 0x80076944: nop

    // 0x80076948: jal         0x80061348
    // 0x8007694C: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007694C: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x80076950: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80076954: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007695C: beq         $v0, $zero, L_80076978
    if (ctx->r2 == 0) {
        // 0x80076960: nop
    
            goto L_80076978;
    }
    // 0x80076960: nop

    // 0x80076964: jal         0x80061348
    // 0x80076968: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076968: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x8007696C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80076970: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80076974: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80076978:
    // 0x80076978: b           L_80076988
    // 0x8007697C: nop

        goto L_80076988;
    // 0x8007697C: nop

    // 0x80076980: b           L_80076988
    // 0x80076984: nop

        goto L_80076988;
    // 0x80076984: nop

L_80076988:
    // 0x80076988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007698C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076990: jr          $ra
    // 0x80076994: nop

    return;
    // 0x80076994: nop

;}
RECOMP_FUNC void func_800841CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800841D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800841D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800841D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800841DC: nop

    // 0x800841E0: sh          $zero, 0xBFE($t6)
    MEM_H(0XBFE, ctx->r14) = 0;
    // 0x800841E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800841E8: nop

    // 0x800841EC: lh          $a1, 0xBFE($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XBFE);
    // 0x800841F0: jal         0x8008C2E8
    // 0x800841F4: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    func_8008C2E8(rdram, ctx);
        goto after_0;
    // 0x800841F4: addiu       $a0, $t7, 0xBEE
    ctx->r4 = ADD32(ctx->r15, 0XBEE);
    after_0:
    // 0x800841F8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800841FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084200: addiu       $a0, $a0, 0x4BFC
    ctx->r4 = ADD32(ctx->r4, 0X4BFC);
    // 0x80084204: jal         0x800AEA98
    // 0x80084208: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    ContPak_SetFileFindParams(rdram, ctx);
        goto after_1;
    // 0x80084208: addiu       $a1, $a1, 0xBEE
    ctx->r5 = ADD32(ctx->r5, 0XBEE);
    after_1:
    // 0x8008420C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80084210: nop

    // 0x80084214: sh          $zero, 0xC14($t8)
    MEM_H(0XC14, ctx->r24) = 0;
    // 0x80084218: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8008421C: nop

    // 0x80084220: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x80084224: b           L_80084234
    // 0x80084228: nop

        goto L_80084234;
    // 0x80084228: nop

    // 0x8008422C: b           L_80084234
    // 0x80084230: nop

        goto L_80084234;
    // 0x80084230: nop

L_80084234:
    // 0x80084234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008423C: jr          $ra
    // 0x80084240: nop

    return;
    // 0x80084240: nop

;}
RECOMP_FUNC void func_8001A210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A210: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001A214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A218: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001A21C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A220: nop

    // 0x8001A224: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8001A228: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001A22C: nop

    // 0x8001A230: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8001A234: nop

    // 0x8001A238: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8001A23C: beq         $t9, $zero, L_8001A5E8
    if (ctx->r25 == 0) {
        // 0x8001A240: nop
    
            goto L_8001A5E8;
    }
    // 0x8001A240: nop

    // 0x8001A244: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8001A248: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A24C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8001A250: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001A254: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001A258: lwc1        $f4, 0x1E8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1E8);
    // 0x8001A25C: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001A260: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001A264: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x8001A268: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8001A26C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8001A270: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001A274: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8001A278: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8001A27C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8001A280: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8001A284: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8001A288: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8001A28C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001A290: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A294: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8001A298: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001A29C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001A2A0: lwc1        $f8, 0x1EC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1EC);
    // 0x8001A2A4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001A2A8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001A2AC: addiu       $t0, $t0, 0x61D8
    ctx->r8 = ADD32(ctx->r8, 0X61D8);
    // 0x8001A2B0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8001A2B4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001A2B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001A2BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8001A2C0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8001A2C4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001A2C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8001A2CC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001A2D0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8001A2D4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A2D8: nop

    // 0x8001A2DC: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x8001A2E0: nop

    // 0x8001A2E4: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x8001A2E8: beq         $t4, $zero, L_8001A2F8
    if (ctx->r12 == 0) {
        // 0x8001A2EC: nop
    
            goto L_8001A2F8;
    }
    // 0x8001A2EC: nop

    // 0x8001A2F0: b           L_8001A5E0
    // 0x8001A2F4: nop

        goto L_8001A5E0;
    // 0x8001A2F4: nop

L_8001A2F8:
    // 0x8001A2F8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001A2FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001A300: lwc1        $f16, 0x1F0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X1F0);
    // 0x8001A304: nop

    // 0x8001A308: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8001A30C: nop

    // 0x8001A310: bc1f        L_8001A3A8
    if (!c1cs) {
        // 0x8001A314: nop
    
            goto L_8001A3A8;
    }
    // 0x8001A314: nop

    // 0x8001A318: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001A31C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001A320: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001A324: lwc1        $f4, 0xEC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XEC);
    // 0x8001A328: lwc1        $f10, 0xE8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8001A32C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001A330: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001A334: swc1        $f16, 0xE8($t6)
    MEM_W(0XE8, ctx->r14) = ctx->f16.u32l;
    // 0x8001A338: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001A33C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001A340: lwc1        $f18, 0xE8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x8001A344: nop

    // 0x8001A348: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8001A34C: nop

    // 0x8001A350: bc1f        L_8001A368
    if (!c1cs) {
        // 0x8001A354: nop
    
            goto L_8001A368;
    }
    // 0x8001A354: nop

    // 0x8001A358: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001A35C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001A360: nop

    // 0x8001A364: swc1        $f6, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f6.u32l;
L_8001A368:
    // 0x8001A368: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001A36C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001A370: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001A374: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001A378: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001A37C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8001A380: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8001A384: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001A388: nop

    // 0x8001A38C: lwc1        $f4, 0x1F0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1F0);
    // 0x8001A390: nop

    // 0x8001A394: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001A398: sub.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d - ctx->f18.d;
    // 0x8001A39C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8001A3A0: b           L_8001A3C8
    // 0x8001A3A4: swc1        $f10, 0x1F0($t9)
    MEM_W(0X1F0, ctx->r25) = ctx->f10.u32l;
        goto L_8001A3C8;
    // 0x8001A3A4: swc1        $f10, 0x1F0($t9)
    MEM_W(0X1F0, ctx->r25) = ctx->f10.u32l;
L_8001A3A8:
    // 0x8001A3A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001A3AC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A3B0: nop

    // 0x8001A3B4: swc1        $f16, 0x1F0($t0)
    MEM_W(0X1F0, ctx->r8) = ctx->f16.u32l;
    // 0x8001A3B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001A3BC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8001A3C0: nop

    // 0x8001A3C4: swc1        $f4, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f4.u32l;
L_8001A3C8:
    // 0x8001A3C8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A3CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001A3D0: lwc1        $f6, 0x1F4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X1F4);
    // 0x8001A3D4: nop

    // 0x8001A3D8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8001A3DC: nop

    // 0x8001A3E0: bc1f        L_8001A428
    if (!c1cs) {
        // 0x8001A3E4: nop
    
            goto L_8001A428;
    }
    // 0x8001A3E4: nop

    // 0x8001A3E8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001A3EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001A3F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001A3F4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001A3F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001A3FC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001A400: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8001A404: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8001A408: nop

    // 0x8001A40C: lwc1        $f6, 0x1F4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1F4);
    // 0x8001A410: nop

    // 0x8001A414: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8001A418: sub.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f18.d - ctx->f4.d;
    // 0x8001A41C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8001A420: b           L_8001A514
    // 0x8001A424: swc1        $f8, 0x1F4($t3)
    MEM_W(0X1F4, ctx->r11) = ctx->f8.u32l;
        goto L_8001A514;
    // 0x8001A424: swc1        $f8, 0x1F4($t3)
    MEM_W(0X1F4, ctx->r11) = ctx->f8.u32l;
L_8001A428:
    // 0x8001A428: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001A42C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001A430: nop

    // 0x8001A434: swc1        $f16, 0x1F4($t4)
    MEM_W(0X1F4, ctx->r12) = ctx->f16.u32l;
    // 0x8001A438: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001A43C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001A440: lwc1        $f6, 0x1F8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X1F8);
    // 0x8001A444: nop

    // 0x8001A448: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8001A44C: nop

    // 0x8001A450: bc1f        L_8001A4F0
    if (!c1cs) {
        // 0x8001A454: nop
    
            goto L_8001A4F0;
    }
    // 0x8001A454: nop

    // 0x8001A458: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001A45C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001A460: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001A464: lwc1        $f4, 0xEC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XEC);
    // 0x8001A468: lwc1        $f16, 0xE8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8001A46C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8001A470: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8001A474: swc1        $f6, 0xE8($t6)
    MEM_W(0XE8, ctx->r14) = ctx->f6.u32l;
    // 0x8001A478: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8001A47C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001A480: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001A484: lwc1        $f18, 0xE8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x8001A488: nop

    // 0x8001A48C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8001A490: nop

    // 0x8001A494: bc1f        L_8001A4B0
    if (!c1cs) {
        // 0x8001A498: nop
    
            goto L_8001A4B0;
    }
    // 0x8001A498: nop

    // 0x8001A49C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001A4A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001A4A4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001A4A8: nop

    // 0x8001A4AC: swc1        $f10, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f10.u32l;
L_8001A4B0:
    // 0x8001A4B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001A4B4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8001A4B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001A4BC: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001A4C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001A4C4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8001A4C8: mul.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x8001A4CC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001A4D0: nop

    // 0x8001A4D4: lwc1        $f4, 0x1F8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1F8);
    // 0x8001A4D8: nop

    // 0x8001A4DC: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8001A4E0: sub.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d - ctx->f18.d;
    // 0x8001A4E4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8001A4E8: b           L_8001A514
    // 0x8001A4EC: swc1        $f16, 0x1F8($t9)
    MEM_W(0X1F8, ctx->r25) = ctx->f16.u32l;
        goto L_8001A514;
    // 0x8001A4EC: swc1        $f16, 0x1F8($t9)
    MEM_W(0X1F8, ctx->r25) = ctx->f16.u32l;
L_8001A4F0:
    // 0x8001A4F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001A4F4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A4F8: nop

    // 0x8001A4FC: swc1        $f6, 0x1F8($t0)
    MEM_W(0X1F8, ctx->r8) = ctx->f6.u32l;
    // 0x8001A500: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001A504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001A508: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8001A50C: nop

    // 0x8001A510: swc1        $f4, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f4.u32l;
L_8001A514:
    // 0x8001A514: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A518: nop

    // 0x8001A51C: lwc1        $f10, 0x1F8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X1F8);
    // 0x8001A520: lwc1        $f18, 0x1F0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X1F0);
    // 0x8001A524: nop

    // 0x8001A528: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x8001A52C: nop

    // 0x8001A530: bc1f        L_8001A5A4
    if (!c1cs) {
        // 0x8001A534: nop
    
            goto L_8001A5A4;
    }
    // 0x8001A534: nop

    // 0x8001A538: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001A53C: nop

    // 0x8001A540: c.eq.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl == ctx->f8.fl;
    // 0x8001A544: nop

    // 0x8001A548: bc1f        L_8001A5A4
    if (!c1cs) {
        // 0x8001A54C: nop
    
            goto L_8001A5A4;
    }
    // 0x8001A54C: nop

    // 0x8001A550: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8001A554: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001A558: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x8001A55C: nop

    // 0x8001A560: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8001A564: sw          $t5, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = ctx->r13;
    // 0x8001A568: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A56C: nop

    // 0x8001A570: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x8001A574: nop

    // 0x8001A578: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8001A57C: sw          $t8, 0x1A8($t6)
    MEM_W(0X1A8, ctx->r14) = ctx->r24;
    // 0x8001A580: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001A584: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001A588: nop

    // 0x8001A58C: swc1        $f16, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f16.u32l;
    // 0x8001A590: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001A594: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001A598: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001A59C: b           L_8001A5E0
    // 0x8001A5A0: swc1        $f6, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f6.u32l;
        goto L_8001A5E0;
    // 0x8001A5A0: swc1        $f6, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f6.u32l;
L_8001A5A4:
    // 0x8001A5A4: jal         0x800C1754
    // 0x8001A5A8: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8001A5A8: nop

    after_0:
    // 0x8001A5AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001A5B0: jal         0x8009A14C
    // 0x8001A5B4: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x8001A5B4: nop

    after_1:
    // 0x8001A5B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001A5BC: jal         0x800997D8
    // 0x8001A5C0: nop

    func_800997D8(rdram, ctx);
        goto after_2;
    // 0x8001A5C0: nop

    after_2:
    // 0x8001A5C4: jal         0x800C1A28
    // 0x8001A5C8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x8001A5C8: nop

    after_3:
    // 0x8001A5CC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8001A5D0: lw          $t1, 0x7238($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7238);
    // 0x8001A5D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001A5D8: ori         $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 | 0X8000;
    // 0x8001A5DC: sw          $t2, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r10;
L_8001A5E0:
    // 0x8001A5E0: b           L_8001A670
    // 0x8001A5E4: nop

        goto L_8001A670;
    // 0x8001A5E4: nop

L_8001A5E8:
    // 0x8001A5E8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001A5EC: nop

    // 0x8001A5F0: lw          $t5, 0x1A8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A8);
    // 0x8001A5F4: nop

    // 0x8001A5F8: andi        $t3, $t5, 0x2
    ctx->r11 = ctx->r13 & 0X2;
    // 0x8001A5FC: beq         $t3, $zero, L_8001A670
    if (ctx->r11 == 0) {
        // 0x8001A600: nop
    
            goto L_8001A670;
    }
    // 0x8001A600: nop

    // 0x8001A604: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001A608: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8001A60C: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8001A610: nop

    // 0x8001A614: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8001A618: sw          $t6, 0x1A8($t7)
    MEM_W(0X1A8, ctx->r15) = ctx->r14;
    // 0x8001A61C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A620: jal         0x80019F4C
    // 0x8001A624: nop

    func_80019F4C(rdram, ctx);
        goto after_4;
    // 0x8001A624: nop

    after_4:
    // 0x8001A628: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8001A62C: lh          $t9, 0x7228($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7228);
    // 0x8001A630: nop

    // 0x8001A634: bne         $t9, $zero, L_8001A65C
    if (ctx->r25 != 0) {
        // 0x8001A638: nop
    
            goto L_8001A65C;
    }
    // 0x8001A638: nop

    // 0x8001A63C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8001A640: lw          $t0, 0x7238($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7238);
    // 0x8001A644: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001A648: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8001A64C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8001A650: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001A654: b           L_8001A670
    // 0x8001A658: sw          $t1, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r9;
        goto L_8001A670;
    // 0x8001A658: sw          $t1, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r9;
L_8001A65C:
    // 0x8001A65C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8001A660: lw          $t2, 0x7238($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7238);
    // 0x8001A664: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001A668: ori         $t4, $t2, 0x8000
    ctx->r12 = ctx->r10 | 0X8000;
    // 0x8001A66C: sw          $t4, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r12;
L_8001A670:
    // 0x8001A670: b           L_8001A680
    // 0x8001A674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001A680;
    // 0x8001A674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A678: b           L_8001A680
    // 0x8001A67C: nop

        goto L_8001A680;
    // 0x8001A67C: nop

L_8001A680:
    // 0x8001A680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001A688: jr          $ra
    // 0x8001A68C: nop

    return;
    // 0x8001A68C: nop

;}
RECOMP_FUNC void func_80002824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000282C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80002830:
    // 0x80002830: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80002834: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80002838: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8000283C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80002840: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80002844: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80002848: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000284C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80002850: lw          $t8, 0x6DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6DC0);
    // 0x80002854: nop

    // 0x80002858: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8000285C: beq         $t9, $zero, L_80002890
    if (ctx->r25 == 0) {
        // 0x80002860: nop
    
            goto L_80002890;
    }
    // 0x80002860: nop

    // 0x80002864: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80002868: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000286C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80002870: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80002874: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80002878: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8000287C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80002880: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80002884: sw          $zero, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = 0;
    // 0x80002888: b           L_8000298C
    // 0x8000288C: nop

        goto L_8000298C;
    // 0x8000288C: nop

L_80002890:
    // 0x80002890: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80002894: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80002898: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8000289C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800028A0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800028A4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800028A8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800028AC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800028B0: lw          $t4, 0x6DC0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6DC0);
    // 0x800028B4: nop

    // 0x800028B8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800028BC: bne         $t5, $zero, L_800028CC
    if (ctx->r13 != 0) {
        // 0x800028C0: nop
    
            goto L_800028CC;
    }
    // 0x800028C0: nop

    // 0x800028C4: b           L_8000298C
    // 0x800028C8: nop

        goto L_8000298C;
    // 0x800028C8: nop

L_800028CC:
    // 0x800028CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800028D0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800028D4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800028D8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800028DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800028E0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800028E4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800028E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800028EC: lw          $t8, 0x6DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6DC0);
    // 0x800028F0: nop

    // 0x800028F4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x800028F8: beq         $t9, $zero, L_80002908
    if (ctx->r25 == 0) {
        // 0x800028FC: nop
    
            goto L_80002908;
    }
    // 0x800028FC: nop

    // 0x80002900: b           L_8000298C
    // 0x80002904: nop

        goto L_8000298C;
    // 0x80002904: nop

L_80002908:
    // 0x80002908: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000290C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80002910: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80002914: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80002918: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8000291C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80002920: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80002924: addiu       $t2, $t2, 0x6C20
    ctx->r10 = ADD32(ctx->r10, 0X6C20);
    // 0x80002928: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8000292C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80002930: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80002934: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002938: lw          $t5, 0x1A4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A4);
    // 0x8000293C: nop

    // 0x80002940: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80002944: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80002948: lw          $t7, -0x248C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X248C);
    // 0x8000294C: nop

    // 0x80002950: bne         $t7, $zero, L_80002960
    if (ctx->r15 != 0) {
        // 0x80002954: nop
    
            goto L_80002960;
    }
    // 0x80002954: nop

    // 0x80002958: b           L_8000298C
    // 0x8000295C: nop

        goto L_8000298C;
    // 0x8000295C: nop

L_80002960:
    // 0x80002960: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80002964: nop

    // 0x80002968: lw          $t9, 0x1A4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A4);
    // 0x8000296C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80002970: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80002974: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80002978: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8000297C: lw          $t9, -0x248C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X248C);
    // 0x80002980: nop

    // 0x80002984: jalr        $t9
    // 0x80002988: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80002988: nop

    after_0:
L_8000298C:
    // 0x8000298C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80002990: nop

    // 0x80002994: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80002998: slti        $at, $t2, 0x20
    ctx->r1 = SIGNED(ctx->r10) < 0X20 ? 1 : 0;
    // 0x8000299C: bne         $at, $zero, L_80002830
    if (ctx->r1 != 0) {
        // 0x800029A0: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_80002830;
    }
    // 0x800029A0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800029A4: b           L_800029AC
    // 0x800029A8: nop

        goto L_800029AC;
    // 0x800029A8: nop

L_800029AC:
    // 0x800029AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800029B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800029B4: jr          $ra
    // 0x800029B8: nop

    return;
    // 0x800029B8: nop

;}
RECOMP_FUNC void Scheduler_ScheduleTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097F78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80097F7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097F80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097F84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80097F88: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80097F8C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80097F90: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80097F94: nop

    // 0x80097F98: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80097F9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80097FA0: nop

    // 0x80097FA4: lw          $t8, 0x288($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X288);
    // 0x80097FA8: nop

    // 0x80097FAC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80097FB0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80097FB4: nop

    // 0x80097FB8: lw          $t0, 0x284($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X284);
    // 0x80097FBC: nop

    // 0x80097FC0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80097FC4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80097FC8: nop

    // 0x80097FCC: lw          $t2, 0x2A4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2A4);
    // 0x80097FD0: nop

    // 0x80097FD4: beq         $t2, $zero, L_800980AC
    if (ctx->r10 == 0) {
        // 0x80097FD8: nop
    
            goto L_800980AC;
    }
    // 0x80097FD8: nop

    // 0x80097FDC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80097FE0: nop

    // 0x80097FE4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80097FE8: beq         $t4, $zero, L_800980AC
    if (ctx->r12 == 0) {
        // 0x80097FEC: nop
    
            goto L_800980AC;
    }
    // 0x80097FEC: nop

    // 0x80097FF0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80097FF4: nop

    // 0x80097FF8: beq         $t5, $zero, L_80098038
    if (ctx->r13 == 0) {
        // 0x80097FFC: nop
    
            goto L_80098038;
    }
    // 0x80097FFC: nop

    // 0x80098000: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80098004: nop

    // 0x80098008: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8009800C: beq         $t7, $zero, L_80098038
    if (ctx->r15 == 0) {
        // 0x80098010: nop
    
            goto L_80098038;
    }
    // 0x80098010: nop

    // 0x80098014: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80098018: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8009801C: nop

    // 0x80098020: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80098024: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80098028: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8009802C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80098030: b           L_800980A4
    // 0x80098034: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
        goto L_800980A4;
    // 0x80098034: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80098038:
    // 0x80098038: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8009803C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80098040: nop

    // 0x80098044: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80098048: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8009804C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80098050: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80098054: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80098058: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009805C: nop

    // 0x80098060: sw          $zero, 0x2A4($t6)
    MEM_W(0X2A4, ctx->r14) = 0;
    // 0x80098064: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80098068: nop

    // 0x8009806C: lw          $t8, 0x284($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X284);
    // 0x80098070: nop

    // 0x80098074: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80098078: nop

    // 0x8009807C: sw          $t9, 0x284($t7)
    MEM_W(0X284, ctx->r15) = ctx->r25;
    // 0x80098080: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80098084: nop

    // 0x80098088: lw          $t1, 0x284($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X284);
    // 0x8009808C: nop

    // 0x80098090: bne         $t1, $zero, L_800980A4
    if (ctx->r9 != 0) {
        // 0x80098094: nop
    
            goto L_800980A4;
    }
    // 0x80098094: nop

    // 0x80098098: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8009809C: nop

    // 0x800980A0: sw          $zero, 0x28C($t2)
    MEM_W(0X28C, ctx->r10) = 0;
L_800980A4:
    // 0x800980A4: b           L_80098358
    // 0x800980A8: nop

        goto L_80098358;
    // 0x800980A8: nop

L_800980AC:
    // 0x800980AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800980B0: jal         0x80097BDC
    // 0x800980B4: nop

    Scheduler_IsTaskReady(rdram, ctx);
        goto after_0;
    // 0x800980B4: nop

    after_0:
    // 0x800980B8: beq         $v0, $zero, L_80098358
    if (ctx->r2 == 0) {
        // 0x800980BC: nop
    
            goto L_80098358;
    }
    // 0x800980BC: nop

    // 0x800980C0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800980C4: nop

    // 0x800980C8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800980CC: nop

    // 0x800980D0: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x800980D4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800980D8: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x800980DC: beq         $at, $zero, L_80098350
    if (ctx->r1 == 0) {
        // 0x800980E0: nop
    
            goto L_80098350;
    }
    // 0x800980E0: nop

    // 0x800980E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800980E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800980EC: addu        $at, $at, $t6
    gpr jr_addend_800980F8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800980F0: lw          $t6, -0x870($at)
    ctx->r14 = ADD32(ctx->r1, -0X870);
    // 0x800980F4: nop

    // 0x800980F8: jr          $t6
    // 0x800980FC: nop

    switch (jr_addend_800980F8 >> 2) {
        case 0: goto L_80098350; break;
        case 1: goto L_80098260; break;
        case 2: goto L_80098100; break;
        case 3: goto L_80098350; break;
        case 4: goto L_80098350; break;
        case 5: goto L_80098260; break;
        case 6: goto L_80098260; break;
        default: switch_error(__func__, 0x800980F8, 0x800EF790);
    }
    // 0x800980FC: nop

L_80098100:
    // 0x80098100: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80098104: nop

    // 0x80098108: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8009810C: nop

    // 0x80098110: andi        $t7, $t9, 0x20
    ctx->r15 = ctx->r25 & 0X20;
    // 0x80098114: beq         $t7, $zero, L_800981D4
    if (ctx->r15 == 0) {
        // 0x80098118: nop
    
            goto L_800981D4;
    }
    // 0x80098118: nop

    // 0x8009811C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80098120: nop

    // 0x80098124: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80098128: beq         $t1, $zero, L_800981CC
    if (ctx->r9 == 0) {
        // 0x8009812C: nop
    
            goto L_800981CC;
    }
    // 0x8009812C: nop

    // 0x80098130: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80098134: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80098138: nop

    // 0x8009813C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80098140: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80098144: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80098148: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8009814C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80098150: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80098154: nop

    // 0x80098158: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8009815C: nop

    // 0x80098160: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80098164: beq         $t9, $zero, L_8009818C
    if (ctx->r25 == 0) {
        // 0x80098168: nop
    
            goto L_8009818C;
    }
    // 0x80098168: nop

    // 0x8009816C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80098170: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80098174: nop

    // 0x80098178: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8009817C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80098180: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80098184: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80098188: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_8009818C:
    // 0x8009818C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80098190: nop

    // 0x80098194: lw          $t4, 0x288($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X288);
    // 0x80098198: nop

    // 0x8009819C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800981A0: nop

    // 0x800981A4: sw          $t5, 0x288($t3)
    MEM_W(0X288, ctx->r11) = ctx->r13;
    // 0x800981A8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800981AC: nop

    // 0x800981B0: lw          $t8, 0x288($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X288);
    // 0x800981B4: nop

    // 0x800981B8: bne         $t8, $zero, L_800981CC
    if (ctx->r24 != 0) {
        // 0x800981BC: nop
    
            goto L_800981CC;
    }
    // 0x800981BC: nop

    // 0x800981C0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800981C4: nop

    // 0x800981C8: sw          $zero, 0x290($t9)
    MEM_W(0X290, ctx->r25) = 0;
L_800981CC:
    // 0x800981CC: b           L_80098258
    // 0x800981D0: nop

        goto L_80098258;
    // 0x800981D0: nop

L_800981D4:
    // 0x800981D4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800981D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800981DC: bne         $t7, $at, L_80098258
    if (ctx->r15 != ctx->r1) {
        // 0x800981E0: nop
    
            goto L_80098258;
    }
    // 0x800981E0: nop

    // 0x800981E4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800981E8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800981EC: nop

    // 0x800981F0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800981F4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800981F8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800981FC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80098200: nop

    // 0x80098204: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80098208: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8009820C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80098210: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x80098214: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80098218: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8009821C: nop

    // 0x80098220: lw          $t9, 0x288($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X288);
    // 0x80098224: nop

    // 0x80098228: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8009822C: nop

    // 0x80098230: sw          $t7, 0x288($t8)
    MEM_W(0X288, ctx->r24) = ctx->r15;
    // 0x80098234: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80098238: nop

    // 0x8009823C: lw          $t1, 0x288($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X288);
    // 0x80098240: nop

    // 0x80098244: bne         $t1, $zero, L_80098258
    if (ctx->r9 != 0) {
        // 0x80098248: nop
    
            goto L_80098258;
    }
    // 0x80098248: nop

    // 0x8009824C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80098250: nop

    // 0x80098254: sw          $zero, 0x290($t2)
    MEM_W(0X290, ctx->r10) = 0;
L_80098258:
    // 0x80098258: b           L_80098358
    // 0x8009825C: nop

        goto L_80098358;
    // 0x8009825C: nop

L_80098260:
    // 0x80098260: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80098264: nop

    // 0x80098268: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8009826C: nop

    // 0x80098270: andi        $t3, $t5, 0x2
    ctx->r11 = ctx->r13 & 0X2;
    // 0x80098274: beq         $t3, $zero, L_800982B8
    if (ctx->r11 == 0) {
        // 0x80098278: nop
    
            goto L_800982B8;
    }
    // 0x80098278: nop

    // 0x8009827C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80098280: nop

    // 0x80098284: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x80098288: beq         $t9, $zero, L_800982B0
    if (ctx->r25 == 0) {
        // 0x8009828C: nop
    
            goto L_800982B0;
    }
    // 0x8009828C: nop

    // 0x80098290: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80098294: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80098298: nop

    // 0x8009829C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800982A0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800982A4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800982A8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800982AC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_800982B0:
    // 0x800982B0: b           L_80098348
    // 0x800982B4: nop

        goto L_80098348;
    // 0x800982B4: nop

L_800982B8:
    // 0x800982B8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800982BC: nop

    // 0x800982C0: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x800982C4: nop

    // 0x800982C8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800982CC: beq         $t5, $zero, L_80098348
    if (ctx->r13 == 0) {
        // 0x800982D0: nop
    
            goto L_80098348;
    }
    // 0x800982D0: nop

    // 0x800982D4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800982D8: nop

    // 0x800982DC: andi        $t6, $t3, 0x1
    ctx->r14 = ctx->r11 & 0X1;
    // 0x800982E0: beq         $t6, $zero, L_80098348
    if (ctx->r14 == 0) {
        // 0x800982E4: nop
    
            goto L_80098348;
    }
    // 0x800982E4: nop

    // 0x800982E8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800982EC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800982F0: nop

    // 0x800982F4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800982F8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800982FC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80098300: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80098304: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80098308: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8009830C: nop

    // 0x80098310: lw          $t2, 0x288($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X288);
    // 0x80098314: nop

    // 0x80098318: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8009831C: nop

    // 0x80098320: sw          $t4, 0x288($t1)
    MEM_W(0X288, ctx->r9) = ctx->r12;
    // 0x80098324: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80098328: nop

    // 0x8009832C: lw          $t3, 0x288($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X288);
    // 0x80098330: nop

    // 0x80098334: bne         $t3, $zero, L_80098348
    if (ctx->r11 != 0) {
        // 0x80098338: nop
    
            goto L_80098348;
    }
    // 0x80098338: nop

    // 0x8009833C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80098340: nop

    // 0x80098344: sw          $zero, 0x290($t6)
    MEM_W(0X290, ctx->r14) = 0;
L_80098348:
    // 0x80098348: b           L_80098358
    // 0x8009834C: nop

        goto L_80098358;
    // 0x8009834C: nop

L_80098350:
    // 0x80098350: b           L_80098358
    // 0x80098354: nop

        goto L_80098358;
    // 0x80098354: nop

L_80098358:
    // 0x80098358: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8009835C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80098360: nop

    // 0x80098364: beq         $t9, $t7, L_80098388
    if (ctx->r25 == ctx->r15) {
        // 0x80098368: nop
    
            goto L_80098388;
    }
    // 0x80098368: nop

    // 0x8009836C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80098370: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80098374: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80098378: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8009837C: jal         0x80097F78
    // 0x80098380: nop

    Scheduler_ScheduleTask(rdram, ctx);
        goto after_1;
    // 0x80098380: nop

    after_1:
    // 0x80098384: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80098388:
    // 0x80098388: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8009838C: b           L_8009839C
    // 0x80098390: nop

        goto L_8009839C;
    // 0x80098390: nop

    // 0x80098394: b           L_8009839C
    // 0x80098398: nop

        goto L_8009839C;
    // 0x80098398: nop

L_8009839C:
    // 0x8009839C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800983A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800983A4: jr          $ra
    // 0x800983A8: nop

    return;
    // 0x800983A8: nop

;}
RECOMP_FUNC void func_800653D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800653D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800653DC: nop

    // 0x800653E0: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x800653E4: nop

    // 0x800653E8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800653EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800653F0: jr          $ra
    // 0x800653F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800653F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800653F8: jr          $ra
    // 0x800653FC: nop

    return;
    // 0x800653FC: nop

    // 0x80065400: jr          $ra
    // 0x80065404: nop

    return;
    // 0x80065404: nop

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
RECOMP_FUNC void func_80023C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023C90: jr          $ra
    // 0x80023C94: nop

    return;
    // 0x80023C94: nop

    // 0x80023C98: jr          $ra
    // 0x80023C9C: nop

    return;
    // 0x80023C9C: nop

;}
RECOMP_FUNC void func_8006C4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C4E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C4E8: jal         0x8005F064
    // 0x8006C4EC: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C4EC: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_0:
    // 0x8006C4F0: b           L_8006C500
    // 0x8006C4F4: nop

        goto L_8006C500;
    // 0x8006C4F4: nop

    // 0x8006C4F8: b           L_8006C500
    // 0x8006C4FC: nop

        goto L_8006C500;
    // 0x8006C4FC: nop

L_8006C500:
    // 0x8006C500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C508: jr          $ra
    // 0x8006C50C: nop

    return;
    // 0x8006C50C: nop

;}
RECOMP_FUNC void func_8007B710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B710: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007B714: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007B718: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007B71C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007B720: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007B724: nop

    // 0x8007B728: beq         $t6, $zero, L_8007BA98
    if (ctx->r14 == 0) {
        // 0x8007B72C: nop
    
            goto L_8007BA98;
    }
    // 0x8007B72C: nop

    // 0x8007B730: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B734: lb          $t7, 0x7108($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7108);
    // 0x8007B738: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007B73C: nop

    // 0x8007B740: bne         $t7, $t8, L_8007B750
    if (ctx->r15 != ctx->r24) {
        // 0x8007B744: nop
    
            goto L_8007B750;
    }
    // 0x8007B744: nop

    // 0x8007B748: b           L_8007C53C
    // 0x8007B74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007B74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B750:
    // 0x8007B750: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8007B754: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B758: sb          $t9, 0x7108($at)
    MEM_B(0X7108, ctx->r1) = ctx->r25;
    // 0x8007B75C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007B760: lb          $t0, 0x7108($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7108);
    // 0x8007B764: nop

    // 0x8007B768: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007B76C: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8007B770: beq         $at, $zero, L_8007BA90
    if (ctx->r1 == 0) {
        // 0x8007B774: nop
    
            goto L_8007BA90;
    }
    // 0x8007B774: nop

    // 0x8007B778: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007B77C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007B780: addu        $at, $at, $t1
    gpr jr_addend_8007B78C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007B784: lw          $t1, -0xD20($at)
    ctx->r9 = ADD32(ctx->r1, -0XD20);
    // 0x8007B788: nop

    // 0x8007B78C: jr          $t1
    // 0x8007B790: nop

    switch (jr_addend_8007B78C >> 2) {
        case 0: goto L_8007B794; break;
        case 1: goto L_8007B7F0; break;
        case 2: goto L_8007B840; break;
        case 3: goto L_8007B9A0; break;
        case 4: goto L_8007B9F0; break;
        case 5: goto L_8007BA40; break;
        default: switch_error(__func__, 0x8007B78C, 0x800EF2E0);
    }
    // 0x8007B790: nop

L_8007B794:
    // 0x8007B794: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007B798: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B79C: swc1        $f4, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f4.u32l;
    // 0x8007B7A0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007B7A4: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007B7A8: addiu       $t2, $zero, 0xE0
    ctx->r10 = ADD32(0, 0XE0);
    // 0x8007B7AC: sh          $t2, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r10;
    // 0x8007B7B0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007B7B4: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007B7B8: addiu       $t4, $zero, -0xA
    ctx->r12 = ADD32(0, -0XA);
    // 0x8007B7BC: sh          $t4, 0x120($t5)
    MEM_H(0X120, ctx->r13) = ctx->r12;
    // 0x8007B7C0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B7C4: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007B7C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B7CC: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8007B7D0: sh          $t7, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r15;
    // 0x8007B7D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007B7D8: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007B7DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B7E0: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x8007B7E4: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007B7E8: b           L_8007BA90
    // 0x8007B7EC: nop

        goto L_8007BA90;
    // 0x8007B7EC: nop

L_8007B7F0:
    // 0x8007B7F0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007B7F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007B7F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B7FC: swc1        $f6, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f6.u32l;
    // 0x8007B800: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007B804: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007B808: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x8007B80C: sh          $t0, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r8;
    // 0x8007B810: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007B814: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007B818: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B81C: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x8007B820: sh          $t3, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r11;
    // 0x8007B824: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B828: lh          $t4, 0x713A($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X713A);
    // 0x8007B82C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B830: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x8007B834: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
    // 0x8007B838: b           L_8007BA90
    // 0x8007B83C: nop

        goto L_8007BA90;
    // 0x8007B83C: nop

L_8007B840:
    // 0x8007B840: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007B844: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007B848: jal         0x800A4074
    // 0x8007B84C: nop

    func_800A4074(rdram, ctx);
        goto after_0;
    // 0x8007B84C: nop

    after_0:
    // 0x8007B850: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B854: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007B858: addiu       $t6, $zero, 0x7D0
    ctx->r14 = ADD32(0, 0X7D0);
    // 0x8007B85C: sw          $t6, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r14;
    // 0x8007B860: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007B864: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007B868: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x8007B86C: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x8007B870: nop

    // 0x8007B874: sh          $t8, 0x1FE($t0)
    MEM_H(0X1FE, ctx->r8) = ctx->r24;
    // 0x8007B878: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007B87C: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007B880: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8007B884: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
    // 0x8007B888: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B88C: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007B890: addiu       $t3, $zero, 0xE0
    ctx->r11 = ADD32(0, 0XE0);
    // 0x8007B894: sh          $t3, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r11;
    // 0x8007B898: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B89C: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007B8A0: addiu       $t5, $zero, -0xA
    ctx->r13 = ADD32(0, -0XA);
    // 0x8007B8A4: sh          $t5, 0x120($t6)
    MEM_H(0X120, ctx->r14) = ctx->r13;
    // 0x8007B8A8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B8AC: addiu       $t7, $t7, 0x70F0
    ctx->r15 = ADD32(ctx->r15, 0X70F0);
    // 0x8007B8B0: addiu       $a0, $t7, 0x20
    ctx->r4 = ADD32(ctx->r15, 0X20);
    // 0x8007B8B4: addiu       $a1, $t7, 0x24
    ctx->r5 = ADD32(ctx->r15, 0X24);
    // 0x8007B8B8: addiu       $a2, $t7, 0x28
    ctx->r6 = ADD32(ctx->r15, 0X28);
    // 0x8007B8BC: addiu       $a3, $t7, 0x2C
    ctx->r7 = ADD32(ctx->r15, 0X2C);
    // 0x8007B8C0: jal         0x8007B12C
    // 0x8007B8C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007B12C(rdram, ctx);
        goto after_1;
    // 0x8007B8C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8007B8C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007B8CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B8D0: lwc1        $f8, 0x7110($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7110);
    // 0x8007B8D4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007B8D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007B8DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007B8E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B8E4: lwc1        $f16, 0x7114($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7114);
    // 0x8007B8E8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007B8EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B8F0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007B8F4: lwc1        $f18, 0x711C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X711C);
    // 0x8007B8F8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8007B8FC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007B900: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007B904: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007B908: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007B90C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8007B910: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007B914: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007B918: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B91C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007B920: lwc1        $f10, 0x7118($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7118);
    // 0x8007B924: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007B928: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8007B92C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007B930: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8007B934: nop

    // 0x8007B938: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8007B93C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007B940: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007B944: nop

    // 0x8007B948: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007B94C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8007B950: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007B954: nop

    // 0x8007B958: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8007B95C: nop

    // 0x8007B960: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8007B964: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007B968: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007B96C: nop

    // 0x8007B970: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007B974: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8007B978: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8007B97C: jal         0x800A39C4
    // 0x8007B980: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800A39C4(rdram, ctx);
        goto after_2;
    // 0x8007B980: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_2:
    // 0x8007B984: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007B988: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007B98C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B990: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x8007B994: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007B998: b           L_8007BA90
    // 0x8007B99C: nop

        goto L_8007BA90;
    // 0x8007B99C: nop

L_8007B9A0:
    // 0x8007B9A0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007B9A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007B9A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B9AC: swc1        $f8, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f8.u32l;
    // 0x8007B9B0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B9B4: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007B9B8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8007B9BC: sh          $t5, 0x11E($t6)
    MEM_H(0X11E, ctx->r14) = ctx->r13;
    // 0x8007B9C0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B9C4: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x8007B9C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B9CC: ori         $t9, $t7, 0x8
    ctx->r25 = ctx->r15 | 0X8;
    // 0x8007B9D0: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007B9D4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007B9D8: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007B9DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B9E0: ori         $t0, $t8, 0x40
    ctx->r8 = ctx->r24 | 0X40;
    // 0x8007B9E4: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007B9E8: b           L_8007BA90
    // 0x8007B9EC: nop

        goto L_8007BA90;
    // 0x8007B9EC: nop

L_8007B9F0:
    // 0x8007B9F0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007B9F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B9F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B9FC: swc1        $f10, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f10.u32l;
    // 0x8007BA00: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BA04: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BA08: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8007BA0C: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x8007BA10: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BA14: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007BA18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA1C: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x8007BA20: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
    // 0x8007BA24: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BA28: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007BA2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA30: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x8007BA34: sh          $t6, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r14;
    // 0x8007BA38: b           L_8007BA90
    // 0x8007BA3C: nop

        goto L_8007BA90;
    // 0x8007BA3C: nop

L_8007BA40:
    // 0x8007BA40: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007BA44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007BA48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA4C: swc1        $f18, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f18.u32l;
    // 0x8007BA50: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BA54: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BA58: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8007BA5C: sh          $t7, 0x11E($t9)
    MEM_H(0X11E, ctx->r25) = ctx->r15;
    // 0x8007BA60: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BA64: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007BA68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA6C: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x8007BA70: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007BA74: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BA78: lh          $t1, 0x713A($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X713A);
    // 0x8007BA7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BA80: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x8007BA84: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
    // 0x8007BA88: b           L_8007BA90
    // 0x8007BA8C: nop

        goto L_8007BA90;
    // 0x8007BA8C: nop

L_8007BA90:
    // 0x8007BA90: b           L_8007C53C
    // 0x8007BA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007BA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007BA98:
    // 0x8007BA98: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BA9C: lb          $t3, 0x7108($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7108);
    // 0x8007BAA0: nop

    // 0x8007BAA4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007BAA8: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x8007BAAC: beq         $at, $zero, L_8007C19C
    if (ctx->r1 == 0) {
        // 0x8007BAB0: nop
    
            goto L_8007C19C;
    }
    // 0x8007BAB0: nop

    // 0x8007BAB4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007BAB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007BABC: addu        $at, $at, $t4
    gpr jr_addend_8007BAC8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8007BAC0: lw          $t4, -0xD08($at)
    ctx->r12 = ADD32(ctx->r1, -0XD08);
    // 0x8007BAC4: nop

    // 0x8007BAC8: jr          $t4
    // 0x8007BACC: nop

    switch (jr_addend_8007BAC8 >> 2) {
        case 0: goto L_8007C194; break;
        case 1: goto L_8007C19C; break;
        case 2: goto L_8007BAD0; break;
        case 3: goto L_8007BC80; break;
        case 4: goto L_8007BD94; break;
        case 5: goto L_8007BE94; break;
        case 6: goto L_8007BF84; break;
        case 7: goto L_8007C0A4; break;
        default: switch_error(__func__, 0x8007BAC8, 0x800EF2F8);
    }
    // 0x8007BACC: nop

L_8007BAD0:
    // 0x8007BAD0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BAD4: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007BAD8: nop

    // 0x8007BADC: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x8007BAE0: beq         $t6, $zero, L_8007BB80
    if (ctx->r14 == 0) {
        // 0x8007BAE4: nop
    
            goto L_8007BB80;
    }
    // 0x8007BAE4: nop

    // 0x8007BAE8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BAEC: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BAF0: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8007BAF4: sw          $t7, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r15;
    // 0x8007BAF8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BAFC: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007BB00: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007BB04: sh          $t8, 0x116($t0)
    MEM_H(0X116, ctx->r8) = ctx->r24;
    // 0x8007BB08: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BB0C: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007BB10: nop

    // 0x8007BB14: sh          $zero, 0x114($t1)
    MEM_H(0X114, ctx->r9) = 0;
    // 0x8007BB18: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BB1C: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BB20: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8007BB24: sw          $t2, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r10;
    // 0x8007BB28: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BB2C: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007BB30: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8007BB34: sh          $t4, 0x118($t5)
    MEM_H(0X118, ctx->r13) = ctx->r12;
    // 0x8007BB38: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BB3C: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007BB40: nop

    // 0x8007BB44: sh          $zero, 0x11A($t6)
    MEM_H(0X11A, ctx->r14) = 0;
    // 0x8007BB48: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BB4C: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007BB50: nop

    // 0x8007BB54: sh          $zero, 0x11C($t7)
    MEM_H(0X11C, ctx->r15) = 0;
    // 0x8007BB58: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BB5C: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BB60: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8007BB64: sh          $t9, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r25;
    // 0x8007BB68: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BB6C: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007BB70: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007BB74: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8007BB78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BB7C: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
L_8007BB80:
    // 0x8007BB80: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BB84: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007BB88: addiu       $a0, $t2, 0x20
    ctx->r4 = ADD32(ctx->r10, 0X20);
    // 0x8007BB8C: addiu       $a1, $t2, 0x24
    ctx->r5 = ADD32(ctx->r10, 0X24);
    // 0x8007BB90: addiu       $a2, $t2, 0x28
    ctx->r6 = ADD32(ctx->r10, 0X28);
    // 0x8007BB94: addiu       $a3, $t2, 0x2C
    ctx->r7 = ADD32(ctx->r10, 0X2C);
    // 0x8007BB98: jal         0x8007B12C
    // 0x8007BB9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007B12C(rdram, ctx);
        goto after_3;
    // 0x8007BB9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8007BBA0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BBA4: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BBA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007BBAC: lh          $t4, 0x120($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X120);
    // 0x8007BBB0: lh          $t5, 0x11E($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X11E);
    // 0x8007BBB4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8007BBB8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007BBBC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007BBC0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8007BBC4: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8007BBC8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007BBCC: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8007BBD0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007BBD4: nop

    // 0x8007BBD8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8007BBDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007BBE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007BBE4: nop

    // 0x8007BBE8: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007BBEC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8007BBF0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007BBF4: sh          $t7, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r15;
    // 0x8007BBF8: nop

    // 0x8007BBFC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BC00: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BC04: nop

    // 0x8007BC08: lh          $t8, 0x11E($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X11E);
    // 0x8007BC0C: nop

    // 0x8007BC10: bgez        $t8, L_8007BC38
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007BC14: nop
    
            goto L_8007BC38;
    }
    // 0x8007BC14: nop

    // 0x8007BC18: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BC1C: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007BC20: nop

    // 0x8007BC24: sh          $zero, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = 0;
    // 0x8007BC28: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BC2C: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BC30: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8007BC34: sh          $t1, 0x120($t2)
    MEM_H(0X120, ctx->r10) = ctx->r9;
L_8007BC38:
    // 0x8007BC38: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007BC3C: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007BC40: nop

    // 0x8007BC44: lh          $t5, 0x11E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X11E);
    // 0x8007BC48: nop

    // 0x8007BC4C: slti        $at, $t5, 0xE1
    ctx->r1 = SIGNED(ctx->r13) < 0XE1 ? 1 : 0;
    // 0x8007BC50: bne         $at, $zero, L_8007BC78
    if (ctx->r1 != 0) {
        // 0x8007BC54: nop
    
            goto L_8007BC78;
    }
    // 0x8007BC54: nop

    // 0x8007BC58: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BC5C: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007BC60: addiu       $t6, $zero, 0xE0
    ctx->r14 = ADD32(0, 0XE0);
    // 0x8007BC64: sh          $t6, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r14;
    // 0x8007BC68: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BC6C: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BC70: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x8007BC74: sh          $t3, 0x120($t9)
    MEM_H(0X120, ctx->r25) = ctx->r11;
L_8007BC78:
    // 0x8007BC78: b           L_8007C1B4
    // 0x8007BC7C: nop

        goto L_8007C1B4;
    // 0x8007BC7C: nop

L_8007BC80:
    // 0x8007BC80: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BC84: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007BC88: nop

    // 0x8007BC8C: andi        $t0, $t8, 0x40
    ctx->r8 = ctx->r24 & 0X40;
    // 0x8007BC90: beq         $t0, $zero, L_8007BD30
    if (ctx->r8 == 0) {
        // 0x8007BC94: nop
    
            goto L_8007BD30;
    }
    // 0x8007BC94: nop

    // 0x8007BC98: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BC9C: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BCA0: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8007BCA4: sw          $t1, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r9;
    // 0x8007BCA8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BCAC: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007BCB0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8007BCB4: sh          $t4, 0x116($t5)
    MEM_H(0X116, ctx->r13) = ctx->r12;
    // 0x8007BCB8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BCBC: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007BCC0: nop

    // 0x8007BCC4: sh          $zero, 0x114($t6)
    MEM_H(0X114, ctx->r14) = 0;
    // 0x8007BCC8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BCCC: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BCD0: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8007BCD4: sw          $t7, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r15;
    // 0x8007BCD8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BCDC: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BCE0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8007BCE4: sh          $t9, 0x118($t8)
    MEM_H(0X118, ctx->r24) = ctx->r25;
    // 0x8007BCE8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BCEC: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007BCF0: nop

    // 0x8007BCF4: sh          $zero, 0x11A($t0)
    MEM_H(0X11A, ctx->r8) = 0;
    // 0x8007BCF8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BCFC: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007BD00: nop

    // 0x8007BD04: sh          $zero, 0x11C($t1)
    MEM_H(0X11C, ctx->r9) = 0;
    // 0x8007BD08: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007BD0C: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007BD10: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8007BD14: sh          $t2, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r10;
    // 0x8007BD18: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BD1C: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007BD20: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007BD24: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8007BD28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BD2C: sh          $t6, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r14;
L_8007BD30:
    // 0x8007BD30: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BD34: addiu       $t7, $t7, 0x70F0
    ctx->r15 = ADD32(ctx->r15, 0X70F0);
    // 0x8007BD38: addiu       $a0, $t7, 0x20
    ctx->r4 = ADD32(ctx->r15, 0X20);
    // 0x8007BD3C: addiu       $a1, $t7, 0x24
    ctx->r5 = ADD32(ctx->r15, 0X24);
    // 0x8007BD40: addiu       $a2, $t7, 0x28
    ctx->r6 = ADD32(ctx->r15, 0X28);
    // 0x8007BD44: addiu       $a3, $t7, 0x2C
    ctx->r7 = ADD32(ctx->r15, 0X2C);
    // 0x8007BD48: jal         0x8007B12C
    // 0x8007BD4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007B12C(rdram, ctx);
        goto after_4;
    // 0x8007BD4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8007BD50: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BD54: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BD58: nop

    // 0x8007BD5C: lh          $t9, 0x11E($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X11E);
    // 0x8007BD60: nop

    // 0x8007BD64: beq         $t9, $zero, L_8007BD7C
    if (ctx->r25 == 0) {
        // 0x8007BD68: nop
    
            goto L_8007BD7C;
    }
    // 0x8007BD68: nop

    // 0x8007BD6C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BD70: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BD74: b           L_8007BD8C
    // 0x8007BD78: sh          $zero, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = 0;
        goto L_8007BD8C;
    // 0x8007BD78: sh          $zero, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = 0;
L_8007BD7C:
    // 0x8007BD7C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BD80: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007BD84: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x8007BD88: sh          $t0, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r8;
L_8007BD8C:
    // 0x8007BD8C: b           L_8007C1B4
    // 0x8007BD90: nop

        goto L_8007C1B4;
    // 0x8007BD90: nop

L_8007BD94:
    // 0x8007BD94: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BD98: addiu       $t2, $t2, 0x70F0
    ctx->r10 = ADD32(ctx->r10, 0X70F0);
    // 0x8007BD9C: addiu       $a0, $t2, 0x20
    ctx->r4 = ADD32(ctx->r10, 0X20);
    // 0x8007BDA0: addiu       $a1, $t2, 0x24
    ctx->r5 = ADD32(ctx->r10, 0X24);
    // 0x8007BDA4: addiu       $a2, $t2, 0x28
    ctx->r6 = ADD32(ctx->r10, 0X28);
    // 0x8007BDA8: addiu       $a3, $t2, 0x2C
    ctx->r7 = ADD32(ctx->r10, 0X2C);
    // 0x8007BDAC: jal         0x8007B12C
    // 0x8007BDB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007B12C(rdram, ctx);
        goto after_5;
    // 0x8007BDB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8007BDB4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007BDB8: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007BDBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007BDC0: lh          $t5, 0x120($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X120);
    // 0x8007BDC4: lh          $t6, 0x11E($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X11E);
    // 0x8007BDC8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8007BDCC: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007BDD0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007BDD4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8007BDD8: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007BDDC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007BDE0: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8007BDE4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007BDE8: nop

    // 0x8007BDEC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8007BDF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007BDF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007BDF8: nop

    // 0x8007BDFC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007BE00: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8007BE04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007BE08: sh          $t3, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r11;
    // 0x8007BE0C: nop

    // 0x8007BE10: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BE14: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BE18: nop

    // 0x8007BE1C: lh          $t8, 0x11E($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X11E);
    // 0x8007BE20: nop

    // 0x8007BE24: bgez        $t8, L_8007BE4C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007BE28: nop
    
            goto L_8007BE4C;
    }
    // 0x8007BE28: nop

    // 0x8007BE2C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007BE30: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007BE34: nop

    // 0x8007BE38: sh          $zero, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = 0;
    // 0x8007BE3C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BE40: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BE44: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8007BE48: sh          $t1, 0x120($t2)
    MEM_H(0X120, ctx->r10) = ctx->r9;
L_8007BE4C:
    // 0x8007BE4C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007BE50: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007BE54: nop

    // 0x8007BE58: lh          $t6, 0x11E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X11E);
    // 0x8007BE5C: nop

    // 0x8007BE60: slti        $at, $t6, 0xE1
    ctx->r1 = SIGNED(ctx->r14) < 0XE1 ? 1 : 0;
    // 0x8007BE64: bne         $at, $zero, L_8007BE8C
    if (ctx->r1 != 0) {
        // 0x8007BE68: nop
    
            goto L_8007BE8C;
    }
    // 0x8007BE68: nop

    // 0x8007BE6C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BE70: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BE74: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x8007BE78: sh          $t7, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = ctx->r15;
    // 0x8007BE7C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007BE80: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007BE84: addiu       $t4, $zero, -0xA
    ctx->r12 = ADD32(0, -0XA);
    // 0x8007BE88: sh          $t4, 0x120($t9)
    MEM_H(0X120, ctx->r25) = ctx->r12;
L_8007BE8C:
    // 0x8007BE8C: b           L_8007C1B4
    // 0x8007BE90: nop

        goto L_8007C1B4;
    // 0x8007BE90: nop

L_8007BE94:
    // 0x8007BE94: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BE98: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007BE9C: nop

    // 0x8007BEA0: andi        $t0, $t8, 0x40
    ctx->r8 = ctx->r24 & 0X40;
    // 0x8007BEA4: beq         $t0, $zero, L_8007BF58
    if (ctx->r8 == 0) {
        // 0x8007BEA8: nop
    
            goto L_8007BF58;
    }
    // 0x8007BEA8: nop

    // 0x8007BEAC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BEB0: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BEB4: addiu       $t1, $zero, 0x48
    ctx->r9 = ADD32(0, 0X48);
    // 0x8007BEB8: sw          $t1, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r9;
    // 0x8007BEBC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BEC0: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007BEC4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007BEC8: sh          $t5, 0x116($t6)
    MEM_H(0X116, ctx->r14) = ctx->r13;
    // 0x8007BECC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BED0: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007BED4: nop

    // 0x8007BED8: sh          $zero, 0x114($t7)
    MEM_H(0X114, ctx->r15) = 0;
    // 0x8007BEDC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007BEE0: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007BEE4: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8007BEE8: sw          $t3, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r11;
    // 0x8007BEEC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BEF0: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BEF4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8007BEF8: sh          $t9, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r25;
    // 0x8007BEFC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BF00: lw          $t1, 0x70F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F0);
    // 0x8007BF04: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8007BF08: sh          $t0, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r8;
    // 0x8007BF0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007BF10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007BF14: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007BF18: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007BF1C: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007BF20: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007BF24: lui         $a2, 0x91
    ctx->r6 = S32(0X91 << 16);
    // 0x8007BF28: ori         $a2, $a2, 0x245
    ctx->r6 = ctx->r6 | 0X245;
    // 0x8007BF2C: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x8007BF30: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007BF34: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8007BF38: jal         0x800B1F0C
    // 0x8007BF3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_6;
    // 0x8007BF3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8007BF40: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BF44: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007BF48: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007BF4C: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x8007BF50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007BF54: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
L_8007BF58:
    // 0x8007BF58: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BF5C: addiu       $t6, $t6, 0x70F0
    ctx->r14 = ADD32(ctx->r14, 0X70F0);
    // 0x8007BF60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007BF64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007BF68: addiu       $a0, $t6, 0x20
    ctx->r4 = ADD32(ctx->r14, 0X20);
    // 0x8007BF6C: addiu       $a1, $t6, 0x24
    ctx->r5 = ADD32(ctx->r14, 0X24);
    // 0x8007BF70: addiu       $a2, $t6, 0x28
    ctx->r6 = ADD32(ctx->r14, 0X28);
    // 0x8007BF74: jal         0x8007B12C
    // 0x8007BF78: addiu       $a3, $t6, 0x2C
    ctx->r7 = ADD32(ctx->r14, 0X2C);
    func_8007B12C(rdram, ctx);
        goto after_7;
    // 0x8007BF78: addiu       $a3, $t6, 0x2C
    ctx->r7 = ADD32(ctx->r14, 0X2C);
    after_7:
    // 0x8007BF7C: b           L_8007C1B4
    // 0x8007BF80: nop

        goto L_8007C1B4;
    // 0x8007BF80: nop

L_8007BF84:
    // 0x8007BF84: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BF88: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007BF8C: nop

    // 0x8007BF90: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x8007BF94: beq         $t4, $zero, L_8007C078
    if (ctx->r12 == 0) {
        // 0x8007BF98: nop
    
            goto L_8007C078;
    }
    // 0x8007BF98: nop

    // 0x8007BF9C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007BFA0: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007BFA4: addiu       $t9, $zero, 0x48
    ctx->r25 = ADD32(0, 0X48);
    // 0x8007BFA8: sw          $t9, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r25;
    // 0x8007BFAC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007BFB0: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007BFB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007BFB8: sh          $t0, 0x116($t1)
    MEM_H(0X116, ctx->r9) = ctx->r8;
    // 0x8007BFBC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007BFC0: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007BFC4: nop

    // 0x8007BFC8: sh          $zero, 0x114($t2)
    MEM_H(0X114, ctx->r10) = 0;
    // 0x8007BFCC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007BFD0: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007BFD4: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x8007BFD8: sw          $t5, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r13;
    // 0x8007BFDC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007BFE0: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007BFE4: nop

    // 0x8007BFE8: sh          $zero, 0x118($t7)
    MEM_H(0X118, ctx->r15) = 0;
    // 0x8007BFEC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007BFF0: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007BFF4: nop

    // 0x8007BFF8: sh          $zero, 0x11A($t3)
    MEM_H(0X11A, ctx->r11) = 0;
    // 0x8007BFFC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007C000: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007C004: nop

    // 0x8007C008: sh          $zero, 0x11C($t4)
    MEM_H(0X11C, ctx->r12) = 0;
    // 0x8007C00C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C010: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007C014: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8007C018: sh          $t9, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r25;
    // 0x8007C01C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C020: lw          $t1, 0x70F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F0);
    // 0x8007C024: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8007C028: sh          $t0, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r8;
    // 0x8007C02C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007C030: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007C034: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C038: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007C03C: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007C040: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C044: lui         $a2, 0xAD
    ctx->r6 = S32(0XAD << 16);
    // 0x8007C048: ori         $a2, $a2, 0x245
    ctx->r6 = ctx->r6 | 0X245;
    // 0x8007C04C: addiu       $a3, $zero, 0x54
    ctx->r7 = ADD32(0, 0X54);
    // 0x8007C050: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007C054: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8007C058: jal         0x800B1F0C
    // 0x8007C05C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_8;
    // 0x8007C05C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x8007C060: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C064: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x8007C068: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007C06C: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x8007C070: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C074: sh          $t5, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r13;
L_8007C078:
    // 0x8007C078: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C07C: addiu       $t6, $t6, 0x70F0
    ctx->r14 = ADD32(ctx->r14, 0X70F0);
    // 0x8007C080: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8007C084: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007C088: addiu       $a0, $t6, 0x20
    ctx->r4 = ADD32(ctx->r14, 0X20);
    // 0x8007C08C: addiu       $a1, $t6, 0x24
    ctx->r5 = ADD32(ctx->r14, 0X24);
    // 0x8007C090: addiu       $a2, $t6, 0x28
    ctx->r6 = ADD32(ctx->r14, 0X28);
    // 0x8007C094: jal         0x8007B12C
    // 0x8007C098: addiu       $a3, $t6, 0x2C
    ctx->r7 = ADD32(ctx->r14, 0X2C);
    func_8007B12C(rdram, ctx);
        goto after_9;
    // 0x8007C098: addiu       $a3, $t6, 0x2C
    ctx->r7 = ADD32(ctx->r14, 0X2C);
    after_9:
    // 0x8007C09C: b           L_8007C1B4
    // 0x8007C0A0: nop

        goto L_8007C1B4;
    // 0x8007C0A0: nop

L_8007C0A4:
    // 0x8007C0A4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C0A8: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007C0AC: nop

    // 0x8007C0B0: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x8007C0B4: beq         $t4, $zero, L_8007C168
    if (ctx->r12 == 0) {
        // 0x8007C0B8: nop
    
            goto L_8007C168;
    }
    // 0x8007C0B8: nop

    // 0x8007C0BC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C0C0: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007C0C4: addiu       $t9, $zero, 0x48
    ctx->r25 = ADD32(0, 0X48);
    // 0x8007C0C8: sw          $t9, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r25;
    // 0x8007C0CC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C0D0: lw          $t1, 0x70F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70F4);
    // 0x8007C0D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007C0D8: sh          $t0, 0x116($t1)
    MEM_H(0X116, ctx->r9) = ctx->r8;
    // 0x8007C0DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C0E0: lw          $t2, 0x70F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70F4);
    // 0x8007C0E4: nop

    // 0x8007C0E8: sh          $zero, 0x114($t2)
    MEM_H(0X114, ctx->r10) = 0;
    // 0x8007C0EC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C0F0: lw          $t6, 0x70F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F4);
    // 0x8007C0F4: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x8007C0F8: sw          $t5, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r13;
    // 0x8007C0FC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C100: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007C104: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8007C108: sh          $t7, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r15;
    // 0x8007C10C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007C110: lw          $t9, 0x70F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F0);
    // 0x8007C114: ori         $t4, $zero, 0xFFFF
    ctx->r12 = 0 | 0XFFFF;
    // 0x8007C118: sh          $t4, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r12;
    // 0x8007C11C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007C120: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007C124: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C128: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8007C12C: lw          $a1, 0x70F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X70F0);
    // 0x8007C130: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C134: lui         $a2, 0x92
    ctx->r6 = S32(0X92 << 16);
    // 0x8007C138: ori         $a2, $a2, 0x245
    ctx->r6 = ctx->r6 | 0X245;
    // 0x8007C13C: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x8007C140: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007C144: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8007C148: jal         0x800B1F0C
    // 0x8007C14C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_10;
    // 0x8007C14C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x8007C150: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C154: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007C158: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8007C15C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8007C160: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C164: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
L_8007C168:
    // 0x8007C168: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007C16C: addiu       $t1, $t1, 0x70F0
    ctx->r9 = ADD32(ctx->r9, 0X70F0);
    // 0x8007C170: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007C174: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8007C178: addiu       $a0, $t1, 0x20
    ctx->r4 = ADD32(ctx->r9, 0X20);
    // 0x8007C17C: addiu       $a1, $t1, 0x24
    ctx->r5 = ADD32(ctx->r9, 0X24);
    // 0x8007C180: addiu       $a2, $t1, 0x28
    ctx->r6 = ADD32(ctx->r9, 0X28);
    // 0x8007C184: jal         0x8007B12C
    // 0x8007C188: addiu       $a3, $t1, 0x2C
    ctx->r7 = ADD32(ctx->r9, 0X2C);
    func_8007B12C(rdram, ctx);
        goto after_11;
    // 0x8007C188: addiu       $a3, $t1, 0x2C
    ctx->r7 = ADD32(ctx->r9, 0X2C);
    after_11:
    // 0x8007C18C: b           L_8007C1B4
    // 0x8007C190: nop

        goto L_8007C1B4;
    // 0x8007C190: nop

L_8007C194:
    // 0x8007C194: b           L_8007C1B4
    // 0x8007C198: nop

        goto L_8007C1B4;
    // 0x8007C198: nop

L_8007C19C:
    // 0x8007C19C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007C1A0: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007C1A4: nop

    // 0x8007C1A8: sh          $zero, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = 0;
    // 0x8007C1AC: b           L_8007C1B4
    // 0x8007C1B0: nop

        goto L_8007C1B4;
    // 0x8007C1B0: nop

L_8007C1B4:
    // 0x8007C1B4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007C1B8: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007C1BC: nop

    // 0x8007C1C0: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8007C1C4: beq         $t7, $zero, L_8007C470
    if (ctx->r15 == 0) {
        // 0x8007C1C8: nop
    
            goto L_8007C470;
    }
    // 0x8007C1C8: nop

    // 0x8007C1CC: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8007C1D0: lb          $s0, 0x7108($s0)
    ctx->r16 = MEM_B(ctx->r16, 0X7108);
    // 0x8007C1D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007C1D8: beq         $s0, $at, L_8007C3D8
    if (ctx->r16 == ctx->r1) {
        // 0x8007C1DC: nop
    
            goto L_8007C3D8;
    }
    // 0x8007C1DC: nop

    // 0x8007C1E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C1E4: beq         $s0, $at, L_8007C20C
    if (ctx->r16 == ctx->r1) {
        // 0x8007C1E8: nop
    
            goto L_8007C20C;
    }
    // 0x8007C1E8: nop

    // 0x8007C1EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007C1F0: beq         $s0, $at, L_8007C20C
    if (ctx->r16 == ctx->r1) {
        // 0x8007C1F4: nop
    
            goto L_8007C20C;
    }
    // 0x8007C1F4: nop

    // 0x8007C1F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007C1FC: beq         $s0, $at, L_8007C2DC
    if (ctx->r16 == ctx->r1) {
        // 0x8007C200: nop
    
            goto L_8007C2DC;
    }
    // 0x8007C200: nop

    // 0x8007C204: b           L_8007C3E0
    // 0x8007C208: nop

        goto L_8007C3E0;
    // 0x8007C208: nop

L_8007C20C:
    // 0x8007C20C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C210: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C214: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007C218: lwc1        $f18, 0x7110($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7110);
    // 0x8007C21C: nop

    // 0x8007C220: swc1        $f18, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f18.u32l;
    // 0x8007C224: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C228: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007C22C: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007C230: lwc1        $f4, 0x7114($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7114);
    // 0x8007C234: nop

    // 0x8007C238: swc1        $f4, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f4.u32l;
    // 0x8007C23C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007C240: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C244: lwc1        $f16, 0x7118($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7118);
    // 0x8007C248: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8007C24C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C250: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C254: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C258: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007C25C: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007C260: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8007C264: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007C268: sh          $t8, 0x100($t0)
    MEM_H(0X100, ctx->r8) = ctx->r24;
    // 0x8007C26C: nop

    // 0x8007C270: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8007C274: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C278: lwc1        $f6, 0x711C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X711C);
    // 0x8007C27C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8007C280: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C284: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C288: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007C28C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007C290: lw          $t5, 0x70F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F4);
    // 0x8007C294: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8007C298: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8007C29C: sh          $t2, 0x102($t5)
    MEM_H(0X102, ctx->r13) = ctx->r10;
    // 0x8007C2A0: nop

    // 0x8007C2A4: jal         0x800C1754
    // 0x8007C2A8: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_12;
    // 0x8007C2A8: nop

    after_12:
    // 0x8007C2AC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C2B0: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C2B4: jal         0x8009A14C
    // 0x8007C2B8: nop

    func_8009A14C(rdram, ctx);
        goto after_13;
    // 0x8007C2B8: nop

    after_13:
    // 0x8007C2BC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C2C0: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C2C4: jal         0x800997D8
    // 0x8007C2C8: nop

    func_800997D8(rdram, ctx);
        goto after_14;
    // 0x8007C2C8: nop

    after_14:
    // 0x8007C2CC: jal         0x800C1A28
    // 0x8007C2D0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_15;
    // 0x8007C2D0: nop

    after_15:
    // 0x8007C2D4: b           L_8007C470
    // 0x8007C2D8: nop

        goto L_8007C470;
    // 0x8007C2D8: nop

L_8007C2DC:
    // 0x8007C2DC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007C2E0: lw          $t7, 0x70F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70F4);
    // 0x8007C2E4: addiu       $t6, $zero, 0x7D0
    ctx->r14 = ADD32(0, 0X7D0);
    // 0x8007C2E8: sw          $t6, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->r14;
    // 0x8007C2EC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007C2F0: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007C2F4: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x8007C2F8: lw          $t9, 0x138($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X138);
    // 0x8007C2FC: nop

    // 0x8007C300: sh          $t3, 0x1FE($t9)
    MEM_H(0X1FE, ctx->r25) = ctx->r11;
    // 0x8007C304: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C308: lw          $t0, 0x70F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F4);
    // 0x8007C30C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8007C310: sh          $t8, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r24;
    // 0x8007C314: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8007C318: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C31C: lwc1        $f18, 0x7110($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7110);
    // 0x8007C320: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8007C324: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C328: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C32C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C330: lwc1        $f16, 0x7114($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7114);
    // 0x8007C334: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007C338: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C33C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8007C340: lwc1        $f8, 0x711C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X711C);
    // 0x8007C344: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8007C348: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8007C34C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C350: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8007C354: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C358: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8007C35C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C360: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C364: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C368: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007C36C: lwc1        $f4, 0x7118($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7118);
    // 0x8007C370: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8007C374: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8007C378: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007C37C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8007C380: nop

    // 0x8007C384: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8007C388: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C38C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C390: nop

    // 0x8007C394: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007C398: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8007C39C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8007C3A0: nop

    // 0x8007C3A4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007C3A8: nop

    // 0x8007C3AC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8007C3B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007C3B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007C3B8: nop

    // 0x8007C3BC: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007C3C0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8007C3C4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007C3C8: jal         0x800A39C4
    // 0x8007C3CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800A39C4(rdram, ctx);
        goto after_16;
    // 0x8007C3CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_16:
    // 0x8007C3D0: b           L_8007C470
    // 0x8007C3D4: nop

        goto L_8007C470;
    // 0x8007C3D4: nop

L_8007C3D8:
    // 0x8007C3D8: b           L_8007C470
    // 0x8007C3DC: nop

        goto L_8007C470;
    // 0x8007C3DC: nop

L_8007C3E0:
    // 0x8007C3E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C3E4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007C3E8: lw          $t4, 0x70F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X70F4);
    // 0x8007C3EC: lwc1        $f18, 0x7110($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7110);
    // 0x8007C3F0: nop

    // 0x8007C3F4: swc1        $f18, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f18.u32l;
    // 0x8007C3F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C3FC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007C400: lw          $t3, 0x70F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70F4);
    // 0x8007C404: lwc1        $f4, 0x7114($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7114);
    // 0x8007C408: nop

    // 0x8007C40C: swc1        $f4, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f4.u32l;
    // 0x8007C410: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C414: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007C418: lw          $t9, 0x70F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70F4);
    // 0x8007C41C: lwc1        $f8, 0x7118($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7118);
    // 0x8007C420: nop

    // 0x8007C424: swc1        $f8, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f8.u32l;
    // 0x8007C428: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C42C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007C430: lw          $t8, 0x70F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X70F4);
    // 0x8007C434: lwc1        $f6, 0x711C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X711C);
    // 0x8007C438: nop

    // 0x8007C43C: swc1        $f6, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f6.u32l;
    // 0x8007C440: jal         0x800C1754
    // 0x8007C444: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_17;
    // 0x8007C444: nop

    after_17:
    // 0x8007C448: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C44C: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C450: jal         0x8009A14C
    // 0x8007C454: nop

    func_8009A14C(rdram, ctx);
        goto after_18;
    // 0x8007C454: nop

    after_18:
    // 0x8007C458: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8007C45C: lw          $a0, 0x70F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70F4);
    // 0x8007C460: jal         0x800997D8
    // 0x8007C464: nop

    func_800997D8(rdram, ctx);
        goto after_19;
    // 0x8007C464: nop

    after_19:
    // 0x8007C468: jal         0x800C1A28
    // 0x8007C46C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_20;
    // 0x8007C46C: nop

    after_20:
L_8007C470:
    // 0x8007C470: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007C474: lh          $t0, 0x713A($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X713A);
    // 0x8007C478: nop

    // 0x8007C47C: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8007C480: beq         $t1, $zero, L_8007C490
    if (ctx->r9 == 0) {
        // 0x8007C484: nop
    
            goto L_8007C490;
    }
    // 0x8007C484: nop

    // 0x8007C488: b           L_8007C53C
    // 0x8007C48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007C48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C490:
    // 0x8007C490: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C494: lwc1        $f16, 0x710C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X710C);
    // 0x8007C498: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007C49C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C4A0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8007C4A4: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8007C4A8: nop

    // 0x8007C4AC: bc1f        L_8007C52C
    if (!c1cs) {
        // 0x8007C4B0: nop
    
            goto L_8007C52C;
    }
    // 0x8007C4B0: nop

    // 0x8007C4B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C4B8: lwc1        $f4, 0x710C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X710C);
    // 0x8007C4BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007C4C0: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8007C4C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C4C8: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8007C4CC: swc1        $f6, 0x710C($at)
    MEM_W(0X710C, ctx->r1) = ctx->f6.u32l;
    // 0x8007C4D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007C4D4: lwc1        $f16, 0x710C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X710C);
    // 0x8007C4D8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007C4DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C4E0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8007C4E4: c.le.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d <= ctx->f18.d;
    // 0x8007C4E8: nop

    // 0x8007C4EC: bc1f        L_8007C524
    if (!c1cs) {
        // 0x8007C4F0: nop
    
            goto L_8007C524;
    }
    // 0x8007C4F0: nop

    // 0x8007C4F4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007C4F8: lb          $t2, 0x7108($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7108);
    // 0x8007C4FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007C500: beq         $t2, $at, L_8007C514
    if (ctx->r10 == ctx->r1) {
        // 0x8007C504: nop
    
            goto L_8007C514;
    }
    // 0x8007C504: nop

    // 0x8007C508: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007C50C: bne         $t2, $at, L_8007C51C
    if (ctx->r10 != ctx->r1) {
        // 0x8007C510: nop
    
            goto L_8007C51C;
    }
    // 0x8007C510: nop

L_8007C514:
    // 0x8007C514: jal         0x8007B710
    // 0x8007C518: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007B710(rdram, ctx);
        goto after_21;
    // 0x8007C518: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
L_8007C51C:
    // 0x8007C51C: b           L_8007C53C
    // 0x8007C520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007C520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C524:
    // 0x8007C524: b           L_8007C53C
    // 0x8007C528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007C53C;
    // 0x8007C528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007C52C:
    // 0x8007C52C: b           L_8007C53C
    // 0x8007C530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C53C;
    // 0x8007C530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C534: b           L_8007C53C
    // 0x8007C538: nop

        goto L_8007C53C;
    // 0x8007C538: nop

L_8007C53C:
    // 0x8007C53C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C540: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007C544: jr          $ra
    // 0x8007C548: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007C548: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80093B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093B30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80093B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093B38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80093B3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80093B40: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80093B44:
    // 0x80093B44: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80093B48: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x80093B4C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80093B50: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80093B54: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093B58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80093B5C: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093B60: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80093B64: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80093B68: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093B6C: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80093B70: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80093B74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80093B78: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x80093B7C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80093B80: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80093B84: lw          $t9, 0x6C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C14);
    // 0x80093B88: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80093B8C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80093B90: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80093B94: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80093B98: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80093B9C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80093BA0: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80093BA4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80093BA8: nop

    // 0x80093BAC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80093BB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80093BB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80093BB8: nop

    // 0x80093BBC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80093BC0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80093BC4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80093BC8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80093BCC: nop

    // 0x80093BD0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80093BD4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80093BD8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80093BDC: lw          $t7, -0x788($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X788);
    // 0x80093BE0: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80093BE4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80093BE8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80093BEC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80093BF0: lbu         $t9, -0x400($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X400);
    // 0x80093BF4: nop

    // 0x80093BF8: sb          $t9, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r25;
    // 0x80093BFC: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093C00: nop

    // 0x80093C04: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80093C08: beq         $t1, $zero, L_80093C38
    if (ctx->r9 == 0) {
        // 0x80093C0C: nop
    
            goto L_80093C38;
    }
    // 0x80093C0C: nop

    // 0x80093C10: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093C14: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093C18: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093C1C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093C20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093C24: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093C28: jal         0x80090784
    // 0x80093C2C: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x80093C2C: nop

    after_0:
    // 0x80093C30: b           L_80093C58
    // 0x80093C34: nop

        goto L_80093C58;
    // 0x80093C34: nop

L_80093C38:
    // 0x80093C38: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093C3C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093C40: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093C44: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093C48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093C4C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093C50: jal         0x80090784
    // 0x80093C54: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80093C54: nop

    after_1:
L_80093C58:
    // 0x80093C58: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093C5C: nop

    // 0x80093C60: andi        $t4, $t2, 0x40
    ctx->r12 = ctx->r10 & 0X40;
    // 0x80093C64: beq         $t4, $zero, L_80093C94
    if (ctx->r12 == 0) {
        // 0x80093C68: nop
    
            goto L_80093C94;
    }
    // 0x80093C68: nop

    // 0x80093C6C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093C70: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093C74: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093C78: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093C7C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093C80: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093C84: jal         0x80090784
    // 0x80093C88: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x80093C88: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x80093C8C: b           L_80093CB4
    // 0x80093C90: nop

        goto L_80093CB4;
    // 0x80093C90: nop

L_80093C94:
    // 0x80093C94: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093C98: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093C9C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093CA0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093CA4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093CA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093CAC: jal         0x80090784
    // 0x80093CB0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x80093CB0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_80093CB4:
    // 0x80093CB4: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093CB8: nop

    // 0x80093CBC: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x80093CC0: beq         $t5, $zero, L_80093CF0
    if (ctx->r13 == 0) {
        // 0x80093CC4: nop
    
            goto L_80093CF0;
    }
    // 0x80093CC4: nop

    // 0x80093CC8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093CCC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093CD0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093CD4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093CD8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093CDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093CE0: jal         0x80090784
    // 0x80093CE4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x80093CE4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x80093CE8: b           L_80093D10
    // 0x80093CEC: nop

        goto L_80093D10;
    // 0x80093CEC: nop

L_80093CF0:
    // 0x80093CF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093CF4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093CF8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093CFC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093D00: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093D04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093D08: jal         0x80090784
    // 0x80093D0C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x80093D0C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80093D10:
    // 0x80093D10: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093D14: nop

    // 0x80093D18: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80093D1C: beq         $t7, $zero, L_80093D4C
    if (ctx->r15 == 0) {
        // 0x80093D20: nop
    
            goto L_80093D4C;
    }
    // 0x80093D20: nop

    // 0x80093D24: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093D28: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093D2C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093D30: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093D34: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093D38: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093D3C: jal         0x80090784
    // 0x80093D40: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80093D40: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80093D44: b           L_80093D6C
    // 0x80093D48: nop

        goto L_80093D6C;
    // 0x80093D48: nop

L_80093D4C:
    // 0x80093D4C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093D50: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093D54: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093D58: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093D5C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093D60: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093D64: jal         0x80090784
    // 0x80093D68: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x80093D68: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_80093D6C:
    // 0x80093D6C: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093D70: nop

    // 0x80093D74: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80093D78: beq         $t9, $zero, L_80093DA8
    if (ctx->r25 == 0) {
        // 0x80093D7C: nop
    
            goto L_80093DA8;
    }
    // 0x80093D7C: nop

    // 0x80093D80: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093D84: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093D88: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093D8C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093D90: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093D94: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093D98: jal         0x80090784
    // 0x80093D9C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x80093D9C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x80093DA0: b           L_80093DC8
    // 0x80093DA4: nop

        goto L_80093DC8;
    // 0x80093DA4: nop

L_80093DA8:
    // 0x80093DA8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093DAC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093DB0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093DB4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093DB8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093DBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093DC0: jal         0x80090784
    // 0x80093DC4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x80093DC4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_80093DC8:
    // 0x80093DC8: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093DCC: nop

    // 0x80093DD0: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80093DD4: beq         $t1, $zero, L_80093E04
    if (ctx->r9 == 0) {
        // 0x80093DD8: nop
    
            goto L_80093E04;
    }
    // 0x80093DD8: nop

    // 0x80093DDC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093DE0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093DE4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093DE8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093DEC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093DF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093DF4: jal         0x80090784
    // 0x80093DF8: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x80093DF8: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x80093DFC: b           L_80093E24
    // 0x80093E00: nop

        goto L_80093E24;
    // 0x80093E00: nop

L_80093E04:
    // 0x80093E04: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093E08: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093E0C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093E10: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093E14: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093E18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093E1C: jal         0x80090784
    // 0x80093E20: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80093E20: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80093E24:
    // 0x80093E24: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093E28: nop

    // 0x80093E2C: andi        $t4, $t2, 0x2
    ctx->r12 = ctx->r10 & 0X2;
    // 0x80093E30: beq         $t4, $zero, L_80093E60
    if (ctx->r12 == 0) {
        // 0x80093E34: nop
    
            goto L_80093E60;
    }
    // 0x80093E34: nop

    // 0x80093E38: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093E3C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093E40: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093E44: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093E48: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093E4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093E50: jal         0x80090784
    // 0x80093E54: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80093E54: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x80093E58: b           L_80093E80
    // 0x80093E5C: nop

        goto L_80093E80;
    // 0x80093E5C: nop

L_80093E60:
    // 0x80093E60: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093E64: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093E68: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093E6C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093E70: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093E74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093E78: jal         0x80090784
    // 0x80093E7C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x80093E7C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_80093E80:
    // 0x80093E80: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093E84: nop

    // 0x80093E88: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x80093E8C: beq         $t5, $zero, L_80093EBC
    if (ctx->r13 == 0) {
        // 0x80093E90: nop
    
            goto L_80093EBC;
    }
    // 0x80093E90: nop

    // 0x80093E94: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093E98: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093E9C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093EA0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093EA4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093EA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093EAC: jal         0x80090784
    // 0x80093EB0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x80093EB0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x80093EB4: b           L_80093EDC
    // 0x80093EB8: nop

        goto L_80093EDC;
    // 0x80093EB8: nop

L_80093EBC:
    // 0x80093EBC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093EC0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093EC4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093EC8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093ECC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093ED0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093ED4: jal         0x80090784
    // 0x80093ED8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x80093ED8: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_80093EDC:
    // 0x80093EDC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80093EE0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80093EE4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80093EE8: lw          $t1, -0x788($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X788);
    // 0x80093EEC: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80093EF0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80093EF4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80093EF8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80093EFC: lbu         $t4, -0x3FF($t2)
    ctx->r12 = MEM_BU(ctx->r10, -0X3FF);
    // 0x80093F00: nop

    // 0x80093F04: sb          $t4, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r12;
    // 0x80093F08: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093F0C: nop

    // 0x80093F10: andi        $t5, $t3, 0x80
    ctx->r13 = ctx->r11 & 0X80;
    // 0x80093F14: beq         $t5, $zero, L_80093F44
    if (ctx->r13 == 0) {
        // 0x80093F18: nop
    
            goto L_80093F44;
    }
    // 0x80093F18: nop

    // 0x80093F1C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093F20: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093F24: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093F28: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093F2C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093F30: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093F34: jal         0x80090784
    // 0x80093F38: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_16;
    // 0x80093F38: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_16:
    // 0x80093F3C: b           L_80093F64
    // 0x80093F40: nop

        goto L_80093F64;
    // 0x80093F40: nop

L_80093F44:
    // 0x80093F44: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093F48: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093F4C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093F50: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093F54: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093F58: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093F5C: jal         0x80090784
    // 0x80093F60: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_17;
    // 0x80093F60: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_17:
L_80093F64:
    // 0x80093F64: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093F68: nop

    // 0x80093F6C: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80093F70: beq         $t8, $zero, L_80093FA0
    if (ctx->r24 == 0) {
        // 0x80093F74: nop
    
            goto L_80093FA0;
    }
    // 0x80093F74: nop

    // 0x80093F78: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093F7C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093F80: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093F84: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093F88: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093F8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093F90: jal         0x80090784
    // 0x80093F94: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_18;
    // 0x80093F94: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_18:
    // 0x80093F98: b           L_80093FC0
    // 0x80093F9C: nop

        goto L_80093FC0;
    // 0x80093F9C: nop

L_80093FA0:
    // 0x80093FA0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093FA4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093FA8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093FAC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093FB0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093FB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093FB8: jal         0x80090784
    // 0x80093FBC: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_19;
    // 0x80093FBC: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_19:
L_80093FC0:
    // 0x80093FC0: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x80093FC4: nop

    // 0x80093FC8: andi        $t9, $t7, 0x20
    ctx->r25 = ctx->r15 & 0X20;
    // 0x80093FCC: beq         $t9, $zero, L_80093FFC
    if (ctx->r25 == 0) {
        // 0x80093FD0: nop
    
            goto L_80093FFC;
    }
    // 0x80093FD0: nop

    // 0x80093FD4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80093FD8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093FDC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093FE0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093FE4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093FE8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80093FEC: jal         0x80090784
    // 0x80093FF0: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_20;
    // 0x80093FF0: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_20:
    // 0x80093FF4: b           L_8009401C
    // 0x80093FF8: nop

        goto L_8009401C;
    // 0x80093FF8: nop

L_80093FFC:
    // 0x80093FFC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094000: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094004: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094008: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009400C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094010: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094014: jal         0x80090784
    // 0x80094018: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_21;
    // 0x80094018: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_21:
L_8009401C:
    // 0x8009401C: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80094020: nop

    // 0x80094024: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80094028: beq         $t1, $zero, L_80094058
    if (ctx->r9 == 0) {
        // 0x8009402C: nop
    
            goto L_80094058;
    }
    // 0x8009402C: nop

    // 0x80094030: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094034: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094038: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009403C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094040: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094044: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094048: jal         0x80090784
    // 0x8009404C: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_22;
    // 0x8009404C: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_22:
    // 0x80094050: b           L_80094078
    // 0x80094054: nop

        goto L_80094078;
    // 0x80094054: nop

L_80094058:
    // 0x80094058: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009405C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094060: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094064: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094068: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009406C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094070: jal         0x80090784
    // 0x80094074: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_23;
    // 0x80094074: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_23:
L_80094078:
    // 0x80094078: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8009407C: nop

    // 0x80094080: andi        $t4, $t2, 0x8
    ctx->r12 = ctx->r10 & 0X8;
    // 0x80094084: beq         $t4, $zero, L_800940B4
    if (ctx->r12 == 0) {
        // 0x80094088: nop
    
            goto L_800940B4;
    }
    // 0x80094088: nop

    // 0x8009408C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094090: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094094: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094098: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009409C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800940A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800940A4: jal         0x80090784
    // 0x800940A8: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    func_80090784(rdram, ctx);
        goto after_24;
    // 0x800940A8: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    after_24:
    // 0x800940AC: b           L_800940D4
    // 0x800940B0: nop

        goto L_800940D4;
    // 0x800940B0: nop

L_800940B4:
    // 0x800940B4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800940B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800940BC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800940C0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800940C4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800940C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800940CC: jal         0x80090784
    // 0x800940D0: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    func_80090784(rdram, ctx);
        goto after_25;
    // 0x800940D0: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    after_25:
L_800940D4:
    // 0x800940D4: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x800940D8: nop

    // 0x800940DC: andi        $t5, $t3, 0x4
    ctx->r13 = ctx->r11 & 0X4;
    // 0x800940E0: beq         $t5, $zero, L_80094110
    if (ctx->r13 == 0) {
        // 0x800940E4: nop
    
            goto L_80094110;
    }
    // 0x800940E4: nop

    // 0x800940E8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800940EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800940F0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800940F4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800940F8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800940FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094100: jal         0x80090784
    // 0x80094104: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    func_80090784(rdram, ctx);
        goto after_26;
    // 0x80094104: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    after_26:
    // 0x80094108: b           L_80094130
    // 0x8009410C: nop

        goto L_80094130;
    // 0x8009410C: nop

L_80094110:
    // 0x80094110: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094114: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094118: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009411C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094120: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094124: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094128: jal         0x80090784
    // 0x8009412C: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    func_80090784(rdram, ctx);
        goto after_27;
    // 0x8009412C: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    after_27:
L_80094130:
    // 0x80094130: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80094134: nop

    // 0x80094138: andi        $t8, $t6, 0x2
    ctx->r24 = ctx->r14 & 0X2;
    // 0x8009413C: beq         $t8, $zero, L_8009416C
    if (ctx->r24 == 0) {
        // 0x80094140: nop
    
            goto L_8009416C;
    }
    // 0x80094140: nop

    // 0x80094144: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094148: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009414C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094150: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80094154: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80094158: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009415C: jal         0x80090784
    // 0x80094160: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    func_80090784(rdram, ctx);
        goto after_28;
    // 0x80094160: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    after_28:
    // 0x80094164: b           L_8009418C
    // 0x80094168: nop

        goto L_8009418C;
    // 0x80094168: nop

L_8009416C:
    // 0x8009416C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80094170: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80094174: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80094178: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009417C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80094180: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80094184: jal         0x80090784
    // 0x80094188: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    func_80090784(rdram, ctx);
        goto after_29;
    // 0x80094188: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    after_29:
L_8009418C:
    // 0x8009418C: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x80094190: nop

    // 0x80094194: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80094198: beq         $t9, $zero, L_800941C8
    if (ctx->r25 == 0) {
        // 0x8009419C: nop
    
            goto L_800941C8;
    }
    // 0x8009419C: nop

    // 0x800941A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800941A4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800941A8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800941AC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800941B0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800941B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800941B8: jal         0x80090784
    // 0x800941BC: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    func_80090784(rdram, ctx);
        goto after_30;
    // 0x800941BC: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    after_30:
    // 0x800941C0: b           L_800941E8
    // 0x800941C4: nop

        goto L_800941E8;
    // 0x800941C4: nop

L_800941C8:
    // 0x800941C8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800941CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800941D0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800941D4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800941D8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800941DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800941E0: jal         0x80090784
    // 0x800941E4: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    func_80090784(rdram, ctx);
        goto after_31;
    // 0x800941E4: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    after_31:
L_800941E8:
    // 0x800941E8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800941EC: nop

    // 0x800941F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800941F4: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x800941F8: bne         $at, $zero, L_80093B44
    if (ctx->r1 != 0) {
        // 0x800941FC: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_80093B44;
    }
    // 0x800941FC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80094200: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80094204: lw          $t2, 0x6B98($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6B98);
    // 0x80094208: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8009420C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80094210: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80094214: sw          $t3, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r11;
    // 0x80094218: b           L_80094220
    // 0x8009421C: nop

        goto L_80094220;
    // 0x8009421C: nop

L_80094220:
    // 0x80094220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094224: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80094228: jr          $ra
    // 0x8009422C: nop

    return;
    // 0x8009422C: nop

;}
RECOMP_FUNC void TempHeap_Free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D390: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000D394: addiu       $t6, $a0, -0x10
    ctx->r14 = ADD32(ctx->r4, -0X10);
    // 0x8000D398: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8000D39C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8000D3A0: nop

    // 0x8000D3A4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000D3A8: nop

    // 0x8000D3AC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000D3B0: bne         $t9, $zero, L_8000D3C0
    if (ctx->r25 != 0) {
        // 0x8000D3B4: nop
    
            goto L_8000D3C0;
    }
    // 0x8000D3B4: nop

    // 0x8000D3B8: b           L_8000D518
    // 0x8000D3BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D518;
    // 0x8000D3BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D3C0:
    // 0x8000D3C0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D3C4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000D3C8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000D3CC: nop

    // 0x8000D3D0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8000D3D4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8000D3D8: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D3DC: nop

    // 0x8000D3E0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8000D3E4: nop

    // 0x8000D3E8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8000D3EC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000D3F0: lw          $t6, -0x5B0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B0C);
    // 0x8000D3F4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8000D3F8: nop

    // 0x8000D3FC: beq         $t5, $t6, L_8000D46C
    if (ctx->r13 == ctx->r14) {
        // 0x8000D400: nop
    
            goto L_8000D46C;
    }
    // 0x8000D400: nop

    // 0x8000D404: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x8000D408: nop

    // 0x8000D40C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8000D410: bne         $t8, $zero, L_8000D46C
    if (ctx->r24 != 0) {
        // 0x8000D414: nop
    
            goto L_8000D46C;
    }
    // 0x8000D414: nop

    // 0x8000D418: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8000D41C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8000D420: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8000D424: nop

    // 0x8000D428: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8000D42C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D430: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8000D434: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x8000D438: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x8000D43C: nop

    // 0x8000D440: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8000D444: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
    // 0x8000D448: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8000D44C: nop

    // 0x8000D450: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8000D454: nop

    // 0x8000D458: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8000D45C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8000D460: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8000D464: nop

    // 0x8000D468: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_8000D46C:
    // 0x8000D46C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8000D470: nop

    // 0x8000D474: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8000D478: nop

    // 0x8000D47C: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x8000D480: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000D484: lw          $t6, -0x5B10($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B10);
    // 0x8000D488: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D48C: nop

    // 0x8000D490: beq         $t3, $t6, L_8000D508
    if (ctx->r11 == ctx->r14) {
        // 0x8000D494: nop
    
            goto L_8000D508;
    }
    // 0x8000D494: nop

    // 0x8000D498: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8000D49C: nop

    // 0x8000D4A0: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x8000D4A4: nop

    // 0x8000D4A8: andi        $t7, $t0, 0x1
    ctx->r15 = ctx->r8 & 0X1;
    // 0x8000D4AC: bne         $t7, $zero, L_8000D508
    if (ctx->r15 != 0) {
        // 0x8000D4B0: nop
    
            goto L_8000D508;
    }
    // 0x8000D4B0: nop

    // 0x8000D4B4: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8000D4B8: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8000D4BC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000D4C0: nop

    // 0x8000D4C4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8000D4C8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8000D4CC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D4D0: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8000D4D4: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x8000D4D8: nop

    // 0x8000D4DC: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8000D4E0: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x8000D4E4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D4E8: nop

    // 0x8000D4EC: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8000D4F0: nop

    // 0x8000D4F4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8000D4F8: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8000D4FC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8000D500: nop

    // 0x8000D504: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_8000D508:
    // 0x8000D508: b           L_8000D518
    // 0x8000D50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D518;
    // 0x8000D50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D510: b           L_8000D518
    // 0x8000D514: nop

        goto L_8000D518;
    // 0x8000D514: nop

L_8000D518:
    // 0x8000D518: jr          $ra
    // 0x8000D51C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000D51C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80058824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005882C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80058830: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80058834: nop

    // 0x80058838: beq         $t6, $zero, L_80058B34
    if (ctx->r14 == 0) {
        // 0x8005883C: nop
    
            goto L_80058B34;
    }
    // 0x8005883C: nop

    // 0x80058840: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80058844: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80058848: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005884C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80058850: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80058854: bne         $t0, $zero, L_80058864
    if (ctx->r8 != 0) {
        // 0x80058858: and         $t1, $t9, $at
        ctx->r9 = ctx->r25 & ctx->r1;
            goto L_80058864;
    }
    // 0x80058858: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005885C: beq         $t1, $zero, L_80058B34
    if (ctx->r9 == 0) {
        // 0x80058860: nop
    
            goto L_80058B34;
    }
    // 0x80058860: nop

L_80058864:
    // 0x80058864: lh          $t7, 0x4A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4A);
    // 0x80058868: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x8005886C: andi        $t2, $t7, 0x1FFF
    ctx->r10 = ctx->r15 & 0X1FFF;
    // 0x80058870: bne         $t2, $at, L_80058B34
    if (ctx->r10 != ctx->r1) {
        // 0x80058874: nop
    
            goto L_80058B34;
    }
    // 0x80058874: nop

    // 0x80058878: lw          $t3, 0x5C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X5C);
    // 0x8005887C: nop

    // 0x80058880: beq         $t3, $zero, L_80058B34
    if (ctx->r11 == 0) {
        // 0x80058884: nop
    
            goto L_80058B34;
    }
    // 0x80058884: nop

    // 0x80058888: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8005888C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80058890: bne         $t4, $at, L_80058B34
    if (ctx->r12 != ctx->r1) {
        // 0x80058894: nop
    
            goto L_80058B34;
    }
    // 0x80058894: nop

    // 0x80058898: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005889C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800588A0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800588A4: lw          $t8, 0x50($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X50);
    // 0x800588A8: nop

    // 0x800588AC: lbu         $t9, 0x30($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X30);
    // 0x800588B0: nop

    // 0x800588B4: bne         $t9, $at, L_80058B34
    if (ctx->r25 != ctx->r1) {
        // 0x800588B8: nop
    
            goto L_80058B34;
    }
    // 0x800588B8: nop

    // 0x800588BC: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x800588C0: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x800588C4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800588C8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800588CC: bne         $t2, $zero, L_80058B34
    if (ctx->r10 != 0) {
        // 0x800588D0: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_80058B34;
    }
    // 0x800588D0: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800588D4: bne         $t3, $zero, L_80058B34
    if (ctx->r11 != 0) {
        // 0x800588D8: nop
    
            goto L_80058B34;
    }
    // 0x800588D8: nop

    // 0x800588DC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800588E0: addiu       $t7, $t7, 0xE80
    ctx->r15 = ADD32(ctx->r15, 0XE80);
    // 0x800588E4: lw          $t6, 0x1C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X1C);
    // 0x800588E8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800588EC: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x800588F0: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x800588F4: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x800588F8: bne         $t8, $zero, L_80058B34
    if (ctx->r24 != 0) {
        // 0x800588FC: and         $t9, $t5, $at
        ctx->r25 = ctx->r13 & ctx->r1;
            goto L_80058B34;
    }
    // 0x800588FC: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80058900: bne         $t9, $zero, L_80058B34
    if (ctx->r25 != 0) {
        // 0x80058904: nop
    
            goto L_80058B34;
    }
    // 0x80058904: nop

    // 0x80058908: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005890C: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80058910: nop

    // 0x80058914: lw          $t1, 0x98($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X98);
    // 0x80058918: nop

    // 0x8005891C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80058920: bne         $t2, $zero, L_8005894C
    if (ctx->r10 != 0) {
        // 0x80058924: nop
    
            goto L_8005894C;
    }
    // 0x80058924: nop

    // 0x80058928: jal         0x800B9000
    // 0x8005892C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x8005892C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_0:
    // 0x80058930: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80058934: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80058938: nop

    // 0x8005893C: lw          $t7, 0x98($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X98);
    // 0x80058940: nop

    // 0x80058944: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x80058948: sw          $t6, 0x98($t3)
    MEM_W(0X98, ctx->r11) = ctx->r14;
L_8005894C:
    // 0x8005894C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80058950: addiu       $t4, $t4, 0x2BB0
    ctx->r12 = ADD32(ctx->r12, 0X2BB0);
    // 0x80058954: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80058958: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005895C: nop

    // 0x80058960: beq         $t5, $zero, L_80058B34
    if (ctx->r13 == 0) {
        // 0x80058964: nop
    
            goto L_80058B34;
    }
    // 0x80058964: nop

    // 0x80058968: lbu         $t8, 0x1($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X1);
    // 0x8005896C: nop

    // 0x80058970: beq         $t8, $zero, L_80058B34
    if (ctx->r24 == 0) {
        // 0x80058974: nop
    
            goto L_80058B34;
    }
    // 0x80058974: nop

L_80058978:
    // 0x80058978: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005897C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80058980: addiu       $t0, $t0, 0x2BB0
    ctx->r8 = ADD32(ctx->r8, 0X2BB0);
    // 0x80058984: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80058988: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8005898C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80058990: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80058994: nop

    // 0x80058998: bne         $t2, $t7, L_80058AFC
    if (ctx->r10 != ctx->r15) {
        // 0x8005899C: nop
    
            goto L_80058AFC;
    }
    // 0x8005899C: nop

    // 0x800589A0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800589A4: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x800589A8: lbu         $t6, 0x1($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1);
    // 0x800589AC: nop

    // 0x800589B0: bne         $t6, $t3, L_80058AFC
    if (ctx->r14 != ctx->r11) {
        // 0x800589B4: nop
    
            goto L_80058AFC;
    }
    // 0x800589B4: nop

    // 0x800589B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800589BC: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800589C0: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800589C4: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800589C8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800589CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800589D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800589D4: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800589D8: nop

    // 0x800589DC: bc1f        L_800589EC
    if (!c1cs) {
        // 0x800589E0: nop
    
            goto L_800589EC;
    }
    // 0x800589E0: nop

    // 0x800589E4: b           L_80058A60
    // 0x800589E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
        goto L_80058A60;
    // 0x800589E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800589EC:
    // 0x800589EC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800589F0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800589F4: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800589F8: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800589FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80058A00: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80058A04: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80058A08: nop

    // 0x80058A0C: bc1f        L_80058A20
    if (!c1cs) {
        // 0x80058A10: nop
    
            goto L_80058A20;
    }
    // 0x80058A10: nop

    // 0x80058A14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80058A18: b           L_80058A60
    // 0x80058A1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_80058A60;
    // 0x80058A1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_80058A20:
    // 0x80058A20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058A24: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80058A28: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80058A2C: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80058A30: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80058A34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058A38: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80058A3C: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80058A40: nop

    // 0x80058A44: bc1f        L_80058A58
    if (!c1cs) {
        // 0x80058A48: nop
    
            goto L_80058A58;
    }
    // 0x80058A48: nop

    // 0x80058A4C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80058A50: b           L_80058A60
    // 0x80058A54: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
        goto L_80058A60;
    // 0x80058A54: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_80058A58:
    // 0x80058A58: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80058A5C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_80058A60:
    // 0x80058A60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80058A64: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80058A68: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80058A6C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80058A70: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80058A74: lw          $t7, 0x4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4);
    // 0x80058A78: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80058A7C: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x80058A80: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80058A84: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80058A88: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80058A8C: lw          $t3, 0x670($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X670);
    // 0x80058A90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80058A94: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80058A98: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80058A9C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80058AA0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80058AA4: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80058AA8: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x80058AAC: lbu         $t6, 0x2BB2($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2BB2);
    // 0x80058AB0: mflo        $t8
    ctx->r24 = lo;
    // 0x80058AB4: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80058AB8: beq         $at, $zero, L_80058AFC
    if (ctx->r1 == 0) {
        // 0x80058ABC: nop
    
            goto L_80058AFC;
    }
    // 0x80058ABC: nop

    // 0x80058AC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80058AC4: addiu       $t7, $t7, 0xE80
    ctx->r15 = ADD32(ctx->r15, 0XE80);
    // 0x80058AC8: lw          $t4, 0x1C($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X1C);
    // 0x80058ACC: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80058AD0: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80058AD4: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x80058AD8: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80058ADC: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x80058AE0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80058AE4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80058AE8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80058AEC: lw          $t5, -0x794($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X794);
    // 0x80058AF0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80058AF4: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80058AF8: sw          $t9, -0x794($at)
    MEM_W(-0X794, ctx->r1) = ctx->r25;
L_80058AFC:
    // 0x80058AFC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80058B00: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80058B04: addiu       $t6, $t8, 0x6
    ctx->r14 = ADD32(ctx->r24, 0X6);
    // 0x80058B08: addiu       $t7, $t7, 0x2BB0
    ctx->r15 = ADD32(ctx->r15, 0X2BB0);
    // 0x80058B0C: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x80058B10: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80058B14: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80058B18: nop

    // 0x80058B1C: beq         $t1, $zero, L_80058B34
    if (ctx->r9 == 0) {
        // 0x80058B20: nop
    
            goto L_80058B34;
    }
    // 0x80058B20: nop

    // 0x80058B24: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x80058B28: nop

    // 0x80058B2C: bne         $t2, $zero, L_80058978
    if (ctx->r10 != 0) {
        // 0x80058B30: nop
    
            goto L_80058978;
    }
    // 0x80058B30: nop

L_80058B34:
    // 0x80058B34: b           L_80058B3C
    // 0x80058B38: nop

        goto L_80058B3C;
    // 0x80058B38: nop

L_80058B3C:
    // 0x80058B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058B40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058B44: jr          $ra
    // 0x80058B48: nop

    return;
    // 0x80058B48: nop

;}
RECOMP_FUNC void func_800A6440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6448: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800A644C:
    // 0x800A644C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6450: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A6454: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A6458: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A645C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6460: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A6464: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800A6468: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A646C: sw          $zero, 0x7400($at)
    MEM_W(0X7400, ctx->r1) = 0;
    // 0x800A6470: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6474: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A6478: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A647C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A6480: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6484: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A6488: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800A648C: addiu       $t0, $t0, 0x7340
    ctx->r8 = ADD32(ctx->r8, 0X7340);
    // 0x800A6490: jal         0x80099E2C
    // 0x800A6494: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x800A6494: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x800A6498: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A649C: nop

    // 0x800A64A0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800A64A4: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x800A64A8: bne         $at, $zero, L_800A644C
    if (ctx->r1 != 0) {
        // 0x800A64AC: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_800A644C;
    }
    // 0x800A64AC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A64B0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A64B4: addiu       $t3, $t3, 0x7340
    ctx->r11 = ADD32(ctx->r11, 0X7340);
    // 0x800A64B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A64BC: sw          $t3, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r11;
    // 0x800A64C0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A64C4: addiu       $t4, $t4, 0x7340
    ctx->r12 = ADD32(ctx->r12, 0X7340);
    // 0x800A64C8: addiu       $t5, $t4, 0x580
    ctx->r13 = ADD32(ctx->r12, 0X580);
    // 0x800A64CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A64D0: sw          $t5, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r13;
    // 0x800A64D4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A64D8: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x800A64DC: addiu       $t7, $t6, 0xB00
    ctx->r15 = ADD32(ctx->r14, 0XB00);
    // 0x800A64E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A64E4: sw          $t7, -0x73D0($at)
    MEM_W(-0X73D0, ctx->r1) = ctx->r15;
    // 0x800A64E8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A64EC: addiu       $t8, $t8, 0x7340
    ctx->r24 = ADD32(ctx->r24, 0X7340);
    // 0x800A64F0: addiu       $t9, $t8, 0x1080
    ctx->r25 = ADD32(ctx->r24, 0X1080);
    // 0x800A64F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A64F8: sw          $t9, -0x73C4($at)
    MEM_W(-0X73C4, ctx->r1) = ctx->r25;
    // 0x800A64FC: b           L_800A6504
    // 0x800A6500: nop

        goto L_800A6504;
    // 0x800A6500: nop

L_800A6504:
    // 0x800A6504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A650C: jr          $ra
    // 0x800A6510: nop

    return;
    // 0x800A6510: nop

;}
RECOMP_FUNC void func_80076998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007699C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800769A0: jal         0x80061348
    // 0x800769A4: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800769A4: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x800769A8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800769AC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800769B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800769B4: beq         $v0, $zero, L_800769EC
    if (ctx->r2 == 0) {
        // 0x800769B8: nop
    
            goto L_800769EC;
    }
    // 0x800769B8: nop

    // 0x800769BC: jal         0x80061348
    // 0x800769C0: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800769C0: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x800769C4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800769C8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800769CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800769D0: beq         $v0, $zero, L_800769EC
    if (ctx->r2 == 0) {
        // 0x800769D4: nop
    
            goto L_800769EC;
    }
    // 0x800769D4: nop

    // 0x800769D8: jal         0x80061348
    // 0x800769DC: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800769DC: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x800769E0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800769E4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800769E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800769EC:
    // 0x800769EC: b           L_800769FC
    // 0x800769F0: nop

        goto L_800769FC;
    // 0x800769F0: nop

    // 0x800769F4: b           L_800769FC
    // 0x800769F8: nop

        goto L_800769FC;
    // 0x800769F8: nop

L_800769FC:
    // 0x800769FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076A04: jr          $ra
    // 0x80076A08: nop

    return;
    // 0x80076A08: nop

;}
RECOMP_FUNC void func_80065124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065124: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065128: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006512C: nop

    // 0x80065130: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x80065134: nop

    // 0x80065138: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006513C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065140: jr          $ra
    // 0x80065144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065148: jr          $ra
    // 0x8006514C: nop

    return;
    // 0x8006514C: nop

    // 0x80065150: jr          $ra
    // 0x80065154: nop

    return;
    // 0x80065154: nop

;}
RECOMP_FUNC void func_80074FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074FC4: jal         0x80061348
    // 0x80074FC8: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074FC8: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x80074FCC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80074FD0: b           L_80074FE0
    // 0x80074FD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80074FE0;
    // 0x80074FD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074FD8: b           L_80074FE0
    // 0x80074FDC: nop

        goto L_80074FE0;
    // 0x80074FDC: nop

L_80074FE0:
    // 0x80074FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074FE8: jr          $ra
    // 0x80074FEC: nop

    return;
    // 0x80074FEC: nop

;}
RECOMP_FUNC void func_80082C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082C0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80082C10: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80082C14: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80082C18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082C1C: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80082C20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80082C24: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80082C28: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80082C2C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80082C30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082C34: lwc1        $f16, 0x10($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80082C38: nop

    // 0x80082C3C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80082C40: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x80082C44: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80082C48: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    // 0x80082C4C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80082C50: lwc1        $f18, -0xAEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XAEC);
    // 0x80082C54: lwc1        $f8, 0x10($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80082C58: lwc1        $f19, -0xAF0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0XAF0);
    // 0x80082C5C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80082C60: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x80082C64: nop

    // 0x80082C68: bc1f        L_80082C94
    if (!c1cs) {
        // 0x80082C6C: nop
    
            goto L_80082C94;
    }
    // 0x80082C6C: nop

    // 0x80082C70: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80082C74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082C78: lwc1        $f10, 0x10($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80082C7C: lwc1        $f5, -0xAE8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XAE8);
    // 0x80082C80: lwc1        $f4, -0xAE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XAE4);
    // 0x80082C84: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80082C88: sub.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d - ctx->f4.d;
    // 0x80082C8C: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80082C90: swc1        $f16, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f16.u32l;
L_80082C94:
    // 0x80082C94: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80082C98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082C9C: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80082CA0: lwc1        $f7, -0xAE0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0XAE0);
    // 0x80082CA4: lwc1        $f6, -0xADC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XADC);
    // 0x80082CA8: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80082CAC: mul.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80082CB0: jal         0x800C3070
    // 0x80082CB4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_0;
    // 0x80082CB4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_0:
    // 0x80082CB8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80082CBC: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80082CC0: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80082CC4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80082CC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082CCC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80082CD0: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x80082CD4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80082CD8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80082CDC: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80082CE0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80082CE4: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80082CE8: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x80082CEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082CF0: nop

    // 0x80082CF4: sub.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d - ctx->f8.d;
    // 0x80082CF8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80082CFC: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
    // 0x80082D00: b           L_80082D08
    // 0x80082D04: nop

        goto L_80082D08;
    // 0x80082D04: nop

L_80082D08:
    // 0x80082D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082D0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082D10: jr          $ra
    // 0x80082D14: nop

    return;
    // 0x80082D14: nop

;}
RECOMP_FUNC void func_8000CC44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000CC48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000CC4C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000CC50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000CC54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000CC58: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8000CC5C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000CC60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000CC64: bne         $t7, $at, L_8000CFC0
    if (ctx->r15 != ctx->r1) {
        // 0x8000CC68: nop
    
            goto L_8000CFC0;
    }
    // 0x8000CC68: nop

L_8000CC6C:
    // 0x8000CC6C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000CC70: nop

    // 0x8000CC74: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000CC78: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x8000CC7C: nop

    // 0x8000CC80: sltu        $at, $t9, $t0
    ctx->r1 = ctx->r25 < ctx->r8 ? 1 : 0;
    // 0x8000CC84: bne         $at, $zero, L_8000CC9C
    if (ctx->r1 != 0) {
        // 0x8000CC88: nop
    
            goto L_8000CC9C;
    }
    // 0x8000CC88: nop

    // 0x8000CC8C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000CC90: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8000CC94: b           L_8000CFC0
    // 0x8000CC98: nop

        goto L_8000CFC0;
    // 0x8000CC98: nop

L_8000CC9C:
    // 0x8000CC9C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000CCA0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000CCA4: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8000CCA8: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x8000CCAC: lhu         $s0, 0x0($t3)
    ctx->r16 = MEM_HU(ctx->r11, 0X0);
    // 0x8000CCB0: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x8000CCB4: addu        $t6, $s0, $at
    ctx->r14 = ADD32(ctx->r16, ctx->r1);
    // 0x8000CCB8: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x8000CCBC: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x8000CCC0: beq         $at, $zero, L_8000CFB0
    if (ctx->r1 == 0) {
        // 0x8000CCC4: sw          $t5, 0xC($t2)
        MEM_W(0XC, ctx->r10) = ctx->r13;
            goto L_8000CFB0;
    }
    // 0x8000CCC4: sw          $t5, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r13;
    // 0x8000CCC8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000CCCC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000CCD0: addu        $at, $at, $t6
    gpr jr_addend_8000CCDC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000CCD4: lw          $t6, -0x2CC0($at)
    ctx->r14 = ADD32(ctx->r1, -0X2CC0);
    // 0x8000CCD8: nop

    // 0x8000CCDC: jr          $t6
    // 0x8000CCE0: nop

    switch (jr_addend_8000CCDC >> 2) {
        case 0: goto L_8000CCE4; break;
        case 1: goto L_8000CFB0; break;
        case 2: goto L_8000CE0C; break;
        case 3: goto L_8000CE74; break;
        case 4: goto L_8000CE88; break;
        case 5: goto L_8000CE90; break;
        case 6: goto L_8000CF38; break;
        default: switch_error(__func__, 0x8000CCDC, 0x800ED340);
    }
    // 0x8000CCE0: nop

L_8000CCE4:
    // 0x8000CCE4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8000CCE8: nop

    // 0x8000CCEC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000CCF0: nop

    // 0x8000CCF4: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8000CCF8: nop

    // 0x8000CCFC: sh          $t9, 0x16($t7)
    MEM_H(0X16, ctx->r15) = ctx->r25;
    // 0x8000CD00: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000CD04: nop

    // 0x8000CD08: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000CD0C: nop

    // 0x8000CD10: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x8000CD14: sw          $t3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r11;
    // 0x8000CD18: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000CD1C: nop

    // 0x8000CD20: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8000CD24: nop

    // 0x8000CD28: lhu         $t2, 0x0($t5)
    ctx->r10 = MEM_HU(ctx->r13, 0X0);
    // 0x8000CD2C: nop

    // 0x8000CD30: sh          $t2, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r10;
    // 0x8000CD34: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000CD38: nop

    // 0x8000CD3C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x8000CD40: nop

    // 0x8000CD44: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000CD48: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8000CD4C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8000CD50: nop

    // 0x8000CD54: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x8000CD58: nop

    // 0x8000CD5C: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8000CD60: nop

    // 0x8000CD64: sh          $t3, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r11;
    // 0x8000CD68: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000CD6C: nop

    // 0x8000CD70: lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XC);
    // 0x8000CD74: nop

    // 0x8000CD78: addiu       $t2, $t5, 0x2
    ctx->r10 = ADD32(ctx->r13, 0X2);
    // 0x8000CD7C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8000CD80: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000CD84: nop

    // 0x8000CD88: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x8000CD8C: nop

    // 0x8000CD90: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000CD94: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x8000CD98: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000CD9C: nop

    // 0x8000CDA0: lw          $t1, 0xC($t6)
    ctx->r9 = MEM_W(ctx->r14, 0XC);
    // 0x8000CDA4: nop

    // 0x8000CDA8: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8000CDAC: nop

    // 0x8000CDB0: sh          $t3, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = ctx->r11;
    // 0x8000CDB4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8000CDB8: nop

    // 0x8000CDBC: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x8000CDC0: nop

    // 0x8000CDC4: addiu       $t2, $t5, 0x2
    ctx->r10 = ADD32(ctx->r13, 0X2);
    // 0x8000CDC8: sw          $t2, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r10;
    // 0x8000CDCC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000CDD0: nop

    // 0x8000CDD4: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    // 0x8000CDD8: nop

    // 0x8000CDDC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8000CDE0: nop

    // 0x8000CDE4: sh          $t9, 0x1E($t0)
    MEM_H(0X1E, ctx->r8) = ctx->r25;
    // 0x8000CDE8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000CDEC: nop

    // 0x8000CDF0: lw          $t1, 0xC($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC);
    // 0x8000CDF4: nop

    // 0x8000CDF8: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x8000CDFC: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8000CE00: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8000CE04: b           L_8000CFB0
    // 0x8000CE08: nop

        goto L_8000CFB0;
    // 0x8000CE08: nop

L_8000CE0C:
    // 0x8000CE0C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000CE10: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000CE14: lhu         $t5, 0x6($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X6);
    // 0x8000CE18: nop

    // 0x8000CE1C: andi        $t2, $t5, 0x1000
    ctx->r10 = ctx->r13 & 0X1000;
    // 0x8000CE20: beq         $t2, $zero, L_8000CE30
    if (ctx->r10 == 0) {
        // 0x8000CE24: nop
    
            goto L_8000CE30;
    }
    // 0x8000CE24: nop

    // 0x8000CE28: jal         0x800338D0
    // 0x8000CE2C: nop

    func_800338D0(rdram, ctx);
        goto after_0;
    // 0x8000CE2C: nop

    after_0:
L_8000CE30:
    // 0x8000CE30: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8000CE34: nop

    // 0x8000CE38: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000CE3C: nop

    // 0x8000CE40: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x8000CE44: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000CE48: jal         0x8005F064
    // 0x8000CE4C: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x8000CE4C: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    after_1:
    // 0x8000CE50: beq         $v0, $zero, L_8000CE60
    if (ctx->r2 == 0) {
        // 0x8000CE54: nop
    
            goto L_8000CE60;
    }
    // 0x8000CE54: nop

    // 0x8000CE58: b           L_8000CFB0
    // 0x8000CE5C: nop

        goto L_8000CFB0;
    // 0x8000CE5C: nop

L_8000CE60:
    // 0x8000CE60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8000CE64: jal         0x8000CFE4
    // 0x8000CE68: ori         $a1, $zero, 0xC003
    ctx->r5 = 0 | 0XC003;
    func_8000CFE4(rdram, ctx);
        goto after_2;
    // 0x8000CE68: ori         $a1, $zero, 0xC003
    ctx->r5 = 0 | 0XC003;
    after_2:
    // 0x8000CE6C: b           L_8000CFB0
    // 0x8000CE70: nop

        goto L_8000CFB0;
    // 0x8000CE70: nop

L_8000CE74:
    // 0x8000CE74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8000CE78: jal         0x8000CFE4
    // 0x8000CE7C: ori         $a1, $zero, 0xC004
    ctx->r5 = 0 | 0XC004;
    func_8000CFE4(rdram, ctx);
        goto after_3;
    // 0x8000CE7C: ori         $a1, $zero, 0xC004
    ctx->r5 = 0 | 0XC004;
    after_3:
    // 0x8000CE80: b           L_8000CFB0
    // 0x8000CE84: nop

        goto L_8000CFB0;
    // 0x8000CE84: nop

L_8000CE88:
    // 0x8000CE88: b           L_8000CFB0
    // 0x8000CE8C: nop

        goto L_8000CFB0;
    // 0x8000CE8C: nop

L_8000CE90:
    // 0x8000CE90: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000CE94: nop

    // 0x8000CE98: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000CE9C: nop

    // 0x8000CEA0: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8000CEA4: nop

    // 0x8000CEA8: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8000CEAC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8000CEB0: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8000CEB4: nop

    // 0x8000CEB8: addiu       $t5, $t6, 0x2
    ctx->r13 = ADD32(ctx->r14, 0X2);
    // 0x8000CEBC: sw          $t5, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r13;
    // 0x8000CEC0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000CEC4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000CEC8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000CECC: nop

    // 0x8000CED0: lhu         $t7, 0x0($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X0);
    // 0x8000CED4: nop

    // 0x8000CED8: or          $t1, $t2, $t7
    ctx->r9 = ctx->r10 | ctx->r15;
    // 0x8000CEDC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8000CEE0: lw          $t3, 0xC($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XC);
    // 0x8000CEE4: nop

    // 0x8000CEE8: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8000CEEC: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
    // 0x8000CEF0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8000CEF4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000CEF8: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x8000CEFC: nop

    // 0x8000CF00: subu        $t9, $t6, $t0
    ctx->r25 = SUB32(ctx->r14, ctx->r8);
    // 0x8000CF04: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8000CF08: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8000CF0C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000CF10: lw          $t1, 0x8($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X8);
    // 0x8000CF14: nop

    // 0x8000CF18: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x8000CF1C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8000CF20: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000CF24: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000CF28: nop

    // 0x8000CF2C: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
    // 0x8000CF30: b           L_8000CFB0
    // 0x8000CF34: nop

        goto L_8000CFB0;
    // 0x8000CF34: nop

L_8000CF38:
    // 0x8000CF38: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8000CF3C: nop

    // 0x8000CF40: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8000CF44: nop

    // 0x8000CF48: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x8000CF4C: nop

    // 0x8000CF50: sh          $t0, 0x1C($t5)
    MEM_H(0X1C, ctx->r13) = ctx->r8;
    // 0x8000CF54: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8000CF58: nop

    // 0x8000CF5C: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x8000CF60: nop

    // 0x8000CF64: addiu       $t2, $t7, 0x2
    ctx->r10 = ADD32(ctx->r15, 0X2);
    // 0x8000CF68: sw          $t2, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r10;
    // 0x8000CF6C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8000CF70: nop

    // 0x8000CF74: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x8000CF78: nop

    // 0x8000CF7C: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000CF80: nop

    // 0x8000CF84: sh          $t4, 0x1E($t1)
    MEM_H(0X1E, ctx->r9) = ctx->r12;
    // 0x8000CF88: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000CF8C: nop

    // 0x8000CF90: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x8000CF94: nop

    // 0x8000CF98: addiu       $t0, $t6, 0x2
    ctx->r8 = ADD32(ctx->r14, 0X2);
    // 0x8000CF9C: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x8000CFA0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8000CFA4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8000CFA8: b           L_8000CFB0
    // 0x8000CFAC: nop

        goto L_8000CFB0;
    // 0x8000CFAC: nop

L_8000CFB0:
    // 0x8000CFB0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000CFB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000CFB8: beq         $t7, $at, L_8000CC6C
    if (ctx->r15 == ctx->r1) {
        // 0x8000CFBC: nop
    
            goto L_8000CC6C;
    }
    // 0x8000CFBC: nop

L_8000CFC0:
    // 0x8000CFC0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8000CFC4: b           L_8000CFD4
    // 0x8000CFC8: nop

        goto L_8000CFD4;
    // 0x8000CFC8: nop

    // 0x8000CFCC: b           L_8000CFD4
    // 0x8000CFD0: nop

        goto L_8000CFD4;
    // 0x8000CFD0: nop

L_8000CFD4:
    // 0x8000CFD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000CFD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000CFDC: jr          $ra
    // 0x8000CFE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000CFE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ContPak_UpdateFilesState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE40C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE414: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE418: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE41C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800AE420: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE424: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE428: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE42C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE430: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE434: addiu       $at, $zero, -0x1D
    ctx->r1 = ADD32(0, -0X1D);
    // 0x800AE438: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800AE43C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE440: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AE444: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE448: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE44C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800AE450: addiu       $a2, $a2, 0x1620
    ctx->r6 = ADD32(ctx->r6, 0X1620);
    // 0x800AE454: addiu       $a1, $a1, 0x162C
    ctx->r5 = ADD32(ctx->r5, 0X162C);
    // 0x800AE458: jal         0x800C6650
    // 0x800AE45C: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE45C: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    after_0:
    // 0x800AE460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE464: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AE468: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE46C: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AE470: nop

    // 0x800AE474: beq         $t0, $zero, L_800AE498
    if (ctx->r8 == 0) {
        // 0x800AE478: nop
    
            goto L_800AE498;
    }
    // 0x800AE478: nop

    // 0x800AE47C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE480: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE484: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE488: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x800AE48C: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
    // 0x800AE490: b           L_800AE570
    // 0x800AE494: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE570;
    // 0x800AE494: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE498:
    // 0x800AE498: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800AE49C:
    // 0x800AE49C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE4A0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE4A4: addiu       $t5, $t5, 0x13D0
    ctx->r13 = ADD32(ctx->r13, 0X13D0);
    // 0x800AE4A8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE4AC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800AE4B0: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800AE4B4: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AE4B8: jal         0x800C67A0
    // 0x800AE4BC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    osPfsFileState_recomp(rdram, ctx);
        goto after_1;
    // 0x800AE4BC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800AE4C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE4C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE4C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AE4CC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AE4D0: sw          $v0, 0x15D8($at)
    MEM_W(0X15D8, ctx->r1) = ctx->r2;
    // 0x800AE4D4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE4D8: nop

    // 0x800AE4DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800AE4E0: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800AE4E4: bne         $at, $zero, L_800AE49C
    if (ctx->r1 != 0) {
        // 0x800AE4E8: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_800AE49C;
    }
    // 0x800AE4E8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800AE4EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE4F0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE4F4: addiu       $a1, $a1, 0x1638
    ctx->r5 = ADD32(ctx->r5, 0X1638);
    // 0x800AE4F8: jal         0x800C6A90
    // 0x800AE4FC: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_2;
    // 0x800AE4FC: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    after_2:
    // 0x800AE500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE504: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AE508: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE50C: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AE510: nop

    // 0x800AE514: beq         $t0, $zero, L_800AE538
    if (ctx->r8 == 0) {
        // 0x800AE518: nop
    
            goto L_800AE538;
    }
    // 0x800AE518: nop

    // 0x800AE51C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE520: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE524: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE528: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x800AE52C: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
    // 0x800AE530: b           L_800AE570
    // 0x800AE534: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE570;
    // 0x800AE534: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE538:
    // 0x800AE538: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE53C: lw          $t3, 0x1638($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1638);
    // 0x800AE540: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE544: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800AE548: sw          $t4, 0x1638($at)
    MEM_W(0X1638, ctx->r1) = ctx->r12;
    // 0x800AE54C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE550: lw          $t5, 0x129C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X129C);
    // 0x800AE554: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE558: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x800AE55C: sw          $t6, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r14;
    // 0x800AE560: b           L_800AE570
    // 0x800AE564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE570;
    // 0x800AE564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE568: b           L_800AE570
    // 0x800AE56C: nop

        goto L_800AE570;
    // 0x800AE56C: nop

L_800AE570:
    // 0x800AE570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE574: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE578: jr          $ra
    // 0x800AE57C: nop

    return;
    // 0x800AE57C: nop

;}
RECOMP_FUNC void func_80064100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064108: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006410C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064110: nop

    // 0x80064114: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064118: nop

    // 0x8006411C: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80064120: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064124: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064128: beq         $v0, $zero, L_80064140
    if (ctx->r2 == 0) {
        // 0x8006412C: nop
    
            goto L_80064140;
    }
    // 0x8006412C: nop

    // 0x80064130: jal         0x8005F064
    // 0x80064134: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064134: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064138: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006413C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80064140:
    // 0x80064140: b           L_80064150
    // 0x80064144: nop

        goto L_80064150;
    // 0x80064144: nop

    // 0x80064148: b           L_80064150
    // 0x8006414C: nop

        goto L_80064150;
    // 0x8006414C: nop

L_80064150:
    // 0x80064150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064158: jr          $ra
    // 0x8006415C: nop

    return;
    // 0x8006415C: nop

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
RECOMP_FUNC void _init_lpfilter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFB00: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800CFB04: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x800CFB08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CFB0C: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x800CFB10: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800CFB14: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800CFB18: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800CFB1C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x800CFB20: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x800CFB24: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x800CFB28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFB2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_800CFB30:
    // 0x800CFB30: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CFB34: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800CFB38: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800CFB3C: bne         $at, $zero, L_800CFB30
    if (ctx->r1 != 0) {
        // 0x800CFB40: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_800CFB30;
    }
    // 0x800CFB40: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x800CFB44: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800CFB48: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x800CFB4C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800CFB50: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CFB54: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800CFB58: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CFB5C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800CFB60: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x800CFB64: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x800CFB68: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800CFB6C: beq         $at, $zero, L_800CFB98
    if (ctx->r1 == 0) {
        // 0x800CFB70: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_800CFB98;
    }
    // 0x800CFB70: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_800CFB74:
    // 0x800CFB74: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800CFB78: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CFB7C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800CFB80: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800CFB84: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x800CFB88: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x800CFB8C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800CFB90: bne         $at, $zero, L_800CFB74
    if (ctx->r1 != 0) {
        // 0x800CFB94: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_800CFB74;
    }
    // 0x800CFB94: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_800CFB98:
    // 0x800CFB98: jr          $ra
    // 0x800CFB9C: nop

    return;
    // 0x800CFB9C: nop

;}
RECOMP_FUNC void func_80010AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010AC8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80010ACC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80010AD0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80010AD4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80010AD8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80010ADC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80010AE0: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80010AE4: nop

    // 0x80010AE8: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80010AEC: nop

    // 0x80010AF0: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80010AF4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80010AF8: nop

    // 0x80010AFC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80010B00: nop

    // 0x80010B04: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80010B08: beq         $t0, $zero, L_80010B18
    if (ctx->r8 == 0) {
        // 0x80010B0C: nop
    
            goto L_80010B18;
    }
    // 0x80010B0C: nop

    // 0x80010B10: b           L_80011028
    // 0x80010B14: nop

        goto L_80011028;
    // 0x80010B14: nop

L_80010B18:
    // 0x80010B18: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80010B1C: nop

    // 0x80010B20: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80010B24: nop

    // 0x80010B28: andi        $t3, $t2, 0x800
    ctx->r11 = ctx->r10 & 0X800;
    // 0x80010B2C: bne         $t3, $zero, L_80010DBC
    if (ctx->r11 != 0) {
        // 0x80010B30: nop
    
            goto L_80010DBC;
    }
    // 0x80010B30: nop

    // 0x80010B34: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80010B38: nop

    // 0x80010B3C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80010B40: nop

    // 0x80010B44: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80010B48: beq         $t6, $zero, L_80010DBC
    if (ctx->r14 == 0) {
        // 0x80010B4C: nop
    
            goto L_80010DBC;
    }
    // 0x80010B4C: nop

    // 0x80010B50: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80010B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010B58: jal         0x800B3434
    // 0x80010B5C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800B3434(rdram, ctx);
        goto after_0;
    // 0x80010B5C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80010B60: sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // 0x80010B64: lhu         $t7, 0x4A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X4A);
    // 0x80010B68: nop

    // 0x80010B6C: andi        $t8, $t7, 0xC000
    ctx->r24 = ctx->r15 & 0XC000;
    // 0x80010B70: beq         $t8, $zero, L_80010DBC
    if (ctx->r24 == 0) {
        // 0x80010B74: nop
    
            goto L_80010DBC;
    }
    // 0x80010B74: nop

    // 0x80010B78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80010B7C: nop

    // 0x80010B80: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80010B84: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80010B88: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80010B8C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80010B90: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80010B94: nop

    // 0x80010B98: lwc1        $f6, 0xCC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x80010B9C: nop

    // 0x80010BA0: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80010BA4: nop

    // 0x80010BA8: bc1f        L_80010BB8
    if (!c1cs) {
        // 0x80010BAC: nop
    
            goto L_80010BB8;
    }
    // 0x80010BAC: nop

    // 0x80010BB0: b           L_80010BD4
    // 0x80010BB4: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
        goto L_80010BD4;
    // 0x80010BB4: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
L_80010BB8:
    // 0x80010BB8: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80010BBC: nop

    // 0x80010BC0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80010BC4: nop

    // 0x80010BC8: lwc1        $f20, 0xCC($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x80010BCC: nop

    // 0x80010BD0: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80010BD4:
    // 0x80010BD4: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x80010BD8: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010BDC: lui         $at, 0x4064
    ctx->r1 = S32(0X4064 << 16);
    // 0x80010BE0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80010BE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80010BE8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80010BEC: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x80010BF0: nop

    // 0x80010BF4: bc1f        L_80010C1C
    if (!c1cs) {
        // 0x80010BF8: nop
    
            goto L_80010C1C;
    }
    // 0x80010BF8: nop

    // 0x80010BFC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010C00: lui         $at, 0x4064
    ctx->r1 = S32(0X4064 << 16);
    // 0x80010C04: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80010C08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010C0C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80010C10: sub.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d - ctx->f6.d;
    // 0x80010C14: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80010C18: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
L_80010C1C:
    // 0x80010C1C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80010C20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80010C24: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80010C28: nop

    // 0x80010C2C: lwc1        $f18, 0xD0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x80010C30: nop

    // 0x80010C34: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80010C38: nop

    // 0x80010C3C: bc1f        L_80010C4C
    if (!c1cs) {
        // 0x80010C40: nop
    
            goto L_80010C4C;
    }
    // 0x80010C40: nop

    // 0x80010C44: b           L_80010C68
    // 0x80010C48: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
        goto L_80010C68;
    // 0x80010C48: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_80010C4C:
    // 0x80010C4C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80010C50: nop

    // 0x80010C54: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80010C58: nop

    // 0x80010C5C: lwc1        $f20, 0xD0($t6)
    ctx->f20.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x80010C60: nop

    // 0x80010C64: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80010C68:
    // 0x80010C68: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x80010C6C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80010C70: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010C74: lwc1        $f11, -0x2B50($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2B50);
    // 0x80010C78: lwc1        $f10, -0x2B4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B4C);
    // 0x80010C7C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80010C80: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x80010C84: nop

    // 0x80010C88: bc1f        L_80010CB0
    if (!c1cs) {
        // 0x80010C8C: nop
    
            goto L_80010CB0;
    }
    // 0x80010C8C: nop

    // 0x80010C90: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80010C94: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010C98: lwc1        $f19, -0x2B48($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2B48);
    // 0x80010C9C: lwc1        $f18, -0x2B44($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B44);
    // 0x80010CA0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80010CA4: sub.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
    // 0x80010CA8: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80010CAC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
L_80010CB0:
    // 0x80010CB0: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80010CB4: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80010CB8: nop

    // 0x80010CBC: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80010CC0: nop

    // 0x80010CC4: bc1f        L_80010CD4
    if (!c1cs) {
        // 0x80010CC8: nop
    
            goto L_80010CD4;
    }
    // 0x80010CC8: nop

    // 0x80010CCC: b           L_80010CE0
    // 0x80010CD0: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
        goto L_80010CE0;
    // 0x80010CD0: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_80010CD4:
    // 0x80010CD4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80010CD8: nop

    // 0x80010CDC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
L_80010CE0:
    // 0x80010CE0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80010CE4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010CE8: lwc1        $f7, -0x2B40($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2B40);
    // 0x80010CEC: lwc1        $f6, -0x2B3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B3C);
    // 0x80010CF0: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80010CF4: nop

    // 0x80010CF8: div.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x80010CFC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80010D00: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80010D04: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80010D08: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x80010D0C: mul.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80010D10: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80010D14: nop

    // 0x80010D18: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80010D1C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80010D20: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80010D24: nop

    // 0x80010D28: cvt.w.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_D(ctx->f4.d);
    // 0x80010D2C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80010D30: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80010D34: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80010D38: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80010D3C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80010D40: nop

    // 0x80010D44: blez        $t1, L_80010DBC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80010D48: nop
    
            goto L_80010DBC;
    }
    // 0x80010D48: nop

    // 0x80010D4C: lhu         $t2, 0x4A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X4A);
    // 0x80010D50: nop

    // 0x80010D54: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x80010D58: beq         $t3, $zero, L_80010D84
    if (ctx->r11 == 0) {
        // 0x80010D5C: nop
    
            goto L_80010D84;
    }
    // 0x80010D5C: nop

    // 0x80010D60: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80010D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010D68: jal         0x800B32E4
    // 0x80010D6C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800B32E4(rdram, ctx);
        goto after_1;
    // 0x80010D6C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x80010D70: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80010D74: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80010D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010D7C: jal         0x8002206C
    // 0x80010D80: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_8002206C(rdram, ctx);
        goto after_2;
    // 0x80010D80: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_2:
L_80010D84:
    // 0x80010D84: lhu         $t4, 0x4A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X4A);
    // 0x80010D88: nop

    // 0x80010D8C: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80010D90: beq         $t5, $zero, L_80010DBC
    if (ctx->r13 == 0) {
        // 0x80010D94: nop
    
            goto L_80010DBC;
    }
    // 0x80010D94: nop

    // 0x80010D98: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80010D9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80010DA0: jal         0x800B32E4
    // 0x80010DA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800B32E4(rdram, ctx);
        goto after_3;
    // 0x80010DA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_3:
    // 0x80010DA8: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80010DAC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80010DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010DB4: jal         0x8002206C
    // 0x80010DB8: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    func_8002206C(rdram, ctx);
        goto after_4;
    // 0x80010DB8: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_4:
L_80010DBC:
    // 0x80010DBC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80010DC0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80010DC4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80010DC8: nop

    // 0x80010DCC: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80010DD0: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x80010DD4: nop

    // 0x80010DD8: blez        $t9, L_80011020
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80010DDC: nop
    
            goto L_80011020;
    }
    // 0x80010DDC: nop

L_80010DE0:
    // 0x80010DE0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80010DE4: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80010DE8: lwc1        $f8, 0xF4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x80010DEC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80010DF0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80010DF4: c.le.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d <= ctx->f16.d;
    // 0x80010DF8: nop

    // 0x80010DFC: bc1t        L_80010E24
    if (c1cs) {
        // 0x80010E00: nop
    
            goto L_80010E24;
    }
    // 0x80010E00: nop

    // 0x80010E04: lwc1        $f10, 0xF8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x80010E08: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80010E0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80010E10: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80010E14: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x80010E18: nop

    // 0x80010E1C: bc1f        L_80010E2C
    if (!c1cs) {
        // 0x80010E20: nop
    
            goto L_80010E2C;
    }
    // 0x80010E20: nop

L_80010E24:
    // 0x80010E24: b           L_80010FF0
    // 0x80010E28: nop

        goto L_80010FF0;
    // 0x80010E28: nop

L_80010E2C:
    // 0x80010E2C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80010E30: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80010E34: lwc1        $f8, 0xF4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XF4);
    // 0x80010E38: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80010E3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80010E40: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80010E44: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x80010E48: nop

    // 0x80010E4C: bc1f        L_80010E78
    if (!c1cs) {
        // 0x80010E50: nop
    
            goto L_80010E78;
    }
    // 0x80010E50: nop

    // 0x80010E54: lwc1        $f10, 0xF8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x80010E58: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80010E5C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80010E60: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80010E64: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80010E68: c.eq.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d == ctx->f18.d;
    // 0x80010E6C: nop

    // 0x80010E70: bc1t        L_80010EC0
    if (c1cs) {
        // 0x80010E74: nop
    
            goto L_80010EC0;
    }
    // 0x80010E74: nop

L_80010E78:
    // 0x80010E78: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80010E7C: lh          $t1, 0x721C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X721C);
    // 0x80010E80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80010E84: beq         $t1, $at, L_80010EA8
    if (ctx->r9 == ctx->r1) {
        // 0x80010E88: nop
    
            goto L_80010EA8;
    }
    // 0x80010E88: nop

    // 0x80010E8C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80010E90: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80010E94: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x80010E98: nop

    // 0x80010E9C: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80010EA0: b           L_80010EC0
    // 0x80010EA4: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
        goto L_80010EC0;
    // 0x80010EA4: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
L_80010EA8:
    // 0x80010EA8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80010EAC: nop

    // 0x80010EB0: lw          $t7, 0xC0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC0);
    // 0x80010EB4: nop

    // 0x80010EB8: ori         $t6, $t7, 0x8
    ctx->r14 = ctx->r15 | 0X8;
    // 0x80010EBC: sw          $t6, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r14;
L_80010EC0:
    // 0x80010EC0: jal         0x800C1754
    // 0x80010EC4: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_5;
    // 0x80010EC4: nop

    after_5:
    // 0x80010EC8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80010ECC: jal         0x8009A14C
    // 0x80010ED0: nop

    func_8009A14C(rdram, ctx);
        goto after_6;
    // 0x80010ED0: nop

    after_6:
    // 0x80010ED4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80010ED8: nop

    // 0x80010EDC: lw          $t8, 0xC0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0XC0);
    // 0x80010EE0: nop

    // 0x80010EE4: andi        $t0, $t8, 0x10
    ctx->r8 = ctx->r24 & 0X10;
    // 0x80010EE8: beq         $t0, $zero, L_80010FDC
    if (ctx->r8 == 0) {
        // 0x80010EEC: nop
    
            goto L_80010FDC;
    }
    // 0x80010EEC: nop

    // 0x80010EF0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80010EF4: nop

    // 0x80010EF8: lwc1        $f12, 0xF0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XF0);
    // 0x80010EFC: jal         0x800C2780
    // 0x80010F00: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_7;
    // 0x80010F00: nop

    after_7:
    // 0x80010F04: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80010F08: nop

    // 0x80010F0C: lwc1        $f12, 0xEC($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XEC);
    // 0x80010F10: jal         0x800C25B8
    // 0x80010F14: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_8;
    // 0x80010F14: nop

    after_8:
    // 0x80010F18: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80010F1C: nop

    // 0x80010F20: lwc1        $f12, 0xE8($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XE8);
    // 0x80010F24: jal         0x800C23E8
    // 0x80010F28: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_9;
    // 0x80010F28: nop

    after_9:
    // 0x80010F2C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80010F30: nop

    // 0x80010F34: lhu         $t7, 0x0($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X0);
    // 0x80010F38: nop

    // 0x80010F3C: andi        $t6, $t7, 0x20
    ctx->r14 = ctx->r15 & 0X20;
    // 0x80010F40: bne         $t6, $zero, L_80010FDC
    if (ctx->r14 != 0) {
        // 0x80010F44: nop
    
            goto L_80010FDC;
    }
    // 0x80010F44: nop

    // 0x80010F48: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80010F4C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80010F50: lwc1        $f8, 0xE8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x80010F54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80010F58: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80010F5C: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x80010F60: nop

    // 0x80010F64: bc1f        L_80010FDC
    if (!c1cs) {
        // 0x80010F68: nop
    
            goto L_80010FDC;
    }
    // 0x80010F68: nop

    // 0x80010F6C: lwc1        $f10, 0xEC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XEC);
    // 0x80010F70: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80010F74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80010F78: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80010F7C: c.eq.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d == ctx->f18.d;
    // 0x80010F80: nop

    // 0x80010F84: bc1f        L_80010FDC
    if (!c1cs) {
        // 0x80010F88: nop
    
            goto L_80010FDC;
    }
    // 0x80010F88: nop

    // 0x80010F8C: lwc1        $f8, 0xF0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XF0);
    // 0x80010F90: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80010F94: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80010F98: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80010F9C: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x80010FA0: nop

    // 0x80010FA4: bc1f        L_80010FDC
    if (!c1cs) {
        // 0x80010FA8: nop
    
            goto L_80010FDC;
    }
    // 0x80010FA8: nop

    // 0x80010FAC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80010FB0: nop

    // 0x80010FB4: lw          $t8, 0xC0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0XC0);
    // 0x80010FB8: nop

    // 0x80010FBC: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x80010FC0: sw          $t0, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r8;
    // 0x80010FC4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80010FC8: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80010FCC: lw          $t3, 0xC0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC0);
    // 0x80010FD0: nop

    // 0x80010FD4: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80010FD8: sw          $t4, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r12;
L_80010FDC:
    // 0x80010FDC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80010FE0: jal         0x800997D8
    // 0x80010FE4: nop

    func_800997D8(rdram, ctx);
        goto after_10;
    // 0x80010FE4: nop

    after_10:
    // 0x80010FE8: jal         0x800C1A28
    // 0x80010FEC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_11;
    // 0x80010FEC: nop

    after_11:
L_80010FF0:
    // 0x80010FF0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80010FF4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80010FF8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80010FFC: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x80011000: addiu       $t5, $t6, 0x160
    ctx->r13 = ADD32(ctx->r14, 0X160);
    // 0x80011004: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x80011008: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8001100C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80011010: nop

    // 0x80011014: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80011018: bne         $at, $zero, L_80010DE0
    if (ctx->r1 != 0) {
        // 0x8001101C: nop
    
            goto L_80010DE0;
    }
    // 0x8001101C: nop

L_80011020:
    // 0x80011020: b           L_80011028
    // 0x80011024: nop

        goto L_80011028;
    // 0x80011024: nop

L_80011028:
    // 0x80011028: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001102C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80011030: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80011034: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80011038: jr          $ra
    // 0x8001103C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001103C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800673D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800673D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800673D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800673DC: nop

    // 0x800673E0: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x800673E4: nop

    // 0x800673E8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800673EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800673F0: jr          $ra
    // 0x800673F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800673F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800673F8: jr          $ra
    // 0x800673FC: nop

    return;
    // 0x800673FC: nop

    // 0x80067400: jr          $ra
    // 0x80067404: nop

    return;
    // 0x80067404: nop

;}
RECOMP_FUNC void func_8006422C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006422C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064234: jal         0x80061488
    // 0x80064238: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064238: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x8006423C: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064240: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064244: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x80064248: nop
    
            goto L_800642D8;
    }
    // 0x80064248: nop

    // 0x8006424C: jal         0x80061488
    // 0x80064250: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80064250: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064254: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064258: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006425C: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x80064260: nop
    
            goto L_800642D8;
    }
    // 0x80064260: nop

    // 0x80064264: jal         0x80061488
    // 0x80064268: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064268: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x8006426C: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064270: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064274: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x80064278: nop
    
            goto L_800642D8;
    }
    // 0x80064278: nop

    // 0x8006427C: jal         0x80061488
    // 0x80064280: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x80064280: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064284: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064288: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006428C: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x80064290: nop
    
            goto L_800642D8;
    }
    // 0x80064290: nop

    // 0x80064294: jal         0x80061488
    // 0x80064298: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x80064298: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x8006429C: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800642A0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800642A4: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x800642A8: nop
    
            goto L_800642D8;
    }
    // 0x800642A8: nop

    // 0x800642AC: jal         0x8005F064
    // 0x800642B0: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x800642B0: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x800642B4: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x800642B8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800642BC: beq         $v0, $zero, L_800642D8
    if (ctx->r2 == 0) {
        // 0x800642C0: nop
    
            goto L_800642D8;
    }
    // 0x800642C0: nop

    // 0x800642C4: jal         0x80061348
    // 0x800642C8: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800642C8: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x800642CC: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800642D0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800642D4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800642D8:
    // 0x800642D8: b           L_800642E8
    // 0x800642DC: nop

        goto L_800642E8;
    // 0x800642DC: nop

    // 0x800642E0: b           L_800642E8
    // 0x800642E4: nop

        goto L_800642E8;
    // 0x800642E4: nop

L_800642E8:
    // 0x800642E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800642EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800642F0: jr          $ra
    // 0x800642F4: nop

    return;
    // 0x800642F4: nop

;}
RECOMP_FUNC void __alCSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAB2C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800CAB30: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800CAB34: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CAB38: bne         $t6, $zero, L_800CAB48
    if (ctx->r14 != 0) {
        // 0x800CAB3C: lw          $v0, 0x10($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X10);
            goto L_800CAB48;
    }
    // 0x800CAB3C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800CAB40: jr          $ra
    // 0x800CAB44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CAB44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CAB48:
    // 0x800CAB48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CAB4C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800CAB50: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_800CAB54:
    // 0x800CAB54: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800CAB58: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x800CAB5C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CAB60: beql        $t8, $zero, L_800CABA4
    if (ctx->r24 == 0) {
        // 0x800CAB64: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800CABA4;
    }
    goto skip_0;
    // 0x800CAB64: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x800CAB68: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CAB6C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CAB70: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800CAB74: beql        $t3, $zero, L_800CAB90
    if (ctx->r11 == 0) {
        // 0x800CAB78: lw          $t0, 0xB8($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XB8);
            goto L_800CAB90;
    }
    goto skip_1;
    // 0x800CAB78: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
    skip_1:
    // 0x800CAB7C: lw          $t4, 0xB8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XB8);
    // 0x800CAB80: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800CAB84: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x800CAB88: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800CAB8C: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
L_800CAB90:
    // 0x800CAB90: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800CAB94: beql        $at, $zero, L_800CABA4
    if (ctx->r1 == 0) {
        // 0x800CAB98: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800CABA4;
    }
    goto skip_2;
    // 0x800CAB98: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x800CAB9C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800CABA0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800CABA4:
    // 0x800CABA4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CABA8: beq         $t8, $zero, L_800CABE8
    if (ctx->r24 == 0) {
        // 0x800CABAC: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_800CABE8;
    }
    // 0x800CABAC: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x800CABB0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CABB4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CABB8: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800CABBC: beql        $t3, $zero, L_800CABD8
    if (ctx->r11 == 0) {
        // 0x800CABC0: lw          $t0, 0xBC($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XBC);
            goto L_800CABD8;
    }
    goto skip_3;
    // 0x800CABC0: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
    skip_3:
    // 0x800CABC4: lw          $t4, 0xBC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XBC);
    // 0x800CABC8: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800CABCC: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x800CABD0: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800CABD4: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
L_800CABD8:
    // 0x800CABD8: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800CABDC: beql        $at, $zero, L_800CABEC
    if (ctx->r1 == 0) {
        // 0x800CABE0: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800CABEC;
    }
    goto skip_4;
    // 0x800CABE0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x800CABE4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800CABE8:
    // 0x800CABE8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800CABEC:
    // 0x800CABEC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CABF0: beq         $t8, $zero, L_800CAC30
    if (ctx->r24 == 0) {
        // 0x800CABF4: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_800CAC30;
    }
    // 0x800CABF4: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x800CABF8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CABFC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CAC00: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800CAC04: beql        $t3, $zero, L_800CAC20
    if (ctx->r11 == 0) {
        // 0x800CAC08: lw          $t0, 0xC0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XC0);
            goto L_800CAC20;
    }
    goto skip_5;
    // 0x800CAC08: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
    skip_5:
    // 0x800CAC0C: lw          $t4, 0xC0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC0);
    // 0x800CAC10: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800CAC14: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x800CAC18: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800CAC1C: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
L_800CAC20:
    // 0x800CAC20: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800CAC24: beql        $at, $zero, L_800CAC34
    if (ctx->r1 == 0) {
        // 0x800CAC28: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800CAC34;
    }
    goto skip_6;
    // 0x800CAC28: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x800CAC2C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800CAC30:
    // 0x800CAC30: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800CAC34:
    // 0x800CAC34: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CAC38: beql        $t8, $zero, L_800CAC78
    if (ctx->r24 == 0) {
        // 0x800CAC3C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800CAC78;
    }
    goto skip_7;
    // 0x800CAC3C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x800CAC40: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CAC44: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CAC48: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800CAC4C: beql        $t3, $zero, L_800CAC64
    if (ctx->r11 == 0) {
        // 0x800CAC50: lw          $a1, 0xC4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0XC4);
            goto L_800CAC64;
    }
    goto skip_8;
    // 0x800CAC50: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
    skip_8:
    // 0x800CAC54: lw          $t4, 0xC4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC4);
    // 0x800CAC58: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800CAC5C: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x800CAC60: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
L_800CAC64:
    // 0x800CAC64: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800CAC68: beql        $at, $zero, L_800CAC78
    if (ctx->r1 == 0) {
        // 0x800CAC6C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800CAC78;
    }
    goto skip_9;
    // 0x800CAC6C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x800CAC70: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800CAC74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800CAC78:
    // 0x800CAC78: bnel        $a2, $t2, L_800CAB54
    if (ctx->r6 != ctx->r10) {
        // 0x800CAC7C: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_800CAB54;
    }
    goto skip_10;
    // 0x800CAC7C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x800CAC80: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CAC84: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x800CAC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CAC8C: jr          $ra
    // 0x800CAC90: nop

    return;
    // 0x800CAC90: nop

;}
RECOMP_FUNC void func_80050A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050A24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050A2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80050A30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80050A34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80050A38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80050A3C: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x80050A40: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80050A44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80050A48: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x80050A4C: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    // 0x80050A50: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80050A54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80050A58: jal         0x8004F3E8
    // 0x80050A5C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8004F3E8(rdram, ctx);
        goto after_0;
    // 0x80050A5C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80050A60: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80050A64: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80050A68: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80050A6C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80050A70: bne         $t2, $zero, L_80050AAC
    if (ctx->r10 != 0) {
        // 0x80050A74: andi        $t3, $t1, 0x2
        ctx->r11 = ctx->r9 & 0X2;
            goto L_80050AAC;
    }
    // 0x80050A74: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x80050A78: bne         $t3, $zero, L_80050AAC
    if (ctx->r11 != 0) {
        // 0x80050A7C: nop
    
            goto L_80050AAC;
    }
    // 0x80050A7C: nop

L_80050A80:
    // 0x80050A80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80050A84: jal         0x800499B0
    // 0x80050A88: nop

    func_800499B0(rdram, ctx);
        goto after_1;
    // 0x80050A88: nop

    after_1:
    // 0x80050A8C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80050A90: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80050A94: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80050A98: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80050A9C: bne         $t6, $zero, L_80050AAC
    if (ctx->r14 != 0) {
        // 0x80050AA0: andi        $t7, $t5, 0x2
        ctx->r15 = ctx->r13 & 0X2;
            goto L_80050AAC;
    }
    // 0x80050AA0: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x80050AA4: beq         $t7, $zero, L_80050A80
    if (ctx->r15 == 0) {
        // 0x80050AA8: nop
    
            goto L_80050A80;
    }
    // 0x80050AA8: nop

L_80050AAC:
    // 0x80050AAC: b           L_80050AB4
    // 0x80050AB0: nop

        goto L_80050AB4;
    // 0x80050AB0: nop

L_80050AB4:
    // 0x80050AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80050AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80050ABC: jr          $ra
    // 0x80050AC0: nop

    return;
    // 0x80050AC0: nop

;}
RECOMP_FUNC void func_8006BC40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BC40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BC44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BC48: jal         0x8005F064
    // 0x8006BC4C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BC4C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x8006BC50: b           L_8006BC60
    // 0x8006BC54: nop

        goto L_8006BC60;
    // 0x8006BC54: nop

    // 0x8006BC58: b           L_8006BC60
    // 0x8006BC5C: nop

        goto L_8006BC60;
    // 0x8006BC5C: nop

L_8006BC60:
    // 0x8006BC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BC64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BC68: jr          $ra
    // 0x8006BC6C: nop

    return;
    // 0x8006BC6C: nop

;}
RECOMP_FUNC void func_8005D2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D2B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D2B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D2B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D2BC: sb          $zero, 0xD74($at)
    MEM_B(0XD74, ctx->r1) = 0;
    // 0x8005D2C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D2C4: sb          $zero, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = 0;
    // 0x8005D2C8: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x8005D2CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D2D0: sh          $t6, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r14;
    // 0x8005D2D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D2D8: sw          $zero, 0x13CC($at)
    MEM_W(0X13CC, ctx->r1) = 0;
    // 0x8005D2DC: jal         0x800BC918
    // 0x8005D2E0: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_0;
    // 0x8005D2E0: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_0:
    // 0x8005D2E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D2E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8005D2EC:
    // 0x8005D2EC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005D2F0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D2F4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005D2F8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8005D2FC: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x8005D300: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005D304: nop

    // 0x8005D308: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8005D30C: slti        $at, $t2, 0x2A
    ctx->r1 = SIGNED(ctx->r10) < 0X2A ? 1 : 0;
    // 0x8005D310: bne         $at, $zero, L_8005D2EC
    if (ctx->r1 != 0) {
        // 0x8005D314: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_8005D2EC;
    }
    // 0x8005D314: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8005D318: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D31C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005D320: sh          $t3, 0x40($t4)
    MEM_H(0X40, ctx->r12) = ctx->r11;
    // 0x8005D324: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D328: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8005D32C: sh          $t5, 0x42($t6)
    MEM_H(0X42, ctx->r14) = ctx->r13;
    // 0x8005D330: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D334: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x8005D338: sh          $t8, 0x38($t7)
    MEM_H(0X38, ctx->r15) = ctx->r24;
    // 0x8005D33C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D340: nop

    // 0x8005D344: lh          $t0, 0x38($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X38);
    // 0x8005D348: nop

    // 0x8005D34C: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x8005D350: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D354: addiu       $t1, $zero, 0x12C
    ctx->r9 = ADD32(0, 0X12C);
    // 0x8005D358: sh          $t1, 0x3A($t2)
    MEM_H(0X3A, ctx->r10) = ctx->r9;
    // 0x8005D35C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D360: nop

    // 0x8005D364: lh          $t4, 0x3A($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X3A);
    // 0x8005D368: nop

    // 0x8005D36C: sh          $t4, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r12;
    // 0x8005D370: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D374: b           L_8005D384
    // 0x8005D378: nop

        goto L_8005D384;
    // 0x8005D378: nop

    // 0x8005D37C: b           L_8005D384
    // 0x8005D380: nop

        goto L_8005D384;
    // 0x8005D380: nop

L_8005D384:
    // 0x8005D384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D388: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D38C: jr          $ra
    // 0x8005D390: nop

    return;
    // 0x8005D390: nop

;}
RECOMP_FUNC void func_800490C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800490C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800490C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800490C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800490CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800490D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800490D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800490D8: lbu         $t7, 0x7E($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X7E);
    // 0x800490DC: addiu       $t9, $t9, 0xEF8
    ctx->r25 = ADD32(ctx->r25, 0XEF8);
    // 0x800490E0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800490E4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800490E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800490EC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800490F0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800490F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800490F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800490FC: jal         0x800C0640
    // 0x80049100: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    Thread_CreateSimple(rdram, ctx);
        goto after_0;
    // 0x80049100: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_0:
    // 0x80049104: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80049108: nop

    // 0x8004910C: sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    // 0x80049110: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80049114: nop

    // 0x80049118: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x8004911C: jal         0x800C0988
    // 0x80049120: nop

    func_800C0988(rdram, ctx);
        goto after_1;
    // 0x80049120: nop

    after_1:
    // 0x80049124: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80049128: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x8004912C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80049130: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80049134: nop

    // 0x80049138: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x8004913C: jal         0x800C0E04
    // 0x80049140: nop

    Thread_GetPtr(rdram, ctx);
        goto after_2;
    // 0x80049140: nop

    after_2:
    // 0x80049144: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80049148: nop

    // 0x8004914C: sw          $v0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r2;
    // 0x80049150: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80049154: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80049158: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8004915C: nop

    // 0x80049160: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80049164: sw          $t7, 0x2F9($at)
    MEM_W(0X2F9, ctx->r1) = ctx->r15;
    // 0x80049168: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8004916C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80049170: sb          $t0, 0x20($t1)
    MEM_B(0X20, ctx->r9) = ctx->r8;
    // 0x80049174: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80049178: nop

    // 0x8004917C: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80049180: jal         0x800C0C8C
    // 0x80049184: nop

    Thread_Start(rdram, ctx);
        goto after_3;
    // 0x80049184: nop

    after_3:
    // 0x80049188: b           L_80049190
    // 0x8004918C: nop

        goto L_80049190;
    // 0x8004918C: nop

L_80049190:
    // 0x80049190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80049198: jr          $ra
    // 0x8004919C: nop

    return;
    // 0x8004919C: nop

;}
RECOMP_FUNC void func_8006D32C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D32C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D334: jal         0x80061348
    // 0x8006D338: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D338: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x8006D33C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D340: b           L_8006D350
    // 0x8006D344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D350;
    // 0x8006D344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D348: b           L_8006D350
    // 0x8006D34C: nop

        goto L_8006D350;
    // 0x8006D34C: nop

L_8006D350:
    // 0x8006D350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D358: jr          $ra
    // 0x8006D35C: nop

    return;
    // 0x8006D35C: nop

;}
RECOMP_FUNC void func_80098928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098928: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009892C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098930: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80098934: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80098938: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8009893C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80098940: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098944: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80098948: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8009894C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80098950: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80098954: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80098958: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x8009895C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80098960: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80098964: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80098968: nop

    // 0x8009896C: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80098970: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x80098974: nop

    // 0x80098978: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8009897C: bne         $t2, $zero, L_8009898C
    if (ctx->r10 != 0) {
        // 0x80098980: nop
    
            goto L_8009898C;
    }
    // 0x80098980: nop

    // 0x80098984: b           L_800989AC
    // 0x80098988: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800989AC;
    // 0x80098988: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009898C:
    // 0x8009898C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80098990: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x80098994: jal         0x800972FC
    // 0x80098998: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    func_800972FC(rdram, ctx);
        goto after_0;
    // 0x80098998: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_0:
    // 0x8009899C: b           L_800989AC
    // 0x800989A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800989AC;
    // 0x800989A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800989A4: b           L_800989AC
    // 0x800989A8: nop

        goto L_800989AC;
    // 0x800989A8: nop

L_800989AC:
    // 0x800989AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800989B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800989B4: jr          $ra
    // 0x800989B8: nop

    return;
    // 0x800989B8: nop

;}
RECOMP_FUNC void func_80028468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028468: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002846C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028470: sw          $zero, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = 0;
    // 0x80028474: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80028478: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x8002847C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028480: sw          $t6, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r14;
    // 0x80028484: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80028488: addiu       $t7, $t7, 0x2578
    ctx->r15 = ADD32(ctx->r15, 0X2578);
    // 0x8002848C: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x80028490: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80028494: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x80028498: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8002849C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_800284A0:
    // 0x800284A0: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800284A4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800284A8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x800284AC: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800284B0: nop

    // 0x800284B4: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x800284B8: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800284BC: nop

    // 0x800284C0: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x800284C4: nop

    // 0x800284C8: sw          $t3, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r11;
    // 0x800284CC: lh          $t4, 0x6($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6);
    // 0x800284D0: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x800284D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800284D8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x800284DC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800284E0: sb          $zero, -0x6550($at)
    MEM_B(-0X6550, ctx->r1) = 0;
    // 0x800284E4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800284E8: lbu         $t6, -0x6550($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6550);
    // 0x800284EC: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800284F0: nop

    // 0x800284F4: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x800284F8: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800284FC: nop

    // 0x80028500: addiu       $t9, $t8, 0x28
    ctx->r25 = ADD32(ctx->r24, 0X28);
    // 0x80028504: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x80028508: lh          $t0, 0x6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X6);
    // 0x8002850C: nop

    // 0x80028510: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80028514: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x80028518: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8002851C: slti        $at, $t2, 0x46
    ctx->r1 = SIGNED(ctx->r10) < 0X46 ? 1 : 0;
    // 0x80028520: bne         $at, $zero, L_800284A0
    if (ctx->r1 != 0) {
        // 0x80028524: sh          $t1, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r9;
            goto L_800284A0;
    }
    // 0x80028524: sh          $t1, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r9;
    // 0x80028528: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8002852C:
    // 0x8002852C: lh          $t4, 0x6($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6);
    // 0x80028530: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028534: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80028538: sb          $zero, 0x1B18($at)
    MEM_B(0X1B18, ctx->r1) = 0;
    // 0x8002853C: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x80028540: nop

    // 0x80028544: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80028548: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8002854C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80028550: slti        $at, $t8, 0x29
    ctx->r1 = SIGNED(ctx->r24) < 0X29 ? 1 : 0;
    // 0x80028554: bne         $at, $zero, L_8002852C
    if (ctx->r1 != 0) {
        // 0x80028558: sh          $t6, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r14;
            goto L_8002852C;
    }
    // 0x80028558: sh          $t6, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r14;
    // 0x8002855C: b           L_80028564
    // 0x80028560: nop

        goto L_80028564;
    // 0x80028560: nop

L_80028564:
    // 0x80028564: jr          $ra
    // 0x80028568: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80028568: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006D694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D694: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D698: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D69C: nop

    // 0x8006D6A0: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x8006D6A4: nop

    // 0x8006D6A8: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006D6AC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D6B0: jr          $ra
    // 0x8006D6B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D6B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D6B8: jr          $ra
    // 0x8006D6BC: nop

    return;
    // 0x8006D6BC: nop

    // 0x8006D6C0: jr          $ra
    // 0x8006D6C4: nop

    return;
    // 0x8006D6C4: nop

;}
RECOMP_FUNC void func_8006DC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DC2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DC30: jal         0x80061348
    // 0x8006DC34: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DC34: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x8006DC38: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DC3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DC40: beq         $v0, $zero, L_8006DC58
    if (ctx->r2 == 0) {
        // 0x8006DC44: nop
    
            goto L_8006DC58;
    }
    // 0x8006DC44: nop

    // 0x8006DC48: jal         0x80061348
    // 0x8006DC4C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DC4C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_1:
    // 0x8006DC50: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DC54: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DC58:
    // 0x8006DC58: b           L_8006DC68
    // 0x8006DC5C: nop

        goto L_8006DC68;
    // 0x8006DC5C: nop

    // 0x8006DC60: b           L_8006DC68
    // 0x8006DC64: nop

        goto L_8006DC68;
    // 0x8006DC64: nop

L_8006DC68:
    // 0x8006DC68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DC6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DC70: jr          $ra
    // 0x8006DC74: nop

    return;
    // 0x8006DC74: nop

;}
RECOMP_FUNC void func_8007683C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007683C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076844: jal         0x80061348
    // 0x80076848: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076848: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    after_0:
    // 0x8007684C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076850: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076854: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076858: beq         $v0, $zero, L_80076890
    if (ctx->r2 == 0) {
        // 0x8007685C: nop
    
            goto L_80076890;
    }
    // 0x8007685C: nop

    // 0x80076860: jal         0x80061348
    // 0x80076864: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80076864: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_1:
    // 0x80076868: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007686C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80076870: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076874: beq         $v0, $zero, L_80076890
    if (ctx->r2 == 0) {
        // 0x80076878: nop
    
            goto L_80076890;
    }
    // 0x80076878: nop

    // 0x8007687C: jal         0x80061348
    // 0x80076880: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80076880: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    after_2:
    // 0x80076884: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80076888: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007688C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80076890:
    // 0x80076890: b           L_800768A0
    // 0x80076894: nop

        goto L_800768A0;
    // 0x80076894: nop

    // 0x80076898: b           L_800768A0
    // 0x8007689C: nop

        goto L_800768A0;
    // 0x8007689C: nop

L_800768A0:
    // 0x800768A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800768A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800768A8: jr          $ra
    // 0x800768AC: nop

    return;
    // 0x800768AC: nop

;}
RECOMP_FUNC void alFilterNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D56B0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800D56B4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800D56B8: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800D56BC: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x800D56C0: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x800D56C4: jr          $ra
    // 0x800D56C8: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x800D56C8: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_8006CB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CB2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB30: jal         0x8005F064
    // 0x8006CB34: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CB34: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_0:
    // 0x8006CB38: b           L_8006CB48
    // 0x8006CB3C: nop

        goto L_8006CB48;
    // 0x8006CB3C: nop

    // 0x8006CB40: b           L_8006CB48
    // 0x8006CB44: nop

        goto L_8006CB48;
    // 0x8006CB44: nop

L_8006CB48:
    // 0x8006CB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CB4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CB50: jr          $ra
    // 0x8006CB54: nop

    return;
    // 0x8006CB54: nop

;}
RECOMP_FUNC void func_800735C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800735C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800735CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800735D0: jal         0x80061488
    // 0x800735D4: addiu       $a0, $zero, 0x643
    ctx->r4 = ADD32(0, 0X643);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800735D4: addiu       $a0, $zero, 0x643
    ctx->r4 = ADD32(0, 0X643);
    after_0:
    // 0x800735D8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800735DC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800735E0: b           L_800735F0
    // 0x800735E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800735F0;
    // 0x800735E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800735E8: b           L_800735F0
    // 0x800735EC: nop

        goto L_800735F0;
    // 0x800735EC: nop

L_800735F0:
    // 0x800735F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800735F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800735F8: jr          $ra
    // 0x800735FC: nop

    return;
    // 0x800735FC: nop

;}
RECOMP_FUNC void func_80077284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007728C: jal         0x80061488
    // 0x80077290: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077290: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x80077294: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077298: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007729C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800772A0: beq         $v0, $zero, L_800772C8
    if (ctx->r2 == 0) {
        // 0x800772A4: nop
    
            goto L_800772C8;
    }
    // 0x800772A4: nop

    // 0x800772A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800772AC: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800772B0: nop

    // 0x800772B4: lh          $v0, 0x30($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X30);
    // 0x800772B8: nop

    // 0x800772BC: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800772C0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800772C4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800772C8:
    // 0x800772C8: b           L_800772D8
    // 0x800772CC: nop

        goto L_800772D8;
    // 0x800772CC: nop

    // 0x800772D0: b           L_800772D8
    // 0x800772D4: nop

        goto L_800772D8;
    // 0x800772D4: nop

L_800772D8:
    // 0x800772D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800772DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800772E0: jr          $ra
    // 0x800772E4: nop

    return;
    // 0x800772E4: nop

;}
RECOMP_FUNC void func_800198F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800198F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800198FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019900: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80019904: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80019908: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001990C: jal         0x80099E2C
    // 0x80019910: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x80019910: nop

    after_0:
    // 0x80019914: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80019918: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8001991C: sh          $t6, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r14;
    // 0x80019920: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80019924: nop

    // 0x80019928: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x8001992C: nop

    // 0x80019930: ori         $t0, $t9, 0x1108
    ctx->r8 = ctx->r25 | 0X1108;
    // 0x80019934: sw          $t0, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r8;
    // 0x80019938: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001993C: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80019940: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
    // 0x80019944: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80019948: nop

    // 0x8001994C: bne         $t3, $zero, L_80019980
    if (ctx->r11 != 0) {
        // 0x80019950: nop
    
            goto L_80019980;
    }
    // 0x80019950: nop

    // 0x80019954: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x80019958: jal         0x800BC6EC
    // 0x8001995C: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8001995C: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    after_1:
    // 0x80019960: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80019964: nop

    // 0x80019968: sw          $v0, 0x12C($t4)
    MEM_W(0X12C, ctx->r12) = ctx->r2;
    // 0x8001996C: jal         0x800BC6EC
    // 0x80019970: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80019970: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    after_2:
    // 0x80019974: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80019978: b           L_800199C4
    // 0x8001997C: sw          $v0, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r2;
        goto L_800199C4;
    // 0x8001997C: sw          $v0, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r2;
L_80019980:
    // 0x80019980: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80019984: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019988: bne         $t6, $at, L_800199BC
    if (ctx->r14 != ctx->r1) {
        // 0x8001998C: nop
    
            goto L_800199BC;
    }
    // 0x8001998C: nop

    // 0x80019990: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x80019994: jal         0x800BC918
    // 0x80019998: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_3;
    // 0x80019998: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    after_3:
    // 0x8001999C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800199A0: nop

    // 0x800199A4: sw          $v0, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->r2;
    // 0x800199A8: jal         0x800BC918
    // 0x800199AC: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_4;
    // 0x800199AC: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    after_4:
    // 0x800199B0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800199B4: b           L_800199C4
    // 0x800199B8: sw          $v0, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r2;
        goto L_800199C4;
    // 0x800199B8: sw          $v0, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r2;
L_800199BC:
    // 0x800199BC: b           L_80019C10
    // 0x800199C0: nop

        goto L_80019C10;
    // 0x800199C0: nop

L_800199C4:
    // 0x800199C4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800199C8: nop

    // 0x800199CC: lw          $t8, 0x12C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X12C);
    // 0x800199D0: nop

    // 0x800199D4: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800199D8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800199DC: lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
    // 0x800199E0: lw          $t2, 0x12C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12C);
    // 0x800199E4: ori         $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 | 0X7FFF;
    // 0x800199E8: addiu       $a0, $t2, 0x1
    ctx->r4 = ADD32(ctx->r10, 0X1);
    // 0x800199EC: jal         0x800BCFCC
    // 0x800199F0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x800199F0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_5:
    // 0x800199F4: jal         0x800C4160
    // 0x800199F8: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_6;
    // 0x800199F8: nop

    after_6:
    // 0x800199FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80019A00: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80019A04: nop

    // 0x80019A08: lw          $t4, 0x12C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X12C);
    // 0x80019A0C: nop

    // 0x80019A10: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80019A14: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80019A18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019A1C: sltu        $at, $t5, $at
    ctx->r1 = ctx->r13 < ctx->r1 ? 1 : 0;
    // 0x80019A20: bne         $at, $zero, L_80019A38
    if (ctx->r1 != 0) {
        // 0x80019A24: nop
    
            goto L_80019A38;
    }
    // 0x80019A24: nop

    // 0x80019A28: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x80019A2C: sltu        $at, $t5, $at
    ctx->r1 = ctx->r13 < ctx->r1 ? 1 : 0;
    // 0x80019A30: bne         $at, $zero, L_80019A44
    if (ctx->r1 != 0) {
        // 0x80019A34: nop
    
            goto L_80019A44;
    }
    // 0x80019A34: nop

L_80019A38:
    // 0x80019A38: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80019A3C: nop

    // 0x80019A40: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80019A44:
    // 0x80019A44: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80019A48: nop

    // 0x80019A4C: lw          $t9, 0x128($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X128);
    // 0x80019A50: nop

    // 0x80019A54: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80019A58: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80019A5C:
    // 0x80019A5C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80019A60:
    // 0x80019A60: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80019A64: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80019A68: sll         $t8, $t0, 6
    ctx->r24 = S32(ctx->r8 << 6);
    // 0x80019A6C: addiu       $t1, $t8, -0xA0
    ctx->r9 = ADD32(ctx->r24, -0XA0);
    // 0x80019A70: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80019A74: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80019A78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80019A7C: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80019A80: addiu       $t5, $t4, -0x78
    ctx->r13 = ADD32(ctx->r12, -0X78);
    // 0x80019A84: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80019A88: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80019A8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019A90: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80019A94: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80019A98: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80019A9C: nop

    // 0x80019AA0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80019AA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80019AA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80019AAC: nop

    // 0x80019AB0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80019AB4: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80019AB8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80019ABC: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80019AC0: nop

    // 0x80019AC4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80019AC8: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x80019ACC: sh          $t0, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r8;
    // 0x80019AD0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80019AD4: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80019AD8: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    // 0x80019ADC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80019AE0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80019AE4: nop

    // 0x80019AE8: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x80019AEC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80019AF0: nop

    // 0x80019AF4: addiu       $t6, $t5, 0xC
    ctx->r14 = ADD32(ctx->r13, 0XC);
    // 0x80019AF8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80019AFC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80019B00:
    // 0x80019B00: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80019B04: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80019B08: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x80019B0C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x80019B10: slti        $at, $t8, 0xF0
    ctx->r1 = SIGNED(ctx->r24) < 0XF0 ? 1 : 0;
    // 0x80019B14: bne         $at, $zero, L_80019B24
    if (ctx->r1 != 0) {
        // 0x80019B18: nop
    
            goto L_80019B24;
    }
    // 0x80019B18: nop

    // 0x80019B1C: b           L_80019BC0
    // 0x80019B20: nop

        goto L_80019BC0;
    // 0x80019B20: nop

L_80019B24:
    // 0x80019B24: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80019B28:
    // 0x80019B28: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80019B2C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80019B30: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80019B34: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80019B38: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80019B3C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80019B40: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80019B44: sll         $t5, $t5, 6
    ctx->r13 = S32(ctx->r13 << 6);
    // 0x80019B48: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x80019B4C: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80019B50: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80019B54: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x80019B58: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x80019B5C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80019B60: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80019B64: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x80019B68: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80019B6C: addu        $t2, $t4, $t3
    ctx->r10 = ADD32(ctx->r12, ctx->r11);
    // 0x80019B70: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x80019B74: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80019B78: nop

    // 0x80019B7C: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80019B80: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019B84: nop

    // 0x80019B88: addiu       $t0, $t7, 0x2
    ctx->r8 = ADD32(ctx->r15, 0X2);
    // 0x80019B8C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80019B90: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80019B94: nop

    // 0x80019B98: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80019B9C: slti        $at, $t8, 0x40
    ctx->r1 = SIGNED(ctx->r24) < 0X40 ? 1 : 0;
    // 0x80019BA0: bne         $at, $zero, L_80019B28
    if (ctx->r1 != 0) {
        // 0x80019BA4: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_80019B28;
    }
    // 0x80019BA4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80019BA8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80019BAC: nop

    // 0x80019BB0: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x80019BB4: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x80019BB8: bne         $at, $zero, L_80019B00
    if (ctx->r1 != 0) {
        // 0x80019BBC: sw          $t4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r12;
            goto L_80019B00;
    }
    // 0x80019BBC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_80019BC0:
    // 0x80019BC0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80019BC4: nop

    // 0x80019BC8: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80019BCC: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x80019BD0: bne         $at, $zero, L_80019A60
    if (ctx->r1 != 0) {
        // 0x80019BD4: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_80019A60;
    }
    // 0x80019BD4: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80019BD8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80019BDC: nop

    // 0x80019BE0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80019BE4: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80019BE8: bne         $at, $zero, L_80019A5C
    if (ctx->r1 != 0) {
        // 0x80019BEC: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_80019A5C;
    }
    // 0x80019BEC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80019BF0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80019BF4: addiu       $t7, $zero, -0x8000
    ctx->r15 = ADD32(0, -0X8000);
    // 0x80019BF8: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x80019BFC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80019C00: addiu       $t9, $zero, -0x8000
    ctx->r25 = ADD32(0, -0X8000);
    // 0x80019C04: sh          $t9, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r25;
    // 0x80019C08: b           L_80019C10
    // 0x80019C0C: nop

        goto L_80019C10;
    // 0x80019C0C: nop

L_80019C10:
    // 0x80019C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019C14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80019C18: jr          $ra
    // 0x80019C1C: nop

    return;
    // 0x80019C1C: nop

;}
RECOMP_FUNC void func_800178D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800178D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800178D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800178DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800178E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800178E4: jal         0x80016074
    // 0x800178E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800178E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800178EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800178F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800178F4: nop

    // 0x800178F8: bne         $t6, $zero, L_80017908
    if (ctx->r14 != 0) {
        // 0x800178FC: nop
    
            goto L_80017908;
    }
    // 0x800178FC: nop

    // 0x80017900: b           L_80017A10
    // 0x80017904: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80017A10;
    // 0x80017904: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017908:
    // 0x80017908: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8001790C: nop

    // 0x80017910: sw          $zero, 0x150($t7)
    MEM_W(0X150, ctx->r15) = 0;
    // 0x80017914: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80017918: nop

    // 0x8001791C: bgez        $t8, L_80017928
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80017920: nop
    
            goto L_80017928;
    }
    // 0x80017920: nop

    // 0x80017924: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
L_80017928:
    // 0x80017928: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8001792C: nop

    // 0x80017930: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80017934: bne         $at, $zero, L_80017944
    if (ctx->r1 != 0) {
        // 0x80017938: nop
    
            goto L_80017944;
    }
    // 0x80017938: nop

    // 0x8001793C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80017940: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
L_80017944:
    // 0x80017944: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80017948: nop

    // 0x8001794C: sh          $zero, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = 0;
    // 0x80017950: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x80017954: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80017958: nop

    // 0x8001795C: sh          $t2, 0x120($t3)
    MEM_H(0X120, ctx->r11) = ctx->r10;
    // 0x80017960: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80017964: nop

    // 0x80017968: lw          $t5, 0x210($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X210);
    // 0x8001796C: nop

    // 0x80017970: bne         $t5, $zero, L_80017988
    if (ctx->r13 != 0) {
        // 0x80017974: nop
    
            goto L_80017988;
    }
    // 0x80017974: nop

    // 0x80017978: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001797C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80017980: b           L_80017A00
    // 0x80017984: sw          $t6, 0x210($t7)
    MEM_W(0X210, ctx->r15) = ctx->r14;
        goto L_80017A00;
    // 0x80017984: sw          $t6, 0x210($t7)
    MEM_W(0X210, ctx->r15) = ctx->r14;
L_80017988:
    // 0x80017988: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001798C: nop

    // 0x80017990: lw          $t9, 0x210($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X210);
    // 0x80017994: nop

    // 0x80017998: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8001799C: lw          $t0, 0x150($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X150);
    // 0x800179A0: nop

    // 0x800179A4: beq         $t0, $zero, L_800179F0
    if (ctx->r8 == 0) {
        // 0x800179A8: nop
    
            goto L_800179F0;
    }
    // 0x800179A8: nop

L_800179AC:
    // 0x800179AC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800179B0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800179B4: lw          $t2, 0x150($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X150);
    // 0x800179B8: nop

    // 0x800179BC: bne         $t2, $t3, L_800179CC
    if (ctx->r10 != ctx->r11) {
        // 0x800179C0: nop
    
            goto L_800179CC;
    }
    // 0x800179C0: nop

    // 0x800179C4: b           L_80017A10
    // 0x800179C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80017A10;
    // 0x800179C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800179CC:
    // 0x800179CC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800179D0: nop

    // 0x800179D4: lw          $t5, 0x150($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X150);
    // 0x800179D8: nop

    // 0x800179DC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800179E0: lw          $t6, 0x150($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X150);
    // 0x800179E4: nop

    // 0x800179E8: bne         $t6, $zero, L_800179AC
    if (ctx->r14 != 0) {
        // 0x800179EC: nop
    
            goto L_800179AC;
    }
    // 0x800179EC: nop

L_800179F0:
    // 0x800179F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800179F4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800179F8: nop

    // 0x800179FC: sw          $t7, 0x150($t8)
    MEM_W(0X150, ctx->r24) = ctx->r15;
L_80017A00:
    // 0x80017A00: b           L_80017A10
    // 0x80017A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017A10;
    // 0x80017A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017A08: b           L_80017A10
    // 0x80017A0C: nop

        goto L_80017A10;
    // 0x80017A0C: nop

L_80017A10:
    // 0x80017A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017A14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017A18: jr          $ra
    // 0x80017A1C: nop

    return;
    // 0x80017A1C: nop

;}
