#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800294D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800294D4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800294D8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800294DC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800294E0: beq         $a0, $at, L_80029518
    if (ctx->r4 == ctx->r1) {
        // 0x800294E4: nop
    
            goto L_80029518;
    }
    // 0x800294E4: nop

    // 0x800294E8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x800294EC: beq         $a0, $at, L_80029518
    if (ctx->r4 == ctx->r1) {
        // 0x800294F0: nop
    
            goto L_80029518;
    }
    // 0x800294F0: nop

    // 0x800294F4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800294F8: beq         $a0, $at, L_80029518
    if (ctx->r4 == ctx->r1) {
        // 0x800294FC: nop
    
            goto L_80029518;
    }
    // 0x800294FC: nop

    // 0x80029500: slti        $at, $a0, 0x24
    ctx->r1 = SIGNED(ctx->r4) < 0X24 ? 1 : 0;
    // 0x80029504: bne         $at, $zero, L_80029520
    if (ctx->r1 != 0) {
        // 0x80029508: nop
    
            goto L_80029520;
    }
    // 0x80029508: nop

    // 0x8002950C: slti        $at, $a0, 0x28
    ctx->r1 = SIGNED(ctx->r4) < 0X28 ? 1 : 0;
    // 0x80029510: beq         $at, $zero, L_80029520
    if (ctx->r1 == 0) {
        // 0x80029514: nop
    
            goto L_80029520;
    }
    // 0x80029514: nop

L_80029518:
    // 0x80029518: jr          $ra
    // 0x8002951C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x8002951C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80029520:
    // 0x80029520: jr          $ra
    // 0x80029524: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x80029524: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
;}
RECOMP_FUNC void SysMem_Bcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD180: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD184: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BD188: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BD18C: blez        $a2, L_800BD1E4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BD190: nop
    
            goto L_800BD1E4;
    }
    // 0x800BD190: nop

L_800BD194:
    // 0x800BD194: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BD198: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BD19C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD1A0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800BD1A4: nop

    // 0x800BD1A8: beq         $t7, $t9, L_800BD1B8
    if (ctx->r15 == ctx->r25) {
        // 0x800BD1AC: nop
    
            goto L_800BD1B8;
    }
    // 0x800BD1AC: nop

    // 0x800BD1B0: b           L_800BD1E4
    // 0x800BD1B4: nop

        goto L_800BD1E4;
    // 0x800BD1B4: nop

L_800BD1B8:
    // 0x800BD1B8: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800BD1BC: nop

    // 0x800BD1C0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BD1C4: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800BD1C8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BD1CC: nop

    // 0x800BD1D0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800BD1D4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800BD1D8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD1DC: bgtz        $a2, L_800BD194
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD1E0: nop
    
            goto L_800BD194;
    }
    // 0x800BD1E0: nop

L_800BD1E4:
    // 0x800BD1E4: b           L_800BD1F4
    // 0x800BD1E8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800BD1F4;
    // 0x800BD1E8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800BD1EC: b           L_800BD1F4
    // 0x800BD1F0: nop

        goto L_800BD1F4;
    // 0x800BD1F0: nop

L_800BD1F4:
    // 0x800BD1F4: jr          $ra
    // 0x800BD1F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD1F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80071BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071BAC: jal         0x80061348
    // 0x80071BB0: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071BB0: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    after_0:
    // 0x80071BB4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071BB8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071BBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071BC0: beq         $v0, $zero, L_80071BDC
    if (ctx->r2 == 0) {
        // 0x80071BC4: nop
    
            goto L_80071BDC;
    }
    // 0x80071BC4: nop

    // 0x80071BC8: jal         0x80061348
    // 0x80071BCC: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071BCC: addiu       $a0, $zero, 0x444
    ctx->r4 = ADD32(0, 0X444);
    after_1:
    // 0x80071BD0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071BD4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071BD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80071BDC:
    // 0x80071BDC: b           L_80071BEC
    // 0x80071BE0: nop

        goto L_80071BEC;
    // 0x80071BE0: nop

    // 0x80071BE4: b           L_80071BEC
    // 0x80071BE8: nop

        goto L_80071BEC;
    // 0x80071BE8: nop

L_80071BEC:
    // 0x80071BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071BF4: jr          $ra
    // 0x80071BF8: nop

    return;
    // 0x80071BF8: nop

;}
RECOMP_FUNC void func_8006E9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E9AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E9B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E9B4: jal         0x80061348
    // 0x8006E9B8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E9B8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E9BC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006E9C0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006E9C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E9C8: beq         $v0, $zero, L_8006E9E4
    if (ctx->r2 == 0) {
        // 0x8006E9CC: nop
    
            goto L_8006E9E4;
    }
    // 0x8006E9CC: nop

    // 0x8006E9D0: jal         0x80061348
    // 0x8006E9D4: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E9D4: addiu       $a0, $zero, 0x2C8
    ctx->r4 = ADD32(0, 0X2C8);
    after_1:
    // 0x8006E9D8: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006E9DC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006E9E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E9E4:
    // 0x8006E9E4: b           L_8006E9F4
    // 0x8006E9E8: nop

        goto L_8006E9F4;
    // 0x8006E9E8: nop

    // 0x8006E9EC: b           L_8006E9F4
    // 0x8006E9F0: nop

        goto L_8006E9F4;
    // 0x8006E9F0: nop

L_8006E9F4:
    // 0x8006E9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E9F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E9FC: jr          $ra
    // 0x8006EA00: nop

    return;
    // 0x8006EA00: nop

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
RECOMP_FUNC void func_800BB578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB578: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800BB57C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800BB580: lw          $t7, -0x7304($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7304);
    // 0x800BB584: lw          $t6, -0x7310($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7310);
    // 0x800BB588: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800BB58C: lw          $t9, -0x730C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X730C);
    // 0x800BB590: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800BB594: jr          $ra
    // 0x800BB598: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    return;
    // 0x800BB598: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
    // 0x800BB59C: jr          $ra
    // 0x800BB5A0: nop

    return;
    // 0x800BB5A0: nop

    // 0x800BB5A4: jr          $ra
    // 0x800BB5A8: nop

    return;
    // 0x800BB5A8: nop

;}
RECOMP_FUNC void func_80075B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075B94: jal         0x8005F064
    // 0x80075B98: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80075B98: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_0:
    // 0x80075B9C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80075BA0: b           L_80075BB0
    // 0x80075BA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80075BB0;
    // 0x80075BA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075BA8: b           L_80075BB0
    // 0x80075BAC: nop

        goto L_80075BB0;
    // 0x80075BAC: nop

L_80075BB0:
    // 0x80075BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075BB8: jr          $ra
    // 0x80075BBC: nop

    return;
    // 0x80075BBC: nop

;}
RECOMP_FUNC void func_8006F6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F6FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F700: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F704: nop

    // 0x8006F708: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x8006F70C: nop

    // 0x8006F710: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F714: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F718: jr          $ra
    // 0x8006F71C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F71C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F720: jr          $ra
    // 0x8006F724: nop

    return;
    // 0x8006F724: nop

    // 0x8006F728: jr          $ra
    // 0x8006F72C: nop

    return;
    // 0x8006F72C: nop

;}
RECOMP_FUNC void LoadPalette(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B53A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B53A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B53A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B53AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B53B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B53B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B53B8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B53BC: lhu         $t8, 0x32($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X32);
    // 0x800B53C0: lhu         $t7, 0x12($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X12);
    // 0x800B53C4: nop

    // 0x800B53C8: beq         $t7, $t8, L_800B5540
    if (ctx->r15 == ctx->r24) {
        // 0x800B53CC: nop
    
            goto L_800B5540;
    }
    // 0x800B53CC: nop

    // 0x800B53D0: lhu         $t9, 0x32($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X32);
    // 0x800B53D4: nop

    // 0x800B53D8: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800B53DC: bne         $t0, $zero, L_800B5500
    if (ctx->r8 != 0) {
        // 0x800B53E0: nop
    
            goto L_800B5500;
    }
    // 0x800B53E0: nop

    // 0x800B53E4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B53E8: nop

    // 0x800B53EC: lbu         $t2, 0x3D($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X3D);
    // 0x800B53F0: nop

    // 0x800B53F4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B53F8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800B53FC: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x800B5400: nop

    // 0x800B5404: beq         $t5, $zero, L_800B5430
    if (ctx->r13 == 0) {
        // 0x800B5408: nop
    
            goto L_800B5430;
    }
    // 0x800B5408: nop

    // 0x800B540C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5410: nop

    // 0x800B5414: lbu         $t7, 0x3D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3D);
    // 0x800B5418: nop

    // 0x800B541C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B5420: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B5424: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x800B5428: jal         0x800BC980
    // 0x800B542C: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800B542C: nop

    after_0:
L_800B5430:
    // 0x800B5430: jal         0x800BC6EC
    // 0x800B5434: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800B5434: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_1:
    // 0x800B5438: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B543C: nop

    // 0x800B5440: lbu         $t2, 0x3D($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X3D);
    // 0x800B5444: nop

    // 0x800B5448: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x800B544C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800B5450: sw          $v0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r2;
    // 0x800B5454: lhu         $t4, 0x32($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X32);
    // 0x800B5458: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B545C: lw          $t7, 0xD48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD48);
    // 0x800B5460: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B5464: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B5468: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B546C: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B5470: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x800B5474: jal         0x800BD1FC
    // 0x800B5478: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B5478: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    after_2:
    // 0x800B547C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5480: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B5484: lbu         $t8, 0x3D($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X3D);
    // 0x800B5488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B548C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B5490: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x800B5494: lw          $a1, 0x14($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X14);
    // 0x800B5498: jal         0x800BD218
    // 0x800B549C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B549C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_3:
    // 0x800B54A0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B54A4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800B54A8: lbu         $t1, 0x3D($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3D);
    // 0x800B54AC: nop

    // 0x800B54B0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800B54B4: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800B54B8: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x800B54BC: nop

    // 0x800B54C0: sw          $t5, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r13;
    // 0x800B54C4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B54C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B54CC: lbu         $t6, 0x3D($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X3D);
    // 0x800B54D0: nop

    // 0x800B54D4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800B54D8: sb          $t9, 0x3D($t8)
    MEM_B(0X3D, ctx->r24) = ctx->r25;
    // 0x800B54DC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B54E0: nop

    // 0x800B54E4: lbu         $t1, 0x3D($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X3D);
    // 0x800B54E8: nop

    // 0x800B54EC: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800B54F0: mfhi        $t0
    ctx->r8 = hi;
    // 0x800B54F4: sb          $t0, 0x3D($t2)
    MEM_B(0X3D, ctx->r10) = ctx->r8;
    // 0x800B54F8: b           L_800B5530
    // 0x800B54FC: nop

        goto L_800B5530;
    // 0x800B54FC: nop

L_800B5500:
    // 0x800B5500: lhu         $t5, 0x32($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X32);
    // 0x800B5504: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800B5508: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800B550C: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x800B5510: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800B5514: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800B5518: lw          $t4, 0x138($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X138);
    // 0x800B551C: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800B5520: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B5524: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800B5528: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x800B552C: sw          $t8, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->r24;
L_800B5530:
    // 0x800B5530: lhu         $t0, 0x32($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X32);
    // 0x800B5534: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5538: nop

    // 0x800B553C: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
L_800B5540:
    // 0x800B5540: b           L_800B5548
    // 0x800B5544: nop

        goto L_800B5548;
    // 0x800B5544: nop

L_800B5548:
    // 0x800B5548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B554C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5550: jr          $ra
    // 0x800B5554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B5554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800782A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800782A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800782AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800782B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800782B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800782B8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800782BC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800782C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800782C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800782C8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800782CC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800782D0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800782D4: nop

    // 0x800782D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800782DC: nop

    // 0x800782E0: bc1f        L_80078304
    if (!c1cs) {
        // 0x800782E4: nop
    
            goto L_80078304;
    }
    // 0x800782E4: nop

    // 0x800782E8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800782EC: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800782F0: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x800782F4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800782F8: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x800782FC: b           L_8007831C
    // 0x80078300: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
        goto L_8007831C;
    // 0x80078300: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
L_80078304:
    // 0x80078304: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80078308: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x8007830C: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80078310: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80078314: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x80078318: swc1        $f18, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f18.u32l;
L_8007831C:
    // 0x8007831C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80078320: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80078324: nop

    // 0x80078328: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8007832C: nop

    // 0x80078330: bc1f        L_80078354
    if (!c1cs) {
        // 0x80078334: nop
    
            goto L_80078354;
    }
    // 0x80078334: nop

    // 0x80078338: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007833C: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x80078340: swc1        $f8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f8.u32l;
    // 0x80078344: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80078348: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x8007834C: b           L_8007836C
    // 0x80078350: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
        goto L_8007836C;
    // 0x80078350: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
L_80078354:
    // 0x80078354: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80078358: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x8007835C: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x80078360: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80078364: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x80078368: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
L_8007836C:
    // 0x8007836C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80078370: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80078374: nop

    // 0x80078378: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007837C: nop

    // 0x80078380: bne         $t7, $zero, L_80078390
    if (ctx->r15 != 0) {
        // 0x80078384: nop
    
            goto L_80078390;
    }
    // 0x80078384: nop

    // 0x80078388: b           L_800783DC
    // 0x8007838C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800783DC;
    // 0x8007838C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80078390:
    // 0x80078390: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80078394: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80078398: lhu         $t8, 0x4E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4E);
    // 0x8007839C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800783A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800783A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800783A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800783AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800783B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800783B4: jal         0x80078628
    // 0x800783B8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80078628(rdram, ctx);
        goto after_0;
    // 0x800783B8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x800783BC: bne         $v0, $zero, L_800783CC
    if (ctx->r2 != 0) {
        // 0x800783C0: nop
    
            goto L_800783CC;
    }
    // 0x800783C0: nop

    // 0x800783C4: b           L_800783DC
    // 0x800783C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800783DC;
    // 0x800783C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800783CC:
    // 0x800783CC: b           L_800783DC
    // 0x800783D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800783DC;
    // 0x800783D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800783D4: b           L_800783DC
    // 0x800783D8: nop

        goto L_800783DC;
    // 0x800783D8: nop

L_800783DC:
    // 0x800783DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800783E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800783E4: jr          $ra
    // 0x800783E8: nop

    return;
    // 0x800783E8: nop

;}
RECOMP_FUNC void func_800296FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800296FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80029700: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80029704: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80029708: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002970C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80029710: nop

    // 0x80029714: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80029718: nop

    // 0x8002971C: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x80029720: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
L_80029724:
    // 0x80029724: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x80029728: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8002972C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80029730: lbu         $t9, 0x1B0C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1B0C);
    // 0x80029734: nop

    // 0x80029738: bne         $t9, $zero, L_80029748
    if (ctx->r25 != 0) {
        // 0x8002973C: nop
    
            goto L_80029748;
    }
    // 0x8002973C: nop

    // 0x80029740: b           L_80029768
    // 0x80029744: nop

        goto L_80029768;
    // 0x80029744: nop

L_80029748:
    // 0x80029748: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x8002974C: nop

    // 0x80029750: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80029754: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80029758: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8002975C: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80029760: bne         $at, $zero, L_80029724
    if (ctx->r1 != 0) {
        // 0x80029764: sh          $t1, 0x36($sp)
        MEM_H(0X36, ctx->r29) = ctx->r9;
            goto L_80029724;
    }
    // 0x80029764: sh          $t1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r9;
L_80029768:
    // 0x80029768: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x8002976C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029770: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80029774: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80029778: sb          $t4, 0x1B0C($at)
    MEM_B(0X1B0C, ctx->r1) = ctx->r12;
    // 0x8002977C: lh          $t6, 0x36($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X36);
    // 0x80029780: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80029784: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80029788: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002978C: lw          $t8, 0x24F0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X24F0);
    // 0x80029790: nop

    // 0x80029794: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80029798: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002979C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800297A0: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800297A4: nop

    // 0x800297A8: swc1        $f4, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f4.u32l;
    // 0x800297AC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800297B0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800297B4: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800297B8: nop

    // 0x800297BC: swc1        $f6, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f6.u32l;
    // 0x800297C0: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x800297C4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800297C8: nop

    // 0x800297CC: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
    // 0x800297D0: lh          $a0, 0x34($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X34);
    // 0x800297D4: jal         0x800294D4
    // 0x800297D8: nop

    func_800294D4(rdram, ctx);
        goto after_0;
    // 0x800297D8: nop

    after_0:
    // 0x800297DC: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // 0x800297E0: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x800297E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800297E8: lwc1        $f8, -0x69E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X69E8);
    // 0x800297EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800297F0: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800297F4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800297F8: swc1        $f8, 0x24D8($at)
    MEM_W(0X24D8, ctx->r1) = ctx->f8.u32l;
    // 0x800297FC: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x80029800: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029804: lwc1        $f10, -0x69E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x80029808: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002980C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80029810: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80029814: swc1        $f10, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->f10.u32l;
    // 0x80029818: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x8002981C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029820: lwc1        $f16, -0x69E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X69E0);
    // 0x80029824: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029828: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8002982C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80029830: swc1        $f16, 0x24E0($at)
    MEM_W(0X24E0, ctx->r1) = ctx->f16.u32l;
    // 0x80029834: lh          $t3, 0x34($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X34);
    // 0x80029838: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002983C: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80029840: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x80029844: lh          $t1, 0x36($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X36);
    // 0x80029848: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002984C: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80029850: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80029854: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80029858: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002985C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80029860: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80029864: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80029868: ori         $t5, $a2, 0x143
    ctx->r13 = ctx->r6 | 0X143;
    // 0x8002986C: lw          $a1, 0x24F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X24F4);
    // 0x80029870: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80029874: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x80029878: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8002987C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80029880: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80029884: jal         0x800B1F0C
    // 0x80029888: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_1;
    // 0x80029888: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8002988C: b           L_80029894
    // 0x80029890: nop

        goto L_80029894;
    // 0x80029890: nop

L_80029894:
    // 0x80029894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80029898: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002989C: jr          $ra
    // 0x800298A0: nop

    return;
    // 0x800298A0: nop

;}
RECOMP_FUNC void func_80068D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068D48: jal         0x80061488
    // 0x80068D4C: addiu       $a0, $zero, 0xED
    ctx->r4 = ADD32(0, 0XED);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068D4C: addiu       $a0, $zero, 0xED
    ctx->r4 = ADD32(0, 0XED);
    after_0:
    // 0x80068D50: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068D54: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068D58: b           L_80068D68
    // 0x80068D5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068D68;
    // 0x80068D5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068D60: b           L_80068D68
    // 0x80068D64: nop

        goto L_80068D68;
    // 0x80068D64: nop

L_80068D68:
    // 0x80068D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068D70: jr          $ra
    // 0x80068D74: nop

    return;
    // 0x80068D74: nop

;}
RECOMP_FUNC void func_8006EEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EEE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EEF0: jal         0x80061348
    // 0x8006EEF4: addiu       $a0, $zero, 0x153
    ctx->r4 = ADD32(0, 0X153);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EEF4: addiu       $a0, $zero, 0x153
    ctx->r4 = ADD32(0, 0X153);
    after_0:
    // 0x8006EEF8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EEFC: b           L_8006EF0C
    // 0x8006EF00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EF0C;
    // 0x8006EF00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EF04: b           L_8006EF0C
    // 0x8006EF08: nop

        goto L_8006EF0C;
    // 0x8006EF08: nop

L_8006EF0C:
    // 0x8006EF0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EF14: jr          $ra
    // 0x8006EF18: nop

    return;
    // 0x8006EF18: nop

;}
RECOMP_FUNC void func_80073634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073634: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073638: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007363C: nop

    // 0x80073640: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073644: nop

    // 0x80073648: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007364C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073650: jr          $ra
    // 0x80073654: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073654: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073658: jr          $ra
    // 0x8007365C: nop

    return;
    // 0x8007365C: nop

    // 0x80073660: jr          $ra
    // 0x80073664: nop

    return;
    // 0x80073664: nop

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
RECOMP_FUNC void func_80028A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028A20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028A28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80028A2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80028A30: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80028A34: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80028A38: nop

    // 0x80028A3C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80028A40: nop

    // 0x80028A44: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80028A48: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80028A4C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80028A50: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80028A54: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80028A58: nop

    // 0x80028A5C: beq         $t9, $at, L_80028B5C
    if (ctx->r25 == ctx->r1) {
        // 0x80028A60: nop
    
            goto L_80028B5C;
    }
    // 0x80028A60: nop

    // 0x80028A64: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80028A68: nop

    // 0x80028A6C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80028A70: nop

    // 0x80028A74: beq         $t1, $zero, L_80028B54
    if (ctx->r9 == 0) {
        // 0x80028A78: sb          $t1, 0x2D($sp)
        MEM_B(0X2D, ctx->r29) = ctx->r9;
            goto L_80028B54;
    }
    // 0x80028A78: sb          $t1, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r9;
L_80028A7C:
    // 0x80028A7C: lbu         $t2, 0x2D($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2D);
    // 0x80028A80: nop

    // 0x80028A84: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x80028A88: beq         $t3, $zero, L_80028AA8
    if (ctx->r11 == 0) {
        // 0x80028A8C: nop
    
            goto L_80028AA8;
    }
    // 0x80028A8C: nop

    // 0x80028A90: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80028A94: nop

    // 0x80028A98: beq         $t4, $zero, L_80028AA8
    if (ctx->r12 == 0) {
        // 0x80028A9C: nop
    
            goto L_80028AA8;
    }
    // 0x80028A9C: nop

    // 0x80028AA0: b           L_80028B54
    // 0x80028AA4: nop

        goto L_80028B54;
    // 0x80028AA4: nop

L_80028AA8:
    // 0x80028AA8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80028AAC: sh          $t5, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r13;
    // 0x80028AB0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80028AB4: nop

    // 0x80028AB8: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80028ABC: nop

    // 0x80028AC0: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x80028AC4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80028AC8: sb          $t7, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r15;
    // 0x80028ACC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028AD0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80028AD4: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x80028AD8: nop

    // 0x80028ADC: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x80028AE0: beq         $t0, $zero, L_80028B04
    if (ctx->r8 == 0) {
        // 0x80028AE4: nop
    
            goto L_80028B04;
    }
    // 0x80028AE4: nop

    // 0x80028AE8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80028AEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80028AF0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80028AF4: nop

    // 0x80028AF8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80028AFC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80028B00: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
L_80028B04:
    // 0x80028B04: lbu         $a2, 0x2D($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2D);
    // 0x80028B08: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80028B0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028B10: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80028B14: lh          $a1, 0x3A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3A);
    // 0x80028B18: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80028B1C: andi        $t1, $a2, 0x7F
    ctx->r9 = ctx->r6 & 0X7F;
    // 0x80028B20: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80028B24: jal         0x800298A4
    // 0x80028B28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800298A4(rdram, ctx);
        goto after_0;
    // 0x80028B28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80028B2C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80028B30: nop

    // 0x80028B34: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x80028B38: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80028B3C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80028B40: nop

    // 0x80028B44: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80028B48: nop

    // 0x80028B4C: bne         $t5, $zero, L_80028A7C
    if (ctx->r13 != 0) {
        // 0x80028B50: sb          $t5, 0x2D($sp)
        MEM_B(0X2D, ctx->r29) = ctx->r13;
            goto L_80028A7C;
    }
    // 0x80028B50: sb          $t5, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r13;
L_80028B54:
    // 0x80028B54: b           L_80028B6C
    // 0x80028B58: nop

        goto L_80028B6C;
    // 0x80028B58: nop

L_80028B5C:
    // 0x80028B5C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80028B60: nop

    // 0x80028B64: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80028B68: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80028B6C:
    // 0x80028B6C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80028B70: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80028B74: nop

    // 0x80028B78: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80028B7C: b           L_80028B84
    // 0x80028B80: nop

        goto L_80028B84;
    // 0x80028B80: nop

L_80028B84:
    // 0x80028B84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028B88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80028B8C: jr          $ra
    // 0x80028B90: nop

    return;
    // 0x80028B90: nop

;}
RECOMP_FUNC void func_80096C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096C6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096C74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80096C78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80096C7C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80096C80: nop

    // 0x80096C84: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80096C88:
    // 0x80096C88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80096C8C: jal         0x800319B0
    // 0x80096C90: nop

    func_800319B0(rdram, ctx);
        goto after_0;
    // 0x80096C90: nop

    after_0:
L_80096C94:
    // 0x80096C94: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80096C98: nop

    // 0x80096C9C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80096CA0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80096CA4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80096CA8: nop

    // 0x80096CAC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80096CB0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80096CB4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80096CB8: nop

    // 0x80096CBC: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80096CC0: nop

    // 0x80096CC4: bne         $t2, $zero, L_80096C94
    if (ctx->r10 != 0) {
        // 0x80096CC8: nop
    
            goto L_80096C94;
    }
    // 0x80096CC8: nop

L_80096CCC:
    // 0x80096CCC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80096CD0: nop

    // 0x80096CD4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80096CD8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80096CDC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80096CE0: nop

    // 0x80096CE4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80096CE8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80096CEC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80096CF0: nop

    // 0x80096CF4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80096CF8: nop

    // 0x80096CFC: beq         $t8, $zero, L_80096CCC
    if (ctx->r24 == 0) {
        // 0x80096D00: nop
    
            goto L_80096CCC;
    }
    // 0x80096D00: nop

    // 0x80096D04: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80096D08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80096D0C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80096D10: nop

    // 0x80096D14: bne         $t0, $at, L_80096C88
    if (ctx->r8 != ctx->r1) {
        // 0x80096D18: nop
    
            goto L_80096C88;
    }
    // 0x80096D18: nop

    // 0x80096D1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80096D20: jal         0x800BC980
    // 0x80096D24: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80096D24: nop

    after_1:
    // 0x80096D28: b           L_80096D30
    // 0x80096D2C: nop

        goto L_80096D30;
    // 0x80096D2C: nop

L_80096D30:
    // 0x80096D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096D34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096D38: jr          $ra
    // 0x80096D3C: nop

    return;
    // 0x80096D3C: nop

;}
RECOMP_FUNC void func_8009230C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009230C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80092310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092314: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80092318: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8009231C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80092320: lh          $t6, -0x4CC8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CC8);
    // 0x80092324: nop

    // 0x80092328: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x8009232C: bne         $t7, $zero, L_8009288C
    if (ctx->r15 != 0) {
        // 0x80092330: nop
    
            goto L_8009288C;
    }
    // 0x80092330: nop

    // 0x80092334: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80092338:
    // 0x80092338: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8009233C: lw          $t8, 0x6BA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6BA0);
    // 0x80092340: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80092344: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80092348: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009234C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80092350: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092354: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80092358: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009235C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092360: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80092364: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80092368: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009236C: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x80092370: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80092374: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80092378: lw          $t1, 0x6C14($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6C14);
    // 0x8009237C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80092380: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80092384: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80092388: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009238C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80092390: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80092394: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80092398: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8009239C: nop

    // 0x800923A0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800923A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800923A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800923AC: nop

    // 0x800923B0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800923B4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800923B8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800923BC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800923C0: nop

    // 0x800923C4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800923C8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800923CC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800923D0: lw          $t9, -0x78C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X78C);
    // 0x800923D4: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x800923D8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800923DC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800923E0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800923E4: lbu         $t1, -0x400($t0)
    ctx->r9 = MEM_BU(ctx->r8, -0X400);
    // 0x800923E8: nop

    // 0x800923EC: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x800923F0: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x800923F4: nop

    // 0x800923F8: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x800923FC: beq         $t3, $zero, L_8009242C
    if (ctx->r11 == 0) {
        // 0x80092400: nop
    
            goto L_8009242C;
    }
    // 0x80092400: nop

    // 0x80092404: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092408: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009240C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092410: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092414: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092418: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009241C: jal         0x80090784
    // 0x80092420: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x80092420: nop

    after_0:
    // 0x80092424: b           L_8009244C
    // 0x80092428: nop

        goto L_8009244C;
    // 0x80092428: nop

L_8009242C:
    // 0x8009242C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092430: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092434: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092438: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009243C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092440: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092444: jal         0x80090784
    // 0x80092448: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80092448: nop

    after_1:
L_8009244C:
    // 0x8009244C: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x80092450: nop

    // 0x80092454: andi        $t6, $t4, 0x40
    ctx->r14 = ctx->r12 & 0X40;
    // 0x80092458: beq         $t6, $zero, L_80092488
    if (ctx->r14 == 0) {
        // 0x8009245C: nop
    
            goto L_80092488;
    }
    // 0x8009245C: nop

    // 0x80092460: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092464: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092468: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009246C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092470: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092474: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092478: jal         0x80090784
    // 0x8009247C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x8009247C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x80092480: b           L_800924A8
    // 0x80092484: nop

        goto L_800924A8;
    // 0x80092484: nop

L_80092488:
    // 0x80092488: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009248C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092490: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092494: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092498: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009249C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800924A0: jal         0x80090784
    // 0x800924A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x800924A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_800924A8:
    // 0x800924A8: lbu         $t5, 0x27($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X27);
    // 0x800924AC: nop

    // 0x800924B0: andi        $t7, $t5, 0x20
    ctx->r15 = ctx->r13 & 0X20;
    // 0x800924B4: beq         $t7, $zero, L_800924E4
    if (ctx->r15 == 0) {
        // 0x800924B8: nop
    
            goto L_800924E4;
    }
    // 0x800924B8: nop

    // 0x800924BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800924C0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800924C4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800924C8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800924CC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800924D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800924D4: jal         0x80090784
    // 0x800924D8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x800924D8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x800924DC: b           L_80092504
    // 0x800924E0: nop

        goto L_80092504;
    // 0x800924E0: nop

L_800924E4:
    // 0x800924E4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800924E8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800924EC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800924F0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800924F4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800924F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800924FC: jal         0x80090784
    // 0x80092500: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x80092500: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80092504:
    // 0x80092504: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x80092508: nop

    // 0x8009250C: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x80092510: beq         $t9, $zero, L_80092540
    if (ctx->r25 == 0) {
        // 0x80092514: nop
    
            goto L_80092540;
    }
    // 0x80092514: nop

    // 0x80092518: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009251C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092520: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092524: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092528: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009252C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092530: jal         0x80090784
    // 0x80092534: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80092534: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80092538: b           L_80092560
    // 0x8009253C: nop

        goto L_80092560;
    // 0x8009253C: nop

L_80092540:
    // 0x80092540: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092544: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092548: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009254C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092550: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092554: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092558: jal         0x80090784
    // 0x8009255C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x8009255C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_80092560:
    // 0x80092560: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80092564: nop

    // 0x80092568: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x8009256C: beq         $t1, $zero, L_8009259C
    if (ctx->r9 == 0) {
        // 0x80092570: nop
    
            goto L_8009259C;
    }
    // 0x80092570: nop

    // 0x80092574: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092578: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009257C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092580: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092584: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092588: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009258C: jal         0x80090784
    // 0x80092590: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x80092590: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x80092594: b           L_800925BC
    // 0x80092598: nop

        goto L_800925BC;
    // 0x80092598: nop

L_8009259C:
    // 0x8009259C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800925A0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800925A4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800925A8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800925AC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800925B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800925B4: jal         0x80090784
    // 0x800925B8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x800925B8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_800925BC:
    // 0x800925BC: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x800925C0: nop

    // 0x800925C4: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800925C8: beq         $t3, $zero, L_800925F8
    if (ctx->r11 == 0) {
        // 0x800925CC: nop
    
            goto L_800925F8;
    }
    // 0x800925CC: nop

    // 0x800925D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800925D4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800925D8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800925DC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800925E0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800925E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800925E8: jal         0x80090784
    // 0x800925EC: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x800925EC: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x800925F0: b           L_80092618
    // 0x800925F4: nop

        goto L_80092618;
    // 0x800925F4: nop

L_800925F8:
    // 0x800925F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800925FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092600: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092604: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092608: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009260C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092610: jal         0x80090784
    // 0x80092614: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80092614: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80092618:
    // 0x80092618: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x8009261C: nop

    // 0x80092620: andi        $t6, $t4, 0x2
    ctx->r14 = ctx->r12 & 0X2;
    // 0x80092624: beq         $t6, $zero, L_80092654
    if (ctx->r14 == 0) {
        // 0x80092628: nop
    
            goto L_80092654;
    }
    // 0x80092628: nop

    // 0x8009262C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092630: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092634: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092638: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009263C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092640: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092644: jal         0x80090784
    // 0x80092648: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80092648: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x8009264C: b           L_80092674
    // 0x80092650: nop

        goto L_80092674;
    // 0x80092650: nop

L_80092654:
    // 0x80092654: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092658: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009265C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092660: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092664: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092668: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009266C: jal         0x80090784
    // 0x80092670: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x80092670: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_80092674:
    // 0x80092674: lbu         $t5, 0x27($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X27);
    // 0x80092678: nop

    // 0x8009267C: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80092680: beq         $t7, $zero, L_800926B0
    if (ctx->r15 == 0) {
        // 0x80092684: nop
    
            goto L_800926B0;
    }
    // 0x80092684: nop

    // 0x80092688: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009268C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092690: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092694: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092698: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009269C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800926A0: jal         0x80090784
    // 0x800926A4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x800926A4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x800926A8: b           L_800926D0
    // 0x800926AC: nop

        goto L_800926D0;
    // 0x800926AC: nop

L_800926B0:
    // 0x800926B0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800926B4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800926B8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800926BC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800926C0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800926C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800926C8: jal         0x80090784
    // 0x800926CC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x800926CC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_800926D0:
    // 0x800926D0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800926D4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800926D8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800926DC: lw          $t3, -0x78C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X78C);
    // 0x800926E0: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800926E4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800926E8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800926EC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800926F0: lbu         $t6, -0x3FF($t4)
    ctx->r14 = MEM_BU(ctx->r12, -0X3FF);
    // 0x800926F4: nop

    // 0x800926F8: sb          $t6, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r14;
    // 0x800926FC: lbu         $t5, 0x27($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X27);
    // 0x80092700: nop

    // 0x80092704: andi        $t7, $t5, 0x80
    ctx->r15 = ctx->r13 & 0X80;
    // 0x80092708: beq         $t7, $zero, L_80092738
    if (ctx->r15 == 0) {
        // 0x8009270C: nop
    
            goto L_80092738;
    }
    // 0x8009270C: nop

    // 0x80092710: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092714: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092718: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009271C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092720: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092724: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092728: jal         0x80090784
    // 0x8009272C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_16;
    // 0x8009272C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_16:
    // 0x80092730: b           L_80092758
    // 0x80092734: nop

        goto L_80092758;
    // 0x80092734: nop

L_80092738:
    // 0x80092738: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009273C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092740: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092744: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092748: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009274C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092750: jal         0x80090784
    // 0x80092754: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_17;
    // 0x80092754: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_17:
L_80092758:
    // 0x80092758: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x8009275C: nop

    // 0x80092760: andi        $t0, $t8, 0x40
    ctx->r8 = ctx->r24 & 0X40;
    // 0x80092764: beq         $t0, $zero, L_80092794
    if (ctx->r8 == 0) {
        // 0x80092768: nop
    
            goto L_80092794;
    }
    // 0x80092768: nop

    // 0x8009276C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092770: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092774: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092778: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009277C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092780: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092784: jal         0x80090784
    // 0x80092788: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_18;
    // 0x80092788: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_18:
    // 0x8009278C: b           L_800927B4
    // 0x80092790: nop

        goto L_800927B4;
    // 0x80092790: nop

L_80092794:
    // 0x80092794: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092798: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009279C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800927A0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800927A4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800927A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800927AC: jal         0x80090784
    // 0x800927B0: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    func_80090784(rdram, ctx);
        goto after_19;
    // 0x800927B0: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    after_19:
L_800927B4:
    // 0x800927B4: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x800927B8: nop

    // 0x800927BC: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x800927C0: beq         $t1, $zero, L_800927F0
    if (ctx->r9 == 0) {
        // 0x800927C4: nop
    
            goto L_800927F0;
    }
    // 0x800927C4: nop

    // 0x800927C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800927CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800927D0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800927D4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800927D8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800927DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800927E0: jal         0x80090784
    // 0x800927E4: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_20;
    // 0x800927E4: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_20:
    // 0x800927E8: b           L_80092810
    // 0x800927EC: nop

        goto L_80092810;
    // 0x800927EC: nop

L_800927F0:
    // 0x800927F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800927F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800927F8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800927FC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092800: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092804: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092808: jal         0x80090784
    // 0x8009280C: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    func_80090784(rdram, ctx);
        goto after_21;
    // 0x8009280C: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    after_21:
L_80092810:
    // 0x80092810: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x80092814: nop

    // 0x80092818: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x8009281C: beq         $t3, $zero, L_8009284C
    if (ctx->r11 == 0) {
        // 0x80092820: nop
    
            goto L_8009284C;
    }
    // 0x80092820: nop

    // 0x80092824: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092828: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009282C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092830: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092834: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092838: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009283C: jal         0x80090784
    // 0x80092840: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_22;
    // 0x80092840: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_22:
    // 0x80092844: b           L_8009286C
    // 0x80092848: nop

        goto L_8009286C;
    // 0x80092848: nop

L_8009284C:
    // 0x8009284C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092850: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092854: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092858: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009285C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092860: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092864: jal         0x80090784
    // 0x80092868: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    func_80090784(rdram, ctx);
        goto after_23;
    // 0x80092868: addiu       $a3, $a3, 0xB
    ctx->r7 = ADD32(ctx->r7, 0XB);
    after_23:
L_8009286C:
    // 0x8009286C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80092870: nop

    // 0x80092874: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80092878: slti        $at, $t6, 0xC
    ctx->r1 = SIGNED(ctx->r14) < 0XC ? 1 : 0;
    // 0x8009287C: bne         $at, $zero, L_80092338
    if (ctx->r1 != 0) {
        // 0x80092880: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_80092338;
    }
    // 0x80092880: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80092884: b           L_80093B00
    // 0x80092888: nop

        goto L_80093B00;
    // 0x80092888: nop

L_8009288C:
    // 0x8009288C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80092890:
    // 0x80092890: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80092894: lw          $t5, 0x6BA0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6BA0);
    // 0x80092898: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8009289C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800928A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800928A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800928A8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800928AC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800928B0: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800928B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800928B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800928BC: lwc1        $f8, -0x4510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x800928C0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800928C4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800928C8: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x800928CC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800928D0: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800928D4: lw          $t9, 0x6C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C14);
    // 0x800928D8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800928DC: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800928E0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800928E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800928E8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800928EC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800928F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800928F4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800928F8: nop

    // 0x800928FC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80092900: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80092904: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80092908: nop

    // 0x8009290C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80092910: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80092914: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80092918: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8009291C: nop

    // 0x80092920: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80092924: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80092928: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8009292C: lw          $t8, -0x78C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X78C);
    // 0x80092930: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80092934: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x80092938: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8009293C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80092940: lbu         $t9, -0x400($t0)
    ctx->r25 = MEM_BU(ctx->r8, -0X400);
    // 0x80092944: nop

    // 0x80092948: sb          $t9, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r25;
    // 0x8009294C: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x80092950: nop

    // 0x80092954: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80092958: beq         $t2, $zero, L_80092A14
    if (ctx->r10 == 0) {
        // 0x8009295C: nop
    
            goto L_80092A14;
    }
    // 0x8009295C: nop

    // 0x80092960: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092964: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80092968: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009296C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80092970: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092974: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092978: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009297C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092980: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80092984: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092988: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x8009298C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092990: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092994: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092998: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8009299C: beq         $t6, $zero, L_800929F0
    if (ctx->r14 == 0) {
        // 0x800929A0: nop
    
            goto L_800929F0;
    }
    // 0x800929A0: nop

    // 0x800929A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800929A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800929AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800929B0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800929B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800929B8: nop

    // 0x800929BC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800929C0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800929C4: nop

    // 0x800929C8: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x800929CC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800929D0: bne         $t6, $zero, L_800929E8
    if (ctx->r14 != 0) {
        // 0x800929D4: nop
    
            goto L_800929E8;
    }
    // 0x800929D4: nop

    // 0x800929D8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800929DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800929E0: b           L_80092A00
    // 0x800929E4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80092A00;
    // 0x800929E4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800929E8:
    // 0x800929E8: b           L_80092A00
    // 0x800929EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80092A00;
    // 0x800929EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800929F0:
    // 0x800929F0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800929F4: nop

    // 0x800929F8: bltz        $t6, L_800929E8
    if (SIGNED(ctx->r14) < 0) {
        // 0x800929FC: nop
    
            goto L_800929E8;
    }
    // 0x800929FC: nop

L_80092A00:
    // 0x80092A00: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80092A04: jal         0x800908A0
    // 0x80092A08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_24;
    // 0x80092A08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_24:
    // 0x80092A0C: b           L_80092AC0
    // 0x80092A10: nop

        goto L_80092AC0;
    // 0x80092A10: nop

L_80092A14:
    // 0x80092A14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092A18: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80092A1C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092A20: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80092A24: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092A28: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092A2C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80092A30: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092A34: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80092A38: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092A3C: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80092A40: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092A44: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092A48: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092A4C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80092A50: beq         $t5, $zero, L_80092AA4
    if (ctx->r13 == 0) {
        // 0x80092A54: nop
    
            goto L_80092AA4;
    }
    // 0x80092A54: nop

    // 0x80092A58: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092A5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092A60: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092A64: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80092A68: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80092A6C: nop

    // 0x80092A70: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80092A74: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80092A78: nop

    // 0x80092A7C: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80092A80: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80092A84: bne         $t5, $zero, L_80092A9C
    if (ctx->r13 != 0) {
        // 0x80092A88: nop
    
            goto L_80092A9C;
    }
    // 0x80092A88: nop

    // 0x80092A8C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80092A90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092A94: b           L_80092AB4
    // 0x80092A98: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80092AB4;
    // 0x80092A98: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80092A9C:
    // 0x80092A9C: b           L_80092AB4
    // 0x80092AA0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80092AB4;
    // 0x80092AA0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80092AA4:
    // 0x80092AA4: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80092AA8: nop

    // 0x80092AAC: bltz        $t5, L_80092A9C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80092AB0: nop
    
            goto L_80092A9C;
    }
    // 0x80092AB0: nop

L_80092AB4:
    // 0x80092AB4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80092AB8: jal         0x800908A0
    // 0x80092ABC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_25;
    // 0x80092ABC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_25:
L_80092AC0:
    // 0x80092AC0: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x80092AC4: nop

    // 0x80092AC8: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80092ACC: beq         $t8, $zero, L_80092B88
    if (ctx->r24 == 0) {
        // 0x80092AD0: nop
    
            goto L_80092B88;
    }
    // 0x80092AD0: nop

    // 0x80092AD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092AD8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80092ADC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092AE0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80092AE4: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092AE8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092AEC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80092AF0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092AF4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80092AF8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092AFC: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80092B00: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092B04: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092B0C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80092B10: beq         $t9, $zero, L_80092B64
    if (ctx->r25 == 0) {
        // 0x80092B14: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80092B64;
    }
    // 0x80092B14: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80092B18: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092B1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80092B20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092B24: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80092B28: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80092B2C: nop

    // 0x80092B30: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80092B34: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80092B38: nop

    // 0x80092B3C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80092B40: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80092B44: bne         $t9, $zero, L_80092B5C
    if (ctx->r25 != 0) {
        // 0x80092B48: nop
    
            goto L_80092B5C;
    }
    // 0x80092B48: nop

    // 0x80092B4C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80092B50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092B54: b           L_80092B74
    // 0x80092B58: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80092B74;
    // 0x80092B58: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80092B5C:
    // 0x80092B5C: b           L_80092B74
    // 0x80092B60: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80092B74;
    // 0x80092B60: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80092B64:
    // 0x80092B64: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80092B68: nop

    // 0x80092B6C: bltz        $t9, L_80092B5C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80092B70: nop
    
            goto L_80092B5C;
    }
    // 0x80092B70: nop

L_80092B74:
    // 0x80092B74: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80092B78: jal         0x800908A0
    // 0x80092B7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_26;
    // 0x80092B7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_26:
    // 0x80092B80: b           L_80092C34
    // 0x80092B84: nop

        goto L_80092C34;
    // 0x80092B84: nop

L_80092B88:
    // 0x80092B88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092B8C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80092B90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80092B94: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80092B98: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092B9C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092BA0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80092BA4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092BA8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80092BAC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092BB0: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80092BB4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092BB8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092BBC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092BC0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80092BC4: beq         $t2, $zero, L_80092C18
    if (ctx->r10 == 0) {
        // 0x80092BC8: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80092C18;
    }
    // 0x80092BC8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80092BCC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092BD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80092BD4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80092BD8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80092BDC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80092BE0: nop

    // 0x80092BE4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80092BE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80092BEC: nop

    // 0x80092BF0: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80092BF4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80092BF8: bne         $t2, $zero, L_80092C10
    if (ctx->r10 != 0) {
        // 0x80092BFC: nop
    
            goto L_80092C10;
    }
    // 0x80092BFC: nop

    // 0x80092C00: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80092C04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092C08: b           L_80092C28
    // 0x80092C0C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80092C28;
    // 0x80092C0C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80092C10:
    // 0x80092C10: b           L_80092C28
    // 0x80092C14: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80092C28;
    // 0x80092C14: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80092C18:
    // 0x80092C18: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80092C1C: nop

    // 0x80092C20: bltz        $t2, L_80092C10
    if (SIGNED(ctx->r10) < 0) {
        // 0x80092C24: nop
    
            goto L_80092C10;
    }
    // 0x80092C24: nop

L_80092C28:
    // 0x80092C28: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80092C2C: jal         0x800908A0
    // 0x80092C30: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_27;
    // 0x80092C30: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_27:
L_80092C34:
    // 0x80092C34: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x80092C38: nop

    // 0x80092C3C: andi        $t6, $t3, 0x20
    ctx->r14 = ctx->r11 & 0X20;
    // 0x80092C40: beq         $t6, $zero, L_80092CFC
    if (ctx->r14 == 0) {
        // 0x80092C44: nop
    
            goto L_80092CFC;
    }
    // 0x80092C44: nop

    // 0x80092C48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092C4C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80092C50: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092C54: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80092C58: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092C5C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092C60: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80092C64: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092C68: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80092C6C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092C70: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80092C74: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092C78: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092C7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092C80: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80092C84: beq         $t5, $zero, L_80092CD8
    if (ctx->r13 == 0) {
        // 0x80092C88: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80092CD8;
    }
    // 0x80092C88: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80092C8C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092C90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092C94: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092C98: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80092C9C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80092CA0: nop

    // 0x80092CA4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80092CA8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80092CAC: nop

    // 0x80092CB0: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80092CB4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80092CB8: bne         $t5, $zero, L_80092CD0
    if (ctx->r13 != 0) {
        // 0x80092CBC: nop
    
            goto L_80092CD0;
    }
    // 0x80092CBC: nop

    // 0x80092CC0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80092CC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092CC8: b           L_80092CE8
    // 0x80092CCC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80092CE8;
    // 0x80092CCC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80092CD0:
    // 0x80092CD0: b           L_80092CE8
    // 0x80092CD4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80092CE8;
    // 0x80092CD4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80092CD8:
    // 0x80092CD8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80092CDC: nop

    // 0x80092CE0: bltz        $t5, L_80092CD0
    if (SIGNED(ctx->r13) < 0) {
        // 0x80092CE4: nop
    
            goto L_80092CD0;
    }
    // 0x80092CE4: nop

L_80092CE8:
    // 0x80092CE8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80092CEC: jal         0x800908A0
    // 0x80092CF0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_28;
    // 0x80092CF0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_28:
    // 0x80092CF4: b           L_80092DA8
    // 0x80092CF8: nop

        goto L_80092DA8;
    // 0x80092CF8: nop

L_80092CFC:
    // 0x80092CFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092D00: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80092D04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092D08: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80092D0C: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092D10: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092D14: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80092D18: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092D1C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80092D20: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092D24: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80092D28: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092D2C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092D30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092D34: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80092D38: beq         $t8, $zero, L_80092D8C
    if (ctx->r24 == 0) {
        // 0x80092D3C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80092D8C;
    }
    // 0x80092D3C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80092D40: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092D44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80092D48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092D4C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80092D50: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80092D54: nop

    // 0x80092D58: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80092D5C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80092D60: nop

    // 0x80092D64: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80092D68: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80092D6C: bne         $t8, $zero, L_80092D84
    if (ctx->r24 != 0) {
        // 0x80092D70: nop
    
            goto L_80092D84;
    }
    // 0x80092D70: nop

    // 0x80092D74: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80092D78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092D7C: b           L_80092D9C
    // 0x80092D80: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80092D9C;
    // 0x80092D80: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80092D84:
    // 0x80092D84: b           L_80092D9C
    // 0x80092D88: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80092D9C;
    // 0x80092D88: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80092D8C:
    // 0x80092D8C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80092D90: nop

    // 0x80092D94: bltz        $t8, L_80092D84
    if (SIGNED(ctx->r24) < 0) {
        // 0x80092D98: nop
    
            goto L_80092D84;
    }
    // 0x80092D98: nop

L_80092D9C:
    // 0x80092D9C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80092DA0: jal         0x800908A0
    // 0x80092DA4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_29;
    // 0x80092DA4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_29:
L_80092DA8:
    // 0x80092DA8: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80092DAC: nop

    // 0x80092DB0: andi        $t9, $t0, 0x10
    ctx->r25 = ctx->r8 & 0X10;
    // 0x80092DB4: beq         $t9, $zero, L_80092E70
    if (ctx->r25 == 0) {
        // 0x80092DB8: nop
    
            goto L_80092E70;
    }
    // 0x80092DB8: nop

    // 0x80092DBC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092DC0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80092DC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80092DC8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80092DCC: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092DD0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092DD4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80092DD8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092DDC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80092DE0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092DE4: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80092DE8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092DEC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092DF0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092DF4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80092DF8: beq         $t2, $zero, L_80092E4C
    if (ctx->r10 == 0) {
        // 0x80092DFC: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_80092E4C;
    }
    // 0x80092DFC: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80092E00: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092E04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80092E08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80092E0C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80092E10: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80092E14: nop

    // 0x80092E18: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80092E1C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80092E20: nop

    // 0x80092E24: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80092E28: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80092E2C: bne         $t2, $zero, L_80092E44
    if (ctx->r10 != 0) {
        // 0x80092E30: nop
    
            goto L_80092E44;
    }
    // 0x80092E30: nop

    // 0x80092E34: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80092E38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092E3C: b           L_80092E5C
    // 0x80092E40: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80092E5C;
    // 0x80092E40: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80092E44:
    // 0x80092E44: b           L_80092E5C
    // 0x80092E48: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80092E5C;
    // 0x80092E48: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80092E4C:
    // 0x80092E4C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80092E50: nop

    // 0x80092E54: bltz        $t2, L_80092E44
    if (SIGNED(ctx->r10) < 0) {
        // 0x80092E58: nop
    
            goto L_80092E44;
    }
    // 0x80092E58: nop

L_80092E5C:
    // 0x80092E5C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80092E60: jal         0x800908A0
    // 0x80092E64: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_30;
    // 0x80092E64: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_30:
    // 0x80092E68: b           L_80092F1C
    // 0x80092E6C: nop

        goto L_80092F1C;
    // 0x80092E6C: nop

L_80092E70:
    // 0x80092E70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092E74: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80092E78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092E7C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80092E80: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092E84: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092E88: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80092E8C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092E90: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80092E94: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092E98: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80092E9C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092EA0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092EA4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092EA8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80092EAC: beq         $t6, $zero, L_80092F00
    if (ctx->r14 == 0) {
        // 0x80092EB0: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_80092F00;
    }
    // 0x80092EB0: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80092EB4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092EB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092EBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092EC0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80092EC4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80092EC8: nop

    // 0x80092ECC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80092ED0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80092ED4: nop

    // 0x80092ED8: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80092EDC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80092EE0: bne         $t6, $zero, L_80092EF8
    if (ctx->r14 != 0) {
        // 0x80092EE4: nop
    
            goto L_80092EF8;
    }
    // 0x80092EE4: nop

    // 0x80092EE8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80092EEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092EF0: b           L_80092F10
    // 0x80092EF4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80092F10;
    // 0x80092EF4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80092EF8:
    // 0x80092EF8: b           L_80092F10
    // 0x80092EFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80092F10;
    // 0x80092EFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80092F00:
    // 0x80092F00: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80092F04: nop

    // 0x80092F08: bltz        $t6, L_80092EF8
    if (SIGNED(ctx->r14) < 0) {
        // 0x80092F0C: nop
    
            goto L_80092EF8;
    }
    // 0x80092F0C: nop

L_80092F10:
    // 0x80092F10: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80092F14: jal         0x800908A0
    // 0x80092F18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_31;
    // 0x80092F18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_31:
L_80092F1C:
    // 0x80092F1C: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x80092F20: nop

    // 0x80092F24: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x80092F28: beq         $t5, $zero, L_80092FE4
    if (ctx->r13 == 0) {
        // 0x80092F2C: nop
    
            goto L_80092FE4;
    }
    // 0x80092F2C: nop

    // 0x80092F30: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092F34: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80092F38: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092F3C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80092F40: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092F44: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092F48: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80092F4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092F50: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80092F54: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092F58: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80092F5C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092F60: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092F64: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80092F68: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80092F6C: beq         $t8, $zero, L_80092FC0
    if (ctx->r24 == 0) {
        // 0x80092F70: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80092FC0;
    }
    // 0x80092F70: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80092F74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80092F78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80092F7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092F80: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80092F84: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80092F88: nop

    // 0x80092F8C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80092F90: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80092F94: nop

    // 0x80092F98: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80092F9C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80092FA0: bne         $t8, $zero, L_80092FB8
    if (ctx->r24 != 0) {
        // 0x80092FA4: nop
    
            goto L_80092FB8;
    }
    // 0x80092FA4: nop

    // 0x80092FA8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80092FAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092FB0: b           L_80092FD0
    // 0x80092FB4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80092FD0;
    // 0x80092FB4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80092FB8:
    // 0x80092FB8: b           L_80092FD0
    // 0x80092FBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80092FD0;
    // 0x80092FBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80092FC0:
    // 0x80092FC0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80092FC4: nop

    // 0x80092FC8: bltz        $t8, L_80092FB8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80092FCC: nop
    
            goto L_80092FB8;
    }
    // 0x80092FCC: nop

L_80092FD0:
    // 0x80092FD0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80092FD4: jal         0x800908A0
    // 0x80092FD8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_32;
    // 0x80092FD8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_32:
    // 0x80092FDC: b           L_80093090
    // 0x80092FE0: nop

        goto L_80093090;
    // 0x80092FE0: nop

L_80092FE4:
    // 0x80092FE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80092FE8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80092FEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092FF0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80092FF4: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80092FF8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80092FFC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80093000: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093004: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80093008: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009300C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80093010: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093014: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093018: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009301C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80093020: beq         $t9, $zero, L_80093074
    if (ctx->r25 == 0) {
        // 0x80093024: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80093074;
    }
    // 0x80093024: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80093028: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009302C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093030: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80093034: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80093038: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8009303C: nop

    // 0x80093040: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80093044: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80093048: nop

    // 0x8009304C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80093050: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80093054: bne         $t9, $zero, L_8009306C
    if (ctx->r25 != 0) {
        // 0x80093058: nop
    
            goto L_8009306C;
    }
    // 0x80093058: nop

    // 0x8009305C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80093060: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093064: b           L_80093084
    // 0x80093068: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80093084;
    // 0x80093068: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8009306C:
    // 0x8009306C: b           L_80093084
    // 0x80093070: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80093084;
    // 0x80093070: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80093074:
    // 0x80093074: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80093078: nop

    // 0x8009307C: bltz        $t9, L_8009306C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80093080: nop
    
            goto L_8009306C;
    }
    // 0x80093080: nop

L_80093084:
    // 0x80093084: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80093088: jal         0x800908A0
    // 0x8009308C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_33;
    // 0x8009308C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_33:
L_80093090:
    // 0x80093090: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x80093094: nop

    // 0x80093098: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x8009309C: beq         $t2, $zero, L_80093158
    if (ctx->r10 == 0) {
        // 0x800930A0: nop
    
            goto L_80093158;
    }
    // 0x800930A0: nop

    // 0x800930A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800930A8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800930AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800930B0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800930B4: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800930B8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800930BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800930C0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800930C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800930C8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800930CC: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x800930D0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800930D4: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800930D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800930DC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800930E0: beq         $t6, $zero, L_80093134
    if (ctx->r14 == 0) {
        // 0x800930E4: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_80093134;
    }
    // 0x800930E4: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x800930E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800930EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800930F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800930F4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800930F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800930FC: nop

    // 0x80093100: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80093104: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80093108: nop

    // 0x8009310C: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80093110: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80093114: bne         $t6, $zero, L_8009312C
    if (ctx->r14 != 0) {
        // 0x80093118: nop
    
            goto L_8009312C;
    }
    // 0x80093118: nop

    // 0x8009311C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80093120: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093124: b           L_80093144
    // 0x80093128: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80093144;
    // 0x80093128: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8009312C:
    // 0x8009312C: b           L_80093144
    // 0x80093130: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80093144;
    // 0x80093130: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80093134:
    // 0x80093134: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80093138: nop

    // 0x8009313C: bltz        $t6, L_8009312C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80093140: nop
    
            goto L_8009312C;
    }
    // 0x80093140: nop

L_80093144:
    // 0x80093144: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80093148: jal         0x800908A0
    // 0x8009314C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_34;
    // 0x8009314C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_34:
    // 0x80093150: b           L_80093204
    // 0x80093154: nop

        goto L_80093204;
    // 0x80093154: nop

L_80093158:
    // 0x80093158: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009315C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80093160: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80093164: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80093168: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009316C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093170: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80093174: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093178: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8009317C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093180: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x80093184: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093188: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009318C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093190: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80093194: beq         $t5, $zero, L_800931E8
    if (ctx->r13 == 0) {
        // 0x80093198: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_800931E8;
    }
    // 0x80093198: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x8009319C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800931A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800931A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800931A8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800931AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800931B0: nop

    // 0x800931B4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800931B8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800931BC: nop

    // 0x800931C0: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800931C4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800931C8: bne         $t5, $zero, L_800931E0
    if (ctx->r13 != 0) {
        // 0x800931CC: nop
    
            goto L_800931E0;
    }
    // 0x800931CC: nop

    // 0x800931D0: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800931D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800931D8: b           L_800931F8
    // 0x800931DC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800931F8;
    // 0x800931DC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800931E0:
    // 0x800931E0: b           L_800931F8
    // 0x800931E4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800931F8;
    // 0x800931E4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_800931E8:
    // 0x800931E8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800931EC: nop

    // 0x800931F0: bltz        $t5, L_800931E0
    if (SIGNED(ctx->r13) < 0) {
        // 0x800931F4: nop
    
            goto L_800931E0;
    }
    // 0x800931F4: nop

L_800931F8:
    // 0x800931F8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800931FC: jal         0x800908A0
    // 0x80093200: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_35;
    // 0x80093200: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_35:
L_80093204:
    // 0x80093204: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x80093208: nop

    // 0x8009320C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80093210: beq         $t8, $zero, L_800932CC
    if (ctx->r24 == 0) {
        // 0x80093214: nop
    
            goto L_800932CC;
    }
    // 0x80093214: nop

    // 0x80093218: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009321C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80093220: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80093224: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80093228: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009322C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093230: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80093234: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093238: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009323C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093240: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80093244: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093248: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009324C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093250: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80093254: beq         $t9, $zero, L_800932A8
    if (ctx->r25 == 0) {
        // 0x80093258: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_800932A8;
    }
    // 0x80093258: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x8009325C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093264: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80093268: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009326C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80093270: nop

    // 0x80093274: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80093278: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009327C: nop

    // 0x80093280: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80093284: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80093288: bne         $t9, $zero, L_800932A0
    if (ctx->r25 != 0) {
        // 0x8009328C: nop
    
            goto L_800932A0;
    }
    // 0x8009328C: nop

    // 0x80093290: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80093294: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093298: b           L_800932B8
    // 0x8009329C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800932B8;
    // 0x8009329C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800932A0:
    // 0x800932A0: b           L_800932B8
    // 0x800932A4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800932B8;
    // 0x800932A4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800932A8:
    // 0x800932A8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800932AC: nop

    // 0x800932B0: bltz        $t9, L_800932A0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800932B4: nop
    
            goto L_800932A0;
    }
    // 0x800932B4: nop

L_800932B8:
    // 0x800932B8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800932BC: jal         0x800908A0
    // 0x800932C0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800908A0(rdram, ctx);
        goto after_36;
    // 0x800932C0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_36:
    // 0x800932C4: b           L_80093378
    // 0x800932C8: nop

        goto L_80093378;
    // 0x800932C8: nop

L_800932CC:
    // 0x800932CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800932D0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800932D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800932D8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800932DC: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800932E0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800932E4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800932E8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800932EC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800932F0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800932F4: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x800932F8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800932FC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093300: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093304: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80093308: beq         $t2, $zero, L_8009335C
    if (ctx->r10 == 0) {
        // 0x8009330C: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_8009335C;
    }
    // 0x8009330C: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80093310: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093314: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80093318: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8009331C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80093320: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80093324: nop

    // 0x80093328: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009332C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093330: nop

    // 0x80093334: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80093338: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8009333C: bne         $t2, $zero, L_80093354
    if (ctx->r10 != 0) {
        // 0x80093340: nop
    
            goto L_80093354;
    }
    // 0x80093340: nop

    // 0x80093344: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80093348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009334C: b           L_8009336C
    // 0x80093350: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8009336C;
    // 0x80093350: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80093354:
    // 0x80093354: b           L_8009336C
    // 0x80093358: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8009336C;
    // 0x80093358: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8009335C:
    // 0x8009335C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80093360: nop

    // 0x80093364: bltz        $t2, L_80093354
    if (SIGNED(ctx->r10) < 0) {
        // 0x80093368: nop
    
            goto L_80093354;
    }
    // 0x80093368: nop

L_8009336C:
    // 0x8009336C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80093370: jal         0x800908A0
    // 0x80093374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_37;
    // 0x80093374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_37:
L_80093378:
    // 0x80093378: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x8009337C: nop

    // 0x80093380: andi        $t6, $t3, 0x1
    ctx->r14 = ctx->r11 & 0X1;
    // 0x80093384: beq         $t6, $zero, L_80093440
    if (ctx->r14 == 0) {
        // 0x80093388: nop
    
            goto L_80093440;
    }
    // 0x80093388: nop

    // 0x8009338C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093390: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80093394: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80093398: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8009339C: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800933A0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800933A4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800933A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800933AC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800933B0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800933B4: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800933B8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800933BC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800933C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800933C4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800933C8: beq         $t5, $zero, L_8009341C
    if (ctx->r13 == 0) {
        // 0x800933CC: addiu       $a3, $a3, 0xE
        ctx->r7 = ADD32(ctx->r7, 0XE);
            goto L_8009341C;
    }
    // 0x800933CC: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x800933D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800933D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800933D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800933DC: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800933E0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800933E4: nop

    // 0x800933E8: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800933EC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800933F0: nop

    // 0x800933F4: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800933F8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800933FC: bne         $t5, $zero, L_80093414
    if (ctx->r13 != 0) {
        // 0x80093400: nop
    
            goto L_80093414;
    }
    // 0x80093400: nop

    // 0x80093404: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80093408: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009340C: b           L_8009342C
    // 0x80093410: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8009342C;
    // 0x80093410: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80093414:
    // 0x80093414: b           L_8009342C
    // 0x80093418: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8009342C;
    // 0x80093418: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_8009341C:
    // 0x8009341C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80093420: nop

    // 0x80093424: bltz        $t5, L_80093414
    if (SIGNED(ctx->r13) < 0) {
        // 0x80093428: nop
    
            goto L_80093414;
    }
    // 0x80093428: nop

L_8009342C:
    // 0x8009342C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80093430: jal         0x800908A0
    // 0x80093434: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_38;
    // 0x80093434: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_38:
    // 0x80093438: b           L_800934EC
    // 0x8009343C: nop

        goto L_800934EC;
    // 0x8009343C: nop

L_80093440:
    // 0x80093440: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093444: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80093448: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009344C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80093450: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093454: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093458: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009345C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093460: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80093464: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093468: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8009346C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093470: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093474: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093478: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8009347C: beq         $t8, $zero, L_800934D0
    if (ctx->r24 == 0) {
        // 0x80093480: addiu       $a3, $a3, 0xE
        ctx->r7 = ADD32(ctx->r7, 0XE);
            goto L_800934D0;
    }
    // 0x80093480: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x80093484: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093488: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009348C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80093490: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80093494: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80093498: nop

    // 0x8009349C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800934A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800934A4: nop

    // 0x800934A8: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800934AC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800934B0: bne         $t8, $zero, L_800934C8
    if (ctx->r24 != 0) {
        // 0x800934B4: nop
    
            goto L_800934C8;
    }
    // 0x800934B4: nop

    // 0x800934B8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800934BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800934C0: b           L_800934E0
    // 0x800934C4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800934E0;
    // 0x800934C4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800934C8:
    // 0x800934C8: b           L_800934E0
    // 0x800934CC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800934E0;
    // 0x800934CC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800934D0:
    // 0x800934D0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800934D4: nop

    // 0x800934D8: bltz        $t8, L_800934C8
    if (SIGNED(ctx->r24) < 0) {
        // 0x800934DC: nop
    
            goto L_800934C8;
    }
    // 0x800934DC: nop

L_800934E0:
    // 0x800934E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800934E4: jal         0x800908A0
    // 0x800934E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_39;
    // 0x800934E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_39:
L_800934EC:
    // 0x800934EC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800934F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800934F4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800934F8: lw          $t6, -0x78C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78C);
    // 0x800934FC: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x80093500: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80093504: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80093508: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x8009350C: lbu         $t5, -0x3FF($t4)
    ctx->r13 = MEM_BU(ctx->r12, -0X3FF);
    // 0x80093510: nop

    // 0x80093514: sb          $t5, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r13;
    // 0x80093518: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x8009351C: nop

    // 0x80093520: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80093524: beq         $t8, $zero, L_800935E0
    if (ctx->r24 == 0) {
        // 0x80093528: nop
    
            goto L_800935E0;
    }
    // 0x80093528: nop

    // 0x8009352C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093530: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80093534: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80093538: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009353C: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093540: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093544: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80093548: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009354C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80093550: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093554: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80093558: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009355C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093560: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093564: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80093568: beq         $t1, $zero, L_800935BC
    if (ctx->r9 == 0) {
        // 0x8009356C: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800935BC;
    }
    // 0x8009356C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80093570: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80093578: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009357C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80093580: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80093584: nop

    // 0x80093588: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8009358C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80093590: nop

    // 0x80093594: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80093598: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8009359C: bne         $t1, $zero, L_800935B4
    if (ctx->r9 != 0) {
        // 0x800935A0: nop
    
            goto L_800935B4;
    }
    // 0x800935A0: nop

    // 0x800935A4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800935A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800935AC: b           L_800935CC
    // 0x800935B0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800935CC;
    // 0x800935B0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800935B4:
    // 0x800935B4: b           L_800935CC
    // 0x800935B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800935CC;
    // 0x800935B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800935BC:
    // 0x800935BC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800935C0: nop

    // 0x800935C4: bltz        $t1, L_800935B4
    if (SIGNED(ctx->r9) < 0) {
        // 0x800935C8: nop
    
            goto L_800935B4;
    }
    // 0x800935C8: nop

L_800935CC:
    // 0x800935CC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800935D0: jal         0x800908A0
    // 0x800935D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_40;
    // 0x800935D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_40:
    // 0x800935D8: b           L_8009368C
    // 0x800935DC: nop

        goto L_8009368C;
    // 0x800935DC: nop

L_800935E0:
    // 0x800935E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800935E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800935E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800935EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800935F0: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800935F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800935F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800935FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093600: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093604: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093608: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8009360C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093610: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093614: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093618: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8009361C: beq         $t2, $zero, L_80093670
    if (ctx->r10 == 0) {
        // 0x80093620: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80093670;
    }
    // 0x80093620: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80093624: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093628: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009362C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80093630: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80093634: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80093638: nop

    // 0x8009363C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80093640: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093644: nop

    // 0x80093648: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8009364C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80093650: bne         $t2, $zero, L_80093668
    if (ctx->r10 != 0) {
        // 0x80093654: nop
    
            goto L_80093668;
    }
    // 0x80093654: nop

    // 0x80093658: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8009365C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093660: b           L_80093680
    // 0x80093664: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80093680;
    // 0x80093664: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80093668:
    // 0x80093668: b           L_80093680
    // 0x8009366C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80093680;
    // 0x8009366C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_80093670:
    // 0x80093670: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80093674: nop

    // 0x80093678: bltz        $t2, L_80093668
    if (SIGNED(ctx->r10) < 0) {
        // 0x8009367C: nop
    
            goto L_80093668;
    }
    // 0x8009367C: nop

L_80093680:
    // 0x80093680: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80093684: jal         0x800908A0
    // 0x80093688: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_41;
    // 0x80093688: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_41:
L_8009368C:
    // 0x8009368C: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x80093690: nop

    // 0x80093694: andi        $t6, $t3, 0x40
    ctx->r14 = ctx->r11 & 0X40;
    // 0x80093698: beq         $t6, $zero, L_80093754
    if (ctx->r14 == 0) {
        // 0x8009369C: nop
    
            goto L_80093754;
    }
    // 0x8009369C: nop

    // 0x800936A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800936A4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800936A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800936AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800936B0: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800936B4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800936B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800936BC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800936C0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800936C4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800936C8: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800936CC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800936D0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800936D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800936D8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800936DC: beq         $t5, $zero, L_80093730
    if (ctx->r13 == 0) {
        // 0x800936E0: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80093730;
    }
    // 0x800936E0: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x800936E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800936E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800936EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800936F0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800936F4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800936F8: nop

    // 0x800936FC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80093700: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80093704: nop

    // 0x80093708: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x8009370C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80093710: bne         $t5, $zero, L_80093728
    if (ctx->r13 != 0) {
        // 0x80093714: nop
    
            goto L_80093728;
    }
    // 0x80093714: nop

    // 0x80093718: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8009371C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093720: b           L_80093740
    // 0x80093724: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80093740;
    // 0x80093724: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80093728:
    // 0x80093728: b           L_80093740
    // 0x8009372C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80093740;
    // 0x8009372C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80093730:
    // 0x80093730: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80093734: nop

    // 0x80093738: bltz        $t5, L_80093728
    if (SIGNED(ctx->r13) < 0) {
        // 0x8009373C: nop
    
            goto L_80093728;
    }
    // 0x8009373C: nop

L_80093740:
    // 0x80093740: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80093744: jal         0x800908A0
    // 0x80093748: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800908A0(rdram, ctx);
        goto after_42;
    // 0x80093748: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_42:
    // 0x8009374C: b           L_80093800
    // 0x80093750: nop

        goto L_80093800;
    // 0x80093750: nop

L_80093754:
    // 0x80093754: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093758: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8009375C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80093760: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80093764: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093768: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009376C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80093770: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093774: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80093778: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009377C: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80093780: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093784: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093788: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009378C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80093790: beq         $t8, $zero, L_800937E4
    if (ctx->r24 == 0) {
        // 0x80093794: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_800937E4;
    }
    // 0x80093794: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80093798: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009379C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800937A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800937A4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800937A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800937AC: nop

    // 0x800937B0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800937B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800937B8: nop

    // 0x800937BC: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800937C0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800937C4: bne         $t8, $zero, L_800937DC
    if (ctx->r24 != 0) {
        // 0x800937C8: nop
    
            goto L_800937DC;
    }
    // 0x800937C8: nop

    // 0x800937CC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800937D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800937D4: b           L_800937F4
    // 0x800937D8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800937F4;
    // 0x800937D8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800937DC:
    // 0x800937DC: b           L_800937F4
    // 0x800937E0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800937F4;
    // 0x800937E0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800937E4:
    // 0x800937E4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800937E8: nop

    // 0x800937EC: bltz        $t8, L_800937DC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800937F0: nop
    
            goto L_800937DC;
    }
    // 0x800937F0: nop

L_800937F4:
    // 0x800937F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800937F8: jal         0x800908A0
    // 0x800937FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_43;
    // 0x800937FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_43:
L_80093800:
    // 0x80093800: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x80093804: nop

    // 0x80093808: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x8009380C: beq         $t1, $zero, L_800938C8
    if (ctx->r9 == 0) {
        // 0x80093810: nop
    
            goto L_800938C8;
    }
    // 0x80093810: nop

    // 0x80093814: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093818: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8009381C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80093820: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80093824: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093828: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8009382C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80093830: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093834: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093838: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009383C: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80093840: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093844: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80093848: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009384C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80093850: beq         $t2, $zero, L_800938A4
    if (ctx->r10 == 0) {
        // 0x80093854: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_800938A4;
    }
    // 0x80093854: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x80093858: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009385C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80093860: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80093864: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80093868: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8009386C: nop

    // 0x80093870: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80093874: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80093878: nop

    // 0x8009387C: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80093880: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80093884: bne         $t2, $zero, L_8009389C
    if (ctx->r10 != 0) {
        // 0x80093888: nop
    
            goto L_8009389C;
    }
    // 0x80093888: nop

    // 0x8009388C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80093890: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093894: b           L_800938B4
    // 0x80093898: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800938B4;
    // 0x80093898: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8009389C:
    // 0x8009389C: b           L_800938B4
    // 0x800938A0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800938B4;
    // 0x800938A0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_800938A4:
    // 0x800938A4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800938A8: nop

    // 0x800938AC: bltz        $t2, L_8009389C
    if (SIGNED(ctx->r10) < 0) {
        // 0x800938B0: nop
    
            goto L_8009389C;
    }
    // 0x800938B0: nop

L_800938B4:
    // 0x800938B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800938B8: jal         0x800908A0
    // 0x800938BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800908A0(rdram, ctx);
        goto after_44;
    // 0x800938BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_44:
    // 0x800938C0: b           L_80093974
    // 0x800938C4: nop

        goto L_80093974;
    // 0x800938C4: nop

L_800938C8:
    // 0x800938C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800938CC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800938D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800938D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800938D8: lwc1        $f4, -0x4CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x800938DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800938E0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800938E4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800938E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800938EC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800938F0: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x800938F4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800938F8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800938FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093900: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80093904: beq         $t6, $zero, L_80093958
    if (ctx->r14 == 0) {
        // 0x80093908: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_80093958;
    }
    // 0x80093908: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x8009390C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093914: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80093918: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009391C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80093920: nop

    // 0x80093924: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80093928: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009392C: nop

    // 0x80093930: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80093934: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80093938: bne         $t6, $zero, L_80093950
    if (ctx->r14 != 0) {
        // 0x8009393C: nop
    
            goto L_80093950;
    }
    // 0x8009393C: nop

    // 0x80093940: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80093944: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093948: b           L_80093968
    // 0x8009394C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80093968;
    // 0x8009394C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80093950:
    // 0x80093950: b           L_80093968
    // 0x80093954: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80093968;
    // 0x80093954: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80093958:
    // 0x80093958: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009395C: nop

    // 0x80093960: bltz        $t6, L_80093950
    if (SIGNED(ctx->r14) < 0) {
        // 0x80093964: nop
    
            goto L_80093950;
    }
    // 0x80093964: nop

L_80093968:
    // 0x80093968: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8009396C: jal         0x800908A0
    // 0x80093970: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800908A0(rdram, ctx);
        goto after_45;
    // 0x80093970: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_45:
L_80093974:
    // 0x80093974: lbu         $t4, 0x27($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X27);
    // 0x80093978: nop

    // 0x8009397C: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80093980: beq         $t5, $zero, L_80093A3C
    if (ctx->r13 == 0) {
        // 0x80093984: nop
    
            goto L_80093A3C;
    }
    // 0x80093984: nop

    // 0x80093988: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009398C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80093990: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80093994: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80093998: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x8009399C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800939A0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800939A4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800939A8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800939AC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800939B0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800939B4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800939B8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800939BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800939C0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800939C4: beq         $t8, $zero, L_80093A18
    if (ctx->r24 == 0) {
        // 0x800939C8: addiu       $a3, $a3, 0x16
        ctx->r7 = ADD32(ctx->r7, 0X16);
            goto L_80093A18;
    }
    // 0x800939C8: addiu       $a3, $a3, 0x16
    ctx->r7 = ADD32(ctx->r7, 0X16);
    // 0x800939CC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800939D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800939D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800939D8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800939DC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800939E0: nop

    // 0x800939E4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800939E8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800939EC: nop

    // 0x800939F0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800939F4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800939F8: bne         $t8, $zero, L_80093A10
    if (ctx->r24 != 0) {
        // 0x800939FC: nop
    
            goto L_80093A10;
    }
    // 0x800939FC: nop

    // 0x80093A00: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80093A04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093A08: b           L_80093A28
    // 0x80093A0C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80093A28;
    // 0x80093A0C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80093A10:
    // 0x80093A10: b           L_80093A28
    // 0x80093A14: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80093A28;
    // 0x80093A14: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80093A18:
    // 0x80093A18: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80093A1C: nop

    // 0x80093A20: bltz        $t8, L_80093A10
    if (SIGNED(ctx->r24) < 0) {
        // 0x80093A24: nop
    
            goto L_80093A10;
    }
    // 0x80093A24: nop

L_80093A28:
    // 0x80093A28: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80093A2C: jal         0x800908A0
    // 0x80093A30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800908A0(rdram, ctx);
        goto after_46;
    // 0x80093A30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_46:
    // 0x80093A34: b           L_80093AE8
    // 0x80093A38: nop

        goto L_80093AE8;
    // 0x80093A38: nop

L_80093A3C:
    // 0x80093A3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093A40: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80093A44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80093A48: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80093A4C: lwc1        $f16, -0x4CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80093A50: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80093A54: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80093A58: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093A5C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80093A60: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093A64: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80093A68: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80093A6C: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80093A70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093A74: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80093A78: beq         $t1, $zero, L_80093ACC
    if (ctx->r9 == 0) {
        // 0x80093A7C: addiu       $a3, $a3, 0x16
        ctx->r7 = ADD32(ctx->r7, 0X16);
            goto L_80093ACC;
    }
    // 0x80093A7C: addiu       $a3, $a3, 0x16
    ctx->r7 = ADD32(ctx->r7, 0X16);
    // 0x80093A80: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80093A84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80093A88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80093A8C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80093A90: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80093A94: nop

    // 0x80093A98: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80093A9C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80093AA0: nop

    // 0x80093AA4: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80093AA8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80093AAC: bne         $t1, $zero, L_80093AC4
    if (ctx->r9 != 0) {
        // 0x80093AB0: nop
    
            goto L_80093AC4;
    }
    // 0x80093AB0: nop

    // 0x80093AB4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80093AB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80093ABC: b           L_80093ADC
    // 0x80093AC0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80093ADC;
    // 0x80093AC0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80093AC4:
    // 0x80093AC4: b           L_80093ADC
    // 0x80093AC8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80093ADC;
    // 0x80093AC8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80093ACC:
    // 0x80093ACC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80093AD0: nop

    // 0x80093AD4: bltz        $t1, L_80093AC4
    if (SIGNED(ctx->r9) < 0) {
        // 0x80093AD8: nop
    
            goto L_80093AC4;
    }
    // 0x80093AD8: nop

L_80093ADC:
    // 0x80093ADC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80093AE0: jal         0x800908A0
    // 0x80093AE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800908A0(rdram, ctx);
        goto after_47;
    // 0x80093AE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_47:
L_80093AE8:
    // 0x80093AE8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80093AEC: nop

    // 0x80093AF0: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80093AF4: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x80093AF8: bne         $at, $zero, L_80092890
    if (ctx->r1 != 0) {
        // 0x80093AFC: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_80092890;
    }
    // 0x80093AFC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80093B00:
    // 0x80093B00: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80093B04: lw          $t3, 0x6B98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6B98);
    // 0x80093B08: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80093B0C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80093B10: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x80093B14: sw          $t4, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r12;
    // 0x80093B18: b           L_80093B20
    // 0x80093B1C: nop

        goto L_80093B20;
    // 0x80093B1C: nop

L_80093B20:
    // 0x80093B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093B24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80093B28: jr          $ra
    // 0x80093B2C: nop

    return;
    // 0x80093B2C: nop

;}
RECOMP_FUNC void func_800451C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800451C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800451C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800451C8: jal         0x800AF060
    // 0x800451CC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x800451CC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x800451D0: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    // 0x800451D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800451D8: jal         0x800AFB70
    // 0x800451DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_1;
    // 0x800451DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800451E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800451E4: sw          $v0, -0x3A60($at)
    MEM_W(-0X3A60, ctx->r1) = ctx->r2;
    // 0x800451E8: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    // 0x800451EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800451F0: jal         0x800AFB70
    // 0x800451F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x800451F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800451F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800451FC: sw          $v0, -0x3A5C($at)
    MEM_W(-0X3A5C, ctx->r1) = ctx->r2;
    // 0x80045200: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    // 0x80045204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045208: jal         0x800AFB70
    // 0x8004520C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_3;
    // 0x8004520C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80045210: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80045214: sw          $v0, -0x3A58($at)
    MEM_W(-0X3A58, ctx->r1) = ctx->r2;
    // 0x80045218: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    // 0x8004521C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045220: jal         0x800AFB70
    // 0x80045224: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_4;
    // 0x80045224: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80045228: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004522C: sw          $v0, -0x3A54($at)
    MEM_W(-0X3A54, ctx->r1) = ctx->r2;
    // 0x80045230: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    // 0x80045234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045238: jal         0x800AFB70
    // 0x8004523C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_5;
    // 0x8004523C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80045240: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80045244: sw          $v0, -0x3A50($at)
    MEM_W(-0X3A50, ctx->r1) = ctx->r2;
    // 0x80045248: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x8004524C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045250: jal         0x800AFB70
    // 0x80045254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_6;
    // 0x80045254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80045258: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004525C: sw          $v0, -0x3A4C($at)
    MEM_W(-0X3A4C, ctx->r1) = ctx->r2;
    // 0x80045260: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x80045264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045268: jal         0x800AFB70
    // 0x8004526C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_7;
    // 0x8004526C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80045270: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80045274: sw          $v0, -0x3A48($at)
    MEM_W(-0X3A48, ctx->r1) = ctx->r2;
    // 0x80045278: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    // 0x8004527C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045280: jal         0x800AFB70
    // 0x80045284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_8;
    // 0x80045284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80045288: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8004528C: sw          $v0, -0x3A44($at)
    MEM_W(-0X3A44, ctx->r1) = ctx->r2;
    // 0x80045290: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80045294: sh          $zero, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = 0;
    // 0x80045298: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004529C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800452A0: swc1        $f4, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = ctx->f4.u32l;
    // 0x800452A4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800452A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800452AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800452B0: swc1        $f6, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f6.u32l;
    // 0x800452B4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800452B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800452BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800452C0: swc1        $f8, 0x733C($at)
    MEM_W(0X733C, ctx->r1) = ctx->f8.u32l;
    // 0x800452C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800452C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800452CC: swc1        $f10, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f10.u32l;
    // 0x800452D0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800452D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800452D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800452DC: swc1        $f16, -0x73E0($at)
    MEM_W(-0X73E0, ctx->r1) = ctx->f16.u32l;
    // 0x800452E0: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800452E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800452E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800452EC: swc1        $f18, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f18.u32l;
    // 0x800452F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800452F4: lwc1        $f4, -0x1170($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x800452F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800452FC: swc1        $f4, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f4.u32l;
    // 0x80045300: b           L_80045308
    // 0x80045304: nop

        goto L_80045308;
    // 0x80045304: nop

L_80045308:
    // 0x80045308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004530C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045310: jr          $ra
    // 0x80045314: nop

    return;
    // 0x80045314: nop

;}
RECOMP_FUNC void func_80065290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065298: jal         0x8005F064
    // 0x8006529C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006529C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800652A0: b           L_800652B0
    // 0x800652A4: nop

        goto L_800652B0;
    // 0x800652A4: nop

    // 0x800652A8: b           L_800652B0
    // 0x800652AC: nop

        goto L_800652B0;
    // 0x800652AC: nop

L_800652B0:
    // 0x800652B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800652B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800652B8: jr          $ra
    // 0x800652BC: nop

    return;
    // 0x800652BC: nop

;}
RECOMP_FUNC void alAuxBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1CB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D1CB4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800D1CB8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D1CBC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D1CC0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D1CC4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D1CC8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D1CCC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D1CD0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D1CD4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D1CD8: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800D1CDC: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800D1CE0: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800D1CE4: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800D1CE8: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x800D1CEC: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x800D1CF0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800D1CF4: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800D1CF8: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800D1CFC: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800D1D00: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800D1D04: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800D1D08: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800D1D0C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800D1D10: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800D1D14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D1D18: blez        $t8, L_800D1D5C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800D1D1C: addiu       $s2, $t0, 0x10
        ctx->r18 = ADD32(ctx->r8, 0X10);
            goto L_800D1D5C;
    }
    // 0x800D1D1C: addiu       $s2, $t0, 0x10
    ctx->r18 = ADD32(ctx->r8, 0X10);
    // 0x800D1D20: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800D1D24:
    // 0x800D1D24: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800D1D28: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D1D2C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D1D30: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800D1D34: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800D1D38: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800D1D3C: jalr        $t9
    // 0x800D1D40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D1D40: nop

    after_0:
    // 0x800D1D44: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x800D1D48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D1D4C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800D1D50: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D1D54: bne         $at, $zero, L_800D1D24
    if (ctx->r1 != 0) {
        // 0x800D1D58: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800D1D24;
    }
    // 0x800D1D58: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800D1D5C:
    // 0x800D1D5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1D60: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800D1D64: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D1D68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D1D6C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D1D70: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1D74: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D1D78: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D1D7C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D1D80: jr          $ra
    // 0x800D1D84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800D1D84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
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
RECOMP_FUNC void AudioDriver_DeallocSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA1E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA1F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BA1F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800BA1F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA1FC: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x800BA200: nop

    // 0x800BA204: beq         $t7, $at, L_800BA22C
    if (ctx->r15 == ctx->r1) {
        // 0x800BA208: nop
    
            goto L_800BA22C;
    }
    // 0x800BA208: nop

    // 0x800BA20C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800BA210: nop

    // 0x800BA214: lh          $a0, 0x18($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X18);
    // 0x800BA218: jal         0x800B9BD4
    // 0x800BA21C: nop

    AudioDriver_RequestSoundDealloc(rdram, ctx);
        goto after_0;
    // 0x800BA21C: nop

    after_0:
    // 0x800BA220: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800BA224: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BA228: sh          $t9, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r25;
L_800BA22C:
    // 0x800BA22C: b           L_800BA234
    // 0x800BA230: nop

        goto L_800BA234;
    // 0x800BA230: nop

L_800BA234:
    // 0x800BA234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA23C: jr          $ra
    // 0x800BA240: nop

    return;
    // 0x800BA240: nop

;}
RECOMP_FUNC void func_800741F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800741F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800741F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800741FC: jal         0x80061348
    // 0x80074200: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074200: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x80074204: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074208: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007420C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074210: beq         $v0, $zero, L_8007422C
    if (ctx->r2 == 0) {
        // 0x80074214: nop
    
            goto L_8007422C;
    }
    // 0x80074214: nop

    // 0x80074218: jal         0x80061348
    // 0x8007421C: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007421C: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074220: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074224: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074228: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8007422C:
    // 0x8007422C: b           L_8007423C
    // 0x80074230: nop

        goto L_8007423C;
    // 0x80074230: nop

    // 0x80074234: b           L_8007423C
    // 0x80074238: nop

        goto L_8007423C;
    // 0x80074238: nop

L_8007423C:
    // 0x8007423C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074244: jr          $ra
    // 0x80074248: nop

    return;
    // 0x80074248: nop

;}
RECOMP_FUNC void func_8006881C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006881C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068824: jal         0x80061488
    // 0x80068828: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068828: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_0:
    // 0x8006882C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068830: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068834: b           L_80068844
    // 0x80068838: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068844;
    // 0x80068838: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006883C: b           L_80068844
    // 0x80068840: nop

        goto L_80068844;
    // 0x80068840: nop

L_80068844:
    // 0x80068844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006884C: jr          $ra
    // 0x80068850: nop

    return;
    // 0x80068850: nop

;}
RECOMP_FUNC void ContPak_GetPfsFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE01C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AE020: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AE024: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800AE028: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800AE02C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800AE030: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800AE034: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800AE038: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800AE03C: lhu         $a1, 0x36($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X36);
    // 0x800AE040: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800AE044: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE048: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800AE04C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800AE050: jal         0x800ADED0
    // 0x800AE054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    ContPak_FindPfsSlot(rdram, ctx);
        goto after_0;
    // 0x800AE054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800AE058: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800AE05C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE060: nop

    // 0x800AE064: bne         $t8, $zero, L_800AE074
    if (ctx->r24 != 0) {
        // 0x800AE068: nop
    
            goto L_800AE074;
    }
    // 0x800AE068: nop

    // 0x800AE06C: b           L_800AE0B0
    // 0x800AE070: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_800AE0B0;
    // 0x800AE070: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800AE074:
    // 0x800AE074: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800AE078: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800AE07C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800AE080: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800AE084: lhu         $a1, 0x36($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X36);
    // 0x800AE088: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800AE08C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE090: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AE094: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800AE098: jal         0x800C57F0
    // 0x800AE09C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_1;
    // 0x800AE09C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_1:
    // 0x800AE0A0: b           L_800AE0B0
    // 0x800AE0A4: nop

        goto L_800AE0B0;
    // 0x800AE0A4: nop

    // 0x800AE0A8: b           L_800AE0B0
    // 0x800AE0AC: nop

        goto L_800AE0B0;
    // 0x800AE0AC: nop

L_800AE0B0:
    // 0x800AE0B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AE0B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AE0B8: jr          $ra
    // 0x800AE0BC: nop

    return;
    // 0x800AE0BC: nop

;}
RECOMP_FUNC void Thread_CreateSimple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0640: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C0644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0648: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C064C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C0650: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C0654: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
L_800C0658:
    // 0x800C0658: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x800C065C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0660: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0664: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0668: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C066C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0670: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0674: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0678: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C067C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0680: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0684: nop

    // 0x800C0688: bne         $t8, $zero, L_800C0698
    if (ctx->r24 != 0) {
        // 0x800C068C: nop
    
            goto L_800C0698;
    }
    // 0x800C068C: nop

    // 0x800C0690: b           L_800C06B4
    // 0x800C0694: nop

        goto L_800C06B4;
    // 0x800C0694: nop

L_800C0698:
    // 0x800C0698: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x800C069C: nop

    // 0x800C06A0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C06A4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C06A8: slti        $at, $t1, 0xC
    ctx->r1 = SIGNED(ctx->r9) < 0XC ? 1 : 0;
    // 0x800C06AC: bne         $at, $zero, L_800C0658
    if (ctx->r1 != 0) {
        // 0x800C06B0: sb          $t0, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r8;
            goto L_800C0658;
    }
    // 0x800C06B0: sb          $t0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r8;
L_800C06B4:
    // 0x800C06B4: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x800C06B8: nop

    // 0x800C06BC: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x800C06C0: bne         $at, $zero, L_800C06D0
    if (ctx->r1 != 0) {
        // 0x800C06C4: nop
    
            goto L_800C06D0;
    }
    // 0x800C06C4: nop

    // 0x800C06C8: b           L_800C0770
    // 0x800C06CC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_800C0770;
    // 0x800C06CC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800C06D0:
    // 0x800C06D0: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    // 0x800C06D4: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C06D8: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800C06DC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800C06E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800C06E4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800C06E8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x800C06EC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800C06F0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800C06F4: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800C06F8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800C06FC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C0700: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800C0704: addiu       $t6, $t6, 0x1950
    ctx->r14 = ADD32(ctx->r14, 0X1950);
    // 0x800C0708: addu        $t7, $t4, $at
    ctx->r15 = ADD32(ctx->r12, ctx->r1);
    // 0x800C070C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0710: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0714: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800C0718: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C071C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x800C0720: addiu       $a1, $t3, 0xA
    ctx->r5 = ADD32(ctx->r11, 0XA);
    // 0x800C0724: jal         0x800C4800
    // 0x800C0728: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C0728: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x800C072C: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x800C0730: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C0734: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800C0738: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C073C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800C0740: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800C0744: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800C0748: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C074C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800C0750: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800C0754: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800C0758: sb          $t0, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = ctx->r8;
    // 0x800C075C: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x800C0760: b           L_800C0770
    // 0x800C0764: nop

        goto L_800C0770;
    // 0x800C0764: nop

    // 0x800C0768: b           L_800C0770
    // 0x800C076C: nop

        goto L_800C0770;
    // 0x800C076C: nop

L_800C0770:
    // 0x800C0770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C0778: jr          $ra
    // 0x800C077C: nop

    return;
    // 0x800C077C: nop

;}
RECOMP_FUNC void func_800771A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800771A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800771AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800771B0: nop

    // 0x800771B4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800771B8: nop

    // 0x800771BC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800771C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800771C4: jr          $ra
    // 0x800771C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800771C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800771CC: jr          $ra
    // 0x800771D0: nop

    return;
    // 0x800771D0: nop

    // 0x800771D4: jr          $ra
    // 0x800771D8: nop

    return;
    // 0x800771D8: nop

;}
RECOMP_FUNC void func_80009C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009C64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80009C68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009C6C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80009C70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009C74: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80009C78: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80009C7C: lw          $t8, -0x5B3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B3C);
    // 0x80009C80: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80009C84: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80009C88: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80009C8C: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80009C90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80009C94: jal         0x800BD1FC
    // 0x80009C98: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80009C98: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80009C9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80009CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009CA4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80009CA8: jal         0x800BD218
    // 0x80009CAC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80009CAC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80009CB0: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x80009CB4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80009CB8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80009CBC: jal         0x800BC6EC
    // 0x80009CC0: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80009CC0: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    after_2:
    // 0x80009CC4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80009CC8: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x80009CCC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80009CD0: lw          $t4, -0x5B38($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5B38);
    // 0x80009CD4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80009CD8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80009CDC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80009CE0: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80009CE4: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80009CE8: jal         0x800BD1FC
    // 0x80009CEC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x80009CEC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80009CF0: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x80009CF4: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80009CF8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80009CFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80009D00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80009D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009D08: jal         0x800BD218
    // 0x80009D0C: subu        $a2, $t6, $t7
    ctx->r6 = SUB32(ctx->r14, ctx->r15);
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x80009D0C: subu        $a2, $t6, $t7
    ctx->r6 = SUB32(ctx->r14, ctx->r15);
    after_4:
    // 0x80009D10: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80009D14: b           L_80009D24
    // 0x80009D18: nop

        goto L_80009D24;
    // 0x80009D18: nop

    // 0x80009D1C: b           L_80009D24
    // 0x80009D20: nop

        goto L_80009D24;
    // 0x80009D20: nop

L_80009D24:
    // 0x80009D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009D28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009D2C: jr          $ra
    // 0x80009D30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80009D30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800045AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800045AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800045B0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800045B4:
    // 0x800045B4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800045B8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800045BC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800045C0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800045C4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800045C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800045CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800045D0: addiu       $t8, $t8, 0x6C20
    ctx->r24 = ADD32(ctx->r24, 0X6C20);
    // 0x800045D4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800045D8: lw          $t0, 0x1A0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A0);
    // 0x800045DC: nop

    // 0x800045E0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800045E4: beq         $t1, $zero, L_80004624
    if (ctx->r9 == 0) {
        // 0x800045E8: nop
    
            goto L_80004624;
    }
    // 0x800045E8: nop

    // 0x800045EC: lw          $t2, 0x1A4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1A4);
    // 0x800045F0: nop

    // 0x800045F4: bne         $t2, $a0, L_80004624
    if (ctx->r10 != ctx->r4) {
        // 0x800045F8: nop
    
            goto L_80004624;
    }
    // 0x800045F8: nop

    // 0x800045FC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80004600: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80004604: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80004608: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8000460C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80004610: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80004614: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80004618: addiu       $t5, $t5, 0x6C20
    ctx->r13 = ADD32(ctx->r13, 0X6C20);
    // 0x8000461C: b           L_8000464C
    // 0x80004620: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
        goto L_8000464C;
    // 0x80004620: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_80004624:
    // 0x80004624: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80004628: nop

    // 0x8000462C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80004630: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x80004634: bne         $at, $zero, L_800045B4
    if (ctx->r1 != 0) {
        // 0x80004638: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800045B4;
    }
    // 0x80004638: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8000463C: b           L_8000464C
    // 0x80004640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000464C;
    // 0x80004640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004644: b           L_8000464C
    // 0x80004648: nop

        goto L_8000464C;
    // 0x80004648: nop

L_8000464C:
    // 0x8000464C: jr          $ra
    // 0x80004650: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80004650: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800A7050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7050: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A7054: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x800A7058: bne         $at, $zero, L_800A7068
    if (ctx->r1 != 0) {
        // 0x800A705C: nop
    
            goto L_800A7068;
    }
    // 0x800A705C: nop

    // 0x800A7060: b           L_800A70D0
    // 0x800A7064: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A70D0;
    // 0x800A7064: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A7068:
    // 0x800A7068: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A706C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A7070: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A7074: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A7078: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A707C: addiu       $t7, $t7, 0x7340
    ctx->r15 = ADD32(ctx->r15, 0X7340);
    // 0x800A7080: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800A7084: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A7088: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800A708C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A7090: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A7094: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800A7098: nop

    // 0x800A709C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800A70A0: bne         $t1, $zero, L_800A70B0
    if (ctx->r9 != 0) {
        // 0x800A70A4: nop
    
            goto L_800A70B0;
    }
    // 0x800A70A4: nop

    // 0x800A70A8: b           L_800A70D0
    // 0x800A70AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A70D0;
    // 0x800A70AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A70B0:
    // 0x800A70B0: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A70B4: nop

    // 0x800A70B8: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800A70BC: nop

    // 0x800A70C0: or          $t4, $t3, $a1
    ctx->r12 = ctx->r11 | ctx->r5;
    // 0x800A70C4: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
    // 0x800A70C8: b           L_800A70D0
    // 0x800A70CC: nop

        goto L_800A70D0;
    // 0x800A70CC: nop

L_800A70D0:
    // 0x800A70D0: jr          $ra
    // 0x800A70D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A70D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80062EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062EF4: jal         0x8005F064
    // 0x80062EF8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062EF8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_0:
    // 0x80062EFC: b           L_80062F0C
    // 0x80062F00: nop

        goto L_80062F0C;
    // 0x80062F00: nop

    // 0x80062F04: b           L_80062F0C
    // 0x80062F08: nop

        goto L_80062F0C;
    // 0x80062F08: nop

L_80062F0C:
    // 0x80062F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062F14: jr          $ra
    // 0x80062F18: nop

    return;
    // 0x80062F18: nop

;}
RECOMP_FUNC void func_80064638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006463C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064640: jal         0x80061488
    // 0x80064644: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064644: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    after_0:
    // 0x80064648: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006464C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80064650: b           L_80064660
    // 0x80064654: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80064660;
    // 0x80064654: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064658: b           L_80064660
    // 0x8006465C: nop

        goto L_80064660;
    // 0x8006465C: nop

L_80064660:
    // 0x80064660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064668: jr          $ra
    // 0x8006466C: nop

    return;
    // 0x8006466C: nop

;}
RECOMP_FUNC void func_80076A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076A74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076A78: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076A7C: nop

    // 0x80076A80: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076A84: nop

    // 0x80076A88: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076A8C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076A90: jr          $ra
    // 0x80076A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076A98: jr          $ra
    // 0x80076A9C: nop

    return;
    // 0x80076A9C: nop

    // 0x80076AA0: jr          $ra
    // 0x80076AA4: nop

    return;
    // 0x80076AA4: nop

;}
RECOMP_FUNC void func_80077730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077730: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077734: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077738: nop

    // 0x8007773C: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80077740: nop

    // 0x80077744: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077748: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007774C: jr          $ra
    // 0x80077750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077754: jr          $ra
    // 0x80077758: nop

    return;
    // 0x80077758: nop

    // 0x8007775C: jr          $ra
    // 0x80077760: nop

    return;
    // 0x80077760: nop

;}
RECOMP_FUNC void func_80064868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064868: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006486C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064870: nop

    // 0x80064874: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064878: nop

    // 0x8006487C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064880: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064884: jr          $ra
    // 0x80064888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006488C: jr          $ra
    // 0x80064890: nop

    return;
    // 0x80064890: nop

    // 0x80064894: jr          $ra
    // 0x80064898: nop

    return;
    // 0x80064898: nop

;}
RECOMP_FUNC void func_8006BD30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD38: jal         0x8005F064
    // 0x8006BD3C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BD3C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_0:
    // 0x8006BD40: b           L_8006BD50
    // 0x8006BD44: nop

        goto L_8006BD50;
    // 0x8006BD44: nop

    // 0x8006BD48: b           L_8006BD50
    // 0x8006BD4C: nop

        goto L_8006BD50;
    // 0x8006BD4C: nop

L_8006BD50:
    // 0x8006BD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BD54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BD58: jr          $ra
    // 0x8006BD5C: nop

    return;
    // 0x8006BD5C: nop

;}
RECOMP_FUNC void func_80066430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066438: jal         0x80061348
    // 0x8006643C: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006643C: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_0:
    // 0x80066440: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066444: b           L_80066454
    // 0x80066448: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066454;
    // 0x80066448: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006644C: b           L_80066454
    // 0x80066450: nop

        goto L_80066454;
    // 0x80066450: nop

L_80066454:
    // 0x80066454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006645C: jr          $ra
    // 0x80066460: nop

    return;
    // 0x80066460: nop

;}
RECOMP_FUNC void func_80068AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068ADC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068AE0: nop

    // 0x80068AE4: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80068AE8: nop

    // 0x80068AEC: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80068AF0: jr          $ra
    // 0x80068AF4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068AF4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068AF8: jr          $ra
    // 0x80068AFC: nop

    return;
    // 0x80068AFC: nop

    // 0x80068B00: jr          $ra
    // 0x80068B04: nop

    return;
    // 0x80068B04: nop

;}
RECOMP_FUNC void func_800642F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800642F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800642FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064300: jal         0x80061488
    // 0x80064304: addiu       $a0, $zero, 0x624
    ctx->r4 = ADD32(0, 0X624);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064304: addiu       $a0, $zero, 0x624
    ctx->r4 = ADD32(0, 0X624);
    after_0:
    // 0x80064308: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006430C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80064310: b           L_80064320
    // 0x80064314: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80064320;
    // 0x80064314: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064318: b           L_80064320
    // 0x8006431C: nop

        goto L_80064320;
    // 0x8006431C: nop

L_80064320:
    // 0x80064320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064328: jr          $ra
    // 0x8006432C: nop

    return;
    // 0x8006432C: nop

;}
RECOMP_FUNC void func_80068960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068960: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068964: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068968: nop

    // 0x8006896C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80068970: nop

    // 0x80068974: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80068978: jr          $ra
    // 0x8006897C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006897C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068980: jr          $ra
    // 0x80068984: nop

    return;
    // 0x80068984: nop

    // 0x80068988: jr          $ra
    // 0x8006898C: nop

    return;
    // 0x8006898C: nop

;}
RECOMP_FUNC void func_8006C360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C368: jal         0x8005F064
    // 0x8006C36C: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C36C: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    after_0:
    // 0x8006C370: b           L_8006C380
    // 0x8006C374: nop

        goto L_8006C380;
    // 0x8006C374: nop

    // 0x8006C378: b           L_8006C380
    // 0x8006C37C: nop

        goto L_8006C380;
    // 0x8006C37C: nop

L_8006C380:
    // 0x8006C380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C388: jr          $ra
    // 0x8006C38C: nop

    return;
    // 0x8006C38C: nop

;}
RECOMP_FUNC void func_8000FE48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FE48: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000FE4C: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x8000FE50: nop

    // 0x8000FE54: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8000FE58: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8000FE5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FE60: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FE64: lwc1        $f4, 0xBC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XBC);
    // 0x8000FE68: lwc1        $f10, 0x18($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X18);
    // 0x8000FE6C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000FE70: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8000FE74: swc1        $f16, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f16.u32l;
    // 0x8000FE78: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000FE7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FE80: lwc1        $f18, 0xBC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XBC);
    // 0x8000FE84: nop

    // 0x8000FE88: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8000FE8C: nop

    // 0x8000FE90: bc1f        L_8000FEE8
    if (!c1cs) {
        // 0x8000FE94: nop
    
            goto L_8000FEE8;
    }
    // 0x8000FE94: nop

    // 0x8000FE98: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000FE9C: nop

    // 0x8000FEA0: lwc1        $f6, 0xB0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XB0);
    // 0x8000FEA4: lwc1        $f10, 0x18($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X18);
    // 0x8000FEA8: nop

    // 0x8000FEAC: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8000FEB0: nop

    // 0x8000FEB4: bc1f        L_8000FEE0
    if (!c1cs) {
        // 0x8000FEB8: nop
    
            goto L_8000FEE0;
    }
    // 0x8000FEB8: nop

    // 0x8000FEBC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000FEC0: nop

    // 0x8000FEC4: lwc1        $f8, 0xB0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XB0);
    // 0x8000FEC8: nop

    // 0x8000FECC: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x8000FED0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FED4: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000FED8: nop

    // 0x8000FEDC: swc1        $f16, 0xBC($t1)
    MEM_W(0XBC, ctx->r9) = ctx->f16.u32l;
L_8000FEE0:
    // 0x8000FEE0: b           L_8000FF50
    // 0x8000FEE4: nop

        goto L_8000FF50;
    // 0x8000FEE4: nop

L_8000FEE8:
    // 0x8000FEE8: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8000FEEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FEF0: lwc1        $f18, 0xBC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XBC);
    // 0x8000FEF4: nop

    // 0x8000FEF8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8000FEFC: nop

    // 0x8000FF00: bc1f        L_8000FF50
    if (!c1cs) {
        // 0x8000FF04: nop
    
            goto L_8000FF50;
    }
    // 0x8000FF04: nop

    // 0x8000FF08: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8000FF0C: nop

    // 0x8000FF10: lwc1        $f6, 0xB0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XB0);
    // 0x8000FF14: lwc1        $f10, 0x18($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8000FF18: nop

    // 0x8000FF1C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8000FF20: nop

    // 0x8000FF24: bc1f        L_8000FF50
    if (!c1cs) {
        // 0x8000FF28: nop
    
            goto L_8000FF50;
    }
    // 0x8000FF28: nop

    // 0x8000FF2C: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8000FF30: nop

    // 0x8000FF34: lwc1        $f8, 0xB0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XB0);
    // 0x8000FF38: nop

    // 0x8000FF3C: swc1        $f8, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f8.u32l;
    // 0x8000FF40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FF44: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8000FF48: nop

    // 0x8000FF4C: swc1        $f16, 0xBC($t5)
    MEM_W(0XBC, ctx->r13) = ctx->f16.u32l;
L_8000FF50:
    // 0x8000FF50: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000FF54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FF58: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FF5C: lwc1        $f18, 0xC0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC0);
    // 0x8000FF60: lwc1        $f10, 0x1C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8000FF64: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000FF68: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000FF6C: swc1        $f8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f8.u32l;
    // 0x8000FF70: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8000FF74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000FF78: lwc1        $f16, 0xC0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XC0);
    // 0x8000FF7C: nop

    // 0x8000FF80: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8000FF84: nop

    // 0x8000FF88: bc1f        L_8000FFE0
    if (!c1cs) {
        // 0x8000FF8C: nop
    
            goto L_8000FFE0;
    }
    // 0x8000FF8C: nop

    // 0x8000FF90: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000FF94: nop

    // 0x8000FF98: lwc1        $f4, 0xB4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XB4);
    // 0x8000FF9C: lwc1        $f10, 0x1C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8000FFA0: nop

    // 0x8000FFA4: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8000FFA8: nop

    // 0x8000FFAC: bc1f        L_8000FFD8
    if (!c1cs) {
        // 0x8000FFB0: nop
    
            goto L_8000FFD8;
    }
    // 0x8000FFB0: nop

    // 0x8000FFB4: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000FFB8: nop

    // 0x8000FFBC: lwc1        $f6, 0xB4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XB4);
    // 0x8000FFC0: nop

    // 0x8000FFC4: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x8000FFC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FFCC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000FFD0: nop

    // 0x8000FFD4: swc1        $f8, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->f8.u32l;
L_8000FFD8:
    // 0x8000FFD8: b           L_80010048
    // 0x8000FFDC: nop

        goto L_80010048;
    // 0x8000FFDC: nop

L_8000FFE0:
    // 0x8000FFE0: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000FFE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000FFE8: lwc1        $f16, 0xC0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC0);
    // 0x8000FFEC: nop

    // 0x8000FFF0: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8000FFF4: nop

    // 0x8000FFF8: bc1f        L_80010048
    if (!c1cs) {
        // 0x8000FFFC: nop
    
            goto L_80010048;
    }
    // 0x8000FFFC: nop

    // 0x80010000: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80010004: nop

    // 0x80010008: lwc1        $f4, 0xB4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XB4);
    // 0x8001000C: lwc1        $f10, 0x1C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80010010: nop

    // 0x80010014: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80010018: nop

    // 0x8001001C: bc1f        L_80010048
    if (!c1cs) {
        // 0x80010020: nop
    
            goto L_80010048;
    }
    // 0x80010020: nop

    // 0x80010024: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x80010028: nop

    // 0x8001002C: lwc1        $f6, 0xB4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XB4);
    // 0x80010030: nop

    // 0x80010034: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
    // 0x80010038: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001003C: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80010040: nop

    // 0x80010044: swc1        $f8, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->f8.u32l;
L_80010048:
    // 0x80010048: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8001004C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80010050: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80010054: lwc1        $f16, 0xC4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XC4);
    // 0x80010058: lwc1        $f10, 0x20($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8001005C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80010060: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80010064: swc1        $f6, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f6.u32l;
    // 0x80010068: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8001006C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80010070: lwc1        $f8, 0xC4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC4);
    // 0x80010074: nop

    // 0x80010078: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8001007C: nop

    // 0x80010080: bc1f        L_800100D8
    if (!c1cs) {
        // 0x80010084: nop
    
            goto L_800100D8;
    }
    // 0x80010084: nop

    // 0x80010088: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8001008C: nop

    // 0x80010090: lwc1        $f18, 0xB8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XB8);
    // 0x80010094: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80010098: nop

    // 0x8001009C: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800100A0: nop

    // 0x800100A4: bc1f        L_800100D0
    if (!c1cs) {
        // 0x800100A8: nop
    
            goto L_800100D0;
    }
    // 0x800100A8: nop

    // 0x800100AC: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800100B0: nop

    // 0x800100B4: lwc1        $f4, 0xB8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XB8);
    // 0x800100B8: nop

    // 0x800100BC: swc1        $f4, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f4.u32l;
    // 0x800100C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800100C4: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800100C8: nop

    // 0x800100CC: swc1        $f6, 0xC4($t9)
    MEM_W(0XC4, ctx->r25) = ctx->f6.u32l;
L_800100D0:
    // 0x800100D0: b           L_80010140
    // 0x800100D4: nop

        goto L_80010140;
    // 0x800100D4: nop

L_800100D8:
    // 0x800100D8: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800100DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800100E0: lwc1        $f8, 0xC4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC4);
    // 0x800100E4: nop

    // 0x800100E8: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800100EC: nop

    // 0x800100F0: bc1f        L_80010140
    if (!c1cs) {
        // 0x800100F4: nop
    
            goto L_80010140;
    }
    // 0x800100F4: nop

    // 0x800100F8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800100FC: nop

    // 0x80010100: lwc1        $f18, 0xB8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XB8);
    // 0x80010104: lwc1        $f10, 0x20($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80010108: nop

    // 0x8001010C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80010110: nop

    // 0x80010114: bc1f        L_80010140
    if (!c1cs) {
        // 0x80010118: nop
    
            goto L_80010140;
    }
    // 0x80010118: nop

    // 0x8001011C: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80010120: nop

    // 0x80010124: lwc1        $f4, 0xB8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XB8);
    // 0x80010128: nop

    // 0x8001012C: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
    // 0x80010130: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010134: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x80010138: nop

    // 0x8001013C: swc1        $f6, 0xC4($t3)
    MEM_W(0XC4, ctx->r11) = ctx->f6.u32l;
L_80010140:
    // 0x80010140: b           L_80010148
    // 0x80010144: nop

        goto L_80010148;
    // 0x80010144: nop

L_80010148:
    // 0x80010148: jr          $ra
    // 0x8001014C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001014C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80014B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014B5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80014B60: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80014B64: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80014B68: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x80014B6C: lw          $t6, 0x306C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X306C);
    // 0x80014B70: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80014B74: blez        $t7, L_80014BBC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80014B78: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_80014BBC;
    }
    // 0x80014B78: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_80014B7C:
    // 0x80014B7C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80014B80: nop

    // 0x80014B84: bne         $t8, $a0, L_80014B94
    if (ctx->r24 != ctx->r4) {
        // 0x80014B88: nop
    
            goto L_80014B94;
    }
    // 0x80014B88: nop

    // 0x80014B8C: b           L_80014BCC
    // 0x80014B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80014BCC;
    // 0x80014B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80014B94:
    // 0x80014B94: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80014B98: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80014B9C: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80014BA0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80014BA4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80014BA8: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80014BAC: addiu       $t2, $t1, 0x28
    ctx->r10 = ADD32(ctx->r9, 0X28);
    // 0x80014BB0: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80014BB4: bne         $at, $zero, L_80014B7C
    if (ctx->r1 != 0) {
        // 0x80014BB8: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_80014B7C;
    }
    // 0x80014BB8: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_80014BBC:
    // 0x80014BBC: b           L_80014BCC
    // 0x80014BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80014BCC;
    // 0x80014BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014BC4: b           L_80014BCC
    // 0x80014BC8: nop

        goto L_80014BCC;
    // 0x80014BC8: nop

L_80014BCC:
    // 0x80014BCC: jr          $ra
    // 0x80014BD0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80014BD0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8000975C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000975C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009760: addiu       $t6, $a0, 0x40
    ctx->r14 = ADD32(ctx->r4, 0X40);
    // 0x80009764: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80009768: lw          $t7, 0x34C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34C);
    // 0x8000976C: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80009770: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80009774: sw          $t8, 0x34C($a0)
    MEM_W(0X34C, ctx->r4) = ctx->r24;
    // 0x80009778: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000977C: nop

    // 0x80009780: swc1        $f4, 0x1A4($a0)
    MEM_W(0X1A4, ctx->r4) = ctx->f4.u32l;
    // 0x80009784: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80009788: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000978C: nop

    // 0x80009790: swc1        $f6, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->f6.u32l;
    // 0x80009794: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80009798: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000979C: nop

    // 0x800097A0: swc1        $f8, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f8.u32l;
    // 0x800097A4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800097A8: lwc1        $f10, 0x1A4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1A4);
    // 0x800097AC: lwc1        $f16, 0xCC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800097B0: lwc1        $f4, 0x1A0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800097B4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800097B8: nop

    // 0x800097BC: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800097C0: swc1        $f6, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = ctx->f6.u32l;
    // 0x800097C4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800097C8: lwc1        $f8, 0x1A8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A8);
    // 0x800097CC: lwc1        $f10, 0xD0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x800097D0: lwc1        $f18, 0x1A0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800097D4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800097D8: nop

    // 0x800097DC: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800097E0: swc1        $f4, 0x1B0($a0)
    MEM_W(0X1B0, ctx->r4) = ctx->f4.u32l;
    // 0x800097E4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800097E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800097EC: lwc1        $f8, 0xFC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XFC);
    // 0x800097F0: lwc1        $f7, -0x2E30($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2E30);
    // 0x800097F4: lwc1        $f6, -0x2E2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E2C);
    // 0x800097F8: lwc1        $f18, 0x1A0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800097FC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80009800: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x80009804: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80009808: nop

    // 0x8000980C: div.d       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x80009810: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80009814: swc1        $f6, 0x1B4($a0)
    MEM_W(0X1B4, ctx->r4) = ctx->f6.u32l;
    // 0x80009818: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8000981C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80009820: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80009824: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009828: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000982C: lwc1        $f10, 0xE8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x80009830: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x80009834: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80009838: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8000983C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80009840: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x80009844: mfhi        $t5
    ctx->r13 = hi;
    // 0x80009848: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8000984C: nop

    // 0x80009850: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009854: swc1        $f4, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f4.u32l;
    // 0x80009858: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000985C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80009860: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80009864: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009868: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000986C: lwc1        $f8, 0xEC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XEC);
    // 0x80009870: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x80009874: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80009878: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8000987C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80009880: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80009884: mfhi        $t9
    ctx->r25 = hi;
    // 0x80009888: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8000988C: nop

    // 0x80009890: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009894: swc1        $f18, 0xEC($t6)
    MEM_W(0XEC, ctx->r14) = ctx->f18.u32l;
    // 0x80009898: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8000989C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800098A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800098A4: lwc1        $f4, 0xE8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x800098A8: lwc1        $f6, 0x1A0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800098AC: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800098B0: nop

    // 0x800098B4: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800098B8: swc1        $f10, 0x1B8($a0)
    MEM_W(0X1B8, ctx->r4) = ctx->f10.u32l;
    // 0x800098BC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800098C0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800098C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800098C8: lwc1        $f16, 0xEC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XEC);
    // 0x800098CC: lwc1        $f8, 0x1A0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800098D0: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800098D4: nop

    // 0x800098D8: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800098DC: swc1        $f6, 0x1BC($a0)
    MEM_W(0X1BC, ctx->r4) = ctx->f6.u32l;
    // 0x800098E0: b           L_800098E8
    // 0x800098E4: nop

        goto L_800098E8;
    // 0x800098E4: nop

L_800098E8:
    // 0x800098E8: jr          $ra
    // 0x800098EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800098EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80076E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076E48: jal         0x80061488
    // 0x80076E4C: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076E4C: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076E50: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076E54: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076E58: b           L_80076E68
    // 0x80076E5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076E68;
    // 0x80076E5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076E60: b           L_80076E68
    // 0x80076E64: nop

        goto L_80076E68;
    // 0x80076E64: nop

L_80076E68:
    // 0x80076E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076E6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076E70: jr          $ra
    // 0x80076E74: nop

    return;
    // 0x80076E74: nop

;}
RECOMP_FUNC void func_80063338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006333C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063340: jal         0x80061488
    // 0x80063344: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063344: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    after_0:
    // 0x80063348: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006334C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063350: b           L_80063360
    // 0x80063354: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063360;
    // 0x80063354: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063358: b           L_80063360
    // 0x8006335C: nop

        goto L_80063360;
    // 0x8006335C: nop

L_80063360:
    // 0x80063360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063368: jr          $ra
    // 0x8006336C: nop

    return;
    // 0x8006336C: nop

;}
RECOMP_FUNC void alCents2Ratio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CADC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CADC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800CADC8: bltz        $a0, L_800CADDC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800CADCC: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800CADDC;
    }
    // 0x800CADCC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CADD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CADD4: b           L_800CADE4
    // 0x800CADD8: lwc1        $f0, 0x200($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X200);
        goto L_800CADE4;
    // 0x800CADD8: lwc1        $f0, 0x200($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X200);
L_800CADDC:
    // 0x800CADDC: lwc1        $f0, 0x204($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X204);
    // 0x800CADE0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800CADE4:
    // 0x800CADE4: beq         $a0, $zero, L_800CAE08
    if (ctx->r4 == 0) {
        // 0x800CADE8: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_800CAE08;
    }
L_800CADE8:
    // 0x800CADE8: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800CADEC: beq         $t6, $zero, L_800CADFC
    if (ctx->r14 == 0) {
        // 0x800CADF0: sra         $t7, $a0, 1
        ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800CADFC;
    }
    // 0x800CADF0: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800CADF4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800CADF8: nop

L_800CADFC:
    // 0x800CADFC: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800CAE00: bne         $t7, $zero, L_800CADE8
    if (ctx->r15 != 0) {
        // 0x800CAE04: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800CADE8;
    }
    // 0x800CAE04: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800CAE08:
    // 0x800CAE08: jr          $ra
    // 0x800CAE0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800CAE0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80066310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066318: jal         0x80061348
    // 0x8006631C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006631C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066320: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066324: b           L_80066334
    // 0x80066328: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066334;
    // 0x80066328: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006632C: b           L_80066334
    // 0x80066330: nop

        goto L_80066334;
    // 0x80066330: nop

L_80066334:
    // 0x80066334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006633C: jr          $ra
    // 0x80066340: nop

    return;
    // 0x80066340: nop

;}
RECOMP_FUNC void func_800684DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800684DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800684E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800684E4: nop

    // 0x800684E8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800684EC: nop

    // 0x800684F0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800684F4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800684F8: jr          $ra
    // 0x800684FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800684FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068500: jr          $ra
    // 0x80068504: nop

    return;
    // 0x80068504: nop

    // 0x80068508: jr          $ra
    // 0x8006850C: nop

    return;
    // 0x8006850C: nop

;}
